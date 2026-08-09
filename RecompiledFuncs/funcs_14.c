#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void Effect_FireSmoke1_Spawn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007CF30: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8007CF34: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8007CF38: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8007CF3C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8007CF40: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8007CF44: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8007CF48: addiu       $v0, $v0, 0x130
    ctx->r2 = ADD32(ctx->r2, 0X130);
    // 0x8007CF4C: addiu       $a0, $a0, 0x3754
    ctx->r4 = ADD32(ctx->r4, 0X3754);
    // 0x8007CF50: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
L_8007CF54:
    // 0x8007CF54: bnel        $t6, $zero, L_8007CF80
    if (ctx->r14 != 0) {
        // 0x8007CF58: addiu       $a0, $a0, -0x8C
        ctx->r4 = ADD32(ctx->r4, -0X8C);
            goto L_8007CF80;
    }
    goto skip_0;
    // 0x8007CF58: addiu       $a0, $a0, -0x8C
    ctx->r4 = ADD32(ctx->r4, -0X8C);
    skip_0:
    // 0x8007CF5C: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8007CF60: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8007CF64: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x8007CF68: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8007CF6C: jal         0x8007CC00
    // 0x8007CF70: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Effect_FireSmoke1_Setup(rdram, ctx);
        goto after_0;
    // 0x8007CF70: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x8007CF74: b           L_8007CF90
    // 0x8007CF78: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8007CF90;
    // 0x8007CF78: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007CF7C: addiu       $a0, $a0, -0x8C
    ctx->r4 = ADD32(ctx->r4, -0X8C);
L_8007CF80:
    // 0x8007CF80: sltu        $at, $a0, $v0
    ctx->r1 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x8007CF84: beql        $at, $zero, L_8007CF54
    if (ctx->r1 == 0) {
        // 0x8007CF88: lbu         $t6, 0x0($a0)
        ctx->r14 = MEM_BU(ctx->r4, 0X0);
            goto L_8007CF54;
    }
    goto skip_1;
    // 0x8007CF88: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    skip_1:
    // 0x8007CF8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8007CF90:
    // 0x8007CF90: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8007CF94: jr          $ra
    // 0x8007CF98: nop

    return;
    // 0x8007CF98: nop

;}
RECOMP_FUNC void Effect_Effect367_Spawn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007D9DC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8007D9E0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8007D9E4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8007D9E8: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8007D9EC: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8007D9F0: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8007D9F4: addiu       $v0, $v0, 0x130
    ctx->r2 = ADD32(ctx->r2, 0X130);
    // 0x8007D9F8: addiu       $a0, $a0, 0x3754
    ctx->r4 = ADD32(ctx->r4, 0X3754);
    // 0x8007D9FC: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
L_8007DA00:
    // 0x8007DA00: bnel        $t6, $zero, L_8007DA3C
    if (ctx->r14 != 0) {
        // 0x8007DA04: addiu       $a0, $a0, -0x8C
        ctx->r4 = ADD32(ctx->r4, -0X8C);
            goto L_8007DA3C;
    }
    goto skip_0;
    // 0x8007DA04: addiu       $a0, $a0, -0x8C
    ctx->r4 = ADD32(ctx->r4, -0X8C);
    skip_0:
    // 0x8007DA08: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8007DA0C: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8007DA10: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x8007DA14: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8007DA18: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x8007DA1C: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x8007DA20: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8007DA24: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x8007DA28: jal         0x8007D94C
    // 0x8007DA2C: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    Effect_Effect367_Setup(rdram, ctx);
        goto after_0;
    // 0x8007DA2C: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    after_0:
    // 0x8007DA30: b           L_8007DA4C
    // 0x8007DA34: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8007DA4C;
    // 0x8007DA34: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8007DA38: addiu       $a0, $a0, -0x8C
    ctx->r4 = ADD32(ctx->r4, -0X8C);
L_8007DA3C:
    // 0x8007DA3C: sltu        $at, $a0, $v0
    ctx->r1 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x8007DA40: beql        $at, $zero, L_8007DA00
    if (ctx->r1 == 0) {
        // 0x8007DA44: lbu         $t6, 0x0($a0)
        ctx->r14 = MEM_BU(ctx->r4, 0X0);
            goto L_8007DA00;
    }
    goto skip_1;
    // 0x8007DA44: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    skip_1:
    // 0x8007DA48: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8007DA4C:
    // 0x8007DA4C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8007DA50: jr          $ra
    // 0x8007DA54: nop

    return;
    // 0x8007DA54: nop

;}
RECOMP_FUNC void Audio_PlayPauseSfx(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D638: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001D63C: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x8001D640: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001D644: beq         $t6, $zero, L_8001D690
    if (ctx->r14 == 0) {
        // 0x8001D648: sw          $a0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r4;
            goto L_8001D690;
    }
    // 0x8001D648: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8001D64C: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8001D650: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x8001D654: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8001D658: addiu       $t7, $t7, 0x5D3C
    ctx->r15 = ADD32(ctx->r15, 0X5D3C);
    // 0x8001D65C: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x8001D660: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x8001D664: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x8001D668: ori         $a0, $a0, 0xF000
    ctx->r4 = ctx->r4 | 0XF000;
    // 0x8001D66C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8001D670: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8001D674: jal         0x80019218
    // 0x8001D678: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_0;
    // 0x8001D678: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_0:
    // 0x8001D67C: lui         $a0, 0xF100
    ctx->r4 = S32(0XF100 << 16);
    // 0x8001D680: jal         0x8001E8CC
    // 0x8001D684: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    AudioThread_QueueCmdS32(rdram, ctx);
        goto after_1;
    // 0x8001D684: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8001D688: b           L_8001D6D0
    // 0x8001D68C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8001D6D0;
    // 0x8001D68C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8001D690:
    // 0x8001D690: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8001D694: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x8001D698: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8001D69C: addiu       $t8, $t8, 0x5D3C
    ctx->r24 = ADD32(ctx->r24, 0X5D3C);
    // 0x8001D6A0: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x8001D6A4: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x8001D6A8: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x8001D6AC: ori         $a0, $a0, 0xF000
    ctx->r4 = ctx->r4 | 0XF000;
    // 0x8001D6B0: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8001D6B4: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8001D6B8: jal         0x80019218
    // 0x8001D6BC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_2;
    // 0x8001D6BC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_2:
    // 0x8001D6C0: lui         $a0, 0xF200
    ctx->r4 = S32(0XF200 << 16);
    // 0x8001D6C4: jal         0x8001E8CC
    // 0x8001D6C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    AudioThread_QueueCmdS32(rdram, ctx);
        goto after_3;
    // 0x8001D6C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x8001D6CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8001D6D0:
    // 0x8001D6D0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001D6D4: jr          $ra
    // 0x8001D6D8: nop

    return;
    // 0x8001D6D8: nop

;}
RECOMP_FUNC void HUD_ShieldGaugeBars_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800856C0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800856C4: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800856C8: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x800856CC: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x800856D0: lui         $at, 0x4240
    ctx->r1 = S32(0X4240 << 16);
    // 0x800856D4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800856D8: lwc1        $f10, 0x48($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800856DC: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x800856E0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800856E4: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800856E8: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800856EC: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800856F0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800856F4: lui         $a1, 0x101
    ctx->r5 = S32(0X101 << 16);
    // 0x800856F8: lui         $a2, 0x101
    ctx->r6 = S32(0X101 << 16);
    // 0x800856FC: addiu       $t6, $zero, 0xC
    ctx->r14 = ADD32(0, 0XC);
    // 0x80085700: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80085704: addiu       $a2, $a2, 0x3700
    ctx->r6 = ADD32(ctx->r6, 0X3700);
    // 0x80085708: addiu       $a1, $a1, 0x3580
    ctx->r5 = ADD32(ctx->r5, 0X3580);
    // 0x8008570C: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x80085710: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    // 0x80085714: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    // 0x80085718: swc1        $f12, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f12.u32l;
    // 0x8008571C: swc1        $f14, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f14.u32l;
    // 0x80085720: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    // 0x80085724: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x80085728: jal         0x80084E78
    // 0x8008572C: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    TextureRect_CI8_2(rdram, ctx);
        goto after_0;
    // 0x8008572C: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x80085730: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80085734: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80085738: jr          $ra
    // 0x8008573C: nop

    return;
    // 0x8008573C: nop

;}
RECOMP_FUNC void Lib_DmaRead(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800033E0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800033E4: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x800033E8: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x800033EC: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800033F0: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x800033F4: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x800033F8: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800033FC: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80003400: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x80003404: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x80003408: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8000340C: jal         0x800216C0
    // 0x80003410: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    osInvalICache_recomp(rdram, ctx);
        goto after_0;
    // 0x80003410: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x80003414: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80003418: jal         0x80021740
    // 0x8000341C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    osInvalDCache_recomp(rdram, ctx);
        goto after_1;
    // 0x8000341C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x80003420: slti        $at, $s0, 0x101
    ctx->r1 = SIGNED(ctx->r16) < 0X101 ? 1 : 0;
    // 0x80003424: bne         $at, $zero, L_80003484
    if (ctx->r1 != 0) {
        // 0x80003428: lui         $s4, 0x800E
        ctx->r20 = S32(0X800E << 16);
            goto L_80003484;
    }
    // 0x80003428: lui         $s4, 0x800E
    ctx->r20 = S32(0X800E << 16);
    // 0x8000342C: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x80003430: addiu       $s3, $s3, 0x20F0
    ctx->r19 = ADD32(ctx->r19, 0X20F0);
    // 0x80003434: addiu       $s4, $s4, 0x2110
    ctx->r20 = ADD32(ctx->r20, 0X2110);
    // 0x80003438: addiu       $t6, $zero, 0x100
    ctx->r14 = ADD32(0, 0X100);
L_8000343C:
    // 0x8000343C: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80003440: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80003444: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80003448: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8000344C: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    // 0x80003450: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    // 0x80003454: jal         0x800217F0
    // 0x80003458: sw          $s3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r19;
    osPiStartDma_recomp(rdram, ctx);
        goto after_2;
    // 0x80003458: sw          $s3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r19;
    after_2:
    // 0x8000345C: addiu       $s0, $s0, -0x100
    ctx->r16 = ADD32(ctx->r16, -0X100);
    // 0x80003460: addiu       $s2, $s2, 0x100
    ctx->r18 = ADD32(ctx->r18, 0X100);
    // 0x80003464: addiu       $s1, $s1, 0x100
    ctx->r17 = ADD32(ctx->r17, 0X100);
    // 0x80003468: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8000346C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80003470: jal         0x800205E0
    // 0x80003474: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_3;
    // 0x80003474: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x80003478: slti        $at, $s0, 0x101
    ctx->r1 = SIGNED(ctx->r16) < 0X101 ? 1 : 0;
    // 0x8000347C: beql        $at, $zero, L_8000343C
    if (ctx->r1 == 0) {
        // 0x80003480: addiu       $t6, $zero, 0x100
        ctx->r14 = ADD32(0, 0X100);
            goto L_8000343C;
    }
    goto skip_0;
    // 0x80003480: addiu       $t6, $zero, 0x100
    ctx->r14 = ADD32(0, 0X100);
    skip_0:
L_80003484:
    // 0x80003484: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x80003488: lui         $s4, 0x800E
    ctx->r20 = S32(0X800E << 16);
    // 0x8000348C: addiu       $s4, $s4, 0x2110
    ctx->r20 = ADD32(ctx->r20, 0X2110);
    // 0x80003490: beq         $s0, $zero, L_800034C8
    if (ctx->r16 == 0) {
        // 0x80003494: addiu       $s3, $s3, 0x20F0
        ctx->r19 = ADD32(ctx->r19, 0X20F0);
            goto L_800034C8;
    }
    // 0x80003494: addiu       $s3, $s3, 0x20F0
    ctx->r19 = ADD32(ctx->r19, 0X20F0);
    // 0x80003498: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8000349C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800034A0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800034A4: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    // 0x800034A8: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    // 0x800034AC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800034B0: jal         0x800217F0
    // 0x800034B4: sw          $s3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r19;
    osPiStartDma_recomp(rdram, ctx);
        goto after_4;
    // 0x800034B4: sw          $s3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r19;
    after_4:
    // 0x800034B8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800034BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800034C0: jal         0x800205E0
    // 0x800034C4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_5;
    // 0x800034C4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
L_800034C8:
    // 0x800034C8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800034CC: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800034D0: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x800034D4: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x800034D8: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x800034DC: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x800034E0: jr          $ra
    // 0x800034E4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800034E4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void Audio_RemoveMatchingSfxRequests(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80019290: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x80019294: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x80019298: lbu         $v0, 0x5D1C($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X5D1C);
    // 0x8001929C: lbu         $v1, 0x5D18($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X5D18);
    // 0x800192A0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800192A4: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x800192A8: beq         $v1, $v0, L_8001942C
    if (ctx->r3 == ctx->r2) {
        // 0x800192AC: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_8001942C;
    }
    // 0x800192AC: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x800192B0: lui         $t1, 0x8014
    ctx->r9 = S32(0X8014 << 16);
    // 0x800192B4: addiu       $t1, $t1, 0x6E60
    ctx->r9 = ADD32(ctx->r9, 0X6E60);
    // 0x800192B8: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x800192BC: addiu       $t2, $zero, 0x18
    ctx->r10 = ADD32(0, 0X18);
    // 0x800192C0: lui         $t0, 0xF000
    ctx->r8 = S32(0XF000 << 16);
L_800192C4:
    // 0x800192C4: sltiu       $at, $a2, 0x6
    ctx->r1 = ctx->r6 < 0X6 ? 1 : 0;
    // 0x800192C8: beq         $at, $zero, L_800193FC
    if (ctx->r1 == 0) {
        // 0x800192CC: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_800193FC;
    }
    // 0x800192CC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800192D0: sll         $t7, $a2, 2
    ctx->r15 = S32(ctx->r6 << 2);
    // 0x800192D4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800192D8: addu        $at, $at, $t7
    gpr jr_addend_800192E0 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800192DC: lw          $t7, -0x6F6C($at)
    ctx->r15 = ADD32(ctx->r1, -0X6F6C);
    // 0x800192E0: jr          $t7
    // 0x800192E4: nop

    switch (jr_addend_800192E0 >> 2) {
        case 0: goto L_800192E8; break;
        case 1: goto L_80019314; break;
        case 2: goto L_80019350; break;
        case 3: goto L_80019374; break;
        case 4: goto L_800193A8; break;
        case 5: goto L_800193DC; break;
        default: switch_error(__func__, 0x800192E0, 0x800C9094);
    }
    // 0x800192E4: nop

L_800192E8:
    // 0x800192E8: multu       $v0, $t2
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800192EC: lw          $t8, 0x24($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X24);
    // 0x800192F0: and         $t9, $t8, $t0
    ctx->r25 = ctx->r24 & ctx->r8;
    // 0x800192F4: mflo        $t3
    ctx->r11 = lo;
    // 0x800192F8: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x800192FC: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x80019300: and         $t6, $t5, $t0
    ctx->r14 = ctx->r13 & ctx->r8;
    // 0x80019304: bne         $t9, $t6, L_800193FC
    if (ctx->r25 != ctx->r14) {
        // 0x80019308: nop
    
            goto L_800193FC;
    }
    // 0x80019308: nop

    // 0x8001930C: b           L_800193FC
    // 0x80019310: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800193FC;
    // 0x80019310: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80019314:
    // 0x80019314: multu       $v0, $t2
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80019318: lw          $t8, 0x24($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X24);
    // 0x8001931C: and         $t3, $t8, $t0
    ctx->r11 = ctx->r24 & ctx->r8;
    // 0x80019320: mflo        $t7
    ctx->r15 = lo;
    // 0x80019324: addu        $a1, $t1, $t7
    ctx->r5 = ADD32(ctx->r9, ctx->r15);
    // 0x80019328: lw          $t4, 0x0($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X0);
    // 0x8001932C: and         $t5, $t4, $t0
    ctx->r13 = ctx->r12 & ctx->r8;
    // 0x80019330: bne         $t3, $t5, L_800193FC
    if (ctx->r11 != ctx->r13) {
        // 0x80019334: nop
    
            goto L_800193FC;
    }
    // 0x80019334: nop

    // 0x80019338: lw          $t9, 0x0($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X0);
    // 0x8001933C: lw          $t6, 0x4($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X4);
    // 0x80019340: bne         $t9, $t6, L_800193FC
    if (ctx->r25 != ctx->r14) {
        // 0x80019344: nop
    
            goto L_800193FC;
    }
    // 0x80019344: nop

    // 0x80019348: b           L_800193FC
    // 0x8001934C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800193FC;
    // 0x8001934C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80019350:
    // 0x80019350: multu       $v0, $t2
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80019354: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
    // 0x80019358: mflo        $t8
    ctx->r24 = lo;
    // 0x8001935C: addu        $t4, $t1, $t8
    ctx->r12 = ADD32(ctx->r9, ctx->r24);
    // 0x80019360: lw          $t3, 0x4($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X4);
    // 0x80019364: bne         $t7, $t3, L_800193FC
    if (ctx->r15 != ctx->r11) {
        // 0x80019368: nop
    
            goto L_800193FC;
    }
    // 0x80019368: nop

    // 0x8001936C: b           L_800193FC
    // 0x80019370: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800193FC;
    // 0x80019370: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80019374:
    // 0x80019374: multu       $v0, $t2
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80019378: lw          $t9, 0x0($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X0);
    // 0x8001937C: mflo        $t5
    ctx->r13 = lo;
    // 0x80019380: addu        $a1, $t1, $t5
    ctx->r5 = ADD32(ctx->r9, ctx->r13);
    // 0x80019384: lw          $t6, 0x4($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X4);
    // 0x80019388: bne         $t9, $t6, L_800193FC
    if (ctx->r25 != ctx->r14) {
        // 0x8001938C: nop
    
            goto L_800193FC;
    }
    // 0x8001938C: nop

    // 0x80019390: lw          $t8, 0x24($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X24);
    // 0x80019394: lw          $t4, 0x0($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X0);
    // 0x80019398: bne         $t8, $t4, L_800193FC
    if (ctx->r24 != ctx->r12) {
        // 0x8001939C: nop
    
            goto L_800193FC;
    }
    // 0x8001939C: nop

    // 0x800193A0: b           L_800193FC
    // 0x800193A4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800193FC;
    // 0x800193A4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800193A8:
    // 0x800193A8: multu       $v0, $t2
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800193AC: lbu         $t3, 0xC($a3)
    ctx->r11 = MEM_BU(ctx->r7, 0XC);
    // 0x800193B0: mflo        $t7
    ctx->r15 = lo;
    // 0x800193B4: addu        $a1, $t1, $t7
    ctx->r5 = ADD32(ctx->r9, ctx->r15);
    // 0x800193B8: lbu         $t5, 0x8($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X8);
    // 0x800193BC: bne         $t3, $t5, L_800193FC
    if (ctx->r11 != ctx->r13) {
        // 0x800193C0: nop
    
            goto L_800193FC;
    }
    // 0x800193C0: nop

    // 0x800193C4: lw          $t9, 0x24($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X24);
    // 0x800193C8: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x800193CC: bne         $t9, $t6, L_800193FC
    if (ctx->r25 != ctx->r14) {
        // 0x800193D0: nop
    
            goto L_800193FC;
    }
    // 0x800193D0: nop

    // 0x800193D4: b           L_800193FC
    // 0x800193D8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800193FC;
    // 0x800193D8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800193DC:
    // 0x800193DC: multu       $v0, $t2
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800193E0: lw          $t8, 0x24($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X24);
    // 0x800193E4: mflo        $t4
    ctx->r12 = lo;
    // 0x800193E8: addu        $t7, $t1, $t4
    ctx->r15 = ADD32(ctx->r9, ctx->r12);
    // 0x800193EC: lw          $t3, 0x0($t7)
    ctx->r11 = MEM_W(ctx->r15, 0X0);
    // 0x800193F0: bne         $t8, $t3, L_800193FC
    if (ctx->r24 != ctx->r11) {
        // 0x800193F4: nop
    
            goto L_800193FC;
    }
    // 0x800193F4: nop

    // 0x800193F8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800193FC:
    // 0x800193FC: beql        $a0, $zero, L_80019420
    if (ctx->r4 == 0) {
        // 0x80019400: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_80019420;
    }
    goto skip_0;
    // 0x80019400: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_0:
    // 0x80019404: multu       $v0, $t2
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80019408: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x8001940C: mflo        $t5
    ctx->r13 = lo;
    // 0x80019410: addu        $t9, $t1, $t5
    ctx->r25 = ADD32(ctx->r9, ctx->r13);
    // 0x80019414: sw          $zero, 0x0($t9)
    MEM_W(0X0, ctx->r25) = 0;
    // 0x80019418: lbu         $v1, 0x5D18($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X5D18);
    // 0x8001941C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_80019420:
    // 0x80019420: andi        $t6, $v0, 0xFF
    ctx->r14 = ctx->r2 & 0XFF;
    // 0x80019424: bne         $v1, $t6, L_800192C4
    if (ctx->r3 != ctx->r14) {
        // 0x80019428: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_800192C4;
    }
    // 0x80019428: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
L_8001942C:
    // 0x8001942C: jr          $ra
    // 0x80019430: nop

    return;
    // 0x80019430: nop

;}
RECOMP_FUNC void Controller_ReadData(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002AF4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80002AF8: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80002AFC: addiu       $v1, $v1, -0x274C
    ctx->r3 = ADD32(ctx->r3, -0X274C);
    // 0x80002B00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80002B04: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80002B08: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80002B0C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80002B10: beq         $v0, $zero, L_80002B9C
    if (ctx->r2 == 0) {
        // 0x80002B14: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_80002B9C;
    }
    // 0x80002B14: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80002B18: sll         $v0, $zero, 24
    ctx->r2 = S32(0 << 24);
    // 0x80002B1C: sra         $t7, $v0, 24
    ctx->r15 = S32(SIGNED(ctx->r2) >> 24);
    // 0x80002B20: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80002B24: sll         $v0, $zero, 24
    ctx->r2 = S32(0 << 24);
    // 0x80002B28: sh          $t7, -0x2740($at)
    MEM_H(-0X2740, ctx->r1) = ctx->r15;
    // 0x80002B2C: sb          $t7, -0x273E($at)
    MEM_B(-0X273E, ctx->r1) = ctx->r15;
    // 0x80002B30: sb          $t7, -0x273D($at)
    MEM_B(-0X273D, ctx->r1) = ctx->r15;
    // 0x80002B34: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80002B38: sra         $t8, $v0, 24
    ctx->r24 = S32(SIGNED(ctx->r2) >> 24);
    // 0x80002B3C: sb          $t8, -0x2737($at)
    MEM_B(-0X2737, ctx->r1) = ctx->r24;
    // 0x80002B40: sb          $t8, -0x2738($at)
    MEM_B(-0X2738, ctx->r1) = ctx->r24;
    // 0x80002B44: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80002B48: sll         $v0, $zero, 24
    ctx->r2 = S32(0 << 24);
    // 0x80002B4C: sra         $t9, $v0, 24
    ctx->r25 = S32(SIGNED(ctx->r2) >> 24);
    // 0x80002B50: sh          $t8, -0x273A($at)
    MEM_H(-0X273A, ctx->r1) = ctx->r24;
    // 0x80002B54: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80002B58: sb          $t9, -0x2731($at)
    MEM_B(-0X2731, ctx->r1) = ctx->r25;
    // 0x80002B5C: sb          $t9, -0x2732($at)
    MEM_B(-0X2732, ctx->r1) = ctx->r25;
    // 0x80002B60: sh          $t9, -0x2734($at)
    MEM_H(-0X2734, ctx->r1) = ctx->r25;
    // 0x80002B64: sll         $v0, $zero, 24
    ctx->r2 = S32(0 << 24);
    // 0x80002B68: sra         $t0, $v0, 24
    ctx->r8 = S32(SIGNED(ctx->r2) >> 24);
    // 0x80002B6C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80002B70: sb          $t0, -0x272B($at)
    MEM_B(-0X272B, ctx->r1) = ctx->r8;
    // 0x80002B74: sb          $t0, -0x272C($at)
    MEM_B(-0X272C, ctx->r1) = ctx->r8;
    // 0x80002B78: sh          $t0, -0x272E($at)
    MEM_H(-0X272E, ctx->r1) = ctx->r8;
    // 0x80002B7C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80002B80: sb          $zero, -0x273C($at)
    MEM_B(-0X273C, ctx->r1) = 0;
    // 0x80002B84: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80002B88: sb          $zero, -0x2736($at)
    MEM_B(-0X2736, ctx->r1) = 0;
    // 0x80002B8C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80002B90: sb          $zero, -0x2730($at)
    MEM_B(-0X2730, ctx->r1) = 0;
    // 0x80002B94: b           L_80002BC4
    // 0x80002B98: sb          $zero, -0x272A($at)
    MEM_B(-0X272A, ctx->r1) = 0;
        goto L_80002BC4;
    // 0x80002B98: sb          $zero, -0x272A($at)
    MEM_B(-0X272A, ctx->r1) = 0;
L_80002B9C:
    // 0x80002B9C: jal         0x80020380
    // 0x80002BA0: addiu       $a0, $a0, 0x2128
    ctx->r4 = ADD32(ctx->r4, 0X2128);
    osContStartReadData_recomp(rdram, ctx);
        goto after_0;
    // 0x80002BA0: addiu       $a0, $a0, 0x2128
    ctx->r4 = ADD32(ctx->r4, 0X2128);
    after_0:
    // 0x80002BA4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80002BA8: addiu       $a0, $a0, 0x2128
    ctx->r4 = ADD32(ctx->r4, 0X2128);
    // 0x80002BAC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80002BB0: jal         0x800205E0
    // 0x80002BB4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x80002BB4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x80002BB8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80002BBC: jal         0x80020444
    // 0x80002BC0: addiu       $a0, $a0, -0x2740
    ctx->r4 = ADD32(ctx->r4, -0X2740);
    osContGetReadData_recomp(rdram, ctx);
        goto after_2;
    // 0x80002BC0: addiu       $a0, $a0, -0x2740
    ctx->r4 = ADD32(ctx->r4, -0X2740);
    after_2:
L_80002BC4:
    // 0x80002BC4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80002BC8: addiu       $a0, $a0, 0x22F8
    ctx->r4 = ADD32(ctx->r4, 0X22F8);
    // 0x80002BCC: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x80002BD0: jal         0x80020720
    // 0x80002BD4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_3;
    // 0x80002BD4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x80002BD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80002BDC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80002BE0: jr          $ra
    // 0x80002BE4: nop

    return;
    // 0x80002BE4: nop

;}
RECOMP_FUNC void Actor_DrawEngineAndContrails(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005ADAC: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8005ADB0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8005ADB4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8005ADB8: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x8005ADBC: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x8005ADC0: lw          $v0, 0x7C($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X7C);
    // 0x8005ADC4: beql        $v0, $zero, L_8005AFC4
    if (ctx->r2 == 0) {
        // 0x8005ADC8: lw          $t4, 0x60($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X60);
            goto L_8005AFC4;
    }
    goto skip_0;
    // 0x8005ADC8: lw          $t4, 0x60($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X60);
    skip_0:
    // 0x8005ADCC: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x8005ADD0: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x8005ADD4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8005ADD8: bne         $t7, $at, L_8005AFC0
    if (ctx->r15 != ctx->r1) {
        // 0x8005ADDC: addiu       $a0, $a0, 0x188
        ctx->r4 = ADD32(ctx->r4, 0X188);
            goto L_8005AFC0;
    }
    // 0x8005ADDC: addiu       $a0, $a0, 0x188
    ctx->r4 = ADD32(ctx->r4, 0X188);
    // 0x8005ADE0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005ADE4: lwc1        $f0, 0x6124($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6124);
    // 0x8005ADE8: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8005ADEC: bne         $at, $zero, L_8005ADFC
    if (ctx->r1 != 0) {
        // 0x8005ADF0: lui         $a2, 0x3E99
        ctx->r6 = S32(0X3E99 << 16);
            goto L_8005ADFC;
    }
    // 0x8005ADF0: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x8005ADF4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005ADF8: lwc1        $f0, 0x6128($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6128);
L_8005ADFC:
    // 0x8005ADFC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8005AE00: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8005AE04: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x8005AE08: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x8005AE0C: jal         0x8009BC2C
    // 0x8005AE10: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_0;
    // 0x8005AE10: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x8005AE14: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x8005AE18: lw          $t9, 0x7DB0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7DB0);
    // 0x8005AE1C: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x8005AE20: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x8005AE24: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x8005AE28: beq         $t0, $zero, L_8005AE40
    if (ctx->r8 == 0) {
        // 0x8005AE2C: lwc1        $f0, 0x188($t8)
        ctx->f0.u32l = MEM_W(ctx->r24, 0X188);
            goto L_8005AE40;
    }
    // 0x8005AE2C: lwc1        $f0, 0x188($t8)
    ctx->f0.u32l = MEM_W(ctx->r24, 0X188);
    // 0x8005AE30: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005AE34: lwc1        $f6, 0x612C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X612C);
    // 0x8005AE38: mul.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8005AE3C: nop

L_8005AE40:
    // 0x8005AE40: addiu       $s0, $s0, -0x4C40
    ctx->r16 = ADD32(ctx->r16, -0X4C40);
    // 0x8005AE44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005AE48: jal         0x80005708
    // 0x8005AE4C: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    Matrix_Push(rdram, ctx);
        goto after_1;
    // 0x8005AE4C: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x8005AE50: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8005AE54: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8005AE58: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8005AE5C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8005AE60: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8005AE64: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8005AE68: jal         0x80005B00
    // 0x8005AE6C: lui         $a3, 0xC270
    ctx->r7 = S32(0XC270 << 16);
    Matrix_Translate(rdram, ctx);
        goto after_2;
    // 0x8005AE6C: lui         $a3, 0xC270
    ctx->r7 = S32(0XC270 << 16);
    after_2:
    // 0x8005AE70: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005AE74: lwc1        $f0, 0x5C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8005AE78: lwc1        $f8, 0x6130($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6130);
    // 0x8005AE7C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8005AE80: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8005AE84: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8005AE88: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8005AE8C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8005AE90: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8005AE94: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x8005AE98: jal         0x80005C34
    // 0x8005AE9C: nop

    Matrix_Scale(rdram, ctx);
        goto after_3;
    // 0x8005AE9C: nop

    after_3:
    // 0x8005AEA0: lw          $t3, 0x60($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X60);
    // 0x8005AEA4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005AEA8: lwc1        $f4, 0x6134($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6134);
    // 0x8005AEAC: lwc1        $f16, 0x18($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0X18);
    // 0x8005AEB0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8005AEB4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8005AEB8: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x8005AEBC: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8005AEC0: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8005AEC4: jal         0x80005FE0
    // 0x8005AEC8: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_4;
    // 0x8005AEC8: nop

    after_4:
    // 0x8005AECC: lw          $t4, 0x60($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X60);
    // 0x8005AED0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005AED4: lwc1        $f16, 0x6138($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6138);
    // 0x8005AED8: lwc1        $f8, 0x10($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X10);
    // 0x8005AEDC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8005AEE0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8005AEE4: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x8005AEE8: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8005AEEC: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8005AEF0: jal         0x80005D44
    // 0x8005AEF4: nop

    Matrix_RotateX(rdram, ctx);
        goto after_5;
    // 0x8005AEF4: nop

    after_5:
    // 0x8005AEF8: lw          $t5, 0x60($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X60);
    // 0x8005AEFC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005AF00: lwc1        $f8, 0x613C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X613C);
    // 0x8005AF04: lwc1        $f4, 0x14($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X14);
    // 0x8005AF08: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8005AF0C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8005AF10: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x8005AF14: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8005AF18: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8005AF1C: jal         0x80005E90
    // 0x8005AF20: nop

    Matrix_RotateY(rdram, ctx);
        goto after_6;
    // 0x8005AF20: nop

    after_6:
    // 0x8005AF24: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x8005AF28: lw          $t7, 0x78A0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X78A0);
    // 0x8005AF2C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8005AF30: lw          $t6, -0x7D80($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7D80);
    // 0x8005AF34: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8005AF38: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8005AF3C: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8005AF40: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8005AF44: sll         $t8, $t8, 5
    ctx->r24 = S32(ctx->r24 << 5);
    // 0x8005AF48: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x8005AF4C: lwc1        $f16, 0x58($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X58);
    // 0x8005AF50: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8005AF54: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8005AF58: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x8005AF5C: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8005AF60: jal         0x80005E90
    // 0x8005AF64: nop

    Matrix_RotateY(rdram, ctx);
        goto after_7;
    // 0x8005AF64: nop

    after_7:
    // 0x8005AF68: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x8005AF6C: lw          $t1, 0x78A0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X78A0);
    // 0x8005AF70: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8005AF74: lw          $t0, -0x7D80($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7D80);
    // 0x8005AF78: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8005AF7C: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8005AF80: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x8005AF84: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x8005AF88: sll         $t2, $t2, 5
    ctx->r10 = S32(ctx->r10 << 5);
    // 0x8005AF8C: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x8005AF90: lw          $a1, 0x5C($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X5C);
    // 0x8005AF94: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8005AF98: jal         0x80005D44
    // 0x8005AF9C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateX(rdram, ctx);
        goto after_8;
    // 0x8005AF9C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_8:
    // 0x8005AFA0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8005AFA4: jal         0x80006EB8
    // 0x8005AFA8: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_9;
    // 0x8005AFA8: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    after_9:
    // 0x8005AFAC: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8005AFB0: jal         0x8005465C
    // 0x8005AFB4: lbu         $a0, 0x7C98($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X7C98);
    Display_DrawEngineGlow(rdram, ctx);
        goto after_10;
    // 0x8005AFB4: lbu         $a0, 0x7C98($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X7C98);
    after_10:
    // 0x8005AFB8: jal         0x80005740
    // 0x8005AFBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_11;
    // 0x8005AFBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
L_8005AFC0:
    // 0x8005AFC0: lw          $t4, 0x60($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X60);
L_8005AFC4:
    // 0x8005AFC4: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8005AFC8: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x8005AFCC: lwc1        $f2, 0x168($t4)
    ctx->f2.u32l = MEM_W(ctx->r12, 0X168);
    // 0x8005AFD0: addiu       $s0, $s0, -0x4C40
    ctx->r16 = ADD32(ctx->r16, -0X4C40);
    // 0x8005AFD4: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x8005AFD8: c.eq.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl == ctx->f12.fl;
    // 0x8005AFDC: nop

    // 0x8005AFE0: bc1tl       L_8005B1D8
    if (c1cs) {
        // 0x8005AFE4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8005B1D8;
    }
    goto skip_1;
    // 0x8005AFE4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x8005AFE8: lbu         $t5, 0x7C98($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0X7C98);
    // 0x8005AFEC: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x8005AFF0: bnel        $t5, $zero, L_8005B1D8
    if (ctx->r13 != 0) {
        // 0x8005AFF4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8005B1D8;
    }
    goto skip_2;
    // 0x8005AFF4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x8005AFF8: lw          $t7, 0x7DB0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7DB0);
    // 0x8005AFFC: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x8005B000: andi        $t6, $t7, 0x1
    ctx->r14 = ctx->r15 & 0X1;
    // 0x8005B004: beq         $t6, $zero, L_8005B014
    if (ctx->r14 == 0) {
        // 0x8005B008: lui         $at, 0x4334
        ctx->r1 = S32(0X4334 << 16);
            goto L_8005B014;
    }
    // 0x8005B008: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8005B00C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8005B010: nop

L_8005B014:
    // 0x8005B014: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    // 0x8005B018: jal         0x800BA170
    // 0x8005B01C: swc1        $f2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f2.u32l;
    RCP_SetupDL_64_2(rdram, ctx);
        goto after_12;
    // 0x8005B01C: swc1        $f2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f2.u32l;
    after_12:
    // 0x8005B020: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8005B024: addiu       $a1, $a1, 0x7E64
    ctx->r5 = ADD32(ctx->r5, 0X7E64);
    // 0x8005B028: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8005B02C: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x8005B030: addiu       $t1, $zero, -0x9C
    ctx->r9 = ADD32(0, -0X9C);
    // 0x8005B034: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8005B038: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x8005B03C: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x8005B040: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8005B044: jal         0x80005708
    // 0x8005B048: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_Push(rdram, ctx);
        goto after_13;
    // 0x8005B048: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x8005B04C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8005B050: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8005B054: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8005B058: lui         $a1, 0x428C
    ctx->r5 = S32(0X428C << 16);
    // 0x8005B05C: lui         $a2, 0xC120
    ctx->r6 = S32(0XC120 << 16);
    // 0x8005B060: jal         0x80005B00
    // 0x8005B064: lui         $a3, 0xC2C8
    ctx->r7 = S32(0XC2C8 << 16);
    Matrix_Translate(rdram, ctx);
        goto after_14;
    // 0x8005B064: lui         $a3, 0xC2C8
    ctx->r7 = S32(0XC2C8 << 16);
    after_14:
    // 0x8005B068: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8005B06C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8005B070: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8005B074: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x8005B078: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8005B07C: jal         0x80005C34
    // 0x8005B080: lui         $a3, 0x4248
    ctx->r7 = S32(0X4248 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_15;
    // 0x8005B080: lui         $a3, 0x4248
    ctx->r7 = S32(0X4248 << 16);
    after_15:
    // 0x8005B084: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8005B088: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8005B08C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8005B090: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8005B094: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8005B098: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8005B09C: jal         0x80005B00
    // 0x8005B0A0: lui         $a3, 0xC18C
    ctx->r7 = S32(0XC18C << 16);
    Matrix_Translate(rdram, ctx);
        goto after_16;
    // 0x8005B0A0: lui         $a3, 0xC18C
    ctx->r7 = S32(0XC18C << 16);
    after_16:
    // 0x8005B0A4: lui         $a1, 0x3FC9
    ctx->r5 = S32(0X3FC9 << 16);
    // 0x8005B0A8: ori         $a1, $a1, 0xFDB
    ctx->r5 = ctx->r5 | 0XFDB;
    // 0x8005B0AC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8005B0B0: jal         0x80005D44
    // 0x8005B0B4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateX(rdram, ctx);
        goto after_17;
    // 0x8005B0B4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_17:
    // 0x8005B0B8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005B0BC: lwc1        $f4, 0x6140($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6140);
    // 0x8005B0C0: lwc1        $f6, 0x54($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8005B0C4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8005B0C8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8005B0CC: mul.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8005B0D0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8005B0D4: jal         0x80005E90
    // 0x8005B0D8: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    Matrix_RotateY(rdram, ctx);
        goto after_18;
    // 0x8005B0D8: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    after_18:
    // 0x8005B0DC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8005B0E0: jal         0x80006EB8
    // 0x8005B0E4: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_19;
    // 0x8005B0E4: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    after_19:
    // 0x8005B0E8: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x8005B0EC: addiu       $a2, $a2, 0x7E64
    ctx->r6 = ADD32(ctx->r6, 0X7E64);
    // 0x8005B0F0: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x8005B0F4: lui         $a1, 0x103
    ctx->r5 = S32(0X103 << 16);
    // 0x8005B0F8: addiu       $a1, $a1, -0x5760
    ctx->r5 = ADD32(ctx->r5, -0X5760);
    // 0x8005B0FC: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x8005B100: sw          $t4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r12;
    // 0x8005B104: lui         $t5, 0x600
    ctx->r13 = S32(0X600 << 16);
    // 0x8005B108: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8005B10C: sw          $a1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r5;
    // 0x8005B110: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005B114: jal         0x80005740
    // 0x8005B118: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    Matrix_Pop(rdram, ctx);
        goto after_20;
    // 0x8005B118: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_20:
    // 0x8005B11C: jal         0x80005708
    // 0x8005B120: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_Push(rdram, ctx);
        goto after_21;
    // 0x8005B120: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x8005B124: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8005B128: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8005B12C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8005B130: lui         $a1, 0xC28C
    ctx->r5 = S32(0XC28C << 16);
    // 0x8005B134: lui         $a2, 0xC120
    ctx->r6 = S32(0XC120 << 16);
    // 0x8005B138: jal         0x80005B00
    // 0x8005B13C: lui         $a3, 0xC2C8
    ctx->r7 = S32(0XC2C8 << 16);
    Matrix_Translate(rdram, ctx);
        goto after_22;
    // 0x8005B13C: lui         $a3, 0xC2C8
    ctx->r7 = S32(0XC2C8 << 16);
    after_22:
    // 0x8005B140: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8005B144: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8005B148: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8005B14C: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x8005B150: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8005B154: jal         0x80005C34
    // 0x8005B158: lui         $a3, 0x4248
    ctx->r7 = S32(0X4248 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_23;
    // 0x8005B158: lui         $a3, 0x4248
    ctx->r7 = S32(0X4248 << 16);
    after_23:
    // 0x8005B15C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8005B160: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8005B164: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8005B168: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8005B16C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8005B170: jal         0x80005B00
    // 0x8005B174: lui         $a3, 0xC18C
    ctx->r7 = S32(0XC18C << 16);
    Matrix_Translate(rdram, ctx);
        goto after_24;
    // 0x8005B174: lui         $a3, 0xC18C
    ctx->r7 = S32(0XC18C << 16);
    after_24:
    // 0x8005B178: lui         $a1, 0x3FC9
    ctx->r5 = S32(0X3FC9 << 16);
    // 0x8005B17C: ori         $a1, $a1, 0xFDB
    ctx->r5 = ctx->r5 | 0XFDB;
    // 0x8005B180: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8005B184: jal         0x80005D44
    // 0x8005B188: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateX(rdram, ctx);
        goto after_25;
    // 0x8005B188: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_25:
    // 0x8005B18C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8005B190: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x8005B194: jal         0x80005E90
    // 0x8005B198: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateY(rdram, ctx);
        goto after_26;
    // 0x8005B198: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_26:
    // 0x8005B19C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8005B1A0: jal         0x80006EB8
    // 0x8005B1A4: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_27;
    // 0x8005B1A4: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    after_27:
    // 0x8005B1A8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8005B1AC: lw          $v0, 0x7E64($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7E64);
    // 0x8005B1B0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8005B1B4: lui         $t1, 0x600
    ctx->r9 = S32(0X600 << 16);
    // 0x8005B1B8: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8005B1BC: sw          $t9, 0x7E64($at)
    MEM_W(0X7E64, ctx->r1) = ctx->r25;
    // 0x8005B1C0: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x8005B1C4: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8005B1C8: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x8005B1CC: jal         0x80005740
    // 0x8005B1D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_28;
    // 0x8005B1D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_28:
    // 0x8005B1D4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8005B1D8:
    // 0x8005B1D8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8005B1DC: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x8005B1E0: jr          $ra
    // 0x8005B1E4: nop

    return;
    // 0x8005B1E4: nop

;}
RECOMP_FUNC void ObjSpecial_SetMatrix(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005D3CC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8005D3D0: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8005D3D4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8005D3D8: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8005D3DC: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8005D3E0: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8005D3E4: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8005D3E8: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8005D3EC: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x8005D3F0: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x8005D3F4: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x8005D3F8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8005D3FC: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x8005D400: bne         $t6, $at, L_8005D53C
    if (ctx->r14 != ctx->r1) {
        // 0x8005D404: nop
    
            goto L_8005D53C;
    }
    // 0x8005D404: nop

    // 0x8005D408: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8005D40C: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x8005D410: addiu       $s0, $s0, -0x4C40
    ctx->r16 = ADD32(ctx->r16, -0X4C40);
    // 0x8005D414: lui         $a3, 0x8017
    ctx->r7 = S32(0X8017 << 16);
    // 0x8005D418: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8005D41C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8005D420: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8005D424: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8005D428: lw          $a3, 0x7D20($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X7D20);
    // 0x8005D42C: jal         0x80005B00
    // 0x8005D430: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_0;
    // 0x8005D430: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_0:
    // 0x8005D434: lui         $s2, 0x8014
    ctx->r18 = S32(0X8014 << 16);
    // 0x8005D438: addiu       $s2, $s2, -0x4438
    ctx->r18 = ADD32(ctx->r18, -0X4438);
    // 0x8005D43C: lw          $a1, 0x4($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X4);
    // 0x8005D440: lw          $a2, 0x8($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X8);
    // 0x8005D444: lw          $a3, 0xC($s1)
    ctx->r7 = MEM_W(ctx->r17, 0XC);
    // 0x8005D448: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8005D44C: jal         0x80005B00
    // 0x8005D450: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_1;
    // 0x8005D450: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_1:
    // 0x8005D454: jal         0x80005708
    // 0x8005D458: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_Push(rdram, ctx);
        goto after_2;
    // 0x8005D458: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8005D45C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8005D460: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    // 0x8005D464: jal         0x80005754
    // 0x8005D468: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_Mult(rdram, ctx);
        goto after_3;
    // 0x8005D468: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x8005D46C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8005D470: addiu       $a0, $a0, 0x15F0
    ctx->r4 = ADD32(ctx->r4, 0X15F0);
    // 0x8005D474: jal         0x80005680
    // 0x8005D478: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    Matrix_Copy(rdram, ctx);
        goto after_4;
    // 0x8005D478: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    after_4:
    // 0x8005D47C: jal         0x80005740
    // 0x8005D480: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_5;
    // 0x8005D480: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8005D484: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005D488: lwc1        $f20, 0x62E4($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X62E4);
    // 0x8005D48C: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8005D490: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8005D494: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8005D498: mul.s       $f6, $f20, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f4.fl);
    // 0x8005D49C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8005D4A0: jal         0x80005E90
    // 0x8005D4A4: nop

    Matrix_RotateY(rdram, ctx);
        goto after_6;
    // 0x8005D4A4: nop

    after_6:
    // 0x8005D4A8: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8005D4AC: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8005D4B0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8005D4B4: mul.s       $f10, $f20, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f20.fl, ctx->f8.fl);
    // 0x8005D4B8: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8005D4BC: jal         0x80005D44
    // 0x8005D4C0: nop

    Matrix_RotateX(rdram, ctx);
        goto after_7;
    // 0x8005D4C0: nop

    after_7:
    // 0x8005D4C4: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8005D4C8: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8005D4CC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8005D4D0: mul.s       $f18, $f20, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f20.fl, ctx->f16.fl);
    // 0x8005D4D4: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8005D4D8: jal         0x80005FE0
    // 0x8005D4DC: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_8;
    // 0x8005D4DC: nop

    after_8:
    // 0x8005D4E0: lwc1        $f4, 0x14($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8005D4E4: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8005D4E8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8005D4EC: mul.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x8005D4F0: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8005D4F4: jal         0x80005E90
    // 0x8005D4F8: nop

    Matrix_RotateY(rdram, ctx);
        goto after_9;
    // 0x8005D4F8: nop

    after_9:
    // 0x8005D4FC: lwc1        $f8, 0x10($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8005D500: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8005D504: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8005D508: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x8005D50C: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8005D510: jal         0x80005D44
    // 0x8005D514: nop

    Matrix_RotateX(rdram, ctx);
        goto after_10;
    // 0x8005D514: nop

    after_10:
    // 0x8005D518: lwc1        $f16, 0x18($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X18);
    // 0x8005D51C: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8005D520: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8005D524: mul.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f20.fl);
    // 0x8005D528: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8005D52C: jal         0x80005FE0
    // 0x8005D530: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_11;
    // 0x8005D530: nop

    after_11:
    // 0x8005D534: b           L_8005D63C
    // 0x8005D538: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_8005D63C;
    // 0x8005D538: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_8005D53C:
    // 0x8005D53C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005D540: lwc1        $f6, 0x7D20($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x8005D544: lwc1        $f4, 0xC($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8005D548: addiu       $s0, $s0, -0x4C40
    ctx->r16 = ADD32(ctx->r16, -0X4C40);
    // 0x8005D54C: lw          $a1, 0x4($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X4);
    // 0x8005D550: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8005D554: lw          $a2, 0x8($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X8);
    // 0x8005D558: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8005D55C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8005D560: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x8005D564: jal         0x80005B00
    // 0x8005D568: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_12;
    // 0x8005D568: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_12:
    // 0x8005D56C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8005D570: addiu       $a0, $a0, 0x15F0
    ctx->r4 = ADD32(ctx->r4, 0X15F0);
    // 0x8005D574: jal         0x80005680
    // 0x8005D578: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    Matrix_Copy(rdram, ctx);
        goto after_13;
    // 0x8005D578: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    after_13:
    // 0x8005D57C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005D580: lwc1        $f20, 0x62E8($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X62E8);
    // 0x8005D584: lwc1        $f10, 0x40($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8005D588: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8005D58C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8005D590: mul.s       $f16, $f20, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f20.fl, ctx->f10.fl);
    // 0x8005D594: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8005D598: jal         0x80005E90
    // 0x8005D59C: nop

    Matrix_RotateY(rdram, ctx);
        goto after_14;
    // 0x8005D59C: nop

    after_14:
    // 0x8005D5A0: lwc1        $f18, 0x3C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8005D5A4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8005D5A8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8005D5AC: mul.s       $f4, $f20, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f18.fl);
    // 0x8005D5B0: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8005D5B4: jal         0x80005D44
    // 0x8005D5B8: nop

    Matrix_RotateX(rdram, ctx);
        goto after_15;
    // 0x8005D5B8: nop

    after_15:
    // 0x8005D5BC: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8005D5C0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8005D5C4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8005D5C8: mul.s       $f8, $f20, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f6.fl);
    // 0x8005D5CC: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8005D5D0: jal         0x80005FE0
    // 0x8005D5D4: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_16;
    // 0x8005D5D4: nop

    after_16:
    // 0x8005D5D8: lwc1        $f10, 0x14($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8005D5DC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8005D5E0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8005D5E4: mul.s       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x8005D5E8: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8005D5EC: jal         0x80005E90
    // 0x8005D5F0: nop

    Matrix_RotateY(rdram, ctx);
        goto after_17;
    // 0x8005D5F0: nop

    after_17:
    // 0x8005D5F4: lwc1        $f18, 0x10($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8005D5F8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8005D5FC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8005D600: mul.s       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x8005D604: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8005D608: jal         0x80005D44
    // 0x8005D60C: nop

    Matrix_RotateX(rdram, ctx);
        goto after_18;
    // 0x8005D60C: nop

    after_18:
    // 0x8005D610: lwc1        $f6, 0x18($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X18);
    // 0x8005D614: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8005D618: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8005D61C: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x8005D620: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8005D624: jal         0x80005FE0
    // 0x8005D628: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_19;
    // 0x8005D628: nop

    after_19:
    // 0x8005D62C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8005D630: jal         0x80006EB8
    // 0x8005D634: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_20;
    // 0x8005D634: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    after_20:
    // 0x8005D638: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_8005D63C:
    // 0x8005D63C: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8005D640: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8005D644: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8005D648: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8005D64C: jr          $ra
    // 0x8005D650: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8005D650: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void Effect_SpawnById1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007EE68: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x8007EE6C: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x8007EE70: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x8007EE74: sw          $s2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r18;
    // 0x8007EE78: sw          $s1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r17;
    // 0x8007EE7C: sdc1        $f20, 0x48($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X48, ctx->r29);
    // 0x8007EE80: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007EE84: lwc1        $f20, 0x7488($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X7488);
    // 0x8007EE88: or          $s1, $a3, $zero
    ctx->r17 = ctx->r7 | 0;
    // 0x8007EE8C: or          $s2, $a2, $zero
    ctx->r18 = ctx->r6 | 0;
    // 0x8007EE90: addiu       $s0, $s0, -0x4438
    ctx->r16 = ADD32(ctx->r16, -0X4438);
    // 0x8007EE94: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x8007EE98: sw          $a0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r4;
    // 0x8007EE9C: sw          $a1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r5;
    // 0x8007EEA0: lwc1        $f4, 0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8007EEA4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8007EEA8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8007EEAC: mul.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x8007EEB0: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8007EEB4: jal         0x80005E90
    // 0x8007EEB8: nop

    Matrix_RotateY(rdram, ctx);
        goto after_0;
    // 0x8007EEB8: nop

    after_0:
    // 0x8007EEBC: lwc1        $f8, 0x0($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8007EEC0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8007EEC4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8007EEC8: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x8007EECC: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8007EED0: jal         0x80005D44
    // 0x8007EED4: nop

    Matrix_RotateX(rdram, ctx);
        goto after_1;
    // 0x8007EED4: nop

    after_1:
    // 0x8007EED8: lwc1        $f16, 0x8($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8007EEDC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8007EEE0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8007EEE4: mul.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f20.fl);
    // 0x8007EEE8: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8007EEEC: jal         0x80005FE0
    // 0x8007EEF0: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_2;
    // 0x8007EEF0: nop

    after_2:
    // 0x8007EEF4: lwc1        $f4, 0x4($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X4);
    // 0x8007EEF8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8007EEFC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8007EF00: mul.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x8007EF04: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8007EF08: jal         0x80005E90
    // 0x8007EF0C: nop

    Matrix_RotateY(rdram, ctx);
        goto after_3;
    // 0x8007EF0C: nop

    after_3:
    // 0x8007EF10: lwc1        $f8, 0x0($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X0);
    // 0x8007EF14: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8007EF18: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8007EF1C: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x8007EF20: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8007EF24: jal         0x80005D44
    // 0x8007EF28: nop

    Matrix_RotateX(rdram, ctx);
        goto after_4;
    // 0x8007EF28: nop

    after_4:
    // 0x8007EF2C: lwc1        $f16, 0x8($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X8);
    // 0x8007EF30: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8007EF34: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8007EF38: mul.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f20.fl);
    // 0x8007EF3C: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8007EF40: jal         0x80005FE0
    // 0x8007EF44: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_5;
    // 0x8007EF44: nop

    after_5:
    // 0x8007EF48: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8007EF4C: lw          $a1, 0x88($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X88);
    // 0x8007EF50: jal         0x80006970
    // 0x8007EF54: addiu       $a2, $sp, 0x68
    ctx->r6 = ADD32(ctx->r29, 0X68);
    Matrix_MultVec3f(rdram, ctx);
        goto after_6;
    // 0x8007EF54: addiu       $a2, $sp, 0x68
    ctx->r6 = ADD32(ctx->r29, 0X68);
    after_6:
    // 0x8007EF58: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8007EF5C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8007EF60: addiu       $v0, $v0, 0x130
    ctx->r2 = ADD32(ctx->r2, 0X130);
    // 0x8007EF64: addiu       $a0, $a0, 0x3754
    ctx->r4 = ADD32(ctx->r4, 0X3754);
    // 0x8007EF68: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
L_8007EF6C:
    // 0x8007EF6C: bnel        $t6, $zero, L_8007F024
    if (ctx->r14 != 0) {
        // 0x8007EF70: addiu       $a0, $a0, -0x8C
        ctx->r4 = ADD32(ctx->r4, -0X8C);
            goto L_8007F024;
    }
    goto skip_0;
    // 0x8007EF70: addiu       $a0, $a0, -0x8C
    ctx->r4 = ADD32(ctx->r4, -0X8C);
    skip_0:
    // 0x8007EF74: lw          $v0, 0x7C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X7C);
    // 0x8007EF78: lwc1        $f6, 0x68($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8007EF7C: lwc1        $f16, 0x6C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8007EF80: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8007EF84: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8007EF88: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8007EF8C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8007EF90: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8007EF94: lw          $a1, 0x78($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X78);
    // 0x8007EF98: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8007EF9C: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x8007EFA0: lwc1        $f8, 0x70($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8007EFA4: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x8007EFA8: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8007EFAC: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x8007EFB0: lwc1        $f18, 0x0($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X0);
    // 0x8007EFB4: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x8007EFB8: lwc1        $f4, 0x4($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X4);
    // 0x8007EFBC: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x8007EFC0: lwc1        $f10, 0x8($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X8);
    // 0x8007EFC4: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x8007EFC8: lwc1        $f18, 0x0($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8007EFCC: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    // 0x8007EFD0: lwc1        $f4, 0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8007EFD4: lwc1        $f18, 0x79E4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X79E4);
    // 0x8007EFD8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8007EFDC: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x8007EFE0: lwc1        $f10, 0x8($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8007EFE4: add.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x8007EFE8: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x8007EFEC: lwc1        $f10, 0x79F4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X79F4);
    // 0x8007EFF0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8007EFF4: lwc1        $f18, 0x7D08($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7D08);
    // 0x8007EFF8: add.s       $f6, $f16, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x8007EFFC: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x8007F000: lwc1        $f16, 0x8C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x8007F004: sub.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x8007F008: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    // 0x8007F00C: swc1        $f16, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f16.u32l;
    // 0x8007F010: jal         0x8007ED54
    // 0x8007F014: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    Effect_SetupById(rdram, ctx);
        goto after_7;
    // 0x8007F014: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    after_7:
    // 0x8007F018: b           L_8007F034
    // 0x8007F01C: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
        goto L_8007F034;
    // 0x8007F01C: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x8007F020: addiu       $a0, $a0, -0x8C
    ctx->r4 = ADD32(ctx->r4, -0X8C);
L_8007F024:
    // 0x8007F024: sltu        $at, $a0, $v0
    ctx->r1 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x8007F028: beql        $at, $zero, L_8007EF6C
    if (ctx->r1 == 0) {
        // 0x8007F02C: lbu         $t6, 0x0($a0)
        ctx->r14 = MEM_BU(ctx->r4, 0X0);
            goto L_8007EF6C;
    }
    goto skip_1;
    // 0x8007F02C: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    skip_1:
    // 0x8007F030: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
L_8007F034:
    // 0x8007F034: ldc1        $f20, 0x48($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X48);
    // 0x8007F038: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x8007F03C: lw          $s1, 0x54($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X54);
    // 0x8007F040: lw          $s2, 0x58($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X58);
    // 0x8007F044: jr          $ra
    // 0x8007F048: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x8007F048: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void Play_SpawnHitmark(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A668C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A6690: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A6694: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    // 0x800A6698: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    // 0x800A669C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800A66A0: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x800A66A4: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800A66A8: addiu       $v0, $v0, 0x4750
    ctx->r2 = ADD32(ctx->r2, 0X4750);
    // 0x800A66AC: addiu       $a0, $a0, 0x4050
    ctx->r4 = ADD32(ctx->r4, 0X4050);
    // 0x800A66B0: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
L_800A66B4:
    // 0x800A66B4: bnel        $t6, $zero, L_800A66F4
    if (ctx->r14 != 0) {
        // 0x800A66B8: addiu       $a0, $a0, 0x70
        ctx->r4 = ADD32(ctx->r4, 0X70);
            goto L_800A66F4;
    }
    goto skip_0;
    // 0x800A66B8: addiu       $a0, $a0, 0x70
    ctx->r4 = ADD32(ctx->r4, 0X70);
    skip_0:
    // 0x800A66BC: jal         0x80035E48
    // 0x800A66C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    PlayerShot_Initialize(rdram, ctx);
        goto after_0;
    // 0x800A66C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800A66C4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800A66C8: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800A66CC: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800A66D0: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800A66D4: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x800A66D8: sb          $t7, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r15;
    // 0x800A66DC: sw          $zero, 0x60($a0)
    MEM_W(0X60, ctx->r4) = 0;
    // 0x800A66E0: swc1        $f4, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f4.u32l;
    // 0x800A66E4: swc1        $f6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f6.u32l;
    // 0x800A66E8: b           L_800A66FC
    // 0x800A66EC: swc1        $f8, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f8.u32l;
        goto L_800A66FC;
    // 0x800A66EC: swc1        $f8, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f8.u32l;
    // 0x800A66F0: addiu       $a0, $a0, 0x70
    ctx->r4 = ADD32(ctx->r4, 0X70);
L_800A66F4:
    // 0x800A66F4: bnel        $a0, $v0, L_800A66B4
    if (ctx->r4 != ctx->r2) {
        // 0x800A66F8: lbu         $t6, 0x0($a0)
        ctx->r14 = MEM_BU(ctx->r4, 0X0);
            goto L_800A66B4;
    }
    goto skip_1;
    // 0x800A66F8: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    skip_1:
L_800A66FC:
    // 0x800A66FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A6700: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800A6704: jr          $ra
    // 0x800A6708: nop

    return;
    // 0x800A6708: nop

;}
RECOMP_FUNC void AudioLoad_SyncDma(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000FA28: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8000FA2C: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8000FA30: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8000FA34: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8000FA38: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x8000FA3C: addiu       $s0, $a2, 0xF
    ctx->r16 = ADD32(ctx->r6, 0XF);
    // 0x8000FA40: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x8000FA44: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8000FA48: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8000FA4C: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x8000FA50: and         $t6, $s0, $at
    ctx->r14 = ctx->r16 & ctx->r1;
    // 0x8000FA54: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8000FA58: or          $s5, $a3, $zero
    ctx->r21 = ctx->r7 | 0;
    // 0x8000FA5C: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x8000FA60: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x8000FA64: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x8000FA68: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
    // 0x8000FA6C: jal         0x80021740
    // 0x8000FA70: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    osInvalDCache_recomp(rdram, ctx);
        goto after_0;
    // 0x8000FA70: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    after_0:
    // 0x8000FA74: lui         $s6, 0x8015
    ctx->r22 = S32(0X8015 << 16);
    // 0x8000FA78: lui         $s4, 0x800C
    ctx->r20 = S32(0X800C << 16);
    // 0x8000FA7C: lui         $s3, 0x8015
    ctx->r19 = S32(0X8015 << 16);
    // 0x8000FA80: addiu       $s3, $s3, 0x4A10
    ctx->r19 = ADD32(ctx->r19, 0X4A10);
    // 0x8000FA84: addiu       $s4, $s4, 0x50E8
    ctx->r20 = ADD32(ctx->r20, 0X50E8);
    // 0x8000FA88: addiu       $s6, $s6, 0x4A30
    ctx->r22 = ADD32(ctx->r22, 0X4A30);
    // 0x8000FA8C: sltiu       $at, $s0, 0x400
    ctx->r1 = ctx->r16 < 0X400 ? 1 : 0;
    // 0x8000FA90: bne         $at, $zero, L_8000FAE4
    if (ctx->r1 != 0) {
        // 0x8000FA94: addiu       $t7, $zero, 0x400
        ctx->r15 = ADD32(0, 0X400);
            goto L_8000FAE4;
    }
L_8000FA94:
    // 0x8000FA94: addiu       $t7, $zero, 0x400
    ctx->r15 = ADD32(0, 0X400);
    // 0x8000FA98: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8000FA9C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8000FAA0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8000FAA4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8000FAA8: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    // 0x8000FAAC: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    // 0x8000FAB0: sw          $s3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r19;
    // 0x8000FAB4: sw          $s5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r21;
    // 0x8000FAB8: jal         0x8000FBA8
    // 0x8000FABC: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    AudioLoad_Dma(rdram, ctx);
        goto after_1;
    // 0x8000FABC: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    after_1:
    // 0x8000FAC0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8000FAC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8000FAC8: jal         0x800205E0
    // 0x8000FACC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x8000FACC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x8000FAD0: addiu       $s0, $s0, -0x400
    ctx->r16 = ADD32(ctx->r16, -0X400);
    // 0x8000FAD4: sltiu       $at, $s0, 0x400
    ctx->r1 = ctx->r16 < 0X400 ? 1 : 0;
    // 0x8000FAD8: addiu       $s2, $s2, 0x400
    ctx->r18 = ADD32(ctx->r18, 0X400);
    // 0x8000FADC: beq         $at, $zero, L_8000FA94
    if (ctx->r1 == 0) {
        // 0x8000FAE0: addiu       $s1, $s1, 0x400
        ctx->r17 = ADD32(ctx->r17, 0X400);
            goto L_8000FA94;
    }
    // 0x8000FAE0: addiu       $s1, $s1, 0x400
    ctx->r17 = ADD32(ctx->r17, 0X400);
L_8000FAE4:
    // 0x8000FAE4: beq         $s0, $zero, L_8000FB28
    if (ctx->r16 == 0) {
        // 0x8000FAE8: or          $a0, $s6, $zero
        ctx->r4 = ctx->r22 | 0;
            goto L_8000FB28;
    }
    // 0x8000FAE8: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8000FAEC: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x8000FAF0: addiu       $t8, $t8, 0x50F4
    ctx->r24 = ADD32(ctx->r24, 0X50F4);
    // 0x8000FAF4: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x8000FAF8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8000FAFC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8000FB00: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    // 0x8000FB04: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    // 0x8000FB08: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8000FB0C: sw          $s3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r19;
    // 0x8000FB10: jal         0x8000FBA8
    // 0x8000FB14: sw          $s5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r21;
    AudioLoad_Dma(rdram, ctx);
        goto after_3;
    // 0x8000FB14: sw          $s5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r21;
    after_3:
    // 0x8000FB18: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8000FB1C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8000FB20: jal         0x800205E0
    // 0x8000FB24: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_4;
    // 0x8000FB24: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
L_8000FB28:
    // 0x8000FB28: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x8000FB2C: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8000FB30: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x8000FB34: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x8000FB38: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x8000FB3C: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x8000FB40: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x8000FB44: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x8000FB48: jr          $ra
    // 0x8000FB4C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8000FB4C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void Math_Fabs(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001FB24: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x8001FB28: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8001FB2C: nop

    // 0x8001FB30: c.lt.d      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.d < ctx->f4.d;
    // 0x8001FB34: nop

    // 0x8001FB38: bc1fl       L_8001FB50
    if (!c1cs) {
        // 0x8001FB3C: mov.d       $f2, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.d = ctx->f12.d;
            goto L_8001FB50;
    }
    goto skip_0;
    // 0x8001FB3C: mov.d       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.d = ctx->f12.d;
    skip_0:
    // 0x8001FB40: neg.d       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.d); 
    ctx->f2.d = -ctx->f12.d;
    // 0x8001FB44: jr          $ra
    // 0x8001FB48: mov.d       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.d = ctx->f2.d;
    return;
    // 0x8001FB48: mov.d       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.d = ctx->f2.d;
    // 0x8001FB4C: mov.d       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.d = ctx->f12.d;
L_8001FB50:
    // 0x8001FB50: jr          $ra
    // 0x8001FB54: mov.d       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.d = ctx->f2.d;
    return;
    // 0x8001FB54: mov.d       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.d = ctx->f2.d;
;}
RECOMP_FUNC void MeHopBot_PostLimbDraw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800599A4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800599A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800599AC: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800599B0: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800599B4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800599B8: bne         $a0, $at, L_80059A14
    if (ctx->r4 != ctx->r1) {
        // 0x800599BC: addiu       $a1, $sp, 0x24
        ctx->r5 = ADD32(ctx->r29, 0X24);
            goto L_80059A14;
    }
    // 0x800599BC: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x800599C0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800599C4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800599C8: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x800599CC: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    // 0x800599D0: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x800599D4: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x800599D8: jal         0x80006970
    // 0x800599DC: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    Matrix_MultVec3f(rdram, ctx);
        goto after_0;
    // 0x800599DC: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x800599E0: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x800599E4: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800599E8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800599EC: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800599F0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800599F4: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800599F8: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x800599FC: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80059A00: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80059A04: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80059A08: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80059A0C: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80059A10: swc1        $f4, 0x40F4($at)
    MEM_W(0X40F4, ctx->r1) = ctx->f4.u32l;
L_80059A14:
    // 0x80059A14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80059A18: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80059A1C: jr          $ra
    // 0x80059A20: nop

    return;
    // 0x80059A20: nop

;}
RECOMP_FUNC void guPerspectiveF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020F40: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80020F44: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x80020F48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80020F4C: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x80020F50: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80020F54: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80020F58: jal         0x80026DD0
    // 0x80020F5C: swc1        $f14, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f14.u32l;
    guMtxIdentF(rdram, ctx);
        goto after_0;
    // 0x80020F5C: swc1        $f14, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x80020F60: lwc1        $f14, 0x38($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80020F64: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80020F68: ldc1        $f6, -0x6CD0($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X6CD0);
    // 0x80020F6C: cvt.d.s     $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f4.d = CVT_D_S(ctx->f14.fl);
    // 0x80020F70: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80020F74: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x80020F78: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80020F7C: cvt.s.d     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f14.fl = CVT_S_D(ctx->f8.d);
    // 0x80020F80: div.s       $f12, $f14, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = DIV_S(ctx->f14.fl, ctx->f10.fl);
    // 0x80020F84: jal         0x80023250
    // 0x80020F88: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    __cosf_recomp(rdram, ctx);
        goto after_1;
    // 0x80020F88: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    after_1:
    // 0x80020F8C: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80020F90: jal         0x80023090
    // 0x80020F94: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    __sinf_recomp(rdram, ctx);
        goto after_2;
    // 0x80020F94: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x80020F98: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80020F9C: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80020FA0: lwc1        $f14, 0x40($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80020FA4: div.s       $f2, $f4, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80020FA8: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80020FAC: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80020FB0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80020FB4: add.s       $f18, $f14, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f14.fl + ctx->f16.fl;
    // 0x80020FB8: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x80020FBC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80020FC0: sub.s       $f12, $f14, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f14.fl - ctx->f16.fl;
    // 0x80020FC4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80020FC8: swc1        $f4, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f4.u32l;
    // 0x80020FCC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80020FD0: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80020FD4: div.s       $f10, $f18, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = DIV_S(ctx->f18.fl, ctx->f12.fl);
    // 0x80020FD8: swc1        $f2, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f2.u32l;
    // 0x80020FDC: div.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f2.fl, ctx->f6.fl);
    // 0x80020FE0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80020FE4: swc1        $f10, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f10.u32l;
    // 0x80020FE8: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x80020FEC: mul.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x80020FF0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80020FF4: nop

    // 0x80020FF8: swc1        $f6, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->f6.u32l;
    // 0x80020FFC: mul.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80021000: div.s       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = DIV_S(ctx->f10.fl, ctx->f12.fl);
    // 0x80021004: swc1        $f4, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f4.u32l;
    // 0x80021008: lwc1        $f0, 0x48($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8002100C: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80021010: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80021014: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80021018: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8002101C: lwc1        $f12, 0x8($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80021020: beq         $v1, $a0, L_80021064
    if (ctx->r3 == ctx->r4) {
        // 0x80021024: lwc1        $f14, 0xC($v0)
        ctx->f14.u32l = MEM_W(ctx->r2, 0XC);
            goto L_80021064;
    }
    // 0x80021024: lwc1        $f14, 0xC($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0XC);
L_80021028:
    // 0x80021028: mul.s       $f8, $f16, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8002102C: lwc1        $f6, 0x10($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80021030: lwc1        $f16, 0x14($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80021034: mul.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x80021038: lwc1        $f12, 0x18($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X18);
    // 0x8002103C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80021040: mul.s       $f2, $f14, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x80021044: lwc1        $f14, 0x1C($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80021048: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
    // 0x8002104C: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80021050: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
    // 0x80021054: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x80021058: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8002105C: bne         $v1, $a0, L_80021028
    if (ctx->r3 != ctx->r4) {
        // 0x80021060: swc1        $f2, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f2.u32l;
            goto L_80021028;
    }
    // 0x80021060: swc1        $f2, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f2.u32l;
L_80021064:
    // 0x80021064: mul.s       $f8, $f16, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80021068: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8002106C: swc1        $f10, -0x10($v0)
    MEM_W(-0X10, ctx->r2) = ctx->f10.u32l;
    // 0x80021070: mul.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x80021074: nop

    // 0x80021078: mul.s       $f2, $f14, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x8002107C: swc1        $f8, -0xC($v0)
    MEM_W(-0XC, ctx->r2) = ctx->f8.u32l;
    // 0x80021080: swc1        $f4, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f4.u32l;
    // 0x80021084: swc1        $f2, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f2.u32l;
    // 0x80021088: beq         $a1, $zero, L_80021160
    if (ctx->r5 == 0) {
        // 0x8002108C: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_80021160;
    }
    // 0x8002108C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80021090: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80021094: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80021098: cvt.d.s     $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f0.d = CVT_D_S(ctx->f18.fl);
    // 0x8002109C: ori         $t6, $zero, 0xFFFF
    ctx->r14 = 0 | 0XFFFF;
    // 0x800210A0: c.le.d      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.d <= ctx->f8.d;
    // 0x800210A4: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x800210A8: bc1fl       L_800210BC
    if (!c1cs) {
        // 0x800210AC: mtc1        $at, $f11
        ctx->f_odd[(11 - 1) * 2] = ctx->r1;
            goto L_800210BC;
    }
    goto skip_0;
    // 0x800210AC: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    skip_0:
    // 0x800210B0: b           L_80021160
    // 0x800210B4: sh          $t6, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r14;
        goto L_80021160;
    // 0x800210B4: sh          $t6, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r14;
    // 0x800210B8: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
L_800210BC:
    // 0x800210BC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800210C0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800210C4: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x800210C8: div.d       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = DIV_D(ctx->f10.d, ctx->f0.d);
    // 0x800210CC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800210D0: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800210D4: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800210D8: nop

    // 0x800210DC: cvt.w.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_D(ctx->f4.d);
    // 0x800210E0: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800210E4: nop

    // 0x800210E8: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x800210EC: beql        $t8, $zero, L_80021140
    if (ctx->r24 == 0) {
        // 0x800210F0: mfc1        $t8, $f6
        ctx->r24 = (int32_t)ctx->f6.u32l;
            goto L_80021140;
    }
    goto skip_1;
    // 0x800210F0: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    skip_1:
    // 0x800210F4: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800210F8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800210FC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80021100: sub.d       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f6.d = ctx->f4.d - ctx->f6.d;
    // 0x80021104: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80021108: nop

    // 0x8002110C: cvt.w.d     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_D(ctx->f6.d);
    // 0x80021110: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80021114: nop

    // 0x80021118: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x8002111C: bne         $t8, $zero, L_80021134
    if (ctx->r24 != 0) {
        // 0x80021120: nop
    
            goto L_80021134;
    }
    // 0x80021120: nop

    // 0x80021124: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x80021128: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8002112C: b           L_8002114C
    // 0x80021130: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_8002114C;
    // 0x80021130: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_80021134:
    // 0x80021134: b           L_8002114C
    // 0x80021138: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_8002114C;
    // 0x80021138: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8002113C: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
L_80021140:
    // 0x80021140: nop

    // 0x80021144: bltz        $t8, L_80021134
    if (SIGNED(ctx->r24) < 0) {
        // 0x80021148: nop
    
            goto L_80021134;
    }
    // 0x80021148: nop

L_8002114C:
    // 0x8002114C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80021150: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x80021154: bgtz        $t9, L_80021160
    if (SIGNED(ctx->r25) > 0) {
        // 0x80021158: sh          $t8, 0x0($a1)
        MEM_H(0X0, ctx->r5) = ctx->r24;
            goto L_80021160;
    }
    // 0x80021158: sh          $t8, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r24;
    // 0x8002115C: sh          $t0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r8;
L_80021160:
    // 0x80021160: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80021164: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80021168: jr          $ra
    // 0x8002116C: nop

    return;
    // 0x8002116C: nop

;}
RECOMP_FUNC void MeteoTunnel_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059AEC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80059AF0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80059AF4: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x80059AF8: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80059AFC: lui         $t8, 0x602
    ctx->r24 = S32(0X602 << 16);
    // 0x80059B00: addiu       $t8, $t8, -0x51C0
    ctx->r24 = ADD32(ctx->r24, -0X51C0);
    // 0x80059B04: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80059B08: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80059B0C: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80059B10: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80059B14: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80059B18: jr          $ra
    // 0x80059B1C: nop

    return;
    // 0x80059B1C: nop

;}
RECOMP_FUNC void Rand_ZeroOne(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004EB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80004EB4: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80004EB8: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80004EBC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80004EC0: addiu       $a0, $a0, -0x4C54
    ctx->r4 = ADD32(ctx->r4, -0X4C54);
    // 0x80004EC4: addiu       $v1, $v1, -0x4C58
    ctx->r3 = ADD32(ctx->r3, -0X4C58);
    // 0x80004EC8: addiu       $v0, $v0, -0x4C5C
    ctx->r2 = ADD32(ctx->r2, -0X4C5C);
    // 0x80004ECC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80004ED0: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80004ED4: addiu       $at, $zero, 0x763D
    ctx->r1 = ADD32(0, 0X763D);
    // 0x80004ED8: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x80004EDC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80004EE0: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80004EE4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80004EE8: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80004EEC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80004EF0: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80004EF4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80004EF8: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80004EFC: div         $zero, $t7, $at
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r1)));
    // 0x80004F00: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80004F04: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x80004F08: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80004F0C: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x80004F10: mfhi        $t5
    ctx->r13 = hi;
    // 0x80004F14: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80004F18: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x80004F1C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80004F20: addiu       $at, $zero, 0x7663
    ctx->r1 = ADD32(0, 0X7663);
    // 0x80004F24: div         $zero, $t0, $at
    lo = S32(S64(S32(ctx->r8)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r8)) % S64(S32(ctx->r1)));
    // 0x80004F28: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x80004F2C: mfhi        $t6
    ctx->r14 = hi;
    // 0x80004F30: addiu       $at, $zero, 0x7673
    ctx->r1 = ADD32(0, 0X7673);
    // 0x80004F34: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80004F38: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80004F3C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80004F40: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80004F44: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80004F48: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80004F4C: sll         $t3, $t3, 1
    ctx->r11 = S32(ctx->r11 << 1);
    // 0x80004F50: div         $zero, $t3, $at
    lo = S32(S64(S32(ctx->r11)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r11)) % S64(S32(ctx->r1)));
    // 0x80004F54: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x80004F58: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x80004F5C: mfhi        $t7
    ctx->r15 = hi;
    // 0x80004F60: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80004F64: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80004F68: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80004F6C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80004F70: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80004F74: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80004F78: lwc1        $f8, -0x7F40($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X7F40);
    // 0x80004F7C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80004F80: lwc1        $f4, -0x7F3C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7F3C);
    // 0x80004F84: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x80004F88: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80004F8C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80004F90: div.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80004F94: lwc1        $f4, -0x7F38($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7F38);
    // 0x80004F98: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80004F9C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80004FA0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80004FA4: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80004FA8: div.s       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80004FAC: jal         0x80004E20
    // 0x80004FB0: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    Math_ModF(rdram, ctx);
        goto after_0;
    // 0x80004FB0: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_0:
    // 0x80004FB4: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80004FB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80004FBC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80004FC0: jr          $ra
    // 0x80004FC4: nop

    return;
    // 0x80004FC4: nop

;}
RECOMP_FUNC void func_effect_80083D2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083D2C: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x80083D30: sdc1        $f26, 0x48($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X48, ctx->r29);
    // 0x80083D34: sdc1        $f24, 0x40($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X40, ctx->r29);
    // 0x80083D38: sdc1        $f22, 0x38($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X38, ctx->r29);
    // 0x80083D3C: mtc1        $a2, $f26
    ctx->f26.u32l = ctx->r6;
    // 0x80083D40: mov.s       $f22, $f12
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    ctx->f22.fl = ctx->f12.fl;
    // 0x80083D44: mov.s       $f24, $f14
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 14);
    ctx->f24.fl = ctx->f14.fl;
    // 0x80083D48: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x80083D4C: sw          $s6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r22;
    // 0x80083D50: sw          $s5, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r21;
    // 0x80083D54: sw          $s4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r20;
    // 0x80083D58: sw          $s3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r19;
    // 0x80083D5C: sw          $s2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r18;
    // 0x80083D60: sw          $s1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r17;
    // 0x80083D64: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x80083D68: sdc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X30, ctx->r29);
    // 0x80083D6C: sw          $a3, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r7;
    // 0x80083D70: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80083D74: lw          $t6, -0x7DCC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7DCC);
    // 0x80083D78: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x80083D7C: beq         $t6, $at, L_80083DBC
    if (ctx->r14 == ctx->r1) {
        // 0x80083D80: lui         $at, 0x432F
        ctx->r1 = S32(0X432F << 16);
            goto L_80083DBC;
    }
    // 0x80083D80: lui         $at, 0x432F
    ctx->r1 = S32(0X432F << 16);
    // 0x80083D84: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80083D88: jal         0x80004EB0
    // 0x80083D8C: swc1        $f2, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f2.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_0;
    // 0x80083D8C: swc1        $f2, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f2.u32l;
    after_0:
    // 0x80083D90: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80083D94: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80083D98: lwc1        $f2, 0x94($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X94);
    // 0x80083D9C: lui         $at, 0xC32F
    ctx->r1 = S32(0XC32F << 16);
    // 0x80083DA0: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80083DA4: nop

    // 0x80083DA8: bc1f        L_80083DF4
    if (!c1cs) {
        // 0x80083DAC: nop
    
            goto L_80083DF4;
    }
    // 0x80083DAC: nop

    // 0x80083DB0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80083DB4: b           L_80083DF4
    // 0x80083DB8: nop

        goto L_80083DF4;
    // 0x80083DB8: nop

L_80083DBC:
    // 0x80083DBC: lui         $at, 0x43AF
    ctx->r1 = S32(0X43AF << 16);
    // 0x80083DC0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80083DC4: jal         0x80004EB0
    // 0x80083DC8: swc1        $f2, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f2.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x80083DC8: swc1        $f2, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f2.u32l;
    after_1:
    // 0x80083DCC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80083DD0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80083DD4: lwc1        $f2, 0x94($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X94);
    // 0x80083DD8: lui         $at, 0xC3AF
    ctx->r1 = S32(0XC3AF << 16);
    // 0x80083DDC: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80083DE0: nop

    // 0x80083DE4: bc1f        L_80083DF4
    if (!c1cs) {
        // 0x80083DE8: nop
    
            goto L_80083DF4;
    }
    // 0x80083DE8: nop

    // 0x80083DEC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80083DF0: nop

L_80083DF4:
    // 0x80083DF4: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80083DF8: lw          $v0, -0x7D80($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D80);
    // 0x80083DFC: lwc1        $f16, 0x78($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X78);
    // 0x80083E00: lwc1        $f8, 0x74($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X74);
    // 0x80083E04: sub.s       $f18, $f16, $f24
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f24.fl;
    // 0x80083E08: add.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x80083E0C: swc1        $f18, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f18.u32l;
    // 0x80083E10: lwc1        $f4, 0x138($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X138);
    // 0x80083E14: sub.s       $f20, $f10, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f20.fl = ctx->f10.fl - ctx->f22.fl;
    // 0x80083E18: sub.s       $f14, $f4, $f26
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f26.fl;
    // 0x80083E1C: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x80083E20: jal         0x80005100
    // 0x80083E24: swc1        $f14, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f14.u32l;
    Math_Atan2F(rdram, ctx);
        goto after_2;
    // 0x80083E24: swc1        $f14, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f14.u32l;
    after_2:
    // 0x80083E28: mul.s       $f6, $f20, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x80083E2C: lwc1        $f2, 0xA0($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x80083E30: swc1        $f0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f0.u32l;
    // 0x80083E34: lwc1        $f12, 0xA4($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x80083E38: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80083E3C: add.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80083E40: jal         0x80005100
    // 0x80083E44: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    Math_Atan2F(rdram, ctx);
        goto after_3;
    // 0x80083E44: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    after_3:
    // 0x80083E48: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x80083E4C: addiu       $s0, $s0, -0x4438
    ctx->r16 = ADD32(ctx->r16, -0X4438);
    // 0x80083E50: neg.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = -ctx->f0.fl;
    // 0x80083E54: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80083E58: lw          $a1, 0x98($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X98);
    // 0x80083E5C: jal         0x80005E90
    // 0x80083E60: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Matrix_RotateY(rdram, ctx);
        goto after_4;
    // 0x80083E60: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x80083E64: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80083E68: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80083E6C: jal         0x80005D44
    // 0x80083E70: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateX(rdram, ctx);
        goto after_5;
    // 0x80083E70: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x80083E74: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80083E78: lwc1        $f10, 0xC4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x80083E7C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80083E80: addiu       $a1, $sp, 0x84
    ctx->r5 = ADD32(ctx->r29, 0X84);
    // 0x80083E84: addiu       $a2, $sp, 0x78
    ctx->r6 = ADD32(ctx->r29, 0X78);
    // 0x80083E88: swc1        $f0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f0.u32l;
    // 0x80083E8C: swc1        $f0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f0.u32l;
    // 0x80083E90: jal         0x80006A20
    // 0x80083E94: swc1        $f10, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f10.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_6;
    // 0x80083E94: swc1        $f10, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f10.u32l;
    after_6:
    // 0x80083E98: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80083E9C: lwc1        $f18, 0x7D08($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7D08);
    // 0x80083EA0: lwc1        $f16, 0x80($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X80);
    // 0x80083EA4: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80083EA8: lui         $s5, 0x800C
    ctx->r21 = S32(0X800C << 16);
    // 0x80083EAC: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80083EB0: lui         $s4, 0x3103
    ctx->r20 = S32(0X3103 << 16);
    // 0x80083EB4: lui         $s3, 0x800C
    ctx->r19 = S32(0X800C << 16);
    // 0x80083EB8: lui         $s1, 0x8017
    ctx->r17 = S32(0X8017 << 16);
    // 0x80083EBC: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80083EC0: swc1        $f4, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f4.u32l;
    // 0x80083EC4: addiu       $s1, $s1, 0x37E0
    ctx->r17 = ADD32(ctx->r17, 0X37E0);
    // 0x80083EC8: addiu       $s3, $s3, 0x5D34
    ctx->r19 = ADD32(ctx->r19, 0X5D34);
    // 0x80083ECC: ori         $s4, $s4, 0x109B
    ctx->r20 = ctx->r20 | 0X109B;
    // 0x80083ED0: addiu       $s5, $s5, 0x5D3C
    ctx->r21 = ADD32(ctx->r21, 0X5D3C);
    // 0x80083ED4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80083ED8: addiu       $s6, $zero, 0x6
    ctx->r22 = ADD32(0, 0X6);
L_80083EDC:
    // 0x80083EDC: lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // 0x80083EE0: addiu       $s0, $s0, 0x130
    ctx->r16 = ADD32(ctx->r16, 0X130);
    // 0x80083EE4: lbu         $t7, 0x0($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X0);
L_80083EE8:
    // 0x80083EE8: bnel        $t7, $zero, L_80083F5C
    if (ctx->r15 != 0) {
        // 0x80083EEC: addiu       $s0, $s0, 0x8C
        ctx->r16 = ADD32(ctx->r16, 0X8C);
            goto L_80083F5C;
    }
    goto skip_0;
    // 0x80083EEC: addiu       $s0, $s0, 0x8C
    ctx->r16 = ADD32(ctx->r16, 0X8C);
    skip_0:
    // 0x80083EF0: mtc1        $s2, $f16
    ctx->f16.u32l = ctx->r18;
    // 0x80083EF4: lwc1        $f6, 0x78($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80083EF8: lwc1        $f8, 0x7C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80083EFC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80083F00: lwc1        $f10, 0x80($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X80);
    // 0x80083F04: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    // 0x80083F08: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x80083F0C: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x80083F10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80083F14: mul.s       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x80083F18: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80083F1C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x80083F20: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x80083F24: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x80083F28: jal         0x80083C70
    // 0x80083F2C: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    Effect_OrbRing_Setup(rdram, ctx);
        goto after_7;
    // 0x80083F2C: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    after_7:
    // 0x80083F30: bne         $s2, $zero, L_80083F64
    if (ctx->r18 != 0) {
        // 0x80083F34: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_80083F64;
    }
    // 0x80083F34: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80083F38: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    // 0x80083F3C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80083F40: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x80083F44: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x80083F48: jal         0x80019218
    // 0x80083F4C: sw          $s5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r21;
    Audio_PlaySfx(rdram, ctx);
        goto after_8;
    // 0x80083F4C: sw          $s5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r21;
    after_8:
    // 0x80083F50: b           L_80083F68
    // 0x80083F54: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
        goto L_80083F68;
    // 0x80083F54: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80083F58: addiu       $s0, $s0, 0x8C
    ctx->r16 = ADD32(ctx->r16, 0X8C);
L_80083F5C:
    // 0x80083F5C: bnel        $s0, $s1, L_80083EE8
    if (ctx->r16 != ctx->r17) {
        // 0x80083F60: lbu         $t7, 0x0($s0)
        ctx->r15 = MEM_BU(ctx->r16, 0X0);
            goto L_80083EE8;
    }
    goto skip_1;
    // 0x80083F60: lbu         $t7, 0x0($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X0);
    skip_1:
L_80083F64:
    // 0x80083F64: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_80083F68:
    // 0x80083F68: bne         $s2, $s6, L_80083EDC
    if (ctx->r18 != ctx->r22) {
        // 0x80083F6C: nop
    
            goto L_80083EDC;
    }
    // 0x80083F6C: nop

    // 0x80083F70: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x80083F74: ldc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X30);
    // 0x80083F78: ldc1        $f22, 0x38($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X38);
    // 0x80083F7C: ldc1        $f24, 0x40($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X40);
    // 0x80083F80: ldc1        $f26, 0x48($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X48);
    // 0x80083F84: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x80083F88: lw          $s1, 0x54($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X54);
    // 0x80083F8C: lw          $s2, 0x58($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X58);
    // 0x80083F90: lw          $s3, 0x5C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X5C);
    // 0x80083F94: lw          $s4, 0x60($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X60);
    // 0x80083F98: lw          $s5, 0x64($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X64);
    // 0x80083F9C: lw          $s6, 0x68($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X68);
    // 0x80083FA0: jr          $ra
    // 0x80083FA4: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    return;
    // 0x80083FA4: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
;}
RECOMP_FUNC void AudioHeap_AllocPersistentSampleCache_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000DC84: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000DC88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000DC8C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8000DC90: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8000DC94: jal         0x8000E208
    // 0x8000DC98: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    AudioHeap_AllocPersistentSampleCacheEntry(rdram, ctx);
        goto after_0;
    // 0x8000DC98: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x8000DC9C: beq         $v0, $zero, L_8000DCC0
    if (ctx->r2 == 0) {
        // 0x8000DCA0: lw          $t6, 0x1C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X1C);
            goto L_8000DCC0;
    }
    // 0x8000DCA0: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8000DCA4: sb          $t6, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r14;
    // 0x8000DCA8: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8000DCAC: sw          $t7, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r15;
    // 0x8000DCB0: lb          $t8, 0x27($sp)
    ctx->r24 = MEM_B(ctx->r29, 0X27);
    // 0x8000DCB4: sb          $t8, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r24;
    // 0x8000DCB8: b           L_8000DCC4
    // 0x8000DCBC: lw          $v0, 0x8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X8);
        goto L_8000DCC4;
    // 0x8000DCBC: lw          $v0, 0x8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X8);
L_8000DCC0:
    // 0x8000DCC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000DCC4:
    // 0x8000DCC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000DCC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000DCCC: jr          $ra
    // 0x8000DCD0: nop

    return;
    // 0x8000DCD0: nop

;}
RECOMP_FUNC void ActorCutscene_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004FEC0: addiu       $sp, $sp, -0x2E0
    ctx->r29 = ADD32(ctx->r29, -0X2E0);
    // 0x8004FEC4: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x8004FEC8: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8004FECC: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8004FED0: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x8004FED4: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x8004FED8: sdc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X30, ctx->r29);
    // 0x8004FEDC: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x8004FEE0: lh          $v0, 0xB6($s2)
    ctx->r2 = MEM_H(ctx->r18, 0XB6);
    // 0x8004FEE4: slti        $at, $v0, 0x30
    ctx->r1 = SIGNED(ctx->r2) < 0X30 ? 1 : 0;
    // 0x8004FEE8: bne         $at, $zero, L_8004FF00
    if (ctx->r1 != 0) {
        // 0x8004FEEC: addiu       $at, $zero, 0x3E8
        ctx->r1 = ADD32(0, 0X3E8);
            goto L_8004FF00;
    }
    // 0x8004FEEC: addiu       $at, $zero, 0x3E8
    ctx->r1 = ADD32(0, 0X3E8);
    // 0x8004FEF0: beq         $v0, $at, L_8004FF20
    if (ctx->r2 == ctx->r1) {
        // 0x8004FEF4: lui         $s1, 0x8013
        ctx->r17 = S32(0X8013 << 16);
            goto L_8004FF20;
    }
    // 0x8004FEF4: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x8004FEF8: b           L_800515A8
    // 0x8004FEFC: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_800515A8;
    // 0x8004FEFC: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_8004FF00:
    // 0x8004FF00: sltiu       $at, $v0, 0x30
    ctx->r1 = ctx->r2 < 0X30 ? 1 : 0;
    // 0x8004FF04: beq         $at, $zero, L_800515A4
    if (ctx->r1 == 0) {
        // 0x8004FF08: sll         $t6, $v0, 2
        ctx->r14 = S32(ctx->r2 << 2);
            goto L_800515A4;
    }
    // 0x8004FF08: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x8004FF0C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004FF10: addu        $at, $at, $t6
    gpr jr_addend_8004FF18 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8004FF14: lw          $t6, 0x5CA4($at)
    ctx->r14 = ADD32(ctx->r1, 0X5CA4);
    // 0x8004FF18: jr          $t6
    // 0x8004FF1C: nop

    switch (jr_addend_8004FF18 >> 2) {
        case 0: goto L_8004FF98; break;
        case 1: goto L_8004FFA8; break;
        case 2: goto L_800515A4; break;
        case 3: goto L_800515A4; break;
        case 4: goto L_800515A4; break;
        case 5: goto L_800515A4; break;
        case 6: goto L_800515A4; break;
        case 7: goto L_800515A4; break;
        case 8: goto L_800515A4; break;
        case 9: goto L_800515A4; break;
        case 10: goto L_80050084; break;
        case 11: goto L_800500F8; break;
        case 12: goto L_800515A4; break;
        case 13: goto L_800515A4; break;
        case 14: goto L_800515A4; break;
        case 15: goto L_800515A4; break;
        case 16: goto L_800515A4; break;
        case 17: goto L_800515A4; break;
        case 18: goto L_800515A4; break;
        case 19: goto L_800515A4; break;
        case 20: goto L_8005021C; break;
        case 21: goto L_800515A4; break;
        case 22: goto L_800515A4; break;
        case 23: goto L_800515A4; break;
        case 24: goto L_8005024C; break;
        case 25: goto L_80050284; break;
        case 26: goto L_800502F0; break;
        case 27: goto L_800515A4; break;
        case 28: goto L_80050350; break;
        case 29: goto L_800515A4; break;
        case 30: goto L_800503B4; break;
        case 31: goto L_80050A98; break;
        case 32: goto L_80050B0C; break;
        case 33: goto L_80050B3C; break;
        case 34: goto L_80050BF4; break;
        case 35: goto L_80050C24; break;
        case 36: goto L_80050C98; break;
        case 37: goto L_80050D04; break;
        case 38: goto L_80050E08; break;
        case 39: goto L_80050C5C; break;
        case 40: goto L_800512E4; break;
        case 41: goto L_80051314; break;
        case 42: goto L_80051324; break;
        case 43: goto L_80051354; break;
        case 44: goto L_80051458; break;
        case 45: goto L_800514E8; break;
        case 46: goto L_8005154C; break;
        case 47: goto L_8005157C; break;
        default: switch_error(__func__, 0x8004FF18, 0x800D5CA4);
    }
    // 0x8004FF1C: nop

L_8004FF20:
    // 0x8004FF20: addiu       $s1, $s1, 0x7E64
    ctx->r17 = ADD32(ctx->r17, 0X7E64);
    // 0x8004FF24: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004FF28: jal         0x800B8DD0
    // 0x8004FF2C: addiu       $a1, $zero, 0x2D
    ctx->r5 = ADD32(0, 0X2D);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x8004FF2C: addiu       $a1, $zero, 0x2D
    ctx->r5 = ADD32(0, 0X2D);
    after_0:
    // 0x8004FF30: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8004FF34: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x8004FF38: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x8004FF3C: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8004FF40: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x8004FF44: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8004FF48: lh          $t9, 0x46($s2)
    ctx->r25 = MEM_H(ctx->r18, 0X46);
    // 0x8004FF4C: lui         $t4, 0x600
    ctx->r12 = S32(0X600 << 16);
    // 0x8004FF50: andi        $t1, $t9, 0xFF
    ctx->r9 = ctx->r25 & 0XFF;
    // 0x8004FF54: or          $t2, $t1, $at
    ctx->r10 = ctx->r9 | ctx->r1;
    // 0x8004FF58: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x8004FF5C: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8004FF60: lui         $t5, 0x400
    ctx->r13 = S32(0X400 << 16);
    // 0x8004FF64: addiu       $t5, $t5, 0x18A0
    ctx->r13 = ADD32(ctx->r13, 0X18A0);
    // 0x8004FF68: addiu       $t3, $v1, 0x8
    ctx->r11 = ADD32(ctx->r3, 0X8);
    // 0x8004FF6C: sw          $t3, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r11;
    // 0x8004FF70: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x8004FF74: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x8004FF78: lh          $t6, 0x46($s2)
    ctx->r14 = MEM_H(ctx->r18, 0X46);
    // 0x8004FF7C: slti        $at, $t6, 0x33
    ctx->r1 = SIGNED(ctx->r14) < 0X33 ? 1 : 0;
    // 0x8004FF80: bnel        $at, $zero, L_800515A8
    if (ctx->r1 != 0) {
        // 0x8004FF84: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_800515A8;
    }
    goto skip_0;
    // 0x8004FF84: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_0:
    // 0x8004FF88: jal         0x8005ADAC
    // 0x8004FF8C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Actor_DrawEngineAndContrails(rdram, ctx);
        goto after_1;
    // 0x8004FF8C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_1:
    // 0x8004FF90: b           L_800515A8
    // 0x8004FF94: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_800515A8;
    // 0x8004FF94: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_8004FF98:
    // 0x8004FF98: jal         0x8005B388
    // 0x8004FF9C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    ActorTeamArwing_Draw(rdram, ctx);
        goto after_2;
    // 0x8004FF9C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_2:
    // 0x8004FFA0: b           L_800515A8
    // 0x8004FFA4: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_800515A8;
    // 0x8004FFA4: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_8004FFA8:
    // 0x8004FFA8: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8004FFAC: lw          $t7, -0x7DCC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7DCC);
    // 0x8004FFB0: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    // 0x8004FFB4: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x8004FFB8: bne         $t7, $at, L_80050070
    if (ctx->r15 != ctx->r1) {
        // 0x8004FFBC: addiu       $s1, $s1, 0x7E64
        ctx->r17 = ADD32(ctx->r17, 0X7E64);
            goto L_80050070;
    }
    // 0x8004FFBC: addiu       $s1, $s1, 0x7E64
    ctx->r17 = ADD32(ctx->r17, 0X7E64);
    // 0x8004FFC0: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8004FFC4: lui         $t9, 0xBC00
    ctx->r25 = S32(0XBC00 << 16);
    // 0x8004FFC8: ori         $t9, $t9, 0x8
    ctx->r25 = ctx->r25 | 0X8;
    // 0x8004FFCC: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8004FFD0: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x8004FFD4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8004FFD8: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8004FFDC: lw          $a0, -0x7C28($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7C28);
    // 0x8004FFE0: addiu       $t1, $zero, 0x3ED
    ctx->r9 = ADD32(0, 0X3ED);
    // 0x8004FFE4: lui         $t2, 0x1
    ctx->r10 = S32(0X1 << 16);
    // 0x8004FFE8: subu        $a1, $t1, $a0
    ctx->r5 = SUB32(ctx->r9, ctx->r4);
    // 0x8004FFEC: ori         $t2, $t2, 0xF400
    ctx->r10 = ctx->r10 | 0XF400;
    // 0x8004FFF0: div         $zero, $t2, $a1
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r5)));
    // 0x8004FFF4: negu        $t6, $a0
    ctx->r14 = SUB32(0, ctx->r4);
    // 0x8004FFF8: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x8004FFFC: addu        $t8, $t7, $t2
    ctx->r24 = ADD32(ctx->r15, ctx->r10);
    // 0x80050000: mflo        $t3
    ctx->r11 = lo;
    // 0x80050004: andi        $t4, $t3, 0xFFFF
    ctx->r12 = ctx->r11 & 0XFFFF;
    // 0x80050008: sll         $t5, $t4, 16
    ctx->r13 = S32(ctx->r12 << 16);
    // 0x8005000C: div         $zero, $t8, $a1
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r5)));
    // 0x80050010: mflo        $t9
    ctx->r25 = lo;
    // 0x80050014: andi        $t1, $t9, 0xFFFF
    ctx->r9 = ctx->r25 & 0XFFFF;
    // 0x80050018: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8005001C: bne         $a1, $zero, L_80050028
    if (ctx->r5 != 0) {
        // 0x80050020: nop
    
            goto L_80050028;
    }
    // 0x80050020: nop

    // 0x80050024: break       7
    do_break(2147811364);
L_80050028:
    // 0x80050028: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8005002C: bne         $a1, $at, L_80050040
    if (ctx->r5 != ctx->r1) {
        // 0x80050030: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80050040;
    }
    // 0x80050030: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80050034: bne         $t2, $at, L_80050040
    if (ctx->r10 != ctx->r1) {
        // 0x80050038: nop
    
            goto L_80050040;
    }
    // 0x80050038: nop

    // 0x8005003C: break       6
    do_break(2147811388);
L_80050040:
    // 0x80050040: addu        $at, $t2, $zero
    ctx->r1 = ADD32(ctx->r10, 0);
    // 0x80050044: or          $t2, $t5, $t1
    ctx->r10 = ctx->r13 | ctx->r9;
    // 0x80050048: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x8005004C: bne         $a1, $zero, L_80050058
    if (ctx->r5 != 0) {
        // 0x80050050: nop
    
            goto L_80050058;
    }
    // 0x80050050: nop

    // 0x80050054: break       7
    do_break(2147811412);
L_80050058:
    // 0x80050058: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8005005C: bne         $a1, $at, L_80050070
    if (ctx->r5 != ctx->r1) {
        // 0x80050060: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80050070;
    }
    // 0x80050060: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80050064: bne         $t8, $at, L_80050070
    if (ctx->r24 != ctx->r1) {
        // 0x80050068: nop
    
            goto L_80050070;
    }
    // 0x80050068: nop

    // 0x8005006C: break       6
    do_break(2147811436);
L_80050070:
    // 0x80050070: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80050074: jal         0x800515C4
    // 0x80050078: sb          $t3, 0x3C($s2)
    MEM_B(0X3C, ctx->r18) = ctx->r11;
    Cutscene_DrawGreatFox(rdram, ctx);
        goto after_3;
    // 0x80050078: sb          $t3, 0x3C($s2)
    MEM_B(0X3C, ctx->r18) = ctx->r11;
    after_3:
    // 0x8005007C: b           L_800515A8
    // 0x80050080: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_800515A8;
    // 0x80050080: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_80050084:
    // 0x80050084: jal         0x800B99C0
    // 0x80050088: nop

    RCP_SetupDL_40(rdram, ctx);
        goto after_4;
    // 0x80050088: nop

    after_4:
    // 0x8005008C: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80050090: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80050094: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80050098: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8005009C: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x800500A0: addiu       $s0, $s0, -0x4C40
    ctx->r16 = ADD32(ctx->r16, -0X4C40);
    // 0x800500A4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800500A8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800500AC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800500B0: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x800500B4: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800500B8: jal         0x80005C34
    // 0x800500BC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_5;
    // 0x800500BC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_5:
    // 0x800500C0: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800500C4: addiu       $s1, $s1, 0x7E64
    ctx->r17 = ADD32(ctx->r17, 0X7E64);
    // 0x800500C8: jal         0x80006EB8
    // 0x800500CC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_6;
    // 0x800500CC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_6:
    // 0x800500D0: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x800500D4: lui         $t8, 0x602
    ctx->r24 = S32(0X602 << 16);
    // 0x800500D8: addiu       $t8, $t8, 0x810
    ctx->r24 = ADD32(ctx->r24, 0X810);
    // 0x800500DC: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800500E0: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x800500E4: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x800500E8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800500EC: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800500F0: b           L_800515A8
    // 0x800500F4: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_800515A8;
    // 0x800500F4: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_800500F8:
    // 0x800500F8: jal         0x800BA170
    // 0x800500FC: nop

    RCP_SetupDL_64_2(rdram, ctx);
        goto after_7;
    // 0x800500FC: nop

    after_7:
    // 0x80050100: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80050104: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80050108: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8005010C: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x80050110: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x80050114: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80050118: addiu       $s1, $s1, 0x7E64
    ctx->r17 = ADD32(ctx->r17, 0X7E64);
    // 0x8005011C: addiu       $s0, $s0, -0x4C40
    ctx->r16 = ADD32(ctx->r16, -0X4C40);
    // 0x80050120: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80050124: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x80050128: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x8005012C: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80050130: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x80050134: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x80050138: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x8005013C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80050140: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80050144: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80050148: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8005014C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80050150: jal         0x80005C34
    // 0x80050154: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_8;
    // 0x80050154: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_8:
    // 0x80050158: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8005015C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80050160: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80050164: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80050168: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8005016C: jal         0x80005B00
    // 0x80050170: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    Matrix_Translate(rdram, ctx);
        goto after_9;
    // 0x80050170: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    after_9:
    // 0x80050174: lwc1        $f0, 0x110($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X110);
    // 0x80050178: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x8005017C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80050180: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80050184: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80050188: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8005018C: jal         0x80005C34
    // 0x80050190: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_10;
    // 0x80050190: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_10:
    // 0x80050194: jal         0x80006EB8
    // 0x80050198: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_11;
    // 0x80050198: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_11:
    // 0x8005019C: jal         0x800BA5B0
    // 0x800501A0: nop

    RCP_SetupDL_49(rdram, ctx);
        goto after_12;
    // 0x800501A0: nop

    after_12:
    // 0x800501A4: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x800501A8: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x800501AC: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x800501B0: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800501B4: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x800501B8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800501BC: lw          $t8, 0x50($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X50);
    // 0x800501C0: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x800501C4: or          $t5, $t9, $at
    ctx->r13 = ctx->r25 | ctx->r1;
    // 0x800501C8: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x800501CC: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x800501D0: lui         $t2, 0xFB00
    ctx->r10 = S32(0XFB00 << 16);
    // 0x800501D4: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x800501D8: addiu       $t1, $v1, 0x8
    ctx->r9 = ADD32(ctx->r3, 0X8);
    // 0x800501DC: sw          $t1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r9;
    // 0x800501E0: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x800501E4: lw          $t3, 0x50($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X50);
    // 0x800501E8: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x800501EC: andi        $t4, $t3, 0xFF
    ctx->r12 = ctx->r11 & 0XFF;
    // 0x800501F0: or          $t6, $t4, $at
    ctx->r14 = ctx->r12 | ctx->r1;
    // 0x800501F4: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x800501F8: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x800501FC: lui         $t9, 0x102
    ctx->r25 = S32(0X102 << 16);
    // 0x80050200: addiu       $t9, $t9, 0x4AC0
    ctx->r25 = ADD32(ctx->r25, 0X4AC0);
    // 0x80050204: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80050208: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x8005020C: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80050210: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80050214: b           L_800515A8
    // 0x80050218: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_800515A8;
    // 0x80050218: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_8005021C:
    // 0x8005021C: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x80050220: addiu       $s1, $s1, 0x7E64
    ctx->r17 = ADD32(ctx->r17, 0X7E64);
    // 0x80050224: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80050228: lui         $t2, 0x401
    ctx->r10 = S32(0X401 << 16);
    // 0x8005022C: addiu       $t2, $t2, -0x5520
    ctx->r10 = ADD32(ctx->r10, -0X5520);
    // 0x80050230: addiu       $t5, $v1, 0x8
    ctx->r13 = ADD32(ctx->r3, 0X8);
    // 0x80050234: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
    // 0x80050238: lui         $t1, 0x600
    ctx->r9 = S32(0X600 << 16);
    // 0x8005023C: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x80050240: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x80050244: b           L_800515A8
    // 0x80050248: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_800515A8;
    // 0x80050248: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_8005024C:
    // 0x8005024C: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x80050250: addiu       $s1, $s1, 0x7E64
    ctx->r17 = ADD32(ctx->r17, 0X7E64);
    // 0x80050254: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80050258: lui         $t6, 0xD01
    ctx->r14 = S32(0XD01 << 16);
    // 0x8005025C: addiu       $t6, $t6, -0x65C0
    ctx->r14 = ADD32(ctx->r14, -0X65C0);
    // 0x80050260: addiu       $t3, $v1, 0x8
    ctx->r11 = ADD32(ctx->r3, 0X8);
    // 0x80050264: sw          $t3, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r11;
    // 0x80050268: lui         $t4, 0x600
    ctx->r12 = S32(0X600 << 16);
    // 0x8005026C: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x80050270: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x80050274: jal         0x8005ADAC
    // 0x80050278: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Actor_DrawEngineAndContrails(rdram, ctx);
        goto after_13;
    // 0x80050278: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_13:
    // 0x8005027C: b           L_800515A8
    // 0x80050280: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_800515A8;
    // 0x80050280: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_80050284:
    // 0x80050284: lw          $t7, 0x40($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X40);
    // 0x80050288: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x8005028C: addiu       $s1, $s1, 0x7E64
    ctx->r17 = ADD32(ctx->r17, 0X7E64);
    // 0x80050290: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x80050294: beq         $t8, $zero, L_800502CC
    if (ctx->r24 == 0) {
        // 0x80050298: lui         $t3, 0x600
        ctx->r11 = S32(0X600 << 16);
            goto L_800502CC;
    }
    // 0x80050298: lui         $t3, 0x600
    ctx->r11 = S32(0X600 << 16);
    // 0x8005029C: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800502A0: addiu       $s1, $s1, 0x7E64
    ctx->r17 = ADD32(ctx->r17, 0X7E64);
    // 0x800502A4: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x800502A8: lui         $t1, 0x600
    ctx->r9 = S32(0X600 << 16);
    // 0x800502AC: addiu       $t1, $t1, 0x1DA0
    ctx->r9 = ADD32(ctx->r9, 0X1DA0);
    // 0x800502B0: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x800502B4: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x800502B8: lui         $t5, 0x600
    ctx->r13 = S32(0X600 << 16);
    // 0x800502BC: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x800502C0: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x800502C4: b           L_800515A8
    // 0x800502C8: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_800515A8;
    // 0x800502C8: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_800502CC:
    // 0x800502CC: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x800502D0: lui         $t4, 0x600
    ctx->r12 = S32(0X600 << 16);
    // 0x800502D4: addiu       $t4, $t4, 0x1360
    ctx->r12 = ADD32(ctx->r12, 0X1360);
    // 0x800502D8: addiu       $t2, $v1, 0x8
    ctx->r10 = ADD32(ctx->r3, 0X8);
    // 0x800502DC: sw          $t2, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r10;
    // 0x800502E0: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x800502E4: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x800502E8: b           L_800515A8
    // 0x800502EC: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_800515A8;
    // 0x800502EC: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_800502F0:
    // 0x800502F0: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x800502F4: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800502F8: addiu       $s1, $s1, 0x7E64
    ctx->r17 = ADD32(ctx->r17, 0X7E64);
    // 0x800502FC: addiu       $s0, $s0, -0x4C40
    ctx->r16 = ADD32(ctx->r16, -0X4C40);
    // 0x80050300: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80050304: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x80050308: addiu       $t8, $t8, 0x4FE0
    ctx->r24 = ADD32(ctx->r24, 0X4FE0);
    // 0x8005030C: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80050310: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x80050314: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80050318: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8005031C: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80050320: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80050324: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80050328: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8005032C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80050330: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80050334: jal         0x80005B00
    // 0x80050338: lui         $a3, 0xC270
    ctx->r7 = S32(0XC270 << 16);
    Matrix_Translate(rdram, ctx);
        goto after_14;
    // 0x80050338: lui         $a3, 0xC270
    ctx->r7 = S32(0XC270 << 16);
    after_14:
    // 0x8005033C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80050340: jal         0x8005B1E8
    // 0x80050344: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    Actor_DrawEngineGlow(rdram, ctx);
        goto after_15;
    // 0x80050344: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_15:
    // 0x80050348: b           L_800515A8
    // 0x8005034C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_800515A8;
    // 0x8005034C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_80050350:
    // 0x80050350: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x80050354: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x80050358: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8005035C: addiu       $s1, $s1, 0x7E64
    ctx->r17 = ADD32(ctx->r17, 0X7E64);
    // 0x80050360: addiu       $s0, $s0, -0x4C40
    ctx->r16 = ADD32(ctx->r16, -0X4C40);
    // 0x80050364: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80050368: lui         $t2, 0x401
    ctx->r10 = S32(0X401 << 16);
    // 0x8005036C: addiu       $t2, $t2, -0x5520
    ctx->r10 = ADD32(ctx->r10, -0X5520);
    // 0x80050370: addiu       $t5, $v1, 0x8
    ctx->r13 = ADD32(ctx->r3, 0X8);
    // 0x80050374: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
    // 0x80050378: lui         $t1, 0x600
    ctx->r9 = S32(0X600 << 16);
    // 0x8005037C: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x80050380: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x80050384: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80050388: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8005038C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80050390: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80050394: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80050398: jal         0x80005B00
    // 0x8005039C: lui         $a3, 0xC270
    ctx->r7 = S32(0XC270 << 16);
    Matrix_Translate(rdram, ctx);
        goto after_16;
    // 0x8005039C: lui         $a3, 0xC270
    ctx->r7 = S32(0XC270 << 16);
    after_16:
    // 0x800503A0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800503A4: jal         0x8005B1E8
    // 0x800503A8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    Actor_DrawEngineGlow(rdram, ctx);
        goto after_17;
    // 0x800503A8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_17:
    // 0x800503AC: b           L_800515A8
    // 0x800503B0: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_800515A8;
    // 0x800503B0: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_800503B4:
    // 0x800503B4: jal         0x8005F670
    // 0x800503B8: addiu       $a0, $s2, 0x4
    ctx->r4 = ADD32(ctx->r18, 0X4);
    Display_SetSecondLight(rdram, ctx);
        goto after_18;
    // 0x800503B8: addiu       $a0, $s2, 0x4
    ctx->r4 = ADD32(ctx->r18, 0X4);
    after_18:
    // 0x800503BC: lh          $t4, 0x46($s2)
    ctx->r12 = MEM_H(ctx->r18, 0X46);
    // 0x800503C0: beq         $t4, $zero, L_80050684
    if (ctx->r12 == 0) {
        // 0x800503C4: lui         $s1, 0x8013
        ctx->r17 = S32(0X8013 << 16);
            goto L_80050684;
    }
    // 0x800503C4: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800503C8: addiu       $s1, $s1, 0x7E64
    ctx->r17 = ADD32(ctx->r17, 0X7E64);
    // 0x800503CC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800503D0: jal         0x800B8DD0
    // 0x800503D4: addiu       $a1, $zero, 0x37
    ctx->r5 = ADD32(0, 0X37);
    RCP_SetupDL(rdram, ctx);
        goto after_19;
    // 0x800503D4: addiu       $a1, $zero, 0x37
    ctx->r5 = ADD32(0, 0X37);
    after_19:
    // 0x800503D8: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x800503DC: lui         $t7, 0xB600
    ctx->r15 = S32(0XB600 << 16);
    // 0x800503E0: addiu       $t8, $zero, 0x2000
    ctx->r24 = ADD32(0, 0X2000);
    // 0x800503E4: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800503E8: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x800503EC: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800503F0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800503F4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800503F8: addiu       $a1, $zero, 0x7148
    ctx->r5 = ADD32(0, 0X7148);
    // 0x800503FC: jal         0x80004FC8
    // 0x80050400: addiu       $a2, $zero, 0x2694
    ctx->r6 = ADD32(0, 0X2694);
    Rand_SetSeed(rdram, ctx);
        goto after_20;
    // 0x80050400: addiu       $a2, $zero, 0x2694
    ctx->r6 = ADD32(0, 0X2694);
    after_20:
    // 0x80050404: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80050408: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8005040C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80050410: lui         $t9, 0x102
    ctx->r25 = S32(0X102 << 16);
    // 0x80050414: addiu       $t9, $t9, 0x1E20
    ctx->r25 = ADD32(ctx->r25, 0X1E20);
    // 0x80050418: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x8005041C: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80050420: addiu       $s0, $s0, -0x4C40
    ctx->r16 = ADD32(ctx->r16, -0X4C40);
    // 0x80050424: sw          $t9, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r25;
    // 0x80050428: sw          $zero, 0x2D0($sp)
    MEM_W(0X2D0, ctx->r29) = 0;
L_8005042C:
    // 0x8005042C: jal         0x80005708
    // 0x80050430: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_Push(rdram, ctx);
        goto after_21;
    // 0x80050430: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x80050434: jal         0x80004FE8
    // 0x80050438: nop

    Rand_ZeroOneSeeded(rdram, ctx);
        goto after_22;
    // 0x80050438: nop

    after_22:
    // 0x8005043C: jal         0x80004FE8
    // 0x80050440: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOneSeeded(rdram, ctx);
        goto after_23;
    // 0x80050440: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    after_23:
    // 0x80050444: jal         0x80004FE8
    // 0x80050448: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOneSeeded(rdram, ctx);
        goto after_24;
    // 0x80050448: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    after_24:
    // 0x8005044C: lwc1        $f4, 0x50($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80050450: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80050454: lwc1        $f12, 0x5D64($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X5D64);
    // 0x80050458: sub.s       $f6, $f4, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f22.fl;
    // 0x8005045C: lwc1        $f16, 0x54($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80050460: lwc1        $f2, 0x164($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X164);
    // 0x80050464: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80050468: mul.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x8005046C: sub.s       $f18, $f16, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f22.fl;
    // 0x80050470: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80050474: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80050478: mul.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x8005047C: sub.s       $f8, $f0, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f22.fl;
    // 0x80050480: mul.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x80050484: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80050488: mul.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x8005048C: nop

    // 0x80050490: mul.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x80050494: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80050498: mul.s       $f16, $f2, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x8005049C: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x800504A0: jal         0x80005B00
    // 0x800504A4: nop

    Matrix_Translate(rdram, ctx);
        goto after_25;
    // 0x800504A4: nop

    after_25:
    // 0x800504A8: jal         0x80004FE8
    // 0x800504AC: nop

    Rand_ZeroOneSeeded(rdram, ctx);
        goto after_26;
    // 0x800504AC: nop

    after_26:
    // 0x800504B0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800504B4: lwc1        $f18, 0x5D68($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X5D68);
    // 0x800504B8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800504BC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800504C0: mul.s       $f2, $f0, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x800504C4: add.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x800504C8: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x800504CC: jal         0x80005E90
    // 0x800504D0: nop

    Matrix_RotateY(rdram, ctx);
        goto after_27;
    // 0x800504D0: nop

    after_27:
    // 0x800504D4: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x800504D8: lw          $t1, 0x7DB0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7DB0);
    // 0x800504DC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800504E0: lwc1        $f10, 0x5D6C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X5D6C);
    // 0x800504E4: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x800504E8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800504EC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800504F0: cvt.s.w     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800504F4: add.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x800504F8: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800504FC: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x80050500: jal         0x80005FE0
    // 0x80050504: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_28;
    // 0x80050504: nop

    after_28:
    // 0x80050508: jal         0x80004FE8
    // 0x8005050C: nop

    Rand_ZeroOneSeeded(rdram, ctx);
        goto after_29;
    // 0x8005050C: nop

    after_29:
    // 0x80050510: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80050514: lwc1        $f18, 0x5D70($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X5D70);
    // 0x80050518: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8005051C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80050520: mul.s       $f2, $f0, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80050524: add.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x80050528: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8005052C: jal         0x80005D44
    // 0x80050530: nop

    Matrix_RotateX(rdram, ctx);
        goto after_30;
    // 0x80050530: nop

    after_30:
    // 0x80050534: lw          $v0, 0x2D0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2D0);
    // 0x80050538: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x8005053C: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80050540: andi        $t2, $v0, 0x3
    ctx->r10 = ctx->r2 & 0X3;
    // 0x80050544: beq         $t2, $zero, L_80050578
    if (ctx->r10 == 0) {
        // 0x80050548: addiu       $t3, $zero, 0x1
        ctx->r11 = ADD32(0, 0X1);
            goto L_80050578;
    }
    // 0x80050548: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8005054C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80050550: beq         $t2, $at, L_80050594
    if (ctx->r10 == ctx->r1) {
        // 0x80050554: lui         $a1, 0x3E99
        ctx->r5 = S32(0X3E99 << 16);
            goto L_80050594;
    }
    // 0x80050554: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x80050558: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8005055C: beq         $t2, $at, L_800505B8
    if (ctx->r10 == ctx->r1) {
        // 0x80050560: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_800505B8;
    }
    // 0x80050560: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80050564: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80050568: beq         $t2, $at, L_800505D8
    if (ctx->r10 == ctx->r1) {
        // 0x8005056C: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_800505D8;
    }
    // 0x8005056C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80050570: b           L_800505F0
    // 0x80050574: nop

        goto L_800505F0;
    // 0x80050574: nop

L_80050578:
    // 0x80050578: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8005057C: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80050580: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80050584: jal         0x80005C34
    // 0x80050588: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    Matrix_Scale(rdram, ctx);
        goto after_31;
    // 0x80050588: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_31:
    // 0x8005058C: b           L_800505F0
    // 0x80050590: nop

        goto L_800505F0;
    // 0x80050590: nop

L_80050594:
    // 0x80050594: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80050598: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x8005059C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800505A0: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800505A4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800505A8: jal         0x80005C34
    // 0x800505AC: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    Matrix_Scale(rdram, ctx);
        goto after_32;
    // 0x800505AC: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    after_32:
    // 0x800505B0: b           L_800505F0
    // 0x800505B4: nop

        goto L_800505F0;
    // 0x800505B4: nop

L_800505B8:
    // 0x800505B8: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x800505BC: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x800505C0: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x800505C4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800505C8: jal         0x80005C34
    // 0x800505CC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    Matrix_Scale(rdram, ctx);
        goto after_33;
    // 0x800505CC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_33:
    // 0x800505D0: b           L_800505F0
    // 0x800505D4: nop

        goto L_800505F0;
    // 0x800505D4: nop

L_800505D8:
    // 0x800505D8: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    // 0x800505DC: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800505E0: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x800505E4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800505E8: jal         0x80005C34
    // 0x800505EC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    Matrix_Scale(rdram, ctx);
        goto after_34;
    // 0x800505EC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_34:
L_800505F0:
    // 0x800505F0: jal         0x80004FE8
    // 0x800505F4: nop

    Rand_ZeroOneSeeded(rdram, ctx);
        goto after_35;
    // 0x800505F4: nop

    after_35:
    // 0x800505F8: jal         0x80004FE8
    // 0x800505FC: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOneSeeded(rdram, ctx);
        goto after_36;
    // 0x800505FC: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    after_36:
    // 0x80050600: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80050604: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80050608: lwc1        $f6, 0x54($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8005060C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80050610: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80050614: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80050618: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8005061C: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x80050620: mul.s       $f16, $f0, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80050624: add.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x80050628: add.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x8005062C: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80050630: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80050634: jal         0x80005C34
    // 0x80050638: nop

    Matrix_Scale(rdram, ctx);
        goto after_37;
    // 0x80050638: nop

    after_37:
    // 0x8005063C: jal         0x80006EB8
    // 0x80050640: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_38;
    // 0x80050640: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_38:
    // 0x80050644: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80050648: lui         $t5, 0x600
    ctx->r13 = S32(0X600 << 16);
    // 0x8005064C: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80050650: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x80050654: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x80050658: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x8005065C: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x80050660: jal         0x80005740
    // 0x80050664: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_39;
    // 0x80050664: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_39:
    // 0x80050668: lw          $t2, 0x2D0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2D0);
    // 0x8005066C: addiu       $at, $zero, 0x1E
    ctx->r1 = ADD32(0, 0X1E);
    // 0x80050670: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x80050674: bne         $t3, $at, L_8005042C
    if (ctx->r11 != ctx->r1) {
        // 0x80050678: sw          $t3, 0x2D0($sp)
        MEM_W(0X2D0, ctx->r29) = ctx->r11;
            goto L_8005042C;
    }
    // 0x80050678: sw          $t3, 0x2D0($sp)
    MEM_W(0X2D0, ctx->r29) = ctx->r11;
    // 0x8005067C: b           L_800515A8
    // 0x80050680: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_800515A8;
    // 0x80050680: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_80050684:
    // 0x80050684: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80050688: lw          $t4, -0x7D80($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7D80);
    // 0x8005068C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80050690: lw          $t6, 0x1C8($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X1C8);
    // 0x80050694: bne         $t6, $at, L_80050728
    if (ctx->r14 != ctx->r1) {
        // 0x80050698: lui         $s0, 0x8014
        ctx->r16 = S32(0X8014 << 16);
            goto L_80050728;
    }
    // 0x80050698: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x8005069C: addiu       $s0, $s0, -0x4C40
    ctx->r16 = ADD32(ctx->r16, -0X4C40);
    // 0x800506A0: jal         0x80005708
    // 0x800506A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_Push(rdram, ctx);
        goto after_40;
    // 0x800506A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_40:
    // 0x800506A8: lui         $a1, 0x3EB2
    ctx->r5 = S32(0X3EB2 << 16);
    // 0x800506AC: ori         $a1, $a1, 0xB8C2
    ctx->r5 = ctx->r5 | 0XB8C2;
    // 0x800506B0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800506B4: jal         0x80005D44
    // 0x800506B8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateX(rdram, ctx);
        goto after_41;
    // 0x800506B8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_41:
    // 0x800506BC: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x800506C0: lw          $t7, 0x7DB0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7DB0);
    // 0x800506C4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800506C8: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x800506CC: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x800506D0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800506D4: lwc1        $f10, 0x5D74($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X5D74);
    // 0x800506D8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800506DC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800506E0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800506E4: mul.s       $f8, $f6, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f22.fl);
    // 0x800506E8: nop

    // 0x800506EC: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800506F0: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x800506F4: jal         0x80005E90
    // 0x800506F8: nop

    Matrix_RotateY(rdram, ctx);
        goto after_42;
    // 0x800506F8: nop

    after_42:
    // 0x800506FC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80050700: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80050704: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80050708: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8005070C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80050710: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80050714: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80050718: jal         0x80005C34
    // 0x8005071C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_43;
    // 0x8005071C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_43:
    // 0x80050720: b           L_800507B4
    // 0x80050724: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
        goto L_800507B4;
    // 0x80050724: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_80050728:
    // 0x80050728: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x8005072C: addiu       $s0, $s0, -0x4C40
    ctx->r16 = ADD32(ctx->r16, -0X4C40);
    // 0x80050730: lui         $a1, 0xBE32
    ctx->r5 = S32(0XBE32 << 16);
    // 0x80050734: ori         $a1, $a1, 0xB8C2
    ctx->r5 = ctx->r5 | 0XB8C2;
    // 0x80050738: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8005073C: jal         0x80005D44
    // 0x80050740: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateX(rdram, ctx);
        goto after_44;
    // 0x80050740: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_44:
    // 0x80050744: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x80050748: lw          $t9, 0x7DB0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7DB0);
    // 0x8005074C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80050750: lwc1        $f6, 0x5D78($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5D78);
    // 0x80050754: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x80050758: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005075C: lwc1        $f10, 0x5D7C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X5D7C);
    // 0x80050760: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80050764: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80050768: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8005076C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80050770: nop

    // 0x80050774: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80050778: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8005077C: jal         0x80005E90
    // 0x80050780: nop

    Matrix_RotateY(rdram, ctx);
        goto after_45;
    // 0x80050780: nop

    after_45:
    // 0x80050784: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80050788: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8005078C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80050790: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80050794: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80050798: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8005079C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800507A0: jal         0x80005C34
    // 0x800507A4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_46;
    // 0x800507A4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_46:
    // 0x800507A8: jal         0x80005708
    // 0x800507AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_Push(rdram, ctx);
        goto after_47;
    // 0x800507AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_47:
    // 0x800507B0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_800507B4:
    // 0x800507B4: lui         $a2, 0xC413
    ctx->r6 = S32(0XC413 << 16);
    // 0x800507B8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800507BC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800507C0: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800507C4: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x800507C8: ori         $a2, $a2, 0x8000
    ctx->r6 = ctx->r6 | 0X8000;
    // 0x800507CC: jal         0x80005B00
    // 0x800507D0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_48;
    // 0x800507D0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_48:
    // 0x800507D4: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800507D8: addiu       $s1, $s1, 0x7E64
    ctx->r17 = ADD32(ctx->r17, 0X7E64);
    // 0x800507DC: jal         0x80006EB8
    // 0x800507E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_49;
    // 0x800507E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_49:
    // 0x800507E4: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x800507E8: lui         $t4, 0x601
    ctx->r12 = S32(0X601 << 16);
    // 0x800507EC: addiu       $t4, $t4, -0x4560
    ctx->r12 = ADD32(ctx->r12, -0X4560);
    // 0x800507F0: addiu       $t2, $v1, 0x8
    ctx->r10 = ADD32(ctx->r3, 0X8);
    // 0x800507F4: sw          $t2, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r10;
    // 0x800507F8: lui         $t3, 0x600
    ctx->r11 = S32(0X600 << 16);
    // 0x800507FC: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x80050800: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x80050804: jal         0x80005708
    // 0x80050808: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_Push(rdram, ctx);
        goto after_50;
    // 0x80050808: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_50:
    // 0x8005080C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80050810: jal         0x800B8DD0
    // 0x80050814: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    RCP_SetupDL(rdram, ctx);
        goto after_51;
    // 0x80050814: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_51:
    // 0x80050818: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8005081C: lw          $v0, 0x7DB0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7DB0);
    // 0x80050820: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x80050824: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80050828: sra         $t6, $v0, 3
    ctx->r14 = S32(SIGNED(ctx->r2) >> 3);
    // 0x8005082C: andi        $t7, $t6, 0x3
    ctx->r15 = ctx->r14 & 0X3;
    // 0x80050830: beq         $t7, $zero, L_8005085C
    if (ctx->r15 == 0) {
        // 0x80050834: addiu       $a0, $a0, -0x5DF0
        ctx->r4 = ADD32(ctx->r4, -0X5DF0);
            goto L_8005085C;
    }
    // 0x80050834: addiu       $a0, $a0, -0x5DF0
    ctx->r4 = ADD32(ctx->r4, -0X5DF0);
    // 0x80050838: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005083C: beq         $t7, $at, L_8005087C
    if (ctx->r15 == ctx->r1) {
        // 0x80050840: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8005087C;
    }
    // 0x80050840: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80050844: beq         $t7, $at, L_80050898
    if (ctx->r15 == ctx->r1) {
        // 0x80050848: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80050898;
    }
    // 0x80050848: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8005084C: beql        $t7, $at, L_800508B8
    if (ctx->r15 == ctx->r1) {
        // 0x80050850: lui         $at, 0x437F
        ctx->r1 = S32(0X437F << 16);
            goto L_800508B8;
    }
    goto skip_1;
    // 0x80050850: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    skip_1:
    // 0x80050854: b           L_800508D0
    // 0x80050858: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
        goto L_800508D0;
    // 0x80050858: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_8005085C:
    // 0x8005085C: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80050860: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80050864: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80050868: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8005086C: swc1        $f0, 0x2DC($sp)
    MEM_W(0X2DC, ctx->r29) = ctx->f0.u32l;
    // 0x80050870: swc1        $f18, 0x2D8($sp)
    MEM_W(0X2D8, ctx->r29) = ctx->f18.u32l;
    // 0x80050874: b           L_800508CC
    // 0x80050878: swc1        $f4, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->f4.u32l;
        goto L_800508CC;
    // 0x80050878: swc1        $f4, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->f4.u32l;
L_8005087C:
    // 0x8005087C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80050880: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80050884: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80050888: swc1        $f2, 0x2DC($sp)
    MEM_W(0X2DC, ctx->r29) = ctx->f2.u32l;
    // 0x8005088C: swc1        $f2, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->f2.u32l;
    // 0x80050890: b           L_800508CC
    // 0x80050894: swc1        $f0, 0x2D8($sp)
    MEM_W(0X2D8, ctx->r29) = ctx->f0.u32l;
        goto L_800508CC;
    // 0x80050894: swc1        $f0, 0x2D8($sp)
    MEM_W(0X2D8, ctx->r29) = ctx->f0.u32l;
L_80050898:
    // 0x80050898: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8005089C: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800508A0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800508A4: swc1        $f2, 0x2DC($sp)
    MEM_W(0X2DC, ctx->r29) = ctx->f2.u32l;
    // 0x800508A8: swc1        $f2, 0x2D8($sp)
    MEM_W(0X2D8, ctx->r29) = ctx->f2.u32l;
    // 0x800508AC: b           L_800508CC
    // 0x800508B0: swc1        $f0, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->f0.u32l;
        goto L_800508CC;
    // 0x800508B0: swc1        $f0, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->f0.u32l;
    // 0x800508B4: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
L_800508B8:
    // 0x800508B8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800508BC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800508C0: swc1        $f0, 0x2DC($sp)
    MEM_W(0X2DC, ctx->r29) = ctx->f0.u32l;
    // 0x800508C4: swc1        $f0, 0x2D8($sp)
    MEM_W(0X2D8, ctx->r29) = ctx->f0.u32l;
    // 0x800508C8: swc1        $f6, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->f6.u32l;
L_800508CC:
    // 0x800508CC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_800508D0:
    // 0x800508D0: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x800508D4: lw          $a1, 0x2DC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2DC);
    // 0x800508D8: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    // 0x800508DC: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800508E0: jal         0x8009BC2C
    // 0x800508E4: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_52;
    // 0x800508E4: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    after_52:
    // 0x800508E8: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800508EC: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800508F0: addiu       $a0, $a0, -0x5DEC
    ctx->r4 = ADD32(ctx->r4, -0X5DEC);
    // 0x800508F4: lw          $a1, 0x2D8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2D8);
    // 0x800508F8: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    // 0x800508FC: jal         0x8009BC2C
    // 0x80050900: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_53;
    // 0x80050900: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    after_53:
    // 0x80050904: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80050908: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8005090C: addiu       $a0, $a0, -0x5DE8
    ctx->r4 = ADD32(ctx->r4, -0X5DE8);
    // 0x80050910: lw          $a1, 0x2D4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2D4);
    // 0x80050914: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    // 0x80050918: jal         0x8009BC2C
    // 0x8005091C: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_54;
    // 0x8005091C: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    after_54:
    // 0x80050920: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80050924: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x80050928: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005092C: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80050930: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x80050934: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80050938: lwc1        $f8, -0x5DF0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X5DF0);
    // 0x8005093C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80050940: lwc1        $f16, -0x5DEC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X5DEC);
    // 0x80050944: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80050948: lwc1        $f4, -0x5DE8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X5DE8);
    // 0x8005094C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80050950: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80050954: mfc1        $t2, $f10
    ctx->r10 = (int32_t)ctx->f10.u32l;
    // 0x80050958: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8005095C: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x80050960: sll         $t3, $t2, 24
    ctx->r11 = S32(ctx->r10 << 24);
    // 0x80050964: mfc1        $t1, $f6
    ctx->r9 = (int32_t)ctx->f6.u32l;
    // 0x80050968: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x8005096C: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x80050970: andi        $t2, $t1, 0xFF
    ctx->r10 = ctx->r9 & 0XFF;
    // 0x80050974: sll         $t4, $t2, 8
    ctx->r12 = S32(ctx->r10 << 8);
    // 0x80050978: or          $t9, $t3, $t8
    ctx->r25 = ctx->r11 | ctx->r24;
    // 0x8005097C: or          $t6, $t9, $t4
    ctx->r14 = ctx->r25 | ctx->r12;
    // 0x80050980: ori         $t7, $t6, 0x80
    ctx->r15 = ctx->r14 | 0X80;
    // 0x80050984: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80050988: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8005098C: lw          $t3, -0x7D80($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X7D80);
    // 0x80050990: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80050994: lw          $t8, 0x1C8($t3)
    ctx->r24 = MEM_W(ctx->r11, 0X1C8);
    // 0x80050998: bne         $t8, $at, L_800509C8
    if (ctx->r24 != ctx->r1) {
        // 0x8005099C: lui         $at, 0x800D
        ctx->r1 = S32(0X800D << 16);
            goto L_800509C8;
    }
    // 0x8005099C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800509A0: lwc1        $f0, 0x5D80($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5D80);
    // 0x800509A4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800509A8: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x800509AC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800509B0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800509B4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800509B8: jal         0x80005C34
    // 0x800509BC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_55;
    // 0x800509BC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_55:
    // 0x800509C0: b           L_800509EC
    // 0x800509C4: nop

        goto L_800509EC;
    // 0x800509C4: nop

L_800509C8:
    // 0x800509C8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800509CC: lwc1        $f0, 0x5D84($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5D84);
    // 0x800509D0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800509D4: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x800509D8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800509DC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800509E0: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800509E4: jal         0x80005C34
    // 0x800509E8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_56;
    // 0x800509E8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_56:
L_800509EC:
    // 0x800509EC: jal         0x80006EB8
    // 0x800509F0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_57;
    // 0x800509F0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_57:
    // 0x800509F4: lui         $a3, 0xBA00
    ctx->r7 = S32(0XBA00 << 16);
    // 0x800509F8: ori         $a3, $a3, 0xC02
    ctx->r7 = ctx->r7 | 0XC02;
    // 0x800509FC: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80050A00: lui         $t4, 0x600
    ctx->r12 = S32(0X600 << 16);
    // 0x80050A04: addiu       $t2, $v1, 0x8
    ctx->r10 = ADD32(ctx->r3, 0X8);
    // 0x80050A08: sw          $t2, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r10;
    // 0x80050A0C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80050A10: sw          $a3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r7;
    // 0x80050A14: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80050A18: lui         $t6, 0x600
    ctx->r14 = S32(0X600 << 16);
    // 0x80050A1C: addiu       $t6, $t6, 0xD80
    ctx->r14 = ADD32(ctx->r14, 0XD80);
    // 0x80050A20: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80050A24: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x80050A28: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x80050A2C: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x80050A30: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80050A34: addiu       $t3, $zero, 0x2000
    ctx->r11 = ADD32(0, 0X2000);
    // 0x80050A38: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80050A3C: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x80050A40: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x80050A44: sw          $a3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r7;
    // 0x80050A48: jal         0x80005740
    // 0x80050A4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_58;
    // 0x80050A4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_58:
    // 0x80050A50: jal         0x80005740
    // 0x80050A54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_59;
    // 0x80050A54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_59:
    // 0x80050A58: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80050A5C: lw          $t8, -0x7D80($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7D80);
    // 0x80050A60: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80050A64: lw          $t5, 0x1C8($t8)
    ctx->r13 = MEM_W(ctx->r24, 0X1C8);
    // 0x80050A68: bne         $t5, $at, L_800515A4
    if (ctx->r13 != ctx->r1) {
        // 0x80050A6C: lui         $at, 0x800D
        ctx->r1 = S32(0X800D << 16);
            goto L_800515A4;
    }
    // 0x80050A6C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80050A70: lwc1        $f0, 0x5D88($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5D88);
    // 0x80050A74: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80050A78: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80050A7C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80050A80: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80050A84: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80050A88: jal         0x80005C34
    // 0x80050A8C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_60;
    // 0x80050A8C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_60:
    // 0x80050A90: b           L_800515A8
    // 0x80050A94: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_800515A8;
    // 0x80050A94: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_80050A98:
    // 0x80050A98: jal         0x800B9760
    // 0x80050A9C: nop

    RCP_SetupDL_21(rdram, ctx);
        goto after_61;
    // 0x80050A9C: nop

    after_61:
    // 0x80050AA0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80050AA4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80050AA8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80050AAC: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80050AB0: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x80050AB4: addiu       $s0, $s0, -0x4C40
    ctx->r16 = ADD32(ctx->r16, -0X4C40);
    // 0x80050AB8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80050ABC: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80050AC0: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80050AC4: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80050AC8: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80050ACC: jal         0x80005C34
    // 0x80050AD0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_62;
    // 0x80050AD0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_62:
    // 0x80050AD4: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x80050AD8: addiu       $s1, $s1, 0x7E64
    ctx->r17 = ADD32(ctx->r17, 0X7E64);
    // 0x80050ADC: jal         0x80006EB8
    // 0x80050AE0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_63;
    // 0x80050AE0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_63:
    // 0x80050AE4: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80050AE8: lui         $t6, 0x102
    ctx->r14 = S32(0X102 << 16);
    // 0x80050AEC: addiu       $t6, $t6, -0x5430
    ctx->r14 = ADD32(ctx->r14, -0X5430);
    // 0x80050AF0: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80050AF4: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x80050AF8: lui         $t4, 0x600
    ctx->r12 = S32(0X600 << 16);
    // 0x80050AFC: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x80050B00: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x80050B04: b           L_800515A8
    // 0x80050B08: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_800515A8;
    // 0x80050B08: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_80050B0C:
    // 0x80050B0C: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x80050B10: addiu       $s1, $s1, 0x7E64
    ctx->r17 = ADD32(ctx->r17, 0X7E64);
    // 0x80050B14: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80050B18: lui         $t8, 0x601
    ctx->r24 = S32(0X601 << 16);
    // 0x80050B1C: addiu       $t8, $t8, -0x7890
    ctx->r24 = ADD32(ctx->r24, -0X7890);
    // 0x80050B20: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80050B24: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x80050B28: lui         $t3, 0x600
    ctx->r11 = S32(0X600 << 16);
    // 0x80050B2C: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x80050B30: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80050B34: b           L_800515A8
    // 0x80050B38: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_800515A8;
    // 0x80050B38: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_80050B3C:
    // 0x80050B3C: lw          $t5, 0x40($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X40);
    // 0x80050B40: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80050B44: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x80050B48: bne         $t5, $at, L_80050B98
    if (ctx->r13 != ctx->r1) {
        // 0x80050B4C: addiu       $s0, $s0, -0x4C40
        ctx->r16 = ADD32(ctx->r16, -0X4C40);
            goto L_80050B98;
    }
    // 0x80050B4C: addiu       $s0, $s0, -0x4C40
    ctx->r16 = ADD32(ctx->r16, -0X4C40);
    // 0x80050B50: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80050B54: lw          $t1, -0x7D80($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X7D80);
    // 0x80050B58: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80050B5C: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x80050B60: lw          $t2, 0x1C8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X1C8);
    // 0x80050B64: addiu       $s1, $s1, 0x7E64
    ctx->r17 = ADD32(ctx->r17, 0X7E64);
    // 0x80050B68: lui         $t4, 0x600
    ctx->r12 = S32(0X600 << 16);
    // 0x80050B6C: bne         $t2, $at, L_80050B98
    if (ctx->r10 != ctx->r1) {
        // 0x80050B70: nop
    
            goto L_80050B98;
    }
    // 0x80050B70: nop

    // 0x80050B74: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80050B78: lui         $t6, 0xD01
    ctx->r14 = S32(0XD01 << 16);
    // 0x80050B7C: addiu       $t6, $t6, -0x4780
    ctx->r14 = ADD32(ctx->r14, -0X4780);
    // 0x80050B80: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80050B84: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x80050B88: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x80050B8C: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x80050B90: b           L_80050BC4
    // 0x80050B94: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
        goto L_80050BC4;
    // 0x80050B94: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_80050B98:
    // 0x80050B98: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x80050B9C: addiu       $s1, $s1, 0x7E64
    ctx->r17 = ADD32(ctx->r17, 0X7E64);
    // 0x80050BA0: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80050BA4: lui         $t8, 0x601
    ctx->r24 = S32(0X601 << 16);
    // 0x80050BA8: addiu       $t8, $t8, -0x1FB0
    ctx->r24 = ADD32(ctx->r24, -0X1FB0);
    // 0x80050BAC: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80050BB0: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x80050BB4: lui         $t3, 0x600
    ctx->r11 = S32(0X600 << 16);
    // 0x80050BB8: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x80050BBC: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80050BC0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_80050BC4:
    // 0x80050BC4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80050BC8: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80050BCC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80050BD0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80050BD4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80050BD8: jal         0x80005B00
    // 0x80050BDC: lui         $a3, 0xC270
    ctx->r7 = S32(0XC270 << 16);
    Matrix_Translate(rdram, ctx);
        goto after_64;
    // 0x80050BDC: lui         $a3, 0xC270
    ctx->r7 = S32(0XC270 << 16);
    after_64:
    // 0x80050BE0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80050BE4: jal         0x8005B1E8
    // 0x80050BE8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    Actor_DrawEngineGlow(rdram, ctx);
        goto after_65;
    // 0x80050BE8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_65:
    // 0x80050BEC: b           L_800515A8
    // 0x80050BF0: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_800515A8;
    // 0x80050BF0: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_80050BF4:
    // 0x80050BF4: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x80050BF8: addiu       $s1, $s1, 0x7E64
    ctx->r17 = ADD32(ctx->r17, 0X7E64);
    // 0x80050BFC: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80050C00: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x80050C04: addiu       $t9, $t9, 0x1530
    ctx->r25 = ADD32(ctx->r25, 0X1530);
    // 0x80050C08: addiu       $t1, $v1, 0x8
    ctx->r9 = ADD32(ctx->r3, 0X8);
    // 0x80050C0C: sw          $t1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r9;
    // 0x80050C10: lui         $t2, 0x600
    ctx->r10 = S32(0X600 << 16);
    // 0x80050C14: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x80050C18: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80050C1C: b           L_800515A8
    // 0x80050C20: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_800515A8;
    // 0x80050C20: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_80050C24:
    // 0x80050C24: lui         $at, 0x3E00
    ctx->r1 = S32(0X3E00 << 16);
    // 0x80050C28: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80050C2C: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x80050C30: addiu       $s0, $s0, -0x4C40
    ctx->r16 = ADD32(ctx->r16, -0X4C40);
    // 0x80050C34: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80050C38: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80050C3C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80050C40: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80050C44: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80050C48: jal         0x80005C34
    // 0x80050C4C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_66;
    // 0x80050C4C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_66:
    // 0x80050C50: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x80050C54: jal         0x80006EB8
    // 0x80050C58: addiu       $a0, $s1, 0x7E64
    ctx->r4 = ADD32(ctx->r17, 0X7E64);
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_67;
    // 0x80050C58: addiu       $a0, $s1, 0x7E64
    ctx->r4 = ADD32(ctx->r17, 0X7E64);
    after_67:
L_80050C5C:
    // 0x80050C5C: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x80050C60: addiu       $s1, $s1, 0x7E64
    ctx->r17 = ADD32(ctx->r17, 0X7E64);
    // 0x80050C64: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80050C68: lui         $t3, 0x601
    ctx->r11 = S32(0X601 << 16);
    // 0x80050C6C: addiu       $t3, $t3, -0x6820
    ctx->r11 = ADD32(ctx->r11, -0X6820);
    // 0x80050C70: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80050C74: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x80050C78: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80050C7C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80050C80: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x80050C84: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80050C88: jal         0x8004FCB8
    // 0x80050C8C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    ActorCutscene_SyShip_Setup(rdram, ctx);
        goto after_68;
    // 0x80050C8C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_68:
    // 0x80050C90: b           L_800515A8
    // 0x80050C94: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_800515A8;
    // 0x80050C94: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_80050C98:
    // 0x80050C98: lwc1        $f0, 0x110($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X110);
    // 0x80050C9C: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x80050CA0: addiu       $s0, $s0, -0x4C40
    ctx->r16 = ADD32(ctx->r16, -0X4C40);
    // 0x80050CA4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80050CA8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80050CAC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80050CB0: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80050CB4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80050CB8: jal         0x80005C34
    // 0x80050CBC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_69;
    // 0x80050CBC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_69:
    // 0x80050CC0: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x80050CC4: addiu       $s1, $s1, 0x7E64
    ctx->r17 = ADD32(ctx->r17, 0X7E64);
    // 0x80050CC8: jal         0x80006EB8
    // 0x80050CCC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_70;
    // 0x80050CCC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_70:
    // 0x80050CD0: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80050CD4: lui         $t2, 0x602
    ctx->r10 = S32(0X602 << 16);
    // 0x80050CD8: addiu       $t2, $t2, -0x28D0
    ctx->r10 = ADD32(ctx->r10, -0X28D0);
    // 0x80050CDC: addiu       $t5, $v1, 0x8
    ctx->r13 = ADD32(ctx->r3, 0X8);
    // 0x80050CE0: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
    // 0x80050CE4: lui         $t1, 0x600
    ctx->r9 = S32(0X600 << 16);
    // 0x80050CE8: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x80050CEC: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x80050CF0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80050CF4: jal         0x8004FCB8
    // 0x80050CF8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    ActorCutscene_SyShip_Setup(rdram, ctx);
        goto after_71;
    // 0x80050CF8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_71:
    // 0x80050CFC: b           L_800515A8
    // 0x80050D00: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_800515A8;
    // 0x80050D00: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_80050D04:
    // 0x80050D04: jal         0x800BA5B0
    // 0x80050D08: nop

    RCP_SetupDL_49(rdram, ctx);
        goto after_72;
    // 0x80050D08: nop

    after_72:
    // 0x80050D0C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80050D10: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x80050D14: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x80050D18: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80050D1C: addiu       $s1, $s1, 0x7E64
    ctx->r17 = ADD32(ctx->r17, 0X7E64);
    // 0x80050D20: addiu       $s0, $s0, -0x4C40
    ctx->r16 = ADD32(ctx->r16, -0X4C40);
    // 0x80050D24: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80050D28: lui         $t4, 0xFA00
    ctx->r12 = S32(0XFA00 << 16);
    // 0x80050D2C: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80050D30: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80050D34: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x80050D38: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x80050D3C: lw          $t8, 0x50($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X50);
    // 0x80050D40: lw          $t6, 0x5C($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X5C);
    // 0x80050D44: lw          $t2, 0x54($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X54);
    // 0x80050D48: lw          $t3, 0x58($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X58);
    // 0x80050D4C: sll         $t5, $t8, 24
    ctx->r13 = S32(ctx->r24 << 24);
    // 0x80050D50: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x80050D54: or          $t1, $t7, $t5
    ctx->r9 = ctx->r15 | ctx->r13;
    // 0x80050D58: andi        $t9, $t2, 0xFF
    ctx->r25 = ctx->r10 & 0XFF;
    // 0x80050D5C: sll         $t4, $t9, 16
    ctx->r12 = S32(ctx->r25 << 16);
    // 0x80050D60: andi        $t8, $t3, 0xFF
    ctx->r24 = ctx->r11 & 0XFF;
    // 0x80050D64: sll         $t7, $t8, 8
    ctx->r15 = S32(ctx->r24 << 8);
    // 0x80050D68: or          $t6, $t1, $t4
    ctx->r14 = ctx->r9 | ctx->r12;
    // 0x80050D6C: or          $t5, $t6, $t7
    ctx->r13 = ctx->r14 | ctx->r15;
    // 0x80050D70: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x80050D74: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80050D78: lui         $t9, 0xFB00
    ctx->r25 = S32(0XFB00 << 16);
    // 0x80050D7C: addiu       $t2, $v1, 0x8
    ctx->r10 = ADD32(ctx->r3, 0X8);
    // 0x80050D80: sw          $t2, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r10;
    // 0x80050D84: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80050D88: lw          $t8, 0x60($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X60);
    // 0x80050D8C: lw          $t1, 0x6C($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X6C);
    // 0x80050D90: lw          $t5, 0x64($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X64);
    // 0x80050D94: lw          $t3, 0x68($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X68);
    // 0x80050D98: sll         $t6, $t8, 24
    ctx->r14 = S32(ctx->r24 << 24);
    // 0x80050D9C: andi        $t4, $t1, 0xFF
    ctx->r12 = ctx->r9 & 0XFF;
    // 0x80050DA0: or          $t7, $t4, $t6
    ctx->r15 = ctx->r12 | ctx->r14;
    // 0x80050DA4: andi        $t2, $t5, 0xFF
    ctx->r10 = ctx->r13 & 0XFF;
    // 0x80050DA8: sll         $t9, $t2, 16
    ctx->r25 = S32(ctx->r10 << 16);
    // 0x80050DAC: andi        $t8, $t3, 0xFF
    ctx->r24 = ctx->r11 & 0XFF;
    // 0x80050DB0: sll         $t4, $t8, 8
    ctx->r12 = S32(ctx->r24 << 8);
    // 0x80050DB4: or          $t1, $t7, $t9
    ctx->r9 = ctx->r15 | ctx->r25;
    // 0x80050DB8: or          $t6, $t1, $t4
    ctx->r14 = ctx->r9 | ctx->r12;
    // 0x80050DBC: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x80050DC0: lw          $a1, 0x110($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X110);
    // 0x80050DC4: lw          $a2, 0x124($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X124);
    // 0x80050DC8: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80050DCC: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80050DD0: jal         0x80005C34
    // 0x80050DD4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_73;
    // 0x80050DD4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_73:
    // 0x80050DD8: jal         0x80006EB8
    // 0x80050DDC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_74;
    // 0x80050DDC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_74:
    // 0x80050DE0: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80050DE4: lui         $t9, 0x102
    ctx->r25 = S32(0X102 << 16);
    // 0x80050DE8: addiu       $t9, $t9, 0x4AC0
    ctx->r25 = ADD32(ctx->r25, 0X4AC0);
    // 0x80050DEC: addiu       $t2, $v1, 0x8
    ctx->r10 = ADD32(ctx->r3, 0X8);
    // 0x80050DF0: sw          $t2, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r10;
    // 0x80050DF4: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80050DF8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80050DFC: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80050E00: b           L_800515A8
    // 0x80050E04: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_800515A8;
    // 0x80050E04: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_80050E08:
    // 0x80050E08: lw          $t3, 0x60($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X60);
    // 0x80050E0C: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80050E10: addiu       $s1, $sp, 0x144
    ctx->r17 = ADD32(ctx->r29, 0X144);
    // 0x80050E14: sll         $t8, $t3, 2
    ctx->r24 = S32(ctx->r11 << 2);
    // 0x80050E18: addu        $a0, $a0, $t8
    ctx->r4 = ADD32(ctx->r4, ctx->r24);
    // 0x80050E1C: lw          $a0, -0x5E0C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5E0C);
    // 0x80050E20: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80050E24: jal         0x8009AA20
    // 0x80050E28: lw          $a1, 0x64($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X64);
    Animation_GetFrameData(rdram, ctx);
        goto after_75;
    // 0x80050E28: lw          $a1, 0x64($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X64);
    after_75:
    // 0x80050E2C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80050E30: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80050E34: lwc1        $f8, 0x11C($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X11C);
    // 0x80050E38: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80050E3C: addiu       $s0, $s2, 0x18C
    ctx->r16 = ADD32(ctx->r18, 0X18C);
    // 0x80050E40: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80050E44: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80050E48: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80050E4C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80050E50: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x80050E54: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    // 0x80050E58: jal         0x8009BEEC
    // 0x80050E5C: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    Math_SmoothStepToVec3fArray(rdram, ctx);
        goto after_76;
    // 0x80050E5C: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    after_76:
    // 0x80050E60: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80050E64: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80050E68: lw          $t4, -0x7C24($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7C24);
    // 0x80050E6C: lw          $t1, -0x7C28($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X7C28);
    // 0x80050E70: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80050E74: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x80050E78: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x80050E7C: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x80050E80: lw          $a3, -0x7CC8($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X7CC8);
    // 0x80050E84: lw          $a2, -0x7CD0($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7CD0);
    // 0x80050E88: lw          $a1, -0x7CD8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7CD8);
    // 0x80050E8C: lw          $a0, -0x7CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7CE0);
    // 0x80050E90: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80050E94: jal         0x800BA2E8
    // 0x80050E98: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    RCP_SetupDL_30(rdram, ctx);
        goto after_77;
    // 0x80050E98: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_77:
    // 0x80050E9C: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x80050EA0: addiu       $s1, $s1, 0x7E64
    ctx->r17 = ADD32(ctx->r17, 0X7E64);
    // 0x80050EA4: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80050EA8: lui         $t2, 0x96FF
    ctx->r10 = S32(0X96FF << 16);
    // 0x80050EAC: ori         $t2, $t2, 0x96FF
    ctx->r10 = ctx->r10 | 0X96FF;
    // 0x80050EB0: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80050EB4: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x80050EB8: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x80050EBC: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x80050EC0: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x80050EC4: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x80050EC8: addiu       $t7, $t7, 0x4660
    ctx->r15 = ADD32(ctx->r15, 0X4660);
    // 0x80050ECC: lui         $a1, 0x603
    ctx->r5 = S32(0X603 << 16);
    // 0x80050ED0: addiu       $a1, $a1, -0x2EC0
    ctx->r5 = ADD32(ctx->r5, -0X2EC0);
    // 0x80050ED4: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x80050ED8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80050EDC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80050EE0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80050EE4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80050EE8: jal         0x8009A72C
    // 0x80050EEC: sw          $s2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r18;
    Animation_DrawSkeleton(rdram, ctx);
        goto after_78;
    // 0x80050EEC: sw          $s2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r18;
    after_78:
    // 0x80050EF0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80050EF4: lwc1        $f4, 0x114($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X114);
    // 0x80050EF8: c.eq.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl == ctx->f4.fl;
    // 0x80050EFC: nop

    // 0x80050F00: bc1tl       L_800510B8
    if (c1cs) {
        // 0x80050F04: mtc1        $zero, $f10
        ctx->f10.u32l = 0;
            goto L_800510B8;
    }
    goto skip_2;
    // 0x80050F04: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    skip_2:
    // 0x80050F08: jal         0x800BA5B0
    // 0x80050F0C: nop

    RCP_SetupDL_49(rdram, ctx);
        goto after_79;
    // 0x80050F0C: nop

    after_79:
    // 0x80050F10: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x80050F14: addiu       $s0, $s0, -0x4C40
    ctx->r16 = ADD32(ctx->r16, -0X4C40);
    // 0x80050F18: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80050F1C: lui         $t3, 0xFA00
    ctx->r11 = S32(0XFA00 << 16);
    // 0x80050F20: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80050F24: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80050F28: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x80050F2C: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80050F30: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x80050F34: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80050F38: lui         $t6, 0xFF20
    ctx->r14 = S32(0XFF20 << 16);
    // 0x80050F3C: ori         $t6, $t6, 0x20FF
    ctx->r14 = ctx->r14 | 0X20FF;
    // 0x80050F40: addiu       $t1, $v1, 0x8
    ctx->r9 = ADD32(ctx->r3, 0X8);
    // 0x80050F44: sw          $t1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r9;
    // 0x80050F48: lui         $t4, 0xFB00
    ctx->r12 = S32(0XFB00 << 16);
    // 0x80050F4C: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x80050F50: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x80050F54: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80050F58: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80050F5C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80050F60: lui         $a1, 0x4120
    ctx->r5 = S32(0X4120 << 16);
    // 0x80050F64: lui         $a2, 0xC0A0
    ctx->r6 = S32(0XC0A0 << 16);
    // 0x80050F68: jal         0x80005B00
    // 0x80050F6C: lui         $a3, 0xC220
    ctx->r7 = S32(0XC220 << 16);
    Matrix_Translate(rdram, ctx);
        goto after_80;
    // 0x80050F6C: lui         $a3, 0xC220
    ctx->r7 = S32(0XC220 << 16);
    after_80:
    // 0x80050F70: lwc1        $f6, 0x14($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X14);
    // 0x80050F74: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80050F78: lwc1        $f10, 0x5D8C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X5D8C);
    // 0x80050F7C: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x80050F80: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80050F84: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80050F88: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80050F8C: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x80050F90: jal         0x80005E90
    // 0x80050F94: nop

    Matrix_RotateY(rdram, ctx);
        goto after_81;
    // 0x80050F94: nop

    after_81:
    // 0x80050F98: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80050F9C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80050FA0: jal         0x8005980C
    // 0x80050FA4: nop

    Graphics_SetScaleMtx(rdram, ctx);
        goto after_82;
    // 0x80050FA4: nop

    after_82:
    // 0x80050FA8: lwc1        $f0, 0x114($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X114);
    // 0x80050FAC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80050FB0: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80050FB4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80050FB8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80050FBC: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80050FC0: jal         0x80005C34
    // 0x80050FC4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_83;
    // 0x80050FC4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_83:
    // 0x80050FC8: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80050FCC: lw          $v0, -0x7D80($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D80);
    // 0x80050FD0: lwc1        $f8, 0x8($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X8);
    // 0x80050FD4: lwc1        $f4, 0x4($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X4);
    // 0x80050FD8: lwc1        $f6, 0x44($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X44);
    // 0x80050FDC: lwc1        $f18, 0x40($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X40);
    // 0x80050FE0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80050FE4: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80050FE8: sub.s       $f20, $f18, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80050FEC: swc1        $f10, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = ctx->f10.u32l;
    // 0x80050FF0: lwc1        $f16, 0xC($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0XC);
    // 0x80050FF4: lwc1        $f18, 0x7D20($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x80050FF8: lwc1        $f6, 0x48($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X48);
    // 0x80050FFC: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x80051000: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80051004: sub.s       $f22, $f6, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f22.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x80051008: jal         0x80005100
    // 0x8005100C: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    Math_Atan2F(rdram, ctx);
        goto after_84;
    // 0x8005100C: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    after_84:
    // 0x80051010: mul.s       $f10, $f22, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x80051014: neg.s       $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = -ctx->f0.fl;
    // 0x80051018: lwc1        $f12, 0x12C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X12C);
    // 0x8005101C: mul.s       $f16, $f20, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x80051020: swc1        $f8, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->f8.u32l;
    // 0x80051024: add.s       $f0, $f10, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80051028: jal         0x80005100
    // 0x8005102C: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    Math_Atan2F(rdram, ctx);
        goto after_85;
    // 0x8005102C: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    after_85:
    // 0x80051030: lwc1        $f18, 0x124($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X124);
    // 0x80051034: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80051038: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8005103C: neg.s       $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = -ctx->f18.fl;
    // 0x80051040: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80051044: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80051048: jal         0x80005E90
    // 0x8005104C: nop

    Matrix_RotateY(rdram, ctx);
        goto after_86;
    // 0x8005104C: nop

    after_86:
    // 0x80051050: neg.s       $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = -ctx->f20.fl;
    // 0x80051054: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80051058: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8005105C: jal         0x80005D44
    // 0x80051060: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateX(rdram, ctx);
        goto after_87;
    // 0x80051060: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_87:
    // 0x80051064: jal         0x80006EB8
    // 0x80051068: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_88;
    // 0x80051068: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_88:
    // 0x8005106C: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80051070: lui         $t3, 0x102
    ctx->r11 = S32(0X102 << 16);
    // 0x80051074: addiu       $t3, $t3, 0x4AC0
    ctx->r11 = ADD32(ctx->r11, 0X4AC0);
    // 0x80051078: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8005107C: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x80051080: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x80051084: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80051088: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x8005108C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80051090: lwc1        $f8, 0x5D90($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5D90);
    // 0x80051094: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80051098: lui         $a3, 0x3E4C
    ctx->r7 = S32(0X3E4C << 16);
    // 0x8005109C: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x800510A0: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800510A4: addiu       $a0, $s2, 0x114
    ctx->r4 = ADD32(ctx->r18, 0X114);
    // 0x800510A8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x800510AC: jal         0x8009BC2C
    // 0x800510B0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_89;
    // 0x800510B0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_89:
    // 0x800510B4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
L_800510B8:
    // 0x800510B8: lwc1        $f16, 0x12C($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X12C);
    // 0x800510BC: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x800510C0: addiu       $s0, $s0, -0x4C40
    ctx->r16 = ADD32(ctx->r16, -0X4C40);
    // 0x800510C4: c.eq.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl == ctx->f16.fl;
    // 0x800510C8: nop

    // 0x800510CC: bc1t        L_800515A4
    if (c1cs) {
        // 0x800510D0: lui         $t8, 0x102
        ctx->r24 = S32(0X102 << 16);
            goto L_800515A4;
    }
    // 0x800510D0: lui         $t8, 0x102
    ctx->r24 = S32(0X102 << 16);
    // 0x800510D4: addiu       $t8, $t8, 0x4AC0
    ctx->r24 = ADD32(ctx->r24, 0X4AC0);
    // 0x800510D8: jal         0x800BA5B0
    // 0x800510DC: sw          $t8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r24;
    RCP_SetupDL_49(rdram, ctx);
        goto after_90;
    // 0x800510DC: sw          $t8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r24;
    after_90:
    // 0x800510E0: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x800510E4: lui         $t4, 0xFA00
    ctx->r12 = S32(0XFA00 << 16);
    // 0x800510E8: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x800510EC: addiu       $t1, $v1, 0x8
    ctx->r9 = ADD32(ctx->r3, 0X8);
    // 0x800510F0: sw          $t1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r9;
    // 0x800510F4: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x800510F8: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x800510FC: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80051100: lui         $t7, 0xFF30
    ctx->r15 = S32(0XFF30 << 16);
    // 0x80051104: ori         $t7, $t7, 0xFF
    ctx->r15 = ctx->r15 | 0XFF;
    // 0x80051108: addiu       $t5, $v1, 0x8
    ctx->r13 = ADD32(ctx->r3, 0X8);
    // 0x8005110C: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
    // 0x80051110: lui         $t2, 0xFB00
    ctx->r10 = S32(0XFB00 << 16);
    // 0x80051114: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x80051118: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8005111C: jal         0x80005740
    // 0x80051120: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_91;
    // 0x80051120: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_91:
    // 0x80051124: jal         0x80005708
    // 0x80051128: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_Push(rdram, ctx);
        goto after_92;
    // 0x80051128: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_92:
    // 0x8005112C: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80051130: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80051134: lwc1        $f18, 0x14($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X14);
    // 0x80051138: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005113C: lwc1        $f8, 0x5D94($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5D94);
    // 0x80051140: sub.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x80051144: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80051148: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8005114C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80051150: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80051154: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80051158: jal         0x80005E90
    // 0x8005115C: nop

    Matrix_RotateY(rdram, ctx);
        goto after_93;
    // 0x8005115C: nop

    after_93:
    // 0x80051160: lui         $at, 0x4352
    ctx->r1 = S32(0X4352 << 16);
    // 0x80051164: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80051168: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x8005116C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80051170: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80051174: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80051178: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8005117C: addiu       $a1, $sp, 0x2B8
    ctx->r5 = ADD32(ctx->r29, 0X2B8);
    // 0x80051180: addiu       $a2, $sp, 0x2AC
    ctx->r6 = ADD32(ctx->r29, 0X2AC);
    // 0x80051184: swc1        $f16, 0x2B8($sp)
    MEM_W(0X2B8, ctx->r29) = ctx->f16.u32l;
    // 0x80051188: swc1        $f18, 0x2BC($sp)
    MEM_W(0X2BC, ctx->r29) = ctx->f18.u32l;
    // 0x8005118C: jal         0x80006A20
    // 0x80051190: swc1        $f6, 0x2C0($sp)
    MEM_W(0X2C0, ctx->r29) = ctx->f6.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_94;
    // 0x80051190: swc1        $f6, 0x2C0($sp)
    MEM_W(0X2C0, ctx->r29) = ctx->f6.u32l;
    after_94:
    // 0x80051194: lwc1        $f4, 0x4($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X4);
    // 0x80051198: lwc1        $f8, 0x2AC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2AC);
    // 0x8005119C: lwc1        $f16, 0x8($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X8);
    // 0x800511A0: lwc1        $f18, 0x2B0($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2B0);
    // 0x800511A4: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800511A8: lwc1        $f8, 0x2B4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2B4);
    // 0x800511AC: lwc1        $f4, 0xC($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0XC);
    // 0x800511B0: add.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800511B4: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x800511B8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800511BC: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800511C0: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x800511C4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800511C8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800511CC: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x800511D0: jal         0x80005B00
    // 0x800511D4: nop

    Matrix_Translate(rdram, ctx);
        goto after_95;
    // 0x800511D4: nop

    after_95:
    // 0x800511D8: lwc1        $f0, 0x12C($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X12C);
    // 0x800511DC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800511E0: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x800511E4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800511E8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800511EC: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800511F0: jal         0x80005C34
    // 0x800511F4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_96;
    // 0x800511F4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_96:
    // 0x800511F8: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800511FC: lw          $v0, -0x7D80($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D80);
    // 0x80051200: lwc1        $f4, 0x8($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X8);
    // 0x80051204: lwc1        $f18, 0x4($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X4);
    // 0x80051208: lwc1        $f6, 0x44($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X44);
    // 0x8005120C: lwc1        $f16, 0x40($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X40);
    // 0x80051210: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80051214: sub.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x80051218: sub.s       $f20, $f16, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f20.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8005121C: swc1        $f8, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = ctx->f8.u32l;
    // 0x80051220: lwc1        $f10, 0xC($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0XC);
    // 0x80051224: lwc1        $f16, 0x7D20($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x80051228: lwc1        $f6, 0x48($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X48);
    // 0x8005122C: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x80051230: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80051234: sub.s       $f22, $f6, $f18
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f22.fl = ctx->f6.fl - ctx->f18.fl;
    // 0x80051238: jal         0x80005100
    // 0x8005123C: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    Math_Atan2F(rdram, ctx);
        goto after_97;
    // 0x8005123C: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    after_97:
    // 0x80051240: mul.s       $f8, $f22, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x80051244: neg.s       $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = -ctx->f0.fl;
    // 0x80051248: lwc1        $f12, 0x12C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X12C);
    // 0x8005124C: mul.s       $f10, $f20, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x80051250: swc1        $f4, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->f4.u32l;
    // 0x80051254: add.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80051258: jal         0x80005100
    // 0x8005125C: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    Math_Atan2F(rdram, ctx);
        goto after_98;
    // 0x8005125C: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    after_98:
    // 0x80051260: lwc1        $f16, 0x124($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X124);
    // 0x80051264: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80051268: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8005126C: neg.s       $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = -ctx->f16.fl;
    // 0x80051270: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80051274: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80051278: jal         0x80005E90
    // 0x8005127C: nop

    Matrix_RotateY(rdram, ctx);
        goto after_99;
    // 0x8005127C: nop

    after_99:
    // 0x80051280: neg.s       $f18, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = -ctx->f20.fl;
    // 0x80051284: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80051288: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8005128C: jal         0x80005D44
    // 0x80051290: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateX(rdram, ctx);
        goto after_100;
    // 0x80051290: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_100:
    // 0x80051294: jal         0x80006EB8
    // 0x80051298: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_101;
    // 0x80051298: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_101:
    // 0x8005129C: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x800512A0: addiu       $a0, $s2, 0x12C
    ctx->r4 = ADD32(ctx->r18, 0X12C);
    // 0x800512A4: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x800512A8: lui         $t1, 0x600
    ctx->r9 = S32(0X600 << 16);
    // 0x800512AC: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x800512B0: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x800512B4: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x800512B8: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x800512BC: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x800512C0: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800512C4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x800512C8: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x800512CC: lui         $a3, 0x3F19
    ctx->r7 = S32(0X3F19 << 16);
    // 0x800512D0: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x800512D4: jal         0x8009BC2C
    // 0x800512D8: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_102;
    // 0x800512D8: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    after_102:
    // 0x800512DC: b           L_800515A8
    // 0x800512E0: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_800515A8;
    // 0x800512E0: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_800512E4:
    // 0x800512E4: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800512E8: addiu       $s1, $s1, 0x7E64
    ctx->r17 = ADD32(ctx->r17, 0X7E64);
    // 0x800512EC: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x800512F0: lui         $t2, 0x601
    ctx->r10 = S32(0X601 << 16);
    // 0x800512F4: addiu       $t2, $t2, 0x32A0
    ctx->r10 = ADD32(ctx->r10, 0X32A0);
    // 0x800512F8: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800512FC: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x80051300: lui         $t5, 0x600
    ctx->r13 = S32(0X600 << 16);
    // 0x80051304: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x80051308: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x8005130C: b           L_800515A8
    // 0x80051310: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_800515A8;
    // 0x80051310: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_80051314:
    // 0x80051314: jal         0x801BE0F0
    // 0x80051318: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Aquas_CsAqFishGroup_Draw(rdram, ctx);
        goto after_103;
    // 0x80051318: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_103:
    // 0x8005131C: b           L_800515A8
    // 0x80051320: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_800515A8;
    // 0x80051320: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_80051324:
    // 0x80051324: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x80051328: addiu       $s1, $s1, 0x7E64
    ctx->r17 = ADD32(ctx->r17, 0X7E64);
    // 0x8005132C: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80051330: lui         $t3, 0x601
    ctx->r11 = S32(0X601 << 16);
    // 0x80051334: addiu       $t3, $t3, 0x4A40
    ctx->r11 = ADD32(ctx->r11, 0X4A40);
    // 0x80051338: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8005133C: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x80051340: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x80051344: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80051348: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x8005134C: b           L_800515A8
    // 0x80051350: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_800515A8;
    // 0x80051350: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_80051354:
    // 0x80051354: jal         0x800BA5B0
    // 0x80051358: nop

    RCP_SetupDL_49(rdram, ctx);
        goto after_104;
    // 0x80051358: nop

    after_104:
    // 0x8005135C: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x80051360: addiu       $s1, $s1, 0x7E64
    ctx->r17 = ADD32(ctx->r17, 0X7E64);
    // 0x80051364: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80051368: lui         $t1, 0xFA00
    ctx->r9 = S32(0XFA00 << 16);
    // 0x8005136C: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x80051370: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80051374: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x80051378: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x8005137C: lw          $t4, 0x50($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X50);
    // 0x80051380: lui         $t7, 0xFB00
    ctx->r15 = S32(0XFB00 << 16);
    // 0x80051384: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80051388: andi        $t6, $t4, 0xFF
    ctx->r14 = ctx->r12 & 0XFF;
    // 0x8005138C: or          $t5, $t6, $at
    ctx->r13 = ctx->r14 | ctx->r1;
    // 0x80051390: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x80051394: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80051398: lui         $t9, 0xFFC0
    ctx->r25 = S32(0XFFC0 << 16);
    // 0x8005139C: ori         $t9, $t9, 0x80FF
    ctx->r25 = ctx->r25 | 0X80FF;
    // 0x800513A0: addiu       $t2, $v1, 0x8
    ctx->r10 = ADD32(ctx->r3, 0X8);
    // 0x800513A4: sw          $t2, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r10;
    // 0x800513A8: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x800513AC: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800513B0: lw          $v0, -0x7D80($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D80);
    // 0x800513B4: lwc1        $f4, 0x40($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X40);
    // 0x800513B8: lwc1        $f8, 0x4C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4C);
    // 0x800513BC: lwc1        $f10, 0x48($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X48);
    // 0x800513C0: lwc1        $f16, 0x54($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X54);
    // 0x800513C4: sub.s       $f12, $f4, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x800513C8: jal         0x80005100
    // 0x800513CC: sub.s       $f14, $f10, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f16.fl;
    Math_Atan2F(rdram, ctx);
        goto after_105;
    // 0x800513CC: sub.s       $f14, $f10, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f16.fl;
    after_105:
    // 0x800513D0: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x800513D4: addiu       $s0, $s0, -0x4C40
    ctx->r16 = ADD32(ctx->r16, -0X4C40);
    // 0x800513D8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800513DC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800513E0: jal         0x80005E90
    // 0x800513E4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateY(rdram, ctx);
        goto after_106;
    // 0x800513E4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_106:
    // 0x800513E8: lwc1        $f0, 0x114($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X114);
    // 0x800513EC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800513F0: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x800513F4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800513F8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800513FC: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80051400: jal         0x80005C34
    // 0x80051404: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_107;
    // 0x80051404: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_107:
    // 0x80051408: jal         0x80006EB8
    // 0x8005140C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_108;
    // 0x8005140C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_108:
    // 0x80051410: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80051414: lui         $t4, 0x102
    ctx->r12 = S32(0X102 << 16);
    // 0x80051418: addiu       $t4, $t4, 0x4AC0
    ctx->r12 = ADD32(ctx->r12, 0X4AC0);
    // 0x8005141C: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80051420: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x80051424: lui         $t1, 0x600
    ctx->r9 = S32(0X600 << 16);
    // 0x80051428: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x8005142C: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x80051430: lw          $a0, 0x50($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X50);
    // 0x80051434: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80051438: beq         $a0, $zero, L_80051444
    if (ctx->r4 == 0) {
        // 0x8005143C: addiu       $t6, $a0, -0x7
        ctx->r14 = ADD32(ctx->r4, -0X7);
            goto L_80051444;
    }
    // 0x8005143C: addiu       $t6, $a0, -0x7
    ctx->r14 = ADD32(ctx->r4, -0X7);
    // 0x80051440: sw          $t6, 0x50($s2)
    MEM_W(0X50, ctx->r18) = ctx->r14;
L_80051444:
    // 0x80051444: lwc1        $f6, 0x114($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X114);
    // 0x80051448: lwc1        $f18, 0x5D98($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X5D98);
    // 0x8005144C: add.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x80051450: b           L_800515A4
    // 0x80051454: swc1        $f4, 0x114($s2)
    MEM_W(0X114, ctx->r18) = ctx->f4.u32l;
        goto L_800515A4;
    // 0x80051454: swc1        $f4, 0x114($s2)
    MEM_W(0X114, ctx->r18) = ctx->f4.u32l;
L_80051458:
    // 0x80051458: lui         $a0, 0x602
    ctx->r4 = S32(0X602 << 16);
    // 0x8005145C: addiu       $s0, $s2, 0x18C
    ctx->r16 = ADD32(ctx->r18, 0X18C);
    // 0x80051460: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80051464: addiu       $a0, $a0, 0xA40
    ctx->r4 = ADD32(ctx->r4, 0XA40);
    // 0x80051468: jal         0x8009AA20
    // 0x8005146C: lw          $a1, 0x50($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X50);
    Animation_GetFrameData(rdram, ctx);
        goto after_109;
    // 0x8005146C: lw          $a1, 0x50($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X50);
    after_109:
    // 0x80051470: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x80051474: addiu       $s1, $s1, 0x7E64
    ctx->r17 = ADD32(ctx->r17, 0X7E64);
    // 0x80051478: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8005147C: lui         $t2, 0xB600
    ctx->r10 = S32(0XB600 << 16);
    // 0x80051480: addiu       $t7, $zero, 0x2000
    ctx->r15 = ADD32(0, 0X2000);
    // 0x80051484: addiu       $t5, $v1, 0x8
    ctx->r13 = ADD32(ctx->r3, 0X8);
    // 0x80051488: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
    // 0x8005148C: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80051490: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x80051494: lui         $t3, 0x800C
    ctx->r11 = S32(0X800C << 16);
    // 0x80051498: addiu       $t3, $t3, 0x4660
    ctx->r11 = ADD32(ctx->r11, 0X4660);
    // 0x8005149C: lui         $a1, 0x602
    ctx->r5 = S32(0X602 << 16);
    // 0x800514A0: addiu       $t9, $s2, 0x40
    ctx->r25 = ADD32(ctx->r18, 0X40);
    // 0x800514A4: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x800514A8: addiu       $a1, $a1, 0xC6C
    ctx->r5 = ADD32(ctx->r5, 0XC6C);
    // 0x800514AC: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x800514B0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800514B4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x800514B8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800514BC: jal         0x8009A72C
    // 0x800514C0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    Animation_DrawSkeleton(rdram, ctx);
        goto after_110;
    // 0x800514C0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_110:
    // 0x800514C4: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x800514C8: lui         $t1, 0xB700
    ctx->r9 = S32(0XB700 << 16);
    // 0x800514CC: addiu       $t4, $zero, 0x2000
    ctx->r12 = ADD32(0, 0X2000);
    // 0x800514D0: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x800514D4: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x800514D8: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x800514DC: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x800514E0: b           L_800515A8
    // 0x800514E4: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_800515A8;
    // 0x800514E4: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_800514E8:
    // 0x800514E8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800514EC: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x800514F0: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x800514F4: addiu       $s0, $s0, -0x4C40
    ctx->r16 = ADD32(ctx->r16, -0X4C40);
    // 0x800514F8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800514FC: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    // 0x80051500: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x80051504: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80051508: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8005150C: jal         0x80005C34
    // 0x80051510: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_111;
    // 0x80051510: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_111:
    // 0x80051514: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x80051518: addiu       $s1, $s1, 0x7E64
    ctx->r17 = ADD32(ctx->r17, 0X7E64);
    // 0x8005151C: jal         0x80006EB8
    // 0x80051520: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_112;
    // 0x80051520: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_112:
    // 0x80051524: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80051528: lui         $t7, 0x601
    ctx->r15 = S32(0X601 << 16);
    // 0x8005152C: addiu       $t7, $t7, -0x1110
    ctx->r15 = ADD32(ctx->r15, -0X1110);
    // 0x80051530: addiu       $t5, $v1, 0x8
    ctx->r13 = ADD32(ctx->r3, 0X8);
    // 0x80051534: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
    // 0x80051538: lui         $t2, 0x600
    ctx->r10 = S32(0X600 << 16);
    // 0x8005153C: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x80051540: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80051544: b           L_800515A8
    // 0x80051548: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_800515A8;
    // 0x80051548: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_8005154C:
    // 0x8005154C: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x80051550: addiu       $s1, $s1, 0x7E64
    ctx->r17 = ADD32(ctx->r17, 0X7E64);
    // 0x80051554: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80051558: lui         $t8, 0x602
    ctx->r24 = S32(0X602 << 16);
    // 0x8005155C: addiu       $t8, $t8, -0x21A0
    ctx->r24 = ADD32(ctx->r24, -0X21A0);
    // 0x80051560: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80051564: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x80051568: lui         $t3, 0x600
    ctx->r11 = S32(0X600 << 16);
    // 0x8005156C: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x80051570: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80051574: b           L_800515A8
    // 0x80051578: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_800515A8;
    // 0x80051578: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_8005157C:
    // 0x8005157C: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x80051580: addiu       $s1, $s1, 0x7E64
    ctx->r17 = ADD32(ctx->r17, 0X7E64);
    // 0x80051584: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80051588: lui         $t6, 0x603
    ctx->r14 = S32(0X603 << 16);
    // 0x8005158C: addiu       $t6, $t6, -0x4B40
    ctx->r14 = ADD32(ctx->r14, -0X4B40);
    // 0x80051590: addiu       $t1, $v1, 0x8
    ctx->r9 = ADD32(ctx->r3, 0X8);
    // 0x80051594: sw          $t1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r9;
    // 0x80051598: lui         $t4, 0x600
    ctx->r12 = S32(0X600 << 16);
    // 0x8005159C: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x800515A0: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
L_800515A4:
    // 0x800515A4: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_800515A8:
    // 0x800515A8: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x800515AC: ldc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X30);
    // 0x800515B0: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x800515B4: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x800515B8: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x800515BC: jr          $ra
    // 0x800515C0: addiu       $sp, $sp, 0x2E0
    ctx->r29 = ADD32(ctx->r29, 0X2E0);
    return;
    // 0x800515C0: addiu       $sp, $sp, 0x2E0
    ctx->r29 = ADD32(ctx->r29, 0X2E0);
;}
RECOMP_FUNC void ActorEvent_SpawnEffect365(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007240C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80072410: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80072414: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80072418: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8007241C: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80072420: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80072424: addiu       $v0, $v0, 0x37E0
    ctx->r2 = ADD32(ctx->r2, 0X37E0);
    // 0x80072428: addiu       $a0, $a0, 0x130
    ctx->r4 = ADD32(ctx->r4, 0X130);
    // 0x8007242C: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
L_80072430:
    // 0x80072430: bnel        $t6, $zero, L_8007245C
    if (ctx->r14 != 0) {
        // 0x80072434: addiu       $a0, $a0, 0x8C
        ctx->r4 = ADD32(ctx->r4, 0X8C);
            goto L_8007245C;
    }
    goto skip_0;
    // 0x80072434: addiu       $a0, $a0, 0x8C
    ctx->r4 = ADD32(ctx->r4, 0X8C);
    skip_0:
    // 0x80072438: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8007243C: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x80072440: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x80072444: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80072448: jal         0x800722EC
    // 0x8007244C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    ActorEvent_SetupEffect365(rdram, ctx);
        goto after_0;
    // 0x8007244C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x80072450: b           L_80072468
    // 0x80072454: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80072468;
    // 0x80072454: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80072458: addiu       $a0, $a0, 0x8C
    ctx->r4 = ADD32(ctx->r4, 0X8C);
L_8007245C:
    // 0x8007245C: bnel        $a0, $v0, L_80072430
    if (ctx->r4 != ctx->r2) {
        // 0x80072460: lbu         $t6, 0x0($a0)
        ctx->r14 = MEM_BU(ctx->r4, 0X0);
            goto L_80072430;
    }
    goto skip_1;
    // 0x80072460: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    skip_1:
    // 0x80072464: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80072468:
    // 0x80072468: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8007246C: jr          $ra
    // 0x80072470: nop

    return;
    // 0x80072470: nop

;}
RECOMP_FUNC void func_versus_800BD05C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BD05C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800BD060: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800BD064: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800BD068: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800BD06C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BD070: lui         $a1, 0x300
    ctx->r5 = S32(0X300 << 16);
    // 0x800BD074: lui         $a2, 0x300
    ctx->r6 = S32(0X300 << 16);
    // 0x800BD078: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x800BD07C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800BD080: addiu       $a2, $a2, 0x4E0
    ctx->r6 = ADD32(ctx->r6, 0X4E0);
    // 0x800BD084: addiu       $a1, $a1, 0x3A0
    ctx->r5 = ADD32(ctx->r5, 0X3A0);
    // 0x800BD088: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x800BD08C: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    // 0x800BD090: swc1        $f12, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f12.u32l;
    // 0x800BD094: swc1        $f14, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f14.u32l;
    // 0x800BD098: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x800BD09C: jal         0x8009C320
    // 0x800BD0A0: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    Lib_TextureRect_CI4(rdram, ctx);
        goto after_0;
    // 0x800BD0A0: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x800BD0A4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800BD0A8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800BD0AC: jr          $ra
    // 0x800BD0B0: nop

    return;
    // 0x800BD0B0: nop

;}
RECOMP_FUNC void Audio_StopSfxByBankAndSource(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A38C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8001A390: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8001A394: andi        $s5, $a0, 0xFF
    ctx->r21 = ctx->r4 & 0XFF;
    // 0x8001A398: sll         $t6, $s5, 4
    ctx->r14 = S32(ctx->r21 << 4);
    // 0x8001A39C: subu        $t6, $t6, $s5
    ctx->r14 = SUB32(ctx->r14, ctx->r21);
    // 0x8001A3A0: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x8001A3A4: addiu       $t7, $t7, -0x79A0
    ctx->r15 = ADD32(ctx->r15, -0X79A0);
    // 0x8001A3A8: sll         $t6, $t6, 6
    ctx->r14 = S32(ctx->r14 << 6);
    // 0x8001A3AC: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8001A3B0: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8001A3B4: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8001A3B8: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8001A3BC: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8001A3C0: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8001A3C4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8001A3C8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8001A3CC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001A3D0: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8001A3D4: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8001A3D8: lbu         $s1, 0x2B($t8)
    ctx->r17 = MEM_BU(ctx->r24, 0X2B);
    // 0x8001A3DC: addiu       $s7, $zero, 0xFF
    ctx->r23 = ADD32(0, 0XFF);
    // 0x8001A3E0: or          $s6, $a1, $zero
    ctx->r22 = ctx->r5 | 0;
    // 0x8001A3E4: beq         $s7, $s1, L_8001A488
    if (ctx->r23 == ctx->r17) {
        // 0x8001A3E8: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_8001A488;
    }
    // 0x8001A3E8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8001A3EC: sll         $t9, $s5, 4
    ctx->r25 = S32(ctx->r21 << 4);
    // 0x8001A3F0: subu        $t9, $t9, $s5
    ctx->r25 = SUB32(ctx->r25, ctx->r21);
    // 0x8001A3F4: sll         $t9, $t9, 6
    ctx->r25 = S32(ctx->r25 << 6);
    // 0x8001A3F8: addu        $s3, $t9, $t7
    ctx->r19 = ADD32(ctx->r25, ctx->r15);
    // 0x8001A3FC: addiu       $fp, $zero, 0x30
    ctx->r30 = ADD32(0, 0X30);
L_8001A400:
    // 0x8001A400: multu       $s1, $fp
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001A404: sll         $t2, $s2, 2
    ctx->r10 = S32(ctx->r18 << 2);
    // 0x8001A408: mflo        $t0
    ctx->r8 = lo;
    // 0x8001A40C: addu        $s0, $s3, $t0
    ctx->r16 = ADD32(ctx->r19, ctx->r8);
    // 0x8001A410: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x8001A414: bnel        $s6, $t1, L_8001A46C
    if (ctx->r22 != ctx->r9) {
        // 0x8001A418: andi        $s2, $s1, 0xFF
        ctx->r18 = ctx->r17 & 0XFF;
            goto L_8001A46C;
    }
    goto skip_0;
    // 0x8001A418: andi        $s2, $s1, 0xFF
    ctx->r18 = ctx->r17 & 0XFF;
    skip_0:
    // 0x8001A41C: lbu         $v0, 0x28($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X28);
    // 0x8001A420: subu        $t2, $t2, $s2
    ctx->r10 = SUB32(ctx->r10, ctx->r18);
    // 0x8001A424: sll         $t2, $t2, 4
    ctx->r10 = S32(ctx->r10 << 4);
    // 0x8001A428: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x8001A42C: bne         $at, $zero, L_8001A450
    if (ctx->r1 != 0) {
        // 0x8001A430: addu        $s4, $s3, $t2
        ctx->r20 = ADD32(ctx->r19, ctx->r10);
            goto L_8001A450;
    }
    // 0x8001A430: addu        $s4, $s3, $t2
    ctx->r20 = ADD32(ctx->r19, ctx->r10);
    // 0x8001A434: lbu         $t3, 0x2C($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X2C);
    // 0x8001A438: lui         $at, 0x602
    ctx->r1 = S32(0X602 << 16);
    // 0x8001A43C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001A440: sll         $t4, $t3, 8
    ctx->r12 = S32(ctx->r11 << 8);
    // 0x8001A444: jal         0x8001E8F0
    // 0x8001A448: or          $a0, $t4, $at
    ctx->r4 = ctx->r12 | ctx->r1;
    AudioThread_QueueCmdS8(rdram, ctx);
        goto after_0;
    // 0x8001A448: or          $a0, $t4, $at
    ctx->r4 = ctx->r12 | ctx->r1;
    after_0:
    // 0x8001A44C: lbu         $v0, 0x28($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X28);
L_8001A450:
    // 0x8001A450: beq         $v0, $zero, L_8001A460
    if (ctx->r2 == 0) {
        // 0x8001A454: andi        $a0, $s5, 0xFF
        ctx->r4 = ctx->r21 & 0XFF;
            goto L_8001A460;
    }
    // 0x8001A454: andi        $a0, $s5, 0xFF
    ctx->r4 = ctx->r21 & 0XFF;
    // 0x8001A458: jal         0x800197AC
    // 0x8001A45C: andi        $a1, $s1, 0xFF
    ctx->r5 = ctx->r17 & 0XFF;
    Audio_RemoveSfxBankEntry(rdram, ctx);
        goto after_1;
    // 0x8001A45C: andi        $a1, $s1, 0xFF
    ctx->r5 = ctx->r17 & 0XFF;
    after_1:
L_8001A460:
    // 0x8001A460: b           L_8001A480
    // 0x8001A464: lbu         $s1, 0x2B($s4)
    ctx->r17 = MEM_BU(ctx->r20, 0X2B);
        goto L_8001A480;
    // 0x8001A464: lbu         $s1, 0x2B($s4)
    ctx->r17 = MEM_BU(ctx->r20, 0X2B);
    // 0x8001A468: andi        $s2, $s1, 0xFF
    ctx->r18 = ctx->r17 & 0XFF;
L_8001A46C:
    // 0x8001A46C: sll         $t6, $s2, 2
    ctx->r14 = S32(ctx->r18 << 2);
    // 0x8001A470: subu        $t6, $t6, $s2
    ctx->r14 = SUB32(ctx->r14, ctx->r18);
    // 0x8001A474: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x8001A478: addu        $t8, $s3, $t6
    ctx->r24 = ADD32(ctx->r19, ctx->r14);
    // 0x8001A47C: lbu         $s1, 0x2B($t8)
    ctx->r17 = MEM_BU(ctx->r24, 0X2B);
L_8001A480:
    // 0x8001A480: bne         $s7, $s1, L_8001A400
    if (ctx->r23 != ctx->r17) {
        // 0x8001A484: nop
    
            goto L_8001A400;
    }
    // 0x8001A484: nop

L_8001A488:
    // 0x8001A488: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8001A48C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001A490: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8001A494: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8001A498: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8001A49C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8001A4A0: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8001A4A4: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8001A4A8: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8001A4AC: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8001A4B0: jr          $ra
    // 0x8001A4B4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8001A4B4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void Game_SetGameState(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A1980: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A1984: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A1988: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800A198C: lwc1        $f4, 0x1A10($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X1A10);
    // 0x800A1990: lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // 0x800A1994: lhu         $v1, 0x1A32($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X1A32);
    // 0x800A1998: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800A199C: swc1        $f4, 0x1A14($at)
    MEM_W(0X1A14, ctx->r1) = ctx->f4.u32l;
    // 0x800A19A0: beq         $v1, $zero, L_800A1B5C
    if (ctx->r3 == 0) {
        // 0x800A19A4: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_800A1B5C;
    }
    // 0x800A19A4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800A19A8: beq         $v1, $at, L_800A1A1C
    if (ctx->r3 == ctx->r1) {
        // 0x800A19AC: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_800A1A1C;
    }
    // 0x800A19AC: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800A19B0: beq         $v1, $at, L_800A1A28
    if (ctx->r3 == ctx->r1) {
        // 0x800A19B4: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_800A1A28;
    }
    // 0x800A19B4: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x800A19B8: bne         $v1, $at, L_800A1A30
    if (ctx->r3 != ctx->r1) {
        // 0x800A19BC: lui         $t6, 0x8016
        ctx->r14 = S32(0X8016 << 16);
            goto L_800A1A30;
    }
    // 0x800A19BC: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x800A19C0: lhu         $t6, 0x1A30($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X1A30);
    // 0x800A19C4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800A19C8: jal         0x800A5844
    // 0x800A19CC: sw          $t6, -0x7DCC($at)
    MEM_W(-0X7DCC, ctx->r1) = ctx->r14;
    Play_Setup(rdram, ctx);
        goto after_0;
    // 0x800A19CC: sw          $t6, -0x7DCC($at)
    MEM_W(-0X7DCC, ctx->r1) = ctx->r14;
    after_0:
    // 0x800A19D0: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x800A19D4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A19D8: addiu       $v0, $v0, 0x1A2E
    ctx->r2 = ADD32(ctx->r2, 0X1A2E);
    // 0x800A19DC: sw          $zero, 0x7854($at)
    MEM_W(0X7854, ctx->r1) = 0;
    // 0x800A19E0: lhu         $t7, 0x0($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X0);
    // 0x800A19E4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800A19E8: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800A19EC: sw          $t7, -0x7D84($at)
    MEM_W(-0X7D84, ctx->r1) = ctx->r15;
    // 0x800A19F0: sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
    // 0x800A19F4: lw          $t8, -0x7D84($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7D84);
    // 0x800A19F8: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800A19FC: beq         $t8, $zero, L_800A1A30
    if (ctx->r24 == 0) {
        // 0x800A1A00: nop
    
            goto L_800A1A30;
    }
    // 0x800A1A00: nop

    // 0x800A1A04: lw          $t9, -0x7DCC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7DCC);
    // 0x800A1A08: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x800A1A0C: beq         $t9, $at, L_800A1A30
    if (ctx->r25 == ctx->r1) {
        // 0x800A1A10: lui         $at, 0x8017
        ctx->r1 = S32(0X8017 << 16);
            goto L_800A1A30;
    }
    // 0x800A1A10: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A1A14: b           L_800A1A30
    // 0x800A1A18: sw          $zero, 0x782C($at)
    MEM_W(0X782C, ctx->r1) = 0;
        goto L_800A1A30;
    // 0x800A1A18: sw          $zero, 0x782C($at)
    MEM_W(0X782C, ctx->r1) = 0;
L_800A1A1C:
    // 0x800A1A1C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A1A20: b           L_800A1A30
    // 0x800A1A24: sw          $zero, 0x7B40($at)
    MEM_W(0X7B40, ctx->r1) = 0;
        goto L_800A1A30;
    // 0x800A1A24: sw          $zero, 0x7B40($at)
    MEM_W(0X7B40, ctx->r1) = 0;
L_800A1A28:
    // 0x800A1A28: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A1A2C: sw          $zero, 0x7868($at)
    MEM_W(0X7868, ctx->r1) = 0;
L_800A1A30:
    // 0x800A1A30: jal         0x80006F20
    // 0x800A1A34: nop

    Memory_FreeAll(rdram, ctx);
        goto after_1;
    // 0x800A1A34: nop

    after_1:
    // 0x800A1A38: jal         0x800A6148
    // 0x800A1A3C: nop

    Play_ClearObjectData(rdram, ctx);
        goto after_2;
    // 0x800A1A3C: nop

    after_2:
    // 0x800A1A40: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x800A1A44: lhu         $t0, 0x1A32($t0)
    ctx->r8 = MEM_HU(ctx->r8, 0X1A32);
    // 0x800A1A48: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A1A4C: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x800A1A50: sw          $t0, 0x7834($at)
    MEM_W(0X7834, ctx->r1) = ctx->r8;
    // 0x800A1A54: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A1A58: sw          $t1, 0x783C($at)
    MEM_W(0X783C, ctx->r1) = ctx->r9;
    // 0x800A1A5C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800A1A60: sw          $zero, -0x6DC($at)
    MEM_W(-0X6DC, ctx->r1) = 0;
    // 0x800A1A64: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800A1A68: sh          $zero, 0x1A32($at)
    MEM_H(0X1A32, ctx->r1) = 0;
    // 0x800A1A6C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A1A70: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x800A1A74: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800A1A78: sw          $zero, 0x7820($at)
    MEM_W(0X7820, ctx->r1) = 0;
    // 0x800A1A7C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800A1A80: addiu       $a0, $a0, 0x7E88
    ctx->r4 = ADD32(ctx->r4, 0X7E88);
    // 0x800A1A84: addiu       $v0, $v0, 0x1A36
    ctx->r2 = ADD32(ctx->r2, 0X1A36);
    // 0x800A1A88: sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
    // 0x800A1A8C: sh          $zero, 0x0($a0)
    MEM_H(0X0, ctx->r4) = 0;
    // 0x800A1A90: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800A1A94: lw          $t3, -0x7DCC($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X7DCC);
    // 0x800A1A98: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A1A9C: swc1        $f6, 0x7D20($at)
    MEM_W(0X7D20, ctx->r1) = ctx->f6.u32l;
    // 0x800A1AA0: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x800A1AA4: bne         $t3, $at, L_800A1AEC
    if (ctx->r11 != ctx->r1) {
        // 0x800A1AA8: lui         $t4, 0x8018
        ctx->r12 = S32(0X8018 << 16);
            goto L_800A1AEC;
    }
    // 0x800A1AA8: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800A1AAC: lw          $t4, -0x7D84($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7D84);
    // 0x800A1AB0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A1AB4: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x800A1AB8: bne         $t4, $at, L_800A1AEC
    if (ctx->r12 != ctx->r1) {
        // 0x800A1ABC: addiu       $v1, $v1, -0x7CAC
        ctx->r3 = ADD32(ctx->r3, -0X7CAC);
            goto L_800A1AEC;
    }
    // 0x800A1ABC: addiu       $v1, $v1, -0x7CAC
    ctx->r3 = ADD32(ctx->r3, -0X7CAC);
    // 0x800A1AC0: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800A1AC4: ori         $t6, $zero, 0xFFFF
    ctx->r14 = 0 | 0XFFFF;
    // 0x800A1AC8: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x800A1ACC: addiu       $a1, $a1, -0x7CB0
    ctx->r5 = ADD32(ctx->r5, -0X7CB0);
    // 0x800A1AD0: sh          $t6, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r14;
    // 0x800A1AD4: sh          $t6, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r14;
    // 0x800A1AD8: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x800A1ADC: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800A1AE0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800A1AE4: b           L_800A1B14
    // 0x800A1AE8: sw          $t7, -0x7CB8($at)
    MEM_W(-0X7CB8, ctx->r1) = ctx->r15;
        goto L_800A1B14;
    // 0x800A1AE8: sw          $t7, -0x7CB8($at)
    MEM_W(-0X7CB8, ctx->r1) = ctx->r15;
L_800A1AEC:
    // 0x800A1AEC: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x800A1AF0: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800A1AF4: addiu       $a1, $a1, -0x7CB0
    ctx->r5 = ADD32(ctx->r5, -0X7CB0);
    // 0x800A1AF8: addiu       $v1, $v1, -0x7CAC
    ctx->r3 = ADD32(ctx->r3, -0X7CAC);
    // 0x800A1AFC: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x800A1B00: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x800A1B04: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800A1B08: sw          $zero, -0x7CB8($at)
    MEM_W(-0X7CB8, ctx->r1) = 0;
    // 0x800A1B0C: jal         0x8001DBD0
    // 0x800A1B10: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    Audio_FadeOutAll(rdram, ctx);
        goto after_3;
    // 0x800A1B10: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
L_800A1B14:
    // 0x800A1B14: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x800A1B18: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800A1B1C: sw          $t2, -0x7CC0($at)
    MEM_W(-0X7CC0, ctx->r1) = ctx->r10;
    // 0x800A1B20: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800A1B24: sw          $zero, -0x7C80($at)
    MEM_W(-0X7C80, ctx->r1) = 0;
    // 0x800A1B28: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800A1B2C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800A1B30: sw          $zero, -0x7D64($at)
    MEM_W(-0X7D64, ctx->r1) = 0;
    // 0x800A1B34: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800A1B38: swc1        $f8, -0x7BD8($at)
    MEM_W(-0X7BD8, ctx->r1) = ctx->f8.u32l;
    // 0x800A1B3C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800A1B40: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x800A1B44: sb          $t3, 0x1A38($at)
    MEM_B(0X1A38, ctx->r1) = ctx->r11;
    // 0x800A1B48: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A1B4C: jal         0x8001AE58
    // 0x800A1B50: sw          $zero, 0x7898($at)
    MEM_W(0X7898, ctx->r1) = 0;
    Audio_ClearVoice(rdram, ctx);
        goto after_4;
    // 0x800A1B50: sw          $zero, 0x7898($at)
    MEM_W(0X7898, ctx->r1) = 0;
    after_4:
    // 0x800A1B54: jal         0x8001D400
    // 0x800A1B58: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    Audio_SetEnvSfxReverb(rdram, ctx);
        goto after_5;
    // 0x800A1B58: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_5:
L_800A1B5C:
    // 0x800A1B5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A1B60: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A1B64: jr          $ra
    // 0x800A1B68: nop

    return;
    // 0x800A1B68: nop

;}
RECOMP_FUNC void ActorEvent_SetMessage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A7B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006A7B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006A7B8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006A7BC: lw          $t6, -0x7D64($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7D64);
    // 0x8006A7C0: beq         $t6, $zero, L_8006A7E8
    if (ctx->r14 == 0) {
        // 0x8006A7C4: nop
    
            goto L_8006A7E8;
    }
    // 0x8006A7C4: nop

    // 0x8006A7C8: mtc1        $a1, $f6
    ctx->f6.u32l = ctx->r5;
    // 0x8006A7CC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8006A7D0: lwc1        $f4, 0x7D68($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7D68);
    // 0x8006A7D4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8006A7D8: c.eq.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl == ctx->f8.fl;
    // 0x8006A7DC: nop

    // 0x8006A7E0: bc1tl       L_8006A7F4
    if (c1cs) {
        // 0x8006A7E4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8006A7F4;
    }
    goto skip_0;
    // 0x8006A7E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
L_8006A7E8:
    // 0x8006A7E8: jal         0x800BA808
    // 0x8006A7EC: nop

    Radio_PlayMessage(rdram, ctx);
        goto after_0;
    // 0x8006A7EC: nop

    after_0:
    // 0x8006A7F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8006A7F4:
    // 0x8006A7F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006A7F8: jr          $ra
    // 0x8006A7FC: nop

    return;
    // 0x8006A7FC: nop

;}
RECOMP_FUNC void Effect_Effect359_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007AA60: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8007AA64: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8007AA68: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8007AA6C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8007AA70: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8007AA74: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x8007AA78: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8007AA7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8007AA80: jal         0x800B8DD0
    // 0x8007AA84: addiu       $a1, $zero, 0x44
    ctx->r5 = ADD32(0, 0X44);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x8007AA84: addiu       $a1, $zero, 0x44
    ctx->r5 = ADD32(0, 0X44);
    after_0:
    // 0x8007AA88: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8007AA8C: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x8007AA90: lui         $at, 0x1F0A
    ctx->r1 = S32(0X1F0A << 16);
    // 0x8007AA94: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8007AA98: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8007AA9C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8007AAA0: lh          $t8, 0x44($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X44);
    // 0x8007AAA4: lui         $t3, 0xFB00
    ctx->r11 = S32(0XFB00 << 16);
    // 0x8007AAA8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8007AAAC: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x8007AAB0: or          $t1, $t9, $at
    ctx->r9 = ctx->r25 | ctx->r1;
    // 0x8007AAB4: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x8007AAB8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8007AABC: lui         $t4, 0x8D49
    ctx->r12 = S32(0X8D49 << 16);
    // 0x8007AAC0: ori         $t4, $t4, 0x500
    ctx->r12 = ctx->r12 | 0X500;
    // 0x8007AAC4: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x8007AAC8: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x8007AACC: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x8007AAD0: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8007AAD4: lwc1        $f0, 0x70($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X70);
    // 0x8007AAD8: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8007AADC: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8007AAE0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8007AAE4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8007AAE8: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8007AAEC: jal         0x80005C34
    // 0x8007AAF0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_1;
    // 0x8007AAF0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x8007AAF4: jal         0x80006EB8
    // 0x8007AAF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_2;
    // 0x8007AAF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8007AAFC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8007AB00: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x8007AB04: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x8007AB08: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8007AB0C: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8007AB10: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8007AB14: lbu         $t8, 0x4C($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X4C);
    // 0x8007AB18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8007AB1C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8007AB20: addu        $t1, $t1, $t9
    ctx->r9 = ADD32(ctx->r9, ctx->r25);
    // 0x8007AB24: lw          $t1, 0x178C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X178C);
    // 0x8007AB28: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x8007AB2C: lh          $t2, 0x48($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X48);
    // 0x8007AB30: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    // 0x8007AB34: jal         0x800B8DD0
    // 0x8007AB38: sb          $t2, 0x4C($s1)
    MEM_B(0X4C, ctx->r17) = ctx->r10;
    RCP_SetupDL(rdram, ctx);
        goto after_3;
    // 0x8007AB38: sb          $t2, 0x4C($s1)
    MEM_B(0X4C, ctx->r17) = ctx->r10;
    after_3:
    // 0x8007AB3C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8007AB40: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8007AB44: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8007AB48: jr          $ra
    // 0x8007AB4C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8007AB4C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void Play_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B832C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800B8330: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800B8334: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800B8338: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800B833C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800B8340: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800B8344: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800B8348: jal         0x800A6590
    // 0x800B834C: nop

    Play_UpdateFillScreen(rdram, ctx);
        goto after_0;
    // 0x800B834C: nop

    after_0:
    // 0x800B8350: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800B8354: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x800B8358: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x800B835C: addiu       $a2, $a2, 0x78B0
    ctx->r6 = ADD32(ctx->r6, 0X78B0);
    // 0x800B8360: addiu       $t0, $t0, 0x7920
    ctx->r8 = ADD32(ctx->r8, 0X7920);
    // 0x800B8364: addiu       $v0, $v0, 0x7914
    ctx->r2 = ADD32(ctx->r2, 0X7914);
    // 0x800B8368: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x800B836C: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
L_800B8370:
    // 0x800B8370: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x800B8374: addu        $v1, $a2, $a0
    ctx->r3 = ADD32(ctx->r6, ctx->r4);
    // 0x800B8378: blezl       $a1, L_800B83A0
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800B837C: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_800B83A0;
    }
    goto skip_0;
    // 0x800B837C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    skip_0:
    // 0x800B8380: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800B8384: addiu       $t6, $a1, -0x2
    ctx->r14 = ADD32(ctx->r5, -0X2);
    // 0x800B8388: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800B838C: addiu       $t8, $t7, -0x2
    ctx->r24 = ADD32(ctx->r15, -0X2);
    // 0x800B8390: bgtz        $t8, L_800B839C
    if (SIGNED(ctx->r24) > 0) {
        // 0x800B8394: sw          $t8, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r24;
            goto L_800B839C;
    }
    // 0x800B8394: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800B8398: sw          $a3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r7;
L_800B839C:
    // 0x800B839C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_800B83A0:
    // 0x800B83A0: sltu        $at, $v0, $t0
    ctx->r1 = ctx->r2 < ctx->r8 ? 1 : 0;
    // 0x800B83A4: bne         $at, $zero, L_800B8370
    if (ctx->r1 != 0) {
        // 0x800B83A8: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_800B8370;
    }
    // 0x800B83A8: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800B83AC: lui         $s4, 0x8017
    ctx->r20 = S32(0X8017 << 16);
    // 0x800B83B0: addiu       $s4, $s4, 0x78A8
    ctx->r20 = ADD32(ctx->r20, 0X78A8);
    // 0x800B83B4: lw          $t1, 0x0($s4)
    ctx->r9 = MEM_W(ctx->r20, 0X0);
    // 0x800B83B8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800B83BC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800B83C0: blez        $t1, L_800B840C
    if (SIGNED(ctx->r9) <= 0) {
        // 0x800B83C4: lui         $s3, 0x8018
        ctx->r19 = S32(0X8018 << 16);
            goto L_800B840C;
    }
    // 0x800B83C4: lui         $s3, 0x8018
    ctx->r19 = S32(0X8018 << 16);
    // 0x800B83C8: lui         $s2, 0x8017
    ctx->r18 = S32(0X8017 << 16);
    // 0x800B83CC: addiu       $s2, $s2, 0x78A0
    ctx->r18 = ADD32(ctx->r18, 0X78A0);
    // 0x800B83D0: addiu       $s3, $s3, -0x7D80
    ctx->r19 = ADD32(ctx->r19, -0X7D80);
    // 0x800B83D4: lw          $t3, 0x0($s3)
    ctx->r11 = MEM_W(ctx->r19, 0X0);
L_800B83D8:
    // 0x800B83D8: sw          $s1, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r17;
    // 0x800B83DC: addu        $t4, $t3, $s0
    ctx->r12 = ADD32(ctx->r11, ctx->r16);
    // 0x800B83E0: sw          $s1, 0x1C4($t4)
    MEM_W(0X1C4, ctx->r12) = ctx->r17;
    // 0x800B83E4: lw          $t5, 0x0($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X0);
    // 0x800B83E8: jal         0x800B48BC
    // 0x800B83EC: addu        $a0, $s0, $t5
    ctx->r4 = ADD32(ctx->r16, ctx->r13);
    Player_Update(rdram, ctx);
        goto after_1;
    // 0x800B83EC: addu        $a0, $s0, $t5
    ctx->r4 = ADD32(ctx->r16, ctx->r13);
    after_1:
    // 0x800B83F0: lw          $t6, 0x0($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X0);
    // 0x800B83F4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800B83F8: addiu       $s0, $s0, 0x4E0
    ctx->r16 = ADD32(ctx->r16, 0X4E0);
    // 0x800B83FC: slt         $at, $s1, $t6
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800B8400: bnel        $at, $zero, L_800B83D8
    if (ctx->r1 != 0) {
        // 0x800B8404: lw          $t3, 0x0($s3)
        ctx->r11 = MEM_W(ctx->r19, 0X0);
            goto L_800B83D8;
    }
    goto skip_1;
    // 0x800B8404: lw          $t3, 0x0($s3)
    ctx->r11 = MEM_W(ctx->r19, 0X0);
    skip_1:
    // 0x800B8408: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_800B840C:
    // 0x800B840C: lui         $s2, 0x8017
    ctx->r18 = S32(0X8017 << 16);
    // 0x800B8410: lui         $s3, 0x8018
    ctx->r19 = S32(0X8018 << 16);
    // 0x800B8414: addiu       $s3, $s3, -0x7D80
    ctx->r19 = ADD32(ctx->r19, -0X7D80);
    // 0x800B8418: jal         0x8006A3E8
    // 0x800B841C: addiu       $s2, $s2, 0x78A0
    ctx->r18 = ADD32(ctx->r18, 0X78A0);
    Object_Update(rdram, ctx);
        goto after_2;
    // 0x800B841C: addiu       $s2, $s2, 0x78A0
    ctx->r18 = ADD32(ctx->r18, 0X78A0);
    after_2:
    // 0x800B8420: jal         0x8003D9B8
    // 0x800B8424: nop

    PlayerShot_UpdateAll(rdram, ctx);
        goto after_3;
    // 0x800B8424: nop

    after_3:
    // 0x800B8428: jal         0x8007729C
    // 0x800B842C: nop

    BonusText_Update(rdram, ctx);
        goto after_4;
    // 0x800B842C: nop

    after_4:
    // 0x800B8430: lw          $t7, 0x0($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X0);
    // 0x800B8434: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800B8438: blez        $t7, L_800B8474
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800B843C: nop
    
            goto L_800B8474;
    }
    // 0x800B843C: nop

    // 0x800B8440: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
L_800B8444:
    // 0x800B8444: sw          $s1, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r17;
    // 0x800B8448: addu        $t1, $t9, $s0
    ctx->r9 = ADD32(ctx->r25, ctx->r16);
    // 0x800B844C: sw          $s1, 0x1C4($t1)
    MEM_W(0X1C4, ctx->r9) = ctx->r17;
    // 0x800B8450: lw          $t3, 0x0($s3)
    ctx->r11 = MEM_W(ctx->r19, 0X0);
    // 0x800B8454: jal         0x800B71E4
    // 0x800B8458: addu        $a0, $s0, $t3
    ctx->r4 = ADD32(ctx->r16, ctx->r11);
    Camera_Update(rdram, ctx);
        goto after_5;
    // 0x800B8458: addu        $a0, $s0, $t3
    ctx->r4 = ADD32(ctx->r16, ctx->r11);
    after_5:
    // 0x800B845C: lw          $t2, 0x0($s4)
    ctx->r10 = MEM_W(ctx->r20, 0X0);
    // 0x800B8460: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800B8464: addiu       $s0, $s0, 0x4E0
    ctx->r16 = ADD32(ctx->r16, 0X4E0);
    // 0x800B8468: slt         $at, $s1, $t2
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800B846C: bnel        $at, $zero, L_800B8444
    if (ctx->r1 != 0) {
        // 0x800B8470: lw          $t9, 0x0($s3)
        ctx->r25 = MEM_W(ctx->r19, 0X0);
            goto L_800B8444;
    }
    goto skip_2;
    // 0x800B8470: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    skip_2:
L_800B8474:
    // 0x800B8474: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x800B8478: addiu       $v1, $v1, -0x7B80
    ctx->r3 = ADD32(ctx->r3, -0X7B80);
    // 0x800B847C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800B8480: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800B8484: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x800B8488: addiu       $s0, $s0, -0x7B84
    ctx->r16 = ADD32(ctx->r16, -0X7B84);
    // 0x800B848C: beq         $v0, $zero, L_800B8504
    if (ctx->r2 == 0) {
        // 0x800B8490: swc1        $f4, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->f4.u32l;
            goto L_800B8504;
    }
    // 0x800B8490: swc1        $f4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f4.u32l;
    // 0x800B8494: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x800B8498: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800B849C: addiu       $t5, $v0, -0x1
    ctx->r13 = ADD32(ctx->r2, -0X1);
    // 0x800B84A0: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x800B84A4: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x800B84A8: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x800B84AC: cvt.s.w     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    ctx->f2.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800B84B0: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800B84B4: nop

    // 0x800B84B8: bc1f        L_800B84C4
    if (!c1cs) {
        // 0x800B84BC: nop
    
            goto L_800B84C4;
    }
    // 0x800B84BC: nop

    // 0x800B84C0: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_800B84C4:
    // 0x800B84C4: lw          $t6, 0x7DB0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7DB0);
    // 0x800B84C8: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x800B84CC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800B84D0: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x800B84D4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B84D8: lwc1        $f4, -0x7420($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7420);
    // 0x800B84DC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800B84E0: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    // 0x800B84E4: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800B84E8: nop

    // 0x800B84EC: mul.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800B84F0: jal         0x80023090
    // 0x800B84F4: nop

    __sinf_recomp(rdram, ctx);
        goto after_6;
    // 0x800B84F4: nop

    after_6:
    // 0x800B84F8: lwc1        $f2, 0x30($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800B84FC: mul.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800B8500: swc1        $f6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f6.u32l;
L_800B8504:
    // 0x800B8504: jal         0x800B79B0
    // 0x800B8508: nop

    Play_UpdateLevel(rdram, ctx);
        goto after_7;
    // 0x800B8508: nop

    after_7:
    // 0x800B850C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800B8510: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800B8514: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800B8518: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800B851C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800B8520: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800B8524: jr          $ra
    // 0x800B8528: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800B8528: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void AudioSeq_AudioListPopBack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800145FC: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80014600: bnel        $v1, $a0, L_80014614
    if (ctx->r3 != ctx->r4) {
        // 0x80014604: lw          $t6, 0x0($v1)
        ctx->r14 = MEM_W(ctx->r3, 0X0);
            goto L_80014614;
    }
    goto skip_0;
    // 0x80014604: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    skip_0:
    // 0x80014608: jr          $ra
    // 0x8001460C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8001460C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80014610: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
L_80014614:
    // 0x80014614: sw          $a0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r4;
    // 0x80014618: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8001461C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80014620: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x80014624: lw          $t8, 0x8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X8);
    // 0x80014628: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x8001462C: sw          $t9, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r25;
    // 0x80014630: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x80014634: jr          $ra
    // 0x80014638: nop

    return;
    // 0x80014638: nop

;}
RECOMP_FUNC void Effect_FireSmoke1_SpawnMoving(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007797C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80077980: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80077984: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80077988: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8007798C: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80077990: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80077994: addiu       $v0, $v0, 0x130
    ctx->r2 = ADD32(ctx->r2, 0X130);
    // 0x80077998: addiu       $a0, $a0, 0x3754
    ctx->r4 = ADD32(ctx->r4, 0X3754);
    // 0x8007799C: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
L_800779A0:
    // 0x800779A0: bnel        $t6, $zero, L_800779E4
    if (ctx->r14 != 0) {
        // 0x800779A4: addiu       $a0, $a0, -0x8C
        ctx->r4 = ADD32(ctx->r4, -0X8C);
            goto L_800779E4;
    }
    goto skip_0;
    // 0x800779A4: addiu       $a0, $a0, -0x8C
    ctx->r4 = ADD32(ctx->r4, -0X8C);
    skip_0:
    // 0x800779A8: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800779AC: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800779B0: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800779B4: lwc1        $f10, 0x40($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800779B8: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x800779BC: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x800779C0: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x800779C4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x800779C8: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x800779CC: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x800779D0: jal         0x800778C4
    // 0x800779D4: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    Effect_FireSmoke1_SetupMoving(rdram, ctx);
        goto after_0;
    // 0x800779D4: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    after_0:
    // 0x800779D8: b           L_800779F4
    // 0x800779DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800779F4;
    // 0x800779DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800779E0: addiu       $a0, $a0, -0x8C
    ctx->r4 = ADD32(ctx->r4, -0X8C);
L_800779E4:
    // 0x800779E4: sltu        $at, $a0, $v0
    ctx->r1 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x800779E8: beql        $at, $zero, L_800779A0
    if (ctx->r1 == 0) {
        // 0x800779EC: lbu         $t6, 0x0($a0)
        ctx->r14 = MEM_BU(ctx->r4, 0X0);
            goto L_800779A0;
    }
    goto skip_1;
    // 0x800779EC: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    skip_1:
    // 0x800779F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800779F4:
    // 0x800779F4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800779F8: jr          $ra
    // 0x800779FC: nop

    return;
    // 0x800779FC: nop

;}
RECOMP_FUNC void RCP_SetupDL_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B92C8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800B92CC: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x800B92D0: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800B92D4: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x800B92D8: addiu       $t8, $t8, 0x3558
    ctx->r24 = ADD32(ctx->r24, 0X3558);
    // 0x800B92DC: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800B92E0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800B92E4: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x800B92E8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800B92EC: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800B92F0: jr          $ra
    // 0x800B92F4: nop

    return;
    // 0x800B92F4: nop

;}
RECOMP_FUNC void RCP_SetupDL_50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BA610: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BA614: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x800BA618: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800BA61C: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x800BA620: addiu       $t8, $t8, 0x3FC0
    ctx->r24 = ADD32(ctx->r24, 0X3FC0);
    // 0x800BA624: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800BA628: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800BA62C: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x800BA630: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800BA634: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800BA638: jr          $ra
    // 0x800BA63C: nop

    return;
    // 0x800BA63C: nop

;}
RECOMP_FUNC void func_effect_80081A8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80081A8C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80081A90: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80081A94: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    // 0x80081A98: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    // 0x80081A9C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80081AA0: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80081AA4: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80081AA8: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80081AAC: beq         $t6, $at, L_80081ABC
    if (ctx->r14 == ctx->r1) {
        // 0x80081AB0: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_80081ABC;
    }
    // 0x80081AB0: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80081AB4: bne         $t6, $at, L_80081AC4
    if (ctx->r14 != ctx->r1) {
        // 0x80081AB8: nop
    
            goto L_80081AC4;
    }
    // 0x80081AB8: nop

L_80081ABC:
    // 0x80081ABC: jal         0x800815DC
    // 0x80081AC0: nop

    func_effect_800815DC(rdram, ctx);
        goto after_0;
    // 0x80081AC0: nop

    after_0:
L_80081AC4:
    // 0x80081AC4: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80081AC8: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80081ACC: addiu       $v0, $v0, 0x37E0
    ctx->r2 = ADD32(ctx->r2, 0X37E0);
    // 0x80081AD0: addiu       $a0, $a0, 0x130
    ctx->r4 = ADD32(ctx->r4, 0X130);
    // 0x80081AD4: lbu         $t7, 0x0($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X0);
L_80081AD8:
    // 0x80081AD8: bnel        $t7, $zero, L_80081B0C
    if (ctx->r15 != 0) {
        // 0x80081ADC: addiu       $a0, $a0, 0x8C
        ctx->r4 = ADD32(ctx->r4, 0X8C);
            goto L_80081B0C;
    }
    goto skip_0;
    // 0x80081ADC: addiu       $a0, $a0, 0x8C
    ctx->r4 = ADD32(ctx->r4, 0X8C);
    skip_0:
    // 0x80081AE0: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80081AE4: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80081AE8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80081AEC: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80081AF0: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80081AF4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80081AF8: jal         0x8008165C
    // 0x80081AFC: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    func_effect_8008165C(rdram, ctx);
        goto after_1;
    // 0x80081AFC: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    after_1:
    // 0x80081B00: b           L_80081B18
    // 0x80081B04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80081B18;
    // 0x80081B04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80081B08: addiu       $a0, $a0, 0x8C
    ctx->r4 = ADD32(ctx->r4, 0X8C);
L_80081B0C:
    // 0x80081B0C: bnel        $a0, $v0, L_80081AD8
    if (ctx->r4 != ctx->r2) {
        // 0x80081B10: lbu         $t7, 0x0($a0)
        ctx->r15 = MEM_BU(ctx->r4, 0X0);
            goto L_80081AD8;
    }
    goto skip_1;
    // 0x80081B10: lbu         $t7, 0x0($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X0);
    skip_1:
    // 0x80081B14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80081B18:
    // 0x80081B18: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80081B1C: jr          $ra
    // 0x80081B20: nop

    return;
    // 0x80081B20: nop

;}
RECOMP_FUNC void Display_OnFootCharacter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800526B8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800526BC: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800526C0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800526C4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800526C8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800526CC: jal         0x80005708
    // 0x800526D0: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Push(rdram, ctx);
        goto after_0;
    // 0x800526D0: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_0:
    // 0x800526D4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800526D8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800526DC: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x800526E0: addiu       $v1, $v1, -0x4438
    ctx->r3 = ADD32(ctx->r3, -0X4438);
    // 0x800526E4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800526E8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800526EC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800526F0: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800526F4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800526F8: jal         0x80005C34
    // 0x800526FC: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_1;
    // 0x800526FC: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    after_1:
    // 0x80052700: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80052704: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80052708: addiu       $v1, $v1, -0x4438
    ctx->r3 = ADD32(ctx->r3, -0X4438);
    // 0x8005270C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80052710: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80052714: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80052718: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8005271C: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x80052720: jal         0x80005B00
    // 0x80052724: lui         $a2, 0x420C
    ctx->r6 = S32(0X420C << 16);
    Matrix_Translate(rdram, ctx);
        goto after_2;
    // 0x80052724: lui         $a2, 0x420C
    ctx->r6 = S32(0X420C << 16);
    after_2:
    // 0x80052728: lw          $v0, 0x1C4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C4);
    // 0x8005272C: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80052730: addiu       $v1, $v1, -0x4438
    ctx->r3 = ADD32(ctx->r3, -0X4438);
    // 0x80052734: beq         $v0, $zero, L_80052768
    if (ctx->r2 == 0) {
        // 0x80052738: addiu       $a0, $zero, 0x5
        ctx->r4 = ADD32(0, 0X5);
            goto L_80052768;
    }
    // 0x80052738: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x8005273C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80052740: beq         $v0, $at, L_800527A0
    if (ctx->r2 == ctx->r1) {
        // 0x80052744: addiu       $a0, $zero, 0x5
        ctx->r4 = ADD32(0, 0X5);
            goto L_800527A0;
    }
    // 0x80052744: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x80052748: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8005274C: beq         $v0, $at, L_800527D8
    if (ctx->r2 == ctx->r1) {
        // 0x80052750: addiu       $a0, $zero, 0x5
        ctx->r4 = ADD32(0, 0X5);
            goto L_800527D8;
    }
    // 0x80052750: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x80052754: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80052758: beq         $v0, $at, L_80052810
    if (ctx->r2 == ctx->r1) {
        // 0x8005275C: addiu       $a0, $zero, 0x5
        ctx->r4 = ADD32(0, 0X5);
            goto L_80052810;
    }
    // 0x8005275C: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x80052760: b           L_80052840
    // 0x80052764: nop

        goto L_80052840;
    // 0x80052764: nop

L_80052768:
    // 0x80052768: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8005276C: lui         $t8, 0x8005
    ctx->r24 = S32(0X8005 << 16);
    // 0x80052770: addiu       $t8, $t8, 0x23A8
    ctx->r24 = ADD32(ctx->r24, 0X23A8);
    // 0x80052774: lui         $a1, 0x302
    ctx->r5 = S32(0X302 << 16);
    // 0x80052778: lui         $a3, 0x8005
    ctx->r7 = S32(0X8005 << 16);
    // 0x8005277C: addiu       $a3, $a3, 0x20FC
    ctx->r7 = ADD32(ctx->r7, 0X20FC);
    // 0x80052780: addiu       $a1, $a1, -0x2DA8
    ctx->r5 = ADD32(ctx->r5, -0X2DA8);
    // 0x80052784: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80052788: addiu       $a2, $s0, 0x2F8
    ctx->r6 = ADD32(ctx->r16, 0X2F8);
    // 0x8005278C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80052790: jal         0x8009A72C
    // 0x80052794: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    Animation_DrawSkeleton(rdram, ctx);
        goto after_3;
    // 0x80052794: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    after_3:
    // 0x80052798: b           L_80052840
    // 0x8005279C: nop

        goto L_80052840;
    // 0x8005279C: nop

L_800527A0:
    // 0x800527A0: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x800527A4: lui         $t0, 0x8005
    ctx->r8 = S32(0X8005 << 16);
    // 0x800527A8: addiu       $t0, $t0, 0x2420
    ctx->r8 = ADD32(ctx->r8, 0X2420);
    // 0x800527AC: lui         $a1, 0x302
    ctx->r5 = S32(0X302 << 16);
    // 0x800527B0: lui         $a3, 0x8005
    ctx->r7 = S32(0X8005 << 16);
    // 0x800527B4: addiu       $a3, $a3, 0x20FC
    ctx->r7 = ADD32(ctx->r7, 0X20FC);
    // 0x800527B8: addiu       $a1, $a1, -0x246C
    ctx->r5 = ADD32(ctx->r5, -0X246C);
    // 0x800527BC: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x800527C0: addiu       $a2, $s0, 0x2F8
    ctx->r6 = ADD32(ctx->r16, 0X2F8);
    // 0x800527C4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800527C8: jal         0x8009A72C
    // 0x800527CC: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    Animation_DrawSkeleton(rdram, ctx);
        goto after_4;
    // 0x800527CC: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    after_4:
    // 0x800527D0: b           L_80052840
    // 0x800527D4: nop

        goto L_80052840;
    // 0x800527D4: nop

L_800527D8:
    // 0x800527D8: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x800527DC: lui         $t2, 0x8005
    ctx->r10 = S32(0X8005 << 16);
    // 0x800527E0: addiu       $t2, $t2, 0x2498
    ctx->r10 = ADD32(ctx->r10, 0X2498);
    // 0x800527E4: lui         $a1, 0x302
    ctx->r5 = S32(0X302 << 16);
    // 0x800527E8: lui         $a3, 0x8005
    ctx->r7 = S32(0X8005 << 16);
    // 0x800527EC: addiu       $a3, $a3, 0x20FC
    ctx->r7 = ADD32(ctx->r7, 0X20FC);
    // 0x800527F0: addiu       $a1, $a1, -0x1C18
    ctx->r5 = ADD32(ctx->r5, -0X1C18);
    // 0x800527F4: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800527F8: addiu       $a2, $s0, 0x2F8
    ctx->r6 = ADD32(ctx->r16, 0X2F8);
    // 0x800527FC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80052800: jal         0x8009A72C
    // 0x80052804: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    Animation_DrawSkeleton(rdram, ctx);
        goto after_5;
    // 0x80052804: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    after_5:
    // 0x80052808: b           L_80052840
    // 0x8005280C: nop

        goto L_80052840;
    // 0x8005280C: nop

L_80052810:
    // 0x80052810: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x80052814: lui         $t4, 0x8005
    ctx->r12 = S32(0X8005 << 16);
    // 0x80052818: addiu       $t4, $t4, 0x250C
    ctx->r12 = ADD32(ctx->r12, 0X250C);
    // 0x8005281C: lui         $a1, 0x302
    ctx->r5 = S32(0X302 << 16);
    // 0x80052820: lui         $a3, 0x8005
    ctx->r7 = S32(0X8005 << 16);
    // 0x80052824: addiu       $a3, $a3, 0x20FC
    ctx->r7 = ADD32(ctx->r7, 0X20FC);
    // 0x80052828: addiu       $a1, $a1, -0x39EC
    ctx->r5 = ADD32(ctx->r5, -0X39EC);
    // 0x8005282C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80052830: addiu       $a2, $s0, 0x2F8
    ctx->r6 = ADD32(ctx->r16, 0X2F8);
    // 0x80052834: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80052838: jal         0x8009A72C
    // 0x8005283C: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    Animation_DrawSkeleton(rdram, ctx);
        goto after_6;
    // 0x8005283C: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    after_6:
L_80052840:
    // 0x80052840: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80052844: jal         0x80005740
    // 0x80052848: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Pop(rdram, ctx);
        goto after_7;
    // 0x80052848: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_7:
    // 0x8005284C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80052850: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x80052854: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80052858: lui         $t7, 0xB700
    ctx->r15 = S32(0XB700 << 16);
    // 0x8005285C: addiu       $t8, $zero, 0x2000
    ctx->r24 = ADD32(0, 0X2000);
    // 0x80052860: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80052864: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80052868: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8005286C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80052870: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80052874: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80052878: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8005287C: jr          $ra
    // 0x80052880: nop

    return;
    // 0x80052880: nop

;}
RECOMP_FUNC void Audio_PlayVoiceWithoutBGM(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001AD00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001AD04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001AD08: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8001AD0C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8001AD10: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8001AD14: sb          $t6, 0x7394($at)
    MEM_B(0X7394, ctx->r1) = ctx->r14;
    // 0x8001AD18: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001AD1C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8001AD20: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    // 0x8001AD24: jal         0x800185A0
    // 0x8001AD28: addiu       $a3, $zero, 0xF
    ctx->r7 = ADD32(0, 0XF);
    Audio_SetSequenceFade(rdram, ctx);
        goto after_0;
    // 0x8001AD28: addiu       $a3, $zero, 0xF
    ctx->r7 = ADD32(0, 0XF);
    after_0:
    // 0x8001AD2C: jal         0x8001ACDC
    // 0x8001AD30: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    Audio_PlayVoice(rdram, ctx);
        goto after_1;
    // 0x8001AD30: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8001AD34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001AD38: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001AD3C: jr          $ra
    // 0x8001AD40: nop

    return;
    // 0x8001AD40: nop

;}
RECOMP_FUNC void HUD_RadarMark_Missile_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800898F0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800898F4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800898F8: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800898FC: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x80089900: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80089904: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80089908: jal         0x800B8DD0
    // 0x8008990C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x8008990C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80089910: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80089914: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80089918: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x8008991C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80089920: lui         $t8, 0xFFD0
    ctx->r24 = S32(0XFFD0 << 16);
    // 0x80089924: ori         $t8, $t8, 0x50FF
    ctx->r24 = ctx->r24 | 0X50FF;
    // 0x80089928: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8008992C: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80089930: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80089934: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80089938: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8008993C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80089940: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80089944: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80089948: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8008994C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80089950: jal         0x80005C34
    // 0x80089954: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_1;
    // 0x80089954: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x80089958: jal         0x80006EB8
    // 0x8008995C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_2;
    // 0x8008995C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80089960: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80089964: lui         $t2, 0x600
    ctx->r10 = S32(0X600 << 16);
    // 0x80089968: addiu       $t2, $t2, 0x4570
    ctx->r10 = ADD32(ctx->r10, 0X4570);
    // 0x8008996C: addiu       $t0, $v1, 0x8
    ctx->r8 = ADD32(ctx->r3, 0X8);
    // 0x80089970: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x80089974: lui         $t1, 0x600
    ctx->r9 = S32(0X600 << 16);
    // 0x80089978: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x8008997C: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x80089980: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80089984: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80089988: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8008998C: jr          $ra
    // 0x80089990: nop

    return;
    // 0x80089990: nop

;}
RECOMP_FUNC void Cutscene_UTurn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004CCC0: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8004CCC4: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8004CCC8: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8004CCCC: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8004CCD0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8004CCD4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8004CCD8: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8004CCDC: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8004CCE0: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8004CCE4: addiu       $a0, $s0, 0x130
    ctx->r4 = ADD32(ctx->r16, 0X130);
    // 0x8004CCE8: lui         $a3, 0x4170
    ctx->r7 = S32(0X4170 << 16);
    // 0x8004CCEC: jal         0x8009BC2C
    // 0x8004CCF0: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_0;
    // 0x8004CCF0: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_0:
    // 0x8004CCF4: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8004CCF8: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8004CCFC: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8004CD00: addiu       $a0, $s0, 0xEC
    ctx->r4 = ADD32(ctx->r16, 0XEC);
    // 0x8004CD04: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x8004CD08: jal         0x8009BC2C
    // 0x8004CD0C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_1;
    // 0x8004CD0C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_1:
    // 0x8004CD10: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8004CD14: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8004CD18: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8004CD1C: addiu       $a0, $s0, 0xE8
    ctx->r4 = ADD32(ctx->r16, 0XE8);
    // 0x8004CD20: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x8004CD24: jal         0x8009BC2C
    // 0x8004CD28: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_2;
    // 0x8004CD28: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_2:
    // 0x8004CD2C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8004CD30: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8004CD34: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8004CD38: addiu       $a0, $s0, 0xE4
    ctx->r4 = ADD32(ctx->r16, 0XE4);
    // 0x8004CD3C: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x8004CD40: jal         0x8009BC2C
    // 0x8004CD44: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_3;
    // 0x8004CD44: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_3:
    // 0x8004CD48: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8004CD4C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8004CD50: lwc1        $f4, 0x78($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X78);
    // 0x8004CD54: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x8004CD58: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8004CD5C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8004CD60: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x8004CD64: addiu       $a0, $s0, 0x44
    ctx->r4 = ADD32(ctx->r16, 0X44);
    // 0x8004CD68: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x8004CD6C: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8004CD70: jal         0x8009BC2C
    // 0x8004CD74: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_4;
    // 0x8004CD74: nop

    after_4:
    // 0x8004CD78: lwc1        $f10, 0xD0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XD0);
    // 0x8004CD7C: swc1        $f10, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f10.u32l;
    // 0x8004CD80: lwc1        $f14, 0x138($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X138);
    // 0x8004CD84: jal         0x80005100
    // 0x8004CD88: lwc1        $f12, 0x74($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X74);
    Math_Atan2F(rdram, ctx);
        goto after_5;
    // 0x8004CD88: lwc1        $f12, 0x74($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X74);
    after_5:
    // 0x8004CD8C: jal         0x8009F768
    // 0x8004CD90: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    Math_RadToDeg(rdram, ctx);
        goto after_6;
    // 0x8004CD90: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_6:
    // 0x8004CD94: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8004CD98: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8004CD9C: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    // 0x8004CDA0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8004CDA4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8004CDA8: lwc1        $f18, 0x2BC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X2BC);
    // 0x8004CDAC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8004CDB0: sw          $v1, 0x2B4($s0)
    MEM_W(0X2B4, ctx->r16) = ctx->r3;
    // 0x8004CDB4: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8004CDB8: swc1        $f6, 0x2BC($s0)
    MEM_W(0X2BC, ctx->r16) = ctx->f6.u32l;
    // 0x8004CDBC: lwc1        $f8, 0x2BC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2BC);
    // 0x8004CDC0: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x8004CDC4: nop

    // 0x8004CDC8: bc1fl       L_8004CDD8
    if (!c1cs) {
        // 0x8004CDCC: lw          $v0, 0x1D0($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X1D0);
            goto L_8004CDD8;
    }
    goto skip_0;
    // 0x8004CDCC: lw          $v0, 0x1D0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1D0);
    skip_0:
    // 0x8004CDD0: swc1        $f2, 0x2BC($s0)
    MEM_W(0X2BC, ctx->r16) = ctx->f2.u32l;
    // 0x8004CDD4: lw          $v0, 0x1D0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1D0);
L_8004CDD8:
    // 0x8004CDD8: beql        $v0, $zero, L_8004CE14
    if (ctx->r2 == 0) {
        // 0x8004CDDC: lw          $t6, 0x19C($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X19C);
            goto L_8004CE14;
    }
    goto skip_1;
    // 0x8004CDDC: lw          $t6, 0x19C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X19C);
    skip_1:
    // 0x8004CDE0: beq         $v0, $v1, L_8004CE60
    if (ctx->r2 == ctx->r3) {
        // 0x8004CDE4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8004CE60;
    }
    // 0x8004CDE4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8004CDE8: beq         $v0, $at, L_8004CEF8
    if (ctx->r2 == ctx->r1) {
        // 0x8004CDEC: addiu       $a0, $s0, 0x4A0
        ctx->r4 = ADD32(ctx->r16, 0X4A0);
            goto L_8004CEF8;
    }
    // 0x8004CDEC: addiu       $a0, $s0, 0x4A0
    ctx->r4 = ADD32(ctx->r16, 0X4A0);
    // 0x8004CDF0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8004CDF4: beq         $v0, $at, L_8004D0B4
    if (ctx->r2 == ctx->r1) {
        // 0x8004CDF8: addiu       $a0, $s0, 0x12C
        ctx->r4 = ADD32(ctx->r16, 0X12C);
            goto L_8004D0B4;
    }
    // 0x8004CDF8: addiu       $a0, $s0, 0x12C
    ctx->r4 = ADD32(ctx->r16, 0X12C);
    // 0x8004CDFC: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8004CE00: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8004CE04: lwc1        $f12, 0x78($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X78);
    // 0x8004CE08: b           L_8004D264
    // 0x8004CE0C: lwc1        $f2, 0x4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X4);
        goto L_8004D264;
    // 0x8004CE0C: lwc1        $f2, 0x4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8004CE10: lw          $t6, 0x19C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X19C);
L_8004CE14:
    // 0x8004CE14: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8004CE18: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8004CE1C: beq         $t6, $zero, L_8004CE30
    if (ctx->r14 == 0) {
        // 0x8004CE20: addiu       $t8, $zero, 0x1E
        ctx->r24 = ADD32(0, 0X1E);
            goto L_8004CE30;
    }
    // 0x8004CE20: addiu       $t8, $zero, 0x1E
    ctx->r24 = ADD32(0, 0X1E);
    // 0x8004CE24: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x8004CE28: b           L_8004CE34
    // 0x8004CE2C: sw          $t7, 0x1F8($s0)
    MEM_W(0X1F8, ctx->r16) = ctx->r15;
        goto L_8004CE34;
    // 0x8004CE2C: sw          $t7, 0x1F8($s0)
    MEM_W(0X1F8, ctx->r16) = ctx->r15;
L_8004CE30:
    // 0x8004CE30: sw          $t8, 0x1F8($s0)
    MEM_W(0X1F8, ctx->r16) = ctx->r24;
L_8004CE34:
    // 0x8004CE34: lwc1        $f0, 0x4D8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4D8);
    // 0x8004CE38: sw          $v1, 0x1D0($s0)
    MEM_W(0X1D0, ctx->r16) = ctx->r3;
    // 0x8004CE3C: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8004CE40: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x8004CE44: nop

    // 0x8004CE48: bc1fl       L_8004CE64
    if (!c1cs) {
        // 0x8004CE4C: lw          $t9, 0x1F8($s0)
        ctx->r25 = MEM_W(ctx->r16, 0X1F8);
            goto L_8004CE64;
    }
    goto skip_2;
    // 0x8004CE4C: lw          $t9, 0x1F8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1F8);
    skip_2:
    // 0x8004CE50: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8004CE54: nop

    // 0x8004CE58: sub.s       $f10, $f0, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8004CE5C: swc1        $f10, 0x4D8($s0)
    MEM_W(0X4D8, ctx->r16) = ctx->f10.u32l;
L_8004CE60:
    // 0x8004CE60: lw          $t9, 0x1F8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1F8);
L_8004CE64:
    // 0x8004CE64: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004CE68: bnel        $t9, $zero, L_8004CE98
    if (ctx->r25 != 0) {
        // 0x8004CE6C: lwc1        $f18, 0xC0($s0)
        ctx->f18.u32l = MEM_W(ctx->r16, 0XC0);
            goto L_8004CE98;
    }
    goto skip_3;
    // 0x8004CE6C: lwc1        $f18, 0xC0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC0);
    skip_3:
    // 0x8004CE70: lw          $t1, 0x19C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X19C);
    // 0x8004CE74: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x8004CE78: sw          $t0, 0x1D0($s0)
    MEM_W(0X1D0, ctx->r16) = ctx->r8;
    // 0x8004CE7C: beq         $t1, $zero, L_8004CE90
    if (ctx->r9 == 0) {
        // 0x8004CE80: addiu       $t3, $zero, 0x50
        ctx->r11 = ADD32(0, 0X50);
            goto L_8004CE90;
    }
    // 0x8004CE80: addiu       $t3, $zero, 0x50
    ctx->r11 = ADD32(0, 0X50);
    // 0x8004CE84: addiu       $t2, $zero, 0x3C
    ctx->r10 = ADD32(0, 0X3C);
    // 0x8004CE88: b           L_8004CE94
    // 0x8004CE8C: sw          $t2, 0x1F8($s0)
    MEM_W(0X1F8, ctx->r16) = ctx->r10;
        goto L_8004CE94;
    // 0x8004CE8C: sw          $t2, 0x1F8($s0)
    MEM_W(0X1F8, ctx->r16) = ctx->r10;
L_8004CE90:
    // 0x8004CE90: sw          $t3, 0x1F8($s0)
    MEM_W(0X1F8, ctx->r16) = ctx->r11;
L_8004CE94:
    // 0x8004CE94: lwc1        $f18, 0xC0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC0);
L_8004CE98:
    // 0x8004CE98: lwc1        $f4, 0x5A3C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5A3C);
    // 0x8004CE9C: lwc1        $f8, 0x40($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8004CEA0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004CEA4: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8004CEA8: lwc1        $f18, 0xC8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x8004CEAC: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8004CEB0: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8004CEB4: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8004CEB8: addiu       $a0, $s0, 0x12C
    ctx->r4 = ADD32(ctx->r16, 0X12C);
    // 0x8004CEBC: lui         $a3, 0x4170
    ctx->r7 = S32(0X4170 << 16);
    // 0x8004CEC0: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8004CEC4: lwc1        $f6, 0x48($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X48);
    // 0x8004CEC8: swc1        $f10, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f10.u32l;
    // 0x8004CECC: lwc1        $f4, 0x5A40($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5A40);
    // 0x8004CED0: mul.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8004CED4: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8004CED8: swc1        $f10, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f10.u32l;
    // 0x8004CEDC: jal         0x8009BC2C
    // 0x8004CEE0: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_7;
    // 0x8004CEE0: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_7:
    // 0x8004CEE4: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8004CEE8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8004CEEC: lwc1        $f12, 0x78($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X78);
    // 0x8004CEF0: b           L_8004D264
    // 0x8004CEF4: lwc1        $f2, 0x4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X4);
        goto L_8004D264;
    // 0x8004CEF4: lwc1        $f2, 0x4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X4);
L_8004CEF8:
    // 0x8004CEF8: lui         $at, 0x430C
    ctx->r1 = S32(0X430C << 16);
    // 0x8004CEFC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8004CF00: lwc1        $f4, 0x4D8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4D8);
    // 0x8004CF04: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x8004CF08: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8004CF0C: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x8004CF10: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x8004CF14: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x8004CF18: bc1fl       L_8004CF2C
    if (!c1cs) {
        // 0x8004CF1C: mtc1        $at, $f6
        ctx->f6.u32l = ctx->r1;
            goto L_8004CF2C;
    }
    goto skip_4;
    // 0x8004CF1C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    skip_4:
    // 0x8004CF20: b           L_8004CF34
    // 0x8004CF24: swc1        $f20, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f20.u32l;
        goto L_8004CF34;
    // 0x8004CF24: swc1        $f20, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f20.u32l;
    // 0x8004CF28: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
L_8004CF2C:
    // 0x8004CF2C: nop

    // 0x8004CF30: swc1        $f6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f6.u32l;
L_8004CF34:
    // 0x8004CF34: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    // 0x8004CF38: jal         0x8009BC2C
    // 0x8004CF3C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_8;
    // 0x8004CF3C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_8:
    // 0x8004CF40: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x8004CF44: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x8004CF48: addiu       $a0, $s0, 0x4A4
    ctx->r4 = ADD32(ctx->r16, 0X4A4);
    // 0x8004CF4C: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    // 0x8004CF50: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x8004CF54: jal         0x8009BC2C
    // 0x8004CF58: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_9;
    // 0x8004CF58: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_9:
    // 0x8004CF5C: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x8004CF60: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x8004CF64: addiu       $a0, $s0, 0x4A8
    ctx->r4 = ADD32(ctx->r16, 0X4A8);
    // 0x8004CF68: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    // 0x8004CF6C: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x8004CF70: jal         0x8009BC2C
    // 0x8004CF74: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_10;
    // 0x8004CF74: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_10:
    // 0x8004CF78: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x8004CF7C: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x8004CF80: addiu       $a0, $s0, 0x4AC
    ctx->r4 = ADD32(ctx->r16, 0X4AC);
    // 0x8004CF84: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    // 0x8004CF88: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x8004CF8C: jal         0x8009BC2C
    // 0x8004CF90: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_11;
    // 0x8004CF90: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_11:
    // 0x8004CF94: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8004CF98: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8004CF9C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8004CFA0: addiu       $a0, $s0, 0x12C
    ctx->r4 = ADD32(ctx->r16, 0X12C);
    // 0x8004CFA4: lui         $a3, 0x4170
    ctx->r7 = S32(0X4170 << 16);
    // 0x8004CFA8: jal         0x8009BC2C
    // 0x8004CFAC: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_12;
    // 0x8004CFAC: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_12:
    // 0x8004CFB0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004CFB4: lwc1        $f8, 0x5A44($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5A44);
    // 0x8004CFB8: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8004CFBC: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8004CFC0: addiu       $a0, $s0, 0x4D8
    ctx->r4 = ADD32(ctx->r16, 0X4D8);
    // 0x8004CFC4: lui         $a1, 0x433E
    ctx->r5 = S32(0X433E << 16);
    // 0x8004CFC8: lui         $a3, 0x40C0
    ctx->r7 = S32(0X40C0 << 16);
    // 0x8004CFCC: jal         0x8009BC2C
    // 0x8004CFD0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_13;
    // 0x8004CFD0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_13:
    // 0x8004CFD4: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8004CFD8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8004CFDC: lwc1        $f10, 0x4D8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4D8);
    // 0x8004CFE0: lui         $a1, 0x900
    ctx->r5 = S32(0X900 << 16);
    // 0x8004CFE4: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x8004CFE8: c.lt.s      $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f14.fl < ctx->f10.fl;
    // 0x8004CFEC: ori         $a1, $a1, 0x2
    ctx->r5 = ctx->r5 | 0X2;
    // 0x8004CFF0: addiu       $a0, $s0, 0x460
    ctx->r4 = ADD32(ctx->r16, 0X460);
    // 0x8004CFF4: bc1f        L_8004D094
    if (!c1cs) {
        // 0x8004CFF8: nop
    
            goto L_8004D094;
    }
    // 0x8004CFF8: nop

    // 0x8004CFFC: lwc1        $f18, 0x114($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X114);
    // 0x8004D000: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8004D004: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8004D008: add.s       $f4, $f18, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f14.fl;
    // 0x8004D00C: lui         $at, 0xC334
    ctx->r1 = S32(0XC334 << 16);
    // 0x8004D010: swc1        $f4, 0x114($s0)
    MEM_W(0X114, ctx->r16) = ctx->f4.u32l;
    // 0x8004D014: lwc1        $f0, 0x114($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X114);
    // 0x8004D018: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8004D01C: nop

    // 0x8004D020: bc1fl       L_8004D038
    if (!c1cs) {
        // 0x8004D024: lwc1        $f8, 0x4D8($s0)
        ctx->f8.u32l = MEM_W(ctx->r16, 0X4D8);
            goto L_8004D038;
    }
    goto skip_5;
    // 0x8004D024: lwc1        $f8, 0x4D8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4D8);
    skip_5:
    // 0x8004D028: sub.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8004D02C: swc1        $f6, 0x114($s0)
    MEM_W(0X114, ctx->r16) = ctx->f6.u32l;
    // 0x8004D030: lwc1        $f0, 0x114($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X114);
    // 0x8004D034: lwc1        $f8, 0x4D8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4D8);
L_8004D038:
    // 0x8004D038: sub.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f14.fl;
    // 0x8004D03C: sub.s       $f18, $f2, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f2.fl - ctx->f10.fl;
    // 0x8004D040: swc1        $f18, 0x4D8($s0)
    MEM_W(0X4D8, ctx->r16) = ctx->f18.u32l;
    // 0x8004D044: lwc1        $f4, 0x5C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8004D048: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x8004D04C: c.lt.s      $f6, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f6.fl < ctx->f14.fl;
    // 0x8004D050: nop

    // 0x8004D054: bc1fl       L_8004D068
    if (!c1cs) {
        // 0x8004D058: mtc1        $at, $f8
        ctx->f8.u32l = ctx->r1;
            goto L_8004D068;
    }
    goto skip_6;
    // 0x8004D058: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    skip_6:
    // 0x8004D05C: b           L_8004D070
    // 0x8004D060: swc1        $f14, 0x12C($s0)
    MEM_W(0X12C, ctx->r16) = ctx->f14.u32l;
        goto L_8004D070;
    // 0x8004D060: swc1        $f14, 0x12C($s0)
    MEM_W(0X12C, ctx->r16) = ctx->f14.u32l;
    // 0x8004D064: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
L_8004D068:
    // 0x8004D068: nop

    // 0x8004D06C: swc1        $f8, 0x12C($s0)
    MEM_W(0X12C, ctx->r16) = ctx->f8.u32l;
L_8004D070:
    // 0x8004D070: sw          $t4, 0x1D0($s0)
    MEM_W(0X1D0, ctx->r16) = ctx->r12;
    // 0x8004D074: jal         0x800A5FA0
    // 0x8004D078: lw          $a2, 0x1C4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X1C4);
    Player_PlaySfx(rdram, ctx);
        goto after_14;
    // 0x8004D078: lw          $a2, 0x1C4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X1C4);
    after_14:
    // 0x8004D07C: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x8004D080: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8004D084: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8004D088: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8004D08C: swc1        $f0, 0x194($s0)
    MEM_W(0X194, ctx->r16) = ctx->f0.u32l;
    // 0x8004D090: swc1        $f0, 0x190($s0)
    MEM_W(0X190, ctx->r16) = ctx->f0.u32l;
L_8004D094:
    // 0x8004D094: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004D098: lwc1        $f18, 0x5A48($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X5A48);
    // 0x8004D09C: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8004D0A0: lwc1        $f12, 0x78($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X78);
    // 0x8004D0A4: sub.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x8004D0A8: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x8004D0AC: b           L_8004D264
    // 0x8004D0B0: lwc1        $f2, 0x4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X4);
        goto L_8004D264;
    // 0x8004D0B0: lwc1        $f2, 0x4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X4);
L_8004D0B4:
    // 0x8004D0B4: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8004D0B8: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x8004D0BC: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8004D0C0: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x8004D0C4: jal         0x8009BC2C
    // 0x8004D0C8: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_15;
    // 0x8004D0C8: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_15:
    // 0x8004D0CC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004D0D0: lwc1        $f12, 0x5A4C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X5A4C);
    // 0x8004D0D4: lwc1        $f6, 0x12C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X12C);
    // 0x8004D0D8: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x8004D0DC: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x8004D0E0: mul.s       $f2, $f6, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x8004D0E4: addiu       $a0, $s0, 0x4A0
    ctx->r4 = ADD32(ctx->r16, 0X4A0);
    // 0x8004D0E8: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x8004D0EC: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x8004D0F0: jal         0x8009BC2C
    // 0x8004D0F4: swc1        $f2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f2.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_16;
    // 0x8004D0F4: swc1        $f2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f2.u32l;
    after_16:
    // 0x8004D0F8: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x8004D0FC: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x8004D100: addiu       $a0, $s0, 0x4A4
    ctx->r4 = ADD32(ctx->r16, 0X4A4);
    // 0x8004D104: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    // 0x8004D108: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x8004D10C: jal         0x8009BC2C
    // 0x8004D110: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_17;
    // 0x8004D110: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_17:
    // 0x8004D114: lwc1        $f2, 0x60($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8004D118: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x8004D11C: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x8004D120: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x8004D124: addiu       $a0, $s0, 0x4A8
    ctx->r4 = ADD32(ctx->r16, 0X4A8);
    // 0x8004D128: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x8004D12C: swc1        $f2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f2.u32l;
    // 0x8004D130: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x8004D134: jal         0x8009BC2C
    // 0x8004D138: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_18;
    // 0x8004D138: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_18:
    // 0x8004D13C: lwc1        $f2, 0x38($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8004D140: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x8004D144: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x8004D148: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x8004D14C: addiu       $a0, $s0, 0x4AC
    ctx->r4 = ADD32(ctx->r16, 0X4AC);
    // 0x8004D150: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x8004D154: jal         0x8009BC2C
    // 0x8004D158: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_19;
    // 0x8004D158: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_19:
    // 0x8004D15C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8004D160: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8004D164: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004D168: lwc1        $f16, 0x5A50($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X5A50);
    // 0x8004D16C: lwc1        $f2, 0xC0($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XC0);
    // 0x8004D170: lwc1        $f12, 0xC8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x8004D174: lwc1        $f8, 0x40($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8004D178: mul.s       $f10, $f2, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x8004D17C: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x8004D180: lw          $v0, 0x19C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X19C);
    // 0x8004D184: mul.s       $f6, $f12, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f16.fl);
    // 0x8004D188: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004D18C: addiu       $a0, $s0, 0x114
    ctx->r4 = ADD32(ctx->r16, 0X114);
    // 0x8004D190: swc1        $f14, 0x190($s0)
    MEM_W(0X190, ctx->r16) = ctx->f14.u32l;
    // 0x8004D194: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8004D198: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8004D19C: swc1        $f18, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f18.u32l;
    // 0x8004D1A0: beq         $v0, $zero, L_8004D1D0
    if (ctx->r2 == 0) {
        // 0x8004D1A4: swc1        $f8, 0x48($s0)
        MEM_W(0X48, ctx->r16) = ctx->f8.u32l;
            goto L_8004D1D0;
    }
    // 0x8004D1A4: swc1        $f8, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f8.u32l;
    // 0x8004D1A8: lwc1        $f0, 0x5A54($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5A54);
    // 0x8004D1AC: lwc1        $f10, 0x40($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8004D1B0: lwc1        $f6, 0x48($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X48);
    // 0x8004D1B4: mul.s       $f18, $f12, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x8004D1B8: lw          $v0, 0x19C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X19C);
    // 0x8004D1BC: mul.s       $f8, $f2, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8004D1C0: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8004D1C4: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8004D1C8: swc1        $f4, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f4.u32l;
    // 0x8004D1CC: swc1        $f10, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f10.u32l;
L_8004D1D0:
    // 0x8004D1D0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004D1D4: bne         $v0, $zero, L_8004D1F8
    if (ctx->r2 != 0) {
        // 0x8004D1D8: lwc1        $f0, 0x5A58($at)
        ctx->f0.u32l = MEM_W(ctx->r1, 0X5A58);
            goto L_8004D1F8;
    }
    // 0x8004D1D8: lwc1        $f0, 0x5A58($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5A58);
    // 0x8004D1DC: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x8004D1E0: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x8004D1E4: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x8004D1E8: jal         0x8009BD38
    // 0x8004D1EC: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_20;
    // 0x8004D1EC: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_20:
    // 0x8004D1F0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004D1F4: lwc1        $f0, 0x5A5C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5A5C);
L_8004D1F8:
    // 0x8004D1F8: lwc1        $f18, 0x78($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X78);
    // 0x8004D1FC: lwc1        $f4, 0xA0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XA0);
    // 0x8004D200: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8004D204: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8004D208: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x8004D20C: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x8004D210: bc1fl       L_8004D23C
    if (!c1cs) {
        // 0x8004D214: lwc1        $f8, 0x4($s0)
        ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
            goto L_8004D23C;
    }
    goto skip_7;
    // 0x8004D214: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    skip_7:
    // 0x8004D218: lwc1        $f2, 0x4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8004D21C: c.lt.s      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.fl < ctx->f20.fl;
    // 0x8004D220: nop

    // 0x8004D224: bc1fl       L_8004D248
    if (!c1cs) {
        // 0x8004D228: lw          $t5, 0x1F8($s0)
        ctx->r13 = MEM_W(ctx->r16, 0X1F8);
            goto L_8004D248;
    }
    goto skip_8;
    // 0x8004D228: lw          $t5, 0x1F8($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X1F8);
    skip_8:
    // 0x8004D22C: add.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8004D230: b           L_8004D244
    // 0x8004D234: swc1        $f6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f6.u32l;
        goto L_8004D244;
    // 0x8004D234: swc1        $f6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f6.u32l;
    // 0x8004D238: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
L_8004D23C:
    // 0x8004D23C: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x8004D240: swc1        $f10, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f10.u32l;
L_8004D244:
    // 0x8004D244: lw          $t5, 0x1F8($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X1F8);
L_8004D248:
    // 0x8004D248: bnel        $t5, $zero, L_8004D260
    if (ctx->r13 != 0) {
        // 0x8004D24C: lwc1        $f12, 0x78($s0)
        ctx->f12.u32l = MEM_W(ctx->r16, 0X78);
            goto L_8004D260;
    }
    goto skip_9;
    // 0x8004D24C: lwc1        $f12, 0x78($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X78);
    skip_9:
    // 0x8004D250: sw          $t6, 0x1C8($s0)
    MEM_W(0X1C8, ctx->r16) = ctx->r14;
    // 0x8004D254: swc1        $f20, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f20.u32l;
    // 0x8004D258: swc1        $f20, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f20.u32l;
    // 0x8004D25C: lwc1        $f12, 0x78($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X78);
L_8004D260:
    // 0x8004D260: lwc1        $f2, 0x4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X4);
L_8004D264:
    // 0x8004D264: add.s       $f18, $f12, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f12.fl + ctx->f2.fl;
    // 0x8004D268: lwc1        $f4, 0x50($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X50);
    // 0x8004D26C: lwc1        $f8, 0xEC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x8004D270: lwc1        $f10, 0x12C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X12C);
    // 0x8004D274: swc1        $f18, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f18.u32l;
    // 0x8004D278: add.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x8004D27C: lwc1        $f4, 0x130($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X130);
    // 0x8004D280: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004D284: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8004D288: lwc1        $f10, 0xE8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XE8);
    // 0x8004D28C: lwc1        $f8, 0x114($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X114);
    // 0x8004D290: swc1        $f6, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f6.u32l;
    // 0x8004D294: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8004D298: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8004D29C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8004D2A0: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8004D2A4: swc1        $f6, 0xF8($s0)
    MEM_W(0XF8, ctx->r16) = ctx->f6.u32l;
    // 0x8004D2A8: lwc1        $f6, 0x5A60($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5A60);
    // 0x8004D2AC: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8004D2B0: add.s       $f4, $f18, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f14.fl;
    // 0x8004D2B4: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8004D2B8: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8004D2BC: jal         0x80005E90
    // 0x8004D2C0: nop

    Matrix_RotateY(rdram, ctx);
        goto after_21;
    // 0x8004D2C0: nop

    after_21:
    // 0x8004D2C4: lwc1        $f10, 0x120($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X120);
    // 0x8004D2C8: lwc1        $f18, 0xE4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XE4);
    // 0x8004D2CC: lwc1        $f6, 0x4D8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4D8);
    // 0x8004D2D0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004D2D4: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8004D2D8: lwc1        $f10, 0x5A64($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X5A64);
    // 0x8004D2DC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8004D2E0: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8004D2E4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8004D2E8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8004D2EC: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8004D2F0: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x8004D2F4: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8004D2F8: jal         0x80005D44
    // 0x8004D2FC: nop

    Matrix_RotateX(rdram, ctx);
        goto after_22;
    // 0x8004D2FC: nop

    after_22:
    // 0x8004D300: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8004D304: swc1        $f20, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f20.u32l;
    // 0x8004D308: swc1        $f20, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f20.u32l;
    // 0x8004D30C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8004D310: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x8004D314: jal         0x80006A20
    // 0x8004D318: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_23;
    // 0x8004D318: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    after_23:
    // 0x8004D31C: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8004D320: lwc1        $f18, 0x74($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X74);
    // 0x8004D324: lwc1        $f0, 0xA4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XA4);
    // 0x8004D328: swc1        $f6, 0xC0($s0)
    MEM_W(0XC0, ctx->r16) = ctx->f6.u32l;
    // 0x8004D32C: lwc1        $f8, 0x4C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8004D330: lwc1        $f4, 0xC0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC0);
    // 0x8004D334: swc1        $f8, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f8.u32l;
    // 0x8004D338: lwc1        $f10, 0x48($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8004D33C: lwc1        $f8, 0x78($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X78);
    // 0x8004D340: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8004D344: swc1        $f10, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f10.u32l;
    // 0x8004D348: lwc1        $f10, 0xC4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x8004D34C: swc1        $f6, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f6.u32l;
    // 0x8004D350: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8004D354: swc1        $f18, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f18.u32l;
    // 0x8004D358: lwc1        $f4, 0x78($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X78);
    // 0x8004D35C: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8004D360: nop

    // 0x8004D364: bc1fl       L_8004D378
    if (!c1cs) {
        // 0x8004D368: lwc1        $f6, 0x7C($s0)
        ctx->f6.u32l = MEM_W(ctx->r16, 0X7C);
            goto L_8004D378;
    }
    goto skip_10;
    // 0x8004D368: lwc1        $f6, 0x7C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X7C);
    skip_10:
    // 0x8004D36C: swc1        $f0, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f0.u32l;
    // 0x8004D370: swc1        $f20, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f20.u32l;
    // 0x8004D374: lwc1        $f6, 0x7C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X7C);
L_8004D378:
    // 0x8004D378: lwc1        $f8, 0xC8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x8004D37C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8004D380: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8004D384: swc1        $f10, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->f10.u32l;
    // 0x8004D388: lwc1        $f18, 0x7C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x8004D38C: jal         0x800B2574
    // 0x8004D390: swc1        $f18, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->f18.u32l;
    Player_ArwingBoost(rdram, ctx);
        goto after_24;
    // 0x8004D390: swc1        $f18, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->f18.u32l;
    after_24:
    // 0x8004D394: jal         0x800B2130
    // 0x8004D398: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_UpdateArwingRoll(rdram, ctx);
        goto after_25;
    // 0x8004D398: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_25:
    // 0x8004D39C: jal         0x800AD7F0
    // 0x8004D3A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_Shoot(rdram, ctx);
        goto after_26;
    // 0x8004D3A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_26:
    // 0x8004D3A4: jal         0x800AA800
    // 0x8004D3A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_FloorCheck(rdram, ctx);
        goto after_27;
    // 0x8004D3A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_27:
    // 0x8004D3AC: jal         0x800A46A0
    // 0x8004D3B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_DamageEffects(rdram, ctx);
        goto after_28;
    // 0x8004D3B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_28:
    // 0x8004D3B4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8004D3B8: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8004D3BC: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8004D3C0: jr          $ra
    // 0x8004D3C4: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x8004D3C4: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_versus_800BD720(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BD720: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800BD724: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800BD728: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800BD72C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800BD730: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BD734: lui         $a1, 0x300
    ctx->r5 = S32(0X300 << 16);
    // 0x800BD738: addiu       $a1, $a1, 0x13E0
    ctx->r5 = ADD32(ctx->r5, 0X13E0);
    // 0x800BD73C: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x800BD740: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x800BD744: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    // 0x800BD748: swc1        $f12, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f12.u32l;
    // 0x800BD74C: swc1        $f14, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f14.u32l;
    // 0x800BD750: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x800BD754: jal         0x8009D994
    // 0x800BD758: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_0;
    // 0x800BD758: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x800BD75C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800BD760: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800BD764: jr          $ra
    // 0x800BD768: nop

    return;
    // 0x800BD768: nop

;}
RECOMP_FUNC void func_pause_800A3E00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A3E00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A3E04: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x800A3E08: addiu       $a2, $a2, 0x7868
    ctx->r6 = ADD32(ctx->r6, 0X7868);
    // 0x800A3E0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A3E10: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x800A3E14: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A3E18: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x800A3E1C: beq         $v0, $zero, L_800A3E48
    if (ctx->r2 == 0) {
        // 0x800A3E20: nop
    
            goto L_800A3E48;
    }
    // 0x800A3E20: nop

    // 0x800A3E24: beq         $v0, $at, L_800A3E60
    if (ctx->r2 == ctx->r1) {
        // 0x800A3E28: addiu       $a3, $zero, 0x2
        ctx->r7 = ADD32(0, 0X2);
            goto L_800A3E60;
    }
    // 0x800A3E28: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x800A3E2C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x800A3E30: beq         $v0, $a3, L_800A3ED0
    if (ctx->r2 == ctx->r7) {
        // 0x800A3E34: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800A3ED0;
    }
    // 0x800A3E34: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800A3E38: beq         $v0, $at, L_800A3F28
    if (ctx->r2 == ctx->r1) {
        // 0x800A3E3C: lui         $t4, 0x8017
        ctx->r12 = S32(0X8017 << 16);
            goto L_800A3F28;
    }
    // 0x800A3E3C: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x800A3E40: b           L_800A3F40
    // 0x800A3E44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800A3F40;
    // 0x800A3E44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A3E48:
    // 0x800A3E48: lw          $t6, 0x783C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X783C);
    // 0x800A3E4C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800A3E50: bnel        $t6, $zero, L_800A3F40
    if (ctx->r14 != 0) {
        // 0x800A3E54: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800A3F40;
    }
    goto skip_0;
    // 0x800A3E54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800A3E58: b           L_800A3F3C
    // 0x800A3E5C: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
        goto L_800A3F3C;
    // 0x800A3E5C: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
L_800A3E60:
    // 0x800A3E60: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800A3E64: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800A3E68: sw          $a3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r7;
    // 0x800A3E6C: addiu       $t8, $zero, 0x7
    ctx->r24 = ADD32(0, 0X7);
    // 0x800A3E70: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A3E74: addiu       $v0, $v0, 0x79B8
    ctx->r2 = ADD32(ctx->r2, 0X79B8);
    // 0x800A3E78: sw          $t8, 0x7898($at)
    MEM_W(0X7898, ctx->r1) = ctx->r24;
    // 0x800A3E7C: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x800A3E80: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800A3E84: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800A3E88: addiu       $v1, $v1, 0x79A0
    ctx->r3 = ADD32(ctx->r3, 0X79A0);
    // 0x800A3E8C: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
    // 0x800A3E90: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800A3E94: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x800A3E98: addiu       $a0, $a0, 0x7988
    ctx->r4 = ADD32(ctx->r4, 0X7988);
    // 0x800A3E9C: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
    // 0x800A3EA0: lwc1        $f10, 0x0($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800A3EA4: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x800A3EA8: addiu       $a1, $a1, 0x7980
    ctx->r5 = ADD32(ctx->r5, 0X7980);
    // 0x800A3EAC: swc1        $f10, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f10.u32l;
    // 0x800A3EB0: lwc1        $f16, 0x0($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800A3EB4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A3EB8: swc1        $f16, 0x7978($at)
    MEM_W(0X7978, ctx->r1) = ctx->f16.u32l;
    // 0x800A3EBC: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x800A3EC0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800A3EC4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A3EC8: b           L_800A3F3C
    // 0x800A3ECC: swc1        $f18, 0x79C0($at)
    MEM_W(0X79C0, ctx->r1) = ctx->f18.u32l;
        goto L_800A3F3C;
    // 0x800A3ECC: swc1        $f18, 0x79C0($at)
    MEM_W(0X79C0, ctx->r1) = ctx->f18.u32l;
L_800A3ED0:
    // 0x800A3ED0: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800A3ED4: addiu       $v0, $v0, -0x2768
    ctx->r2 = ADD32(ctx->r2, -0X2768);
    // 0x800A3ED8: lhu         $t9, 0x0($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X0);
    // 0x800A3EDC: andi        $t0, $t9, 0x1000
    ctx->r8 = ctx->r25 & 0X1000;
    // 0x800A3EE0: bne         $t0, $zero, L_800A3EF8
    if (ctx->r8 != 0) {
        // 0x800A3EE4: nop
    
            goto L_800A3EF8;
    }
    // 0x800A3EE4: nop

    // 0x800A3EE8: lhu         $t1, 0x6($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X6);
    // 0x800A3EEC: andi        $t2, $t1, 0x1000
    ctx->r10 = ctx->r9 & 0X1000;
    // 0x800A3EF0: beql        $t2, $zero, L_800A3F40
    if (ctx->r10 == 0) {
        // 0x800A3EF4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800A3F40;
    }
    goto skip_1;
    // 0x800A3EF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
L_800A3EF8:
    // 0x800A3EF8: jal         0x8001D638
    // 0x800A3EFC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    Audio_PlayPauseSfx(rdram, ctx);
        goto after_0;
    // 0x800A3EFC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x800A3F00: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x800A3F04: addiu       $a2, $a2, 0x7868
    ctx->r6 = ADD32(ctx->r6, 0X7868);
    // 0x800A3F08: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x800A3F0C: sw          $t3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r11;
    // 0x800A3F10: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A3F14: jal         0x800A5844
    // 0x800A3F18: sw          $zero, 0x7898($at)
    MEM_W(0X7898, ctx->r1) = 0;
    Play_Setup(rdram, ctx);
        goto after_1;
    // 0x800A3F18: sw          $zero, 0x7898($at)
    MEM_W(0X7898, ctx->r1) = 0;
    after_1:
    // 0x800A3F1C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A3F20: b           L_800A3F3C
    // 0x800A3F24: sw          $zero, 0x783C($at)
    MEM_W(0X783C, ctx->r1) = 0;
        goto L_800A3F3C;
    // 0x800A3F24: sw          $zero, 0x783C($at)
    MEM_W(0X783C, ctx->r1) = 0;
L_800A3F28:
    // 0x800A3F28: lw          $t4, 0x783C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X783C);
    // 0x800A3F2C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A3F30: bnel        $t4, $zero, L_800A3F40
    if (ctx->r12 != 0) {
        // 0x800A3F34: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800A3F40;
    }
    goto skip_2;
    // 0x800A3F34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x800A3F38: sw          $a3, 0x7854($at)
    MEM_W(0X7854, ctx->r1) = ctx->r7;
L_800A3F3C:
    // 0x800A3F3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A3F40:
    // 0x800A3F40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A3F44: jr          $ra
    // 0x800A3F48: nop

    return;
    // 0x800A3F48: nop

;}
RECOMP_FUNC void __ltruncf(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001FEE8: trunc.w.s   $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    ctx->f4.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x8001FEEC: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x8001FEF0: jr          $ra
    // 0x8001FEF4: nop

    return;
    // 0x8001FEF4: nop

;}
RECOMP_FUNC void ActorAllRange_SpawnSupplies(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002FEF0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8002FEF4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8002FEF8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8002FEFC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8002FF00: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x8002FF04: lw          $t6, 0x1690($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1690);
    // 0x8002FF08: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x8002FF0C: beq         $t6, $zero, L_8002FF74
    if (ctx->r14 == 0) {
        // 0x8002FF10: nop
    
            goto L_8002FF74;
    }
    // 0x8002FF10: nop

    // 0x8002FF14: lw          $t7, 0x7AF8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7AF8);
    // 0x8002FF18: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8002FF1C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8002FF20: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8002FF24: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x8002FF28: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8002FF2C: lhu         $t9, -0x2768($t9)
    ctx->r25 = MEM_HU(ctx->r25, -0X2768);
    // 0x8002FF30: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x8002FF34: beq         $t0, $zero, L_8002FF74
    if (ctx->r8 == 0) {
        // 0x8002FF38: nop
    
            goto L_8002FF74;
    }
    // 0x8002FF38: nop

    // 0x8002FF3C: jal         0x8001AF40
    // 0x8002FF40: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    Audio_SetUnkVoiceParam(rdram, ctx);
        goto after_0;
    // 0x8002FF40: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8002FF44: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002FF48: sw          $zero, -0x70($at)
    MEM_W(-0X70, ctx->r1) = 0;
    // 0x8002FF4C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8002FF50: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8002FF54: sw          $zero, 0x1690($at)
    MEM_W(0X1690, ctx->r1) = 0;
    // 0x8002FF58: addiu       $a0, $a0, 0x3AAC
    ctx->r4 = ADD32(ctx->r4, 0X3AAC);
    // 0x8002FF5C: jal         0x800BA808
    // 0x8002FF60: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    Radio_PlayMessage(rdram, ctx);
        goto after_1;
    // 0x8002FF60: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    after_1:
    // 0x8002FF64: lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // 0x8002FF68: addiu       $v1, $v1, -0x700
    ctx->r3 = ADD32(ctx->r3, -0X700);
    // 0x8002FF6C: addiu       $t1, $zero, 0xA0
    ctx->r9 = ADD32(0, 0XA0);
    // 0x8002FF70: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
L_8002FF74:
    // 0x8002FF74: lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // 0x8002FF78: addiu       $v1, $v1, -0x700
    ctx->r3 = ADD32(ctx->r3, -0X700);
    // 0x8002FF7C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002FF80: beq         $v0, $zero, L_80030074
    if (ctx->r2 == 0) {
        // 0x8002FF84: addiu       $t2, $v0, -0x1
        ctx->r10 = ADD32(ctx->r2, -0X1);
            goto L_80030074;
    }
    // 0x8002FF84: addiu       $t2, $v0, -0x1
    ctx->r10 = ADD32(ctx->r2, -0X1);
    // 0x8002FF88: bne         $t2, $zero, L_80030074
    if (ctx->r10 != 0) {
        // 0x8002FF8C: sw          $t2, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r10;
            goto L_80030074;
    }
    // 0x8002FF8C: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x8002FF90: lui         $s0, 0x8016
    ctx->r16 = S32(0X8016 << 16);
    // 0x8002FF94: addiu       $s0, $s0, 0x7AF0
    ctx->r16 = ADD32(ctx->r16, 0X7AF0);
    // 0x8002FF98: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    // 0x8002FF9C: addiu       $v1, $zero, 0x3C
    ctx->r3 = ADD32(0, 0X3C);
L_8002FFA0:
    // 0x8002FFA0: lbu         $t4, 0x0($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X0);
    // 0x8002FFA4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8002FFA8: bne         $t4, $zero, L_8003006C
    if (ctx->r12 != 0) {
        // 0x8002FFAC: nop
    
            goto L_8003006C;
    }
    // 0x8002FFAC: nop

    // 0x8002FFB0: jal         0x800613C4
    // 0x8002FFB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Actor_Initialize(rdram, ctx);
        goto after_2;
    // 0x8002FFB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8002FFB8: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8002FFBC: addiu       $t6, $zero, 0x123
    ctx->r14 = ADD32(0, 0X123);
    // 0x8002FFC0: sb          $t5, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r13;
    // 0x8002FFC4: sh          $t6, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r14;
    // 0x8002FFC8: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8002FFCC: lw          $t7, -0x7DCC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7DCC);
    // 0x8002FFD0: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    // 0x8002FFD4: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8002FFD8: bne         $t7, $at, L_80030030
    if (ctx->r15 != ctx->r1) {
        // 0x8002FFDC: addiu       $a3, $a3, 0x5D34
        ctx->r7 = ADD32(ctx->r7, 0X5D34);
            goto L_80030030;
    }
    // 0x8002FFDC: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8002FFE0: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8002FFE4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8002FFE8: lui         $at, 0xC3FA
    ctx->r1 = S32(0XC3FA << 16);
    // 0x8002FFEC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8002FFF0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8002FFF4: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x8002FFF8: addiu       $t8, $t8, 0x5D3C
    ctx->r24 = ADD32(ctx->r24, 0X5D3C);
    // 0x8002FFFC: lui         $a0, 0x900
    ctx->r4 = S32(0X900 << 16);
    // 0x80030000: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x80030004: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x80030008: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    // 0x8003000C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80030010: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80030014: ori         $a0, $a0, 0x2
    ctx->r4 = ctx->r4 | 0X2;
    // 0x80030018: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x8003001C: jal         0x80019218
    // 0x80030020: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Audio_PlaySfx(rdram, ctx);
        goto after_3;
    // 0x80030020: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x80030024: addiu       $t9, $zero, 0x32
    ctx->r25 = ADD32(0, 0X32);
    // 0x80030028: b           L_80030058
    // 0x8003002C: sh          $t9, 0xC2($s0)
    MEM_H(0XC2, ctx->r16) = ctx->r25;
        goto L_80030058;
    // 0x8003002C: sh          $t9, 0xC2($s0)
    MEM_H(0XC2, ctx->r16) = ctx->r25;
L_80030030:
    // 0x80030030: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80030034: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80030038: addiu       $t0, $zero, 0x32
    ctx->r8 = ADD32(0, 0X32);
    // 0x8003003C: swc1        $f10, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f10.u32l;
    // 0x80030040: lwc1        $f16, 0x4EA4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X4EA4);
    // 0x80030044: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80030048: swc1        $f16, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f16.u32l;
    // 0x8003004C: lwc1        $f18, 0x4EA8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X4EA8);
    // 0x80030050: sh          $t0, 0xC2($s0)
    MEM_H(0XC2, ctx->r16) = ctx->r8;
    // 0x80030054: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
L_80030058:
    // 0x80030058: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x8003005C: jal         0x800612B8
    // 0x80030060: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    Object_SetInfo(rdram, ctx);
        goto after_4;
    // 0x80030060: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    after_4:
    // 0x80030064: b           L_80030074
    // 0x80030068: nop

        goto L_80030074;
    // 0x80030068: nop

L_8003006C:
    // 0x8003006C: bne         $v0, $v1, L_8002FFA0
    if (ctx->r2 != ctx->r3) {
        // 0x80030070: addiu       $s0, $s0, 0x2F4
        ctx->r16 = ADD32(ctx->r16, 0X2F4);
            goto L_8002FFA0;
    }
    // 0x80030070: addiu       $s0, $s0, 0x2F4
    ctx->r16 = ADD32(ctx->r16, 0X2F4);
L_80030074:
    // 0x80030074: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80030078: lw          $v0, -0x7D80($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D80);
    // 0x8003007C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80030080: addiu       $v1, $zero, 0x3C
    ctx->r3 = ADD32(0, 0X3C);
    // 0x80030084: lw          $t1, 0x1C8($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X1C8);
    // 0x80030088: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x8003008C: bnel        $t1, $at, L_800300FC
    if (ctx->r9 != ctx->r1) {
        // 0x80030090: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800300FC;
    }
    goto skip_0;
    // 0x80030090: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80030094: lw          $t2, -0x6F0($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X6F0);
    // 0x80030098: lui         $s0, 0x8016
    ctx->r16 = S32(0X8016 << 16);
    // 0x8003009C: addiu       $s0, $s0, -0x6F4
    ctx->r16 = ADD32(ctx->r16, -0X6F4);
    // 0x800300A0: bnel        $t2, $zero, L_800300FC
    if (ctx->r10 != 0) {
        // 0x800300A4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800300FC;
    }
    goto skip_1;
    // 0x800300A4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x800300A8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800300AC: beq         $a0, $zero, L_800300B8
    if (ctx->r4 == 0) {
        // 0x800300B0: addiu       $t3, $a0, -0x1
        ctx->r11 = ADD32(ctx->r4, -0X1);
            goto L_800300B8;
    }
    // 0x800300B0: addiu       $t3, $a0, -0x1
    ctx->r11 = ADD32(ctx->r4, -0X1);
    // 0x800300B4: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
L_800300B8:
    // 0x800300B8: lw          $t4, 0x264($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X264);
    // 0x800300BC: slti        $at, $t4, 0x40
    ctx->r1 = SIGNED(ctx->r12) < 0X40 ? 1 : 0;
    // 0x800300C0: bne         $at, $zero, L_800300E4
    if (ctx->r1 != 0) {
        // 0x800300C4: nop
    
            goto L_800300E4;
    }
    // 0x800300C4: nop

    // 0x800300C8: jal         0x8002FE74
    // 0x800300CC: nop

    AllRange_SupplyEvent(rdram, ctx);
        goto after_5;
    // 0x800300CC: nop

    after_5:
    // 0x800300D0: bne         $v0, $zero, L_800300E4
    if (ctx->r2 != 0) {
        // 0x800300D4: addiu       $v1, $zero, 0x3C
        ctx->r3 = ADD32(0, 0X3C);
            goto L_800300E4;
    }
    // 0x800300D4: addiu       $v1, $zero, 0x3C
    ctx->r3 = ADD32(0, 0X3C);
    // 0x800300D8: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x800300DC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800300E0: bne         $t5, $at, L_800300F8
    if (ctx->r13 != ctx->r1) {
        // 0x800300E4: lui         $at, 0x8016
        ctx->r1 = S32(0X8016 << 16);
            goto L_800300F8;
    }
L_800300E4:
    // 0x800300E4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800300E8: sw          $v1, 0x1690($at)
    MEM_W(0X1690, ctx->r1) = ctx->r3;
    // 0x800300EC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800300F0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800300F4: sw          $t6, -0x6F0($at)
    MEM_W(-0X6F0, ctx->r1) = ctx->r14;
L_800300F8:
    // 0x800300F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800300FC:
    // 0x800300FC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80030100: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80030104: jr          $ra
    // 0x80030108: nop

    return;
    // 0x80030108: nop

;}
RECOMP_FUNC void func_tank_800443DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800443DC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800443E0: sw          $s2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r18;
    // 0x800443E4: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800443E8: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800443EC: sw          $s5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r21;
    // 0x800443F0: sw          $s4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r20;
    // 0x800443F4: sw          $s3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r19;
    // 0x800443F8: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x800443FC: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x80044400: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80044404: lui         $at, 0x44FA
    ctx->r1 = S32(0X44FA << 16);
    // 0x80044408: lui         $s0, 0x8016
    ctx->r16 = S32(0X8016 << 16);
    // 0x8004440C: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80044410: addiu       $s0, $s0, 0x1B00
    ctx->r16 = ADD32(ctx->r16, 0X1B00);
    // 0x80044414: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80044418: addiu       $s5, $zero, 0x32
    ctx->r21 = ADD32(0, 0X32);
    // 0x8004441C: addiu       $s4, $zero, 0x3A
    ctx->r20 = ADD32(0, 0X3A);
    // 0x80044420: addiu       $s3, $zero, 0x2
    ctx->r19 = ADD32(0, 0X2);
L_80044424:
    // 0x80044424: lbu         $t6, 0x0($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X0);
    // 0x80044428: bnel        $s3, $t6, L_8004448C
    if (ctx->r19 != ctx->r14) {
        // 0x8004442C: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8004448C;
    }
    goto skip_0;
    // 0x8004442C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x80044430: lhu         $t7, 0x2($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X2);
    // 0x80044434: bnel        $s4, $t7, L_8004448C
    if (ctx->r20 != ctx->r15) {
        // 0x80044438: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8004448C;
    }
    goto skip_1;
    // 0x80044438: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_1:
    // 0x8004443C: lwc1        $f4, 0x138($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X138);
    // 0x80044440: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80044444: sub.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f20.fl;
    // 0x80044448: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x8004444C: nop

    // 0x80044450: bc1fl       L_8004448C
    if (!c1cs) {
        // 0x80044454: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8004448C;
    }
    goto skip_2;
    // 0x80044454: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_2:
    // 0x80044458: lw          $a1, 0x28($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X28);
    // 0x8004445C: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    // 0x80044460: lw          $a3, 0x8($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X8);
    // 0x80044464: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x80044468: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8004446C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80044470: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x80044474: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80044478: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x8004447C: lwc1        $f16, 0x18($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80044480: jal         0x800441C8
    // 0x80044484: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    func_tank_800441C8(rdram, ctx);
        goto after_0;
    // 0x80044484: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    after_0:
    // 0x80044488: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8004448C:
    // 0x8004448C: bne         $s1, $s5, L_80044424
    if (ctx->r17 != ctx->r21) {
        // 0x80044490: addiu       $s0, $s0, 0x80
        ctx->r16 = ADD32(ctx->r16, 0X80);
            goto L_80044424;
    }
    // 0x80044490: addiu       $s0, $s0, 0x80
    ctx->r16 = ADD32(ctx->r16, 0X80);
    // 0x80044494: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80044498: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8004449C: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x800444A0: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x800444A4: lw          $s2, 0x34($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X34);
    // 0x800444A8: lw          $s3, 0x38($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X38);
    // 0x800444AC: lw          $s4, 0x3C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X3C);
    // 0x800444B0: lw          $s5, 0x40($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X40);
    // 0x800444B4: jr          $ra
    // 0x800444B8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x800444B8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_radio_800BAAE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BAAE8: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800BAAEC: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x800BAAF0: addiu       $v1, $v1, -0x78BC
    ctx->r3 = ADD32(ctx->r3, -0X78BC);
    // 0x800BAAF4: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800BAAF8: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x800BAAFC: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x800BAB00: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x800BAB04: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x800BAB08: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800BAB0C: lw          $v0, -0x7D5C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D5C);
    // 0x800BAB10: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800BAB14: slti        $at, $v0, 0x138
    ctx->r1 = SIGNED(ctx->r2) < 0X138 ? 1 : 0;
    // 0x800BAB18: bne         $at, $zero, L_800BAB54
    if (ctx->r1 != 0) {
        // 0x800BAB1C: addiu       $at, $zero, 0x15E
        ctx->r1 = ADD32(0, 0X15E);
            goto L_800BAB54;
    }
    // 0x800BAB1C: addiu       $at, $zero, 0x15E
    ctx->r1 = ADD32(0, 0X15E);
    // 0x800BAB20: beq         $v0, $at, L_800BB034
    if (ctx->r2 == ctx->r1) {
        // 0x800BAB24: lui         $t1, 0x600
        ctx->r9 = S32(0X600 << 16);
            goto L_800BB034;
    }
    // 0x800BAB24: lui         $t1, 0x600
    ctx->r9 = S32(0X600 << 16);
    // 0x800BAB28: addiu       $at, $zero, 0x15F
    ctx->r1 = ADD32(0, 0X15F);
    // 0x800BAB2C: beq         $v0, $at, L_800BB040
    if (ctx->r2 == ctx->r1) {
        // 0x800BAB30: lui         $t2, 0x600
        ctx->r10 = S32(0X600 << 16);
            goto L_800BB040;
    }
    // 0x800BAB30: lui         $t2, 0x600
    ctx->r10 = S32(0X600 << 16);
    // 0x800BAB34: addiu       $at, $zero, 0x190
    ctx->r1 = ADD32(0, 0X190);
    // 0x800BAB38: beq         $v0, $at, L_800BAC04
    if (ctx->r2 == ctx->r1) {
        // 0x800BAB3C: lui         $t1, 0x100
        ctx->r9 = S32(0X100 << 16);
            goto L_800BAC04;
    }
    // 0x800BAB3C: lui         $t1, 0x100
    ctx->r9 = S32(0X100 << 16);
    // 0x800BAB40: addiu       $at, $zero, 0x191
    ctx->r1 = ADD32(0, 0X191);
    // 0x800BAB44: beq         $v0, $at, L_800BAC10
    if (ctx->r2 == ctx->r1) {
        // 0x800BAB48: lui         $t2, 0x100
        ctx->r10 = S32(0X100 << 16);
            goto L_800BAC10;
    }
    // 0x800BAB48: lui         $t2, 0x100
    ctx->r10 = S32(0X100 << 16);
    // 0x800BAB4C: b           L_800BB0CC
    // 0x800BAB50: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
        goto L_800BB0CC;
    // 0x800BAB50: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
L_800BAB54:
    // 0x800BAB54: slti        $at, $v0, 0x12E
    ctx->r1 = SIGNED(ctx->r2) < 0X12E ? 1 : 0;
    // 0x800BAB58: bne         $at, $zero, L_800BAB7C
    if (ctx->r1 != 0) {
        // 0x800BAB5C: addiu       $at, $zero, 0x136
        ctx->r1 = ADD32(0, 0X136);
            goto L_800BAB7C;
    }
    // 0x800BAB5C: addiu       $at, $zero, 0x136
    ctx->r1 = ADD32(0, 0X136);
    // 0x800BAB60: beq         $v0, $at, L_800BB01C
    if (ctx->r2 == ctx->r1) {
        // 0x800BAB64: lui         $t9, 0xE01
        ctx->r25 = S32(0XE01 << 16);
            goto L_800BB01C;
    }
    // 0x800BAB64: lui         $t9, 0xE01
    ctx->r25 = S32(0XE01 << 16);
    // 0x800BAB68: addiu       $at, $zero, 0x137
    ctx->r1 = ADD32(0, 0X137);
    // 0x800BAB6C: beq         $v0, $at, L_800BB028
    if (ctx->r2 == ctx->r1) {
        // 0x800BAB70: lui         $t0, 0xE01
        ctx->r8 = S32(0XE01 << 16);
            goto L_800BB028;
    }
    // 0x800BAB70: lui         $t0, 0xE01
    ctx->r8 = S32(0XE01 << 16);
    // 0x800BAB74: b           L_800BB0CC
    // 0x800BAB78: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
        goto L_800BB0CC;
    // 0x800BAB78: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
L_800BAB7C:
    // 0x800BAB7C: slti        $at, $v0, 0x12D
    ctx->r1 = SIGNED(ctx->r2) < 0X12D ? 1 : 0;
    // 0x800BAB80: bne         $at, $zero, L_800BAB98
    if (ctx->r1 != 0) {
        // 0x800BAB84: addiu       $at, $zero, 0x12D
        ctx->r1 = ADD32(0, 0X12D);
            goto L_800BAB98;
    }
    // 0x800BAB84: addiu       $at, $zero, 0x12D
    ctx->r1 = ADD32(0, 0X12D);
    // 0x800BAB88: beq         $v0, $at, L_800BB010
    if (ctx->r2 == ctx->r1) {
        // 0x800BAB8C: lui         $t8, 0xE01
        ctx->r24 = S32(0XE01 << 16);
            goto L_800BB010;
    }
    // 0x800BAB8C: lui         $t8, 0xE01
    ctx->r24 = S32(0XE01 << 16);
    // 0x800BAB90: b           L_800BB0CC
    // 0x800BAB94: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
        goto L_800BB0CC;
    // 0x800BAB94: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
L_800BAB98:
    // 0x800BAB98: slti        $at, $v0, 0x110
    ctx->r1 = SIGNED(ctx->r2) < 0X110 ? 1 : 0;
    // 0x800BAB9C: bne         $at, $zero, L_800BABB4
    if (ctx->r1 != 0) {
        // 0x800BABA0: addiu       $at, $zero, 0x12C
        ctx->r1 = ADD32(0, 0X12C);
            goto L_800BABB4;
    }
    // 0x800BABA0: addiu       $at, $zero, 0x12C
    ctx->r1 = ADD32(0, 0X12C);
    // 0x800BABA4: beq         $v0, $at, L_800BB004
    if (ctx->r2 == ctx->r1) {
        // 0x800BABA8: lui         $t7, 0xE01
        ctx->r15 = S32(0XE01 << 16);
            goto L_800BB004;
    }
    // 0x800BABA8: lui         $t7, 0xE01
    ctx->r15 = S32(0XE01 << 16);
    // 0x800BABAC: b           L_800BB0CC
    // 0x800BABB0: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
        goto L_800BB0CC;
    // 0x800BABB0: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
L_800BABB4:
    // 0x800BABB4: sltiu       $at, $v0, 0x110
    ctx->r1 = ctx->r2 < 0X110 ? 1 : 0;
    // 0x800BABB8: beq         $at, $zero, L_800BB0C8
    if (ctx->r1 == 0) {
        // 0x800BABBC: sll         $t6, $v0, 2
        ctx->r14 = S32(ctx->r2 << 2);
            goto L_800BB0C8;
    }
    // 0x800BABBC: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x800BABC0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800BABC4: addu        $at, $at, $t6
    gpr jr_addend_800BABCC = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800BABC8: lw          $t6, -0x73F4($at)
    ctx->r14 = ADD32(ctx->r1, -0X73F4);
    // 0x800BABCC: jr          $t6
    // 0x800BABD0: nop

    switch (jr_addend_800BABCC >> 2) {
        case 0: goto L_800BABDC; break;
        case 1: goto L_800BABF4; break;
        case 2: goto L_800BB050; break;
        case 3: goto L_800BB04C; break;
        case 4: goto L_800BB0C8; break;
        case 5: goto L_800BABD4; break;
        case 6: goto L_800BABEC; break;
        case 7: goto L_800BB0C8; break;
        case 8: goto L_800BB0C8; break;
        case 9: goto L_800BB0C8; break;
        case 10: goto L_800BAC24; break;
        case 11: goto L_800BAC3C; break;
        case 12: goto L_800BB0C8; break;
        case 13: goto L_800BB0C8; break;
        case 14: goto L_800BB0C8; break;
        case 15: goto L_800BAC1C; break;
        case 16: goto L_800BAC34; break;
        case 17: goto L_800BB0C8; break;
        case 18: goto L_800BB0C8; break;
        case 19: goto L_800BB0C8; break;
        case 20: goto L_800BAC54; break;
        case 21: goto L_800BAC6C; break;
        case 22: goto L_800BB0C8; break;
        case 23: goto L_800BB0C8; break;
        case 24: goto L_800BB0C8; break;
        case 25: goto L_800BAC4C; break;
        case 26: goto L_800BAC64; break;
        case 27: goto L_800BB0C8; break;
        case 28: goto L_800BB0C8; break;
        case 29: goto L_800BB0C8; break;
        case 30: goto L_800BAC84; break;
        case 31: goto L_800BAC9C; break;
        case 32: goto L_800BB0C8; break;
        case 33: goto L_800BB0C8; break;
        case 34: goto L_800BB0C8; break;
        case 35: goto L_800BAC7C; break;
        case 36: goto L_800BAC94; break;
        case 37: goto L_800BB0C8; break;
        case 38: goto L_800BB0C8; break;
        case 39: goto L_800BB0C8; break;
        case 40: goto L_800BAEFC; break;
        case 41: goto L_800BAF0C; break;
        case 42: goto L_800BB0C8; break;
        case 43: goto L_800BB0C8; break;
        case 44: goto L_800BB0C8; break;
        case 45: goto L_800BB0C8; break;
        case 46: goto L_800BB0C8; break;
        case 47: goto L_800BB0C8; break;
        case 48: goto L_800BB0C8; break;
        case 49: goto L_800BB0C8; break;
        case 50: goto L_800BAF1C; break;
        case 51: goto L_800BAF60; break;
        case 52: goto L_800BB0C8; break;
        case 53: goto L_800BB0C8; break;
        case 54: goto L_800BB0C8; break;
        case 55: goto L_800BAF1C; break;
        case 56: goto L_800BAF60; break;
        case 57: goto L_800BB0C8; break;
        case 58: goto L_800BB0C8; break;
        case 59: goto L_800BB0C8; break;
        case 60: goto L_800BAFA4; break;
        case 61: goto L_800BAFB4; break;
        case 62: goto L_800BB0C8; break;
        case 63: goto L_800BB0C8; break;
        case 64: goto L_800BB0C8; break;
        case 65: goto L_800BB0C8; break;
        case 66: goto L_800BB0C8; break;
        case 67: goto L_800BB0C8; break;
        case 68: goto L_800BB0C8; break;
        case 69: goto L_800BB0C8; break;
        case 70: goto L_800BAFE4; break;
        case 71: goto L_800BAFF4; break;
        case 72: goto L_800BB0C8; break;
        case 73: goto L_800BB0C8; break;
        case 74: goto L_800BB0C8; break;
        case 75: goto L_800BB0C8; break;
        case 76: goto L_800BB0C8; break;
        case 77: goto L_800BB0C8; break;
        case 78: goto L_800BB0C8; break;
        case 79: goto L_800BB0C8; break;
        case 80: goto L_800BADAC; break;
        case 81: goto L_800BADBC; break;
        case 82: goto L_800BB0C8; break;
        case 83: goto L_800BB0C8; break;
        case 84: goto L_800BB0C8; break;
        case 85: goto L_800BB0C8; break;
        case 86: goto L_800BB0C8; break;
        case 87: goto L_800BB0C8; break;
        case 88: goto L_800BB0C8; break;
        case 89: goto L_800BB0C8; break;
        case 90: goto L_800BAED4; break;
        case 91: goto L_800BAEEC; break;
        case 92: goto L_800BB0C8; break;
        case 93: goto L_800BB0C8; break;
        case 94: goto L_800BB0C8; break;
        case 95: goto L_800BAECC; break;
        case 96: goto L_800BAEE4; break;
        case 97: goto L_800BB0C8; break;
        case 98: goto L_800BB0C8; break;
        case 99: goto L_800BB0C8; break;
        case 100: goto L_800BADEC; break;
        case 101: goto L_800BADFC; break;
        case 102: goto L_800BB0C8; break;
        case 103: goto L_800BB0C8; break;
        case 104: goto L_800BB0C8; break;
        case 105: goto L_800BB0C8; break;
        case 106: goto L_800BB0C8; break;
        case 107: goto L_800BB0C8; break;
        case 108: goto L_800BB0C8; break;
        case 109: goto L_800BB0C8; break;
        case 110: goto L_800BADCC; break;
        case 111: goto L_800BADDC; break;
        case 112: goto L_800BB0C8; break;
        case 113: goto L_800BB0C8; break;
        case 114: goto L_800BB0C8; break;
        case 115: goto L_800BB0C8; break;
        case 116: goto L_800BB0C8; break;
        case 117: goto L_800BB0C8; break;
        case 118: goto L_800BB0C8; break;
        case 119: goto L_800BB0C8; break;
        case 120: goto L_800BAE0C; break;
        case 121: goto L_800BAE1C; break;
        case 122: goto L_800BB0C8; break;
        case 123: goto L_800BB0C8; break;
        case 124: goto L_800BB0C8; break;
        case 125: goto L_800BB0C8; break;
        case 126: goto L_800BB0C8; break;
        case 127: goto L_800BB0C8; break;
        case 128: goto L_800BB0C8; break;
        case 129: goto L_800BB0C8; break;
        case 130: goto L_800BAE4C; break;
        case 131: goto L_800BAE5C; break;
        case 132: goto L_800BB0C8; break;
        case 133: goto L_800BB0C8; break;
        case 134: goto L_800BB0C8; break;
        case 135: goto L_800BB0C8; break;
        case 136: goto L_800BB0C8; break;
        case 137: goto L_800BB0C8; break;
        case 138: goto L_800BB0C8; break;
        case 139: goto L_800BB0C8; break;
        case 140: goto L_800BAED4; break;
        case 141: goto L_800BAEEC; break;
        case 142: goto L_800BB0C8; break;
        case 143: goto L_800BB0C8; break;
        case 144: goto L_800BB0C8; break;
        case 145: goto L_800BB0C8; break;
        case 146: goto L_800BB0C8; break;
        case 147: goto L_800BB0C8; break;
        case 148: goto L_800BB0C8; break;
        case 149: goto L_800BB0C8; break;
        case 150: goto L_800BAE6C; break;
        case 151: goto L_800BAE7C; break;
        case 152: goto L_800BB0C8; break;
        case 153: goto L_800BB0C8; break;
        case 154: goto L_800BB0C8; break;
        case 155: goto L_800BB0C8; break;
        case 156: goto L_800BB0C8; break;
        case 157: goto L_800BB0C8; break;
        case 158: goto L_800BB0C8; break;
        case 159: goto L_800BB0C8; break;
        case 160: goto L_800BAE8C; break;
        case 161: goto L_800BAE9C; break;
        case 162: goto L_800BB0C8; break;
        case 163: goto L_800BB0C8; break;
        case 164: goto L_800BB0C8; break;
        case 165: goto L_800BB0C8; break;
        case 166: goto L_800BB0C8; break;
        case 167: goto L_800BB0C8; break;
        case 168: goto L_800BB0C8; break;
        case 169: goto L_800BB0C8; break;
        case 170: goto L_800BAFC4; break;
        case 171: goto L_800BAFD4; break;
        case 172: goto L_800BB0C8; break;
        case 173: goto L_800BB0C8; break;
        case 174: goto L_800BB0C8; break;
        case 175: goto L_800BB0C8; break;
        case 176: goto L_800BB0C8; break;
        case 177: goto L_800BB0C8; break;
        case 178: goto L_800BB0C8; break;
        case 179: goto L_800BB0C8; break;
        case 180: goto L_800BAE2C; break;
        case 181: goto L_800BAE3C; break;
        case 182: goto L_800BB0C8; break;
        case 183: goto L_800BB0C8; break;
        case 184: goto L_800BB0C8; break;
        case 185: goto L_800BB0C8; break;
        case 186: goto L_800BB0C8; break;
        case 187: goto L_800BB0C8; break;
        case 188: goto L_800BB0C8; break;
        case 189: goto L_800BB0C8; break;
        case 190: goto L_800BAEAC; break;
        case 191: goto L_800BAEBC; break;
        case 192: goto L_800BB0C8; break;
        case 193: goto L_800BB0C8; break;
        case 194: goto L_800BB0C8; break;
        case 195: goto L_800BB0C8; break;
        case 196: goto L_800BB0C8; break;
        case 197: goto L_800BB0C8; break;
        case 198: goto L_800BB0C8; break;
        case 199: goto L_800BB0C8; break;
        case 200: goto L_800BACAC; break;
        case 201: goto L_800BACBC; break;
        case 202: goto L_800BB0C8; break;
        case 203: goto L_800BB0C8; break;
        case 204: goto L_800BB0C8; break;
        case 205: goto L_800BB0C8; break;
        case 206: goto L_800BB0C8; break;
        case 207: goto L_800BB0C8; break;
        case 208: goto L_800BB0C8; break;
        case 209: goto L_800BB0C8; break;
        case 210: goto L_800BACCC; break;
        case 211: goto L_800BACDC; break;
        case 212: goto L_800BB0C8; break;
        case 213: goto L_800BB0C8; break;
        case 214: goto L_800BB0C8; break;
        case 215: goto L_800BB0C8; break;
        case 216: goto L_800BB0C8; break;
        case 217: goto L_800BB0C8; break;
        case 218: goto L_800BB0C8; break;
        case 219: goto L_800BB0C8; break;
        case 220: goto L_800BACEC; break;
        case 221: goto L_800BACFC; break;
        case 222: goto L_800BB0C8; break;
        case 223: goto L_800BB0C8; break;
        case 224: goto L_800BB0C8; break;
        case 225: goto L_800BB0C8; break;
        case 226: goto L_800BB0C8; break;
        case 227: goto L_800BB0C8; break;
        case 228: goto L_800BB0C8; break;
        case 229: goto L_800BB0C8; break;
        case 230: goto L_800BAD0C; break;
        case 231: goto L_800BAD1C; break;
        case 232: goto L_800BB0C8; break;
        case 233: goto L_800BB0C8; break;
        case 234: goto L_800BB0C8; break;
        case 235: goto L_800BB0C8; break;
        case 236: goto L_800BB0C8; break;
        case 237: goto L_800BB0C8; break;
        case 238: goto L_800BB0C8; break;
        case 239: goto L_800BB0C8; break;
        case 240: goto L_800BAD2C; break;
        case 241: goto L_800BAD3C; break;
        case 242: goto L_800BB0C8; break;
        case 243: goto L_800BB0C8; break;
        case 244: goto L_800BB0C8; break;
        case 245: goto L_800BB0C8; break;
        case 246: goto L_800BB0C8; break;
        case 247: goto L_800BB0C8; break;
        case 248: goto L_800BB0C8; break;
        case 249: goto L_800BB0C8; break;
        case 250: goto L_800BAD4C; break;
        case 251: goto L_800BAD5C; break;
        case 252: goto L_800BB0C8; break;
        case 253: goto L_800BB0C8; break;
        case 254: goto L_800BB0C8; break;
        case 255: goto L_800BB0C8; break;
        case 256: goto L_800BB0C8; break;
        case 257: goto L_800BB0C8; break;
        case 258: goto L_800BB0C8; break;
        case 259: goto L_800BB0C8; break;
        case 260: goto L_800BAD6C; break;
        case 261: goto L_800BAD7C; break;
        case 262: goto L_800BB0C8; break;
        case 263: goto L_800BB0C8; break;
        case 264: goto L_800BB0C8; break;
        case 265: goto L_800BB0C8; break;
        case 266: goto L_800BB0C8; break;
        case 267: goto L_800BB0C8; break;
        case 268: goto L_800BB0C8; break;
        case 269: goto L_800BB0C8; break;
        case 270: goto L_800BAD8C; break;
        case 271: goto L_800BAD9C; break;
        default: switch_error(__func__, 0x800BABCC, 0x800D8C0C);
    }
    // 0x800BABD0: nop

L_800BABD4:
    // 0x800BABD4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800BABD8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
L_800BABDC:
    // 0x800BABDC: lui         $t8, 0x100
    ctx->r24 = S32(0X100 << 16);
    // 0x800BABE0: addiu       $t8, $t8, 0x50E0
    ctx->r24 = ADD32(ctx->r24, 0X50E0);
    // 0x800BABE4: b           L_800BB0C8
    // 0x800BABE8: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
        goto L_800BB0C8;
    // 0x800BABE8: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
L_800BABEC:
    // 0x800BABEC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800BABF0: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
L_800BABF4:
    // 0x800BABF4: lui         $t0, 0x100
    ctx->r8 = S32(0X100 << 16);
    // 0x800BABF8: addiu       $t0, $t0, 0x6000
    ctx->r8 = ADD32(ctx->r8, 0X6000);
    // 0x800BABFC: b           L_800BB0C8
    // 0x800BAC00: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
        goto L_800BB0C8;
    // 0x800BAC00: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
L_800BAC04:
    // 0x800BAC04: addiu       $t1, $t1, 0x6F20
    ctx->r9 = ADD32(ctx->r9, 0X6F20);
    // 0x800BAC08: b           L_800BB0C8
    // 0x800BAC0C: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
        goto L_800BB0C8;
    // 0x800BAC0C: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
L_800BAC10:
    // 0x800BAC10: addiu       $t2, $t2, 0x7E40
    ctx->r10 = ADD32(ctx->r10, 0X7E40);
    // 0x800BAC14: b           L_800BB0C8
    // 0x800BAC18: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
        goto L_800BB0C8;
    // 0x800BAC18: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
L_800BAC1C:
    // 0x800BAC1C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800BAC20: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
L_800BAC24:
    // 0x800BAC24: lui         $t4, 0x100
    ctx->r12 = S32(0X100 << 16);
    // 0x800BAC28: addiu       $t4, $t4, 0x32A0
    ctx->r12 = ADD32(ctx->r12, 0X32A0);
    // 0x800BAC2C: b           L_800BB0C8
    // 0x800BAC30: sw          $t4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r12;
        goto L_800BB0C8;
    // 0x800BAC30: sw          $t4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r12;
L_800BAC34:
    // 0x800BAC34: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800BAC38: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
L_800BAC3C:
    // 0x800BAC3C: lui         $t6, 0x100
    ctx->r14 = S32(0X100 << 16);
    // 0x800BAC40: addiu       $t6, $t6, 0x41C0
    ctx->r14 = ADD32(ctx->r14, 0X41C0);
    // 0x800BAC44: b           L_800BB0C8
    // 0x800BAC48: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
        goto L_800BB0C8;
    // 0x800BAC48: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
L_800BAC4C:
    // 0x800BAC4C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800BAC50: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
L_800BAC54:
    // 0x800BAC54: lui         $t8, 0x101
    ctx->r24 = S32(0X101 << 16);
    // 0x800BAC58: addiu       $t8, $t8, -0x2700
    ctx->r24 = ADD32(ctx->r24, -0X2700);
    // 0x800BAC5C: b           L_800BB0C8
    // 0x800BAC60: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
        goto L_800BB0C8;
    // 0x800BAC60: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
L_800BAC64:
    // 0x800BAC64: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800BAC68: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
L_800BAC6C:
    // 0x800BAC6C: lui         $t0, 0x101
    ctx->r8 = S32(0X101 << 16);
    // 0x800BAC70: addiu       $t0, $t0, -0x17E0
    ctx->r8 = ADD32(ctx->r8, -0X17E0);
    // 0x800BAC74: b           L_800BB0C8
    // 0x800BAC78: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
        goto L_800BB0C8;
    // 0x800BAC78: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
L_800BAC7C:
    // 0x800BAC7C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800BAC80: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
L_800BAC84:
    // 0x800BAC84: lui         $t2, 0x101
    ctx->r10 = S32(0X101 << 16);
    // 0x800BAC88: addiu       $t2, $t2, -0x4540
    ctx->r10 = ADD32(ctx->r10, -0X4540);
    // 0x800BAC8C: b           L_800BB0C8
    // 0x800BAC90: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
        goto L_800BB0C8;
    // 0x800BAC90: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
L_800BAC94:
    // 0x800BAC94: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800BAC98: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
L_800BAC9C:
    // 0x800BAC9C: lui         $t4, 0x101
    ctx->r12 = S32(0X101 << 16);
    // 0x800BACA0: addiu       $t4, $t4, -0x3620
    ctx->r12 = ADD32(ctx->r12, -0X3620);
    // 0x800BACA4: b           L_800BB0C8
    // 0x800BACA8: sw          $t4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r12;
        goto L_800BB0C8;
    // 0x800BACA8: sw          $t4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r12;
L_800BACAC:
    // 0x800BACAC: lui         $t5, 0xF01
    ctx->r13 = S32(0XF01 << 16);
    // 0x800BACB0: addiu       $t5, $t5, -0x4A80
    ctx->r13 = ADD32(ctx->r13, -0X4A80);
    // 0x800BACB4: b           L_800BB0C8
    // 0x800BACB8: sw          $t5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r13;
        goto L_800BB0C8;
    // 0x800BACB8: sw          $t5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r13;
L_800BACBC:
    // 0x800BACBC: lui         $t6, 0xF01
    ctx->r14 = S32(0XF01 << 16);
    // 0x800BACC0: addiu       $t6, $t6, -0x3B60
    ctx->r14 = ADD32(ctx->r14, -0X3B60);
    // 0x800BACC4: b           L_800BB0C8
    // 0x800BACC8: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
        goto L_800BB0C8;
    // 0x800BACC8: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
L_800BACCC:
    // 0x800BACCC: lui         $t7, 0xF00
    ctx->r15 = S32(0XF00 << 16);
    // 0x800BACD0: addiu       $t7, $t7, 0x3C80
    ctx->r15 = ADD32(ctx->r15, 0X3C80);
    // 0x800BACD4: b           L_800BB0C8
    // 0x800BACD8: sw          $t7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r15;
        goto L_800BB0C8;
    // 0x800BACD8: sw          $t7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r15;
L_800BACDC:
    // 0x800BACDC: lui         $t8, 0xF00
    ctx->r24 = S32(0XF00 << 16);
    // 0x800BACE0: addiu       $t8, $t8, 0x4BA0
    ctx->r24 = ADD32(ctx->r24, 0X4BA0);
    // 0x800BACE4: b           L_800BB0C8
    // 0x800BACE8: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
        goto L_800BB0C8;
    // 0x800BACE8: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
L_800BACEC:
    // 0x800BACEC: lui         $t9, 0xF00
    ctx->r25 = S32(0XF00 << 16);
    // 0x800BACF0: addiu       $t9, $t9, 0x7900
    ctx->r25 = ADD32(ctx->r25, 0X7900);
    // 0x800BACF4: b           L_800BB0C8
    // 0x800BACF8: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
        goto L_800BB0C8;
    // 0x800BACF8: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
L_800BACFC:
    // 0x800BACFC: lui         $t0, 0xF01
    ctx->r8 = S32(0XF01 << 16);
    // 0x800BAD00: addiu       $t0, $t0, -0x77E0
    ctx->r8 = ADD32(ctx->r8, -0X77E0);
    // 0x800BAD04: b           L_800BB0C8
    // 0x800BAD08: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
        goto L_800BB0C8;
    // 0x800BAD08: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
L_800BAD0C:
    // 0x800BAD0C: lui         $t1, 0xF00
    ctx->r9 = S32(0XF00 << 16);
    // 0x800BAD10: addiu       $t1, $t1, 0x0
    ctx->r9 = ADD32(ctx->r9, 0X0);
    // 0x800BAD14: b           L_800BB0C8
    // 0x800BAD18: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
        goto L_800BB0C8;
    // 0x800BAD18: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
L_800BAD1C:
    // 0x800BAD1C: lui         $t2, 0xF00
    ctx->r10 = S32(0XF00 << 16);
    // 0x800BAD20: addiu       $t2, $t2, 0xF20
    ctx->r10 = ADD32(ctx->r10, 0XF20);
    // 0x800BAD24: b           L_800BB0C8
    // 0x800BAD28: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
        goto L_800BB0C8;
    // 0x800BAD28: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
L_800BAD2C:
    // 0x800BAD2C: lui         $t3, 0xF01
    ctx->r11 = S32(0XF01 << 16);
    // 0x800BAD30: addiu       $t3, $t3, -0x2C40
    ctx->r11 = ADD32(ctx->r11, -0X2C40);
    // 0x800BAD34: b           L_800BB0C8
    // 0x800BAD38: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
        goto L_800BB0C8;
    // 0x800BAD38: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
L_800BAD3C:
    // 0x800BAD3C: lui         $t4, 0xF01
    ctx->r12 = S32(0XF01 << 16);
    // 0x800BAD40: addiu       $t4, $t4, -0x1D20
    ctx->r12 = ADD32(ctx->r12, -0X1D20);
    // 0x800BAD44: b           L_800BB0C8
    // 0x800BAD48: sw          $t4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r12;
        goto L_800BB0C8;
    // 0x800BAD48: sw          $t4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r12;
L_800BAD4C:
    // 0x800BAD4C: lui         $t5, 0xF00
    ctx->r13 = S32(0XF00 << 16);
    // 0x800BAD50: addiu       $t5, $t5, 0x5AC0
    ctx->r13 = ADD32(ctx->r13, 0X5AC0);
    // 0x800BAD54: b           L_800BB0C8
    // 0x800BAD58: sw          $t5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r13;
        goto L_800BB0C8;
    // 0x800BAD58: sw          $t5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r13;
L_800BAD5C:
    // 0x800BAD5C: lui         $t6, 0xF00
    ctx->r14 = S32(0XF00 << 16);
    // 0x800BAD60: addiu       $t6, $t6, 0x69E0
    ctx->r14 = ADD32(ctx->r14, 0X69E0);
    // 0x800BAD64: b           L_800BB0C8
    // 0x800BAD68: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
        goto L_800BB0C8;
    // 0x800BAD68: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
L_800BAD6C:
    // 0x800BAD6C: lui         $t7, 0xF01
    ctx->r15 = S32(0XF01 << 16);
    // 0x800BAD70: addiu       $t7, $t7, -0x68C0
    ctx->r15 = ADD32(ctx->r15, -0X68C0);
    // 0x800BAD74: b           L_800BB0C8
    // 0x800BAD78: sw          $t7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r15;
        goto L_800BB0C8;
    // 0x800BAD78: sw          $t7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r15;
L_800BAD7C:
    // 0x800BAD7C: lui         $t8, 0xF01
    ctx->r24 = S32(0XF01 << 16);
    // 0x800BAD80: addiu       $t8, $t8, -0x59A0
    ctx->r24 = ADD32(ctx->r24, -0X59A0);
    // 0x800BAD84: b           L_800BB0C8
    // 0x800BAD88: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
        goto L_800BB0C8;
    // 0x800BAD88: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
L_800BAD8C:
    // 0x800BAD8C: lui         $t9, 0xF00
    ctx->r25 = S32(0XF00 << 16);
    // 0x800BAD90: addiu       $t9, $t9, 0x1E40
    ctx->r25 = ADD32(ctx->r25, 0X1E40);
    // 0x800BAD94: b           L_800BB0C8
    // 0x800BAD98: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
        goto L_800BB0C8;
    // 0x800BAD98: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
L_800BAD9C:
    // 0x800BAD9C: lui         $t0, 0xF00
    ctx->r8 = S32(0XF00 << 16);
    // 0x800BADA0: addiu       $t0, $t0, 0x2D60
    ctx->r8 = ADD32(ctx->r8, 0X2D60);
    // 0x800BADA4: b           L_800BB0C8
    // 0x800BADA8: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
        goto L_800BB0C8;
    // 0x800BADA8: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
L_800BADAC:
    // 0x800BADAC: lui         $t1, 0x602
    ctx->r9 = S32(0X602 << 16);
    // 0x800BADB0: addiu       $t1, $t1, 0x6420
    ctx->r9 = ADD32(ctx->r9, 0X6420);
    // 0x800BADB4: b           L_800BB0C8
    // 0x800BADB8: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
        goto L_800BB0C8;
    // 0x800BADB8: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
L_800BADBC:
    // 0x800BADBC: lui         $t2, 0x602
    ctx->r10 = S32(0X602 << 16);
    // 0x800BADC0: addiu       $t2, $t2, 0x7340
    ctx->r10 = ADD32(ctx->r10, 0X7340);
    // 0x800BADC4: b           L_800BB0C8
    // 0x800BADC8: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
        goto L_800BB0C8;
    // 0x800BADC8: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
L_800BADCC:
    // 0x800BADCC: lui         $t3, 0x602
    ctx->r11 = S32(0X602 << 16);
    // 0x800BADD0: addiu       $t3, $t3, 0x45E0
    ctx->r11 = ADD32(ctx->r11, 0X45E0);
    // 0x800BADD4: b           L_800BB0C8
    // 0x800BADD8: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
        goto L_800BB0C8;
    // 0x800BADD8: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
L_800BADDC:
    // 0x800BADDC: lui         $t4, 0x602
    ctx->r12 = S32(0X602 << 16);
    // 0x800BADE0: addiu       $t4, $t4, 0x5500
    ctx->r12 = ADD32(ctx->r12, 0X5500);
    // 0x800BADE4: b           L_800BB0C8
    // 0x800BADE8: sw          $t4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r12;
        goto L_800BB0C8;
    // 0x800BADE8: sw          $t4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r12;
L_800BADEC:
    // 0x800BADEC: lui         $t5, 0x602
    ctx->r13 = S32(0X602 << 16);
    // 0x800BADF0: addiu       $t5, $t5, -0x3720
    ctx->r13 = ADD32(ctx->r13, -0X3720);
    // 0x800BADF4: b           L_800BB0C8
    // 0x800BADF8: sw          $t5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r13;
        goto L_800BB0C8;
    // 0x800BADF8: sw          $t5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r13;
L_800BADFC:
    // 0x800BADFC: lui         $t6, 0x602
    ctx->r14 = S32(0X602 << 16);
    // 0x800BAE00: addiu       $t6, $t6, -0x2800
    ctx->r14 = ADD32(ctx->r14, -0X2800);
    // 0x800BAE04: b           L_800BB0C8
    // 0x800BAE08: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
        goto L_800BB0C8;
    // 0x800BAE08: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
L_800BAE0C:
    // 0x800BAE0C: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x800BAE10: addiu       $t7, $t7, 0x47E0
    ctx->r15 = ADD32(ctx->r15, 0X47E0);
    // 0x800BAE14: b           L_800BB0C8
    // 0x800BAE18: sw          $t7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r15;
        goto L_800BB0C8;
    // 0x800BAE18: sw          $t7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r15;
L_800BAE1C:
    // 0x800BAE1C: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x800BAE20: addiu       $t8, $t8, 0x5700
    ctx->r24 = ADD32(ctx->r24, 0X5700);
    // 0x800BAE24: b           L_800BB0C8
    // 0x800BAE28: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
        goto L_800BB0C8;
    // 0x800BAE28: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
L_800BAE2C:
    // 0x800BAE2C: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x800BAE30: addiu       $t9, $t9, 0x29A0
    ctx->r25 = ADD32(ctx->r25, 0X29A0);
    // 0x800BAE34: b           L_800BB0C8
    // 0x800BAE38: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
        goto L_800BB0C8;
    // 0x800BAE38: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
L_800BAE3C:
    // 0x800BAE3C: lui         $t0, 0x600
    ctx->r8 = S32(0X600 << 16);
    // 0x800BAE40: addiu       $t0, $t0, 0x38C0
    ctx->r8 = ADD32(ctx->r8, 0X38C0);
    // 0x800BAE44: b           L_800BB0C8
    // 0x800BAE48: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
        goto L_800BB0C8;
    // 0x800BAE48: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
L_800BAE4C:
    // 0x800BAE4C: lui         $t1, 0x601
    ctx->r9 = S32(0X601 << 16);
    // 0x800BAE50: addiu       $t1, $t1, 0x4510
    ctx->r9 = ADD32(ctx->r9, 0X4510);
    // 0x800BAE54: b           L_800BB0C8
    // 0x800BAE58: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
        goto L_800BB0C8;
    // 0x800BAE58: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
L_800BAE5C:
    // 0x800BAE5C: lui         $t2, 0x601
    ctx->r10 = S32(0X601 << 16);
    // 0x800BAE60: addiu       $t2, $t2, 0x5430
    ctx->r10 = ADD32(ctx->r10, 0X5430);
    // 0x800BAE64: b           L_800BB0C8
    // 0x800BAE68: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
        goto L_800BB0C8;
    // 0x800BAE68: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
L_800BAE6C:
    // 0x800BAE6C: lui         $t3, 0x602
    ctx->r11 = S32(0X602 << 16);
    // 0x800BAE70: addiu       $t3, $t3, 0xFB0
    ctx->r11 = ADD32(ctx->r11, 0XFB0);
    // 0x800BAE74: b           L_800BB0C8
    // 0x800BAE78: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
        goto L_800BB0C8;
    // 0x800BAE78: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
L_800BAE7C:
    // 0x800BAE7C: lui         $t4, 0x602
    ctx->r12 = S32(0X602 << 16);
    // 0x800BAE80: addiu       $t4, $t4, 0x1ED0
    ctx->r12 = ADD32(ctx->r12, 0X1ED0);
    // 0x800BAE84: b           L_800BB0C8
    // 0x800BAE88: sw          $t4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r12;
        goto L_800BB0C8;
    // 0x800BAE88: sw          $t4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r12;
L_800BAE8C:
    // 0x800BAE8C: lui         $t5, 0x602
    ctx->r13 = S32(0X602 << 16);
    // 0x800BAE90: addiu       $t5, $t5, -0x70D0
    ctx->r13 = ADD32(ctx->r13, -0X70D0);
    // 0x800BAE94: b           L_800BB0C8
    // 0x800BAE98: sw          $t5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r13;
        goto L_800BB0C8;
    // 0x800BAE98: sw          $t5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r13;
L_800BAE9C:
    // 0x800BAE9C: lui         $t6, 0x602
    ctx->r14 = S32(0X602 << 16);
    // 0x800BAEA0: addiu       $t6, $t6, -0x61B0
    ctx->r14 = ADD32(ctx->r14, -0X61B0);
    // 0x800BAEA4: b           L_800BB0C8
    // 0x800BAEA8: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
        goto L_800BB0C8;
    // 0x800BAEA8: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
L_800BAEAC:
    // 0x800BAEAC: lui         $t7, 0x601
    ctx->r15 = S32(0X601 << 16);
    // 0x800BAEB0: addiu       $t7, $t7, 0xC20
    ctx->r15 = ADD32(ctx->r15, 0XC20);
    // 0x800BAEB4: b           L_800BB0C8
    // 0x800BAEB8: sw          $t7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r15;
        goto L_800BB0C8;
    // 0x800BAEB8: sw          $t7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r15;
L_800BAEBC:
    // 0x800BAEBC: lui         $t8, 0x601
    ctx->r24 = S32(0X601 << 16);
    // 0x800BAEC0: addiu       $t8, $t8, 0x1B40
    ctx->r24 = ADD32(ctx->r24, 0X1B40);
    // 0x800BAEC4: b           L_800BB0C8
    // 0x800BAEC8: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
        goto L_800BB0C8;
    // 0x800BAEC8: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
L_800BAECC:
    // 0x800BAECC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800BAED0: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
L_800BAED4:
    // 0x800BAED4: lui         $t0, 0x101
    ctx->r8 = S32(0X101 << 16);
    // 0x800BAED8: addiu       $t0, $t0, -0x6380
    ctx->r8 = ADD32(ctx->r8, -0X6380);
    // 0x800BAEDC: b           L_800BB0C8
    // 0x800BAEE0: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
        goto L_800BB0C8;
    // 0x800BAEE0: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
L_800BAEE4:
    // 0x800BAEE4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800BAEE8: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
L_800BAEEC:
    // 0x800BAEEC: lui         $t2, 0x101
    ctx->r10 = S32(0X101 << 16);
    // 0x800BAEF0: addiu       $t2, $t2, -0x5460
    ctx->r10 = ADD32(ctx->r10, -0X5460);
    // 0x800BAEF4: b           L_800BB0C8
    // 0x800BAEF8: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
        goto L_800BB0C8;
    // 0x800BAEF8: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
L_800BAEFC:
    // 0x800BAEFC: lui         $t3, 0xD00
    ctx->r11 = S32(0XD00 << 16);
    // 0x800BAF00: addiu       $t3, $t3, 0x3DF0
    ctx->r11 = ADD32(ctx->r11, 0X3DF0);
    // 0x800BAF04: b           L_800BB0C8
    // 0x800BAF08: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
        goto L_800BB0C8;
    // 0x800BAF08: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
L_800BAF0C:
    // 0x800BAF0C: lui         $t4, 0xD00
    ctx->r12 = S32(0XD00 << 16);
    // 0x800BAF10: addiu       $t4, $t4, 0x4D10
    ctx->r12 = ADD32(ctx->r12, 0X4D10);
    // 0x800BAF14: b           L_800BB0C8
    // 0x800BAF18: sw          $t4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r12;
        goto L_800BB0C8;
    // 0x800BAF18: sw          $t4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r12;
L_800BAF1C:
    // 0x800BAF1C: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x800BAF20: lw          $t5, 0x7834($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7834);
    // 0x800BAF24: lui         $v0, 0xD00
    ctx->r2 = S32(0XD00 << 16);
    // 0x800BAF28: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x800BAF2C: bne         $t5, $at, L_800BAF50
    if (ctx->r13 != ctx->r1) {
        // 0x800BAF30: addiu       $v0, $v0, 0x170
        ctx->r2 = ADD32(ctx->r2, 0X170);
            goto L_800BAF50;
    }
    // 0x800BAF30: addiu       $v0, $v0, 0x170
    ctx->r2 = ADD32(ctx->r2, 0X170);
    // 0x800BAF34: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800BAF38: lw          $t6, -0x7DCC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7DCC);
    // 0x800BAF3C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800BAF40: bnel        $t6, $at, L_800BAF54
    if (ctx->r14 != ctx->r1) {
        // 0x800BAF44: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_800BAF54;
    }
    goto skip_0;
    // 0x800BAF44: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    skip_0:
    // 0x800BAF48: lui         $v0, 0x600
    ctx->r2 = S32(0X600 << 16);
    // 0x800BAF4C: addiu       $v0, $v0, 0xB60
    ctx->r2 = ADD32(ctx->r2, 0XB60);
L_800BAF50:
    // 0x800BAF50: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
L_800BAF54:
    // 0x800BAF54: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800BAF58: b           L_800BB0C8
    // 0x800BAF5C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
        goto L_800BB0C8;
    // 0x800BAF5C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
L_800BAF60:
    // 0x800BAF60: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x800BAF64: lw          $t8, 0x7834($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7834);
    // 0x800BAF68: lui         $v0, 0xD00
    ctx->r2 = S32(0XD00 << 16);
    // 0x800BAF6C: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x800BAF70: bne         $t8, $at, L_800BAF94
    if (ctx->r24 != ctx->r1) {
        // 0x800BAF74: addiu       $v0, $v0, 0x1090
        ctx->r2 = ADD32(ctx->r2, 0X1090);
            goto L_800BAF94;
    }
    // 0x800BAF74: addiu       $v0, $v0, 0x1090
    ctx->r2 = ADD32(ctx->r2, 0X1090);
    // 0x800BAF78: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800BAF7C: lw          $t9, -0x7DCC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7DCC);
    // 0x800BAF80: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800BAF84: bnel        $t9, $at, L_800BAF98
    if (ctx->r25 != ctx->r1) {
        // 0x800BAF88: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_800BAF98;
    }
    goto skip_1;
    // 0x800BAF88: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    skip_1:
    // 0x800BAF8C: lui         $v0, 0x600
    ctx->r2 = S32(0X600 << 16);
    // 0x800BAF90: addiu       $v0, $v0, 0x1A80
    ctx->r2 = ADD32(ctx->r2, 0X1A80);
L_800BAF94:
    // 0x800BAF94: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_800BAF98:
    // 0x800BAF98: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x800BAF9C: b           L_800BB0C8
    // 0x800BAFA0: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
        goto L_800BB0C8;
    // 0x800BAFA0: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
L_800BAFA4:
    // 0x800BAFA4: lui         $t1, 0xD00
    ctx->r9 = S32(0XD00 << 16);
    // 0x800BAFA8: addiu       $t1, $t1, 0x5C30
    ctx->r9 = ADD32(ctx->r9, 0X5C30);
    // 0x800BAFAC: b           L_800BB0C8
    // 0x800BAFB0: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
        goto L_800BB0C8;
    // 0x800BAFB0: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
L_800BAFB4:
    // 0x800BAFB4: lui         $t2, 0xD00
    ctx->r10 = S32(0XD00 << 16);
    // 0x800BAFB8: addiu       $t2, $t2, 0x6B50
    ctx->r10 = ADD32(ctx->r10, 0X6B50);
    // 0x800BAFBC: b           L_800BB0C8
    // 0x800BAFC0: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
        goto L_800BB0C8;
    // 0x800BAFC0: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
L_800BAFC4:
    // 0x800BAFC4: lui         $t3, 0xD00
    ctx->r11 = S32(0XD00 << 16);
    // 0x800BAFC8: addiu       $t3, $t3, 0x1FB0
    ctx->r11 = ADD32(ctx->r11, 0X1FB0);
    // 0x800BAFCC: b           L_800BB0C8
    // 0x800BAFD0: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
        goto L_800BB0C8;
    // 0x800BAFD0: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
L_800BAFD4:
    // 0x800BAFD4: lui         $t4, 0xD00
    ctx->r12 = S32(0XD00 << 16);
    // 0x800BAFD8: addiu       $t4, $t4, 0x2ED0
    ctx->r12 = ADD32(ctx->r12, 0X2ED0);
    // 0x800BAFDC: b           L_800BB0C8
    // 0x800BAFE0: sw          $t4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r12;
        goto L_800BB0C8;
    // 0x800BAFE0: sw          $t4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r12;
L_800BAFE4:
    // 0x800BAFE4: lui         $t5, 0xD00
    ctx->r13 = S32(0XD00 << 16);
    // 0x800BAFE8: addiu       $t5, $t5, 0x7A70
    ctx->r13 = ADD32(ctx->r13, 0X7A70);
    // 0x800BAFEC: b           L_800BB0C8
    // 0x800BAFF0: sw          $t5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r13;
        goto L_800BB0C8;
    // 0x800BAFF0: sw          $t5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r13;
L_800BAFF4:
    // 0x800BAFF4: lui         $t6, 0xD01
    ctx->r14 = S32(0XD01 << 16);
    // 0x800BAFF8: addiu       $t6, $t6, -0x7670
    ctx->r14 = ADD32(ctx->r14, -0X7670);
    // 0x800BAFFC: b           L_800BB0C8
    // 0x800BB000: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
        goto L_800BB0C8;
    // 0x800BB000: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
L_800BB004:
    // 0x800BB004: addiu       $t7, $t7, -0x1F00
    ctx->r15 = ADD32(ctx->r15, -0X1F00);
    // 0x800BB008: b           L_800BB0C8
    // 0x800BB00C: sw          $t7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r15;
        goto L_800BB0C8;
    // 0x800BB00C: sw          $t7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r15;
L_800BB010:
    // 0x800BB010: addiu       $t8, $t8, -0xFE0
    ctx->r24 = ADD32(ctx->r24, -0XFE0);
    // 0x800BB014: b           L_800BB0C8
    // 0x800BB018: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
        goto L_800BB0C8;
    // 0x800BB018: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
L_800BB01C:
    // 0x800BB01C: addiu       $t9, $t9, -0xC0
    ctx->r25 = ADD32(ctx->r25, -0XC0);
    // 0x800BB020: b           L_800BB0C8
    // 0x800BB024: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
        goto L_800BB0C8;
    // 0x800BB024: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
L_800BB028:
    // 0x800BB028: addiu       $t0, $t0, 0xE60
    ctx->r8 = ADD32(ctx->r8, 0XE60);
    // 0x800BB02C: b           L_800BB0C8
    // 0x800BB030: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
        goto L_800BB0C8;
    // 0x800BB030: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
L_800BB034:
    // 0x800BB034: addiu       $t1, $t1, 0x900
    ctx->r9 = ADD32(ctx->r9, 0X900);
    // 0x800BB038: b           L_800BB0C8
    // 0x800BB03C: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
        goto L_800BB0C8;
    // 0x800BB03C: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
L_800BB040:
    // 0x800BB040: addiu       $t2, $t2, 0x1820
    ctx->r10 = ADD32(ctx->r10, 0X1820);
    // 0x800BB044: b           L_800BB0C8
    // 0x800BB048: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
        goto L_800BB0C8;
    // 0x800BB048: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
L_800BB04C:
    // 0x800BB04C: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_800BB050:
    // 0x800BB050: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800BB054: lw          $v0, 0x7834($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7834);
    // 0x800BB058: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800BB05C: lui         $t4, 0x601
    ctx->r12 = S32(0X601 << 16);
    // 0x800BB060: beq         $v0, $at, L_800BB094
    if (ctx->r2 == ctx->r1) {
        // 0x800BB064: addiu       $t4, $t4, -0x3960
        ctx->r12 = ADD32(ctx->r12, -0X3960);
            goto L_800BB094;
    }
    // 0x800BB064: addiu       $t4, $t4, -0x3960
    ctx->r12 = ADD32(ctx->r12, -0X3960);
    // 0x800BB068: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x800BB06C: beq         $v0, $at, L_800BB088
    if (ctx->r2 == ctx->r1) {
        // 0x800BB070: lui         $t3, 0x101
        ctx->r11 = S32(0X101 << 16);
            goto L_800BB088;
    }
    // 0x800BB070: lui         $t3, 0x101
    ctx->r11 = S32(0X101 << 16);
    // 0x800BB074: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x800BB078: beql        $v0, $at, L_800BB098
    if (ctx->r2 == ctx->r1) {
        // 0x800BB07C: sw          $t4, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r12;
            goto L_800BB098;
    }
    goto skip_2;
    // 0x800BB07C: sw          $t4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r12;
    skip_2:
    // 0x800BB080: b           L_800BB098
    // 0x800BB084: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
        goto L_800BB098;
    // 0x800BB084: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
L_800BB088:
    // 0x800BB088: addiu       $t3, $t3, -0x72A0
    ctx->r11 = ADD32(ctx->r11, -0X72A0);
    // 0x800BB08C: b           L_800BB098
    // 0x800BB090: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
        goto L_800BB098;
    // 0x800BB090: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
L_800BB094:
    // 0x800BB094: sw          $t4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r12;
L_800BB098:
    // 0x800BB098: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800BB09C: lwc1        $f4, 0x7D68($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7D68);
    // 0x800BB0A0: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x800BB0A4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800BB0A8: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800BB0AC: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x800BB0B0: nop

    // 0x800BB0B4: beq         $v0, $at, L_800BB0C4
    if (ctx->r2 == ctx->r1) {
        // 0x800BB0B8: addiu       $at, $zero, 0x37
        ctx->r1 = ADD32(0, 0X37);
            goto L_800BB0C4;
    }
    // 0x800BB0B8: addiu       $at, $zero, 0x37
    ctx->r1 = ADD32(0, 0X37);
    // 0x800BB0BC: bnel        $v0, $at, L_800BB0CC
    if (ctx->r2 != ctx->r1) {
        // 0x800BB0C0: lw          $t7, 0x44($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X44);
            goto L_800BB0CC;
    }
    goto skip_3;
    // 0x800BB0C0: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    skip_3:
L_800BB0C4:
    // 0x800BB0C4: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
L_800BB0C8:
    // 0x800BB0C8: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
L_800BB0CC:
    // 0x800BB0CC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800BB0D0: beql        $t7, $zero, L_800BB374
    if (ctx->r15 == 0) {
        // 0x800BB0D4: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_800BB374;
    }
    goto skip_4;
    // 0x800BB0D4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_4:
    // 0x800BB0D8: lwc1        $f0, 0x7D38($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X7D38);
    // 0x800BB0DC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800BB0E0: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x800BB0E4: c.eq.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl == ctx->f0.fl;
    // 0x800BB0E8: nop

    // 0x800BB0EC: bc1tl       L_800BB374
    if (c1cs) {
        // 0x800BB0F0: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_800BB374;
    }
    goto skip_5;
    // 0x800BB0F0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_5:
    // 0x800BB0F4: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x800BB0F8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BB0FC: add.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x800BB100: lwc1        $f2, -0x78C0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X78C0);
    // 0x800BB104: mul.s       $f6, $f0, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800BB108: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800BB10C: add.s       $f12, $f10, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x800BB110: add.s       $f16, $f2, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = ctx->f2.fl + ctx->f20.fl;
    // 0x800BB114: c.le.s      $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.fl <= ctx->f12.fl;
    // 0x800BB118: nop

    // 0x800BB11C: bc1fl       L_800BB134
    if (!c1cs) {
        // 0x800BB120: c.le.s      $f12, $f2
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl <= ctx->f2.fl;
            goto L_800BB134;
    }
    goto skip_6;
    // 0x800BB120: c.le.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl <= ctx->f2.fl;
    skip_6:
    // 0x800BB124: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800BB128: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800BB12C: swc1        $f18, 0x4A74($at)
    MEM_W(0X4A74, ctx->r1) = ctx->f18.u32l;
    // 0x800BB130: c.le.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl <= ctx->f2.fl;
L_800BB134:
    // 0x800BB134: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x800BB138: bc1f        L_800BB14C
    if (!c1cs) {
        // 0x800BB13C: nop
    
            goto L_800BB14C;
    }
    // 0x800BB13C: nop

    // 0x800BB140: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800BB144: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800BB148: swc1        $f4, 0x4A74($at)
    MEM_W(0X4A74, ctx->r1) = ctx->f4.u32l;
L_800BB14C:
    // 0x800BB14C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800BB150: lwc1        $f8, 0x4A74($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X4A74);
    // 0x800BB154: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800BB158: jal         0x800BA490
    // 0x800BB15C: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    RCP_SetupDL_76(rdram, ctx);
        goto after_0;
    // 0x800BB15C: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    after_0:
    // 0x800BB160: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BB164: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x800BB168: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800BB16C: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x800BB170: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x800BB174: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x800BB178: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800BB17C: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x800BB180: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800BB184: beq         $s0, $zero, L_800BB284
    if (ctx->r16 == 0) {
        // 0x800BB188: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_800BB284;
    }
    // 0x800BB188: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800BB18C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800BB190: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_800BB194:
    // 0x800BB194: mtc1        $s0, $f18
    ctx->f18.u32l = ctx->r16;
    // 0x800BB198: lwc1        $f16, 0x38($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800BB19C: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x800BB1A0: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800BB1A4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BB1A8: lwc1        $f14, -0x78C4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X78C4);
    // 0x800BB1AC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800BB1B0: lwc1        $f0, 0x7D38($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X7D38);
    // 0x800BB1B4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BB1B8: mul.s       $f18, $f18, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x800BB1BC: lwc1        $f12, -0x78C0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X78C0);
    // 0x800BB1C0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BB1C4: sll         $t1, $s1, 1
    ctx->r9 = S32(ctx->r17 << 1);
    // 0x800BB1C8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800BB1CC: add.s       $f12, $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f20.fl;
    // 0x800BB1D0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800BB1D4: mul.s       $f18, $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800BB1D8: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x800BB1DC: add.s       $f16, $f12, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f12.fl + ctx->f16.fl;
    // 0x800BB1E0: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    // 0x800BB1E4: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    // 0x800BB1E8: addiu       $a2, $zero, 0x2C
    ctx->r6 = ADD32(0, 0X2C);
    // 0x800BB1EC: addiu       $a3, $zero, 0x14
    ctx->r7 = ADD32(0, 0X14);
    // 0x800BB1F0: add.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800BB1F4: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x800BB1F8: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x800BB1FC: jal         0x8009D6CC
    // 0x800BB200: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    Lib_TextureRect_RGBA16_MirX(rdram, ctx);
        goto after_1;
    // 0x800BB200: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_1:
    // 0x800BB204: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800BB208: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800BB20C: bne         $s0, $at, L_800BB194
    if (ctx->r16 != ctx->r1) {
        // 0x800BB210: addiu       $s1, $s1, 0x370
        ctx->r17 = ADD32(ctx->r17, 0X370);
            goto L_800BB194;
    }
    // 0x800BB210: addiu       $s1, $s1, 0x370
    ctx->r17 = ADD32(ctx->r17, 0X370);
    // 0x800BB214: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BB218: lwc1        $f16, -0x78C4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X78C4);
    // 0x800BB21C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800BB220: lwc1        $f0, 0x7D38($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X7D38);
    // 0x800BB224: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BB228: lwc1        $f18, -0x78C0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X78C0);
    // 0x800BB22C: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x800BB230: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800BB234: add.s       $f8, $f18, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f20.fl;
    // 0x800BB238: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x800BB23C: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800BB240: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800BB244: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800BB248: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x800BB24C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BB250: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800BB254: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800BB258: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x800BB25C: addiu       $a2, $zero, 0x2C
    ctx->r6 = ADD32(0, 0X2C);
    // 0x800BB260: add.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x800BB264: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x800BB268: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x800BB26C: addiu       $a1, $a1, 0xDC0
    ctx->r5 = ADD32(ctx->r5, 0XDC0);
    // 0x800BB270: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x800BB274: jal         0x8009D6CC
    // 0x800BB278: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    Lib_TextureRect_RGBA16_MirX(rdram, ctx);
        goto after_2;
    // 0x800BB278: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x800BB27C: b           L_800BB374
    // 0x800BB280: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_800BB374;
    // 0x800BB280: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_800BB284:
    // 0x800BB284: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800BB288:
    // 0x800BB288: mtc1        $s0, $f18
    ctx->f18.u32l = ctx->r16;
    // 0x800BB28C: lwc1        $f16, 0x38($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800BB290: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x800BB294: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800BB298: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BB29C: lwc1        $f14, -0x78C4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X78C4);
    // 0x800BB2A0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800BB2A4: lwc1        $f0, 0x7D38($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X7D38);
    // 0x800BB2A8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BB2AC: mul.s       $f18, $f18, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x800BB2B0: lwc1        $f12, -0x78C0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X78C0);
    // 0x800BB2B4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BB2B8: sll         $t3, $s1, 1
    ctx->r11 = S32(ctx->r17 << 1);
    // 0x800BB2BC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800BB2C0: add.s       $f12, $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f20.fl;
    // 0x800BB2C4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800BB2C8: mul.s       $f18, $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800BB2CC: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x800BB2D0: add.s       $f16, $f12, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f12.fl + ctx->f16.fl;
    // 0x800BB2D4: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    // 0x800BB2D8: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    // 0x800BB2DC: addiu       $a2, $zero, 0x2C
    ctx->r6 = ADD32(0, 0X2C);
    // 0x800BB2E0: addiu       $a3, $zero, 0x14
    ctx->r7 = ADD32(0, 0X14);
    // 0x800BB2E4: add.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800BB2E8: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x800BB2EC: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x800BB2F0: jal         0x8009D418
    // 0x800BB2F4: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    Lib_TextureRect_RGBA16(rdram, ctx);
        goto after_3;
    // 0x800BB2F4: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_3:
    // 0x800BB2F8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800BB2FC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800BB300: bne         $s0, $at, L_800BB288
    if (ctx->r16 != ctx->r1) {
        // 0x800BB304: addiu       $s1, $s1, 0x370
        ctx->r17 = ADD32(ctx->r17, 0X370);
            goto L_800BB288;
    }
    // 0x800BB304: addiu       $s1, $s1, 0x370
    ctx->r17 = ADD32(ctx->r17, 0X370);
    // 0x800BB308: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BB30C: lwc1        $f4, -0x78C4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X78C4);
    // 0x800BB310: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800BB314: lwc1        $f0, 0x7D38($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X7D38);
    // 0x800BB318: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BB31C: lwc1        $f10, -0x78C0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X78C0);
    // 0x800BB320: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x800BB324: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800BB328: add.s       $f18, $f10, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f20.fl;
    // 0x800BB32C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x800BB330: mul.s       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800BB334: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800BB338: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800BB33C: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x800BB340: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BB344: add.s       $f16, $f18, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x800BB348: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800BB34C: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x800BB350: addiu       $a2, $zero, 0x2C
    ctx->r6 = ADD32(0, 0X2C);
    // 0x800BB354: add.s       $f10, $f16, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x800BB358: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x800BB35C: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x800BB360: addiu       $a1, $a1, 0xDC0
    ctx->r5 = ADD32(ctx->r5, 0XDC0);
    // 0x800BB364: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    // 0x800BB368: jal         0x8009D418
    // 0x800BB36C: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    Lib_TextureRect_RGBA16(rdram, ctx);
        goto after_4;
    // 0x800BB36C: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    after_4:
    // 0x800BB370: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_800BB374:
    // 0x800BB374: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x800BB378: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x800BB37C: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x800BB380: jr          $ra
    // 0x800BB384: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x800BB384: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void Object_SetSfxSourceToView(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005F290: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005F294: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005F298: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x8005F29C: lw          $t6, 0x78A8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X78A8);
    // 0x8005F2A0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005F2A4: beql        $t6, $at, L_8005F2C8
    if (ctx->r14 == ctx->r1) {
        // 0x8005F2A8: lwc1        $f4, 0x0($a1)
        ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
            goto L_8005F2C8;
    }
    goto skip_0;
    // 0x8005F2A8: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    skip_0:
    // 0x8005F2AC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8005F2B0: nop

    // 0x8005F2B4: swc1        $f0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f0.u32l;
    // 0x8005F2B8: swc1        $f0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f0.u32l;
    // 0x8005F2BC: b           L_8005F2DC
    // 0x8005F2C0: swc1        $f0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f0.u32l;
        goto L_8005F2DC;
    // 0x8005F2C0: swc1        $f0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f0.u32l;
    // 0x8005F2C4: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
L_8005F2C8:
    // 0x8005F2C8: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x8005F2CC: lwc1        $f6, 0x4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8005F2D0: swc1        $f6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f6.u32l;
    // 0x8005F2D4: lwc1        $f8, 0x8($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8005F2D8: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
L_8005F2DC:
    // 0x8005F2DC: jal         0x8005F030
    // 0x8005F2E0: nop

    Object_ClampSfxSource(rdram, ctx);
        goto after_0;
    // 0x8005F2E0: nop

    after_0:
    // 0x8005F2E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005F2E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005F2EC: jr          $ra
    // 0x8005F2F0: nop

    return;
    // 0x8005F2F0: nop

;}
RECOMP_FUNC void Effect_Effect349_Spawn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062C38: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80062C3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80062C40: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    // 0x80062C44: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    // 0x80062C48: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x80062C4C: lbu         $t6, 0x7C98($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X7C98);
    // 0x80062C50: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x80062C54: addiu       $a2, $a2, 0x130
    ctx->r6 = ADD32(ctx->r6, 0X130);
    // 0x80062C58: bne         $t6, $zero, L_80062CF4
    if (ctx->r14 != 0) {
        // 0x80062C5C: lui         $v0, 0x8017
        ctx->r2 = S32(0X8017 << 16);
            goto L_80062CF4;
    }
    // 0x80062C5C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80062C60: addiu       $v0, $v0, 0x37E0
    ctx->r2 = ADD32(ctx->r2, 0X37E0);
    // 0x80062C64: lbu         $t7, 0x0($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X0);
L_80062C68:
    // 0x80062C68: bne         $t7, $zero, L_80062CE8
    if (ctx->r15 != 0) {
        // 0x80062C6C: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_80062CE8;
    }
    // 0x80062C6C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80062C70: jal         0x80061474
    // 0x80062C74: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    Effect_Initialize(rdram, ctx);
        goto after_0;
    // 0x80062C74: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80062C78: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80062C7C: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80062C80: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80062C84: addiu       $t9, $zero, 0x15D
    ctx->r25 = ADD32(0, 0X15D);
    // 0x80062C88: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80062C8C: sb          $t8, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r24;
    // 0x80062C90: sh          $t9, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r25;
    // 0x80062C94: swc1        $f4, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f4.u32l;
    // 0x80062C98: lwc1        $f6, 0x7940($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7940);
    // 0x80062C9C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80062CA0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80062CA4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80062CA8: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80062CAC: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80062CB0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80062CB4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80062CB8: swc1        $f16, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f16.u32l;
    // 0x80062CBC: swc1        $f10, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f10.u32l;
    // 0x80062CC0: swc1        $f18, 0x70($a2)
    MEM_W(0X70, ctx->r6) = ctx->f18.u32l;
    // 0x80062CC4: lwc1        $f4, 0x64A4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X64A4);
    // 0x80062CC8: addiu       $t0, $zero, 0x78
    ctx->r8 = ADD32(0, 0X78);
    // 0x80062CCC: andi        $a1, $t9, 0xFFFF
    ctx->r5 = ctx->r25 & 0XFFFF;
    // 0x80062CD0: sh          $t0, 0x44($a2)
    MEM_H(0X44, ctx->r6) = ctx->r8;
    // 0x80062CD4: addiu       $a0, $a2, 0x1C
    ctx->r4 = ADD32(ctx->r6, 0X1C);
    // 0x80062CD8: jal         0x800612B8
    // 0x80062CDC: swc1        $f4, 0x6C($a2)
    MEM_W(0X6C, ctx->r6) = ctx->f4.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_1;
    // 0x80062CDC: swc1        $f4, 0x6C($a2)
    MEM_W(0X6C, ctx->r6) = ctx->f4.u32l;
    after_1:
    // 0x80062CE0: b           L_80062CF8
    // 0x80062CE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80062CF8;
    // 0x80062CE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80062CE8:
    // 0x80062CE8: addiu       $a2, $a2, 0x8C
    ctx->r6 = ADD32(ctx->r6, 0X8C);
    // 0x80062CEC: bnel        $a2, $v0, L_80062C68
    if (ctx->r6 != ctx->r2) {
        // 0x80062CF0: lbu         $t7, 0x0($a2)
        ctx->r15 = MEM_BU(ctx->r6, 0X0);
            goto L_80062C68;
    }
    goto skip_0;
    // 0x80062CF0: lbu         $t7, 0x0($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X0);
    skip_0:
L_80062CF4:
    // 0x80062CF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80062CF8:
    // 0x80062CF8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80062CFC: jr          $ra
    // 0x80062D00: nop

    return;
    // 0x80062D00: nop

;}
RECOMP_FUNC void HUD_DrawBossHealth(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008DE68: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8008DE6C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8008DE70: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8008DE74: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x8008DE78: lw          $t6, 0x1734($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1734);
    // 0x8008DE7C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8008DE80: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x8008DE84: bnel        $t6, $at, L_8008E28C
    if (ctx->r14 != ctx->r1) {
        // 0x8008DE88: mtc1        $zero, $f14
        ctx->f14.u32l = 0;
            goto L_8008E28C;
    }
    goto skip_0;
    // 0x8008DE88: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    skip_0:
    // 0x8008DE8C: lw          $t7, 0x78B8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X78B8);
    // 0x8008DE90: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x8008DE94: blezl       $t7, L_8008E28C
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8008DE98: mtc1        $zero, $f14
        ctx->f14.u32l = 0;
            goto L_8008E28C;
    }
    goto skip_1;
    // 0x8008DE98: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    skip_1:
    // 0x8008DE9C: lw          $t8, 0x7848($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7848);
    // 0x8008DEA0: bltz        $t8, L_8008DEFC
    if (SIGNED(ctx->r24) < 0) {
        // 0x8008DEA4: lui         $at, 0xBF80
        ctx->r1 = S32(0XBF80 << 16);
            goto L_8008DEFC;
    }
    // 0x8008DEA4: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8008DEA8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8008DEAC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008DEB0: lwc1        $f6, 0x16BC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X16BC);
    // 0x8008DEB4: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8008DEB8: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x8008DEBC: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x8008DEC0: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x8008DEC4: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8008DEC8: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x8008DECC: bc1f        L_8008DEFC
    if (!c1cs) {
        // 0x8008DED0: ori         $a0, $a0, 0xC028
        ctx->r4 = ctx->r4 | 0XC028;
            goto L_8008DEFC;
    }
    // 0x8008DED0: ori         $a0, $a0, 0xC028
    ctx->r4 = ctx->r4 | 0XC028;
    // 0x8008DED4: lui         $t9, 0x800C
    ctx->r25 = S32(0X800C << 16);
    // 0x8008DED8: addiu       $t9, $t9, 0x5D3C
    ctx->r25 = ADD32(ctx->r25, 0X5D3C);
    // 0x8008DEDC: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8008DEE0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8008DEE4: jal         0x80019218
    // 0x8008DEE8: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    Audio_PlaySfx(rdram, ctx);
        goto after_0;
    // 0x8008DEE8: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_0:
    // 0x8008DEEC: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x8008DEF0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8008DEF4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008DEF8: swc1        $f8, 0x16BC($at)
    MEM_W(0X16BC, ctx->r1) = ctx->f8.u32l;
L_8008DEFC:
    // 0x8008DEFC: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8008DF00: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8008DF04: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8008DF08: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x8008DF0C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8008DF10: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x8008DF14: addiu       $a0, $a0, 0x16C0
    ctx->r4 = ADD32(ctx->r4, 0X16C0);
    // 0x8008DF18: lui         $a1, 0x41C8
    ctx->r5 = S32(0X41C8 << 16);
    // 0x8008DF1C: jal         0x8009BC2C
    // 0x8008DF20: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_1;
    // 0x8008DF20: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x8008DF24: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008DF28: lwc1        $f10, 0x16C0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X16C0);
    // 0x8008DF2C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8008DF30: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x8008DF34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8008DF38: addiu       $a1, $zero, 0x4E
    ctx->r5 = ADD32(0, 0X4E);
    // 0x8008DF3C: jal         0x800B8DD0
    // 0x8008DF40: swc1        $f10, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f10.u32l;
    RCP_SetupDL(rdram, ctx);
        goto after_2;
    // 0x8008DF40: swc1        $f10, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f10.u32l;
    after_2:
    // 0x8008DF44: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8008DF48: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8008DF4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8008DF50: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8008DF54: lui         $t1, 0xFA00
    ctx->r9 = S32(0XFA00 << 16);
    // 0x8008DF58: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x8008DF5C: addiu       $t0, $v0, 0x8
    ctx->r8 = ADD32(ctx->r2, 0X8);
    // 0x8008DF60: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x8008DF64: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x8008DF68: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x8008DF6C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8008DF70: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8008DF74: lui         $at, 0x4250
    ctx->r1 = S32(0X4250 << 16);
    // 0x8008DF78: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8008DF7C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8008DF80: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8008DF84: lwc1        $f16, 0x3C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8008DF88: lui         $a1, 0x101
    ctx->r5 = S32(0X101 << 16);
    // 0x8008DF8C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8008DF90: lui         $a2, 0x101
    ctx->r6 = S32(0X101 << 16);
    // 0x8008DF94: addiu       $t3, $zero, 0x7
    ctx->r11 = ADD32(0, 0X7);
    // 0x8008DF98: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8008DF9C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8008DFA0: addiu       $a2, $a2, 0x1AB0
    ctx->r6 = ADD32(ctx->r6, 0X1AB0);
    // 0x8008DFA4: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x8008DFA8: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x8008DFAC: addiu       $a1, $a1, 0x1A40
    ctx->r5 = ADD32(ctx->r5, 0X1A40);
    // 0x8008DFB0: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    // 0x8008DFB4: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x8008DFB8: jal         0x8009C320
    // 0x8008DFBC: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    Lib_TextureRect_CI4(rdram, ctx);
        goto after_3;
    // 0x8008DFBC: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    after_3:
    // 0x8008DFC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8008DFC4: jal         0x800B8DD0
    // 0x8008DFC8: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    RCP_SetupDL(rdram, ctx);
        goto after_4;
    // 0x8008DFC8: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    after_4:
    // 0x8008DFCC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8008DFD0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8008DFD4: lui         $at, 0x4250
    ctx->r1 = S32(0X4250 << 16);
    // 0x8008DFD8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8008DFDC: lwc1        $f16, 0x3C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8008DFE0: lui         $a1, 0x100
    ctx->r5 = S32(0X100 << 16);
    // 0x8008DFE4: addiu       $a1, $a1, 0x2040
    ctx->r5 = ADD32(ctx->r5, 0X2040);
    // 0x8008DFE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8008DFEC: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    // 0x8008DFF0: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    // 0x8008DFF4: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x8008DFF8: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x8008DFFC: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x8008E000: jal         0x8009D994
    // 0x8008E004: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_5;
    // 0x8008E004: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_5:
    // 0x8008E008: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x8008E00C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8008E010: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8008E014: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8008E018: lui         $a1, 0x3F61
    ctx->r5 = S32(0X3F61 << 16);
    // 0x8008E01C: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x8008E020: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x8008E024: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x8008E028: ori         $a1, $a1, 0x47AE
    ctx->r5 = ctx->r5 | 0X47AE;
    // 0x8008E02C: bc1f        L_8008E04C
    if (!c1cs) {
        // 0x8008E030: addiu       $a0, $a0, 0x16C4
        ctx->r4 = ADD32(ctx->r4, 0X16C4);
            goto L_8008E04C;
    }
    // 0x8008E030: addiu       $a0, $a0, 0x16C4
    ctx->r4 = ADD32(ctx->r4, 0X16C4);
    // 0x8008E034: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8008E038: lwc1        $f8, 0x7DB4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7DB4);
    // 0x8008E03C: lui         $a3, 0x3E4C
    ctx->r7 = S32(0X3E4C << 16);
    // 0x8008E040: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x8008E044: jal         0x8009BC2C
    // 0x8008E048: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_6;
    // 0x8008E048: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_6:
L_8008E04C:
    // 0x8008E04C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008E050: lwc1        $f10, 0x16C4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X16C4);
    // 0x8008E054: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8008E058: lwc1        $f16, 0x7DB8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7DB8);
    // 0x8008E05C: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x8008E060: lwc1        $f18, 0x3C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8008E064: c.le.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl <= ctx->f10.fl;
    // 0x8008E068: nop

    // 0x8008E06C: bc1fl       L_8008E11C
    if (!c1cs) {
        // 0x8008E070: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8008E11C;
    }
    goto skip_2;
    // 0x8008E070: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x8008E074: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8008E078: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8008E07C: c.le.s      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.fl <= ctx->f18.fl;
    // 0x8008E080: nop

    // 0x8008E084: bc1fl       L_8008E11C
    if (!c1cs) {
        // 0x8008E088: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8008E11C;
    }
    goto skip_3;
    // 0x8008E088: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_3:
    // 0x8008E08C: jal         0x800B8DD0
    // 0x8008E090: addiu       $a1, $zero, 0x4E
    ctx->r5 = ADD32(0, 0X4E);
    RCP_SetupDL(rdram, ctx);
        goto after_7;
    // 0x8008E090: addiu       $a1, $zero, 0x4E
    ctx->r5 = ADD32(0, 0X4E);
    after_7:
    // 0x8008E094: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8008E098: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x8008E09C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8008E0A0: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x8008E0A4: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x8008E0A8: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8008E0AC: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8008E0B0: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x8008E0B4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8008E0B8: lui         $at, 0x4250
    ctx->r1 = S32(0X4250 << 16);
    // 0x8008E0BC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8008E0C0: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8008E0C4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8008E0C8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8008E0CC: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8008E0D0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8008E0D4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8008E0D8: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8008E0DC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008E0E0: lwc1        $f8, 0x16C4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X16C4);
    // 0x8008E0E4: lui         $a1, 0x101
    ctx->r5 = S32(0X101 << 16);
    // 0x8008E0E8: lui         $a2, 0x101
    ctx->r6 = S32(0X101 << 16);
    // 0x8008E0EC: addiu       $t7, $zero, 0x6D
    ctx->r15 = ADD32(0, 0X6D);
    // 0x8008E0F0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8008E0F4: addiu       $a2, $a2, 0x3090
    ctx->r6 = ADD32(ctx->r6, 0X3090);
    // 0x8008E0F8: addiu       $a1, $a1, 0x29C0
    ctx->r5 = ADD32(ctx->r5, 0X29C0);
    // 0x8008E0FC: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x8008E100: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    // 0x8008E104: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8008E108: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x8008E10C: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x8008E110: jal         0x8009D0BC
    // 0x8008E114: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    Lib_TextureRect_CI8(rdram, ctx);
        goto after_8;
    // 0x8008E114: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    after_8:
    // 0x8008E118: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8008E11C:
    // 0x8008E11C: jal         0x800B8DD0
    // 0x8008E120: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    RCP_SetupDL(rdram, ctx);
        goto after_9;
    // 0x8008E120: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    after_9:
    // 0x8008E124: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8008E128: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008E12C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8008E130: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x8008E134: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x8008E138: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8008E13C: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8008E140: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x8008E144: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8008E148: lwc1        $f2, 0x16BC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X16BC);
    // 0x8008E14C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8008E150: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x8008E154: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    // 0x8008E158: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8008E15C: addiu       $a0, $a0, 0x16C8
    ctx->r4 = ADD32(ctx->r4, 0X16C8);
    // 0x8008E160: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8008E164: bc1f        L_8008E1E0
    if (!c1cs) {
        // 0x8008E168: lui         $a3, 0x447A
        ctx->r7 = S32(0X447A << 16);
            goto L_8008E1E0;
    }
    // 0x8008E168: lui         $a3, 0x447A
    ctx->r7 = S32(0X447A << 16);
    // 0x8008E16C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8008E170: lwc1        $f12, 0x7DBC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X7DBC);
    // 0x8008E174: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x8008E178: lw          $t1, 0x7848($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7848);
    // 0x8008E17C: div.s       $f4, $f12, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = DIV_S(ctx->f12.fl, ctx->f2.fl);
    // 0x8008E180: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8008E184: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x8008E188: nop

    // 0x8008E18C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8008E190: sub.s       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f2.fl - ctx->f16.fl;
    // 0x8008E194: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8008E198: mul.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8008E19C: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x8008E1A0: nop

    // 0x8008E1A4: bc1fl       L_8008E1B4
    if (!c1cs) {
        // 0x8008E1A8: c.lt.s      $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
            goto L_8008E1B4;
    }
    goto skip_4;
    // 0x8008E1A8: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    skip_4:
    // 0x8008E1AC: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x8008E1B0: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
L_8008E1B4:
    // 0x8008E1B4: nop

    // 0x8008E1B8: bc1f        L_8008E1C4
    if (!c1cs) {
        // 0x8008E1BC: nop
    
            goto L_8008E1C4;
    }
    // 0x8008E1BC: nop

    // 0x8008E1C0: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_8008E1C4:
    // 0x8008E1C4: lwc1        $f6, 0x7DC0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7DC0);
    // 0x8008E1C8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8008E1CC: jal         0x8009BC2C
    // 0x8008E1D0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_10;
    // 0x8008E1D0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_10:
    // 0x8008E1D4: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8008E1D8: b           L_8008E1EC
    // 0x8008E1DC: nop

        goto L_8008E1EC;
    // 0x8008E1DC: nop

L_8008E1E0:
    // 0x8008E1E0: lwc1        $f12, 0x7DC4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X7DC4);
    // 0x8008E1E4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008E1E8: swc1        $f12, 0x16C8($at)
    MEM_W(0X16C8, ctx->r1) = ctx->f12.u32l;
L_8008E1EC:
    // 0x8008E1EC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008E1F0: lwc1        $f8, 0x16C4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X16C4);
    // 0x8008E1F4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8008E1F8: lwc1        $f10, 0x7DC8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7DC8);
    // 0x8008E1FC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008E200: c.le.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl <= ctx->f8.fl;
    // 0x8008E204: nop

    // 0x8008E208: bc1fl       L_8008E2B8
    if (!c1cs) {
        // 0x8008E20C: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_8008E2B8;
    }
    goto skip_5;
    // 0x8008E20C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_5:
    // 0x8008E210: lwc1        $f0, 0x16C8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X16C8);
    // 0x8008E214: lui         $at, 0x42CA
    ctx->r1 = S32(0X42CA << 16);
    // 0x8008E218: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8008E21C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8008E220: lwc1        $f18, 0x7DCC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7DCC);
    // 0x8008E224: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x8008E228: lui         $at, 0x4250
    ctx->r1 = S32(0X4250 << 16);
    // 0x8008E22C: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8008E230: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8008E234: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8008E238: addiu       $a1, $a1, -0x6608
    ctx->r5 = ADD32(ctx->r5, -0X6608);
    // 0x8008E23C: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8008E240: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8008E244: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x8008E248: sub.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x8008E24C: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    // 0x8008E250: lwc1        $f10, 0x3C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8008E254: bc1f        L_8008E2B4
    if (!c1cs) {
        // 0x8008E258: add.s       $f2, $f6, $f8
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f6.fl + ctx->f8.fl;
            goto L_8008E2B4;
    }
    // 0x8008E258: add.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8008E25C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8008E260: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8008E264: lwc1        $f4, 0x7DD0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7DD0);
    // 0x8008E268: add.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8008E26C: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    // 0x8008E270: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x8008E274: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x8008E278: jal         0x8009D418
    // 0x8008E27C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    Lib_TextureRect_RGBA16(rdram, ctx);
        goto after_11;
    // 0x8008E27C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_11:
    // 0x8008E280: b           L_8008E2B8
    // 0x8008E284: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_8008E2B8;
    // 0x8008E284: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8008E288: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
L_8008E28C:
    // 0x8008E28C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008E290: swc1        $f14, 0x16C0($at)
    MEM_W(0X16C0, ctx->r1) = ctx->f14.u32l;
    // 0x8008E294: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008E298: swc1        $f14, 0x16C4($at)
    MEM_W(0X16C4, ctx->r1) = ctx->f14.u32l;
    // 0x8008E29C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008E2A0: swc1        $f14, 0x16C8($at)
    MEM_W(0X16C8, ctx->r1) = ctx->f14.u32l;
    // 0x8008E2A4: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8008E2A8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8008E2AC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008E2B0: swc1        $f6, 0x16BC($at)
    MEM_W(0X16BC, ctx->r1) = ctx->f6.u32l;
L_8008E2B4:
    // 0x8008E2B4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_8008E2B8:
    // 0x8008E2B8: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8008E2BC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8008E2C0: jr          $ra
    // 0x8008E2C4: nop

    return;
    // 0x8008E2C4: nop

;}
RECOMP_FUNC void func_8000FC7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000FC7C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8000FC80: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8000FC84: jr          $ra
    // 0x8000FC88: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8000FC88: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void AudioLoad_SyncLoadInstrument(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000EE14: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8000EE18: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000EE1C: slti        $at, $a1, 0x7F
    ctx->r1 = SIGNED(ctx->r5) < 0X7F ? 1 : 0;
    // 0x8000EE20: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8000EE24: beq         $at, $zero, L_8000EE9C
    if (ctx->r1 == 0) {
        // 0x8000EE28: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_8000EE9C;
    }
    // 0x8000EE28: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8000EE2C: jal         0x80011D4C
    // 0x8000EE30: nop

    Audio_GetInstrument(rdram, ctx);
        goto after_0;
    // 0x8000EE30: nop

    after_0:
    // 0x8000EE34: bne         $v0, $zero, L_8000EE44
    if (ctx->r2 != 0) {
        // 0x8000EE38: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8000EE44;
    }
    // 0x8000EE38: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8000EE3C: b           L_8000EED0
    // 0x8000EE40: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8000EED0;
    // 0x8000EE40: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8000EE44:
    // 0x8000EE44: lbu         $t6, 0x1($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X1);
    // 0x8000EE48: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8000EE4C: beql        $t6, $zero, L_8000EE68
    if (ctx->r14 == 0) {
        // 0x8000EE50: lw          $a0, 0x10($v1)
        ctx->r4 = MEM_W(ctx->r3, 0X10);
            goto L_8000EE68;
    }
    goto skip_0;
    // 0x8000EE50: lw          $a0, 0x10($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X10);
    skip_0:
    // 0x8000EE54: lw          $a0, 0x8($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X8);
    // 0x8000EE58: jal         0x8000ED28
    // 0x8000EE5C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    AudioLoad_SyncLoadSample(rdram, ctx);
        goto after_1;
    // 0x8000EE5C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_1:
    // 0x8000EE60: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8000EE64: lw          $a0, 0x10($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X10);
L_8000EE68:
    // 0x8000EE68: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x8000EE6C: jal         0x8000ED28
    // 0x8000EE70: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    AudioLoad_SyncLoadSample(rdram, ctx);
        goto after_2;
    // 0x8000EE70: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x8000EE74: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8000EE78: addiu       $at, $zero, 0x7F
    ctx->r1 = ADD32(0, 0X7F);
    // 0x8000EE7C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8000EE80: lbu         $t7, 0x2($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X2);
    // 0x8000EE84: beql        $t7, $at, L_8000EED4
    if (ctx->r15 == ctx->r1) {
        // 0x8000EE88: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8000EED4;
    }
    goto skip_1;
    // 0x8000EE88: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8000EE8C: jal         0x8000ED28
    // 0x8000EE90: lw          $a0, 0x18($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X18);
    AudioLoad_SyncLoadSample(rdram, ctx);
        goto after_3;
    // 0x8000EE90: lw          $a0, 0x18($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X18);
    after_3:
    // 0x8000EE94: b           L_8000EED4
    // 0x8000EE98: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8000EED4;
    // 0x8000EE98: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8000EE9C:
    // 0x8000EE9C: addiu       $at, $zero, 0x7F
    ctx->r1 = ADD32(0, 0X7F);
    // 0x8000EEA0: bne         $a1, $at, L_8000EED0
    if (ctx->r5 != ctx->r1) {
        // 0x8000EEA4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8000EED0;
    }
    // 0x8000EEA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8000EEA8: jal         0x80011DFC
    // 0x8000EEAC: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    Audio_GetDrum(rdram, ctx);
        goto after_4;
    // 0x8000EEAC: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_4:
    // 0x8000EEB0: bne         $v0, $zero, L_8000EEC0
    if (ctx->r2 != 0) {
        // 0x8000EEB4: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8000EEC0;
    }
    // 0x8000EEB4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8000EEB8: b           L_8000EED0
    // 0x8000EEBC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8000EED0;
    // 0x8000EEBC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8000EEC0:
    // 0x8000EEC0: lw          $a0, 0x4($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X4);
    // 0x8000EEC4: jal         0x8000ED28
    // 0x8000EEC8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    AudioLoad_SyncLoadSample(rdram, ctx);
        goto after_5;
    // 0x8000EEC8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_5:
    // 0x8000EECC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000EED0:
    // 0x8000EED0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8000EED4:
    // 0x8000EED4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000EED8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8000EEDC: jr          $ra
    // 0x8000EEE0: nop

    return;
    // 0x8000EEE0: nop

;}
RECOMP_FUNC void Lights_SetTwoLights(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800038AC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800038B0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800038B4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800038B8: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800038BC: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x800038C0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800038C4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800038C8: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800038CC: addiu       $v1, $v1, 0x7E6C
    ctx->r3 = ADD32(ctx->r3, 0X7E6C);
    // 0x800038D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800038D4: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x800038D8: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x800038DC: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
L_800038E0:
    // 0x800038E0: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800038E4: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800038E8: sb          $s0, 0x10($t7)
    MEM_B(0X10, ctx->r15) = ctx->r16;
    // 0x800038EC: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800038F0: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x800038F4: sb          $s1, 0x11($t9)
    MEM_B(0X11, ctx->r25) = ctx->r17;
    // 0x800038F8: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x800038FC: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x80003900: sb          $a3, 0x12($t4)
    MEM_B(0X12, ctx->r12) = ctx->r7;
    // 0x80003904: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x80003908: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x8000390C: sb          $a0, 0x8($t6)
    MEM_B(0X8, ctx->r14) = ctx->r4;
    // 0x80003910: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80003914: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x80003918: sb          $a1, 0x9($t8)
    MEM_B(0X9, ctx->r24) = ctx->r5;
    // 0x8000391C: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x80003920: addu        $t3, $t9, $v0
    ctx->r11 = ADD32(ctx->r25, ctx->r2);
    // 0x80003924: sb          $a2, 0xA($t3)
    MEM_B(0XA, ctx->r11) = ctx->r6;
    // 0x80003928: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x8000392C: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x80003930: sb          $a0, 0xC($t5)
    MEM_B(0XC, ctx->r13) = ctx->r4;
    // 0x80003934: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80003938: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x8000393C: sb          $a1, 0xD($t7)
    MEM_B(0XD, ctx->r15) = ctx->r5;
    // 0x80003940: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x80003944: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x80003948: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8000394C: slti        $at, $v0, 0x40
    ctx->r1 = SIGNED(ctx->r2) < 0X40 ? 1 : 0;
    // 0x80003950: bne         $at, $zero, L_800038E0
    if (ctx->r1 != 0) {
        // 0x80003954: sb          $a2, 0xE($t9)
        MEM_B(0XE, ctx->r25) = ctx->r6;
            goto L_800038E0;
    }
    // 0x80003954: sb          $a2, 0xE($t9)
    MEM_B(0XE, ctx->r25) = ctx->r6;
    // 0x80003958: addiu       $v0, $zero, 0x40
    ctx->r2 = ADD32(0, 0X40);
    // 0x8000395C: addiu       $t2, $zero, 0x70
    ctx->r10 = ADD32(0, 0X70);
    // 0x80003960: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x80003964: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x80003968: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x8000396C: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x80003970: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x80003974: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
L_80003978:
    // 0x80003978: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x8000397C: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x80003980: sb          $a3, 0x10($t4)
    MEM_B(0X10, ctx->r12) = ctx->r7;
    // 0x80003984: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x80003988: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x8000398C: sb          $t0, 0x11($t6)
    MEM_B(0X11, ctx->r14) = ctx->r8;
    // 0x80003990: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80003994: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x80003998: sb          $t1, 0x12($t8)
    MEM_B(0X12, ctx->r24) = ctx->r9;
    // 0x8000399C: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800039A0: addu        $t3, $t9, $v0
    ctx->r11 = ADD32(ctx->r25, ctx->r2);
    // 0x800039A4: sb          $a0, 0x8($t3)
    MEM_B(0X8, ctx->r11) = ctx->r4;
    // 0x800039A8: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800039AC: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x800039B0: sb          $a1, 0x9($t5)
    MEM_B(0X9, ctx->r13) = ctx->r5;
    // 0x800039B4: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800039B8: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800039BC: sb          $a2, 0xA($t7)
    MEM_B(0XA, ctx->r15) = ctx->r6;
    // 0x800039C0: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800039C4: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x800039C8: sb          $a0, 0xC($t9)
    MEM_B(0XC, ctx->r25) = ctx->r4;
    // 0x800039CC: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x800039D0: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x800039D4: sb          $a1, 0xD($t4)
    MEM_B(0XD, ctx->r12) = ctx->r5;
    // 0x800039D8: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x800039DC: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x800039E0: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800039E4: bne         $v0, $t2, L_80003978
    if (ctx->r2 != ctx->r10) {
        // 0x800039E8: sb          $a2, 0xE($t6)
        MEM_B(0XE, ctx->r14) = ctx->r6;
            goto L_80003978;
    }
    // 0x800039E8: sb          $a2, 0xE($t6)
    MEM_B(0XE, ctx->r14) = ctx->r6;
    // 0x800039EC: lw          $v0, 0x54($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X54);
    // 0x800039F0: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800039F4: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x800039F8: lw          $a2, 0x5C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X5C);
    // 0x800039FC: sb          $v0, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r2;
    // 0x80003A00: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x80003A04: sb          $a1, 0x1($t8)
    MEM_B(0X1, ctx->r24) = ctx->r5;
    // 0x80003A08: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x80003A0C: sb          $a2, 0x2($t9)
    MEM_B(0X2, ctx->r25) = ctx->r6;
    // 0x80003A10: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x80003A14: sb          $v0, 0x4($t3)
    MEM_B(0X4, ctx->r11) = ctx->r2;
    // 0x80003A18: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x80003A1C: sb          $a1, 0x5($t4)
    MEM_B(0X5, ctx->r12) = ctx->r5;
    // 0x80003A20: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x80003A24: sb          $a2, 0x6($t5)
    MEM_B(0X6, ctx->r13) = ctx->r6;
    // 0x80003A28: jal         0x800035D0
    // 0x80003A2C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    Lights_AddLight(rdram, ctx);
        goto after_0;
    // 0x80003A2C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_0:
    // 0x80003A30: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80003A34: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80003A38: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80003A3C: jr          $ra
    // 0x80003A40: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80003A40: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void Player_Shoot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AD7F0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800AD7F4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800AD7F8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800AD7FC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800AD800: lw          $v0, 0x1CC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1CC);
    // 0x800AD804: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800AD808: beql        $v0, $zero, L_800AD82C
    if (ctx->r2 == 0) {
        // 0x800AD80C: lbu         $t6, 0x49C($s0)
        ctx->r14 = MEM_BU(ctx->r16, 0X49C);
            goto L_800AD82C;
    }
    goto skip_0;
    // 0x800AD80C: lbu         $t6, 0x49C($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X49C);
    skip_0:
    // 0x800AD810: beq         $v0, $at, L_800AD960
    if (ctx->r2 == ctx->r1) {
        // 0x800AD814: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800AD960;
    }
    // 0x800AD814: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800AD818: beq         $v0, $at, L_800AD9B0
    if (ctx->r2 == ctx->r1) {
        // 0x800AD81C: lui         $t6, 0x8017
        ctx->r14 = S32(0X8017 << 16);
            goto L_800AD9B0;
    }
    // 0x800AD81C: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x800AD820: b           L_800ADA18
    // 0x800AD824: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800ADA18;
    // 0x800AD824: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800AD828: lbu         $t6, 0x49C($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X49C);
L_800AD82C:
    // 0x800AD82C: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x800AD830: bnel        $at, $zero, L_800AD84C
    if (ctx->r1 != 0) {
        // 0x800AD834: lw          $t8, 0x1C4($s0)
        ctx->r24 = MEM_W(ctx->r16, 0X1C4);
            goto L_800AD84C;
    }
    goto skip_1;
    // 0x800AD834: lw          $t8, 0x1C4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X1C4);
    skip_1:
    // 0x800AD838: lbu         $t7, 0x49D($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X49D);
    // 0x800AD83C: slti        $at, $t7, 0x2
    ctx->r1 = SIGNED(ctx->r15) < 0X2 ? 1 : 0;
    // 0x800AD840: beq         $at, $zero, L_800AD85C
    if (ctx->r1 == 0) {
        // 0x800AD844: nop
    
            goto L_800AD85C;
    }
    // 0x800AD844: nop

    // 0x800AD848: lw          $t8, 0x1C4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X1C4);
L_800AD84C:
    // 0x800AD84C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800AD850: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800AD854: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800AD858: sw          $zero, 0x1AA8($at)
    MEM_W(0X1AA8, ctx->r1) = 0;
L_800AD85C:
    // 0x800AD85C: jal         0x800AD1F4
    // 0x800AD860: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_UpdateLockOn(rdram, ctx);
        goto after_0;
    // 0x800AD860: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800AD864: bne         $v0, $zero, L_800ADA14
    if (ctx->r2 != 0) {
        // 0x800AD868: lui         $t0, 0x8017
        ctx->r8 = S32(0X8017 << 16);
            goto L_800ADA14;
    }
    // 0x800AD868: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x800AD86C: lw          $t0, 0x78A0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X78A0);
    // 0x800AD870: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x800AD874: lui         $a1, 0xC120
    ctx->r5 = S32(0XC120 << 16);
    // 0x800AD878: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x800AD87C: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x800AD880: lw          $t2, 0x1AA8($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X1AA8);
    // 0x800AD884: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x800AD888: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    // 0x800AD88C: blez        $t2, L_800AD8AC
    if (SIGNED(ctx->r10) <= 0) {
        // 0x800AD890: addiu       $a0, $s0, 0x4B0
        ctx->r4 = ADD32(ctx->r16, 0X4B0);
            goto L_800AD8AC;
    }
    // 0x800AD890: addiu       $a0, $s0, 0x4B0
    ctx->r4 = ADD32(ctx->r16, 0X4B0);
    // 0x800AD894: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800AD898: addiu       $a0, $s0, 0x4B0
    ctx->r4 = ADD32(ctx->r16, 0X4B0);
    // 0x800AD89C: jal         0x8009BC2C
    // 0x800AD8A0: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_1;
    // 0x800AD8A0: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x800AD8A4: b           L_800AD8C8
    // 0x800AD8A8: lw          $t3, 0x1C4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X1C4);
        goto L_800AD8C8;
    // 0x800AD8A8: lw          $t3, 0x1C4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X1C4);
L_800AD8AC:
    // 0x800AD8AC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800AD8B0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x800AD8B4: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    // 0x800AD8B8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800AD8BC: jal         0x8009BC2C
    // 0x800AD8C0: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_2;
    // 0x800AD8C0: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x800AD8C4: lw          $t3, 0x1C4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X1C4);
L_800AD8C8:
    // 0x800AD8C8: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x800AD8CC: lw          $t6, 0x797C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X797C);
    // 0x800AD8D0: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x800AD8D4: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x800AD8D8: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x800AD8DC: lhu         $t5, 0x7938($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0X7938);
    // 0x800AD8E0: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x800AD8E4: and         $t8, $t5, $t7
    ctx->r24 = ctx->r13 & ctx->r15;
    // 0x800AD8E8: beql        $t8, $zero, L_800AD904
    if (ctx->r24 == 0) {
        // 0x800AD8EC: lw          $v0, 0x244($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X244);
            goto L_800AD904;
    }
    goto skip_2;
    // 0x800AD8EC: lw          $v0, 0x244($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X244);
    skip_2:
    // 0x800AD8F0: jal         0x800ACABC
    // 0x800AD8F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_ArwingLaser(rdram, ctx);
        goto after_3;
    // 0x800AD8F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x800AD8F8: addiu       $t9, $zero, 0x8
    ctx->r25 = ADD32(0, 0X8);
    // 0x800AD8FC: sw          $t9, 0x244($s0)
    MEM_W(0X244, ctx->r16) = ctx->r25;
    // 0x800AD900: lw          $v0, 0x244($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X244);
L_800AD904:
    // 0x800AD904: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x800AD908: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x800AD90C: beq         $v0, $zero, L_800AD950
    if (ctx->r2 == 0) {
        // 0x800AD910: addiu       $t0, $v0, -0x1
        ctx->r8 = ADD32(ctx->r2, -0X1);
            goto L_800AD950;
    }
    // 0x800AD910: addiu       $t0, $v0, -0x1
    ctx->r8 = ADD32(ctx->r2, -0X1);
    // 0x800AD914: lw          $t1, 0x1C4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X1C4);
    // 0x800AD918: sw          $t0, 0x244($s0)
    MEM_W(0X244, ctx->r16) = ctx->r8;
    // 0x800AD91C: lw          $t4, 0x7974($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7974);
    // 0x800AD920: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x800AD924: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x800AD928: lhu         $t3, 0x7938($t3)
    ctx->r11 = MEM_HU(ctx->r11, 0X7938);
    // 0x800AD92C: lhu         $t6, 0x0($t4)
    ctx->r14 = MEM_HU(ctx->r12, 0X0);
    // 0x800AD930: andi        $t8, $t0, 0x3
    ctx->r24 = ctx->r8 & 0X3;
    // 0x800AD934: and         $t5, $t3, $t6
    ctx->r13 = ctx->r11 & ctx->r14;
    // 0x800AD938: beq         $t5, $zero, L_800AD950
    if (ctx->r13 == 0) {
        // 0x800AD93C: nop
    
            goto L_800AD950;
    }
    // 0x800AD93C: nop

    // 0x800AD940: bne         $t8, $zero, L_800AD950
    if (ctx->r24 != 0) {
        // 0x800AD944: nop
    
            goto L_800AD950;
    }
    // 0x800AD944: nop

    // 0x800AD948: jal         0x800ACABC
    // 0x800AD94C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_ArwingLaser(rdram, ctx);
        goto after_4;
    // 0x800AD94C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
L_800AD950:
    // 0x800AD950: jal         0x800ACC7C
    // 0x800AD954: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_SmartBomb(rdram, ctx);
        goto after_5;
    // 0x800AD954: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x800AD958: b           L_800ADA18
    // 0x800AD95C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800ADA18;
    // 0x800AD95C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800AD960:
    // 0x800AD960: jal         0x800AD1F4
    // 0x800AD964: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_UpdateLockOn(rdram, ctx);
        goto after_6;
    // 0x800AD964: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x800AD968: bne         $v0, $zero, L_800ADA14
    if (ctx->r2 != 0) {
        // 0x800AD96C: lui         $t1, 0x8017
        ctx->r9 = S32(0X8017 << 16);
            goto L_800ADA14;
    }
    // 0x800AD96C: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x800AD970: lw          $t9, 0x1C4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1C4);
    // 0x800AD974: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x800AD978: lw          $t2, 0x797C($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X797C);
    // 0x800AD97C: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x800AD980: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x800AD984: lhu         $t1, 0x7938($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0X7938);
    // 0x800AD988: lhu         $t4, 0x0($t2)
    ctx->r12 = MEM_HU(ctx->r10, 0X0);
    // 0x800AD98C: and         $t3, $t1, $t4
    ctx->r11 = ctx->r9 & ctx->r12;
    // 0x800AD990: beq         $t3, $zero, L_800AD9A0
    if (ctx->r11 == 0) {
        // 0x800AD994: nop
    
            goto L_800AD9A0;
    }
    // 0x800AD994: nop

    // 0x800AD998: jal         0x800ACA40
    // 0x800AD99C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_TankCannon(rdram, ctx);
        goto after_7;
    // 0x800AD99C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
L_800AD9A0:
    // 0x800AD9A0: jal         0x800ACC7C
    // 0x800AD9A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_SmartBomb(rdram, ctx);
        goto after_8;
    // 0x800AD9A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x800AD9A8: b           L_800ADA18
    // 0x800AD9AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800ADA18;
    // 0x800AD9AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800AD9B0:
    // 0x800AD9B0: lw          $t6, 0x797C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X797C);
    // 0x800AD9B4: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x800AD9B8: lhu         $t5, 0x0($t6)
    ctx->r13 = MEM_HU(ctx->r14, 0X0);
    // 0x800AD9BC: andi        $t7, $t5, 0x8000
    ctx->r15 = ctx->r13 & 0X8000;
    // 0x800AD9C0: beq         $t7, $zero, L_800AD9CC
    if (ctx->r15 == 0) {
        // 0x800AD9C4: nop
    
            goto L_800AD9CC;
    }
    // 0x800AD9C4: nop

    // 0x800AD9C8: sw          $zero, 0x244($s0)
    MEM_W(0X244, ctx->r16) = 0;
L_800AD9CC:
    // 0x800AD9CC: lw          $t8, 0x7974($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7974);
    // 0x800AD9D0: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x800AD9D4: andi        $t0, $t9, 0x8000
    ctx->r8 = ctx->r25 & 0X8000;
    // 0x800AD9D8: beq         $t0, $zero, L_800ADA0C
    if (ctx->r8 == 0) {
        // 0x800AD9DC: nop
    
            goto L_800ADA0C;
    }
    // 0x800AD9DC: nop

    // 0x800AD9E0: lw          $v0, 0x244($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X244);
    // 0x800AD9E4: bnel        $v0, $zero, L_800AD9FC
    if (ctx->r2 != 0) {
        // 0x800AD9E8: addiu       $t2, $v0, 0x1
        ctx->r10 = ADD32(ctx->r2, 0X1);
            goto L_800AD9FC;
    }
    goto skip_3;
    // 0x800AD9E8: addiu       $t2, $v0, 0x1
    ctx->r10 = ADD32(ctx->r2, 0X1);
    skip_3:
    // 0x800AD9EC: jal         0x800AD094
    // 0x800AD9F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_OnFootGun(rdram, ctx);
        goto after_9;
    // 0x800AD9F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x800AD9F4: lw          $v0, 0x244($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X244);
    // 0x800AD9F8: addiu       $t2, $v0, 0x1
    ctx->r10 = ADD32(ctx->r2, 0X1);
L_800AD9FC:
    // 0x800AD9FC: slti        $at, $t2, 0x5
    ctx->r1 = SIGNED(ctx->r10) < 0X5 ? 1 : 0;
    // 0x800ADA00: bne         $at, $zero, L_800ADA0C
    if (ctx->r1 != 0) {
        // 0x800ADA04: sw          $t2, 0x244($s0)
        MEM_W(0X244, ctx->r16) = ctx->r10;
            goto L_800ADA0C;
    }
    // 0x800ADA04: sw          $t2, 0x244($s0)
    MEM_W(0X244, ctx->r16) = ctx->r10;
    // 0x800ADA08: sw          $zero, 0x244($s0)
    MEM_W(0X244, ctx->r16) = 0;
L_800ADA0C:
    // 0x800ADA0C: jal         0x800ACC7C
    // 0x800ADA10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_SmartBomb(rdram, ctx);
        goto after_10;
    // 0x800ADA10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
L_800ADA14:
    // 0x800ADA14: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800ADA18:
    // 0x800ADA18: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800ADA1C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800ADA20: jr          $ra
    // 0x800ADA24: nop

    return;
    // 0x800ADA24: nop

;}
RECOMP_FUNC void AudioHeap_AllocTemporarySampleCacheEntry(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000DD68: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8000DD6C: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x8000DD70: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8000DD74: addiu       $a0, $a0, -0x31A8
    ctx->r4 = ADD32(ctx->r4, -0X31A8);
    // 0x8000DD78: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8000DD7C: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8000DD80: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8000DD84: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x8000DD88: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x8000DD8C: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x8000DD90: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8000DD94: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8000DD98: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8000DD9C: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x8000DDA0: lw          $s3, 0x4($a0)
    ctx->r19 = MEM_W(ctx->r4, 0X4);
    // 0x8000DDA4: jal         0x8000BF14
    // 0x8000DDA8: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    AudioHeap_Alloc(rdram, ctx);
        goto after_0;
    // 0x8000DDA8: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    after_0:
    // 0x8000DDAC: bne         $v0, $zero, L_8000DDFC
    if (ctx->r2 != 0) {
        // 0x8000DDB0: sw          $v0, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r2;
            goto L_8000DDFC;
    }
    // 0x8000DDB0: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x8000DDB4: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x8000DDB8: lw          $t6, -0x31A8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X31A8);
    // 0x8000DDBC: lui         $s0, 0x8015
    ctx->r16 = S32(0X8015 << 16);
    // 0x8000DDC0: lw          $s0, -0x31A4($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X31A4);
    // 0x8000DDC4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8000DDC8: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8000DDCC: addiu       $a0, $a0, -0x31A8
    ctx->r4 = ADD32(ctx->r4, -0X31A8);
    // 0x8000DDD0: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x8000DDD4: jal         0x8000BF14
    // 0x8000DDD8: sw          $t6, -0x31A4($at)
    MEM_W(-0X31A4, ctx->r1) = ctx->r14;
    AudioHeap_Alloc(rdram, ctx);
        goto after_1;
    // 0x8000DDD8: sw          $t6, -0x31A4($at)
    MEM_W(-0X31A4, ctx->r1) = ctx->r14;
    after_1:
    // 0x8000DDDC: bne         $v0, $zero, L_8000DDF4
    if (ctx->r2 != 0) {
        // 0x8000DDE0: sw          $v0, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r2;
            goto L_8000DDF4;
    }
    // 0x8000DDE0: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x8000DDE4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8000DDE8: sw          $s0, -0x31A4($at)
    MEM_W(-0X31A4, ctx->r1) = ctx->r16;
    // 0x8000DDEC: b           L_8000DFD0
    // 0x8000DDF0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000DFD0;
    // 0x8000DDF0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000DDF4:
    // 0x8000DDF4: lui         $s3, 0x8015
    ctx->r19 = S32(0X8015 << 16);
    // 0x8000DDF8: lw          $s3, -0x31A8($s3)
    ctx->r19 = MEM_W(ctx->r19, -0X31A8);
L_8000DDFC:
    // 0x8000DDFC: lui         $a2, 0x8015
    ctx->r6 = S32(0X8015 << 16);
    // 0x8000DE00: lw          $a2, 0x3D04($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X3D04);
    // 0x8000DE04: lui         $s2, 0x8015
    ctx->r18 = S32(0X8015 << 16);
    // 0x8000DE08: lw          $s2, -0x31A4($s2)
    ctx->r18 = MEM_W(ctx->r18, -0X31A4);
    // 0x8000DE0C: addiu       $s5, $zero, -0x1
    ctx->r21 = ADD32(0, -0X1);
    // 0x8000DE10: blez        $a2, L_8000DEE4
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8000DE14: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_8000DEE4;
    }
    // 0x8000DE14: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8000DE18: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8000DE1C: addiu       $a1, $a1, 0x3300
    ctx->r5 = ADD32(ctx->r5, 0X3300);
    // 0x8000DE20: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
    // 0x8000DE24: lw          $t7, 0x10($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X10);
L_8000DE28:
    // 0x8000DE28: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x8000DE2C: addiu       $t6, $t6, 0x3300
    ctx->r14 = ADD32(ctx->r14, 0X3300);
    // 0x8000DE30: bnel        $t7, $zero, L_8000DEC4
    if (ctx->r15 != 0) {
        // 0x8000DE34: sll         $t5, $a2, 2
        ctx->r13 = S32(ctx->r6 << 2);
            goto L_8000DEC4;
    }
    goto skip_0;
    // 0x8000DE34: sll         $t5, $a2, 2
    ctx->r13 = S32(ctx->r6 << 2);
    skip_0:
    // 0x8000DE38: lw          $t8, 0x4($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X4);
    // 0x8000DE3C: lw          $v0, 0x8($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X8);
    // 0x8000DE40: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8000DE44: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8000DE48: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8000DE4C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8000DE50: and         $t0, $t9, $at
    ctx->r8 = ctx->r25 & ctx->r1;
    // 0x8000DE54: addu        $a0, $v0, $t0
    ctx->r4 = ADD32(ctx->r2, ctx->r8);
    // 0x8000DE58: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x8000DE5C: sltu        $at, $a0, $s3
    ctx->r1 = ctx->r4 < ctx->r19 ? 1 : 0;
    // 0x8000DE60: beq         $at, $zero, L_8000DE88
    if (ctx->r1 == 0) {
        // 0x8000DE64: sltu        $at, $v0, $s3
        ctx->r1 = ctx->r2 < ctx->r19 ? 1 : 0;
            goto L_8000DE88;
    }
    // 0x8000DE64: sltu        $at, $v0, $s3
    ctx->r1 = ctx->r2 < ctx->r19 ? 1 : 0;
    // 0x8000DE68: beq         $at, $zero, L_8000DE88
    if (ctx->r1 == 0) {
        // 0x8000DE6C: sll         $t1, $a2, 2
        ctx->r9 = S32(ctx->r6 << 2);
            goto L_8000DE88;
    }
    // 0x8000DE6C: sll         $t1, $a2, 2
    ctx->r9 = S32(ctx->r6 << 2);
    // 0x8000DE70: addu        $t1, $t1, $a2
    ctx->r9 = ADD32(ctx->r9, ctx->r6);
    // 0x8000DE74: lui         $t2, 0x8015
    ctx->r10 = S32(0X8015 << 16);
    // 0x8000DE78: addiu       $t2, $t2, 0x3300
    ctx->r10 = ADD32(ctx->r10, 0X3300);
    // 0x8000DE7C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8000DE80: b           L_8000DED0
    // 0x8000DE84: addu        $v0, $t1, $t2
    ctx->r2 = ADD32(ctx->r9, ctx->r10);
        goto L_8000DED0;
    // 0x8000DE84: addu        $v0, $t1, $t2
    ctx->r2 = ADD32(ctx->r9, ctx->r10);
L_8000DE88:
    // 0x8000DE88: sltu        $at, $a0, $s2
    ctx->r1 = ctx->r4 < ctx->r18 ? 1 : 0;
    // 0x8000DE8C: bne         $at, $zero, L_8000DEB4
    if (ctx->r1 != 0) {
        // 0x8000DE90: sltu        $at, $v1, $s2
        ctx->r1 = ctx->r3 < ctx->r18 ? 1 : 0;
            goto L_8000DEB4;
    }
    // 0x8000DE90: sltu        $at, $v1, $s2
    ctx->r1 = ctx->r3 < ctx->r18 ? 1 : 0;
    // 0x8000DE94: bne         $at, $zero, L_8000DEB4
    if (ctx->r1 != 0) {
        // 0x8000DE98: sll         $t3, $a2, 2
        ctx->r11 = S32(ctx->r6 << 2);
            goto L_8000DEB4;
    }
    // 0x8000DE98: sll         $t3, $a2, 2
    ctx->r11 = S32(ctx->r6 << 2);
    // 0x8000DE9C: addu        $t3, $t3, $a2
    ctx->r11 = ADD32(ctx->r11, ctx->r6);
    // 0x8000DEA0: lui         $t4, 0x8015
    ctx->r12 = S32(0X8015 << 16);
    // 0x8000DEA4: addiu       $t4, $t4, 0x3300
    ctx->r12 = ADD32(ctx->r12, 0X3300);
    // 0x8000DEA8: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8000DEAC: b           L_8000DED0
    // 0x8000DEB0: addu        $v0, $t3, $t4
    ctx->r2 = ADD32(ctx->r11, ctx->r12);
        goto L_8000DED0;
    // 0x8000DEB0: addu        $v0, $t3, $t4
    ctx->r2 = ADD32(ctx->r11, ctx->r12);
L_8000DEB4:
    // 0x8000DEB4: sw          $s7, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r23;
    // 0x8000DEB8: lui         $a2, 0x8015
    ctx->r6 = S32(0X8015 << 16);
    // 0x8000DEBC: lw          $a2, 0x3D04($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X3D04);
    // 0x8000DEC0: sll         $t5, $a2, 2
    ctx->r13 = S32(ctx->r6 << 2);
L_8000DEC4:
    // 0x8000DEC4: addu        $t5, $t5, $a2
    ctx->r13 = ADD32(ctx->r13, ctx->r6);
    // 0x8000DEC8: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8000DECC: addu        $v0, $t5, $t6
    ctx->r2 = ADD32(ctx->r13, ctx->r14);
L_8000DED0:
    // 0x8000DED0: addiu       $a1, $a1, 0x14
    ctx->r5 = ADD32(ctx->r5, 0X14);
    // 0x8000DED4: sltu        $at, $a1, $v0
    ctx->r1 = ctx->r5 < ctx->r2 ? 1 : 0;
    // 0x8000DED8: bnel        $at, $zero, L_8000DE28
    if (ctx->r1 != 0) {
        // 0x8000DEDC: lw          $t7, 0x10($a1)
        ctx->r15 = MEM_W(ctx->r5, 0X10);
            goto L_8000DE28;
    }
    goto skip_1;
    // 0x8000DEDC: lw          $t7, 0x10($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X10);
    skip_1:
    // 0x8000DEE0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8000DEE4:
    // 0x8000DEE4: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x8000DEE8: lw          $t7, -0x2C98($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2C98);
    // 0x8000DEEC: lui         $s0, 0x8015
    ctx->r16 = S32(0X8015 << 16);
    // 0x8000DEF0: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
    // 0x8000DEF4: blez        $t7, L_8000DF84
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8000DEF8: addiu       $s0, $s0, -0x31A8
        ctx->r16 = ADD32(ctx->r16, -0X31A8);
            goto L_8000DF84;
    }
    // 0x8000DEF8: addiu       $s0, $s0, -0x31A8
    ctx->r16 = ADD32(ctx->r16, -0X31A8);
    // 0x8000DEFC: addiu       $s6, $zero, -0x1
    ctx->r22 = ADD32(0, -0X1);
L_8000DF00:
    // 0x8000DF00: lb          $t8, 0x10($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X10);
    // 0x8000DF04: bnel        $t8, $zero, L_8000DF18
    if (ctx->r24 != 0) {
        // 0x8000DF08: lw          $v1, 0x18($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X18);
            goto L_8000DF18;
    }
    goto skip_2;
    // 0x8000DF08: lw          $v1, 0x18($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X18);
    skip_2:
    // 0x8000DF0C: b           L_8000DF74
    // 0x8000DF10: lw          $v0, 0x510($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X510);
        goto L_8000DF74;
    // 0x8000DF10: lw          $v0, 0x510($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X510);
    // 0x8000DF14: lw          $v1, 0x18($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X18);
L_8000DF18:
    // 0x8000DF18: lw          $t9, 0x20($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X20);
    // 0x8000DF1C: addu        $a0, $t9, $v1
    ctx->r4 = ADD32(ctx->r25, ctx->r3);
    // 0x8000DF20: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x8000DF24: sltu        $at, $a0, $s3
    ctx->r1 = ctx->r4 < ctx->r19 ? 1 : 0;
    // 0x8000DF28: beq         $at, $zero, L_8000DF40
    if (ctx->r1 == 0) {
        // 0x8000DF2C: sltu        $at, $v1, $s3
        ctx->r1 = ctx->r3 < ctx->r19 ? 1 : 0;
            goto L_8000DF40;
    }
    // 0x8000DF2C: sltu        $at, $v1, $s3
    ctx->r1 = ctx->r3 < ctx->r19 ? 1 : 0;
    // 0x8000DF30: beql        $at, $zero, L_8000DF44
    if (ctx->r1 == 0) {
        // 0x8000DF34: sltu        $at, $a0, $s2
        ctx->r1 = ctx->r4 < ctx->r18 ? 1 : 0;
            goto L_8000DF44;
    }
    goto skip_3;
    // 0x8000DF34: sltu        $at, $a0, $s2
    ctx->r1 = ctx->r4 < ctx->r18 ? 1 : 0;
    skip_3:
    // 0x8000DF38: b           L_8000DF74
    // 0x8000DF3C: lw          $v0, 0x510($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X510);
        goto L_8000DF74;
    // 0x8000DF3C: lw          $v0, 0x510($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X510);
L_8000DF40:
    // 0x8000DF40: sltu        $at, $a0, $s2
    ctx->r1 = ctx->r4 < ctx->r18 ? 1 : 0;
L_8000DF44:
    // 0x8000DF44: bne         $at, $zero, L_8000DF5C
    if (ctx->r1 != 0) {
        // 0x8000DF48: sltu        $at, $v1, $s2
        ctx->r1 = ctx->r3 < ctx->r18 ? 1 : 0;
            goto L_8000DF5C;
    }
    // 0x8000DF48: sltu        $at, $v1, $s2
    ctx->r1 = ctx->r3 < ctx->r18 ? 1 : 0;
    // 0x8000DF4C: bne         $at, $zero, L_8000DF5C
    if (ctx->r1 != 0) {
        // 0x8000DF50: nop
    
            goto L_8000DF5C;
    }
    // 0x8000DF50: nop

    // 0x8000DF54: b           L_8000DF74
    // 0x8000DF58: lw          $v0, 0x510($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X510);
        goto L_8000DF74;
    // 0x8000DF58: lw          $v0, 0x510($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X510);
L_8000DF5C:
    // 0x8000DF5C: jal         0x8000DFFC
    // 0x8000DF60: addiu       $a0, $s0, 0x10
    ctx->r4 = ADD32(ctx->r16, 0X10);
    AudioHeap_DiscardSampleCacheEntry(rdram, ctx);
        goto after_2;
    // 0x8000DF60: addiu       $a0, $s0, 0x10
    ctx->r4 = ADD32(ctx->r16, 0X10);
    after_2:
    // 0x8000DF64: bnel        $s5, $s6, L_8000DF74
    if (ctx->r21 != ctx->r22) {
        // 0x8000DF68: lw          $v0, 0x510($s4)
        ctx->r2 = MEM_W(ctx->r20, 0X510);
            goto L_8000DF74;
    }
    goto skip_4;
    // 0x8000DF68: lw          $v0, 0x510($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X510);
    skip_4:
    // 0x8000DF6C: or          $s5, $s1, $zero
    ctx->r21 = ctx->r17 | 0;
    // 0x8000DF70: lw          $v0, 0x510($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X510);
L_8000DF74:
    // 0x8000DF74: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8000DF78: slt         $at, $s1, $v0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8000DF7C: bne         $at, $zero, L_8000DF00
    if (ctx->r1 != 0) {
        // 0x8000DF80: addiu       $s0, $s0, 0x14
        ctx->r16 = ADD32(ctx->r16, 0X14);
            goto L_8000DF00;
    }
    // 0x8000DF80: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
L_8000DF84:
    // 0x8000DF84: addiu       $s6, $zero, -0x1
    ctx->r22 = ADD32(0, -0X1);
    // 0x8000DF88: bne         $s5, $s6, L_8000DFA4
    if (ctx->r21 != ctx->r22) {
        // 0x8000DF8C: lui         $t3, 0x8015
        ctx->r11 = S32(0X8015 << 16);
            goto L_8000DFA4;
    }
    // 0x8000DF8C: lui         $t3, 0x8015
    ctx->r11 = S32(0X8015 << 16);
    // 0x8000DF90: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x8000DF94: lw          $s5, -0x2C98($t0)
    ctx->r21 = MEM_W(ctx->r8, -0X2C98);
    // 0x8000DF98: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8000DF9C: addiu       $t1, $s5, 0x1
    ctx->r9 = ADD32(ctx->r21, 0X1);
    // 0x8000DFA0: sw          $t1, -0x2C98($at)
    MEM_W(-0X2C98, ctx->r1) = ctx->r9;
L_8000DFA4:
    // 0x8000DFA4: sll         $t2, $s5, 2
    ctx->r10 = S32(ctx->r21 << 2);
    // 0x8000DFA8: addu        $t2, $t2, $s5
    ctx->r10 = ADD32(ctx->r10, ctx->r21);
    // 0x8000DFAC: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8000DFB0: addiu       $t3, $t3, -0x31A8
    ctx->r11 = ADD32(ctx->r11, -0X31A8);
    // 0x8000DFB4: addu        $v1, $t2, $t3
    ctx->r3 = ADD32(ctx->r10, ctx->r11);
    // 0x8000DFB8: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x8000DFBC: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x8000DFC0: sb          $s7, 0x10($v1)
    MEM_B(0X10, ctx->r3) = ctx->r23;
    // 0x8000DFC4: addiu       $v0, $v1, 0x10
    ctx->r2 = ADD32(ctx->r3, 0X10);
    // 0x8000DFC8: sw          $t4, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r12;
    // 0x8000DFCC: sw          $t5, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r13;
L_8000DFD0:
    // 0x8000DFD0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8000DFD4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8000DFD8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8000DFDC: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8000DFE0: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8000DFE4: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x8000DFE8: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x8000DFEC: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x8000DFF0: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x8000DFF4: jr          $ra
    // 0x8000DFF8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8000DFF8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
