#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void Map_GameOver_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A4650: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x801A4654: sw          $s7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r23;
    // 0x801A4658: lui         $s7, 0x8013
    ctx->r23 = S32(0X8013 << 16);
    // 0x801A465C: addiu       $s7, $s7, 0x7E64
    ctx->r23 = ADD32(ctx->r23, 0X7E64);
    // 0x801A4660: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x801A4664: sw          $fp, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r30;
    // 0x801A4668: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x801A466C: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x801A4670: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x801A4674: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x801A4678: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x801A467C: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x801A4680: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x801A4684: sdc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X38, ctx->r29);
    // 0x801A4688: addiu       $t6, $zero, 0x1C
    ctx->r14 = ADD32(0, 0X1C);
    // 0x801A468C: addiu       $t7, $zero, 0x3A
    ctx->r15 = ADD32(0, 0X3A);
    // 0x801A4690: addiu       $t8, $zero, 0x69
    ctx->r24 = ADD32(0, 0X69);
    // 0x801A4694: addiu       $t9, $zero, 0x41
    ctx->r25 = ADD32(0, 0X41);
    // 0x801A4698: addiu       $t0, $zero, 0x46
    ctx->r8 = ADD32(0, 0X46);
    // 0x801A469C: addiu       $t1, $zero, 0x30
    ctx->r9 = ADD32(0, 0X30);
    // 0x801A46A0: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x801A46A4: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x801A46A8: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x801A46AC: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x801A46B0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801A46B4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801A46B8: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x801A46BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801A46C0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801A46C4: jal         0x8000372C
    // 0x801A46C8: addiu       $a3, $zero, 0x7F
    ctx->r7 = ADD32(0, 0X7F);
    Lights_SetOneLight(rdram, ctx);
        goto after_0;
    // 0x801A46C8: addiu       $a3, $zero, 0x7F
    ctx->r7 = ADD32(0, 0X7F);
    after_0:
    // 0x801A46CC: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x801A46D0: jal         0x800B8DD0
    // 0x801A46D4: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    RCP_SetupDL(rdram, ctx);
        goto after_1;
    // 0x801A46D4: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    after_1:
    // 0x801A46D8: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x801A46DC: addiu       $s1, $s1, -0x4C40
    ctx->r17 = ADD32(ctx->r17, -0X4C40);
    // 0x801A46E0: lw          $v1, 0x0($s7)
    ctx->r3 = MEM_W(ctx->r23, 0X0);
    // 0x801A46E4: lui         $t3, 0xBB00
    ctx->r11 = S32(0XBB00 << 16);
    // 0x801A46E8: lui         $t4, 0x9C4
    ctx->r12 = S32(0X9C4 << 16);
    // 0x801A46EC: addiu       $t2, $v1, 0x8
    ctx->r10 = ADD32(ctx->r3, 0X8);
    // 0x801A46F0: sw          $t2, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r10;
    // 0x801A46F4: ori         $t4, $t4, 0xC8
    ctx->r12 = ctx->r12 | 0XC8;
    // 0x801A46F8: ori         $t3, $t3, 0x1
    ctx->r11 = ctx->r11 | 0X1;
    // 0x801A46FC: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x801A4700: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x801A4704: lw          $v1, 0x0($s7)
    ctx->r3 = MEM_W(ctx->r23, 0X0);
    // 0x801A4708: lui         $t6, 0xB700
    ctx->r14 = S32(0XB700 << 16);
    // 0x801A470C: lui         $t7, 0x4
    ctx->r15 = S32(0X4 << 16);
    // 0x801A4710: addiu       $t5, $v1, 0x8
    ctx->r13 = ADD32(ctx->r3, 0X8);
    // 0x801A4714: sw          $t5, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r13;
    // 0x801A4718: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x801A471C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x801A4720: jal         0x80005708
    // 0x801A4724: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Push(rdram, ctx);
        goto after_2;
    // 0x801A4724: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x801A4728: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801A472C: lui         $at, 0xC3FA
    ctx->r1 = S32(0XC3FA << 16);
    // 0x801A4730: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801A4734: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801A4738: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801A473C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801A4740: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801A4744: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801A4748: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x801A474C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801A4750: lui         $a3, 0x43FA
    ctx->r7 = S32(0X43FA << 16);
    // 0x801A4754: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x801A4758: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x801A475C: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x801A4760: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x801A4764: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x801A4768: jal         0x80006E3C
    // 0x801A476C: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    Matrix_LookAt(rdram, ctx);
        goto after_3;
    // 0x801A476C: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    after_3:
    // 0x801A4770: jal         0x80006EB8
    // 0x801A4774: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_4;
    // 0x801A4774: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_4:
    // 0x801A4778: lui         $s2, 0x801D
    ctx->r18 = S32(0X801D << 16);
    // 0x801A477C: lui         $s3, 0x801D
    ctx->r19 = S32(0X801D << 16);
    // 0x801A4780: lui         $s4, 0x801D
    ctx->r20 = S32(0X801D << 16);
    // 0x801A4784: lui         $s5, 0x801D
    ctx->r21 = S32(0X801D << 16);
    // 0x801A4788: lui         $s6, 0x801D
    ctx->r22 = S32(0X801D << 16);
    // 0x801A478C: lui         $s0, 0x801B
    ctx->r16 = S32(0X801B << 16);
    // 0x801A4790: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A4794: lui         $fp, 0x801D
    ctx->r30 = S32(0X801D << 16);
    // 0x801A4798: addiu       $fp, $fp, -0xF80
    ctx->r30 = ADD32(ctx->r30, -0XF80);
    // 0x801A479C: lwc1        $f20, 0x77C8($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X77C8);
    // 0x801A47A0: addiu       $s0, $s0, 0x6A4C
    ctx->r16 = ADD32(ctx->r16, 0X6A4C);
    // 0x801A47A4: addiu       $s6, $s6, -0xF78
    ctx->r22 = ADD32(ctx->r22, -0XF78);
    // 0x801A47A8: addiu       $s5, $s5, -0xF58
    ctx->r21 = ADD32(ctx->r21, -0XF58);
    // 0x801A47AC: addiu       $s4, $s4, -0xFA0
    ctx->r20 = ADD32(ctx->r20, -0XFA0);
    // 0x801A47B0: addiu       $s3, $s3, -0xFC0
    ctx->r19 = ADD32(ctx->r19, -0XFC0);
    // 0x801A47B4: addiu       $s2, $s2, -0xFE0
    ctx->r18 = ADD32(ctx->r18, -0XFE0);
L_801A47B8:
    // 0x801A47B8: jal         0x80005708
    // 0x801A47BC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Push(rdram, ctx);
        goto after_5;
    // 0x801A47BC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x801A47C0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801A47C4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x801A47C8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801A47CC: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    // 0x801A47D0: lw          $a2, 0x0($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X0);
    // 0x801A47D4: jal         0x80005B00
    // 0x801A47D8: lw          $a3, 0x0($s4)
    ctx->r7 = MEM_W(ctx->r20, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_6;
    // 0x801A47D8: lw          $a3, 0x0($s4)
    ctx->r7 = MEM_W(ctx->r20, 0X0);
    after_6:
    // 0x801A47DC: lwc1        $f8, 0x0($s5)
    ctx->f8.u32l = MEM_W(ctx->r21, 0X0);
    // 0x801A47E0: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801A47E4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801A47E8: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x801A47EC: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x801A47F0: jal         0x80005E90
    // 0x801A47F4: nop

    Matrix_RotateY(rdram, ctx);
        goto after_7;
    // 0x801A47F4: nop

    after_7:
    // 0x801A47F8: lwc1        $f16, 0x0($s6)
    ctx->f16.u32l = MEM_W(ctx->r22, 0X0);
    // 0x801A47FC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801A4800: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801A4804: mul.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f20.fl);
    // 0x801A4808: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x801A480C: jal         0x80005D44
    // 0x801A4810: nop

    Matrix_RotateX(rdram, ctx);
        goto after_8;
    // 0x801A4810: nop

    after_8:
    // 0x801A4814: lwc1        $f0, 0x0($fp)
    ctx->f0.u32l = MEM_W(ctx->r30, 0X0);
    // 0x801A4818: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801A481C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x801A4820: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801A4824: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801A4828: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x801A482C: jal         0x80005C34
    // 0x801A4830: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_9;
    // 0x801A4830: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_9:
    // 0x801A4834: jal         0x80006EB8
    // 0x801A4838: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_10;
    // 0x801A4838: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_10:
    // 0x801A483C: lw          $v1, 0x0($s7)
    ctx->r3 = MEM_W(ctx->r23, 0X0);
    // 0x801A4840: lui         $t2, 0x600
    ctx->r10 = S32(0X600 << 16);
    // 0x801A4844: addiu       $t1, $v1, 0x8
    ctx->r9 = ADD32(ctx->r3, 0X8);
    // 0x801A4848: sw          $t1, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r9;
    // 0x801A484C: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x801A4850: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x801A4854: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x801A4858: jal         0x80005740
    // 0x801A485C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_11;
    // 0x801A485C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_11:
    // 0x801A4860: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x801A4864: addiu       $t4, $t4, 0x6A6C
    ctx->r12 = ADD32(ctx->r12, 0X6A6C);
    // 0x801A4868: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x801A486C: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x801A4870: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x801A4874: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x801A4878: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
    // 0x801A487C: bne         $s0, $t4, L_801A47B8
    if (ctx->r16 != ctx->r12) {
        // 0x801A4880: addiu       $s6, $s6, 0x4
        ctx->r22 = ADD32(ctx->r22, 0X4);
            goto L_801A47B8;
    }
    // 0x801A4880: addiu       $s6, $s6, 0x4
    ctx->r22 = ADD32(ctx->r22, 0X4);
    // 0x801A4884: jal         0x80005740
    // 0x801A4888: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_12;
    // 0x801A4888: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_12:
    // 0x801A488C: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x801A4890: ldc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X38);
    // 0x801A4894: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x801A4898: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x801A489C: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x801A48A0: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x801A48A4: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x801A48A8: lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X54);
    // 0x801A48AC: lw          $s6, 0x58($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X58);
    // 0x801A48B0: lw          $s7, 0x5C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X5C);
    // 0x801A48B4: lw          $fp, 0x60($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X60);
    // 0x801A48B8: jr          $ra
    // 0x801A48BC: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x801A48BC: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void Option_MainMenu_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80193864: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x80193868: sw          $ra, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r31;
    // 0x8019386C: sw          $s6, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r22;
    // 0x80193870: sw          $s5, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r21;
    // 0x80193874: sw          $s4, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r20;
    // 0x80193878: sw          $s3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r19;
    // 0x8019387C: sw          $s2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r18;
    // 0x80193880: sw          $s1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r17;
    // 0x80193884: sw          $s0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r16;
    // 0x80193888: sdc1        $f28, 0x60($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X60, ctx->r29);
    // 0x8019388C: sdc1        $f26, 0x58($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X58, ctx->r29);
    // 0x80193890: sdc1        $f24, 0x50($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X50, ctx->r29);
    // 0x80193894: sdc1        $f22, 0x48($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X48, ctx->r29);
    // 0x80193898: sdc1        $f20, 0x40($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X40, ctx->r29);
    // 0x8019389C: jal         0x8019BDF0
    // 0x801938A0: nop

    Option_Menu_Push(rdram, ctx);
        goto after_0;
    // 0x801938A0: nop

    after_0:
    // 0x801938A4: lui         $s0, 0x801B
    ctx->r16 = S32(0X801B << 16);
    // 0x801938A8: lui         $s1, 0x801B
    ctx->r17 = S32(0X801B << 16);
    // 0x801938AC: addiu       $s1, $s1, -0x1788
    ctx->r17 = ADD32(ctx->r17, -0X1788);
    // 0x801938B0: addiu       $s0, $s0, -0x19C8
    ctx->r16 = ADD32(ctx->r16, -0X19C8);
    // 0x801938B4: lw          $t6, 0x5C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X5C);
L_801938B8:
    // 0x801938B8: beql        $t6, $zero, L_801938FC
    if (ctx->r14 == 0) {
        // 0x801938BC: addiu       $s0, $s0, 0x60
        ctx->r16 = ADD32(ctx->r16, 0X60);
            goto L_801938FC;
    }
    goto skip_0;
    // 0x801938BC: addiu       $s0, $s0, 0x60
    ctx->r16 = ADD32(ctx->r16, 0X60);
    skip_0:
    // 0x801938C0: lw          $at, 0x38($s0)
    ctx->r1 = MEM_W(ctx->r16, 0X38);
    // 0x801938C4: lw          $t8, 0x3C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X3C);
    // 0x801938C8: lw          $a3, 0x44($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X44);
    // 0x801938CC: sw          $at, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r1;
    // 0x801938D0: lw          $at, 0x40($s0)
    ctx->r1 = MEM_W(ctx->r16, 0X40);
    // 0x801938D4: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
    // 0x801938D8: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x801938DC: sw          $at, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r1;
    // 0x801938E0: lw          $at, 0x48($s0)
    ctx->r1 = MEM_W(ctx->r16, 0X48);
    // 0x801938E4: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x801938E8: lw          $a0, 0x0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X0);
    // 0x801938EC: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x801938F0: jal         0x8019BAB8
    // 0x801938F4: sw          $at, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r1;
    Option_DrawMenuCard(rdram, ctx);
        goto after_1;
    // 0x801938F4: sw          $at, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r1;
    after_1:
    // 0x801938F8: addiu       $s0, $s0, 0x60
    ctx->r16 = ADD32(ctx->r16, 0X60);
L_801938FC:
    // 0x801938FC: sltu        $at, $s0, $s1
    ctx->r1 = ctx->r16 < ctx->r17 ? 1 : 0;
    // 0x80193900: bnel        $at, $zero, L_801938B8
    if (ctx->r1 != 0) {
        // 0x80193904: lw          $t6, 0x5C($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X5C);
            goto L_801938B8;
    }
    goto skip_1;
    // 0x80193904: lw          $t6, 0x5C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X5C);
    skip_1:
    // 0x80193908: lui         $t9, 0x801C
    ctx->r25 = S32(0X801C << 16);
    // 0x8019390C: lw          $t9, -0x6E5C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X6E5C);
    // 0x80193910: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x80193914: addiu       $t2, $t2, -0x19C8
    ctx->r10 = ADD32(ctx->r10, -0X19C8);
    // 0x80193918: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8019391C: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x80193920: sll         $t0, $t0, 5
    ctx->r8 = S32(ctx->r8 << 5);
    // 0x80193924: addiu       $t1, $t0, 0x4C
    ctx->r9 = ADD32(ctx->r8, 0X4C);
    // 0x80193928: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x8019392C: lw          $at, 0x0($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X0);
    // 0x80193930: sw          $at, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r1;
    // 0x80193934: lw          $a1, 0x4($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X4);
    // 0x80193938: lw          $a0, 0x0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X0);
    // 0x8019393C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80193940: lw          $a2, 0x8($t3)
    ctx->r6 = MEM_W(ctx->r11, 0X8);
    // 0x80193944: jal         0x8019BBA4
    // 0x80193948: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    Option_DrawMenuArwing(rdram, ctx);
        goto after_2;
    // 0x80193948: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    after_2:
    // 0x8019394C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80193950: jal         0x80005740
    // 0x80193954: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Pop(rdram, ctx);
        goto after_3;
    // 0x80193954: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_3:
    // 0x80193958: lui         $at, 0x4318
    ctx->r1 = S32(0X4318 << 16);
    // 0x8019395C: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x80193960: lui         $at, 0x4260
    ctx->r1 = S32(0X4260 << 16);
    // 0x80193964: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80193968: lui         $at, 0x42C4
    ctx->r1 = S32(0X42C4 << 16);
    // 0x8019396C: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80193970: lui         $at, 0x42D4
    ctx->r1 = S32(0X42D4 << 16);
    // 0x80193974: lui         $s0, 0x801B
    ctx->r16 = S32(0X801B << 16);
    // 0x80193978: lui         $s6, 0x801B
    ctx->r22 = S32(0X801B << 16);
    // 0x8019397C: lui         $s5, 0x801B
    ctx->r21 = S32(0X801B << 16);
    // 0x80193980: lui         $s4, 0x801B
    ctx->r20 = S32(0X801B << 16);
    // 0x80193984: lui         $s2, 0x801C
    ctx->r18 = S32(0X801C << 16);
    // 0x80193988: lui         $s1, 0x801C
    ctx->r17 = S32(0X801C << 16);
    // 0x8019398C: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80193990: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x80193994: addiu       $s1, $s1, -0x6E38
    ctx->r17 = ADD32(ctx->r17, -0X6E38);
    // 0x80193998: addiu       $s2, $s2, -0x6ED4
    ctx->r18 = ADD32(ctx->r18, -0X6ED4);
    // 0x8019399C: addiu       $s4, $s4, -0x1788
    ctx->r20 = ADD32(ctx->r20, -0X1788);
    // 0x801939A0: addiu       $s5, $s5, -0x19C8
    ctx->r21 = ADD32(ctx->r21, -0X19C8);
    // 0x801939A4: addiu       $s6, $s6, -0x1848
    ctx->r22 = ADD32(ctx->r22, -0X1848);
    // 0x801939A8: addiu       $s0, $s0, -0x19C8
    ctx->r16 = ADD32(ctx->r16, -0X19C8);
    // 0x801939AC: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x801939B0: lw          $t6, 0x58($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X58);
L_801939B4:
    // 0x801939B4: beql        $t6, $zero, L_80193AB8
    if (ctx->r14 == 0) {
        // 0x801939B8: addiu       $s0, $s0, 0x60
        ctx->r16 = ADD32(ctx->r16, 0X60);
            goto L_80193AB8;
    }
    goto skip_2;
    // 0x801939B8: addiu       $s0, $s0, 0x60
    ctx->r16 = ADD32(ctx->r16, 0X60);
    skip_2:
    // 0x801939BC: lwc1        $f4, 0x20($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X20);
    // 0x801939C0: c.le.s      $f4, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f4.fl <= ctx->f24.fl;
    // 0x801939C4: nop

    // 0x801939C8: bc1tl       L_80193AB8
    if (c1cs) {
        // 0x801939CC: addiu       $s0, $s0, 0x60
        ctx->r16 = ADD32(ctx->r16, 0X60);
            goto L_80193AB8;
    }
    goto skip_3;
    // 0x801939CC: addiu       $s0, $s0, 0x60
    ctx->r16 = ADD32(ctx->r16, 0X60);
    skip_3:
    // 0x801939D0: bne         $s0, $s5, L_80193A18
    if (ctx->r16 != ctx->r21) {
        // 0x801939D4: nop
    
            goto L_80193A18;
    }
    // 0x801939D4: nop

    // 0x801939D8: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x801939DC: beq         $t7, $zero, L_80193A18
    if (ctx->r15 == 0) {
        // 0x801939E0: nop
    
            goto L_80193A18;
    }
    // 0x801939E0: nop

    // 0x801939E4: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x801939E8: addiu       $a3, $zero, 0x14
    ctx->r7 = ADD32(0, 0X14);
    // 0x801939EC: addiu       $t8, $zero, 0x4B
    ctx->r24 = ADD32(0, 0X4B);
    // 0x801939F0: beql        $v0, $zero, L_80193A04
    if (ctx->r2 == 0) {
        // 0x801939F4: mfc1        $a2, $f22
        ctx->r6 = (int32_t)ctx->f22.u32l;
            goto L_80193A04;
    }
    goto skip_4;
    // 0x801939F4: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    skip_4:
    // 0x801939F8: bne         $s3, $v0, L_80193A18
    if (ctx->r19 != ctx->r2) {
        // 0x801939FC: nop
    
            goto L_80193A18;
    }
    // 0x801939FC: nop

    // 0x80193A00: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
L_80193A04:
    // 0x80193A04: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x80193A08: mov.s       $f14, $f26
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    ctx->f14.fl = ctx->f26.fl;
    // 0x80193A0C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80193A10: jal         0x8019B6D8
    // 0x80193A14: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    Option_VsSelectionArrows_Draw(rdram, ctx);
        goto after_4;
    // 0x80193A14: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    after_4:
L_80193A18:
    // 0x80193A18: bnel        $s0, $s6, L_80193A64
    if (ctx->r16 != ctx->r22) {
        // 0x80193A1C: or          $t4, $s0, $zero
        ctx->r12 = ctx->r16 | 0;
            goto L_80193A64;
    }
    goto skip_5;
    // 0x80193A1C: or          $t4, $s0, $zero
    ctx->r12 = ctx->r16 | 0;
    skip_5:
    // 0x80193A20: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80193A24: beql        $t9, $zero, L_80193A64
    if (ctx->r25 == 0) {
        // 0x80193A28: or          $t4, $s0, $zero
        ctx->r12 = ctx->r16 | 0;
            goto L_80193A64;
    }
    goto skip_6;
    // 0x80193A28: or          $t4, $s0, $zero
    ctx->r12 = ctx->r16 | 0;
    skip_6:
    // 0x80193A2C: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80193A30: addiu       $a3, $zero, 0x14
    ctx->r7 = ADD32(0, 0X14);
    // 0x80193A34: addiu       $t0, $zero, 0x4B
    ctx->r8 = ADD32(0, 0X4B);
    // 0x80193A38: beql        $v0, $zero, L_80193A4C
    if (ctx->r2 == 0) {
        // 0x80193A3C: mfc1        $a2, $f22
        ctx->r6 = (int32_t)ctx->f22.u32l;
            goto L_80193A4C;
    }
    goto skip_7;
    // 0x80193A3C: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    skip_7:
    // 0x80193A40: bnel        $s3, $v0, L_80193A64
    if (ctx->r19 != ctx->r2) {
        // 0x80193A44: or          $t4, $s0, $zero
        ctx->r12 = ctx->r16 | 0;
            goto L_80193A64;
    }
    goto skip_8;
    // 0x80193A44: or          $t4, $s0, $zero
    ctx->r12 = ctx->r16 | 0;
    skip_8:
    // 0x80193A48: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
L_80193A4C:
    // 0x80193A4C: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x80193A50: mov.s       $f14, $f28
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 28);
    ctx->f14.fl = ctx->f28.fl;
    // 0x80193A54: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80193A58: jal         0x8019B6D8
    // 0x80193A5C: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    Option_VsSelectionArrows_Draw(rdram, ctx);
        goto after_5;
    // 0x80193A5C: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    after_5:
    // 0x80193A60: or          $t4, $s0, $zero
    ctx->r12 = ctx->r16 | 0;
L_80193A64:
    // 0x80193A64: or          $t3, $sp, $zero
    ctx->r11 = ctx->r29 | 0;
    // 0x80193A68: addiu       $t2, $s0, 0x30
    ctx->r10 = ADD32(ctx->r16, 0X30);
L_80193A6C:
    // 0x80193A6C: lw          $at, 0x0($t4)
    ctx->r1 = MEM_W(ctx->r12, 0X0);
    // 0x80193A70: addiu       $t4, $t4, 0xC
    ctx->r12 = ADD32(ctx->r12, 0XC);
    // 0x80193A74: addiu       $t3, $t3, 0xC
    ctx->r11 = ADD32(ctx->r11, 0XC);
    // 0x80193A78: sw          $at, -0xC($t3)
    MEM_W(-0XC, ctx->r11) = ctx->r1;
    // 0x80193A7C: lw          $at, -0x8($t4)
    ctx->r1 = MEM_W(ctx->r12, -0X8);
    // 0x80193A80: sw          $at, -0x8($t3)
    MEM_W(-0X8, ctx->r11) = ctx->r1;
    // 0x80193A84: lw          $at, -0x4($t4)
    ctx->r1 = MEM_W(ctx->r12, -0X4);
    // 0x80193A88: bne         $t4, $t2, L_80193A6C
    if (ctx->r12 != ctx->r10) {
        // 0x80193A8C: sw          $at, -0x4($t3)
        MEM_W(-0X4, ctx->r11) = ctx->r1;
            goto L_80193A6C;
    }
    // 0x80193A8C: sw          $at, -0x4($t3)
    MEM_W(-0X4, ctx->r11) = ctx->r1;
    // 0x80193A90: lw          $at, 0x0($t4)
    ctx->r1 = MEM_W(ctx->r12, 0X0);
    // 0x80193A94: sw          $at, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r1;
    // 0x80193A98: lw          $t2, 0x4($t4)
    ctx->r10 = MEM_W(ctx->r12, 0X4);
    // 0x80193A9C: sw          $t2, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r10;
    // 0x80193AA0: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    // 0x80193AA4: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x80193AA8: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x80193AAC: jal         0x8019C120
    // 0x80193AB0: lw          $a0, 0x0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X0);
    Option_DrawCardLabel(rdram, ctx);
        goto after_6;
    // 0x80193AB0: lw          $a0, 0x0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X0);
    after_6:
    // 0x80193AB4: addiu       $s0, $s0, 0x60
    ctx->r16 = ADD32(ctx->r16, 0X60);
L_80193AB8:
    // 0x80193AB8: bnel        $s0, $s4, L_801939B4
    if (ctx->r16 != ctx->r20) {
        // 0x80193ABC: lw          $t6, 0x58($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X58);
            goto L_801939B4;
    }
    goto skip_9;
    // 0x80193ABC: lw          $t6, 0x58($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X58);
    skip_9:
    // 0x80193AC0: jal         0x8019BF34
    // 0x80193AC4: nop

    Option_CardLightning_Update(rdram, ctx);
        goto after_7;
    // 0x80193AC4: nop

    after_7:
    // 0x80193AC8: lw          $ra, 0x84($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X84);
    // 0x80193ACC: ldc1        $f20, 0x40($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X40);
    // 0x80193AD0: ldc1        $f22, 0x48($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X48);
    // 0x80193AD4: ldc1        $f24, 0x50($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X50);
    // 0x80193AD8: ldc1        $f26, 0x58($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X58);
    // 0x80193ADC: ldc1        $f28, 0x60($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X60);
    // 0x80193AE0: lw          $s0, 0x68($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X68);
    // 0x80193AE4: lw          $s1, 0x6C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X6C);
    // 0x80193AE8: lw          $s2, 0x70($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X70);
    // 0x80193AEC: lw          $s3, 0x74($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X74);
    // 0x80193AF0: lw          $s4, 0x78($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X78);
    // 0x80193AF4: lw          $s5, 0x7C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X7C);
    // 0x80193AF8: lw          $s6, 0x80($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X80);
    // 0x80193AFC: jr          $ra
    // 0x80193B00: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x80193B00: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void Map_Setup_Menu(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019F600: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8019F604: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8019F608: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8019F60C: lui         $a3, 0x8017
    ctx->r7 = S32(0X8017 << 16);
    // 0x8019F610: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x8019F614: addiu       $t0, $t0, 0x7C58
    ctx->r8 = ADD32(ctx->r8, 0X7C58);
    // 0x8019F618: addiu       $a3, $a3, 0x7C38
    ctx->r7 = ADD32(ctx->r7, 0X7C38);
    // 0x8019F61C: addiu       $a0, $a0, 0x78D0
    ctx->r4 = ADD32(ctx->r4, 0X78D0);
    // 0x8019F620: addiu       $v1, $v1, 0x78B0
    ctx->r3 = ADD32(ctx->r3, 0X78B0);
    // 0x8019F624: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8019F628: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8019F62C: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x8019F630: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8019F634: sw          $zero, 0x1714($at)
    MEM_W(0X1714, ctx->r1) = 0;
    // 0x8019F638: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8019F63C: sw          $zero, 0x1A98($at)
    MEM_W(0X1A98, ctx->r1) = 0;
    // 0x8019F640: sw          $a1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r5;
    // 0x8019F644: sw          $a1, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r5;
    // 0x8019F648: sw          $a1, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r5;
    // 0x8019F64C: sw          $a1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r5;
    // 0x8019F650: sw          $a1, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r5;
    // 0x8019F654: sw          $a1, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r5;
    // 0x8019F658: sw          $a1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r5;
    // 0x8019F65C: sw          $a1, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r5;
    // 0x8019F660: sw          $a1, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r5;
    // 0x8019F664: sw          $a1, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r5;
    // 0x8019F668: sw          $a1, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r5;
    // 0x8019F66C: sw          $a1, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r5;
    // 0x8019F670: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8019F674: lui         $v1, 0x801B
    ctx->r3 = S32(0X801B << 16);
    // 0x8019F678: lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // 0x8019F67C: sw          $t1, -0x26B0($at)
    MEM_W(-0X26B0, ctx->r1) = ctx->r9;
    // 0x8019F680: addiu       $v0, $v0, -0xB60
    ctx->r2 = ADD32(ctx->r2, -0XB60);
    // 0x8019F684: addiu       $v1, $v1, -0x818
    ctx->r3 = ADD32(ctx->r3, -0X818);
L_8019F688:
    // 0x8019F688: addiu       $v0, $v0, 0x38
    ctx->r2 = ADD32(ctx->r2, 0X38);
    // 0x8019F68C: sltu        $at, $v0, $v1
    ctx->r1 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x8019F690: bne         $at, $zero, L_8019F688
    if (ctx->r1 != 0) {
        // 0x8019F694: sw          $zero, -0x14($v0)
        MEM_W(-0X14, ctx->r2) = 0;
            goto L_8019F688;
    }
    // 0x8019F694: sw          $zero, -0x14($v0)
    MEM_W(-0X14, ctx->r2) = 0;
    // 0x8019F698: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8019F69C: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8019F6A0: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8019F6A4: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8019F6A8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8019F6AC: sw          $zero, -0x2690($at)
    MEM_W(-0X2690, ctx->r1) = 0;
    // 0x8019F6B0: addiu       $a0, $a0, 0x4BD0
    ctx->r4 = ADD32(ctx->r4, 0X4BD0);
    // 0x8019F6B4: addiu       $v0, $v0, 0x4750
    ctx->r2 = ADD32(ctx->r2, 0X4750);
    // 0x8019F6B8: addiu       $v1, $v1, 0x7BD8
    ctx->r3 = ADD32(ctx->r3, 0X7BD8);
L_8019F6BC:
    // 0x8019F6BC: addiu       $v0, $v0, 0x30
    ctx->r2 = ADD32(ctx->r2, 0X30);
    // 0x8019F6C0: sltu        $at, $v0, $a0
    ctx->r1 = ctx->r2 < ctx->r4 ? 1 : 0;
    // 0x8019F6C4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8019F6C8: sw          $zero, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = 0;
    // 0x8019F6CC: bne         $at, $zero, L_8019F6BC
    if (ctx->r1 != 0) {
        // 0x8019F6D0: swc1        $f0, -0xC($v0)
        MEM_W(-0XC, ctx->r2) = ctx->f0.u32l;
            goto L_8019F6BC;
    }
    // 0x8019F6D0: swc1        $f0, -0xC($v0)
    MEM_W(-0XC, ctx->r2) = ctx->f0.u32l;
    // 0x8019F6D4: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8019F6D8: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8019F6DC: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8019F6E0: lui         $a3, 0x8017
    ctx->r7 = S32(0X8017 << 16);
    // 0x8019F6E4: lui         $a2, 0xFF
    ctx->r6 = S32(0XFF << 16);
    // 0x8019F6E8: ori         $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 | 0XFFFF;
    // 0x8019F6EC: addiu       $a3, $a3, 0x7B6C
    ctx->r7 = ADD32(ctx->r7, 0X7B6C);
    // 0x8019F6F0: addiu       $v0, $v0, 0x7B50
    ctx->r2 = ADD32(ctx->r2, 0X7B50);
    // 0x8019F6F4: addiu       $a0, $a0, 0x7B70
    ctx->r4 = ADD32(ctx->r4, 0X7B70);
    // 0x8019F6F8: addiu       $v1, $v1, 0x7BB0
    ctx->r3 = ADD32(ctx->r3, 0X7BB0);
L_8019F6FC:
    // 0x8019F6FC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8019F700: sltu        $at, $v0, $a3
    ctx->r1 = ctx->r2 < ctx->r7 ? 1 : 0;
    // 0x8019F704: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8019F708: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8019F70C: sw          $zero, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = 0;
    // 0x8019F710: sw          $zero, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = 0;
    // 0x8019F714: bne         $at, $zero, L_8019F6FC
    if (ctx->r1 != 0) {
        // 0x8019F718: sw          $a2, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->r6;
            goto L_8019F6FC;
    }
    // 0x8019F718: sw          $a2, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r6;
    // 0x8019F71C: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8019F720: addiu       $v1, $v1, 0x7B90
    ctx->r3 = ADD32(ctx->r3, 0X7B90);
    // 0x8019F724: addiu       $a3, $zero, 0x9
    ctx->r7 = ADD32(0, 0X9);
    // 0x8019F728: addiu       $t6, $zero, 0xD
    ctx->r14 = ADD32(0, 0XD);
    // 0x8019F72C: sw          $a3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r7;
    // 0x8019F730: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x8019F734: sw          $t1, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r9;
    // 0x8019F738: sw          $t1, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r9;
    // 0x8019F73C: sw          $t1, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r9;
    // 0x8019F740: sw          $t1, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r9;
    // 0x8019F744: sw          $t6, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r14;
    // 0x8019F748: lui         $v1, 0x801B
    ctx->r3 = S32(0X801B << 16);
    // 0x8019F74C: lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // 0x8019F750: addiu       $v0, $v0, -0x2E8
    ctx->r2 = ADD32(ctx->r2, -0X2E8);
    // 0x8019F754: addiu       $v1, $v1, -0x48
    ctx->r3 = ADD32(ctx->r3, -0X48);
L_8019F758:
    // 0x8019F758: addiu       $v0, $v0, 0x70
    ctx->r2 = ADD32(ctx->r2, 0X70);
    // 0x8019F75C: sw          $a1, -0x3C($v0)
    MEM_W(-0X3C, ctx->r2) = ctx->r5;
    // 0x8019F760: sw          $a1, -0x20($v0)
    MEM_W(-0X20, ctx->r2) = ctx->r5;
    // 0x8019F764: sw          $a1, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r5;
    // 0x8019F768: bne         $v0, $v1, L_8019F758
    if (ctx->r2 != ctx->r3) {
        // 0x8019F76C: sw          $a1, -0x58($v0)
        MEM_W(-0X58, ctx->r2) = ctx->r5;
            goto L_8019F758;
    }
    // 0x8019F76C: sw          $a1, -0x58($v0)
    MEM_W(-0X58, ctx->r2) = ctx->r5;
    // 0x8019F770: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019F774: sw          $zero, 0x7B48($at)
    MEM_W(0X7B48, ctx->r1) = 0;
    // 0x8019F778: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8019F77C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8019F780: sw          $zero, -0x7DCC($at)
    MEM_W(-0X7DCC, ctx->r1) = 0;
    // 0x8019F784: addiu       $v0, $v0, -0x26AC
    ctx->r2 = ADD32(ctx->r2, -0X26AC);
    // 0x8019F788: sw          $a3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r7;
    // 0x8019F78C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8019F790: swc1        $f0, -0x1564($at)
    MEM_W(-0X1564, ctx->r1) = ctx->f0.u32l;
    // 0x8019F794: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8019F798: lwc1        $f4, 0x753C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X753C);
    // 0x8019F79C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8019F7A0: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x8019F7A4: swc1        $f4, -0x2650($at)
    MEM_W(-0X2650, ctx->r1) = ctx->f4.u32l;
    // 0x8019F7A8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8019F7AC: lwc1        $f6, 0x7540($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7540);
    // 0x8019F7B0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8019F7B4: swc1        $f6, -0x264C($at)
    MEM_W(-0X264C, ctx->r1) = ctx->f6.u32l;
    // 0x8019F7B8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8019F7BC: sw          $zero, -0x26BC($at)
    MEM_W(-0X26BC, ctx->r1) = 0;
    // 0x8019F7C0: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8019F7C4: sll         $t7, $a0, 3
    ctx->r15 = S32(ctx->r4 << 3);
    // 0x8019F7C8: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x8019F7CC: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8019F7D0: addu        $a1, $a1, $t7
    ctx->r5 = ADD32(ctx->r5, ctx->r15);
    // 0x8019F7D4: jal         0x801A655C
    // 0x8019F7D8: lw          $a1, -0xB34($a1)
    ctx->r5 = MEM_W(ctx->r5, -0XB34);
    Map_GetPathId(rdram, ctx);
        goto after_0;
    // 0x8019F7D8: lw          $a1, -0xB34($a1)
    ctx->r5 = MEM_W(ctx->r5, -0XB34);
    after_0:
    // 0x8019F7DC: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8019F7E0: lw          $a0, -0x26AC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X26AC);
    // 0x8019F7E4: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x8019F7E8: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8019F7EC: sll         $t8, $a0, 3
    ctx->r24 = S32(ctx->r4 << 3);
    // 0x8019F7F0: subu        $t8, $t8, $a0
    ctx->r24 = SUB32(ctx->r24, ctx->r4);
    // 0x8019F7F4: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8019F7F8: addu        $a1, $a1, $t8
    ctx->r5 = ADD32(ctx->r5, ctx->r24);
    // 0x8019F7FC: jal         0x801A655C
    // 0x8019F800: lw          $a1, -0xB30($a1)
    ctx->r5 = MEM_W(ctx->r5, -0XB30);
    Map_GetPathId(rdram, ctx);
        goto after_1;
    // 0x8019F800: lw          $a1, -0xB30($a1)
    ctx->r5 = MEM_W(ctx->r5, -0XB30);
    after_1:
    // 0x8019F804: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8019F808: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8019F80C: addiu       $v1, $v1, 0x7BD8
    ctx->r3 = ADD32(ctx->r3, 0X7BD8);
    // 0x8019F810: sll         $t2, $t9, 2
    ctx->r10 = S32(ctx->r25 << 2);
    // 0x8019F814: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8019F818: addu        $t3, $v1, $t2
    ctx->r11 = ADD32(ctx->r3, ctx->r10);
    // 0x8019F81C: sll         $t4, $v0, 2
    ctx->r12 = S32(ctx->r2 << 2);
    // 0x8019F820: sw          $a0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r4;
    // 0x8019F824: addu        $t5, $v1, $t4
    ctx->r13 = ADD32(ctx->r3, ctx->r12);
    // 0x8019F828: sw          $a0, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r4;
    // 0x8019F82C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8019F830: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8019F834: jr          $ra
    // 0x8019F838: nop

    return;
    // 0x8019F838: nop

;}
RECOMP_FUNC void Title_Screen_Input(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019111C: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x80191120: lw          $t6, -0x7D50($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7D50);
    // 0x80191124: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x80191128: addiu       $a2, $a2, -0x6FC0
    ctx->r6 = ADD32(ctx->r6, -0X6FC0);
    // 0x8019112C: bne         $t6, $zero, L_80191188
    if (ctx->r14 != 0) {
        // 0x80191130: lui         $t4, 0x8017
        ctx->r12 = S32(0X8017 << 16);
            goto L_80191188;
    }
    // 0x80191130: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x80191134: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x80191138: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x8019113C: bne         $t7, $zero, L_80191188
    if (ctx->r15 != 0) {
        // 0x80191140: nop
    
            goto L_80191188;
    }
    // 0x80191140: nop

    // 0x80191144: lw          $t8, 0x7AF8($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7AF8);
    // 0x80191148: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8019114C: addiu       $t0, $t0, -0x2768
    ctx->r8 = ADD32(ctx->r8, -0X2768);
    // 0x80191150: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80191154: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80191158: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x8019115C: addu        $v1, $t9, $t0
    ctx->r3 = ADD32(ctx->r25, ctx->r8);
    // 0x80191160: lb          $t1, 0x2($v1)
    ctx->r9 = MEM_B(ctx->r3, 0X2);
    // 0x80191164: lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // 0x80191168: addiu       $a3, $a3, -0x795C
    ctx->r7 = ADD32(ctx->r7, -0X795C);
    // 0x8019116C: bne         $t1, $zero, L_80191180
    if (ctx->r9 != 0) {
        // 0x80191170: addiu       $t3, $zero, 0x1
        ctx->r11 = ADD32(0, 0X1);
            goto L_80191180;
    }
    // 0x80191170: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80191174: lb          $t2, 0x3($v1)
    ctx->r10 = MEM_B(ctx->r3, 0X3);
    // 0x80191178: beq         $t2, $zero, L_80191188
    if (ctx->r10 == 0) {
        // 0x8019117C: nop
    
            goto L_80191188;
    }
    // 0x8019117C: nop

L_80191180:
    // 0x80191180: sw          $t3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r11;
    // 0x80191184: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
L_80191188:
    // 0x80191188: lw          $t4, 0x7AF8($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7AF8);
    // 0x8019118C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80191190: addiu       $t6, $t6, -0x2768
    ctx->r14 = ADD32(ctx->r14, -0X2768);
    // 0x80191194: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80191198: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x8019119C: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x801911A0: addu        $v1, $t5, $t6
    ctx->r3 = ADD32(ctx->r13, ctx->r14);
    // 0x801911A4: lb          $a0, 0x2($v1)
    ctx->r4 = MEM_B(ctx->r3, 0X2);
    // 0x801911A8: lb          $a1, 0x3($v1)
    ctx->r5 = MEM_B(ctx->r3, 0X3);
    // 0x801911AC: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x801911B0: addiu       $a2, $a2, -0x6FC0
    ctx->r6 = ADD32(ctx->r6, -0X6FC0);
    // 0x801911B4: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x801911B8: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
    // 0x801911BC: mtc1        $a1, $f6
    ctx->f6.u32l = ctx->r5;
    // 0x801911C0: lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // 0x801911C4: addiu       $a3, $a3, -0x795C
    ctx->r7 = ADD32(ctx->r7, -0X795C);
    // 0x801911C8: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801911CC: beq         $v0, $zero, L_8019126C
    if (ctx->r2 == 0) {
        // 0x801911D0: cvt.s.w     $f2, $f6
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    ctx->f2.fl = CVT_S_W(ctx->f6.u32l);
            goto L_8019126C;
    }
    // 0x801911D0: cvt.s.w     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    ctx->f2.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801911D4: lui         $at, 0xC3FA
    ctx->r1 = S32(0XC3FA << 16);
    // 0x801911D8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x801911DC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801911E0: lwc1        $f16, 0x70D4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X70D4);
    // 0x801911E4: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801911E8: addiu       $v1, $v1, -0x6FA4
    ctx->r3 = ADD32(ctx->r3, -0X6FA4);
    // 0x801911EC: mul.s       $f8, $f0, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x801911F0: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
    // 0x801911F4: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x801911F8: mul.s       $f4, $f2, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x801911FC: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80191200: c.lt.s      $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl < ctx->f12.fl;
    // 0x80191204: nop

    // 0x80191208: bc1f        L_8019122C
    if (!c1cs) {
        // 0x8019120C: nop
    
            goto L_8019122C;
    }
    // 0x8019120C: nop

    // 0x80191210: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80191214: nop

    // 0x80191218: c.lt.s      $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f12.fl < ctx->f18.fl;
    // 0x8019121C: nop

    // 0x80191220: bc1f        L_8019122C
    if (!c1cs) {
        // 0x80191224: nop
    
            goto L_8019122C;
    }
    // 0x80191224: nop

    // 0x80191228: swc1        $f12, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f12.u32l;
L_8019122C:
    // 0x8019122C: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80191230: addiu       $v1, $v1, -0x6FA0
    ctx->r3 = ADD32(ctx->r3, -0X6FA0);
    // 0x80191234: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80191238: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x8019123C: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80191240: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x80191244: nop

    // 0x80191248: bc1f        L_8019126C
    if (!c1cs) {
        // 0x8019124C: nop
    
            goto L_8019126C;
    }
    // 0x8019124C: nop

    // 0x80191250: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80191254: nop

    // 0x80191258: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x8019125C: nop

    // 0x80191260: bc1f        L_8019126C
    if (!c1cs) {
        // 0x80191264: nop
    
            goto L_8019126C;
    }
    // 0x80191264: nop

    // 0x80191268: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
L_8019126C:
    // 0x8019126C: beql        $v0, $zero, L_80191298
    if (ctx->r2 == 0) {
        // 0x80191270: sw          $zero, 0x0($a3)
        MEM_W(0X0, ctx->r7) = 0;
            goto L_80191298;
    }
    goto skip_0;
    // 0x80191270: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
    skip_0:
    // 0x80191274: bnel        $a0, $zero, L_80191298
    if (ctx->r4 != 0) {
        // 0x80191278: sw          $zero, 0x0($a3)
        MEM_W(0X0, ctx->r7) = 0;
            goto L_80191298;
    }
    goto skip_1;
    // 0x80191278: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
    skip_1:
    // 0x8019127C: bnel        $a1, $zero, L_80191298
    if (ctx->r5 != 0) {
        // 0x80191280: sw          $zero, 0x0($a3)
        MEM_W(0X0, ctx->r7) = 0;
            goto L_80191298;
    }
    goto skip_2;
    // 0x80191280: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
    skip_2:
    // 0x80191284: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
    // 0x80191288: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8019128C: jr          $ra
    // 0x80191290: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    return;
    // 0x80191290: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x80191294: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
L_80191298:
    // 0x80191298: jr          $ra
    // 0x8019129C: nop

    return;
    // 0x8019129C: nop

;}
RECOMP_FUNC void Map_Titania_DrawRings1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A791C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x801A7920: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x801A7924: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x801A7928: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x801A792C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801A7930: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x801A7934: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x801A7938: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801A793C: jal         0x800B8DD0
    // 0x801A7940: addiu       $a1, $zero, 0x43
    ctx->r5 = ADD32(0, 0X43);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x801A7940: addiu       $a1, $zero, 0x43
    ctx->r5 = ADD32(0, 0X43);
    after_0:
    // 0x801A7944: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x801A7948: addiu       $s1, $s1, -0x4C40
    ctx->r17 = ADD32(ctx->r17, -0X4C40);
    // 0x801A794C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801A7950: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x801A7954: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x801A7958: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801A795C: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x801A7960: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801A7964: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x801A7968: addiu       $t0, $t0, -0xB60
    ctx->r8 = ADD32(ctx->r8, -0XB60);
    // 0x801A796C: lui         $at, 0xFFAF
    ctx->r1 = S32(0XFFAF << 16);
    // 0x801A7970: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x801A7974: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x801A7978: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x801A797C: addu        $a2, $t9, $t0
    ctx->r6 = ADD32(ctx->r25, ctx->r8);
    // 0x801A7980: lw          $t1, 0x24($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X24);
    // 0x801A7984: ori         $at, $at, 0xAF00
    ctx->r1 = ctx->r1 | 0XAF00;
    // 0x801A7988: lui         $t5, 0xFB00
    ctx->r13 = S32(0XFB00 << 16);
    // 0x801A798C: andi        $t2, $t1, 0xFF
    ctx->r10 = ctx->r9 & 0XFF;
    // 0x801A7990: or          $t3, $t2, $at
    ctx->r11 = ctx->r10 | ctx->r1;
    // 0x801A7994: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x801A7998: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801A799C: lui         $t6, 0x491F
    ctx->r14 = S32(0X491F << 16);
    // 0x801A79A0: ori         $t6, $t6, 0xF00
    ctx->r14 = ctx->r14 | 0XF00;
    // 0x801A79A4: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x801A79A8: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x801A79AC: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x801A79B0: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x801A79B4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801A79B8: jal         0x80005708
    // 0x801A79BC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    Matrix_Push(rdram, ctx);
        goto after_1;
    // 0x801A79BC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_1:
    // 0x801A79C0: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x801A79C4: lui         $t9, 0x801D
    ctx->r25 = S32(0X801D << 16);
    // 0x801A79C8: addiu       $t9, $t9, -0x21E0
    ctx->r25 = ADD32(ctx->r25, -0X21E0);
    // 0x801A79CC: sll         $t8, $t7, 6
    ctx->r24 = S32(ctx->r15 << 6);
    // 0x801A79D0: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    // 0x801A79D4: jal         0x80005680
    // 0x801A79D8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    Matrix_Copy(rdram, ctx);
        goto after_2;
    // 0x801A79D8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_2:
    // 0x801A79DC: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x801A79E0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A79E4: lwc1        $f8, 0x7990($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7990);
    // 0x801A79E8: lwc1        $f4, 0xC($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0XC);
    // 0x801A79EC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801A79F0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801A79F4: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x801A79F8: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x801A79FC: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x801A7A00: jal         0x80005FE0
    // 0x801A7A04: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_3;
    // 0x801A7A04: nop

    after_3:
    // 0x801A7A08: lui         $a1, 0x3EB2
    ctx->r5 = S32(0X3EB2 << 16);
    // 0x801A7A0C: ori         $a1, $a1, 0xB8C2
    ctx->r5 = ctx->r5 | 0XB8C2;
    // 0x801A7A10: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801A7A14: jal         0x80005D44
    // 0x801A7A18: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateX(rdram, ctx);
        goto after_4;
    // 0x801A7A18: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
    // 0x801A7A1C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801A7A20: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801A7A24: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801A7A28: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x801A7A2C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801A7A30: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801A7A34: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x801A7A38: jal         0x80005C34
    // 0x801A7A3C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_5;
    // 0x801A7A3C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_5:
    // 0x801A7A40: jal         0x80006EB8
    // 0x801A7A44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_6;
    // 0x801A7A44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x801A7A48: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801A7A4C: lui         $t4, 0x605
    ctx->r12 = S32(0X605 << 16);
    // 0x801A7A50: addiu       $t4, $t4, -0x3AC0
    ctx->r12 = ADD32(ctx->r12, -0X3AC0);
    // 0x801A7A54: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x801A7A58: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x801A7A5C: lui         $t3, 0x600
    ctx->r11 = S32(0X600 << 16);
    // 0x801A7A60: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x801A7A64: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x801A7A68: jal         0x80005740
    // 0x801A7A6C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_7;
    // 0x801A7A6C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_7:
    // 0x801A7A70: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801A7A74: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x801A7A78: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x801A7A7C: jr          $ra
    // 0x801A7A80: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x801A7A80: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void Title_SetCamUp3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80191320: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80191324: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80191328: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8019132C: beq         $a0, $zero, L_80191350
    if (ctx->r4 == 0) {
        // 0x80191330: lui         $s0, 0x8014
        ctx->r16 = S32(0X8014 << 16);
            goto L_80191350;
    }
    // 0x80191330: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x80191334: lw          $v0, 0x70($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X70);
    // 0x80191338: lw          $v1, 0x74($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X74);
    // 0x8019133C: lw          $t0, 0x78($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X78);
    // 0x80191340: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80191344: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80191348: b           L_80191380
    // 0x8019134C: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
        goto L_80191380;
    // 0x8019134C: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
L_80191350:
    // 0x80191350: lwc1        $f4, 0x84($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X84);
    // 0x80191354: lw          $t6, 0x70($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X70);
    // 0x80191358: lw          $t7, 0x74($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X74);
    // 0x8019135C: lw          $t8, 0x78($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X78);
    // 0x80191360: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x80191364: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x80191368: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x8019136C: or          $t0, $a3, $zero
    ctx->r8 = ctx->r7 | 0;
    // 0x80191370: swc1        $f6, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f6.u32l;
    // 0x80191374: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
    // 0x80191378: sw          $t7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r15;
    // 0x8019137C: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
L_80191380:
    // 0x80191380: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80191384: lwc1        $f8, 0x84($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X84);
    // 0x80191388: addiu       $s0, $s0, -0x4438
    ctx->r16 = ADD32(ctx->r16, -0X4438);
    // 0x8019138C: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x80191390: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x80191394: swc1        $f8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f8.u32l;
    // 0x80191398: lw          $a3, 0x0($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X0);
    // 0x8019139C: lw          $a2, 0x0($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X0);
    // 0x801913A0: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x801913A4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x801913A8: jal         0x80005B00
    // 0x801913AC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_0;
    // 0x801913AC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_0:
    // 0x801913B0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801913B4: lwc1        $f10, 0x70D8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X70D8);
    // 0x801913B8: lwc1        $f16, 0x80($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X80);
    // 0x801913BC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x801913C0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801913C4: mul.s       $f0, $f10, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x801913C8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801913CC: jal         0x80005E90
    // 0x801913D0: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    Matrix_RotateY(rdram, ctx);
        goto after_1;
    // 0x801913D0: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x801913D4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801913D8: lwc1        $f18, 0x70DC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X70DC);
    // 0x801913DC: lwc1        $f4, 0x7C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x801913E0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x801913E4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801913E8: mul.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x801913EC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801913F0: jal         0x80005D44
    // 0x801913F4: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    Matrix_RotateX(rdram, ctx);
        goto after_2;
    // 0x801913F4: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x801913F8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x801913FC: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x80191400: jal         0x80006970
    // 0x80191404: addiu       $a2, $sp, 0x54
    ctx->r6 = ADD32(ctx->r29, 0X54);
    Matrix_MultVec3f(rdram, ctx);
        goto after_3;
    // 0x80191404: addiu       $a2, $sp, 0x54
    ctx->r6 = ADD32(ctx->r29, 0X54);
    after_3:
    // 0x80191408: lwc1        $f6, 0x54($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8019140C: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x80191410: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80191414: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80191418: swc1        $f6, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f6.u32l;
    // 0x8019141C: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x80191420: lwc1        $f8, 0x58($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80191424: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80191428: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8019142C: swc1        $f8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f8.u32l;
    // 0x80191430: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x80191434: lwc1        $f10, 0x5C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80191438: swc1        $f10, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f10.u32l;
    // 0x8019143C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80191440: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80191444: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x80191448: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    // 0x8019144C: jal         0x80005E90
    // 0x80191450: swc1        $f16, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f16.u32l;
    Matrix_RotateY(rdram, ctx);
        goto after_4;
    // 0x80191450: swc1        $f16, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f16.u32l;
    after_4:
    // 0x80191454: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80191458: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8019145C: jal         0x80005D44
    // 0x80191460: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateX(rdram, ctx);
        goto after_5;
    // 0x80191460: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x80191464: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80191468: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x8019146C: jal         0x80006970
    // 0x80191470: addiu       $a2, $sp, 0x54
    ctx->r6 = ADD32(ctx->r29, 0X54);
    Matrix_MultVec3f(rdram, ctx);
        goto after_6;
    // 0x80191470: addiu       $a2, $sp, 0x54
    ctx->r6 = ADD32(ctx->r29, 0X54);
    after_6:
    // 0x80191474: lwc1        $f18, 0x54($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80191478: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8019147C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80191480: swc1        $f18, -0x7D64($at)
    MEM_W(-0X7D64, ctx->r1) = ctx->f18.u32l;
    // 0x80191484: lwc1        $f6, 0x5C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80191488: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019148C: swc1        $f4, -0x7D60($at)
    MEM_W(-0X7D60, ctx->r1) = ctx->f4.u32l;
    // 0x80191490: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80191494: swc1        $f6, -0x7D5C($at)
    MEM_W(-0X7D5C, ctx->r1) = ctx->f6.u32l;
    // 0x80191498: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8019149C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801914A0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x801914A4: jr          $ra
    // 0x801914A8: nop

    return;
    // 0x801914A8: nop

;}
RECOMP_FUNC void Title_Corneria_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DF0C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8018DF10: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8018DF14: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8018DF18: swc1        $f12, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f12.u32l;
    // 0x8018DF1C: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x8018DF20: jal         0x80191798
    // 0x8018DF24: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    Title_GetCamRot(rdram, ctx);
        goto after_0;
    // 0x8018DF24: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_0:
    // 0x8018DF28: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8018DF2C: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8018DF30: jal         0x800B8DD0
    // 0x8018DF34: addiu       $a1, $zero, 0x35
    ctx->r5 = ADD32(0, 0X35);
    RCP_SetupDL(rdram, ctx);
        goto after_1;
    // 0x8018DF34: addiu       $a1, $zero, 0x35
    ctx->r5 = ADD32(0, 0X35);
    after_1:
    // 0x8018DF38: lwc1        $f0, 0x38($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8018DF3C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8018DF40: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x8018DF44: addiu       $s0, $s0, -0x4C40
    ctx->r16 = ADD32(ctx->r16, -0X4C40);
    // 0x8018DF48: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x8018DF4C: nop

    // 0x8018DF50: bc1t        L_8018DF68
    if (c1cs) {
        // 0x8018DF54: lui         $at, 0x8017
        ctx->r1 = S32(0X8017 << 16);
            goto L_8018DF68;
    }
    // 0x8018DF54: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018DF58: lwc1        $f6, 0x7988($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7988);
    // 0x8018DF5C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018DF60: sub.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x8018DF64: swc1        $f8, -0x7970($at)
    MEM_W(-0X7970, ctx->r1) = ctx->f8.u32l;
L_8018DF68:
    // 0x8018DF68: jal         0x80005708
    // 0x8018DF6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_Push(rdram, ctx);
        goto after_2;
    // 0x8018DF6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8018DF70: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8018DF74: addiu       $v0, $v0, -0x7978
    ctx->r2 = ADD32(ctx->r2, -0X7978);
    // 0x8018DF78: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8018DF7C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8018DF80: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x8018DF84: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    // 0x8018DF88: lw          $a3, 0x8($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X8);
    // 0x8018DF8C: jal         0x80005B00
    // 0x8018DF90: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_3;
    // 0x8018DF90: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_3:
    // 0x8018DF94: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018DF98: lwc1        $f10, 0x7058($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7058);
    // 0x8018DF9C: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8018DFA0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8018DFA4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018DFA8: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8018DFAC: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8018DFB0: jal         0x80005E90
    // 0x8018DFB4: nop

    Matrix_RotateY(rdram, ctx);
        goto after_4;
    // 0x8018DFB4: nop

    after_4:
    // 0x8018DFB8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018DFBC: lwc1        $f4, 0x705C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X705C);
    // 0x8018DFC0: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8018DFC4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8018DFC8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018DFCC: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8018DFD0: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8018DFD4: jal         0x80005D44
    // 0x8018DFD8: nop

    Matrix_RotateX(rdram, ctx);
        goto after_5;
    // 0x8018DFD8: nop

    after_5:
    // 0x8018DFDC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018DFE0: lwc1        $f0, -0x7968($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7968);
    // 0x8018DFE4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8018DFE8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8018DFEC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8018DFF0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8018DFF4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8018DFF8: jal         0x80005C34
    // 0x8018DFFC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_6;
    // 0x8018DFFC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_6:
    // 0x8018E000: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8018E004: jal         0x80006EB8
    // 0x8018E008: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_7;
    // 0x8018E008: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    after_7:
    // 0x8018E00C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8018E010: lw          $v1, 0x7E64($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7E64);
    // 0x8018E014: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8018E018: lui         $t0, 0x603
    ctx->r8 = S32(0X603 << 16);
    // 0x8018E01C: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8018E020: sw          $t8, 0x7E64($at)
    MEM_W(0X7E64, ctx->r1) = ctx->r24;
    // 0x8018E024: addiu       $t0, $t0, 0x7CF0
    ctx->r8 = ADD32(ctx->r8, 0X7CF0);
    // 0x8018E028: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x8018E02C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8018E030: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x8018E034: jal         0x8018E200
    // 0x8018E038: nop

    Title_CorneriaExplosions_Draw(rdram, ctx);
        goto after_8;
    // 0x8018E038: nop

    after_8:
    // 0x8018E03C: jal         0x80005740
    // 0x8018E040: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_9;
    // 0x8018E040: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x8018E044: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8018E048: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8018E04C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8018E050: jr          $ra
    // 0x8018E054: nop

    return;
    // 0x8018E054: nop

;}
RECOMP_FUNC void Option_VersusStage_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019A0B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8019A0BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8019A0C0: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8019A0C4: lw          $v0, -0x6C30($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6C30);
    // 0x8019A0C8: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8019A0CC: beq         $v0, $at, L_8019A0EC
    if (ctx->r2 == ctx->r1) {
        // 0x8019A0D0: addiu       $at, $zero, 0x14
        ctx->r1 = ADD32(0, 0X14);
            goto L_8019A0EC;
    }
    // 0x8019A0D0: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x8019A0D4: beq         $v0, $at, L_8019A0FC
    if (ctx->r2 == ctx->r1) {
        // 0x8019A0D8: addiu       $at, $zero, 0x1E
        ctx->r1 = ADD32(0, 0X1E);
            goto L_8019A0FC;
    }
    // 0x8019A0D8: addiu       $at, $zero, 0x1E
    ctx->r1 = ADD32(0, 0X1E);
    // 0x8019A0DC: beq         $v0, $at, L_8019A10C
    if (ctx->r2 == ctx->r1) {
        // 0x8019A0E0: nop
    
            goto L_8019A10C;
    }
    // 0x8019A0E0: nop

    // 0x8019A0E4: b           L_8019A118
    // 0x8019A0E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8019A118;
    // 0x8019A0E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8019A0EC:
    // 0x8019A0EC: jal         0x8019A124
    // 0x8019A0F0: nop

    Option_Vs_PointMatch_Update(rdram, ctx);
        goto after_0;
    // 0x8019A0F0: nop

    after_0:
    // 0x8019A0F4: b           L_8019A118
    // 0x8019A0F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8019A118;
    // 0x8019A0F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8019A0FC:
    // 0x8019A0FC: jal         0x8019A1A8
    // 0x8019A100: nop

    Option_Vs_BattleRoyal_Update(rdram, ctx);
        goto after_1;
    // 0x8019A100: nop

    after_1:
    // 0x8019A104: b           L_8019A118
    // 0x8019A108: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8019A118;
    // 0x8019A108: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8019A10C:
    // 0x8019A10C: jal         0x8019A214
    // 0x8019A110: nop

    Option_Vs_TimeTrial_Update(rdram, ctx);
        goto after_2;
    // 0x8019A110: nop

    after_2:
    // 0x8019A114: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8019A118:
    // 0x8019A118: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8019A11C: jr          $ra
    // 0x8019A120: nop

    return;
    // 0x8019A120: nop

;}
RECOMP_FUNC void Option_Ranking_Setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80196E54: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80196E58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80196E5C: jal         0x80188010
    // 0x80196E60: nop

    Title_GetRankTotalHits(rdram, ctx);
        goto after_0;
    // 0x80196E60: nop

    after_0:
    // 0x80196E64: lui         $at, 0x42E4
    ctx->r1 = S32(0X42E4 << 16);
    // 0x80196E68: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80196E6C: lui         $at, 0xC0C0
    ctx->r1 = S32(0XC0C0 << 16);
    // 0x80196E70: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80196E74: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80196E78: addiu       $t6, $zero, 0x320
    ctx->r14 = ADD32(0, 0X320);
    // 0x80196E7C: sw          $t6, -0x7BF0($at)
    MEM_W(-0X7BF0, ctx->r1) = ctx->r14;
    // 0x80196E80: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80196E84: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80196E88: sw          $t7, -0x6E30($at)
    MEM_W(-0X6E30, ctx->r1) = ctx->r15;
    // 0x80196E8C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80196E90: sw          $zero, -0x6C1C($at)
    MEM_W(-0X6C1C, ctx->r1) = 0;
    // 0x80196E94: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80196E98: swc1        $f0, -0x6E2C($at)
    MEM_W(-0X6E2C, ctx->r1) = ctx->f0.u32l;
    // 0x80196E9C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80196EA0: swc1        $f0, -0x6E24($at)
    MEM_W(-0X6E24, ctx->r1) = ctx->f0.u32l;
    // 0x80196EA4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80196EA8: swc1        $f2, -0x6E28($at)
    MEM_W(-0X6E28, ctx->r1) = ctx->f2.u32l;
    // 0x80196EAC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80196EB0: swc1        $f2, -0x6E20($at)
    MEM_W(-0X6E20, ctx->r1) = ctx->f2.u32l;
    // 0x80196EB4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80196EB8: sw          $zero, -0x6C20($at)
    MEM_W(-0X6C20, ctx->r1) = 0;
    // 0x80196EBC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80196EC0: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x80196EC4: sw          $t8, -0x7D78($at)
    MEM_W(-0X7D78, ctx->r1) = ctx->r24;
    // 0x80196EC8: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80196ECC: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80196ED0: addiu       $v1, $v1, -0x6BF8
    ctx->r3 = ADD32(ctx->r3, -0X6BF8);
    // 0x80196ED4: addiu       $v0, $v0, -0x6C00
    ctx->r2 = ADD32(ctx->r2, -0X6C00);
    // 0x80196ED8: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x80196EDC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80196EE0: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x80196EE4: jal         0x80192598
    // 0x80196EE8: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    Option_PlanetTextures_Setup(rdram, ctx);
        goto after_1;
    // 0x80196EE8: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    after_1:
    // 0x80196EEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80196EF0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80196EF4: jr          $ra
    // 0x80196EF8: nop

    return;
    // 0x80196EF8: nop

;}
RECOMP_FUNC void Map_801A4394(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A4394: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801A4398: addiu       $v1, $v1, -0x26B4
    ctx->r3 = ADD32(ctx->r3, -0X26B4);
    // 0x801A439C: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x801A43A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801A43A4: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x801A43A8: beq         $a1, $zero, L_801A43D4
    if (ctx->r5 == 0) {
        // 0x801A43AC: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_801A43D4;
    }
    // 0x801A43AC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x801A43B0: beq         $a0, $v0, L_801A4404
    if (ctx->r4 == ctx->r2) {
        // 0x801A43B4: lui         $a2, 0x801D
        ctx->r6 = S32(0X801D << 16);
            goto L_801A4404;
    }
    // 0x801A43B4: lui         $a2, 0x801D
    ctx->r6 = S32(0X801D << 16);
    // 0x801A43B8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801A43BC: beq         $a0, $at, L_801A44CC
    if (ctx->r4 == ctx->r1) {
        // 0x801A43C0: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_801A44CC;
    }
    // 0x801A43C0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801A43C4: beq         $a0, $at, L_801A4518
    if (ctx->r4 == ctx->r1) {
        // 0x801A43C8: nop
    
            goto L_801A4518;
    }
    // 0x801A43C8: nop

    // 0x801A43CC: jr          $ra
    // 0x801A43D0: nop

    return;
    // 0x801A43D0: nop

L_801A43D4:
    // 0x801A43D4: lw          $t6, 0x7B48($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7B48);
    // 0x801A43D8: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x801A43DC: addiu       $a0, $a0, -0x2640
    ctx->r4 = ADD32(ctx->r4, -0X2640);
    // 0x801A43E0: bne         $t6, $zero, L_801A43F8
    if (ctx->r14 != 0) {
        // 0x801A43E4: addiu       $t7, $zero, 0x2D
        ctx->r15 = ADD32(0, 0X2D);
            goto L_801A43F8;
    }
    // 0x801A43E4: addiu       $t7, $zero, 0x2D
    ctx->r15 = ADD32(0, 0X2D);
    // 0x801A43E8: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x801A43EC: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x801A43F0: jr          $ra
    // 0x801A43F4: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    return;
    // 0x801A43F4: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
L_801A43F8:
    // 0x801A43F8: addiu       $t9, $a1, 0x1
    ctx->r25 = ADD32(ctx->r5, 0X1);
    // 0x801A43FC: jr          $ra
    // 0x801A4400: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    return;
    // 0x801A4400: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
L_801A4404:
    // 0x801A4404: addiu       $a2, $a2, -0x2654
    ctx->r6 = ADD32(ctx->r6, -0X2654);
    // 0x801A4408: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x801A440C: lw          $t4, 0x7B48($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7B48);
    // 0x801A4410: lw          $a0, 0x0($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X0);
    // 0x801A4414: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x801A4418: addiu       $t6, $zero, 0x2D
    ctx->r14 = ADD32(0, 0X2D);
    // 0x801A441C: bnel        $a0, $t4, L_801A443C
    if (ctx->r4 != ctx->r12) {
        // 0x801A4420: sll         $t7, $a0, 2
        ctx->r15 = S32(ctx->r4 << 2);
            goto L_801A443C;
    }
    goto skip_0;
    // 0x801A4420: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    skip_0:
    // 0x801A4424: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x801A4428: addiu       $a0, $a0, -0x2640
    ctx->r4 = ADD32(ctx->r4, -0X2640);
    // 0x801A442C: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x801A4430: jr          $ra
    // 0x801A4434: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    return;
    // 0x801A4434: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x801A4438: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
L_801A443C:
    // 0x801A443C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801A4440: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x801A4444: lw          $v0, -0x2720($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2720);
    // 0x801A4448: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x801A444C: addiu       $t9, $t9, -0x2E8
    ctx->r25 = ADD32(ctx->r25, -0X2E8);
    // 0x801A4450: sll         $t8, $v0, 3
    ctx->r24 = S32(ctx->r2 << 3);
    // 0x801A4454: subu        $t8, $t8, $v0
    ctx->r24 = SUB32(ctx->r24, ctx->r2);
    // 0x801A4458: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x801A445C: addu        $a2, $t8, $t9
    ctx->r6 = ADD32(ctx->r24, ctx->r25);
    // 0x801A4460: lw          $a3, 0x0($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X0);
    // 0x801A4464: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801A4468: addiu       $t7, $a1, 0x1
    ctx->r15 = ADD32(ctx->r5, 0X1);
    // 0x801A446C: beq         $a3, $at, L_801A447C
    if (ctx->r7 == ctx->r1) {
        // 0x801A4470: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_801A447C;
    }
    // 0x801A4470: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x801A4474: bne         $a3, $at, L_801A4498
    if (ctx->r7 != ctx->r1) {
        // 0x801A4478: addiu       $t5, $zero, 0x2
        ctx->r13 = ADD32(0, 0X2);
            goto L_801A4498;
    }
    // 0x801A4478: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
L_801A447C:
    // 0x801A447C: sll         $t4, $v0, 2
    ctx->r12 = S32(ctx->r2 << 2);
    // 0x801A4480: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801A4484: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x801A4488: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x801A448C: sw          $a0, 0x7BD8($at)
    MEM_W(0X7BD8, ctx->r1) = ctx->r4;
    // 0x801A4490: b           L_801A44AC
    // 0x801A4494: sw          $a0, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->r4;
        goto L_801A44AC;
    // 0x801A4494: sw          $a0, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->r4;
L_801A4498:
    // 0x801A4498: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x801A449C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801A44A0: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x801A44A4: sw          $t5, 0x7BD8($at)
    MEM_W(0X7BD8, ctx->r1) = ctx->r13;
    // 0x801A44A8: sw          $zero, 0x14($a2)
    MEM_W(0X14, ctx->r6) = 0;
L_801A44AC:
    // 0x801A44AC: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x801A44B0: sw          $v0, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->r2;
    // 0x801A44B4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A44B8: sw          $v0, -0x1154($at)
    MEM_W(-0X1154, ctx->r1) = ctx->r2;
    // 0x801A44BC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A44C0: sw          $v0, -0x1158($at)
    MEM_W(-0X1158, ctx->r1) = ctx->r2;
    // 0x801A44C4: jr          $ra
    // 0x801A44C8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    return;
    // 0x801A44C8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
L_801A44CC:
    // 0x801A44CC: lui         $a2, 0x801D
    ctx->r6 = S32(0X801D << 16);
    // 0x801A44D0: addiu       $a2, $a2, -0x2654
    ctx->r6 = ADD32(ctx->r6, -0X2654);
    // 0x801A44D4: lw          $a0, 0x0($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X0);
    // 0x801A44D8: lui         $t9, 0x801D
    ctx->r25 = S32(0X801D << 16);
    // 0x801A44DC: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x801A44E0: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x801A44E4: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x801A44E8: lw          $t9, -0x2720($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2720);
    // 0x801A44EC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801A44F0: sll         $t4, $t9, 2
    ctx->r12 = S32(ctx->r25 << 2);
    // 0x801A44F4: addu        $a1, $a1, $t4
    ctx->r5 = ADD32(ctx->r5, ctx->r12);
    // 0x801A44F8: lw          $a1, 0x7BD8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7BD8);
    // 0x801A44FC: beq         $a1, $at, L_801A4508
    if (ctx->r5 == ctx->r1) {
        // 0x801A4500: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_801A4508;
    }
    // 0x801A4500: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x801A4504: bne         $a1, $at, L_801A4648
    if (ctx->r5 != ctx->r1) {
        // 0x801A4508: addiu       $t5, $a0, 0x1
        ctx->r13 = ADD32(ctx->r4, 0X1);
            goto L_801A4648;
    }
L_801A4508:
    // 0x801A4508: addiu       $t5, $a0, 0x1
    ctx->r13 = ADD32(ctx->r4, 0X1);
    // 0x801A450C: sw          $t5, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r13;
    // 0x801A4510: jr          $ra
    // 0x801A4514: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    return;
    // 0x801A4514: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_801A4518:
    // 0x801A4518: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x801A451C: addiu       $a0, $a0, -0x2640
    ctx->r4 = ADD32(ctx->r4, -0X2640);
    // 0x801A4520: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x801A4524: lui         $a2, 0x801D
    ctx->r6 = S32(0X801D << 16);
    // 0x801A4528: addiu       $a2, $a2, -0xFE0
    ctx->r6 = ADD32(ctx->r6, -0XFE0);
    // 0x801A452C: bne         $t6, $zero, L_801A4648
    if (ctx->r14 != 0) {
        // 0x801A4530: lui         $a3, 0x801B
        ctx->r7 = S32(0X801B << 16);
            goto L_801A4648;
    }
    // 0x801A4530: lui         $a3, 0x801B
    ctx->r7 = S32(0X801B << 16);
    // 0x801A4534: lui         $t0, 0x801D
    ctx->r8 = S32(0X801D << 16);
    // 0x801A4538: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x801A453C: lui         $t2, 0x801D
    ctx->r10 = S32(0X801D << 16);
    // 0x801A4540: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x801A4544: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x801A4548: addiu       $a1, $a1, 0x6A34
    ctx->r5 = ADD32(ctx->r5, 0X6A34);
    // 0x801A454C: addiu       $t3, $t3, 0x6A14
    ctx->r11 = ADD32(ctx->r11, 0X6A14);
    // 0x801A4550: addiu       $t2, $t2, -0xFA0
    ctx->r10 = ADD32(ctx->r10, -0XFA0);
    // 0x801A4554: addiu       $t1, $t1, 0x69F4
    ctx->r9 = ADD32(ctx->r9, 0X69F4);
    // 0x801A4558: addiu       $t0, $t0, -0xFC0
    ctx->r8 = ADD32(ctx->r8, -0XFC0);
    // 0x801A455C: addiu       $a3, $a3, 0x69D4
    ctx->r7 = ADD32(ctx->r7, 0X69D4);
L_801A4560:
    // 0x801A4560: lwc1        $f10, 0x4($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X4);
    // 0x801A4564: lwc1        $f16, 0x4($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0X4);
    // 0x801A4568: lwc1        $f18, 0x4($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0X4);
    // 0x801A456C: lwc1        $f4, 0x0($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X0);
    // 0x801A4570: lwc1        $f6, 0x0($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X0);
    // 0x801A4574: lwc1        $f8, 0x0($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0X0);
    // 0x801A4578: swc1        $f10, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f10.u32l;
    // 0x801A457C: swc1        $f16, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f16.u32l;
    // 0x801A4580: swc1        $f18, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->f18.u32l;
    // 0x801A4584: swc1        $f4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f4.u32l;
    // 0x801A4588: swc1        $f6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f6.u32l;
    // 0x801A458C: swc1        $f8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f8.u32l;
    // 0x801A4590: lwc1        $f8, 0x8($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0X8);
    // 0x801A4594: lwc1        $f6, 0x8($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X8);
    // 0x801A4598: lwc1        $f4, 0x8($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X8);
    // 0x801A459C: lwc1        $f18, 0xC($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0XC);
    // 0x801A45A0: lwc1        $f16, 0xC($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0XC);
    // 0x801A45A4: lwc1        $f10, 0xC($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0XC);
    // 0x801A45A8: addiu       $t3, $t3, 0x10
    ctx->r11 = ADD32(ctx->r11, 0X10);
    // 0x801A45AC: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x801A45B0: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x801A45B4: addiu       $t0, $t0, 0x10
    ctx->r8 = ADD32(ctx->r8, 0X10);
    // 0x801A45B8: addiu       $t1, $t1, 0x10
    ctx->r9 = ADD32(ctx->r9, 0X10);
    // 0x801A45BC: addiu       $t2, $t2, 0x10
    ctx->r10 = ADD32(ctx->r10, 0X10);
    // 0x801A45C0: swc1        $f8, -0x8($t2)
    MEM_W(-0X8, ctx->r10) = ctx->f8.u32l;
    // 0x801A45C4: swc1        $f6, -0x8($t0)
    MEM_W(-0X8, ctx->r8) = ctx->f6.u32l;
    // 0x801A45C8: swc1        $f4, -0x8($a2)
    MEM_W(-0X8, ctx->r6) = ctx->f4.u32l;
    // 0x801A45CC: swc1        $f18, -0x4($t2)
    MEM_W(-0X4, ctx->r10) = ctx->f18.u32l;
    // 0x801A45D0: swc1        $f16, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->f16.u32l;
    // 0x801A45D4: bne         $t3, $a1, L_801A4560
    if (ctx->r11 != ctx->r5) {
        // 0x801A45D8: swc1        $f10, -0x4($a2)
        MEM_W(-0X4, ctx->r6) = ctx->f10.u32l;
            goto L_801A4560;
    }
    // 0x801A45D8: swc1        $f10, -0x4($a2)
    MEM_W(-0X4, ctx->r6) = ctx->f10.u32l;
    // 0x801A45DC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A45E0: sw          $v0, -0x2688($at)
    MEM_W(-0X2688, ctx->r1) = ctx->r2;
    // 0x801A45E4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A45E8: sw          $v0, -0xEE0($at)
    MEM_W(-0XEE0, ctx->r1) = ctx->r2;
    // 0x801A45EC: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x801A45F0: lw          $t7, 0x6A38($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6A38);
    // 0x801A45F4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A45F8: sw          $v0, -0xEE4($at)
    MEM_W(-0XEE4, ctx->r1) = ctx->r2;
    // 0x801A45FC: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x801A4600: lw          $t8, 0x6A40($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6A40);
    // 0x801A4604: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A4608: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x801A460C: sw          $t7, -0xF38($at)
    MEM_W(-0XF38, ctx->r1) = ctx->r15;
    // 0x801A4610: lw          $t9, 0x6A48($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6A48);
    // 0x801A4614: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A4618: sw          $t8, -0xF34($at)
    MEM_W(-0XF34, ctx->r1) = ctx->r24;
    // 0x801A461C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A4620: sw          $t9, -0xF30($at)
    MEM_W(-0XF30, ctx->r1) = ctx->r25;
    // 0x801A4624: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801A4628: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801A462C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A4630: addiu       $t4, $zero, 0x1C2
    ctx->r12 = ADD32(0, 0X1C2);
    // 0x801A4634: swc1        $f4, -0xF80($at)
    MEM_W(-0XF80, ctx->r1) = ctx->f4.u32l;
    // 0x801A4638: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x801A463C: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x801A4640: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A4644: sw          $v0, -0x26B8($at)
    MEM_W(-0X26B8, ctx->r1) = ctx->r2;
L_801A4648:
    // 0x801A4648: jr          $ra
    // 0x801A464C: nop

    return;
    // 0x801A464C: nop

;}
RECOMP_FUNC void Title_Screen_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80189208: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8018920C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80189210: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x80189214: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x80189218: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8018921C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80189220: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x80189224: lw          $t6, -0x7D08($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7D08);
    // 0x80189228: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x8018922C: lw          $t7, -0x7D04($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7D04);
    // 0x80189230: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80189234: lui         $t8, 0x801C
    ctx->r24 = S32(0X801C << 16);
    // 0x80189238: sw          $t6, -0x7AB8($at)
    MEM_W(-0X7AB8, ctx->r1) = ctx->r14;
    // 0x8018923C: lw          $t8, -0x7D00($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7D00);
    // 0x80189240: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80189244: sw          $t7, -0x7AB4($at)
    MEM_W(-0X7AB4, ctx->r1) = ctx->r15;
    // 0x80189248: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018924C: sw          $t8, -0x7AB0($at)
    MEM_W(-0X7AB0, ctx->r1) = ctx->r24;
    // 0x80189250: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80189254: lwc1        $f4, -0x7CFC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7CFC);
    // 0x80189258: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018925C: lui         $t5, 0x801C
    ctx->r13 = S32(0X801C << 16);
    // 0x80189260: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80189264: lw          $t5, -0x795C($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X795C);
    // 0x80189268: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x8018926C: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    // 0x80189270: nop

    // 0x80189274: sw          $t0, -0x7AAC($at)
    MEM_W(-0X7AAC, ctx->r1) = ctx->r8;
    // 0x80189278: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018927C: lwc1        $f8, -0x7CF8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X7CF8);
    // 0x80189280: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80189284: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80189288: mfc1        $t2, $f10
    ctx->r10 = (int32_t)ctx->f10.u32l;
    // 0x8018928C: nop

    // 0x80189290: sw          $t2, -0x7AA8($at)
    MEM_W(-0X7AA8, ctx->r1) = ctx->r10;
    // 0x80189294: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80189298: lwc1        $f18, -0x7CF4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X7CF4);
    // 0x8018929C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801892A0: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x801892A4: mfc1        $t4, $f4
    ctx->r12 = (int32_t)ctx->f4.u32l;
    // 0x801892A8: nop

    // 0x801892AC: sw          $t4, -0x7AA4($at)
    MEM_W(-0X7AA4, ctx->r1) = ctx->r12;
    // 0x801892B0: slti        $at, $t5, 0x2
    ctx->r1 = SIGNED(ctx->r13) < 0X2 ? 1 : 0;
    // 0x801892B4: beq         $at, $zero, L_801893A8
    if (ctx->r1 == 0) {
        // 0x801892B8: nop
    
            goto L_801893A8;
    }
    // 0x801892B8: nop

    // 0x801892BC: lw          $t6, -0x6FC0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6FC0);
    // 0x801892C0: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x801892C4: addiu       $s0, $s0, -0x6FA4
    ctx->r16 = ADD32(ctx->r16, -0X6FA4);
    // 0x801892C8: beq         $t6, $zero, L_801893A8
    if (ctx->r14 == 0) {
        // 0x801892CC: lui         $s1, 0x801C
        ctx->r17 = S32(0X801C << 16);
            goto L_801893A8;
    }
    // 0x801892CC: lui         $s1, 0x801C
    ctx->r17 = S32(0X801C << 16);
    // 0x801892D0: lwc1        $f2, 0x0($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X0);
    // 0x801892D4: addiu       $s1, $s1, -0x6F9C
    ctx->r17 = ADD32(ctx->r17, -0X6F9C);
    // 0x801892D8: lwc1        $f16, 0x0($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X0);
    // 0x801892DC: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x801892E0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801892E4: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x801892E8: neg.s       $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = -ctx->f16.fl;
    // 0x801892EC: lwc1        $f12, -0x6FA0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X6FA0);
    // 0x801892F0: mul.s       $f8, $f16, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x801892F4: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    // 0x801892F8: add.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801892FC: jal         0x80005100
    // 0x80189300: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    Math_Atan2F(rdram, ctx);
        goto after_0;
    // 0x80189300: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    after_0:
    // 0x80189304: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80189308: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018930C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80189310: lwc1        $f4, 0x6E5C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6E5C);
    // 0x80189314: mul.s       $f18, $f0, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80189318: lui         $s2, 0x801C
    ctx->r18 = S32(0X801C << 16);
    // 0x8018931C: addiu       $s2, $s2, -0x7928
    ctx->r18 = ADD32(ctx->r18, -0X7928);
    // 0x80189320: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80189324: lwc1        $f14, 0x0($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80189328: div.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8018932C: jal         0x80005100
    // 0x80189330: swc1        $f6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f6.u32l;
    Math_Atan2F(rdram, ctx);
        goto after_1;
    // 0x80189330: swc1        $f6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f6.u32l;
    after_1:
    // 0x80189334: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80189338: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018933C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80189340: lwc1        $f18, 0x6E60($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6E60);
    // 0x80189344: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80189348: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x8018934C: addiu       $s0, $s0, -0x7924
    ctx->r16 = ADD32(ctx->r16, -0X7924);
    // 0x80189350: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80189354: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80189358: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8018935C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80189360: div.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80189364: addiu       $a0, $a0, -0x7938
    ctx->r4 = ADD32(ctx->r4, -0X7938);
    // 0x80189368: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    // 0x8018936C: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x80189370: swc1        $f4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f4.u32l;
    // 0x80189374: lwc1        $f6, 0x6E64($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6E64);
    // 0x80189378: jal         0x8009BC2C
    // 0x8018937C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_2;
    // 0x8018937C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x80189380: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80189384: lwc1        $f8, 0x6E68($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6E68);
    // 0x80189388: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8018938C: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80189390: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80189394: addiu       $a0, $a0, -0x7934
    ctx->r4 = ADD32(ctx->r4, -0X7934);
    // 0x80189398: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x8018939C: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x801893A0: jal         0x8009BC2C
    // 0x801893A4: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_3;
    // 0x801893A4: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_3:
L_801893A8:
    // 0x801893A8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801893AC: lwc1        $f12, -0x7938($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X7938);
    // 0x801893B0: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x801893B4: lui         $t8, 0x801C
    ctx->r24 = S32(0X801C << 16);
    // 0x801893B8: addiu       $t8, $t8, -0x7D18
    ctx->r24 = ADD32(ctx->r24, -0X7D18);
    // 0x801893BC: addiu       $t7, $t7, -0x7D1C
    ctx->r15 = ADD32(ctx->r15, -0X7D1C);
    // 0x801893C0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801893C4: lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // 0x801893C8: addiu       $a3, $a3, -0x7D20
    ctx->r7 = ADD32(ctx->r7, -0X7D20);
    // 0x801893CC: lwc1        $f14, -0x7934($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X7934);
    // 0x801893D0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801893D4: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x801893D8: jal         0x80191674
    // 0x801893DC: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    Title_SetLightRot(rdram, ctx);
        goto after_4;
    // 0x801893DC: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    after_4:
    // 0x801893E0: lui         $s0, 0x801B
    ctx->r16 = S32(0X801B << 16);
    // 0x801893E4: lui         $s3, 0x801B
    ctx->r19 = S32(0X801B << 16);
    // 0x801893E8: lui         $s1, 0x801C
    ctx->r17 = S32(0X801C << 16);
    // 0x801893EC: addiu       $s1, $s1, -0x7CB0
    ctx->r17 = ADD32(ctx->r17, -0X7CB0);
    // 0x801893F0: addiu       $s3, $s3, -0x256C
    ctx->r19 = ADD32(ctx->r19, -0X256C);
    // 0x801893F4: addiu       $s0, $s0, -0x257C
    ctx->r16 = ADD32(ctx->r16, -0X257C);
    // 0x801893F8: addiu       $s2, $zero, 0x60
    ctx->r18 = ADD32(0, 0X60);
L_801893FC:
    // 0x801893FC: jal         0x8018EA78
    // 0x80189400: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    Title_Team_Draw(rdram, ctx);
        goto after_5;
    // 0x80189400: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_5:
    // 0x80189404: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80189408: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8018940C: multu       $t9, $s2
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80189410: mflo        $t0
    ctx->r8 = lo;
    // 0x80189414: addu        $v0, $s1, $t0
    ctx->r2 = ADD32(ctx->r17, ctx->r8);
    // 0x80189418: lw          $t1, 0x58($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X58);
    // 0x8018941C: lw          $t2, 0x5C($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X5C);
    // 0x80189420: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x80189424: bne         $s0, $s3, L_801893FC
    if (ctx->r16 != ctx->r19) {
        // 0x80189428: sw          $t3, 0x58($v0)
        MEM_W(0X58, ctx->r2) = ctx->r11;
            goto L_801893FC;
    }
    // 0x80189428: sw          $t3, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->r11;
    // 0x8018942C: lui         $t4, 0x801C
    ctx->r12 = S32(0X801C << 16);
    // 0x80189430: lw          $t4, -0x7CF0($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7CF0);
    // 0x80189434: lui         $t5, 0x801C
    ctx->r13 = S32(0X801C << 16);
    // 0x80189438: lw          $t5, -0x7CEC($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X7CEC);
    // 0x8018943C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80189440: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x80189444: sw          $t4, -0x7AB8($at)
    MEM_W(-0X7AB8, ctx->r1) = ctx->r12;
    // 0x80189448: lw          $t6, -0x7CE8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7CE8);
    // 0x8018944C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80189450: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x80189454: sw          $t5, -0x7AB4($at)
    MEM_W(-0X7AB4, ctx->r1) = ctx->r13;
    // 0x80189458: lw          $t7, -0x7CE4($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7CE4);
    // 0x8018945C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80189460: lui         $t8, 0x801C
    ctx->r24 = S32(0X801C << 16);
    // 0x80189464: sw          $t6, -0x7AB0($at)
    MEM_W(-0X7AB0, ctx->r1) = ctx->r14;
    // 0x80189468: lw          $t8, -0x7CE0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7CE0);
    // 0x8018946C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80189470: lui         $t9, 0x801C
    ctx->r25 = S32(0X801C << 16);
    // 0x80189474: sw          $t7, -0x7AAC($at)
    MEM_W(-0X7AAC, ctx->r1) = ctx->r15;
    // 0x80189478: lw          $t9, -0x7CDC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7CDC);
    // 0x8018947C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80189480: sw          $t8, -0x7AA8($at)
    MEM_W(-0X7AA8, ctx->r1) = ctx->r24;
    // 0x80189484: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80189488: sw          $t9, -0x7AA4($at)
    MEM_W(-0X7AA4, ctx->r1) = ctx->r25;
    // 0x8018948C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80189490: lwc1        $f12, -0x7930($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X7930);
    // 0x80189494: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x80189498: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x8018949C: addiu       $t1, $t1, -0x7D18
    ctx->r9 = ADD32(ctx->r9, -0X7D18);
    // 0x801894A0: addiu       $t0, $t0, -0x7D1C
    ctx->r8 = ADD32(ctx->r8, -0X7D1C);
    // 0x801894A4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801894A8: lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // 0x801894AC: addiu       $a3, $a3, -0x7D20
    ctx->r7 = ADD32(ctx->r7, -0X7D20);
    // 0x801894B0: lwc1        $f14, -0x792C($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X792C);
    // 0x801894B4: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x801894B8: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x801894BC: jal         0x80191674
    // 0x801894C0: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    Title_SetLightRot(rdram, ctx);
        goto after_6;
    // 0x801894C0: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    after_6:
    // 0x801894C4: jal         0x8018D2B8
    // 0x801894C8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    Title_Arwing_Draw(rdram, ctx);
        goto after_7;
    // 0x801894C8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_7:
    // 0x801894CC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x801894D0: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x801894D4: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x801894D8: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x801894DC: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x801894E0: jr          $ra
    // 0x801894E4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x801894E4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void Map_RestartLevelLifeDown_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A5C90: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x801A5C94: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x801A5C98: addiu       $a0, $a0, -0x2634
    ctx->r4 = ADD32(ctx->r4, -0X2634);
    // 0x801A5C9C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x801A5CA0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x801A5CA4: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x801A5CA8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801A5CAC: beql        $v0, $zero, L_801A5E74
    if (ctx->r2 == 0) {
        // 0x801A5CB0: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_801A5E74;
    }
    goto skip_0;
    // 0x801A5CB0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_0:
    // 0x801A5CB4: lw          $t6, 0x78A0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X78A0);
    // 0x801A5CB8: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x801A5CBC: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x801A5CC0: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x801A5CC4: lh          $t8, 0x1AA0($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X1AA0);
    // 0x801A5CC8: slti        $at, $t8, 0xA
    ctx->r1 = SIGNED(ctx->r24) < 0XA ? 1 : 0;
    // 0x801A5CCC: beq         $at, $zero, L_801A5CE0
    if (ctx->r1 == 0) {
        // 0x801A5CD0: lui         $at, 0x801B
        ctx->r1 = S32(0X801B << 16);
            goto L_801A5CE0;
    }
    // 0x801A5CD0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A5CD4: lwc1        $f4, 0x7808($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7808);
    // 0x801A5CD8: b           L_801A5CEC
    // 0x801A5CDC: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
        goto L_801A5CEC;
    // 0x801A5CDC: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
L_801A5CE0:
    // 0x801A5CE0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A5CE4: lwc1        $f6, 0x780C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X780C);
    // 0x801A5CE8: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
L_801A5CEC:
    // 0x801A5CEC: beq         $v0, $a1, L_801A5D08
    if (ctx->r2 == ctx->r5) {
        // 0x801A5CF0: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_801A5D08;
    }
    // 0x801A5CF0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x801A5CF4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x801A5CF8: beq         $v1, $v0, L_801A5D1C
    if (ctx->r3 == ctx->r2) {
        // 0x801A5CFC: lui         $t9, 0x801D
        ctx->r25 = S32(0X801D << 16);
            goto L_801A5D1C;
    }
    // 0x801A5CFC: lui         $t9, 0x801D
    ctx->r25 = S32(0X801D << 16);
    // 0x801A5D00: b           L_801A5D60
    // 0x801A5D04: nop

        goto L_801A5D60;
    // 0x801A5D04: nop

L_801A5D08:
    // 0x801A5D08: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x801A5D0C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A5D10: sw          $v0, -0x2640($at)
    MEM_W(-0X2640, ctx->r1) = ctx->r2;
    // 0x801A5D14: b           L_801A5D60
    // 0x801A5D18: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
        goto L_801A5D60;
    // 0x801A5D18: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
L_801A5D1C:
    // 0x801A5D1C: lw          $t9, -0x2640($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2640);
    // 0x801A5D20: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801A5D24: addiu       $v1, $v1, -0x2630
    ctx->r3 = ADD32(ctx->r3, -0X2630);
    // 0x801A5D28: beql        $t9, $zero, L_801A5D3C
    if (ctx->r25 == 0) {
        // 0x801A5D2C: lw          $v0, 0x0($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X0);
            goto L_801A5D3C;
    }
    goto skip_1;
    // 0x801A5D2C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    skip_1:
    // 0x801A5D30: b           L_801A5D60
    // 0x801A5D34: nop

        goto L_801A5D60;
    // 0x801A5D34: nop

    // 0x801A5D38: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
L_801A5D3C:
    // 0x801A5D3C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x801A5D40: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x801A5D44: bnel        $at, $zero, L_801A5D5C
    if (ctx->r1 != 0) {
        // 0x801A5D48: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_801A5D5C;
    }
    goto skip_2;
    // 0x801A5D48: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    skip_2:
    // 0x801A5D4C: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x801A5D50: b           L_801A5D60
    // 0x801A5D54: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
        goto L_801A5D60;
    // 0x801A5D54: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x801A5D58: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_801A5D5C:
    // 0x801A5D5C: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
L_801A5D60:
    // 0x801A5D60: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A5D64: jal         0x80005708
    // 0x801A5D68: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Push(rdram, ctx);
        goto after_0;
    // 0x801A5D68: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_0:
    // 0x801A5D6C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801A5D70: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801A5D74: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801A5D78: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A5D7C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801A5D80: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801A5D84: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801A5D88: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x801A5D8C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x801A5D90: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x801A5D94: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x801A5D98: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x801A5D9C: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x801A5DA0: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x801A5DA4: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x801A5DA8: jal         0x80006E3C
    // 0x801A5DAC: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    Matrix_LookAt(rdram, ctx);
        goto after_1;
    // 0x801A5DAC: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x801A5DB0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801A5DB4: jal         0x80006EB8
    // 0x801A5DB8: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_2;
    // 0x801A5DB8: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    after_2:
    // 0x801A5DBC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801A5DC0: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x801A5DC4: jal         0x800B8DD0
    // 0x801A5DC8: addiu       $a1, $zero, 0x35
    ctx->r5 = ADD32(0, 0X35);
    RCP_SetupDL(rdram, ctx);
        goto after_3;
    // 0x801A5DC8: addiu       $a1, $zero, 0x35
    ctx->r5 = ADD32(0, 0X35);
    after_3:
    // 0x801A5DCC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A5DD0: jal         0x80005708
    // 0x801A5DD4: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Push(rdram, ctx);
        goto after_4;
    // 0x801A5DD4: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_4:
    // 0x801A5DD8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A5DDC: lui         $a3, 0x3C23
    ctx->r7 = S32(0X3C23 << 16);
    // 0x801A5DE0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801A5DE4: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x801A5DE8: ori         $a3, $a3, 0xD70A
    ctx->r7 = ctx->r7 | 0XD70A;
    // 0x801A5DEC: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x801A5DF0: lui         $a1, 0x4234
    ctx->r5 = S32(0X4234 << 16);
    // 0x801A5DF4: jal         0x80005B00
    // 0x801A5DF8: lui         $a2, 0x4200
    ctx->r6 = S32(0X4200 << 16);
    Matrix_Translate(rdram, ctx);
        goto after_5;
    // 0x801A5DF8: lui         $a2, 0x4200
    ctx->r6 = S32(0X4200 << 16);
    after_5:
    // 0x801A5DFC: lwc1        $f0, 0x38($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X38);
    // 0x801A5E00: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A5E04: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801A5E08: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801A5E0C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801A5E10: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x801A5E14: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x801A5E18: jal         0x80005C34
    // 0x801A5E1C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Scale(rdram, ctx);
        goto after_6;
    // 0x801A5E1C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_6:
    // 0x801A5E20: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801A5E24: jal         0x80006EB8
    // 0x801A5E28: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_7;
    // 0x801A5E28: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    after_7:
    // 0x801A5E2C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x801A5E30: lw          $v1, 0x7E64($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7E64);
    // 0x801A5E34: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801A5E38: lui         $t4, 0x600
    ctx->r12 = S32(0X600 << 16);
    // 0x801A5E3C: addiu       $t3, $v1, 0x8
    ctx->r11 = ADD32(ctx->r3, 0X8);
    // 0x801A5E40: sw          $t3, 0x7E64($at)
    MEM_W(0X7E64, ctx->r1) = ctx->r11;
    // 0x801A5E44: lui         $t5, 0x801D
    ctx->r13 = S32(0X801D << 16);
    // 0x801A5E48: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x801A5E4C: lw          $t5, -0x2630($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2630);
    // 0x801A5E50: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x801A5E54: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A5E58: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x801A5E5C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x801A5E60: lw          $t7, -0x7DC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7DC);
    // 0x801A5E64: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x801A5E68: jal         0x80005740
    // 0x801A5E6C: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Pop(rdram, ctx);
        goto after_8;
    // 0x801A5E6C: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_8:
    // 0x801A5E70: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_801A5E74:
    // 0x801A5E74: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x801A5E78: jr          $ra
    // 0x801A5E7C: nop

    return;
    // 0x801A5E7C: nop

;}
RECOMP_FUNC void Option_VsBackToSubMenu(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019B8A0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019B8A4: sw          $a0, -0x6EDC($at)
    MEM_W(-0X6EDC, ctx->r1) = ctx->r4;
    // 0x8019B8A8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019B8AC: sw          $zero, 0x7898($at)
    MEM_W(0X7898, ctx->r1) = 0;
    // 0x8019B8B0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019B8B4: sw          $zero, -0x6ED4($at)
    MEM_W(-0X6ED4, ctx->r1) = 0;
    // 0x8019B8B8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019B8BC: sw          $zero, -0x6E4C($at)
    MEM_W(-0X6E4C, ctx->r1) = 0;
    // 0x8019B8C0: jr          $ra
    // 0x8019B8C4: nop

    return;
    // 0x8019B8C4: nop

;}
RECOMP_FUNC void Title_ScreenFade_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801912A0: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801912A4: addiu       $v1, $v1, -0x7964
    ctx->r3 = ADD32(ctx->r3, -0X7964);
    // 0x801912A8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801912AC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801912B0: beq         $v0, $zero, L_801912C8
    if (ctx->r2 == 0) {
        // 0x801912B4: nop
    
            goto L_801912C8;
    }
    // 0x801912B4: nop

    // 0x801912B8: beq         $v0, $at, L_801912F0
    if (ctx->r2 == ctx->r1) {
        // 0x801912BC: nop
    
            goto L_801912F0;
    }
    // 0x801912BC: nop

    // 0x801912C0: jr          $ra
    // 0x801912C4: nop

    return;
    // 0x801912C4: nop

L_801912C8:
    // 0x801912C8: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x801912CC: addiu       $v0, $v0, -0x7CC0
    ctx->r2 = ADD32(ctx->r2, -0X7CC0);
    // 0x801912D0: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801912D4: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x801912D8: addiu       $t7, $t6, -0x4
    ctx->r15 = ADD32(ctx->r14, -0X4);
    // 0x801912DC: bgez        $t7, L_80191318
    if (SIGNED(ctx->r15) >= 0) {
        // 0x801912E0: sw          $t7, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r15;
            goto L_80191318;
    }
    // 0x801912E0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801912E4: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x801912E8: jr          $ra
    // 0x801912EC: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    return;
    // 0x801912EC: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
L_801912F0:
    // 0x801912F0: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x801912F4: addiu       $v0, $v0, -0x7CC0
    ctx->r2 = ADD32(ctx->r2, -0X7CC0);
    // 0x801912F8: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x801912FC: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80191300: addiu       $t0, $t9, 0xF
    ctx->r8 = ADD32(ctx->r25, 0XF);
    // 0x80191304: slti        $at, $t0, 0x100
    ctx->r1 = SIGNED(ctx->r8) < 0X100 ? 1 : 0;
    // 0x80191308: bne         $at, $zero, L_80191318
    if (ctx->r1 != 0) {
        // 0x8019130C: sw          $t0, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r8;
            goto L_80191318;
    }
    // 0x8019130C: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x80191310: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x80191314: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
L_80191318:
    // 0x80191318: jr          $ra
    // 0x8019131C: nop

    return;
    // 0x8019131C: nop

;}
RECOMP_FUNC void Option_Menu_Push(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019BDF0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8019BDF4: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8019BDF8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8019BDFC: jal         0x80005708
    // 0x8019BE00: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Push(rdram, ctx);
        goto after_0;
    // 0x8019BE00: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_0:
    // 0x8019BE04: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019BE08: lwc1        $f4, 0x79A0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X79A0);
    // 0x8019BE0C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019BE10: lwc1        $f6, 0x79B8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X79B8);
    // 0x8019BE14: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019BE18: lwc1        $f8, 0x79C0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X79C0);
    // 0x8019BE1C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8019BE20: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8019BE24: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8019BE28: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8019BE2C: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x8019BE30: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x8019BE34: lui         $a3, 0x8017
    ctx->r7 = S32(0X8017 << 16);
    // 0x8019BE38: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8019BE3C: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x8019BE40: lw          $a3, 0x7988($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X7988);
    // 0x8019BE44: lw          $a2, 0x7980($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7980);
    // 0x8019BE48: lw          $a1, 0x7978($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7978);
    // 0x8019BE4C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8019BE50: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8019BE54: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x8019BE58: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x8019BE5C: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x8019BE60: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x8019BE64: jal         0x80006E3C
    // 0x8019BE68: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    Matrix_LookAt(rdram, ctx);
        goto after_1;
    // 0x8019BE68: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x8019BE6C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8019BE70: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8019BE74: jr          $ra
    // 0x8019BE78: nop

    return;
    // 0x8019BE78: nop

;}
RECOMP_FUNC void Map_ZoomPlanetPath_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A2B8C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801A2B90: lui         $t0, 0x801D
    ctx->r8 = S32(0X801D << 16);
    // 0x801A2B94: addiu       $t0, $t0, -0x26B4
    ctx->r8 = ADD32(ctx->r8, -0X26B4);
    // 0x801A2B98: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801A2B9C: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x801A2BA0: slti        $at, $a1, 0x15
    ctx->r1 = SIGNED(ctx->r5) < 0X15 ? 1 : 0;
    // 0x801A2BA4: bne         $at, $zero, L_801A2BC0
    if (ctx->r1 != 0) {
        // 0x801A2BA8: or          $v0, $a1, $zero
        ctx->r2 = ctx->r5 | 0;
            goto L_801A2BC0;
    }
    // 0x801A2BA8: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x801A2BAC: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x801A2BB0: beq         $v0, $at, L_801A2BFC
    if (ctx->r2 == ctx->r1) {
        // 0x801A2BB4: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_801A2BFC;
    }
    // 0x801A2BB4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x801A2BB8: b           L_801A2E5C
    // 0x801A2BBC: nop

        goto L_801A2E5C;
    // 0x801A2BBC: nop

L_801A2BC0:
    // 0x801A2BC0: sltiu       $at, $v0, 0x15
    ctx->r1 = ctx->r2 < 0X15 ? 1 : 0;
    // 0x801A2BC4: beq         $at, $zero, L_801A2E5C
    if (ctx->r1 == 0) {
        // 0x801A2BC8: sll         $t6, $v0, 2
        ctx->r14 = S32(ctx->r2 << 2);
            goto L_801A2E5C;
    }
    // 0x801A2BC8: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x801A2BCC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A2BD0: addu        $at, $at, $t6
    gpr jr_addend_801A2BD8 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x801A2BD4: lw          $t6, 0x76DC($at)
    ctx->r14 = ADD32(ctx->r1, 0X76DC);
    // 0x801A2BD8: jr          $t6
    // 0x801A2BDC: nop

    switch (jr_addend_801A2BD8 >> 2) {
        case 0: goto L_801A2BE0; break;
        case 1: goto L_801A2D98; break;
        case 2: goto L_801A2DBC; break;
        case 3: goto L_801A2E28; break;
        case 4: goto L_801A2E5C; break;
        case 5: goto L_801A2E5C; break;
        case 6: goto L_801A2E5C; break;
        case 7: goto L_801A2E5C; break;
        case 8: goto L_801A2E5C; break;
        case 9: goto L_801A2E5C; break;
        case 10: goto L_801A2C90; break;
        case 11: goto L_801A2E5C; break;
        case 12: goto L_801A2E5C; break;
        case 13: goto L_801A2E5C; break;
        case 14: goto L_801A2E5C; break;
        case 15: goto L_801A2E5C; break;
        case 16: goto L_801A2E5C; break;
        case 17: goto L_801A2E5C; break;
        case 18: goto L_801A2E5C; break;
        case 19: goto L_801A2E5C; break;
        case 20: goto L_801A2D48; break;
        default: switch_error(__func__, 0x801A2BD8, 0x801B76DC);
    }
    // 0x801A2BDC: nop

L_801A2BE0:
    // 0x801A2BE0: jal         0x801A281C
    // 0x801A2BE4: nop

    Map_801A281C(rdram, ctx);
        goto after_0;
    // 0x801A2BE4: nop

    after_0:
    // 0x801A2BE8: lui         $t0, 0x801D
    ctx->r8 = S32(0X801D << 16);
    // 0x801A2BEC: addiu       $t0, $t0, -0x26B4
    ctx->r8 = ADD32(ctx->r8, -0X26B4);
    // 0x801A2BF0: addiu       $t7, $zero, 0x64
    ctx->r15 = ADD32(0, 0X64);
    // 0x801A2BF4: b           L_801A2E5C
    // 0x801A2BF8: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
        goto L_801A2E5C;
    // 0x801A2BF8: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
L_801A2BFC:
    // 0x801A2BFC: addiu       $a0, $a0, -0x7CC0
    ctx->r4 = ADD32(ctx->r4, -0X7CC0);
    // 0x801A2C00: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x801A2C04: lui         $t1, 0x801D
    ctx->r9 = S32(0X801D << 16);
    // 0x801A2C08: addiu       $t1, $t1, -0x2640
    ctx->r9 = ADD32(ctx->r9, -0X2640);
    // 0x801A2C0C: beq         $v0, $zero, L_801A2C28
    if (ctx->r2 == 0) {
        // 0x801A2C10: addiu       $t2, $zero, 0x1E
        ctx->r10 = ADD32(0, 0X1E);
            goto L_801A2C28;
    }
    // 0x801A2C10: addiu       $t2, $zero, 0x1E
    ctx->r10 = ADD32(0, 0X1E);
    // 0x801A2C14: addiu       $t8, $v0, -0x40
    ctx->r24 = ADD32(ctx->r2, -0X40);
    // 0x801A2C18: bgez        $t8, L_801A2E5C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x801A2C1C: sw          $t8, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r24;
            goto L_801A2E5C;
    }
    // 0x801A2C1C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x801A2C20: b           L_801A2E5C
    // 0x801A2C24: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
        goto L_801A2E5C;
    // 0x801A2C24: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
L_801A2C28:
    // 0x801A2C28: sw          $t2, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r10;
    // 0x801A2C2C: lui         $t3, 0x801D
    ctx->r11 = S32(0X801D << 16);
    // 0x801A2C30: lw          $t3, -0x2674($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2674);
    // 0x801A2C34: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801A2C38: lui         $t4, 0x801D
    ctx->r12 = S32(0X801D << 16);
    // 0x801A2C3C: beq         $v0, $t3, L_801A2C4C
    if (ctx->r2 == ctx->r11) {
        // 0x801A2C40: addiu       $v1, $zero, 0xFF
        ctx->r3 = ADD32(0, 0XFF);
            goto L_801A2C4C;
    }
    // 0x801A2C40: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x801A2C44: lw          $t4, -0x2680($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2680);
    // 0x801A2C48: bne         $v0, $t4, L_801A2C80
    if (ctx->r2 != ctx->r12) {
        // 0x801A2C4C: lui         $at, 0x8018
        ctx->r1 = S32(0X8018 << 16);
            goto L_801A2C80;
    }
L_801A2C4C:
    // 0x801A2C4C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801A2C50: sw          $v1, -0x7CB8($at)
    MEM_W(-0X7CB8, ctx->r1) = ctx->r3;
    // 0x801A2C54: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801A2C58: sw          $v1, -0x7CB0($at)
    MEM_W(-0X7CB0, ctx->r1) = ctx->r3;
    // 0x801A2C5C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801A2C60: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801A2C64: sw          $v1, -0x7CAC($at)
    MEM_W(-0X7CAC, ctx->r1) = ctx->r3;
    // 0x801A2C68: addiu       $a3, $a3, -0x267C
    ctx->r7 = ADD32(ctx->r7, -0X267C);
    // 0x801A2C6C: addiu       $t5, $zero, 0xA
    ctx->r13 = ADD32(0, 0XA);
    // 0x801A2C70: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x801A2C74: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
    // 0x801A2C78: b           L_801A2E5C
    // 0x801A2C7C: sw          $t5, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r13;
        goto L_801A2E5C;
    // 0x801A2C7C: sw          $t5, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r13;
L_801A2C80:
    // 0x801A2C80: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A2C84: sw          $zero, -0x263C($at)
    MEM_W(-0X263C, ctx->r1) = 0;
    // 0x801A2C88: b           L_801A2E5C
    // 0x801A2C8C: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
        goto L_801A2E5C;
    // 0x801A2C8C: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
L_801A2C90:
    // 0x801A2C90: lui         $t1, 0x801D
    ctx->r9 = S32(0X801D << 16);
    // 0x801A2C94: addiu       $t1, $t1, -0x2640
    ctx->r9 = ADD32(ctx->r9, -0X2640);
    // 0x801A2C98: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x801A2C9C: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801A2CA0: addiu       $a3, $a3, -0x267C
    ctx->r7 = ADD32(ctx->r7, -0X267C);
    // 0x801A2CA4: bne         $t6, $zero, L_801A2E5C
    if (ctx->r14 != 0) {
        // 0x801A2CA8: nop
    
            goto L_801A2E5C;
    }
    // 0x801A2CA8: nop

    // 0x801A2CAC: lw          $a2, 0x0($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X0);
    // 0x801A2CB0: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x801A2CB4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x801A2CB8: bne         $v1, $a2, L_801A2CE4
    if (ctx->r3 != ctx->r6) {
        // 0x801A2CBC: addiu       $a0, $a0, -0x7CC0
        ctx->r4 = ADD32(ctx->r4, -0X7CC0);
            goto L_801A2CE4;
    }
    // 0x801A2CBC: addiu       $a0, $a0, -0x7CC0
    ctx->r4 = ADD32(ctx->r4, -0X7CC0);
    // 0x801A2CC0: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x801A2CC4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A2CC8: addiu       $t8, $zero, 0x1E
    ctx->r24 = ADD32(0, 0X1E);
    // 0x801A2CCC: bne         $t7, $zero, L_801A2CE4
    if (ctx->r15 != 0) {
        // 0x801A2CD0: addiu       $t9, $zero, 0x14
        ctx->r25 = ADD32(0, 0X14);
            goto L_801A2CE4;
    }
    // 0x801A2CD0: addiu       $t9, $zero, 0x14
    ctx->r25 = ADD32(0, 0X14);
    // 0x801A2CD4: sw          $zero, -0x2680($at)
    MEM_W(-0X2680, ctx->r1) = 0;
    // 0x801A2CD8: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x801A2CDC: b           L_801A2E5C
    // 0x801A2CE0: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
        goto L_801A2E5C;
    // 0x801A2CE0: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
L_801A2CE4:
    // 0x801A2CE4: lui         $t0, 0x801D
    ctx->r8 = S32(0X801D << 16);
    // 0x801A2CE8: addiu       $t0, $t0, -0x2678
    ctx->r8 = ADD32(ctx->r8, -0X2678);
    // 0x801A2CEC: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x801A2CF0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x801A2CF4: addiu       $a0, $a0, -0x7CC0
    ctx->r4 = ADD32(ctx->r4, -0X7CC0);
    // 0x801A2CF8: beq         $a1, $zero, L_801A2D14
    if (ctx->r5 == 0) {
        // 0x801A2CFC: lw          $v0, 0x0($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X0);
            goto L_801A2D14;
    }
    // 0x801A2CFC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x801A2D00: xori        $t2, $v0, 0xFF
    ctx->r10 = ctx->r2 ^ 0XFF;
    // 0x801A2D04: addiu       $t3, $a1, -0x1
    ctx->r11 = ADD32(ctx->r5, -0X1);
    // 0x801A2D08: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x801A2D0C: b           L_801A2E5C
    // 0x801A2D10: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
        goto L_801A2E5C;
    // 0x801A2D10: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
L_801A2D14:
    // 0x801A2D14: beq         $v0, $zero, L_801A2D2C
    if (ctx->r2 == 0) {
        // 0x801A2D18: sw          $zero, 0x0($t0)
        MEM_W(0X0, ctx->r8) = 0;
            goto L_801A2D2C;
    }
    // 0x801A2D18: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    // 0x801A2D1C: addiu       $t4, $v0, -0x15
    ctx->r12 = ADD32(ctx->r2, -0X15);
    // 0x801A2D20: bgez        $t4, L_801A2D2C
    if (SIGNED(ctx->r12) >= 0) {
        // 0x801A2D24: sw          $t4, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r12;
            goto L_801A2D2C;
    }
    // 0x801A2D24: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x801A2D28: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
L_801A2D2C:
    // 0x801A2D2C: addiu       $t6, $a2, 0x8
    ctx->r14 = ADD32(ctx->r6, 0X8);
    // 0x801A2D30: slti        $at, $t6, 0x100
    ctx->r1 = SIGNED(ctx->r14) < 0X100 ? 1 : 0;
    // 0x801A2D34: bne         $at, $zero, L_801A2E5C
    if (ctx->r1 != 0) {
        // 0x801A2D38: sw          $t6, 0x0($a3)
        MEM_W(0X0, ctx->r7) = ctx->r14;
            goto L_801A2E5C;
    }
    // 0x801A2D38: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x801A2D3C: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x801A2D40: b           L_801A2E5C
    // 0x801A2D44: sw          $v1, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r3;
        goto L_801A2E5C;
    // 0x801A2D44: sw          $v1, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r3;
L_801A2D48:
    // 0x801A2D48: lui         $t1, 0x801D
    ctx->r9 = S32(0X801D << 16);
    // 0x801A2D4C: addiu       $t1, $t1, -0x2640
    ctx->r9 = ADD32(ctx->r9, -0X2640);
    // 0x801A2D50: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x801A2D54: lui         $t9, 0x801D
    ctx->r25 = S32(0X801D << 16);
    // 0x801A2D58: bne         $t8, $zero, L_801A2E5C
    if (ctx->r24 != 0) {
        // 0x801A2D5C: nop
    
            goto L_801A2E5C;
    }
    // 0x801A2D5C: nop

    // 0x801A2D60: lw          $t9, -0x2674($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2674);
    // 0x801A2D64: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801A2D68: lui         $t2, 0x801D
    ctx->r10 = S32(0X801D << 16);
    // 0x801A2D6C: beq         $v0, $t9, L_801A2E5C
    if (ctx->r2 == ctx->r25) {
        // 0x801A2D70: nop
    
            goto L_801A2E5C;
    }
    // 0x801A2D70: nop

    // 0x801A2D74: lw          $t2, -0x2680($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2680);
    // 0x801A2D78: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A2D7C: addiu       $t3, $zero, 0x1E
    ctx->r11 = ADD32(0, 0X1E);
    // 0x801A2D80: beq         $v0, $t2, L_801A2E5C
    if (ctx->r2 == ctx->r10) {
        // 0x801A2D84: nop
    
            goto L_801A2E5C;
    }
    // 0x801A2D84: nop

    // 0x801A2D88: sw          $zero, -0x263C($at)
    MEM_W(-0X263C, ctx->r1) = 0;
    // 0x801A2D8C: sw          $t3, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r11;
    // 0x801A2D90: b           L_801A2E5C
    // 0x801A2D94: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
        goto L_801A2E5C;
    // 0x801A2D94: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
L_801A2D98:
    // 0x801A2D98: lui         $t1, 0x801D
    ctx->r9 = S32(0X801D << 16);
    // 0x801A2D9C: addiu       $t1, $t1, -0x2640
    ctx->r9 = ADD32(ctx->r9, -0X2640);
    // 0x801A2DA0: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x801A2DA4: bne         $t4, $zero, L_801A2E5C
    if (ctx->r12 != 0) {
        // 0x801A2DA8: nop
    
            goto L_801A2E5C;
    }
    // 0x801A2DA8: nop

    // 0x801A2DAC: jal         0x801A2EB8
    // 0x801A2DB0: nop

    Map_801A2EB8(rdram, ctx);
        goto after_1;
    // 0x801A2DB0: nop

    after_1:
    // 0x801A2DB4: b           L_801A2E5C
    // 0x801A2DB8: nop

        goto L_801A2E5C;
    // 0x801A2DB8: nop

L_801A2DBC:
    // 0x801A2DBC: lui         $t1, 0x801D
    ctx->r9 = S32(0X801D << 16);
    // 0x801A2DC0: addiu       $t1, $t1, -0x2640
    ctx->r9 = ADD32(ctx->r9, -0X2640);
    // 0x801A2DC4: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x801A2DC8: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x801A2DCC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A2DD0: bne         $t5, $zero, L_801A2E5C
    if (ctx->r13 != 0) {
        // 0x801A2DD4: addiu       $t7, $zero, 0xFF
        ctx->r15 = ADD32(0, 0XFF);
            goto L_801A2E5C;
    }
    // 0x801A2DD4: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x801A2DD8: sw          $t6, -0x2700($at)
    MEM_W(-0X2700, ctx->r1) = ctx->r14;
    // 0x801A2DDC: sw          $t7, -0x26FC($at)
    MEM_W(-0X26FC, ctx->r1) = ctx->r15;
    // 0x801A2DE0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A2DE4: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x801A2DE8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801A2DEC: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x801A2DF0: addiu       $a0, $a0, -0x26C4
    ctx->r4 = ADD32(ctx->r4, -0X26C4);
    // 0x801A2DF4: addiu       $v0, $v0, -0x26F4
    ctx->r2 = ADD32(ctx->r2, -0X26F4);
    // 0x801A2DF8: sw          $t8, -0x26F8($at)
    MEM_W(-0X26F8, ctx->r1) = ctx->r24;
    // 0x801A2DFC: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
L_801A2E00:
    // 0x801A2E00: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x801A2E04: sw          $v1, -0xC($v0)
    MEM_W(-0XC, ctx->r2) = ctx->r3;
    // 0x801A2E08: sw          $v1, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->r3;
    // 0x801A2E0C: sw          $v1, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r3;
    // 0x801A2E10: bne         $v0, $a0, L_801A2E00
    if (ctx->r2 != ctx->r4) {
        // 0x801A2E14: sw          $v1, -0x10($v0)
        MEM_W(-0X10, ctx->r2) = ctx->r3;
            goto L_801A2E00;
    }
    // 0x801A2E14: sw          $v1, -0x10($v0)
    MEM_W(-0X10, ctx->r2) = ctx->r3;
    // 0x801A2E18: addiu       $t9, $a1, 0x1
    ctx->r25 = ADD32(ctx->r5, 0X1);
    // 0x801A2E1C: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
    // 0x801A2E20: b           L_801A2E5C
    // 0x801A2E24: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
        goto L_801A2E5C;
    // 0x801A2E24: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
L_801A2E28:
    // 0x801A2E28: lui         $t1, 0x801D
    ctx->r9 = S32(0X801D << 16);
    // 0x801A2E2C: addiu       $t1, $t1, -0x2640
    ctx->r9 = ADD32(ctx->r9, -0X2640);
    // 0x801A2E30: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x801A2E34: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801A2E38: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A2E3C: bne         $t2, $zero, L_801A2E5C
    if (ctx->r10 != 0) {
        // 0x801A2E40: addiu       $t3, $zero, 0x3
        ctx->r11 = ADD32(0, 0X3);
            goto L_801A2E5C;
    }
    // 0x801A2E40: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x801A2E44: sw          $v0, -0x1038($at)
    MEM_W(-0X1038, ctx->r1) = ctx->r2;
    // 0x801A2E48: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A2E4C: sw          $v0, -0x2684($at)
    MEM_W(-0X2684, ctx->r1) = ctx->r2;
    // 0x801A2E50: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    // 0x801A2E54: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A2E58: sw          $t3, -0x26BC($at)
    MEM_W(-0X26BC, ctx->r1) = ctx->r11;
L_801A2E5C:
    // 0x801A2E5C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A2E60: lwc1        $f12, -0x260C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X260C);
    // 0x801A2E64: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A2E68: lwc1        $f14, -0x2608($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X2608);
    // 0x801A2E6C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A2E70: lwc1        $f4, -0x25FC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X25FC);
    // 0x801A2E74: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A2E78: lwc1        $f6, -0x25F8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X25F8);
    // 0x801A2E7C: lui         $a2, 0x801D
    ctx->r6 = S32(0X801D << 16);
    // 0x801A2E80: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801A2E84: lw          $a3, -0x2600($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X2600);
    // 0x801A2E88: lw          $a2, -0x2604($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X2604);
    // 0x801A2E8C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x801A2E90: jal         0x800B6F50
    // 0x801A2E94: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    Camera_SetStarfieldPos(rdram, ctx);
        goto after_2;
    // 0x801A2E94: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x801A2E98: lui         $t4, 0x801D
    ctx->r12 = S32(0X801D << 16);
    // 0x801A2E9C: lw          $t4, -0x263C($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X263C);
    // 0x801A2EA0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A2EA4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801A2EA8: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x801A2EAC: sw          $t5, -0x263C($at)
    MEM_W(-0X263C, ctx->r1) = ctx->r13;
    // 0x801A2EB0: jr          $ra
    // 0x801A2EB4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x801A2EB4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void Map_PathPlanetMedal_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801AB17C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801AB180: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801AB184: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x801AB188: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x801AB18C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801AB190: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    // 0x801AB194: swc1        $f14, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f14.u32l;
    // 0x801AB198: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x801AB19C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801AB1A0: jal         0x800B8DD0
    // 0x801AB1A4: addiu       $a1, $zero, 0x35
    ctx->r5 = ADD32(0, 0X35);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x801AB1A4: addiu       $a1, $zero, 0x35
    ctx->r5 = ADD32(0, 0X35);
    after_0:
    // 0x801AB1A8: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x801AB1AC: lui         $t7, 0xBA00
    ctx->r15 = S32(0XBA00 << 16);
    // 0x801AB1B0: ori         $t7, $t7, 0xC02
    ctx->r15 = ctx->r15 | 0XC02;
    // 0x801AB1B4: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x801AB1B8: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x801AB1BC: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x801AB1C0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x801AB1C4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801AB1C8: jal         0x80005708
    // 0x801AB1CC: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Push(rdram, ctx);
        goto after_1;
    // 0x801AB1CC: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_1:
    // 0x801AB1D0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801AB1D4: lwc1        $f6, 0x6B04($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6B04);
    // 0x801AB1D8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801AB1DC: lwc1        $f16, 0x6B08($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6B08);
    // 0x801AB1E0: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801AB1E4: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801AB1E8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801AB1EC: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801AB1F0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801AB1F4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x801AB1F8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801AB1FC: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x801AB200: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x801AB204: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x801AB208: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x801AB20C: jal         0x80005B00
    // 0x801AB210: nop

    Matrix_Translate(rdram, ctx);
        goto after_2;
    // 0x801AB210: nop

    after_2:
    // 0x801AB214: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801AB218: lwc1        $f0, 0x6B00($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6B00);
    // 0x801AB21C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801AB220: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801AB224: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801AB228: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801AB22C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x801AB230: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x801AB234: jal         0x80005C34
    // 0x801AB238: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Scale(rdram, ctx);
        goto after_3;
    // 0x801AB238: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_3:
    // 0x801AB23C: jal         0x80006EB8
    // 0x801AB240: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_4;
    // 0x801AB240: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x801AB244: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x801AB248: lui         $t2, 0x602
    ctx->r10 = S32(0X602 << 16);
    // 0x801AB24C: addiu       $t2, $t2, -0x2E10
    ctx->r10 = ADD32(ctx->r10, -0X2E10);
    // 0x801AB250: addiu       $t0, $v1, 0x8
    ctx->r8 = ADD32(ctx->r3, 0X8);
    // 0x801AB254: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x801AB258: lui         $t1, 0x600
    ctx->r9 = S32(0X600 << 16);
    // 0x801AB25C: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x801AB260: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x801AB264: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801AB268: jal         0x80005740
    // 0x801AB26C: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Pop(rdram, ctx);
        goto after_5;
    // 0x801AB26C: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_5:
    // 0x801AB270: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801AB274: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801AB278: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801AB27C: jr          $ra
    // 0x801AB280: nop

    return;
    // 0x801AB280: nop

;}
RECOMP_FUNC void Map_BriefingRadio_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801AB300: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801AB304: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x801AB308: addiu       $t0, $t0, -0x7D54
    ctx->r8 = ADD32(ctx->r8, -0X7D54);
    // 0x801AB30C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801AB310: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x801AB314: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x801AB318: addiu       $a3, $a3, -0x7D4C
    ctx->r7 = ADD32(ctx->r7, -0X7D4C);
    // 0x801AB31C: blez        $v0, L_801AB32C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x801AB320: lui         $t1, 0x801D
        ctx->r9 = S32(0X801D << 16);
            goto L_801AB32C;
    }
    // 0x801AB320: lui         $t1, 0x801D
    ctx->r9 = S32(0X801D << 16);
    // 0x801AB324: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x801AB328: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
L_801AB32C:
    // 0x801AB32C: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x801AB330: addiu       $t1, $t1, -0xFE8
    ctx->r9 = ADD32(ctx->r9, -0XFE8);
    // 0x801AB334: blez        $v0, L_801AB340
    if (SIGNED(ctx->r2) <= 0) {
        // 0x801AB338: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_801AB340;
    }
    // 0x801AB338: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x801AB33C: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
L_801AB340:
    // 0x801AB340: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x801AB344: slti        $at, $v1, 0x65
    ctx->r1 = SIGNED(ctx->r3) < 0X65 ? 1 : 0;
    // 0x801AB348: bne         $at, $zero, L_801AB36C
    if (ctx->r1 != 0) {
        // 0x801AB34C: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_801AB36C;
    }
    // 0x801AB34C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x801AB350: addiu       $at, $zero, 0xC8
    ctx->r1 = ADD32(0, 0XC8);
    // 0x801AB354: beq         $v0, $at, L_801AB424
    if (ctx->r2 == ctx->r1) {
        // 0x801AB358: addiu       $at, $zero, 0xD2
        ctx->r1 = ADD32(0, 0XD2);
            goto L_801AB424;
    }
    // 0x801AB358: addiu       $at, $zero, 0xD2
    ctx->r1 = ADD32(0, 0XD2);
    // 0x801AB35C: beql        $v0, $at, L_801AB43C
    if (ctx->r2 == ctx->r1) {
        // 0x801AB360: lw          $t7, 0x0($t0)
        ctx->r15 = MEM_W(ctx->r8, 0X0);
            goto L_801AB43C;
    }
    goto skip_0;
    // 0x801AB360: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    skip_0:
    // 0x801AB364: b           L_801AB928
    // 0x801AB368: nop

        goto L_801AB928;
    // 0x801AB368: nop

L_801AB36C:
    // 0x801AB36C: slti        $at, $v0, 0x2A
    ctx->r1 = SIGNED(ctx->r2) < 0X2A ? 1 : 0;
    // 0x801AB370: bne         $at, $zero, L_801AB388
    if (ctx->r1 != 0) {
        // 0x801AB374: addiu       $at, $zero, 0x64
        ctx->r1 = ADD32(0, 0X64);
            goto L_801AB388;
    }
    // 0x801AB374: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x801AB378: beq         $v0, $at, L_801AB3C4
    if (ctx->r2 == ctx->r1) {
        // 0x801AB37C: lui         $a1, 0x801D
        ctx->r5 = S32(0X801D << 16);
            goto L_801AB3C4;
    }
    // 0x801AB37C: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801AB380: b           L_801AB928
    // 0x801AB384: nop

        goto L_801AB928;
    // 0x801AB384: nop

L_801AB388:
    // 0x801AB388: slti        $at, $v0, 0x9
    ctx->r1 = SIGNED(ctx->r2) < 0X9 ? 1 : 0;
    // 0x801AB38C: bne         $at, $zero, L_801AB3A4
    if (ctx->r1 != 0) {
        // 0x801AB390: addiu       $at, $zero, 0x29
        ctx->r1 = ADD32(0, 0X29);
            goto L_801AB3A4;
    }
    // 0x801AB390: addiu       $at, $zero, 0x29
    ctx->r1 = ADD32(0, 0X29);
    // 0x801AB394: beql        $v0, $at, L_801AB764
    if (ctx->r2 == ctx->r1) {
        // 0x801AB398: lw          $t7, 0x0($t0)
        ctx->r15 = MEM_W(ctx->r8, 0X0);
            goto L_801AB764;
    }
    goto skip_1;
    // 0x801AB398: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    skip_1:
    // 0x801AB39C: b           L_801AB928
    // 0x801AB3A0: nop

        goto L_801AB928;
    // 0x801AB3A0: nop

L_801AB3A4:
    // 0x801AB3A4: sltiu       $at, $v0, 0x9
    ctx->r1 = ctx->r2 < 0X9 ? 1 : 0;
    // 0x801AB3A8: beq         $at, $zero, L_801AB928
    if (ctx->r1 == 0) {
        // 0x801AB3AC: sll         $t8, $v0, 2
        ctx->r24 = S32(ctx->r2 << 2);
            goto L_801AB928;
    }
    // 0x801AB3AC: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x801AB3B0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801AB3B4: addu        $at, $at, $t8
    gpr jr_addend_801AB3BC = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x801AB3B8: lw          $t8, 0x7AD8($at)
    ctx->r24 = ADD32(ctx->r1, 0X7AD8);
    // 0x801AB3BC: jr          $t8
    // 0x801AB3C0: nop

    switch (jr_addend_801AB3BC >> 2) {
        case 0: goto L_801AB928; break;
        case 1: goto L_801AB50C; break;
        case 2: goto L_801AB928; break;
        case 3: goto L_801AB928; break;
        case 4: goto L_801AB5B8; break;
        case 5: goto L_801AB874; break;
        case 6: goto L_801AB8AC; break;
        case 7: goto L_801AB928; break;
        case 8: goto L_801AB8E8; break;
        default: switch_error(__func__, 0x801AB3BC, 0x801B7AD8);
    }
    // 0x801AB3C0: nop

L_801AB3C4:
    // 0x801AB3C4: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x801AB3C8: addiu       $t2, $t2, 0x7D68
    ctx->r10 = ADD32(ctx->r10, 0X7D68);
    // 0x801AB3CC: lwc1        $f4, 0x0($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X0);
    // 0x801AB3D0: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801AB3D4: addiu       $v0, $v0, -0x158C
    ctx->r2 = ADD32(ctx->r2, -0X158C);
    // 0x801AB3D8: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x801AB3DC: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x801AB3E0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801AB3E4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801AB3E8: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    // 0x801AB3EC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801AB3F0: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x801AB3F4: sw          $t3, -0x7D5C($at)
    MEM_W(-0X7D5C, ctx->r1) = ctx->r11;
    // 0x801AB3F8: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
    // 0x801AB3FC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801AB400: swc1        $f0, 0x7D50($at)
    MEM_W(0X7D50, ctx->r1) = ctx->f0.u32l;
    // 0x801AB404: addiu       $a2, $a2, -0x7D28
    ctx->r6 = ADD32(ctx->r6, -0X7D28);
    // 0x801AB408: addiu       $a1, $a1, -0xEDC
    ctx->r5 = ADD32(ctx->r5, -0XEDC);
    // 0x801AB40C: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x801AB410: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801AB414: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
    // 0x801AB418: sw          $zero, -0x154C($at)
    MEM_W(-0X154C, ctx->r1) = 0;
    // 0x801AB41C: b           L_801AB928
    // 0x801AB420: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
        goto L_801AB928;
    // 0x801AB420: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
L_801AB424:
    // 0x801AB424: addiu       $v1, $zero, 0xD2
    ctx->r3 = ADD32(0, 0XD2);
    // 0x801AB428: addiu       $t6, $zero, 0x1E
    ctx->r14 = ADD32(0, 0X1E);
    // 0x801AB42C: sw          $v1, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r3;
    // 0x801AB430: b           L_801AB928
    // 0x801AB434: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
        goto L_801AB928;
    // 0x801AB434: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x801AB438: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
L_801AB43C:
    // 0x801AB43C: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x801AB440: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801AB444: bne         $t7, $zero, L_801AB928
    if (ctx->r15 != 0) {
        // 0x801AB448: lui         $t9, 0x801D
        ctx->r25 = S32(0X801D << 16);
            goto L_801AB928;
    }
    // 0x801AB448: lui         $t9, 0x801D
    ctx->r25 = S32(0X801D << 16);
    // 0x801AB44C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801AB450: addiu       $v1, $v1, -0x26C0
    ctx->r3 = ADD32(ctx->r3, -0X26C0);
    // 0x801AB454: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x801AB458: lw          $t9, -0x26AC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X26AC);
    // 0x801AB45C: sll         $t5, $t8, 2
    ctx->r13 = S32(ctx->r24 << 2);
    // 0x801AB460: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x801AB464: sll         $t3, $t9, 3
    ctx->r11 = S32(ctx->r25 << 3);
    // 0x801AB468: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x801AB46C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x801AB470: lw          $a0, -0xBD8($t7)
    ctx->r4 = MEM_W(ctx->r15, -0XBD8);
    // 0x801AB474: addiu       $v0, $v0, -0x7CF8
    ctx->r2 = ADD32(ctx->r2, -0X7CF8);
    // 0x801AB478: jal         0x800C2890
    // 0x801AB47C: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    Message_IdFromPtr(rdram, ctx);
        goto after_0;
    // 0x801AB47C: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    after_0:
    // 0x801AB480: jal         0x8001ACDC
    // 0x801AB484: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    Audio_PlayVoice(rdram, ctx);
        goto after_1;
    // 0x801AB484: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x801AB488: lui         $t8, 0x801D
    ctx->r24 = S32(0X801D << 16);
    // 0x801AB48C: lw          $t8, -0x26C0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X26C0);
    // 0x801AB490: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x801AB494: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801AB498: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x801AB49C: addu        $t4, $t4, $t9
    ctx->r12 = ADD32(ctx->r12, ctx->r25);
    // 0x801AB4A0: lw          $t4, -0xBE0($t4)
    ctx->r12 = MEM_W(ctx->r12, -0XBE0);
    // 0x801AB4A4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x801AB4A8: lw          $a0, -0x7CF8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7CF8);
    // 0x801AB4AC: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x801AB4B0: nop

    // 0x801AB4B4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801AB4B8: jal         0x800C2928
    // 0x801AB4BC: swc1        $f10, 0x7D68($at)
    MEM_W(0X7D68, ctx->r1) = ctx->f10.u32l;
    Message_GetCharCount(rdram, ctx);
        goto after_2;
    // 0x801AB4BC: swc1        $f10, 0x7D68($at)
    MEM_W(0X7D68, ctx->r1) = ctx->f10.u32l;
    after_2:
    // 0x801AB4C0: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x801AB4C4: sll         $t3, $v0, 1
    ctx->r11 = S32(ctx->r2 << 1);
    // 0x801AB4C8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801AB4CC: sw          $t3, -0x7D54($at)
    MEM_W(-0X7D54, ctx->r1) = ctx->r11;
    // 0x801AB4D0: addiu       $t2, $t2, 0x7D68
    ctx->r10 = ADD32(ctx->r10, 0X7D68);
    // 0x801AB4D4: lwc1        $f16, 0x0($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0X0);
    // 0x801AB4D8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801AB4DC: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x801AB4E0: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x801AB4E4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801AB4E8: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
    // 0x801AB4EC: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x801AB4F0: nop

    // 0x801AB4F4: sw          $t6, -0x7D5C($at)
    MEM_W(-0X7D5C, ctx->r1) = ctx->r14;
    // 0x801AB4F8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801AB4FC: sw          $t7, -0xFE8($at)
    MEM_W(-0XFE8, ctx->r1) = ctx->r15;
    // 0x801AB500: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801AB504: b           L_801AB928
    // 0x801AB508: sw          $t8, -0x2660($at)
    MEM_W(-0X2660, ctx->r1) = ctx->r24;
        goto L_801AB928;
    // 0x801AB508: sw          $t8, -0x2660($at)
    MEM_W(-0X2660, ctx->r1) = ctx->r24;
L_801AB50C:
    // 0x801AB50C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801AB510: addiu       $v0, $v0, -0x158C
    ctx->r2 = ADD32(ctx->r2, -0X158C);
    // 0x801AB514: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x801AB518: addiu       $t4, $t9, 0x8
    ctx->r12 = ADD32(ctx->r25, 0X8);
    // 0x801AB51C: slti        $at, $t4, 0x100
    ctx->r1 = SIGNED(ctx->r12) < 0X100 ? 1 : 0;
    // 0x801AB520: bne         $at, $zero, L_801AB928
    if (ctx->r1 != 0) {
        // 0x801AB524: sw          $t4, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r12;
            goto L_801AB928;
    }
    // 0x801AB524: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x801AB528: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x801AB52C: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x801AB530: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801AB534: lwc1        $f4, 0x7AFC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7AFC);
    // 0x801AB538: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x801AB53C: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x801AB540: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x801AB544: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801AB548: addiu       $t6, $t6, 0x5D3C
    ctx->r14 = ADD32(ctx->r14, 0X5D3C);
    // 0x801AB54C: lui         $a0, 0x4100
    ctx->r4 = S32(0X4100 << 16);
    // 0x801AB550: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x801AB554: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x801AB558: ori         $a0, $a0, 0x1E
    ctx->r4 = ctx->r4 | 0X1E;
    // 0x801AB55C: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x801AB560: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x801AB564: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x801AB568: jal         0x80019218
    // 0x801AB56C: swc1        $f4, 0x7D50($at)
    MEM_W(0X7D50, ctx->r1) = ctx->f4.u32l;
    Audio_PlaySfx(rdram, ctx);
        goto after_3;
    // 0x801AB56C: swc1        $f4, 0x7D50($at)
    MEM_W(0X7D50, ctx->r1) = ctx->f4.u32l;
    after_3:
    // 0x801AB570: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x801AB574: jal         0x800C2890
    // 0x801AB578: lw          $a0, -0x7CF8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7CF8);
    Message_IdFromPtr(rdram, ctx);
        goto after_4;
    // 0x801AB578: lw          $a0, -0x7CF8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7CF8);
    after_4:
    // 0x801AB57C: jal         0x8001ACDC
    // 0x801AB580: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    Audio_PlayVoice(rdram, ctx);
        goto after_5;
    // 0x801AB580: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_5:
    // 0x801AB584: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x801AB588: jal         0x800C2928
    // 0x801AB58C: lw          $a0, -0x7CF8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7CF8);
    Message_GetCharCount(rdram, ctx);
        goto after_6;
    // 0x801AB58C: lw          $a0, -0x7CF8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7CF8);
    after_6:
    // 0x801AB590: sll         $t7, $v0, 1
    ctx->r15 = S32(ctx->r2 << 1);
    // 0x801AB594: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801AB598: sw          $t7, -0x7D54($at)
    MEM_W(-0X7D54, ctx->r1) = ctx->r15;
    // 0x801AB59C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801AB5A0: sw          $zero, -0x265C($at)
    MEM_W(-0X265C, ctx->r1) = 0;
    // 0x801AB5A4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801AB5A8: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x801AB5AC: sw          $t8, -0xFE8($at)
    MEM_W(-0XFE8, ctx->r1) = ctx->r24;
    // 0x801AB5B0: b           L_801AB928
    // 0x801AB5B4: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
        goto L_801AB928;
    // 0x801AB5B4: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
L_801AB5B8:
    // 0x801AB5B8: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x801AB5BC: bne         $t9, $zero, L_801AB640
    if (ctx->r25 != 0) {
        // 0x801AB5C0: nop
    
            goto L_801AB640;
    }
    // 0x801AB5C0: nop

    // 0x801AB5C4: jal         0x8001AE78
    // 0x801AB5C8: nop

    Audio_GetCurrentVoice(rdram, ctx);
        goto after_7;
    // 0x801AB5C8: nop

    after_7:
    // 0x801AB5CC: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x801AB5D0: bne         $v0, $zero, L_801AB640
    if (ctx->r2 != 0) {
        // 0x801AB5D4: addiu       $a3, $a3, -0x7D4C
        ctx->r7 = ADD32(ctx->r7, -0X7D4C);
            goto L_801AB640;
    }
    // 0x801AB5D4: addiu       $a3, $a3, -0x7D4C
    ctx->r7 = ADD32(ctx->r7, -0X7D4C);
    // 0x801AB5D8: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x801AB5DC: addiu       $t2, $t2, 0x7D68
    ctx->r10 = ADD32(ctx->r10, 0X7D68);
    // 0x801AB5E0: lwc1        $f6, 0x0($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X0);
    // 0x801AB5E4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801AB5E8: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x801AB5EC: mfc1        $t3, $f8
    ctx->r11 = (int32_t)ctx->f8.u32l;
    // 0x801AB5F0: jal         0x8001AE58
    // 0x801AB5F4: sw          $t3, -0x7D5C($at)
    MEM_W(-0X7D5C, ctx->r1) = ctx->r11;
    Audio_ClearVoice(rdram, ctx);
        goto after_8;
    // 0x801AB5F4: sw          $t3, -0x7D5C($at)
    MEM_W(-0X7D5C, ctx->r1) = ctx->r11;
    after_8:
    // 0x801AB5F8: lui         $t5, 0x801D
    ctx->r13 = S32(0X801D << 16);
    // 0x801AB5FC: lw          $t5, -0x26C0($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X26C0);
    // 0x801AB600: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x801AB604: addiu       $a2, $a2, -0x7D28
    ctx->r6 = ADD32(ctx->r6, -0X7D28);
    // 0x801AB608: bne         $t5, $zero, L_801AB620
    if (ctx->r13 != 0) {
        // 0x801AB60C: addiu       $t6, $zero, 0x1E
        ctx->r14 = ADD32(0, 0X1E);
            goto L_801AB620;
    }
    // 0x801AB60C: addiu       $t6, $zero, 0x1E
    ctx->r14 = ADD32(0, 0X1E);
    // 0x801AB610: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x801AB614: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801AB618: b           L_801AB62C
    // 0x801AB61C: sw          $t6, -0x7D54($at)
    MEM_W(-0X7D54, ctx->r1) = ctx->r14;
        goto L_801AB62C;
    // 0x801AB61C: sw          $t6, -0x7D54($at)
    MEM_W(-0X7D54, ctx->r1) = ctx->r14;
L_801AB620:
    // 0x801AB620: addiu       $t7, $zero, 0x14
    ctx->r15 = ADD32(0, 0X14);
    // 0x801AB624: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801AB628: sw          $t7, -0x7D54($at)
    MEM_W(-0X7D54, ctx->r1) = ctx->r15;
L_801AB62C:
    // 0x801AB62C: addiu       $t8, $zero, 0x29
    ctx->r24 = ADD32(0, 0X29);
    // 0x801AB630: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801AB634: sw          $t8, -0xFE8($at)
    MEM_W(-0XFE8, ctx->r1) = ctx->r24;
    // 0x801AB638: b           L_801AB928
    // 0x801AB63C: addiu       $v1, $zero, 0x29
    ctx->r3 = ADD32(0, 0X29);
        goto L_801AB928;
    // 0x801AB63C: addiu       $v1, $zero, 0x29
    ctx->r3 = ADD32(0, 0X29);
L_801AB640:
    // 0x801AB640: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x801AB644: addiu       $t2, $t2, 0x7D68
    ctx->r10 = ADD32(ctx->r10, 0X7D68);
    // 0x801AB648: lwc1        $f0, 0x0($t2)
    ctx->f0.u32l = MEM_W(ctx->r10, 0X0);
    // 0x801AB64C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801AB650: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x801AB654: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x801AB658: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x801AB65C: nop

    // 0x801AB660: sw          $t4, -0x7D5C($at)
    MEM_W(-0X7D5C, ctx->r1) = ctx->r12;
    // 0x801AB664: lw          $t3, 0x0($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X0);
    // 0x801AB668: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801AB66C: blez        $t3, L_801AB690
    if (SIGNED(ctx->r11) <= 0) {
        // 0x801AB670: nop
    
            goto L_801AB690;
    }
    // 0x801AB670: nop

    // 0x801AB674: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801AB678: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801AB67C: add.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x801AB680: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x801AB684: mfc1        $t6, $f4
    ctx->r14 = (int32_t)ctx->f4.u32l;
    // 0x801AB688: nop

    // 0x801AB68C: sw          $t6, -0x7D5C($at)
    MEM_W(-0X7D5C, ctx->r1) = ctx->r14;
L_801AB690:
    // 0x801AB690: jal         0x800C2928
    // 0x801AB694: lw          $a0, -0x7CF8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7CF8);
    Message_GetCharCount(rdram, ctx);
        goto after_9;
    // 0x801AB694: lw          $a0, -0x7CF8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7CF8);
    after_9:
    // 0x801AB698: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x801AB69C: addiu       $a2, $a2, -0x7D28
    ctx->r6 = ADD32(ctx->r6, -0X7D28);
    // 0x801AB6A0: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x801AB6A4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801AB6A8: lui         $t8, 0x801D
    ctx->r24 = S32(0X801D << 16);
    // 0x801AB6AC: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x801AB6B0: bne         $at, $zero, L_801AB6C0
    if (ctx->r1 != 0) {
        // 0x801AB6B4: lui         $a1, 0x801D
        ctx->r5 = S32(0X801D << 16);
            goto L_801AB6C0;
    }
    // 0x801AB6B4: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801AB6B8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801AB6BC: sw          $t7, -0x265C($at)
    MEM_W(-0X265C, ctx->r1) = ctx->r15;
L_801AB6C0:
    // 0x801AB6C0: lw          $t8, -0x2660($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2660);
    // 0x801AB6C4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801AB6C8: addiu       $a1, $a1, -0xEDC
    ctx->r5 = ADD32(ctx->r5, -0XEDC);
    // 0x801AB6CC: bne         $t8, $at, L_801AB6F8
    if (ctx->r24 != ctx->r1) {
        // 0x801AB6D0: lui         $at, 0x801B
        ctx->r1 = S32(0X801B << 16);
            goto L_801AB6F8;
    }
    // 0x801AB6D0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801AB6D4: lwc1        $f8, 0x7B00($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7B00);
    // 0x801AB6D8: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x801AB6DC: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801AB6E0: swc1        $f10, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f10.u32l;
    // 0x801AB6E4: lwc1        $f16, 0x0($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X0);
    // 0x801AB6E8: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x801AB6EC: mfc1        $t4, $f18
    ctx->r12 = (int32_t)ctx->f18.u32l;
    // 0x801AB6F0: b           L_801AB700
    // 0x801AB6F4: sw          $t4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r12;
        goto L_801AB700;
    // 0x801AB6F4: sw          $t4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r12;
L_801AB6F8:
    // 0x801AB6F8: addiu       $t3, $v1, 0x2
    ctx->r11 = ADD32(ctx->r3, 0X2);
    // 0x801AB6FC: sw          $t3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r11;
L_801AB700:
    // 0x801AB700: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801AB704: lw          $v0, -0x154C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X154C);
    // 0x801AB708: beql        $v0, $zero, L_801AB74C
    if (ctx->r2 == 0) {
        // 0x801AB70C: xori        $t6, $v0, 0x1
        ctx->r14 = ctx->r2 ^ 0X1;
            goto L_801AB74C;
    }
    goto skip_2;
    // 0x801AB70C: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    skip_2:
    // 0x801AB710: jal         0x8001AED4
    // 0x801AB714: nop

    Audio_GetCurrentVoiceStatus(rdram, ctx);
        goto after_10;
    // 0x801AB714: nop

    after_10:
    // 0x801AB718: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x801AB71C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801AB720: bne         $v0, $at, L_801AB73C
    if (ctx->r2 != ctx->r1) {
        // 0x801AB724: addiu       $a3, $a3, -0x7D4C
        ctx->r7 = ADD32(ctx->r7, -0X7D4C);
            goto L_801AB73C;
    }
    // 0x801AB724: addiu       $a3, $a3, -0x7D4C
    ctx->r7 = ADD32(ctx->r7, -0X7D4C);
    // 0x801AB728: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x801AB72C: sw          $t5, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r13;
    // 0x801AB730: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801AB734: b           L_801AB748
    // 0x801AB738: lw          $v0, -0x154C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X154C);
        goto L_801AB748;
    // 0x801AB738: lw          $v0, -0x154C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X154C);
L_801AB73C:
    // 0x801AB73C: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
    // 0x801AB740: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801AB744: lw          $v0, -0x154C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X154C);
L_801AB748:
    // 0x801AB748: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
L_801AB74C:
    // 0x801AB74C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801AB750: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801AB754: sw          $t6, -0x154C($at)
    MEM_W(-0X154C, ctx->r1) = ctx->r14;
    // 0x801AB758: b           L_801AB928
    // 0x801AB75C: lw          $v1, -0xFE8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0XFE8);
        goto L_801AB928;
    // 0x801AB75C: lw          $v1, -0xFE8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0XFE8);
    // 0x801AB760: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
L_801AB764:
    // 0x801AB764: lui         $t8, 0x801D
    ctx->r24 = S32(0X801D << 16);
    // 0x801AB768: bne         $t7, $zero, L_801AB928
    if (ctx->r15 != 0) {
        // 0x801AB76C: nop
    
            goto L_801AB928;
    }
    // 0x801AB76C: nop

    // 0x801AB770: lw          $t8, -0x26C0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X26C0);
    // 0x801AB774: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x801AB778: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x801AB77C: bne         $v1, $t8, L_801AB790
    if (ctx->r3 != ctx->r24) {
        // 0x801AB780: lui         $at, 0x801D
        ctx->r1 = S32(0X801D << 16);
            goto L_801AB790;
    }
    // 0x801AB780: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801AB784: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
    // 0x801AB788: b           L_801AB928
    // 0x801AB78C: sw          $v1, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r3;
        goto L_801AB928;
    // 0x801AB78C: sw          $v1, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r3;
L_801AB790:
    // 0x801AB790: sw          $v1, -0x26C0($at)
    MEM_W(-0X26C0, ctx->r1) = ctx->r3;
    // 0x801AB794: lui         $t4, 0x801D
    ctx->r12 = S32(0X801D << 16);
    // 0x801AB798: lui         $t5, 0x801D
    ctx->r13 = S32(0X801D << 16);
    // 0x801AB79C: lw          $t5, -0x26C0($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X26C0);
    // 0x801AB7A0: lw          $t4, -0x26AC($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X26AC);
    // 0x801AB7A4: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x801AB7A8: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x801AB7AC: sll         $t3, $t4, 3
    ctx->r11 = S32(ctx->r12 << 3);
    // 0x801AB7B0: addu        $t7, $t3, $t6
    ctx->r15 = ADD32(ctx->r11, ctx->r14);
    // 0x801AB7B4: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x801AB7B8: lw          $a0, -0xBD8($t8)
    ctx->r4 = MEM_W(ctx->r24, -0XBD8);
    // 0x801AB7BC: addiu       $v0, $v0, -0x7CF8
    ctx->r2 = ADD32(ctx->r2, -0X7CF8);
    // 0x801AB7C0: jal         0x800C2890
    // 0x801AB7C4: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    Message_IdFromPtr(rdram, ctx);
        goto after_11;
    // 0x801AB7C4: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    after_11:
    // 0x801AB7C8: jal         0x8001ACDC
    // 0x801AB7CC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    Audio_PlayVoice(rdram, ctx);
        goto after_12;
    // 0x801AB7CC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_12:
    // 0x801AB7D0: lui         $t9, 0x801D
    ctx->r25 = S32(0X801D << 16);
    // 0x801AB7D4: lw          $t9, -0x26C0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X26C0);
    // 0x801AB7D8: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x801AB7DC: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x801AB7E0: sll         $t4, $t9, 2
    ctx->r12 = S32(ctx->r25 << 2);
    // 0x801AB7E4: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x801AB7E8: lw          $t5, -0xBE0($t5)
    ctx->r13 = MEM_W(ctx->r13, -0XBE0);
    // 0x801AB7EC: addiu       $t2, $t2, 0x7D68
    ctx->r10 = ADD32(ctx->r10, 0X7D68);
    // 0x801AB7F0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801AB7F4: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x801AB7F8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801AB7FC: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801AB800: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801AB804: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x801AB808: addiu       $a2, $a2, -0x7D28
    ctx->r6 = ADD32(ctx->r6, -0X7D28);
    // 0x801AB80C: addiu       $a1, $a1, -0xEDC
    ctx->r5 = ADD32(ctx->r5, -0XEDC);
    // 0x801AB810: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x801AB814: swc1        $f6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f6.u32l;
    // 0x801AB818: lwc1        $f8, 0x0($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X0);
    // 0x801AB81C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x801AB820: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x801AB824: nop

    // 0x801AB828: sw          $t6, -0x7D5C($at)
    MEM_W(-0X7D5C, ctx->r1) = ctx->r14;
    // 0x801AB82C: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x801AB830: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
    // 0x801AB834: jal         0x800C2928
    // 0x801AB838: lw          $a0, -0x7CF8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7CF8);
    Message_GetCharCount(rdram, ctx);
        goto after_13;
    // 0x801AB838: lw          $a0, -0x7CF8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7CF8);
    after_13:
    // 0x801AB83C: sll         $t7, $v0, 1
    ctx->r15 = S32(ctx->r2 << 1);
    // 0x801AB840: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801AB844: sw          $t7, -0x7D54($at)
    MEM_W(-0X7D54, ctx->r1) = ctx->r15;
    // 0x801AB848: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801AB84C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801AB850: sw          $t8, -0x2660($at)
    MEM_W(-0X2660, ctx->r1) = ctx->r24;
    // 0x801AB854: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801AB858: sw          $zero, -0x265C($at)
    MEM_W(-0X265C, ctx->r1) = 0;
    // 0x801AB85C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801AB860: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x801AB864: sw          $t9, -0xFE8($at)
    MEM_W(-0XFE8, ctx->r1) = ctx->r25;
    // 0x801AB868: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801AB86C: b           L_801AB928
    // 0x801AB870: lw          $v1, -0xFE8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0XFE8);
        goto L_801AB928;
    // 0x801AB870: lw          $v1, -0xFE8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0XFE8);
L_801AB874:
    // 0x801AB874: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x801AB878: addiu       $t2, $t2, 0x7D68
    ctx->r10 = ADD32(ctx->r10, 0X7D68);
    // 0x801AB87C: lwc1        $f16, 0x0($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0X0);
    // 0x801AB880: addiu       $t4, $zero, 0x5
    ctx->r12 = ADD32(0, 0X5);
    // 0x801AB884: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
    // 0x801AB888: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x801AB88C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801AB890: addiu       $t6, $v1, 0x1
    ctx->r14 = ADD32(ctx->r3, 0X1);
    // 0x801AB894: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x801AB898: mfc1        $t3, $f18
    ctx->r11 = (int32_t)ctx->f18.u32l;
    // 0x801AB89C: nop

    // 0x801AB8A0: sw          $t3, -0x7D5C($at)
    MEM_W(-0X7D5C, ctx->r1) = ctx->r11;
    // 0x801AB8A4: b           L_801AB928
    // 0x801AB8A8: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
        goto L_801AB928;
    // 0x801AB8A8: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
L_801AB8AC:
    // 0x801AB8AC: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x801AB8B0: bne         $t7, $zero, L_801AB928
    if (ctx->r15 != 0) {
        // 0x801AB8B4: lui         $a0, 0x4100
        ctx->r4 = S32(0X4100 << 16);
            goto L_801AB928;
    }
    // 0x801AB8B4: lui         $a0, 0x4100
    ctx->r4 = S32(0X4100 << 16);
    // 0x801AB8B8: jal         0x8001A838
    // 0x801AB8BC: ori         $a0, $a0, 0x1E
    ctx->r4 = ctx->r4 | 0X1E;
    Audio_KillSfxById(rdram, ctx);
        goto after_14;
    // 0x801AB8BC: ori         $a0, $a0, 0x1E
    ctx->r4 = ctx->r4 | 0X1E;
    after_14:
    // 0x801AB8C0: jal         0x8001ACDC
    // 0x801AB8C4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    Audio_PlayVoice(rdram, ctx);
        goto after_15;
    // 0x801AB8C4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_15:
    // 0x801AB8C8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801AB8CC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801AB8D0: addiu       $t8, $zero, 0x7
    ctx->r24 = ADD32(0, 0X7);
    // 0x801AB8D4: swc1        $f0, 0x7D50($at)
    MEM_W(0X7D50, ctx->r1) = ctx->f0.u32l;
    // 0x801AB8D8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801AB8DC: sw          $t8, -0xFE8($at)
    MEM_W(-0XFE8, ctx->r1) = ctx->r24;
    // 0x801AB8E0: b           L_801AB928
    // 0x801AB8E4: addiu       $v1, $zero, 0x7
    ctx->r3 = ADD32(0, 0X7);
        goto L_801AB928;
    // 0x801AB8E4: addiu       $v1, $zero, 0x7
    ctx->r3 = ADD32(0, 0X7);
L_801AB8E8:
    // 0x801AB8E8: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x801AB8EC: addiu       $t2, $t2, 0x7D68
    ctx->r10 = ADD32(ctx->r10, 0X7D68);
    // 0x801AB8F0: lwc1        $f4, 0x0($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X0);
    // 0x801AB8F4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801AB8F8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801AB8FC: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x801AB900: addiu       $v0, $v0, -0x158C
    ctx->r2 = ADD32(ctx->r2, -0X158C);
    // 0x801AB904: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x801AB908: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x801AB90C: nop

    // 0x801AB910: sw          $t4, -0x7D5C($at)
    MEM_W(-0X7D5C, ctx->r1) = ctx->r12;
    // 0x801AB914: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801AB918: lwc1        $f8, 0x7B04($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7B04);
    // 0x801AB91C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801AB920: swc1        $f8, 0x7D50($at)
    MEM_W(0X7D50, ctx->r1) = ctx->f8.u32l;
    // 0x801AB924: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
L_801AB928:
    // 0x801AB928: blez        $v1, L_801AB968
    if (SIGNED(ctx->r3) <= 0) {
        // 0x801AB92C: addiu       $at, $zero, 0x64
        ctx->r1 = ADD32(0, 0X64);
            goto L_801AB968;
    }
    // 0x801AB92C: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x801AB930: beq         $v1, $at, L_801AB968
    if (ctx->r3 == ctx->r1) {
        // 0x801AB934: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_801AB968;
    }
    // 0x801AB934: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x801AB938: jal         0x801AB978
    // 0x801AB93C: lw          $a0, -0x7D5C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7D5C);
    Map_BriefingRadio_Draw(rdram, ctx);
        goto after_16;
    // 0x801AB93C: lw          $a0, -0x7D5C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7D5C);
    after_16:
    // 0x801AB940: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801AB944: lw          $v0, -0x26C0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X26C0);
    // 0x801AB948: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x801AB94C: sltiu       $t3, $v0, 0x1
    ctx->r11 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x801AB950: sll         $t6, $t3, 2
    ctx->r14 = S32(ctx->r11 << 2);
    // 0x801AB954: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x801AB958: jal         0x801AB978
    // 0x801AB95C: lw          $a0, -0xBE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0XBE0);
    Map_BriefingRadio_Draw(rdram, ctx);
        goto after_17;
    // 0x801AB95C: lw          $a0, -0xBE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0XBE0);
    after_17:
    // 0x801AB960: jal         0x800BB388
    // 0x801AB964: nop

    func_radio_800BB388(rdram, ctx);
        goto after_18;
    // 0x801AB964: nop

    after_18:
L_801AB968:
    // 0x801AB968: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801AB96C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801AB970: jr          $ra
    // 0x801AB974: nop

    return;
    // 0x801AB974: nop

;}
RECOMP_FUNC void Title_GreatFoxDeckLauncher_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80190B30: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80190B34: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80190B38: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80190B3C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80190B40: lwc1        $f4, -0x7D20($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7D20);
    // 0x80190B44: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80190B48: lwc1        $f8, -0x7D1C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X7D1C);
    // 0x80190B4C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80190B50: lwc1        $f16, -0x7D18($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X7D18);
    // 0x80190B54: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80190B58: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80190B5C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80190B60: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80190B64: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80190B68: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80190B6C: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80190B70: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80190B74: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80190B78: lw          $t4, -0x7AA4($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7AA4);
    // 0x80190B7C: lw          $t3, -0x7AA8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X7AA8);
    // 0x80190B80: lw          $t2, -0x7AAC($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X7AAC);
    // 0x80190B84: lw          $t1, -0x7AB0($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X7AB0);
    // 0x80190B88: lw          $t0, -0x7AB4($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7AB4);
    // 0x80190B8C: lw          $t9, -0x7AB8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7AB8);
    // 0x80190B90: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x80190B94: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80190B98: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80190B9C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80190BA0: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x80190BA4: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    // 0x80190BA8: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    // 0x80190BAC: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x80190BB0: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x80190BB4: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80190BB8: jal         0x8000372C
    // 0x80190BBC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    Lights_SetOneLight(rdram, ctx);
        goto after_0;
    // 0x80190BBC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_0:
    // 0x80190BC0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80190BC4: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x80190BC8: jal         0x800B8DD0
    // 0x80190BCC: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    RCP_SetupDL(rdram, ctx);
        goto after_1;
    // 0x80190BCC: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    after_1:
    // 0x80190BD0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80190BD4: jal         0x80005708
    // 0x80190BD8: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Push(rdram, ctx);
        goto after_2;
    // 0x80190BD8: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_2:
    // 0x80190BDC: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x80190BE0: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x80190BE4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80190BE8: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80190BEC: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x80190BF0: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80190BF4: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x80190BF8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80190BFC: addu        $a1, $a1, $t6
    ctx->r5 = ADD32(ctx->r5, ctx->r14);
    // 0x80190C00: lui         $a2, 0xC14C
    ctx->r6 = S32(0XC14C << 16);
    // 0x80190C04: lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // 0x80190C08: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80190C0C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80190C10: lw          $a3, -0x6FBC($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X6FBC);
    // 0x80190C14: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80190C18: lw          $a1, -0x7B18($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7B18);
    // 0x80190C1C: jal         0x80005B00
    // 0x80190C20: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Translate(rdram, ctx);
        goto after_3;
    // 0x80190C20: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_3:
    // 0x80190C24: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80190C28: lwc1        $f0, 0x70D0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X70D0);
    // 0x80190C2C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80190C30: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80190C34: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80190C38: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80190C3C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80190C40: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80190C44: jal         0x80005C34
    // 0x80190C48: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Scale(rdram, ctx);
        goto after_4;
    // 0x80190C48: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_4:
    // 0x80190C4C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80190C50: jal         0x80006EB8
    // 0x80190C54: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_5;
    // 0x80190C54: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    after_5:
    // 0x80190C58: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80190C5C: lw          $v1, 0x7E64($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7E64);
    // 0x80190C60: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80190C64: lui         $t1, 0x602
    ctx->r9 = S32(0X602 << 16);
    // 0x80190C68: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80190C6C: sw          $t9, 0x7E64($at)
    MEM_W(0X7E64, ctx->r1) = ctx->r25;
    // 0x80190C70: addiu       $t1, $t1, -0x3840
    ctx->r9 = ADD32(ctx->r9, -0X3840);
    // 0x80190C74: lui         $t0, 0x600
    ctx->r8 = S32(0X600 << 16);
    // 0x80190C78: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x80190C7C: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x80190C80: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80190C84: jal         0x80005740
    // 0x80190C88: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Pop(rdram, ctx);
        goto after_6;
    // 0x80190C88: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_6:
    // 0x80190C8C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80190C90: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80190C94: jr          $ra
    // 0x80190C98: nop

    return;
    // 0x80190C98: nop

;}
RECOMP_FUNC void Option_RankingRouteMedal_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80199198: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8019919C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801991A0: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    // 0x801991A4: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    // 0x801991A8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x801991AC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801991B0: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x801991B4: jal         0x800B8DD0
    // 0x801991B8: addiu       $a1, $zero, 0x35
    ctx->r5 = ADD32(0, 0X35);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x801991B8: addiu       $a1, $zero, 0x35
    ctx->r5 = ADD32(0, 0X35);
    after_0:
    // 0x801991BC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801991C0: jal         0x80005708
    // 0x801991C4: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Push(rdram, ctx);
        goto after_1;
    // 0x801991C4: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_1:
    // 0x801991C8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801991CC: lwc1        $f6, -0xEC0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0XEC0);
    // 0x801991D0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801991D4: lwc1        $f16, -0xEBC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0XEBC);
    // 0x801991D8: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x801991DC: lwc1        $f10, 0x24($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X24);
    // 0x801991E0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801991E4: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801991E8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801991EC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801991F0: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801991F4: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x801991F8: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x801991FC: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80199200: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80199204: jal         0x80005B00
    // 0x80199208: nop

    Matrix_Translate(rdram, ctx);
        goto after_2;
    // 0x80199208: nop

    after_2:
    // 0x8019920C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80199210: lwc1        $f0, -0xEC4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0XEC4);
    // 0x80199214: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80199218: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8019921C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80199220: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80199224: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80199228: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8019922C: jal         0x80005C34
    // 0x80199230: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Scale(rdram, ctx);
        goto after_3;
    // 0x80199230: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_3:
    // 0x80199234: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80199238: jal         0x80006EB8
    // 0x8019923C: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_4;
    // 0x8019923C: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    after_4:
    // 0x80199240: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80199244: lw          $v1, 0x7E64($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7E64);
    // 0x80199248: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8019924C: lui         $t0, 0x602
    ctx->r8 = S32(0X602 << 16);
    // 0x80199250: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80199254: sw          $t8, 0x7E64($at)
    MEM_W(0X7E64, ctx->r1) = ctx->r24;
    // 0x80199258: addiu       $t0, $t0, -0x2E10
    ctx->r8 = ADD32(ctx->r8, -0X2E10);
    // 0x8019925C: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x80199260: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80199264: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x80199268: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8019926C: jal         0x80005740
    // 0x80199270: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Pop(rdram, ctx);
        goto after_5;
    // 0x80199270: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_5:
    // 0x80199274: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80199278: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8019927C: jr          $ra
    // 0x80199280: nop

    return;
    // 0x80199280: nop

;}
RECOMP_FUNC void Map_801A3550(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A3550: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801A3554: mtc1        $a3, $f12
    ctx->f12.u32l = ctx->r7;
    // 0x801A3558: sdc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X8, ctx->r29);
    // 0x801A355C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801A3560: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801A3564: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801A3568: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801A356C: sub.s       $f2, $f4, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f12.fl;
    // 0x801A3570: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801A3574: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801A3578: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801A357C: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x801A3580: sub.s       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f12.fl;
    // 0x801A3584: mul.s       $f14, $f6, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x801A3588: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801A358C: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x801A3590: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801A3594: mul.s       $f10, $f12, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x801A3598: add.s       $f18, $f6, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801A359C: mul.s       $f20, $f10, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x801A35A0: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x801A35A4: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x801A35A8: lwc1        $f10, 0xC($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0XC);
    // 0x801A35AC: mul.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x801A35B0: nop

    // 0x801A35B4: mul.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x801A35B8: lwc1        $f10, 0x18($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X18);
    // 0x801A35BC: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x801A35C0: mul.s       $f8, $f20, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f10.fl);
    // 0x801A35C4: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801A35C8: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x801A35CC: lwc1        $f10, 0x4($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X4);
    // 0x801A35D0: lwc1        $f8, 0x10($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X10);
    // 0x801A35D4: mul.s       $f6, $f10, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x801A35D8: nop

    // 0x801A35DC: mul.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x801A35E0: lwc1        $f8, 0x1C($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x801A35E4: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x801A35E8: mul.s       $f6, $f20, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f8.fl);
    // 0x801A35EC: add.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x801A35F0: swc1        $f4, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f4.u32l;
    // 0x801A35F4: lwc1        $f8, 0x8($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X8);
    // 0x801A35F8: lwc1        $f6, 0x14($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X14);
    // 0x801A35FC: mul.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x801A3600: nop

    // 0x801A3604: mul.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x801A3608: lwc1        $f6, 0x20($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X20);
    // 0x801A360C: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x801A3610: mul.s       $f10, $f20, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f20.fl, ctx->f6.fl);
    // 0x801A3614: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801A3618: swc1        $f4, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f4.u32l;
    // 0x801A361C: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    // 0x801A3620: lwc1        $f10, 0xC($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0XC);
    // 0x801A3624: mul.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x801A3628: nop

    // 0x801A362C: mul.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x801A3630: lwc1        $f10, 0x18($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X18);
    // 0x801A3634: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x801A3638: mul.s       $f8, $f20, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f10.fl);
    // 0x801A363C: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801A3640: swc1        $f4, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f4.u32l;
    // 0x801A3644: lwc1        $f10, 0x4($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X4);
    // 0x801A3648: lwc1        $f8, 0x10($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X10);
    // 0x801A364C: mul.s       $f6, $f10, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x801A3650: nop

    // 0x801A3654: mul.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x801A3658: lwc1        $f8, 0x14($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X14);
    // 0x801A365C: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x801A3660: lwc1        $f6, 0x1C($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X1C);
    // 0x801A3664: mul.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x801A3668: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x801A366C: swc1        $f8, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f8.u32l;
    // 0x801A3670: lwc1        $f6, 0x8($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X8);
    // 0x801A3674: lwc1        $f4, 0x14($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X14);
    // 0x801A3678: mul.s       $f10, $f6, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x801A367C: nop

    // 0x801A3680: mul.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x801A3684: lwc1        $f4, 0x14($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X14);
    // 0x801A3688: add.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x801A368C: lwc1        $f10, 0x20($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X20);
    // 0x801A3690: mul.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x801A3694: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801A3698: swc1        $f4, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f4.u32l;
    // 0x801A369C: ldc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X8);
    // 0x801A36A0: jr          $ra
    // 0x801A36A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x801A36A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void Option_Input_DataSelect_X(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019C5A0: addiu       $t0, $zero, 0x6
    ctx->r8 = ADD32(0, 0X6);
    // 0x8019C5A4: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x8019C5A8: lw          $t6, 0x7AF8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7AF8);
    // 0x8019C5AC: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8019C5B0: addiu       $t8, $t8, -0x2768
    ctx->r24 = ADD32(ctx->r24, -0X2768);
    // 0x8019C5B4: multu       $t6, $t0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8019C5B8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8019C5BC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8019C5C0: mflo        $t7
    ctx->r15 = lo;
    // 0x8019C5C4: addu        $a2, $t7, $t8
    ctx->r6 = ADD32(ctx->r15, ctx->r24);
    // 0x8019C5C8: lb          $a3, 0x3($a2)
    ctx->r7 = MEM_B(ctx->r6, 0X3);
    // 0x8019C5CC: lb          $a1, 0x2($a2)
    ctx->r5 = MEM_B(ctx->r6, 0X2);
    // 0x8019C5D0: negu        $a3, $a3
    ctx->r7 = SUB32(0, ctx->r7);
    // 0x8019C5D4: slti        $at, $a3, 0x29
    ctx->r1 = SIGNED(ctx->r7) < 0X29 ? 1 : 0;
    // 0x8019C5D8: beq         $at, $zero, L_8019C5E8
    if (ctx->r1 == 0) {
        // 0x8019C5DC: slti        $at, $a3, -0x28
        ctx->r1 = SIGNED(ctx->r7) < -0X28 ? 1 : 0;
            goto L_8019C5E8;
    }
    // 0x8019C5DC: slti        $at, $a3, -0x28
    ctx->r1 = SIGNED(ctx->r7) < -0X28 ? 1 : 0;
    // 0x8019C5E0: beq         $at, $zero, L_8019C5F0
    if (ctx->r1 == 0) {
        // 0x8019C5E4: lui         $a3, 0x801C
        ctx->r7 = S32(0X801C << 16);
            goto L_8019C5F0;
    }
    // 0x8019C5E4: lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
L_8019C5E8:
    // 0x8019C5E8: jr          $ra
    // 0x8019C5EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8019C5EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8019C5F0:
    // 0x8019C5F0: slti        $at, $a1, 0x1E
    ctx->r1 = SIGNED(ctx->r5) < 0X1E ? 1 : 0;
    // 0x8019C5F4: beq         $at, $zero, L_8019C60C
    if (ctx->r1 == 0) {
        // 0x8019C5F8: addiu       $a3, $a3, -0x6E60
        ctx->r7 = ADD32(ctx->r7, -0X6E60);
            goto L_8019C60C;
    }
    // 0x8019C5F8: addiu       $a3, $a3, -0x6E60
    ctx->r7 = ADD32(ctx->r7, -0X6E60);
    // 0x8019C5FC: slti        $at, $a1, -0x1D
    ctx->r1 = SIGNED(ctx->r5) < -0X1D ? 1 : 0;
    // 0x8019C600: bnel        $at, $zero, L_8019C610
    if (ctx->r1 != 0) {
        // 0x8019C604: lw          $a2, 0x0($a3)
        ctx->r6 = MEM_W(ctx->r7, 0X0);
            goto L_8019C610;
    }
    goto skip_0;
    // 0x8019C604: lw          $a2, 0x0($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X0);
    skip_0:
    // 0x8019C608: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_8019C60C:
    // 0x8019C60C: lw          $a2, 0x0($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X0);
L_8019C610:
    // 0x8019C610: bne         $a2, $zero, L_8019C644
    if (ctx->r6 != 0) {
        // 0x8019C614: nop
    
            goto L_8019C644;
    }
    // 0x8019C614: nop

    // 0x8019C618: beq         $a1, $zero, L_8019C644
    if (ctx->r5 == 0) {
        // 0x8019C61C: nop
    
            goto L_8019C644;
    }
    // 0x8019C61C: nop

    // 0x8019C620: blez        $a1, L_8019C630
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8019C624: or          $a2, $t0, $zero
        ctx->r6 = ctx->r8 | 0;
            goto L_8019C630;
    }
    // 0x8019C624: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
    // 0x8019C628: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x8019C62C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8019C630:
    // 0x8019C630: bgez        $a1, L_8019C640
    if (SIGNED(ctx->r5) >= 0) {
        // 0x8019C634: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_8019C640;
    }
    // 0x8019C634: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8019C638: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8019C63C: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
L_8019C640:
    // 0x8019C640: sw          $t0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r8;
L_8019C644:
    // 0x8019C644: blez        $a2, L_8019C650
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8019C648: addiu       $t1, $a2, -0x1
        ctx->r9 = ADD32(ctx->r6, -0X1);
            goto L_8019C650;
    }
    // 0x8019C648: addiu       $t1, $a2, -0x1
    ctx->r9 = ADD32(ctx->r6, -0X1);
    // 0x8019C64C: sw          $t1, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r9;
L_8019C650:
    // 0x8019C650: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x8019C654: bnel        $v0, $t2, L_8019C664
    if (ctx->r2 != ctx->r10) {
        // 0x8019C658: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8019C664;
    }
    goto skip_1;
    // 0x8019C658: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_1:
    // 0x8019C65C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8019C660: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8019C664:
    // 0x8019C664: jr          $ra
    // 0x8019C668: nop

    return;
    // 0x8019C668: nop

;}
RECOMP_FUNC void Map_PositionCursor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A914C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801A9150: addiu       $v1, $v1, -0x1558
    ctx->r3 = ADD32(ctx->r3, -0X1558);
    // 0x801A9154: lui         $at, 0x430C
    ctx->r1 = S32(0X430C << 16);
    // 0x801A9158: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801A915C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801A9160: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x801A9164: swc1        $f4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f4.u32l;
    // 0x801A9168: lw          $v0, -0x26AC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X26AC);
    // 0x801A916C: bne         $v0, $at, L_801A9180
    if (ctx->r2 != ctx->r1) {
        // 0x801A9170: lui         $at, 0x4366
        ctx->r1 = S32(0X4366 << 16);
            goto L_801A9180;
    }
    // 0x801A9170: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x801A9174: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801A9178: nop

    // 0x801A917C: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
L_801A9180:
    // 0x801A9180: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801A9184: bne         $v0, $at, L_801A9198
    if (ctx->r2 != ctx->r1) {
        // 0x801A9188: lui         $at, 0x4352
        ctx->r1 = S32(0X4352 << 16);
            goto L_801A9198;
    }
    // 0x801A9188: lui         $at, 0x4352
    ctx->r1 = S32(0X4352 << 16);
    // 0x801A918C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801A9190: nop

    // 0x801A9194: swc1        $f8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f8.u32l;
L_801A9198:
    // 0x801A9198: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x801A919C: bne         $v0, $at, L_801A91B0
    if (ctx->r2 != ctx->r1) {
        // 0x801A91A0: lui         $at, 0x437A
        ctx->r1 = S32(0X437A << 16);
            goto L_801A91B0;
    }
    // 0x801A91A0: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x801A91A4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801A91A8: nop

    // 0x801A91AC: swc1        $f10, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f10.u32l;
L_801A91B0:
    // 0x801A91B0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x801A91B4: bne         $v0, $at, L_801A91C8
    if (ctx->r2 != ctx->r1) {
        // 0x801A91B8: lui         $at, 0x4316
        ctx->r1 = S32(0X4316 << 16);
            goto L_801A91C8;
    }
    // 0x801A91B8: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x801A91BC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801A91C0: nop

    // 0x801A91C4: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
L_801A91C8:
    // 0x801A91C8: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x801A91CC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801A91D0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x801A91D4: bnel        $v0, $at, L_801A91E4
    if (ctx->r2 != ctx->r1) {
        // 0x801A91D8: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_801A91E4;
    }
    goto skip_0;
    // 0x801A91D8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    skip_0:
    // 0x801A91DC: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x801A91E0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
L_801A91E4:
    // 0x801A91E4: bnel        $v0, $at, L_801A91F4
    if (ctx->r2 != ctx->r1) {
        // 0x801A91E8: addiu       $at, $zero, 0xD
        ctx->r1 = ADD32(0, 0XD);
            goto L_801A91F4;
    }
    goto skip_1;
    // 0x801A91E8: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    skip_1:
    // 0x801A91EC: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x801A91F0: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
L_801A91F4:
    // 0x801A91F4: bne         $v0, $at, L_801A9208
    if (ctx->r2 != ctx->r1) {
        // 0x801A91F8: lui         $at, 0x4396
        ctx->r1 = S32(0X4396 << 16);
            goto L_801A9208;
    }
    // 0x801A91F8: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x801A91FC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801A9200: nop

    // 0x801A9204: swc1        $f16, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f16.u32l;
L_801A9208:
    // 0x801A9208: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    // 0x801A920C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A9210: swc1        $f0, -0x1554($at)
    MEM_W(-0X1554, ctx->r1) = ctx->f0.u32l;
    // 0x801A9214: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A9218: swc1        $f0, -0x1550($at)
    MEM_W(-0X1550, ctx->r1) = ctx->f0.u32l;
    // 0x801A921C: jr          $ra
    // 0x801A9220: nop

    return;
    // 0x801A9220: nop

;}
RECOMP_FUNC void Option_Data_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80196894: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x80196898: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8019689C: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x801968A0: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x801968A4: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x801968A8: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x801968AC: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x801968B0: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x801968B4: jal         0x8019B9C0
    // 0x801968B8: nop

    Option_DrawMenuLabel(rdram, ctx);
        goto after_0;
    // 0x801968B8: nop

    after_0:
    // 0x801968BC: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x801968C0: addiu       $s2, $s2, 0x7E64
    ctx->r18 = ADD32(ctx->r18, 0X7E64);
    // 0x801968C4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x801968C8: jal         0x800B8DD0
    // 0x801968CC: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    RCP_SetupDL(rdram, ctx);
        goto after_1;
    // 0x801968CC: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    after_1:
    // 0x801968D0: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x801968D4: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x801968D8: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x801968DC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801968E0: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
    // 0x801968E4: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x801968E8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801968EC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801968F0: lui         $s1, 0x801
    ctx->r17 = S32(0X801 << 16);
    // 0x801968F4: lui         $s4, 0x801B
    ctx->r20 = S32(0X801B << 16);
    // 0x801968F8: lui         $s3, 0x801B
    ctx->r19 = S32(0X801B << 16);
    // 0x801968FC: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80196900: addiu       $s3, $s3, -0xF6C
    ctx->r19 = ADD32(ctx->r19, -0XF6C);
    // 0x80196904: addiu       $s4, $s4, -0xF54
    ctx->r20 = ADD32(ctx->r20, -0XF54);
    // 0x80196908: addiu       $s1, $s1, -0x7B50
    ctx->r17 = ADD32(ctx->r17, -0X7B50);
    // 0x8019690C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80196910:
    // 0x80196910: mtc1        $s0, $f8
    ctx->f8.u32l = ctx->r16;
    // 0x80196914: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80196918: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8019691C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80196920: lwc1        $f4, 0x0($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X0);
    // 0x80196924: lwc1        $f18, 0x0($s4)
    ctx->f18.u32l = MEM_W(ctx->r20, 0X0);
    // 0x80196928: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8019692C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80196930: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80196934: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80196938: addiu       $a2, $zero, 0xB0
    ctx->r6 = ADD32(0, 0XB0);
    // 0x8019693C: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x80196940: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x80196944: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80196948: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x8019694C: jal         0x8009D994
    // 0x80196950: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_2;
    // 0x80196950: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x80196954: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80196958: slti        $at, $s0, 0x2
    ctx->r1 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
    // 0x8019695C: bne         $at, $zero, L_80196910
    if (ctx->r1 != 0) {
        // 0x80196960: addiu       $s1, $s1, 0x2C0
        ctx->r17 = ADD32(ctx->r17, 0X2C0);
            goto L_80196910;
    }
    // 0x80196960: addiu       $s1, $s1, 0x2C0
    ctx->r17 = ADD32(ctx->r17, 0X2C0);
    // 0x80196964: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80196968: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8019696C: lwc1        $f6, 0x0($s4)
    ctx->f6.u32l = MEM_W(ctx->r20, 0X0);
    // 0x80196970: lwc1        $f8, 0x0($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X0);
    // 0x80196974: lui         $a1, 0x801
    ctx->r5 = S32(0X801 << 16);
    // 0x80196978: add.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8019697C: addiu       $a1, $a1, -0x75D0
    ctx->r5 = ADD32(ctx->r5, -0X75D0);
    // 0x80196980: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80196984: addiu       $a2, $zero, 0xB0
    ctx->r6 = ADD32(0, 0XB0);
    // 0x80196988: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x8019698C: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x80196990: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x80196994: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80196998: jal         0x8009D994
    // 0x8019699C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_3;
    // 0x8019699C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_3:
    // 0x801969A0: lui         $t9, 0x801C
    ctx->r25 = S32(0X801C << 16);
    // 0x801969A4: lw          $t9, -0x6E34($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X6E34);
    // 0x801969A8: lui         $s0, 0x801
    ctx->r16 = S32(0X801 << 16);
    // 0x801969AC: addiu       $s0, $s0, -0x1ED0
    ctx->r16 = ADD32(ctx->r16, -0X1ED0);
    // 0x801969B0: slti        $at, $t9, 0x2
    ctx->r1 = SIGNED(ctx->r25) < 0X2 ? 1 : 0;
    // 0x801969B4: beq         $at, $zero, L_80196C00
    if (ctx->r1 == 0) {
        // 0x801969B8: lui         $s1, 0x801C
        ctx->r17 = S32(0X801C << 16);
            goto L_80196C00;
    }
    // 0x801969B8: lui         $s1, 0x801C
    ctx->r17 = S32(0X801C << 16);
    // 0x801969BC: addiu       $s1, $s1, -0x6E40
    ctx->r17 = ADD32(ctx->r17, -0X6E40);
    // 0x801969C0: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x801969C4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801969C8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x801969CC: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x801969D0: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x801969D4: lwc1        $f16, -0xF7C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0XF7C);
    // 0x801969D8: lui         $at, 0x430C
    ctx->r1 = S32(0X430C << 16);
    // 0x801969DC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801969E0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x801969E4: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x801969E8: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    // 0x801969EC: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x801969F0: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x801969F4: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x801969F8: jal         0x8009E1E8
    // 0x801969FC: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    Lib_TextureRect_IA8_MirX(rdram, ctx);
        goto after_4;
    // 0x801969FC: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_4:
    // 0x80196A00: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x80196A04: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80196A08: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80196A0C: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80196A10: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x80196A14: lwc1        $f8, -0xF74($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0XF74);
    // 0x80196A18: lui         $at, 0x430C
    ctx->r1 = S32(0X430C << 16);
    // 0x80196A1C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80196A20: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80196A24: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80196A28: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    // 0x80196A2C: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x80196A30: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80196A34: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x80196A38: jal         0x8009D994
    // 0x80196A3C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_5;
    // 0x80196A3C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_5:
    // 0x80196A40: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x80196A44: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x80196A48: addiu       $t7, $t7, -0x12E0
    ctx->r15 = ADD32(ctx->r15, -0X12E0);
    // 0x80196A4C: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80196A50: jal         0x8019C824
    // 0x80196A54: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    Option_Color_FlashRed(rdram, ctx);
        goto after_6;
    // 0x80196A54: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    after_6:
    // 0x80196A58: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80196A5C: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80196A60: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80196A64: sltiu       $t8, $a0, 0x1
    ctx->r24 = ctx->r4 < 0X1 ? 1 : 0;
    // 0x80196A68: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80196A6C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80196A70: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80196A74: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80196A78: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80196A7C: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80196A80: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x80196A84: sw          $t2, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r10;
    // 0x80196A88: sw          $t1, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r9;
    // 0x80196A8C: addiu       $t0, $t0, -0x6CC8
    ctx->r8 = ADD32(ctx->r8, -0X6CC8);
    // 0x80196A90: addiu       $v0, $v0, -0x6CD0
    ctx->r2 = ADD32(ctx->r2, -0X6CD0);
    // 0x80196A94: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80196A98: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80196A9C: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x80196AA0: addiu       $a2, $sp, 0x7C
    ctx->r6 = ADD32(ctx->r29, 0X7C);
    // 0x80196AA4: addiu       $a1, $sp, 0x74
    ctx->r5 = ADD32(ctx->r29, 0X74);
    // 0x80196AA8: swc1        $f10, -0x12E0($at)
    MEM_W(-0X12E0, ctx->r1) = ctx->f10.u32l;
L_80196AAC:
    // 0x80196AAC: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x80196AB0: addu        $t3, $a1, $v1
    ctx->r11 = ADD32(ctx->r5, ctx->r3);
    // 0x80196AB4: addu        $t4, $a2, $v1
    ctx->r12 = ADD32(ctx->r6, ctx->r3);
    // 0x80196AB8: beq         $a0, $zero, L_80196ACC
    if (ctx->r4 == 0) {
        // 0x80196ABC: addiu       $t5, $a0, -0x1
        ctx->r13 = ADD32(ctx->r4, -0X1);
            goto L_80196ACC;
    }
    // 0x80196ABC: addiu       $t5, $a0, -0x1
    ctx->r13 = ADD32(ctx->r4, -0X1);
    // 0x80196AC0: sw          $s0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r16;
    // 0x80196AC4: sw          $a3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r7;
    // 0x80196AC8: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
L_80196ACC:
    // 0x80196ACC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80196AD0: bne         $v0, $t0, L_80196AAC
    if (ctx->r2 != ctx->r8) {
        // 0x80196AD4: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_80196AAC;
    }
    // 0x80196AD4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80196AD8: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80196ADC: lw          $v0, 0x7DB0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7DB0);
    // 0x80196AE0: lw          $t6, 0x78($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X78);
    // 0x80196AE4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80196AE8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80196AEC: and         $t7, $t6, $v0
    ctx->r15 = ctx->r14 & ctx->r2;
    // 0x80196AF0: beq         $t7, $zero, L_80196B74
    if (ctx->r15 == 0) {
        // 0x80196AF4: lui         $a1, 0x801
        ctx->r5 = S32(0X801 << 16);
            goto L_80196B74;
    }
    // 0x80196AF4: lui         $a1, 0x801
    ctx->r5 = S32(0X801 << 16);
    // 0x80196AF8: lwc1        $f18, -0x12DC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X12DC);
    // 0x80196AFC: addiu       $a1, $a1, -0x6680
    ctx->r5 = ADD32(ctx->r5, -0X6680);
    // 0x80196B00: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x80196B04: trunc.w.s   $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80196B08: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    // 0x80196B0C: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
    // 0x80196B10: nop

    // 0x80196B14: sw          $t9, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r25;
    // 0x80196B18: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80196B1C: lui         $t2, 0xFA00
    ctx->r10 = S32(0XFA00 << 16);
    // 0x80196B20: lui         $at, 0xFF00
    ctx->r1 = S32(0XFF00 << 16);
    // 0x80196B24: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x80196B28: sw          $t1, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r9;
    // 0x80196B2C: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x80196B30: lw          $t0, 0x80($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X80);
    // 0x80196B34: andi        $t3, $t0, 0xFF
    ctx->r11 = ctx->r8 & 0XFF;
    // 0x80196B38: sll         $t4, $t3, 8
    ctx->r12 = S32(ctx->r11 << 8);
    // 0x80196B3C: or          $t5, $t4, $at
    ctx->r13 = ctx->r12 | ctx->r1;
    // 0x80196B40: sll         $t6, $t3, 16
    ctx->r14 = S32(ctx->r11 << 16);
    // 0x80196B44: or          $t7, $t5, $t6
    ctx->r15 = ctx->r13 | ctx->r14;
    // 0x80196B48: ori         $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 | 0XFF;
    // 0x80196B4C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80196B50: lwc1        $f4, 0x4($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X4);
    // 0x80196B54: lwc1        $f8, 0x4($s4)
    ctx->f8.u32l = MEM_W(ctx->r20, 0X4);
    // 0x80196B58: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x80196B5C: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80196B60: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80196B64: jal         0x8009D994
    // 0x80196B68: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_7;
    // 0x80196B68: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_7:
    // 0x80196B6C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80196B70: lw          $v0, 0x7DB0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7DB0);
L_80196B74:
    // 0x80196B74: lw          $t9, 0x74($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X74);
    // 0x80196B78: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80196B7C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80196B80: and         $t1, $t9, $v0
    ctx->r9 = ctx->r25 & ctx->r2;
    // 0x80196B84: beq         $t1, $zero, L_80196C00
    if (ctx->r9 == 0) {
        // 0x80196B88: lui         $a1, 0x801
        ctx->r5 = S32(0X801 << 16);
            goto L_80196C00;
    }
    // 0x80196B88: lui         $a1, 0x801
    ctx->r5 = S32(0X801 << 16);
    // 0x80196B8C: lwc1        $f6, -0x12E0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X12E0);
    // 0x80196B90: addiu       $a1, $a1, -0x6500
    ctx->r5 = ADD32(ctx->r5, -0X6500);
    // 0x80196B94: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    // 0x80196B98: trunc.w.s   $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80196B9C: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    // 0x80196BA0: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
    // 0x80196BA4: nop

    // 0x80196BA8: sw          $t3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r11;
    // 0x80196BAC: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80196BB0: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x80196BB4: lui         $at, 0xFF00
    ctx->r1 = S32(0XFF00 << 16);
    // 0x80196BB8: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x80196BBC: sw          $t4, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r12;
    // 0x80196BC0: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80196BC4: lw          $t0, 0x7C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X7C);
    // 0x80196BC8: andi        $t6, $t0, 0xFF
    ctx->r14 = ctx->r8 & 0XFF;
    // 0x80196BCC: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x80196BD0: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x80196BD4: sll         $t9, $t6, 16
    ctx->r25 = S32(ctx->r14 << 16);
    // 0x80196BD8: or          $t1, $t8, $t9
    ctx->r9 = ctx->r24 | ctx->r25;
    // 0x80196BDC: ori         $t2, $t1, 0xFF
    ctx->r10 = ctx->r9 | 0XFF;
    // 0x80196BE0: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x80196BE4: lwc1        $f18, 0x8($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0X8);
    // 0x80196BE8: lwc1        $f16, 0x8($s4)
    ctx->f16.u32l = MEM_W(ctx->r20, 0X8);
    // 0x80196BEC: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x80196BF0: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80196BF4: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x80196BF8: jal         0x8009D994
    // 0x80196BFC: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_8;
    // 0x80196BFC: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    after_8:
L_80196C00:
    // 0x80196C00: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80196C04: lw          $a0, -0x6E34($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6E34);
    // 0x80196C08: lui         $s1, 0x801
    ctx->r17 = S32(0X801 << 16);
    // 0x80196C0C: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80196C10: beq         $a0, $zero, L_80196C38
    if (ctx->r4 == 0) {
        // 0x80196C14: addiu       $s1, $s1, -0x7260
        ctx->r17 = ADD32(ctx->r17, -0X7260);
            goto L_80196C38;
    }
    // 0x80196C14: addiu       $s1, $s1, -0x7260
    ctx->r17 = ADD32(ctx->r17, -0X7260);
    // 0x80196C18: beq         $a0, $s0, L_80196CE8
    if (ctx->r4 == ctx->r16) {
        // 0x80196C1C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80196CE8;
    }
    // 0x80196C1C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80196C20: beq         $a0, $at, L_80196CE8
    if (ctx->r4 == ctx->r1) {
        // 0x80196C24: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80196CE8;
    }
    // 0x80196C24: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80196C28: beq         $a0, $at, L_80196DA0
    if (ctx->r4 == ctx->r1) {
        // 0x80196C2C: lui         $t1, 0xFA00
        ctx->r9 = S32(0XFA00 << 16);
            goto L_80196DA0;
    }
    // 0x80196C2C: lui         $t1, 0xFA00
    ctx->r9 = S32(0XFA00 << 16);
    // 0x80196C30: b           L_80196E28
    // 0x80196C34: nop

        goto L_80196E28;
    // 0x80196C34: nop

L_80196C38:
    // 0x80196C38: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80196C3C: lui         $t4, 0xFA00
    ctx->r12 = S32(0XFA00 << 16);
    // 0x80196C40: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80196C44: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x80196C48: sw          $t3, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r11;
    // 0x80196C4C: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x80196C50: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80196C54: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80196C58:
    // 0x80196C58: mtc1        $s0, $f8
    ctx->f8.u32l = ctx->r16;
    // 0x80196C5C: lwc1        $f6, 0xC($s4)
    ctx->f6.u32l = MEM_W(ctx->r20, 0XC);
    // 0x80196C60: lwc1        $f4, 0xC($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0XC);
    // 0x80196C64: cvt.s.w     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    ctx->f0.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80196C68: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80196C6C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80196C70: addiu       $a2, $zero, 0xA0
    ctx->r6 = ADD32(0, 0XA0);
    // 0x80196C74: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x80196C78: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x80196C7C: add.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x80196C80: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80196C84: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80196C88: add.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80196C8C: jal         0x8009D994
    // 0x80196C90: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_9;
    // 0x80196C90: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_9:
    // 0x80196C94: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80196C98: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80196C9C: bne         $s0, $at, L_80196C58
    if (ctx->r16 != ctx->r1) {
        // 0x80196CA0: addiu       $s1, $s1, 0x140
        ctx->r17 = ADD32(ctx->r17, 0X140);
            goto L_80196C58;
    }
    // 0x80196CA0: addiu       $s1, $s1, 0x140
    ctx->r17 = ADD32(ctx->r17, 0X140);
    // 0x80196CA4: lui         $at, 0x4190
    ctx->r1 = S32(0X4190 << 16);
    // 0x80196CA8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80196CAC: lwc1        $f4, 0xC($s4)
    ctx->f4.u32l = MEM_W(ctx->r20, 0XC);
    // 0x80196CB0: lwc1        $f16, 0xC($s3)
    ctx->f16.u32l = MEM_W(ctx->r19, 0XC);
    // 0x80196CB4: lui         $a1, 0x801
    ctx->r5 = S32(0X801 << 16);
    // 0x80196CB8: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80196CBC: addiu       $a1, $a1, -0x6720
    ctx->r5 = ADD32(ctx->r5, -0X6720);
    // 0x80196CC0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80196CC4: addiu       $a2, $zero, 0xA0
    ctx->r6 = ADD32(0, 0XA0);
    // 0x80196CC8: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x80196CCC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80196CD0: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x80196CD4: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80196CD8: jal         0x8009D994
    // 0x80196CDC: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_10;
    // 0x80196CDC: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_10:
    // 0x80196CE0: b           L_80196E28
    // 0x80196CE4: nop

        goto L_80196E28;
    // 0x80196CE4: nop

L_80196CE8:
    // 0x80196CE8: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80196CEC: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x80196CF0: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80196CF4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80196CF8: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
    // 0x80196CFC: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80196D00: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80196D04: lui         $s1, 0x801
    ctx->r17 = S32(0X801 << 16);
    // 0x80196D08: addiu       $s1, $s1, -0x6320
    ctx->r17 = ADD32(ctx->r17, -0X6320);
    // 0x80196D0C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80196D10:
    // 0x80196D10: mtc1        $s0, $f18
    ctx->f18.u32l = ctx->r16;
    // 0x80196D14: lwc1        $f16, 0x10($s4)
    ctx->f16.u32l = MEM_W(ctx->r20, 0X10);
    // 0x80196D18: lwc1        $f10, 0x10($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X10);
    // 0x80196D1C: cvt.s.w     $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80196D20: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80196D24: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80196D28: addiu       $a2, $zero, 0xA0
    ctx->r6 = ADD32(0, 0XA0);
    // 0x80196D2C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x80196D30: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x80196D34: add.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x80196D38: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80196D3C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x80196D40: add.s       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x80196D44: jal         0x8009D994
    // 0x80196D48: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_11;
    // 0x80196D48: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_11:
    // 0x80196D4C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80196D50: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x80196D54: bne         $s0, $at, L_80196D10
    if (ctx->r16 != ctx->r1) {
        // 0x80196D58: addiu       $s1, $s1, 0x140
        ctx->r17 = ADD32(ctx->r17, 0X140);
            goto L_80196D10;
    }
    // 0x80196D58: addiu       $s1, $s1, 0x140
    ctx->r17 = ADD32(ctx->r17, 0X140);
    // 0x80196D5C: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80196D60: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80196D64: lwc1        $f10, 0x10($s4)
    ctx->f10.u32l = MEM_W(ctx->r20, 0X10);
    // 0x80196D68: lwc1        $f6, 0x10($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X10);
    // 0x80196D6C: lui         $a1, 0x801
    ctx->r5 = S32(0X801 << 16);
    // 0x80196D70: add.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x80196D74: addiu       $a1, $a1, -0x4A20
    ctx->r5 = ADD32(ctx->r5, -0X4A20);
    // 0x80196D78: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80196D7C: addiu       $a2, $zero, 0xA0
    ctx->r6 = ADD32(0, 0XA0);
    // 0x80196D80: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x80196D84: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80196D88: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x80196D8C: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80196D90: jal         0x8009D994
    // 0x80196D94: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_12;
    // 0x80196D94: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_12:
    // 0x80196D98: b           L_80196E28
    // 0x80196D9C: nop

        goto L_80196E28;
    // 0x80196D9C: nop

L_80196DA0:
    // 0x80196DA0: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80196DA4: lui         $t2, 0xFF20
    ctx->r10 = S32(0XFF20 << 16);
    // 0x80196DA8: ori         $t2, $t2, 0x20FF
    ctx->r10 = ctx->r10 | 0X20FF;
    // 0x80196DAC: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80196DB0: sw          $t9, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r25;
    // 0x80196DB4: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x80196DB8: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x80196DBC: lwc1        $f4, 0x14($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X14);
    // 0x80196DC0: lwc1        $f8, 0x14($s4)
    ctx->f8.u32l = MEM_W(ctx->r20, 0X14);
    // 0x80196DC4: lui         $a1, 0x801
    ctx->r5 = S32(0X801 << 16);
    // 0x80196DC8: addiu       $a1, $a1, -0x4980
    ctx->r5 = ADD32(ctx->r5, -0X4980);
    // 0x80196DCC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80196DD0: addiu       $a2, $zero, 0x90
    ctx->r6 = ADD32(0, 0X90);
    // 0x80196DD4: addiu       $a3, $zero, 0x1C
    ctx->r7 = ADD32(0, 0X1C);
    // 0x80196DD8: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x80196DDC: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80196DE0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80196DE4: jal         0x8009D994
    // 0x80196DE8: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_13;
    // 0x80196DE8: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_13:
    // 0x80196DEC: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x80196DF0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80196DF4: lwc1        $f10, 0x14($s4)
    ctx->f10.u32l = MEM_W(ctx->r20, 0X14);
    // 0x80196DF8: lwc1        $f6, 0x14($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X14);
    // 0x80196DFC: lui         $a1, 0x801
    ctx->r5 = S32(0X801 << 16);
    // 0x80196E00: add.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x80196E04: addiu       $a1, $a1, -0x39C0
    ctx->r5 = ADD32(ctx->r5, -0X39C0);
    // 0x80196E08: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80196E0C: addiu       $a2, $zero, 0x90
    ctx->r6 = ADD32(0, 0X90);
    // 0x80196E10: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x80196E14: addiu       $a3, $zero, 0xD
    ctx->r7 = ADD32(0, 0XD);
    // 0x80196E18: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x80196E1C: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80196E20: jal         0x8009D994
    // 0x80196E24: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_14;
    // 0x80196E24: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_14:
L_80196E28:
    // 0x80196E28: jal         0x8019B7D4
    // 0x80196E2C: nop

    Option_AcceptCancel_Draw(rdram, ctx);
        goto after_15;
    // 0x80196E2C: nop

    after_15:
    // 0x80196E30: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80196E34: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x80196E38: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80196E3C: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x80196E40: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x80196E44: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x80196E48: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x80196E4C: jr          $ra
    // 0x80196E50: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x80196E50: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void Title_CsTeamRunning_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018A990: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8018A994: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8018A998: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8018A99C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8018A9A0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8018A9A4: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x8018A9A8: lw          $a1, 0x7DB0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7DB0);
    // 0x8018A9AC: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8018A9B0: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x8018A9B4: andi        $t6, $a1, 0x7
    ctx->r14 = ctx->r5 & 0X7;
    // 0x8018A9B8: bne         $t6, $at, L_8018AA4C
    if (ctx->r14 != ctx->r1) {
        // 0x8018A9BC: addiu       $a2, $a2, -0x7CC8
        ctx->r6 = ADD32(ctx->r6, -0X7CC8);
            goto L_8018AA4C;
    }
    // 0x8018A9BC: addiu       $a2, $a2, -0x7CC8
    ctx->r6 = ADD32(ctx->r6, -0X7CC8);
    // 0x8018A9C0: lw          $a0, 0x0($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X0);
    // 0x8018A9C4: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8018A9C8: addiu       $v1, $v1, -0x7CCC
    ctx->r3 = ADD32(ctx->r3, -0X7CCC);
    // 0x8018A9CC: beql        $a0, $zero, L_8018AA28
    if (ctx->r4 == 0) {
        // 0x8018A9D0: lui         $at, 0x431B
        ctx->r1 = S32(0X431B << 16);
            goto L_8018AA28;
    }
    goto skip_0;
    // 0x8018A9D0: lui         $at, 0x431B
    ctx->r1 = S32(0X431B << 16);
    skip_0:
    // 0x8018A9D4: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8018A9D8: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x8018A9DC: addiu       $t2, $t2, -0x20AC
    ctx->r10 = ADD32(ctx->r10, -0X20AC);
    // 0x8018A9E0: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8018A9E4: andi        $t9, $t8, 0x3
    ctx->r25 = ctx->r24 & 0X3;
    // 0x8018A9E8: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x8018A9EC: subu        $t1, $t1, $t9
    ctx->r9 = SUB32(ctx->r9, ctx->r25);
    // 0x8018A9F0: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8018A9F4: addu        $v0, $t1, $t2
    ctx->r2 = ADD32(ctx->r9, ctx->r10);
    // 0x8018A9F8: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8018A9FC: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8018AA00: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018AA04: swc1        $f4, -0x7CD8($at)
    MEM_W(-0X7CD8, ctx->r1) = ctx->f4.u32l;
    // 0x8018AA08: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8018AA0C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018AA10: swc1        $f6, -0x7CD4($at)
    MEM_W(-0X7CD4, ctx->r1) = ctx->f6.u32l;
    // 0x8018AA14: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8018AA18: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018AA1C: b           L_8018AA44
    // 0x8018AA20: swc1        $f8, -0x7CD0($at)
    MEM_W(-0X7CD0, ctx->r1) = ctx->f8.u32l;
        goto L_8018AA44;
    // 0x8018AA20: swc1        $f8, -0x7CD0($at)
    MEM_W(-0X7CD0, ctx->r1) = ctx->f8.u32l;
    // 0x8018AA24: lui         $at, 0x431B
    ctx->r1 = S32(0X431B << 16);
L_8018AA28:
    // 0x8018AA28: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8018AA2C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018AA30: swc1        $f0, -0x7CD8($at)
    MEM_W(-0X7CD8, ctx->r1) = ctx->f0.u32l;
    // 0x8018AA34: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018AA38: swc1        $f0, -0x7CD4($at)
    MEM_W(-0X7CD4, ctx->r1) = ctx->f0.u32l;
    // 0x8018AA3C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018AA40: swc1        $f0, -0x7CD0($at)
    MEM_W(-0X7CD0, ctx->r1) = ctx->f0.u32l;
L_8018AA44:
    // 0x8018AA44: xori        $t3, $a0, 0x1
    ctx->r11 = ctx->r4 ^ 0X1;
    // 0x8018AA48: sw          $t3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r11;
L_8018AA4C:
    // 0x8018AA4C: andi        $t4, $a1, 0x1
    ctx->r12 = ctx->r5 & 0X1;
    // 0x8018AA50: beq         $t4, $zero, L_8018AA9C
    if (ctx->r12 == 0) {
        // 0x8018AA54: lui         $v0, 0x801C
        ctx->r2 = S32(0X801C << 16);
            goto L_8018AA9C;
    }
    // 0x8018AA54: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8018AA58: addiu       $v0, $v0, -0x7934
    ctx->r2 = ADD32(ctx->r2, -0X7934);
    // 0x8018AA5C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8018AA60: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8018AA64: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8018AA68: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8018AA6C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018AA70: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8018AA74: lui         $at, 0xC2B4
    ctx->r1 = S32(0XC2B4 << 16);
    // 0x8018AA78: swc1        $f18, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f18.u32l;
    // 0x8018AA7C: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8018AA80: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8018AA84: nop

    // 0x8018AA88: bc1f        L_8018AA9C
    if (!c1cs) {
        // 0x8018AA8C: nop
    
            goto L_8018AA9C;
    }
    // 0x8018AA8C: nop

    // 0x8018AA90: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018AA94: nop

    // 0x8018AA98: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
L_8018AA9C:
    // 0x8018AA9C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018AAA0: lwc1        $f10, -0x7CD8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X7CD8);
    // 0x8018AAA4: lui         $s2, 0x8018
    ctx->r18 = S32(0X8018 << 16);
    // 0x8018AAA8: addiu       $s2, $s2, -0x7AAC
    ctx->r18 = ADD32(ctx->r18, -0X7AAC);
    // 0x8018AAAC: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8018AAB0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018AAB4: mfc1        $t6, $f16
    ctx->r14 = (int32_t)ctx->f16.u32l;
    // 0x8018AAB8: nop

    // 0x8018AABC: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
    // 0x8018AAC0: lwc1        $f18, -0x7CD4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X7CD4);
    // 0x8018AAC4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018AAC8: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8018AACC: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x8018AAD0: nop

    // 0x8018AAD4: sw          $t8, -0x7AA8($at)
    MEM_W(-0X7AA8, ctx->r1) = ctx->r24;
    // 0x8018AAD8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018AADC: lwc1        $f6, -0x7CD0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7CD0);
    // 0x8018AAE0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018AAE4: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8018AAE8: mfc1        $t0, $f8
    ctx->r8 = (int32_t)ctx->f8.u32l;
    // 0x8018AAEC: jal         0x8018F438
    // 0x8018AAF0: sw          $t0, -0x7AA4($at)
    MEM_W(-0X7AA4, ctx->r1) = ctx->r8;
    Title_Passage_Draw(rdram, ctx);
        goto after_0;
    // 0x8018AAF0: sw          $t0, -0x7AA4($at)
    MEM_W(-0X7AA4, ctx->r1) = ctx->r8;
    after_0:
    // 0x8018AAF4: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x8018AAF8: lw          $t1, -0x7D08($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X7D08);
    // 0x8018AAFC: lui         $t2, 0x801C
    ctx->r10 = S32(0X801C << 16);
    // 0x8018AB00: lw          $t2, -0x7D04($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X7D04);
    // 0x8018AB04: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018AB08: lui         $t3, 0x801C
    ctx->r11 = S32(0X801C << 16);
    // 0x8018AB0C: sw          $t1, -0x7AB8($at)
    MEM_W(-0X7AB8, ctx->r1) = ctx->r9;
    // 0x8018AB10: lw          $t3, -0x7D00($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X7D00);
    // 0x8018AB14: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018AB18: sw          $t2, -0x7AB4($at)
    MEM_W(-0X7AB4, ctx->r1) = ctx->r10;
    // 0x8018AB1C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018AB20: sw          $t3, -0x7AB0($at)
    MEM_W(-0X7AB0, ctx->r1) = ctx->r11;
    // 0x8018AB24: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018AB28: lwc1        $f10, -0x7CFC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X7CFC);
    // 0x8018AB2C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018AB30: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x8018AB34: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8018AB38: addiu       $s0, $s0, -0x7CB0
    ctx->r16 = ADD32(ctx->r16, -0X7CB0);
    // 0x8018AB3C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8018AB40: mfc1        $t5, $f16
    ctx->r13 = (int32_t)ctx->f16.u32l;
    // 0x8018AB44: nop

    // 0x8018AB48: sw          $t5, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r13;
    // 0x8018AB4C: lwc1        $f18, -0x7CF8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X7CF8);
    // 0x8018AB50: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018AB54: addiu       $s2, $zero, 0x4
    ctx->r18 = ADD32(0, 0X4);
    // 0x8018AB58: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8018AB5C: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x8018AB60: nop

    // 0x8018AB64: sw          $t7, -0x7AA8($at)
    MEM_W(-0X7AA8, ctx->r1) = ctx->r15;
    // 0x8018AB68: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018AB6C: lwc1        $f6, -0x7CF4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7CF4);
    // 0x8018AB70: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018AB74: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8018AB78: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x8018AB7C: nop

    // 0x8018AB80: sw          $t9, -0x7AA4($at)
    MEM_W(-0X7AA4, ctx->r1) = ctx->r25;
L_8018AB84:
    // 0x8018AB84: jal         0x8018E67C
    // 0x8018AB88: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Title_TeamRunning_Draw(rdram, ctx);
        goto after_1;
    // 0x8018AB88: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x8018AB8C: lw          $t0, 0x58($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X58);
    // 0x8018AB90: lw          $t1, 0x5C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X5C);
    // 0x8018AB94: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8018AB98: addiu       $s0, $s0, 0x60
    ctx->r16 = ADD32(ctx->r16, 0X60);
    // 0x8018AB9C: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x8018ABA0: bne         $s1, $s2, L_8018AB84
    if (ctx->r17 != ctx->r18) {
        // 0x8018ABA4: sw          $t2, -0x8($s0)
        MEM_W(-0X8, ctx->r16) = ctx->r10;
            goto L_8018AB84;
    }
    // 0x8018ABA4: sw          $t2, -0x8($s0)
    MEM_W(-0X8, ctx->r16) = ctx->r10;
    // 0x8018ABA8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8018ABAC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8018ABB0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8018ABB4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8018ABB8: jr          $ra
    // 0x8018ABBC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8018ABBC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void Option_Ranking_Select(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80196FC4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80196FC8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80196FCC: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x80196FD0: lw          $t6, 0x7AF8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7AF8);
    // 0x80196FD4: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80196FD8: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80196FDC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80196FE0: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80196FE4: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x80196FE8: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80196FEC: lhu         $t8, -0x2768($t8)
    ctx->r24 = MEM_HU(ctx->r24, -0X2768);
    // 0x80196FF0: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x80196FF4: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80196FF8: andi        $t9, $t8, 0x8000
    ctx->r25 = ctx->r24 & 0X8000;
    // 0x80196FFC: beq         $t9, $zero, L_80197038
    if (ctx->r25 == 0) {
        // 0x80197000: ori         $a0, $a0, 0x3
        ctx->r4 = ctx->r4 | 0X3;
            goto L_80197038;
    }
    // 0x80197000: ori         $a0, $a0, 0x3
    ctx->r4 = ctx->r4 | 0X3;
    // 0x80197004: lui         $t0, 0x800C
    ctx->r8 = S32(0X800C << 16);
    // 0x80197008: addiu       $t0, $t0, 0x5D3C
    ctx->r8 = ADD32(ctx->r8, 0X5D3C);
    // 0x8019700C: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x80197010: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x80197014: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80197018: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8019701C: jal         0x80019218
    // 0x80197020: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    Audio_PlaySfx(rdram, ctx);
        goto after_0;
    // 0x80197020: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_0:
    // 0x80197024: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80197028: addiu       $v0, $v0, -0x6C20
    ctx->r2 = ADD32(ctx->r2, -0X6C20);
    // 0x8019702C: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x80197030: xori        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 ^ 0X1;
    // 0x80197034: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
L_80197038:
    // 0x80197038: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8019703C: addiu       $v0, $v0, -0x6C20
    ctx->r2 = ADD32(ctx->r2, -0X6C20);
    // 0x80197040: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x80197044: beq         $t3, $zero, L_8019705C
    if (ctx->r11 == 0) {
        // 0x80197048: nop
    
            goto L_8019705C;
    }
    // 0x80197048: nop

    // 0x8019704C: jal         0x8019715C
    // 0x80197050: nop

    Option_Ranking2_Cursor(rdram, ctx);
        goto after_1;
    // 0x80197050: nop

    after_1:
    // 0x80197054: b           L_80197068
    // 0x80197058: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80197068;
    // 0x80197058: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8019705C:
    // 0x8019705C: jal         0x80197074
    // 0x80197060: nop

    Option_Ranking_Cursor(rdram, ctx);
        goto after_2;
    // 0x80197060: nop

    after_2:
    // 0x80197064: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80197068:
    // 0x80197068: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8019706C: jr          $ra
    // 0x80197070: nop

    return;
    // 0x80197070: nop

;}
RECOMP_FUNC void Map_PlanetMedal_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A809C: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x801A80A0: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x801A80A4: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x801A80A8: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x801A80AC: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x801A80B0: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x801A80B4: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x801A80B8: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x801A80BC: sw          $a0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r4;
    // 0x801A80C0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x801A80C4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801A80C8: lw          $v0, -0x2674($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2674);
    // 0x801A80CC: lw          $a0, 0x98($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X98);
    // 0x801A80D0: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x801A80D4: beq         $v1, $v0, L_801A80F8
    if (ctx->r3 == ctx->r2) {
        // 0x801A80D8: sll         $t8, $a0, 2
        ctx->r24 = S32(ctx->r4 << 2);
            goto L_801A80F8;
    }
    // 0x801A80D8: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x801A80DC: lw          $t6, 0x98($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X98);
    // 0x801A80E0: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x801A80E4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801A80E8: addu        $s0, $s0, $t7
    ctx->r16 = ADD32(ctx->r16, ctx->r15);
    // 0x801A80EC: lw          $s0, -0x2700($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X2700);
    // 0x801A80F0: b           L_801A8110
    // 0x801A80F4: sw          $t7, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r15;
        goto L_801A8110;
    // 0x801A80F4: sw          $t7, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r15;
L_801A80F8:
    // 0x801A80F8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A80FC: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x801A8100: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x801A8104: lw          $s0, -0x267C($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X267C);
    // 0x801A8108: sw          $t9, -0x2700($at)
    MEM_W(-0X2700, ctx->r1) = ctx->r25;
    // 0x801A810C: sw          $t8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r24;
L_801A8110:
    // 0x801A8110: beql        $s0, $zero, L_801A8718
    if (ctx->r16 == 0) {
        // 0x801A8114: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_801A8718;
    }
    goto skip_0;
    // 0x801A8114: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_0:
    // 0x801A8118: bne         $v1, $v0, L_801A860C
    if (ctx->r3 != ctx->r2) {
        // 0x801A811C: lui         $s2, 0x8013
        ctx->r18 = S32(0X8013 << 16);
            goto L_801A860C;
    }
    // 0x801A811C: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x801A8120: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801A8124: lw          $v0, -0x2670($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2670);
    // 0x801A8128: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x801A812C: addiu       $s2, $s2, 0x7E64
    ctx->r18 = ADD32(ctx->r18, 0X7E64);
    // 0x801A8130: beq         $v0, $zero, L_801A8148
    if (ctx->r2 == 0) {
        // 0x801A8134: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_801A8148;
    }
    // 0x801A8134: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x801A8138: beq         $v0, $v1, L_801A827C
    if (ctx->r2 == ctx->r3) {
        // 0x801A813C: nop
    
            goto L_801A827C;
    }
    // 0x801A813C: nop

    // 0x801A8140: b           L_801A8718
    // 0x801A8144: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_801A8718;
    // 0x801A8144: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_801A8148:
    // 0x801A8148: jal         0x800B8DD0
    // 0x801A814C: addiu       $a1, $zero, 0x43
    ctx->r5 = ADD32(0, 0X43);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x801A814C: addiu       $a1, $zero, 0x43
    ctx->r5 = ADD32(0, 0X43);
    after_0:
    // 0x801A8150: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x801A8154: addiu       $s1, $s1, -0x4C40
    ctx->r17 = ADD32(ctx->r17, -0X4C40);
    // 0x801A8158: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x801A815C: andi        $t2, $s0, 0xFF
    ctx->r10 = ctx->r16 & 0XFF;
    // 0x801A8160: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x801A8164: addiu       $t0, $v1, 0x8
    ctx->r8 = ADD32(ctx->r3, 0X8);
    // 0x801A8168: sw          $t0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r8;
    // 0x801A816C: or          $t3, $t2, $at
    ctx->r11 = ctx->r10 | ctx->r1;
    // 0x801A8170: lui         $t1, 0xFA00
    ctx->r9 = S32(0XFA00 << 16);
    // 0x801A8174: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x801A8178: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x801A817C: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x801A8180: lui         $t5, 0xFB00
    ctx->r13 = S32(0XFB00 << 16);
    // 0x801A8184: lui         $t6, 0x5050
    ctx->r14 = S32(0X5050 << 16);
    // 0x801A8188: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x801A818C: sw          $t4, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r12;
    // 0x801A8190: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x801A8194: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x801A8198: jal         0x80005708
    // 0x801A819C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Push(rdram, ctx);
        goto after_1;
    // 0x801A819C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x801A81A0: lw          $t7, 0x98($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X98);
    // 0x801A81A4: lui         $t9, 0x801D
    ctx->r25 = S32(0X801D << 16);
    // 0x801A81A8: addiu       $t9, $t9, -0x1E20
    ctx->r25 = ADD32(ctx->r25, -0X1E20);
    // 0x801A81AC: sll         $t8, $t7, 6
    ctx->r24 = S32(ctx->r15 << 6);
    // 0x801A81B0: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    // 0x801A81B4: jal         0x80005680
    // 0x801A81B8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    Matrix_Copy(rdram, ctx);
        goto after_2;
    // 0x801A81B8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_2:
    // 0x801A81BC: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x801A81C0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801A81C4: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x801A81C8: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    // 0x801A81CC: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x801A81D0: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801A81D4: jal         0x80005B00
    // 0x801A81D8: lui         $a2, 0xC1F0
    ctx->r6 = S32(0XC1F0 << 16);
    Matrix_Translate(rdram, ctx);
        goto after_3;
    // 0x801A81D8: lui         $a2, 0xC1F0
    ctx->r6 = S32(0XC1F0 << 16);
    after_3:
    // 0x801A81DC: jal         0x80006EB8
    // 0x801A81E0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_4;
    // 0x801A81E0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_4:
    // 0x801A81E4: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x801A81E8: lui         $t3, 0x605
    ctx->r11 = S32(0X605 << 16);
    // 0x801A81EC: addiu       $t3, $t3, -0x2980
    ctx->r11 = ADD32(ctx->r11, -0X2980);
    // 0x801A81F0: addiu       $t1, $v1, 0x8
    ctx->r9 = ADD32(ctx->r3, 0X8);
    // 0x801A81F4: sw          $t1, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r9;
    // 0x801A81F8: lui         $t2, 0x600
    ctx->r10 = S32(0X600 << 16);
    // 0x801A81FC: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x801A8200: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x801A8204: jal         0x80005740
    // 0x801A8208: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_5;
    // 0x801A8208: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x801A820C: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x801A8210: lui         $t5, 0x801D
    ctx->r13 = S32(0X801D << 16);
    // 0x801A8214: addiu       $t5, $t5, -0x1548
    ctx->r13 = ADD32(ctx->r13, -0X1548);
    // 0x801A8218: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x801A821C: addu        $v0, $t4, $t5
    ctx->r2 = ADD32(ctx->r12, ctx->r13);
    // 0x801A8220: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801A8224: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801A8228: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x801A822C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801A8230: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801A8234: addiu       $v1, $v1, -0x2638
    ctx->r3 = ADD32(ctx->r3, -0X2638);
    // 0x801A8238: addiu       $t6, $zero, 0xF
    ctx->r14 = ADD32(0, 0XF);
    // 0x801A823C: bne         $s0, $a0, L_801A8714
    if (ctx->r16 != ctx->r4) {
        // 0x801A8240: swc1        $f8, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
            goto L_801A8714;
    }
    // 0x801A8240: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x801A8244: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x801A8248: addiu       $s0, $s0, -0x2668
    ctx->r16 = ADD32(ctx->r16, -0X2668);
    // 0x801A824C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x801A8250: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x801A8254: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A8258: sw          $a0, -0x266C($at)
    MEM_W(-0X266C, ctx->r1) = ctx->r4;
    // 0x801A825C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801A8260: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A8264: addiu       $v0, $v0, -0x2670
    ctx->r2 = ADD32(ctx->r2, -0X2670);
    // 0x801A8268: swc1        $f22, -0x2664($at)
    MEM_W(-0X2664, ctx->r1) = ctx->f22.u32l;
    // 0x801A826C: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x801A8270: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x801A8274: b           L_801A8714
    // 0x801A8278: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
        goto L_801A8714;
    // 0x801A8278: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
L_801A827C:
    // 0x801A827C: jal         0x80004EB0
    // 0x801A8280: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_6;
    // 0x801A8280: nop

    after_6:
    // 0x801A8284: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x801A8288: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801A828C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x801A8290: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801A8294: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x801A8298: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A829C: lwc1        $f4, 0x79A8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X79A8);
    // 0x801A82A0: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x801A82A4: lui         $a2, 0x3DB8
    ctx->r6 = S32(0X3DB8 << 16);
    // 0x801A82A8: ori         $a2, $a2, 0x51EC
    ctx->r6 = ctx->r6 | 0X51EC;
    // 0x801A82AC: addiu       $a0, $a0, -0x2664
    ctx->r4 = ADD32(ctx->r4, -0X2664);
    // 0x801A82B0: lui         $a1, 0x4316
    ctx->r5 = S32(0X4316 << 16);
    // 0x801A82B4: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x801A82B8: add.s       $f20, $f16, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f20.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x801A82BC: jal         0x8009BC2C
    // 0x801A82C0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_7;
    // 0x801A82C0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_7:
    // 0x801A82C4: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x801A82C8: addiu       $s2, $s2, 0x7E64
    ctx->r18 = ADD32(ctx->r18, 0X7E64);
    // 0x801A82CC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x801A82D0: jal         0x800B8DD0
    // 0x801A82D4: addiu       $a1, $zero, 0x43
    ctx->r5 = ADD32(0, 0X43);
    RCP_SetupDL(rdram, ctx);
        goto after_8;
    // 0x801A82D4: addiu       $a1, $zero, 0x43
    ctx->r5 = ADD32(0, 0X43);
    after_8:
    // 0x801A82D8: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x801A82DC: lui         $t0, 0xFA00
    ctx->r8 = S32(0XFA00 << 16);
    // 0x801A82E0: lui         $t1, 0x801D
    ctx->r9 = S32(0X801D << 16);
    // 0x801A82E4: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x801A82E8: sw          $t9, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r25;
    // 0x801A82EC: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x801A82F0: lw          $t1, -0x266C($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X266C);
    // 0x801A82F4: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x801A82F8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801A82FC: andi        $t2, $t1, 0xFF
    ctx->r10 = ctx->r9 & 0XFF;
    // 0x801A8300: or          $t3, $t2, $at
    ctx->r11 = ctx->r10 | ctx->r1;
    // 0x801A8304: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x801A8308: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x801A830C: lui         $t5, 0xFB00
    ctx->r13 = S32(0XFB00 << 16);
    // 0x801A8310: lui         $t6, 0x5050
    ctx->r14 = S32(0X5050 << 16);
    // 0x801A8314: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x801A8318: sw          $t4, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r12;
    // 0x801A831C: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x801A8320: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x801A8324: lw          $t8, 0x98($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X98);
    // 0x801A8328: lui         $t0, 0x801D
    ctx->r8 = S32(0X801D << 16);
    // 0x801A832C: addiu       $t0, $t0, -0x1A60
    ctx->r8 = ADD32(ctx->r8, -0X1A60);
    // 0x801A8330: lui         $t7, 0x605
    ctx->r15 = S32(0X605 << 16);
    // 0x801A8334: sll         $t9, $t8, 6
    ctx->r25 = S32(ctx->r24 << 6);
    // 0x801A8338: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x801A833C: addiu       $t7, $t7, -0x2980
    ctx->r15 = ADD32(ctx->r15, -0X2980);
    // 0x801A8340: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A8344: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x801A8348: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x801A834C: addiu       $s1, $s1, -0x4C40
    ctx->r17 = ADD32(ctx->r17, -0X4C40);
    // 0x801A8350: lwc1        $f24, 0x79AC($at)
    ctx->f24.u32l = MEM_W(ctx->r1, 0X79AC);
    // 0x801A8354: sw          $t7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r15;
    // 0x801A8358: sw          $t1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r9;
L_801A835C:
    // 0x801A835C: jal         0x80005708
    // 0x801A8360: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Push(rdram, ctx);
        goto after_9;
    // 0x801A8360: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_9:
    // 0x801A8364: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801A8368: jal         0x80005680
    // 0x801A836C: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    Matrix_Copy(rdram, ctx);
        goto after_10;
    // 0x801A836C: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    after_10:
    // 0x801A8370: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    // 0x801A8374: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x801A8378: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801A837C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x801A8380: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801A8384: jal         0x80005B00
    // 0x801A8388: lui         $a2, 0xC1F0
    ctx->r6 = S32(0XC1F0 << 16);
    Matrix_Translate(rdram, ctx);
        goto after_11;
    // 0x801A8388: lui         $a2, 0xC1F0
    ctx->r6 = S32(0XC1F0 << 16);
    after_11:
    // 0x801A838C: mtc1        $s0, $f6
    ctx->f6.u32l = ctx->r16;
    // 0x801A8390: lui         $at, 0xC234
    ctx->r1 = S32(0XC234 << 16);
    // 0x801A8394: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801A8398: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801A839C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801A83A0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801A83A4: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x801A83A8: nop

    // 0x801A83AC: mul.s       $f18, $f16, $f24
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f24.fl);
    // 0x801A83B0: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x801A83B4: jal         0x80005FE0
    // 0x801A83B8: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_12;
    // 0x801A83B8: nop

    after_12:
    // 0x801A83BC: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    // 0x801A83C0: lui         $a2, 0x801D
    ctx->r6 = S32(0X801D << 16);
    // 0x801A83C4: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x801A83C8: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x801A83CC: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x801A83D0: lw          $a2, -0x2664($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X2664);
    // 0x801A83D4: jal         0x80005B00
    // 0x801A83D8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_13;
    // 0x801A83D8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_13:
    // 0x801A83DC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A83E0: lwc1        $f4, 0x6A78($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6A78);
    // 0x801A83E4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801A83E8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801A83EC: mul.s       $f6, $f24, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f24.fl, ctx->f4.fl);
    // 0x801A83F0: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x801A83F4: jal         0x80005FE0
    // 0x801A83F8: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_14;
    // 0x801A83F8: nop

    after_14:
    // 0x801A83FC: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x801A8400: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x801A8404: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x801A8408: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801A840C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x801A8410: jal         0x80005C34
    // 0x801A8414: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_15;
    // 0x801A8414: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_15:
    // 0x801A8418: jal         0x80006EB8
    // 0x801A841C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_16;
    // 0x801A841C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_16:
    // 0x801A8420: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x801A8424: lui         $t6, 0x600
    ctx->r14 = S32(0X600 << 16);
    // 0x801A8428: addiu       $t5, $v1, 0x8
    ctx->r13 = ADD32(ctx->r3, 0X8);
    // 0x801A842C: sw          $t5, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r13;
    // 0x801A8430: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x801A8434: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x801A8438: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x801A843C: jal         0x80005740
    // 0x801A8440: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_17;
    // 0x801A8440: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_17:
    // 0x801A8444: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801A8448: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x801A844C: bne         $s0, $at, L_801A835C
    if (ctx->r16 != ctx->r1) {
        // 0x801A8450: nop
    
            goto L_801A835C;
    }
    // 0x801A8450: nop

    // 0x801A8454: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A8458: lwc1        $f8, 0x6A78($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6A78);
    // 0x801A845C: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x801A8460: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801A8464: lui         $t8, 0x801D
    ctx->r24 = S32(0X801D << 16);
    // 0x801A8468: lw          $t8, -0x266C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X266C);
    // 0x801A846C: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801A8470: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A8474: addiu       $t9, $t8, -0x10
    ctx->r25 = ADD32(ctx->r24, -0X10);
    // 0x801A8478: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x801A847C: swc1        $f16, 0x6A78($at)
    MEM_W(0X6A78, ctx->r1) = ctx->f16.u32l;
    // 0x801A8480: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A8484: bgtz        $t9, L_801A8494
    if (SIGNED(ctx->r25) > 0) {
        // 0x801A8488: sw          $t9, -0x266C($at)
        MEM_W(-0X266C, ctx->r1) = ctx->r25;
            goto L_801A8494;
    }
    // 0x801A8488: sw          $t9, -0x266C($at)
    MEM_W(-0X266C, ctx->r1) = ctx->r25;
    // 0x801A848C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A8490: sw          $zero, -0x266C($at)
    MEM_W(-0X266C, ctx->r1) = 0;
L_801A8494:
    // 0x801A8494: jal         0x800B8DD0
    // 0x801A8498: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    RCP_SetupDL(rdram, ctx);
        goto after_18;
    // 0x801A8498: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_18:
    // 0x801A849C: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x801A84A0: addiu       $s0, $s0, -0x2668
    ctx->r16 = ADD32(ctx->r16, -0X2668);
    // 0x801A84A4: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x801A84A8: lui         $t1, 0xBA00
    ctx->r9 = S32(0XBA00 << 16);
    // 0x801A84AC: ori         $t1, $t1, 0xC02
    ctx->r9 = ctx->r9 | 0XC02;
    // 0x801A84B0: addiu       $t0, $v1, 0x8
    ctx->r8 = ADD32(ctx->r3, 0X8);
    // 0x801A84B4: sw          $t0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r8;
    // 0x801A84B8: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x801A84BC: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x801A84C0: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x801A84C4: lui         $t3, 0xFA00
    ctx->r11 = S32(0XFA00 << 16);
    // 0x801A84C8: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x801A84CC: addiu       $t2, $v1, 0x8
    ctx->r10 = ADD32(ctx->r3, 0X8);
    // 0x801A84D0: sw          $t2, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r10;
    // 0x801A84D4: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x801A84D8: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x801A84DC: andi        $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 & 0XFF;
    // 0x801A84E0: or          $t6, $t5, $at
    ctx->r14 = ctx->r13 | ctx->r1;
    // 0x801A84E4: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x801A84E8: jal         0x80005708
    // 0x801A84EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Push(rdram, ctx);
        goto after_19;
    // 0x801A84EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_19:
    // 0x801A84F0: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801A84F4: jal         0x80005680
    // 0x801A84F8: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    Matrix_Copy(rdram, ctx);
        goto after_20;
    // 0x801A84F8: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    after_20:
    // 0x801A84FC: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    // 0x801A8500: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x801A8504: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801A8508: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801A850C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801A8510: jal         0x80005B00
    // 0x801A8514: lui         $a2, 0xC1F0
    ctx->r6 = S32(0XC1F0 << 16);
    Matrix_Translate(rdram, ctx);
        goto after_21;
    // 0x801A8514: lui         $a2, 0xC1F0
    ctx->r6 = S32(0XC1F0 << 16);
    after_21:
    // 0x801A8518: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801A851C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801A8520: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801A8524: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x801A8528: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801A852C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801A8530: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x801A8534: jal         0x80005C34
    // 0x801A8538: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_22;
    // 0x801A8538: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_22:
    // 0x801A853C: jal         0x80006EB8
    // 0x801A8540: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_23;
    // 0x801A8540: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_23:
    // 0x801A8544: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x801A8548: lui         $t1, 0x602
    ctx->r9 = S32(0X602 << 16);
    // 0x801A854C: addiu       $t1, $t1, -0x2E10
    ctx->r9 = ADD32(ctx->r9, -0X2E10);
    // 0x801A8550: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x801A8554: sw          $t9, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r25;
    // 0x801A8558: lui         $t0, 0x600
    ctx->r8 = S32(0X600 << 16);
    // 0x801A855C: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x801A8560: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x801A8564: jal         0x80005740
    // 0x801A8568: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_24;
    // 0x801A8568: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_24:
    // 0x801A856C: lui         $at, 0xC2B4
    ctx->r1 = S32(0XC2B4 << 16);
    // 0x801A8570: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801A8574: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x801A8578: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A857C: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x801A8580: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x801A8584: swc1        $f18, -0x1508($at)
    MEM_W(-0X1508, ctx->r1) = ctx->f18.u32l;
    // 0x801A8588: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x801A858C: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x801A8590: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x801A8594: addiu       $v0, $t3, 0x8
    ctx->r2 = ADD32(ctx->r11, 0X8);
    // 0x801A8598: bne         $v0, $at, L_801A85CC
    if (ctx->r2 != ctx->r1) {
        // 0x801A859C: sw          $v0, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r2;
            goto L_801A85CC;
    }
    // 0x801A859C: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x801A85A0: lui         $t5, 0x800C
    ctx->r13 = S32(0X800C << 16);
    // 0x801A85A4: addiu       $t5, $t5, 0x5D3C
    ctx->r13 = ADD32(ctx->r13, 0X5D3C);
    // 0x801A85A8: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x801A85AC: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x801A85B0: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x801A85B4: ori         $a0, $a0, 0x8030
    ctx->r4 = ctx->r4 | 0X8030;
    // 0x801A85B8: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x801A85BC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x801A85C0: jal         0x80019218
    // 0x801A85C4: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    Audio_PlaySfx(rdram, ctx);
        goto after_25;
    // 0x801A85C4: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_25:
    // 0x801A85C8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_801A85CC:
    // 0x801A85CC: slti        $at, $v0, 0xFF
    ctx->r1 = SIGNED(ctx->r2) < 0XFF ? 1 : 0;
    // 0x801A85D0: bne         $at, $zero, L_801A85E0
    if (ctx->r1 != 0) {
        // 0x801A85D4: lui         $v1, 0x801D
        ctx->r3 = S32(0X801D << 16);
            goto L_801A85E0;
    }
    // 0x801A85D4: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801A85D8: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x801A85DC: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
L_801A85E0:
    // 0x801A85E0: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x801A85E4: bne         $v0, $at, L_801A8714
    if (ctx->r2 != ctx->r1) {
        // 0x801A85E8: addiu       $v1, $v1, -0x2638
        ctx->r3 = ADD32(ctx->r3, -0X2638);
            goto L_801A8714;
    }
    // 0x801A85E8: addiu       $v1, $v1, -0x2638
    ctx->r3 = ADD32(ctx->r3, -0X2638);
    // 0x801A85EC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801A85F0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A85F4: bne         $v0, $zero, L_801A8604
    if (ctx->r2 != 0) {
        // 0x801A85F8: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_801A8604;
    }
    // 0x801A85F8: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x801A85FC: b           L_801A8714
    // 0x801A8600: sw          $zero, -0x2674($at)
    MEM_W(-0X2674, ctx->r1) = 0;
        goto L_801A8714;
    // 0x801A8600: sw          $zero, -0x2674($at)
    MEM_W(-0X2674, ctx->r1) = 0;
L_801A8604:
    // 0x801A8604: b           L_801A8714
    // 0x801A8608: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
        goto L_801A8714;
    // 0x801A8608: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
L_801A860C:
    // 0x801A860C: addiu       $s2, $s2, 0x7E64
    ctx->r18 = ADD32(ctx->r18, 0X7E64);
    // 0x801A8610: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x801A8614: jal         0x800B8DD0
    // 0x801A8618: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    RCP_SetupDL(rdram, ctx);
        goto after_26;
    // 0x801A8618: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_26:
    // 0x801A861C: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x801A8620: addiu       $s1, $s1, -0x4C40
    ctx->r17 = ADD32(ctx->r17, -0X4C40);
    // 0x801A8624: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x801A8628: lui         $t9, 0xBA00
    ctx->r25 = S32(0XBA00 << 16);
    // 0x801A862C: ori         $t9, $t9, 0xC02
    ctx->r25 = ctx->r25 | 0XC02;
    // 0x801A8630: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x801A8634: sw          $t8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r24;
    // 0x801A8638: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x801A863C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x801A8640: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x801A8644: andi        $t2, $s0, 0xFF
    ctx->r10 = ctx->r16 & 0XFF;
    // 0x801A8648: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x801A864C: addiu       $t0, $v1, 0x8
    ctx->r8 = ADD32(ctx->r3, 0X8);
    // 0x801A8650: sw          $t0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r8;
    // 0x801A8654: or          $t3, $t2, $at
    ctx->r11 = ctx->r10 | ctx->r1;
    // 0x801A8658: lui         $t1, 0xFA00
    ctx->r9 = S32(0XFA00 << 16);
    // 0x801A865C: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x801A8660: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x801A8664: jal         0x80005708
    // 0x801A8668: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Push(rdram, ctx);
        goto after_27;
    // 0x801A8668: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_27:
    // 0x801A866C: lw          $t4, 0x98($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X98);
    // 0x801A8670: lui         $t6, 0x801D
    ctx->r14 = S32(0X801D << 16);
    // 0x801A8674: addiu       $t6, $t6, -0x1A60
    ctx->r14 = ADD32(ctx->r14, -0X1A60);
    // 0x801A8678: sll         $t5, $t4, 6
    ctx->r13 = S32(ctx->r12 << 6);
    // 0x801A867C: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    // 0x801A8680: jal         0x80005680
    // 0x801A8684: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    Matrix_Copy(rdram, ctx);
        goto after_28;
    // 0x801A8684: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_28:
    // 0x801A8688: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x801A868C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801A8690: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801A8694: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    // 0x801A8698: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x801A869C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801A86A0: jal         0x80005B00
    // 0x801A86A4: lui         $a2, 0xC1F0
    ctx->r6 = S32(0XC1F0 << 16);
    Matrix_Translate(rdram, ctx);
        goto after_29;
    // 0x801A86A4: lui         $a2, 0xC1F0
    ctx->r6 = S32(0XC1F0 << 16);
    after_29:
    // 0x801A86A8: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801A86AC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801A86B0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801A86B4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x801A86B8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801A86BC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801A86C0: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x801A86C4: jal         0x80005C34
    // 0x801A86C8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_30;
    // 0x801A86C8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_30:
    // 0x801A86CC: jal         0x80006EB8
    // 0x801A86D0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_31;
    // 0x801A86D0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_31:
    // 0x801A86D4: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x801A86D8: lui         $t1, 0x602
    ctx->r9 = S32(0X602 << 16);
    // 0x801A86DC: addiu       $t1, $t1, -0x2E10
    ctx->r9 = ADD32(ctx->r9, -0X2E10);
    // 0x801A86E0: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x801A86E4: sw          $t9, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r25;
    // 0x801A86E8: lui         $t0, 0x600
    ctx->r8 = S32(0X600 << 16);
    // 0x801A86EC: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x801A86F0: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x801A86F4: jal         0x80005740
    // 0x801A86F8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_32;
    // 0x801A86F8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_32:
    // 0x801A86FC: lui         $at, 0xC2B4
    ctx->r1 = S32(0XC2B4 << 16);
    // 0x801A8700: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801A8704: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x801A8708: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A870C: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x801A8710: swc1        $f4, -0x1508($at)
    MEM_W(-0X1508, ctx->r1) = ctx->f4.u32l;
L_801A8714:
    // 0x801A8714: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_801A8718:
    // 0x801A8718: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x801A871C: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x801A8720: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x801A8724: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x801A8728: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x801A872C: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x801A8730: jr          $ra
    // 0x801A8734: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x801A8734: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void Title_Setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801875E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801875E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801875E8: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x801875EC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801875F0: sb          $t6, 0x7E78($at)
    MEM_B(0X7E78, ctx->r1) = ctx->r14;
    // 0x801875F4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801875F8: sw          $zero, 0x7DB0($at)
    MEM_W(0X7DB0, ctx->r1) = 0;
    // 0x801875FC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80187600: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80187604: sw          $t7, 0x7AE0($at)
    MEM_W(0X7AE0, ctx->r1) = ctx->r15;
    // 0x80187608: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018760C: sh          $zero, 0x1A34($at)
    MEM_H(0X1A34, ctx->r1) = 0;
    // 0x80187610: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80187614: jal         0x80187ABC
    // 0x80187618: sw          $zero, 0x2870($at)
    MEM_W(0X2870, ctx->r1) = 0;
    Title_CheckControllers(rdram, ctx);
        goto after_0;
    // 0x80187618: sw          $zero, 0x2870($at)
    MEM_W(0X2870, ctx->r1) = 0;
    after_0:
    // 0x8018761C: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80187620: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80187624: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80187628: sw          $v0, 0x7AF8($at)
    MEM_W(0X7AF8, ctx->r1) = ctx->r2;
    // 0x8018762C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80187630: sw          $zero, -0x7CB8($at)
    MEM_W(-0X7CB8, ctx->r1) = 0;
    // 0x80187634: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80187638: sw          $zero, -0x7CB0($at)
    MEM_W(-0X7CB0, ctx->r1) = 0;
    // 0x8018763C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80187640: sw          $zero, -0x7CAC($at)
    MEM_W(-0X7CAC, ctx->r1) = 0;
    // 0x80187644: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80187648: sw          $zero, -0x7CC0($at)
    MEM_W(-0X7CC0, ctx->r1) = 0;
    // 0x8018764C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80187650: sw          $zero, -0x7CE0($at)
    MEM_W(-0X7CE0, ctx->r1) = 0;
    // 0x80187654: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80187658: sw          $zero, -0x7CD8($at)
    MEM_W(-0X7CD8, ctx->r1) = 0;
    // 0x8018765C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80187660: sw          $zero, -0x7CD0($at)
    MEM_W(-0X7CD0, ctx->r1) = 0;
    // 0x80187664: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80187668: sh          $zero, 0x1A36($at)
    MEM_H(0X1A36, ctx->r1) = 0;
    // 0x8018766C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80187670: sw          $zero, -0x7D7C($at)
    MEM_W(-0X7D7C, ctx->r1) = 0;
    // 0x80187674: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80187678: sw          $zero, -0x7D58($at)
    MEM_W(-0X7D58, ctx->r1) = 0;
    // 0x8018767C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80187680: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80187684: sw          $zero, -0x7D54($at)
    MEM_W(-0X7D54, ctx->r1) = 0;
    // 0x80187688: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018768C: swc1        $f4, -0x7CC4($at)
    MEM_W(-0X7CC4, ctx->r1) = ctx->f4.u32l;
    // 0x80187690: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80187694: sw          $zero, -0x7D40($at)
    MEM_W(-0X7D40, ctx->r1) = 0;
    // 0x80187698: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018769C: sw          $zero, -0x7D80($at)
    MEM_W(-0X7D80, ctx->r1) = 0;
    // 0x801876A0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801876A4: swc1        $f0, 0x7BCC($at)
    MEM_W(0X7BCC, ctx->r1) = ctx->f0.u32l;
    // 0x801876A8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801876AC: jal         0x80006F20
    // 0x801876B0: swc1        $f0, 0x7BC8($at)
    MEM_W(0X7BC8, ctx->r1) = ctx->f0.u32l;
    Memory_FreeAll(rdram, ctx);
        goto after_1;
    // 0x801876B0: swc1        $f0, 0x7BC8($at)
    MEM_W(0X7BC8, ctx->r1) = ctx->f0.u32l;
    after_1:
    // 0x801876B4: jal         0x800A5D6C
    // 0x801876B8: nop

    Play_GenerateStarfield(rdram, ctx);
        goto after_2;
    // 0x801876B8: nop

    after_2:
    // 0x801876BC: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x801876C0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801876C4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801876C8: swc1        $f6, -0x7BE0($at)
    MEM_W(-0X7BE0, ctx->r1) = ctx->f6.u32l;
    // 0x801876CC: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x801876D0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801876D4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801876D8: jal         0x80188010
    // 0x801876DC: swc1        $f8, -0x7BDC($at)
    MEM_W(-0X7BDC, ctx->r1) = ctx->f8.u32l;
    Title_GetRankTotalHits(rdram, ctx);
        goto after_3;
    // 0x801876DC: swc1        $f8, -0x7BDC($at)
    MEM_W(-0X7BDC, ctx->r1) = ctx->f8.u32l;
    after_3:
    // 0x801876E0: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x801876E4: lw          $t8, 0x7AF8($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7AF8);
    // 0x801876E8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801876EC: lui         $t9, 0x801C
    ctx->r25 = S32(0X801C << 16);
    // 0x801876F0: beq         $t8, $at, L_80187708
    if (ctx->r24 == ctx->r1) {
        // 0x801876F4: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80187708;
    }
    // 0x801876F4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801876F8: lw          $t9, -0x7D84($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7D84);
    // 0x801876FC: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    // 0x80187700: beq         $t9, $zero, L_80187724
    if (ctx->r25 == 0) {
        // 0x80187704: nop
    
            goto L_80187724;
    }
    // 0x80187704: nop

L_80187708:
    // 0x80187708: jal         0x8001DC6C
    // 0x8018770C: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    Audio_SetAudioSpec(rdram, ctx);
        goto after_4;
    // 0x8018770C: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    after_4:
    // 0x80187710: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80187714: sw          $zero, -0x7D3C($at)
    MEM_W(-0X7D3C, ctx->r1) = 0;
    // 0x80187718: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018771C: b           L_80187738
    // 0x80187720: sw          $zero, -0x7D84($at)
    MEM_W(-0X7D84, ctx->r1) = 0;
        goto L_80187738;
    // 0x80187720: sw          $zero, -0x7D84($at)
    MEM_W(-0X7D84, ctx->r1) = 0;
L_80187724:
    // 0x80187724: jal         0x8001DC6C
    // 0x80187728: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    Audio_SetAudioSpec(rdram, ctx);
        goto after_5;
    // 0x80187728: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_5:
    // 0x8018772C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80187730: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80187734: sw          $t0, -0x7D3C($at)
    MEM_W(-0X7D3C, ctx->r1) = ctx->r8;
L_80187738:
    // 0x80187738: addiu       $t1, $zero, 0x1E
    ctx->r9 = ADD32(0, 0X1E);
    // 0x8018773C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80187740: sw          $t1, -0x274C($at)
    MEM_W(-0X274C, ctx->r1) = ctx->r9;
    // 0x80187744: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80187748: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018774C: jr          $ra
    // 0x80187750: nop

    return;
    // 0x80187750: nop

;}
RECOMP_FUNC void Map_PlanetOrderZpos(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A68E4: lui         $t3, 0x801D
    ctx->r11 = S32(0X801D << 16);
    // 0x801A68E8: lui         $t1, 0x801D
    ctx->r9 = S32(0X801D << 16);
    // 0x801A68EC: addiu       $t1, $t1, -0x16A0
    ctx->r9 = ADD32(ctx->r9, -0X16A0);
    // 0x801A68F0: addiu       $t3, $t3, -0x2724
    ctx->r11 = ADD32(ctx->r11, -0X2724);
    // 0x801A68F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801A68F8: addiu       $t4, $zero, 0xE
    ctx->r12 = ADD32(0, 0XE);
    // 0x801A68FC: addiu       $t2, $zero, 0xC
    ctx->r10 = ADD32(0, 0XC);
    // 0x801A6900: addiu       $t0, $zero, 0xF
    ctx->r8 = ADD32(0, 0XF);
    // 0x801A6904: slti        $at, $v0, 0xF
    ctx->r1 = SIGNED(ctx->r2) < 0XF ? 1 : 0;
L_801A6908:
    // 0x801A6908: beq         $at, $zero, L_801A6A10
    if (ctx->r1 == 0) {
        // 0x801A690C: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_801A6A10;
    }
    // 0x801A690C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x801A6910: lui         $t7, 0x801D
    ctx->r15 = S32(0X801D << 16);
    // 0x801A6914: subu        $a0, $t0, $v0
    ctx->r4 = SUB32(ctx->r8, ctx->r2);
    // 0x801A6918: andi        $t8, $a0, 0x1
    ctx->r24 = ctx->r4 & 0X1;
    // 0x801A691C: addiu       $t7, $t7, -0x2760
    ctx->r15 = ADD32(ctx->r15, -0X2760);
    // 0x801A6920: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x801A6924: beq         $t8, $zero, L_801A6970
    if (ctx->r24 == 0) {
        // 0x801A6928: addu        $a1, $t6, $t7
        ctx->r5 = ADD32(ctx->r14, ctx->r15);
            goto L_801A6970;
    }
    // 0x801A6928: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    // 0x801A692C: lw          $a2, 0x0($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X0);
    // 0x801A6930: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x801A6934: multu       $a2, $t2
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801A6938: mflo        $t9
    ctx->r25 = lo;
    // 0x801A693C: addu        $t5, $t1, $t9
    ctx->r13 = ADD32(ctx->r9, ctx->r25);
    // 0x801A6940: lwc1        $f4, 0x8($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X8);
    // 0x801A6944: multu       $a2, $t2
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801A6948: mflo        $t6
    ctx->r14 = lo;
    // 0x801A694C: addu        $t7, $t1, $t6
    ctx->r15 = ADD32(ctx->r9, ctx->r14);
    // 0x801A6950: lwc1        $f6, 0x8($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X8);
    // 0x801A6954: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x801A6958: nop

    // 0x801A695C: bc1f        L_801A696C
    if (!c1cs) {
        // 0x801A6960: nop
    
            goto L_801A696C;
    }
    // 0x801A6960: nop

    // 0x801A6964: sw          $a2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r6;
    // 0x801A6968: sw          $a2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r6;
L_801A696C:
    // 0x801A696C: beq         $v1, $t0, L_801A6A10
    if (ctx->r3 == ctx->r8) {
        // 0x801A6970: lui         $t9, 0x801D
        ctx->r25 = S32(0X801D << 16);
            goto L_801A6A10;
    }
L_801A6970:
    // 0x801A6970: lui         $t9, 0x801D
    ctx->r25 = S32(0X801D << 16);
    // 0x801A6974: addiu       $t9, $t9, -0x2760
    ctx->r25 = ADD32(ctx->r25, -0X2760);
    // 0x801A6978: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x801A697C: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    // 0x801A6980: lw          $a2, 0x0($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X0);
L_801A6984:
    // 0x801A6984: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x801A6988: multu       $a2, $t2
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801A698C: mflo        $t5
    ctx->r13 = lo;
    // 0x801A6990: addu        $t6, $t1, $t5
    ctx->r14 = ADD32(ctx->r9, ctx->r13);
    // 0x801A6994: lwc1        $f0, 0x8($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X8);
    // 0x801A6998: multu       $v1, $t2
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801A699C: mflo        $t7
    ctx->r15 = lo;
    // 0x801A69A0: addu        $t8, $t1, $t7
    ctx->r24 = ADD32(ctx->r9, ctx->r15);
    // 0x801A69A4: lwc1        $f8, 0x8($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X8);
    // 0x801A69A8: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x801A69AC: nop

    // 0x801A69B0: bc1fl       L_801A69DC
    if (!c1cs) {
        // 0x801A69B4: lw          $v1, 0x4($a0)
        ctx->r3 = MEM_W(ctx->r4, 0X4);
            goto L_801A69DC;
    }
    goto skip_0;
    // 0x801A69B4: lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4);
    skip_0:
    // 0x801A69B8: sw          $v1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r3;
    // 0x801A69BC: sw          $a2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r6;
    // 0x801A69C0: lw          $a2, 0x0($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X0);
    // 0x801A69C4: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x801A69C8: subu        $t9, $t9, $a2
    ctx->r25 = SUB32(ctx->r25, ctx->r6);
    // 0x801A69CC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x801A69D0: addu        $t5, $t1, $t9
    ctx->r13 = ADD32(ctx->r9, ctx->r25);
    // 0x801A69D4: lwc1        $f0, 0x8($t5)
    ctx->f0.u32l = MEM_W(ctx->r13, 0X8);
    // 0x801A69D8: lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4);
L_801A69DC:
    // 0x801A69DC: multu       $v1, $t2
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801A69E0: mflo        $t6
    ctx->r14 = lo;
    // 0x801A69E4: addu        $t7, $t1, $t6
    ctx->r15 = ADD32(ctx->r9, ctx->r14);
    // 0x801A69E8: lwc1        $f10, 0x8($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X8);
    // 0x801A69EC: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x801A69F0: nop

    // 0x801A69F4: bc1fl       L_801A6A08
    if (!c1cs) {
        // 0x801A69F8: addiu       $a0, $a0, 0x8
        ctx->r4 = ADD32(ctx->r4, 0X8);
            goto L_801A6A08;
    }
    goto skip_1;
    // 0x801A69F8: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    skip_1:
    // 0x801A69FC: sw          $v1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r3;
    // 0x801A6A00: sw          $a2, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r6;
    // 0x801A6A04: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
L_801A6A08:
    // 0x801A6A08: bnel        $a0, $t3, L_801A6984
    if (ctx->r4 != ctx->r11) {
        // 0x801A6A0C: lw          $a2, 0x0($a1)
        ctx->r6 = MEM_W(ctx->r5, 0X0);
            goto L_801A6984;
    }
    goto skip_2;
    // 0x801A6A0C: lw          $a2, 0x0($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X0);
    skip_2:
L_801A6A10:
    // 0x801A6A10: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x801A6A14: bnel        $v0, $t4, L_801A6908
    if (ctx->r2 != ctx->r12) {
        // 0x801A6A18: slti        $at, $v0, 0xF
        ctx->r1 = SIGNED(ctx->r2) < 0XF ? 1 : 0;
            goto L_801A6908;
    }
    goto skip_3;
    // 0x801A6A18: slti        $at, $v0, 0xF
    ctx->r1 = SIGNED(ctx->r2) < 0XF ? 1 : 0;
    skip_3:
    // 0x801A6A1C: jr          $ra
    // 0x801A6A20: nop

    return;
    // 0x801A6A20: nop

;}
RECOMP_FUNC void Map_PathChange_UpdateEntry(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A4D0C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801A4D10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801A4D14: sltiu       $at, $a0, 0x5
    ctx->r1 = ctx->r4 < 0X5 ? 1 : 0;
    // 0x801A4D18: beq         $at, $zero, L_801A4D6C
    if (ctx->r1 == 0) {
        // 0x801A4D1C: sll         $t6, $a0, 2
        ctx->r14 = S32(ctx->r4 << 2);
            goto L_801A4D6C;
    }
    // 0x801A4D1C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x801A4D20: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A4D24: addu        $at, $at, $t6
    gpr jr_addend_801A4D2C = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x801A4D28: lw          $t6, 0x77F0($at)
    ctx->r14 = ADD32(ctx->r1, 0X77F0);
    // 0x801A4D2C: jr          $t6
    // 0x801A4D30: nop

    switch (jr_addend_801A4D2C >> 2) {
        case 0: goto L_801A4D6C; break;
        case 1: goto L_801A4D34; break;
        case 2: goto L_801A4D6C; break;
        case 3: goto L_801A4D64; break;
        case 4: goto L_801A4D34; break;
        default: switch_error(__func__, 0x801A4D2C, 0x801B77F0);
    }
    // 0x801A4D30: nop

L_801A4D34:
    // 0x801A4D34: lui         $t7, 0x801D
    ctx->r15 = S32(0X801D << 16);
    // 0x801A4D38: lw          $t7, -0x262C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X262C);
    // 0x801A4D3C: beq         $t7, $zero, L_801A4D54
    if (ctx->r15 == 0) {
        // 0x801A4D40: nop
    
            goto L_801A4D54;
    }
    // 0x801A4D40: nop

    // 0x801A4D44: jal         0x801A4F8C
    // 0x801A4D48: nop

    Map_GoToGameOver(rdram, ctx);
        goto after_0;
    // 0x801A4D48: nop

    after_0:
    // 0x801A4D4C: b           L_801A4D70
    // 0x801A4D50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801A4D70;
    // 0x801A4D50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801A4D54:
    // 0x801A4D54: jal         0x801A4FC4
    // 0x801A4D58: nop

    Map_RetryCourse(rdram, ctx);
        goto after_1;
    // 0x801A4D58: nop

    after_1:
    // 0x801A4D5C: b           L_801A4D70
    // 0x801A4D60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801A4D70;
    // 0x801A4D60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801A4D64:
    // 0x801A4D64: jal         0x801A53C8
    // 0x801A4D68: nop

    Map_ChangePath(rdram, ctx);
        goto after_2;
    // 0x801A4D68: nop

    after_2:
L_801A4D6C:
    // 0x801A4D6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801A4D70:
    // 0x801A4D70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801A4D74: jr          $ra
    // 0x801A4D78: nop

    return;
    // 0x801A4D78: nop

;}
RECOMP_FUNC void Title_CsTakeOff_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018B5C4: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x8018B5C8: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x8018B5CC: addiu       $t0, $t0, -0x7D40
    ctx->r8 = ADD32(ctx->r8, -0X7D40);
    // 0x8018B5D0: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x8018B5D4: sw          $s1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r17;
    // 0x8018B5D8: sw          $s0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r16;
    // 0x8018B5DC: sdc1        $f24, 0x48($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X48, ctx->r29);
    // 0x8018B5E0: sdc1        $f22, 0x40($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X40, ctx->r29);
    // 0x8018B5E4: sdc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X38, ctx->r29);
    // 0x8018B5E8: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x8018B5EC: sltiu       $at, $t6, 0xB
    ctx->r1 = ctx->r14 < 0XB ? 1 : 0;
    // 0x8018B5F0: beq         $at, $zero, L_8018C0A0
    if (ctx->r1 == 0) {
        // 0x8018B5F4: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_8018C0A0;
    }
    // 0x8018B5F4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8018B5F8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018B5FC: addu        $at, $at, $t6
    gpr jr_addend_8018B604 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8018B600: lw          $t6, 0x6F54($at)
    ctx->r14 = ADD32(ctx->r1, 0X6F54);
    // 0x8018B604: jr          $t6
    // 0x8018B608: nop

    switch (jr_addend_8018B604 >> 2) {
        case 0: goto L_8018B60C; break;
        case 1: goto L_8018B6F0; break;
        case 2: goto L_8018BB3C; break;
        case 3: goto L_8018BE00; break;
        case 4: goto L_8018BEEC; break;
        case 5: goto L_8018C0A0; break;
        case 6: goto L_8018C0A0; break;
        case 7: goto L_8018C0A0; break;
        case 8: goto L_8018C0A0; break;
        case 9: goto L_8018C0A0; break;
        case 10: goto L_8018B69C; break;
        default: switch_error(__func__, 0x8018B604, 0x801B6F54);
    }
    // 0x8018B608: nop

L_8018B60C:
    // 0x8018B60C: lui         $s1, 0x801B
    ctx->r17 = S32(0X801B << 16);
    // 0x8018B610: addiu       $s1, $s1, 0x7BEC
    ctx->r17 = ADD32(ctx->r17, 0X7BEC);
    // 0x8018B614: jal         0x8018B058
    // 0x8018B618: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
    Title_CsTakeOff_Setup(rdram, ctx);
        goto after_0;
    // 0x8018B618: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
    after_0:
    // 0x8018B61C: jal         0x8001D400
    // 0x8018B620: addiu       $a0, $zero, 0x68
    ctx->r4 = ADD32(0, 0X68);
    Audio_SetEnvSfxReverb(rdram, ctx);
        goto after_1;
    // 0x8018B620: addiu       $a0, $zero, 0x68
    ctx->r4 = ADD32(0, 0X68);
    after_1:
    // 0x8018B624: addiu       $t7, $zero, 0x1E
    ctx->r15 = ADD32(0, 0X1E);
    // 0x8018B628: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018B62C: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x8018B630: sw          $t7, -0x7D58($at)
    MEM_W(-0X7D58, ctx->r1) = ctx->r15;
    // 0x8018B634: addiu       $s0, $s0, -0x7B18
    ctx->r16 = ADD32(ctx->r16, -0X7B18);
    // 0x8018B638: addiu       $t8, $zero, 0x46
    ctx->r24 = ADD32(0, 0X46);
    // 0x8018B63C: addiu       $t9, $zero, 0x66
    ctx->r25 = ADD32(0, 0X66);
    // 0x8018B640: addiu       $t1, $zero, 0x84
    ctx->r9 = ADD32(0, 0X84);
    // 0x8018B644: addiu       $t2, $zero, 0xAB
    ctx->r10 = ADD32(0, 0XAB);
    // 0x8018B648: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x8018B64C: sw          $t8, 0x14C($s0)
    MEM_W(0X14C, ctx->r16) = ctx->r24;
    // 0x8018B650: sw          $t9, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->r25;
    // 0x8018B654: sw          $t1, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->r9;
    // 0x8018B658: sw          $t2, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r10;
    // 0x8018B65C: addiu       $t3, $t3, 0x6C60
    ctx->r11 = ADD32(ctx->r11, 0X6C60);
    // 0x8018B660: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018B664: sw          $t3, -0x7D6C($at)
    MEM_W(-0X7D6C, ctx->r1) = ctx->r11;
    // 0x8018B668: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8018B66C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018B670: sw          $zero, -0x7D68($at)
    MEM_W(-0X7D68, ctx->r1) = 0;
    // 0x8018B674: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018B678: swc1        $f20, -0x7D74($at)
    MEM_W(-0X7D74, ctx->r1) = ctx->f20.u32l;
    // 0x8018B67C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018B680: lwc1        $f4, 0x6F80($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6F80);
    // 0x8018B684: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018B688: addiu       $t4, $zero, 0xA
    ctx->r12 = ADD32(0, 0XA);
    // 0x8018B68C: swc1        $f4, -0x7D70($at)
    MEM_W(-0X7D70, ctx->r1) = ctx->f4.u32l;
    // 0x8018B690: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018B694: b           L_8018C0A0
    // 0x8018B698: sw          $t4, -0x7D40($at)
    MEM_W(-0X7D40, ctx->r1) = ctx->r12;
        goto L_8018C0A0;
    // 0x8018B698: sw          $t4, -0x7D40($at)
    MEM_W(-0X7D40, ctx->r1) = ctx->r12;
L_8018B69C:
    // 0x8018B69C: lui         $t5, 0x801C
    ctx->r13 = S32(0X801C << 16);
    // 0x8018B6A0: lw          $t5, -0x7D58($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X7D58);
    // 0x8018B6A4: bne         $t5, $zero, L_8018C0A0
    if (ctx->r13 != 0) {
        // 0x8018B6A8: lui         $a3, 0x800C
        ctx->r7 = S32(0X800C << 16);
            goto L_8018C0A0;
    }
    // 0x8018B6A8: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8018B6AC: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x8018B6B0: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8018B6B4: addiu       $t6, $t6, 0x5D3C
    ctx->r14 = ADD32(ctx->r14, 0X5D3C);
    // 0x8018B6B8: lui         $a0, 0x100
    ctx->r4 = S32(0X100 << 16);
    // 0x8018B6BC: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x8018B6C0: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x8018B6C4: ori         $a0, $a0, 0x1D
    ctx->r4 = ctx->r4 | 0X1D;
    // 0x8018B6C8: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8018B6CC: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8018B6D0: jal         0x80019218
    // 0x8018B6D4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_2;
    // 0x8018B6D4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_2:
    // 0x8018B6D8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018B6DC: sw          $zero, -0x7D4C($at)
    MEM_W(-0X7D4C, ctx->r1) = 0;
    // 0x8018B6E0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018B6E4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8018B6E8: b           L_8018C0A0
    // 0x8018B6EC: sw          $t7, -0x7D40($at)
    MEM_W(-0X7D40, ctx->r1) = ctx->r15;
        goto L_8018C0A0;
    // 0x8018B6EC: sw          $t7, -0x7D40($at)
    MEM_W(-0X7D40, ctx->r1) = ctx->r15;
L_8018B6F0:
    // 0x8018B6F0: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8018B6F4: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x8018B6F8: addiu       $a1, $a1, -0x7954
    ctx->r5 = ADD32(ctx->r5, -0X7954);
    // 0x8018B6FC: jal         0x80191798
    // 0x8018B700: addiu       $a0, $a0, -0x7958
    ctx->r4 = ADD32(ctx->r4, -0X7958);
    Title_GetCamRot(rdram, ctx);
        goto after_3;
    // 0x8018B700: addiu       $a0, $a0, -0x7958
    ctx->r4 = ADD32(ctx->r4, -0X7958);
    after_3:
    // 0x8018B704: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018B708: lwc1        $f12, -0x7958($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X7958);
    // 0x8018B70C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018B710: jal         0x80191844
    // 0x8018B714: lwc1        $f14, -0x7954($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X7954);
    Title_SetCamUp(rdram, ctx);
        goto after_4;
    // 0x8018B714: lwc1        $f14, -0x7954($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X7954);
    after_4:
    // 0x8018B718: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8018B71C: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x8018B720: lw          $a2, -0x7D70($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7D70);
    // 0x8018B724: lw          $a0, -0x7D6C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7D6C);
    // 0x8018B728: jal         0x8018CC30
    // 0x8018B72C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    Title_Cutscene_SetCamera(rdram, ctx);
        goto after_5;
    // 0x8018B72C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_5:
    // 0x8018B730: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8018B734: addiu       $v0, $v0, -0x6FB8
    ctx->r2 = ADD32(ctx->r2, -0X6FB8);
    // 0x8018B738: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8018B73C: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8018B740: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018B744: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x8018B748: nop

    // 0x8018B74C: bc1f        L_8018B7A4
    if (!c1cs) {
        // 0x8018B750: nop
    
            goto L_8018B7A4;
    }
    // 0x8018B750: nop

    // 0x8018B754: lwc1        $f6, 0x6F84($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6F84);
    // 0x8018B758: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8018B75C: lui         $a0, 0x900
    ctx->r4 = S32(0X900 << 16);
    // 0x8018B760: sub.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x8018B764: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x8018B768: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x8018B76C: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8018B770: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x8018B774: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8018B778: addiu       $t8, $t8, 0x5D3C
    ctx->r24 = ADD32(ctx->r24, 0X5D3C);
    // 0x8018B77C: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x8018B780: c.lt.s      $f10, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f10.fl < ctx->f20.fl;
    // 0x8018B784: ori         $a0, $a0, 0x2013
    ctx->r4 = ctx->r4 | 0X2013;
    // 0x8018B788: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8018B78C: bc1f        L_8018B7A4
    if (!c1cs) {
        // 0x8018B790: nop
    
            goto L_8018B7A4;
    }
    // 0x8018B790: nop

    // 0x8018B794: swc1        $f20, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f20.u32l;
    // 0x8018B798: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8018B79C: jal         0x80019218
    // 0x8018B7A0: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    Audio_PlaySfx(rdram, ctx);
        goto after_6;
    // 0x8018B7A0: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    after_6:
L_8018B7A4:
    // 0x8018B7A4: lui         $t9, 0x801C
    ctx->r25 = S32(0X801C << 16);
    // 0x8018B7A8: lw          $t9, -0x7D4C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7D4C);
    // 0x8018B7AC: addiu       $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
    // 0x8018B7B0: addiu       $s1, $zero, 0x3
    ctx->r17 = ADD32(0, 0X3);
    // 0x8018B7B4: bne         $t9, $at, L_8018B7C8
    if (ctx->r25 != ctx->r1) {
        // 0x8018B7B8: lui         $s0, 0x801C
        ctx->r16 = S32(0X801C << 16);
            goto L_8018B7C8;
    }
    // 0x8018B7B8: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x8018B7BC: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8018B7C0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018B7C4: sw          $t1, 0x7BF0($at)
    MEM_W(0X7BF0, ctx->r1) = ctx->r9;
L_8018B7C8:
    // 0x8018B7C8: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8018B7CC: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x8018B7D0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018B7D4: lwc1        $f22, 0x6F88($at)
    ctx->f22.u32l = MEM_W(ctx->r1, 0X6F88);
    // 0x8018B7D8: addiu       $s0, $s0, -0x7A04
    ctx->r16 = ADD32(ctx->r16, -0X7A04);
L_8018B7DC:
    // 0x8018B7DC: lw          $v0, 0x38($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X38);
    // 0x8018B7E0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8018B7E4: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8018B7E8: blez        $v0, L_8018B7F8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8018B7EC: addiu       $t2, $v0, -0x1
        ctx->r10 = ADD32(ctx->r2, -0X1);
            goto L_8018B7F8;
    }
    // 0x8018B7EC: addiu       $t2, $v0, -0x1
    ctx->r10 = ADD32(ctx->r2, -0X1);
    // 0x8018B7F0: sw          $t2, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r10;
    // 0x8018B7F4: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
L_8018B7F8:
    // 0x8018B7F8: bne         $v0, $at, L_8018B828
    if (ctx->r2 != ctx->r1) {
        // 0x8018B7FC: addiu       $a3, $a3, 0x5D34
        ctx->r7 = ADD32(ctx->r7, 0X5D34);
            goto L_8018B828;
    }
    // 0x8018B7FC: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8018B800: lui         $t3, 0x800C
    ctx->r11 = S32(0X800C << 16);
    // 0x8018B804: addiu       $t3, $t3, 0x5D3C
    ctx->r11 = ADD32(ctx->r11, 0X5D3C);
    // 0x8018B808: lui         $a0, 0x1950
    ctx->r4 = S32(0X1950 << 16);
    // 0x8018B80C: ori         $a0, $a0, 0x107A
    ctx->r4 = ctx->r4 | 0X107A;
    // 0x8018B810: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x8018B814: addiu       $a1, $s0, 0x50
    ctx->r5 = ADD32(ctx->r16, 0X50);
    // 0x8018B818: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8018B81C: jal         0x80019218
    // 0x8018B820: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    Audio_PlaySfx(rdram, ctx);
        goto after_7;
    // 0x8018B820: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_7:
    // 0x8018B824: lw          $v0, 0x38($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X38);
L_8018B828:
    // 0x8018B828: bne         $v0, $zero, L_8018B8A8
    if (ctx->r2 != 0) {
        // 0x8018B82C: addiu       $a0, $s0, 0x28
        ctx->r4 = ADD32(ctx->r16, 0X28);
            goto L_8018B8A8;
    }
    // 0x8018B82C: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    // 0x8018B830: sll         $t5, $s1, 2
    ctx->r13 = S32(ctx->r17 << 2);
    // 0x8018B834: addiu       $t6, $sp, 0x6C
    ctx->r14 = ADD32(ctx->r29, 0X6C);
    // 0x8018B838: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x8018B83C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8018B840: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x8018B844: addiu       $t4, $s0, 0x24
    ctx->r12 = ADD32(ctx->r16, 0X24);
    // 0x8018B848: sw          $t4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r12;
    // 0x8018B84C: sw          $t7, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r15;
    // 0x8018B850: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    // 0x8018B854: jal         0x8009BC2C
    // 0x8018B858: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_8;
    // 0x8018B858: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    after_8:
    // 0x8018B85C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8018B860: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x8018B864: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x8018B868: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    // 0x8018B86C: jal         0x8009BC2C
    // 0x8018B870: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_9;
    // 0x8018B870: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    after_9:
    // 0x8018B874: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x8018B878: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018B87C: c.eq.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl == ctx->f20.fl;
    // 0x8018B880: swc1        $f0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f0.u32l;
    // 0x8018B884: lwc1        $f16, 0x10($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8018B888: lwc1        $f18, 0x6F8C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6F8C);
    // 0x8018B88C: addiu       $a0, $s0, 0x50
    ctx->r4 = ADD32(ctx->r16, 0X50);
    // 0x8018B890: lui         $a1, 0x1950
    ctx->r5 = S32(0X1950 << 16);
    // 0x8018B894: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8018B898: bc1f        L_8018B8A8
    if (!c1cs) {
        // 0x8018B89C: swc1        $f4, 0x10($s0)
        MEM_W(0X10, ctx->r16) = ctx->f4.u32l;
            goto L_8018B8A8;
    }
    // 0x8018B89C: swc1        $f4, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f4.u32l;
    // 0x8018B8A0: jal         0x8001A55C
    // 0x8018B8A4: ori         $a1, $a1, 0x107A
    ctx->r5 = ctx->r5 | 0X107A;
    Audio_KillSfxBySourceAndId(rdram, ctx);
        goto after_10;
    // 0x8018B8A4: ori         $a1, $a1, 0x107A
    ctx->r5 = ctx->r5 | 0X107A;
    after_10:
L_8018B8A8:
    // 0x8018B8A8: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x8018B8AC: bgez        $s1, L_8018B7DC
    if (SIGNED(ctx->r17) >= 0) {
        // 0x8018B8B0: addiu       $s0, $s0, -0x5C
        ctx->r16 = ADD32(ctx->r16, -0X5C);
            goto L_8018B7DC;
    }
    // 0x8018B8B0: addiu       $s0, $s0, -0x5C
    ctx->r16 = ADD32(ctx->r16, -0X5C);
    // 0x8018B8B4: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8018B8B8: lw          $v0, -0x7D4C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D4C);
    // 0x8018B8BC: addiu       $at, $zero, 0x46
    ctx->r1 = ADD32(0, 0X46);
    // 0x8018B8C0: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x8018B8C4: bne         $v0, $at, L_8018B8D8
    if (ctx->r2 != ctx->r1) {
        // 0x8018B8C8: addiu       $s0, $s0, -0x7B18
        ctx->r16 = ADD32(ctx->r16, -0X7B18);
            goto L_8018B8D8;
    }
    // 0x8018B8C8: addiu       $s0, $s0, -0x7B18
    ctx->r16 = ADD32(ctx->r16, -0X7B18);
    // 0x8018B8CC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018B8D0: sw          $zero, 0x7BE4($at)
    MEM_W(0X7BE4, ctx->r1) = 0;
    // 0x8018B8D4: sw          $zero, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = 0;
L_8018B8D8:
    // 0x8018B8D8: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x8018B8DC: addiu       $at, $zero, 0x50
    ctx->r1 = ADD32(0, 0X50);
    // 0x8018B8E0: bne         $v0, $at, L_8018B90C
    if (ctx->r2 != ctx->r1) {
        // 0x8018B8E4: addiu       $s0, $s0, -0x7B18
        ctx->r16 = ADD32(ctx->r16, -0X7B18);
            goto L_8018B90C;
    }
    // 0x8018B8E4: addiu       $s0, $s0, -0x7B18
    ctx->r16 = ADD32(ctx->r16, -0X7B18);
    // 0x8018B8E8: sw          $zero, 0xA8($s0)
    MEM_W(0XA8, ctx->r16) = 0;
    // 0x8018B8EC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018B8F0: sw          $zero, -0x7AD0($at)
    MEM_W(-0X7AD0, ctx->r1) = 0;
    // 0x8018B8F4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018B8F8: sw          $zero, -0x7A74($at)
    MEM_W(-0X7A74, ctx->r1) = 0;
    // 0x8018B8FC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018B900: sw          $zero, -0x7A18($at)
    MEM_W(-0X7A18, ctx->r1) = 0;
    // 0x8018B904: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018B908: sw          $zero, -0x79BC($at)
    MEM_W(-0X79BC, ctx->r1) = 0;
L_8018B90C:
    // 0x8018B90C: addiu       $at, $zero, 0x73
    ctx->r1 = ADD32(0, 0X73);
    // 0x8018B910: bne         $v0, $at, L_8018B924
    if (ctx->r2 != ctx->r1) {
        // 0x8018B914: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_8018B924;
    }
    // 0x8018B914: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8018B918: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8018B91C: sw          $t9, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->r25;
    // 0x8018B920: sw          $t1, 0xA8($s0)
    MEM_W(0XA8, ctx->r16) = ctx->r9;
L_8018B924:
    // 0x8018B924: addiu       $at, $zero, 0xE2
    ctx->r1 = ADD32(0, 0XE2);
    // 0x8018B928: bne         $v0, $at, L_8018BB2C
    if (ctx->r2 != ctx->r1) {
        // 0x8018B92C: lui         $s1, 0x801C
        ctx->r17 = S32(0X801C << 16);
            goto L_8018BB2C;
    }
    // 0x8018B92C: lui         $s1, 0x801C
    ctx->r17 = S32(0X801C << 16);
    // 0x8018B930: lui         $t2, 0x800C
    ctx->r10 = S32(0X800C << 16);
    // 0x8018B934: lui         $t3, 0x800C
    ctx->r11 = S32(0X800C << 16);
    // 0x8018B938: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018B93C: addiu       $t3, $t3, 0x5D3C
    ctx->r11 = ADD32(ctx->r11, 0X5D3C);
    // 0x8018B940: addiu       $a3, $t2, 0x5D34
    ctx->r7 = ADD32(ctx->r10, 0X5D34);
    // 0x8018B944: lui         $a0, 0x100
    ctx->r4 = S32(0X100 << 16);
    // 0x8018B948: addiu       $a1, $s1, -0x79B4
    ctx->r5 = ADD32(ctx->r17, -0X79B4);
    // 0x8018B94C: sw          $zero, 0x7BF0($at)
    MEM_W(0X7BF0, ctx->r1) = 0;
    // 0x8018B950: ori         $a0, $a0, 0x1E
    ctx->r4 = ctx->r4 | 0X1E;
    // 0x8018B954: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8018B958: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x8018B95C: jal         0x80019218
    // 0x8018B960: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Audio_PlaySfx(rdram, ctx);
        goto after_11;
    // 0x8018B960: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_11:
    // 0x8018B964: lui         $at, 0x42D2
    ctx->r1 = S32(0X42D2 << 16);
    // 0x8018B968: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018B96C: lui         $at, 0xC140
    ctx->r1 = S32(0XC140 << 16);
    // 0x8018B970: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018B974: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8018B978: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8018B97C: lui         $s1, 0x801C
    ctx->r17 = S32(0X801C << 16);
    // 0x8018B980: addiu       $s1, $s1, -0x7944
    ctx->r17 = ADD32(ctx->r17, -0X7944);
    // 0x8018B984: addiu       $v1, $v1, -0x793C
    ctx->r3 = ADD32(ctx->r3, -0X793C);
    // 0x8018B988: addiu       $v0, $v0, -0x7940
    ctx->r2 = ADD32(ctx->r2, -0X7940);
    // 0x8018B98C: swc1        $f20, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f20.u32l;
    // 0x8018B990: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018B994: swc1        $f6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f6.u32l;
    // 0x8018B998: swc1        $f8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f8.u32l;
    // 0x8018B99C: lwc1        $f10, 0x6F90($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6F90);
    // 0x8018B9A0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018B9A4: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8018B9A8: swc1        $f10, -0x7958($at)
    MEM_W(-0X7958, ctx->r1) = ctx->f10.u32l;
    // 0x8018B9AC: lui         $at, 0x42DC
    ctx->r1 = S32(0X42DC << 16);
    // 0x8018B9B0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8018B9B4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018B9B8: addiu       $a0, $a0, -0x7948
    ctx->r4 = ADD32(ctx->r4, -0X7948);
    // 0x8018B9BC: swc1        $f16, -0x7954($at)
    MEM_W(-0X7954, ctx->r1) = ctx->f16.u32l;
    // 0x8018B9C0: lui         $at, 0x4210
    ctx->r1 = S32(0X4210 << 16);
    // 0x8018B9C4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8018B9C8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018B9CC: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x8018B9D0: swc1        $f18, -0x794C($at)
    MEM_W(-0X794C, ctx->r1) = ctx->f18.u32l;
    // 0x8018B9D4: lui         $at, 0xC28C
    ctx->r1 = S32(0XC28C << 16);
    // 0x8018B9D8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018B9DC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018B9E0: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x8018B9E4: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x8018B9E8: lwc1        $f6, -0x794C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X794C);
    // 0x8018B9EC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018B9F0: lwc1        $f10, -0x7958($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X7958);
    // 0x8018B9F4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018B9F8: lwc1        $f16, -0x7954($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X7954);
    // 0x8018B9FC: lwc1        $f8, 0x0($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8018BA00: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x8018BA04: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x8018BA08: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x8018BA0C: addiu       $t8, $t8, 0x79C0
    ctx->r24 = ADD32(ctx->r24, 0X79C0);
    // 0x8018BA10: addiu       $t7, $t7, 0x79B8
    ctx->r15 = ADD32(ctx->r15, 0X79B8);
    // 0x8018BA14: addiu       $t6, $t6, 0x79A0
    ctx->r14 = ADD32(ctx->r14, 0X79A0);
    // 0x8018BA18: addiu       $t5, $t5, 0x7988
    ctx->r13 = ADD32(ctx->r13, 0X7988);
    // 0x8018BA1C: addiu       $t4, $t4, 0x7980
    ctx->r12 = ADD32(ctx->r12, 0X7980);
    // 0x8018BA20: lui         $a3, 0x8017
    ctx->r7 = S32(0X8017 << 16);
    // 0x8018BA24: addiu       $a3, $a3, 0x7978
    ctx->r7 = ADD32(ctx->r7, 0X7978);
    // 0x8018BA28: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8018BA2C: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8018BA30: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x8018BA34: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x8018BA38: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x8018BA3C: lw          $a2, 0x0($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X0);
    // 0x8018BA40: lwc1        $f14, 0x0($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8018BA44: lwc1        $f12, 0x0($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8018BA48: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x8018BA4C: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    // 0x8018BA50: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    // 0x8018BA54: jal         0x801914AC
    // 0x8018BA58: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    Title_SetCamUp2(rdram, ctx);
        goto after_12;
    // 0x8018BA58: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    after_12:
    // 0x8018BA5C: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8018BA60: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8018BA64: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018BA68: sw          $zero, -0x7D4C($at)
    MEM_W(-0X7D4C, ctx->r1) = 0;
    // 0x8018BA6C: swc1        $f20, 0x158($s0)
    MEM_W(0X158, ctx->r16) = ctx->f20.u32l;
    // 0x8018BA70: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018BA74: swc1        $f0, -0x7938($at)
    MEM_W(-0X7938, ctx->r1) = ctx->f0.u32l;
    // 0x8018BA78: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018BA7C: swc1        $f20, -0x7934($at)
    MEM_W(-0X7934, ctx->r1) = ctx->f20.u32l;
    // 0x8018BA80: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x8018BA84: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8018BA88: lui         $s1, 0x801C
    ctx->r17 = S32(0X801C << 16);
    // 0x8018BA8C: addiu       $s1, $s1, -0x7D14
    ctx->r17 = ADD32(ctx->r17, -0X7D14);
    // 0x8018BA90: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018BA94: swc1        $f0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f0.u32l;
    // 0x8018BA98: swc1        $f18, -0x7D10($at)
    MEM_W(-0X7D10, ctx->r1) = ctx->f18.u32l;
    // 0x8018BA9C: lwc1        $f4, 0x0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8018BAA0: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8018BAA4: addiu       $v1, $v1, -0x7D0C
    ctx->r3 = ADD32(ctx->r3, -0X7D0C);
    // 0x8018BAA8: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8018BAAC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018BAB0: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x8018BAB4: addiu       $t6, $zero, 0x23
    ctx->r14 = ADD32(0, 0X23);
    // 0x8018BAB8: mfc1        $t1, $f6
    ctx->r9 = (int32_t)ctx->f6.u32l;
    // 0x8018BABC: addiu       $t7, $zero, 0x18
    ctx->r15 = ADD32(0, 0X18);
    // 0x8018BAC0: lui         $t9, 0x801C
    ctx->r25 = S32(0X801C << 16);
    // 0x8018BAC4: sw          $t1, -0x7AB8($at)
    MEM_W(-0X7AB8, ctx->r1) = ctx->r9;
    // 0x8018BAC8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018BACC: lwc1        $f8, -0x7D10($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X7D10);
    // 0x8018BAD0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018BAD4: lw          $t9, -0x7D40($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7D40);
    // 0x8018BAD8: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8018BADC: addiu       $t8, $zero, 0x2E
    ctx->r24 = ADD32(0, 0X2E);
    // 0x8018BAE0: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8018BAE4: addiu       $t1, $t9, 0x1
    ctx->r9 = ADD32(ctx->r25, 0X1);
    // 0x8018BAE8: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
    // 0x8018BAEC: lw          $v0, -0x7D4C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D4C);
    // 0x8018BAF0: sw          $t3, -0x7AB4($at)
    MEM_W(-0X7AB4, ctx->r1) = ctx->r11;
    // 0x8018BAF4: lwc1        $f16, 0x0($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8018BAF8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018BAFC: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8018BB00: mfc1        $t5, $f18
    ctx->r13 = (int32_t)ctx->f18.u32l;
    // 0x8018BB04: nop

    // 0x8018BB08: sw          $t5, -0x7AB0($at)
    MEM_W(-0X7AB0, ctx->r1) = ctx->r13;
    // 0x8018BB0C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018BB10: sw          $t6, -0x7AAC($at)
    MEM_W(-0X7AAC, ctx->r1) = ctx->r14;
    // 0x8018BB14: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018BB18: sw          $t7, -0x7AA8($at)
    MEM_W(-0X7AA8, ctx->r1) = ctx->r15;
    // 0x8018BB1C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018BB20: sw          $t8, -0x7AA4($at)
    MEM_W(-0X7AA4, ctx->r1) = ctx->r24;
    // 0x8018BB24: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018BB28: sw          $t1, -0x7D40($at)
    MEM_W(-0X7D40, ctx->r1) = ctx->r9;
L_8018BB2C:
    // 0x8018BB2C: addiu       $t2, $v0, 0x1
    ctx->r10 = ADD32(ctx->r2, 0X1);
    // 0x8018BB30: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018BB34: b           L_8018C0A0
    // 0x8018BB38: sw          $t2, -0x7D4C($at)
    MEM_W(-0X7D4C, ctx->r1) = ctx->r10;
        goto L_8018C0A0;
    // 0x8018BB38: sw          $t2, -0x7D4C($at)
    MEM_W(-0X7D4C, ctx->r1) = ctx->r10;
L_8018BB3C:
    // 0x8018BB3C: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8018BB40: lw          $v0, -0x7D4C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D4C);
    // 0x8018BB44: addiu       $at, $zero, 0x1E
    ctx->r1 = ADD32(0, 0X1E);
    // 0x8018BB48: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x8018BB4C: bne         $v0, $at, L_8018BB5C
    if (ctx->r2 != ctx->r1) {
        // 0x8018BB50: addiu       $s0, $s0, -0x7B18
        ctx->r16 = ADD32(ctx->r16, -0X7B18);
            goto L_8018BB5C;
    }
    // 0x8018BB50: addiu       $s0, $s0, -0x7B18
    ctx->r16 = ADD32(ctx->r16, -0X7B18);
    // 0x8018BB54: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8018BB58: sw          $t3, 0x154($s0)
    MEM_W(0X154, ctx->r16) = ctx->r11;
L_8018BB5C:
    // 0x8018BB5C: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x8018BB60: addiu       $at, $zero, 0x28
    ctx->r1 = ADD32(0, 0X28);
    // 0x8018BB64: bne         $v0, $at, L_8018BB74
    if (ctx->r2 != ctx->r1) {
        // 0x8018BB68: addiu       $s0, $s0, -0x7B18
        ctx->r16 = ADD32(ctx->r16, -0X7B18);
            goto L_8018BB74;
    }
    // 0x8018BB68: addiu       $s0, $s0, -0x7B18
    ctx->r16 = ADD32(ctx->r16, -0X7B18);
    // 0x8018BB6C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8018BB70: sw          $t4, 0x150($s0)
    MEM_W(0X150, ctx->r16) = ctx->r12;
L_8018BB74:
    // 0x8018BB74: slti        $at, $v0, 0x29
    ctx->r1 = SIGNED(ctx->r2) < 0X29 ? 1 : 0;
    // 0x8018BB78: bne         $at, $zero, L_8018BC80
    if (ctx->r1 != 0) {
        // 0x8018BB7C: lui         $s1, 0x801C
        ctx->r17 = S32(0X801C << 16);
            goto L_8018BC80;
    }
    // 0x8018BB7C: lui         $s1, 0x801C
    ctx->r17 = S32(0X801C << 16);
    // 0x8018BB80: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018BB84: lwc1        $f20, 0x6F94($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X6F94);
    // 0x8018BB88: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018BB8C: lwc1        $f6, 0x6F98($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6F98);
    // 0x8018BB90: lwc1        $f4, 0x158($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X158);
    // 0x8018BB94: addiu       $s1, $s1, -0x7D14
    ctx->r17 = ADD32(ctx->r17, -0X7D14);
    // 0x8018BB98: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018BB9C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8018BBA0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8018BBA4: swc1        $f8, 0x158($s0)
    MEM_W(0X158, ctx->r16) = ctx->f8.u32l;
    // 0x8018BBA8: lwc1        $f10, 0x158($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X158);
    // 0x8018BBAC: c.lt.s      $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f20.fl < ctx->f10.fl;
    // 0x8018BBB0: nop

    // 0x8018BBB4: bc1f        L_8018BBC0
    if (!c1cs) {
        // 0x8018BBB8: nop
    
            goto L_8018BBC0;
    }
    // 0x8018BBB8: nop

    // 0x8018BBBC: swc1        $f20, 0x158($s0)
    MEM_W(0X158, ctx->r16) = ctx->f20.u32l;
L_8018BBC0:
    // 0x8018BBC0: lwc1        $f20, 0x6F9C($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X6F9C);
    // 0x8018BBC4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018BBC8: lwc1        $f22, 0x6FA0($at)
    ctx->f22.u32l = MEM_W(ctx->r1, 0X6FA0);
    // 0x8018BBCC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8018BBD0: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x8018BBD4: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8018BBD8: lui         $a1, 0x4370
    ctx->r5 = S32(0X4370 << 16);
    // 0x8018BBDC: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x8018BBE0: jal         0x8009BC2C
    // 0x8018BBE4: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_13;
    // 0x8018BBE4: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    after_13:
    // 0x8018BBE8: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8018BBEC: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8018BBF0: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x8018BBF4: addiu       $a0, $a0, -0x7D10
    ctx->r4 = ADD32(ctx->r4, -0X7D10);
    // 0x8018BBF8: lui         $a1, 0x4370
    ctx->r5 = S32(0X4370 << 16);
    // 0x8018BBFC: jal         0x8009BC2C
    // 0x8018BC00: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_14;
    // 0x8018BC00: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    after_14:
    // 0x8018BC04: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8018BC08: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8018BC0C: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x8018BC10: addiu       $a0, $a0, -0x7D0C
    ctx->r4 = ADD32(ctx->r4, -0X7D0C);
    // 0x8018BC14: lui         $a1, 0x437F
    ctx->r5 = S32(0X437F << 16);
    // 0x8018BC18: jal         0x8009BC2C
    // 0x8018BC1C: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_15;
    // 0x8018BC1C: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    after_15:
    // 0x8018BC20: lwc1        $f16, 0x0($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8018BC24: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018BC28: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8018BC2C: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8018BC30: addiu       $v1, $v1, -0x7D0C
    ctx->r3 = ADD32(ctx->r3, -0X7D0C);
    // 0x8018BC34: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8018BC38: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x8018BC3C: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x8018BC40: addiu       $t0, $t0, -0x7D40
    ctx->r8 = ADD32(ctx->r8, -0X7D40);
    // 0x8018BC44: lw          $v0, -0x7D4C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D4C);
    // 0x8018BC48: sw          $t6, -0x7AB8($at)
    MEM_W(-0X7AB8, ctx->r1) = ctx->r14;
    // 0x8018BC4C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018BC50: lwc1        $f4, -0x7D10($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7D10);
    // 0x8018BC54: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018BC58: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8018BC5C: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x8018BC60: nop

    // 0x8018BC64: sw          $t8, -0x7AB4($at)
    MEM_W(-0X7AB4, ctx->r1) = ctx->r24;
    // 0x8018BC68: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8018BC6C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018BC70: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8018BC74: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    // 0x8018BC78: nop

    // 0x8018BC7C: sw          $t1, -0x7AB0($at)
    MEM_W(-0X7AB0, ctx->r1) = ctx->r9;
L_8018BC80:
    // 0x8018BC80: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018BC84: lwc1        $f22, 0x6FA4($at)
    ctx->f22.u32l = MEM_W(ctx->r1, 0X6FA4);
    // 0x8018BC88: slti        $at, $v0, 0x3D
    ctx->r1 = SIGNED(ctx->r2) < 0X3D ? 1 : 0;
    // 0x8018BC8C: bne         $at, $zero, L_8018BCB0
    if (ctx->r1 != 0) {
        // 0x8018BC90: lui         $a1, 0x4180
        ctx->r5 = S32(0X4180 << 16);
            goto L_8018BCB0;
    }
    // 0x8018BC90: lui         $a1, 0x4180
    ctx->r5 = S32(0X4180 << 16);
    // 0x8018BC94: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8018BC98: addiu       $a0, $a0, -0x7CC0
    ctx->r4 = ADD32(ctx->r4, -0X7CC0);
    // 0x8018BC9C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8018BCA0: slti        $at, $v1, 0xFF
    ctx->r1 = SIGNED(ctx->r3) < 0XFF ? 1 : 0;
    // 0x8018BCA4: beq         $at, $zero, L_8018BCB0
    if (ctx->r1 == 0) {
        // 0x8018BCA8: addiu       $t2, $v1, 0x1
        ctx->r10 = ADD32(ctx->r3, 0X1);
            goto L_8018BCB0;
    }
    // 0x8018BCA8: addiu       $t2, $v1, 0x1
    ctx->r10 = ADD32(ctx->r3, 0X1);
    // 0x8018BCAC: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
L_8018BCB0:
    // 0x8018BCB0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8018BCB4: addiu       $a0, $a0, -0x7CC0
    ctx->r4 = ADD32(ctx->r4, -0X7CC0);
    // 0x8018BCB8: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x8018BCBC: addiu       $at, $zero, 0x80
    ctx->r1 = ADD32(0, 0X80);
    // 0x8018BCC0: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x8018BCC4: bne         $t3, $at, L_8018BCF0
    if (ctx->r11 != ctx->r1) {
        // 0x8018BCC8: addiu       $t4, $zero, 0x7
        ctx->r12 = ADD32(0, 0X7);
            goto L_8018BCF0;
    }
    // 0x8018BCC8: addiu       $t4, $zero, 0x7
    ctx->r12 = ADD32(0, 0X7);
    // 0x8018BCCC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018BCD0: sw          $t4, -0x7D58($at)
    MEM_W(-0X7D58, ctx->r1) = ctx->r12;
    // 0x8018BCD4: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x8018BCD8: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x8018BCDC: sw          $zero, 0x150($s0)
    MEM_W(0X150, ctx->r16) = 0;
    // 0x8018BCE0: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8018BCE4: sw          $zero, 0x154($s0)
    MEM_W(0X154, ctx->r16) = 0;
    // 0x8018BCE8: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x8018BCEC: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
L_8018BCF0:
    // 0x8018BCF0: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x8018BCF4: bnel        $v0, $at, L_8018BD04
    if (ctx->r2 != ctx->r1) {
        // 0x8018BCF8: addiu       $at, $zero, 0x3C
        ctx->r1 = ADD32(0, 0X3C);
            goto L_8018BD04;
    }
    goto skip_0;
    // 0x8018BCF8: addiu       $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
    skip_0:
    // 0x8018BCFC: sw          $zero, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = 0;
    // 0x8018BD00: addiu       $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
L_8018BD04:
    // 0x8018BD04: bnel        $v0, $at, L_8018BD14
    if (ctx->r2 != ctx->r1) {
        // 0x8018BD08: lui         $at, 0x42C8
        ctx->r1 = S32(0X42C8 << 16);
            goto L_8018BD14;
    }
    goto skip_1;
    // 0x8018BD08: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    skip_1:
    // 0x8018BD0C: sw          $zero, 0xA8($s0)
    MEM_W(0XA8, ctx->r16) = 0;
    // 0x8018BD10: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
L_8018BD14:
    // 0x8018BD14: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x8018BD18: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8018BD1C: addiu       $a0, $a0, -0x794C
    ctx->r4 = ADD32(ctx->r4, -0X794C);
    // 0x8018BD20: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x8018BD24: jal         0x8009BC2C
    // 0x8018BD28: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_16;
    // 0x8018BD28: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    after_16:
    // 0x8018BD2C: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8018BD30: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x8018BD34: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x8018BD38: addiu       $a0, $a0, -0x7954
    ctx->r4 = ADD32(ctx->r4, -0X7954);
    // 0x8018BD3C: lui         $a1, 0x430A
    ctx->r5 = S32(0X430A << 16);
    // 0x8018BD40: jal         0x8009BC2C
    // 0x8018BD44: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_17;
    // 0x8018BD44: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    after_17:
    // 0x8018BD48: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018BD4C: lwc1        $f16, -0x794C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X794C);
    // 0x8018BD50: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018BD54: lwc1        $f4, -0x7958($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7958);
    // 0x8018BD58: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8018BD5C: addiu       $a0, $a0, -0x7948
    ctx->r4 = ADD32(ctx->r4, -0X7948);
    // 0x8018BD60: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018BD64: lwc1        $f6, -0x7954($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7954);
    // 0x8018BD68: lwc1        $f18, 0x0($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8018BD6C: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8018BD70: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8018BD74: lui         $s1, 0x801C
    ctx->r17 = S32(0X801C << 16);
    // 0x8018BD78: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x8018BD7C: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x8018BD80: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x8018BD84: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x8018BD88: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x8018BD8C: addiu       $s1, $s1, -0x7944
    ctx->r17 = ADD32(ctx->r17, -0X7944);
    // 0x8018BD90: addiu       $v1, $v1, -0x793C
    ctx->r3 = ADD32(ctx->r3, -0X793C);
    // 0x8018BD94: addiu       $v0, $v0, -0x7940
    ctx->r2 = ADD32(ctx->r2, -0X7940);
    // 0x8018BD98: addiu       $t3, $t3, 0x79C0
    ctx->r11 = ADD32(ctx->r11, 0X79C0);
    // 0x8018BD9C: addiu       $t2, $t2, 0x79B8
    ctx->r10 = ADD32(ctx->r10, 0X79B8);
    // 0x8018BDA0: addiu       $t1, $t1, 0x79A0
    ctx->r9 = ADD32(ctx->r9, 0X79A0);
    // 0x8018BDA4: addiu       $t9, $t9, 0x7988
    ctx->r25 = ADD32(ctx->r25, 0X7988);
    // 0x8018BDA8: addiu       $t8, $t8, 0x7980
    ctx->r24 = ADD32(ctx->r24, 0X7980);
    // 0x8018BDAC: lui         $a3, 0x8017
    ctx->r7 = S32(0X8017 << 16);
    // 0x8018BDB0: addiu       $a3, $a3, 0x7978
    ctx->r7 = ADD32(ctx->r7, 0X7978);
    // 0x8018BDB4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8018BDB8: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8018BDBC: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x8018BDC0: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x8018BDC4: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x8018BDC8: lwc1        $f14, 0x0($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8018BDCC: lw          $a2, 0x0($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X0);
    // 0x8018BDD0: lwc1        $f12, 0x0($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8018BDD4: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    // 0x8018BDD8: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x8018BDDC: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    // 0x8018BDE0: jal         0x801914AC
    // 0x8018BDE4: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    Title_SetCamUp2(rdram, ctx);
        goto after_18;
    // 0x8018BDE4: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    after_18:
    // 0x8018BDE8: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8018BDEC: addiu       $v0, $v0, -0x7D4C
    ctx->r2 = ADD32(ctx->r2, -0X7D4C);
    // 0x8018BDF0: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x8018BDF4: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8018BDF8: b           L_8018C0A0
    // 0x8018BDFC: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
        goto L_8018C0A0;
    // 0x8018BDFC: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
L_8018BE00:
    // 0x8018BE00: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x8018BE04: lw          $t6, -0x7D58($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7D58);
    // 0x8018BE08: bne         $t6, $zero, L_8018C0A0
    if (ctx->r14 != 0) {
        // 0x8018BE0C: lui         $s1, 0x801C
        ctx->r17 = S32(0X801C << 16);
            goto L_8018C0A0;
    }
    // 0x8018BE0C: lui         $s1, 0x801C
    ctx->r17 = S32(0X801C << 16);
    // 0x8018BE10: addiu       $s1, $s1, -0x79B4
    ctx->r17 = ADD32(ctx->r17, -0X79B4);
    // 0x8018BE14: lui         $a1, 0x100
    ctx->r5 = S32(0X100 << 16);
    // 0x8018BE18: ori         $a1, $a1, 0x1E
    ctx->r5 = ctx->r5 | 0X1E;
    // 0x8018BE1C: jal         0x8001A55C
    // 0x8018BE20: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Audio_KillSfxBySourceAndId(rdram, ctx);
        goto after_19;
    // 0x8018BE20: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_19:
    // 0x8018BE24: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8018BE28: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x8018BE2C: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8018BE30: addiu       $t7, $t7, 0x5D3C
    ctx->r15 = ADD32(ctx->r15, 0X5D3C);
    // 0x8018BE34: lui         $a0, 0x900
    ctx->r4 = S32(0X900 << 16);
    // 0x8018BE38: ori         $a0, $a0, 0x2
    ctx->r4 = ctx->r4 | 0X2;
    // 0x8018BE3C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8018BE40: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8018BE44: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8018BE48: jal         0x80019218
    // 0x8018BE4C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Audio_PlaySfx(rdram, ctx);
        goto after_20;
    // 0x8018BE4C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_20:
    // 0x8018BE50: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x8018BE54: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018BE58: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8018BE5C: sw          $t8, -0x7D58($at)
    MEM_W(-0X7D58, ctx->r1) = ctx->r24;
    // 0x8018BE60: addiu       $a0, $a0, -0x7CC0
    ctx->r4 = ADD32(ctx->r4, -0X7CC0);
    // 0x8018BE64: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x8018BE68: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018BE6C: lwc1        $f0, 0x6FA8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6FA8);
    // 0x8018BE70: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018BE74: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8018BE78: sw          $t9, -0x7ADC($at)
    MEM_W(-0X7ADC, ctx->r1) = ctx->r25;
    // 0x8018BE7C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018BE80: swc1        $f0, -0x7AD4($at)
    MEM_W(-0X7AD4, ctx->r1) = ctx->f0.u32l;
    // 0x8018BE84: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018BE88: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8018BE8C: sw          $t1, -0x7A80($at)
    MEM_W(-0X7A80, ctx->r1) = ctx->r9;
    // 0x8018BE90: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018BE94: swc1        $f0, -0x7A78($at)
    MEM_W(-0X7A78, ctx->r1) = ctx->f0.u32l;
    // 0x8018BE98: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018BE9C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8018BEA0: sw          $t2, -0x7A24($at)
    MEM_W(-0X7A24, ctx->r1) = ctx->r10;
    // 0x8018BEA4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018BEA8: swc1        $f0, -0x7A1C($at)
    MEM_W(-0X7A1C, ctx->r1) = ctx->f0.u32l;
    // 0x8018BEAC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018BEB0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8018BEB4: sw          $t3, -0x79C8($at)
    MEM_W(-0X79C8, ctx->r1) = ctx->r11;
    // 0x8018BEB8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018BEBC: swc1        $f0, -0x79C0($at)
    MEM_W(-0X79C0, ctx->r1) = ctx->f0.u32l;
    // 0x8018BEC0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018BEC4: lui         $t5, 0x801C
    ctx->r13 = S32(0X801C << 16);
    // 0x8018BEC8: lw          $t5, -0x7D40($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X7D40);
    // 0x8018BECC: sw          $zero, -0x7D4C($at)
    MEM_W(-0X7D4C, ctx->r1) = 0;
    // 0x8018BED0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018BED4: addiu       $t4, $zero, 0x320
    ctx->r12 = ADD32(0, 0X320);
    // 0x8018BED8: sw          $t4, -0x7BF0($at)
    MEM_W(-0X7BF0, ctx->r1) = ctx->r12;
    // 0x8018BEDC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018BEE0: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8018BEE4: b           L_8018C0A0
    // 0x8018BEE8: sw          $t6, -0x7D40($at)
    MEM_W(-0X7D40, ctx->r1) = ctx->r14;
        goto L_8018C0A0;
    // 0x8018BEE8: sw          $t6, -0x7D40($at)
    MEM_W(-0X7D40, ctx->r1) = ctx->r14;
L_8018BEEC:
    // 0x8018BEEC: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x8018BEF0: lw          $t7, -0x7D58($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7D58);
    // 0x8018BEF4: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x8018BEF8: addiu       $s0, $s0, -0x7B18
    ctx->r16 = ADD32(ctx->r16, -0X7B18);
    // 0x8018BEFC: bne         $t7, $zero, L_8018C0A0
    if (ctx->r15 != 0) {
        // 0x8018BF00: lui         $at, 0x801B
        ctx->r1 = S32(0X801B << 16);
            goto L_8018C0A0;
    }
    // 0x8018BF00: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018BF04: lwc1        $f20, 0x6FAC($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X6FAC);
    // 0x8018BF08: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8018BF0C: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x8018BF10: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018BF14: lwc1        $f8, 0x6FB0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6FB0);
    // 0x8018BF18: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018BF1C: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8018BF20: swc1        $f8, 0x158($s0)
    MEM_W(0X158, ctx->r16) = ctx->f8.u32l;
    // 0x8018BF24: lwc1        $f10, 0x6FB4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6FB4);
    // 0x8018BF28: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8018BF2C: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x8018BF30: addiu       $a0, $a0, -0x79FC
    ctx->r4 = ADD32(ctx->r4, -0X79FC);
    // 0x8018BF34: lui         $a1, 0x4461
    ctx->r5 = S32(0X4461 << 16);
    // 0x8018BF38: jal         0x8009BC2C
    // 0x8018BF3C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_21;
    // 0x8018BF3C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_21:
    // 0x8018BF40: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018BF44: lwc1        $f20, 0x6FB8($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X6FB8);
    // 0x8018BF48: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018BF4C: lwc1        $f22, 0x6FBC($at)
    ctx->f22.u32l = MEM_W(ctx->r1, 0X6FBC);
    // 0x8018BF50: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8018BF54: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x8018BF58: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8018BF5C: addiu       $a0, $a0, -0x7954
    ctx->r4 = ADD32(ctx->r4, -0X7954);
    // 0x8018BF60: lui         $a1, 0x431A
    ctx->r5 = S32(0X431A << 16);
    // 0x8018BF64: jal         0x8009BC2C
    // 0x8018BF68: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_22;
    // 0x8018BF68: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    after_22:
    // 0x8018BF6C: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8018BF70: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8018BF74: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x8018BF78: addiu       $a0, $a0, -0x7958
    ctx->r4 = ADD32(ctx->r4, -0X7958);
    // 0x8018BF7C: lui         $a1, 0xC0A0
    ctx->r5 = S32(0XC0A0 << 16);
    // 0x8018BF80: jal         0x8009BC2C
    // 0x8018BF84: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_23;
    // 0x8018BF84: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    after_23:
    // 0x8018BF88: lui         $s1, 0x801C
    ctx->r17 = S32(0X801C << 16);
    // 0x8018BF8C: addiu       $s1, $s1, -0x7944
    ctx->r17 = ADD32(ctx->r17, -0X7944);
    // 0x8018BF90: mfc1        $a1, $f24
    ctx->r5 = (int32_t)ctx->f24.u32l;
    // 0x8018BF94: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8018BF98: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x8018BF9C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8018BFA0: jal         0x8009BC2C
    // 0x8018BFA4: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_24;
    // 0x8018BFA4: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    after_24:
    // 0x8018BFA8: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8018BFAC: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8018BFB0: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x8018BFB4: addiu       $a0, $a0, -0x794C
    ctx->r4 = ADD32(ctx->r4, -0X794C);
    // 0x8018BFB8: lui         $a1, 0x4220
    ctx->r5 = S32(0X4220 << 16);
    // 0x8018BFBC: jal         0x8009BC2C
    // 0x8018BFC0: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_25;
    // 0x8018BFC0: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    after_25:
    // 0x8018BFC4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018BFC8: lwc1        $f16, -0x794C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X794C);
    // 0x8018BFCC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018BFD0: lwc1        $f4, -0x7958($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7958);
    // 0x8018BFD4: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8018BFD8: addiu       $a0, $a0, -0x7948
    ctx->r4 = ADD32(ctx->r4, -0X7948);
    // 0x8018BFDC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018BFE0: lwc1        $f6, -0x7954($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7954);
    // 0x8018BFE4: lwc1        $f18, 0x0($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8018BFE8: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8018BFEC: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8018BFF0: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x8018BFF4: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x8018BFF8: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x8018BFFC: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x8018C000: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x8018C004: addiu       $v1, $v1, -0x793C
    ctx->r3 = ADD32(ctx->r3, -0X793C);
    // 0x8018C008: addiu       $v0, $v0, -0x7940
    ctx->r2 = ADD32(ctx->r2, -0X7940);
    // 0x8018C00C: addiu       $t3, $t3, 0x79C0
    ctx->r11 = ADD32(ctx->r11, 0X79C0);
    // 0x8018C010: addiu       $t2, $t2, 0x79B8
    ctx->r10 = ADD32(ctx->r10, 0X79B8);
    // 0x8018C014: addiu       $t1, $t1, 0x79A0
    ctx->r9 = ADD32(ctx->r9, 0X79A0);
    // 0x8018C018: addiu       $t9, $t9, 0x7988
    ctx->r25 = ADD32(ctx->r25, 0X7988);
    // 0x8018C01C: addiu       $t8, $t8, 0x7980
    ctx->r24 = ADD32(ctx->r24, 0X7980);
    // 0x8018C020: lui         $a3, 0x8017
    ctx->r7 = S32(0X8017 << 16);
    // 0x8018C024: addiu       $a3, $a3, 0x7978
    ctx->r7 = ADD32(ctx->r7, 0X7978);
    // 0x8018C028: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8018C02C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8018C030: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x8018C034: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x8018C038: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x8018C03C: lwc1        $f14, 0x0($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8018C040: lw          $a2, 0x0($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X0);
    // 0x8018C044: lwc1        $f12, 0x0($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8018C048: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    // 0x8018C04C: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x8018C050: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    // 0x8018C054: jal         0x801914AC
    // 0x8018C058: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    Title_SetCamUp2(rdram, ctx);
        goto after_26;
    // 0x8018C058: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    after_26:
    // 0x8018C05C: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8018C060: lw          $v0, -0x7D4C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D4C);
    // 0x8018C064: slti        $at, $v0, 0x9
    ctx->r1 = SIGNED(ctx->r2) < 0X9 ? 1 : 0;
    // 0x8018C068: bnel        $at, $zero, L_8018C098
    if (ctx->r1 != 0) {
        // 0x8018C06C: addiu       $t5, $v0, 0x1
        ctx->r13 = ADD32(ctx->r2, 0X1);
            goto L_8018C098;
    }
    goto skip_2;
    // 0x8018C06C: addiu       $t5, $v0, 0x1
    ctx->r13 = ADD32(ctx->r2, 0X1);
    skip_2:
    // 0x8018C070: jal         0x8001D400
    // 0x8018C074: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    Audio_SetEnvSfxReverb(rdram, ctx);
        goto after_27;
    // 0x8018C074: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_27:
    // 0x8018C078: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018C07C: sw          $zero, -0x7D40($at)
    MEM_W(-0X7D40, ctx->r1) = 0;
    // 0x8018C080: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018C084: addiu       $t4, $zero, 0x5
    ctx->r12 = ADD32(0, 0X5);
    // 0x8018C088: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8018C08C: lw          $v0, -0x7D4C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D4C);
    // 0x8018C090: sw          $t4, -0x7D3C($at)
    MEM_W(-0X7D3C, ctx->r1) = ctx->r12;
    // 0x8018C094: addiu       $t5, $v0, 0x1
    ctx->r13 = ADD32(ctx->r2, 0X1);
L_8018C098:
    // 0x8018C098: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018C09C: sw          $t5, -0x7D4C($at)
    MEM_W(-0X7D4C, ctx->r1) = ctx->r13;
L_8018C0A0:
    // 0x8018C0A0: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8018C0A4: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x8018C0A8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018C0AC: lwc1        $f12, -0x7938($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X7938);
    // 0x8018C0B0: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x8018C0B4: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x8018C0B8: lui         $s1, 0x801B
    ctx->r17 = S32(0X801B << 16);
    // 0x8018C0BC: addiu       $t7, $t7, -0x7D18
    ctx->r15 = ADD32(ctx->r15, -0X7D18);
    // 0x8018C0C0: addiu       $t6, $t6, -0x7D1C
    ctx->r14 = ADD32(ctx->r14, -0X7D1C);
    // 0x8018C0C4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018C0C8: lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // 0x8018C0CC: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x8018C0D0: addiu       $s1, $s1, 0x7BEC
    ctx->r17 = ADD32(ctx->r17, 0X7BEC);
    // 0x8018C0D4: addiu       $a3, $a3, -0x7D20
    ctx->r7 = ADD32(ctx->r7, -0X7D20);
    // 0x8018C0D8: lwc1        $f14, -0x7934($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X7934);
    // 0x8018C0DC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8018C0E0: jal         0x80191674
    // 0x8018C0E4: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    Title_SetLightRot(rdram, ctx);
        goto after_28;
    // 0x8018C0E4: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_28:
    // 0x8018C0E8: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x8018C0EC: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8018C0F0: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x8018C0F4: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x8018C0F8: ldc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X38);
    // 0x8018C0FC: ldc1        $f22, 0x40($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X40);
    // 0x8018C100: ldc1        $f24, 0x48($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X48);
    // 0x8018C104: lw          $s0, 0x54($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X54);
    // 0x8018C108: lw          $s1, 0x58($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X58);
    // 0x8018C10C: jr          $ra
    // 0x8018C110: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x8018C110: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void Option_NameEntry_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019CAE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8019CAE4: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8019CAE8: addiu       $v1, $v1, -0x6ED4
    ctx->r3 = ADD32(ctx->r3, -0X6ED4);
    // 0x8019CAEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8019CAF0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8019CAF4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8019CAF8: beq         $v0, $zero, L_8019CB20
    if (ctx->r2 == 0) {
        // 0x8019CAFC: nop
    
            goto L_8019CB20;
    }
    // 0x8019CAFC: nop

    // 0x8019CB00: beq         $v0, $at, L_8019CB40
    if (ctx->r2 == ctx->r1) {
        // 0x8019CB04: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8019CB40;
    }
    // 0x8019CB04: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8019CB08: beq         $v0, $at, L_8019CB50
    if (ctx->r2 == ctx->r1) {
        // 0x8019CB0C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8019CB50;
    }
    // 0x8019CB0C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8019CB10: beq         $v0, $at, L_8019CB84
    if (ctx->r2 == ctx->r1) {
        // 0x8019CB14: lui         $t1, 0x801C
        ctx->r9 = S32(0X801C << 16);
            goto L_8019CB84;
    }
    // 0x8019CB14: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x8019CB18: b           L_8019CBB4
    // 0x8019CB1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8019CBB4;
    // 0x8019CB1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8019CB20:
    // 0x8019CB20: jal         0x8019CBC0
    // 0x8019CB24: nop

    Option_NameEntry_Setup(rdram, ctx);
        goto after_0;
    // 0x8019CB24: nop

    after_0:
    // 0x8019CB28: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8019CB2C: addiu       $v1, $v1, -0x6ED4
    ctx->r3 = ADD32(ctx->r3, -0X6ED4);
    // 0x8019CB30: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8019CB34: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8019CB38: b           L_8019CBB0
    // 0x8019CB3C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
        goto L_8019CBB0;
    // 0x8019CB3C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
L_8019CB40:
    // 0x8019CB40: jal         0x8019CD54
    // 0x8019CB44: nop

    Option_NameEntry_Select(rdram, ctx);
        goto after_1;
    // 0x8019CB44: nop

    after_1:
    // 0x8019CB48: b           L_8019CBB4
    // 0x8019CB4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8019CBB4;
    // 0x8019CB4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8019CB50:
    // 0x8019CB50: jal         0x8019D624
    // 0x8019CB54: nop

    Option_Ranking_SaveData(rdram, ctx);
        goto after_2;
    // 0x8019CB54: nop

    after_2:
    // 0x8019CB58: jal         0x80188010
    // 0x8019CB5C: nop

    Title_GetRankTotalHits(rdram, ctx);
        goto after_3;
    // 0x8019CB5C: nop

    after_3:
    // 0x8019CB60: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8019CB64: addiu       $t8, $zero, 0xF
    ctx->r24 = ADD32(0, 0XF);
    // 0x8019CB68: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019CB6C: addiu       $v1, $v1, -0x6ED4
    ctx->r3 = ADD32(ctx->r3, -0X6ED4);
    // 0x8019CB70: sw          $t8, -0x6E84($at)
    MEM_W(-0X6E84, ctx->r1) = ctx->r24;
    // 0x8019CB74: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8019CB78: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8019CB7C: b           L_8019CBB0
    // 0x8019CB80: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
        goto L_8019CBB0;
    // 0x8019CB80: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
L_8019CB84:
    // 0x8019CB84: lw          $t1, -0x6E84($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X6E84);
    // 0x8019CB88: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x8019CB8C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8019CB90: bne         $t1, $zero, L_8019CBB0
    if (ctx->r9 != 0) {
        // 0x8019CB94: addiu       $t3, $zero, 0x12C
        ctx->r11 = ADD32(0, 0X12C);
            goto L_8019CBB0;
    }
    // 0x8019CB94: addiu       $t3, $zero, 0x12C
    ctx->r11 = ADD32(0, 0X12C);
    // 0x8019CB98: sb          $t2, 0x1A38($at)
    MEM_B(0X1A38, ctx->r1) = ctx->r10;
    // 0x8019CB9C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019CBA0: sw          $zero, 0x7898($at)
    MEM_W(0X7898, ctx->r1) = 0;
    // 0x8019CBA4: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x8019CBA8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019CBAC: sw          $t3, -0x6EDC($at)
    MEM_W(-0X6EDC, ctx->r1) = ctx->r11;
L_8019CBB0:
    // 0x8019CBB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8019CBB4:
    // 0x8019CBB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8019CBB8: jr          $ra
    // 0x8019CBBC: nop

    return;
    // 0x8019CBBC: nop

;}
RECOMP_FUNC void Option_GetRouteLineColor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80199284: lui         $v1, 0x801B
    ctx->r3 = S32(0X801B << 16);
    // 0x80199288: lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // 0x8019928C: addiu       $v0, $v0, -0x1194
    ctx->r2 = ADD32(ctx->r2, -0X1194);
    // 0x80199290: addiu       $v1, $v1, -0x12B4
    ctx->r3 = ADD32(ctx->r3, -0X12B4);
    // 0x80199294: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
L_80199298:
    // 0x80199298: bnel        $a0, $t6, L_801992B0
    if (ctx->r4 != ctx->r14) {
        // 0x8019929C: addiu       $v1, $v1, 0xC
        ctx->r3 = ADD32(ctx->r3, 0XC);
            goto L_801992B0;
    }
    goto skip_0;
    // 0x8019929C: addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
    skip_0:
    // 0x801992A0: lw          $t7, 0x4($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X4);
    // 0x801992A4: beql        $a1, $t7, L_801992BC
    if (ctx->r5 == ctx->r15) {
        // 0x801992A8: lw          $v0, 0x8($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X8);
            goto L_801992BC;
    }
    goto skip_1;
    // 0x801992A8: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    skip_1:
    // 0x801992AC: addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
L_801992B0:
    // 0x801992B0: bnel        $v1, $v0, L_80199298
    if (ctx->r3 != ctx->r2) {
        // 0x801992B4: lw          $t6, 0x0($v1)
        ctx->r14 = MEM_W(ctx->r3, 0X0);
            goto L_80199298;
    }
    goto skip_2;
    // 0x801992B4: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    skip_2:
    // 0x801992B8: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
L_801992BC:
    // 0x801992BC: jr          $ra
    // 0x801992C0: nop

    return;
    // 0x801992C0: nop

;}
RECOMP_FUNC void Map_PathChange_Input(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A4D7C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801A4D80: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801A4D84: jal         0x801A5770
    // 0x801A4D88: nop

    Map_Input_CursorY(rdram, ctx);
        goto after_0;
    // 0x801A4D88: nop

    after_0:
    // 0x801A4D8C: beq         $v0, $zero, L_801A4E08
    if (ctx->r2 == 0) {
        // 0x801A4D90: lui         $a2, 0x3F00
        ctx->r6 = S32(0X3F00 << 16);
            goto L_801A4E08;
    }
    // 0x801A4D90: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    // 0x801A4D94: lui         $t0, 0x801D
    ctx->r8 = S32(0X801D << 16);
    // 0x801A4D98: addiu       $t0, $t0, -0x1024
    ctx->r8 = ADD32(ctx->r8, -0X1024);
    // 0x801A4D9C: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x801A4DA0: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x801A4DA4: lui         $t7, 0x801D
    ctx->r15 = S32(0X801D << 16);
    // 0x801A4DA8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801A4DAC: lw          $t7, -0x26C4($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X26C4);
    // 0x801A4DB0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A4DB4: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x801A4DB8: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x801A4DBC: beq         $t7, $zero, L_801A4E00
    if (ctx->r15 == 0) {
        // 0x801A4DC0: swc1        $f4, -0x1018($at)
        MEM_W(-0X1018, ctx->r1) = ctx->f4.u32l;
            goto L_801A4E00;
    }
    // 0x801A4DC0: swc1        $f4, -0x1018($at)
    MEM_W(-0X1018, ctx->r1) = ctx->f4.u32l;
    // 0x801A4DC4: lui         $t8, 0x801D
    ctx->r24 = S32(0X801D << 16);
    // 0x801A4DC8: lw          $t8, -0x102C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X102C);
    // 0x801A4DCC: addiu       $t9, $v0, 0x1
    ctx->r25 = ADD32(ctx->r2, 0X1);
    // 0x801A4DD0: slti        $at, $t9, 0x3
    ctx->r1 = SIGNED(ctx->r25) < 0X3 ? 1 : 0;
    // 0x801A4DD4: bgez        $t8, L_801A4DEC
    if (SIGNED(ctx->r24) >= 0) {
        // 0x801A4DD8: addiu       $t2, $v0, -0x1
        ctx->r10 = ADD32(ctx->r2, -0X1);
            goto L_801A4DEC;
    }
    // 0x801A4DD8: addiu       $t2, $v0, -0x1
    ctx->r10 = ADD32(ctx->r2, -0X1);
    // 0x801A4DDC: bne         $at, $zero, L_801A4E08
    if (ctx->r1 != 0) {
        // 0x801A4DE0: sw          $t9, 0x0($t0)
        MEM_W(0X0, ctx->r8) = ctx->r25;
            goto L_801A4E08;
    }
    // 0x801A4DE0: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x801A4DE4: b           L_801A4E08
    // 0x801A4DE8: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
        goto L_801A4E08;
    // 0x801A4DE8: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
L_801A4DEC:
    // 0x801A4DEC: bgez        $t2, L_801A4E08
    if (SIGNED(ctx->r10) >= 0) {
        // 0x801A4DF0: sw          $t2, 0x0($t0)
        MEM_W(0X0, ctx->r8) = ctx->r10;
            goto L_801A4E08;
    }
    // 0x801A4DF0: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x801A4DF4: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x801A4DF8: b           L_801A4E08
    // 0x801A4DFC: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
        goto L_801A4E08;
    // 0x801A4DFC: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
L_801A4E00:
    // 0x801A4E00: xori        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 ^ 0X1;
    // 0x801A4E04: sw          $t5, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r13;
L_801A4E08:
    // 0x801A4E08: lui         $t0, 0x801D
    ctx->r8 = S32(0X801D << 16);
    // 0x801A4E0C: addiu       $t0, $t0, -0x1024
    ctx->r8 = ADD32(ctx->r8, -0X1024);
    // 0x801A4E10: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x801A4E14: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801A4E18: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801A4E1C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801A4E20: lui         $t8, 0x801D
    ctx->r24 = S32(0X801D << 16);
    // 0x801A4E24: addiu       $v0, $v0, -0x1020
    ctx->r2 = ADD32(ctx->r2, -0X1020);
    // 0x801A4E28: addiu       $t8, $t8, -0x1018
    ctx->r24 = ADD32(ctx->r24, -0X1018);
    // 0x801A4E2C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801A4E30: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    // 0x801A4E34: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x801A4E38: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x801A4E3C: jal         0x8009BC2C
    // 0x801A4E40: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_1;
    // 0x801A4E40: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x801A4E44: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801A4E48: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801A4E4C: addiu       $v0, $v0, -0x1020
    ctx->r2 = ADD32(ctx->r2, -0X1020);
    // 0x801A4E50: c.eq.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl == ctx->f8.fl;
    // 0x801A4E54: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x801A4E58: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x801A4E5C: bc1f        L_801A4E90
    if (!c1cs) {
        // 0x801A4E60: nop
    
            goto L_801A4E90;
    }
    // 0x801A4E60: nop

    // 0x801A4E64: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801A4E68: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801A4E6C: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x801A4E70: c.eq.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl == ctx->f10.fl;
    // 0x801A4E74: nop

    // 0x801A4E78: bc1fl       L_801A4E90
    if (!c1cs) {
        // 0x801A4E7C: swc1        $f0, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
            goto L_801A4E90;
    }
    goto skip_0;
    // 0x801A4E7C: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    skip_0:
    // 0x801A4E80: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801A4E84: b           L_801A4E90
    // 0x801A4E88: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
        goto L_801A4E90;
    // 0x801A4E88: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
    // 0x801A4E8C: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
L_801A4E90:
    // 0x801A4E90: lw          $t9, 0x7AF8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7AF8);
    // 0x801A4E94: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x801A4E98: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x801A4E9C: subu        $t1, $t1, $t9
    ctx->r9 = SUB32(ctx->r9, ctx->r25);
    // 0x801A4EA0: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x801A4EA4: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x801A4EA8: lhu         $v0, -0x2768($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X2768);
    // 0x801A4EAC: andi        $t2, $v0, 0x5000
    ctx->r10 = ctx->r2 & 0X5000;
    // 0x801A4EB0: beq         $t2, $zero, L_801A4ED8
    if (ctx->r10 == 0) {
        // 0x801A4EB4: andi        $t4, $v0, 0x8000
        ctx->r12 = ctx->r2 & 0X8000;
            goto L_801A4ED8;
    }
    // 0x801A4EB4: andi        $t4, $v0, 0x8000
    ctx->r12 = ctx->r2 & 0X8000;
    // 0x801A4EB8: jal         0x8001D6DC
    // 0x801A4EBC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    Audio_PlayMapMenuSfx(rdram, ctx);
        goto after_2;
    // 0x801A4EBC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x801A4EC0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A4EC4: sw          $zero, -0x103C($at)
    MEM_W(-0X103C, ctx->r1) = 0;
    // 0x801A4EC8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A4ECC: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x801A4ED0: b           L_801A4F7C
    // 0x801A4ED4: sw          $t3, -0x26BC($at)
    MEM_W(-0X26BC, ctx->r1) = ctx->r11;
        goto L_801A4F7C;
    // 0x801A4ED4: sw          $t3, -0x26BC($at)
    MEM_W(-0X26BC, ctx->r1) = ctx->r11;
L_801A4ED8:
    // 0x801A4ED8: beql        $t4, $zero, L_801A4F80
    if (ctx->r12 == 0) {
        // 0x801A4EDC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801A4F80;
    }
    goto skip_1;
    // 0x801A4EDC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x801A4EE0: jal         0x8001D6DC
    // 0x801A4EE4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    Audio_PlayMapMenuSfx(rdram, ctx);
        goto after_3;
    // 0x801A4EE4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x801A4EE8: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x801A4EEC: lui         $t5, 0x800C
    ctx->r13 = S32(0X800C << 16);
    // 0x801A4EF0: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x801A4EF4: addiu       $t5, $t5, 0x5D3C
    ctx->r13 = ADD32(ctx->r13, 0X5D3C);
    // 0x801A4EF8: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x801A4EFC: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x801A4F00: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x801A4F04: ori         $a0, $a0, 0x3
    ctx->r4 = ctx->r4 | 0X3;
    // 0x801A4F08: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x801A4F0C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x801A4F10: jal         0x80019218
    // 0x801A4F14: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_4;
    // 0x801A4F14: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_4:
    // 0x801A4F18: lui         $t0, 0x801D
    ctx->r8 = S32(0X801D << 16);
    // 0x801A4F1C: addiu       $t0, $t0, -0x1024
    ctx->r8 = ADD32(ctx->r8, -0X1024);
    // 0x801A4F20: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x801A4F24: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801A4F28: lw          $v1, -0x26C4($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X26C4);
    // 0x801A4F2C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A4F30: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x801A4F34: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x801A4F38: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x801A4F3C: beq         $v1, $zero, L_801A4F50
    if (ctx->r3 == 0) {
        // 0x801A4F40: sw          $a0, -0x1000($at)
        MEM_W(-0X1000, ctx->r1) = ctx->r4;
            goto L_801A4F50;
    }
    // 0x801A4F40: sw          $a0, -0x1000($at)
    MEM_W(-0X1000, ctx->r1) = ctx->r4;
    // 0x801A4F44: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801A4F48: beql        $v0, $at, L_801A4F60
    if (ctx->r2 == ctx->r1) {
        // 0x801A4F4C: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_801A4F60;
    }
    goto skip_2;
    // 0x801A4F4C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    skip_2:
L_801A4F50:
    // 0x801A4F50: bne         $v1, $zero, L_801A4F70
    if (ctx->r3 != 0) {
        // 0x801A4F54: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_801A4F70;
    }
    // 0x801A4F54: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801A4F58: bne         $v0, $at, L_801A4F70
    if (ctx->r2 != ctx->r1) {
        // 0x801A4F5C: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_801A4F70;
    }
    // 0x801A4F5C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
L_801A4F60:
    // 0x801A4F60: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A4F64: sw          $t7, -0x1030($at)
    MEM_W(-0X1030, ctx->r1) = ctx->r15;
    // 0x801A4F68: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A4F6C: sw          $a0, -0xFF4($at)
    MEM_W(-0XFF4, ctx->r1) = ctx->r4;
L_801A4F70:
    // 0x801A4F70: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801A4F74: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A4F78: sw          $t8, -0x26B4($at)
    MEM_W(-0X26B4, ctx->r1) = ctx->r24;
L_801A4F7C:
    // 0x801A4F7C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801A4F80:
    // 0x801A4F80: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801A4F84: jr          $ra
    // 0x801A4F88: nop

    return;
    // 0x801A4F88: nop

;}
RECOMP_FUNC void Map_CorneriaExplosion_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A8738: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801A873C: lui         $a2, 0x801D
    ctx->r6 = S32(0X801D << 16);
    // 0x801A8740: addiu       $a2, $a2, -0x14CC
    ctx->r6 = ADD32(ctx->r6, -0X14CC);
    // 0x801A8744: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801A8748: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801A874C: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x801A8750: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x801A8754: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x801A8758: bltz        $t6, L_801A89A8
    if (SIGNED(ctx->r14) < 0) {
        // 0x801A875C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_801A89A8;
    }
    // 0x801A875C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801A8760: jal         0x800B8DD0
    // 0x801A8764: addiu       $a1, $zero, 0x43
    ctx->r5 = ADD32(0, 0X43);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x801A8764: addiu       $a1, $zero, 0x43
    ctx->r5 = ADD32(0, 0X43);
    after_0:
    // 0x801A8768: lui         $a2, 0x801D
    ctx->r6 = S32(0X801D << 16);
    // 0x801A876C: addiu       $a2, $a2, -0x14CC
    ctx->r6 = ADD32(ctx->r6, -0X14CC);
    // 0x801A8770: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801A8774: lui         $t8, 0xFB00
    ctx->r24 = S32(0XFB00 << 16);
    // 0x801A8778: lui         $t9, 0xFF00
    ctx->r25 = S32(0XFF00 << 16);
    // 0x801A877C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801A8780: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x801A8784: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x801A8788: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x801A878C: lw          $a0, 0x0($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X0);
    // 0x801A8790: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801A8794: addiu       $v1, $v1, -0x14C4
    ctx->r3 = ADD32(ctx->r3, -0X14C4);
    // 0x801A8798: beq         $a0, $zero, L_801A87C0
    if (ctx->r4 == 0) {
        // 0x801A879C: lui         $at, 0x801B
        ctx->r1 = S32(0X801B << 16);
            goto L_801A87C0;
    }
    // 0x801A879C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A87A0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801A87A4: beq         $a0, $at, L_801A8820
    if (ctx->r4 == ctx->r1) {
        // 0x801A87A8: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_801A8820;
    }
    // 0x801A87A8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801A87AC: beq         $a0, $at, L_801A8874
    if (ctx->r4 == ctx->r1) {
        // 0x801A87B0: lui         $a1, 0x801D
        ctx->r5 = S32(0X801D << 16);
            goto L_801A8874;
    }
    // 0x801A87B0: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801A87B4: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801A87B8: b           L_801A88C4
    // 0x801A87BC: addiu       $a1, $a1, -0x14C8
    ctx->r5 = ADD32(ctx->r5, -0X14C8);
        goto L_801A88C4;
    // 0x801A87BC: addiu       $a1, $a1, -0x14C8
    ctx->r5 = ADD32(ctx->r5, -0X14C8);
L_801A87C0:
    // 0x801A87C0: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x801A87C4: lwc1        $f6, 0x79B0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X79B0);
    // 0x801A87C8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A87CC: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801A87D0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801A87D4: addiu       $v0, $v0, -0x14C0
    ctx->r2 = ADD32(ctx->r2, -0X14C0);
    // 0x801A87D8: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x801A87DC: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801A87E0: swc1        $f8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f8.u32l;
    // 0x801A87E4: lwc1        $f16, 0x79B4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X79B4);
    // 0x801A87E8: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
    // 0x801A87EC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A87F0: c.le.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl <= ctx->f10.fl;
    // 0x801A87F4: nop

    // 0x801A87F8: bc1f        L_801A8818
    if (!c1cs) {
        // 0x801A87FC: nop
    
            goto L_801A8818;
    }
    // 0x801A87FC: nop

    // 0x801A8800: lwc1        $f18, 0x79B8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X79B8);
    // 0x801A8804: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801A8808: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801A880C: sw          $t0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r8;
    // 0x801A8810: swc1        $f18, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f18.u32l;
    // 0x801A8814: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
L_801A8818:
    // 0x801A8818: b           L_801A88C4
    // 0x801A881C: addiu       $a1, $a1, -0x14C8
    ctx->r5 = ADD32(ctx->r5, -0X14C8);
        goto L_801A88C4;
    // 0x801A881C: addiu       $a1, $a1, -0x14C8
    ctx->r5 = ADD32(ctx->r5, -0X14C8);
L_801A8820:
    // 0x801A8820: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801A8824: addiu       $v0, $v0, -0x14C0
    ctx->r2 = ADD32(ctx->r2, -0X14C0);
    // 0x801A8828: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801A882C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801A8830: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801A8834: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801A8838: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801A883C: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x801A8840: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
    // 0x801A8844: lwc1        $f18, 0x0($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801A8848: c.le.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl <= ctx->f16.fl;
    // 0x801A884C: nop

    // 0x801A8850: bc1f        L_801A886C
    if (!c1cs) {
        // 0x801A8854: addiu       $t1, $zero, 0x3
        ctx->r9 = ADD32(0, 0X3);
            goto L_801A886C;
    }
    // 0x801A8854: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x801A8858: sw          $t1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r9;
    // 0x801A885C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A8860: lwc1        $f4, 0x79BC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X79BC);
    // 0x801A8864: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A8868: swc1        $f4, -0x14C4($at)
    MEM_W(-0X14C4, ctx->r1) = ctx->f4.u32l;
L_801A886C:
    // 0x801A886C: b           L_801A88C4
    // 0x801A8870: addiu       $a1, $a1, -0x14C8
    ctx->r5 = ADD32(ctx->r5, -0X14C8);
        goto L_801A88C4;
    // 0x801A8870: addiu       $a1, $a1, -0x14C8
    ctx->r5 = ADD32(ctx->r5, -0X14C8);
L_801A8874:
    // 0x801A8874: addiu       $a1, $a1, -0x14C8
    ctx->r5 = ADD32(ctx->r5, -0X14C8);
    // 0x801A8878: lw          $t2, 0x0($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X0);
    // 0x801A887C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A8880: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x801A8884: addiu       $t3, $t2, -0x8
    ctx->r11 = ADD32(ctx->r10, -0X8);
    // 0x801A8888: sw          $t3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r11;
    // 0x801A888C: lwc1        $f6, -0x14C4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X14C4);
    // 0x801A8890: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A8894: lwc1        $f8, 0x79C0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X79C0);
    // 0x801A8898: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A889C: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x801A88A0: swc1        $f10, -0x14C4($at)
    MEM_W(-0X14C4, ctx->r1) = ctx->f10.u32l;
    // 0x801A88A4: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x801A88A8: bgez        $v0, L_801A88B8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x801A88AC: nop
    
            goto L_801A88B8;
    }
    // 0x801A88AC: nop

    // 0x801A88B0: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x801A88B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801A88B8:
    // 0x801A88B8: bnel        $v0, $zero, L_801A88C8
    if (ctx->r2 != 0) {
        // 0x801A88BC: lw          $v0, 0x0($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X0);
            goto L_801A88C8;
    }
    goto skip_0;
    // 0x801A88BC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    skip_0:
    // 0x801A88C0: sw          $t4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r12;
L_801A88C4:
    // 0x801A88C4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_801A88C8:
    // 0x801A88C8: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x801A88CC: lui         $at, 0xFFC8
    ctx->r1 = S32(0XFFC8 << 16);
    // 0x801A88D0: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x801A88D4: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x801A88D8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x801A88DC: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x801A88E0: ori         $at, $at, 0xC800
    ctx->r1 = ctx->r1 | 0XC800;
    // 0x801A88E4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A88E8: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x801A88EC: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x801A88F0: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x801A88F4: jal         0x80005708
    // 0x801A88F8: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Push(rdram, ctx);
        goto after_1;
    // 0x801A88F8: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_1:
    // 0x801A88FC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A8900: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801A8904: addiu       $a1, $a1, -0x1FA0
    ctx->r5 = ADD32(ctx->r5, -0X1FA0);
    // 0x801A8908: jal         0x80005680
    // 0x801A890C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Copy(rdram, ctx);
        goto after_2;
    // 0x801A890C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_2:
    // 0x801A8910: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A8914: lui         $a1, 0xBF5F
    ctx->r5 = S32(0XBF5F << 16);
    // 0x801A8918: ori         $a1, $a1, 0x66F3
    ctx->r5 = ctx->r5 | 0X66F3;
    // 0x801A891C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x801A8920: jal         0x80005FE0
    // 0x801A8924: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateZ(rdram, ctx);
        goto after_3;
    // 0x801A8924: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x801A8928: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801A892C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A8930: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801A8934: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801A8938: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x801A893C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x801A8940: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x801A8944: jal         0x80005B00
    // 0x801A8948: lui         $a2, 0x41C8
    ctx->r6 = S32(0X41C8 << 16);
    Matrix_Translate(rdram, ctx);
        goto after_4;
    // 0x801A8948: lui         $a2, 0x41C8
    ctx->r6 = S32(0X41C8 << 16);
    after_4:
    // 0x801A894C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A8950: lwc1        $f0, -0x14C4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X14C4);
    // 0x801A8954: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A8958: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801A895C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801A8960: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801A8964: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x801A8968: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x801A896C: jal         0x80005C34
    // 0x801A8970: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Scale(rdram, ctx);
        goto after_5;
    // 0x801A8970: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_5:
    // 0x801A8974: jal         0x80006EB8
    // 0x801A8978: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_6;
    // 0x801A8978: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x801A897C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801A8980: lui         $t4, 0x604
    ctx->r12 = S32(0X604 << 16);
    // 0x801A8984: addiu       $t4, $t4, 0x79D0
    ctx->r12 = ADD32(ctx->r12, 0X79D0);
    // 0x801A8988: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x801A898C: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x801A8990: lui         $t3, 0x600
    ctx->r11 = S32(0X600 << 16);
    // 0x801A8994: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x801A8998: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x801A899C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A89A0: jal         0x80005740
    // 0x801A89A4: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Pop(rdram, ctx);
        goto after_7;
    // 0x801A89A4: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_7:
L_801A89A8:
    // 0x801A89A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801A89AC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801A89B0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801A89B4: jr          $ra
    // 0x801A89B8: nop

    return;
    // 0x801A89B8: nop

;}
RECOMP_FUNC void Title_Team_OverrideLimbDraw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018EDC8: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8018EDCC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8018EDD0: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x8018EDD4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8018EDD8: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x8018EDDC: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x8018EDE0: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x8018EDE4: lw          $t7, -0x795C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X795C);
    // 0x8018EDE8: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x8018EDEC: lui         $t8, 0x801C
    ctx->r24 = S32(0X801C << 16);
    // 0x8018EDF0: slti        $at, $t7, 0x2
    ctx->r1 = SIGNED(ctx->r15) < 0X2 ? 1 : 0;
    // 0x8018EDF4: beq         $at, $zero, L_8018F11C
    if (ctx->r1 == 0) {
        // 0x8018EDF8: lw          $v1, 0x0($t6)
        ctx->r3 = MEM_W(ctx->r14, 0X0);
            goto L_8018F11C;
    }
    // 0x8018EDF8: lw          $v1, 0x0($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X0);
    // 0x8018EDFC: lw          $t8, -0x6FC0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X6FC0);
    // 0x8018EE00: addiu       $t1, $zero, 0x60
    ctx->r9 = ADD32(0, 0X60);
    // 0x8018EE04: beq         $t8, $zero, L_8018F11C
    if (ctx->r24 == 0) {
        // 0x8018EE08: nop
    
            goto L_8018F11C;
    }
    // 0x8018EE08: nop

    // 0x8018EE0C: multu       $v1, $t1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8018EE10: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x8018EE14: addiu       $t0, $t0, -0x7CB0
    ctx->r8 = ADD32(ctx->r8, -0X7CB0);
    // 0x8018EE18: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018EE1C: lwc1        $f4, -0x6FA4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6FA4);
    // 0x8018EE20: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018EE24: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    // 0x8018EE28: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x8018EE2C: mflo        $t9
    ctx->r25 = lo;
    // 0x8018EE30: addu        $v0, $t0, $t9
    ctx->r2 = ADD32(ctx->r8, ctx->r25);
    // 0x8018EE34: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8018EE38: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8018EE3C: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8018EE40: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8018EE44: lwc1        $f4, -0x6FA0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6FA0);
    // 0x8018EE48: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018EE4C: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8018EE50: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8018EE54: lwc1        $f6, -0x6F9C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X6F9C);
    // 0x8018EE58: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8018EE5C: sub.s       $f2, $f4, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f18.fl;
    // 0x8018EE60: sub.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8018EE64: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8018EE68: swc1        $f2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f2.u32l;
    // 0x8018EE6C: mul.s       $f4, $f16, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x8018EE70: swc1        $f16, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f16.u32l;
    // 0x8018EE74: add.s       $f0, $f10, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8018EE78: jal         0x80005100
    // 0x8018EE7C: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    Math_Atan2F(rdram, ctx);
        goto after_0;
    // 0x8018EE7C: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    after_0:
    // 0x8018EE80: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018EE84: lwc1        $f18, 0x7094($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7094);
    // 0x8018EE88: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x8018EE8C: lwc1        $f12, 0x40($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8018EE90: mul.s       $f6, $f0, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x8018EE94: lwc1        $f14, 0x3C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8018EE98: jal         0x80005100
    // 0x8018EE9C: swc1        $f6, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f6.u32l;
    Math_Atan2F(rdram, ctx);
        goto after_1;
    // 0x8018EE9C: swc1        $f6, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f6.u32l;
    after_1:
    // 0x8018EEA0: lui         $at, 0xC234
    ctx->r1 = S32(0XC234 << 16);
    // 0x8018EEA4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8018EEA8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018EEAC: lwc1        $f8, 0x7098($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7098);
    // 0x8018EEB0: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x8018EEB4: lui         $a2, 0x3C23
    ctx->r6 = S32(0X3C23 << 16);
    // 0x8018EEB8: mul.s       $f2, $f0, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8018EEBC: lwc1        $f12, 0x28($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X28);
    // 0x8018EEC0: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x8018EEC4: ori         $a2, $a2, 0xD70A
    ctx->r6 = ctx->r6 | 0XD70A;
    // 0x8018EEC8: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x8018EECC: c.lt.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
    // 0x8018EED0: addiu       $a0, $v0, 0x30
    ctx->r4 = ADD32(ctx->r2, 0X30);
    // 0x8018EED4: swc1        $f2, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f2.u32l;
    // 0x8018EED8: swc1        $f2, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->f2.u32l;
    // 0x8018EEDC: bc1f        L_8018EEEC
    if (!c1cs) {
        // 0x8018EEE0: swc1        $f12, 0x38($v0)
        MEM_W(0X38, ctx->r2) = ctx->f12.u32l;
            goto L_8018EEEC;
    }
    // 0x8018EEE0: swc1        $f12, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f12.u32l;
    // 0x8018EEE4: b           L_8018EF0C
    // 0x8018EEE8: swc1        $f14, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f14.u32l;
        goto L_8018EF0C;
    // 0x8018EEE8: swc1        $f14, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f14.u32l;
L_8018EEEC:
    // 0x8018EEEC: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x8018EEF0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8018EEF4: nop

    // 0x8018EEF8: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x8018EEFC: nop

    // 0x8018EF00: bc1fl       L_8018EF10
    if (!c1cs) {
        // 0x8018EF04: lui         $at, 0xC220
        ctx->r1 = S32(0XC220 << 16);
            goto L_8018EF10;
    }
    goto skip_0;
    // 0x8018EF04: lui         $at, 0xC220
    ctx->r1 = S32(0XC220 << 16);
    skip_0:
    // 0x8018EF08: swc1        $f0, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f0.u32l;
L_8018EF0C:
    // 0x8018EF0C: lui         $at, 0xC220
    ctx->r1 = S32(0XC220 << 16);
L_8018EF10:
    // 0x8018EF10: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8018EF14: lwc1        $f0, 0x2C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x8018EF18: lui         $at, 0x425C
    ctx->r1 = S32(0X425C << 16);
    // 0x8018EF1C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8018EF20: nop

    // 0x8018EF24: bc1fl       L_8018EF38
    if (!c1cs) {
        // 0x8018EF28: mtc1        $at, $f2
        ctx->f2.u32l = ctx->r1;
            goto L_8018EF38;
    }
    goto skip_1;
    // 0x8018EF28: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    skip_1:
    // 0x8018EF2C: b           L_8018EF50
    // 0x8018EF30: swc1        $f2, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f2.u32l;
        goto L_8018EF50;
    // 0x8018EF30: swc1        $f2, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f2.u32l;
    // 0x8018EF34: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
L_8018EF38:
    // 0x8018EF38: nop

    // 0x8018EF3C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8018EF40: nop

    // 0x8018EF44: bc1fl       L_8018EF54
    if (!c1cs) {
        // 0x8018EF48: lui         $at, 0xC1A0
        ctx->r1 = S32(0XC1A0 << 16);
            goto L_8018EF54;
    }
    goto skip_2;
    // 0x8018EF48: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    skip_2:
    // 0x8018EF4C: swc1        $f2, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f2.u32l;
L_8018EF50:
    // 0x8018EF50: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
L_8018EF54:
    // 0x8018EF54: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8018EF58: lwc1        $f0, 0x38($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X38);
    // 0x8018EF5C: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8018EF60: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8018EF64: nop

    // 0x8018EF68: bc1fl       L_8018EF98
    if (!c1cs) {
        // 0x8018EF6C: mtc1        $at, $f2
        ctx->f2.u32l = ctx->r1;
            goto L_8018EF98;
    }
    goto skip_3;
    // 0x8018EF6C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    skip_3:
    // 0x8018EF70: sub.s       $f10, $f0, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8018EF74: swc1        $f10, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f10.u32l;
    // 0x8018EF78: lwc1        $f4, 0x38($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X38);
    // 0x8018EF7C: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x8018EF80: nop

    // 0x8018EF84: bc1fl       L_8018EFE0
    if (!c1cs) {
        // 0x8018EF88: lui         $at, 0xC20C
        ctx->r1 = S32(0XC20C << 16);
            goto L_8018EFE0;
    }
    goto skip_4;
    // 0x8018EF88: lui         $at, 0xC20C
    ctx->r1 = S32(0XC20C << 16);
    skip_4:
    // 0x8018EF8C: b           L_8018EFDC
    // 0x8018EF90: swc1        $f2, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f2.u32l;
        goto L_8018EFDC;
    // 0x8018EF90: swc1        $f2, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f2.u32l;
    // 0x8018EF94: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
L_8018EF98:
    // 0x8018EF98: nop

    // 0x8018EF9C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8018EFA0: nop

    // 0x8018EFA4: bc1fl       L_8018EFD4
    if (!c1cs) {
        // 0x8018EFA8: mtc1        $zero, $f8
        ctx->f8.u32l = 0;
            goto L_8018EFD4;
    }
    goto skip_5;
    // 0x8018EFA8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    skip_5:
    // 0x8018EFAC: sub.s       $f18, $f0, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8018EFB0: swc1        $f18, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f18.u32l;
    // 0x8018EFB4: lwc1        $f6, 0x38($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X38);
    // 0x8018EFB8: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x8018EFBC: nop

    // 0x8018EFC0: bc1fl       L_8018EFE0
    if (!c1cs) {
        // 0x8018EFC4: lui         $at, 0xC20C
        ctx->r1 = S32(0XC20C << 16);
            goto L_8018EFE0;
    }
    goto skip_6;
    // 0x8018EFC4: lui         $at, 0xC20C
    ctx->r1 = S32(0XC20C << 16);
    skip_6:
    // 0x8018EFC8: b           L_8018EFDC
    // 0x8018EFCC: swc1        $f2, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f2.u32l;
        goto L_8018EFDC;
    // 0x8018EFCC: swc1        $f2, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f2.u32l;
    // 0x8018EFD0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
L_8018EFD4:
    // 0x8018EFD4: nop

    // 0x8018EFD8: swc1        $f8, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f8.u32l;
L_8018EFDC:
    // 0x8018EFDC: lui         $at, 0xC20C
    ctx->r1 = S32(0XC20C << 16);
L_8018EFE0:
    // 0x8018EFE0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8018EFE4: lwc1        $f0, 0x3C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x8018EFE8: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x8018EFEC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8018EFF0: nop

    // 0x8018EFF4: bc1fl       L_8018F02C
    if (!c1cs) {
        // 0x8018EFF8: mtc1        $at, $f2
        ctx->f2.u32l = ctx->r1;
            goto L_8018F02C;
    }
    goto skip_7;
    // 0x8018EFF8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    skip_7:
    // 0x8018EFFC: sub.s       $f10, $f0, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8018F000: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x8018F004: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8018F008: swc1        $f10, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->f10.u32l;
    // 0x8018F00C: lwc1        $f4, 0x3C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x8018F010: c.lt.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl < ctx->f12.fl;
    // 0x8018F014: nop

    // 0x8018F018: bc1f        L_8018F080
    if (!c1cs) {
        // 0x8018F01C: nop
    
            goto L_8018F080;
    }
    // 0x8018F01C: nop

    // 0x8018F020: b           L_8018F080
    // 0x8018F024: swc1        $f12, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->f12.u32l;
        goto L_8018F080;
    // 0x8018F024: swc1        $f12, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->f12.u32l;
    // 0x8018F028: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
L_8018F02C:
    // 0x8018F02C: nop

    // 0x8018F030: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8018F034: nop

    // 0x8018F038: bc1fl       L_8018F078
    if (!c1cs) {
        // 0x8018F03C: mtc1        $zero, $f4
        ctx->f4.u32l = 0;
            goto L_8018F078;
    }
    goto skip_8;
    // 0x8018F03C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    skip_8:
    // 0x8018F040: sub.s       $f18, $f0, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8018F044: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8018F048: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018F04C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8018F050: swc1        $f18, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->f18.u32l;
    // 0x8018F054: lwc1        $f8, 0x3C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x8018F058: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x8018F05C: nop

    // 0x8018F060: bc1f        L_8018F080
    if (!c1cs) {
        // 0x8018F064: nop
    
            goto L_8018F080;
    }
    // 0x8018F064: nop

    // 0x8018F068: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018F06C: b           L_8018F080
    // 0x8018F070: swc1        $f10, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->f10.u32l;
        goto L_8018F080;
    // 0x8018F070: swc1        $f10, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->f10.u32l;
    // 0x8018F074: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
L_8018F078:
    // 0x8018F078: nop

    // 0x8018F07C: swc1        $f4, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->f4.u32l;
L_8018F080:
    // 0x8018F080: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018F084: lwc1        $f18, 0x709C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X709C);
    // 0x8018F088: lw          $a1, 0x28($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X28);
    // 0x8018F08C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8018F090: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    // 0x8018F094: jal         0x8009BC2C
    // 0x8018F098: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_2;
    // 0x8018F098: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_2:
    // 0x8018F09C: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x8018F0A0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018F0A4: lwc1        $f6, 0x70A0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X70A0);
    // 0x8018F0A8: lui         $a2, 0x3C23
    ctx->r6 = S32(0X3C23 << 16);
    // 0x8018F0AC: ori         $a2, $a2, 0xD70A
    ctx->r6 = ctx->r6 | 0XD70A;
    // 0x8018F0B0: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x8018F0B4: addiu       $a0, $v0, 0x34
    ctx->r4 = ADD32(ctx->r2, 0X34);
    // 0x8018F0B8: lw          $a1, 0x2C($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X2C);
    // 0x8018F0BC: jal         0x8009BC2C
    // 0x8018F0C0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_3;
    // 0x8018F0C0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_3:
    // 0x8018F0C4: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x8018F0C8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018F0CC: lwc1        $f8, 0x70A4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X70A4);
    // 0x8018F0D0: lui         $a2, 0x3BA3
    ctx->r6 = S32(0X3BA3 << 16);
    // 0x8018F0D4: ori         $a2, $a2, 0xD70A
    ctx->r6 = ctx->r6 | 0XD70A;
    // 0x8018F0D8: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x8018F0DC: addiu       $a0, $v0, 0x40
    ctx->r4 = ADD32(ctx->r2, 0X40);
    // 0x8018F0E0: lw          $a1, 0x38($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X38);
    // 0x8018F0E4: jal         0x8009BC2C
    // 0x8018F0E8: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_4;
    // 0x8018F0E8: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_4:
    // 0x8018F0EC: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x8018F0F0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018F0F4: lwc1        $f10, 0x70A8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X70A8);
    // 0x8018F0F8: lui         $a2, 0x3BA3
    ctx->r6 = S32(0X3BA3 << 16);
    // 0x8018F0FC: ori         $a2, $a2, 0xD70A
    ctx->r6 = ctx->r6 | 0XD70A;
    // 0x8018F100: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x8018F104: addiu       $a0, $v0, 0x44
    ctx->r4 = ADD32(ctx->r2, 0X44);
    // 0x8018F108: lw          $a1, 0x3C($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X3C);
    // 0x8018F10C: jal         0x8009BC2C
    // 0x8018F110: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_5;
    // 0x8018F110: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_5:
    // 0x8018F114: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x8018F118: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
L_8018F11C:
    // 0x8018F11C: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x8018F120: addiu       $t0, $t0, -0x7CB0
    ctx->r8 = ADD32(ctx->r8, -0X7CB0);
    // 0x8018F124: beq         $v1, $zero, L_8018F154
    if (ctx->r3 == 0) {
        // 0x8018F128: addiu       $t1, $zero, 0x60
        ctx->r9 = ADD32(0, 0X60);
            goto L_8018F154;
    }
    // 0x8018F128: addiu       $t1, $zero, 0x60
    ctx->r9 = ADD32(0, 0X60);
    // 0x8018F12C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8018F130: beq         $v1, $v0, L_8018F1EC
    if (ctx->r3 == ctx->r2) {
        // 0x8018F134: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_8018F1EC;
    }
    // 0x8018F134: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8018F138: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8018F13C: beq         $v1, $at, L_8018F2C4
    if (ctx->r3 == ctx->r1) {
        // 0x8018F140: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8018F2C4;
    }
    // 0x8018F140: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8018F144: beq         $v1, $at, L_8018F374
    if (ctx->r3 == ctx->r1) {
        // 0x8018F148: nop
    
            goto L_8018F374;
    }
    // 0x8018F148: nop

    // 0x8018F14C: b           L_8018F424
    // 0x8018F150: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8018F424;
    // 0x8018F150: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8018F154:
    // 0x8018F154: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8018F158: bne         $a0, $v0, L_8018F17C
    if (ctx->r4 != ctx->r2) {
        // 0x8018F15C: addiu       $at, $zero, 0x13
        ctx->r1 = ADD32(0, 0X13);
            goto L_8018F17C;
    }
    // 0x8018F15C: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x8018F160: multu       $v1, $t1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8018F164: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8018F168: mflo        $t2
    ctx->r10 = lo;
    // 0x8018F16C: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x8018F170: lwc1        $f18, 0x18($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0X18);
    // 0x8018F174: add.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x8018F178: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
L_8018F17C:
    // 0x8018F17C: bnel        $a0, $at, L_8018F1B4
    if (ctx->r4 != ctx->r1) {
        // 0x8018F180: addiu       $at, $zero, 0x14
        ctx->r1 = ADD32(0, 0X14);
            goto L_8018F1B4;
    }
    goto skip_9;
    // 0x8018F180: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    skip_9:
    // 0x8018F184: multu       $v1, $t1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8018F188: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8018F18C: lwc1        $f18, 0x4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8018F190: mflo        $t4
    ctx->r12 = lo;
    // 0x8018F194: addu        $v0, $t0, $t4
    ctx->r2 = ADD32(ctx->r8, ctx->r12);
    // 0x8018F198: lwc1        $f10, 0x30($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X30);
    // 0x8018F19C: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8018F1A0: swc1        $f4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f4.u32l;
    // 0x8018F1A4: lwc1        $f6, 0x34($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X34);
    // 0x8018F1A8: add.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x8018F1AC: swc1        $f8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f8.u32l;
    // 0x8018F1B0: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
L_8018F1B4:
    // 0x8018F1B4: bnel        $a0, $at, L_8018F424
    if (ctx->r4 != ctx->r1) {
        // 0x8018F1B8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8018F424;
    }
    goto skip_10;
    // 0x8018F1B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_10:
    // 0x8018F1BC: multu       $v1, $t1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8018F1C0: lwc1        $f10, 0x0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8018F1C4: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8018F1C8: mflo        $t5
    ctx->r13 = lo;
    // 0x8018F1CC: addu        $v0, $t0, $t5
    ctx->r2 = ADD32(ctx->r8, ctx->r13);
    // 0x8018F1D0: lwc1        $f4, 0x40($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X40);
    // 0x8018F1D4: add.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8018F1D8: swc1        $f18, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f18.u32l;
    // 0x8018F1DC: lwc1        $f8, 0x44($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X44);
    // 0x8018F1E0: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8018F1E4: b           L_8018F420
    // 0x8018F1E8: swc1        $f10, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f10.u32l;
        goto L_8018F420;
    // 0x8018F1E8: swc1        $f10, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f10.u32l;
L_8018F1EC:
    // 0x8018F1EC: bne         $a0, $v0, L_8018F210
    if (ctx->r4 != ctx->r2) {
        // 0x8018F1F0: nop
    
            goto L_8018F210;
    }
    // 0x8018F1F0: nop

    // 0x8018F1F4: multu       $v1, $t1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8018F1F8: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8018F1FC: mflo        $t6
    ctx->r14 = lo;
    // 0x8018F200: addu        $t7, $t0, $t6
    ctx->r15 = ADD32(ctx->r8, ctx->r14);
    // 0x8018F204: lwc1        $f18, 0x18($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0X18);
    // 0x8018F208: add.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x8018F20C: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
L_8018F210:
    // 0x8018F210: bnel        $a0, $at, L_8018F238
    if (ctx->r4 != ctx->r1) {
        // 0x8018F214: addiu       $at, $zero, 0x13
        ctx->r1 = ADD32(0, 0X13);
            goto L_8018F238;
    }
    goto skip_11;
    // 0x8018F214: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    skip_11:
    // 0x8018F218: multu       $v1, $t1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8018F21C: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8018F220: mflo        $t8
    ctx->r24 = lo;
    // 0x8018F224: addu        $t9, $t0, $t8
    ctx->r25 = ADD32(ctx->r8, ctx->r24);
    // 0x8018F228: lwc1        $f10, 0x20($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X20);
    // 0x8018F22C: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8018F230: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    // 0x8018F234: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
L_8018F238:
    // 0x8018F238: bnel        $a0, $at, L_8018F270
    if (ctx->r4 != ctx->r1) {
        // 0x8018F23C: addiu       $at, $zero, 0x14
        ctx->r1 = ADD32(0, 0X14);
            goto L_8018F270;
    }
    goto skip_12;
    // 0x8018F23C: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    skip_12:
    // 0x8018F240: multu       $v1, $t1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8018F244: lwc1        $f18, 0x0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8018F248: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8018F24C: mflo        $t2
    ctx->r10 = lo;
    // 0x8018F250: addu        $v0, $t0, $t2
    ctx->r2 = ADD32(ctx->r8, ctx->r10);
    // 0x8018F254: lwc1        $f6, 0x30($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X30);
    // 0x8018F258: add.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x8018F25C: swc1        $f8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f8.u32l;
    // 0x8018F260: lwc1        $f4, 0x34($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X34);
    // 0x8018F264: add.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8018F268: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
    // 0x8018F26C: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
L_8018F270:
    // 0x8018F270: bnel        $a0, $at, L_8018F2A8
    if (ctx->r4 != ctx->r1) {
        // 0x8018F274: addiu       $at, $zero, 0x15
        ctx->r1 = ADD32(0, 0X15);
            goto L_8018F2A8;
    }
    goto skip_13;
    // 0x8018F274: addiu       $at, $zero, 0x15
    ctx->r1 = ADD32(0, 0X15);
    skip_13:
    // 0x8018F278: multu       $v1, $t1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8018F27C: lwc1        $f6, 0x0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8018F280: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8018F284: mflo        $t3
    ctx->r11 = lo;
    // 0x8018F288: addu        $v0, $t0, $t3
    ctx->r2 = ADD32(ctx->r8, ctx->r11);
    // 0x8018F28C: lwc1        $f8, 0x40($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X40);
    // 0x8018F290: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8018F294: swc1        $f10, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f10.u32l;
    // 0x8018F298: lwc1        $f18, 0x44($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X44);
    // 0x8018F29C: add.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x8018F2A0: swc1        $f6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f6.u32l;
    // 0x8018F2A4: addiu       $at, $zero, 0x15
    ctx->r1 = ADD32(0, 0X15);
L_8018F2A8:
    // 0x8018F2A8: bne         $a0, $at, L_8018F420
    if (ctx->r4 != ctx->r1) {
        // 0x8018F2AC: lui         $at, 0xC0A0
        ctx->r1 = S32(0XC0A0 << 16);
            goto L_8018F420;
    }
    // 0x8018F2AC: lui         $at, 0xC0A0
    ctx->r1 = S32(0XC0A0 << 16);
    // 0x8018F2B0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018F2B4: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8018F2B8: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8018F2BC: b           L_8018F420
    // 0x8018F2C0: swc1        $f4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f4.u32l;
        goto L_8018F420;
    // 0x8018F2C0: swc1        $f4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f4.u32l;
L_8018F2C4:
    // 0x8018F2C4: bne         $a0, $v0, L_8018F2E8
    if (ctx->r4 != ctx->r2) {
        // 0x8018F2C8: addiu       $at, $zero, 0x13
        ctx->r1 = ADD32(0, 0X13);
            goto L_8018F2E8;
    }
    // 0x8018F2C8: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x8018F2CC: multu       $v1, $t1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8018F2D0: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8018F2D4: mflo        $t4
    ctx->r12 = lo;
    // 0x8018F2D8: addu        $t5, $t0, $t4
    ctx->r13 = ADD32(ctx->r8, ctx->r12);
    // 0x8018F2DC: lwc1        $f6, 0x18($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0X18);
    // 0x8018F2E0: add.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x8018F2E4: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
L_8018F2E8:
    // 0x8018F2E8: bnel        $a0, $at, L_8018F320
    if (ctx->r4 != ctx->r1) {
        // 0x8018F2EC: addiu       $at, $zero, 0x14
        ctx->r1 = ADD32(0, 0X14);
            goto L_8018F320;
    }
    goto skip_14;
    // 0x8018F2EC: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    skip_14:
    // 0x8018F2F0: multu       $v1, $t1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8018F2F4: lwc1        $f10, 0x0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8018F2F8: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8018F2FC: mflo        $t6
    ctx->r14 = lo;
    // 0x8018F300: addu        $v0, $t0, $t6
    ctx->r2 = ADD32(ctx->r8, ctx->r14);
    // 0x8018F304: lwc1        $f4, 0x30($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X30);
    // 0x8018F308: add.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8018F30C: swc1        $f18, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f18.u32l;
    // 0x8018F310: lwc1        $f8, 0x34($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X34);
    // 0x8018F314: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8018F318: swc1        $f10, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f10.u32l;
    // 0x8018F31C: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
L_8018F320:
    // 0x8018F320: bnel        $a0, $at, L_8018F358
    if (ctx->r4 != ctx->r1) {
        // 0x8018F324: addiu       $at, $zero, 0x15
        ctx->r1 = ADD32(0, 0X15);
            goto L_8018F358;
    }
    goto skip_15;
    // 0x8018F324: addiu       $at, $zero, 0x15
    ctx->r1 = ADD32(0, 0X15);
    skip_15:
    // 0x8018F328: multu       $v1, $t1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8018F32C: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8018F330: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8018F334: mflo        $t7
    ctx->r15 = lo;
    // 0x8018F338: addu        $v0, $t0, $t7
    ctx->r2 = ADD32(ctx->r8, ctx->r15);
    // 0x8018F33C: lwc1        $f18, 0x40($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X40);
    // 0x8018F340: add.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x8018F344: swc1        $f6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f6.u32l;
    // 0x8018F348: lwc1        $f10, 0x44($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X44);
    // 0x8018F34C: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8018F350: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x8018F354: addiu       $at, $zero, 0x15
    ctx->r1 = ADD32(0, 0X15);
L_8018F358:
    // 0x8018F358: bne         $a0, $at, L_8018F420
    if (ctx->r4 != ctx->r1) {
        // 0x8018F35C: lui         $at, 0x4120
        ctx->r1 = S32(0X4120 << 16);
            goto L_8018F420;
    }
    // 0x8018F35C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8018F360: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018F364: lwc1        $f18, 0x0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8018F368: add.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x8018F36C: b           L_8018F420
    // 0x8018F370: swc1        $f8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f8.u32l;
        goto L_8018F420;
    // 0x8018F370: swc1        $f8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f8.u32l;
L_8018F374:
    // 0x8018F374: bne         $a0, $v0, L_8018F398
    if (ctx->r4 != ctx->r2) {
        // 0x8018F378: addiu       $at, $zero, 0x11
        ctx->r1 = ADD32(0, 0X11);
            goto L_8018F398;
    }
    // 0x8018F378: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x8018F37C: multu       $v1, $t1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8018F380: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8018F384: mflo        $t8
    ctx->r24 = lo;
    // 0x8018F388: addu        $t9, $t0, $t8
    ctx->r25 = ADD32(ctx->r8, ctx->r24);
    // 0x8018F38C: lwc1        $f4, 0x18($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X18);
    // 0x8018F390: add.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8018F394: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
L_8018F398:
    // 0x8018F398: bnel        $a0, $at, L_8018F3D0
    if (ctx->r4 != ctx->r1) {
        // 0x8018F39C: addiu       $at, $zero, 0x12
        ctx->r1 = ADD32(0, 0X12);
            goto L_8018F3D0;
    }
    goto skip_16;
    // 0x8018F39C: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    skip_16:
    // 0x8018F3A0: multu       $v1, $t1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8018F3A4: lwc1        $f6, 0x0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8018F3A8: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8018F3AC: mflo        $t2
    ctx->r10 = lo;
    // 0x8018F3B0: addu        $v0, $t0, $t2
    ctx->r2 = ADD32(ctx->r8, ctx->r10);
    // 0x8018F3B4: lwc1        $f8, 0x30($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X30);
    // 0x8018F3B8: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8018F3BC: swc1        $f10, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f10.u32l;
    // 0x8018F3C0: lwc1        $f18, 0x34($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X34);
    // 0x8018F3C4: add.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x8018F3C8: swc1        $f6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f6.u32l;
    // 0x8018F3CC: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
L_8018F3D0:
    // 0x8018F3D0: bnel        $a0, $at, L_8018F408
    if (ctx->r4 != ctx->r1) {
        // 0x8018F3D4: addiu       $at, $zero, 0x13
        ctx->r1 = ADD32(0, 0X13);
            goto L_8018F408;
    }
    goto skip_17;
    // 0x8018F3D4: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    skip_17:
    // 0x8018F3D8: multu       $v1, $t1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8018F3DC: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8018F3E0: lwc1        $f18, 0x4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8018F3E4: mflo        $t3
    ctx->r11 = lo;
    // 0x8018F3E8: addu        $v0, $t0, $t3
    ctx->r2 = ADD32(ctx->r8, ctx->r11);
    // 0x8018F3EC: lwc1        $f10, 0x40($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X40);
    // 0x8018F3F0: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8018F3F4: swc1        $f4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f4.u32l;
    // 0x8018F3F8: lwc1        $f6, 0x44($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X44);
    // 0x8018F3FC: add.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x8018F400: swc1        $f8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f8.u32l;
    // 0x8018F404: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
L_8018F408:
    // 0x8018F408: bne         $a0, $at, L_8018F420
    if (ctx->r4 != ctx->r1) {
        // 0x8018F40C: lui         $at, 0x4080
        ctx->r1 = S32(0X4080 << 16);
            goto L_8018F420;
    }
    // 0x8018F40C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8018F410: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018F414: lwc1        $f10, 0x0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8018F418: add.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8018F41C: swc1        $f18, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f18.u32l;
L_8018F420:
    // 0x8018F420: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8018F424:
    // 0x8018F424: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8018F428: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8018F42C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8018F430: jr          $ra
    // 0x8018F434: nop

    return;
    // 0x8018F434: nop

;}
RECOMP_FUNC void Option_Input_Sound_X(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019C66C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8019C670: mtc1        $a1, $f14
    ctx->f14.u32l = ctx->r5;
    // 0x8019C674: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x8019C678: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8019C67C: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x8019C680: lw          $t6, 0x7AF8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7AF8);
    // 0x8019C684: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8019C688: addiu       $t8, $t8, -0x2768
    ctx->r24 = ADD32(ctx->r24, -0X2768);
    // 0x8019C68C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8019C690: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8019C694: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x8019C698: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x8019C69C: lb          $a1, 0x3($v0)
    ctx->r5 = MEM_B(ctx->r2, 0X3);
    // 0x8019C6A0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8019C6A4: lwc1        $f16, 0x0($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8019C6A8: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
    // 0x8019C6AC: slti        $at, $a1, 0xB
    ctx->r1 = SIGNED(ctx->r5) < 0XB ? 1 : 0;
    // 0x8019C6B0: beq         $at, $zero, L_8019C6C4
    if (ctx->r1 == 0) {
        // 0x8019C6B4: lb          $v1, 0x2($v0)
        ctx->r3 = MEM_B(ctx->r2, 0X2);
            goto L_8019C6C4;
    }
    // 0x8019C6B4: lb          $v1, 0x2($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X2);
    // 0x8019C6B8: slti        $at, $a1, -0xA
    ctx->r1 = SIGNED(ctx->r5) < -0XA ? 1 : 0;
    // 0x8019C6BC: beql        $at, $zero, L_8019C6D0
    if (ctx->r1 == 0) {
        // 0x8019C6C0: slti        $at, $v1, 0xA
        ctx->r1 = SIGNED(ctx->r3) < 0XA ? 1 : 0;
            goto L_8019C6D0;
    }
    goto skip_0;
    // 0x8019C6C0: slti        $at, $v1, 0xA
    ctx->r1 = SIGNED(ctx->r3) < 0XA ? 1 : 0;
    skip_0:
L_8019C6C4:
    // 0x8019C6C4: b           L_8019C814
    // 0x8019C6C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8019C814;
    // 0x8019C6C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8019C6CC: slti        $at, $v1, 0xA
    ctx->r1 = SIGNED(ctx->r3) < 0XA ? 1 : 0;
L_8019C6D0:
    // 0x8019C6D0: beq         $at, $zero, L_8019C6EC
    if (ctx->r1 == 0) {
        // 0x8019C6D4: lui         $a1, 0x800C
        ctx->r5 = S32(0X800C << 16);
            goto L_8019C6EC;
    }
    // 0x8019C6D4: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x8019C6D8: slti        $at, $v1, -0x9
    ctx->r1 = SIGNED(ctx->r3) < -0X9 ? 1 : 0;
    // 0x8019C6DC: bne         $at, $zero, L_8019C6EC
    if (ctx->r1 != 0) {
        // 0x8019C6E0: nop
    
            goto L_8019C6EC;
    }
    // 0x8019C6E0: nop

    // 0x8019C6E4: b           L_8019C700
    // 0x8019C6E8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_8019C700;
    // 0x8019C6E8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8019C6EC:
    // 0x8019C6EC: bgezl       $v1, L_8019C700
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8019C6F0: addiu       $v1, $v1, -0xA
        ctx->r3 = ADD32(ctx->r3, -0XA);
            goto L_8019C700;
    }
    goto skip_1;
    // 0x8019C6F0: addiu       $v1, $v1, -0xA
    ctx->r3 = ADD32(ctx->r3, -0XA);
    skip_1:
    // 0x8019C6F4: b           L_8019C700
    // 0x8019C6F8: addiu       $v1, $v1, 0xA
    ctx->r3 = ADD32(ctx->r3, 0XA);
        goto L_8019C700;
    // 0x8019C6F8: addiu       $v1, $v1, 0xA
    ctx->r3 = ADD32(ctx->r3, 0XA);
    // 0x8019C6FC: addiu       $v1, $v1, -0xA
    ctx->r3 = ADD32(ctx->r3, -0XA);
L_8019C700:
    // 0x8019C700: lw          $v0, 0x4($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X4);
    // 0x8019C704: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x8019C708: addiu       $t7, $t7, 0x5D3C
    ctx->r15 = ADD32(ctx->r15, 0X5D3C);
    // 0x8019C70C: bne         $v0, $zero, L_8019C7C0
    if (ctx->r2 != 0) {
        // 0x8019C710: addiu       $a1, $a1, 0x5D28
        ctx->r5 = ADD32(ctx->r5, 0X5D28);
            goto L_8019C7C0;
    }
    // 0x8019C710: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x8019C714: beq         $v1, $zero, L_8019C7B4
    if (ctx->r3 == 0) {
        // 0x8019C718: addiu       $t1, $zero, 0x7
        ctx->r9 = ADD32(0, 0X7);
            goto L_8019C7B4;
    }
    // 0x8019C718: addiu       $t1, $zero, 0x7
    ctx->r9 = ADD32(0, 0X7);
    // 0x8019C71C: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x8019C720: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x8019C724: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8019C728: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8019C72C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8019C730: sw          $v0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r2;
    // 0x8019C734: addiu       $t9, $v0, -0x7
    ctx->r25 = ADD32(ctx->r2, -0X7);
    // 0x8019C738: beq         $v0, $zero, L_8019C744
    if (ctx->r2 == 0) {
        // 0x8019C73C: div.s       $f2, $f6, $f8
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
            goto L_8019C744;
    }
    // 0x8019C73C: div.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8019C740: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
L_8019C744:
    // 0x8019C744: lw          $t0, 0x4($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X4);
    // 0x8019C748: beql        $t0, $zero, L_8019C774
    if (ctx->r8 == 0) {
        // 0x8019C74C: lwc1        $f10, 0x0($a0)
        ctx->f10.u32l = MEM_W(ctx->r4, 0X0);
            goto L_8019C774;
    }
    goto skip_2;
    // 0x8019C74C: lwc1        $f10, 0x0($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X0);
    skip_2:
    // 0x8019C750: blez        $v1, L_8019C768
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8019C754: lui         $at, 0xBF80
        ctx->r1 = S32(0XBF80 << 16);
            goto L_8019C768;
    }
    // 0x8019C754: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8019C758: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8019C75C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8019C760: b           L_8019C774
    // 0x8019C764: lwc1        $f10, 0x0($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X0);
        goto L_8019C774;
    // 0x8019C764: lwc1        $f10, 0x0($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X0);
L_8019C768:
    // 0x8019C768: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8019C76C: nop

    // 0x8019C770: lwc1        $f10, 0x0($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X0);
L_8019C774:
    // 0x8019C774: add.s       $f18, $f10, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x8019C778: swc1        $f18, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f18.u32l;
    // 0x8019C77C: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8019C780: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x8019C784: nop

    // 0x8019C788: bc1fl       L_8019C79C
    if (!c1cs) {
        // 0x8019C78C: c.lt.s      $f0, $f14
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
            goto L_8019C79C;
    }
    goto skip_3;
    // 0x8019C78C: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    skip_3:
    // 0x8019C790: swc1        $f12, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f12.u32l;
    // 0x8019C794: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8019C798: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
L_8019C79C:
    // 0x8019C79C: nop

    // 0x8019C7A0: bc1f        L_8019C7AC
    if (!c1cs) {
        // 0x8019C7A4: nop
    
            goto L_8019C7AC;
    }
    // 0x8019C7A4: nop

    // 0x8019C7A8: swc1        $f14, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f14.u32l;
L_8019C7AC:
    // 0x8019C7AC: b           L_8019C7C0
    // 0x8019C7B0: lw          $v0, 0x4($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X4);
        goto L_8019C7C0;
    // 0x8019C7B0: lw          $v0, 0x4($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X4);
L_8019C7B4:
    // 0x8019C7B4: sw          $zero, 0x4($a3)
    MEM_W(0X4, ctx->r7) = 0;
    // 0x8019C7B8: sw          $t1, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r9;
    // 0x8019C7BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8019C7C0:
    // 0x8019C7C0: blez        $v0, L_8019C7D0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8019C7C4: trunc.w.s   $f4, $f16
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.u32l = TRUNC_W_S(ctx->f16.fl);
            goto L_8019C7D0;
    }
    // 0x8019C7C4: trunc.w.s   $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8019C7C8: addiu       $t2, $v0, -0x1
    ctx->r10 = ADD32(ctx->r2, -0X1);
    // 0x8019C7CC: sw          $t2, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r10;
L_8019C7D0:
    // 0x8019C7D0: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8019C7D4: mfc1        $t4, $f4
    ctx->r12 = (int32_t)ctx->f4.u32l;
    // 0x8019C7D8: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8019C7DC: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8019C7E0: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x8019C7E4: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8019C7E8: ori         $a0, $a0, 0x4007
    ctx->r4 = ctx->r4 | 0X4007;
    // 0x8019C7EC: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x8019C7F0: nop

    // 0x8019C7F4: beql        $t4, $t6, L_8019C814
    if (ctx->r12 == ctx->r14) {
        // 0x8019C7F8: or          $v0, $a2, $zero
        ctx->r2 = ctx->r6 | 0;
            goto L_8019C814;
    }
    goto skip_4;
    // 0x8019C7F8: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    skip_4:
    // 0x8019C7FC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8019C800: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8019C804: jal         0x80019218
    // 0x8019C808: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    Audio_PlaySfx(rdram, ctx);
        goto after_0;
    // 0x8019C808: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_0:
    // 0x8019C80C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8019C810: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
L_8019C814:
    // 0x8019C814: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8019C818: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8019C81C: jr          $ra
    // 0x8019C820: nop

    return;
    // 0x8019C820: nop

;}
RECOMP_FUNC void Title_Sun_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80190144: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80190148: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x8019014C: addiu       $v1, $v1, -0x7CC0
    ctx->r3 = ADD32(ctx->r3, -0X7CC0);
    // 0x80190150: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80190154: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x80190158: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x8019015C: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x80190160: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x80190164: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x80190168: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8019016C: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80190170: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80190174: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80190178: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8019017C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80190180: lui         $s1, 0x8018
    ctx->r17 = S32(0X8018 << 16);
    // 0x80190184: addiu       $s1, $s1, -0x7C30
    ctx->r17 = ADD32(ctx->r17, -0X7C30);
    // 0x80190188: blez        $v0, L_8019019C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8019018C: lui         $s2, 0x8018
        ctx->r18 = S32(0X8018 << 16);
            goto L_8019019C;
    }
    // 0x8019018C: lui         $s2, 0x8018
    ctx->r18 = S32(0X8018 << 16);
    // 0x80190190: addiu       $t6, $v0, -0x4
    ctx->r14 = ADD32(ctx->r2, -0X4);
    // 0x80190194: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80190198: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
L_8019019C:
    // 0x8019019C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801901A0: lwc1        $f4, 0x7BB8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7BB8);
    // 0x801901A4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801901A8: addiu       $s2, $s2, -0x7C2C
    ctx->r18 = ADD32(ctx->r18, -0X7C2C);
    // 0x801901AC: swc1        $f4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f4.u32l;
    // 0x801901B0: lwc1        $f6, 0x7BBC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7BBC);
    // 0x801901B4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801901B8: lwc1        $f0, 0x0($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X0);
    // 0x801901BC: swc1        $f6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f6.u32l;
    // 0x801901C0: lwc1        $f8, 0x70C0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X70C0);
    // 0x801901C4: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x801901C8: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x801901CC: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x801901D0: lui         $at, 0xC461
    ctx->r1 = S32(0XC461 << 16);
    // 0x801901D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801901D8: bc1f        L_8019022C
    if (!c1cs) {
        // 0x801901DC: nop
    
            goto L_8019022C;
    }
    // 0x801901DC: nop

    // 0x801901E0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801901E4: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801901E8: slti        $at, $t7, 0x3D
    ctx->r1 = SIGNED(ctx->r15) < 0X3D ? 1 : 0;
    // 0x801901EC: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x801901F0: nop

    // 0x801901F4: bc1f        L_8019022C
    if (!c1cs) {
        // 0x801901F8: nop
    
            goto L_8019022C;
    }
    // 0x801901F8: nop

    // 0x801901FC: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80190200: bne         $at, $zero, L_80190210
    if (ctx->r1 != 0) {
        // 0x80190204: or          $v0, $t7, $zero
        ctx->r2 = ctx->r15 | 0;
            goto L_80190210;
    }
    // 0x80190204: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80190208: addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
    // 0x8019020C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_80190210:
    // 0x80190210: addiu       $v1, $zero, 0xD0
    ctx->r3 = ADD32(0, 0XD0);
    // 0x80190214: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80190218: sw          $v1, -0x7CB8($at)
    MEM_W(-0X7CB8, ctx->r1) = ctx->r3;
    // 0x8019021C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80190220: sw          $v1, -0x7CB0($at)
    MEM_W(-0X7CB0, ctx->r1) = ctx->r3;
    // 0x80190224: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80190228: sw          $v1, -0x7CAC($at)
    MEM_W(-0X7CAC, ctx->r1) = ctx->r3;
L_8019022C:
    // 0x8019022C: blezl       $v0, L_80190388
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80190230: lw          $ra, 0x4C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X4C);
            goto L_80190388;
    }
    goto skip_0;
    // 0x80190230: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    skip_0:
    // 0x80190234: jal         0x800B8DD0
    // 0x80190238: addiu       $a1, $zero, 0x3E
    ctx->r5 = ADD32(0, 0X3E);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x80190238: addiu       $a1, $zero, 0x3E
    ctx->r5 = ADD32(0, 0X3E);
    after_0:
    // 0x8019023C: lui         $s5, 0x8014
    ctx->r21 = S32(0X8014 << 16);
    // 0x80190240: addiu       $s5, $s5, -0x4C40
    ctx->r21 = ADD32(ctx->r21, -0X4C40);
    // 0x80190244: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80190248: lui         $t0, 0xBA00
    ctx->r8 = S32(0XBA00 << 16);
    // 0x8019024C: ori         $t0, $t0, 0x402
    ctx->r8 = ctx->r8 | 0X402;
    // 0x80190250: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80190254: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80190258: addiu       $t1, $zero, 0x20
    ctx->r9 = ADD32(0, 0X20);
    // 0x8019025C: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x80190260: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x80190264: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80190268: lui         $t3, 0xBA00
    ctx->r11 = S32(0XBA00 << 16);
    // 0x8019026C: ori         $t3, $t3, 0x602
    ctx->r11 = ctx->r11 | 0X602;
    // 0x80190270: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x80190274: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x80190278: addiu       $t4, $zero, 0x80
    ctx->r12 = ADD32(0, 0X80);
    // 0x8019027C: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80190280: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80190284: jal         0x80005708
    // 0x80190288: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    Matrix_Push(rdram, ctx);
        goto after_1;
    // 0x80190288: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_1:
    // 0x8019028C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80190290: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80190294: lw          $a0, 0x0($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X0);
    // 0x80190298: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x8019029C: lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X0);
    // 0x801902A0: jal         0x80005B00
    // 0x801902A4: lui         $a3, 0xC348
    ctx->r7 = S32(0XC348 << 16);
    Matrix_Translate(rdram, ctx);
        goto after_2;
    // 0x801902A4: lui         $a3, 0xC348
    ctx->r7 = S32(0XC348 << 16);
    after_2:
    // 0x801902A8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801902AC: lui         $s2, 0x801B
    ctx->r18 = S32(0X801B << 16);
    // 0x801902B0: lui         $s3, 0x801B
    ctx->r19 = S32(0X801B << 16);
    // 0x801902B4: lui         $s4, 0x801B
    ctx->r20 = S32(0X801B << 16);
    // 0x801902B8: lui         $s1, 0x801B
    ctx->r17 = S32(0X801B << 16);
    // 0x801902BC: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x801902C0: addiu       $s1, $s1, -0x1B74
    ctx->r17 = ADD32(ctx->r17, -0X1B74);
    // 0x801902C4: addiu       $s4, $s4, -0x1AE4
    ctx->r20 = ADD32(ctx->r20, -0X1AE4);
    // 0x801902C8: addiu       $s3, $s3, -0x1AD8
    ctx->r19 = ADD32(ctx->r19, -0X1AD8);
    // 0x801902CC: addiu       $s2, $s2, -0x1B14
    ctx->r18 = ADD32(ctx->r18, -0X1B14);
    // 0x801902D0: lui         $fp, 0x600
    ctx->r30 = S32(0X600 << 16);
    // 0x801902D4: lui         $s7, 0xFFFF
    ctx->r23 = S32(0XFFFF << 16);
    // 0x801902D8: lui         $s6, 0xFA00
    ctx->r22 = S32(0XFA00 << 16);
L_801902DC:
    // 0x801902DC: jal         0x80005708
    // 0x801902E0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    Matrix_Push(rdram, ctx);
        goto after_3;
    // 0x801902E0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_3:
    // 0x801902E4: lwc1        $f16, 0x0($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X0);
    // 0x801902E8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801902EC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801902F0: mul.s       $f0, $f16, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f16.fl, ctx->f20.fl);
    // 0x801902F4: lw          $a0, 0x0($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X0);
    // 0x801902F8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801902FC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80190300: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80190304: jal         0x80005C34
    // 0x80190308: nop

    Matrix_Scale(rdram, ctx);
        goto after_4;
    // 0x80190308: nop

    after_4:
    // 0x8019030C: jal         0x80006EB8
    // 0x80190310: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_5;
    // 0x80190310: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80190314: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80190318: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8019031C: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80190320: sw          $s6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r22;
    // 0x80190324: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    // 0x80190328: lbu         $t2, 0x0($s4)
    ctx->r10 = MEM_BU(ctx->r20, 0X0);
    // 0x8019032C: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x80190330: or          $t0, $t9, $s7
    ctx->r8 = ctx->r25 | ctx->r23;
    // 0x80190334: sll         $t3, $t2, 8
    ctx->r11 = S32(ctx->r10 << 8);
    // 0x80190338: or          $t4, $t0, $t3
    ctx->r12 = ctx->r8 | ctx->r11;
    // 0x8019033C: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80190340: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80190344: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x80190348: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x8019034C: sw          $fp, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r30;
    // 0x80190350: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x80190354: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80190358: jal         0x80005740
    // 0x8019035C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_6;
    // 0x8019035C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_6:
    // 0x80190360: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x80190364: addiu       $t7, $t7, -0x1B64
    ctx->r15 = ADD32(ctx->r15, -0X1B64);
    // 0x80190368: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8019036C: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80190370: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x80190374: bne         $s1, $t7, L_801902DC
    if (ctx->r17 != ctx->r15) {
        // 0x80190378: addiu       $s4, $s4, 0x1
        ctx->r20 = ADD32(ctx->r20, 0X1);
            goto L_801902DC;
    }
    // 0x80190378: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x8019037C: jal         0x80005740
    // 0x80190380: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_7;
    // 0x80190380: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_7:
    // 0x80190384: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_80190388:
    // 0x80190388: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8019038C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80190390: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80190394: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80190398: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x8019039C: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x801903A0: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x801903A4: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x801903A8: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x801903AC: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x801903B0: jr          $ra
    // 0x801903B4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x801903B4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void Option_MainMenu_Setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801929F0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x801929F4: sw          $zero, 0x2870($at)
    MEM_W(0X2870, ctx->r1) = 0;
    // 0x801929F8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x801929FC: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80192A00: sb          $t6, 0x1A38($at)
    MEM_B(0X1A38, ctx->r1) = ctx->r14;
    // 0x80192A04: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80192A08: sw          $zero, -0x274C($at)
    MEM_W(-0X274C, ctx->r1) = 0;
    // 0x80192A0C: lui         $t8, 0x801C
    ctx->r24 = S32(0X801C << 16);
    // 0x80192A10: lw          $t8, -0x6DBC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X6DBC);
    // 0x80192A14: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80192A18: addiu       $t7, $zero, 0x320
    ctx->r15 = ADD32(0, 0X320);
    // 0x80192A1C: sw          $t7, -0x7BF0($at)
    MEM_W(-0X7BF0, ctx->r1) = ctx->r15;
    // 0x80192A20: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80192A24: bne         $t8, $zero, L_80192C24
    if (ctx->r24 != 0) {
        // 0x80192A28: sw          $zero, -0x6DB8($at)
        MEM_W(-0X6DB8, ctx->r1) = 0;
            goto L_80192C24;
    }
    // 0x80192A28: sw          $zero, -0x6DB8($at)
    MEM_W(-0X6DB8, ctx->r1) = 0;
    // 0x80192A2C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80192A30: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80192A34: sw          $t0, -0x6E44($at)
    MEM_W(-0X6E44, ctx->r1) = ctx->r8;
    // 0x80192A38: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80192A3C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80192A40: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80192A44: lwc1        $f2, 0x7328($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X7328);
    // 0x80192A48: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80192A4C: lwc1        $f14, 0x732C($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X732C);
    // 0x80192A50: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80192A54: lwc1        $f4, -0x1A48($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X1A48);
    // 0x80192A58: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80192A5C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80192A60: swc1        $f4, -0x19B0($at)
    MEM_W(-0X19B0, ctx->r1) = ctx->f4.u32l;
    // 0x80192A64: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80192A68: lwc1        $f6, -0x1A30($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X1A30);
    // 0x80192A6C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80192A70: swc1        $f0, -0x19A8($at)
    MEM_W(-0X19A8, ctx->r1) = ctx->f0.u32l;
    // 0x80192A74: swc1        $f0, -0x19A4($at)
    MEM_W(-0X19A4, ctx->r1) = ctx->f0.u32l;
    // 0x80192A78: swc1        $f6, -0x19AC($at)
    MEM_W(-0X19AC, ctx->r1) = ctx->f6.u32l;
    // 0x80192A7C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80192A80: sw          $t0, -0x1970($at)
    MEM_W(-0X1970, ctx->r1) = ctx->r8;
    // 0x80192A84: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80192A88: swc1        $f14, -0x1984($at)
    MEM_W(-0X1984, ctx->r1) = ctx->f14.u32l;
    // 0x80192A8C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80192A90: swc1        $f2, -0x1980($at)
    MEM_W(-0X1980, ctx->r1) = ctx->f2.u32l;
    // 0x80192A94: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80192A98: lwc1        $f8, -0x1A90($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X1A90);
    // 0x80192A9C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80192AA0: swc1        $f12, -0x1988($at)
    MEM_W(-0X1988, ctx->r1) = ctx->f12.u32l;
    // 0x80192AA4: swc1        $f8, -0x198C($at)
    MEM_W(-0X198C, ctx->r1) = ctx->f8.u32l;
    // 0x80192AA8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80192AAC: sw          $t0, -0x196C($at)
    MEM_W(-0X196C, ctx->r1) = ctx->r8;
    // 0x80192AB0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80192AB4: lwc1        $f10, -0x1A44($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X1A44);
    // 0x80192AB8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80192ABC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80192AC0: swc1        $f10, -0x1950($at)
    MEM_W(-0X1950, ctx->r1) = ctx->f10.u32l;
    // 0x80192AC4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80192AC8: lwc1        $f16, -0x1A2C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X1A2C);
    // 0x80192ACC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80192AD0: swc1        $f0, -0x1948($at)
    MEM_W(-0X1948, ctx->r1) = ctx->f0.u32l;
    // 0x80192AD4: swc1        $f0, -0x1944($at)
    MEM_W(-0X1944, ctx->r1) = ctx->f0.u32l;
    // 0x80192AD8: swc1        $f16, -0x194C($at)
    MEM_W(-0X194C, ctx->r1) = ctx->f16.u32l;
    // 0x80192ADC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80192AE0: sw          $t0, -0x1910($at)
    MEM_W(-0X1910, ctx->r1) = ctx->r8;
    // 0x80192AE4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80192AE8: swc1        $f14, -0x1924($at)
    MEM_W(-0X1924, ctx->r1) = ctx->f14.u32l;
    // 0x80192AEC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80192AF0: swc1        $f2, -0x1920($at)
    MEM_W(-0X1920, ctx->r1) = ctx->f2.u32l;
    // 0x80192AF4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80192AF8: lwc1        $f18, -0x1A8C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X1A8C);
    // 0x80192AFC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80192B00: swc1        $f12, -0x1928($at)
    MEM_W(-0X1928, ctx->r1) = ctx->f12.u32l;
    // 0x80192B04: swc1        $f18, -0x192C($at)
    MEM_W(-0X192C, ctx->r1) = ctx->f18.u32l;
    // 0x80192B08: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80192B0C: sw          $t0, -0x190C($at)
    MEM_W(-0X190C, ctx->r1) = ctx->r8;
    // 0x80192B10: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x80192B14: subu        $t9, $t9, $v0
    ctx->r25 = SUB32(ctx->r25, ctx->r2);
    // 0x80192B18: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x80192B1C: addiu       $t1, $t1, -0x19C8
    ctx->r9 = ADD32(ctx->r9, -0X19C8);
    // 0x80192B20: sll         $t9, $t9, 5
    ctx->r25 = S32(ctx->r25 << 5);
    // 0x80192B24: addu        $v1, $t9, $t1
    ctx->r3 = ADD32(ctx->r25, ctx->r9);
    // 0x80192B28: sll         $a0, $v0, 2
    ctx->r4 = S32(ctx->r2 << 2);
    // 0x80192B2C: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x80192B30: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x80192B34: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x80192B38: addiu       $t2, $t2, -0x1A48
    ctx->r10 = ADD32(ctx->r10, -0X1A48);
    // 0x80192B3C: addiu       $t3, $t3, -0x1A30
    ctx->r11 = ADD32(ctx->r11, -0X1A30);
    // 0x80192B40: addiu       $t4, $t4, -0x1A90
    ctx->r12 = ADD32(ctx->r12, -0X1A90);
    // 0x80192B44: addu        $a1, $a0, $t2
    ctx->r5 = ADD32(ctx->r4, ctx->r10);
    // 0x80192B48: addu        $a2, $a0, $t3
    ctx->r6 = ADD32(ctx->r4, ctx->r11);
    // 0x80192B4C: addu        $a3, $a0, $t4
    ctx->r7 = ADD32(ctx->r4, ctx->r12);
    // 0x80192B50: lwc1        $f18, 0x4($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X4);
    // 0x80192B54: lwc1        $f16, 0x4($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X4);
    // 0x80192B58: lwc1        $f10, 0x4($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80192B5C: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80192B60: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80192B64: lwc1        $f8, 0x0($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X0);
    // 0x80192B68: swc1        $f18, 0x9C($v1)
    MEM_W(0X9C, ctx->r3) = ctx->f18.u32l;
    // 0x80192B6C: swc1        $f16, 0x7C($v1)
    MEM_W(0X7C, ctx->r3) = ctx->f16.u32l;
    // 0x80192B70: swc1        $f10, 0x78($v1)
    MEM_W(0X78, ctx->r3) = ctx->f10.u32l;
    // 0x80192B74: swc1        $f4, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f4.u32l;
    // 0x80192B78: swc1        $f6, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f6.u32l;
    // 0x80192B7C: swc1        $f8, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f8.u32l;
    // 0x80192B80: lwc1        $f8, 0x8($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X8);
    // 0x80192B84: lwc1        $f6, 0x8($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X8);
    // 0x80192B88: lwc1        $f4, 0x8($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80192B8C: lwc1        $f10, 0xC($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0XC);
    // 0x80192B90: lwc1        $f16, 0xC($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0XC);
    // 0x80192B94: lwc1        $f18, 0xC($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0XC);
    // 0x80192B98: sw          $t0, 0xB8($v1)
    MEM_W(0XB8, ctx->r3) = ctx->r8;
    // 0x80192B9C: sw          $t0, 0xBC($v1)
    MEM_W(0XBC, ctx->r3) = ctx->r8;
    // 0x80192BA0: sw          $t0, 0x118($v1)
    MEM_W(0X118, ctx->r3) = ctx->r8;
    // 0x80192BA4: sw          $t0, 0x11C($v1)
    MEM_W(0X11C, ctx->r3) = ctx->r8;
    // 0x80192BA8: sw          $t0, 0x178($v1)
    MEM_W(0X178, ctx->r3) = ctx->r8;
    // 0x80192BAC: sw          $t0, 0x17C($v1)
    MEM_W(0X17C, ctx->r3) = ctx->r8;
    // 0x80192BB0: sw          $t0, 0x58($v1)
    MEM_W(0X58, ctx->r3) = ctx->r8;
    // 0x80192BB4: sw          $t0, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->r8;
    // 0x80192BB8: swc1        $f0, 0x80($v1)
    MEM_W(0X80, ctx->r3) = ctx->f0.u32l;
    // 0x80192BBC: swc1        $f0, 0x84($v1)
    MEM_W(0X84, ctx->r3) = ctx->f0.u32l;
    // 0x80192BC0: swc1        $f0, 0xE0($v1)
    MEM_W(0XE0, ctx->r3) = ctx->f0.u32l;
    // 0x80192BC4: swc1        $f0, 0xE4($v1)
    MEM_W(0XE4, ctx->r3) = ctx->f0.u32l;
    // 0x80192BC8: swc1        $f0, 0x140($v1)
    MEM_W(0X140, ctx->r3) = ctx->f0.u32l;
    // 0x80192BCC: swc1        $f0, 0x144($v1)
    MEM_W(0X144, ctx->r3) = ctx->f0.u32l;
    // 0x80192BD0: swc1        $f0, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f0.u32l;
    // 0x80192BD4: swc1        $f0, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->f0.u32l;
    // 0x80192BD8: swc1        $f2, 0xA8($v1)
    MEM_W(0XA8, ctx->r3) = ctx->f2.u32l;
    // 0x80192BDC: swc1        $f2, 0x108($v1)
    MEM_W(0X108, ctx->r3) = ctx->f2.u32l;
    // 0x80192BE0: swc1        $f2, 0x168($v1)
    MEM_W(0X168, ctx->r3) = ctx->f2.u32l;
    // 0x80192BE4: swc1        $f2, 0x48($v1)
    MEM_W(0X48, ctx->r3) = ctx->f2.u32l;
    // 0x80192BE8: swc1        $f14, 0xA4($v1)
    MEM_W(0XA4, ctx->r3) = ctx->f14.u32l;
    // 0x80192BEC: swc1        $f14, 0x104($v1)
    MEM_W(0X104, ctx->r3) = ctx->f14.u32l;
    // 0x80192BF0: swc1        $f14, 0x164($v1)
    MEM_W(0X164, ctx->r3) = ctx->f14.u32l;
    // 0x80192BF4: swc1        $f14, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->f14.u32l;
    // 0x80192BF8: swc1        $f12, 0xA0($v1)
    MEM_W(0XA0, ctx->r3) = ctx->f12.u32l;
    // 0x80192BFC: swc1        $f12, 0x100($v1)
    MEM_W(0X100, ctx->r3) = ctx->f12.u32l;
    // 0x80192C00: swc1        $f12, 0x160($v1)
    MEM_W(0X160, ctx->r3) = ctx->f12.u32l;
    // 0x80192C04: swc1        $f12, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f12.u32l;
    // 0x80192C08: swc1        $f8, 0xFC($v1)
    MEM_W(0XFC, ctx->r3) = ctx->f8.u32l;
    // 0x80192C0C: swc1        $f6, 0xDC($v1)
    MEM_W(0XDC, ctx->r3) = ctx->f6.u32l;
    // 0x80192C10: swc1        $f4, 0xD8($v1)
    MEM_W(0XD8, ctx->r3) = ctx->f4.u32l;
    // 0x80192C14: swc1        $f10, 0x138($v1)
    MEM_W(0X138, ctx->r3) = ctx->f10.u32l;
    // 0x80192C18: swc1        $f16, 0x13C($v1)
    MEM_W(0X13C, ctx->r3) = ctx->f16.u32l;
    // 0x80192C1C: b           L_80192D08
    // 0x80192C20: swc1        $f18, 0x15C($v1)
    MEM_W(0X15C, ctx->r3) = ctx->f18.u32l;
        goto L_80192D08;
    // 0x80192C20: swc1        $f18, 0x15C($v1)
    MEM_W(0X15C, ctx->r3) = ctx->f18.u32l;
L_80192C24:
    // 0x80192C24: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80192C28: sw          $zero, -0x6E44($at)
    MEM_W(-0X6E44, ctx->r1) = 0;
    // 0x80192C2C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80192C30: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80192C34: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80192C38: lwc1        $f2, 0x7330($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X7330);
    // 0x80192C3C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80192C40: swc1        $f0, -0x19A4($at)
    MEM_W(-0X19A4, ctx->r1) = ctx->f0.u32l;
    // 0x80192C44: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80192C48: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80192C4C: swc1        $f2, -0x1980($at)
    MEM_W(-0X1980, ctx->r1) = ctx->f2.u32l;
    // 0x80192C50: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80192C54: swc1        $f12, -0x1988($at)
    MEM_W(-0X1988, ctx->r1) = ctx->f12.u32l;
    // 0x80192C58: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80192C5C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80192C60: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80192C64: sw          $t6, -0x1970($at)
    MEM_W(-0X1970, ctx->r1) = ctx->r14;
    // 0x80192C68: sw          $t5, -0x196C($at)
    MEM_W(-0X196C, ctx->r1) = ctx->r13;
    // 0x80192C6C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80192C70: swc1        $f0, -0x1944($at)
    MEM_W(-0X1944, ctx->r1) = ctx->f0.u32l;
    // 0x80192C74: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80192C78: swc1        $f2, -0x1920($at)
    MEM_W(-0X1920, ctx->r1) = ctx->f2.u32l;
    // 0x80192C7C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80192C80: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80192C84: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x80192C88: swc1        $f12, -0x1928($at)
    MEM_W(-0X1928, ctx->r1) = ctx->f12.u32l;
    // 0x80192C8C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80192C90: subu        $t9, $t9, $v0
    ctx->r25 = SUB32(ctx->r25, ctx->r2);
    // 0x80192C94: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x80192C98: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80192C9C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80192CA0: addiu       $t1, $t1, -0x19C8
    ctx->r9 = ADD32(ctx->r9, -0X19C8);
    // 0x80192CA4: sll         $t9, $t9, 5
    ctx->r25 = S32(ctx->r25 << 5);
    // 0x80192CA8: sw          $t8, -0x1910($at)
    MEM_W(-0X1910, ctx->r1) = ctx->r24;
    // 0x80192CAC: sw          $t7, -0x190C($at)
    MEM_W(-0X190C, ctx->r1) = ctx->r15;
    // 0x80192CB0: addu        $v1, $t9, $t1
    ctx->r3 = ADD32(ctx->r25, ctx->r9);
    // 0x80192CB4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80192CB8: sw          $t0, 0xBC($v1)
    MEM_W(0XBC, ctx->r3) = ctx->r8;
    // 0x80192CBC: sw          $t0, 0xB8($v1)
    MEM_W(0XB8, ctx->r3) = ctx->r8;
    // 0x80192CC0: sw          $t0, 0x11C($v1)
    MEM_W(0X11C, ctx->r3) = ctx->r8;
    // 0x80192CC4: sw          $t0, 0x118($v1)
    MEM_W(0X118, ctx->r3) = ctx->r8;
    // 0x80192CC8: sw          $t0, 0x17C($v1)
    MEM_W(0X17C, ctx->r3) = ctx->r8;
    // 0x80192CCC: sw          $t0, 0x178($v1)
    MEM_W(0X178, ctx->r3) = ctx->r8;
    // 0x80192CD0: sw          $t0, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->r8;
    // 0x80192CD4: sw          $t0, 0x58($v1)
    MEM_W(0X58, ctx->r3) = ctx->r8;
    // 0x80192CD8: swc1        $f0, 0x84($v1)
    MEM_W(0X84, ctx->r3) = ctx->f0.u32l;
    // 0x80192CDC: swc1        $f0, 0xE4($v1)
    MEM_W(0XE4, ctx->r3) = ctx->f0.u32l;
    // 0x80192CE0: swc1        $f0, 0x144($v1)
    MEM_W(0X144, ctx->r3) = ctx->f0.u32l;
    // 0x80192CE4: swc1        $f0, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->f0.u32l;
    // 0x80192CE8: swc1        $f2, 0xA8($v1)
    MEM_W(0XA8, ctx->r3) = ctx->f2.u32l;
    // 0x80192CEC: swc1        $f2, 0x108($v1)
    MEM_W(0X108, ctx->r3) = ctx->f2.u32l;
    // 0x80192CF0: swc1        $f2, 0x168($v1)
    MEM_W(0X168, ctx->r3) = ctx->f2.u32l;
    // 0x80192CF4: swc1        $f2, 0x48($v1)
    MEM_W(0X48, ctx->r3) = ctx->f2.u32l;
    // 0x80192CF8: swc1        $f12, 0xA0($v1)
    MEM_W(0XA0, ctx->r3) = ctx->f12.u32l;
    // 0x80192CFC: swc1        $f12, 0x100($v1)
    MEM_W(0X100, ctx->r3) = ctx->f12.u32l;
    // 0x80192D00: swc1        $f12, 0x160($v1)
    MEM_W(0X160, ctx->r3) = ctx->f12.u32l;
    // 0x80192D04: swc1        $f12, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f12.u32l;
L_80192D08:
    // 0x80192D08: lui         $at, 0xC234
    ctx->r1 = S32(0XC234 << 16);
    // 0x80192D0C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80192D10: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80192D14: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80192D18: swc1        $f4, -0x6DFC($at)
    MEM_W(-0X6DFC, ctx->r1) = ctx->f4.u32l;
    // 0x80192D1C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80192D20: sw          $zero, -0x6DEC($at)
    MEM_W(-0X6DEC, ctx->r1) = 0;
    // 0x80192D24: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80192D28: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80192D2C: addiu       $a0, $a0, -0x6E68
    ctx->r4 = ADD32(ctx->r4, -0X6E68);
    // 0x80192D30: addiu       $v1, $v1, -0x6E70
    ctx->r3 = ADD32(ctx->r3, -0X6E70);
    // 0x80192D34: addiu       $v0, $v0, -0x6E80
    ctx->r2 = ADD32(ctx->r2, -0X6E80);
    // 0x80192D38: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x80192D3C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80192D40: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x80192D44: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80192D48: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x80192D4C: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x80192D50: jr          $ra
    // 0x80192D54: nop

    return;
    // 0x80192D54: nop

;}
RECOMP_FUNC void Option_RankingRoute_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80198164: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80198168: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8019816C: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x80198170: mtc1        $a1, $f22
    ctx->f22.u32l = ctx->r5;
    // 0x80198174: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80198178: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8019817C: sw          $s3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r19;
    // 0x80198180: sw          $s2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r18;
    // 0x80198184: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x80198188: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x8019818C: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x80198190: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80198194: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80198198: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x8019819C: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x801981A0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801981A4: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x801981A8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801981AC: lui         $s2, 0x8018
    ctx->r18 = S32(0X8018 << 16);
    // 0x801981B0: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x801981B4: addu        $s2, $s2, $s1
    ctx->r18 = ADD32(ctx->r18, ctx->r17);
    // 0x801981B8: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x801981BC: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x801981C0: lbu         $s2, -0x775A($s2)
    ctx->r18 = MEM_BU(ctx->r18, -0X775A);
    // 0x801981C4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801981C8: addiu       $s3, $zero, 0x7
    ctx->r19 = ADD32(0, 0X7);
    // 0x801981CC: add.s       $f26, $f4, $f6
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f26.fl = ctx->f4.fl + ctx->f6.fl;
L_801981D0:
    // 0x801981D0: add.s       $f20, $f28, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f20.fl = ctx->f28.fl + ctx->f24.fl;
    // 0x801981D4: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x801981D8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801981DC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x801981E0: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x801981E4: jal         0x801982B0
    // 0x801981E8: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    Option_RankingRouteFrame_Draw(rdram, ctx);
        goto after_0;
    // 0x801981E8: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    after_0:
    // 0x801981EC: slt         $at, $s0, $s2
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x801981F0: beq         $at, $zero, L_80198230
    if (ctx->r1 == 0) {
        // 0x801981F4: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80198230;
    }
    // 0x801981F4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801981F8: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x801981FC: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80198200: jal         0x8019882C
    // 0x80198204: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    Option_RankingPlanetName_Draw(rdram, ctx);
        goto after_1;
    // 0x80198204: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x80198208: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8019820C: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80198210: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80198214: jal         0x801984D0
    // 0x80198218: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    Option_RankingHitCount_Draw(rdram, ctx);
        goto after_2;
    // 0x80198218: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x8019821C: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80198220: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80198224: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80198228: jal         0x80198608
    // 0x8019822C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    Option_RankingTeamPresence_Draw(rdram, ctx);
        goto after_3;
    // 0x8019822C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
L_80198230:
    // 0x80198230: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80198234: bne         $s0, $s3, L_801981D0
    if (ctx->r16 != ctx->r19) {
        // 0x80198238: add.s       $f24, $f24, $f26
        CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f24.fl = ctx->f24.fl + ctx->f26.fl;
            goto L_801981D0;
    }
    // 0x80198238: add.s       $f24, $f24, $f26
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f24.fl = ctx->f24.fl + ctx->f26.fl;
    // 0x8019823C: lui         $at, 0x4296
    ctx->r1 = S32(0X4296 << 16);
    // 0x80198240: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80198244: lwc1        $f8, 0x60($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80198248: lui         $at, 0xC2A0
    ctx->r1 = S32(0XC2A0 << 16);
    // 0x8019824C: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x80198250: nop

    // 0x80198254: bc1fl       L_80198284
    if (!c1cs) {
        // 0x80198258: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_80198284;
    }
    goto skip_0;
    // 0x80198258: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    skip_0:
    // 0x8019825C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80198260: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80198264: c.lt.s      $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f16.fl < ctx->f8.fl;
    // 0x80198268: nop

    // 0x8019826C: bc1fl       L_80198284
    if (!c1cs) {
        // 0x80198270: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_80198284;
    }
    goto skip_1;
    // 0x80198270: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    skip_1:
    // 0x80198274: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80198278: jal         0x8019896C
    // 0x8019827C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    Option_RankingPlanetRoute_Draw(rdram, ctx);
        goto after_4;
    // 0x8019827C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_4:
    // 0x80198280: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_80198284:
    // 0x80198284: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80198288: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8019828C: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80198290: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x80198294: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x80198298: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x8019829C: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x801982A0: lw          $s2, 0x4C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X4C);
    // 0x801982A4: lw          $s3, 0x50($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X50);
    // 0x801982A8: jr          $ra
    // 0x801982AC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x801982AC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void Map_CurrentPlanet_SetAlpha(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019FA1C: lui         $t0, 0x801D
    ctx->r8 = S32(0X801D << 16);
    // 0x8019FA20: lw          $t0, -0x26AC($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X26AC);
    // 0x8019FA24: lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // 0x8019FA28: addiu       $v0, $v0, -0xAB8
    ctx->r2 = ADD32(ctx->r2, -0XAB8);
    // 0x8019FA2C: bne         $t0, $zero, L_8019FA44
    if (ctx->r8 != 0) {
        // 0x8019FA30: addiu       $t1, $t0, -0x1
        ctx->r9 = ADD32(ctx->r8, -0X1);
            goto L_8019FA44;
    }
    // 0x8019FA30: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x8019FA34: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8019FA38: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8019FA3C: b           L_8019FA4C
    // 0x8019FA40: sw          $t6, -0xB3C($at)
    MEM_W(-0XB3C, ctx->r1) = ctx->r14;
        goto L_8019FA4C;
    // 0x8019FA40: sw          $t6, -0xB3C($at)
    MEM_W(-0XB3C, ctx->r1) = ctx->r14;
L_8019FA44:
    // 0x8019FA44: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8019FA48: sw          $zero, -0xB3C($at)
    MEM_W(-0XB3C, ctx->r1) = 0;
L_8019FA4C:
    // 0x8019FA4C: bne         $t1, $zero, L_8019FA64
    if (ctx->r9 != 0) {
        // 0x8019FA50: addiu       $t2, $t0, -0x2
        ctx->r10 = ADD32(ctx->r8, -0X2);
            goto L_8019FA64;
    }
    // 0x8019FA50: addiu       $t2, $t0, -0x2
    ctx->r10 = ADD32(ctx->r8, -0X2);
    // 0x8019FA54: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8019FA58: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8019FA5C: b           L_8019FA6C
    // 0x8019FA60: sw          $t7, -0xB04($at)
    MEM_W(-0XB04, ctx->r1) = ctx->r15;
        goto L_8019FA6C;
    // 0x8019FA60: sw          $t7, -0xB04($at)
    MEM_W(-0XB04, ctx->r1) = ctx->r15;
L_8019FA64:
    // 0x8019FA64: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8019FA68: sw          $zero, -0xB04($at)
    MEM_W(-0XB04, ctx->r1) = 0;
L_8019FA6C:
    // 0x8019FA6C: bne         $t2, $zero, L_8019FA84
    if (ctx->r10 != 0) {
        // 0x8019FA70: sll         $t9, $t0, 3
        ctx->r25 = S32(ctx->r8 << 3);
            goto L_8019FA84;
    }
    // 0x8019FA70: sll         $t9, $t0, 3
    ctx->r25 = S32(ctx->r8 << 3);
    // 0x8019FA74: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8019FA78: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8019FA7C: b           L_8019FA8C
    // 0x8019FA80: sw          $t8, -0xACC($at)
    MEM_W(-0XACC, ctx->r1) = ctx->r24;
        goto L_8019FA8C;
    // 0x8019FA80: sw          $t8, -0xACC($at)
    MEM_W(-0XACC, ctx->r1) = ctx->r24;
L_8019FA84:
    // 0x8019FA84: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8019FA88: sw          $zero, -0xACC($at)
    MEM_W(-0XACC, ctx->r1) = 0;
L_8019FA8C:
    // 0x8019FA8C: subu        $t9, $t9, $t0
    ctx->r25 = SUB32(ctx->r25, ctx->r8);
    // 0x8019FA90: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8019FA94: addiu       $t6, $t6, -0xB60
    ctx->r14 = ADD32(ctx->r14, -0XB60);
    // 0x8019FA98: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x8019FA9C: addu        $v1, $t9, $t6
    ctx->r3 = ADD32(ctx->r25, ctx->r14);
    // 0x8019FAA0: sll         $t7, $t1, 3
    ctx->r15 = S32(ctx->r9 << 3);
    // 0x8019FAA4: addiu       $t3, $t0, -0x3
    ctx->r11 = ADD32(ctx->r8, -0X3);
    // 0x8019FAA8: sll         $t9, $t3, 3
    ctx->r25 = S32(ctx->r11 << 3);
    // 0x8019FAAC: subu        $t7, $t7, $t1
    ctx->r15 = SUB32(ctx->r15, ctx->r9);
    // 0x8019FAB0: sll         $t8, $t2, 3
    ctx->r24 = S32(ctx->r10 << 3);
    // 0x8019FAB4: subu        $t8, $t8, $t2
    ctx->r24 = SUB32(ctx->r24, ctx->r10);
    // 0x8019FAB8: subu        $t9, $t9, $t3
    ctx->r25 = SUB32(ctx->r25, ctx->r11);
    // 0x8019FABC: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x8019FAC0: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8019FAC4: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8019FAC8: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x8019FACC: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x8019FAD0: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x8019FAD4: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x8019FAD8: lui         $a3, 0x801B
    ctx->r7 = S32(0X801B << 16);
    // 0x8019FADC: addiu       $a3, $a3, -0xAB8
    ctx->r7 = ADD32(ctx->r7, -0XAB8);
    // 0x8019FAE0: addiu       $t4, $t4, -0xAF0
    ctx->r12 = ADD32(ctx->r12, -0XAF0);
    // 0x8019FAE4: addiu       $t5, $t5, -0xAB8
    ctx->r13 = ADD32(ctx->r13, -0XAB8);
    // 0x8019FAE8: addiu       $t0, $t0, -0xA80
    ctx->r8 = ADD32(ctx->r8, -0XA80);
    // 0x8019FAEC: addiu       $t1, $t1, -0xA48
    ctx->r9 = ADD32(ctx->r9, -0XA48);
    // 0x8019FAF0: addu        $a0, $t7, $t6
    ctx->r4 = ADD32(ctx->r15, ctx->r14);
    // 0x8019FAF4: addu        $a1, $t8, $t6
    ctx->r5 = ADD32(ctx->r24, ctx->r14);
    // 0x8019FAF8: addu        $a2, $t9, $t6
    ctx->r6 = ADD32(ctx->r25, ctx->r14);
    // 0x8019FAFC: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x8019FB00: addiu       $t2, $zero, 0x90
    ctx->r10 = ADD32(0, 0X90);
L_8019FB04:
    // 0x8019FB04: bne         $v0, $v1, L_8019FB34
    if (ctx->r2 != ctx->r3) {
        // 0x8019FB08: lui         $t8, 0x801B
        ctx->r24 = S32(0X801B << 16);
            goto L_8019FB34;
    }
    // 0x8019FB08: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x8019FB0C: beq         $v0, $a3, L_8019FB24
    if (ctx->r2 == ctx->r7) {
        // 0x8019FB10: nop
    
            goto L_8019FB24;
    }
    // 0x8019FB10: nop

    // 0x8019FB14: beq         $v0, $t0, L_8019FB24
    if (ctx->r2 == ctx->r8) {
        // 0x8019FB18: nop
    
            goto L_8019FB24;
    }
    // 0x8019FB18: nop

    // 0x8019FB1C: bne         $v0, $t1, L_8019FB2C
    if (ctx->r2 != ctx->r9) {
        // 0x8019FB20: nop
    
            goto L_8019FB2C;
    }
    // 0x8019FB20: nop

L_8019FB24:
    // 0x8019FB24: b           L_8019FB38
    // 0x8019FB28: sw          $t2, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r10;
        goto L_8019FB38;
    // 0x8019FB28: sw          $t2, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r10;
L_8019FB2C:
    // 0x8019FB2C: b           L_8019FB38
    // 0x8019FB30: sw          $t3, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r11;
        goto L_8019FB38;
    // 0x8019FB30: sw          $t3, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r11;
L_8019FB34:
    // 0x8019FB34: sw          $zero, 0x24($v0)
    MEM_W(0X24, ctx->r2) = 0;
L_8019FB38:
    // 0x8019FB38: bne         $v0, $a0, L_8019FB6C
    if (ctx->r2 != ctx->r4) {
        // 0x8019FB3C: addiu       $t8, $t8, -0xB28
        ctx->r24 = ADD32(ctx->r24, -0XB28);
            goto L_8019FB6C;
    }
    // 0x8019FB3C: addiu       $t8, $t8, -0xB28
    ctx->r24 = ADD32(ctx->r24, -0XB28);
    // 0x8019FB40: beq         $v0, $t4, L_8019FB5C
    if (ctx->r2 == ctx->r12) {
        // 0x8019FB44: nop
    
            goto L_8019FB5C;
    }
    // 0x8019FB44: nop

    // 0x8019FB48: beq         $v0, $t5, L_8019FB5C
    if (ctx->r2 == ctx->r13) {
        // 0x8019FB4C: lui         $t7, 0x801B
        ctx->r15 = S32(0X801B << 16);
            goto L_8019FB5C;
    }
    // 0x8019FB4C: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x8019FB50: addiu       $t7, $t7, -0xA80
    ctx->r15 = ADD32(ctx->r15, -0XA80);
    // 0x8019FB54: bne         $v0, $t7, L_8019FB64
    if (ctx->r2 != ctx->r15) {
        // 0x8019FB58: nop
    
            goto L_8019FB64;
    }
    // 0x8019FB58: nop

L_8019FB5C:
    // 0x8019FB5C: b           L_8019FB70
    // 0x8019FB60: sw          $t2, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->r10;
        goto L_8019FB70;
    // 0x8019FB60: sw          $t2, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->r10;
L_8019FB64:
    // 0x8019FB64: b           L_8019FB70
    // 0x8019FB68: sw          $t3, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->r11;
        goto L_8019FB70;
    // 0x8019FB68: sw          $t3, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->r11;
L_8019FB6C:
    // 0x8019FB6C: sw          $zero, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = 0;
L_8019FB70:
    // 0x8019FB70: bne         $v0, $a1, L_8019FBA8
    if (ctx->r2 != ctx->r5) {
        // 0x8019FB74: lui         $t7, 0x801B
        ctx->r15 = S32(0X801B << 16);
            goto L_8019FBA8;
    }
    // 0x8019FB74: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x8019FB78: beq         $v0, $t8, L_8019FB98
    if (ctx->r2 == ctx->r24) {
        // 0x8019FB7C: lui         $t9, 0x801B
        ctx->r25 = S32(0X801B << 16);
            goto L_8019FB98;
    }
    // 0x8019FB7C: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x8019FB80: addiu       $t9, $t9, -0xAF0
    ctx->r25 = ADD32(ctx->r25, -0XAF0);
    // 0x8019FB84: beq         $v0, $t9, L_8019FB98
    if (ctx->r2 == ctx->r25) {
        // 0x8019FB88: lui         $t6, 0x801B
        ctx->r14 = S32(0X801B << 16);
            goto L_8019FB98;
    }
    // 0x8019FB88: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8019FB8C: addiu       $t6, $t6, -0xAB8
    ctx->r14 = ADD32(ctx->r14, -0XAB8);
    // 0x8019FB90: bne         $v0, $t6, L_8019FBA0
    if (ctx->r2 != ctx->r14) {
        // 0x8019FB94: nop
    
            goto L_8019FBA0;
    }
    // 0x8019FB94: nop

L_8019FB98:
    // 0x8019FB98: b           L_8019FBAC
    // 0x8019FB9C: sw          $t2, 0x94($v0)
    MEM_W(0X94, ctx->r2) = ctx->r10;
        goto L_8019FBAC;
    // 0x8019FB9C: sw          $t2, 0x94($v0)
    MEM_W(0X94, ctx->r2) = ctx->r10;
L_8019FBA0:
    // 0x8019FBA0: b           L_8019FBAC
    // 0x8019FBA4: sw          $t3, 0x94($v0)
    MEM_W(0X94, ctx->r2) = ctx->r11;
        goto L_8019FBAC;
    // 0x8019FBA4: sw          $t3, 0x94($v0)
    MEM_W(0X94, ctx->r2) = ctx->r11;
L_8019FBA8:
    // 0x8019FBA8: sw          $zero, 0x94($v0)
    MEM_W(0X94, ctx->r2) = 0;
L_8019FBAC:
    // 0x8019FBAC: bne         $v0, $a2, L_8019FBE8
    if (ctx->r2 != ctx->r6) {
        // 0x8019FBB0: lui         $t6, 0x801B
        ctx->r14 = S32(0X801B << 16);
            goto L_8019FBE8;
    }
    // 0x8019FBB0: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8019FBB4: addiu       $t7, $t7, -0xB60
    ctx->r15 = ADD32(ctx->r15, -0XB60);
    // 0x8019FBB8: beq         $v0, $t7, L_8019FBD8
    if (ctx->r2 == ctx->r15) {
        // 0x8019FBBC: lui         $t8, 0x801B
        ctx->r24 = S32(0X801B << 16);
            goto L_8019FBD8;
    }
    // 0x8019FBBC: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x8019FBC0: addiu       $t8, $t8, -0xB28
    ctx->r24 = ADD32(ctx->r24, -0XB28);
    // 0x8019FBC4: beq         $v0, $t8, L_8019FBD8
    if (ctx->r2 == ctx->r24) {
        // 0x8019FBC8: lui         $t9, 0x801B
        ctx->r25 = S32(0X801B << 16);
            goto L_8019FBD8;
    }
    // 0x8019FBC8: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x8019FBCC: addiu       $t9, $t9, -0xAF0
    ctx->r25 = ADD32(ctx->r25, -0XAF0);
    // 0x8019FBD0: bne         $v0, $t9, L_8019FBE0
    if (ctx->r2 != ctx->r25) {
        // 0x8019FBD4: nop
    
            goto L_8019FBE0;
    }
    // 0x8019FBD4: nop

L_8019FBD8:
    // 0x8019FBD8: b           L_8019FBEC
    // 0x8019FBDC: sw          $t2, 0xCC($v0)
    MEM_W(0XCC, ctx->r2) = ctx->r10;
        goto L_8019FBEC;
    // 0x8019FBDC: sw          $t2, 0xCC($v0)
    MEM_W(0XCC, ctx->r2) = ctx->r10;
L_8019FBE0:
    // 0x8019FBE0: b           L_8019FBEC
    // 0x8019FBE4: sw          $t3, 0xCC($v0)
    MEM_W(0XCC, ctx->r2) = ctx->r11;
        goto L_8019FBEC;
    // 0x8019FBE4: sw          $t3, 0xCC($v0)
    MEM_W(0XCC, ctx->r2) = ctx->r11;
L_8019FBE8:
    // 0x8019FBE8: sw          $zero, 0xCC($v0)
    MEM_W(0XCC, ctx->r2) = 0;
L_8019FBEC:
    // 0x8019FBEC: addiu       $v0, $v0, 0xE0
    ctx->r2 = ADD32(ctx->r2, 0XE0);
    // 0x8019FBF0: addiu       $t6, $t6, -0x818
    ctx->r14 = ADD32(ctx->r14, -0X818);
    // 0x8019FBF4: bne         $v0, $t6, L_8019FB04
    if (ctx->r2 != ctx->r14) {
        // 0x8019FBF8: nop
    
            goto L_8019FB04;
    }
    // 0x8019FBF8: nop

    // 0x8019FBFC: jr          $ra
    // 0x8019FC00: nop

    return;
    // 0x8019FC00: nop

;}
RECOMP_FUNC void Title_Ranking_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80187CA8: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80187CAC: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80187CB0: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80187CB4: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x80187CB8: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80187CBC: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x80187CC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80187CC4: jal         0x800B8DD0
    // 0x80187CC8: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x80187CC8: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    after_0:
    // 0x80187CCC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80187CD0: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80187CD4: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x80187CD8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80187CDC: lui         $t8, 0xFFFF
    ctx->r24 = S32(0XFFFF << 16);
    // 0x80187CE0: ori         $t8, $t8, 0xFF
    ctx->r24 = ctx->r24 | 0XFF;
    // 0x80187CE4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80187CE8: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80187CEC: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80187CF0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80187CF4: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x80187CF8: addiu       $t9, $t9, -0x25BC
    ctx->r25 = ADD32(ctx->r25, -0X25BC);
    // 0x80187CFC: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80187D00: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80187D04: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80187D08: addiu       $a0, $zero, 0x24
    ctx->r4 = ADD32(0, 0X24);
    // 0x80187D0C: jal         0x800A1200
    // 0x80187D10: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    Graphics_DisplaySmallText(rdram, ctx);
        goto after_1;
    // 0x80187D10: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_1:
    // 0x80187D14: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80187D18: lui         $t1, 0xFA00
    ctx->r9 = S32(0XFA00 << 16);
    // 0x80187D1C: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80187D20: addiu       $t0, $v0, 0x8
    ctx->r8 = ADD32(ctx->r2, 0X8);
    // 0x80187D24: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x80187D28: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x80187D2C: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x80187D30: addiu       $t3, $zero, 0x14
    ctx->r11 = ADD32(0, 0X14);
    // 0x80187D34: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x80187D38: lui         $at, 0x4314
    ctx->r1 = S32(0X4314 << 16);
    // 0x80187D3C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80187D40: cvt.s.w     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80187D44: lui         $a1, 0x500
    ctx->r5 = S32(0X500 << 16);
    // 0x80187D48: addiu       $a1, $a1, 0x300
    ctx->r5 = ADD32(ctx->r5, 0X300);
    // 0x80187D4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80187D50: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80187D54: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    // 0x80187D58: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80187D5C: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x80187D60: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x80187D64: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80187D68: jal         0x8009D994
    // 0x80187D6C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_2;
    // 0x80187D6C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x80187D70: lui         $at, 0x4324
    ctx->r1 = S32(0X4324 << 16);
    // 0x80187D74: lwc1        $f0, 0x38($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80187D78: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80187D7C: lui         $a1, 0x500
    ctx->r5 = S32(0X500 << 16);
    // 0x80187D80: addiu       $a1, $a1, 0x200
    ctx->r5 = ADD32(ctx->r5, 0X200);
    // 0x80187D84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80187D88: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80187D8C: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    // 0x80187D90: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x80187D94: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80187D98: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80187D9C: jal         0x8009D994
    // 0x80187DA0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_3;
    // 0x80187DA0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_3:
    // 0x80187DA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80187DA8: jal         0x800B8DD0
    // 0x80187DAC: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    RCP_SetupDL(rdram, ctx);
        goto after_4;
    // 0x80187DAC: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    after_4:
    // 0x80187DB0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80187DB4: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x80187DB8: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80187DBC: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x80187DC0: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x80187DC4: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80187DC8: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80187DCC: lui         $at, 0x4210
    ctx->r1 = S32(0X4210 << 16);
    // 0x80187DD0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80187DD4: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x80187DD8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80187DDC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80187DE0: lwc1        $f18, 0x6DC8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6DC8);
    // 0x80187DE4: lui         $a1, 0x500
    ctx->r5 = S32(0X500 << 16);
    // 0x80187DE8: addiu       $a1, $a1, 0x77B0
    ctx->r5 = ADD32(ctx->r5, 0X77B0);
    // 0x80187DEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80187DF0: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80187DF4: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x80187DF8: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80187DFC: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x80187E00: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x80187E04: jal         0x8009D994
    // 0x80187E08: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_5;
    // 0x80187E08: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    after_5:
    // 0x80187E0C: jal         0x80187E28
    // 0x80187E10: nop

    Title_RankingData_Draw(rdram, ctx);
        goto after_6;
    // 0x80187E10: nop

    after_6:
    // 0x80187E14: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80187E18: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x80187E1C: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80187E20: jr          $ra
    // 0x80187E24: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80187E24: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void Map_GameOver_3DFont(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A3A00: addiu       $sp, $sp, -0xC8
    ctx->r29 = ADD32(ctx->r29, -0XC8);
    // 0x801A3A04: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x801A3A08: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x801A3A0C: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x801A3A10: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x801A3A14: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x801A3A18: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x801A3A1C: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801A3A20: lw          $a3, -0x26B4($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X26B4);
    // 0x801A3A24: sltiu       $at, $a3, 0xC
    ctx->r1 = ctx->r7 < 0XC ? 1 : 0;
    // 0x801A3A28: beq         $at, $zero, L_801A4374
    if (ctx->r1 == 0) {
        // 0x801A3A2C: sll         $t6, $a3, 2
        ctx->r14 = S32(ctx->r7 << 2);
            goto L_801A4374;
    }
    // 0x801A3A2C: sll         $t6, $a3, 2
    ctx->r14 = S32(ctx->r7 << 2);
    // 0x801A3A30: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A3A34: addu        $at, $at, $t6
    gpr jr_addend_801A3A3C = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x801A3A38: lw          $t6, 0x7788($at)
    ctx->r14 = ADD32(ctx->r1, 0X7788);
    // 0x801A3A3C: jr          $t6
    // 0x801A3A40: nop

    switch (jr_addend_801A3A3C >> 2) {
        case 0: goto L_801A3A44; break;
        case 1: goto L_801A3B58; break;
        case 2: goto L_801A3F80; break;
        case 3: goto L_801A411C; break;
        case 4: goto L_801A4374; break;
        case 5: goto L_801A4374; break;
        case 6: goto L_801A4374; break;
        case 7: goto L_801A4374; break;
        case 8: goto L_801A4374; break;
        case 9: goto L_801A4374; break;
        case 10: goto L_801A3EA8; break;
        case 11: goto L_801A3DFC; break;
        default: switch_error(__func__, 0x801A3A3C, 0x801B7788);
    }
    // 0x801A3A40: nop

L_801A3A44:
    // 0x801A3A44: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x801A3A48: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801A3A4C: lui         $s1, 0x801D
    ctx->r17 = S32(0X801D << 16);
    // 0x801A3A50: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x801A3A54: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801A3A58: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x801A3A5C: addiu       $v0, $v0, -0xF08
    ctx->r2 = ADD32(ctx->r2, -0XF08);
    // 0x801A3A60: addiu       $s0, $s0, -0xF58
    ctx->r16 = ADD32(ctx->r16, -0XF58);
    // 0x801A3A64: addiu       $s1, $s1, -0xF78
    ctx->r17 = ADD32(ctx->r17, -0XF78);
    // 0x801A3A68: addiu       $v1, $v1, -0xF28
    ctx->r3 = ADD32(ctx->r3, -0XF28);
    // 0x801A3A6C: lw          $a0, -0xEE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0XEE0);
    // 0x801A3A70: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x801A3A74: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x801A3A78: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x801A3A7C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
L_801A3A80:
    // 0x801A3A80: bne         $a0, $zero, L_801A3A90
    if (ctx->r4 != 0) {
        // 0x801A3A84: addiu       $t8, $s2, 0x4
        ctx->r24 = ADD32(ctx->r18, 0X4);
            goto L_801A3A90;
    }
    // 0x801A3A84: addiu       $t8, $s2, 0x4
    ctx->r24 = ADD32(ctx->r18, 0X4);
    // 0x801A3A88: b           L_801A3AA0
    // 0x801A3A8C: sw          $s2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r18;
        goto L_801A3AA0;
    // 0x801A3A8C: sw          $s2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r18;
L_801A3A90:
    // 0x801A3A90: multu       $t0, $a1
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801A3A94: mflo        $t7
    ctx->r15 = lo;
    // 0x801A3A98: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x801A3A9C: nop

L_801A3AA0:
    // 0x801A3AA0: swc1        $f2, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f2.u32l;
    // 0x801A3AA4: swc1        $f2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f2.u32l;
    // 0x801A3AA8: bne         $a0, $zero, L_801A3AB8
    if (ctx->r4 != 0) {
        // 0x801A3AAC: sw          $zero, 0x0($v0)
        MEM_W(0X0, ctx->r2) = 0;
            goto L_801A3AB8;
    }
    // 0x801A3AAC: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x801A3AB0: b           L_801A3AC8
    // 0x801A3AB4: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
        goto L_801A3AC8;
    // 0x801A3AB4: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
L_801A3AB8:
    // 0x801A3AB8: multu       $t0, $a1
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801A3ABC: mflo        $t9
    ctx->r25 = lo;
    // 0x801A3AC0: addiu       $t6, $t9, 0x3
    ctx->r14 = ADD32(ctx->r25, 0X3);
    // 0x801A3AC4: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
L_801A3AC8:
    // 0x801A3AC8: swc1        $f2, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f2.u32l;
    // 0x801A3ACC: swc1        $f2, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f2.u32l;
    // 0x801A3AD0: bne         $a0, $zero, L_801A3AE4
    if (ctx->r4 != 0) {
        // 0x801A3AD4: sw          $zero, 0x4($v0)
        MEM_W(0X4, ctx->r2) = 0;
            goto L_801A3AE4;
    }
    // 0x801A3AD4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801A3AD8: addiu       $t7, $s2, 0x8
    ctx->r15 = ADD32(ctx->r18, 0X8);
    // 0x801A3ADC: b           L_801A3AF4
    // 0x801A3AE0: sw          $t7, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r15;
        goto L_801A3AF4;
    // 0x801A3AE0: sw          $t7, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r15;
L_801A3AE4:
    // 0x801A3AE4: multu       $t0, $a1
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801A3AE8: mflo        $t8
    ctx->r24 = lo;
    // 0x801A3AEC: addiu       $t9, $t8, 0x6
    ctx->r25 = ADD32(ctx->r24, 0X6);
    // 0x801A3AF0: sw          $t9, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r25;
L_801A3AF4:
    // 0x801A3AF4: swc1        $f2, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f2.u32l;
    // 0x801A3AF8: swc1        $f2, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f2.u32l;
    // 0x801A3AFC: bne         $a0, $zero, L_801A3B10
    if (ctx->r4 != 0) {
        // 0x801A3B00: sw          $zero, 0x8($v0)
        MEM_W(0X8, ctx->r2) = 0;
            goto L_801A3B10;
    }
    // 0x801A3B00: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    // 0x801A3B04: addiu       $t6, $s2, 0xC
    ctx->r14 = ADD32(ctx->r18, 0XC);
    // 0x801A3B08: b           L_801A3B20
    // 0x801A3B0C: sw          $t6, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r14;
        goto L_801A3B20;
    // 0x801A3B0C: sw          $t6, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r14;
L_801A3B10:
    // 0x801A3B10: multu       $t0, $a1
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801A3B14: mflo        $t7
    ctx->r15 = lo;
    // 0x801A3B18: addiu       $t8, $t7, 0x9
    ctx->r24 = ADD32(ctx->r15, 0X9);
    // 0x801A3B1C: sw          $t8, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r24;
L_801A3B20:
    // 0x801A3B20: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x801A3B24: swc1        $f2, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f2.u32l;
    // 0x801A3B28: swc1        $f2, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f2.u32l;
    // 0x801A3B2C: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x801A3B30: addiu       $s2, $s2, 0x10
    ctx->r18 = ADD32(ctx->r18, 0X10);
    // 0x801A3B34: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x801A3B38: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x801A3B3C: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x801A3B40: bne         $t0, $a2, L_801A3A80
    if (ctx->r8 != ctx->r6) {
        // 0x801A3B44: addiu       $v0, $v0, 0x10
        ctx->r2 = ADD32(ctx->r2, 0X10);
            goto L_801A3A80;
    }
    // 0x801A3B44: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x801A3B48: addiu       $t9, $a3, 0x1
    ctx->r25 = ADD32(ctx->r7, 0X1);
    // 0x801A3B4C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A3B50: b           L_801A4374
    // 0x801A3B54: sw          $t9, -0x26B4($at)
    MEM_W(-0X26B4, ctx->r1) = ctx->r25;
        goto L_801A4374;
    // 0x801A3B54: sw          $t9, -0x26B4($at)
    MEM_W(-0X26B4, ctx->r1) = ctx->r25;
L_801A3B58:
    // 0x801A3B58: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801A3B5C: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x801A3B60: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x801A3B64: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801A3B68: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x801A3B6C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x801A3B70: addiu       $v1, $v1, -0xF28
    ctx->r3 = ADD32(ctx->r3, -0XF28);
    // 0x801A3B74: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x801A3B78: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_801A3B7C:
    // 0x801A3B7C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801A3B80: lui         $t7, 0x801D
    ctx->r15 = S32(0X801D << 16);
    // 0x801A3B84: addiu       $t7, $t7, -0xFE0
    ctx->r15 = ADD32(ctx->r15, -0XFE0);
    // 0x801A3B88: beq         $v0, $zero, L_801A3B9C
    if (ctx->r2 == 0) {
        // 0x801A3B8C: addu        $a0, $s2, $t7
        ctx->r4 = ADD32(ctx->r18, ctx->r15);
            goto L_801A3B9C;
    }
    // 0x801A3B8C: addu        $a0, $s2, $t7
    ctx->r4 = ADD32(ctx->r18, ctx->r15);
    // 0x801A3B90: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x801A3B94: b           L_801A3CF8
    // 0x801A3B98: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
        goto L_801A3CF8;
    // 0x801A3B98: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
L_801A3B9C:
    // 0x801A3B9C: lui         $t8, 0x801D
    ctx->r24 = S32(0X801D << 16);
    // 0x801A3BA0: lw          $t8, -0xF38($t8)
    ctx->r24 = MEM_W(ctx->r24, -0XF38);
    // 0x801A3BA4: lui         $t6, 0x801D
    ctx->r14 = S32(0X801D << 16);
    // 0x801A3BA8: addiu       $t6, $t6, -0xF78
    ctx->r14 = ADD32(ctx->r14, -0XF78);
    // 0x801A3BAC: addu        $t9, $t8, $s2
    ctx->r25 = ADD32(ctx->r24, ctx->r18);
    // 0x801A3BB0: lw          $a1, 0x0($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X0);
    // 0x801A3BB4: lui         $t9, 0x801D
    ctx->r25 = S32(0X801D << 16);
    // 0x801A3BB8: addiu       $t9, $t9, -0xFC0
    ctx->r25 = ADD32(ctx->r25, -0XFC0);
    // 0x801A3BBC: addu        $s1, $s2, $t6
    ctx->r17 = ADD32(ctx->r18, ctx->r14);
    // 0x801A3BC0: addiu       $t7, $sp, 0xA0
    ctx->r15 = ADD32(ctx->r29, 0XA0);
    // 0x801A3BC4: addu        $t8, $s2, $t7
    ctx->r24 = ADD32(ctx->r18, ctx->r15);
    // 0x801A3BC8: addu        $t6, $s2, $t9
    ctx->r14 = ADD32(ctx->r18, ctx->r25);
    // 0x801A3BCC: sw          $t6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r14;
    // 0x801A3BD0: sw          $t8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r24;
    // 0x801A3BD4: addiu       $t7, $sp, 0x80
    ctx->r15 = ADD32(ctx->r29, 0X80);
    // 0x801A3BD8: addu        $t8, $s2, $t7
    ctx->r24 = ADD32(ctx->r18, ctx->r15);
    // 0x801A3BDC: addiu       $t6, $sp, 0x60
    ctx->r14 = ADD32(ctx->r29, 0X60);
    // 0x801A3BE0: lui         $t9, 0x801D
    ctx->r25 = S32(0X801D << 16);
    // 0x801A3BE4: addiu       $t9, $t9, -0xFA0
    ctx->r25 = ADD32(ctx->r25, -0XFA0);
    // 0x801A3BE8: addu        $t7, $s2, $t6
    ctx->r15 = ADD32(ctx->r18, ctx->r14);
    // 0x801A3BEC: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x801A3BF0: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x801A3BF4: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801A3BF8: sw          $t7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r15;
    // 0x801A3BFC: addu        $s0, $s2, $t9
    ctx->r16 = ADD32(ctx->r18, ctx->r25);
    // 0x801A3C00: sw          $t8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r24;
    // 0x801A3C04: sw          $v1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r3;
    // 0x801A3C08: jal         0x8009BC2C
    // 0x801A3C0C: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_0;
    // 0x801A3C0C: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    after_0:
    // 0x801A3C10: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x801A3C14: lui         $t9, 0x801D
    ctx->r25 = S32(0X801D << 16);
    // 0x801A3C18: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x801A3C1C: swc1        $f0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f0.u32l;
    // 0x801A3C20: lw          $t9, -0xF34($t9)
    ctx->r25 = MEM_W(ctx->r25, -0XF34);
    // 0x801A3C24: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x801A3C28: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x801A3C2C: addu        $t6, $t9, $s2
    ctx->r14 = ADD32(ctx->r25, ctx->r18);
    // 0x801A3C30: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    // 0x801A3C34: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    // 0x801A3C38: jal         0x8009BC2C
    // 0x801A3C3C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    Math_SmoothStepToF(rdram, ctx);
        goto after_1;
    // 0x801A3C3C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    after_1:
    // 0x801A3C40: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x801A3C44: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A3C48: lwc1        $f12, 0x77B8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X77B8);
    // 0x801A3C4C: lui         $t8, 0x801D
    ctx->r24 = S32(0X801D << 16);
    // 0x801A3C50: swc1        $f0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f0.u32l;
    // 0x801A3C54: lw          $t8, -0xF30($t8)
    ctx->r24 = MEM_W(ctx->r24, -0XF30);
    // 0x801A3C58: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x801A3C5C: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x801A3C60: addu        $t9, $t8, $s2
    ctx->r25 = ADD32(ctx->r24, ctx->r18);
    // 0x801A3C64: lw          $a1, 0x0($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X0);
    // 0x801A3C68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801A3C6C: jal         0x8009BC2C
    // 0x801A3C70: swc1        $f12, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f12.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_2;
    // 0x801A3C70: swc1        $f12, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f12.u32l;
    after_2:
    // 0x801A3C74: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
    // 0x801A3C78: lw          $v1, 0x50($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X50);
    // 0x801A3C7C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x801A3C80: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x801A3C84: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x801A3C88: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801A3C8C: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x801A3C90: lwc1        $f4, 0x0($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X0);
    // 0x801A3C94: c.eq.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl == ctx->f4.fl;
    // 0x801A3C98: nop

    // 0x801A3C9C: bc1fl       L_801A3CF0
    if (!c1cs) {
        // 0x801A3CA0: lwc1        $f8, 0x0($s1)
        ctx->f8.u32l = MEM_W(ctx->r17, 0X0);
            goto L_801A3CF0;
    }
    goto skip_0;
    // 0x801A3CA0: lwc1        $f8, 0x0($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X0);
    skip_0:
    // 0x801A3CA4: lwc1        $f6, 0x0($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X0);
    // 0x801A3CA8: c.eq.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl == ctx->f6.fl;
    // 0x801A3CAC: nop

    // 0x801A3CB0: bc1fl       L_801A3CF0
    if (!c1cs) {
        // 0x801A3CB4: lwc1        $f8, 0x0($s1)
        ctx->f8.u32l = MEM_W(ctx->r17, 0X0);
            goto L_801A3CF0;
    }
    goto skip_1;
    // 0x801A3CB4: lwc1        $f8, 0x0($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X0);
    skip_1:
    // 0x801A3CB8: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801A3CBC: c.eq.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
    // 0x801A3CC0: nop

    // 0x801A3CC4: bc1fl       L_801A3CF0
    if (!c1cs) {
        // 0x801A3CC8: lwc1        $f8, 0x0($s1)
        ctx->f8.u32l = MEM_W(ctx->r17, 0X0);
            goto L_801A3CF0;
    }
    goto skip_2;
    // 0x801A3CC8: lwc1        $f8, 0x0($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X0);
    skip_2:
    // 0x801A3CCC: c.eq.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
    // 0x801A3CD0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A3CD4: swc1        $f2, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f2.u32l;
    // 0x801A3CD8: addu        $at, $at, $s2
    ctx->r1 = ADD32(ctx->r1, ctx->r18);
    // 0x801A3CDC: bc1f        L_801A3CF8
    if (!c1cs) {
        // 0x801A3CE0: nop
    
            goto L_801A3CF8;
    }
    // 0x801A3CE0: nop

    // 0x801A3CE4: b           L_801A3CF8
    // 0x801A3CE8: sw          $t1, -0xF08($at)
    MEM_W(-0XF08, ctx->r1) = ctx->r9;
        goto L_801A3CF8;
    // 0x801A3CE8: sw          $t1, -0xF08($at)
    MEM_W(-0XF08, ctx->r1) = ctx->r9;
    // 0x801A3CEC: lwc1        $f8, 0x0($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X0);
L_801A3CF0:
    // 0x801A3CF0: add.s       $f10, $f8, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f22.fl;
    // 0x801A3CF4: swc1        $f10, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f10.u32l;
L_801A3CF8:
    // 0x801A3CF8: lui         $t8, 0x801D
    ctx->r24 = S32(0X801D << 16);
    // 0x801A3CFC: addiu       $t8, $t8, -0xF08
    ctx->r24 = ADD32(ctx->r24, -0XF08);
    // 0x801A3D00: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x801A3D04: sltu        $at, $v1, $t8
    ctx->r1 = ctx->r3 < ctx->r24 ? 1 : 0;
    // 0x801A3D08: bne         $at, $zero, L_801A3B7C
    if (ctx->r1 != 0) {
        // 0x801A3D0C: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_801A3B7C;
    }
    // 0x801A3D0C: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x801A3D10: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801A3D14: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801A3D18: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x801A3D1C: addiu       $v1, $v1, -0xEE8
    ctx->r3 = ADD32(ctx->r3, -0XEE8);
    // 0x801A3D20: addiu       $v0, $v0, -0xF08
    ctx->r2 = ADD32(ctx->r2, -0XF08);
    // 0x801A3D24: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
L_801A3D28:
    // 0x801A3D28: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x801A3D2C: sltu        $at, $v0, $v1
    ctx->r1 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x801A3D30: bne         $t9, $zero, L_801A3D40
    if (ctx->r25 != 0) {
        // 0x801A3D34: nop
    
            goto L_801A3D40;
    }
    // 0x801A3D34: nop

    // 0x801A3D38: b           L_801A3D48
    // 0x801A3D3C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
        goto L_801A3D48;
    // 0x801A3D3C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_801A3D40:
    // 0x801A3D40: bnel        $at, $zero, L_801A3D28
    if (ctx->r1 != 0) {
        // 0x801A3D44: lw          $t9, 0x0($v0)
        ctx->r25 = MEM_W(ctx->r2, 0X0);
            goto L_801A3D28;
    }
    goto skip_3;
    // 0x801A3D44: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    skip_3:
L_801A3D48:
    // 0x801A3D48: bne         $a0, $t1, L_801A4374
    if (ctx->r4 != ctx->r9) {
        // 0x801A3D4C: lui         $at, 0x801D
        ctx->r1 = S32(0X801D << 16);
            goto L_801A4374;
    }
    // 0x801A3D4C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A3D50: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801A3D54: lui         $s1, 0x801D
    ctx->r17 = S32(0X801D << 16);
    // 0x801A3D58: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801A3D5C: sw          $zero, -0xEE8($at)
    MEM_W(-0XEE8, ctx->r1) = 0;
    // 0x801A3D60: addiu       $v0, $v0, -0xF08
    ctx->r2 = ADD32(ctx->r2, -0XF08);
    // 0x801A3D64: addiu       $s1, $s1, -0xF78
    ctx->r17 = ADD32(ctx->r17, -0XF78);
    // 0x801A3D68: addiu       $v1, $v1, -0xF28
    ctx->r3 = ADD32(ctx->r3, -0XF28);
    // 0x801A3D6C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801A3D70: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x801A3D74: addiu       $a3, $zero, 0x14
    ctx->r7 = ADD32(0, 0X14);
    // 0x801A3D78: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x801A3D7C: addiu       $t0, $zero, 0x6E
    ctx->r8 = ADD32(0, 0X6E);
L_801A3D80:
    // 0x801A3D80: sw          $a0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r4;
    // 0x801A3D84: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    // 0x801A3D88: sw          $a2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r6;
    // 0x801A3D8C: sw          $a3, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r7;
    // 0x801A3D90: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // 0x801A3D94: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    // 0x801A3D98: addiu       $a3, $a3, 0x28
    ctx->r7 = ADD32(ctx->r7, 0X28);
    // 0x801A3D9C: addiu       $a2, $a2, 0x28
    ctx->r6 = ADD32(ctx->r6, 0X28);
    // 0x801A3DA0: swc1        $f2, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f2.u32l;
    // 0x801A3DA4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801A3DA8: swc1        $f2, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f2.u32l;
    // 0x801A3DAC: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    // 0x801A3DB0: swc1        $f2, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f2.u32l;
    // 0x801A3DB4: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x801A3DB8: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x801A3DBC: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x801A3DC0: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x801A3DC4: swc1        $f2, -0x10($s1)
    MEM_W(-0X10, ctx->r17) = ctx->f2.u32l;
    // 0x801A3DC8: bne         $a0, $t0, L_801A3D80
    if (ctx->r4 != ctx->r8) {
        // 0x801A3DCC: sw          $zero, -0x10($v0)
        MEM_W(-0X10, ctx->r2) = 0;
            goto L_801A3D80;
    }
    // 0x801A3DCC: sw          $zero, -0x10($v0)
    MEM_W(-0X10, ctx->r2) = 0;
    // 0x801A3DD0: lui         $a2, 0x801D
    ctx->r6 = S32(0X801D << 16);
    // 0x801A3DD4: addiu       $a2, $a2, -0x2640
    ctx->r6 = ADD32(ctx->r6, -0X2640);
    // 0x801A3DD8: addiu       $t6, $zero, 0x3C
    ctx->r14 = ADD32(0, 0X3C);
    // 0x801A3DDC: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x801A3DE0: addiu       $t7, $zero, 0x55
    ctx->r15 = ADD32(0, 0X55);
    // 0x801A3DE4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A3DE8: sw          $t7, -0x2644($at)
    MEM_W(-0X2644, ctx->r1) = ctx->r15;
    // 0x801A3DEC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A3DF0: addiu       $t8, $zero, 0xB
    ctx->r24 = ADD32(0, 0XB);
    // 0x801A3DF4: b           L_801A4374
    // 0x801A3DF8: sw          $t8, -0x26B4($at)
    MEM_W(-0X26B4, ctx->r1) = ctx->r24;
        goto L_801A4374;
    // 0x801A3DF8: sw          $t8, -0x26B4($at)
    MEM_W(-0X26B4, ctx->r1) = ctx->r24;
L_801A3DFC:
    // 0x801A3DFC: lui         $a2, 0x801D
    ctx->r6 = S32(0X801D << 16);
    // 0x801A3E00: addiu       $a2, $a2, -0x2640
    ctx->r6 = ADD32(ctx->r6, -0X2640);
    // 0x801A3E04: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x801A3E08: lui         $t6, 0x801D
    ctx->r14 = S32(0X801D << 16);
    // 0x801A3E0C: bnel        $t9, $zero, L_801A4378
    if (ctx->r25 != 0) {
        // 0x801A3E10: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_801A4378;
    }
    goto skip_4;
    // 0x801A3E10: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_4:
    // 0x801A3E14: lw          $t6, -0x2644($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2644);
    // 0x801A3E18: lui         $s1, 0x801D
    ctx->r17 = S32(0X801D << 16);
    // 0x801A3E1C: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x801A3E20: beq         $t6, $zero, L_801A3EA0
    if (ctx->r14 == 0) {
        // 0x801A3E24: lui         $at, 0x801D
        ctx->r1 = S32(0X801D << 16);
            goto L_801A3EA0;
    }
    // 0x801A3E24: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A3E28: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x801A3E2C: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x801A3E30: lui         $s2, 0x801D
    ctx->r18 = S32(0X801D << 16);
    // 0x801A3E34: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x801A3E38: addiu       $s2, $s2, -0xF38
    ctx->r18 = ADD32(ctx->r18, -0XF38);
    // 0x801A3E3C: addiu       $s0, $s0, -0xF58
    ctx->r16 = ADD32(ctx->r16, -0XF58);
    // 0x801A3E40: addiu       $s1, $s1, -0xF78
    ctx->r17 = ADD32(ctx->r17, -0XF78);
L_801A3E44:
    // 0x801A3E44: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801A3E48: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801A3E4C: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x801A3E50: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x801A3E54: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x801A3E58: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801A3E5C: lui         $a1, 0x43B4
    ctx->r5 = S32(0X43B4 << 16);
    // 0x801A3E60: jal         0x8009BC2C
    // 0x801A3E64: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_3;
    // 0x801A3E64: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_3:
    // 0x801A3E68: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801A3E6C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801A3E70: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x801A3E74: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x801A3E78: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x801A3E7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801A3E80: lui         $a1, 0x43B4
    ctx->r5 = S32(0X43B4 << 16);
    // 0x801A3E84: jal         0x8009BC2C
    // 0x801A3E88: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_4;
    // 0x801A3E88: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_4:
    // 0x801A3E8C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x801A3E90: bne         $s0, $s2, L_801A3E44
    if (ctx->r16 != ctx->r18) {
        // 0x801A3E94: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_801A3E44;
    }
    // 0x801A3E94: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x801A3E98: b           L_801A4378
    // 0x801A3E9C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_801A4378;
    // 0x801A3E9C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_801A3EA0:
    // 0x801A3EA0: b           L_801A4374
    // 0x801A3EA4: sw          $t7, -0x26B4($at)
    MEM_W(-0X26B4, ctx->r1) = ctx->r15;
        goto L_801A4374;
    // 0x801A3EA4: sw          $t7, -0x26B4($at)
    MEM_W(-0X26B4, ctx->r1) = ctx->r15;
L_801A3EA8:
    // 0x801A3EA8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801A3EAC: addiu       $v0, $v0, -0x2648
    ctx->r2 = ADD32(ctx->r2, -0X2648);
    // 0x801A3EB0: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x801A3EB4: lui         $t9, 0x801D
    ctx->r25 = S32(0X801D << 16);
    // 0x801A3EB8: bnel        $t8, $zero, L_801A4378
    if (ctx->r24 != 0) {
        // 0x801A3EBC: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_801A4378;
    }
    goto skip_5;
    // 0x801A3EBC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_5:
    // 0x801A3EC0: lw          $t9, -0xEE0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0XEE0);
    // 0x801A3EC4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x801A3EC8: bne         $t9, $zero, L_801A3EF0
    if (ctx->r25 != 0) {
        // 0x801A3ECC: nop
    
            goto L_801A3EF0;
    }
    // 0x801A3ECC: nop

    // 0x801A3ED0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x801A3ED4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A3ED8: addiu       $t6, $zero, 0x19
    ctx->r14 = ADD32(0, 0X19);
    // 0x801A3EDC: swc1        $f2, -0x1560($at)
    MEM_W(-0X1560, ctx->r1) = ctx->f2.u32l;
    // 0x801A3EE0: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x801A3EE4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A3EE8: b           L_801A4374
    // 0x801A3EEC: sw          $a1, -0x26B4($at)
    MEM_W(-0X26B4, ctx->r1) = ctx->r5;
        goto L_801A4374;
    // 0x801A3EEC: sw          $a1, -0x26B4($at)
    MEM_W(-0X26B4, ctx->r1) = ctx->r5;
L_801A3EF0:
    // 0x801A3EF0: lui         $s1, 0x801D
    ctx->r17 = S32(0X801D << 16);
    // 0x801A3EF4: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x801A3EF8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801A3EFC: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801A3F00: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x801A3F04: addiu       $v1, $v1, -0xEE8
    ctx->r3 = ADD32(ctx->r3, -0XEE8);
    // 0x801A3F08: addiu       $v0, $v0, -0xF08
    ctx->r2 = ADD32(ctx->r2, -0XF08);
    // 0x801A3F0C: addiu       $s0, $s0, -0xF58
    ctx->r16 = ADD32(ctx->r16, -0XF58);
    // 0x801A3F10: addiu       $s1, $s1, -0xF78
    ctx->r17 = ADD32(ctx->r17, -0XF78);
L_801A3F14:
    // 0x801A3F14: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x801A3F18: swc1        $f2, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f2.u32l;
    // 0x801A3F1C: swc1        $f2, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f2.u32l;
    // 0x801A3F20: sw          $zero, -0xC($v0)
    MEM_W(-0XC, ctx->r2) = 0;
    // 0x801A3F24: swc1        $f2, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f2.u32l;
    // 0x801A3F28: swc1        $f2, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f2.u32l;
    // 0x801A3F2C: sw          $zero, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = 0;
    // 0x801A3F30: swc1        $f2, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f2.u32l;
    // 0x801A3F34: swc1        $f2, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f2.u32l;
    // 0x801A3F38: sw          $zero, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = 0;
    // 0x801A3F3C: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x801A3F40: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x801A3F44: swc1        $f2, -0x10($s1)
    MEM_W(-0X10, ctx->r17) = ctx->f2.u32l;
    // 0x801A3F48: swc1        $f2, -0x10($s0)
    MEM_W(-0X10, ctx->r16) = ctx->f2.u32l;
    // 0x801A3F4C: bne         $v0, $v1, L_801A3F14
    if (ctx->r2 != ctx->r3) {
        // 0x801A3F50: sw          $zero, -0x10($v0)
        MEM_W(-0X10, ctx->r2) = 0;
            goto L_801A3F14;
    }
    // 0x801A3F50: sw          $zero, -0x10($v0)
    MEM_W(-0X10, ctx->r2) = 0;
    // 0x801A3F54: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801A3F58: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801A3F5C: addiu       $a1, $a1, -0x1034
    ctx->r5 = ADD32(ctx->r5, -0X1034);
    // 0x801A3F60: addiu       $v1, $v1, -0xF28
    ctx->r3 = ADD32(ctx->r3, -0XF28);
    // 0x801A3F64: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x801A3F68: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x801A3F6C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x801A3F70: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x801A3F74: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A3F78: b           L_801A4374
    // 0x801A3F7C: sw          $t8, -0x26B4($at)
    MEM_W(-0X26B4, ctx->r1) = ctx->r24;
        goto L_801A4374;
    // 0x801A3F7C: sw          $t8, -0x26B4($at)
    MEM_W(-0X26B4, ctx->r1) = ctx->r24;
L_801A3F80:
    // 0x801A3F80: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801A3F84: addiu       $v1, $v1, -0xF28
    ctx->r3 = ADD32(ctx->r3, -0XF28);
    // 0x801A3F88: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801A3F8C: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801A3F90: addiu       $a1, $a1, -0x1034
    ctx->r5 = ADD32(ctx->r5, -0X1034);
    // 0x801A3F94: beq         $v0, $zero, L_801A3FAC
    if (ctx->r2 == 0) {
        // 0x801A3F98: addiu       $t9, $v0, -0x1
        ctx->r25 = ADD32(ctx->r2, -0X1);
            goto L_801A3FAC;
    }
    // 0x801A3F98: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x801A3F9C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x801A3FA0: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x801A3FA4: b           L_801A4090
    // 0x801A3FA8: lw          $a0, -0x1034($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1034);
        goto L_801A4090;
    // 0x801A3FA8: lw          $a0, -0x1034($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1034);
L_801A3FAC:
    // 0x801A3FAC: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x801A3FB0: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x801A3FB4: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x801A3FB8: addiu       $a0, $t6, 0x1
    ctx->r4 = ADD32(ctx->r14, 0X1);
    // 0x801A3FBC: slti        $at, $a0, 0x9
    ctx->r1 = SIGNED(ctx->r4) < 0X9 ? 1 : 0;
    // 0x801A3FC0: bne         $at, $zero, L_801A408C
    if (ctx->r1 != 0) {
        // 0x801A3FC4: sw          $a0, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->r4;
            goto L_801A408C;
    }
    // 0x801A3FC4: sw          $a0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r4;
    // 0x801A3FC8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801A3FCC: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801A3FD0: sw          $a2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r6;
    // 0x801A3FD4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801A3FD8: addiu       $v1, $v1, -0xEE8
    ctx->r3 = ADD32(ctx->r3, -0XEE8);
    // 0x801A3FDC: addiu       $v0, $v0, -0xF08
    ctx->r2 = ADD32(ctx->r2, -0XF08);
    // 0x801A3FE0: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
L_801A3FE4:
    // 0x801A3FE4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x801A3FE8: bne         $t8, $zero, L_801A3FF8
    if (ctx->r24 != 0) {
        // 0x801A3FEC: nop
    
            goto L_801A3FF8;
    }
    // 0x801A3FEC: nop

    // 0x801A3FF0: b           L_801A4000
    // 0x801A3FF4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
        goto L_801A4000;
    // 0x801A3FF4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_801A3FF8:
    // 0x801A3FF8: bnel        $v0, $v1, L_801A3FE4
    if (ctx->r2 != ctx->r3) {
        // 0x801A3FFC: lw          $t8, 0x0($v0)
        ctx->r24 = MEM_W(ctx->r2, 0X0);
            goto L_801A3FE4;
    }
    goto skip_6;
    // 0x801A3FFC: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    skip_6:
L_801A4000:
    // 0x801A4000: beq         $a0, $zero, L_801A4080
    if (ctx->r4 == 0) {
        // 0x801A4004: lui         $a2, 0x801D
        ctx->r6 = S32(0X801D << 16);
            goto L_801A4080;
    }
    // 0x801A4004: lui         $a2, 0x801D
    ctx->r6 = S32(0X801D << 16);
    // 0x801A4008: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x801A400C: addiu       $a0, $a0, -0xEE4
    ctx->r4 = ADD32(ctx->r4, -0XEE4);
    // 0x801A4010: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x801A4014: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x801A4018: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x801A401C: xori        $v1, $t9, 0x1
    ctx->r3 = ctx->r25 ^ 0X1;
    // 0x801A4020: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x801A4024: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // 0x801A4028: addu        $t7, $t7, $v0
    ctx->r15 = ADD32(ctx->r15, ctx->r2);
    // 0x801A402C: lw          $t7, 0x6A34($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6A34);
    // 0x801A4030: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x801A4034: addu        $t8, $t8, $v0
    ctx->r24 = ADD32(ctx->r24, ctx->r2);
    // 0x801A4038: lw          $t8, 0x6A3C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6A3C);
    // 0x801A403C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A4040: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x801A4044: addu        $t9, $t9, $v0
    ctx->r25 = ADD32(ctx->r25, ctx->r2);
    // 0x801A4048: sw          $t7, -0xF38($at)
    MEM_W(-0XF38, ctx->r1) = ctx->r15;
    // 0x801A404C: lw          $t9, 0x6A44($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6A44);
    // 0x801A4050: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A4054: sw          $t8, -0xF34($at)
    MEM_W(-0XF34, ctx->r1) = ctx->r24;
    // 0x801A4058: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A405C: addiu       $a2, $a2, -0x2640
    ctx->r6 = ADD32(ctx->r6, -0X2640);
    // 0x801A4060: addiu       $t6, $zero, 0xF
    ctx->r14 = ADD32(0, 0XF);
    // 0x801A4064: sw          $t9, -0xF30($at)
    MEM_W(-0XF30, ctx->r1) = ctx->r25;
    // 0x801A4068: beq         $v1, $zero, L_801A4078
    if (ctx->r3 == 0) {
        // 0x801A406C: sw          $t6, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->r14;
            goto L_801A4078;
    }
    // 0x801A406C: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x801A4070: addiu       $t7, $zero, 0xF0
    ctx->r15 = ADD32(0, 0XF0);
    // 0x801A4074: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
L_801A4078:
    // 0x801A4078: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A407C: sw          $zero, -0x26B4($at)
    MEM_W(-0X26B4, ctx->r1) = 0;
L_801A4080:
    // 0x801A4080: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x801A4084: b           L_801A4090
    // 0x801A4088: lw          $a0, -0x1034($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1034);
        goto L_801A4090;
    // 0x801A4088: lw          $a0, -0x1034($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1034);
L_801A408C:
    // 0x801A408C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
L_801A4090:
    // 0x801A4090: blez        $a0, L_801A4374
    if (SIGNED(ctx->r4) <= 0) {
        // 0x801A4094: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_801A4374;
    }
    // 0x801A4094: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x801A4098: lui         $t9, 0x801D
    ctx->r25 = S32(0X801D << 16);
    // 0x801A409C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x801A40A0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801A40A4: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x801A40A8: addiu       $v0, $t9, -0xF08
    ctx->r2 = ADD32(ctx->r25, -0XF08);
    // 0x801A40AC: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x801A40B0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x801A40B4: addu        $v1, $t6, $v0
    ctx->r3 = ADD32(ctx->r14, ctx->r2);
    // 0x801A40B8: addiu       $a0, $a0, -0xF58
    ctx->r4 = ADD32(ctx->r4, -0XF58);
    // 0x801A40BC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_801A40C0:
    // 0x801A40C0: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x801A40C4: addu        $s0, $a0, $s2
    ctx->r16 = ADD32(ctx->r4, ctx->r18);
    // 0x801A40C8: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x801A40CC: beql        $t1, $t7, L_801A4108
    if (ctx->r9 == ctx->r15) {
        // 0x801A40D0: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_801A4108;
    }
    goto skip_7;
    // 0x801A40D0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    skip_7:
    // 0x801A40D4: lwc1        $f0, 0x0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X0);
    // 0x801A40D8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801A40DC: nop

    // 0x801A40E0: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x801A40E4: nop

    // 0x801A40E8: bc1fl       L_801A4100
    if (!c1cs) {
        // 0x801A40EC: add.s       $f6, $f0, $f22
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f22.fl;
            goto L_801A4100;
    }
    goto skip_8;
    // 0x801A40EC: add.s       $f6, $f0, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f22.fl;
    skip_8:
    // 0x801A40F0: swc1        $f2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f2.u32l;
    // 0x801A40F4: b           L_801A4104
    // 0x801A40F8: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
        goto L_801A4104;
    // 0x801A40F8: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x801A40FC: add.s       $f6, $f0, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f22.fl;
L_801A4100:
    // 0x801A4100: swc1        $f6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f6.u32l;
L_801A4104:
    // 0x801A4104: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_801A4108:
    // 0x801A4108: sltu        $at, $v0, $v1
    ctx->r1 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x801A410C: bne         $at, $zero, L_801A40C0
    if (ctx->r1 != 0) {
        // 0x801A4110: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_801A40C0;
    }
    // 0x801A4110: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x801A4114: b           L_801A4378
    // 0x801A4118: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_801A4378;
    // 0x801A4118: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_801A411C:
    // 0x801A411C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801A4120: addiu       $v0, $v0, -0x2648
    ctx->r2 = ADD32(ctx->r2, -0X2648);
    // 0x801A4124: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x801A4128: lui         $s1, 0x801D
    ctx->r17 = S32(0X801D << 16);
    // 0x801A412C: addiu       $s1, $s1, -0xF78
    ctx->r17 = ADD32(ctx->r17, -0XF78);
    // 0x801A4130: bne         $t8, $zero, L_801A4374
    if (ctx->r24 != 0) {
        // 0x801A4134: lui         $s0, 0x801D
        ctx->r16 = S32(0X801D << 16);
            goto L_801A4374;
    }
    // 0x801A4134: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x801A4138: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A413C: lwc1        $f14, 0x77BC($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X77BC);
    // 0x801A4140: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A4144: lwc1        $f12, 0x77C0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X77C0);
    // 0x801A4148: lui         $at, 0xC396
    ctx->r1 = S32(0XC396 << 16);
    // 0x801A414C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801A4150: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801A4154: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801A4158: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801A415C: addiu       $v0, $v0, -0xF80
    ctx->r2 = ADD32(ctx->r2, -0XF80);
    // 0x801A4160: addiu       $s0, $s0, -0xFA0
    ctx->r16 = ADD32(ctx->r16, -0XFA0);
L_801A4164:
    // 0x801A4164: lwc1        $f16, 0x0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X0);
    // 0x801A4168: lwc1        $f8, 0x0($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X0);
    // 0x801A416C: add.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x801A4170: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x801A4174: swc1        $f18, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f18.u32l;
    // 0x801A4178: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x801A417C: swc1        $f10, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f10.u32l;
    // 0x801A4180: c.le.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl <= ctx->f12.fl;
    // 0x801A4184: nop

    // 0x801A4188: bc1fl       L_801A4198
    if (!c1cs) {
        // 0x801A418C: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_801A4198;
    }
    goto skip_9;
    // 0x801A418C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    skip_9:
    // 0x801A4190: swc1        $f14, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f14.u32l;
    // 0x801A4194: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_801A4198:
    // 0x801A4198: sltu        $at, $s0, $v0
    ctx->r1 = ctx->r16 < ctx->r2 ? 1 : 0;
    // 0x801A419C: bne         $at, $zero, L_801A4164
    if (ctx->r1 != 0) {
        // 0x801A41A0: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_801A4164;
    }
    // 0x801A41A0: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x801A41A4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A41A8: lwc1        $f6, 0x77C4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X77C4);
    // 0x801A41AC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A41B0: lwc1        $f8, -0xFA0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0XFA0);
    // 0x801A41B4: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801A41B8: lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // 0x801A41BC: c.le.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl <= ctx->f6.fl;
    // 0x801A41C0: addiu       $v1, $v1, -0x1560
    ctx->r3 = ADD32(ctx->r3, -0X1560);
    // 0x801A41C4: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x801A41C8: addiu       $v0, $v0, -0xAB8
    ctx->r2 = ADD32(ctx->r2, -0XAB8);
    // 0x801A41CC: bc1f        L_801A4334
    if (!c1cs) {
        // 0x801A41D0: lui         $s2, 0x801B
        ctx->r18 = S32(0X801B << 16);
            goto L_801A4334;
    }
    // 0x801A41D0: lui         $s2, 0x801B
    ctx->r18 = S32(0X801B << 16);
    // 0x801A41D4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801A41D8: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x801A41DC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801A41E0: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
    // 0x801A41E4: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x801A41E8: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x801A41EC: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801A41F0: addiu       $t3, $t7, -0xB28
    ctx->r11 = ADD32(ctx->r15, -0XB28);
    // 0x801A41F4: addiu       $t0, $t9, -0xAF0
    ctx->r8 = ADD32(ctx->r25, -0XAF0);
    // 0x801A41F8: lui         $ra, 0x801B
    ctx->r31 = S32(0X801B << 16);
    // 0x801A41FC: swc1        $f18, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f18.u32l;
    // 0x801A4200: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    // 0x801A4204: addiu       $ra, $ra, -0xB60
    ctx->r31 = ADD32(ctx->r31, -0XB60);
    // 0x801A4208: or          $s1, $t0, $zero
    ctx->r17 = ctx->r8 | 0;
    // 0x801A420C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x801A4210: or          $s0, $t3, $zero
    ctx->r16 = ctx->r11 | 0;
    // 0x801A4214: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A4218: addiu       $s2, $s2, -0x818
    ctx->r18 = ADD32(ctx->r18, -0X818);
    // 0x801A421C: bc1f        L_801A422C
    if (!c1cs) {
        // 0x801A4220: lui         $t8, 0x801B
        ctx->r24 = S32(0X801B << 16);
            goto L_801A422C;
    }
    // 0x801A4220: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x801A4224: swc1        $f2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f2.u32l;
    // 0x801A4228: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
L_801A422C:
    // 0x801A422C: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x801A4230: addiu       $a1, $t8, -0xAB8
    ctx->r5 = ADD32(ctx->r24, -0XAB8);
    // 0x801A4234: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x801A4238: addiu       $a2, $t6, -0xA80
    ctx->r6 = ADD32(ctx->r14, -0XA80);
    // 0x801A423C: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    // 0x801A4240: lui         $a3, 0x801B
    ctx->r7 = S32(0X801B << 16);
    // 0x801A4244: addiu       $a3, $a3, -0xA48
    ctx->r7 = ADD32(ctx->r7, -0XA48);
    // 0x801A4248: sw          $a0, -0xB3C($at)
    MEM_W(-0XB3C, ctx->r1) = ctx->r4;
    // 0x801A424C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A4250: sw          $a0, -0x2690($at)
    MEM_W(-0X2690, ctx->r1) = ctx->r4;
    // 0x801A4254: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A4258: sw          $a0, -0xB04($at)
    MEM_W(-0XB04, ctx->r1) = ctx->r4;
    // 0x801A425C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A4260: or          $t2, $a2, $zero
    ctx->r10 = ctx->r6 | 0;
    // 0x801A4264: or          $t5, $a1, $zero
    ctx->r13 = ctx->r5 | 0;
    // 0x801A4268: or          $t1, $a1, $zero
    ctx->r9 = ctx->r5 | 0;
    // 0x801A426C: or          $t4, $t0, $zero
    ctx->r12 = ctx->r8 | 0;
    // 0x801A4270: addiu       $v1, $zero, 0x90
    ctx->r3 = ADD32(0, 0X90);
    // 0x801A4274: sw          $a0, -0xACC($at)
    MEM_W(-0XACC, ctx->r1) = ctx->r4;
L_801A4278:
    // 0x801A4278: beq         $v0, $a1, L_801A4290
    if (ctx->r2 == ctx->r5) {
        // 0x801A427C: sw          $a0, 0x24($v0)
        MEM_W(0X24, ctx->r2) = ctx->r4;
            goto L_801A4290;
    }
    // 0x801A427C: sw          $a0, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r4;
    // 0x801A4280: beql        $v0, $a2, L_801A4294
    if (ctx->r2 == ctx->r6) {
        // 0x801A4284: lw          $t7, 0x24($v0)
        ctx->r15 = MEM_W(ctx->r2, 0X24);
            goto L_801A4294;
    }
    goto skip_10;
    // 0x801A4284: lw          $t7, 0x24($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X24);
    skip_10:
    // 0x801A4288: bne         $v0, $a3, L_801A42A4
    if (ctx->r2 != ctx->r7) {
        // 0x801A428C: nop
    
            goto L_801A42A4;
    }
    // 0x801A428C: nop

L_801A4290:
    // 0x801A4290: lw          $t7, 0x24($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X24);
L_801A4294:
    // 0x801A4294: slti        $at, $t7, 0x91
    ctx->r1 = SIGNED(ctx->r15) < 0X91 ? 1 : 0;
    // 0x801A4298: bne         $at, $zero, L_801A42A4
    if (ctx->r1 != 0) {
        // 0x801A429C: nop
    
            goto L_801A42A4;
    }
    // 0x801A429C: nop

    // 0x801A42A0: sw          $v1, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r3;
L_801A42A4:
    // 0x801A42A4: beq         $v0, $t0, L_801A42BC
    if (ctx->r2 == ctx->r8) {
        // 0x801A42A8: sw          $a0, 0x5C($v0)
        MEM_W(0X5C, ctx->r2) = ctx->r4;
            goto L_801A42BC;
    }
    // 0x801A42A8: sw          $a0, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->r4;
    // 0x801A42AC: beql        $v0, $t1, L_801A42C0
    if (ctx->r2 == ctx->r9) {
        // 0x801A42B0: lw          $t9, 0x5C($v0)
        ctx->r25 = MEM_W(ctx->r2, 0X5C);
            goto L_801A42C0;
    }
    goto skip_11;
    // 0x801A42B0: lw          $t9, 0x5C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X5C);
    skip_11:
    // 0x801A42B4: bne         $v0, $t2, L_801A42D0
    if (ctx->r2 != ctx->r10) {
        // 0x801A42B8: nop
    
            goto L_801A42D0;
    }
    // 0x801A42B8: nop

L_801A42BC:
    // 0x801A42BC: lw          $t9, 0x5C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X5C);
L_801A42C0:
    // 0x801A42C0: slti        $at, $t9, 0x91
    ctx->r1 = SIGNED(ctx->r25) < 0X91 ? 1 : 0;
    // 0x801A42C4: bne         $at, $zero, L_801A42D0
    if (ctx->r1 != 0) {
        // 0x801A42C8: nop
    
            goto L_801A42D0;
    }
    // 0x801A42C8: nop

    // 0x801A42CC: sw          $v1, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->r3;
L_801A42D0:
    // 0x801A42D0: beq         $v0, $t3, L_801A42E8
    if (ctx->r2 == ctx->r11) {
        // 0x801A42D4: sw          $a0, 0x94($v0)
        MEM_W(0X94, ctx->r2) = ctx->r4;
            goto L_801A42E8;
    }
    // 0x801A42D4: sw          $a0, 0x94($v0)
    MEM_W(0X94, ctx->r2) = ctx->r4;
    // 0x801A42D8: beql        $v0, $t4, L_801A42EC
    if (ctx->r2 == ctx->r12) {
        // 0x801A42DC: lw          $t6, 0x94($v0)
        ctx->r14 = MEM_W(ctx->r2, 0X94);
            goto L_801A42EC;
    }
    goto skip_12;
    // 0x801A42DC: lw          $t6, 0x94($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X94);
    skip_12:
    // 0x801A42E0: bne         $v0, $t5, L_801A42FC
    if (ctx->r2 != ctx->r13) {
        // 0x801A42E4: nop
    
            goto L_801A42FC;
    }
    // 0x801A42E4: nop

L_801A42E8:
    // 0x801A42E8: lw          $t6, 0x94($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X94);
L_801A42EC:
    // 0x801A42EC: slti        $at, $t6, 0x91
    ctx->r1 = SIGNED(ctx->r14) < 0X91 ? 1 : 0;
    // 0x801A42F0: bne         $at, $zero, L_801A42FC
    if (ctx->r1 != 0) {
        // 0x801A42F4: nop
    
            goto L_801A42FC;
    }
    // 0x801A42F4: nop

    // 0x801A42F8: sw          $v1, 0x94($v0)
    MEM_W(0X94, ctx->r2) = ctx->r3;
L_801A42FC:
    // 0x801A42FC: beq         $v0, $ra, L_801A4314
    if (ctx->r2 == ctx->r31) {
        // 0x801A4300: sw          $a0, 0xCC($v0)
        MEM_W(0XCC, ctx->r2) = ctx->r4;
            goto L_801A4314;
    }
    // 0x801A4300: sw          $a0, 0xCC($v0)
    MEM_W(0XCC, ctx->r2) = ctx->r4;
    // 0x801A4304: beql        $v0, $s0, L_801A4318
    if (ctx->r2 == ctx->r16) {
        // 0x801A4308: lw          $t8, 0xCC($v0)
        ctx->r24 = MEM_W(ctx->r2, 0XCC);
            goto L_801A4318;
    }
    goto skip_13;
    // 0x801A4308: lw          $t8, 0xCC($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XCC);
    skip_13:
    // 0x801A430C: bnel        $v0, $s1, L_801A432C
    if (ctx->r2 != ctx->r17) {
        // 0x801A4310: addiu       $v0, $v0, 0xE0
        ctx->r2 = ADD32(ctx->r2, 0XE0);
            goto L_801A432C;
    }
    goto skip_14;
    // 0x801A4310: addiu       $v0, $v0, 0xE0
    ctx->r2 = ADD32(ctx->r2, 0XE0);
    skip_14:
L_801A4314:
    // 0x801A4314: lw          $t8, 0xCC($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XCC);
L_801A4318:
    // 0x801A4318: slti        $at, $t8, 0x91
    ctx->r1 = SIGNED(ctx->r24) < 0X91 ? 1 : 0;
    // 0x801A431C: bnel        $at, $zero, L_801A432C
    if (ctx->r1 != 0) {
        // 0x801A4320: addiu       $v0, $v0, 0xE0
        ctx->r2 = ADD32(ctx->r2, 0XE0);
            goto L_801A432C;
    }
    goto skip_15;
    // 0x801A4320: addiu       $v0, $v0, 0xE0
    ctx->r2 = ADD32(ctx->r2, 0XE0);
    skip_15:
    // 0x801A4324: sw          $v1, 0xCC($v0)
    MEM_W(0XCC, ctx->r2) = ctx->r3;
    // 0x801A4328: addiu       $v0, $v0, 0xE0
    ctx->r2 = ADD32(ctx->r2, 0XE0);
L_801A432C:
    // 0x801A432C: bne         $v0, $s2, L_801A4278
    if (ctx->r2 != ctx->r18) {
        // 0x801A4330: nop
    
            goto L_801A4278;
    }
    // 0x801A4330: nop

L_801A4334:
    // 0x801A4334: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x801A4338: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801A433C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A4340: lwc1        $f6, -0x1560($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X1560);
    // 0x801A4344: c.eq.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl == ctx->f6.fl;
    // 0x801A4348: nop

    // 0x801A434C: bc1fl       L_801A4378
    if (!c1cs) {
        // 0x801A4350: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_801A4378;
    }
    goto skip_16;
    // 0x801A4350: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_16:
    // 0x801A4354: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x801A4358: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A435C: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x801A4360: swc1        $f2, -0xF80($at)
    MEM_W(-0XF80, ctx->r1) = ctx->f2.u32l;
    // 0x801A4364: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A4368: sw          $t7, -0x26B8($at)
    MEM_W(-0X26B8, ctx->r1) = ctx->r15;
    // 0x801A436C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A4370: sw          $zero, -0x26B4($at)
    MEM_W(-0X26B4, ctx->r1) = 0;
L_801A4374:
    // 0x801A4374: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_801A4378:
    // 0x801A4378: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x801A437C: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x801A4380: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x801A4384: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x801A4388: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x801A438C: jr          $ra
    // 0x801A4390: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
    return;
    // 0x801A4390: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
;}
RECOMP_FUNC void Map_RetryCourse(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A4FC4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801A4FC8: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x801A4FCC: addiu       $t0, $t0, 0x78A0
    ctx->r8 = ADD32(ctx->r8, 0X78A0);
    // 0x801A4FD0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801A4FD4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801A4FD8: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x801A4FDC: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x801A4FE0: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x801A4FE4: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x801A4FE8: lui         $a3, 0x8017
    ctx->r7 = S32(0X8017 << 16);
    // 0x801A4FEC: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    // 0x801A4FF0: addiu       $a3, $a3, 0x7C50
    ctx->r7 = ADD32(ctx->r7, 0X7C50);
    // 0x801A4FF4: addiu       $v1, $v1, 0x7C38
    ctx->r3 = ADD32(ctx->r3, 0X7C38);
    // 0x801A4FF8: addiu       $a2, $a2, 0x78B0
    ctx->r6 = ADD32(ctx->r6, 0X78B0);
    // 0x801A4FFC: addiu       $a1, $a1, 0x7C58
    ctx->r5 = ADD32(ctx->r5, 0X7C58);
    // 0x801A5000: addiu       $a0, $a0, 0x78D0
    ctx->r4 = ADD32(ctx->r4, 0X78D0);
L_801A5004:
    // 0x801A5004: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x801A5008: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x801A500C: sltu        $at, $v1, $a3
    ctx->r1 = ctx->r3 < ctx->r7 ? 1 : 0;
    // 0x801A5010: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x801A5014: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x801A5018: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x801A501C: sw          $v0, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = ctx->r2;
    // 0x801A5020: sw          $v0, -0x4($a2)
    MEM_W(-0X4, ctx->r6) = ctx->r2;
    // 0x801A5024: bne         $at, $zero, L_801A5004
    if (ctx->r1 != 0) {
        // 0x801A5028: sw          $v0, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->r2;
            goto L_801A5004;
    }
    // 0x801A5028: sw          $v0, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r2;
    // 0x801A502C: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x801A5030: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x801A5034: addiu       $v0, $v0, 0x7C48
    ctx->r2 = ADD32(ctx->r2, 0X7C48);
    // 0x801A5038: addiu       $v1, $v1, 0x7C3C
    ctx->r3 = ADD32(ctx->r3, 0X7C3C);
    // 0x801A503C: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x801A5040: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
L_801A5044:
    // 0x801A5044: bnel        $t6, $zero, L_801A5054
    if (ctx->r14 != 0) {
        // 0x801A5048: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_801A5054;
    }
    goto skip_0;
    // 0x801A5048: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    skip_0:
    // 0x801A504C: sw          $a2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r6;
    // 0x801A5050: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_801A5054:
    // 0x801A5054: bnel        $v1, $v0, L_801A5044
    if (ctx->r3 != ctx->r2) {
        // 0x801A5058: lw          $t6, 0x0($v1)
        ctx->r14 = MEM_W(ctx->r3, 0X0);
            goto L_801A5044;
    }
    goto skip_1;
    // 0x801A5058: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    skip_1:
    // 0x801A505C: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x801A5060: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x801A5064: lw          $s0, -0x26AC($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X26AC);
    // 0x801A5068: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x801A506C: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x801A5070: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x801A5074: sw          $zero, 0x1AA8($at)
    MEM_W(0X1AA8, ctx->r1) = 0;
    // 0x801A5078: sll         $t9, $s0, 3
    ctx->r25 = S32(ctx->r16 << 3);
    // 0x801A507C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801A5080: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x801A5084: subu        $t9, $t9, $s0
    ctx->r25 = SUB32(ctx->r25, ctx->r16);
    // 0x801A5088: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x801A508C: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x801A5090: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x801A5094: addiu       $t1, $t1, -0xB60
    ctx->r9 = ADD32(ctx->r9, -0XB60);
    // 0x801A5098: sw          $t8, 0x7DA0($at)
    MEM_W(0X7DA0, ctx->r1) = ctx->r24;
    // 0x801A509C: addu        $v1, $t9, $t1
    ctx->r3 = ADD32(ctx->r25, ctx->r9);
    // 0x801A50A0: lw          $a1, 0x2C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X2C);
    // 0x801A50A4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801A50A8: beql        $a1, $at, L_801A5108
    if (ctx->r5 == ctx->r1) {
        // 0x801A50AC: lw          $a1, 0x30($v1)
        ctx->r5 = MEM_W(ctx->r3, 0X30);
            goto L_801A5108;
    }
    goto skip_2;
    // 0x801A50AC: lw          $a1, 0x30($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X30);
    skip_2:
    // 0x801A50B0: jal         0x801A655C
    // 0x801A50B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Map_GetPathId(rdram, ctx);
        goto after_0;
    // 0x801A50B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x801A50B8: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x801A50BC: lw          $s0, -0x26AC($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X26AC);
    // 0x801A50C0: sll         $t2, $v0, 2
    ctx->r10 = S32(ctx->r2 << 2);
    // 0x801A50C4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801A50C8: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x801A50CC: sll         $t3, $v0, 3
    ctx->r11 = S32(ctx->r2 << 3);
    // 0x801A50D0: sw          $zero, 0x7BD8($at)
    MEM_W(0X7BD8, ctx->r1) = 0;
    // 0x801A50D4: subu        $t3, $t3, $v0
    ctx->r11 = SUB32(ctx->r11, ctx->r2);
    // 0x801A50D8: sll         $t4, $s0, 3
    ctx->r12 = S32(ctx->r16 << 3);
    // 0x801A50DC: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x801A50E0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A50E4: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x801A50E8: subu        $t4, $t4, $s0
    ctx->r12 = SUB32(ctx->r12, ctx->r16);
    // 0x801A50EC: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x801A50F0: addiu       $t5, $t5, -0xB60
    ctx->r13 = ADD32(ctx->r13, -0XB60);
    // 0x801A50F4: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x801A50F8: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x801A50FC: sw          $zero, -0x2D0($at)
    MEM_W(-0X2D0, ctx->r1) = 0;
    // 0x801A5100: addu        $v1, $t4, $t5
    ctx->r3 = ADD32(ctx->r12, ctx->r13);
    // 0x801A5104: lw          $a1, 0x30($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X30);
L_801A5108:
    // 0x801A5108: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801A510C: beql        $a1, $at, L_801A516C
    if (ctx->r5 == ctx->r1) {
        // 0x801A5110: lw          $a1, 0x34($v1)
        ctx->r5 = MEM_W(ctx->r3, 0X34);
            goto L_801A516C;
    }
    goto skip_3;
    // 0x801A5110: lw          $a1, 0x34($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X34);
    skip_3:
    // 0x801A5114: jal         0x801A655C
    // 0x801A5118: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Map_GetPathId(rdram, ctx);
        goto after_1;
    // 0x801A5118: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x801A511C: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x801A5120: lw          $s0, -0x26AC($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X26AC);
    // 0x801A5124: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x801A5128: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801A512C: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x801A5130: sll         $t7, $v0, 3
    ctx->r15 = S32(ctx->r2 << 3);
    // 0x801A5134: sw          $zero, 0x7BD8($at)
    MEM_W(0X7BD8, ctx->r1) = 0;
    // 0x801A5138: subu        $t7, $t7, $v0
    ctx->r15 = SUB32(ctx->r15, ctx->r2);
    // 0x801A513C: sll         $t8, $s0, 3
    ctx->r24 = S32(ctx->r16 << 3);
    // 0x801A5140: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801A5144: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A5148: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x801A514C: subu        $t8, $t8, $s0
    ctx->r24 = SUB32(ctx->r24, ctx->r16);
    // 0x801A5150: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x801A5154: addiu       $t9, $t9, -0xB60
    ctx->r25 = ADD32(ctx->r25, -0XB60);
    // 0x801A5158: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x801A515C: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x801A5160: sw          $zero, -0x2D0($at)
    MEM_W(-0X2D0, ctx->r1) = 0;
    // 0x801A5164: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // 0x801A5168: lw          $a1, 0x34($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X34);
L_801A516C:
    // 0x801A516C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801A5170: beq         $a1, $at, L_801A51AC
    if (ctx->r5 == ctx->r1) {
        // 0x801A5174: nop
    
            goto L_801A51AC;
    }
    // 0x801A5174: nop

    // 0x801A5178: jal         0x801A655C
    // 0x801A517C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Map_GetPathId(rdram, ctx);
        goto after_2;
    // 0x801A517C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x801A5180: sll         $t1, $v0, 2
    ctx->r9 = S32(ctx->r2 << 2);
    // 0x801A5184: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801A5188: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x801A518C: sll         $t2, $v0, 3
    ctx->r10 = S32(ctx->r2 << 3);
    // 0x801A5190: sw          $zero, 0x7BD8($at)
    MEM_W(0X7BD8, ctx->r1) = 0;
    // 0x801A5194: subu        $t2, $t2, $v0
    ctx->r10 = SUB32(ctx->r10, ctx->r2);
    // 0x801A5198: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x801A519C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A51A0: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x801A51A4: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x801A51A8: sw          $zero, -0x2D0($at)
    MEM_W(-0X2D0, ctx->r1) = 0;
L_801A51AC:
    // 0x801A51AC: lui         $t3, 0x801D
    ctx->r11 = S32(0X801D << 16);
    // 0x801A51B0: lw          $t3, -0x1134($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X1134);
    // 0x801A51B4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A51B8: lui         $a3, 0x8017
    ctx->r7 = S32(0X8017 << 16);
    // 0x801A51BC: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x801A51C0: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x801A51C4: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x801A51C8: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x801A51CC: sw          $zero, -0x2D4($at)
    MEM_W(-0X2D4, ctx->r1) = 0;
    // 0x801A51D0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A51D4: sw          $zero, -0x1160($at)
    MEM_W(-0X1160, ctx->r1) = 0;
    // 0x801A51D8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A51DC: sw          $zero, -0x115C($at)
    MEM_W(-0X115C, ctx->r1) = 0;
    // 0x801A51E0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A51E4: sw          $a2, -0x1158($at)
    MEM_W(-0X1158, ctx->r1) = ctx->r6;
    // 0x801A51E8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A51EC: addiu       $a3, $a3, 0x7B48
    ctx->r7 = ADD32(ctx->r7, 0X7B48);
    // 0x801A51F0: sw          $a2, -0x1154($at)
    MEM_W(-0X1154, ctx->r1) = ctx->r6;
    // 0x801A51F4: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x801A51F8: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x801A51FC: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x801A5200: addiu       $t5, $t5, 0x7B70
    ctx->r13 = ADD32(ctx->r13, 0X7B70);
    // 0x801A5204: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x801A5208: addiu       $a1, $a1, 0x1714
    ctx->r5 = ADD32(ctx->r5, 0X1714);
    // 0x801A520C: addu        $a0, $v0, $t5
    ctx->r4 = ADD32(ctx->r2, ctx->r13);
    // 0x801A5210: lw          $t7, -0x4($a0)
    ctx->r15 = MEM_W(ctx->r4, -0X4);
    // 0x801A5214: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x801A5218: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801A521C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x801A5220: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x801A5224: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x801A5228: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x801A522C: sw          $t9, 0x7B90($at)
    MEM_W(0X7B90, ctx->r1) = ctx->r25;
    // 0x801A5230: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801A5234: sw          $zero, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = 0;
    // 0x801A5238: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x801A523C: sw          $zero, 0x7BAC($at)
    MEM_W(0X7BAC, ctx->r1) = 0;
    // 0x801A5240: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801A5244: lui         $t1, 0xFF
    ctx->r9 = S32(0XFF << 16);
    // 0x801A5248: ori         $t1, $t1, 0xFFFF
    ctx->r9 = ctx->r9 | 0XFFFF;
    // 0x801A524C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x801A5250: sw          $t1, 0x7B4C($at)
    MEM_W(0X7B4C, ctx->r1) = ctx->r9;
    // 0x801A5254: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x801A5258: sw          $zero, 0x1A98($at)
    MEM_W(0X1A98, ctx->r1) = 0;
    // 0x801A525C: addiu       $t2, $v1, -0x1
    ctx->r10 = ADD32(ctx->r3, -0X1);
    // 0x801A5260: jal         0x801A05B4
    // 0x801A5264: sw          $t2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r10;
    Map_801A05B4(rdram, ctx);
        goto after_3;
    // 0x801A5264: sw          $t2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r10;
    after_3:
    // 0x801A5268: lui         $t3, 0x801D
    ctx->r11 = S32(0X801D << 16);
    // 0x801A526C: lw          $t3, -0x26B0($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X26B0);
    // 0x801A5270: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A5274: sw          $v0, -0x27C4($at)
    MEM_W(-0X27C4, ctx->r1) = ctx->r2;
    // 0x801A5278: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x801A527C: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x801A5280: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x801A5284: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A5288: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x801A528C: addiu       $t5, $t5, -0xB60
    ctx->r13 = ADD32(ctx->r13, -0XB60);
    // 0x801A5290: addu        $v1, $t4, $t5
    ctx->r3 = ADD32(ctx->r12, ctx->r13);
    // 0x801A5294: sw          $t3, -0x26AC($at)
    MEM_W(-0X26AC, ctx->r1) = ctx->r11;
    // 0x801A5298: lw          $a1, 0x2C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X2C);
    // 0x801A529C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801A52A0: or          $s0, $t3, $zero
    ctx->r16 = ctx->r11 | 0;
    // 0x801A52A4: beql        $a1, $at, L_801A5308
    if (ctx->r5 == ctx->r1) {
        // 0x801A52A8: lw          $a1, 0x30($v1)
        ctx->r5 = MEM_W(ctx->r3, 0X30);
            goto L_801A5308;
    }
    goto skip_4;
    // 0x801A52A8: lw          $a1, 0x30($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X30);
    skip_4:
    // 0x801A52AC: jal         0x801A655C
    // 0x801A52B0: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    Map_GetPathId(rdram, ctx);
        goto after_4;
    // 0x801A52B0: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    after_4:
    // 0x801A52B4: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x801A52B8: lw          $s0, -0x26AC($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X26AC);
    // 0x801A52BC: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x801A52C0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801A52C4: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x801A52C8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801A52CC: sll         $t8, $v0, 3
    ctx->r24 = S32(ctx->r2 << 3);
    // 0x801A52D0: sw          $t6, 0x7BD8($at)
    MEM_W(0X7BD8, ctx->r1) = ctx->r14;
    // 0x801A52D4: subu        $t8, $t8, $v0
    ctx->r24 = SUB32(ctx->r24, ctx->r2);
    // 0x801A52D8: sll         $t9, $s0, 3
    ctx->r25 = S32(ctx->r16 << 3);
    // 0x801A52DC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x801A52E0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A52E4: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x801A52E8: subu        $t9, $t9, $s0
    ctx->r25 = SUB32(ctx->r25, ctx->r16);
    // 0x801A52EC: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x801A52F0: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x801A52F4: addiu       $t1, $t1, -0xB60
    ctx->r9 = ADD32(ctx->r9, -0XB60);
    // 0x801A52F8: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x801A52FC: sw          $a2, -0x2D0($at)
    MEM_W(-0X2D0, ctx->r1) = ctx->r6;
    // 0x801A5300: addu        $v1, $t9, $t1
    ctx->r3 = ADD32(ctx->r25, ctx->r9);
    // 0x801A5304: lw          $a1, 0x30($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X30);
L_801A5308:
    // 0x801A5308: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801A530C: beql        $a1, $at, L_801A5370
    if (ctx->r5 == ctx->r1) {
        // 0x801A5310: lw          $a1, 0x34($v1)
        ctx->r5 = MEM_W(ctx->r3, 0X34);
            goto L_801A5370;
    }
    goto skip_5;
    // 0x801A5310: lw          $a1, 0x34($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X34);
    skip_5:
    // 0x801A5314: jal         0x801A655C
    // 0x801A5318: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Map_GetPathId(rdram, ctx);
        goto after_5;
    // 0x801A5318: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x801A531C: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x801A5320: lw          $s0, -0x26AC($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X26AC);
    // 0x801A5324: sll         $t3, $v0, 2
    ctx->r11 = S32(ctx->r2 << 2);
    // 0x801A5328: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801A532C: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x801A5330: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801A5334: sll         $t4, $v0, 3
    ctx->r12 = S32(ctx->r2 << 3);
    // 0x801A5338: sw          $t2, 0x7BD8($at)
    MEM_W(0X7BD8, ctx->r1) = ctx->r10;
    // 0x801A533C: subu        $t4, $t4, $v0
    ctx->r12 = SUB32(ctx->r12, ctx->r2);
    // 0x801A5340: sll         $t5, $s0, 3
    ctx->r13 = S32(ctx->r16 << 3);
    // 0x801A5344: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x801A5348: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A534C: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x801A5350: subu        $t5, $t5, $s0
    ctx->r13 = SUB32(ctx->r13, ctx->r16);
    // 0x801A5354: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x801A5358: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x801A535C: addiu       $t6, $t6, -0xB60
    ctx->r14 = ADD32(ctx->r14, -0XB60);
    // 0x801A5360: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x801A5364: sw          $a2, -0x2D0($at)
    MEM_W(-0X2D0, ctx->r1) = ctx->r6;
    // 0x801A5368: addu        $v1, $t5, $t6
    ctx->r3 = ADD32(ctx->r13, ctx->r14);
    // 0x801A536C: lw          $a1, 0x34($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X34);
L_801A5370:
    // 0x801A5370: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801A5374: beq         $a1, $at, L_801A53AC
    if (ctx->r5 == ctx->r1) {
        // 0x801A5378: nop
    
            goto L_801A53AC;
    }
    // 0x801A5378: nop

    // 0x801A537C: jal         0x801A655C
    // 0x801A5380: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Map_GetPathId(rdram, ctx);
        goto after_6;
    // 0x801A5380: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x801A5384: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x801A5388: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801A538C: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x801A5390: sll         $t8, $v0, 3
    ctx->r24 = S32(ctx->r2 << 3);
    // 0x801A5394: sw          $zero, 0x7BD8($at)
    MEM_W(0X7BD8, ctx->r1) = 0;
    // 0x801A5398: subu        $t8, $t8, $v0
    ctx->r24 = SUB32(ctx->r24, ctx->r2);
    // 0x801A539C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x801A53A0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A53A4: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x801A53A8: sw          $zero, -0x2D0($at)
    MEM_W(-0X2D0, ctx->r1) = 0;
L_801A53AC:
    // 0x801A53AC: jal         0x801A6368
    // 0x801A53B0: nop

    Map_CurrentLevel_Setup(rdram, ctx);
        goto after_7;
    // 0x801A53B0: nop

    after_7:
    // 0x801A53B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801A53B8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801A53BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801A53C0: jr          $ra
    // 0x801A53C4: nop

    return;
    // 0x801A53C4: nop

;}
RECOMP_FUNC void Title_SetLightRot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80191674: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80191678: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8019167C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80191680: swc1        $f12, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f12.u32l;
    // 0x80191684: swc1        $f14, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f14.u32l;
    // 0x80191688: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x8019168C: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x80191690: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80191694: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x80191698: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x8019169C: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x801916A0: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x801916A4: jal         0x80191798
    // 0x801916A8: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    Title_GetCamRot(rdram, ctx);
        goto after_0;
    // 0x801916A8: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x801916AC: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x801916B0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801916B4: lwc1        $f10, 0x70E8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X70E8);
    // 0x801916B8: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x801916BC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801916C0: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x801916C4: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801916C8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801916CC: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x801916D0: jal         0x80005D44
    // 0x801916D4: nop

    Matrix_RotateX(rdram, ctx);
        goto after_1;
    // 0x801916D4: nop

    after_1:
    // 0x801916D8: lwc1        $f18, 0x30($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X30);
    // 0x801916DC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801916E0: lwc1        $f6, 0x70EC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X70EC);
    // 0x801916E4: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x801916E8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801916EC: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x801916F0: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801916F4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801916F8: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x801916FC: jal         0x80005E90
    // 0x80191700: nop

    Matrix_RotateY(rdram, ctx);
        goto after_2;
    // 0x80191700: nop

    after_2:
    // 0x80191704: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80191708: lwc1        $f10, 0x70F0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X70F0);
    // 0x8019170C: lwc1        $f16, 0x3C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80191710: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80191714: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80191718: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8019171C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80191720: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80191724: jal         0x80005E90
    // 0x80191728: nop

    Matrix_RotateY(rdram, ctx);
        goto after_3;
    // 0x80191728: nop

    after_3:
    // 0x8019172C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80191730: lwc1        $f4, 0x70F4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X70F4);
    // 0x80191734: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80191738: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8019173C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80191740: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80191744: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80191748: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8019174C: jal         0x80005D44
    // 0x80191750: nop

    Matrix_RotateX(rdram, ctx);
        goto after_4;
    // 0x80191750: nop

    after_4:
    // 0x80191754: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80191758: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8019175C: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x80191760: jal         0x80006970
    // 0x80191764: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    Matrix_MultVec3f(rdram, ctx);
        goto after_5;
    // 0x80191764: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    after_5:
    // 0x80191768: lwc1        $f10, 0x24($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8019176C: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x80191770: swc1        $f10, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f10.u32l;
    // 0x80191774: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x80191778: lwc1        $f16, 0x28($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8019177C: swc1        $f16, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f16.u32l;
    // 0x80191780: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x80191784: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80191788: swc1        $f18, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f18.u32l;
    // 0x8019178C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80191790: jr          $ra
    // 0x80191794: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80191794: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void Map_TeamDownWrench_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801ABCDC: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x801ABCE0: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    // 0x801ABCE4: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x801ABCE8: addiu       $s0, $s0, -0x4C40
    ctx->r16 = ADD32(ctx->r16, -0X4C40);
    // 0x801ABCEC: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x801ABCF0: sw          $s1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r17;
    // 0x801ABCF4: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x801ABCF8: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x801ABCFC: jal         0x80005708
    // 0x801ABD00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_Push(rdram, ctx);
        goto after_0;
    // 0x801ABD00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x801ABD04: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801ABD08: lui         $at, 0xC3C8
    ctx->r1 = S32(0XC3C8 << 16);
    // 0x801ABD0C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801ABD10: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801ABD14: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801ABD18: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801ABD1C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801ABD20: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801ABD24: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x801ABD28: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x801ABD2C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x801ABD30: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x801ABD34: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x801ABD38: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x801ABD3C: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x801ABD40: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x801ABD44: jal         0x80006E3C
    // 0x801ABD48: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    Matrix_LookAt(rdram, ctx);
        goto after_1;
    // 0x801ABD48: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x801ABD4C: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x801ABD50: addiu       $s1, $s1, 0x7E64
    ctx->r17 = ADD32(ctx->r17, 0X7E64);
    // 0x801ABD54: jal         0x80006EB8
    // 0x801ABD58: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_2;
    // 0x801ABD58: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x801ABD5C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801ABD60: jal         0x800B8DD0
    // 0x801ABD64: addiu       $a1, $zero, 0x29
    ctx->r5 = ADD32(0, 0X29);
    RCP_SetupDL(rdram, ctx);
        goto after_3;
    // 0x801ABD64: addiu       $a1, $zero, 0x29
    ctx->r5 = ADD32(0, 0X29);
    after_3:
    // 0x801ABD68: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x801ABD6C: lui         $t8, 0xBA00
    ctx->r24 = S32(0XBA00 << 16);
    // 0x801ABD70: ori         $t8, $t8, 0xC02
    ctx->r24 = ctx->r24 | 0XC02;
    // 0x801ABD74: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801ABD78: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x801ABD7C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801ABD80: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x801ABD84: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x801ABD88: lui         $t0, 0xFA00
    ctx->r8 = S32(0XFA00 << 16);
    // 0x801ABD8C: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x801ABD90: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x801ABD94: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x801ABD98: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x801ABD9C: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x801ABDA0: andi        $t2, $t1, 0xFF
    ctx->r10 = ctx->r9 & 0XFF;
    // 0x801ABDA4: or          $t3, $t2, $at
    ctx->r11 = ctx->r10 | ctx->r1;
    // 0x801ABDA8: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x801ABDAC: jal         0x80005708
    // 0x801ABDB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_Push(rdram, ctx);
        goto after_4;
    // 0x801ABDB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x801ABDB4: lw          $t4, 0x58($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X58);
    // 0x801ABDB8: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x801ABDBC: addiu       $t6, $t6, 0x6B24
    ctx->r14 = ADD32(ctx->r14, 0X6B24);
    // 0x801ABDC0: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x801ABDC4: addu        $v0, $t5, $t6
    ctx->r2 = ADD32(ctx->r13, ctx->r14);
    // 0x801ABDC8: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x801ABDCC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801ABDD0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x801ABDD4: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x801ABDD8: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x801ABDDC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x801ABDE0: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801ABDE4: lui         $a2, 0xC20C
    ctx->r6 = S32(0XC20C << 16);
    // 0x801ABDE8: lui         $a3, 0xC3C8
    ctx->r7 = S32(0XC3C8 << 16);
    // 0x801ABDEC: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x801ABDF0: jal         0x80005B00
    // 0x801ABDF4: nop

    Matrix_Translate(rdram, ctx);
        goto after_5;
    // 0x801ABDF4: nop

    after_5:
    // 0x801ABDF8: lui         $a1, 0xBF32
    ctx->r5 = S32(0XBF32 << 16);
    // 0x801ABDFC: ori         $a1, $a1, 0xB8C2
    ctx->r5 = ctx->r5 | 0XB8C2;
    // 0x801ABE00: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x801ABE04: jal         0x80005FE0
    // 0x801ABE08: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateZ(rdram, ctx);
        goto after_6;
    // 0x801ABE08: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_6:
    // 0x801ABE0C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801ABE10: lwc1        $f0, 0x7B10($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X7B10);
    // 0x801ABE14: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801ABE18: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x801ABE1C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801ABE20: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801ABE24: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x801ABE28: jal         0x80005C34
    // 0x801ABE2C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_7;
    // 0x801ABE2C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_7:
    // 0x801ABE30: jal         0x80006EB8
    // 0x801ABE34: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_8;
    // 0x801ABE34: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_8:
    // 0x801ABE38: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x801ABE3C: lui         $a1, 0x501
    ctx->r5 = S32(0X501 << 16);
    // 0x801ABE40: addiu       $a1, $a1, -0x4A00
    ctx->r5 = ADD32(ctx->r5, -0X4A00);
    // 0x801ABE44: addiu       $t0, $v0, 0x8
    ctx->r8 = ADD32(ctx->r2, 0X8);
    // 0x801ABE48: sw          $t0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r8;
    // 0x801ABE4C: lui         $t1, 0x600
    ctx->r9 = S32(0X600 << 16);
    // 0x801ABE50: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x801ABE54: sw          $a1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r5;
    // 0x801ABE58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801ABE5C: jal         0x80005740
    // 0x801ABE60: sw          $a1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r5;
    Matrix_Pop(rdram, ctx);
        goto after_9;
    // 0x801ABE60: sw          $a1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r5;
    after_9:
    // 0x801ABE64: jal         0x80005708
    // 0x801ABE68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_Push(rdram, ctx);
        goto after_10;
    // 0x801ABE68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x801ABE6C: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x801ABE70: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801ABE74: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x801ABE78: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x801ABE7C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x801ABE80: lui         $a2, 0xC20C
    ctx->r6 = S32(0XC20C << 16);
    // 0x801ABE84: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x801ABE88: lui         $a3, 0xC3C8
    ctx->r7 = S32(0XC3C8 << 16);
    // 0x801ABE8C: cvt.s.w     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801ABE90: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x801ABE94: jal         0x80005B00
    // 0x801ABE98: nop

    Matrix_Translate(rdram, ctx);
        goto after_11;
    // 0x801ABE98: nop

    after_11:
    // 0x801ABE9C: lui         $a1, 0x3F32
    ctx->r5 = S32(0X3F32 << 16);
    // 0x801ABEA0: ori         $a1, $a1, 0xB8C2
    ctx->r5 = ctx->r5 | 0XB8C2;
    // 0x801ABEA4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x801ABEA8: jal         0x80005FE0
    // 0x801ABEAC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateZ(rdram, ctx);
        goto after_12;
    // 0x801ABEAC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_12:
    // 0x801ABEB0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801ABEB4: lwc1        $f0, 0x7B14($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X7B14);
    // 0x801ABEB8: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801ABEBC: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x801ABEC0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801ABEC4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801ABEC8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x801ABECC: jal         0x80005C34
    // 0x801ABED0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_13;
    // 0x801ABED0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_13:
    // 0x801ABED4: jal         0x80006EB8
    // 0x801ABED8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_14;
    // 0x801ABED8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_14:
    // 0x801ABEDC: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x801ABEE0: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x801ABEE4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801ABEE8: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x801ABEEC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801ABEF0: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x801ABEF4: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x801ABEF8: jal         0x80005740
    // 0x801ABEFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_15;
    // 0x801ABEFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x801ABF00: jal         0x80005740
    // 0x801ABF04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_16;
    // 0x801ABF04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x801ABF08: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x801ABF0C: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x801ABF10: lw          $s1, 0x38($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X38);
    // 0x801ABF14: jr          $ra
    // 0x801ABF18: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x801ABF18: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void Map_PlanetCleared_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A7F1C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801A7F20: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801A7F24: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801A7F28: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x801A7F2C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x801A7F30: lui         $t6, 0x801D
    ctx->r14 = S32(0X801D << 16);
    // 0x801A7F34: lw          $t6, -0x2680($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2680);
    // 0x801A7F38: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801A7F3C: lui         $a2, 0x801D
    ctx->r6 = S32(0X801D << 16);
    // 0x801A7F40: beq         $t6, $at, L_801A7F5C
    if (ctx->r14 == ctx->r1) {
        // 0x801A7F44: sll         $s1, $a3, 2
        ctx->r17 = S32(ctx->r7 << 2);
            goto L_801A7F5C;
    }
    // 0x801A7F44: sll         $s1, $a3, 2
    ctx->r17 = S32(ctx->r7 << 2);
    // 0x801A7F48: sll         $s1, $a3, 2
    ctx->r17 = S32(ctx->r7 << 2);
    // 0x801A7F4C: lui         $a2, 0x801D
    ctx->r6 = S32(0X801D << 16);
    // 0x801A7F50: addu        $a2, $a2, $s1
    ctx->r6 = ADD32(ctx->r6, ctx->r17);
    // 0x801A7F54: b           L_801A7F70
    // 0x801A7F58: lw          $a2, -0x2700($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X2700);
        goto L_801A7F70;
    // 0x801A7F58: lw          $a2, -0x2700($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X2700);
L_801A7F5C:
    // 0x801A7F5C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A7F60: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x801A7F64: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x801A7F68: lw          $a2, -0x267C($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X267C);
    // 0x801A7F6C: sw          $t7, -0x2700($at)
    MEM_W(-0X2700, ctx->r1) = ctx->r15;
L_801A7F70:
    // 0x801A7F70: beq         $a2, $zero, L_801A8088
    if (ctx->r6 == 0) {
        // 0x801A7F74: lui         $s0, 0x8013
        ctx->r16 = S32(0X8013 << 16);
            goto L_801A8088;
    }
    // 0x801A7F74: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x801A7F78: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x801A7F7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801A7F80: addiu       $a1, $zero, 0x43
    ctx->r5 = ADD32(0, 0X43);
    // 0x801A7F84: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x801A7F88: jal         0x800B8DD0
    // 0x801A7F8C: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x801A7F8C: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_0:
    // 0x801A7F90: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x801A7F94: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801A7F98: andi        $t0, $a2, 0xFF
    ctx->r8 = ctx->r6 & 0XFF;
    // 0x801A7F9C: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x801A7FA0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x801A7FA4: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x801A7FA8: or          $t1, $t0, $at
    ctx->r9 = ctx->r8 | ctx->r1;
    // 0x801A7FAC: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x801A7FB0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x801A7FB4: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x801A7FB8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801A7FBC: lui         $t3, 0xFB00
    ctx->r11 = S32(0XFB00 << 16);
    // 0x801A7FC0: lui         $t4, 0x5050
    ctx->r12 = S32(0X5050 << 16);
    // 0x801A7FC4: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x801A7FC8: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x801A7FCC: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x801A7FD0: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x801A7FD4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A7FD8: jal         0x80005708
    // 0x801A7FDC: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Push(rdram, ctx);
        goto after_1;
    // 0x801A7FDC: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_1:
    // 0x801A7FE0: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x801A7FE4: lui         $t6, 0x801D
    ctx->r14 = S32(0X801D << 16);
    // 0x801A7FE8: addiu       $t6, $t6, -0x1E20
    ctx->r14 = ADD32(ctx->r14, -0X1E20);
    // 0x801A7FEC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A7FF0: sll         $t5, $a3, 6
    ctx->r13 = S32(ctx->r7 << 6);
    // 0x801A7FF4: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    // 0x801A7FF8: jal         0x80005680
    // 0x801A7FFC: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Copy(rdram, ctx);
        goto after_2;
    // 0x801A7FFC: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_2:
    // 0x801A8000: jal         0x80006EB8
    // 0x801A8004: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_3;
    // 0x801A8004: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x801A8008: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801A800C: lui         $t9, 0x605
    ctx->r25 = S32(0X605 << 16);
    // 0x801A8010: addiu       $t9, $t9, -0x2980
    ctx->r25 = ADD32(ctx->r25, -0X2980);
    // 0x801A8014: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801A8018: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x801A801C: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x801A8020: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x801A8024: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x801A8028: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A802C: jal         0x80005740
    // 0x801A8030: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Pop(rdram, ctx);
        goto after_4;
    // 0x801A8030: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_4:
    // 0x801A8034: lui         $t0, 0x801D
    ctx->r8 = S32(0X801D << 16);
    // 0x801A8038: addiu       $t0, $t0, -0x1548
    ctx->r8 = ADD32(ctx->r8, -0X1548);
    // 0x801A803C: addu        $v0, $s1, $t0
    ctx->r2 = ADD32(ctx->r17, ctx->r8);
    // 0x801A8040: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x801A8044: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801A8048: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801A804C: lui         $t1, 0x801D
    ctx->r9 = S32(0X801D << 16);
    // 0x801A8050: lui         $t2, 0x801D
    ctx->r10 = S32(0X801D << 16);
    // 0x801A8054: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801A8058: addiu       $t2, $t2, -0x1508
    ctx->r10 = ADD32(ctx->r10, -0X1508);
    // 0x801A805C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x801A8060: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x801A8064: lw          $t1, -0x2680($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2680);
    // 0x801A8068: addu        $v0, $s1, $t2
    ctx->r2 = ADD32(ctx->r17, ctx->r10);
    // 0x801A806C: bnel        $t1, $zero, L_801A808C
    if (ctx->r9 != 0) {
        // 0x801A8070: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801A808C;
    }
    goto skip_0;
    // 0x801A8070: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x801A8074: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801A8078: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801A807C: nop

    // 0x801A8080: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801A8084: swc1        $f18, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f18.u32l;
L_801A8088:
    // 0x801A8088: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801A808C:
    // 0x801A808C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x801A8090: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801A8094: jr          $ra
    // 0x801A8098: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x801A8098: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void Option_VersusMenu_Cursor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019949C: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x801994A0: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x801994A4: sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // 0x801994A8: sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // 0x801994AC: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x801994B0: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x801994B4: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x801994B8: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x801994BC: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x801994C0: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x801994C4: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x801994C8: sdc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X30, ctx->r29);
    // 0x801994CC: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x801994D0: lui         $fp, 0x800E
    ctx->r30 = S32(0X800E << 16);
    // 0x801994D4: lui         $s4, 0x800C
    ctx->r20 = S32(0X800C << 16);
    // 0x801994D8: lui         $s2, 0x801C
    ctx->r18 = S32(0X801C << 16);
    // 0x801994DC: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x801994E0: addiu       $s2, $s2, -0x6C3C
    ctx->r18 = ADD32(ctx->r18, -0X6C3C);
    // 0x801994E4: addiu       $s4, $s4, 0x5D34
    ctx->r20 = ADD32(ctx->r20, 0X5D34);
    // 0x801994E8: addiu       $fp, $fp, -0x2768
    ctx->r30 = ADD32(ctx->r30, -0X2768);
    // 0x801994EC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_801994F0:
    // 0x801994F0: lbu         $t7, 0x0($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0X0);
    // 0x801994F4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801994F8: sllv        $s3, $t6, $s1
    ctx->r19 = S32(ctx->r14 << (ctx->r17 & 31));
    // 0x801994FC: and         $t8, $t7, $s3
    ctx->r24 = ctx->r15 & ctx->r19;
    // 0x80199500: bne         $t8, $zero, L_80199598
    if (ctx->r24 != 0) {
        // 0x80199504: lui         $t9, 0x801C
        ctx->r25 = S32(0X801C << 16);
            goto L_80199598;
    }
    // 0x80199504: lui         $t9, 0x801C
    ctx->r25 = S32(0X801C << 16);
    // 0x80199508: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x8019950C: lui         $t2, 0x801C
    ctx->r10 = S32(0X801C << 16);
    // 0x80199510: addiu       $t2, $t2, -0x6C60
    ctx->r10 = ADD32(ctx->r10, -0X6C60);
    // 0x80199514: addiu       $t0, $t0, -0x12C4
    ctx->r8 = ADD32(ctx->r8, -0X12C4);
    // 0x80199518: addiu       $t9, $t9, -0x6CA8
    ctx->r25 = ADD32(ctx->r25, -0X6CA8);
    // 0x8019951C: sll         $v0, $s1, 2
    ctx->r2 = S32(ctx->r17 << 2);
    // 0x80199520: sll         $t1, $s1, 3
    ctx->r9 = S32(ctx->r17 << 3);
    // 0x80199524: addu        $s5, $t1, $t2
    ctx->r21 = ADD32(ctx->r9, ctx->r10);
    // 0x80199528: addu        $a0, $v0, $t9
    ctx->r4 = ADD32(ctx->r2, ctx->r25);
    // 0x8019952C: jal         0x8019C824
    // 0x80199530: addu        $s0, $v0, $t0
    ctx->r16 = ADD32(ctx->r2, ctx->r8);
    Option_Color_FlashRed(rdram, ctx);
        goto after_0;
    // 0x80199530: addu        $s0, $v0, $t0
    ctx->r16 = ADD32(ctx->r2, ctx->r8);
    after_0:
    // 0x80199534: addiu       $t3, $zero, 0x14
    ctx->r11 = ADD32(0, 0X14);
    // 0x80199538: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x8019953C: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x80199540: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x80199544: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80199548: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8019954C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80199550: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80199554: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80199558: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8019955C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80199560: jal         0x8019C418
    // 0x80199564: sw          $s5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r21;
    Option_Input_MoveCursor_Y(rdram, ctx);
        goto after_1;
    // 0x80199564: sw          $s5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r21;
    after_1:
    // 0x80199568: beq         $v0, $zero, L_80199598
    if (ctx->r2 == 0) {
        // 0x8019956C: lui         $a0, 0x4900
        ctx->r4 = S32(0X4900 << 16);
            goto L_80199598;
    }
    // 0x8019956C: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x80199570: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x80199574: addiu       $t6, $t6, 0x5D3C
    ctx->r14 = ADD32(ctx->r14, 0X5D3C);
    // 0x80199578: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x8019957C: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x80199580: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80199584: ori         $a0, $a0, 0x2
    ctx->r4 = ctx->r4 | 0X2;
    // 0x80199588: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8019958C: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    // 0x80199590: jal         0x80019218
    // 0x80199594: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    Audio_PlaySfx(rdram, ctx);
        goto after_2;
    // 0x80199594: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    after_2:
L_80199598:
    // 0x80199598: lhu         $v0, 0x0($fp)
    ctx->r2 = MEM_HU(ctx->r30, 0X0);
    // 0x8019959C: andi        $t7, $v0, 0x8000
    ctx->r15 = ctx->r2 & 0X8000;
    // 0x801995A0: beql        $t7, $zero, L_8019969C
    if (ctx->r15 == 0) {
        // 0x801995A4: andi        $t1, $v0, 0x4000
        ctx->r9 = ctx->r2 & 0X4000;
            goto L_8019969C;
    }
    goto skip_0;
    // 0x801995A4: andi        $t1, $v0, 0x4000
    ctx->r9 = ctx->r2 & 0X4000;
    skip_0:
    // 0x801995A8: lbu         $v1, 0x0($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0X0);
    // 0x801995AC: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x801995B0: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x801995B4: bne         $v1, $at, L_80199608
    if (ctx->r3 != ctx->r1) {
        // 0x801995B8: ori         $a0, $a0, 0x3
        ctx->r4 = ctx->r4 | 0X3;
            goto L_80199608;
    }
    // 0x801995B8: ori         $a0, $a0, 0x3
    ctx->r4 = ctx->r4 | 0X3;
    // 0x801995BC: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x801995C0: addiu       $t8, $t8, 0x5D3C
    ctx->r24 = ADD32(ctx->r24, 0X5D3C);
    // 0x801995C4: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x801995C8: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x801995CC: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x801995D0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x801995D4: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    // 0x801995D8: jal         0x80019218
    // 0x801995DC: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    Audio_PlaySfx(rdram, ctx);
        goto after_3;
    // 0x801995DC: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    after_3:
    // 0x801995E0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801995E4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801995E8: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801995EC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801995F0: addiu       $v0, $v0, -0x6ED4
    ctx->r2 = ADD32(ctx->r2, -0X6ED4);
    // 0x801995F4: swc1        $f4, -0x6E14($at)
    MEM_W(-0X6E14, ctx->r1) = ctx->f4.u32l;
    // 0x801995F8: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x801995FC: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80199600: b           L_80199758
    // 0x80199604: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
        goto L_80199758;
    // 0x80199604: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
L_80199608:
    // 0x80199608: and         $t1, $v1, $s3
    ctx->r9 = ctx->r3 & ctx->r19;
    // 0x8019960C: bnel        $t1, $zero, L_8019969C
    if (ctx->r9 != 0) {
        // 0x80199610: andi        $t1, $v0, 0x4000
        ctx->r9 = ctx->r2 & 0X4000;
            goto L_8019969C;
    }
    goto skip_1;
    // 0x80199610: andi        $t1, $v0, 0x4000
    ctx->r9 = ctx->r2 & 0X4000;
    skip_1:
    // 0x80199614: sll         $v0, $s1, 2
    ctx->r2 = S32(ctx->r17 << 2);
    // 0x80199618: lui         $t2, 0x800C
    ctx->r10 = S32(0X800C << 16);
    // 0x8019961C: lui         $t3, 0x801C
    ctx->r11 = S32(0X801C << 16);
    // 0x80199620: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x80199624: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x80199628: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x8019962C: addiu       $t6, $t6, -0x6CB8
    ctx->r14 = ADD32(ctx->r14, -0X6CB8);
    // 0x80199630: addiu       $t5, $t5, 0x7888
    ctx->r13 = ADD32(ctx->r13, 0X7888);
    // 0x80199634: addiu       $t4, $t4, -0x12C4
    ctx->r12 = ADD32(ctx->r12, -0X12C4);
    // 0x80199638: addiu       $t3, $t3, -0x6CA8
    ctx->r11 = ADD32(ctx->r11, -0X6CA8);
    // 0x8019963C: addiu       $t2, $t2, 0x5D3C
    ctx->r10 = ADD32(ctx->r10, 0X5D3C);
    // 0x80199640: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x80199644: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x80199648: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x8019964C: ori         $a0, $a0, 0x3
    ctx->r4 = ctx->r4 | 0X3;
    // 0x80199650: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80199654: addu        $s5, $v0, $t3
    ctx->r21 = ADD32(ctx->r2, ctx->r11);
    // 0x80199658: addu        $s0, $v0, $t4
    ctx->r16 = ADD32(ctx->r2, ctx->r12);
    // 0x8019965C: addu        $s6, $v0, $t5
    ctx->r22 = ADD32(ctx->r2, ctx->r13);
    // 0x80199660: addu        $s7, $v0, $t6
    ctx->r23 = ADD32(ctx->r2, ctx->r14);
    // 0x80199664: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80199668: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    // 0x8019966C: jal         0x80019218
    // 0x80199670: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    Audio_PlaySfx(rdram, ctx);
        goto after_4;
    // 0x80199670: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    after_4:
    // 0x80199674: lbu         $t9, 0x0($s2)
    ctx->r25 = MEM_BU(ctx->r18, 0X0);
    // 0x80199678: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x8019967C: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x80199680: or          $t0, $t9, $s3
    ctx->r8 = ctx->r25 | ctx->r19;
    // 0x80199684: swc1        $f20, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->f20.u32l;
    // 0x80199688: sw          $t8, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r24;
    // 0x8019968C: sb          $t0, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r8;
    // 0x80199690: lhu         $v0, 0x0($fp)
    ctx->r2 = MEM_HU(ctx->r30, 0X0);
    // 0x80199694: sw          $t7, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r15;
    // 0x80199698: andi        $t1, $v0, 0x4000
    ctx->r9 = ctx->r2 & 0X4000;
L_8019969C:
    // 0x8019969C: beql        $t1, $zero, L_8019974C
    if (ctx->r9 == 0) {
        // 0x801996A0: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8019974C;
    }
    goto skip_2;
    // 0x801996A0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_2:
    // 0x801996A4: lbu         $t2, 0x0($s2)
    ctx->r10 = MEM_BU(ctx->r18, 0X0);
    // 0x801996A8: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x801996AC: ori         $a0, $a0, 0x101D
    ctx->r4 = ctx->r4 | 0X101D;
    // 0x801996B0: and         $t3, $t2, $s3
    ctx->r11 = ctx->r10 & ctx->r19;
    // 0x801996B4: beq         $t3, $zero, L_801996F0
    if (ctx->r11 == 0) {
        // 0x801996B8: lui         $a1, 0x800C
        ctx->r5 = S32(0X800C << 16);
            goto L_801996F0;
    }
    // 0x801996B8: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x801996BC: lui         $t4, 0x800C
    ctx->r12 = S32(0X800C << 16);
    // 0x801996C0: addiu       $t4, $t4, 0x5D3C
    ctx->r12 = ADD32(ctx->r12, 0X5D3C);
    // 0x801996C4: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x801996C8: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x801996CC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x801996D0: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    // 0x801996D4: jal         0x80019218
    // 0x801996D8: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    Audio_PlaySfx(rdram, ctx);
        goto after_5;
    // 0x801996D8: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    after_5:
    // 0x801996DC: lbu         $t5, 0x0($s2)
    ctx->r13 = MEM_BU(ctx->r18, 0X0);
    // 0x801996E0: xori        $t6, $s3, 0xF
    ctx->r14 = ctx->r19 ^ 0XF;
    // 0x801996E4: and         $t7, $t5, $t6
    ctx->r15 = ctx->r13 & ctx->r14;
    // 0x801996E8: b           L_80199748
    // 0x801996EC: sb          $t7, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r15;
        goto L_80199748;
    // 0x801996EC: sb          $t7, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r15;
L_801996F0:
    // 0x801996F0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801996F4: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    // 0x801996F8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801996FC: jal         0x8001D444
    // 0x80199700: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    Audio_PlaySequence(rdram, ctx);
        goto after_6;
    // 0x80199700: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_6:
    // 0x80199704: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x80199708: addiu       $t8, $t8, 0x5D3C
    ctx->r24 = ADD32(ctx->r24, 0X5D3C);
    // 0x8019970C: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x80199710: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x80199714: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x80199718: ori         $a0, $a0, 0x21
    ctx->r4 = ctx->r4 | 0X21;
    // 0x8019971C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80199720: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80199724: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    // 0x80199728: jal         0x80019218
    // 0x8019972C: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    Audio_PlaySfx(rdram, ctx);
        goto after_7;
    // 0x8019972C: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    after_7:
    // 0x80199730: jal         0x8019B8A0
    // 0x80199734: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    Option_VsBackToSubMenu(rdram, ctx);
        goto after_8;
    // 0x80199734: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_8:
    // 0x80199738: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8019973C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80199740: b           L_80199758
    // 0x80199744: sw          $t9, -0x6DB8($at)
    MEM_W(-0X6DB8, ctx->r1) = ctx->r25;
        goto L_80199758;
    // 0x80199744: sw          $t9, -0x6DB8($at)
    MEM_W(-0X6DB8, ctx->r1) = ctx->r25;
L_80199748:
    // 0x80199748: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8019974C:
    // 0x8019974C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80199750: bne         $s1, $at, L_801994F0
    if (ctx->r17 != ctx->r1) {
        // 0x80199754: addiu       $fp, $fp, 0x6
        ctx->r30 = ADD32(ctx->r30, 0X6);
            goto L_801994F0;
    }
    // 0x80199754: addiu       $fp, $fp, 0x6
    ctx->r30 = ADD32(ctx->r30, 0X6);
L_80199758:
    // 0x80199758: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x8019975C: ldc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X30);
    // 0x80199760: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x80199764: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x80199768: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x8019976C: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x80199770: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x80199774: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x80199778: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x8019977C: lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X54);
    // 0x80199780: lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X58);
    // 0x80199784: jr          $ra
    // 0x80199788: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80199788: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void Option_Invoice_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019E030: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8019E034: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x8019E038: addiu       $t0, $t0, -0x6ED4
    ctx->r8 = ADD32(ctx->r8, -0X6ED4);
    // 0x8019E03C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8019E040: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x8019E044: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8019E048: addiu       $t6, $zero, 0x1E
    ctx->r14 = ADD32(0, 0X1E);
    // 0x8019E04C: beq         $v1, $zero, L_8019E080
    if (ctx->r3 == 0) {
        // 0x8019E050: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8019E080;
    }
    // 0x8019E050: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8019E054: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8019E058: beq         $v0, $v1, L_8019E0C8
    if (ctx->r2 == ctx->r3) {
        // 0x8019E05C: lui         $t8, 0x801C
        ctx->r24 = S32(0X801C << 16);
            goto L_8019E0C8;
    }
    // 0x8019E05C: lui         $t8, 0x801C
    ctx->r24 = S32(0X801C << 16);
    // 0x8019E060: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8019E064: beq         $v0, $a0, L_8019E1AC
    if (ctx->r2 == ctx->r4) {
        // 0x8019E068: lui         $t7, 0x801C
        ctx->r15 = S32(0X801C << 16);
            goto L_8019E1AC;
    }
    // 0x8019E068: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x8019E06C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8019E070: beq         $v0, $at, L_8019E240
    if (ctx->r2 == ctx->r1) {
        // 0x8019E074: lui         $t7, 0x801C
        ctx->r15 = S32(0X801C << 16);
            goto L_8019E240;
    }
    // 0x8019E074: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x8019E078: b           L_8019E278
    // 0x8019E07C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8019E278;
    // 0x8019E07C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8019E080:
    // 0x8019E080: sw          $zero, -0x7BF0($at)
    MEM_W(-0X7BF0, ctx->r1) = 0;
    // 0x8019E084: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8019E088: sh          $zero, 0x1A36($at)
    MEM_H(0X1A36, ctx->r1) = 0;
    // 0x8019E08C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8019E090: sw          $zero, -0x7CB8($at)
    MEM_W(-0X7CB8, ctx->r1) = 0;
    // 0x8019E094: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8019E098: sw          $zero, -0x7CB0($at)
    MEM_W(-0X7CB0, ctx->r1) = 0;
    // 0x8019E09C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8019E0A0: sw          $zero, -0x7CAC($at)
    MEM_W(-0X7CAC, ctx->r1) = 0;
    // 0x8019E0A4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8019E0A8: sw          $zero, -0x7CC0($at)
    MEM_W(-0X7CC0, ctx->r1) = 0;
    // 0x8019E0AC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019E0B0: sw          $zero, -0x6F70($at)
    MEM_W(-0X6F70, ctx->r1) = 0;
    // 0x8019E0B4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019E0B8: sw          $t6, -0x6E88($at)
    MEM_W(-0X6E88, ctx->r1) = ctx->r14;
    // 0x8019E0BC: addiu       $t7, $v1, 0x1
    ctx->r15 = ADD32(ctx->r3, 0X1);
    // 0x8019E0C0: b           L_8019E274
    // 0x8019E0C4: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
        goto L_8019E274;
    // 0x8019E0C4: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
L_8019E0C8:
    // 0x8019E0C8: lw          $t8, -0x6E88($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X6E88);
    // 0x8019E0CC: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8019E0D0: bnel        $t8, $zero, L_8019E278
    if (ctx->r24 != 0) {
        // 0x8019E0D4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8019E278;
    }
    goto skip_0;
    // 0x8019E0D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8019E0D8: lw          $v0, 0x1714($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1714);
    // 0x8019E0DC: ori         $at, $zero, 0xC350
    ctx->r1 = 0 | 0XC350;
    // 0x8019E0E0: sll         $t9, $v0, 6
    ctx->r25 = S32(ctx->r2 << 6);
    // 0x8019E0E4: slt         $at, $t9, $at
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8019E0E8: bne         $at, $zero, L_8019E148
    if (ctx->r1 != 0) {
        // 0x8019E0EC: or          $v0, $t9, $zero
        ctx->r2 = ctx->r25 | 0;
            goto L_8019E148;
    }
    // 0x8019E0EC: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x8019E0F0: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8019E0F4: ori         $at, $at, 0x1170
    ctx->r1 = ctx->r1 | 0X1170;
    // 0x8019E0F8: slt         $at, $t9, $at
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8019E0FC: beq         $at, $zero, L_8019E148
    if (ctx->r1 == 0) {
        // 0x8019E100: lui         $a3, 0x800C
        ctx->r7 = S32(0X800C << 16);
            goto L_8019E148;
    }
    // 0x8019E100: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8019E104: lui         $t1, 0x800C
    ctx->r9 = S32(0X800C << 16);
    // 0x8019E108: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8019E10C: addiu       $t1, $t1, 0x5D3C
    ctx->r9 = ADD32(ctx->r9, 0X5D3C);
    // 0x8019E110: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x8019E114: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x8019E118: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x8019E11C: ori         $a0, $a0, 0x32
    ctx->r4 = ctx->r4 | 0X32;
    // 0x8019E120: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x8019E124: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8019E128: jal         0x80019218
    // 0x8019E12C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_0;
    // 0x8019E12C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_0:
    // 0x8019E130: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8019E134: lw          $v0, 0x1714($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1714);
    // 0x8019E138: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x8019E13C: addiu       $t0, $t0, -0x6ED4
    ctx->r8 = ADD32(ctx->r8, -0X6ED4);
    // 0x8019E140: sll         $t2, $v0, 6
    ctx->r10 = S32(ctx->r2 << 6);
    // 0x8019E144: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
L_8019E148:
    // 0x8019E148: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8019E14C: ori         $at, $at, 0x1170
    ctx->r1 = ctx->r1 | 0X1170;
    // 0x8019E150: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8019E154: slt         $at, $v0, $at
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8019E158: bne         $at, $zero, L_8019E190
    if (ctx->r1 != 0) {
        // 0x8019E15C: addiu       $a3, $a3, 0x5D34
        ctx->r7 = ADD32(ctx->r7, 0X5D34);
            goto L_8019E190;
    }
    // 0x8019E15C: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8019E160: lui         $t3, 0x800C
    ctx->r11 = S32(0X800C << 16);
    // 0x8019E164: addiu       $t3, $t3, 0x5D3C
    ctx->r11 = ADD32(ctx->r11, 0X5D3C);
    // 0x8019E168: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x8019E16C: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x8019E170: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x8019E174: ori         $a0, $a0, 0x33
    ctx->r4 = ctx->r4 | 0X33;
    // 0x8019E178: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x8019E17C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8019E180: jal         0x80019218
    // 0x8019E184: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    Audio_PlaySfx(rdram, ctx);
        goto after_1;
    // 0x8019E184: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_1:
    // 0x8019E188: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x8019E18C: addiu       $t0, $t0, -0x6ED4
    ctx->r8 = ADD32(ctx->r8, -0X6ED4);
L_8019E190:
    // 0x8019E190: addiu       $t4, $zero, 0x14
    ctx->r12 = ADD32(0, 0X14);
    // 0x8019E194: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019E198: sw          $t4, -0x6E88($at)
    MEM_W(-0X6E88, ctx->r1) = ctx->r12;
    // 0x8019E19C: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x8019E1A0: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8019E1A4: b           L_8019E274
    // 0x8019E1A8: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
        goto L_8019E274;
    // 0x8019E1A8: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
L_8019E1AC:
    // 0x8019E1AC: lw          $t7, -0x6E88($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X6E88);
    // 0x8019E1B0: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x8019E1B4: bnel        $t7, $zero, L_8019E278
    if (ctx->r15 != 0) {
        // 0x8019E1B8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8019E278;
    }
    goto skip_1;
    // 0x8019E1B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8019E1BC: lw          $t8, 0x7AF8($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7AF8);
    // 0x8019E1C0: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8019E1C4: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8019E1C8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8019E1CC: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8019E1D0: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x8019E1D4: addu        $t1, $t1, $t9
    ctx->r9 = ADD32(ctx->r9, ctx->r25);
    // 0x8019E1D8: lhu         $t1, -0x2768($t1)
    ctx->r9 = MEM_HU(ctx->r9, -0X2768);
    // 0x8019E1DC: lui         $a0, 0x1903
    ctx->r4 = S32(0X1903 << 16);
    // 0x8019E1E0: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8019E1E4: andi        $t2, $t1, 0xD00E
    ctx->r10 = ctx->r9 & 0XD00E;
    // 0x8019E1E8: beq         $t2, $zero, L_8019E274
    if (ctx->r10 == 0) {
        // 0x8019E1EC: ori         $a0, $a0, 0x1083
        ctx->r4 = ctx->r4 | 0X1083;
            goto L_8019E274;
    }
    // 0x8019E1EC: ori         $a0, $a0, 0x1083
    ctx->r4 = ctx->r4 | 0X1083;
    // 0x8019E1F0: lui         $t3, 0x800C
    ctx->r11 = S32(0X800C << 16);
    // 0x8019E1F4: addiu       $t3, $t3, 0x5D3C
    ctx->r11 = ADD32(ctx->r11, 0X5D3C);
    // 0x8019E1F8: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x8019E1FC: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x8019E200: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x8019E204: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8019E208: jal         0x80019218
    // 0x8019E20C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    Audio_PlaySfx(rdram, ctx);
        goto after_2;
    // 0x8019E20C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_2:
    // 0x8019E210: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8019E214: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019E218: sw          $v1, -0x6F70($at)
    MEM_W(-0X6F70, ctx->r1) = ctx->r3;
    // 0x8019E21C: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x8019E220: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019E224: addiu       $t4, $zero, 0x3C
    ctx->r12 = ADD32(0, 0X3C);
    // 0x8019E228: addiu       $t0, $t0, -0x6ED4
    ctx->r8 = ADD32(ctx->r8, -0X6ED4);
    // 0x8019E22C: sw          $t4, -0x6E88($at)
    MEM_W(-0X6E88, ctx->r1) = ctx->r12;
    // 0x8019E230: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x8019E234: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8019E238: b           L_8019E274
    // 0x8019E23C: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
        goto L_8019E274;
    // 0x8019E23C: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
L_8019E240:
    // 0x8019E240: lw          $t7, -0x6E88($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X6E88);
    // 0x8019E244: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8019E248: bnel        $t7, $zero, L_8019E278
    if (ctx->r15 != 0) {
        // 0x8019E24C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8019E278;
    }
    goto skip_2;
    // 0x8019E24C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x8019E250: sw          $zero, -0x7BF0($at)
    MEM_W(-0X7BF0, ctx->r1) = 0;
    // 0x8019E254: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019E258: sw          $v1, 0x7834($at)
    MEM_W(0X7834, ctx->r1) = ctx->r3;
    // 0x8019E25C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019E260: sw          $zero, 0x7898($at)
    MEM_W(0X7898, ctx->r1) = 0;
    // 0x8019E264: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8019E268: sh          $a0, 0x1AA0($at)
    MEM_H(0X1AA0, ctx->r1) = ctx->r4;
    // 0x8019E26C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8019E270: sw          $zero, 0x1714($at)
    MEM_W(0X1714, ctx->r1) = 0;
L_8019E274:
    // 0x8019E274: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8019E278:
    // 0x8019E278: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8019E27C: jr          $ra
    // 0x8019E280: nop

    return;
    // 0x8019E280: nop

;}
RECOMP_FUNC void Option_Data_Setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80196260: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80196264: addiu       $v0, $v0, -0x6CD0
    ctx->r2 = ADD32(ctx->r2, -0X6CD0);
    // 0x80196268: addiu       $t6, $zero, 0x320
    ctx->r14 = ADD32(0, 0X320);
    // 0x8019626C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80196270: sw          $t6, -0x7BF0($at)
    MEM_W(-0X7BF0, ctx->r1) = ctx->r14;
    // 0x80196274: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80196278: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019627C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80196280: swc1        $f4, -0x6E1C($at)
    MEM_W(-0X6E1C, ctx->r1) = ctx->f4.u32l;
    // 0x80196284: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x80196288: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8019628C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80196290: sw          $zero, -0x6E40($at)
    MEM_W(-0X6E40, ctx->r1) = 0;
    // 0x80196294: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80196298: sw          $zero, -0x6E34($at)
    MEM_W(-0X6E34, ctx->r1) = 0;
    // 0x8019629C: jr          $ra
    // 0x801962A0: nop

    return;
    // 0x801962A0: nop

;}
