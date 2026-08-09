#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void ItemSilverRing_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005C900: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005C904: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8005C908: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8005C90C: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8005C910: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005C914: jal         0x800B8DD0
    // 0x8005C918: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x8005C918: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    after_0:
    // 0x8005C91C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8005C920: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8005C924: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8005C928: lui         $t7, 0xBB00
    ctx->r15 = S32(0XBB00 << 16);
    // 0x8005C92C: ori         $t7, $t7, 0x1
    ctx->r15 = ctx->r15 | 0X1;
    // 0x8005C930: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8005C934: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8005C938: lui         $t8, 0xBB8
    ctx->r24 = S32(0XBB8 << 16);
    // 0x8005C93C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8005C940: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8005C944: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8005C948: lui         $t0, 0xB700
    ctx->r8 = S32(0XB700 << 16);
    // 0x8005C94C: lui         $t1, 0xC
    ctx->r9 = S32(0XC << 16);
    // 0x8005C950: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8005C954: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8005C958: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x8005C95C: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x8005C960: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x8005C964: jal         0x8005980C
    // 0x8005C968: lwc1        $f12, 0x68($t2)
    ctx->f12.u32l = MEM_W(ctx->r10, 0X68);
    Graphics_SetScaleMtx(rdram, ctx);
        goto after_1;
    // 0x8005C968: lwc1        $f12, 0x68($t2)
    ctx->f12.u32l = MEM_W(ctx->r10, 0X68);
    after_1:
    // 0x8005C96C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8005C970: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8005C974: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8005C978: lui         $t5, 0x102
    ctx->r13 = S32(0X102 << 16);
    // 0x8005C97C: addiu       $t5, $t5, -0x5A90
    ctx->r13 = ADD32(ctx->r13, -0X5A90);
    // 0x8005C980: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x8005C984: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x8005C988: lui         $t4, 0x600
    ctx->r12 = S32(0X600 << 16);
    // 0x8005C98C: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8005C990: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x8005C994: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8005C998: lui         $t7, 0xB600
    ctx->r15 = S32(0XB600 << 16);
    // 0x8005C99C: lui         $t8, 0xC
    ctx->r24 = S32(0XC << 16);
    // 0x8005C9A0: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8005C9A4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8005C9A8: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8005C9AC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8005C9B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005C9B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005C9B8: jr          $ra
    // 0x8005C9BC: nop

    return;
    // 0x8005C9BC: nop

;}
RECOMP_FUNC void ActorEvent_UpdatePeriscope(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072474: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80072478: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8007247C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80072480: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80072484: lh          $v1, 0x48($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X48);
    // 0x80072488: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8007248C: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80072490: beql        $v1, $zero, L_800724F0
    if (ctx->r3 == 0) {
        // 0x80072494: lw          $t6, 0x8C($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X8C);
            goto L_800724F0;
    }
    goto skip_0;
    // 0x80072494: lw          $t6, 0x8C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8C);
    skip_0:
    // 0x80072498: beq         $v1, $a0, L_800724C4
    if (ctx->r3 == ctx->r4) {
        // 0x8007249C: lui         $at, 0x4234
        ctx->r1 = S32(0X4234 << 16);
            goto L_800724C4;
    }
    // 0x8007249C: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x800724A0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800724A4: beq         $v1, $at, L_800724D0
    if (ctx->r3 == ctx->r1) {
        // 0x800724A8: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800724D0;
    }
    // 0x800724A8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800724AC: beq         $v1, $at, L_800724DC
    if (ctx->r3 == ctx->r1) {
        // 0x800724B0: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_800724DC;
    }
    // 0x800724B0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800724B4: beql        $v1, $at, L_800724E8
    if (ctx->r3 == ctx->r1) {
        // 0x800724B8: sw          $zero, 0x8C($s0)
        MEM_W(0X8C, ctx->r16) = 0;
            goto L_800724E8;
    }
    goto skip_1;
    // 0x800724B8: sw          $zero, 0x8C($s0)
    MEM_W(0X8C, ctx->r16) = 0;
    skip_1:
    // 0x800724BC: b           L_800724EC
    // 0x800724C0: sh          $zero, 0x48($s0)
    MEM_H(0X48, ctx->r16) = 0;
        goto L_800724EC;
    // 0x800724C0: sh          $zero, 0x48($s0)
    MEM_H(0X48, ctx->r16) = 0;
L_800724C4:
    // 0x800724C4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800724C8: b           L_800724E8
    // 0x800724CC: swc1        $f4, 0x154($s0)
    MEM_W(0X154, ctx->r16) = ctx->f4.u32l;
        goto L_800724E8;
    // 0x800724CC: swc1        $f4, 0x154($s0)
    MEM_W(0X154, ctx->r16) = ctx->f4.u32l;
L_800724D0:
    // 0x800724D0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800724D4: b           L_800724E8
    // 0x800724D8: swc1        $f6, 0x154($s0)
    MEM_W(0X154, ctx->r16) = ctx->f6.u32l;
        goto L_800724E8;
    // 0x800724D8: swc1        $f6, 0x154($s0)
    MEM_W(0X154, ctx->r16) = ctx->f6.u32l;
L_800724DC:
    // 0x800724DC: b           L_800724E8
    // 0x800724E0: sw          $a0, 0x8C($s0)
    MEM_W(0X8C, ctx->r16) = ctx->r4;
        goto L_800724E8;
    // 0x800724E0: sw          $a0, 0x8C($s0)
    MEM_W(0X8C, ctx->r16) = ctx->r4;
    // 0x800724E4: sw          $zero, 0x8C($s0)
    MEM_W(0X8C, ctx->r16) = 0;
L_800724E8:
    // 0x800724E8: sh          $zero, 0x48($s0)
    MEM_H(0X48, ctx->r16) = 0;
L_800724EC:
    // 0x800724EC: lw          $t6, 0x8C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8C);
L_800724F0:
    // 0x800724F0: beql        $t6, $zero, L_8007252C
    if (ctx->r14 == 0) {
        // 0x800724F4: lw          $t7, 0x68($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X68);
            goto L_8007252C;
    }
    goto skip_2;
    // 0x800724F4: lw          $t7, 0x68($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X68);
    skip_2:
    // 0x800724F8: lw          $v0, -0x7D80($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D80);
    // 0x800724FC: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80072500: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80072504: lwc1        $f8, 0x74($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X74);
    // 0x80072508: lwc1        $f16, 0x138($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X138);
    // 0x8007250C: sub.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80072510: jal         0x80005100
    // 0x80072514: sub.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f18.fl;
    Math_Atan2F(rdram, ctx);
        goto after_0;
    // 0x80072514: sub.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f18.fl;
    after_0:
    // 0x80072518: jal         0x8009F768
    // 0x8007251C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    Math_RadToDeg(rdram, ctx);
        goto after_1;
    // 0x8007251C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_1:
    // 0x80072520: b           L_80072544
    // 0x80072524: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
        goto L_80072544;
    // 0x80072524: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80072528: lw          $t7, 0x68($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X68);
L_8007252C:
    // 0x8007252C: beql        $t7, $zero, L_80072540
    if (ctx->r15 == 0) {
        // 0x80072530: mtc1        $zero, $f2
        ctx->f2.u32l = 0;
            goto L_80072540;
    }
    goto skip_3;
    // 0x80072530: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    skip_3:
    // 0x80072534: b           L_80072544
    // 0x80072538: lwc1        $f2, 0xF8($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XF8);
        goto L_80072544;
    // 0x80072538: lwc1        $f2, 0xF8($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XF8);
    // 0x8007253C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
L_80072540:
    // 0x80072540: nop

L_80072544:
    // 0x80072544: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80072548: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x8007254C: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x80072550: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80072554: addiu       $a0, $s0, 0x14
    ctx->r4 = ADD32(ctx->r16, 0X14);
    // 0x80072558: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    // 0x8007255C: jal         0x8009BD38
    // 0x80072560: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_2;
    // 0x80072560: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x80072564: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80072568: lw          $a1, 0x154($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X154);
    // 0x8007256C: addiu       $a0, $s0, 0x150
    ctx->r4 = ADD32(ctx->r16, 0X150);
    // 0x80072570: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    // 0x80072574: lui         $a3, 0x4100
    ctx->r7 = S32(0X4100 << 16);
    // 0x80072578: jal         0x8009BD38
    // 0x8007257C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_3;
    // 0x8007257C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_3:
    // 0x80072580: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80072584: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80072588: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8007258C: jr          $ra
    // 0x80072590: nop

    return;
    // 0x80072590: nop

;}
RECOMP_FUNC void Player_DamageEffects(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A46A0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800A46A4: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800A46A8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800A46AC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800A46B0: lw          $t6, 0x238($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X238);
    // 0x800A46B4: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x800A46B8: beql        $t6, $zero, L_800A46D4
    if (ctx->r14 == 0) {
        // 0x800A46BC: lbu         $t8, 0x49C($s0)
        ctx->r24 = MEM_BU(ctx->r16, 0X49C);
            goto L_800A46D4;
    }
    goto skip_0;
    // 0x800A46BC: lbu         $t8, 0x49C($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X49C);
    skip_0:
    // 0x800A46C0: lw          $t7, 0x7880($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7880);
    // 0x800A46C4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A46C8: bnel        $t7, $at, L_800A49AC
    if (ctx->r15 != ctx->r1) {
        // 0x800A46CC: lw          $v0, 0x264($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X264);
            goto L_800A49AC;
    }
    goto skip_1;
    // 0x800A46CC: lw          $v0, 0x264($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X264);
    skip_1:
    // 0x800A46D0: lbu         $t8, 0x49C($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X49C);
L_800A46D4:
    // 0x800A46D4: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800A46D8: slti        $at, $t8, 0x2
    ctx->r1 = SIGNED(ctx->r24) < 0X2 ? 1 : 0;
    // 0x800A46DC: beql        $at, $zero, L_800A483C
    if (ctx->r1 == 0) {
        // 0x800A46E0: lbu         $t7, 0x49D($s0)
        ctx->r15 = MEM_BU(ctx->r16, 0X49D);
            goto L_800A483C;
    }
    goto skip_2;
    // 0x800A46E0: lbu         $t7, 0x49D($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X49D);
    skip_2:
    // 0x800A46E4: lw          $v0, 0x7DB0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7DB0);
    // 0x800A46E8: andi        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 & 0X1;
    // 0x800A46EC: bne         $t9, $zero, L_800A4774
    if (ctx->r25 != 0) {
        // 0x800A46F0: or          $v0, $t9, $zero
        ctx->r2 = ctx->r25 | 0;
            goto L_800A4774;
    }
    // 0x800A46F0: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x800A46F4: lw          $t0, 0x1C4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X1C4);
    // 0x800A46F8: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x800A46FC: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x800A4700: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x800A4704: lw          $t2, 0x7D70($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7D70);
    // 0x800A4708: beq         $t2, $zero, L_800A4774
    if (ctx->r10 == 0) {
        // 0x800A470C: nop
    
            goto L_800A4774;
    }
    // 0x800A470C: nop

    // 0x800A4710: jal         0x80004EB0
    // 0x800A4714: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_0;
    // 0x800A4714: nop

    after_0:
    // 0x800A4718: jal         0x80004EB0
    // 0x800A471C: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x800A471C: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x800A4720: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800A4724: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A4728: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800A472C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800A4730: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800A4734: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800A4738: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x800A473C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A4740: lwc1        $f4, 0x2D4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2D4);
    // 0x800A4744: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800A4748: lwc1        $f10, 0x2D8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2D8);
    // 0x800A474C: lw          $a2, 0x2DC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X2DC);
    // 0x800A4750: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800A4754: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x800A4758: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800A475C: jal         0x8007D10C
    // 0x800A4760: add.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f10.fl;
    Effect_FireSmoke2_Spawn3(rdram, ctx);
        goto after_2;
    // 0x800A4760: add.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f10.fl;
    after_2:
    // 0x800A4764: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800A4768: lw          $v0, 0x7DB0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7DB0);
    // 0x800A476C: andi        $t3, $v0, 0x1
    ctx->r11 = ctx->r2 & 0X1;
    // 0x800A4770: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
L_800A4774:
    // 0x800A4774: bnel        $v0, $zero, L_800A483C
    if (ctx->r2 != 0) {
        // 0x800A4778: lbu         $t7, 0x49D($s0)
        ctx->r15 = MEM_BU(ctx->r16, 0X49D);
            goto L_800A483C;
    }
    goto skip_3;
    // 0x800A4778: lbu         $t7, 0x49D($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X49D);
    skip_3:
    // 0x800A477C: jal         0x80004EB0
    // 0x800A4780: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_3;
    // 0x800A4780: nop

    after_3:
    // 0x800A4784: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800A4788: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800A478C: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x800A4790: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x800A4794: nop

    // 0x800A4798: bc1fl       L_800A483C
    if (!c1cs) {
        // 0x800A479C: lbu         $t7, 0x49D($s0)
        ctx->r15 = MEM_BU(ctx->r16, 0X49D);
            goto L_800A483C;
    }
    goto skip_4;
    // 0x800A479C: lbu         $t7, 0x49D($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X49D);
    skip_4:
    // 0x800A47A0: lw          $t4, 0x78E8($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X78E8);
    // 0x800A47A4: bnel        $t4, $zero, L_800A483C
    if (ctx->r12 != 0) {
        // 0x800A47A8: lbu         $t7, 0x49D($s0)
        ctx->r15 = MEM_BU(ctx->r16, 0X49D);
            goto L_800A483C;
    }
    goto skip_5;
    // 0x800A47A8: lbu         $t7, 0x49D($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X49D);
    skip_5:
    // 0x800A47AC: jal         0x80004EB0
    // 0x800A47B0: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_4;
    // 0x800A47B0: nop

    after_4:
    // 0x800A47B4: jal         0x80004EB0
    // 0x800A47B8: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_5;
    // 0x800A47B8: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    after_5:
    // 0x800A47BC: jal         0x80004EB0
    // 0x800A47C0: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_6;
    // 0x800A47C0: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    after_6:
    // 0x800A47C4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A47C8: lwc1        $f2, -0x7CCC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X7CCC);
    // 0x800A47CC: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x800A47D0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A47D4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800A47D8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A47DC: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800A47E0: lwc1        $f18, 0x2D4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X2D4);
    // 0x800A47E4: lw          $a2, 0x2DC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X2DC);
    // 0x800A47E8: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800A47EC: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800A47F0: lw          $a3, 0xC0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XC0);
    // 0x800A47F4: mul.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800A47F8: lwc1        $f8, 0x2D8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2D8);
    // 0x800A47FC: mul.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x800A4800: nop

    // 0x800A4804: mul.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800A4808: add.s       $f12, $f10, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x800A480C: lwc1        $f10, 0xC4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x800A4810: add.s       $f14, $f6, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800A4814: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x800A4818: lwc1        $f18, 0xC8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x800A481C: add.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x800A4820: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x800A4824: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x800A4828: lw          $t5, 0x1C4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X1C4);
    // 0x800A482C: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x800A4830: jal         0x8007C484
    // 0x800A4834: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    Effect_ElectricArc_Spawn(rdram, ctx);
        goto after_7;
    // 0x800A4834: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_7:
    // 0x800A4838: lbu         $t7, 0x49D($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X49D);
L_800A483C:
    // 0x800A483C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800A4840: slti        $at, $t7, 0x2
    ctx->r1 = SIGNED(ctx->r15) < 0X2 ? 1 : 0;
    // 0x800A4844: beql        $at, $zero, L_800A49AC
    if (ctx->r1 == 0) {
        // 0x800A4848: lw          $v0, 0x264($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X264);
            goto L_800A49AC;
    }
    goto skip_6;
    // 0x800A4848: lw          $v0, 0x264($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X264);
    skip_6:
    // 0x800A484C: lw          $v0, 0x7DB0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7DB0);
    // 0x800A4850: andi        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 & 0X1;
    // 0x800A4854: bne         $t8, $zero, L_800A48DC
    if (ctx->r24 != 0) {
        // 0x800A4858: or          $v0, $t8, $zero
        ctx->r2 = ctx->r24 | 0;
            goto L_800A48DC;
    }
    // 0x800A4858: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800A485C: lw          $t9, 0x1C4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1C4);
    // 0x800A4860: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x800A4864: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800A4868: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x800A486C: lw          $t1, 0x7D88($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7D88);
    // 0x800A4870: beq         $t1, $zero, L_800A48DC
    if (ctx->r9 == 0) {
        // 0x800A4874: nop
    
            goto L_800A48DC;
    }
    // 0x800A4874: nop

    // 0x800A4878: jal         0x80004EB0
    // 0x800A487C: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_8;
    // 0x800A487C: nop

    after_8:
    // 0x800A4880: jal         0x80004EB0
    // 0x800A4884: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_9;
    // 0x800A4884: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    after_9:
    // 0x800A4888: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800A488C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800A4890: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800A4894: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800A4898: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800A489C: sub.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800A48A0: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x800A48A4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800A48A8: lwc1        $f8, 0x2C8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2C8);
    // 0x800A48AC: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800A48B0: lwc1        $f4, 0x2CC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2CC);
    // 0x800A48B4: lw          $a2, 0x2D0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X2D0);
    // 0x800A48B8: mul.s       $f18, $f0, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x800A48BC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x800A48C0: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800A48C4: jal         0x8007D10C
    // 0x800A48C8: add.s       $f14, $f18, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f4.fl;
    Effect_FireSmoke2_Spawn3(rdram, ctx);
        goto after_10;
    // 0x800A48C8: add.s       $f14, $f18, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f4.fl;
    after_10:
    // 0x800A48CC: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800A48D0: lw          $v0, 0x7DB0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7DB0);
    // 0x800A48D4: andi        $t2, $v0, 0x1
    ctx->r10 = ctx->r2 & 0X1;
    // 0x800A48D8: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
L_800A48DC:
    // 0x800A48DC: bnel        $v0, $zero, L_800A49AC
    if (ctx->r2 != 0) {
        // 0x800A48E0: lw          $v0, 0x264($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X264);
            goto L_800A49AC;
    }
    goto skip_7;
    // 0x800A48E0: lw          $v0, 0x264($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X264);
    skip_7:
    // 0x800A48E4: jal         0x80004EB0
    // 0x800A48E8: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_11;
    // 0x800A48E8: nop

    after_11:
    // 0x800A48EC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800A48F0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A48F4: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x800A48F8: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x800A48FC: nop

    // 0x800A4900: bc1fl       L_800A49AC
    if (!c1cs) {
        // 0x800A4904: lw          $v0, 0x264($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X264);
            goto L_800A49AC;
    }
    goto skip_8;
    // 0x800A4904: lw          $v0, 0x264($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X264);
    skip_8:
    // 0x800A4908: lw          $t3, 0x78E8($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X78E8);
    // 0x800A490C: bnel        $t3, $zero, L_800A49AC
    if (ctx->r11 != 0) {
        // 0x800A4910: lw          $v0, 0x264($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X264);
            goto L_800A49AC;
    }
    goto skip_9;
    // 0x800A4910: lw          $v0, 0x264($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X264);
    skip_9:
    // 0x800A4914: jal         0x80004EB0
    // 0x800A4918: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_12;
    // 0x800A4918: nop

    after_12:
    // 0x800A491C: jal         0x80004EB0
    // 0x800A4920: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_13;
    // 0x800A4920: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    after_13:
    // 0x800A4924: jal         0x80004EB0
    // 0x800A4928: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_14;
    // 0x800A4928: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    after_14:
    // 0x800A492C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800A4930: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800A4934: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800A4938: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x800A493C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800A4940: sub.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800A4944: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800A4948: lwc1        $f8, 0x2C8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2C8);
    // 0x800A494C: lw          $a2, 0x2D0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X2D0);
    // 0x800A4950: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800A4954: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800A4958: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A495C: lw          $a3, 0xC0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XC0);
    // 0x800A4960: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800A4964: lwc1        $f18, -0x7CC8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X7CC8);
    // 0x800A4968: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A496C: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800A4970: lwc1        $f6, 0x2CC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2CC);
    // 0x800A4974: lwc1        $f8, 0xC4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x800A4978: add.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800A497C: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x800A4980: lwc1        $f6, -0x7CC4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7CC4);
    // 0x800A4984: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x800A4988: lwc1        $f10, 0xC8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x800A498C: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    // 0x800A4990: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800A4994: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x800A4998: lw          $t4, 0x1C4($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X1C4);
    // 0x800A499C: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x800A49A0: jal         0x8007C484
    // 0x800A49A4: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    Effect_ElectricArc_Spawn(rdram, ctx);
        goto after_15;
    // 0x800A49A4: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    after_15:
    // 0x800A49A8: lw          $v0, 0x264($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X264);
L_800A49AC:
    // 0x800A49AC: addiu       $v1, $zero, 0x7
    ctx->r3 = ADD32(0, 0X7);
    // 0x800A49B0: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x800A49B4: slti        $at, $v0, 0x40
    ctx->r1 = SIGNED(ctx->r2) < 0X40 ? 1 : 0;
    // 0x800A49B8: beq         $at, $zero, L_800A4C2C
    if (ctx->r1 == 0) {
        // 0x800A49BC: slti        $at, $v0, 0x11
        ctx->r1 = SIGNED(ctx->r2) < 0X11 ? 1 : 0;
            goto L_800A4C2C;
    }
    // 0x800A49BC: slti        $at, $v0, 0x11
    ctx->r1 = SIGNED(ctx->r2) < 0X11 ? 1 : 0;
    // 0x800A49C0: lw          $a1, 0x238($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X238);
    // 0x800A49C4: bne         $at, $zero, L_800A49D0
    if (ctx->r1 != 0) {
        // 0x800A49C8: lw          $a0, 0x7DB0($a0)
        ctx->r4 = MEM_W(ctx->r4, 0X7DB0);
            goto L_800A49D0;
    }
    // 0x800A49C8: lw          $a0, 0x7DB0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7DB0);
    // 0x800A49CC: addiu       $v1, $zero, 0xF
    ctx->r3 = ADD32(0, 0XF);
L_800A49D0:
    // 0x800A49D0: slti        $at, $v0, 0x21
    ctx->r1 = SIGNED(ctx->r2) < 0X21 ? 1 : 0;
    // 0x800A49D4: bne         $at, $zero, L_800A49E0
    if (ctx->r1 != 0) {
        // 0x800A49D8: lui         $t6, 0x8017
        ctx->r14 = S32(0X8017 << 16);
            goto L_800A49E0;
    }
    // 0x800A49D8: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x800A49DC: addiu       $v1, $zero, 0x1F
    ctx->r3 = ADD32(0, 0X1F);
L_800A49E0:
    // 0x800A49E0: slti        $at, $v0, 0x31
    ctx->r1 = SIGNED(ctx->r2) < 0X31 ? 1 : 0;
    // 0x800A49E4: bne         $at, $zero, L_800A49F0
    if (ctx->r1 != 0) {
        // 0x800A49E8: nop
    
            goto L_800A49F0;
    }
    // 0x800A49E8: nop

    // 0x800A49EC: addiu       $v1, $zero, 0x3F
    ctx->r3 = ADD32(0, 0X3F);
L_800A49F0:
    // 0x800A49F0: beq         $a1, $zero, L_800A4A0C
    if (ctx->r5 == 0) {
        // 0x800A49F4: and         $t8, $a0, $v1
        ctx->r24 = ctx->r4 & ctx->r3;
            goto L_800A4A0C;
    }
    // 0x800A49F4: and         $t8, $a0, $v1
    ctx->r24 = ctx->r4 & ctx->r3;
    // 0x800A49F8: lw          $t6, 0x7880($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7880);
    // 0x800A49FC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A4A00: sra         $t5, $v1, 2
    ctx->r13 = S32(SIGNED(ctx->r3) >> 2);
    // 0x800A4A04: bnel        $t6, $at, L_800A4BEC
    if (ctx->r14 != ctx->r1) {
        // 0x800A4A08: and         $t6, $t5, $a0
        ctx->r14 = ctx->r13 & ctx->r4;
            goto L_800A4BEC;
    }
    goto skip_10;
    // 0x800A4A08: and         $t6, $t5, $a0
    ctx->r14 = ctx->r13 & ctx->r4;
    skip_10:
L_800A4A0C:
    // 0x800A4A0C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800A4A10: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A4A14: swc1        $f10, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f10.u32l;
    // 0x800A4A18: lw          $t7, 0x1CC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1CC);
    // 0x800A4A1C: bne         $t7, $at, L_800A4A30
    if (ctx->r15 != ctx->r1) {
        // 0x800A4A20: lui         $at, 0x41F0
        ctx->r1 = S32(0X41F0 << 16);
            goto L_800A4A30;
    }
    // 0x800A4A20: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x800A4A24: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800A4A28: nop

    // 0x800A4A2C: swc1        $f18, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f18.u32l;
L_800A4A30:
    // 0x800A4A30: bnel        $t8, $zero, L_800A4AD4
    if (ctx->r24 != 0) {
        // 0x800A4A34: sra         $t9, $v1, 2
        ctx->r25 = S32(SIGNED(ctx->r3) >> 2);
            goto L_800A4AD4;
    }
    goto skip_11;
    // 0x800A4A34: sra         $t9, $v1, 2
    ctx->r25 = S32(SIGNED(ctx->r3) >> 2);
    skip_11:
    // 0x800A4A38: jal         0x80004EB0
    // 0x800A4A3C: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    Rand_ZeroOne(rdram, ctx);
        goto after_16;
    // 0x800A4A3C: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    after_16:
    // 0x800A4A40: jal         0x80004EB0
    // 0x800A4A44: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_17;
    // 0x800A4A44: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    after_17:
    // 0x800A4A48: jal         0x80004EB0
    // 0x800A4A4C: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_18;
    // 0x800A4A4C: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    after_18:
    // 0x800A4A50: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800A4A54: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A4A58: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800A4A5C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800A4A60: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800A4A64: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800A4A68: lwc1        $f4, 0x74($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X74);
    // 0x800A4A6C: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800A4A70: lui         $a3, 0x400C
    ctx->r7 = S32(0X400C << 16);
    // 0x800A4A74: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800A4A78: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800A4A7C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800A4A80: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x800A4A84: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800A4A88: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800A4A8C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800A4A90: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800A4A94: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800A4A98: lwc1        $f18, 0x78($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X78);
    // 0x800A4A9C: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800A4AA0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800A4AA4: sub.s       $f18, $f0, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x800A4AA8: add.s       $f14, $f10, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800A4AAC: mul.s       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800A4AB0: lwc1        $f6, 0x138($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X138);
    // 0x800A4AB4: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800A4AB8: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x800A4ABC: jal         0x8007D10C
    // 0x800A4AC0: nop

    Effect_FireSmoke2_Spawn3(rdram, ctx);
        goto after_19;
    // 0x800A4AC0: nop

    after_19:
    // 0x800A4AC4: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x800A4AC8: lw          $a0, 0x7DB0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7DB0);
    // 0x800A4ACC: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x800A4AD0: sra         $t9, $v1, 2
    ctx->r25 = S32(SIGNED(ctx->r3) >> 2);
L_800A4AD4:
    // 0x800A4AD4: and         $t0, $t9, $a0
    ctx->r8 = ctx->r25 & ctx->r4;
    // 0x800A4AD8: bnel        $t0, $zero, L_800A4C30
    if (ctx->r8 != 0) {
        // 0x800A4ADC: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_800A4C30;
    }
    goto skip_12;
    // 0x800A4ADC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_12:
    // 0x800A4AE0: jal         0x80004EB0
    // 0x800A4AE4: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_20;
    // 0x800A4AE4: nop

    after_20:
    // 0x800A4AE8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800A4AEC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800A4AF0: nop

    // 0x800A4AF4: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x800A4AF8: nop

    // 0x800A4AFC: bc1fl       L_800A4C30
    if (!c1cs) {
        // 0x800A4B00: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_800A4C30;
    }
    goto skip_13;
    // 0x800A4B00: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_13:
    // 0x800A4B04: jal         0x80004EB0
    // 0x800A4B08: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_21;
    // 0x800A4B08: nop

    after_21:
    // 0x800A4B0C: jal         0x80004EB0
    // 0x800A4B10: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_22;
    // 0x800A4B10: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    after_22:
    // 0x800A4B14: jal         0x80004EB0
    // 0x800A4B18: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_23;
    // 0x800A4B18: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    after_23:
    // 0x800A4B1C: jal         0x80004EB0
    // 0x800A4B20: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_24;
    // 0x800A4B20: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    after_24:
    // 0x800A4B24: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800A4B28: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800A4B2C: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800A4B30: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x800A4B34: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800A4B38: sub.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x800A4B3C: lwc1        $f4, 0x74($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X74);
    // 0x800A4B40: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800A4B44: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800A4B48: mul.s       $f18, $f6, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800A4B4C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A4B50: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800A4B54: lw          $a3, 0xC0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XC0);
    // 0x800A4B58: mul.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x800A4B5C: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800A4B60: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800A4B64: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800A4B68: lwc1        $f18, 0x78($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X78);
    // 0x800A4B6C: add.s       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800A4B70: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800A4B74: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x800A4B78: sub.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f18.fl;
    // 0x800A4B7C: lwc1        $f6, 0x138($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X138);
    // 0x800A4B80: add.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800A4B84: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800A4B88: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A4B8C: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800A4B90: lwc1        $f4, 0xC4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x800A4B94: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x800A4B98: lwc1        $f8, 0xC8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x800A4B9C: add.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800A4BA0: lwc1        $f10, -0x7CC0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X7CC0);
    // 0x800A4BA4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A4BA8: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x800A4BAC: mul.s       $f6, $f0, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x800A4BB0: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x800A4BB4: lwc1        $f18, -0x7CBC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X7CBC);
    // 0x800A4BB8: add.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x800A4BBC: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x800A4BC0: lw          $t1, 0x1C4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X1C4);
    // 0x800A4BC4: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x800A4BC8: jal         0x8007C484
    // 0x800A4BCC: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    Effect_ElectricArc_Spawn(rdram, ctx);
        goto after_25;
    // 0x800A4BCC: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    after_25:
    // 0x800A4BD0: lw          $t3, 0x224($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X224);
    // 0x800A4BD4: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x800A4BD8: bnel        $t3, $zero, L_800A4C30
    if (ctx->r11 != 0) {
        // 0x800A4BDC: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_800A4C30;
    }
    goto skip_14;
    // 0x800A4BDC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_14:
    // 0x800A4BE0: b           L_800A4C2C
    // 0x800A4BE4: sw          $t4, 0x224($s0)
    MEM_W(0X224, ctx->r16) = ctx->r12;
        goto L_800A4C2C;
    // 0x800A4BE4: sw          $t4, 0x224($s0)
    MEM_W(0X224, ctx->r16) = ctx->r12;
    // 0x800A4BE8: and         $t6, $t5, $a0
    ctx->r14 = ctx->r13 & ctx->r4;
L_800A4BEC:
    // 0x800A4BEC: bnel        $t6, $zero, L_800A4C30
    if (ctx->r14 != 0) {
        // 0x800A4BF0: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_800A4C30;
    }
    goto skip_15;
    // 0x800A4BF0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_15:
    // 0x800A4BF4: jal         0x80004EB0
    // 0x800A4BF8: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_26;
    // 0x800A4BF8: nop

    after_26:
    // 0x800A4BFC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800A4C00: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800A4C04: nop

    // 0x800A4C08: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x800A4C0C: nop

    // 0x800A4C10: bc1fl       L_800A4C30
    if (!c1cs) {
        // 0x800A4C14: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_800A4C30;
    }
    goto skip_16;
    // 0x800A4C14: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_16:
    // 0x800A4C18: lw          $t7, 0x224($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X224);
    // 0x800A4C1C: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x800A4C20: bnel        $t7, $zero, L_800A4C30
    if (ctx->r15 != 0) {
        // 0x800A4C24: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_800A4C30;
    }
    goto skip_17;
    // 0x800A4C24: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_17:
    // 0x800A4C28: sw          $t8, 0x224($s0)
    MEM_W(0X224, ctx->r16) = ctx->r24;
L_800A4C2C:
    // 0x800A4C2C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800A4C30:
    // 0x800A4C30: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800A4C34: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x800A4C38: jr          $ra
    // 0x800A4C3C: nop

    return;
    // 0x800A4C3C: nop

;}
RECOMP_FUNC void Effect_Effect391_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083B8C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80083B90: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80083B94: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80083B98: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80083B9C: jal         0x800BA5B0
    // 0x80083BA0: nop

    RCP_SetupDL_49(rdram, ctx);
        goto after_0;
    // 0x80083BA0: nop

    after_0:
    // 0x80083BA4: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80083BA8: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x80083BAC: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80083BB0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80083BB4: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x80083BB8: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x80083BBC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80083BC0: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80083BC4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80083BC8: lh          $t8, 0x44($t1)
    ctx->r24 = MEM_H(ctx->r9, 0X44);
    // 0x80083BCC: lui         $t4, 0xFB00
    ctx->r12 = S32(0XFB00 << 16);
    // 0x80083BD0: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x80083BD4: or          $t2, $t9, $at
    ctx->r10 = ctx->r25 | ctx->r1;
    // 0x80083BD8: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x80083BDC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80083BE0: lui         $t5, 0x242D
    ctx->r13 = S32(0X242D << 16);
    // 0x80083BE4: ori         $t5, $t5, 0x1CFF
    ctx->r13 = ctx->r13 | 0X1CFF;
    // 0x80083BE8: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x80083BEC: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x80083BF0: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x80083BF4: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80083BF8: lwc1        $f0, 0x70($t1)
    ctx->f0.u32l = MEM_W(ctx->r9, 0X70);
    // 0x80083BFC: lwc1        $f4, 0x64($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X64);
    // 0x80083C00: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80083C04: lw          $a1, 0x60($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X60);
    // 0x80083C08: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80083C0C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80083C10: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80083C14: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80083C18: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80083C1C: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80083C20: jal         0x80005C34
    // 0x80083C24: nop

    Matrix_Scale(rdram, ctx);
        goto after_1;
    // 0x80083C24: nop

    after_1:
    // 0x80083C28: jal         0x80006EB8
    // 0x80083C2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_2;
    // 0x80083C2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80083C30: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80083C34: lui         $t9, 0x602
    ctx->r25 = S32(0X602 << 16);
    // 0x80083C38: addiu       $t9, $t9, -0x4530
    ctx->r25 = ADD32(ctx->r25, -0X4530);
    // 0x80083C3C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80083C40: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80083C44: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x80083C48: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80083C4C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80083C50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80083C54: jal         0x800B8DD0
    // 0x80083C58: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    RCP_SetupDL(rdram, ctx);
        goto after_3;
    // 0x80083C58: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_3:
    // 0x80083C5C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80083C60: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80083C64: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80083C68: jr          $ra
    // 0x80083C6C: nop

    return;
    // 0x80083C6C: nop

;}
RECOMP_FUNC void Boss_CompleteLevel(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004319C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800431A0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800431A4: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800431A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800431AC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800431B0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800431B4: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800431B8: lui         $a0, 0x1050
    ctx->r4 = S32(0X1050 << 16);
    // 0x800431BC: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    // 0x800431C0: jal         0x800182F4
    // 0x800431C4: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_0;
    // 0x800431C4: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x800431C8: lui         $a0, 0x1150
    ctx->r4 = S32(0X1150 << 16);
    // 0x800431CC: jal         0x800182F4
    // 0x800431D0: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_1;
    // 0x800431D0: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    after_1:
    // 0x800431D4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800431D8: sw          $zero, 0x7A80($at)
    MEM_W(0X7A80, ctx->r1) = 0;
    // 0x800431DC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800431E0: lwc1        $f6, 0x7D20($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x800431E4: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800431E8: lwc1        $f10, 0x1C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800431EC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800431F0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800431F4: lwc1        $f16, 0x20($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800431F8: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800431FC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80043200: swc1        $f8, -0x7BB8($at)
    MEM_W(-0X7BB8, ctx->r1) = ctx->f8.u32l;
    // 0x80043204: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80043208: swc1        $f10, -0x7BC0($at)
    MEM_W(-0X7BC0, ctx->r1) = ctx->f10.u32l;
    // 0x8004320C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80043210: swc1        $f16, -0x7BBC($at)
    MEM_W(-0X7BBC, ctx->r1) = ctx->f16.u32l;
    // 0x80043214: lwc1        $f6, 0xAC($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0XAC);
    // 0x80043218: lwc1        $f4, 0x74($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X74);
    // 0x8004321C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80043220: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80043224: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80043228: addiu       $v0, $zero, 0x32
    ctx->r2 = ADD32(0, 0X32);
    // 0x8004322C: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
    // 0x80043230: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x80043234: sw          $t6, 0x1C8($a1)
    MEM_W(0X1C8, ctx->r5) = ctx->r14;
    // 0x80043238: sw          $t7, 0x1D0($a1)
    MEM_W(0X1D0, ctx->r5) = ctx->r15;
    // 0x8004323C: sw          $v0, 0x1F8($a1)
    MEM_W(0X1F8, ctx->r5) = ctx->r2;
    // 0x80043240: sw          $v0, 0x1FC($a1)
    MEM_W(0X1FC, ctx->r5) = ctx->r2;
    // 0x80043244: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
    // 0x80043248: bc1f        L_80043260
    if (!c1cs) {
        // 0x8004324C: swc1        $f18, 0x4($a1)
        MEM_W(0X4, ctx->r5) = ctx->f18.u32l;
            goto L_80043260;
    }
    // 0x8004324C: swc1        $f18, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f18.u32l;
    // 0x80043250: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80043254: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80043258: nop

    // 0x8004325C: swc1        $f8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f8.u32l;
L_80043260:
    // 0x80043260: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80043264: lw          $t8, -0x7D80($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7D80);
    // 0x80043268: swc1        $f0, 0xC0($t8)
    MEM_W(0XC0, ctx->r24) = ctx->f0.u32l;
    // 0x8004326C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80043270: jr          $ra
    // 0x80043274: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80043274: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_enmy_80063F58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063F58: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80063F5C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80063F60: lwc1        $f4, 0x18($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X18);
    // 0x80063F64: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80063F68: swc1        $f8, 0x68($a0)
    MEM_W(0X68, ctx->r4) = ctx->f8.u32l;
    // 0x80063F6C: jr          $ra
    // 0x80063F70: nop

    return;
    // 0x80063F70: nop

;}
RECOMP_FUNC void Audio_NoteInitForLayer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80012CEC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80012CF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80012CF4: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80012CF8: sw          $t6, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->r14;
    // 0x80012CFC: sw          $a1, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->r5;
    // 0x80012D00: lw          $t7, 0x4C($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X4C);
    // 0x80012D04: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x80012D08: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80012D0C: lbu         $t8, 0x5($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X5);
    // 0x80012D10: sb          $t8, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r24;
    // 0x80012D14: lbu         $t0, 0x0($a1)
    ctx->r8 = MEM_BU(ctx->r5, 0X0);
    // 0x80012D18: lw          $t3, 0x4C($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X4C);
    // 0x80012D1C: sb          $t2, 0x3($a1)
    MEM_B(0X3, ctx->r5) = ctx->r10;
    // 0x80012D20: ori         $t1, $t0, 0x4
    ctx->r9 = ctx->r8 | 0X4;
    // 0x80012D24: sb          $t1, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r9;
    // 0x80012D28: sw          $a0, 0x40($a1)
    MEM_W(0X40, ctx->r5) = ctx->r4;
    // 0x80012D2C: sw          $a0, 0x38($t3)
    MEM_W(0X38, ctx->r11) = ctx->r4;
    // 0x80012D30: lw          $t4, 0x4C($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X4C);
    // 0x80012D34: sw          $a1, 0x3C($t4)
    MEM_W(0X3C, ctx->r12) = ctx->r5;
    // 0x80012D38: swc1        $f4, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->f4.u32l;
    // 0x80012D3C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80012D40: jal         0x80011EB8
    // 0x80012D44: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    Audio_NoteInit(rdram, ctx);
        goto after_0;
    // 0x80012D44: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    after_0:
    // 0x80012D48: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80012D4C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80012D50: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80012D54: lbu         $a2, 0x2($a1)
    ctx->r6 = MEM_BU(ctx->r5, 0X2);
    // 0x80012D58: addiu       $v0, $a0, 0xB0
    ctx->r2 = ADD32(ctx->r4, 0XB0);
    // 0x80012D5C: bnel        $a2, $at, L_80012D70
    if (ctx->r6 != ctx->r1) {
        // 0x80012D60: lw          $t6, 0x48($a1)
        ctx->r14 = MEM_W(ctx->r5, 0X48);
            goto L_80012D70;
    }
    goto skip_0;
    // 0x80012D60: lw          $t6, 0x48($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X48);
    skip_0:
    // 0x80012D64: lw          $t5, 0x4C($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X4C);
    // 0x80012D68: lh          $a2, 0x1C($t5)
    ctx->r6 = MEM_H(ctx->r13, 0X1C);
    // 0x80012D6C: lw          $t6, 0x48($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X48);
L_80012D70:
    // 0x80012D70: slti        $at, $a2, 0x80
    ctx->r1 = SIGNED(ctx->r6) < 0X80 ? 1 : 0;
    // 0x80012D74: bne         $at, $zero, L_80012D8C
    if (ctx->r1 != 0) {
        // 0x80012D78: sw          $t6, 0xC($v0)
        MEM_W(0XC, ctx->r2) = ctx->r14;
            goto L_80012D8C;
    }
    // 0x80012D78: sw          $t6, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r14;
    // 0x80012D7C: lbu         $t8, 0x1($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X1);
    // 0x80012D80: ori         $t9, $t8, 0x2
    ctx->r25 = ctx->r24 | 0X2;
    // 0x80012D84: b           L_80012D98
    // 0x80012D88: sb          $t9, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r25;
        goto L_80012D98;
    // 0x80012D88: sb          $t9, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r25;
L_80012D8C:
    // 0x80012D8C: lbu         $t0, 0x1($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X1);
    // 0x80012D90: andi        $t1, $t0, 0xFFFD
    ctx->r9 = ctx->r8 & 0XFFFD;
    // 0x80012D94: sb          $t1, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r9;
L_80012D98:
    // 0x80012D98: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x80012D9C: sll         $t4, $t2, 14
    ctx->r12 = S32(ctx->r10 << 14);
    // 0x80012DA0: bgezl       $t4, L_80012DC8
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80012DA4: lw          $t5, 0x4C($a1)
        ctx->r13 = MEM_W(ctx->r5, 0X4C);
            goto L_80012DC8;
    }
    goto skip_1;
    // 0x80012DA4: lw          $t5, 0x4C($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X4C);
    skip_1:
    // 0x80012DA8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80012DAC: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80012DB0: jal         0x800126AC
    // 0x80012DB4: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    Audio_BuildSyntheticWave(rdram, ctx);
        goto after_1;
    // 0x80012DB4: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    after_1:
    // 0x80012DB8: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80012DBC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80012DC0: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80012DC4: lw          $t5, 0x4C($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X4C);
L_80012DC8:
    // 0x80012DC8: lbu         $t6, 0x6($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X6);
    // 0x80012DCC: sb          $t6, 0x33($a0)
    MEM_B(0X33, ctx->r4) = ctx->r14;
    // 0x80012DD0: lw          $t7, 0x4C($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X4C);
    // 0x80012DD4: lbu         $t3, 0x0($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X0);
    // 0x80012DD8: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80012DDC: andi        $t4, $t3, 0xFFFD
    ctx->r12 = ctx->r11 & 0XFFFD;
    // 0x80012DE0: lbu         $t3, 0x1($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X1);
    // 0x80012DE4: sll         $t9, $t8, 5
    ctx->r25 = S32(ctx->r24 << 5);
    // 0x80012DE8: srl         $t0, $t9, 31
    ctx->r8 = S32(U32(ctx->r25) >> 31);
    // 0x80012DEC: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x80012DF0: andi        $t2, $t1, 0x2
    ctx->r10 = ctx->r9 & 0X2;
    // 0x80012DF4: or          $t5, $t2, $t4
    ctx->r13 = ctx->r10 | ctx->r12;
    // 0x80012DF8: sb          $t5, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r13;
    // 0x80012DFC: lw          $t6, 0x4C($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X4C);
    // 0x80012E00: andi        $t2, $t3, 0xFF1F
    ctx->r10 = ctx->r11 & 0XFF1F;
    // 0x80012E04: lbu         $t7, 0x7($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X7);
    // 0x80012E08: andi        $t9, $t7, 0x3
    ctx->r25 = ctx->r15 & 0X3;
    // 0x80012E0C: sll         $t1, $t9, 5
    ctx->r9 = S32(ctx->r25 << 5);
    // 0x80012E10: or          $t4, $t1, $t2
    ctx->r12 = ctx->r9 | ctx->r10;
    // 0x80012E14: sb          $t4, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r12;
    // 0x80012E18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80012E1C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80012E20: jr          $ra
    // 0x80012E24: nop

    return;
    // 0x80012E24: nop

;}
RECOMP_FUNC void BoShieldReactor_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002E670: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002E674: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002E678: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8002E67C: jal         0x80187520
    // 0x8002E680: addiu       $a0, $zero, 0x5F
    ctx->r4 = ADD32(0, 0X5F);
    LOOKUP_FUNC(0x80187520)(rdram, ctx);
        goto after_0;
    // 0x8002E680: addiu       $a0, $zero, 0x5F
    ctx->r4 = ADD32(0, 0X5F);
    after_0:
    // 0x8002E684: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002E688: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002E68C: jr          $ra
    // 0x8002E690: nop

    return;
    // 0x8002E690: nop

;}
RECOMP_FUNC void Player_Update360(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B44C4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800B44C8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800B44CC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800B44D0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800B44D4: lw          $v0, 0x1CC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1CC);
    // 0x800B44D8: beq         $v0, $zero, L_800B4500
    if (ctx->r2 == 0) {
        // 0x800B44DC: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_800B4500;
    }
    // 0x800B44DC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800B44E0: beq         $v0, $at, L_800B460C
    if (ctx->r2 == ctx->r1) {
        // 0x800B44E4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800B460C;
    }
    // 0x800B44E4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800B44E8: beq         $v0, $at, L_800B4684
    if (ctx->r2 == ctx->r1) {
        // 0x800B44EC: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800B4684;
    }
    // 0x800B44EC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800B44F0: beq         $v0, $at, L_800B4694
    if (ctx->r2 == ctx->r1) {
        // 0x800B44F4: nop
    
            goto L_800B4694;
    }
    // 0x800B44F4: nop

    // 0x800B44F8: b           L_800B46E8
    // 0x800B44FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800B46E8;
    // 0x800B44FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800B4500:
    // 0x800B4500: jal         0x800ADA28
    // 0x800B4504: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_ArwingBank(rdram, ctx);
        goto after_0;
    // 0x800B4504: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800B4508: jal         0x800B2574
    // 0x800B450C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_ArwingBoost(rdram, ctx);
        goto after_1;
    // 0x800B450C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800B4510: jal         0x800B2C00
    // 0x800B4514: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_ArwingBrake(rdram, ctx);
        goto after_2;
    // 0x800B4514: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800B4518: jal         0x800B41E0
    // 0x800B451C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Play_dummy_800B41E0(rdram, ctx);
        goto after_3;
    // 0x800B451C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x800B4520: jal         0x800B2130
    // 0x800B4524: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_UpdateArwingRoll(rdram, ctx);
        goto after_4;
    // 0x800B4524: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x800B4528: lw          $t6, 0x4DC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4DC);
    // 0x800B452C: beq         $t6, $zero, L_800B4544
    if (ctx->r14 == 0) {
        // 0x800B4530: nop
    
            goto L_800B4544;
    }
    // 0x800B4530: nop

    // 0x800B4534: jal         0x800AECAC
    // 0x800B4538: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_PerformLoop(rdram, ctx);
        goto after_5;
    // 0x800B4538: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x800B453C: b           L_800B454C
    // 0x800B4540: nop

        goto L_800B454C;
    // 0x800B4540: nop

L_800B4544:
    // 0x800B4544: jal         0x800AE4A4
    // 0x800B4548: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_MoveArwing360(rdram, ctx);
        goto after_6;
    // 0x800B4548: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
L_800B454C:
    // 0x800B454C: jal         0x800AD7F0
    // 0x800B4550: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_Shoot(rdram, ctx);
        goto after_7;
    // 0x800B4550: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x800B4554: jal         0x800A8BA4
    // 0x800B4558: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_CollisionCheck(rdram, ctx);
        goto after_8;
    // 0x800B4558: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x800B455C: jal         0x800A4C40
    // 0x800B4560: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_WaterEffects(rdram, ctx);
        goto after_9;
    // 0x800B4560: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x800B4564: jal         0x800AA800
    // 0x800B4568: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_FloorCheck(rdram, ctx);
        goto after_10;
    // 0x800B4568: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x800B456C: jal         0x800B415C
    // 0x800B4570: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_LowHealthAlarm(rdram, ctx);
        goto after_11;
    // 0x800B4570: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x800B4574: lw          $t7, 0x264($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X264);
    // 0x800B4578: bgtzl       $t7, L_800B46E8
    if (SIGNED(ctx->r15) > 0) {
        // 0x800B457C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800B46E8;
    }
    goto skip_0;
    // 0x800B457C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x800B4580: lw          $t8, 0x220($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X220);
    // 0x800B4584: beql        $t8, $zero, L_800B46E8
    if (ctx->r24 == 0) {
        // 0x800B4588: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800B46E8;
    }
    goto skip_1;
    // 0x800B4588: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x800B458C: jal         0x800B41EC
    // 0x800B4590: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_Down(rdram, ctx);
        goto after_12;
    // 0x800B4590: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x800B4594: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x800B4598: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800B459C: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x800B45A0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800B45A4: swc1        $f4, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f4.u32l;
    // 0x800B45A8: lbu         $t9, 0x7C98($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X7C98);
    // 0x800B45AC: addiu       $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
    // 0x800B45B0: addiu       $t1, $zero, 0x78
    ctx->r9 = ADD32(0, 0X78);
    // 0x800B45B4: bnel        $t9, $at, L_800B45CC
    if (ctx->r25 != ctx->r1) {
        // 0x800B45B8: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_800B45CC;
    }
    goto skip_2;
    // 0x800B45B8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_2:
    // 0x800B45BC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800B45C0: nop

    // 0x800B45C4: swc1        $f0, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f0.u32l;
    // 0x800B45C8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_800B45CC:
    // 0x800B45CC: lwc1        $f8, 0xE8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XE8);
    // 0x800B45D0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800B45D4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800B45D8: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x800B45DC: sw          $t0, 0x1F8($s0)
    MEM_W(0X1F8, ctx->r16) = ctx->r8;
    // 0x800B45E0: sw          $t1, 0x1FC($s0)
    MEM_W(0X1FC, ctx->r16) = ctx->r9;
    // 0x800B45E4: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
    // 0x800B45E8: bc1f        L_800B4600
    if (!c1cs) {
        // 0x800B45EC: swc1        $f6, 0x4($s0)
        MEM_W(0X4, ctx->r16) = ctx->f6.u32l;
            goto L_800B4600;
    }
    // 0x800B45EC: swc1        $f6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f6.u32l;
    // 0x800B45F0: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x800B45F4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800B45F8: nop

    // 0x800B45FC: swc1        $f10, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f10.u32l;
L_800B4600:
    // 0x800B4600: swc1        $f0, 0xE4($s0)
    MEM_W(0XE4, ctx->r16) = ctx->f0.u32l;
    // 0x800B4604: b           L_800B46E4
    // 0x800B4608: swc1        $f0, 0x4D8($s0)
    MEM_W(0X4D8, ctx->r16) = ctx->f0.u32l;
        goto L_800B46E4;
    // 0x800B4608: swc1        $f0, 0x4D8($s0)
    MEM_W(0X4D8, ctx->r16) = ctx->f0.u32l;
L_800B460C:
    // 0x800B460C: jal         0x800ADD98
    // 0x800B4610: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_UseTankJets(rdram, ctx);
        goto after_13;
    // 0x800B4610: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x800B4614: jal         0x800B3314
    // 0x800B4618: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_UpdateTankJets(rdram, ctx);
        goto after_14;
    // 0x800B4618: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x800B461C: jal         0x800B3010
    // 0x800B4620: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_TankBoostBrake(rdram, ctx);
        goto after_15;
    // 0x800B4620: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x800B4624: jal         0x800B41E0
    // 0x800B4628: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Play_dummy_800B41E0(rdram, ctx);
        goto after_16;
    // 0x800B4628: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x800B462C: jal         0x800B22C0
    // 0x800B4630: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_UpdateTankRoll(rdram, ctx);
        goto after_17;
    // 0x800B4630: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x800B4634: jal         0x800AF928
    // 0x800B4638: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_MoveTank360(rdram, ctx);
        goto after_18;
    // 0x800B4638: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x800B463C: jal         0x800AD7F0
    // 0x800B4640: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_Shoot(rdram, ctx);
        goto after_19;
    // 0x800B4640: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x800B4644: jal         0x800A8BA4
    // 0x800B4648: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_CollisionCheck(rdram, ctx);
        goto after_20;
    // 0x800B4648: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x800B464C: jal         0x800AA800
    // 0x800B4650: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_FloorCheck(rdram, ctx);
        goto after_21;
    // 0x800B4650: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x800B4654: jal         0x800B415C
    // 0x800B4658: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_LowHealthAlarm(rdram, ctx);
        goto after_22;
    // 0x800B4658: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x800B465C: lw          $t2, 0x264($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X264);
    // 0x800B4660: bgtzl       $t2, L_800B46E8
    if (SIGNED(ctx->r10) > 0) {
        // 0x800B4664: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800B46E8;
    }
    goto skip_3;
    // 0x800B4664: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x800B4668: lw          $t3, 0x220($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X220);
    // 0x800B466C: beql        $t3, $zero, L_800B46E8
    if (ctx->r11 == 0) {
        // 0x800B4670: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800B46E8;
    }
    goto skip_4;
    // 0x800B4670: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x800B4674: jal         0x800B41EC
    // 0x800B4678: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_Down(rdram, ctx);
        goto after_23;
    // 0x800B4678: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x800B467C: b           L_800B46E8
    // 0x800B4680: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800B46E8;
    // 0x800B4680: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800B4684:
    // 0x800B4684: jal         0x801BEC80
    // 0x800B4688: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Aquas_Update360(rdram, ctx);
        goto after_24;
    // 0x800B4688: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x800B468C: b           L_800B46E8
    // 0x800B4690: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800B46E8;
    // 0x800B4690: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800B4694:
    // 0x800B4694: jal         0x800B00C0
    // 0x800B4698: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_OnFootUpdateSpeed(rdram, ctx);
        goto after_25;
    // 0x800B4698: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_25:
    // 0x800B469C: jal         0x800B0194
    // 0x800B46A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_MoveOnFoot(rdram, ctx);
        goto after_26;
    // 0x800B46A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_26:
    // 0x800B46A4: jal         0x800AD7F0
    // 0x800B46A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_Shoot(rdram, ctx);
        goto after_27;
    // 0x800B46A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_27:
    // 0x800B46AC: jal         0x800A8BA4
    // 0x800B46B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_CollisionCheck(rdram, ctx);
        goto after_28;
    // 0x800B46B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_28:
    // 0x800B46B4: jal         0x800AA800
    // 0x800B46B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_FloorCheck(rdram, ctx);
        goto after_29;
    // 0x800B46B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_29:
    // 0x800B46BC: jal         0x800B415C
    // 0x800B46C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_LowHealthAlarm(rdram, ctx);
        goto after_30;
    // 0x800B46C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_30:
    // 0x800B46C4: lw          $t4, 0x264($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X264);
    // 0x800B46C8: bgtzl       $t4, L_800B46E8
    if (SIGNED(ctx->r12) > 0) {
        // 0x800B46CC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800B46E8;
    }
    goto skip_5;
    // 0x800B46CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_5:
    // 0x800B46D0: lw          $t5, 0x220($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X220);
    // 0x800B46D4: beql        $t5, $zero, L_800B46E8
    if (ctx->r13 == 0) {
        // 0x800B46D8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800B46E8;
    }
    goto skip_6;
    // 0x800B46D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_6:
    // 0x800B46DC: jal         0x800B41EC
    // 0x800B46E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_Down(rdram, ctx);
        goto after_31;
    // 0x800B46E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_31:
L_800B46E4:
    // 0x800B46E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800B46E8:
    // 0x800B46E8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800B46EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800B46F0: jr          $ra
    // 0x800B46F4: nop

    return;
    // 0x800B46F4: nop

;}
RECOMP_FUNC void Display_ArwingOverrideLimbDraw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800531A4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800531A8: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800531AC: addiu       $v1, $v1, -0x5DD4
    ctx->r3 = ADD32(ctx->r3, -0X5DD4);
    // 0x800531B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800531B4: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x800531B8: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x800531BC: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x800531C0: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800531C4: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800531C8: beql        $t6, $zero, L_8005320C
    if (ctx->r14 == 0) {
        // 0x800531CC: lw          $t9, 0x40($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X40);
            goto L_8005320C;
    }
    goto skip_0;
    // 0x800531CC: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    skip_0:
    // 0x800531D0: lw          $t7, -0x7D80($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7D80);
    // 0x800531D4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800531D8: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x800531DC: lw          $t8, 0x200($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X200);
    // 0x800531E0: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    // 0x800531E4: bnel        $t8, $zero, L_8005320C
    if (ctx->r24 != 0) {
        // 0x800531E8: lw          $t9, 0x40($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X40);
            goto L_8005320C;
    }
    goto skip_1;
    // 0x800531E8: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    skip_1:
    // 0x800531EC: jal         0x800B8DD0
    // 0x800531F0: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x800531F0: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    after_0:
    // 0x800531F4: jal         0x8005314C
    // 0x800531F8: nop

    Display_SetCullingMode(rdram, ctx);
        goto after_1;
    // 0x800531F8: nop

    after_1:
    // 0x800531FC: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80053200: addiu       $v1, $v1, -0x5DD4
    ctx->r3 = ADD32(ctx->r3, -0X5DD4);
    // 0x80053204: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x80053208: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
L_8005320C:
    // 0x8005320C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80053210: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x80053214: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x80053218: sltiu       $at, $t0, 0xD
    ctx->r1 = ctx->r8 < 0XD ? 1 : 0;
    // 0x8005321C: beq         $at, $zero, L_80053554
    if (ctx->r1 == 0) {
        // 0x80053220: sw          $t9, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r25;
            goto L_80053554;
    }
    // 0x80053220: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x80053224: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80053228: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005322C: addu        $at, $at, $t0
    gpr jr_addend_80053234 = ctx->r8;
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80053230: lw          $t0, 0x5E10($at)
    ctx->r8 = ADD32(ctx->r1, 0X5E10);
    // 0x80053234: jr          $t0
    // 0x80053238: nop

    switch (jr_addend_80053234 >> 2) {
        case 0: goto L_80053310; break;
        case 1: goto L_80053310; break;
        case 2: goto L_80053554; break;
        case 3: goto L_80053554; break;
        case 4: goto L_800534A0; break;
        case 5: goto L_800534A0; break;
        case 6: goto L_80053554; break;
        case 7: goto L_80053554; break;
        case 8: goto L_80053554; break;
        case 9: goto L_80053554; break;
        case 10: goto L_80053554; break;
        case 11: goto L_800533CC; break;
        case 12: goto L_8005323C; break;
        default: switch_error(__func__, 0x80053234, 0x800D5E10);
    }
    // 0x80053238: nop

L_8005323C:
    // 0x8005323C: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x80053240: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x80053244: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80053248: lbu         $v0, 0x0($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X0);
    // 0x8005324C: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x80053250: bne         $v0, $zero, L_80053260
    if (ctx->r2 != 0) {
        // 0x80053254: nop
    
            goto L_80053260;
    }
    // 0x80053254: nop

    // 0x80053258: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
    // 0x8005325C: lbu         $v0, 0x0($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X0);
L_80053260:
    // 0x80053260: bne         $v0, $at, L_80053274
    if (ctx->r2 != ctx->r1) {
        // 0x80053264: lw          $t3, 0x44($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X44);
            goto L_80053274;
    }
    // 0x80053264: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x80053268: lui         $t2, 0x301
    ctx->r10 = S32(0X301 << 16);
    // 0x8005326C: addiu       $t2, $t2, 0x5120
    ctx->r10 = ADD32(ctx->r10, 0X5120);
    // 0x80053270: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
L_80053274:
    // 0x80053274: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x80053278: beql        $t4, $zero, L_80053558
    if (ctx->r12 == 0) {
        // 0x8005327C: lw          $t3, 0x18($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X18);
            goto L_80053558;
    }
    goto skip_2;
    // 0x8005327C: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    skip_2:
    // 0x80053280: lw          $t5, 0x7D40($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7D40);
    // 0x80053284: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    // 0x80053288: andi        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 & 0X1;
    // 0x8005328C: beql        $t6, $zero, L_80053558
    if (ctx->r14 == 0) {
        // 0x80053290: lw          $t3, 0x18($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X18);
            goto L_80053558;
    }
    goto skip_3;
    // 0x80053290: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    skip_3:
    // 0x80053294: jal         0x800B8DD0
    // 0x80053298: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    RCP_SetupDL(rdram, ctx);
        goto after_2;
    // 0x80053298: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    after_2:
    // 0x8005329C: jal         0x8005314C
    // 0x800532A0: nop

    Display_SetCullingMode(rdram, ctx);
        goto after_3;
    // 0x800532A0: nop

    after_3:
    // 0x800532A4: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x800532A8: lw          $t7, 0x7D40($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7D40);
    // 0x800532AC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800532B0: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x800532B4: slti        $at, $t7, 0x3E9
    ctx->r1 = SIGNED(ctx->r15) < 0X3E9 ? 1 : 0;
    // 0x800532B8: bne         $at, $zero, L_800532E8
    if (ctx->r1 != 0) {
        // 0x800532BC: lw          $a3, 0x4C($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X4C);
            goto L_800532E8;
    }
    // 0x800532BC: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x800532C0: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800532C4: lui         $t0, 0x2020
    ctx->r8 = S32(0X2020 << 16);
    // 0x800532C8: ori         $t0, $t0, 0xFFFF
    ctx->r8 = ctx->r8 | 0XFFFF;
    // 0x800532CC: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x800532D0: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800532D4: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x800532D8: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800532DC: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x800532E0: b           L_80053558
    // 0x800532E4: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
        goto L_80053558;
    // 0x800532E4: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
L_800532E8:
    // 0x800532E8: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800532EC: lui         $t3, 0xFF00
    ctx->r11 = S32(0XFF00 << 16);
    // 0x800532F0: ori         $t3, $t3, 0xFF
    ctx->r11 = ctx->r11 | 0XFF;
    // 0x800532F4: addiu       $t1, $v1, 0x8
    ctx->r9 = ADD32(ctx->r3, 0X8);
    // 0x800532F8: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x800532FC: lui         $t2, 0xFA00
    ctx->r10 = S32(0XFA00 << 16);
    // 0x80053300: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x80053304: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x80053308: b           L_80053558
    // 0x8005330C: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
        goto L_80053558;
    // 0x8005330C: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
L_80053310:
    // 0x80053310: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x80053314: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80053318: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x8005331C: lbu         $t4, 0x0($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0X0);
    // 0x80053320: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x80053324: beql        $t4, $at, L_80053334
    if (ctx->r12 == ctx->r1) {
        // 0x80053328: lw          $t6, 0x0($v1)
        ctx->r14 = MEM_W(ctx->r3, 0X0);
            goto L_80053334;
    }
    goto skip_4;
    // 0x80053328: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    skip_4:
    // 0x8005332C: sw          $zero, 0x0($t5)
    MEM_W(0X0, ctx->r13) = 0;
    // 0x80053330: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
L_80053334:
    // 0x80053334: beql        $t6, $zero, L_80053558
    if (ctx->r14 == 0) {
        // 0x80053338: lw          $t3, 0x18($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X18);
            goto L_80053558;
    }
    goto skip_5;
    // 0x80053338: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    skip_5:
    // 0x8005333C: lw          $t7, 0x7D40($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7D40);
    // 0x80053340: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    // 0x80053344: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x80053348: beql        $t8, $zero, L_80053558
    if (ctx->r24 == 0) {
        // 0x8005334C: lw          $t3, 0x18($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X18);
            goto L_80053558;
    }
    goto skip_6;
    // 0x8005334C: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    skip_6:
    // 0x80053350: jal         0x800B8DD0
    // 0x80053354: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    RCP_SetupDL(rdram, ctx);
        goto after_4;
    // 0x80053354: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    after_4:
    // 0x80053358: jal         0x8005314C
    // 0x8005335C: nop

    Display_SetCullingMode(rdram, ctx);
        goto after_5;
    // 0x8005335C: nop

    after_5:
    // 0x80053360: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x80053364: lw          $t9, 0x7D40($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7D40);
    // 0x80053368: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8005336C: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x80053370: slti        $at, $t9, 0x3E9
    ctx->r1 = SIGNED(ctx->r25) < 0X3E9 ? 1 : 0;
    // 0x80053374: bne         $at, $zero, L_800533A4
    if (ctx->r1 != 0) {
        // 0x80053378: lw          $a3, 0x4C($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X4C);
            goto L_800533A4;
    }
    // 0x80053378: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x8005337C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80053380: lui         $t2, 0x2020
    ctx->r10 = S32(0X2020 << 16);
    // 0x80053384: ori         $t2, $t2, 0xFFFF
    ctx->r10 = ctx->r10 | 0XFFFF;
    // 0x80053388: addiu       $t0, $v1, 0x8
    ctx->r8 = ADD32(ctx->r3, 0X8);
    // 0x8005338C: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
    // 0x80053390: lui         $t1, 0xFA00
    ctx->r9 = S32(0XFA00 << 16);
    // 0x80053394: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x80053398: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x8005339C: b           L_80053558
    // 0x800533A0: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
        goto L_80053558;
    // 0x800533A0: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
L_800533A4:
    // 0x800533A4: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800533A8: lui         $t5, 0xFF00
    ctx->r13 = S32(0XFF00 << 16);
    // 0x800533AC: ori         $t5, $t5, 0xFF
    ctx->r13 = ctx->r13 | 0XFF;
    // 0x800533B0: addiu       $t3, $v1, 0x8
    ctx->r11 = ADD32(ctx->r3, 0X8);
    // 0x800533B4: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x800533B8: lui         $t4, 0xFA00
    ctx->r12 = S32(0XFA00 << 16);
    // 0x800533BC: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x800533C0: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x800533C4: b           L_80053558
    // 0x800533C8: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
        goto L_80053558;
    // 0x800533C8: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
L_800533CC:
    // 0x800533CC: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x800533D0: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x800533D4: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x800533D8: lbu         $t6, 0x0($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X0);
    // 0x800533DC: bnel        $t6, $zero, L_800533EC
    if (ctx->r14 != 0) {
        // 0x800533E0: lbu         $t8, 0x1($a2)
        ctx->r24 = MEM_BU(ctx->r6, 0X1);
            goto L_800533EC;
    }
    goto skip_7;
    // 0x800533E0: lbu         $t8, 0x1($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X1);
    skip_7:
    // 0x800533E4: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
    // 0x800533E8: lbu         $t8, 0x1($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X1);
L_800533EC:
    // 0x800533EC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800533F0: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x800533F4: bne         $t8, $at, L_80053404
    if (ctx->r24 != ctx->r1) {
        // 0x800533F8: lui         $t9, 0x301
        ctx->r25 = S32(0X301 << 16);
            goto L_80053404;
    }
    // 0x800533F8: lui         $t9, 0x301
    ctx->r25 = S32(0X301 << 16);
    // 0x800533FC: addiu       $t9, $t9, 0x4BF0
    ctx->r25 = ADD32(ctx->r25, 0X4BF0);
    // 0x80053400: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
L_80053404:
    // 0x80053404: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x80053408: beql        $t1, $zero, L_80053558
    if (ctx->r9 == 0) {
        // 0x8005340C: lw          $t3, 0x18($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X18);
            goto L_80053558;
    }
    goto skip_8;
    // 0x8005340C: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    skip_8:
    // 0x80053410: lw          $t2, 0x7D58($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7D58);
    // 0x80053414: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    // 0x80053418: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x8005341C: beql        $t3, $zero, L_80053558
    if (ctx->r11 == 0) {
        // 0x80053420: lw          $t3, 0x18($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X18);
            goto L_80053558;
    }
    goto skip_9;
    // 0x80053420: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    skip_9:
    // 0x80053424: jal         0x800B8DD0
    // 0x80053428: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    RCP_SetupDL(rdram, ctx);
        goto after_6;
    // 0x80053428: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    after_6:
    // 0x8005342C: jal         0x8005314C
    // 0x80053430: nop

    Display_SetCullingMode(rdram, ctx);
        goto after_7;
    // 0x80053430: nop

    after_7:
    // 0x80053434: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x80053438: lw          $t4, 0x7D58($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7D58);
    // 0x8005343C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80053440: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x80053444: slti        $at, $t4, 0x3E9
    ctx->r1 = SIGNED(ctx->r12) < 0X3E9 ? 1 : 0;
    // 0x80053448: bne         $at, $zero, L_80053478
    if (ctx->r1 != 0) {
        // 0x8005344C: lw          $a3, 0x4C($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X4C);
            goto L_80053478;
    }
    // 0x8005344C: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x80053450: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80053454: lui         $t7, 0x2020
    ctx->r15 = S32(0X2020 << 16);
    // 0x80053458: ori         $t7, $t7, 0xFFFF
    ctx->r15 = ctx->r15 | 0XFFFF;
    // 0x8005345C: addiu       $t5, $v1, 0x8
    ctx->r13 = ADD32(ctx->r3, 0X8);
    // 0x80053460: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x80053464: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x80053468: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8005346C: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80053470: b           L_80053558
    // 0x80053474: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
        goto L_80053558;
    // 0x80053474: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
L_80053478:
    // 0x80053478: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8005347C: lui         $t0, 0xFF00
    ctx->r8 = S32(0XFF00 << 16);
    // 0x80053480: ori         $t0, $t0, 0xFF
    ctx->r8 = ctx->r8 | 0XFF;
    // 0x80053484: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80053488: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8005348C: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x80053490: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80053494: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x80053498: b           L_80053558
    // 0x8005349C: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
        goto L_80053558;
    // 0x8005349C: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
L_800534A0:
    // 0x800534A0: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x800534A4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800534A8: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x800534AC: lbu         $t1, 0x1($a2)
    ctx->r9 = MEM_BU(ctx->r6, 0X1);
    // 0x800534B0: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x800534B4: beql        $t1, $at, L_800534C4
    if (ctx->r9 == ctx->r1) {
        // 0x800534B8: lw          $t3, 0x0($v1)
        ctx->r11 = MEM_W(ctx->r3, 0X0);
            goto L_800534C4;
    }
    goto skip_10;
    // 0x800534B8: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    skip_10:
    // 0x800534BC: sw          $zero, 0x0($t2)
    MEM_W(0X0, ctx->r10) = 0;
    // 0x800534C0: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
L_800534C4:
    // 0x800534C4: beql        $t3, $zero, L_80053558
    if (ctx->r11 == 0) {
        // 0x800534C8: lw          $t3, 0x18($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X18);
            goto L_80053558;
    }
    goto skip_11;
    // 0x800534C8: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    skip_11:
    // 0x800534CC: lw          $t4, 0x7D58($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7D58);
    // 0x800534D0: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    // 0x800534D4: andi        $t5, $t4, 0x1
    ctx->r13 = ctx->r12 & 0X1;
    // 0x800534D8: beql        $t5, $zero, L_80053558
    if (ctx->r13 == 0) {
        // 0x800534DC: lw          $t3, 0x18($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X18);
            goto L_80053558;
    }
    goto skip_12;
    // 0x800534DC: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    skip_12:
    // 0x800534E0: jal         0x800B8DD0
    // 0x800534E4: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    RCP_SetupDL(rdram, ctx);
        goto after_8;
    // 0x800534E4: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    after_8:
    // 0x800534E8: jal         0x8005314C
    // 0x800534EC: nop

    Display_SetCullingMode(rdram, ctx);
        goto after_9;
    // 0x800534EC: nop

    after_9:
    // 0x800534F0: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x800534F4: lw          $t6, 0x7D58($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7D58);
    // 0x800534F8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800534FC: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x80053500: slti        $at, $t6, 0x3E9
    ctx->r1 = SIGNED(ctx->r14) < 0X3E9 ? 1 : 0;
    // 0x80053504: bne         $at, $zero, L_80053534
    if (ctx->r1 != 0) {
        // 0x80053508: lw          $a3, 0x4C($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X4C);
            goto L_80053534;
    }
    // 0x80053508: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x8005350C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80053510: lui         $t9, 0x2020
    ctx->r25 = S32(0X2020 << 16);
    // 0x80053514: ori         $t9, $t9, 0xFFFF
    ctx->r25 = ctx->r25 | 0XFFFF;
    // 0x80053518: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8005351C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80053520: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x80053524: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80053528: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8005352C: b           L_80053558
    // 0x80053530: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
        goto L_80053558;
    // 0x80053530: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
L_80053534:
    // 0x80053534: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80053538: lui         $t2, 0xFF00
    ctx->r10 = S32(0XFF00 << 16);
    // 0x8005353C: ori         $t2, $t2, 0xFF
    ctx->r10 = ctx->r10 | 0XFF;
    // 0x80053540: addiu       $t0, $v1, 0x8
    ctx->r8 = ADD32(ctx->r3, 0X8);
    // 0x80053544: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
    // 0x80053548: lui         $t1, 0xFA00
    ctx->r9 = S32(0XFA00 << 16);
    // 0x8005354C: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x80053550: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
L_80053554:
    // 0x80053554: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
L_80053558:
    // 0x80053558: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x8005355C: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x80053560: sltiu       $at, $t4, 0xD
    ctx->r1 = ctx->r12 < 0XD ? 1 : 0;
    // 0x80053564: beq         $at, $zero, L_80053644
    if (ctx->r1 == 0) {
        // 0x80053568: sll         $t4, $t4, 2
        ctx->r12 = S32(ctx->r12 << 2);
            goto L_80053644;
    }
    // 0x80053568: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8005356C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80053570: addu        $at, $at, $t4
    gpr jr_addend_80053578 = ctx->r12;
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x80053574: lw          $t4, 0x5E44($at)
    ctx->r12 = ADD32(ctx->r1, 0X5E44);
    // 0x80053578: jr          $t4
    // 0x8005357C: nop

    switch (jr_addend_80053578 >> 2) {
        case 0: goto L_80053580; break;
        case 1: goto L_80053594; break;
        case 2: goto L_80053644; break;
        case 3: goto L_800535F8; break;
        case 4: goto L_800535A8; break;
        case 5: goto L_800535BC; break;
        case 6: goto L_80053644; break;
        case 7: goto L_80053620; break;
        case 8: goto L_80053644; break;
        case 9: goto L_80053644; break;
        case 10: goto L_80053644; break;
        case 11: goto L_800535D0; break;
        case 12: goto L_800535E4; break;
        default: switch_error(__func__, 0x80053578, 0x800D5E44);
    }
    // 0x8005357C: nop

L_80053580:
    // 0x80053580: lwc1        $f4, 0x4($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X4);
    // 0x80053584: lwc1        $f6, 0x4($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X4);
    // 0x80053588: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8005358C: b           L_80053644
    // 0x80053590: swc1        $f8, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f8.u32l;
        goto L_80053644;
    // 0x80053590: swc1        $f8, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f8.u32l;
L_80053594:
    // 0x80053594: lwc1        $f10, 0x4($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X4);
    // 0x80053598: lwc1        $f16, 0x8($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X8);
    // 0x8005359C: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x800535A0: b           L_80053644
    // 0x800535A4: swc1        $f18, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f18.u32l;
        goto L_80053644;
    // 0x800535A4: swc1        $f18, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f18.u32l;
L_800535A8:
    // 0x800535A8: lwc1        $f4, 0x4($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X4);
    // 0x800535AC: lwc1        $f6, 0x10($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X10);
    // 0x800535B0: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800535B4: b           L_80053644
    // 0x800535B8: swc1        $f8, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f8.u32l;
        goto L_80053644;
    // 0x800535B8: swc1        $f8, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f8.u32l;
L_800535BC:
    // 0x800535BC: lwc1        $f10, 0x4($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X4);
    // 0x800535C0: lwc1        $f16, 0xC($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0XC);
    // 0x800535C4: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x800535C8: b           L_80053644
    // 0x800535CC: swc1        $f18, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f18.u32l;
        goto L_80053644;
    // 0x800535CC: swc1        $f18, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f18.u32l;
L_800535D0:
    // 0x800535D0: lwc1        $f4, 0x8($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X8);
    // 0x800535D4: lwc1        $f6, 0x20($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X20);
    // 0x800535D8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800535DC: b           L_80053644
    // 0x800535E0: swc1        $f8, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f8.u32l;
        goto L_80053644;
    // 0x800535E0: swc1        $f8, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f8.u32l;
L_800535E4:
    // 0x800535E4: lwc1        $f10, 0x8($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X8);
    // 0x800535E8: lwc1        $f16, 0x20($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X20);
    // 0x800535EC: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800535F0: b           L_80053644
    // 0x800535F4: swc1        $f18, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f18.u32l;
        goto L_80053644;
    // 0x800535F4: swc1        $f18, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f18.u32l;
L_800535F8:
    // 0x800535F8: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x800535FC: lwc1        $f6, 0x14($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X14);
    // 0x80053600: lwc1        $f4, 0x8($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X8);
    // 0x80053604: lwc1        $f10, 0x0($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X0);
    // 0x80053608: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8005360C: swc1        $f8, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->f8.u32l;
    // 0x80053610: lwc1        $f16, 0x18($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X18);
    // 0x80053614: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80053618: b           L_80053644
    // 0x8005361C: swc1        $f18, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f18.u32l;
        goto L_80053644;
    // 0x8005361C: swc1        $f18, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f18.u32l;
L_80053620:
    // 0x80053620: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x80053624: lwc1        $f6, 0x14($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X14);
    // 0x80053628: lwc1        $f4, 0x8($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X8);
    // 0x8005362C: lwc1        $f10, 0x0($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X0);
    // 0x80053630: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80053634: swc1        $f8, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f8.u32l;
    // 0x80053638: lwc1        $f16, 0x18($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X18);
    // 0x8005363C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80053640: swc1        $f18, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f18.u32l;
L_80053644:
    // 0x80053644: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80053648: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005364C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80053650: jr          $ra
    // 0x80053654: nop

    return;
    // 0x80053654: nop

;}
RECOMP_FUNC void Display_SetupPlayerSfxPos(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80057814: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80057818: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005781C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80057820: lwc1        $f4, 0x74($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X74);
    // 0x80057824: addiu       $a0, $a2, 0x460
    ctx->r4 = ADD32(ctx->r6, 0X460);
    // 0x80057828: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x8005782C: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x80057830: lwc1        $f6, 0x78($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X78);
    // 0x80057834: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    // 0x80057838: lwc1        $f8, 0x138($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X138);
    // 0x8005783C: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    // 0x80057840: lwc1        $f10, 0x460($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X460);
    // 0x80057844: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    // 0x80057848: lwc1        $f16, 0x464($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X464);
    // 0x8005784C: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    // 0x80057850: lwc1        $f18, 0x468($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X468);
    // 0x80057854: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80057858: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    // 0x8005785C: jal         0x8005F0E8
    // 0x80057860: swc1        $f18, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f18.u32l;
    Object_SetSfxSourceToPos(rdram, ctx);
        goto after_0;
    // 0x80057860: swc1        $f18, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f18.u32l;
    after_0:
    // 0x80057864: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x80057868: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8005786C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80057870: lwc1        $f4, 0x460($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X460);
    // 0x80057874: lwc1        $f10, 0x464($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X464);
    // 0x80057878: addiu       $t6, $a2, 0x46C
    ctx->r14 = ADD32(ctx->r6, 0X46C);
    // 0x8005787C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80057880: lwc1        $f4, 0x468($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X468);
    // 0x80057884: swc1        $f8, 0x46C($a2)
    MEM_W(0X46C, ctx->r6) = ctx->f8.u32l;
    // 0x80057888: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8005788C: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80057890: lwc1        $f10, 0xC4($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0XC4);
    // 0x80057894: lwc1        $f16, 0xF8($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0XF8);
    // 0x80057898: swc1        $f18, 0x470($a2)
    MEM_W(0X470, ctx->r6) = ctx->f18.u32l;
    // 0x8005789C: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800578A0: sw          $t6, 0x480($a2)
    MEM_W(0X480, ctx->r6) = ctx->r14;
    // 0x800578A4: sw          $a0, 0x47C($a2)
    MEM_W(0X47C, ctx->r6) = ctx->r4;
    // 0x800578A8: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800578AC: swc1        $f10, 0x488($a2)
    MEM_W(0X488, ctx->r6) = ctx->f10.u32l;
    // 0x800578B0: swc1        $f16, 0x490($a2)
    MEM_W(0X490, ctx->r6) = ctx->f16.u32l;
    // 0x800578B4: swc1        $f8, 0x474($a2)
    MEM_W(0X474, ctx->r6) = ctx->f8.u32l;
    // 0x800578B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800578BC: jr          $ra
    // 0x800578C0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800578C0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void ActorEvent_TriggerBranch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070CEC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80070CF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80070CF4: lw          $v0, 0x5C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X5C);
    // 0x80070CF8: slti        $at, $v0, 0xC8
    ctx->r1 = SIGNED(ctx->r2) < 0XC8 ? 1 : 0;
    // 0x80070CFC: beq         $at, $zero, L_80070D20
    if (ctx->r1 == 0) {
        // 0x80070D00: addiu       $t7, $v0, -0xC8
        ctx->r15 = ADD32(ctx->r2, -0XC8);
            goto L_80070D20;
    }
    // 0x80070D00: addiu       $t7, $v0, -0xC8
    ctx->r15 = ADD32(ctx->r2, -0XC8);
    // 0x80070D04: sll         $t6, $v0, 1
    ctx->r14 = S32(ctx->r2 << 1);
    // 0x80070D08: sh          $t6, 0xE6($a0)
    MEM_H(0XE6, ctx->r4) = ctx->r14;
    // 0x80070D0C: sw          $zero, 0x50($a0)
    MEM_W(0X50, ctx->r4) = 0;
    // 0x80070D10: jal         0x8006D36C
    // 0x80070D14: sw          $zero, 0x58($a0)
    MEM_W(0X58, ctx->r4) = 0;
    ActorEvent_ProcessScript(rdram, ctx);
        goto after_0;
    // 0x80070D14: sw          $zero, 0x58($a0)
    MEM_W(0X58, ctx->r4) = 0;
    after_0:
    // 0x80070D18: b           L_80070D38
    // 0x80070D1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80070D38;
    // 0x80070D1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80070D20:
    // 0x80070D20: sh          $t7, 0xE4($a0)
    MEM_H(0XE4, ctx->r4) = ctx->r15;
    // 0x80070D24: sh          $zero, 0xE6($a0)
    MEM_H(0XE6, ctx->r4) = 0;
    // 0x80070D28: sw          $zero, 0x50($a0)
    MEM_W(0X50, ctx->r4) = 0;
    // 0x80070D2C: jal         0x8006D36C
    // 0x80070D30: sw          $zero, 0x58($a0)
    MEM_W(0X58, ctx->r4) = 0;
    ActorEvent_ProcessScript(rdram, ctx);
        goto after_1;
    // 0x80070D30: sw          $zero, 0x58($a0)
    MEM_W(0X58, ctx->r4) = 0;
    after_1:
    // 0x80070D34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80070D38:
    // 0x80070D38: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80070D3C: jr          $ra
    // 0x80070D40: nop

    return;
    // 0x80070D40: nop

;}
RECOMP_FUNC void AudioLoad_SyncLoadSeq(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000F354: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000F358: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000F35C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8000F360: jal         0x8000F790
    // 0x8000F364: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    AudioLoad_GetLoadTableIndex(rdram, ctx);
        goto after_0;
    // 0x8000F364: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8000F368: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8000F36C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8000F370: jal         0x8000F554
    // 0x8000F374: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    AudioLoad_SyncLoad(rdram, ctx);
        goto after_1;
    // 0x8000F374: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    after_1:
    // 0x8000F378: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000F37C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8000F380: jr          $ra
    // 0x8000F384: nop

    return;
    // 0x8000F384: nop

;}
RECOMP_FUNC void ActorEvent_RetreatTeammate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800700A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800700A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800700AC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800700B0: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    // 0x800700B4: lh          $t6, 0xB8($a2)
    ctx->r14 = MEM_H(ctx->r6, 0XB8);
    // 0x800700B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800700BC: beq         $a3, $t6, L_800701D0
    if (ctx->r7 == ctx->r14) {
        // 0x800700C0: nop
    
            goto L_800701D0;
    }
    // 0x800700C0: nop

    // 0x800700C4: lw          $v1, 0x80($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X80);
    // 0x800700C8: blez        $v1, L_800701D0
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800700CC: slti        $at, $v1, 0x4
        ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
            goto L_800701D0;
    }
    // 0x800700CC: slti        $at, $v1, 0x4
    ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // 0x800700D0: beq         $at, $zero, L_800701D0
    if (ctx->r1 == 0) {
        // 0x800700D4: sll         $t7, $v1, 2
        ctx->r15 = S32(ctx->r3 << 2);
            goto L_800701D0;
    }
    // 0x800700D4: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x800700D8: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x800700DC: addiu       $t8, $t8, 0x78B0
    ctx->r24 = ADD32(ctx->r24, 0X78B0);
    // 0x800700E0: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    // 0x800700E4: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x800700E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800700EC: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x800700F0: bgtz        $t9, L_800701D0
    if (SIGNED(ctx->r25) > 0) {
        // 0x800700F4: nop
    
            goto L_800701D0;
    }
    // 0x800700F4: nop

    // 0x800700F8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800700FC: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80070100: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80070104: sh          $a3, 0xB8($a2)
    MEM_H(0XB8, ctx->r6) = ctx->r7;
    // 0x80070108: sw          $zero, 0x58($a2)
    MEM_W(0X58, ctx->r6) = 0;
    // 0x8007010C: swc1        $f4, 0x13C($a2)
    MEM_W(0X13C, ctx->r6) = ctx->f4.u32l;
    // 0x80070110: swc1        $f6, 0x140($a2)
    MEM_W(0X140, ctx->r6) = ctx->f6.u32l;
    // 0x80070114: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
    // 0x80070118: lw          $v1, 0x80($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X80);
    // 0x8007011C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80070120: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80070124: beq         $v1, $a1, L_80070148
    if (ctx->r3 == ctx->r5) {
        // 0x80070128: addiu       $a0, $a0, 0x39B8
        ctx->r4 = ADD32(ctx->r4, 0X39B8);
            goto L_80070148;
    }
    // 0x80070128: addiu       $a0, $a0, 0x39B8
    ctx->r4 = ADD32(ctx->r4, 0X39B8);
    // 0x8007012C: beq         $v1, $at, L_80070160
    if (ctx->r3 == ctx->r1) {
        // 0x80070130: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_80070160;
    }
    // 0x80070130: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80070134: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80070138: beq         $v1, $at, L_8007017C
    if (ctx->r3 == ctx->r1) {
        // 0x8007013C: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_8007017C;
    }
    // 0x8007013C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80070140: b           L_80070198
    // 0x80070144: sll         $t1, $v1, 2
    ctx->r9 = S32(ctx->r3 << 2);
        goto L_80070198;
    // 0x80070144: sll         $t1, $v1, 2
    ctx->r9 = S32(ctx->r3 << 2);
L_80070148:
    // 0x80070148: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x8007014C: jal         0x800BA808
    // 0x80070150: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    Radio_PlayMessage(rdram, ctx);
        goto after_0;
    // 0x80070150: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80070154: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80070158: b           L_80070194
    // 0x8007015C: lw          $v1, 0x80($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X80);
        goto L_80070194;
    // 0x8007015C: lw          $v1, 0x80($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X80);
L_80070160:
    // 0x80070160: addiu       $a0, $a0, 0x3A64
    ctx->r4 = ADD32(ctx->r4, 0X3A64);
    // 0x80070164: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x80070168: jal         0x800BA808
    // 0x8007016C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    Radio_PlayMessage(rdram, ctx);
        goto after_1;
    // 0x8007016C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_1:
    // 0x80070170: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80070174: b           L_80070194
    // 0x80070178: lw          $v1, 0x80($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X80);
        goto L_80070194;
    // 0x80070178: lw          $v1, 0x80($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X80);
L_8007017C:
    // 0x8007017C: addiu       $a0, $a0, 0x3A08
    ctx->r4 = ADD32(ctx->r4, 0X3A08);
    // 0x80070180: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x80070184: jal         0x800BA808
    // 0x80070188: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    Radio_PlayMessage(rdram, ctx);
        goto after_2;
    // 0x80070188: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_2:
    // 0x8007018C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80070190: lw          $v1, 0x80($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X80);
L_80070194:
    // 0x80070194: sll         $t1, $v1, 2
    ctx->r9 = S32(ctx->r3 << 2);
L_80070198:
    // 0x80070198: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8007019C: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x800701A0: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x800701A4: sw          $t0, 0x78B0($at)
    MEM_W(0X78B0, ctx->r1) = ctx->r8;
    // 0x800701A8: lw          $t2, 0x80($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X80);
    // 0x800701AC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800701B0: addiu       $t4, $zero, 0x1388
    ctx->r12 = ADD32(0, 0X1388);
    // 0x800701B4: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800701B8: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x800701BC: sw          $zero, 0x7910($at)
    MEM_W(0X7910, ctx->r1) = 0;
    // 0x800701C0: sh          $t4, 0xC2($a2)
    MEM_H(0XC2, ctx->r6) = ctx->r12;
    // 0x800701C4: sb          $zero, 0xD0($a2)
    MEM_B(0XD0, ctx->r6) = 0;
    // 0x800701C8: b           L_800701D0
    // 0x800701CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800701D0;
    // 0x800701CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800701D0:
    // 0x800701D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800701D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800701D8: jr          $ra
    // 0x800701DC: nop

    return;
    // 0x800701DC: nop

;}
RECOMP_FUNC void BoLaserCannon_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002E6DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002E6E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002E6E4: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8002E6E8: jal         0x80187520
    // 0x8002E6EC: addiu       $a0, $zero, 0x62
    ctx->r4 = ADD32(0, 0X62);
    LOOKUP_FUNC(0x80187520)(rdram, ctx);
        goto after_0;
    // 0x8002E6EC: addiu       $a0, $zero, 0x62
    ctx->r4 = ADD32(0, 0X62);
    after_0:
    // 0x8002E6F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002E6F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002E6F8: jr          $ra
    // 0x8002E6FC: nop

    return;
    // 0x8002E6FC: nop

;}
RECOMP_FUNC void AudioSeq_SeqLayerProcessScript(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80014748: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8001474C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80014750: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80014754: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80014758: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8001475C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80014760: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80014764: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80014768: sw          $t6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r14;
    // 0x8001476C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80014770: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80014774: srl         $t7, $v0, 31
    ctx->r15 = S32(U32(ctx->r2) >> 31);
    // 0x80014778: beql        $t7, $zero, L_800152A4
    if (ctx->r15 == 0) {
        // 0x8001477C: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_800152A4;
    }
    goto skip_0;
    // 0x8001477C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x80014780: lh          $v1, 0x38($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X38);
    // 0x80014784: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
    // 0x80014788: sll         $t7, $v0, 3
    ctx->r15 = S32(ctx->r2 << 3);
    // 0x8001478C: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x80014790: bne         $at, $zero, L_800147CC
    if (ctx->r1 != 0) {
        // 0x80014794: addiu       $t8, $v1, -0x1
        ctx->r24 = ADD32(ctx->r3, -0X1);
            goto L_800147CC;
    }
    // 0x80014794: addiu       $t8, $v1, -0x1
    ctx->r24 = ADD32(ctx->r3, -0X1);
    // 0x80014798: bltz        $t0, L_800152A0
    if (SIGNED(ctx->r8) < 0) {
        // 0x8001479C: sh          $t8, 0x38($a0)
        MEM_H(0X38, ctx->r4) = ctx->r24;
            goto L_800152A0;
    }
    // 0x8001479C: sh          $t8, 0x38($a0)
    MEM_H(0X38, ctx->r4) = ctx->r24;
    // 0x800147A0: lh          $t1, 0x3A($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X3A);
    // 0x800147A4: lh          $t2, 0x38($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X38);
    // 0x800147A8: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800147AC: bnel        $at, $zero, L_800152A4
    if (ctx->r1 != 0) {
        // 0x800147B0: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_800152A4;
    }
    goto skip_1;
    // 0x800147B0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_1:
    // 0x800147B4: jal         0x8001266C
    // 0x800147B8: nop

    Audio_SeqLayerNoteDecay(rdram, ctx);
        goto after_0;
    // 0x800147B8: nop

    after_0:
    // 0x800147BC: lbu         $t4, 0x0($s1)
    ctx->r12 = MEM_BU(ctx->r17, 0X0);
    // 0x800147C0: ori         $t5, $t4, 0x20
    ctx->r13 = ctx->r12 | 0X20;
    // 0x800147C4: b           L_800152A0
    // 0x800147C8: sb          $t5, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r13;
        goto L_800152A0;
    // 0x800147C8: sb          $t5, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r13;
L_800147CC:
    // 0x800147CC: bltzl       $t7, L_800147E8
    if (SIGNED(ctx->r15) < 0) {
        // 0x800147D0: lw          $a0, 0x40($s1)
        ctx->r4 = MEM_W(ctx->r17, 0X40);
            goto L_800147E8;
    }
    goto skip_2;
    // 0x800147D0: lw          $a0, 0x40($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X40);
    skip_2:
    // 0x800147D4: jal         0x8001266C
    // 0x800147D8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Audio_SeqLayerNoteDecay(rdram, ctx);
        goto after_1;
    // 0x800147D8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x800147DC: b           L_80014808
    // 0x800147E0: lbu         $v0, 0x8($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X8);
        goto L_80014808;
    // 0x800147E0: lbu         $v0, 0x8($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X8);
    // 0x800147E4: lw          $a0, 0x40($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X40);
L_800147E8:
    // 0x800147E8: beql        $a0, $zero, L_80014808
    if (ctx->r4 == 0) {
        // 0x800147EC: lbu         $v0, 0x8($s1)
        ctx->r2 = MEM_BU(ctx->r17, 0X8);
            goto L_80014808;
    }
    goto skip_3;
    // 0x800147EC: lbu         $v0, 0x8($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X8);
    skip_3:
    // 0x800147F0: lw          $t8, 0x48($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X48);
    // 0x800147F4: bnel        $s1, $t8, L_80014808
    if (ctx->r17 != ctx->r24) {
        // 0x800147F8: lbu         $v0, 0x8($s1)
        ctx->r2 = MEM_BU(ctx->r17, 0X8);
            goto L_80014808;
    }
    goto skip_4;
    // 0x800147F8: lbu         $v0, 0x8($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X8);
    skip_4:
    // 0x800147FC: jal         0x8001266C
    // 0x80014800: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Audio_SeqLayerNoteDecay(rdram, ctx);
        goto after_2;
    // 0x80014800: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x80014804: lbu         $v0, 0x8($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X8);
L_80014808:
    // 0x80014808: addiu       $at, $zero, -0x81
    ctx->r1 = ADD32(0, -0X81);
    // 0x8001480C: and         $t9, $v0, $at
    ctx->r25 = ctx->r2 & ctx->r1;
    // 0x80014810: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80014814: beq         $t9, $at, L_80014824
    if (ctx->r25 == ctx->r1) {
        // 0x80014818: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80014824;
    }
    // 0x80014818: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8001481C: bnel        $t9, $at, L_8001482C
    if (ctx->r25 != ctx->r1) {
        // 0x80014820: lw          $v0, 0x4C($s1)
        ctx->r2 = MEM_W(ctx->r17, 0X4C);
            goto L_8001482C;
    }
    goto skip_5;
    // 0x80014820: lw          $v0, 0x4C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X4C);
    skip_5:
L_80014824:
    // 0x80014824: sb          $zero, 0x8($s1)
    MEM_B(0X8, ctx->r17) = 0;
    // 0x80014828: lw          $v0, 0x4C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X4C);
L_8001482C:
    // 0x8001482C: lbu         $t1, 0x0($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X0);
    // 0x80014830: addiu       $s0, $s1, 0x50
    ctx->r16 = ADD32(ctx->r17, 0X50);
    // 0x80014834: lw          $s4, 0x44($v0)
    ctx->r20 = MEM_W(ctx->r2, 0X44);
    // 0x80014838: ori         $t2, $t1, 0x4
    ctx->r10 = ctx->r9 | 0X4;
    // 0x8001483C: sb          $t2, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r10;
    // 0x80014840: lhu         $s3, 0x44($sp)
    ctx->r19 = MEM_HU(ctx->r29, 0X44);
    // 0x80014844: sw          $v0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r2;
L_80014848:
    // 0x80014848: jal         0x800146C0
    // 0x8001484C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    AudioSeq_ScriptReadU8(rdram, ctx);
        goto after_3;
    // 0x8001484C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80014850: slti        $at, $v0, 0xC1
    ctx->r1 = SIGNED(ctx->r2) < 0XC1 ? 1 : 0;
    // 0x80014854: andi        $s2, $v0, 0xFF
    ctx->r18 = ctx->r2 & 0XFF;
    // 0x80014858: bne         $at, $zero, L_80014C60
    if (ctx->r1 != 0) {
        // 0x8001485C: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80014C60;
    }
    // 0x8001485C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80014860: slti        $at, $v0, 0xCE
    ctx->r1 = SIGNED(ctx->r2) < 0XCE ? 1 : 0;
    // 0x80014864: bne         $at, $zero, L_80014890
    if (ctx->r1 != 0) {
        // 0x80014868: addiu       $t4, $a1, -0xC1
        ctx->r12 = ADD32(ctx->r5, -0XC1);
            goto L_80014890;
    }
    // 0x80014868: addiu       $t4, $a1, -0xC1
    ctx->r12 = ADD32(ctx->r5, -0XC1);
    // 0x8001486C: addiu       $t3, $v0, -0xF4
    ctx->r11 = ADD32(ctx->r2, -0XF4);
    // 0x80014870: sltiu       $at, $t3, 0xC
    ctx->r1 = ctx->r11 < 0XC ? 1 : 0;
    // 0x80014874: beq         $at, $zero, L_80014BF0
    if (ctx->r1 == 0) {
        // 0x80014878: sll         $t3, $t3, 2
        ctx->r11 = S32(ctx->r11 << 2);
            goto L_80014BF0;
    }
    // 0x80014878: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8001487C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80014880: addu        $at, $at, $t3
    gpr jr_addend_80014888 = ctx->r11;
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x80014884: lw          $t3, -0x78E0($at)
    ctx->r11 = ADD32(ctx->r1, -0X78E0);
    // 0x80014888: jr          $t3
    // 0x8001488C: nop

    switch (jr_addend_80014888 >> 2) {
        case 0: goto L_800149C8; break;
        case 1: goto L_80014BF0; break;
        case 2: goto L_80014BF0; break;
        case 3: goto L_80014960; break;
        case 4: goto L_80014928; break;
        case 5: goto L_80014BF0; break;
        case 6: goto L_80014BF0; break;
        case 7: goto L_800149A8; break;
        case 8: goto L_800148E8; break;
        case 9: goto L_80014BF0; break;
        case 10: goto L_80014BF0; break;
        case 11: goto L_800148B0; break;
        default: switch_error(__func__, 0x80014888, 0x800C8720);
    }
    // 0x8001488C: nop

L_80014890:
    // 0x80014890: sltiu       $at, $t4, 0xD
    ctx->r1 = ctx->r12 < 0XD ? 1 : 0;
    // 0x80014894: beq         $at, $zero, L_80014BF0
    if (ctx->r1 == 0) {
        // 0x80014898: sll         $t4, $t4, 2
        ctx->r12 = S32(ctx->r12 << 2);
            goto L_80014BF0;
    }
    // 0x80014898: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8001489C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800148A0: addu        $at, $at, $t4
    gpr jr_addend_800148A8 = ctx->r12;
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x800148A4: lw          $t4, -0x78B0($at)
    ctx->r12 = ADD32(ctx->r1, -0X78B0);
    // 0x800148A8: jr          $t4
    // 0x800148AC: nop

    switch (jr_addend_800148A8 >> 2) {
        case 0: goto L_800149E8; break;
        case 1: goto L_80014A30; break;
        case 2: goto L_80014A90; break;
        case 3: goto L_80014A58; break;
        case 4: goto L_80014A58; break;
        case 5: goto L_80014AA4; break;
        case 6: goto L_80014B14; break;
        case 7: goto L_80014B9C; break;
        case 8: goto L_80014A30; break;
        case 9: goto L_800149E8; break;
        case 10: goto L_80014BA4; break;
        case 11: goto L_80014BD0; break;
        case 12: goto L_80014BE0; break;
        default: switch_error(__func__, 0x800148A8, 0x800C8750);
    }
    // 0x800148AC: nop

L_800148B0:
    // 0x800148B0: lbu         $v1, 0x18($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X18);
    // 0x800148B4: bne         $v1, $zero, L_800148CC
    if (ctx->r3 != 0) {
        // 0x800148B8: addiu       $v0, $v1, -0x1
        ctx->r2 = ADD32(ctx->r3, -0X1);
            goto L_800148CC;
    }
    // 0x800148B8: addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
    // 0x800148BC: jal         0x800140D0
    // 0x800148C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    AudioSeq_SeqLayerDisable(rdram, ctx);
        goto after_4;
    // 0x800148C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x800148C4: b           L_800152A4
    // 0x800148C8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_800152A4;
    // 0x800148C8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800148CC:
    // 0x800148CC: andi        $t5, $v0, 0xFF
    ctx->r13 = ctx->r2 & 0XFF;
    // 0x800148D0: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800148D4: addu        $t7, $s0, $t6
    ctx->r15 = ADD32(ctx->r16, ctx->r14);
    // 0x800148D8: sb          $t5, 0x18($s0)
    MEM_B(0X18, ctx->r16) = ctx->r13;
    // 0x800148DC: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x800148E0: b           L_80014848
    // 0x800148E4: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
        goto L_80014848;
    // 0x800148E4: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
L_800148E8:
    // 0x800148E8: jal         0x800146D4
    // 0x800148EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    AudioSeq_ScriptReadS16(rdram, ctx);
        goto after_5;
    // 0x800148EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x800148F0: lbu         $t0, 0x18($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X18);
    // 0x800148F4: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x800148F8: andi        $t6, $v0, 0xFFFF
    ctx->r14 = ctx->r2 & 0XFFFF;
    // 0x800148FC: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80014900: addu        $t2, $s0, $t1
    ctx->r10 = ADD32(ctx->r16, ctx->r9);
    // 0x80014904: sw          $t9, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r25;
    // 0x80014908: lbu         $t3, 0x18($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X18);
    // 0x8001490C: andi        $s3, $v0, 0xFFFF
    ctx->r19 = ctx->r2 & 0XFFFF;
    // 0x80014910: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80014914: sb          $t4, 0x18($s0)
    MEM_B(0X18, ctx->r16) = ctx->r12;
    // 0x80014918: lw          $t5, 0x18($s4)
    ctx->r13 = MEM_W(ctx->r20, 0X18);
    // 0x8001491C: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x80014920: b           L_80014848
    // 0x80014924: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
        goto L_80014848;
    // 0x80014924: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
L_80014928:
    // 0x80014928: jal         0x800146C0
    // 0x8001492C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    AudioSeq_ScriptReadU8(rdram, ctx);
        goto after_6;
    // 0x8001492C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80014930: lbu         $t8, 0x18($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X18);
    // 0x80014934: addu        $t0, $s0, $t8
    ctx->r8 = ADD32(ctx->r16, ctx->r24);
    // 0x80014938: sb          $v0, 0x14($t0)
    MEM_B(0X14, ctx->r8) = ctx->r2;
    // 0x8001493C: lbu         $t9, 0x18($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X18);
    // 0x80014940: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x80014944: sll         $t2, $t9, 2
    ctx->r10 = S32(ctx->r25 << 2);
    // 0x80014948: addu        $t3, $s0, $t2
    ctx->r11 = ADD32(ctx->r16, ctx->r10);
    // 0x8001494C: sw          $t1, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r9;
    // 0x80014950: lbu         $t4, 0x18($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X18);
    // 0x80014954: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80014958: b           L_80014848
    // 0x8001495C: sb          $t5, 0x18($s0)
    MEM_B(0X18, ctx->r16) = ctx->r13;
        goto L_80014848;
    // 0x8001495C: sb          $t5, 0x18($s0)
    MEM_B(0X18, ctx->r16) = ctx->r13;
L_80014960:
    // 0x80014960: lbu         $t6, 0x18($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X18);
    // 0x80014964: addu        $v0, $s0, $t6
    ctx->r2 = ADD32(ctx->r16, ctx->r14);
    // 0x80014968: lbu         $t7, 0x13($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X13);
    // 0x8001496C: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80014970: sb          $t8, 0x13($v0)
    MEM_B(0X13, ctx->r2) = ctx->r24;
    // 0x80014974: lbu         $v1, 0x18($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X18);
    // 0x80014978: addu        $t0, $s0, $v1
    ctx->r8 = ADD32(ctx->r16, ctx->r3);
    // 0x8001497C: lbu         $t9, 0x13($t0)
    ctx->r25 = MEM_BU(ctx->r8, 0X13);
    // 0x80014980: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x80014984: sll         $t2, $a0, 2
    ctx->r10 = S32(ctx->r4 << 2);
    // 0x80014988: beq         $t9, $zero, L_800149A0
    if (ctx->r25 == 0) {
        // 0x8001498C: addiu       $t4, $v1, -0x1
        ctx->r12 = ADD32(ctx->r3, -0X1);
            goto L_800149A0;
    }
    // 0x8001498C: addiu       $t4, $v1, -0x1
    ctx->r12 = ADD32(ctx->r3, -0X1);
    // 0x80014990: addu        $t1, $s0, $t2
    ctx->r9 = ADD32(ctx->r16, ctx->r10);
    // 0x80014994: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x80014998: b           L_80014848
    // 0x8001499C: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
        goto L_80014848;
    // 0x8001499C: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
L_800149A0:
    // 0x800149A0: b           L_80014848
    // 0x800149A4: sb          $t4, 0x18($s0)
    MEM_B(0X18, ctx->r16) = ctx->r12;
        goto L_80014848;
    // 0x800149A4: sb          $t4, 0x18($s0)
    MEM_B(0X18, ctx->r16) = ctx->r12;
L_800149A8:
    // 0x800149A8: jal         0x800146D4
    // 0x800149AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    AudioSeq_ScriptReadS16(rdram, ctx);
        goto after_7;
    // 0x800149AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x800149B0: lw          $t5, 0x18($s4)
    ctx->r13 = MEM_W(ctx->r20, 0X18);
    // 0x800149B4: andi        $t6, $v0, 0xFFFF
    ctx->r14 = ctx->r2 & 0XFFFF;
    // 0x800149B8: andi        $s3, $v0, 0xFFFF
    ctx->r19 = ctx->r2 & 0XFFFF;
    // 0x800149BC: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x800149C0: b           L_80014848
    // 0x800149C4: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
        goto L_80014848;
    // 0x800149C4: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
L_800149C8:
    // 0x800149C8: jal         0x800146C0
    // 0x800149CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    AudioSeq_ScriptReadU8(rdram, ctx);
        goto after_8;
    // 0x800149CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x800149D0: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x800149D4: sll         $t0, $v0, 24
    ctx->r8 = S32(ctx->r2 << 24);
    // 0x800149D8: sra         $t9, $t0, 24
    ctx->r25 = S32(SIGNED(ctx->r8) >> 24);
    // 0x800149DC: addu        $t2, $t8, $t9
    ctx->r10 = ADD32(ctx->r24, ctx->r25);
    // 0x800149E0: b           L_80014848
    // 0x800149E4: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
        goto L_80014848;
    // 0x800149E4: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
L_800149E8:
    // 0x800149E8: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800149EC: addiu       $at, $zero, 0xC1
    ctx->r1 = ADD32(0, 0XC1);
    // 0x800149F0: lbu         $a0, 0x0($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X0);
    // 0x800149F4: addiu       $t1, $v1, 0x1
    ctx->r9 = ADD32(ctx->r3, 0X1);
    // 0x800149F8: bne         $a1, $at, L_80014A28
    if (ctx->r5 != ctx->r1) {
        // 0x800149FC: sw          $t1, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r9;
            goto L_80014A28;
    }
    // 0x800149FC: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x80014A00: multu       $a0, $a0
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80014A04: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80014A08: lwc1        $f8, -0x787C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X787C);
    // 0x80014A0C: mflo        $t3
    ctx->r11 = lo;
    // 0x80014A10: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x80014A14: nop

    // 0x80014A18: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80014A1C: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80014A20: b           L_80014848
    // 0x80014A24: swc1        $f10, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->f10.u32l;
        goto L_80014848;
    // 0x80014A24: swc1        $f10, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->f10.u32l;
L_80014A28:
    // 0x80014A28: b           L_80014848
    // 0x80014A2C: sb          $a0, 0x6($s1)
    MEM_B(0X6, ctx->r17) = ctx->r4;
        goto L_80014848;
    // 0x80014A2C: sb          $a0, 0x6($s1)
    MEM_B(0X6, ctx->r17) = ctx->r4;
L_80014A30:
    // 0x80014A30: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80014A34: addiu       $at, $zero, 0xC9
    ctx->r1 = ADD32(0, 0XC9);
    // 0x80014A38: lbu         $a0, 0x0($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X0);
    // 0x80014A3C: addiu       $t4, $v1, 0x1
    ctx->r12 = ADD32(ctx->r3, 0X1);
    // 0x80014A40: bne         $a1, $at, L_80014A50
    if (ctx->r5 != ctx->r1) {
        // 0x80014A44: sw          $t4, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r12;
            goto L_80014A50;
    }
    // 0x80014A44: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x80014A48: b           L_80014848
    // 0x80014A4C: sb          $a0, 0x4($s1)
    MEM_B(0X4, ctx->r17) = ctx->r4;
        goto L_80014848;
    // 0x80014A4C: sb          $a0, 0x4($s1)
    MEM_B(0X4, ctx->r17) = ctx->r4;
L_80014A50:
    // 0x80014A50: b           L_80014848
    // 0x80014A54: sh          $a0, 0x22($s1)
    MEM_H(0X22, ctx->r17) = ctx->r4;
        goto L_80014848;
    // 0x80014A54: sh          $a0, 0x22($s1)
    MEM_H(0X22, ctx->r17) = ctx->r4;
L_80014A58:
    // 0x80014A58: addiu       $at, $zero, 0xC4
    ctx->r1 = ADD32(0, 0XC4);
    // 0x80014A5C: bnel        $a1, $at, L_80014A78
    if (ctx->r5 != ctx->r1) {
        // 0x80014A60: lbu         $t0, 0x0($s1)
        ctx->r8 = MEM_BU(ctx->r17, 0X0);
            goto L_80014A78;
    }
    goto skip_6;
    // 0x80014A60: lbu         $t0, 0x0($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0X0);
    skip_6:
    // 0x80014A64: lbu         $t6, 0x0($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X0);
    // 0x80014A68: ori         $t7, $t6, 0x10
    ctx->r15 = ctx->r14 | 0X10;
    // 0x80014A6C: b           L_80014A80
    // 0x80014A70: sb          $t7, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r15;
        goto L_80014A80;
    // 0x80014A70: sb          $t7, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r15;
    // 0x80014A74: lbu         $t0, 0x0($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0X0);
L_80014A78:
    // 0x80014A78: andi        $t8, $t0, 0xFFEF
    ctx->r24 = ctx->r8 & 0XFFEF;
    // 0x80014A7C: sb          $t8, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r24;
L_80014A80:
    // 0x80014A80: jal         0x8001266C
    // 0x80014A84: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Audio_SeqLayerNoteDecay(rdram, ctx);
        goto after_9;
    // 0x80014A84: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_9:
    // 0x80014A88: b           L_80014848
    // 0x80014A8C: nop

        goto L_80014848;
    // 0x80014A8C: nop

L_80014A90:
    // 0x80014A90: jal         0x80014704
    // 0x80014A94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    AudioSeq_ScriptReadCompressedU16(rdram, ctx);
        goto after_10;
    // 0x80014A94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80014A98: andi        $s3, $v0, 0xFFFF
    ctx->r19 = ctx->r2 & 0XFFFF;
    // 0x80014A9C: b           L_80014848
    // 0x80014AA0: sh          $v0, 0x34($s1)
    MEM_H(0X34, ctx->r17) = ctx->r2;
        goto L_80014848;
    // 0x80014AA0: sh          $v0, 0x34($s1)
    MEM_H(0X34, ctx->r17) = ctx->r2;
L_80014AA4:
    // 0x80014AA4: jal         0x800146C0
    // 0x80014AA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    AudioSeq_ScriptReadU8(rdram, ctx);
        goto after_11;
    // 0x80014AA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80014AAC: slti        $at, $v0, 0x7F
    ctx->r1 = SIGNED(ctx->r2) < 0X7F ? 1 : 0;
    // 0x80014AB0: andi        $s2, $v0, 0xFF
    ctx->r18 = ctx->r2 & 0XFF;
    // 0x80014AB4: bne         $at, $zero, L_80014AEC
    if (ctx->r1 != 0) {
        // 0x80014AB8: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80014AEC;
    }
    // 0x80014AB8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80014ABC: addiu       $at, $zero, 0x7F
    ctx->r1 = ADD32(0, 0X7F);
    // 0x80014AC0: bnel        $v0, $at, L_80014AD4
    if (ctx->r2 != ctx->r1) {
        // 0x80014AC4: sb          $v0, 0x2($s1)
        MEM_B(0X2, ctx->r17) = ctx->r2;
            goto L_80014AD4;
    }
    goto skip_7;
    // 0x80014AC4: sb          $v0, 0x2($s1)
    MEM_B(0X2, ctx->r17) = ctx->r2;
    skip_7:
    // 0x80014AC8: b           L_80014AD8
    // 0x80014ACC: sb          $zero, 0x2($s1)
    MEM_B(0X2, ctx->r17) = 0;
        goto L_80014AD8;
    // 0x80014ACC: sb          $zero, 0x2($s1)
    MEM_B(0X2, ctx->r17) = 0;
    // 0x80014AD0: sb          $v0, 0x2($s1)
    MEM_B(0X2, ctx->r17) = ctx->r2;
L_80014AD4:
    // 0x80014AD4: sw          $zero, 0x44($s1)
    MEM_W(0X44, ctx->r17) = 0;
L_80014AD8:
    // 0x80014AD8: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80014ADC: bne         $a1, $at, L_80014848
    if (ctx->r5 != ctx->r1) {
        // 0x80014AE0: nop
    
            goto L_80014848;
    }
    // 0x80014AE0: nop

    // 0x80014AE4: b           L_80014848
    // 0x80014AE8: sb          $zero, 0x18($s1)
    MEM_B(0X18, ctx->r17) = 0;
        goto L_80014848;
    // 0x80014AE8: sb          $zero, 0x18($s1)
    MEM_B(0X18, ctx->r17) = 0;
L_80014AEC:
    // 0x80014AEC: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x80014AF0: andi        $a1, $s2, 0xFF
    ctx->r5 = ctx->r18 & 0XFF;
    // 0x80014AF4: addiu       $a2, $s1, 0x44
    ctx->r6 = ADD32(ctx->r17, 0X44);
    // 0x80014AF8: jal         0x800152C0
    // 0x80014AFC: addiu       $a3, $s1, 0x18
    ctx->r7 = ADD32(ctx->r17, 0X18);
    AudioSeq_GetInstrument(rdram, ctx);
        goto after_12;
    // 0x80014AFC: addiu       $a3, $s1, 0x18
    ctx->r7 = ADD32(ctx->r17, 0X18);
    after_12:
    // 0x80014B00: bne         $v0, $zero, L_80014848
    if (ctx->r2 != 0) {
        // 0x80014B04: sb          $v0, 0x2($s1)
        MEM_B(0X2, ctx->r17) = ctx->r2;
            goto L_80014848;
    }
    // 0x80014B04: sb          $v0, 0x2($s1)
    MEM_B(0X2, ctx->r17) = ctx->r2;
    // 0x80014B08: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80014B0C: b           L_80014848
    // 0x80014B10: sb          $t9, 0x2($s1)
    MEM_B(0X2, ctx->r17) = ctx->r25;
        goto L_80014848;
    // 0x80014B10: sb          $t9, 0x2($s1)
    MEM_B(0X2, ctx->r17) = ctx->r25;
L_80014B14:
    // 0x80014B14: jal         0x800146C0
    // 0x80014B18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    AudioSeq_ScriptReadU8(rdram, ctx);
        goto after_13;
    // 0x80014B18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80014B1C: sb          $v0, 0x8($s1)
    MEM_B(0X8, ctx->r17) = ctx->r2;
    // 0x80014B20: jal         0x800146C0
    // 0x80014B24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    AudioSeq_ScriptReadU8(rdram, ctx);
        goto after_14;
    // 0x80014B24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80014B28: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x80014B2C: lh          $t4, 0x22($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X22);
    // 0x80014B30: lh          $t6, 0xE($s4)
    ctx->r14 = MEM_H(ctx->r20, 0XE);
    // 0x80014B34: lh          $t1, 0x1E($t2)
    ctx->r9 = MEM_H(ctx->r10, 0X1E);
    // 0x80014B38: addu        $t3, $v0, $t1
    ctx->r11 = ADD32(ctx->r2, ctx->r9);
    // 0x80014B3C: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x80014B40: addu        $s2, $t5, $t6
    ctx->r18 = ADD32(ctx->r13, ctx->r14);
    // 0x80014B44: andi        $t7, $s2, 0xFF
    ctx->r15 = ctx->r18 & 0XFF;
    // 0x80014B48: slti        $at, $t7, 0x80
    ctx->r1 = SIGNED(ctx->r15) < 0X80 ? 1 : 0;
    // 0x80014B4C: bne         $at, $zero, L_80014B58
    if (ctx->r1 != 0) {
        // 0x80014B50: or          $s2, $t7, $zero
        ctx->r18 = ctx->r15 | 0;
            goto L_80014B58;
    }
    // 0x80014B50: or          $s2, $t7, $zero
    ctx->r18 = ctx->r15 | 0;
    // 0x80014B54: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_80014B58:
    // 0x80014B58: lbu         $t0, 0x8($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0X8);
    // 0x80014B5C: sb          $s2, 0x5($s1)
    MEM_B(0X5, ctx->r17) = ctx->r18;
    // 0x80014B60: andi        $t8, $t0, 0x80
    ctx->r24 = ctx->r8 & 0X80;
    // 0x80014B64: beq         $t8, $zero, L_80014B88
    if (ctx->r24 == 0) {
        // 0x80014B68: nop
    
            goto L_80014B88;
    }
    // 0x80014B68: nop

    // 0x80014B6C: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80014B70: lbu         $t2, 0x0($t9)
    ctx->r10 = MEM_BU(ctx->r25, 0X0);
    // 0x80014B74: sh          $t2, 0x20($s1)
    MEM_H(0X20, ctx->r17) = ctx->r10;
    // 0x80014B78: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x80014B7C: addiu       $t3, $t1, 0x1
    ctx->r11 = ADD32(ctx->r9, 0X1);
    // 0x80014B80: b           L_80014848
    // 0x80014B84: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
        goto L_80014848;
    // 0x80014B84: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
L_80014B88:
    // 0x80014B88: jal         0x80014704
    // 0x80014B8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    AudioSeq_ScriptReadCompressedU16(rdram, ctx);
        goto after_15;
    // 0x80014B8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80014B90: andi        $s3, $v0, 0xFFFF
    ctx->r19 = ctx->r2 & 0XFFFF;
    // 0x80014B94: b           L_80014848
    // 0x80014B98: sh          $v0, 0x20($s1)
    MEM_H(0X20, ctx->r17) = ctx->r2;
        goto L_80014848;
    // 0x80014B98: sh          $v0, 0x20($s1)
    MEM_H(0X20, ctx->r17) = ctx->r2;
L_80014B9C:
    // 0x80014B9C: b           L_80014848
    // 0x80014BA0: sb          $zero, 0x8($s1)
    MEM_B(0X8, ctx->r17) = 0;
        goto L_80014848;
    // 0x80014BA0: sb          $zero, 0x8($s1)
    MEM_B(0X8, ctx->r17) = 0;
L_80014BA4:
    // 0x80014BA4: jal         0x800146D4
    // 0x80014BA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    AudioSeq_ScriptReadS16(rdram, ctx);
        goto after_16;
    // 0x80014BA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80014BAC: lw          $t4, 0x18($s4)
    ctx->r12 = MEM_W(ctx->r20, 0X18);
    // 0x80014BB0: andi        $t5, $v0, 0xFFFF
    ctx->r13 = ctx->r2 & 0XFFFF;
    // 0x80014BB4: andi        $s3, $v0, 0xFFFF
    ctx->r19 = ctx->r2 & 0XFFFF;
    // 0x80014BB8: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x80014BBC: sw          $t6, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r14;
    // 0x80014BC0: jal         0x800146C0
    // 0x80014BC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    AudioSeq_ScriptReadU8(rdram, ctx);
        goto after_17;
    // 0x80014BC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80014BC8: b           L_80014848
    // 0x80014BCC: sb          $v0, 0x18($s1)
    MEM_B(0X18, ctx->r17) = ctx->r2;
        goto L_80014848;
    // 0x80014BCC: sb          $v0, 0x18($s1)
    MEM_B(0X18, ctx->r17) = ctx->r2;
L_80014BD0:
    // 0x80014BD0: lbu         $t0, 0x0($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0X0);
    // 0x80014BD4: ori         $t8, $t0, 0x2
    ctx->r24 = ctx->r8 | 0X2;
    // 0x80014BD8: b           L_80014848
    // 0x80014BDC: sb          $t8, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r24;
        goto L_80014848;
    // 0x80014BDC: sb          $t8, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r24;
L_80014BE0:
    // 0x80014BE0: jal         0x800146C0
    // 0x80014BE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    AudioSeq_ScriptReadU8(rdram, ctx);
        goto after_18;
    // 0x80014BE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x80014BE8: b           L_80014848
    // 0x80014BEC: sb          $v0, 0x1($s1)
    MEM_B(0X1, ctx->r17) = ctx->r2;
        goto L_80014848;
    // 0x80014BEC: sb          $v0, 0x1($s1)
    MEM_B(0X1, ctx->r17) = ctx->r2;
L_80014BF0:
    // 0x80014BF0: andi        $v1, $a1, 0xF0
    ctx->r3 = ctx->r5 & 0XF0;
    // 0x80014BF4: addiu       $at, $zero, 0xD0
    ctx->r1 = ADD32(0, 0XD0);
    // 0x80014BF8: beq         $v1, $at, L_80014C10
    if (ctx->r3 == ctx->r1) {
        // 0x80014BFC: addiu       $at, $zero, 0xE0
        ctx->r1 = ADD32(0, 0XE0);
            goto L_80014C10;
    }
    // 0x80014BFC: addiu       $at, $zero, 0xE0
    ctx->r1 = ADD32(0, 0XE0);
    // 0x80014C00: beql        $v1, $at, L_80014C4C
    if (ctx->r3 == ctx->r1) {
        // 0x80014C04: lw          $t4, 0x94($s4)
        ctx->r12 = MEM_W(ctx->r20, 0X94);
            goto L_80014C4C;
    }
    goto skip_8;
    // 0x80014C04: lw          $t4, 0x94($s4)
    ctx->r12 = MEM_W(ctx->r20, 0X94);
    skip_8:
    // 0x80014C08: b           L_80014848
    // 0x80014C0C: nop

        goto L_80014848;
    // 0x80014C0C: nop

L_80014C10:
    // 0x80014C10: lw          $t9, 0x90($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X90);
    // 0x80014C14: andi        $t2, $a1, 0xF
    ctx->r10 = ctx->r5 & 0XF;
    // 0x80014C18: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80014C1C: addu        $t1, $t9, $t2
    ctx->r9 = ADD32(ctx->r25, ctx->r10);
    // 0x80014C20: lbu         $s3, 0x0($t1)
    ctx->r19 = MEM_BU(ctx->r9, 0X0);
    // 0x80014C24: lwc1        $f4, -0x7878($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7878);
    // 0x80014C28: multu       $s3, $s3
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80014C2C: mflo        $t3
    ctx->r11 = lo;
    // 0x80014C30: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x80014C34: nop

    // 0x80014C38: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80014C3C: div.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80014C40: b           L_80014848
    // 0x80014C44: swc1        $f6, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->f6.u32l;
        goto L_80014848;
    // 0x80014C44: swc1        $f6, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->f6.u32l;
    // 0x80014C48: lw          $t4, 0x94($s4)
    ctx->r12 = MEM_W(ctx->r20, 0X94);
L_80014C4C:
    // 0x80014C4C: andi        $t5, $a1, 0xF
    ctx->r13 = ctx->r5 & 0XF;
    // 0x80014C50: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x80014C54: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x80014C58: b           L_80014848
    // 0x80014C5C: sb          $t7, 0x4($s1)
    MEM_B(0X4, ctx->r17) = ctx->r15;
        goto L_80014848;
    // 0x80014C5C: sb          $t7, 0x4($s1)
    MEM_B(0X4, ctx->r17) = ctx->r15;
L_80014C60:
    // 0x80014C60: addiu       $at, $zero, 0xC0
    ctx->r1 = ADD32(0, 0XC0);
    // 0x80014C64: bne         $a1, $at, L_80014C88
    if (ctx->r5 != ctx->r1) {
        // 0x80014C68: andi        $v1, $a1, 0xC0
        ctx->r3 = ctx->r5 & 0XC0;
            goto L_80014C88;
    }
    // 0x80014C68: andi        $v1, $a1, 0xC0
    ctx->r3 = ctx->r5 & 0XC0;
    // 0x80014C6C: jal         0x80014704
    // 0x80014C70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    AudioSeq_ScriptReadCompressedU16(rdram, ctx);
        goto after_19;
    // 0x80014C70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x80014C74: lbu         $t8, 0x0($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X0);
    // 0x80014C78: sh          $v0, 0x38($s1)
    MEM_H(0X38, ctx->r17) = ctx->r2;
    // 0x80014C7C: ori         $t9, $t8, 0x20
    ctx->r25 = ctx->r24 | 0X20;
    // 0x80014C80: b           L_80015164
    // 0x80014C84: sb          $t9, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r25;
        goto L_80015164;
    // 0x80014C84: sb          $t9, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r25;
L_80014C88:
    // 0x80014C88: lbu         $t2, 0x0($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X0);
    // 0x80014C8C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80014C90: andi        $t1, $t2, 0xFFDF
    ctx->r9 = ctx->r10 & 0XFFDF;
    // 0x80014C94: sb          $t1, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r9;
    // 0x80014C98: lw          $t3, 0x60($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X60);
    // 0x80014C9C: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x80014CA0: sll         $t5, $t4, 6
    ctx->r13 = S32(ctx->r12 << 6);
    // 0x80014CA4: srl         $t6, $t5, 31
    ctx->r14 = S32(U32(ctx->r13) >> 31);
    // 0x80014CA8: bne         $t6, $at, L_80014DB0
    if (ctx->r14 != ctx->r1) {
        // 0x80014CAC: nop
    
            goto L_80014DB0;
    }
    // 0x80014CAC: nop

    // 0x80014CB0: andi        $v1, $a1, 0xC0
    ctx->r3 = ctx->r5 & 0XC0;
    // 0x80014CB4: beq         $v1, $zero, L_80014CD4
    if (ctx->r3 == 0) {
        // 0x80014CB8: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_80014CD4;
    }
    // 0x80014CB8: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x80014CBC: beq         $v1, $at, L_80014D10
    if (ctx->r3 == ctx->r1) {
        // 0x80014CC0: addiu       $at, $zero, 0x80
        ctx->r1 = ADD32(0, 0X80);
            goto L_80014D10;
    }
    // 0x80014CC0: addiu       $at, $zero, 0x80
    ctx->r1 = ADD32(0, 0X80);
    // 0x80014CC4: beq         $v1, $at, L_80014D3C
    if (ctx->r3 == ctx->r1) {
        // 0x80014CC8: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80014D3C;
    }
    // 0x80014CC8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80014CCC: b           L_80014D68
    // 0x80014CD0: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
        goto L_80014D68;
    // 0x80014CD0: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
L_80014CD4:
    // 0x80014CD4: jal         0x80014704
    // 0x80014CD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    AudioSeq_ScriptReadCompressedU16(rdram, ctx);
        goto after_20;
    // 0x80014CD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x80014CDC: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80014CE0: andi        $s3, $v0, 0xFFFF
    ctx->r19 = ctx->r2 & 0XFFFF;
    // 0x80014CE4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80014CE8: lbu         $a2, 0x0($v1)
    ctx->r6 = MEM_BU(ctx->r3, 0X0);
    // 0x80014CEC: addiu       $t7, $v1, 0x1
    ctx->r15 = ADD32(ctx->r3, 0X1);
    // 0x80014CF0: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80014CF4: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x80014CF8: sb          $t8, 0x4($s1)
    MEM_B(0X4, ctx->r17) = ctx->r24;
    // 0x80014CFC: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80014D00: addiu       $t2, $t9, 0x1
    ctx->r10 = ADD32(ctx->r25, 0X1);
    // 0x80014D04: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x80014D08: b           L_80014D68
    // 0x80014D0C: sh          $v0, 0x36($s1)
    MEM_H(0X36, ctx->r17) = ctx->r2;
        goto L_80014D68;
    // 0x80014D0C: sh          $v0, 0x36($s1)
    MEM_H(0X36, ctx->r17) = ctx->r2;
L_80014D10:
    // 0x80014D10: jal         0x80014704
    // 0x80014D14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    AudioSeq_ScriptReadCompressedU16(rdram, ctx);
        goto after_21;
    // 0x80014D14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x80014D18: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80014D1C: andi        $s3, $v0, 0xFFFF
    ctx->r19 = ctx->r2 & 0XFFFF;
    // 0x80014D20: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80014D24: lbu         $a2, 0x0($v1)
    ctx->r6 = MEM_BU(ctx->r3, 0X0);
    // 0x80014D28: addiu       $t1, $v1, 0x1
    ctx->r9 = ADD32(ctx->r3, 0X1);
    // 0x80014D2C: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x80014D30: sb          $zero, 0x4($s1)
    MEM_B(0X4, ctx->r17) = 0;
    // 0x80014D34: b           L_80014D68
    // 0x80014D38: sh          $v0, 0x36($s1)
    MEM_H(0X36, ctx->r17) = ctx->r2;
        goto L_80014D68;
    // 0x80014D38: sh          $v0, 0x36($s1)
    MEM_H(0X36, ctx->r17) = ctx->r2;
L_80014D3C:
    // 0x80014D3C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80014D40: lhu         $s3, 0x36($s1)
    ctx->r19 = MEM_HU(ctx->r17, 0X36);
    // 0x80014D44: lbu         $a2, 0x0($v1)
    ctx->r6 = MEM_BU(ctx->r3, 0X0);
    // 0x80014D48: addiu       $t3, $v1, 0x1
    ctx->r11 = ADD32(ctx->r3, 0X1);
    // 0x80014D4C: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x80014D50: lbu         $t5, 0x0($t3)
    ctx->r13 = MEM_BU(ctx->r11, 0X0);
    // 0x80014D54: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80014D58: sb          $t5, 0x4($s1)
    MEM_B(0X4, ctx->r17) = ctx->r13;
    // 0x80014D5C: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80014D60: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80014D64: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
L_80014D68:
    // 0x80014D68: slti        $at, $a2, 0x80
    ctx->r1 = SIGNED(ctx->r6) < 0X80 ? 1 : 0;
    // 0x80014D6C: beql        $at, $zero, L_80014D80
    if (ctx->r1 == 0) {
        // 0x80014D70: addiu       $a2, $zero, 0x7F
        ctx->r6 = ADD32(0, 0X7F);
            goto L_80014D80;
    }
    goto skip_9;
    // 0x80014D70: addiu       $a2, $zero, 0x7F
    ctx->r6 = ADD32(0, 0X7F);
    skip_9:
    // 0x80014D74: bgezl       $a2, L_80014D84
    if (SIGNED(ctx->r6) >= 0) {
        // 0x80014D78: mtc1        $a2, $f8
        ctx->f8.u32l = ctx->r6;
            goto L_80014D84;
    }
    goto skip_10;
    // 0x80014D78: mtc1        $a2, $f8
    ctx->f8.u32l = ctx->r6;
    skip_10:
    // 0x80014D7C: addiu       $a2, $zero, 0x7F
    ctx->r6 = ADD32(0, 0X7F);
L_80014D80:
    // 0x80014D80: mtc1        $a2, $f8
    ctx->f8.u32l = ctx->r6;
L_80014D84:
    // 0x80014D84: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80014D88: lwc1        $f16, -0x7874($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X7874);
    // 0x80014D8C: cvt.s.w     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    ctx->f0.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80014D90: andi        $t0, $s2, 0xC0
    ctx->r8 = ctx->r18 & 0XC0;
    // 0x80014D94: subu        $s2, $s2, $t0
    ctx->r18 = SUB32(ctx->r18, ctx->r8);
    // 0x80014D98: andi        $t8, $s2, 0xFF
    ctx->r24 = ctx->r18 & 0XFF;
    // 0x80014D9C: or          $s2, $t8, $zero
    ctx->r18 = ctx->r24 | 0;
    // 0x80014DA0: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80014DA4: div.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80014DA8: b           L_80014E0C
    // 0x80014DAC: swc1        $f18, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->f18.u32l;
        goto L_80014E0C;
    // 0x80014DAC: swc1        $f18, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->f18.u32l;
L_80014DB0:
    // 0x80014DB0: beq         $v1, $zero, L_80014DD0
    if (ctx->r3 == 0) {
        // 0x80014DB4: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_80014DD0;
    }
    // 0x80014DB4: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x80014DB8: beq         $v1, $at, L_80014DE8
    if (ctx->r3 == ctx->r1) {
        // 0x80014DBC: addiu       $at, $zero, 0x80
        ctx->r1 = ADD32(0, 0X80);
            goto L_80014DE8;
    }
    // 0x80014DBC: addiu       $at, $zero, 0x80
    ctx->r1 = ADD32(0, 0X80);
    // 0x80014DC0: beql        $v1, $at, L_80014DF8
    if (ctx->r3 == ctx->r1) {
        // 0x80014DC4: lhu         $s3, 0x36($s1)
        ctx->r19 = MEM_HU(ctx->r17, 0X36);
            goto L_80014DF8;
    }
    goto skip_11;
    // 0x80014DC4: lhu         $s3, 0x36($s1)
    ctx->r19 = MEM_HU(ctx->r17, 0X36);
    skip_11:
    // 0x80014DC8: b           L_80014DFC
    // 0x80014DCC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
        goto L_80014DFC;
    // 0x80014DCC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_80014DD0:
    // 0x80014DD0: jal         0x80014704
    // 0x80014DD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    AudioSeq_ScriptReadCompressedU16(rdram, ctx);
        goto after_22;
    // 0x80014DD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x80014DD8: andi        $s3, $v0, 0xFFFF
    ctx->r19 = ctx->r2 & 0XFFFF;
    // 0x80014DDC: sh          $v0, 0x36($s1)
    MEM_H(0X36, ctx->r17) = ctx->r2;
    // 0x80014DE0: b           L_80014DFC
    // 0x80014DE4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
        goto L_80014DFC;
    // 0x80014DE4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_80014DE8:
    // 0x80014DE8: lhu         $s3, 0x34($s1)
    ctx->r19 = MEM_HU(ctx->r17, 0X34);
    // 0x80014DEC: b           L_80014DFC
    // 0x80014DF0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
        goto L_80014DFC;
    // 0x80014DF0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80014DF4: lhu         $s3, 0x36($s1)
    ctx->r19 = MEM_HU(ctx->r17, 0X36);
L_80014DF8:
    // 0x80014DF8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_80014DFC:
    // 0x80014DFC: andi        $t9, $s2, 0xC0
    ctx->r25 = ctx->r18 & 0XC0;
    // 0x80014E00: subu        $s2, $s2, $t9
    ctx->r18 = SUB32(ctx->r18, ctx->r25);
    // 0x80014E04: andi        $t2, $s2, 0xFF
    ctx->r10 = ctx->r18 & 0XFF;
    // 0x80014E08: or          $s2, $t2, $zero
    ctx->r18 = ctx->r10 | 0;
L_80014E0C:
    // 0x80014E0C: lbu         $t1, 0x4($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X4);
    // 0x80014E10: sh          $a0, 0x38($s1)
    MEM_H(0X38, ctx->r17) = ctx->r4;
    // 0x80014E14: multu       $t1, $a0
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80014E18: mflo        $t3
    ctx->r11 = lo;
    // 0x80014E1C: sra         $t4, $t3, 8
    ctx->r12 = S32(SIGNED(ctx->r11) >> 8);
    // 0x80014E20: sh          $t4, 0x3A($s1)
    MEM_H(0X3A, ctx->r17) = ctx->r12;
    // 0x80014E24: lw          $t5, 0x0($s4)
    ctx->r13 = MEM_W(ctx->r20, 0X0);
    // 0x80014E28: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x80014E2C: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x80014E30: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x80014E34: bgezl       $t7, L_80014E50
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80014E38: lw          $v1, 0x0($t2)
        ctx->r3 = MEM_W(ctx->r10, 0X0);
            goto L_80014E50;
    }
    goto skip_12;
    // 0x80014E38: lw          $v1, 0x0($t2)
    ctx->r3 = MEM_W(ctx->r10, 0X0);
    skip_12:
    // 0x80014E3C: lbu         $t8, 0x3($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0X3);
    // 0x80014E40: andi        $t9, $t8, 0x50
    ctx->r25 = ctx->r24 & 0X50;
    // 0x80014E44: bnel        $t9, $zero, L_80014E68
    if (ctx->r25 != 0) {
        // 0x80014E48: lbu         $t5, 0x0($s1)
        ctx->r13 = MEM_BU(ctx->r17, 0X0);
            goto L_80014E68;
    }
    goto skip_13;
    // 0x80014E48: lbu         $t5, 0x0($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0X0);
    skip_13:
    // 0x80014E4C: lw          $v1, 0x0($t2)
    ctx->r3 = MEM_W(ctx->r10, 0X0);
L_80014E50:
    // 0x80014E50: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x80014E54: lw          $t7, 0x60($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X60);
    // 0x80014E58: sll         $t3, $v1, 3
    ctx->r11 = S32(ctx->r3 << 3);
    // 0x80014E5C: bgez        $t3, L_80014E74
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80014E60: sll         $t0, $v1, 4
        ctx->r8 = S32(ctx->r3 << 4);
            goto L_80014E74;
    }
    // 0x80014E60: sll         $t0, $v1, 4
    ctx->r8 = S32(ctx->r3 << 4);
    // 0x80014E64: lbu         $t5, 0x0($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0X0);
L_80014E68:
    // 0x80014E68: ori         $t6, $t5, 0x20
    ctx->r14 = ctx->r13 | 0X20;
    // 0x80014E6C: b           L_80015164
    // 0x80014E70: sb          $t6, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r14;
        goto L_80015164;
    // 0x80014E70: sb          $t6, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r14;
L_80014E74:
    // 0x80014E74: lbu         $a0, 0x2($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X2);
    // 0x80014E78: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80014E7C: bne         $a0, $at, L_80014E90
    if (ctx->r4 != ctx->r1) {
        // 0x80014E80: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_80014E90;
    }
    // 0x80014E80: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80014E84: bgezl       $t0, L_800152A4
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80014E88: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_800152A4;
    }
    goto skip_14;
    // 0x80014E88: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_14:
    // 0x80014E8C: lh          $v0, 0x1C($t8)
    ctx->r2 = MEM_H(ctx->r24, 0X1C);
L_80014E90:
    // 0x80014E90: bnel        $v0, $zero, L_80014F10
    if (ctx->r2 != 0) {
        // 0x80014E94: lh          $t5, 0xE($s4)
        ctx->r13 = MEM_H(ctx->r20, 0XE);
            goto L_80014F10;
    }
    goto skip_15;
    // 0x80014E94: lh          $t5, 0xE($s4)
    ctx->r13 = MEM_H(ctx->r20, 0XE);
    skip_15:
    // 0x80014E98: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x80014E9C: lh          $t3, 0x22($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X22);
    // 0x80014EA0: lh          $t2, 0x1E($t9)
    ctx->r10 = MEM_H(ctx->r25, 0X1E);
    // 0x80014EA4: lbu         $a0, 0x6($t9)
    ctx->r4 = MEM_BU(ctx->r25, 0X6);
    // 0x80014EA8: addu        $t1, $s2, $t2
    ctx->r9 = ADD32(ctx->r18, ctx->r10);
    // 0x80014EAC: addu        $s2, $t1, $t3
    ctx->r18 = ADD32(ctx->r9, ctx->r11);
    // 0x80014EB0: jal         0x80011DFC
    // 0x80014EB4: andi        $a1, $s2, 0xFF
    ctx->r5 = ctx->r18 & 0XFF;
    Audio_GetDrum(rdram, ctx);
        goto after_23;
    // 0x80014EB4: andi        $a1, $s2, 0xFF
    ctx->r5 = ctx->r18 & 0XFF;
    after_23:
    // 0x80014EB8: bne         $v0, $zero, L_80014ED8
    if (ctx->r2 != 0) {
        // 0x80014EBC: addiu       $v1, $v0, 0x4
        ctx->r3 = ADD32(ctx->r2, 0X4);
            goto L_80014ED8;
    }
    // 0x80014EBC: addiu       $v1, $v0, 0x4
    ctx->r3 = ADD32(ctx->r2, 0X4);
    // 0x80014EC0: lbu         $t6, 0x0($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X0);
    // 0x80014EC4: lh          $t0, 0x38($s1)
    ctx->r8 = MEM_H(ctx->r17, 0X38);
    // 0x80014EC8: ori         $t7, $t6, 0x20
    ctx->r15 = ctx->r14 | 0X20;
    // 0x80014ECC: sb          $t7, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r15;
    // 0x80014ED0: b           L_800152A0
    // 0x80014ED4: sh          $t0, 0x3C($s1)
    MEM_H(0X3C, ctx->r17) = ctx->r8;
        goto L_800152A0;
    // 0x80014ED4: sh          $t0, 0x3C($s1)
    MEM_H(0X3C, ctx->r17) = ctx->r8;
L_80014ED8:
    // 0x80014ED8: lw          $t8, 0xC($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XC);
    // 0x80014EDC: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x80014EE0: sw          $t8, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r24;
    // 0x80014EE4: lbu         $t2, 0x0($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X0);
    // 0x80014EE8: sll         $t4, $t1, 6
    ctx->r12 = S32(ctx->r9 << 6);
    // 0x80014EEC: bltz        $t4, L_80014EFC
    if (SIGNED(ctx->r12) < 0) {
        // 0x80014EF0: sb          $t2, 0x18($s1)
        MEM_B(0X18, ctx->r17) = ctx->r10;
            goto L_80014EFC;
    }
    // 0x80014EF0: sb          $t2, 0x18($s1)
    MEM_B(0X18, ctx->r17) = ctx->r10;
    // 0x80014EF4: lbu         $t9, 0x1($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X1);
    // 0x80014EF8: sb          $t9, 0x6($s1)
    MEM_B(0X6, ctx->r17) = ctx->r25;
L_80014EFC:
    // 0x80014EFC: sw          $v1, 0x48($s1)
    MEM_W(0X48, ctx->r17) = ctx->r3;
    // 0x80014F00: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80014F04: b           L_8001515C
    // 0x80014F08: swc1        $f4, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f4.u32l;
        goto L_8001515C;
    // 0x80014F08: swc1        $f4, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f4.u32l;
    // 0x80014F0C: lh          $t5, 0xE($s4)
    ctx->r13 = MEM_H(ctx->r20, 0XE);
L_80014F10:
    // 0x80014F10: lh          $t0, 0x1E($t7)
    ctx->r8 = MEM_H(ctx->r15, 0X1E);
    // 0x80014F14: lh          $t2, 0x22($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X22);
    // 0x80014F18: addu        $t6, $s2, $t5
    ctx->r14 = ADD32(ctx->r18, ctx->r13);
    // 0x80014F1C: addu        $t8, $t6, $t0
    ctx->r24 = ADD32(ctx->r14, ctx->r8);
    // 0x80014F20: addu        $s2, $t8, $t2
    ctx->r18 = ADD32(ctx->r24, ctx->r10);
    // 0x80014F24: andi        $a1, $s2, 0xFF
    ctx->r5 = ctx->r18 & 0XFF;
    // 0x80014F28: slti        $at, $a1, 0x80
    ctx->r1 = SIGNED(ctx->r5) < 0X80 ? 1 : 0;
    // 0x80014F2C: bne         $at, $zero, L_80014F44
    if (ctx->r1 != 0) {
        // 0x80014F30: or          $s2, $a1, $zero
        ctx->r18 = ctx->r5 | 0;
            goto L_80014F44;
    }
    // 0x80014F30: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x80014F34: lbu         $t4, 0x0($s1)
    ctx->r12 = MEM_BU(ctx->r17, 0X0);
    // 0x80014F38: ori         $t9, $t4, 0x20
    ctx->r25 = ctx->r12 | 0X20;
    // 0x80014F3C: b           L_8001515C
    // 0x80014F40: sb          $t9, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r25;
        goto L_8001515C;
    // 0x80014F40: sb          $t9, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r25;
L_80014F44:
    // 0x80014F44: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80014F48: bne         $a0, $at, L_80014F58
    if (ctx->r4 != ctx->r1) {
        // 0x80014F4C: lw          $t5, 0x60($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X60);
            goto L_80014F58;
    }
    // 0x80014F4C: lw          $t5, 0x60($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X60);
    // 0x80014F50: b           L_80014F5C
    // 0x80014F54: lw          $a0, 0x40($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X40);
        goto L_80014F5C;
    // 0x80014F54: lw          $a0, 0x40($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X40);
L_80014F58:
    // 0x80014F58: lw          $a0, 0x44($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X44);
L_80014F5C:
    // 0x80014F5C: lbu         $t7, 0x8($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X8);
    // 0x80014F60: beq         $t7, $zero, L_800150FC
    if (ctx->r15 == 0) {
        // 0x80014F64: nop
    
            goto L_800150FC;
    }
    // 0x80014F64: nop

    // 0x80014F68: lbu         $v0, 0x5($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X5);
    // 0x80014F6C: slt         $at, $v0, $a1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80014F70: beq         $at, $zero, L_80014F80
    if (ctx->r1 == 0) {
        // 0x80014F74: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_80014F80;
    }
    // 0x80014F74: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80014F78: b           L_80014F80
    // 0x80014F7C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
        goto L_80014F80;
    // 0x80014F7C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
L_80014F80:
    // 0x80014F80: beq         $a0, $zero, L_80014FAC
    if (ctx->r4 == 0) {
        // 0x80014F84: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80014FAC;
    }
    // 0x80014F84: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80014F88: jal         0x80011D10
    // 0x80014F8C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    Audio_GetInstrumentTunedSample(rdram, ctx);
        goto after_24;
    // 0x80014F8C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_24:
    // 0x80014F90: lw          $t6, 0x48($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X48);
    // 0x80014F94: xor         $t0, $v0, $t6
    ctx->r8 = ctx->r2 ^ ctx->r14;
    // 0x80014F98: sltiu       $t0, $t0, 0x1
    ctx->r8 = ctx->r8 < 0X1 ? 1 : 0;
    // 0x80014F9C: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    // 0x80014FA0: sw          $v0, 0x48($s1)
    MEM_W(0X48, ctx->r17) = ctx->r2;
    // 0x80014FA4: b           L_80014FB4
    // 0x80014FA8: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
        goto L_80014FB4;
    // 0x80014FA8: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
L_80014FAC:
    // 0x80014FAC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80014FB0: sw          $zero, 0x48($s1)
    MEM_W(0X48, ctx->r17) = 0;
L_80014FB4:
    // 0x80014FB4: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80014FB8: lbu         $t1, 0x5($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X5);
    // 0x80014FBC: addiu       $v1, $v1, -0x30D0
    ctx->r3 = ADD32(ctx->r3, -0X30D0);
    // 0x80014FC0: sll         $t8, $s2, 2
    ctx->r24 = S32(ctx->r18 << 2);
    // 0x80014FC4: addu        $t2, $v1, $t8
    ctx->r10 = ADD32(ctx->r3, ctx->r24);
    // 0x80014FC8: lwc1        $f6, 0x0($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X0);
    // 0x80014FCC: lbu         $t9, 0x8($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X8);
    // 0x80014FD0: sll         $t3, $t1, 2
    ctx->r11 = S32(ctx->r9 << 2);
    // 0x80014FD4: addu        $t4, $v1, $t3
    ctx->r12 = ADD32(ctx->r3, ctx->r11);
    // 0x80014FD8: lwc1        $f8, 0x0($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X0);
    // 0x80014FDC: mul.s       $f2, $f6, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80014FE0: addiu       $at, $zero, -0x81
    ctx->r1 = ADD32(0, -0X81);
    // 0x80014FE4: and         $t5, $t9, $at
    ctx->r13 = ctx->r25 & ctx->r1;
    // 0x80014FE8: addiu       $t7, $t5, -0x1
    ctx->r15 = ADD32(ctx->r13, -0X1);
    // 0x80014FEC: sltiu       $at, $t7, 0x5
    ctx->r1 = ctx->r15 < 0X5 ? 1 : 0;
    // 0x80014FF0: mul.s       $f14, $f8, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80014FF4: beq         $at, $zero, L_80015028
    if (ctx->r1 == 0) {
        // 0x80014FF8: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80015028;
    }
    // 0x80014FF8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80014FFC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80015000: addu        $at, $at, $t7
    gpr jr_addend_80015008 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80015004: lw          $t7, -0x7870($at)
    ctx->r15 = ADD32(ctx->r1, -0X7870);
    // 0x80015008: jr          $t7
    // 0x8001500C: nop

    switch (jr_addend_80015008 >> 2) {
        case 0: goto L_80015010; break;
        case 1: goto L_8001501C; break;
        case 2: goto L_80015010; break;
        case 3: goto L_8001501C; break;
        case 4: goto L_80015010; break;
        default: switch_error(__func__, 0x80015008, 0x800C8790);
    }
    // 0x8001500C: nop

L_80015010:
    // 0x80015010: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x80015014: b           L_80015030
    // 0x80015018: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
        goto L_80015030;
    // 0x80015018: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
L_8001501C:
    // 0x8001501C: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
    // 0x80015020: b           L_80015030
    // 0x80015024: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
        goto L_80015030;
    // 0x80015024: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
L_80015028:
    // 0x80015028: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
    // 0x8001502C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_80015030:
    // 0x80015030: div.s       $f10, $f0, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = DIV_S(ctx->f0.fl, ctx->f12.fl);
    // 0x80015034: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80015038: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8001503C: addiu       $v0, $s1, 0x8
    ctx->r2 = ADD32(ctx->r17, 0X8);
    // 0x80015040: lui         $at, 0x46FE
    ctx->r1 = S32(0X46FE << 16);
    // 0x80015044: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80015048: swc1        $f18, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f18.u32l;
    // 0x8001504C: lbu         $t6, 0x8($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X8);
    // 0x80015050: andi        $t0, $t6, 0x80
    ctx->r8 = ctx->r14 & 0X80;
    // 0x80015054: beql        $t0, $zero, L_800150B4
    if (ctx->r8 == 0) {
        // 0x80015058: lhu         $t4, 0x20($s1)
        ctx->r12 = MEM_HU(ctx->r17, 0X20);
            goto L_800150B4;
    }
    goto skip_16;
    // 0x80015058: lhu         $t4, 0x20($s1)
    ctx->r12 = MEM_HU(ctx->r17, 0X20);
    skip_16:
    // 0x8001505C: lhu         $t8, 0x8($s4)
    ctx->r24 = MEM_HU(ctx->r20, 0X8);
    // 0x80015060: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x80015064: lh          $t1, 0x5CA4($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X5CA4);
    // 0x80015068: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8001506C: lh          $t2, 0x38($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X38);
    // 0x80015070: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80015074: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80015078: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x8001507C: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x80015080: lhu         $t3, 0x20($s1)
    ctx->r11 = MEM_HU(ctx->r17, 0X20);
    // 0x80015084: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80015088: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8001508C: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x80015090: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80015094: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80015098: mul.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x8001509C: nop

    // 0x800150A0: mul.s       $f18, $f8, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x800150A4: div.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = DIV_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800150A8: b           L_800150D0
    // 0x800150AC: swc1        $f6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f6.u32l;
        goto L_800150D0;
    // 0x800150AC: swc1        $f6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f6.u32l;
    // 0x800150B0: lhu         $t4, 0x20($s1)
    ctx->r12 = MEM_HU(ctx->r17, 0X20);
L_800150B4:
    // 0x800150B4: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x800150B8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800150BC: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x800150C0: nop

    // 0x800150C4: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800150C8: div.s       $f10, $f16, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = DIV_S(ctx->f16.fl, ctx->f4.fl);
    // 0x800150CC: swc1        $f10, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f10.u32l;
L_800150D0:
    // 0x800150D0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800150D4: addiu       $at, $zero, -0x81
    ctx->r1 = ADD32(0, -0X81);
    // 0x800150D8: swc1        $f18, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f18.u32l;
    // 0x800150DC: lbu         $t9, 0x8($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X8);
    // 0x800150E0: swc1        $f12, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f12.u32l;
    // 0x800150E4: and         $t5, $t9, $at
    ctx->r13 = ctx->r25 & ctx->r1;
    // 0x800150E8: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800150EC: bnel        $t5, $at, L_80015160
    if (ctx->r13 != ctx->r1) {
        // 0x800150F0: lh          $t3, 0x38($s1)
        ctx->r11 = MEM_H(ctx->r17, 0X38);
            goto L_80015160;
    }
    goto skip_17;
    // 0x800150F0: lh          $t3, 0x38($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X38);
    skip_17:
    // 0x800150F4: b           L_8001515C
    // 0x800150F8: sb          $s2, 0x5($s1)
    MEM_B(0X5, ctx->r17) = ctx->r18;
        goto L_8001515C;
    // 0x800150F8: sb          $s2, 0x5($s1)
    MEM_B(0X5, ctx->r17) = ctx->r18;
L_800150FC:
    // 0x800150FC: beq         $a0, $zero, L_80015144
    if (ctx->r4 == 0) {
        // 0x80015100: lui         $v1, 0x800E
        ctx->r3 = S32(0X800E << 16);
            goto L_80015144;
    }
    // 0x80015100: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80015104: jal         0x80011D10
    // 0x80015108: nop

    Audio_GetInstrumentTunedSample(rdram, ctx);
        goto after_25;
    // 0x80015108: nop

    after_25:
    // 0x8001510C: lw          $t7, 0x48($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X48);
    // 0x80015110: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80015114: addiu       $v1, $v1, -0x30D0
    ctx->r3 = ADD32(ctx->r3, -0X30D0);
    // 0x80015118: xor         $t6, $v0, $t7
    ctx->r14 = ctx->r2 ^ ctx->r15;
    // 0x8001511C: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80015120: sw          $t6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r14;
    // 0x80015124: sw          $v0, 0x48($s1)
    MEM_W(0X48, ctx->r17) = ctx->r2;
    // 0x80015128: sll         $t0, $s2, 2
    ctx->r8 = S32(ctx->r18 << 2);
    // 0x8001512C: addu        $t8, $v1, $t0
    ctx->r24 = ADD32(ctx->r3, ctx->r8);
    // 0x80015130: lwc1        $f6, 0x0($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X0);
    // 0x80015134: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80015138: mul.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8001513C: b           L_8001515C
    // 0x80015140: swc1        $f16, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f16.u32l;
        goto L_8001515C;
    // 0x80015140: swc1        $f16, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f16.u32l;
L_80015144:
    // 0x80015144: addiu       $v1, $v1, -0x30D0
    ctx->r3 = ADD32(ctx->r3, -0X30D0);
    // 0x80015148: sll         $t2, $s2, 2
    ctx->r10 = S32(ctx->r18 << 2);
    // 0x8001514C: sw          $zero, 0x48($s1)
    MEM_W(0X48, ctx->r17) = 0;
    // 0x80015150: addu        $t1, $v1, $t2
    ctx->r9 = ADD32(ctx->r3, ctx->r10);
    // 0x80015154: lwc1        $f4, 0x0($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X0);
    // 0x80015158: swc1        $f4, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f4.u32l;
L_8001515C:
    // 0x8001515C: lh          $t3, 0x38($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X38);
L_80015160:
    // 0x80015160: sh          $t3, 0x3C($s1)
    MEM_H(0X3C, ctx->r17) = ctx->r11;
L_80015164:
    // 0x80015164: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80015168: sll         $a1, $v0, 2
    ctx->r5 = S32(ctx->r2 << 2);
    // 0x8001516C: srl         $t4, $a1, 31
    ctx->r12 = S32(U32(ctx->r5) >> 31);
    // 0x80015170: bne         $t4, $zero, L_800151C4
    if (ctx->r12 != 0) {
        // 0x80015174: or          $a1, $t4, $zero
        ctx->r5 = ctx->r12 | 0;
            goto L_800151C4;
    }
    // 0x80015174: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
    // 0x80015178: lw          $v1, 0x48($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X48);
    // 0x8001517C: beql        $v1, $zero, L_800151C8
    if (ctx->r3 == 0) {
        // 0x80015180: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_800151C8;
    }
    goto skip_18;
    // 0x80015180: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    skip_18:
    // 0x80015184: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x80015188: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8001518C: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    // 0x80015190: srl         $t5, $a0, 28
    ctx->r13 = S32(U32(ctx->r4) >> 28);
    // 0x80015194: bne         $t5, $at, L_800151C4
    if (ctx->r13 != ctx->r1) {
        // 0x80015198: sll         $t7, $a0, 4
        ctx->r15 = S32(ctx->r4 << 4);
            goto L_800151C4;
    }
    // 0x80015198: sll         $t7, $a0, 4
    ctx->r15 = S32(ctx->r4 << 4);
    // 0x8001519C: srl         $t6, $t7, 30
    ctx->r14 = S32(U32(ctx->r15) >> 30);
    // 0x800151A0: beql        $t6, $zero, L_800151C8
    if (ctx->r14 == 0) {
        // 0x800151A4: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_800151C8;
    }
    goto skip_19;
    // 0x800151A4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    skip_19:
    // 0x800151A8: lbu         $t8, 0x0($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X0);
    // 0x800151AC: ori         $t2, $t8, 0x20
    ctx->r10 = ctx->r24 | 0X20;
    // 0x800151B0: sb          $t2, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r10;
    // 0x800151B4: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800151B8: sll         $a1, $v0, 2
    ctx->r5 = S32(ctx->r2 << 2);
    // 0x800151BC: srl         $t1, $a1, 31
    ctx->r9 = S32(U32(ctx->r5) >> 31);
    // 0x800151C0: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
L_800151C4:
    // 0x800151C4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_800151C8:
    // 0x800151C8: bne         $a1, $at, L_800151F8
    if (ctx->r5 != ctx->r1) {
        // 0x800151CC: sll         $t7, $v0, 3
        ctx->r15 = S32(ctx->r2 << 3);
            goto L_800151F8;
    }
    // 0x800151CC: sll         $t7, $v0, 3
    ctx->r15 = S32(ctx->r2 << 3);
    // 0x800151D0: lw          $t3, 0x40($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X40);
    // 0x800151D4: sll         $t9, $v0, 3
    ctx->r25 = S32(ctx->r2 << 3);
    // 0x800151D8: bne         $t3, $zero, L_800151E8
    if (ctx->r11 != 0) {
        // 0x800151DC: nop
    
            goto L_800151E8;
    }
    // 0x800151DC: nop

    // 0x800151E0: bgezl       $t9, L_800152A4
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800151E4: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_800152A4;
    }
    goto skip_20;
    // 0x800151E4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_20:
L_800151E8:
    // 0x800151E8: jal         0x8001266C
    // 0x800151EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Audio_SeqLayerNoteDecay(rdram, ctx);
        goto after_26;
    // 0x800151EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_26:
    // 0x800151F0: b           L_800152A4
    // 0x800151F4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_800152A4;
    // 0x800151F4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800151F8:
    // 0x800151F8: bltz        $t7, L_80015208
    if (SIGNED(ctx->r15) < 0) {
        // 0x800151FC: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_80015208;
    }
    // 0x800151FC: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80015200: b           L_8001526C
    // 0x80015204: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
        goto L_8001526C;
    // 0x80015204: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_80015208:
    // 0x80015208: lw          $a0, 0x40($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X40);
    // 0x8001520C: beq         $a0, $zero, L_80015224
    if (ctx->r4 == 0) {
        // 0x80015210: nop
    
            goto L_80015224;
    }
    // 0x80015210: nop

    // 0x80015214: lbu         $t6, 0x3($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X3);
    // 0x80015218: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x8001521C: bne         $t6, $zero, L_8001522C
    if (ctx->r14 != 0) {
        // 0x80015220: nop
    
            goto L_8001522C;
    }
    // 0x80015220: nop

L_80015224:
    // 0x80015224: b           L_8001526C
    // 0x80015228: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
        goto L_8001526C;
    // 0x80015228: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_8001522C:
    // 0x8001522C: bnel        $t0, $zero, L_80015248
    if (ctx->r8 != 0) {
        // 0x80015230: lw          $t8, 0x44($a0)
        ctx->r24 = MEM_W(ctx->r4, 0X44);
            goto L_80015248;
    }
    goto skip_21;
    // 0x80015230: lw          $t8, 0x44($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X44);
    skip_21:
    // 0x80015234: jal         0x8001266C
    // 0x80015238: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Audio_SeqLayerNoteDecay(rdram, ctx);
        goto after_27;
    // 0x80015238: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_27:
    // 0x8001523C: b           L_8001526C
    // 0x80015240: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
        goto L_8001526C;
    // 0x80015240: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x80015244: lw          $t8, 0x44($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X44);
L_80015248:
    // 0x80015248: beql        $s1, $t8, L_8001525C
    if (ctx->r17 == ctx->r24) {
        // 0x8001524C: lw          $t2, 0x48($s1)
        ctx->r10 = MEM_W(ctx->r17, 0X48);
            goto L_8001525C;
    }
    goto skip_22;
    // 0x8001524C: lw          $t2, 0x48($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X48);
    skip_22:
    // 0x80015250: b           L_8001526C
    // 0x80015254: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
        goto L_8001526C;
    // 0x80015254: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x80015258: lw          $t2, 0x48($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X48);
L_8001525C:
    // 0x8001525C: bne         $t2, $zero, L_8001526C
    if (ctx->r10 != 0) {
        // 0x80015260: nop
    
            goto L_8001526C;
    }
    // 0x80015260: nop

    // 0x80015264: jal         0x800127B0
    // 0x80015268: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    Audio_InitSyntheticWave(rdram, ctx);
        goto after_28;
    // 0x80015268: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_28:
L_8001526C:
    // 0x8001526C: beql        $s2, $zero, L_80015284
    if (ctx->r18 == 0) {
        // 0x80015270: lw          $a0, 0x40($s1)
        ctx->r4 = MEM_W(ctx->r17, 0X40);
            goto L_80015284;
    }
    goto skip_23;
    // 0x80015270: lw          $a0, 0x40($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X40);
    skip_23:
    // 0x80015274: jal         0x8001301C
    // 0x80015278: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Audio_AllocNote(rdram, ctx);
        goto after_29;
    // 0x80015278: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_29:
    // 0x8001527C: sw          $v0, 0x40($s1)
    MEM_W(0X40, ctx->r17) = ctx->r2;
    // 0x80015280: lw          $a0, 0x40($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X40);
L_80015284:
    // 0x80015284: beql        $a0, $zero, L_800152A4
    if (ctx->r4 == 0) {
        // 0x80015288: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_800152A4;
    }
    goto skip_24;
    // 0x80015288: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_24:
    // 0x8001528C: lw          $t1, 0x44($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X44);
    // 0x80015290: bnel        $s1, $t1, L_800152A4
    if (ctx->r17 != ctx->r9) {
        // 0x80015294: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_800152A4;
    }
    goto skip_25;
    // 0x80015294: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_25:
    // 0x80015298: jal         0x80013A84
    // 0x8001529C: nop

    Audio_NoteVibratoInit(rdram, ctx);
        goto after_30;
    // 0x8001529C: nop

    after_30:
L_800152A0:
    // 0x800152A0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800152A4:
    // 0x800152A4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800152A8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800152AC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800152B0: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800152B4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800152B8: jr          $ra
    // 0x800152BC: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x800152BC: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void Math_Atan2F_XY(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800051F8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800051FC: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80005200: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80005204: mov.s       $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    ctx->f20.fl = ctx->f12.fl;
    // 0x80005208: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8000520C: c.eq.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl == ctx->f2.fl;
    // 0x80005210: nop

    // 0x80005214: bc1fl       L_80005238
    if (!c1cs) {
        // 0x80005218: c.eq.s      $f20, $f2
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl == ctx->f2.fl;
            goto L_80005238;
    }
    goto skip_0;
    // 0x80005218: c.eq.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl == ctx->f2.fl;
    skip_0:
    // 0x8000521C: c.eq.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl == ctx->f2.fl;
    // 0x80005220: nop

    // 0x80005224: bc1fl       L_80005238
    if (!c1cs) {
        // 0x80005228: c.eq.s      $f20, $f2
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl == ctx->f2.fl;
            goto L_80005238;
    }
    goto skip_1;
    // 0x80005228: c.eq.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl == ctx->f2.fl;
    skip_1:
    // 0x8000522C: b           L_8000530C
    // 0x80005230: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_8000530C;
    // 0x80005230: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x80005234: c.eq.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl == ctx->f2.fl;
L_80005238:
    // 0x80005238: nop

    // 0x8000523C: bc1fl       L_8000526C
    if (!c1cs) {
        // 0x80005240: c.eq.s      $f14, $f2
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl == ctx->f2.fl;
            goto L_8000526C;
    }
    goto skip_2;
    // 0x80005240: c.eq.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl == ctx->f2.fl;
    skip_2:
    // 0x80005244: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    // 0x80005248: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8000524C: bc1f        L_80005260
    if (!c1cs) {
        // 0x80005250: nop
    
            goto L_80005260;
    }
    // 0x80005250: nop

    // 0x80005254: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80005258: b           L_8000530C
    // 0x8000525C: lwc1        $f0, -0x7F18($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7F18);
        goto L_8000530C;
    // 0x8000525C: lwc1        $f0, -0x7F18($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7F18);
L_80005260:
    // 0x80005260: b           L_8000530C
    // 0x80005264: lwc1        $f0, -0x7F14($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7F14);
        goto L_8000530C;
    // 0x80005264: lwc1        $f0, -0x7F14($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7F14);
    // 0x80005268: c.eq.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl == ctx->f2.fl;
L_8000526C:
    // 0x8000526C: nop

    // 0x80005270: bc1fl       L_8000529C
    if (!c1cs) {
        // 0x80005274: c.lt.s      $f20, $f2
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl < ctx->f2.fl;
            goto L_8000529C;
    }
    goto skip_3;
    // 0x80005274: c.lt.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl < ctx->f2.fl;
    skip_3:
    // 0x80005278: c.lt.s      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.fl < ctx->f20.fl;
    // 0x8000527C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80005280: bc1f        L_80005290
    if (!c1cs) {
        // 0x80005284: nop
    
            goto L_80005290;
    }
    // 0x80005284: nop

    // 0x80005288: b           L_8000530C
    // 0x8000528C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_8000530C;
    // 0x8000528C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_80005290:
    // 0x80005290: b           L_8000530C
    // 0x80005294: lwc1        $f0, -0x7F10($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7F10);
        goto L_8000530C;
    // 0x80005294: lwc1        $f0, -0x7F10($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7F10);
    // 0x80005298: c.lt.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl < ctx->f2.fl;
L_8000529C:
    // 0x8000529C: nop

    // 0x800052A0: bc1f        L_80005304
    if (!c1cs) {
        // 0x800052A4: nop
    
            goto L_80005304;
    }
    // 0x800052A4: nop

    // 0x800052A8: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    // 0x800052AC: nop

    // 0x800052B0: bc1fl       L_800052E4
    if (!c1cs) {
        // 0x800052B4: div.s       $f8, $f20, $f14
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = DIV_S(ctx->f20.fl, ctx->f14.fl);
            goto L_800052E4;
    }
    goto skip_4;
    // 0x800052B4: div.s       $f8, $f20, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = DIV_S(ctx->f20.fl, ctx->f14.fl);
    skip_4:
    // 0x800052B8: div.s       $f4, $f20, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = DIV_S(ctx->f20.fl, ctx->f14.fl);
    // 0x800052BC: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
    // 0x800052C0: abs.d       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = fabs(ctx->f0.d);
    // 0x800052C4: jal         0x8001FBE8
    // 0x800052C8: cvt.s.d     $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f12.fl = CVT_S_D(ctx->f0.d);
    Math_FAtanF(rdram, ctx);
        goto after_0;
    // 0x800052C8: cvt.s.d     $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f12.fl = CVT_S_D(ctx->f0.d);
    after_0:
    // 0x800052CC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800052D0: lwc1        $f6, -0x7F0C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7F0C);
    // 0x800052D4: sub.s       $f0, $f6, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x800052D8: b           L_8000530C
    // 0x800052DC: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
        goto L_8000530C;
    // 0x800052DC: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800052E0: div.s       $f8, $f20, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = DIV_S(ctx->f20.fl, ctx->f14.fl);
L_800052E4:
    // 0x800052E4: cvt.d.s     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f0.d = CVT_D_S(ctx->f8.fl);
    // 0x800052E8: abs.d       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = fabs(ctx->f0.d);
    // 0x800052EC: jal         0x8001FBE8
    // 0x800052F0: cvt.s.d     $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f12.fl = CVT_S_D(ctx->f0.d);
    Math_FAtanF(rdram, ctx);
        goto after_1;
    // 0x800052F0: cvt.s.d     $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f12.fl = CVT_S_D(ctx->f0.d);
    after_1:
    // 0x800052F4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800052F8: lwc1        $f10, -0x7F08($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X7F08);
    // 0x800052FC: b           L_8000530C
    // 0x80005300: sub.s       $f0, $f10, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f0.fl;
        goto L_8000530C;
    // 0x80005300: sub.s       $f0, $f10, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f0.fl;
L_80005304:
    // 0x80005304: jal         0x8001FBE8
    // 0x80005308: div.s       $f12, $f20, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = DIV_S(ctx->f20.fl, ctx->f14.fl);
    Math_FAtanF(rdram, ctx);
        goto after_2;
    // 0x80005308: div.s       $f12, $f20, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = DIV_S(ctx->f20.fl, ctx->f14.fl);
    after_2:
L_8000530C:
    // 0x8000530C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80005310: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80005314: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80005318: jr          $ra
    // 0x8000531C: nop

    return;
    // 0x8000531C: nop

;}
RECOMP_FUNC void ActorEvent_FlamePillar_Spawn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EB64: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006EB68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006EB6C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8006EB70: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8006EB74: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8006EB78: addiu       $v0, $v0, 0x37E0
    ctx->r2 = ADD32(ctx->r2, 0X37E0);
    // 0x8006EB7C: addiu       $a0, $a0, 0x1C88
    ctx->r4 = ADD32(ctx->r4, 0X1C88);
    // 0x8006EB80: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
L_8006EB84:
    // 0x8006EB84: bnel        $t6, $zero, L_8006EBA8
    if (ctx->r14 != 0) {
        // 0x8006EB88: addiu       $a0, $a0, 0x8C
        ctx->r4 = ADD32(ctx->r4, 0X8C);
            goto L_8006EBA8;
    }
    goto skip_0;
    // 0x8006EB88: addiu       $a0, $a0, 0x8C
    ctx->r4 = ADD32(ctx->r4, 0X8C);
    skip_0:
    // 0x8006EB8C: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8006EB90: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x8006EB94: jal         0x8006EAC4
    // 0x8006EB98: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    ActorEvent_FlamePillar_Setup(rdram, ctx);
        goto after_0;
    // 0x8006EB98: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    after_0:
    // 0x8006EB9C: b           L_8006EBB4
    // 0x8006EBA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8006EBB4;
    // 0x8006EBA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006EBA4: addiu       $a0, $a0, 0x8C
    ctx->r4 = ADD32(ctx->r4, 0X8C);
L_8006EBA8:
    // 0x8006EBA8: bnel        $a0, $v0, L_8006EB84
    if (ctx->r4 != ctx->r2) {
        // 0x8006EBAC: lbu         $t6, 0x0($a0)
        ctx->r14 = MEM_BU(ctx->r4, 0X0);
            goto L_8006EB84;
    }
    goto skip_1;
    // 0x8006EBAC: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    skip_1:
    // 0x8006EBB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8006EBB4:
    // 0x8006EBB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006EBB8: jr          $ra
    // 0x8006EBBC: nop

    return;
    // 0x8006EBBC: nop

;}
RECOMP_FUNC void CoIBeam_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B95C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006B960: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8006B964: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8006B968: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8006B96C: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8006B970: lwc1        $f6, 0x64($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X64);
    // 0x8006B974: lwc1        $f0, 0x68($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X68);
    // 0x8006B978: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8006B97C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8006B980: lwc1        $f4, 0x6C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x8006B984: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8006B988: add.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x8006B98C: lw          $v0, 0x48($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X48);
    // 0x8006B990: swc1        $f8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f8.u32l;
    // 0x8006B994: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8006B998: swc1        $f16, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f16.u32l;
    // 0x8006B99C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8006B9A0: beq         $v0, $zero, L_8006B9C4
    if (ctx->r2 == 0) {
        // 0x8006B9A4: swc1        $f6, 0xC($s0)
        MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
            goto L_8006B9C4;
    }
    // 0x8006B9A4: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
    // 0x8006B9A8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8006B9AC: beq         $v0, $at, L_8006BA3C
    if (ctx->r2 == ctx->r1) {
        // 0x8006B9B0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8006BA3C;
    }
    // 0x8006B9B0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8006B9B4: beql        $v0, $at, L_8006BA54
    if (ctx->r2 == ctx->r1) {
        // 0x8006B9B8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8006BA54;
    }
    goto skip_0;
    // 0x8006B9B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8006B9BC: b           L_8006BA54
    // 0x8006B9C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8006BA54;
    // 0x8006B9C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8006B9C4:
    // 0x8006B9C4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8006B9C8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8006B9CC: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8006B9D0: sub.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x8006B9D4: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8006B9D8: lui         $a0, 0x1913
    ctx->r4 = S32(0X1913 << 16);
    // 0x8006B9DC: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x8006B9E0: swc1        $f10, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->f10.u32l;
    // 0x8006B9E4: lwc1        $f16, 0x7940($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7940);
    // 0x8006B9E8: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x8006B9EC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8006B9F0: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8006B9F4: addiu       $t6, $t6, 0x5D3C
    ctx->r14 = ADD32(ctx->r14, 0X5D3C);
    // 0x8006B9F8: add.s       $f2, $f16, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8006B9FC: ori         $a0, $a0, 0x3
    ctx->r4 = ctx->r4 | 0X3;
    // 0x8006BA00: addiu       $a1, $s0, 0x70
    ctx->r5 = ADD32(ctx->r16, 0X70);
    // 0x8006BA04: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8006BA08: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x8006BA0C: nop

    // 0x8006BA10: bc1fl       L_8006BA54
    if (!c1cs) {
        // 0x8006BA14: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8006BA54;
    }
    goto skip_1;
    // 0x8006BA14: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x8006BA18: swc1        $f2, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f2.u32l;
    // 0x8006BA1C: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8006BA20: jal         0x80019218
    // 0x8006BA24: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    Audio_PlaySfx(rdram, ctx);
        goto after_0;
    // 0x8006BA24: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_0:
    // 0x8006BA28: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8006BA2C: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8006BA30: sw          $t7, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->r15;
    // 0x8006BA34: b           L_8006BA50
    // 0x8006BA38: swc1        $f6, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->f6.u32l;
        goto L_8006BA50;
    // 0x8006BA38: swc1        $f6, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->f6.u32l;
L_8006BA3C:
    // 0x8006BA3C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8006BA40: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8006BA44: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8006BA48: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8006BA4C: swc1        $f16, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f16.u32l;
L_8006BA50:
    // 0x8006BA50: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8006BA54:
    // 0x8006BA54: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8006BA58: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8006BA5C: jr          $ra
    // 0x8006BA60: nop

    return;
    // 0x8006BA60: nop

;}
RECOMP_FUNC void Actor_Despawn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066254: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80066258: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006625C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80066260: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x80066264: lw          $t6, 0x78E8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X78E8);
    // 0x80066268: beql        $t6, $zero, L_800662CC
    if (ctx->r14 == 0) {
        // 0x8006626C: lhu         $t5, 0x2($a2)
        ctx->r13 = MEM_HU(ctx->r6, 0X2);
            goto L_800662CC;
    }
    goto skip_0;
    // 0x8006626C: lhu         $t5, 0x2($a2)
    ctx->r13 = MEM_HU(ctx->r6, 0X2);
    skip_0:
    // 0x80066270: lh          $v1, 0xD4($a2)
    ctx->r3 = MEM_H(ctx->r6, 0XD4);
    // 0x80066274: blez        $v1, L_8006653C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80066278: slti        $at, $v1, 0x5
        ctx->r1 = SIGNED(ctx->r3) < 0X5 ? 1 : 0;
            goto L_8006653C;
    }
    // 0x80066278: slti        $at, $v1, 0x5
    ctx->r1 = SIGNED(ctx->r3) < 0X5 ? 1 : 0;
    // 0x8006627C: beq         $at, $zero, L_8006653C
    if (ctx->r1 == 0) {
        // 0x80066280: lui         $v0, 0x8018
        ctx->r2 = S32(0X8018 << 16);
            goto L_8006653C;
    }
    // 0x80066280: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80066284: addiu       $v0, $v0, -0x7898
    ctx->r2 = ADD32(ctx->r2, -0X7898);
    // 0x80066288: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x8006628C: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x80066290: addiu       $t1, $t1, 0x7C30
    ctx->r9 = ADD32(ctx->r9, 0X7C30);
    // 0x80066294: bne         $t7, $zero, L_800662B0
    if (ctx->r15 != 0) {
        // 0x80066298: sll         $t0, $v1, 1
        ctx->r8 = S32(ctx->r3 << 1);
            goto L_800662B0;
    }
    // 0x80066298: sll         $t0, $v1, 1
    ctx->r8 = S32(ctx->r3 << 1);
    // 0x8006629C: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x800662A0: bnel        $t8, $zero, L_800662B4
    if (ctx->r24 != 0) {
        // 0x800662A4: addu        $v0, $t0, $t1
        ctx->r2 = ADD32(ctx->r8, ctx->r9);
            goto L_800662B4;
    }
    goto skip_1;
    // 0x800662A4: addu        $v0, $t0, $t1
    ctx->r2 = ADD32(ctx->r8, ctx->r9);
    skip_1:
    // 0x800662A8: lw          $t9, 0x8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X8);
    // 0x800662AC: beq         $t9, $zero, L_8006653C
    if (ctx->r25 == 0) {
        // 0x800662B0: addu        $v0, $t0, $t1
        ctx->r2 = ADD32(ctx->r8, ctx->r9);
            goto L_8006653C;
    }
L_800662B0:
    // 0x800662B0: addu        $v0, $t0, $t1
    ctx->r2 = ADD32(ctx->r8, ctx->r9);
L_800662B4:
    // 0x800662B4: lhu         $t2, -0x2($v0)
    ctx->r10 = MEM_HU(ctx->r2, -0X2);
    // 0x800662B8: lbu         $t3, 0x3C($a2)
    ctx->r11 = MEM_BU(ctx->r6, 0X3C);
    // 0x800662BC: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x800662C0: b           L_8006653C
    // 0x800662C4: sh          $t4, -0x2($v0)
    MEM_H(-0X2, ctx->r2) = ctx->r12;
        goto L_8006653C;
    // 0x800662C4: sh          $t4, -0x2($v0)
    MEM_H(-0X2, ctx->r2) = ctx->r12;
    // 0x800662C8: lhu         $t5, 0x2($a2)
    ctx->r13 = MEM_HU(ctx->r6, 0X2);
L_800662CC:
    // 0x800662CC: addiu       $at, $zero, 0xC5
    ctx->r1 = ADD32(0, 0XC5);
    // 0x800662D0: bnel        $t5, $at, L_800662EC
    if (ctx->r13 != ctx->r1) {
        // 0x800662D4: lh          $t7, 0xD4($a2)
        ctx->r15 = MEM_H(ctx->r6, 0XD4);
            goto L_800662EC;
    }
    goto skip_2;
    // 0x800662D4: lh          $t7, 0xD4($a2)
    ctx->r15 = MEM_H(ctx->r6, 0XD4);
    skip_2:
    // 0x800662D8: lh          $t6, 0xB6($a2)
    ctx->r14 = MEM_H(ctx->r6, 0XB6);
    // 0x800662DC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800662E0: beql        $a0, $t6, L_80066540
    if (ctx->r4 == ctx->r14) {
        // 0x800662E4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80066540;
    }
    goto skip_3;
    // 0x800662E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x800662E8: lh          $t7, 0xD4($a2)
    ctx->r15 = MEM_H(ctx->r6, 0XD4);
L_800662EC:
    // 0x800662EC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800662F0: bnel        $a0, $t7, L_800663DC
    if (ctx->r4 != ctx->r15) {
        // 0x800662F4: lbu         $v0, 0x44($a2)
        ctx->r2 = MEM_BU(ctx->r6, 0X44);
            goto L_800663DC;
    }
    goto skip_4;
    // 0x800662F4: lbu         $v0, 0x44($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X44);
    skip_4:
    // 0x800662F8: lbu         $v0, 0x3C($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X3C);
    // 0x800662FC: lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // 0x80066300: addiu       $v1, $v1, 0x1A98
    ctx->r3 = ADD32(ctx->r3, 0X1A98);
    // 0x80066304: beql        $v0, $zero, L_800663DC
    if (ctx->r2 == 0) {
        // 0x80066308: lbu         $v0, 0x44($a2)
        ctx->r2 = MEM_BU(ctx->r6, 0X44);
            goto L_800663DC;
    }
    goto skip_5;
    // 0x80066308: lbu         $v0, 0x44($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X44);
    skip_5:
    // 0x8006630C: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x80066310: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x80066314: addiu       $t0, $zero, 0xF
    ctx->r8 = ADD32(0, 0XF);
    // 0x80066318: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x8006631C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80066320: lw          $t1, 0x7880($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7880);
    // 0x80066324: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80066328: sw          $t0, 0x7850($at)
    MEM_W(0X7850, ctx->r1) = ctx->r8;
    // 0x8006632C: bne         $a0, $t1, L_800663A4
    if (ctx->r4 != ctx->r9) {
        // 0x80066330: lui         $v0, 0x8016
        ctx->r2 = S32(0X8016 << 16);
            goto L_800663A4;
    }
    // 0x80066330: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x80066334: lhu         $v0, 0x1A62($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X1A62);
    // 0x80066338: beq         $v0, $zero, L_800663A4
    if (ctx->r2 == 0) {
        // 0x8006633C: addiu       $t2, $v0, -0x4
        ctx->r10 = ADD32(ctx->r2, -0X4);
            goto L_800663A4;
    }
    // 0x8006633C: addiu       $t2, $v0, -0x4
    ctx->r10 = ADD32(ctx->r2, -0X4);
    // 0x80066340: sltiu       $at, $t2, 0x1A
    ctx->r1 = ctx->r10 < 0X1A ? 1 : 0;
    // 0x80066344: beq         $at, $zero, L_8006639C
    if (ctx->r1 == 0) {
        // 0x80066348: sll         $t2, $t2, 2
        ctx->r10 = S32(ctx->r10 << 2);
            goto L_8006639C;
    }
    // 0x80066348: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8006634C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80066350: addu        $at, $at, $t2
    gpr jr_addend_80066358 = ctx->r10;
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x80066354: lw          $t2, 0x68C0($at)
    ctx->r10 = ADD32(ctx->r1, 0X68C0);
    // 0x80066358: jr          $t2
    // 0x8006635C: nop

    switch (jr_addend_80066358 >> 2) {
        case 0: goto L_80066388; break;
        case 1: goto L_8006639C; break;
        case 2: goto L_8006639C; break;
        case 3: goto L_8006639C; break;
        case 4: goto L_8006639C; break;
        case 5: goto L_80066360; break;
        case 6: goto L_8006639C; break;
        case 7: goto L_8006639C; break;
        case 8: goto L_8006639C; break;
        case 9: goto L_8006639C; break;
        case 10: goto L_80066394; break;
        case 11: goto L_8006639C; break;
        case 12: goto L_8006639C; break;
        case 13: goto L_8006639C; break;
        case 14: goto L_8006639C; break;
        case 15: goto L_80066388; break;
        case 16: goto L_8006639C; break;
        case 17: goto L_8006639C; break;
        case 18: goto L_8006639C; break;
        case 19: goto L_8006639C; break;
        case 20: goto L_8006639C; break;
        case 21: goto L_8006639C; break;
        case 22: goto L_8006639C; break;
        case 23: goto L_8006639C; break;
        case 24: goto L_8006639C; break;
        case 25: goto L_80066388; break;
        default: switch_error(__func__, 0x80066358, 0x800D68C0);
    }
    // 0x8006635C: nop

L_80066360:
    // 0x80066360: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80066364: lw          $t3, -0x7DCC($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X7DCC);
    // 0x80066368: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x8006636C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80066370: bne         $t3, $at, L_80066388
    if (ctx->r11 != ctx->r1) {
        // 0x80066374: addiu       $a0, $a0, 0x2544
        ctx->r4 = ADD32(ctx->r4, 0X2544);
            goto L_80066388;
    }
    // 0x80066374: addiu       $a0, $a0, 0x2544
    ctx->r4 = ADD32(ctx->r4, 0X2544);
    // 0x80066378: addiu       $a1, $zero, 0xAA
    ctx->r5 = ADD32(0, 0XAA);
    // 0x8006637C: jal         0x800BA808
    // 0x80066380: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    Radio_PlayMessage(rdram, ctx);
        goto after_0;
    // 0x80066380: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x80066384: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
L_80066388:
    // 0x80066388: addiu       $t4, $zero, 0xE
    ctx->r12 = ADD32(0, 0XE);
    // 0x8006638C: b           L_8006639C
    // 0x80066390: sb          $t4, 0x44($a2)
    MEM_B(0X44, ctx->r6) = ctx->r12;
        goto L_8006639C;
    // 0x80066390: sb          $t4, 0x44($a2)
    MEM_B(0X44, ctx->r6) = ctx->r12;
L_80066394:
    // 0x80066394: addiu       $t5, $zero, 0x9
    ctx->r13 = ADD32(0, 0X9);
    // 0x80066398: sb          $t5, 0x44($a2)
    MEM_B(0X44, ctx->r6) = ctx->r13;
L_8006639C:
    // 0x8006639C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800663A0: sh          $zero, 0x1A62($at)
    MEM_H(0X1A62, ctx->r1) = 0;
L_800663A4:
    // 0x800663A4: lhu         $t6, 0x2($a2)
    ctx->r14 = MEM_HU(ctx->r6, 0X2);
    // 0x800663A8: addiu       $at, $zero, 0xC5
    ctx->r1 = ADD32(0, 0XC5);
    // 0x800663AC: bnel        $t6, $at, L_800663DC
    if (ctx->r14 != ctx->r1) {
        // 0x800663B0: lbu         $v0, 0x44($a2)
        ctx->r2 = MEM_BU(ctx->r6, 0X44);
            goto L_800663DC;
    }
    goto skip_6;
    // 0x800663B0: lbu         $v0, 0x44($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X44);
    skip_6:
    // 0x800663B4: lh          $v0, 0xE4($a2)
    ctx->r2 = MEM_H(ctx->r6, 0XE4);
    // 0x800663B8: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x800663BC: bne         $at, $zero, L_800663D8
    if (ctx->r1 != 0) {
        // 0x800663C0: slti        $at, $v0, 0x8
        ctx->r1 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
            goto L_800663D8;
    }
    // 0x800663C0: slti        $at, $v0, 0x8
    ctx->r1 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
    // 0x800663C4: beq         $at, $zero, L_800663D8
    if (ctx->r1 == 0) {
        // 0x800663C8: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_800663D8;
    }
    // 0x800663C8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800663CC: jal         0x8002E3E0
    // 0x800663D0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    AllRange_GetStarWolfHits(rdram, ctx);
        goto after_1;
    // 0x800663D0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_1:
    // 0x800663D4: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
L_800663D8:
    // 0x800663D8: lbu         $v0, 0x44($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X44);
L_800663DC:
    // 0x800663DC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800663E0: beq         $v0, $zero, L_8006653C
    if (ctx->r2 == 0) {
        // 0x800663E4: sll         $t7, $v0, 2
        ctx->r15 = S32(ctx->r2 << 2);
            goto L_8006653C;
    }
    // 0x800663E4: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x800663E8: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800663EC: lwc1        $f4, -0x1A4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X1A4);
    // 0x800663F0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800663F4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800663F8: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    // 0x800663FC: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80066400: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x80066404: bc1f        L_8006648C
    if (!c1cs) {
        // 0x80066408: nop
    
            goto L_8006648C;
    }
    // 0x80066408: nop

    // 0x8006640C: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x80066410: addiu       $v0, $v0, 0x3FE0
    ctx->r2 = ADD32(ctx->r2, 0X3FE0);
L_80066414:
    // 0x80066414: lbu         $t8, 0x0($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X0);
    // 0x80066418: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8006641C: beq         $t8, $zero, L_80066444
    if (ctx->r24 == 0) {
        // 0x80066420: nop
    
            goto L_80066444;
    }
    // 0x80066420: nop

    // 0x80066424: lw          $t9, 0x40($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X40);
    // 0x80066428: lw          $t0, 0x40($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X40);
    // 0x8006642C: beq         $t9, $t0, L_80066444
    if (ctx->r25 == ctx->r8) {
        // 0x80066430: nop
    
            goto L_80066444;
    }
    // 0x80066430: nop

    // 0x80066434: lw          $t1, 0x8C($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X8C);
    // 0x80066438: lw          $t2, 0x8C($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X8C);
    // 0x8006643C: beql        $t1, $t2, L_80066540
    if (ctx->r9 == ctx->r10) {
        // 0x80066440: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80066540;
    }
    goto skip_7;
    // 0x80066440: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_7:
L_80066444:
    // 0x80066444: bne         $v1, $a0, L_80066414
    if (ctx->r3 != ctx->r4) {
        // 0x80066448: addiu       $v0, $v0, 0x2F4
        ctx->r2 = ADD32(ctx->r2, 0X2F4);
            goto L_80066414;
    }
    // 0x80066448: addiu       $v0, $v0, 0x2F4
    ctx->r2 = ADD32(ctx->r2, 0X2F4);
    // 0x8006644C: jal         0x800660F0
    // 0x80066450: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_enmy_800660F0(rdram, ctx);
        goto after_2;
    // 0x80066450: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_2:
    // 0x80066454: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80066458: lui         $t3, 0x800C
    ctx->r11 = S32(0X800C << 16);
    // 0x8006645C: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80066460: addiu       $t3, $t3, 0x5D3C
    ctx->r11 = ADD32(ctx->r11, 0X5D3C);
    // 0x80066464: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x80066468: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x8006646C: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x80066470: ori         $a0, $a0, 0xC
    ctx->r4 = ctx->r4 | 0XC;
    // 0x80066474: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80066478: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8006647C: jal         0x80019218
    // 0x80066480: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_3;
    // 0x80066480: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_3:
    // 0x80066484: b           L_80066540
    // 0x80066488: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80066540;
    // 0x80066488: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8006648C:
    // 0x8006648C: bne         $v0, $at, L_80066504
    if (ctx->r2 != ctx->r1) {
        // 0x80066490: lui         $v0, 0x8017
        ctx->r2 = S32(0X8017 << 16);
            goto L_80066504;
    }
    // 0x80066490: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80066494: addiu       $v0, $v0, 0x78B0
    ctx->r2 = ADD32(ctx->r2, 0X78B0);
    // 0x80066498: lw          $t4, 0xC($v0)
    ctx->r12 = MEM_W(ctx->r2, 0XC);
    // 0x8006649C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800664A0: addiu       $a0, $a0, 0x3CA8
    ctx->r4 = ADD32(ctx->r4, 0X3CA8);
    // 0x800664A4: blezl       $t4, L_800664C0
    if (SIGNED(ctx->r12) <= 0) {
        // 0x800664A8: lw          $t5, 0x8($v0)
        ctx->r13 = MEM_W(ctx->r2, 0X8);
            goto L_800664C0;
    }
    goto skip_8;
    // 0x800664A8: lw          $t5, 0x8($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X8);
    skip_8:
    // 0x800664AC: jal         0x800BA808
    // 0x800664B0: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    Radio_PlayMessage(rdram, ctx);
        goto after_4;
    // 0x800664B0: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_4:
    // 0x800664B4: b           L_80066540
    // 0x800664B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80066540;
    // 0x800664B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800664BC: lw          $t5, 0x8($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X8);
L_800664C0:
    // 0x800664C0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800664C4: addiu       $a0, $a0, 0x3D3C
    ctx->r4 = ADD32(ctx->r4, 0X3D3C);
    // 0x800664C8: blezl       $t5, L_800664E4
    if (SIGNED(ctx->r13) <= 0) {
        // 0x800664CC: lw          $t6, 0x4($v0)
        ctx->r14 = MEM_W(ctx->r2, 0X4);
            goto L_800664E4;
    }
    goto skip_9;
    // 0x800664CC: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    skip_9:
    // 0x800664D0: jal         0x800BA808
    // 0x800664D4: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    Radio_PlayMessage(rdram, ctx);
        goto after_5;
    // 0x800664D4: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_5:
    // 0x800664D8: b           L_80066540
    // 0x800664DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80066540;
    // 0x800664DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800664E0: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
L_800664E4:
    // 0x800664E4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800664E8: addiu       $a0, $a0, 0x3CF0
    ctx->r4 = ADD32(ctx->r4, 0X3CF0);
    // 0x800664EC: blezl       $t6, L_80066540
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800664F0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80066540;
    }
    goto skip_10;
    // 0x800664F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_10:
    // 0x800664F4: jal         0x800BA808
    // 0x800664F8: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    Radio_PlayMessage(rdram, ctx);
        goto after_6;
    // 0x800664F8: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_6:
    // 0x800664FC: b           L_80066540
    // 0x80066500: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80066540;
    // 0x80066500: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80066504:
    // 0x80066504: jal         0x80004EB0
    // 0x80066508: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    Rand_ZeroOne(rdram, ctx);
        goto after_7;
    // 0x80066508: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_7:
    // 0x8006650C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80066510: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80066514: lbu         $t7, 0x44($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X44);
    // 0x80066518: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8006651C: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80066520: lwc1        $f8, -0x1A4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X1A4);
    // 0x80066524: c.le.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl <= ctx->f8.fl;
    // 0x80066528: nop

    // 0x8006652C: bc1fl       L_80066540
    if (!c1cs) {
        // 0x80066530: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80066540;
    }
    goto skip_11;
    // 0x80066530: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_11:
    // 0x80066534: jal         0x800660F0
    // 0x80066538: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_enmy_800660F0(rdram, ctx);
        goto after_8;
    // 0x80066538: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_8:
L_8006653C:
    // 0x8006653C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80066540:
    // 0x80066540: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80066544: jr          $ra
    // 0x80066548: nop

    return;
    // 0x80066548: nop

;}
RECOMP_FUNC void Lib_vsPrintf(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002E80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80002E84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80002E88: jal         0x8001FA04
    // 0x80002E8C: nop

    vsprintf_recomp(rdram, ctx);
        goto after_0;
    // 0x80002E8C: nop

    after_0:
    // 0x80002E90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80002E94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80002E98: jr          $ra
    // 0x80002E9C: nop

    return;
    // 0x80002E9C: nop

;}
RECOMP_FUNC void Effect_WaterSpray_Spawn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007ACE0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8007ACE4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8007ACE8: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8007ACEC: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8007ACF0: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8007ACF4: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8007ACF8: addiu       $v0, $v0, 0x37E0
    ctx->r2 = ADD32(ctx->r2, 0X37E0);
    // 0x8007ACFC: addiu       $a0, $a0, 0x130
    ctx->r4 = ADD32(ctx->r4, 0X130);
    // 0x8007AD00: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
L_8007AD04:
    // 0x8007AD04: bnel        $t6, $zero, L_8007AD40
    if (ctx->r14 != 0) {
        // 0x8007AD08: addiu       $a0, $a0, 0x8C
        ctx->r4 = ADD32(ctx->r4, 0X8C);
            goto L_8007AD40;
    }
    goto skip_0;
    // 0x8007AD08: addiu       $a0, $a0, 0x8C
    ctx->r4 = ADD32(ctx->r4, 0X8C);
    skip_0:
    // 0x8007AD0C: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8007AD10: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8007AD14: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8007AD18: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8007AD1C: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x8007AD20: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x8007AD24: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8007AD28: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x8007AD2C: jal         0x8007AC0C
    // 0x8007AD30: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    Effect_WaterSpray_Setup(rdram, ctx);
        goto after_0;
    // 0x8007AD30: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x8007AD34: b           L_8007AD4C
    // 0x8007AD38: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8007AD4C;
    // 0x8007AD38: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8007AD3C: addiu       $a0, $a0, 0x8C
    ctx->r4 = ADD32(ctx->r4, 0X8C);
L_8007AD40:
    // 0x8007AD40: bnel        $a0, $v0, L_8007AD04
    if (ctx->r4 != ctx->r2) {
        // 0x8007AD44: lbu         $t6, 0x0($a0)
        ctx->r14 = MEM_BU(ctx->r4, 0X0);
            goto L_8007AD04;
    }
    goto skip_1;
    // 0x8007AD44: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    skip_1:
    // 0x8007AD48: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8007AD4C:
    // 0x8007AD4C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8007AD50: jr          $ra
    // 0x8007AD54: nop

    return;
    // 0x8007AD54: nop

;}
RECOMP_FUNC void AudioSeq_SequenceChannelEnable(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80014440: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80014444: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x80014448: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8001444C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80014450: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80014454: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80014458: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8001445C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80014460: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80014464: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x80014468: lw          $s2, 0x34($t8)
    ctx->r18 = MEM_W(ctx->r24, 0X34);
    // 0x8001446C: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x80014470: addiu       $t9, $t9, 0x2FE8
    ctx->r25 = ADD32(ctx->r25, 0X2FE8);
    // 0x80014474: beq         $s2, $t9, L_800144C8
    if (ctx->r18 == ctx->r25) {
        // 0x80014478: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_800144C8;
    }
    // 0x80014478: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8001447C: lbu         $t2, 0x0($s2)
    ctx->r10 = MEM_BU(ctx->r18, 0X0);
    // 0x80014480: sb          $zero, 0x70($s2)
    MEM_B(0X70, ctx->r18) = 0;
    // 0x80014484: sw          $a2, 0x58($s2)
    MEM_W(0X58, ctx->r18) = ctx->r6;
    // 0x80014488: ori         $t4, $t2, 0x80
    ctx->r12 = ctx->r10 | 0X80;
    // 0x8001448C: sb          $t4, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r12;
    // 0x80014490: andi        $t5, $t4, 0xBF
    ctx->r13 = ctx->r12 & 0XBF;
    // 0x80014494: sb          $t5, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r13;
    // 0x80014498: sh          $zero, 0x1A($s2)
    MEM_H(0X1A, ctx->r18) = 0;
    // 0x8001449C: or          $s1, $s2, $zero
    ctx->r17 = ctx->r18 | 0;
    // 0x800144A0: addiu       $s3, $zero, 0x4
    ctx->r19 = ADD32(0, 0X4);
L_800144A4:
    // 0x800144A4: lw          $t6, 0x48($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X48);
    // 0x800144A8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800144AC: beql        $t6, $zero, L_800144C0
    if (ctx->r14 == 0) {
        // 0x800144B0: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800144C0;
    }
    goto skip_0;
    // 0x800144B0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x800144B4: jal         0x8001410C
    // 0x800144B8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    AudioSeq_SeqLayerFree(rdram, ctx);
        goto after_0;
    // 0x800144B8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x800144BC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800144C0:
    // 0x800144C0: bne         $s0, $s3, L_800144A4
    if (ctx->r16 != ctx->r19) {
        // 0x800144C4: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_800144A4;
    }
    // 0x800144C4: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_800144C8:
    // 0x800144C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800144CC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800144D0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800144D4: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800144D8: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800144DC: jr          $ra
    // 0x800144E0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800144E0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void PlayerShot_Effect344_Spawn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800365E4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800365E8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800365EC: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800365F0: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x800365F4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800365F8: lw          $t6, -0x7B54($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7B54);
    // 0x800365FC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80036600: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x80036604: beql        $t6, $at, L_800366C0
    if (ctx->r14 == ctx->r1) {
        // 0x80036608: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_800366C0;
    }
    goto skip_0;
    // 0x80036608: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x8003660C: lbu         $t7, 0x7C98($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X7C98);
    // 0x80036610: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x80036614: bnel        $t7, $zero, L_800366C0
    if (ctx->r15 != 0) {
        // 0x80036618: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_800366C0;
    }
    goto skip_1;
    // 0x80036618: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_1:
    // 0x8003661C: lw          $t8, 0x1A88($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1A88);
    // 0x80036620: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80036624: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80036628: beql        $t8, $at, L_800366C0
    if (ctx->r24 == ctx->r1) {
        // 0x8003662C: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_800366C0;
    }
    goto skip_2;
    // 0x8003662C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_2:
    // 0x80036630: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
    // 0x80036634: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80036638: beq         $v0, $at, L_800366BC
    if (ctx->r2 == ctx->r1) {
        // 0x8003663C: addiu       $at, $zero, 0x11
        ctx->r1 = ADD32(0, 0X11);
            goto L_800366BC;
    }
    // 0x8003663C: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x80036640: beq         $v0, $at, L_800366BC
    if (ctx->r2 == ctx->r1) {
        // 0x80036644: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_800366BC;
    }
    // 0x80036644: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80036648: beq         $v0, $at, L_800366BC
    if (ctx->r2 == ctx->r1) {
        // 0x8003664C: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_800366BC;
    }
    // 0x8003664C: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80036650: beq         $v0, $at, L_800366BC
    if (ctx->r2 == ctx->r1) {
        // 0x80036654: lui         $a0, 0x8017
        ctx->r4 = S32(0X8017 << 16);
            goto L_800366BC;
    }
    // 0x80036654: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80036658: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8003665C: addiu       $v0, $v0, 0x1C88
    ctx->r2 = ADD32(ctx->r2, 0X1C88);
    // 0x80036660: addiu       $a0, $a0, 0x130
    ctx->r4 = ADD32(ctx->r4, 0X130);
    // 0x80036664: lbu         $t9, 0x0($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X0);
L_80036668:
    // 0x80036668: bnel        $t9, $zero, L_800366B4
    if (ctx->r25 != 0) {
        // 0x8003666C: addiu       $a0, $a0, 0x8C
        ctx->r4 = ADD32(ctx->r4, 0X8C);
            goto L_800366B4;
    }
    goto skip_3;
    // 0x8003666C: addiu       $a0, $a0, 0x8C
    ctx->r4 = ADD32(ctx->r4, 0X8C);
    skip_3:
    // 0x80036670: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80036674: lwc1        $f6, 0x4C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80036678: lwc1        $f8, 0x50($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8003667C: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x80036680: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x80036684: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x80036688: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x8003668C: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x80036690: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80036694: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x80036698: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x8003669C: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x800366A0: jal         0x80036528
    // 0x800366A4: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    PlayerShot_Effect344_Setup(rdram, ctx);
        goto after_0;
    // 0x800366A4: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    after_0:
    // 0x800366A8: b           L_800366C0
    // 0x800366AC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_800366C0;
    // 0x800366AC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800366B0: addiu       $a0, $a0, 0x8C
    ctx->r4 = ADD32(ctx->r4, 0X8C);
L_800366B4:
    // 0x800366B4: bnel        $a0, $v0, L_80036668
    if (ctx->r4 != ctx->r2) {
        // 0x800366B8: lbu         $t9, 0x0($a0)
        ctx->r25 = MEM_BU(ctx->r4, 0X0);
            goto L_80036668;
    }
    goto skip_4;
    // 0x800366B8: lbu         $t9, 0x0($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X0);
    skip_4:
L_800366BC:
    // 0x800366BC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800366C0:
    // 0x800366C0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800366C4: jr          $ra
    // 0x800366C8: nop

    return;
    // 0x800366C8: nop

;}
RECOMP_FUNC void Save_Write(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3084: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C3088: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x800C308C: addiu       $a3, $a3, -0x7790
    ctx->r7 = ADD32(ctx->r7, -0X7790);
    // 0x800C3090: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C3094: jal         0x800C2FB0
    // 0x800C3098: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    Save_Checksum(rdram, ctx);
        goto after_0;
    // 0x800C3098: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_0:
    // 0x800C309C: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x800C30A0: addiu       $a3, $a3, -0x7790
    ctx->r7 = ADD32(ctx->r7, -0X7790);
    // 0x800C30A4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800C30A8: sh          $v0, 0xFE($a3)
    MEM_H(0XFE, ctx->r7) = ctx->r2;
    // 0x800C30AC: addiu       $t6, $t6, -0x7690
    ctx->r14 = ADD32(ctx->r14, -0X7690);
    // 0x800C30B0: or          $t9, $a3, $zero
    ctx->r25 = ctx->r7 | 0;
    // 0x800C30B4: addiu       $t8, $a3, 0xFC
    ctx->r24 = ADD32(ctx->r7, 0XFC);
L_800C30B8:
    // 0x800C30B8: lwl         $at, 0x0($t9)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r25, 0X0);
    // 0x800C30BC: lwr         $at, 0x3($t9)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r25, 0X3);
    // 0x800C30C0: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x800C30C4: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x800C30C8: swl         $at, -0xC($t6)
    do_swl(rdram, -0XC, ctx->r14, ctx->r1);
    // 0x800C30CC: swr         $at, -0x9($t6)
    do_swr(rdram, -0X9, ctx->r14, ctx->r1);
    // 0x800C30D0: lwl         $at, -0x8($t9)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r25, -0X8);
    // 0x800C30D4: lwr         $at, -0x5($t9)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r25, -0X5);
    // 0x800C30D8: swl         $at, -0x8($t6)
    do_swl(rdram, -0X8, ctx->r14, ctx->r1);
    // 0x800C30DC: swr         $at, -0x5($t6)
    do_swr(rdram, -0X5, ctx->r14, ctx->r1);
    // 0x800C30E0: lwl         $at, -0x4($t9)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r25, -0X4);
    // 0x800C30E4: lwr         $at, -0x1($t9)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r25, -0X1);
    // 0x800C30E8: swl         $at, -0x4($t6)
    do_swl(rdram, -0X4, ctx->r14, ctx->r1);
    // 0x800C30EC: bne         $t9, $t8, L_800C30B8
    if (ctx->r25 != ctx->r24) {
        // 0x800C30F0: swr         $at, -0x1($t6)
        do_swr(rdram, -0X1, ctx->r14, ctx->r1);
            goto L_800C30B8;
    }
    // 0x800C30F0: swr         $at, -0x1($t6)
    do_swr(rdram, -0X1, ctx->r14, ctx->r1);
    // 0x800C30F4: lwl         $at, 0x0($t9)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r25, 0X0);
    // 0x800C30F8: lwr         $at, 0x3($t9)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r25, 0X3);
    // 0x800C30FC: lui         $t0, 0x8014
    ctx->r8 = S32(0X8014 << 16);
    // 0x800C3100: addiu       $t0, $t0, 0x4F60
    ctx->r8 = ADD32(ctx->r8, 0X4F60);
    // 0x800C3104: swl         $at, 0x0($t6)
    do_swl(rdram, 0X0, ctx->r14, ctx->r1);
    // 0x800C3108: or          $t3, $a3, $zero
    ctx->r11 = ctx->r7 | 0;
    // 0x800C310C: addiu       $t2, $a3, 0x1F8
    ctx->r10 = ADD32(ctx->r7, 0X1F8);
    // 0x800C3110: swr         $at, 0x3($t6)
    do_swr(rdram, 0X3, ctx->r14, ctx->r1);
L_800C3114:
    // 0x800C3114: lw          $at, 0x0($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X0);
    // 0x800C3118: addiu       $t3, $t3, 0xC
    ctx->r11 = ADD32(ctx->r11, 0XC);
    // 0x800C311C: addiu       $t0, $t0, 0xC
    ctx->r8 = ADD32(ctx->r8, 0XC);
    // 0x800C3120: sw          $at, -0xC($t0)
    MEM_W(-0XC, ctx->r8) = ctx->r1;
    // 0x800C3124: lw          $at, -0x8($t3)
    ctx->r1 = MEM_W(ctx->r11, -0X8);
    // 0x800C3128: sw          $at, -0x8($t0)
    MEM_W(-0X8, ctx->r8) = ctx->r1;
    // 0x800C312C: lw          $at, -0x4($t3)
    ctx->r1 = MEM_W(ctx->r11, -0X4);
    // 0x800C3130: bne         $t3, $t2, L_800C3114
    if (ctx->r11 != ctx->r10) {
        // 0x800C3134: sw          $at, -0x4($t0)
        MEM_W(-0X4, ctx->r8) = ctx->r1;
            goto L_800C3114;
    }
    // 0x800C3134: sw          $at, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->r1;
    // 0x800C3138: lw          $at, 0x0($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X0);
    // 0x800C313C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800C3140: addiu       $a0, $a0, 0x22C0
    ctx->r4 = ADD32(ctx->r4, 0X22C0);
    // 0x800C3144: sw          $at, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r1;
    // 0x800C3148: lw          $t2, 0x4($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X4);
    // 0x800C314C: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x800C3150: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800C3154: jal         0x80020720
    // 0x800C3158: sw          $t2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r10;
    osSendMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x800C3158: sw          $t2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r10;
    after_1:
    // 0x800C315C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800C3160: addiu       $a0, $a0, 0x2318
    ctx->r4 = ADD32(ctx->r4, 0X2318);
    // 0x800C3164: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x800C3168: jal         0x800205E0
    // 0x800C316C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x800C316C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x800C3170: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x800C3174: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x800C3178: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C317C: beq         $t4, $at, L_800C318C
    if (ctx->r12 == ctx->r1) {
        // 0x800C3180: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800C318C;
    }
    // 0x800C3180: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C3184: b           L_800C318C
    // 0x800C3188: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800C318C;
    // 0x800C3188: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800C318C:
    // 0x800C318C: jr          $ra
    // 0x800C3190: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800C3190: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void bcopy_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80027220: beq         $a2, $zero, L_8002728C
    if (ctx->r6 == 0) {
        // 0x80027224: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_8002728C;
    }
    // 0x80027224: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80027228: beq         $a0, $a1, L_8002728C
    if (ctx->r4 == ctx->r5) {
        // 0x8002722C: slt         $at, $a1, $a0
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_8002728C;
    }
    // 0x8002722C: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80027230: bnel        $at, $zero, L_80027254
    if (ctx->r1 != 0) {
        // 0x80027234: slti        $at, $a2, 0x10
        ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
            goto L_80027254;
    }
    goto skip_0;
    // 0x80027234: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    skip_0:
    // 0x80027238: add         $v0, $a0, $a2
    ctx->r2 = ADD32(ctx->r4, ctx->r6);
    // 0x8002723C: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80027240: beql        $at, $zero, L_80027254
    if (ctx->r1 == 0) {
        // 0x80027244: slti        $at, $a2, 0x10
        ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
            goto L_80027254;
    }
    goto skip_1;
    // 0x80027244: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    skip_1:
    // 0x80027248: b           L_800273B8
    // 0x8002724C: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
        goto L_800273B8;
    // 0x8002724C: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    // 0x80027250: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
L_80027254:
    // 0x80027254: bne         $at, $zero, L_8002726C
    if (ctx->r1 != 0) {
        // 0x80027258: nop
    
            goto L_8002726C;
    }
    // 0x80027258: nop

    // 0x8002725C: andi        $v0, $a0, 0x3
    ctx->r2 = ctx->r4 & 0X3;
    // 0x80027260: andi        $v1, $a1, 0x3
    ctx->r3 = ctx->r5 & 0X3;
    // 0x80027264: beq         $v0, $v1, L_80027294
    if (ctx->r2 == ctx->r3) {
        // 0x80027268: nop
    
            goto L_80027294;
    }
    // 0x80027268: nop

L_8002726C:
    // 0x8002726C: beq         $a2, $zero, L_8002728C
    if (ctx->r6 == 0) {
        // 0x80027270: nop
    
            goto L_8002728C;
    }
    // 0x80027270: nop

    // 0x80027274: addu        $v1, $a0, $a2
    ctx->r3 = ADD32(ctx->r4, ctx->r6);
L_80027278:
    // 0x80027278: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x8002727C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80027280: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80027284: bne         $a0, $v1, L_80027278
    if (ctx->r4 != ctx->r3) {
        // 0x80027288: sb          $v0, -0x1($a1)
        MEM_B(-0X1, ctx->r5) = ctx->r2;
            goto L_80027278;
    }
    // 0x80027288: sb          $v0, -0x1($a1)
    MEM_B(-0X1, ctx->r5) = ctx->r2;
L_8002728C:
    // 0x8002728C: jr          $ra
    // 0x80027290: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    return;
    // 0x80027290: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_80027294:
    // 0x80027294: beq         $v0, $zero, L_800272F8
    if (ctx->r2 == 0) {
        // 0x80027298: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_800272F8;
    }
    // 0x80027298: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8002729C: beq         $v0, $at, L_800272DC
    if (ctx->r2 == ctx->r1) {
        // 0x800272A0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800272DC;
    }
    // 0x800272A0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800272A4: beql        $v0, $at, L_800272C8
    if (ctx->r2 == ctx->r1) {
        // 0x800272A8: lh          $v0, 0x0($a0)
        ctx->r2 = MEM_H(ctx->r4, 0X0);
            goto L_800272C8;
    }
    goto skip_2;
    // 0x800272A8: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
    skip_2:
    // 0x800272AC: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x800272B0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800272B4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800272B8: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x800272BC: b           L_800272F8
    // 0x800272C0: sb          $v0, -0x1($a1)
    MEM_B(-0X1, ctx->r5) = ctx->r2;
        goto L_800272F8;
    // 0x800272C0: sb          $v0, -0x1($a1)
    MEM_B(-0X1, ctx->r5) = ctx->r2;
    // 0x800272C4: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
L_800272C8:
    // 0x800272C8: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x800272CC: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x800272D0: addiu       $a2, $a2, -0x2
    ctx->r6 = ADD32(ctx->r6, -0X2);
    // 0x800272D4: b           L_800272F8
    // 0x800272D8: sh          $v0, -0x2($a1)
    MEM_H(-0X2, ctx->r5) = ctx->r2;
        goto L_800272F8;
    // 0x800272D8: sh          $v0, -0x2($a1)
    MEM_H(-0X2, ctx->r5) = ctx->r2;
L_800272DC:
    // 0x800272DC: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x800272E0: lh          $v1, 0x1($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X1);
    // 0x800272E4: addiu       $a0, $a0, 0x3
    ctx->r4 = ADD32(ctx->r4, 0X3);
    // 0x800272E8: addiu       $a1, $a1, 0x3
    ctx->r5 = ADD32(ctx->r5, 0X3);
    // 0x800272EC: addiu       $a2, $a2, -0x3
    ctx->r6 = ADD32(ctx->r6, -0X3);
    // 0x800272F0: sb          $v0, -0x3($a1)
    MEM_B(-0X3, ctx->r5) = ctx->r2;
    // 0x800272F4: sh          $v1, -0x2($a1)
    MEM_H(-0X2, ctx->r5) = ctx->r3;
L_800272F8:
    // 0x800272F8: slti        $at, $a2, 0x20
    ctx->r1 = SIGNED(ctx->r6) < 0X20 ? 1 : 0;
    // 0x800272FC: bnel        $at, $zero, L_80027358
    if (ctx->r1 != 0) {
        // 0x80027300: slti        $at, $a2, 0x10
        ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
            goto L_80027358;
    }
    goto skip_3;
    // 0x80027300: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    skip_3:
    // 0x80027304: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80027308: lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4);
    // 0x8002730C: lw          $t0, 0x8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X8);
    // 0x80027310: lw          $t1, 0xC($a0)
    ctx->r9 = MEM_W(ctx->r4, 0XC);
    // 0x80027314: lw          $t2, 0x10($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X10);
    // 0x80027318: lw          $t3, 0x14($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14);
    // 0x8002731C: lw          $t4, 0x18($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X18);
    // 0x80027320: lw          $t5, 0x1C($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X1C);
    // 0x80027324: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    // 0x80027328: addiu       $a1, $a1, 0x20
    ctx->r5 = ADD32(ctx->r5, 0X20);
    // 0x8002732C: addiu       $a2, $a2, -0x20
    ctx->r6 = ADD32(ctx->r6, -0X20);
    // 0x80027330: sw          $v0, -0x20($a1)
    MEM_W(-0X20, ctx->r5) = ctx->r2;
    // 0x80027334: sw          $v1, -0x1C($a1)
    MEM_W(-0X1C, ctx->r5) = ctx->r3;
    // 0x80027338: sw          $t0, -0x18($a1)
    MEM_W(-0X18, ctx->r5) = ctx->r8;
    // 0x8002733C: sw          $t1, -0x14($a1)
    MEM_W(-0X14, ctx->r5) = ctx->r9;
    // 0x80027340: sw          $t2, -0x10($a1)
    MEM_W(-0X10, ctx->r5) = ctx->r10;
    // 0x80027344: sw          $t3, -0xC($a1)
    MEM_W(-0XC, ctx->r5) = ctx->r11;
    // 0x80027348: sw          $t4, -0x8($a1)
    MEM_W(-0X8, ctx->r5) = ctx->r12;
    // 0x8002734C: b           L_800272F8
    // 0x80027350: sw          $t5, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r13;
        goto L_800272F8;
    // 0x80027350: sw          $t5, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r13;
L_80027354:
    // 0x80027354: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
L_80027358:
    // 0x80027358: bnel        $at, $zero, L_80027394
    if (ctx->r1 != 0) {
        // 0x8002735C: slti        $at, $a2, 0x4
        ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
            goto L_80027394;
    }
    goto skip_4;
    // 0x8002735C: slti        $at, $a2, 0x4
    ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
    skip_4:
    // 0x80027360: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80027364: lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4);
    // 0x80027368: lw          $t0, 0x8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X8);
    // 0x8002736C: lw          $t1, 0xC($a0)
    ctx->r9 = MEM_W(ctx->r4, 0XC);
    // 0x80027370: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x80027374: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x80027378: addiu       $a2, $a2, -0x10
    ctx->r6 = ADD32(ctx->r6, -0X10);
    // 0x8002737C: sw          $v0, -0x10($a1)
    MEM_W(-0X10, ctx->r5) = ctx->r2;
    // 0x80027380: sw          $v1, -0xC($a1)
    MEM_W(-0XC, ctx->r5) = ctx->r3;
    // 0x80027384: sw          $t0, -0x8($a1)
    MEM_W(-0X8, ctx->r5) = ctx->r8;
    // 0x80027388: b           L_80027354
    // 0x8002738C: sw          $t1, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r9;
        goto L_80027354;
    // 0x8002738C: sw          $t1, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r9;
L_80027390:
    // 0x80027390: slti        $at, $a2, 0x4
    ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
L_80027394:
    // 0x80027394: bne         $at, $zero, L_8002726C
    if (ctx->r1 != 0) {
        // 0x80027398: nop
    
            goto L_8002726C;
    }
    // 0x80027398: nop

    // 0x8002739C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800273A0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800273A4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800273A8: addiu       $a2, $a2, -0x4
    ctx->r6 = ADD32(ctx->r6, -0X4);
    // 0x800273AC: b           L_80027390
    // 0x800273B0: sw          $v0, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r2;
        goto L_80027390;
    // 0x800273B0: sw          $v0, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r2;
    // 0x800273B4: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
L_800273B8:
    // 0x800273B8: add         $a0, $a0, $a2
    ctx->r4 = ADD32(ctx->r4, ctx->r6);
    // 0x800273BC: bne         $at, $zero, L_800273D4
    if (ctx->r1 != 0) {
        // 0x800273C0: add         $a1, $a1, $a2
        ctx->r5 = ADD32(ctx->r5, ctx->r6);
            goto L_800273D4;
    }
    // 0x800273C0: add         $a1, $a1, $a2
    ctx->r5 = ADD32(ctx->r5, ctx->r6);
    // 0x800273C4: andi        $v0, $a0, 0x3
    ctx->r2 = ctx->r4 & 0X3;
    // 0x800273C8: andi        $v1, $a1, 0x3
    ctx->r3 = ctx->r5 & 0X3;
    // 0x800273CC: beq         $v0, $v1, L_80027404
    if (ctx->r2 == ctx->r3) {
        // 0x800273D0: nop
    
            goto L_80027404;
    }
    // 0x800273D0: nop

L_800273D4:
    // 0x800273D4: beq         $a2, $zero, L_8002728C
    if (ctx->r6 == 0) {
        // 0x800273D8: nop
    
            goto L_8002728C;
    }
    // 0x800273D8: nop

    // 0x800273DC: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x800273E0: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x800273E4: subu        $v1, $a0, $a2
    ctx->r3 = SUB32(ctx->r4, ctx->r6);
L_800273E8:
    // 0x800273E8: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x800273EC: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x800273F0: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x800273F4: bne         $a0, $v1, L_800273E8
    if (ctx->r4 != ctx->r3) {
        // 0x800273F8: sb          $v0, 0x1($a1)
        MEM_B(0X1, ctx->r5) = ctx->r2;
            goto L_800273E8;
    }
    // 0x800273F8: sb          $v0, 0x1($a1)
    MEM_B(0X1, ctx->r5) = ctx->r2;
    // 0x800273FC: jr          $ra
    // 0x80027400: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    return;
    // 0x80027400: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_80027404:
    // 0x80027404: beq         $v0, $zero, L_80027468
    if (ctx->r2 == 0) {
        // 0x80027408: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80027468;
    }
    // 0x80027408: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8002740C: beq         $v0, $at, L_8002744C
    if (ctx->r2 == ctx->r1) {
        // 0x80027410: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8002744C;
    }
    // 0x80027410: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80027414: beql        $v0, $at, L_80027438
    if (ctx->r2 == ctx->r1) {
        // 0x80027418: lh          $v0, -0x2($a0)
        ctx->r2 = MEM_H(ctx->r4, -0X2);
            goto L_80027438;
    }
    goto skip_5;
    // 0x80027418: lh          $v0, -0x2($a0)
    ctx->r2 = MEM_H(ctx->r4, -0X2);
    skip_5:
    // 0x8002741C: lb          $v0, -0x1($a0)
    ctx->r2 = MEM_B(ctx->r4, -0X1);
    // 0x80027420: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80027424: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80027428: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x8002742C: b           L_80027468
    // 0x80027430: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
        goto L_80027468;
    // 0x80027430: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
    // 0x80027434: lh          $v0, -0x2($a0)
    ctx->r2 = MEM_H(ctx->r4, -0X2);
L_80027438:
    // 0x80027438: addiu       $a0, $a0, -0x2
    ctx->r4 = ADD32(ctx->r4, -0X2);
    // 0x8002743C: addiu       $a1, $a1, -0x2
    ctx->r5 = ADD32(ctx->r5, -0X2);
    // 0x80027440: addiu       $a2, $a2, -0x2
    ctx->r6 = ADD32(ctx->r6, -0X2);
    // 0x80027444: b           L_80027468
    // 0x80027448: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
        goto L_80027468;
    // 0x80027448: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
L_8002744C:
    // 0x8002744C: lb          $v0, -0x1($a0)
    ctx->r2 = MEM_B(ctx->r4, -0X1);
    // 0x80027450: lh          $v1, -0x3($a0)
    ctx->r3 = MEM_H(ctx->r4, -0X3);
    // 0x80027454: addiu       $a0, $a0, -0x3
    ctx->r4 = ADD32(ctx->r4, -0X3);
    // 0x80027458: addiu       $a1, $a1, -0x3
    ctx->r5 = ADD32(ctx->r5, -0X3);
    // 0x8002745C: addiu       $a2, $a2, -0x3
    ctx->r6 = ADD32(ctx->r6, -0X3);
    // 0x80027460: sb          $v0, 0x2($a1)
    MEM_B(0X2, ctx->r5) = ctx->r2;
    // 0x80027464: sh          $v1, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r3;
L_80027468:
    // 0x80027468: slti        $at, $a2, 0x20
    ctx->r1 = SIGNED(ctx->r6) < 0X20 ? 1 : 0;
    // 0x8002746C: bnel        $at, $zero, L_800274C8
    if (ctx->r1 != 0) {
        // 0x80027470: slti        $at, $a2, 0x10
        ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
            goto L_800274C8;
    }
    goto skip_6;
    // 0x80027470: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    skip_6:
    // 0x80027474: lw          $v0, -0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, -0X4);
    // 0x80027478: lw          $v1, -0x8($a0)
    ctx->r3 = MEM_W(ctx->r4, -0X8);
    // 0x8002747C: lw          $t0, -0xC($a0)
    ctx->r8 = MEM_W(ctx->r4, -0XC);
    // 0x80027480: lw          $t1, -0x10($a0)
    ctx->r9 = MEM_W(ctx->r4, -0X10);
    // 0x80027484: lw          $t2, -0x14($a0)
    ctx->r10 = MEM_W(ctx->r4, -0X14);
    // 0x80027488: lw          $t3, -0x18($a0)
    ctx->r11 = MEM_W(ctx->r4, -0X18);
    // 0x8002748C: lw          $t4, -0x1C($a0)
    ctx->r12 = MEM_W(ctx->r4, -0X1C);
    // 0x80027490: lw          $t5, -0x20($a0)
    ctx->r13 = MEM_W(ctx->r4, -0X20);
    // 0x80027494: addiu       $a0, $a0, -0x20
    ctx->r4 = ADD32(ctx->r4, -0X20);
    // 0x80027498: addiu       $a1, $a1, -0x20
    ctx->r5 = ADD32(ctx->r5, -0X20);
    // 0x8002749C: addiu       $a2, $a2, -0x20
    ctx->r6 = ADD32(ctx->r6, -0X20);
    // 0x800274A0: sw          $v0, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->r2;
    // 0x800274A4: sw          $v1, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->r3;
    // 0x800274A8: sw          $t0, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r8;
    // 0x800274AC: sw          $t1, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r9;
    // 0x800274B0: sw          $t2, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r10;
    // 0x800274B4: sw          $t3, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r11;
    // 0x800274B8: sw          $t4, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r12;
    // 0x800274BC: b           L_80027468
    // 0x800274C0: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
        goto L_80027468;
    // 0x800274C0: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
L_800274C4:
    // 0x800274C4: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
L_800274C8:
    // 0x800274C8: bnel        $at, $zero, L_80027504
    if (ctx->r1 != 0) {
        // 0x800274CC: slti        $at, $a2, 0x4
        ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
            goto L_80027504;
    }
    goto skip_7;
    // 0x800274CC: slti        $at, $a2, 0x4
    ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
    skip_7:
    // 0x800274D0: lw          $v0, -0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, -0X4);
    // 0x800274D4: lw          $v1, -0x8($a0)
    ctx->r3 = MEM_W(ctx->r4, -0X8);
    // 0x800274D8: lw          $t0, -0xC($a0)
    ctx->r8 = MEM_W(ctx->r4, -0XC);
    // 0x800274DC: lw          $t1, -0x10($a0)
    ctx->r9 = MEM_W(ctx->r4, -0X10);
    // 0x800274E0: addiu       $a0, $a0, -0x10
    ctx->r4 = ADD32(ctx->r4, -0X10);
    // 0x800274E4: addiu       $a1, $a1, -0x10
    ctx->r5 = ADD32(ctx->r5, -0X10);
    // 0x800274E8: addiu       $a2, $a2, -0x10
    ctx->r6 = ADD32(ctx->r6, -0X10);
    // 0x800274EC: sw          $v0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r2;
    // 0x800274F0: sw          $v1, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r3;
    // 0x800274F4: sw          $t0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r8;
    // 0x800274F8: b           L_800274C4
    // 0x800274FC: sw          $t1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r9;
        goto L_800274C4;
    // 0x800274FC: sw          $t1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r9;
L_80027500:
    // 0x80027500: slti        $at, $a2, 0x4
    ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
L_80027504:
    // 0x80027504: bne         $at, $zero, L_800273D4
    if (ctx->r1 != 0) {
        // 0x80027508: nop
    
            goto L_800273D4;
    }
    // 0x80027508: nop

    // 0x8002750C: lw          $v0, -0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, -0X4);
    // 0x80027510: addiu       $a0, $a0, -0x4
    ctx->r4 = ADD32(ctx->r4, -0X4);
    // 0x80027514: addiu       $a1, $a1, -0x4
    ctx->r5 = ADD32(ctx->r5, -0X4);
    // 0x80027518: addiu       $a2, $a2, -0x4
    ctx->r6 = ADD32(ctx->r6, -0X4);
    // 0x8002751C: b           L_80027500
    // 0x80027520: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
        goto L_80027500;
    // 0x80027520: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x80027524: nop

    // 0x80027528: nop

    // 0x8002752C: nop

;}
RECOMP_FUNC void AudioLoad_ProcessAsyncLoad(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80010C60: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80010C64: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80010C68: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80010C6C: lb          $v0, 0x1($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X1);
    // 0x80010C70: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x80010C74: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80010C78: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80010C7C: bne         $at, $zero, L_80010C90
    if (ctx->r1 != 0) {
        // 0x80010C80: lw          $v1, 0x5C64($v1)
        ctx->r3 = MEM_W(ctx->r3, 0X5C64);
            goto L_80010C90;
    }
    // 0x80010C80: lw          $v1, 0x5C64($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X5C64);
    // 0x80010C84: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80010C88: b           L_80010EE8
    // 0x80010C8C: sb          $t6, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r14;
        goto L_80010EE8;
    // 0x80010C8C: sb          $t6, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r14;
L_80010C90:
    // 0x80010C90: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80010C94: bne         $a3, $v0, L_80010CA4
    if (ctx->r7 != ctx->r2) {
        // 0x80010C98: nop
    
            goto L_80010CA4;
    }
    // 0x80010C98: nop

    // 0x80010C9C: b           L_80010CE4
    // 0x80010CA0: sb          $zero, 0x1($s0)
    MEM_B(0X1, ctx->r16) = 0;
        goto L_80010CE4;
    // 0x80010CA0: sb          $zero, 0x1($s0)
    MEM_B(0X1, ctx->r16) = 0;
L_80010CA4:
    // 0x80010CA4: beq         $a1, $zero, L_80010CC4
    if (ctx->r5 == 0) {
        // 0x80010CA8: addiu       $a0, $s0, 0x20
        ctx->r4 = ADD32(ctx->r16, 0X20);
            goto L_80010CC4;
    }
    // 0x80010CA8: addiu       $a0, $s0, 0x20
    ctx->r4 = ADD32(ctx->r16, 0X20);
    // 0x80010CAC: addiu       $a0, $s0, 0x20
    ctx->r4 = ADD32(ctx->r16, 0X20);
    // 0x80010CB0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80010CB4: jal         0x800205E0
    // 0x80010CB8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80010CB8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80010CBC: b           L_80010EE8
    // 0x80010CC0: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
        goto L_80010EE8;
    // 0x80010CC0: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
L_80010CC4:
    // 0x80010CC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80010CC8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80010CCC: jal         0x800205E0
    // 0x80010CD0: sw          $v1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r3;
    osRecvMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x80010CD0: sw          $v1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r3;
    after_1:
    // 0x80010CD4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80010CD8: lw          $v1, 0x5C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X5C);
    // 0x80010CDC: beq         $v0, $at, L_80010EE8
    if (ctx->r2 == ctx->r1) {
        // 0x80010CE0: addiu       $a3, $zero, 0x1
        ctx->r7 = ADD32(0, 0X1);
            goto L_80010EE8;
    }
    // 0x80010CE0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_80010CE4:
    // 0x80010CE4: lw          $t7, 0x10($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X10);
    // 0x80010CE8: bne         $t7, $zero, L_80010E40
    if (ctx->r15 != 0) {
        // 0x80010CEC: sw          $t7, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r15;
            goto L_80010E40;
    }
    // 0x80010CEC: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x80010CF0: lw          $a1, 0x18($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X18);
    // 0x80010CF4: lui         $t2, 0x8015
    ctx->r10 = S32(0X8015 << 16);
    // 0x80010CF8: addiu       $t2, $t2, -0x2BD8
    ctx->r10 = ADD32(ctx->r10, -0X2BD8);
    // 0x80010CFC: srl         $v1, $a1, 16
    ctx->r3 = S32(U32(ctx->r5) >> 16);
    // 0x80010D00: andi        $t9, $v1, 0xFF
    ctx->r25 = ctx->r3 & 0XFF;
    // 0x80010D04: beq         $t9, $zero, L_80010D28
    if (ctx->r25 == 0) {
        // 0x80010D08: or          $v0, $a1, $zero
        ctx->r2 = ctx->r5 | 0;
            goto L_80010D28;
    }
    // 0x80010D08: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x80010D0C: beq         $t9, $a3, L_80010D7C
    if (ctx->r25 == ctx->r7) {
        // 0x80010D10: srl         $t0, $v0, 8
        ctx->r8 = S32(U32(ctx->r2) >> 8);
            goto L_80010D7C;
    }
    // 0x80010D10: srl         $t0, $v0, 8
    ctx->r8 = S32(U32(ctx->r2) >> 8);
    // 0x80010D14: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80010D18: beq         $t9, $at, L_80010D50
    if (ctx->r25 == ctx->r1) {
        // 0x80010D1C: srl         $t5, $v0, 8
        ctx->r13 = S32(U32(ctx->r2) >> 8);
            goto L_80010D50;
    }
    // 0x80010D1C: srl         $t5, $v0, 8
    ctx->r13 = S32(U32(ctx->r2) >> 8);
    // 0x80010D20: b           L_80010E2C
    // 0x80010D24: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
        goto L_80010E2C;
    // 0x80010D24: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
L_80010D28:
    // 0x80010D28: srl         $t0, $v0, 8
    ctx->r8 = S32(U32(ctx->r2) >> 8);
    // 0x80010D2C: andi        $t1, $t0, 0xFF
    ctx->r9 = ctx->r8 & 0XFF;
    // 0x80010D30: addu        $v1, $t1, $t2
    ctx->r3 = ADD32(ctx->r9, ctx->r10);
    // 0x80010D34: lbu         $t3, 0x0($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X0);
    // 0x80010D38: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80010D3C: beql        $t3, $at, L_80010E2C
    if (ctx->r11 == ctx->r1) {
        // 0x80010D40: sb          $zero, 0x0($s0)
        MEM_B(0X0, ctx->r16) = 0;
            goto L_80010E2C;
    }
    goto skip_0;
    // 0x80010D40: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    skip_0:
    // 0x80010D44: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x80010D48: b           L_80010E28
    // 0x80010D4C: lw          $a1, 0x18($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X18);
        goto L_80010E28;
    // 0x80010D4C: lw          $a1, 0x18($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X18);
L_80010D50:
    // 0x80010D50: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x80010D54: addiu       $t7, $t7, -0x2C58
    ctx->r15 = ADD32(ctx->r15, -0X2C58);
    // 0x80010D58: andi        $t6, $t5, 0xFF
    ctx->r14 = ctx->r13 & 0XFF;
    // 0x80010D5C: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x80010D60: lbu         $t8, 0x0($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X0);
    // 0x80010D64: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80010D68: beql        $t8, $at, L_80010E2C
    if (ctx->r24 == ctx->r1) {
        // 0x80010D6C: sb          $zero, 0x0($s0)
        MEM_B(0X0, ctx->r16) = 0;
            goto L_80010E2C;
    }
    goto skip_1;
    // 0x80010D6C: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    skip_1:
    // 0x80010D70: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x80010D74: b           L_80010E28
    // 0x80010D78: lw          $a1, 0x18($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X18);
        goto L_80010E28;
    // 0x80010D78: lw          $a1, 0x18($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X18);
L_80010D7C:
    // 0x80010D7C: lui         $t2, 0x8015
    ctx->r10 = S32(0X8015 << 16);
    // 0x80010D80: addiu       $t2, $t2, -0x2C18
    ctx->r10 = ADD32(ctx->r10, -0X2C18);
    // 0x80010D84: andi        $t1, $t0, 0xFF
    ctx->r9 = ctx->r8 & 0XFF;
    // 0x80010D88: addu        $v1, $t1, $t2
    ctx->r3 = ADD32(ctx->r9, ctx->r10);
    // 0x80010D8C: lbu         $t3, 0x0($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X0);
    // 0x80010D90: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80010D94: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x80010D98: beq         $t3, $at, L_80010DA4
    if (ctx->r11 == ctx->r1) {
        // 0x80010D9C: addiu       $a1, $sp, 0x3C
        ctx->r5 = ADD32(ctx->r29, 0X3C);
            goto L_80010DA4;
    }
    // 0x80010D9C: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x80010DA0: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
L_80010DA4:
    // 0x80010DA4: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80010DA8: lui         $t5, 0x8015
    ctx->r13 = S32(0X8015 << 16);
    // 0x80010DAC: lw          $t5, 0x5C70($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X5C70);
    // 0x80010DB0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80010DB4: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80010DB8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80010DBC: addu        $v0, $t5, $t7
    ctx->r2 = ADD32(ctx->r13, ctx->r15);
    // 0x80010DC0: lbu         $a0, 0x2($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X2);
    // 0x80010DC4: lbu         $a2, 0x3($v0)
    ctx->r6 = MEM_BU(ctx->r2, 0X3);
    // 0x80010DC8: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80010DCC: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    // 0x80010DD0: beq         $a0, $at, L_80010DEC
    if (ctx->r4 == ctx->r1) {
        // 0x80010DD4: sw          $a2, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r6;
            goto L_80010DEC;
    }
    // 0x80010DD4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80010DD8: jal         0x8000F388
    // 0x80010DDC: sw          $a2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r6;
    AudioLoad_SyncLoadSampleBank(rdram, ctx);
        goto after_2;
    // 0x80010DDC: sw          $a2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r6;
    after_2:
    // 0x80010DE0: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x80010DE4: b           L_80010DF0
    // 0x80010DE8: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
        goto L_80010DF0;
    // 0x80010DE8: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
L_80010DEC:
    // 0x80010DEC: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
L_80010DF0:
    // 0x80010DF0: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80010DF4: beq         $a2, $at, L_80010E0C
    if (ctx->r6 == ctx->r1) {
        // 0x80010DF8: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_80010E0C;
    }
    // 0x80010DF8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80010DFC: jal         0x8000F388
    // 0x80010E00: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    AudioLoad_SyncLoadSampleBank(rdram, ctx);
        goto after_3;
    // 0x80010E00: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_3:
    // 0x80010E04: b           L_80010E10
    // 0x80010E08: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
        goto L_80010E10;
    // 0x80010E08: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
L_80010E0C:
    // 0x80010E0C: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
L_80010E10:
    // 0x80010E10: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80010E14: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x80010E18: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    // 0x80010E1C: jal         0x80011120
    // 0x80010E20: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    AudioLoad_RelocateFontAndPreloadSamples(rdram, ctx);
        goto after_4;
    // 0x80010E20: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_4:
    // 0x80010E24: lw          $a1, 0x18($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X18);
L_80010E28:
    // 0x80010E28: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
L_80010E2C:
    // 0x80010E2C: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    // 0x80010E30: jal         0x80020720
    // 0x80010E34: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_5;
    // 0x80010E34: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x80010E38: b           L_80010EEC
    // 0x80010E3C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80010EEC;
    // 0x80010E3C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80010E40:
    // 0x80010E40: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x80010E44: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80010E48: sltu        $at, $t8, $a2
    ctx->r1 = ctx->r24 < ctx->r6 ? 1 : 0;
    // 0x80010E4C: beql        $at, $zero, L_80010E94
    if (ctx->r1 == 0) {
        // 0x80010E50: lb          $t0, 0x2($s0)
        ctx->r8 = MEM_B(ctx->r16, 0X2);
            goto L_80010E94;
    }
    goto skip_2;
    // 0x80010E50: lb          $t0, 0x2($s0)
    ctx->r8 = MEM_B(ctx->r16, 0X2);
    skip_2:
    // 0x80010E54: lb          $t9, 0x2($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X2);
    // 0x80010E58: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x80010E5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80010E60: bne         $a3, $t9, L_80010E80
    if (ctx->r7 != ctx->r25) {
        // 0x80010E64: nop
    
            goto L_80010E80;
    }
    // 0x80010E64: nop

    // 0x80010E68: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    // 0x80010E6C: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x80010E70: jal         0x80010F8C
    // 0x80010E74: lh          $a3, 0x2($v1)
    ctx->r7 = MEM_H(ctx->r3, 0X2);
    AudioLoad_AsyncDmaUnkMedium(rdram, ctx);
        goto after_6;
    // 0x80010E74: lh          $a3, 0x2($v1)
    ctx->r7 = MEM_H(ctx->r3, 0X2);
    after_6:
    // 0x80010E78: b           L_80010E88
    // 0x80010E7C: nop

        goto L_80010E88;
    // 0x80010E7C: nop

L_80010E80:
    // 0x80010E80: jal         0x80010EFC
    // 0x80010E84: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    AudioLoad_AsyncDma(rdram, ctx);
        goto after_7;
    // 0x80010E84: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_7:
L_80010E88:
    // 0x80010E88: b           L_80010EE8
    // 0x80010E8C: sw          $zero, 0x10($s0)
    MEM_W(0X10, ctx->r16) = 0;
        goto L_80010EE8;
    // 0x80010E8C: sw          $zero, 0x10($s0)
    MEM_W(0X10, ctx->r16) = 0;
    // 0x80010E90: lb          $t0, 0x2($s0)
    ctx->r8 = MEM_B(ctx->r16, 0X2);
L_80010E94:
    // 0x80010E94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80010E98: bne         $a3, $t0, L_80010EB8
    if (ctx->r7 != ctx->r8) {
        // 0x80010E9C: nop
    
            goto L_80010EB8;
    }
    // 0x80010E9C: nop

    // 0x80010EA0: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    // 0x80010EA4: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x80010EA8: jal         0x80010F8C
    // 0x80010EAC: lh          $a3, 0x2($v1)
    ctx->r7 = MEM_H(ctx->r3, 0X2);
    AudioLoad_AsyncDmaUnkMedium(rdram, ctx);
        goto after_8;
    // 0x80010EAC: lh          $a3, 0x2($v1)
    ctx->r7 = MEM_H(ctx->r3, 0X2);
    after_8:
    // 0x80010EB0: b           L_80010EC4
    // 0x80010EB4: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
        goto L_80010EC4;
    // 0x80010EB4: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
L_80010EB8:
    // 0x80010EB8: jal         0x80010EFC
    // 0x80010EBC: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    AudioLoad_AsyncDma(rdram, ctx);
        goto after_9;
    // 0x80010EBC: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_9:
    // 0x80010EC0: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
L_80010EC4:
    // 0x80010EC4: lw          $t1, 0x10($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X10);
    // 0x80010EC8: lw          $t3, 0x8($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X8);
    // 0x80010ECC: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x80010ED0: subu        $t2, $t1, $a2
    ctx->r10 = SUB32(ctx->r9, ctx->r6);
    // 0x80010ED4: addu        $t4, $t3, $a2
    ctx->r12 = ADD32(ctx->r11, ctx->r6);
    // 0x80010ED8: addu        $t5, $t6, $a2
    ctx->r13 = ADD32(ctx->r14, ctx->r6);
    // 0x80010EDC: sw          $t2, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r10;
    // 0x80010EE0: sw          $t4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r12;
    // 0x80010EE4: sw          $t5, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r13;
L_80010EE8:
    // 0x80010EE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80010EEC:
    // 0x80010EEC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80010EF0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x80010EF4: jr          $ra
    // 0x80010EF8: nop

    return;
    // 0x80010EF8: nop

;}
RECOMP_FUNC void AudioThread_ResetAudioHeap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001ED8C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8001ED90: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8001ED94: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8001ED98: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001ED9C: lui         $s1, 0x800C
    ctx->r17 = S32(0X800C << 16);
    // 0x8001EDA0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8001EDA4: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8001EDA8: addiu       $s1, $s1, 0x7C64
    ctx->r17 = ADD32(ctx->r17, 0X7C64);
    // 0x8001EDAC: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
    // 0x8001EDB0: addiu       $s2, $sp, 0x28
    ctx->r18 = ADD32(ctx->r29, 0X28);
    // 0x8001EDB4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
L_8001EDB8:
    // 0x8001EDB8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8001EDBC: jal         0x800205E0
    // 0x8001EDC0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8001EDC0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8001EDC4: bnel        $v0, $s0, L_8001EDB8
    if (ctx->r2 != ctx->r16) {
        // 0x8001EDC8: lw          $a0, 0x0($s1)
        ctx->r4 = MEM_W(ctx->r17, 0X0);
            goto L_8001EDB8;
    }
    goto skip_0;
    // 0x8001EDC8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    skip_0:
    // 0x8001EDCC: jal         0x8001E998
    // 0x8001EDD0: nop

    AudioThread_ResetCmdQueue(rdram, ctx);
        goto after_1;
    // 0x8001EDD0: nop

    after_1:
    // 0x8001EDD4: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x8001EDD8: lw          $a0, 0x7C60($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7C60);
    // 0x8001EDDC: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x8001EDE0: jal         0x80020720
    // 0x8001EDE4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x8001EDE4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x8001EDE8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8001EDEC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001EDF0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8001EDF4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8001EDF8: jr          $ra
    // 0x8001EDFC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8001EDFC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void Audio_DisableSetupOp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800184EC: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x800184F0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800184F4: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800184F8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800184FC: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80018500: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80018504: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80018508: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x8001850C: addiu       $t8, $t8, -0x5258
    ctx->r24 = ADD32(ctx->r24, -0X5258);
    // 0x80018510: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80018514: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x80018518: lbu         $a2, 0x41($v1)
    ctx->r6 = MEM_BU(ctx->r3, 0X41);
    // 0x8001851C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80018520: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80018524: andi        $a3, $a1, 0xFF
    ctx->r7 = ctx->r5 & 0XFF;
    // 0x80018528: blez        $a2, L_80018598
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8001852C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80018598;
    }
    // 0x8001852C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80018530: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x80018534: addu        $t9, $t9, $t6
    ctx->r25 = ADD32(ctx->r25, ctx->r14);
    // 0x80018538: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8001853C: subu        $t9, $t9, $t6
    ctx->r25 = SUB32(ctx->r25, ctx->r14);
    // 0x80018540: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80018544: subu        $t9, $t9, $t6
    ctx->r25 = SUB32(ctx->r25, ctx->r14);
    // 0x80018548: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x8001854C: addu        $a1, $t9, $t8
    ctx->r5 = ADD32(ctx->r25, ctx->r24);
    // 0x80018550: or          $t0, $a3, $zero
    ctx->r8 = ctx->r7 | 0;
    // 0x80018554: lui         $t2, 0xFF00
    ctx->r10 = S32(0XFF00 << 16);
    // 0x80018558: lui         $t1, 0xF0
    ctx->r9 = S32(0XF0 << 16);
L_8001855C:
    // 0x8001855C: sll         $t3, $v0, 2
    ctx->r11 = S32(ctx->r2 << 2);
    // 0x80018560: addu        $a3, $a1, $t3
    ctx->r7 = ADD32(ctx->r5, ctx->r11);
    // 0x80018564: lw          $t4, 0x2C($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X2C);
    // 0x80018568: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001856C: andi        $t7, $v0, 0xFF
    ctx->r15 = ctx->r2 & 0XFF;
    // 0x80018570: and         $a0, $t4, $t1
    ctx->r4 = ctx->r12 & ctx->r9;
    // 0x80018574: srl         $t5, $a0, 20
    ctx->r13 = S32(U32(ctx->r4) >> 20);
    // 0x80018578: andi        $t6, $t5, 0xFF
    ctx->r14 = ctx->r13 & 0XFF;
    // 0x8001857C: bnel        $t0, $t6, L_80018590
    if (ctx->r8 != ctx->r14) {
        // 0x80018580: slt         $at, $t7, $a2
        ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_80018590;
    }
    goto skip_0;
    // 0x80018580: slt         $at, $t7, $a2
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r6) ? 1 : 0;
    skip_0:
    // 0x80018584: sw          $t2, 0x2C($a3)
    MEM_W(0X2C, ctx->r7) = ctx->r10;
    // 0x80018588: lbu         $a2, 0x41($v1)
    ctx->r6 = MEM_BU(ctx->r3, 0X41);
    // 0x8001858C: slt         $at, $t7, $a2
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r6) ? 1 : 0;
L_80018590:
    // 0x80018590: bne         $at, $zero, L_8001855C
    if (ctx->r1 != 0) {
        // 0x80018594: or          $v0, $t7, $zero
        ctx->r2 = ctx->r15 | 0;
            goto L_8001855C;
    }
    // 0x80018594: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_80018598:
    // 0x80018598: jr          $ra
    // 0x8001859C: nop

    return;
    // 0x8001859C: nop

;}
RECOMP_FUNC void func_col1_800988B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800988B4: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800988B8: lwc1        $f8, 0x0($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800988BC: lwc1        $f16, 0x8($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800988C0: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x800988C4: lwc1        $f18, 0x8($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800988C8: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800988CC: lwc1        $f8, 0xC($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0XC);
    // 0x800988D0: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800988D4: lwc1        $f18, 0x4($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800988D8: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x800988DC: sub.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800988E0: div.s       $f10, $f16, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800988E4: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x800988E8: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x800988EC: nop

    // 0x800988F0: jr          $ra
    // 0x800988F4: nop

    return;
    // 0x800988F4: nop

;}
RECOMP_FUNC void func_tank_80047E7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80047E7C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80047E80: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80047E84: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80047E88: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x80047E8C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80047E90: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80047E94: lwc1        $f6, 0x74($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X74);
    // 0x80047E98: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80047E9C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80047EA0: c.lt.s      $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f6.fl < ctx->f12.fl;
    // 0x80047EA4: swc1        $f4, 0x188($s0)
    MEM_W(0X188, ctx->r16) = ctx->f4.u32l;
    // 0x80047EA8: bc1fl       L_80047F34
    if (!c1cs) {
        // 0x80047EAC: mtc1        $at, $f4
        ctx->f4.u32l = ctx->r1;
            goto L_80047F34;
    }
    goto skip_0;
    // 0x80047EAC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    skip_0:
    // 0x80047EB0: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x80047EB4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80047EB8: lwc1        $f8, 0x12C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X12C);
    // 0x80047EBC: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    // 0x80047EC0: addiu       $a0, $s0, 0x78
    ctx->r4 = ADD32(ctx->r16, 0X78);
    // 0x80047EC4: c.le.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl <= ctx->f8.fl;
    // 0x80047EC8: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    // 0x80047ECC: lui         $a3, 0x41F0
    ctx->r7 = S32(0X41F0 << 16);
    // 0x80047ED0: bc1fl       L_80047EFC
    if (!c1cs) {
        // 0x80047ED4: mtc1        $zero, $f18
        ctx->f18.u32l = 0;
            goto L_80047EFC;
    }
    goto skip_1;
    // 0x80047ED4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    skip_1:
    // 0x80047ED8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80047EDC: addiu       $a0, $s0, 0x12C
    ctx->r4 = ADD32(ctx->r16, 0X12C);
    // 0x80047EE0: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    // 0x80047EE4: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    // 0x80047EE8: jal         0x8009BC2C
    // 0x80047EEC: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_0;
    // 0x80047EEC: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_0:
    // 0x80047EF0: b           L_80047FAC
    // 0x80047EF4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80047FAC;
    // 0x80047EF4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80047EF8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
L_80047EFC:
    // 0x80047EFC: mfc1        $a1, $f14
    ctx->r5 = (int32_t)ctx->f14.u32l;
    // 0x80047F00: jal         0x8009BC2C
    // 0x80047F04: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_1;
    // 0x80047F04: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_1:
    // 0x80047F08: lw          $t6, 0x1DC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1DC);
    // 0x80047F0C: addiu       $v0, $zero, -0x14
    ctx->r2 = ADD32(0, -0X14);
    // 0x80047F10: addiu       $t7, $zero, 0x9
    ctx->r15 = ADD32(0, 0X9);
    // 0x80047F14: bne         $t6, $zero, L_80047FA8
    if (ctx->r14 != 0) {
        // 0x80047F18: addiu       $t8, $zero, 0xF
        ctx->r24 = ADD32(0, 0XF);
            goto L_80047FA8;
    }
    // 0x80047F18: addiu       $t8, $zero, 0xF
    ctx->r24 = ADD32(0, 0XF);
    // 0x80047F1C: sw          $t7, 0x1DC($s0)
    MEM_W(0X1DC, ctx->r16) = ctx->r15;
    // 0x80047F20: sw          $t8, 0x1E8($s0)
    MEM_W(0X1E8, ctx->r16) = ctx->r24;
    // 0x80047F24: sw          $v0, 0x1F0($s0)
    MEM_W(0X1F0, ctx->r16) = ctx->r2;
    // 0x80047F28: b           L_80047FA8
    // 0x80047F2C: sw          $v0, 0x1EC($s0)
    MEM_W(0X1EC, ctx->r16) = ctx->r2;
        goto L_80047FA8;
    // 0x80047F2C: sw          $v0, 0x1EC($s0)
    MEM_W(0X1EC, ctx->r16) = ctx->r2;
    // 0x80047F30: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
L_80047F34:
    // 0x80047F34: lwc1        $f6, 0x12C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X12C);
    // 0x80047F38: lui         $a1, 0xC1F0
    ctx->r5 = S32(0XC1F0 << 16);
    // 0x80047F3C: addiu       $a0, $s0, 0x78
    ctx->r4 = ADD32(ctx->r16, 0X78);
    // 0x80047F40: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x80047F44: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    // 0x80047F48: lui         $a3, 0x41F0
    ctx->r7 = S32(0X41F0 << 16);
    // 0x80047F4C: bc1fl       L_80047F78
    if (!c1cs) {
        // 0x80047F50: mtc1        $zero, $f10
        ctx->f10.u32l = 0;
            goto L_80047F78;
    }
    goto skip_2;
    // 0x80047F50: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    skip_2:
    // 0x80047F54: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80047F58: addiu       $a0, $s0, 0x12C
    ctx->r4 = ADD32(ctx->r16, 0X12C);
    // 0x80047F5C: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    // 0x80047F60: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    // 0x80047F64: jal         0x8009BC2C
    // 0x80047F68: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_2;
    // 0x80047F68: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x80047F6C: b           L_80047FAC
    // 0x80047F70: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80047FAC;
    // 0x80047F70: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80047F74: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
L_80047F78:
    // 0x80047F78: mfc1        $a1, $f14
    ctx->r5 = (int32_t)ctx->f14.u32l;
    // 0x80047F7C: jal         0x8009BC2C
    // 0x80047F80: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_3;
    // 0x80047F80: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_3:
    // 0x80047F84: lw          $t9, 0x1DC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1DC);
    // 0x80047F88: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    // 0x80047F8C: addiu       $t0, $zero, 0x9
    ctx->r8 = ADD32(0, 0X9);
    // 0x80047F90: bne         $t9, $zero, L_80047FA8
    if (ctx->r25 != 0) {
        // 0x80047F94: addiu       $t1, $zero, 0xF
        ctx->r9 = ADD32(0, 0XF);
            goto L_80047FA8;
    }
    // 0x80047F94: addiu       $t1, $zero, 0xF
    ctx->r9 = ADD32(0, 0XF);
    // 0x80047F98: sw          $t0, 0x1DC($s0)
    MEM_W(0X1DC, ctx->r16) = ctx->r8;
    // 0x80047F9C: sw          $t1, 0x1E8($s0)
    MEM_W(0X1E8, ctx->r16) = ctx->r9;
    // 0x80047FA0: sw          $v0, 0x1F0($s0)
    MEM_W(0X1F0, ctx->r16) = ctx->r2;
    // 0x80047FA4: sw          $v0, 0x1EC($s0)
    MEM_W(0X1EC, ctx->r16) = ctx->r2;
L_80047FA8:
    // 0x80047FA8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80047FAC:
    // 0x80047FAC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80047FB0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80047FB4: jr          $ra
    // 0x80047FB8: nop

    return;
    // 0x80047FB8: nop

;}
RECOMP_FUNC void guMtxL2F(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026E88: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x80026E8C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80026E90: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80026E94: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x80026E98: addiu       $v1, $a1, 0x20
    ctx->r3 = ADD32(ctx->r5, 0X20);
    // 0x80026E9C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80026EA0: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x80026EA4: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x80026EA8: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80026EAC: lui         $t2, 0xFFFF
    ctx->r10 = S32(0XFFFF << 16);
L_80026EB0:
    // 0x80026EB0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80026EB4: or          $t1, $t0, $zero
    ctx->r9 = ctx->r8 | 0;
L_80026EB8:
    // 0x80026EB8: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80026EBC: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80026EC0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80026EC4: srl         $t7, $t6, 16
    ctx->r15 = S32(U32(ctx->r14) >> 16);
    // 0x80026EC8: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x80026ECC: and         $t5, $t9, $t2
    ctx->r13 = ctx->r25 & ctx->r10;
    // 0x80026ED0: or          $t6, $t8, $t5
    ctx->r14 = ctx->r24 | ctx->r13;
    // 0x80026ED4: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
    // 0x80026ED8: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80026EDC: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80026EE0: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x80026EE4: andi        $t9, $t7, 0xFFFF
    ctx->r25 = ctx->r15 & 0XFFFF;
    // 0x80026EE8: sll         $t5, $t8, 16
    ctx->r13 = S32(ctx->r24 << 16);
    // 0x80026EEC: mtc1        $a1, $f18
    ctx->f18.u32l = ctx->r5;
    // 0x80026EF0: and         $t6, $t5, $t2
    ctx->r14 = ctx->r13 & ctx->r10;
    // 0x80026EF4: or          $a3, $t9, $t6
    ctx->r7 = ctx->r25 | ctx->r14;
    // 0x80026EF8: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80026EFC: mtc1        $a3, $f16
    ctx->f16.u32l = ctx->r7;
    // 0x80026F00: sw          $a3, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r7;
    // 0x80026F04: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80026F08: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80026F0C: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80026F10: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x80026F14: div.s       $f18, $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80026F18: div.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = DIV_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80026F1C: swc1        $f18, -0x8($t1)
    MEM_W(-0X8, ctx->r9) = ctx->f18.u32l;
    // 0x80026F20: bne         $a0, $t3, L_80026EB8
    if (ctx->r4 != ctx->r11) {
        // 0x80026F24: swc1        $f16, -0x4($t1)
        MEM_W(-0X4, ctx->r9) = ctx->f16.u32l;
            goto L_80026EB8;
    }
    // 0x80026F24: swc1        $f16, -0x4($t1)
    MEM_W(-0X4, ctx->r9) = ctx->f16.u32l;
    // 0x80026F28: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80026F2C: bne         $a2, $t4, L_80026EB0
    if (ctx->r6 != ctx->r12) {
        // 0x80026F30: addiu       $t0, $t0, 0x10
        ctx->r8 = ADD32(ctx->r8, 0X10);
            goto L_80026EB0;
    }
    // 0x80026F30: addiu       $t0, $t0, 0x10
    ctx->r8 = ADD32(ctx->r8, 0X10);
    // 0x80026F34: jr          $ra
    // 0x80026F38: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x80026F38: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void Player_ResetVsData(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AB964: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x800AB968: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AB96C: addiu       $t0, $t6, 0x7DD0
    ctx->r8 = ADD32(ctx->r14, 0X7DD0);
    // 0x800AB970: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800AB974: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800AB978: lui         $a3, 0x8017
    ctx->r7 = S32(0X8017 << 16);
    // 0x800AB97C: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x800AB980: sw          $zero, -0x78AC($at)
    MEM_W(-0X78AC, ctx->r1) = 0;
    // 0x800AB984: addiu       $t2, $t2, 0x7E70
    ctx->r10 = ADD32(ctx->r10, 0X7E70);
    // 0x800AB988: addiu       $a3, $a3, 0x7DA0
    ctx->r7 = ADD32(ctx->r7, 0X7DA0);
    // 0x800AB98C: addiu       $a2, $a2, 0x1AA8
    ctx->r6 = ADD32(ctx->r6, 0X1AA8);
    // 0x800AB990: addiu       $v1, $v1, 0x7DB8
    ctx->r3 = ADD32(ctx->r3, 0X7DB8);
    // 0x800AB994: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    // 0x800AB998: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
L_800AB99C:
    // 0x800AB99C: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x800AB9A0: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    // 0x800AB9A4: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x800AB9A8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800AB9AC: addiu       $a1, $a0, 0x8
    ctx->r5 = ADD32(ctx->r4, 0X8);
L_800AB9B0:
    // 0x800AB9B0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800AB9B4: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x800AB9B8: sw          $zero, 0x8($a1)
    MEM_W(0X8, ctx->r5) = 0;
    // 0x800AB9BC: sw          $zero, 0xC($a1)
    MEM_W(0XC, ctx->r5) = 0;
    // 0x800AB9C0: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x800AB9C4: bne         $v0, $t1, L_800AB9B0
    if (ctx->r2 != ctx->r9) {
        // 0x800AB9C8: sw          $zero, -0x10($a1)
        MEM_W(-0X10, ctx->r5) = 0;
            goto L_800AB9B0;
    }
    // 0x800AB9C8: sw          $zero, -0x10($a1)
    MEM_W(-0X10, ctx->r5) = 0;
    // 0x800AB9CC: addiu       $t0, $t0, 0x28
    ctx->r8 = ADD32(ctx->r8, 0X28);
    // 0x800AB9D0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800AB9D4: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    // 0x800AB9D8: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x800AB9DC: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x800AB9E0: sw          $zero, -0x4($a2)
    MEM_W(-0X4, ctx->r6) = 0;
    // 0x800AB9E4: bne         $t0, $t2, L_800AB99C
    if (ctx->r8 != ctx->r10) {
        // 0x800AB9E8: sw          $zero, -0x4($a3)
        MEM_W(-0X4, ctx->r7) = 0;
            goto L_800AB99C;
    }
    // 0x800AB9E8: sw          $zero, -0x4($a3)
    MEM_W(-0X4, ctx->r7) = 0;
    // 0x800AB9EC: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800AB9F0: addiu       $v0, $v0, 0x7E74
    ctx->r2 = ADD32(ctx->r2, 0X7E74);
    // 0x800AB9F4: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800AB9F8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800AB9FC: sw          $zero, 0x7E7C($at)
    MEM_W(0X7E7C, ctx->r1) = 0;
    // 0x800ABA00: jr          $ra
    // 0x800ABA04: nop

    return;
    // 0x800ABA04: nop

;}
RECOMP_FUNC void dummy_800B8F08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B8F08: jr          $ra
    // 0x800B8F0C: nop

    return;
    // 0x800B8F0C: nop

;}
RECOMP_FUNC void Effect_Sparkle_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80078EBC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80078EC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80078EC4: lh          $t6, 0x4E($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X4E);
    // 0x80078EC8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80078ECC: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80078ED0: bne         $t6, $at, L_80078EFC
    if (ctx->r14 != ctx->r1) {
        // 0x80078ED4: addiu       $v0, $v0, -0x7D80
        ctx->r2 = ADD32(ctx->r2, -0X7D80);
            goto L_80078EFC;
    }
    // 0x80078ED4: addiu       $v0, $v0, -0x7D80
    ctx->r2 = ADD32(ctx->r2, -0X7D80);
    // 0x80078ED8: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x80078EDC: lwc1        $f4, 0xC0($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0XC0);
    // 0x80078EE0: swc1        $f4, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f4.u32l;
    // 0x80078EE4: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80078EE8: lwc1        $f6, 0xC4($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0XC4);
    // 0x80078EEC: swc1        $f6, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f6.u32l;
    // 0x80078EF0: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80078EF4: lwc1        $f8, 0xC8($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0XC8);
    // 0x80078EF8: swc1        $f8, 0x5C($a0)
    MEM_W(0X5C, ctx->r4) = ctx->f8.u32l;
L_80078EFC:
    // 0x80078EFC: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x80078F00: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80078F04: lwc1        $f10, 0x18($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X18);
    // 0x80078F08: lhu         $t0, 0x50($a0)
    ctx->r8 = MEM_HU(ctx->r4, 0X50);
    // 0x80078F0C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80078F10: slti        $at, $t0, 0x7
    ctx->r1 = SIGNED(ctx->r8) < 0X7 ? 1 : 0;
    // 0x80078F14: bne         $at, $zero, L_80078F34
    if (ctx->r1 != 0) {
        // 0x80078F18: swc1        $f18, 0x18($a0)
        MEM_W(0X18, ctx->r4) = ctx->f18.u32l;
            goto L_80078F34;
    }
    // 0x80078F18: swc1        $f18, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f18.u32l;
    // 0x80078F1C: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80078F20: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80078F24: lwc1        $f4, 0x6C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x80078F28: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80078F2C: b           L_80078F48
    // 0x80078F30: swc1        $f8, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f8.u32l;
        goto L_80078F48;
    // 0x80078F30: swc1        $f8, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f8.u32l;
L_80078F34:
    // 0x80078F34: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80078F38: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80078F3C: lwc1        $f10, 0x6C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x80078F40: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80078F44: swc1        $f18, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f18.u32l;
L_80078F48:
    // 0x80078F48: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80078F4C: lwc1        $f6, 0x6C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x80078F50: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x80078F54: nop

    // 0x80078F58: bc1fl       L_80078F6C
    if (!c1cs) {
        // 0x80078F5C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80078F6C;
    }
    goto skip_0;
    // 0x80078F5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80078F60: jal         0x80060FBC
    // 0x80078F64: addiu       $a1, $a0, 0x80
    ctx->r5 = ADD32(ctx->r4, 0X80);
    Object_Kill(rdram, ctx);
        goto after_0;
    // 0x80078F64: addiu       $a1, $a0, 0x80
    ctx->r5 = ADD32(ctx->r4, 0X80);
    after_0:
    // 0x80078F68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80078F6C:
    // 0x80078F6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80078F70: jr          $ra
    // 0x80078F74: nop

    return;
    // 0x80078F74: nop

;}
RECOMP_FUNC void Matrix_RotateAxis(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000612C: addiu       $sp, $sp, -0xE0
    ctx->r29 = ADD32(ctx->r29, -0XE0);
    // 0x80006130: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x80006134: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x80006138: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x8000613C: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x80006140: mtc1        $a2, $f20
    ctx->f20.u32l = ctx->r6;
    // 0x80006144: mtc1        $a3, $f22
    ctx->f22.u32l = ctx->r7;
    // 0x80006148: mtc1        $a1, $f26
    ctx->f26.u32l = ctx->r5;
    // 0x8000614C: lwc1        $f24, 0xF0($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x80006150: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80006154: sdc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X38, ctx->r29);
    // 0x80006158: sdc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X30, ctx->r29);
    // 0x8000615C: mul.s       $f4, $f20, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x80006160: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x80006164: mul.s       $f6, $f22, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x80006168: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8000616C: mul.s       $f10, $f24, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = MUL_S(ctx->f24.fl, ctx->f24.fl);
    // 0x80006170: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80006174: add.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80006178: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x8000617C: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x80006180: c.eq.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d == ctx->f6.d;
    // 0x80006184: nop

    // 0x80006188: bc1tl       L_800064E0
    if (c1cs) {
        // 0x8000618C: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_800064E0;
    }
    goto skip_0;
    // 0x8000618C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_0:
    // 0x80006190: div.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = DIV_S(ctx->f20.fl, ctx->f0.fl);
    // 0x80006194: mov.s       $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    ctx->f12.fl = ctx->f26.fl;
    // 0x80006198: sw          $a0, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r4;
    // 0x8000619C: div.s       $f22, $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = DIV_S(ctx->f22.fl, ctx->f0.fl);
    // 0x800061A0: jal         0x80023090
    // 0x800061A4: div.s       $f24, $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f24.fl = DIV_S(ctx->f24.fl, ctx->f0.fl);
    __sinf_recomp(rdram, ctx);
        goto after_0;
    // 0x800061A4: div.s       $f24, $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f24.fl = DIV_S(ctx->f24.fl, ctx->f0.fl);
    after_0:
    // 0x800061A8: swc1        $f0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f0.u32l;
    // 0x800061AC: jal         0x80023250
    // 0x800061B0: mov.s       $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    ctx->f12.fl = ctx->f26.fl;
    __cosf_recomp(rdram, ctx);
        goto after_1;
    // 0x800061B0: mov.s       $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    ctx->f12.fl = ctx->f26.fl;
    after_1:
    // 0x800061B4: mul.s       $f26, $f20, $f22
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f26.fl = MUL_S(ctx->f20.fl, ctx->f22.fl);
    // 0x800061B8: lbu         $t6, 0xF7($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0XF7);
    // 0x800061BC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800061C0: mul.s       $f8, $f22, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = MUL_S(ctx->f22.fl, ctx->f24.fl);
    // 0x800061C4: lw          $a0, 0xE0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE0);
    // 0x800061C8: mul.s       $f10, $f20, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = MUL_S(ctx->f20.fl, ctx->f24.fl);
    // 0x800061CC: swc1        $f8, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f8.u32l;
    // 0x800061D0: bne         $t6, $at, L_80006400
    if (ctx->r14 != ctx->r1) {
        // 0x800061D4: swc1        $f10, 0x94($sp)
        MEM_W(0X94, ctx->r29) = ctx->f10.u32l;
            goto L_80006400;
    }
    // 0x800061D4: swc1        $f10, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f10.u32l;
    // 0x800061D8: swc1        $f24, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f24.u32l;
    // 0x800061DC: mul.s       $f24, $f20, $f20
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f24.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x800061E0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800061E4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800061E8: lwc1        $f2, 0x0($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800061EC: lwc1        $f12, 0x4($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800061F0: sub.s       $f16, $f18, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f18.fl - ctx->f0.fl;
    // 0x800061F4: lwc1        $f14, 0x8($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800061F8: sub.s       $f4, $f18, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f24.fl;
    // 0x800061FC: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80006200: lwc1        $f4, 0xF0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x80006204: mul.s       $f10, $f16, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f26.fl);
    // 0x80006208: add.s       $f8, $f6, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f24.fl;
    // 0x8000620C: lwc1        $f6, 0x90($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X90);
    // 0x80006210: swc1        $f10, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f10.u32l;
    // 0x80006214: lwc1        $f10, 0x5C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80006218: mul.s       $f28, $f4, $f6
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f28.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8000621C: swc1        $f8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f8.u32l;
    // 0x80006220: sub.s       $f4, $f10, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f28.fl;
    // 0x80006224: lwc1        $f10, 0x94($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X94);
    // 0x80006228: mul.s       $f10, $f16, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x8000622C: swc1        $f4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f4.u32l;
    // 0x80006230: mul.s       $f30, $f22, $f6
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f30.fl = MUL_S(ctx->f22.fl, ctx->f6.fl);
    // 0x80006234: swc1        $f10, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f10.u32l;
    // 0x80006238: lwc1        $f10, 0x6C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8000623C: add.s       $f6, $f10, $f30
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f30.fl;
    // 0x80006240: mul.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x80006244: nop

    // 0x80006248: mul.s       $f8, $f12, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x8000624C: swc1        $f6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f6.u32l;
    // 0x80006250: add.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80006254: mul.s       $f10, $f14, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f6.fl);
    // 0x80006258: nop

    // 0x8000625C: mul.s       $f24, $f22, $f22
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f24.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x80006260: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80006264: sub.s       $f10, $f18, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = ctx->f18.fl - ctx->f24.fl;
    // 0x80006268: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
    // 0x8000626C: lwc1        $f6, 0x5C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80006270: mul.s       $f8, $f10, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80006274: lwc1        $f10, 0x98($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X98);
    // 0x80006278: add.s       $f4, $f6, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f28.fl;
    // 0x8000627C: swc1        $f4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f4.u32l;
    // 0x80006280: add.s       $f6, $f8, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f24.fl;
    // 0x80006284: mul.s       $f8, $f16, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x80006288: lwc1        $f10, 0x90($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X90);
    // 0x8000628C: swc1        $f6, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f6.u32l;
    // 0x80006290: swc1        $f8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f8.u32l;
    // 0x80006294: mul.s       $f8, $f20, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f10.fl);
    // 0x80006298: lwc1        $f10, 0x4C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8000629C: swc1        $f8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f8.u32l;
    // 0x800062A0: lwc1        $f8, 0x48($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800062A4: sub.s       $f10, $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x800062A8: mul.s       $f8, $f2, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x800062AC: nop

    // 0x800062B0: mul.s       $f4, $f12, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f6.fl);
    // 0x800062B4: swc1        $f10, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f10.u32l;
    // 0x800062B8: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800062BC: mul.s       $f8, $f14, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f10.fl);
    // 0x800062C0: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800062C4: swc1        $f4, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f4.u32l;
    // 0x800062C8: lwc1        $f10, 0x6C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800062CC: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800062D0: lwc1        $f8, 0x4C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800062D4: sub.s       $f6, $f10, $f30
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f30.fl;
    // 0x800062D8: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800062DC: lwc1        $f8, 0xF0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x800062E0: swc1        $f6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f6.u32l;
    // 0x800062E4: mul.s       $f26, $f8, $f8
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f26.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x800062E8: swc1        $f10, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f10.u32l;
    // 0x800062EC: sub.s       $f4, $f18, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f26.fl;
    // 0x800062F0: mul.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800062F4: add.s       $f4, $f8, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f26.fl;
    // 0x800062F8: mul.s       $f8, $f12, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x800062FC: nop

    // 0x80006300: mul.s       $f10, $f2, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x80006304: swc1        $f4, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f4.u32l;
    // 0x80006308: lwc1        $f2, 0x10($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8000630C: lwc1        $f12, 0x14($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80006310: add.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80006314: mul.s       $f10, $f14, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f4.fl);
    // 0x80006318: lwc1        $f14, 0x18($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X18);
    // 0x8000631C: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80006320: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
    // 0x80006324: lwc1        $f4, 0x60($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80006328: lwc1        $f10, 0x50($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8000632C: mul.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80006330: nop

    // 0x80006334: mul.s       $f8, $f12, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x80006338: lwc1        $f10, 0x68($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8000633C: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80006340: mul.s       $f6, $f14, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f10.fl);
    // 0x80006344: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80006348: swc1        $f8, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f8.u32l;
    // 0x8000634C: lwc1        $f24, 0x58($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80006350: lwc1        $f18, 0x78($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80006354: lwc1        $f22, 0x64($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80006358: mul.s       $f10, $f2, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f24.fl);
    // 0x8000635C: lwc1        $f26, 0x54($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80006360: lwc1        $f20, 0x70($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80006364: mul.s       $f4, $f12, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f18.fl);
    // 0x80006368: lwc1        $f16, 0x7C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x8000636C: mul.s       $f8, $f14, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f22.fl);
    // 0x80006370: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80006374: mul.s       $f4, $f2, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f26.fl);
    // 0x80006378: lwc1        $f2, 0x20($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X20);
    // 0x8000637C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80006380: mul.s       $f6, $f12, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f20.fl);
    // 0x80006384: lwc1        $f12, 0x24($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X24);
    // 0x80006388: swc1        $f10, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f10.u32l;
    // 0x8000638C: mul.s       $f10, $f14, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f16.fl);
    // 0x80006390: lwc1        $f14, 0x28($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X28);
    // 0x80006394: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80006398: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8000639C: swc1        $f4, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f4.u32l;
    // 0x800063A0: lwc1        $f6, 0x60($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X60);
    // 0x800063A4: lwc1        $f10, 0x50($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800063A8: mul.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x800063AC: nop

    // 0x800063B0: mul.s       $f4, $f12, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x800063B4: lwc1        $f10, 0x68($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800063B8: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800063BC: mul.s       $f8, $f14, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f10.fl);
    // 0x800063C0: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800063C4: mul.s       $f10, $f2, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f24.fl);
    // 0x800063C8: nop

    // 0x800063CC: mul.s       $f6, $f12, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f18.fl);
    // 0x800063D0: swc1        $f4, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f4.u32l;
    // 0x800063D4: mul.s       $f4, $f14, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f22.fl);
    // 0x800063D8: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800063DC: mul.s       $f6, $f2, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f26.fl);
    // 0x800063E0: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800063E4: mul.s       $f8, $f12, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f20.fl);
    // 0x800063E8: swc1        $f10, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f10.u32l;
    // 0x800063EC: mul.s       $f10, $f14, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f16.fl);
    // 0x800063F0: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800063F4: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800063F8: b           L_800064DC
    // 0x800063FC: swc1        $f6, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f6.u32l;
        goto L_800064DC;
    // 0x800063FC: swc1        $f6, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f6.u32l;
L_80006400:
    // 0x80006400: swc1        $f24, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f24.u32l;
    // 0x80006404: mul.s       $f24, $f20, $f20
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f24.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x80006408: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000640C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80006410: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80006414: sub.s       $f16, $f18, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f18.fl - ctx->f0.fl;
    // 0x80006418: sub.s       $f8, $f18, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f24.fl;
    // 0x8000641C: mul.s       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80006420: add.s       $f10, $f4, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f24.fl;
    // 0x80006424: mul.s       $f2, $f16, $f26
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f2.fl = MUL_S(ctx->f16.fl, ctx->f26.fl);
    // 0x80006428: swc1        $f10, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f10.u32l;
    // 0x8000642C: lwc1        $f6, 0xF0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x80006430: lwc1        $f8, 0x90($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X90);
    // 0x80006434: mul.s       $f28, $f6, $f8
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f28.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80006438: add.s       $f4, $f2, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f28.fl;
    // 0x8000643C: swc1        $f4, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f4.u32l;
    // 0x80006440: lwc1        $f10, 0x94($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X94);
    // 0x80006444: lwc1        $f6, 0x90($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X90);
    // 0x80006448: sub.s       $f4, $f2, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f28.fl;
    // 0x8000644C: mul.s       $f12, $f16, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x80006450: swc1        $f14, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f14.u32l;
    // 0x80006454: mul.s       $f30, $f22, $f6
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f30.fl = MUL_S(ctx->f22.fl, ctx->f6.fl);
    // 0x80006458: swc1        $f4, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f4.u32l;
    // 0x8000645C: mul.s       $f24, $f22, $f22
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f24.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x80006460: sub.s       $f8, $f12, $f30
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f30.fl;
    // 0x80006464: sub.s       $f10, $f18, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = ctx->f18.fl - ctx->f24.fl;
    // 0x80006468: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
    // 0x8000646C: swc1        $f12, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f12.u32l;
    // 0x80006470: mul.s       $f6, $f10, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80006474: add.s       $f8, $f6, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f24.fl;
    // 0x80006478: swc1        $f8, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f8.u32l;
    // 0x8000647C: lwc1        $f4, 0x98($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X98);
    // 0x80006480: lwc1        $f10, 0x90($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X90);
    // 0x80006484: swc1        $f14, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f14.u32l;
    // 0x80006488: mul.s       $f12, $f16, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x8000648C: nop

    // 0x80006490: mul.s       $f2, $f20, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = MUL_S(ctx->f20.fl, ctx->f10.fl);
    // 0x80006494: add.s       $f6, $f12, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f12.fl + ctx->f2.fl;
    // 0x80006498: sub.s       $f10, $f12, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f12.fl - ctx->f2.fl;
    // 0x8000649C: swc1        $f6, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f6.u32l;
    // 0x800064A0: lwc1        $f8, 0x6C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800064A4: swc1        $f10, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f10.u32l;
    // 0x800064A8: add.s       $f4, $f8, $f30
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f30.fl;
    // 0x800064AC: swc1        $f4, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f4.u32l;
    // 0x800064B0: lwc1        $f2, 0xF0($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x800064B4: swc1        $f18, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f18.u32l;
    // 0x800064B8: swc1        $f14, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f14.u32l;
    // 0x800064BC: mul.s       $f26, $f2, $f2
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f26.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800064C0: swc1        $f14, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f14.u32l;
    // 0x800064C4: swc1        $f14, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f14.u32l;
    // 0x800064C8: swc1        $f14, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f14.u32l;
    // 0x800064CC: sub.s       $f6, $f18, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f26.fl;
    // 0x800064D0: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800064D4: add.s       $f4, $f8, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f26.fl;
    // 0x800064D8: swc1        $f4, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f4.u32l;
L_800064DC:
    // 0x800064DC: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_800064E0:
    // 0x800064E0: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x800064E4: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x800064E8: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x800064EC: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x800064F0: ldc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X30);
    // 0x800064F4: ldc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X38);
    // 0x800064F8: jr          $ra
    // 0x800064FC: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
    return;
    // 0x800064FC: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
;}
RECOMP_FUNC void Effect_Effect367_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007E648: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8007E64C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8007E650: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8007E654: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8007E658: lhu         $t6, 0x50($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X50);
    // 0x8007E65C: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x8007E660: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8007E664: bne         $t6, $zero, L_8007E6A4
    if (ctx->r14 != 0) {
        // 0x8007E668: addiu       $a0, $s0, 0x70
        ctx->r4 = ADD32(ctx->r16, 0X70);
            goto L_8007E6A4;
    }
    // 0x8007E668: addiu       $a0, $s0, 0x70
    ctx->r4 = ADD32(ctx->r16, 0X70);
    // 0x8007E66C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8007E670: lw          $a1, 0x6C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X6C);
    // 0x8007E674: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x8007E678: jal         0x8009BC2C
    // 0x8007E67C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_0;
    // 0x8007E67C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x8007E680: lh          $t7, 0x44($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X44);
    // 0x8007E684: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8007E688: addiu       $t8, $t7, -0x2
    ctx->r24 = ADD32(ctx->r15, -0X2);
    // 0x8007E68C: sh          $t8, 0x44($s0)
    MEM_H(0X44, ctx->r16) = ctx->r24;
    // 0x8007E690: lh          $t9, 0x44($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X44);
    // 0x8007E694: bgezl       $t9, L_8007E6A8
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8007E698: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8007E6A8;
    }
    goto skip_0;
    // 0x8007E698: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8007E69C: jal         0x80060FBC
    // 0x8007E6A0: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    Object_Kill(rdram, ctx);
        goto after_1;
    // 0x8007E6A0: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    after_1:
L_8007E6A4:
    // 0x8007E6A4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8007E6A8:
    // 0x8007E6A8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8007E6AC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8007E6B0: jr          $ra
    // 0x8007E6B4: nop

    return;
    // 0x8007E6B4: nop

;}
RECOMP_FUNC void ItemLasers_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005CC9C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005CCA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005CCA4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005CCA8: lwc1        $f6, 0x62A8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X62A8);
    // 0x8005CCAC: lwc1        $f4, 0x68($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X68);
    // 0x8005CCB0: mul.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8005CCB4: jal         0x8005980C
    // 0x8005CCB8: nop

    Graphics_SetScaleMtx(rdram, ctx);
        goto after_0;
    // 0x8005CCB8: nop

    after_0:
    // 0x8005CCBC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8005CCC0: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8005CCC4: jal         0x800B8DD0
    // 0x8005CCC8: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    RCP_SetupDL(rdram, ctx);
        goto after_1;
    // 0x8005CCC8: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    after_1:
    // 0x8005CCCC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8005CCD0: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8005CCD4: lui         $t1, 0x4
    ctx->r9 = S32(0X4 << 16);
    // 0x8005CCD8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8005CCDC: lui         $t7, 0xBB00
    ctx->r15 = S32(0XBB00 << 16);
    // 0x8005CCE0: lui         $t8, 0x7D0
    ctx->r24 = S32(0X7D0 << 16);
    // 0x8005CCE4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8005CCE8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8005CCEC: ori         $t8, $t8, 0x7D0
    ctx->r24 = ctx->r24 | 0X7D0;
    // 0x8005CCF0: ori         $t7, $t7, 0x1
    ctx->r15 = ctx->r15 | 0X1;
    // 0x8005CCF4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8005CCF8: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8005CCFC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8005CD00: lui         $t2, 0xB700
    ctx->r10 = S32(0XB700 << 16);
    // 0x8005CD04: lui         $t4, 0x600
    ctx->r12 = S32(0X600 << 16);
    // 0x8005CD08: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8005CD0C: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8005CD10: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x8005CD14: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x8005CD18: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8005CD1C: lui         $t5, 0x102
    ctx->r13 = S32(0X102 << 16);
    // 0x8005CD20: addiu       $t5, $t5, -0x67E0
    ctx->r13 = ADD32(ctx->r13, -0X67E0);
    // 0x8005CD24: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x8005CD28: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x8005CD2C: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x8005CD30: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8005CD34: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8005CD38: lui         $t7, 0xB600
    ctx->r15 = S32(0XB600 << 16);
    // 0x8005CD3C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8005CD40: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8005CD44: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x8005CD48: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8005CD4C: jal         0x800B8DD0
    // 0x8005CD50: addiu       $a1, $zero, 0x1B
    ctx->r5 = ADD32(0, 0X1B);
    RCP_SetupDL(rdram, ctx);
        goto after_2;
    // 0x8005CD50: addiu       $a1, $zero, 0x1B
    ctx->r5 = ADD32(0, 0X1B);
    after_2:
    // 0x8005CD54: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8005CD58: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8005CD5C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8005CD60: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x8005CD64: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x8005CD68: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8005CD6C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8005CD70: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x8005CD74: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8005CD78: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8005CD7C: lui         $t5, 0x102
    ctx->r13 = S32(0X102 << 16);
    // 0x8005CD80: addiu       $t5, $t5, -0x5720
    ctx->r13 = ADD32(ctx->r13, -0X5720);
    // 0x8005CD84: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x8005CD88: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x8005CD8C: lui         $t4, 0x600
    ctx->r12 = S32(0X600 << 16);
    // 0x8005CD90: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8005CD94: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x8005CD98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005CD9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005CDA0: jr          $ra
    // 0x8005CDA4: nop

    return;
    // 0x8005CDA4: nop

;}
RECOMP_FUNC void Effect_Effect364_Setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007B7E8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8007B7EC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8007B7F0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8007B7F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8007B7F8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8007B7FC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8007B800: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8007B804: jal         0x80061474
    // 0x8007B808: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Effect_Initialize(rdram, ctx);
        goto after_0;
    // 0x8007B808: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8007B80C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8007B810: addiu       $t7, $zero, 0x16C
    ctx->r15 = ADD32(0, 0X16C);
    // 0x8007B814: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
    // 0x8007B818: sh          $t7, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r15;
    // 0x8007B81C: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8007B820: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x8007B824: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8007B828: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x8007B82C: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8007B830: jal         0x80004EB0
    // 0x8007B834: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x8007B834: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    after_1:
    // 0x8007B838: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8007B83C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8007B840: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8007B844: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8007B848: sub.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x8007B84C: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8007B850: jal         0x80004EB0
    // 0x8007B854: swc1        $f4, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f4.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_2;
    // 0x8007B854: swc1        $f4, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f4.u32l;
    after_2:
    // 0x8007B858: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8007B85C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8007B860: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8007B864: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8007B868: sub.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x8007B86C: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x8007B870: sh          $t8, 0x48($s0)
    MEM_H(0X48, ctx->r16) = ctx->r24;
    // 0x8007B874: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8007B878: jal         0x80004EB0
    // 0x8007B87C: swc1        $f16, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f16.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_3;
    // 0x8007B87C: swc1        $f16, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f16.u32l;
    after_3:
    // 0x8007B880: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8007B884: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8007B888: addiu       $t1, $zero, 0x32
    ctx->r9 = ADD32(0, 0X32);
    // 0x8007B88C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8007B890: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x8007B894: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007B898: bc1fl       L_8007B8B0
    if (!c1cs) {
        // 0x8007B89C: sh          $t1, 0x4A($s0)
        MEM_H(0X4A, ctx->r16) = ctx->r9;
            goto L_8007B8B0;
    }
    goto skip_0;
    // 0x8007B89C: sh          $t1, 0x4A($s0)
    MEM_H(0X4A, ctx->r16) = ctx->r9;
    skip_0:
    // 0x8007B8A0: lh          $t9, 0x48($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X48);
    // 0x8007B8A4: negu        $t0, $t9
    ctx->r8 = SUB32(0, ctx->r25);
    // 0x8007B8A8: sh          $t0, 0x48($s0)
    MEM_H(0X48, ctx->r16) = ctx->r8;
    // 0x8007B8AC: sh          $t1, 0x4A($s0)
    MEM_H(0X4A, ctx->r16) = ctx->r9;
L_8007B8B0:
    // 0x8007B8B0: sh          $t2, 0x46($s0)
    MEM_H(0X46, ctx->r16) = ctx->r10;
    // 0x8007B8B4: lwc1        $f6, 0x73DC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X73DC);
    // 0x8007B8B8: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8007B8BC: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8007B8C0: jal         0x80004EB0
    // 0x8007B8C4: swc1        $f8, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f8.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_4;
    // 0x8007B8C4: swc1        $f8, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f8.u32l;
    after_4:
    // 0x8007B8C8: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8007B8CC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8007B8D0: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x8007B8D4: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    // 0x8007B8D8: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8007B8DC: jal         0x800612B8
    // 0x8007B8E0: swc1        $f16, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f16.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_5;
    // 0x8007B8E0: swc1        $f16, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f16.u32l;
    after_5:
    // 0x8007B8E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007B8E8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8007B8EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8007B8F0: jr          $ra
    // 0x8007B8F4: nop

    return;
    // 0x8007B8F4: nop

;}
RECOMP_FUNC void RCP_SetupDL_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B9008: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800B900C: addiu       $t3, $t3, 0x7E64
    ctx->r11 = ADD32(ctx->r11, 0X7E64);
    // 0x800B9010: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x800B9014: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x800B9018: addiu       $t8, $t8, 0x3288
    ctx->r24 = ADD32(ctx->r24, 0X3288);
    // 0x800B901C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800B9020: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x800B9024: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x800B9028: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800B902C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800B9030: lw          $t0, 0x0($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X0);
    // 0x800B9034: lui         $t4, 0xF800
    ctx->r12 = S32(0XF800 << 16);
    // 0x800B9038: andi        $t7, $a1, 0xFF
    ctx->r15 = ctx->r5 & 0XFF;
    // 0x800B903C: addiu       $t9, $t0, 0x8
    ctx->r25 = ADD32(ctx->r8, 0X8);
    // 0x800B9040: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x800B9044: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x800B9048: sll         $t6, $a0, 24
    ctx->r14 = S32(ctx->r4 << 24);
    // 0x800B904C: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
    // 0x800B9050: andi        $t4, $a2, 0xFF
    ctx->r12 = ctx->r6 & 0XFF;
    // 0x800B9054: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x800B9058: sll         $t5, $t4, 8
    ctx->r13 = S32(ctx->r12 << 8);
    // 0x800B905C: or          $t7, $t9, $t5
    ctx->r15 = ctx->r25 | ctx->r13;
    // 0x800B9060: andi        $t6, $a3, 0xFF
    ctx->r14 = ctx->r7 & 0XFF;
    // 0x800B9064: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x800B9068: sw          $t8, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r24;
    // 0x800B906C: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x800B9070: lui         $t9, 0xBC00
    ctx->r25 = S32(0XBC00 << 16);
    // 0x800B9074: ori         $t9, $t9, 0x8
    ctx->r25 = ctx->r25 | 0X8;
    // 0x800B9078: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x800B907C: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
    // 0x800B9080: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800B9084: lw          $t7, 0x10($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X10);
    // 0x800B9088: lw          $t5, 0x14($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X14);
    // 0x800B908C: lui         $t6, 0x1
    ctx->r14 = S32(0X1 << 16);
    // 0x800B9090: ori         $t6, $t6, 0xF400
    ctx->r14 = ctx->r14 | 0XF400;
    // 0x800B9094: subu        $t2, $t5, $t7
    ctx->r10 = SUB32(ctx->r13, ctx->r15);
    // 0x800B9098: div         $zero, $t6, $t2
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r10))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r10)));
    // 0x800B909C: negu        $t5, $t7
    ctx->r13 = SUB32(0, ctx->r15);
    // 0x800B90A0: mflo        $t4
    ctx->r12 = lo;
    // 0x800B90A4: sll         $t9, $t4, 16
    ctx->r25 = S32(ctx->r12 << 16);
    // 0x800B90A8: or          $t1, $v1, $zero
    ctx->r9 = ctx->r3 | 0;
    // 0x800B90AC: bne         $t2, $zero, L_800B90B8
    if (ctx->r10 != 0) {
        // 0x800B90B0: nop
    
            goto L_800B90B8;
    }
    // 0x800B90B0: nop

    // 0x800B90B4: break       7
    do_break(2148241588);
L_800B90B8:
    // 0x800B90B8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B90BC: bne         $t2, $at, L_800B90D0
    if (ctx->r10 != ctx->r1) {
        // 0x800B90C0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B90D0;
    }
    // 0x800B90C0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B90C4: bne         $t6, $at, L_800B90D0
    if (ctx->r14 != ctx->r1) {
        // 0x800B90C8: nop
    
            goto L_800B90D0;
    }
    // 0x800B90C8: nop

    // 0x800B90CC: break       6
    do_break(2148241612);
L_800B90D0:
    // 0x800B90D0: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x800B90D4: ori         $at, $at, 0xF400
    ctx->r1 = ctx->r1 | 0XF400;
    // 0x800B90D8: sll         $t6, $t5, 8
    ctx->r14 = S32(ctx->r13 << 8);
    // 0x800B90DC: addu        $t8, $t6, $at
    ctx->r24 = ADD32(ctx->r14, ctx->r1);
    // 0x800B90E0: div         $zero, $t8, $t2
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r10))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r10)));
    // 0x800B90E4: mflo        $t4
    ctx->r12 = lo;
    // 0x800B90E8: andi        $t7, $t4, 0xFFFF
    ctx->r15 = ctx->r12 & 0XFFFF;
    // 0x800B90EC: or          $t5, $t9, $t7
    ctx->r13 = ctx->r25 | ctx->r15;
    // 0x800B90F0: sw          $t5, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r13;
    // 0x800B90F4: bne         $t2, $zero, L_800B9100
    if (ctx->r10 != 0) {
        // 0x800B90F8: nop
    
            goto L_800B9100;
    }
    // 0x800B90F8: nop

    // 0x800B90FC: break       7
    do_break(2148241660);
L_800B9100:
    // 0x800B9100: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B9104: bne         $t2, $at, L_800B9118
    if (ctx->r10 != ctx->r1) {
        // 0x800B9108: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B9118;
    }
    // 0x800B9108: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B910C: bne         $t8, $at, L_800B9118
    if (ctx->r24 != ctx->r1) {
        // 0x800B9110: nop
    
            goto L_800B9118;
    }
    // 0x800B9110: nop

    // 0x800B9114: break       6
    do_break(2148241684);
L_800B9118:
    // 0x800B9118: jr          $ra
    // 0x800B911C: nop

    return;
    // 0x800B911C: nop

;}
RECOMP_FUNC void Audio_GetCurrentVoice(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001AE78: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8001AE7C: lw          $v0, -0x1674($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X1674);
    // 0x8001AE80: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x8001AE84: addiu       $t6, $t6, 0x2FE8
    ctx->r14 = ADD32(ctx->r14, 0X2FE8);
    // 0x8001AE88: bnel        $t6, $v0, L_8001AE9C
    if (ctx->r14 != ctx->r2) {
        // 0x8001AE8C: lb          $t7, 0xBD($v0)
        ctx->r15 = MEM_B(ctx->r2, 0XBD);
            goto L_8001AE9C;
    }
    goto skip_0;
    // 0x8001AE8C: lb          $t7, 0xBD($v0)
    ctx->r15 = MEM_B(ctx->r2, 0XBD);
    skip_0:
    // 0x8001AE90: jr          $ra
    // 0x8001AE94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8001AE94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001AE98: lb          $t7, 0xBD($v0)
    ctx->r15 = MEM_B(ctx->r2, 0XBD);
L_8001AE9C:
    // 0x8001AE9C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001AEA0: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x8001AEA4: bne         $t7, $at, L_8001AECC
    if (ctx->r15 != ctx->r1) {
        // 0x8001AEA8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8001AECC;
    }
    // 0x8001AEA8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001AEAC: lw          $v1, 0x7388($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7388);
    // 0x8001AEB0: sltiu       $at, $v1, 0x4
    ctx->r1 = ctx->r3 < 0X4 ? 1 : 0;
    // 0x8001AEB4: beq         $at, $zero, L_8001AEC4
    if (ctx->r1 == 0) {
        // 0x8001AEB8: nop
    
            goto L_8001AEC4;
    }
    // 0x8001AEB8: nop

    // 0x8001AEBC: jr          $ra
    // 0x8001AEC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8001AEC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001AEC4:
    // 0x8001AEC4: jr          $ra
    // 0x8001AEC8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8001AEC8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8001AECC:
    // 0x8001AECC: jr          $ra
    // 0x8001AED0: nop

    return;
    // 0x8001AED0: nop

;}
RECOMP_FUNC void Player_TankBoostBrake(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B3010: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800B3014: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800B3018: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800B301C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800B3020: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800B3024: lw          $t6, 0x2B8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X2B8);
    // 0x800B3028: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800B302C: bnel        $t6, $zero, L_800B3058
    if (ctx->r14 != 0) {
        // 0x800B3030: mtc1        $zero, $f2
        ctx->f2.u32l = 0;
            goto L_800B3058;
    }
    goto skip_0;
    // 0x800B3030: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    skip_0:
    // 0x800B3034: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800B3038: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800B303C: addiu       $a0, $s0, 0x2BC
    ctx->r4 = ADD32(ctx->r16, 0X2BC);
    // 0x800B3040: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x800B3044: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x800B3048: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800B304C: jal         0x8009BC2C
    // 0x800B3050: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_0;
    // 0x800B3050: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x800B3054: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
L_800B3058:
    // 0x800B3058: lwc1        $f4, 0x2BC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2BC);
    // 0x800B305C: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x800B3060: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800B3064: c.eq.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl == ctx->f4.fl;
    // 0x800B3068: sw          $zero, 0x2B8($s0)
    MEM_W(0X2B8, ctx->r16) = 0;
    // 0x800B306C: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x800B3070: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x800B3074: bc1f        L_800B308C
    if (!c1cs) {
        // 0x800B3078: nop
    
            goto L_800B308C;
    }
    // 0x800B3078: nop

    // 0x800B307C: sw          $zero, 0x2B4($s0)
    MEM_W(0X2B4, ctx->r16) = 0;
    // 0x800B3080: lw          $t7, 0x7974($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7974);
    // 0x800B3084: b           L_800B30F4
    // 0x800B3088: lhu         $v0, 0x0($t7)
    ctx->r2 = MEM_HU(ctx->r15, 0X0);
        goto L_800B30F4;
    // 0x800B3088: lhu         $v0, 0x0($t7)
    ctx->r2 = MEM_HU(ctx->r15, 0X0);
L_800B308C:
    // 0x800B308C: lw          $t8, 0x7974($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7974);
    // 0x800B3090: lhu         $v0, 0x0($t8)
    ctx->r2 = MEM_HU(ctx->r24, 0X0);
    // 0x800B3094: andi        $t9, $v0, 0x2000
    ctx->r25 = ctx->r2 & 0X2000;
    // 0x800B3098: bne         $t9, $zero, L_800B30F4
    if (ctx->r25 != 0) {
        // 0x800B309C: andi        $t0, $v0, 0x10
        ctx->r8 = ctx->r2 & 0X10;
            goto L_800B30F4;
    }
    // 0x800B309C: andi        $t0, $v0, 0x10
    ctx->r8 = ctx->r2 & 0X10;
    // 0x800B30A0: bnel        $t0, $zero, L_800B30F8
    if (ctx->r8 != 0) {
        // 0x800B30A4: swc1        $f6, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
            goto L_800B30F8;
    }
    goto skip_1;
    // 0x800B30A4: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    skip_1:
    // 0x800B30A8: lw          $v1, 0x1C4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1C4);
    // 0x800B30AC: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x800B30B0: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x800B30B4: sll         $t1, $v1, 1
    ctx->r9 = S32(ctx->r3 << 1);
    // 0x800B30B8: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x800B30BC: lhu         $t2, 0x7908($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0X7908);
    // 0x800B30C0: addu        $t4, $t4, $t1
    ctx->r12 = ADD32(ctx->r12, ctx->r9);
    // 0x800B30C4: and         $t3, $t2, $v0
    ctx->r11 = ctx->r10 & ctx->r2;
    // 0x800B30C8: bnel        $t3, $zero, L_800B30F8
    if (ctx->r11 != 0) {
        // 0x800B30CC: swc1        $f6, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
            goto L_800B30F8;
    }
    goto skip_2;
    // 0x800B30CC: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    skip_2:
    // 0x800B30D0: lhu         $t4, 0x7928($t4)
    ctx->r12 = MEM_HU(ctx->r12, 0X7928);
    // 0x800B30D4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800B30D8: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x800B30DC: and         $t5, $t4, $v0
    ctx->r13 = ctx->r12 & ctx->r2;
    // 0x800B30E0: bnel        $t5, $zero, L_800B30F8
    if (ctx->r13 != 0) {
        // 0x800B30E4: swc1        $f6, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
            goto L_800B30F8;
    }
    goto skip_3;
    // 0x800B30E4: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    skip_3:
    // 0x800B30E8: sw          $t6, 0x2B4($s0)
    MEM_W(0X2B4, ctx->r16) = ctx->r14;
    // 0x800B30EC: lw          $t7, 0x7974($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7974);
    // 0x800B30F0: lhu         $v0, 0x0($t7)
    ctx->r2 = MEM_HU(ctx->r15, 0X0);
L_800B30F4:
    // 0x800B30F4: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
L_800B30F8:
    // 0x800B30F8: lw          $s1, 0x1C4($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X1C4);
    // 0x800B30FC: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x800B3100: sll         $t8, $s1, 1
    ctx->r24 = S32(ctx->r17 << 1);
    // 0x800B3104: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800B3108: lhu         $t9, 0x7908($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0X7908);
    // 0x800B310C: and         $t0, $t9, $v0
    ctx->r8 = ctx->r25 & ctx->r2;
    // 0x800B3110: beql        $t0, $zero, L_800B31F8
    if (ctx->r8 == 0) {
        // 0x800B3114: lw          $s1, 0x1C4($s0)
        ctx->r17 = MEM_W(ctx->r16, 0X1C4);
            goto L_800B31F8;
    }
    goto skip_4;
    // 0x800B3114: lw          $s1, 0x1C4($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X1C4);
    skip_4:
    // 0x800B3118: lw          $t1, 0x2B4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X2B4);
    // 0x800B311C: addiu       $t2, $s0, 0x2BC
    ctx->r10 = ADD32(ctx->r16, 0X2BC);
    // 0x800B3120: bnel        $t1, $zero, L_800B31F8
    if (ctx->r9 != 0) {
        // 0x800B3124: lw          $s1, 0x1C4($s0)
        ctx->r17 = MEM_W(ctx->r16, 0X1C4);
            goto L_800B31F8;
    }
    goto skip_5;
    // 0x800B3124: lw          $s1, 0x1C4($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X1C4);
    skip_5:
    // 0x800B3128: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x800B312C: lwc1        $f8, 0x2BC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2BC);
    // 0x800B3130: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800B3134: addiu       $a0, $s0, 0x460
    ctx->r4 = ADD32(ctx->r16, 0X460);
    // 0x800B3138: c.eq.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl == ctx->f8.fl;
    // 0x800B313C: lui         $a1, 0x900
    ctx->r5 = S32(0X900 << 16);
    // 0x800B3140: bc1f        L_800B3168
    if (!c1cs) {
        // 0x800B3144: nop
    
            goto L_800B3168;
    }
    // 0x800B3144: nop

    // 0x800B3148: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800B314C: ori         $a1, $a1, 0x2
    ctx->r5 = ctx->r5 | 0X2;
    // 0x800B3150: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x800B3154: swc1        $f0, 0x194($s0)
    MEM_W(0X194, ctx->r16) = ctx->f0.u32l;
    // 0x800B3158: jal         0x800A5FA0
    // 0x800B315C: swc1        $f0, 0x190($s0)
    MEM_W(0X190, ctx->r16) = ctx->f0.u32l;
    Player_PlaySfx(rdram, ctx);
        goto after_1;
    // 0x800B315C: swc1        $f0, 0x190($s0)
    MEM_W(0X190, ctx->r16) = ctx->f0.u32l;
    after_1:
    // 0x800B3160: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800B3164: lw          $s1, 0x1C4($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X1C4);
L_800B3168:
    // 0x800B3168: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x800B316C: addiu       $t4, $t4, 0x79A8
    ctx->r12 = ADD32(ctx->r12, 0X79A8);
    // 0x800B3170: sll         $t3, $s1, 2
    ctx->r11 = S32(ctx->r17 << 2);
    // 0x800B3174: addu        $a0, $t3, $t4
    ctx->r4 = ADD32(ctx->r11, ctx->r12);
    // 0x800B3178: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    // 0x800B317C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x800B3180: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x800B3184: jal         0x8009BC2C
    // 0x800B3188: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_2;
    // 0x800B3188: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    after_2:
    // 0x800B318C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800B3190: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800B3194: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800B3198: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800B319C: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x800B31A0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800B31A4: swc1        $f10, 0x190($s0)
    MEM_W(0X190, ctx->r16) = ctx->f10.u32l;
    // 0x800B31A8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800B31AC: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800B31B0: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    // 0x800B31B4: sw          $t5, 0x2B8($s0)
    MEM_W(0X2B8, ctx->r16) = ctx->r13;
    // 0x800B31B8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800B31BC: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800B31C0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800B31C4: lui         $a1, 0x42B4
    ctx->r5 = S32(0X42B4 << 16);
    // 0x800B31C8: jal         0x8009BC2C
    // 0x800B31CC: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_3;
    // 0x800B31CC: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_3:
    // 0x800B31D0: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x800B31D4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800B31D8: lwc1        $f4, 0x2BC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2BC);
    // 0x800B31DC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800B31E0: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x800B31E4: nop

    // 0x800B31E8: bc1fl       L_800B31F8
    if (!c1cs) {
        // 0x800B31EC: lw          $s1, 0x1C4($s0)
        ctx->r17 = MEM_W(ctx->r16, 0X1C4);
            goto L_800B31F8;
    }
    goto skip_6;
    // 0x800B31EC: lw          $s1, 0x1C4($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X1C4);
    skip_6:
    // 0x800B31F0: sw          $t6, 0x2B4($s0)
    MEM_W(0X2B4, ctx->r16) = ctx->r14;
    // 0x800B31F4: lw          $s1, 0x1C4($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X1C4);
L_800B31F8:
    // 0x800B31F8: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x800B31FC: lw          $t9, 0x7974($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7974);
    // 0x800B3200: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x800B3204: sll         $t7, $s1, 1
    ctx->r15 = S32(ctx->r17 << 1);
    // 0x800B3208: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800B320C: lhu         $t8, 0x7928($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X7928);
    // 0x800B3210: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x800B3214: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800B3218: and         $t1, $t8, $t0
    ctx->r9 = ctx->r24 & ctx->r8;
    // 0x800B321C: beq         $t1, $zero, L_800B32DC
    if (ctx->r9 == 0) {
        // 0x800B3220: nop
    
            goto L_800B32DC;
    }
    // 0x800B3220: nop

    // 0x800B3224: lw          $t2, 0x2B4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X2B4);
    // 0x800B3228: addiu       $t3, $s0, 0x2BC
    ctx->r11 = ADD32(ctx->r16, 0X2BC);
    // 0x800B322C: bne         $t2, $zero, L_800B32DC
    if (ctx->r10 != 0) {
        // 0x800B3230: nop
    
            goto L_800B32DC;
    }
    // 0x800B3230: nop

    // 0x800B3234: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x800B3238: lwc1        $f8, 0x2BC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2BC);
    // 0x800B323C: lui         $a1, 0x900
    ctx->r5 = S32(0X900 << 16);
    // 0x800B3240: ori         $a1, $a1, 0x3
    ctx->r5 = ctx->r5 | 0X3;
    // 0x800B3244: c.eq.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl == ctx->f8.fl;
    // 0x800B3248: addiu       $a0, $s0, 0x460
    ctx->r4 = ADD32(ctx->r16, 0X460);
    // 0x800B324C: bc1f        L_800B3264
    if (!c1cs) {
        // 0x800B3250: nop
    
            goto L_800B3264;
    }
    // 0x800B3250: nop

    // 0x800B3254: jal         0x800A5FA0
    // 0x800B3258: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    Player_PlaySfx(rdram, ctx);
        goto after_4;
    // 0x800B3258: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_4:
    // 0x800B325C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800B3260: lw          $s1, 0x1C4($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X1C4);
L_800B3264:
    // 0x800B3264: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x800B3268: addiu       $t5, $t5, 0x79A8
    ctx->r13 = ADD32(ctx->r13, 0X79A8);
    // 0x800B326C: sll         $t4, $s1, 2
    ctx->r12 = S32(ctx->r17 << 2);
    // 0x800B3270: addu        $a0, $t4, $t5
    ctx->r4 = ADD32(ctx->r12, ctx->r13);
    // 0x800B3274: lui         $a1, 0x41A0
    ctx->r5 = S32(0X41A0 << 16);
    // 0x800B3278: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x800B327C: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x800B3280: jal         0x8009BC2C
    // 0x800B3284: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_5;
    // 0x800B3284: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    after_5:
    // 0x800B3288: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x800B328C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800B3290: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800B3294: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800B3298: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    // 0x800B329C: sw          $t6, 0x2B8($s0)
    MEM_W(0X2B8, ctx->r16) = ctx->r14;
    // 0x800B32A0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800B32A4: lui         $a1, 0x42B4
    ctx->r5 = S32(0X42B4 << 16);
    // 0x800B32A8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x800B32AC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x800B32B0: jal         0x8009BC2C
    // 0x800B32B4: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_6;
    // 0x800B32B4: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_6:
    // 0x800B32B8: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x800B32BC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800B32C0: lwc1        $f18, 0x2BC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X2BC);
    // 0x800B32C4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800B32C8: c.le.s      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.fl <= ctx->f18.fl;
    // 0x800B32CC: nop

    // 0x800B32D0: bc1f        L_800B32DC
    if (!c1cs) {
        // 0x800B32D4: nop
    
            goto L_800B32DC;
    }
    // 0x800B32D4: nop

    // 0x800B32D8: sw          $t7, 0x2B4($s0)
    MEM_W(0X2B4, ctx->r16) = ctx->r15;
L_800B32DC:
    // 0x800B32DC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B32E0: lwc1        $f6, -0x7664($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7664);
    // 0x800B32E4: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x800B32E8: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800B32EC: addiu       $a0, $s0, 0xD0
    ctx->r4 = ADD32(ctx->r16, 0XD0);
    // 0x800B32F0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800B32F4: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x800B32F8: jal         0x8009BC2C
    // 0x800B32FC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_7;
    // 0x800B32FC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_7:
    // 0x800B3300: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800B3304: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800B3308: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800B330C: jr          $ra
    // 0x800B3310: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800B3310: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void Game_ChangeScene(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A1B6C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A1B70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A1B74: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800A1B78: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x800A1B7C: lbu         $t6, 0x2910($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X2910);
    // 0x800A1B80: lw          $v0, 0x74F8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X74F8);
    // 0x800A1B84: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x800A1B88: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800A1B8C: beq         $v0, $t6, L_800A1BA4
    if (ctx->r2 == ctx->r14) {
        // 0x800A1B90: lui         $a1, 0x800D
        ctx->r5 = S32(0X800D << 16);
            goto L_800A1BA4;
    }
    // 0x800A1B90: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x800A1B94: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800A1B98: sb          $v0, 0x2910($at)
    MEM_B(0X2910, ctx->r1) = ctx->r2;
    // 0x800A1B9C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800A1BA0: sb          $v1, 0x2908($at)
    MEM_B(0X2908, ctx->r1) = ctx->r3;
L_800A1BA4:
    // 0x800A1BA4: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800A1BA8: lbu         $v1, 0x2908($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X2908);
    // 0x800A1BAC: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x800A1BB0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800A1BB4: bne         $v1, $zero, L_800A1BD4
    if (ctx->r3 != 0) {
        // 0x800A1BB8: nop
    
            goto L_800A1BD4;
    }
    // 0x800A1BB8: nop

    // 0x800A1BBC: lbu         $t7, 0x2910($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X2910);
    // 0x800A1BC0: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x800A1BC4: lw          $t8, 0x7820($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7820);
    // 0x800A1BC8: sb          $t7, 0x290C($at)
    MEM_B(0X290C, ctx->r1) = ctx->r15;
    // 0x800A1BCC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800A1BD0: sb          $t8, 0x2914($at)
    MEM_B(0X2914, ctx->r1) = ctx->r24;
L_800A1BD4:
    // 0x800A1BD4: lbu         $a0, 0x290C($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X290C);
    // 0x800A1BD8: jal         0x80058F14
    // 0x800A1BDC: lbu         $a1, 0x2914($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X2914);
    Load_SceneSetup(rdram, ctx);
        goto after_0;
    // 0x800A1BDC: lbu         $a1, 0x2914($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X2914);
    after_0:
    // 0x800A1BE0: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800A1BE4: lbu         $v1, 0x2908($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X2908);
    // 0x800A1BE8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800A1BEC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800A1BF0: beq         $v1, $zero, L_800A1C04
    if (ctx->r3 == 0) {
        // 0x800A1BF4: addiu       $t9, $v1, -0x1
        ctx->r25 = ADD32(ctx->r3, -0X1);
            goto L_800A1C04;
    }
    // 0x800A1BF4: addiu       $t9, $v1, -0x1
    ctx->r25 = ADD32(ctx->r3, -0X1);
    // 0x800A1BF8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800A1BFC: b           L_800A1C04
    // 0x800A1C00: sb          $t9, 0x2908($at)
    MEM_B(0X2908, ctx->r1) = ctx->r25;
        goto L_800A1C04;
    // 0x800A1C00: sb          $t9, 0x2908($at)
    MEM_B(0X2908, ctx->r1) = ctx->r25;
L_800A1C04:
    // 0x800A1C04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A1C08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A1C0C: jr          $ra
    // 0x800A1C10: nop

    return;
    // 0x800A1C10: nop

;}
RECOMP_FUNC void func_effect_800815DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800815DC: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800815E0: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x800815E4: addiu       $t2, $t2, 0x37E0
    ctx->r10 = ADD32(ctx->r10, 0X37E0);
    // 0x800815E8: addiu       $v1, $v1, 0x130
    ctx->r3 = ADD32(ctx->r3, 0X130);
    // 0x800815EC: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x800815F0: addiu       $t0, $zero, 0x15A
    ctx->r8 = ADD32(0, 0X15A);
    // 0x800815F4: addiu       $a3, $zero, 0x16C
    ctx->r7 = ADD32(0, 0X16C);
    // 0x800815F8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800815FC: addiu       $a1, $zero, 0x18B
    ctx->r5 = ADD32(0, 0X18B);
    // 0x80081600: addiu       $a0, $zero, 0x16E
    ctx->r4 = ADD32(0, 0X16E);
    // 0x80081604: lhu         $v0, 0x2($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X2);
L_80081608:
    // 0x80081608: beql        $a0, $v0, L_80081638
    if (ctx->r4 == ctx->r2) {
        // 0x8008160C: lbu         $t7, 0x0($v1)
        ctx->r15 = MEM_BU(ctx->r3, 0X0);
            goto L_80081638;
    }
    goto skip_0;
    // 0x8008160C: lbu         $t7, 0x0($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X0);
    skip_0:
    // 0x80081610: bne         $a1, $v0, L_80081624
    if (ctx->r5 != ctx->r2) {
        // 0x80081614: nop
    
            goto L_80081624;
    }
    // 0x80081614: nop

    // 0x80081618: lh          $t6, 0x4E($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X4E);
    // 0x8008161C: beql        $a2, $t6, L_80081638
    if (ctx->r6 == ctx->r14) {
        // 0x80081620: lbu         $t7, 0x0($v1)
        ctx->r15 = MEM_BU(ctx->r3, 0X0);
            goto L_80081638;
    }
    goto skip_1;
    // 0x80081620: lbu         $t7, 0x0($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X0);
    skip_1:
L_80081624:
    // 0x80081624: beql        $a3, $v0, L_80081638
    if (ctx->r7 == ctx->r2) {
        // 0x80081628: lbu         $t7, 0x0($v1)
        ctx->r15 = MEM_BU(ctx->r3, 0X0);
            goto L_80081638;
    }
    goto skip_2;
    // 0x80081628: lbu         $t7, 0x0($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X0);
    skip_2:
    // 0x8008162C: bnel        $t0, $v0, L_8008164C
    if (ctx->r8 != ctx->r2) {
        // 0x80081630: addiu       $v1, $v1, 0x8C
        ctx->r3 = ADD32(ctx->r3, 0X8C);
            goto L_8008164C;
    }
    goto skip_3;
    // 0x80081630: addiu       $v1, $v1, 0x8C
    ctx->r3 = ADD32(ctx->r3, 0X8C);
    skip_3:
    // 0x80081634: lbu         $t7, 0x0($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X0);
L_80081638:
    // 0x80081638: bnel        $t1, $t7, L_8008164C
    if (ctx->r9 != ctx->r15) {
        // 0x8008163C: addiu       $v1, $v1, 0x8C
        ctx->r3 = ADD32(ctx->r3, 0X8C);
            goto L_8008164C;
    }
    goto skip_4;
    // 0x8008163C: addiu       $v1, $v1, 0x8C
    ctx->r3 = ADD32(ctx->r3, 0X8C);
    skip_4:
    // 0x80081640: jr          $ra
    // 0x80081644: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    return;
    // 0x80081644: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // 0x80081648: addiu       $v1, $v1, 0x8C
    ctx->r3 = ADD32(ctx->r3, 0X8C);
L_8008164C:
    // 0x8008164C: bnel        $v1, $t2, L_80081608
    if (ctx->r3 != ctx->r10) {
        // 0x80081650: lhu         $v0, 0x2($v1)
        ctx->r2 = MEM_HU(ctx->r3, 0X2);
            goto L_80081608;
    }
    goto skip_5;
    // 0x80081650: lhu         $v0, 0x2($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X2);
    skip_5:
    // 0x80081654: jr          $ra
    // 0x80081658: nop

    return;
    // 0x80081658: nop

;}
RECOMP_FUNC void Camera_UpdateArwingOnRails(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B56BC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800B56C0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800B56C4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800B56C8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800B56CC: lwc1        $f4, 0x74($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X74);
    // 0x800B56D0: lwc1        $f6, 0xAC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XAC);
    // 0x800B56D4: lwc1        $f10, 0x148($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X148);
    // 0x800B56D8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B56DC: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800B56E0: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800B56E4: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800B56E8: swc1        $f16, 0x7978($at)
    MEM_W(0X7978, ctx->r1) = ctx->f16.u32l;
    // 0x800B56EC: lw          $t6, 0x1CC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1CC);
    // 0x800B56F0: bnel        $t6, $zero, L_800B570C
    if (ctx->r14 != 0) {
        // 0x800B56F4: lw          $v1, 0x1C8($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X1C8);
            goto L_800B570C;
    }
    goto skip_0;
    // 0x800B56F4: lw          $v1, 0x1C8($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1C8);
    skip_0:
    // 0x800B56F8: lw          $t7, 0x1C8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1C8);
    // 0x800B56FC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800B5700: beql        $t7, $at, L_800B571C
    if (ctx->r15 == ctx->r1) {
        // 0x800B5704: lwc1        $f18, 0x78($s0)
        ctx->f18.u32l = MEM_W(ctx->r16, 0X78);
            goto L_800B571C;
    }
    goto skip_1;
    // 0x800B5704: lwc1        $f18, 0x78($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X78);
    skip_1:
    // 0x800B5708: lw          $v1, 0x1C8($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1C8);
L_800B570C:
    // 0x800B570C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800B5710: bne         $v1, $at, L_800B5738
    if (ctx->r3 != ctx->r1) {
        // 0x800B5714: nop
    
            goto L_800B5738;
    }
    // 0x800B5714: nop

    // 0x800B5718: lwc1        $f18, 0x78($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X78);
L_800B571C:
    // 0x800B571C: lwc1        $f4, 0xB0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XB0);
    // 0x800B5720: lwc1        $f8, 0x148($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X148);
    // 0x800B5724: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B5728: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x800B572C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800B5730: swc1        $f10, 0x7980($at)
    MEM_W(0X7980, ctx->r1) = ctx->f10.u32l;
    // 0x800B5734: lw          $v1, 0x1C8($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1C8);
L_800B5738:
    // 0x800B5738: lw          $v0, 0x797C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X797C);
    // 0x800B573C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800B5740: lb          $t9, 0x3($v0)
    ctx->r25 = MEM_B(ctx->r2, 0X3);
    // 0x800B5744: lb          $t8, 0x2($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X2);
    // 0x800B5748: negu        $t3, $t9
    ctx->r11 = SUB32(0, ctx->r25);
    // 0x800B574C: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x800B5750: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x800B5754: cvt.s.w     $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800B5758: bne         $v1, $at, L_800B576C
    if (ctx->r3 != ctx->r1) {
        // 0x800B575C: cvt.s.w     $f2, $f16
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = CVT_S_W(ctx->f16.u32l);
            goto L_800B576C;
    }
    // 0x800B575C: cvt.s.w     $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800B5760: lw          $t4, 0x4DC($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X4DC);
    // 0x800B5764: beq         $t4, $zero, L_800B5778
    if (ctx->r12 == 0) {
        // 0x800B5768: nop
    
            goto L_800B5778;
    }
    // 0x800B5768: nop

L_800B576C:
    // 0x800B576C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800B5770: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800B5774: nop

L_800B5778:
    // 0x800B5778: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B577C: lwc1        $f4, -0x75B4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X75B4);
    // 0x800B5780: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B5784: lwc1        $f8, -0x75B0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X75B0);
    // 0x800B5788: mul.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x800B578C: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x800B5790: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800B5794: addiu       $a0, $s0, 0x30
    ctx->r4 = ADD32(ctx->r16, 0X30);
    // 0x800B5798: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    // 0x800B579C: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x800B57A0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x800B57A4: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800B57A8: jal         0x8009BC2C
    // 0x800B57AC: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_0;
    // 0x800B57AC: nop

    after_0:
    // 0x800B57B0: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x800B57B4: lbu         $t5, 0x7C98($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0X7C98);
    // 0x800B57B8: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x800B57BC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800B57C0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800B57C4: bne         $t5, $at, L_800B5808
    if (ctx->r13 != ctx->r1) {
        // 0x800B57C8: lwc1        $f0, 0x28($sp)
        ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
            goto L_800B5808;
    }
    // 0x800B57C8: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800B57CC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B57D0: lwc1        $f10, -0x75AC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X75AC);
    // 0x800B57D4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B57D8: lwc1        $f18, -0x75A8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X75A8);
    // 0x800B57DC: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x800B57E0: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x800B57E4: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x800B57E8: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800B57EC: addiu       $a0, $s0, 0x2C
    ctx->r4 = ADD32(ctx->r16, 0X2C);
    // 0x800B57F0: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x800B57F4: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x800B57F8: jal         0x8009BC2C
    // 0x800B57FC: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_1;
    // 0x800B57FC: nop

    after_1:
    // 0x800B5800: b           L_800B5898
    // 0x800B5804: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
        goto L_800B5898;
    // 0x800B5804: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
L_800B5808:
    // 0x800B5808: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B580C: lwc1        $f6, 0x7940($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7940);
    // 0x800B5810: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x800B5814: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800B5818: lwc1        $f4, 0x78($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X78);
    // 0x800B581C: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x800B5820: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800B5824: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B5828: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800B582C: addiu       $a0, $s0, 0x2C
    ctx->r4 = ADD32(ctx->r16, 0X2C);
    // 0x800B5830: c.lt.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl < ctx->f10.fl;
    // 0x800B5834: nop

    // 0x800B5838: bc1fl       L_800B587C
    if (!c1cs) {
        // 0x800B583C: add.s       $f8, $f0, $f0
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f0.fl;
            goto L_800B587C;
    }
    goto skip_2;
    // 0x800B583C: add.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f0.fl;
    skip_2:
    // 0x800B5840: lwc1        $f16, -0x75A4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X75A4);
    // 0x800B5844: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B5848: lwc1        $f6, -0x75A0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X75A0);
    // 0x800B584C: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x800B5850: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x800B5854: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x800B5858: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800B585C: addiu       $a0, $s0, 0x2C
    ctx->r4 = ADD32(ctx->r16, 0X2C);
    // 0x800B5860: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x800B5864: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x800B5868: jal         0x8009BC2C
    // 0x800B586C: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_2;
    // 0x800B586C: nop

    after_2:
    // 0x800B5870: b           L_800B5898
    // 0x800B5874: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
        goto L_800B5898;
    // 0x800B5874: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x800B5878: add.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f0.fl;
L_800B587C:
    // 0x800B587C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B5880: lwc1        $f4, -0x759C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X759C);
    // 0x800B5884: lui         $a3, 0x4080
    ctx->r7 = S32(0X4080 << 16);
    // 0x800B5888: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x800B588C: jal         0x8009BC2C
    // 0x800B5890: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_3;
    // 0x800B5890: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_3:
    // 0x800B5894: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
L_800B5898:
    // 0x800B5898: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800B589C: lwc1        $f10, 0x30($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X30);
    // 0x800B58A0: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x800B58A4: addiu       $t1, $t1, 0x7978
    ctx->r9 = ADD32(ctx->r9, 0X7978);
    // 0x800B58A8: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800B58AC: lwc1        $f6, 0x0($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X0);
    // 0x800B58B0: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x800B58B4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800B58B8: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x800B58BC: addiu       $t2, $t2, 0x7980
    ctx->r10 = ADD32(ctx->r10, 0X7980);
    // 0x800B58C0: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800B58C4: sub.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f18.fl;
    // 0x800B58C8: lwc1        $f6, 0x0($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X0);
    // 0x800B58CC: addiu       $v1, $v1, 0x79A0
    ctx->r3 = ADD32(ctx->r3, 0X79A0);
    // 0x800B58D0: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x800B58D4: swc1        $f8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f8.u32l;
    // 0x800B58D8: lwc1        $f4, 0x2C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x800B58DC: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x800B58E0: addiu       $t0, $t0, 0x79B8
    ctx->r8 = ADD32(ctx->r8, 0X79B8);
    // 0x800B58E4: sub.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x800B58E8: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800B58EC: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800B58F0: lui         $a2, 0x3ECC
    ctx->r6 = S32(0X3ECC << 16);
    // 0x800B58F4: sub.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f6.fl - ctx->f16.fl;
    // 0x800B58F8: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800B58FC: addiu       $a0, $a0, 0x2F58
    ctx->r4 = ADD32(ctx->r4, 0X2F58);
    // 0x800B5900: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x800B5904: swc1        $f18, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f18.u32l;
    // 0x800B5908: lwc1        $f4, 0xAC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XAC);
    // 0x800B590C: lwc1        $f8, 0x74($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X74);
    // 0x800B5910: lwc1        $f6, 0x14C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14C);
    // 0x800B5914: sub.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x800B5918: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800B591C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800B5920: mul.s       $f16, $f10, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x800B5924: swc1        $f16, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f16.u32l;
    // 0x800B5928: lwc1        $f18, 0x84($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X84);
    // 0x800B592C: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800B5930: mul.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x800B5934: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800B5938: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x800B593C: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800B5940: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
    // 0x800B5944: lwc1        $f16, 0x30($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X30);
    // 0x800B5948: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800B594C: mul.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800B5950: sub.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x800B5954: swc1        $f4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f4.u32l;
    // 0x800B5958: lwc1        $f16, 0xB0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XB0);
    // 0x800B595C: lwc1        $f6, 0x78($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X78);
    // 0x800B5960: lwc1        $f10, 0x14C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14C);
    // 0x800B5964: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800B5968: sub.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f6.fl - ctx->f16.fl;
    // 0x800B596C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x800B5970: mul.s       $f8, $f18, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x800B5974: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800B5978: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x800B597C: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800B5980: swc1        $f6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f6.u32l;
    // 0x800B5984: lwc1        $f16, 0x60($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X60);
    // 0x800B5988: lwc1        $f8, 0x0($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X0);
    // 0x800B598C: mul.s       $f10, $f16, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800B5990: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800B5994: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800B5998: swc1        $f4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f4.u32l;
    // 0x800B599C: lwc1        $f6, 0x2C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x800B59A0: lwc1        $f8, 0x0($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X0);
    // 0x800B59A4: mul.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x800B59A8: sub.s       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x800B59AC: swc1        $f10, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f10.u32l;
    // 0x800B59B0: lw          $v0, 0x2F54($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X2F54);
    // 0x800B59B4: beq         $v0, $zero, L_800B59CC
    if (ctx->r2 == 0) {
        // 0x800B59B8: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_800B59CC;
    }
    // 0x800B59B8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800B59BC: beq         $v0, $at, L_800B5A00
    if (ctx->r2 == ctx->r1) {
        // 0x800B59C0: lui         $a0, 0x800D
        ctx->r4 = S32(0X800D << 16);
            goto L_800B5A00;
    }
    // 0x800B59C0: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800B59C4: b           L_800B5A44
    // 0x800B59C8: lwc1        $f16, 0x0($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0X0);
        goto L_800B5A44;
    // 0x800B59C8: lwc1        $f16, 0x0($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0X0);
L_800B59CC:
    // 0x800B59CC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800B59D0: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x800B59D4: jal         0x8009BC2C
    // 0x800B59D8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_4;
    // 0x800B59D8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_4:
    // 0x800B59DC: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x800B59E0: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x800B59E4: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x800B59E8: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800B59EC: addiu       $v1, $v1, 0x79A0
    ctx->r3 = ADD32(ctx->r3, 0X79A0);
    // 0x800B59F0: addiu       $t0, $t0, 0x79B8
    ctx->r8 = ADD32(ctx->r8, 0X79B8);
    // 0x800B59F4: addiu       $t1, $t1, 0x7978
    ctx->r9 = ADD32(ctx->r9, 0X7978);
    // 0x800B59F8: b           L_800B5A40
    // 0x800B59FC: addiu       $t2, $t2, 0x7980
    ctx->r10 = ADD32(ctx->r10, 0X7980);
        goto L_800B5A40;
    // 0x800B59FC: addiu       $t2, $t2, 0x7980
    ctx->r10 = ADD32(ctx->r10, 0X7980);
L_800B5A00:
    // 0x800B5A00: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800B5A04: lui         $a2, 0x3ECC
    ctx->r6 = S32(0X3ECC << 16);
    // 0x800B5A08: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800B5A0C: addiu       $a0, $a0, 0x2F58
    ctx->r4 = ADD32(ctx->r4, 0X2F58);
    // 0x800B5A10: lui         $a1, 0x4348
    ctx->r5 = S32(0X4348 << 16);
    // 0x800B5A14: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x800B5A18: jal         0x8009BC2C
    // 0x800B5A1C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_5;
    // 0x800B5A1C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_5:
    // 0x800B5A20: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x800B5A24: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x800B5A28: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x800B5A2C: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800B5A30: addiu       $v1, $v1, 0x79A0
    ctx->r3 = ADD32(ctx->r3, 0X79A0);
    // 0x800B5A34: addiu       $t0, $t0, 0x79B8
    ctx->r8 = ADD32(ctx->r8, 0X79B8);
    // 0x800B5A38: addiu       $t1, $t1, 0x7978
    ctx->r9 = ADD32(ctx->r9, 0X7978);
    // 0x800B5A3C: addiu       $t2, $t2, 0x7980
    ctx->r10 = ADD32(ctx->r10, 0X7980);
L_800B5A40:
    // 0x800B5A40: lwc1        $f16, 0x0($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0X0);
L_800B5A44:
    // 0x800B5A44: lwc1        $f8, 0xAC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XAC);
    // 0x800B5A48: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800B5A4C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800B5A50: add.s       $f18, $f16, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x800B5A54: lwc1        $f16, 0x0($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0X0);
    // 0x800B5A58: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800B5A5C: addiu       $v0, $v0, 0x7988
    ctx->r2 = ADD32(ctx->r2, 0X7988);
    // 0x800B5A60: swc1        $f18, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f18.u32l;
    // 0x800B5A64: lwc1        $f4, 0xAC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XAC);
    // 0x800B5A68: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x800B5A6C: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x800B5A70: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800B5A74: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800B5A78: addiu       $a0, $s0, 0x48
    ctx->r4 = ADD32(ctx->r16, 0X48);
    // 0x800B5A7C: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    // 0x800B5A80: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
    // 0x800B5A84: lwc1        $f8, 0xB0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XB0);
    // 0x800B5A88: lwc1        $f0, 0x2F58($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X2F58);
    // 0x800B5A8C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B5A90: add.s       $f18, $f8, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x800B5A94: add.s       $f10, $f16, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800B5A98: swc1        $f10, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f10.u32l;
    // 0x800B5A9C: lwc1        $f6, 0x7D20($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x800B5AA0: lwc1        $f4, 0x138($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X138);
    // 0x800B5AA4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800B5AA8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800B5AAC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800B5AB0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B5AB4: sub.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x800B5AB8: swc1        $f18, 0x79C0($at)
    MEM_W(0X79C0, ctx->r1) = ctx->f18.u32l;
    // 0x800B5ABC: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x800B5AC0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800B5AC4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800B5AC8: add.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x800B5ACC: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x800B5AD0: lw          $t6, 0x7C70($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7C70);
    // 0x800B5AD4: bne         $t6, $at, L_800B5AEC
    if (ctx->r14 != ctx->r1) {
        // 0x800B5AD8: lui         $at, 0x4248
        ctx->r1 = S32(0X4248 << 16);
            goto L_800B5AEC;
    }
    // 0x800B5AD8: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x800B5ADC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800B5AE0: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800B5AE4: sub.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800B5AE8: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
L_800B5AEC:
    // 0x800B5AEC: lw          $t7, 0x4DC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4DC);
    // 0x800B5AF0: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x800B5AF4: beql        $t7, $zero, L_800B5B78
    if (ctx->r15 == 0) {
        // 0x800B5AF8: mtc1        $zero, $f8
        ctx->f8.u32l = 0;
            goto L_800B5B78;
    }
    goto skip_3;
    // 0x800B5AF8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    skip_3:
    // 0x800B5AFC: lwc1        $f18, 0x0($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800B5B00: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800B5B04: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B5B08: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x800B5B0C: add.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x800B5B10: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800B5B14: addiu       $a0, $s0, 0x48
    ctx->r4 = ADD32(ctx->r16, 0X48);
    // 0x800B5B18: lui         $a3, 0x4100
    ctx->r7 = S32(0X4100 << 16);
    // 0x800B5B1C: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x800B5B20: lwc1        $f8, 0xB0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XB0);
    // 0x800B5B24: lwc1        $f6, 0x78($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X78);
    // 0x800B5B28: lwc1        $f18, -0x7598($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X7598);
    // 0x800B5B2C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800B5B30: sub.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800B5B34: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x800B5B38: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x800B5B3C: mul.s       $f10, $f16, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800B5B40: jal         0x8009BC2C
    // 0x800B5B44: swc1        $f10, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_6;
    // 0x800B5B44: swc1        $f10, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f10.u32l;
    after_6:
    // 0x800B5B48: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800B5B4C: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x800B5B50: lui         $a3, 0x3D4C
    ctx->r7 = S32(0X3D4C << 16);
    // 0x800B5B54: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x800B5B58: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x800B5B5C: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x800B5B60: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x800B5B64: jal         0x8009BC2C
    // 0x800B5B68: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_7;
    // 0x800B5B68: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_7:
    // 0x800B5B6C: b           L_800B5BA4
    // 0x800B5B70: nop

        goto L_800B5BA4;
    // 0x800B5B70: nop

    // 0x800B5B74: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
L_800B5B78:
    // 0x800B5B78: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x800B5B7C: jal         0x8009BC2C
    // 0x800B5B80: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_8;
    // 0x800B5B80: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_8:
    // 0x800B5B84: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800B5B88: lui         $a3, 0x3D4C
    ctx->r7 = S32(0X3D4C << 16);
    // 0x800B5B8C: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x800B5B90: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x800B5B94: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x800B5B98: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x800B5B9C: jal         0x8009BC2C
    // 0x800B5BA0: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_9;
    // 0x800B5BA0: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_9:
L_800B5BA4:
    // 0x800B5BA4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800B5BA8: lwc1        $f18, 0x2F58($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X2F58);
    // 0x800B5BAC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800B5BB0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800B5BB4: lwc1        $f6, 0xB0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XB0);
    // 0x800B5BB8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B5BBC: mul.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x800B5BC0: lwc1        $f16, 0x79B8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X79B8);
    // 0x800B5BC4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800B5BC8: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x800B5BCC: lw          $a1, 0x7978($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7978);
    // 0x800B5BD0: addiu       $a0, $s0, 0x40
    ctx->r4 = ADD32(ctx->r16, 0X40);
    // 0x800B5BD4: lui         $a3, 0x447A
    ctx->r7 = S32(0X447A << 16);
    // 0x800B5BD8: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x800B5BDC: add.s       $f18, $f16, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x800B5BE0: swc1        $f18, 0x79B8($at)
    MEM_W(0X79B8, ctx->r1) = ctx->f18.u32l;
    // 0x800B5BE4: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x800B5BE8: jal         0x8009BC2C
    // 0x800B5BEC: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_10;
    // 0x800B5BEC: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_10:
    // 0x800B5BF0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800B5BF4: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x800B5BF8: lw          $a2, 0x18($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X18);
    // 0x800B5BFC: lw          $a1, 0x7980($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7980);
    // 0x800B5C00: addiu       $a0, $s0, 0x44
    ctx->r4 = ADD32(ctx->r16, 0X44);
    // 0x800B5C04: lui         $a3, 0x447A
    ctx->r7 = S32(0X447A << 16);
    // 0x800B5C08: jal         0x8009BC2C
    // 0x800B5C0C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_11;
    // 0x800B5C0C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_11:
    // 0x800B5C10: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800B5C14: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x800B5C18: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x800B5C1C: lw          $a1, 0x79A0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X79A0);
    // 0x800B5C20: addiu       $a0, $s0, 0x4C
    ctx->r4 = ADD32(ctx->r16, 0X4C);
    // 0x800B5C24: lui         $a3, 0x447A
    ctx->r7 = S32(0X447A << 16);
    // 0x800B5C28: jal         0x8009BC2C
    // 0x800B5C2C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_12;
    // 0x800B5C2C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_12:
    // 0x800B5C30: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800B5C34: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x800B5C38: lw          $a2, 0x18($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X18);
    // 0x800B5C3C: lw          $a1, 0x79B8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X79B8);
    // 0x800B5C40: addiu       $a0, $s0, 0x50
    ctx->r4 = ADD32(ctx->r16, 0X50);
    // 0x800B5C44: lui         $a3, 0x447A
    ctx->r7 = S32(0X447A << 16);
    // 0x800B5C48: jal         0x8009BC2C
    // 0x800B5C4C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_13;
    // 0x800B5C4C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_13:
    // 0x800B5C50: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800B5C54: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x800B5C58: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x800B5C5C: lw          $a1, 0x79C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X79C0);
    // 0x800B5C60: addiu       $a0, $s0, 0x54
    ctx->r4 = ADD32(ctx->r16, 0X54);
    // 0x800B5C64: lui         $a3, 0x447A
    ctx->r7 = S32(0X447A << 16);
    // 0x800B5C68: jal         0x8009BC2C
    // 0x800B5C6C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_14;
    // 0x800B5C6C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_14:
    // 0x800B5C70: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800B5C74: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800B5C78: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800B5C7C: lui         $a3, 0x3D4C
    ctx->r7 = S32(0X3D4C << 16);
    // 0x800B5C80: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800B5C84: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800B5C88: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x800B5C8C: addiu       $a0, $s0, 0x14
    ctx->r4 = ADD32(ctx->r16, 0X14);
    // 0x800B5C90: jal         0x8009BC2C
    // 0x800B5C94: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_15;
    // 0x800B5C94: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_15:
    // 0x800B5C98: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800B5C9C: lbu         $v0, 0x7C98($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7C98);
    // 0x800B5CA0: lwc1        $f0, 0xEC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x800B5CA4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800B5CA8: bne         $v0, $zero, L_800B5CE8
    if (ctx->r2 != 0) {
        // 0x800B5CAC: neg.s       $f0, $f0
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
            goto L_800B5CE8;
    }
    // 0x800B5CAC: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800B5CB0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B5CB4: lwc1        $f10, -0x7594($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X7594);
    // 0x800B5CB8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800B5CBC: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x800B5CC0: mul.s       $f6, $f0, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x800B5CC4: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800B5CC8: addiu       $a0, $s0, 0x34
    ctx->r4 = ADD32(ctx->r16, 0X34);
    // 0x800B5CCC: lui         $a3, 0x3FC0
    ctx->r7 = S32(0X3FC0 << 16);
    // 0x800B5CD0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x800B5CD4: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800B5CD8: jal         0x8009BC2C
    // 0x800B5CDC: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_16;
    // 0x800B5CDC: nop

    after_16:
    // 0x800B5CE0: b           L_800B5D20
    // 0x800B5CE4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800B5D20;
    // 0x800B5CE4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800B5CE8:
    // 0x800B5CE8: bne         $v0, $at, L_800B5D1C
    if (ctx->r2 != ctx->r1) {
        // 0x800B5CEC: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_800B5D1C;
    }
    // 0x800B5CEC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B5CF0: lwc1        $f16, -0x7590($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X7590);
    // 0x800B5CF4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800B5CF8: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x800B5CFC: mul.s       $f8, $f0, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x800B5D00: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800B5D04: addiu       $a0, $s0, 0x34
    ctx->r4 = ADD32(ctx->r16, 0X34);
    // 0x800B5D08: lui         $a3, 0x3FC0
    ctx->r7 = S32(0X3FC0 << 16);
    // 0x800B5D0C: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x800B5D10: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x800B5D14: jal         0x8009BC2C
    // 0x800B5D18: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_17;
    // 0x800B5D18: nop

    after_17:
L_800B5D1C:
    // 0x800B5D1C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800B5D20:
    // 0x800B5D20: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800B5D24: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800B5D28: jr          $ra
    // 0x800B5D2C: nop

    return;
    // 0x800B5D2C: nop

;}
RECOMP_FUNC void Cutscene_CoTeamFormAlongPlayer2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004E4D4: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8004E4D8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8004E4DC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8004E4E0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8004E4E4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8004E4E8: lw          $t6, -0x7D80($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7D80);
    // 0x8004E4EC: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8004E4F0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8004E4F4: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
    // 0x8004E4F8: lwc1        $f4, 0x130($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X130);
    // 0x8004E4FC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004E500: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8004E504: swc1        $f8, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->f8.u32l;
    // 0x8004E508: lwc1        $f16, 0x5A84($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X5A84);
    // 0x8004E50C: lwc1        $f10, 0x130($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X130);
    // 0x8004E510: mul.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8004E514: jal         0x80023090
    // 0x8004E518: nop

    __sinf_recomp(rdram, ctx);
        goto after_0;
    // 0x8004E518: nop

    after_0:
    // 0x8004E51C: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8004E520: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8004E524: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8004E528: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8004E52C: lwc1        $f6, 0x134($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X134);
    // 0x8004E530: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x8004E534: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004E538: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8004E53C: swc1        $f10, 0x134($s0)
    MEM_W(0X134, ctx->r16) = ctx->f10.u32l;
    // 0x8004E540: swc1        $f4, 0xFC($s0)
    MEM_W(0XFC, ctx->r16) = ctx->f4.u32l;
    // 0x8004E544: lwc1        $f18, 0x5A88($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X5A88);
    // 0x8004E548: lwc1        $f16, 0x134($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X134);
    // 0x8004E54C: mul.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8004E550: jal         0x80023090
    // 0x8004E554: nop

    __sinf_recomp(rdram, ctx);
        goto after_1;
    // 0x8004E554: nop

    after_1:
    // 0x8004E558: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8004E55C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8004E560: nop

    // 0x8004E564: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8004E568: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    // 0x8004E56C: lhu         $t7, 0xB8($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0XB8);
    // 0x8004E570: sltiu       $at, $t7, 0x21
    ctx->r1 = ctx->r15 < 0X21 ? 1 : 0;
    // 0x8004E574: beq         $at, $zero, L_8004EB30
    if (ctx->r1 == 0) {
        // 0x8004E578: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_8004EB30;
    }
    // 0x8004E578: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8004E57C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004E580: addu        $at, $at, $t7
    gpr jr_addend_8004E588 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8004E584: lw          $t7, 0x5A8C($at)
    ctx->r15 = ADD32(ctx->r1, 0X5A8C);
    // 0x8004E588: jr          $t7
    // 0x8004E58C: nop

    switch (jr_addend_8004E588 >> 2) {
        case 0: goto L_8004E590; break;
        case 1: goto L_8004E67C; break;
        case 2: goto L_8004E6D4; break;
        case 3: goto L_8004EB30; break;
        case 4: goto L_8004EB30; break;
        case 5: goto L_8004EB30; break;
        case 6: goto L_8004EB30; break;
        case 7: goto L_8004EB30; break;
        case 8: goto L_8004EB30; break;
        case 9: goto L_8004EB30; break;
        case 10: goto L_8004E74C; break;
        case 11: goto L_8004E7A0; break;
        case 12: goto L_8004EB30; break;
        case 13: goto L_8004EB30; break;
        case 14: goto L_8004EB30; break;
        case 15: goto L_8004EB30; break;
        case 16: goto L_8004EB30; break;
        case 17: goto L_8004EB30; break;
        case 18: goto L_8004EB30; break;
        case 19: goto L_8004EB30; break;
        case 20: goto L_8004EB30; break;
        case 21: goto L_8004EB30; break;
        case 22: goto L_8004EB30; break;
        case 23: goto L_8004EB30; break;
        case 24: goto L_8004EB30; break;
        case 25: goto L_8004EB30; break;
        case 26: goto L_8004EB30; break;
        case 27: goto L_8004EB30; break;
        case 28: goto L_8004EB30; break;
        case 29: goto L_8004EB30; break;
        case 30: goto L_8004E8D8; break;
        case 31: goto L_8004EA84; break;
        case 32: goto L_8004EAC8; break;
        default: switch_error(__func__, 0x8004E588, 0x800D5A8C);
    }
    // 0x8004E58C: nop

L_8004E590:
    // 0x8004E590: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8004E594: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x8004E598: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8004E59C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8004E5A0: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x8004E5A4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8004E5A8: jal         0x8009BC2C
    // 0x8004E5AC: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_2;
    // 0x8004E5AC: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x8004E5B0: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x8004E5B4: lwc1        $f8, 0x114($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X114);
    // 0x8004E5B8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8004E5BC: lwc1        $f10, 0x74($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X74);
    // 0x8004E5C0: lui         $a2, 0x3CF5
    ctx->r6 = S32(0X3CF5 << 16);
    // 0x8004E5C4: ori         $a2, $a2, 0xC28F
    ctx->r6 = ctx->r6 | 0XC28F;
    // 0x8004E5C8: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8004E5CC: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x8004E5D0: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x8004E5D4: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x8004E5D8: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8004E5DC: jal         0x8009BC2C
    // 0x8004E5E0: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_3;
    // 0x8004E5E0: nop

    after_3:
    // 0x8004E5E4: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x8004E5E8: lwc1        $f4, 0x118($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X118);
    // 0x8004E5EC: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8004E5F0: lwc1        $f6, 0x78($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X78);
    // 0x8004E5F4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8004E5F8: lui         $a2, 0x3CF5
    ctx->r6 = S32(0X3CF5 << 16);
    // 0x8004E5FC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8004E600: ori         $a2, $a2, 0xC28F
    ctx->r6 = ctx->r6 | 0XC28F;
    // 0x8004E604: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x8004E608: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x8004E60C: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8004E610: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x8004E614: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8004E618: jal         0x8009BC2C
    // 0x8004E61C: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_4;
    // 0x8004E61C: nop

    after_4:
    // 0x8004E620: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8004E624: lwc1        $f4, 0x11C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X11C);
    // 0x8004E628: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8004E62C: lwc1        $f6, 0x138($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X138);
    // 0x8004E630: lui         $a2, 0x3CF5
    ctx->r6 = S32(0X3CF5 << 16);
    // 0x8004E634: ori         $a2, $a2, 0xC28F
    ctx->r6 = ctx->r6 | 0XC28F;
    // 0x8004E638: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8004E63C: addiu       $a0, $s0, 0xC
    ctx->r4 = ADD32(ctx->r16, 0XC);
    // 0x8004E640: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x8004E644: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x8004E648: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8004E64C: jal         0x8009BC2C
    // 0x8004E650: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_5;
    // 0x8004E650: nop

    after_5:
    // 0x8004E654: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x8004E658: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8004E65C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8004E660: lwc1        $f16, 0xE4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XE4);
    // 0x8004E664: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x8004E668: swc1        $f18, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f18.u32l;
    // 0x8004E66C: lwc1        $f4, 0xE8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XE8);
    // 0x8004E670: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8004E674: b           L_8004EB30
    // 0x8004E678: swc1        $f8, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f8.u32l;
        goto L_8004EB30;
    // 0x8004E678: swc1        $f8, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f8.u32l;
L_8004E67C:
    // 0x8004E67C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8004E680: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8004E684: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8004E688: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8004E68C: addiu       $t2, $zero, 0x32
    ctx->r10 = ADD32(0, 0X32);
    // 0x8004E690: lui         $t3, 0x800C
    ctx->r11 = S32(0X800C << 16);
    // 0x8004E694: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8004E698: sh          $t1, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r9;
    // 0x8004E69C: sh          $t2, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r10;
    // 0x8004E6A0: addiu       $t3, $t3, 0x5D3C
    ctx->r11 = ADD32(ctx->r11, 0X5D3C);
    // 0x8004E6A4: lui         $a0, 0x900
    ctx->r4 = S32(0X900 << 16);
    // 0x8004E6A8: swc1        $f10, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->f10.u32l;
    // 0x8004E6AC: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x8004E6B0: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8004E6B4: ori         $a0, $a0, 0x2
    ctx->r4 = ctx->r4 | 0X2;
    // 0x8004E6B8: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x8004E6BC: jal         0x80019218
    // 0x8004E6C0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Audio_PlaySfx(rdram, ctx);
        goto after_6;
    // 0x8004E6C0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x8004E6C4: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8004E6C8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8004E6CC: nop

    // 0x8004E6D0: swc1        $f16, 0x188($s0)
    MEM_W(0X188, ctx->r16) = ctx->f16.u32l;
L_8004E6D4:
    // 0x8004E6D4: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x8004E6D8: lbu         $t4, 0x7C98($t4)
    ctx->r12 = MEM_BU(ctx->r12, 0X7C98);
    // 0x8004E6DC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004E6E0: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x8004E6E4: bne         $t4, $zero, L_8004E71C
    if (ctx->r12 != 0) {
        // 0x8004E6E8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8004E71C;
    }
    // 0x8004E6E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8004E6EC: lwc1        $f0, 0x5B10($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5B10);
    // 0x8004E6F0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004E6F4: lwc1        $f4, 0x5B14($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5B14);
    // 0x8004E6F8: lwc1        $f18, 0x168($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X168);
    // 0x8004E6FC: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8004E700: swc1        $f6, 0x168($s0)
    MEM_W(0X168, ctx->r16) = ctx->f6.u32l;
    // 0x8004E704: lwc1        $f8, 0x168($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X168);
    // 0x8004E708: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x8004E70C: nop

    // 0x8004E710: bc1fl       L_8004E720
    if (!c1cs) {
        // 0x8004E714: sw          $t5, 0x7C($s0)
        MEM_W(0X7C, ctx->r16) = ctx->r13;
            goto L_8004E720;
    }
    goto skip_0;
    // 0x8004E714: sw          $t5, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r13;
    skip_0:
    // 0x8004E718: swc1        $f0, 0x168($s0)
    MEM_W(0X168, ctx->r16) = ctx->f0.u32l;
L_8004E71C:
    // 0x8004E71C: sw          $t5, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r13;
L_8004E720:
    // 0x8004E720: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004E724: lwc1        $f16, 0x5B18($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X5B18);
    // 0x8004E728: lwc1        $f10, 0x138($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X138);
    // 0x8004E72C: lhu         $t6, 0xBC($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0XBC);
    // 0x8004E730: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8004E734: bne         $t6, $zero, L_8004EB30
    if (ctx->r14 != 0) {
        // 0x8004E738: swc1        $f18, 0x138($s0)
        MEM_W(0X138, ctx->r16) = ctx->f18.u32l;
            goto L_8004EB30;
    }
    // 0x8004E738: swc1        $f18, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->f18.u32l;
    // 0x8004E73C: jal         0x80060FBC
    // 0x8004E740: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    Object_Kill(rdram, ctx);
        goto after_7;
    // 0x8004E740: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    after_7:
    // 0x8004E744: b           L_8004EB30
    // 0x8004E748: nop

        goto L_8004EB30;
    // 0x8004E748: nop

L_8004E74C:
    // 0x8004E74C: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8004E750: addiu       $t7, $zero, 0xB
    ctx->r15 = ADD32(0, 0XB);
    // 0x8004E754: addiu       $t8, $zero, 0x96
    ctx->r24 = ADD32(0, 0X96);
    // 0x8004E758: addiu       $t9, $zero, 0x28
    ctx->r25 = ADD32(0, 0X28);
    // 0x8004E75C: lui         $t0, 0x800C
    ctx->r8 = S32(0X800C << 16);
    // 0x8004E760: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8004E764: sh          $t7, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r15;
    // 0x8004E768: sh          $t8, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r24;
    // 0x8004E76C: sh          $t9, 0xBE($s0)
    MEM_H(0XBE, ctx->r16) = ctx->r25;
    // 0x8004E770: addiu       $t0, $t0, 0x5D3C
    ctx->r8 = ADD32(ctx->r8, 0X5D3C);
    // 0x8004E774: lui         $a0, 0x900
    ctx->r4 = S32(0X900 << 16);
    // 0x8004E778: ori         $a0, $a0, 0x2
    ctx->r4 = ctx->r4 | 0X2;
    // 0x8004E77C: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8004E780: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8004E784: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x8004E788: jal         0x80019218
    // 0x8004E78C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Audio_PlaySfx(rdram, ctx);
        goto after_8;
    // 0x8004E78C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_8:
    // 0x8004E790: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8004E794: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8004E798: nop

    // 0x8004E79C: swc1        $f4, 0x188($s0)
    MEM_W(0X188, ctx->r16) = ctx->f4.u32l;
L_8004E7A0:
    // 0x8004E7A0: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8004E7A4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8004E7A8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8004E7AC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8004E7B0: lwc1        $f6, 0x138($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X138);
    // 0x8004E7B4: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x8004E7B8: sw          $v1, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r3;
    // 0x8004E7BC: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8004E7C0: swc1        $f10, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->f10.u32l;
    // 0x8004E7C4: lwc1        $f16, 0x138($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X138);
    // 0x8004E7C8: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x8004E7CC: nop

    // 0x8004E7D0: bc1fl       L_8004E7E0
    if (!c1cs) {
        // 0x8004E7D4: lhu         $t1, 0xBE($s0)
        ctx->r9 = MEM_HU(ctx->r16, 0XBE);
            goto L_8004E7E0;
    }
    goto skip_1;
    // 0x8004E7D4: lhu         $t1, 0xBE($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0XBE);
    skip_1:
    // 0x8004E7D8: swc1        $f0, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->f0.u32l;
    // 0x8004E7DC: lhu         $t1, 0xBE($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0XBE);
L_8004E7E0:
    // 0x8004E7E0: bnel        $t1, $zero, L_8004E8BC
    if (ctx->r9 != 0) {
        // 0x8004E7E4: lhu         $t2, 0xBC($s0)
        ctx->r10 = MEM_HU(ctx->r16, 0XBC);
            goto L_8004E8BC;
    }
    goto skip_2;
    // 0x8004E7E4: lhu         $t2, 0xBC($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0XBC);
    skip_2:
    // 0x8004E7E8: lw          $v0, 0x40($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X40);
    // 0x8004E7EC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8004E7F0: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x8004E7F4: beq         $v0, $at, L_8004E818
    if (ctx->r2 == ctx->r1) {
        // 0x8004E7F8: nop
    
            goto L_8004E818;
    }
    // 0x8004E7F8: nop

    // 0x8004E7FC: beq         $v0, $v1, L_8004E850
    if (ctx->r2 == ctx->r3) {
        // 0x8004E800: lui         $at, 0x800D
        ctx->r1 = S32(0X800D << 16);
            goto L_8004E850;
    }
    // 0x8004E800: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004E804: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8004E808: beq         $v0, $at, L_8004E888
    if (ctx->r2 == ctx->r1) {
        // 0x8004E80C: addiu       $a0, $s0, 0x18
        ctx->r4 = ADD32(ctx->r16, 0X18);
            goto L_8004E888;
    }
    // 0x8004E80C: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x8004E810: b           L_8004E8BC
    // 0x8004E814: lhu         $t2, 0xBC($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0XBC);
        goto L_8004E8BC;
    // 0x8004E814: lhu         $t2, 0xBC($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0XBC);
L_8004E818:
    // 0x8004E818: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004E81C: lwc1        $f4, 0x5B1C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5B1C);
    // 0x8004E820: lwc1        $f18, 0x14($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8004E824: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8004E828: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x8004E82C: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8004E830: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8004E834: lui         $a1, 0xC28C
    ctx->r5 = S32(0XC28C << 16);
    // 0x8004E838: lui         $a3, 0x4080
    ctx->r7 = S32(0X4080 << 16);
    // 0x8004E83C: swc1        $f6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f6.u32l;
    // 0x8004E840: jal         0x8009BC2C
    // 0x8004E844: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_9;
    // 0x8004E844: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_9:
    // 0x8004E848: b           L_8004E8BC
    // 0x8004E84C: lhu         $t2, 0xBC($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0XBC);
        goto L_8004E8BC;
    // 0x8004E84C: lhu         $t2, 0xBC($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0XBC);
L_8004E850:
    // 0x8004E850: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8004E854: lwc1        $f16, 0x5B20($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X5B20);
    // 0x8004E858: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8004E85C: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x8004E860: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8004E864: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8004E868: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x8004E86C: lui         $a1, 0x428C
    ctx->r5 = S32(0X428C << 16);
    // 0x8004E870: swc1        $f18, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f18.u32l;
    // 0x8004E874: lui         $a3, 0x4080
    ctx->r7 = S32(0X4080 << 16);
    // 0x8004E878: jal         0x8009BC2C
    // 0x8004E87C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_10;
    // 0x8004E87C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_10:
    // 0x8004E880: b           L_8004E8BC
    // 0x8004E884: lhu         $t2, 0xBC($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0XBC);
        goto L_8004E8BC;
    // 0x8004E884: lhu         $t2, 0xBC($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0XBC);
L_8004E888:
    // 0x8004E888: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004E88C: lwc1        $f8, 0x5B24($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5B24);
    // 0x8004E890: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8004E894: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8004E898: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x8004E89C: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8004E8A0: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8004E8A4: lui         $a1, 0x447A
    ctx->r5 = S32(0X447A << 16);
    // 0x8004E8A8: lui         $a3, 0x40C0
    ctx->r7 = S32(0X40C0 << 16);
    // 0x8004E8AC: swc1        $f10, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f10.u32l;
    // 0x8004E8B0: jal         0x8009BC2C
    // 0x8004E8B4: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_11;
    // 0x8004E8B4: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_11:
    // 0x8004E8B8: lhu         $t2, 0xBC($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0XBC);
L_8004E8BC:
    // 0x8004E8BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8004E8C0: bne         $t2, $zero, L_8004EB30
    if (ctx->r10 != 0) {
        // 0x8004E8C4: nop
    
            goto L_8004EB30;
    }
    // 0x8004E8C4: nop

    // 0x8004E8C8: jal         0x80060FBC
    // 0x8004E8CC: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    Object_Kill(rdram, ctx);
        goto after_12;
    // 0x8004E8CC: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    after_12:
    // 0x8004E8D0: b           L_8004EB30
    // 0x8004E8D4: nop

        goto L_8004EB30;
    // 0x8004E8D4: nop

L_8004E8D8:
    // 0x8004E8D8: lw          $t3, 0x40($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X40);
    // 0x8004E8DC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004E8E0: lwc1        $f18, 0x120($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X120);
    // 0x8004E8E4: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8004E8E8: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x8004E8EC: lwc1        $f4, -0x5F68($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X5F68);
    // 0x8004E8F0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004E8F4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8004E8F8: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8004E8FC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8004E900: swc1        $f6, 0x120($s0)
    MEM_W(0X120, ctx->r16) = ctx->f6.u32l;
    // 0x8004E904: lwc1        $f10, 0x5B28($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X5B28);
    // 0x8004E908: lwc1        $f8, 0x120($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X120);
    // 0x8004E90C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8004E910: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8004E914: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8004E918: jal         0x80005E90
    // 0x8004E91C: nop

    Matrix_RotateY(rdram, ctx);
        goto after_13;
    // 0x8004E91C: nop

    after_13:
    // 0x8004E920: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8004E924: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004E928: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8004E92C: swc1        $f18, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f18.u32l;
    // 0x8004E930: lw          $t5, 0x40($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X40);
    // 0x8004E934: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8004E938: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x8004E93C: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8004E940: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8004E944: lwc1        $f4, -0x5F5C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X5F5C);
    // 0x8004E948: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004E94C: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    // 0x8004E950: swc1        $f4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f4.u32l;
    // 0x8004E954: lw          $t7, 0x40($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X40);
    // 0x8004E958: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8004E95C: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8004E960: lwc1        $f6, -0x5F50($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X5F50);
    // 0x8004E964: jal         0x80006970
    // 0x8004E968: swc1        $f6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f6.u32l;
    Matrix_MultVec3f(rdram, ctx);
        goto after_14;
    // 0x8004E968: swc1        $f6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f6.u32l;
    after_14:
    // 0x8004E96C: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8004E970: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8004E974: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8004E978: swc1        $f8, 0x114($s0)
    MEM_W(0X114, ctx->r16) = ctx->f8.u32l;
    // 0x8004E97C: lwc1        $f10, 0x40($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8004E980: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004E984: lwc1        $f6, 0x120($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X120);
    // 0x8004E988: swc1        $f10, 0x118($s0)
    MEM_W(0X118, ctx->r16) = ctx->f10.u32l;
    // 0x8004E98C: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8004E990: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8004E994: swc1        $f4, 0x11C($s0)
    MEM_W(0X11C, ctx->r16) = ctx->f4.u32l;
    // 0x8004E998: lwc1        $f8, 0x5B2C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5B2C);
    // 0x8004E99C: mul.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8004E9A0: jal         0x80023090
    // 0x8004E9A4: nop

    __sinf_recomp(rdram, ctx);
        goto after_15;
    // 0x8004E9A4: nop

    after_15:
    // 0x8004E9A8: lui         $at, 0xC1F0
    ctx->r1 = S32(0XC1F0 << 16);
    // 0x8004E9AC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8004E9B0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8004E9B4: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8004E9B8: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8004E9BC: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8004E9C0: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x8004E9C4: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x8004E9C8: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x8004E9CC: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8004E9D0: jal         0x8009BC2C
    // 0x8004E9D4: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_16;
    // 0x8004E9D4: nop

    after_16:
    // 0x8004E9D8: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x8004E9DC: lwc1        $f4, 0x114($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X114);
    // 0x8004E9E0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8004E9E4: lwc1        $f6, 0x74($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X74);
    // 0x8004E9E8: lui         $a2, 0x3CF5
    ctx->r6 = S32(0X3CF5 << 16);
    // 0x8004E9EC: ori         $a2, $a2, 0xC28F
    ctx->r6 = ctx->r6 | 0XC28F;
    // 0x8004E9F0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8004E9F4: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x8004E9F8: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x8004E9FC: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x8004EA00: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8004EA04: jal         0x8009BC2C
    // 0x8004EA08: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_17;
    // 0x8004EA08: nop

    after_17:
    // 0x8004EA0C: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8004EA10: lwc1        $f16, 0x118($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X118);
    // 0x8004EA14: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8004EA18: lwc1        $f18, 0x78($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X78);
    // 0x8004EA1C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8004EA20: lui         $a2, 0x3CF5
    ctx->r6 = S32(0X3CF5 << 16);
    // 0x8004EA24: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8004EA28: ori         $a2, $a2, 0xC28F
    ctx->r6 = ctx->r6 | 0XC28F;
    // 0x8004EA2C: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x8004EA30: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x8004EA34: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8004EA38: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x8004EA3C: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8004EA40: jal         0x8009BC2C
    // 0x8004EA44: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_18;
    // 0x8004EA44: nop

    after_18:
    // 0x8004EA48: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x8004EA4C: lwc1        $f16, 0x11C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X11C);
    // 0x8004EA50: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8004EA54: lwc1        $f18, 0x138($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0X138);
    // 0x8004EA58: lui         $a2, 0x3CF5
    ctx->r6 = S32(0X3CF5 << 16);
    // 0x8004EA5C: ori         $a2, $a2, 0xC28F
    ctx->r6 = ctx->r6 | 0XC28F;
    // 0x8004EA60: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8004EA64: addiu       $a0, $s0, 0xC
    ctx->r4 = ADD32(ctx->r16, 0XC);
    // 0x8004EA68: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x8004EA6C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x8004EA70: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8004EA74: jal         0x8009BC2C
    // 0x8004EA78: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_19;
    // 0x8004EA78: nop

    after_19:
    // 0x8004EA7C: b           L_8004EB30
    // 0x8004EA80: nop

        goto L_8004EB30;
    // 0x8004EA80: nop

L_8004EA84:
    // 0x8004EA84: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8004EA88: lui         $t2, 0x800C
    ctx->r10 = S32(0X800C << 16);
    // 0x8004EA8C: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8004EA90: addiu       $t2, $t2, 0x5D3C
    ctx->r10 = ADD32(ctx->r10, 0X5D3C);
    // 0x8004EA94: lui         $a0, 0x900
    ctx->r4 = S32(0X900 << 16);
    // 0x8004EA98: ori         $a0, $a0, 0x2
    ctx->r4 = ctx->r4 | 0X2;
    // 0x8004EA9C: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8004EAA0: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8004EAA4: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x8004EAA8: jal         0x80019218
    // 0x8004EAAC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Audio_PlaySfx(rdram, ctx);
        goto after_20;
    // 0x8004EAAC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_20:
    // 0x8004EAB0: lh          $t3, 0xB8($s0)
    ctx->r11 = MEM_H(ctx->r16, 0XB8);
    // 0x8004EAB4: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8004EAB8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8004EABC: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8004EAC0: sh          $t4, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r12;
    // 0x8004EAC4: swc1        $f8, 0x188($s0)
    MEM_W(0X188, ctx->r16) = ctx->f8.u32l;
L_8004EAC8:
    // 0x8004EAC8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8004EACC: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x8004EAD0: sw          $t5, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r13;
    // 0x8004EAD4: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8004EAD8: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8004EADC: addiu       $a0, $s0, 0x10
    ctx->r4 = ADD32(ctx->r16, 0X10);
    // 0x8004EAE0: lui         $a1, 0xC1A0
    ctx->r5 = S32(0XC1A0 << 16);
    // 0x8004EAE4: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    // 0x8004EAE8: jal         0x8009BC2C
    // 0x8004EAEC: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_21;
    // 0x8004EAEC: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_21:
    // 0x8004EAF0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8004EAF4: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8004EAF8: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8004EAFC: addiu       $a0, $s0, 0x138
    ctx->r4 = ADD32(ctx->r16, 0X138);
    // 0x8004EB00: lui         $a1, 0x41C8
    ctx->r5 = S32(0X41C8 << 16);
    // 0x8004EB04: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x8004EB08: jal         0x8009BC2C
    // 0x8004EB0C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_22;
    // 0x8004EB0C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_22:
    // 0x8004EB10: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8004EB14: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8004EB18: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8004EB1C: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x8004EB20: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x8004EB24: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    // 0x8004EB28: jal         0x8009BC2C
    // 0x8004EB2C: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_23;
    // 0x8004EB2C: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    after_23:
L_8004EB30:
    // 0x8004EB30: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004EB34: lwc1        $f4, 0x5B30($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5B30);
    // 0x8004EB38: lwc1        $f18, 0x14($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8004EB3C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8004EB40: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8004EB44: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8004EB48: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8004EB4C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8004EB50: jal         0x80005E90
    // 0x8004EB54: nop

    Matrix_RotateY(rdram, ctx);
        goto after_24;
    // 0x8004EB54: nop

    after_24:
    // 0x8004EB58: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004EB5C: lwc1        $f10, 0x5B34($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X5B34);
    // 0x8004EB60: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8004EB64: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8004EB68: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8004EB6C: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8004EB70: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8004EB74: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8004EB78: jal         0x80005D44
    // 0x8004EB7C: nop

    Matrix_RotateX(rdram, ctx);
        goto after_25;
    // 0x8004EB7C: nop

    after_25:
    // 0x8004EB80: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8004EB84: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8004EB88: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8004EB8C: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    // 0x8004EB90: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    // 0x8004EB94: lwc1        $f18, 0x138($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X138);
    // 0x8004EB98: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x8004EB9C: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    // 0x8004EBA0: jal         0x80006A20
    // 0x8004EBA4: swc1        $f18, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f18.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_26;
    // 0x8004EBA4: swc1        $f18, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f18.u32l;
    after_26:
    // 0x8004EBA8: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8004EBAC: swc1        $f4, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f4.u32l;
    // 0x8004EBB0: lwc1        $f6, 0x4C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8004EBB4: swc1        $f6, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f6.u32l;
    // 0x8004EBB8: lwc1        $f8, 0x50($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8004EBBC: swc1        $f8, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f8.u32l;
    // 0x8004EBC0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8004EBC4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8004EBC8: jr          $ra
    // 0x8004EBCC: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8004EBCC: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void Effect_Effect345_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007E258: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007E25C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007E260: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x8007E264: lw          $t6, 0x78A8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X78A8);
    // 0x8007E268: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8007E26C: beql        $t6, $at, L_8007E28C
    if (ctx->r14 == ctx->r1) {
        // 0x8007E270: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8007E28C;
    }
    goto skip_0;
    // 0x8007E270: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8007E274: lhu         $t7, 0x50($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X50);
    // 0x8007E278: bnel        $t7, $zero, L_8007E28C
    if (ctx->r15 != 0) {
        // 0x8007E27C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8007E28C;
    }
    goto skip_1;
    // 0x8007E27C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8007E280: jal         0x80060FBC
    // 0x8007E284: addiu       $a1, $a0, 0x80
    ctx->r5 = ADD32(ctx->r4, 0X80);
    Object_Kill(rdram, ctx);
        goto after_0;
    // 0x8007E284: addiu       $a1, $a0, 0x80
    ctx->r5 = ADD32(ctx->r4, 0X80);
    after_0:
    // 0x8007E288: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8007E28C:
    // 0x8007E28C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007E290: jr          $ra
    // 0x8007E294: nop

    return;
    // 0x8007E294: nop

;}
RECOMP_FUNC void func_enmy_80062568(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062568: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8006256C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80062570: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x80062574: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x80062578: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8006257C: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x80062580: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80062584: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80062588: lw          $a0, -0x7DCC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7DCC);
    // 0x8006258C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80062590: lui         $s2, 0x8017
    ctx->r18 = S32(0X8017 << 16);
    // 0x80062594: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80062598: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x8006259C: lw          $v0, -0x260($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X260);
    // 0x800625A0: addiu       $s2, $s2, 0x7CA0
    ctx->r18 = ADD32(ctx->r18, 0X7CA0);
    // 0x800625A4: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800625A8: sll         $t8, $v0, 4
    ctx->r24 = S32(ctx->r2 << 4);
    // 0x800625AC: srl         $t9, $t8, 28
    ctx->r25 = S32(U32(ctx->r24) >> 28);
    // 0x800625B0: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800625B4: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x800625B8: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x800625BC: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x800625C0: lw          $t1, 0x1FD0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X1FD0);
    // 0x800625C4: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800625C8: and         $t7, $v0, $at
    ctx->r15 = ctx->r2 & ctx->r1;
    // 0x800625CC: addiu       $s0, $v1, -0x28
    ctx->r16 = ADD32(ctx->r3, -0X28);
    // 0x800625D0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800625D4: sll         $t4, $s0, 2
    ctx->r12 = S32(ctx->r16 << 2);
    // 0x800625D8: addu        $t2, $t7, $t1
    ctx->r10 = ADD32(ctx->r15, ctx->r9);
    // 0x800625DC: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800625E0: addu        $t3, $t2, $at
    ctx->r11 = ADD32(ctx->r10, ctx->r1);
    // 0x800625E4: addu        $t4, $t4, $s0
    ctx->r12 = ADD32(ctx->r12, ctx->r16);
    // 0x800625E8: addiu       $a1, $a1, -0x7CF0
    ctx->r5 = ADD32(ctx->r5, -0X7CF0);
    // 0x800625EC: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800625F0: slt         $at, $s0, $v1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800625F4: sw          $t3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r11;
    // 0x800625F8: beq         $at, $zero, L_80062644
    if (ctx->r1 == 0) {
        // 0x800625FC: addu        $s1, $t4, $t3
        ctx->r17 = ADD32(ctx->r12, ctx->r11);
            goto L_80062644;
    }
    // 0x800625FC: addu        $s1, $t4, $t3
    ctx->r17 = ADD32(ctx->r12, ctx->r11);
    // 0x80062600: lui         $at, 0xC57A
    ctx->r1 = S32(0XC57A << 16);
    // 0x80062604: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80062608: lui         $at, 0x457A
    ctx->r1 = S32(0X457A << 16);
    // 0x8006260C: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80062610: nop

    // 0x80062614: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
L_80062618:
    // 0x80062618: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x8006261C: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80062620: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80062624: jal         0x80062180
    // 0x80062628: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    Object_Load(rdram, ctx);
        goto after_0;
    // 0x80062628: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    after_0:
    // 0x8006262C: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x80062630: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80062634: addiu       $s1, $s1, 0x14
    ctx->r17 = ADD32(ctx->r17, 0X14);
    // 0x80062638: slt         $at, $s0, $t6
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8006263C: bnel        $at, $zero, L_80062618
    if (ctx->r1 != 0) {
        // 0x80062640: mfc1        $a1, $f20
        ctx->r5 = (int32_t)ctx->f20.u32l;
            goto L_80062618;
    }
    goto skip_0;
    // 0x80062640: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    skip_0:
L_80062644:
    // 0x80062644: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80062648: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8006264C: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x80062650: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80062654: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x80062658: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x8006265C: jr          $ra
    // 0x80062660: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80062660: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void Effect_Effect359_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007A994: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8007A998: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8007A99C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8007A9A0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8007A9A4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007A9A8: lwc1        $f4, 0x73B0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X73B0);
    // 0x8007A9AC: lw          $a1, 0x6C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X6C);
    // 0x8007A9B0: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8007A9B4: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8007A9B8: addiu       $a0, $s0, 0x70
    ctx->r4 = ADD32(ctx->r16, 0X70);
    // 0x8007A9BC: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x8007A9C0: jal         0x8009BC2C
    // 0x8007A9C4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_0;
    // 0x8007A9C4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x8007A9C8: lwc1        $f6, 0x18($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8007A9CC: lwc1        $f8, 0x68($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X68);
    // 0x8007A9D0: lwc1        $f16, 0x58($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X58);
    // 0x8007A9D4: lwc1        $f18, 0x64($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X64);
    // 0x8007A9D8: lh          $t6, 0x4A($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X4A);
    // 0x8007A9DC: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8007A9E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8007A9E4: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x8007A9E8: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8007A9EC: swc1        $f10, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f10.u32l;
    // 0x8007A9F0: beq         $t7, $zero, L_8007AA1C
    if (ctx->r15 == 0) {
        // 0x8007A9F4: swc1        $f4, 0x58($s0)
        MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
            goto L_8007AA1C;
    }
    // 0x8007A9F4: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    // 0x8007A9F8: lh          $t8, 0x48($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X48);
    // 0x8007A9FC: addiu       $t1, $zero, 0x5
    ctx->r9 = ADD32(0, 0X5);
    // 0x8007AA00: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8007AA04: sh          $t9, 0x48($s0)
    MEM_H(0X48, ctx->r16) = ctx->r25;
    // 0x8007AA08: lh          $t0, 0x48($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X48);
    // 0x8007AA0C: slti        $at, $t0, 0x6
    ctx->r1 = SIGNED(ctx->r8) < 0X6 ? 1 : 0;
    // 0x8007AA10: bnel        $at, $zero, L_8007AA20
    if (ctx->r1 != 0) {
        // 0x8007AA14: lh          $t2, 0x44($s0)
        ctx->r10 = MEM_H(ctx->r16, 0X44);
            goto L_8007AA20;
    }
    goto skip_0;
    // 0x8007AA14: lh          $t2, 0x44($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X44);
    skip_0:
    // 0x8007AA18: sh          $t1, 0x48($s0)
    MEM_H(0X48, ctx->r16) = ctx->r9;
L_8007AA1C:
    // 0x8007AA1C: lh          $t2, 0x44($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X44);
L_8007AA20:
    // 0x8007AA20: lh          $t3, 0x46($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X46);
    // 0x8007AA24: subu        $t4, $t2, $t3
    ctx->r12 = SUB32(ctx->r10, ctx->r11);
    // 0x8007AA28: sh          $t4, 0x44($s0)
    MEM_H(0X44, ctx->r16) = ctx->r12;
    // 0x8007AA2C: lh          $t5, 0x44($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X44);
    // 0x8007AA30: slti        $at, $t5, 0x15
    ctx->r1 = SIGNED(ctx->r13) < 0X15 ? 1 : 0;
    // 0x8007AA34: beql        $at, $zero, L_8007AA48
    if (ctx->r1 == 0) {
        // 0x8007AA38: lh          $t6, 0x4A($s0)
        ctx->r14 = MEM_H(ctx->r16, 0X4A);
            goto L_8007AA48;
    }
    goto skip_1;
    // 0x8007AA38: lh          $t6, 0x4A($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X4A);
    skip_1:
    // 0x8007AA3C: jal         0x80060FBC
    // 0x8007AA40: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    Object_Kill(rdram, ctx);
        goto after_1;
    // 0x8007AA40: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    after_1:
    // 0x8007AA44: lh          $t6, 0x4A($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X4A);
L_8007AA48:
    // 0x8007AA48: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8007AA4C: sh          $t7, 0x4A($s0)
    MEM_H(0X4A, ctx->r16) = ctx->r15;
    // 0x8007AA50: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8007AA54: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8007AA58: jr          $ra
    // 0x8007AA5C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8007AA5C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void AudioSeq_SequencePlayerDisable(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800144E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800144E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800144EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800144F0: jal         0x80014370
    // 0x800144F4: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    AudioSeq_SequencePlayerDisableChannels(rdram, ctx);
        goto after_0;
    // 0x800144F4: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    after_0:
    // 0x800144F8: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x800144FC: jal         0x80012964
    // 0x80014500: addiu       $a0, $a2, 0x98
    ctx->r4 = ADD32(ctx->r6, 0X98);
    Audio_NotePoolClear(rdram, ctx);
        goto after_1;
    // 0x80014500: addiu       $a0, $a2, 0x98
    ctx->r4 = ADD32(ctx->r6, 0X98);
    after_1:
    // 0x80014504: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80014508: lui         $t2, 0x8015
    ctx->r10 = S32(0X8015 << 16);
    // 0x8001450C: addiu       $t2, $t2, -0x2BD8
    ctx->r10 = ADD32(ctx->r10, -0X2BD8);
    // 0x80014510: lbu         $t7, 0x0($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X0);
    // 0x80014514: lbu         $t1, 0x4($a2)
    ctx->r9 = MEM_BU(ctx->r6, 0X4);
    // 0x80014518: ori         $t9, $t7, 0x40
    ctx->r25 = ctx->r15 | 0X40;
    // 0x8001451C: andi        $t0, $t9, 0x7F
    ctx->r8 = ctx->r25 & 0X7F;
    // 0x80014520: sb          $t9, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r25;
    // 0x80014524: sb          $t0, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r8;
    // 0x80014528: addu        $v0, $t1, $t2
    ctx->r2 = ADD32(ctx->r9, ctx->r10);
    // 0x8001452C: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x80014530: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80014534: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x80014538: bne         $at, $zero, L_8001454C
    if (ctx->r1 != 0) {
        // 0x8001453C: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_8001454C;
    }
    // 0x8001453C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80014540: beq         $v1, $at, L_8001454C
    if (ctx->r3 == ctx->r1) {
        // 0x80014544: addiu       $t3, $zero, 0x3
        ctx->r11 = ADD32(0, 0X3);
            goto L_8001454C;
    }
    // 0x80014544: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x80014548: sb          $t3, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r11;
L_8001454C:
    // 0x8001454C: lbu         $v0, 0x5($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X5);
    // 0x80014550: lui         $t4, 0x8015
    ctx->r12 = S32(0X8015 << 16);
    // 0x80014554: addiu       $t4, $t4, -0x2C18
    ctx->r12 = ADD32(ctx->r12, -0X2C18);
    // 0x80014558: addu        $v1, $v0, $t4
    ctx->r3 = ADD32(ctx->r2, ctx->r12);
    // 0x8001455C: lbu         $a0, 0x0($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X0);
    // 0x80014560: slti        $at, $a0, 0x2
    ctx->r1 = SIGNED(ctx->r4) < 0X2 ? 1 : 0;
    // 0x80014564: bne         $at, $zero, L_8001457C
    if (ctx->r1 != 0) {
        // 0x80014568: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_8001457C;
    }
    // 0x80014568: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8001456C: beq         $a0, $at, L_8001457C
    if (ctx->r4 == ctx->r1) {
        // 0x80014570: addiu       $t5, $zero, 0x4
        ctx->r13 = ADD32(0, 0X4);
            goto L_8001457C;
    }
    // 0x80014570: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x80014574: sb          $t5, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r13;
    // 0x80014578: lbu         $v0, 0x5($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X5);
L_8001457C:
    // 0x8001457C: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x80014580: addiu       $a0, $a0, -0x3BF0
    ctx->r4 = ADD32(ctx->r4, -0X3BF0);
    // 0x80014584: lh          $t6, 0x1B2($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X1B2);
    // 0x80014588: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8001458C: bnel        $v0, $t6, L_800145A0
    if (ctx->r2 != ctx->r14) {
        // 0x80014590: lh          $t8, 0x1BE($a0)
        ctx->r24 = MEM_H(ctx->r4, 0X1BE);
            goto L_800145A0;
    }
    goto skip_0;
    // 0x80014590: lh          $t8, 0x1BE($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X1BE);
    skip_0:
    // 0x80014594: b           L_800145AC
    // 0x80014598: sw          $t7, 0x194($a0)
    MEM_W(0X194, ctx->r4) = ctx->r15;
        goto L_800145AC;
    // 0x80014598: sw          $t7, 0x194($a0)
    MEM_W(0X194, ctx->r4) = ctx->r15;
    // 0x8001459C: lh          $t8, 0x1BE($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X1BE);
L_800145A0:
    // 0x800145A0: bnel        $v1, $t8, L_800145B0
    if (ctx->r3 != ctx->r24) {
        // 0x800145A4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800145B0;
    }
    goto skip_1;
    // 0x800145A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x800145A8: sw          $zero, 0x194($a0)
    MEM_W(0X194, ctx->r4) = 0;
L_800145AC:
    // 0x800145AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800145B0:
    // 0x800145B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800145B4: jr          $ra
    // 0x800145B8: nop

    return;
    // 0x800145B8: nop

;}
