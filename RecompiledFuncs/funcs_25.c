#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void Audio_StopEngineNoise(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001CF60: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8001CF64: lw          $t6, -0x7D80($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7D80);
    // 0x8001CF68: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001CF6C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001CF70: lbu         $t7, 0x478($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X478);
    // 0x8001CF74: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001CF78: lui         $a1, 0x3100
    ctx->r5 = S32(0X3100 << 16);
    // 0x8001CF7C: bne         $t7, $at, L_8001CF90
    if (ctx->r15 != ctx->r1) {
        // 0x8001CF80: ori         $a1, $a1, 0xC
        ctx->r5 = ctx->r5 | 0XC;
            goto L_8001CF90;
    }
    // 0x8001CF80: ori         $a1, $a1, 0xC
    ctx->r5 = ctx->r5 | 0XC;
    // 0x8001CF84: lui         $a1, 0x3100
    ctx->r5 = S32(0X3100 << 16);
    // 0x8001CF88: b           L_8001CF90
    // 0x8001CF8C: ori         $a1, $a1, 0x40
    ctx->r5 = ctx->r5 | 0X40;
        goto L_8001CF90;
    // 0x8001CF8C: ori         $a1, $a1, 0x40
    ctx->r5 = ctx->r5 | 0X40;
L_8001CF90:
    // 0x8001CF90: jal         0x8001A55C
    // 0x8001CF94: nop

    Audio_KillSfxBySourceAndId(rdram, ctx);
        goto after_0;
    // 0x8001CF94: nop

    after_0:
    // 0x8001CF98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001CF9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001CFA0: jr          $ra
    // 0x8001CFA4: nop

    return;
    // 0x8001CFA4: nop

;}
RECOMP_FUNC void osDriveRomInit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001EE60: jr          $ra
    // 0x8001EE64: nop

    return;
    // 0x8001EE64: nop

;}
RECOMP_FUNC void SyShipDebris_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80074F90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80074F94: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80074F98: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80074F9C: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x80074FA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80074FA4: jal         0x800B8DD0
    // 0x80074FA8: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x80074FA8: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    after_0:
    // 0x80074FAC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80074FB0: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x80074FB4: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80074FB8: lui         $t8, 0x602
    ctx->r24 = S32(0X602 << 16);
    // 0x80074FBC: addiu       $t8, $t8, -0x5290
    ctx->r24 = ADD32(ctx->r24, -0X5290);
    // 0x80074FC0: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80074FC4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80074FC8: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80074FCC: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80074FD0: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80074FD4: jal         0x800B8DD0
    // 0x80074FD8: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    RCP_SetupDL(rdram, ctx);
        goto after_1;
    // 0x80074FD8: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_1:
    // 0x80074FDC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80074FE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80074FE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80074FE8: jr          $ra
    // 0x80074FEC: nop

    return;
    // 0x80074FEC: nop

;}
RECOMP_FUNC void HUD_PlayerShieldGauge_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B5B0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8008B5B4: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8008B5B8: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8008B5BC: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x8008B5C0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8008B5C4: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8008B5C8: swc1        $f12, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f12.u32l;
    // 0x8008B5CC: swc1        $f14, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f14.u32l;
    // 0x8008B5D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8008B5D4: jal         0x800B8DD0
    // 0x8008B5D8: addiu       $a1, $zero, 0x4B
    ctx->r5 = ADD32(0, 0X4B);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x8008B5D8: addiu       $a1, $zero, 0x4B
    ctx->r5 = ADD32(0, 0X4B);
    after_0:
    // 0x8008B5DC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8008B5E0: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8008B5E4: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8008B5E8: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8008B5EC: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x8008B5F0: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8008B5F4: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8008B5F8: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8008B5FC: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8008B600: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8008B604: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8008B608: lwc1        $f16, 0x40($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8008B60C: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8008B610: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x8008B614: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8008B618: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8008B61C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8008B620: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008B624: lwc1        $f16, 0x17AC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X17AC);
    // 0x8008B628: add.s       $f14, $f10, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8008B62C: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x8008B630: lw          $a2, 0x17A8($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X17A8);
    // 0x8008B634: jal         0x800856C0
    // 0x8008B638: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    HUD_ShieldGaugeBars_Draw(rdram, ctx);
        goto after_1;
    // 0x8008B638: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_1:
    // 0x8008B63C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8008B640: jal         0x800B8DD0
    // 0x8008B644: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    RCP_SetupDL(rdram, ctx);
        goto after_2;
    // 0x8008B644: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    after_2:
    // 0x8008B648: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8008B64C: lui         $t0, 0xFA00
    ctx->r8 = S32(0XFA00 << 16);
    // 0x8008B650: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x8008B654: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8008B658: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x8008B65C: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x8008B660: lw          $t4, 0x1EB8($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X1EB8);
    // 0x8008B664: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x8008B668: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x8008B66C: lw          $t8, 0x1EBC($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1EBC);
    // 0x8008B670: lw          $t2, 0x1EB4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X1EB4);
    // 0x8008B674: andi        $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 & 0XFF;
    // 0x8008B678: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x8008B67C: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x8008B680: sll         $t3, $t2, 24
    ctx->r11 = S32(ctx->r10 << 24);
    // 0x8008B684: or          $t7, $t3, $t6
    ctx->r15 = ctx->r11 | ctx->r14;
    // 0x8008B688: sll         $t0, $t9, 8
    ctx->r8 = S32(ctx->r25 << 8);
    // 0x8008B68C: or          $t1, $t7, $t0
    ctx->r9 = ctx->r15 | ctx->r8;
    // 0x8008B690: ori         $t2, $t1, 0xFF
    ctx->r10 = ctx->r9 | 0XFF;
    // 0x8008B694: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x8008B698: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8008B69C: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x8008B6A0: lwc1        $f12, 0x40($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8008B6A4: jal         0x80085618
    // 0x8008B6A8: lwc1        $f14, 0x44($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X44);
    HUD_ShieldGaugeEdgeLeft_Draw(rdram, ctx);
        goto after_3;
    // 0x8008B6A8: lwc1        $f14, 0x44($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X44);
    after_3:
    // 0x8008B6AC: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x8008B6B0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8008B6B4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008B6B8: lwc1        $f6, 0x17A8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X17A8);
    // 0x8008B6BC: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x8008B6C0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8008B6C4: lwc1        $f18, 0x40($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8008B6C8: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8008B6CC: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8008B6D0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8008B6D4: add.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8008B6D8: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8008B6DC: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x8008B6E0: lwc1        $f14, 0x44($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8008B6E4: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x8008B6E8: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8008B6EC: jal         0x800855C4
    // 0x8008B6F0: add.s       $f12, $f0, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f18.fl;
    HUD_ShieldGaugeEdgeRight_Draw(rdram, ctx);
        goto after_4;
    // 0x8008B6F0: add.s       $f12, $f0, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f18.fl;
    after_4:
    // 0x8008B6F4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008B6F8: lwc1        $f4, 0x17A8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X17A8);
    // 0x8008B6FC: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x8008B700: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8008B704: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x8008B708: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8008B70C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8008B710: lwc1        $f14, 0x44($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8008B714: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x8008B718: jal         0x8008566C
    // 0x8008B71C: nop

    HUD_ShieldGaugeFrame_Draw(rdram, ctx);
        goto after_5;
    // 0x8008B71C: nop

    after_5:
    // 0x8008B720: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8008B724: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8008B728: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8008B72C: jr          $ra
    // 0x8008B730: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8008B730: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80012E28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80012E28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80012E2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80012E30: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80012E34: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80012E38: jal         0x8001268C
    // 0x80012E3C: lw          $a0, 0x44($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X44);
    Audio_SeqLayerNoteRelease(rdram, ctx);
        goto after_0;
    // 0x80012E3C: lw          $a0, 0x44($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X44);
    after_0:
    // 0x80012E40: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80012E44: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80012E48: sw          $t7, 0x48($t8)
    MEM_W(0X48, ctx->r24) = ctx->r15;
    // 0x80012E4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80012E50: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80012E54: jr          $ra
    // 0x80012E58: nop

    return;
    // 0x80012E58: nop

;}
RECOMP_FUNC void Effect_Effect343_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007CAF0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8007CAF4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8007CAF8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8007CAFC: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8007CB00: jal         0x8005980C
    // 0x8007CB04: lwc1        $f12, 0x70($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0X70);
    Graphics_SetScaleMtx(rdram, ctx);
        goto after_0;
    // 0x8007CB04: lwc1        $f12, 0x70($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0X70);
    after_0:
    // 0x8007CB08: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8007CB0C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8007CB10: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8007CB14: lh          $t7, 0x44($t0)
    ctx->r15 = MEM_H(ctx->r8, 0X44);
    // 0x8007CB18: lui         $t4, 0x600
    ctx->r12 = S32(0X600 << 16);
    // 0x8007CB1C: bnel        $t7, $zero, L_8007CB6C
    if (ctx->r15 != 0) {
        // 0x8007CB20: lui         $at, 0x3FC0
        ctx->r1 = S32(0X3FC0 << 16);
            goto L_8007CB6C;
    }
    goto skip_0;
    // 0x8007CB20: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    skip_0:
    // 0x8007CB24: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007CB28: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x8007CB2C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8007CB30: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8007CB34: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8007CB38: lh          $t1, 0x4A($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X4A);
    // 0x8007CB3C: andi        $t2, $t1, 0xFF
    ctx->r10 = ctx->r9 & 0XFF;
    // 0x8007CB40: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x8007CB44: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007CB48: lui         $t5, 0x103
    ctx->r13 = S32(0X103 << 16);
    // 0x8007CB4C: addiu       $t5, $t5, -0x5FF0
    ctx->r13 = ADD32(ctx->r13, -0X5FF0);
    // 0x8007CB50: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x8007CB54: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x8007CB58: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x8007CB5C: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8007CB60: b           L_8007CBF4
    // 0x8007CB64: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8007CBF4;
    // 0x8007CB64: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007CB68: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
L_8007CB6C:
    // 0x8007CB6C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8007CB70: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8007CB74: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8007CB78: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8007CB7C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8007CB80: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8007CB84: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8007CB88: jal         0x80005C34
    // 0x8007CB8C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Scale(rdram, ctx);
        goto after_1;
    // 0x8007CB8C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_1:
    // 0x8007CB90: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8007CB94: jal         0x80006EB8
    // 0x8007CB98: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_2;
    // 0x8007CB98: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    after_2:
    // 0x8007CB9C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8007CBA0: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8007CBA4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007CBA8: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x8007CBAC: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x8007CBB0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8007CBB4: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8007CBB8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8007CBBC: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x8007CBC0: lui         $t5, 0x600
    ctx->r13 = S32(0X600 << 16);
    // 0x8007CBC4: lh          $t1, 0x4A($t9)
    ctx->r9 = MEM_H(ctx->r25, 0X4A);
    // 0x8007CBC8: andi        $t2, $t1, 0xFF
    ctx->r10 = ctx->r9 & 0XFF;
    // 0x8007CBCC: or          $t3, $t2, $at
    ctx->r11 = ctx->r10 | ctx->r1;
    // 0x8007CBD0: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x8007CBD4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007CBD8: lui         $t6, 0x200
    ctx->r14 = S32(0X200 << 16);
    // 0x8007CBDC: addiu       $t6, $t6, 0x31B0
    ctx->r14 = ADD32(ctx->r14, 0X31B0);
    // 0x8007CBE0: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x8007CBE4: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x8007CBE8: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8007CBEC: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8007CBF0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8007CBF4:
    // 0x8007CBF4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8007CBF8: jr          $ra
    // 0x8007CBFC: nop

    return;
    // 0x8007CBFC: nop

;}
RECOMP_FUNC void __cosf_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023250: swc1        $f12, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f12.u32l;
    // 0x80023254: lw          $v0, 0x0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X0);
    // 0x80023258: lwc1        $f6, 0x0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X0);
    // 0x8002325C: lwc1        $f10, 0x0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X0);
    // 0x80023260: sra         $t6, $v0, 22
    ctx->r14 = S32(SIGNED(ctx->r2) >> 22);
    // 0x80023264: andi        $t7, $t6, 0x1FF
    ctx->r15 = ctx->r14 & 0X1FF;
    // 0x80023268: slti        $at, $t7, 0x136
    ctx->r1 = SIGNED(ctx->r15) < 0X136 ? 1 : 0;
    // 0x8002326C: beql        $at, $zero, L_80023394
    if (ctx->r1 == 0) {
        // 0x80023270: c.eq.s      $f10, $f10
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f10.fl == ctx->f10.fl;
            goto L_80023394;
    }
    goto skip_0;
    // 0x80023270: c.eq.s      $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f10.fl == ctx->f10.fl;
    skip_0:
    // 0x80023274: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80023278: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8002327C: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80023280: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80023284: lwc1        $f0, 0x0($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X0);
    // 0x80023288: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002328C: bc1fl       L_800232A0
    if (!c1cs) {
        // 0x80023290: neg.s       $f0, $f0
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
            goto L_800232A0;
    }
    goto skip_1;
    // 0x80023290: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    skip_1:
    // 0x80023294: b           L_800232A0
    // 0x80023298: mov.s       $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = ctx->f6.fl;
        goto L_800232A0;
    // 0x80023298: mov.s       $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = ctx->f6.fl;
    // 0x8002329C: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
L_800232A0:
    // 0x800232A0: ldc1        $f8, -0x6C48($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X6C48);
    // 0x800232A4: cvt.d.s     $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.d = CVT_D_S(ctx->f0.fl);
    // 0x800232A8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800232AC: mul.d       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f12.d, ctx->f8.d);
    // 0x800232B0: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x800232B4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800232B8: add.d       $f14, $f10, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f14.d = ctx->f10.d + ctx->f18.d;
    // 0x800232BC: c.le.d      $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f4.d <= ctx->f14.d;
    // 0x800232C0: nop

    // 0x800232C4: bc1fl       L_800232E4
    if (!c1cs) {
        // 0x800232C8: sub.d       $f10, $f14, $f18
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = ctx->f14.d - ctx->f18.d;
            goto L_800232E4;
    }
    goto skip_2;
    // 0x800232C8: sub.d       $f10, $f14, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = ctx->f14.d - ctx->f18.d;
    skip_2:
    // 0x800232CC: add.d       $f6, $f14, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = ctx->f14.d + ctx->f18.d;
    // 0x800232D0: trunc.w.d   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_D(ctx->f6.d);
    // 0x800232D4: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x800232D8: b           L_800232F4
    // 0x800232DC: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
        goto L_800232F4;
    // 0x800232DC: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x800232E0: sub.d       $f10, $f14, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = ctx->f14.d - ctx->f18.d;
L_800232E4:
    // 0x800232E4: trunc.w.d   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_D(ctx->f10.d);
    // 0x800232E8: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x800232EC: nop

    // 0x800232F0: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
L_800232F4:
    // 0x800232F4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800232F8: ldc1        $f10, -0x6C40($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X6C40);
    // 0x800232FC: cvt.d.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.d = CVT_D_W(ctx->f6.u32l);
    // 0x80023300: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80023304: ldc1        $f6, -0x6C38($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X6C38);
    // 0x80023308: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8002330C: addiu       $v1, $v1, -0x6C70
    ctx->r3 = ADD32(ctx->r3, -0X6C70);
    // 0x80023310: sub.d       $f0, $f8, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d); 
    ctx->f0.d = ctx->f8.d - ctx->f18.d;
    // 0x80023314: andi        $t0, $v0, 0x1
    ctx->r8 = ctx->r2 & 0X1;
    // 0x80023318: mul.d       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = MUL_D(ctx->f0.d, ctx->f10.d);
    // 0x8002331C: ldc1        $f10, 0x20($v1)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r3, 0X20);
    // 0x80023320: mul.d       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f0.d, ctx->f6.d);
    // 0x80023324: ldc1        $f6, 0x18($v1)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r3, 0X18);
    // 0x80023328: sub.d       $f2, $f12, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f4.d); 
    ctx->f2.d = ctx->f12.d - ctx->f4.d;
    // 0x8002332C: sub.d       $f2, $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f8.d); 
    ctx->f2.d = ctx->f2.d - ctx->f8.d;
    // 0x80023330: mul.d       $f14, $f2, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f2.d); 
    ctx->f14.d = MUL_D(ctx->f2.d, ctx->f2.d);
    // 0x80023334: nop

    // 0x80023338: mul.d       $f4, $f10, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f14.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f14.d);
    // 0x8002333C: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x80023340: ldc1        $f4, 0x10($v1)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r3, 0X10);
    // 0x80023344: mul.d       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f14.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f14.d);
    // 0x80023348: add.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f10.d + ctx->f4.d;
    // 0x8002334C: ldc1        $f10, 0x8($v1)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r3, 0X8);
    // 0x80023350: mul.d       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f14.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f14.d);
    // 0x80023354: bne         $t0, $zero, L_80023374
    if (ctx->r8 != 0) {
        // 0x80023358: add.d       $f16, $f10, $f8
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = ctx->f10.d + ctx->f8.d;
            goto L_80023374;
    }
    // 0x80023358: add.d       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = ctx->f10.d + ctx->f8.d;
    // 0x8002335C: mul.d       $f4, $f2, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f14.d); 
    ctx->f4.d = MUL_D(ctx->f2.d, ctx->f14.d);
    // 0x80023360: nop

    // 0x80023364: mul.d       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f16.d);
    // 0x80023368: add.d       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = ctx->f6.d + ctx->f2.d;
    // 0x8002336C: jr          $ra
    // 0x80023370: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
    return;
    // 0x80023370: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
L_80023374:
    // 0x80023374: mul.d       $f8, $f2, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f14.d); 
    ctx->f8.d = MUL_D(ctx->f2.d, ctx->f14.d);
    // 0x80023378: nop

    // 0x8002337C: mul.d       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f16.d);
    // 0x80023380: add.d       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f2.d); 
    ctx->f6.d = ctx->f4.d + ctx->f2.d;
    // 0x80023384: cvt.s.d     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f0.fl = CVT_S_D(ctx->f6.d);
    // 0x80023388: jr          $ra
    // 0x8002338C: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    return;
    // 0x8002338C: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80023390: c.eq.s      $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f10.fl == ctx->f10.fl;
L_80023394:
    // 0x80023394: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80023398: bc1t        L_800233AC
    if (c1cs) {
        // 0x8002339C: nop
    
            goto L_800233AC;
    }
    // 0x8002339C: nop

    // 0x800233A0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800233A4: jr          $ra
    // 0x800233A8: lwc1        $f0, -0x6A90($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6A90);
    return;
    // 0x800233A8: lwc1        $f0, -0x6A90($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6A90);
L_800233AC:
    // 0x800233AC: lwc1        $f0, -0x6C30($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6C30);
    // 0x800233B0: jr          $ra
    // 0x800233B4: nop

    return;
    // 0x800233B4: nop

;}
RECOMP_FUNC void Memory_Allocate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006F38: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x80006F3C: addiu       $a2, $a2, 0x4BD0
    ctx->r6 = ADD32(ctx->r6, 0X4BD0);
    // 0x80006F40: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80006F44: addiu       $t6, $a0, 0xF
    ctx->r14 = ADD32(ctx->r4, 0XF);
    // 0x80006F48: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x80006F4C: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x80006F50: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x80006F54: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x80006F58: jr          $ra
    // 0x80006F5C: nop

    return;
    // 0x80006F5C: nop

;}
RECOMP_FUNC void func_versus_800C024C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C024C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800C0250: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800C0254: sw          $t6, -0x7844($at)
    MEM_W(-0X7844, ctx->r1) = ctx->r14;
    // 0x800C0258: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800C025C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800C0260: sw          $zero, -0x7868($at)
    MEM_W(-0X7868, ctx->r1) = 0;
    // 0x800C0264: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800C0268: swc1        $f4, -0x783C($at)
    MEM_W(-0X783C, ctx->r1) = ctx->f4.u32l;
    // 0x800C026C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C0270: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800C0274: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800C0278: swc1        $f6, -0x7838($at)
    MEM_W(-0X7838, ctx->r1) = ctx->f6.u32l;
    // 0x800C027C: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x800C0280: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800C0284: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800C0288: swc1        $f8, -0x7840($at)
    MEM_W(-0X7840, ctx->r1) = ctx->f8.u32l;
    // 0x800C028C: jr          $ra
    // 0x800C0290: nop

    return;
    // 0x800C0290: nop

;}
RECOMP_FUNC void HUD_IncomingMsgSignal2_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085514: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80085518: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8008551C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80085520: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80085524: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80085528: lui         $a1, 0x101
    ctx->r5 = S32(0X101 << 16);
    // 0x8008552C: lui         $a2, 0x101
    ctx->r6 = S32(0X101 << 16);
    // 0x80085530: addiu       $t6, $zero, 0x1A
    ctx->r14 = ADD32(0, 0X1A);
    // 0x80085534: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80085538: addiu       $a2, $a2, 0x1D70
    ctx->r6 = ADD32(ctx->r6, 0X1D70);
    // 0x8008553C: addiu       $a1, $a1, 0x1CA0
    ctx->r5 = ADD32(ctx->r5, 0X1CA0);
    // 0x80085540: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x80085544: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x80085548: swc1        $f12, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f12.u32l;
    // 0x8008554C: swc1        $f14, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f14.u32l;
    // 0x80085550: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x80085554: jal         0x8009C320
    // 0x80085558: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    Lib_TextureRect_CI4(rdram, ctx);
        goto after_0;
    // 0x80085558: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x8008555C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80085560: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80085564: jr          $ra
    // 0x80085568: nop

    return;
    // 0x80085568: nop

;}
RECOMP_FUNC void Effect_SetupShootAtPlayer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007E6B8: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8007E6BC: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8007E6C0: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8007E6C4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8007E6C8: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8007E6CC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8007E6D0: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x8007E6D4: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    // 0x8007E6D8: jal         0x80061474
    // 0x8007E6DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Effect_Initialize(rdram, ctx);
        goto after_0;
    // 0x8007E6DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8007E6E0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8007E6E4: addiu       $t7, $zero, 0x64
    ctx->r15 = ADD32(0, 0X64);
    // 0x8007E6E8: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
    // 0x8007E6EC: sh          $s1, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r17;
    // 0x8007E6F0: sh          $t7, 0x50($s0)
    MEM_H(0X50, ctx->r16) = ctx->r15;
    // 0x8007E6F4: lwc1        $f4, 0x60($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8007E6F8: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x8007E6FC: andi        $a1, $s1, 0xFFFF
    ctx->r5 = ctx->r17 & 0XFFFF;
    // 0x8007E700: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x8007E704: lwc1        $f6, 0x64($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8007E708: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x8007E70C: lwc1        $f8, 0x68($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8007E710: jal         0x800612B8
    // 0x8007E714: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_1;
    // 0x8007E714: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    after_1:
    // 0x8007E718: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8007E71C: lw          $v0, -0x7D80($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D80);
    // 0x8007E720: lwc1        $f18, 0x60($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8007E724: lwc1        $f6, 0x68($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8007E728: lwc1        $f10, 0x74($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X74);
    // 0x8007E72C: lwc1        $f4, 0x138($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X138);
    // 0x8007E730: sub.s       $f12, $f10, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x8007E734: jal         0x80005100
    // 0x8007E738: sub.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f6.fl;
    Math_Atan2F(rdram, ctx);
        goto after_2;
    // 0x8007E738: sub.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f6.fl;
    after_2:
    // 0x8007E73C: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8007E740: lw          $v0, -0x7D80($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D80);
    // 0x8007E744: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    // 0x8007E748: lwc1        $f10, 0x68($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8007E74C: lwc1        $f8, 0x138($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X138);
    // 0x8007E750: lwc1        $f4, 0x60($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8007E754: lwc1        $f18, 0x74($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X74);
    // 0x8007E758: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8007E75C: lwc1        $f10, 0x78($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X78);
    // 0x8007E760: sub.s       $f2, $f18, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8007E764: mul.s       $f6, $f16, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x8007E768: lwc1        $f18, 0x64($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8007E76C: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8007E770: sub.s       $f12, $f10, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x8007E774: add.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8007E778: jal         0x80005100
    // 0x8007E77C: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    Math_Atan2F(rdram, ctx);
        goto after_3;
    // 0x8007E77C: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    after_3:
    // 0x8007E780: neg.s       $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = -ctx->f0.fl;
    // 0x8007E784: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8007E788: swc1        $f4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f4.u32l;
    // 0x8007E78C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8007E790: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x8007E794: jal         0x80005E90
    // 0x8007E798: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Matrix_RotateY(rdram, ctx);
        goto after_4;
    // 0x8007E798: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x8007E79C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8007E7A0: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8007E7A4: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x8007E7A8: jal         0x80005D44
    // 0x8007E7AC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateX(rdram, ctx);
        goto after_5;
    // 0x8007E7AC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x8007E7B0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8007E7B4: lwc1        $f6, 0x6C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8007E7B8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8007E7BC: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8007E7C0: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x8007E7C4: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    // 0x8007E7C8: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x8007E7CC: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x8007E7D0: jal         0x80006970
    // 0x8007E7D4: swc1        $f6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f6.u32l;
    Matrix_MultVec3f(rdram, ctx);
        goto after_6;
    // 0x8007E7D4: swc1        $f6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f6.u32l;
    after_6:
    // 0x8007E7D8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8007E7DC: lwc1        $f10, 0x79E4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X79E4);
    // 0x8007E7E0: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8007E7E4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8007E7E8: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8007E7EC: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8007E7F0: lui         $a0, 0x3100
    ctx->r4 = S32(0X3100 << 16);
    // 0x8007E7F4: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x8007E7F8: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8007E7FC: swc1        $f18, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f18.u32l;
    // 0x8007E800: lwc1        $f6, 0x79F4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X79F4);
    // 0x8007E804: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8007E808: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8007E80C: addiu       $t8, $t8, 0x5D3C
    ctx->r24 = ADD32(ctx->r24, 0X5D3C);
    // 0x8007E810: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8007E814: ori         $a0, $a0, 0x25
    ctx->r4 = ctx->r4 | 0X25;
    // 0x8007E818: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    // 0x8007E81C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8007E820: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
    // 0x8007E824: lwc1        $f18, 0x7D08($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7D08);
    // 0x8007E828: lwc1        $f10, 0x3C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8007E82C: addiu       $at, $zero, 0x161
    ctx->r1 = ADD32(0, 0X161);
    // 0x8007E830: sub.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x8007E834: beq         $s1, $at, L_8007E844
    if (ctx->r17 == ctx->r1) {
        // 0x8007E838: swc1        $f4, 0x5C($s0)
        MEM_W(0X5C, ctx->r16) = ctx->f4.u32l;
            goto L_8007E844;
    }
    // 0x8007E838: swc1        $f4, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f4.u32l;
    // 0x8007E83C: addiu       $at, $zero, 0x162
    ctx->r1 = ADD32(0, 0X162);
    // 0x8007E840: bne         $s1, $at, L_8007E874
    if (ctx->r17 != ctx->r1) {
        // 0x8007E844: lui         $at, 0x4334
        ctx->r1 = S32(0X4334 << 16);
            goto L_8007E874;
    }
L_8007E844:
    // 0x8007E844: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8007E848: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8007E84C: lwc1        $f6, 0x54($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8007E850: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007E854: lwc1        $f2, 0x7480($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X7480);
    // 0x8007E858: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8007E85C: div.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8007E860: swc1        $f10, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f10.u32l;
    // 0x8007E864: lwc1        $f18, 0x50($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8007E868: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8007E86C: div.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8007E870: swc1        $f6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f6.u32l;
L_8007E874:
    // 0x8007E874: addiu       $at, $zero, 0x164
    ctx->r1 = ADD32(0, 0X164);
    // 0x8007E878: bne         $s1, $at, L_8007E88C
    if (ctx->r17 != ctx->r1) {
        // 0x8007E87C: nop
    
            goto L_8007E88C;
    }
    // 0x8007E87C: nop

    // 0x8007E880: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8007E884: jal         0x80019218
    // 0x8007E888: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    Audio_PlaySfx(rdram, ctx);
        goto after_7;
    // 0x8007E888: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    after_7:
L_8007E88C:
    // 0x8007E88C: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8007E890: addiu       $at, $zero, 0x178
    ctx->r1 = ADD32(0, 0X178);
    // 0x8007E894: bne         $s1, $at, L_8007E8CC
    if (ctx->r17 != ctx->r1) {
        // 0x8007E898: addiu       $a3, $a3, 0x5D34
        ctx->r7 = ADD32(ctx->r7, 0X5D34);
            goto L_8007E8CC;
    }
    // 0x8007E898: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8007E89C: jal         0x80004EB0
    // 0x8007E8A0: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_8;
    // 0x8007E8A0: nop

    after_8:
    // 0x8007E8A4: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8007E8A8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8007E8AC: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8007E8B0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8007E8B4: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8007E8B8: addiu       $t9, $zero, 0xB4
    ctx->r25 = ADD32(0, 0XB4);
    // 0x8007E8BC: sh          $t9, 0x4A($s0)
    MEM_H(0X4A, ctx->r16) = ctx->r25;
    // 0x8007E8C0: swc1        $f18, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f18.u32l;
    // 0x8007E8C4: b           L_8007E928
    // 0x8007E8C8: swc1        $f10, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f10.u32l;
        goto L_8007E928;
    // 0x8007E8C8: swc1        $f10, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f10.u32l;
L_8007E8CC:
    // 0x8007E8CC: addiu       $at, $zero, 0x163
    ctx->r1 = ADD32(0, 0X163);
    // 0x8007E8D0: beq         $s1, $at, L_8007E8E4
    if (ctx->r17 == ctx->r1) {
        // 0x8007E8D4: addiu       $a1, $s0, 0x80
        ctx->r5 = ADD32(ctx->r16, 0X80);
            goto L_8007E8E4;
    }
    // 0x8007E8D4: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    // 0x8007E8D8: addiu       $at, $zero, 0x179
    ctx->r1 = ADD32(0, 0X179);
    // 0x8007E8DC: bne         $s1, $at, L_8007E90C
    if (ctx->r17 != ctx->r1) {
        // 0x8007E8E0: lui         $a0, 0x2900
        ctx->r4 = S32(0X2900 << 16);
            goto L_8007E90C;
    }
    // 0x8007E8E0: lui         $a0, 0x2900
    ctx->r4 = S32(0X2900 << 16);
L_8007E8E4:
    // 0x8007E8E4: lui         $t0, 0x800C
    ctx->r8 = S32(0X800C << 16);
    // 0x8007E8E8: addiu       $t0, $t0, 0x5D3C
    ctx->r8 = ADD32(ctx->r8, 0X5D3C);
    // 0x8007E8EC: lui         $a0, 0x3100
    ctx->r4 = S32(0X3100 << 16);
    // 0x8007E8F0: ori         $a0, $a0, 0x25
    ctx->r4 = ctx->r4 | 0X25;
    // 0x8007E8F4: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8007E8F8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8007E8FC: jal         0x80019218
    // 0x8007E900: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    Audio_PlaySfx(rdram, ctx);
        goto after_9;
    // 0x8007E900: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_9:
    // 0x8007E904: b           L_8007E92C
    // 0x8007E908: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8007E92C;
    // 0x8007E908: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8007E90C:
    // 0x8007E90C: lui         $t1, 0x800C
    ctx->r9 = S32(0X800C << 16);
    // 0x8007E910: addiu       $t1, $t1, 0x5D3C
    ctx->r9 = ADD32(ctx->r9, 0X5D3C);
    // 0x8007E914: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x8007E918: ori         $a0, $a0, 0x2002
    ctx->r4 = ctx->r4 | 0X2002;
    // 0x8007E91C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8007E920: jal         0x80019218
    // 0x8007E924: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    Audio_PlaySfx(rdram, ctx);
        goto after_10;
    // 0x8007E924: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_10:
L_8007E928:
    // 0x8007E928: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8007E92C:
    // 0x8007E92C: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8007E930: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8007E934: jr          $ra
    // 0x8007E938: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8007E938: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void Display_Arwing_Skel(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80053658: addiu       $sp, $sp, -0x1D0
    ctx->r29 = ADD32(ctx->r29, -0X1D0);
    // 0x8005365C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80053660: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80053664: sw          $a0, 0x1D0($sp)
    MEM_W(0X1D0, ctx->r29) = ctx->r4;
    // 0x80053668: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005366C: jal         0x80005708
    // 0x80053670: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Push(rdram, ctx);
        goto after_0;
    // 0x80053670: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_0:
    // 0x80053674: lw          $v1, 0x1D0($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1D0);
    // 0x80053678: lui         $at, 0xC0E0
    ctx->r1 = S32(0XC0E0 << 16);
    // 0x8005367C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80053680: lwc1        $f0, 0x14($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X14);
    // 0x80053684: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80053688: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8005368C: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80053690: swc1        $f4, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f4.u32l;
    // 0x80053694: bc1f        L_800536BC
    if (!c1cs) {
        // 0x80053698: lui         $at, 0x40E0
        ctx->r1 = S32(0X40E0 << 16);
            goto L_800536BC;
    }
    // 0x80053698: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x8005369C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800536A0: neg.s       $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = -ctx->f0.fl;
    // 0x800536A4: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x800536A8: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800536AC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800536B0: nop

    // 0x800536B4: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800536B8: swc1        $f4, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f4.u32l;
L_800536BC:
    // 0x800536BC: lw          $v0, 0x7834($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7834);
    // 0x800536C0: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x800536C4: bne         $v0, $at, L_80053708
    if (ctx->r2 != ctx->r1) {
        // 0x800536C8: lui         $a2, 0x8018
        ctx->r6 = S32(0X8018 << 16);
            goto L_80053708;
    }
    // 0x800536C8: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x800536CC: lw          $a2, -0x7D80($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7D80);
    // 0x800536D0: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x800536D4: addiu       $t6, $t6, 0x4660
    ctx->r14 = ADD32(ctx->r14, 0X4660);
    // 0x800536D8: lui         $a1, 0x301
    ctx->r5 = S32(0X301 << 16);
    // 0x800536DC: lui         $a3, 0x8005
    ctx->r7 = S32(0X8005 << 16);
    // 0x800536E0: addiu       $a3, $a3, 0x31A4
    ctx->r7 = ADD32(ctx->r7, 0X31A4);
    // 0x800536E4: addiu       $a1, $a1, 0x6610
    ctx->r5 = ADD32(ctx->r5, 0X6610);
    // 0x800536E8: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x800536EC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800536F0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800536F4: sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    // 0x800536F8: jal         0x8009A72C
    // 0x800536FC: addiu       $a2, $a2, 0x2F8
    ctx->r6 = ADD32(ctx->r6, 0X2F8);
    Animation_DrawSkeleton(rdram, ctx);
        goto after_1;
    // 0x800536FC: addiu       $a2, $a2, 0x2F8
    ctx->r6 = ADD32(ctx->r6, 0X2F8);
    after_1:
    // 0x80053700: b           L_8005377C
    // 0x80053704: nop

        goto L_8005377C;
    // 0x80053704: nop

L_80053708:
    // 0x80053708: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8005370C: bne         $v0, $at, L_80053734
    if (ctx->r2 != ctx->r1) {
        // 0x80053710: addiu       $s0, $sp, 0x68
        ctx->r16 = ADD32(ctx->r29, 0X68);
            goto L_80053734;
    }
    // 0x80053710: addiu       $s0, $sp, 0x68
    ctx->r16 = ADD32(ctx->r29, 0X68);
    // 0x80053714: addiu       $s0, $sp, 0x68
    ctx->r16 = ADD32(ctx->r29, 0X68);
    // 0x80053718: lui         $a0, 0x301
    ctx->r4 = S32(0X301 << 16);
    // 0x8005371C: addiu       $a0, $a0, 0x5AF4
    ctx->r4 = ADD32(ctx->r4, 0X5AF4);
    // 0x80053720: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80053724: jal         0x8009AA20
    // 0x80053728: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    Animation_GetFrameData(rdram, ctx);
        goto after_2;
    // 0x80053728: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x8005372C: b           L_8005374C
    // 0x80053730: lw          $t7, 0x1D0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1D0);
        goto L_8005374C;
    // 0x80053730: lw          $t7, 0x1D0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1D0);
L_80053734:
    // 0x80053734: lui         $a0, 0x301
    ctx->r4 = S32(0X301 << 16);
    // 0x80053738: addiu       $a0, $a0, 0x5C28
    ctx->r4 = ADD32(ctx->r4, 0X5C28);
    // 0x8005373C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80053740: jal         0x8009AA20
    // 0x80053744: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    Animation_GetFrameData(rdram, ctx);
        goto after_3;
    // 0x80053744: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_3:
    // 0x80053748: lw          $t7, 0x1D0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1D0);
L_8005374C:
    // 0x8005374C: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x80053750: addiu       $t8, $t8, 0x4660
    ctx->r24 = ADD32(ctx->r24, 0X4660);
    // 0x80053754: lui         $a1, 0x301
    ctx->r5 = S32(0X301 << 16);
    // 0x80053758: lui         $a3, 0x8005
    ctx->r7 = S32(0X8005 << 16);
    // 0x8005375C: addiu       $a3, $a3, 0x31A4
    ctx->r7 = ADD32(ctx->r7, 0X31A4);
    // 0x80053760: addiu       $a1, $a1, 0x6610
    ctx->r5 = ADD32(ctx->r5, 0X6610);
    // 0x80053764: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80053768: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8005376C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80053770: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80053774: jal         0x8009A72C
    // 0x80053778: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    Animation_DrawSkeleton(rdram, ctx);
        goto after_4;
    // 0x80053778: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_4:
L_8005377C:
    // 0x8005377C: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x80053780: lw          $t0, -0x5DE0($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X5DE0);
    // 0x80053784: lw          $t9, 0x1D0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1D0);
    // 0x80053788: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005378C: sw          $zero, -0x5DD4($at)
    MEM_W(-0X5DD4, ctx->r1) = 0;
    // 0x80053790: beq         $t0, $zero, L_8005379C
    if (ctx->r8 == 0) {
        // 0x80053794: lbu         $v0, 0x2C($t9)
        ctx->r2 = MEM_BU(ctx->r25, 0X2C);
            goto L_8005379C;
    }
    // 0x80053794: lbu         $v0, 0x2C($t9)
    ctx->r2 = MEM_BU(ctx->r25, 0X2C);
    // 0x80053798: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8005379C:
    // 0x8005379C: beq         $v0, $zero, L_80053918
    if (ctx->r2 == 0) {
        // 0x800537A0: lui         $a0, 0x8014
        ctx->r4 = S32(0X8014 << 16);
            goto L_80053918;
    }
    // 0x800537A0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800537A4: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    // 0x800537A8: jal         0x80005708
    // 0x800537AC: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    Matrix_Push(rdram, ctx);
        goto after_5;
    // 0x800537AC: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    after_5:
    // 0x800537B0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800537B4: lui         $a2, 0x40CC
    ctx->r6 = S32(0X40CC << 16);
    // 0x800537B8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800537BC: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x800537C0: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800537C4: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x800537C8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x800537CC: jal         0x80005B00
    // 0x800537D0: lui         $a3, 0xC184
    ctx->r7 = S32(0XC184 << 16);
    Matrix_Translate(rdram, ctx);
        goto after_6;
    // 0x800537D0: lui         $a3, 0xC184
    ctx->r7 = S32(0XC184 << 16);
    after_6:
    // 0x800537D4: lw          $t2, 0x1D0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1D0);
    // 0x800537D8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800537DC: lwc1        $f8, 0x5E78($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5E78);
    // 0x800537E0: lwc1        $f6, 0x34($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X34);
    // 0x800537E4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800537E8: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x800537EC: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800537F0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800537F4: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x800537F8: jal         0x80005E90
    // 0x800537FC: nop

    Matrix_RotateY(rdram, ctx);
        goto after_7;
    // 0x800537FC: nop

    after_7:
    // 0x80053800: lw          $t3, 0x1D0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1D0);
    // 0x80053804: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80053808: lwc1        $f18, 0x5E7C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X5E7C);
    // 0x8005380C: lwc1        $f16, 0x30($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0X30);
    // 0x80053810: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80053814: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80053818: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8005381C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80053820: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80053824: jal         0x80005D44
    // 0x80053828: nop

    Matrix_RotateX(rdram, ctx);
        goto after_8;
    // 0x80053828: nop

    after_8:
    // 0x8005382C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80053830: lwc1        $f0, 0x5E80($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5E80);
    // 0x80053834: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80053838: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8005383C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80053840: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80053844: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80053848: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8005384C: jal         0x80005C34
    // 0x80053850: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Scale(rdram, ctx);
        goto after_9;
    // 0x80053850: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_9:
    // 0x80053854: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x80053858: lw          $t5, 0x7834($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7834);
    // 0x8005385C: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80053860: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80053864: bne         $t5, $at, L_8005388C
    if (ctx->r13 != ctx->r1) {
        // 0x80053868: lui         $at, 0x800D
        ctx->r1 = S32(0X800D << 16);
            goto L_8005388C;
    }
    // 0x80053868: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005386C: lwc1        $f0, 0x5E84($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5E84);
    // 0x80053870: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80053874: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80053878: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8005387C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80053880: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80053884: jal         0x80005C34
    // 0x80053888: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Scale(rdram, ctx);
        goto after_10;
    // 0x80053888: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_10:
L_8005388C:
    // 0x8005388C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80053890: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x80053894: jal         0x80006EB8
    // 0x80053898: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_11;
    // 0x80053898: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x8005389C: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x800538A0: lw          $t7, 0x79F8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X79F8);
    // 0x800538A4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800538A8: beql        $t7, $zero, L_800538E8
    if (ctx->r15 == 0) {
        // 0x800538AC: lw          $v0, 0x0($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X0);
            goto L_800538E8;
    }
    goto skip_0;
    // 0x800538AC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    skip_0:
    // 0x800538B0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800538B4: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x800538B8: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x800538BC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800538C0: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800538C4: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800538C8: lw          $t0, 0x64($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X64);
    // 0x800538CC: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x800538D0: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x800538D4: lw          $t2, -0x5D88($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X5D88);
    // 0x800538D8: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x800538DC: b           L_80053910
    // 0x800538E0: nop

        goto L_80053910;
    // 0x800538E0: nop

    // 0x800538E4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_800538E8:
    // 0x800538E8: lui         $t4, 0x600
    ctx->r12 = S32(0X600 << 16);
    // 0x800538EC: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x800538F0: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x800538F4: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x800538F8: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x800538FC: lw          $t5, 0x64($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X64);
    // 0x80053900: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80053904: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80053908: lw          $t7, -0x5D98($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5D98);
    // 0x8005390C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
L_80053910:
    // 0x80053910: jal         0x80005740
    // 0x80053914: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Pop(rdram, ctx);
        goto after_12;
    // 0x80053914: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_12:
L_80053918:
    // 0x80053918: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8005391C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80053920: lui         $a2, 0x4189
    ctx->r6 = S32(0X4189 << 16);
    // 0x80053924: lui         $a3, 0xC1CE
    ctx->r7 = S32(0XC1CE << 16);
    // 0x80053928: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8005392C: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x80053930: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80053934: ori         $a3, $a3, 0x6666
    ctx->r7 = ctx->r7 | 0X6666;
    // 0x80053938: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x8005393C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80053940: jal         0x80005B00
    // 0x80053944: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_13;
    // 0x80053944: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_13:
    // 0x80053948: lw          $t9, 0x1D0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1D0);
    // 0x8005394C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80053950: lwc1        $f8, 0x5E88($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5E88);
    // 0x80053954: lwc1        $f6, 0x38($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X38);
    // 0x80053958: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005395C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80053960: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80053964: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80053968: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8005396C: jal         0x80005D44
    // 0x80053970: nop

    Matrix_RotateX(rdram, ctx);
        goto after_14;
    // 0x80053970: nop

    after_14:
    // 0x80053974: jal         0x80006EB8
    // 0x80053978: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_15;
    // 0x80053978: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x8005397C: jal         0x800BA170
    // 0x80053980: nop

    RCP_SetupDL_64_2(rdram, ctx);
        goto after_16;
    // 0x80053980: nop

    after_16:
    // 0x80053984: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x80053988: lw          $t0, 0x7834($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7834);
    // 0x8005398C: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80053990: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80053994: bne         $t0, $at, L_80053A64
    if (ctx->r8 != ctx->r1) {
        // 0x80053998: nop
    
            goto L_80053A64;
    }
    // 0x80053998: nop

    // 0x8005399C: lw          $t1, -0x7D80($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X7D80);
    // 0x800539A0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800539A4: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800539A8: lw          $t2, 0x1C8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X1C8);
    // 0x800539AC: bne         $t2, $at, L_80053A64
    if (ctx->r10 != ctx->r1) {
        // 0x800539B0: nop
    
            goto L_80053A64;
    }
    // 0x800539B0: nop

    // 0x800539B4: lw          $t3, -0x7DCC($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X7DCC);
    // 0x800539B8: lui         $t1, 0x600
    ctx->r9 = S32(0X600 << 16);
    // 0x800539BC: bne         $t3, $zero, L_80053A64
    if (ctx->r11 != 0) {
        // 0x800539C0: nop
    
            goto L_80053A64;
    }
    // 0x800539C0: nop

    // 0x800539C4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800539C8: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x800539CC: addiu       $t6, $zero, -0x88
    ctx->r14 = ADD32(0, -0X88);
    // 0x800539D0: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x800539D4: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x800539D8: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800539DC: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800539E0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800539E4: lui         $t8, 0xB600
    ctx->r24 = S32(0XB600 << 16);
    // 0x800539E8: addiu       $t9, $zero, 0x2000
    ctx->r25 = ADD32(0, 0X2000);
    // 0x800539EC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800539F0: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800539F4: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800539F8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800539FC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80053A00: lui         $t2, 0x302
    ctx->r10 = S32(0X302 << 16);
    // 0x80053A04: addiu       $t2, $t2, -0x6B20
    ctx->r10 = ADD32(ctx->r10, -0X6B20);
    // 0x80053A08: addiu       $t0, $v0, 0x8
    ctx->r8 = ADD32(ctx->r2, 0X8);
    // 0x80053A0C: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x80053A10: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x80053A14: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x80053A18: jal         0x800BA0E0
    // 0x80053A1C: nop

    RCP_SetupDL_46(rdram, ctx);
        goto after_17;
    // 0x80053A1C: nop

    after_17:
    // 0x80053A20: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80053A24: lui         $t4, 0xFA00
    ctx->r12 = S32(0XFA00 << 16);
    // 0x80053A28: addiu       $t5, $zero, -0x9C
    ctx->r13 = ADD32(0, -0X9C);
    // 0x80053A2C: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x80053A30: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x80053A34: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x80053A38: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80053A3C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80053A40: lui         $t8, 0x302
    ctx->r24 = S32(0X302 << 16);
    // 0x80053A44: addiu       $t8, $t8, -0x7C30
    ctx->r24 = ADD32(ctx->r24, -0X7C30);
    // 0x80053A48: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80053A4C: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80053A50: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80053A54: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80053A58: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80053A5C: b           L_80053AC8
    // 0x80053A60: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
        goto L_80053AC8;
    // 0x80053A60: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_80053A64:
    // 0x80053A64: jal         0x800BA0E0
    // 0x80053A68: nop

    RCP_SetupDL_46(rdram, ctx);
        goto after_18;
    // 0x80053A68: nop

    after_18:
    // 0x80053A6C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80053A70: lui         $t0, 0xFA00
    ctx->r8 = S32(0XFA00 << 16);
    // 0x80053A74: addiu       $t1, $zero, -0x74
    ctx->r9 = ADD32(0, -0X74);
    // 0x80053A78: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80053A7C: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80053A80: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x80053A84: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x80053A88: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80053A8C: lui         $t3, 0xB600
    ctx->r11 = S32(0XB600 << 16);
    // 0x80053A90: addiu       $t4, $zero, 0x2000
    ctx->r12 = ADD32(0, 0X2000);
    // 0x80053A94: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x80053A98: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x80053A9C: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80053AA0: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80053AA4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80053AA8: lui         $t7, 0x302
    ctx->r15 = S32(0X302 << 16);
    // 0x80053AAC: addiu       $t7, $t7, -0x6B20
    ctx->r15 = ADD32(ctx->r15, -0X6B20);
    // 0x80053AB0: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x80053AB4: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x80053AB8: lui         $t6, 0x600
    ctx->r14 = S32(0X600 << 16);
    // 0x80053ABC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80053AC0: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80053AC4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_80053AC8:
    // 0x80053AC8: lui         $t9, 0xB700
    ctx->r25 = S32(0XB700 << 16);
    // 0x80053ACC: addiu       $t0, $zero, 0x2000
    ctx->r8 = ADD32(0, 0X2000);
    // 0x80053AD0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80053AD4: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80053AD8: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x80053ADC: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80053AE0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80053AE4: jal         0x80005740
    // 0x80053AE8: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Pop(rdram, ctx);
        goto after_19;
    // 0x80053AE8: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_19:
    // 0x80053AEC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80053AF0: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80053AF4: addiu       $sp, $sp, 0x1D0
    ctx->r29 = ADD32(ctx->r29, 0X1D0);
    // 0x80053AF8: jr          $ra
    // 0x80053AFC: nop

    return;
    // 0x80053AFC: nop

;}
RECOMP_FUNC void Sprite168_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059850: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80059854: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80059858: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8005985C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80059860: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x80059864: jal         0x800B8DD0
    // 0x80059868: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x80059868: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_0:
    // 0x8005986C: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80059870: addiu       $t0, $t0, 0x7E64
    ctx->r8 = ADD32(ctx->r8, 0X7E64);
    // 0x80059874: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x80059878: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x8005987C: addiu       $t8, $zero, -0xC4
    ctx->r24 = ADD32(0, -0XC4);
    // 0x80059880: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80059884: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x80059888: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8005988C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80059890: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80059894: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80059898: lw          $t1, -0x7C24($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X7C24);
    // 0x8005989C: lw          $t9, -0x7C28($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7C28);
    // 0x800598A0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800598A4: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800598A8: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x800598AC: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x800598B0: lw          $a3, -0x7CC8($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X7CC8);
    // 0x800598B4: lw          $a2, -0x7CD0($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7CD0);
    // 0x800598B8: lw          $a1, -0x7CD8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7CD8);
    // 0x800598BC: lw          $a0, -0x7CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7CE0);
    // 0x800598C0: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x800598C4: jal         0x800B9B38
    // 0x800598C8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    RCP_SetupDL_60(rdram, ctx);
        goto after_1;
    // 0x800598C8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_1:
    // 0x800598CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800598D0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800598D4: jr          $ra
    // 0x800598D8: nop

    return;
    // 0x800598D8: nop

;}
RECOMP_FUNC void Math_FAcosF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001FE30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001FE34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001FE38: jal         0x8001FE00
    // 0x8001FE3C: nop

    Math_FAsinF(rdram, ctx);
        goto after_0;
    // 0x8001FE3C: nop

    after_0:
    // 0x8001FE40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001FE44: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001FE48: lwc1        $f4, -0x6CD8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6CD8);
    // 0x8001FE4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001FE50: jr          $ra
    // 0x8001FE54: sub.s       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f0.fl;
    return;
    // 0x8001FE54: sub.s       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f0.fl;
;}
RECOMP_FUNC void func_col1_80097730(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80097730: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x80097734: lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // 0x80097738: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x8009773C: lui         $a3, 0x8016
    ctx->r7 = S32(0X8016 << 16);
    // 0x80097740: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x80097744: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x80097748: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x8009774C: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x80097750: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x80097754: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x80097758: addiu       $t5, $t5, 0x1950
    ctx->r13 = ADD32(ctx->r13, 0X1950);
    // 0x8009775C: addiu       $t4, $t4, 0x1988
    ctx->r12 = ADD32(ctx->r12, 0X1988);
    // 0x80097760: addiu       $t3, $t3, 0x1984
    ctx->r11 = ADD32(ctx->r11, 0X1984);
    // 0x80097764: addiu       $t2, $t2, 0x1980
    ctx->r10 = ADD32(ctx->r10, 0X1980);
    // 0x80097768: addiu       $t1, $t1, 0x197C
    ctx->r9 = ADD32(ctx->r9, 0X197C);
    // 0x8009776C: addiu       $t0, $t0, 0x1978
    ctx->r8 = ADD32(ctx->r8, 0X1978);
    // 0x80097770: addiu       $a3, $a3, 0x1974
    ctx->r7 = ADD32(ctx->r7, 0X1974);
    // 0x80097774: addiu       $a2, $a2, 0x1970
    ctx->r6 = ADD32(ctx->r6, 0X1970);
    // 0x80097778: addiu       $v1, $v1, 0x196C
    ctx->r3 = ADD32(ctx->r3, 0X196C);
    // 0x8009777C: addiu       $v0, $v0, 0x1968
    ctx->r2 = ADD32(ctx->r2, 0X1968);
    // 0x80097780: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80097784: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80097788: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    // 0x8009778C: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x80097790: lwc1        $f6, -0x14($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, -0X14);
    // 0x80097794: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
    // 0x80097798: lwc1        $f8, -0x10($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, -0X10);
    // 0x8009779C: swc1        $f8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f8.u32l;
    // 0x800977A0: lwc1        $f10, -0xC($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, -0XC);
    // 0x800977A4: swc1        $f10, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f10.u32l;
    // 0x800977A8: lwc1        $f16, -0x8($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, -0X8);
    // 0x800977AC: lwc1        $f0, 0x0($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X0);
    // 0x800977B0: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800977B4: swc1        $f16, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f16.u32l;
    // 0x800977B8: lwc1        $f18, -0x4($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, -0X4);
    // 0x800977BC: sub.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x800977C0: swc1        $f18, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f18.u32l;
    // 0x800977C4: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800977C8: swc1        $f4, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f4.u32l;
    // 0x800977CC: lwc1        $f6, 0x4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800977D0: lwc1        $f18, 0x0($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X0);
    // 0x800977D4: swc1        $f6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f6.u32l;
    // 0x800977D8: sub.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f0.fl;
    // 0x800977DC: lwc1        $f8, 0x8($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800977E0: swc1        $f16, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f16.u32l;
    // 0x800977E4: swc1        $f8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f8.u32l;
    // 0x800977E8: swc1        $f4, 0x1954($at)
    MEM_W(0X1954, ctx->r1) = ctx->f4.u32l;
    // 0x800977EC: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800977F0: lwc1        $f2, 0x0($t0)
    ctx->f2.u32l = MEM_W(ctx->r8, 0X0);
    // 0x800977F4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800977F8: sub.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f6.fl;
    // 0x800977FC: swc1        $f8, 0x1958($at)
    MEM_W(0X1958, ctx->r1) = ctx->f8.u32l;
    // 0x80097800: lwc1        $f10, 0x0($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X0);
    // 0x80097804: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80097808: sub.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f2.fl;
    // 0x8009780C: swc1        $f16, 0x195C($at)
    MEM_W(0X195C, ctx->r1) = ctx->f16.u32l;
    // 0x80097810: lwc1        $f18, 0x0($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80097814: lwc1        $f12, 0x0($t1)
    ctx->f12.u32l = MEM_W(ctx->r9, 0X0);
    // 0x80097818: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8009781C: sub.s       $f4, $f12, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f12.fl - ctx->f18.fl;
    // 0x80097820: swc1        $f4, 0x1960($at)
    MEM_W(0X1960, ctx->r1) = ctx->f4.u32l;
    // 0x80097824: lwc1        $f6, 0x0($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X0);
    // 0x80097828: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8009782C: sub.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f12.fl;
    // 0x80097830: swc1        $f8, 0x1964($at)
    MEM_W(0X1964, ctx->r1) = ctx->f8.u32l;
    // 0x80097834: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80097838: lwc1        $f10, 0x1958($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X1958);
    // 0x8009783C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80097840: lwc1        $f16, 0x1964($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X1964);
    // 0x80097844: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80097848: lwc1        $f4, 0x1960($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X1960);
    // 0x8009784C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80097850: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80097854: lwc1        $f6, 0x195C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X195C);
    // 0x80097858: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8009785C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80097860: sub.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x80097864: swc1        $f10, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f10.u32l;
    // 0x80097868: lwc1        $f16, 0x1960($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X1960);
    // 0x8009786C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80097870: lwc1        $f4, 0x1954($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X1954);
    // 0x80097874: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80097878: lwc1        $f8, 0x1964($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X1964);
    // 0x8009787C: mul.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x80097880: lwc1        $f18, 0x0($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0X0);
    // 0x80097884: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80097888: mul.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x8009788C: sub.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80097890: swc1        $f16, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f16.u32l;
    // 0x80097894: lwc1        $f18, 0x195C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X195C);
    // 0x80097898: lwc1        $f4, 0x0($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X0);
    // 0x8009789C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800978A0: lwc1        $f6, 0x1958($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X1958);
    // 0x800978A4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800978A8: mul.s       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x800978AC: lwc1        $f10, 0x1954($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X1954);
    // 0x800978B0: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800978B4: sub.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x800978B8: swc1        $f4, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f4.u32l;
    // 0x800978BC: jr          $ra
    // 0x800978C0: nop

    return;
    // 0x800978C0: nop

;}
RECOMP_FUNC void HUD_RadioDamage_Type(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B774: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8008B778: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8008B77C: lw          $v0, -0x7D5C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D5C);
    // 0x8008B780: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8008B784: slti        $at, $v0, 0x20
    ctx->r1 = SIGNED(ctx->r2) < 0X20 ? 1 : 0;
    // 0x8008B788: bne         $at, $zero, L_8008B7B0
    if (ctx->r1 != 0) {
        // 0x8008B78C: addiu       $t6, $v0, -0xC8
        ctx->r14 = ADD32(ctx->r2, -0XC8);
            goto L_8008B7B0;
    }
    // 0x8008B78C: addiu       $t6, $v0, -0xC8
    ctx->r14 = ADD32(ctx->r2, -0XC8);
    // 0x8008B790: sltiu       $at, $t6, 0x48
    ctx->r1 = ctx->r14 < 0X48 ? 1 : 0;
    // 0x8008B794: beq         $at, $zero, L_8008B830
    if (ctx->r1 == 0) {
        // 0x8008B798: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_8008B830;
    }
    // 0x8008B798: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8008B79C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8008B7A0: addu        $at, $at, $t6
    gpr jr_addend_8008B7A8 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8008B7A4: lw          $t6, 0x7BB8($at)
    ctx->r14 = ADD32(ctx->r1, 0X7BB8);
    // 0x8008B7A8: jr          $t6
    // 0x8008B7AC: nop

    switch (jr_addend_8008B7A8 >> 2) {
        case 0: goto L_8008B800; break;
        case 1: goto L_8008B800; break;
        case 2: goto L_8008B830; break;
        case 3: goto L_8008B830; break;
        case 4: goto L_8008B830; break;
        case 5: goto L_8008B830; break;
        case 6: goto L_8008B830; break;
        case 7: goto L_8008B830; break;
        case 8: goto L_8008B830; break;
        case 9: goto L_8008B830; break;
        case 10: goto L_8008B818; break;
        case 11: goto L_8008B818; break;
        case 12: goto L_8008B830; break;
        case 13: goto L_8008B830; break;
        case 14: goto L_8008B830; break;
        case 15: goto L_8008B830; break;
        case 16: goto L_8008B830; break;
        case 17: goto L_8008B830; break;
        case 18: goto L_8008B830; break;
        case 19: goto L_8008B830; break;
        case 20: goto L_8008B80C; break;
        case 21: goto L_8008B80C; break;
        case 22: goto L_8008B830; break;
        case 23: goto L_8008B830; break;
        case 24: goto L_8008B830; break;
        case 25: goto L_8008B830; break;
        case 26: goto L_8008B830; break;
        case 27: goto L_8008B830; break;
        case 28: goto L_8008B830; break;
        case 29: goto L_8008B830; break;
        case 30: goto L_8008B824; break;
        case 31: goto L_8008B824; break;
        case 32: goto L_8008B830; break;
        case 33: goto L_8008B830; break;
        case 34: goto L_8008B830; break;
        case 35: goto L_8008B830; break;
        case 36: goto L_8008B830; break;
        case 37: goto L_8008B830; break;
        case 38: goto L_8008B830; break;
        case 39: goto L_8008B830; break;
        case 40: goto L_8008B800; break;
        case 41: goto L_8008B800; break;
        case 42: goto L_8008B830; break;
        case 43: goto L_8008B830; break;
        case 44: goto L_8008B830; break;
        case 45: goto L_8008B830; break;
        case 46: goto L_8008B830; break;
        case 47: goto L_8008B830; break;
        case 48: goto L_8008B830; break;
        case 49: goto L_8008B830; break;
        case 50: goto L_8008B818; break;
        case 51: goto L_8008B818; break;
        case 52: goto L_8008B830; break;
        case 53: goto L_8008B830; break;
        case 54: goto L_8008B830; break;
        case 55: goto L_8008B830; break;
        case 56: goto L_8008B830; break;
        case 57: goto L_8008B830; break;
        case 58: goto L_8008B830; break;
        case 59: goto L_8008B830; break;
        case 60: goto L_8008B80C; break;
        case 61: goto L_8008B80C; break;
        case 62: goto L_8008B830; break;
        case 63: goto L_8008B830; break;
        case 64: goto L_8008B830; break;
        case 65: goto L_8008B830; break;
        case 66: goto L_8008B830; break;
        case 67: goto L_8008B830; break;
        case 68: goto L_8008B830; break;
        case 69: goto L_8008B830; break;
        case 70: goto L_8008B824; break;
        case 71: goto L_8008B824; break;
        default: switch_error(__func__, 0x8008B7A8, 0x800D7BB8);
    }
    // 0x8008B7AC: nop

L_8008B7B0:
    // 0x8008B7B0: sltiu       $at, $v0, 0x20
    ctx->r1 = ctx->r2 < 0X20 ? 1 : 0;
    // 0x8008B7B4: beq         $at, $zero, L_8008B830
    if (ctx->r1 == 0) {
        // 0x8008B7B8: sll         $t7, $v0, 2
        ctx->r15 = S32(ctx->r2 << 2);
            goto L_8008B830;
    }
    // 0x8008B7B8: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x8008B7BC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8008B7C0: addu        $at, $at, $t7
    gpr jr_addend_8008B7C8 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8008B7C4: lw          $t7, 0x7CD8($at)
    ctx->r15 = ADD32(ctx->r1, 0X7CD8);
    // 0x8008B7C8: jr          $t7
    // 0x8008B7CC: nop

    switch (jr_addend_8008B7C8 >> 2) {
        case 0: goto L_8008B7D0; break;
        case 1: goto L_8008B7D0; break;
        case 2: goto L_8008B830; break;
        case 3: goto L_8008B830; break;
        case 4: goto L_8008B830; break;
        case 5: goto L_8008B830; break;
        case 6: goto L_8008B830; break;
        case 7: goto L_8008B830; break;
        case 8: goto L_8008B830; break;
        case 9: goto L_8008B830; break;
        case 10: goto L_8008B7DC; break;
        case 11: goto L_8008B7DC; break;
        case 12: goto L_8008B830; break;
        case 13: goto L_8008B830; break;
        case 14: goto L_8008B830; break;
        case 15: goto L_8008B830; break;
        case 16: goto L_8008B830; break;
        case 17: goto L_8008B830; break;
        case 18: goto L_8008B830; break;
        case 19: goto L_8008B830; break;
        case 20: goto L_8008B7E8; break;
        case 21: goto L_8008B7E8; break;
        case 22: goto L_8008B830; break;
        case 23: goto L_8008B830; break;
        case 24: goto L_8008B830; break;
        case 25: goto L_8008B830; break;
        case 26: goto L_8008B830; break;
        case 27: goto L_8008B830; break;
        case 28: goto L_8008B830; break;
        case 29: goto L_8008B830; break;
        case 30: goto L_8008B7F4; break;
        case 31: goto L_8008B7F4; break;
        default: switch_error(__func__, 0x8008B7C8, 0x800D7CD8);
    }
    // 0x8008B7CC: nop

L_8008B7D0:
    // 0x8008B7D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8008B7D4: b           L_8008B838
    // 0x8008B7D8: lw          $a0, 0x4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4);
        goto L_8008B838;
    // 0x8008B7D8: lw          $a0, 0x4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4);
L_8008B7DC:
    // 0x8008B7DC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8008B7E0: b           L_8008B838
    // 0x8008B7E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8008B838;
    // 0x8008B7E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8008B7E8:
    // 0x8008B7E8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8008B7EC: b           L_8008B838
    // 0x8008B7F0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_8008B838;
    // 0x8008B7F0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_8008B7F4:
    // 0x8008B7F4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8008B7F8: b           L_8008B838
    // 0x8008B7FC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_8008B838;
    // 0x8008B7FC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_8008B800:
    // 0x8008B800: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8008B804: b           L_8008B838
    // 0x8008B808: lw          $a0, 0x4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4);
        goto L_8008B838;
    // 0x8008B808: lw          $a0, 0x4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4);
L_8008B80C:
    // 0x8008B80C: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x8008B810: b           L_8008B838
    // 0x8008B814: lw          $a0, 0x4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4);
        goto L_8008B838;
    // 0x8008B814: lw          $a0, 0x4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4);
L_8008B818:
    // 0x8008B818: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x8008B81C: b           L_8008B838
    // 0x8008B820: lw          $a0, 0x4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4);
        goto L_8008B838;
    // 0x8008B820: lw          $a0, 0x4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4);
L_8008B824:
    // 0x8008B824: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x8008B828: b           L_8008B838
    // 0x8008B82C: lw          $a0, 0x4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4);
        goto L_8008B838;
    // 0x8008B82C: lw          $a0, 0x4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4);
L_8008B830:
    // 0x8008B830: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x8008B834: lw          $a0, 0x4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4);
L_8008B838:
    // 0x8008B838: blez        $v0, L_8008B908
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8008B83C: slti        $at, $v0, 0x4
        ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
            goto L_8008B908;
    }
    // 0x8008B83C: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x8008B840: beq         $at, $zero, L_8008B908
    if (ctx->r1 == 0) {
        // 0x8008B844: lui         $t8, 0x8017
        ctx->r24 = S32(0X8017 << 16);
            goto L_8008B908;
    }
    // 0x8008B844: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x8008B848: lw          $t8, 0x7880($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7880);
    // 0x8008B84C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8008B850: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8008B854: bne         $a2, $t8, L_8008B870
    if (ctx->r6 != ctx->r24) {
        // 0x8008B858: lui         $t3, 0x8017
        ctx->r11 = S32(0X8017 << 16);
            goto L_8008B870;
    }
    // 0x8008B858: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x8008B85C: lw          $a1, -0x7DCC($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7DCC);
    // 0x8008B860: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8008B864: beq         $a1, $zero, L_8008B870
    if (ctx->r5 == 0) {
        // 0x8008B868: nop
    
            goto L_8008B870;
    }
    // 0x8008B868: nop

    // 0x8008B86C: bne         $a1, $at, L_8008B908
    if (ctx->r5 != ctx->r1) {
        // 0x8008B870: lui         $a1, 0x8016
        ctx->r5 = S32(0X8016 << 16);
            goto L_8008B908;
    }
L_8008B870:
    // 0x8008B870: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8008B874: addiu       $a1, $a1, 0x3FE0
    ctx->r5 = ADD32(ctx->r5, 0X3FE0);
    // 0x8008B878: addiu       $t3, $t3, -0xEF0
    ctx->r11 = ADD32(ctx->r11, -0XEF0);
    // 0x8008B87C: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x8008B880: addiu       $t1, $zero, 0xC6
    ctx->r9 = ADD32(0, 0XC6);
    // 0x8008B884: addiu       $t0, $zero, 0x2B
    ctx->r8 = ADD32(0, 0X2B);
    // 0x8008B888: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x8008B88C: lbu         $t9, 0x0($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X0);
L_8008B890:
    // 0x8008B890: bnel        $a3, $t9, L_8008B8F8
    if (ctx->r7 != ctx->r25) {
        // 0x8008B894: addiu       $a1, $a1, 0x2F4
        ctx->r5 = ADD32(ctx->r5, 0X2F4);
            goto L_8008B8F8;
    }
    goto skip_0;
    // 0x8008B894: addiu       $a1, $a1, 0x2F4
    ctx->r5 = ADD32(ctx->r5, 0X2F4);
    skip_0:
    // 0x8008B898: lw          $t4, 0x80($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X80);
    // 0x8008B89C: bnel        $a0, $t4, L_8008B8F8
    if (ctx->r4 != ctx->r12) {
        // 0x8008B8A0: addiu       $a1, $a1, 0x2F4
        ctx->r5 = ADD32(ctx->r5, 0X2F4);
            goto L_8008B8F8;
    }
    goto skip_1;
    // 0x8008B8A0: addiu       $a1, $a1, 0x2F4
    ctx->r5 = ADD32(ctx->r5, 0X2F4);
    skip_1:
    // 0x8008B8A4: lh          $v0, 0xB4($a1)
    ctx->r2 = MEM_H(ctx->r5, 0XB4);
    // 0x8008B8A8: beql        $a3, $v0, L_8008B8E4
    if (ctx->r7 == ctx->r2) {
        // 0x8008B8AC: lhu         $t6, 0xC6($a1)
        ctx->r14 = MEM_HU(ctx->r5, 0XC6);
            goto L_8008B8E4;
    }
    goto skip_2;
    // 0x8008B8AC: lhu         $t6, 0xC6($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0XC6);
    skip_2:
    // 0x8008B8B0: beql        $t0, $v0, L_8008B8E4
    if (ctx->r8 == ctx->r2) {
        // 0x8008B8B4: lhu         $t6, 0xC6($a1)
        ctx->r14 = MEM_HU(ctx->r5, 0XC6);
            goto L_8008B8E4;
    }
    goto skip_3;
    // 0x8008B8B4: lhu         $t6, 0xC6($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0XC6);
    skip_3:
    // 0x8008B8B8: lhu         $t5, 0x2($a1)
    ctx->r13 = MEM_HU(ctx->r5, 0X2);
    // 0x8008B8BC: bnel        $t1, $t5, L_8008B8F8
    if (ctx->r9 != ctx->r13) {
        // 0x8008B8C0: addiu       $a1, $a1, 0x2F4
        ctx->r5 = ADD32(ctx->r5, 0X2F4);
            goto L_8008B8F8;
    }
    goto skip_4;
    // 0x8008B8C0: addiu       $a1, $a1, 0x2F4
    ctx->r5 = ADD32(ctx->r5, 0X2F4);
    skip_4:
    // 0x8008B8C4: lh          $v0, 0xE4($a1)
    ctx->r2 = MEM_H(ctx->r5, 0XE4);
    // 0x8008B8C8: beql        $a2, $v0, L_8008B8E4
    if (ctx->r6 == ctx->r2) {
        // 0x8008B8CC: lhu         $t6, 0xC6($a1)
        ctx->r14 = MEM_HU(ctx->r5, 0XC6);
            goto L_8008B8E4;
    }
    goto skip_5;
    // 0x8008B8CC: lhu         $t6, 0xC6($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0XC6);
    skip_5:
    // 0x8008B8D0: beql        $a3, $v0, L_8008B8E4
    if (ctx->r7 == ctx->r2) {
        // 0x8008B8D4: lhu         $t6, 0xC6($a1)
        ctx->r14 = MEM_HU(ctx->r5, 0XC6);
            goto L_8008B8E4;
    }
    goto skip_6;
    // 0x8008B8D4: lhu         $t6, 0xC6($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0XC6);
    skip_6:
    // 0x8008B8D8: bnel        $t2, $v0, L_8008B8F8
    if (ctx->r10 != ctx->r2) {
        // 0x8008B8DC: addiu       $a1, $a1, 0x2F4
        ctx->r5 = ADD32(ctx->r5, 0X2F4);
            goto L_8008B8F8;
    }
    goto skip_7;
    // 0x8008B8DC: addiu       $a1, $a1, 0x2F4
    ctx->r5 = ADD32(ctx->r5, 0X2F4);
    skip_7:
    // 0x8008B8E0: lhu         $t6, 0xC6($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0XC6);
L_8008B8E4:
    // 0x8008B8E4: beql        $t6, $zero, L_8008B908
    if (ctx->r14 == 0) {
        // 0x8008B8E8: addiu       $v0, $zero, 0x9
        ctx->r2 = ADD32(0, 0X9);
            goto L_8008B908;
    }
    goto skip_8;
    // 0x8008B8E8: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    skip_8:
    // 0x8008B8EC: b           L_8008B904
    // 0x8008B8F0: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
        goto L_8008B904;
    // 0x8008B8F0: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x8008B8F4: addiu       $a1, $a1, 0x2F4
    ctx->r5 = ADD32(ctx->r5, 0X2F4);
L_8008B8F8:
    // 0x8008B8F8: sltu        $at, $a1, $t3
    ctx->r1 = ctx->r5 < ctx->r11 ? 1 : 0;
    // 0x8008B8FC: bnel        $at, $zero, L_8008B890
    if (ctx->r1 != 0) {
        // 0x8008B900: lbu         $t9, 0x0($a1)
        ctx->r25 = MEM_BU(ctx->r5, 0X0);
            goto L_8008B890;
    }
    goto skip_9;
    // 0x8008B900: lbu         $t9, 0x0($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X0);
    skip_9:
L_8008B904:
    // 0x8008B904: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
L_8008B908:
    // 0x8008B908: sltiu       $at, $v0, 0xA
    ctx->r1 = ctx->r2 < 0XA ? 1 : 0;
    // 0x8008B90C: beq         $at, $zero, L_8008B9A8
    if (ctx->r1 == 0) {
        // 0x8008B910: addiu       $a2, $zero, 0x1
        ctx->r6 = ADD32(0, 0X1);
            goto L_8008B9A8;
    }
    // 0x8008B910: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8008B914: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x8008B918: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8008B91C: addu        $at, $at, $t7
    gpr jr_addend_8008B924 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8008B920: lw          $t7, 0x7D58($at)
    ctx->r15 = ADD32(ctx->r1, 0X7D58);
    // 0x8008B924: jr          $t7
    // 0x8008B928: nop

    switch (jr_addend_8008B924 >> 2) {
        case 0: goto L_8008B92C; break;
        case 1: goto L_8008B9A8; break;
        case 2: goto L_8008B9A8; break;
        case 3: goto L_8008B9A8; break;
        case 4: goto L_8008B948; break;
        case 5: goto L_8008B948; break;
        case 6: goto L_8008B948; break;
        case 7: goto L_8008B948; break;
        case 8: goto L_8008B9DC; break;
        case 9: goto L_8008B9DC; break;
        default: switch_error(__func__, 0x8008B924, 0x800D7D58);
    }
    // 0x8008B928: nop

L_8008B92C:
    // 0x8008B92C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8008B930: lw          $t8, -0x7D80($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7D80);
    // 0x8008B934: lw          $t9, 0x220($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X220);
    // 0x8008B938: beql        $t9, $zero, L_8008B9E0
    if (ctx->r25 == 0) {
        // 0x8008B93C: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8008B9E0;
    }
    goto skip_10;
    // 0x8008B93C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_10:
    // 0x8008B940: b           L_8008B9DC
    // 0x8008B944: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_8008B9DC;
    // 0x8008B944: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8008B948:
    // 0x8008B948: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x8008B94C: lw          $t4, 0x7880($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7880);
    // 0x8008B950: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x8008B954: subu        $t5, $t5, $v0
    ctx->r13 = SUB32(ctx->r13, ctx->r2);
    // 0x8008B958: bne         $a2, $t4, L_8008B9DC
    if (ctx->r6 != ctx->r12) {
        // 0x8008B95C: sll         $t5, $t5, 4
        ctx->r13 = S32(ctx->r13 << 4);
            goto L_8008B9DC;
    }
    // 0x8008B95C: sll         $t5, $t5, 4
    ctx->r13 = S32(ctx->r13 << 4);
    // 0x8008B960: subu        $t5, $t5, $v0
    ctx->r13 = SUB32(ctx->r13, ctx->r2);
    // 0x8008B964: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8008B968: addu        $t5, $t5, $v0
    ctx->r13 = ADD32(ctx->r13, ctx->r2);
    // 0x8008B96C: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x8008B970: addiu       $t6, $t6, 0x3FE0
    ctx->r14 = ADD32(ctx->r14, 0X3FE0);
    // 0x8008B974: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8008B978: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    // 0x8008B97C: lhu         $t7, 0xC6($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0XC6);
    // 0x8008B980: beq         $t7, $zero, L_8008B98C
    if (ctx->r15 == 0) {
        // 0x8008B984: nop
    
            goto L_8008B98C;
    }
    // 0x8008B984: nop

    // 0x8008B988: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
L_8008B98C:
    // 0x8008B98C: bnel        $v1, $a2, L_8008B9E0
    if (ctx->r3 != ctx->r6) {
        // 0x8008B990: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8008B9E0;
    }
    goto skip_11;
    // 0x8008B990: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_11:
    // 0x8008B994: lh          $t8, 0xCE($a1)
    ctx->r24 = MEM_H(ctx->r5, 0XCE);
    // 0x8008B998: bgtzl       $t8, L_8008B9E0
    if (SIGNED(ctx->r24) > 0) {
        // 0x8008B99C: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8008B9E0;
    }
    goto skip_12;
    // 0x8008B99C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_12:
    // 0x8008B9A0: b           L_8008B9DC
    // 0x8008B9A4: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
        goto L_8008B9DC;
    // 0x8008B9A4: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
L_8008B9A8:
    // 0x8008B9A8: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x8008B9AC: subu        $t9, $t9, $v0
    ctx->r25 = SUB32(ctx->r25, ctx->r2);
    // 0x8008B9B0: sll         $t9, $t9, 4
    ctx->r25 = S32(ctx->r25 << 4);
    // 0x8008B9B4: subu        $t9, $t9, $v0
    ctx->r25 = SUB32(ctx->r25, ctx->r2);
    // 0x8008B9B8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8008B9BC: addu        $t9, $t9, $v0
    ctx->r25 = ADD32(ctx->r25, ctx->r2);
    // 0x8008B9C0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8008B9C4: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x8008B9C8: addu        $t4, $t4, $t9
    ctx->r12 = ADD32(ctx->r12, ctx->r25);
    // 0x8008B9CC: lhu         $t4, 0x40A6($t4)
    ctx->r12 = MEM_HU(ctx->r12, 0X40A6);
    // 0x8008B9D0: beql        $t4, $zero, L_8008B9E0
    if (ctx->r12 == 0) {
        // 0x8008B9D4: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8008B9E0;
    }
    goto skip_13;
    // 0x8008B9D4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_13:
    // 0x8008B9D8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8008B9DC:
    // 0x8008B9DC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8008B9E0:
    // 0x8008B9E0: jr          $ra
    // 0x8008B9E4: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8008B9E4: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_tank_80047FBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80047FBC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80047FC0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80047FC4: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80047FC8: addiu       $v0, $v0, -0x60F8
    ctx->r2 = ADD32(ctx->r2, -0X60F8);
    // 0x80047FCC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80047FD0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80047FD4: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x80047FD8: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80047FDC: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80047FE0: bnel        $t7, $zero, L_800480AC
    if (ctx->r15 != 0) {
        // 0x80047FE4: lwc1        $f10, 0xC8($s0)
        ctx->f10.u32l = MEM_W(ctx->r16, 0XC8);
            goto L_800480AC;
    }
    goto skip_0;
    // 0x80047FE4: lwc1        $f10, 0xC8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC8);
    skip_0:
    // 0x80047FE8: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80047FEC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80047FF0: lwc1        $f4, 0xC8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x80047FF4: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80047FF8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80047FFC: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80048000: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80048004: lwc1        $f4, 0x5734($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5734);
    // 0x80048008: lui         $a2, 0x3ECC
    ctx->r6 = S32(0X3ECC << 16);
    // 0x8004800C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80048010: addiu       $a0, $s0, 0xEC
    ctx->r4 = ADD32(ctx->r16, 0XEC);
    // 0x80048014: lui         $a3, 0x4100
    ctx->r7 = S32(0X4100 << 16);
    // 0x80048018: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8004801C: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80048020: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x80048024: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80048028: jal         0x8009BC2C
    // 0x8004802C: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_0;
    // 0x8004802C: nop

    after_0:
    // 0x80048030: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80048034: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80048038: lwc1        $f6, 0xEC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x8004803C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80048040: addiu       $v0, $v0, -0x60F8
    ctx->r2 = ADD32(ctx->r2, -0X60F8);
    // 0x80048044: c.le.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl <= ctx->f6.fl;
    // 0x80048048: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8004804C: bc1fl       L_8004811C
    if (!c1cs) {
        // 0x80048050: lbu         $t5, 0x0($v0)
        ctx->r13 = MEM_BU(ctx->r2, 0X0);
            goto L_8004811C;
    }
    goto skip_1;
    // 0x80048050: lbu         $t5, 0x0($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X0);
    skip_1:
    // 0x80048054: lw          $t8, -0x7D80($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7D80);
    // 0x80048058: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8004805C: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80048060: lw          $t9, 0x1C8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X1C8);
    // 0x80048064: lui         $a0, 0x1900
    ctx->r4 = S32(0X1900 << 16);
    // 0x80048068: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8004806C: beq         $t9, $at, L_80048098
    if (ctx->r25 == ctx->r1) {
        // 0x80048070: ori         $a0, $a0, 0x65
        ctx->r4 = ctx->r4 | 0X65;
            goto L_80048098;
    }
    // 0x80048070: ori         $a0, $a0, 0x65
    ctx->r4 = ctx->r4 | 0X65;
    // 0x80048074: lui         $t0, 0x800C
    ctx->r8 = S32(0X800C << 16);
    // 0x80048078: addiu       $t0, $t0, 0x5D3C
    ctx->r8 = ADD32(ctx->r8, 0X5D3C);
    // 0x8004807C: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80048080: addiu       $a1, $s0, 0x460
    ctx->r5 = ADD32(ctx->r16, 0X460);
    // 0x80048084: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80048088: jal         0x80019218
    // 0x8004808C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    Audio_PlaySfx(rdram, ctx);
        goto after_1;
    // 0x8004808C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_1:
    // 0x80048090: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80048094: addiu       $v0, $v0, -0x60F8
    ctx->r2 = ADD32(ctx->r2, -0X60F8);
L_80048098:
    // 0x80048098: lbu         $t1, 0x0($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X0);
    // 0x8004809C: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x800480A0: b           L_80048118
    // 0x800480A4: sb          $t2, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r10;
        goto L_80048118;
    // 0x800480A4: sb          $t2, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r10;
    // 0x800480A8: lwc1        $f10, 0xC8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC8);
L_800480AC:
    // 0x800480AC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800480B0: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800480B4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800480B8: div.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800480BC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800480C0: lwc1        $f8, 0x5738($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5738);
    // 0x800480C4: lui         $a2, 0x3ECC
    ctx->r6 = S32(0X3ECC << 16);
    // 0x800480C8: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800480CC: addiu       $a0, $s0, 0xEC
    ctx->r4 = ADD32(ctx->r16, 0XEC);
    // 0x800480D0: lui         $a3, 0x4100
    ctx->r7 = S32(0X4100 << 16);
    // 0x800480D4: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x800480D8: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800480DC: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800480E0: jal         0x8009BC2C
    // 0x800480E4: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_2;
    // 0x800480E4: nop

    after_2:
    // 0x800480E8: lui         $at, 0xC040
    ctx->r1 = S32(0XC040 << 16);
    // 0x800480EC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800480F0: lwc1        $f16, 0xEC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x800480F4: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800480F8: addiu       $v0, $v0, -0x60F8
    ctx->r2 = ADD32(ctx->r2, -0X60F8);
    // 0x800480FC: c.le.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl <= ctx->f10.fl;
    // 0x80048100: nop

    // 0x80048104: bc1fl       L_8004811C
    if (!c1cs) {
        // 0x80048108: lbu         $t5, 0x0($v0)
        ctx->r13 = MEM_BU(ctx->r2, 0X0);
            goto L_8004811C;
    }
    goto skip_2;
    // 0x80048108: lbu         $t5, 0x0($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X0);
    skip_2:
    // 0x8004810C: lbu         $t3, 0x0($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X0);
    // 0x80048110: andi        $t4, $t3, 0xFE
    ctx->r12 = ctx->r11 & 0XFE;
    // 0x80048114: sb          $t4, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r12;
L_80048118:
    // 0x80048118: lbu         $t5, 0x0($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X0);
L_8004811C:
    // 0x8004811C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80048120: andi        $t6, $t5, 0x8
    ctx->r14 = ctx->r13 & 0X8;
    // 0x80048124: bnel        $t6, $zero, L_80048194
    if (ctx->r14 != 0) {
        // 0x80048128: mtc1        $at, $f2
        ctx->f2.u32l = ctx->r1;
            goto L_80048194;
    }
    goto skip_3;
    // 0x80048128: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    skip_3:
    // 0x8004812C: lwc1        $f18, 0xC8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x80048130: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80048134: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80048138: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x8004813C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80048140: div.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80048144: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80048148: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8004814C: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x80048150: nop

    // 0x80048154: bc1fl       L_80048178
    if (!c1cs) {
        // 0x80048158: lwc1        $f4, 0x78($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0X78);
            goto L_80048178;
    }
    goto skip_4;
    // 0x80048158: lwc1        $f4, 0x78($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X78);
    skip_4:
    // 0x8004815C: lwc1        $f10, 0x78($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X78);
    // 0x80048160: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80048164: nop

    // 0x80048168: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8004816C: b           L_80048180
    // 0x80048170: swc1        $f18, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f18.u32l;
        goto L_80048180;
    // 0x80048170: swc1        $f18, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f18.u32l;
    // 0x80048174: lwc1        $f4, 0x78($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X78);
L_80048178:
    // 0x80048178: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x8004817C: swc1        $f6, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f6.u32l;
L_80048180:
    // 0x80048180: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x80048184: ori         $t8, $t7, 0x8
    ctx->r24 = ctx->r15 | 0X8;
    // 0x80048188: b           L_800481E0
    // 0x8004818C: sb          $t8, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r24;
        goto L_800481E0;
    // 0x8004818C: sb          $t8, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r24;
    // 0x80048190: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
L_80048194:
    // 0x80048194: lwc1        $f8, 0xC8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x80048198: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8004819C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800481A0: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x800481A4: div.s       $f0, $f10, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800481A8: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800481AC: nop

    // 0x800481B0: bc1fl       L_800481CC
    if (!c1cs) {
        // 0x800481B4: lwc1        $f6, 0x78($s0)
        ctx->f6.u32l = MEM_W(ctx->r16, 0X78);
            goto L_800481CC;
    }
    goto skip_5;
    // 0x800481B4: lwc1        $f6, 0x78($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X78);
    skip_5:
    // 0x800481B8: lwc1        $f18, 0x78($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X78);
    // 0x800481BC: sub.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f2.fl;
    // 0x800481C0: b           L_800481D4
    // 0x800481C4: swc1        $f4, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f4.u32l;
        goto L_800481D4;
    // 0x800481C4: swc1        $f4, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f4.u32l;
    // 0x800481C8: lwc1        $f6, 0x78($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X78);
L_800481CC:
    // 0x800481CC: sub.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x800481D0: swc1        $f8, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f8.u32l;
L_800481D4:
    // 0x800481D4: lbu         $t9, 0x0($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X0);
    // 0x800481D8: andi        $t0, $t9, 0xF7
    ctx->r8 = ctx->r25 & 0XF7;
    // 0x800481DC: sb          $t0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r8;
L_800481E0:
    // 0x800481E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800481E4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800481E8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800481EC: jr          $ra
    // 0x800481F0: nop

    return;
    // 0x800481F0: nop

;}
RECOMP_FUNC void FoBase_ExplodeCs(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80090200: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80090204: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80090208: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8009020C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80090210: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80090214: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x80090218: lh          $t6, 0x88($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X88);
    // 0x8009021C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80090220: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80090224: bnel        $t6, $at, L_800907B0
    if (ctx->r14 != ctx->r1) {
        // 0x80090228: lw          $v0, 0x30($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X30);
            goto L_800907B0;
    }
    goto skip_0;
    // 0x80090228: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    skip_0:
    // 0x8009022C: jal         0x8008FFF0
    // 0x80090230: addiu       $a1, $zero, 0x2194
    ctx->r5 = ADD32(0, 0X2194);
    FoBase_BurnEffects(rdram, ctx);
        goto after_0;
    // 0x80090230: addiu       $a1, $zero, 0x2194
    ctx->r5 = ADD32(0, 0X2194);
    after_0:
    // 0x80090234: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80090238: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    // 0x8009023C: lh          $v0, 0x8A($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X8A);
    // 0x80090240: lui         $s1, 0x8018
    ctx->r17 = S32(0X8018 << 16);
    // 0x80090244: lw          $s1, -0x7D80($s1)
    ctx->r17 = MEM_W(ctx->r17, -0X7D80);
    // 0x80090248: sltiu       $at, $v0, 0x5
    ctx->r1 = ctx->r2 < 0X5 ? 1 : 0;
    // 0x8009024C: beq         $at, $zero, L_80090630
    if (ctx->r1 == 0) {
        // 0x80090250: sll         $t8, $v0, 2
        ctx->r24 = S32(ctx->r2 << 2);
            goto L_80090630;
    }
    // 0x80090250: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x80090254: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80090258: addu        $at, $at, $t8
    gpr jr_addend_80090260 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8009025C: lw          $t8, 0x7EC8($at)
    ctx->r24 = ADD32(ctx->r1, 0X7EC8);
    // 0x80090260: jr          $t8
    // 0x80090264: nop

    switch (jr_addend_80090260 >> 2) {
        case 0: goto L_80090268; break;
        case 1: goto L_80090360; break;
        case 2: goto L_80090468; break;
        case 3: goto L_8009054C; break;
        case 4: goto L_80090628; break;
        default: switch_error(__func__, 0x80090260, 0x800D7EC8);
    }
    // 0x80090264: nop

L_80090268:
    // 0x80090268: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8009026C: lui         $t9, 0x800C
    ctx->r25 = S32(0X800C << 16);
    // 0x80090270: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80090274: addiu       $t9, $t9, 0x5D3C
    ctx->r25 = ADD32(ctx->r25, 0X5D3C);
    // 0x80090278: lui         $a0, 0x1100
    ctx->r4 = S32(0X1100 << 16);
    // 0x8009027C: addiu       $a1, $s0, 0x3FC
    ctx->r5 = ADD32(ctx->r16, 0X3FC);
    // 0x80090280: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x80090284: ori         $a0, $a0, 0x11
    ctx->r4 = ctx->r4 | 0X11;
    // 0x80090288: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8009028C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80090290: jal         0x80019218
    // 0x80090294: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Audio_PlaySfx(rdram, ctx);
        goto after_1;
    // 0x80090294: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80090298: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8009029C: lui         $t0, 0x800C
    ctx->r8 = S32(0X800C << 16);
    // 0x800902A0: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x800902A4: addiu       $t0, $t0, 0x5D3C
    ctx->r8 = ADD32(ctx->r8, 0X5D3C);
    // 0x800902A8: lui         $a0, 0x3140
    ctx->r4 = S32(0X3140 << 16);
    // 0x800902AC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x800902B0: ori         $a0, $a0, 0x402E
    ctx->r4 = ctx->r4 | 0X402E;
    // 0x800902B4: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x800902B8: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x800902BC: jal         0x80019218
    // 0x800902C0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Audio_PlaySfx(rdram, ctx);
        goto after_2;
    // 0x800902C0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x800902C4: lui         $a0, 0x1032
    ctx->r4 = S32(0X1032 << 16);
    // 0x800902C8: jal         0x800182F4
    // 0x800902CC: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_3;
    // 0x800902CC: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    after_3:
    // 0x800902D0: lui         $a0, 0x1132
    ctx->r4 = S32(0X1132 << 16);
    // 0x800902D4: jal         0x800182F4
    // 0x800902D8: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_4;
    // 0x800902D8: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    after_4:
    // 0x800902DC: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800902E0: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x800902E4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800902E8: swc1        $f0, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f0.u32l;
    // 0x800902EC: swc1        $f0, 0x40($s1)
    MEM_W(0X40, ctx->r17) = ctx->f0.u32l;
    // 0x800902F0: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800902F4: lui         $at, 0x457A
    ctx->r1 = S32(0X457A << 16);
    // 0x800902F8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800902FC: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80090300: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80090304: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80090308: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8009030C: swc1        $f0, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f0.u32l;
    // 0x80090310: swc1        $f0, 0x44($s1)
    MEM_W(0X44, ctx->r17) = ctx->f0.u32l;
    // 0x80090314: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80090318: addiu       $t1, $zero, 0x3E8
    ctx->r9 = ADD32(0, 0X3E8);
    // 0x8009031C: add.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80090320: swc1        $f0, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f0.u32l;
    // 0x80090324: swc1        $f0, 0x48($s1)
    MEM_W(0X48, ctx->r17) = ctx->f0.u32l;
    // 0x80090328: lwc1        $f16, 0x4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8009032C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80090330: swc1        $f16, 0x4C($s1)
    MEM_W(0X4C, ctx->r17) = ctx->f16.u32l;
    // 0x80090334: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80090338: swc1        $f18, 0x50($s1)
    MEM_W(0X50, ctx->r17) = ctx->f18.u32l;
    // 0x8009033C: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80090340: swc1        $f4, 0x54($s1)
    MEM_W(0X54, ctx->r17) = ctx->f4.u32l;
    // 0x80090344: sh          $t2, 0x8A($s0)
    MEM_H(0X8A, ctx->r16) = ctx->r10;
    // 0x80090348: sh          $t1, 0x50($s0)
    MEM_H(0X50, ctx->r16) = ctx->r9;
    // 0x8009034C: lh          $v0, 0x8A($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X8A);
    // 0x80090350: swc1        $f6, 0xFC($s0)
    MEM_W(0XFC, ctx->r16) = ctx->f6.u32l;
    // 0x80090354: swc1        $f0, 0xF4($s0)
    MEM_W(0XF4, ctx->r16) = ctx->f0.u32l;
    // 0x80090358: b           L_80090630
    // 0x8009035C: swc1        $f0, 0xF8($s0)
    MEM_W(0XF8, ctx->r16) = ctx->f0.u32l;
        goto L_80090630;
    // 0x8009035C: swc1        $f0, 0xF8($s0)
    MEM_W(0XF8, ctx->r16) = ctx->f0.u32l;
L_80090360:
    // 0x80090360: lh          $t3, 0x50($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X50);
    // 0x80090364: addiu       $at, $zero, 0x3A2
    ctx->r1 = ADD32(0, 0X3A2);
    // 0x80090368: addiu       $a0, $s0, 0xFC
    ctx->r4 = ADD32(ctx->r16, 0XFC);
    // 0x8009036C: bne         $t3, $at, L_8009037C
    if (ctx->r11 != ctx->r1) {
        // 0x80090370: lui         $a1, 0x42A0
        ctx->r5 = S32(0X42A0 << 16);
            goto L_8009037C;
    }
    // 0x80090370: lui         $a1, 0x42A0
    ctx->r5 = S32(0X42A0 << 16);
    // 0x80090374: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x80090378: sh          $t4, 0x8A($s0)
    MEM_H(0X8A, ctx->r16) = ctx->r12;
L_8009037C:
    // 0x8009037C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80090380: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80090384: lwc1        $f8, 0xF4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XF4);
    // 0x80090388: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8009038C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80090390: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80090394: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80090398: lui         $a2, 0x3C23
    ctx->r6 = S32(0X3C23 << 16);
    // 0x8009039C: ori         $a2, $a2, 0xD70A
    ctx->r6 = ctx->r6 | 0XD70A;
    // 0x800903A0: swc1        $f16, 0xF4($s0)
    MEM_W(0XF4, ctx->r16) = ctx->f16.u32l;
    // 0x800903A4: lwc1        $f18, 0xF4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XF4);
    // 0x800903A8: lui         $a3, 0x461C
    ctx->r7 = S32(0X461C << 16);
    // 0x800903AC: c.le.s      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.fl <= ctx->f18.fl;
    // 0x800903B0: nop

    // 0x800903B4: bc1fl       L_800903CC
    if (!c1cs) {
        // 0x800903B8: ori         $a3, $a3, 0x4000
        ctx->r7 = ctx->r7 | 0X4000;
            goto L_800903CC;
    }
    goto skip_1;
    // 0x800903B8: ori         $a3, $a3, 0x4000
    ctx->r7 = ctx->r7 | 0X4000;
    skip_1:
    // 0x800903BC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800903C0: nop

    // 0x800903C4: swc1        $f6, 0xF4($s0)
    MEM_W(0XF4, ctx->r16) = ctx->f6.u32l;
    // 0x800903C8: ori         $a3, $a3, 0x4000
    ctx->r7 = ctx->r7 | 0X4000;
L_800903CC:
    // 0x800903CC: jal         0x8009BC2C
    // 0x800903D0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_5;
    // 0x800903D0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_5:
    // 0x800903D4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800903D8: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x800903DC: lui         $a2, 0x3CA3
    ctx->r6 = S32(0X3CA3 << 16);
    // 0x800903E0: lui         $a3, 0x461C
    ctx->r7 = S32(0X461C << 16);
    // 0x800903E4: ori         $a3, $a3, 0x4000
    ctx->r7 = ctx->r7 | 0X4000;
    // 0x800903E8: ori         $a2, $a2, 0xD70A
    ctx->r6 = ctx->r6 | 0XD70A;
    // 0x800903EC: addiu       $a0, $s0, 0xE8
    ctx->r4 = ADD32(ctx->r16, 0XE8);
    // 0x800903F0: jal         0x8009BC2C
    // 0x800903F4: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_6;
    // 0x800903F4: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_6:
    // 0x800903F8: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x800903FC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80090400: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80090404: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80090408: lui         $a2, 0x3CA3
    ctx->r6 = S32(0X3CA3 << 16);
    // 0x8009040C: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80090410: lui         $a3, 0x461C
    ctx->r7 = S32(0X461C << 16);
    // 0x80090414: ori         $a3, $a3, 0x4000
    ctx->r7 = ctx->r7 | 0X4000;
    // 0x80090418: ori         $a2, $a2, 0xD70A
    ctx->r6 = ctx->r6 | 0XD70A;
    // 0x8009041C: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80090420: addiu       $a0, $s0, 0xEC
    ctx->r4 = ADD32(ctx->r16, 0XEC);
    // 0x80090424: jal         0x8009BC2C
    // 0x80090428: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_7;
    // 0x80090428: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_7:
    // 0x8009042C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80090430: lwc1        $f10, 0x7EDC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7EDC);
    // 0x80090434: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80090438: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8009043C: lui         $a2, 0x3CA3
    ctx->r6 = S32(0X3CA3 << 16);
    // 0x80090440: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80090444: lui         $a3, 0x461C
    ctx->r7 = S32(0X461C << 16);
    // 0x80090448: ori         $a3, $a3, 0x4000
    ctx->r7 = ctx->r7 | 0X4000;
    // 0x8009044C: ori         $a2, $a2, 0xD70A
    ctx->r6 = ctx->r6 | 0XD70A;
    // 0x80090450: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x80090454: addiu       $a0, $s0, 0xF0
    ctx->r4 = ADD32(ctx->r16, 0XF0);
    // 0x80090458: jal         0x8009BC2C
    // 0x8009045C: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_8;
    // 0x8009045C: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_8:
    // 0x80090460: b           L_80090630
    // 0x80090464: lh          $v0, 0x8A($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X8A);
        goto L_80090630;
    // 0x80090464: lh          $v0, 0x8A($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X8A);
L_80090468:
    // 0x80090468: lh          $t5, 0x50($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X50);
    // 0x8009046C: addiu       $at, $zero, 0x366
    ctx->r1 = ADD32(0, 0X366);
    // 0x80090470: addiu       $a0, $s0, 0xE8
    ctx->r4 = ADD32(ctx->r16, 0XE8);
    // 0x80090474: bne         $t5, $at, L_80090484
    if (ctx->r13 != ctx->r1) {
        // 0x80090478: lui         $a2, 0x3CA3
        ctx->r6 = S32(0X3CA3 << 16);
            goto L_80090484;
    }
    // 0x80090478: lui         $a2, 0x3CA3
    ctx->r6 = S32(0X3CA3 << 16);
    // 0x8009047C: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x80090480: sh          $t6, 0x8A($s0)
    MEM_H(0X8A, ctx->r16) = ctx->r14;
L_80090484:
    // 0x80090484: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80090488: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8009048C: lwc1        $f4, 0xF4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XF4);
    // 0x80090490: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80090494: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80090498: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8009049C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800904A0: lui         $a3, 0x461C
    ctx->r7 = S32(0X461C << 16);
    // 0x800904A4: ori         $a3, $a3, 0x4000
    ctx->r7 = ctx->r7 | 0X4000;
    // 0x800904A8: swc1        $f8, 0xF4($s0)
    MEM_W(0XF4, ctx->r16) = ctx->f8.u32l;
    // 0x800904AC: lwc1        $f10, 0xF4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XF4);
    // 0x800904B0: ori         $a2, $a2, 0xD70A
    ctx->r6 = ctx->r6 | 0XD70A;
    // 0x800904B4: c.le.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl <= ctx->f10.fl;
    // 0x800904B8: nop

    // 0x800904BC: bc1fl       L_800904D4
    if (!c1cs) {
        // 0x800904C0: lw          $a1, 0x4($s0)
        ctx->r5 = MEM_W(ctx->r16, 0X4);
            goto L_800904D4;
    }
    goto skip_2;
    // 0x800904C0: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    skip_2:
    // 0x800904C4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800904C8: nop

    // 0x800904CC: swc1        $f18, 0xF4($s0)
    MEM_W(0XF4, ctx->r16) = ctx->f18.u32l;
    // 0x800904D0: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
L_800904D4:
    // 0x800904D4: jal         0x8009BC2C
    // 0x800904D8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_9;
    // 0x800904D8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_9:
    // 0x800904DC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800904E0: lwc1        $f8, 0x7EE0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7EE0);
    // 0x800904E4: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800904E8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800904EC: lui         $a2, 0x3CA3
    ctx->r6 = S32(0X3CA3 << 16);
    // 0x800904F0: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800904F4: lui         $a3, 0x461C
    ctx->r7 = S32(0X461C << 16);
    // 0x800904F8: ori         $a3, $a3, 0x4000
    ctx->r7 = ctx->r7 | 0X4000;
    // 0x800904FC: ori         $a2, $a2, 0xD70A
    ctx->r6 = ctx->r6 | 0XD70A;
    // 0x80090500: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80090504: addiu       $a0, $s0, 0xEC
    ctx->r4 = ADD32(ctx->r16, 0XEC);
    // 0x80090508: jal         0x8009BC2C
    // 0x8009050C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_10;
    // 0x8009050C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_10:
    // 0x80090510: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80090514: lwc1        $f4, 0x7EE4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7EE4);
    // 0x80090518: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8009051C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80090520: lui         $a2, 0x3CA3
    ctx->r6 = S32(0X3CA3 << 16);
    // 0x80090524: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80090528: lui         $a3, 0x461C
    ctx->r7 = S32(0X461C << 16);
    // 0x8009052C: ori         $a3, $a3, 0x4000
    ctx->r7 = ctx->r7 | 0X4000;
    // 0x80090530: ori         $a2, $a2, 0xD70A
    ctx->r6 = ctx->r6 | 0XD70A;
    // 0x80090534: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80090538: addiu       $a0, $s0, 0xF0
    ctx->r4 = ADD32(ctx->r16, 0XF0);
    // 0x8009053C: jal         0x8009BC2C
    // 0x80090540: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_11;
    // 0x80090540: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_11:
    // 0x80090544: b           L_80090630
    // 0x80090548: lh          $v0, 0x8A($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X8A);
        goto L_80090630;
    // 0x80090548: lh          $v0, 0x8A($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X8A);
L_8009054C:
    // 0x8009054C: lh          $t7, 0x50($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X50);
    // 0x80090550: addiu       $at, $zero, 0x302
    ctx->r1 = ADD32(0, 0X302);
    // 0x80090554: addiu       $a0, $s0, 0xFC
    ctx->r4 = ADD32(ctx->r16, 0XFC);
    // 0x80090558: bne         $t7, $at, L_80090568
    if (ctx->r15 != ctx->r1) {
        // 0x8009055C: lui         $a1, 0x4120
        ctx->r5 = S32(0X4120 << 16);
            goto L_80090568;
    }
    // 0x8009055C: lui         $a1, 0x4120
    ctx->r5 = S32(0X4120 << 16);
    // 0x80090560: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x80090564: sh          $t8, 0x8A($s0)
    MEM_H(0X8A, ctx->r16) = ctx->r24;
L_80090568:
    // 0x80090568: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8009056C: lui         $a2, 0x3C23
    ctx->r6 = S32(0X3C23 << 16);
    // 0x80090570: lui         $a3, 0x461C
    ctx->r7 = S32(0X461C << 16);
    // 0x80090574: ori         $a3, $a3, 0x4000
    ctx->r7 = ctx->r7 | 0X4000;
    // 0x80090578: ori         $a2, $a2, 0xD70A
    ctx->r6 = ctx->r6 | 0XD70A;
    // 0x8009057C: jal         0x8009BC2C
    // 0x80090580: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_12;
    // 0x80090580: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_12:
    // 0x80090584: lui         $at, 0x457A
    ctx->r1 = S32(0X457A << 16);
    // 0x80090588: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8009058C: lwc1        $f16, 0x4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80090590: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80090594: lui         $a2, 0x3CA3
    ctx->r6 = S32(0X3CA3 << 16);
    // 0x80090598: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8009059C: lui         $a3, 0x461C
    ctx->r7 = S32(0X461C << 16);
    // 0x800905A0: ori         $a3, $a3, 0x4000
    ctx->r7 = ctx->r7 | 0X4000;
    // 0x800905A4: ori         $a2, $a2, 0xD70A
    ctx->r6 = ctx->r6 | 0XD70A;
    // 0x800905A8: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x800905AC: addiu       $a0, $s0, 0xE8
    ctx->r4 = ADD32(ctx->r16, 0XE8);
    // 0x800905B0: jal         0x8009BC2C
    // 0x800905B4: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_13;
    // 0x800905B4: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_13:
    // 0x800905B8: lui         $at, 0x44FA
    ctx->r1 = S32(0X44FA << 16);
    // 0x800905BC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800905C0: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800905C4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800905C8: lui         $a2, 0x3CA3
    ctx->r6 = S32(0X3CA3 << 16);
    // 0x800905CC: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800905D0: lui         $a3, 0x461C
    ctx->r7 = S32(0X461C << 16);
    // 0x800905D4: ori         $a3, $a3, 0x4000
    ctx->r7 = ctx->r7 | 0X4000;
    // 0x800905D8: ori         $a2, $a2, 0xD70A
    ctx->r6 = ctx->r6 | 0XD70A;
    // 0x800905DC: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x800905E0: addiu       $a0, $s0, 0xEC
    ctx->r4 = ADD32(ctx->r16, 0XEC);
    // 0x800905E4: jal         0x8009BC2C
    // 0x800905E8: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_14;
    // 0x800905E8: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_14:
    // 0x800905EC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800905F0: lwc1        $f6, 0x7EE8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7EE8);
    // 0x800905F4: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800905F8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800905FC: lui         $a2, 0x3CA3
    ctx->r6 = S32(0X3CA3 << 16);
    // 0x80090600: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80090604: lui         $a3, 0x461C
    ctx->r7 = S32(0X461C << 16);
    // 0x80090608: ori         $a3, $a3, 0x4000
    ctx->r7 = ctx->r7 | 0X4000;
    // 0x8009060C: ori         $a2, $a2, 0xD70A
    ctx->r6 = ctx->r6 | 0XD70A;
    // 0x80090610: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80090614: addiu       $a0, $s0, 0xF0
    ctx->r4 = ADD32(ctx->r16, 0XF0);
    // 0x80090618: jal         0x8009BC2C
    // 0x8009061C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_15;
    // 0x8009061C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_15:
    // 0x80090620: b           L_80090630
    // 0x80090624: lh          $v0, 0x8A($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X8A);
        goto L_80090630;
    // 0x80090624: lh          $v0, 0x8A($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X8A);
L_80090628:
    // 0x80090628: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8009062C: sw          $t9, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r25;
L_80090630:
    // 0x80090630: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x80090634: beql        $at, $zero, L_800907B0
    if (ctx->r1 == 0) {
        // 0x80090638: lw          $v0, 0x30($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X30);
            goto L_800907B0;
    }
    goto skip_3;
    // 0x80090638: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    skip_3:
    // 0x8009063C: lwc1        $f16, 0xE8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XE8);
    // 0x80090640: lwc1        $f18, 0x4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80090644: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80090648: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8009064C: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80090650: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    // 0x80090654: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80090658: lwc1        $f6, 0xEC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x8009065C: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80090660: swc1        $f10, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f10.u32l;
    // 0x80090664: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80090668: lwc1        $f16, 0xF0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XF0);
    // 0x8009066C: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80090670: swc1        $f4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f4.u32l;
    // 0x80090674: lw          $a3, 0xC($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XC);
    // 0x80090678: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    // 0x8009067C: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x80090680: jal         0x80005B00
    // 0x80090684: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    Matrix_Translate(rdram, ctx);
        goto after_16;
    // 0x80090684: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_16:
    // 0x80090688: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8009068C: lwc1        $f8, 0x7EEC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7EEC);
    // 0x80090690: lwc1        $f6, 0xF4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XF4);
    // 0x80090694: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80090698: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8009069C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800906A0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800906A4: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x800906A8: jal         0x80005E90
    // 0x800906AC: nop

    Matrix_RotateY(rdram, ctx);
        goto after_17;
    // 0x800906AC: nop

    after_17:
    // 0x800906B0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800906B4: lwc1        $f18, 0x7EF0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7EF0);
    // 0x800906B8: lwc1        $f16, 0xF8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XF8);
    // 0x800906BC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800906C0: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x800906C4: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800906C8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800906CC: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x800906D0: jal         0x80005D44
    // 0x800906D4: nop

    Matrix_RotateX(rdram, ctx);
        goto after_18;
    // 0x800906D4: nop

    after_18:
    // 0x800906D8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800906DC: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x800906E0: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x800906E4: jal         0x80006970
    // 0x800906E8: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    Matrix_MultVec3f(rdram, ctx);
        goto after_19;
    // 0x800906E8: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    after_19:
    // 0x800906EC: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800906F0: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x800906F4: swc1        $f6, 0x40($s1)
    MEM_W(0X40, ctx->r17) = ctx->f6.u32l;
    // 0x800906F8: lwc1        $f8, 0x48($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800906FC: swc1        $f8, 0x44($s1)
    MEM_W(0X44, ctx->r17) = ctx->f8.u32l;
    // 0x80090700: lwc1        $f10, 0x4C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80090704: swc1        $f10, 0x48($s1)
    MEM_W(0X48, ctx->r17) = ctx->f10.u32l;
    // 0x80090708: lwc1        $f16, 0x4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8009070C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80090710: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80090714: swc1        $f16, 0x4C($s1)
    MEM_W(0X4C, ctx->r17) = ctx->f16.u32l;
    // 0x80090718: lwc1        $f18, 0x4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8009071C: swc1        $f18, 0x50($s1)
    MEM_W(0X50, ctx->r17) = ctx->f18.u32l;
    // 0x80090720: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80090724: swc1        $f4, 0x54($s1)
    MEM_W(0X54, ctx->r17) = ctx->f4.u32l;
    // 0x80090728: lh          $t0, 0x50($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X50);
    // 0x8009072C: lwc1        $f18, 0x7EF4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7EF4);
    // 0x80090730: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x80090734: nop

    // 0x80090738: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8009073C: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80090740: nop

    // 0x80090744: mul.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80090748: jal         0x80023250
    // 0x8009074C: nop

    __cosf_recomp(rdram, ctx);
        goto after_20;
    // 0x8009074C: nop

    after_20:
    // 0x80090750: lwc1        $f6, 0xFC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XFC);
    // 0x80090754: lwc1        $f4, 0x4C($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4C);
    // 0x80090758: lui         $at, 0x4333
    ctx->r1 = S32(0X4333 << 16);
    // 0x8009075C: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80090760: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80090764: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80090768: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8009076C: swc1        $f10, 0x4C($s1)
    MEM_W(0X4C, ctx->r17) = ctx->f10.u32l;
    // 0x80090770: lh          $t1, 0x50($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X50);
    // 0x80090774: lwc1        $f8, 0x7EF8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7EF8);
    // 0x80090778: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x8009077C: nop

    // 0x80090780: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80090784: mul.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x80090788: nop

    // 0x8009078C: mul.s       $f12, $f4, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80090790: jal         0x80023090
    // 0x80090794: nop

    __sinf_recomp(rdram, ctx);
        goto after_21;
    // 0x80090794: nop

    after_21:
    // 0x80090798: lwc1        $f16, 0xFC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XFC);
    // 0x8009079C: lwc1        $f10, 0x50($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X50);
    // 0x800907A0: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x800907A4: add.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x800907A8: swc1        $f6, 0x50($s1)
    MEM_W(0X50, ctx->r17) = ctx->f6.u32l;
    // 0x800907AC: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
L_800907B0:
    // 0x800907B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800907B4: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800907B8: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800907BC: jr          $ra
    // 0x800907C0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800907C0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void ActorAllRange_UpdateEvents(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003010C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80030110: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80030114: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80030118: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8003011C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80030120: lw          $t6, -0x7D80($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7D80);
    // 0x80030124: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80030128: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003012C: lw          $v0, 0x1C8($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X1C8);
    // 0x80030130: beq         $v0, $at, L_80030140
    if (ctx->r2 == ctx->r1) {
        // 0x80030134: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_80030140;
    }
    // 0x80030134: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80030138: bne         $v0, $at, L_80030150
    if (ctx->r2 != ctx->r1) {
        // 0x8003013C: nop
    
            goto L_80030150;
    }
    // 0x8003013C: nop

L_80030140:
    // 0x80030140: jal         0x80060FBC
    // 0x80030144: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    Object_Kill(rdram, ctx);
        goto after_0;
    // 0x80030144: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    after_0:
    // 0x80030148: b           L_800301E4
    // 0x8003014C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800301E4;
    // 0x8003014C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80030150:
    // 0x80030150: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x80030154: addiu       $v0, $v0, -0x6D8
    ctx->r2 = ADD32(ctx->r2, -0X6D8);
    // 0x80030158: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x8003015C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80030160: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80030164: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80030168: lw          $t9, -0x7DCC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7DCC);
    // 0x8003016C: addiu       $t0, $t9, -0xE
    ctx->r8 = ADD32(ctx->r25, -0XE);
    // 0x80030170: sltiu       $at, $t0, 0x6
    ctx->r1 = ctx->r8 < 0X6 ? 1 : 0;
    // 0x80030174: beq         $at, $zero, L_800301D8
    if (ctx->r1 == 0) {
        // 0x80030178: sll         $t0, $t0, 2
        ctx->r8 = S32(ctx->r8 << 2);
            goto L_800301D8;
    }
    // 0x80030178: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8003017C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80030180: addu        $at, $at, $t0
    gpr jr_addend_80030188 = ctx->r8;
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80030184: lw          $t0, 0x4EAC($at)
    ctx->r8 = ADD32(ctx->r1, 0X4EAC);
    // 0x80030188: jr          $t0
    // 0x8003018C: nop

    switch (jr_addend_80030188 >> 2) {
        case 0: goto L_80030190; break;
        case 1: goto L_800301D8; break;
        case 2: goto L_800301A0; break;
        case 3: goto L_800301B0; break;
        case 4: goto L_800301C0; break;
        case 5: goto L_800301D0; break;
        default: switch_error(__func__, 0x80030188, 0x800D4EAC);
    }
    // 0x8003018C: nop

L_80030190:
    // 0x80030190: jal         0x80187960
    // 0x80030194: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Fortuna_UpdateEvents(rdram, ctx);
        goto after_1;
    // 0x80030194: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80030198: b           L_800301D8
    // 0x8003019C: nop

        goto L_800301D8;
    // 0x8003019C: nop

L_800301A0:
    // 0x800301A0: jal         0x80198594
    // 0x800301A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x80198594)(rdram, ctx);
        goto after_2;
    // 0x800301A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800301A8: b           L_800301D8
    // 0x800301AC: nop

        goto L_800301D8;
    // 0x800301AC: nop

L_800301B0:
    // 0x800301B0: jal         0x8018C158
    // 0x800301B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Bolse_UpdateEventHandler(rdram, ctx);
        goto after_3;
    // 0x800301B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x800301B8: b           L_800301D8
    // 0x800301BC: nop

        goto L_800301D8;
    // 0x800301BC: nop

L_800301C0:
    // 0x800301C0: jal         0x8019AB8C
    // 0x800301C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    SectorZ_UpdateEvents(rdram, ctx);
        goto after_4;
    // 0x800301C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x800301C8: b           L_800301D8
    // 0x800301CC: nop

        goto L_800301D8;
    // 0x800301CC: nop

L_800301D0:
    // 0x800301D0: jal         0x80196314
    // 0x800301D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Venom2_UpdateEvents(rdram, ctx);
        goto after_5;
    // 0x800301D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
L_800301D8:
    // 0x800301D8: jal         0x8002FEF0
    // 0x800301DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ActorAllRange_SpawnSupplies(rdram, ctx);
        goto after_6;
    // 0x800301DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x800301E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800301E4:
    // 0x800301E4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800301E8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800301EC: jr          $ra
    // 0x800301F0: nop

    return;
    // 0x800301F0: nop

;}
RECOMP_FUNC void Effect_MeFireball_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800802F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800802FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80080300: jal         0x8007FE88
    // 0x80080304: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    Effect_EnemyShot_Update(rdram, ctx);
        goto after_0;
    // 0x80080304: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80080308: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8008030C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80080310: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80080314: lwc1        $f4, 0x18($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X18);
    // 0x80080318: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8008031C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80080320: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80080324: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x80080328: swc1        $f10, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f10.u32l;
    // 0x8008032C: lui         $at, 0x4060
    ctx->r1 = S32(0X4060 << 16);
    // 0x80080330: swc1        $f8, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f8.u32l;
    // 0x80080334: lw          $t6, 0x7DB0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7DB0);
    // 0x80080338: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x8008033C: beql        $t7, $zero, L_80080354
    if (ctx->r15 == 0) {
        // 0x80080340: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80080354;
    }
    goto skip_0;
    // 0x80080340: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80080344: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80080348: nop

    // 0x8008034C: swc1        $f16, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f16.u32l;
    // 0x80080350: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80080354:
    // 0x80080354: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80080358: jr          $ra
    // 0x8008035C: nop

    return;
    // 0x8008035C: nop

;}
RECOMP_FUNC void HUD_IncomingMsgButton_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085464: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80085468: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8008546C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80085470: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80085474: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80085478: lui         $a1, 0x101
    ctx->r5 = S32(0X101 << 16);
    // 0x8008547C: lui         $a2, 0x101
    ctx->r6 = S32(0X101 << 16);
    // 0x80085480: addiu       $t6, $zero, 0x1A
    ctx->r14 = ADD32(0, 0X1A);
    // 0x80085484: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80085488: addiu       $a2, $a2, 0x1B90
    ctx->r6 = ADD32(ctx->r6, 0X1B90);
    // 0x8008548C: addiu       $a1, $a1, 0x1AC0
    ctx->r5 = ADD32(ctx->r5, 0X1AC0);
    // 0x80085490: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x80085494: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x80085498: swc1        $f12, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f12.u32l;
    // 0x8008549C: swc1        $f14, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f14.u32l;
    // 0x800854A0: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x800854A4: jal         0x8009C320
    // 0x800854A8: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    Lib_TextureRect_CI4(rdram, ctx);
        goto after_0;
    // 0x800854A8: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x800854AC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800854B0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800854B4: jr          $ra
    // 0x800854B8: nop

    return;
    // 0x800854B8: nop

;}
RECOMP_FUNC void func_tank_80045348(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80045348: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8004534C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80045350: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80045354: lwc1        $f0, 0x568C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X568C);
    // 0x80045358: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8004535C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80045360: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x80045364: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80045368: lui         $at, 0x4060
    ctx->r1 = S32(0X4060 << 16);
    // 0x8004536C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80045370: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80045374: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x80045378: swc1        $f4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f4.u32l;
    // 0x8004537C: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    // 0x80045380: lw          $v0, 0x19C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X19C);
    // 0x80045384: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80045388: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x8004538C: bltz        $v0, L_80045640
    if (SIGNED(ctx->r2) < 0) {
        // 0x80045390: addiu       $at, $zero, -0x1
        ctx->r1 = ADD32(0, -0X1);
            goto L_80045640;
    }
    // 0x80045390: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80045394: lw          $t6, 0x1C4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1C4);
    // 0x80045398: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8004539C: lw          $v0, 0x7974($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7974);
    // 0x800453A0: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x800453A4: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800453A8: lhu         $t8, 0x7908($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X7908);
    // 0x800453AC: lhu         $t9, 0x0($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X0);
    // 0x800453B0: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800453B4: addiu       $v1, $v1, -0x60DC
    ctx->r3 = ADD32(ctx->r3, -0X60DC);
    // 0x800453B8: and         $t1, $t8, $t9
    ctx->r9 = ctx->r24 & ctx->r25;
    // 0x800453BC: beql        $t1, $zero, L_80045520
    if (ctx->r9 == 0) {
        // 0x800453C0: mtc1        $zero, $f4
        ctx->f4.u32l = 0;
            goto L_80045520;
    }
    goto skip_0;
    // 0x800453C0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    skip_0:
    // 0x800453C4: lw          $t2, 0x2B4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X2B4);
    // 0x800453C8: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x800453CC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800453D0: bnel        $t2, $zero, L_80045520
    if (ctx->r10 != 0) {
        // 0x800453D4: mtc1        $zero, $f4
        ctx->f4.u32l = 0;
            goto L_80045520;
    }
    goto skip_1;
    // 0x800453D4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    skip_1:
    // 0x800453D8: lw          $t3, -0x60EC($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X60EC);
    // 0x800453DC: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800453E0: addiu       $v1, $v1, -0x60DC
    ctx->r3 = ADD32(ctx->r3, -0X60DC);
    // 0x800453E4: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800453E8: sw          $t4, -0x60EC($at)
    MEM_W(-0X60EC, ctx->r1) = ctx->r12;
    // 0x800453EC: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800453F0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800453F4: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x800453F8: lui         $a0, 0x900
    ctx->r4 = S32(0X900 << 16);
    // 0x800453FC: c.eq.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl == ctx->f10.fl;
    // 0x80045400: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80045404: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80045408: ori         $a0, $a0, 0x402F
    ctx->r4 = ctx->r4 | 0X402F;
    // 0x8004540C: bc1f        L_80045454
    if (!c1cs) {
        // 0x80045410: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_80045454;
    }
    // 0x80045410: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80045414: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80045418: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8004541C: lui         $t5, 0x800C
    ctx->r13 = S32(0X800C << 16);
    // 0x80045420: addiu       $t5, $t5, 0x5D3C
    ctx->r13 = ADD32(ctx->r13, 0X5D3C);
    // 0x80045424: swc1        $f0, 0x194($s0)
    MEM_W(0X194, ctx->r16) = ctx->f0.u32l;
    // 0x80045428: swc1        $f0, 0x190($s0)
    MEM_W(0X190, ctx->r16) = ctx->f0.u32l;
    // 0x8004542C: sh          $t0, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r8;
    // 0x80045430: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80045434: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80045438: addiu       $a1, $s0, 0x460
    ctx->r5 = ADD32(ctx->r16, 0X460);
    // 0x8004543C: jal         0x80019218
    // 0x80045440: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Audio_PlaySfx(rdram, ctx);
        goto after_0;
    // 0x80045440: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80045444: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80045448: addiu       $v1, $v1, -0x60DC
    ctx->r3 = ADD32(ctx->r3, -0X60DC);
    // 0x8004544C: b           L_80045460
    // 0x80045450: lh          $t0, 0x2E($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X2E);
        goto L_80045460;
    // 0x80045450: lh          $t0, 0x2E($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X2E);
L_80045454:
    // 0x80045454: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80045458: nop

    // 0x8004545C: swc1        $f16, 0x190($s0)
    MEM_W(0X190, ctx->r16) = ctx->f16.u32l;
L_80045460:
    // 0x80045460: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80045464: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80045468: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x8004546C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80045470: lui         $at, 0xC348
    ctx->r1 = S32(0XC348 << 16);
    // 0x80045474: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80045478: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8004547C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80045480: lwc1        $f4, 0x5690($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5690);
    // 0x80045484: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x80045488: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x8004548C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80045490: swc1        $f18, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f18.u32l;
    // 0x80045494: swc1        $f10, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f10.u32l;
    // 0x80045498: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    // 0x8004549C: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    // 0x800454A0: lw          $t6, 0x1C4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1C4);
    // 0x800454A4: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x800454A8: addiu       $t8, $t8, 0x79A8
    ctx->r24 = ADD32(ctx->r24, 0X79A8);
    // 0x800454AC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800454B0: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    // 0x800454B4: lwc1        $f16, 0x0($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800454B8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800454BC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800454C0: c.lt.s      $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.fl < ctx->f12.fl;
    // 0x800454C4: lui         $a1, 0x4248
    ctx->r5 = S32(0X4248 << 16);
    // 0x800454C8: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x800454CC: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x800454D0: bc1fl       L_800454F4
    if (!c1cs) {
        // 0x800454D4: swc1        $f18, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
            goto L_800454F4;
    }
    goto skip_2;
    // 0x800454D4: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    skip_2:
    // 0x800454D8: swc1        $f12, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f12.u32l;
    // 0x800454DC: lw          $t9, 0x1C4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1C4);
    // 0x800454E0: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x800454E4: addiu       $t2, $t2, 0x79A8
    ctx->r10 = ADD32(ctx->r10, 0X79A8);
    // 0x800454E8: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x800454EC: addu        $a0, $t1, $t2
    ctx->r4 = ADD32(ctx->r9, ctx->r10);
    // 0x800454F0: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
L_800454F4:
    // 0x800454F4: sh          $t0, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r8;
    // 0x800454F8: jal         0x8009BC2C
    // 0x800454FC: swc1        $f2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f2.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_1;
    // 0x800454FC: swc1        $f2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f2.u32l;
    after_1:
    // 0x80045500: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x80045504: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80045508: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8004550C: lw          $v0, 0x7974($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7974);
    // 0x80045510: lh          $t0, 0x2E($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X2E);
    // 0x80045514: b           L_8004552C
    // 0x80045518: lwc1        $f2, 0x44($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X44);
        goto L_8004552C;
    // 0x80045518: lwc1        $f2, 0x44($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8004551C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
L_80045520:
    // 0x80045520: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x80045524: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80045528: swc1        $f4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f4.u32l;
L_8004552C:
    // 0x8004552C: lw          $t3, 0x1C4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X1C4);
    // 0x80045530: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x80045534: lhu         $t6, 0x0($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X0);
    // 0x80045538: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x8004553C: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x80045540: lhu         $t5, 0x7928($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0X7928);
    // 0x80045544: and         $t7, $t5, $t6
    ctx->r15 = ctx->r13 & ctx->r14;
    // 0x80045548: beql        $t7, $zero, L_800455EC
    if (ctx->r15 == 0) {
        // 0x8004554C: mtc1        $zero, $f6
        ctx->f6.u32l = 0;
            goto L_800455EC;
    }
    goto skip_3;
    // 0x8004554C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    skip_3:
    // 0x80045550: lw          $t8, 0x2B4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X2B4);
    // 0x80045554: bnel        $t8, $zero, L_800455EC
    if (ctx->r24 != 0) {
        // 0x80045558: mtc1        $zero, $f6
        ctx->f6.u32l = 0;
            goto L_800455EC;
    }
    goto skip_4;
    // 0x80045558: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    skip_4:
    // 0x8004555C: bne         $t0, $zero, L_800455E8
    if (ctx->r8 != 0) {
        // 0x80045560: lui         $v0, 0x800D
        ctx->r2 = S32(0X800D << 16);
            goto L_800455E8;
    }
    // 0x80045560: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80045564: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x80045568: lw          $t9, -0x60EC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X60EC);
    // 0x8004556C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80045570: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80045574: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80045578: addiu       $t1, $t9, 0x1
    ctx->r9 = ADD32(ctx->r25, 0X1);
    // 0x8004557C: sw          $t1, -0x60EC($at)
    MEM_W(-0X60EC, ctx->r1) = ctx->r9;
    // 0x80045580: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80045584: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80045588: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004558C: lwc1        $f8, 0x5694($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5694);
    // 0x80045590: addiu       $v0, $v0, -0x60D8
    ctx->r2 = ADD32(ctx->r2, -0X60D8);
    // 0x80045594: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80045598: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8004559C: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800455A0: swc1        $f6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f6.u32l;
    // 0x800455A4: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    // 0x800455A8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800455AC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800455B0: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x800455B4: addiu       $t4, $t4, 0x79A8
    ctx->r12 = ADD32(ctx->r12, 0X79A8);
    // 0x800455B8: swc1        $f18, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f18.u32l;
    // 0x800455BC: lw          $t2, 0x1C4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X1C4);
    // 0x800455C0: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x800455C4: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x800455C8: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800455CC: addu        $a0, $t3, $t4
    ctx->r4 = ADD32(ctx->r11, ctx->r12);
    // 0x800455D0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x800455D4: swc1        $f2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f2.u32l;
    // 0x800455D8: jal         0x8009BC2C
    // 0x800455DC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_2;
    // 0x800455DC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x800455E0: b           L_800455F8
    // 0x800455E4: lwc1        $f2, 0x44($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X44);
        goto L_800455F8;
    // 0x800455E4: lwc1        $f2, 0x44($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X44);
L_800455E8:
    // 0x800455E8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
L_800455EC:
    // 0x800455EC: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800455F0: addiu       $v0, $v0, -0x60D8
    ctx->r2 = ADD32(ctx->r2, -0X60D8);
    // 0x800455F4: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
L_800455F8:
    // 0x800455F8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800455FC: lwc1        $f8, 0x5698($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5698);
    // 0x80045600: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80045604: addiu       $a0, $s0, 0xD0
    ctx->r4 = ADD32(ctx->r16, 0XD0);
    // 0x80045608: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x8004560C: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x80045610: jal         0x8009BC2C
    // 0x80045614: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_3;
    // 0x80045614: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_3:
    // 0x80045618: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004561C: lwc1        $f10, 0x569C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X569C);
    // 0x80045620: addiu       $a0, $s0, 0x8C
    ctx->r4 = ADD32(ctx->r16, 0X8C);
    // 0x80045624: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x80045628: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x8004562C: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x80045630: jal         0x8009BC2C
    // 0x80045634: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_4;
    // 0x80045634: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_4:
    // 0x80045638: b           L_80045668
    // 0x8004563C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80045668;
    // 0x8004563C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80045640:
    // 0x80045640: bne         $v0, $at, L_80045664
    if (ctx->r2 != ctx->r1) {
        // 0x80045644: addiu       $a0, $s0, 0xD0
        ctx->r4 = ADD32(ctx->r16, 0XD0);
            goto L_80045664;
    }
    // 0x80045644: addiu       $a0, $s0, 0xD0
    ctx->r4 = ADD32(ctx->r16, 0XD0);
    // 0x80045648: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004564C: lwc1        $f16, 0x56A0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X56A0);
    // 0x80045650: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80045654: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80045658: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x8004565C: jal         0x8009BC2C
    // 0x80045660: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_5;
    // 0x80045660: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_5:
L_80045664:
    // 0x80045664: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80045668:
    // 0x80045668: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8004566C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80045670: jr          $ra
    // 0x80045674: nop

    return;
    // 0x80045674: nop

;}
RECOMP_FUNC void Aquas_CsIntroGreatFox_Init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80093310: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80093314: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80093318: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8009331C: jal         0x800613C4
    // 0x80093320: addiu       $a0, $a0, 0x3FE0
    ctx->r4 = ADD32(ctx->r4, 0X3FE0);
    Actor_Initialize(rdram, ctx);
        goto after_0;
    // 0x80093320: addiu       $a0, $a0, 0x3FE0
    ctx->r4 = ADD32(ctx->r4, 0X3FE0);
    after_0:
    // 0x80093324: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80093328: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8009332C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80093330: sb          $t6, 0x3FE0($at)
    MEM_B(0X3FE0, ctx->r1) = ctx->r14;
    // 0x80093334: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80093338: swc1        $f4, 0x3FE4($at)
    MEM_W(0X3FE4, ctx->r1) = ctx->f4.u32l;
    // 0x8009333C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80093340: lwc1        $f6, 0x3FE8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X3FE8);
    // 0x80093344: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80093348: lwc1        $f8, 0x7FEC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7FEC);
    // 0x8009334C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80093350: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80093354: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80093358: addiu       $a1, $zero, 0xC3
    ctx->r5 = ADD32(0, 0XC3);
    // 0x8009335C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80093360: addiu       $a0, $a0, 0x3FFC
    ctx->r4 = ADD32(ctx->r4, 0X3FFC);
    // 0x80093364: swc1        $f10, 0x3FE8($at)
    MEM_W(0X3FE8, ctx->r1) = ctx->f10.u32l;
    // 0x80093368: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8009336C: lwc1        $f16, 0x3FEC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X3FEC);
    // 0x80093370: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80093374: lwc1        $f18, 0x7FF0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7FF0);
    // 0x80093378: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8009337C: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80093380: swc1        $f4, 0x3FEC($at)
    MEM_W(0X3FEC, ctx->r1) = ctx->f4.u32l;
    // 0x80093384: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80093388: sh          $t7, 0x4096($at)
    MEM_H(0X4096, ctx->r1) = ctx->r15;
    // 0x8009338C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80093390: jal         0x800612B8
    // 0x80093394: sh          $a1, 0x3FE2($at)
    MEM_H(0X3FE2, ctx->r1) = ctx->r5;
    Object_SetInfo(rdram, ctx);
        goto after_1;
    // 0x80093394: sh          $a1, 0x3FE2($at)
    MEM_H(0X3FE2, ctx->r1) = ctx->r5;
    after_1:
    // 0x80093398: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8009339C: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x800933A0: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x800933A4: addiu       $t8, $t8, 0x5D3C
    ctx->r24 = ADD32(ctx->r24, 0X5D3C);
    // 0x800933A8: lui         $a0, 0x1103
    ctx->r4 = S32(0X1103 << 16);
    // 0x800933AC: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x800933B0: addiu       $a1, $a1, 0x40E0
    ctx->r5 = ADD32(ctx->r5, 0X40E0);
    // 0x800933B4: ori         $a0, $a0, 0x10
    ctx->r4 = ctx->r4 | 0X10;
    // 0x800933B8: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x800933BC: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x800933C0: jal         0x80019218
    // 0x800933C4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Audio_PlaySfx(rdram, ctx);
        goto after_2;
    // 0x800933C4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x800933C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800933CC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800933D0: jr          $ra
    // 0x800933D4: nop

    return;
    // 0x800933D4: nop

;}
RECOMP_FUNC void Audio_UpdateUnkVoiceParam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001AF50: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8001AF54: lbu         $v0, 0x7390($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7390);
    // 0x8001AF58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001AF5C: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8001AF60: beq         $v0, $at, L_8001AF8C
    if (ctx->r2 == ctx->r1) {
        // 0x8001AF64: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8001AF8C;
    }
    // 0x8001AF64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001AF68: sll         $a1, $v0, 24
    ctx->r5 = S32(ctx->r2 << 24);
    // 0x8001AF6C: sra         $t6, $a1, 24
    ctx->r14 = S32(SIGNED(ctx->r5) >> 24);
    // 0x8001AF70: lui         $a0, 0x603
    ctx->r4 = S32(0X603 << 16);
    // 0x8001AF74: ori         $a0, $a0, 0xE00
    ctx->r4 = ctx->r4 | 0XE00;
    // 0x8001AF78: jal         0x8001E8F0
    // 0x8001AF7C: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    AudioThread_QueueCmdS8(rdram, ctx);
        goto after_0;
    // 0x8001AF7C: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    after_0:
    // 0x8001AF80: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8001AF84: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8001AF88: sb          $t7, 0x7390($at)
    MEM_B(0X7390, ctx->r1) = ctx->r15;
L_8001AF8C:
    // 0x8001AF8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001AF90: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001AF94: jr          $ra
    // 0x8001AF98: nop

    return;
    // 0x8001AF98: nop

;}
RECOMP_FUNC void Math_Factorial(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800054C8: slti        $at, $a0, 0xD
    ctx->r1 = SIGNED(ctx->r4) < 0XD ? 1 : 0;
    // 0x800054CC: bne         $at, $zero, L_800055C4
    if (ctx->r1 != 0) {
        // 0x800054D0: sll         $t0, $a0, 2
        ctx->r8 = S32(ctx->r4 << 2);
            goto L_800055C4;
    }
    // 0x800054D0: sll         $t0, $a0, 2
    ctx->r8 = S32(ctx->r4 << 2);
    // 0x800054D4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800054D8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800054DC: slti        $at, $a0, 0x2
    ctx->r1 = SIGNED(ctx->r4) < 0X2 ? 1 : 0;
    // 0x800054E0: bne         $at, $zero, L_800055D0
    if (ctx->r1 != 0) {
        // 0x800054E4: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_800055D0;
    }
    // 0x800054E4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800054E8: addiu       $a1, $a0, -0x1
    ctx->r5 = ADD32(ctx->r4, -0X1);
    // 0x800054EC: andi        $t6, $a1, 0x3
    ctx->r14 = ctx->r5 & 0X3;
    // 0x800054F0: negu        $a1, $t6
    ctx->r5 = SUB32(0, ctx->r14);
    // 0x800054F4: beq         $a1, $zero, L_8000551C
    if (ctx->r5 == 0) {
        // 0x800054F8: addu        $v1, $a1, $a0
        ctx->r3 = ADD32(ctx->r5, ctx->r4);
            goto L_8000551C;
    }
    // 0x800054F8: addu        $v1, $a1, $a0
    ctx->r3 = ADD32(ctx->r5, ctx->r4);
    // 0x800054FC: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
L_80005500:
    // 0x80005500: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80005504: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80005508: mul.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x8000550C: bnel        $v1, $v0, L_80005500
    if (ctx->r3 != ctx->r2) {
        // 0x80005510: mtc1        $v0, $f4
        ctx->f4.u32l = ctx->r2;
            goto L_80005500;
    }
    goto skip_0;
    // 0x80005510: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    skip_0:
    // 0x80005514: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80005518: beq         $v0, $v1, L_800055D0
    if (ctx->r2 == ctx->r3) {
        // 0x8000551C: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_800055D0;
    }
L_8000551C:
    // 0x8000551C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80005520: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x80005524: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80005528: beq         $v0, $v1, L_80005578
    if (ctx->r2 == ctx->r3) {
        // 0x8000552C: cvt.s.w     $f18, $f10
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
            goto L_80005578;
    }
    // 0x8000552C: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
L_80005530:
    // 0x80005530: mul.s       $f2, $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x80005534: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x80005538: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x8000553C: addiu       $t8, $v0, -0x2
    ctx->r24 = ADD32(ctx->r2, -0X2);
    // 0x80005540: mtc1        $t8, $f14
    ctx->f14.u32l = ctx->r24;
    // 0x80005544: addiu       $t9, $v0, -0x3
    ctx->r25 = ADD32(ctx->r2, -0X3);
    // 0x80005548: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8000554C: mtc1        $t9, $f12
    ctx->f12.u32l = ctx->r25;
    // 0x80005550: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // 0x80005554: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x80005558: cvt.s.w     $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.fl = CVT_S_W(ctx->f14.u32l);
    // 0x8000555C: mul.s       $f2, $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x80005560: cvt.s.w     $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    ctx->f12.fl = CVT_S_W(ctx->f12.u32l);
    // 0x80005564: mul.s       $f2, $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x80005568: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8000556C: mul.s       $f2, $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x80005570: bne         $v0, $v1, L_80005530
    if (ctx->r2 != ctx->r3) {
        // 0x80005574: nop
    
            goto L_80005530;
    }
    // 0x80005574: nop

L_80005578:
    // 0x80005578: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x8000557C: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x80005580: mul.s       $f2, $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x80005584: addiu       $t8, $v0, -0x2
    ctx->r24 = ADD32(ctx->r2, -0X2);
    // 0x80005588: mtc1        $t8, $f14
    ctx->f14.u32l = ctx->r24;
    // 0x8000558C: addiu       $t9, $v0, -0x3
    ctx->r25 = ADD32(ctx->r2, -0X3);
    // 0x80005590: mtc1        $t9, $f12
    ctx->f12.u32l = ctx->r25;
    // 0x80005594: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x80005598: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8000559C: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // 0x800055A0: cvt.s.w     $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.fl = CVT_S_W(ctx->f14.u32l);
    // 0x800055A4: mul.s       $f2, $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x800055A8: cvt.s.w     $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    ctx->f12.fl = CVT_S_W(ctx->f12.u32l);
    // 0x800055AC: mul.s       $f2, $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x800055B0: nop

    // 0x800055B4: mul.s       $f2, $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x800055B8: nop

    // 0x800055BC: b           L_800055D4
    // 0x800055C0: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_800055D4;
    // 0x800055C0: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_800055C4:
    // 0x800055C4: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x800055C8: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x800055CC: lwc1        $f2, 0x45E0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X45E0);
L_800055D0:
    // 0x800055D0: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_800055D4:
    // 0x800055D4: jr          $ra
    // 0x800055D8: nop

    return;
    // 0x800055D8: nop

;}
RECOMP_FUNC void ActorAllRange_SpawnStarWolf(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002F3E0: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8002F3E4: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8002F3E8: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x8002F3EC: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x8002F3F0: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x8002F3F4: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x8002F3F8: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x8002F3FC: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x8002F400: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8002F404: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x8002F408: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8002F40C: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x8002F410: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8002F414: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    // 0x8002F418: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8002F41C: lui         $at, 0x4361
    ctx->r1 = S32(0X4361 << 16);
    // 0x8002F420: lui         $s0, 0x8016
    ctx->r16 = S32(0X8016 << 16);
    // 0x8002F424: lui         $s6, 0x8017
    ctx->r22 = S32(0X8017 << 16);
    // 0x8002F428: lui         $fp, 0x8018
    ctx->r30 = S32(0X8018 << 16);
    // 0x8002F42C: lui         $s5, 0x800C
    ctx->r21 = S32(0X800C << 16);
    // 0x8002F430: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8002F434: addiu       $s5, $s5, 0x5D34
    ctx->r21 = ADD32(ctx->r21, 0X5D34);
    // 0x8002F438: addiu       $fp, $fp, -0x7DCC
    ctx->r30 = ADD32(ctx->r30, -0X7DCC);
    // 0x8002F43C: addiu       $s6, $s6, 0x7CD0
    ctx->r22 = ADD32(ctx->r22, 0X7CD0);
    // 0x8002F440: addiu       $s0, $s0, 0x4BB0
    ctx->r16 = ADD32(ctx->r16, 0X4BB0);
    // 0x8002F444: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8002F448: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8002F44C: addiu       $s7, $zero, 0x13
    ctx->r23 = ADD32(0, 0X13);
L_8002F450:
    // 0x8002F450: lw          $t6, 0x0($s6)
    ctx->r14 = MEM_W(ctx->r22, 0X0);
    // 0x8002F454: sll         $t7, $s2, 2
    ctx->r15 = S32(ctx->r18 << 2);
    // 0x8002F458: subu        $t7, $t7, $s2
    ctx->r15 = SUB32(ctx->r15, ctx->r18);
    // 0x8002F45C: beq         $t6, $zero, L_8002F5A4
    if (ctx->r14 == 0) {
        // 0x8002F460: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8002F5A4;
    }
    // 0x8002F460: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8002F464: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x8002F468: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x8002F46C: addiu       $t9, $t9, -0x64D4
    ctx->r25 = ADD32(ctx->r25, -0X64D4);
    // 0x8002F470: addiu       $t8, $t8, -0x6504
    ctx->r24 = ADD32(ctx->r24, -0X6504);
    // 0x8002F474: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8002F478: addu        $s1, $t7, $t8
    ctx->r17 = ADD32(ctx->r15, ctx->r24);
    // 0x8002F47C: jal         0x800613C4
    // 0x8002F480: addu        $s4, $s3, $t9
    ctx->r20 = ADD32(ctx->r19, ctx->r25);
    Actor_Initialize(rdram, ctx);
        goto after_0;
    // 0x8002F480: addu        $s4, $s3, $t9
    ctx->r20 = ADD32(ctx->r19, ctx->r25);
    after_0:
    // 0x8002F484: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x8002F488: sb          $t0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r8;
    // 0x8002F48C: lwc1        $f4, 0x0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8002F490: addiu       $t1, $zero, 0xC5
    ctx->r9 = ADD32(0, 0XC5);
    // 0x8002F494: addiu       $t2, $s2, 0x4
    ctx->r10 = ADD32(ctx->r18, 0X4);
    // 0x8002F498: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x8002F49C: lwc1        $f6, 0x4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8002F4A0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8002F4A4: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x8002F4A8: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x8002F4AC: lwc1        $f8, 0x8($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8002F4B0: sh          $t1, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r9;
    // 0x8002F4B4: sh          $t2, 0xE4($s0)
    MEM_H(0XE4, ctx->r16) = ctx->r10;
    // 0x8002F4B8: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    // 0x8002F4BC: lw          $t3, 0x0($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X0);
    // 0x8002F4C0: addiu       $t7, $zero, 0x64
    ctx->r15 = ADD32(0, 0X64);
    // 0x8002F4C4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8002F4C8: sh          $t3, 0xE6($s0)
    MEM_H(0XE6, ctx->r16) = ctx->r11;
    // 0x8002F4CC: lh          $t5, 0xE6($s0)
    ctx->r13 = MEM_H(ctx->r16, 0XE6);
    // 0x8002F4D0: addiu       $t9, $zero, 0xFA
    ctx->r25 = ADD32(0, 0XFA);
    // 0x8002F4D4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8002F4D8: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8002F4DC: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x8002F4E0: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x8002F4E4: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x8002F4E8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8002F4EC: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8002F4F0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8002F4F4: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8002F4F8: sh          $t4, 0x40C6($at)
    MEM_H(0X40C6, ctx->r1) = ctx->r12;
    // 0x8002F4FC: sh          $t7, 0xCE($s0)
    MEM_H(0XCE, ctx->r16) = ctx->r15;
    // 0x8002F500: sb          $t8, 0xC9($s0)
    MEM_B(0XC9, ctx->r16) = ctx->r24;
    // 0x8002F504: swc1        $f20, 0xF8($s0)
    MEM_W(0XF8, ctx->r16) = ctx->f20.u32l;
    // 0x8002F508: sh          $zero, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = 0;
    // 0x8002F50C: sh          $t9, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r25;
    // 0x8002F510: swc1        $f22, 0xF4($s0)
    MEM_W(0XF4, ctx->r16) = ctx->f22.u32l;
    // 0x8002F514: sw          $t0, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r8;
    // 0x8002F518: lw          $t1, 0x0($fp)
    ctx->r9 = MEM_W(ctx->r30, 0X0);
    // 0x8002F51C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002F520: addu        $at, $at, $s3
    ctx->r1 = ADD32(ctx->r1, ctx->r19);
    // 0x8002F524: bne         $s7, $t1, L_8002F53C
    if (ctx->r23 != ctx->r9) {
        // 0x8002F528: addiu       $a0, $s0, 0x1C
        ctx->r4 = ADD32(ctx->r16, 0X1C);
            goto L_8002F53C;
    }
    // 0x8002F528: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x8002F52C: lwc1        $f10, -0x64C4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X64C4);
    // 0x8002F530: addiu       $t2, $zero, 0x19
    ctx->r10 = ADD32(0, 0X19);
    // 0x8002F534: sb          $t2, 0x44($s0)
    MEM_B(0X44, ctx->r16) = ctx->r10;
    // 0x8002F538: swc1        $f10, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f10.u32l;
L_8002F53C:
    // 0x8002F53C: jal         0x800612B8
    // 0x8002F540: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    Object_SetInfo(rdram, ctx);
        goto after_1;
    // 0x8002F540: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    after_1:
    // 0x8002F544: lw          $t3, 0x0($fp)
    ctx->r11 = MEM_W(ctx->r30, 0X0);
    // 0x8002F548: lui         $a0, 0x3100
    ctx->r4 = S32(0X3100 << 16);
    // 0x8002F54C: ori         $a0, $a0, 0x4005
    ctx->r4 = ctx->r4 | 0X4005;
    // 0x8002F550: bne         $s7, $t3, L_8002F588
    if (ctx->r23 != ctx->r11) {
        // 0x8002F554: addiu       $a1, $s0, 0x100
        ctx->r5 = ADD32(ctx->r16, 0X100);
            goto L_8002F588;
    }
    // 0x8002F554: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x8002F558: lui         $t5, 0x800C
    ctx->r13 = S32(0X800C << 16);
    // 0x8002F55C: addiu       $t5, $t5, 0x5D3C
    ctx->r13 = ADD32(ctx->r13, 0X5D3C);
    // 0x8002F560: lui         $a0, 0x3100
    ctx->r4 = S32(0X3100 << 16);
    // 0x8002F564: ori         $a0, $a0, 0x4006
    ctx->r4 = ctx->r4 | 0X4006;
    // 0x8002F568: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8002F56C: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x8002F570: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8002F574: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    // 0x8002F578: jal         0x80019218
    // 0x8002F57C: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    Audio_PlaySfx(rdram, ctx);
        goto after_2;
    // 0x8002F57C: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    after_2:
    // 0x8002F580: b           L_8002F5A8
    // 0x8002F584: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
        goto L_8002F5A8;
    // 0x8002F584: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_8002F588:
    // 0x8002F588: lui         $t4, 0x800C
    ctx->r12 = S32(0X800C << 16);
    // 0x8002F58C: addiu       $t4, $t4, 0x5D3C
    ctx->r12 = ADD32(ctx->r12, 0X5D3C);
    // 0x8002F590: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x8002F594: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8002F598: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    // 0x8002F59C: jal         0x80019218
    // 0x8002F5A0: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    Audio_PlaySfx(rdram, ctx);
        goto after_3;
    // 0x8002F5A0: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    after_3:
L_8002F5A4:
    // 0x8002F5A4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_8002F5A8:
    // 0x8002F5A8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8002F5AC: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x8002F5B0: addiu       $s6, $s6, 0x4
    ctx->r22 = ADD32(ctx->r22, 0X4);
    // 0x8002F5B4: bne         $s2, $at, L_8002F450
    if (ctx->r18 != ctx->r1) {
        // 0x8002F5B8: addiu       $s0, $s0, 0x2F4
        ctx->r16 = ADD32(ctx->r16, 0X2F4);
            goto L_8002F450;
    }
    // 0x8002F5B8: addiu       $s0, $s0, 0x2F4
    ctx->r16 = ADD32(ctx->r16, 0X2F4);
    // 0x8002F5BC: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x8002F5C0: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8002F5C4: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x8002F5C8: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8002F5CC: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x8002F5D0: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x8002F5D4: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x8002F5D8: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x8002F5DC: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x8002F5E0: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x8002F5E4: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x8002F5E8: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x8002F5EC: jr          $ra
    // 0x8002F5F0: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8002F5F0: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void Audio_KillSfxBySourceAndId(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A55C: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x8001A560: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8001A564: lui         $at, 0xF000
    ctx->r1 = S32(0XF000 << 16);
    // 0x8001A568: and         $s6, $a1, $at
    ctx->r22 = ctx->r5 & ctx->r1;
    // 0x8001A56C: srl         $t6, $s6, 28
    ctx->r14 = S32(U32(ctx->r22) >> 28);
    // 0x8001A570: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x8001A574: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x8001A578: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8001A57C: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x8001A580: addiu       $t9, $t9, -0x79A0
    ctx->r25 = ADD32(ctx->r25, -0X79A0);
    // 0x8001A584: sll         $t8, $t8, 6
    ctx->r24 = S32(ctx->r24 << 6);
    // 0x8001A588: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8001A58C: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8001A590: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8001A594: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8001A598: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8001A59C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8001A5A0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8001A5A4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8001A5A8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001A5AC: sw          $a0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r4;
    // 0x8001A5B0: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8001A5B4: lbu         $s1, 0x2B($t0)
    ctx->r17 = MEM_BU(ctx->r8, 0X2B);
    // 0x8001A5B8: addiu       $s5, $zero, 0xFF
    ctx->r21 = ADD32(0, 0XFF);
    // 0x8001A5BC: or          $fp, $a1, $zero
    ctx->r30 = ctx->r5 | 0;
    // 0x8001A5C0: or          $s6, $t7, $zero
    ctx->r22 = ctx->r15 | 0;
    // 0x8001A5C4: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8001A5C8: beq         $s5, $s1, L_8001A67C
    if (ctx->r21 == ctx->r17) {
        // 0x8001A5CC: or          $v0, $s1, $zero
        ctx->r2 = ctx->r17 | 0;
            goto L_8001A67C;
    }
    // 0x8001A5CC: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x8001A5D0: sll         $t1, $t7, 4
    ctx->r9 = S32(ctx->r15 << 4);
    // 0x8001A5D4: subu        $t1, $t1, $t7
    ctx->r9 = SUB32(ctx->r9, ctx->r15);
    // 0x8001A5D8: sll         $t1, $t1, 6
    ctx->r9 = S32(ctx->r9 << 6);
    // 0x8001A5DC: addu        $s4, $t1, $t9
    ctx->r20 = ADD32(ctx->r9, ctx->r25);
    // 0x8001A5E0: lui         $s7, 0x602
    ctx->r23 = S32(0X602 << 16);
    // 0x8001A5E4: addiu       $s2, $zero, 0x30
    ctx->r18 = ADD32(0, 0X30);
L_8001A5E8:
    // 0x8001A5E8: multu       $s1, $s2
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001A5EC: lw          $t3, 0x88($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X88);
    // 0x8001A5F0: mflo        $t2
    ctx->r10 = lo;
    // 0x8001A5F4: addu        $s0, $s4, $t2
    ctx->r16 = ADD32(ctx->r20, ctx->r10);
    // 0x8001A5F8: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x8001A5FC: bnel        $t3, $t4, L_8001A658
    if (ctx->r11 != ctx->r12) {
        // 0x8001A600: andi        $s3, $s1, 0xFF
        ctx->r19 = ctx->r17 & 0XFF;
            goto L_8001A658;
    }
    goto skip_0;
    // 0x8001A600: andi        $s3, $s1, 0xFF
    ctx->r19 = ctx->r17 & 0XFF;
    skip_0:
    // 0x8001A604: lw          $t5, 0x24($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X24);
    // 0x8001A608: bnel        $fp, $t5, L_8001A658
    if (ctx->r30 != ctx->r13) {
        // 0x8001A60C: andi        $s3, $s1, 0xFF
        ctx->r19 = ctx->r17 & 0XFF;
            goto L_8001A658;
    }
    goto skip_1;
    // 0x8001A60C: andi        $s3, $s1, 0xFF
    ctx->r19 = ctx->r17 & 0XFF;
    skip_1:
    // 0x8001A610: lbu         $v0, 0x28($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X28);
    // 0x8001A614: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x8001A618: bne         $at, $zero, L_8001A638
    if (ctx->r1 != 0) {
        // 0x8001A61C: nop
    
            goto L_8001A638;
    }
    // 0x8001A61C: nop

    // 0x8001A620: lbu         $t7, 0x2C($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X2C);
    // 0x8001A624: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001A628: sll         $t8, $t7, 8
    ctx->r24 = S32(ctx->r15 << 8);
    // 0x8001A62C: jal         0x8001E8F0
    // 0x8001A630: or          $a0, $t8, $s7
    ctx->r4 = ctx->r24 | ctx->r23;
    AudioThread_QueueCmdS8(rdram, ctx);
        goto after_0;
    // 0x8001A630: or          $a0, $t8, $s7
    ctx->r4 = ctx->r24 | ctx->r23;
    after_0:
    // 0x8001A634: lbu         $v0, 0x28($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X28);
L_8001A638:
    // 0x8001A638: beq         $v0, $zero, L_8001A648
    if (ctx->r2 == 0) {
        // 0x8001A63C: andi        $a0, $s6, 0xFF
        ctx->r4 = ctx->r22 & 0XFF;
            goto L_8001A648;
    }
    // 0x8001A63C: andi        $a0, $s6, 0xFF
    ctx->r4 = ctx->r22 & 0XFF;
    // 0x8001A640: jal         0x800197AC
    // 0x8001A644: andi        $a1, $s1, 0xFF
    ctx->r5 = ctx->r17 & 0XFF;
    Audio_RemoveSfxBankEntry(rdram, ctx);
        goto after_1;
    // 0x8001A644: andi        $a1, $s1, 0xFF
    ctx->r5 = ctx->r17 & 0XFF;
    after_1:
L_8001A648:
    // 0x8001A648: addiu       $s1, $zero, 0xFF
    ctx->r17 = ADD32(0, 0XFF);
    // 0x8001A64C: b           L_8001A658
    // 0x8001A650: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
        goto L_8001A658;
    // 0x8001A650: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8001A654: andi        $s3, $s1, 0xFF
    ctx->r19 = ctx->r17 & 0XFF;
L_8001A658:
    // 0x8001A658: beq         $s5, $v0, L_8001A674
    if (ctx->r21 == ctx->r2) {
        // 0x8001A65C: nop
    
            goto L_8001A674;
    }
    // 0x8001A65C: nop

    // 0x8001A660: multu       $s3, $s2
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001A664: mflo        $t0
    ctx->r8 = lo;
    // 0x8001A668: addu        $t1, $s4, $t0
    ctx->r9 = ADD32(ctx->r20, ctx->r8);
    // 0x8001A66C: lbu         $s1, 0x2B($t1)
    ctx->r17 = MEM_BU(ctx->r9, 0X2B);
    // 0x8001A670: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
L_8001A674:
    // 0x8001A674: bne         $s5, $v0, L_8001A5E8
    if (ctx->r21 != ctx->r2) {
        // 0x8001A678: nop
    
            goto L_8001A5E8;
    }
    // 0x8001A678: nop

L_8001A67C:
    // 0x8001A67C: lw          $t9, 0x88($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X88);
    // 0x8001A680: sw          $fp, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r30;
    // 0x8001A684: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8001A688: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x8001A68C: jal         0x80019290
    // 0x8001A690: sw          $t9, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r25;
    Audio_RemoveMatchingSfxRequests(rdram, ctx);
        goto after_2;
    // 0x8001A690: sw          $t9, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r25;
    after_2:
    // 0x8001A694: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8001A698: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001A69C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8001A6A0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8001A6A4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8001A6A8: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8001A6AC: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8001A6B0: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8001A6B4: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8001A6B8: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8001A6BC: jr          $ra
    // 0x8001A6C0: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x8001A6C0: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void RCP_SetupDL_49(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BA5B0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BA5B4: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x800BA5B8: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800BA5BC: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x800BA5C0: addiu       $t8, $t8, 0x3F78
    ctx->r24 = ADD32(ctx->r24, 0X3F78);
    // 0x800BA5C4: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800BA5C8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800BA5CC: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x800BA5D0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800BA5D4: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800BA5D8: jr          $ra
    // 0x800BA5DC: nop

    return;
    // 0x800BA5DC: nop

;}
RECOMP_FUNC void Effect_Effect342_Spawn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007CEBC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8007CEC0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8007CEC4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8007CEC8: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8007CECC: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8007CED0: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8007CED4: addiu       $v0, $v0, 0x130
    ctx->r2 = ADD32(ctx->r2, 0X130);
    // 0x8007CED8: addiu       $a0, $a0, 0x3754
    ctx->r4 = ADD32(ctx->r4, 0X3754);
    // 0x8007CEDC: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
L_8007CEE0:
    // 0x8007CEE0: bnel        $t6, $zero, L_8007CF14
    if (ctx->r14 != 0) {
        // 0x8007CEE4: addiu       $a0, $a0, -0x8C
        ctx->r4 = ADD32(ctx->r4, -0X8C);
            goto L_8007CF14;
    }
    goto skip_0;
    // 0x8007CEE4: addiu       $a0, $a0, -0x8C
    ctx->r4 = ADD32(ctx->r4, -0X8C);
    skip_0:
    // 0x8007CEE8: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8007CEEC: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8007CEF0: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8007CEF4: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x8007CEF8: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8007CEFC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8007CF00: jal         0x8007CD7C
    // 0x8007CF04: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    Effect_Effect342_Setup(rdram, ctx);
        goto after_0;
    // 0x8007CF04: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_0:
    // 0x8007CF08: b           L_8007CF24
    // 0x8007CF0C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8007CF24;
    // 0x8007CF0C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007CF10: addiu       $a0, $a0, -0x8C
    ctx->r4 = ADD32(ctx->r4, -0X8C);
L_8007CF14:
    // 0x8007CF14: sltu        $at, $a0, $v0
    ctx->r1 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x8007CF18: beql        $at, $zero, L_8007CEE0
    if (ctx->r1 == 0) {
        // 0x8007CF1C: lbu         $t6, 0x0($a0)
        ctx->r14 = MEM_BU(ctx->r4, 0X0);
            goto L_8007CEE0;
    }
    goto skip_1;
    // 0x8007CF1C: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    skip_1:
    // 0x8007CF20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8007CF24:
    // 0x8007CF24: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8007CF28: jr          $ra
    // 0x8007CF2C: nop

    return;
    // 0x8007CF2C: nop

;}
RECOMP_FUNC void Effect_Effect387_Spawn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007C688: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8007C68C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8007C690: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8007C694: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8007C698: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8007C69C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8007C6A0: addiu       $v0, $v0, 0x130
    ctx->r2 = ADD32(ctx->r2, 0X130);
    // 0x8007C6A4: addiu       $a0, $a0, 0x3754
    ctx->r4 = ADD32(ctx->r4, 0X3754);
    // 0x8007C6A8: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
L_8007C6AC:
    // 0x8007C6AC: bnel        $t6, $zero, L_8007C6E0
    if (ctx->r14 != 0) {
        // 0x8007C6B0: addiu       $a0, $a0, -0x8C
        ctx->r4 = ADD32(ctx->r4, -0X8C);
            goto L_8007C6E0;
    }
    goto skip_0;
    // 0x8007C6B0: addiu       $a0, $a0, -0x8C
    ctx->r4 = ADD32(ctx->r4, -0X8C);
    skip_0:
    // 0x8007C6B4: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8007C6B8: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8007C6BC: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8007C6C0: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x8007C6C4: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8007C6C8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8007C6CC: jal         0x8007C608
    // 0x8007C6D0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    Effect_Effect387_Setup(rdram, ctx);
        goto after_0;
    // 0x8007C6D0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_0:
    // 0x8007C6D4: b           L_8007C6F0
    // 0x8007C6D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8007C6F0;
    // 0x8007C6D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007C6DC: addiu       $a0, $a0, -0x8C
    ctx->r4 = ADD32(ctx->r4, -0X8C);
L_8007C6E0:
    // 0x8007C6E0: sltu        $at, $a0, $v0
    ctx->r1 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x8007C6E4: beql        $at, $zero, L_8007C6AC
    if (ctx->r1 == 0) {
        // 0x8007C6E8: lbu         $t6, 0x0($a0)
        ctx->r14 = MEM_BU(ctx->r4, 0X0);
            goto L_8007C6AC;
    }
    goto skip_1;
    // 0x8007C6E8: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    skip_1:
    // 0x8007C6EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8007C6F0:
    // 0x8007C6F0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8007C6F4: jr          $ra
    // 0x8007C6F8: nop

    return;
    // 0x8007C6F8: nop

;}
RECOMP_FUNC void Load_SceneSetup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80058F14: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80058F18: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80058F1C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80058F20: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x80058F24: andi        $t7, $a1, 0xFF
    ctx->r15 = ctx->r5 & 0XFF;
    // 0x80058F28: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x80058F2C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x80058F30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80058F34: slti        $at, $a0, 0x33
    ctx->r1 = SIGNED(ctx->r4) < 0X33 ? 1 : 0;
    // 0x80058F38: bne         $at, $zero, L_80058F54
    if (ctx->r1 != 0) {
        // 0x80058F3C: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_80058F54;
    }
    // 0x80058F3C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80058F40: addiu       $at, $zero, 0x63
    ctx->r1 = ADD32(0, 0X63);
    // 0x80058F44: beq         $a0, $at, L_80059410
    if (ctx->r4 == ctx->r1) {
        // 0x80058F48: sll         $t9, $a1, 2
        ctx->r25 = S32(ctx->r5 << 2);
            goto L_80059410;
    }
    // 0x80058F48: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x80058F4C: b           L_80059484
    // 0x80058F50: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_80059484;
    // 0x80058F50: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80058F54:
    // 0x80058F54: slti        $at, $v0, 0x19
    ctx->r1 = SIGNED(ctx->r2) < 0X19 ? 1 : 0;
    // 0x80058F58: bne         $at, $zero, L_80058F70
    if (ctx->r1 != 0) {
        // 0x80058F5C: addiu       $at, $zero, 0x32
        ctx->r1 = ADD32(0, 0X32);
            goto L_80058F70;
    }
    // 0x80058F5C: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x80058F60: beq         $v0, $at, L_800593CC
    if (ctx->r2 == ctx->r1) {
        // 0x80058F64: sll         $t7, $a1, 2
        ctx->r15 = S32(ctx->r5 << 2);
            goto L_800593CC;
    }
    // 0x80058F64: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x80058F68: b           L_80059484
    // 0x80058F6C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_80059484;
    // 0x80058F6C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80058F70:
    // 0x80058F70: sltiu       $at, $v0, 0x19
    ctx->r1 = ctx->r2 < 0X19 ? 1 : 0;
    // 0x80058F74: beq         $at, $zero, L_80059480
    if (ctx->r1 == 0) {
        // 0x80058F78: sll         $t8, $v0, 2
        ctx->r24 = S32(ctx->r2 << 2);
            goto L_80059480;
    }
    // 0x80058F78: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x80058F7C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80058F80: addu        $at, $at, $t8
    gpr jr_addend_80058F88 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80058F84: lw          $t8, 0x5FB4($at)
    ctx->r24 = ADD32(ctx->r1, 0X5FB4);
    // 0x80058F88: jr          $t8
    // 0x80058F8C: nop

    switch (jr_addend_80058F88 >> 2) {
        case 0: goto L_80058F90; break;
        case 1: goto L_80058FD8; break;
        case 2: goto L_80059004; break;
        case 3: goto L_80059030; break;
        case 4: goto L_80059454; break;
        case 5: goto L_8005905C; break;
        case 6: goto L_80059088; break;
        case 7: goto L_800590B4; break;
        case 8: goto L_800590E0; break;
        case 9: goto L_80059138; break;
        case 10: goto L_80059164; break;
        case 11: goto L_80059190; break;
        case 12: goto L_800591BC; break;
        case 13: goto L_800591E8; break;
        case 14: goto L_80059214; break;
        case 15: goto L_80059240; break;
        case 16: goto L_8005926C; break;
        case 17: goto L_80059298; break;
        case 18: goto L_800592C4; break;
        case 19: goto L_80059374; break;
        case 20: goto L_8005931C; break;
        case 21: goto L_800593A0; break;
        case 22: goto L_80059348; break;
        case 23: goto L_8005910C; break;
        case 24: goto L_800592F0; break;
        default: switch_error(__func__, 0x80058F88, 0x800D5FB4);
    }
    // 0x80058F8C: nop

L_80058F90:
    // 0x80058F90: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x80058F94: addu        $t9, $t9, $a1
    ctx->r25 = ADD32(ctx->r25, ctx->r5);
    // 0x80058F98: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80058F9C: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x80058FA0: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x80058FA4: addiu       $t0, $t0, -0x5824
    ctx->r8 = ADD32(ctx->r8, -0X5824);
    // 0x80058FA8: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x80058FAC: jal         0x80058C48
    // 0x80058FB0: addu        $a0, $t9, $t0
    ctx->r4 = ADD32(ctx->r25, ctx->r8);
    Load_SceneFiles(rdram, ctx);
        goto after_0;
    // 0x80058FB0: addu        $a0, $t9, $t0
    ctx->r4 = ADD32(ctx->r25, ctx->r8);
    after_0:
    // 0x80058FB4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80058FB8: bne         $v0, $at, L_80059484
    if (ctx->r2 != ctx->r1) {
        // 0x80058FBC: andi        $v1, $v0, 0xFF
        ctx->r3 = ctx->r2 & 0XFF;
            goto L_80059484;
    }
    // 0x80058FBC: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x80058FC0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80058FC4: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    // 0x80058FC8: jal         0x8001DC6C
    // 0x80058FCC: sb          $v1, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r3;
    Audio_SetAudioSpec(rdram, ctx);
        goto after_1;
    // 0x80058FCC: sb          $v1, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r3;
    after_1:
    // 0x80058FD0: b           L_80059484
    // 0x80058FD4: lbu         $v1, 0x1F($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X1F);
        goto L_80059484;
    // 0x80058FD4: lbu         $v1, 0x1F($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X1F);
L_80058FD8:
    // 0x80058FD8: sll         $t1, $a1, 2
    ctx->r9 = S32(ctx->r5 << 2);
    // 0x80058FDC: addu        $t1, $t1, $a1
    ctx->r9 = ADD32(ctx->r9, ctx->r5);
    // 0x80058FE0: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80058FE4: subu        $t1, $t1, $a1
    ctx->r9 = SUB32(ctx->r9, ctx->r5);
    // 0x80058FE8: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x80058FEC: addiu       $t2, $t2, -0x578C
    ctx->r10 = ADD32(ctx->r10, -0X578C);
    // 0x80058FF0: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x80058FF4: jal         0x80058C48
    // 0x80058FF8: addu        $a0, $t1, $t2
    ctx->r4 = ADD32(ctx->r9, ctx->r10);
    Load_SceneFiles(rdram, ctx);
        goto after_2;
    // 0x80058FF8: addu        $a0, $t1, $t2
    ctx->r4 = ADD32(ctx->r9, ctx->r10);
    after_2:
    // 0x80058FFC: b           L_80059484
    // 0x80059000: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
        goto L_80059484;
    // 0x80059000: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
L_80059004:
    // 0x80059004: sll         $t3, $a1, 2
    ctx->r11 = S32(ctx->r5 << 2);
    // 0x80059008: addu        $t3, $t3, $a1
    ctx->r11 = ADD32(ctx->r11, ctx->r5);
    // 0x8005900C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80059010: subu        $t3, $t3, $a1
    ctx->r11 = SUB32(ctx->r11, ctx->r5);
    // 0x80059014: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x80059018: addiu       $t4, $t4, -0x56F4
    ctx->r12 = ADD32(ctx->r12, -0X56F4);
    // 0x8005901C: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x80059020: jal         0x80058C48
    // 0x80059024: addu        $a0, $t3, $t4
    ctx->r4 = ADD32(ctx->r11, ctx->r12);
    Load_SceneFiles(rdram, ctx);
        goto after_3;
    // 0x80059024: addu        $a0, $t3, $t4
    ctx->r4 = ADD32(ctx->r11, ctx->r12);
    after_3:
    // 0x80059028: b           L_80059484
    // 0x8005902C: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
        goto L_80059484;
    // 0x8005902C: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
L_80059030:
    // 0x80059030: sll         $t5, $a1, 2
    ctx->r13 = S32(ctx->r5 << 2);
    // 0x80059034: addu        $t5, $t5, $a1
    ctx->r13 = ADD32(ctx->r13, ctx->r5);
    // 0x80059038: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8005903C: subu        $t5, $t5, $a1
    ctx->r13 = SUB32(ctx->r13, ctx->r5);
    // 0x80059040: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80059044: addiu       $t6, $t6, -0x565C
    ctx->r14 = ADD32(ctx->r14, -0X565C);
    // 0x80059048: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x8005904C: jal         0x80058C48
    // 0x80059050: addu        $a0, $t5, $t6
    ctx->r4 = ADD32(ctx->r13, ctx->r14);
    Load_SceneFiles(rdram, ctx);
        goto after_4;
    // 0x80059050: addu        $a0, $t5, $t6
    ctx->r4 = ADD32(ctx->r13, ctx->r14);
    after_4:
    // 0x80059054: b           L_80059484
    // 0x80059058: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
        goto L_80059484;
    // 0x80059058: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
L_8005905C:
    // 0x8005905C: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x80059060: addu        $t7, $t7, $a1
    ctx->r15 = ADD32(ctx->r15, ctx->r5);
    // 0x80059064: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80059068: subu        $t7, $t7, $a1
    ctx->r15 = SUB32(ctx->r15, ctx->r5);
    // 0x8005906C: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x80059070: addiu       $t8, $t8, -0x55C4
    ctx->r24 = ADD32(ctx->r24, -0X55C4);
    // 0x80059074: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80059078: jal         0x80058C48
    // 0x8005907C: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    Load_SceneFiles(rdram, ctx);
        goto after_5;
    // 0x8005907C: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    after_5:
    // 0x80059080: b           L_80059484
    // 0x80059084: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
        goto L_80059484;
    // 0x80059084: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
L_80059088:
    // 0x80059088: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x8005908C: addu        $t9, $t9, $a1
    ctx->r25 = ADD32(ctx->r25, ctx->r5);
    // 0x80059090: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80059094: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x80059098: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x8005909C: addiu       $t0, $t0, -0x552C
    ctx->r8 = ADD32(ctx->r8, -0X552C);
    // 0x800590A0: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x800590A4: jal         0x80058C48
    // 0x800590A8: addu        $a0, $t9, $t0
    ctx->r4 = ADD32(ctx->r25, ctx->r8);
    Load_SceneFiles(rdram, ctx);
        goto after_6;
    // 0x800590A8: addu        $a0, $t9, $t0
    ctx->r4 = ADD32(ctx->r25, ctx->r8);
    after_6:
    // 0x800590AC: b           L_80059484
    // 0x800590B0: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
        goto L_80059484;
    // 0x800590B0: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
L_800590B4:
    // 0x800590B4: sll         $t1, $a1, 2
    ctx->r9 = S32(ctx->r5 << 2);
    // 0x800590B8: addu        $t1, $t1, $a1
    ctx->r9 = ADD32(ctx->r9, ctx->r5);
    // 0x800590BC: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800590C0: subu        $t1, $t1, $a1
    ctx->r9 = SUB32(ctx->r9, ctx->r5);
    // 0x800590C4: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x800590C8: addiu       $t2, $t2, -0x53FC
    ctx->r10 = ADD32(ctx->r10, -0X53FC);
    // 0x800590CC: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x800590D0: jal         0x80058C48
    // 0x800590D4: addu        $a0, $t1, $t2
    ctx->r4 = ADD32(ctx->r9, ctx->r10);
    Load_SceneFiles(rdram, ctx);
        goto after_7;
    // 0x800590D4: addu        $a0, $t1, $t2
    ctx->r4 = ADD32(ctx->r9, ctx->r10);
    after_7:
    // 0x800590D8: b           L_80059484
    // 0x800590DC: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
        goto L_80059484;
    // 0x800590DC: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
L_800590E0:
    // 0x800590E0: sll         $t3, $a1, 2
    ctx->r11 = S32(ctx->r5 << 2);
    // 0x800590E4: addu        $t3, $t3, $a1
    ctx->r11 = ADD32(ctx->r11, ctx->r5);
    // 0x800590E8: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800590EC: subu        $t3, $t3, $a1
    ctx->r11 = SUB32(ctx->r11, ctx->r5);
    // 0x800590F0: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x800590F4: addiu       $t4, $t4, -0x506C
    ctx->r12 = ADD32(ctx->r12, -0X506C);
    // 0x800590F8: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x800590FC: jal         0x80058C48
    // 0x80059100: addu        $a0, $t3, $t4
    ctx->r4 = ADD32(ctx->r11, ctx->r12);
    Load_SceneFiles(rdram, ctx);
        goto after_8;
    // 0x80059100: addu        $a0, $t3, $t4
    ctx->r4 = ADD32(ctx->r11, ctx->r12);
    after_8:
    // 0x80059104: b           L_80059484
    // 0x80059108: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
        goto L_80059484;
    // 0x80059108: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
L_8005910C:
    // 0x8005910C: sll         $t5, $a1, 2
    ctx->r13 = S32(ctx->r5 << 2);
    // 0x80059110: addu        $t5, $t5, $a1
    ctx->r13 = ADD32(ctx->r13, ctx->r5);
    // 0x80059114: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80059118: subu        $t5, $t5, $a1
    ctx->r13 = SUB32(ctx->r13, ctx->r5);
    // 0x8005911C: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80059120: addiu       $t6, $t6, -0x4F3C
    ctx->r14 = ADD32(ctx->r14, -0X4F3C);
    // 0x80059124: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x80059128: jal         0x80058C48
    // 0x8005912C: addu        $a0, $t5, $t6
    ctx->r4 = ADD32(ctx->r13, ctx->r14);
    Load_SceneFiles(rdram, ctx);
        goto after_9;
    // 0x8005912C: addu        $a0, $t5, $t6
    ctx->r4 = ADD32(ctx->r13, ctx->r14);
    after_9:
    // 0x80059130: b           L_80059484
    // 0x80059134: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
        goto L_80059484;
    // 0x80059134: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
L_80059138:
    // 0x80059138: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x8005913C: addu        $t7, $t7, $a1
    ctx->r15 = ADD32(ctx->r15, ctx->r5);
    // 0x80059140: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80059144: subu        $t7, $t7, $a1
    ctx->r15 = SUB32(ctx->r15, ctx->r5);
    // 0x80059148: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x8005914C: addiu       $t8, $t8, -0x4EA4
    ctx->r24 = ADD32(ctx->r24, -0X4EA4);
    // 0x80059150: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80059154: jal         0x80058C48
    // 0x80059158: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    Load_SceneFiles(rdram, ctx);
        goto after_10;
    // 0x80059158: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    after_10:
    // 0x8005915C: b           L_80059484
    // 0x80059160: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
        goto L_80059484;
    // 0x80059160: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
L_80059164:
    // 0x80059164: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x80059168: addu        $t9, $t9, $a1
    ctx->r25 = ADD32(ctx->r25, ctx->r5);
    // 0x8005916C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80059170: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x80059174: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x80059178: addiu       $t0, $t0, -0x4E0C
    ctx->r8 = ADD32(ctx->r8, -0X4E0C);
    // 0x8005917C: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x80059180: jal         0x80058C48
    // 0x80059184: addu        $a0, $t9, $t0
    ctx->r4 = ADD32(ctx->r25, ctx->r8);
    Load_SceneFiles(rdram, ctx);
        goto after_11;
    // 0x80059184: addu        $a0, $t9, $t0
    ctx->r4 = ADD32(ctx->r25, ctx->r8);
    after_11:
    // 0x80059188: b           L_80059484
    // 0x8005918C: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
        goto L_80059484;
    // 0x8005918C: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
L_80059190:
    // 0x80059190: sll         $t1, $a1, 2
    ctx->r9 = S32(ctx->r5 << 2);
    // 0x80059194: addu        $t1, $t1, $a1
    ctx->r9 = ADD32(ctx->r9, ctx->r5);
    // 0x80059198: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8005919C: subu        $t1, $t1, $a1
    ctx->r9 = SUB32(ctx->r9, ctx->r5);
    // 0x800591A0: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x800591A4: addiu       $t2, $t2, -0x4D74
    ctx->r10 = ADD32(ctx->r10, -0X4D74);
    // 0x800591A8: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x800591AC: jal         0x80058C48
    // 0x800591B0: addu        $a0, $t1, $t2
    ctx->r4 = ADD32(ctx->r9, ctx->r10);
    Load_SceneFiles(rdram, ctx);
        goto after_12;
    // 0x800591B0: addu        $a0, $t1, $t2
    ctx->r4 = ADD32(ctx->r9, ctx->r10);
    after_12:
    // 0x800591B4: b           L_80059484
    // 0x800591B8: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
        goto L_80059484;
    // 0x800591B8: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
L_800591BC:
    // 0x800591BC: sll         $t3, $a1, 2
    ctx->r11 = S32(ctx->r5 << 2);
    // 0x800591C0: addu        $t3, $t3, $a1
    ctx->r11 = ADD32(ctx->r11, ctx->r5);
    // 0x800591C4: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800591C8: subu        $t3, $t3, $a1
    ctx->r11 = SUB32(ctx->r11, ctx->r5);
    // 0x800591CC: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x800591D0: addiu       $t4, $t4, -0x4C44
    ctx->r12 = ADD32(ctx->r12, -0X4C44);
    // 0x800591D4: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x800591D8: jal         0x80058C48
    // 0x800591DC: addu        $a0, $t3, $t4
    ctx->r4 = ADD32(ctx->r11, ctx->r12);
    Load_SceneFiles(rdram, ctx);
        goto after_13;
    // 0x800591DC: addu        $a0, $t3, $t4
    ctx->r4 = ADD32(ctx->r11, ctx->r12);
    after_13:
    // 0x800591E0: b           L_80059484
    // 0x800591E4: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
        goto L_80059484;
    // 0x800591E4: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
L_800591E8:
    // 0x800591E8: sll         $t5, $a1, 2
    ctx->r13 = S32(ctx->r5 << 2);
    // 0x800591EC: addu        $t5, $t5, $a1
    ctx->r13 = ADD32(ctx->r13, ctx->r5);
    // 0x800591F0: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800591F4: subu        $t5, $t5, $a1
    ctx->r13 = SUB32(ctx->r13, ctx->r5);
    // 0x800591F8: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x800591FC: addiu       $t6, $t6, -0x4BAC
    ctx->r14 = ADD32(ctx->r14, -0X4BAC);
    // 0x80059200: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x80059204: jal         0x80058C48
    // 0x80059208: addu        $a0, $t5, $t6
    ctx->r4 = ADD32(ctx->r13, ctx->r14);
    Load_SceneFiles(rdram, ctx);
        goto after_14;
    // 0x80059208: addu        $a0, $t5, $t6
    ctx->r4 = ADD32(ctx->r13, ctx->r14);
    after_14:
    // 0x8005920C: b           L_80059484
    // 0x80059210: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
        goto L_80059484;
    // 0x80059210: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
L_80059214:
    // 0x80059214: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x80059218: addu        $t7, $t7, $a1
    ctx->r15 = ADD32(ctx->r15, ctx->r5);
    // 0x8005921C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80059220: subu        $t7, $t7, $a1
    ctx->r15 = SUB32(ctx->r15, ctx->r5);
    // 0x80059224: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x80059228: addiu       $t8, $t8, -0x4B14
    ctx->r24 = ADD32(ctx->r24, -0X4B14);
    // 0x8005922C: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80059230: jal         0x80058C48
    // 0x80059234: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    Load_SceneFiles(rdram, ctx);
        goto after_15;
    // 0x80059234: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    after_15:
    // 0x80059238: b           L_80059484
    // 0x8005923C: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
        goto L_80059484;
    // 0x8005923C: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
L_80059240:
    // 0x80059240: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x80059244: addu        $t9, $t9, $a1
    ctx->r25 = ADD32(ctx->r25, ctx->r5);
    // 0x80059248: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8005924C: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x80059250: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x80059254: addiu       $t0, $t0, -0x4A7C
    ctx->r8 = ADD32(ctx->r8, -0X4A7C);
    // 0x80059258: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x8005925C: jal         0x80058C48
    // 0x80059260: addu        $a0, $t9, $t0
    ctx->r4 = ADD32(ctx->r25, ctx->r8);
    Load_SceneFiles(rdram, ctx);
        goto after_16;
    // 0x80059260: addu        $a0, $t9, $t0
    ctx->r4 = ADD32(ctx->r25, ctx->r8);
    after_16:
    // 0x80059264: b           L_80059484
    // 0x80059268: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
        goto L_80059484;
    // 0x80059268: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
L_8005926C:
    // 0x8005926C: sll         $t1, $a1, 2
    ctx->r9 = S32(ctx->r5 << 2);
    // 0x80059270: addu        $t1, $t1, $a1
    ctx->r9 = ADD32(ctx->r9, ctx->r5);
    // 0x80059274: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80059278: subu        $t1, $t1, $a1
    ctx->r9 = SUB32(ctx->r9, ctx->r5);
    // 0x8005927C: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x80059280: addiu       $t2, $t2, -0x494C
    ctx->r10 = ADD32(ctx->r10, -0X494C);
    // 0x80059284: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x80059288: jal         0x80058C48
    // 0x8005928C: addu        $a0, $t1, $t2
    ctx->r4 = ADD32(ctx->r9, ctx->r10);
    Load_SceneFiles(rdram, ctx);
        goto after_17;
    // 0x8005928C: addu        $a0, $t1, $t2
    ctx->r4 = ADD32(ctx->r9, ctx->r10);
    after_17:
    // 0x80059290: b           L_80059484
    // 0x80059294: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
        goto L_80059484;
    // 0x80059294: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
L_80059298:
    // 0x80059298: sll         $t3, $a1, 2
    ctx->r11 = S32(ctx->r5 << 2);
    // 0x8005929C: addu        $t3, $t3, $a1
    ctx->r11 = ADD32(ctx->r11, ctx->r5);
    // 0x800592A0: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800592A4: subu        $t3, $t3, $a1
    ctx->r11 = SUB32(ctx->r11, ctx->r5);
    // 0x800592A8: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x800592AC: addiu       $t4, $t4, -0x448C
    ctx->r12 = ADD32(ctx->r12, -0X448C);
    // 0x800592B0: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x800592B4: jal         0x80058C48
    // 0x800592B8: addu        $a0, $t3, $t4
    ctx->r4 = ADD32(ctx->r11, ctx->r12);
    Load_SceneFiles(rdram, ctx);
        goto after_18;
    // 0x800592B8: addu        $a0, $t3, $t4
    ctx->r4 = ADD32(ctx->r11, ctx->r12);
    after_18:
    // 0x800592BC: b           L_80059484
    // 0x800592C0: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
        goto L_80059484;
    // 0x800592C0: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
L_800592C4:
    // 0x800592C4: sll         $t5, $a1, 2
    ctx->r13 = S32(ctx->r5 << 2);
    // 0x800592C8: addu        $t5, $t5, $a1
    ctx->r13 = ADD32(ctx->r13, ctx->r5);
    // 0x800592CC: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800592D0: subu        $t5, $t5, $a1
    ctx->r13 = SUB32(ctx->r13, ctx->r5);
    // 0x800592D4: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x800592D8: addiu       $t6, $t6, -0x49E4
    ctx->r14 = ADD32(ctx->r14, -0X49E4);
    // 0x800592DC: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x800592E0: jal         0x80058C48
    // 0x800592E4: addu        $a0, $t5, $t6
    ctx->r4 = ADD32(ctx->r13, ctx->r14);
    Load_SceneFiles(rdram, ctx);
        goto after_19;
    // 0x800592E4: addu        $a0, $t5, $t6
    ctx->r4 = ADD32(ctx->r13, ctx->r14);
    after_19:
    // 0x800592E8: b           L_80059484
    // 0x800592EC: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
        goto L_80059484;
    // 0x800592EC: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
L_800592F0:
    // 0x800592F0: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x800592F4: addu        $t7, $t7, $a1
    ctx->r15 = ADD32(ctx->r15, ctx->r5);
    // 0x800592F8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800592FC: subu        $t7, $t7, $a1
    ctx->r15 = SUB32(ctx->r15, ctx->r5);
    // 0x80059300: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x80059304: addiu       $t8, $t8, -0x48B4
    ctx->r24 = ADD32(ctx->r24, -0X48B4);
    // 0x80059308: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8005930C: jal         0x80058C48
    // 0x80059310: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    Load_SceneFiles(rdram, ctx);
        goto after_20;
    // 0x80059310: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    after_20:
    // 0x80059314: b           L_80059484
    // 0x80059318: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
        goto L_80059484;
    // 0x80059318: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
L_8005931C:
    // 0x8005931C: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x80059320: addu        $t9, $t9, $a1
    ctx->r25 = ADD32(ctx->r25, ctx->r5);
    // 0x80059324: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80059328: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x8005932C: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x80059330: addiu       $t0, $t0, -0x4784
    ctx->r8 = ADD32(ctx->r8, -0X4784);
    // 0x80059334: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x80059338: jal         0x80058C48
    // 0x8005933C: addu        $a0, $t9, $t0
    ctx->r4 = ADD32(ctx->r25, ctx->r8);
    Load_SceneFiles(rdram, ctx);
        goto after_21;
    // 0x8005933C: addu        $a0, $t9, $t0
    ctx->r4 = ADD32(ctx->r25, ctx->r8);
    after_21:
    // 0x80059340: b           L_80059484
    // 0x80059344: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
        goto L_80059484;
    // 0x80059344: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
L_80059348:
    // 0x80059348: sll         $t1, $a1, 2
    ctx->r9 = S32(ctx->r5 << 2);
    // 0x8005934C: addu        $t1, $t1, $a1
    ctx->r9 = ADD32(ctx->r9, ctx->r5);
    // 0x80059350: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80059354: subu        $t1, $t1, $a1
    ctx->r9 = SUB32(ctx->r9, ctx->r5);
    // 0x80059358: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x8005935C: addiu       $t2, $t2, -0x46EC
    ctx->r10 = ADD32(ctx->r10, -0X46EC);
    // 0x80059360: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x80059364: jal         0x80058C48
    // 0x80059368: addu        $a0, $t1, $t2
    ctx->r4 = ADD32(ctx->r9, ctx->r10);
    Load_SceneFiles(rdram, ctx);
        goto after_22;
    // 0x80059368: addu        $a0, $t1, $t2
    ctx->r4 = ADD32(ctx->r9, ctx->r10);
    after_22:
    // 0x8005936C: b           L_80059484
    // 0x80059370: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
        goto L_80059484;
    // 0x80059370: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
L_80059374:
    // 0x80059374: sll         $t3, $a1, 2
    ctx->r11 = S32(ctx->r5 << 2);
    // 0x80059378: addu        $t3, $t3, $a1
    ctx->r11 = ADD32(ctx->r11, ctx->r5);
    // 0x8005937C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80059380: subu        $t3, $t3, $a1
    ctx->r11 = SUB32(ctx->r11, ctx->r5);
    // 0x80059384: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x80059388: addiu       $t4, $t4, -0x4654
    ctx->r12 = ADD32(ctx->r12, -0X4654);
    // 0x8005938C: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x80059390: jal         0x80058C48
    // 0x80059394: addu        $a0, $t3, $t4
    ctx->r4 = ADD32(ctx->r11, ctx->r12);
    Load_SceneFiles(rdram, ctx);
        goto after_23;
    // 0x80059394: addu        $a0, $t3, $t4
    ctx->r4 = ADD32(ctx->r11, ctx->r12);
    after_23:
    // 0x80059398: b           L_80059484
    // 0x8005939C: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
        goto L_80059484;
    // 0x8005939C: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
L_800593A0:
    // 0x800593A0: sll         $t5, $a1, 2
    ctx->r13 = S32(ctx->r5 << 2);
    // 0x800593A4: addu        $t5, $t5, $a1
    ctx->r13 = ADD32(ctx->r13, ctx->r5);
    // 0x800593A8: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800593AC: subu        $t5, $t5, $a1
    ctx->r13 = SUB32(ctx->r13, ctx->r5);
    // 0x800593B0: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x800593B4: addiu       $t6, $t6, -0x45BC
    ctx->r14 = ADD32(ctx->r14, -0X45BC);
    // 0x800593B8: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x800593BC: jal         0x80058C48
    // 0x800593C0: addu        $a0, $t5, $t6
    ctx->r4 = ADD32(ctx->r13, ctx->r14);
    Load_SceneFiles(rdram, ctx);
        goto after_24;
    // 0x800593C0: addu        $a0, $t5, $t6
    ctx->r4 = ADD32(ctx->r13, ctx->r14);
    after_24:
    // 0x800593C4: b           L_80059484
    // 0x800593C8: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
        goto L_80059484;
    // 0x800593C8: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
L_800593CC:
    // 0x800593CC: addu        $t7, $t7, $a1
    ctx->r15 = ADD32(ctx->r15, ctx->r5);
    // 0x800593D0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800593D4: subu        $t7, $t7, $a1
    ctx->r15 = SUB32(ctx->r15, ctx->r5);
    // 0x800593D8: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x800593DC: addiu       $t8, $t8, -0x43F4
    ctx->r24 = ADD32(ctx->r24, -0X43F4);
    // 0x800593E0: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800593E4: jal         0x80058C48
    // 0x800593E8: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    Load_SceneFiles(rdram, ctx);
        goto after_25;
    // 0x800593E8: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    after_25:
    // 0x800593EC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800593F0: bne         $v0, $at, L_80059484
    if (ctx->r2 != ctx->r1) {
        // 0x800593F4: andi        $v1, $v0, 0xFF
        ctx->r3 = ctx->r2 & 0XFF;
            goto L_80059484;
    }
    // 0x800593F4: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x800593F8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x800593FC: addiu       $a1, $zero, 0x310
    ctx->r5 = ADD32(0, 0X310);
    // 0x80059400: jal         0x8001DC6C
    // 0x80059404: sb          $v1, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r3;
    Audio_SetAudioSpec(rdram, ctx);
        goto after_26;
    // 0x80059404: sb          $v1, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r3;
    after_26:
    // 0x80059408: b           L_80059484
    // 0x8005940C: lbu         $v1, 0x1F($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X1F);
        goto L_80059484;
    // 0x8005940C: lbu         $v1, 0x1F($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X1F);
L_80059410:
    // 0x80059410: addu        $t9, $t9, $a1
    ctx->r25 = ADD32(ctx->r25, ctx->r5);
    // 0x80059414: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80059418: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x8005941C: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x80059420: addiu       $t0, $t0, -0x5C4C
    ctx->r8 = ADD32(ctx->r8, -0X5C4C);
    // 0x80059424: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x80059428: jal         0x80058C48
    // 0x8005942C: addu        $a0, $t9, $t0
    ctx->r4 = ADD32(ctx->r25, ctx->r8);
    Load_SceneFiles(rdram, ctx);
        goto after_27;
    // 0x8005942C: addu        $a0, $t9, $t0
    ctx->r4 = ADD32(ctx->r25, ctx->r8);
    after_27:
    // 0x80059430: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80059434: bne         $v0, $at, L_80059484
    if (ctx->r2 != ctx->r1) {
        // 0x80059438: andi        $v1, $v0, 0xFF
        ctx->r3 = ctx->r2 & 0XFF;
            goto L_80059484;
    }
    // 0x80059438: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x8005943C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80059440: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    // 0x80059444: jal         0x8001DC6C
    // 0x80059448: sb          $v1, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r3;
    Audio_SetAudioSpec(rdram, ctx);
        goto after_28;
    // 0x80059448: sb          $v1, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r3;
    after_28:
    // 0x8005944C: b           L_80059484
    // 0x80059450: lbu         $v1, 0x1F($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X1F);
        goto L_80059484;
    // 0x80059450: lbu         $v1, 0x1F($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X1F);
L_80059454:
    // 0x80059454: sll         $t1, $a1, 2
    ctx->r9 = S32(ctx->r5 << 2);
    // 0x80059458: addu        $t1, $t1, $a1
    ctx->r9 = ADD32(ctx->r9, ctx->r5);
    // 0x8005945C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80059460: subu        $t1, $t1, $a1
    ctx->r9 = SUB32(ctx->r9, ctx->r5);
    // 0x80059464: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x80059468: addiu       $t2, $t2, -0x5BB4
    ctx->r10 = ADD32(ctx->r10, -0X5BB4);
    // 0x8005946C: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x80059470: jal         0x80058C48
    // 0x80059474: addu        $a0, $t1, $t2
    ctx->r4 = ADD32(ctx->r9, ctx->r10);
    Load_SceneFiles(rdram, ctx);
        goto after_29;
    // 0x80059474: addu        $a0, $t1, $t2
    ctx->r4 = ADD32(ctx->r9, ctx->r10);
    after_29:
    // 0x80059478: b           L_80059484
    // 0x8005947C: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
        goto L_80059484;
    // 0x8005947C: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
L_80059480:
    // 0x80059480: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80059484:
    // 0x80059484: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80059488: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005948C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80059490: jr          $ra
    // 0x80059494: nop

    return;
    // 0x80059494: nop

;}
RECOMP_FUNC void Graphics_SetupTextureRender(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009F7B4: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x8009F7B8: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8009F7BC: lui         $ra, 0x8013
    ctx->r31 = S32(0X8013 << 16);
    // 0x8009F7C0: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8009F7C4: sw          $a1, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r5;
    // 0x8009F7C8: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x8009F7CC: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8009F7D0: addiu       $v1, $v1, 0x7E58
    ctx->r3 = ADD32(ctx->r3, 0X7E58);
    // 0x8009F7D4: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x8009F7D8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8009F7DC: addiu       $ra, $ra, 0x7E74
    ctx->r31 = ADD32(ctx->r31, 0X7E74);
    // 0x8009F7E0: sw          $a2, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r6;
    // 0x8009F7E4: lbu         $t4, 0xC3($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0XC3);
    // 0x8009F7E8: addiu       $t8, $a1, 0xF
    ctx->r24 = ADD32(ctx->r5, 0XF);
    // 0x8009F7EC: andi        $t3, $t8, 0x70
    ctx->r11 = ctx->r24 & 0X70;
    // 0x8009F7F0: multu       $t3, $t4
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009F7F4: lw          $a3, 0x0($ra)
    ctx->r7 = MEM_W(ctx->r31, 0X0);
    // 0x8009F7F8: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    // 0x8009F7FC: lui         $t1, 0x8028
    ctx->r9 = S32(0X8028 << 16);
    // 0x8009F800: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x8009F804: addiu       $t1, $t1, 0x2000
    ctx->r9 = ADD32(ctx->r9, 0X2000);
    // 0x8009F808: sw          $a3, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r7;
    // 0x8009F80C: mflo        $t6
    ctx->r14 = lo;
    // 0x8009F810: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x8009F814: addu        $t8, $t7, $a3
    ctx->r24 = ADD32(ctx->r15, ctx->r7);
    // 0x8009F818: sw          $t8, 0x0($ra)
    MEM_W(0X0, ctx->r31) = ctx->r24;
    // 0x8009F81C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8009F820: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x8009F824: lui         $t8, 0xBA00
    ctx->r24 = S32(0XBA00 << 16);
    // 0x8009F828: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8009F82C: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x8009F830: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8009F834: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8009F838: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8009F83C: ori         $t8, $t8, 0x1402
    ctx->r24 = ctx->r24 | 0X1402;
    // 0x8009F840: lui         $t9, 0x30
    ctx->r25 = S32(0X30 << 16);
    // 0x8009F844: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8009F848: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x8009F84C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8009F850: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8009F854: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8009F858: lui         $t7, 0xB900
    ctx->r15 = S32(0XB900 << 16);
    // 0x8009F85C: ori         $t7, $t7, 0x31D
    ctx->r15 = ctx->r15 | 0X31D;
    // 0x8009F860: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8009F864: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8009F868: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8009F86C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8009F870: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8009F874: sll         $t5, $t3, 1
    ctx->r13 = S32(ctx->r11 << 1);
    // 0x8009F878: sll         $a0, $t4, 1
    ctx->r4 = S32(ctx->r12 << 1);
    // 0x8009F87C: sh          $t5, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r13;
    // 0x8009F880: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8009F884: addiu       $t2, $zero, 0x1FF
    ctx->r10 = ADD32(0, 0X1FF);
    // 0x8009F888: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8009F88C: sh          $a0, 0x2($t9)
    MEM_H(0X2, ctx->r25) = ctx->r4;
    // 0x8009F890: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8009F894: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8009F898: lui         $ra, 0xE700
    ctx->r31 = S32(0XE700 << 16);
    // 0x8009F89C: sh          $t2, 0x4($t6)
    MEM_H(0X4, ctx->r14) = ctx->r10;
    // 0x8009F8A0: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8009F8A4: sh          $zero, 0x6($t7)
    MEM_H(0X6, ctx->r15) = 0;
    // 0x8009F8A8: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8009F8AC: sh          $t5, 0x8($t8)
    MEM_H(0X8, ctx->r24) = ctx->r13;
    // 0x8009F8B0: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8009F8B4: sh          $a0, 0xA($t9)
    MEM_H(0XA, ctx->r25) = ctx->r4;
    // 0x8009F8B8: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8009F8BC: addiu       $a0, $t3, -0x1
    ctx->r4 = ADD32(ctx->r11, -0X1);
    // 0x8009F8C0: sh          $t2, 0xC($t6)
    MEM_H(0XC, ctx->r14) = ctx->r10;
    // 0x8009F8C4: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8009F8C8: sh          $zero, 0xE($t7)
    MEM_H(0XE, ctx->r15) = 0;
    // 0x8009F8CC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8009F8D0: lui         $t9, 0x380
    ctx->r25 = S32(0X380 << 16);
    // 0x8009F8D4: ori         $t9, $t9, 0x10
    ctx->r25 = ctx->r25 | 0X10;
    // 0x8009F8D8: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8009F8DC: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8009F8E0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8009F8E4: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8009F8E8: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8009F8EC: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8009F8F0: addiu       $t8, $t7, 0x10
    ctx->r24 = ADD32(ctx->r15, 0X10);
    // 0x8009F8F4: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8009F8F8: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    // 0x8009F8FC: lui         $t6, 0xED00
    ctx->r14 = S32(0XED00 << 16);
    // 0x8009F900: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8009F904: addiu       $t9, $a3, 0x8
    ctx->r25 = ADD32(ctx->r7, 0X8);
    // 0x8009F908: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x8009F90C: bgez        $a1, L_8009F924
    if (SIGNED(ctx->r5) >= 0) {
        // 0x8009F910: sw          $t6, 0x0($a3)
        MEM_W(0X0, ctx->r7) = ctx->r14;
            goto L_8009F924;
    }
    // 0x8009F910: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x8009F914: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8009F918: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8009F91C: nop

    // 0x8009F920: add.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f6.fl;
L_8009F924:
    // 0x8009F924: lbu         $t7, 0xC3($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0XC3);
    // 0x8009F928: mul.s       $f16, $f0, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x8009F92C: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x8009F930: bgez        $t7, L_8009F948
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8009F934: cvt.s.w     $f2, $f8
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    ctx->f2.fl = CVT_S_W(ctx->f8.u32l);
            goto L_8009F948;
    }
    // 0x8009F934: cvt.s.w     $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    ctx->f2.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8009F938: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8009F93C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8009F940: nop

    // 0x8009F944: add.s       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f10.fl;
L_8009F948:
    // 0x8009F948: mul.s       $f4, $f2, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x8009F94C: lui         $at, 0xFF10
    ctx->r1 = S32(0XFF10 << 16);
    // 0x8009F950: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8009F954: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8009F958: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x8009F95C: nop

    // 0x8009F960: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x8009F964: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x8009F968: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x8009F96C: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x8009F970: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x8009F974: sw          $t8, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r24;
    // 0x8009F978: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8009F97C: lui         $t7, 0xFE00
    ctx->r15 = S32(0XFE00 << 16);
    // 0x8009F980: lui         $t5, 0xF700
    ctx->r13 = S32(0XF700 << 16);
    // 0x8009F984: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8009F988: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x8009F98C: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x8009F990: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8009F994: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8009F998: andi        $a3, $a0, 0xFFF
    ctx->r7 = ctx->r4 & 0XFFF;
    // 0x8009F99C: or          $t8, $a3, $at
    ctx->r24 = ctx->r7 | ctx->r1;
    // 0x8009F9A0: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8009F9A4: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8009F9A8: or          $a3, $t8, $zero
    ctx->r7 = ctx->r24 | 0;
    // 0x8009F9AC: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x8009F9B0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8009F9B4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8009F9B8: lui         $t7, 0xFFFC
    ctx->r15 = S32(0XFFFC << 16);
    // 0x8009F9BC: ori         $t7, $t7, 0xFFFC
    ctx->r15 = ctx->r15 | 0XFFFC;
    // 0x8009F9C0: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8009F9C4: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x8009F9C8: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8009F9CC: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8009F9D0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8009F9D4: andi        $t8, $a0, 0x3FF
    ctx->r24 = ctx->r4 & 0X3FF;
    // 0x8009F9D8: sll         $t9, $t8, 14
    ctx->r25 = S32(ctx->r24 << 14);
    // 0x8009F9DC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8009F9E0: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8009F9E4: addiu       $t6, $t4, -0x1
    ctx->r14 = ADD32(ctx->r12, -0X1);
    // 0x8009F9E8: lui         $at, 0xF600
    ctx->r1 = S32(0XF600 << 16);
    // 0x8009F9EC: or          $t7, $t9, $at
    ctx->r15 = ctx->r25 | ctx->r1;
    // 0x8009F9F0: andi        $t8, $t6, 0x3FF
    ctx->r24 = ctx->r14 & 0X3FF;
    // 0x8009F9F4: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8009F9F8: or          $t0, $t7, $t9
    ctx->r8 = ctx->r15 | ctx->r25;
    // 0x8009F9FC: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x8009FA00: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8009FA04: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8009FA08: div.s       $f8, $f0, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8009FA0C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8009FA10: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8009FA14: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8009FA18: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8009FA1C: sw          $ra, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r31;
    // 0x8009FA20: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8009FA24: lui         $t7, 0xB900
    ctx->r15 = S32(0XB900 << 16);
    // 0x8009FA28: ori         $t7, $t7, 0x201
    ctx->r15 = ctx->r15 | 0X201;
    // 0x8009FA2C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8009FA30: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8009FA34: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8009FA38: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8009FA3C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8009FA40: lui         $t7, 0xBA00
    ctx->r15 = S32(0XBA00 << 16);
    // 0x8009FA44: addiu       $a1, $sp, 0xB2
    ctx->r5 = ADD32(ctx->r29, 0XB2);
    // 0x8009FA48: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8009FA4C: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x8009FA50: sw          $a3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r7;
    // 0x8009FA54: lw          $t6, 0xB4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB4);
    // 0x8009FA58: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x8009FA5C: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x8009FA60: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8009FA64: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8009FA68: ori         $t7, $t7, 0x602
    ctx->r15 = ctx->r15 | 0X602;
    // 0x8009FA6C: addiu       $t9, $zero, 0xC0
    ctx->r25 = ADD32(0, 0XC0);
    // 0x8009FA70: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8009FA74: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8009FA78: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8009FA7C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8009FA80: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8009FA84: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8009FA88: lui         $at, 0x4648
    ctx->r1 = S32(0X4648 << 16);
    // 0x8009FA8C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8009FA90: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8009FA94: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8009FA98: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8009FA9C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8009FAA0: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8009FAA4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8009FAA8: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8009FAAC: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8009FAB0: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8009FAB4: lhu         $a0, 0x1A36($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X1A36);
    // 0x8009FAB8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8009FABC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8009FAC0: ori         $t7, $a0, 0x1
    ctx->r15 = ctx->r4 | 0X1;
    // 0x8009FAC4: sll         $t9, $t7, 16
    ctx->r25 = S32(ctx->r15 << 16);
    // 0x8009FAC8: or          $t6, $t9, $t7
    ctx->r14 = ctx->r25 | ctx->r15;
    // 0x8009FACC: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8009FAD0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8009FAD4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8009FAD8: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8009FADC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8009FAE0: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x8009FAE4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8009FAE8: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8009FAEC: addiu       $v1, $v1, 0x7E5C
    ctx->r3 = ADD32(ctx->r3, 0X7E5C);
    // 0x8009FAF0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8009FAF4: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x8009FAF8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8009FAFC: sw          $ra, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r31;
    // 0x8009FB00: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x8009FB04: lw          $a2, 0x1A3C($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X1A3C);
    // 0x8009FB08: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x8009FB0C: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x8009FB10: jal         0x80021170
    // 0x8009FB14: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    guPerspective(rdram, ctx);
        goto after_0;
    // 0x8009FB14: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    after_0:
    // 0x8009FB18: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8009FB1C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8009FB20: addiu       $v1, $v1, 0x7E5C
    ctx->r3 = ADD32(ctx->r3, 0X7E5C);
    // 0x8009FB24: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8009FB28: lui         $t6, 0xBC00
    ctx->r14 = S32(0XBC00 << 16);
    // 0x8009FB2C: ori         $t6, $t6, 0xE
    ctx->r14 = ctx->r14 | 0XE;
    // 0x8009FB30: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8009FB34: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x8009FB38: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8009FB3C: lhu         $t8, 0xB2($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0XB2);
    // 0x8009FB40: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8009FB44: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8009FB48: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8009FB4C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8009FB50: lui         $t9, 0x103
    ctx->r25 = S32(0X103 << 16);
    // 0x8009FB54: ori         $t9, $t9, 0x40
    ctx->r25 = ctx->r25 | 0X40;
    // 0x8009FB58: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8009FB5C: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x8009FB60: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8009FB64: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8009FB68: lui         $at, 0xC648
    ctx->r1 = S32(0XC648 << 16);
    // 0x8009FB6C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8009FB70: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8009FB74: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8009FB78: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8009FB7C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8009FB80: addiu       $t7, $t8, 0x40
    ctx->r15 = ADD32(ctx->r24, 0X40);
    // 0x8009FB84: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8009FB88: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8009FB8C: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x8009FB90: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x8009FB94: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x8009FB98: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x8009FB9C: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x8009FBA0: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x8009FBA4: jal         0x80021488
    // 0x8009FBA8: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    guLookAt(rdram, ctx);
        goto after_1;
    // 0x8009FBA8: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x8009FBAC: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8009FBB0: addiu       $v1, $v1, 0x7E5C
    ctx->r3 = ADD32(ctx->r3, 0X7E5C);
    // 0x8009FBB4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8009FBB8: lui         $t6, 0x101
    ctx->r14 = S32(0X101 << 16);
    // 0x8009FBBC: ori         $t6, $t6, 0x40
    ctx->r14 = ctx->r14 | 0X40;
    // 0x8009FBC0: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8009FBC4: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x8009FBC8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8009FBCC: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8009FBD0: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x8009FBD4: addiu       $a1, $a1, 0x4660
    ctx->r5 = ADD32(ctx->r5, 0X4660);
    // 0x8009FBD8: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8009FBDC: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8009FBE0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8009FBE4: addiu       $t9, $t7, 0x40
    ctx->r25 = ADD32(ctx->r15, 0X40);
    // 0x8009FBE8: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8009FBEC: jal         0x80005680
    // 0x8009FBF0: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Copy(rdram, ctx);
        goto after_2;
    // 0x8009FBF0: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_2:
    // 0x8009FBF4: lw          $v0, 0xB4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XB4);
    // 0x8009FBF8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8009FBFC: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8009FC00: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    // 0x8009FC04: jr          $ra
    // 0x8009FC08: nop

    return;
    // 0x8009FC08: nop

;}
RECOMP_FUNC void Item_Initialize(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80061444: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80061448: addiu       $a0, $zero, 0x6C
    ctx->r4 = ADD32(0, 0X6C);
    // 0x8006144C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80061450:
    // 0x80061450: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80061454: sb          $zero, 0x1($v0)
    MEM_B(0X1, ctx->r2) = 0;
    // 0x80061458: sb          $zero, 0x2($v0)
    MEM_B(0X2, ctx->r2) = 0;
    // 0x8006145C: sb          $zero, 0x3($v0)
    MEM_B(0X3, ctx->r2) = 0;
    // 0x80061460: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80061464: bne         $v1, $a0, L_80061450
    if (ctx->r3 != ctx->r4) {
        // 0x80061468: sb          $zero, -0x4($v0)
        MEM_B(-0X4, ctx->r2) = 0;
            goto L_80061450;
    }
    // 0x80061468: sb          $zero, -0x4($v0)
    MEM_B(-0X4, ctx->r2) = 0;
    // 0x8006146C: jr          $ra
    // 0x80061470: nop

    return;
    // 0x80061470: nop

;}
RECOMP_FUNC void AudioSeq_ScriptReadU8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800146C0: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x800146C4: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x800146C8: addiu       $t6, $a1, 0x1
    ctx->r14 = ADD32(ctx->r5, 0X1);
    // 0x800146CC: jr          $ra
    // 0x800146D0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    return;
    // 0x800146D0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
;}
RECOMP_FUNC void RCP_SetupDL_30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BA2E8: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800BA2EC: addiu       $t3, $t3, 0x7E64
    ctx->r11 = ADD32(ctx->r11, 0X7E64);
    // 0x800BA2F0: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x800BA2F4: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x800BA2F8: addiu       $t8, $t8, 0x3A20
    ctx->r24 = ADD32(ctx->r24, 0X3A20);
    // 0x800BA2FC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800BA300: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x800BA304: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x800BA308: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800BA30C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800BA310: lw          $t0, 0x0($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X0);
    // 0x800BA314: lui         $t4, 0xF800
    ctx->r12 = S32(0XF800 << 16);
    // 0x800BA318: andi        $t7, $a1, 0xFF
    ctx->r15 = ctx->r5 & 0XFF;
    // 0x800BA31C: addiu       $t9, $t0, 0x8
    ctx->r25 = ADD32(ctx->r8, 0X8);
    // 0x800BA320: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x800BA324: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x800BA328: sll         $t6, $a0, 24
    ctx->r14 = S32(ctx->r4 << 24);
    // 0x800BA32C: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
    // 0x800BA330: andi        $t4, $a2, 0xFF
    ctx->r12 = ctx->r6 & 0XFF;
    // 0x800BA334: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x800BA338: sll         $t5, $t4, 8
    ctx->r13 = S32(ctx->r12 << 8);
    // 0x800BA33C: or          $t7, $t9, $t5
    ctx->r15 = ctx->r25 | ctx->r13;
    // 0x800BA340: andi        $t6, $a3, 0xFF
    ctx->r14 = ctx->r7 & 0XFF;
    // 0x800BA344: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x800BA348: sw          $t8, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r24;
    // 0x800BA34C: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x800BA350: lui         $t9, 0xBC00
    ctx->r25 = S32(0XBC00 << 16);
    // 0x800BA354: ori         $t9, $t9, 0x8
    ctx->r25 = ctx->r25 | 0X8;
    // 0x800BA358: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x800BA35C: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
    // 0x800BA360: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800BA364: lw          $t7, 0x10($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X10);
    // 0x800BA368: lw          $t5, 0x14($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X14);
    // 0x800BA36C: lui         $t6, 0x1
    ctx->r14 = S32(0X1 << 16);
    // 0x800BA370: ori         $t6, $t6, 0xF400
    ctx->r14 = ctx->r14 | 0XF400;
    // 0x800BA374: subu        $t2, $t5, $t7
    ctx->r10 = SUB32(ctx->r13, ctx->r15);
    // 0x800BA378: div         $zero, $t6, $t2
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r10))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r10)));
    // 0x800BA37C: negu        $t5, $t7
    ctx->r13 = SUB32(0, ctx->r15);
    // 0x800BA380: mflo        $t4
    ctx->r12 = lo;
    // 0x800BA384: sll         $t9, $t4, 16
    ctx->r25 = S32(ctx->r12 << 16);
    // 0x800BA388: or          $t1, $v1, $zero
    ctx->r9 = ctx->r3 | 0;
    // 0x800BA38C: bne         $t2, $zero, L_800BA398
    if (ctx->r10 != 0) {
        // 0x800BA390: nop
    
            goto L_800BA398;
    }
    // 0x800BA390: nop

    // 0x800BA394: break       7
    do_break(2148246420);
L_800BA398:
    // 0x800BA398: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800BA39C: bne         $t2, $at, L_800BA3B0
    if (ctx->r10 != ctx->r1) {
        // 0x800BA3A0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800BA3B0;
    }
    // 0x800BA3A0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800BA3A4: bne         $t6, $at, L_800BA3B0
    if (ctx->r14 != ctx->r1) {
        // 0x800BA3A8: nop
    
            goto L_800BA3B0;
    }
    // 0x800BA3A8: nop

    // 0x800BA3AC: break       6
    do_break(2148246444);
L_800BA3B0:
    // 0x800BA3B0: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x800BA3B4: ori         $at, $at, 0xF400
    ctx->r1 = ctx->r1 | 0XF400;
    // 0x800BA3B8: sll         $t6, $t5, 8
    ctx->r14 = S32(ctx->r13 << 8);
    // 0x800BA3BC: addu        $t8, $t6, $at
    ctx->r24 = ADD32(ctx->r14, ctx->r1);
    // 0x800BA3C0: div         $zero, $t8, $t2
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r10))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r10)));
    // 0x800BA3C4: mflo        $t4
    ctx->r12 = lo;
    // 0x800BA3C8: andi        $t7, $t4, 0xFFFF
    ctx->r15 = ctx->r12 & 0XFFFF;
    // 0x800BA3CC: or          $t5, $t9, $t7
    ctx->r13 = ctx->r25 | ctx->r15;
    // 0x800BA3D0: sw          $t5, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r13;
    // 0x800BA3D4: bne         $t2, $zero, L_800BA3E0
    if (ctx->r10 != 0) {
        // 0x800BA3D8: nop
    
            goto L_800BA3E0;
    }
    // 0x800BA3D8: nop

    // 0x800BA3DC: break       7
    do_break(2148246492);
L_800BA3E0:
    // 0x800BA3E0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800BA3E4: bne         $t2, $at, L_800BA3F8
    if (ctx->r10 != ctx->r1) {
        // 0x800BA3E8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800BA3F8;
    }
    // 0x800BA3E8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800BA3EC: bne         $t8, $at, L_800BA3F8
    if (ctx->r24 != ctx->r1) {
        // 0x800BA3F0: nop
    
            goto L_800BA3F8;
    }
    // 0x800BA3F0: nop

    // 0x800BA3F4: break       6
    do_break(2148246516);
L_800BA3F8:
    // 0x800BA3F8: jr          $ra
    // 0x800BA3FC: nop

    return;
    // 0x800BA3FC: nop

;}
RECOMP_FUNC void Display_OnFootCharacter_OverrideLimbDraw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800520FC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80052100: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80052104: addiu       $t0, $t0, 0x7E64
    ctx->r8 = ADD32(ctx->r8, 0X7E64);
    // 0x80052108: lw          $a1, 0x10($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X10);
    // 0x8005210C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80052110: addiu       $t1, $zero, 0x2000
    ctx->r9 = ADD32(0, 0X2000);
    // 0x80052114: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80052118: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x8005211C: lui         $t7, 0xB700
    ctx->r15 = S32(0XB700 << 16);
    // 0x80052120: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80052124: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80052128: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x8005212C: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x80052130: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80052134: lw          $a2, 0x1C4($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X1C4);
    // 0x80052138: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8005213C: bne         $t2, $a2, L_80052268
    if (ctx->r10 != ctx->r6) {
        // 0x80052140: nop
    
            goto L_80052268;
    }
    // 0x80052140: nop

    // 0x80052144: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x80052148: bne         $a0, $at, L_80052170
    if (ctx->r4 != ctx->r1) {
        // 0x8005214C: lui         $a2, 0xB600
        ctx->r6 = S32(0XB600 << 16);
            goto L_80052170;
    }
    // 0x8005214C: lui         $a2, 0xB600
    ctx->r6 = S32(0XB600 << 16);
    // 0x80052150: lwc1        $f4, 0x4($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X4);
    // 0x80052154: lwc1        $f6, 0x154($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X154);
    // 0x80052158: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8005215C: swc1        $f8, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f8.u32l;
    // 0x80052160: lwc1        $f10, 0x4($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X4);
    // 0x80052164: lwc1        $f16, 0x180($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X180);
    // 0x80052168: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8005216C: swc1        $f18, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f18.u32l;
L_80052170:
    // 0x80052170: addiu       $at, $zero, 0x16
    ctx->r1 = ADD32(0, 0X16);
    // 0x80052174: bne         $a0, $at, L_800521AC
    if (ctx->r4 != ctx->r1) {
        // 0x80052178: nop
    
            goto L_800521AC;
    }
    // 0x80052178: nop

    // 0x8005217C: lwc1        $f4, 0x158($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X158);
    // 0x80052180: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80052184: lwc1        $f8, 0x5DDC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5DDC);
    // 0x80052188: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x8005218C: lwc1        $f16, 0x4($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X4);
    // 0x80052190: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80052194: lwc1        $f4, 0x0($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X0);
    // 0x80052198: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x8005219C: swc1        $f18, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f18.u32l;
    // 0x800521A0: lwc1        $f6, 0x15C($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X15C);
    // 0x800521A4: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800521A8: swc1        $f8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f8.u32l;
L_800521AC:
    // 0x800521AC: bne         $a0, $t2, L_800521D8
    if (ctx->r4 != ctx->r10) {
        // 0x800521B0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800521D8;
    }
    // 0x800521B0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800521B4: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x800521B8: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x800521BC: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x800521C0: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x800521C4: sw          $a2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r6;
    // 0x800521C8: lwc1        $f16, 0x4($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X4);
    // 0x800521CC: lwc1        $f10, 0x164($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X164);
    // 0x800521D0: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x800521D4: swc1        $f18, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f18.u32l;
L_800521D8:
    // 0x800521D8: bne         $a0, $at, L_80052204
    if (ctx->r4 != ctx->r1) {
        // 0x800521DC: lui         $a2, 0xB600
        ctx->r6 = S32(0XB600 << 16);
            goto L_80052204;
    }
    // 0x800521DC: lui         $a2, 0xB600
    ctx->r6 = S32(0XB600 << 16);
    // 0x800521E0: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x800521E4: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x800521E8: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x800521EC: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x800521F0: sw          $a2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r6;
    // 0x800521F4: lwc1        $f4, 0x4($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X4);
    // 0x800521F8: lwc1        $f6, 0x164($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X164);
    // 0x800521FC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80052200: swc1        $f8, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f8.u32l;
L_80052204:
    // 0x80052204: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80052208: bnel        $a0, $at, L_80052238
    if (ctx->r4 != ctx->r1) {
        // 0x8005220C: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80052238;
    }
    goto skip_0;
    // 0x8005220C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    skip_0:
    // 0x80052210: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x80052214: addiu       $t3, $v1, 0x8
    ctx->r11 = ADD32(ctx->r3, 0X8);
    // 0x80052218: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x8005221C: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x80052220: sw          $a2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r6;
    // 0x80052224: lwc1        $f16, 0x4($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X4);
    // 0x80052228: lwc1        $f10, 0x168($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X168);
    // 0x8005222C: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x80052230: swc1        $f18, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f18.u32l;
    // 0x80052234: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
L_80052238:
    // 0x80052238: bne         $a0, $at, L_800523A0
    if (ctx->r4 != ctx->r1) {
        // 0x8005223C: nop
    
            goto L_800523A0;
    }
    // 0x8005223C: nop

    // 0x80052240: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x80052244: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x80052248: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
    // 0x8005224C: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x80052250: sw          $a2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r6;
    // 0x80052254: lwc1        $f4, 0x4($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X4);
    // 0x80052258: lwc1        $f6, 0x168($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X168);
    // 0x8005225C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80052260: b           L_800523A0
    // 0x80052264: swc1        $f8, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f8.u32l;
        goto L_800523A0;
    // 0x80052264: swc1        $f8, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f8.u32l;
L_80052268:
    // 0x80052268: bnel        $a0, $at, L_800522F4
    if (ctx->r4 != ctx->r1) {
        // 0x8005226C: addiu       $at, $zero, 0x10
        ctx->r1 = ADD32(0, 0X10);
            goto L_800522F4;
    }
    goto skip_1;
    // 0x8005226C: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    skip_1:
    // 0x80052270: bnel        $a2, $zero, L_800522A0
    if (ctx->r6 != 0) {
        // 0x80052274: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800522A0;
    }
    goto skip_2;
    // 0x80052274: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_2:
    // 0x80052278: lwc1        $f16, 0x154($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X154);
    // 0x8005227C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80052280: lwc1        $f18, 0x5DE0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X5DE0);
    // 0x80052284: neg.s       $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = -ctx->f16.fl;
    // 0x80052288: lwc1        $f6, 0x4($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X4);
    // 0x8005228C: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80052290: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80052294: swc1        $f8, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f8.u32l;
    // 0x80052298: lw          $a2, 0x1C4($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X1C4);
    // 0x8005229C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_800522A0:
    // 0x800522A0: bnel        $a2, $at, L_800522D0
    if (ctx->r6 != ctx->r1) {
        // 0x800522A4: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800522D0;
    }
    goto skip_3;
    // 0x800522A4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    skip_3:
    // 0x800522A8: lwc1        $f16, 0x4($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X4);
    // 0x800522AC: lwc1        $f10, 0x154($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X154);
    // 0x800522B0: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x800522B4: swc1        $f18, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f18.u32l;
    // 0x800522B8: lwc1        $f6, 0x4($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X4);
    // 0x800522BC: lwc1        $f4, 0x180($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X180);
    // 0x800522C0: sub.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x800522C4: swc1        $f8, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f8.u32l;
    // 0x800522C8: lw          $a2, 0x1C4($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X1C4);
    // 0x800522CC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
L_800522D0:
    // 0x800522D0: bne         $a2, $at, L_800522F0
    if (ctx->r6 != ctx->r1) {
        // 0x800522D4: lui         $at, 0x800D
        ctx->r1 = S32(0X800D << 16);
            goto L_800522F0;
    }
    // 0x800522D4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800522D8: lwc1        $f10, 0x5DE4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X5DE4);
    // 0x800522DC: lwc1        $f16, 0x154($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X154);
    // 0x800522E0: lwc1        $f6, 0x4($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X4);
    // 0x800522E4: mul.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x800522E8: add.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x800522EC: swc1        $f4, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f4.u32l;
L_800522F0:
    // 0x800522F0: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
L_800522F4:
    // 0x800522F4: bnel        $a0, $at, L_80052330
    if (ctx->r4 != ctx->r1) {
        // 0x800522F8: addiu       $at, $zero, 0x11
        ctx->r1 = ADD32(0, 0X11);
            goto L_80052330;
    }
    goto skip_4;
    // 0x800522F8: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    skip_4:
    // 0x800522FC: lwc1        $f8, 0x158($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X158);
    // 0x80052300: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80052304: lwc1        $f10, 0x5DE8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X5DE8);
    // 0x80052308: neg.s       $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = -ctx->f8.fl;
    // 0x8005230C: lwc1        $f18, 0x4($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X4);
    // 0x80052310: mul.s       $f6, $f16, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x80052314: lwc1        $f8, 0x0($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X0);
    // 0x80052318: add.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x8005231C: swc1        $f4, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f4.u32l;
    // 0x80052320: lwc1        $f16, 0x15C($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X15C);
    // 0x80052324: sub.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x80052328: swc1        $f10, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f10.u32l;
    // 0x8005232C: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
L_80052330:
    // 0x80052330: bne         $a0, $at, L_800523A0
    if (ctx->r4 != ctx->r1) {
        // 0x80052334: nop
    
            goto L_800523A0;
    }
    // 0x80052334: nop

    // 0x80052338: lw          $t5, 0x1C4($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X1C4);
    // 0x8005233C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80052340: beq         $t5, $at, L_800523A0
    if (ctx->r13 == ctx->r1) {
        // 0x80052344: nop
    
            goto L_800523A0;
    }
    // 0x80052344: nop

    // 0x80052348: lwc1        $f18, 0x4($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X4);
    // 0x8005234C: lwc1        $f6, 0x180($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X180);
    // 0x80052350: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80052354: lwc1        $f0, 0x5DEC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5DEC);
    // 0x80052358: add.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x8005235C: lwc1        $f8, 0x0($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X0);
    // 0x80052360: swc1        $f4, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f4.u32l;
    // 0x80052364: lwc1        $f16, 0x180($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X180);
    // 0x80052368: lwc1        $f18, 0x4($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X4);
    // 0x8005236C: sub.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x80052370: swc1        $f10, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f10.u32l;
    // 0x80052374: lwc1        $f6, 0x158($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X158);
    // 0x80052378: lwc1        $f10, 0x0($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X0);
    // 0x8005237C: neg.s       $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = -ctx->f6.fl;
    // 0x80052380: mul.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80052384: add.s       $f16, $f18, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x80052388: swc1        $f16, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f16.u32l;
    // 0x8005238C: lwc1        $f6, 0x15C($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X15C);
    // 0x80052390: neg.s       $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = -ctx->f6.fl;
    // 0x80052394: mul.s       $f18, $f4, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80052398: add.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8005239C: swc1        $f8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f8.u32l;
L_800523A0:
    // 0x800523A0: jr          $ra
    // 0x800523A4: nop

    return;
    // 0x800523A4: nop

;}
RECOMP_FUNC void AudioSynth_LoadRingBufferPart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800098DC: sra         $t0, $a3, 4
    ctx->r8 = S32(SIGNED(ctx->r7) >> 4);
    // 0x800098E0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800098E4: or          $t6, $a1, $zero
    ctx->r14 = ctx->r5 | 0;
    // 0x800098E8: andi        $t8, $t0, 0xFF
    ctx->r24 = ctx->r8 & 0XFF;
    // 0x800098EC: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x800098F0: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x800098F4: andi        $t7, $a2, 0xFFFF
    ctx->r15 = ctx->r6 & 0XFFFF;
    // 0x800098F8: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x800098FC: lui         $at, 0x1400
    ctx->r1 = S32(0X1400 << 16);
    // 0x80009900: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x80009904: or          $t0, $t9, $at
    ctx->r8 = ctx->r25 | ctx->r1;
    // 0x80009908: andi        $t6, $t6, 0xFFFF
    ctx->r14 = ctx->r14 & 0XFFFF;
    // 0x8000990C: or          $t7, $t0, $t6
    ctx->r15 = ctx->r8 | ctx->r14;
    // 0x80009910: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80009914: lw          $t8, 0x10($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X10);
    // 0x80009918: lui         $t5, 0x8015
    ctx->r13 = S32(0X8015 << 16);
    // 0x8000991C: addiu       $t5, $t5, -0x45B0
    ctx->r13 = ADD32(ctx->r13, -0X45B0);
    // 0x80009920: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x80009924: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80009928: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8000992C: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80009930: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80009934: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80009938: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8000993C: addu        $t1, $t9, $t5
    ctx->r9 = ADD32(ctx->r25, ctx->r13);
    // 0x80009940: lw          $t6, 0x1C($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X1C);
    // 0x80009944: sll         $t2, $a2, 1
    ctx->r10 = S32(ctx->r6 << 1);
    // 0x80009948: lui         $t4, 0x8000
    ctx->r12 = S32(0X8000 << 16);
    // 0x8000994C: addiu       $t9, $a1, 0x180
    ctx->r25 = ADD32(ctx->r5, 0X180);
    // 0x80009950: addu        $t7, $t6, $t2
    ctx->r15 = ADD32(ctx->r14, ctx->r10);
    // 0x80009954: addu        $t8, $t7, $t4
    ctx->r24 = ADD32(ctx->r15, ctx->r12);
    // 0x80009958: andi        $t5, $t9, 0xFFFF
    ctx->r13 = ctx->r25 & 0XFFFF;
    // 0x8000995C: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x80009960: addiu       $t3, $a0, 0x8
    ctx->r11 = ADD32(ctx->r4, 0X8);
    // 0x80009964: or          $t6, $t0, $t5
    ctx->r14 = ctx->r8 | ctx->r13;
    // 0x80009968: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x8000996C: lw          $t7, 0x20($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X20);
    // 0x80009970: addiu       $v0, $t3, 0x8
    ctx->r2 = ADD32(ctx->r11, 0X8);
    // 0x80009974: addu        $t8, $t7, $t2
    ctx->r24 = ADD32(ctx->r15, ctx->r10);
    // 0x80009978: addu        $t9, $t8, $t4
    ctx->r25 = ADD32(ctx->r24, ctx->r12);
    // 0x8000997C: jr          $ra
    // 0x80009980: sw          $t9, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r25;
    return;
    // 0x80009980: sw          $t9, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r25;
;}
RECOMP_FUNC void PlayerShot_DrawShot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80039A50: addiu       $sp, $sp, -0x128
    ctx->r29 = ADD32(ctx->r29, -0X128);
    // 0x80039A54: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80039A58: lui         $s2, 0x8014
    ctx->r18 = S32(0X8014 << 16);
    // 0x80039A5C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80039A60: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80039A64: addiu       $s2, $s2, -0x4C40
    ctx->r18 = ADD32(ctx->r18, -0X4C40);
    // 0x80039A68: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80039A6C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80039A70: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x80039A74: addiu       $t7, $t7, -0x63F4
    ctx->r15 = ADD32(ctx->r15, -0X63F4);
    // 0x80039A78: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x80039A7C: addiu       $t6, $sp, 0x11C
    ctx->r14 = ADD32(ctx->r29, 0X11C);
    // 0x80039A80: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x80039A84: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x80039A88: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x80039A8C: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x80039A90: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80039A94: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x80039A98: sw          $zero, 0x104($sp)
    MEM_W(0X104, ctx->r29) = 0;
    // 0x80039A9C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80039AA0: lwc1        $f6, 0x7D20($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x80039AA4: lwc1        $f4, 0xC($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80039AA8: lw          $a2, 0x8($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X8);
    // 0x80039AAC: lw          $a1, 0x4($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X4);
    // 0x80039AB0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80039AB4: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80039AB8: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80039ABC: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x80039AC0: jal         0x80005B00
    // 0x80039AC4: nop

    Matrix_Translate(rdram, ctx);
        goto after_0;
    // 0x80039AC4: nop

    after_0:
    // 0x80039AC8: lui         $s0, 0x8016
    ctx->r16 = S32(0X8016 << 16);
    // 0x80039ACC: addiu       $s0, $s0, -0x6B0
    ctx->r16 = ADD32(ctx->r16, -0X6B0);
    // 0x80039AD0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80039AD4: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80039AD8: jal         0x80006970
    // 0x80039ADC: addiu       $a1, $sp, 0x11C
    ctx->r5 = ADD32(ctx->r29, 0X11C);
    Matrix_MultVec3f(rdram, ctx);
        goto after_1;
    // 0x80039ADC: addiu       $a1, $sp, 0x11C
    ctx->r5 = ADD32(ctx->r29, 0X11C);
    after_1:
    // 0x80039AE0: lwc1        $f12, 0x8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80039AE4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80039AE8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80039AEC: c.lt.s      $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f12.fl < ctx->f10.fl;
    // 0x80039AF0: nop

    // 0x80039AF4: bc1fl       L_80039B6C
    if (!c1cs) {
        // 0x80039AF8: lw          $t3, 0x104($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X104);
            goto L_80039B6C;
    }
    goto skip_0;
    // 0x80039AF8: lw          $t3, 0x104($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X104);
    skip_0:
    // 0x80039AFC: lwc1        $f18, 0x5288($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X5288);
    // 0x80039B00: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x80039B04: c.lt.s      $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f18.fl < ctx->f12.fl;
    // 0x80039B08: nop

    // 0x80039B0C: bc1fl       L_80039B6C
    if (!c1cs) {
        // 0x80039B10: lw          $t3, 0x104($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X104);
            goto L_80039B6C;
    }
    goto skip_1;
    // 0x80039B10: lw          $t3, 0x104($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X104);
    skip_1:
    // 0x80039B14: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80039B18: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80039B1C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80039B20: lwc1        $f0, 0x0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80039B24: mul.s       $f14, $f12, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x80039B28: abs.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = fabsf(ctx->f0.fl);
    // 0x80039B2C: abs.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = fabsf(ctx->f14.fl);
    // 0x80039B30: add.s       $f6, $f14, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f14.fl + ctx->f16.fl;
    // 0x80039B34: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x80039B38: nop

    // 0x80039B3C: bc1fl       L_80039B6C
    if (!c1cs) {
        // 0x80039B40: lw          $t3, 0x104($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X104);
            goto L_80039B6C;
    }
    goto skip_2;
    // 0x80039B40: lw          $t3, 0x104($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X104);
    skip_2:
    // 0x80039B44: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80039B48: add.s       $f8, $f14, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f14.fl + ctx->f16.fl;
    // 0x80039B4C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80039B50: abs.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = fabsf(ctx->f0.fl);
    // 0x80039B54: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x80039B58: nop

    // 0x80039B5C: bc1fl       L_80039B6C
    if (!c1cs) {
        // 0x80039B60: lw          $t3, 0x104($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X104);
            goto L_80039B6C;
    }
    goto skip_3;
    // 0x80039B60: lw          $t3, 0x104($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X104);
    skip_3:
    // 0x80039B64: sw          $t2, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r10;
    // 0x80039B68: lw          $t3, 0x104($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X104);
L_80039B6C:
    // 0x80039B6C: bnel        $t3, $zero, L_80039BBC
    if (ctx->r11 != 0) {
        // 0x80039B70: lhu         $v1, 0x2($s1)
        ctx->r3 = MEM_HU(ctx->r17, 0X2);
            goto L_80039BBC;
    }
    goto skip_4;
    // 0x80039B70: lhu         $v1, 0x2($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X2);
    skip_4:
    // 0x80039B74: lhu         $t4, 0x2($s1)
    ctx->r12 = MEM_HU(ctx->r17, 0X2);
    // 0x80039B78: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80039B7C: beql        $t4, $at, L_8003AF74
    if (ctx->r12 == ctx->r1) {
        // 0x80039B80: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8003AF74;
    }
    goto skip_5;
    // 0x80039B80: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_5:
    // 0x80039B84: lw          $t5, 0x64($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X64);
    // 0x80039B88: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x80039B8C: slti        $at, $t5, 0xA
    ctx->r1 = SIGNED(ctx->r13) < 0XA ? 1 : 0;
    // 0x80039B90: beql        $at, $zero, L_8003AF74
    if (ctx->r1 == 0) {
        // 0x80039B94: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8003AF74;
    }
    goto skip_6;
    // 0x80039B94: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_6:
    // 0x80039B98: lw          $t9, 0x78E8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X78E8);
    // 0x80039B9C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80039BA0: bnel        $t9, $zero, L_8003AF74
    if (ctx->r25 != 0) {
        // 0x80039BA4: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8003AF74;
    }
    goto skip_7;
    // 0x80039BA4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_7:
    // 0x80039BA8: jal         0x80060FBC
    // 0x80039BAC: addiu       $a1, $s1, 0x38
    ctx->r5 = ADD32(ctx->r17, 0X38);
    Object_Kill(rdram, ctx);
        goto after_2;
    // 0x80039BAC: addiu       $a1, $s1, 0x38
    ctx->r5 = ADD32(ctx->r17, 0X38);
    after_2:
    // 0x80039BB0: b           L_8003AF74
    // 0x80039BB4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8003AF74;
    // 0x80039BB4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80039BB8: lhu         $v1, 0x2($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X2);
L_80039BBC:
    // 0x80039BBC: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80039BC0: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x80039BC4: beq         $v1, $at, L_80039BE0
    if (ctx->r3 == ctx->r1) {
        // 0x80039BC8: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80039BE0;
    }
    // 0x80039BC8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80039BCC: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80039BD0: beq         $v1, $at, L_80039BE0
    if (ctx->r3 == ctx->r1) {
        // 0x80039BD4: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_80039BE0;
    }
    // 0x80039BD4: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80039BD8: bnel        $v1, $at, L_80039C74
    if (ctx->r3 != ctx->r1) {
        // 0x80039BDC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80039C74;
    }
    goto skip_8;
    // 0x80039BDC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_8:
L_80039BE0:
    // 0x80039BE0: lw          $t6, 0x78A0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X78A0);
    // 0x80039BE4: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80039BE8: lw          $t8, -0x7D80($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7D80);
    // 0x80039BEC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80039BF0: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80039BF4: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80039BF8: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80039BFC: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x80039C00: addu        $t0, $t8, $t7
    ctx->r8 = ADD32(ctx->r24, ctx->r15);
    // 0x80039C04: lwc1        $f10, 0x58($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X58);
    // 0x80039C08: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80039C0C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80039C10: neg.s       $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = -ctx->f10.fl;
    // 0x80039C14: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80039C18: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80039C1C: lwc1        $f6, 0x528C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X528C);
    // 0x80039C20: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x80039C24: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80039C28: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80039C2C: lhu         $v1, 0x2($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X2);
    // 0x80039C30: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80039C34: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80039C38: swc1        $f8, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f8.u32l;
    // 0x80039C3C: lw          $t2, 0x78A0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X78A0);
    // 0x80039C40: lw          $t1, -0x7D80($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X7D80);
    // 0x80039C44: lwc1        $f4, 0x5290($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5290);
    // 0x80039C48: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80039C4C: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80039C50: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x80039C54: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x80039C58: sll         $t3, $t3, 5
    ctx->r11 = S32(ctx->r11 << 5);
    // 0x80039C5C: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x80039C60: lwc1        $f10, 0x5C($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0X5C);
    // 0x80039C64: mul.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80039C68: div.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80039C6C: swc1        $f6, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f6.u32l;
    // 0x80039C70: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_80039C74:
    // 0x80039C74: beq         $v0, $at, L_80039D70
    if (ctx->r2 == ctx->r1) {
        // 0x80039C78: lui         $at, 0x800D
        ctx->r1 = S32(0X800D << 16);
            goto L_80039D70;
    }
    // 0x80039C78: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80039C7C: lwc1        $f10, 0x5294($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X5294);
    // 0x80039C80: lwc1        $f8, 0x14($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X14);
    // 0x80039C84: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80039C88: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80039C8C: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80039C90: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80039C94: jal         0x80005E90
    // 0x80039C98: nop

    Matrix_RotateY(rdram, ctx);
        goto after_3;
    // 0x80039C98: nop

    after_3:
    // 0x80039C9C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80039CA0: lwc1        $f6, 0x5298($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5298);
    // 0x80039CA4: lwc1        $f4, 0x10($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X10);
    // 0x80039CA8: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80039CAC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80039CB0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80039CB4: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80039CB8: jal         0x80005D44
    // 0x80039CBC: nop

    Matrix_RotateX(rdram, ctx);
        goto after_4;
    // 0x80039CBC: nop

    after_4:
    // 0x80039CC0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80039CC4: lwc1        $f18, 0x529C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X529C);
    // 0x80039CC8: lwc1        $f10, 0x18($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X18);
    // 0x80039CCC: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80039CD0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80039CD4: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80039CD8: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80039CDC: jal         0x80005FE0
    // 0x80039CE0: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_5;
    // 0x80039CE0: nop

    after_5:
    // 0x80039CE4: lhu         $v1, 0x2($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X2);
    // 0x80039CE8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80039CEC: bnel        $v1, $at, L_80039D74
    if (ctx->r3 != ctx->r1) {
        // 0x80039CF0: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_80039D74;
    }
    goto skip_9;
    // 0x80039CF0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_9:
    // 0x80039CF4: lw          $t5, 0x5C($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X5C);
    // 0x80039CF8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80039CFC: bnel        $t5, $zero, L_80039D74
    if (ctx->r13 != 0) {
        // 0x80039D00: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_80039D74;
    }
    goto skip_10;
    // 0x80039D00: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_10:
    // 0x80039D04: lwc1        $f6, 0x34($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X34);
    // 0x80039D08: lwc1        $f8, 0x52A0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X52A0);
    // 0x80039D0C: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80039D10: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80039D14: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80039D18: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80039D1C: jal         0x80005FE0
    // 0x80039D20: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_6;
    // 0x80039D20: nop

    after_6:
    // 0x80039D24: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80039D28: lwc1        $f4, 0x52A4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X52A4);
    // 0x80039D2C: lwc1        $f18, 0x30($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X30);
    // 0x80039D30: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80039D34: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80039D38: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80039D3C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80039D40: jal         0x80005E90
    // 0x80039D44: nop

    Matrix_RotateY(rdram, ctx);
        goto after_7;
    // 0x80039D44: nop

    after_7:
    // 0x80039D48: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80039D4C: lwc1        $f10, 0x52A8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X52A8);
    // 0x80039D50: lwc1        $f8, 0x2C($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X2C);
    // 0x80039D54: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80039D58: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80039D5C: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80039D60: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80039D64: jal         0x80005D44
    // 0x80039D68: nop

    Matrix_RotateX(rdram, ctx);
        goto after_8;
    // 0x80039D68: nop

    after_8:
    // 0x80039D6C: lhu         $v1, 0x2($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X2);
L_80039D70:
    // 0x80039D70: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_80039D74:
    // 0x80039D74: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x80039D78: lui         $a3, 0x800D
    ctx->r7 = S32(0X800D << 16);
    // 0x80039D7C: addu        $a3, $a3, $t9
    ctx->r7 = ADD32(ctx->r7, ctx->r25);
    // 0x80039D80: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80039D84: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80039D88: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80039D8C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80039D90: lw          $a3, -0x6428($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X6428);
    // 0x80039D94: jal         0x80005B00
    // 0x80039D98: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_9;
    // 0x80039D98: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_9:
    // 0x80039D9C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80039DA0: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x80039DA4: jal         0x80006EB8
    // 0x80039DA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_10;
    // 0x80039DA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80039DAC: lhu         $t8, 0x2($s1)
    ctx->r24 = MEM_HU(ctx->r17, 0X2);
    // 0x80039DB0: sltiu       $at, $t8, 0xA
    ctx->r1 = ctx->r24 < 0XA ? 1 : 0;
    // 0x80039DB4: beq         $at, $zero, L_8003AF70
    if (ctx->r1 == 0) {
        // 0x80039DB8: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_8003AF70;
    }
    // 0x80039DB8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80039DBC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80039DC0: addu        $at, $at, $t8
    gpr jr_addend_80039DC8 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80039DC4: lw          $t8, 0x52AC($at)
    ctx->r24 = ADD32(ctx->r1, 0X52AC);
    // 0x80039DC8: jr          $t8
    // 0x80039DCC: nop

    switch (jr_addend_80039DC8 >> 2) {
        case 0: goto L_80039DD0; break;
        case 1: goto L_80039DD0; break;
        case 2: goto L_8003AF70; break;
        case 3: goto L_80039DE0; break;
        case 4: goto L_8003AF70; break;
        case 5: goto L_8003A28C; break;
        case 6: goto L_8003A698; break;
        case 7: goto L_8003A698; break;
        case 8: goto L_8003A85C; break;
        case 9: goto L_8003AF00; break;
        default: switch_error(__func__, 0x80039DC8, 0x800D52AC);
    }
    // 0x80039DCC: nop

L_80039DD0:
    // 0x80039DD0: jal         0x80039210
    // 0x80039DD4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    PlayerShot_DrawLaser(rdram, ctx);
        goto after_11;
    // 0x80039DD4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_11:
    // 0x80039DD8: b           L_8003AF74
    // 0x80039DDC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8003AF74;
    // 0x80039DDC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80039DE0:
    // 0x80039DE0: lw          $t7, 0x5C($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X5C);
    // 0x80039DE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80039DE8: bnel        $t7, $zero, L_8003A0D0
    if (ctx->r15 != 0) {
        // 0x80039DEC: lwc1        $f0, 0x44($s1)
        ctx->f0.u32l = MEM_W(ctx->r17, 0X44);
            goto L_8003A0D0;
    }
    goto skip_11;
    // 0x80039DEC: lwc1        $f0, 0x44($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X44);
    skip_11:
    // 0x80039DF0: jal         0x800B8DD0
    // 0x80039DF4: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    RCP_SetupDL(rdram, ctx);
        goto after_12;
    // 0x80039DF4: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    after_12:
    // 0x80039DF8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80039DFC: lui         $t1, 0x102
    ctx->r9 = S32(0X102 << 16);
    // 0x80039E00: addiu       $t1, $t1, 0x31A0
    ctx->r9 = ADD32(ctx->r9, 0X31A0);
    // 0x80039E04: addiu       $t0, $v0, 0x8
    ctx->r8 = ADD32(ctx->r2, 0X8);
    // 0x80039E08: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x80039E0C: lui         $t2, 0x600
    ctx->r10 = S32(0X600 << 16);
    // 0x80039E10: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x80039E14: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x80039E18: jal         0x80005740
    // 0x80039E1C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_13;
    // 0x80039E1C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_13:
    // 0x80039E20: jal         0x80005708
    // 0x80039E24: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Push(rdram, ctx);
        goto after_14;
    // 0x80039E24: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_14:
    // 0x80039E28: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80039E2C: lwc1        $f6, 0x7D20($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x80039E30: lwc1        $f4, 0xC($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80039E34: lw          $a1, 0x4($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X4);
    // 0x80039E38: lw          $a2, 0x8($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X8);
    // 0x80039E3C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80039E40: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80039E44: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80039E48: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80039E4C: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x80039E50: jal         0x80005B00
    // 0x80039E54: nop

    Matrix_Translate(rdram, ctx);
        goto after_15;
    // 0x80039E54: nop

    after_15:
    // 0x80039E58: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x80039E5C: lw          $t5, 0x78A0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X78A0);
    // 0x80039E60: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80039E64: lw          $t4, -0x7D80($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7D80);
    // 0x80039E68: sll         $t9, $t5, 2
    ctx->r25 = S32(ctx->r13 << 2);
    // 0x80039E6C: addu        $t9, $t9, $t5
    ctx->r25 = ADD32(ctx->r25, ctx->r13);
    // 0x80039E70: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x80039E74: subu        $t9, $t9, $t5
    ctx->r25 = SUB32(ctx->r25, ctx->r13);
    // 0x80039E78: sll         $t9, $t9, 5
    ctx->r25 = S32(ctx->r25 << 5);
    // 0x80039E7C: addu        $t6, $t4, $t9
    ctx->r14 = ADD32(ctx->r12, ctx->r25);
    // 0x80039E80: lwc1        $f10, 0x58($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X58);
    // 0x80039E84: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80039E88: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80039E8C: neg.s       $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = -ctx->f10.fl;
    // 0x80039E90: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80039E94: jal         0x80005E90
    // 0x80039E98: nop

    Matrix_RotateY(rdram, ctx);
        goto after_16;
    // 0x80039E98: nop

    after_16:
    // 0x80039E9C: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x80039EA0: lw          $t7, 0x78A0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X78A0);
    // 0x80039EA4: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80039EA8: lw          $t8, -0x7D80($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7D80);
    // 0x80039EAC: sll         $t0, $t7, 2
    ctx->r8 = S32(ctx->r15 << 2);
    // 0x80039EB0: addu        $t0, $t0, $t7
    ctx->r8 = ADD32(ctx->r8, ctx->r15);
    // 0x80039EB4: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x80039EB8: subu        $t0, $t0, $t7
    ctx->r8 = SUB32(ctx->r8, ctx->r15);
    // 0x80039EBC: sll         $t0, $t0, 5
    ctx->r8 = S32(ctx->r8 << 5);
    // 0x80039EC0: addu        $t2, $t8, $t0
    ctx->r10 = ADD32(ctx->r24, ctx->r8);
    // 0x80039EC4: lw          $a1, 0x5C($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X5C);
    // 0x80039EC8: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80039ECC: jal         0x80005D44
    // 0x80039ED0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateX(rdram, ctx);
        goto after_17;
    // 0x80039ED0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_17:
    // 0x80039ED4: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x80039ED8: lw          $t1, 0x7DB0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7DB0);
    // 0x80039EDC: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80039EE0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80039EE4: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x80039EE8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80039EEC: lwc1        $f18, 0x52D4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X52D4);
    // 0x80039EF0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80039EF4: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80039EF8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80039EFC: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80039F00: nop

    // 0x80039F04: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80039F08: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80039F0C: jal         0x80005FE0
    // 0x80039F10: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_18;
    // 0x80039F10: nop

    after_18:
    // 0x80039F14: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x80039F18: lw          $t3, 0x7DB0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7DB0);
    // 0x80039F1C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80039F20: andi        $t5, $t3, 0x1
    ctx->r13 = ctx->r11 & 0X1;
    // 0x80039F24: bne         $t5, $zero, L_80039F58
    if (ctx->r13 != 0) {
        // 0x80039F28: nop
    
            goto L_80039F58;
    }
    // 0x80039F28: nop

    // 0x80039F2C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80039F30: lwc1        $f0, 0x52D8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X52D8);
    // 0x80039F34: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80039F38: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80039F3C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80039F40: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80039F44: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80039F48: jal         0x80005C34
    // 0x80039F4C: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_19;
    // 0x80039F4C: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_19:
    // 0x80039F50: b           L_80039F7C
    // 0x80039F54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80039F7C;
    // 0x80039F54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80039F58:
    // 0x80039F58: lwc1        $f0, 0x52DC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X52DC);
    // 0x80039F5C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80039F60: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80039F64: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80039F68: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80039F6C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80039F70: jal         0x80005C34
    // 0x80039F74: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_20;
    // 0x80039F74: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_20:
    // 0x80039F78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80039F7C:
    // 0x80039F7C: jal         0x800B8DD0
    // 0x80039F80: addiu       $a1, $zero, 0x31
    ctx->r5 = ADD32(0, 0X31);
    RCP_SetupDL(rdram, ctx);
        goto after_21;
    // 0x80039F80: addiu       $a1, $zero, 0x31
    ctx->r5 = ADD32(0, 0X31);
    after_21:
    // 0x80039F84: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80039F88: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x80039F8C: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80039F90: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80039F94: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80039F98: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80039F9C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80039FA0: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x80039FA4: lw          $t0, 0x78E8($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X78E8);
    // 0x80039FA8: lui         $t5, 0xFB00
    ctx->r13 = S32(0XFB00 << 16);
    // 0x80039FAC: beql        $t0, $zero, L_8003A084
    if (ctx->r8 == 0) {
        // 0x80039FB0: lw          $v0, 0x0($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X0);
            goto L_8003A084;
    }
    goto skip_12;
    // 0x80039FB0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    skip_12:
    // 0x80039FB4: lw          $v1, 0x68($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X68);
    // 0x80039FB8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80039FBC: lui         $t1, 0xFB00
    ctx->r9 = S32(0XFB00 << 16);
    // 0x80039FC0: beql        $v1, $zero, L_80039FF4
    if (ctx->r3 == 0) {
        // 0x80039FC4: lw          $v0, 0x0($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X0);
            goto L_80039FF4;
    }
    goto skip_13;
    // 0x80039FC4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    skip_13:
    // 0x80039FC8: beq         $v1, $at, L_8003A014
    if (ctx->r3 == ctx->r1) {
        // 0x80039FCC: lui         $t4, 0xFB00
        ctx->r12 = S32(0XFB00 << 16);
            goto L_8003A014;
    }
    // 0x80039FCC: lui         $t4, 0xFB00
    ctx->r12 = S32(0XFB00 << 16);
    // 0x80039FD0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80039FD4: beq         $v1, $at, L_8003A038
    if (ctx->r3 == ctx->r1) {
        // 0x80039FD8: lui         $t7, 0xFB00
        ctx->r15 = S32(0XFB00 << 16);
            goto L_8003A038;
    }
    // 0x80039FD8: lui         $t7, 0xFB00
    ctx->r15 = S32(0XFB00 << 16);
    // 0x80039FDC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80039FE0: beq         $v1, $at, L_8003A05C
    if (ctx->r3 == ctx->r1) {
        // 0x80039FE4: lui         $t2, 0xFB00
        ctx->r10 = S32(0XFB00 << 16);
            goto L_8003A05C;
    }
    // 0x80039FE4: lui         $t2, 0xFB00
    ctx->r10 = S32(0XFB00 << 16);
    // 0x80039FE8: b           L_8003A09C
    // 0x80039FEC: nop

        goto L_8003A09C;
    // 0x80039FEC: nop

    // 0x80039FF0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_80039FF4:
    // 0x80039FF4: lui         $t3, 0xFFFF
    ctx->r11 = S32(0XFFFF << 16);
    // 0x80039FF8: ori         $t3, $t3, 0x2080
    ctx->r11 = ctx->r11 | 0X2080;
    // 0x80039FFC: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x8003A000: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x8003A004: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x8003A008: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x8003A00C: b           L_8003A09C
    // 0x8003A010: nop

        goto L_8003A09C;
    // 0x8003A010: nop

L_8003A014:
    // 0x8003A014: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8003A018: lui         $t9, 0xFF20
    ctx->r25 = S32(0XFF20 << 16);
    // 0x8003A01C: ori         $t9, $t9, 0x2080
    ctx->r25 = ctx->r25 | 0X2080;
    // 0x8003A020: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x8003A024: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x8003A028: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8003A02C: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8003A030: b           L_8003A09C
    // 0x8003A034: nop

        goto L_8003A09C;
    // 0x8003A034: nop

L_8003A038:
    // 0x8003A038: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8003A03C: lui         $t8, 0x20FF
    ctx->r24 = S32(0X20FF << 16);
    // 0x8003A040: ori         $t8, $t8, 0x2080
    ctx->r24 = ctx->r24 | 0X2080;
    // 0x8003A044: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8003A048: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8003A04C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8003A050: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8003A054: b           L_8003A09C
    // 0x8003A058: nop

        goto L_8003A09C;
    // 0x8003A058: nop

L_8003A05C:
    // 0x8003A05C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8003A060: lui         $t1, 0x2020
    ctx->r9 = S32(0X2020 << 16);
    // 0x8003A064: ori         $t1, $t1, 0xFF80
    ctx->r9 = ctx->r9 | 0XFF80;
    // 0x8003A068: addiu       $t0, $v0, 0x8
    ctx->r8 = ADD32(ctx->r2, 0X8);
    // 0x8003A06C: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x8003A070: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x8003A074: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x8003A078: b           L_8003A09C
    // 0x8003A07C: nop

        goto L_8003A09C;
    // 0x8003A07C: nop

    // 0x8003A080: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_8003A084:
    // 0x8003A084: lui         $t4, 0x80
    ctx->r12 = S32(0X80 << 16);
    // 0x8003A088: ori         $t4, $t4, 0xFFFF
    ctx->r12 = ctx->r12 | 0XFFFF;
    // 0x8003A08C: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x8003A090: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x8003A094: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x8003A098: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
L_8003A09C:
    // 0x8003A09C: jal         0x80006EB8
    // 0x8003A0A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_22;
    // 0x8003A0A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x8003A0A4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8003A0A8: lui         $t7, 0x102
    ctx->r15 = S32(0X102 << 16);
    // 0x8003A0AC: addiu       $t7, $t7, 0x4AC0
    ctx->r15 = ADD32(ctx->r15, 0X4AC0);
    // 0x8003A0B0: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8003A0B4: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x8003A0B8: lui         $t6, 0x600
    ctx->r14 = S32(0X600 << 16);
    // 0x8003A0BC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8003A0C0: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8003A0C4: b           L_8003AF74
    // 0x8003A0C8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8003AF74;
    // 0x8003A0C8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8003A0CC: lwc1        $f0, 0x44($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X44);
L_8003A0D0:
    // 0x8003A0D0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8003A0D4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8003A0D8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8003A0DC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8003A0E0: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8003A0E4: jal         0x80005C34
    // 0x8003A0E8: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_23;
    // 0x8003A0E8: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_23:
    // 0x8003A0EC: jal         0x80006EB8
    // 0x8003A0F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_24;
    // 0x8003A0F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x8003A0F4: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x8003A0F8: lw          $t0, 0x78E8($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X78E8);
    // 0x8003A0FC: beq         $t0, $zero, L_8003A234
    if (ctx->r8 == 0) {
        // 0x8003A100: nop
    
            goto L_8003A234;
    }
    // 0x8003A100: nop

    // 0x8003A104: jal         0x800BA5B0
    // 0x8003A108: nop

    RCP_SetupDL_49(rdram, ctx);
        goto after_25;
    // 0x8003A108: nop

    after_25:
    // 0x8003A10C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8003A110: lui         $t1, 0xFA00
    ctx->r9 = S32(0XFA00 << 16);
    // 0x8003A114: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x8003A118: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x8003A11C: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x8003A120: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x8003A124: lw          $t3, 0x58($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X58);
    // 0x8003A128: andi        $t5, $t3, 0xFF
    ctx->r13 = ctx->r11 & 0XFF;
    // 0x8003A12C: or          $t4, $t5, $at
    ctx->r12 = ctx->r13 | ctx->r1;
    // 0x8003A130: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x8003A134: lw          $v1, 0x68($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X68);
    // 0x8003A138: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003A13C: beql        $v1, $zero, L_8003A168
    if (ctx->r3 == 0) {
        // 0x8003A140: lw          $v0, 0x0($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X0);
            goto L_8003A168;
    }
    goto skip_14;
    // 0x8003A140: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    skip_14:
    // 0x8003A144: beq         $v1, $at, L_8003A198
    if (ctx->r3 == ctx->r1) {
        // 0x8003A148: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8003A198;
    }
    // 0x8003A148: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8003A14C: beq         $v1, $at, L_8003A1CC
    if (ctx->r3 == ctx->r1) {
        // 0x8003A150: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8003A1CC;
    }
    // 0x8003A150: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8003A154: beql        $v1, $at, L_8003A204
    if (ctx->r3 == ctx->r1) {
        // 0x8003A158: lw          $v0, 0x0($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X0);
            goto L_8003A204;
    }
    goto skip_15;
    // 0x8003A158: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    skip_15:
    // 0x8003A15C: b           L_8003A268
    // 0x8003A160: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
        goto L_8003A268;
    // 0x8003A160: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8003A164: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_8003A168:
    // 0x8003A168: lui         $t6, 0xFB00
    ctx->r14 = S32(0XFB00 << 16);
    // 0x8003A16C: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8003A170: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8003A174: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x8003A178: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8003A17C: lw          $t7, 0x58($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X58);
    // 0x8003A180: ori         $at, $at, 0x2000
    ctx->r1 = ctx->r1 | 0X2000;
    // 0x8003A184: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x8003A188: or          $t0, $t8, $at
    ctx->r8 = ctx->r24 | ctx->r1;
    // 0x8003A18C: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x8003A190: b           L_8003A268
    // 0x8003A194: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
        goto L_8003A268;
    // 0x8003A194: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_8003A198:
    // 0x8003A198: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8003A19C: lui         $t1, 0xFB00
    ctx->r9 = S32(0XFB00 << 16);
    // 0x8003A1A0: lui         $at, 0xFF20
    ctx->r1 = S32(0XFF20 << 16);
    // 0x8003A1A4: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x8003A1A8: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x8003A1AC: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x8003A1B0: lw          $t3, 0x58($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X58);
    // 0x8003A1B4: ori         $at, $at, 0x2000
    ctx->r1 = ctx->r1 | 0X2000;
    // 0x8003A1B8: andi        $t5, $t3, 0xFF
    ctx->r13 = ctx->r11 & 0XFF;
    // 0x8003A1BC: or          $t4, $t5, $at
    ctx->r12 = ctx->r13 | ctx->r1;
    // 0x8003A1C0: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x8003A1C4: b           L_8003A268
    // 0x8003A1C8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
        goto L_8003A268;
    // 0x8003A1C8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_8003A1CC:
    // 0x8003A1CC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8003A1D0: lui         $t6, 0xFB00
    ctx->r14 = S32(0XFB00 << 16);
    // 0x8003A1D4: lui         $at, 0x20FF
    ctx->r1 = S32(0X20FF << 16);
    // 0x8003A1D8: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8003A1DC: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x8003A1E0: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8003A1E4: lw          $t7, 0x58($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X58);
    // 0x8003A1E8: ori         $at, $at, 0x2000
    ctx->r1 = ctx->r1 | 0X2000;
    // 0x8003A1EC: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x8003A1F0: or          $t0, $t8, $at
    ctx->r8 = ctx->r24 | ctx->r1;
    // 0x8003A1F4: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x8003A1F8: b           L_8003A268
    // 0x8003A1FC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
        goto L_8003A268;
    // 0x8003A1FC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8003A200: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_8003A204:
    // 0x8003A204: lui         $t1, 0xFB00
    ctx->r9 = S32(0XFB00 << 16);
    // 0x8003A208: lui         $at, 0x2020
    ctx->r1 = S32(0X2020 << 16);
    // 0x8003A20C: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x8003A210: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x8003A214: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x8003A218: lw          $t3, 0x58($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X58);
    // 0x8003A21C: ori         $at, $at, 0xFF00
    ctx->r1 = ctx->r1 | 0XFF00;
    // 0x8003A220: andi        $t5, $t3, 0xFF
    ctx->r13 = ctx->r11 & 0XFF;
    // 0x8003A224: or          $t4, $t5, $at
    ctx->r12 = ctx->r13 | ctx->r1;
    // 0x8003A228: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x8003A22C: b           L_8003A268
    // 0x8003A230: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
        goto L_8003A268;
    // 0x8003A230: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_8003A234:
    // 0x8003A234: jal         0x800BA170
    // 0x8003A238: nop

    RCP_SetupDL_64_2(rdram, ctx);
        goto after_26;
    // 0x8003A238: nop

    after_26:
    // 0x8003A23C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8003A240: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x8003A244: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x8003A248: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8003A24C: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x8003A250: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8003A254: lw          $t7, 0x58($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X58);
    // 0x8003A258: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x8003A25C: or          $t0, $t8, $at
    ctx->r8 = ctx->r24 | ctx->r1;
    // 0x8003A260: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x8003A264: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_8003A268:
    // 0x8003A268: lui         $t3, 0x103
    ctx->r11 = S32(0X103 << 16);
    // 0x8003A26C: addiu       $t3, $t3, 0x1EC0
    ctx->r11 = ADD32(ctx->r11, 0X1EC0);
    // 0x8003A270: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x8003A274: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x8003A278: lui         $t1, 0x600
    ctx->r9 = S32(0X600 << 16);
    // 0x8003A27C: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x8003A280: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x8003A284: b           L_8003AF74
    // 0x8003A288: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8003AF74;
    // 0x8003A288: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8003A28C:
    // 0x8003A28C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8003A290: lui         $t4, 0xB600
    ctx->r12 = S32(0XB600 << 16);
    // 0x8003A294: addiu       $t9, $zero, 0x2000
    ctx->r25 = ADD32(0, 0X2000);
    // 0x8003A298: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x8003A29C: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x8003A2A0: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8003A2A4: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8003A2A8: jal         0x800B99C0
    // 0x8003A2AC: nop

    RCP_SetupDL_40(rdram, ctx);
        goto after_27;
    // 0x8003A2AC: nop

    after_27:
    // 0x8003A2B0: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x8003A2B4: lw          $t6, 0x78E8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X78E8);
    // 0x8003A2B8: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x8003A2BC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003A2C0: beq         $t6, $zero, L_8003A5A4
    if (ctx->r14 == 0) {
        // 0x8003A2C4: nop
    
            goto L_8003A5A4;
    }
    // 0x8003A2C4: nop

    // 0x8003A2C8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8003A2CC: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x8003A2D0: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8003A2D4: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8003A2D8: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x8003A2DC: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x8003A2E0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8003A2E4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8003A2E8: lui         $t1, 0xFB00
    ctx->r9 = S32(0XFB00 << 16);
    // 0x8003A2EC: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x8003A2F0: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x8003A2F4: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x8003A2F8: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x8003A2FC: lw          $v1, 0x68($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X68);
    // 0x8003A300: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x8003A304: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x8003A308: addu        $t9, $t9, $v1
    ctx->r25 = ADD32(ctx->r25, ctx->r3);
    // 0x8003A30C: addu        $t3, $t3, $v1
    ctx->r11 = ADD32(ctx->r11, ctx->r3);
    // 0x8003A310: lbu         $t5, -0x63F8($t3)
    ctx->r13 = MEM_BU(ctx->r11, -0X63F8);
    // 0x8003A314: lbu         $t6, -0x6400($t9)
    ctx->r14 = MEM_BU(ctx->r25, -0X6400);
    // 0x8003A318: addu        $t0, $t0, $v1
    ctx->r8 = ADD32(ctx->r8, ctx->r3);
    // 0x8003A31C: lbu         $t2, -0x63FC($t0)
    ctx->r10 = MEM_BU(ctx->r8, -0X63FC);
    // 0x8003A320: sll         $t4, $t5, 8
    ctx->r12 = S32(ctx->r13 << 8);
    // 0x8003A324: sll         $t7, $t6, 24
    ctx->r15 = S32(ctx->r14 << 24);
    // 0x8003A328: or          $t8, $t4, $t7
    ctx->r24 = ctx->r12 | ctx->r15;
    // 0x8003A32C: sll         $t1, $t2, 16
    ctx->r9 = S32(ctx->r10 << 16);
    // 0x8003A330: or          $t3, $t8, $t1
    ctx->r11 = ctx->r24 | ctx->r9;
    // 0x8003A334: ori         $t5, $t3, 0xFF
    ctx->r13 = ctx->r11 | 0XFF;
    // 0x8003A338: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x8003A33C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003A340: jal         0x800B8DD0
    // 0x8003A344: addiu       $a1, $zero, 0x31
    ctx->r5 = ADD32(0, 0X31);
    RCP_SetupDL(rdram, ctx);
        goto after_28;
    // 0x8003A344: addiu       $a1, $zero, 0x31
    ctx->r5 = ADD32(0, 0X31);
    after_28:
    // 0x8003A348: lw          $t9, 0x68($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X68);
    // 0x8003A34C: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x8003A350: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x8003A354: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x8003A358: addu        $t4, $t4, $t6
    ctx->r12 = ADD32(ctx->r12, ctx->r14);
    // 0x8003A35C: lw          $t4, 0x1AA8($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X1AA8);
    // 0x8003A360: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x8003A364: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003A368: beq         $t4, $zero, L_8003A50C
    if (ctx->r12 == 0) {
        // 0x8003A36C: nop
    
            goto L_8003A50C;
    }
    // 0x8003A36C: nop

    // 0x8003A370: lw          $t7, 0x7DB0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7DB0);
    // 0x8003A374: lui         $at, 0x4240
    ctx->r1 = S32(0X4240 << 16);
    // 0x8003A378: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8003A37C: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x8003A380: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8003A384: lwc1        $f4, 0x52E0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X52E0);
    // 0x8003A388: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8003A38C: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8003A390: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003A394: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8003A398: nop

    // 0x8003A39C: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8003A3A0: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8003A3A4: jal         0x80005FE0
    // 0x8003A3A8: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_29;
    // 0x8003A3A8: nop

    after_29:
    // 0x8003A3AC: jal         0x80005708
    // 0x8003A3B0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Push(rdram, ctx);
        goto after_30;
    // 0x8003A3B0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_30:
    // 0x8003A3B4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8003A3B8: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8003A3BC: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8003A3C0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8003A3C4: lui         $a2, 0x4248
    ctx->r6 = S32(0X4248 << 16);
    // 0x8003A3C8: jal         0x80005B00
    // 0x8003A3CC: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_31;
    // 0x8003A3CC: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_31:
    // 0x8003A3D0: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x8003A3D4: lw          $t2, 0x7DB0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7DB0);
    // 0x8003A3D8: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x8003A3DC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8003A3E0: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x8003A3E4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8003A3E8: lwc1        $f6, 0x52E4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X52E4);
    // 0x8003A3EC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8003A3F0: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8003A3F4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003A3F8: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8003A3FC: nop

    // 0x8003A400: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8003A404: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8003A408: jal         0x80005FE0
    // 0x8003A40C: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_32;
    // 0x8003A40C: nop

    after_32:
    // 0x8003A410: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8003A414: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8003A418: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8003A41C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8003A420: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8003A424: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8003A428: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8003A42C: jal         0x80005C34
    // 0x8003A430: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_33;
    // 0x8003A430: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_33:
    // 0x8003A434: jal         0x80006EB8
    // 0x8003A438: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_34;
    // 0x8003A438: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_34:
    // 0x8003A43C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8003A440: lui         $s1, 0x302
    ctx->r17 = S32(0X302 << 16);
    // 0x8003A444: addiu       $s1, $s1, -0x52A0
    ctx->r17 = ADD32(ctx->r17, -0X52A0);
    // 0x8003A448: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x8003A44C: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x8003A450: lui         $t3, 0x600
    ctx->r11 = S32(0X600 << 16);
    // 0x8003A454: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8003A458: sw          $s1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r17;
    // 0x8003A45C: jal         0x80005740
    // 0x8003A460: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_35;
    // 0x8003A460: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_35:
    // 0x8003A464: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8003A468: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8003A46C: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8003A470: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8003A474: lui         $a2, 0xC248
    ctx->r6 = S32(0XC248 << 16);
    // 0x8003A478: jal         0x80005B00
    // 0x8003A47C: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_36;
    // 0x8003A47C: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_36:
    // 0x8003A480: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x8003A484: lw          $t9, 0x7DB0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7DB0);
    // 0x8003A488: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x8003A48C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8003A490: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x8003A494: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8003A498: lwc1        $f8, 0x52E8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X52E8);
    // 0x8003A49C: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8003A4A0: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8003A4A4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003A4A8: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8003A4AC: nop

    // 0x8003A4B0: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8003A4B4: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8003A4B8: jal         0x80005FE0
    // 0x8003A4BC: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_37;
    // 0x8003A4BC: nop

    after_37:
    // 0x8003A4C0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8003A4C4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8003A4C8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8003A4CC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8003A4D0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8003A4D4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8003A4D8: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8003A4DC: jal         0x80005C34
    // 0x8003A4E0: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_38;
    // 0x8003A4E0: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_38:
    // 0x8003A4E4: jal         0x80006EB8
    // 0x8003A4E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_39;
    // 0x8003A4E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_39:
    // 0x8003A4EC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8003A4F0: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x8003A4F4: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x8003A4F8: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x8003A4FC: sw          $s1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r17;
    // 0x8003A500: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8003A504: b           L_8003AF74
    // 0x8003A508: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8003AF74;
    // 0x8003A508: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8003A50C:
    // 0x8003A50C: lw          $t0, 0x7DB0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7DB0);
    // 0x8003A510: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8003A514: andi        $t2, $t0, 0x1
    ctx->r10 = ctx->r8 & 0X1;
    // 0x8003A518: bnel        $t2, $zero, L_8003A52C
    if (ctx->r10 != 0) {
        // 0x8003A51C: mtc1        $zero, $f2
        ctx->f2.u32l = 0;
            goto L_8003A52C;
    }
    goto skip_16;
    // 0x8003A51C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    skip_16:
    // 0x8003A520: b           L_8003A530
    // 0x8003A524: lwc1        $f2, 0x52EC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X52EC);
        goto L_8003A530;
    // 0x8003A524: lwc1        $f2, 0x52EC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X52EC);
    // 0x8003A528: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
L_8003A52C:
    // 0x8003A52C: nop

L_8003A530:
    // 0x8003A530: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x8003A534: jal         0x80005E90
    // 0x8003A538: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    Matrix_RotateY(rdram, ctx);
        goto after_40;
    // 0x8003A538: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_40:
    // 0x8003A53C: lui         $a1, 0x3F06
    ctx->r5 = S32(0X3F06 << 16);
    // 0x8003A540: ori         $a1, $a1, 0xA92
    ctx->r5 = ctx->r5 | 0XA92;
    // 0x8003A544: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8003A548: jal         0x80005FE0
    // 0x8003A54C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateZ(rdram, ctx);
        goto after_41;
    // 0x8003A54C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_41:
    // 0x8003A550: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8003A554: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8003A558: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8003A55C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8003A560: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8003A564: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8003A568: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8003A56C: jal         0x80005C34
    // 0x8003A570: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_42;
    // 0x8003A570: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_42:
    // 0x8003A574: jal         0x80006EB8
    // 0x8003A578: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_43;
    // 0x8003A578: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_43:
    // 0x8003A57C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8003A580: lui         $t5, 0x302
    ctx->r13 = S32(0X302 << 16);
    // 0x8003A584: addiu       $t5, $t5, -0x52A0
    ctx->r13 = ADD32(ctx->r13, -0X52A0);
    // 0x8003A588: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x8003A58C: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x8003A590: lui         $t3, 0x600
    ctx->r11 = S32(0X600 << 16);
    // 0x8003A594: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8003A598: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x8003A59C: b           L_8003AF74
    // 0x8003A5A0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8003AF74;
    // 0x8003A5A0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8003A5A4:
    // 0x8003A5A4: lw          $t9, 0x7DB0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7DB0);
    // 0x8003A5A8: andi        $t6, $t9, 0x1
    ctx->r14 = ctx->r25 & 0X1;
    // 0x8003A5AC: bne         $t6, $zero, L_8003A5BC
    if (ctx->r14 != 0) {
        // 0x8003A5B0: lui         $at, 0x800D
        ctx->r1 = S32(0X800D << 16);
            goto L_8003A5BC;
    }
    // 0x8003A5B0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8003A5B4: b           L_8003A5C4
    // 0x8003A5B8: lwc1        $f2, 0x52F0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X52F0);
        goto L_8003A5C4;
    // 0x8003A5B8: lwc1        $f2, 0x52F0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X52F0);
L_8003A5BC:
    // 0x8003A5BC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8003A5C0: nop

L_8003A5C4:
    // 0x8003A5C4: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x8003A5C8: jal         0x80005E90
    // 0x8003A5CC: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    Matrix_RotateY(rdram, ctx);
        goto after_44;
    // 0x8003A5CC: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_44:
    // 0x8003A5D0: lui         $a1, 0x3F06
    ctx->r5 = S32(0X3F06 << 16);
    // 0x8003A5D4: ori         $a1, $a1, 0xA92
    ctx->r5 = ctx->r5 | 0XA92;
    // 0x8003A5D8: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8003A5DC: jal         0x80005FE0
    // 0x8003A5E0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateZ(rdram, ctx);
        goto after_45;
    // 0x8003A5E0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_45:
    // 0x8003A5E4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8003A5E8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8003A5EC: lui         $a2, 0x3F26
    ctx->r6 = S32(0X3F26 << 16);
    // 0x8003A5F0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8003A5F4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8003A5F8: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8003A5FC: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8003A600: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x8003A604: jal         0x80005C34
    // 0x8003A608: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_46;
    // 0x8003A608: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_46:
    // 0x8003A60C: jal         0x80006EB8
    // 0x8003A610: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_47;
    // 0x8003A610: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_47:
    // 0x8003A614: jal         0x800BA580
    // 0x8003A618: nop

    RCP_SetupDL_68(rdram, ctx);
        goto after_48;
    // 0x8003A618: nop

    after_48:
    // 0x8003A61C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8003A620: lui         $t0, 0xFA00
    ctx->r8 = S32(0XFA00 << 16);
    // 0x8003A624: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x8003A628: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8003A62C: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x8003A630: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x8003A634: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x8003A638: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8003A63C: lui         $t1, 0xFB00
    ctx->r9 = S32(0XFB00 << 16);
    // 0x8003A640: lui         $t3, 0xFF
    ctx->r11 = S32(0XFF << 16);
    // 0x8003A644: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8003A648: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8003A64C: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x8003A650: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x8003A654: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8003A658: lui         $t9, 0xB600
    ctx->r25 = S32(0XB600 << 16);
    // 0x8003A65C: addiu       $t6, $zero, 0x2000
    ctx->r14 = ADD32(0, 0X2000);
    // 0x8003A660: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x8003A664: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x8003A668: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8003A66C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8003A670: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8003A674: lui         $t0, 0x300
    ctx->r8 = S32(0X300 << 16);
    // 0x8003A678: addiu       $t0, $t0, 0x6940
    ctx->r8 = ADD32(ctx->r8, 0X6940);
    // 0x8003A67C: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x8003A680: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x8003A684: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x8003A688: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8003A68C: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x8003A690: b           L_8003AF74
    // 0x8003A694: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8003AF74;
    // 0x8003A694: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8003A698:
    // 0x8003A698: lwc1        $f0, 0x44($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X44);
    // 0x8003A69C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8003A6A0: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8003A6A4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8003A6A8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8003A6AC: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8003A6B0: jal         0x80005C34
    // 0x8003A6B4: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_49;
    // 0x8003A6B4: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_49:
    // 0x8003A6B8: jal         0x80006EB8
    // 0x8003A6BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_50;
    // 0x8003A6BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_50:
    // 0x8003A6C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003A6C4: jal         0x800B8DD0
    // 0x8003A6C8: addiu       $a1, $zero, 0x31
    ctx->r5 = ADD32(0, 0X31);
    RCP_SetupDL(rdram, ctx);
        goto after_51;
    // 0x8003A6C8: addiu       $a1, $zero, 0x31
    ctx->r5 = ADD32(0, 0X31);
    after_51:
    // 0x8003A6CC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8003A6D0: lui         $t1, 0xFA00
    ctx->r9 = S32(0XFA00 << 16);
    // 0x8003A6D4: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x8003A6D8: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8003A6DC: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8003A6E0: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x8003A6E4: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x8003A6E8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8003A6EC: lui         $t9, 0xFB00
    ctx->r25 = S32(0XFB00 << 16);
    // 0x8003A6F0: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8003A6F4: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x8003A6F8: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x8003A6FC: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8003A700: lw          $v1, 0x68($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X68);
    // 0x8003A704: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x8003A708: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x8003A70C: addu        $t0, $t0, $v1
    ctx->r8 = ADD32(ctx->r8, ctx->r3);
    // 0x8003A710: addu        $t6, $t6, $v1
    ctx->r14 = ADD32(ctx->r14, ctx->r3);
    // 0x8003A714: lbu         $t4, -0x63F8($t6)
    ctx->r12 = MEM_BU(ctx->r14, -0X63F8);
    // 0x8003A718: lbu         $t2, -0x6400($t0)
    ctx->r10 = MEM_BU(ctx->r8, -0X6400);
    // 0x8003A71C: addu        $t3, $t3, $v1
    ctx->r11 = ADD32(ctx->r11, ctx->r3);
    // 0x8003A720: lbu         $t5, -0x63FC($t3)
    ctx->r13 = MEM_BU(ctx->r11, -0X63FC);
    // 0x8003A724: sll         $t7, $t4, 8
    ctx->r15 = S32(ctx->r12 << 8);
    // 0x8003A728: sll         $t8, $t2, 24
    ctx->r24 = S32(ctx->r10 << 24);
    // 0x8003A72C: or          $t1, $t7, $t8
    ctx->r9 = ctx->r15 | ctx->r24;
    // 0x8003A730: sll         $t9, $t5, 16
    ctx->r25 = S32(ctx->r13 << 16);
    // 0x8003A734: or          $t6, $t1, $t9
    ctx->r14 = ctx->r9 | ctx->r25;
    // 0x8003A738: ori         $t4, $t6, 0xFF
    ctx->r12 = ctx->r14 | 0XFF;
    // 0x8003A73C: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x8003A740: lw          $t0, 0x68($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X68);
    // 0x8003A744: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x8003A748: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x8003A74C: sll         $t2, $t0, 2
    ctx->r10 = S32(ctx->r8 << 2);
    // 0x8003A750: addu        $t7, $t7, $t2
    ctx->r15 = ADD32(ctx->r15, ctx->r10);
    // 0x8003A754: lw          $t7, 0x1AA8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1AA8);
    // 0x8003A758: lui         $t2, 0x600
    ctx->r10 = S32(0X600 << 16);
    // 0x8003A75C: beql        $t7, $zero, L_8003A83C
    if (ctx->r15 == 0) {
        // 0x8003A760: lw          $v0, 0x0($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X0);
            goto L_8003A83C;
    }
    goto skip_17;
    // 0x8003A760: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    skip_17:
    // 0x8003A764: lw          $t8, 0x7DB0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7DB0);
    // 0x8003A768: lui         $at, 0x4240
    ctx->r1 = S32(0X4240 << 16);
    // 0x8003A76C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003A770: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x8003A774: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8003A778: lwc1        $f10, 0x52F4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X52F4);
    // 0x8003A77C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8003A780: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8003A784: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003A788: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8003A78C: nop

    // 0x8003A790: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8003A794: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8003A798: jal         0x80005FE0
    // 0x8003A79C: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_52;
    // 0x8003A79C: nop

    after_52:
    // 0x8003A7A0: jal         0x80005708
    // 0x8003A7A4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Push(rdram, ctx);
        goto after_53;
    // 0x8003A7A4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_53:
    // 0x8003A7A8: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8003A7AC: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8003A7B0: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8003A7B4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8003A7B8: lui         $a2, 0x4220
    ctx->r6 = S32(0X4220 << 16);
    // 0x8003A7BC: jal         0x80005B00
    // 0x8003A7C0: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_54;
    // 0x8003A7C0: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_54:
    // 0x8003A7C4: jal         0x80006EB8
    // 0x8003A7C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_55;
    // 0x8003A7C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_55:
    // 0x8003A7CC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8003A7D0: lui         $s1, 0x302
    ctx->r17 = S32(0X302 << 16);
    // 0x8003A7D4: addiu       $s1, $s1, -0x5110
    ctx->r17 = ADD32(ctx->r17, -0X5110);
    // 0x8003A7D8: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x8003A7DC: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x8003A7E0: lui         $t1, 0x600
    ctx->r9 = S32(0X600 << 16);
    // 0x8003A7E4: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x8003A7E8: sw          $s1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r17;
    // 0x8003A7EC: jal         0x80005740
    // 0x8003A7F0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_56;
    // 0x8003A7F0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_56:
    // 0x8003A7F4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8003A7F8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8003A7FC: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8003A800: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8003A804: lui         $a2, 0xC220
    ctx->r6 = S32(0XC220 << 16);
    // 0x8003A808: jal         0x80005B00
    // 0x8003A80C: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_57;
    // 0x8003A80C: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_57:
    // 0x8003A810: jal         0x80006EB8
    // 0x8003A814: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_58;
    // 0x8003A814: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_58:
    // 0x8003A818: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8003A81C: lui         $t4, 0x600
    ctx->r12 = S32(0X600 << 16);
    // 0x8003A820: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8003A824: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8003A828: sw          $s1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r17;
    // 0x8003A82C: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8003A830: b           L_8003AF74
    // 0x8003A834: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8003AF74;
    // 0x8003A834: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8003A838: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_8003A83C:
    // 0x8003A83C: lui         $t7, 0x302
    ctx->r15 = S32(0X302 << 16);
    // 0x8003A840: addiu       $t7, $t7, -0x5110
    ctx->r15 = ADD32(ctx->r15, -0X5110);
    // 0x8003A844: addiu       $t0, $v0, 0x8
    ctx->r8 = ADD32(ctx->r2, 0X8);
    // 0x8003A848: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x8003A84C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8003A850: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x8003A854: b           L_8003AF74
    // 0x8003A858: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8003AF74;
    // 0x8003A858: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8003A85C:
    // 0x8003A85C: lui         $a1, 0x4049
    ctx->r5 = S32(0X4049 << 16);
    // 0x8003A860: ori         $a1, $a1, 0xFDB
    ctx->r5 = ctx->r5 | 0XFDB;
    // 0x8003A864: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8003A868: jal         0x80005E90
    // 0x8003A86C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateY(rdram, ctx);
        goto after_59;
    // 0x8003A86C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_59:
    // 0x8003A870: jal         0x80006EB8
    // 0x8003A874: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_60;
    // 0x8003A874: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_60:
    // 0x8003A878: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8003A87C: lw          $t8, -0x7DCC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7DCC);
    // 0x8003A880: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x8003A884: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003A888: bnel        $t8, $at, L_8003A9A8
    if (ctx->r24 != ctx->r1) {
        // 0x8003A88C: lw          $t7, 0x5C($s1)
        ctx->r15 = MEM_W(ctx->r17, 0X5C);
            goto L_8003A9A8;
    }
    goto skip_18;
    // 0x8003A88C: lw          $t7, 0x5C($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X5C);
    skip_18:
    // 0x8003A890: jal         0x800B8DD0
    // 0x8003A894: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    RCP_SetupDL(rdram, ctx);
        goto after_61;
    // 0x8003A894: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    after_61:
    // 0x8003A898: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8003A89C: lui         $t1, 0x601
    ctx->r9 = S32(0X601 << 16);
    // 0x8003A8A0: addiu       $t1, $t1, -0x2480
    ctx->r9 = ADD32(ctx->r9, -0X2480);
    // 0x8003A8A4: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x8003A8A8: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x8003A8AC: lui         $t5, 0x600
    ctx->r13 = S32(0X600 << 16);
    // 0x8003A8B0: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8003A8B4: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x8003A8B8: jal         0x80005740
    // 0x8003A8BC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_62;
    // 0x8003A8BC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_62:
    // 0x8003A8C0: jal         0x80005708
    // 0x8003A8C4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Push(rdram, ctx);
        goto after_63;
    // 0x8003A8C4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_63:
    // 0x8003A8C8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8003A8CC: lwc1        $f6, 0x7D20($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x8003A8D0: lwc1        $f4, 0xC($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8003A8D4: lw          $a1, 0x4($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X4);
    // 0x8003A8D8: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x8003A8DC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8003A8E0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8003A8E4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8003A8E8: lw          $a2, 0x7940($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7940);
    // 0x8003A8EC: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x8003A8F0: jal         0x80005B00
    // 0x8003A8F4: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_64;
    // 0x8003A8F4: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_64:
    // 0x8003A8F8: lw          $a1, 0x2C($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X2C);
    // 0x8003A8FC: lw          $a2, 0x30($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X30);
    // 0x8003A900: lw          $a3, 0x34($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X34);
    // 0x8003A904: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8003A908: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8003A90C: jal         0x80005C34
    // 0x8003A910: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_65;
    // 0x8003A910: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_65:
    // 0x8003A914: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003A918: jal         0x800B8DD0
    // 0x8003A91C: addiu       $a1, $zero, 0x31
    ctx->r5 = ADD32(0, 0X31);
    RCP_SetupDL(rdram, ctx);
        goto after_66;
    // 0x8003A91C: addiu       $a1, $zero, 0x31
    ctx->r5 = ADD32(0, 0X31);
    after_66:
    // 0x8003A920: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8003A924: lui         $t0, 0xFA00
    ctx->r8 = S32(0XFA00 << 16);
    // 0x8003A928: lui         $at, 0x2020
    ctx->r1 = S32(0X2020 << 16);
    // 0x8003A92C: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x8003A930: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x8003A934: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x8003A938: lw          $t2, 0x58($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X58);
    // 0x8003A93C: andi        $t7, $t2, 0xFF
    ctx->r15 = ctx->r10 & 0XFF;
    // 0x8003A940: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x8003A944: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8003A948: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8003A94C: lui         $t5, 0xFB00
    ctx->r13 = S32(0XFB00 << 16);
    // 0x8003A950: lui         $at, 0x2010
    ctx->r1 = S32(0X2010 << 16);
    // 0x8003A954: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x8003A958: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x8003A95C: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8003A960: lw          $t1, 0x58($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X58);
    // 0x8003A964: ori         $at, $at, 0x1000
    ctx->r1 = ctx->r1 | 0X1000;
    // 0x8003A968: andi        $t9, $t1, 0xFF
    ctx->r25 = ctx->r9 & 0XFF;
    // 0x8003A96C: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x8003A970: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8003A974: jal         0x80006EB8
    // 0x8003A978: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_67;
    // 0x8003A978: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_67:
    // 0x8003A97C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8003A980: lui         $t2, 0x102
    ctx->r10 = S32(0X102 << 16);
    // 0x8003A984: addiu       $t2, $t2, 0x4AC0
    ctx->r10 = ADD32(ctx->r10, 0X4AC0);
    // 0x8003A988: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x8003A98C: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x8003A990: lui         $t0, 0x600
    ctx->r8 = S32(0X600 << 16);
    // 0x8003A994: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x8003A998: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x8003A99C: b           L_8003AF74
    // 0x8003A9A0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8003AF74;
    // 0x8003A9A0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8003A9A4: lw          $t7, 0x5C($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X5C);
L_8003A9A8:
    // 0x8003A9A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003A9AC: bne         $t7, $zero, L_8003AD3C
    if (ctx->r15 != 0) {
        // 0x8003A9B0: lui         $at, 0x3FC0
        ctx->r1 = S32(0X3FC0 << 16);
            goto L_8003AD3C;
    }
    // 0x8003A9B0: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8003A9B4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8003A9B8: lwc1        $f10, 0x44($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X44);
    // 0x8003A9BC: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x8003A9C0: nop

    // 0x8003A9C4: bc1tl       L_8003AF74
    if (c1cs) {
        // 0x8003A9C8: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8003AF74;
    }
    goto skip_19;
    // 0x8003A9C8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_19:
    // 0x8003A9CC: jal         0x80005740
    // 0x8003A9D0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_68;
    // 0x8003A9D0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_68:
    // 0x8003A9D4: jal         0x80005708
    // 0x8003A9D8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Push(rdram, ctx);
        goto after_69;
    // 0x8003A9D8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_69:
    // 0x8003A9DC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8003A9E0: lwc1        $f4, 0x7D20($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x8003A9E4: lwc1        $f18, 0xC($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8003A9E8: lw          $a1, 0x4($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X4);
    // 0x8003A9EC: lw          $a2, 0x8($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X8);
    // 0x8003A9F0: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8003A9F4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8003A9F8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8003A9FC: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8003AA00: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x8003AA04: jal         0x80005B00
    // 0x8003AA08: nop

    Matrix_Translate(rdram, ctx);
        goto after_70;
    // 0x8003AA08: nop

    after_70:
    // 0x8003AA0C: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x8003AA10: lw          $t5, 0x78A0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X78A0);
    // 0x8003AA14: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8003AA18: lw          $t3, -0x7D80($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X7D80);
    // 0x8003AA1C: sll         $t1, $t5, 2
    ctx->r9 = S32(ctx->r13 << 2);
    // 0x8003AA20: addu        $t1, $t1, $t5
    ctx->r9 = ADD32(ctx->r9, ctx->r13);
    // 0x8003AA24: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x8003AA28: subu        $t1, $t1, $t5
    ctx->r9 = SUB32(ctx->r9, ctx->r13);
    // 0x8003AA2C: sll         $t1, $t1, 5
    ctx->r9 = S32(ctx->r9 << 5);
    // 0x8003AA30: addu        $t9, $t3, $t1
    ctx->r25 = ADD32(ctx->r11, ctx->r9);
    // 0x8003AA34: lwc1        $f8, 0x58($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X58);
    // 0x8003AA38: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8003AA3C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003AA40: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x8003AA44: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8003AA48: jal         0x80005E90
    // 0x8003AA4C: nop

    Matrix_RotateY(rdram, ctx);
        goto after_71;
    // 0x8003AA4C: nop

    after_71:
    // 0x8003AA50: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x8003AA54: lw          $t4, 0x78A0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X78A0);
    // 0x8003AA58: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8003AA5C: lw          $t6, -0x7D80($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7D80);
    // 0x8003AA60: sll         $t0, $t4, 2
    ctx->r8 = S32(ctx->r12 << 2);
    // 0x8003AA64: addu        $t0, $t0, $t4
    ctx->r8 = ADD32(ctx->r8, ctx->r12);
    // 0x8003AA68: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x8003AA6C: subu        $t0, $t0, $t4
    ctx->r8 = SUB32(ctx->r8, ctx->r12);
    // 0x8003AA70: sll         $t0, $t0, 5
    ctx->r8 = S32(ctx->r8 << 5);
    // 0x8003AA74: addu        $t2, $t6, $t0
    ctx->r10 = ADD32(ctx->r14, ctx->r8);
    // 0x8003AA78: lw          $a1, 0x5C($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X5C);
    // 0x8003AA7C: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8003AA80: jal         0x80005D44
    // 0x8003AA84: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateX(rdram, ctx);
        goto after_72;
    // 0x8003AA84: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_72:
    // 0x8003AA88: jal         0x80005708
    // 0x8003AA8C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Push(rdram, ctx);
        goto after_73;
    // 0x8003AA8C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_73:
    // 0x8003AA90: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8003AA94: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8003AA98: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8003AA9C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8003AAA0: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x8003AAA4: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x8003AAA8: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x8003AAAC: jal         0x80005C34
    // 0x8003AAB0: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_74;
    // 0x8003AAB0: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_74:
    // 0x8003AAB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003AAB8: jal         0x800B8DD0
    // 0x8003AABC: addiu       $a1, $zero, 0x31
    ctx->r5 = ADD32(0, 0X31);
    RCP_SetupDL(rdram, ctx);
        goto after_75;
    // 0x8003AABC: addiu       $a1, $zero, 0x31
    ctx->r5 = ADD32(0, 0X31);
    after_75:
    // 0x8003AAC0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8003AAC4: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x8003AAC8: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x8003AACC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8003AAD0: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8003AAD4: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x8003AAD8: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8003AADC: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x8003AAE0: lw          $t1, 0x78E8($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X78E8);
    // 0x8003AAE4: beql        $t1, $zero, L_8003ABBC
    if (ctx->r9 == 0) {
        // 0x8003AAE8: lw          $v0, 0x0($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X0);
            goto L_8003ABBC;
    }
    goto skip_20;
    // 0x8003AAE8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    skip_20:
    // 0x8003AAEC: lw          $v1, 0x68($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X68);
    // 0x8003AAF0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003AAF4: lui         $t4, 0xFB00
    ctx->r12 = S32(0XFB00 << 16);
    // 0x8003AAF8: beql        $v1, $zero, L_8003AB2C
    if (ctx->r3 == 0) {
        // 0x8003AAFC: lw          $v0, 0x0($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X0);
            goto L_8003AB2C;
    }
    goto skip_21;
    // 0x8003AAFC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    skip_21:
    // 0x8003AB00: beq         $v1, $at, L_8003AB4C
    if (ctx->r3 == ctx->r1) {
        // 0x8003AB04: lui         $t2, 0xFB00
        ctx->r10 = S32(0XFB00 << 16);
            goto L_8003AB4C;
    }
    // 0x8003AB04: lui         $t2, 0xFB00
    ctx->r10 = S32(0XFB00 << 16);
    // 0x8003AB08: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8003AB0C: beq         $v1, $at, L_8003AB70
    if (ctx->r3 == ctx->r1) {
        // 0x8003AB10: lui         $t5, 0xFB00
        ctx->r13 = S32(0XFB00 << 16);
            goto L_8003AB70;
    }
    // 0x8003AB10: lui         $t5, 0xFB00
    ctx->r13 = S32(0XFB00 << 16);
    // 0x8003AB14: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8003AB18: beq         $v1, $at, L_8003AB94
    if (ctx->r3 == ctx->r1) {
        // 0x8003AB1C: lui         $t9, 0xFB00
        ctx->r25 = S32(0XFB00 << 16);
            goto L_8003AB94;
    }
    // 0x8003AB1C: lui         $t9, 0xFB00
    ctx->r25 = S32(0XFB00 << 16);
    // 0x8003AB20: b           L_8003ABD8
    // 0x8003AB24: nop

        goto L_8003ABD8;
    // 0x8003AB24: nop

    // 0x8003AB28: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_8003AB2C:
    // 0x8003AB2C: lui         $t6, 0xFFFF
    ctx->r14 = S32(0XFFFF << 16);
    // 0x8003AB30: ori         $t6, $t6, 0x20FF
    ctx->r14 = ctx->r14 | 0X20FF;
    // 0x8003AB34: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8003AB38: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x8003AB3C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8003AB40: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8003AB44: b           L_8003ABD8
    // 0x8003AB48: nop

        goto L_8003ABD8;
    // 0x8003AB48: nop

L_8003AB4C:
    // 0x8003AB4C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8003AB50: lui         $t7, 0xFF20
    ctx->r15 = S32(0XFF20 << 16);
    // 0x8003AB54: ori         $t7, $t7, 0x20FF
    ctx->r15 = ctx->r15 | 0X20FF;
    // 0x8003AB58: addiu       $t0, $v0, 0x8
    ctx->r8 = ADD32(ctx->r2, 0X8);
    // 0x8003AB5C: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x8003AB60: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8003AB64: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x8003AB68: b           L_8003ABD8
    // 0x8003AB6C: nop

        goto L_8003ABD8;
    // 0x8003AB6C: nop

L_8003AB70:
    // 0x8003AB70: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8003AB74: lui         $t3, 0x20FF
    ctx->r11 = S32(0X20FF << 16);
    // 0x8003AB78: ori         $t3, $t3, 0x20FF
    ctx->r11 = ctx->r11 | 0X20FF;
    // 0x8003AB7C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8003AB80: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8003AB84: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x8003AB88: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8003AB8C: b           L_8003ABD8
    // 0x8003AB90: nop

        goto L_8003ABD8;
    // 0x8003AB90: nop

L_8003AB94:
    // 0x8003AB94: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8003AB98: lui         $t4, 0x2020
    ctx->r12 = S32(0X2020 << 16);
    // 0x8003AB9C: ori         $t4, $t4, 0xFFFF
    ctx->r12 = ctx->r12 | 0XFFFF;
    // 0x8003ABA0: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x8003ABA4: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x8003ABA8: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x8003ABAC: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8003ABB0: b           L_8003ABD8
    // 0x8003ABB4: nop

        goto L_8003ABD8;
    // 0x8003ABB4: nop

    // 0x8003ABB8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_8003ABBC:
    // 0x8003ABBC: lui         $t2, 0xFF
    ctx->r10 = S32(0XFF << 16);
    // 0x8003ABC0: ori         $t2, $t2, 0xFF
    ctx->r10 = ctx->r10 | 0XFF;
    // 0x8003ABC4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8003ABC8: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8003ABCC: lui         $t0, 0xFB00
    ctx->r8 = S32(0XFB00 << 16);
    // 0x8003ABD0: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x8003ABD4: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
L_8003ABD8:
    // 0x8003ABD8: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x8003ABDC: lw          $t7, 0x7DB0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7DB0);
    // 0x8003ABE0: lui         $at, 0x4254
    ctx->r1 = S32(0X4254 << 16);
    // 0x8003ABE4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003ABE8: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x8003ABEC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8003ABF0: lwc1        $f10, 0x52F8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X52F8);
    // 0x8003ABF4: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8003ABF8: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8003ABFC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003AC00: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8003AC04: nop

    // 0x8003AC08: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8003AC0C: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8003AC10: jal         0x80005FE0
    // 0x8003AC14: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_76;
    // 0x8003AC14: nop

    after_76:
    // 0x8003AC18: jal         0x80006EB8
    // 0x8003AC1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_77;
    // 0x8003AC1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_77:
    // 0x8003AC20: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8003AC24: lui         $s1, 0x102
    ctx->r17 = S32(0X102 << 16);
    // 0x8003AC28: addiu       $s1, $s1, -0x3D20
    ctx->r17 = ADD32(ctx->r17, -0X3D20);
    // 0x8003AC2C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8003AC30: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8003AC34: lui         $t5, 0x600
    ctx->r13 = S32(0X600 << 16);
    // 0x8003AC38: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8003AC3C: sw          $s1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r17;
    // 0x8003AC40: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x8003AC44: lw          $t3, 0x7DB0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7DB0);
    // 0x8003AC48: lui         $at, 0xC254
    ctx->r1 = S32(0XC254 << 16);
    // 0x8003AC4C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8003AC50: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x8003AC54: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8003AC58: lwc1        $f18, 0x52FC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X52FC);
    // 0x8003AC5C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8003AC60: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8003AC64: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003AC68: mul.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8003AC6C: add.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x8003AC70: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8003AC74: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8003AC78: jal         0x80005FE0
    // 0x8003AC7C: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_78;
    // 0x8003AC7C: nop

    after_78:
    // 0x8003AC80: jal         0x80006EB8
    // 0x8003AC84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_79;
    // 0x8003AC84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_79:
    // 0x8003AC88: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8003AC8C: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x8003AC90: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x8003AC94: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x8003AC98: sw          $s1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r17;
    // 0x8003AC9C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8003ACA0: jal         0x80005740
    // 0x8003ACA4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_80;
    // 0x8003ACA4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_80:
    // 0x8003ACA8: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x8003ACAC: lw          $t4, 0x7DB0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7DB0);
    // 0x8003ACB0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8003ACB4: andi        $t6, $t4, 0x1
    ctx->r14 = ctx->r12 & 0X1;
    // 0x8003ACB8: bne         $t6, $zero, L_8003ACEC
    if (ctx->r14 != 0) {
        // 0x8003ACBC: nop
    
            goto L_8003ACEC;
    }
    // 0x8003ACBC: nop

    // 0x8003ACC0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8003ACC4: lwc1        $f0, 0x5300($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5300);
    // 0x8003ACC8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8003ACCC: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8003ACD0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8003ACD4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8003ACD8: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8003ACDC: jal         0x80005C34
    // 0x8003ACE0: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_81;
    // 0x8003ACE0: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_81:
    // 0x8003ACE4: b           L_8003AD0C
    // 0x8003ACE8: nop

        goto L_8003AD0C;
    // 0x8003ACE8: nop

L_8003ACEC:
    // 0x8003ACEC: lwc1        $f0, 0x5304($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5304);
    // 0x8003ACF0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8003ACF4: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8003ACF8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8003ACFC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8003AD00: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8003AD04: jal         0x80005C34
    // 0x8003AD08: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_82;
    // 0x8003AD08: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_82:
L_8003AD0C:
    // 0x8003AD0C: jal         0x80006EB8
    // 0x8003AD10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_83;
    // 0x8003AD10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_83:
    // 0x8003AD14: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8003AD18: lui         $t5, 0x102
    ctx->r13 = S32(0X102 << 16);
    // 0x8003AD1C: addiu       $t5, $t5, 0x4AC0
    ctx->r13 = ADD32(ctx->r13, 0X4AC0);
    // 0x8003AD20: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8003AD24: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x8003AD28: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x8003AD2C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8003AD30: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x8003AD34: b           L_8003AF74
    // 0x8003AD38: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8003AF74;
    // 0x8003AD38: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8003AD3C:
    // 0x8003AD3C: jal         0x800B8DD0
    // 0x8003AD40: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    RCP_SetupDL(rdram, ctx);
        goto after_84;
    // 0x8003AD40: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    after_84:
    // 0x8003AD44: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8003AD48: lui         $t9, 0x102
    ctx->r25 = S32(0X102 << 16);
    // 0x8003AD4C: addiu       $t9, $t9, 0x31A0
    ctx->r25 = ADD32(ctx->r25, 0X31A0);
    // 0x8003AD50: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x8003AD54: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x8003AD58: lui         $t1, 0x600
    ctx->r9 = S32(0X600 << 16);
    // 0x8003AD5C: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x8003AD60: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8003AD64: jal         0x80005740
    // 0x8003AD68: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_85;
    // 0x8003AD68: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_85:
    // 0x8003AD6C: jal         0x80005708
    // 0x8003AD70: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Push(rdram, ctx);
        goto after_86;
    // 0x8003AD70: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_86:
    // 0x8003AD74: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8003AD78: lwc1        $f8, 0x7D20($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x8003AD7C: lwc1        $f6, 0xC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8003AD80: lw          $a1, 0x4($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X4);
    // 0x8003AD84: lw          $a2, 0x8($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X8);
    // 0x8003AD88: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8003AD8C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8003AD90: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8003AD94: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8003AD98: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x8003AD9C: jal         0x80005B00
    // 0x8003ADA0: nop

    Matrix_Translate(rdram, ctx);
        goto after_87;
    // 0x8003ADA0: nop

    after_87:
    // 0x8003ADA4: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x8003ADA8: lw          $t0, 0x78A0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X78A0);
    // 0x8003ADAC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8003ADB0: lw          $t6, -0x7D80($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7D80);
    // 0x8003ADB4: sll         $t2, $t0, 2
    ctx->r10 = S32(ctx->r8 << 2);
    // 0x8003ADB8: addu        $t2, $t2, $t0
    ctx->r10 = ADD32(ctx->r10, ctx->r8);
    // 0x8003ADBC: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x8003ADC0: subu        $t2, $t2, $t0
    ctx->r10 = SUB32(ctx->r10, ctx->r8);
    // 0x8003ADC4: sll         $t2, $t2, 5
    ctx->r10 = S32(ctx->r10 << 5);
    // 0x8003ADC8: addu        $t7, $t6, $t2
    ctx->r15 = ADD32(ctx->r14, ctx->r10);
    // 0x8003ADCC: lwc1        $f18, 0x58($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0X58);
    // 0x8003ADD0: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8003ADD4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003ADD8: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x8003ADDC: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8003ADE0: jal         0x80005E90
    // 0x8003ADE4: nop

    Matrix_RotateY(rdram, ctx);
        goto after_88;
    // 0x8003ADE4: nop

    after_88:
    // 0x8003ADE8: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x8003ADEC: lw          $t5, 0x78A0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X78A0);
    // 0x8003ADF0: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8003ADF4: lw          $t8, -0x7D80($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7D80);
    // 0x8003ADF8: sll         $t3, $t5, 2
    ctx->r11 = S32(ctx->r13 << 2);
    // 0x8003ADFC: addu        $t3, $t3, $t5
    ctx->r11 = ADD32(ctx->r11, ctx->r13);
    // 0x8003AE00: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x8003AE04: subu        $t3, $t3, $t5
    ctx->r11 = SUB32(ctx->r11, ctx->r13);
    // 0x8003AE08: sll         $t3, $t3, 5
    ctx->r11 = S32(ctx->r11 << 5);
    // 0x8003AE0C: addu        $t1, $t8, $t3
    ctx->r9 = ADD32(ctx->r24, ctx->r11);
    // 0x8003AE10: lw          $a1, 0x5C($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X5C);
    // 0x8003AE14: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8003AE18: jal         0x80005D44
    // 0x8003AE1C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateX(rdram, ctx);
        goto after_89;
    // 0x8003AE1C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_89:
    // 0x8003AE20: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x8003AE24: lw          $t9, 0x7DB0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7DB0);
    // 0x8003AE28: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8003AE2C: andi        $t4, $t9, 0x1
    ctx->r12 = ctx->r25 & 0X1;
    // 0x8003AE30: bnel        $t4, $zero, L_8003AE68
    if (ctx->r12 != 0) {
        // 0x8003AE34: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_8003AE68;
    }
    goto skip_22;
    // 0x8003AE34: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_22:
    // 0x8003AE38: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8003AE3C: lwc1        $f0, 0x5308($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5308);
    // 0x8003AE40: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8003AE44: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8003AE48: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8003AE4C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8003AE50: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8003AE54: jal         0x80005C34
    // 0x8003AE58: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_90;
    // 0x8003AE58: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_90:
    // 0x8003AE5C: b           L_8003AE88
    // 0x8003AE60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8003AE88;
    // 0x8003AE60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003AE64: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_8003AE68:
    // 0x8003AE68: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8003AE6C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8003AE70: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8003AE74: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8003AE78: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8003AE7C: jal         0x80005C34
    // 0x8003AE80: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_91;
    // 0x8003AE80: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_91:
    // 0x8003AE84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8003AE88:
    // 0x8003AE88: jal         0x800B8DD0
    // 0x8003AE8C: addiu       $a1, $zero, 0x31
    ctx->r5 = ADD32(0, 0X31);
    RCP_SetupDL(rdram, ctx);
        goto after_92;
    // 0x8003AE8C: addiu       $a1, $zero, 0x31
    ctx->r5 = ADD32(0, 0X31);
    after_92:
    // 0x8003AE90: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8003AE94: lui         $t5, 0xFFFF
    ctx->r13 = S32(0XFFFF << 16);
    // 0x8003AE98: ori         $t5, $t5, 0xFF
    ctx->r13 = ctx->r13 | 0XFF;
    // 0x8003AE9C: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x8003AEA0: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x8003AEA4: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x8003AEA8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8003AEAC: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x8003AEB0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8003AEB4: lui         $t1, 0xFF80
    ctx->r9 = S32(0XFF80 << 16);
    // 0x8003AEB8: ori         $t1, $t1, 0x80FF
    ctx->r9 = ctx->r9 | 0X80FF;
    // 0x8003AEBC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8003AEC0: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8003AEC4: lui         $t3, 0xFB00
    ctx->r11 = S32(0XFB00 << 16);
    // 0x8003AEC8: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8003AECC: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x8003AED0: jal         0x80006EB8
    // 0x8003AED4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_93;
    // 0x8003AED4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_93:
    // 0x8003AED8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8003AEDC: lui         $t0, 0x102
    ctx->r8 = S32(0X102 << 16);
    // 0x8003AEE0: addiu       $t0, $t0, 0x4AC0
    ctx->r8 = ADD32(ctx->r8, 0X4AC0);
    // 0x8003AEE4: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8003AEE8: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x8003AEEC: lui         $t4, 0x600
    ctx->r12 = S32(0X600 << 16);
    // 0x8003AEF0: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8003AEF4: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x8003AEF8: b           L_8003AF74
    // 0x8003AEFC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8003AF74;
    // 0x8003AEFC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8003AF00:
    // 0x8003AF00: lui         $a1, 0x4049
    ctx->r5 = S32(0X4049 << 16);
    // 0x8003AF04: ori         $a1, $a1, 0xFDB
    ctx->r5 = ctx->r5 | 0XFDB;
    // 0x8003AF08: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8003AF0C: jal         0x80005E90
    // 0x8003AF10: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateY(rdram, ctx);
        goto after_94;
    // 0x8003AF10: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_94:
    // 0x8003AF14: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8003AF18: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8003AF1C: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8003AF20: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8003AF24: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8003AF28: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8003AF2C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8003AF30: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x8003AF34: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8003AF38: jal         0x80005C34
    // 0x8003AF3C: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_95;
    // 0x8003AF3C: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_95:
    // 0x8003AF40: jal         0x80006EB8
    // 0x8003AF44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_96;
    // 0x8003AF44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_96:
    // 0x8003AF48: jal         0x800B99C0
    // 0x8003AF4C: nop

    RCP_SetupDL_40(rdram, ctx);
        goto after_97;
    // 0x8003AF4C: nop

    after_97:
    // 0x8003AF50: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8003AF54: lui         $t5, 0xE01
    ctx->r13 = S32(0XE01 << 16);
    // 0x8003AF58: addiu       $t5, $t5, -0x2050
    ctx->r13 = ADD32(ctx->r13, -0X2050);
    // 0x8003AF5C: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x8003AF60: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x8003AF64: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x8003AF68: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8003AF6C: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
L_8003AF70:
    // 0x8003AF70: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8003AF74:
    // 0x8003AF74: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8003AF78: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8003AF7C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8003AF80: jr          $ra
    // 0x8003AF84: addiu       $sp, $sp, 0x128
    ctx->r29 = ADD32(ctx->r29, 0X128);
    return;
    // 0x8003AF84: addiu       $sp, $sp, 0x128
    ctx->r29 = ADD32(ctx->r29, 0X128);
;}
RECOMP_FUNC void Math_Vec3fFromAngles(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009F6CC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8009F6D0: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x8009F6D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009F6D8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8009F6DC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8009F6E0: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8009F6E4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009F6E8: lwc1        $f4, -0x7DBC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7DBC);
    // 0x8009F6EC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8009F6F0: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8009F6F4: mul.s       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x8009F6F8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8009F6FC: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8009F700: jal         0x80005E90
    // 0x8009F704: nop

    Matrix_RotateY(rdram, ctx);
        goto after_0;
    // 0x8009F704: nop

    after_0:
    // 0x8009F708: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009F70C: lwc1        $f10, -0x7DB8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X7DB8);
    // 0x8009F710: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8009F714: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8009F718: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8009F71C: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8009F720: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8009F724: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8009F728: jal         0x80005D44
    // 0x8009F72C: nop

    Matrix_RotateX(rdram, ctx);
        goto after_1;
    // 0x8009F72C: nop

    after_1:
    // 0x8009F730: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8009F734: lwc1        $f18, 0x34($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8009F738: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8009F73C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8009F740: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x8009F744: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8009F748: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x8009F74C: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x8009F750: jal         0x80006A20
    // 0x8009F754: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_2;
    // 0x8009F754: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    after_2:
    // 0x8009F758: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009F75C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8009F760: jr          $ra
    // 0x8009F764: nop

    return;
    // 0x8009F764: nop

;}
RECOMP_FUNC void Cutscene_CoComplete2_TeamSetup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004A840: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8004A844: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004A848: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8004A84C: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x8004A850: subu        $t6, $t6, $a1
    ctx->r14 = SUB32(ctx->r14, ctx->r5);
    // 0x8004A854: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x8004A858: subu        $t6, $t6, $a1
    ctx->r14 = SUB32(ctx->r14, ctx->r5);
    // 0x8004A85C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8004A860: addu        $t6, $t6, $a1
    ctx->r14 = ADD32(ctx->r14, ctx->r5);
    // 0x8004A864: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x8004A868: addiu       $t7, $t7, 0x3FE0
    ctx->r15 = ADD32(ctx->r15, 0X3FE0);
    // 0x8004A86C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8004A870: jal         0x8004A700
    // 0x8004A874: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    Cutscene_TeamSetup(rdram, ctx);
        goto after_0;
    // 0x8004A874: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    after_0:
    // 0x8004A878: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004A87C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8004A880: jr          $ra
    // 0x8004A884: nop

    return;
    // 0x8004A884: nop

;}
RECOMP_FUNC void TexturedLine_DrawPath(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060D94: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80060D98: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80060D9C: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80060DA0: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80060DA4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80060DA8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80060DAC: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80060DB0: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x80060DB4: addiu       $t7, $t7, 0x4750
    ctx->r15 = ADD32(ctx->r15, 0X4750);
    // 0x80060DB8: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x80060DBC: addu        $s0, $t6, $t7
    ctx->r16 = ADD32(ctx->r14, ctx->r15);
    // 0x80060DC0: lbu         $t8, 0x2F($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X2F);
    // 0x80060DC4: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80060DC8: bne         $t8, $at, L_80060DE8
    if (ctx->r24 != ctx->r1) {
        // 0x80060DCC: lui         $s1, 0x8013
        ctx->r17 = S32(0X8013 << 16);
            goto L_80060DE8;
    }
    // 0x80060DCC: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x80060DD0: addiu       $s1, $s1, 0x7E64
    ctx->r17 = ADD32(ctx->r17, 0X7E64);
    // 0x80060DD4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80060DD8: jal         0x800B8DD0
    // 0x80060DDC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x80060DDC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_0:
    // 0x80060DE0: b           L_80060DFC
    // 0x80060DE4: nop

        goto L_80060DFC;
    // 0x80060DE4: nop

L_80060DE8:
    // 0x80060DE8: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x80060DEC: addiu       $s1, $s1, 0x7E64
    ctx->r17 = ADD32(ctx->r17, 0X7E64);
    // 0x80060DF0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80060DF4: jal         0x800B8DD0
    // 0x80060DF8: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    RCP_SetupDL(rdram, ctx);
        goto after_1;
    // 0x80060DF8: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    after_1:
L_80060DFC:
    // 0x80060DFC: lui         $s2, 0x8014
    ctx->r18 = S32(0X8014 << 16);
    // 0x80060E00: addiu       $s2, $s2, -0x4C40
    ctx->r18 = ADD32(ctx->r18, -0X4C40);
    // 0x80060E04: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80060E08: lui         $t0, 0xFA00
    ctx->r8 = S32(0XFA00 << 16);
    // 0x80060E0C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80060E10: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x80060E14: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x80060E18: lbu         $t5, 0x2D($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X2D);
    // 0x80060E1C: lbu         $t2, 0x2C($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X2C);
    // 0x80060E20: lbu         $t9, 0x2E($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X2E);
    // 0x80060E24: lbu         $t4, 0x2F($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X2F);
    // 0x80060E28: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x80060E2C: sll         $t3, $t2, 24
    ctx->r11 = S32(ctx->r10 << 24);
    // 0x80060E30: or          $t7, $t3, $t6
    ctx->r15 = ctx->r11 | ctx->r14;
    // 0x80060E34: sll         $t0, $t9, 8
    ctx->r8 = S32(ctx->r25 << 8);
    // 0x80060E38: or          $t1, $t7, $t0
    ctx->r9 = ctx->r15 | ctx->r8;
    // 0x80060E3C: or          $t5, $t1, $t4
    ctx->r13 = ctx->r9 | ctx->r12;
    // 0x80060E40: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x80060E44: jal         0x80005708
    // 0x80060E48: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Push(rdram, ctx);
        goto after_2;
    // 0x80060E48: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_2:
    // 0x80060E4C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80060E50: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80060E54: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80060E58: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x80060E5C: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    // 0x80060E60: jal         0x80005B00
    // 0x80060E64: lw          $a3, 0xC($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XC);
    Matrix_Translate(rdram, ctx);
        goto after_3;
    // 0x80060E64: lw          $a3, 0xC($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XC);
    after_3:
    // 0x80060E68: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80060E6C: lw          $a1, 0x20($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X20);
    // 0x80060E70: jal         0x80005E90
    // 0x80060E74: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateY(rdram, ctx);
        goto after_4;
    // 0x80060E74: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
    // 0x80060E78: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80060E7C: lw          $a1, 0x1C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1C);
    // 0x80060E80: jal         0x80005D44
    // 0x80060E84: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateX(rdram, ctx);
        goto after_5;
    // 0x80060E84: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x80060E88: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80060E8C: lw          $a1, 0x1C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1C);
    // 0x80060E90: jal         0x80005FE0
    // 0x80060E94: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateZ(rdram, ctx);
        goto after_6;
    // 0x80060E94: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_6:
    // 0x80060E98: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80060E9C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80060EA0: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80060EA4: lw          $a1, 0x28($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X28);
    // 0x80060EA8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80060EAC: jal         0x80005C34
    // 0x80060EB0: lw          $a3, 0x24($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X24);
    Matrix_Scale(rdram, ctx);
        goto after_7;
    // 0x80060EB0: lw          $a3, 0x24($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X24);
    after_7:
    // 0x80060EB4: jal         0x80006EB8
    // 0x80060EB8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_8;
    // 0x80060EB8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_8:
    // 0x80060EBC: addiu       $a3, $zero, 0x2000
    ctx->r7 = ADD32(0, 0X2000);
    // 0x80060EC0: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80060EC4: lui         $t9, 0xB600
    ctx->r25 = S32(0XB600 << 16);
    // 0x80060EC8: lui         $t0, 0x600
    ctx->r8 = S32(0X600 << 16);
    // 0x80060ECC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80060ED0: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x80060ED4: sw          $a3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r7;
    // 0x80060ED8: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80060EDC: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80060EE0: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x80060EE4: addiu       $t2, $t2, -0x280
    ctx->r10 = ADD32(ctx->r10, -0X280);
    // 0x80060EE8: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80060EEC: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x80060EF0: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x80060EF4: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x80060EF8: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80060EFC: lui         $t4, 0xB700
    ctx->r12 = S32(0XB700 << 16);
    // 0x80060F00: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x80060F04: sw          $t1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r9;
    // 0x80060F08: sw          $a3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r7;
    // 0x80060F0C: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80060F10: jal         0x80005740
    // 0x80060F14: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_9;
    // 0x80060F14: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_9:
    // 0x80060F18: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80060F1C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80060F20: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80060F24: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80060F28: jr          $ra
    // 0x80060F2C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80060F2C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void Effect_FireSmoke3_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007D8A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007D8AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007D8B0: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x8007D8B4: lbu         $t6, 0x7C98($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X7C98);
    // 0x8007D8B8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8007D8BC: bne         $t6, $at, L_8007D8D4
    if (ctx->r14 != ctx->r1) {
        // 0x8007D8C0: nop
    
            goto L_8007D8D4;
    }
    // 0x8007D8C0: nop

    // 0x8007D8C4: jal         0x8007D2F4
    // 0x8007D8C8: nop

    Effect_FireSmoke1_Update(rdram, ctx);
        goto after_0;
    // 0x8007D8C8: nop

    after_0:
    // 0x8007D8CC: b           L_8007D940
    // 0x8007D8D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8007D940;
    // 0x8007D8D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8007D8D4:
    // 0x8007D8D4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007D8D8: lwc1        $f6, 0x7444($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7444);
    // 0x8007D8DC: lwc1        $f4, 0x58($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X58);
    // 0x8007D8E0: lhu         $t7, 0x50($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X50);
    // 0x8007D8E4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8007D8E8: bne         $t7, $zero, L_8007D920
    if (ctx->r15 != 0) {
        // 0x8007D8EC: swc1        $f8, 0x58($a0)
        MEM_W(0X58, ctx->r4) = ctx->f8.u32l;
            goto L_8007D920;
    }
    // 0x8007D8EC: swc1        $f8, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f8.u32l;
    // 0x8007D8F0: lbu         $t8, 0x4C($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X4C);
    // 0x8007D8F4: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x8007D8F8: sh          $t0, 0x50($a0)
    MEM_H(0X50, ctx->r4) = ctx->r8;
    // 0x8007D8FC: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8007D900: andi        $t1, $t9, 0xFF
    ctx->r9 = ctx->r25 & 0XFF;
    // 0x8007D904: slti        $at, $t1, 0x14
    ctx->r1 = SIGNED(ctx->r9) < 0X14 ? 1 : 0;
    // 0x8007D908: bne         $at, $zero, L_8007D920
    if (ctx->r1 != 0) {
        // 0x8007D90C: sb          $t9, 0x4C($a0)
        MEM_B(0X4C, ctx->r4) = ctx->r25;
            goto L_8007D920;
    }
    // 0x8007D90C: sb          $t9, 0x4C($a0)
    MEM_B(0X4C, ctx->r4) = ctx->r25;
    // 0x8007D910: addiu       $a1, $a0, 0x80
    ctx->r5 = ADD32(ctx->r4, 0X80);
    // 0x8007D914: jal         0x80060FBC
    // 0x8007D918: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    Object_Kill(rdram, ctx);
        goto after_1;
    // 0x8007D918: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x8007D91C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_8007D920:
    // 0x8007D920: lbu         $t2, 0x4C($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X4C);
    // 0x8007D924: slti        $at, $t2, 0x10
    ctx->r1 = SIGNED(ctx->r10) < 0X10 ? 1 : 0;
    // 0x8007D928: bnel        $at, $zero, L_8007D940
    if (ctx->r1 != 0) {
        // 0x8007D92C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8007D940;
    }
    goto skip_0;
    // 0x8007D92C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8007D930: lh          $t3, 0x44($a0)
    ctx->r11 = MEM_H(ctx->r4, 0X44);
    // 0x8007D934: addiu       $t4, $t3, -0x14
    ctx->r12 = ADD32(ctx->r11, -0X14);
    // 0x8007D938: sh          $t4, 0x44($a0)
    MEM_H(0X44, ctx->r4) = ctx->r12;
    // 0x8007D93C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8007D940:
    // 0x8007D940: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007D944: jr          $ra
    // 0x8007D948: nop

    return;
    // 0x8007D948: nop

;}
RECOMP_FUNC void FoBase_BurnEffects(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008FFF0: addiu       $sp, $sp, -0x118
    ctx->r29 = ADD32(ctx->r29, -0X118);
    // 0x8008FFF4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8008FFF8: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x8008FFFC: addiu       $t7, $t7, 0x21C8
    ctx->r15 = ADD32(ctx->r15, 0X21C8);
    // 0x80090000: addiu       $t0, $t7, 0xD8
    ctx->r8 = ADD32(ctx->r15, 0XD8);
    // 0x80090004: addiu       $t6, $sp, 0x38
    ctx->r14 = ADD32(ctx->r29, 0X38);
L_80090008:
    // 0x80090008: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x8009000C: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x80090010: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80090014: sw          $at, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r1;
    // 0x80090018: lw          $at, -0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, -0X8);
    // 0x8009001C: sw          $at, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r1;
    // 0x80090020: lw          $at, -0x4($t7)
    ctx->r1 = MEM_W(ctx->r15, -0X4);
    // 0x80090024: bne         $t7, $t0, L_80090008
    if (ctx->r15 != ctx->r8) {
        // 0x80090028: sw          $at, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r1;
            goto L_80090008;
    }
    // 0x80090028: sw          $at, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r1;
    // 0x8009002C: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x80090030: addiu       $v1, $a1, -0x1B58
    ctx->r3 = ADD32(ctx->r5, -0X1B58);
    // 0x80090034: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x80090038: lhu         $at, 0x4($t7)
    ctx->r1 = MEM_HU(ctx->r15, 0X4);
    // 0x8009003C: sh          $at, 0x4($t6)
    MEM_H(0X4, ctx->r14) = ctx->r1;
    // 0x80090040: slti        $at, $a1, 0x1B58
    ctx->r1 = SIGNED(ctx->r5) < 0X1B58 ? 1 : 0;
    // 0x80090044: bne         $at, $zero, L_800901F0
    if (ctx->r1 != 0) {
        // 0x80090048: slti        $at, $v1, 0x63D
        ctx->r1 = SIGNED(ctx->r3) < 0X63D ? 1 : 0;
            goto L_800901F0;
    }
    // 0x80090048: slti        $at, $v1, 0x63D
    ctx->r1 = SIGNED(ctx->r3) < 0X63D ? 1 : 0;
    // 0x8009004C: bnel        $at, $zero, L_8009005C
    if (ctx->r1 != 0) {
        // 0x80090050: mtc1        $v1, $f4
        ctx->f4.u32l = ctx->r3;
            goto L_8009005C;
    }
    goto skip_0;
    // 0x80090050: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    skip_0:
    // 0x80090054: addiu       $v1, $zero, 0x63C
    ctx->r3 = ADD32(0, 0X63C);
    // 0x80090058: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
L_8009005C:
    // 0x8009005C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80090060: lwc1        $f8, 0x7EC0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7EC0);
    // 0x80090064: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80090068: lh          $t1, 0x88($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X88);
    // 0x8009006C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80090070: div.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80090074: beq         $t1, $at, L_80090090
    if (ctx->r9 == ctx->r1) {
        // 0x80090078: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_80090090;
    }
    // 0x80090078: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x8009007C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80090080: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80090084: nop

    // 0x80090088: mul.s       $f2, $f0, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8009008C: nop

L_80090090:
    // 0x80090090: sw          $a0, 0x118($sp)
    MEM_W(0X118, ctx->r29) = ctx->r4;
    // 0x80090094: jal         0x80004EB0
    // 0x80090098: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_0;
    // 0x80090098: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    after_0:
    // 0x8009009C: lui         $at, 0x4210
    ctx->r1 = S32(0X4210 << 16);
    // 0x800900A0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800900A4: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800900A8: lw          $v0, 0x7DB0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7DB0);
    // 0x800900AC: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x800900B0: lw          $a0, 0x118($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X118);
    // 0x800900B4: andi        $t3, $v0, 0x2
    ctx->r11 = ctx->r2 & 0X2;
    // 0x800900B8: lwc1        $f2, 0x30($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800900BC: addiu       $t5, $sp, 0x38
    ctx->r13 = ADD32(ctx->r29, 0X38);
    // 0x800900C0: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x800900C4: mfc1        $v1, $f4
    ctx->r3 = (int32_t)ctx->f4.u32l;
    // 0x800900C8: bne         $t3, $zero, L_80090168
    if (ctx->r11 != 0) {
        // 0x800900CC: sll         $t4, $v1, 2
        ctx->r12 = S32(ctx->r3 << 2);
            goto L_80090168;
    }
    // 0x800900CC: sll         $t4, $v1, 2
    ctx->r12 = S32(ctx->r3 << 2);
    // 0x800900D0: subu        $t4, $t4, $v1
    ctx->r12 = SUB32(ctx->r12, ctx->r3);
    // 0x800900D4: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x800900D8: addu        $v0, $t4, $t5
    ctx->r2 = ADD32(ctx->r12, ctx->r13);
    // 0x800900DC: lh          $t9, 0x0($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X0);
    // 0x800900E0: lh          $t8, 0x2($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X2);
    // 0x800900E4: lh          $t0, 0x4($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X4);
    // 0x800900E8: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x800900EC: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x800900F0: lwc1        $f10, 0x4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800900F4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800900F8: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x800900FC: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80090100: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80090104: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80090108: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8009010C: addiu       $t7, $zero, 0x14
    ctx->r15 = ADD32(0, 0X14);
    // 0x80090110: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80090114: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80090118: lwc1        $f10, 0xC($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8009011C: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    // 0x80090120: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80090124: sw          $a0, 0x118($sp)
    MEM_W(0X118, ctx->r29) = ctx->r4;
    // 0x80090128: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    // 0x8009012C: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x80090130: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80090134: add.s       $f14, $f18, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80090138: lwc1        $f18, 0x7EC4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7EC4);
    // 0x8009013C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x80090140: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80090144: mul.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x80090148: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x8009014C: jal         0x8007C120
    // 0x80090150: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    Effect_Effect390_Spawn(rdram, ctx);
        goto after_1;
    // 0x80090150: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80090154: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80090158: lw          $v0, 0x7DB0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7DB0);
    // 0x8009015C: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x80090160: lw          $a0, 0x118($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X118);
    // 0x80090164: lwc1        $f2, 0x30($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X30);
L_80090168:
    // 0x80090168: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8009016C: andi        $t6, $v0, 0x7
    ctx->r14 = ctx->r2 & 0X7;
    // 0x80090170: bne         $t6, $zero, L_800901F0
    if (ctx->r14 != 0) {
        // 0x80090174: sll         $t1, $v1, 2
        ctx->r9 = S32(ctx->r3 << 2);
            goto L_800901F0;
    }
    // 0x80090174: sll         $t1, $v1, 2
    ctx->r9 = S32(ctx->r3 << 2);
    // 0x80090178: subu        $t1, $t1, $v1
    ctx->r9 = SUB32(ctx->r9, ctx->r3);
    // 0x8009017C: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x80090180: addiu       $t2, $sp, 0x38
    ctx->r10 = ADD32(ctx->r29, 0X38);
    // 0x80090184: addu        $v0, $t1, $t2
    ctx->r2 = ADD32(ctx->r9, ctx->r10);
    // 0x80090188: lh          $t3, 0x0($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X0);
    // 0x8009018C: lh          $t4, 0x2($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X2);
    // 0x80090190: lh          $t5, 0x4($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X4);
    // 0x80090194: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x80090198: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x8009019C: lwc1        $f10, 0x4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800901A0: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800901A4: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x800901A8: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800901AC: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x800901B0: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800901B4: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800901B8: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x800901BC: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800901C0: lwc1        $f10, 0xC($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800901C4: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x800901C8: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800901CC: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x800901D0: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x800901D4: add.s       $f14, $f18, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800901D8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800901DC: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800901E0: mul.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x800901E4: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x800901E8: jal         0x8007BFFC
    // 0x800901EC: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    Effect_Effect386_Spawn1(rdram, ctx);
        goto after_2;
    // 0x800901EC: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    after_2:
L_800901F0:
    // 0x800901F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800901F4: addiu       $sp, $sp, 0x118
    ctx->r29 = ADD32(ctx->r29, 0X118);
    // 0x800901F8: jr          $ra
    // 0x800901FC: nop

    return;
    // 0x800901FC: nop

;}
RECOMP_FUNC void func_edisplay_8005BAAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005BAAC: jr          $ra
    // 0x8005BAB0: nop

    return;
    // 0x8005BAB0: nop

;}
RECOMP_FUNC void Audio_dummy_80016A50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016A50: jr          $ra
    // 0x80016A54: nop

    return;
    // 0x80016A54: nop

;}
RECOMP_FUNC void ItemCheckpoint_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068914: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80068918: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8006891C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80068920: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80068924: jal         0x80066EF0
    // 0x80068928: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Item_CheckBounds(rdram, ctx);
        goto after_0;
    // 0x80068928: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8006892C: lh          $a0, 0x44($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X44);
    // 0x80068930: lwc1        $f4, 0x58($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80068934: lbu         $t6, 0x46($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X46);
    // 0x80068938: mtc1        $a0, $f6
    ctx->f6.u32l = ctx->r4;
    // 0x8006893C: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x80068940: addiu       $a2, $a2, -0x7D80
    ctx->r6 = ADD32(ctx->r6, -0X7D80);
    // 0x80068944: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80068948: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8006894C: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80068950: sub.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x80068954: blez        $t6, L_80068B08
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80068958: swc1        $f10, 0x58($s0)
        MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
            goto L_80068B08;
    }
    // 0x80068958: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
    // 0x8006895C: lh          $v1, 0x4E($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X4E);
    // 0x80068960: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80068964: lwc1        $f2, 0x6998($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X6998);
    // 0x80068968: addiu       $t7, $a0, 0x1
    ctx->r15 = ADD32(ctx->r4, 0X1);
    // 0x8006896C: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x80068970: sh          $t7, 0x44($s0)
    MEM_H(0X44, ctx->r16) = ctx->r15;
    // 0x80068974: addu        $t8, $t8, $v1
    ctx->r24 = ADD32(ctx->r24, ctx->r3);
    // 0x80068978: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x8006897C: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x80068980: subu        $t8, $t8, $v1
    ctx->r24 = SUB32(ctx->r24, ctx->r3);
    // 0x80068984: sll         $v1, $t8, 5
    ctx->r3 = S32(ctx->r24 << 5);
    // 0x80068988: addu        $t0, $t9, $v1
    ctx->r8 = ADD32(ctx->r25, ctx->r3);
    // 0x8006898C: lwc1        $f16, 0x74($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X74);
    // 0x80068990: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80068994: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80068998: addiu       $a0, $s0, 0x68
    ctx->r4 = ADD32(ctx->r16, 0X68);
    // 0x8006899C: sub.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x800689A0: lui         $a1, 0x40A0
    ctx->r5 = S32(0X40A0 << 16);
    // 0x800689A4: lui         $a3, 0x4170
    ctx->r7 = S32(0X4170 << 16);
    // 0x800689A8: mul.s       $f6, $f18, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x800689AC: add.s       $f4, $f0, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x800689B0: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x800689B4: lw          $t1, 0x0($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X0);
    // 0x800689B8: addu        $v0, $t1, $v1
    ctx->r2 = ADD32(ctx->r9, ctx->r3);
    // 0x800689BC: lw          $t2, 0x1CC($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X1CC);
    // 0x800689C0: bne         $t2, $at, L_800689EC
    if (ctx->r10 != ctx->r1) {
        // 0x800689C4: lui         $at, 0x4248
        ctx->r1 = S32(0X4248 << 16);
            goto L_800689EC;
    }
    // 0x800689C4: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x800689C8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800689CC: lwc1        $f8, 0x78($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X78);
    // 0x800689D0: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800689D4: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800689D8: sub.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x800689DC: mul.s       $f6, $f18, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x800689E0: add.s       $f4, $f0, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x800689E4: b           L_80068A04
    // 0x800689E8: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
        goto L_80068A04;
    // 0x800689E8: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
L_800689EC:
    // 0x800689EC: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800689F0: lwc1        $f8, 0x78($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X78);
    // 0x800689F4: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x800689F8: mul.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800689FC: add.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x80068A00: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
L_80068A04:
    // 0x80068A04: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80068A08: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80068A0C: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x80068A10: lw          $t3, 0x238($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X238);
    // 0x80068A14: addu        $t4, $v0, $v1
    ctx->r12 = ADD32(ctx->r2, ctx->r3);
    // 0x80068A18: addu        $t5, $v0, $v1
    ctx->r13 = ADD32(ctx->r2, ctx->r3);
    // 0x80068A1C: beql        $t3, $zero, L_80068A50
    if (ctx->r11 == 0) {
        // 0x80068A20: lwc1        $f6, 0x138($t5)
        ctx->f6.u32l = MEM_W(ctx->r13, 0X138);
            goto L_80068A50;
    }
    goto skip_0;
    // 0x80068A20: lwc1        $f6, 0x138($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0X138);
    skip_0:
    // 0x80068A24: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80068A28: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80068A2C: lwc1        $f6, 0x138($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X138);
    // 0x80068A30: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80068A34: sub.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x80068A38: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x80068A3C: mul.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80068A40: add.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x80068A44: b           L_80068A6C
    // 0x80068A48: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
        goto L_80068A6C;
    // 0x80068A48: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
    // 0x80068A4C: lwc1        $f6, 0x138($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0X138);
L_80068A50:
    // 0x80068A50: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80068A54: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80068A58: sub.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x80068A5C: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x80068A60: mul.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80068A64: add.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x80068A68: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
L_80068A6C:
    // 0x80068A6C: lhu         $t6, 0x48($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X48);
    // 0x80068A70: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80068A74: bnel        $t6, $zero, L_80068ADC
    if (ctx->r14 != 0) {
        // 0x80068A78: lui         $at, 0x40D0
        ctx->r1 = S32(0X40D0 << 16);
            goto L_80068ADC;
    }
    goto skip_1;
    // 0x80068A78: lui         $at, 0x40D0
    ctx->r1 = S32(0X40D0 << 16);
    skip_1:
    // 0x80068A7C: lwc1        $f6, 0x699C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X699C);
    // 0x80068A80: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80068A84: jal         0x8009BC2C
    // 0x80068A88: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_1;
    // 0x80068A88: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x80068A8C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80068A90: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80068A94: lui         $a3, 0x3CF5
    ctx->r7 = S32(0X3CF5 << 16);
    // 0x80068A98: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80068A9C: ori         $a3, $a3, 0xC28F
    ctx->r7 = ctx->r7 | 0XC28F;
    // 0x80068AA0: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80068AA4: addiu       $a0, $s0, 0x50
    ctx->r4 = ADD32(ctx->r16, 0X50);
    // 0x80068AA8: jal         0x8009BC2C
    // 0x80068AAC: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_2;
    // 0x80068AAC: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x80068AB0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80068AB4: lwc1        $f4, 0x69A0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X69A0);
    // 0x80068AB8: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80068ABC: lui         $a3, 0x3E4C
    ctx->r7 = S32(0X3E4C << 16);
    // 0x80068AC0: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80068AC4: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80068AC8: addiu       $a0, $s0, 0x54
    ctx->r4 = ADD32(ctx->r16, 0X54);
    // 0x80068ACC: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    // 0x80068AD0: jal         0x8009BC2C
    // 0x80068AD4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_3;
    // 0x80068AD4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_3:
    // 0x80068AD8: lui         $at, 0x40D0
    ctx->r1 = S32(0X40D0 << 16);
L_80068ADC:
    // 0x80068ADC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80068AE0: lwc1        $f10, 0x68($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X68);
    // 0x80068AE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80068AE8: c.le.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl <= ctx->f8.fl;
    // 0x80068AEC: nop

    // 0x80068AF0: bc1fl       L_80068C38
    if (!c1cs) {
        // 0x80068AF4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80068C38;
    }
    goto skip_2;
    // 0x80068AF4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x80068AF8: jal         0x80060FBC
    // 0x80068AFC: addiu       $a1, $s0, 0x5C
    ctx->r5 = ADD32(ctx->r16, 0X5C);
    Object_Kill(rdram, ctx);
        goto after_4;
    // 0x80068AFC: addiu       $a1, $s0, 0x5C
    ctx->r5 = ADD32(ctx->r16, 0X5C);
    after_4:
    // 0x80068B00: b           L_80068C38
    // 0x80068B04: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80068C38;
    // 0x80068B04: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80068B08:
    // 0x80068B08: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80068B0C: lb          $t8, 0x4C($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X4C);
    // 0x80068B10: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80068B14: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80068B18: sh          $t7, 0x44($s0)
    MEM_H(0X44, ctx->r16) = ctx->r15;
    // 0x80068B1C: swc1        $f0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
    // 0x80068B20: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x80068B24: beq         $t8, $zero, L_80068C34
    if (ctx->r24 == 0) {
        // 0x80068B28: swc1        $f16, 0x68($s0)
        MEM_W(0X68, ctx->r16) = ctx->f16.u32l;
            goto L_80068C34;
    }
    // 0x80068B28: swc1        $f16, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->f16.u32l;
    // 0x80068B2C: lh          $t1, 0x4E($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X4E);
    // 0x80068B30: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x80068B34: addiu       $a2, $a2, -0x7D80
    ctx->r6 = ADD32(ctx->r6, -0X7D80);
    // 0x80068B38: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80068B3C: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80068B40: lw          $t0, 0x0($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X0);
    // 0x80068B44: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x80068B48: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x80068B4C: sll         $t2, $t2, 5
    ctx->r10 = S32(ctx->r10 << 5);
    // 0x80068B50: addiu       $t9, $zero, 0x80
    ctx->r25 = ADD32(0, 0X80);
    // 0x80068B54: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x80068B58: sw          $t9, 0x26C($t3)
    MEM_W(0X26C, ctx->r11) = ctx->r25;
    // 0x80068B5C: lbu         $t4, 0x46($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X46);
    // 0x80068B60: addiu       $t6, $zero, 0xF
    ctx->r14 = ADD32(0, 0XF);
    // 0x80068B64: sh          $t6, 0x48($s0)
    MEM_H(0X48, ctx->r16) = ctx->r14;
    // 0x80068B68: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80068B6C: sb          $t5, 0x46($s0)
    MEM_B(0X46, ctx->r16) = ctx->r13;
    // 0x80068B70: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x80068B74: lw          $t7, 0x1A88($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1A88);
    // 0x80068B78: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80068B7C: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80068B80: sw          $t7, 0x1A8C($at)
    MEM_W(0X1A8C, ctx->r1) = ctx->r15;
    // 0x80068B84: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80068B88: addiu       $a0, $a0, 0x7CB0
    ctx->r4 = ADD32(ctx->r4, 0X7CB0);
    // 0x80068B8C: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x80068B90: neg.s       $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = -ctx->f18.fl;
    // 0x80068B94: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80068B98: swc1        $f6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f6.u32l;
    // 0x80068B9C: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80068BA0: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x80068BA4: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x80068BA8: sub.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x80068BAC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80068BB0: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x80068BB4: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80068BB8: swc1        $f10, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f10.u32l;
    // 0x80068BBC: lw          $t8, 0x7DC8($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7DC8);
    // 0x80068BC0: lbu         $t1, 0x1684($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X1684);
    // 0x80068BC4: lw          $t0, 0x1A98($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X1A98);
    // 0x80068BC8: sw          $t8, 0x7CA0($at)
    MEM_W(0X7CA0, ctx->r1) = ctx->r24;
    // 0x80068BCC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80068BD0: sb          $t1, 0x1A50($at)
    MEM_B(0X1A50, ctx->r1) = ctx->r9;
    // 0x80068BD4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80068BD8: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80068BDC: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80068BE0: addiu       $v0, $v0, 0x78B4
    ctx->r2 = ADD32(ctx->r2, 0X78B4);
    // 0x80068BE4: addiu       $a0, $a0, 0x78C0
    ctx->r4 = ADD32(ctx->r4, 0X78C0);
    // 0x80068BE8: addiu       $v1, $v1, 0x78D4
    ctx->r3 = ADD32(ctx->r3, 0X78D4);
    // 0x80068BEC: sw          $t0, 0x1A9C($at)
    MEM_W(0X1A9C, ctx->r1) = ctx->r8;
L_80068BF0:
    // 0x80068BF0: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x80068BF4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80068BF8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80068BFC: bne         $v0, $a0, L_80068BF0
    if (ctx->r2 != ctx->r4) {
        // 0x80068C00: sw          $t2, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->r10;
            goto L_80068BF0;
    }
    // 0x80068C00: sw          $t2, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r10;
    // 0x80068C04: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80068C08: lui         $t9, 0x800C
    ctx->r25 = S32(0X800C << 16);
    // 0x80068C0C: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80068C10: addiu       $t9, $t9, 0x5D3C
    ctx->r25 = ADD32(ctx->r25, 0X5D3C);
    // 0x80068C14: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x80068C18: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x80068C1C: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x80068C20: ori         $a0, $a0, 0x400F
    ctx->r4 = ctx->r4 | 0X400F;
    // 0x80068C24: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80068C28: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80068C2C: jal         0x80019218
    // 0x80068C30: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_5;
    // 0x80068C30: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_5:
L_80068C34:
    // 0x80068C34: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80068C38:
    // 0x80068C38: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80068C3C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80068C40: jr          $ra
    // 0x80068C44: nop

    return;
    // 0x80068C44: nop

;}
RECOMP_FUNC void Graphics_SetScaleMtx(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005980C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80059810: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80059814: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80059818: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8005981C: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x80059820: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x80059824: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80059828: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8005982C: jal         0x80005C34
    // 0x80059830: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Scale(rdram, ctx);
        goto after_0;
    // 0x80059830: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_0:
    // 0x80059834: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80059838: jal         0x80006EB8
    // 0x8005983C: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_1;
    // 0x8005983C: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    after_1:
    // 0x80059840: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80059844: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80059848: jr          $ra
    // 0x8005984C: nop

    return;
    // 0x8005984C: nop

;}
RECOMP_FUNC void Cutscene_WarpZoneStart_TeamSetup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80049968: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8004996C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80049970: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80049974: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80049978: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8004997C: jal         0x800613C4
    // 0x80049980: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Actor_Initialize(rdram, ctx);
        goto after_0;
    // 0x80049980: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80049984: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80049988: addiu       $t7, $zero, 0xC3
    ctx->r15 = ADD32(0, 0XC3);
    // 0x8004998C: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
    // 0x80049990: sh          $t7, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r15;
    // 0x80049994: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x80049998: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004999C: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x800499A0: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x800499A4: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x800499A8: lwc1        $f4, -0x6030($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6030);
    // 0x800499AC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800499B0: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x800499B4: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x800499B8: lwc1        $f6, -0x6020($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X6020);
    // 0x800499BC: addiu       $v1, $v1, -0x7D80
    ctx->r3 = ADD32(ctx->r3, -0X7D80);
    // 0x800499C0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800499C4: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x800499C8: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800499CC: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x800499D0: lwc1        $f10, -0x6010($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X6010);
    // 0x800499D4: lwc1        $f8, 0x138($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X138);
    // 0x800499D8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800499DC: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x800499E0: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800499E4: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x800499E8: addu        $t0, $t0, $t8
    ctx->r8 = ADD32(ctx->r8, ctx->r24);
    // 0x800499EC: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x800499F0: swc1        $f16, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
    // 0x800499F4: lwc1        $f18, -0x6000($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X6000);
    // 0x800499F8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800499FC: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80049A00: swc1        $f18, 0x114($s0)
    MEM_W(0X114, ctx->r16) = ctx->f18.u32l;
    // 0x80049A04: lwc1        $f4, -0x5FF0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X5FF0);
    // 0x80049A08: addu        $t1, $t1, $t8
    ctx->r9 = ADD32(ctx->r9, ctx->r24);
    // 0x80049A0C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80049A10: swc1        $f4, 0x118($s0)
    MEM_W(0X118, ctx->r16) = ctx->f4.u32l;
    // 0x80049A14: lw          $t0, -0x5FD0($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X5FD0);
    // 0x80049A18: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80049A1C: andi        $a1, $t7, 0xFFFF
    ctx->r5 = ctx->r15 & 0XFFFF;
    // 0x80049A20: sh          $t0, 0xB6($s0)
    MEM_H(0XB6, ctx->r16) = ctx->r8;
    // 0x80049A24: lw          $t1, -0x5FC0($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X5FC0);
    // 0x80049A28: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x80049A2C: sh          $t1, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r9;
    // 0x80049A30: lwc1        $f6, -0x5FE0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X5FE0);
    // 0x80049A34: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80049A38: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80049A3C: swc1        $f6, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f6.u32l;
    // 0x80049A40: swc1        $f8, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f8.u32l;
    // 0x80049A44: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x80049A48: lwc1        $f10, 0xC8($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0XC8);
    // 0x80049A4C: jal         0x800612B8
    // 0x80049A50: swc1        $f10, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f10.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_1;
    // 0x80049A50: swc1        $f10, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f10.u32l;
    after_1:
    // 0x80049A54: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80049A58: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80049A5C: lui         $t4, 0x800C
    ctx->r12 = S32(0X800C << 16);
    // 0x80049A60: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80049A64: sw          $t3, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r11;
    // 0x80049A68: addiu       $t4, $t4, 0x5D3C
    ctx->r12 = ADD32(ctx->r12, 0X5D3C);
    // 0x80049A6C: lui         $a0, 0x3100
    ctx->r4 = S32(0X3100 << 16);
    // 0x80049A70: ori         $a0, $a0, 0xC
    ctx->r4 = ctx->r4 | 0XC;
    // 0x80049A74: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80049A78: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80049A7C: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x80049A80: jal         0x80019218
    // 0x80049A84: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_2;
    // 0x80049A84: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_2:
    // 0x80049A88: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80049A8C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80049A90: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80049A94: jr          $ra
    // 0x80049A98: nop

    return;
    // 0x80049A98: nop

;}
RECOMP_FUNC void func_radio_800BC040(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BC040: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800BC044: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800BC048: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x800BC04C: lw          $t6, 0x7854($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7854);
    // 0x800BC050: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x800BC054: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800BC058: beq         $t6, $at, L_800BC4A0
    if (ctx->r14 == ctx->r1) {
        // 0x800BC05C: addiu       $v0, $v0, -0x7D54
        ctx->r2 = ADD32(ctx->r2, -0X7D54);
            goto L_800BC4A0;
    }
    // 0x800BC05C: addiu       $v0, $v0, -0x7D54
    ctx->r2 = ADD32(ctx->r2, -0X7D54);
    // 0x800BC060: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x800BC064: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800BC068: addiu       $a0, $a0, -0x7D4C
    ctx->r4 = ADD32(ctx->r4, -0X7D4C);
    // 0x800BC06C: blez        $v1, L_800BC07C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800BC070: lui         $a1, 0x8018
        ctx->r5 = S32(0X8018 << 16);
            goto L_800BC07C;
    }
    // 0x800BC070: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800BC074: addiu       $t7, $v1, -0x1
    ctx->r15 = ADD32(ctx->r3, -0X1);
    // 0x800BC078: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
L_800BC07C:
    // 0x800BC07C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800BC080: addiu       $a1, $a1, -0x7D64
    ctx->r5 = ADD32(ctx->r5, -0X7D64);
    // 0x800BC084: blez        $v1, L_800BC090
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800BC088: addiu       $t8, $v1, -0x1
        ctx->r24 = ADD32(ctx->r3, -0X1);
            goto L_800BC090;
    }
    // 0x800BC088: addiu       $t8, $v1, -0x1
    ctx->r24 = ADD32(ctx->r3, -0X1);
    // 0x800BC08C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
L_800BC090:
    // 0x800BC090: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x800BC094: slti        $at, $a0, 0x8
    ctx->r1 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
    // 0x800BC098: bne         $at, $zero, L_800BC0B4
    if (ctx->r1 != 0) {
        // 0x800BC09C: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_800BC0B4;
    }
    // 0x800BC09C: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800BC0A0: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x800BC0A4: beq         $v1, $at, L_800BC0D4
    if (ctx->r3 == ctx->r1) {
        // 0x800BC0A8: lui         $v0, 0x8017
        ctx->r2 = S32(0X8017 << 16);
            goto L_800BC0D4;
    }
    // 0x800BC0A8: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800BC0AC: b           L_800BC3D0
    // 0x800BC0B0: nop

        goto L_800BC3D0;
    // 0x800BC0B0: nop

L_800BC0B4:
    // 0x800BC0B4: sltiu       $at, $v1, 0x8
    ctx->r1 = ctx->r3 < 0X8 ? 1 : 0;
    // 0x800BC0B8: beq         $at, $zero, L_800BC3D0
    if (ctx->r1 == 0) {
        // 0x800BC0BC: sll         $t9, $v1, 2
        ctx->r25 = S32(ctx->r3 << 2);
            goto L_800BC3D0;
    }
    // 0x800BC0BC: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x800BC0C0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800BC0C4: addu        $at, $at, $t9
    gpr jr_addend_800BC0CC = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800BC0C8: lw          $t9, -0x6DF8($at)
    ctx->r25 = ADD32(ctx->r1, -0X6DF8);
    // 0x800BC0CC: jr          $t9
    // 0x800BC0D0: nop

    switch (jr_addend_800BC0CC >> 2) {
        case 0: goto L_800BC3D0; break;
        case 1: goto L_800BC140; break;
        case 2: goto L_800BC190; break;
        case 3: goto L_800BC1DC; break;
        case 4: goto L_800BC274; break;
        case 5: goto L_800BC298; break;
        case 6: goto L_800BC2D4; break;
        case 7: goto L_800BC360; break;
        default: switch_error(__func__, 0x800BC0CC, 0x800D9208);
    }
    // 0x800BC0D0: nop

L_800BC0D4:
    // 0x800BC0D4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800BC0D8: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800BC0DC: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x800BC0E0: addiu       $a2, $a2, -0x7D5C
    ctx->r6 = ADD32(ctx->r6, -0X7D5C);
    // 0x800BC0E4: addiu       $v1, $v1, 0x7D38
    ctx->r3 = ADD32(ctx->r3, 0X7D38);
    // 0x800BC0E8: addiu       $v0, $v0, 0x7D50
    ctx->r2 = ADD32(ctx->r2, 0X7D50);
    // 0x800BC0EC: addiu       $t0, $zero, 0x3E8
    ctx->r8 = ADD32(0, 0X3E8);
    // 0x800BC0F0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800BC0F4: sw          $t0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r8;
    // 0x800BC0F8: sw          $t1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r9;
    // 0x800BC0FC: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800BC100: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x800BC104: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x800BC108: jal         0x800C28DC
    // 0x800BC10C: lw          $a0, -0x7CF8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7CF8);
    Message_GetWidth(rdram, ctx);
        goto after_0;
    // 0x800BC10C: lw          $a0, -0x7CF8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7CF8);
    after_0:
    // 0x800BC110: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x800BC114: lw          $t2, 0x78A8($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X78A8);
    // 0x800BC118: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BC11C: sw          $v0, -0x7D28($at)
    MEM_W(-0X7D28, ctx->r1) = ctx->r2;
    // 0x800BC120: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800BC124: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800BC128: beq         $t2, $at, L_800BC134
    if (ctx->r10 == ctx->r1) {
        // 0x800BC12C: addiu       $a1, $a1, -0x7D64
        ctx->r5 = ADD32(ctx->r5, -0X7D64);
            goto L_800BC134;
    }
    // 0x800BC12C: addiu       $a1, $a1, -0x7D64
    ctx->r5 = ADD32(ctx->r5, -0X7D64);
    // 0x800BC130: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
L_800BC134:
    // 0x800BC134: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800BC138: b           L_800BC3D0
    // 0x800BC13C: lw          $a0, -0x7D64($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7D64);
        goto L_800BC3D0;
    // 0x800BC13C: lw          $a0, -0x7D64($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7D64);
L_800BC140:
    // 0x800BC140: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800BC144: addiu       $v1, $v1, 0x7D38
    ctx->r3 = ADD32(ctx->r3, 0X7D38);
    // 0x800BC148: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800BC14C: lwc1        $f6, -0x6DD8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X6DD8);
    // 0x800BC150: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800BC154: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800BC158: addiu       $t3, $a0, 0x1
    ctx->r11 = ADD32(ctx->r4, 0X1);
    // 0x800BC15C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800BC160: addiu       $t4, $zero, 0x5
    ctx->r12 = ADD32(0, 0X5);
    // 0x800BC164: swc1        $f8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f8.u32l;
    // 0x800BC168: lwc1        $f16, 0x0($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800BC16C: lwc1        $f10, -0x6DD4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X6DD4);
    // 0x800BC170: c.eq.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl == ctx->f16.fl;
    // 0x800BC174: nop

    // 0x800BC178: bc1f        L_800BC3D0
    if (!c1cs) {
        // 0x800BC17C: nop
    
            goto L_800BC3D0;
    }
    // 0x800BC17C: nop

    // 0x800BC180: sw          $t3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r11;
    // 0x800BC184: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x800BC188: b           L_800BC3D0
    // 0x800BC18C: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
        goto L_800BC3D0;
    // 0x800BC18C: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
L_800BC190:
    // 0x800BC190: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x800BC194: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x800BC198: addiu       $a2, $a2, -0x7D5C
    ctx->r6 = ADD32(ctx->r6, -0X7D5C);
    // 0x800BC19C: bne         $t5, $zero, L_800BC1B8
    if (ctx->r13 != 0) {
        // 0x800BC1A0: addiu       $t8, $zero, 0x2
        ctx->r24 = ADD32(0, 0X2);
            goto L_800BC1B8;
    }
    // 0x800BC1A0: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x800BC1A4: addiu       $t6, $a0, 0x1
    ctx->r14 = ADD32(ctx->r4, 0X1);
    // 0x800BC1A8: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x800BC1AC: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x800BC1B0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800BC1B4: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
L_800BC1B8:
    // 0x800BC1B8: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x800BC1BC: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x800BC1C0: lw          $t9, 0x7DB0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7DB0);
    // 0x800BC1C4: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x800BC1C8: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x800BC1CC: beq         $t0, $zero, L_800BC3D0
    if (ctx->r8 == 0) {
        // 0x800BC1D0: nop
    
            goto L_800BC3D0;
    }
    // 0x800BC1D0: nop

    // 0x800BC1D4: b           L_800BC3D0
    // 0x800BC1D8: sw          $t1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r9;
        goto L_800BC3D0;
    // 0x800BC1D8: sw          $t1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r9;
L_800BC1DC:
    // 0x800BC1DC: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x800BC1E0: addiu       $t3, $a0, 0x1
    ctx->r11 = ADD32(ctx->r4, 0X1);
    // 0x800BC1E4: addiu       $t4, $zero, 0x5
    ctx->r12 = ADD32(0, 0X5);
    // 0x800BC1E8: bne         $t2, $zero, L_800BC210
    if (ctx->r10 != 0) {
        // 0x800BC1EC: lui         $t5, 0x8017
        ctx->r13 = S32(0X8017 << 16);
            goto L_800BC210;
    }
    // 0x800BC1EC: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x800BC1F0: sw          $t3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r11;
    // 0x800BC1F4: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x800BC1F8: lw          $t5, 0x7834($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7834);
    // 0x800BC1FC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800BC200: addiu       $t6, $zero, 0x1E
    ctx->r14 = ADD32(0, 0X1E);
    // 0x800BC204: bne         $t5, $at, L_800BC210
    if (ctx->r13 != ctx->r1) {
        // 0x800BC208: nop
    
            goto L_800BC210;
    }
    // 0x800BC208: nop

    // 0x800BC20C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
L_800BC210:
    // 0x800BC210: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800BC214: lwc1        $f0, -0x6DD0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6DD0);
    // 0x800BC218: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800BC21C: lwc1        $f18, 0x7D68($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7D68);
    // 0x800BC220: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x800BC224: addiu       $a2, $a2, -0x7D5C
    ctx->r6 = ADD32(ctx->r6, -0X7D5C);
    // 0x800BC228: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x800BC22C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800BC230: addiu       $v0, $v0, 0x7D50
    ctx->r2 = ADD32(ctx->r2, 0X7D50);
    // 0x800BC234: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800BC238: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x800BC23C: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800BC240: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800BC244: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x800BC248: lwc1        $f8, -0x6DCC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X6DCC);
    // 0x800BC24C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800BC250: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
    // 0x800BC254: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800BC258: lw          $a0, -0x7D64($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7D64);
    // 0x800BC25C: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x800BC260: nop

    // 0x800BC264: bc1f        L_800BC3D0
    if (!c1cs) {
        // 0x800BC268: nop
    
            goto L_800BC3D0;
    }
    // 0x800BC268: nop

    // 0x800BC26C: b           L_800BC3D0
    // 0x800BC270: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
        goto L_800BC3D0;
    // 0x800BC270: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
L_800BC274:
    // 0x800BC274: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x800BC278: addiu       $t0, $a0, 0x1
    ctx->r8 = ADD32(ctx->r4, 0X1);
    // 0x800BC27C: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x800BC280: bne         $t9, $zero, L_800BC3D0
    if (ctx->r25 != 0) {
        // 0x800BC284: nop
    
            goto L_800BC3D0;
    }
    // 0x800BC284: nop

    // 0x800BC288: sw          $t0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r8;
    // 0x800BC28C: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x800BC290: b           L_800BC3D0
    // 0x800BC294: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
        goto L_800BC3D0;
    // 0x800BC294: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
L_800BC298:
    // 0x800BC298: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x800BC29C: addiu       $t3, $a0, 0x1
    ctx->r11 = ADD32(ctx->r4, 0X1);
    // 0x800BC2A0: addiu       $t4, $zero, 0x5
    ctx->r12 = ADD32(0, 0X5);
    // 0x800BC2A4: bne         $t2, $zero, L_800BC2B8
    if (ctx->r10 != 0) {
        // 0x800BC2A8: lui         $at, 0x8017
        ctx->r1 = S32(0X8017 << 16);
            goto L_800BC2B8;
    }
    // 0x800BC2A8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800BC2AC: sw          $t3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r11;
    // 0x800BC2B0: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x800BC2B4: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
L_800BC2B8:
    // 0x800BC2B8: lwc1        $f18, 0x7D68($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7D68);
    // 0x800BC2BC: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x800BC2C0: addiu       $a2, $a2, -0x7D5C
    ctx->r6 = ADD32(ctx->r6, -0X7D5C);
    // 0x800BC2C4: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x800BC2C8: mfc1        $t6, $f4
    ctx->r14 = (int32_t)ctx->f4.u32l;
    // 0x800BC2CC: b           L_800BC3D0
    // 0x800BC2D0: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
        goto L_800BC3D0;
    // 0x800BC2D0: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
L_800BC2D4:
    // 0x800BC2D4: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x800BC2D8: bne         $t7, $zero, L_800BC2FC
    if (ctx->r15 != 0) {
        // 0x800BC2DC: nop
    
            goto L_800BC2FC;
    }
    // 0x800BC2DC: nop

    // 0x800BC2E0: jal         0x8001ACDC
    // 0x800BC2E4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    Audio_PlayVoice(rdram, ctx);
        goto after_1;
    // 0x800BC2E4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x800BC2E8: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800BC2EC: addiu       $a1, $a1, -0x7D64
    ctx->r5 = ADD32(ctx->r5, -0X7D64);
    // 0x800BC2F0: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x800BC2F4: addiu       $a0, $t8, 0x1
    ctx->r4 = ADD32(ctx->r24, 0X1);
    // 0x800BC2F8: sw          $a0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r4;
L_800BC2FC:
    // 0x800BC2FC: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x800BC300: addiu       $a2, $a2, -0x7D5C
    ctx->r6 = ADD32(ctx->r6, -0X7D5C);
    // 0x800BC304: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x800BC308: sw          $t0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r8;
    // 0x800BC30C: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x800BC310: lw          $t1, 0x7DB0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7DB0);
    // 0x800BC314: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800BC318: addiu       $v0, $v0, 0x7D50
    ctx->r2 = ADD32(ctx->r2, 0X7D50);
    // 0x800BC31C: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x800BC320: beq         $t2, $zero, L_800BC330
    if (ctx->r10 == 0) {
        // 0x800BC324: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_800BC330;
    }
    // 0x800BC324: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800BC328: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x800BC32C: sw          $t3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r11;
L_800BC330:
    // 0x800BC330: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800BC334: lwc1        $f8, -0x6DC8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X6DC8);
    // 0x800BC338: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800BC33C: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800BC340: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
    // 0x800BC344: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800BC348: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x800BC34C: nop

    // 0x800BC350: bc1f        L_800BC3D0
    if (!c1cs) {
        // 0x800BC354: nop
    
            goto L_800BC3D0;
    }
    // 0x800BC354: nop

    // 0x800BC358: b           L_800BC3D0
    // 0x800BC35C: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
        goto L_800BC3D0;
    // 0x800BC35C: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
L_800BC360:
    // 0x800BC360: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800BC364: addiu       $v1, $v1, 0x7D38
    ctx->r3 = ADD32(ctx->r3, 0X7D38);
    // 0x800BC368: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800BC36C: lwc1        $f4, -0x6DC4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6DC4);
    // 0x800BC370: lwc1        $f18, 0x0($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800BC374: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800BC378: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x800BC37C: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x800BC380: addiu       $a2, $a2, -0x7D5C
    ctx->r6 = ADD32(ctx->r6, -0X7D5C);
    // 0x800BC384: addiu       $t4, $zero, 0x5
    ctx->r12 = ADD32(0, 0X5);
    // 0x800BC388: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x800BC38C: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
    // 0x800BC390: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800BC394: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x800BC398: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x800BC39C: c.eq.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl == ctx->f10.fl;
    // 0x800BC3A0: nop

    // 0x800BC3A4: bc1fl       L_800BC3BC
    if (!c1cs) {
        // 0x800BC3A8: sw          $t5, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->r13;
            goto L_800BC3BC;
    }
    goto skip_0;
    // 0x800BC3A8: sw          $t5, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r13;
    skip_0:
    // 0x800BC3AC: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x800BC3B0: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x800BC3B4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800BC3B8: sw          $t5, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r13;
L_800BC3BC:
    // 0x800BC3BC: lw          $t6, 0x7DB0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7DB0);
    // 0x800BC3C0: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x800BC3C4: beq         $t7, $zero, L_800BC3D0
    if (ctx->r15 == 0) {
        // 0x800BC3C8: nop
    
            goto L_800BC3D0;
    }
    // 0x800BC3C8: nop

    // 0x800BC3CC: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
L_800BC3D0:
    // 0x800BC3D0: blez        $a0, L_800BC4A0
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800BC3D4: addiu       $at, $zero, 0x64
        ctx->r1 = ADD32(0, 0X64);
            goto L_800BC4A0;
    }
    // 0x800BC3D4: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x800BC3D8: beql        $a0, $at, L_800BC4A4
    if (ctx->r4 == ctx->r1) {
        // 0x800BC3DC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800BC4A4;
    }
    goto skip_1;
    // 0x800BC3DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x800BC3E0: jal         0x800BAAE8
    // 0x800BC3E4: nop

    func_radio_800BAAE8(rdram, ctx);
        goto after_2;
    // 0x800BC3E4: nop

    after_2:
    // 0x800BC3E8: jal         0x800BB388
    // 0x800BC3EC: nop

    func_radio_800BB388(rdram, ctx);
        goto after_3;
    // 0x800BC3EC: nop

    after_3:
    // 0x800BC3F0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800BC3F4: lwc1        $f16, 0x7D68($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7D68);
    // 0x800BC3F8: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800BC3FC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800BC400: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800BC404: mfc1        $v0, $f18
    ctx->r2 = (int32_t)ctx->f18.u32l;
    // 0x800BC408: nop

    // 0x800BC40C: beq         $v0, $at, L_800BC424
    if (ctx->r2 == ctx->r1) {
        // 0x800BC410: addiu       $at, $zero, 0x14
        ctx->r1 = ADD32(0, 0X14);
            goto L_800BC424;
    }
    // 0x800BC410: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x800BC414: beq         $v0, $at, L_800BC424
    if (ctx->r2 == ctx->r1) {
        // 0x800BC418: addiu       $at, $zero, 0x1E
        ctx->r1 = ADD32(0, 0X1E);
            goto L_800BC424;
    }
    // 0x800BC418: addiu       $at, $zero, 0x1E
    ctx->r1 = ADD32(0, 0X1E);
    // 0x800BC41C: bnel        $v0, $at, L_800BC4A4
    if (ctx->r2 != ctx->r1) {
        // 0x800BC420: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800BC4A4;
    }
    goto skip_2;
    // 0x800BC420: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
L_800BC424:
    // 0x800BC424: jal         0x80005708
    // 0x800BC428: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Push(rdram, ctx);
        goto after_4;
    // 0x800BC428: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_4:
    // 0x800BC42C: jal         0x800B9358
    // 0x800BC430: nop

    RCP_SetupDL_36(rdram, ctx);
        goto after_5;
    // 0x800BC430: nop

    after_5:
    // 0x800BC434: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800BC438: lui         $a3, 0xC3DD
    ctx->r7 = S32(0XC3DD << 16);
    // 0x800BC43C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800BC440: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x800BC444: ori         $a3, $a3, 0x8000
    ctx->r7 = ctx->r7 | 0X8000;
    // 0x800BC448: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x800BC44C: lui         $a1, 0xC316
    ctx->r5 = S32(0XC316 << 16);
    // 0x800BC450: jal         0x80005B00
    // 0x800BC454: lui         $a2, 0xC2E6
    ctx->r6 = S32(0XC2E6 << 16);
    Matrix_Translate(rdram, ctx);
        goto after_6;
    // 0x800BC454: lui         $a2, 0xC2E6
    ctx->r6 = S32(0XC2E6 << 16);
    after_6:
    // 0x800BC458: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800BC45C: lwc1        $f0, -0x6DC0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6DC0);
    // 0x800BC460: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800BC464: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800BC468: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800BC46C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800BC470: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x800BC474: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x800BC478: jal         0x80005C34
    // 0x800BC47C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_7;
    // 0x800BC47C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_7:
    // 0x800BC480: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BC484: jal         0x80006EB8
    // 0x800BC488: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_8;
    // 0x800BC488: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    after_8:
    // 0x800BC48C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800BC490: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800BC494: sw          $zero, 0x78A0($at)
    MEM_W(0X78A0, ctx->r1) = 0;
    // 0x800BC498: jal         0x80005740
    // 0x800BC49C: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Pop(rdram, ctx);
        goto after_9;
    // 0x800BC49C: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_9:
L_800BC4A0:
    // 0x800BC4A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800BC4A4:
    // 0x800BC4A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800BC4A8: jr          $ra
    // 0x800BC4AC: nop

    return;
    // 0x800BC4AC: nop

;}
RECOMP_FUNC void PlayerShot_CheckBossHitbox(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003C008: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x8003C00C: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x8003C010: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x8003C014: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x8003C018: sw          $fp, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r30;
    // 0x8003C01C: sw          $s7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r23;
    // 0x8003C020: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x8003C024: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x8003C028: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x8003C02C: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x8003C030: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x8003C034: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x8003C038: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x8003C03C: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x8003C040: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x8003C044: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x8003C048: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8003C04C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8003C050: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8003C054: lwc1        $f30, 0x5328($at)
    ctx->f30.u32l = MEM_W(ctx->r1, 0X5328);
    // 0x8003C058: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8003C05C: lwc1        $f26, 0x532C($at)
    ctx->f26.u32l = MEM_W(ctx->r1, 0X532C);
    // 0x8003C060: lui         $at, 0xC2C8
    ctx->r1 = S32(0XC2C8 << 16);
    // 0x8003C064: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8003C068: lui         $s1, 0x8017
    ctx->r17 = S32(0X8017 << 16);
    // 0x8003C06C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8003C070: lui         $s2, 0x8014
    ctx->r18 = S32(0X8014 << 16);
    // 0x8003C074: mtc1        $zero, $f28
    ctx->f28.u32l = 0;
    // 0x8003C078: addiu       $s1, $s1, -0xEF0
    ctx->r17 = ADD32(ctx->r17, -0XEF0);
    // 0x8003C07C: addiu       $s2, $s2, -0x4438
    ctx->r18 = ADD32(ctx->r18, -0X4438);
    // 0x8003C080: lwc1        $f20, 0x5330($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X5330);
    // 0x8003C084: sw          $zero, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = 0;
    // 0x8003C088: addiu       $fp, $sp, 0x80
    ctx->r30 = ADD32(ctx->r29, 0X80);
    // 0x8003C08C: addiu       $s7, $sp, 0x8C
    ctx->r23 = ADD32(ctx->r29, 0X8C);
L_8003C090:
    // 0x8003C090: lbu         $t6, 0x0($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X0);
    // 0x8003C094: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8003C098: bnel        $t6, $at, L_8003C37C
    if (ctx->r14 != ctx->r1) {
        // 0x8003C09C: lw          $t3, 0xB4($sp)
        ctx->r11 = MEM_W(ctx->r29, 0XB4);
            goto L_8003C37C;
    }
    goto skip_0;
    // 0x8003C09C: lw          $t3, 0xB4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XB4);
    skip_0:
    // 0x8003C0A0: lh          $t7, 0x5A($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X5A);
    // 0x8003C0A4: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8003C0A8: bnel        $t7, $zero, L_8003C37C
    if (ctx->r15 != 0) {
        // 0x8003C0AC: lw          $t3, 0xB4($sp)
        ctx->r11 = MEM_W(ctx->r29, 0XB4);
            goto L_8003C37C;
    }
    goto skip_1;
    // 0x8003C0AC: lw          $t3, 0xB4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XB4);
    skip_1:
    // 0x8003C0B0: lhu         $t8, 0x2($s1)
    ctx->r24 = MEM_HU(ctx->r17, 0X2);
    // 0x8003C0B4: addiu       $at, $zero, 0x13C
    ctx->r1 = ADD32(0, 0X13C);
    // 0x8003C0B8: lw          $v0, 0x7DB0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7DB0);
    // 0x8003C0BC: bne         $t8, $at, L_8003C0DC
    if (ctx->r24 != ctx->r1) {
        // 0x8003C0C0: lwc1        $f0, 0x44($s4)
        ctx->f0.u32l = MEM_W(ctx->r20, 0X44);
            goto L_8003C0DC;
    }
    // 0x8003C0C0: lwc1        $f0, 0x44($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X44);
    // 0x8003C0C4: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x8003C0C8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8003C0CC: andi        $s6, $v0, 0x7
    ctx->r22 = ctx->r2 & 0X7;
    // 0x8003C0D0: mul.s       $f24, $f0, $f4
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f24.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8003C0D4: b           L_8003C0F4
    // 0x8003C0D8: lw          $s0, 0x28($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X28);
        goto L_8003C0F4;
    // 0x8003C0D8: lw          $s0, 0x28($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X28);
L_8003C0DC:
    // 0x8003C0DC: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8003C0E0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003C0E4: andi        $s6, $v0, 0xF
    ctx->r22 = ctx->r2 & 0XF;
    // 0x8003C0E8: mul.s       $f24, $f0, $f6
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f24.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8003C0EC: nop

    // 0x8003C0F0: lw          $s0, 0x28($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X28);
L_8003C0F4:
    // 0x8003C0F4: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8003C0F8: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8003C0FC: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8003C100: mfc1        $s5, $f10
    ctx->r21 = (int32_t)ctx->f10.u32l;
    // 0x8003C104: nop

    // 0x8003C108: beql        $s5, $zero, L_8003C37C
    if (ctx->r21 == 0) {
        // 0x8003C10C: lw          $t3, 0xB4($sp)
        ctx->r11 = MEM_W(ctx->r29, 0XB4);
            goto L_8003C37C;
    }
    goto skip_2;
    // 0x8003C10C: lw          $t3, 0xB4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XB4);
    skip_2:
    // 0x8003C110: blez        $s5, L_8003C378
    if (SIGNED(ctx->r21) <= 0) {
        // 0x8003C114: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_8003C378;
    }
    // 0x8003C114: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_8003C118:
    // 0x8003C118: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8003C11C: c.eq.s      $f26, $f4
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f26.fl == ctx->f4.fl;
    // 0x8003C120: nop

    // 0x8003C124: bc1fl       L_8003C1F8
    if (!c1cs) {
        // 0x8003C128: lwc1        $f10, 0x18($s1)
        ctx->f10.u32l = MEM_W(ctx->r17, 0X18);
            goto L_8003C1F8;
    }
    goto skip_3;
    // 0x8003C128: lwc1        $f10, 0x18($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X18);
    skip_3:
    // 0x8003C12C: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003C130: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8003C134: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8003C138: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x8003C13C: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x8003C140: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8003C144: jal         0x80005FE0
    // 0x8003C148: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_0;
    // 0x8003C148: nop

    after_0:
    // 0x8003C14C: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8003C150: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8003C154: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003C158: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x8003C15C: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x8003C160: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8003C164: jal         0x80005D44
    // 0x8003C168: nop

    Matrix_RotateX(rdram, ctx);
        goto after_1;
    // 0x8003C168: nop

    after_1:
    // 0x8003C16C: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8003C170: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8003C174: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003C178: neg.s       $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = -ctx->f10.fl;
    // 0x8003C17C: mul.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x8003C180: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8003C184: jal         0x80005E90
    // 0x8003C188: nop

    Matrix_RotateY(rdram, ctx);
        goto after_2;
    // 0x8003C188: nop

    after_2:
    // 0x8003C18C: lwc1        $f8, 0x18($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X18);
    // 0x8003C190: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8003C194: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003C198: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x8003C19C: mul.s       $f4, $f10, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x8003C1A0: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8003C1A4: jal         0x80005FE0
    // 0x8003C1A8: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_3;
    // 0x8003C1A8: nop

    after_3:
    // 0x8003C1AC: lwc1        $f6, 0x10($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8003C1B0: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8003C1B4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003C1B8: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x8003C1BC: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x8003C1C0: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8003C1C4: jal         0x80005D44
    // 0x8003C1C8: nop

    Matrix_RotateX(rdram, ctx);
        goto after_4;
    // 0x8003C1C8: nop

    after_4:
    // 0x8003C1CC: lwc1        $f4, 0x14($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8003C1D0: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8003C1D4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003C1D8: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x8003C1DC: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x8003C1E0: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8003C1E4: jal         0x80005E90
    // 0x8003C1E8: nop

    Matrix_RotateY(rdram, ctx);
        goto after_5;
    // 0x8003C1E8: nop

    after_5:
    // 0x8003C1EC: b           L_8003C254
    // 0x8003C1F0: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
        goto L_8003C254;
    // 0x8003C1F0: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x8003C1F4: lwc1        $f10, 0x18($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X18);
L_8003C1F8:
    // 0x8003C1F8: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8003C1FC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8003C200: neg.s       $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = -ctx->f10.fl;
    // 0x8003C204: mul.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x8003C208: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8003C20C: jal         0x80005FE0
    // 0x8003C210: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_6;
    // 0x8003C210: nop

    after_6:
    // 0x8003C214: lwc1        $f8, 0x10($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8003C218: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8003C21C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003C220: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x8003C224: mul.s       $f4, $f10, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x8003C228: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8003C22C: jal         0x80005D44
    // 0x8003C230: nop

    Matrix_RotateX(rdram, ctx);
        goto after_7;
    // 0x8003C230: nop

    after_7:
    // 0x8003C234: lwc1        $f6, 0x14($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8003C238: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8003C23C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003C240: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x8003C244: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x8003C248: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8003C24C: jal         0x80005E90
    // 0x8003C250: nop

    Matrix_RotateY(rdram, ctx);
        goto after_8;
    // 0x8003C250: nop

    after_8:
L_8003C254:
    // 0x8003C254: bnel        $s3, $s6, L_8003C370
    if (ctx->r19 != ctx->r22) {
        // 0x8003C258: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_8003C370;
    }
    goto skip_4;
    // 0x8003C258: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_4:
    // 0x8003C25C: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8003C260: c.lt.s      $f22, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f22.fl < ctx->f4.fl;
    // 0x8003C264: nop

    // 0x8003C268: bc1fl       L_8003C370
    if (!c1cs) {
        // 0x8003C26C: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_8003C370;
    }
    goto skip_5;
    // 0x8003C26C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_5:
    // 0x8003C270: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003C274: c.lt.s      $f22, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f22.fl < ctx->f6.fl;
    // 0x8003C278: nop

    // 0x8003C27C: bc1fl       L_8003C370
    if (!c1cs) {
        // 0x8003C280: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_8003C370;
    }
    goto skip_6;
    // 0x8003C280: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_6:
    // 0x8003C284: lwc1        $f8, 0x4($s4)
    ctx->f8.u32l = MEM_W(ctx->r20, 0X4);
    // 0x8003C288: lwc1        $f10, 0x4($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8003C28C: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8003C290: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x8003C294: sub.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8003C298: or          $a2, $fp, $zero
    ctx->r6 = ctx->r30 | 0;
    // 0x8003C29C: swc1        $f4, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f4.u32l;
    // 0x8003C2A0: lwc1        $f8, 0x8($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8003C2A4: lwc1        $f6, 0x8($s4)
    ctx->f6.u32l = MEM_W(ctx->r20, 0X8);
    // 0x8003C2A8: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8003C2AC: swc1        $f10, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f10.u32l;
    // 0x8003C2B0: lwc1        $f6, 0xC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8003C2B4: lwc1        $f4, 0xC($s4)
    ctx->f4.u32l = MEM_W(ctx->r20, 0XC);
    // 0x8003C2B8: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8003C2BC: jal         0x80006A20
    // 0x8003C2C0: swc1        $f8, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f8.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_9;
    // 0x8003C2C0: swc1        $f8, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f8.u32l;
    after_9:
    // 0x8003C2C4: lwc1        $f0, 0x4($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8003C2C8: lwc1        $f10, 0x10($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003C2CC: lwc1        $f6, 0x80($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X80);
    // 0x8003C2D0: lwc1        $f2, 0x8($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8003C2D4: add.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x8003C2D8: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8003C2DC: lwc1        $f12, 0xC($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8003C2E0: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x8003C2E4: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x8003C2E8: lw          $t0, 0x7880($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7880);
    // 0x8003C2EC: add.s       $f6, $f10, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x8003C2F0: lwc1        $f10, 0x0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8003C2F4: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x8003C2F8: sub.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x8003C2FC: lwc1        $f4, 0x84($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X84);
    // 0x8003C300: addiu       $t2, $zero, 0x14
    ctx->r10 = ADD32(0, 0X14);
    // 0x8003C304: add.s       $f8, $f2, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x8003C308: add.s       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f12.fl;
    // 0x8003C30C: mul.s       $f10, $f16, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x8003C310: sub.s       $f18, $f6, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8003C314: lwc1        $f6, 0x88($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X88);
    // 0x8003C318: add.s       $f8, $f12, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f12.fl + ctx->f6.fl;
    // 0x8003C31C: mul.s       $f6, $f18, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x8003C320: bne         $t0, $zero, L_8003C340
    if (ctx->r8 != 0) {
        // 0x8003C324: sub.s       $f14, $f4, $f8
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f8.fl;
            goto L_8003C340;
    }
    // 0x8003C324: sub.s       $f14, $f4, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x8003C328: c.lt.s      $f14, $f28
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f14.fl < ctx->f28.fl;
    // 0x8003C32C: nop

    // 0x8003C330: bc1f        L_8003C340
    if (!c1cs) {
        // 0x8003C334: nop
    
            goto L_8003C340;
    }
    // 0x8003C334: nop

    // 0x8003C338: mul.s       $f14, $f14, $f30
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f30.fl);
    // 0x8003C33C: nop

L_8003C340:
    // 0x8003C340: mul.s       $f8, $f14, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8003C344: add.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8003C348: add.s       $f0, $f4, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8003C34C: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x8003C350: c.lt.s      $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f0.fl < ctx->f24.fl;
    // 0x8003C354: nop

    // 0x8003C358: bc1fl       L_8003C370
    if (!c1cs) {
        // 0x8003C35C: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_8003C370;
    }
    goto skip_7;
    // 0x8003C35C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_7:
    // 0x8003C360: sh          $s3, 0x66($s1)
    MEM_H(0X66, ctx->r17) = ctx->r19;
    // 0x8003C364: sb          $t1, 0x62($s1)
    MEM_B(0X62, ctx->r17) = ctx->r9;
    // 0x8003C368: sh          $t2, 0x64($s1)
    MEM_H(0X64, ctx->r17) = ctx->r10;
    // 0x8003C36C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_8003C370:
    // 0x8003C370: bne         $s3, $s5, L_8003C118
    if (ctx->r19 != ctx->r21) {
        // 0x8003C374: addiu       $s0, $s0, 0x18
        ctx->r16 = ADD32(ctx->r16, 0X18);
            goto L_8003C118;
    }
    // 0x8003C374: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
L_8003C378:
    // 0x8003C378: lw          $t3, 0xB4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XB4);
L_8003C37C:
    // 0x8003C37C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8003C380: addiu       $s1, $s1, 0x408
    ctx->r17 = ADD32(ctx->r17, 0X408);
    // 0x8003C384: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8003C388: bne         $t4, $at, L_8003C090
    if (ctx->r12 != ctx->r1) {
        // 0x8003C38C: sw          $t4, 0xB4($sp)
        MEM_W(0XB4, ctx->r29) = ctx->r12;
            goto L_8003C090;
    }
    // 0x8003C38C: sw          $t4, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r12;
    // 0x8003C390: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x8003C394: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8003C398: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8003C39C: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x8003C3A0: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x8003C3A4: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x8003C3A8: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x8003C3AC: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x8003C3B0: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x8003C3B4: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x8003C3B8: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x8003C3BC: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x8003C3C0: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x8003C3C4: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x8003C3C8: lw          $s7, 0x64($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X64);
    // 0x8003C3CC: lw          $fp, 0x68($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X68);
    // 0x8003C3D0: jr          $ra
    // 0x8003C3D4: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    return;
    // 0x8003C3D4: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
;}
