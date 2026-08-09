#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void MeMora_DrawParts(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B46C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8006B470: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8006B474: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x8006B478: addiu       $s0, $s0, -0x4C40
    ctx->r16 = ADD32(ctx->r16, -0X4C40);
    // 0x8006B47C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8006B480: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8006B484: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x8006B488: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x8006B48C: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x8006B490: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x8006B494: addiu       $t7, $t7, 0x10
    ctx->r15 = ADD32(ctx->r15, 0X10);
    // 0x8006B498: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x8006B49C: addiu       $t6, $sp, 0x34
    ctx->r14 = ADD32(ctx->r29, 0X34);
    // 0x8006B4A0: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x8006B4A4: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x8006B4A8: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x8006B4AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8006B4B0: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x8006B4B4: jal         0x80005708
    // 0x8006B4B8: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    Matrix_Push(rdram, ctx);
        goto after_0;
    // 0x8006B4B8: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    after_0:
    // 0x8006B4BC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8006B4C0: lwc1        $f6, 0x7D20($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x8006B4C4: lwc1        $f4, 0x4C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8006B4C8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8006B4CC: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8006B4D0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8006B4D4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8006B4D8: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x8006B4DC: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x8006B4E0: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x8006B4E4: jal         0x80005B00
    // 0x8006B4E8: nop

    Matrix_Translate(rdram, ctx);
        goto after_1;
    // 0x8006B4E8: nop

    after_1:
    // 0x8006B4EC: lbu         $t2, 0x5F($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X5F);
    // 0x8006B4F0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8006B4F4: lwc1        $f16, 0x54($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8006B4F8: beq         $t2, $at, L_8006B568
    if (ctx->r10 == ctx->r1) {
        // 0x8006B4FC: sw          $t2, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r10;
            goto L_8006B568;
    }
    // 0x8006B4FC: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x8006B500: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006B504: lwc1        $f10, 0x6A84($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6A84);
    // 0x8006B508: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8006B50C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8006B510: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8006B514: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8006B518: jal         0x80005E90
    // 0x8006B51C: nop

    Matrix_RotateY(rdram, ctx);
        goto after_2;
    // 0x8006B51C: nop

    after_2:
    // 0x8006B520: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006B524: lwc1        $f4, 0x6A88($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6A88);
    // 0x8006B528: lwc1        $f6, 0x50($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8006B52C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8006B530: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8006B534: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8006B538: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8006B53C: jal         0x80005D44
    // 0x8006B540: nop

    Matrix_RotateX(rdram, ctx);
        goto after_3;
    // 0x8006B540: nop

    after_3:
    // 0x8006B544: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006B548: lwc1        $f10, 0x6A8C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6A8C);
    // 0x8006B54C: lwc1        $f16, 0x58($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8006B550: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8006B554: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8006B558: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8006B55C: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8006B560: jal         0x80005FE0
    // 0x8006B564: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_4;
    // 0x8006B564: nop

    after_4:
L_8006B568:
    // 0x8006B568: lwc1        $f0, 0x60($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8006B56C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8006B570: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8006B574: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8006B578: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8006B57C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8006B580: jal         0x80005C34
    // 0x8006B584: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_5;
    // 0x8006B584: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_5:
    // 0x8006B588: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8006B58C: jal         0x80006EB8
    // 0x8006B590: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_6;
    // 0x8006B590: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    after_6:
    // 0x8006B594: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8006B598: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8006B59C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8006B5A0: beq         $t4, $at, L_8006B650
    if (ctx->r12 == ctx->r1) {
        // 0x8006B5A4: lui         $a1, 0x8018
        ctx->r5 = S32(0X8018 << 16);
            goto L_8006B650;
    }
    // 0x8006B5A4: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8006B5A8: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8006B5AC: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8006B5B0: lw          $t9, -0x7C24($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7C24);
    // 0x8006B5B4: lw          $t5, -0x7C28($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X7C28);
    // 0x8006B5B8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8006B5BC: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8006B5C0: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x8006B5C4: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x8006B5C8: lw          $a3, -0x7CC8($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X7CC8);
    // 0x8006B5CC: lw          $a2, -0x7CD0($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7CD0);
    // 0x8006B5D0: lw          $a1, -0x7CD8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7CD8);
    // 0x8006B5D4: lw          $a0, -0x7CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7CE0);
    // 0x8006B5D8: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8006B5DC: jal         0x800BA1D0
    // 0x8006B5E0: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    RCP_SetupDL_29(rdram, ctx);
        goto after_7;
    // 0x8006B5E0: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_7:
    // 0x8006B5E4: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8006B5E8: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
    // 0x8006B5EC: bnel        $t8, $zero, L_8006B688
    if (ctx->r24 != 0) {
        // 0x8006B5F0: lw          $t2, 0x64($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X64);
            goto L_8006B688;
    }
    goto skip_0;
    // 0x8006B5F0: lw          $t2, 0x64($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X64);
    skip_0:
    // 0x8006B5F4: lbu         $t6, 0xCA($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0XCA);
    // 0x8006B5F8: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8006B5FC: beql        $t6, $zero, L_8006B688
    if (ctx->r14 == 0) {
        // 0x8006B600: lw          $t2, 0x64($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X64);
            goto L_8006B688;
    }
    goto skip_1;
    // 0x8006B600: lw          $t2, 0x64($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X64);
    skip_1:
    // 0x8006B604: lwc1        $f6, 0x38($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X38);
    // 0x8006B608: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x8006B60C: addiu       $a2, $a2, 0x1578
    ctx->r6 = ADD32(ctx->r6, 0X1578);
    // 0x8006B610: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8006B614: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8006B618: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x8006B61C: jal         0x80006970
    // 0x8006B620: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    Matrix_MultVec3f(rdram, ctx);
        goto after_8;
    // 0x8006B620: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    after_8:
    // 0x8006B624: lui         $at, 0xC3FA
    ctx->r1 = S32(0XC3FA << 16);
    // 0x8006B628: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8006B62C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8006B630: lwc1        $f16, 0x1580($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X1580);
    // 0x8006B634: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x8006B638: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x8006B63C: nop

    // 0x8006B640: bc1fl       L_8006B688
    if (!c1cs) {
        // 0x8006B644: lw          $t2, 0x64($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X64);
            goto L_8006B688;
    }
    goto skip_2;
    // 0x8006B644: lw          $t2, 0x64($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X64);
    skip_2:
    // 0x8006B648: b           L_8006B684
    // 0x8006B64C: sb          $zero, 0xCA($t7)
    MEM_B(0XCA, ctx->r15) = 0;
        goto L_8006B684;
    // 0x8006B64C: sb          $zero, 0xCA($t7)
    MEM_B(0XCA, ctx->r15) = 0;
L_8006B650:
    // 0x8006B650: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8006B654: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8006B658: lw          $t1, -0x7C24($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X7C24);
    // 0x8006B65C: lw          $t0, -0x7C28($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7C28);
    // 0x8006B660: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x8006B664: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x8006B668: lw          $a3, -0x7CC8($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X7CC8);
    // 0x8006B66C: lw          $a2, -0x7CD0($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7CD0);
    // 0x8006B670: lw          $a0, -0x7CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7CE0);
    // 0x8006B674: lw          $a1, -0x7CD8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7CD8);
    // 0x8006B678: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x8006B67C: jal         0x800B9B38
    // 0x8006B680: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    RCP_SetupDL_60(rdram, ctx);
        goto after_9;
    // 0x8006B680: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_9:
L_8006B684:
    // 0x8006B684: lw          $t2, 0x64($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X64);
L_8006B688:
    // 0x8006B688: beq         $t2, $zero, L_8006B6C0
    if (ctx->r10 == 0) {
        // 0x8006B68C: nop
    
            goto L_8006B6C0;
    }
    // 0x8006B68C: nop

    // 0x8006B690: jal         0x800BA140
    // 0x8006B694: nop

    RCP_SetupDL_64(rdram, ctx);
        goto after_10;
    // 0x8006B694: nop

    after_10:
    // 0x8006B698: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8006B69C: addiu       $a1, $a1, 0x7E64
    ctx->r5 = ADD32(ctx->r5, 0X7E64);
    // 0x8006B6A0: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8006B6A4: lui         $t5, 0xFF00
    ctx->r13 = S32(0XFF00 << 16);
    // 0x8006B6A8: ori         $t5, $t5, 0xFF
    ctx->r13 = ctx->r13 | 0XFF;
    // 0x8006B6AC: addiu       $t3, $v1, 0x8
    ctx->r11 = ADD32(ctx->r3, 0X8);
    // 0x8006B6B0: sw          $t3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r11;
    // 0x8006B6B4: lui         $t4, 0xFA00
    ctx->r12 = S32(0XFA00 << 16);
    // 0x8006B6B8: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x8006B6BC: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
L_8006B6C0:
    // 0x8006B6C0: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8006B6C4: addiu       $a1, $a1, 0x7E64
    ctx->r5 = ADD32(ctx->r5, 0X7E64);
    // 0x8006B6C8: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8006B6CC: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x8006B6D0: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x8006B6D4: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8006B6D8: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x8006B6DC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8006B6E0: lbu         $t6, 0x5F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X5F);
    // 0x8006B6E4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8006B6E8: addu        $t0, $t0, $t7
    ctx->r8 = ADD32(ctx->r8, ctx->r15);
    // 0x8006B6EC: lw          $t0, 0x4($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X4);
    // 0x8006B6F0: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x8006B6F4: jal         0x80005740
    // 0x8006B6F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_11;
    // 0x8006B6F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x8006B6FC: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8006B700: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8006B704: lw          $t2, -0x7C24($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X7C24);
    // 0x8006B708: lw          $t1, -0x7C28($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X7C28);
    // 0x8006B70C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8006B710: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8006B714: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x8006B718: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x8006B71C: lw          $a3, -0x7CC8($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X7CC8);
    // 0x8006B720: lw          $a2, -0x7CD0($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7CD0);
    // 0x8006B724: lw          $a1, -0x7CD8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7CD8);
    // 0x8006B728: lw          $a0, -0x7CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7CE0);
    // 0x8006B72C: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8006B730: jal         0x800BA1D0
    // 0x8006B734: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    RCP_SetupDL_29(rdram, ctx);
        goto after_12;
    // 0x8006B734: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_12:
    // 0x8006B738: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8006B73C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8006B740: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8006B744: jr          $ra
    // 0x8006B748: nop

    return;
    // 0x8006B748: nop

;}
RECOMP_FUNC void func_versus_800BD164(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BD164: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800BD168: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800BD16C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800BD170: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800BD174: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BD178: lui         $a1, 0x700
    ctx->r5 = S32(0X700 << 16);
    // 0x800BD17C: addiu       $a1, $a1, 0x3C70
    ctx->r5 = ADD32(ctx->r5, 0X3C70);
    // 0x800BD180: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x800BD184: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x800BD188: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x800BD18C: swc1        $f12, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f12.u32l;
    // 0x800BD190: swc1        $f14, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f14.u32l;
    // 0x800BD194: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x800BD198: jal         0x8009D994
    // 0x800BD19C: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_0;
    // 0x800BD19C: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x800BD1A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800BD1A4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800BD1A8: jr          $ra
    // 0x800BD1AC: nop

    return;
    // 0x800BD1AC: nop

;}
RECOMP_FUNC void RCP_SetupDL_66(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B9D68: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800B9D6C: addiu       $t3, $t3, 0x7E64
    ctx->r11 = ADD32(ctx->r11, 0X7E64);
    // 0x800B9D70: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x800B9D74: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x800B9D78: addiu       $t8, $t8, 0x4440
    ctx->r24 = ADD32(ctx->r24, 0X4440);
    // 0x800B9D7C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800B9D80: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x800B9D84: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x800B9D88: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800B9D8C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800B9D90: lw          $t0, 0x0($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X0);
    // 0x800B9D94: lui         $t4, 0xF800
    ctx->r12 = S32(0XF800 << 16);
    // 0x800B9D98: andi        $t7, $a1, 0xFF
    ctx->r15 = ctx->r5 & 0XFF;
    // 0x800B9D9C: addiu       $t9, $t0, 0x8
    ctx->r25 = ADD32(ctx->r8, 0X8);
    // 0x800B9DA0: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x800B9DA4: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x800B9DA8: sll         $t6, $a0, 24
    ctx->r14 = S32(ctx->r4 << 24);
    // 0x800B9DAC: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
    // 0x800B9DB0: andi        $t4, $a2, 0xFF
    ctx->r12 = ctx->r6 & 0XFF;
    // 0x800B9DB4: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x800B9DB8: sll         $t5, $t4, 8
    ctx->r13 = S32(ctx->r12 << 8);
    // 0x800B9DBC: or          $t7, $t9, $t5
    ctx->r15 = ctx->r25 | ctx->r13;
    // 0x800B9DC0: andi        $t6, $a3, 0xFF
    ctx->r14 = ctx->r7 & 0XFF;
    // 0x800B9DC4: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x800B9DC8: sw          $t8, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r24;
    // 0x800B9DCC: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x800B9DD0: lui         $t9, 0xBC00
    ctx->r25 = S32(0XBC00 << 16);
    // 0x800B9DD4: ori         $t9, $t9, 0x8
    ctx->r25 = ctx->r25 | 0X8;
    // 0x800B9DD8: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x800B9DDC: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
    // 0x800B9DE0: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800B9DE4: lw          $t7, 0x10($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X10);
    // 0x800B9DE8: lw          $t5, 0x14($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X14);
    // 0x800B9DEC: lui         $t6, 0x1
    ctx->r14 = S32(0X1 << 16);
    // 0x800B9DF0: ori         $t6, $t6, 0xF400
    ctx->r14 = ctx->r14 | 0XF400;
    // 0x800B9DF4: subu        $t2, $t5, $t7
    ctx->r10 = SUB32(ctx->r13, ctx->r15);
    // 0x800B9DF8: div         $zero, $t6, $t2
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r10))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r10)));
    // 0x800B9DFC: negu        $t5, $t7
    ctx->r13 = SUB32(0, ctx->r15);
    // 0x800B9E00: mflo        $t4
    ctx->r12 = lo;
    // 0x800B9E04: sll         $t9, $t4, 16
    ctx->r25 = S32(ctx->r12 << 16);
    // 0x800B9E08: or          $t1, $v1, $zero
    ctx->r9 = ctx->r3 | 0;
    // 0x800B9E0C: bne         $t2, $zero, L_800B9E18
    if (ctx->r10 != 0) {
        // 0x800B9E10: nop
    
            goto L_800B9E18;
    }
    // 0x800B9E10: nop

    // 0x800B9E14: break       7
    do_break(2148245012);
L_800B9E18:
    // 0x800B9E18: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B9E1C: bne         $t2, $at, L_800B9E30
    if (ctx->r10 != ctx->r1) {
        // 0x800B9E20: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B9E30;
    }
    // 0x800B9E20: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B9E24: bne         $t6, $at, L_800B9E30
    if (ctx->r14 != ctx->r1) {
        // 0x800B9E28: nop
    
            goto L_800B9E30;
    }
    // 0x800B9E28: nop

    // 0x800B9E2C: break       6
    do_break(2148245036);
L_800B9E30:
    // 0x800B9E30: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x800B9E34: ori         $at, $at, 0xF400
    ctx->r1 = ctx->r1 | 0XF400;
    // 0x800B9E38: sll         $t6, $t5, 8
    ctx->r14 = S32(ctx->r13 << 8);
    // 0x800B9E3C: addu        $t8, $t6, $at
    ctx->r24 = ADD32(ctx->r14, ctx->r1);
    // 0x800B9E40: div         $zero, $t8, $t2
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r10))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r10)));
    // 0x800B9E44: mflo        $t4
    ctx->r12 = lo;
    // 0x800B9E48: andi        $t7, $t4, 0xFFFF
    ctx->r15 = ctx->r12 & 0XFFFF;
    // 0x800B9E4C: or          $t5, $t9, $t7
    ctx->r13 = ctx->r25 | ctx->r15;
    // 0x800B9E50: sw          $t5, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r13;
    // 0x800B9E54: bne         $t2, $zero, L_800B9E60
    if (ctx->r10 != 0) {
        // 0x800B9E58: nop
    
            goto L_800B9E60;
    }
    // 0x800B9E58: nop

    // 0x800B9E5C: break       7
    do_break(2148245084);
L_800B9E60:
    // 0x800B9E60: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B9E64: bne         $t2, $at, L_800B9E78
    if (ctx->r10 != ctx->r1) {
        // 0x800B9E68: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B9E78;
    }
    // 0x800B9E68: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B9E6C: bne         $t8, $at, L_800B9E78
    if (ctx->r24 != ctx->r1) {
        // 0x800B9E70: nop
    
            goto L_800B9E78;
    }
    // 0x800B9E70: nop

    // 0x800B9E74: break       6
    do_break(2148245108);
L_800B9E78:
    // 0x800B9E78: jr          $ra
    // 0x800B9E7C: nop

    return;
    // 0x800B9E7C: nop

;}
RECOMP_FUNC void Effect_Move(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069924: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80069928: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006992C: lwc1        $f4, 0x4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80069930: lwc1        $f6, 0x54($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X54);
    // 0x80069934: lwc1        $f10, 0x8($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80069938: lwc1        $f16, 0x58($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X58);
    // 0x8006993C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80069940: lwc1        $f6, 0x5C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X5C);
    // 0x80069944: lwc1        $f4, 0xC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80069948: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8006994C: swc1        $f8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f8.u32l;
    // 0x80069950: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x80069954: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80069958: swc1        $f18, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f18.u32l;
    // 0x8006995C: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80069960: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80069964: swc1        $f8, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f8.u32l;
    // 0x80069968: lw          $t6, 0x1AB8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1AB8);
    // 0x8006996C: beql        $t6, $zero, L_80069A04
    if (ctx->r14 == 0) {
        // 0x80069970: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80069A04;
    }
    goto skip_0;
    // 0x80069970: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80069974: lw          $v0, -0x7D80($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D80);
    // 0x80069978: lwc1        $f16, 0x2C($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x8006997C: lwc1        $f4, 0xC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80069980: lwc1        $f6, 0x7D20($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x80069984: lwc1        $f10, 0x48($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X48);
    // 0x80069988: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8006998C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80069990: c.lt.s      $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f18.fl < ctx->f8.fl;
    // 0x80069994: nop

    // 0x80069998: bc1fl       L_800699B4
    if (!c1cs) {
        // 0x8006999C: lwc1        $f10, 0x8($a0)
        ctx->f10.u32l = MEM_W(ctx->r4, 0X8);
            goto L_800699B4;
    }
    goto skip_1;
    // 0x8006999C: lwc1        $f10, 0x8($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X8);
    skip_1:
    // 0x800699A0: jal         0x80060FBC
    // 0x800699A4: addiu       $a1, $a0, 0x80
    ctx->r5 = ADD32(ctx->r4, 0X80);
    Object_Kill(rdram, ctx);
        goto after_0;
    // 0x800699A4: addiu       $a1, $a0, 0x80
    ctx->r5 = ADD32(ctx->r4, 0X80);
    after_0:
    // 0x800699A8: b           L_80069A04
    // 0x800699AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80069A04;
    // 0x800699AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800699B0: lwc1        $f10, 0x8($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X8);
L_800699B4:
    // 0x800699B4: lwc1        $f16, 0x44($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X44);
    // 0x800699B8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800699BC: lwc1        $f2, 0x6A48($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X6A48);
    // 0x800699C0: sub.s       $f0, $f10, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x800699C4: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x800699C8: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800699CC: nop

    // 0x800699D0: bc1t        L_800699F8
    if (c1cs) {
        // 0x800699D4: nop
    
            goto L_800699F8;
    }
    // 0x800699D4: nop

    // 0x800699D8: lwc1        $f4, 0x4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800699DC: lwc1        $f6, 0x40($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X40);
    // 0x800699E0: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800699E4: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x800699E8: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800699EC: nop

    // 0x800699F0: bc1fl       L_80069A04
    if (!c1cs) {
        // 0x800699F4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80069A04;
    }
    goto skip_2;
    // 0x800699F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
L_800699F8:
    // 0x800699F8: jal         0x80060FBC
    // 0x800699FC: addiu       $a1, $a0, 0x80
    ctx->r5 = ADD32(ctx->r4, 0X80);
    Object_Kill(rdram, ctx);
        goto after_1;
    // 0x800699FC: addiu       $a1, $a0, 0x80
    ctx->r5 = ADD32(ctx->r4, 0X80);
    after_1:
    // 0x80069A00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80069A04:
    // 0x80069A04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80069A08: jr          $ra
    // 0x80069A0C: nop

    return;
    // 0x80069A0C: nop

;}
RECOMP_FUNC void AllRange_DrawCountdown(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002E548: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8002E54C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8002E550: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x8002E554: lw          $t6, -0x6C4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6C4);
    // 0x8002E558: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8002E55C: addiu       $a0, $a0, -0x6D0
    ctx->r4 = ADD32(ctx->r4, -0X6D0);
    // 0x8002E560: beq         $t6, $zero, L_8002E5D0
    if (ctx->r14 == 0) {
        // 0x8002E564: lui         $a1, 0x8016
        ctx->r5 = S32(0X8016 << 16);
            goto L_8002E5D0;
    }
    // 0x8002E564: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8002E568: lw          $t7, 0x4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4);
    // 0x8002E56C: lw          $a1, -0x6BC($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X6BC);
    // 0x8002E570: jal         0x8008E51C
    // 0x8002E574: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    HUD_DrawCountdown(rdram, ctx);
        goto after_0;
    // 0x8002E574: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    after_0:
    // 0x8002E578: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8002E57C: addiu       $a0, $a0, -0x6D0
    ctx->r4 = ADD32(ctx->r4, -0X6D0);
    // 0x8002E580: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8002E584: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8002E588: bnel        $t8, $zero, L_8002E5D4
    if (ctx->r24 != 0) {
        // 0x8002E58C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8002E5D4;
    }
    goto skip_0;
    // 0x8002E58C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8002E590: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x8002E594: beq         $t9, $v0, L_8002E5D0
    if (ctx->r25 == ctx->r2) {
        // 0x8002E598: slti        $at, $v0, 0xF
        ctx->r1 = SIGNED(ctx->r2) < 0XF ? 1 : 0;
            goto L_8002E5D0;
    }
    // 0x8002E598: slti        $at, $v0, 0xF
    ctx->r1 = SIGNED(ctx->r2) < 0XF ? 1 : 0;
    // 0x8002E59C: beq         $at, $zero, L_8002E5D0
    if (ctx->r1 == 0) {
        // 0x8002E5A0: lui         $a3, 0x800C
        ctx->r7 = S32(0X800C << 16);
            goto L_8002E5D0;
    }
    // 0x8002E5A0: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8002E5A4: lui         $t0, 0x800C
    ctx->r8 = S32(0X800C << 16);
    // 0x8002E5A8: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8002E5AC: addiu       $t0, $t0, 0x5D3C
    ctx->r8 = ADD32(ctx->r8, 0X5D3C);
    // 0x8002E5B0: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x8002E5B4: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x8002E5B8: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x8002E5BC: ori         $a0, $a0, 0xC02A
    ctx->r4 = ctx->r4 | 0XC02A;
    // 0x8002E5C0: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8002E5C4: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8002E5C8: jal         0x80019218
    // 0x8002E5CC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_1;
    // 0x8002E5CC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_1:
L_8002E5D0:
    // 0x8002E5D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8002E5D4:
    // 0x8002E5D4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8002E5D8: jr          $ra
    // 0x8002E5DC: nop

    return;
    // 0x8002E5DC: nop

;}
RECOMP_FUNC void Aquas_Effect363_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80094954: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80094958: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009495C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80094960: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80094964: lw          $v0, -0x7D80($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D80);
    // 0x80094968: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8009496C: lw          $v1, 0x1C8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X1C8);
    // 0x80094970: bnel        $a1, $v1, L_80094ABC
    if (ctx->r5 != ctx->r3) {
        // 0x80094974: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_80094ABC;
    }
    goto skip_0;
    // 0x80094974: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    skip_0:
    // 0x80094978: lw          $t6, -0x7DCC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7DCC);
    // 0x8009497C: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x80094980: bnel        $t6, $at, L_80094ABC
    if (ctx->r14 != ctx->r1) {
        // 0x80094984: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_80094ABC;
    }
    goto skip_1;
    // 0x80094984: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    skip_1:
    // 0x80094988: lw          $t7, 0x1D0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X1D0);
    // 0x8009498C: slti        $at, $t7, 0x2
    ctx->r1 = SIGNED(ctx->r15) < 0X2 ? 1 : 0;
    // 0x80094990: beql        $at, $zero, L_80094ABC
    if (ctx->r1 == 0) {
        // 0x80094994: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_80094ABC;
    }
    goto skip_2;
    // 0x80094994: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    skip_2:
    // 0x80094998: lh          $v0, 0x4E($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X4E);
    // 0x8009499C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800949A0: beql        $v0, $zero, L_800949BC
    if (ctx->r2 == 0) {
        // 0x800949A4: lh          $t8, 0x44($a0)
        ctx->r24 = MEM_H(ctx->r4, 0X44);
            goto L_800949BC;
    }
    goto skip_3;
    // 0x800949A4: lh          $t8, 0x44($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X44);
    skip_3:
    // 0x800949A8: beql        $v0, $at, L_80094A0C
    if (ctx->r2 == ctx->r1) {
        // 0x800949AC: lh          $t5, 0x4A($a0)
        ctx->r13 = MEM_H(ctx->r4, 0X4A);
            goto L_80094A0C;
    }
    goto skip_4;
    // 0x800949AC: lh          $t5, 0x4A($a0)
    ctx->r13 = MEM_H(ctx->r4, 0X4A);
    skip_4:
    // 0x800949B0: b           L_80094A34
    // 0x800949B4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
        goto L_80094A34;
    // 0x800949B4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800949B8: lh          $t8, 0x44($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X44);
L_800949BC:
    // 0x800949BC: lh          $t9, 0x46($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X46);
    // 0x800949C0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800949C4: lwc1        $f4, 0x70($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X70);
    // 0x800949C8: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x800949CC: sh          $t0, 0x44($a0)
    MEM_H(0X44, ctx->r4) = ctx->r8;
    // 0x800949D0: lh          $t1, 0x44($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X44);
    // 0x800949D4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800949D8: addiu       $t4, $zero, 0xC8
    ctx->r12 = ADD32(0, 0XC8);
    // 0x800949DC: sh          $t1, 0x4A($a0)
    MEM_H(0X4A, ctx->r4) = ctx->r9;
    // 0x800949E0: lwc1        $f6, -0x7F80($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7F80);
    // 0x800949E4: lh          $t2, 0x4A($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X4A);
    // 0x800949E8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800949EC: slti        $at, $t2, 0xC8
    ctx->r1 = SIGNED(ctx->r10) < 0XC8 ? 1 : 0;
    // 0x800949F0: bne         $at, $zero, L_80094A00
    if (ctx->r1 != 0) {
        // 0x800949F4: swc1        $f8, 0x70($a0)
        MEM_W(0X70, ctx->r4) = ctx->f8.u32l;
            goto L_80094A00;
    }
    // 0x800949F4: swc1        $f8, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f8.u32l;
    // 0x800949F8: sh          $t3, 0x4E($a0)
    MEM_H(0X4E, ctx->r4) = ctx->r11;
    // 0x800949FC: sh          $t4, 0x4A($a0)
    MEM_H(0X4A, ctx->r4) = ctx->r12;
L_80094A00:
    // 0x80094A00: b           L_80094A30
    // 0x80094A04: lh          $v0, 0x4E($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X4E);
        goto L_80094A30;
    // 0x80094A04: lh          $v0, 0x4E($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X4E);
    // 0x80094A08: lh          $t5, 0x4A($a0)
    ctx->r13 = MEM_H(ctx->r4, 0X4A);
L_80094A0C:
    // 0x80094A0C: lh          $t6, 0x46($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X46);
    // 0x80094A10: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80094A14: lwc1        $f10, 0x70($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X70);
    // 0x80094A18: subu        $t7, $t5, $t6
    ctx->r15 = SUB32(ctx->r13, ctx->r14);
    // 0x80094A1C: sh          $t7, 0x4A($a0)
    MEM_H(0X4A, ctx->r4) = ctx->r15;
    // 0x80094A20: lwc1        $f16, -0x7F7C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X7F7C);
    // 0x80094A24: lh          $v0, 0x4E($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X4E);
    // 0x80094A28: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80094A2C: swc1        $f18, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f18.u32l;
L_80094A30:
    // 0x80094A30: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_80094A34:
    // 0x80094A34: bnel        $v0, $at, L_80094A5C
    if (ctx->r2 != ctx->r1) {
        // 0x80094A38: lwc1        $f0, 0x6C($a0)
        ctx->f0.u32l = MEM_W(ctx->r4, 0X6C);
            goto L_80094A5C;
    }
    goto skip_5;
    // 0x80094A38: lwc1        $f0, 0x6C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X6C);
    skip_5:
    // 0x80094A3C: lh          $t8, 0x4A($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X4A);
    // 0x80094A40: addiu       $a1, $a0, 0x80
    ctx->r5 = ADD32(ctx->r4, 0X80);
    // 0x80094A44: bgtzl       $t8, L_80094A5C
    if (SIGNED(ctx->r24) > 0) {
        // 0x80094A48: lwc1        $f0, 0x6C($a0)
        ctx->f0.u32l = MEM_W(ctx->r4, 0X6C);
            goto L_80094A5C;
    }
    goto skip_6;
    // 0x80094A48: lwc1        $f0, 0x6C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X6C);
    skip_6:
    // 0x80094A4C: jal         0x80060FBC
    // 0x80094A50: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    Object_Kill(rdram, ctx);
        goto after_0;
    // 0x80094A50: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80094A54: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80094A58: lwc1        $f0, 0x6C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X6C);
L_80094A5C:
    // 0x80094A5C: lwc1        $f4, 0x58($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X58);
    // 0x80094A60: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80094A64: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80094A68: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80094A6C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80094A70: swc1        $f6, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f6.u32l;
    // 0x80094A74: lwc1        $f8, -0x7F78($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X7F78);
    // 0x80094A78: sub.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x80094A7C: swc1        $f10, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f10.u32l;
    // 0x80094A80: lwc1        $f16, 0x6C($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x80094A84: c.lt.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl < ctx->f2.fl;
    // 0x80094A88: nop

    // 0x80094A8C: bc1fl       L_80094A9C
    if (!c1cs) {
        // 0x80094A90: lh          $t9, 0x48($a0)
        ctx->r25 = MEM_H(ctx->r4, 0X48);
            goto L_80094A9C;
    }
    goto skip_7;
    // 0x80094A90: lh          $t9, 0x48($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X48);
    skip_7:
    // 0x80094A94: swc1        $f2, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f2.u32l;
    // 0x80094A98: lh          $t9, 0x48($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X48);
L_80094A9C:
    // 0x80094A9C: lwc1        $f18, 0x18($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X18);
    // 0x80094AA0: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80094AA4: nop

    // 0x80094AA8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80094AAC: add.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x80094AB0: b           L_80094BAC
    // 0x80094AB4: swc1        $f8, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f8.u32l;
        goto L_80094BAC;
    // 0x80094AB4: swc1        $f8, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f8.u32l;
    // 0x80094AB8: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
L_80094ABC:
    // 0x80094ABC: bne         $v1, $at, L_80094AF8
    if (ctx->r3 != ctx->r1) {
        // 0x80094AC0: lui         $at, 0x4334
        ctx->r1 = S32(0X4334 << 16);
            goto L_80094AF8;
    }
    // 0x80094AC0: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80094AC4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80094AC8: lwc1        $f10, 0x5C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x80094ACC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80094AD0: lwc1        $f2, -0x7F74($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X7F74);
    // 0x80094AD4: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80094AD8: div.s       $f4, $f16, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = DIV_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80094ADC: swc1        $f4, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f4.u32l;
    // 0x80094AE0: lwc1        $f18, 0x58($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X58);
    // 0x80094AE4: neg.s       $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = -ctx->f18.fl;
    // 0x80094AE8: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80094AEC: div.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80094AF0: swc1        $f10, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f10.u32l;
    // 0x80094AF4: lw          $v1, 0x1C8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X1C8);
L_80094AF8:
    // 0x80094AF8: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80094AFC: bnel        $v1, $at, L_80094B2C
    if (ctx->r3 != ctx->r1) {
        // 0x80094B00: lh          $t1, 0x4A($a0)
        ctx->r9 = MEM_H(ctx->r4, 0X4A);
            goto L_80094B2C;
    }
    goto skip_8;
    // 0x80094B00: lh          $t1, 0x4A($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X4A);
    skip_8:
    // 0x80094B04: sh          $a1, 0x46($a0)
    MEM_H(0X46, ctx->r4) = ctx->r5;
    // 0x80094B08: lw          $t0, 0x1D0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X1D0);
    // 0x80094B0C: slti        $at, $t0, 0x4
    ctx->r1 = SIGNED(ctx->r8) < 0X4 ? 1 : 0;
    // 0x80094B10: bne         $at, $zero, L_80094B28
    if (ctx->r1 != 0) {
        // 0x80094B14: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_80094B28;
    }
    // 0x80094B14: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80094B18: lwc1        $f4, -0x7F70($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7F70);
    // 0x80094B1C: lwc1        $f16, 0x58($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X58);
    // 0x80094B20: sub.s       $f18, $f16, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x80094B24: swc1        $f18, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f18.u32l;
L_80094B28:
    // 0x80094B28: lh          $t1, 0x4A($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X4A);
L_80094B2C:
    // 0x80094B2C: lh          $t2, 0x46($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X46);
    // 0x80094B30: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80094B34: lwc1        $f8, -0x7F6C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X7F6C);
    // 0x80094B38: lwc1        $f6, 0x70($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X70);
    // 0x80094B3C: subu        $t3, $t1, $t2
    ctx->r11 = SUB32(ctx->r9, ctx->r10);
    // 0x80094B40: sh          $t3, 0x4A($a0)
    MEM_H(0X4A, ctx->r4) = ctx->r11;
    // 0x80094B44: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80094B48: lh          $t4, 0x4A($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X4A);
    // 0x80094B4C: bltz        $t4, L_80094B80
    if (SIGNED(ctx->r12) < 0) {
        // 0x80094B50: swc1        $f10, 0x70($a0)
        MEM_W(0X70, ctx->r4) = ctx->f10.u32l;
            goto L_80094B80;
    }
    // 0x80094B50: swc1        $f10, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f10.u32l;
    // 0x80094B54: lw          $t5, 0x1C8($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X1C8);
    // 0x80094B58: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80094B5C: bnel        $a1, $t5, L_80094B94
    if (ctx->r5 != ctx->r13) {
        // 0x80094B60: lh          $t8, 0x48($a0)
        ctx->r24 = MEM_H(ctx->r4, 0X48);
            goto L_80094B94;
    }
    goto skip_9;
    // 0x80094B60: lh          $t8, 0x48($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X48);
    skip_9:
    // 0x80094B64: lw          $t6, -0x7DCC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7DCC);
    // 0x80094B68: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x80094B6C: bnel        $t6, $at, L_80094B94
    if (ctx->r14 != ctx->r1) {
        // 0x80094B70: lh          $t8, 0x48($a0)
        ctx->r24 = MEM_H(ctx->r4, 0X48);
            goto L_80094B94;
    }
    goto skip_10;
    // 0x80094B70: lh          $t8, 0x48($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X48);
    skip_10:
    // 0x80094B74: lw          $t7, 0x1D0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X1D0);
    // 0x80094B78: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80094B7C: bne         $t7, $at, L_80094B90
    if (ctx->r15 != ctx->r1) {
        // 0x80094B80: addiu       $a1, $a0, 0x80
        ctx->r5 = ADD32(ctx->r4, 0X80);
            goto L_80094B90;
    }
L_80094B80:
    // 0x80094B80: addiu       $a1, $a0, 0x80
    ctx->r5 = ADD32(ctx->r4, 0X80);
    // 0x80094B84: jal         0x80060FBC
    // 0x80094B88: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    Object_Kill(rdram, ctx);
        goto after_1;
    // 0x80094B88: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x80094B8C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_80094B90:
    // 0x80094B90: lh          $t8, 0x48($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X48);
L_80094B94:
    // 0x80094B94: lwc1        $f16, 0x18($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X18);
    // 0x80094B98: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80094B9C: nop

    // 0x80094BA0: cvt.s.w     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80094BA4: add.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80094BA8: swc1        $f6, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f6.u32l;
L_80094BAC:
    // 0x80094BAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80094BB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80094BB4: jr          $ra
    // 0x80094BB8: nop

    return;
    // 0x80094BB8: nop

;}
RECOMP_FUNC void Audio_UpdatePlayerReverb(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001BB74: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001BB78: lwc1        $f12, -0x6F24($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X6F24);
    // 0x8001BB7C: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x8001BB80: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x8001BB84: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8001BB88: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8001BB8C: addiu       $a1, $a1, -0x47B0
    ctx->r5 = ADD32(ctx->r5, -0X47B0);
    // 0x8001BB90: addiu       $a3, $a3, -0x7D80
    ctx->r7 = ADD32(ctx->r7, -0X7D80);
    // 0x8001BB94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001BB98: addiu       $t0, $zero, 0x4E0
    ctx->r8 = ADD32(0, 0X4E0);
    // 0x8001BB9C: addiu       $a2, $zero, 0x70
    ctx->r6 = ADD32(0, 0X70);
L_8001BBA0:
    // 0x8001BBA0: multu       $v0, $a2
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001BBA4: mflo        $t6
    ctx->r14 = lo;
    // 0x8001BBA8: addu        $v1, $a1, $t6
    ctx->r3 = ADD32(ctx->r5, ctx->r14);
    // 0x8001BBAC: lbu         $t7, 0x6C($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X6C);
    // 0x8001BBB0: bnel        $t7, $zero, L_8001BC08
    if (ctx->r15 != 0) {
        // 0x8001BBB4: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8001BC08;
    }
    goto skip_0;
    // 0x8001BBB4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_0:
    // 0x8001BBB8: multu       $v0, $t0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001BBBC: lw          $t8, 0x0($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X0);
    // 0x8001BBC0: mflo        $t9
    ctx->r25 = lo;
    // 0x8001BBC4: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    // 0x8001BBC8: lbu         $t1, 0x478($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X478);
    // 0x8001BBCC: bnel        $t1, $zero, L_8001BC08
    if (ctx->r9 != 0) {
        // 0x8001BBD0: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8001BC08;
    }
    goto skip_1;
    // 0x8001BBD0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_1:
    // 0x8001BBD4: lwc1        $f0, 0x78($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X78);
    // 0x8001BBD8: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8001BBDC: nop

    // 0x8001BBE0: bc1fl       L_8001BC04
    if (!c1cs) {
        // 0x8001BBE4: sb          $zero, 0x6D($v1)
        MEM_B(0X6D, ctx->r3) = 0;
            goto L_8001BC04;
    }
    goto skip_2;
    // 0x8001BBE4: sb          $zero, 0x6D($v1)
    MEM_B(0X6D, ctx->r3) = 0;
    skip_2:
    // 0x8001BBE8: sub.s       $f4, $f2, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x8001BBEC: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x8001BBF0: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8001BBF4: mfc1        $t3, $f8
    ctx->r11 = (int32_t)ctx->f8.u32l;
    // 0x8001BBF8: b           L_8001BC04
    // 0x8001BBFC: sb          $t3, 0x6D($v1)
    MEM_B(0X6D, ctx->r3) = ctx->r11;
        goto L_8001BC04;
    // 0x8001BBFC: sb          $t3, 0x6D($v1)
    MEM_B(0X6D, ctx->r3) = ctx->r11;
    // 0x8001BC00: sb          $zero, 0x6D($v1)
    MEM_B(0X6D, ctx->r3) = 0;
L_8001BC04:
    // 0x8001BC04: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_8001BC08:
    // 0x8001BC08: andi        $t4, $v0, 0xFF
    ctx->r12 = ctx->r2 & 0XFF;
    // 0x8001BC0C: slti        $at, $t4, 0x4
    ctx->r1 = SIGNED(ctx->r12) < 0X4 ? 1 : 0;
    // 0x8001BC10: bne         $at, $zero, L_8001BBA0
    if (ctx->r1 != 0) {
        // 0x8001BC14: or          $v0, $t4, $zero
        ctx->r2 = ctx->r12 | 0;
            goto L_8001BBA0;
    }
    // 0x8001BC14: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    // 0x8001BC18: jr          $ra
    // 0x8001BC1C: nop

    return;
    // 0x8001BC1C: nop

;}
RECOMP_FUNC void Effect_Effect342_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007E330: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007E334: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007E338: lwc1        $f12, 0x70($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X70);
    // 0x8007E33C: jal         0x8005980C
    // 0x8007E340: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    Graphics_SetScaleMtx(rdram, ctx);
        goto after_0;
    // 0x8007E340: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8007E344: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8007E348: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8007E34C: addiu       $a1, $a1, 0x7E64
    ctx->r5 = ADD32(ctx->r5, 0X7E64);
    // 0x8007E350: lh          $t6, 0x44($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X44);
    // 0x8007E354: bne         $t6, $zero, L_8007E38C
    if (ctx->r14 != 0) {
        // 0x8007E358: nop
    
            goto L_8007E38C;
    }
    // 0x8007E358: nop

    // 0x8007E35C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8007E360: addiu       $a1, $a1, 0x7E64
    ctx->r5 = ADD32(ctx->r5, 0X7E64);
    // 0x8007E364: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8007E368: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x8007E36C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8007E370: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x8007E374: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8007E378: lh          $t9, 0x4A($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X4A);
    // 0x8007E37C: andi        $t0, $t9, 0xFF
    ctx->r8 = ctx->r25 & 0XFF;
    // 0x8007E380: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x8007E384: b           L_8007E3B8
    // 0x8007E388: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
        goto L_8007E3B8;
    // 0x8007E388: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
L_8007E38C:
    // 0x8007E38C: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8007E390: lui         $t2, 0xFA00
    ctx->r10 = S32(0XFA00 << 16);
    // 0x8007E394: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x8007E398: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x8007E39C: sw          $t1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r9;
    // 0x8007E3A0: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x8007E3A4: lh          $t3, 0x4A($a0)
    ctx->r11 = MEM_H(ctx->r4, 0X4A);
    // 0x8007E3A8: andi        $t4, $t3, 0xFF
    ctx->r12 = ctx->r11 & 0XFF;
    // 0x8007E3AC: or          $t5, $t4, $at
    ctx->r13 = ctx->r12 | ctx->r1;
    // 0x8007E3B0: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x8007E3B4: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
L_8007E3B8:
    // 0x8007E3B8: lui         $t8, 0x201
    ctx->r24 = S32(0X201 << 16);
    // 0x8007E3BC: addiu       $t8, $t8, 0xA30
    ctx->r24 = ADD32(ctx->r24, 0XA30);
    // 0x8007E3C0: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8007E3C4: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x8007E3C8: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x8007E3CC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8007E3D0: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8007E3D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007E3D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007E3DC: jr          $ra
    // 0x8007E3E0: nop

    return;
    // 0x8007E3E0: nop

;}
RECOMP_FUNC void RCP_SetupDL_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B92F8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800B92FC: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x800B9300: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800B9304: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x800B9308: addiu       $t8, $t8, 0x35A0
    ctx->r24 = ADD32(ctx->r24, 0X35A0);
    // 0x800B930C: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800B9310: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800B9314: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x800B9318: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800B931C: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800B9320: jr          $ra
    // 0x800B9324: nop

    return;
    // 0x800B9324: nop

;}
RECOMP_FUNC void Effect_Effect398_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008040C: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80080410: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80080414: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80080418: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8008041C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80080420: lh          $v0, 0x4E($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X4E);
    // 0x80080424: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80080428: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8008042C: beq         $v0, $zero, L_80080444
    if (ctx->r2 == 0) {
        // 0x80080430: lui         $s0, 0x8018
        ctx->r16 = S32(0X8018 << 16);
            goto L_80080444;
    }
    // 0x80080430: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x80080434: beq         $v0, $at, L_80080558
    if (ctx->r2 == ctx->r1) {
        // 0x80080438: lui         $s0, 0x8018
        ctx->r16 = S32(0X8018 << 16);
            goto L_80080558;
    }
    // 0x80080438: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x8008043C: b           L_80080908
    // 0x80080440: lw          $s0, -0x7D80($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X7D80);
        goto L_80080908;
    // 0x80080440: lw          $s0, -0x7D80($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X7D80);
L_80080444:
    // 0x80080444: lw          $s0, -0x7D80($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X7D80);
    // 0x80080448: lwc1        $f6, 0x4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8008044C: lwc1        $f10, 0xC($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80080450: lwc1        $f4, 0x74($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X74);
    // 0x80080454: lwc1        $f8, 0x138($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X138);
    // 0x80080458: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8008045C: jal         0x80005100
    // 0x80080460: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    Math_Atan2F(rdram, ctx);
        goto after_0;
    // 0x80080460: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    after_0:
    // 0x80080464: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x80080468: lw          $s0, -0x7D80($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X7D80);
    // 0x8008046C: swc1        $f0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f0.u32l;
    // 0x80080470: lwc1        $f4, 0xC($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80080474: lwc1        $f18, 0x138($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X138);
    // 0x80080478: lwc1        $f8, 0x4($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8008047C: lwc1        $f6, 0x74($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X74);
    // 0x80080480: sub.s       $f16, $f18, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80080484: lwc1        $f4, 0x78($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X78);
    // 0x80080488: sub.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8008048C: mul.s       $f10, $f16, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x80080490: lwc1        $f6, 0x8($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80080494: mul.s       $f18, $f2, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80080498: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8008049C: add.s       $f0, $f10, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x800804A0: jal         0x80005100
    // 0x800804A4: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    Math_Atan2F(rdram, ctx);
        goto after_1;
    // 0x800804A4: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    after_1:
    // 0x800804A8: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x800804AC: neg.s       $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = -ctx->f0.fl;
    // 0x800804B0: addiu       $s0, $s0, -0x4438
    ctx->r16 = ADD32(ctx->r16, -0X4438);
    // 0x800804B4: swc1        $f8, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f8.u32l;
    // 0x800804B8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800804BC: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    // 0x800804C0: jal         0x80005E90
    // 0x800804C4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Matrix_RotateY(rdram, ctx);
        goto after_2;
    // 0x800804C4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x800804C8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800804CC: lw          $a1, 0x6C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X6C);
    // 0x800804D0: jal         0x80005D44
    // 0x800804D4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateX(rdram, ctx);
        goto after_3;
    // 0x800804D4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x800804D8: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800804DC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800804E0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800804E4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800804E8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800804EC: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x800804F0: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    // 0x800804F4: swc1        $f10, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f10.u32l;
    // 0x800804F8: swc1        $f18, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f18.u32l;
    // 0x800804FC: jal         0x80006970
    // 0x80080500: swc1        $f4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f4.u32l;
    Matrix_MultVec3f(rdram, ctx);
        goto after_4;
    // 0x80080500: swc1        $f4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f4.u32l;
    after_4:
    // 0x80080504: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80080508: lwc1        $f8, 0x79E4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X79E4);
    // 0x8008050C: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80080510: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80080514: lh          $t6, 0x4E($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X4E);
    // 0x80080518: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8008051C: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x80080520: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80080524: swc1        $f10, 0x54($s1)
    MEM_W(0X54, ctx->r17) = ctx->f10.u32l;
    // 0x80080528: lwc1        $f4, 0x79F4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X79F4);
    // 0x8008052C: lwc1        $f18, 0x4C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80080530: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80080534: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80080538: swc1        $f6, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->f6.u32l;
    // 0x8008053C: lwc1        $f10, 0x7D08($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7D08);
    // 0x80080540: lwc1        $f8, 0x50($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80080544: sh          $t7, 0x4E($s1)
    MEM_H(0X4E, ctx->r17) = ctx->r15;
    // 0x80080548: sub.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8008054C: swc1        $f18, 0x5C($s1)
    MEM_W(0X5C, ctx->r17) = ctx->f18.u32l;
    // 0x80080550: b           L_80080908
    // 0x80080554: lw          $s0, -0x7D80($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X7D80);
        goto L_80080908;
    // 0x80080554: lw          $s0, -0x7D80($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X7D80);
L_80080558:
    // 0x80080558: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8008055C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80080560: lwc1        $f6, 0x18($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X18);
    // 0x80080564: lhu         $t8, 0x50($s1)
    ctx->r24 = MEM_HU(ctx->r17, 0X50);
    // 0x80080568: addiu       $a1, $s1, 0x80
    ctx->r5 = ADD32(ctx->r17, 0X80);
    // 0x8008056C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80080570: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80080574: bne         $t8, $zero, L_8008058C
    if (ctx->r24 != 0) {
        // 0x80080578: swc1        $f8, 0x18($s1)
        MEM_W(0X18, ctx->r17) = ctx->f8.u32l;
            goto L_8008058C;
    }
    // 0x80080578: swc1        $f8, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->f8.u32l;
    // 0x8008057C: jal         0x80060FBC
    // 0x80080580: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Object_Kill(rdram, ctx);
        goto after_5;
    // 0x80080580: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x80080584: b           L_8008091C
    // 0x80080588: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8008091C;
    // 0x80080588: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8008058C:
    // 0x8008058C: jal         0x8007FD84
    // 0x80080590: swc1        $f12, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f12.u32l;
    Effect_CheckTeamCollision(rdram, ctx);
        goto after_6;
    // 0x80080590: swc1        $f12, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f12.u32l;
    after_6:
    // 0x80080594: beq         $v0, $zero, L_800805B0
    if (ctx->r2 == 0) {
        // 0x80080598: lwc1        $f12, 0x60($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X60);
            goto L_800805B0;
    }
    // 0x80080598: lwc1        $f12, 0x60($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8008059C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800805A0: jal         0x80060FBC
    // 0x800805A4: addiu       $a1, $s1, 0x80
    ctx->r5 = ADD32(ctx->r17, 0X80);
    Object_Kill(rdram, ctx);
        goto after_7;
    // 0x800805A4: addiu       $a1, $s1, 0x80
    ctx->r5 = ADD32(ctx->r17, 0X80);
    after_7:
    // 0x800805A8: b           L_8008091C
    // 0x800805AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8008091C;
    // 0x800805AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800805B0:
    // 0x800805B0: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x800805B4: lw          $s0, -0x7D80($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X7D80);
    // 0x800805B8: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800805BC: lw          $v0, 0x280($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X280);
    // 0x800805C0: beql        $v0, $zero, L_800805D4
    if (ctx->r2 == 0) {
        // 0x800805C4: lwc1        $f10, 0x138($s0)
        ctx->f10.u32l = MEM_W(ctx->r16, 0X138);
            goto L_800805D4;
    }
    goto skip_0;
    // 0x800805C4: lwc1        $f10, 0x138($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X138);
    skip_0:
    // 0x800805C8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800805CC: nop

    // 0x800805D0: lwc1        $f10, 0x138($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X138);
L_800805D4:
    // 0x800805D4: lwc1        $f18, 0xC($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0XC);
    // 0x800805D8: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x800805DC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800805E0: sub.s       $f0, $f10, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x800805E4: add.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x800805E8: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x800805EC: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x800805F0: nop

    // 0x800805F4: bc1f        L_80080900
    if (!c1cs) {
        // 0x800805F8: nop
    
            goto L_80080900;
    }
    // 0x800805F8: nop

    // 0x800805FC: lwc1        $f8, 0x74($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X74);
    // 0x80080600: lwc1        $f10, 0x4($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80080604: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80080608: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8008060C: sub.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80080610: add.s       $f2, $f18, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f18.fl + ctx->f12.fl;
    // 0x80080614: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80080618: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8008061C: nop

    // 0x80080620: bc1f        L_80080804
    if (!c1cs) {
        // 0x80080624: nop
    
            goto L_80080804;
    }
    // 0x80080624: nop

    // 0x80080628: lwc1        $f4, 0x78($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X78);
    // 0x8008062C: lwc1        $f6, 0x8($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80080630: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80080634: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80080638: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8008063C: nop

    // 0x80080640: bc1f        L_80080804
    if (!c1cs) {
        // 0x80080644: nop
    
            goto L_80080804;
    }
    // 0x80080644: nop

    // 0x80080648: bne         $v0, $zero, L_8008065C
    if (ctx->r2 != 0) {
        // 0x8008064C: lui         $at, 0x42B4
        ctx->r1 = S32(0X42B4 << 16);
            goto L_8008065C;
    }
    // 0x8008064C: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80080650: lw          $t9, 0x27C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X27C);
    // 0x80080654: beq         $t9, $zero, L_80080754
    if (ctx->r25 == 0) {
        // 0x80080658: nop
    
            goto L_80080754;
    }
    // 0x80080658: nop

L_8008065C:
    // 0x8008065C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80080660: jal         0x80004EB0
    // 0x80080664: swc1        $f8, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f8.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_8;
    // 0x80080664: swc1        $f8, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f8.u32l;
    after_8:
    // 0x80080668: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8008066C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80080670: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80080674: lwc1        $f4, 0x14($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X14);
    // 0x80080678: mul.s       $f18, $f0, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8008067C: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x80080680: addiu       $s0, $s0, -0x4438
    ctx->r16 = ADD32(ctx->r16, -0X4438);
    // 0x80080684: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80080688: swc1        $f18, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f18.u32l;
    // 0x8008068C: lwc1        $f6, 0x74D8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X74D8);
    // 0x80080690: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80080694: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80080698: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8008069C: jal         0x80005E90
    // 0x800806A0: nop

    Matrix_RotateY(rdram, ctx);
        goto after_9;
    // 0x800806A0: nop

    after_9:
    // 0x800806A4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800806A8: lwc1        $f18, 0x74DC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X74DC);
    // 0x800806AC: lwc1        $f10, 0x10($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X10);
    // 0x800806B0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800806B4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800806B8: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800806BC: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x800806C0: jal         0x80005D44
    // 0x800806C4: nop

    Matrix_RotateX(rdram, ctx);
        goto after_10;
    // 0x800806C4: nop

    after_10:
    // 0x800806C8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800806CC: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800806D0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800806D4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800806D8: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x800806DC: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    // 0x800806E0: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    // 0x800806E4: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    // 0x800806E8: jal         0x80006970
    // 0x800806EC: swc1        $f6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f6.u32l;
    Matrix_MultVec3f(rdram, ctx);
        goto after_11;
    // 0x800806EC: swc1        $f6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f6.u32l;
    after_11:
    // 0x800806F0: lwc1        $f8, 0x48($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800806F4: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x800806F8: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x800806FC: swc1        $f8, 0x54($s1)
    MEM_W(0X54, ctx->r17) = ctx->f8.u32l;
    // 0x80080700: lwc1        $f10, 0x4C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80080704: lui         $t2, 0x800C
    ctx->r10 = S32(0X800C << 16);
    // 0x80080708: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8008070C: swc1        $f10, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->f10.u32l;
    // 0x80080710: lwc1        $f18, 0x50($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80080714: addiu       $t2, $t2, 0x5D3C
    ctx->r10 = ADD32(ctx->r10, 0X5D3C);
    // 0x80080718: lui         $a0, 0x900
    ctx->r4 = S32(0X900 << 16);
    // 0x8008071C: swc1        $f18, 0x5C($s1)
    MEM_W(0X5C, ctx->r17) = ctx->f18.u32l;
    // 0x80080720: lw          $s0, -0x7D80($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X7D80);
    // 0x80080724: ori         $a0, $a0, 0x7011
    ctx->r4 = ctx->r4 | 0X7011;
    // 0x80080728: addiu       $a1, $s1, 0x80
    ctx->r5 = ADD32(ctx->r17, 0X80);
    // 0x8008072C: lw          $t0, 0x2C4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X2C4);
    // 0x80080730: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80080734: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80080738: sw          $t1, 0x2C4($s0)
    MEM_W(0X2C4, ctx->r16) = ctx->r9;
    // 0x8008073C: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80080740: jal         0x80019218
    // 0x80080744: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    Audio_PlaySfx(rdram, ctx);
        goto after_12;
    // 0x80080744: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_12:
    // 0x80080748: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x8008074C: lw          $s0, -0x7D80($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X7D80);
    // 0x80080750: lw          $v0, 0x280($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X280);
L_80080754:
    // 0x80080754: bne         $v0, $zero, L_80080804
    if (ctx->r2 != 0) {
        // 0x80080758: nop
    
            goto L_80080804;
    }
    // 0x80080758: nop

    // 0x8008075C: lw          $t3, 0x498($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X498);
    // 0x80080760: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80080764: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80080768: bne         $t3, $zero, L_80080804
    if (ctx->r11 != 0) {
        // 0x8008076C: addiu       $t4, $s1, 0x80
        ctx->r12 = ADD32(ctx->r17, 0X80);
            goto L_80080804;
    }
    // 0x8008076C: addiu       $t4, $s1, 0x80
    ctx->r12 = ADD32(ctx->r17, 0X80);
    // 0x80080770: lbu         $a2, 0x34($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X34);
    // 0x80080774: jal         0x800A6CD0
    // 0x80080778: sw          $t4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r12;
    Player_ApplyDamage(rdram, ctx);
        goto after_13;
    // 0x80080778: sw          $t4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r12;
    after_13:
    // 0x8008077C: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80080780: addiu       $v0, $v0, -0x7D80
    ctx->r2 = ADD32(ctx->r2, -0X7D80);
    // 0x80080784: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80080788: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8008078C: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x80080790: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80080794: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80080798: swc1        $f0, 0xD8($t5)
    MEM_W(0XD8, ctx->r13) = ctx->f0.u32l;
    // 0x8008079C: lwc1        $f4, 0x54($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X54);
    // 0x800807A0: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x800807A4: nop

    // 0x800807A8: bc1fl       L_800807CC
    if (!c1cs) {
        // 0x800807AC: lw          $t6, 0x0($v0)
        ctx->r14 = MEM_W(ctx->r2, 0X0);
            goto L_800807CC;
    }
    goto skip_1;
    // 0x800807AC: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    skip_1:
    // 0x800807B0: lw          $s0, 0x0($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X0);
    // 0x800807B4: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x800807B8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800807BC: lwc1        $f6, 0xD8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XD8);
    // 0x800807C0: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800807C4: swc1        $f10, 0xD8($s0)
    MEM_W(0XD8, ctx->r16) = ctx->f10.u32l;
    // 0x800807C8: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
L_800807CC:
    // 0x800807CC: swc1        $f0, 0xDC($t6)
    MEM_W(0XDC, ctx->r14) = ctx->f0.u32l;
    // 0x800807D0: lwc1        $f18, 0x58($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X58);
    // 0x800807D4: c.lt.s      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl < ctx->f2.fl;
    // 0x800807D8: nop

    // 0x800807DC: bc1f        L_800807FC
    if (!c1cs) {
        // 0x800807E0: nop
    
            goto L_800807FC;
    }
    // 0x800807E0: nop

    // 0x800807E4: lw          $s0, 0x0($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X0);
    // 0x800807E8: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x800807EC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800807F0: lwc1        $f4, 0xDC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XDC);
    // 0x800807F4: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800807F8: swc1        $f8, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f8.u32l;
L_800807FC:
    // 0x800807FC: jal         0x80060FBC
    // 0x80080800: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    Object_Kill(rdram, ctx);
        goto after_14;
    // 0x80080800: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_14:
L_80080804:
    // 0x80080804: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80080808: lw          $t7, -0x7B54($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7B54);
    // 0x8008080C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80080810: lwc1        $f14, 0x8($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80080814: bne         $t7, $at, L_80080854
    if (ctx->r15 != ctx->r1) {
        // 0x80080818: lui         $s0, 0x8017
        ctx->r16 = S32(0X8017 << 16);
            goto L_80080854;
    }
    // 0x80080818: lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // 0x8008081C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80080820: lwc1        $f18, 0x7D20($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x80080824: lwc1        $f10, 0xC($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80080828: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8008082C: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x80080830: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80080834: jal         0x801B6AEC
    // 0x80080838: nop

    Ground_801B6AEC(rdram, ctx);
        goto after_15;
    // 0x80080838: nop

    after_15:
    // 0x8008083C: beq         $v0, $zero, L_800808A8
    if (ctx->r2 == 0) {
        // 0x80080840: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800808A8;
    }
    // 0x80080840: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80080844: jal         0x80060FBC
    // 0x80080848: addiu       $a1, $s1, 0x80
    ctx->r5 = ADD32(ctx->r17, 0X80);
    Object_Kill(rdram, ctx);
        goto after_16;
    // 0x80080848: addiu       $a1, $s1, 0x80
    ctx->r5 = ADD32(ctx->r17, 0X80);
    after_16:
    // 0x8008084C: b           L_800808AC
    // 0x80080850: lwc1        $f10, 0x54($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X54);
        goto L_800808AC;
    // 0x80080850: lwc1        $f10, 0x54($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X54);
L_80080854:
    // 0x80080854: addiu       $s0, $s0, 0x7940
    ctx->r16 = ADD32(ctx->r16, 0X7940);
    // 0x80080858: lwc1        $f6, 0x0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8008085C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80080860: c.lt.s      $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f14.fl < ctx->f6.fl;
    // 0x80080864: nop

    // 0x80080868: bc1fl       L_800808AC
    if (!c1cs) {
        // 0x8008086C: lwc1        $f10, 0x54($s1)
        ctx->f10.u32l = MEM_W(ctx->r17, 0X54);
            goto L_800808AC;
    }
    goto skip_2;
    // 0x8008086C: lwc1        $f10, 0x54($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X54);
    skip_2:
    // 0x80080870: jal         0x80060FBC
    // 0x80080874: addiu       $a1, $s1, 0x80
    ctx->r5 = ADD32(ctx->r17, 0X80);
    Object_Kill(rdram, ctx);
        goto after_17;
    // 0x80080874: addiu       $a1, $s1, 0x80
    ctx->r5 = ADD32(ctx->r17, 0X80);
    after_17:
    // 0x80080878: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x8008087C: lw          $t8, 0x1A88($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1A88);
    // 0x80080880: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80080884: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x80080888: beql        $t8, $at, L_800808AC
    if (ctx->r24 == ctx->r1) {
        // 0x8008088C: lwc1        $f10, 0x54($s1)
        ctx->f10.u32l = MEM_W(ctx->r17, 0X54);
            goto L_800808AC;
    }
    goto skip_3;
    // 0x8008088C: lwc1        $f10, 0x54($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X54);
    skip_3:
    // 0x80080890: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80080894: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80080898: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    // 0x8008089C: swc1        $f8, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f8.u32l;
    // 0x800808A0: jal         0x8007D074
    // 0x800808A4: lwc1        $f14, 0x8($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X8);
    Effect_FireSmoke2_Spawn2(rdram, ctx);
        goto after_18;
    // 0x800808A4: lwc1        $f14, 0x8($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X8);
    after_18:
L_800808A8:
    // 0x800808A8: lwc1        $f10, 0x54($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X54);
L_800808AC:
    // 0x800808AC: addiu       $a0, $zero, 0x3E8
    ctx->r4 = ADD32(0, 0X3E8);
    // 0x800808B0: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    // 0x800808B4: swc1        $f10, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f10.u32l;
    // 0x800808B8: lwc1        $f18, 0x58($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X58);
    // 0x800808BC: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    // 0x800808C0: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x800808C4: swc1        $f18, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f18.u32l;
    // 0x800808C8: lwc1        $f4, 0x5C($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X5C);
    // 0x800808CC: jal         0x8006351C
    // 0x800808D0: swc1        $f4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f4.u32l;
    Object_CheckCollision(rdram, ctx);
        goto after_19;
    // 0x800808D0: swc1        $f4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f4.u32l;
    after_19:
    // 0x800808D4: beq         $v0, $zero, L_80080900
    if (ctx->r2 == 0) {
        // 0x800808D8: lui         $a3, 0x4000
        ctx->r7 = S32(0X4000 << 16);
            goto L_80080900;
    }
    // 0x800808D8: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x800808DC: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800808E0: lwc1        $f14, 0x8($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800808E4: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    // 0x800808E8: addiu       $t9, $s1, 0x80
    ctx->r25 = ADD32(ctx->r17, 0X80);
    // 0x800808EC: jal         0x8007D10C
    // 0x800808F0: sw          $t9, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r25;
    Effect_FireSmoke2_Spawn3(rdram, ctx);
        goto after_20;
    // 0x800808F0: sw          $t9, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r25;
    after_20:
    // 0x800808F4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800808F8: jal         0x80060FBC
    // 0x800808FC: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    Object_Kill(rdram, ctx);
        goto after_21;
    // 0x800808FC: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_21:
L_80080900:
    // 0x80080900: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x80080904: lw          $s0, -0x7D80($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X7D80);
L_80080908:
    // 0x80080908: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8008090C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80080910: jal         0x8007A774
    // 0x80080914: lui         $a2, 0x4248
    ctx->r6 = S32(0X4248 << 16);
    Effect_CheckPlayerCollision(rdram, ctx);
        goto after_22;
    // 0x80080914: lui         $a2, 0x4248
    ctx->r6 = S32(0X4248 << 16);
    after_22:
    // 0x80080918: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8008091C:
    // 0x8008091C: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80080920: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80080924: jr          $ra
    // 0x80080928: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x80080928: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void Item_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069F30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80069F34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80069F38: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80069F3C: lhu         $v0, 0x48($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X48);
    // 0x80069F40: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80069F44: beq         $v0, $zero, L_80069F50
    if (ctx->r2 == 0) {
        // 0x80069F48: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_80069F50;
    }
    // 0x80069F48: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80069F4C: sh          $t6, 0x48($a2)
    MEM_H(0X48, ctx->r6) = ctx->r14;
L_80069F50:
    // 0x80069F50: lhu         $v0, 0x4A($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X4A);
    // 0x80069F54: beq         $v0, $zero, L_80069F60
    if (ctx->r2 == 0) {
        // 0x80069F58: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_80069F60;
    }
    // 0x80069F58: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x80069F5C: sh          $t7, 0x4A($a2)
    MEM_H(0X4A, ctx->r6) = ctx->r15;
L_80069F60:
    // 0x80069F60: lbu         $v0, 0x0($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X0);
    // 0x80069F64: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80069F68: beq         $v0, $at, L_80069F80
    if (ctx->r2 == ctx->r1) {
        // 0x80069F6C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80069F80;
    }
    // 0x80069F6C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80069F70: beq         $v0, $at, L_80069FA4
    if (ctx->r2 == ctx->r1) {
        // 0x80069F74: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_80069FA4;
    }
    // 0x80069F74: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80069F78: b           L_80069FC8
    // 0x80069F7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80069FC8;
    // 0x80069F7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80069F80:
    // 0x80069F80: sb          $t8, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r24;
    // 0x80069F84: lw          $a0, 0x40($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X40);
    // 0x80069F88: lhu         $a1, 0x2($a2)
    ctx->r5 = MEM_HU(ctx->r6, 0X2);
    // 0x80069F8C: jal         0x80063F90
    // 0x80069F90: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    Object_Init(rdram, ctx);
        goto after_0;
    // 0x80069F90: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80069F94: jal         0x80069A10
    // 0x80069F98: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    Item_Move(rdram, ctx);
        goto after_1;
    // 0x80069F98: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80069F9C: b           L_80069FC8
    // 0x80069FA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80069FC8;
    // 0x80069FA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80069FA4:
    // 0x80069FA4: jal         0x80069A10
    // 0x80069FA8: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    Item_Move(rdram, ctx);
        goto after_2;
    // 0x80069FA8: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_2:
    // 0x80069FAC: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80069FB0: lw          $v0, 0x24($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X24);
    // 0x80069FB4: beql        $v0, $zero, L_80069FC8
    if (ctx->r2 == 0) {
        // 0x80069FB8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80069FC8;
    }
    goto skip_0;
    // 0x80069FB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80069FBC: jalr        $v0
    // 0x80069FC0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_3;
    // 0x80069FC0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_3:
    // 0x80069FC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80069FC8:
    // 0x80069FC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80069FCC: jr          $ra
    // 0x80069FD0: nop

    return;
    // 0x80069FD0: nop

;}
RECOMP_FUNC void AudioThread_ResetCmdQueue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E998: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x8001E99C: lbu         $t6, 0x7C50($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X7C50);
    // 0x8001E9A0: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8001E9A4: jr          $ra
    // 0x8001E9A8: sb          $t6, 0x7C54($at)
    MEM_B(0X7C54, ctx->r1) = ctx->r14;
    return;
    // 0x8001E9A8: sb          $t6, 0x7C54($at)
    MEM_B(0X7C54, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void func_enmy2_8006BF7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BF7C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8006BF80: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x8006BF84: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x8006BF88: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x8006BF8C: mtc1        $a2, $f24
    ctx->f24.u32l = ctx->r6;
    // 0x8006BF90: mov.s       $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    ctx->f20.fl = ctx->f12.fl;
    // 0x8006BF94: mov.s       $f22, $f14
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 14);
    ctx->f22.fl = ctx->f14.fl;
    // 0x8006BF98: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8006BF9C: sw          $s1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r17;
    // 0x8006BFA0: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    // 0x8006BFA4: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x8006BFA8: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x8006BFAC: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x8006BFB0: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    // 0x8006BFB4: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x8006BFB8: addiu       $s1, $s1, 0x30
    ctx->r17 = ADD32(ctx->r17, 0X30);
    // 0x8006BFBC: addiu       $s0, $s0, 0x1C
    ctx->r16 = ADD32(ctx->r16, 0X1C);
    // 0x8006BFC0: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
L_8006BFC4:
    // 0x8006BFC4: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x8006BFC8: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x8006BFCC: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    // 0x8006BFD0: jal         0x8006A900
    // 0x8006BFD4: add.s       $f12, $f4, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f20.fl;
    func_enmy2_8006A900(rdram, ctx);
        goto after_0;
    // 0x8006BFD4: add.s       $f12, $f4, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f20.fl;
    after_0:
    // 0x8006BFD8: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8006BFDC: bnel        $s0, $s1, L_8006BFC4
    if (ctx->r16 != ctx->r17) {
        // 0x8006BFE0: lwc1        $f4, 0x0($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
            goto L_8006BFC4;
    }
    goto skip_0;
    // 0x8006BFE0: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    skip_0:
    // 0x8006BFE4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8006BFE8: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x8006BFEC: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x8006BFF0: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x8006BFF4: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x8006BFF8: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x8006BFFC: lw          $s1, 0x38($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X38);
    // 0x8006C000: jr          $ra
    // 0x8006C004: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8006C004: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void Effect_DrawOnRails(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005E454: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8005E458: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8005E45C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8005E460: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8005E464: bgez        $a1, L_8005E488
    if (SIGNED(ctx->r5) >= 0) {
        // 0x8005E468: lui         $at, 0x40E0
        ctx->r1 = S32(0X40E0 << 16);
            goto L_8005E488;
    }
    // 0x8005E468: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x8005E46C: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8005E470: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8005E474: nop

    // 0x8005E478: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8005E47C: nop

    // 0x8005E480: bc1tl       L_8005E528
    if (c1cs) {
        // 0x8005E484: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8005E528;
    }
    goto skip_0;
    // 0x8005E484: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
L_8005E488:
    // 0x8005E488: lhu         $v0, 0x2($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X2);
    // 0x8005E48C: addiu       $at, $zero, 0x161
    ctx->r1 = ADD32(0, 0X161);
    // 0x8005E490: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005E494: beq         $v0, $at, L_8005E4A4
    if (ctx->r2 == ctx->r1) {
        // 0x8005E498: addiu       $at, $zero, 0x171
        ctx->r1 = ADD32(0, 0X171);
            goto L_8005E4A4;
    }
    // 0x8005E498: addiu       $at, $zero, 0x171
    ctx->r1 = ADD32(0, 0X171);
    // 0x8005E49C: bnel        $v0, $at, L_8005E4C4
    if (ctx->r2 != ctx->r1) {
        // 0x8005E4A0: lh          $t6, 0x30($s0)
        ctx->r14 = MEM_H(ctx->r16, 0X30);
            goto L_8005E4C4;
    }
    goto skip_1;
    // 0x8005E4A0: lh          $t6, 0x30($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X30);
    skip_1:
L_8005E4A4:
    // 0x8005E4A4: lw          $a1, 0x60($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X60);
    // 0x8005E4A8: lw          $a2, 0x64($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X64);
    // 0x8005E4AC: lw          $a3, 0x68($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X68);
    // 0x8005E4B0: jal         0x8005D3CC
    // 0x8005E4B4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    ObjSpecial_SetMatrix(rdram, ctx);
        goto after_0;
    // 0x8005E4B4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_0:
    // 0x8005E4B8: b           L_8005E514
    // 0x8005E4BC: lw          $v0, 0x1C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C);
        goto L_8005E514;
    // 0x8005E4BC: lw          $v0, 0x1C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C);
    // 0x8005E4C0: lh          $t6, 0x30($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X30);
L_8005E4C4:
    // 0x8005E4C4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8005E4C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005E4CC: bne         $t6, $at, L_8005E508
    if (ctx->r14 != ctx->r1) {
        // 0x8005E4D0: lui         $at, 0x8018
        ctx->r1 = S32(0X8018 << 16);
            goto L_8005E508;
    }
    // 0x8005E4D0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005E4D4: lwc1        $f10, -0x7B84($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X7B84);
    // 0x8005E4D8: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8005E4DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005E4E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005E4E4: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8005E4E8: jal         0x8005D008
    // 0x8005E4EC: swc1        $f16, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f16.u32l;
    Object_SetMatrix(rdram, ctx);
        goto after_1;
    // 0x8005E4EC: swc1        $f16, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f16.u32l;
    after_1:
    // 0x8005E4F0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005E4F4: lwc1        $f4, -0x7B84($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7B84);
    // 0x8005E4F8: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8005E4FC: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8005E500: b           L_8005E510
    // 0x8005E504: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
        goto L_8005E510;
    // 0x8005E504: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
L_8005E508:
    // 0x8005E508: jal         0x8005D008
    // 0x8005E50C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    Object_SetMatrix(rdram, ctx);
        goto after_2;
    // 0x8005E50C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
L_8005E510:
    // 0x8005E510: lw          $v0, 0x1C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C);
L_8005E514:
    // 0x8005E514: beql        $v0, $zero, L_8005E528
    if (ctx->r2 == 0) {
        // 0x8005E518: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8005E528;
    }
    goto skip_2;
    // 0x8005E518: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x8005E51C: jalr        $v0
    // 0x8005E520: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_3;
    // 0x8005E520: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8005E524: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8005E528:
    // 0x8005E528: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8005E52C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8005E530: jr          $ra
    // 0x8005E534: nop

    return;
    // 0x8005E534: nop

;}
RECOMP_FUNC void func_versus_800BCB44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BCB44: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800BCB48: sdc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X30, ctx->r29);
    // 0x800BCB4C: sdc1        $f24, 0x40($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X40, ctx->r29);
    // 0x800BCB50: sdc1        $f22, 0x38($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X38, ctx->r29);
    // 0x800BCB54: mtc1        $a2, $f20
    ctx->f20.u32l = ctx->r6;
    // 0x800BCB58: mov.s       $f22, $f12
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    ctx->f22.fl = ctx->f12.fl;
    // 0x800BCB5C: mov.s       $f24, $f14
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 14);
    ctx->f24.fl = ctx->f14.fl;
    // 0x800BCB60: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x800BCB64: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x800BCB68: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x800BCB6C: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x800BCB70: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x800BCB74: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x800BCB78: lui         $s1, 0x300
    ctx->r17 = S32(0X300 << 16);
    // 0x800BCB7C: lui         $s3, 0x300
    ctx->r19 = S32(0X300 << 16);
    // 0x800BCB80: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x800BCB84: addiu       $s2, $s2, 0x7E64
    ctx->r18 = ADD32(ctx->r18, 0X7E64);
    // 0x800BCB88: addiu       $s3, $s3, 0x7500
    ctx->r19 = ADD32(ctx->r19, 0X7500);
    // 0x800BCB8C: addiu       $s1, $s1, 0x6C60
    ctx->r17 = ADD32(ctx->r17, 0X6C60);
    // 0x800BCB90: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800BCB94: addiu       $s4, $zero, 0x10
    ctx->r20 = ADD32(0, 0X10);
L_800BCB98:
    // 0x800BCB98: mtc1        $s0, $f4
    ctx->f4.u32l = ctx->r16;
    // 0x800BCB9C: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x800BCBA0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800BCBA4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800BCBA8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800BCBAC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800BCBB0: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x800BCBB4: addiu       $a3, $zero, 0x60
    ctx->r7 = ADD32(0, 0X60);
    // 0x800BCBB8: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    // 0x800BCBBC: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x800BCBC0: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x800BCBC4: swc1        $f20, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f20.u32l;
    // 0x800BCBC8: add.s       $f10, $f8, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f24.fl;
    // 0x800BCBCC: jal         0x8009D0BC
    // 0x800BCBD0: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    Lib_TextureRect_CI8(rdram, ctx);
        goto after_0;
    // 0x800BCBD0: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    after_0:
    // 0x800BCBD4: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800BCBD8: bne         $s0, $s4, L_800BCB98
    if (ctx->r16 != ctx->r20) {
        // 0x800BCBDC: addiu       $s1, $s1, 0x300
        ctx->r17 = ADD32(ctx->r17, 0X300);
            goto L_800BCB98;
    }
    // 0x800BCBDC: addiu       $s1, $s1, 0x300
    ctx->r17 = ADD32(ctx->r17, 0X300);
    // 0x800BCBE0: mtc1        $s0, $f16
    ctx->f16.u32l = ctx->r16;
    // 0x800BCBE4: addiu       $t7, $zero, 0x7
    ctx->r15 = ADD32(0, 0X7);
    // 0x800BCBE8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800BCBEC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800BCBF0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800BCBF4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800BCBF8: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x800BCBFC: addiu       $a3, $zero, 0x60
    ctx->r7 = ADD32(0, 0X60);
    // 0x800BCC00: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    // 0x800BCC04: mul.s       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x800BCC08: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x800BCC0C: swc1        $f20, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f20.u32l;
    // 0x800BCC10: add.s       $f6, $f4, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f24.fl;
    // 0x800BCC14: jal         0x8009D0BC
    // 0x800BCC18: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    Lib_TextureRect_CI8(rdram, ctx);
        goto after_1;
    // 0x800BCC18: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x800BCC1C: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x800BCC20: ldc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X30);
    // 0x800BCC24: ldc1        $f22, 0x38($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X38);
    // 0x800BCC28: ldc1        $f24, 0x40($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X40);
    // 0x800BCC2C: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x800BCC30: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x800BCC34: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x800BCC38: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x800BCC3C: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x800BCC40: jr          $ra
    // 0x800BCC44: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x800BCC44: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_versus_800BECA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BECA8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800BECAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BECB0: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x800BECB4: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x800BECB8: addiu       $t7, $t7, 0x4BB0
    ctx->r15 = ADD32(ctx->r15, 0X4BB0);
    // 0x800BECBC: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x800BECC0: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x800BECC4: addiu       $t6, $sp, 0x30
    ctx->r14 = ADD32(ctx->r29, 0X30);
    // 0x800BECC8: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x800BECCC: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x800BECD0: lw          $t0, 0xC($t7)
    ctx->r8 = MEM_W(ctx->r15, 0XC);
    // 0x800BECD4: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x800BECD8: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x800BECDC: addiu       $t2, $t2, 0x4BC0
    ctx->r10 = ADD32(ctx->r10, 0X4BC0);
    // 0x800BECE0: sw          $t0, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r8;
    // 0x800BECE4: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x800BECE8: lw          $t5, 0x4($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X4);
    // 0x800BECEC: lw          $at, 0x0($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X0);
    // 0x800BECF0: addiu       $t1, $sp, 0x20
    ctx->r9 = ADD32(ctx->r29, 0X20);
    // 0x800BECF4: sw          $t5, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r13;
    // 0x800BECF8: sw          $at, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r1;
    // 0x800BECFC: lw          $at, 0x8($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X8);
    // 0x800BED00: lw          $t5, 0xC($t2)
    ctx->r13 = MEM_W(ctx->r10, 0XC);
    // 0x800BED04: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BED08: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x800BED0C: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    // 0x800BED10: sw          $at, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r1;
    // 0x800BED14: jal         0x800B8DD0
    // 0x800BED18: sw          $t5, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->r13;
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x800BED18: sw          $t5, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->r13;
    after_0:
    // 0x800BED1C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800BED20: addiu       $a1, $a1, 0x7E64
    ctx->r5 = ADD32(ctx->r5, 0X7E64);
    // 0x800BED24: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x800BED28: lui         $t6, 0xFF1E
    ctx->r14 = S32(0XFF1E << 16);
    // 0x800BED2C: ori         $t6, $t6, 0xFF
    ctx->r14 = ctx->r14 | 0XFF;
    // 0x800BED30: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x800BED34: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x800BED38: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x800BED3C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800BED40: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x800BED44: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800BED48: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x800BED4C: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x800BED50: addu        $t0, $sp, $t7
    ctx->r8 = ADD32(ctx->r29, ctx->r15);
    // 0x800BED54: addu        $t4, $sp, $t7
    ctx->r12 = ADD32(ctx->r29, ctx->r15);
    // 0x800BED58: lwc1        $f14, 0x20($t4)
    ctx->f14.u32l = MEM_W(ctx->r12, 0X20);
    // 0x800BED5C: lwc1        $f12, 0x30($t0)
    ctx->f12.u32l = MEM_W(ctx->r8, 0X30);
    // 0x800BED60: jal         0x800BC88C
    // 0x800BED64: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    func_versus_800BC88C(rdram, ctx);
        goto after_1;
    // 0x800BED64: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_1:
    // 0x800BED68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BED6C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x800BED70: jr          $ra
    // 0x800BED74: nop

    return;
    // 0x800BED74: nop

;}
RECOMP_FUNC void Actor_Load(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006168C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80061690: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80061694: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80061698: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8006169C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800616A0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x800616A4: jal         0x800613C4
    // 0x800616A8: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    Actor_Initialize(rdram, ctx);
        goto after_0;
    // 0x800616A8: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_0:
    // 0x800616AC: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x800616B0: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x800616B4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800616B8: sb          $t6, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r14;
    // 0x800616BC: lwc1        $f4, 0x0($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X0);
    // 0x800616C0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800616C4: addiu       $a0, $a2, 0x1C
    ctx->r4 = ADD32(ctx->r6, 0X1C);
    // 0x800616C8: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x800616CC: swc1        $f6, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f6.u32l;
    // 0x800616D0: lh          $t7, 0x4($a3)
    ctx->r15 = MEM_H(ctx->r7, 0X4);
    // 0x800616D4: lwc1        $f8, 0x6424($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6424);
    // 0x800616D8: lwc1        $f4, 0xC($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0XC);
    // 0x800616DC: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x800616E0: nop

    // 0x800616E4: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800616E8: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x800616EC: add.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x800616F0: swc1        $f6, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f6.u32l;
    // 0x800616F4: lh          $t8, 0x6($a3)
    ctx->r24 = MEM_H(ctx->r7, 0X6);
    // 0x800616F8: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x800616FC: nop

    // 0x80061700: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80061704: swc1        $f8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f8.u32l;
    // 0x80061708: lh          $t9, 0x8($a3)
    ctx->r25 = MEM_H(ctx->r7, 0X8);
    // 0x8006170C: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x80061710: nop

    // 0x80061714: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80061718: swc1        $f4, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f4.u32l;
    // 0x8006171C: lh          $t0, 0xC($a3)
    ctx->r8 = MEM_H(ctx->r7, 0XC);
    // 0x80061720: mtc1        $t0, $f18
    ctx->f18.u32l = ctx->r8;
    // 0x80061724: nop

    // 0x80061728: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8006172C: swc1        $f6, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->f6.u32l;
    // 0x80061730: lh          $t1, 0xA($a3)
    ctx->r9 = MEM_H(ctx->r7, 0XA);
    // 0x80061734: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x80061738: nop

    // 0x8006173C: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80061740: swc1        $f8, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->f8.u32l;
    // 0x80061744: lh          $t2, 0xE($a3)
    ctx->r10 = MEM_H(ctx->r7, 0XE);
    // 0x80061748: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x8006174C: nop

    // 0x80061750: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80061754: swc1        $f4, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->f4.u32l;
    // 0x80061758: lh          $t3, 0x10($a3)
    ctx->r11 = MEM_H(ctx->r7, 0X10);
    // 0x8006175C: sh          $t3, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r11;
    // 0x80061760: jal         0x800612B8
    // 0x80061764: andi        $a1, $t3, 0xFFFF
    ctx->r5 = ctx->r11 & 0XFFFF;
    Object_SetInfo(rdram, ctx);
        goto after_1;
    // 0x80061764: andi        $a1, $t3, 0xFFFF
    ctx->r5 = ctx->r11 & 0XFFFF;
    after_1:
    // 0x80061768: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006176C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80061770: jr          $ra
    // 0x80061774: nop

    return;
    // 0x80061774: nop

;}
RECOMP_FUNC void Effect_Effect357_Spawn50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800794CC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800794D0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800794D4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800794D8: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800794DC: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x800794E0: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800794E4: addiu       $v0, $v0, 0x130
    ctx->r2 = ADD32(ctx->r2, 0X130);
    // 0x800794E8: addiu       $a0, $a0, 0x1C88
    ctx->r4 = ADD32(ctx->r4, 0X1C88);
    // 0x800794EC: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
L_800794F0:
    // 0x800794F0: bnel        $t6, $zero, L_80079520
    if (ctx->r14 != 0) {
        // 0x800794F4: addiu       $a0, $a0, -0x8C
        ctx->r4 = ADD32(ctx->r4, -0X8C);
            goto L_80079520;
    }
    goto skip_0;
    // 0x800794F4: addiu       $a0, $a0, -0x8C
    ctx->r4 = ADD32(ctx->r4, -0X8C);
    skip_0:
    // 0x800794F8: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800794FC: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x80079500: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x80079504: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80079508: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8007950C: jal         0x8007905C
    // 0x80079510: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Effect_Effect357_Setup(rdram, ctx);
        goto after_0;
    // 0x80079510: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x80079514: b           L_80079530
    // 0x80079518: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80079530;
    // 0x80079518: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007951C: addiu       $a0, $a0, -0x8C
    ctx->r4 = ADD32(ctx->r4, -0X8C);
L_80079520:
    // 0x80079520: sltu        $at, $a0, $v0
    ctx->r1 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x80079524: beql        $at, $zero, L_800794F0
    if (ctx->r1 == 0) {
        // 0x80079528: lbu         $t6, 0x0($a0)
        ctx->r14 = MEM_BU(ctx->r4, 0X0);
            goto L_800794F0;
    }
    goto skip_1;
    // 0x80079528: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    skip_1:
    // 0x8007952C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80079530:
    // 0x80079530: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80079534: jr          $ra
    // 0x80079538: nop

    return;
    // 0x80079538: nop

;}
RECOMP_FUNC void ActorTeamBoss_SlippyEscapeFromTiBoss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80090A00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80090A04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80090A08: lw          $t6, 0x64($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X64);
    // 0x80090A0C: sltiu       $at, $t6, 0x6
    ctx->r1 = ctx->r14 < 0X6 ? 1 : 0;
    // 0x80090A10: beq         $at, $zero, L_80090CB8
    if (ctx->r1 == 0) {
        // 0x80090A14: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80090CB8;
    }
    // 0x80090A14: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80090A18: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80090A1C: addu        $at, $at, $t6
    gpr jr_addend_80090A24 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80090A20: lw          $t6, 0x7F08($at)
    ctx->r14 = ADD32(ctx->r1, 0X7F08);
    // 0x80090A24: jr          $t6
    // 0x80090A28: nop

    switch (jr_addend_80090A24 >> 2) {
        case 0: goto L_80090A2C; break;
        case 1: goto L_80090A70; break;
        case 2: goto L_80090AEC; break;
        case 3: goto L_80090B68; break;
        case 4: goto L_80090BD0; break;
        case 5: goto L_80090C68; break;
        default: switch_error(__func__, 0x80090A24, 0x800D7F08);
    }
    // 0x80090A28: nop

L_80090A2C:
    // 0x80090A2C: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80090A30: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80090A34: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80090A38: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80090A3C: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80090A40: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80090A44: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80090A48: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x80090A4C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80090A50: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80090A54: sh          $t7, 0xBC($a0)
    MEM_H(0XBC, ctx->r4) = ctx->r15;
    // 0x80090A58: sw          $t8, 0x60($a0)
    MEM_W(0X60, ctx->r4) = ctx->r24;
    // 0x80090A5C: sw          $t9, 0x64($a0)
    MEM_W(0X64, ctx->r4) = ctx->r25;
    // 0x80090A60: swc1        $f6, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->f6.u32l;
    // 0x80090A64: swc1        $f8, 0xF8($a0)
    MEM_W(0XF8, ctx->r4) = ctx->f8.u32l;
    // 0x80090A68: swc1        $f4, 0x134($a0)
    MEM_W(0X134, ctx->r4) = ctx->f4.u32l;
    // 0x80090A6C: swc1        $f10, 0xF4($a0)
    MEM_W(0XF4, ctx->r4) = ctx->f10.u32l;
L_80090A70:
    // 0x80090A70: lhu         $t0, 0xBC($a0)
    ctx->r8 = MEM_HU(ctx->r4, 0XBC);
    // 0x80090A74: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80090A78: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80090A7C: mtc1        $t0, $f18
    ctx->f18.u32l = ctx->r8;
    // 0x80090A80: addiu       $t1, $zero, 0x24
    ctx->r9 = ADD32(0, 0X24);
    // 0x80090A84: bgez        $t0, L_80090A98
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80090A88: cvt.s.w     $f4, $f18
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
            goto L_80090A98;
    }
    // 0x80090A88: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80090A8C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80090A90: nop

    // 0x80090A94: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_80090A98:
    // 0x80090A98: c.eq.s      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.fl == ctx->f4.fl;
    // 0x80090A9C: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80090AA0: bc1fl       L_80090AD8
    if (!c1cs) {
        // 0x80090AA4: lwc1        $f18, 0x8($a0)
        ctx->f18.u32l = MEM_W(ctx->r4, 0X8);
            goto L_80090AD8;
    }
    goto skip_0;
    // 0x80090AA4: lwc1        $f18, 0x8($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X8);
    skip_0:
    // 0x80090AA8: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80090AAC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80090AB0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80090AB4: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x80090AB8: swc1        $f8, 0x118($a0)
    MEM_W(0X118, ctx->r4) = ctx->f8.u32l;
    // 0x80090ABC: lwc1        $f10, 0x7F20($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7F20);
    // 0x80090AC0: sw          $zero, 0x58($a0)
    MEM_W(0X58, ctx->r4) = 0;
    // 0x80090AC4: sw          $t1, 0x5C($a0)
    MEM_W(0X5C, ctx->r4) = ctx->r9;
    // 0x80090AC8: sw          $t2, 0x64($a0)
    MEM_W(0X64, ctx->r4) = ctx->r10;
    // 0x80090ACC: b           L_80090AEC
    // 0x80090AD0: swc1        $f10, 0x120($a0)
    MEM_W(0X120, ctx->r4) = ctx->f10.u32l;
        goto L_80090AEC;
    // 0x80090AD0: swc1        $f10, 0x120($a0)
    MEM_W(0X120, ctx->r4) = ctx->f10.u32l;
    // 0x80090AD4: lwc1        $f18, 0x8($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X8);
L_80090AD8:
    // 0x80090AD8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80090ADC: nop

    // 0x80090AE0: sub.s       $f16, $f18, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x80090AE4: b           L_80090CB8
    // 0x80090AE8: swc1        $f16, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f16.u32l;
        goto L_80090CB8;
    // 0x80090AE8: swc1        $f16, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f16.u32l;
L_80090AEC:
    // 0x80090AEC: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80090AF0: addiu       $v1, $v1, -0xEF0
    ctx->r3 = ADD32(ctx->r3, -0XEF0);
    // 0x80090AF4: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80090AF8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80090AFC: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80090B00: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80090B04: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80090B08: add.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80090B0C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80090B10: swc1        $f10, 0x128($a0)
    MEM_W(0X128, ctx->r4) = ctx->f10.u32l;
    // 0x80090B14: lwc1        $f18, 0xC($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80090B18: swc1        $f8, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->f8.u32l;
    // 0x80090B1C: lwc1        $f6, 0x7F24($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7F24);
    // 0x80090B20: lw          $t3, 0x58($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X58);
    // 0x80090B24: lw          $t5, 0x5C($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X5C);
    // 0x80090B28: sub.s       $f16, $f18, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x80090B2C: addiu       $v0, $t3, 0x1
    ctx->r2 = ADD32(ctx->r11, 0X1);
    // 0x80090B30: sw          $v0, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->r2;
    // 0x80090B34: bne         $v0, $t5, L_80090B54
    if (ctx->r2 != ctx->r13) {
        // 0x80090B38: swc1        $f16, 0x12C($a0)
        MEM_W(0X12C, ctx->r4) = ctx->f16.u32l;
            goto L_80090B54;
    }
    // 0x80090B38: swc1        $f16, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->f16.u32l;
    // 0x80090B3C: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x80090B40: addiu       $t7, $zero, 0x28
    ctx->r15 = ADD32(0, 0X28);
    // 0x80090B44: sw          $t6, 0x64($a0)
    MEM_W(0X64, ctx->r4) = ctx->r14;
    // 0x80090B48: sw          $t7, 0x5C($a0)
    MEM_W(0X5C, ctx->r4) = ctx->r15;
    // 0x80090B4C: b           L_80090CB8
    // 0x80090B50: sw          $zero, 0x58($a0)
    MEM_W(0X58, ctx->r4) = 0;
        goto L_80090CB8;
    // 0x80090B50: sw          $zero, 0x58($a0)
    MEM_W(0X58, ctx->r4) = 0;
L_80090B54:
    // 0x80090B54: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80090B58: bne         $v0, $at, L_80090CB8
    if (ctx->r2 != ctx->r1) {
        // 0x80090B5C: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_80090CB8;
    }
    // 0x80090B5C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80090B60: b           L_80090CB8
    // 0x80090B64: sw          $t8, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->r24;
        goto L_80090CB8;
    // 0x80090B64: sw          $t8, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->r24;
L_80090B68:
    // 0x80090B68: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80090B6C: addiu       $v1, $v1, -0xEF0
    ctx->r3 = ADD32(ctx->r3, -0XEF0);
    // 0x80090B70: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80090B74: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80090B78: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80090B7C: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x80090B80: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80090B84: sub.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x80090B88: lw          $t9, 0x58($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X58);
    // 0x80090B8C: lw          $t1, 0x5C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X5C);
    // 0x80090B90: swc1        $f10, 0x128($a0)
    MEM_W(0X128, ctx->r4) = ctx->f10.u32l;
    // 0x80090B94: swc1        $f8, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->f8.u32l;
    // 0x80090B98: lwc1        $f18, 0xC($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80090B9C: addiu       $v0, $t9, 0x1
    ctx->r2 = ADD32(ctx->r25, 0X1);
    // 0x80090BA0: sw          $v0, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->r2;
    // 0x80090BA4: bne         $v0, $t1, L_80090BB8
    if (ctx->r2 != ctx->r9) {
        // 0x80090BA8: swc1        $f18, 0x12C($a0)
        MEM_W(0X12C, ctx->r4) = ctx->f18.u32l;
            goto L_80090BB8;
    }
    // 0x80090BA8: swc1        $f18, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->f18.u32l;
    // 0x80090BAC: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x80090BB0: b           L_80090CB8
    // 0x80090BB4: sw          $t2, 0x64($a0)
    MEM_W(0X64, ctx->r4) = ctx->r10;
        goto L_80090CB8;
    // 0x80090BB4: sw          $t2, 0x64($a0)
    MEM_W(0X64, ctx->r4) = ctx->r10;
L_80090BB8:
    // 0x80090BB8: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x80090BBC: bne         $v0, $at, L_80090CB8
    if (ctx->r2 != ctx->r1) {
        // 0x80090BC0: lui         $at, 0x41F0
        ctx->r1 = S32(0X41F0 << 16);
            goto L_80090CB8;
    }
    // 0x80090BC0: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80090BC4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80090BC8: b           L_80090CB8
    // 0x80090BCC: swc1        $f6, 0x118($a0)
    MEM_W(0X118, ctx->r4) = ctx->f6.u32l;
        goto L_80090CB8;
    // 0x80090BCC: swc1        $f6, 0x118($a0)
    MEM_W(0X118, ctx->r4) = ctx->f6.u32l;
L_80090BD0:
    // 0x80090BD0: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x80090BD4: addiu       $v1, $v1, -0x7D80
    ctx->r3 = ADD32(ctx->r3, -0X7D80);
    // 0x80090BD8: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x80090BDC: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80090BE0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80090BE4: lwc1        $f16, 0x138($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0X138);
    // 0x80090BE8: lwc1        $f10, 0x4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80090BEC: swc1        $f4, 0x128($a0)
    MEM_W(0X128, ctx->r4) = ctx->f4.u32l;
    // 0x80090BF0: swc1        $f16, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->f16.u32l;
    // 0x80090BF4: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x80090BF8: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80090BFC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80090C00: lwc1        $f8, 0x74($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X74);
    // 0x80090C04: swc1        $f8, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->f8.u32l;
    // 0x80090C08: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80090C0C: lwc1        $f18, 0x74($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X74);
    // 0x80090C10: sub.s       $f0, $f10, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x80090C14: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80090C18: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80090C1C: nop

    // 0x80090C20: bc1fl       L_80090CBC
    if (!c1cs) {
        // 0x80090C24: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80090CBC;
    }
    goto skip_1;
    // 0x80090C24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x80090C28: lwc1        $f16, 0xC($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80090C2C: lwc1        $f4, 0x138($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X138);
    // 0x80090C30: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80090C34: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80090C38: sub.s       $f0, $f16, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x80090C3C: addiu       $t5, $zero, 0x5
    ctx->r13 = ADD32(0, 0X5);
    // 0x80090C40: addiu       $t6, $zero, 0x14
    ctx->r14 = ADD32(0, 0X14);
    // 0x80090C44: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80090C48: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80090C4C: nop

    // 0x80090C50: bc1fl       L_80090CBC
    if (!c1cs) {
        // 0x80090C54: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80090CBC;
    }
    goto skip_2;
    // 0x80090C54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
    // 0x80090C58: sw          $t5, 0x64($a0)
    MEM_W(0X64, ctx->r4) = ctx->r13;
    // 0x80090C5C: sw          $t6, 0x5C($a0)
    MEM_W(0X5C, ctx->r4) = ctx->r14;
    // 0x80090C60: b           L_80090CB8
    // 0x80090C64: sw          $zero, 0x58($a0)
    MEM_W(0X58, ctx->r4) = 0;
        goto L_80090CB8;
    // 0x80090C64: sw          $zero, 0x58($a0)
    MEM_W(0X58, ctx->r4) = 0;
L_80090C68:
    // 0x80090C68: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x80090C6C: addiu       $v1, $v1, -0x7D80
    ctx->r3 = ADD32(ctx->r3, -0X7D80);
    // 0x80090C70: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80090C74: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80090C78: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80090C7C: lwc1        $f10, 0x138($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X138);
    // 0x80090C80: lw          $t9, 0x58($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X58);
    // 0x80090C84: swc1        $f0, 0x128($a0)
    MEM_W(0X128, ctx->r4) = ctx->f0.u32l;
    // 0x80090C88: add.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x80090C8C: lw          $t2, 0x5C($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X5C);
    // 0x80090C90: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80090C94: swc1        $f18, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->f18.u32l;
    // 0x80090C98: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x80090C9C: lwc1        $f6, 0x74($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X74);
    // 0x80090CA0: sw          $t0, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->r8;
    // 0x80090CA4: sub.s       $f16, $f6, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x80090CA8: bne         $t0, $t2, L_80090CB8
    if (ctx->r8 != ctx->r10) {
        // 0x80090CAC: swc1        $f16, 0x124($a0)
        MEM_W(0X124, ctx->r4) = ctx->f16.u32l;
            goto L_80090CB8;
    }
    // 0x80090CAC: swc1        $f16, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->f16.u32l;
    // 0x80090CB0: jal         0x80060FBC
    // 0x80090CB4: addiu       $a1, $a0, 0x100
    ctx->r5 = ADD32(ctx->r4, 0X100);
    Object_Kill(rdram, ctx);
        goto after_0;
    // 0x80090CB4: addiu       $a1, $a0, 0x100
    ctx->r5 = ADD32(ctx->r4, 0X100);
    after_0:
L_80090CB8:
    // 0x80090CB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80090CBC:
    // 0x80090CBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80090CC0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80090CC4: jr          $ra
    // 0x80090CC8: nop

    return;
    // 0x80090CC8: nop

;}
RECOMP_FUNC void HUD_DrawStatusScreens(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008865C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80088660: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80088664: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x80088668: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8008866C: addiu       $a0, $a0, 0x17FC
    ctx->r4 = ADD32(ctx->r4, 0X17FC);
    // 0x80088670: addiu       $v0, $v0, 0x17E8
    ctx->r2 = ADD32(ctx->r2, 0X17E8);
    // 0x80088674: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
L_80088678:
    // 0x80088678: beq         $v1, $zero, L_80088684
    if (ctx->r3 == 0) {
        // 0x8008867C: addiu       $t6, $v1, -0x1
        ctx->r14 = ADD32(ctx->r3, -0X1);
            goto L_80088684;
    }
    // 0x8008867C: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x80088680: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
L_80088684:
    // 0x80088684: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80088688: bnel        $v0, $a0, L_80088678
    if (ctx->r2 != ctx->r4) {
        // 0x8008868C: lw          $v1, 0x0($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X0);
            goto L_80088678;
    }
    goto skip_0;
    // 0x8008868C: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    skip_0:
    // 0x80088690: jal         0x80086CC8
    // 0x80088694: nop

    HUD_DrawLevelStartStatusScreen(rdram, ctx);
        goto after_0;
    // 0x80088694: nop

    after_0:
    // 0x80088698: jal         0x80086DCC
    // 0x8008869C: nop

    HUD_DrawLevelClearScreen(rdram, ctx);
        goto after_1;
    // 0x8008869C: nop

    after_1:
    // 0x800886A0: jal         0x80087B5C
    // 0x800886A4: nop

    HUD_LevelClearStatusScreen_Draw(rdram, ctx);
        goto after_2;
    // 0x800886A4: nop

    after_2:
    // 0x800886A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800886AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800886B0: jr          $ra
    // 0x800886B4: nop

    return;
    // 0x800886B4: nop

;}
RECOMP_FUNC void func_enmy_80061A4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80061A4C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80061A50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80061A54: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80061A58: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80061A5C: addiu       $v0, $v0, 0x37E0
    ctx->r2 = ADD32(ctx->r2, 0X37E0);
    // 0x80061A60: addiu       $a0, $a0, 0x130
    ctx->r4 = ADD32(ctx->r4, 0X130);
    // 0x80061A64: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
L_80061A68:
    // 0x80061A68: bnel        $t6, $zero, L_80061B50
    if (ctx->r14 != 0) {
        // 0x80061A6C: addiu       $a0, $a0, 0x8C
        ctx->r4 = ADD32(ctx->r4, 0X8C);
            goto L_80061B50;
    }
    goto skip_0;
    // 0x80061A6C: addiu       $a0, $a0, 0x8C
    ctx->r4 = ADD32(ctx->r4, 0X8C);
    skip_0:
    // 0x80061A70: jal         0x80004EB0
    // 0x80061A74: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    Rand_ZeroOne(rdram, ctx);
        goto after_0;
    // 0x80061A74: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80061A78: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80061A7C: lw          $v0, -0x7D80($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D80);
    // 0x80061A80: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80061A84: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80061A88: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80061A8C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80061A90: lwc1        $f4, 0xC0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC0);
    // 0x80061A94: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x80061A98: sub.s       $f18, $f0, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x80061A9C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80061AA0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80061AA4: lwc1        $f10, 0x74($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X74);
    // 0x80061AA8: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80061AAC: add.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80061AB0: add.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x80061AB4: jal         0x80004EB0
    // 0x80061AB8: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x80061AB8: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80061ABC: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x80061AC0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80061AC4: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80061AC8: lw          $v0, -0x7D80($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D80);
    // 0x80061ACC: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80061AD0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80061AD4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80061AD8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80061ADC: lwc1        $f10, 0xC4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC4);
    // 0x80061AE0: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x80061AE4: sub.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x80061AE8: mul.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x80061AEC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80061AF0: lwc1        $f18, 0x78($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X78);
    // 0x80061AF4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80061AF8: mul.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x80061AFC: lwc1        $f12, 0x7D20($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x80061B00: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80061B04: lwc1        $f10, 0x7D08($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7D08);
    // 0x80061B08: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    // 0x80061B0C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80061B10: sub.s       $f2, $f12, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f12.fl - ctx->f16.fl;
    // 0x80061B14: add.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x80061B18: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80061B1C: nop

    // 0x80061B20: c.lt.s      $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f10.fl < ctx->f18.fl;
    // 0x80061B24: add.s       $f14, $f8, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80061B28: bc1fl       L_80061B38
    if (!c1cs) {
        // 0x80061B2C: mfc1        $a2, $f14
        ctx->r6 = (int32_t)ctx->f14.u32l;
            goto L_80061B38;
    }
    goto skip_1;
    // 0x80061B2C: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    skip_1:
    // 0x80061B30: add.s       $f2, $f12, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f12.fl + ctx->f16.fl;
    // 0x80061B34: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
L_80061B38:
    // 0x80061B38: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80061B3C: jal         0x80061958
    // 0x80061B40: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    Effect_SmallRock_Setup(rdram, ctx);
        goto after_2;
    // 0x80061B40: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x80061B44: b           L_80061B5C
    // 0x80061B48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80061B5C;
    // 0x80061B48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80061B4C: addiu       $a0, $a0, 0x8C
    ctx->r4 = ADD32(ctx->r4, 0X8C);
L_80061B50:
    // 0x80061B50: bnel        $a0, $v0, L_80061A68
    if (ctx->r4 != ctx->r2) {
        // 0x80061B54: lbu         $t6, 0x0($a0)
        ctx->r14 = MEM_BU(ctx->r4, 0X0);
            goto L_80061A68;
    }
    goto skip_2;
    // 0x80061B54: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    skip_2:
    // 0x80061B58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80061B5C:
    // 0x80061B5C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80061B60: jr          $ra
    // 0x80061B64: nop

    return;
    // 0x80061B64: nop

;}
RECOMP_FUNC void Display_OnFootMuzzleFlash(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80052584: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80052588: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8005258C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80052590: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80052594: jal         0x80005708
    // 0x80052598: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Push(rdram, ctx);
        goto after_0;
    // 0x80052598: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_0:
    // 0x8005259C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800525A0: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x800525A4: addiu       $a1, $a1, 0x4660
    ctx->r5 = ADD32(ctx->r5, 0X4660);
    // 0x800525A8: jal         0x80005680
    // 0x800525AC: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Copy(rdram, ctx);
        goto after_1;
    // 0x800525AC: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_1:
    // 0x800525B0: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x800525B4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800525B8: lw          $t6, 0x1C8($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X1C8);
    // 0x800525BC: bne         $t6, $at, L_8005269C
    if (ctx->r14 != ctx->r1) {
        // 0x800525C0: nop
    
            goto L_8005269C;
    }
    // 0x800525C0: nop

    // 0x800525C4: lw          $t7, 0x1F8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X1F8);
    // 0x800525C8: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x800525CC: addiu       $t0, $t0, 0x13B0
    ctx->r8 = ADD32(ctx->r8, 0X13B0);
    // 0x800525D0: beq         $t7, $zero, L_8005269C
    if (ctx->r15 == 0) {
        // 0x800525D4: lui         $a0, 0x8014
        ctx->r4 = S32(0X8014 << 16);
            goto L_8005269C;
    }
    // 0x800525D4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800525D8: lw          $t8, 0x1C4($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X1C4);
    // 0x800525DC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800525E0: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x800525E4: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800525E8: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x800525EC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800525F0: addu        $v0, $t9, $t0
    ctx->r2 = ADD32(ctx->r25, ctx->r8);
    // 0x800525F4: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x800525F8: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    // 0x800525FC: lw          $a3, 0x8($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X8);
    // 0x80052600: jal         0x80005B00
    // 0x80052604: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Translate(rdram, ctx);
        goto after_2;
    // 0x80052604: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_2:
    // 0x80052608: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8005260C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80052610: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80052614: lw          $t3, 0x1F8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X1F8);
    // 0x80052618: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8005261C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80052620: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80052624: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x80052628: lwc1        $f0, -0x5DC8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5DC8);
    // 0x8005262C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80052630: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80052634: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80052638: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8005263C: jal         0x80005C34
    // 0x80052640: nop

    Matrix_Scale(rdram, ctx);
        goto after_3;
    // 0x80052640: nop

    after_3:
    // 0x80052644: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80052648: jal         0x80006EB8
    // 0x8005264C: addiu       $a0, $a1, 0x7E64
    ctx->r4 = ADD32(ctx->r5, 0X7E64);
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_4;
    // 0x8005264C: addiu       $a0, $a1, 0x7E64
    ctx->r4 = ADD32(ctx->r5, 0X7E64);
    after_4:
    // 0x80052650: jal         0x800B99C0
    // 0x80052654: nop

    RCP_SetupDL_40(rdram, ctx);
        goto after_5;
    // 0x80052654: nop

    after_5:
    // 0x80052658: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8005265C: addiu       $a1, $a1, 0x7E64
    ctx->r5 = ADD32(ctx->r5, 0X7E64);
    // 0x80052660: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80052664: lui         $t7, 0xB600
    ctx->r15 = S32(0XB600 << 16);
    // 0x80052668: addiu       $t8, $zero, 0x2000
    ctx->r24 = ADD32(0, 0X2000);
    // 0x8005266C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80052670: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x80052674: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80052678: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8005267C: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80052680: lui         $t1, 0x303
    ctx->r9 = S32(0X303 << 16);
    // 0x80052684: addiu       $t1, $t1, -0x2DC0
    ctx->r9 = ADD32(ctx->r9, -0X2DC0);
    // 0x80052688: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8005268C: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x80052690: lui         $t0, 0x600
    ctx->r8 = S32(0X600 << 16);
    // 0x80052694: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x80052698: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
L_8005269C:
    // 0x8005269C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800526A0: jal         0x80005740
    // 0x800526A4: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Pop(rdram, ctx);
        goto after_6;
    // 0x800526A4: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_6:
    // 0x800526A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800526AC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800526B0: jr          $ra
    // 0x800526B4: nop

    return;
    // 0x800526B4: nop

;}
RECOMP_FUNC void Player_CheckBounds360(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AE278: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x800AE27C: lw          $t6, 0x78A8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X78A8);
    // 0x800AE280: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800AE284: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800AE288: beq         $t6, $at, L_800AE3E4
    if (ctx->r14 == ctx->r1) {
        // 0x800AE28C: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_800AE3E4;
    }
    // 0x800AE28C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AE290: lwc1        $f2, -0x7978($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X7978);
    // 0x800AE294: lwc1        $f0, 0x74($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X74);
    // 0x800AE298: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AE29C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800AE2A0: nop

    // 0x800AE2A4: bc1f        L_800AE2D8
    if (!c1cs) {
        // 0x800AE2A8: nop
    
            goto L_800AE2D8;
    }
    // 0x800AE2A8: nop

    // 0x800AE2AC: lwc1        $f12, -0x7974($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X7974);
    // 0x800AE2B0: lwc1        $f6, 0x40($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X40);
    // 0x800AE2B4: lwc1        $f10, 0x4C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X4C);
    // 0x800AE2B8: sub.s       $f4, $f0, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x800AE2BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800AE2C0: sub.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f12.fl;
    // 0x800AE2C4: swc1        $f4, 0x74($a0)
    MEM_W(0X74, ctx->r4) = ctx->f4.u32l;
    // 0x800AE2C8: lwc1        $f0, 0x74($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X74);
    // 0x800AE2CC: sub.s       $f16, $f10, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f12.fl;
    // 0x800AE2D0: swc1        $f8, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f8.u32l;
    // 0x800AE2D4: swc1        $f16, 0x4C($a0)
    MEM_W(0X4C, ctx->r4) = ctx->f16.u32l;
L_800AE2D8:
    // 0x800AE2D8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AE2DC: lwc1        $f12, -0x7970($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X7970);
    // 0x800AE2E0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AE2E4: lwc1        $f14, -0x796C($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X796C);
    // 0x800AE2E8: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x800AE2EC: nop

    // 0x800AE2F0: bc1fl       L_800AE320
    if (!c1cs) {
        // 0x800AE2F4: lwc1        $f0, 0x7C($a0)
        ctx->f0.u32l = MEM_W(ctx->r4, 0X7C);
            goto L_800AE320;
    }
    goto skip_0;
    // 0x800AE2F4: lwc1        $f0, 0x7C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X7C);
    skip_0:
    // 0x800AE2F8: lwc1        $f4, 0x40($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X40);
    // 0x800AE2FC: lwc1        $f8, 0x4C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X4C);
    // 0x800AE300: add.s       $f18, $f0, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f12.fl;
    // 0x800AE304: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800AE308: add.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x800AE30C: swc1        $f18, 0x74($a0)
    MEM_W(0X74, ctx->r4) = ctx->f18.u32l;
    // 0x800AE310: add.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f12.fl;
    // 0x800AE314: swc1        $f6, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f6.u32l;
    // 0x800AE318: swc1        $f10, 0x4C($a0)
    MEM_W(0X4C, ctx->r4) = ctx->f10.u32l;
    // 0x800AE31C: lwc1        $f0, 0x7C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X7C);
L_800AE320:
    // 0x800AE320: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800AE324: nop

    // 0x800AE328: bc1fl       L_800AE35C
    if (!c1cs) {
        // 0x800AE32C: c.lt.s      $f0, $f14
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
            goto L_800AE35C;
    }
    goto skip_1;
    // 0x800AE32C: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    skip_1:
    // 0x800AE330: lwc1        $f18, 0x48($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X48);
    // 0x800AE334: lwc1        $f6, 0x54($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X54);
    // 0x800AE338: sub.s       $f16, $f0, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x800AE33C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800AE340: sub.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f12.fl;
    // 0x800AE344: swc1        $f16, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->f16.u32l;
    // 0x800AE348: lwc1        $f0, 0x7C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X7C);
    // 0x800AE34C: sub.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f12.fl;
    // 0x800AE350: swc1        $f4, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f4.u32l;
    // 0x800AE354: swc1        $f8, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f8.u32l;
    // 0x800AE358: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
L_800AE35C:
    // 0x800AE35C: nop

    // 0x800AE360: bc1f        L_800AE38C
    if (!c1cs) {
        // 0x800AE364: nop
    
            goto L_800AE38C;
    }
    // 0x800AE364: nop

    // 0x800AE368: lwc1        $f16, 0x48($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X48);
    // 0x800AE36C: lwc1        $f4, 0x54($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X54);
    // 0x800AE370: add.s       $f10, $f0, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f12.fl;
    // 0x800AE374: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800AE378: add.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f12.fl;
    // 0x800AE37C: swc1        $f10, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->f10.u32l;
    // 0x800AE380: add.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x800AE384: swc1        $f18, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f18.u32l;
    // 0x800AE388: swc1        $f6, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f6.u32l;
L_800AE38C:
    // 0x800AE38C: beq         $v0, $zero, L_800AE49C
    if (ctx->r2 == 0) {
        // 0x800AE390: nop
    
            goto L_800AE49C;
    }
    // 0x800AE390: nop

    // 0x800AE394: lw          $t7, 0x1C4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1C4);
    // 0x800AE398: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x800AE39C: addiu       $a1, $a1, 0x7B00
    ctx->r5 = ADD32(ctx->r5, 0X7B00);
    // 0x800AE3A0: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x800AE3A4: addu        $t9, $a1, $t8
    ctx->r25 = ADD32(ctx->r5, ctx->r24);
    // 0x800AE3A8: sw          $zero, 0xC($t9)
    MEM_W(0XC, ctx->r25) = 0;
    // 0x800AE3AC: lw          $t0, 0x1C4($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X1C4);
    // 0x800AE3B0: sll         $t1, $t0, 4
    ctx->r9 = S32(ctx->r8 << 4);
    // 0x800AE3B4: addu        $v0, $a1, $t1
    ctx->r2 = ADD32(ctx->r5, ctx->r9);
    // 0x800AE3B8: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x800AE3BC: sw          $v1, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r3;
    // 0x800AE3C0: lw          $t2, 0x1C4($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X1C4);
    // 0x800AE3C4: sll         $t3, $t2, 4
    ctx->r11 = S32(ctx->r10 << 4);
    // 0x800AE3C8: addu        $t4, $a1, $t3
    ctx->r12 = ADD32(ctx->r5, ctx->r11);
    // 0x800AE3CC: sw          $v1, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r3;
    // 0x800AE3D0: lw          $t5, 0x1C4($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X1C4);
    // 0x800AE3D4: sll         $t6, $t5, 4
    ctx->r14 = S32(ctx->r13 << 4);
    // 0x800AE3D8: addu        $t7, $a1, $t6
    ctx->r15 = ADD32(ctx->r5, ctx->r14);
    // 0x800AE3DC: jr          $ra
    // 0x800AE3E0: sw          $v1, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r3;
    return;
    // 0x800AE3E0: sw          $v1, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r3;
L_800AE3E4:
    // 0x800AE3E4: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800AE3E8: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
    // 0x800AE3EC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AE3F0: lwc1        $f2, -0x7968($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X7968);
    // 0x800AE3F4: bne         $v0, $zero, L_800AE40C
    if (ctx->r2 != 0) {
        // 0x800AE3F8: addiu       $at, $zero, 0x11
        ctx->r1 = ADD32(0, 0X11);
            goto L_800AE40C;
    }
    // 0x800AE3F8: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x800AE3FC: lui         $at, 0x45FA
    ctx->r1 = S32(0X45FA << 16);
    // 0x800AE400: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800AE404: b           L_800AE454
    // 0x800AE408: lwc1        $f0, 0x74($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X74);
        goto L_800AE454;
    // 0x800AE408: lwc1        $f0, 0x74($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X74);
L_800AE40C:
    // 0x800AE40C: bne         $v0, $at, L_800AE41C
    if (ctx->r2 != ctx->r1) {
        // 0x800AE410: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_800AE41C;
    }
    // 0x800AE410: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AE414: b           L_800AE450
    // 0x800AE418: lwc1        $f2, -0x7964($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X7964);
        goto L_800AE450;
    // 0x800AE418: lwc1        $f2, -0x7964($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X7964);
L_800AE41C:
    // 0x800AE41C: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    // 0x800AE420: bne         $v0, $at, L_800AE430
    if (ctx->r2 != ctx->r1) {
        // 0x800AE424: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_800AE430;
    }
    // 0x800AE424: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AE428: b           L_800AE450
    // 0x800AE42C: lwc1        $f2, -0x7960($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X7960);
        goto L_800AE450;
    // 0x800AE42C: lwc1        $f2, -0x7960($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X7960);
L_800AE430:
    // 0x800AE430: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x800AE434: bne         $v0, $at, L_800AE450
    if (ctx->r2 != ctx->r1) {
        // 0x800AE438: lui         $t8, 0x8017
        ctx->r24 = S32(0X8017 << 16);
            goto L_800AE450;
    }
    // 0x800AE438: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x800AE43C: lbu         $t8, 0x7AB0($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X7AB0);
    // 0x800AE440: slti        $at, $t8, 0x4
    ctx->r1 = SIGNED(ctx->r24) < 0X4 ? 1 : 0;
    // 0x800AE444: bne         $at, $zero, L_800AE450
    if (ctx->r1 != 0) {
        // 0x800AE448: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_800AE450;
    }
    // 0x800AE448: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AE44C: lwc1        $f2, -0x795C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X795C);
L_800AE450:
    // 0x800AE450: lwc1        $f0, 0x74($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X74);
L_800AE454:
    // 0x800AE454: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x800AE458: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x800AE45C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800AE460: nop

    // 0x800AE464: bc1tl       L_800AE488
    if (c1cs) {
        // 0x800AE468: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_800AE488;
    }
    goto skip_2;
    // 0x800AE468: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_2:
    // 0x800AE46C: lwc1        $f0, 0x7C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X7C);
    // 0x800AE470: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x800AE474: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800AE478: nop

    // 0x800AE47C: bc1f        L_800AE49C
    if (!c1cs) {
        // 0x800AE480: nop
    
            goto L_800AE49C;
    }
    // 0x800AE480: nop

    // 0x800AE484: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_800AE488:
    // 0x800AE488: sw          $t9, 0x1C8($a0)
    MEM_W(0X1C8, ctx->r4) = ctx->r25;
    // 0x800AE48C: sw          $zero, 0x19C($a0)
    MEM_W(0X19C, ctx->r4) = 0;
    // 0x800AE490: sw          $zero, 0x1D0($a0)
    MEM_W(0X1D0, ctx->r4) = 0;
    // 0x800AE494: swc1        $f0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f0.u32l;
    // 0x800AE498: swc1        $f0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f0.u32l;
L_800AE49C:
    // 0x800AE49C: jr          $ra
    // 0x800AE4A0: nop

    return;
    // 0x800AE4A0: nop

;}
RECOMP_FUNC void Versus_SelectStartingForm(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BE564: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800BE568: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800BE56C: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x800BE570: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x800BE574: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800BE578: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x800BE57C: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800BE580: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800BE584: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800BE588: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800BE58C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800BE590: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800BE594: lw          $t6, -0x78A4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X78A4);
    // 0x800BE598: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800BE59C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800BE5A0: bne         $t6, $zero, L_800BE5B4
    if (ctx->r14 != 0) {
        // 0x800BE5A4: lui         $t8, 0x8017
        ctx->r24 = S32(0X8017 << 16);
            goto L_800BE5B4;
    }
    // 0x800BE5A4: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x800BE5A8: lw          $t7, -0x78A0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X78A0);
    // 0x800BE5AC: beq         $t7, $zero, L_800BE5C8
    if (ctx->r15 == 0) {
        // 0x800BE5B0: nop
    
            goto L_800BE5C8;
    }
    // 0x800BE5B0: nop

L_800BE5B4:
    // 0x800BE5B4: lw          $t8, 0x789C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X789C);
    // 0x800BE5B8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800BE5BC: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800BE5C0: bne         $t8, $at, L_800BE668
    if (ctx->r24 != ctx->r1) {
        // 0x800BE5C4: or          $s5, $zero, $zero
        ctx->r21 = 0 | 0;
            goto L_800BE668;
    }
    // 0x800BE5C4: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
L_800BE5C8:
    // 0x800BE5C8: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x800BE5CC: lw          $t9, 0x1A18($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X1A18);
    // 0x800BE5D0: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x800BE5D4: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x800BE5D8: bne         $t9, $zero, L_800BE5F8
    if (ctx->r25 != 0) {
        // 0x800BE5DC: lui         $t5, 0x8016
        ctx->r13 = S32(0X8016 << 16);
            goto L_800BE5F8;
    }
    // 0x800BE5DC: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x800BE5E0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800BE5E4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BE5E8: sw          $t0, -0x7880($at)
    MEM_W(-0X7880, ctx->r1) = ctx->r8;
    // 0x800BE5EC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800BE5F0: sw          $zero, 0x7870($at)
    MEM_W(0X7870, ctx->r1) = 0;
    // 0x800BE5F4: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_800BE5F8:
    // 0x800BE5F8: lw          $t1, 0x1A1C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X1A1C);
    // 0x800BE5FC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800BE600: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BE604: bne         $t1, $zero, L_800BE61C
    if (ctx->r9 != 0) {
        // 0x800BE608: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_800BE61C;
    }
    // 0x800BE608: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800BE60C: sw          $t2, -0x787C($at)
    MEM_W(-0X787C, ctx->r1) = ctx->r10;
    // 0x800BE610: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800BE614: sw          $zero, 0x7874($at)
    MEM_W(0X7874, ctx->r1) = 0;
    // 0x800BE618: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_800BE61C:
    // 0x800BE61C: lw          $t3, 0x1A20($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X1A20);
    // 0x800BE620: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BE624: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800BE628: bne         $t3, $zero, L_800BE640
    if (ctx->r11 != 0) {
        // 0x800BE62C: nop
    
            goto L_800BE640;
    }
    // 0x800BE62C: nop

    // 0x800BE630: sw          $t4, -0x7878($at)
    MEM_W(-0X7878, ctx->r1) = ctx->r12;
    // 0x800BE634: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800BE638: sw          $zero, 0x7878($at)
    MEM_W(0X7878, ctx->r1) = 0;
    // 0x800BE63C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_800BE640:
    // 0x800BE640: lw          $t5, 0x1A24($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X1A24);
    // 0x800BE644: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BE648: bne         $t5, $zero, L_800BE660
    if (ctx->r13 != 0) {
        // 0x800BE64C: nop
    
            goto L_800BE660;
    }
    // 0x800BE64C: nop

    // 0x800BE650: sw          $t6, -0x7874($at)
    MEM_W(-0X7874, ctx->r1) = ctx->r14;
    // 0x800BE654: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800BE658: sw          $zero, 0x787C($at)
    MEM_W(0X787C, ctx->r1) = 0;
    // 0x800BE65C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_800BE660:
    // 0x800BE660: b           L_800BE8F4
    // 0x800BE664: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
        goto L_800BE8F4;
    // 0x800BE664: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
L_800BE668:
    // 0x800BE668: lui         $s6, 0x8016
    ctx->r22 = S32(0X8016 << 16);
    // 0x800BE66C: lui         $s7, 0x800E
    ctx->r23 = S32(0X800E << 16);
    // 0x800BE670: lui         $s4, 0x800C
    ctx->r20 = S32(0X800C << 16);
    // 0x800BE674: addiu       $s4, $s4, 0x5D34
    ctx->r20 = ADD32(ctx->r20, 0X5D34);
    // 0x800BE678: addiu       $s7, $s7, -0x2768
    ctx->r23 = ADD32(ctx->r23, -0X2768);
    // 0x800BE67C: addiu       $s6, $s6, 0x1A18
    ctx->r22 = ADD32(ctx->r22, 0X1A18);
    // 0x800BE680: addiu       $fp, $zero, 0x6
    ctx->r30 = ADD32(0, 0X6);
L_800BE684:
    // 0x800BE684: lw          $t7, 0x0($s6)
    ctx->r15 = MEM_W(ctx->r22, 0X0);
    // 0x800BE688: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800BE68C: addiu       $t8, $t8, -0x7880
    ctx->r24 = ADD32(ctx->r24, -0X7880);
    // 0x800BE690: bne         $t7, $zero, L_800BE8DC
    if (ctx->r15 != 0) {
        // 0x800BE694: addu        $s0, $s5, $t8
        ctx->r16 = ADD32(ctx->r21, ctx->r24);
            goto L_800BE8DC;
    }
    // 0x800BE694: addu        $s0, $s5, $t8
    ctx->r16 = ADD32(ctx->r21, ctx->r24);
    // 0x800BE698: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x800BE69C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800BE6A0: addiu       $t9, $t9, -0x7808
    ctx->r25 = ADD32(ctx->r25, -0X7808);
    // 0x800BE6A4: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800BE6A8: lw          $v0, -0x78A4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X78A4);
    // 0x800BE6AC: bne         $t0, $zero, L_800BE740
    if (ctx->r8 != 0) {
        // 0x800BE6B0: addu        $s1, $s5, $t9
        ctx->r17 = ADD32(ctx->r21, ctx->r25);
            goto L_800BE740;
    }
    // 0x800BE6B0: addu        $s1, $s5, $t9
    ctx->r17 = ADD32(ctx->r21, ctx->r25);
    // 0x800BE6B4: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x800BE6B8: bnel        $t1, $zero, L_800BE744
    if (ctx->r9 != 0) {
        // 0x800BE6BC: lw          $v1, 0x0($s1)
        ctx->r3 = MEM_W(ctx->r17, 0X0);
            goto L_800BE744;
    }
    goto skip_0;
    // 0x800BE6BC: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    skip_0:
    // 0x800BE6C0: beq         $v0, $zero, L_800BE704
    if (ctx->r2 == 0) {
        // 0x800BE6C4: lui         $t2, 0x8018
        ctx->r10 = S32(0X8018 << 16);
            goto L_800BE704;
    }
    // 0x800BE6C4: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x800BE6C8: lw          $t2, -0x78A0($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X78A0);
    // 0x800BE6CC: beq         $t2, $zero, L_800BE704
    if (ctx->r10 == 0) {
        // 0x800BE6D0: nop
    
            goto L_800BE704;
    }
    // 0x800BE6D0: nop

    // 0x800BE6D4: jal         0x80004EB0
    // 0x800BE6D8: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_0;
    // 0x800BE6D8: nop

    after_0:
    // 0x800BE6DC: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x800BE6E0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800BE6E4: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800BE6E8: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800BE6EC: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800BE6F0: mfc1        $t4, $f8
    ctx->r12 = (int32_t)ctx->f8.u32l;
    // 0x800BE6F4: nop

    // 0x800BE6F8: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x800BE6FC: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x800BE700: lw          $v0, -0x78A4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X78A4);
L_800BE704:
    // 0x800BE704: beq         $v0, $zero, L_800BE740
    if (ctx->r2 == 0) {
        // 0x800BE708: lui         $t6, 0x8018
        ctx->r14 = S32(0X8018 << 16);
            goto L_800BE740;
    }
    // 0x800BE708: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800BE70C: lw          $t6, -0x78A0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X78A0);
    // 0x800BE710: bnel        $t6, $zero, L_800BE744
    if (ctx->r14 != 0) {
        // 0x800BE714: lw          $v1, 0x0($s1)
        ctx->r3 = MEM_W(ctx->r17, 0X0);
            goto L_800BE744;
    }
    goto skip_1;
    // 0x800BE714: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    skip_1:
    // 0x800BE718: jal         0x80004EB0
    // 0x800BE71C: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x800BE71C: nop

    after_1:
    // 0x800BE720: add.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x800BE724: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800BE728: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x800BE72C: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
    // 0x800BE730: nop

    // 0x800BE734: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800BE738: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x800BE73C: lw          $v0, -0x78A4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X78A4);
L_800BE740:
    // 0x800BE740: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
L_800BE744:
    // 0x800BE744: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800BE748: beq         $v1, $zero, L_800BE754
    if (ctx->r3 == 0) {
        // 0x800BE74C: addiu       $t0, $v1, -0x1
        ctx->r8 = ADD32(ctx->r3, -0X1);
            goto L_800BE754;
    }
    // 0x800BE74C: addiu       $t0, $v1, -0x1
    ctx->r8 = ADD32(ctx->r3, -0X1);
    // 0x800BE750: sw          $t0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r8;
L_800BE754:
    // 0x800BE754: beq         $v0, $zero, L_800BE7B4
    if (ctx->r2 == 0) {
        // 0x800BE758: nop
    
            goto L_800BE7B4;
    }
    // 0x800BE758: nop

    // 0x800BE75C: bne         $a0, $zero, L_800BE7B4
    if (ctx->r4 != 0) {
        // 0x800BE760: nop
    
            goto L_800BE7B4;
    }
    // 0x800BE760: nop

    // 0x800BE764: multu       $s3, $fp
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BE768: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x800BE76C: lui         $t5, 0x800C
    ctx->r13 = S32(0X800C << 16);
    // 0x800BE770: addiu       $t5, $t5, 0x5D3C
    ctx->r13 = ADD32(ctx->r13, 0X5D3C);
    // 0x800BE774: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x800BE778: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x800BE77C: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    // 0x800BE780: mflo        $t1
    ctx->r9 = lo;
    // 0x800BE784: addu        $t2, $s7, $t1
    ctx->r10 = ADD32(ctx->r23, ctx->r9);
    // 0x800BE788: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x800BE78C: andi        $t4, $t3, 0x4000
    ctx->r12 = ctx->r11 & 0X4000;
    // 0x800BE790: beq         $t4, $zero, L_800BE7B4
    if (ctx->r12 == 0) {
        // 0x800BE794: nop
    
            goto L_800BE7B4;
    }
    // 0x800BE794: nop

    // 0x800BE798: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x800BE79C: ori         $a0, $a0, 0x3
    ctx->r4 = ctx->r4 | 0X3;
    // 0x800BE7A0: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // 0x800BE7A4: jal         0x80019218
    // 0x800BE7A8: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    Audio_PlaySfx(rdram, ctx);
        goto after_2;
    // 0x800BE7A8: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    after_2:
    // 0x800BE7AC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x800BE7B0: sw          $a0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r4;
L_800BE7B4:
    // 0x800BE7B4: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800BE7B8: lw          $t7, -0x78A0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X78A0);
    // 0x800BE7BC: beq         $t7, $zero, L_800BE834
    if (ctx->r15 == 0) {
        // 0x800BE7C0: nop
    
            goto L_800BE834;
    }
    // 0x800BE7C0: nop

    // 0x800BE7C4: bne         $a0, $zero, L_800BE834
    if (ctx->r4 != 0) {
        // 0x800BE7C8: nop
    
            goto L_800BE834;
    }
    // 0x800BE7C8: nop

    // 0x800BE7CC: multu       $s3, $fp
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BE7D0: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x800BE7D4: lui         $t4, 0x800C
    ctx->r12 = S32(0X800C << 16);
    // 0x800BE7D8: addiu       $t4, $t4, 0x5D3C
    ctx->r12 = ADD32(ctx->r12, 0X5D3C);
    // 0x800BE7DC: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x800BE7E0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x800BE7E4: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    // 0x800BE7E8: mflo        $t8
    ctx->r24 = lo;
    // 0x800BE7EC: addu        $t9, $s7, $t8
    ctx->r25 = ADD32(ctx->r23, ctx->r24);
    // 0x800BE7F0: lhu         $v0, 0x0($t9)
    ctx->r2 = MEM_HU(ctx->r25, 0X0);
    // 0x800BE7F4: andi        $t0, $v0, 0x2
    ctx->r8 = ctx->r2 & 0X2;
    // 0x800BE7F8: bne         $t0, $zero, L_800BE818
    if (ctx->r8 != 0) {
        // 0x800BE7FC: andi        $t1, $v0, 0x4
        ctx->r9 = ctx->r2 & 0X4;
            goto L_800BE818;
    }
    // 0x800BE7FC: andi        $t1, $v0, 0x4
    ctx->r9 = ctx->r2 & 0X4;
    // 0x800BE800: bne         $t1, $zero, L_800BE818
    if (ctx->r9 != 0) {
        // 0x800BE804: andi        $t2, $v0, 0x8
        ctx->r10 = ctx->r2 & 0X8;
            goto L_800BE818;
    }
    // 0x800BE804: andi        $t2, $v0, 0x8
    ctx->r10 = ctx->r2 & 0X8;
    // 0x800BE808: bne         $t2, $zero, L_800BE818
    if (ctx->r10 != 0) {
        // 0x800BE80C: andi        $t3, $v0, 0x1
        ctx->r11 = ctx->r2 & 0X1;
            goto L_800BE818;
    }
    // 0x800BE80C: andi        $t3, $v0, 0x1
    ctx->r11 = ctx->r2 & 0X1;
    // 0x800BE810: beq         $t3, $zero, L_800BE834
    if (ctx->r11 == 0) {
        // 0x800BE814: nop
    
            goto L_800BE834;
    }
    // 0x800BE814: nop

L_800BE818:
    // 0x800BE818: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x800BE81C: ori         $a0, $a0, 0x3
    ctx->r4 = ctx->r4 | 0X3;
    // 0x800BE820: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // 0x800BE824: jal         0x80019218
    // 0x800BE828: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    Audio_PlaySfx(rdram, ctx);
        goto after_3;
    // 0x800BE828: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    after_3:
    // 0x800BE82C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x800BE830: sw          $a0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r4;
L_800BE834:
    // 0x800BE834: bne         $a0, $zero, L_800BE88C
    if (ctx->r4 != 0) {
        // 0x800BE838: nop
    
            goto L_800BE88C;
    }
    // 0x800BE838: nop

    // 0x800BE83C: multu       $s3, $fp
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BE840: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x800BE844: lui         $t0, 0x800C
    ctx->r8 = S32(0X800C << 16);
    // 0x800BE848: addiu       $t0, $t0, 0x5D3C
    ctx->r8 = ADD32(ctx->r8, 0X5D3C);
    // 0x800BE84C: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x800BE850: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x800BE854: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    // 0x800BE858: mflo        $t6
    ctx->r14 = lo;
    // 0x800BE85C: addu        $t7, $s7, $t6
    ctx->r15 = ADD32(ctx->r23, ctx->r14);
    // 0x800BE860: lhu         $t8, 0x0($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X0);
    // 0x800BE864: andi        $t9, $t8, 0x8000
    ctx->r25 = ctx->r24 & 0X8000;
    // 0x800BE868: beq         $t9, $zero, L_800BE88C
    if (ctx->r25 == 0) {
        // 0x800BE86C: nop
    
            goto L_800BE88C;
    }
    // 0x800BE86C: nop

    // 0x800BE870: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x800BE874: ori         $a0, $a0, 0x3
    ctx->r4 = ctx->r4 | 0X3;
    // 0x800BE878: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // 0x800BE87C: jal         0x80019218
    // 0x800BE880: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    Audio_PlaySfx(rdram, ctx);
        goto after_4;
    // 0x800BE880: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    after_4:
    // 0x800BE884: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800BE888: sw          $a0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r4;
L_800BE88C:
    // 0x800BE88C: beq         $a0, $zero, L_800BE8DC
    if (ctx->r4 == 0) {
        // 0x800BE890: lui         $t2, 0x8017
        ctx->r10 = S32(0X8017 << 16);
            goto L_800BE8DC;
    }
    // 0x800BE890: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x800BE894: addiu       $t2, $t2, 0x7870
    ctx->r10 = ADD32(ctx->r10, 0X7870);
    // 0x800BE898: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800BE89C: beq         $a0, $at, L_800BE8C4
    if (ctx->r4 == ctx->r1) {
        // 0x800BE8A0: addu        $v1, $s5, $t2
        ctx->r3 = ADD32(ctx->r21, ctx->r10);
            goto L_800BE8C4;
    }
    // 0x800BE8A0: addu        $v1, $s5, $t2
    ctx->r3 = ADD32(ctx->r21, ctx->r10);
    // 0x800BE8A4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800BE8A8: beq         $a0, $at, L_800BE8CC
    if (ctx->r4 == ctx->r1) {
        // 0x800BE8AC: addiu       $t3, $zero, 0x1
        ctx->r11 = ADD32(0, 0X1);
            goto L_800BE8CC;
    }
    // 0x800BE8AC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800BE8B0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800BE8B4: beq         $a0, $at, L_800BE8D4
    if (ctx->r4 == ctx->r1) {
        // 0x800BE8B8: addiu       $t4, $zero, 0x3
        ctx->r12 = ADD32(0, 0X3);
            goto L_800BE8D4;
    }
    // 0x800BE8B8: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x800BE8BC: b           L_800BE8D8
    // 0x800BE8C0: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
        goto L_800BE8D8;
    // 0x800BE8C0: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_800BE8C4:
    // 0x800BE8C4: b           L_800BE8D8
    // 0x800BE8C8: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
        goto L_800BE8D8;
    // 0x800BE8C8: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_800BE8CC:
    // 0x800BE8CC: b           L_800BE8D8
    // 0x800BE8D0: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
        goto L_800BE8D8;
    // 0x800BE8D0: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
L_800BE8D4:
    // 0x800BE8D4: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
L_800BE8D8:
    // 0x800BE8D8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_800BE8DC:
    // 0x800BE8DC: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800BE8E0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800BE8E4: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
    // 0x800BE8E8: bne         $s3, $at, L_800BE684
    if (ctx->r19 != ctx->r1) {
        // 0x800BE8EC: addiu       $s6, $s6, 0x4
        ctx->r22 = ADD32(ctx->r22, 0X4);
            goto L_800BE684;
    }
    // 0x800BE8EC: addiu       $s6, $s6, 0x4
    ctx->r22 = ADD32(ctx->r22, 0X4);
    // 0x800BE8F0: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
L_800BE8F4:
    // 0x800BE8F4: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800BE8F8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800BE8FC: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800BE900: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800BE904: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800BE908: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800BE90C: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x800BE910: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x800BE914: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x800BE918: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x800BE91C: jr          $ra
    // 0x800BE920: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x800BE920: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void AudioLoad_AddToSampleSet(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011710: blez        $a1, L_8001173C
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80011714: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8001173C;
    }
    // 0x80011714: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80011718: lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4);
    // 0x8001171C: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
L_80011720:
    // 0x80011720: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x80011724: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80011728: beq         $v1, $t7, L_8001173C
    if (ctx->r3 == ctx->r15) {
        // 0x8001172C: nop
    
            goto L_8001173C;
    }
    // 0x8001172C: nop

    // 0x80011730: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80011734: bne         $v0, $a1, L_80011720
    if (ctx->r2 != ctx->r5) {
        // 0x80011738: addiu       $a3, $a3, 0x4
        ctx->r7 = ADD32(ctx->r7, 0X4);
            goto L_80011720;
    }
    // 0x80011738: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
L_8001173C:
    // 0x8001173C: bne         $v0, $a1, L_80011750
    if (ctx->r2 != ctx->r5) {
        // 0x80011740: sll         $t8, $a1, 2
        ctx->r24 = S32(ctx->r5 << 2);
            goto L_80011750;
    }
    // 0x80011740: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x80011744: addu        $t9, $a2, $t8
    ctx->r25 = ADD32(ctx->r6, ctx->r24);
    // 0x80011748: sw          $a0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r4;
    // 0x8001174C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_80011750:
    // 0x80011750: jr          $ra
    // 0x80011754: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    return;
    // 0x80011754: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
;}
RECOMP_FUNC void HUD_DisplayCountdown(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008E2C8: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x8008E2CC: sdc1        $f22, 0x38($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X38, ctx->r29);
    // 0x8008E2D0: sw          $s3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r19;
    // 0x8008E2D4: sdc1        $f26, 0x48($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X48, ctx->r29);
    // 0x8008E2D8: sdc1        $f24, 0x40($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X40, ctx->r29);
    // 0x8008E2DC: mtc1        $a3, $f22
    ctx->f22.u32l = ctx->r7;
    // 0x8008E2E0: mov.s       $f24, $f12
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 12);
    ctx->f24.fl = ctx->f12.fl;
    // 0x8008E2E4: mov.s       $f26, $f14
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 14);
    ctx->f26.fl = ctx->f14.fl;
    // 0x8008E2E8: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    // 0x8008E2EC: sw          $ra, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r31;
    // 0x8008E2F0: sw          $fp, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r30;
    // 0x8008E2F4: sw          $s7, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r23;
    // 0x8008E2F8: sw          $s6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r22;
    // 0x8008E2FC: sw          $s5, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r21;
    // 0x8008E300: sw          $s4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r20;
    // 0x8008E304: sw          $s2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r18;
    // 0x8008E308: sw          $s1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r17;
    // 0x8008E30C: sw          $s0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r16;
    // 0x8008E310: sdc1        $f28, 0x50($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X50, ctx->r29);
    // 0x8008E314: sdc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X30, ctx->r29);
    // 0x8008E318: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8008E31C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8008E320: lui         $at, 0x4208
    ctx->r1 = S32(0X4208 << 16);
    // 0x8008E324: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8008E328: sub.s       $f0, $f22, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f22.fl - ctx->f4.fl;
    // 0x8008E32C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8008E330: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8008E334: lui         $at, 0x4110
    ctx->r1 = S32(0X4110 << 16);
    // 0x8008E338: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8008E33C: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x8008E340: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8008E344: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8008E348: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x8008E34C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8008E350: addiu       $s1, $s1, 0x7E64
    ctx->r17 = ADD32(ctx->r17, 0X7E64);
    // 0x8008E354: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8008E358: sub.s       $f24, $f24, $f8
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f24.fl = ctx->f24.fl - ctx->f8.fl;
    // 0x8008E35C: addiu       $fp, $zero, 0x64
    ctx->r30 = ADD32(0, 0X64);
    // 0x8008E360: addiu       $s7, $zero, 0x4
    ctx->r23 = ADD32(0, 0X4);
    // 0x8008E364: sub.s       $f26, $f26, $f16
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f26.fl = ctx->f26.fl - ctx->f16.fl;
    // 0x8008E368: addiu       $s6, $zero, 0x3C
    ctx->r22 = ADD32(0, 0X3C);
    // 0x8008E36C: addiu       $s5, $zero, 0x2
    ctx->r21 = ADD32(0, 0X2);
    // 0x8008E370: lui         $s4, 0xFA00
    ctx->r20 = S32(0XFA00 << 16);
L_8008E374:
    // 0x8008E374: beq         $s0, $zero, L_8008E384
    if (ctx->r16 == 0) {
        // 0x8008E378: andi        $t4, $s0, 0x1
        ctx->r12 = ctx->r16 & 0X1;
            goto L_8008E384;
    }
    // 0x8008E378: andi        $t4, $s0, 0x1
    ctx->r12 = ctx->r16 & 0X1;
    // 0x8008E37C: bne         $s0, $s5, L_8008E3CC
    if (ctx->r16 != ctx->r21) {
        // 0x8008E380: nop
    
            goto L_8008E3CC;
    }
    // 0x8008E380: nop

L_8008E384:
    // 0x8008E384: bgez        $s0, L_8008E394
    if (SIGNED(ctx->r16) >= 0) {
        // 0x8008E388: sra         $t6, $s0, 1
        ctx->r14 = S32(SIGNED(ctx->r16) >> 1);
            goto L_8008E394;
    }
    // 0x8008E388: sra         $t6, $s0, 1
    ctx->r14 = S32(SIGNED(ctx->r16) >> 1);
    // 0x8008E38C: addiu       $at, $s0, 0x1
    ctx->r1 = ADD32(ctx->r16, 0X1);
    // 0x8008E390: sra         $t6, $at, 1
    ctx->r14 = S32(SIGNED(ctx->r1) >> 1);
L_8008E394:
    // 0x8008E394: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8008E398: addu        $t8, $s3, $t7
    ctx->r24 = ADD32(ctx->r19, ctx->r15);
    // 0x8008E39C: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8008E3A0: div         $zero, $t9, $s6
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r22))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r22)));
    // 0x8008E3A4: mfhi        $s2
    ctx->r18 = hi;
    // 0x8008E3A8: bne         $s6, $zero, L_8008E3B4
    if (ctx->r22 != 0) {
        // 0x8008E3AC: nop
    
            goto L_8008E3B4;
    }
    // 0x8008E3AC: nop

    // 0x8008E3B0: break       7
    do_break(2148066224);
L_8008E3B4:
    // 0x8008E3B4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8008E3B8: bne         $s6, $at, L_8008E3CC
    if (ctx->r22 != ctx->r1) {
        // 0x8008E3BC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8008E3CC;
    }
    // 0x8008E3BC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8008E3C0: bne         $t9, $at, L_8008E3CC
    if (ctx->r25 != ctx->r1) {
        // 0x8008E3C4: nop
    
            goto L_8008E3CC;
    }
    // 0x8008E3C4: nop

    // 0x8008E3C8: break       6
    do_break(2148066248);
L_8008E3CC:
    // 0x8008E3CC: bne         $s0, $s7, L_8008E41C
    if (ctx->r16 != ctx->r23) {
        // 0x8008E3D0: nop
    
            goto L_8008E41C;
    }
    // 0x8008E3D0: nop

    // 0x8008E3D4: bgez        $s0, L_8008E3E4
    if (SIGNED(ctx->r16) >= 0) {
        // 0x8008E3D8: sra         $t0, $s0, 1
        ctx->r8 = S32(SIGNED(ctx->r16) >> 1);
            goto L_8008E3E4;
    }
    // 0x8008E3D8: sra         $t0, $s0, 1
    ctx->r8 = S32(SIGNED(ctx->r16) >> 1);
    // 0x8008E3DC: addiu       $at, $s0, 0x1
    ctx->r1 = ADD32(ctx->r16, 0X1);
    // 0x8008E3E0: sra         $t0, $at, 1
    ctx->r8 = S32(SIGNED(ctx->r1) >> 1);
L_8008E3E4:
    // 0x8008E3E4: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8008E3E8: addu        $t2, $s3, $t1
    ctx->r10 = ADD32(ctx->r19, ctx->r9);
    // 0x8008E3EC: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x8008E3F0: div         $zero, $t3, $fp
    lo = S32(S64(S32(ctx->r11)) / S64(S32(ctx->r30))); hi = S32(S64(S32(ctx->r11)) % S64(S32(ctx->r30)));
    // 0x8008E3F4: mfhi        $s2
    ctx->r18 = hi;
    // 0x8008E3F8: bne         $fp, $zero, L_8008E404
    if (ctx->r30 != 0) {
        // 0x8008E3FC: nop
    
            goto L_8008E404;
    }
    // 0x8008E3FC: nop

    // 0x8008E400: break       7
    do_break(2148066304);
L_8008E404:
    // 0x8008E404: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8008E408: bne         $fp, $at, L_8008E41C
    if (ctx->r30 != ctx->r1) {
        // 0x8008E40C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8008E41C;
    }
    // 0x8008E40C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8008E410: bne         $t3, $at, L_8008E41C
    if (ctx->r11 != ctx->r1) {
        // 0x8008E414: nop
    
            goto L_8008E41C;
    }
    // 0x8008E414: nop

    // 0x8008E418: break       6
    do_break(2148066328);
L_8008E41C:
    // 0x8008E41C: beq         $t4, $zero, L_8008E488
    if (ctx->r12 == 0) {
        // 0x8008E420: nop
    
            goto L_8008E488;
    }
    // 0x8008E420: nop

    // 0x8008E424: jal         0x800BA4F0
    // 0x8008E428: nop

    RCP_SetupDL_78(rdram, ctx);
        goto after_0;
    // 0x8008E428: nop

    after_0:
    // 0x8008E42C: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8008E430: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8008E434: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8008E438: addiu       $t5, $v1, 0x8
    ctx->r13 = ADD32(ctx->r3, 0X8);
    // 0x8008E43C: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
    // 0x8008E440: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8008E444: sw          $s4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r20;
    // 0x8008E448: mul.s       $f18, $f20, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = MUL_S(ctx->f20.fl, ctx->f22.fl);
    // 0x8008E44C: lui         $a1, 0x101
    ctx->r5 = S32(0X101 << 16);
    // 0x8008E450: lui         $a2, 0x101
    ctx->r6 = S32(0X101 << 16);
    // 0x8008E454: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x8008E458: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8008E45C: addiu       $a2, $a2, 0x1EC0
    ctx->r6 = ADD32(ctx->r6, 0X1EC0);
    // 0x8008E460: addiu       $a1, $a1, 0x1E80
    ctx->r5 = ADD32(ctx->r5, 0X1E80);
    // 0x8008E464: add.s       $f4, $f18, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f24.fl;
    // 0x8008E468: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x8008E46C: swc1        $f26, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f26.u32l;
    // 0x8008E470: swc1        $f22, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f22.u32l;
    // 0x8008E474: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x8008E478: jal         0x8009C320
    // 0x8008E47C: swc1        $f22, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f22.u32l;
    Lib_TextureRect_CI4(rdram, ctx);
        goto after_1;
    // 0x8008E47C: swc1        $f22, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f22.u32l;
    after_1:
    // 0x8008E480: b           L_8008E4CC
    // 0x8008E484: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_8008E4CC;
    // 0x8008E484: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8008E488:
    // 0x8008E488: jal         0x800BA490
    // 0x8008E48C: nop

    RCP_SetupDL_76(rdram, ctx);
        goto after_2;
    // 0x8008E48C: nop

    after_2:
    // 0x8008E490: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8008E494: lui         $t9, 0xFFFF
    ctx->r25 = S32(0XFFFF << 16);
    // 0x8008E498: ori         $t9, $t9, 0xFF
    ctx->r25 = ctx->r25 | 0XFF;
    // 0x8008E49C: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8008E4A0: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x8008E4A4: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8008E4A8: sw          $s4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r20;
    // 0x8008E4AC: mul.s       $f6, $f20, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f22.fl);
    // 0x8008E4B0: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x8008E4B4: mov.s       $f14, $f26
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    ctx->f14.fl = ctx->f26.fl;
    // 0x8008E4B8: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    // 0x8008E4BC: jal         0x8008C390
    // 0x8008E4C0: add.s       $f12, $f6, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f24.fl;
    HUD_DisplaySmallNumber(rdram, ctx);
        goto after_3;
    // 0x8008E4C0: add.s       $f12, $f6, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f24.fl;
    after_3:
    // 0x8008E4C4: add.s       $f20, $f20, $f28
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f28.fl;
    // 0x8008E4C8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8008E4CC:
    // 0x8008E4CC: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8008E4D0: bne         $s0, $at, L_8008E374
    if (ctx->r16 != ctx->r1) {
        // 0x8008E4D4: add.s       $f20, $f20, $f28
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f28.fl;
            goto L_8008E374;
    }
    // 0x8008E4D4: add.s       $f20, $f20, $f28
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f28.fl;
    // 0x8008E4D8: lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X7C);
    // 0x8008E4DC: ldc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X30);
    // 0x8008E4E0: ldc1        $f22, 0x38($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X38);
    // 0x8008E4E4: ldc1        $f24, 0x40($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X40);
    // 0x8008E4E8: ldc1        $f26, 0x48($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X48);
    // 0x8008E4EC: ldc1        $f28, 0x50($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X50);
    // 0x8008E4F0: lw          $s0, 0x58($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X58);
    // 0x8008E4F4: lw          $s1, 0x5C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X5C);
    // 0x8008E4F8: lw          $s2, 0x60($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X60);
    // 0x8008E4FC: lw          $s3, 0x64($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X64);
    // 0x8008E500: lw          $s4, 0x68($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X68);
    // 0x8008E504: lw          $s5, 0x6C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X6C);
    // 0x8008E508: lw          $s6, 0x70($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X70);
    // 0x8008E50C: lw          $s7, 0x74($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X74);
    // 0x8008E510: lw          $fp, 0x78($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X78);
    // 0x8008E514: jr          $ra
    // 0x8008E518: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x8008E518: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void ActorTeamBoss_Init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80092D48: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80092D4C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80092D50: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80092D54: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80092D58: addiu       $v1, $sp, 0x2C
    ctx->r3 = ADD32(ctx->r29, 0X2C);
    // 0x80092D5C: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80092D60: addiu       $t6, $t6, 0x22A8
    ctx->r14 = ADD32(ctx->r14, 0X22A8);
    // 0x80092D64: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x80092D68: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80092D6C: sw          $at, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r1;
    // 0x80092D70: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x80092D74: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80092D78: lw          $at, 0x8($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X8);
    // 0x80092D7C: sw          $at, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r1;
    // 0x80092D80: lw          $t0, -0x7DCC($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7DCC);
    // 0x80092D84: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80092D88: beq         $t0, $at, L_80092DCC
    if (ctx->r8 == ctx->r1) {
        // 0x80092D8C: lui         $at, 0x4220
        ctx->r1 = S32(0X4220 << 16);
            goto L_80092DCC;
    }
    // 0x80092D8C: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80092D90: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80092D94: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80092D98: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80092D9C: swc1        $f4, 0x118($s0)
    MEM_W(0X118, ctx->r16) = ctx->f4.u32l;
    // 0x80092DA0: lwc1        $f6, 0x7FD4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7FD4);
    // 0x80092DA4: addiu       $v0, $v0, 0x1970
    ctx->r2 = ADD32(ctx->r2, 0X1970);
    // 0x80092DA8: swc1        $f6, 0x120($s0)
    MEM_W(0X120, ctx->r16) = ctx->f6.u32l;
    // 0x80092DAC: lh          $t1, 0x0($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X0);
    // 0x80092DB0: andi        $t2, $t1, 0x3
    ctx->r10 = ctx->r9 & 0X3;
    // 0x80092DB4: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x80092DB8: sh          $t3, 0xE4($s0)
    MEM_H(0XE4, ctx->r16) = ctx->r11;
    // 0x80092DBC: lh          $t4, 0x0($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X0);
    // 0x80092DC0: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80092DC4: b           L_80092DEC
    // 0x80092DC8: sh          $t5, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r13;
        goto L_80092DEC;
    // 0x80092DC8: sh          $t5, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r13;
L_80092DCC:
    // 0x80092DCC: addiu       $t8, $zero, 0x7
    ctx->r24 = ADD32(0, 0X7);
    // 0x80092DD0: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80092DD4: sh          $t8, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r24;
    // 0x80092DD8: sh          $t7, 0xE4($s0)
    MEM_H(0XE4, ctx->r16) = ctx->r15;
    // 0x80092DDC: sw          $zero, 0x64($s0)
    MEM_W(0X64, ctx->r16) = 0;
    // 0x80092DE0: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80092DE4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80092DE8: sw          $t6, 0x78B8($at)
    MEM_W(0X78B8, ctx->r1) = ctx->r14;
L_80092DEC:
    // 0x80092DEC: lh          $t9, 0xE4($s0)
    ctx->r25 = MEM_H(ctx->r16, 0XE4);
    // 0x80092DF0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80092DF4: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x80092DF8: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80092DFC: addu        $t1, $v1, $t0
    ctx->r9 = ADD32(ctx->r3, ctx->r8);
    // 0x80092E00: lw          $t2, -0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, -0X4);
    // 0x80092E04: sw          $t3, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r11;
    // 0x80092E08: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80092E0C: sw          $t2, 0x80($s0)
    MEM_W(0X80, ctx->r16) = ctx->r10;
    // 0x80092E10: lbu         $t4, 0x7C98($t4)
    ctx->r12 = MEM_BU(ctx->r12, 0X7C98);
    // 0x80092E14: lui         $a0, 0x3100
    ctx->r4 = S32(0X3100 << 16);
    // 0x80092E18: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80092E1C: bne         $t4, $zero, L_80092E2C
    if (ctx->r12 != 0) {
        // 0x80092E20: ori         $a0, $a0, 0xC
        ctx->r4 = ctx->r4 | 0XC;
            goto L_80092E2C;
    }
    // 0x80092E20: ori         $a0, $a0, 0xC
    ctx->r4 = ctx->r4 | 0XC;
    // 0x80092E24: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80092E28: sb          $t5, 0xC9($s0)
    MEM_B(0XC9, ctx->r16) = ctx->r13;
L_80092E2C:
    // 0x80092E2C: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x80092E30: addiu       $t8, $t8, 0x5D3C
    ctx->r24 = ADD32(ctx->r24, 0X5D3C);
    // 0x80092E34: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x80092E38: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x80092E3C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80092E40: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80092E44: jal         0x80019218
    // 0x80092E48: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    Audio_PlaySfx(rdram, ctx);
        goto after_0;
    // 0x80092E48: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_0:
    // 0x80092E4C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80092E50: addiu       $v0, $v0, 0x1970
    ctx->r2 = ADD32(ctx->r2, 0X1970);
    // 0x80092E54: lh          $t7, 0x0($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X0);
    // 0x80092E58: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x80092E5C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80092E60: andi        $t6, $t7, 0x3
    ctx->r14 = ctx->r15 & 0X3;
    // 0x80092E64: bnel        $v1, $t6, L_80092E88
    if (ctx->r3 != ctx->r14) {
        // 0x80092E68: lh          $t0, 0xE4($s0)
        ctx->r8 = MEM_H(ctx->r16, 0XE4);
            goto L_80092E88;
    }
    goto skip_0;
    // 0x80092E68: lh          $t0, 0xE4($s0)
    ctx->r8 = MEM_H(ctx->r16, 0XE4);
    skip_0:
    // 0x80092E6C: lw          $t9, -0x7DCC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7DCC);
    // 0x80092E70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80092E74: bnel        $v1, $t9, L_80092E88
    if (ctx->r3 != ctx->r25) {
        // 0x80092E78: lh          $t0, 0xE4($s0)
        ctx->r8 = MEM_H(ctx->r16, 0XE4);
            goto L_80092E88;
    }
    goto skip_1;
    // 0x80092E78: lh          $t0, 0xE4($s0)
    ctx->r8 = MEM_H(ctx->r16, 0XE4);
    skip_1:
    // 0x80092E7C: jal         0x80060FBC
    // 0x80092E80: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    Object_Kill(rdram, ctx);
        goto after_1;
    // 0x80092E80: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x80092E84: lh          $t0, 0xE4($s0)
    ctx->r8 = MEM_H(ctx->r16, 0XE4);
L_80092E88:
    // 0x80092E88: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x80092E8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80092E90: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80092E94: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80092E98: lw          $t2, 0x78B0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X78B0);
    // 0x80092E9C: bgtzl       $t2, L_80092EB0
    if (SIGNED(ctx->r10) > 0) {
        // 0x80092EA0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80092EB0;
    }
    goto skip_2;
    // 0x80092EA0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x80092EA4: jal         0x80060FBC
    // 0x80092EA8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    Object_Kill(rdram, ctx);
        goto after_2;
    // 0x80092EA8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x80092EAC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80092EB0:
    // 0x80092EB0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80092EB4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80092EB8: jr          $ra
    // 0x80092EBC: nop

    return;
    // 0x80092EBC: nop

;}
RECOMP_FUNC void Boss_Initialize(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80061404: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80061408: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8006140C: addiu       $a1, $zero, 0x408
    ctx->r5 = ADD32(0, 0X408);
L_80061410:
    // 0x80061410: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80061414: sb          $zero, 0x1($v0)
    MEM_B(0X1, ctx->r2) = 0;
    // 0x80061418: sb          $zero, 0x2($v0)
    MEM_B(0X2, ctx->r2) = 0;
    // 0x8006141C: sb          $zero, 0x3($v0)
    MEM_B(0X3, ctx->r2) = 0;
    // 0x80061420: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80061424: bne         $v1, $a1, L_80061410
    if (ctx->r3 != ctx->r5) {
        // 0x80061428: sb          $zero, -0x4($v0)
        MEM_B(-0X4, ctx->r2) = 0;
            goto L_80061410;
    }
    // 0x80061428: sb          $zero, -0x4($v0)
    MEM_B(-0X4, ctx->r2) = 0;
    // 0x8006142C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80061430: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80061434: nop

    // 0x80061438: swc1        $f4, 0x3F8($a0)
    MEM_W(0X3F8, ctx->r4) = ctx->f4.u32l;
    // 0x8006143C: jr          $ra
    // 0x80061440: nop

    return;
    // 0x80061440: nop

;}
RECOMP_FUNC void func_enmy_800660F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800660F0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800660F4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800660F8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800660FC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80066100: lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // 0x80066104: addiu       $s0, $s0, 0x37E0
    ctx->r16 = ADD32(ctx->r16, 0X37E0);
    // 0x80066108: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8006610C: addiu       $v1, $zero, 0x14
    ctx->r3 = ADD32(0, 0X14);
L_80066110:
    // 0x80066110: lbu         $t6, 0x0($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X0);
    // 0x80066114: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80066118: bne         $t6, $zero, L_80066238
    if (ctx->r14 != 0) {
        // 0x8006611C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80066238;
    }
    // 0x8006611C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80066120: jal         0x80061444
    // 0x80066124: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    Item_Initialize(rdram, ctx);
        goto after_0;
    // 0x80066124: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x80066128: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8006612C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80066130: sb          $t7, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r15;
    // 0x80066134: lbu         $t8, 0x44($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X44);
    // 0x80066138: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x8006613C: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
    // 0x80066140: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80066144: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80066148: lw          $t0, -0x20C($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X20C);
    // 0x8006614C: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x80066150: sh          $t0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r8;
    // 0x80066154: lwc1        $f4, 0x4($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X4);
    // 0x80066158: andi        $a1, $t0, 0xFFFF
    ctx->r5 = ctx->r8 & 0XFFFF;
    // 0x8006615C: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x80066160: lwc1        $f6, 0x8($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X8);
    // 0x80066164: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x80066168: lwc1        $f8, 0xC($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0XC);
    // 0x8006616C: sh          $t1, 0x4A($s0)
    MEM_H(0X4A, ctx->r16) = ctx->r9;
    // 0x80066170: jal         0x800612B8
    // 0x80066174: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_1;
    // 0x80066174: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    after_1:
    // 0x80066178: lhu         $v0, 0x2($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X2);
    // 0x8006617C: addiu       $at, $zero, 0x144
    ctx->r1 = ADD32(0, 0X144);
    // 0x80066180: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80066184: beq         $v0, $at, L_8006619C
    if (ctx->r2 == ctx->r1) {
        // 0x80066188: addiu       $a3, $a3, 0x5D34
        ctx->r7 = ADD32(ctx->r7, 0X5D34);
            goto L_8006619C;
    }
    // 0x80066188: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8006618C: addiu       $at, $zero, 0x147
    ctx->r1 = ADD32(0, 0X147);
    // 0x80066190: beq         $v0, $at, L_8006619C
    if (ctx->r2 == ctx->r1) {
        // 0x80066194: addiu       $at, $zero, 0x142
        ctx->r1 = ADD32(0, 0X142);
            goto L_8006619C;
    }
    // 0x80066194: addiu       $at, $zero, 0x142
    ctx->r1 = ADD32(0, 0X142);
    // 0x80066198: bne         $v0, $at, L_800661AC
    if (ctx->r2 != ctx->r1) {
        // 0x8006619C: lui         $at, 0x42B4
        ctx->r1 = S32(0X42B4 << 16);
            goto L_800661AC;
    }
L_8006619C:
    // 0x8006619C: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x800661A0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800661A4: lhu         $v0, 0x2($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X2);
    // 0x800661A8: swc1        $f10, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f10.u32l;
L_800661AC:
    // 0x800661AC: slti        $at, $v0, 0x150
    ctx->r1 = SIGNED(ctx->r2) < 0X150 ? 1 : 0;
    // 0x800661B0: beq         $at, $zero, L_800661C0
    if (ctx->r1 == 0) {
        // 0x800661B4: lui         $a0, 0x4900
        ctx->r4 = S32(0X4900 << 16);
            goto L_800661C0;
    }
    // 0x800661B4: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x800661B8: addiu       $at, $zero, 0x14F
    ctx->r1 = ADD32(0, 0X14F);
    // 0x800661BC: bne         $v0, $at, L_80066240
    if (ctx->r2 != ctx->r1) {
        // 0x800661C0: lui         $at, 0x42B4
        ctx->r1 = S32(0X42B4 << 16);
            goto L_80066240;
    }
L_800661C0:
    // 0x800661C0: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x800661C4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800661C8: lui         $t2, 0x800C
    ctx->r10 = S32(0X800C << 16);
    // 0x800661CC: addiu       $t2, $t2, 0x5D3C
    ctx->r10 = ADD32(ctx->r10, 0X5D3C);
    // 0x800661D0: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x800661D4: swc1        $f16, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f16.u32l;
    // 0x800661D8: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x800661DC: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x800661E0: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x800661E4: ori         $a0, $a0, 0xC
    ctx->r4 = ctx->r4 | 0XC;
    // 0x800661E8: jal         0x80019218
    // 0x800661EC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_2;
    // 0x800661EC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_2:
    // 0x800661F0: lhu         $t4, 0x2($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X2);
    // 0x800661F4: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x800661F8: addiu       $t3, $zero, 0x3E8
    ctx->r11 = ADD32(0, 0X3E8);
    // 0x800661FC: addiu       $at, $zero, 0x151
    ctx->r1 = ADD32(0, 0X151);
    // 0x80066200: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80066204: bne         $t4, $at, L_80066240
    if (ctx->r12 != ctx->r1) {
        // 0x80066208: sh          $t3, 0x48($s0)
        MEM_H(0X48, ctx->r16) = ctx->r11;
            goto L_80066240;
    }
    // 0x80066208: sh          $t3, 0x48($s0)
    MEM_H(0X48, ctx->r16) = ctx->r11;
    // 0x8006620C: lui         $t5, 0x800C
    ctx->r13 = S32(0X800C << 16);
    // 0x80066210: addiu       $t5, $t5, 0x5D3C
    ctx->r13 = ADD32(ctx->r13, 0X5D3C);
    // 0x80066214: lui         $a0, 0x1900
    ctx->r4 = S32(0X1900 << 16);
    // 0x80066218: ori         $a0, $a0, 0x302B
    ctx->r4 = ctx->r4 | 0X302B;
    // 0x8006621C: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80066220: addiu       $a1, $s0, 0x5C
    ctx->r5 = ADD32(ctx->r16, 0X5C);
    // 0x80066224: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80066228: jal         0x80019218
    // 0x8006622C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    Audio_PlaySfx(rdram, ctx);
        goto after_3;
    // 0x8006622C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_3:
    // 0x80066230: b           L_80066244
    // 0x80066234: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80066244;
    // 0x80066234: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80066238:
    // 0x80066238: bne         $v0, $v1, L_80066110
    if (ctx->r2 != ctx->r3) {
        // 0x8006623C: addiu       $s0, $s0, 0x6C
        ctx->r16 = ADD32(ctx->r16, 0X6C);
            goto L_80066110;
    }
    // 0x8006623C: addiu       $s0, $s0, 0x6C
    ctx->r16 = ADD32(ctx->r16, 0X6C);
L_80066240:
    // 0x80066240: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80066244:
    // 0x80066244: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80066248: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8006624C: jr          $ra
    // 0x80066250: nop

    return;
    // 0x80066250: nop

;}
RECOMP_FUNC void Matrix_Scale(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005C34: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80005C38: sdc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X8, ctx->r29);
    // 0x80005C3C: mtc1        $a3, $f20
    ctx->f20.u32l = ctx->r7;
    // 0x80005C40: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80005C44: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x80005C48: lbu         $t6, 0x23($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X23);
    // 0x80005C4C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80005C50: bnel        $t6, $at, L_80005CF0
    if (ctx->r14 != ctx->r1) {
        // 0x80005C54: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_80005CF0;
    }
    goto skip_0;
    // 0x80005C54: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_0:
    // 0x80005C58: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80005C5C: lwc1        $f2, 0x10($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80005C60: lwc1        $f8, 0x20($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X20);
    // 0x80005C64: mul.s       $f4, $f0, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x80005C68: lwc1        $f0, 0x4($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80005C6C: mul.s       $f6, $f2, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x80005C70: lwc1        $f2, 0x14($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80005C74: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x80005C78: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x80005C7C: lwc1        $f4, 0x24($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X24);
    // 0x80005C80: mul.s       $f16, $f0, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x80005C84: swc1        $f6, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f6.u32l;
    // 0x80005C88: lwc1        $f0, 0x8($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80005C8C: mul.s       $f18, $f2, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x80005C90: lwc1        $f2, 0x18($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X18);
    // 0x80005C94: swc1        $f10, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f10.u32l;
    // 0x80005C98: mul.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x80005C9C: swc1        $f16, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f16.u32l;
    // 0x80005CA0: lwc1        $f16, 0x28($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X28);
    // 0x80005CA4: mul.s       $f8, $f0, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x80005CA8: swc1        $f18, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f18.u32l;
    // 0x80005CAC: lwc1        $f0, 0xC($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80005CB0: mul.s       $f10, $f2, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x80005CB4: lwc1        $f2, 0x1C($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x80005CB8: swc1        $f6, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f6.u32l;
    // 0x80005CBC: mul.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f20.fl);
    // 0x80005CC0: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
    // 0x80005CC4: lwc1        $f8, 0x2C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x80005CC8: mul.s       $f4, $f0, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x80005CCC: swc1        $f10, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f10.u32l;
    // 0x80005CD0: mul.s       $f6, $f2, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x80005CD4: swc1        $f18, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f18.u32l;
    // 0x80005CD8: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x80005CDC: swc1        $f4, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f4.u32l;
    // 0x80005CE0: swc1        $f6, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f6.u32l;
    // 0x80005CE4: b           L_80005D38
    // 0x80005CE8: swc1        $f10, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f10.u32l;
        goto L_80005D38;
    // 0x80005CE8: swc1        $f10, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f10.u32l;
    // 0x80005CEC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_80005CF0:
    // 0x80005CF0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80005CF4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80005CF8: swc1        $f12, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f12.u32l;
    // 0x80005CFC: swc1        $f14, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f14.u32l;
    // 0x80005D00: swc1        $f20, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f20.u32l;
    // 0x80005D04: swc1        $f0, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f0.u32l;
    // 0x80005D08: swc1        $f0, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f0.u32l;
    // 0x80005D0C: swc1        $f0, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f0.u32l;
    // 0x80005D10: swc1        $f0, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f0.u32l;
    // 0x80005D14: swc1        $f0, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f0.u32l;
    // 0x80005D18: swc1        $f0, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f0.u32l;
    // 0x80005D1C: swc1        $f0, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f0.u32l;
    // 0x80005D20: swc1        $f0, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f0.u32l;
    // 0x80005D24: swc1        $f0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f0.u32l;
    // 0x80005D28: swc1        $f0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f0.u32l;
    // 0x80005D2C: swc1        $f0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f0.u32l;
    // 0x80005D30: swc1        $f0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f0.u32l;
    // 0x80005D34: swc1        $f16, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f16.u32l;
L_80005D38:
    // 0x80005D38: ldc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X8);
    // 0x80005D3C: jr          $ra
    // 0x80005D40: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x80005D40: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void Effect_Effect375_Spawn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BB1C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006BB20: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006BB24: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8006BB28: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8006BB2C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8006BB30: addiu       $v0, $v0, 0x37E0
    ctx->r2 = ADD32(ctx->r2, 0X37E0);
    // 0x8006BB34: addiu       $a0, $a0, 0x130
    ctx->r4 = ADD32(ctx->r4, 0X130);
    // 0x8006BB38: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
L_8006BB3C:
    // 0x8006BB3C: bnel        $t6, $zero, L_8006BB60
    if (ctx->r14 != 0) {
        // 0x8006BB40: addiu       $a0, $a0, 0x8C
        ctx->r4 = ADD32(ctx->r4, 0X8C);
            goto L_8006BB60;
    }
    goto skip_0;
    // 0x8006BB40: addiu       $a0, $a0, 0x8C
    ctx->r4 = ADD32(ctx->r4, 0X8C);
    skip_0:
    // 0x8006BB44: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8006BB48: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x8006BB4C: jal         0x8006BA64
    // 0x8006BB50: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    Effect_Effect375_Setup(rdram, ctx);
        goto after_0;
    // 0x8006BB50: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    after_0:
    // 0x8006BB54: b           L_8006BB6C
    // 0x8006BB58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8006BB6C;
    // 0x8006BB58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006BB5C: addiu       $a0, $a0, 0x8C
    ctx->r4 = ADD32(ctx->r4, 0X8C);
L_8006BB60:
    // 0x8006BB60: bnel        $a0, $v0, L_8006BB3C
    if (ctx->r4 != ctx->r2) {
        // 0x8006BB64: lbu         $t6, 0x0($a0)
        ctx->r14 = MEM_BU(ctx->r4, 0X0);
            goto L_8006BB3C;
    }
    goto skip_1;
    // 0x8006BB64: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    skip_1:
    // 0x8006BB68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8006BB6C:
    // 0x8006BB6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006BB70: jr          $ra
    // 0x8006BB74: nop

    return;
    // 0x8006BB74: nop

;}
RECOMP_FUNC void Object_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A3E8: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8006A3EC: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8006A3F0: addiu       $a0, $a0, 0x1AB8
    ctx->r4 = ADD32(ctx->r4, 0X1AB8);
    // 0x8006A3F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006A3F8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8006A3FC: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x8006A400: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8006A404: lw          $v1, 0x7880($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7880);
    // 0x8006A408: bne         $v1, $zero, L_8006A454
    if (ctx->r3 != 0) {
        // 0x8006A40C: lui         $t6, 0x8018
        ctx->r14 = S32(0X8018 << 16);
            goto L_8006A454;
    }
    // 0x8006A40C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006A410: lw          $t6, -0x7D80($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7D80);
    // 0x8006A414: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8006A418: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8006A41C: lw          $v0, 0x1C8($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X1C8);
    // 0x8006A420: beql        $a1, $v0, L_8006A454
    if (ctx->r5 == ctx->r2) {
        // 0x8006A424: sw          $a1, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r5;
            goto L_8006A454;
    }
    goto skip_0;
    // 0x8006A424: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
    skip_0:
    // 0x8006A428: beq         $v0, $at, L_8006A450
    if (ctx->r2 == ctx->r1) {
        // 0x8006A42C: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8006A450;
    }
    // 0x8006A42C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8006A430: beq         $v0, $at, L_8006A450
    if (ctx->r2 == ctx->r1) {
        // 0x8006A434: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_8006A450;
    }
    // 0x8006A434: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8006A438: beq         $v0, $at, L_8006A450
    if (ctx->r2 == ctx->r1) {
        // 0x8006A43C: addiu       $at, $zero, 0x9
        ctx->r1 = ADD32(0, 0X9);
            goto L_8006A450;
    }
    // 0x8006A43C: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8006A440: beq         $v0, $at, L_8006A450
    if (ctx->r2 == ctx->r1) {
        // 0x8006A444: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_8006A450;
    }
    // 0x8006A444: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8006A448: bnel        $v0, $at, L_8006A458
    if (ctx->r2 != ctx->r1) {
        // 0x8006A44C: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_8006A458;
    }
    goto skip_1;
    // 0x8006A44C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    skip_1:
L_8006A450:
    // 0x8006A450: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
L_8006A454:
    // 0x8006A454: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_8006A458:
    // 0x8006A458: beq         $a1, $v1, L_8006A4CC
    if (ctx->r5 == ctx->r3) {
        // 0x8006A45C: lui         $t7, 0x8018
        ctx->r15 = S32(0X8018 << 16);
            goto L_8006A4CC;
    }
    // 0x8006A45C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8006A460: lw          $t7, -0x7B78($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7B78);
    // 0x8006A464: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8006A468: beq         $t7, $zero, L_8006A48C
    if (ctx->r15 == 0) {
        // 0x8006A46C: nop
    
            goto L_8006A48C;
    }
    // 0x8006A46C: nop

    // 0x8006A470: lw          $t8, -0x7D80($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7D80);
    // 0x8006A474: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8006A478: lw          $t9, 0x1C8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X1C8);
    // 0x8006A47C: beq         $t9, $at, L_8006A48C
    if (ctx->r25 == ctx->r1) {
        // 0x8006A480: nop
    
            goto L_8006A48C;
    }
    // 0x8006A480: nop

    // 0x8006A484: jal         0x80062664
    // 0x8006A488: nop

    Object_LoadLevelObjects(rdram, ctx);
        goto after_0;
    // 0x8006A488: nop

    after_0:
L_8006A48C:
    // 0x8006A48C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8006A490: addiu       $a0, $a0, 0x1B00
    ctx->r4 = ADD32(ctx->r4, 0X1B00);
    // 0x8006A494: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8006A498:
    // 0x8006A498: lbu         $t0, 0x0($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X0);
    // 0x8006A49C: beql        $t0, $zero, L_8006A4B8
    if (ctx->r8 == 0) {
        // 0x8006A4A0: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8006A4B8;
    }
    goto skip_2;
    // 0x8006A4A0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_2:
    // 0x8006A4A4: sw          $s0, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->r16;
    // 0x8006A4A8: jal         0x80069DF4
    // 0x8006A4AC: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    Scenery_Update(rdram, ctx);
        goto after_1;
    // 0x8006A4AC: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    after_1:
    // 0x8006A4B0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8006A4B4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8006A4B8:
    // 0x8006A4B8: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x8006A4BC: bne         $s0, $at, L_8006A498
    if (ctx->r16 != ctx->r1) {
        // 0x8006A4C0: addiu       $a0, $a0, 0x80
        ctx->r4 = ADD32(ctx->r4, 0X80);
            goto L_8006A498;
    }
    // 0x8006A4C0: addiu       $a0, $a0, 0x80
    ctx->r4 = ADD32(ctx->r4, 0X80);
    // 0x8006A4C4: b           L_8006A618
    // 0x8006A4C8: nop

        goto L_8006A618;
    // 0x8006A4C8: nop

L_8006A4CC:
    // 0x8006A4CC: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x8006A4D0: lw          $t1, 0x78E8($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X78E8);
    // 0x8006A4D4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8006A4D8: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8006A4DC: beq         $t1, $zero, L_8006A618
    if (ctx->r9 == 0) {
        // 0x8006A4E0: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_8006A618;
    }
    // 0x8006A4E0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8006A4E4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8006A4E8: lw          $v0, -0x7D58($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D58);
    // 0x8006A4EC: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    // 0x8006A4F0: addiu       $v1, $zero, 0x92
    ctx->r3 = ADD32(0, 0X92);
L_8006A4F4:
    // 0x8006A4F4: lbu         $t2, 0x0($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X0);
    // 0x8006A4F8: beql        $t2, $zero, L_8006A538
    if (ctx->r10 == 0) {
        // 0x8006A4FC: lbu         $t5, 0x58($v0)
        ctx->r13 = MEM_BU(ctx->r2, 0X58);
            goto L_8006A538;
    }
    goto skip_3;
    // 0x8006A4FC: lbu         $t5, 0x58($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X58);
    skip_3:
    // 0x8006A500: lhu         $t3, 0x2($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X2);
    // 0x8006A504: andi        $t4, $s0, 0x1
    ctx->r12 = ctx->r16 & 0X1;
    // 0x8006A508: bnel        $v1, $t3, L_8006A538
    if (ctx->r3 != ctx->r11) {
        // 0x8006A50C: lbu         $t5, 0x58($v0)
        ctx->r13 = MEM_BU(ctx->r2, 0X58);
            goto L_8006A538;
    }
    goto skip_4;
    // 0x8006A50C: lbu         $t5, 0x58($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X58);
    skip_4:
    // 0x8006A510: beql        $t4, $zero, L_8006A52C
    if (ctx->r12 == 0) {
        // 0x8006A514: lwc1        $f8, 0x14($v0)
        ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
            goto L_8006A52C;
    }
    goto skip_5;
    // 0x8006A514: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    skip_5:
    // 0x8006A518: lwc1        $f4, 0x14($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8006A51C: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x8006A520: b           L_8006A534
    // 0x8006A524: swc1        $f6, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f6.u32l;
        goto L_8006A534;
    // 0x8006A524: swc1        $f6, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f6.u32l;
    // 0x8006A528: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
L_8006A52C:
    // 0x8006A52C: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x8006A530: swc1        $f10, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f10.u32l;
L_8006A534:
    // 0x8006A534: lbu         $t5, 0x58($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X58);
L_8006A538:
    // 0x8006A538: addiu       $v0, $v0, 0x58
    ctx->r2 = ADD32(ctx->r2, 0X58);
    // 0x8006A53C: beql        $t5, $zero, L_8006A580
    if (ctx->r13 == 0) {
        // 0x8006A540: lbu         $t9, 0x58($v0)
        ctx->r25 = MEM_BU(ctx->r2, 0X58);
            goto L_8006A580;
    }
    goto skip_6;
    // 0x8006A540: lbu         $t9, 0x58($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X58);
    skip_6:
    // 0x8006A544: lhu         $t6, 0x2($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X2);
    // 0x8006A548: addiu       $t7, $s0, 0x1
    ctx->r15 = ADD32(ctx->r16, 0X1);
    // 0x8006A54C: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x8006A550: bnel        $v1, $t6, L_8006A580
    if (ctx->r3 != ctx->r14) {
        // 0x8006A554: lbu         $t9, 0x58($v0)
        ctx->r25 = MEM_BU(ctx->r2, 0X58);
            goto L_8006A580;
    }
    goto skip_7;
    // 0x8006A554: lbu         $t9, 0x58($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X58);
    skip_7:
    // 0x8006A558: beql        $t8, $zero, L_8006A574
    if (ctx->r24 == 0) {
        // 0x8006A55C: lwc1        $f4, 0x14($v0)
        ctx->f4.u32l = MEM_W(ctx->r2, 0X14);
            goto L_8006A574;
    }
    goto skip_8;
    // 0x8006A55C: lwc1        $f4, 0x14($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X14);
    skip_8:
    // 0x8006A560: lwc1        $f16, 0x14($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8006A564: add.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x8006A568: b           L_8006A57C
    // 0x8006A56C: swc1        $f18, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f18.u32l;
        goto L_8006A57C;
    // 0x8006A56C: swc1        $f18, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f18.u32l;
    // 0x8006A570: lwc1        $f4, 0x14($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X14);
L_8006A574:
    // 0x8006A574: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x8006A578: swc1        $f6, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f6.u32l;
L_8006A57C:
    // 0x8006A57C: lbu         $t9, 0x58($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X58);
L_8006A580:
    // 0x8006A580: addiu       $v0, $v0, 0x58
    ctx->r2 = ADD32(ctx->r2, 0X58);
    // 0x8006A584: beql        $t9, $zero, L_8006A5C8
    if (ctx->r25 == 0) {
        // 0x8006A588: lbu         $t3, 0x58($v0)
        ctx->r11 = MEM_BU(ctx->r2, 0X58);
            goto L_8006A5C8;
    }
    goto skip_9;
    // 0x8006A588: lbu         $t3, 0x58($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X58);
    skip_9:
    // 0x8006A58C: lhu         $t0, 0x2($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X2);
    // 0x8006A590: addiu       $t1, $s0, 0x2
    ctx->r9 = ADD32(ctx->r16, 0X2);
    // 0x8006A594: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x8006A598: bnel        $v1, $t0, L_8006A5C8
    if (ctx->r3 != ctx->r8) {
        // 0x8006A59C: lbu         $t3, 0x58($v0)
        ctx->r11 = MEM_BU(ctx->r2, 0X58);
            goto L_8006A5C8;
    }
    goto skip_10;
    // 0x8006A59C: lbu         $t3, 0x58($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X58);
    skip_10:
    // 0x8006A5A0: beql        $t2, $zero, L_8006A5BC
    if (ctx->r10 == 0) {
        // 0x8006A5A4: lwc1        $f16, 0x14($v0)
        ctx->f16.u32l = MEM_W(ctx->r2, 0X14);
            goto L_8006A5BC;
    }
    goto skip_11;
    // 0x8006A5A4: lwc1        $f16, 0x14($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X14);
    skip_11:
    // 0x8006A5A8: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8006A5AC: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x8006A5B0: b           L_8006A5C4
    // 0x8006A5B4: swc1        $f10, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f10.u32l;
        goto L_8006A5C4;
    // 0x8006A5B4: swc1        $f10, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f10.u32l;
    // 0x8006A5B8: lwc1        $f16, 0x14($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X14);
L_8006A5BC:
    // 0x8006A5BC: sub.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x8006A5C0: swc1        $f18, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f18.u32l;
L_8006A5C4:
    // 0x8006A5C4: lbu         $t3, 0x58($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X58);
L_8006A5C8:
    // 0x8006A5C8: addiu       $v0, $v0, 0x58
    ctx->r2 = ADD32(ctx->r2, 0X58);
    // 0x8006A5CC: beql        $t3, $zero, L_8006A610
    if (ctx->r11 == 0) {
        // 0x8006A5D0: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8006A610;
    }
    goto skip_12;
    // 0x8006A5D0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    skip_12:
    // 0x8006A5D4: lhu         $t4, 0x2($v0)
    ctx->r12 = MEM_HU(ctx->r2, 0X2);
    // 0x8006A5D8: addiu       $t5, $s0, 0x3
    ctx->r13 = ADD32(ctx->r16, 0X3);
    // 0x8006A5DC: andi        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 & 0X1;
    // 0x8006A5E0: bnel        $v1, $t4, L_8006A610
    if (ctx->r3 != ctx->r12) {
        // 0x8006A5E4: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8006A610;
    }
    goto skip_13;
    // 0x8006A5E4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    skip_13:
    // 0x8006A5E8: beql        $t6, $zero, L_8006A604
    if (ctx->r14 == 0) {
        // 0x8006A5EC: lwc1        $f8, 0x14($v0)
        ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
            goto L_8006A604;
    }
    goto skip_14;
    // 0x8006A5EC: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    skip_14:
    // 0x8006A5F0: lwc1        $f4, 0x14($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8006A5F4: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x8006A5F8: b           L_8006A60C
    // 0x8006A5FC: swc1        $f6, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f6.u32l;
        goto L_8006A60C;
    // 0x8006A5FC: swc1        $f6, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f6.u32l;
    // 0x8006A600: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
L_8006A604:
    // 0x8006A604: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x8006A608: swc1        $f10, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f10.u32l;
L_8006A60C:
    // 0x8006A60C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_8006A610:
    // 0x8006A610: bne         $s0, $a0, L_8006A4F4
    if (ctx->r16 != ctx->r4) {
        // 0x8006A614: addiu       $v0, $v0, 0x58
        ctx->r2 = ADD32(ctx->r2, 0X58);
            goto L_8006A4F4;
    }
    // 0x8006A614: addiu       $v0, $v0, 0x58
    ctx->r2 = ADD32(ctx->r2, 0X58);
L_8006A618:
    // 0x8006A618: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8006A61C: addiu       $a0, $a0, 0x3400
    ctx->r4 = ADD32(ctx->r4, 0X3400);
    // 0x8006A620: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8006A624:
    // 0x8006A624: lbu         $t7, 0x0($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X0);
    // 0x8006A628: beql        $t7, $zero, L_8006A644
    if (ctx->r15 == 0) {
        // 0x8006A62C: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8006A644;
    }
    goto skip_15;
    // 0x8006A62C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_15:
    // 0x8006A630: sw          $s0, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->r16;
    // 0x8006A634: jal         0x80069E88
    // 0x8006A638: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    Sprite_Update(rdram, ctx);
        goto after_2;
    // 0x8006A638: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_2:
    // 0x8006A63C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8006A640: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8006A644:
    // 0x8006A644: slti        $at, $s0, 0x28
    ctx->r1 = SIGNED(ctx->r16) < 0X28 ? 1 : 0;
    // 0x8006A648: bne         $at, $zero, L_8006A624
    if (ctx->r1 != 0) {
        // 0x8006A64C: addiu       $a0, $a0, 0x4C
        ctx->r4 = ADD32(ctx->r4, 0X4C);
            goto L_8006A624;
    }
    // 0x8006A64C: addiu       $a0, $a0, 0x4C
    ctx->r4 = ADD32(ctx->r4, 0X4C);
    // 0x8006A650: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8006A654: addiu       $a0, $a0, -0xEF0
    ctx->r4 = ADD32(ctx->r4, -0XEF0);
    // 0x8006A658: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8006A65C:
    // 0x8006A65C: lbu         $t8, 0x0($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X0);
    // 0x8006A660: beql        $t8, $zero, L_8006A67C
    if (ctx->r24 == 0) {
        // 0x8006A664: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8006A67C;
    }
    goto skip_16;
    // 0x8006A664: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_16:
    // 0x8006A668: sw          $s0, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->r16;
    // 0x8006A66C: jal         0x80069CBC
    // 0x8006A670: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    Boss_Update(rdram, ctx);
        goto after_3;
    // 0x8006A670: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    after_3:
    // 0x8006A674: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8006A678: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8006A67C:
    // 0x8006A67C: slti        $at, $s0, 0x4
    ctx->r1 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x8006A680: bne         $at, $zero, L_8006A65C
    if (ctx->r1 != 0) {
        // 0x8006A684: addiu       $a0, $a0, 0x408
        ctx->r4 = ADD32(ctx->r4, 0X408);
            goto L_8006A65C;
    }
    // 0x8006A684: addiu       $a0, $a0, 0x408
    ctx->r4 = ADD32(ctx->r4, 0X408);
    // 0x8006A688: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8006A68C: addiu       $a0, $a0, 0x3FE0
    ctx->r4 = ADD32(ctx->r4, 0X3FE0);
    // 0x8006A690: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8006A694:
    // 0x8006A694: lbu         $t9, 0x0($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X0);
    // 0x8006A698: beql        $t9, $zero, L_8006A6B4
    if (ctx->r25 == 0) {
        // 0x8006A69C: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8006A6B4;
    }
    goto skip_17;
    // 0x8006A69C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_17:
    // 0x8006A6A0: sw          $s0, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->r16;
    // 0x8006A6A4: jal         0x80069AAC
    // 0x8006A6A8: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    Actor_Update(rdram, ctx);
        goto after_4;
    // 0x8006A6A8: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    after_4:
    // 0x8006A6AC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8006A6B0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8006A6B4:
    // 0x8006A6B4: slti        $at, $s0, 0x3C
    ctx->r1 = SIGNED(ctx->r16) < 0X3C ? 1 : 0;
    // 0x8006A6B8: bne         $at, $zero, L_8006A694
    if (ctx->r1 != 0) {
        // 0x8006A6BC: addiu       $a0, $a0, 0x2F4
        ctx->r4 = ADD32(ctx->r4, 0X2F4);
            goto L_8006A694;
    }
    // 0x8006A6BC: addiu       $a0, $a0, 0x2F4
    ctx->r4 = ADD32(ctx->r4, 0X2F4);
    // 0x8006A6C0: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8006A6C4: addiu       $a0, $a0, 0x37E0
    ctx->r4 = ADD32(ctx->r4, 0X37E0);
    // 0x8006A6C8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8006A6CC:
    // 0x8006A6CC: lbu         $t0, 0x0($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X0);
    // 0x8006A6D0: beql        $t0, $zero, L_8006A6EC
    if (ctx->r8 == 0) {
        // 0x8006A6D4: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8006A6EC;
    }
    goto skip_18;
    // 0x8006A6D4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_18:
    // 0x8006A6D8: sw          $s0, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->r16;
    // 0x8006A6DC: jal         0x80069F30
    // 0x8006A6E0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    Item_Update(rdram, ctx);
        goto after_5;
    // 0x8006A6E0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_5:
    // 0x8006A6E4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8006A6E8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8006A6EC:
    // 0x8006A6EC: slti        $at, $s0, 0x14
    ctx->r1 = SIGNED(ctx->r16) < 0X14 ? 1 : 0;
    // 0x8006A6F0: bne         $at, $zero, L_8006A6CC
    if (ctx->r1 != 0) {
        // 0x8006A6F4: addiu       $a0, $a0, 0x6C
        ctx->r4 = ADD32(ctx->r4, 0X6C);
            goto L_8006A6CC;
    }
    // 0x8006A6F4: addiu       $a0, $a0, 0x6C
    ctx->r4 = ADD32(ctx->r4, 0X6C);
    // 0x8006A6F8: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8006A6FC: addiu       $a0, $a0, 0x130
    ctx->r4 = ADD32(ctx->r4, 0X130);
    // 0x8006A700: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8006A704:
    // 0x8006A704: lbu         $t1, 0x0($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X0);
    // 0x8006A708: beql        $t1, $zero, L_8006A724
    if (ctx->r9 == 0) {
        // 0x8006A70C: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8006A724;
    }
    goto skip_19;
    // 0x8006A70C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_19:
    // 0x8006A710: sw          $s0, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->r16;
    // 0x8006A714: jal         0x80069FD4
    // 0x8006A718: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    Effect_Update(rdram, ctx);
        goto after_6;
    // 0x8006A718: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_6:
    // 0x8006A71C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8006A720: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8006A724:
    // 0x8006A724: slti        $at, $s0, 0x64
    ctx->r1 = SIGNED(ctx->r16) < 0X64 ? 1 : 0;
    // 0x8006A728: bne         $at, $zero, L_8006A704
    if (ctx->r1 != 0) {
        // 0x8006A72C: addiu       $a0, $a0, 0x8C
        ctx->r4 = ADD32(ctx->r4, 0X8C);
            goto L_8006A704;
    }
    // 0x8006A72C: addiu       $a0, $a0, 0x8C
    ctx->r4 = ADD32(ctx->r4, 0X8C);
    // 0x8006A730: jal         0x8006A38C
    // 0x8006A734: nop

    TexturedLine_UpdateAll(rdram, ctx);
        goto after_7;
    // 0x8006A734: nop

    after_7:
    // 0x8006A738: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8006A73C: lw          $v0, 0x1670($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1670);
    // 0x8006A740: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8006A744: beq         $v0, $zero, L_8006A750
    if (ctx->r2 == 0) {
        // 0x8006A748: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_8006A750;
    }
    // 0x8006A748: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8006A74C: sw          $v0, 0x1670($at)
    MEM_W(0X1670, ctx->r1) = ctx->r2;
L_8006A750:
    // 0x8006A750: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8006A754: lw          $v0, 0x1674($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1674);
    // 0x8006A758: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8006A75C: beq         $v0, $zero, L_8006A768
    if (ctx->r2 == 0) {
        // 0x8006A760: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_8006A768;
    }
    // 0x8006A760: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8006A764: sw          $v0, 0x1674($at)
    MEM_W(0X1674, ctx->r1) = ctx->r2;
L_8006A768:
    // 0x8006A768: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8006A76C: lw          $v0, 0x1678($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1678);
    // 0x8006A770: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8006A774: beq         $v0, $zero, L_8006A780
    if (ctx->r2 == 0) {
        // 0x8006A778: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_8006A780;
    }
    // 0x8006A778: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8006A77C: sw          $v0, 0x1678($at)
    MEM_W(0X1678, ctx->r1) = ctx->r2;
L_8006A780:
    // 0x8006A780: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8006A784: lw          $v0, 0x167C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X167C);
    // 0x8006A788: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8006A78C: beq         $v0, $zero, L_8006A798
    if (ctx->r2 == 0) {
        // 0x8006A790: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_8006A798;
    }
    // 0x8006A790: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8006A794: sw          $v0, 0x167C($at)
    MEM_W(0X167C, ctx->r1) = ctx->r2;
L_8006A798:
    // 0x8006A798: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006A79C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8006A7A0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8006A7A4: jr          $ra
    // 0x8006A7A8: nop

    return;
    // 0x8006A7A8: nop

;}
RECOMP_FUNC void AudioLoad_DecreaseSampleDmaTtls(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E4A0: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8000E4A4: addiu       $a1, $a1, 0x5A4C
    ctx->r5 = ADD32(ctx->r5, 0X5A4C);
    // 0x8000E4A8: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8000E4AC: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8000E4B0: addiu       $a0, $a0, 0x4A48
    ctx->r4 = ADD32(ctx->r4, 0X4A48);
    // 0x8000E4B4: beq         $v1, $zero, L_8000E518
    if (ctx->r3 == 0) {
        // 0x8000E4B8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8000E518;
    }
    // 0x8000E4B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000E4BC: lui         $a3, 0x8015
    ctx->r7 = S32(0X8015 << 16);
    // 0x8000E4C0: lui         $a2, 0x8015
    ctx->r6 = S32(0X8015 << 16);
    // 0x8000E4C4: addiu       $a2, $a2, 0x5C5A
    ctx->r6 = ADD32(ctx->r6, 0X5C5A);
    // 0x8000E4C8: addiu       $a3, $a3, 0x5A58
    ctx->r7 = ADD32(ctx->r7, 0X5A58);
    // 0x8000E4CC: lbu         $v1, 0xE($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0XE);
L_8000E4D0:
    // 0x8000E4D0: beq         $v1, $zero, L_8000E500
    if (ctx->r3 == 0) {
        // 0x8000E4D4: addiu       $t6, $v1, -0x1
        ctx->r14 = ADD32(ctx->r3, -0X1);
            goto L_8000E500;
    }
    // 0x8000E4D4: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x8000E4D8: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x8000E4DC: bne         $t7, $zero, L_8000E500
    if (ctx->r15 != 0) {
        // 0x8000E4E0: sb          $t6, 0xE($a0)
        MEM_B(0XE, ctx->r4) = ctx->r14;
            goto L_8000E500;
    }
    // 0x8000E4E0: sb          $t6, 0xE($a0)
    MEM_B(0XE, ctx->r4) = ctx->r14;
    // 0x8000E4E4: lbu         $v1, 0x0($a2)
    ctx->r3 = MEM_BU(ctx->r6, 0X0);
    // 0x8000E4E8: lbu         $t8, 0x0($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X0);
    // 0x8000E4EC: addu        $t9, $a3, $v1
    ctx->r25 = ADD32(ctx->r7, ctx->r3);
    // 0x8000E4F0: sb          $v0, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r2;
    // 0x8000E4F4: addiu       $t0, $v1, 0x1
    ctx->r8 = ADD32(ctx->r3, 0X1);
    // 0x8000E4F8: sb          $t0, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r8;
    // 0x8000E4FC: sb          $t8, 0xD($a0)
    MEM_B(0XD, ctx->r4) = ctx->r24;
L_8000E500:
    // 0x8000E500: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8000E504: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8000E508: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x8000E50C: sltu        $at, $v0, $v1
    ctx->r1 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x8000E510: bnel        $at, $zero, L_8000E4D0
    if (ctx->r1 != 0) {
        // 0x8000E514: lbu         $v1, 0xE($a0)
        ctx->r3 = MEM_BU(ctx->r4, 0XE);
            goto L_8000E4D0;
    }
    goto skip_0;
    // 0x8000E514: lbu         $v1, 0xE($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0XE);
    skip_0:
L_8000E518:
    // 0x8000E518: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8000E51C: addiu       $a1, $a1, 0x5A48
    ctx->r5 = ADD32(ctx->r5, 0X5A48);
    // 0x8000E520: lw          $t1, 0x0($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X0);
    // 0x8000E524: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8000E528: sll         $t2, $v1, 4
    ctx->r10 = S32(ctx->r3 << 4);
    // 0x8000E52C: sltu        $at, $v1, $t1
    ctx->r1 = ctx->r3 < ctx->r9 ? 1 : 0;
    // 0x8000E530: beq         $at, $zero, L_8000E59C
    if (ctx->r1 == 0) {
        // 0x8000E534: lui         $t3, 0x8015
        ctx->r11 = S32(0X8015 << 16);
            goto L_8000E59C;
    }
    // 0x8000E534: lui         $t3, 0x8015
    ctx->r11 = S32(0X8015 << 16);
    // 0x8000E538: addiu       $t3, $t3, 0x4A48
    ctx->r11 = ADD32(ctx->r11, 0X4A48);
    // 0x8000E53C: lui         $a3, 0x8015
    ctx->r7 = S32(0X8015 << 16);
    // 0x8000E540: lui         $a2, 0x8015
    ctx->r6 = S32(0X8015 << 16);
    // 0x8000E544: addiu       $a2, $a2, 0x5C5B
    ctx->r6 = ADD32(ctx->r6, 0X5C5B);
    // 0x8000E548: addiu       $a3, $a3, 0x5B58
    ctx->r7 = ADD32(ctx->r7, 0X5B58);
    // 0x8000E54C: addu        $a0, $t2, $t3
    ctx->r4 = ADD32(ctx->r10, ctx->r11);
    // 0x8000E550: lbu         $v1, 0xE($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0XE);
L_8000E554:
    // 0x8000E554: beq         $v1, $zero, L_8000E584
    if (ctx->r3 == 0) {
        // 0x8000E558: addiu       $t4, $v1, -0x1
        ctx->r12 = ADD32(ctx->r3, -0X1);
            goto L_8000E584;
    }
    // 0x8000E558: addiu       $t4, $v1, -0x1
    ctx->r12 = ADD32(ctx->r3, -0X1);
    // 0x8000E55C: andi        $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 & 0XFF;
    // 0x8000E560: bne         $t5, $zero, L_8000E584
    if (ctx->r13 != 0) {
        // 0x8000E564: sb          $t4, 0xE($a0)
        MEM_B(0XE, ctx->r4) = ctx->r12;
            goto L_8000E584;
    }
    // 0x8000E564: sb          $t4, 0xE($a0)
    MEM_B(0XE, ctx->r4) = ctx->r12;
    // 0x8000E568: lbu         $v1, 0x0($a2)
    ctx->r3 = MEM_BU(ctx->r6, 0X0);
    // 0x8000E56C: lbu         $t6, 0x0($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X0);
    // 0x8000E570: addu        $t7, $a3, $v1
    ctx->r15 = ADD32(ctx->r7, ctx->r3);
    // 0x8000E574: sb          $v0, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r2;
    // 0x8000E578: addiu       $t8, $v1, 0x1
    ctx->r24 = ADD32(ctx->r3, 0X1);
    // 0x8000E57C: sb          $t8, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r24;
    // 0x8000E580: sb          $t6, 0xD($a0)
    MEM_B(0XD, ctx->r4) = ctx->r14;
L_8000E584:
    // 0x8000E584: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x8000E588: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8000E58C: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x8000E590: sltu        $at, $v0, $t9
    ctx->r1 = ctx->r2 < ctx->r25 ? 1 : 0;
    // 0x8000E594: bnel        $at, $zero, L_8000E554
    if (ctx->r1 != 0) {
        // 0x8000E598: lbu         $v1, 0xE($a0)
        ctx->r3 = MEM_BU(ctx->r4, 0XE);
            goto L_8000E554;
    }
    goto skip_1;
    // 0x8000E598: lbu         $v1, 0xE($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0XE);
    skip_1:
L_8000E59C:
    // 0x8000E59C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8000E5A0: jr          $ra
    // 0x8000E5A4: sw          $zero, 0x5A50($at)
    MEM_W(0X5A50, ctx->r1) = 0;
    return;
    // 0x8000E5A4: sw          $zero, 0x5A50($at)
    MEM_W(0X5A50, ctx->r1) = 0;
;}
RECOMP_FUNC void PlayerShot_DrawHitmark(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038F34: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80038F38: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80038F3C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80038F40: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80038F44: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x80038F48: addiu       $t7, $t7, -0x6434
    ctx->r15 = ADD32(ctx->r15, -0X6434);
    // 0x80038F4C: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x80038F50: addiu       $t6, $sp, 0x4C
    ctx->r14 = ADD32(ctx->r29, 0X4C);
    // 0x80038F54: lw          $t1, 0x4($t7)
    ctx->r9 = MEM_W(ctx->r15, 0X4);
    // 0x80038F58: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x80038F5C: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x80038F60: sw          $t1, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r9;
    // 0x80038F64: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80038F68: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x80038F6C: sw          $zero, 0x48($sp)
    MEM_W(0X48, ctx->r29) = 0;
    // 0x80038F70: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80038F74: lwc1        $f6, 0x7D20($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x80038F78: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80038F7C: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    // 0x80038F80: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x80038F84: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80038F88: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80038F8C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80038F90: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80038F94: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x80038F98: jal         0x80005B00
    // 0x80038F9C: nop

    Matrix_Translate(rdram, ctx);
        goto after_0;
    // 0x80038F9C: nop

    after_0:
    // 0x80038FA0: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80038FA4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80038FA8: addiu       $a2, $a2, -0x6B0
    ctx->r6 = ADD32(ctx->r6, -0X6B0);
    // 0x80038FAC: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80038FB0: jal         0x80006970
    // 0x80038FB4: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    Matrix_MultVec3f(rdram, ctx);
        goto after_1;
    // 0x80038FB4: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    after_1:
    // 0x80038FB8: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80038FBC: addiu       $a2, $a2, -0x6B0
    ctx->r6 = ADD32(ctx->r6, -0X6B0);
    // 0x80038FC0: lwc1        $f2, 0x8($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X8);
    // 0x80038FC4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80038FC8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80038FCC: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x80038FD0: c.lt.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl < ctx->f10.fl;
    // 0x80038FD4: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x80038FD8: bc1fl       L_80039050
    if (!c1cs) {
        // 0x80038FDC: lw          $t4, 0x48($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X48);
            goto L_80039050;
    }
    goto skip_0;
    // 0x80038FDC: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    skip_0:
    // 0x80038FE0: lwc1        $f18, 0x5278($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X5278);
    // 0x80038FE4: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x80038FE8: c.lt.s      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl < ctx->f2.fl;
    // 0x80038FEC: nop

    // 0x80038FF0: bc1fl       L_80039050
    if (!c1cs) {
        // 0x80038FF4: lw          $t4, 0x48($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X48);
            goto L_80039050;
    }
    goto skip_1;
    // 0x80038FF4: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    skip_1:
    // 0x80038FF8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80038FFC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80039000: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80039004: lwc1        $f0, 0x0($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80039008: mul.s       $f14, $f2, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x8003900C: abs.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = fabsf(ctx->f0.fl);
    // 0x80039010: abs.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = fabsf(ctx->f14.fl);
    // 0x80039014: add.s       $f6, $f14, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f14.fl + ctx->f16.fl;
    // 0x80039018: c.lt.s      $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f12.fl < ctx->f6.fl;
    // 0x8003901C: nop

    // 0x80039020: bc1fl       L_80039050
    if (!c1cs) {
        // 0x80039024: lw          $t4, 0x48($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X48);
            goto L_80039050;
    }
    goto skip_2;
    // 0x80039024: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    skip_2:
    // 0x80039028: lwc1        $f0, 0x4($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X4);
    // 0x8003902C: add.s       $f8, $f14, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f14.fl + ctx->f16.fl;
    // 0x80039030: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80039034: abs.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = fabsf(ctx->f0.fl);
    // 0x80039038: c.lt.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl < ctx->f8.fl;
    // 0x8003903C: nop

    // 0x80039040: bc1fl       L_80039050
    if (!c1cs) {
        // 0x80039044: lw          $t4, 0x48($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X48);
            goto L_80039050;
    }
    goto skip_3;
    // 0x80039044: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    skip_3:
    // 0x80039048: sw          $t3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r11;
    // 0x8003904C: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
L_80039050:
    // 0x80039050: bne         $t4, $zero, L_80039078
    if (ctx->r12 != 0) {
        // 0x80039054: nop
    
            goto L_80039078;
    }
    // 0x80039054: nop

    // 0x80039058: lw          $t5, 0x78E8($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X78E8);
    // 0x8003905C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80039060: bnel        $t5, $zero, L_80039200
    if (ctx->r13 != 0) {
        // 0x80039064: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80039200;
    }
    goto skip_4;
    // 0x80039064: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_4:
    // 0x80039068: jal         0x80060FBC
    // 0x8003906C: addiu       $a1, $s0, 0x38
    ctx->r5 = ADD32(ctx->r16, 0X38);
    Object_Kill(rdram, ctx);
        goto after_2;
    // 0x8003906C: addiu       $a1, $s0, 0x38
    ctx->r5 = ADD32(ctx->r16, 0X38);
    after_2:
    // 0x80039070: b           L_80039200
    // 0x80039074: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80039200;
    // 0x80039074: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80039078:
    // 0x80039078: lw          $t8, 0x78A0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X78A0);
    // 0x8003907C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80039080: lw          $t9, -0x7D80($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7D80);
    // 0x80039084: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x80039088: addu        $t6, $t6, $t8
    ctx->r14 = ADD32(ctx->r14, ctx->r24);
    // 0x8003908C: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80039090: subu        $t6, $t6, $t8
    ctx->r14 = SUB32(ctx->r14, ctx->r24);
    // 0x80039094: sll         $t6, $t6, 5
    ctx->r14 = S32(ctx->r14 << 5);
    // 0x80039098: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x8003909C: lwc1        $f10, 0x58($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X58);
    // 0x800390A0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800390A4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800390A8: neg.s       $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = -ctx->f10.fl;
    // 0x800390AC: swc1        $f18, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f18.u32l;
    // 0x800390B0: lw          $a1, 0x14($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X14);
    // 0x800390B4: jal         0x80005E90
    // 0x800390B8: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_RotateY(rdram, ctx);
        goto after_3;
    // 0x800390B8: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_3:
    // 0x800390BC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800390C0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800390C4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800390C8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800390CC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800390D0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800390D4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800390D8: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x800390DC: jal         0x80005C34
    // 0x800390E0: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Scale(rdram, ctx);
        goto after_4;
    // 0x800390E0: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_4:
    // 0x800390E4: lhu         $t2, 0x2($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X2);
    // 0x800390E8: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x800390EC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800390F0: bne         $t2, $at, L_80039118
    if (ctx->r10 != ctx->r1) {
        // 0x800390F4: lui         $at, 0x800D
        ctx->r1 = S32(0X800D << 16);
            goto L_80039118;
    }
    // 0x800390F4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800390F8: lwc1        $f0, 0x527C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X527C);
    // 0x800390FC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80039100: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80039104: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80039108: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8003910C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80039110: jal         0x80005C34
    // 0x80039114: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Scale(rdram, ctx);
        goto after_5;
    // 0x80039114: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_5:
L_80039118:
    // 0x80039118: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8003911C: jal         0x80006EB8
    // 0x80039120: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_6;
    // 0x80039120: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    after_6:
    // 0x80039124: jal         0x800B99C0
    // 0x80039128: nop

    RCP_SetupDL_40(rdram, ctx);
        goto after_7;
    // 0x80039128: nop

    after_7:
    // 0x8003912C: lw          $v0, 0x60($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X60);
    // 0x80039130: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80039134: addiu       $t0, $t0, 0x7E64
    ctx->r8 = ADD32(ctx->r8, 0X7E64);
    // 0x80039138: beq         $v0, $zero, L_80039160
    if (ctx->r2 == 0) {
        // 0x8003913C: lui         $t5, 0x600
        ctx->r13 = S32(0X600 << 16);
            goto L_80039160;
    }
    // 0x8003913C: lui         $t5, 0x600
    ctx->r13 = S32(0X600 << 16);
    // 0x80039140: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80039144: beq         $v0, $at, L_80039184
    if (ctx->r2 == ctx->r1) {
        // 0x80039148: lui         $t6, 0x600
        ctx->r14 = S32(0X600 << 16);
            goto L_80039184;
    }
    // 0x80039148: lui         $t6, 0x600
    ctx->r14 = S32(0X600 << 16);
    // 0x8003914C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80039150: beq         $v0, $at, L_800391A8
    if (ctx->r2 == ctx->r1) {
        // 0x80039154: lui         $a0, 0x8014
        ctx->r4 = S32(0X8014 << 16);
            goto L_800391A8;
    }
    // 0x80039154: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80039158: b           L_80039200
    // 0x8003915C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80039200;
    // 0x8003915C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80039160:
    // 0x80039160: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x80039164: lui         $t8, 0x102
    ctx->r24 = S32(0X102 << 16);
    // 0x80039168: addiu       $t8, $t8, 0x6090
    ctx->r24 = ADD32(ctx->r24, 0X6090);
    // 0x8003916C: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x80039170: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
    // 0x80039174: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80039178: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8003917C: b           L_80039200
    // 0x80039180: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80039200;
    // 0x80039180: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80039184:
    // 0x80039184: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x80039188: lui         $t7, 0x102
    ctx->r15 = S32(0X102 << 16);
    // 0x8003918C: addiu       $t7, $t7, 0x5800
    ctx->r15 = ADD32(ctx->r15, 0X5800);
    // 0x80039190: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80039194: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x80039198: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8003919C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800391A0: b           L_80039200
    // 0x800391A4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80039200;
    // 0x800391A4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800391A8:
    // 0x800391A8: lui         $a2, 0x3F33
    ctx->r6 = S32(0X3F33 << 16);
    // 0x800391AC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800391B0: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x800391B4: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x800391B8: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x800391BC: lui         $a1, 0x3FC0
    ctx->r5 = S32(0X3FC0 << 16);
    // 0x800391C0: jal         0x80005C34
    // 0x800391C4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_8;
    // 0x800391C4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_8:
    // 0x800391C8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800391CC: jal         0x80006EB8
    // 0x800391D0: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_9;
    // 0x800391D0: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    after_9:
    // 0x800391D4: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x800391D8: addiu       $t0, $t0, 0x7E64
    ctx->r8 = ADD32(ctx->r8, 0X7E64);
    // 0x800391DC: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800391E0: lui         $t4, 0x102
    ctx->r12 = S32(0X102 << 16);
    // 0x800391E4: addiu       $t4, $t4, 0x5800
    ctx->r12 = ADD32(ctx->r12, 0X5800);
    // 0x800391E8: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x800391EC: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x800391F0: lui         $t3, 0x600
    ctx->r11 = S32(0X600 << 16);
    // 0x800391F4: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x800391F8: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x800391FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80039200:
    // 0x80039200: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80039204: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80039208: jr          $ra
    // 0x8003920C: nop

    return;
    // 0x8003920C: nop

;}
RECOMP_FUNC void func_col1_80097558(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80097558: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8009755C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80097560: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x80097564: lh          $v1, 0x0($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X0);
    // 0x80097568: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    // 0x8009756C: lh          $a3, 0x4($v0)
    ctx->r7 = MEM_H(ctx->r2, 0X4);
    // 0x80097570: lw          $v0, -0x4($a1)
    ctx->r2 = MEM_W(ctx->r5, -0X4);
    // 0x80097574: lh          $t1, 0x2($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X2);
    // 0x80097578: lh          $t0, 0x0($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X0);
    // 0x8009757C: lh          $t2, 0x4($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X4);
    // 0x80097580: subu        $t8, $t1, $a2
    ctx->r24 = SUB32(ctx->r9, ctx->r6);
    // 0x80097584: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x80097588: negu        $t8, $v1
    ctx->r24 = SUB32(0, ctx->r3);
    // 0x8009758C: multu       $t8, $t1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80097590: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80097594: subu        $t6, $t0, $v1
    ctx->r14 = SUB32(ctx->r8, ctx->r3);
    // 0x80097598: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8009759C: lh          $t4, 0x2($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X2);
    // 0x800975A0: lh          $t5, 0x4($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X4);
    // 0x800975A4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800975A8: subu        $t9, $t4, $t1
    ctx->r25 = SUB32(ctx->r12, ctx->r9);
    // 0x800975AC: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x800975B0: lh          $t3, 0x0($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X0);
    // 0x800975B4: mflo        $t9
    ctx->r25 = lo;
    // 0x800975B8: subu        $t6, $t2, $a3
    ctx->r14 = SUB32(ctx->r10, ctx->r7);
    // 0x800975BC: subu        $t7, $t3, $t0
    ctx->r15 = SUB32(ctx->r11, ctx->r8);
    // 0x800975C0: multu       $t9, $t5
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800975C4: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x800975C8: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800975CC: subu        $t7, $t5, $t2
    ctx->r15 = SUB32(ctx->r13, ctx->r10);
    // 0x800975D0: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x800975D4: swc1        $f6, 0x1950($at)
    MEM_W(0X1950, ctx->r1) = ctx->f6.u32l;
    // 0x800975D8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800975DC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800975E0: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x800975E4: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x800975E8: mflo        $t6
    ctx->r14 = lo;
    // 0x800975EC: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x800975F0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800975F4: multu       $t0, $t4
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800975F8: swc1        $f10, 0x1954($at)
    MEM_W(0X1954, ctx->r1) = ctx->f10.u32l;
    // 0x800975FC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80097600: swc1        $f18, 0x1958($at)
    MEM_W(0X1958, ctx->r1) = ctx->f18.u32l;
    // 0x80097604: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80097608: addiu       $a1, $a1, 0x1960
    ctx->r5 = ADD32(ctx->r5, 0X1960);
    // 0x8009760C: addiu       $v0, $v0, 0x195C
    ctx->r2 = ADD32(ctx->r2, 0X195C);
    // 0x80097610: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x80097614: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80097618: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8009761C: mflo        $t7
    ctx->r15 = lo;
    // 0x80097620: swc1        $f10, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f10.u32l;
    // 0x80097624: nop

    // 0x80097628: multu       $t7, $a3
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009762C: swc1        $f18, 0x1964($at)
    MEM_W(0X1964, ctx->r1) = ctx->f18.u32l;
    // 0x80097630: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80097634: lwc1        $f4, 0x1958($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X1958);
    // 0x80097638: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8009763C: lwc1        $f8, 0x0($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80097640: mul.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x80097644: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80097648: mflo        $t8
    ctx->r24 = lo;
    // 0x8009764C: subu        $t9, $t6, $t8
    ctx->r25 = SUB32(ctx->r14, ctx->r24);
    // 0x80097650: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80097654: sub.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f16.fl;
    // 0x80097658: multu       $t3, $a2
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009765C: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x80097660: lwc1        $f8, 0x1954($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X1954);
    // 0x80097664: lwc1        $f18, 0x0($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80097668: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8009766C: lwc1        $f6, 0x1950($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X1950);
    // 0x80097670: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80097674: mul.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x80097678: mflo        $t7
    ctx->r15 = lo;
    // 0x8009767C: lwc1        $f16, 0x1964($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X1964);
    // 0x80097680: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80097684: multu       $t7, $t2
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80097688: mul.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x8009768C: sub.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80097690: mflo        $t6
    ctx->r14 = lo;
    // 0x80097694: subu        $t8, $t9, $t6
    ctx->r24 = SUB32(ctx->r25, ctx->r14);
    // 0x80097698: swc1        $f18, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f18.u32l;
    // 0x8009769C: multu       $v1, $t4
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800976A0: lwc1        $f8, 0x1950($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X1950);
    // 0x800976A4: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800976A8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800976AC: lwc1        $f10, 0x1958($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X1958);
    // 0x800976B0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800976B4: mul.s       $f16, $f8, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x800976B8: lwc1        $f4, 0x1954($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X1954);
    // 0x800976BC: mflo        $t7
    ctx->r15 = lo;
    // 0x800976C0: mul.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800976C4: sub.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800976C8: multu       $t7, $t2
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800976CC: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
    // 0x800976D0: mflo        $t9
    ctx->r25 = lo;
    // 0x800976D4: addu        $t6, $t8, $t9
    ctx->r14 = ADD32(ctx->r24, ctx->r25);
    // 0x800976D8: nop

    // 0x800976DC: multu       $t0, $a2
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800976E0: mflo        $t7
    ctx->r15 = lo;
    // 0x800976E4: nop

    // 0x800976E8: nop

    // 0x800976EC: multu       $t7, $t5
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800976F0: mflo        $t8
    ctx->r24 = lo;
    // 0x800976F4: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x800976F8: nop

    // 0x800976FC: multu       $t3, $t1
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80097700: mflo        $t7
    ctx->r15 = lo;
    // 0x80097704: nop

    // 0x80097708: nop

    // 0x8009770C: multu       $t7, $a3
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80097710: mflo        $t6
    ctx->r14 = lo;
    // 0x80097714: addu        $t8, $t9, $t6
    ctx->r24 = ADD32(ctx->r25, ctx->r14);
    // 0x80097718: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x8009771C: nop

    // 0x80097720: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80097724: swc1        $f10, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f10.u32l;
    // 0x80097728: jr          $ra
    // 0x8009772C: nop

    return;
    // 0x8009772C: nop

;}
RECOMP_FUNC void CoIBeam_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059BBC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80059BC0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80059BC4: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x80059BC8: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80059BCC: lui         $t8, 0x602
    ctx->r24 = S32(0X602 << 16);
    // 0x80059BD0: addiu       $t8, $t8, 0x3AC0
    ctx->r24 = ADD32(ctx->r24, 0X3AC0);
    // 0x80059BD4: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80059BD8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80059BDC: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80059BE0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80059BE4: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80059BE8: jr          $ra
    // 0x80059BEC: nop

    return;
    // 0x80059BEC: nop

;}
RECOMP_FUNC void HUD_RadarMarks_Setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A240: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8008A244: sw          $s2, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r18;
    // 0x8008A248: sw          $s1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r17;
    // 0x8008A24C: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x8008A250: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8008A254: lw          $v1, 0x78A8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X78A8);
    // 0x8008A258: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8008A25C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8008A260: blez        $v1, L_8008A354
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8008A264: lui         $at, 0x4316
        ctx->r1 = S32(0X4316 << 16);
            goto L_8008A354;
    }
    // 0x8008A264: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x8008A268: lui         $s1, 0x8017
    ctx->r17 = S32(0X8017 << 16);
    // 0x8008A26C: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x8008A270: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x8008A274: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x8008A278: lui         $a3, 0x8017
    ctx->r7 = S32(0X8017 << 16);
    // 0x8008A27C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8008A280: addiu       $a3, $a3, 0x78E8
    ctx->r7 = ADD32(ctx->r7, 0X78E8);
    // 0x8008A284: addiu       $t0, $t0, 0x5A10
    ctx->r8 = ADD32(ctx->r8, 0X5A10);
    // 0x8008A288: addiu       $t3, $t3, 0x78A0
    ctx->r11 = ADD32(ctx->r11, 0X78A0);
    // 0x8008A28C: addiu       $t5, $t5, 0x789C
    ctx->r13 = ADD32(ctx->r13, 0X789C);
    // 0x8008A290: addiu       $s1, $s1, 0x7DB0
    ctx->r17 = ADD32(ctx->r17, 0X7DB0);
    // 0x8008A294: lw          $a0, -0x7D80($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7D80);
    // 0x8008A298: addiu       $s2, $zero, 0x3E7
    ctx->r18 = ADD32(0, 0X3E7);
    // 0x8008A29C: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
    // 0x8008A2A0: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x8008A2A4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8008A2A8: addiu       $t1, $zero, 0x28
    ctx->r9 = ADD32(0, 0X28);
    // 0x8008A2AC: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
L_8008A2B0:
    // 0x8008A2B0: lw          $t6, 0x1C8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1C8);
    // 0x8008A2B4: beql        $a2, $t6, L_8008A348
    if (ctx->r6 == ctx->r14) {
        // 0x8008A2B8: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8008A348;
    }
    goto skip_0;
    // 0x8008A2B8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_0:
    // 0x8008A2BC: multu       $v0, $t1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008A2C0: lw          $t8, 0x0($t3)
    ctx->r24 = MEM_W(ctx->r11, 0X0);
    // 0x8008A2C4: mflo        $t7
    ctx->r15 = lo;
    // 0x8008A2C8: addu        $a1, $t0, $t7
    ctx->r5 = ADD32(ctx->r8, ctx->r15);
    // 0x8008A2CC: sb          $t2, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r10;
    // 0x8008A2D0: sh          $v0, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r2;
    // 0x8008A2D4: lwc1        $f6, 0x114($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X114);
    // 0x8008A2D8: lwc1        $f4, 0xE8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XE8);
    // 0x8008A2DC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8008A2E0: swc1        $f8, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f8.u32l;
    // 0x8008A2E4: lwc1        $f10, 0x138($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X138);
    // 0x8008A2E8: swc1        $f10, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f10.u32l;
    // 0x8008A2EC: lwc1        $f16, 0x74($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X74);
    // 0x8008A2F0: beq         $v0, $t8, L_8008A344
    if (ctx->r2 == ctx->r24) {
        // 0x8008A2F4: swc1        $f16, 0x4($a1)
        MEM_W(0X4, ctx->r5) = ctx->f16.u32l;
            goto L_8008A344;
    }
    // 0x8008A2F4: swc1        $f16, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f16.u32l;
    // 0x8008A2F8: lw          $t9, 0x0($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X0);
    // 0x8008A2FC: beql        $t9, $zero, L_8008A314
    if (ctx->r25 == 0) {
        // 0x8008A300: lw          $t7, 0x1C8($a0)
        ctx->r15 = MEM_W(ctx->r4, 0X1C8);
            goto L_8008A314;
    }
    goto skip_1;
    // 0x8008A300: lw          $t7, 0x1C8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1C8);
    skip_1:
    // 0x8008A304: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x8008A308: beql        $t4, $t6, L_8008A348
    if (ctx->r12 == ctx->r14) {
        // 0x8008A30C: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8008A348;
    }
    goto skip_2;
    // 0x8008A30C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_2:
    // 0x8008A310: lw          $t7, 0x1C8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1C8);
L_8008A314:
    // 0x8008A314: bnel        $s0, $t7, L_8008A348
    if (ctx->r16 != ctx->r15) {
        // 0x8008A318: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8008A348;
    }
    goto skip_3;
    // 0x8008A318: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_3:
    // 0x8008A31C: lwc1        $f18, 0x78($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X78);
    // 0x8008A320: c.le.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl <= ctx->f18.fl;
    // 0x8008A324: nop

    // 0x8008A328: bc1tl       L_8008A348
    if (c1cs) {
        // 0x8008A32C: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8008A348;
    }
    goto skip_4;
    // 0x8008A32C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_4:
    // 0x8008A330: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x8008A334: andi        $t9, $t8, 0x3F
    ctx->r25 = ctx->r24 & 0X3F;
    // 0x8008A338: beql        $t9, $zero, L_8008A348
    if (ctx->r25 == 0) {
        // 0x8008A33C: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8008A348;
    }
    goto skip_5;
    // 0x8008A33C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_5:
    // 0x8008A340: sh          $s2, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r18;
L_8008A344:
    // 0x8008A344: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_8008A348:
    // 0x8008A348: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8008A34C: bne         $at, $zero, L_8008A2B0
    if (ctx->r1 != 0) {
        // 0x8008A350: addiu       $a0, $a0, 0x4E0
        ctx->r4 = ADD32(ctx->r4, 0X4E0);
            goto L_8008A2B0;
    }
    // 0x8008A350: addiu       $a0, $a0, 0x4E0
    ctx->r4 = ADD32(ctx->r4, 0X4E0);
L_8008A354:
    // 0x8008A354: lui         $a3, 0x8017
    ctx->r7 = S32(0X8017 << 16);
    // 0x8008A358: addiu       $a3, $a3, 0x78E8
    ctx->r7 = ADD32(ctx->r7, 0X78E8);
    // 0x8008A35C: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x8008A360: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x8008A364: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8008A368: addiu       $t0, $t0, 0x5A10
    ctx->r8 = ADD32(ctx->r8, 0X5A10);
    // 0x8008A36C: addiu       $t1, $zero, 0x28
    ctx->r9 = ADD32(0, 0X28);
    // 0x8008A370: bne         $t6, $at, L_8008A4C8
    if (ctx->r14 != ctx->r1) {
        // 0x8008A374: addiu       $t2, $zero, 0x1
        ctx->r10 = ADD32(0, 0X1);
            goto L_8008A4C8;
    }
    // 0x8008A374: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8008A378: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8008A37C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8008A380: addiu       $v1, $v1, 0x37E0
    ctx->r3 = ADD32(ctx->r3, 0X37E0);
    // 0x8008A384: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8008A388: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8008A38C: addiu       $a0, $zero, 0x67
    ctx->r4 = ADD32(0, 0X67);
L_8008A390:
    // 0x8008A390: lbu         $t7, 0x0($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X0);
    // 0x8008A394: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x8008A398: slti        $at, $t7, 0x2
    ctx->r1 = SIGNED(ctx->r15) < 0X2 ? 1 : 0;
    // 0x8008A39C: bnel        $at, $zero, L_8008A42C
    if (ctx->r1 != 0) {
        // 0x8008A3A0: lbu         $t6, 0x6C($v1)
        ctx->r14 = MEM_BU(ctx->r3, 0X6C);
            goto L_8008A42C;
    }
    goto skip_6;
    // 0x8008A3A0: lbu         $t6, 0x6C($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X6C);
    skip_6:
    // 0x8008A3A4: lw          $t8, 0x40($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X40);
    // 0x8008A3A8: multu       $t8, $t1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008A3AC: mflo        $t9
    ctx->r25 = lo;
    // 0x8008A3B0: addu        $t6, $t0, $t9
    ctx->r14 = ADD32(ctx->r8, ctx->r25);
    // 0x8008A3B4: sb          $t2, 0x7D0($t6)
    MEM_B(0X7D0, ctx->r14) = ctx->r10;
    // 0x8008A3B8: lw          $t7, 0x40($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X40);
    // 0x8008A3BC: multu       $t7, $t1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008A3C0: mflo        $t8
    ctx->r24 = lo;
    // 0x8008A3C4: addu        $t9, $t0, $t8
    ctx->r25 = ADD32(ctx->r8, ctx->r24);
    // 0x8008A3C8: sh          $a0, 0x7D2($t9)
    MEM_H(0X7D2, ctx->r25) = ctx->r4;
    // 0x8008A3CC: lw          $t6, 0x40($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X40);
    // 0x8008A3D0: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8008A3D4: multu       $t6, $t1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008A3D8: mflo        $t7
    ctx->r15 = lo;
    // 0x8008A3DC: addu        $t8, $t0, $t7
    ctx->r24 = ADD32(ctx->r8, ctx->r15);
    // 0x8008A3E0: swc1        $f4, 0x7D4($t8)
    MEM_W(0X7D4, ctx->r24) = ctx->f4.u32l;
    // 0x8008A3E4: lw          $t9, 0x40($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X40);
    // 0x8008A3E8: lwc1        $f6, 0x8($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8008A3EC: multu       $t9, $t1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008A3F0: mflo        $t6
    ctx->r14 = lo;
    // 0x8008A3F4: addu        $t7, $t0, $t6
    ctx->r15 = ADD32(ctx->r8, ctx->r14);
    // 0x8008A3F8: swc1        $f6, 0x7D8($t7)
    MEM_W(0X7D8, ctx->r15) = ctx->f6.u32l;
    // 0x8008A3FC: lw          $t8, 0x40($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X40);
    // 0x8008A400: lwc1        $f8, 0xC($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8008A404: multu       $t8, $t1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008A408: mflo        $t9
    ctx->r25 = lo;
    // 0x8008A40C: addu        $t6, $t0, $t9
    ctx->r14 = ADD32(ctx->r8, ctx->r25);
    // 0x8008A410: swc1        $f8, 0x7DC($t6)
    MEM_W(0X7DC, ctx->r14) = ctx->f8.u32l;
    // 0x8008A414: lw          $t7, 0x40($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X40);
    // 0x8008A418: multu       $t7, $t1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008A41C: mflo        $t8
    ctx->r24 = lo;
    // 0x8008A420: addu        $t9, $t0, $t8
    ctx->r25 = ADD32(ctx->r8, ctx->r24);
    // 0x8008A424: swc1        $f0, 0x7E0($t9)
    MEM_W(0X7E0, ctx->r25) = ctx->f0.u32l;
    // 0x8008A428: lbu         $t6, 0x6C($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X6C);
L_8008A42C:
    // 0x8008A42C: addiu       $v1, $v1, 0x6C
    ctx->r3 = ADD32(ctx->r3, 0X6C);
    // 0x8008A430: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x8008A434: bne         $at, $zero, L_8008A4C0
    if (ctx->r1 != 0) {
        // 0x8008A438: nop
    
            goto L_8008A4C0;
    }
    // 0x8008A438: nop

    // 0x8008A43C: lw          $t7, 0x40($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X40);
    // 0x8008A440: multu       $t7, $t1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008A444: mflo        $t8
    ctx->r24 = lo;
    // 0x8008A448: addu        $t9, $t0, $t8
    ctx->r25 = ADD32(ctx->r8, ctx->r24);
    // 0x8008A44C: sb          $t2, 0x7D0($t9)
    MEM_B(0X7D0, ctx->r25) = ctx->r10;
    // 0x8008A450: lw          $t6, 0x40($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X40);
    // 0x8008A454: multu       $t6, $t1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008A458: mflo        $t7
    ctx->r15 = lo;
    // 0x8008A45C: addu        $t8, $t0, $t7
    ctx->r24 = ADD32(ctx->r8, ctx->r15);
    // 0x8008A460: sh          $a0, 0x7D2($t8)
    MEM_H(0X7D2, ctx->r24) = ctx->r4;
    // 0x8008A464: lw          $t9, 0x40($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X40);
    // 0x8008A468: lwc1        $f10, 0x4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8008A46C: multu       $t9, $t1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008A470: mflo        $t6
    ctx->r14 = lo;
    // 0x8008A474: addu        $t7, $t0, $t6
    ctx->r15 = ADD32(ctx->r8, ctx->r14);
    // 0x8008A478: swc1        $f10, 0x7D4($t7)
    MEM_W(0X7D4, ctx->r15) = ctx->f10.u32l;
    // 0x8008A47C: lw          $t8, 0x40($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X40);
    // 0x8008A480: lwc1        $f16, 0x8($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8008A484: multu       $t8, $t1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008A488: mflo        $t9
    ctx->r25 = lo;
    // 0x8008A48C: addu        $t6, $t0, $t9
    ctx->r14 = ADD32(ctx->r8, ctx->r25);
    // 0x8008A490: swc1        $f16, 0x7D8($t6)
    MEM_W(0X7D8, ctx->r14) = ctx->f16.u32l;
    // 0x8008A494: lw          $t7, 0x40($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X40);
    // 0x8008A498: lwc1        $f18, 0xC($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8008A49C: multu       $t7, $t1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008A4A0: mflo        $t8
    ctx->r24 = lo;
    // 0x8008A4A4: addu        $t9, $t0, $t8
    ctx->r25 = ADD32(ctx->r8, ctx->r24);
    // 0x8008A4A8: swc1        $f18, 0x7DC($t9)
    MEM_W(0X7DC, ctx->r25) = ctx->f18.u32l;
    // 0x8008A4AC: lw          $t6, 0x40($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X40);
    // 0x8008A4B0: multu       $t6, $t1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008A4B4: mflo        $t7
    ctx->r15 = lo;
    // 0x8008A4B8: addu        $t8, $t0, $t7
    ctx->r24 = ADD32(ctx->r8, ctx->r15);
    // 0x8008A4BC: swc1        $f0, 0x7E0($t8)
    MEM_W(0X7E0, ctx->r24) = ctx->f0.u32l;
L_8008A4C0:
    // 0x8008A4C0: bne         $v0, $a1, L_8008A390
    if (ctx->r2 != ctx->r5) {
        // 0x8008A4C4: addiu       $v1, $v1, 0x6C
        ctx->r3 = ADD32(ctx->r3, 0X6C);
            goto L_8008A390;
    }
    // 0x8008A4C4: addiu       $v1, $v1, 0x6C
    ctx->r3 = ADD32(ctx->r3, 0X6C);
L_8008A4C8:
    // 0x8008A4C8: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    // 0x8008A4CC: lw          $s1, 0x8($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X8);
    // 0x8008A4D0: lw          $s2, 0xC($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XC);
    // 0x8008A4D4: jr          $ra
    // 0x8008A4D8: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8008A4D8: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void TextureRect_CI8_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084E78: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80084E7C: lui         $t0, 0xE700
    ctx->r8 = S32(0XE700 << 16);
    // 0x80084E80: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80084E84: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80084E88: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80084E8C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80084E90: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x80084E94: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80084E98: lui         $t8, 0xFD10
    ctx->r24 = S32(0XFD10 << 16);
    // 0x80084E9C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80084EA0: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80084EA4: sw          $a2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r6;
    // 0x80084EA8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80084EAC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80084EB0: lui         $t6, 0xE800
    ctx->r14 = S32(0XE800 << 16);
    // 0x80084EB4: lui         $t8, 0xF500
    ctx->r24 = S32(0XF500 << 16);
    // 0x80084EB8: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80084EBC: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80084EC0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80084EC4: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80084EC8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80084ECC: ori         $t8, $t8, 0x100
    ctx->r24 = ctx->r24 | 0X100;
    // 0x80084ED0: lui         $a2, 0x700
    ctx->r6 = S32(0X700 << 16);
    // 0x80084ED4: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80084ED8: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80084EDC: sw          $a2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r6;
    // 0x80084EE0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80084EE4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80084EE8: lui         $t6, 0xE600
    ctx->r14 = S32(0XE600 << 16);
    // 0x80084EEC: lui         $t8, 0xF000
    ctx->r24 = S32(0XF000 << 16);
    // 0x80084EF0: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80084EF4: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80084EF8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80084EFC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80084F00: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80084F04: lui         $t9, 0x73F
    ctx->r25 = S32(0X73F << 16);
    // 0x80084F08: ori         $t9, $t9, 0xC000
    ctx->r25 = ctx->r25 | 0XC000;
    // 0x80084F0C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80084F10: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80084F14: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80084F18: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80084F1C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80084F20: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80084F24: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80084F28: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80084F2C: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x80084F30: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80084F34: lui         $t8, 0xFD50
    ctx->r24 = S32(0XFD50 << 16);
    // 0x80084F38: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80084F3C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80084F40: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80084F44: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x80084F48: sw          $a1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r5;
    // 0x80084F4C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80084F50: lui         $t6, 0xF550
    ctx->r14 = S32(0XF550 << 16);
    // 0x80084F54: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80084F58: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80084F5C: sw          $a2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r6;
    // 0x80084F60: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80084F64: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80084F68: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x80084F6C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80084F70: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80084F74: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80084F78: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80084F7C: multu       $a3, $t1
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80084F80: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80084F84: lui         $t6, 0xF300
    ctx->r14 = S32(0XF300 << 16);
    // 0x80084F88: srl         $v0, $a3, 3
    ctx->r2 = S32(U32(ctx->r7) >> 3);
    // 0x80084F8C: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80084F90: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80084F94: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80084F98: mflo        $t5
    ctx->r13 = lo;
    // 0x80084F9C: addiu       $t5, $t5, 0x1
    ctx->r13 = ADD32(ctx->r13, 0X1);
    // 0x80084FA0: srl         $t7, $t5, 1
    ctx->r15 = S32(U32(ctx->r13) >> 1);
    // 0x80084FA4: addiu       $t5, $t7, -0x1
    ctx->r13 = ADD32(ctx->r15, -0X1);
    // 0x80084FA8: sltiu       $at, $t5, 0x7FF
    ctx->r1 = ctx->r13 < 0X7FF ? 1 : 0;
    // 0x80084FAC: beql        $at, $zero, L_80084FC0
    if (ctx->r1 == 0) {
        // 0x80084FB0: addiu       $a1, $zero, 0x7FF
        ctx->r5 = ADD32(0, 0X7FF);
            goto L_80084FC0;
    }
    goto skip_0;
    // 0x80084FB0: addiu       $a1, $zero, 0x7FF
    ctx->r5 = ADD32(0, 0X7FF);
    skip_0:
    // 0x80084FB4: b           L_80084FC0
    // 0x80084FB8: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
        goto L_80084FC0;
    // 0x80084FB8: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
    // 0x80084FBC: addiu       $a1, $zero, 0x7FF
    ctx->r5 = ADD32(0, 0X7FF);
L_80084FC0:
    // 0x80084FC0: bne         $v0, $zero, L_80084FD0
    if (ctx->r2 != 0) {
        // 0x80084FC4: or          $t2, $a3, $zero
        ctx->r10 = ctx->r7 | 0;
            goto L_80084FD0;
    }
    // 0x80084FC4: or          $t2, $a3, $zero
    ctx->r10 = ctx->r7 | 0;
    // 0x80084FC8: b           L_80084FD4
    // 0x80084FCC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
        goto L_80084FD4;
    // 0x80084FCC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_80084FD0:
    // 0x80084FD0: or          $t3, $v0, $zero
    ctx->r11 = ctx->r2 | 0;
L_80084FD4:
    // 0x80084FD4: bne         $v0, $zero, L_80084FE4
    if (ctx->r2 != 0) {
        // 0x80084FD8: addiu       $t8, $t3, 0x7FF
        ctx->r24 = ADD32(ctx->r11, 0X7FF);
            goto L_80084FE4;
    }
    // 0x80084FD8: addiu       $t8, $t3, 0x7FF
    ctx->r24 = ADD32(ctx->r11, 0X7FF);
    // 0x80084FDC: b           L_80084FE8
    // 0x80084FE0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
        goto L_80084FE8;
    // 0x80084FE0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
L_80084FE4:
    // 0x80084FE4: or          $t4, $v0, $zero
    ctx->r12 = ctx->r2 | 0;
L_80084FE8:
    // 0x80084FE8: divu        $zero, $t8, $t4
    lo = S32(U32(ctx->r24) / U32(ctx->r12)); hi = S32(U32(ctx->r24) % U32(ctx->r12));
    // 0x80084FEC: mflo        $t9
    ctx->r25 = lo;
    // 0x80084FF0: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x80084FF4: andi        $t8, $a1, 0xFFF
    ctx->r24 = ctx->r5 & 0XFFF;
    // 0x80084FF8: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x80084FFC: or          $t7, $t6, $a2
    ctx->r15 = ctx->r14 | ctx->r6;
    // 0x80085000: or          $t6, $t7, $t9
    ctx->r14 = ctx->r15 | ctx->r25;
    // 0x80085004: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x80085008: bne         $t4, $zero, L_80085014
    if (ctx->r12 != 0) {
        // 0x8008500C: nop
    
            goto L_80085014;
    }
    // 0x8008500C: nop

    // 0x80085010: break       7
    do_break(2148028432);
L_80085014:
    // 0x80085014: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80085018: addiu       $t9, $t2, 0x7
    ctx->r25 = ADD32(ctx->r10, 0X7);
    // 0x8008501C: srl         $t6, $t9, 3
    ctx->r14 = S32(U32(ctx->r25) >> 3);
    // 0x80085020: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80085024: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80085028: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8008502C: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x80085030: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80085034: andi        $t8, $t6, 0x1FF
    ctx->r24 = ctx->r14 & 0X1FF;
    // 0x80085038: lui         $at, 0xF548
    ctx->r1 = S32(0XF548 << 16);
    // 0x8008503C: sw          $v0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r2;
    // 0x80085040: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80085044: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80085048: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x8008504C: sll         $t7, $t8, 9
    ctx->r15 = S32(ctx->r24 << 9);
    // 0x80085050: or          $t9, $t7, $at
    ctx->r25 = ctx->r15 | ctx->r1;
    // 0x80085054: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80085058: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x8008505C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80085060: lui         $t7, 0xF200
    ctx->r15 = S32(0XF200 << 16);
    // 0x80085064: addiu       $t6, $a3, -0x1
    ctx->r14 = ADD32(ctx->r7, -0X1);
    // 0x80085068: sw          $v0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r2;
    // 0x8008506C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80085070: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80085074: lw          $t9, 0x0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X0);
    // 0x80085078: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x8008507C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80085080: sw          $t7, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r15;
    // 0x80085084: andi        $t7, $t8, 0xFFF
    ctx->r15 = ctx->r24 & 0XFFF;
    // 0x80085088: sll         $t6, $t7, 12
    ctx->r14 = S32(ctx->r15 << 12);
    // 0x8008508C: addiu       $t8, $t1, -0x1
    ctx->r24 = ADD32(ctx->r9, -0X1);
    // 0x80085090: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x80085094: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x80085098: or          $t7, $t6, $t8
    ctx->r15 = ctx->r14 | ctx->r24;
    // 0x8008509C: sw          $t7, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r15;
    // 0x800850A0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800850A4: lwc1        $f14, 0x58($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800850A8: lwc1        $f12, 0x50($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800850AC: lwc1        $f2, 0x4C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800850B0: lwc1        $f0, 0x54($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800850B4: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800850B8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800850BC: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800850C0: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800850C4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800850C8: lwc1        $f4, 0x5C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800850CC: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800850D0: add.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x800850D4: mul.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800850D8: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800850DC: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800850E0: nop

    // 0x800850E4: cvt.w.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800850E8: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800850EC: nop

    // 0x800850F0: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x800850F4: beql        $t7, $zero, L_80085144
    if (ctx->r15 == 0) {
        // 0x800850F8: mfc1        $t7, $f18
        ctx->r15 = (int32_t)ctx->f18.u32l;
            goto L_80085144;
    }
    goto skip_1;
    // 0x800850F8: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    skip_1:
    // 0x800850FC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80085100: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80085104: sub.s       $f18, $f10, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x80085108: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8008510C: nop

    // 0x80085110: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80085114: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80085118: nop

    // 0x8008511C: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x80085120: bne         $t7, $zero, L_80085138
    if (ctx->r15 != 0) {
        // 0x80085124: nop
    
            goto L_80085138;
    }
    // 0x80085124: nop

    // 0x80085128: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x8008512C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80085130: b           L_80085150
    // 0x80085134: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_80085150;
    // 0x80085134: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_80085138:
    // 0x80085138: b           L_80085150
    // 0x8008513C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_80085150;
    // 0x8008513C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80085140: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
L_80085144:
    // 0x80085144: nop

    // 0x80085148: bltz        $t7, L_80085138
    if (SIGNED(ctx->r15) < 0) {
        // 0x8008514C: nop
    
            goto L_80085138;
    }
    // 0x8008514C: nop

L_80085150:
    // 0x80085150: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80085154: lwc1        $f4, 0x60($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80085158: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x8008515C: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x80085160: mul.s       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x80085164: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80085168: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x8008516C: or          $t8, $t6, $at
    ctx->r24 = ctx->r14 | ctx->r1;
    // 0x80085170: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80085174: add.s       $f8, $f12, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f12.fl + ctx->f6.fl;
    // 0x80085178: mul.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8008517C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80085180: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80085184: nop

    // 0x80085188: cvt.w.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8008518C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80085190: nop

    // 0x80085194: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x80085198: beql        $t9, $zero, L_800851E8
    if (ctx->r25 == 0) {
        // 0x8008519C: mfc1        $t9, $f18
        ctx->r25 = (int32_t)ctx->f18.u32l;
            goto L_800851E8;
    }
    goto skip_2;
    // 0x8008519C: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    skip_2:
    // 0x800851A0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800851A4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800851A8: sub.s       $f18, $f10, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x800851AC: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800851B0: nop

    // 0x800851B4: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800851B8: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800851BC: nop

    // 0x800851C0: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x800851C4: bne         $t9, $zero, L_800851DC
    if (ctx->r25 != 0) {
        // 0x800851C8: nop
    
            goto L_800851DC;
    }
    // 0x800851C8: nop

    // 0x800851CC: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x800851D0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800851D4: b           L_800851F4
    // 0x800851D8: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_800851F4;
    // 0x800851D8: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_800851DC:
    // 0x800851DC: b           L_800851F4
    // 0x800851E0: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_800851F4;
    // 0x800851E0: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x800851E4: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
L_800851E8:
    // 0x800851E8: nop

    // 0x800851EC: bltz        $t9, L_800851DC
    if (SIGNED(ctx->r25) < 0) {
        // 0x800851F0: nop
    
            goto L_800851DC;
    }
    // 0x800851F0: nop

L_800851F4:
    // 0x800851F4: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800851F8: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x800851FC: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x80085200: mul.s       $f4, $f2, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x80085204: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80085208: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8008520C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80085210: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80085214: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80085218: nop

    // 0x8008521C: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80085220: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80085224: nop

    // 0x80085228: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x8008522C: beql        $t8, $zero, L_8008527C
    if (ctx->r24 == 0) {
        // 0x80085230: mfc1        $t8, $f6
        ctx->r24 = (int32_t)ctx->f6.u32l;
            goto L_8008527C;
    }
    goto skip_3;
    // 0x80085230: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    skip_3:
    // 0x80085234: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80085238: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8008523C: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80085240: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80085244: nop

    // 0x80085248: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8008524C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80085250: nop

    // 0x80085254: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x80085258: bne         $t8, $zero, L_80085270
    if (ctx->r24 != 0) {
        // 0x8008525C: nop
    
            goto L_80085270;
    }
    // 0x8008525C: nop

    // 0x80085260: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x80085264: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80085268: b           L_80085288
    // 0x8008526C: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_80085288;
    // 0x8008526C: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_80085270:
    // 0x80085270: b           L_80085288
    // 0x80085274: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_80085288;
    // 0x80085274: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80085278: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
L_8008527C:
    // 0x8008527C: nop

    // 0x80085280: bltz        $t8, L_80085270
    if (SIGNED(ctx->r24) < 0) {
        // 0x80085284: nop
    
            goto L_80085270;
    }
    // 0x80085284: nop

L_80085288:
    // 0x80085288: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8008528C: andi        $t6, $t8, 0xFFF
    ctx->r14 = ctx->r24 & 0XFFF;
    // 0x80085290: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80085294: mul.s       $f8, $f12, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f16.fl);
    // 0x80085298: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x8008529C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800852A0: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800852A4: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800852A8: nop

    // 0x800852AC: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800852B0: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800852B4: nop

    // 0x800852B8: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x800852BC: beql        $t8, $zero, L_8008530C
    if (ctx->r24 == 0) {
        // 0x800852C0: mfc1        $t8, $f10
        ctx->r24 = (int32_t)ctx->f10.u32l;
            goto L_8008530C;
    }
    goto skip_4;
    // 0x800852C0: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    skip_4:
    // 0x800852C4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800852C8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800852CC: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800852D0: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800852D4: nop

    // 0x800852D8: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800852DC: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800852E0: nop

    // 0x800852E4: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x800852E8: bne         $t8, $zero, L_80085300
    if (ctx->r24 != 0) {
        // 0x800852EC: nop
    
            goto L_80085300;
    }
    // 0x800852EC: nop

    // 0x800852F0: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x800852F4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800852F8: b           L_80085318
    // 0x800852FC: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_80085318;
    // 0x800852FC: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_80085300:
    // 0x80085300: b           L_80085318
    // 0x80085304: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_80085318;
    // 0x80085304: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80085308: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
L_8008530C:
    // 0x8008530C: nop

    // 0x80085310: bltz        $t8, L_80085300
    if (SIGNED(ctx->r24) < 0) {
        // 0x80085314: nop
    
            goto L_80085300;
    }
    // 0x80085314: nop

L_80085318:
    // 0x80085318: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8008531C: andi        $t6, $t8, 0xFFF
    ctx->r14 = ctx->r24 & 0XFFF;
    // 0x80085320: or          $t9, $t7, $t6
    ctx->r25 = ctx->r15 | ctx->r14;
    // 0x80085324: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80085328: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8008532C: lui         $t7, 0xB400
    ctx->r15 = S32(0XB400 << 16);
    // 0x80085330: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80085334: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80085338: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8008533C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80085340: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80085344: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80085348: lui         $at, 0x4480
    ctx->r1 = S32(0X4480 << 16);
    // 0x8008534C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80085350: div.s       $f18, $f2, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = DIV_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80085354: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80085358: lui         $t9, 0xB300
    ctx->r25 = S32(0XB300 << 16);
    // 0x8008535C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80085360: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80085364: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80085368: div.s       $f8, $f2, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = DIV_S(ctx->f2.fl, ctx->f14.fl);
    // 0x8008536C: mul.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x80085370: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80085374: mul.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x80085378: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x8008537C: nop

    // 0x80085380: sll         $t9, $t6, 16
    ctx->r25 = S32(ctx->r14 << 16);
    // 0x80085384: trunc.w.s   $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80085388: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x8008538C: nop

    // 0x80085390: andi        $t6, $t7, 0xFFFF
    ctx->r14 = ctx->r15 & 0XFFFF;
    // 0x80085394: or          $t8, $t9, $t6
    ctx->r24 = ctx->r25 | ctx->r14;
    // 0x80085398: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8008539C: jr          $ra
    // 0x800853A0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800853A0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void Versus_dummy_800C175C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C175C: jr          $ra
    // 0x800C1760: nop

    return;
    // 0x800C1760: nop

;}
RECOMP_FUNC void HUD_VS_BombIcon_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008D1F0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8008D1F4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8008D1F8: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8008D1FC: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x8008D200: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8008D204: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8008D208: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8008D20C: lui         $a1, 0x101
    ctx->r5 = S32(0X101 << 16);
    // 0x8008D210: lui         $a2, 0x101
    ctx->r6 = S32(0X101 << 16);
    // 0x8008D214: addiu       $t6, $zero, 0x10
    ctx->r14 = ADD32(0, 0X10);
    // 0x8008D218: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8008D21C: addiu       $a2, $a2, 0x1730
    ctx->r6 = ADD32(ctx->r6, 0X1730);
    // 0x8008D220: addiu       $a1, $a1, 0x16B0
    ctx->r5 = ADD32(ctx->r5, 0X16B0);
    // 0x8008D224: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8008D228: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x8008D22C: swc1        $f12, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f12.u32l;
    // 0x8008D230: swc1        $f14, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f14.u32l;
    // 0x8008D234: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x8008D238: jal         0x8009C320
    // 0x8008D23C: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    Lib_TextureRect_CI4(rdram, ctx);
        goto after_0;
    // 0x8008D23C: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x8008D240: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8008D244: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8008D248: jr          $ra
    // 0x8008D24C: nop

    return;
    // 0x8008D24C: nop

;}
RECOMP_FUNC void Effect_FireSmoke3_Setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007D138: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8007D13C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8007D140: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8007D144: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8007D148: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8007D14C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8007D150: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8007D154: jal         0x80061474
    // 0x8007D158: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Effect_Initialize(rdram, ctx);
        goto after_0;
    // 0x8007D158: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8007D15C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8007D160: addiu       $t7, $zero, 0x155
    ctx->r15 = ADD32(0, 0X155);
    // 0x8007D164: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
    // 0x8007D168: sh          $t7, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r15;
    // 0x8007D16C: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8007D170: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x8007D174: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8007D178: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x8007D17C: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8007D180: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    // 0x8007D184: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8007D188: jal         0x80004EB0
    // 0x8007D18C: swc1        $f10, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f10.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x8007D18C: swc1        $f10, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f10.u32l;
    after_1:
    // 0x8007D190: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8007D194: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8007D198: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x8007D19C: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    // 0x8007D1A0: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x8007D1A4: jal         0x800612B8
    // 0x8007D1A8: swc1        $f18, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f18.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_2;
    // 0x8007D1A8: swc1        $f18, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f18.u32l;
    after_2:
    // 0x8007D1AC: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x8007D1B0: lbu         $t8, 0x7C98($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X7C98);
    // 0x8007D1B4: addiu       $t9, $zero, 0xF
    ctx->r25 = ADD32(0, 0XF);
    // 0x8007D1B8: addiu       $t0, $zero, 0xB4
    ctx->r8 = ADD32(0, 0XB4);
    // 0x8007D1BC: bnel        $t8, $zero, L_8007D1CC
    if (ctx->r24 != 0) {
        // 0x8007D1C0: sh          $t0, 0x44($s0)
        MEM_H(0X44, ctx->r16) = ctx->r8;
            goto L_8007D1CC;
    }
    goto skip_0;
    // 0x8007D1C0: sh          $t0, 0x44($s0)
    MEM_H(0X44, ctx->r16) = ctx->r8;
    skip_0:
    // 0x8007D1C4: sb          $t9, 0x4C($s0)
    MEM_B(0X4C, ctx->r16) = ctx->r25;
    // 0x8007D1C8: sh          $t0, 0x44($s0)
    MEM_H(0X44, ctx->r16) = ctx->r8;
L_8007D1CC:
    // 0x8007D1CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007D1D0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8007D1D4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8007D1D8: jr          $ra
    // 0x8007D1DC: nop

    return;
    // 0x8007D1DC: nop

;}
RECOMP_FUNC void func_bg_8003E1E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003E1E0: jr          $ra
    // 0x8003E1E4: nop

    return;
    // 0x8003E1E4: nop

;}
RECOMP_FUNC void Item_Move(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069A10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80069A14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80069A18: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x80069A1C: lw          $t6, 0x1AB8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1AB8);
    // 0x80069A20: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80069A24: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80069A28: beql        $t6, $zero, L_80069AA0
    if (ctx->r14 == 0) {
        // 0x80069A2C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80069AA0;
    }
    goto skip_0;
    // 0x80069A2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80069A30: lw          $t7, -0x7D80($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7D80);
    // 0x80069A34: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80069A38: lwc1        $f8, 0x2C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x80069A3C: lwc1        $f6, 0x48($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X48);
    // 0x80069A40: lwc1        $f16, 0xC($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80069A44: lwc1        $f18, 0x7D20($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x80069A48: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80069A4C: addiu       $a1, $a0, 0x5C
    ctx->r5 = ADD32(ctx->r4, 0X5C);
    // 0x80069A50: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80069A54: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x80069A58: c.lt.s      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.fl < ctx->f4.fl;
    // 0x80069A5C: nop

    // 0x80069A60: bc1fl       L_80069AA0
    if (!c1cs) {
        // 0x80069A64: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80069AA0;
    }
    goto skip_1;
    // 0x80069A64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80069A68: jal         0x80060FBC
    // 0x80069A6C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    Object_Kill(rdram, ctx);
        goto after_0;
    // 0x80069A6C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80069A70: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80069A74: addiu       $at, $zero, 0x146
    ctx->r1 = ADD32(0, 0X146);
    // 0x80069A78: lhu         $t8, 0x2($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0X2);
    // 0x80069A7C: bnel        $t8, $at, L_80069AA0
    if (ctx->r24 != ctx->r1) {
        // 0x80069A80: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80069AA0;
    }
    goto skip_2;
    // 0x80069A80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80069A84: lbu         $t9, 0x46($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X46);
    // 0x80069A88: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80069A8C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80069A90: bnel        $t9, $zero, L_80069AA0
    if (ctx->r25 != 0) {
        // 0x80069A94: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80069AA0;
    }
    goto skip_3;
    // 0x80069A94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x80069A98: sw          $t0, 0x7E80($at)
    MEM_W(0X7E80, ctx->r1) = ctx->r8;
    // 0x80069A9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80069AA0:
    // 0x80069AA0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80069AA4: jr          $ra
    // 0x80069AA8: nop

    return;
    // 0x80069AA8: nop

;}
RECOMP_FUNC void Audio_PlayAllSfx(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001AAE4: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x8001AAE8: lw          $t7, -0x17FC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X17FC);
    // 0x8001AAEC: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x8001AAF0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001AAF4: addiu       $t6, $t6, 0x2FE8
    ctx->r14 = ADD32(ctx->r14, 0X2FE8);
    // 0x8001AAF8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001AAFC: beq         $t6, $t7, L_8001AB3C
    if (ctx->r14 == ctx->r15) {
        // 0x8001AB00: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_8001AB3C;
    }
    // 0x8001AB00: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001AB04: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8001AB08: sb          $zero, -0x6588($at)
    MEM_B(-0X6588, ctx->r1) = 0;
    // 0x8001AB0C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8001AB10:
    // 0x8001AB10: jal         0x800198C0
    // 0x8001AB14: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    Audio_ChooseActiveSfx(rdram, ctx);
        goto after_0;
    // 0x8001AB14: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    after_0:
    // 0x8001AB18: jal         0x8001A01C
    // 0x8001AB1C: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    Audio_PlayActiveSfx(rdram, ctx);
        goto after_1;
    // 0x8001AB1C: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    after_1:
    // 0x8001AB20: jal         0x8001AA90
    // 0x8001AB24: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    Audio_UpdateSfxVolumeMod(rdram, ctx);
        goto after_2;
    // 0x8001AB24: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    after_2:
    // 0x8001AB28: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001AB2C: andi        $t8, $s0, 0xFF
    ctx->r24 = ctx->r16 & 0XFF;
    // 0x8001AB30: slti        $at, $t8, 0x5
    ctx->r1 = SIGNED(ctx->r24) < 0X5 ? 1 : 0;
    // 0x8001AB34: bne         $at, $zero, L_8001AB10
    if (ctx->r1 != 0) {
        // 0x8001AB38: or          $s0, $t8, $zero
        ctx->r16 = ctx->r24 | 0;
            goto L_8001AB10;
    }
    // 0x8001AB38: or          $s0, $t8, $zero
    ctx->r16 = ctx->r24 | 0;
L_8001AB3C:
    // 0x8001AB3C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001AB40: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001AB44: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001AB48: jr          $ra
    // 0x8001AB4C: nop

    return;
    // 0x8001AB4C: nop

;}
RECOMP_FUNC void ActorEvent_ProcessActions(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F40C: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x8006F410: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x8006F414: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8006F418: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8006F41C: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8006F420: lw          $v0, -0x7D80($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D80);
    // 0x8006F424: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8006F428: lw          $t6, 0x1C8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X1C8);
    // 0x8006F42C: bnel        $t6, $at, L_8006FE18
    if (ctx->r14 != ctx->r1) {
        // 0x8006F430: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_8006FE18;
    }
    goto skip_0;
    // 0x8006F430: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_0:
    // 0x8006F434: lh          $v1, 0xB4($s0)
    ctx->r3 = MEM_H(ctx->r16, 0XB4);
    // 0x8006F438: addiu       $at, $zero, 0x34
    ctx->r1 = ADD32(0, 0X34);
    // 0x8006F43C: beq         $v1, $at, L_8006FE14
    if (ctx->r3 == ctx->r1) {
        // 0x8006F440: addiu       $at, $zero, 0x67
        ctx->r1 = ADD32(0, 0X67);
            goto L_8006FE14;
    }
    // 0x8006F440: addiu       $at, $zero, 0x67
    ctx->r1 = ADD32(0, 0X67);
    // 0x8006F444: beq         $v1, $at, L_8006FE14
    if (ctx->r3 == ctx->r1) {
        // 0x8006F448: addiu       $at, $zero, 0x68
        ctx->r1 = ADD32(0, 0X68);
            goto L_8006FE14;
    }
    // 0x8006F448: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x8006F44C: beq         $v1, $at, L_8006FE14
    if (ctx->r3 == ctx->r1) {
        // 0x8006F450: addiu       $at, $zero, 0x30
        ctx->r1 = ADD32(0, 0X30);
            goto L_8006FE14;
    }
    // 0x8006F450: addiu       $at, $zero, 0x30
    ctx->r1 = ADD32(0, 0X30);
    // 0x8006F454: beq         $v1, $at, L_8006FE14
    if (ctx->r3 == ctx->r1) {
        // 0x8006F458: addiu       $at, $zero, 0x31
        ctx->r1 = ADD32(0, 0X31);
            goto L_8006FE14;
    }
    // 0x8006F458: addiu       $at, $zero, 0x31
    ctx->r1 = ADD32(0, 0X31);
    // 0x8006F45C: beq         $v1, $at, L_8006FE14
    if (ctx->r3 == ctx->r1) {
        // 0x8006F460: addiu       $at, $zero, 0x32
        ctx->r1 = ADD32(0, 0X32);
            goto L_8006FE14;
    }
    // 0x8006F460: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x8006F464: beql        $v1, $at, L_8006FE18
    if (ctx->r3 == ctx->r1) {
        // 0x8006F468: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_8006FE18;
    }
    goto skip_1;
    // 0x8006F468: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_1:
    // 0x8006F46C: lhu         $t7, 0x48($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X48);
    // 0x8006F470: sltiu       $at, $t7, 0x14
    ctx->r1 = ctx->r15 < 0X14 ? 1 : 0;
    // 0x8006F474: beq         $at, $zero, L_8006FE14
    if (ctx->r1 == 0) {
        // 0x8006F478: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_8006FE14;
    }
    // 0x8006F478: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8006F47C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006F480: addu        $at, $at, $t7
    gpr jr_addend_8006F488 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8006F484: lw          $t7, 0x6BA8($at)
    ctx->r15 = ADD32(ctx->r1, 0X6BA8);
    // 0x8006F488: jr          $t7
    // 0x8006F48C: nop

    switch (jr_addend_8006F488 >> 2) {
        case 0: goto L_8006FE14; break;
        case 1: goto L_8006F490; break;
        case 2: goto L_8006F4A0; break;
        case 3: goto L_8006F508; break;
        case 4: goto L_8006F60C; break;
        case 5: goto L_8006F630; break;
        case 6: goto L_8006F7D8; break;
        case 7: goto L_8006F840; break;
        case 8: goto L_8006F88C; break;
        case 9: goto L_8006F960; break;
        case 10: goto L_8006F9B8; break;
        case 11: goto L_8006FA10; break;
        case 12: goto L_8006FA7C; break;
        case 13: goto L_8006FA98; break;
        case 14: goto L_8006FE14; break;
        case 15: goto L_8006FE14; break;
        case 16: goto L_8006FB38; break;
        case 17: goto L_8006FC18; break;
        case 18: goto L_8006FC80; break;
        case 19: goto L_8006FDFC; break;
        default: switch_error(__func__, 0x8006F488, 0x800D6BA8);
    }
    // 0x8006F48C: nop

L_8006F490:
    // 0x8006F490: jal         0x8006F254
    // 0x8006F494: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ActorEvent_ShootForward(rdram, ctx);
        goto after_0;
    // 0x8006F494: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8006F498: b           L_8006FE14
    // 0x8006F49C: sh          $zero, 0x48($s0)
    MEM_H(0X48, ctx->r16) = 0;
        goto L_8006FE14;
    // 0x8006F49C: sh          $zero, 0x48($s0)
    MEM_H(0X48, ctx->r16) = 0;
L_8006F4A0:
    // 0x8006F4A0: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x8006F4A4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8006F4A8: lwc1        $f4, 0x138($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X138);
    // 0x8006F4AC: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8006F4B0: addiu       $a0, $zero, 0x161
    ctx->r4 = ADD32(0, 0X161);
    // 0x8006F4B4: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8006F4B8: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x8006F4BC: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x8006F4C0: nop

    // 0x8006F4C4: bc1f        L_8006F500
    if (!c1cs) {
        // 0x8006F4C8: nop
    
            goto L_8006F500;
    }
    // 0x8006F4C8: nop

    // 0x8006F4CC: lhu         $t8, 0x7828($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X7828);
    // 0x8006F4D0: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8006F4D4: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x8006F4D8: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x8006F4DC: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    // 0x8006F4E0: bgez        $t8, L_8006F4F8
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8006F4E4: cvt.s.w     $f18, $f10
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
            goto L_8006F4F8;
    }
    // 0x8006F4E4: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8006F4E8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8006F4EC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8006F4F0: nop

    // 0x8006F4F4: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_8006F4F8:
    // 0x8006F4F8: jal         0x8007F11C
    // 0x8006F4FC: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Effect_ShootAtPlayer(rdram, ctx);
        goto after_1;
    // 0x8006F4FC: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_1:
L_8006F500:
    // 0x8006F500: b           L_8006FE14
    // 0x8006F504: sh          $zero, 0x48($s0)
    MEM_H(0X48, ctx->r16) = 0;
        goto L_8006FE14;
    // 0x8006F504: sh          $zero, 0x48($s0)
    MEM_H(0X48, ctx->r16) = 0;
L_8006F508:
    // 0x8006F508: lhu         $t9, 0xBE($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0XBE);
    // 0x8006F50C: addiu       $t0, $zero, 0x6
    ctx->r8 = ADD32(0, 0X6);
    // 0x8006F510: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8006F514: bne         $t9, $zero, L_8006FE14
    if (ctx->r25 != 0) {
        // 0x8006F518: lui         $a0, 0x8014
        ctx->r4 = S32(0X8014 << 16);
            goto L_8006FE14;
    }
    // 0x8006F518: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8006F51C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8006F520: sh          $t0, 0xBE($s0)
    MEM_H(0XBE, ctx->r16) = ctx->r8;
    // 0x8006F524: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8006F528: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8006F52C: addiu       $a1, $sp, 0x78
    ctx->r5 = ADD32(ctx->r29, 0X78);
    // 0x8006F530: addiu       $a2, $sp, 0x6C
    ctx->r6 = ADD32(ctx->r29, 0X6C);
    // 0x8006F534: swc1        $f0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f0.u32l;
    // 0x8006F538: swc1        $f0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f0.u32l;
    // 0x8006F53C: jal         0x80006A20
    // 0x8006F540: swc1        $f6, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f6.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_2;
    // 0x8006F540: swc1        $f6, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x8006F544: lwc1        $f4, 0x6C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8006F548: lui         $at, 0x3FF8
    ctx->r1 = S32(0X3FF8 << 16);
    // 0x8006F54C: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x8006F550: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8006F554: cvt.d.s     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f18.d = CVT_D_S(ctx->f4.fl);
    // 0x8006F558: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8006F55C: mul.d       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f0.d);
    // 0x8006F560: lw          $a0, 0x40($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X40);
    // 0x8006F564: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8006F568: add.d       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f10.d + ctx->f6.d;
    // 0x8006F56C: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8006F570: cvt.s.d     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f18.fl = CVT_S_D(ctx->f8.d);
    // 0x8006F574: lwc1        $f8, 0x70($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8006F578: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x8006F57C: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8006F580: cvt.d.s     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f18.d = CVT_D_S(ctx->f8.fl);
    // 0x8006F584: mul.d       $f10, $f18, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = MUL_D(ctx->f18.d, ctx->f0.d);
    // 0x8006F588: add.d       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = ctx->f6.d + ctx->f10.d;
    // 0x8006F58C: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8006F590: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8006F594: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x8006F598: cvt.s.d     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f6.fl = CVT_S_D(ctx->f18.d);
    // 0x8006F59C: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x8006F5A0: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x8006F5A4: lwc1        $f6, 0x74($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8006F5A8: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x8006F5AC: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x8006F5B0: mul.d       $f10, $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = MUL_D(ctx->f10.d, ctx->f0.d);
    // 0x8006F5B4: add.d       $f18, $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = ctx->f18.d + ctx->f10.d;
    // 0x8006F5B8: cvt.s.d     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f10.fl = CVT_S_D(ctx->f18.d);
    // 0x8006F5BC: lwc1        $f18, 0xF4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XF4);
    // 0x8006F5C0: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x8006F5C4: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    // 0x8006F5C8: lwc1        $f10, 0xF8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XF8);
    // 0x8006F5CC: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    // 0x8006F5D0: lwc1        $f8, 0xFC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XFC);
    // 0x8006F5D4: lwc1        $f4, 0x2F0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2F0);
    // 0x8006F5D8: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8006F5DC: jal         0x8006EEFC
    // 0x8006F5E0: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    Actor_SpawnPlayerLaser(rdram, ctx);
        goto after_3;
    // 0x8006F5E0: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    after_3:
    // 0x8006F5E4: lh          $t2, 0x4C($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X4C);
    // 0x8006F5E8: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8006F5EC: sh          $t1, 0xC2($s0)
    MEM_H(0XC2, ctx->r16) = ctx->r9;
    // 0x8006F5F0: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x8006F5F4: sh          $t3, 0x4C($s0)
    MEM_H(0X4C, ctx->r16) = ctx->r11;
    // 0x8006F5F8: lh          $t4, 0x4C($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X4C);
    // 0x8006F5FC: bgtzl       $t4, L_8006FE18
    if (SIGNED(ctx->r12) > 0) {
        // 0x8006F600: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_8006FE18;
    }
    goto skip_2;
    // 0x8006F600: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_2:
    // 0x8006F604: b           L_8006FE14
    // 0x8006F608: sh          $zero, 0x48($s0)
    MEM_H(0X48, ctx->r16) = 0;
        goto L_8006FE14;
    // 0x8006F608: sh          $zero, 0x48($s0)
    MEM_H(0X48, ctx->r16) = 0;
L_8006F60C:
    // 0x8006F60C: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8006F610: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8006F614: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8006F618: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8006F61C: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x8006F620: jal         0x8006EB64
    // 0x8006F624: sub.s       $f14, $f18, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f10.fl;
    ActorEvent_FlamePillar_Spawn(rdram, ctx);
        goto after_4;
    // 0x8006F624: sub.s       $f14, $f18, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f10.fl;
    after_4:
    // 0x8006F628: b           L_8006FE14
    // 0x8006F62C: sh          $zero, 0x48($s0)
    MEM_H(0X48, ctx->r16) = 0;
        goto L_8006FE14;
    // 0x8006F62C: sh          $zero, 0x48($s0)
    MEM_H(0X48, ctx->r16) = 0;
L_8006F630:
    // 0x8006F630: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006F634: lwc1        $f8, 0x6BF8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6BF8);
    // 0x8006F638: lwc1        $f4, 0x2EC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2EC);
    // 0x8006F63C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8006F640: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8006F644: mul.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8006F648: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8006F64C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8006F650: jal         0x80005E90
    // 0x8006F654: nop

    Matrix_RotateY(rdram, ctx);
        goto after_5;
    // 0x8006F654: nop

    after_5:
    // 0x8006F658: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006F65C: lwc1        $f10, 0x6BFC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6BFC);
    // 0x8006F660: lwc1        $f18, 0x2E8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X2E8);
    // 0x8006F664: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8006F668: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8006F66C: mul.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x8006F670: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8006F674: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8006F678: jal         0x80005D44
    // 0x8006F67C: nop

    Matrix_RotateX(rdram, ctx);
        goto after_6;
    // 0x8006F67C: nop

    after_6:
    // 0x8006F680: lwc1        $f8, 0x2F0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2F0);
    // 0x8006F684: lwc1        $f6, 0xFC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XFC);
    // 0x8006F688: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006F68C: lwc1        $f10, 0x6C00($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6C00);
    // 0x8006F690: add.s       $f18, $f8, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8006F694: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8006F698: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8006F69C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8006F6A0: mul.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x8006F6A4: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8006F6A8: jal         0x80005FE0
    // 0x8006F6AC: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_7;
    // 0x8006F6AC: nop

    after_7:
    // 0x8006F6B0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006F6B4: lwc1        $f6, 0x6C04($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6C04);
    // 0x8006F6B8: lwc1        $f8, 0xF8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XF8);
    // 0x8006F6BC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8006F6C0: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8006F6C4: mul.s       $f18, $f8, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8006F6C8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8006F6CC: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8006F6D0: jal         0x80005E90
    // 0x8006F6D4: nop

    Matrix_RotateY(rdram, ctx);
        goto after_8;
    // 0x8006F6D4: nop

    after_8:
    // 0x8006F6D8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006F6DC: lwc1        $f4, 0x6C08($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6C08);
    // 0x8006F6E0: lwc1        $f10, 0xF4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XF4);
    // 0x8006F6E4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8006F6E8: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8006F6EC: mul.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8006F6F0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8006F6F4: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8006F6F8: jal         0x80005D44
    // 0x8006F6FC: nop

    Matrix_RotateX(rdram, ctx);
        goto after_9;
    // 0x8006F6FC: nop

    after_9:
    // 0x8006F700: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x8006F704: lhu         $t5, 0x7828($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0X7828);
    // 0x8006F708: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8006F70C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8006F710: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x8006F714: swc1        $f0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f0.u32l;
    // 0x8006F718: swc1        $f0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f0.u32l;
    // 0x8006F71C: bgez        $t5, L_8006F734
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8006F720: cvt.s.w     $f18, $f6
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.fl = CVT_S_W(ctx->f6.u32l);
            goto L_8006F734;
    }
    // 0x8006F720: cvt.s.w     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8006F724: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8006F728: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8006F72C: nop

    // 0x8006F730: add.s       $f18, $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f10.fl;
L_8006F734:
    // 0x8006F734: swc1        $f18, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f18.u32l;
    // 0x8006F738: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8006F73C: addiu       $a1, $sp, 0x78
    ctx->r5 = ADD32(ctx->r29, 0X78);
    // 0x8006F740: jal         0x80006A20
    // 0x8006F744: addiu       $a2, $sp, 0x6C
    ctx->r6 = ADD32(ctx->r29, 0X6C);
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_10;
    // 0x8006F744: addiu       $a2, $sp, 0x6C
    ctx->r6 = ADD32(ctx->r29, 0X6C);
    after_10:
    // 0x8006F748: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8006F74C: lwc1        $f8, 0x6C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8006F750: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8006F754: lwc1        $f18, 0x70($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8006F758: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8006F75C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8006F760: addiu       $a0, $zero, 0x163
    ctx->r4 = ADD32(0, 0X163);
    // 0x8006F764: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8006F768: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8006F76C: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8006F770: lwc1        $f10, 0x74($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8006F774: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x8006F778: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8006F77C: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8006F780: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x8006F784: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x8006F788: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8006F78C: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x8006F790: lwc1        $f6, 0x18($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8006F794: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x8006F798: lwc1        $f4, 0x2E8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2E8);
    // 0x8006F79C: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x8006F7A0: lwc1        $f6, 0x2EC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2EC);
    // 0x8006F7A4: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x8006F7A8: lwc1        $f6, 0xFC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XFC);
    // 0x8006F7AC: lwc1        $f4, 0x2F0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2F0);
    // 0x8006F7B0: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    // 0x8006F7B4: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    // 0x8006F7B8: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8006F7BC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8006F7C0: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    // 0x8006F7C4: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x8006F7C8: jal         0x8007F04C
    // 0x8006F7CC: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    Effect_SpawnById2(rdram, ctx);
        goto after_11;
    // 0x8006F7CC: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    after_11:
    // 0x8006F7D0: b           L_8006FE14
    // 0x8006F7D4: sh          $zero, 0x48($s0)
    MEM_H(0X48, ctx->r16) = 0;
        goto L_8006FE14;
    // 0x8006F7D4: sh          $zero, 0x48($s0)
    MEM_H(0X48, ctx->r16) = 0;
L_8006F7D8:
    // 0x8006F7D8: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x8006F7DC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8006F7E0: lwc1        $f4, 0x138($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X138);
    // 0x8006F7E4: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8006F7E8: addiu       $a0, $zero, 0x163
    ctx->r4 = ADD32(0, 0X163);
    // 0x8006F7EC: sub.s       $f18, $f4, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x8006F7F0: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x8006F7F4: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x8006F7F8: nop

    // 0x8006F7FC: bc1f        L_8006F838
    if (!c1cs) {
        // 0x8006F800: nop
    
            goto L_8006F838;
    }
    // 0x8006F800: nop

    // 0x8006F804: lhu         $t6, 0x7828($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X7828);
    // 0x8006F808: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8006F80C: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x8006F810: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x8006F814: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    // 0x8006F818: bgez        $t6, L_8006F830
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8006F81C: cvt.s.w     $f6, $f10
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
            goto L_8006F830;
    }
    // 0x8006F81C: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8006F820: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8006F824: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8006F828: nop

    // 0x8006F82C: add.s       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f4.fl;
L_8006F830:
    // 0x8006F830: jal         0x8007F11C
    // 0x8006F834: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Effect_ShootAtPlayer(rdram, ctx);
        goto after_12;
    // 0x8006F834: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_12:
L_8006F838:
    // 0x8006F838: b           L_8006FE14
    // 0x8006F83C: sh          $zero, 0x48($s0)
    MEM_H(0X48, ctx->r16) = 0;
        goto L_8006FE14;
    // 0x8006F83C: sh          $zero, 0x48($s0)
    MEM_H(0X48, ctx->r16) = 0;
L_8006F840:
    // 0x8006F840: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x8006F844: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8006F848: lwc1        $f8, 0x138($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X138);
    // 0x8006F84C: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8006F850: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8006F854: sub.s       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x8006F858: addiu       $a0, $zero, 0x164
    ctx->r4 = ADD32(0, 0X164);
    // 0x8006F85C: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x8006F860: nop

    // 0x8006F864: bc1f        L_8006F884
    if (!c1cs) {
        // 0x8006F868: nop
    
            goto L_8006F884;
    }
    // 0x8006F868: nop

    // 0x8006F86C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8006F870: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x8006F874: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    // 0x8006F878: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8006F87C: jal         0x8007F11C
    // 0x8006F880: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Effect_ShootAtPlayer(rdram, ctx);
        goto after_13;
    // 0x8006F880: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_13:
L_8006F884:
    // 0x8006F884: b           L_8006FE14
    // 0x8006F888: sh          $zero, 0x48($s0)
    MEM_H(0X48, ctx->r16) = 0;
        goto L_8006FE14;
    // 0x8006F888: sh          $zero, 0x48($s0)
    MEM_H(0X48, ctx->r16) = 0;
L_8006F88C:
    // 0x8006F88C: lwc1        $f6, 0x74($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X74);
    // 0x8006F890: swc1        $f6, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f6.u32l;
    // 0x8006F894: lwc1        $f8, 0x78($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X78);
    // 0x8006F898: jal         0x80004EB0
    // 0x8006F89C: swc1        $f8, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f8.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_14;
    // 0x8006F89C: swc1        $f8, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f8.u32l;
    after_14:
    // 0x8006F8A0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8006F8A4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8006F8A8: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x8006F8AC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8006F8B0: sub.s       $f10, $f0, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x8006F8B4: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8006F8B8: lw          $v0, -0x7D80($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D80);
    // 0x8006F8BC: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8006F8C0: lwc1        $f8, 0x74($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X74);
    // 0x8006F8C4: add.s       $f18, $f8, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8006F8C8: jal         0x80004EB0
    // 0x8006F8CC: swc1        $f18, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->f18.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_15;
    // 0x8006F8CC: swc1        $f18, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->f18.u32l;
    after_15:
    // 0x8006F8D0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8006F8D4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8006F8D8: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x8006F8DC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8006F8E0: sub.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x8006F8E4: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8006F8E8: lw          $v0, -0x7D80($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D80);
    // 0x8006F8EC: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x8006F8F0: mul.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8006F8F4: lwc1        $f18, 0x78($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X78);
    // 0x8006F8F8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8006F8FC: addiu       $a0, $zero, 0x161
    ctx->r4 = ADD32(0, 0X161);
    // 0x8006F900: add.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x8006F904: swc1        $f10, 0x78($v0)
    MEM_W(0X78, ctx->r2) = ctx->f10.u32l;
    // 0x8006F908: lhu         $t7, 0x7828($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X7828);
    // 0x8006F90C: lw          $a3, 0xC($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XC);
    // 0x8006F910: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    // 0x8006F914: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8006F918: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x8006F91C: bgez        $t7, L_8006F930
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8006F920: cvt.s.w     $f8, $f4
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8006F930;
    }
    // 0x8006F920: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8006F924: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8006F928: nop

    // 0x8006F92C: add.s       $f8, $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f18.fl;
L_8006F930:
    // 0x8006F930: jal         0x8007F11C
    // 0x8006F934: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Effect_ShootAtPlayer(rdram, ctx);
        goto after_16;
    // 0x8006F934: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_16:
    // 0x8006F938: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8006F93C: addiu       $v0, $v0, -0x7D80
    ctx->r2 = ADD32(ctx->r2, -0X7D80);
    // 0x8006F940: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8006F944: lwc1        $f6, 0x6C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8006F948: swc1        $f6, 0x74($t8)
    MEM_W(0X74, ctx->r24) = ctx->f6.u32l;
    // 0x8006F94C: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x8006F950: lwc1        $f10, 0x70($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8006F954: swc1        $f10, 0x78($t9)
    MEM_W(0X78, ctx->r25) = ctx->f10.u32l;
    // 0x8006F958: b           L_8006FE14
    // 0x8006F95C: sh          $zero, 0x48($s0)
    MEM_H(0X48, ctx->r16) = 0;
        goto L_8006FE14;
    // 0x8006F95C: sh          $zero, 0x48($s0)
    MEM_H(0X48, ctx->r16) = 0;
L_8006F960:
    // 0x8006F960: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8006F964: lw          $t0, -0x7DCC($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7DCC);
    // 0x8006F968: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x8006F96C: bnel        $t0, $at, L_8006F994
    if (ctx->r8 != ctx->r1) {
        // 0x8006F970: lwc1        $f12, 0x4($s0)
        ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
            goto L_8006F994;
    }
    goto skip_3;
    // 0x8006F970: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    skip_3:
    // 0x8006F974: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8006F978: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8006F97C: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x8006F980: jal         0x8006F1EC
    // 0x8006F984: lui         $a3, 0x4140
    ctx->r7 = S32(0X4140 << 16);
    ActorEvent_Effect394_Spawn(rdram, ctx);
        goto after_17;
    // 0x8006F984: lui         $a3, 0x4140
    ctx->r7 = S32(0X4140 << 16);
    after_17:
    // 0x8006F988: b           L_8006F9A8
    // 0x8006F98C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8006F9A8;
    // 0x8006F98C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8006F990: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
L_8006F994:
    // 0x8006F994: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8006F998: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x8006F99C: jal         0x8006F0D8
    // 0x8006F9A0: lui         $a3, 0x4220
    ctx->r7 = S32(0X4220 << 16);
    ActorEvent_PinkExplosion_Spawn(rdram, ctx);
        goto after_18;
    // 0x8006F9A0: lui         $a3, 0x4220
    ctx->r7 = S32(0X4220 << 16);
    after_18:
    // 0x8006F9A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8006F9A8:
    // 0x8006F9A8: jal         0x80060FBC
    // 0x8006F9AC: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    Object_Kill(rdram, ctx);
        goto after_19;
    // 0x8006F9AC: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    after_19:
    // 0x8006F9B0: b           L_8006FE18
    // 0x8006F9B4: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_8006FE18;
    // 0x8006F9B4: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_8006F9B8:
    // 0x8006F9B8: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8006F9BC: lw          $t1, -0x7DCC($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X7DCC);
    // 0x8006F9C0: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x8006F9C4: lui         $a3, 0x4170
    ctx->r7 = S32(0X4170 << 16);
    // 0x8006F9C8: bnel        $t1, $at, L_8006F9F0
    if (ctx->r9 != ctx->r1) {
        // 0x8006F9CC: lwc1        $f12, 0x4($s0)
        ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
            goto L_8006F9F0;
    }
    goto skip_4;
    // 0x8006F9CC: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    skip_4:
    // 0x8006F9D0: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8006F9D4: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8006F9D8: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x8006F9DC: jal         0x8006F1EC
    // 0x8006F9E0: lui         $a3, 0x40C0
    ctx->r7 = S32(0X40C0 << 16);
    ActorEvent_Effect394_Spawn(rdram, ctx);
        goto after_20;
    // 0x8006F9E0: lui         $a3, 0x40C0
    ctx->r7 = S32(0X40C0 << 16);
    after_20:
    // 0x8006F9E4: b           L_8006FA00
    // 0x8006F9E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8006FA00;
    // 0x8006F9E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8006F9EC: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
L_8006F9F0:
    // 0x8006F9F0: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8006F9F4: jal         0x8006F0D8
    // 0x8006F9F8: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    ActorEvent_PinkExplosion_Spawn(rdram, ctx);
        goto after_21;
    // 0x8006F9F8: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    after_21:
    // 0x8006F9FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8006FA00:
    // 0x8006FA00: jal         0x80060FBC
    // 0x8006FA04: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    Object_Kill(rdram, ctx);
        goto after_22;
    // 0x8006FA04: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    after_22:
    // 0x8006FA08: b           L_8006FE18
    // 0x8006FA0C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_8006FE18;
    // 0x8006FA0C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_8006FA10:
    // 0x8006FA10: lwc1        $f4, 0xEC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x8006FA14: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8006FA18: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8006FA1C: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x8006FA20: lw          $a3, 0xE8($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XE8);
    // 0x8006FA24: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8006FA28: lwc1        $f18, 0xF0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XF0);
    // 0x8006FA2C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8006FA30: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8006FA34: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x8006FA38: lwc1        $f8, 0x110($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X110);
    // 0x8006FA3C: addiu       $t2, $zero, 0xF
    ctx->r10 = ADD32(0, 0XF);
    // 0x8006FA40: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x8006FA44: mul.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8006FA48: jal         0x8007BFFC
    // 0x8006FA4C: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    Effect_Effect386_Spawn1(rdram, ctx);
        goto after_23;
    // 0x8006FA4C: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    after_23:
    // 0x8006FA50: jal         0x80066254
    // 0x8006FA54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Actor_Despawn(rdram, ctx);
        goto after_24;
    // 0x8006FA54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x8006FA58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8006FA5C: jal         0x80060FBC
    // 0x8006FA60: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    Object_Kill(rdram, ctx);
        goto after_25;
    // 0x8006FA60: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    after_25:
    // 0x8006FA64: lui         $a1, 0x2903
    ctx->r5 = S32(0X2903 << 16);
    // 0x8006FA68: ori         $a1, $a1, 0xB009
    ctx->r5 = ctx->r5 | 0XB009;
    // 0x8006FA6C: jal         0x8007A6F0
    // 0x8006FA70: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    Effect_TimedSfx_Spawn(rdram, ctx);
        goto after_26;
    // 0x8006FA70: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    after_26:
    // 0x8006FA74: b           L_8006FE18
    // 0x8006FA78: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_8006FE18;
    // 0x8006FA78: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_8006FA7C:
    // 0x8006FA7C: jal         0x80066254
    // 0x8006FA80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Actor_Despawn(rdram, ctx);
        goto after_27;
    // 0x8006FA80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_27:
    // 0x8006FA84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8006FA88: jal         0x80060FBC
    // 0x8006FA8C: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    Object_Kill(rdram, ctx);
        goto after_28;
    // 0x8006FA8C: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    after_28:
    // 0x8006FA90: b           L_8006FE18
    // 0x8006FA94: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_8006FE18;
    // 0x8006FA94: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_8006FA98:
    // 0x8006FA98: lhu         $v0, 0xBE($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XBE);
    // 0x8006FA9C: addiu       $a0, $s0, 0x150
    ctx->r4 = ADD32(ctx->r16, 0X150);
    // 0x8006FAA0: lui         $a1, 0x42B4
    ctx->r5 = S32(0X42B4 << 16);
    // 0x8006FAA4: slti        $at, $v0, 0x1A
    ctx->r1 = SIGNED(ctx->r2) < 0X1A ? 1 : 0;
    // 0x8006FAA8: bne         $at, $zero, L_8006FACC
    if (ctx->r1 != 0) {
        // 0x8006FAAC: lui         $a2, 0x3E4C
        ctx->r6 = S32(0X3E4C << 16);
            goto L_8006FACC;
    }
    // 0x8006FAAC: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x8006FAB0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006FAB4: lwc1        $f4, 0x6C0C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6C0C);
    // 0x8006FAB8: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8006FABC: lui         $a3, 0x4100
    ctx->r7 = S32(0X4100 << 16);
    // 0x8006FAC0: jal         0x8009BC2C
    // 0x8006FAC4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_29;
    // 0x8006FAC4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_29:
    // 0x8006FAC8: lhu         $v0, 0xBE($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XBE);
L_8006FACC:
    // 0x8006FACC: slti        $at, $v0, 0x19
    ctx->r1 = SIGNED(ctx->r2) < 0X19 ? 1 : 0;
    // 0x8006FAD0: beq         $at, $zero, L_8006FB00
    if (ctx->r1 == 0) {
        // 0x8006FAD4: addiu       $a0, $s0, 0x150
        ctx->r4 = ADD32(ctx->r16, 0X150);
            goto L_8006FB00;
    }
    // 0x8006FAD4: addiu       $a0, $s0, 0x150
    ctx->r4 = ADD32(ctx->r16, 0X150);
    // 0x8006FAD8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8006FADC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006FAE0: lwc1        $f18, 0x6C10($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6C10);
    // 0x8006FAE4: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x8006FAE8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8006FAEC: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8006FAF0: lui         $a3, 0x4100
    ctx->r7 = S32(0X4100 << 16);
    // 0x8006FAF4: jal         0x8009BC2C
    // 0x8006FAF8: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_30;
    // 0x8006FAF8: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_30:
    // 0x8006FAFC: lhu         $v0, 0xBE($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XBE);
L_8006FB00:
    // 0x8006FB00: addiu       $at, $zero, 0x1E
    ctx->r1 = ADD32(0, 0X1E);
    // 0x8006FB04: bne         $v0, $at, L_8006FB28
    if (ctx->r2 != ctx->r1) {
        // 0x8006FB08: lui         $at, 0x4248
        ctx->r1 = S32(0X4248 << 16);
            goto L_8006FB28;
    }
    // 0x8006FB08: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8006FB0C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8006FB10: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8006FB14: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8006FB18: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x8006FB1C: jal         0x8006EC60
    // 0x8006FB20: sub.s       $f14, $f8, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f6.fl;
    ActorEvent_TiLandmine_Spawn(rdram, ctx);
        goto after_31;
    // 0x8006FB20: sub.s       $f14, $f8, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f6.fl;
    after_31:
    // 0x8006FB24: lhu         $v0, 0xBE($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XBE);
L_8006FB28:
    // 0x8006FB28: bnel        $v0, $zero, L_8006FE18
    if (ctx->r2 != 0) {
        // 0x8006FB2C: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_8006FE18;
    }
    goto skip_5;
    // 0x8006FB2C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_5:
    // 0x8006FB30: b           L_8006FE14
    // 0x8006FB34: sh          $zero, 0x48($s0)
    MEM_H(0X48, ctx->r16) = 0;
        goto L_8006FE14;
    // 0x8006FB34: sh          $zero, 0x48($s0)
    MEM_H(0X48, ctx->r16) = 0;
L_8006FB38:
    // 0x8006FB38: lui         $at, 0x433E
    ctx->r1 = S32(0X433E << 16);
    // 0x8006FB3C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8006FB40: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8006FB44: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8006FB48: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8006FB4C: add.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8006FB50: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8006FB54: lui         $at, 0x435C
    ctx->r1 = S32(0X435C << 16);
    // 0x8006FB58: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8006FB5C: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8006FB60: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8006FB64: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8006FB68: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x8006FB6C: lhu         $t3, 0x7828($t3)
    ctx->r11 = MEM_HU(ctx->r11, 0X7828);
    // 0x8006FB70: add.s       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x8006FB74: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x8006FB78: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x8006FB7C: addiu       $a0, $zero, 0x161
    ctx->r4 = ADD32(0, 0X161);
    // 0x8006FB80: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x8006FB84: bgez        $t3, L_8006FB9C
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8006FB88: cvt.s.w     $f10, $f6
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
            goto L_8006FB9C;
    }
    // 0x8006FB88: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8006FB8C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8006FB90: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8006FB94: nop

    // 0x8006FB98: add.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f4.fl;
L_8006FB9C:
    // 0x8006FB9C: jal         0x8007F11C
    // 0x8006FBA0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Effect_ShootAtPlayer(rdram, ctx);
        goto after_32;
    // 0x8006FBA0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_32:
    // 0x8006FBA4: lui         $at, 0x433E
    ctx->r1 = S32(0X433E << 16);
    // 0x8006FBA8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8006FBAC: lwc1        $f18, 0x4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8006FBB0: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8006FBB4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8006FBB8: sub.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x8006FBBC: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8006FBC0: lui         $at, 0x435C
    ctx->r1 = S32(0X435C << 16);
    // 0x8006FBC4: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8006FBC8: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8006FBCC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8006FBD0: add.s       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8006FBD4: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x8006FBD8: lhu         $t4, 0x7828($t4)
    ctx->r12 = MEM_HU(ctx->r12, 0X7828);
    // 0x8006FBDC: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8006FBE0: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x8006FBE4: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x8006FBE8: addiu       $a0, $zero, 0x161
    ctx->r4 = ADD32(0, 0X161);
    // 0x8006FBEC: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x8006FBF0: bgez        $t4, L_8006FC08
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8006FBF4: cvt.s.w     $f18, $f10
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
            goto L_8006FC08;
    }
    // 0x8006FBF4: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8006FBF8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8006FBFC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8006FC00: nop

    // 0x8006FC04: add.s       $f18, $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f8.fl;
L_8006FC08:
    // 0x8006FC08: jal         0x8007F11C
    // 0x8006FC0C: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Effect_ShootAtPlayer(rdram, ctx);
        goto after_33;
    // 0x8006FC0C: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_33:
    // 0x8006FC10: b           L_8006FE14
    // 0x8006FC14: sh          $zero, 0x48($s0)
    MEM_H(0X48, ctx->r16) = 0;
        goto L_8006FE14;
    // 0x8006FC14: sh          $zero, 0x48($s0)
    MEM_H(0X48, ctx->r16) = 0;
L_8006FC18:
    // 0x8006FC18: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x8006FC1C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8006FC20: lwc1        $f6, 0x48($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X48);
    // 0x8006FC24: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8006FC28: addiu       $a0, $zero, 0x161
    ctx->r4 = ADD32(0, 0X161);
    // 0x8006FC2C: sub.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x8006FC30: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x8006FC34: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x8006FC38: nop

    // 0x8006FC3C: bc1f        L_8006FC78
    if (!c1cs) {
        // 0x8006FC40: nop
    
            goto L_8006FC78;
    }
    // 0x8006FC40: nop

    // 0x8006FC44: lhu         $t5, 0x7828($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0X7828);
    // 0x8006FC48: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8006FC4C: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x8006FC50: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x8006FC54: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    // 0x8006FC58: bgez        $t5, L_8006FC70
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8006FC5C: cvt.s.w     $f18, $f8
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
            goto L_8006FC70;
    }
    // 0x8006FC5C: cvt.s.w     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8006FC60: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8006FC64: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8006FC68: nop

    // 0x8006FC6C: add.s       $f18, $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f6.fl;
L_8006FC70:
    // 0x8006FC70: jal         0x8007F20C
    // 0x8006FC74: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Effect_ShootAtCamera(rdram, ctx);
        goto after_34;
    // 0x8006FC74: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_34:
L_8006FC78:
    // 0x8006FC78: b           L_8006FE14
    // 0x8006FC7C: sh          $zero, 0x48($s0)
    MEM_H(0X48, ctx->r16) = 0;
        goto L_8006FE14;
    // 0x8006FC7C: sh          $zero, 0x48($s0)
    MEM_H(0X48, ctx->r16) = 0;
L_8006FC80:
    // 0x8006FC80: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8006FC84: addiu       $v0, $v0, 0x3400
    ctx->r2 = ADD32(ctx->r2, 0X3400);
    // 0x8006FC88: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8006FC8C: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    // 0x8006FC90: addiu       $a1, $zero, 0xAF
    ctx->r5 = ADD32(0, 0XAF);
    // 0x8006FC94: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
L_8006FC98:
    // 0x8006FC98: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x8006FC9C: bnel        $a0, $t6, L_8006FDEC
    if (ctx->r4 != ctx->r14) {
        // 0x8006FCA0: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8006FDEC;
    }
    goto skip_6;
    // 0x8006FCA0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_6:
    // 0x8006FCA4: lhu         $t7, 0x2($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X2);
    // 0x8006FCA8: bnel        $a1, $t7, L_8006FDEC
    if (ctx->r5 != ctx->r15) {
        // 0x8006FCAC: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8006FDEC;
    }
    goto skip_7;
    // 0x8006FCAC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_7:
    // 0x8006FCB0: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x8006FCB4: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8006FCB8: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8006FCBC: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8006FCC0: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8006FCC4: sub.s       $f18, $f8, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x8006FCC8: sub.s       $f12, $f4, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x8006FCCC: swc1        $f18, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f18.u32l;
    // 0x8006FCD0: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8006FCD4: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8006FCD8: swc1        $f12, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f12.u32l;
    // 0x8006FCDC: sub.s       $f14, $f4, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x8006FCE0: jal         0x80005100
    // 0x8006FCE4: swc1        $f14, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f14.u32l;
    Math_Atan2F(rdram, ctx);
        goto after_35;
    // 0x8006FCE4: swc1        $f14, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f14.u32l;
    after_35:
    // 0x8006FCE8: jal         0x8009F768
    // 0x8006FCEC: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    Math_RadToDeg(rdram, ctx);
        goto after_36;
    // 0x8006FCEC: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_36:
    // 0x8006FCF0: lwc1        $f2, 0x64($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8006FCF4: lwc1        $f16, 0x5C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8006FCF8: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    // 0x8006FCFC: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8006FD00: lwc1        $f12, 0x60($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8006FD04: mul.s       $f6, $f16, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x8006FD08: add.s       $f0, $f8, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8006FD0C: jal         0x80005100
    // 0x8006FD10: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    Math_Atan2F(rdram, ctx);
        goto after_37;
    // 0x8006FD10: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    after_37:
    // 0x8006FD14: jal         0x8009F768
    // 0x8006FD18: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
    Math_RadToDeg(rdram, ctx);
        goto after_38;
    // 0x8006FD18: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
    after_38:
    // 0x8006FD1C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006FD20: lwc1        $f18, 0x6C14($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6C14);
    // 0x8006FD24: lwc1        $f4, 0x54($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8006FD28: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8006FD2C: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    // 0x8006FD30: mul.s       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8006FD34: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8006FD38: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8006FD3C: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8006FD40: jal         0x80005E90
    // 0x8006FD44: nop

    Matrix_RotateY(rdram, ctx);
        goto after_39;
    // 0x8006FD44: nop

    after_39:
    // 0x8006FD48: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006FD4C: lwc1        $f8, 0x6C18($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6C18);
    // 0x8006FD50: lwc1        $f6, 0x58($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8006FD54: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8006FD58: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8006FD5C: mul.s       $f18, $f8, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8006FD60: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8006FD64: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8006FD68: jal         0x80005D44
    // 0x8006FD6C: nop

    Matrix_RotateX(rdram, ctx);
        goto after_40;
    // 0x8006FD6C: nop

    after_40:
    // 0x8006FD70: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8006FD74: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8006FD78: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8006FD7C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8006FD80: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8006FD84: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    // 0x8006FD88: addiu       $a2, $sp, 0x78
    ctx->r6 = ADD32(ctx->r29, 0X78);
    // 0x8006FD8C: swc1        $f0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f0.u32l;
    // 0x8006FD90: swc1        $f0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f0.u32l;
    // 0x8006FD94: jal         0x80006A20
    // 0x8006FD98: swc1        $f4, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f4.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_41;
    // 0x8006FD98: swc1        $f4, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f4.u32l;
    after_41:
    // 0x8006FD9C: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x8006FDA0: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    // 0x8006FDA4: lw          $a3, 0xC($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XC);
    // 0x8006FDA8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8006FDAC: lwc1        $f10, 0x78($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8006FDB0: lwc1        $f8, 0x7C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x8006FDB4: lwc1        $f6, 0x80($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X80);
    // 0x8006FDB8: lwc1        $f18, 0x58($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8006FDBC: lwc1        $f4, 0x54($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8006FDC0: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    // 0x8006FDC4: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x8006FDC8: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x8006FDCC: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x8006FDD0: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x8006FDD4: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    // 0x8006FDD8: jal         0x8006EFA0
    // 0x8006FDDC: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    Actor_SpawnGreatFoxLaser(rdram, ctx);
        goto after_42;
    // 0x8006FDDC: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    after_42:
    // 0x8006FDE0: b           L_8006FDF4
    // 0x8006FDE4: nop

        goto L_8006FDF4;
    // 0x8006FDE4: nop

    // 0x8006FDE8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8006FDEC:
    // 0x8006FDEC: bne         $v1, $a2, L_8006FC98
    if (ctx->r3 != ctx->r6) {
        // 0x8006FDF0: addiu       $v0, $v0, 0x4C
        ctx->r2 = ADD32(ctx->r2, 0X4C);
            goto L_8006FC98;
    }
    // 0x8006FDF0: addiu       $v0, $v0, 0x4C
    ctx->r2 = ADD32(ctx->r2, 0X4C);
L_8006FDF4:
    // 0x8006FDF4: b           L_8006FE14
    // 0x8006FDF8: sh          $zero, 0x48($s0)
    MEM_H(0X48, ctx->r16) = 0;
        goto L_8006FE14;
    // 0x8006FDF8: sh          $zero, 0x48($s0)
    MEM_H(0X48, ctx->r16) = 0;
L_8006FDFC:
    // 0x8006FDFC: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8006FE00: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8006FE04: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x8006FE08: jal         0x80083D2C
    // 0x8006FE0C: lui         $a3, 0x4220
    ctx->r7 = S32(0X4220 << 16);
    func_effect_80083D2C(rdram, ctx);
        goto after_43;
    // 0x8006FE0C: lui         $a3, 0x4220
    ctx->r7 = S32(0X4220 << 16);
    after_43:
    // 0x8006FE10: sh          $zero, 0x48($s0)
    MEM_H(0X48, ctx->r16) = 0;
L_8006FE14:
    // 0x8006FE14: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_8006FE18:
    // 0x8006FE18: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x8006FE1C: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    // 0x8006FE20: jr          $ra
    // 0x8006FE24: nop

    return;
    // 0x8006FE24: nop

;}
RECOMP_FUNC void AudioSynth_LoadWaveSamples(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B3F0: lui         $t6, 0x1408
    ctx->r14 = S32(0X1408 << 16);
    // 0x8000B3F4: ori         $t6, $t6, 0x5F0
    ctx->r14 = ctx->r14 | 0X5F0;
    // 0x8000B3F8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8000B3FC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8000B400: lw          $t7, 0xC($a1)
    ctx->r15 = MEM_W(ctx->r5, 0XC);
    // 0x8000B404: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000B408: addiu       $t2, $zero, 0x40
    ctx->r10 = ADD32(0, 0X40);
    // 0x8000B40C: addu        $t8, $t7, $at
    ctx->r24 = ADD32(ctx->r15, ctx->r1);
    // 0x8000B410: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8000B414: lw          $t9, 0x8($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X8);
    // 0x8000B418: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x8000B41C: andi        $t0, $t9, 0x3F
    ctx->r8 = ctx->r25 & 0X3F;
    // 0x8000B420: subu        $v1, $t2, $t0
    ctx->r3 = SUB32(ctx->r10, ctx->r8);
    // 0x8000B424: slt         $at, $v1, $a3
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8000B428: beq         $at, $zero, L_8000B478
    if (ctx->r1 == 0) {
        // 0x8000B42C: sw          $t0, 0x8($a2)
        MEM_W(0X8, ctx->r6) = ctx->r8;
            goto L_8000B478;
    }
    // 0x8000B42C: sw          $t0, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r8;
    // 0x8000B430: subu        $v0, $a3, $v1
    ctx->r2 = SUB32(ctx->r7, ctx->r3);
    // 0x8000B434: addiu       $v0, $v0, 0x3F
    ctx->r2 = ADD32(ctx->r2, 0X3F);
    // 0x8000B438: bgez        $v0, L_8000B448
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8000B43C: sra         $t3, $v0, 6
        ctx->r11 = S32(SIGNED(ctx->r2) >> 6);
            goto L_8000B448;
    }
    // 0x8000B43C: sra         $t3, $v0, 6
    ctx->r11 = S32(SIGNED(ctx->r2) >> 6);
    // 0x8000B440: addiu       $at, $v0, 0x3F
    ctx->r1 = ADD32(ctx->r2, 0X3F);
    // 0x8000B444: sra         $t3, $at, 6
    ctx->r11 = S32(SIGNED(ctx->r1) >> 6);
L_8000B448:
    // 0x8000B448: beq         $t3, $zero, L_8000B478
    if (ctx->r11 == 0) {
        // 0x8000B44C: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_8000B478;
    }
    // 0x8000B44C: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x8000B450: andi        $t4, $t3, 0xFF
    ctx->r12 = ctx->r11 & 0XFF;
    // 0x8000B454: sll         $t5, $t4, 16
    ctx->r13 = S32(ctx->r12 << 16);
    // 0x8000B458: lui         $at, 0x1A00
    ctx->r1 = S32(0X1A00 << 16);
    // 0x8000B45C: or          $t6, $t5, $at
    ctx->r14 = ctx->r13 | ctx->r1;
    // 0x8000B460: lui         $t8, 0x670
    ctx->r24 = S32(0X670 << 16);
    // 0x8000B464: ori         $t8, $t8, 0x80
    ctx->r24 = ctx->r24 | 0X80;
    // 0x8000B468: ori         $t7, $t6, 0x5F0
    ctx->r15 = ctx->r14 | 0X5F0;
    // 0x8000B46C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8000B470: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8000B474: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
L_8000B478:
    // 0x8000B478: jr          $ra
    // 0x8000B47C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x8000B47C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
;}
RECOMP_FUNC void MeMora_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B74C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8006B750: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x8006B754: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8006B758: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8006B75C: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x8006B760: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x8006B764: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x8006B768: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x8006B76C: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x8006B770: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x8006B774: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8006B778: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8006B77C: lh          $s0, 0x4A($s1)
    ctx->r16 = MEM_H(ctx->r17, 0X4A);
    // 0x8006B780: lui         $fp, 0x8017
    ctx->r30 = S32(0X8017 << 16);
    // 0x8006B784: addiu       $fp, $fp, 0x71D8
    ctx->r30 = ADD32(ctx->r30, 0X71D8);
    // 0x8006B788: slti        $at, $s0, 0x10
    ctx->r1 = SIGNED(ctx->r16) < 0X10 ? 1 : 0;
    // 0x8006B78C: beq         $at, $zero, L_8006B92C
    if (ctx->r1 == 0) {
        // 0x8006B790: lui         $s7, 0x8017
        ctx->r23 = S32(0X8017 << 16);
            goto L_8006B92C;
    }
    // 0x8006B790: lui         $s7, 0x8017
    ctx->r23 = S32(0X8017 << 16);
    // 0x8006B794: lui         $s6, 0x8017
    ctx->r22 = S32(0X8017 << 16);
    // 0x8006B798: lui         $s5, 0x8017
    ctx->r21 = S32(0X8017 << 16);
    // 0x8006B79C: lui         $s4, 0x8017
    ctx->r20 = S32(0X8017 << 16);
    // 0x8006B7A0: lui         $s2, 0x800D
    ctx->r18 = S32(0X800D << 16);
    // 0x8006B7A4: addiu       $s2, $s2, -0x6C
    ctx->r18 = ADD32(ctx->r18, -0X6C);
    // 0x8006B7A8: addiu       $s4, $s4, 0x6558
    ctx->r20 = ADD32(ctx->r20, 0X6558);
    // 0x8006B7AC: addiu       $s5, $s5, 0x6878
    ctx->r21 = ADD32(ctx->r21, 0X6878);
    // 0x8006B7B0: addiu       $s6, $s6, 0x6B98
    ctx->r22 = ADD32(ctx->r22, 0X6B98);
    // 0x8006B7B4: addiu       $s7, $s7, 0x6EB8
    ctx->r23 = ADD32(ctx->r23, 0X6EB8);
    // 0x8006B7B8: addiu       $s3, $zero, 0x64
    ctx->r19 = ADD32(0, 0X64);
    // 0x8006B7BC: sll         $t6, $s0, 1
    ctx->r14 = S32(ctx->r16 << 1);
L_8006B7C0:
    // 0x8006B7C0: addu        $t7, $s2, $t6
    ctx->r15 = ADD32(ctx->r18, ctx->r14);
    // 0x8006B7C4: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x8006B7C8: lh          $t9, 0x4E($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X4E);
    // 0x8006B7CC: lh          $v0, 0x46($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X46);
    // 0x8006B7D0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8006B7D4: addu        $t1, $t8, $t9
    ctx->r9 = ADD32(ctx->r24, ctx->r25);
    // 0x8006B7D8: div         $zero, $t1, $s3
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r19))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r19)));
    // 0x8006B7DC: sll         $t4, $v0, 2
    ctx->r12 = S32(ctx->r2 << 2);
    // 0x8006B7E0: bne         $s3, $zero, L_8006B7EC
    if (ctx->r19 != 0) {
        // 0x8006B7E4: nop
    
            goto L_8006B7EC;
    }
    // 0x8006B7E4: nop

    // 0x8006B7E8: break       7
    do_break(2147923944);
L_8006B7EC:
    // 0x8006B7EC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8006B7F0: bne         $s3, $at, L_8006B804
    if (ctx->r19 != ctx->r1) {
        // 0x8006B7F4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8006B804;
    }
    // 0x8006B7F4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8006B7F8: bne         $t1, $at, L_8006B804
    if (ctx->r9 != ctx->r1) {
        // 0x8006B7FC: nop
    
            goto L_8006B804;
    }
    // 0x8006B7FC: nop

    // 0x8006B800: break       6
    do_break(2147923968);
L_8006B804:
    // 0x8006B804: subu        $t4, $t4, $v0
    ctx->r12 = SUB32(ctx->r12, ctx->r2);
    // 0x8006B808: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x8006B80C: sll         $t1, $v0, 2
    ctx->r9 = S32(ctx->r2 << 2);
    // 0x8006B810: subu        $t1, $t1, $v0
    ctx->r9 = SUB32(ctx->r9, ctx->r2);
    // 0x8006B814: addu        $t4, $t4, $v0
    ctx->r12 = ADD32(ctx->r12, ctx->r2);
    // 0x8006B818: mfhi        $t0
    ctx->r8 = hi;
    // 0x8006B81C: sll         $t4, $t4, 4
    ctx->r12 = S32(ctx->r12 << 4);
    // 0x8006B820: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x8006B824: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x8006B828: sll         $t2, $t0, 16
    ctx->r10 = S32(ctx->r8 << 16);
    // 0x8006B82C: addu        $t5, $s4, $t4
    ctx->r13 = ADD32(ctx->r20, ctx->r12);
    // 0x8006B830: subu        $t7, $t7, $v0
    ctx->r15 = SUB32(ctx->r15, ctx->r2);
    // 0x8006B834: addu        $t1, $t1, $v0
    ctx->r9 = ADD32(ctx->r9, ctx->r2);
    // 0x8006B838: sra         $t3, $t2, 16
    ctx->r11 = S32(SIGNED(ctx->r10) >> 16);
    // 0x8006B83C: sll         $t1, $t1, 4
    ctx->r9 = S32(ctx->r9 << 4);
    // 0x8006B840: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8006B844: sll         $t4, $v0, 2
    ctx->r12 = S32(ctx->r2 << 2);
    // 0x8006B848: addu        $t2, $s6, $t1
    ctx->r10 = ADD32(ctx->r22, ctx->r9);
    // 0x8006B84C: subu        $t4, $t4, $v0
    ctx->r12 = SUB32(ctx->r12, ctx->r2);
    // 0x8006B850: addu        $t7, $t7, $v0
    ctx->r15 = ADD32(ctx->r15, ctx->r2);
    // 0x8006B854: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x8006B858: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x8006B85C: sll         $v1, $t3, 2
    ctx->r3 = S32(ctx->r11 << 2);
    // 0x8006B860: sll         $t1, $v0, 2
    ctx->r9 = S32(ctx->r2 << 2);
    // 0x8006B864: addu        $t6, $t5, $v1
    ctx->r14 = ADD32(ctx->r13, ctx->r3);
    // 0x8006B868: addu        $t8, $s5, $t7
    ctx->r24 = ADD32(ctx->r21, ctx->r15);
    // 0x8006B86C: subu        $t1, $t1, $v0
    ctx->r9 = SUB32(ctx->r9, ctx->r2);
    // 0x8006B870: addu        $t4, $t4, $v0
    ctx->r12 = ADD32(ctx->r12, ctx->r2);
    // 0x8006B874: sll         $t4, $t4, 4
    ctx->r12 = S32(ctx->r12 << 4);
    // 0x8006B878: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x8006B87C: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x8006B880: addu        $t5, $s7, $t4
    ctx->r13 = ADD32(ctx->r23, ctx->r12);
    // 0x8006B884: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    // 0x8006B888: subu        $t7, $t7, $v0
    ctx->r15 = SUB32(ctx->r15, ctx->r2);
    // 0x8006B88C: addu        $t1, $t1, $v0
    ctx->r9 = ADD32(ctx->r9, ctx->r2);
    // 0x8006B890: sll         $t1, $t1, 4
    ctx->r9 = S32(ctx->r9 << 4);
    // 0x8006B894: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8006B898: addu        $t6, $t5, $v1
    ctx->r14 = ADD32(ctx->r13, ctx->r3);
    // 0x8006B89C: addu        $t3, $t2, $v1
    ctx->r11 = ADD32(ctx->r10, ctx->r3);
    // 0x8006B8A0: lwc1        $f4, 0x0($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X0);
    // 0x8006B8A4: addu        $t2, $t1, $v1
    ctx->r10 = ADD32(ctx->r9, ctx->r3);
    // 0x8006B8A8: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x8006B8AC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8006B8B0: addu        $t7, $t7, $v0
    ctx->r15 = ADD32(ctx->r15, ctx->r2);
    // 0x8006B8B4: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x8006B8B8: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x8006B8BC: lw          $a2, 0x0($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X0);
    // 0x8006B8C0: lw          $a3, 0x0($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X0);
    // 0x8006B8C4: lwc1        $f8, 0x7500($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7500);
    // 0x8006B8C8: addu        $t8, $fp, $t7
    ctx->r24 = ADD32(ctx->r30, ctx->r15);
    // 0x8006B8CC: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x8006B8D0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006B8D4: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x8006B8D8: sll         $t4, $s0, 2
    ctx->r12 = S32(ctx->r16 << 2);
    // 0x8006B8DC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8006B8E0: lwc1        $f6, 0x0($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X0);
    // 0x8006B8E4: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x8006B8E8: addu        $t3, $t3, $s0
    ctx->r11 = ADD32(ctx->r11, ctx->r16);
    // 0x8006B8EC: lbu         $t3, -0x4C($t3)
    ctx->r11 = MEM_BU(ctx->r11, -0X4C);
    // 0x8006B8F0: lwc1        $f10, -0x3C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X3C);
    // 0x8006B8F4: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x8006B8F8: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x8006B8FC: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x8006B900: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    // 0x8006B904: lhu         $t5, 0xC6($s1)
    ctx->r13 = MEM_HU(ctx->r17, 0XC6);
    // 0x8006B908: andi        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 & 0X1;
    // 0x8006B90C: jal         0x8006B46C
    // 0x8006B910: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    MeMora_DrawParts(rdram, ctx);
        goto after_0;
    // 0x8006B910: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x8006B914: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8006B918: sll         $t7, $s0, 16
    ctx->r15 = S32(ctx->r16 << 16);
    // 0x8006B91C: sra         $s0, $t7, 16
    ctx->r16 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8006B920: slti        $at, $s0, 0x10
    ctx->r1 = SIGNED(ctx->r16) < 0X10 ? 1 : 0;
    // 0x8006B924: bnel        $at, $zero, L_8006B7C0
    if (ctx->r1 != 0) {
        // 0x8006B928: sll         $t6, $s0, 1
        ctx->r14 = S32(ctx->r16 << 1);
            goto L_8006B7C0;
    }
    goto skip_0;
    // 0x8006B928: sll         $t6, $s0, 1
    ctx->r14 = S32(ctx->r16 << 1);
    skip_0:
L_8006B92C:
    // 0x8006B92C: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x8006B930: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8006B934: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x8006B938: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x8006B93C: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x8006B940: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x8006B944: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x8006B948: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x8006B94C: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x8006B950: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x8006B954: jr          $ra
    // 0x8006B958: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8006B958: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void TexturedLine_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060968: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x8006096C: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x80060970: lui         $s6, 0x8018
    ctx->r22 = S32(0X8018 << 16);
    // 0x80060974: addiu       $s6, $s6, -0x7DCC
    ctx->r22 = ADD32(ctx->r22, -0X7DCC);
    // 0x80060978: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x8006097C: sw          $fp, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r30;
    // 0x80060980: sw          $s7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r23;
    // 0x80060984: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x80060988: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x8006098C: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x80060990: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x80060994: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x80060998: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x8006099C: sdc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X40, ctx->r29);
    // 0x800609A0: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x800609A4: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x800609A8: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x800609AC: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x800609B0: lw          $a0, 0x0($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X0);
    // 0x800609B4: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x800609B8: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x800609BC: bne         $a0, $at, L_800609F4
    if (ctx->r4 != ctx->r1) {
        // 0x800609C0: addiu       $s2, $s2, 0x7E64
        ctx->r18 = ADD32(ctx->r18, 0X7E64);
            goto L_800609F4;
    }
    // 0x800609C0: addiu       $s2, $s2, 0x7E64
    ctx->r18 = ADD32(ctx->r18, 0X7E64);
    // 0x800609C4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800609C8: jal         0x800B8DD0
    // 0x800609CC: addiu       $a1, $zero, 0x21
    ctx->r5 = ADD32(0, 0X21);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x800609CC: addiu       $a1, $zero, 0x21
    ctx->r5 = ADD32(0, 0X21);
    after_0:
    // 0x800609D0: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800609D4: lui         $t7, 0xB600
    ctx->r15 = S32(0XB600 << 16);
    // 0x800609D8: addiu       $t8, $zero, 0x2000
    ctx->r24 = ADD32(0, 0X2000);
    // 0x800609DC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800609E0: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
    // 0x800609E4: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800609E8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800609EC: b           L_80060A30
    // 0x800609F0: addiu       $fp, $zero, 0xD
    ctx->r30 = ADD32(0, 0XD);
        goto L_80060A30;
    // 0x800609F0: addiu       $fp, $zero, 0xD
    ctx->r30 = ADD32(0, 0XD);
L_800609F4:
    // 0x800609F4: addiu       $fp, $zero, 0xD
    ctx->r30 = ADD32(0, 0XD);
    // 0x800609F8: beq         $fp, $a0, L_80060A04
    if (ctx->r30 == ctx->r4) {
        // 0x800609FC: addiu       $at, $zero, 0x9
        ctx->r1 = ADD32(0, 0X9);
            goto L_80060A04;
    }
    // 0x800609FC: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80060A00: bne         $a0, $at, L_80060A20
    if (ctx->r4 != ctx->r1) {
        // 0x80060A04: lui         $s2, 0x8013
        ctx->r18 = S32(0X8013 << 16);
            goto L_80060A20;
    }
L_80060A04:
    // 0x80060A04: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x80060A08: addiu       $s2, $s2, 0x7E64
    ctx->r18 = ADD32(ctx->r18, 0X7E64);
    // 0x80060A0C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80060A10: jal         0x800B8DD0
    // 0x80060A14: addiu       $a1, $zero, 0x29
    ctx->r5 = ADD32(0, 0X29);
    RCP_SetupDL(rdram, ctx);
        goto after_1;
    // 0x80060A14: addiu       $a1, $zero, 0x29
    ctx->r5 = ADD32(0, 0X29);
    after_1:
    // 0x80060A18: b           L_80060A34
    // 0x80060A1C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
        goto L_80060A34;
    // 0x80060A1C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_80060A20:
    // 0x80060A20: jal         0x800B92F8
    // 0x80060A24: nop

    RCP_SetupDL_14(rdram, ctx);
        goto after_2;
    // 0x80060A24: nop

    after_2:
    // 0x80060A28: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x80060A2C: addiu       $s2, $s2, 0x7E64
    ctx->r18 = ADD32(ctx->r18, 0X7E64);
L_80060A30:
    // 0x80060A30: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_80060A34:
    // 0x80060A34: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x80060A38: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80060A3C: lwc1        $f26, 0x63C0($at)
    ctx->f26.u32l = MEM_W(ctx->r1, 0X63C0);
    // 0x80060A40: lui         $at, 0xC348
    ctx->r1 = S32(0XC348 << 16);
    // 0x80060A44: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80060A48: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80060A4C: lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // 0x80060A50: lui         $s5, 0x8017
    ctx->r21 = S32(0X8017 << 16);
    // 0x80060A54: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x80060A58: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80060A5C: addiu       $s1, $s1, -0x4C40
    ctx->r17 = ADD32(ctx->r17, -0X4C40);
    // 0x80060A60: addiu       $s5, $s5, 0x7DB0
    ctx->r21 = ADD32(ctx->r21, 0X7DB0);
    // 0x80060A64: addiu       $s0, $s0, 0x4750
    ctx->r16 = ADD32(ctx->r16, 0X4750);
    // 0x80060A68: lwc1        $f22, 0x63C4($at)
    ctx->f22.u32l = MEM_W(ctx->r1, 0X63C4);
    // 0x80060A6C: lui         $s7, 0xFA00
    ctx->r23 = S32(0XFA00 << 16);
    // 0x80060A70: lui         $s4, 0x600
    ctx->r20 = S32(0X600 << 16);
    // 0x80060A74: lbu         $t9, 0x0($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X0);
L_80060A78:
    // 0x80060A78: beq         $t9, $zero, L_80060D3C
    if (ctx->r25 == 0) {
        // 0x80060A7C: nop
    
            goto L_80060D3C;
    }
    // 0x80060A7C: nop

    // 0x80060A80: jal         0x80005708
    // 0x80060A84: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Push(rdram, ctx);
        goto after_3;
    // 0x80060A84: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x80060A88: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80060A8C: lwc1        $f6, 0x7D20($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x80060A90: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80060A94: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80060A98: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80060A9C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80060AA0: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80060AA4: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x80060AA8: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    // 0x80060AAC: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x80060AB0: jal         0x80005B00
    // 0x80060AB4: nop

    Matrix_Translate(rdram, ctx);
        goto after_4;
    // 0x80060AB4: nop

    after_4:
    // 0x80060AB8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80060ABC: lw          $a1, 0x20($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X20);
    // 0x80060AC0: jal         0x80005E90
    // 0x80060AC4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateY(rdram, ctx);
        goto after_5;
    // 0x80060AC4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x80060AC8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80060ACC: lw          $a1, 0x1C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1C);
    // 0x80060AD0: jal         0x80005D44
    // 0x80060AD4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateX(rdram, ctx);
        goto after_6;
    // 0x80060AD4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_6:
    // 0x80060AD8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80060ADC: lw          $a1, 0x20($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X20);
    // 0x80060AE0: jal         0x80005FE0
    // 0x80060AE4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateZ(rdram, ctx);
        goto after_7;
    // 0x80060AE4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_7:
    // 0x80060AE8: lwc1        $f0, 0x28($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X28);
    // 0x80060AEC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80060AF0: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80060AF4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80060AF8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80060AFC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80060B00: jal         0x80005C34
    // 0x80060B04: lw          $a3, 0x24($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X24);
    Matrix_Scale(rdram, ctx);
        goto after_8;
    // 0x80060B04: lw          $a3, 0x24($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X24);
    after_8:
    // 0x80060B08: lw          $a0, 0x0($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X0);
    // 0x80060B0C: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80060B10: beql        $fp, $a0, L_80060B24
    if (ctx->r30 == ctx->r4) {
        // 0x80060B14: lw          $t2, 0x0($s5)
        ctx->r10 = MEM_W(ctx->r21, 0X0);
            goto L_80060B24;
    }
    goto skip_0;
    // 0x80060B14: lw          $t2, 0x0($s5)
    ctx->r10 = MEM_W(ctx->r21, 0X0);
    skip_0:
    // 0x80060B18: bne         $a0, $at, L_80060CA0
    if (ctx->r4 != ctx->r1) {
        // 0x80060B1C: nop
    
            goto L_80060CA0;
    }
    // 0x80060B1C: nop

    // 0x80060B20: lw          $t2, 0x0($s5)
    ctx->r10 = MEM_W(ctx->r21, 0X0);
L_80060B24:
    // 0x80060B24: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    // 0x80060B28: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x80060B2C: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x80060B30: beq         $t3, $zero, L_80060B40
    if (ctx->r11 == 0) {
        // 0x80060B34: lui         $a2, 0x3E99
        ctx->r6 = S32(0X3E99 << 16);
            goto L_80060B40;
    }
    // 0x80060B34: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x80060B38: b           L_80060B40
    // 0x80060B3C: addiu       $a1, $zero, 0xB4
    ctx->r5 = ADD32(0, 0XB4);
        goto L_80060B40;
    // 0x80060B3C: addiu       $a1, $zero, 0xB4
    ctx->r5 = ADD32(0, 0XB4);
L_80060B40:
    // 0x80060B40: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80060B44: andi        $t5, $a1, 0xFF
    ctx->r13 = ctx->r5 & 0XFF;
    // 0x80060B48: or          $t6, $t5, $at
    ctx->r14 = ctx->r13 | ctx->r1;
    // 0x80060B4C: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x80060B50: sw          $t4, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r12;
    // 0x80060B54: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80060B58: sw          $s7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r23;
    // 0x80060B5C: lw          $a0, 0x0($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X0);
    // 0x80060B60: lui         $a1, 0x3C23
    ctx->r5 = S32(0X3C23 << 16);
    // 0x80060B64: ori         $a1, $a1, 0xD70A
    ctx->r5 = ctx->r5 | 0XD70A;
    // 0x80060B68: bne         $fp, $a0, L_80060C04
    if (ctx->r30 != ctx->r4) {
        // 0x80060B6C: addiu       $at, $zero, 0x9
        ctx->r1 = ADD32(0, 0X9);
            goto L_80060C04;
    }
    // 0x80060B6C: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80060B70: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80060B74: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80060B78: lui         $s3, 0x601
    ctx->r19 = S32(0X601 << 16);
    // 0x80060B7C: addiu       $s3, $s3, 0x19A0
    ctx->r19 = ADD32(ctx->r19, 0X19A0);
    // 0x80060B80: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80060B84: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80060B88: jal         0x80005C34
    // 0x80060B8C: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    Matrix_Scale(rdram, ctx);
        goto after_9;
    // 0x80060B8C: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    after_9:
    // 0x80060B90: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80060B94: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80060B98: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x80060B9C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80060BA0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80060BA4: jal         0x80005B00
    // 0x80060BA8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_10;
    // 0x80060BA8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_10:
    // 0x80060BAC: lw          $t9, 0x0($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X0);
    // 0x80060BB0: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80060BB4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80060BB8: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x80060BBC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80060BC0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80060BC4: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80060BC8: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80060BCC: nop

    // 0x80060BD0: mul.s       $f6, $f4, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f26.fl);
    // 0x80060BD4: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80060BD8: jal         0x80005FE0
    // 0x80060BDC: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_11;
    // 0x80060BDC: nop

    after_11:
    // 0x80060BE0: jal         0x80006EB8
    // 0x80060BE4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_12;
    // 0x80060BE4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_12:
    // 0x80060BE8: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80060BEC: addiu       $t0, $v0, 0x8
    ctx->r8 = ADD32(ctx->r2, 0X8);
    // 0x80060BF0: sw          $t0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r8;
    // 0x80060BF4: sw          $s3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r19;
    // 0x80060BF8: sw          $s4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r20;
    // 0x80060BFC: b           L_80060D34
    // 0x80060C00: nop

        goto L_80060D34;
    // 0x80060C00: nop

L_80060C04:
    // 0x80060C04: bne         $a0, $at, L_80060D34
    if (ctx->r4 != ctx->r1) {
        // 0x80060C08: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_80060D34;
    }
    // 0x80060C08: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80060C0C: mfc1        $a1, $f28
    ctx->r5 = (int32_t)ctx->f28.u32l;
    // 0x80060C10: mfc1        $a2, $f28
    ctx->r6 = (int32_t)ctx->f28.u32l;
    // 0x80060C14: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80060C18: lui         $s3, 0xC01
    ctx->r19 = S32(0XC01 << 16);
    // 0x80060C1C: addiu       $s3, $s3, 0x7440
    ctx->r19 = ADD32(ctx->r19, 0X7440);
    // 0x80060C20: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80060C24: jal         0x80005C34
    // 0x80060C28: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    Matrix_Scale(rdram, ctx);
        goto after_13;
    // 0x80060C28: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_13:
    // 0x80060C2C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80060C30: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80060C34: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x80060C38: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80060C3C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80060C40: jal         0x80005B00
    // 0x80060C44: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_14;
    // 0x80060C44: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_14:
    // 0x80060C48: lw          $t3, 0x0($s5)
    ctx->r11 = MEM_W(ctx->r21, 0X0);
    // 0x80060C4C: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x80060C50: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80060C54: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x80060C58: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80060C5C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80060C60: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80060C64: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80060C68: nop

    // 0x80060C6C: mul.s       $f4, $f18, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f26.fl);
    // 0x80060C70: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80060C74: jal         0x80005FE0
    // 0x80060C78: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_15;
    // 0x80060C78: nop

    after_15:
    // 0x80060C7C: jal         0x80006EB8
    // 0x80060C80: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_16;
    // 0x80060C80: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_16:
    // 0x80060C84: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80060C88: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x80060C8C: sw          $t4, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r12;
    // 0x80060C90: sw          $s3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r19;
    // 0x80060C94: sw          $s4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r20;
    // 0x80060C98: b           L_80060D34
    // 0x80060C9C: nop

        goto L_80060D34;
    // 0x80060C9C: nop

L_80060CA0:
    // 0x80060CA0: jal         0x80006EB8
    // 0x80060CA4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_17;
    // 0x80060CA4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_17:
    // 0x80060CA8: lw          $t5, 0x0($s6)
    ctx->r13 = MEM_W(ctx->r22, 0X0);
    // 0x80060CAC: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80060CB0: bnel        $t5, $at, L_80060CE0
    if (ctx->r13 != ctx->r1) {
        // 0x80060CB4: lw          $v0, 0x0($s2)
        ctx->r2 = MEM_W(ctx->r18, 0X0);
            goto L_80060CE0;
    }
    goto skip_1;
    // 0x80060CB4: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    skip_1:
    // 0x80060CB8: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80060CBC: lui         $t7, 0x601
    ctx->r15 = S32(0X601 << 16);
    // 0x80060CC0: addiu       $t7, $t7, 0x2C00
    ctx->r15 = ADD32(ctx->r15, 0X2C00);
    // 0x80060CC4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80060CC8: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
    // 0x80060CCC: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80060CD0: sw          $s4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r20;
    // 0x80060CD4: b           L_80060D34
    // 0x80060CD8: nop

        goto L_80060D34;
    // 0x80060CD8: nop

    // 0x80060CDC: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
L_80060CE0:
    // 0x80060CE0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80060CE4: sw          $t8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r24;
    // 0x80060CE8: sw          $s7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r23;
    // 0x80060CEC: lbu         $t3, 0x2D($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X2D);
    // 0x80060CF0: lbu         $t0, 0x2C($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X2C);
    // 0x80060CF4: lbu         $t7, 0x2E($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X2E);
    // 0x80060CF8: lbu         $t2, 0x2F($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X2F);
    // 0x80060CFC: sll         $t4, $t3, 16
    ctx->r12 = S32(ctx->r11 << 16);
    // 0x80060D00: sll         $t1, $t0, 24
    ctx->r9 = S32(ctx->r8 << 24);
    // 0x80060D04: or          $t5, $t1, $t4
    ctx->r13 = ctx->r9 | ctx->r12;
    // 0x80060D08: sll         $t8, $t7, 8
    ctx->r24 = S32(ctx->r15 << 8);
    // 0x80060D0C: or          $t9, $t5, $t8
    ctx->r25 = ctx->r13 | ctx->r24;
    // 0x80060D10: or          $t3, $t9, $t2
    ctx->r11 = ctx->r25 | ctx->r10;
    // 0x80060D14: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x80060D18: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80060D1C: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x80060D20: addiu       $t4, $t4, -0x280
    ctx->r12 = ADD32(ctx->r12, -0X280);
    // 0x80060D24: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x80060D28: sw          $t1, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r9;
    // 0x80060D2C: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80060D30: sw          $s4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r20;
L_80060D34:
    // 0x80060D34: jal         0x80005740
    // 0x80060D38: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_18;
    // 0x80060D38: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_18:
L_80060D3C:
    // 0x80060D3C: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x80060D40: addiu       $t6, $t6, 0x5A10
    ctx->r14 = ADD32(ctx->r14, 0X5A10);
    // 0x80060D44: addiu       $s0, $s0, 0x30
    ctx->r16 = ADD32(ctx->r16, 0X30);
    // 0x80060D48: bnel        $s0, $t6, L_80060A78
    if (ctx->r16 != ctx->r14) {
        // 0x80060D4C: lbu         $t9, 0x0($s0)
        ctx->r25 = MEM_BU(ctx->r16, 0X0);
            goto L_80060A78;
    }
    goto skip_2;
    // 0x80060D4C: lbu         $t9, 0x0($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X0);
    skip_2:
    // 0x80060D50: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x80060D54: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80060D58: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x80060D5C: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x80060D60: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x80060D64: ldc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X40);
    // 0x80060D68: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x80060D6C: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x80060D70: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x80060D74: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x80060D78: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x80060D7C: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x80060D80: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x80060D84: lw          $s7, 0x64($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X64);
    // 0x80060D88: lw          $fp, 0x68($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X68);
    // 0x80060D8C: jr          $ra
    // 0x80060D90: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x80060D90: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void Aquas_CsLevelStart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800935E8: addiu       $sp, $sp, -0x260
    ctx->r29 = ADD32(ctx->r29, -0X260);
    // 0x800935EC: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x800935F0: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x800935F4: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800935F8: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x800935FC: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x80093600: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x80093604: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80093608: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x8009360C: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x80093610: addiu       $t7, $t7, 0x22D8
    ctx->r15 = ADD32(ctx->r15, 0X22D8);
    // 0x80093614: addiu       $t2, $t7, 0x24
    ctx->r10 = ADD32(ctx->r15, 0X24);
    // 0x80093618: addiu       $t6, $sp, 0x23C
    ctx->r14 = ADD32(ctx->r29, 0X23C);
L_8009361C:
    // 0x8009361C: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x80093620: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x80093624: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80093628: sw          $at, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r1;
    // 0x8009362C: lw          $at, -0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, -0X8);
    // 0x80093630: sw          $at, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r1;
    // 0x80093634: lw          $at, -0x4($t7)
    ctx->r1 = MEM_W(ctx->r15, -0X4);
    // 0x80093638: bne         $t7, $t2, L_8009361C
    if (ctx->r15 != ctx->r10) {
        // 0x8009363C: sw          $at, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r1;
            goto L_8009361C;
    }
    // 0x8009363C: sw          $at, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r1;
    // 0x80093640: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x80093644: addiu       $t4, $t4, 0x22FC
    ctx->r12 = ADD32(ctx->r12, 0X22FC);
    // 0x80093648: addiu       $t8, $t4, 0x24
    ctx->r24 = ADD32(ctx->r12, 0X24);
    // 0x8009364C: addiu       $t3, $sp, 0x218
    ctx->r11 = ADD32(ctx->r29, 0X218);
L_80093650:
    // 0x80093650: lw          $at, 0x0($t4)
    ctx->r1 = MEM_W(ctx->r12, 0X0);
    // 0x80093654: addiu       $t4, $t4, 0xC
    ctx->r12 = ADD32(ctx->r12, 0XC);
    // 0x80093658: addiu       $t3, $t3, 0xC
    ctx->r11 = ADD32(ctx->r11, 0XC);
    // 0x8009365C: sw          $at, -0xC($t3)
    MEM_W(-0XC, ctx->r11) = ctx->r1;
    // 0x80093660: lw          $at, -0x8($t4)
    ctx->r1 = MEM_W(ctx->r12, -0X8);
    // 0x80093664: sw          $at, -0x8($t3)
    MEM_W(-0X8, ctx->r11) = ctx->r1;
    // 0x80093668: lw          $at, -0x4($t4)
    ctx->r1 = MEM_W(ctx->r12, -0X4);
    // 0x8009366C: bne         $t4, $t8, L_80093650
    if (ctx->r12 != ctx->r24) {
        // 0x80093670: sw          $at, -0x4($t3)
        MEM_W(-0X4, ctx->r11) = ctx->r1;
            goto L_80093650;
    }
    // 0x80093670: sw          $at, -0x4($t3)
    MEM_W(-0X4, ctx->r11) = ctx->r1;
    // 0x80093674: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x80093678: addiu       $t7, $t7, 0x2320
    ctx->r15 = ADD32(ctx->r15, 0X2320);
    // 0x8009367C: addiu       $t5, $t7, 0x180
    ctx->r13 = ADD32(ctx->r15, 0X180);
    // 0x80093680: addiu       $t2, $sp, 0x98
    ctx->r10 = ADD32(ctx->r29, 0X98);
L_80093684:
    // 0x80093684: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x80093688: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x8009368C: addiu       $t2, $t2, 0xC
    ctx->r10 = ADD32(ctx->r10, 0XC);
    // 0x80093690: sw          $at, -0xC($t2)
    MEM_W(-0XC, ctx->r10) = ctx->r1;
    // 0x80093694: lw          $at, -0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, -0X8);
    // 0x80093698: sw          $at, -0x8($t2)
    MEM_W(-0X8, ctx->r10) = ctx->r1;
    // 0x8009369C: lw          $at, -0x4($t7)
    ctx->r1 = MEM_W(ctx->r15, -0X4);
    // 0x800936A0: bne         $t7, $t5, L_80093684
    if (ctx->r15 != ctx->r13) {
        // 0x800936A4: sw          $at, -0x4($t2)
        MEM_W(-0X4, ctx->r10) = ctx->r1;
            goto L_80093684;
    }
    // 0x800936A4: sw          $at, -0x4($t2)
    MEM_W(-0X4, ctx->r10) = ctx->r1;
    // 0x800936A8: lw          $t8, 0x1D0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X1D0);
    // 0x800936AC: lui         $s4, 0x8014
    ctx->r20 = S32(0X8014 << 16);
    // 0x800936B0: addiu       $s4, $s4, -0x4438
    ctx->r20 = ADD32(ctx->r20, -0X4438);
    // 0x800936B4: sltiu       $at, $t8, 0x7
    ctx->r1 = ctx->r24 < 0X7 ? 1 : 0;
    // 0x800936B8: beq         $at, $zero, L_80094764
    if (ctx->r1 == 0) {
        // 0x800936BC: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80094764;
    }
    // 0x800936BC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800936C0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800936C4: addu        $at, $at, $t8
    gpr jr_addend_800936CC = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x800936C8: lw          $t8, 0x7FFC($at)
    ctx->r24 = ADD32(ctx->r1, 0X7FFC);
    // 0x800936CC: jr          $t8
    // 0x800936D0: nop

    switch (jr_addend_800936CC >> 2) {
        case 0: goto L_800936D4; break;
        case 1: goto L_8009384C; break;
        case 2: goto L_80093D00; break;
        case 3: goto L_80093E40; break;
        case 4: goto L_80094354; break;
        case 5: goto L_80094378; break;
        case 6: goto L_8009447C; break;
        default: switch_error(__func__, 0x800936CC, 0x800D7FFC);
    }
    // 0x800936D0: nop

L_800936D4:
    // 0x800936D4: jal         0x80093310
    // 0x800936D8: nop

    Aquas_CsIntroGreatFox_Init(rdram, ctx);
        goto after_0;
    // 0x800936D8: nop

    after_0:
    // 0x800936DC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800936E0: sw          $zero, 0x7A80($at)
    MEM_W(0X7A80, ctx->r1) = 0;
    // 0x800936E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800936E8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800936EC: sb          $v0, 0x7AB0($at)
    MEM_B(0X7AB0, ctx->r1) = ctx->r2;
    // 0x800936F0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800936F4: sb          $v0, 0x7AC8($at)
    MEM_B(0X7AC8, ctx->r1) = ctx->r2;
    // 0x800936F8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800936FC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80093700: sw          $zero, 0x234($s3)
    MEM_W(0X234, ctx->r19) = 0;
    // 0x80093704: sw          $t4, 0x1D0($s3)
    MEM_W(0X1D0, ctx->r19) = ctx->r12;
    // 0x80093708: sw          $zero, 0x208($s3)
    MEM_W(0X208, ctx->r19) = 0;
    // 0x8009370C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80093710: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80093714: swc1        $f4, 0xD0($s3)
    MEM_W(0XD0, ctx->r19) = ctx->f4.u32l;
    // 0x80093718: sw          $t3, -0x7CC0($at)
    MEM_W(-0X7CC0, ctx->r1) = ctx->r11;
    // 0x8009371C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80093720: sw          $zero, -0x7CAC($at)
    MEM_W(-0X7CAC, ctx->r1) = 0;
    // 0x80093724: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80093728: sw          $zero, -0x7CB0($at)
    MEM_W(-0X7CB0, ctx->r1) = 0;
    // 0x8009372C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80093730: sw          $zero, -0x7CB8($at)
    MEM_W(-0X7CB8, ctx->r1) = 0;
    // 0x80093734: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80093738: sw          $zero, -0x7CA8($at)
    MEM_W(-0X7CA8, ctx->r1) = 0;
    // 0x8009373C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80093740: lwc1        $f6, -0x7FE8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7FE8);
    // 0x80093744: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80093748: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x8009374C: swc1        $f6, 0x7978($at)
    MEM_W(0X7978, ctx->r1) = ctx->f6.u32l;
    // 0x80093750: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80093754: swc1        $f6, 0x40($s3)
    MEM_W(0X40, ctx->r19) = ctx->f6.u32l;
    // 0x80093758: lwc1        $f8, -0x7FE4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X7FE4);
    // 0x8009375C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80093760: addiu       $t0, $t0, 0x16B0
    ctx->r8 = ADD32(ctx->r8, 0X16B0);
    // 0x80093764: swc1        $f8, 0x7980($at)
    MEM_W(0X7980, ctx->r1) = ctx->f8.u32l;
    // 0x80093768: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009376C: swc1        $f8, 0x44($s3)
    MEM_W(0X44, ctx->r19) = ctx->f8.u32l;
    // 0x80093770: lwc1        $f10, -0x7FE0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X7FE0);
    // 0x80093774: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80093778: swc1        $f10, 0x7988($at)
    MEM_W(0X7988, ctx->r1) = ctx->f10.u32l;
    // 0x8009377C: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80093780: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80093784: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80093788: swc1        $f10, 0x48($s3)
    MEM_W(0X48, ctx->r19) = ctx->f10.u32l;
    // 0x8009378C: swc1        $f16, 0x79A0($at)
    MEM_W(0X79A0, ctx->r1) = ctx->f16.u32l;
    // 0x80093790: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80093794: swc1        $f16, 0x4C($s3)
    MEM_W(0X4C, ctx->r19) = ctx->f16.u32l;
    // 0x80093798: lwc1        $f18, -0x7FDC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X7FDC);
    // 0x8009379C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800937A0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800937A4: swc1        $f18, 0x79B8($at)
    MEM_W(0X79B8, ctx->r1) = ctx->f18.u32l;
    // 0x800937A8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800937AC: swc1        $f18, 0x50($s3)
    MEM_W(0X50, ctx->r19) = ctx->f18.u32l;
    // 0x800937B0: lwc1        $f4, -0x7FD8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7FD8);
    // 0x800937B4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800937B8: swc1        $f4, 0x79C0($at)
    MEM_W(0X79C0, ctx->r1) = ctx->f4.u32l;
    // 0x800937BC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800937C0: swc1        $f4, 0x54($s3)
    MEM_W(0X54, ctx->r19) = ctx->f4.u32l;
    // 0x800937C4: lwc1        $f6, -0x7FD4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7FD4);
    // 0x800937C8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800937CC: swc1        $f6, 0x16A0($at)
    MEM_W(0X16A0, ctx->r1) = ctx->f6.u32l;
    // 0x800937D0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800937D4: lwc1        $f8, -0x7FD0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X7FD0);
    // 0x800937D8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800937DC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800937E0: swc1        $f8, 0x16A4($at)
    MEM_W(0X16A4, ctx->r1) = ctx->f8.u32l;
    // 0x800937E4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800937E8: swc1        $f10, 0x16A8($at)
    MEM_W(0X16A8, ctx->r1) = ctx->f10.u32l;
    // 0x800937EC: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x800937F0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800937F4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800937F8: swc1        $f16, 0x40D8($at)
    MEM_W(0X40D8, ctx->r1) = ctx->f16.u32l;
    // 0x800937FC: lui         $at, 0x4160
    ctx->r1 = S32(0X4160 << 16);
    // 0x80093800: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80093804: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80093808: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8009380C: swc1        $f18, 0x7A5C($at)
    MEM_W(0X7A5C, ctx->r1) = ctx->f18.u32l;
    // 0x80093810: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80093814: lwc1        $f4, -0x7FCC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7FCC);
    // 0x80093818: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8009381C: swc1        $f4, 0x7A48($at)
    MEM_W(0X7A48, ctx->r1) = ctx->f4.u32l;
    // 0x80093820: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80093824: sw          $zero, 0x7A28($at)
    MEM_W(0X7A28, ctx->r1) = 0;
    // 0x80093828: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8009382C: sw          $zero, 0x7A2C($at)
    MEM_W(0X7A2C, ctx->r1) = 0;
    // 0x80093830: swc1        $f6, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->f6.u32l;
    // 0x80093834: lwc1        $f8, 0x8($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X8);
    // 0x80093838: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8009383C: swc1        $f8, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f8.u32l;
    // 0x80093840: lwc1        $f10, 0x4($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X4);
    // 0x80093844: swc1        $f10, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f10.u32l;
    // 0x80093848: swc1        $f16, 0x7A64($at)
    MEM_W(0X7A64, ctx->r1) = ctx->f16.u32l;
L_8009384C:
    // 0x8009384C: lw          $v0, 0x208($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X208);
    // 0x80093850: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x80093854: bnel        $v0, $zero, L_80093A7C
    if (ctx->r2 != 0) {
        // 0x80093858: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_80093A7C;
    }
    goto skip_0;
    // 0x80093858: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    skip_0:
    // 0x8009385C: lw          $t9, 0x7A80($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7A80);
    // 0x80093860: slti        $at, $t9, 0xFA
    ctx->r1 = SIGNED(ctx->r25) < 0XFA ? 1 : 0;
    // 0x80093864: beql        $at, $zero, L_80093A7C
    if (ctx->r1 == 0) {
        // 0x80093868: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_80093A7C;
    }
    goto skip_1;
    // 0x80093868: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    skip_1:
    // 0x8009386C: jal         0x80004EB0
    // 0x80093870: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x80093870: nop

    after_1:
    // 0x80093874: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x80093878: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8009387C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80093880: lui         $s4, 0x8014
    ctx->r20 = S32(0X8014 << 16);
    // 0x80093884: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80093888: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8009388C: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x80093890: nop

    // 0x80093894: slti        $at, $v0, 0x20
    ctx->r1 = SIGNED(ctx->r2) < 0X20 ? 1 : 0;
    // 0x80093898: beq         $at, $zero, L_80093970
    if (ctx->r1 == 0) {
        // 0x8009389C: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_80093970;
    }
    // 0x8009389C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800938A0: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x800938A4: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x800938A8: addiu       $s4, $s4, -0x4438
    ctx->r20 = ADD32(ctx->r20, -0X4438);
L_800938AC:
    // 0x800938AC: sll         $t5, $s1, 2
    ctx->r13 = S32(ctx->r17 << 2);
    // 0x800938B0: subu        $t5, $t5, $s1
    ctx->r13 = SUB32(ctx->r13, ctx->r17);
    // 0x800938B4: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800938B8: addiu       $t7, $sp, 0x98
    ctx->r15 = ADD32(ctx->r29, 0X98);
    // 0x800938BC: addu        $s0, $t5, $t7
    ctx->r16 = ADD32(ctx->r13, ctx->r15);
    // 0x800938C0: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800938C4: jal         0x80004EB0
    // 0x800938C8: swc1        $f8, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f8.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_2;
    // 0x800938C8: swc1        $f8, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x800938CC: mul.s       $f10, $f0, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800938D0: lwc1        $f16, 0x4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800938D4: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x800938D8: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800938DC: lui         $a3, 0x8016
    ctx->r7 = S32(0X8016 << 16);
    // 0x800938E0: lw          $a3, 0x3FEC($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X3FEC);
    // 0x800938E4: lw          $a2, 0x3FE8($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X3FE8);
    // 0x800938E8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800938EC: lw          $a1, 0x3FE4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X3FE4);
    // 0x800938F0: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x800938F4: swc1        $f18, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f18.u32l;
    // 0x800938F8: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800938FC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80093900: jal         0x80005B00
    // 0x80093904: swc1        $f4, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f4.u32l;
    Matrix_Translate(rdram, ctx);
        goto after_3;
    // 0x80093904: swc1        $f4, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f4.u32l;
    after_3:
    // 0x80093908: lui         $a1, 0x3F06
    ctx->r5 = S32(0X3F06 << 16);
    // 0x8009390C: ori         $a1, $a1, 0xA92
    ctx->r5 = ctx->r5 | 0XA92;
    // 0x80093910: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x80093914: jal         0x80005E90
    // 0x80093918: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateY(rdram, ctx);
        goto after_4;
    // 0x80093918: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
    // 0x8009391C: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x80093920: addiu       $a1, $sp, 0x8C
    ctx->r5 = ADD32(ctx->r29, 0X8C);
    // 0x80093924: jal         0x80006970
    // 0x80093928: addiu       $a2, $sp, 0x80
    ctx->r6 = ADD32(ctx->r29, 0X80);
    Matrix_MultVec3f(rdram, ctx);
        goto after_5;
    // 0x80093928: addiu       $a2, $sp, 0x80
    ctx->r6 = ADD32(ctx->r29, 0X80);
    after_5:
    // 0x8009392C: lwc1        $f12, 0x80($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X80);
    // 0x80093930: lwc1        $f14, 0x84($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X84);
    // 0x80093934: lw          $a2, 0x88($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X88);
    // 0x80093938: jal         0x800933D8
    // 0x8009393C: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    Aquas_Effect363_Spawn(rdram, ctx);
        goto after_6;
    // 0x8009393C: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    after_6:
    // 0x80093940: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80093944: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80093948: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8009394C: bgez        $s1, L_80093960
    if (SIGNED(ctx->r17) >= 0) {
        // 0x80093950: andi        $t2, $s1, 0x1F
        ctx->r10 = ctx->r17 & 0X1F;
            goto L_80093960;
    }
    // 0x80093950: andi        $t2, $s1, 0x1F
    ctx->r10 = ctx->r17 & 0X1F;
    // 0x80093954: beq         $t2, $zero, L_80093960
    if (ctx->r10 == 0) {
        // 0x80093958: nop
    
            goto L_80093960;
    }
    // 0x80093958: nop

    // 0x8009395C: addiu       $t2, $t2, -0x20
    ctx->r10 = ADD32(ctx->r10, -0X20);
L_80093960:
    // 0x80093960: bne         $s2, $at, L_800938AC
    if (ctx->r18 != ctx->r1) {
        // 0x80093964: or          $s1, $t2, $zero
        ctx->r17 = ctx->r10 | 0;
            goto L_800938AC;
    }
    // 0x80093964: or          $s1, $t2, $zero
    ctx->r17 = ctx->r10 | 0;
    // 0x80093968: b           L_80093A48
    // 0x8009396C: nop

        goto L_80093A48;
    // 0x8009396C: nop

L_80093970:
    // 0x80093970: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x80093974: lui         $s4, 0x8014
    ctx->r20 = S32(0X8014 << 16);
    // 0x80093978: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8009397C: addiu       $s1, $v0, -0x20
    ctx->r17 = ADD32(ctx->r2, -0X20);
    // 0x80093980: addiu       $s4, $s4, -0x4438
    ctx->r20 = ADD32(ctx->r20, -0X4438);
    // 0x80093984: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_80093988:
    // 0x80093988: sll         $t8, $s1, 2
    ctx->r24 = S32(ctx->r17 << 2);
    // 0x8009398C: subu        $t8, $t8, $s1
    ctx->r24 = SUB32(ctx->r24, ctx->r17);
    // 0x80093990: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80093994: addiu       $t4, $sp, 0x98
    ctx->r12 = ADD32(ctx->r29, 0X98);
    // 0x80093998: addu        $s0, $t8, $t4
    ctx->r16 = ADD32(ctx->r24, ctx->r12);
    // 0x8009399C: lwc1        $f6, 0x0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800939A0: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x800939A4: jal         0x80004EB0
    // 0x800939A8: swc1        $f8, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f8.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_7;
    // 0x800939A8: swc1        $f8, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f8.u32l;
    after_7:
    // 0x800939AC: mul.s       $f10, $f0, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800939B0: lwc1        $f16, 0x4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800939B4: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x800939B8: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800939BC: lui         $a3, 0x8016
    ctx->r7 = S32(0X8016 << 16);
    // 0x800939C0: lw          $a3, 0x3FEC($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X3FEC);
    // 0x800939C4: lw          $a2, 0x3FE8($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X3FE8);
    // 0x800939C8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800939CC: lw          $a1, 0x3FE4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X3FE4);
    // 0x800939D0: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x800939D4: swc1        $f18, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f18.u32l;
    // 0x800939D8: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800939DC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800939E0: jal         0x80005B00
    // 0x800939E4: swc1        $f4, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f4.u32l;
    Matrix_Translate(rdram, ctx);
        goto after_8;
    // 0x800939E4: swc1        $f4, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f4.u32l;
    after_8:
    // 0x800939E8: lui         $a1, 0x3F06
    ctx->r5 = S32(0X3F06 << 16);
    // 0x800939EC: ori         $a1, $a1, 0xA92
    ctx->r5 = ctx->r5 | 0XA92;
    // 0x800939F0: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x800939F4: jal         0x80005E90
    // 0x800939F8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateY(rdram, ctx);
        goto after_9;
    // 0x800939F8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_9:
    // 0x800939FC: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x80093A00: addiu       $a1, $sp, 0x8C
    ctx->r5 = ADD32(ctx->r29, 0X8C);
    // 0x80093A04: jal         0x80006970
    // 0x80093A08: addiu       $a2, $sp, 0x80
    ctx->r6 = ADD32(ctx->r29, 0X80);
    Matrix_MultVec3f(rdram, ctx);
        goto after_10;
    // 0x80093A08: addiu       $a2, $sp, 0x80
    ctx->r6 = ADD32(ctx->r29, 0X80);
    after_10:
    // 0x80093A0C: lwc1        $f12, 0x80($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X80);
    // 0x80093A10: lwc1        $f14, 0x84($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X84);
    // 0x80093A14: lw          $a2, 0x88($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X88);
    // 0x80093A18: jal         0x800933D8
    // 0x80093A1C: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    Aquas_Effect363_Spawn(rdram, ctx);
        goto after_11;
    // 0x80093A1C: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    after_11:
    // 0x80093A20: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80093A24: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80093A28: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80093A2C: bgez        $s1, L_80093A40
    if (SIGNED(ctx->r17) >= 0) {
        // 0x80093A30: andi        $t3, $s1, 0x1F
        ctx->r11 = ctx->r17 & 0X1F;
            goto L_80093A40;
    }
    // 0x80093A30: andi        $t3, $s1, 0x1F
    ctx->r11 = ctx->r17 & 0X1F;
    // 0x80093A34: beq         $t3, $zero, L_80093A40
    if (ctx->r11 == 0) {
        // 0x80093A38: nop
    
            goto L_80093A40;
    }
    // 0x80093A38: nop

    // 0x80093A3C: addiu       $t3, $t3, -0x20
    ctx->r11 = ADD32(ctx->r11, -0X20);
L_80093A40:
    // 0x80093A40: bne         $s2, $at, L_80093988
    if (ctx->r18 != ctx->r1) {
        // 0x80093A44: or          $s1, $t3, $zero
        ctx->r17 = ctx->r11 | 0;
            goto L_80093988;
    }
    // 0x80093A44: or          $s1, $t3, $zero
    ctx->r17 = ctx->r11 | 0;
L_80093A48:
    // 0x80093A48: jal         0x80004EB0
    // 0x80093A4C: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_12;
    // 0x80093A4C: nop

    after_12:
    // 0x80093A50: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80093A54: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80093A58: nop

    // 0x80093A5C: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80093A60: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80093A64: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x80093A68: nop

    // 0x80093A6C: addiu       $t5, $t6, 0x1
    ctx->r13 = ADD32(ctx->r14, 0X1);
    // 0x80093A70: b           L_80093A88
    // 0x80093A74: sw          $t5, 0x208($s3)
    MEM_W(0X208, ctx->r19) = ctx->r13;
        goto L_80093A88;
    // 0x80093A74: sw          $t5, 0x208($s3)
    MEM_W(0X208, ctx->r19) = ctx->r13;
    // 0x80093A78: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
L_80093A7C:
    // 0x80093A7C: lui         $s4, 0x8014
    ctx->r20 = S32(0X8014 << 16);
    // 0x80093A80: addiu       $s4, $s4, -0x4438
    ctx->r20 = ADD32(ctx->r20, -0X4438);
    // 0x80093A84: sw          $t7, 0x208($s3)
    MEM_W(0X208, ctx->r19) = ctx->r15;
L_80093A88:
    // 0x80093A88: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x80093A8C: addiu       $t1, $t1, 0x7A10
    ctx->r9 = ADD32(ctx->r9, 0X7A10);
    // 0x80093A90: lw          $v1, 0x18($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X18);
    // 0x80093A94: addiu       $t8, $sp, 0x23C
    ctx->r24 = ADD32(ctx->r29, 0X23C);
    // 0x80093A98: addiu       $a0, $sp, 0x8C
    ctx->r4 = ADD32(ctx->r29, 0X8C);
    // 0x80093A9C: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x80093AA0: beq         $at, $zero, L_80093B8C
    if (ctx->r1 == 0) {
        // 0x80093AA4: sll         $t2, $v1, 2
        ctx->r10 = S32(ctx->r3 << 2);
            goto L_80093B8C;
    }
    // 0x80093AA4: sll         $t2, $v1, 2
    ctx->r10 = S32(ctx->r3 << 2);
    // 0x80093AA8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80093AAC: lwc1        $f0, 0x7A5C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X7A5C);
    // 0x80093AB0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80093AB4: lwc1        $f16, 0x7978($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7978);
    // 0x80093AB8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80093ABC: lwc1        $f18, 0x7980($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7980);
    // 0x80093AC0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80093AC4: lwc1        $f4, 0x7988($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7988);
    // 0x80093AC8: subu        $t2, $t2, $v1
    ctx->r10 = SUB32(ctx->r10, ctx->r3);
    // 0x80093ACC: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80093AD0: addu        $v0, $t2, $t8
    ctx->r2 = ADD32(ctx->r10, ctx->r24);
    // 0x80093AD4: swc1        $f16, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f16.u32l;
    // 0x80093AD8: swc1        $f18, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f18.u32l;
    // 0x80093ADC: swc1        $f4, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f4.u32l;
    // 0x80093AE0: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80093AE4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80093AE8: lwc1        $f16, -0x7FC8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X7FC8);
    // 0x80093AEC: swc1        $f6, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f6.u32l;
    // 0x80093AF0: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80093AF4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80093AF8: lwc1        $f18, -0x7FC4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X7FC4);
    // 0x80093AFC: swc1        $f8, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f8.u32l;
    // 0x80093B00: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80093B04: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80093B08: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80093B0C: addiu       $a2, $a2, 0x16A0
    ctx->r6 = ADD32(ctx->r6, 0X16A0);
    // 0x80093B10: addiu       $a1, $sp, 0x80
    ctx->r5 = ADD32(ctx->r29, 0X80);
    // 0x80093B14: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x80093B18: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x80093B1C: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x80093B20: jal         0x8009C124
    // 0x80093B24: swc1        $f10, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f10.u32l;
    Math_PursueVec3f(rdram, ctx);
        goto after_13;
    // 0x80093B24: swc1        $f10, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f10.u32l;
    after_13:
    // 0x80093B28: beq         $v0, $zero, L_80093B64
    if (ctx->r2 == 0) {
        // 0x80093B2C: lui         $t1, 0x8017
        ctx->r9 = S32(0X8017 << 16);
            goto L_80093B64;
    }
    // 0x80093B2C: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x80093B30: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x80093B34: lw          $t4, 0x7A28($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7A28);
    // 0x80093B38: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x80093B3C: bne         $t4, $zero, L_80093B58
    if (ctx->r12 != 0) {
        // 0x80093B40: or          $v1, $t4, $zero
        ctx->r3 = ctx->r12 | 0;
            goto L_80093B58;
    }
    // 0x80093B40: or          $v1, $t4, $zero
    ctx->r3 = ctx->r12 | 0;
    // 0x80093B44: lw          $t3, 0x7A2C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7A2C);
    // 0x80093B48: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80093B4C: or          $v1, $t4, $zero
    ctx->r3 = ctx->r12 | 0;
    // 0x80093B50: addiu       $t9, $t3, 0x1
    ctx->r25 = ADD32(ctx->r11, 0X1);
    // 0x80093B54: sw          $t9, 0x7A2C($at)
    MEM_W(0X7A2C, ctx->r1) = ctx->r25;
L_80093B58:
    // 0x80093B58: addiu       $t6, $v1, 0x1
    ctx->r14 = ADD32(ctx->r3, 0X1);
    // 0x80093B5C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80093B60: sw          $t6, 0x7A28($at)
    MEM_W(0X7A28, ctx->r1) = ctx->r14;
L_80093B64:
    // 0x80093B64: lwc1        $f4, 0x8C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x80093B68: lwc1        $f6, 0x90($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X90);
    // 0x80093B6C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80093B70: swc1        $f4, 0x7978($at)
    MEM_W(0X7978, ctx->r1) = ctx->f4.u32l;
    // 0x80093B74: lwc1        $f8, 0x94($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X94);
    // 0x80093B78: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80093B7C: swc1        $f6, 0x7980($at)
    MEM_W(0X7980, ctx->r1) = ctx->f6.u32l;
    // 0x80093B80: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80093B84: addiu       $t1, $t1, 0x7A10
    ctx->r9 = ADD32(ctx->r9, 0X7A10);
    // 0x80093B88: swc1        $f8, 0x7988($at)
    MEM_W(0X7988, ctx->r1) = ctx->f8.u32l;
L_80093B8C:
    // 0x80093B8C: lw          $v1, 0x1C($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X1C);
    // 0x80093B90: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80093B94: addiu       $t7, $sp, 0x218
    ctx->r15 = ADD32(ctx->r29, 0X218);
    // 0x80093B98: bne         $v1, $at, L_80093C6C
    if (ctx->r3 != ctx->r1) {
        // 0x80093B9C: sll         $t5, $v1, 2
        ctx->r13 = S32(ctx->r3 << 2);
            goto L_80093C6C;
    }
    // 0x80093B9C: sll         $t5, $v1, 2
    ctx->r13 = S32(ctx->r3 << 2);
    // 0x80093BA0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80093BA4: lwc1        $f0, 0x7A5C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X7A5C);
    // 0x80093BA8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80093BAC: lwc1        $f10, 0x79A0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X79A0);
    // 0x80093BB0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80093BB4: lwc1        $f16, 0x79B8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X79B8);
    // 0x80093BB8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80093BBC: lwc1        $f18, 0x79C0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X79C0);
    // 0x80093BC0: subu        $t5, $t5, $v1
    ctx->r13 = SUB32(ctx->r13, ctx->r3);
    // 0x80093BC4: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80093BC8: addu        $v0, $t5, $t7
    ctx->r2 = ADD32(ctx->r13, ctx->r15);
    // 0x80093BCC: swc1        $f10, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f10.u32l;
    // 0x80093BD0: swc1        $f16, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f16.u32l;
    // 0x80093BD4: swc1        $f18, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f18.u32l;
    // 0x80093BD8: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80093BDC: lw          $t2, 0x18($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X18);
    // 0x80093BE0: swc1        $f4, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f4.u32l;
    // 0x80093BE4: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80093BE8: slt         $at, $v1, $t2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80093BEC: swc1        $f6, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f6.u32l;
    // 0x80093BF0: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80093BF4: bne         $at, $zero, L_80093C48
    if (ctx->r1 != 0) {
        // 0x80093BF8: swc1        $f8, 0x88($sp)
        MEM_W(0X88, ctx->r29) = ctx->f8.u32l;
            goto L_80093C48;
    }
    // 0x80093BF8: swc1        $f8, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f8.u32l;
    // 0x80093BFC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80093C00: lwc1        $f10, -0x7FC0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X7FC0);
    // 0x80093C04: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80093C08: lwc1        $f16, -0x7FBC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X7FBC);
    // 0x80093C0C: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80093C10: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80093C14: addiu       $a2, $a2, 0x16B0
    ctx->r6 = ADD32(ctx->r6, 0X16B0);
    // 0x80093C18: addiu       $a0, $sp, 0x8C
    ctx->r4 = ADD32(ctx->r29, 0X8C);
    // 0x80093C1C: addiu       $a1, $sp, 0x80
    ctx->r5 = ADD32(ctx->r29, 0X80);
    // 0x80093C20: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x80093C24: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x80093C28: jal         0x8009C124
    // 0x80093C2C: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    Math_PursueVec3f(rdram, ctx);
        goto after_14;
    // 0x80093C2C: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    after_14:
    // 0x80093C30: beq         $v0, $zero, L_80093C48
    if (ctx->r2 == 0) {
        // 0x80093C34: lui         $t8, 0x8017
        ctx->r24 = S32(0X8017 << 16);
            goto L_80093C48;
    }
    // 0x80093C34: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x80093C38: lw          $t8, 0x7A2C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7A2C);
    // 0x80093C3C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80093C40: addiu       $t3, $t8, 0x1
    ctx->r11 = ADD32(ctx->r24, 0X1);
    // 0x80093C44: sw          $t3, 0x7A2C($at)
    MEM_W(0X7A2C, ctx->r1) = ctx->r11;
L_80093C48:
    // 0x80093C48: lwc1        $f18, 0x8C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x80093C4C: lwc1        $f4, 0x90($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X90);
    // 0x80093C50: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80093C54: swc1        $f18, 0x79A0($at)
    MEM_W(0X79A0, ctx->r1) = ctx->f18.u32l;
    // 0x80093C58: lwc1        $f6, 0x94($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X94);
    // 0x80093C5C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80093C60: swc1        $f4, 0x79B8($at)
    MEM_W(0X79B8, ctx->r1) = ctx->f4.u32l;
    // 0x80093C64: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80093C68: swc1        $f6, 0x79C0($at)
    MEM_W(0X79C0, ctx->r1) = ctx->f6.u32l;
L_80093C6C:
    // 0x80093C6C: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x80093C70: lw          $t9, 0x7A80($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7A80);
    // 0x80093C74: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80093C78: addiu       $v0, $v0, -0x7CAC
    ctx->r2 = ADD32(ctx->r2, -0X7CAC);
    // 0x80093C7C: slti        $at, $t9, 0x32
    ctx->r1 = SIGNED(ctx->r25) < 0X32 ? 1 : 0;
    // 0x80093C80: bne         $at, $zero, L_80094764
    if (ctx->r1 != 0) {
        // 0x80093C84: lui         $t4, 0x8018
        ctx->r12 = S32(0X8018 << 16);
            goto L_80094764;
    }
    // 0x80093C84: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80093C88: lw          $t4, -0x7CC0($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7CC0);
    // 0x80093C8C: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80093C90: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x80093C94: bne         $t0, $t4, L_80093CA4
    if (ctx->r8 != ctx->r12) {
        // 0x80093C98: addiu       $v1, $v1, -0x7CB0
        ctx->r3 = ADD32(ctx->r3, -0X7CB0);
            goto L_80093CA4;
    }
    // 0x80093C98: addiu       $v1, $v1, -0x7CB0
    ctx->r3 = ADD32(ctx->r3, -0X7CB0);
    // 0x80093C9C: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80093CA0: sw          $t6, 0x1D0($s3)
    MEM_W(0X1D0, ctx->r19) = ctx->r14;
L_80093CA4:
    // 0x80093CA4: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x80093CA8: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x80093CAC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80093CB0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80093CB4: sw          $t0, -0x7CB8($at)
    MEM_W(-0X7CB8, ctx->r1) = ctx->r8;
    // 0x80093CB8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80093CBC: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80093CC0: lui         $a2, 0x3D23
    ctx->r6 = S32(0X3D23 << 16);
    // 0x80093CC4: lui         $a3, 0x3D4C
    ctx->r7 = S32(0X3D4C << 16);
    // 0x80093CC8: sw          $t0, -0x7CA8($at)
    MEM_W(-0X7CA8, ctx->r1) = ctx->r8;
    // 0x80093CCC: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80093CD0: ori         $a2, $a2, 0xD70A
    ctx->r6 = ctx->r6 | 0XD70A;
    // 0x80093CD4: addiu       $a0, $a0, 0x7A64
    ctx->r4 = ADD32(ctx->r4, 0X7A64);
    // 0x80093CD8: lui         $a1, 0x4180
    ctx->r5 = S32(0X4180 << 16);
    // 0x80093CDC: jal         0x8009BC2C
    // 0x80093CE0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_15;
    // 0x80093CE0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_15:
    // 0x80093CE4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80093CE8: lwc1        $f10, 0x7A64($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7A64);
    // 0x80093CEC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80093CF0: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80093CF4: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
    // 0x80093CF8: b           L_80094764
    // 0x80093CFC: sw          $t8, -0x7CA4($at)
    MEM_W(-0X7CA4, ctx->r1) = ctx->r24;
        goto L_80094764;
    // 0x80093CFC: sw          $t8, -0x7CA4($at)
    MEM_W(-0X7CA4, ctx->r1) = ctx->r24;
L_80093D00:
    // 0x80093D00: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80093D04: sw          $zero, -0x7C80($at)
    MEM_W(-0X7C80, ctx->r1) = 0;
    // 0x80093D08: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80093D0C: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x80093D10: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80093D14: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x80093D18: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x80093D1C: addiu       $t0, $t0, 0x7A10
    ctx->r8 = ADD32(ctx->r8, 0X7A10);
    // 0x80093D20: addiu       $a1, $a1, -0x7AAC
    ctx->r5 = ADD32(ctx->r5, -0X7AAC);
    // 0x80093D24: addiu       $a0, $a0, -0x7AB0
    ctx->r4 = ADD32(ctx->r4, -0X7AB0);
    // 0x80093D28: addiu       $v1, $v1, -0x7AB4
    ctx->r3 = ADD32(ctx->r3, -0X7AB4);
    // 0x80093D2C: addiu       $v0, $v0, -0x7AB8
    ctx->r2 = ADD32(ctx->r2, -0X7AB8);
    // 0x80093D30: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x80093D34: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x80093D38: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x80093D3C: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x80093D40: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x80093D44: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x80093D48: addiu       $a3, $a3, -0x7AA4
    ctx->r7 = ADD32(ctx->r7, -0X7AA4);
    // 0x80093D4C: addiu       $a2, $a2, -0x7AA8
    ctx->r6 = ADD32(ctx->r6, -0X7AA8);
    // 0x80093D50: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x80093D54: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
    // 0x80093D58: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80093D5C: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x80093D60: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x80093D64: sw          $t4, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r12;
    // 0x80093D68: sw          $t6, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r14;
    // 0x80093D6C: addiu       $t2, $zero, 0x28
    ctx->r10 = ADD32(0, 0X28);
    // 0x80093D70: addiu       $t8, $zero, 0x64
    ctx->r24 = ADD32(0, 0X64);
    // 0x80093D74: addiu       $t3, $zero, 0x78
    ctx->r11 = ADD32(0, 0X78);
    // 0x80093D78: addiu       $t9, $zero, 0x14
    ctx->r25 = ADD32(0, 0X14);
    // 0x80093D7C: addiu       $t4, $zero, 0x1E
    ctx->r12 = ADD32(0, 0X1E);
    // 0x80093D80: addiu       $t6, $zero, 0x32
    ctx->r14 = ADD32(0, 0X32);
    // 0x80093D84: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x80093D88: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80093D8C: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x80093D90: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x80093D94: sw          $t4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r12;
    // 0x80093D98: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x80093D9C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80093DA0: sw          $t5, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r13;
    // 0x80093DA4: sw          $t7, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->r15;
    // 0x80093DA8: swc1        $f18, 0x7A50($at)
    MEM_W(0X7A50, ctx->r1) = ctx->f18.u32l;
    // 0x80093DAC: lui         $at, 0xC4C8
    ctx->r1 = S32(0XC4C8 << 16);
    // 0x80093DB0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80093DB4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80093DB8: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x80093DBC: swc1        $f4, 0x7A54($at)
    MEM_W(0X7A54, ctx->r1) = ctx->f4.u32l;
    // 0x80093DC0: lui         $at, 0x4402
    ctx->r1 = S32(0X4402 << 16);
    // 0x80093DC4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80093DC8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80093DCC: addiu       $t7, $zero, 0x3E8
    ctx->r15 = ADD32(0, 0X3E8);
    // 0x80093DD0: swc1        $f6, 0x7A58($at)
    MEM_W(0X7A58, ctx->r1) = ctx->f6.u32l;
    // 0x80093DD4: sw          $t5, 0x1D0($s3)
    MEM_W(0X1D0, ctx->r19) = ctx->r13;
    // 0x80093DD8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80093DDC: sb          $zero, 0x7AB0($at)
    MEM_B(0X7AB0, ctx->r1) = 0;
    // 0x80093DE0: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80093DE4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80093DE8: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80093DEC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80093DF0: sw          $t7, 0x1F8($s3)
    MEM_W(0X1F8, ctx->r19) = ctx->r15;
    // 0x80093DF4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80093DF8: swc1        $f8, 0x34($s3)
    MEM_W(0X34, ctx->r19) = ctx->f8.u32l;
    // 0x80093DFC: swc1        $f10, 0xE8($s3)
    MEM_W(0XE8, ctx->r19) = ctx->f10.u32l;
    // 0x80093E00: lwc1        $f16, -0x7FB8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X7FB8);
    // 0x80093E04: lui         $at, 0xC248
    ctx->r1 = S32(0XC248 << 16);
    // 0x80093E08: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80093E0C: lui         $at, 0x4496
    ctx->r1 = S32(0X4496 << 16);
    // 0x80093E10: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80093E14: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80093E18: swc1        $f16, 0x7C($s3)
    MEM_W(0X7C, ctx->r19) = ctx->f16.u32l;
    // 0x80093E1C: swc1        $f18, 0x74($s3)
    MEM_W(0X74, ctx->r19) = ctx->f18.u32l;
    // 0x80093E20: swc1        $f4, 0x78($s3)
    MEM_W(0X78, ctx->r19) = ctx->f4.u32l;
    // 0x80093E24: jal         0x801BDF14
    // 0x80093E28: sw          $zero, -0x7CA8($at)
    MEM_W(-0X7CA8, ctx->r1) = 0;
    Aquas_801BDF14(rdram, ctx);
        goto after_16;
    // 0x80093E28: sw          $zero, -0x7CA8($at)
    MEM_W(-0X7CA8, ctx->r1) = 0;
    after_16:
    // 0x80093E2C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80093E30: addiu       $a1, $zero, 0x2D
    ctx->r5 = ADD32(0, 0X2D);
    // 0x80093E34: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80093E38: jal         0x8001D444
    // 0x80093E3C: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    Audio_PlaySequence(rdram, ctx);
        goto after_17;
    // 0x80093E3C: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_17:
L_80093E40:
    // 0x80093E40: addiu       $t2, $zero, 0x10
    ctx->r10 = ADD32(0, 0X10);
    // 0x80093E44: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80093E48: sw          $t2, -0x7CA4($at)
    MEM_W(-0X7CA4, ctx->r1) = ctx->r10;
    // 0x80093E4C: lw          $v0, 0x1F8($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X1F8);
    // 0x80093E50: slti        $at, $v0, 0x307
    ctx->r1 = SIGNED(ctx->r2) < 0X307 ? 1 : 0;
    // 0x80093E54: bne         $at, $zero, L_80093FD4
    if (ctx->r1 != 0) {
        // 0x80093E58: lui         $at, 0x8017
        ctx->r1 = S32(0X8017 << 16);
            goto L_80093FD4;
    }
    // 0x80093E58: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80093E5C: lwc1        $f6, 0x7A58($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7A58);
    // 0x80093E60: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80093E64: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80093E68: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80093E6C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80093E70: c.le.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl <= ctx->f6.fl;
    // 0x80093E74: addiu       $a0, $a0, 0x7A58
    ctx->r4 = ADD32(ctx->r4, 0X7A58);
    // 0x80093E78: lui         $a1, 0xC348
    ctx->r5 = S32(0XC348 << 16);
    // 0x80093E7C: lui         $a2, 0x3D75
    ctx->r6 = S32(0X3D75 << 16);
    // 0x80093E80: bc1fl       L_80093EB8
    if (!c1cs) {
        // 0x80093E84: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_80093EB8;
    }
    goto skip_2;
    // 0x80093E84: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_2:
    // 0x80093E88: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80093E8C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80093E90: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80093E94: addiu       $a0, $a0, 0x7A58
    ctx->r4 = ADD32(ctx->r4, 0X7A58);
    // 0x80093E98: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80093E9C: lui         $a1, 0xC348
    ctx->r5 = S32(0XC348 << 16);
    // 0x80093EA0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80093EA4: jal         0x8009BC2C
    // 0x80093EA8: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_18;
    // 0x80093EA8: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_18:
    // 0x80093EAC: b           L_80093ECC
    // 0x80093EB0: nop

        goto L_80093ECC;
    // 0x80093EB0: nop

    // 0x80093EB4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_80093EB8:
    // 0x80093EB8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80093EBC: ori         $a2, $a2, 0xC28F
    ctx->r6 = ctx->r6 | 0XC28F;
    // 0x80093EC0: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80093EC4: jal         0x8009BC2C
    // 0x80093EC8: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_19;
    // 0x80093EC8: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_19:
L_80093ECC:
    // 0x80093ECC: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80093ED0: addiu       $v0, $v0, 0x7A48
    ctx->r2 = ADD32(ctx->r2, 0X7A48);
    // 0x80093ED4: lwc1        $f16, 0x8($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80093ED8: lwc1        $f18, 0xC($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80093EDC: lwc1        $f4, 0x10($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80093EE0: lui         $s4, 0x8014
    ctx->r20 = S32(0X8014 << 16);
    // 0x80093EE4: addiu       $s4, $s4, -0x4438
    ctx->r20 = ADD32(ctx->r20, -0X4438);
    // 0x80093EE8: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80093EEC: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80093EF0: lui         $a3, 0x8016
    ctx->r7 = S32(0X8016 << 16);
    // 0x80093EF4: lw          $a3, 0x3FEC($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X3FEC);
    // 0x80093EF8: lw          $a2, 0x3FE8($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X3FE8);
    // 0x80093EFC: lw          $a1, 0x3FE4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X3FE4);
    // 0x80093F00: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x80093F04: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80093F08: swc1        $f16, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f16.u32l;
    // 0x80093F0C: swc1        $f18, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f18.u32l;
    // 0x80093F10: jal         0x80005B00
    // 0x80093F14: swc1        $f4, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f4.u32l;
    Matrix_Translate(rdram, ctx);
        goto after_20;
    // 0x80093F14: swc1        $f4, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f4.u32l;
    after_20:
    // 0x80093F18: lui         $a1, 0x3F06
    ctx->r5 = S32(0X3F06 << 16);
    // 0x80093F1C: ori         $a1, $a1, 0xA92
    ctx->r5 = ctx->r5 | 0XA92;
    // 0x80093F20: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x80093F24: jal         0x80005E90
    // 0x80093F28: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateY(rdram, ctx);
        goto after_21;
    // 0x80093F28: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_21:
    // 0x80093F2C: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x80093F30: addiu       $a1, $sp, 0x8C
    ctx->r5 = ADD32(ctx->r29, 0X8C);
    // 0x80093F34: jal         0x80006970
    // 0x80093F38: addiu       $a2, $sp, 0x80
    ctx->r6 = ADD32(ctx->r29, 0X80);
    Matrix_MultVec3f(rdram, ctx);
        goto after_22;
    // 0x80093F38: addiu       $a2, $sp, 0x80
    ctx->r6 = ADD32(ctx->r29, 0X80);
    after_22:
    // 0x80093F3C: lwc1        $f6, 0x80($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X80);
    // 0x80093F40: lwc1        $f8, 0x84($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X84);
    // 0x80093F44: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80093F48: swc1        $f6, 0x7978($at)
    MEM_W(0X7978, ctx->r1) = ctx->f6.u32l;
    // 0x80093F4C: lwc1        $f10, 0x88($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X88);
    // 0x80093F50: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80093F54: swc1        $f8, 0x7980($at)
    MEM_W(0X7980, ctx->r1) = ctx->f8.u32l;
    // 0x80093F58: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80093F5C: swc1        $f10, 0x7988($at)
    MEM_W(0X7988, ctx->r1) = ctx->f10.u32l;
    // 0x80093F60: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80093F64: swc1        $f6, 0x79A0($at)
    MEM_W(0X79A0, ctx->r1) = ctx->f6.u32l;
    // 0x80093F68: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80093F6C: swc1        $f6, 0x4C($s3)
    MEM_W(0X4C, ctx->r19) = ctx->f6.u32l;
    // 0x80093F70: lwc1        $f16, 0x7980($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7980);
    // 0x80093F74: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80093F78: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80093F7C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80093F80: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80093F84: swc1        $f4, 0x79B8($at)
    MEM_W(0X79B8, ctx->r1) = ctx->f4.u32l;
    // 0x80093F88: swc1        $f4, 0x50($s3)
    MEM_W(0X50, ctx->r19) = ctx->f4.u32l;
    // 0x80093F8C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80093F90: lwc1        $f8, 0x7988($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7988);
    // 0x80093F94: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80093F98: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80093F9C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80093FA0: add.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80093FA4: swc1        $f6, 0x79C0($at)
    MEM_W(0X79C0, ctx->r1) = ctx->f6.u32l;
    // 0x80093FA8: swc1        $f6, 0x54($s3)
    MEM_W(0X54, ctx->r19) = ctx->f6.u32l;
    // 0x80093FAC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80093FB0: lwc1        $f16, 0x7978($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7978);
    // 0x80093FB4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80093FB8: lw          $v0, 0x1F8($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X1F8);
    // 0x80093FBC: swc1        $f16, 0x40($s3)
    MEM_W(0X40, ctx->r19) = ctx->f16.u32l;
    // 0x80093FC0: lwc1        $f18, 0x7980($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7980);
    // 0x80093FC4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80093FC8: swc1        $f18, 0x44($s3)
    MEM_W(0X44, ctx->r19) = ctx->f18.u32l;
    // 0x80093FCC: lwc1        $f4, 0x7988($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7988);
    // 0x80093FD0: swc1        $f4, 0x48($s3)
    MEM_W(0X48, ctx->r19) = ctx->f4.u32l;
L_80093FD4:
    // 0x80093FD4: lui         $s4, 0x8014
    ctx->r20 = S32(0X8014 << 16);
    // 0x80093FD8: addiu       $at, $zero, 0x306
    ctx->r1 = ADD32(0, 0X306);
    // 0x80093FDC: bne         $v0, $at, L_80094024
    if (ctx->r2 != ctx->r1) {
        // 0x80093FE0: addiu       $s4, $s4, -0x4438
        ctx->r20 = ADD32(ctx->r20, -0X4438);
            goto L_80094024;
    }
    // 0x80093FE0: addiu       $s4, $s4, -0x4438
    ctx->r20 = ADD32(ctx->r20, -0X4438);
    // 0x80093FE4: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80093FE8: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x80093FEC: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80093FF0: addiu       $t8, $t8, 0x5D3C
    ctx->r24 = ADD32(ctx->r24, 0X5D3C);
    // 0x80093FF4: lui         $a0, 0x103
    ctx->r4 = S32(0X103 << 16);
    // 0x80093FF8: ori         $a0, $a0, 0x8026
    ctx->r4 = ctx->r4 | 0X8026;
    // 0x80093FFC: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80094000: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80094004: addiu       $a1, $s3, 0x460
    ctx->r5 = ADD32(ctx->r19, 0X460);
    // 0x80094008: jal         0x80019218
    // 0x8009400C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Audio_PlaySfx(rdram, ctx);
        goto after_23;
    // 0x8009400C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_23:
    // 0x80094010: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80094014: addiu       $v1, $v1, 0x7A10
    ctx->r3 = ADD32(ctx->r3, 0X7A10);
    // 0x80094018: addiu       $t3, $zero, 0x28
    ctx->r11 = ADD32(0, 0X28);
    // 0x8009401C: sw          $t3, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r11;
    // 0x80094020: lw          $v0, 0x1F8($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X1F8);
L_80094024:
    // 0x80094024: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80094028: slti        $at, $v0, 0x307
    ctx->r1 = SIGNED(ctx->r2) < 0X307 ? 1 : 0;
    // 0x8009402C: beq         $at, $zero, L_80094308
    if (ctx->r1 == 0) {
        // 0x80094030: addiu       $v1, $v1, 0x7A10
        ctx->r3 = ADD32(ctx->r3, 0X7A10);
            goto L_80094308;
    }
    // 0x80094030: addiu       $v1, $v1, 0x7A10
    ctx->r3 = ADD32(ctx->r3, 0X7A10);
    // 0x80094034: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80094038: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8009403C: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x80094040: swc1        $f14, 0x7A48($at)
    MEM_W(0X7A48, ctx->r1) = ctx->f14.u32l;
    // 0x80094044: lw          $v0, 0x24($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X24);
    // 0x80094048: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
    // 0x8009404C: beq         $v0, $zero, L_800940B8
    if (ctx->r2 == 0) {
        // 0x80094050: addiu       $t4, $v0, -0x1
        ctx->r12 = ADD32(ctx->r2, -0X1);
            goto L_800940B8;
    }
    // 0x80094050: addiu       $t4, $v0, -0x1
    ctx->r12 = ADD32(ctx->r2, -0X1);
    // 0x80094054: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x80094058: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8009405C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80094060: cvt.s.w     $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    ctx->f20.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80094064: sw          $t4, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r12;
    // 0x80094068: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x8009406C: nop

    // 0x80094070: bc1f        L_8009407C
    if (!c1cs) {
        // 0x80094074: nop
    
            goto L_8009407C;
    }
    // 0x80094074: nop

    // 0x80094078: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
L_8009407C:
    // 0x8009407C: lw          $t6, 0x7DB0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7DB0);
    // 0x80094080: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x80094084: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80094088: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x8009408C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80094090: lwc1        $f4, -0x7FB4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7FB4);
    // 0x80094094: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80094098: mul.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x8009409C: nop

    // 0x800940A0: mul.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800940A4: jal         0x80023090
    // 0x800940A8: nop

    __sinf_recomp(rdram, ctx);
        goto after_24;
    // 0x800940A8: nop

    after_24:
    // 0x800940AC: mul.s       $f2, $f0, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800940B0: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x800940B4: nop

L_800940B8:
    // 0x800940B8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800940BC: lwc1        $f8, 0x7980($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7980);
    // 0x800940C0: lui         $a2, 0x3CA3
    ctx->r6 = S32(0X3CA3 << 16);
    // 0x800940C4: ori         $a2, $a2, 0xD70A
    ctx->r6 = ctx->r6 | 0XD70A;
    // 0x800940C8: add.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x800940CC: addiu       $a0, $s3, 0x18
    ctx->r4 = ADD32(ctx->r19, 0X18);
    // 0x800940D0: lui         $a1, 0xC496
    ctx->r5 = S32(0XC496 << 16);
    // 0x800940D4: lui         $a3, 0x4270
    ctx->r7 = S32(0X4270 << 16);
    // 0x800940D8: swc1        $f10, 0x44($s3)
    MEM_W(0X44, ctx->r19) = ctx->f10.u32l;
    // 0x800940DC: lwc1        $f6, 0x7980($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7980);
    // 0x800940E0: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800940E4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800940E8: nop

    // 0x800940EC: add.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x800940F0: swc1        $f18, 0x50($s3)
    MEM_W(0X50, ctx->r19) = ctx->f18.u32l;
    // 0x800940F4: jal         0x8009BC2C
    // 0x800940F8: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_25;
    // 0x800940F8: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    after_25:
    // 0x800940FC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80094100: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80094104: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x80094108: swc1        $f4, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f4.u32l;
    // 0x8009410C: swc1        $f8, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f8.u32l;
    // 0x80094110: lwc1        $f10, 0x18($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X18);
    // 0x80094114: swc1        $f10, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f10.u32l;
    // 0x80094118: lw          $a3, 0x7C($s3)
    ctx->r7 = MEM_W(ctx->r19, 0X7C);
    // 0x8009411C: lw          $a2, 0x78($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X78);
    // 0x80094120: lw          $a1, 0x74($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X74);
    // 0x80094124: jal         0x80005B00
    // 0x80094128: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    Matrix_Translate(rdram, ctx);
        goto after_26;
    // 0x80094128: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_26:
    // 0x8009412C: lui         $a1, 0x3F06
    ctx->r5 = S32(0X3F06 << 16);
    // 0x80094130: ori         $a1, $a1, 0xA92
    ctx->r5 = ctx->r5 | 0XA92;
    // 0x80094134: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x80094138: jal         0x80005E90
    // 0x8009413C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateY(rdram, ctx);
        goto after_27;
    // 0x8009413C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_27:
    // 0x80094140: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x80094144: addiu       $a1, $sp, 0x8C
    ctx->r5 = ADD32(ctx->r29, 0X8C);
    // 0x80094148: jal         0x80006970
    // 0x8009414C: addiu       $a2, $sp, 0x80
    ctx->r6 = ADD32(ctx->r29, 0X80);
    Matrix_MultVec3f(rdram, ctx);
        goto after_28;
    // 0x8009414C: addiu       $a2, $sp, 0x80
    ctx->r6 = ADD32(ctx->r29, 0X80);
    after_28:
    // 0x80094150: lwc1        $f6, 0x80($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X80);
    // 0x80094154: lw          $v0, 0x1F8($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X1F8);
    // 0x80094158: swc1        $f6, 0x74($s3)
    MEM_W(0X74, ctx->r19) = ctx->f6.u32l;
    // 0x8009415C: lwc1        $f16, 0x84($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X84);
    // 0x80094160: andi        $t5, $v0, 0x7
    ctx->r13 = ctx->r2 & 0X7;
    // 0x80094164: slti        $at, $v0, 0x2E5
    ctx->r1 = SIGNED(ctx->r2) < 0X2E5 ? 1 : 0;
    // 0x80094168: swc1        $f16, 0x78($s3)
    MEM_W(0X78, ctx->r19) = ctx->f16.u32l;
    // 0x8009416C: lwc1        $f18, 0x88($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X88);
    // 0x80094170: bne         $t5, $zero, L_800941A4
    if (ctx->r13 != 0) {
        // 0x80094174: swc1        $f18, 0x7C($s3)
        MEM_W(0X7C, ctx->r19) = ctx->f18.u32l;
            goto L_800941A4;
    }
    // 0x80094174: swc1        $f18, 0x7C($s3)
    MEM_W(0X7C, ctx->r19) = ctx->f18.u32l;
    // 0x80094178: bne         $at, $zero, L_800941A4
    if (ctx->r1 != 0) {
        // 0x8009417C: lui         $a3, 0x4120
        ctx->r7 = S32(0X4120 << 16);
            goto L_800941A4;
    }
    // 0x8009417C: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x80094180: lui         $at, 0x44C8
    ctx->r1 = S32(0X44C8 << 16);
    // 0x80094184: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80094188: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8009418C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80094190: lwc1        $f12, 0x40($s3)
    ctx->f12.u32l = MEM_W(ctx->r19, 0X40);
    // 0x80094194: lw          $a2, 0x48($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X48);
    // 0x80094198: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8009419C: jal         0x8007D9DC
    // 0x800941A0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Effect_Effect367_Spawn(rdram, ctx);
        goto after_29;
    // 0x800941A0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_29:
L_800941A4:
    // 0x800941A4: lui         $at, 0xC348
    ctx->r1 = S32(0XC348 << 16);
    // 0x800941A8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800941AC: lwc1        $f10, 0x18($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X18);
    // 0x800941B0: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800941B4: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x800941B8: nop

    // 0x800941BC: bc1f        L_80094230
    if (!c1cs) {
        // 0x800941C0: nop
    
            goto L_80094230;
    }
    // 0x800941C0: nop

    // 0x800941C4: lw          $v0, 0x7A30($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7A30);
    // 0x800941C8: slti        $at, $v0, 0x6
    ctx->r1 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    // 0x800941CC: beq         $at, $zero, L_80094230
    if (ctx->r1 == 0) {
        // 0x800941D0: slti        $at, $v0, 0x2
        ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
            goto L_80094230;
    }
    // 0x800941D0: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x800941D4: beq         $at, $zero, L_80094200
    if (ctx->r1 == 0) {
        // 0x800941D8: lui         $a3, 0x41A0
        ctx->r7 = S32(0X41A0 << 16);
            goto L_80094200;
    }
    // 0x800941D8: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    // 0x800941DC: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x800941E0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800941E4: lwc1        $f6, 0x78($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X78);
    // 0x800941E8: lwc1        $f12, 0x74($s3)
    ctx->f12.u32l = MEM_W(ctx->r19, 0X74);
    // 0x800941EC: lw          $a2, 0x7C($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X7C);
    // 0x800941F0: jal         0x800933D8
    // 0x800941F4: sub.s       $f14, $f6, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f16.fl;
    Aquas_Effect363_Spawn(rdram, ctx);
        goto after_30;
    // 0x800941F4: sub.s       $f14, $f6, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f16.fl;
    after_30:
    // 0x800941F8: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800941FC: lw          $v0, 0x7A30($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7A30);
L_80094200:
    // 0x80094200: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80094204: bne         $at, $zero, L_80094224
    if (ctx->r1 != 0) {
        // 0x80094208: lui         $a3, 0x4120
        ctx->r7 = S32(0X4120 << 16);
            goto L_80094224;
    }
    // 0x80094208: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x8009420C: lwc1        $f12, 0x74($s3)
    ctx->f12.u32l = MEM_W(ctx->r19, 0X74);
    // 0x80094210: lwc1        $f14, 0x78($s3)
    ctx->f14.u32l = MEM_W(ctx->r19, 0X78);
    // 0x80094214: jal         0x800933D8
    // 0x80094218: lw          $a2, 0x7C($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X7C);
    Aquas_Effect363_Spawn(rdram, ctx);
        goto after_31;
    // 0x80094218: lw          $a2, 0x7C($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X7C);
    after_31:
    // 0x8009421C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80094220: lw          $v0, 0x7A30($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7A30);
L_80094224:
    // 0x80094224: addiu       $t7, $v0, 0x1
    ctx->r15 = ADD32(ctx->r2, 0X1);
    // 0x80094228: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8009422C: sw          $t7, 0x7A30($at)
    MEM_W(0X7A30, ctx->r1) = ctx->r15;
L_80094230:
    // 0x80094230: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x80094234: lw          $t2, 0x7DB0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7DB0);
    // 0x80094238: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8009423C: lw          $v0, 0x1F8($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X1F8);
    // 0x80094240: div         $zero, $t2, $at
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r1)));
    // 0x80094244: mfhi        $t8
    ctx->r24 = hi;
    // 0x80094248: slti        $at, $v0, 0x2E5
    ctx->r1 = SIGNED(ctx->r2) < 0X2E5 ? 1 : 0;
    // 0x8009424C: bnel        $t8, $zero, L_8009430C
    if (ctx->r24 != 0) {
        // 0x80094250: slti        $at, $v0, 0x2E0
        ctx->r1 = SIGNED(ctx->r2) < 0X2E0 ? 1 : 0;
            goto L_8009430C;
    }
    goto skip_3;
    // 0x80094250: slti        $at, $v0, 0x2E0
    ctx->r1 = SIGNED(ctx->r2) < 0X2E0 ? 1 : 0;
    skip_3:
    // 0x80094254: beq         $at, $zero, L_80094308
    if (ctx->r1 == 0) {
        // 0x80094258: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_80094308;
    }
    // 0x80094258: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8009425C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80094260: lui         $s2, 0x800D
    ctx->r18 = S32(0X800D << 16);
    // 0x80094264: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x80094268: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8009426C: addiu       $s0, $s0, 0x22C4
    ctx->r16 = ADD32(ctx->r16, 0X22C4);
    // 0x80094270: addiu       $s2, $s2, 0x22C8
    ctx->r18 = ADD32(ctx->r18, 0X22C8);
L_80094274:
    // 0x80094274: jal         0x80004EB0
    // 0x80094278: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_32;
    // 0x80094278: nop

    after_32:
    // 0x8009427C: jal         0x80004EB0
    // 0x80094280: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_33;
    // 0x80094280: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    after_33:
    // 0x80094284: jal         0x80004EB0
    // 0x80094288: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_34;
    // 0x80094288: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    after_34:
    // 0x8009428C: lwc1        $f18, 0x50($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80094290: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80094294: lwc1        $f16, 0x54($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80094298: sub.s       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f20.fl;
    // 0x8009429C: lwc1        $f6, 0x40($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X40);
    // 0x800942A0: lui         $at, 0x4382
    ctx->r1 = S32(0X4382 << 16);
    // 0x800942A4: sub.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f20.fl;
    // 0x800942A8: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800942AC: lwc1        $f4, 0x0($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X0);
    // 0x800942B0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x800942B4: mul.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800942B8: sub.s       $f18, $f0, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x800942BC: add.s       $f12, $f10, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800942C0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800942C4: lwc1        $f10, 0x44($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X44);
    // 0x800942C8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800942CC: lwc1        $f4, 0x22CC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X22CC);
    // 0x800942D0: add.s       $f16, $f10, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800942D4: lwc1        $f6, 0x48($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X48);
    // 0x800942D8: mul.s       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800942DC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800942E0: add.s       $f14, $f8, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x800942E4: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800942E8: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x800942EC: jal         0x801AC8A8
    // 0x800942F0: nop

    Aquas_Bubble_Spawn(rdram, ctx);
        goto after_35;
    // 0x800942F0: nop

    after_35:
    // 0x800942F4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800942F8: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x800942FC: bne         $s1, $at, L_80094274
    if (ctx->r17 != ctx->r1) {
        // 0x80094300: nop
    
            goto L_80094274;
    }
    // 0x80094300: nop

    // 0x80094304: lw          $v0, 0x1F8($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X1F8);
L_80094308:
    // 0x80094308: slti        $at, $v0, 0x2E0
    ctx->r1 = SIGNED(ctx->r2) < 0X2E0 ? 1 : 0;
L_8009430C:
    // 0x8009430C: beq         $at, $zero, L_80094764
    if (ctx->r1 == 0) {
        // 0x80094310: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80094764;
    }
    // 0x80094310: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80094314: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x80094318: sw          $t3, 0x1D0($s3)
    MEM_W(0X1D0, ctx->r19) = ctx->r11;
    // 0x8009431C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80094320: sb          $v0, 0x7AC8($at)
    MEM_B(0X7AC8, ctx->r1) = ctx->r2;
    // 0x80094324: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x80094328: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8009432C: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80094330: addiu       $a0, $a0, -0x7CB0
    ctx->r4 = ADD32(ctx->r4, -0X7CB0);
    // 0x80094334: addiu       $v1, $v1, -0x7CAC
    ctx->r3 = ADD32(ctx->r3, -0X7CAC);
    // 0x80094338: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // 0x8009433C: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
    // 0x80094340: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80094344: sw          $a1, -0x7CB8($at)
    MEM_W(-0X7CB8, ctx->r1) = ctx->r5;
    // 0x80094348: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8009434C: b           L_80094764
    // 0x80094350: sw          $a1, -0x7CA8($at)
    MEM_W(-0X7CA8, ctx->r1) = ctx->r5;
        goto L_80094764;
    // 0x80094350: sw          $a1, -0x7CA8($at)
    MEM_W(-0X7CA8, ctx->r1) = ctx->r5;
L_80094354:
    // 0x80094354: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80094358: lw          $t6, -0x7CC0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7CC0);
    // 0x8009435C: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80094360: lui         $s4, 0x8014
    ctx->r20 = S32(0X8014 << 16);
    // 0x80094364: bne         $t6, $at, L_80094370
    if (ctx->r14 != ctx->r1) {
        // 0x80094368: addiu       $t5, $zero, 0x5
        ctx->r13 = ADD32(0, 0X5);
            goto L_80094370;
    }
    // 0x80094368: addiu       $t5, $zero, 0x5
    ctx->r13 = ADD32(0, 0X5);
    // 0x8009436C: sw          $t5, 0x1D0($s3)
    MEM_W(0X1D0, ctx->r19) = ctx->r13;
L_80094370:
    // 0x80094370: b           L_80094764
    // 0x80094374: addiu       $s4, $s4, -0x4438
    ctx->r20 = ADD32(ctx->r20, -0X4438);
        goto L_80094764;
    // 0x80094374: addiu       $s4, $s4, -0x4438
    ctx->r20 = ADD32(ctx->r20, -0X4438);
L_80094378:
    // 0x80094378: lui         $at, 0x43AF
    ctx->r1 = S32(0X43AF << 16);
    // 0x8009437C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80094380: lui         $at, 0x4482
    ctx->r1 = S32(0X4482 << 16);
    // 0x80094384: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80094388: lwc1        $f0, 0xA0($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0XA0);
    // 0x8009438C: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80094390: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80094394: div.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80094398: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8009439C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800943A0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800943A4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800943A8: swc1        $f2, 0x78($s3)
    MEM_W(0X78, ctx->r19) = ctx->f2.u32l;
    // 0x800943AC: swc1        $f12, 0x74($s3)
    MEM_W(0X74, ctx->r19) = ctx->f12.u32l;
    // 0x800943B0: swc1        $f12, 0x7C($s3)
    MEM_W(0X7C, ctx->r19) = ctx->f12.u32l;
    // 0x800943B4: swc1        $f12, 0x40($s3)
    MEM_W(0X40, ctx->r19) = ctx->f12.u32l;
    // 0x800943B8: swc1        $f12, 0x4C($s3)
    MEM_W(0X4C, ctx->r19) = ctx->f12.u32l;
    // 0x800943BC: lwc1        $f8, 0x60($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X60);
    // 0x800943C0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800943C4: addiu       $t2, $zero, 0x6
    ctx->r10 = ADD32(0, 0X6);
    // 0x800943C8: addiu       $t8, $zero, 0x3E8
    ctx->r24 = ADD32(0, 0X3E8);
    // 0x800943CC: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800943D0: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x800943D4: addiu       $a1, $a1, 0x40E0
    ctx->r5 = ADD32(ctx->r5, 0X40E0);
    // 0x800943D8: addiu       $a0, $a0, 0x3FE0
    ctx->r4 = ADD32(ctx->r4, 0X3FE0);
    // 0x800943DC: mul.s       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x800943E0: sub.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x800943E4: mul.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800943E8: lwc1        $f16, 0x7C($s3)
    ctx->f16.u32l = MEM_W(ctx->r19, 0X7C);
    // 0x800943EC: swc1        $f6, 0x44($s3)
    MEM_W(0X44, ctx->r19) = ctx->f6.u32l;
    // 0x800943F0: lwc1        $f4, -0x7FB0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7FB0);
    // 0x800943F4: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x800943F8: swc1        $f12, 0x34($s3)
    MEM_W(0X34, ctx->r19) = ctx->f12.u32l;
    // 0x800943FC: div.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80094400: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80094404: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80094408: mul.s       $f6, $f2, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x8009440C: add.s       $f10, $f16, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x80094410: swc1        $f10, 0x7C($s3)
    MEM_W(0X7C, ctx->r19) = ctx->f10.u32l;
    // 0x80094414: add.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x80094418: swc1        $f8, 0x50($s3)
    MEM_W(0X50, ctx->r19) = ctx->f8.u32l;
    // 0x8009441C: lwc1        $f6, -0x7FAC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7FAC);
    // 0x80094420: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80094424: swc1        $f6, 0x7A48($at)
    MEM_W(0X7A48, ctx->r1) = ctx->f6.u32l;
    // 0x80094428: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8009442C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80094430: sw          $t7, 0x234($s3)
    MEM_W(0X234, ctx->r19) = ctx->r15;
    // 0x80094434: sw          $t2, 0x1D0($s3)
    MEM_W(0X1D0, ctx->r19) = ctx->r10;
    // 0x80094438: sw          $t8, 0x1F8($s3)
    MEM_W(0X1F8, ctx->r19) = ctx->r24;
    // 0x8009443C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80094440: swc1        $f12, 0xE8($s3)
    MEM_W(0XE8, ctx->r19) = ctx->f12.u32l;
    // 0x80094444: swc1        $f18, 0xD0($s3)
    MEM_W(0XD0, ctx->r19) = ctx->f18.u32l;
    // 0x80094448: sb          $zero, 0x7AC8($at)
    MEM_B(0X7AC8, ctx->r1) = 0;
    // 0x8009444C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80094450: jal         0x80060FBC
    // 0x80094454: sw          $zero, -0x7CA8($at)
    MEM_W(-0X7CA8, ctx->r1) = 0;
    Object_Kill(rdram, ctx);
        goto after_36;
    // 0x80094454: sw          $zero, -0x7CA8($at)
    MEM_W(-0X7CA8, ctx->r1) = 0;
    after_36:
    // 0x80094458: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
    // 0x8009445C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80094460: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80094464: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80094468: swc1        $f8, 0x7988($at)
    MEM_W(0X7988, ctx->r1) = ctx->f8.u32l;
    // 0x8009446C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80094470: swc1        $f8, 0x48($s3)
    MEM_W(0X48, ctx->r19) = ctx->f8.u32l;
    // 0x80094474: swc1        $f16, 0x79C0($at)
    MEM_W(0X79C0, ctx->r1) = ctx->f16.u32l;
    // 0x80094478: swc1        $f16, 0x54($s3)
    MEM_W(0X54, ctx->r19) = ctx->f16.u32l;
L_8009447C:
    // 0x8009447C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80094480: lwc1        $f10, -0x7FA8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X7FA8);
    // 0x80094484: lwc1        $f4, 0xF4($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0XF4);
    // 0x80094488: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009448C: lwc1        $f18, -0x7FA4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X7FA4);
    // 0x80094490: mul.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x80094494: nop

    // 0x80094498: mul.s       $f12, $f6, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x8009449C: jal         0x80023090
    // 0x800944A0: nop

    __sinf_recomp(rdram, ctx);
        goto after_37;
    // 0x800944A0: nop

    after_37:
    // 0x800944A4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800944A8: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x800944AC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800944B0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800944B4: mul.s       $f8, $f0, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800944B8: lwc1        $f16, 0x88($s3)
    ctx->f16.u32l = MEM_W(ctx->r19, 0X88);
    // 0x800944BC: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x800944C0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800944C4: lwc1        $f6, 0xF4($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0XF4);
    // 0x800944C8: add.s       $f10, $f16, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x800944CC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800944D0: swc1        $f8, 0x60($s3)
    MEM_W(0X60, ctx->r19) = ctx->f8.u32l;
    // 0x800944D4: add.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x800944D8: swc1        $f10, 0x88($s3)
    MEM_W(0X88, ctx->r19) = ctx->f10.u32l;
    // 0x800944DC: lwc1        $f16, 0x88($s3)
    ctx->f16.u32l = MEM_W(ctx->r19, 0X88);
    // 0x800944E0: swc1        $f8, 0xF4($s3)
    MEM_W(0XF4, ctx->r19) = ctx->f8.u32l;
    // 0x800944E4: lwc1        $f4, -0x7FA0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7FA0);
    // 0x800944E8: mul.s       $f12, $f16, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x800944EC: jal         0x80023090
    // 0x800944F0: nop

    __sinf_recomp(rdram, ctx);
        goto after_38;
    // 0x800944F0: nop

    after_38:
    // 0x800944F4: neg.s       $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = -ctx->f0.fl;
    // 0x800944F8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800944FC: mul.s       $f6, $f10, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x80094500: lwc1        $f18, 0xF4($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0XF4);
    // 0x80094504: swc1        $f6, 0x80($s3)
    MEM_W(0X80, ctx->r19) = ctx->f6.u32l;
    // 0x80094508: lwc1        $f8, -0x7F9C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X7F9C);
    // 0x8009450C: mul.s       $f12, $f18, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x80094510: jal         0x80023090
    // 0x80094514: nop

    __sinf_recomp(rdram, ctx);
        goto after_39;
    // 0x80094514: nop

    after_39:
    // 0x80094518: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x8009451C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80094520: lwc1        $f6, 0x9C($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X9C);
    // 0x80094524: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80094528: lwc1        $f12, -0x7F98($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X7F98);
    // 0x8009452C: div.s       $f18, $f2, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = DIV_S(ctx->f2.fl, ctx->f6.fl);
    // 0x80094530: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80094534: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80094538: lwc1        $f10, 0x74($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X74);
    // 0x8009453C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80094540: mul.s       $f4, $f0, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80094544: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80094548: addiu       $v0, $v0, 0x7980
    ctx->r2 = ADD32(ctx->r2, 0X7980);
    // 0x8009454C: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80094550: addiu       $v1, $v1, 0x79B8
    ctx->r3 = ADD32(ctx->r3, 0X79B8);
    // 0x80094554: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x80094558: addiu       $a0, $s3, 0x7C
    ctx->r4 = ADD32(ctx->r19, 0X7C);
    // 0x8009455C: swc1        $f4, 0xF0($s3)
    MEM_W(0XF0, ctx->r19) = ctx->f4.u32l;
    // 0x80094560: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80094564: lui         $a3, 0x4220
    ctx->r7 = S32(0X4220 << 16);
    // 0x80094568: mul.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8009456C: swc1        $f8, 0x7978($at)
    MEM_W(0X7978, ctx->r1) = ctx->f8.u32l;
    // 0x80094570: lui         $at, 0x4439
    ctx->r1 = S32(0X4439 << 16);
    // 0x80094574: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80094578: lwc1        $f4, 0xA0($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0XA0);
    // 0x8009457C: lwc1        $f10, 0x78($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X78);
    // 0x80094580: lui         $at, 0xC248
    ctx->r1 = S32(0XC248 << 16);
    // 0x80094584: div.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f16.fl, ctx->f4.fl);
    // 0x80094588: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8009458C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80094590: mul.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x80094594: swc1        $f18, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f18.u32l;
    // 0x80094598: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8009459C: sub.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x800945A0: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x800945A4: lwc1        $f6, 0x9C($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X9C);
    // 0x800945A8: lwc1        $f10, 0x74($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X74);
    // 0x800945AC: div.s       $f18, $f2, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = DIV_S(ctx->f2.fl, ctx->f6.fl);
    // 0x800945B0: mul.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800945B4: swc1        $f8, 0x79A0($at)
    MEM_W(0X79A0, ctx->r1) = ctx->f8.u32l;
    // 0x800945B8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800945BC: lwc1        $f16, -0x7F94($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X7F94);
    // 0x800945C0: lwc1        $f4, 0xA0($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0XA0);
    // 0x800945C4: lwc1        $f10, 0x78($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X78);
    // 0x800945C8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800945CC: div.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f16.fl, ctx->f4.fl);
    // 0x800945D0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800945D4: mul.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x800945D8: swc1        $f18, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f18.u32l;
    // 0x800945DC: lwc1        $f8, 0x60($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X60);
    // 0x800945E0: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800945E4: swc1        $f12, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f12.u32l;
    // 0x800945E8: mul.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800945EC: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800945F0: jal         0x8009BC2C
    // 0x800945F4: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_40;
    // 0x800945F4: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
    after_40:
    // 0x800945F8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800945FC: lwc1        $f18, -0x7F90($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X7F90);
    // 0x80094600: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80094604: swc1        $f18, 0x7A48($at)
    MEM_W(0X7A48, ctx->r1) = ctx->f18.u32l;
    // 0x80094608: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x8009460C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80094610: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80094614: swc1        $f8, 0x7988($at)
    MEM_W(0X7988, ctx->r1) = ctx->f8.u32l;
    // 0x80094618: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8009461C: lwc1        $f16, 0x7D20($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x80094620: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80094624: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80094628: lwc1        $f6, 0x7C($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X7C);
    // 0x8009462C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80094630: sub.s       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x80094634: add.s       $f18, $f6, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80094638: swc1        $f18, 0x79C0($at)
    MEM_W(0X79C0, ctx->r1) = ctx->f18.u32l;
    // 0x8009463C: lw          $v0, 0x1F8($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X1F8);
    // 0x80094640: andi        $t3, $v0, 0x1
    ctx->r11 = ctx->r2 & 0X1;
    // 0x80094644: bne         $t3, $zero, L_8009467C
    if (ctx->r11 != 0) {
        // 0x80094648: slti        $at, $v0, 0x3C3
        ctx->r1 = SIGNED(ctx->r2) < 0X3C3 ? 1 : 0;
            goto L_8009467C;
    }
    // 0x80094648: slti        $at, $v0, 0x3C3
    ctx->r1 = SIGNED(ctx->r2) < 0X3C3 ? 1 : 0;
    // 0x8009464C: bne         $at, $zero, L_8009467C
    if (ctx->r1 != 0) {
        // 0x80094650: lui         $at, 0x4248
        ctx->r1 = S32(0X4248 << 16);
            goto L_8009467C;
    }
    // 0x80094650: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80094654: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80094658: lwc1        $f8, 0x7C($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X7C);
    // 0x8009465C: lwc1        $f12, 0x74($s3)
    ctx->f12.u32l = MEM_W(ctx->r19, 0X74);
    // 0x80094660: lwc1        $f14, 0x78($s3)
    ctx->f14.u32l = MEM_W(ctx->r19, 0X78);
    // 0x80094664: add.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x80094668: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    // 0x8009466C: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80094670: jal         0x800933D8
    // 0x80094674: nop

    Aquas_Effect363_Spawn(rdram, ctx);
        goto after_41;
    // 0x80094674: nop

    after_41:
    // 0x80094678: lw          $v0, 0x1F8($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X1F8);
L_8009467C:
    // 0x8009467C: slti        $at, $v0, 0x385
    ctx->r1 = SIGNED(ctx->r2) < 0X385 ? 1 : 0;
    // 0x80094680: beq         $at, $zero, L_800946D8
    if (ctx->r1 == 0) {
        // 0x80094684: addiu       $t9, $zero, 0x32
        ctx->r25 = ADD32(0, 0X32);
            goto L_800946D8;
    }
    // 0x80094684: addiu       $t9, $zero, 0x32
    ctx->r25 = ADD32(0, 0X32);
    // 0x80094688: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8009468C: sw          $t9, 0x7838($at)
    MEM_W(0X7838, ctx->r1) = ctx->r25;
    // 0x80094690: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x80094694: sw          $t4, 0x1C8($s3)
    MEM_W(0X1C8, ctx->r19) = ctx->r12;
    // 0x80094698: sw          $zero, 0x1D0($s3)
    MEM_W(0X1D0, ctx->r19) = 0;
    // 0x8009469C: sw          $zero, 0x1F8($s3)
    MEM_W(0X1F8, ctx->r19) = 0;
    // 0x800946A0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800946A4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800946A8: lui         $a0, 0x1032
    ctx->r4 = S32(0X1032 << 16);
    // 0x800946AC: sw          $t6, -0x7B78($at)
    MEM_W(-0X7B78, ctx->r1) = ctx->r14;
    // 0x800946B0: jal         0x800182F4
    // 0x800946B4: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_42;
    // 0x800946B4: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    after_42:
    // 0x800946B8: lui         $a0, 0x1132
    ctx->r4 = S32(0X1132 << 16);
    // 0x800946BC: jal         0x800182F4
    // 0x800946C0: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_43;
    // 0x800946C0: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    after_43:
    // 0x800946C4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800946C8: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    // 0x800946CC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800946D0: jal         0x8001D444
    // 0x800946D4: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    Audio_PlaySequence(rdram, ctx);
        goto after_44;
    // 0x800946D4: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_44:
L_800946D8:
    // 0x800946D8: jal         0x80004EB0
    // 0x800946DC: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_45;
    // 0x800946DC: nop

    after_45:
    // 0x800946E0: jal         0x80004EB0
    // 0x800946E4: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_46;
    // 0x800946E4: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    after_46:
    // 0x800946E8: jal         0x80004EB0
    // 0x800946EC: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_47;
    // 0x800946EC: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    after_47:
    // 0x800946F0: lwc1        $f6, 0x50($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800946F4: lwc1        $f16, 0x54($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800946F8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800946FC: sub.s       $f4, $f6, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f20.fl;
    // 0x80094700: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80094704: lwc1        $f8, 0x74($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X74);
    // 0x80094708: sub.s       $f10, $f16, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f16.fl - ctx->f20.fl;
    // 0x8009470C: mul.s       $f18, $f4, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80094710: lwc1        $f4, 0x78($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X78);
    // 0x80094714: lui         $at, 0x4282
    ctx->r1 = S32(0X4282 << 16);
    // 0x80094718: mul.s       $f6, $f10, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8009471C: lui         $a3, 0x3ECC
    ctx->r7 = S32(0X3ECC << 16);
    // 0x80094720: sub.s       $f10, $f0, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x80094724: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80094728: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x8009472C: add.s       $f12, $f18, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x80094730: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80094734: lwc1        $f18, 0x7C($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0X7C);
    // 0x80094738: add.s       $f14, $f6, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8009473C: mul.s       $f6, $f10, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80094740: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80094744: sub.s       $f16, $f18, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x80094748: add.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x8009474C: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80094750: jal         0x801AC8A8
    // 0x80094754: nop

    Aquas_Bubble_Spawn(rdram, ctx);
        goto after_48;
    // 0x80094754: nop

    after_48:
    // 0x80094758: lui         $s4, 0x8014
    ctx->r20 = S32(0X8014 << 16);
    // 0x8009475C: b           L_80094764
    // 0x80094760: addiu       $s4, $s4, -0x4438
    ctx->r20 = ADD32(ctx->r20, -0X4438);
        goto L_80094764;
    // 0x80094760: addiu       $s4, $s4, -0x4438
    ctx->r20 = ADD32(ctx->r20, -0X4438);
L_80094764:
    // 0x80094764: lwc1        $f18, 0xE8($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0XE8);
    // 0x80094768: lwc1        $f8, 0x114($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X114);
    // 0x8009476C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80094770: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80094774: add.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x80094778: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009477C: lwc1        $f4, -0x7F8C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7F8C);
    // 0x80094780: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x80094784: add.s       $f16, $f10, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80094788: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8009478C: mul.s       $f18, $f16, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x80094790: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80094794: jal         0x80005E90
    // 0x80094798: nop

    Matrix_RotateY(rdram, ctx);
        goto after_49;
    // 0x80094798: nop

    after_49:
    // 0x8009479C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800947A0: lwc1        $f10, -0x7F88($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X7F88);
    // 0x800947A4: lwc1        $f8, 0xE4($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0XE4);
    // 0x800947A8: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x800947AC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800947B0: mul.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800947B4: neg.s       $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = -ctx->f6.fl;
    // 0x800947B8: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x800947BC: jal         0x80005D44
    // 0x800947C0: nop

    Matrix_RotateX(rdram, ctx);
        goto after_50;
    // 0x800947C0: nop

    after_50:
    // 0x800947C4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800947C8: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x800947CC: addiu       $a1, $sp, 0x8C
    ctx->r5 = ADD32(ctx->r29, 0X8C);
    // 0x800947D0: swc1        $f0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f0.u32l;
    // 0x800947D4: swc1        $f0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f0.u32l;
    // 0x800947D8: lwc1        $f4, 0xD0($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0XD0);
    // 0x800947DC: addiu       $a2, $sp, 0x80
    ctx->r6 = ADD32(ctx->r29, 0X80);
    // 0x800947E0: jal         0x80006A20
    // 0x800947E4: swc1        $f4, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f4.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_51;
    // 0x800947E4: swc1        $f4, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f4.u32l;
    after_51:
    // 0x800947E8: lwc1        $f18, 0x80($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800947EC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800947F0: lwc1        $f20, -0x7F84($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X7F84);
    // 0x800947F4: swc1        $f18, 0xC0($s3)
    MEM_W(0XC0, ctx->r19) = ctx->f18.u32l;
    // 0x800947F8: lwc1        $f8, 0x84($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X84);
    // 0x800947FC: lwc1        $f16, 0xC0($s3)
    ctx->f16.u32l = MEM_W(ctx->r19, 0XC0);
    // 0x80094800: lwc1        $f6, 0x74($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X74);
    // 0x80094804: swc1        $f8, 0xC4($s3)
    MEM_W(0XC4, ctx->r19) = ctx->f8.u32l;
    // 0x80094808: lwc1        $f10, 0x88($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X88);
    // 0x8009480C: lwc1        $f8, 0xC4($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0XC4);
    // 0x80094810: lwc1        $f18, 0x78($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0X78);
    // 0x80094814: swc1        $f10, 0xC8($s3)
    MEM_W(0XC8, ctx->r19) = ctx->f10.u32l;
    // 0x80094818: add.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x8009481C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80094820: addiu       $v0, $v0, 0x7CE8
    ctx->r2 = ADD32(ctx->r2, 0X7CE8);
    // 0x80094824: add.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x80094828: swc1        $f4, 0x74($s3)
    MEM_W(0X74, ctx->r19) = ctx->f4.u32l;
    // 0x8009482C: lwc1        $f16, 0xC8($s3)
    ctx->f16.u32l = MEM_W(ctx->r19, 0XC8);
    // 0x80094830: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80094834: swc1        $f10, 0x78($s3)
    MEM_W(0X78, ctx->r19) = ctx->f10.u32l;
    // 0x80094838: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8009483C: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x80094840: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80094844: sub.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f16.fl;
    // 0x80094848: addiu       $a0, $s3, 0x40
    ctx->r4 = ADD32(ctx->r19, 0X40);
    // 0x8009484C: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x80094850: lwc1        $f8, 0x12C($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X12C);
    // 0x80094854: lwc1        $f18, 0xEC($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0XEC);
    // 0x80094858: lwc1        $f6, 0x130($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X130);
    // 0x8009485C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80094860: add.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x80094864: add.s       $f16, $f10, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80094868: swc1        $f16, 0xF8($s3)
    MEM_W(0XF8, ctx->r19) = ctx->f16.u32l;
    // 0x8009486C: lw          $a2, 0x7A48($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A48);
    // 0x80094870: lw          $a1, 0x7978($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7978);
    // 0x80094874: jal         0x8009BC2C
    // 0x80094878: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_52;
    // 0x80094878: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_52:
    // 0x8009487C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80094880: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80094884: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x80094888: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x8009488C: lw          $a2, 0x7A48($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A48);
    // 0x80094890: lw          $a1, 0x7980($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7980);
    // 0x80094894: addiu       $a0, $s3, 0x44
    ctx->r4 = ADD32(ctx->r19, 0X44);
    // 0x80094898: jal         0x8009BC2C
    // 0x8009489C: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_53;
    // 0x8009489C: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_53:
    // 0x800948A0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800948A4: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x800948A8: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x800948AC: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x800948B0: lw          $a2, 0x7A48($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A48);
    // 0x800948B4: lw          $a1, 0x7988($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7988);
    // 0x800948B8: addiu       $a0, $s3, 0x48
    ctx->r4 = ADD32(ctx->r19, 0X48);
    // 0x800948BC: jal         0x8009BC2C
    // 0x800948C0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_54;
    // 0x800948C0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_54:
    // 0x800948C4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800948C8: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x800948CC: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x800948D0: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x800948D4: lw          $a2, 0x7A48($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A48);
    // 0x800948D8: lw          $a1, 0x79A0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X79A0);
    // 0x800948DC: addiu       $a0, $s3, 0x4C
    ctx->r4 = ADD32(ctx->r19, 0X4C);
    // 0x800948E0: jal         0x8009BC2C
    // 0x800948E4: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_55;
    // 0x800948E4: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_55:
    // 0x800948E8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800948EC: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x800948F0: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x800948F4: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x800948F8: lw          $a2, 0x7A48($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A48);
    // 0x800948FC: lw          $a1, 0x79B8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X79B8);
    // 0x80094900: addiu       $a0, $s3, 0x50
    ctx->r4 = ADD32(ctx->r19, 0X50);
    // 0x80094904: jal         0x8009BC2C
    // 0x80094908: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_56;
    // 0x80094908: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_56:
    // 0x8009490C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80094910: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80094914: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x80094918: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x8009491C: lw          $a2, 0x7A48($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A48);
    // 0x80094920: lw          $a1, 0x79C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X79C0);
    // 0x80094924: addiu       $a0, $s3, 0x54
    ctx->r4 = ADD32(ctx->r19, 0X54);
    // 0x80094928: jal         0x8009BC2C
    // 0x8009492C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_57;
    // 0x8009492C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_57:
    // 0x80094930: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80094934: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x80094938: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8009493C: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x80094940: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x80094944: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x80094948: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x8009494C: jr          $ra
    // 0x80094950: addiu       $sp, $sp, 0x260
    ctx->r29 = ADD32(ctx->r29, 0X260);
    return;
    // 0x80094950: addiu       $sp, $sp, 0x260
    ctx->r29 = ADD32(ctx->r29, 0X260);
;}
RECOMP_FUNC void Versus_PlayAgain(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C16D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C16D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C16D8: jal         0x800ABA08
    // 0x800C16DC: nop

    Player_InitVersus(rdram, ctx);
        goto after_0;
    // 0x800C16DC: nop

    after_0:
    // 0x800C16E0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800C16E4: sw          $zero, -0x78AC($at)
    MEM_W(-0X78AC, ctx->r1) = 0;
    // 0x800C16E8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800C16EC: sw          $zero, -0x7888($at)
    MEM_W(-0X7888, ctx->r1) = 0;
    // 0x800C16F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C16F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C16F8: jr          $ra
    // 0x800C16FC: nop

    return;
    // 0x800C16FC: nop

;}
