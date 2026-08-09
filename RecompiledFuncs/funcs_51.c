#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void Map_PositionPlanets(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A6694: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x801A6698: sdc1        $f22, 0x40($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X40, ctx->r29);
    // 0x801A669C: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x801A66A0: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x801A66A4: sw          $fp, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r30;
    // 0x801A66A8: sw          $s7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r23;
    // 0x801A66AC: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x801A66B0: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x801A66B4: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x801A66B8: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x801A66BC: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x801A66C0: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x801A66C4: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x801A66C8: sdc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X38, ctx->r29);
    // 0x801A66CC: lui         $s1, 0x801B
    ctx->r17 = S32(0X801B << 16);
    // 0x801A66D0: lui         $s2, 0x801D
    ctx->r18 = S32(0X801D << 16);
    // 0x801A66D4: lui         $s3, 0x801D
    ctx->r19 = S32(0X801D << 16);
    // 0x801A66D8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A66DC: lui         $fp, 0x801D
    ctx->r30 = S32(0X801D << 16);
    // 0x801A66E0: lui         $s7, 0x801D
    ctx->r23 = S32(0X801D << 16);
    // 0x801A66E4: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x801A66E8: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x801A66EC: swc1        $f22, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f22.u32l;
    // 0x801A66F0: swc1        $f22, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f22.u32l;
    // 0x801A66F4: swc1        $f22, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f22.u32l;
    // 0x801A66F8: addiu       $s0, $s0, -0x4C40
    ctx->r16 = ADD32(ctx->r16, -0X4C40);
    // 0x801A66FC: addiu       $s4, $s4, 0x7E64
    ctx->r20 = ADD32(ctx->r20, 0X7E64);
    // 0x801A6700: addiu       $s7, $s7, -0x260C
    ctx->r23 = ADD32(ctx->r23, -0X260C);
    // 0x801A6704: addiu       $fp, $fp, -0x2608
    ctx->r30 = ADD32(ctx->r30, -0X2608);
    // 0x801A6708: lwc1        $f20, 0x793C($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X793C);
    // 0x801A670C: addiu       $s3, $s3, -0x16A0
    ctx->r19 = ADD32(ctx->r19, -0X16A0);
    // 0x801A6710: addiu       $s2, $s2, -0x25A0
    ctx->r18 = ADD32(ctx->r18, -0X25A0);
    // 0x801A6714: addiu       $s1, $s1, -0xB60
    ctx->r17 = ADD32(ctx->r17, -0XB60);
    // 0x801A6718: addiu       $s6, $sp, 0x88
    ctx->r22 = ADD32(ctx->r29, 0X88);
    // 0x801A671C: addiu       $s5, $sp, 0x7C
    ctx->r21 = ADD32(ctx->r29, 0X7C);
L_801A6720:
    // 0x801A6720: jal         0x80005708
    // 0x801A6724: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_Push(rdram, ctx);
        goto after_0;
    // 0x801A6724: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x801A6728: lwc1        $f4, 0x1C($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x801A672C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x801A6730: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801A6734: mul.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x801A6738: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x801A673C: jal         0x80005E90
    // 0x801A6740: nop

    Matrix_RotateY(rdram, ctx);
        goto after_1;
    // 0x801A6740: nop

    after_1:
    // 0x801A6744: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x801A6748: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801A674C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801A6750: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x801A6754: lw          $a1, 0x4($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X4);
    // 0x801A6758: jal         0x80005B00
    // 0x801A675C: lw          $a2, 0x8($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X8);
    Matrix_Translate(rdram, ctx);
        goto after_2;
    // 0x801A675C: lw          $a2, 0x8($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X8);
    after_2:
    // 0x801A6760: lwc1        $f8, 0x1C($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x801A6764: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x801A6768: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801A676C: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x801A6770: mul.s       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x801A6774: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x801A6778: jal         0x80005E90
    // 0x801A677C: nop

    Matrix_RotateY(rdram, ctx);
        goto after_3;
    // 0x801A677C: nop

    after_3:
    // 0x801A6780: jal         0x801AD048
    // 0x801A6784: nop

    Map_CamMatrixRot(rdram, ctx);
        goto after_4;
    // 0x801A6784: nop

    after_4:
    // 0x801A6788: jal         0x80006EB8
    // 0x801A678C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_5;
    // 0x801A678C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_5:
    // 0x801A6790: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x801A6794: jal         0x80005680
    // 0x801A6798: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    Matrix_Copy(rdram, ctx);
        goto after_6;
    // 0x801A6798: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    after_6:
    // 0x801A679C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x801A67A0: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x801A67A4: jal         0x80006970
    // 0x801A67A8: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    Matrix_MultVec3f(rdram, ctx);
        goto after_7;
    // 0x801A67A8: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_7:
    // 0x801A67AC: lwc1        $f18, 0x88($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X88);
    // 0x801A67B0: lwc1        $f4, 0x8C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x801A67B4: lwc1        $f6, 0x90($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X90);
    // 0x801A67B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801A67BC: swc1        $f18, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f18.u32l;
    // 0x801A67C0: swc1        $f4, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f4.u32l;
    // 0x801A67C4: jal         0x80005740
    // 0x801A67C8: swc1        $f6, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->f6.u32l;
    Matrix_Pop(rdram, ctx);
        goto after_8;
    // 0x801A67C8: swc1        $f6, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->f6.u32l;
    after_8:
    // 0x801A67CC: jal         0x80005708
    // 0x801A67D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_Push(rdram, ctx);
        goto after_9;
    // 0x801A67D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x801A67D4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A67D8: lwc1        $f8, -0x2600($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2600);
    // 0x801A67DC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A67E0: lwc1        $f10, -0x25FC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X25FC);
    // 0x801A67E4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A67E8: lwc1        $f16, -0x25F8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X25F8);
    // 0x801A67EC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A67F0: lwc1        $f18, -0x25E0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X25E0);
    // 0x801A67F4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A67F8: lwc1        $f4, -0x25DC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X25DC);
    // 0x801A67FC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A6800: lwc1        $f6, -0x25D8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X25D8);
    // 0x801A6804: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801A6808: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801A680C: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x801A6810: lw          $a3, -0x2604($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X2604);
    // 0x801A6814: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x801A6818: lw          $a1, 0x0($s7)
    ctx->r5 = MEM_W(ctx->r23, 0X0);
    // 0x801A681C: lw          $a2, 0x0($fp)
    ctx->r6 = MEM_W(ctx->r30, 0X0);
    // 0x801A6820: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x801A6824: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    // 0x801A6828: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    // 0x801A682C: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    // 0x801A6830: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x801A6834: jal         0x80006E3C
    // 0x801A6838: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    Matrix_LookAt(rdram, ctx);
        goto after_10;
    // 0x801A6838: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    after_10:
    // 0x801A683C: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801A6840: lui         $a2, 0x801D
    ctx->r6 = S32(0X801D << 16);
    // 0x801A6844: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801A6848: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801A684C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x801A6850: lw          $a3, -0x15A0($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X15A0);
    // 0x801A6854: lw          $a2, -0x15A4($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X15A4);
    // 0x801A6858: lw          $a1, -0x15A8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X15A8);
    // 0x801A685C: jal         0x80005B00
    // 0x801A6860: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_11;
    // 0x801A6860: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_11:
    // 0x801A6864: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x801A6868: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x801A686C: jal         0x80005754
    // 0x801A6870: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_Mult(rdram, ctx);
        goto after_12;
    // 0x801A6870: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_12:
    // 0x801A6874: jal         0x80006EB8
    // 0x801A6878: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_13;
    // 0x801A6878: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_13:
    // 0x801A687C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x801A6880: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x801A6884: jal         0x80006970
    // 0x801A6888: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    Matrix_MultVec3f(rdram, ctx);
        goto after_14;
    // 0x801A6888: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_14:
    // 0x801A688C: jal         0x80005740
    // 0x801A6890: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_15;
    // 0x801A6890: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x801A6894: lui         $t9, 0x801D
    ctx->r25 = S32(0X801D << 16);
    // 0x801A6898: addiu       $t9, $t9, -0x15EC
    ctx->r25 = ADD32(ctx->r25, -0X15EC);
    // 0x801A689C: addiu       $s3, $s3, 0xC
    ctx->r19 = ADD32(ctx->r19, 0XC);
    // 0x801A68A0: addiu       $s1, $s1, 0x38
    ctx->r17 = ADD32(ctx->r17, 0X38);
    // 0x801A68A4: bne         $s3, $t9, L_801A6720
    if (ctx->r19 != ctx->r25) {
        // 0x801A68A8: addiu       $s2, $s2, 0x40
        ctx->r18 = ADD32(ctx->r18, 0X40);
            goto L_801A6720;
    }
    // 0x801A68A8: addiu       $s2, $s2, 0x40
    ctx->r18 = ADD32(ctx->r18, 0X40);
    // 0x801A68AC: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x801A68B0: ldc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X38);
    // 0x801A68B4: ldc1        $f22, 0x40($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X40);
    // 0x801A68B8: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x801A68BC: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x801A68C0: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x801A68C4: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x801A68C8: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x801A68CC: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x801A68D0: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x801A68D4: lw          $s7, 0x64($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X64);
    // 0x801A68D8: lw          $fp, 0x68($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X68);
    // 0x801A68DC: jr          $ra
    // 0x801A68E0: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x801A68E0: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void Map_PathPlanet_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801AA778: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x801AA77C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x801AA780: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x801AA784: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x801AA788: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x801AA78C: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x801AA790: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x801AA794: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x801AA798: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x801AA79C: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x801AA7A0: lw          $t6, 0x7834($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7834);
    // 0x801AA7A4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x801AA7A8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x801AA7AC: bne         $t6, $at, L_801AA7CC
    if (ctx->r14 != ctx->r1) {
        // 0x801AA7B0: lw          $t9, 0x4C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X4C);
            goto L_801AA7CC;
    }
    // 0x801AA7B0: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x801AA7B4: lui         $t8, 0x801D
    ctx->r24 = S32(0X801D << 16);
    // 0x801AA7B8: lw          $t8, -0x26AC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X26AC);
    // 0x801AA7BC: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x801AA7C0: bnel        $t7, $t8, L_801AA7D0
    if (ctx->r15 != ctx->r24) {
        // 0x801AA7C4: sltiu       $at, $t9, 0xF
        ctx->r1 = ctx->r25 < 0XF ? 1 : 0;
            goto L_801AA7D0;
    }
    goto skip_0;
    // 0x801AA7C4: sltiu       $at, $t9, 0xF
    ctx->r1 = ctx->r25 < 0XF ? 1 : 0;
    skip_0:
    // 0x801AA7C8: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
L_801AA7CC:
    // 0x801AA7CC: sltiu       $at, $t9, 0xF
    ctx->r1 = ctx->r25 < 0XF ? 1 : 0;
L_801AA7D0:
    // 0x801AA7D0: beq         $at, $zero, L_801AAF3C
    if (ctx->r1 == 0) {
        // 0x801AA7D4: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_801AAF3C;
    }
    // 0x801AA7D4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x801AA7D8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801AA7DC: addu        $at, $at, $t9
    gpr jr_addend_801AA7E4 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x801AA7E0: lw          $t9, 0x7A54($at)
    ctx->r25 = ADD32(ctx->r1, 0X7A54);
    // 0x801AA7E4: jr          $t9
    // 0x801AA7E8: nop

    switch (jr_addend_801AA7E4 >> 2) {
        case 0: goto L_801AA9B0; break;
        case 1: goto L_801AADC4; break;
        case 2: goto L_801AAC4C; break;
        case 3: goto L_801AAB38; break;
        case 4: goto L_801AAB38; break;
        case 5: goto L_801AAB38; break;
        case 6: goto L_801AAF3C; break;
        case 7: goto L_801AAF3C; break;
        case 8: goto L_801AAF3C; break;
        case 9: goto L_801AAF3C; break;
        case 10: goto L_801AAF3C; break;
        case 11: goto L_801AAF3C; break;
        case 12: goto L_801AAF3C; break;
        case 13: goto L_801AAF3C; break;
        case 14: goto L_801AA7EC; break;
        default: switch_error(__func__, 0x801AA7E4, 0x801B7A54);
    }
    // 0x801AA7E8: nop

L_801AA7EC:
    // 0x801AA7EC: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x801AA7F0: lw          $t2, 0x7DB0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7DB0);
    // 0x801AA7F4: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x801AA7F8: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x801AA7FC: and         $t3, $t2, $v0
    ctx->r11 = ctx->r10 & ctx->r2;
    // 0x801AA800: beq         $t3, $zero, L_801AB138
    if (ctx->r11 == 0) {
        // 0x801AA804: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_801AB138;
    }
    // 0x801AA804: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801AA808: jal         0x800B8DD0
    // 0x801AA80C: addiu       $a1, $zero, 0x43
    ctx->r5 = ADD32(0, 0X43);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x801AA80C: addiu       $a1, $zero, 0x43
    ctx->r5 = ADD32(0, 0X43);
    after_0:
    // 0x801AA810: lui         $s2, 0x8014
    ctx->r18 = S32(0X8014 << 16);
    // 0x801AA814: addiu       $s2, $s2, -0x4C40
    ctx->r18 = ADD32(ctx->r18, -0X4C40);
    // 0x801AA818: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801AA81C: lui         $t6, 0xF000
    ctx->r14 = S32(0XF000 << 16);
    // 0x801AA820: ori         $t6, $t6, 0xFF
    ctx->r14 = ctx->r14 | 0XFF;
    // 0x801AA824: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x801AA828: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x801AA82C: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x801AA830: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x801AA834: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x801AA838: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801AA83C: lui         $t8, 0xFB00
    ctx->r24 = S32(0XFB00 << 16);
    // 0x801AA840: lui         $t9, 0x1F00
    ctx->r25 = S32(0X1F00 << 16);
    // 0x801AA844: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801AA848: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x801AA84C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x801AA850: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x801AA854: jal         0x80005708
    // 0x801AA858: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Push(rdram, ctx);
        goto after_1;
    // 0x801AA858: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_1:
    // 0x801AA85C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801AA860: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x801AA864: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x801AA868: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x801AA86C: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x801AA870: jal         0x80005B00
    // 0x801AA874: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_2;
    // 0x801AA874: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_2:
    // 0x801AA878: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x801AA87C: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x801AA880: addiu       $t5, $t5, -0xB60
    ctx->r13 = ADD32(ctx->r13, -0XB60);
    // 0x801AA884: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x801AA888: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x801AA88C: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x801AA890: addu        $s1, $t4, $t5
    ctx->r17 = ADD32(ctx->r12, ctx->r13);
    // 0x801AA894: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801AA898: lwc1        $f6, 0x7A90($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7A90);
    // 0x801AA89C: lwc1        $f4, 0xC($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XC);
    // 0x801AA8A0: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x801AA8A4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801AA8A8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x801AA8AC: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x801AA8B0: jal         0x80005FE0
    // 0x801AA8B4: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_3;
    // 0x801AA8B4: nop

    after_3:
    // 0x801AA8B8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801AA8BC: lwc1        $f0, 0x7A94($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X7A94);
    // 0x801AA8C0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801AA8C4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801AA8C8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801AA8CC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801AA8D0: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x801AA8D4: jal         0x80005C34
    // 0x801AA8D8: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_4;
    // 0x801AA8D8: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_4:
    // 0x801AA8DC: jal         0x80006EB8
    // 0x801AA8E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_5;
    // 0x801AA8E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x801AA8E4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801AA8E8: lwc1        $f0, 0x7A98($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X7A98);
    // 0x801AA8EC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801AA8F0: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x801AA8F4: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x801AA8F8: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801AA8FC: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x801AA900: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x801AA904: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x801AA908: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801AA90C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801AA910: sll         $t2, $t9, 2
    ctx->r10 = S32(ctx->r25 << 2);
    // 0x801AA914: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x801AA918: lw          $t3, 0x68F8($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X68F8);
    // 0x801AA91C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x801AA920: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801AA924: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x801AA928: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801AA92C: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x801AA930: addiu       $t6, $zero, -0x80
    ctx->r14 = ADD32(0, -0X80);
    // 0x801AA934: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x801AA938: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x801AA93C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x801AA940: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x801AA944: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801AA948: lui         $t8, 0xFB00
    ctx->r24 = S32(0XFB00 << 16);
    // 0x801AA94C: lui         $t9, 0x1F00
    ctx->r25 = S32(0X1F00 << 16);
    // 0x801AA950: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801AA954: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x801AA958: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x801AA95C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x801AA960: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x801AA964: jal         0x80005C34
    // 0x801AA968: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    Matrix_Scale(rdram, ctx);
        goto after_6;
    // 0x801AA968: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_6:
    // 0x801AA96C: jal         0x80006EB8
    // 0x801AA970: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_7;
    // 0x801AA970: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x801AA974: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801AA978: lui         $t4, 0x600
    ctx->r12 = S32(0X600 << 16);
    // 0x801AA97C: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x801AA980: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x801AA984: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x801AA988: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x801AA98C: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x801AA990: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x801AA994: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x801AA998: lw          $t7, 0x68F8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X68F8);
    // 0x801AA99C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x801AA9A0: jal         0x80005740
    // 0x801AA9A4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_8;
    // 0x801AA9A4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_8:
    // 0x801AA9A8: b           L_801AB13C
    // 0x801AA9AC: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
        goto L_801AB13C;
    // 0x801AA9AC: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
L_801AA9B0:
    // 0x801AA9B0: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x801AA9B4: lw          $t8, 0x7DB0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7DB0);
    // 0x801AA9B8: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x801AA9BC: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x801AA9C0: and         $t9, $t8, $v0
    ctx->r25 = ctx->r24 & ctx->r2;
    // 0x801AA9C4: beq         $t9, $zero, L_801AB138
    if (ctx->r25 == 0) {
        // 0x801AA9C8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_801AB138;
    }
    // 0x801AA9C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801AA9CC: jal         0x800B8DD0
    // 0x801AA9D0: addiu       $a1, $zero, 0x3E
    ctx->r5 = ADD32(0, 0X3E);
    RCP_SetupDL(rdram, ctx);
        goto after_9;
    // 0x801AA9D0: addiu       $a1, $zero, 0x3E
    ctx->r5 = ADD32(0, 0X3E);
    after_9:
    // 0x801AA9D4: lui         $s2, 0x8014
    ctx->r18 = S32(0X8014 << 16);
    // 0x801AA9D8: addiu       $s2, $s2, -0x4C40
    ctx->r18 = ADD32(ctx->r18, -0X4C40);
    // 0x801AA9DC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801AA9E0: lui         $t3, 0xFA00
    ctx->r11 = S32(0XFA00 << 16);
    // 0x801AA9E4: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x801AA9E8: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x801AA9EC: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x801AA9F0: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x801AA9F4: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x801AA9F8: jal         0x80005708
    // 0x801AA9FC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Push(rdram, ctx);
        goto after_10;
    // 0x801AA9FC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_10:
    // 0x801AAA00: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801AAA04: lwc1        $f16, 0x7A9C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7A9C);
    // 0x801AAA08: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801AAA0C: lwc1        $f6, 0x7AA0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7AA0);
    // 0x801AAA10: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x801AAA14: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x801AAA18: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801AAA1C: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x801AAA20: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x801AAA24: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x801AAA28: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801AAA2C: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x801AAA30: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x801AAA34: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x801AAA38: jal         0x80005B00
    // 0x801AAA3C: nop

    Matrix_Translate(rdram, ctx);
        goto after_11;
    // 0x801AAA3C: nop

    after_11:
    // 0x801AAA40: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x801AAA44: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x801AAA48: addiu       $t8, $t8, -0xB60
    ctx->r24 = ADD32(ctx->r24, -0XB60);
    // 0x801AAA4C: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x801AAA50: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x801AAA54: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x801AAA58: addu        $s1, $t7, $t8
    ctx->r17 = ADD32(ctx->r15, ctx->r24);
    // 0x801AAA5C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801AAA60: lwc1        $f16, 0x7AA4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7AA4);
    // 0x801AAA64: lwc1        $f10, 0xC($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XC);
    // 0x801AAA68: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x801AAA6C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801AAA70: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x801AAA74: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x801AAA78: jal         0x80005FE0
    // 0x801AAA7C: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_12;
    // 0x801AAA7C: nop

    after_12:
    // 0x801AAA80: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801AAA84: lwc1        $f0, 0x7AA8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X7AA8);
    // 0x801AAA88: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801AAA8C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x801AAA90: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801AAA94: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801AAA98: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x801AAA9C: jal         0x80005C34
    // 0x801AAAA0: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_13;
    // 0x801AAAA0: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_13:
    // 0x801AAAA4: jal         0x80006EB8
    // 0x801AAAA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_14;
    // 0x801AAAA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x801AAAAC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801AAAB0: lui         $t3, 0x600
    ctx->r11 = S32(0X600 << 16);
    // 0x801AAAB4: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x801AAAB8: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x801AAABC: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x801AAAC0: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x801AAAC4: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x801AAAC8: lui         $a1, 0x4190
    ctx->r5 = S32(0X4190 << 16);
    // 0x801AAACC: lui         $a2, 0xC1A0
    ctx->r6 = S32(0XC1A0 << 16);
    // 0x801AAAD0: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x801AAAD4: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x801AAAD8: lw          $t6, 0x68F8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X68F8);
    // 0x801AAADC: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x801AAAE0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801AAAE4: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x801AAAE8: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x801AAAEC: jal         0x80005B00
    // 0x801AAAF0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    Matrix_Translate(rdram, ctx);
        goto after_15;
    // 0x801AAAF0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_15:
    // 0x801AAAF4: jal         0x80006EB8
    // 0x801AAAF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_16;
    // 0x801AAAF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x801AAAFC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801AAB00: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x801AAB04: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x801AAB08: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x801AAB0C: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x801AAB10: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x801AAB14: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x801AAB18: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x801AAB1C: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x801AAB20: lw          $t4, 0x68F8($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X68F8);
    // 0x801AAB24: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x801AAB28: jal         0x80005740
    // 0x801AAB2C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_17;
    // 0x801AAB2C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_17:
    // 0x801AAB30: b           L_801AB13C
    // 0x801AAB34: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
        goto L_801AB13C;
    // 0x801AAB34: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
L_801AAB38:
    // 0x801AAB38: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x801AAB3C: lw          $t5, 0x7DB0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7DB0);
    // 0x801AAB40: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x801AAB44: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x801AAB48: and         $t6, $t5, $v0
    ctx->r14 = ctx->r13 & ctx->r2;
    // 0x801AAB4C: beq         $t6, $zero, L_801AB138
    if (ctx->r14 == 0) {
        // 0x801AAB50: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_801AB138;
    }
    // 0x801AAB50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801AAB54: jal         0x800B8DD0
    // 0x801AAB58: addiu       $a1, $zero, 0x3E
    ctx->r5 = ADD32(0, 0X3E);
    RCP_SetupDL(rdram, ctx);
        goto after_18;
    // 0x801AAB58: addiu       $a1, $zero, 0x3E
    ctx->r5 = ADD32(0, 0X3E);
    after_18:
    // 0x801AAB5C: lui         $s2, 0x8014
    ctx->r18 = S32(0X8014 << 16);
    // 0x801AAB60: addiu       $s2, $s2, -0x4C40
    ctx->r18 = ADD32(ctx->r18, -0X4C40);
    // 0x801AAB64: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801AAB68: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x801AAB6C: addiu       $t9, $zero, -0x70
    ctx->r25 = ADD32(0, -0X70);
    // 0x801AAB70: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801AAB74: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x801AAB78: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x801AAB7C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x801AAB80: jal         0x80005708
    // 0x801AAB84: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Push(rdram, ctx);
        goto after_19;
    // 0x801AAB84: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_19:
    // 0x801AAB88: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801AAB8C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x801AAB90: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x801AAB94: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x801AAB98: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x801AAB9C: jal         0x80005B00
    // 0x801AABA0: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_20;
    // 0x801AABA0: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_20:
    // 0x801AABA4: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x801AABA8: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x801AABAC: addiu       $t5, $t5, -0xB60
    ctx->r13 = ADD32(ctx->r13, -0XB60);
    // 0x801AABB0: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x801AABB4: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x801AABB8: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x801AABBC: addu        $s1, $t4, $t5
    ctx->r17 = ADD32(ctx->r12, ctx->r13);
    // 0x801AABC0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801AABC4: lwc1        $f6, 0x7AAC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7AAC);
    // 0x801AABC8: lwc1        $f4, 0xC($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XC);
    // 0x801AABCC: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x801AABD0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801AABD4: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x801AABD8: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x801AABDC: jal         0x80005FE0
    // 0x801AABE0: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_21;
    // 0x801AABE0: nop

    after_21:
    // 0x801AABE4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801AABE8: lwc1        $f0, 0x7AB0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X7AB0);
    // 0x801AABEC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801AABF0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801AABF4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801AABF8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801AABFC: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x801AAC00: jal         0x80005C34
    // 0x801AAC04: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_22;
    // 0x801AAC04: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_22:
    // 0x801AAC08: jal         0x80006EB8
    // 0x801AAC0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_23;
    // 0x801AAC0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x801AAC10: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801AAC14: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x801AAC18: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x801AAC1C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801AAC20: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x801AAC24: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x801AAC28: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x801AAC2C: sll         $t2, $t9, 2
    ctx->r10 = S32(ctx->r25 << 2);
    // 0x801AAC30: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x801AAC34: lw          $t3, 0x68F8($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X68F8);
    // 0x801AAC38: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x801AAC3C: jal         0x80005740
    // 0x801AAC40: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_24;
    // 0x801AAC40: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_24:
    // 0x801AAC44: b           L_801AB13C
    // 0x801AAC48: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
        goto L_801AB13C;
    // 0x801AAC48: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
L_801AAC4C:
    // 0x801AAC4C: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x801AAC50: lw          $t4, 0x7DB0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7DB0);
    // 0x801AAC54: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x801AAC58: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x801AAC5C: and         $t5, $t4, $v0
    ctx->r13 = ctx->r12 & ctx->r2;
    // 0x801AAC60: beq         $t5, $zero, L_801AB138
    if (ctx->r13 == 0) {
        // 0x801AAC64: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_801AB138;
    }
    // 0x801AAC64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801AAC68: jal         0x800B8DD0
    // 0x801AAC6C: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    RCP_SetupDL(rdram, ctx);
        goto after_25;
    // 0x801AAC6C: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    after_25:
    // 0x801AAC70: addiu       $t6, $zero, 0x32
    ctx->r14 = ADD32(0, 0X32);
    // 0x801AAC74: addiu       $t7, $zero, 0x32
    ctx->r15 = ADD32(0, 0X32);
    // 0x801AAC78: addiu       $t8, $zero, 0x28
    ctx->r24 = ADD32(0, 0X28);
    // 0x801AAC7C: addiu       $t9, $zero, 0x64
    ctx->r25 = ADD32(0, 0X64);
    // 0x801AAC80: addiu       $t2, $zero, 0x64
    ctx->r10 = ADD32(0, 0X64);
    // 0x801AAC84: addiu       $t3, $zero, 0x64
    ctx->r11 = ADD32(0, 0X64);
    // 0x801AAC88: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x801AAC8C: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x801AAC90: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x801AAC94: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x801AAC98: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801AAC9C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801AACA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801AACA4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801AACA8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801AACAC: jal         0x8000372C
    // 0x801AACB0: addiu       $a3, $zero, 0x64
    ctx->r7 = ADD32(0, 0X64);
    Lights_SetOneLight(rdram, ctx);
        goto after_26;
    // 0x801AACB0: addiu       $a3, $zero, 0x64
    ctx->r7 = ADD32(0, 0X64);
    after_26:
    // 0x801AACB4: lui         $s2, 0x8014
    ctx->r18 = S32(0X8014 << 16);
    // 0x801AACB8: addiu       $s2, $s2, -0x4C40
    ctx->r18 = ADD32(ctx->r18, -0X4C40);
    // 0x801AACBC: jal         0x80005708
    // 0x801AACC0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Push(rdram, ctx);
        goto after_27;
    // 0x801AACC0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_27:
    // 0x801AACC4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801AACC8: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x801AACCC: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x801AACD0: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x801AACD4: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x801AACD8: jal         0x80005B00
    // 0x801AACDC: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_28;
    // 0x801AACDC: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_28:
    // 0x801AACE0: lui         $a1, 0x3EB2
    ctx->r5 = S32(0X3EB2 << 16);
    // 0x801AACE4: ori         $a1, $a1, 0xB8C2
    ctx->r5 = ctx->r5 | 0XB8C2;
    // 0x801AACE8: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x801AACEC: jal         0x80005D44
    // 0x801AACF0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateX(rdram, ctx);
        goto after_29;
    // 0x801AACF0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_29:
    // 0x801AACF4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801AACF8: lwc1        $f10, 0x7AB4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7AB4);
    // 0x801AACFC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801AAD00: lwc1        $f16, -0xC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0XC);
    // 0x801AAD04: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x801AAD08: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801AAD0C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x801AAD10: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x801AAD14: jal         0x80005E90
    // 0x801AAD18: nop

    Matrix_RotateY(rdram, ctx);
        goto after_30;
    // 0x801AAD18: nop

    after_30:
    // 0x801AAD1C: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x801AAD20: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x801AAD24: addiu       $t7, $t7, -0xB60
    ctx->r15 = ADD32(ctx->r15, -0XB60);
    // 0x801AAD28: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x801AAD2C: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x801AAD30: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x801AAD34: addu        $s1, $t6, $t7
    ctx->r17 = ADD32(ctx->r14, ctx->r15);
    // 0x801AAD38: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801AAD3C: lwc1        $f6, 0x7AB8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7AB8);
    // 0x801AAD40: lwc1        $f4, 0xC($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XC);
    // 0x801AAD44: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x801AAD48: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801AAD4C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x801AAD50: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x801AAD54: jal         0x80005FE0
    // 0x801AAD58: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_31;
    // 0x801AAD58: nop

    after_31:
    // 0x801AAD5C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801AAD60: lwc1        $f0, 0x7ABC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X7ABC);
    // 0x801AAD64: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801AAD68: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x801AAD6C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801AAD70: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801AAD74: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x801AAD78: jal         0x80005C34
    // 0x801AAD7C: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_32;
    // 0x801AAD7C: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_32:
    // 0x801AAD80: jal         0x80006EB8
    // 0x801AAD84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_33;
    // 0x801AAD84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_33:
    // 0x801AAD88: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801AAD8C: lui         $t2, 0x600
    ctx->r10 = S32(0X600 << 16);
    // 0x801AAD90: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x801AAD94: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x801AAD98: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x801AAD9C: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x801AADA0: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x801AADA4: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x801AADA8: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x801AADAC: lw          $t5, 0x68F8($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X68F8);
    // 0x801AADB0: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x801AADB4: jal         0x80005740
    // 0x801AADB8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_34;
    // 0x801AADB8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_34:
    // 0x801AADBC: b           L_801AB13C
    // 0x801AADC0: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
        goto L_801AB13C;
    // 0x801AADC0: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
L_801AADC4:
    // 0x801AADC4: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x801AADC8: lw          $t6, 0x7DB0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7DB0);
    // 0x801AADCC: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x801AADD0: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x801AADD4: and         $t7, $t6, $v0
    ctx->r15 = ctx->r14 & ctx->r2;
    // 0x801AADD8: beq         $t7, $zero, L_801AB138
    if (ctx->r15 == 0) {
        // 0x801AADDC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_801AB138;
    }
    // 0x801AADDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801AADE0: jal         0x800B8DD0
    // 0x801AADE4: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    RCP_SetupDL(rdram, ctx);
        goto after_35;
    // 0x801AADE4: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    after_35:
    // 0x801AADE8: addiu       $t8, $zero, 0x32
    ctx->r24 = ADD32(0, 0X32);
    // 0x801AADEC: addiu       $t9, $zero, 0x32
    ctx->r25 = ADD32(0, 0X32);
    // 0x801AADF0: addiu       $t2, $zero, 0x28
    ctx->r10 = ADD32(0, 0X28);
    // 0x801AADF4: addiu       $t3, $zero, 0x64
    ctx->r11 = ADD32(0, 0X64);
    // 0x801AADF8: addiu       $t4, $zero, 0x64
    ctx->r12 = ADD32(0, 0X64);
    // 0x801AADFC: addiu       $t5, $zero, 0x64
    ctx->r13 = ADD32(0, 0X64);
    // 0x801AAE00: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x801AAE04: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    // 0x801AAE08: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x801AAE0C: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x801AAE10: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x801AAE14: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x801AAE18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801AAE1C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801AAE20: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801AAE24: jal         0x8000372C
    // 0x801AAE28: addiu       $a3, $zero, 0x64
    ctx->r7 = ADD32(0, 0X64);
    Lights_SetOneLight(rdram, ctx);
        goto after_36;
    // 0x801AAE28: addiu       $a3, $zero, 0x64
    ctx->r7 = ADD32(0, 0X64);
    after_36:
    // 0x801AAE2C: lui         $s2, 0x8014
    ctx->r18 = S32(0X8014 << 16);
    // 0x801AAE30: addiu       $s2, $s2, -0x4C40
    ctx->r18 = ADD32(ctx->r18, -0X4C40);
    // 0x801AAE34: jal         0x80005708
    // 0x801AAE38: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Push(rdram, ctx);
        goto after_37;
    // 0x801AAE38: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_37:
    // 0x801AAE3C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801AAE40: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801AAE44: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x801AAE48: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x801AAE4C: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x801AAE50: jal         0x80005B00
    // 0x801AAE54: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_38;
    // 0x801AAE54: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_38:
    // 0x801AAE58: lui         $a1, 0x3EB2
    ctx->r5 = S32(0X3EB2 << 16);
    // 0x801AAE5C: ori         $a1, $a1, 0xB8C2
    ctx->r5 = ctx->r5 | 0XB8C2;
    // 0x801AAE60: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x801AAE64: jal         0x80005D44
    // 0x801AAE68: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateX(rdram, ctx);
        goto after_39;
    // 0x801AAE68: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_39:
    // 0x801AAE6C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801AAE70: lwc1        $f10, 0x7AC0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7AC0);
    // 0x801AAE74: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801AAE78: lwc1        $f16, -0x4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X4);
    // 0x801AAE7C: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x801AAE80: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801AAE84: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x801AAE88: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x801AAE8C: jal         0x80005E90
    // 0x801AAE90: nop

    Matrix_RotateY(rdram, ctx);
        goto after_40;
    // 0x801AAE90: nop

    after_40:
    // 0x801AAE94: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x801AAE98: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x801AAE9C: addiu       $t9, $t9, -0xB60
    ctx->r25 = ADD32(ctx->r25, -0XB60);
    // 0x801AAEA0: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x801AAEA4: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x801AAEA8: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x801AAEAC: addu        $s1, $t8, $t9
    ctx->r17 = ADD32(ctx->r24, ctx->r25);
    // 0x801AAEB0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801AAEB4: lwc1        $f6, 0x7AC4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7AC4);
    // 0x801AAEB8: lwc1        $f4, 0xC($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XC);
    // 0x801AAEBC: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x801AAEC0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801AAEC4: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x801AAEC8: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x801AAECC: jal         0x80005FE0
    // 0x801AAED0: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_41;
    // 0x801AAED0: nop

    after_41:
    // 0x801AAED4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801AAED8: lwc1        $f0, 0x7AC8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X7AC8);
    // 0x801AAEDC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801AAEE0: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x801AAEE4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801AAEE8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801AAEEC: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x801AAEF0: jal         0x80005C34
    // 0x801AAEF4: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_42;
    // 0x801AAEF4: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_42:
    // 0x801AAEF8: jal         0x80006EB8
    // 0x801AAEFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_43;
    // 0x801AAEFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_43:
    // 0x801AAF00: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801AAF04: lui         $t4, 0x600
    ctx->r12 = S32(0X600 << 16);
    // 0x801AAF08: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x801AAF0C: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x801AAF10: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x801AAF14: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x801AAF18: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x801AAF1C: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x801AAF20: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x801AAF24: lw          $t7, 0x68F8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X68F8);
    // 0x801AAF28: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x801AAF2C: jal         0x80005740
    // 0x801AAF30: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_44;
    // 0x801AAF30: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_44:
    // 0x801AAF34: b           L_801AB13C
    // 0x801AAF38: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
        goto L_801AB13C;
    // 0x801AAF38: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
L_801AAF3C:
    // 0x801AAF3C: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x801AAF40: lw          $t8, 0x7DB0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7DB0);
    // 0x801AAF44: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x801AAF48: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x801AAF4C: and         $t9, $t8, $v0
    ctx->r25 = ctx->r24 & ctx->r2;
    // 0x801AAF50: beq         $t9, $zero, L_801AB138
    if (ctx->r25 == 0) {
        // 0x801AAF54: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_801AB138;
    }
    // 0x801AAF54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801AAF58: jal         0x800B8DD0
    // 0x801AAF5C: addiu       $a1, $zero, 0x3E
    ctx->r5 = ADD32(0, 0X3E);
    RCP_SetupDL(rdram, ctx);
        goto after_45;
    // 0x801AAF5C: addiu       $a1, $zero, 0x3E
    ctx->r5 = ADD32(0, 0X3E);
    after_45:
    // 0x801AAF60: lui         $s2, 0x8014
    ctx->r18 = S32(0X8014 << 16);
    // 0x801AAF64: addiu       $s2, $s2, -0x4C40
    ctx->r18 = ADD32(ctx->r18, -0X4C40);
    // 0x801AAF68: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801AAF6C: lui         $t3, 0xFA00
    ctx->r11 = S32(0XFA00 << 16);
    // 0x801AAF70: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x801AAF74: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x801AAF78: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x801AAF7C: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x801AAF80: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x801AAF84: jal         0x80005708
    // 0x801AAF88: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Push(rdram, ctx);
        goto after_46;
    // 0x801AAF88: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_46:
    // 0x801AAF8C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801AAF90: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x801AAF94: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x801AAF98: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x801AAF9C: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x801AAFA0: jal         0x80005B00
    // 0x801AAFA4: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_47;
    // 0x801AAFA4: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_47:
    // 0x801AAFA8: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x801AAFAC: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x801AAFB0: addiu       $t8, $t8, -0xB60
    ctx->r24 = ADD32(ctx->r24, -0XB60);
    // 0x801AAFB4: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x801AAFB8: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x801AAFBC: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x801AAFC0: addu        $s1, $t7, $t8
    ctx->r17 = ADD32(ctx->r15, ctx->r24);
    // 0x801AAFC4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801AAFC8: lwc1        $f16, 0x7ACC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7ACC);
    // 0x801AAFCC: lwc1        $f10, 0xC($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XC);
    // 0x801AAFD0: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x801AAFD4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801AAFD8: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x801AAFDC: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x801AAFE0: jal         0x80005FE0
    // 0x801AAFE4: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_48;
    // 0x801AAFE4: nop

    after_48:
    // 0x801AAFE8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801AAFEC: lwc1        $f0, 0x7AD0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X7AD0);
    // 0x801AAFF0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801AAFF4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x801AAFF8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801AAFFC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801AB000: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x801AB004: jal         0x80005C34
    // 0x801AB008: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_49;
    // 0x801AB008: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_49:
    // 0x801AB00C: jal         0x80006EB8
    // 0x801AB010: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_50;
    // 0x801AB010: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_50:
    // 0x801AB014: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801AB018: lui         $t3, 0x600
    ctx->r11 = S32(0X600 << 16);
    // 0x801AB01C: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x801AB020: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x801AB024: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x801AB028: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x801AB02C: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x801AB030: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x801AB034: addiu       $t8, $t8, -0x888
    ctx->r24 = ADD32(ctx->r24, -0X888);
    // 0x801AB038: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x801AB03C: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x801AB040: lw          $t6, 0x68F8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X68F8);
    // 0x801AB044: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x801AB048: lw          $t7, 0x28($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X28);
    // 0x801AB04C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x801AB050: bne         $t7, $at, L_801AB130
    if (ctx->r15 != ctx->r1) {
        // 0x801AB054: nop
    
            goto L_801AB130;
    }
    // 0x801AB054: nop

    // 0x801AB058: beq         $s1, $t8, L_801AB0E4
    if (ctx->r17 == ctx->r24) {
        // 0x801AB05C: lui         $t9, 0x801B
        ctx->r25 = S32(0X801B << 16);
            goto L_801AB0E4;
    }
    // 0x801AB05C: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x801AB060: addiu       $t9, $t9, -0x8F8
    ctx->r25 = ADD32(ctx->r25, -0X8F8);
    // 0x801AB064: beq         $s1, $t9, L_801AB0E4
    if (ctx->r17 == ctx->r25) {
        // 0x801AB068: nop
    
            goto L_801AB0E4;
    }
    // 0x801AB068: nop

    // 0x801AB06C: jal         0x80006EB8
    // 0x801AB070: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_51;
    // 0x801AB070: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_51:
    // 0x801AB074: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x801AB078: addiu       $t2, $t2, -0x9D8
    ctx->r10 = ADD32(ctx->r10, -0X9D8);
    // 0x801AB07C: bne         $s1, $t2, L_801AB0A8
    if (ctx->r17 != ctx->r10) {
        // 0x801AB080: lui         $t4, 0xFA00
        ctx->r12 = S32(0XFA00 << 16);
            goto L_801AB0A8;
    }
    // 0x801AB080: lui         $t4, 0xFA00
    ctx->r12 = S32(0XFA00 << 16);
    // 0x801AB084: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801AB088: lui         $t5, 0x4040
    ctx->r13 = S32(0X4040 << 16);
    // 0x801AB08C: ori         $t5, $t5, 0x40FF
    ctx->r13 = ctx->r13 | 0X40FF;
    // 0x801AB090: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x801AB094: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x801AB098: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x801AB09C: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x801AB0A0: b           L_801AB0C8
    // 0x801AB0A4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
        goto L_801AB0C8;
    // 0x801AB0A4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_801AB0A8:
    // 0x801AB0A8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801AB0AC: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x801AB0B0: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x801AB0B4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801AB0B8: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x801AB0BC: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x801AB0C0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801AB0C4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_801AB0C8:
    // 0x801AB0C8: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x801AB0CC: addiu       $t3, $t3, 0x4A40
    ctx->r11 = ADD32(ctx->r11, 0X4A40);
    // 0x801AB0D0: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x801AB0D4: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x801AB0D8: lui         $t2, 0x600
    ctx->r10 = S32(0X600 << 16);
    // 0x801AB0DC: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x801AB0E0: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
L_801AB0E4:
    // 0x801AB0E4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801AB0E8: lwc1        $f0, 0x7AD4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X7AD4);
    // 0x801AB0EC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801AB0F0: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x801AB0F4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801AB0F8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801AB0FC: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x801AB100: jal         0x80005C34
    // 0x801AB104: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_52;
    // 0x801AB104: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_52:
    // 0x801AB108: jal         0x80006EB8
    // 0x801AB10C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_53;
    // 0x801AB10C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_53:
    // 0x801AB110: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801AB114: lui         $t7, 0x606
    ctx->r15 = S32(0X606 << 16);
    // 0x801AB118: addiu       $t7, $t7, -0x3DD0
    ctx->r15 = ADD32(ctx->r15, -0X3DD0);
    // 0x801AB11C: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x801AB120: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x801AB124: lui         $t6, 0x600
    ctx->r14 = S32(0X600 << 16);
    // 0x801AB128: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x801AB12C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
L_801AB130:
    // 0x801AB130: jal         0x80005740
    // 0x801AB134: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_54;
    // 0x801AB134: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_54:
L_801AB138:
    // 0x801AB138: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
L_801AB13C:
    // 0x801AB13C: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x801AB140: lwc1        $f12, 0x44($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X44);
    // 0x801AB144: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x801AB148: addu        $t2, $t2, $t9
    ctx->r10 = ADD32(ctx->r10, ctx->r25);
    // 0x801AB14C: lw          $t2, 0x7BB0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7BB0);
    // 0x801AB150: lwc1        $f14, 0x48($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X48);
    // 0x801AB154: beql        $t2, $zero, L_801AB168
    if (ctx->r10 == 0) {
        // 0x801AB158: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_801AB168;
    }
    goto skip_1;
    // 0x801AB158: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_1:
    // 0x801AB15C: jal         0x801AB17C
    // 0x801AB160: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    Map_PathPlanetMedal_Draw(rdram, ctx);
        goto after_55;
    // 0x801AB160: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_55:
    // 0x801AB164: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_801AB168:
    // 0x801AB168: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x801AB16C: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x801AB170: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x801AB174: jr          $ra
    // 0x801AB178: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x801AB178: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void Title_CsTeamRunning_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018A644: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8018A648: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x8018A64C: addiu       $t0, $t0, -0x7D40
    ctx->r8 = ADD32(ctx->r8, -0X7D40);
    // 0x8018A650: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8018A654: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x8018A658: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8018A65C: beq         $v0, $zero, L_8018A688
    if (ctx->r2 == 0) {
        // 0x8018A660: nop
    
            goto L_8018A688;
    }
    // 0x8018A660: nop

    // 0x8018A664: beq         $v0, $at, L_8018A728
    if (ctx->r2 == ctx->r1) {
        // 0x8018A668: lui         $v1, 0x801C
        ctx->r3 = S32(0X801C << 16);
            goto L_8018A728;
    }
    // 0x8018A668: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8018A66C: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x8018A670: beq         $v0, $v1, L_8018A7FC
    if (ctx->r2 == ctx->r3) {
        // 0x8018A674: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8018A7FC;
    }
    // 0x8018A674: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8018A678: beq         $v0, $at, L_8018A904
    if (ctx->r2 == ctx->r1) {
        // 0x8018A67C: nop
    
            goto L_8018A904;
    }
    // 0x8018A67C: nop

    // 0x8018A680: b           L_8018A930
    // 0x8018A684: nop

        goto L_8018A930;
    // 0x8018A684: nop

L_8018A688:
    // 0x8018A688: jal         0x8018A338
    // 0x8018A68C: nop

    Title_CsTeamRunning_Setup(rdram, ctx);
        goto after_0;
    // 0x8018A68C: nop

    after_0:
    // 0x8018A690: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8018A694: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x8018A698: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8018A69C: addiu       $t6, $t6, 0x5D3C
    ctx->r14 = ADD32(ctx->r14, 0X5D3C);
    // 0x8018A6A0: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x8018A6A4: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x8018A6A8: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x8018A6AC: ori         $a0, $a0, 0x14
    ctx->r4 = ctx->r4 | 0X14;
    // 0x8018A6B0: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8018A6B4: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8018A6B8: jal         0x80019218
    // 0x8018A6BC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_1;
    // 0x8018A6BC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_1:
    // 0x8018A6C0: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8018A6C4: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x8018A6C8: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8018A6CC: addiu       $t7, $t7, 0x5D3C
    ctx->r15 = ADD32(ctx->r15, 0X5D3C);
    // 0x8018A6D0: lui         $a0, 0x140
    ctx->r4 = S32(0X140 << 16);
    // 0x8018A6D4: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x8018A6D8: addiu       $a1, $a1, -0x7B28
    ctx->r5 = ADD32(ctx->r5, -0X7B28);
    // 0x8018A6DC: ori         $a0, $a0, 0x1C
    ctx->r4 = ctx->r4 | 0X1C;
    // 0x8018A6E0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8018A6E4: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8018A6E8: jal         0x80019218
    // 0x8018A6EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Audio_PlaySfx(rdram, ctx);
        goto after_2;
    // 0x8018A6EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x8018A6F0: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8018A6F4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8018A6F8: addiu       $v1, $v1, -0x7D4C
    ctx->r3 = ADD32(ctx->r3, -0X7D4C);
    // 0x8018A6FC: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x8018A700: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018A704: lui         $t8, 0x801C
    ctx->r24 = S32(0X801C << 16);
    // 0x8018A708: lw          $t8, -0x7D40($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7D40);
    // 0x8018A70C: swc1        $f2, -0x7D38($at)
    MEM_W(-0X7D38, ctx->r1) = ctx->f2.u32l;
    // 0x8018A710: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018A714: sw          $zero, 0x7BEC($at)
    MEM_W(0X7BEC, ctx->r1) = 0;
    // 0x8018A718: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018A71C: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8018A720: b           L_8018A930
    // 0x8018A724: sw          $t9, -0x7D40($at)
    MEM_W(-0X7D40, ctx->r1) = ctx->r25;
        goto L_8018A930;
    // 0x8018A724: sw          $t9, -0x7D40($at)
    MEM_W(-0X7D40, ctx->r1) = ctx->r25;
L_8018A728:
    // 0x8018A728: addiu       $v1, $v1, -0x7D4C
    ctx->r3 = ADD32(ctx->r3, -0X7D4C);
    // 0x8018A72C: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x8018A730: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x8018A734: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8018A738: bne         $t1, $at, L_8018A748
    if (ctx->r9 != ctx->r1) {
        // 0x8018A73C: addiu       $a0, $a0, -0x7B30
        ctx->r4 = ADD32(ctx->r4, -0X7B30);
            goto L_8018A748;
    }
    // 0x8018A73C: addiu       $a0, $a0, -0x7B30
    ctx->r4 = ADD32(ctx->r4, -0X7B30);
    // 0x8018A740: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018A744: sw          $zero, -0x7964($at)
    MEM_W(-0X7964, ctx->r1) = 0;
L_8018A748:
    // 0x8018A748: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8018A74C: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8018A750: lui         $a2, 0x3DB8
    ctx->r6 = S32(0X3DB8 << 16);
    // 0x8018A754: ori         $a2, $a2, 0x51EC
    ctx->r6 = ctx->r6 | 0X51EC;
    // 0x8018A758: c.eq.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
    // 0x8018A75C: lui         $a3, 0x428C
    ctx->r7 = S32(0X428C << 16);
    // 0x8018A760: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8018A764: bc1tl       L_8018A79C
    if (c1cs) {
        // 0x8018A768: c.eq.s      $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
            goto L_8018A79C;
    }
    goto skip_0;
    // 0x8018A768: c.eq.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
    skip_0:
    // 0x8018A76C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018A770: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x8018A774: jal         0x8009BC2C
    // 0x8018A778: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_3;
    // 0x8018A778: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_3:
    // 0x8018A77C: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8018A780: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018A784: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x8018A788: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8018A78C: addiu       $t0, $t0, -0x7D40
    ctx->r8 = ADD32(ctx->r8, -0X7D40);
    // 0x8018A790: lwc1        $f0, -0x7B30($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7B30);
    // 0x8018A794: addiu       $v1, $v1, -0x7D4C
    ctx->r3 = ADD32(ctx->r3, -0X7D4C);
    // 0x8018A798: c.eq.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
L_8018A79C:
    // 0x8018A79C: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8018A7A0: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x8018A7A4: addiu       $a0, $a0, -0x7CC0
    ctx->r4 = ADD32(ctx->r4, -0X7CC0);
    // 0x8018A7A8: bc1f        L_8018A7EC
    if (!c1cs) {
        // 0x8018A7AC: addiu       $t2, $t2, -0x256C
        ctx->r10 = ADD32(ctx->r10, -0X256C);
            goto L_8018A7EC;
    }
    // 0x8018A7AC: addiu       $t2, $t2, -0x256C
    ctx->r10 = ADD32(ctx->r10, -0X256C);
    // 0x8018A7B0: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x8018A7B4: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x8018A7B8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018A7BC: sw          $t2, -0x7D6C($at)
    MEM_W(-0X7D6C, ctx->r1) = ctx->r10;
    // 0x8018A7C0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018A7C4: sw          $zero, -0x7D68($at)
    MEM_W(-0X7D68, ctx->r1) = 0;
    // 0x8018A7C8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018A7CC: swc1        $f2, -0x7D74($at)
    MEM_W(-0X7D74, ctx->r1) = ctx->f2.u32l;
    // 0x8018A7D0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018A7D4: lwc1        $f6, 0x6F1C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6F1C);
    // 0x8018A7D8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018A7DC: swc1        $f6, -0x7D70($at)
    MEM_W(-0X7D70, ctx->r1) = ctx->f6.u32l;
    // 0x8018A7E0: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x8018A7E4: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8018A7E8: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
L_8018A7EC:
    // 0x8018A7EC: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x8018A7F0: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8018A7F4: b           L_8018A930
    // 0x8018A7F8: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
        goto L_8018A930;
    // 0x8018A7F8: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
L_8018A7FC:
    // 0x8018A7FC: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8018A800: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x8018A804: addiu       $a1, $a1, -0x7954
    ctx->r5 = ADD32(ctx->r5, -0X7954);
    // 0x8018A808: jal         0x80191798
    // 0x8018A80C: addiu       $a0, $a0, -0x7958
    ctx->r4 = ADD32(ctx->r4, -0X7958);
    Title_GetCamRot(rdram, ctx);
        goto after_4;
    // 0x8018A80C: addiu       $a0, $a0, -0x7958
    ctx->r4 = ADD32(ctx->r4, -0X7958);
    after_4:
    // 0x8018A810: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018A814: lwc1        $f12, -0x7958($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X7958);
    // 0x8018A818: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018A81C: jal         0x80191844
    // 0x8018A820: lwc1        $f14, -0x7954($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X7954);
    Title_SetCamUp(rdram, ctx);
        goto after_5;
    // 0x8018A820: lwc1        $f14, -0x7954($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X7954);
    after_5:
    // 0x8018A824: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8018A828: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x8018A82C: lw          $a2, -0x7D70($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7D70);
    // 0x8018A830: lw          $a0, -0x7D6C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7D6C);
    // 0x8018A834: jal         0x8018CC30
    // 0x8018A838: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    Title_Cutscene_SetCamera(rdram, ctx);
        goto after_6;
    // 0x8018A838: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    after_6:
    // 0x8018A83C: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8018A840: addiu       $a0, $a0, -0x7CC0
    ctx->r4 = ADD32(ctx->r4, -0X7CC0);
    // 0x8018A844: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8018A848: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8018A84C: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x8018A850: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8018A854: addiu       $v1, $v1, -0x7D4C
    ctx->r3 = ADD32(ctx->r3, -0X7D4C);
    // 0x8018A858: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8018A85C: lw          $t9, -0x20BC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X20BC);
    // 0x8018A860: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8018A864: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x8018A868: bne         $v0, $t9, L_8018A890
    if (ctx->r2 != ctx->r25) {
        // 0x8018A86C: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_8018A890;
    }
    // 0x8018A86C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8018A870: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018A874: sw          $t1, -0x7CBC($at)
    MEM_W(-0X7CBC, ctx->r1) = ctx->r9;
    // 0x8018A878: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018A87C: addiu       $t2, $zero, 0x28
    ctx->r10 = ADD32(0, 0X28);
    // 0x8018A880: sw          $t2, -0x7D58($at)
    MEM_W(-0X7D58, ctx->r1) = ctx->r10;
    // 0x8018A884: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018A888: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x8018A88C: sw          $t3, -0x7D40($at)
    MEM_W(-0X7D40, ctx->r1) = ctx->r11;
L_8018A890:
    // 0x8018A890: addiu       $at, $zero, 0x1DB
    ctx->r1 = ADD32(0, 0X1DB);
    // 0x8018A894: bne         $v0, $at, L_8018A8A4
    if (ctx->r2 != ctx->r1) {
        // 0x8018A898: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_8018A8A4;
    }
    // 0x8018A898: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8018A89C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018A8A0: sw          $t4, -0x7964($at)
    MEM_W(-0X7964, ctx->r1) = ctx->r12;
L_8018A8A4:
    // 0x8018A8A4: lw          $t5, 0x7BEC($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7BEC);
    // 0x8018A8A8: addiu       $at, $zero, 0x31B
    ctx->r1 = ADD32(0, 0X31B);
    // 0x8018A8AC: bne         $t5, $at, L_8018A8F8
    if (ctx->r13 != ctx->r1) {
        // 0x8018A8B0: lui         $a0, 0x4900
        ctx->r4 = S32(0X4900 << 16);
            goto L_8018A8F8;
    }
    // 0x8018A8B0: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x8018A8B4: jal         0x8001A838
    // 0x8018A8B8: ori         $a0, $a0, 0x14
    ctx->r4 = ctx->r4 | 0X14;
    Audio_KillSfxById(rdram, ctx);
        goto after_7;
    // 0x8018A8B8: ori         $a0, $a0, 0x14
    ctx->r4 = ctx->r4 | 0X14;
    after_7:
    // 0x8018A8BC: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8018A8C0: lui         $a1, 0x140
    ctx->r5 = S32(0X140 << 16);
    // 0x8018A8C4: ori         $a1, $a1, 0x1C
    ctx->r5 = ctx->r5 | 0X1C;
    // 0x8018A8C8: jal         0x8001A55C
    // 0x8018A8CC: addiu       $a0, $a0, -0x7B28
    ctx->r4 = ADD32(ctx->r4, -0X7B28);
    Audio_KillSfxBySourceAndId(rdram, ctx);
        goto after_8;
    // 0x8018A8CC: addiu       $a0, $a0, -0x7B28
    ctx->r4 = ADD32(ctx->r4, -0X7B28);
    after_8:
    // 0x8018A8D0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018A8D4: sw          $zero, -0x7D40($at)
    MEM_W(-0X7D40, ctx->r1) = 0;
    // 0x8018A8D8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018A8DC: sw          $zero, 0x7898($at)
    MEM_W(0X7898, ctx->r1) = 0;
    // 0x8018A8E0: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8018A8E4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018A8E8: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x8018A8EC: addiu       $v1, $v1, -0x7D4C
    ctx->r3 = ADD32(ctx->r3, -0X7D4C);
    // 0x8018A8F0: sw          $t6, -0x7D3C($at)
    MEM_W(-0X7D3C, ctx->r1) = ctx->r14;
    // 0x8018A8F4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
L_8018A8F8:
    // 0x8018A8F8: addiu       $t7, $v0, 0x1
    ctx->r15 = ADD32(ctx->r2, 0X1);
    // 0x8018A8FC: b           L_8018A930
    // 0x8018A900: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
        goto L_8018A930;
    // 0x8018A900: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
L_8018A904:
    // 0x8018A904: lui         $t8, 0x801C
    ctx->r24 = S32(0X801C << 16);
    // 0x8018A908: lw          $t8, -0x7D58($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7D58);
    // 0x8018A90C: bne         $t8, $zero, L_8018A930
    if (ctx->r24 != 0) {
        // 0x8018A910: lui         $a0, 0x801C
        ctx->r4 = S32(0X801C << 16);
            goto L_8018A930;
    }
    // 0x8018A910: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8018A914: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018A918: addiu       $a0, $a0, -0x7CC0
    ctx->r4 = ADD32(ctx->r4, -0X7CC0);
    // 0x8018A91C: sw          $zero, -0x7CBC($at)
    MEM_W(-0X7CBC, ctx->r1) = 0;
    // 0x8018A920: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x8018A924: sw          $v1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r3;
    // 0x8018A928: addiu       $t1, $t9, 0x1
    ctx->r9 = ADD32(ctx->r25, 0X1);
    // 0x8018A92C: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
L_8018A930:
    // 0x8018A930: jal         0x801912A0
    // 0x8018A934: nop

    Title_ScreenFade_Update(rdram, ctx);
        goto after_9;
    // 0x8018A934: nop

    after_9:
    // 0x8018A938: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018A93C: lwc1        $f12, -0x7938($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X7938);
    // 0x8018A940: lui         $t2, 0x801C
    ctx->r10 = S32(0X801C << 16);
    // 0x8018A944: lui         $t3, 0x801C
    ctx->r11 = S32(0X801C << 16);
    // 0x8018A948: addiu       $t3, $t3, -0x7D18
    ctx->r11 = ADD32(ctx->r11, -0X7D18);
    // 0x8018A94C: addiu       $t2, $t2, -0x7D1C
    ctx->r10 = ADD32(ctx->r10, -0X7D1C);
    // 0x8018A950: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018A954: lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // 0x8018A958: addiu       $a3, $a3, -0x7D20
    ctx->r7 = ADD32(ctx->r7, -0X7D20);
    // 0x8018A95C: lwc1        $f14, -0x7934($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X7934);
    // 0x8018A960: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8018A964: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x8018A968: jal         0x80191674
    // 0x8018A96C: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    Title_SetLightRot(rdram, ctx);
        goto after_10;
    // 0x8018A96C: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    after_10:
    // 0x8018A970: lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // 0x8018A974: addiu       $v0, $v0, 0x7BEC
    ctx->r2 = ADD32(ctx->r2, 0X7BEC);
    // 0x8018A978: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x8018A97C: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8018A980: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8018A984: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8018A988: jr          $ra
    // 0x8018A98C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8018A98C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void Map_Prologue_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A0954: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801A0958: lui         $t2, 0x801D
    ctx->r10 = S32(0X801D << 16);
    // 0x801A095C: addiu       $t2, $t2, -0x26B8
    ctx->r10 = ADD32(ctx->r10, -0X26B8);
    // 0x801A0960: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801A0964: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    // 0x801A0968: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801A096C: addiu       $v1, $v1, -0x261C
    ctx->r3 = ADD32(ctx->r3, -0X261C);
    // 0x801A0970: beq         $a0, $zero, L_801A09A8
    if (ctx->r4 == 0) {
        // 0x801A0974: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_801A09A8;
    }
    // 0x801A0974: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x801A0978: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801A097C: beq         $v0, $at, L_801A0A18
    if (ctx->r2 == ctx->r1) {
        // 0x801A0980: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_801A0A18;
    }
    // 0x801A0980: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801A0984: beq         $v0, $at, L_801A0B84
    if (ctx->r2 == ctx->r1) {
        // 0x801A0988: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_801A0B84;
    }
    // 0x801A0988: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801A098C: beq         $v0, $at, L_801A0BD4
    if (ctx->r2 == ctx->r1) {
        // 0x801A0990: lui         $t5, 0x801D
        ctx->r13 = S32(0X801D << 16);
            goto L_801A0BD4;
    }
    // 0x801A0990: lui         $t5, 0x801D
    ctx->r13 = S32(0X801D << 16);
    // 0x801A0994: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x801A0998: beq         $v0, $at, L_801A0BF0
    if (ctx->r2 == ctx->r1) {
        // 0x801A099C: nop
    
            goto L_801A0BF0;
    }
    // 0x801A099C: nop

    // 0x801A09A0: b           L_801A0BF0
    // 0x801A09A4: nop

        goto L_801A0BF0;
    // 0x801A09A4: nop

L_801A09A8:
    // 0x801A09A8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A09AC: sw          $zero, -0x2610($at)
    MEM_W(-0X2610, ctx->r1) = 0;
    // 0x801A09B0: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801A09B4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801A09B8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A09BC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801A09C0: swc1        $f4, -0x2624($at)
    MEM_W(-0X2624, ctx->r1) = ctx->f4.u32l;
    // 0x801A09C4: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x801A09C8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801A09CC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A09D0: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801A09D4: swc1        $f6, -0x2620($at)
    MEM_W(-0X2620, ctx->r1) = ctx->f6.u32l;
    // 0x801A09D8: addiu       $v0, $v0, -0x2618
    ctx->r2 = ADD32(ctx->r2, -0X2618);
    // 0x801A09DC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A09E0: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x801A09E4: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x801A09E8: lwc1        $f8, 0x75C0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X75C0);
    // 0x801A09EC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A09F0: addiu       $t6, $zero, 0x320
    ctx->r14 = ADD32(0, 0X320);
    // 0x801A09F4: swc1        $f8, -0x2614($at)
    MEM_W(-0X2614, ctx->r1) = ctx->f8.u32l;
    // 0x801A09F8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801A09FC: sw          $t6, -0x7BF0($at)
    MEM_W(-0X7BF0, ctx->r1) = ctx->r14;
    // 0x801A0A00: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A0A04: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x801A0A08: sw          $t7, -0x2640($at)
    MEM_W(-0X2640, ctx->r1) = ctx->r15;
    // 0x801A0A0C: addiu       $t8, $a0, 0x1
    ctx->r24 = ADD32(ctx->r4, 0X1);
    // 0x801A0A10: b           L_801A0BF0
    // 0x801A0A14: sw          $t8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r24;
        goto L_801A0BF0;
    // 0x801A0A14: sw          $t8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r24;
L_801A0A18:
    // 0x801A0A18: lui         $t9, 0x801D
    ctx->r25 = S32(0X801D << 16);
    // 0x801A0A1C: lw          $t9, -0x2640($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2640);
    // 0x801A0A20: bne         $t9, $zero, L_801A0BF0
    if (ctx->r25 != 0) {
        // 0x801A0A24: lui         $t3, 0x8018
        ctx->r11 = S32(0X8018 << 16);
            goto L_801A0BF0;
    }
    // 0x801A0A24: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x801A0A28: lw          $t3, -0x7CC0($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X7CC0);
    // 0x801A0A2C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A0A30: bne         $t3, $zero, L_801A0BF0
    if (ctx->r11 != 0) {
        // 0x801A0A34: nop
    
            goto L_801A0BF0;
    }
    // 0x801A0A34: nop

    // 0x801A0A38: lwc1        $f0, -0x2620($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2620);
    // 0x801A0A3C: addiu       $at, $zero, 0xCD
    ctx->r1 = ADD32(0, 0XCD);
    // 0x801A0A40: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x801A0A44: mfc1        $t5, $f10
    ctx->r13 = (int32_t)ctx->f10.u32l;
    // 0x801A0A48: nop

    // 0x801A0A4C: bne         $t5, $at, L_801A0A6C
    if (ctx->r13 != ctx->r1) {
        // 0x801A0A50: nop
    
            goto L_801A0A6C;
    }
    // 0x801A0A50: nop

    // 0x801A0A54: jal         0x8001AD00
    // 0x801A0A58: addiu       $a0, $zero, 0x3E8
    ctx->r4 = ADD32(0, 0X3E8);
    Audio_PlayVoiceWithoutBGM(rdram, ctx);
        goto after_0;
    // 0x801A0A58: addiu       $a0, $zero, 0x3E8
    ctx->r4 = ADD32(0, 0X3E8);
    after_0:
    // 0x801A0A5C: lui         $t2, 0x801D
    ctx->r10 = S32(0X801D << 16);
    // 0x801A0A60: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A0A64: lwc1        $f0, -0x2620($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2620);
    // 0x801A0A68: addiu       $t2, $t2, -0x26B8
    ctx->r10 = ADD32(ctx->r10, -0X26B8);
L_801A0A6C:
    // 0x801A0A6C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A0A70: lwc1        $f14, 0x75C4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X75C4);
    // 0x801A0A74: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801A0A78: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801A0A7C: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x801A0A80: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A0A84: addiu       $v0, $v0, -0x2618
    ctx->r2 = ADD32(ctx->r2, -0X2618);
    // 0x801A0A88: addiu       $v1, $v1, -0x261C
    ctx->r3 = ADD32(ctx->r3, -0X261C);
    // 0x801A0A8C: bc1f        L_801A0AA8
    if (!c1cs) {
        // 0x801A0A90: lui         $t6, 0x801D
        ctx->r14 = S32(0X801D << 16);
            goto L_801A0AA8;
    }
    // 0x801A0A90: lui         $t6, 0x801D
    ctx->r14 = S32(0X801D << 16);
    // 0x801A0A94: lwc1        $f16, -0x2614($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X2614);
    // 0x801A0A98: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A0A9C: sub.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x801A0AA0: swc1        $f18, -0x2620($at)
    MEM_W(-0X2620, ctx->r1) = ctx->f18.u32l;
    // 0x801A0AA4: lwc1        $f0, -0x2620($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2620);
L_801A0AA8:
    // 0x801A0AA8: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x801A0AAC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801A0AB0: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x801A0AB4: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x801A0AB8: nop

    // 0x801A0ABC: bc1f        L_801A0B08
    if (!c1cs) {
        // 0x801A0AC0: nop
    
            goto L_801A0B08;
    }
    // 0x801A0AC0: nop

    // 0x801A0AC4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x801A0AC8: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801A0ACC: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x801A0AD0: c.eq.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl == ctx->f2.fl;
    // 0x801A0AD4: nop

    // 0x801A0AD8: bc1t        L_801A0B08
    if (c1cs) {
        // 0x801A0ADC: nop
    
            goto L_801A0B08;
    }
    // 0x801A0ADC: nop

    // 0x801A0AE0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801A0AE4: nop

    // 0x801A0AE8: add.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f6.fl;
    // 0x801A0AEC: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x801A0AF0: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801A0AF4: c.lt.s      $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f12.fl < ctx->f10.fl;
    // 0x801A0AF8: nop

    // 0x801A0AFC: bc1f        L_801A0B08
    if (!c1cs) {
        // 0x801A0B00: nop
    
            goto L_801A0B08;
    }
    // 0x801A0B00: nop

    // 0x801A0B04: swc1        $f12, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f12.u32l;
L_801A0B08:
    // 0x801A0B08: lw          $t6, -0x2610($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2610);
    // 0x801A0B0C: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x801A0B10: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x801A0B14: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A0B18: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801A0B1C: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x801A0B20: lwc1        $f16, 0x6934($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6934);
    // 0x801A0B24: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x801A0B28: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x801A0B2C: nop

    // 0x801A0B30: bc1fl       L_801A0B68
    if (!c1cs) {
        // 0x801A0B34: c.le.s      $f0, $f14
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl <= ctx->f14.fl;
            goto L_801A0B68;
    }
    goto skip_0;
    // 0x801A0B34: c.le.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl <= ctx->f14.fl;
    skip_0:
    // 0x801A0B38: lwc1        $f18, 0x0($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X0);
    // 0x801A0B3C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801A0B40: nop

    // 0x801A0B44: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x801A0B48: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
    // 0x801A0B4C: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x801A0B50: c.lt.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl < ctx->f8.fl;
    // 0x801A0B54: nop

    // 0x801A0B58: bc1fl       L_801A0B68
    if (!c1cs) {
        // 0x801A0B5C: c.le.s      $f0, $f14
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl <= ctx->f14.fl;
            goto L_801A0B68;
    }
    goto skip_1;
    // 0x801A0B5C: c.le.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl <= ctx->f14.fl;
    skip_1:
    // 0x801A0B60: swc1        $f12, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f12.u32l;
    // 0x801A0B64: c.le.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl <= ctx->f14.fl;
L_801A0B68:
    // 0x801A0B68: nop

    // 0x801A0B6C: bc1f        L_801A0BF0
    if (!c1cs) {
        // 0x801A0B70: nop
    
            goto L_801A0BF0;
    }
    // 0x801A0B70: nop

    // 0x801A0B74: lw          $t8, 0x0($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X0);
    // 0x801A0B78: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x801A0B7C: b           L_801A0BF0
    // 0x801A0B80: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
        goto L_801A0BF0;
    // 0x801A0B80: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
L_801A0B84:
    // 0x801A0B84: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801A0B88: addiu       $v0, $v0, -0x2618
    ctx->r2 = ADD32(ctx->r2, -0X2618);
    // 0x801A0B8C: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x801A0B90: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801A0B94: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801A0B98: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801A0B9C: addiu       $t3, $a0, 0x1
    ctx->r11 = ADD32(ctx->r4, 0X1);
    // 0x801A0BA0: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x801A0BA4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A0BA8: addiu       $t4, $zero, 0x14
    ctx->r12 = ADD32(0, 0X14);
    // 0x801A0BAC: swc1        $f18, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f18.u32l;
    // 0x801A0BB0: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801A0BB4: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x801A0BB8: nop

    // 0x801A0BBC: bc1f        L_801A0BF0
    if (!c1cs) {
        // 0x801A0BC0: nop
    
            goto L_801A0BF0;
    }
    // 0x801A0BC0: nop

    // 0x801A0BC4: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x801A0BC8: sw          $t3, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r11;
    // 0x801A0BCC: b           L_801A0BF0
    // 0x801A0BD0: sw          $t4, -0x2640($at)
    MEM_W(-0X2640, ctx->r1) = ctx->r12;
        goto L_801A0BF0;
    // 0x801A0BD0: sw          $t4, -0x2640($at)
    MEM_W(-0X2640, ctx->r1) = ctx->r12;
L_801A0BD4:
    // 0x801A0BD4: lw          $t5, -0x2640($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2640);
    // 0x801A0BD8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801A0BDC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A0BE0: bne         $t5, $zero, L_801A0BF0
    if (ctx->r13 != 0) {
        // 0x801A0BE4: nop
    
            goto L_801A0BF0;
    }
    // 0x801A0BE4: nop

    // 0x801A0BE8: sw          $zero, 0x0($t2)
    MEM_W(0X0, ctx->r10) = 0;
    // 0x801A0BEC: sw          $t6, -0x26BC($at)
    MEM_W(-0X26BC, ctx->r1) = ctx->r14;
L_801A0BF0:
    // 0x801A0BF0: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x801A0BF4: lw          $t7, 0x7AF8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7AF8);
    // 0x801A0BF8: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x801A0BFC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x801A0C00: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x801A0C04: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x801A0C08: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x801A0C0C: lhu         $t9, -0x2768($t9)
    ctx->r25 = MEM_HU(ctx->r25, -0X2768);
    // 0x801A0C10: andi        $t3, $t9, 0x1000
    ctx->r11 = ctx->r25 & 0X1000;
    // 0x801A0C14: beq         $t3, $zero, L_801A0D04
    if (ctx->r11 == 0) {
        // 0x801A0C18: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_801A0D04;
    }
    // 0x801A0C18: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801A0C1C: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    // 0x801A0C20: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801A0C24: jal         0x8001D444
    // 0x801A0C28: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    Audio_PlaySequence(rdram, ctx);
        goto after_1;
    // 0x801A0C28: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_1:
    // 0x801A0C2C: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x801A0C30: lui         $t4, 0x800C
    ctx->r12 = S32(0X800C << 16);
    // 0x801A0C34: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x801A0C38: addiu       $t4, $t4, 0x5D3C
    ctx->r12 = ADD32(ctx->r12, 0X5D3C);
    // 0x801A0C3C: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x801A0C40: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x801A0C44: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x801A0C48: ori         $a0, $a0, 0x1F
    ctx->r4 = ctx->r4 | 0X1F;
    // 0x801A0C4C: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x801A0C50: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x801A0C54: jal         0x80019218
    // 0x801A0C58: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_2;
    // 0x801A0C58: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_2:
    // 0x801A0C5C: lui         $v1, 0x801B
    ctx->r3 = S32(0X801B << 16);
    // 0x801A0C60: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801A0C64: lui         $t1, 0x801D
    ctx->r9 = S32(0X801D << 16);
    // 0x801A0C68: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801A0C6C: lui         $a2, 0x801D
    ctx->r6 = S32(0X801D << 16);
    // 0x801A0C70: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801A0C74: addiu       $a1, $a1, -0x26F4
    ctx->r5 = ADD32(ctx->r5, -0X26F4);
    // 0x801A0C78: addiu       $a2, $a2, -0x26F0
    ctx->r6 = ADD32(ctx->r6, -0X26F0);
    // 0x801A0C7C: addiu       $a3, $a3, -0x26EC
    ctx->r7 = ADD32(ctx->r7, -0X26EC);
    // 0x801A0C80: addiu       $t1, $t1, -0x26C4
    ctx->r9 = ADD32(ctx->r9, -0X26C4);
    // 0x801A0C84: addiu       $v0, $v0, -0x2700
    ctx->r2 = ADD32(ctx->r2, -0X2700);
    // 0x801A0C88: addiu       $v1, $v1, -0xB60
    ctx->r3 = ADD32(ctx->r3, -0XB60);
    // 0x801A0C8C: addiu       $t0, $zero, 0x90
    ctx->r8 = ADD32(0, 0X90);
    // 0x801A0C90: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
L_801A0C94:
    // 0x801A0C94: beq         $v0, $a1, L_801A0CAC
    if (ctx->r2 == ctx->r5) {
        // 0x801A0C98: nop
    
            goto L_801A0CAC;
    }
    // 0x801A0C98: nop

    // 0x801A0C9C: beq         $v0, $a2, L_801A0CAC
    if (ctx->r2 == ctx->r6) {
        // 0x801A0CA0: nop
    
            goto L_801A0CAC;
    }
    // 0x801A0CA0: nop

    // 0x801A0CA4: bnel        $v0, $a3, L_801A0CB8
    if (ctx->r2 != ctx->r7) {
        // 0x801A0CA8: sw          $a0, 0x24($v1)
        MEM_W(0X24, ctx->r3) = ctx->r4;
            goto L_801A0CB8;
    }
    goto skip_2;
    // 0x801A0CA8: sw          $a0, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r4;
    skip_2:
L_801A0CAC:
    // 0x801A0CAC: b           L_801A0CB8
    // 0x801A0CB0: sw          $t0, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r8;
        goto L_801A0CB8;
    // 0x801A0CB0: sw          $t0, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r8;
    // 0x801A0CB4: sw          $a0, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r4;
L_801A0CB8:
    // 0x801A0CB8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x801A0CBC: addiu       $v1, $v1, 0x38
    ctx->r3 = ADD32(ctx->r3, 0X38);
    // 0x801A0CC0: bne         $v0, $t1, L_801A0C94
    if (ctx->r2 != ctx->r9) {
        // 0x801A0CC4: sw          $a0, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->r4;
            goto L_801A0C94;
    }
    // 0x801A0CC4: sw          $a0, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r4;
    // 0x801A0CC8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A0CCC: jal         0x8001AE58
    // 0x801A0CD0: sw          $a0, -0x2690($at)
    MEM_W(-0X2690, ctx->r1) = ctx->r4;
    Audio_ClearVoice(rdram, ctx);
        goto after_3;
    // 0x801A0CD0: sw          $a0, -0x2690($at)
    MEM_W(-0X2690, ctx->r1) = ctx->r4;
    after_3:
    // 0x801A0CD4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801A0CD8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A0CDC: sw          $t5, -0x268C($at)
    MEM_W(-0X268C, ctx->r1) = ctx->r13;
    // 0x801A0CE0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A0CE4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801A0CE8: lui         $t2, 0x801D
    ctx->r10 = S32(0X801D << 16);
    // 0x801A0CEC: sw          $t6, -0x2684($at)
    MEM_W(-0X2684, ctx->r1) = ctx->r14;
    // 0x801A0CF0: addiu       $t2, $t2, -0x26B8
    ctx->r10 = ADD32(ctx->r10, -0X26B8);
    // 0x801A0CF4: sw          $zero, 0x0($t2)
    MEM_W(0X0, ctx->r10) = 0;
    // 0x801A0CF8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A0CFC: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x801A0D00: sw          $t7, -0x26BC($at)
    MEM_W(-0X26BC, ctx->r1) = ctx->r15;
L_801A0D04:
    // 0x801A0D04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801A0D08: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801A0D0C: jr          $ra
    // 0x801A0D10: nop

    return;
    // 0x801A0D10: nop

;}
RECOMP_FUNC void Map_LevelPlayedStatus_Check(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A62FC: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x801A6300: sltiu       $at, $a0, 0xF
    ctx->r1 = ctx->r4 < 0XF ? 1 : 0;
    // 0x801A6304: beq         $at, $zero, L_801A6334
    if (ctx->r1 == 0) {
        // 0x801A6308: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_801A6334;
    }
    // 0x801A6308: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x801A630C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x801A6310: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A6314: addu        $at, $at, $t6
    gpr jr_addend_801A631C = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x801A6318: lw          $t6, 0x7874($at)
    ctx->r14 = ADD32(ctx->r1, 0X7874);
    // 0x801A631C: jr          $t6
    // 0x801A6320: nop

    switch (jr_addend_801A631C >> 2) {
        case 0: goto L_801A6324; break;
        case 1: goto L_801A6324; break;
        case 2: goto L_801A6324; break;
        case 3: goto L_801A6324; break;
        case 4: goto L_801A6324; break;
        case 5: goto L_801A6324; break;
        case 6: goto L_801A6324; break;
        case 7: goto L_801A6324; break;
        case 8: goto L_801A6324; break;
        case 9: goto L_801A6324; break;
        case 10: goto L_801A6324; break;
        case 11: goto L_801A6324; break;
        case 12: goto L_801A6324; break;
        case 13: goto L_801A6334; break;
        case 14: goto L_801A632C; break;
        default: switch_error(__func__, 0x801A631C, 0x801B7874);
    }
    // 0x801A6320: nop

L_801A6324:
    // 0x801A6324: b           L_801A6334
    // 0x801A6328: sw          $a0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r4;
        goto L_801A6334;
    // 0x801A6328: sw          $a0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r4;
L_801A632C:
    // 0x801A632C: addiu       $t7, $zero, 0xD
    ctx->r15 = ADD32(0, 0XD);
    // 0x801A6330: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
L_801A6334:
    // 0x801A6334: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x801A6338: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x801A633C: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x801A6340: lbu         $t9, -0x7790($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X7790);
    // 0x801A6344: sll         $t0, $t9, 29
    ctx->r8 = S32(ctx->r25 << 29);
    // 0x801A6348: srl         $t1, $t0, 31
    ctx->r9 = S32(U32(ctx->r8) >> 31);
    // 0x801A634C: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x801A6350: beql        $t2, $zero, L_801A6360
    if (ctx->r10 == 0) {
        // 0x801A6354: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_801A6360;
    }
    goto skip_0;
    // 0x801A6354: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_0:
    // 0x801A6358: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x801A635C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_801A6360:
    // 0x801A6360: jr          $ra
    // 0x801A6364: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x801A6364: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void Map_LevelStart_AudioSpecSetup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A61B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801A61B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801A61BC: sltiu       $at, $a0, 0x13
    ctx->r1 = ctx->r4 < 0X13 ? 1 : 0;
    // 0x801A61C0: beq         $at, $zero, L_801A62EC
    if (ctx->r1 == 0) {
        // 0x801A61C4: sll         $t6, $a0, 2
        ctx->r14 = S32(ctx->r4 << 2);
            goto L_801A62EC;
    }
    // 0x801A61C4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x801A61C8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A61CC: addu        $at, $at, $t6
    gpr jr_addend_801A61D4 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x801A61D0: lw          $t6, 0x7828($at)
    ctx->r14 = ADD32(ctx->r1, 0X7828);
    // 0x801A61D4: jr          $t6
    // 0x801A61D8: nop

    switch (jr_addend_801A61D4 >> 2) {
        case 0: goto L_801A61DC; break;
        case 1: goto L_801A61F0; break;
        case 2: goto L_801A6290; break;
        case 3: goto L_801A6254; break;
        case 4: goto L_801A62EC; break;
        case 5: goto L_801A62CC; break;
        case 6: goto L_801A62EC; break;
        case 7: goto L_801A62E0; break;
        case 8: goto L_801A62B8; break;
        case 9: goto L_801A62EC; break;
        case 10: goto L_801A62EC; break;
        case 11: goto L_801A62A4; break;
        case 12: goto L_801A6204; break;
        case 13: goto L_801A6218; break;
        case 14: goto L_801A627C; break;
        case 15: goto L_801A62EC; break;
        case 16: goto L_801A6240; break;
        case 17: goto L_801A622C; break;
        case 18: goto L_801A6268; break;
        default: switch_error(__func__, 0x801A61D4, 0x801B7828);
    }
    // 0x801A61D8: nop

L_801A61DC:
    // 0x801A61DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801A61E0: jal         0x8001DC6C
    // 0x801A61E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    Audio_SetAudioSpec(rdram, ctx);
        goto after_0;
    // 0x801A61E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x801A61E8: b           L_801A62F0
    // 0x801A61EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801A62F0;
    // 0x801A61EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801A61F0:
    // 0x801A61F0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801A61F4: jal         0x8001DC6C
    // 0x801A61F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    Audio_SetAudioSpec(rdram, ctx);
        goto after_1;
    // 0x801A61F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x801A61FC: b           L_801A62F0
    // 0x801A6200: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801A62F0;
    // 0x801A6200: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801A6204:
    // 0x801A6204: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801A6208: jal         0x8001DC6C
    // 0x801A620C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    Audio_SetAudioSpec(rdram, ctx);
        goto after_2;
    // 0x801A620C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x801A6210: b           L_801A62F0
    // 0x801A6214: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801A62F0;
    // 0x801A6214: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801A6218:
    // 0x801A6218: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801A621C: jal         0x8001DC6C
    // 0x801A6220: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    Audio_SetAudioSpec(rdram, ctx);
        goto after_3;
    // 0x801A6220: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_3:
    // 0x801A6224: b           L_801A62F0
    // 0x801A6228: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801A62F0;
    // 0x801A6228: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801A622C:
    // 0x801A622C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801A6230: jal         0x8001DC6C
    // 0x801A6234: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    Audio_SetAudioSpec(rdram, ctx);
        goto after_4;
    // 0x801A6234: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_4:
    // 0x801A6238: b           L_801A62F0
    // 0x801A623C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801A62F0;
    // 0x801A623C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801A6240:
    // 0x801A6240: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801A6244: jal         0x8001DC6C
    // 0x801A6248: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    Audio_SetAudioSpec(rdram, ctx);
        goto after_5;
    // 0x801A6248: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_5:
    // 0x801A624C: b           L_801A62F0
    // 0x801A6250: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801A62F0;
    // 0x801A6250: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801A6254:
    // 0x801A6254: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801A6258: jal         0x8001DC6C
    // 0x801A625C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    Audio_SetAudioSpec(rdram, ctx);
        goto after_6;
    // 0x801A625C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_6:
    // 0x801A6260: b           L_801A62F0
    // 0x801A6264: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801A62F0;
    // 0x801A6264: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801A6268:
    // 0x801A6268: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801A626C: jal         0x8001DC6C
    // 0x801A6270: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    Audio_SetAudioSpec(rdram, ctx);
        goto after_7;
    // 0x801A6270: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    after_7:
    // 0x801A6274: b           L_801A62F0
    // 0x801A6278: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801A62F0;
    // 0x801A6278: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801A627C:
    // 0x801A627C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801A6280: jal         0x8001DC6C
    // 0x801A6284: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    Audio_SetAudioSpec(rdram, ctx);
        goto after_8;
    // 0x801A6284: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_8:
    // 0x801A6288: b           L_801A62F0
    // 0x801A628C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801A62F0;
    // 0x801A628C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801A6290:
    // 0x801A6290: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801A6294: jal         0x8001DC6C
    // 0x801A6298: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    Audio_SetAudioSpec(rdram, ctx);
        goto after_9;
    // 0x801A6298: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_9:
    // 0x801A629C: b           L_801A62F0
    // 0x801A62A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801A62F0;
    // 0x801A62A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801A62A4:
    // 0x801A62A4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801A62A8: jal         0x8001DC6C
    // 0x801A62AC: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    Audio_SetAudioSpec(rdram, ctx);
        goto after_10;
    // 0x801A62AC: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    after_10:
    // 0x801A62B0: b           L_801A62F0
    // 0x801A62B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801A62F0;
    // 0x801A62B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801A62B8:
    // 0x801A62B8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801A62BC: jal         0x8001DC6C
    // 0x801A62C0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    Audio_SetAudioSpec(rdram, ctx);
        goto after_11;
    // 0x801A62C0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_11:
    // 0x801A62C4: b           L_801A62F0
    // 0x801A62C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801A62F0;
    // 0x801A62C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801A62CC:
    // 0x801A62CC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801A62D0: jal         0x8001DC6C
    // 0x801A62D4: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    Audio_SetAudioSpec(rdram, ctx);
        goto after_12;
    // 0x801A62D4: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_12:
    // 0x801A62D8: b           L_801A62F0
    // 0x801A62DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801A62F0;
    // 0x801A62DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801A62E0:
    // 0x801A62E0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801A62E4: jal         0x8001DC6C
    // 0x801A62E8: addiu       $a1, $zero, 0x209
    ctx->r5 = ADD32(0, 0X209);
    Audio_SetAudioSpec(rdram, ctx);
        goto after_13;
    // 0x801A62E8: addiu       $a1, $zero, 0x209
    ctx->r5 = ADD32(0, 0X209);
    after_13:
L_801A62EC:
    // 0x801A62EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801A62F0:
    // 0x801A62F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801A62F4: jr          $ra
    // 0x801A62F8: nop

    return;
    // 0x801A62F8: nop

;}
RECOMP_FUNC void Title_StarfoxLogo_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018F680: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8018F684: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8018F688: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x8018F68C: addiu       $s2, $s2, 0x7E64
    ctx->r18 = ADD32(ctx->r18, 0X7E64);
    // 0x8018F690: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8018F694: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x8018F698: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x8018F69C: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x8018F6A0: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x8018F6A4: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x8018F6A8: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8018F6AC: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x8018F6B0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8018F6B4: jal         0x800B8DD0
    // 0x8018F6B8: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x8018F6B8: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    after_0:
    // 0x8018F6BC: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x8018F6C0: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x8018F6C4: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8018F6C8: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8018F6CC: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
    // 0x8018F6D0: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8018F6D4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8018F6D8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8018F6DC: lui         $s5, 0x801C
    ctx->r21 = S32(0X801C << 16);
    // 0x8018F6E0: lui         $s4, 0x801C
    ctx->r20 = S32(0X801C << 16);
    // 0x8018F6E4: lui         $s3, 0x600
    ctx->r19 = S32(0X600 << 16);
    // 0x8018F6E8: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8018F6EC: addiu       $s3, $s3, 0x0
    ctx->r19 = ADD32(ctx->r19, 0X0);
    // 0x8018F6F0: addiu       $s4, $s4, -0x6FAC
    ctx->r20 = ADD32(ctx->r20, -0X6FAC);
    // 0x8018F6F4: addiu       $s5, $s5, -0x6FA8
    ctx->r21 = ADD32(ctx->r21, -0X6FA8);
    // 0x8018F6F8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8018F6FC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8018F700: addiu       $s6, $zero, 0x1E
    ctx->r22 = ADD32(0, 0X1E);
L_8018F704:
    // 0x8018F704: mtc1        $s0, $f6
    ctx->f6.u32l = ctx->r16;
    // 0x8018F708: lwc1        $f10, 0x0($s5)
    ctx->f10.u32l = MEM_W(ctx->r21, 0X0);
    // 0x8018F70C: lwc1        $f4, 0x0($s4)
    ctx->f4.u32l = MEM_W(ctx->r20, 0X0);
    // 0x8018F710: cvt.s.w     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8018F714: sll         $t9, $s1, 1
    ctx->r25 = S32(ctx->r17 << 1);
    // 0x8018F718: addu        $a1, $s3, $t9
    ctx->r5 = ADD32(ctx->r19, ctx->r25);
    // 0x8018F71C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8018F720: addiu       $a2, $zero, 0xEC
    ctx->r6 = ADD32(0, 0XEC);
    // 0x8018F724: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x8018F728: add.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x8018F72C: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x8018F730: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8018F734: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8018F738: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8018F73C: jal         0x8009D418
    // 0x8018F740: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    Lib_TextureRect_RGBA16(rdram, ctx);
        goto after_1;
    // 0x8018F740: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    after_1:
    // 0x8018F744: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8018F748: bne         $s0, $s6, L_8018F704
    if (ctx->r16 != ctx->r22) {
        // 0x8018F74C: addiu       $s1, $s1, 0x1D8
        ctx->r17 = ADD32(ctx->r17, 0X1D8);
            goto L_8018F704;
    }
    // 0x8018F74C: addiu       $s1, $s1, 0x1D8
    ctx->r17 = ADD32(ctx->r17, 0X1D8);
    // 0x8018F750: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x8018F754: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x8018F758: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8018F75C: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x8018F760: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x8018F764: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x8018F768: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x8018F76C: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x8018F770: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x8018F774: jr          $ra
    // 0x8018F778: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8018F778: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void Option_NameEntry_Select(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019CD54: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8019CD58: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x8019CD5C: addiu       $t1, $t1, -0x6ED8
    ctx->r9 = ADD32(ctx->r9, -0X6ED8);
    // 0x8019CD60: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8019CD64: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x8019CD68: sltiu       $at, $t6, 0xB
    ctx->r1 = ctx->r14 < 0XB ? 1 : 0;
    // 0x8019CD6C: beq         $at, $zero, L_8019D108
    if (ctx->r1 == 0) {
        // 0x8019CD70: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_8019D108;
    }
    // 0x8019CD70: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8019CD74: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8019CD78: addu        $at, $at, $t6
    gpr jr_addend_8019CD80 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8019CD7C: lw          $t6, 0x7474($at)
    ctx->r14 = ADD32(ctx->r1, 0X7474);
    // 0x8019CD80: jr          $t6
    // 0x8019CD84: nop

    switch (jr_addend_8019CD80 >> 2) {
        case 0: goto L_8019CD88; break;
        case 1: goto L_8019D058; break;
        case 2: goto L_8019D0A8; break;
        case 3: goto L_8019D0F0; break;
        case 4: goto L_8019D108; break;
        case 5: goto L_8019D108; break;
        case 6: goto L_8019D108; break;
        case 7: goto L_8019D108; break;
        case 8: goto L_8019D108; break;
        case 9: goto L_8019D108; break;
        case 10: goto L_8019D024; break;
        default: switch_error(__func__, 0x8019CD80, 0x801B7474);
    }
    // 0x8019CD84: nop

L_8019CD88:
    // 0x8019CD88: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x8019CD8C: lw          $t7, -0x6EC8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X6EC8);
    // 0x8019CD90: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x8019CD94: addiu       $t0, $t0, -0x6F68
    ctx->r8 = ADD32(ctx->r8, -0X6F68);
    // 0x8019CD98: bne         $t7, $zero, L_8019CE80
    if (ctx->r15 != 0) {
        // 0x8019CD9C: lui         $t9, 0x801C
        ctx->r25 = S32(0X801C << 16);
            goto L_8019CE80;
    }
    // 0x8019CD9C: lui         $t9, 0x801C
    ctx->r25 = S32(0X801C << 16);
    // 0x8019CDA0: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x8019CDA4: addiu       $t9, $t9, -0x6F60
    ctx->r25 = ADD32(ctx->r25, -0X6F60);
    // 0x8019CDA8: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x8019CDAC: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x8019CDB0: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    // 0x8019CDB4: lui         $t8, 0x801C
    ctx->r24 = S32(0X801C << 16);
    // 0x8019CDB8: lw          $t6, 0x7AF8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7AF8);
    // 0x8019CDBC: addiu       $t8, $t8, -0x6EA0
    ctx->r24 = ADD32(ctx->r24, -0X6EA0);
    // 0x8019CDC0: sll         $t7, $v0, 3
    ctx->r15 = S32(ctx->r2 << 3);
    // 0x8019CDC4: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8019CDC8: addiu       $t3, $zero, 0x32
    ctx->r11 = ADD32(0, 0X32);
    // 0x8019CDCC: addiu       $t4, $zero, 0x5
    ctx->r12 = ADD32(0, 0X5);
    // 0x8019CDD0: addiu       $t5, $zero, 0xA
    ctx->r13 = ADD32(0, 0XA);
    // 0x8019CDD4: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x8019CDD8: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x8019CDDC: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8019CDE0: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x8019CDE4: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    // 0x8019CDE8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8019CDEC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8019CDF0: jal         0x8019C418
    // 0x8019CDF4: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    Option_Input_MoveCursor_Y(rdram, ctx);
        goto after_0;
    // 0x8019CDF4: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x8019CDF8: beq         $v0, $zero, L_8019CE80
    if (ctx->r2 == 0) {
        // 0x8019CDFC: lui         $a3, 0x800C
        ctx->r7 = S32(0X800C << 16);
            goto L_8019CE80;
    }
    // 0x8019CDFC: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8019CE00: lui         $t3, 0x800C
    ctx->r11 = S32(0X800C << 16);
    // 0x8019CE04: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8019CE08: addiu       $t3, $t3, 0x5D3C
    ctx->r11 = ADD32(ctx->r11, 0X5D3C);
    // 0x8019CE0C: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x8019CE10: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x8019CE14: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x8019CE18: ori         $a0, $a0, 0x2
    ctx->r4 = ctx->r4 | 0X2;
    // 0x8019CE1C: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x8019CE20: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8019CE24: jal         0x80019218
    // 0x8019CE28: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_1;
    // 0x8019CE28: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_1:
    // 0x8019CE2C: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x8019CE30: addiu       $t0, $t0, -0x6F68
    ctx->r8 = ADD32(ctx->r8, -0X6F68);
    // 0x8019CE34: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x8019CE38: lui         $t4, 0x801C
    ctx->r12 = S32(0X801C << 16);
    // 0x8019CE3C: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x8019CE40: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x8019CE44: addu        $t4, $t4, $v1
    ctx->r12 = ADD32(ctx->r12, ctx->r3);
    // 0x8019CE48: lw          $t4, -0x6F60($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X6F60);
    // 0x8019CE4C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019CE50: sll         $t6, $v0, 1
    ctx->r14 = S32(ctx->r2 << 1);
    // 0x8019CE54: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x8019CE58: lbu         $t5, -0x10A4($t5)
    ctx->r13 = MEM_BU(ctx->r13, -0X10A4);
    // 0x8019CE5C: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8019CE60: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8019CE64: sb          $t5, -0x6EB0($at)
    MEM_B(-0X6EB0, ctx->r1) = ctx->r13;
    // 0x8019CE68: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019CE6C: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8019CE70: swc1        $f0, -0x6F30($at)
    MEM_W(-0X6F30, ctx->r1) = ctx->f0.u32l;
    // 0x8019CE74: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019CE78: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8019CE7C: swc1        $f0, -0x6F00($at)
    MEM_W(-0X6F00, ctx->r1) = ctx->f0.u32l;
L_8019CE80:
    // 0x8019CE80: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x8019CE84: lw          $t7, 0x7AF8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7AF8);
    // 0x8019CE88: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8019CE8C: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x8019CE90: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8019CE94: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8019CE98: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x8019CE9C: addu        $v1, $v1, $t8
    ctx->r3 = ADD32(ctx->r3, ctx->r24);
    // 0x8019CEA0: lhu         $v1, -0x2768($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X2768);
    // 0x8019CEA4: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8019CEA8: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x8019CEAC: lui         $t2, 0x800C
    ctx->r10 = S32(0X800C << 16);
    // 0x8019CEB0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8019CEB4: andi        $t9, $v1, 0x8000
    ctx->r25 = ctx->r3 & 0X8000;
    // 0x8019CEB8: addiu       $t2, $t2, 0x5D3C
    ctx->r10 = ADD32(ctx->r10, 0X5D3C);
    // 0x8019CEBC: addiu       $t0, $t0, -0x6F68
    ctx->r8 = ADD32(ctx->r8, -0X6F68);
    // 0x8019CEC0: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8019CEC4: beq         $t9, $zero, L_8019CFA4
    if (ctx->r25 == 0) {
        // 0x8019CEC8: addiu       $a1, $a1, 0x5D28
        ctx->r5 = ADD32(ctx->r5, 0X5D28);
            goto L_8019CFA4;
    }
    // 0x8019CEC8: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x8019CECC: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x8019CED0: lui         $t4, 0x801C
    ctx->r12 = S32(0X801C << 16);
    // 0x8019CED4: lw          $t4, -0x6EC8($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X6EC8);
    // 0x8019CED8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019CEDC: sll         $t3, $v0, 2
    ctx->r11 = S32(ctx->r2 << 2);
    // 0x8019CEE0: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x8019CEE4: beq         $t4, $zero, L_8019CF3C
    if (ctx->r12 == 0) {
        // 0x8019CEE8: swc1        $f0, -0x6F30($at)
        MEM_W(-0X6F30, ctx->r1) = ctx->f0.u32l;
            goto L_8019CF3C;
    }
    // 0x8019CEE8: swc1        $f0, -0x6F30($at)
    MEM_W(-0X6F30, ctx->r1) = ctx->f0.u32l;
    // 0x8019CEEC: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x8019CEF0: ori         $a0, $a0, 0x3
    ctx->r4 = ctx->r4 | 0X3;
    // 0x8019CEF4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8019CEF8: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8019CEFC: jal         0x80019218
    // 0x8019CF00: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    Audio_PlaySfx(rdram, ctx);
        goto after_2;
    // 0x8019CF00: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    after_2:
    // 0x8019CF04: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8019CF08: addiu       $a0, $a0, -0x6EC0
    ctx->r4 = ADD32(ctx->r4, -0X6EC0);
    // 0x8019CF0C: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x8019CF10: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x8019CF14: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x8019CF18: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
    // 0x8019CF1C: sw          $v0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r2;
    // 0x8019CF20: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x8019CF24: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019CF28: addiu       $t1, $t1, -0x6ED8
    ctx->r9 = ADD32(ctx->r9, -0X6ED8);
    // 0x8019CF2C: sw          $t5, -0x6EC8($at)
    MEM_W(-0X6EC8, ctx->r1) = ctx->r13;
    // 0x8019CF30: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8019CF34: b           L_8019D108
    // 0x8019CF38: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
        goto L_8019D108;
    // 0x8019CF38: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
L_8019CF3C:
    // 0x8019CF3C: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x8019CF40: beq         $at, $zero, L_8019CFA4
    if (ctx->r1 == 0) {
        // 0x8019CF44: lui         $a0, 0x4900
        ctx->r4 = S32(0X4900 << 16);
            goto L_8019CFA4;
    }
    // 0x8019CF44: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x8019CF48: ori         $a0, $a0, 0x3
    ctx->r4 = ctx->r4 | 0X3;
    // 0x8019CF4C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8019CF50: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8019CF54: jal         0x80019218
    // 0x8019CF58: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    Audio_PlaySfx(rdram, ctx);
        goto after_3;
    // 0x8019CF58: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    after_3:
    // 0x8019CF5C: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x8019CF60: addiu       $t0, $t0, -0x6F68
    ctx->r8 = ADD32(ctx->r8, -0X6F68);
    // 0x8019CF64: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x8019CF68: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8019CF6C: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8019CF70: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019CF74: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x8019CF78: addiu       $a0, $a0, -0x6EC0
    ctx->r4 = ADD32(ctx->r4, -0X6EC0);
    // 0x8019CF7C: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8019CF80: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x8019CF84: addu        $t9, $a0, $t7
    ctx->r25 = ADD32(ctx->r4, ctx->r15);
    // 0x8019CF88: addiu       $t8, $zero, 0xF
    ctx->r24 = ADD32(0, 0XF);
    // 0x8019CF8C: swc1        $f0, -0x6F30($at)
    MEM_W(-0X6F30, ctx->r1) = ctx->f0.u32l;
    // 0x8019CF90: addiu       $t1, $t1, -0x6ED8
    ctx->r9 = ADD32(ctx->r9, -0X6ED8);
    // 0x8019CF94: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8019CF98: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8019CF9C: b           L_8019D108
    // 0x8019CFA0: sw          $t3, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r11;
        goto L_8019D108;
    // 0x8019CFA0: sw          $t3, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r11;
L_8019CFA4:
    // 0x8019CFA4: andi        $t4, $v1, 0x4000
    ctx->r12 = ctx->r3 & 0X4000;
    // 0x8019CFA8: beql        $t4, $zero, L_8019D10C
    if (ctx->r12 == 0) {
        // 0x8019CFAC: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8019D10C;
    }
    goto skip_0;
    // 0x8019CFAC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x8019CFB0: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x8019CFB4: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x8019CFB8: ori         $a0, $a0, 0x101D
    ctx->r4 = ctx->r4 | 0X101D;
    // 0x8019CFBC: beq         $t5, $zero, L_8019D108
    if (ctx->r13 == 0) {
        // 0x8019CFC0: addiu       $a2, $zero, 0x4
        ctx->r6 = ADD32(0, 0X4);
            goto L_8019D108;
    }
    // 0x8019CFC0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8019CFC4: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8019CFC8: jal         0x80019218
    // 0x8019CFCC: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    Audio_PlaySfx(rdram, ctx);
        goto after_4;
    // 0x8019CFCC: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    after_4:
    // 0x8019CFD0: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x8019CFD4: lw          $t6, -0x6EC8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6EC8);
    // 0x8019CFD8: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x8019CFDC: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x8019CFE0: addiu       $t1, $t1, -0x6ED8
    ctx->r9 = ADD32(ctx->r9, -0X6ED8);
    // 0x8019CFE4: beq         $t6, $zero, L_8019CFF4
    if (ctx->r14 == 0) {
        // 0x8019CFE8: addiu       $t0, $t0, -0x6F68
        ctx->r8 = ADD32(ctx->r8, -0X6F68);
            goto L_8019CFF4;
    }
    // 0x8019CFE8: addiu       $t0, $t0, -0x6F68
    ctx->r8 = ADD32(ctx->r8, -0X6F68);
    // 0x8019CFEC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019CFF0: sw          $zero, -0x6EC8($at)
    MEM_W(-0X6EC8, ctx->r1) = 0;
L_8019CFF4:
    // 0x8019CFF4: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x8019CFF8: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8019CFFC: addiu       $a0, $a0, -0x6EC0
    ctx->r4 = ADD32(ctx->r4, -0X6EC0);
    // 0x8019D000: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x8019D004: sll         $t4, $t8, 2
    ctx->r12 = S32(ctx->r24 << 2);
    // 0x8019D008: addu        $t5, $a0, $t4
    ctx->r13 = ADD32(ctx->r4, ctx->r12);
    // 0x8019D00C: addiu       $t9, $zero, 0xF
    ctx->r25 = ADD32(0, 0XF);
    // 0x8019D010: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x8019D014: sw          $t9, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r25;
    // 0x8019D018: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x8019D01C: b           L_8019D108
    // 0x8019D020: sw          $v0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r2;
        goto L_8019D108;
    // 0x8019D020: sw          $v0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r2;
L_8019D024:
    // 0x8019D024: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x8019D028: addiu       $t0, $t0, -0x6F68
    ctx->r8 = ADD32(ctx->r8, -0X6F68);
    // 0x8019D02C: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x8019D030: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8019D034: addiu       $a0, $a0, -0x6EC0
    ctx->r4 = ADD32(ctx->r4, -0X6EC0);
    // 0x8019D038: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8019D03C: addu        $v1, $a0, $t7
    ctx->r3 = ADD32(ctx->r4, ctx->r15);
    // 0x8019D040: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8019D044: addiu       $t3, $t8, -0x1
    ctx->r11 = ADD32(ctx->r24, -0X1);
    // 0x8019D048: bne         $t3, $zero, L_8019D108
    if (ctx->r11 != 0) {
        // 0x8019D04C: sw          $t3, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r11;
            goto L_8019D108;
    }
    // 0x8019D04C: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x8019D050: b           L_8019D108
    // 0x8019D054: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
        goto L_8019D108;
    // 0x8019D054: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
L_8019D058:
    // 0x8019D058: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x8019D05C: addiu       $t0, $t0, -0x6F68
    ctx->r8 = ADD32(ctx->r8, -0X6F68);
    // 0x8019D060: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x8019D064: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8019D068: addiu       $a0, $a0, -0x6EC0
    ctx->r4 = ADD32(ctx->r4, -0X6EC0);
    // 0x8019D06C: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x8019D070: addu        $v1, $a0, $t9
    ctx->r3 = ADD32(ctx->r4, ctx->r25);
    // 0x8019D074: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x8019D078: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x8019D07C: bne         $t6, $zero, L_8019D108
    if (ctx->r14 != 0) {
        // 0x8019D080: sw          $t6, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r14;
            goto L_8019D108;
    }
    // 0x8019D080: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8019D084: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x8019D088: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x8019D08C: bne         $at, $zero, L_8019D09C
    if (ctx->r1 != 0) {
        // 0x8019D090: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_8019D09C;
    }
    // 0x8019D090: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8019D094: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019D098: sw          $t8, -0x6EC8($at)
    MEM_W(-0X6EC8, ctx->r1) = ctx->r24;
L_8019D09C:
    // 0x8019D09C: sw          $v1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r3;
    // 0x8019D0A0: b           L_8019D108
    // 0x8019D0A4: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
        goto L_8019D108;
    // 0x8019D0A4: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
L_8019D0A8:
    // 0x8019D0A8: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8019D0AC: addiu       $a0, $a0, -0x6EC0
    ctx->r4 = ADD32(ctx->r4, -0X6EC0);
    // 0x8019D0B0: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x8019D0B4: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
    // 0x8019D0B8: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x8019D0BC: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x8019D0C0: addiu       $t5, $t9, -0x1
    ctx->r13 = ADD32(ctx->r25, -0X1);
    // 0x8019D0C4: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8019D0C8: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x8019D0CC: sw          $t5, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r13;
    // 0x8019D0D0: bne         $t4, $zero, L_8019D108
    if (ctx->r12 != 0) {
        // 0x8019D0D4: sw          $t7, 0x8($a0)
        MEM_W(0X8, ctx->r4) = ctx->r15;
            goto L_8019D108;
    }
    // 0x8019D0D4: sw          $t7, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r15;
    // 0x8019D0D8: addiu       $t3, $zero, 0x14
    ctx->r11 = ADD32(0, 0X14);
    // 0x8019D0DC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019D0E0: sw          $t3, -0x6E84($at)
    MEM_W(-0X6E84, ctx->r1) = ctx->r11;
    // 0x8019D0E4: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x8019D0E8: b           L_8019D108
    // 0x8019D0EC: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
        goto L_8019D108;
    // 0x8019D0EC: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
L_8019D0F0:
    // 0x8019D0F0: lui         $t9, 0x801C
    ctx->r25 = S32(0X801C << 16);
    // 0x8019D0F4: lw          $t9, -0x6E84($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X6E84);
    // 0x8019D0F8: bne         $t9, $zero, L_8019D108
    if (ctx->r25 != 0) {
        // 0x8019D0FC: addiu       $t5, $zero, 0x2
        ctx->r13 = ADD32(0, 0X2);
            goto L_8019D108;
    }
    // 0x8019D0FC: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x8019D100: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019D104: sw          $t5, -0x6ED4($at)
    MEM_W(-0X6ED4, ctx->r1) = ctx->r13;
L_8019D108:
    // 0x8019D108: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8019D10C:
    // 0x8019D10C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8019D110: jr          $ra
    // 0x8019D114: nop

    return;
    // 0x8019D114: nop

;}
RECOMP_FUNC void Option_SetMenuLightPos(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019BE7C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8019BE80: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8019BE84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8019BE88: swc1        $f12, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f12.u32l;
    // 0x8019BE8C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8019BE90: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x8019BE94: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8019BE98: lwc1        $f6, 0x746C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X746C);
    // 0x8019BE9C: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8019BEA0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8019BEA4: mul.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x8019BEA8: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x8019BEAC: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x8019BEB0: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8019BEB4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8019BEB8: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x8019BEBC: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8019BEC0: jal         0x80005E90
    // 0x8019BEC4: nop

    Matrix_RotateY(rdram, ctx);
        goto after_0;
    // 0x8019BEC4: nop

    after_0:
    // 0x8019BEC8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8019BECC: lwc1        $f10, 0x7470($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7470);
    // 0x8019BED0: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8019BED4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8019BED8: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8019BEDC: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8019BEE0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8019BEE4: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8019BEE8: jal         0x80005D44
    // 0x8019BEEC: nop

    Matrix_RotateX(rdram, ctx);
        goto after_1;
    // 0x8019BEEC: nop

    after_1:
    // 0x8019BEF0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8019BEF4: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8019BEF8: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x8019BEFC: jal         0x80006970
    // 0x8019BF00: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    Matrix_MultVec3f(rdram, ctx);
        goto after_2;
    // 0x8019BF00: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    after_2:
    // 0x8019BF04: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8019BF08: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x8019BF0C: swc1        $f4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f4.u32l;
    // 0x8019BF10: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x8019BF14: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8019BF18: swc1        $f6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f6.u32l;
    // 0x8019BF1C: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x8019BF20: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8019BF24: swc1        $f8, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f8.u32l;
    // 0x8019BF28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8019BF2C: jr          $ra
    // 0x8019BF30: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8019BF30: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void Map_GralPepper_Talk(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A2304: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801A2308: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801A230C: addiu       $a1, $a1, -0x26B4
    ctx->r5 = ADD32(ctx->r5, -0X26B4);
    // 0x801A2310: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801A2314: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x801A2318: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x801A231C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801A2320: beq         $v0, $zero, L_801A2344
    if (ctx->r2 == 0) {
        // 0x801A2324: nop
    
            goto L_801A2344;
    }
    // 0x801A2324: nop

    // 0x801A2328: beq         $v0, $at, L_801A23C8
    if (ctx->r2 == ctx->r1) {
        // 0x801A232C: lui         $v1, 0x801D
        ctx->r3 = S32(0X801D << 16);
            goto L_801A23C8;
    }
    // 0x801A232C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801A2330: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x801A2334: beq         $v0, $at, L_801A24B4
    if (ctx->r2 == ctx->r1) {
        // 0x801A2338: lui         $a0, 0x801D
        ctx->r4 = S32(0X801D << 16);
            goto L_801A24B4;
    }
    // 0x801A2338: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x801A233C: b           L_801A25B8
    // 0x801A2340: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
        goto L_801A25B8;
    // 0x801A2340: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
L_801A2344:
    // 0x801A2344: jal         0x8001ACDC
    // 0x801A2348: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    Audio_PlayVoice(rdram, ctx);
        goto after_0;
    // 0x801A2348: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_0:
    // 0x801A234C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801A2350: addiu       $v0, $v0, -0x1588
    ctx->r2 = ADD32(ctx->r2, -0X1588);
    // 0x801A2354: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A2358: lwc1        $f0, 0x7658($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X7658);
    // 0x801A235C: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801A2360: lui         $at, 0x40B0
    ctx->r1 = S32(0X40B0 << 16);
    // 0x801A2364: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801A2368: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x801A236C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801A2370: addiu       $v1, $v1, -0x1580
    ctx->r3 = ADD32(ctx->r3, -0X1580);
    // 0x801A2374: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x801A2378: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x801A237C: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801A2380: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x801A2384: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801A2388: addiu       $a1, $a1, -0x26B4
    ctx->r5 = ADD32(ctx->r5, -0X26B4);
    // 0x801A238C: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    // 0x801A2390: swc1        $f10, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f10.u32l;
    // 0x801A2394: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A2398: addiu       $t8, $zero, 0xD
    ctx->r24 = ADD32(0, 0XD);
    // 0x801A239C: bc1fl       L_801A25B8
    if (!c1cs) {
        // 0x801A23A0: lw          $v0, 0x2C($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X2C);
            goto L_801A25B8;
    }
    goto skip_0;
    // 0x801A23A0: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x801A23A4: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x801A23A8: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
    // 0x801A23AC: lwc1        $f18, 0x765C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X765C);
    // 0x801A23B0: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x801A23B4: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x801A23B8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A23BC: swc1        $f18, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f18.u32l;
    // 0x801A23C0: b           L_801A25B4
    // 0x801A23C4: sw          $t8, -0x2648($at)
    MEM_W(-0X2648, ctx->r1) = ctx->r24;
        goto L_801A25B4;
    // 0x801A23C4: sw          $t8, -0x2648($at)
    MEM_W(-0X2648, ctx->r1) = ctx->r24;
L_801A23C8:
    // 0x801A23C8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801A23CC: addiu       $v0, $v0, -0x1588
    ctx->r2 = ADD32(ctx->r2, -0X1588);
    // 0x801A23D0: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x801A23D4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801A23D8: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801A23DC: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x801A23E0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801A23E4: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x801A23E8: addiu       $v1, $v1, -0x1580
    ctx->r3 = ADD32(ctx->r3, -0X1580);
    // 0x801A23EC: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x801A23F0: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x801A23F4: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x801A23F8: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801A23FC: addiu       $a0, $a0, -0x1568
    ctx->r4 = ADD32(ctx->r4, -0X1568);
    // 0x801A2400: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x801A2404: c.lt.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl < ctx->f2.fl;
    // 0x801A2408: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A240C: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x801A2410: addiu       $t0, $t9, 0xA
    ctx->r8 = ADD32(ctx->r25, 0XA);
    // 0x801A2414: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
    // 0x801A2418: bc1f        L_801A2424
    if (!c1cs) {
        // 0x801A241C: swc1        $f10, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->f10.u32l;
            goto L_801A2424;
    }
    // 0x801A241C: swc1        $f10, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f10.u32l;
    // 0x801A2420: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
L_801A2424:
    // 0x801A2424: lwc1        $f12, 0x7660($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X7660);
    // 0x801A2428: lwc1        $f18, 0x0($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X0);
    // 0x801A242C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801A2430: addiu       $v0, $v0, -0x1584
    ctx->r2 = ADD32(ctx->r2, -0X1584);
    // 0x801A2434: c.lt.s      $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f18.fl < ctx->f12.fl;
    // 0x801A2438: lui         $t1, 0x801D
    ctx->r9 = S32(0X801D << 16);
    // 0x801A243C: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x801A2440: addiu       $t3, $zero, 0x64
    ctx->r11 = ADD32(0, 0X64);
    // 0x801A2444: bc1fl       L_801A2454
    if (!c1cs) {
        // 0x801A2448: lwc1        $f4, 0x0($v0)
        ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
            goto L_801A2454;
    }
    goto skip_1;
    // 0x801A2448: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    skip_1:
    // 0x801A244C: swc1        $f12, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f12.u32l;
    // 0x801A2450: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
L_801A2454:
    // 0x801A2454: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801A2458: addiu       $v1, $v1, -0x157C
    ctx->r3 = ADD32(ctx->r3, -0X157C);
    // 0x801A245C: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x801A2460: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x801A2464: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x801A2468: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801A246C: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x801A2470: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    // 0x801A2474: swc1        $f10, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f10.u32l;
    // 0x801A2478: bc1fl       L_801A2488
    if (!c1cs) {
        // 0x801A247C: lwc1        $f18, 0x0($v1)
        ctx->f18.u32l = MEM_W(ctx->r3, 0X0);
            goto L_801A2488;
    }
    goto skip_2;
    // 0x801A247C: lwc1        $f18, 0x0($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X0);
    skip_2:
    // 0x801A2480: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
    // 0x801A2484: lwc1        $f18, 0x0($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X0);
L_801A2488:
    // 0x801A2488: c.lt.s      $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f12.fl < ctx->f18.fl;
    // 0x801A248C: nop

    // 0x801A2490: bc1f        L_801A249C
    if (!c1cs) {
        // 0x801A2494: nop
    
            goto L_801A249C;
    }
    // 0x801A2494: nop

    // 0x801A2498: swc1        $f12, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f12.u32l;
L_801A249C:
    // 0x801A249C: lw          $t1, -0x2648($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2648);
    // 0x801A24A0: bnel        $t1, $zero, L_801A25B8
    if (ctx->r9 != 0) {
        // 0x801A24A4: lw          $v0, 0x2C($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X2C);
            goto L_801A25B8;
    }
    goto skip_3;
    // 0x801A24A4: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    skip_3:
    // 0x801A24A8: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x801A24AC: b           L_801A25B4
    // 0x801A24B0: sw          $t3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r11;
        goto L_801A25B4;
    // 0x801A24B0: sw          $t3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r11;
L_801A24B4:
    // 0x801A24B4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801A24B8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801A24BC: lui         $a2, 0x3ECC
    ctx->r6 = S32(0X3ECC << 16);
    // 0x801A24C0: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801A24C4: addiu       $a0, $a0, -0x1578
    ctx->r4 = ADD32(ctx->r4, -0X1578);
    // 0x801A24C8: lui         $a1, 0xC34E
    ctx->r5 = S32(0XC34E << 16);
    // 0x801A24CC: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x801A24D0: jal         0x8009BC2C
    // 0x801A24D4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_1;
    // 0x801A24D4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x801A24D8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801A24DC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801A24E0: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x801A24E4: lui         $a2, 0x3ECC
    ctx->r6 = S32(0X3ECC << 16);
    // 0x801A24E8: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x801A24EC: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801A24F0: addiu       $a0, $a0, -0x1574
    ctx->r4 = ADD32(ctx->r4, -0X1574);
    // 0x801A24F4: lui         $a1, 0x424C
    ctx->r5 = S32(0X424C << 16);
    // 0x801A24F8: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x801A24FC: jal         0x8009BC2C
    // 0x801A2500: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_2;
    // 0x801A2500: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x801A2504: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801A2508: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801A250C: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x801A2510: lui         $a1, 0xC41C
    ctx->r5 = S32(0XC41C << 16);
    // 0x801A2514: lui         $a2, 0x3ECC
    ctx->r6 = S32(0X3ECC << 16);
    // 0x801A2518: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x801A251C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801A2520: ori         $a1, $a1, 0xC000
    ctx->r5 = ctx->r5 | 0XC000;
    // 0x801A2524: addiu       $a0, $a0, -0x1570
    ctx->r4 = ADD32(ctx->r4, -0X1570);
    // 0x801A2528: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x801A252C: jal         0x8009BC2C
    // 0x801A2530: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_3;
    // 0x801A2530: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_3:
    // 0x801A2534: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801A2538: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801A253C: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x801A2540: lui         $a1, 0x422B
    ctx->r5 = S32(0X422B << 16);
    // 0x801A2544: lui         $a2, 0x3ECC
    ctx->r6 = S32(0X3ECC << 16);
    // 0x801A2548: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x801A254C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801A2550: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x801A2554: addiu       $a0, $a0, -0x156C
    ctx->r4 = ADD32(ctx->r4, -0X156C);
    // 0x801A2558: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x801A255C: jal         0x8009BC2C
    // 0x801A2560: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_4;
    // 0x801A2560: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_4:
    // 0x801A2564: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x801A2568: lwc1        $f16, 0x28($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801A256C: lwc1        $f18, 0x24($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X24);
    // 0x801A2570: c.eq.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl == ctx->f2.fl;
    // 0x801A2574: nop

    // 0x801A2578: bc1fl       L_801A25B8
    if (!c1cs) {
        // 0x801A257C: lw          $v0, 0x2C($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X2C);
            goto L_801A25B8;
    }
    goto skip_4;
    // 0x801A257C: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    skip_4:
    // 0x801A2580: c.eq.s      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl == ctx->f2.fl;
    // 0x801A2584: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x801A2588: bc1fl       L_801A25B8
    if (!c1cs) {
        // 0x801A258C: lw          $v0, 0x2C($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X2C);
            goto L_801A25B8;
    }
    goto skip_5;
    // 0x801A258C: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    skip_5:
    // 0x801A2590: c.eq.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl == ctx->f2.fl;
    // 0x801A2594: nop

    // 0x801A2598: bc1fl       L_801A25B8
    if (!c1cs) {
        // 0x801A259C: lw          $v0, 0x2C($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X2C);
            goto L_801A25B8;
    }
    goto skip_6;
    // 0x801A259C: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    skip_6:
    // 0x801A25A0: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    // 0x801A25A4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801A25A8: bc1fl       L_801A25B8
    if (!c1cs) {
        // 0x801A25AC: lw          $v0, 0x2C($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X2C);
            goto L_801A25B8;
    }
    goto skip_7;
    // 0x801A25AC: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    skip_7:
    // 0x801A25B0: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
L_801A25B4:
    // 0x801A25B4: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
L_801A25B8:
    // 0x801A25B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801A25BC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801A25C0: jr          $ra
    // 0x801A25C4: nop

    return;
    // 0x801A25C4: nop

;}
RECOMP_FUNC void Option_DrawArwing(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019BC44: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8019BC48: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8019BC4C: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8019BC50: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    // 0x8019BC54: swc1        $f14, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f14.u32l;
    // 0x8019BC58: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x8019BC5C: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    // 0x8019BC60: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019BC64: lwc1        $f12, -0x6DDC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X6DDC);
    // 0x8019BC68: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019BC6C: addiu       $t6, $sp, 0x40
    ctx->r14 = ADD32(ctx->r29, 0X40);
    // 0x8019BC70: addiu       $t7, $sp, 0x3C
    ctx->r15 = ADD32(ctx->r29, 0X3C);
    // 0x8019BC74: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8019BC78: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8019BC7C: lwc1        $f14, -0x6DD8($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X6DD8);
    // 0x8019BC80: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    // 0x8019BC84: jal         0x8019BE7C
    // 0x8019BC88: addiu       $a3, $sp, 0x44
    ctx->r7 = ADD32(ctx->r29, 0X44);
    Option_SetMenuLightPos(rdram, ctx);
        goto after_0;
    // 0x8019BC88: addiu       $a3, $sp, 0x44
    ctx->r7 = ADD32(ctx->r29, 0X44);
    after_0:
    // 0x8019BC8C: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8019BC90: lwc1        $f8, 0x40($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8019BC94: lwc1        $f16, 0x3C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8019BC98: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8019BC9C: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x8019BCA0: lui         $t2, 0x801C
    ctx->r10 = S32(0X801C << 16);
    // 0x8019BCA4: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8019BCA8: lui         $t3, 0x801C
    ctx->r11 = S32(0X801C << 16);
    // 0x8019BCAC: lui         $t4, 0x801C
    ctx->r12 = S32(0X801C << 16);
    // 0x8019BCB0: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8019BCB4: lui         $t5, 0x801C
    ctx->r13 = S32(0X801C << 16);
    // 0x8019BCB8: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x8019BCBC: lw          $t6, -0x6DC0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6DC0);
    // 0x8019BCC0: lw          $t5, -0x6DC4($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X6DC4);
    // 0x8019BCC4: lw          $t4, -0x6DC8($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X6DC8);
    // 0x8019BCC8: lw          $t3, -0x6DCC($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X6DCC);
    // 0x8019BCCC: lw          $t2, -0x6DD0($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X6DD0);
    // 0x8019BCD0: lw          $t1, -0x6DD4($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X6DD4);
    // 0x8019BCD4: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x8019BCD8: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x8019BCDC: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8019BCE0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8019BCE4: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8019BCE8: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x8019BCEC: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    // 0x8019BCF0: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x8019BCF4: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x8019BCF8: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8019BCFC: jal         0x8000372C
    // 0x8019BD00: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    Lights_SetOneLight(rdram, ctx);
        goto after_1;
    // 0x8019BD00: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_1:
    // 0x8019BD04: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x8019BD08: addiu       $s0, $s0, -0x4C40
    ctx->r16 = ADD32(ctx->r16, -0X4C40);
    // 0x8019BD0C: jal         0x80005708
    // 0x8019BD10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_Push(rdram, ctx);
        goto after_2;
    // 0x8019BD10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8019BD14: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8019BD18: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8019BD1C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8019BD20: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x8019BD24: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    // 0x8019BD28: jal         0x80005B00
    // 0x8019BD2C: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    Matrix_Translate(rdram, ctx);
        goto after_3;
    // 0x8019BD2C: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    after_3:
    // 0x8019BD30: lwc1        $f0, 0x5C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8019BD34: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8019BD38: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8019BD3C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8019BD40: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8019BD44: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8019BD48: jal         0x80005C34
    // 0x8019BD4C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_4;
    // 0x8019BD4C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_4:
    // 0x8019BD50: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8019BD54: lwc1        $f4, 0x7464($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7464);
    // 0x8019BD58: lwc1        $f6, 0x58($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8019BD5C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8019BD60: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8019BD64: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8019BD68: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8019BD6C: jal         0x80005FE0
    // 0x8019BD70: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_5;
    // 0x8019BD70: nop

    after_5:
    // 0x8019BD74: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8019BD78: lwc1        $f10, 0x7468($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7468);
    // 0x8019BD7C: lwc1        $f16, 0x54($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8019BD80: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8019BD84: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8019BD88: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8019BD8C: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8019BD90: jal         0x80005E90
    // 0x8019BD94: nop

    Matrix_RotateY(rdram, ctx);
        goto after_6;
    // 0x8019BD94: nop

    after_6:
    // 0x8019BD98: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8019BD9C: jal         0x80006EB8
    // 0x8019BDA0: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_7;
    // 0x8019BDA0: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    after_7:
    // 0x8019BDA4: jal         0x800B9E80
    // 0x8019BDA8: nop

    RCP_SetupDL_55(rdram, ctx);
        goto after_8;
    // 0x8019BDA8: nop

    after_8:
    // 0x8019BDAC: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8019BDB0: lw          $v1, 0x7E64($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7E64);
    // 0x8019BDB4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8019BDB8: lui         $t1, 0x605
    ctx->r9 = S32(0X605 << 16);
    // 0x8019BDBC: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8019BDC0: sw          $t9, 0x7E64($at)
    MEM_W(0X7E64, ctx->r1) = ctx->r25;
    // 0x8019BDC4: addiu       $t1, $t1, -0x5610
    ctx->r9 = ADD32(ctx->r9, -0X5610);
    // 0x8019BDC8: lui         $t0, 0x600
    ctx->r8 = S32(0X600 << 16);
    // 0x8019BDCC: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x8019BDD0: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x8019BDD4: jal         0x80005740
    // 0x8019BDD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_9;
    // 0x8019BDD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x8019BDDC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8019BDE0: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8019BDE4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8019BDE8: jr          $ra
    // 0x8019BDEC: nop

    return;
    // 0x8019BDEC: nop

;}
RECOMP_FUNC void Title_GreatFoxDeck_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80190950: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80190954: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80190958: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019095C: lwc1        $f4, -0x7D20($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7D20);
    // 0x80190960: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80190964: lwc1        $f8, -0x7D1C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X7D1C);
    // 0x80190968: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019096C: lwc1        $f16, -0x7D18($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X7D18);
    // 0x80190970: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80190974: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80190978: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8019097C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80190980: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80190984: lw          $t1, -0x7AA4($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X7AA4);
    // 0x80190988: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8019098C: lw          $t0, -0x7AA8($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7AA8);
    // 0x80190990: lw          $t9, -0x7AAC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7AAC);
    // 0x80190994: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80190998: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x8019099C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x801909A0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801909A4: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x801909A8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x801909AC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x801909B0: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x801909B4: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x801909B8: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x801909BC: jal         0x8000372C
    // 0x801909C0: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    Lights_SetOneLight(rdram, ctx);
        goto after_0;
    // 0x801909C0: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    after_0:
    // 0x801909C4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801909C8: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x801909CC: jal         0x800B8DD0
    // 0x801909D0: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    RCP_SetupDL(rdram, ctx);
        goto after_1;
    // 0x801909D0: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    after_1:
    // 0x801909D4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801909D8: jal         0x80005708
    // 0x801909DC: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Push(rdram, ctx);
        goto after_2;
    // 0x801909DC: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_2:
    // 0x801909E0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801909E4: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x801909E8: lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // 0x801909EC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801909F0: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x801909F4: lw          $a3, -0x6FB4($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X6FB4);
    // 0x801909F8: lw          $a2, -0x6FB8($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X6FB8);
    // 0x801909FC: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80190A00: jal         0x80005B00
    // 0x80190A04: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_3;
    // 0x80190A04: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_3:
    // 0x80190A08: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80190A0C: lwc1        $f0, 0x70CC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X70CC);
    // 0x80190A10: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80190A14: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80190A18: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80190A1C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80190A20: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80190A24: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80190A28: jal         0x80005C34
    // 0x80190A2C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Scale(rdram, ctx);
        goto after_4;
    // 0x80190A2C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_4:
    // 0x80190A30: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80190A34: jal         0x80006EB8
    // 0x80190A38: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_5;
    // 0x80190A38: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    after_5:
    // 0x80190A3C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80190A40: lw          $v1, 0x7E64($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7E64);
    // 0x80190A44: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80190A48: lui         $t6, 0x602
    ctx->r14 = S32(0X602 << 16);
    // 0x80190A4C: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x80190A50: sw          $t4, 0x7E64($at)
    MEM_W(0X7E64, ctx->r1) = ctx->r12;
    // 0x80190A54: addiu       $t6, $t6, -0x72C0
    ctx->r14 = ADD32(ctx->r14, -0X72C0);
    // 0x80190A58: lui         $t5, 0x600
    ctx->r13 = S32(0X600 << 16);
    // 0x80190A5C: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x80190A60: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x80190A64: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x80190A68: lw          $t7, 0x7BE4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7BE4);
    // 0x80190A6C: beq         $t7, $zero, L_80190A7C
    if (ctx->r15 == 0) {
        // 0x80190A70: nop
    
            goto L_80190A7C;
    }
    // 0x80190A70: nop

    // 0x80190A74: jal         0x80190A98
    // 0x80190A78: nop

    Title_GreatFoxDeckPlatform_Draw(rdram, ctx);
        goto after_6;
    // 0x80190A78: nop

    after_6:
L_80190A7C:
    // 0x80190A7C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80190A80: jal         0x80005740
    // 0x80190A84: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Pop(rdram, ctx);
        goto after_7;
    // 0x80190A84: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_7:
    // 0x80190A88: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80190A8C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80190A90: jr          $ra
    // 0x80190A94: nop

    return;
    // 0x80190A94: nop

;}
RECOMP_FUNC void Option_Vs_PointMatch_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019A124: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8019A128: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8019A12C: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8019A130: lw          $v0, -0x6ED4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6ED4);
    // 0x8019A134: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8019A138: beq         $v0, $zero, L_8019A160
    if (ctx->r2 == 0) {
        // 0x8019A13C: nop
    
            goto L_8019A160;
    }
    // 0x8019A13C: nop

    // 0x8019A140: beq         $v0, $at, L_8019A170
    if (ctx->r2 == ctx->r1) {
        // 0x8019A144: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8019A170;
    }
    // 0x8019A144: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8019A148: beq         $v0, $at, L_8019A180
    if (ctx->r2 == ctx->r1) {
        // 0x8019A14C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8019A180;
    }
    // 0x8019A14C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8019A150: beq         $v0, $at, L_8019A190
    if (ctx->r2 == ctx->r1) {
        // 0x8019A154: nop
    
            goto L_8019A190;
    }
    // 0x8019A154: nop

    // 0x8019A158: b           L_8019A19C
    // 0x8019A15C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8019A19C;
    // 0x8019A15C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8019A160:
    // 0x8019A160: jal         0x8019A2E0
    // 0x8019A164: nop

    Option_Vs_Point_Selection(rdram, ctx);
        goto after_0;
    // 0x8019A164: nop

    after_0:
    // 0x8019A168: b           L_8019A19C
    // 0x8019A16C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8019A19C;
    // 0x8019A16C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8019A170:
    // 0x8019A170: jal         0x8019A6DC
    // 0x8019A174: nop

    Option_VsStageSelection(rdram, ctx);
        goto after_1;
    // 0x8019A174: nop

    after_1:
    // 0x8019A178: b           L_8019A19C
    // 0x8019A17C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8019A19C;
    // 0x8019A17C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8019A180:
    // 0x8019A180: jal         0x8019A954
    // 0x8019A184: nop

    Option_VsConfirmSelection(rdram, ctx);
        goto after_2;
    // 0x8019A184: nop

    after_2:
    // 0x8019A188: b           L_8019A19C
    // 0x8019A18C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8019A19C;
    // 0x8019A18C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8019A190:
    // 0x8019A190: jal         0x8019A298
    // 0x8019A194: nop

    Option_Vs_StartMatch(rdram, ctx);
        goto after_3;
    // 0x8019A194: nop

    after_3:
    // 0x8019A198: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8019A19C:
    // 0x8019A19C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8019A1A0: jr          $ra
    // 0x8019A1A4: nop

    return;
    // 0x8019A1A4: nop

;}
RECOMP_FUNC void Option_Color_FlashRed(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019C824: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8019C828: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8019C82C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8019C830: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8019C834: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019C838: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x8019C83C: lw          $a1, -0x6E1C($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X6E1C);
    // 0x8019C840: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8019C844: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    // 0x8019C848: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x8019C84C: jal         0x8009BC2C
    // 0x8019C850: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_0;
    // 0x8019C850: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x8019C854: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8019C858: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8019C85C: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8019C860: addiu       $v0, $v0, -0x6E1C
    ctx->r2 = ADD32(ctx->r2, -0X6E1C);
    // 0x8019C864: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x8019C868: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8019C86C: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x8019C870: nop

    // 0x8019C874: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8019C878: c.eq.s      $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f6.fl == ctx->f16.fl;
    // 0x8019C87C: nop

    // 0x8019C880: bc1f        L_8019C8B4
    if (!c1cs) {
        // 0x8019C884: lui         $at, 0x4200
        ctx->r1 = S32(0X4200 << 16);
            goto L_8019C8B4;
    }
    // 0x8019C884: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x8019C888: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8019C88C: lwc1        $f18, 0x0($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0X0);
    // 0x8019C890: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x8019C894: c.eq.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl == ctx->f18.fl;
    // 0x8019C898: nop

    // 0x8019C89C: bc1fl       L_8019C8B4
    if (!c1cs) {
        // 0x8019C8A0: swc1        $f0, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
            goto L_8019C8B4;
    }
    goto skip_0;
    // 0x8019C8A0: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    skip_0:
    // 0x8019C8A4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019C8A8: b           L_8019C8B4
    // 0x8019C8AC: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
        goto L_8019C8B4;
    // 0x8019C8AC: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x8019C8B0: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
L_8019C8B4:
    // 0x8019C8B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8019C8B8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8019C8BC: jr          $ra
    // 0x8019C8C0: nop

    return;
    // 0x8019C8C0: nop

;}
RECOMP_FUNC void Map_GetPlanetId(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A6480: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x801A6484: sltiu       $at, $a0, 0x14
    ctx->r1 = ctx->r4 < 0X14 ? 1 : 0;
    // 0x801A6488: beq         $at, $zero, L_801A6550
    if (ctx->r1 == 0) {
        // 0x801A648C: sll         $t6, $a0, 2
        ctx->r14 = S32(ctx->r4 << 2);
            goto L_801A6550;
    }
    // 0x801A648C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x801A6490: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A6494: addu        $at, $at, $t6
    gpr jr_addend_801A649C = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x801A6498: lw          $t6, 0x78EC($at)
    ctx->r14 = ADD32(ctx->r1, 0X78EC);
    // 0x801A649C: jr          $t6
    // 0x801A64A0: nop

    switch (jr_addend_801A649C >> 2) {
        case 0: goto L_801A64A4; break;
        case 1: goto L_801A64B0; break;
        case 2: goto L_801A650C; break;
        case 3: goto L_801A64E8; break;
        case 4: goto L_801A6550; break;
        case 5: goto L_801A6530; break;
        case 6: goto L_801A653C; break;
        case 7: goto L_801A6548; break;
        case 8: goto L_801A6524; break;
        case 9: goto L_801A653C; break;
        case 10: goto L_801A6550; break;
        case 11: goto L_801A6518; break;
        case 12: goto L_801A64B8; break;
        case 13: goto L_801A64C4; break;
        case 14: goto L_801A6500; break;
        case 15: goto L_801A6550; break;
        case 16: goto L_801A64DC; break;
        case 17: goto L_801A64D0; break;
        case 18: goto L_801A64F4; break;
        case 19: goto L_801A653C; break;
        default: switch_error(__func__, 0x801A649C, 0x801B78EC);
    }
    // 0x801A64A0: nop

L_801A64A4:
    // 0x801A64A4: addiu       $t7, $zero, 0x9
    ctx->r15 = ADD32(0, 0X9);
    // 0x801A64A8: b           L_801A6550
    // 0x801A64AC: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
        goto L_801A6550;
    // 0x801A64AC: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
L_801A64B0:
    // 0x801A64B0: b           L_801A6550
    // 0x801A64B4: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
        goto L_801A6550;
    // 0x801A64B4: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_801A64B8:
    // 0x801A64B8: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x801A64BC: b           L_801A6550
    // 0x801A64C0: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
        goto L_801A6550;
    // 0x801A64C0: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
L_801A64C4:
    // 0x801A64C4: addiu       $t9, $zero, 0xB
    ctx->r25 = ADD32(0, 0XB);
    // 0x801A64C8: b           L_801A6550
    // 0x801A64CC: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
        goto L_801A6550;
    // 0x801A64CC: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
L_801A64D0:
    // 0x801A64D0: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x801A64D4: b           L_801A6550
    // 0x801A64D8: sw          $t0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r8;
        goto L_801A6550;
    // 0x801A64D8: sw          $t0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r8;
L_801A64DC:
    // 0x801A64DC: addiu       $t1, $zero, 0x6
    ctx->r9 = ADD32(0, 0X6);
    // 0x801A64E0: b           L_801A6550
    // 0x801A64E4: sw          $t1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r9;
        goto L_801A6550;
    // 0x801A64E4: sw          $t1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r9;
L_801A64E8:
    // 0x801A64E8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801A64EC: b           L_801A6550
    // 0x801A64F0: sw          $t2, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r10;
        goto L_801A6550;
    // 0x801A64F0: sw          $t2, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r10;
L_801A64F4:
    // 0x801A64F4: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x801A64F8: b           L_801A6550
    // 0x801A64FC: sw          $t3, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r11;
        goto L_801A6550;
    // 0x801A64FC: sw          $t3, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r11;
L_801A6500:
    // 0x801A6500: addiu       $t4, $zero, 0xC
    ctx->r12 = ADD32(0, 0XC);
    // 0x801A6504: b           L_801A6550
    // 0x801A6508: sw          $t4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r12;
        goto L_801A6550;
    // 0x801A6508: sw          $t4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r12;
L_801A650C:
    // 0x801A650C: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x801A6510: b           L_801A6550
    // 0x801A6514: sw          $t5, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r13;
        goto L_801A6550;
    // 0x801A6514: sw          $t5, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r13;
L_801A6518:
    // 0x801A6518: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
    // 0x801A651C: b           L_801A6550
    // 0x801A6520: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
        goto L_801A6550;
    // 0x801A6520: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
L_801A6524:
    // 0x801A6524: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x801A6528: b           L_801A6550
    // 0x801A652C: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
        goto L_801A6550;
    // 0x801A652C: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
L_801A6530:
    // 0x801A6530: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x801A6534: b           L_801A6550
    // 0x801A6538: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
        goto L_801A6550;
    // 0x801A6538: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
L_801A653C:
    // 0x801A653C: addiu       $t9, $zero, 0xD
    ctx->r25 = ADD32(0, 0XD);
    // 0x801A6540: b           L_801A6550
    // 0x801A6544: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
        goto L_801A6550;
    // 0x801A6544: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
L_801A6548:
    // 0x801A6548: addiu       $t0, $zero, 0xE
    ctx->r8 = ADD32(0, 0XE);
    // 0x801A654C: sw          $t0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r8;
L_801A6550:
    // 0x801A6550: lw          $v0, 0x4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4);
    // 0x801A6554: jr          $ra
    // 0x801A6558: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x801A6558: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void Map_801A3440(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A3440: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x801A3444: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801A3448: addiu       $v1, $v1, -0x1128
    ctx->r3 = ADD32(ctx->r3, -0X1128);
    // 0x801A344C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801A3450: swc1        $f12, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f12.u32l;
    // 0x801A3454: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x801A3458: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801A345C: lui         $t0, 0x801D
    ctx->r8 = S32(0X801D << 16);
    // 0x801A3460: beq         $t1, $at, L_801A3540
    if (ctx->r9 == ctx->r1) {
        // 0x801A3464: addiu       $t0, $t0, -0x1124
        ctx->r8 = ADD32(ctx->r8, -0X1124);
            goto L_801A3540;
    }
    // 0x801A3464: addiu       $t0, $t0, -0x1124
    ctx->r8 = ADD32(ctx->r8, -0X1124);
    // 0x801A3468: sll         $v0, $t1, 2
    ctx->r2 = S32(ctx->r9 << 2);
    // 0x801A346C: subu        $v0, $v0, $t1
    ctx->r2 = SUB32(ctx->r2, ctx->r9);
    // 0x801A3470: lui         $t6, 0x801D
    ctx->r14 = S32(0X801D << 16);
    // 0x801A3474: lui         $t7, 0x801D
    ctx->r15 = S32(0X801D << 16);
    // 0x801A3478: addiu       $t7, $t7, -0x10A8
    ctx->r15 = ADD32(ctx->r15, -0X10A8);
    // 0x801A347C: addiu       $t6, $t6, -0x1118
    ctx->r14 = ADD32(ctx->r14, -0X1118);
    // 0x801A3480: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x801A3484: addu        $a1, $v0, $t6
    ctx->r5 = ADD32(ctx->r2, ctx->r14);
    // 0x801A3488: addu        $a2, $v0, $t7
    ctx->r6 = ADD32(ctx->r2, ctx->r15);
    // 0x801A348C: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x801A3490: jal         0x801A3550
    // 0x801A3494: lw          $a3, 0x0($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X0);
    Map_801A3550(rdram, ctx);
        goto after_0;
    // 0x801A3494: lw          $a3, 0x0($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X0);
    after_0:
    // 0x801A3498: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x801A349C: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x801A34A0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A34A4: swc1        $f4, -0x260C($at)
    MEM_W(-0X260C, ctx->r1) = ctx->f4.u32l;
    // 0x801A34A8: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801A34AC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A34B0: swc1        $f6, -0x2608($at)
    MEM_W(-0X2608, ctx->r1) = ctx->f6.u32l;
    // 0x801A34B4: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801A34B8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A34BC: swc1        $f8, -0x2604($at)
    MEM_W(-0X2604, ctx->r1) = ctx->f8.u32l;
    // 0x801A34C0: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x801A34C4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A34C8: swc1        $f10, -0x2600($at)
    MEM_W(-0X2600, ctx->r1) = ctx->f10.u32l;
    // 0x801A34CC: lwc1        $f18, 0x34($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X34);
    // 0x801A34D0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A34D4: swc1        $f16, -0x25FC($at)
    MEM_W(-0X25FC, ctx->r1) = ctx->f16.u32l;
    // 0x801A34D8: lui         $t0, 0x801D
    ctx->r8 = S32(0X801D << 16);
    // 0x801A34DC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A34E0: addiu       $t0, $t0, -0x1124
    ctx->r8 = ADD32(ctx->r8, -0X1124);
    // 0x801A34E4: swc1        $f18, -0x25F8($at)
    MEM_W(-0X25F8, ctx->r1) = ctx->f18.u32l;
    // 0x801A34E8: lwc1        $f4, 0x0($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X0);
    // 0x801A34EC: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x801A34F0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801A34F4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801A34F8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801A34FC: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801A3500: addiu       $v1, $v1, -0x1128
    ctx->r3 = ADD32(ctx->r3, -0X1128);
    // 0x801A3504: swc1        $f8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f8.u32l;
    // 0x801A3508: lwc1        $f16, 0x0($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X0);
    // 0x801A350C: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x801A3510: nop

    // 0x801A3514: bc1fl       L_801A3544
    if (!c1cs) {
        // 0x801A3518: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801A3544;
    }
    goto skip_0;
    // 0x801A3518: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801A351C: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x801A3520: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801A3524: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x801A3528: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x801A352C: slti        $at, $t9, 0x6
    ctx->r1 = SIGNED(ctx->r25) < 0X6 ? 1 : 0;
    // 0x801A3530: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x801A3534: bne         $at, $zero, L_801A3540
    if (ctx->r1 != 0) {
        // 0x801A3538: swc1        $f18, 0x0($t0)
        MEM_W(0X0, ctx->r8) = ctx->f18.u32l;
            goto L_801A3540;
    }
    // 0x801A3538: swc1        $f18, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f18.u32l;
    // 0x801A353C: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
L_801A3540:
    // 0x801A3540: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801A3544:
    // 0x801A3544: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x801A3548: jr          $ra
    // 0x801A354C: nop

    return;
    // 0x801A354C: nop

;}
RECOMP_FUNC void Title_CsTakeOffSpace_Setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018C1C0: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x8018C1C4: sw          $ra, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r31;
    // 0x8018C1C8: sw          $fp, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r30;
    // 0x8018C1CC: sw          $s7, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r23;
    // 0x8018C1D0: sw          $s6, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r22;
    // 0x8018C1D4: sw          $s5, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r21;
    // 0x8018C1D8: sw          $s4, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r20;
    // 0x8018C1DC: sw          $s3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r19;
    // 0x8018C1E0: sw          $s2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r18;
    // 0x8018C1E4: sw          $s1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r17;
    // 0x8018C1E8: sw          $s0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r16;
    // 0x8018C1EC: sdc1        $f30, 0x68($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X68, ctx->r29);
    // 0x8018C1F0: sdc1        $f28, 0x60($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X60, ctx->r29);
    // 0x8018C1F4: sdc1        $f26, 0x58($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X58, ctx->r29);
    // 0x8018C1F8: sdc1        $f24, 0x50($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X50, ctx->r29);
    // 0x8018C1FC: sdc1        $f22, 0x48($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X48, ctx->r29);
    // 0x8018C200: sdc1        $f20, 0x40($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X40, ctx->r29);
    // 0x8018C204: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8018C208: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018C20C: sw          $t6, -0x7BF0($at)
    MEM_W(-0X7BF0, ctx->r1) = ctx->r14;
    // 0x8018C210: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018C214: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x8018C218: sw          $t7, 0x7C98($at)
    MEM_W(0X7C98, ctx->r1) = ctx->r15;
    // 0x8018C21C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018C220: lwc1        $f30, 0x6FC0($at)
    ctx->f30.u32l = MEM_W(ctx->r1, 0X6FC0);
    // 0x8018C224: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x8018C228: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x8018C22C: lui         $at, 0xC270
    ctx->r1 = S32(0XC270 << 16);
    // 0x8018C230: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x8018C234: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018C238: lwc1        $f24, 0x6FC4($at)
    ctx->f24.u32l = MEM_W(ctx->r1, 0X6FC4);
    // 0x8018C23C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8018C240: lui         $s1, 0x801B
    ctx->r17 = S32(0X801B << 16);
    // 0x8018C244: lui         $s2, 0x801B
    ctx->r18 = S32(0X801B << 16);
    // 0x8018C248: lui         $s3, 0x801B
    ctx->r19 = S32(0X801B << 16);
    // 0x8018C24C: lui         $s4, 0x801B
    ctx->r20 = S32(0X801B << 16);
    // 0x8018C250: lui         $s5, 0x801B
    ctx->r21 = S32(0X801B << 16);
    // 0x8018C254: lui         $s6, 0x801B
    ctx->r22 = S32(0X801B << 16);
    // 0x8018C258: lui         $s7, 0x801B
    ctx->r23 = S32(0X801B << 16);
    // 0x8018C25C: lui         $s0, 0x801B
    ctx->r16 = S32(0X801B << 16);
    // 0x8018C260: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8018C264: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8018C268: addiu       $s0, $s0, 0x7CA0
    ctx->r16 = ADD32(ctx->r16, 0X7CA0);
    // 0x8018C26C: addiu       $s7, $s7, 0x7CF0
    ctx->r23 = ADD32(ctx->r23, 0X7CF0);
    // 0x8018C270: addiu       $s6, $s6, 0x7CC8
    ctx->r22 = ADD32(ctx->r22, 0X7CC8);
    // 0x8018C274: addiu       $s5, $s5, 0x7D18
    ctx->r21 = ADD32(ctx->r21, 0X7D18);
    // 0x8018C278: addiu       $s4, $s4, 0x7C70
    ctx->r20 = ADD32(ctx->r20, 0X7C70);
    // 0x8018C27C: addiu       $s3, $s3, 0x7C48
    ctx->r19 = ADD32(ctx->r19, 0X7C48);
    // 0x8018C280: addiu       $s2, $s2, 0x7C20
    ctx->r18 = ADD32(ctx->r18, 0X7C20);
    // 0x8018C284: addiu       $s1, $s1, 0x7BF8
    ctx->r17 = ADD32(ctx->r17, 0X7BF8);
    // 0x8018C288: addiu       $fp, $zero, 0x80
    ctx->r30 = ADD32(0, 0X80);
L_8018C28C:
    // 0x8018C28C: jal         0x80004EB0
    // 0x8018C290: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_0;
    // 0x8018C290: nop

    after_0:
    // 0x8018C294: mul.s       $f4, $f0, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x8018C298: add.s       $f6, $f4, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f22.fl;
    // 0x8018C29C: jal         0x80004EB0
    // 0x8018C2A0: swc1        $f6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f6.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x8018C2A0: swc1        $f6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f6.u32l;
    after_1:
    // 0x8018C2A4: mul.s       $f8, $f0, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f26.fl);
    // 0x8018C2A8: swc1        $f20, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f20.u32l;
    // 0x8018C2AC: add.s       $f10, $f8, $f28
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f28.fl;
    // 0x8018C2B0: jal         0x80004EB0
    // 0x8018C2B4: swc1        $f10, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f10.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_2;
    // 0x8018C2B4: swc1        $f10, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f10.u32l;
    after_2:
    // 0x8018C2B8: mul.s       $f16, $f0, $f30
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f30.fl);
    // 0x8018C2BC: add.s       $f18, $f16, $f24
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f24.fl;
    // 0x8018C2C0: jal         0x80004EB0
    // 0x8018C2C4: swc1        $f18, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->f18.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_3;
    // 0x8018C2C4: swc1        $f18, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->f18.u32l;
    after_3:
    // 0x8018C2C8: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8018C2CC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018C2D0: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x8018C2D4: addiu       $t8, $t8, 0x7CC8
    ctx->r24 = ADD32(ctx->r24, 0X7CC8);
    // 0x8018C2D8: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8018C2DC: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8018C2E0: sltu        $at, $s0, $t8
    ctx->r1 = ctx->r16 < ctx->r24 ? 1 : 0;
    // 0x8018C2E4: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8018C2E8: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8018C2EC: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x8018C2F0: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x8018C2F4: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8018C2F8: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x8018C2FC: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
    // 0x8018C300: addiu       $s6, $s6, 0x4
    ctx->r22 = ADD32(ctx->r22, 0X4);
    // 0x8018C304: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x8018C308: addiu       $s7, $s7, 0x4
    ctx->r23 = ADD32(ctx->r23, 0X4);
    // 0x8018C30C: sw          $t7, -0x4($s6)
    MEM_W(-0X4, ctx->r22) = ctx->r15;
    // 0x8018C310: addiu       $t6, $t9, 0x5
    ctx->r14 = ADD32(ctx->r25, 0X5);
    // 0x8018C314: sw          $t6, -0x4($s5)
    MEM_W(-0X4, ctx->r21) = ctx->r14;
    // 0x8018C318: sw          $fp, -0x4($s7)
    MEM_W(-0X4, ctx->r23) = ctx->r30;
    // 0x8018C31C: bne         $at, $zero, L_8018C28C
    if (ctx->r1 != 0) {
        // 0x8018C320: sw          $zero, -0x4($s0)
        MEM_W(-0X4, ctx->r16) = 0;
            goto L_8018C28C;
    }
    // 0x8018C320: sw          $zero, -0x4($s0)
    MEM_W(-0X4, ctx->r16) = 0;
    // 0x8018C324: lui         $at, 0xC1F0
    ctx->r1 = S32(0XC1F0 << 16);
    // 0x8018C328: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8018C32C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8018C330: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018C334: sw          $a3, -0x7960($at)
    MEM_W(-0X7960, ctx->r1) = ctx->r7;
    // 0x8018C338: lui         $at, 0xC218
    ctx->r1 = S32(0XC218 << 16);
    // 0x8018C33C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018C340: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x8018C344: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8018C348: lui         $at, 0xC20C
    ctx->r1 = S32(0XC20C << 16);
    // 0x8018C34C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8018C350: lui         $at, 0xC248
    ctx->r1 = S32(0XC248 << 16);
    // 0x8018C354: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018C358: lui         $at, 0x42D2
    ctx->r1 = S32(0X42D2 << 16);
    // 0x8018C35C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018C360: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8018C364: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018C368: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x8018C36C: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x8018C370: lui         $t2, 0x801C
    ctx->r10 = S32(0X801C << 16);
    // 0x8018C374: lui         $t3, 0x801C
    ctx->r11 = S32(0X801C << 16);
    // 0x8018C378: lui         $t4, 0x801C
    ctx->r12 = S32(0X801C << 16);
    // 0x8018C37C: lui         $t5, 0x801C
    ctx->r13 = S32(0X801C << 16);
    // 0x8018C380: lui         $ra, 0x801C
    ctx->r31 = S32(0X801C << 16);
    // 0x8018C384: addiu       $ra, $ra, -0x7948
    ctx->r31 = ADD32(ctx->r31, -0X7948);
    // 0x8018C388: addiu       $t5, $t5, -0x794C
    ctx->r13 = ADD32(ctx->r13, -0X794C);
    // 0x8018C38C: addiu       $t4, $t4, -0x7954
    ctx->r12 = ADD32(ctx->r12, -0X7954);
    // 0x8018C390: addiu       $t3, $t3, -0x7958
    ctx->r11 = ADD32(ctx->r11, -0X7958);
    // 0x8018C394: addiu       $t2, $t2, -0x793C
    ctx->r10 = ADD32(ctx->r10, -0X793C);
    // 0x8018C398: addiu       $t1, $t1, -0x7940
    ctx->r9 = ADD32(ctx->r9, -0X7940);
    // 0x8018C39C: addiu       $t0, $t0, -0x7944
    ctx->r8 = ADD32(ctx->r8, -0X7944);
    // 0x8018C3A0: swc1        $f20, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f20.u32l;
    // 0x8018C3A4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018C3A8: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8018C3AC: swc1        $f10, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f10.u32l;
    // 0x8018C3B0: swc1        $f16, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f16.u32l;
    // 0x8018C3B4: swc1        $f18, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f18.u32l;
    // 0x8018C3B8: swc1        $f4, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f4.u32l;
    // 0x8018C3BC: swc1        $f6, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f6.u32l;
    // 0x8018C3C0: swc1        $f8, 0x0($ra)
    MEM_W(0X0, ctx->r31) = ctx->f8.u32l;
    // 0x8018C3C4: sw          $t9, -0x7964($at)
    MEM_W(-0X7964, ctx->r1) = ctx->r25;
    // 0x8018C3C8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018C3CC: sw          $zero, -0x7CC0($at)
    MEM_W(-0X7CC0, ctx->r1) = 0;
    // 0x8018C3D0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018C3D4: sw          $zero, -0x7CB8($at)
    MEM_W(-0X7CB8, ctx->r1) = 0;
    // 0x8018C3D8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018C3DC: sw          $zero, -0x7CB0($at)
    MEM_W(-0X7CB0, ctx->r1) = 0;
    // 0x8018C3E0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018C3E4: sw          $zero, -0x7CAC($at)
    MEM_W(-0X7CAC, ctx->r1) = 0;
    // 0x8018C3E8: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8018C3EC: lui         $at, 0x4302
    ctx->r1 = S32(0X4302 << 16);
    // 0x8018C3F0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018C3F4: addiu       $v1, $v1, -0x79A8
    ctx->r3 = ADD32(ctx->r3, -0X79A8);
    // 0x8018C3F8: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x8018C3FC: lui         $at, 0x44FA
    ctx->r1 = S32(0X44FA << 16);
    // 0x8018C400: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8018C404: addiu       $a2, $a2, -0x7978
    ctx->r6 = ADD32(ctx->r6, -0X7978);
    // 0x8018C408: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8018C40C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8018C410: sw          $zero, 0xC($a2)
    MEM_W(0XC, ctx->r6) = 0;
    // 0x8018C414: swc1        $f20, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f20.u32l;
    // 0x8018C418: swc1        $f20, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f20.u32l;
    // 0x8018C41C: swc1        $f20, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f20.u32l;
    // 0x8018C420: swc1        $f20, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f20.u32l;
    // 0x8018C424: swc1        $f20, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->f20.u32l;
    // 0x8018C428: swc1        $f20, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f20.u32l;
    // 0x8018C42C: swc1        $f24, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f24.u32l;
    // 0x8018C430: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018C434: swc1        $f0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f0.u32l;
    // 0x8018C438: swc1        $f10, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f10.u32l;
    // 0x8018C43C: swc1        $f16, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f16.u32l;
    // 0x8018C440: swc1        $f18, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->f18.u32l;
    // 0x8018C444: swc1        $f20, -0x7938($at)
    MEM_W(-0X7938, ctx->r1) = ctx->f20.u32l;
    // 0x8018C448: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018C44C: swc1        $f20, -0x7934($at)
    MEM_W(-0X7934, ctx->r1) = ctx->f20.u32l;
    // 0x8018C450: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018C454: addiu       $t6, $zero, 0x65
    ctx->r14 = ADD32(0, 0X65);
    // 0x8018C458: sw          $t6, -0x7AB8($at)
    MEM_W(-0X7AB8, ctx->r1) = ctx->r14;
    // 0x8018C45C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018C460: addiu       $t7, $zero, 0x6A
    ctx->r15 = ADD32(0, 0X6A);
    // 0x8018C464: sw          $t7, -0x7AB4($at)
    MEM_W(-0X7AB4, ctx->r1) = ctx->r15;
    // 0x8018C468: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018C46C: addiu       $t8, $zero, 0x5C
    ctx->r24 = ADD32(0, 0X5C);
    // 0x8018C470: sw          $t8, -0x7AB0($at)
    MEM_W(-0X7AB0, ctx->r1) = ctx->r24;
    // 0x8018C474: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018C478: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x8018C47C: sw          $t9, -0x7AAC($at)
    MEM_W(-0X7AAC, ctx->r1) = ctx->r25;
    // 0x8018C480: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8018C484: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018C488: sw          $a1, -0x7AA8($at)
    MEM_W(-0X7AA8, ctx->r1) = ctx->r5;
    // 0x8018C48C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018C490: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x8018C494: sw          $t6, -0x7AA4($at)
    MEM_W(-0X7AA4, ctx->r1) = ctx->r14;
    // 0x8018C498: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018C49C: lwc1        $f14, 0x6FC8($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X6FC8);
    // 0x8018C4A0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018C4A4: lwc1        $f12, 0x6FCC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X6FCC);
    // 0x8018C4A8: lui         $at, 0xC220
    ctx->r1 = S32(0XC220 << 16);
    // 0x8018C4AC: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8018C4B0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8018C4B4: addiu       $v0, $v0, -0x7B18
    ctx->r2 = ADD32(ctx->r2, -0X7B18);
    // 0x8018C4B8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8018C4BC:
    // 0x8018C4BC: addiu       $v1, $a0, 0x1
    ctx->r3 = ADD32(ctx->r4, 0X1);
    // 0x8018C4C0: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x8018C4C4: addiu       $v0, $v0, 0x5C
    ctx->r2 = ADD32(ctx->r2, 0X5C);
    // 0x8018C4C8: swc1        $f20, -0x5C($v0)
    MEM_W(-0X5C, ctx->r2) = ctx->f20.u32l;
    // 0x8018C4CC: swc1        $f2, -0x58($v0)
    MEM_W(-0X58, ctx->r2) = ctx->f2.u32l;
    // 0x8018C4D0: swc1        $f0, -0x54($v0)
    MEM_W(-0X54, ctx->r2) = ctx->f0.u32l;
    // 0x8018C4D4: swc1        $f24, -0x50($v0)
    MEM_W(-0X50, ctx->r2) = ctx->f24.u32l;
    // 0x8018C4D8: swc1        $f20, -0x44($v0)
    MEM_W(-0X44, ctx->r2) = ctx->f20.u32l;
    // 0x8018C4DC: swc1        $f20, -0x40($v0)
    MEM_W(-0X40, ctx->r2) = ctx->f20.u32l;
    // 0x8018C4E0: swc1        $f20, -0x3C($v0)
    MEM_W(-0X3C, ctx->r2) = ctx->f20.u32l;
    // 0x8018C4E4: swc1        $f12, -0x4C($v0)
    MEM_W(-0X4C, ctx->r2) = ctx->f12.u32l;
    // 0x8018C4E8: swc1        $f20, -0x38($v0)
    MEM_W(-0X38, ctx->r2) = ctx->f20.u32l;
    // 0x8018C4EC: swc1        $f20, -0x34($v0)
    MEM_W(-0X34, ctx->r2) = ctx->f20.u32l;
    // 0x8018C4F0: swc1        $f20, -0x30($v0)
    MEM_W(-0X30, ctx->r2) = ctx->f20.u32l;
    // 0x8018C4F4: swc1        $f20, -0x2C($v0)
    MEM_W(-0X2C, ctx->r2) = ctx->f20.u32l;
    // 0x8018C4F8: sw          $v1, -0x28($v0)
    MEM_W(-0X28, ctx->r2) = ctx->r3;
    // 0x8018C4FC: sw          $a3, -0x20($v0)
    MEM_W(-0X20, ctx->r2) = ctx->r7;
    // 0x8018C500: sw          $zero, -0x1C($v0)
    MEM_W(-0X1C, ctx->r2) = 0;
    // 0x8018C504: swc1        $f14, -0x18($v0)
    MEM_W(-0X18, ctx->r2) = ctx->f14.u32l;
    // 0x8018C508: sw          $zero, -0x14($v0)
    MEM_W(-0X14, ctx->r2) = 0;
    // 0x8018C50C: bne         $v1, $a1, L_8018C4BC
    if (ctx->r3 != ctx->r5) {
        // 0x8018C510: sw          $zero, -0x10($v0)
        MEM_W(-0X10, ctx->r2) = 0;
            goto L_8018C4BC;
    }
    // 0x8018C510: sw          $zero, -0x10($v0)
    MEM_W(-0X10, ctx->r2) = 0;
    // 0x8018C514: lui         $at, 0xC100
    ctx->r1 = S32(0XC100 << 16);
    // 0x8018C518: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018C51C: lui         $at, 0xC214
    ctx->r1 = S32(0XC214 << 16);
    // 0x8018C520: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018C524: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x8018C528: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018C52C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018C530: swc1        $f4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f4.u32l;
    // 0x8018C534: swc1        $f6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f6.u32l;
    // 0x8018C538: swc1        $f8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f8.u32l;
    // 0x8018C53C: lwc1        $f10, 0x6FD0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6FD0);
    // 0x8018C540: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018C544: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x8018C548: swc1        $f10, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f10.u32l;
    // 0x8018C54C: lwc1        $f16, 0x6FD4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6FD4);
    // 0x8018C550: lui         $at, 0x436B
    ctx->r1 = S32(0X436B << 16);
    // 0x8018C554: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8018C558: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8018C55C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018C560: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018C564: swc1        $f16, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f16.u32l;
    // 0x8018C568: swc1        $f18, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f18.u32l;
    // 0x8018C56C: swc1        $f4, 0x0($ra)
    MEM_W(0X0, ctx->r31) = ctx->f4.u32l;
    // 0x8018C570: swc1        $f20, -0x7D64($at)
    MEM_W(-0X7D64, ctx->r1) = ctx->f20.u32l;
    // 0x8018C574: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8018C578: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018C57C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018C580: addiu       $t7, $t7, 0x7980
    ctx->r15 = ADD32(ctx->r15, 0X7980);
    // 0x8018C584: swc1        $f6, -0x7D60($at)
    MEM_W(-0X7D60, ctx->r1) = ctx->f6.u32l;
    // 0x8018C588: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018C58C: swc1        $f20, -0x7D5C($at)
    MEM_W(-0X7D5C, ctx->r1) = ctx->f20.u32l;
    // 0x8018C590: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8018C594: lwc1        $f18, 0x0($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X0);
    // 0x8018C598: lwc1        $f16, 0x0($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0X0);
    // 0x8018C59C: lwc1        $f10, 0x0($ra)
    ctx->f10.u32l = MEM_W(ctx->r31, 0X0);
    // 0x8018C5A0: lwc1        $f8, 0x0($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0X0);
    // 0x8018C5A4: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x8018C5A8: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x8018C5AC: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x8018C5B0: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x8018C5B4: addiu       $t6, $t6, 0x79B8
    ctx->r14 = ADD32(ctx->r14, 0X79B8);
    // 0x8018C5B8: addiu       $t9, $t9, 0x79A0
    ctx->r25 = ADD32(ctx->r25, 0X79A0);
    // 0x8018C5BC: addiu       $t8, $t8, 0x7988
    ctx->r24 = ADD32(ctx->r24, 0X7988);
    // 0x8018C5C0: addiu       $t7, $t7, 0x79C0
    ctx->r15 = ADD32(ctx->r15, 0X79C0);
    // 0x8018C5C4: lui         $a3, 0x8017
    ctx->r7 = S32(0X8017 << 16);
    // 0x8018C5C8: addiu       $a3, $a3, 0x7978
    ctx->r7 = ADD32(ctx->r7, 0X7978);
    // 0x8018C5CC: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x8018C5D0: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8018C5D4: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8018C5D8: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x8018C5DC: lw          $a2, 0x0($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X0);
    // 0x8018C5E0: lwc1        $f14, 0x0($t1)
    ctx->f14.u32l = MEM_W(ctx->r9, 0X0);
    // 0x8018C5E4: lwc1        $f12, 0x0($t0)
    ctx->f12.u32l = MEM_W(ctx->r8, 0X0);
    // 0x8018C5E8: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    // 0x8018C5EC: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    // 0x8018C5F0: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x8018C5F4: jal         0x801914AC
    // 0x8018C5F8: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    Title_SetCamUp2(rdram, ctx);
        goto after_4;
    // 0x8018C5F8: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    after_4:
    // 0x8018C5FC: lw          $ra, 0x94($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X94);
    // 0x8018C600: ldc1        $f20, 0x40($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X40);
    // 0x8018C604: ldc1        $f22, 0x48($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X48);
    // 0x8018C608: ldc1        $f24, 0x50($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X50);
    // 0x8018C60C: ldc1        $f26, 0x58($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X58);
    // 0x8018C610: ldc1        $f28, 0x60($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X60);
    // 0x8018C614: ldc1        $f30, 0x68($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X68);
    // 0x8018C618: lw          $s0, 0x70($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X70);
    // 0x8018C61C: lw          $s1, 0x74($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X74);
    // 0x8018C620: lw          $s2, 0x78($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X78);
    // 0x8018C624: lw          $s3, 0x7C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X7C);
    // 0x8018C628: lw          $s4, 0x80($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X80);
    // 0x8018C62C: lw          $s5, 0x84($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X84);
    // 0x8018C630: lw          $s6, 0x88($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X88);
    // 0x8018C634: lw          $s7, 0x8C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X8C);
    // 0x8018C638: lw          $fp, 0x90($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X90);
    // 0x8018C63C: jr          $ra
    // 0x8018C640: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x8018C640: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void OvlMenu_CallFunction(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80187520: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80187524: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80187528: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8018752C: addiu       $t6, $a0, -0x67
    ctx->r14 = ADD32(ctx->r4, -0X67);
    // 0x80187530: sltiu       $at, $t6, 0x8
    ctx->r1 = ctx->r14 < 0X8 ? 1 : 0;
    // 0x80187534: beq         $at, $zero, L_801875C8
    if (ctx->r1 == 0) {
        // 0x80187538: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_801875C8;
    }
    // 0x80187538: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8018753C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80187540: addu        $at, $at, $t6
    gpr jr_addend_80187548 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80187544: lw          $t6, 0x6D50($at)
    ctx->r14 = ADD32(ctx->r1, 0X6D50);
    // 0x80187548: jr          $t6
    // 0x8018754C: nop

    switch (jr_addend_80187548 >> 2) {
        case 0: goto L_80187550; break;
        case 1: goto L_80187560; break;
        case 2: goto L_80187570; break;
        case 3: goto L_80187580; break;
        case 4: goto L_80187590; break;
        case 5: goto L_801875A0; break;
        case 6: goto L_801875B0; break;
        case 7: goto L_801875C0; break;
        default: switch_error(__func__, 0x80187548, 0x801B6D50);
    }
    // 0x8018754C: nop

L_80187550:
    // 0x80187550: jal         0x80187754
    // 0x80187554: nop

    Title_Main(rdram, ctx);
        goto after_0;
    // 0x80187554: nop

    after_0:
    // 0x80187558: b           L_801875CC
    // 0x8018755C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801875CC;
    // 0x8018755C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80187560:
    // 0x80187560: jal         0x801878D8
    // 0x80187564: nop

    Title_Draw(rdram, ctx);
        goto after_1;
    // 0x80187564: nop

    after_1:
    // 0x80187568: b           L_801875CC
    // 0x8018756C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801875CC;
    // 0x8018756C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80187570:
    // 0x80187570: jal         0x8019E8D0
    // 0x80187574: nop

    Map_Main(rdram, ctx);
        goto after_2;
    // 0x80187574: nop

    after_2:
    // 0x80187578: b           L_801875CC
    // 0x8018757C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801875CC;
    // 0x8018757C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80187580:
    // 0x80187580: jal         0x801A01A8
    // 0x80187584: nop

    Map_Draw(rdram, ctx);
        goto after_3;
    // 0x80187584: nop

    after_3:
    // 0x80187588: b           L_801875CC
    // 0x8018758C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801875CC;
    // 0x8018758C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80187590:
    // 0x80187590: jal         0x801920C4
    // 0x80187594: nop

    Option_Main(rdram, ctx);
        goto after_4;
    // 0x80187594: nop

    after_4:
    // 0x80187598: b           L_801875CC
    // 0x8018759C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801875CC;
    // 0x8018759C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801875A0:
    // 0x801875A0: jal         0x80192340
    // 0x801875A4: nop

    Option_Entry_Draw(rdram, ctx);
        goto after_5;
    // 0x801875A4: nop

    after_5:
    // 0x801875A8: b           L_801875CC
    // 0x801875AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801875CC;
    // 0x801875AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801875B0:
    // 0x801875B0: jal         0x8019E85C
    // 0x801875B4: nop

    Map_GameOver(rdram, ctx);
        goto after_6;
    // 0x801875B4: nop

    after_6:
    // 0x801875B8: b           L_801875CC
    // 0x801875BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801875CC;
    // 0x801875BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801875C0:
    // 0x801875C0: jal         0x8019E8C8
    // 0x801875C4: nop

    Map_8019E8C8(rdram, ctx);
        goto after_7;
    // 0x801875C4: nop

    after_7:
L_801875C8:
    // 0x801875C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801875CC:
    // 0x801875CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801875D0: jr          $ra
    // 0x801875D4: nop

    return;
    // 0x801875D4: nop

;}
RECOMP_FUNC void Title_Copyright_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018FC14: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8018FC18: sw          $s2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r18;
    // 0x8018FC1C: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x8018FC20: addiu       $s2, $s2, 0x7E64
    ctx->r18 = ADD32(ctx->r18, 0X7E64);
    // 0x8018FC24: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8018FC28: sw          $s3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r19;
    // 0x8018FC2C: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x8018FC30: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x8018FC34: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x8018FC38: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x8018FC3C: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x8018FC40: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8018FC44: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8018FC48: jal         0x800B8DD0
    // 0x8018FC4C: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x8018FC4C: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    after_0:
    // 0x8018FC50: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x8018FC54: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x8018FC58: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8018FC5C: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8018FC60: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
    // 0x8018FC64: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8018FC68: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8018FC6C: lui         $at, 0x4351
    ctx->r1 = S32(0X4351 << 16);
    // 0x8018FC70: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x8018FC74: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x8018FC78: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x8018FC7C: lui         $at, 0x42CC
    ctx->r1 = S32(0X42CC << 16);
    // 0x8018FC80: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8018FC84: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8018FC88: lui         $s1, 0x601
    ctx->r17 = S32(0X601 << 16);
    // 0x8018FC8C: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8018FC90: addiu       $s1, $s1, -0x2240
    ctx->r17 = ADD32(ctx->r17, -0X2240);
    // 0x8018FC94: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8018FC98: addiu       $s3, $zero, 0x2
    ctx->r19 = ADD32(0, 0X2);
L_8018FC9C:
    // 0x8018FC9C: mtc1        $s0, $f4
    ctx->f4.u32l = ctx->r16;
    // 0x8018FCA0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8018FCA4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8018FCA8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8018FCAC: addiu       $a2, $zero, 0x78
    ctx->r6 = ADD32(0, 0X78);
    // 0x8018FCB0: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    // 0x8018FCB4: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    // 0x8018FCB8: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x8018FCBC: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8018FCC0: mul.s       $f8, $f6, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f24.fl);
    // 0x8018FCC4: add.s       $f10, $f8, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f26.fl;
    // 0x8018FCC8: jal         0x8009D994
    // 0x8018FCCC: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_1;
    // 0x8018FCCC: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x8018FCD0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8018FCD4: bne         $s0, $s3, L_8018FC9C
    if (ctx->r16 != ctx->r19) {
        // 0x8018FCD8: addiu       $s1, $s1, 0x2D0
        ctx->r17 = ADD32(ctx->r17, 0X2D0);
            goto L_8018FC9C;
    }
    // 0x8018FCD8: addiu       $s1, $s1, 0x2D0
    ctx->r17 = ADD32(ctx->r17, 0X2D0);
    // 0x8018FCDC: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x8018FCE0: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8018FCE4: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x8018FCE8: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x8018FCEC: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x8018FCF0: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x8018FCF4: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x8018FCF8: lw          $s2, 0x4C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X4C);
    // 0x8018FCFC: lw          $s3, 0x50($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X50);
    // 0x8018FD00: jr          $ra
    // 0x8018FD04: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8018FD04: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void Option_80197914(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80197914: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80197918: sw          $s4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r20;
    // 0x8019791C: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x80197920: addiu       $s4, $s4, 0x7E64
    ctx->r20 = ADD32(ctx->r20, 0X7E64);
    // 0x80197924: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80197928: sw          $s7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r23;
    // 0x8019792C: sw          $s6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r22;
    // 0x80197930: sw          $s5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r21;
    // 0x80197934: sw          $s3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r19;
    // 0x80197938: sw          $s2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r18;
    // 0x8019793C: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x80197940: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x80197944: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80197948: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8019794C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80197950: jal         0x800B8DD0
    // 0x80197954: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x80197954: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80197958: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8019795C: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80197960: lui         $at, 0xC3FA
    ctx->r1 = S32(0XC3FA << 16);
    // 0x80197964: lui         $s0, 0x801B
    ctx->r16 = S32(0X801B << 16);
    // 0x80197968: lui         $s1, 0x801B
    ctx->r17 = S32(0X801B << 16);
    // 0x8019796C: lui         $s5, 0x801B
    ctx->r21 = S32(0X801B << 16);
    // 0x80197970: lui         $s2, 0x8014
    ctx->r18 = S32(0X8014 << 16);
    // 0x80197974: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80197978: addiu       $s2, $s2, -0x4C40
    ctx->r18 = ADD32(ctx->r18, -0X4C40);
    // 0x8019797C: addiu       $s5, $s5, -0x10D0
    ctx->r21 = ADD32(ctx->r21, -0X10D0);
    // 0x80197980: addiu       $s1, $s1, -0xEE8
    ctx->r17 = ADD32(ctx->r17, -0XEE8);
    // 0x80197984: addiu       $s0, $s0, -0xF00
    ctx->r16 = ADD32(ctx->r16, -0XF00);
    // 0x80197988: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8019798C: addiu       $s7, $zero, 0x2
    ctx->r23 = ADD32(0, 0X2);
    // 0x80197990: lui         $s6, 0x600
    ctx->r22 = S32(0X600 << 16);
L_80197994:
    // 0x80197994: jal         0x80005708
    // 0x80197998: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Push(rdram, ctx);
        goto after_1;
    // 0x80197998: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_1:
    // 0x8019799C: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x801979A0: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    // 0x801979A4: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x801979A8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801979AC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801979B0: jal         0x80005B00
    // 0x801979B4: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_2;
    // 0x801979B4: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_2:
    // 0x801979B8: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x801979BC: lw          $a2, 0x4($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X4);
    // 0x801979C0: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x801979C4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801979C8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801979CC: jal         0x80005C34
    // 0x801979D0: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_3;
    // 0x801979D0: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_3:
    // 0x801979D4: jal         0x80006EB8
    // 0x801979D8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_4;
    // 0x801979D8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_4:
    // 0x801979DC: lw          $v1, 0x0($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X0);
    // 0x801979E0: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x801979E4: sw          $t8, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r24;
    // 0x801979E8: sw          $s5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r21;
    // 0x801979EC: sw          $s6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r22;
    // 0x801979F0: jal         0x80005740
    // 0x801979F4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_5;
    // 0x801979F4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_5:
    // 0x801979F8: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x801979FC: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x80197A00: bne         $s3, $s7, L_80197994
    if (ctx->r19 != ctx->r23) {
        // 0x80197A04: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_80197994;
    }
    // 0x80197A04: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    // 0x80197A08: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80197A0C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80197A10: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80197A14: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x80197A18: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x80197A1C: lw          $s2, 0x34($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X34);
    // 0x80197A20: lw          $s3, 0x38($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X38);
    // 0x80197A24: lw          $s4, 0x3C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X3C);
    // 0x80197A28: lw          $s5, 0x40($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X40);
    // 0x80197A2C: lw          $s6, 0x44($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X44);
    // 0x80197A30: lw          $s7, 0x48($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X48);
    // 0x80197A34: jr          $ra
    // 0x80197A38: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80197A38: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void Title_CorneriaExplosions_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018E200: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8018E204: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x8018E208: sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // 0x8018E20C: sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // 0x8018E210: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x8018E214: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x8018E218: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x8018E21C: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x8018E220: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x8018E224: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x8018E228: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x8018E22C: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x8018E230: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x8018E234: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8018E238: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8018E23C: lw          $a0, 0x7C98($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7C98);
    // 0x8018E240: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x8018E244: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x8018E248: blez        $a0, L_8018E4A8
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8018E24C: lui         $at, 0x40A0
        ctx->r1 = S32(0X40A0 << 16);
            goto L_8018E4A8;
    }
    // 0x8018E24C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8018E250: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x8018E254: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8018E258: lui         $s7, 0x801B
    ctx->r23 = S32(0X801B << 16);
    // 0x8018E25C: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8018E260: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x8018E264: addiu       $s7, $s7, 0x7CA0
    ctx->r23 = ADD32(ctx->r23, 0X7CA0);
    // 0x8018E268: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x8018E26C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_8018E270:
    // 0x8018E270: lw          $v0, 0x0($s7)
    ctx->r2 = MEM_W(ctx->r23, 0X0);
    // 0x8018E274: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x8018E278: addiu       $t8, $t8, 0x7C48
    ctx->r24 = ADD32(ctx->r24, 0X7C48);
    // 0x8018E27C: beq         $v0, $zero, L_8018E2B4
    if (ctx->r2 == 0) {
        // 0x8018E280: addu        $s1, $s4, $t8
        ctx->r17 = ADD32(ctx->r20, ctx->r24);
            goto L_8018E2B4;
    }
    // 0x8018E280: addu        $s1, $s4, $t8
    ctx->r17 = ADD32(ctx->r20, ctx->r24);
    // 0x8018E284: beq         $v0, $a1, L_8018E334
    if (ctx->r2 == ctx->r5) {
        // 0x8018E288: lui         $t7, 0x801B
        ctx->r15 = S32(0X801B << 16);
            goto L_8018E334;
    }
    // 0x8018E288: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x8018E28C: beq         $v0, $a2, L_8018E304
    if (ctx->r2 == ctx->r6) {
        // 0x8018E290: lui         $t1, 0x801B
        ctx->r9 = S32(0X801B << 16);
            goto L_8018E304;
    }
    // 0x8018E290: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x8018E294: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8018E298: beq         $v0, $at, L_8018E3A4
    if (ctx->r2 == ctx->r1) {
        // 0x8018E29C: lui         $t8, 0x801B
        ctx->r24 = S32(0X801B << 16);
            goto L_8018E3A4;
    }
    // 0x8018E29C: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x8018E2A0: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x8018E2A4: addiu       $t7, $t7, 0x7CA0
    ctx->r15 = ADD32(ctx->r15, 0X7CA0);
    // 0x8018E2A8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8018E2AC: b           L_8018E494
    // 0x8018E2B0: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
        goto L_8018E494;
    // 0x8018E2B0: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
L_8018E2B4:
    // 0x8018E2B4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018E2B8: lwc1        $f6, 0x706C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X706C);
    // 0x8018E2BC: lwc1        $f4, 0x0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8018E2C0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018E2C4: addu        $at, $at, $s4
    ctx->r1 = ADD32(ctx->r1, ctx->r20);
    // 0x8018E2C8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8018E2CC: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x8018E2D0: addiu       $t0, $t0, 0x7CA0
    ctx->r8 = ADD32(ctx->r8, 0X7CA0);
    // 0x8018E2D4: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x8018E2D8: swc1        $f8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f8.u32l;
    // 0x8018E2DC: lwc1        $f10, 0x0($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8018E2E0: lwc1        $f0, 0x7C70($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X7C70);
    // 0x8018E2E4: addu        $v1, $t9, $t0
    ctx->r3 = ADD32(ctx->r25, ctx->r8);
    // 0x8018E2E8: c.le.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl <= ctx->f10.fl;
    // 0x8018E2EC: nop

    // 0x8018E2F0: bc1fl       L_8018E498
    if (!c1cs) {
        // 0x8018E2F4: addiu       $s7, $s7, 0x4
        ctx->r23 = ADD32(ctx->r23, 0X4);
            goto L_8018E498;
    }
    goto skip_0;
    // 0x8018E2F4: addiu       $s7, $s7, 0x4
    ctx->r23 = ADD32(ctx->r23, 0X4);
    skip_0:
    // 0x8018E2F8: swc1        $f0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f0.u32l;
    // 0x8018E2FC: b           L_8018E494
    // 0x8018E300: sw          $a2, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r6;
        goto L_8018E494;
    // 0x8018E300: sw          $a2, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r6;
L_8018E304:
    // 0x8018E304: addiu       $t1, $t1, 0x7D18
    ctx->r9 = ADD32(ctx->r9, 0X7D18);
    // 0x8018E308: addu        $s2, $s4, $t1
    ctx->r18 = ADD32(ctx->r20, ctx->r9);
    // 0x8018E30C: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x8018E310: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x8018E314: addiu       $t5, $t5, 0x7CA0
    ctx->r13 = ADD32(ctx->r13, 0X7CA0);
    // 0x8018E318: sll         $t4, $a0, 2
    ctx->r12 = S32(ctx->r4 << 2);
    // 0x8018E31C: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x8018E320: sw          $t3, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r11;
    // 0x8018E324: bgtz        $t3, L_8018E494
    if (SIGNED(ctx->r11) > 0) {
        // 0x8018E328: addu        $v1, $t4, $t5
        ctx->r3 = ADD32(ctx->r12, ctx->r13);
            goto L_8018E494;
    }
    // 0x8018E328: addu        $v1, $t4, $t5
    ctx->r3 = ADD32(ctx->r12, ctx->r13);
    // 0x8018E32C: b           L_8018E494
    // 0x8018E330: sw          $a1, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r5;
        goto L_8018E494;
    // 0x8018E330: sw          $a1, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r5;
L_8018E334:
    // 0x8018E334: addiu       $t7, $t7, 0x7CC8
    ctx->r15 = ADD32(ctx->r15, 0X7CC8);
    // 0x8018E338: addu        $s0, $s4, $t7
    ctx->r16 = ADD32(ctx->r20, ctx->r15);
    // 0x8018E33C: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x8018E340: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x8018E344: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x8018E348: addiu       $t2, $t2, 0x7CA0
    ctx->r10 = ADD32(ctx->r10, 0X7CA0);
    // 0x8018E34C: addiu       $t0, $t0, 0x7CF0
    ctx->r8 = ADD32(ctx->r8, 0X7CF0);
    // 0x8018E350: sll         $t1, $a0, 2
    ctx->r9 = S32(ctx->r4 << 2);
    // 0x8018E354: addiu       $v0, $t8, -0x10
    ctx->r2 = ADD32(ctx->r24, -0X10);
    // 0x8018E358: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8018E35C: addu        $v1, $t1, $t2
    ctx->r3 = ADD32(ctx->r9, ctx->r10);
    // 0x8018E360: bgez        $v0, L_8018E370
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8018E364: addu        $s3, $s4, $t0
        ctx->r19 = ADD32(ctx->r20, ctx->r8);
            goto L_8018E370;
    }
    // 0x8018E364: addu        $s3, $s4, $t0
    ctx->r19 = ADD32(ctx->r20, ctx->r8);
    // 0x8018E368: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x8018E36C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8018E370:
    // 0x8018E370: lw          $t3, 0x0($s3)
    ctx->r11 = MEM_W(ctx->r19, 0X0);
    // 0x8018E374: addiu       $t4, $t3, -0x10
    ctx->r12 = ADD32(ctx->r11, -0X10);
    // 0x8018E378: bgez        $t4, L_8018E384
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8018E37C: sw          $t4, 0x0($s3)
        MEM_W(0X0, ctx->r19) = ctx->r12;
            goto L_8018E384;
    }
    // 0x8018E37C: sw          $t4, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r12;
    // 0x8018E380: sw          $zero, 0x0($s3)
    MEM_W(0X0, ctx->r19) = 0;
L_8018E384:
    // 0x8018E384: bnel        $v0, $zero, L_8018E498
    if (ctx->r2 != 0) {
        // 0x8018E388: addiu       $s7, $s7, 0x4
        ctx->r23 = ADD32(ctx->r23, 0X4);
            goto L_8018E498;
    }
    goto skip_1;
    // 0x8018E388: addiu       $s7, $s7, 0x4
    ctx->r23 = ADD32(ctx->r23, 0X4);
    skip_1:
    // 0x8018E38C: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x8018E390: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8018E394: bnel        $t6, $zero, L_8018E498
    if (ctx->r14 != 0) {
        // 0x8018E398: addiu       $s7, $s7, 0x4
        ctx->r23 = ADD32(ctx->r23, 0X4);
            goto L_8018E498;
    }
    goto skip_2;
    // 0x8018E398: addiu       $s7, $s7, 0x4
    ctx->r23 = ADD32(ctx->r23, 0X4);
    skip_2:
    // 0x8018E39C: b           L_8018E494
    // 0x8018E3A0: sw          $t7, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r15;
        goto L_8018E494;
    // 0x8018E3A0: sw          $t7, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r15;
L_8018E3A4:
    // 0x8018E3A4: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x8018E3A8: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x8018E3AC: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x8018E3B0: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x8018E3B4: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x8018E3B8: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x8018E3BC: addiu       $t4, $t4, 0x7C20
    ctx->r12 = ADD32(ctx->r12, 0X7C20);
    // 0x8018E3C0: addiu       $t3, $t3, 0x7BF8
    ctx->r11 = ADD32(ctx->r11, 0X7BF8);
    // 0x8018E3C4: addiu       $t2, $t2, 0x7CF0
    ctx->r10 = ADD32(ctx->r10, 0X7CF0);
    // 0x8018E3C8: addiu       $t1, $t1, 0x7CC8
    ctx->r9 = ADD32(ctx->r9, 0X7CC8);
    // 0x8018E3CC: addiu       $t0, $t0, 0x7D18
    ctx->r8 = ADD32(ctx->r8, 0X7D18);
    // 0x8018E3D0: addiu       $t9, $t9, 0x7C70
    ctx->r25 = ADD32(ctx->r25, 0X7C70);
    // 0x8018E3D4: addiu       $t8, $t8, 0x7C48
    ctx->r24 = ADD32(ctx->r24, 0X7C48);
    // 0x8018E3D8: addu        $s1, $s4, $t8
    ctx->r17 = ADD32(ctx->r20, ctx->r24);
    // 0x8018E3DC: addu        $fp, $s4, $t9
    ctx->r30 = ADD32(ctx->r20, ctx->r25);
    // 0x8018E3E0: addu        $s2, $s4, $t0
    ctx->r18 = ADD32(ctx->r20, ctx->r8);
    // 0x8018E3E4: addu        $s0, $s4, $t1
    ctx->r16 = ADD32(ctx->r20, ctx->r9);
    // 0x8018E3E8: addu        $s3, $s4, $t2
    ctx->r19 = ADD32(ctx->r20, ctx->r10);
    // 0x8018E3EC: addu        $s5, $s4, $t3
    ctx->r21 = ADD32(ctx->r20, ctx->r11);
    // 0x8018E3F0: jal         0x80004EB0
    // 0x8018E3F4: addu        $s6, $s4, $t4
    ctx->r22 = ADD32(ctx->r20, ctx->r12);
    Rand_ZeroOne(rdram, ctx);
        goto after_0;
    // 0x8018E3F4: addu        $s6, $s4, $t4
    ctx->r22 = ADD32(ctx->r20, ctx->r12);
    after_0:
    // 0x8018E3F8: mul.s       $f16, $f0, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8018E3FC: add.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f20.fl;
    // 0x8018E400: jal         0x80004EB0
    // 0x8018E404: swc1        $f18, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->f18.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x8018E404: swc1        $f18, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->f18.u32l;
    after_1:
    // 0x8018E408: lui         $at, 0xC270
    ctx->r1 = S32(0XC270 << 16);
    // 0x8018E40C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018E410: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x8018E414: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018E418: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8018E41C: swc1        $f22, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f22.u32l;
    // 0x8018E420: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8018E424: jal         0x80004EB0
    // 0x8018E428: swc1        $f10, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->f10.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_2;
    // 0x8018E428: swc1        $f10, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->f10.u32l;
    after_2:
    // 0x8018E42C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018E430: lwc1        $f16, 0x7070($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7070);
    // 0x8018E434: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018E438: lwc1        $f4, 0x7074($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7074);
    // 0x8018E43C: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x8018E440: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8018E444: jal         0x80004EB0
    // 0x8018E448: swc1        $f6, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->f6.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_3;
    // 0x8018E448: swc1        $f6, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->f6.u32l;
    after_3:
    // 0x8018E44C: mul.s       $f8, $f0, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x8018E450: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8018E454: addiu       $t9, $zero, 0x80
    ctx->r25 = ADD32(0, 0X80);
    // 0x8018E458: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8018E45C: sw          $t9, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r25;
    // 0x8018E460: sw          $zero, 0x0($s7)
    MEM_W(0X0, ctx->r23) = 0;
    // 0x8018E464: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8018E468: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8018E46C: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x8018E470: addiu       $t1, $t1, 0x7CA0
    ctx->r9 = ADD32(ctx->r9, 0X7CA0);
    // 0x8018E474: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x8018E478: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x8018E47C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8018E480: addiu       $t7, $t6, 0x5
    ctx->r15 = ADD32(ctx->r14, 0X5);
    // 0x8018E484: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    // 0x8018E488: lw          $a0, 0x7C98($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7C98);
    // 0x8018E48C: sll         $t0, $a0, 2
    ctx->r8 = S32(ctx->r4 << 2);
    // 0x8018E490: addu        $v1, $t0, $t1
    ctx->r3 = ADD32(ctx->r8, ctx->r9);
L_8018E494:
    // 0x8018E494: addiu       $s7, $s7, 0x4
    ctx->r23 = ADD32(ctx->r23, 0X4);
L_8018E498:
    // 0x8018E498: sltu        $at, $s7, $v1
    ctx->r1 = ctx->r23 < ctx->r3 ? 1 : 0;
    // 0x8018E49C: bne         $at, $zero, L_8018E270
    if (ctx->r1 != 0) {
        // 0x8018E4A0: addiu       $s4, $s4, 0x4
        ctx->r20 = ADD32(ctx->r20, 0X4);
            goto L_8018E270;
    }
    // 0x8018E4A0: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x8018E4A4: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
L_8018E4A8:
    // 0x8018E4A8: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x8018E4AC: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8018E4B0: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x8018E4B4: addiu       $s4, $s4, 0x7E64
    ctx->r20 = ADD32(ctx->r20, 0X7E64);
    // 0x8018E4B8: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x8018E4BC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8018E4C0: jal         0x800B8DD0
    // 0x8018E4C4: addiu       $a1, $zero, 0x31
    ctx->r5 = ADD32(0, 0X31);
    RCP_SetupDL(rdram, ctx);
        goto after_4;
    // 0x8018E4C4: addiu       $a1, $zero, 0x31
    ctx->r5 = ADD32(0, 0X31);
    after_4:
    // 0x8018E4C8: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x8018E4CC: lw          $t2, 0x7C98($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7C98);
    // 0x8018E4D0: lui         $s1, 0x801B
    ctx->r17 = S32(0X801B << 16);
    // 0x8018E4D4: addiu       $s1, $s1, 0x7C48
    ctx->r17 = ADD32(ctx->r17, 0X7C48);
    // 0x8018E4D8: blez        $t2, L_8018E640
    if (SIGNED(ctx->r10) <= 0) {
        // 0x8018E4DC: lui         $s0, 0x801B
        ctx->r16 = S32(0X801B << 16);
            goto L_8018E640;
    }
    // 0x8018E4DC: lui         $s0, 0x801B
    ctx->r16 = S32(0X801B << 16);
    // 0x8018E4E0: lui         $s3, 0x801B
    ctx->r19 = S32(0X801B << 16);
    // 0x8018E4E4: lui         $s5, 0x801B
    ctx->r21 = S32(0X801B << 16);
    // 0x8018E4E8: lui         $s6, 0x801B
    ctx->r22 = S32(0X801B << 16);
    // 0x8018E4EC: lui         $fp, 0x603
    ctx->r30 = S32(0X603 << 16);
    // 0x8018E4F0: lui         $s2, 0x8014
    ctx->r18 = S32(0X8014 << 16);
    // 0x8018E4F4: addiu       $s2, $s2, -0x4C40
    ctx->r18 = ADD32(ctx->r18, -0X4C40);
    // 0x8018E4F8: addiu       $fp, $fp, 0x20E0
    ctx->r30 = ADD32(ctx->r30, 0X20E0);
    // 0x8018E4FC: addiu       $s6, $s6, 0x7C20
    ctx->r22 = ADD32(ctx->r22, 0X7C20);
    // 0x8018E500: addiu       $s5, $s5, 0x7BF8
    ctx->r21 = ADD32(ctx->r21, 0X7BF8);
    // 0x8018E504: addiu       $s3, $s3, 0x7CF0
    ctx->r19 = ADD32(ctx->r19, 0X7CF0);
    // 0x8018E508: addiu       $s0, $s0, 0x7CC8
    ctx->r16 = ADD32(ctx->r16, 0X7CC8);
L_8018E50C:
    // 0x8018E50C: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x8018E510: lui         $t4, 0xFA00
    ctx->r12 = S32(0XFA00 << 16);
    // 0x8018E514: lui         $at, 0xFFC8
    ctx->r1 = S32(0XFFC8 << 16);
    // 0x8018E518: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x8018E51C: sw          $t3, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r11;
    // 0x8018E520: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8018E524: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x8018E528: ori         $at, $at, 0xC800
    ctx->r1 = ctx->r1 | 0XC800;
    // 0x8018E52C: andi        $t6, $t5, 0xFF
    ctx->r14 = ctx->r13 & 0XFF;
    // 0x8018E530: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x8018E534: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8018E538: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x8018E53C: lui         $t9, 0xFB00
    ctx->r25 = S32(0XFB00 << 16);
    // 0x8018E540: lui         $at, 0xFF00
    ctx->r1 = S32(0XFF00 << 16);
    // 0x8018E544: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8018E548: sw          $t8, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r24;
    // 0x8018E54C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8018E550: lw          $t0, 0x0($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X0);
    // 0x8018E554: andi        $t1, $t0, 0xFF
    ctx->r9 = ctx->r8 & 0XFF;
    // 0x8018E558: or          $t2, $t1, $at
    ctx->r10 = ctx->r9 | ctx->r1;
    // 0x8018E55C: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x8018E560: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018E564: lwc1        $f18, -0x7968($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X7968);
    // 0x8018E568: lwc1        $f16, 0x0($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8018E56C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8018E570: jal         0x80005708
    // 0x8018E574: div.s       $f20, $f16, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f20.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    Matrix_Push(rdram, ctx);
        goto after_5;
    // 0x8018E574: div.s       $f20, $f16, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f20.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    after_5:
    // 0x8018E578: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    // 0x8018E57C: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x8018E580: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x8018E584: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8018E588: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8018E58C: jal         0x80005B00
    // 0x8018E590: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_6;
    // 0x8018E590: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_6:
    // 0x8018E594: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018E598: lwc1        $f6, 0x7078($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7078);
    // 0x8018E59C: lwc1        $f4, 0x0($s6)
    ctx->f4.u32l = MEM_W(ctx->r22, 0X0);
    // 0x8018E5A0: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8018E5A4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018E5A8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8018E5AC: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8018E5B0: jal         0x80005FE0
    // 0x8018E5B4: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_7;
    // 0x8018E5B4: nop

    after_7:
    // 0x8018E5B8: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    // 0x8018E5BC: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x8018E5C0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8018E5C4: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8018E5C8: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8018E5CC: jal         0x80005B00
    // 0x8018E5D0: lw          $a2, 0x0($s5)
    ctx->r6 = MEM_W(ctx->r21, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_8;
    // 0x8018E5D0: lw          $a2, 0x0($s5)
    ctx->r6 = MEM_W(ctx->r21, 0X0);
    after_8:
    // 0x8018E5D4: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8018E5D8: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8018E5DC: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x8018E5E0: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8018E5E4: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8018E5E8: jal         0x80005C34
    // 0x8018E5EC: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_9;
    // 0x8018E5EC: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_9:
    // 0x8018E5F0: jal         0x80006EB8
    // 0x8018E5F4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_10;
    // 0x8018E5F4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_10:
    // 0x8018E5F8: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x8018E5FC: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x8018E600: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8018E604: sw          $t6, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r14;
    // 0x8018E608: sw          $fp, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r30;
    // 0x8018E60C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8018E610: jal         0x80005740
    // 0x8018E614: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_11;
    // 0x8018E614: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_11:
    // 0x8018E618: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x8018E61C: lw          $t8, 0x7C98($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7C98);
    // 0x8018E620: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x8018E624: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8018E628: slt         $at, $s7, $t8
    ctx->r1 = SIGNED(ctx->r23) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8018E62C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8018E630: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x8018E634: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
    // 0x8018E638: bne         $at, $zero, L_8018E50C
    if (ctx->r1 != 0) {
        // 0x8018E63C: addiu       $s6, $s6, 0x4
        ctx->r22 = ADD32(ctx->r22, 0X4);
            goto L_8018E50C;
    }
    // 0x8018E63C: addiu       $s6, $s6, 0x4
    ctx->r22 = ADD32(ctx->r22, 0X4);
L_8018E640:
    // 0x8018E640: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x8018E644: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8018E648: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x8018E64C: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x8018E650: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x8018E654: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x8018E658: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x8018E65C: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x8018E660: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x8018E664: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x8018E668: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x8018E66C: lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X54);
    // 0x8018E670: lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X58);
    // 0x8018E674: jr          $ra
    // 0x8018E678: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8018E678: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void Map_PlanetExplosions_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A89BC: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x801A89C0: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x801A89C4: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x801A89C8: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x801A89CC: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x801A89D0: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x801A89D4: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x801A89D8: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x801A89DC: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x801A89E0: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x801A89E4: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x801A89E8: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x801A89EC: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x801A89F0: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x801A89F4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x801A89F8: sll         $t6, $a2, 3
    ctx->r14 = S32(ctx->r6 << 3);
    // 0x801A89FC: subu        $t6, $t6, $a2
    ctx->r14 = SUB32(ctx->r14, ctx->r6);
    // 0x801A8A00: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x801A8A04: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x801A8A08: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x801A8A0C: lw          $t7, -0xB3C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0XB3C);
    // 0x801A8A10: sll         $t8, $s4, 2
    ctx->r24 = S32(ctx->r20 << 2);
    // 0x801A8A14: lui         $t9, 0x801D
    ctx->r25 = S32(0X801D << 16);
    // 0x801A8A18: beq         $t7, $zero, L_801A8F08
    if (ctx->r15 == 0) {
        // 0x801A8A1C: addu        $t9, $t9, $t8
        ctx->r25 = ADD32(ctx->r25, ctx->r24);
            goto L_801A8F08;
    }
    // 0x801A8A1C: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x801A8A20: lw          $t9, -0x14B8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X14B8);
    // 0x801A8A24: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801A8A28: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x801A8A2C: beq         $t9, $zero, L_801A8F08
    if (ctx->r25 == 0) {
        // 0x801A8A30: addiu       $a0, $a0, 0x7E64
        ctx->r4 = ADD32(ctx->r4, 0X7E64);
            goto L_801A8F08;
    }
    // 0x801A8A30: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x801A8A34: beq         $a2, $at, L_801A8A40
    if (ctx->r6 == ctx->r1) {
        // 0x801A8A38: addiu       $v0, $zero, 0xA
        ctx->r2 = ADD32(0, 0XA);
            goto L_801A8A40;
    }
    // 0x801A8A38: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x801A8A3C: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_801A8A40:
    // 0x801A8A40: addiu       $a1, $zero, 0x43
    ctx->r5 = ADD32(0, 0X43);
    // 0x801A8A44: sw          $v0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r2;
    // 0x801A8A48: jal         0x800B8DD0
    // 0x801A8A4C: sw          $a2, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r6;
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x801A8A4C: sw          $a2, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r6;
    after_0:
    // 0x801A8A50: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x801A8A54: lw          $v0, 0x7E64($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7E64);
    // 0x801A8A58: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801A8A5C: lui         $t1, 0xFB00
    ctx->r9 = S32(0XFB00 << 16);
    // 0x801A8A60: addiu       $t0, $v0, 0x8
    ctx->r8 = ADD32(ctx->r2, 0X8);
    // 0x801A8A64: sw          $t0, 0x7E64($at)
    MEM_W(0X7E64, ctx->r1) = ctx->r8;
    // 0x801A8A68: lui         $t2, 0xFF00
    ctx->r10 = S32(0XFF00 << 16);
    // 0x801A8A6C: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x801A8A70: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x801A8A74: lw          $t3, 0x90($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X90);
    // 0x801A8A78: sw          $zero, 0x94($sp)
    MEM_W(0X94, ctx->r29) = 0;
    // 0x801A8A7C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x801A8A80: blez        $t3, L_801A8F08
    if (SIGNED(ctx->r11) <= 0) {
        // 0x801A8A84: sll         $t4, $s4, 2
        ctx->r12 = S32(ctx->r20 << 2);
            goto L_801A8F08;
    }
    // 0x801A8A84: sll         $t4, $s4, 2
    ctx->r12 = S32(ctx->r20 << 2);
    // 0x801A8A88: sll         $t6, $s4, 2
    ctx->r14 = S32(ctx->r20 << 2);
    // 0x801A8A8C: addu        $t6, $t6, $s4
    ctx->r14 = ADD32(ctx->r14, ctx->r20);
    // 0x801A8A90: addu        $t4, $t4, $s4
    ctx->r12 = ADD32(ctx->r12, ctx->r20);
    // 0x801A8A94: lui         $t5, 0x801D
    ctx->r13 = S32(0X801D << 16);
    // 0x801A8A98: lui         $t7, 0x801D
    ctx->r15 = S32(0X801D << 16);
    // 0x801A8A9C: addiu       $t7, $t7, -0x1340
    ctx->r15 = ADD32(ctx->r15, -0X1340);
    // 0x801A8AA0: addiu       $t5, $t5, -0x14A8
    ctx->r13 = ADD32(ctx->r13, -0X14A8);
    // 0x801A8AA4: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x801A8AA8: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x801A8AAC: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x801A8AB0: addu        $s7, $t6, $t7
    ctx->r23 = ADD32(ctx->r14, ctx->r15);
    // 0x801A8AB4: addu        $fp, $t4, $t5
    ctx->r30 = ADD32(ctx->r12, ctx->r13);
L_801A8AB8:
    // 0x801A8AB8: lw          $v0, 0x0($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X0);
    // 0x801A8ABC: sll         $t8, $s4, 2
    ctx->r24 = S32(ctx->r20 << 2);
    // 0x801A8AC0: addu        $t8, $t8, $s4
    ctx->r24 = ADD32(ctx->r24, ctx->r20);
    // 0x801A8AC4: beq         $v0, $zero, L_801A8AF8
    if (ctx->r2 == 0) {
        // 0x801A8AC8: sll         $t8, $t8, 3
        ctx->r24 = S32(ctx->r24 << 3);
            goto L_801A8AF8;
    }
    // 0x801A8AC8: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x801A8ACC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801A8AD0: beq         $v0, $at, L_801A8B44
    if (ctx->r2 == ctx->r1) {
        // 0x801A8AD4: sll         $t2, $s4, 2
        ctx->r10 = S32(ctx->r20 << 2);
            goto L_801A8B44;
    }
    // 0x801A8AD4: sll         $t2, $s4, 2
    ctx->r10 = S32(ctx->r20 << 2);
    // 0x801A8AD8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801A8ADC: beq         $v0, $at, L_801A8B98
    if (ctx->r2 == ctx->r1) {
        // 0x801A8AE0: sll         $t6, $s4, 2
        ctx->r14 = S32(ctx->r20 << 2);
            goto L_801A8B98;
    }
    // 0x801A8AE0: sll         $t6, $s4, 2
    ctx->r14 = S32(ctx->r20 << 2);
    // 0x801A8AE4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801A8AE8: beq         $v0, $at, L_801A8BD4
    if (ctx->r2 == ctx->r1) {
        // 0x801A8AEC: sll         $t3, $s4, 2
        ctx->r11 = S32(ctx->r20 << 2);
            goto L_801A8BD4;
    }
    // 0x801A8AEC: sll         $t3, $s4, 2
    ctx->r11 = S32(ctx->r20 << 2);
    // 0x801A8AF0: b           L_801A8D4C
    // 0x801A8AF4: lwc1        $f2, 0x0($s7)
    ctx->f2.u32l = MEM_W(ctx->r23, 0X0);
        goto L_801A8D4C;
    // 0x801A8AF4: lwc1        $f2, 0x0($s7)
    ctx->f2.u32l = MEM_W(ctx->r23, 0X0);
L_801A8AF8:
    // 0x801A8AF8: lui         $t0, 0x801D
    ctx->r8 = S32(0X801D << 16);
    // 0x801A8AFC: addiu       $t0, $t0, -0x13B8
    ctx->r8 = ADD32(ctx->r8, -0X13B8);
    // 0x801A8B00: addu        $t9, $t8, $s3
    ctx->r25 = ADD32(ctx->r24, ctx->r19);
    // 0x801A8B04: addu        $s1, $t9, $t0
    ctx->r17 = ADD32(ctx->r25, ctx->r8);
    // 0x801A8B08: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A8B0C: lwc1        $f6, 0x79C4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X79C4);
    // 0x801A8B10: lwc1        $f4, 0x0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X0);
    // 0x801A8B14: lwc1        $f2, 0x0($s7)
    ctx->f2.u32l = MEM_W(ctx->r23, 0X0);
    // 0x801A8B18: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801A8B1C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801A8B20: swc1        $f8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f8.u32l;
    // 0x801A8B24: lwc1        $f10, 0x0($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X0);
    // 0x801A8B28: c.le.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl <= ctx->f10.fl;
    // 0x801A8B2C: nop

    // 0x801A8B30: bc1fl       L_801A8D50
    if (!c1cs) {
        // 0x801A8B34: c.eq.s      $f22, $f2
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f22.fl == ctx->f2.fl;
            goto L_801A8D50;
    }
    goto skip_0;
    // 0x801A8B34: c.eq.s      $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f22.fl == ctx->f2.fl;
    skip_0:
    // 0x801A8B38: swc1        $f2, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f2.u32l;
    // 0x801A8B3C: b           L_801A8D4C
    // 0x801A8B40: sw          $t1, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r9;
        goto L_801A8D4C;
    // 0x801A8B40: sw          $t1, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r9;
L_801A8B44:
    // 0x801A8B44: addu        $t2, $t2, $s4
    ctx->r10 = ADD32(ctx->r10, ctx->r20);
    // 0x801A8B48: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x801A8B4C: lui         $t4, 0x801D
    ctx->r12 = S32(0X801D << 16);
    // 0x801A8B50: addiu       $t4, $t4, -0x11D8
    ctx->r12 = ADD32(ctx->r12, -0X11D8);
    // 0x801A8B54: addu        $t3, $t2, $s3
    ctx->r11 = ADD32(ctx->r10, ctx->r19);
    // 0x801A8B58: addu        $s2, $t3, $t4
    ctx->r18 = ADD32(ctx->r11, ctx->r12);
    // 0x801A8B5C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801A8B60: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801A8B64: lwc1        $f16, 0x0($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X0);
    // 0x801A8B68: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801A8B6C: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x801A8B70: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x801A8B74: swc1        $f4, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f4.u32l;
    // 0x801A8B78: lwc1        $f8, 0x0($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X0);
    // 0x801A8B7C: c.le.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl <= ctx->f6.fl;
    // 0x801A8B80: nop

    // 0x801A8B84: bc1f        L_801A8B90
    if (!c1cs) {
        // 0x801A8B88: nop
    
            goto L_801A8B90;
    }
    // 0x801A8B88: nop

    // 0x801A8B8C: sw          $t5, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r13;
L_801A8B90:
    // 0x801A8B90: b           L_801A8D4C
    // 0x801A8B94: lwc1        $f2, 0x0($s7)
    ctx->f2.u32l = MEM_W(ctx->r23, 0X0);
        goto L_801A8D4C;
    // 0x801A8B94: lwc1        $f2, 0x0($s7)
    ctx->f2.u32l = MEM_W(ctx->r23, 0X0);
L_801A8B98:
    // 0x801A8B98: addu        $t6, $t6, $s4
    ctx->r14 = ADD32(ctx->r14, ctx->r20);
    // 0x801A8B9C: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x801A8BA0: lui         $t8, 0x801D
    ctx->r24 = S32(0X801D << 16);
    // 0x801A8BA4: addiu       $t8, $t8, -0x1430
    ctx->r24 = ADD32(ctx->r24, -0X1430);
    // 0x801A8BA8: addu        $t7, $t6, $s3
    ctx->r15 = ADD32(ctx->r14, ctx->r19);
    // 0x801A8BAC: addu        $s0, $t7, $t8
    ctx->r16 = ADD32(ctx->r15, ctx->r24);
    // 0x801A8BB0: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x801A8BB4: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x801A8BB8: addiu       $t0, $t9, -0x30
    ctx->r8 = ADD32(ctx->r25, -0X30);
    // 0x801A8BBC: bgez        $t0, L_801A8BCC
    if (SIGNED(ctx->r8) >= 0) {
        // 0x801A8BC0: sw          $t0, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r8;
            goto L_801A8BCC;
    }
    // 0x801A8BC0: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x801A8BC4: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x801A8BC8: sw          $t2, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r10;
L_801A8BCC:
    // 0x801A8BCC: b           L_801A8D4C
    // 0x801A8BD0: lwc1        $f2, 0x0($s7)
    ctx->f2.u32l = MEM_W(ctx->r23, 0X0);
        goto L_801A8D4C;
    // 0x801A8BD0: lwc1        $f2, 0x0($s7)
    ctx->f2.u32l = MEM_W(ctx->r23, 0X0);
L_801A8BD4:
    // 0x801A8BD4: addu        $t3, $t3, $s4
    ctx->r11 = ADD32(ctx->r11, ctx->r20);
    // 0x801A8BD8: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x801A8BDC: lui         $t5, 0x801D
    ctx->r13 = S32(0X801D << 16);
    // 0x801A8BE0: sll         $t6, $s4, 2
    ctx->r14 = S32(ctx->r20 << 2);
    // 0x801A8BE4: addu        $t6, $t6, $s4
    ctx->r14 = ADD32(ctx->r14, ctx->r20);
    // 0x801A8BE8: addiu       $t5, $t5, -0x13B8
    ctx->r13 = ADD32(ctx->r13, -0X13B8);
    // 0x801A8BEC: addu        $t4, $t3, $s3
    ctx->r12 = ADD32(ctx->r11, ctx->r19);
    // 0x801A8BF0: addu        $s1, $t4, $t5
    ctx->r17 = ADD32(ctx->r12, ctx->r13);
    // 0x801A8BF4: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x801A8BF8: lui         $t8, 0x801D
    ctx->r24 = S32(0X801D << 16);
    // 0x801A8BFC: addiu       $t8, $t8, -0x11D8
    ctx->r24 = ADD32(ctx->r24, -0X11D8);
    // 0x801A8C00: addu        $t7, $t6, $s3
    ctx->r15 = ADD32(ctx->r14, ctx->r19);
    // 0x801A8C04: sll         $t5, $s4, 2
    ctx->r13 = S32(ctx->r20 << 2);
    // 0x801A8C08: sll         $t9, $s4, 2
    ctx->r25 = S32(ctx->r20 << 2);
    // 0x801A8C0C: sll         $t2, $s4, 2
    ctx->r10 = S32(ctx->r20 << 2);
    // 0x801A8C10: addu        $t2, $t2, $s4
    ctx->r10 = ADD32(ctx->r10, ctx->r20);
    // 0x801A8C14: addu        $t9, $t9, $s4
    ctx->r25 = ADD32(ctx->r25, ctx->r20);
    // 0x801A8C18: addu        $t5, $t5, $s4
    ctx->r13 = ADD32(ctx->r13, ctx->r20);
    // 0x801A8C1C: addu        $s2, $t7, $t8
    ctx->r18 = ADD32(ctx->r15, ctx->r24);
    // 0x801A8C20: lui         $t7, 0x801D
    ctx->r15 = S32(0X801D << 16);
    // 0x801A8C24: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x801A8C28: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x801A8C2C: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x801A8C30: lui         $t4, 0x801D
    ctx->r12 = S32(0X801D << 16);
    // 0x801A8C34: lui         $t1, 0x801D
    ctx->r9 = S32(0X801D << 16);
    // 0x801A8C38: lui         $at, 0x42DC
    ctx->r1 = S32(0X42DC << 16);
    // 0x801A8C3C: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x801A8C40: addiu       $t1, $t1, -0x1430
    ctx->r9 = ADD32(ctx->r9, -0X1430);
    // 0x801A8C44: addiu       $t4, $t4, -0x12C8
    ctx->r12 = ADD32(ctx->r12, -0X12C8);
    // 0x801A8C48: addu        $t3, $t2, $s3
    ctx->r11 = ADD32(ctx->r10, ctx->r19);
    // 0x801A8C4C: addu        $t0, $t9, $s3
    ctx->r8 = ADD32(ctx->r25, ctx->r19);
    // 0x801A8C50: addu        $t6, $t5, $s3
    ctx->r14 = ADD32(ctx->r13, ctx->r19);
    // 0x801A8C54: addiu       $t7, $t7, -0x1250
    ctx->r15 = ADD32(ctx->r15, -0X1250);
    // 0x801A8C58: addu        $s6, $t6, $t7
    ctx->r22 = ADD32(ctx->r14, ctx->r15);
    // 0x801A8C5C: addu        $s0, $t0, $t1
    ctx->r16 = ADD32(ctx->r8, ctx->r9);
    // 0x801A8C60: jal         0x80004EB0
    // 0x801A8C64: addu        $s5, $t3, $t4
    ctx->r21 = ADD32(ctx->r11, ctx->r12);
    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x801A8C64: addu        $s5, $t3, $t4
    ctx->r21 = ADD32(ctx->r11, ctx->r12);
    after_1:
    // 0x801A8C68: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801A8C6C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801A8C70: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x801A8C74: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x801A8C78: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x801A8C7C: swc1        $f22, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f22.u32l;
    // 0x801A8C80: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x801A8C84: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x801A8C88: jal         0x80004EB0
    // 0x801A8C8C: sw          $t9, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r25;
    Rand_ZeroOne(rdram, ctx);
        goto after_2;
    // 0x801A8C8C: sw          $t9, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r25;
    after_2:
    // 0x801A8C90: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A8C94: lwc1        $f4, 0x79C8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X79C8);
    // 0x801A8C98: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801A8C9C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801A8CA0: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x801A8CA4: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801A8CA8: jal         0x80004EB0
    // 0x801A8CAC: swc1        $f10, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->f10.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_3;
    // 0x801A8CAC: swc1        $f10, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->f10.u32l;
    after_3:
    // 0x801A8CB0: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x801A8CB4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801A8CB8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801A8CBC: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x801A8CC0: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x801A8CC4: mfc1        $t2, $f4
    ctx->r10 = (int32_t)ctx->f4.u32l;
    // 0x801A8CC8: nop

    // 0x801A8CCC: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x801A8CD0: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x801A8CD4: nop

    // 0x801A8CD8: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801A8CDC: bne         $s4, $at, L_801A8CF0
    if (ctx->r20 != ctx->r1) {
        // 0x801A8CE0: swc1        $f8, 0x0($s2)
        MEM_W(0X0, ctx->r18) = ctx->f8.u32l;
            goto L_801A8CF0;
    }
    // 0x801A8CE0: swc1        $f8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f8.u32l;
    // 0x801A8CE4: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x801A8CE8: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x801A8CEC: nop

L_801A8CF0:
    // 0x801A8CF0: jal         0x80004EB0
    // 0x801A8CF4: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_4;
    // 0x801A8CF4: nop

    after_4:
    // 0x801A8CF8: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801A8CFC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801A8D00: nop

    // 0x801A8D04: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x801A8D08: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x801A8D0C: mfc1        $t5, $f18
    ctx->r13 = (int32_t)ctx->f18.u32l;
    // 0x801A8D10: nop

    // 0x801A8D14: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x801A8D18: nop

    // 0x801A8D1C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801A8D20: add.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f20.fl;
    // 0x801A8D24: jal         0x80004EB0
    // 0x801A8D28: swc1        $f8, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->f8.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_5;
    // 0x801A8D28: swc1        $f8, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->f8.u32l;
    after_5:
    // 0x801A8D2C: lui         $at, 0xC270
    ctx->r1 = S32(0XC270 << 16);
    // 0x801A8D30: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801A8D34: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x801A8D38: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801A8D3C: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x801A8D40: lwc1        $f2, 0x0($s7)
    ctx->f2.u32l = MEM_W(ctx->r23, 0X0);
    // 0x801A8D44: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x801A8D48: swc1        $f4, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->f4.u32l;
L_801A8D4C:
    // 0x801A8D4C: c.eq.s      $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f22.fl == ctx->f2.fl;
L_801A8D50:
    // 0x801A8D50: sll         $t6, $s4, 2
    ctx->r14 = S32(ctx->r20 << 2);
    // 0x801A8D54: addu        $t6, $t6, $s4
    ctx->r14 = ADD32(ctx->r14, ctx->r20);
    // 0x801A8D58: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x801A8D5C: bc1t        L_801A8EE8
    if (c1cs) {
        // 0x801A8D60: addu        $t7, $t6, $s3
        ctx->r15 = ADD32(ctx->r14, ctx->r19);
            goto L_801A8EE8;
    }
    // 0x801A8D60: addu        $t7, $t6, $s3
    ctx->r15 = ADD32(ctx->r14, ctx->r19);
    // 0x801A8D64: lui         $t8, 0x801D
    ctx->r24 = S32(0X801D << 16);
    // 0x801A8D68: addiu       $t8, $t8, -0x1430
    ctx->r24 = ADD32(ctx->r24, -0X1430);
    // 0x801A8D6C: addu        $s0, $t7, $t8
    ctx->r16 = ADD32(ctx->r15, ctx->r24);
    // 0x801A8D70: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x801A8D74: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801A8D78: addiu       $a1, $a1, 0x7E64
    ctx->r5 = ADD32(ctx->r5, 0X7E64);
    // 0x801A8D7C: beq         $t9, $zero, L_801A8EE8
    if (ctx->r25 == 0) {
        // 0x801A8D80: lui         $a0, 0x8014
        ctx->r4 = S32(0X8014 << 16);
            goto L_801A8EE8;
    }
    // 0x801A8D80: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A8D84: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x801A8D88: lui         $t1, 0xFA00
    ctx->r9 = S32(0XFA00 << 16);
    // 0x801A8D8C: lui         $at, 0xFFC8
    ctx->r1 = S32(0XFFC8 << 16);
    // 0x801A8D90: addiu       $t0, $v0, 0x8
    ctx->r8 = ADD32(ctx->r2, 0X8);
    // 0x801A8D94: sw          $t0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r8;
    // 0x801A8D98: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x801A8D9C: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x801A8DA0: ori         $at, $at, 0xC800
    ctx->r1 = ctx->r1 | 0XC800;
    // 0x801A8DA4: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    // 0x801A8DA8: andi        $t3, $t2, 0xFF
    ctx->r11 = ctx->r10 & 0XFF;
    // 0x801A8DAC: or          $t4, $t3, $at
    ctx->r12 = ctx->r11 | ctx->r1;
    // 0x801A8DB0: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x801A8DB4: sll         $t5, $s4, 2
    ctx->r13 = S32(ctx->r20 << 2);
    // 0x801A8DB8: addu        $t5, $t5, $s4
    ctx->r13 = ADD32(ctx->r13, ctx->r20);
    // 0x801A8DBC: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x801A8DC0: lui         $t7, 0x801D
    ctx->r15 = S32(0X801D << 16);
    // 0x801A8DC4: addiu       $t7, $t7, -0x13B8
    ctx->r15 = ADD32(ctx->r15, -0X13B8);
    // 0x801A8DC8: addu        $t6, $t5, $s3
    ctx->r14 = ADD32(ctx->r13, ctx->r19);
    // 0x801A8DCC: lw          $t4, 0x98($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X98);
    // 0x801A8DD0: addu        $s1, $t6, $t7
    ctx->r17 = ADD32(ctx->r14, ctx->r15);
    // 0x801A8DD4: sll         $t8, $s4, 2
    ctx->r24 = S32(ctx->r20 << 2);
    // 0x801A8DD8: sll         $t1, $s4, 2
    ctx->r9 = S32(ctx->r20 << 2);
    // 0x801A8DDC: addu        $t1, $t1, $s4
    ctx->r9 = ADD32(ctx->r9, ctx->r20);
    // 0x801A8DE0: addu        $t8, $t8, $s4
    ctx->r24 = ADD32(ctx->r24, ctx->r20);
    // 0x801A8DE4: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x801A8DE8: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x801A8DEC: lui         $t7, 0x604
    ctx->r15 = S32(0X604 << 16);
    // 0x801A8DF0: lui         $t6, 0x801D
    ctx->r14 = S32(0X801D << 16);
    // 0x801A8DF4: lui         $t0, 0x801D
    ctx->r8 = S32(0X801D << 16);
    // 0x801A8DF8: lui         $t3, 0x801D
    ctx->r11 = S32(0X801D << 16);
    // 0x801A8DFC: addiu       $t3, $t3, -0x1250
    ctx->r11 = ADD32(ctx->r11, -0X1250);
    // 0x801A8E00: addiu       $t0, $t0, -0x12C8
    ctx->r8 = ADD32(ctx->r8, -0X12C8);
    // 0x801A8E04: addiu       $t6, $t6, -0x25A0
    ctx->r14 = ADD32(ctx->r14, -0X25A0);
    // 0x801A8E08: addiu       $t7, $t7, 0x79D0
    ctx->r15 = ADD32(ctx->r15, 0X79D0);
    // 0x801A8E0C: addu        $t2, $t1, $s3
    ctx->r10 = ADD32(ctx->r9, ctx->r19);
    // 0x801A8E10: addu        $t9, $t8, $s3
    ctx->r25 = ADD32(ctx->r24, ctx->r19);
    // 0x801A8E14: sll         $t5, $t4, 6
    ctx->r13 = S32(ctx->r12 << 6);
    // 0x801A8E18: addu        $s2, $t5, $t6
    ctx->r18 = ADD32(ctx->r13, ctx->r14);
    // 0x801A8E1C: addu        $s5, $t9, $t0
    ctx->r21 = ADD32(ctx->r25, ctx->r8);
    // 0x801A8E20: addu        $s6, $t2, $t3
    ctx->r22 = ADD32(ctx->r10, ctx->r11);
    // 0x801A8E24: jal         0x80005708
    // 0x801A8E28: sw          $t7, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r15;
    Matrix_Push(rdram, ctx);
        goto after_6;
    // 0x801A8E28: sw          $t7, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r15;
    after_6:
    // 0x801A8E2C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A8E30: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x801A8E34: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x801A8E38: jal         0x80005754
    // 0x801A8E3C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_Mult(rdram, ctx);
        goto after_7;
    // 0x801A8E3C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_7:
    // 0x801A8E40: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A8E44: lwc1        $f8, 0x79CC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X79CC);
    // 0x801A8E48: lwc1        $f6, 0x0($s6)
    ctx->f6.u32l = MEM_W(ctx->r22, 0X0);
    // 0x801A8E4C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A8E50: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x801A8E54: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x801A8E58: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801A8E5C: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x801A8E60: jal         0x80005FE0
    // 0x801A8E64: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_8;
    // 0x801A8E64: nop

    after_8:
    // 0x801A8E68: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A8E6C: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    // 0x801A8E70: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x801A8E74: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801A8E78: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x801A8E7C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x801A8E80: jal         0x80005B00
    // 0x801A8E84: lw          $a2, 0x0($s5)
    ctx->r6 = MEM_W(ctx->r21, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_9;
    // 0x801A8E84: lw          $a2, 0x0($s5)
    ctx->r6 = MEM_W(ctx->r21, 0X0);
    after_9:
    // 0x801A8E88: lwc1        $f0, 0x0($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X0);
    // 0x801A8E8C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A8E90: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801A8E94: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801A8E98: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801A8E9C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x801A8EA0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x801A8EA4: jal         0x80005C34
    // 0x801A8EA8: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Scale(rdram, ctx);
        goto after_10;
    // 0x801A8EA8: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_10:
    // 0x801A8EAC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801A8EB0: jal         0x80006EB8
    // 0x801A8EB4: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_11;
    // 0x801A8EB4: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    after_11:
    // 0x801A8EB8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x801A8EBC: lw          $v0, 0x7E64($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7E64);
    // 0x801A8EC0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801A8EC4: lui         $t1, 0x600
    ctx->r9 = S32(0X600 << 16);
    // 0x801A8EC8: addiu       $t0, $v0, 0x8
    ctx->r8 = ADD32(ctx->r2, 0X8);
    // 0x801A8ECC: sw          $t0, 0x7E64($at)
    MEM_W(0X7E64, ctx->r1) = ctx->r8;
    // 0x801A8ED0: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x801A8ED4: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x801A8ED8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A8EDC: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x801A8EE0: jal         0x80005740
    // 0x801A8EE4: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Pop(rdram, ctx);
        goto after_12;
    // 0x801A8EE4: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_12:
L_801A8EE8:
    // 0x801A8EE8: lw          $t3, 0x94($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X94);
    // 0x801A8EEC: lw          $t5, 0x90($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X90);
    // 0x801A8EF0: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x801A8EF4: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x801A8EF8: sw          $t4, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r12;
    // 0x801A8EFC: addiu       $fp, $fp, 0x4
    ctx->r30 = ADD32(ctx->r30, 0X4);
    // 0x801A8F00: bne         $t4, $t5, L_801A8AB8
    if (ctx->r12 != ctx->r13) {
        // 0x801A8F04: addiu       $s7, $s7, 0x4
        ctx->r23 = ADD32(ctx->r23, 0X4);
            goto L_801A8AB8;
    }
    // 0x801A8F04: addiu       $s7, $s7, 0x4
    ctx->r23 = ADD32(ctx->r23, 0X4);
L_801A8F08:
    // 0x801A8F08: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x801A8F0C: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x801A8F10: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x801A8F14: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x801A8F18: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x801A8F1C: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x801A8F20: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x801A8F24: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x801A8F28: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x801A8F2C: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x801A8F30: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x801A8F34: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x801A8F38: jr          $ra
    // 0x801A8F3C: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x801A8F3C: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void Title_CopyrightSymbol_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018F85C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8018F860: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8018F864: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8018F868: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8018F86C: jal         0x800B8DD0
    // 0x8018F870: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x8018F870: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    after_0:
    // 0x8018F874: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8018F878: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8018F87C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8018F880: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8018F884: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8018F888: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x8018F88C: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8018F890: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8018F894: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8018F898: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8018F89C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8018F8A0: lui         $at, 0x436A
    ctx->r1 = S32(0X436A << 16);
    // 0x8018F8A4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018F8A8: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8018F8AC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018F8B0: lui         $a1, 0x601
    ctx->r5 = S32(0X601 << 16);
    // 0x8018F8B4: addiu       $a1, $a1, 0x3470
    ctx->r5 = ADD32(ctx->r5, 0X3470);
    // 0x8018F8B8: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x8018F8BC: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x8018F8C0: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x8018F8C4: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x8018F8C8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8018F8CC: jal         0x8009D994
    // 0x8018F8D0: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_1;
    // 0x8018F8D0: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x8018F8D4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8018F8D8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8018F8DC: jr          $ra
    // 0x8018F8E0: nop

    return;
    // 0x8018F8E0: nop

;}
RECOMP_FUNC void Title_Arwing_DrawEngineGlow(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D510: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8018D514: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8018D518: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x8018D51C: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8018D520: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8018D524: addiu       $s1, $s1, 0x7E64
    ctx->r17 = ADD32(ctx->r17, 0X7E64);
    // 0x8018D528: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8018D52C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8018D530: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8018D534: jal         0x800B8DD0
    // 0x8018D538: addiu       $a1, $zero, 0x43
    ctx->r5 = ADD32(0, 0X43);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x8018D538: addiu       $a1, $zero, 0x43
    ctx->r5 = ADD32(0, 0X43);
    after_0:
    // 0x8018D53C: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8018D540: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x8018D544: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8018D548: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8018D54C: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x8018D550: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8018D554: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8018D558: sll         $t9, $s2, 2
    ctx->r25 = S32(ctx->r18 << 2);
    // 0x8018D55C: subu        $t9, $t9, $s2
    ctx->r25 = SUB32(ctx->r25, ctx->r18);
    // 0x8018D560: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x8018D564: subu        $t9, $t9, $s2
    ctx->r25 = SUB32(ctx->r25, ctx->r18);
    // 0x8018D568: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x8018D56C: addiu       $t0, $t0, -0x7B18
    ctx->r8 = ADD32(ctx->r8, -0X7B18);
    // 0x8018D570: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8018D574: addu        $s0, $t9, $t0
    ctx->r16 = ADD32(ctx->r25, ctx->r8);
    // 0x8018D578: lw          $t1, 0x40($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X40);
    // 0x8018D57C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8018D580: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x8018D584: bne         $t1, $at, L_8018D5C4
    if (ctx->r9 != ctx->r1) {
        // 0x8018D588: lui         $s2, 0x8014
        ctx->r18 = S32(0X8014 << 16);
            goto L_8018D5C4;
    }
    // 0x8018D588: lui         $s2, 0x8014
    ctx->r18 = S32(0X8014 << 16);
    // 0x8018D58C: lui         $at, 0xC1F0
    ctx->r1 = S32(0XC1F0 << 16);
    // 0x8018D590: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8018D594: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018D598: lwc1        $f2, 0x7024($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X7024);
    // 0x8018D59C: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8018D5A0: lui         $t4, 0x8080
    ctx->r12 = S32(0X8080 << 16);
    // 0x8018D5A4: ori         $t4, $t4, 0xFFFF
    ctx->r12 = ctx->r12 | 0XFFFF;
    // 0x8018D5A8: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x8018D5AC: sw          $t2, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r10;
    // 0x8018D5B0: lui         $t3, 0xFB00
    ctx->r11 = S32(0XFB00 << 16);
    // 0x8018D5B4: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8018D5B8: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x8018D5BC: b           L_8018D5F0
    // 0x8018D5C0: nop

        goto L_8018D5F0;
    // 0x8018D5C0: nop

L_8018D5C4:
    // 0x8018D5C4: lui         $at, 0xC282
    ctx->r1 = S32(0XC282 << 16);
    // 0x8018D5C8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8018D5CC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018D5D0: lwc1        $f2, 0x7028($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X7028);
    // 0x8018D5D4: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8018D5D8: lui         $t6, 0xFB00
    ctx->r14 = S32(0XFB00 << 16);
    // 0x8018D5DC: ori         $t7, $zero, 0xFFFF
    ctx->r15 = 0 | 0XFFFF;
    // 0x8018D5E0: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x8018D5E4: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
    // 0x8018D5E8: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8018D5EC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
L_8018D5F0:
    // 0x8018D5F0: lw          $t8, 0x7DB0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7DB0);
    // 0x8018D5F4: addiu       $s2, $s2, -0x4C40
    ctx->r18 = ADD32(ctx->r18, -0X4C40);
    // 0x8018D5F8: lwc1        $f0, 0x44($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X44);
    // 0x8018D5FC: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x8018D600: beq         $t9, $zero, L_8018D60C
    if (ctx->r25 == 0) {
        // 0x8018D604: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_8018D60C;
    }
    // 0x8018D604: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8018D608: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
L_8018D60C:
    // 0x8018D60C: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x8018D610: jal         0x80005708
    // 0x8018D614: swc1        $f12, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f12.u32l;
    Matrix_Push(rdram, ctx);
        goto after_1;
    // 0x8018D614: swc1        $f12, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f12.u32l;
    after_1:
    // 0x8018D618: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8018D61C: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8018D620: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8018D624: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x8018D628: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x8018D62C: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x8018D630: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8018D634: jal         0x80005B00
    // 0x8018D638: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_2;
    // 0x8018D638: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_2:
    // 0x8018D63C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018D640: lwc1        $f0, 0x44($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8018D644: lwc1        $f4, 0x702C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X702C);
    // 0x8018D648: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8018D64C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8018D650: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8018D654: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8018D658: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8018D65C: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8018D660: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x8018D664: jal         0x80005C34
    // 0x8018D668: nop

    Matrix_Scale(rdram, ctx);
        goto after_3;
    // 0x8018D668: nop

    after_3:
    // 0x8018D66C: lwc1        $f8, 0x20($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X20);
    // 0x8018D670: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018D674: lwc1        $f18, 0x7030($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7030);
    // 0x8018D678: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x8018D67C: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8018D680: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8018D684: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018D688: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8018D68C: jal         0x80005FE0
    // 0x8018D690: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_4;
    // 0x8018D690: nop

    after_4:
    // 0x8018D694: lwc1        $f6, 0x18($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8018D698: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018D69C: lwc1        $f10, 0x7034($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7034);
    // 0x8018D6A0: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x8018D6A4: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8018D6A8: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8018D6AC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018D6B0: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8018D6B4: jal         0x80005D44
    // 0x8018D6B8: nop

    Matrix_RotateX(rdram, ctx);
        goto after_5;
    // 0x8018D6B8: nop

    after_5:
    // 0x8018D6BC: lwc1        $f4, 0x1C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x8018D6C0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018D6C4: lwc1        $f8, 0x7038($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7038);
    // 0x8018D6C8: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x8018D6CC: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8018D6D0: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8018D6D4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018D6D8: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8018D6DC: jal         0x80005E90
    // 0x8018D6E0: nop

    Matrix_RotateY(rdram, ctx);
        goto after_6;
    // 0x8018D6E0: nop

    after_6:
    // 0x8018D6E4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018D6E8: lwc1        $f18, 0x7978($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7978);
    // 0x8018D6EC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018D6F0: lwc1        $f6, 0x7988($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7988);
    // 0x8018D6F4: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8018D6F8: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8018D6FC: sub.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8018D700: jal         0x80005100
    // 0x8018D704: sub.s       $f14, $f6, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f8.fl;
    Math_Atan2F(rdram, ctx);
        goto after_7;
    // 0x8018D704: sub.s       $f14, $f6, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f8.fl;
    after_7:
    // 0x8018D708: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018D70C: lwc1        $f18, 0x7978($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7978);
    // 0x8018D710: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8018D714: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018D718: lwc1        $f6, 0x7988($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7988);
    // 0x8018D71C: sub.s       $f2, $f18, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8018D720: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8018D724: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018D728: neg.s       $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = -ctx->f0.fl;
    // 0x8018D72C: sub.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8018D730: swc1        $f10, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f10.u32l;
    // 0x8018D734: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8018D738: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8018D73C: lwc1        $f4, 0x7980($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7980);
    // 0x8018D740: mul.s       $f18, $f16, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x8018D744: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8018D748: add.s       $f0, $f10, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8018D74C: jal         0x80005100
    // 0x8018D750: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    Math_Atan2F(rdram, ctx);
        goto after_8;
    // 0x8018D750: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    after_8:
    // 0x8018D754: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8018D758: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x8018D75C: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8018D760: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x8018D764: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018D768: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8018D76C: jal         0x80005E90
    // 0x8018D770: nop

    Matrix_RotateY(rdram, ctx);
        goto after_9;
    // 0x8018D770: nop

    after_9:
    // 0x8018D774: lwc1        $f18, 0x40($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8018D778: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8018D77C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018D780: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x8018D784: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8018D788: jal         0x80005D44
    // 0x8018D78C: nop

    Matrix_RotateX(rdram, ctx);
        goto after_10;
    // 0x8018D78C: nop

    after_10:
    // 0x8018D790: jal         0x80006EB8
    // 0x8018D794: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_11;
    // 0x8018D794: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_11:
    // 0x8018D798: addiu       $a3, $zero, 0x2000
    ctx->r7 = ADD32(0, 0X2000);
    // 0x8018D79C: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8018D7A0: lui         $t3, 0xB600
    ctx->r11 = S32(0XB600 << 16);
    // 0x8018D7A4: lui         $t5, 0x600
    ctx->r13 = S32(0X600 << 16);
    // 0x8018D7A8: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x8018D7AC: sw          $t2, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r10;
    // 0x8018D7B0: sw          $a3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r7;
    // 0x8018D7B4: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8018D7B8: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8018D7BC: lui         $t6, 0x603
    ctx->r14 = S32(0X603 << 16);
    // 0x8018D7C0: addiu       $t6, $t6, 0x20E0
    ctx->r14 = ADD32(ctx->r14, 0X20E0);
    // 0x8018D7C4: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x8018D7C8: sw          $t4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r12;
    // 0x8018D7CC: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8018D7D0: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8018D7D4: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8018D7D8: lui         $t8, 0xB700
    ctx->r24 = S32(0XB700 << 16);
    // 0x8018D7DC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8018D7E0: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x8018D7E4: sw          $a3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r7;
    // 0x8018D7E8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8018D7EC: jal         0x80005740
    // 0x8018D7F0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_12;
    // 0x8018D7F0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_12:
    // 0x8018D7F4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8018D7F8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8018D7FC: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8018D800: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8018D804: jr          $ra
    // 0x8018D808: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8018D808: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void Option_Vs_TimeTrial_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019A214: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8019A218: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8019A21C: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8019A220: lw          $v0, -0x6ED4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6ED4);
    // 0x8019A224: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8019A228: beq         $v0, $zero, L_8019A250
    if (ctx->r2 == 0) {
        // 0x8019A22C: nop
    
            goto L_8019A250;
    }
    // 0x8019A22C: nop

    // 0x8019A230: beq         $v0, $at, L_8019A260
    if (ctx->r2 == ctx->r1) {
        // 0x8019A234: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8019A260;
    }
    // 0x8019A234: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8019A238: beq         $v0, $at, L_8019A270
    if (ctx->r2 == ctx->r1) {
        // 0x8019A23C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8019A270;
    }
    // 0x8019A23C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8019A240: beq         $v0, $at, L_8019A280
    if (ctx->r2 == ctx->r1) {
        // 0x8019A244: nop
    
            goto L_8019A280;
    }
    // 0x8019A244: nop

    // 0x8019A248: b           L_8019A28C
    // 0x8019A24C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8019A28C;
    // 0x8019A24C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8019A250:
    // 0x8019A250: jal         0x8019A4DC
    // 0x8019A254: nop

    Option_VsTimeSelection(rdram, ctx);
        goto after_0;
    // 0x8019A254: nop

    after_0:
    // 0x8019A258: b           L_8019A28C
    // 0x8019A25C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8019A28C;
    // 0x8019A25C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8019A260:
    // 0x8019A260: jal         0x8019A6DC
    // 0x8019A264: nop

    Option_VsStageSelection(rdram, ctx);
        goto after_1;
    // 0x8019A264: nop

    after_1:
    // 0x8019A268: b           L_8019A28C
    // 0x8019A26C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8019A28C;
    // 0x8019A26C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8019A270:
    // 0x8019A270: jal         0x8019A954
    // 0x8019A274: nop

    Option_VsConfirmSelection(rdram, ctx);
        goto after_2;
    // 0x8019A274: nop

    after_2:
    // 0x8019A278: b           L_8019A28C
    // 0x8019A27C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8019A28C;
    // 0x8019A27C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8019A280:
    // 0x8019A280: jal         0x8019A298
    // 0x8019A284: nop

    Option_Vs_StartMatch(rdram, ctx);
        goto after_3;
    // 0x8019A284: nop

    after_3:
    // 0x8019A288: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8019A28C:
    // 0x8019A28C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8019A290: jr          $ra
    // 0x8019A294: nop

    return;
    // 0x8019A294: nop

;}
RECOMP_FUNC void Map_PlayLevel(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A6628: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801A662C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801A6630: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
    // 0x801A6634: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801A6638: sw          $t6, 0x7834($at)
    MEM_W(0X7834, ctx->r1) = ctx->r14;
    // 0x801A663C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801A6640: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x801A6644: sw          $t7, 0x783C($at)
    MEM_W(0X783C, ctx->r1) = ctx->r15;
    // 0x801A6648: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801A664C: sw          $zero, 0x7854($at)
    MEM_W(0X7854, ctx->r1) = 0;
    // 0x801A6650: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801A6654: sw          $zero, 0x7898($at)
    MEM_W(0X7898, ctx->r1) = 0;
    // 0x801A6658: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x801A665C: jal         0x800A5844
    // 0x801A6660: sw          $zero, 0x1A98($at)
    MEM_W(0X1A98, ctx->r1) = 0;
    Play_Setup(rdram, ctx);
        goto after_0;
    // 0x801A6660: sw          $zero, 0x1A98($at)
    MEM_W(0X1A98, ctx->r1) = 0;
    after_0:
    // 0x801A6664: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801A6668: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801A666C: sw          $zero, 0x7CA0($at)
    MEM_W(0X7CA0, ctx->r1) = 0;
    // 0x801A6670: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801A6674: swc1        $f4, 0x7CB0($at)
    MEM_W(0X7CB0, ctx->r1) = ctx->f4.u32l;
    // 0x801A6678: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801A667C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801A6680: sw          $t8, 0x782C($at)
    MEM_W(0X782C, ctx->r1) = ctx->r24;
    // 0x801A6684: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801A6688: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801A668C: jr          $ra
    // 0x801A6690: nop

    return;
    // 0x801A6690: nop

;}
RECOMP_FUNC void Title_TeamRunning_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018E67C: addiu       $sp, $sp, -0x2B8
    ctx->r29 = ADD32(ctx->r29, -0X2B8);
    // 0x8018E680: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x8018E684: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x8018E688: addiu       $s1, $s1, 0x7E64
    ctx->r17 = ADD32(ctx->r17, 0X7E64);
    // 0x8018E68C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8018E690: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x8018E694: sw          $a0, 0x2B8($sp)
    MEM_W(0X2B8, ctx->r29) = ctx->r4;
    // 0x8018E698: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018E69C: lwc1        $f4, -0x7D20($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7D20);
    // 0x8018E6A0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018E6A4: lwc1        $f8, -0x7D1C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X7D1C);
    // 0x8018E6A8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018E6AC: lwc1        $f16, -0x7D18($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X7D18);
    // 0x8018E6B0: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8018E6B4: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8018E6B8: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8018E6BC: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8018E6C0: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8018E6C4: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8018E6C8: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8018E6CC: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8018E6D0: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8018E6D4: lw          $t4, -0x7AA4($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7AA4);
    // 0x8018E6D8: lw          $t3, -0x7AA8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X7AA8);
    // 0x8018E6DC: lw          $t2, -0x7AAC($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X7AAC);
    // 0x8018E6E0: lw          $t1, -0x7AB0($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X7AB0);
    // 0x8018E6E4: lw          $t0, -0x7AB4($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7AB4);
    // 0x8018E6E8: lw          $t9, -0x7AB8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7AB8);
    // 0x8018E6EC: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x8018E6F0: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x8018E6F4: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8018E6F8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8018E6FC: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    // 0x8018E700: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    // 0x8018E704: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x8018E708: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x8018E70C: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8018E710: jal         0x8000372C
    // 0x8018E714: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    Lights_SetOneLight(rdram, ctx);
        goto after_0;
    // 0x8018E714: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_0:
    // 0x8018E718: lw          $t5, 0x2B8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2B8);
    // 0x8018E71C: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x8018E720: addiu       $t7, $t7, -0x2600
    ctx->r15 = ADD32(ctx->r15, -0X2600);
    // 0x8018E724: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8018E728: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x8018E72C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8018E730: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x8018E734: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8018E738: jal         0x8009ACDC
    // 0x8018E73C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    Animation_GetFrameCount(rdram, ctx);
        goto after_1;
    // 0x8018E73C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_1:
    // 0x8018E740: lw          $t8, 0x2B8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2B8);
    // 0x8018E744: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x8018E748: addiu       $t0, $t0, -0x7CB0
    ctx->r8 = ADD32(ctx->r8, -0X7CB0);
    // 0x8018E74C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8018E750: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8018E754: sll         $t9, $t9, 5
    ctx->r25 = S32(ctx->r25 << 5);
    // 0x8018E758: addu        $s0, $t9, $t0
    ctx->r16 = ADD32(ctx->r25, ctx->r8);
    // 0x8018E75C: lw          $t1, 0x58($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X58);
    // 0x8018E760: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8018E764: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8018E768: div         $zero, $t1, $v0
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r2)));
    // 0x8018E76C: mfhi        $t2
    ctx->r10 = hi;
    // 0x8018E770: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x8018E774: addiu       $t3, $zero, 0x3E3
    ctx->r11 = ADD32(0, 0X3E3);
    // 0x8018E778: addiu       $t4, $zero, 0x3E8
    ctx->r12 = ADD32(0, 0X3E8);
    // 0x8018E77C: bne         $v0, $zero, L_8018E788
    if (ctx->r2 != 0) {
        // 0x8018E780: nop
    
            goto L_8018E788;
    }
    // 0x8018E780: nop

    // 0x8018E784: break       7
    do_break(2149115780);
L_8018E788:
    // 0x8018E788: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8018E78C: bne         $v0, $at, L_8018E7A0
    if (ctx->r2 != ctx->r1) {
        // 0x8018E790: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8018E7A0;
    }
    // 0x8018E790: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8018E794: bne         $t1, $at, L_8018E7A0
    if (ctx->r9 != ctx->r1) {
        // 0x8018E798: nop
    
            goto L_8018E7A0;
    }
    // 0x8018E798: nop

    // 0x8018E79C: break       6
    do_break(2149115804);
L_8018E7A0:
    // 0x8018E7A0: sw          $t2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r10;
    // 0x8018E7A4: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x8018E7A8: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8018E7AC: lw          $a2, -0x7CD0($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7CD0);
    // 0x8018E7B0: lw          $a1, -0x7CD8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7CD8);
    // 0x8018E7B4: lw          $a0, -0x7CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7CE0);
    // 0x8018E7B8: jal         0x800BA1D0
    // 0x8018E7BC: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    RCP_SetupDL_29(rdram, ctx);
        goto after_2;
    // 0x8018E7BC: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_2:
    // 0x8018E7C0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018E7C4: jal         0x80005708
    // 0x8018E7C8: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Push(rdram, ctx);
        goto after_3;
    // 0x8018E7C8: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_3:
    // 0x8018E7CC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018E7D0: lwc1        $f6, -0x7B30($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7B30);
    // 0x8018E7D4: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8018E7D8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018E7DC: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8018E7E0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8018E7E4: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8018E7E8: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8018E7EC: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x8018E7F0: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x8018E7F4: jal         0x80005B00
    // 0x8018E7F8: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    Matrix_Translate(rdram, ctx);
        goto after_4;
    // 0x8018E7F8: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    after_4:
    // 0x8018E7FC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018E800: lwc1        $f0, -0x7B2C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7B2C);
    // 0x8018E804: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018E808: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8018E80C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8018E810: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8018E814: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8018E818: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8018E81C: jal         0x80005C34
    // 0x8018E820: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Scale(rdram, ctx);
        goto after_5;
    // 0x8018E820: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_5:
    // 0x8018E824: jal         0x80006EB8
    // 0x8018E828: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_6;
    // 0x8018E828: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_6:
    // 0x8018E82C: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x8018E830: addiu       $t7, $t7, -0x7BF0
    ctx->r15 = ADD32(ctx->r15, -0X7BF0);
    // 0x8018E834: bne         $s0, $t7, L_8018E858
    if (ctx->r16 != ctx->r15) {
        // 0x8018E838: addiu       $a2, $sp, 0x60
        ctx->r6 = ADD32(ctx->r29, 0X60);
            goto L_8018E858;
    }
    // 0x8018E838: addiu       $a2, $sp, 0x60
    ctx->r6 = ADD32(ctx->r29, 0X60);
    // 0x8018E83C: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8018E840: lui         $t9, 0xB600
    ctx->r25 = S32(0XB600 << 16);
    // 0x8018E844: addiu       $t0, $zero, 0x2000
    ctx->r8 = ADD32(0, 0X2000);
    // 0x8018E848: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8018E84C: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x8018E850: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x8018E854: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
L_8018E858:
    // 0x8018E858: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x8018E85C: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x8018E860: jal         0x8009AA20
    // 0x8018E864: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    Animation_GetFrameData(rdram, ctx);
        goto after_7;
    // 0x8018E864: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    after_7:
    // 0x8018E868: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x8018E86C: lui         $t3, 0x800C
    ctx->r11 = S32(0X800C << 16);
    // 0x8018E870: addiu       $t3, $t3, 0x4660
    ctx->r11 = ADD32(ctx->r11, 0X4660);
    // 0x8018E874: lw          $a1, 0x8($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X8);
    // 0x8018E878: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x8018E87C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8018E880: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8018E884: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8018E888: addiu       $a2, $sp, 0x60
    ctx->r6 = ADD32(ctx->r29, 0X60);
    // 0x8018E88C: jal         0x8009A72C
    // 0x8018E890: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    Animation_DrawSkeleton(rdram, ctx);
        goto after_8;
    // 0x8018E890: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_8:
    // 0x8018E894: lui         $t4, 0x801C
    ctx->r12 = S32(0X801C << 16);
    // 0x8018E898: addiu       $t4, $t4, -0x7BF0
    ctx->r12 = ADD32(ctx->r12, -0X7BF0);
    // 0x8018E89C: bne         $s0, $t4, L_8018E8C0
    if (ctx->r16 != ctx->r12) {
        // 0x8018E8A0: lui         $t8, 0x801C
        ctx->r24 = S32(0X801C << 16);
            goto L_8018E8C0;
    }
    // 0x8018E8A0: lui         $t8, 0x801C
    ctx->r24 = S32(0X801C << 16);
    // 0x8018E8A4: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8018E8A8: lui         $t6, 0xB700
    ctx->r14 = S32(0XB700 << 16);
    // 0x8018E8AC: addiu       $t7, $zero, 0x2000
    ctx->r15 = ADD32(0, 0X2000);
    // 0x8018E8B0: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x8018E8B4: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
    // 0x8018E8B8: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8018E8BC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
L_8018E8C0:
    // 0x8018E8C0: addiu       $t8, $t8, -0x7CB0
    ctx->r24 = ADD32(ctx->r24, -0X7CB0);
    // 0x8018E8C4: bne         $s0, $t8, L_8018E8D4
    if (ctx->r16 != ctx->r24) {
        // 0x8018E8C8: lui         $a0, 0x801C
        ctx->r4 = S32(0X801C << 16);
            goto L_8018E8D4;
    }
    // 0x8018E8C8: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8018E8CC: jal         0x8005F1EC
    // 0x8018E8D0: addiu       $a0, $a0, -0x7B28
    ctx->r4 = ADD32(ctx->r4, -0X7B28);
    Object_UpdateSfxSource(rdram, ctx);
        goto after_9;
    // 0x8018E8D0: addiu       $a0, $a0, -0x7B28
    ctx->r4 = ADD32(ctx->r4, -0X7B28);
    after_9:
L_8018E8D4:
    // 0x8018E8D4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018E8D8: jal         0x80005740
    // 0x8018E8DC: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Pop(rdram, ctx);
        goto after_10;
    // 0x8018E8DC: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_10:
    // 0x8018E8E0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018E8E4: jal         0x80005708
    // 0x8018E8E8: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Push(rdram, ctx);
        goto after_11;
    // 0x8018E8E8: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_11:
    // 0x8018E8EC: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8018E8F0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8018E8F4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8018E8F8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018E8FC: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8018E900: lwc1        $f10, 0x0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8018E904: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018E908: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8018E90C: lwc1        $f8, -0x7B30($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X7B30);
    // 0x8018E910: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018E914: sub.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x8018E918: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8018E91C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8018E920: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8018E924: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8018E928: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8018E92C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8018E930: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x8018E934: jal         0x80005B00
    // 0x8018E938: nop

    Matrix_Translate(rdram, ctx);
        goto after_12;
    // 0x8018E938: nop

    after_12:
    // 0x8018E93C: lwc1        $f0, 0x10($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8018E940: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018E944: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8018E948: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8018E94C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8018E950: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8018E954: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8018E958: jal         0x80005C34
    // 0x8018E95C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Scale(rdram, ctx);
        goto after_13;
    // 0x8018E95C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_13:
    // 0x8018E960: jal         0x80006EB8
    // 0x8018E964: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_14;
    // 0x8018E964: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_14:
    // 0x8018E968: jal         0x800BA140
    // 0x8018E96C: nop

    RCP_SetupDL_64(rdram, ctx);
        goto after_15;
    // 0x8018E96C: nop

    after_15:
    // 0x8018E970: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8018E974: lui         $t2, 0xFA00
    ctx->r10 = S32(0XFA00 << 16);
    // 0x8018E978: addiu       $t3, $zero, -0x80
    ctx->r11 = ADD32(0, -0X80);
    // 0x8018E97C: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x8018E980: sw          $t1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r9;
    // 0x8018E984: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x8018E988: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x8018E98C: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8018E990: lui         $t6, 0x604
    ctx->r14 = S32(0X604 << 16);
    // 0x8018E994: addiu       $t6, $t6, 0x1070
    ctx->r14 = ADD32(ctx->r14, 0X1070);
    // 0x8018E998: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x8018E99C: sw          $t4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r12;
    // 0x8018E9A0: lui         $t5, 0x600
    ctx->r13 = S32(0X600 << 16);
    // 0x8018E9A4: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8018E9A8: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8018E9AC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018E9B0: jal         0x80005740
    // 0x8018E9B4: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Pop(rdram, ctx);
        goto after_16;
    // 0x8018E9B4: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_16:
    // 0x8018E9B8: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    // 0x8018E9BC: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x8018E9C0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018E9C4: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x8018E9C8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018E9CC: lwc1        $f8, 0x707C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X707C);
    // 0x8018E9D0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8018E9D4: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8018E9D8: nop

    // 0x8018E9DC: mul.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8018E9E0: jal         0x80023090
    // 0x8018E9E4: nop

    __sinf_recomp(rdram, ctx);
        goto after_17;
    // 0x8018E9E4: nop

    after_17:
    // 0x8018E9E8: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x8018E9EC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018E9F0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8018E9F4: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x8018E9F8: mul.s       $f2, $f0, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8018E9FC: c.le.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl <= ctx->f2.fl;
    // 0x8018EA00: nop

    // 0x8018EA04: bc1fl       L_8018EA18
    if (!c1cs) {
        // 0x8018EA08: mtc1        $at, $f18
        ctx->f18.u32l = ctx->r1;
            goto L_8018EA18;
    }
    goto skip_0;
    // 0x8018EA08: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    skip_0:
    // 0x8018EA0C: b           L_8018EA44
    // 0x8018EA10: swc1        $f2, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f2.u32l;
        goto L_8018EA44;
    // 0x8018EA10: swc1        $f2, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f2.u32l;
    // 0x8018EA14: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
L_8018EA18:
    // 0x8018EA18: nop

    // 0x8018EA1C: c.lt.s      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl < ctx->f2.fl;
    // 0x8018EA20: nop

    // 0x8018EA24: bc1fl       L_8018EA3C
    if (!c1cs) {
        // 0x8018EA28: mtc1        $zero, $f6
        ctx->f6.u32l = 0;
            goto L_8018EA3C;
    }
    goto skip_1;
    // 0x8018EA28: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    skip_1:
    // 0x8018EA2C: neg.s       $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = -ctx->f2.fl;
    // 0x8018EA30: b           L_8018EA44
    // 0x8018EA34: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
        goto L_8018EA44;
    // 0x8018EA34: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
    // 0x8018EA38: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
L_8018EA3C:
    // 0x8018EA3C: nop

    // 0x8018EA40: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
L_8018EA44:
    // 0x8018EA44: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8018EA48: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018EA4C: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8018EA50: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8018EA54: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8018EA58: div.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8018EA5C: sub.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x8018EA60: swc1        $f4, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f4.u32l;
    // 0x8018EA64: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8018EA68: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x8018EA6C: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x8018EA70: jr          $ra
    // 0x8018EA74: addiu       $sp, $sp, 0x2B8
    ctx->r29 = ADD32(ctx->r29, 0X2B8);
    return;
    // 0x8018EA74: addiu       $sp, $sp, 0x2B8
    ctx->r29 = ADD32(ctx->r29, 0X2B8);
;}
RECOMP_FUNC void Title_CsGreatFoxCloseUp_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018ACEC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8018ACF0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8018ACF4: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8018ACF8: lw          $v0, -0x7D40($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D40);
    // 0x8018ACFC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8018AD00: beq         $v0, $zero, L_8018AD18
    if (ctx->r2 == 0) {
        // 0x8018AD04: nop
    
            goto L_8018AD18;
    }
    // 0x8018AD04: nop

    // 0x8018AD08: beq         $v0, $at, L_8018ADB0
    if (ctx->r2 == ctx->r1) {
        // 0x8018AD0C: lui         $a0, 0x801C
        ctx->r4 = S32(0X801C << 16);
            goto L_8018ADB0;
    }
    // 0x8018AD0C: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8018AD10: b           L_8018AF20
    // 0x8018AD14: nop

        goto L_8018AF20;
    // 0x8018AD14: nop

L_8018AD18:
    // 0x8018AD18: jal         0x8018ABC0
    // 0x8018AD1C: nop

    Title_CsGreatFoxCloseUp_Setup(rdram, ctx);
        goto after_0;
    // 0x8018AD1C: nop

    after_0:
    // 0x8018AD20: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8018AD24: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x8018AD28: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8018AD2C: addiu       $t6, $t6, 0x5D3C
    ctx->r14 = ADD32(ctx->r14, 0X5D3C);
    // 0x8018AD30: lui         $a0, 0x1103
    ctx->r4 = S32(0X1103 << 16);
    // 0x8018AD34: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x8018AD38: addiu       $a1, $a1, -0x7984
    ctx->r5 = ADD32(ctx->r5, -0X7984);
    // 0x8018AD3C: ori         $a0, $a0, 0x10
    ctx->r4 = ctx->r4 | 0X10;
    // 0x8018AD40: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8018AD44: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8018AD48: jal         0x80019218
    // 0x8018AD4C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Audio_PlaySfx(rdram, ctx);
        goto after_1;
    // 0x8018AD4C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x8018AD50: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8018AD54: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x8018AD58: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8018AD5C: addiu       $t7, $t7, 0x5D3C
    ctx->r15 = ADD32(ctx->r15, 0X5D3C);
    // 0x8018AD60: lui         $a0, 0x3102
    ctx->r4 = S32(0X3102 << 16);
    // 0x8018AD64: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x8018AD68: addiu       $a1, $a1, -0x7984
    ctx->r5 = ADD32(ctx->r5, -0X7984);
    // 0x8018AD6C: ori         $a0, $a0, 0x4059
    ctx->r4 = ctx->r4 | 0X4059;
    // 0x8018AD70: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8018AD74: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8018AD78: jal         0x80019218
    // 0x8018AD7C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Audio_PlaySfx(rdram, ctx);
        goto after_2;
    // 0x8018AD7C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x8018AD80: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018AD84: lwc1        $f4, 0x6F20($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6F20);
    // 0x8018AD88: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018AD8C: lui         $t8, 0x801C
    ctx->r24 = S32(0X801C << 16);
    // 0x8018AD90: lw          $t8, -0x7D40($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7D40);
    // 0x8018AD94: swc1        $f4, -0x7D34($at)
    MEM_W(-0X7D34, ctx->r1) = ctx->f4.u32l;
    // 0x8018AD98: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018AD9C: sw          $zero, -0x7D4C($at)
    MEM_W(-0X7D4C, ctx->r1) = 0;
    // 0x8018ADA0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018ADA4: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8018ADA8: b           L_8018AF20
    // 0x8018ADAC: sw          $t9, -0x7D40($at)
    MEM_W(-0X7D40, ctx->r1) = ctx->r25;
        goto L_8018AF20;
    // 0x8018ADAC: sw          $t9, -0x7D40($at)
    MEM_W(-0X7D40, ctx->r1) = ctx->r25;
L_8018ADB0:
    // 0x8018ADB0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018ADB4: lwc1        $f6, 0x6F24($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6F24);
    // 0x8018ADB8: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x8018ADBC: lw          $a2, -0x7D34($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7D34);
    // 0x8018ADC0: addiu       $a0, $a0, -0x7958
    ctx->r4 = ADD32(ctx->r4, -0X7958);
    // 0x8018ADC4: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    // 0x8018ADC8: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x8018ADCC: jal         0x8009BC2C
    // 0x8018ADD0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_3;
    // 0x8018ADD0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_3:
    // 0x8018ADD4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018ADD8: lwc1        $f8, 0x6F28($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6F28);
    // 0x8018ADDC: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8018ADE0: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x8018ADE4: lw          $a2, -0x7D34($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7D34);
    // 0x8018ADE8: addiu       $a0, $a0, -0x7954
    ctx->r4 = ADD32(ctx->r4, -0X7954);
    // 0x8018ADEC: lui         $a1, 0xC170
    ctx->r5 = S32(0XC170 << 16);
    // 0x8018ADF0: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x8018ADF4: jal         0x8009BC2C
    // 0x8018ADF8: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_4;
    // 0x8018ADF8: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_4:
    // 0x8018ADFC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018AE00: lwc1        $f10, 0x6F2C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6F2C);
    // 0x8018AE04: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8018AE08: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x8018AE0C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8018AE10: addiu       $a0, $a0, 0x79A0
    ctx->r4 = ADD32(ctx->r4, 0X79A0);
    // 0x8018AE14: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8018AE18: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x8018AE1C: jal         0x8009BC2C
    // 0x8018AE20: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_5;
    // 0x8018AE20: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_5:
    // 0x8018AE24: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018AE28: lwc1        $f16, 0x6F30($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6F30);
    // 0x8018AE2C: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8018AE30: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x8018AE34: lw          $a2, -0x7D34($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7D34);
    // 0x8018AE38: addiu       $a0, $a0, 0x79B8
    ctx->r4 = ADD32(ctx->r4, 0X79B8);
    // 0x8018AE3C: lui         $a1, 0xC220
    ctx->r5 = S32(0XC220 << 16);
    // 0x8018AE40: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x8018AE44: jal         0x8009BC2C
    // 0x8018AE48: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_6;
    // 0x8018AE48: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_6:
    // 0x8018AE4C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018AE50: lwc1        $f18, 0x6F34($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6F34);
    // 0x8018AE54: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8018AE58: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x8018AE5C: lw          $a2, -0x7D34($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7D34);
    // 0x8018AE60: addiu       $a0, $a0, -0x7950
    ctx->r4 = ADD32(ctx->r4, -0X7950);
    // 0x8018AE64: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    // 0x8018AE68: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x8018AE6C: jal         0x8009BC2C
    // 0x8018AE70: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_7;
    // 0x8018AE70: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_7:
    // 0x8018AE74: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018AE78: lwc1        $f4, -0x7D34($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7D34);
    // 0x8018AE7C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018AE80: lwc1        $f6, 0x6F38($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6F38);
    // 0x8018AE84: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x8018AE88: lw          $t0, -0x7D4C($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7D4C);
    // 0x8018AE8C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8018AE90: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018AE94: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8018AE98: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8018AE9C: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8018AEA0: addiu       $a0, $a0, -0x7984
    ctx->r4 = ADD32(ctx->r4, -0X7984);
    // 0x8018AEA4: lui         $a1, 0x1103
    ctx->r5 = S32(0X1103 << 16);
    // 0x8018AEA8: swc1        $f8, -0x7D34($at)
    MEM_W(-0X7D34, ctx->r1) = ctx->f8.u32l;
    // 0x8018AEAC: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x8018AEB0: bne         $t0, $at, L_8018AEBC
    if (ctx->r8 != ctx->r1) {
        // 0x8018AEB4: lui         $at, 0x801C
        ctx->r1 = S32(0X801C << 16);
            goto L_8018AEBC;
    }
    // 0x8018AEB4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018AEB8: sw          $t1, -0x7964($at)
    MEM_W(-0X7964, ctx->r1) = ctx->r9;
L_8018AEBC:
    // 0x8018AEBC: lw          $t2, -0x7CC0($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X7CC0);
    // 0x8018AEC0: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8018AEC4: bne         $t2, $at, L_8018AF04
    if (ctx->r10 != ctx->r1) {
        // 0x8018AEC8: nop
    
            goto L_8018AF04;
    }
    // 0x8018AEC8: nop

    // 0x8018AECC: jal         0x8001A55C
    // 0x8018AED0: ori         $a1, $a1, 0x10
    ctx->r5 = ctx->r5 | 0X10;
    Audio_KillSfxBySourceAndId(rdram, ctx);
        goto after_8;
    // 0x8018AED0: ori         $a1, $a1, 0x10
    ctx->r5 = ctx->r5 | 0X10;
    after_8:
    // 0x8018AED4: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8018AED8: lui         $a1, 0x3102
    ctx->r5 = S32(0X3102 << 16);
    // 0x8018AEDC: ori         $a1, $a1, 0x4059
    ctx->r5 = ctx->r5 | 0X4059;
    // 0x8018AEE0: jal         0x8001A55C
    // 0x8018AEE4: addiu       $a0, $a0, -0x7984
    ctx->r4 = ADD32(ctx->r4, -0X7984);
    Audio_KillSfxBySourceAndId(rdram, ctx);
        goto after_9;
    // 0x8018AEE4: addiu       $a0, $a0, -0x7984
    ctx->r4 = ADD32(ctx->r4, -0X7984);
    after_9:
    // 0x8018AEE8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018AEEC: sw          $zero, 0x7898($at)
    MEM_W(0X7898, ctx->r1) = 0;
    // 0x8018AEF0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018AEF4: sw          $zero, -0x7D40($at)
    MEM_W(-0X7D40, ctx->r1) = 0;
    // 0x8018AEF8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018AEFC: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x8018AF00: sw          $t3, -0x7D3C($at)
    MEM_W(-0X7D3C, ctx->r1) = ctx->r11;
L_8018AF04:
    // 0x8018AF04: jal         0x801912A0
    // 0x8018AF08: nop

    Title_ScreenFade_Update(rdram, ctx);
        goto after_10;
    // 0x8018AF08: nop

    after_10:
    // 0x8018AF0C: lui         $t4, 0x801C
    ctx->r12 = S32(0X801C << 16);
    // 0x8018AF10: lw          $t4, -0x7D4C($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7D4C);
    // 0x8018AF14: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018AF18: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8018AF1C: sw          $t5, -0x7D4C($at)
    MEM_W(-0X7D4C, ctx->r1) = ctx->r13;
L_8018AF20:
    // 0x8018AF20: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018AF24: lwc1        $f10, -0x7958($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X7958);
    // 0x8018AF28: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018AF2C: lwc1        $f16, -0x7954($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X7954);
    // 0x8018AF30: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018AF34: lwc1        $f18, -0x7950($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X7950);
    // 0x8018AF38: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x8018AF3C: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x8018AF40: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x8018AF44: addiu       $t8, $t8, 0x79C0
    ctx->r24 = ADD32(ctx->r24, 0X79C0);
    // 0x8018AF48: addiu       $t7, $t7, 0x79B8
    ctx->r15 = ADD32(ctx->r15, 0X79B8);
    // 0x8018AF4C: addiu       $t6, $t6, 0x79A0
    ctx->r14 = ADD32(ctx->r14, 0X79A0);
    // 0x8018AF50: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x8018AF54: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x8018AF58: lui         $a3, 0x8017
    ctx->r7 = S32(0X8017 << 16);
    // 0x8018AF5C: addiu       $a3, $a3, 0x7988
    ctx->r7 = ADD32(ctx->r7, 0X7988);
    // 0x8018AF60: addiu       $a2, $a2, 0x7980
    ctx->r6 = ADD32(ctx->r6, 0X7980);
    // 0x8018AF64: addiu       $a1, $a1, 0x7978
    ctx->r5 = ADD32(ctx->r5, 0X7978);
    // 0x8018AF68: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8018AF6C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8018AF70: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8018AF74: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8018AF78: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x8018AF7C: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    // 0x8018AF80: jal         0x80191320
    // 0x8018AF84: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    Title_SetCamUp3(rdram, ctx);
        goto after_11;
    // 0x8018AF84: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    after_11:
    // 0x8018AF88: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018AF8C: lwc1        $f12, -0x7938($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X7938);
    // 0x8018AF90: lui         $t9, 0x801C
    ctx->r25 = S32(0X801C << 16);
    // 0x8018AF94: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x8018AF98: addiu       $t0, $t0, -0x7D18
    ctx->r8 = ADD32(ctx->r8, -0X7D18);
    // 0x8018AF9C: addiu       $t9, $t9, -0x7D1C
    ctx->r25 = ADD32(ctx->r25, -0X7D1C);
    // 0x8018AFA0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018AFA4: lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // 0x8018AFA8: addiu       $a3, $a3, -0x7D20
    ctx->r7 = ADD32(ctx->r7, -0X7D20);
    // 0x8018AFAC: lwc1        $f14, -0x7934($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X7934);
    // 0x8018AFB0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8018AFB4: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8018AFB8: jal         0x80191674
    // 0x8018AFBC: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    Title_SetLightRot(rdram, ctx);
        goto after_12;
    // 0x8018AFBC: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    after_12:
    // 0x8018AFC0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018AFC4: lwc1        $f12, 0x7978($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X7978);
    // 0x8018AFC8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018AFCC: lwc1        $f14, 0x7980($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X7980);
    // 0x8018AFD0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018AFD4: lwc1        $f4, 0x79B8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X79B8);
    // 0x8018AFD8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018AFDC: lwc1        $f6, 0x79C0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X79C0);
    // 0x8018AFE0: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x8018AFE4: lui         $a3, 0x8017
    ctx->r7 = S32(0X8017 << 16);
    // 0x8018AFE8: lw          $a3, 0x79A0($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X79A0);
    // 0x8018AFEC: lw          $a2, 0x7988($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7988);
    // 0x8018AFF0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8018AFF4: jal         0x800B6F50
    // 0x8018AFF8: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    Camera_SetStarfieldPos(rdram, ctx);
        goto after_13;
    // 0x8018AFF8: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_13:
    // 0x8018AFFC: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8018B000: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x8018B004: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8018B008: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8018B00C: addiu       $v1, $v1, -0x7BD0
    ctx->r3 = ADD32(ctx->r3, -0X7BD0);
    // 0x8018B010: addiu       $v0, $v0, -0x7BD4
    ctx->r2 = ADD32(ctx->r2, -0X7BD4);
    // 0x8018B014: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8018B018: lwc1        $f16, 0x0($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8018B01C: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x8018B020: add.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x8018B024: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
    // 0x8018B028: swc1        $f18, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f18.u32l;
    // 0x8018B02C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8018B030: jr          $ra
    // 0x8018B034: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8018B034: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void Option_Score_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019DF64: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8019DF68: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8019DF6C: jal         0x8019752C
    // 0x8019DF70: nop

    Option_RankingMenu2_Draw(rdram, ctx);
        goto after_0;
    // 0x8019DF70: nop

    after_0:
    // 0x8019DF74: jal         0x8019BDF0
    // 0x8019DF78: nop

    Option_Menu_Push(rdram, ctx);
        goto after_1;
    // 0x8019DF78: nop

    after_1:
    // 0x8019DF7C: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8019DF80: addiu       $t6, $t6, -0x1870
    ctx->r14 = ADD32(ctx->r14, -0X1870);
    // 0x8019DF84: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x8019DF88: sw          $at, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r1;
    // 0x8019DF8C: lw          $t8, 0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X4);
    // 0x8019DF90: lw          $a0, 0x0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X0);
    // 0x8019DF94: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
    // 0x8019DF98: lw          $at, 0x8($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X8);
    // 0x8019DF9C: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x8019DFA0: sw          $at, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r1;
    // 0x8019DFA4: lw          $a3, 0xC($t6)
    ctx->r7 = MEM_W(ctx->r14, 0XC);
    // 0x8019DFA8: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x8019DFAC: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8019DFB0: lw          $at, 0x10($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X10);
    // 0x8019DFB4: jal         0x8019BAB8
    // 0x8019DFB8: sw          $at, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r1;
    Option_DrawMenuCard(rdram, ctx);
        goto after_2;
    // 0x8019DFB8: sw          $at, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r1;
    after_2:
    // 0x8019DFBC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8019DFC0: jal         0x80005740
    // 0x8019DFC4: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Pop(rdram, ctx);
        goto after_3;
    // 0x8019DFC4: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_3:
    // 0x8019DFC8: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x8019DFCC: addiu       $t9, $t9, -0x18A8
    ctx->r25 = ADD32(ctx->r25, -0X18A8);
    // 0x8019DFD0: addiu       $t1, $t9, 0x30
    ctx->r9 = ADD32(ctx->r25, 0X30);
    // 0x8019DFD4: or          $t2, $sp, $zero
    ctx->r10 = ctx->r29 | 0;
L_8019DFD8:
    // 0x8019DFD8: lw          $at, 0x0($t9)
    ctx->r1 = MEM_W(ctx->r25, 0X0);
    // 0x8019DFDC: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x8019DFE0: addiu       $t2, $t2, 0xC
    ctx->r10 = ADD32(ctx->r10, 0XC);
    // 0x8019DFE4: sw          $at, -0xC($t2)
    MEM_W(-0XC, ctx->r10) = ctx->r1;
    // 0x8019DFE8: lw          $at, -0x8($t9)
    ctx->r1 = MEM_W(ctx->r25, -0X8);
    // 0x8019DFEC: sw          $at, -0x8($t2)
    MEM_W(-0X8, ctx->r10) = ctx->r1;
    // 0x8019DFF0: lw          $at, -0x4($t9)
    ctx->r1 = MEM_W(ctx->r25, -0X4);
    // 0x8019DFF4: bne         $t9, $t1, L_8019DFD8
    if (ctx->r25 != ctx->r9) {
        // 0x8019DFF8: sw          $at, -0x4($t2)
        MEM_W(-0X4, ctx->r10) = ctx->r1;
            goto L_8019DFD8;
    }
    // 0x8019DFF8: sw          $at, -0x4($t2)
    MEM_W(-0X4, ctx->r10) = ctx->r1;
    // 0x8019DFFC: lw          $at, 0x0($t9)
    ctx->r1 = MEM_W(ctx->r25, 0X0);
    // 0x8019E000: sw          $at, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r1;
    // 0x8019E004: lw          $t1, 0x4($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X4);
    // 0x8019E008: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    // 0x8019E00C: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    // 0x8019E010: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x8019E014: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x8019E018: jal         0x8019C120
    // 0x8019E01C: lw          $a0, 0x0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X0);
    Option_DrawCardLabel(rdram, ctx);
        goto after_4;
    // 0x8019E01C: lw          $a0, 0x0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X0);
    after_4:
    // 0x8019E020: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8019E024: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8019E028: jr          $ra
    // 0x8019E02C: nop

    return;
    // 0x8019E02C: nop

;}
RECOMP_FUNC void Map_CamMatrixRot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801AD048: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801AD04C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801AD050: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801AD054: lwc1        $f4, -0x260C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X260C);
    // 0x801AD058: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801AD05C: lwc1        $f6, -0x2600($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2600);
    // 0x801AD060: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801AD064: lwc1        $f8, -0x2604($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2604);
    // 0x801AD068: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801AD06C: sub.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801AD070: lwc1        $f10, -0x25F8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X25F8);
    // 0x801AD074: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801AD078: lwc1        $f6, -0x2608($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2608);
    // 0x801AD07C: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x801AD080: mul.s       $f18, $f2, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x801AD084: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801AD088: lwc1        $f8, -0x25FC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X25FC);
    // 0x801AD08C: mul.s       $f4, $f16, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x801AD090: sub.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x801AD094: add.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x801AD098: jal         0x80005100
    // 0x801AD09C: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    Math_Atan2F(rdram, ctx);
        goto after_0;
    // 0x801AD09C: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    after_0:
    // 0x801AD0A0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801AD0A4: lwc1        $f18, -0x260C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X260C);
    // 0x801AD0A8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801AD0AC: lwc1        $f16, -0x2600($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X2600);
    // 0x801AD0B0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801AD0B4: lwc1        $f10, -0x2604($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2604);
    // 0x801AD0B8: sub.s       $f12, $f18, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x801AD0BC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801AD0C0: lwc1        $f16, -0x25F8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X25F8);
    // 0x801AD0C4: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x801AD0C8: jal         0x80005100
    // 0x801AD0CC: sub.s       $f14, $f10, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f16.fl;
    Math_Atan2F(rdram, ctx);
        goto after_1;
    // 0x801AD0CC: sub.s       $f14, $f10, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f16.fl;
    after_1:
    // 0x801AD0D0: neg.s       $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = -ctx->f0.fl;
    // 0x801AD0D4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801AD0D8: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x801AD0DC: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x801AD0E0: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x801AD0E4: jal         0x80005E90
    // 0x801AD0E8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateY(rdram, ctx);
        goto after_2;
    // 0x801AD0E8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x801AD0EC: lwc1        $f18, 0x1C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x801AD0F0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801AD0F4: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x801AD0F8: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x801AD0FC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801AD100: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x801AD104: jal         0x80005D44
    // 0x801AD108: nop

    Matrix_RotateX(rdram, ctx);
        goto after_3;
    // 0x801AD108: nop

    after_3:
    // 0x801AD10C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801AD110: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801AD114: jr          $ra
    // 0x801AD118: nop

    return;
    // 0x801AD118: nop

;}
RECOMP_FUNC void Title_CsTakeOffSpace_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018CB90: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8018CB94: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8018CB98: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8018CB9C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8018CBA0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8018CBA4: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x8018CBA8: lw          $t6, -0x7960($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7960);
    // 0x8018CBAC: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x8018CBB0: beql        $t6, $zero, L_8018CC1C
    if (ctx->r14 == 0) {
        // 0x8018CBB4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8018CC1C;
    }
    goto skip_0;
    // 0x8018CBB4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8018CBB8: lw          $t7, -0x796C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X796C);
    // 0x8018CBBC: lui         $at, 0xC47A
    ctx->r1 = S32(0XC47A << 16);
    // 0x8018CBC0: beq         $t7, $zero, L_8018CBD4
    if (ctx->r15 == 0) {
        // 0x8018CBC4: nop
    
            goto L_8018CBD4;
    }
    // 0x8018CBC4: nop

    // 0x8018CBC8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8018CBCC: jal         0x8018DF0C
    // 0x8018CBD0: nop

    Title_Corneria_Draw(rdram, ctx);
        goto after_0;
    // 0x8018CBD0: nop

    after_0:
L_8018CBD4:
    // 0x8018CBD4: jal         0x8018E058
    // 0x8018CBD8: nop

    Title_GreatFox_Draw(rdram, ctx);
        goto after_1;
    // 0x8018CBD8: nop

    after_1:
    // 0x8018CBDC: lui         $s1, 0x801C
    ctx->r17 = S32(0X801C << 16);
    // 0x8018CBE0: addiu       $s1, $s1, -0x7B18
    ctx->r17 = ADD32(ctx->r17, -0X7B18);
    // 0x8018CBE4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8018CBE8: addiu       $s2, $zero, 0x4
    ctx->r18 = ADD32(0, 0X4);
L_8018CBEC:
    // 0x8018CBEC: lw          $t8, 0x38($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X38);
    // 0x8018CBF0: bgtzl       $t8, L_8018CC10
    if (SIGNED(ctx->r24) > 0) {
        // 0x8018CBF4: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8018CC10;
    }
    goto skip_1;
    // 0x8018CBF4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_1:
    // 0x8018CBF8: lw          $t9, 0x4C($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X4C);
    // 0x8018CBFC: beql        $t9, $zero, L_8018CC10
    if (ctx->r25 == 0) {
        // 0x8018CC00: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8018CC10;
    }
    goto skip_2;
    // 0x8018CC00: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_2:
    // 0x8018CC04: jal         0x8018D2B8
    // 0x8018CC08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Title_Arwing_Draw(rdram, ctx);
        goto after_2;
    // 0x8018CC08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8018CC0C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8018CC10:
    // 0x8018CC10: bne         $s0, $s2, L_8018CBEC
    if (ctx->r16 != ctx->r18) {
        // 0x8018CC14: addiu       $s1, $s1, 0x5C
        ctx->r17 = ADD32(ctx->r17, 0X5C);
            goto L_8018CBEC;
    }
    // 0x8018CC14: addiu       $s1, $s1, 0x5C
    ctx->r17 = ADD32(ctx->r17, 0X5C);
    // 0x8018CC18: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8018CC1C:
    // 0x8018CC1C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8018CC20: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8018CC24: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8018CC28: jr          $ra
    // 0x8018CC2C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8018CC2C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void Option_Training_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80192938: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8019293C: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x80192940: addiu       $v1, $v1, -0x7CC0
    ctx->r3 = ADD32(ctx->r3, -0X7CC0);
    // 0x80192944: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80192948: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8019294C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80192950: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x80192954: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80192958: bne         $a0, $v0, L_801929D0
    if (ctx->r4 != ctx->r2) {
        // 0x8019295C: addiu       $t1, $v0, 0x20
        ctx->r9 = ADD32(ctx->r2, 0X20);
            goto L_801929D0;
    }
    // 0x8019295C: addiu       $t1, $v0, 0x20
    ctx->r9 = ADD32(ctx->r2, 0X20);
    // 0x80192960: sw          $t6, -0x7DCC($at)
    MEM_W(-0X7DCC, ctx->r1) = ctx->r14;
    // 0x80192964: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80192968: addiu       $t7, $zero, 0x7
    ctx->r15 = ADD32(0, 0X7);
    // 0x8019296C: sw          $t7, 0x7834($at)
    MEM_W(0X7834, ctx->r1) = ctx->r15;
    // 0x80192970: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80192974: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80192978: sw          $t8, 0x783C($at)
    MEM_W(0X783C, ctx->r1) = ctx->r24;
    // 0x8019297C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80192980: sw          $zero, 0x7854($at)
    MEM_W(0X7854, ctx->r1) = 0;
    // 0x80192984: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80192988: jal         0x800A5844
    // 0x8019298C: sw          $zero, 0x7898($at)
    MEM_W(0X7898, ctx->r1) = 0;
    Play_Setup(rdram, ctx);
        goto after_0;
    // 0x8019298C: sw          $zero, 0x7898($at)
    MEM_W(0X7898, ctx->r1) = 0;
    after_0:
    // 0x80192990: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80192994: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80192998: sw          $zero, 0x7CA0($at)
    MEM_W(0X7CA0, ctx->r1) = 0;
    // 0x8019299C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801929A0: swc1        $f4, 0x7CB0($at)
    MEM_W(0X7CB0, ctx->r1) = ctx->f4.u32l;
    // 0x801929A4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801929A8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801929AC: sw          $t9, 0x782C($at)
    MEM_W(0X782C, ctx->r1) = ctx->r25;
    // 0x801929B0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x801929B4: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x801929B8: sw          $t0, -0x274C($at)
    MEM_W(-0X274C, ctx->r1) = ctx->r8;
    // 0x801929BC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801929C0: jal         0x8001DC6C
    // 0x801929C4: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    Audio_SetAudioSpec(rdram, ctx);
        goto after_1;
    // 0x801929C4: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    after_1:
    // 0x801929C8: b           L_801929E4
    // 0x801929CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801929E4;
    // 0x801929CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801929D0:
    // 0x801929D0: slti        $at, $t1, 0x100
    ctx->r1 = SIGNED(ctx->r9) < 0X100 ? 1 : 0;
    // 0x801929D4: bne         $at, $zero, L_801929E0
    if (ctx->r1 != 0) {
        // 0x801929D8: sw          $t1, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r9;
            goto L_801929E0;
    }
    // 0x801929D8: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x801929DC: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
L_801929E0:
    // 0x801929E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801929E4:
    // 0x801929E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801929E8: jr          $ra
    // 0x801929EC: nop

    return;
    // 0x801929EC: nop

;}
RECOMP_FUNC void Option_Data_Select(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019669C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801966A0: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801966A4: addiu       $v1, $v1, -0x6E34
    ctx->r3 = ADD32(ctx->r3, -0X6E34);
    // 0x801966A8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801966AC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801966B0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801966B4: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801966B8: beq         $v0, $zero, L_801966C8
    if (ctx->r2 == 0) {
        // 0x801966BC: nop
    
            goto L_801966C8;
    }
    // 0x801966BC: nop

    // 0x801966C0: bne         $v0, $at, L_8019670C
    if (ctx->r2 != ctx->r1) {
        // 0x801966C4: nop
    
            goto L_8019670C;
    }
    // 0x801966C4: nop

L_801966C8:
    // 0x801966C8: jal         0x8019C5A0
    // 0x801966CC: addiu       $a0, $a0, -0x6E40
    ctx->r4 = ADD32(ctx->r4, -0X6E40);
    Option_Input_DataSelect_X(rdram, ctx);
        goto after_0;
    // 0x801966CC: addiu       $a0, $a0, -0x6E40
    ctx->r4 = ADD32(ctx->r4, -0X6E40);
    after_0:
    // 0x801966D0: beq         $v0, $zero, L_80196704
    if (ctx->r2 == 0) {
        // 0x801966D4: lui         $a1, 0x800C
        ctx->r5 = S32(0X800C << 16);
            goto L_80196704;
    }
    // 0x801966D4: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x801966D8: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x801966DC: lui         $t0, 0x800C
    ctx->r8 = S32(0X800C << 16);
    // 0x801966E0: addiu       $t0, $t0, 0x5D3C
    ctx->r8 = ADD32(ctx->r8, 0X5D3C);
    // 0x801966E4: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x801966E8: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x801966EC: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x801966F0: ori         $a0, $a0, 0x2
    ctx->r4 = ctx->r4 | 0X2;
    // 0x801966F4: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x801966F8: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x801966FC: jal         0x80019218
    // 0x80196700: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_1;
    // 0x80196700: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_1:
L_80196704:
    // 0x80196704: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80196708: addiu       $v1, $v1, -0x6E34
    ctx->r3 = ADD32(ctx->r3, -0X6E34);
L_8019670C:
    // 0x8019670C: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x80196710: lw          $t6, 0x7AF8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7AF8);
    // 0x80196714: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80196718: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x8019671C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80196720: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80196724: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x80196728: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x8019672C: lhu         $v0, -0x2768($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X2768);
    // 0x80196730: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80196734: lui         $t0, 0x800C
    ctx->r8 = S32(0X800C << 16);
    // 0x80196738: andi        $t8, $v0, 0x8000
    ctx->r24 = ctx->r2 & 0X8000;
    // 0x8019673C: addiu       $t0, $t0, 0x5D3C
    ctx->r8 = ADD32(ctx->r8, 0X5D3C);
    // 0x80196740: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80196744: beq         $t8, $zero, L_80196820
    if (ctx->r24 == 0) {
        // 0x80196748: addiu       $a1, $a1, 0x5D28
        ctx->r5 = ADD32(ctx->r5, 0X5D28);
            goto L_80196820;
    }
    // 0x80196748: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x8019674C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80196750: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80196754: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x80196758: bne         $v0, $at, L_80196784
    if (ctx->r2 != ctx->r1) {
        // 0x8019675C: lui         $v1, 0x801C
        ctx->r3 = S32(0X801C << 16);
            goto L_80196784;
    }
    // 0x8019675C: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80196760: ori         $a0, $a0, 0x21
    ctx->r4 = ctx->r4 | 0X21;
    // 0x80196764: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80196768: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8019676C: jal         0x80019218
    // 0x80196770: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    Audio_PlaySfx(rdram, ctx);
        goto after_2;
    // 0x80196770: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    after_2:
    // 0x80196774: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x80196778: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019677C: b           L_80196884
    // 0x80196780: sw          $t9, -0x6ED4($at)
    MEM_W(-0X6ED4, ctx->r1) = ctx->r25;
        goto L_80196884;
    // 0x80196780: sw          $t9, -0x6ED4($at)
    MEM_W(-0X6ED4, ctx->r1) = ctx->r25;
L_80196784:
    // 0x80196784: lw          $v1, -0x6E40($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X6E40);
    // 0x80196788: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019678C: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x80196790: sll         $t2, $v1, 2
    ctx->r10 = S32(ctx->r3 << 2);
    // 0x80196794: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x80196798: bne         $v1, $zero, L_801967F8
    if (ctx->r3 != 0) {
        // 0x8019679C: sw          $t1, -0x6CD0($at)
        MEM_W(-0X6CD0, ctx->r1) = ctx->r9;
            goto L_801967F8;
    }
    // 0x8019679C: sw          $t1, -0x6CD0($at)
    MEM_W(-0X6CD0, ctx->r1) = ctx->r9;
    // 0x801967A0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801967A4: bne         $v0, $at, L_801967D4
    if (ctx->r2 != ctx->r1) {
        // 0x801967A8: lui         $a0, 0x4900
        ctx->r4 = S32(0X4900 << 16);
            goto L_801967D4;
    }
    // 0x801967A8: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x801967AC: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x801967B0: ori         $a0, $a0, 0x3
    ctx->r4 = ctx->r4 | 0X3;
    // 0x801967B4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x801967B8: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x801967BC: jal         0x80019218
    // 0x801967C0: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    Audio_PlaySfx(rdram, ctx);
        goto after_3;
    // 0x801967C0: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    after_3:
    // 0x801967C4: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x801967C8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801967CC: b           L_80196884
    // 0x801967D0: sw          $t3, -0x6ED4($at)
    MEM_W(-0X6ED4, ctx->r1) = ctx->r11;
        goto L_80196884;
    // 0x801967D0: sw          $t3, -0x6ED4($at)
    MEM_W(-0X6ED4, ctx->r1) = ctx->r11;
L_801967D4:
    // 0x801967D4: ori         $a0, $a0, 0x21
    ctx->r4 = ctx->r4 | 0X21;
    // 0x801967D8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x801967DC: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x801967E0: jal         0x80019218
    // 0x801967E4: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    Audio_PlaySfx(rdram, ctx);
        goto after_4;
    // 0x801967E4: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    after_4:
    // 0x801967E8: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x801967EC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801967F0: b           L_80196884
    // 0x801967F4: sw          $t4, -0x6ED4($at)
    MEM_W(-0X6ED4, ctx->r1) = ctx->r12;
        goto L_80196884;
    // 0x801967F4: sw          $t4, -0x6ED4($at)
    MEM_W(-0X6ED4, ctx->r1) = ctx->r12;
L_801967F8:
    // 0x801967F8: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x801967FC: ori         $a0, $a0, 0x3
    ctx->r4 = ctx->r4 | 0X3;
    // 0x80196800: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80196804: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80196808: jal         0x80019218
    // 0x8019680C: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    Audio_PlaySfx(rdram, ctx);
        goto after_5;
    // 0x8019680C: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    after_5:
    // 0x80196810: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x80196814: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80196818: b           L_80196884
    // 0x8019681C: sw          $t5, -0x6ED4($at)
    MEM_W(-0X6ED4, ctx->r1) = ctx->r13;
        goto L_80196884;
    // 0x8019681C: sw          $t5, -0x6ED4($at)
    MEM_W(-0X6ED4, ctx->r1) = ctx->r13;
L_80196820:
    // 0x80196820: andi        $t6, $v0, 0x4000
    ctx->r14 = ctx->r2 & 0X4000;
    // 0x80196824: beql        $t6, $zero, L_80196888
    if (ctx->r14 == 0) {
        // 0x80196828: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80196888;
    }
    goto skip_0;
    // 0x80196828: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8019682C: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80196830: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80196834: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x80196838: bne         $t7, $at, L_80196868
    if (ctx->r15 != ctx->r1) {
        // 0x8019683C: ori         $a0, $a0, 0x21
        ctx->r4 = ctx->r4 | 0X21;
            goto L_80196868;
    }
    // 0x8019683C: ori         $a0, $a0, 0x21
    ctx->r4 = ctx->r4 | 0X21;
    // 0x80196840: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x80196844: ori         $a0, $a0, 0x101D
    ctx->r4 = ctx->r4 | 0X101D;
    // 0x80196848: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8019684C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80196850: jal         0x80019218
    // 0x80196854: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    Audio_PlaySfx(rdram, ctx);
        goto after_6;
    // 0x80196854: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    after_6:
    // 0x80196858: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8019685C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80196860: b           L_80196884
    // 0x80196864: sw          $t8, -0x6ED4($at)
    MEM_W(-0X6ED4, ctx->r1) = ctx->r24;
        goto L_80196884;
    // 0x80196864: sw          $t8, -0x6ED4($at)
    MEM_W(-0X6ED4, ctx->r1) = ctx->r24;
L_80196868:
    // 0x80196868: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8019686C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80196870: jal         0x80019218
    // 0x80196874: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    Audio_PlaySfx(rdram, ctx);
        goto after_7;
    // 0x80196874: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    after_7:
    // 0x80196878: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x8019687C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80196880: sw          $t9, -0x6ED4($at)
    MEM_W(-0X6ED4, ctx->r1) = ctx->r25;
L_80196884:
    // 0x80196884: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80196888:
    // 0x80196888: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8019688C: jr          $ra
    // 0x80196890: nop

    return;
    // 0x80196890: nop

;}
RECOMP_FUNC void Map_TeamStatus_Refill(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019F910: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x8019F914: lw          $t6, 0x7B48($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7B48);
    // 0x8019F918: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x8019F91C: addiu       $t8, $t8, 0x7B50
    ctx->r24 = ADD32(ctx->r24, 0X7B50);
    // 0x8019F920: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8019F924: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8019F928: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8019F92C: lui         $v0, 0xFF
    ctx->r2 = S32(0XFF << 16);
    // 0x8019F930: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    // 0x8019F934: addiu       $v1, $v1, 0x78B0
    ctx->r3 = ADD32(ctx->r3, 0X78B0);
    // 0x8019F938: addiu       $a0, $a0, 0x78BC
    ctx->r4 = ADD32(ctx->r4, 0X78BC);
L_8019F93C:
    // 0x8019F93C: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x8019F940: addiu       $a0, $a0, -0x4
    ctx->r4 = ADD32(ctx->r4, -0X4);
    // 0x8019F944: sra         $t4, $v0, 8
    ctx->r12 = S32(SIGNED(ctx->r2) >> 8);
    // 0x8019F948: bgtzl       $t9, L_8019F964
    if (SIGNED(ctx->r25) > 0) {
        // 0x8019F94C: lw          $t2, 0x0($a1)
        ctx->r10 = MEM_W(ctx->r5, 0X0);
            goto L_8019F964;
    }
    goto skip_0;
    // 0x8019F94C: lw          $t2, 0x0($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X0);
    skip_0:
    // 0x8019F950: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
    // 0x8019F954: xor         $t1, $t0, $v0
    ctx->r9 = ctx->r8 ^ ctx->r2;
    // 0x8019F958: b           L_8019F96C
    // 0x8019F95C: sw          $t1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r9;
        goto L_8019F96C;
    // 0x8019F95C: sw          $t1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r9;
    // 0x8019F960: lw          $t2, 0x0($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X0);
L_8019F964:
    // 0x8019F964: or          $t3, $t2, $v0
    ctx->r11 = ctx->r10 | ctx->r2;
    // 0x8019F968: sw          $t3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r11;
L_8019F96C:
    // 0x8019F96C: bne         $v1, $a0, L_8019F93C
    if (ctx->r3 != ctx->r4) {
        // 0x8019F970: or          $v0, $t4, $zero
        ctx->r2 = ctx->r12 | 0;
            goto L_8019F93C;
    }
    // 0x8019F970: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    // 0x8019F974: jr          $ra
    // 0x8019F978: nop

    return;
    // 0x8019F978: nop

;}
RECOMP_FUNC void Option_Score_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019DD44: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8019DD48: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8019DD4C: addiu       $a0, $a0, -0x6ED4
    ctx->r4 = ADD32(ctx->r4, -0X6ED4);
    // 0x8019DD50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8019DD54: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8019DD58: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8019DD5C: beq         $v0, $zero, L_8019DD74
    if (ctx->r2 == 0) {
        // 0x8019DD60: nop
    
            goto L_8019DD74;
    }
    // 0x8019DD60: nop

    // 0x8019DD64: beq         $v0, $a1, L_8019DE5C
    if (ctx->r2 == ctx->r5) {
        // 0x8019DD68: nop
    
            goto L_8019DE5C;
    }
    // 0x8019DD68: nop

    // 0x8019DD6C: b           L_8019DE68
    // 0x8019DD70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8019DE68;
    // 0x8019DD70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8019DD74:
    // 0x8019DD74: jal         0x80196E54
    // 0x8019DD78: nop

    Option_Ranking_Setup(rdram, ctx);
        goto after_0;
    // 0x8019DD78: nop

    after_0:
    // 0x8019DD7C: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8019DD80: lw          $v0, -0x6F6C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6F6C);
    // 0x8019DD84: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8019DD88: addiu       $v1, $v1, -0x6C1C
    ctx->r3 = ADD32(ctx->r3, -0X6C1C);
    // 0x8019DD8C: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8019DD90: addiu       $a0, $a0, -0x6ED4
    ctx->r4 = ADD32(ctx->r4, -0X6ED4);
    // 0x8019DD94: bltz        $v0, L_8019DDA8
    if (SIGNED(ctx->r2) < 0) {
        // 0x8019DD98: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_8019DDA8;
    }
    // 0x8019DD98: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8019DD9C: slti        $at, $v0, 0xA
    ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // 0x8019DDA0: bnel        $at, $zero, L_8019DDB0
    if (ctx->r1 != 0) {
        // 0x8019DDA4: lw          $t6, 0x0($v1)
        ctx->r14 = MEM_W(ctx->r3, 0X0);
            goto L_8019DDB0;
    }
    goto skip_0;
    // 0x8019DDA4: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    skip_0:
L_8019DDA8:
    // 0x8019DDA8: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x8019DDAC: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
L_8019DDB0:
    // 0x8019DDB0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8019DDB4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8019DDB8: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8019DDBC: lui         $at, 0x4302
    ctx->r1 = S32(0X4302 << 16);
    // 0x8019DDC0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8019DDC4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8019DDC8: lui         $at, 0x42E4
    ctx->r1 = S32(0X42E4 << 16);
    // 0x8019DDCC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8019DDD0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019DDD4: lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // 0x8019DDD8: addiu       $v0, $v0, -0x19C8
    ctx->r2 = ADD32(ctx->r2, -0X19C8);
    // 0x8019DDDC: mul.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8019DDE0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8019DDE4: sub.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x8019DDE8: swc1        $f16, -0x6E2C($at)
    MEM_W(-0X6E2C, ctx->r1) = ctx->f16.u32l;
    // 0x8019DDEC: lui         $at, 0xC0C0
    ctx->r1 = S32(0XC0C0 << 16);
    // 0x8019DDF0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8019DDF4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019DDF8: add.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f18.fl;
    // 0x8019DDFC: swc1        $f4, -0x6E28($at)
    MEM_W(-0X6E28, ctx->r1) = ctx->f4.u32l;
    // 0x8019DE00: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8019DE04: lwc1        $f6, -0x1A3C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X1A3C);
    // 0x8019DE08: lui         $at, 0x41B8
    ctx->r1 = S32(0X41B8 << 16);
    // 0x8019DE0C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8019DE10: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8019DE14: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8019DE18: sw          $a1, 0x178($v0)
    MEM_W(0X178, ctx->r2) = ctx->r5;
    // 0x8019DE1C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8019DE20: swc1        $f2, 0x140($v0)
    MEM_W(0X140, ctx->r2) = ctx->f2.u32l;
    // 0x8019DE24: swc1        $f2, 0x144($v0)
    MEM_W(0X144, ctx->r2) = ctx->f2.u32l;
    // 0x8019DE28: swc1        $f6, 0x138($v0)
    MEM_W(0X138, ctx->r2) = ctx->f6.u32l;
    // 0x8019DE2C: swc1        $f8, 0x13C($v0)
    MEM_W(0X13C, ctx->r2) = ctx->f8.u32l;
    // 0x8019DE30: swc1        $f10, 0x15C($v0)
    MEM_W(0X15C, ctx->r2) = ctx->f10.u32l;
    // 0x8019DE34: lwc1        $f16, 0x74B0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X74B0);
    // 0x8019DE38: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8019DE3C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8019DE40: swc1        $f16, 0x164($v0)
    MEM_W(0X164, ctx->r2) = ctx->f16.u32l;
    // 0x8019DE44: lwc1        $f18, 0x74B4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X74B4);
    // 0x8019DE48: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8019DE4C: sw          $a1, 0x17C($v0)
    MEM_W(0X17C, ctx->r2) = ctx->r5;
    // 0x8019DE50: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8019DE54: b           L_8019DE64
    // 0x8019DE58: swc1        $f18, 0x168($v0)
    MEM_W(0X168, ctx->r2) = ctx->f18.u32l;
        goto L_8019DE64;
    // 0x8019DE58: swc1        $f18, 0x168($v0)
    MEM_W(0X168, ctx->r2) = ctx->f18.u32l;
L_8019DE5C:
    // 0x8019DE5C: jal         0x8019DE74
    // 0x8019DE60: nop

    Option_Score_Update2(rdram, ctx);
        goto after_1;
    // 0x8019DE60: nop

    after_1:
L_8019DE64:
    // 0x8019DE64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8019DE68:
    // 0x8019DE68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8019DE6C: jr          $ra
    // 0x8019DE70: nop

    return;
    // 0x8019DE70: nop

;}
RECOMP_FUNC void Option_RankingMenu_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801973C0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801973C4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x801973C8: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x801973CC: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x801973D0: lw          $t6, -0x6C20($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6C20);
    // 0x801973D4: beq         $t6, $zero, L_801973F0
    if (ctx->r14 == 0) {
        // 0x801973D8: nop
    
            goto L_801973F0;
    }
    // 0x801973D8: nop

    // 0x801973DC: jal         0x8019752C
    // 0x801973E0: nop

    Option_RankingMenu2_Draw(rdram, ctx);
        goto after_0;
    // 0x801973E0: nop

    after_0:
    // 0x801973E4: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x801973E8: b           L_801974C4
    // 0x801973EC: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
        goto L_801974C4;
    // 0x801973EC: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
L_801973F0:
    // 0x801973F0: jal         0x80187E28
    // 0x801973F4: nop

    Title_RankingData_Draw(rdram, ctx);
        goto after_1;
    // 0x801973F4: nop

    after_1:
    // 0x801973F8: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x801973FC: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x80197400: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80197404: jal         0x800B8DD0
    // 0x80197408: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    RCP_SetupDL(rdram, ctx);
        goto after_2;
    // 0x80197408: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    after_2:
    // 0x8019740C: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80197410: jal         0x8019C824
    // 0x80197414: addiu       $a0, $a0, -0x6C10
    ctx->r4 = ADD32(ctx->r4, -0X6C10);
    Option_Color_FlashRed(rdram, ctx);
        goto after_3;
    // 0x80197414: addiu       $a0, $a0, -0x6C10
    ctx->r4 = ADD32(ctx->r4, -0X6C10);
    after_3:
    // 0x80197418: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019741C: lwc1        $f4, -0x6C10($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6C10);
    // 0x80197420: lui         $at, 0xFF00
    ctx->r1 = S32(0XFF00 << 16);
    // 0x80197424: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x80197428: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8019742C: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x80197430: mfc1        $t1, $f6
    ctx->r9 = (int32_t)ctx->f6.u32l;
    // 0x80197434: nop

    // 0x80197438: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8019743C: andi        $t0, $t1, 0xFF
    ctx->r8 = ctx->r9 & 0XFF;
    // 0x80197440: sll         $t2, $t0, 16
    ctx->r10 = S32(ctx->r8 << 16);
    // 0x80197444: or          $t3, $t2, $at
    ctx->r11 = ctx->r10 | ctx->r1;
    // 0x80197448: sll         $t4, $t0, 8
    ctx->r12 = S32(ctx->r8 << 8);
    // 0x8019744C: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80197450: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80197454: or          $t5, $t3, $t4
    ctx->r13 = ctx->r11 | ctx->r12;
    // 0x80197458: ori         $t6, $t5, 0xFF
    ctx->r14 = ctx->r13 | 0XFF;
    // 0x8019745C: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x80197460: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80197464: lw          $t7, -0x6C1C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X6C1C);
    // 0x80197468: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x8019746C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80197470: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x80197474: lui         $at, 0x4188
    ctx->r1 = S32(0X4188 << 16);
    // 0x80197478: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8019747C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80197480: lui         $at, 0x425C
    ctx->r1 = S32(0X425C << 16);
    // 0x80197484: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80197488: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8019748C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x80197490: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80197494: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80197498: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8019749C: lui         $a1, 0x700
    ctx->r5 = S32(0X700 << 16);
    // 0x801974A0: addiu       $a1, $a1, 0x4010
    ctx->r5 = ADD32(ctx->r5, 0X4010);
    // 0x801974A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801974A8: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x801974AC: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    // 0x801974B0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801974B4: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x801974B8: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    // 0x801974BC: jal         0x8009D994
    // 0x801974C0: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_4;
    // 0x801974C0: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_4:
L_801974C4:
    // 0x801974C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801974C8: jal         0x800B8DD0
    // 0x801974CC: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    RCP_SetupDL(rdram, ctx);
        goto after_5;
    // 0x801974CC: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    after_5:
    // 0x801974D0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801974D4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801974D8: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x801974DC: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x801974E0: lui         $t2, 0xFFFF
    ctx->r10 = S32(0XFFFF << 16);
    // 0x801974E4: ori         $t2, $t2, 0xFF
    ctx->r10 = ctx->r10 | 0XFF;
    // 0x801974E8: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x801974EC: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x801974F0: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x801974F4: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x801974F8: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x801974FC: addiu       $t3, $t3, 0x715C
    ctx->r11 = ADD32(ctx->r11, 0X715C);
    // 0x80197500: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80197504: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80197508: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8019750C: addiu       $a0, $zero, 0xF2
    ctx->r4 = ADD32(0, 0XF2);
    // 0x80197510: jal         0x800A1200
    // 0x80197514: addiu       $a1, $zero, 0xD7
    ctx->r5 = ADD32(0, 0XD7);
    Graphics_DisplaySmallText(rdram, ctx);
        goto after_6;
    // 0x80197514: addiu       $a1, $zero, 0xD7
    ctx->r5 = ADD32(0, 0XD7);
    after_6:
    // 0x80197518: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8019751C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80197520: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80197524: jr          $ra
    // 0x80197528: nop

    return;
    // 0x80197528: nop

;}
RECOMP_FUNC void Option_VS_HandicapSet_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80199820: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x80199824: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x80199828: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x8019982C: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x80199830: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80199834: addiu       $s2, $s2, 0x7E64
    ctx->r18 = ADD32(ctx->r18, 0X7E64);
    // 0x80199838: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x8019983C: sw          $fp, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r30;
    // 0x80199840: sw          $s7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r23;
    // 0x80199844: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x80199848: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x8019984C: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x80199850: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x80199854: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x80199858: sdc1        $f22, 0x38($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X38, ctx->r29);
    // 0x8019985C: sdc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X30, ctx->r29);
    // 0x80199860: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80199864: jal         0x800B8DD0
    // 0x80199868: addiu       $a1, $zero, 0x55
    ctx->r5 = ADD32(0, 0X55);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x80199868: addiu       $a1, $zero, 0x55
    ctx->r5 = ADD32(0, 0X55);
    after_0:
    // 0x8019986C: addiu       $s5, $zero, -0x1
    ctx->r21 = ADD32(0, -0X1);
    // 0x80199870: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80199874: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x80199878: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8019987C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80199880: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
    // 0x80199884: sw          $s5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r21;
    // 0x80199888: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8019988C: sll         $t0, $s3, 2
    ctx->r8 = S32(ctx->r19 << 2);
    // 0x80199890: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x80199894: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80199898: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8019989C: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x801998A0: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x801998A4: addiu       $t9, $t9, -0xEA8
    ctx->r25 = ADD32(ctx->r25, -0XEA8);
    // 0x801998A8: addiu       $t8, $t8, -0xEB8
    ctx->r24 = ADD32(ctx->r24, -0XEB8);
    // 0x801998AC: lui         $s3, 0x701
    ctx->r19 = S32(0X701 << 16);
    // 0x801998B0: lui         $s4, 0x701
    ctx->r20 = S32(0X701 << 16);
    // 0x801998B4: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x801998B8: addiu       $s4, $s4, 0x18E0
    ctx->r20 = ADD32(ctx->r20, 0X18E0);
    // 0x801998BC: addiu       $s3, $s3, 0x23F8
    ctx->r19 = ADD32(ctx->r19, 0X23F8);
    // 0x801998C0: addu        $s7, $t0, $t8
    ctx->r23 = ADD32(ctx->r8, ctx->r24);
    // 0x801998C4: addu        $fp, $t0, $t9
    ctx->r30 = ADD32(ctx->r8, ctx->r25);
    // 0x801998C8: sw          $t0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r8;
    // 0x801998CC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_801998D0:
    // 0x801998D0: mtc1        $s0, $f8
    ctx->f8.u32l = ctx->r16;
    // 0x801998D4: lwc1        $f6, 0x0($fp)
    ctx->f6.u32l = MEM_W(ctx->r30, 0X0);
    // 0x801998D8: lwc1        $f4, 0x0($s7)
    ctx->f4.u32l = MEM_W(ctx->r23, 0X0);
    // 0x801998DC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801998E0: addiu       $t5, $zero, 0x10
    ctx->r13 = ADD32(0, 0X10);
    // 0x801998E4: lw          $t0, 0x7C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X7C);
    // 0x801998E8: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x801998EC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x801998F0: bgez        $s1, L_80199900
    if (SIGNED(ctx->r17) >= 0) {
        // 0x801998F4: sra         $t4, $s1, 1
        ctx->r12 = S32(SIGNED(ctx->r17) >> 1);
            goto L_80199900;
    }
    // 0x801998F4: sra         $t4, $s1, 1
    ctx->r12 = S32(SIGNED(ctx->r17) >> 1);
    // 0x801998F8: addiu       $at, $s1, 0x1
    ctx->r1 = ADD32(ctx->r17, 0X1);
    // 0x801998FC: sra         $t4, $at, 1
    ctx->r12 = S32(SIGNED(ctx->r1) >> 1);
L_80199900:
    // 0x80199900: mul.s       $f16, $f22, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f22.fl, ctx->f10.fl);
    // 0x80199904: addu        $a1, $s4, $t4
    ctx->r5 = ADD32(ctx->r20, ctx->r12);
    // 0x80199908: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x8019990C: addiu       $a3, $zero, 0x50
    ctx->r7 = ADD32(0, 0X50);
    // 0x80199910: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80199914: swc1        $f20, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f20.u32l;
    // 0x80199918: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x8019991C: add.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x80199920: jal         0x8009C320
    // 0x80199924: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    Lib_TextureRect_CI4(rdram, ctx);
        goto after_1;
    // 0x80199924: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    after_1:
    // 0x80199928: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8019992C: slti        $at, $s0, 0x4
    ctx->r1 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x80199930: bne         $at, $zero, L_801998D0
    if (ctx->r1 != 0) {
        // 0x80199934: addiu       $s1, $s1, 0x500
        ctx->r17 = ADD32(ctx->r17, 0X500);
            goto L_801998D0;
    }
    // 0x80199934: addiu       $s1, $s1, 0x500
    ctx->r17 = ADD32(ctx->r17, 0X500);
    // 0x80199938: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x8019993C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80199940: lwc1        $f8, 0x0($fp)
    ctx->f8.u32l = MEM_W(ctx->r30, 0X0);
    // 0x80199944: lwc1        $f4, 0x0($s7)
    ctx->f4.u32l = MEM_W(ctx->r23, 0X0);
    // 0x80199948: lui         $a1, 0x701
    ctx->r5 = S32(0X701 << 16);
    // 0x8019994C: add.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80199950: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
    // 0x80199954: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80199958: addiu       $a1, $a1, 0x22E0
    ctx->r5 = ADD32(ctx->r5, 0X22E0);
    // 0x8019995C: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x80199960: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80199964: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80199968: addiu       $a3, $zero, 0x50
    ctx->r7 = ADD32(0, 0X50);
    // 0x8019996C: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80199970: swc1        $f20, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f20.u32l;
    // 0x80199974: jal         0x8009C320
    // 0x80199978: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    Lib_TextureRect_CI4(rdram, ctx);
        goto after_2;
    // 0x80199978: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x8019997C: lw          $t0, 0x7C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X7C);
    // 0x80199980: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80199984: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x80199988: addiu       $t9, $t9, -0xDB4
    ctx->r25 = ADD32(ctx->r25, -0XDB4);
    // 0x8019998C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80199990: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    // 0x80199994: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x80199998: addu        $t1, $t0, $t9
    ctx->r9 = ADD32(ctx->r8, ctx->r25);
    // 0x8019999C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x801999A0: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x801999A4: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x801999A8: addiu       $t4, $t4, -0xDD4
    ctx->r12 = ADD32(ctx->r12, -0XDD4);
    // 0x801999AC: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x801999B0: addiu       $t5, $t5, -0xDC4
    ctx->r13 = ADD32(ctx->r13, -0XDC4);
    // 0x801999B4: addu        $t2, $t0, $t4
    ctx->r10 = ADD32(ctx->r8, ctx->r12);
    // 0x801999B8: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x801999BC: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x801999C0: sll         $t8, $t7, 8
    ctx->r24 = S32(ctx->r15 << 8);
    // 0x801999C4: addu        $t3, $t0, $t5
    ctx->r11 = ADD32(ctx->r8, ctx->r13);
    // 0x801999C8: lw          $t7, 0x0($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X0);
    // 0x801999CC: sll         $t5, $t4, 24
    ctx->r13 = S32(ctx->r12 << 24);
    // 0x801999D0: or          $t6, $t8, $t5
    ctx->r14 = ctx->r24 | ctx->r13;
    // 0x801999D4: andi        $t9, $t7, 0xFF
    ctx->r25 = ctx->r15 & 0XFF;
    // 0x801999D8: sll         $t4, $t9, 16
    ctx->r12 = S32(ctx->r25 << 16);
    // 0x801999DC: or          $t8, $t6, $t4
    ctx->r24 = ctx->r14 | ctx->r12;
    // 0x801999E0: ori         $t5, $t8, 0xFF
    ctx->r13 = ctx->r24 | 0XFF;
    // 0x801999E4: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x801999E8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801999EC: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x801999F0: lwc1        $f16, -0xE78($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0XE78);
    // 0x801999F4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801999F8: lwc1        $f10, -0xE68($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0XE68);
    // 0x801999FC: lwc1        $f18, 0x0($s7)
    ctx->f18.u32l = MEM_W(ctx->r23, 0X0);
    // 0x80199A00: lwc1        $f8, 0x0($fp)
    ctx->f8.u32l = MEM_W(ctx->r30, 0X0);
    // 0x80199A04: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x80199A08: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80199A0C: addu        $t7, $t7, $t0
    ctx->r15 = ADD32(ctx->r15, ctx->r8);
    // 0x80199A10: lw          $t7, -0xE88($t7)
    ctx->r15 = MEM_W(ctx->r15, -0XE88);
    // 0x80199A14: add.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80199A18: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x80199A1C: lui         $a2, 0x801B
    ctx->r6 = S32(0X801B << 16);
    // 0x80199A20: lui         $a3, 0x801B
    ctx->r7 = S32(0X801B << 16);
    // 0x80199A24: addu        $a3, $a3, $t0
    ctx->r7 = ADD32(ctx->r7, ctx->r8);
    // 0x80199A28: addu        $a2, $a2, $t0
    ctx->r6 = ADD32(ctx->r6, ctx->r8);
    // 0x80199A2C: addu        $a1, $a1, $t0
    ctx->r5 = ADD32(ctx->r5, ctx->r8);
    // 0x80199A30: lw          $a1, -0xE14($a1)
    ctx->r5 = MEM_W(ctx->r5, -0XE14);
    // 0x80199A34: lw          $a2, -0xE04($a2)
    ctx->r6 = MEM_W(ctx->r6, -0XE04);
    // 0x80199A38: lw          $a3, -0xE98($a3)
    ctx->r7 = MEM_W(ctx->r7, -0XE98);
    // 0x80199A3C: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x80199A40: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x80199A44: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80199A48: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80199A4C: swc1        $f20, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f20.u32l;
    // 0x80199A50: sw          $t1, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r9;
    // 0x80199A54: sw          $t2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r10;
    // 0x80199A58: sw          $t3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r11;
    // 0x80199A5C: jal         0x8009D0BC
    // 0x80199A60: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    Lib_TextureRect_CI8(rdram, ctx);
        goto after_3;
    // 0x80199A60: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_3:
    // 0x80199A64: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80199A68: jal         0x800B8DD0
    // 0x80199A6C: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    RCP_SetupDL(rdram, ctx);
        goto after_4;
    // 0x80199A6C: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    after_4:
    // 0x80199A70: lw          $t9, 0x7C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X7C);
    // 0x80199A74: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x80199A78: addiu       $t6, $t6, -0x6CB8
    ctx->r14 = ADD32(ctx->r14, -0X6CB8);
    // 0x80199A7C: addu        $v1, $t9, $t6
    ctx->r3 = ADD32(ctx->r25, ctx->r14);
    // 0x80199A80: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x80199A84: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80199A88: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x80199A8C: beq         $a0, $zero, L_80199A9C
    if (ctx->r4 == 0) {
        // 0x80199A90: addiu       $t4, $a0, -0x1
        ctx->r12 = ADD32(ctx->r4, -0X1);
            goto L_80199A9C;
    }
    // 0x80199A90: addiu       $t4, $a0, -0x1
    ctx->r12 = ADD32(ctx->r4, -0X1);
    // 0x80199A94: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80199A98: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
L_80199A9C:
    // 0x80199A9C: lw          $t8, 0x7DB0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7DB0);
    // 0x80199AA0: and         $t5, $t8, $v0
    ctx->r13 = ctx->r24 & ctx->r2;
    // 0x80199AA4: beq         $t5, $zero, L_80199BC0
    if (ctx->r13 == 0) {
        // 0x80199AA8: nop
    
            goto L_80199BC0;
    }
    // 0x80199AA8: nop

    // 0x80199AAC: lw          $t7, 0x7C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X7C);
    // 0x80199AB0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80199AB4: lui         $a1, 0x700
    ctx->r5 = S32(0X700 << 16);
    // 0x80199AB8: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80199ABC: lwc1        $f16, -0x6CA8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X6CA8);
    // 0x80199AC0: lui         $at, 0xFF00
    ctx->r1 = S32(0XFF00 << 16);
    // 0x80199AC4: lui         $t4, 0xFA00
    ctx->r12 = S32(0XFA00 << 16);
    // 0x80199AC8: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80199ACC: addiu       $a1, $a1, 0x1030
    ctx->r5 = ADD32(ctx->r5, 0X1030);
    // 0x80199AD0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80199AD4: mfc1        $t1, $f18
    ctx->r9 = (int32_t)ctx->f18.u32l;
    // 0x80199AD8: nop

    // 0x80199ADC: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80199AE0: andi        $t0, $t1, 0xFF
    ctx->r8 = ctx->r9 & 0XFF;
    // 0x80199AE4: sll         $t8, $t0, 16
    ctx->r24 = S32(ctx->r8 << 16);
    // 0x80199AE8: or          $t5, $t8, $at
    ctx->r13 = ctx->r24 | ctx->r1;
    // 0x80199AEC: sll         $t7, $t0, 8
    ctx->r15 = S32(ctx->r8 << 8);
    // 0x80199AF0: or          $s0, $t5, $t7
    ctx->r16 = ctx->r13 | ctx->r15;
    // 0x80199AF4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80199AF8: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
    // 0x80199AFC: ori         $t9, $s0, 0xFF
    ctx->r25 = ctx->r16 | 0XFF;
    // 0x80199B00: or          $s0, $t9, $zero
    ctx->r16 = ctx->r25 | 0;
    // 0x80199B04: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80199B08: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80199B0C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80199B10: lwc1        $f8, -0xE44($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0XE44);
    // 0x80199B14: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80199B18: lwc1        $f16, -0xE40($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0XE40);
    // 0x80199B1C: lwc1        $f4, 0x0($s7)
    ctx->f4.u32l = MEM_W(ctx->r23, 0X0);
    // 0x80199B20: lwc1        $f6, 0x0($fp)
    ctx->f6.u32l = MEM_W(ctx->r30, 0X0);
    // 0x80199B24: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    // 0x80199B28: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80199B2C: addiu       $a3, $zero, 0x9
    ctx->r7 = ADD32(0, 0X9);
    // 0x80199B30: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x80199B34: add.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x80199B38: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x80199B3C: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80199B40: jal         0x8009D994
    // 0x80199B44: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_5;
    // 0x80199B44: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_5:
    // 0x80199B48: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80199B4C: lui         $t4, 0xFA00
    ctx->r12 = S32(0XFA00 << 16);
    // 0x80199B50: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80199B54: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80199B58: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
    // 0x80199B5C: sw          $s0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r16;
    // 0x80199B60: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80199B64: lw          $t8, 0x7C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X7C);
    // 0x80199B68: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80199B6C: lwc1        $f8, -0xE3C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0XE3C);
    // 0x80199B70: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80199B74: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x80199B78: lwc1        $f16, -0xE38($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0XE38);
    // 0x80199B7C: lwc1        $f4, 0x0($s7)
    ctx->f4.u32l = MEM_W(ctx->r23, 0X0);
    // 0x80199B80: lwc1        $f6, 0x0($fp)
    ctx->f6.u32l = MEM_W(ctx->r30, 0X0);
    // 0x80199B84: addu        $t5, $t5, $t8
    ctx->r13 = ADD32(ctx->r13, ctx->r24);
    // 0x80199B88: lw          $t5, -0x12C4($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X12C4);
    // 0x80199B8C: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80199B90: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x80199B94: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x80199B98: add.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x80199B9C: addu        $a1, $a1, $t7
    ctx->r5 = ADD32(ctx->r5, ctx->r15);
    // 0x80199BA0: lw          $a1, -0xE20($a1)
    ctx->r5 = MEM_W(ctx->r5, -0XE20);
    // 0x80199BA4: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x80199BA8: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x80199BAC: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    // 0x80199BB0: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    // 0x80199BB4: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x80199BB8: jal         0x8009D994
    // 0x80199BBC: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_6;
    // 0x80199BBC: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    after_6:
L_80199BC0:
    // 0x80199BC0: lui         $s0, 0x801
    ctx->r16 = S32(0X801 << 16);
    // 0x80199BC4: lui         $s1, 0x801B
    ctx->r17 = S32(0X801B << 16);
    // 0x80199BC8: addiu       $s1, $s1, -0xE24
    ctx->r17 = ADD32(ctx->r17, -0XE24);
    // 0x80199BCC: addiu       $s0, $s0, -0x1ED0
    ctx->r16 = ADD32(ctx->r16, -0X1ED0);
    // 0x80199BD0: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80199BD4: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x80199BD8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80199BDC: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80199BE0: sw          $t9, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r25;
    // 0x80199BE4: sw          $s5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r21;
    // 0x80199BE8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80199BEC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80199BF0: lwc1        $f8, -0xE2C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0XE2C);
    // 0x80199BF4: lwc1        $f4, 0x0($s7)
    ctx->f4.u32l = MEM_W(ctx->r23, 0X0);
    // 0x80199BF8: lwc1        $f6, 0x0($fp)
    ctx->f6.u32l = MEM_W(ctx->r30, 0X0);
    // 0x80199BFC: lwc1        $f16, 0x0($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80199C00: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80199C04: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80199C08: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80199C0C: add.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x80199C10: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x80199C14: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    // 0x80199C18: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x80199C1C: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x80199C20: jal         0x8009E1E8
    // 0x80199C24: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    Lib_TextureRect_IA8_MirX(rdram, ctx);
        goto after_7;
    // 0x80199C24: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    after_7:
    // 0x80199C28: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80199C2C: lwc1        $f8, -0xE28($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0XE28);
    // 0x80199C30: lwc1        $f4, 0x0($s7)
    ctx->f4.u32l = MEM_W(ctx->r23, 0X0);
    // 0x80199C34: lwc1        $f6, 0x0($fp)
    ctx->f6.u32l = MEM_W(ctx->r30, 0X0);
    // 0x80199C38: lwc1        $f16, 0x0($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80199C3C: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80199C40: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80199C44: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80199C48: add.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x80199C4C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x80199C50: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80199C54: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    // 0x80199C58: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x80199C5C: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x80199C60: jal         0x8009D994
    // 0x80199C64: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_8;
    // 0x80199C64: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    after_8:
    // 0x80199C68: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80199C6C: lwc1        $f8, -0xE34($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0XE34);
    // 0x80199C70: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80199C74: lwc1        $f16, -0xE30($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0XE30);
    // 0x80199C78: lwc1        $f4, 0x0($s7)
    ctx->f4.u32l = MEM_W(ctx->r23, 0X0);
    // 0x80199C7C: lwc1        $f6, 0x0($fp)
    ctx->f6.u32l = MEM_W(ctx->r30, 0X0);
    // 0x80199C80: lui         $a1, 0x700
    ctx->r5 = S32(0X700 << 16);
    // 0x80199C84: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80199C88: addiu       $a1, $a1, 0xF10
    ctx->r5 = ADD32(ctx->r5, 0XF10);
    // 0x80199C8C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80199C90: add.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x80199C94: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x80199C98: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    // 0x80199C9C: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    // 0x80199CA0: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x80199CA4: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x80199CA8: jal         0x8009D994
    // 0x80199CAC: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_9;
    // 0x80199CAC: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    after_9:
    // 0x80199CB0: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80199CB4: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x80199CB8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80199CBC: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x80199CC0: sw          $t4, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r12;
    // 0x80199CC4: sw          $s5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r21;
    // 0x80199CC8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80199CCC: lw          $t5, 0x7C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X7C);
    // 0x80199CD0: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80199CD4: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80199CD8: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x80199CDC: addiu       $t7, $t7, -0xDF4
    ctx->r15 = ADD32(ctx->r15, -0XDF4);
    // 0x80199CE0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80199CE4: lui         $s4, 0x801B
    ctx->r20 = S32(0X801B << 16);
    // 0x80199CE8: lui         $s3, 0x801B
    ctx->r19 = S32(0X801B << 16);
    // 0x80199CEC: addiu       $s3, $s3, -0xE4C
    ctx->r19 = ADD32(ctx->r19, -0XE4C);
    // 0x80199CF0: addiu       $s4, $s4, -0xE48
    ctx->r20 = ADD32(ctx->r20, -0XE48);
    // 0x80199CF4: lwc1        $f20, 0x7454($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X7454);
    // 0x80199CF8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80199CFC: addiu       $s5, $zero, 0x2
    ctx->r21 = ADD32(0, 0X2);
    // 0x80199D00: addu        $s6, $t5, $t7
    ctx->r22 = ADD32(ctx->r13, ctx->r15);
L_80199D04:
    // 0x80199D04: lwc1        $f4, 0x0($s7)
    ctx->f4.u32l = MEM_W(ctx->r23, 0X0);
    // 0x80199D08: lwc1        $f8, 0x0($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X0);
    // 0x80199D0C: lwc1        $f6, 0x0($fp)
    ctx->f6.u32l = MEM_W(ctx->r30, 0X0);
    // 0x80199D10: lwc1        $f16, 0x0($s4)
    ctx->f16.u32l = MEM_W(ctx->r20, 0X0);
    // 0x80199D14: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80199D18: mtc1        $s0, $f4
    ctx->f4.u32l = ctx->r16;
    // 0x80199D1C: lw          $t9, 0x0($s6)
    ctx->r25 = MEM_W(ctx->r22, 0X0);
    // 0x80199D20: add.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x80199D24: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x80199D28: sll         $t6, $s1, 1
    ctx->r14 = S32(ctx->r17 << 1);
    // 0x80199D2C: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80199D30: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80199D34: addiu       $a2, $zero, 0x2C
    ctx->r6 = ADD32(0, 0X2C);
    // 0x80199D38: addiu       $a3, $zero, 0x14
    ctx->r7 = ADD32(0, 0X14);
    // 0x80199D3C: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x80199D40: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80199D44: mul.s       $f10, $f8, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f22.fl);
    // 0x80199D48: addu        $a1, $t9, $t6
    ctx->r5 = ADD32(ctx->r25, ctx->r14);
    // 0x80199D4C: mul.s       $f6, $f10, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x80199D50: add.s       $f16, $f18, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x80199D54: jal         0x8009D418
    // 0x80199D58: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    Lib_TextureRect_RGBA16(rdram, ctx);
        goto after_10;
    // 0x80199D58: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    after_10:
    // 0x80199D5C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80199D60: bne         $s0, $s5, L_80199D04
    if (ctx->r16 != ctx->r21) {
        // 0x80199D64: addiu       $s1, $s1, 0x370
        ctx->r17 = ADD32(ctx->r17, 0X370);
            goto L_80199D04;
    }
    // 0x80199D64: addiu       $s1, $s1, 0x370
    ctx->r17 = ADD32(ctx->r17, 0X370);
    // 0x80199D68: lwc1        $f4, 0x0($s7)
    ctx->f4.u32l = MEM_W(ctx->r23, 0X0);
    // 0x80199D6C: lwc1        $f8, 0x0($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X0);
    // 0x80199D70: lwc1        $f18, 0x0($fp)
    ctx->f18.u32l = MEM_W(ctx->r30, 0X0);
    // 0x80199D74: lwc1        $f6, 0x0($s4)
    ctx->f6.u32l = MEM_W(ctx->r20, 0X0);
    // 0x80199D78: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80199D7C: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x80199D80: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80199D84: add.s       $f16, $f18, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x80199D88: lw          $a1, 0x0($s6)
    ctx->r5 = MEM_W(ctx->r22, 0X0);
    // 0x80199D8C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x80199D90: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80199D94: add.s       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x80199D98: addiu       $a2, $zero, 0x2C
    ctx->r6 = ADD32(0, 0X2C);
    // 0x80199D9C: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x80199DA0: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x80199DA4: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x80199DA8: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80199DAC: jal         0x8009D418
    // 0x80199DB0: addiu       $a1, $a1, 0xDC0
    ctx->r5 = ADD32(ctx->r5, 0XDC0);
    Lib_TextureRect_RGBA16(rdram, ctx);
        goto after_11;
    // 0x80199DB0: addiu       $a1, $a1, 0xDC0
    ctx->r5 = ADD32(ctx->r5, 0XDC0);
    after_11:
    // 0x80199DB4: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x80199DB8: addiu       $t4, $t4, -0xDF4
    ctx->r12 = ADD32(ctx->r12, -0XDF4);
    // 0x80199DBC: bne         $s6, $t4, L_80199DC8
    if (ctx->r22 != ctx->r12) {
        // 0x80199DC0: addiu       $a2, $zero, 0x18
        ctx->r6 = ADD32(0, 0X18);
            goto L_80199DC8;
    }
    // 0x80199DC0: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    // 0x80199DC4: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
L_80199DC8:
    // 0x80199DC8: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80199DCC: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x80199DD0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80199DD4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80199DD8: sw          $t8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r24;
    // 0x80199DDC: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80199DE0: lw          $t7, 0x80($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X80);
    // 0x80199DE4: lw          $t8, 0x70($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X70);
    // 0x80199DE8: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x80199DEC: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80199DF0: lw          $t7, 0x0($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X0);
    // 0x80199DF4: lw          $t8, 0x6C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X6C);
    // 0x80199DF8: andi        $t6, $t9, 0xFF
    ctx->r14 = ctx->r25 & 0XFF;
    // 0x80199DFC: sll         $t9, $t7, 24
    ctx->r25 = S32(ctx->r15 << 24);
    // 0x80199E00: lw          $t5, 0x0($t8)
    ctx->r13 = MEM_W(ctx->r24, 0X0);
    // 0x80199E04: sll         $t4, $t6, 8
    ctx->r12 = S32(ctx->r14 << 8);
    // 0x80199E08: or          $t6, $t4, $t9
    ctx->r14 = ctx->r12 | ctx->r25;
    // 0x80199E0C: andi        $t7, $t5, 0xFF
    ctx->r15 = ctx->r13 & 0XFF;
    // 0x80199E10: sll         $t4, $t7, 16
    ctx->r12 = S32(ctx->r15 << 16);
    // 0x80199E14: or          $t9, $t6, $t4
    ctx->r25 = ctx->r14 | ctx->r12;
    // 0x80199E18: ori         $t8, $t9, 0xFF
    ctx->r24 = ctx->r25 | 0XFF;
    // 0x80199E1C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80199E20: lw          $t5, 0x7C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X7C);
    // 0x80199E24: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80199E28: lwc1        $f18, 0x0($s7)
    ctx->f18.u32l = MEM_W(ctx->r23, 0X0);
    // 0x80199E2C: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x80199E30: lwc1        $f10, -0xE64($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0XE64);
    // 0x80199E34: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80199E38: lwc1        $f4, -0xE54($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0XE54);
    // 0x80199E3C: lwc1        $f16, 0x0($fp)
    ctx->f16.u32l = MEM_W(ctx->r30, 0X0);
    // 0x80199E40: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80199E44: add.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x80199E48: lwc1        $f0, -0xE50($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0XE50);
    // 0x80199E4C: addu        $a1, $a1, $t5
    ctx->r5 = ADD32(ctx->r5, ctx->r13);
    // 0x80199E50: add.s       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x80199E54: lw          $a1, -0xDE4($a1)
    ctx->r5 = MEM_W(ctx->r5, -0XDE4);
    // 0x80199E58: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x80199E5C: addiu       $a3, $zero, 0xD
    ctx->r7 = ADD32(0, 0XD);
    // 0x80199E60: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x80199E64: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x80199E68: jal         0x8009D994
    // 0x80199E6C: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_12;
    // 0x80199E6C: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    after_12:
    // 0x80199E70: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x80199E74: ldc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X30);
    // 0x80199E78: ldc1        $f22, 0x38($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X38);
    // 0x80199E7C: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x80199E80: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x80199E84: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x80199E88: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x80199E8C: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x80199E90: lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X54);
    // 0x80199E94: lw          $s6, 0x58($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X58);
    // 0x80199E98: lw          $s7, 0x5C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X5C);
    // 0x80199E9C: lw          $fp, 0x60($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X60);
    // 0x80199EA0: jr          $ra
    // 0x80199EA4: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x80199EA4: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
;}
RECOMP_FUNC void Title_CsGreatFoxTraveling_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018994C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80189950: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80189954: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80189958: lw          $v0, -0x7D40($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D40);
    // 0x8018995C: slti        $at, $v0, 0xB
    ctx->r1 = SIGNED(ctx->r2) < 0XB ? 1 : 0;
    // 0x80189960: bne         $at, $zero, L_80189978
    if (ctx->r1 != 0) {
        // 0x80189964: addiu       $at, $zero, 0x64
        ctx->r1 = ADD32(0, 0X64);
            goto L_80189978;
    }
    // 0x80189964: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x80189968: beq         $v0, $at, L_80189A04
    if (ctx->r2 == ctx->r1) {
        // 0x8018996C: nop
    
            goto L_80189A04;
    }
    // 0x8018996C: nop

    // 0x80189970: b           L_8018A224
    // 0x80189974: nop

        goto L_8018A224;
    // 0x80189974: nop

L_80189978:
    // 0x80189978: sltiu       $at, $v0, 0xB
    ctx->r1 = ctx->r2 < 0XB ? 1 : 0;
    // 0x8018997C: beq         $at, $zero, L_8018A224
    if (ctx->r1 == 0) {
        // 0x80189980: sll         $t6, $v0, 2
        ctx->r14 = S32(ctx->r2 << 2);
            goto L_8018A224;
    }
    // 0x80189980: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80189984: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80189988: addu        $at, $at, $t6
    gpr jr_addend_80189990 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8018998C: lw          $t6, 0x6E78($at)
    ctx->r14 = ADD32(ctx->r1, 0X6E78);
    // 0x80189990: jr          $t6
    // 0x80189994: nop

    switch (jr_addend_80189990 >> 2) {
        case 0: goto L_80189998; break;
        case 1: goto L_80189A3C; break;
        case 2: goto L_80189AF4; break;
        case 3: goto L_80189C04; break;
        case 4: goto L_80189CE8; break;
        case 5: goto L_8018A224; break;
        case 6: goto L_8018A224; break;
        case 7: goto L_8018A224; break;
        case 8: goto L_8018A224; break;
        case 9: goto L_8018A224; break;
        case 10: goto L_80189DEC; break;
        default: switch_error(__func__, 0x80189990, 0x801B6E78);
    }
    // 0x80189994: nop

L_80189998:
    // 0x80189998: jal         0x801894E8
    // 0x8018999C: nop

    Title_CsGreatFox_Setup(rdram, ctx);
        goto after_0;
    // 0x8018999C: nop

    after_0:
    // 0x801899A0: lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // 0x801899A4: addiu       $v0, $v0, 0x6B40
    ctx->r2 = ADD32(ctx->r2, 0X6B40);
    // 0x801899A8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801899AC: sw          $v0, -0x7D6C($at)
    MEM_W(-0X7D6C, ctx->r1) = ctx->r2;
    // 0x801899B0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801899B4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801899B8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801899BC: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801899C0: swc1        $f4, 0x7BE8($at)
    MEM_W(0X7BE8, ctx->r1) = ctx->f4.u32l;
    // 0x801899C4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801899C8: lwc1        $f6, 0x6EA4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6EA4);
    // 0x801899CC: addiu       $v1, $v1, -0x7D34
    ctx->r3 = ADD32(ctx->r3, -0X7D34);
    // 0x801899D0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801899D4: addiu       $t7, $zero, 0x64
    ctx->r15 = ADD32(0, 0X64);
    // 0x801899D8: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
    // 0x801899DC: sw          $t7, -0x7D40($at)
    MEM_W(-0X7D40, ctx->r1) = ctx->r15;
    // 0x801899E0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801899E4: sw          $zero, -0x7D48($at)
    MEM_W(-0X7D48, ctx->r1) = 0;
    // 0x801899E8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801899EC: sw          $zero, -0x7D64($at)
    MEM_W(-0X7D64, ctx->r1) = 0;
    // 0x801899F0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801899F4: sw          $zero, -0x7D00($at)
    MEM_W(-0X7D00, ctx->r1) = 0;
    // 0x801899F8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x801899FC: b           L_8018A224
    // 0x80189A00: sw          $zero, 0x4A70($at)
    MEM_W(0X4A70, ctx->r1) = 0;
        goto L_8018A224;
    // 0x80189A00: sw          $zero, 0x4A70($at)
    MEM_W(0X4A70, ctx->r1) = 0;
L_80189A04:
    // 0x80189A04: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x80189A08: addiu       $v1, $v1, -0x7CC0
    ctx->r3 = ADD32(ctx->r3, -0X7CC0);
    // 0x80189A0C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80189A10: beq         $v0, $zero, L_80189A20
    if (ctx->r2 == 0) {
        // 0x80189A14: addiu       $t8, $v0, -0x5
        ctx->r24 = ADD32(ctx->r2, -0X5);
            goto L_80189A20;
    }
    // 0x80189A14: addiu       $t8, $v0, -0x5
    ctx->r24 = ADD32(ctx->r2, -0X5);
    // 0x80189A18: b           L_8018A224
    // 0x80189A1C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
        goto L_8018A224;
    // 0x80189A1C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
L_80189A20:
    // 0x80189A20: addiu       $t9, $zero, 0x13
    ctx->r25 = ADD32(0, 0X13);
    // 0x80189A24: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80189A28: sw          $t9, -0x7D58($at)
    MEM_W(-0X7D58, ctx->r1) = ctx->r25;
    // 0x80189A2C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80189A30: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80189A34: b           L_8018A224
    // 0x80189A38: sw          $t0, -0x7D40($at)
    MEM_W(-0X7D40, ctx->r1) = ctx->r8;
        goto L_8018A224;
    // 0x80189A38: sw          $t0, -0x7D40($at)
    MEM_W(-0X7D40, ctx->r1) = ctx->r8;
L_80189A3C:
    // 0x80189A3C: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x80189A40: lw          $t1, -0x7D58($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X7D58);
    // 0x80189A44: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80189A48: addiu       $v1, $v1, -0x7D34
    ctx->r3 = ADD32(ctx->r3, -0X7D34);
    // 0x80189A4C: bne         $t1, $zero, L_8018A224
    if (ctx->r9 != 0) {
        // 0x80189A50: lui         $a0, 0x801B
        ctx->r4 = S32(0X801B << 16);
            goto L_8018A224;
    }
    // 0x80189A50: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x80189A54: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80189A58: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80189A5C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80189A60: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80189A64: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80189A68: addiu       $a0, $a0, 0x7BDC
    ctx->r4 = ADD32(ctx->r4, 0X7BDC);
    // 0x80189A6C: lw          $a2, 0x0($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X0);
    // 0x80189A70: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x80189A74: jal         0x8009BC2C
    // 0x80189A78: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_1;
    // 0x80189A78: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x80189A7C: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80189A80: addiu       $v1, $v1, -0x7D34
    ctx->r3 = ADD32(ctx->r3, -0X7D34);
    // 0x80189A84: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80189A88: lwc1        $f16, 0x6EA8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6EA8);
    // 0x80189A8C: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80189A90: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80189A94: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80189A98: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80189A9C: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x80189AA0: addiu       $v0, $v0, -0x7D30
    ctx->r2 = ADD32(ctx->r2, -0X7D30);
    // 0x80189AA4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80189AA8: addiu       $t2, $zero, 0x32
    ctx->r10 = ADD32(0, 0X32);
    // 0x80189AAC: addiu       $t3, $zero, 0x55
    ctx->r11 = ADD32(0, 0X55);
    // 0x80189AB0: bc1f        L_8018A224
    if (!c1cs) {
        // 0x80189AB4: swc1        $f18, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->f18.u32l;
            goto L_8018A224;
    }
    // 0x80189AB4: swc1        $f18, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f18.u32l;
    // 0x80189AB8: lwc1        $f12, 0x6EAC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X6EAC);
    // 0x80189ABC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80189AC0: sw          $t2, -0x7D58($at)
    MEM_W(-0X7D58, ctx->r1) = ctx->r10;
    // 0x80189AC4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80189AC8: sw          $t3, -0x7D54($at)
    MEM_W(-0X7D54, ctx->r1) = ctx->r11;
    // 0x80189ACC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80189AD0: swc1        $f12, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f12.u32l;
    // 0x80189AD4: lwc1        $f6, 0x6EB0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6EB0);
    // 0x80189AD8: lui         $t4, 0x801C
    ctx->r12 = S32(0X801C << 16);
    // 0x80189ADC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80189AE0: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
    // 0x80189AE4: lw          $t4, -0x7D40($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7D40);
    // 0x80189AE8: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80189AEC: b           L_8018A224
    // 0x80189AF0: sw          $t5, -0x7D40($at)
    MEM_W(-0X7D40, ctx->r1) = ctx->r13;
        goto L_8018A224;
    // 0x80189AF0: sw          $t5, -0x7D40($at)
    MEM_W(-0X7D40, ctx->r1) = ctx->r13;
L_80189AF4:
    // 0x80189AF4: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x80189AF8: lw          $t6, -0x7D58($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7D58);
    // 0x80189AFC: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80189B00: addiu       $v0, $v0, -0x7D30
    ctx->r2 = ADD32(ctx->r2, -0X7D30);
    // 0x80189B04: bne         $t6, $zero, L_8018A224
    if (ctx->r14 != 0) {
        // 0x80189B08: lui         $a0, 0x801B
        ctx->r4 = S32(0X801B << 16);
            goto L_8018A224;
    }
    // 0x80189B08: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x80189B0C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80189B10: lwc1        $f8, 0x6EB4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6EB4);
    // 0x80189B14: addiu       $a0, $a0, 0x7BDC
    ctx->r4 = ADD32(ctx->r4, 0X7BDC);
    // 0x80189B18: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80189B1C: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x80189B20: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x80189B24: jal         0x8009BC2C
    // 0x80189B28: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_2;
    // 0x80189B28: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x80189B2C: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80189B30: addiu       $v0, $v0, -0x7D30
    ctx->r2 = ADD32(ctx->r2, -0X7D30);
    // 0x80189B34: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80189B38: lwc1        $f16, 0x6EB8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6EB8);
    // 0x80189B3C: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80189B40: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x80189B44: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80189B48: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80189B4C: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x80189B50: addiu       $v1, $v1, -0x7D34
    ctx->r3 = ADD32(ctx->r3, -0X7D34);
    // 0x80189B54: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80189B58: addiu       $a0, $a0, 0x7BE0
    ctx->r4 = ADD32(ctx->r4, 0X7BE0);
    // 0x80189B5C: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x80189B60: swc1        $f18, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f18.u32l;
    // 0x80189B64: lw          $t7, -0x7D54($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7D54);
    // 0x80189B68: bne         $t7, $zero, L_8018A224
    if (ctx->r15 != 0) {
        // 0x80189B6C: nop
    
            goto L_8018A224;
    }
    // 0x80189B6C: nop

    // 0x80189B70: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80189B74: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80189B78: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80189B7C: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80189B80: lw          $a2, 0x0($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X0);
    // 0x80189B84: jal         0x8009BC2C
    // 0x80189B88: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_3;
    // 0x80189B88: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_3:
    // 0x80189B8C: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80189B90: addiu       $v1, $v1, -0x7D34
    ctx->r3 = ADD32(ctx->r3, -0X7D34);
    // 0x80189B94: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80189B98: lwc1        $f8, 0x6EBC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6EBC);
    // 0x80189B9C: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80189BA0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80189BA4: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80189BA8: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80189BAC: c.eq.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl == ctx->f16.fl;
    // 0x80189BB0: addiu       $v0, $v0, -0x7D30
    ctx->r2 = ADD32(ctx->r2, -0X7D30);
    // 0x80189BB4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80189BB8: addiu       $t8, $zero, 0x1E
    ctx->r24 = ADD32(0, 0X1E);
    // 0x80189BBC: lui         $t9, 0x801C
    ctx->r25 = S32(0X801C << 16);
    // 0x80189BC0: bc1f        L_8018A224
    if (!c1cs) {
        // 0x80189BC4: swc1        $f10, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->f10.u32l;
            goto L_8018A224;
    }
    // 0x80189BC4: swc1        $f10, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f10.u32l;
    // 0x80189BC8: lwc1        $f0, 0x6EC0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6EC0);
    // 0x80189BCC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80189BD0: sw          $t8, -0x7D58($at)
    MEM_W(-0X7D58, ctx->r1) = ctx->r24;
    // 0x80189BD4: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x80189BD8: lw          $t9, -0x7D40($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7D40);
    // 0x80189BDC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80189BE0: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x80189BE4: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80189BE8: sw          $t0, -0x7D40($at)
    MEM_W(-0X7D40, ctx->r1) = ctx->r8;
    // 0x80189BEC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80189BF0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80189BF4: addiu       $v1, $v1, -0x7CC0
    ctx->r3 = ADD32(ctx->r3, -0X7CC0);
    // 0x80189BF8: sw          $t1, 0x7BD8($at)
    MEM_W(0X7BD8, ctx->r1) = ctx->r9;
    // 0x80189BFC: b           L_8018A224
    // 0x80189C00: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
        goto L_8018A224;
    // 0x80189C00: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_80189C04:
    // 0x80189C04: lui         $t2, 0x801C
    ctx->r10 = S32(0X801C << 16);
    // 0x80189C08: lw          $t2, -0x7D58($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X7D58);
    // 0x80189C0C: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x80189C10: addiu       $a0, $a0, 0x7BE0
    ctx->r4 = ADD32(ctx->r4, 0X7BE0);
    // 0x80189C14: bne         $t2, $zero, L_8018A224
    if (ctx->r10 != 0) {
        // 0x80189C18: addiu       $a1, $zero, 0x0
        ctx->r5 = ADD32(0, 0X0);
            goto L_8018A224;
    }
    // 0x80189C18: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80189C1C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80189C20: lwc1        $f18, 0x6EC4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6EC4);
    // 0x80189C24: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x80189C28: lw          $a2, -0x7D30($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7D30);
    // 0x80189C2C: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x80189C30: jal         0x8009BC2C
    // 0x80189C34: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_4;
    // 0x80189C34: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_4:
    // 0x80189C38: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80189C3C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80189C40: lwc1        $f6, 0x6EC8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6EC8);
    // 0x80189C44: addiu       $v0, $v0, -0x7D30
    ctx->r2 = ADD32(ctx->r2, -0X7D30);
    // 0x80189C48: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80189C4C: lui         $v1, 0x801B
    ctx->r3 = S32(0X801B << 16);
    // 0x80189C50: addiu       $v1, $v1, 0x7BB8
    ctx->r3 = ADD32(ctx->r3, 0X7BB8);
    // 0x80189C54: lui         $at, 0x4496
    ctx->r1 = S32(0X4496 << 16);
    // 0x80189C58: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80189C5C: lwc1        $f2, 0x0($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80189C60: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80189C64: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80189C68: c.lt.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl < ctx->f10.fl;
    // 0x80189C6C: lui         $t4, 0x801C
    ctx->r12 = S32(0X801C << 16);
    // 0x80189C70: bc1f        L_80189CD0
    if (!c1cs) {
        // 0x80189C74: swc1        $f8, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
            goto L_80189CD0;
    }
    // 0x80189C74: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x80189C78: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80189C7C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80189C80: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80189C84: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80189C88: add.s       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f2.fl + ctx->f16.fl;
    // 0x80189C8C: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x80189C90: addiu       $a0, $a0, 0x7BDC
    ctx->r4 = ADD32(ctx->r4, 0X7BDC);
    // 0x80189C94: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80189C98: swc1        $f18, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f18.u32l;
    // 0x80189C9C: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80189CA0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80189CA4: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80189CA8: nop

    // 0x80189CAC: bc1f        L_8018A224
    if (!c1cs) {
        // 0x80189CB0: nop
    
            goto L_8018A224;
    }
    // 0x80189CB0: nop

    // 0x80189CB4: sw          $t3, 0x7BD4($at)
    MEM_W(0X7BD4, ctx->r1) = ctx->r11;
    // 0x80189CB8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80189CBC: lwc1        $f10, 0x6ECC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6ECC);
    // 0x80189CC0: lwc1        $f8, 0x0($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80189CC4: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80189CC8: b           L_8018A224
    // 0x80189CCC: swc1        $f16, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f16.u32l;
        goto L_8018A224;
    // 0x80189CCC: swc1        $f16, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f16.u32l;
L_80189CD0:
    // 0x80189CD0: lw          $t4, -0x7D40($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7D40);
    // 0x80189CD4: sw          $zero, 0x7BD8($at)
    MEM_W(0X7BD8, ctx->r1) = 0;
    // 0x80189CD8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80189CDC: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80189CE0: b           L_8018A224
    // 0x80189CE4: sw          $t5, -0x7D40($at)
    MEM_W(-0X7D40, ctx->r1) = ctx->r13;
        goto L_8018A224;
    // 0x80189CE4: sw          $t5, -0x7D40($at)
    MEM_W(-0X7D40, ctx->r1) = ctx->r13;
L_80189CE8:
    // 0x80189CE8: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x80189CEC: addiu       $a0, $a0, 0x7BDC
    ctx->r4 = ADD32(ctx->r4, 0X7BDC);
    // 0x80189CF0: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80189CF4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80189CF8: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80189CFC: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80189D00: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x80189D04: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80189D08: addiu       $a1, $a1, -0x7D24
    ctx->r5 = ADD32(ctx->r5, -0X7D24);
    // 0x80189D0C: addiu       $v1, $v1, -0x7D28
    ctx->r3 = ADD32(ctx->r3, -0X7D28);
    // 0x80189D10: lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // 0x80189D14: bc1f        L_80189D34
    if (!c1cs) {
        // 0x80189D18: lui         $a2, 0x801C
        ctx->r6 = S32(0X801C << 16);
            goto L_80189D34;
    }
    // 0x80189D18: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x80189D1C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80189D20: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80189D24: nop

    // 0x80189D28: add.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f18.fl;
    // 0x80189D2C: b           L_8018A224
    // 0x80189D30: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
        goto L_8018A224;
    // 0x80189D30: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
L_80189D34:
    // 0x80189D34: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80189D38: lwc1        $f0, 0x6ED0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6ED0);
    // 0x80189D3C: swc1        $f2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f2.u32l;
    // 0x80189D40: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80189D44: addiu       $t6, $zero, 0x46
    ctx->r14 = ADD32(0, 0X46);
    // 0x80189D48: sw          $t6, -0x7D58($at)
    MEM_W(-0X7D58, ctx->r1) = ctx->r14;
    // 0x80189D4C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80189D50: sw          $zero, -0x7D4C($at)
    MEM_W(-0X7D4C, ctx->r1) = 0;
    // 0x80189D54: addiu       $a2, $a2, -0x7D2C
    ctx->r6 = ADD32(ctx->r6, -0X7D2C);
    // 0x80189D58: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80189D5C: swc1        $f0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f0.u32l;
    // 0x80189D60: lwc1        $f6, 0x6ED4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6ED4);
    // 0x80189D64: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80189D68: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80189D6C: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
    // 0x80189D70: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
    // 0x80189D74: sw          $zero, -0x7D68($at)
    MEM_W(-0X7D68, ctx->r1) = 0;
    // 0x80189D78: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80189D7C: swc1        $f8, -0x7D74($at)
    MEM_W(-0X7D74, ctx->r1) = ctx->f8.u32l;
    // 0x80189D80: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80189D84: lwc1        $f10, 0x6ED8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6ED8);
    // 0x80189D88: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80189D8C: addiu       $v0, $v0, 0x6B40
    ctx->r2 = ADD32(ctx->r2, 0X6B40);
    // 0x80189D90: swc1        $f10, -0x7D70($at)
    MEM_W(-0X7D70, ctx->r1) = ctx->f10.u32l;
    // 0x80189D94: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80189D98: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80189D9C: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x80189DA0: swc1        $f16, 0x7978($at)
    MEM_W(0X7978, ctx->r1) = ctx->f16.u32l;
    // 0x80189DA4: lwc1        $f18, 0x4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80189DA8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80189DAC: swc1        $f18, 0x7980($at)
    MEM_W(0X7980, ctx->r1) = ctx->f18.u32l;
    // 0x80189DB0: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80189DB4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80189DB8: swc1        $f4, 0x7988($at)
    MEM_W(0X7988, ctx->r1) = ctx->f4.u32l;
    // 0x80189DBC: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80189DC0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80189DC4: swc1        $f6, 0x79A0($at)
    MEM_W(0X79A0, ctx->r1) = ctx->f6.u32l;
    // 0x80189DC8: lwc1        $f8, 0x10($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80189DCC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80189DD0: swc1        $f8, 0x79B8($at)
    MEM_W(0X79B8, ctx->r1) = ctx->f8.u32l;
    // 0x80189DD4: lwc1        $f10, 0x14($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80189DD8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80189DDC: swc1        $f10, 0x79C0($at)
    MEM_W(0X79C0, ctx->r1) = ctx->f10.u32l;
    // 0x80189DE0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80189DE4: b           L_8018A224
    // 0x80189DE8: sw          $t7, -0x7D40($at)
    MEM_W(-0X7D40, ctx->r1) = ctx->r15;
        goto L_8018A224;
    // 0x80189DE8: sw          $t7, -0x7D40($at)
    MEM_W(-0X7D40, ctx->r1) = ctx->r15;
L_80189DEC:
    // 0x80189DEC: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80189DF0: lw          $v0, -0x7D4C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D4C);
    // 0x80189DF4: addiu       $at, $zero, 0x2D
    ctx->r1 = ADD32(0, 0X2D);
    // 0x80189DF8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80189DFC: bne         $v0, $at, L_80189E0C
    if (ctx->r2 != ctx->r1) {
        // 0x80189E00: lui         $a3, 0x800C
        ctx->r7 = S32(0X800C << 16);
            goto L_80189E0C;
    }
    // 0x80189E00: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80189E04: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80189E08: sw          $t8, 0x7BF0($at)
    MEM_W(0X7BF0, ctx->r1) = ctx->r24;
L_80189E0C:
    // 0x80189E0C: addiu       $at, $zero, 0x91
    ctx->r1 = ADD32(0, 0X91);
    // 0x80189E10: bne         $v0, $at, L_80189E20
    if (ctx->r2 != ctx->r1) {
        // 0x80189E14: addiu       $a3, $a3, 0x5D34
        ctx->r7 = ADD32(ctx->r7, 0X5D34);
            goto L_80189E20;
    }
    // 0x80189E14: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80189E18: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80189E1C: sw          $zero, 0x7BF0($at)
    MEM_W(0X7BF0, ctx->r1) = 0;
L_80189E20:
    // 0x80189E20: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80189E24: lw          $v0, -0x7D48($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D48);
    // 0x80189E28: addiu       $at, $zero, 0x27E
    ctx->r1 = ADD32(0, 0X27E);
    // 0x80189E2C: lui         $a0, 0x1103
    ctx->r4 = S32(0X1103 << 16);
    // 0x80189E30: bne         $v0, $at, L_80189EA0
    if (ctx->r2 != ctx->r1) {
        // 0x80189E34: ori         $a0, $a0, 0x10
        ctx->r4 = ctx->r4 | 0X10;
            goto L_80189EA0;
    }
    // 0x80189E34: ori         $a0, $a0, 0x10
    ctx->r4 = ctx->r4 | 0X10;
    // 0x80189E38: lui         $t9, 0x800C
    ctx->r25 = S32(0X800C << 16);
    // 0x80189E3C: addiu       $t9, $t9, 0x5D3C
    ctx->r25 = ADD32(ctx->r25, 0X5D3C);
    // 0x80189E40: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x80189E44: addiu       $a1, $a1, -0x7984
    ctx->r5 = ADD32(ctx->r5, -0X7984);
    // 0x80189E48: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80189E4C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80189E50: jal         0x80019218
    // 0x80189E54: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    Audio_PlaySfx(rdram, ctx);
        goto after_5;
    // 0x80189E54: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_5:
    // 0x80189E58: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80189E5C: lui         $t0, 0x800C
    ctx->r8 = S32(0X800C << 16);
    // 0x80189E60: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80189E64: addiu       $t0, $t0, 0x5D3C
    ctx->r8 = ADD32(ctx->r8, 0X5D3C);
    // 0x80189E68: lui         $a0, 0x3102
    ctx->r4 = S32(0X3102 << 16);
    // 0x80189E6C: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x80189E70: addiu       $a1, $a1, -0x7984
    ctx->r5 = ADD32(ctx->r5, -0X7984);
    // 0x80189E74: ori         $a0, $a0, 0x4059
    ctx->r4 = ctx->r4 | 0X4059;
    // 0x80189E78: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80189E7C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80189E80: jal         0x80019218
    // 0x80189E84: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Audio_PlaySfx(rdram, ctx);
        goto after_6;
    // 0x80189E84: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x80189E88: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80189E8C: addiu       $a0, $a0, -0x5F0C
    ctx->r4 = ADD32(ctx->r4, -0X5F0C);
    // 0x80189E90: jal         0x800BA808
    // 0x80189E94: addiu       $a1, $zero, 0x12C
    ctx->r5 = ADD32(0, 0X12C);
    Radio_PlayMessage(rdram, ctx);
        goto after_7;
    // 0x80189E94: addiu       $a1, $zero, 0x12C
    ctx->r5 = ADD32(0, 0X12C);
    after_7:
    // 0x80189E98: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80189E9C: lw          $v0, -0x7D48($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D48);
L_80189EA0:
    // 0x80189EA0: addiu       $at, $zero, 0x346
    ctx->r1 = ADD32(0, 0X346);
    // 0x80189EA4: bne         $v0, $at, L_80189EB8
    if (ctx->r2 != ctx->r1) {
        // 0x80189EA8: lui         $a0, 0x801B
        ctx->r4 = S32(0X801B << 16);
            goto L_80189EB8;
    }
    // 0x80189EA8: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x80189EAC: addiu       $a0, $a0, -0x25D0
    ctx->r4 = ADD32(ctx->r4, -0X25D0);
    // 0x80189EB0: jal         0x801919C4
    // 0x80189EB4: addiu       $a1, $zero, 0x136
    ctx->r5 = ADD32(0, 0X136);
    Title_Radio_PlayMessage(rdram, ctx);
        goto after_8;
    // 0x80189EB4: addiu       $a1, $zero, 0x136
    ctx->r5 = ADD32(0, 0X136);
    after_8:
L_80189EB8:
    // 0x80189EB8: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80189EBC: lw          $v0, -0x7D58($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D58);
    // 0x80189EC0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80189EC4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80189EC8: bne         $v0, $at, L_80189ED8
    if (ctx->r2 != ctx->r1) {
        // 0x80189ECC: lui         $a1, 0x801C
        ctx->r5 = S32(0X801C << 16);
            goto L_80189ED8;
    }
    // 0x80189ECC: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x80189ED0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80189ED4: sw          $t1, -0x7CB8($at)
    MEM_W(-0X7CB8, ctx->r1) = ctx->r9;
L_80189ED8:
    // 0x80189ED8: bne         $v0, $zero, L_8018A224
    if (ctx->r2 != 0) {
        // 0x80189EDC: addiu       $a1, $a1, -0x6F88
        ctx->r5 = ADD32(ctx->r5, -0X6F88);
            goto L_8018A224;
    }
    // 0x80189EDC: addiu       $a1, $a1, -0x6F88
    ctx->r5 = ADD32(ctx->r5, -0X6F88);
    // 0x80189EE0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80189EE4: lwc1        $f16, 0x6EDC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6EDC);
    // 0x80189EE8: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80189EEC: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80189EF0: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80189EF4: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x80189EF8: addiu       $v1, $v1, -0x6F90
    ctx->r3 = ADD32(ctx->r3, -0X6F90);
    // 0x80189EFC: addiu       $v0, $v0, -0x6F84
    ctx->r2 = ADD32(ctx->r2, -0X6F84);
    // 0x80189F00: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x80189F04: bc1f        L_80189F50
    if (!c1cs) {
        // 0x80189F08: lui         $a3, 0x42C8
        ctx->r7 = S32(0X42C8 << 16);
            goto L_80189F50;
    }
    // 0x80189F08: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x80189F0C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80189F10: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80189F14: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80189F18: lwc1        $f12, 0x6EE0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X6EE0);
    // 0x80189F1C: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80189F20: addiu       $a0, $a0, -0x6F8C
    ctx->r4 = ADD32(ctx->r4, -0X6F8C);
    // 0x80189F24: add.s       $f18, $f0, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f12.fl;
    // 0x80189F28: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80189F2C: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80189F30: lwc1        $f16, 0x0($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80189F34: swc1        $f18, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f18.u32l;
    // 0x80189F38: add.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x80189F3C: sub.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x80189F40: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x80189F44: sub.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f2.fl;
    // 0x80189F48: swc1        $f10, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f10.u32l;
    // 0x80189F4C: swc1        $f18, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f18.u32l;
L_80189F50:
    // 0x80189F50: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80189F54: lwc1        $f4, 0x6EE4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6EE4);
    // 0x80189F58: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x80189F5C: addiu       $a0, $a0, 0x7BDC
    ctx->r4 = ADD32(ctx->r4, 0X7BDC);
    // 0x80189F60: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80189F64: lw          $a2, -0x7D24($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7D24);
    // 0x80189F68: jal         0x8009BC2C
    // 0x80189F6C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_9;
    // 0x80189F6C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_9:
    // 0x80189F70: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x80189F74: addiu       $a1, $a1, -0x7D24
    ctx->r5 = ADD32(ctx->r5, -0X7D24);
    // 0x80189F78: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80189F7C: lwc1        $f8, 0x6EE8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6EE8);
    // 0x80189F80: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80189F84: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80189F88: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80189F8C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80189F90: c.eq.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl == ctx->f16.fl;
    // 0x80189F94: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80189F98: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80189F9C: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x80189FA0: bc1f        L_80189FAC
    if (!c1cs) {
        // 0x80189FA4: swc1        $f10, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->f10.u32l;
            goto L_80189FAC;
    }
    // 0x80189FA4: swc1        $f10, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f10.u32l;
    // 0x80189FA8: sw          $t2, 0x7BD4($at)
    MEM_W(0X7BD4, ctx->r1) = ctx->r10;
L_80189FAC:
    // 0x80189FAC: lw          $a0, -0x7D6C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7D6C);
    // 0x80189FB0: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x80189FB4: jal         0x8018CC30
    // 0x80189FB8: lw          $a2, -0x7D70($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7D70);
    Title_Cutscene_SetCamera(rdram, ctx);
        goto after_10;
    // 0x80189FB8: lw          $a2, -0x7D70($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7D70);
    after_10:
    // 0x80189FBC: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80189FC0: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x80189FC4: addiu       $a1, $a1, -0x7954
    ctx->r5 = ADD32(ctx->r5, -0X7954);
    // 0x80189FC8: jal         0x80191798
    // 0x80189FCC: addiu       $a0, $a0, -0x7958
    ctx->r4 = ADD32(ctx->r4, -0X7958);
    Title_GetCamRot(rdram, ctx);
        goto after_11;
    // 0x80189FCC: addiu       $a0, $a0, -0x7958
    ctx->r4 = ADD32(ctx->r4, -0X7958);
    after_11:
    // 0x80189FD0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80189FD4: lwc1        $f12, -0x7958($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X7958);
    // 0x80189FD8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80189FDC: jal         0x80191844
    // 0x80189FE0: lwc1        $f14, -0x7954($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X7954);
    Title_SetCamUp(rdram, ctx);
        goto after_12;
    // 0x80189FE0: lwc1        $f14, -0x7954($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X7954);
    after_12:
    // 0x80189FE4: lui         $t3, 0x801C
    ctx->r11 = S32(0X801C << 16);
    // 0x80189FE8: lw          $t3, -0x7D48($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X7D48);
    // 0x80189FEC: lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // 0x80189FF0: addiu       $v0, $v0, 0x7BE8
    ctx->r2 = ADD32(ctx->r2, 0X7BE8);
    // 0x80189FF4: slti        $at, $t3, 0x3C1
    ctx->r1 = SIGNED(ctx->r11) < 0X3C1 ? 1 : 0;
    // 0x80189FF8: bne         $at, $zero, L_8018A040
    if (ctx->r1 != 0) {
        // 0x80189FFC: lui         $a0, 0x801C
        ctx->r4 = S32(0X801C << 16);
            goto L_8018A040;
    }
    // 0x80189FFC: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8018A000: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8018A004: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8018A008: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018A00C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8018A010: nop

    // 0x8018A014: bc1fl       L_8018A044
    if (!c1cs) {
        // 0x8018A018: lui         $at, 0xC2C8
        ctx->r1 = S32(0XC2C8 << 16);
            goto L_8018A044;
    }
    goto skip_0;
    // 0x8018A018: lui         $at, 0xC2C8
    ctx->r1 = S32(0XC2C8 << 16);
    skip_0:
    // 0x8018A01C: lwc1        $f18, 0x6EEC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6EEC);
    // 0x8018A020: sub.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x8018A024: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x8018A028: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8018A02C: c.lt.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl < ctx->f2.fl;
    // 0x8018A030: nop

    // 0x8018A034: bc1fl       L_8018A044
    if (!c1cs) {
        // 0x8018A038: lui         $at, 0xC2C8
        ctx->r1 = S32(0XC2C8 << 16);
            goto L_8018A044;
    }
    goto skip_1;
    // 0x8018A038: lui         $at, 0xC2C8
    ctx->r1 = S32(0XC2C8 << 16);
    skip_1:
    // 0x8018A03C: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
L_8018A040:
    // 0x8018A040: lui         $at, 0xC2C8
    ctx->r1 = S32(0XC2C8 << 16);
L_8018A044:
    // 0x8018A044: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018A048: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018A04C: lwc1        $f10, -0x7954($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X7954);
    // 0x8018A050: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018A054: addiu       $a0, $a0, -0x7938
    ctx->r4 = ADD32(ctx->r4, -0X7938);
    // 0x8018A058: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x8018A05C: lui         $a1, 0x4170
    ctx->r5 = S32(0X4170 << 16);
    // 0x8018A060: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x8018A064: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x8018A068: bc1f        L_8018A0D0
    if (!c1cs) {
        // 0x8018A06C: nop
    
            goto L_8018A0D0;
    }
    // 0x8018A06C: nop

    // 0x8018A070: lwc1        $f16, 0x6EF0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6EF0);
    // 0x8018A074: lw          $a2, -0x7D2C($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7D2C);
    // 0x8018A078: jal         0x8009BC2C
    // 0x8018A07C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_13;
    // 0x8018A07C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_13:
    // 0x8018A080: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018A084: lwc1        $f18, 0x6EF4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6EF4);
    // 0x8018A088: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8018A08C: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x8018A090: lw          $a2, -0x7D2C($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7D2C);
    // 0x8018A094: addiu       $a0, $a0, -0x7934
    ctx->r4 = ADD32(ctx->r4, -0X7934);
    // 0x8018A098: lui         $a1, 0xC20C
    ctx->r5 = S32(0XC20C << 16);
    // 0x8018A09C: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x8018A0A0: jal         0x8009BC2C
    // 0x8018A0A4: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_14;
    // 0x8018A0A4: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_14:
    // 0x8018A0A8: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x8018A0AC: addiu       $a2, $a2, -0x7D2C
    ctx->r6 = ADD32(ctx->r6, -0X7D2C);
    // 0x8018A0B0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018A0B4: lwc1        $f6, 0x6EF8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6EF8);
    // 0x8018A0B8: lwc1        $f4, 0x0($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8018A0BC: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8018A0C0: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8018A0C4: swc1        $f8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f8.u32l;
    // 0x8018A0C8: b           L_8018A16C
    // 0x8018A0CC: lw          $v0, -0x7D4C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D4C);
        goto L_8018A16C;
    // 0x8018A0CC: lw          $v0, -0x7D4C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D4C);
L_8018A0D0:
    // 0x8018A0D0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018A0D4: lwc1        $f10, 0x6EFC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6EFC);
    // 0x8018A0D8: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8018A0DC: addiu       $v1, $v1, -0x7D28
    ctx->r3 = ADD32(ctx->r3, -0X7D28);
    // 0x8018A0E0: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8018A0E4: addiu       $a0, $a0, -0x7938
    ctx->r4 = ADD32(ctx->r4, -0X7938);
    // 0x8018A0E8: lw          $a2, 0x0($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X0);
    // 0x8018A0EC: lui         $a1, 0xC1A0
    ctx->r5 = S32(0XC1A0 << 16);
    // 0x8018A0F0: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x8018A0F4: jal         0x8009BC2C
    // 0x8018A0F8: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_15;
    // 0x8018A0F8: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_15:
    // 0x8018A0FC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018A100: lwc1        $f16, 0x6F00($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6F00);
    // 0x8018A104: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8018A108: addiu       $v1, $v1, -0x7D28
    ctx->r3 = ADD32(ctx->r3, -0X7D28);
    // 0x8018A10C: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8018A110: addiu       $a0, $a0, -0x7934
    ctx->r4 = ADD32(ctx->r4, -0X7934);
    // 0x8018A114: lw          $a2, 0x0($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X0);
    // 0x8018A118: lui         $a1, 0xC1C8
    ctx->r5 = S32(0XC1C8 << 16);
    // 0x8018A11C: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x8018A120: jal         0x8009BC2C
    // 0x8018A124: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_16;
    // 0x8018A124: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_16:
    // 0x8018A128: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8018A12C: lw          $v0, -0x7D4C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D4C);
    // 0x8018A130: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8018A134: addiu       $v1, $v1, -0x7D28
    ctx->r3 = ADD32(ctx->r3, -0X7D28);
    // 0x8018A138: slti        $at, $v0, 0x227
    ctx->r1 = SIGNED(ctx->r2) < 0X227 ? 1 : 0;
    // 0x8018A13C: bne         $at, $zero, L_8018A158
    if (ctx->r1 != 0) {
        // 0x8018A140: lui         $at, 0x801B
        ctx->r1 = S32(0X801B << 16);
            goto L_8018A158;
    }
    // 0x8018A140: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018A144: lwc1        $f4, 0x6F04($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6F04);
    // 0x8018A148: lwc1        $f18, 0x0($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8018A14C: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8018A150: b           L_8018A16C
    // 0x8018A154: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
        goto L_8018A16C;
    // 0x8018A154: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
L_8018A158:
    // 0x8018A158: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018A15C: lwc1        $f10, 0x6F08($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6F08);
    // 0x8018A160: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8018A164: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8018A168: swc1        $f16, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f16.u32l;
L_8018A16C:
    // 0x8018A16C: addiu       $at, $zero, 0x104
    ctx->r1 = ADD32(0, 0X104);
    // 0x8018A170: bne         $v0, $at, L_8018A180
    if (ctx->r2 != ctx->r1) {
        // 0x8018A174: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_8018A180;
    }
    // 0x8018A174: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8018A178: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018A17C: sw          $t4, -0x796C($at)
    MEM_W(-0X796C, ctx->r1) = ctx->r12;
L_8018A180:
    // 0x8018A180: addiu       $at, $zero, 0x2EE
    ctx->r1 = ADD32(0, 0X2EE);
    // 0x8018A184: bne         $v0, $at, L_8018A1B8
    if (ctx->r2 != ctx->r1) {
        // 0x8018A188: lui         $v1, 0x8018
        ctx->r3 = S32(0X8018 << 16);
            goto L_8018A1B8;
    }
    // 0x8018A188: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x8018A18C: addiu       $v1, $v1, -0x7CC0
    ctx->r3 = ADD32(ctx->r3, -0X7CC0);
    // 0x8018A190: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x8018A194: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018A198: sw          $zero, -0x7CB8($at)
    MEM_W(-0X7CB8, ctx->r1) = 0;
    // 0x8018A19C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018A1A0: sw          $zero, -0x7CB0($at)
    MEM_W(-0X7CB0, ctx->r1) = 0;
    // 0x8018A1A4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018A1A8: sw          $zero, -0x7CAC($at)
    MEM_W(-0X7CAC, ctx->r1) = 0;
    // 0x8018A1AC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018A1B0: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8018A1B4: sw          $t5, -0x7964($at)
    MEM_W(-0X7964, ctx->r1) = ctx->r13;
L_8018A1B8:
    // 0x8018A1B8: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x8018A1BC: addiu       $v1, $v1, -0x7CC0
    ctx->r3 = ADD32(ctx->r3, -0X7CC0);
    // 0x8018A1C0: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8018A1C4: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8018A1C8: bne         $t6, $at, L_8018A218
    if (ctx->r14 != ctx->r1) {
        // 0x8018A1CC: lui         $a0, 0x801C
        ctx->r4 = S32(0X801C << 16);
            goto L_8018A218;
    }
    // 0x8018A1CC: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8018A1D0: lui         $a1, 0x1103
    ctx->r5 = S32(0X1103 << 16);
    // 0x8018A1D4: ori         $a1, $a1, 0x10
    ctx->r5 = ctx->r5 | 0X10;
    // 0x8018A1D8: jal         0x8001A55C
    // 0x8018A1DC: addiu       $a0, $a0, -0x7984
    ctx->r4 = ADD32(ctx->r4, -0X7984);
    Audio_KillSfxBySourceAndId(rdram, ctx);
        goto after_17;
    // 0x8018A1DC: addiu       $a0, $a0, -0x7984
    ctx->r4 = ADD32(ctx->r4, -0X7984);
    after_17:
    // 0x8018A1E0: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8018A1E4: lui         $a1, 0x3102
    ctx->r5 = S32(0X3102 << 16);
    // 0x8018A1E8: ori         $a1, $a1, 0x4059
    ctx->r5 = ctx->r5 | 0X4059;
    // 0x8018A1EC: jal         0x8001A55C
    // 0x8018A1F0: addiu       $a0, $a0, -0x7984
    ctx->r4 = ADD32(ctx->r4, -0X7984);
    Audio_KillSfxBySourceAndId(rdram, ctx);
        goto after_18;
    // 0x8018A1F0: addiu       $a0, $a0, -0x7984
    ctx->r4 = ADD32(ctx->r4, -0X7984);
    after_18:
    // 0x8018A1F4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018A1F8: sw          $zero, -0x7D40($at)
    MEM_W(-0X7D40, ctx->r1) = 0;
    // 0x8018A1FC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018A200: sw          $zero, 0x7898($at)
    MEM_W(0X7898, ctx->r1) = 0;
    // 0x8018A204: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018A208: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8018A20C: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8018A210: lw          $v0, -0x7D4C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D4C);
    // 0x8018A214: sw          $t7, -0x7D3C($at)
    MEM_W(-0X7D3C, ctx->r1) = ctx->r15;
L_8018A218:
    // 0x8018A218: addiu       $t8, $v0, 0x1
    ctx->r24 = ADD32(ctx->r2, 0X1);
    // 0x8018A21C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018A220: sw          $t8, -0x7D4C($at)
    MEM_W(-0X7D4C, ctx->r1) = ctx->r24;
L_8018A224:
    // 0x8018A224: jal         0x801912A0
    // 0x8018A228: nop

    Title_ScreenFade_Update(rdram, ctx);
        goto after_19;
    // 0x8018A228: nop

    after_19:
    // 0x8018A22C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018A230: lwc1        $f12, -0x7938($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X7938);
    // 0x8018A234: lui         $t9, 0x801C
    ctx->r25 = S32(0X801C << 16);
    // 0x8018A238: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x8018A23C: addiu       $t0, $t0, -0x7D18
    ctx->r8 = ADD32(ctx->r8, -0X7D18);
    // 0x8018A240: addiu       $t9, $t9, -0x7D1C
    ctx->r25 = ADD32(ctx->r25, -0X7D1C);
    // 0x8018A244: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018A248: lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // 0x8018A24C: addiu       $a3, $a3, -0x7D20
    ctx->r7 = ADD32(ctx->r7, -0X7D20);
    // 0x8018A250: lwc1        $f14, -0x7934($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X7934);
    // 0x8018A254: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8018A258: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8018A25C: jal         0x80191674
    // 0x8018A260: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    Title_SetLightRot(rdram, ctx);
        goto after_20;
    // 0x8018A260: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    after_20:
    // 0x8018A264: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018A268: lwc1        $f0, 0x7BE8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X7BE8);
    // 0x8018A26C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8018A270: nop

    // 0x8018A274: c.eq.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl == ctx->f0.fl;
    // 0x8018A278: nop

    // 0x8018A27C: bc1t        L_8018A2C4
    if (c1cs) {
        // 0x8018A280: lui         $at, 0x8017
        ctx->r1 = S32(0X8017 << 16);
            goto L_8018A2C4;
    }
    // 0x8018A280: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018A284: lwc1        $f12, 0x7978($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X7978);
    // 0x8018A288: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018A28C: lwc1        $f14, 0x7980($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X7980);
    // 0x8018A290: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018A294: lwc1        $f4, 0x79B8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X79B8);
    // 0x8018A298: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018A29C: lwc1        $f6, 0x79C0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X79C0);
    // 0x8018A2A0: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x8018A2A4: lui         $a3, 0x8017
    ctx->r7 = S32(0X8017 << 16);
    // 0x8018A2A8: lw          $a3, 0x79A0($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X79A0);
    // 0x8018A2AC: lw          $a2, 0x7988($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7988);
    // 0x8018A2B0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8018A2B4: jal         0x800B6F50
    // 0x8018A2B8: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    Camera_SetStarfieldPos(rdram, ctx);
        goto after_21;
    // 0x8018A2B8: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_21:
    // 0x8018A2BC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018A2C0: lwc1        $f0, 0x7BE8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X7BE8);
L_8018A2C4:
    // 0x8018A2C4: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8018A2C8: addiu       $v0, $v0, -0x7BD4
    ctx->r2 = ADD32(ctx->r2, -0X7BD4);
    // 0x8018A2CC: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8018A2D0: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8018A2D4: addiu       $v1, $v1, -0x7D48
    ctx->r3 = ADD32(ctx->r3, -0X7D48);
    // 0x8018A2D8: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x8018A2DC: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x8018A2E0: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x8018A2E4: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
    // 0x8018A2E8: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x8018A2EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8018A2F0: jr          $ra
    // 0x8018A2F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8018A2F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void Option_RankingMenu2_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019752C: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80197530: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x80197534: sw          $s3, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r19;
    // 0x80197538: sw          $s2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r18;
    // 0x8019753C: sw          $s1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r17;
    // 0x80197540: sw          $s0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r16;
    // 0x80197544: sdc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X48, ctx->r29);
    // 0x80197548: sdc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X40, ctx->r29);
    // 0x8019754C: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x80197550: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x80197554: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x80197558: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8019755C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80197560: lwc1        $f20, -0x6E2C($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X6E2C);
    // 0x80197564: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80197568: lwc1        $f22, -0x6E28($at)
    ctx->f22.u32l = MEM_W(ctx->r1, -0X6E28);
    // 0x8019756C: lui         $at, 0x41D0
    ctx->r1 = S32(0X41D0 << 16);
    // 0x80197570: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x80197574: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x80197578: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x8019757C: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80197580: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80197584: lui         $at, 0x428A
    ctx->r1 = S32(0X428A << 16);
    // 0x80197588: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x8019758C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80197590: addiu       $s3, $zero, 0xA
    ctx->r19 = ADD32(0, 0XA);
L_80197594:
    // 0x80197594: c.lt.s      $f24, $f20
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f24.fl < ctx->f20.fl;
    // 0x80197598: nop

    // 0x8019759C: bc1fl       L_80197640
    if (!c1cs) {
        // 0x801975A0: mfc1        $a1, $f20
        ctx->r5 = (int32_t)ctx->f20.u32l;
            goto L_80197640;
    }
    goto skip_0;
    // 0x801975A0: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    skip_0:
    // 0x801975A4: c.lt.s      $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f20.fl < ctx->f26.fl;
    // 0x801975A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801975AC: bc1fl       L_80197640
    if (!c1cs) {
        // 0x801975B0: mfc1        $a1, $f20
        ctx->r5 = (int32_t)ctx->f20.u32l;
            goto L_80197640;
    }
    goto skip_1;
    // 0x801975B0: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    skip_1:
    // 0x801975B4: trunc.w.s   $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    ctx->f4.u32l = TRUNC_W_S(ctx->f20.fl);
    // 0x801975B8: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x801975BC: addiu       $t7, $t7, -0x7790
    ctx->r15 = ADD32(ctx->r15, -0X7790);
    // 0x801975C0: addu        $s2, $s0, $t7
    ctx->r18 = ADD32(ctx->r16, ctx->r15);
    // 0x801975C4: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x801975C8: jal         0x80197A3C
    // 0x801975CC: addiu       $a1, $zero, 0x29
    ctx->r5 = ADD32(0, 0X29);
    Option_OrdinalNumbers_Draw(rdram, ctx);
        goto after_0;
    // 0x801975CC: addiu       $a1, $zero, 0x29
    ctx->r5 = ADD32(0, 0X29);
    after_0:
    // 0x801975D0: sub.s       $f6, $f20, $f28
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f6.fl = ctx->f20.fl - ctx->f28.fl;
    // 0x801975D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801975D8: addiu       $a1, $zero, 0x4B
    ctx->r5 = ADD32(0, 0X4B);
    // 0x801975DC: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x801975E0: mfc1        $s1, $f8
    ctx->r17 = (int32_t)ctx->f8.u32l;
    // 0x801975E4: jal         0x80197D30
    // 0x801975E8: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    Option_RankingName_Draw(rdram, ctx);
        goto after_1;
    // 0x801975E8: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_1:
    // 0x801975EC: sub.s       $f10, $f20, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f10.fl = ctx->f20.fl - ctx->f30.fl;
    // 0x801975F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801975F4: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    // 0x801975F8: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x801975FC: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80197600: jal         0x80197DE4
    // 0x80197604: nop

    Option_RankingTotalHits_Draw(rdram, ctx);
        goto after_2;
    // 0x80197604: nop

    after_2:
    // 0x80197608: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x8019760C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80197610: addiu       $a0, $zero, 0xD2
    ctx->r4 = ADD32(0, 0XD2);
    // 0x80197614: lbu         $a2, 0x40($s2)
    ctx->r6 = MEM_BU(ctx->r18, 0X40);
    // 0x80197618: sub.s       $f4, $f20, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f20.fl - ctx->f18.fl;
    // 0x8019761C: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80197620: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80197624: jal         0x801AD7EC
    // 0x80197628: nop

    Map_RemainingLives_Draw(rdram, ctx);
        goto after_3;
    // 0x80197628: nop

    after_3:
    // 0x8019762C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80197630: addiu       $a1, $zero, 0x102
    ctx->r5 = ADD32(0, 0X102);
    // 0x80197634: jal         0x80197F74
    // 0x80197638: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    Option_RankingTeamAlive_Draw(rdram, ctx);
        goto after_4;
    // 0x80197638: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_4:
    // 0x8019763C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
L_80197640:
    // 0x80197640: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x80197644: jal         0x80198164
    // 0x80197648: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Option_RankingRoute_Draw(rdram, ctx);
        goto after_5;
    // 0x80197648: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8019764C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80197650: lwc1        $f0, -0xF0C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0XF0C);
    // 0x80197654: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80197658: add.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f0.fl;
    // 0x8019765C: bne         $s0, $s3, L_80197594
    if (ctx->r16 != ctx->r19) {
        // 0x80197660: sub.s       $f22, $f22, $f0
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = ctx->f22.fl - ctx->f0.fl;
            goto L_80197594;
    }
    // 0x80197660: sub.s       $f22, $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = ctx->f22.fl - ctx->f0.fl;
    // 0x80197664: jal         0x8019BDF0
    // 0x80197668: nop

    Option_Menu_Push(rdram, ctx);
        goto after_6;
    // 0x80197668: nop

    after_6:
    // 0x8019766C: jal         0x80197914
    // 0x80197670: nop

    Option_80197914(rdram, ctx);
        goto after_7;
    // 0x80197670: nop

    after_7:
    // 0x80197674: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80197678: jal         0x80005740
    // 0x8019767C: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Pop(rdram, ctx);
        goto after_8;
    // 0x8019767C: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_8:
    // 0x80197680: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80197684: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x80197688: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8019768C: jal         0x800B8DD0
    // 0x80197690: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    RCP_SetupDL(rdram, ctx);
        goto after_9;
    // 0x80197690: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    after_9:
    // 0x80197694: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80197698: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8019769C: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x801976A0: lui         $s2, 0x801
    ctx->r18 = S32(0X801 << 16);
    // 0x801976A4: lui         $s3, 0x801B
    ctx->r19 = S32(0X801B << 16);
    // 0x801976A8: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x801976AC: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x801976B0: addiu       $s3, $s3, -0xF08
    ctx->r19 = ADD32(ctx->r19, -0XF08);
    // 0x801976B4: addiu       $s2, $s2, -0x2E90
    ctx->r18 = ADD32(ctx->r18, -0X2E90);
    // 0x801976B8: lui         $s1, 0xFA00
    ctx->r17 = S32(0XFA00 << 16);
    // 0x801976BC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801976C0: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x801976C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801976C8: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x801976CC: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x801976D0: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x801976D4: sw          $s1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r17;
    // 0x801976D8: lwc1        $f8, 0x0($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X0);
    // 0x801976DC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x801976E0: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x801976E4: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x801976E8: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x801976EC: swc1        $f22, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f22.u32l;
    // 0x801976F0: swc1        $f24, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f24.u32l;
    // 0x801976F4: jal         0x8009D994
    // 0x801976F8: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_10;
    // 0x801976F8: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_10:
    // 0x801976FC: lwc1        $f10, 0x4($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X4);
    // 0x80197700: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80197704: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80197708: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x8019770C: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x80197710: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x80197714: swc1        $f22, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f22.u32l;
    // 0x80197718: swc1        $f24, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f24.u32l;
    // 0x8019771C: jal         0x8009E4B0
    // 0x80197720: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    Lib_TextureRect_IA8_MirY(rdram, ctx);
        goto after_11;
    // 0x80197720: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_11:
    // 0x80197724: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80197728: jal         0x8003DE68
    // 0x8019772C: addiu       $a1, $zero, 0x46
    ctx->r5 = ADD32(0, 0X46);
    Background_DrawPartialStarfield(rdram, ctx);
        goto after_12;
    // 0x8019772C: addiu       $a1, $zero, 0x46
    ctx->r5 = ADD32(0, 0X46);
    after_12:
    // 0x80197730: addiu       $a0, $zero, 0xAA
    ctx->r4 = ADD32(0, 0XAA);
    // 0x80197734: jal         0x8003DE68
    // 0x80197738: addiu       $a1, $zero, 0xEF
    ctx->r5 = ADD32(0, 0XEF);
    Background_DrawPartialStarfield(rdram, ctx);
        goto after_13;
    // 0x80197738: addiu       $a1, $zero, 0xEF
    ctx->r5 = ADD32(0, 0XEF);
    after_13:
    // 0x8019773C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80197740: jal         0x800B8DD0
    // 0x80197744: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    RCP_SetupDL(rdram, ctx);
        goto after_14;
    // 0x80197744: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    after_14:
    // 0x80197748: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019774C: lwc1        $f16, -0x6E2C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X6E2C);
    // 0x80197750: lui         $at, 0x42E4
    ctx->r1 = S32(0X42E4 << 16);
    // 0x80197754: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80197758: lui         $s2, 0x801C
    ctx->r18 = S32(0X801C << 16);
    // 0x8019775C: addiu       $s2, $s2, -0x6C0C
    ctx->r18 = ADD32(ctx->r18, -0X6C0C);
    // 0x80197760: c.le.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl <= ctx->f16.fl;
    // 0x80197764: nop

    // 0x80197768: bc1f        L_80197794
    if (!c1cs) {
        // 0x8019776C: nop
    
            goto L_80197794;
    }
    // 0x8019776C: nop

    // 0x80197770: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80197774: lui         $t4, 0x2020
    ctx->r12 = S32(0X2020 << 16);
    // 0x80197778: ori         $t4, $t4, 0x20FF
    ctx->r12 = ctx->r12 | 0X20FF;
    // 0x8019777C: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x80197780: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x80197784: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80197788: sw          $s1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r17;
    // 0x8019778C: b           L_801977E0
    // 0x80197790: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
        goto L_801977E0;
    // 0x80197790: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_80197794:
    // 0x80197794: jal         0x8019C824
    // 0x80197798: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Option_Color_FlashRed(rdram, ctx);
        goto after_15;
    // 0x80197798: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_15:
    // 0x8019779C: lwc1        $f4, 0x0($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X0);
    // 0x801977A0: lui         $at, 0xFF00
    ctx->r1 = S32(0XFF00 << 16);
    // 0x801977A4: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x801977A8: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x801977AC: nop

    // 0x801977B0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801977B4: andi        $a0, $a1, 0xFF
    ctx->r4 = ctx->r5 & 0XFF;
    // 0x801977B8: sll         $t7, $a0, 16
    ctx->r15 = S32(ctx->r4 << 16);
    // 0x801977BC: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x801977C0: sll         $t9, $a0, 8
    ctx->r25 = S32(ctx->r4 << 8);
    // 0x801977C4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801977C8: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x801977CC: or          $t0, $t8, $t9
    ctx->r8 = ctx->r24 | ctx->r25;
    // 0x801977D0: ori         $t1, $t0, 0xFF
    ctx->r9 = ctx->r8 | 0XFF;
    // 0x801977D4: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x801977D8: sw          $s1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r17;
    // 0x801977DC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_801977E0:
    // 0x801977E0: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x801977E4: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x801977E8: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x801977EC: lui         $at, 0x4230
    ctx->r1 = S32(0X4230 << 16);
    // 0x801977F0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801977F4: lui         $s3, 0x801
    ctx->r19 = S32(0X801 << 16);
    // 0x801977F8: addiu       $s3, $s3, -0x2F90
    ctx->r19 = ADD32(ctx->r19, -0X2F90);
    // 0x801977FC: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80197800: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80197804: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80197808: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x8019780C: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x80197810: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80197814: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    // 0x80197818: jal         0x8009D994
    // 0x8019781C: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_16;
    // 0x8019781C: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_16:
    // 0x80197820: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80197824: lwc1        $f10, 0x73E0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X73E0);
    // 0x80197828: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019782C: lwc1        $f16, -0x6E2C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X6E2C);
    // 0x80197830: lui         $s2, 0x801C
    ctx->r18 = S32(0X801C << 16);
    // 0x80197834: addiu       $s2, $s2, -0x6C08
    ctx->r18 = ADD32(ctx->r18, -0X6C08);
    // 0x80197838: c.le.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl <= ctx->f10.fl;
    // 0x8019783C: nop

    // 0x80197840: bc1f        L_8019786C
    if (!c1cs) {
        // 0x80197844: nop
    
            goto L_8019786C;
    }
    // 0x80197844: nop

    // 0x80197848: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8019784C: lui         $t3, 0x2020
    ctx->r11 = S32(0X2020 << 16);
    // 0x80197850: ori         $t3, $t3, 0x20FF
    ctx->r11 = ctx->r11 | 0X20FF;
    // 0x80197854: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x80197858: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x8019785C: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x80197860: sw          $s1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r17;
    // 0x80197864: b           L_801978B8
    // 0x80197868: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
        goto L_801978B8;
    // 0x80197868: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
L_8019786C:
    // 0x8019786C: jal         0x8019C824
    // 0x80197870: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Option_Color_FlashRed(rdram, ctx);
        goto after_17;
    // 0x80197870: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_17:
    // 0x80197874: lwc1        $f18, 0x0($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X0);
    // 0x80197878: lui         $at, 0xFF00
    ctx->r1 = S32(0XFF00 << 16);
    // 0x8019787C: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80197880: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80197884: nop

    // 0x80197888: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8019788C: andi        $a0, $a1, 0xFF
    ctx->r4 = ctx->r5 & 0XFF;
    // 0x80197890: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x80197894: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x80197898: sll         $t8, $a0, 8
    ctx->r24 = S32(ctx->r4 << 8);
    // 0x8019789C: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x801978A0: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x801978A4: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x801978A8: ori         $t0, $t9, 0xFF
    ctx->r8 = ctx->r25 | 0XFF;
    // 0x801978AC: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x801978B0: sw          $s1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r17;
    // 0x801978B4: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
L_801978B8:
    // 0x801978B8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801978BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801978C0: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x801978C4: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x801978C8: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x801978CC: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    // 0x801978D0: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x801978D4: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x801978D8: jal         0x8009E4B0
    // 0x801978DC: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    Lib_TextureRect_IA8_MirY(rdram, ctx);
        goto after_18;
    // 0x801978DC: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_18:
    // 0x801978E0: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x801978E4: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x801978E8: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x801978EC: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x801978F0: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x801978F4: ldc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X40);
    // 0x801978F8: ldc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X48);
    // 0x801978FC: lw          $s0, 0x54($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X54);
    // 0x80197900: lw          $s1, 0x58($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X58);
    // 0x80197904: lw          $s2, 0x5C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X5C);
    // 0x80197908: lw          $s3, 0x60($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X60);
    // 0x8019790C: jr          $ra
    // 0x80197910: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80197910: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void Title_GreatFox_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018E058: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8018E05C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8018E060: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x8018E064: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x8018E068: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018E06C: lwc1        $f4, -0x7D20($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7D20);
    // 0x8018E070: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018E074: lwc1        $f8, -0x7D1C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X7D1C);
    // 0x8018E078: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018E07C: lwc1        $f16, -0x7D18($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X7D18);
    // 0x8018E080: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8018E084: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8018E088: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8018E08C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8018E090: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8018E094: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8018E098: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8018E09C: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8018E0A0: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8018E0A4: lw          $t4, -0x7AA4($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7AA4);
    // 0x8018E0A8: lw          $t3, -0x7AA8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X7AA8);
    // 0x8018E0AC: lw          $t2, -0x7AAC($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X7AAC);
    // 0x8018E0B0: lw          $t1, -0x7AB0($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X7AB0);
    // 0x8018E0B4: lw          $t0, -0x7AB4($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7AB4);
    // 0x8018E0B8: lw          $t9, -0x7AB8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7AB8);
    // 0x8018E0BC: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x8018E0C0: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x8018E0C4: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8018E0C8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8018E0CC: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8018E0D0: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    // 0x8018E0D4: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    // 0x8018E0D8: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x8018E0DC: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x8018E0E0: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8018E0E4: jal         0x8000372C
    // 0x8018E0E8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    Lights_SetOneLight(rdram, ctx);
        goto after_0;
    // 0x8018E0E8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_0:
    // 0x8018E0EC: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x8018E0F0: addiu       $s1, $s1, -0x4C40
    ctx->r17 = ADD32(ctx->r17, -0X4C40);
    // 0x8018E0F4: jal         0x80005708
    // 0x8018E0F8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Push(rdram, ctx);
        goto after_1;
    // 0x8018E0F8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x8018E0FC: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x8018E100: addiu       $s0, $s0, -0x79A8
    ctx->r16 = ADD32(ctx->r16, -0X79A8);
    // 0x8018E104: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8018E108: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8018E10C: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x8018E110: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    // 0x8018E114: lw          $a3, 0x8($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X8);
    // 0x8018E118: jal         0x80005B00
    // 0x8018E11C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_2;
    // 0x8018E11C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_2:
    // 0x8018E120: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018E124: lwc1        $f4, 0x7060($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7060);
    // 0x8018E128: lwc1        $f6, 0x18($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8018E12C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8018E130: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018E134: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8018E138: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8018E13C: jal         0x80005FE0
    // 0x8018E140: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_3;
    // 0x8018E140: nop

    after_3:
    // 0x8018E144: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018E148: lwc1        $f10, 0x7064($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7064);
    // 0x8018E14C: lwc1        $f16, 0x10($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8018E150: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8018E154: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018E158: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8018E15C: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8018E160: jal         0x80005D44
    // 0x8018E164: nop

    Matrix_RotateX(rdram, ctx);
        goto after_4;
    // 0x8018E164: nop

    after_4:
    // 0x8018E168: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018E16C: lwc1        $f4, 0x7068($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7068);
    // 0x8018E170: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8018E174: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8018E178: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018E17C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8018E180: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8018E184: jal         0x80005E90
    // 0x8018E188: nop

    Matrix_RotateY(rdram, ctx);
        goto after_5;
    // 0x8018E188: nop

    after_5:
    // 0x8018E18C: lwc1        $f0, 0x1C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x8018E190: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8018E194: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8018E198: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8018E19C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8018E1A0: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8018E1A4: jal         0x80005C34
    // 0x8018E1A8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_6;
    // 0x8018E1A8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_6:
    // 0x8018E1AC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8018E1B0: jal         0x80006EB8
    // 0x8018E1B4: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_7;
    // 0x8018E1B4: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    after_7:
    // 0x8018E1B8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8018E1BC: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8018E1C0: jal         0x800B8DD0
    // 0x8018E1C4: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    RCP_SetupDL(rdram, ctx);
        goto after_8;
    // 0x8018E1C4: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    after_8:
    // 0x8018E1C8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8018E1CC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018E1D0: jal         0x800515C4
    // 0x8018E1D4: sb          $t7, 0x7B8C($at)
    MEM_B(0X7B8C, ctx->r1) = ctx->r15;
    Cutscene_DrawGreatFox(rdram, ctx);
        goto after_9;
    // 0x8018E1D4: sb          $t7, 0x7B8C($at)
    MEM_B(0X7B8C, ctx->r1) = ctx->r15;
    after_9:
    // 0x8018E1D8: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8018E1DC: jal         0x8005F1EC
    // 0x8018E1E0: addiu       $a0, $a0, -0x7984
    ctx->r4 = ADD32(ctx->r4, -0X7984);
    Object_UpdateSfxSource(rdram, ctx);
        goto after_10;
    // 0x8018E1E0: addiu       $a0, $a0, -0x7984
    ctx->r4 = ADD32(ctx->r4, -0X7984);
    after_10:
    // 0x8018E1E4: jal         0x80005740
    // 0x8018E1E8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_11;
    // 0x8018E1E8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_11:
    // 0x8018E1EC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8018E1F0: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x8018E1F4: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x8018E1F8: jr          $ra
    // 0x8018E1FC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8018E1FC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void Map_GameOver(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019E85C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8019E860: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8019E864: addiu       $v1, $v1, 0x7868
    ctx->r3 = ADD32(ctx->r3, 0X7868);
    // 0x8019E868: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8019E86C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8019E870: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8019E874: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x8019E878: beq         $v0, $zero, L_8019E898
    if (ctx->r2 == 0) {
        // 0x8019E87C: nop
    
            goto L_8019E898;
    }
    // 0x8019E87C: nop

    // 0x8019E880: beq         $v0, $at, L_8019E8B0
    if (ctx->r2 == ctx->r1) {
        // 0x8019E884: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8019E8B0;
    }
    // 0x8019E884: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8019E888: beql        $v0, $at, L_8019E8BC
    if (ctx->r2 == ctx->r1) {
        // 0x8019E88C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8019E8BC;
    }
    goto skip_0;
    // 0x8019E88C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8019E890: b           L_8019E8BC
    // 0x8019E894: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8019E8BC;
    // 0x8019E894: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8019E898:
    // 0x8019E898: lw          $t6, 0x783C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X783C);
    // 0x8019E89C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8019E8A0: bnel        $t6, $zero, L_8019E8BC
    if (ctx->r14 != 0) {
        // 0x8019E8A4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8019E8BC;
    }
    goto skip_1;
    // 0x8019E8A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8019E8A8: b           L_8019E8B8
    // 0x8019E8AC: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
        goto L_8019E8B8;
    // 0x8019E8AC: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
L_8019E8B0:
    // 0x8019E8B0: jal         0x8019E800
    // 0x8019E8B4: nop

    Map_8019E800(rdram, ctx);
        goto after_0;
    // 0x8019E8B4: nop

    after_0:
L_8019E8B8:
    // 0x8019E8B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8019E8BC:
    // 0x8019E8BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8019E8C0: jr          $ra
    // 0x8019E8C4: nop

    return;
    // 0x8019E8C4: nop

;}
RECOMP_FUNC void Title_TeamName_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018FD08: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8018FD0C: sw          $s2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r18;
    // 0x8018FD10: sw          $s0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r16;
    // 0x8018FD14: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x8018FD18: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x8018FD1C: addiu       $s2, $s2, 0x7E64
    ctx->r18 = ADD32(ctx->r18, 0X7E64);
    // 0x8018FD20: addiu       $s0, $s0, -0x7CC0
    ctx->r16 = ADD32(ctx->r16, -0X7CC0);
    // 0x8018FD24: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8018FD28: sw          $s3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r19;
    // 0x8018FD2C: sw          $s1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r17;
    // 0x8018FD30: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x8018FD34: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x8018FD38: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8018FD3C: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x8018FD40: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018FD44: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8018FD48: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8018FD4C: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8018FD50: lwc1        $f24, -0x1B84($at)
    ctx->f24.u32l = MEM_W(ctx->r1, -0X1B84);
    // 0x8018FD54: jal         0x800B8DD0
    // 0x8018FD58: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x8018FD58: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    after_0:
    // 0x8018FD5C: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x8018FD60: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x8018FD64: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8018FD68: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8018FD6C: sw          $t8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r24;
    // 0x8018FD70: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x8018FD74: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8018FD78: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8018FD7C: lui         $a1, 0x601
    ctx->r5 = S32(0X601 << 16);
    // 0x8018FD80: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8018FD84: beq         $a0, $zero, L_8018FDB8
    if (ctx->r4 == 0) {
        // 0x8018FD88: addiu       $a1, $a1, -0x6C0
        ctx->r5 = ADD32(ctx->r5, -0X6C0);
            goto L_8018FDB8;
    }
    // 0x8018FD88: addiu       $a1, $a1, -0x6C0
    ctx->r5 = ADD32(ctx->r5, -0X6C0);
    // 0x8018FD8C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8018FD90: beq         $a0, $at, L_8018FDEC
    if (ctx->r4 == ctx->r1) {
        // 0x8018FD94: lui         $a1, 0x601
        ctx->r5 = S32(0X601 << 16);
            goto L_8018FDEC;
    }
    // 0x8018FD94: lui         $a1, 0x601
    ctx->r5 = S32(0X601 << 16);
    // 0x8018FD98: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8018FD9C: beq         $a0, $at, L_8018FE28
    if (ctx->r4 == ctx->r1) {
        // 0x8018FDA0: lui         $s1, 0x601
        ctx->r17 = S32(0X601 << 16);
            goto L_8018FE28;
    }
    // 0x8018FDA0: lui         $s1, 0x601
    ctx->r17 = S32(0X601 << 16);
    // 0x8018FDA4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8018FDA8: beq         $a0, $at, L_8018FEBC
    if (ctx->r4 == ctx->r1) {
        // 0x8018FDAC: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8018FEBC;
    }
    // 0x8018FDAC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8018FDB0: b           L_8018FF50
    // 0x8018FDB4: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
        goto L_8018FF50;
    // 0x8018FDB4: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_8018FDB8:
    // 0x8018FDB8: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8018FDBC: lui         $at, 0x4352
    ctx->r1 = S32(0X4352 << 16);
    // 0x8018FDC0: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8018FDC4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8018FDC8: addiu       $a2, $zero, 0x90
    ctx->r6 = ADD32(0, 0X90);
    // 0x8018FDCC: addiu       $a3, $zero, 0xD
    ctx->r7 = ADD32(0, 0XD);
    // 0x8018FDD0: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    // 0x8018FDD4: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x8018FDD8: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8018FDDC: jal         0x8009D994
    // 0x8018FDE0: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_1;
    // 0x8018FDE0: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    after_1:
    // 0x8018FDE4: b           L_8018FF50
    // 0x8018FDE8: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
        goto L_8018FF50;
    // 0x8018FDE8: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_8018FDEC:
    // 0x8018FDEC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8018FDF0: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8018FDF4: lui         $at, 0x4352
    ctx->r1 = S32(0X4352 << 16);
    // 0x8018FDF8: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8018FDFC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8018FE00: addiu       $a1, $a1, 0x90
    ctx->r5 = ADD32(ctx->r5, 0X90);
    // 0x8018FE04: addiu       $a2, $zero, 0x78
    ctx->r6 = ADD32(0, 0X78);
    // 0x8018FE08: addiu       $a3, $zero, 0xD
    ctx->r7 = ADD32(0, 0XD);
    // 0x8018FE0C: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    // 0x8018FE10: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x8018FE14: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8018FE18: jal         0x8009D994
    // 0x8018FE1C: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_2;
    // 0x8018FE1C: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    after_2:
    // 0x8018FE20: b           L_8018FF50
    // 0x8018FE24: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
        goto L_8018FF50;
    // 0x8018FE24: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_8018FE28:
    // 0x8018FE28: lui         $at, 0x4352
    ctx->r1 = S32(0X4352 << 16);
    // 0x8018FE2C: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8018FE30: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8018FE34: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8018FE38: addiu       $s1, $s1, 0x6B0
    ctx->r17 = ADD32(ctx->r17, 0X6B0);
    // 0x8018FE3C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8018FE40: addiu       $s3, $zero, 0xC
    ctx->r19 = ADD32(0, 0XC);
L_8018FE44:
    // 0x8018FE44: mtc1        $s0, $f4
    ctx->f4.u32l = ctx->r16;
    // 0x8018FE48: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8018FE4C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8018FE50: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8018FE54: addiu       $a2, $zero, 0xB0
    ctx->r6 = ADD32(0, 0XB0);
    // 0x8018FE58: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x8018FE5C: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    // 0x8018FE60: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x8018FE64: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8018FE68: add.s       $f8, $f6, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f22.fl;
    // 0x8018FE6C: jal         0x8009D994
    // 0x8018FE70: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_3;
    // 0x8018FE70: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_3:
    // 0x8018FE74: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8018FE78: bne         $s0, $s3, L_8018FE44
    if (ctx->r16 != ctx->r19) {
        // 0x8018FE7C: addiu       $s1, $s1, 0x2C0
        ctx->r17 = ADD32(ctx->r17, 0X2C0);
            goto L_8018FE44;
    }
    // 0x8018FE7C: addiu       $s1, $s1, 0x2C0
    ctx->r17 = ADD32(ctx->r17, 0X2C0);
    // 0x8018FE80: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x8018FE84: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018FE88: lui         $a1, 0x601
    ctx->r5 = S32(0X601 << 16);
    // 0x8018FE8C: addiu       $a1, $a1, 0xEF0
    ctx->r5 = ADD32(ctx->r5, 0XEF0);
    // 0x8018FE90: add.s       $f16, $f22, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f22.fl + ctx->f10.fl;
    // 0x8018FE94: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8018FE98: addiu       $a2, $zero, 0xB0
    ctx->r6 = ADD32(0, 0XB0);
    // 0x8018FE9C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8018FEA0: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x8018FEA4: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    // 0x8018FEA8: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x8018FEAC: jal         0x8009D994
    // 0x8018FEB0: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_4;
    // 0x8018FEB0: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    after_4:
    // 0x8018FEB4: b           L_8018FF50
    // 0x8018FEB8: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
        goto L_8018FF50;
    // 0x8018FEB8: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_8018FEBC:
    // 0x8018FEBC: lui         $at, 0x4352
    ctx->r1 = S32(0X4352 << 16);
    // 0x8018FEC0: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8018FEC4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8018FEC8: lui         $s1, 0x601
    ctx->r17 = S32(0X601 << 16);
    // 0x8018FECC: lui         $s3, 0x601
    ctx->r19 = S32(0X601 << 16);
    // 0x8018FED0: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8018FED4: addiu       $s3, $s3, 0x17E0
    ctx->r19 = ADD32(ctx->r19, 0X17E0);
    // 0x8018FED8: addiu       $s1, $s1, 0xFA0
    ctx->r17 = ADD32(ctx->r17, 0XFA0);
L_8018FEDC:
    // 0x8018FEDC: mtc1        $s0, $f18
    ctx->f18.u32l = ctx->r16;
    // 0x8018FEE0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8018FEE4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8018FEE8: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8018FEEC: addiu       $a2, $zero, 0xB0
    ctx->r6 = ADD32(0, 0XB0);
    // 0x8018FEF0: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x8018FEF4: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    // 0x8018FEF8: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x8018FEFC: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8018FF00: add.s       $f6, $f4, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f22.fl;
    // 0x8018FF04: jal         0x8009D994
    // 0x8018FF08: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_5;
    // 0x8018FF08: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_5:
    // 0x8018FF0C: addiu       $s1, $s1, 0x2C0
    ctx->r17 = ADD32(ctx->r17, 0X2C0);
    // 0x8018FF10: bne         $s1, $s3, L_8018FEDC
    if (ctx->r17 != ctx->r19) {
        // 0x8018FF14: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8018FEDC;
    }
    // 0x8018FF14: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8018FF18: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x8018FF1C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018FF20: lui         $a1, 0x601
    ctx->r5 = S32(0X601 << 16);
    // 0x8018FF24: addiu       $a1, $a1, 0x17E0
    ctx->r5 = ADD32(ctx->r5, 0X17E0);
    // 0x8018FF28: add.s       $f10, $f22, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f22.fl + ctx->f8.fl;
    // 0x8018FF2C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8018FF30: addiu       $a2, $zero, 0xB0
    ctx->r6 = ADD32(0, 0XB0);
    // 0x8018FF34: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8018FF38: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    // 0x8018FF3C: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    // 0x8018FF40: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x8018FF44: jal         0x8009D994
    // 0x8018FF48: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_6;
    // 0x8018FF48: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    after_6:
    // 0x8018FF4C: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_8018FF50:
    // 0x8018FF50: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8018FF54: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x8018FF58: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x8018FF5C: lw          $s0, 0x3C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X3C);
    // 0x8018FF60: lw          $s1, 0x40($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X40);
    // 0x8018FF64: lw          $s2, 0x44($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X44);
    // 0x8018FF68: lw          $s3, 0x48($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X48);
    // 0x8018FF6C: jr          $ra
    // 0x8018FF70: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8018FF70: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void Map_8019E8C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019E8C8: jr          $ra
    // 0x8019E8CC: nop

    return;
    // 0x8019E8CC: nop

;}
RECOMP_FUNC void Map_GoToGameOver(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A4F8C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801A4F90: sw          $zero, -0x7BF0($at)
    MEM_W(-0X7BF0, ctx->r1) = 0;
    // 0x801A4F94: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801A4F98: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x801A4F9C: sw          $t6, 0x7834($at)
    MEM_W(0X7834, ctx->r1) = ctx->r14;
    // 0x801A4FA0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801A4FA4: sw          $zero, 0x7868($at)
    MEM_W(0X7868, ctx->r1) = 0;
    // 0x801A4FA8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801A4FAC: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x801A4FB0: sw          $t7, 0x783C($at)
    MEM_W(0X783C, ctx->r1) = ctx->r15;
    // 0x801A4FB4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801A4FB8: sw          $zero, 0x7898($at)
    MEM_W(0X7898, ctx->r1) = 0;
    // 0x801A4FBC: jr          $ra
    // 0x801A4FC0: nop

    return;
    // 0x801A4FC0: nop

;}
RECOMP_FUNC void Title_CheckControllers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80187ABC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80187AC0: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x80187AC4: addiu       $a0, $a0, -0x2750
    ctx->r4 = ADD32(ctx->r4, -0X2750);
    // 0x80187AC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80187ACC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80187AD0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80187AD4:
    // 0x80187AD4: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x80187AD8: bnel        $a1, $t6, L_80187AEC
    if (ctx->r5 != ctx->r14) {
        // 0x80187ADC: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_80187AEC;
    }
    goto skip_0;
    // 0x80187ADC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_0:
    // 0x80187AE0: b           L_80187AF4
    // 0x80187AE4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_80187AF4;
    // 0x80187AE4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80187AE8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_80187AEC:
    // 0x80187AEC: bne         $v0, $a2, L_80187AD4
    if (ctx->r2 != ctx->r6) {
        // 0x80187AF0: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_80187AD4;
    }
    // 0x80187AF0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_80187AF4:
    // 0x80187AF4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80187AF8: jr          $ra
    // 0x80187AFC: nop

    return;
    // 0x80187AFC: nop

;}
RECOMP_FUNC void Option_Ranking2_Cursor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019715C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80197160: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80197164: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x80197168: lw          $t6, -0x6E30($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6E30);
    // 0x8019716C: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80197170: addiu       $a0, $a0, -0x6E28
    ctx->r4 = ADD32(ctx->r4, -0X6E28);
    // 0x80197174: beq         $t6, $zero, L_80197264
    if (ctx->r14 == 0) {
        // 0x80197178: lui         $a1, 0x801C
        ctx->r5 = S32(0X801C << 16);
            goto L_80197264;
    }
    // 0x80197178: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x8019717C: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x80197180: lw          $t0, 0x7AF8($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7AF8);
    // 0x80197184: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x80197188: addiu       $t1, $t1, -0x6BF8
    ctx->r9 = ADD32(ctx->r9, -0X6BF8);
    // 0x8019718C: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80197190: addiu       $t7, $zero, 0x14
    ctx->r15 = ADD32(0, 0X14);
    // 0x80197194: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80197198: addiu       $t9, $zero, 0x9
    ctx->r25 = ADD32(0, 0X9);
    // 0x8019719C: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x801971A0: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x801971A4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801971A8: addiu       $a0, $a0, -0x6C1C
    ctx->r4 = ADD32(ctx->r4, -0X6C1C);
    // 0x801971AC: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x801971B0: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x801971B4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801971B8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801971BC: jal         0x8019C418
    // 0x801971C0: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    Option_Input_MoveCursor_Y(rdram, ctx);
        goto after_0;
    // 0x801971C0: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    after_0:
    // 0x801971C4: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x801971C8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801971CC: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x801971D0: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801971D4: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x801971D8: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x801971DC: lui         $t2, 0x800C
    ctx->r10 = S32(0X800C << 16);
    // 0x801971E0: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x801971E4: addiu       $t2, $t2, 0x5D3C
    ctx->r10 = ADD32(ctx->r10, 0X5D3C);
    // 0x801971E8: c.eq.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl == ctx->f8.fl;
    // 0x801971EC: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x801971F0: ori         $a0, $a0, 0x2
    ctx->r4 = ctx->r4 | 0X2;
    // 0x801971F4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x801971F8: bc1t        L_80197258
    if (c1cs) {
        // 0x801971FC: nop
    
            goto L_80197258;
    }
    // 0x801971FC: nop

    // 0x80197200: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80197204: jal         0x80019218
    // 0x80197208: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    Audio_PlaySfx(rdram, ctx);
        goto after_1;
    // 0x80197208: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    after_1:
    // 0x8019720C: lui         $t3, 0x801C
    ctx->r11 = S32(0X801C << 16);
    // 0x80197210: lw          $t3, -0x6C1C($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X6C1C);
    // 0x80197214: lui         $at, 0x4302
    ctx->r1 = S32(0X4302 << 16);
    // 0x80197218: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8019721C: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x80197220: lui         $at, 0x42E4
    ctx->r1 = S32(0X42E4 << 16);
    // 0x80197224: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80197228: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8019722C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80197230: mul.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80197234: sub.s       $f4, $f6, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x80197238: swc1        $f4, -0x6E24($at)
    MEM_W(-0X6E24, ctx->r1) = ctx->f4.u32l;
    // 0x8019723C: lui         $at, 0xC0C0
    ctx->r1 = S32(0XC0C0 << 16);
    // 0x80197240: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80197244: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80197248: add.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x8019724C: swc1        $f10, -0x6E20($at)
    MEM_W(-0X6E20, ctx->r1) = ctx->f10.u32l;
    // 0x80197250: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80197254: sw          $zero, -0x6E30($at)
    MEM_W(-0X6E30, ctx->r1) = 0;
L_80197258:
    // 0x80197258: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8019725C: b           L_801972E4
    // 0x80197260: addiu       $a0, $a0, -0x6E2C
    ctx->r4 = ADD32(ctx->r4, -0X6E2C);
        goto L_801972E4;
    // 0x80197260: addiu       $a0, $a0, -0x6E2C
    ctx->r4 = ADD32(ctx->r4, -0X6E2C);
L_80197264:
    // 0x80197264: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80197268: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8019726C: lw          $a1, -0x6E20($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X6E20);
    // 0x80197270: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    // 0x80197274: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x80197278: jal         0x8009BC2C
    // 0x8019727C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_2;
    // 0x8019727C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_2:
    // 0x80197280: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80197284: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80197288: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8019728C: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x80197290: addiu       $a0, $a0, -0x6E2C
    ctx->r4 = ADD32(ctx->r4, -0X6E2C);
    // 0x80197294: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x80197298: lw          $a1, -0x6E24($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X6E24);
    // 0x8019729C: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    // 0x801972A0: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x801972A4: jal         0x8009BC2C
    // 0x801972A8: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_3;
    // 0x801972A8: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_3:
    // 0x801972AC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x801972B0: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x801972B4: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801972B8: addiu       $a0, $a0, -0x6E2C
    ctx->r4 = ADD32(ctx->r4, -0X6E2C);
    // 0x801972BC: c.eq.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl == ctx->f2.fl;
    // 0x801972C0: nop

    // 0x801972C4: bc1fl       L_801972E8
    if (!c1cs) {
        // 0x801972C8: lwc1        $f4, 0x0($a0)
        ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
            goto L_801972E8;
    }
    goto skip_0;
    // 0x801972C8: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    skip_0:
    // 0x801972CC: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    // 0x801972D0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801972D4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801972D8: bc1fl       L_801972E8
    if (!c1cs) {
        // 0x801972DC: lwc1        $f4, 0x0($a0)
        ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
            goto L_801972E8;
    }
    goto skip_1;
    // 0x801972DC: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    skip_1:
    // 0x801972E0: sw          $t4, -0x6E30($at)
    MEM_W(-0X6E30, ctx->r1) = ctx->r12;
L_801972E4:
    // 0x801972E4: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
L_801972E8:
    // 0x801972E8: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801972EC: addiu       $a1, $a1, -0x6E28
    ctx->r5 = ADD32(ctx->r5, -0X6E28);
    // 0x801972F0: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x801972F4: lwc1        $f10, 0x0($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X0);
    // 0x801972F8: lui         $at, 0x42E4
    ctx->r1 = S32(0X42E4 << 16);
    // 0x801972FC: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x80197300: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80197304: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80197308: mtc1        $v0, $f18
    ctx->f18.u32l = ctx->r2;
    // 0x8019730C: lui         $at, 0x42E4
    ctx->r1 = S32(0X42E4 << 16);
    // 0x80197310: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    // 0x80197314: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80197318: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x8019731C: nop

    // 0x80197320: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80197324: swc1        $f6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f6.u32l;
    // 0x80197328: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8019732C: c.le.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl <= ctx->f0.fl;
    // 0x80197330: swc1        $f8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f8.u32l;
    // 0x80197334: bc1fl       L_80197350
    if (!c1cs) {
        // 0x80197338: lui         $at, 0xC484
        ctx->r1 = S32(0XC484 << 16);
            goto L_80197350;
    }
    goto skip_2;
    // 0x80197338: lui         $at, 0xC484
    ctx->r1 = S32(0XC484 << 16);
    skip_2:
    // 0x8019733C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80197340: nop

    // 0x80197344: swc1        $f16, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f16.u32l;
    // 0x80197348: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8019734C: lui         $at, 0xC484
    ctx->r1 = S32(0XC484 << 16);
L_80197350:
    // 0x80197350: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80197354: lui         $at, 0xC0C0
    ctx->r1 = S32(0XC0C0 << 16);
    // 0x80197358: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8019735C: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x80197360: lui         $at, 0xC0C0
    ctx->r1 = S32(0XC0C0 << 16);
    // 0x80197364: bc1fl       L_80197374
    if (!c1cs) {
        // 0x80197368: lwc1        $f0, 0x0($a1)
        ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
            goto L_80197374;
    }
    goto skip_3;
    // 0x80197368: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    skip_3:
    // 0x8019736C: swc1        $f2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f2.u32l;
    // 0x80197370: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
L_80197374:
    // 0x80197374: c.le.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl <= ctx->f18.fl;
    // 0x80197378: nop

    // 0x8019737C: bc1f        L_80197394
    if (!c1cs) {
        // 0x80197380: nop
    
            goto L_80197394;
    }
    // 0x80197380: nop

    // 0x80197384: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80197388: nop

    // 0x8019738C: swc1        $f6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f6.u32l;
    // 0x80197390: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
L_80197394:
    // 0x80197394: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80197398: lwc1        $f2, 0x73DC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X73DC);
    // 0x8019739C: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x801973A0: nop

    // 0x801973A4: bc1fl       L_801973B4
    if (!c1cs) {
        // 0x801973A8: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_801973B4;
    }
    goto skip_4;
    // 0x801973A8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_4:
    // 0x801973AC: swc1        $f2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f2.u32l;
    // 0x801973B0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_801973B4:
    // 0x801973B4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x801973B8: jr          $ra
    // 0x801973BC: nop

    return;
    // 0x801973BC: nop

;}
RECOMP_FUNC void Option_VsStageSelection(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019A6DC: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8019A6E0: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8019A6E4: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x8019A6E8: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x8019A6EC: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x8019A6F0: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x8019A6F4: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x8019A6F8: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x8019A6FC: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8019A700: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x8019A704: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8019A708: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x8019A70C: lw          $t6, -0x6C8C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6C8C);
    // 0x8019A710: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x8019A714: bnel        $t6, $zero, L_8019A928
    if (ctx->r14 != 0) {
        // 0x8019A718: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_8019A928;
    }
    goto skip_0;
    // 0x8019A718: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    skip_0:
    // 0x8019A71C: lw          $t7, -0x6E10($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X6E10);
    // 0x8019A720: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8019A724: addiu       $v0, $v0, -0x6ED4
    ctx->r2 = ADD32(ctx->r2, -0X6ED4);
    // 0x8019A728: beq         $t7, $zero, L_8019A750
    if (ctx->r15 == 0) {
        // 0x8019A72C: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_8019A750;
    }
    // 0x8019A72C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8019A730: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019A734: sw          $t8, -0x6CC4($at)
    MEM_W(-0X6CC4, ctx->r1) = ctx->r24;
    // 0x8019A738: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019A73C: sw          $zero, -0x6E10($at)
    MEM_W(-0X6E10, ctx->r1) = 0;
    // 0x8019A740: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x8019A744: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8019A748: b           L_8019A924
    // 0x8019A74C: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
        goto L_8019A924;
    // 0x8019A74C: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
L_8019A750:
    // 0x8019A750: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x8019A754: lui         $s7, 0x8016
    ctx->r23 = S32(0X8016 << 16);
    // 0x8019A758: lui         $s6, 0x800C
    ctx->r22 = S32(0X800C << 16);
    // 0x8019A75C: lui         $s5, 0x800C
    ctx->r21 = S32(0X800C << 16);
    // 0x8019A760: lui         $s4, 0x801C
    ctx->r20 = S32(0X801C << 16);
    // 0x8019A764: lui         $s3, 0x800C
    ctx->r19 = S32(0X800C << 16);
    // 0x8019A768: addiu       $s3, $s3, 0x5D34
    ctx->r19 = ADD32(ctx->r19, 0X5D34);
    // 0x8019A76C: addiu       $s4, $s4, -0x6C28
    ctx->r20 = ADD32(ctx->r20, -0X6C28);
    // 0x8019A770: addiu       $s5, $s5, 0x5D28
    ctx->r21 = ADD32(ctx->r21, 0X5D28);
    // 0x8019A774: addiu       $s6, $s6, 0x5D3C
    ctx->r22 = ADD32(ctx->r22, 0X5D3C);
    // 0x8019A778: addiu       $s7, $s7, 0x1A28
    ctx->r23 = ADD32(ctx->r23, 0X1A28);
    // 0x8019A77C: addiu       $s2, $s2, -0x2750
    ctx->r18 = ADD32(ctx->r18, -0X2750);
    // 0x8019A780: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8019A784: addiu       $fp, $zero, 0x4
    ctx->r30 = ADD32(0, 0X4);
L_8019A788:
    // 0x8019A788: lbu         $t1, 0x0($s2)
    ctx->r9 = MEM_BU(ctx->r18, 0X0);
    // 0x8019A78C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8019A790: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8019A794: beq         $t1, $zero, L_8019A918
    if (ctx->r9 == 0) {
        // 0x8019A798: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_8019A918;
    }
    // 0x8019A798: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8019A79C: lui         $t5, 0x801C
    ctx->r13 = S32(0X801C << 16);
    // 0x8019A7A0: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
    // 0x8019A7A4: subu        $t7, $t7, $s0
    ctx->r15 = SUB32(ctx->r15, ctx->r16);
    // 0x8019A7A8: addiu       $t5, $t5, -0x6C80
    ctx->r13 = ADD32(ctx->r13, -0X6C80);
    // 0x8019A7AC: sll         $t4, $s0, 3
    ctx->r12 = S32(ctx->r16 << 3);
    // 0x8019A7B0: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8019A7B4: addiu       $t8, $t8, -0x2768
    ctx->r24 = ADD32(ctx->r24, -0X2768);
    // 0x8019A7B8: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x8019A7BC: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x8019A7C0: addiu       $t2, $zero, 0x14
    ctx->r10 = ADD32(0, 0X14);
    // 0x8019A7C4: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x8019A7C8: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x8019A7CC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8019A7D0: addu        $s1, $t7, $t8
    ctx->r17 = ADD32(ctx->r15, ctx->r24);
    // 0x8019A7D4: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x8019A7D8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8019A7DC: sw          $fp, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r30;
    // 0x8019A7E0: jal         0x8019C418
    // 0x8019A7E4: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    Option_Input_MoveCursor_Y(rdram, ctx);
        goto after_0;
    // 0x8019A7E4: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    after_0:
    // 0x8019A7E8: beq         $v0, $zero, L_8019A814
    if (ctx->r2 == 0) {
        // 0x8019A7EC: lui         $a0, 0x4900
        ctx->r4 = S32(0X4900 << 16);
            goto L_8019A814;
    }
    // 0x8019A7EC: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x8019A7F0: ori         $a0, $a0, 0x2
    ctx->r4 = ctx->r4 | 0X2;
    // 0x8019A7F4: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x8019A7F8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8019A7FC: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x8019A800: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x8019A804: jal         0x80019218
    // 0x8019A808: sw          $s6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r22;
    Audio_PlaySfx(rdram, ctx);
        goto after_1;
    // 0x8019A808: sw          $s6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r22;
    after_1:
    // 0x8019A80C: lw          $t9, 0x0($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X0);
    // 0x8019A810: sw          $t9, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r25;
L_8019A814:
    // 0x8019A814: lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X0);
    // 0x8019A818: andi        $t0, $v0, 0x8000
    ctx->r8 = ctx->r2 & 0X8000;
    // 0x8019A81C: beq         $t0, $zero, L_8019A8A0
    if (ctx->r8 == 0) {
        // 0x8019A820: andi        $t6, $v0, 0x4000
        ctx->r14 = ctx->r2 & 0X4000;
            goto L_8019A8A0;
    }
    // 0x8019A820: andi        $t6, $v0, 0x4000
    ctx->r14 = ctx->r2 & 0X4000;
    // 0x8019A824: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x8019A828: ori         $a0, $a0, 0x3
    ctx->r4 = ctx->r4 | 0X3;
    // 0x8019A82C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x8019A830: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8019A834: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x8019A838: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x8019A83C: jal         0x80019218
    // 0x8019A840: sw          $s6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r22;
    Audio_PlaySfx(rdram, ctx);
        goto after_2;
    // 0x8019A840: sw          $s6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r22;
    after_2:
    // 0x8019A844: lw          $t1, 0x0($s7)
    ctx->r9 = MEM_W(ctx->r23, 0X0);
    // 0x8019A848: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8019A84C: addiu       $v0, $v0, 0x789C
    ctx->r2 = ADD32(ctx->r2, 0X789C);
    // 0x8019A850: bne         $t1, $zero, L_8019A884
    if (ctx->r9 != 0) {
        // 0x8019A854: addiu       $t5, $zero, 0xA
        ctx->r13 = ADD32(0, 0XA);
            goto L_8019A884;
    }
    // 0x8019A854: addiu       $t5, $zero, 0xA
    ctx->r13 = ADD32(0, 0XA);
    // 0x8019A858: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8019A85C: addiu       $v0, $v0, 0x789C
    ctx->r2 = ADD32(ctx->r2, 0X789C);
    // 0x8019A860: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x8019A864: lui         $t2, 0x801C
    ctx->r10 = S32(0X801C << 16);
    // 0x8019A868: lw          $t2, -0x6C30($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X6C30);
    // 0x8019A86C: addiu       $at, $zero, 0x1E
    ctx->r1 = ADD32(0, 0X1E);
    // 0x8019A870: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8019A874: bne         $t2, $at, L_8019A88C
    if (ctx->r10 != ctx->r1) {
        // 0x8019A878: nop
    
            goto L_8019A88C;
    }
    // 0x8019A878: nop

    // 0x8019A87C: b           L_8019A88C
    // 0x8019A880: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
        goto L_8019A88C;
    // 0x8019A880: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
L_8019A884:
    // 0x8019A884: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x8019A888: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
L_8019A88C:
    // 0x8019A88C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019A890: jal         0x8019A080
    // 0x8019A894: sw          $t5, -0x6C8C($at)
    MEM_W(-0X6C8C, ctx->r1) = ctx->r13;
    Option_8019A080(rdram, ctx);
        goto after_3;
    // 0x8019A894: sw          $t5, -0x6C8C($at)
    MEM_W(-0X6C8C, ctx->r1) = ctx->r13;
    after_3:
    // 0x8019A898: b           L_8019A928
    // 0x8019A89C: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
        goto L_8019A928;
    // 0x8019A89C: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_8019A8A0:
    // 0x8019A8A0: beq         $t6, $zero, L_8019A918
    if (ctx->r14 == 0) {
        // 0x8019A8A4: lui         $a0, 0x4900
        ctx->r4 = S32(0X4900 << 16);
            goto L_8019A918;
    }
    // 0x8019A8A4: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x8019A8A8: ori         $a0, $a0, 0x101D
    ctx->r4 = ctx->r4 | 0X101D;
    // 0x8019A8AC: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x8019A8B0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8019A8B4: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x8019A8B8: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x8019A8BC: jal         0x80019218
    // 0x8019A8C0: sw          $s6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r22;
    Audio_PlaySfx(rdram, ctx);
        goto after_4;
    // 0x8019A8C0: sw          $s6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r22;
    after_4:
    // 0x8019A8C4: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8019A8C8: lw          $v0, -0x6C30($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6C30);
    // 0x8019A8CC: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x8019A8D0: bne         $v0, $at, L_8019A8F0
    if (ctx->r2 != ctx->r1) {
        // 0x8019A8D4: lui         $at, 0x801C
        ctx->r1 = S32(0X801C << 16);
            goto L_8019A8F0;
    }
    // 0x8019A8D4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019A8D8: sw          $v0, -0x6EDC($at)
    MEM_W(-0X6EDC, ctx->r1) = ctx->r2;
    // 0x8019A8DC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019A8E0: jal         0x801924C4
    // 0x8019A8E4: sw          $zero, -0x6E3C($at)
    MEM_W(-0X6E3C, ctx->r1) = 0;
    Option_Entry_Setup(rdram, ctx);
        goto after_5;
    // 0x8019A8E4: sw          $zero, -0x6E3C($at)
    MEM_W(-0X6E3C, ctx->r1) = 0;
    after_5:
    // 0x8019A8E8: b           L_8019A928
    // 0x8019A8EC: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
        goto L_8019A928;
    // 0x8019A8EC: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_8019A8F0:
    // 0x8019A8F0: jal         0x8019A080
    // 0x8019A8F4: nop

    Option_8019A080(rdram, ctx);
        goto after_6;
    // 0x8019A8F4: nop

    after_6:
    // 0x8019A8F8: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8019A8FC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019A900: addiu       $v0, $v0, -0x6ED4
    ctx->r2 = ADD32(ctx->r2, -0X6ED4);
    // 0x8019A904: sw          $zero, -0x6E10($at)
    MEM_W(-0X6E10, ctx->r1) = 0;
    // 0x8019A908: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x8019A90C: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x8019A910: b           L_8019A924
    // 0x8019A914: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
        goto L_8019A924;
    // 0x8019A914: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
L_8019A918:
    // 0x8019A918: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8019A91C: bne         $s0, $fp, L_8019A788
    if (ctx->r16 != ctx->r30) {
        // 0x8019A920: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_8019A788;
    }
    // 0x8019A920: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_8019A924:
    // 0x8019A924: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_8019A928:
    // 0x8019A928: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8019A92C: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x8019A930: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x8019A934: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x8019A938: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x8019A93C: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x8019A940: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x8019A944: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x8019A948: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x8019A94C: jr          $ra
    // 0x8019A950: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8019A950: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void Option_Vs_BattleRoyal_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019A1A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8019A1AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8019A1B0: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8019A1B4: lw          $v0, -0x6ED4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6ED4);
    // 0x8019A1B8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8019A1BC: beq         $v0, $zero, L_8019A1DC
    if (ctx->r2 == 0) {
        // 0x8019A1C0: nop
    
            goto L_8019A1DC;
    }
    // 0x8019A1C0: nop

    // 0x8019A1C4: beq         $v0, $at, L_8019A1EC
    if (ctx->r2 == ctx->r1) {
        // 0x8019A1C8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8019A1EC;
    }
    // 0x8019A1C8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8019A1CC: beq         $v0, $at, L_8019A1FC
    if (ctx->r2 == ctx->r1) {
        // 0x8019A1D0: nop
    
            goto L_8019A1FC;
    }
    // 0x8019A1D0: nop

    // 0x8019A1D4: b           L_8019A208
    // 0x8019A1D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8019A208;
    // 0x8019A1D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8019A1DC:
    // 0x8019A1DC: jal         0x8019A6DC
    // 0x8019A1E0: nop

    Option_VsStageSelection(rdram, ctx);
        goto after_0;
    // 0x8019A1E0: nop

    after_0:
    // 0x8019A1E4: b           L_8019A208
    // 0x8019A1E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8019A208;
    // 0x8019A1E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8019A1EC:
    // 0x8019A1EC: jal         0x8019A954
    // 0x8019A1F0: nop

    Option_VsConfirmSelection(rdram, ctx);
        goto after_1;
    // 0x8019A1F0: nop

    after_1:
    // 0x8019A1F4: b           L_8019A208
    // 0x8019A1F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8019A208;
    // 0x8019A1F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8019A1FC:
    // 0x8019A1FC: jal         0x8019A298
    // 0x8019A200: nop

    Option_Vs_StartMatch(rdram, ctx);
        goto after_2;
    // 0x8019A200: nop

    after_2:
    // 0x8019A204: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8019A208:
    // 0x8019A208: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8019A20C: jr          $ra
    // 0x8019A210: nop

    return;
    // 0x8019A210: nop

;}
RECOMP_FUNC void Map_PathLines_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801AC9A0: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x801AC9A4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801AC9A8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801AC9AC: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x801AC9B0: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x801AC9B4: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    // 0x801AC9B8: jal         0x801ACD90
    // 0x801AC9BC: addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    Map_PathLinePos(rdram, ctx);
        goto after_0;
    // 0x801AC9BC: addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    after_0:
    // 0x801AC9C0: lwc1        $f16, 0x5C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x801AC9C4: lwc1        $f18, 0x50($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X50);
    // 0x801AC9C8: lwc1        $f4, 0x60($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X60);
    // 0x801AC9CC: lwc1        $f6, 0x54($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X54);
    // 0x801AC9D0: sub.s       $f2, $f16, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x801AC9D4: lwc1        $f8, 0x64($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X64);
    // 0x801AC9D8: lwc1        $f10, 0x58($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X58);
    // 0x801AC9DC: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801AC9E0: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x801AC9E4: lw          $t6, 0x68($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X68);
    // 0x801AC9E8: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x801AC9EC: mul.s       $f6, $f12, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x801AC9F0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801AC9F4: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x801AC9F8: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x801AC9FC: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x801ACA00: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x801ACA04: addiu       $t8, $t8, 0x4750
    ctx->r24 = ADD32(ctx->r24, 0X4750);
    // 0x801ACA08: addu        $s0, $t7, $t8
    ctx->r16 = ADD32(ctx->r15, ctx->r24);
    // 0x801ACA0C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801ACA10: lwc1        $f4, 0x60($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X60);
    // 0x801ACA14: lwc1        $f6, 0x64($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X64);
    // 0x801ACA18: swc1        $f2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f2.u32l;
    // 0x801ACA1C: add.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801ACA20: lwc1        $f8, 0x54($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X54);
    // 0x801ACA24: lwc1        $f10, 0x58($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X58);
    // 0x801ACA28: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    // 0x801ACA2C: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x801ACA30: swc1        $f14, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f14.u32l;
    // 0x801ACA34: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x801ACA38: sb          $t9, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r25;
    // 0x801ACA3C: lwc1        $f14, 0x44($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X44);
    // 0x801ACA40: lwc1        $f12, 0x4C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x801ACA44: swc1        $f16, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f16.u32l;
    // 0x801ACA48: swc1        $f18, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f18.u32l;
    // 0x801ACA4C: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    // 0x801ACA50: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
    // 0x801ACA54: swc1        $f8, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f8.u32l;
    // 0x801ACA58: swc1        $f10, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f10.u32l;
    // 0x801ACA5C: jal         0x80005100
    // 0x801ACA60: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    Math_Atan2F(rdram, ctx);
        goto after_1;
    // 0x801ACA60: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x801ACA64: lwc1        $f2, 0x4C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x801ACA68: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
    // 0x801ACA6C: swc1        $f0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f0.u32l;
    // 0x801ACA70: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x801ACA74: lwc1        $f12, 0x48($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
    // 0x801ACA78: mul.s       $f6, $f16, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x801ACA7C: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801ACA80: jal         0x80005100
    // 0x801ACA84: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    Math_Atan2F(rdram, ctx);
        goto after_2;
    // 0x801ACA84: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    after_2:
    // 0x801ACA88: lw          $t0, 0x68($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X68);
    // 0x801ACA8C: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x801ACA90: addiu       $t2, $t2, 0x7BD8
    ctx->r10 = ADD32(ctx->r10, 0X7BD8);
    // 0x801ACA94: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x801ACA98: addu        $v1, $t1, $t2
    ctx->r3 = ADD32(ctx->r9, ctx->r10);
    // 0x801ACA9C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801ACAA0: neg.s       $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = -ctx->f0.fl;
    // 0x801ACAA4: addiu       $t3, $v0, -0x1
    ctx->r11 = ADD32(ctx->r2, -0X1);
    // 0x801ACAA8: sltiu       $at, $t3, 0xB
    ctx->r1 = ctx->r11 < 0XB ? 1 : 0;
    // 0x801ACAAC: beq         $at, $zero, L_801ACC8C
    if (ctx->r1 == 0) {
        // 0x801ACAB0: swc1        $f8, 0x1C($s0)
        MEM_W(0X1C, ctx->r16) = ctx->f8.u32l;
            goto L_801ACC8C;
    }
    // 0x801ACAB0: swc1        $f8, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f8.u32l;
    // 0x801ACAB4: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x801ACAB8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801ACABC: addu        $at, $at, $t3
    gpr jr_addend_801ACAC4 = ctx->r11;
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x801ACAC0: lw          $t3, 0x7B30($at)
    ctx->r11 = ADD32(ctx->r1, 0X7B30);
    // 0x801ACAC4: jr          $t3
    // 0x801ACAC8: nop

    switch (jr_addend_801ACAC4 >> 2) {
        case 0: goto L_801ACACC; break;
        case 1: goto L_801ACBEC; break;
        case 2: goto L_801ACC68; break;
        case 3: goto L_801ACC68; break;
        case 4: goto L_801ACB84; break;
        case 5: goto L_801ACB84; break;
        case 6: goto L_801ACC8C; break;
        case 7: goto L_801ACC8C; break;
        case 8: goto L_801ACC8C; break;
        case 9: goto L_801ACC8C; break;
        case 10: goto L_801ACB14; break;
        default: switch_error(__func__, 0x801ACAC4, 0x801B7B30);
    }
    // 0x801ACAC8: nop

L_801ACACC:
    // 0x801ACACC: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x801ACAD0: lui         $t4, 0x800C
    ctx->r12 = S32(0X800C << 16);
    // 0x801ACAD4: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x801ACAD8: addiu       $t4, $t4, 0x5D3C
    ctx->r12 = ADD32(ctx->r12, 0X5D3C);
    // 0x801ACADC: lui         $a0, 0x1900
    ctx->r4 = S32(0X1900 << 16);
    // 0x801ACAE0: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x801ACAE4: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x801ACAE8: ori         $a0, $a0, 0x404D
    ctx->r4 = ctx->r4 | 0X404D;
    // 0x801ACAEC: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x801ACAF0: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x801ACAF4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x801ACAF8: jal         0x80019218
    // 0x801ACAFC: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    Audio_PlaySfx(rdram, ctx);
        goto after_3;
    // 0x801ACAFC: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    after_3:
    // 0x801ACB00: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x801ACB04: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    // 0x801ACB08: lw          $t0, 0x68($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X68);
    // 0x801ACB0C: b           L_801ACC8C
    // 0x801ACB10: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
        goto L_801ACC8C;
    // 0x801ACB10: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_801ACB14:
    // 0x801ACB14: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x801ACB18: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801ACB1C: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x801ACB20: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801ACB24: addiu       $a0, $s0, 0x24
    ctx->r4 = ADD32(ctx->r16, 0X24);
    // 0x801ACB28: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x801ACB2C: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x801ACB30: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    // 0x801ACB34: jal         0x8009BC2C
    // 0x801ACB38: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_4;
    // 0x801ACB38: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_4:
    // 0x801ACB3C: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x801ACB40: lwc1        $f6, 0x24($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X24);
    // 0x801ACB44: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x801ACB48: lui         $a0, 0x1900
    ctx->r4 = S32(0X1900 << 16);
    // 0x801ACB4C: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x801ACB50: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x801ACB54: sb          $a1, 0x2F($s0)
    MEM_B(0X2F, ctx->r16) = ctx->r5;
    // 0x801ACB58: ori         $a0, $a0, 0x404D
    ctx->r4 = ctx->r4 | 0X404D;
    // 0x801ACB5C: bc1fl       L_801ACB7C
    if (!c1cs) {
        // 0x801ACB60: lw          $v0, 0x0($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X0);
            goto L_801ACB7C;
    }
    goto skip_0;
    // 0x801ACB60: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    skip_0:
    // 0x801ACB64: jal         0x8001A838
    // 0x801ACB68: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    Audio_KillSfxById(rdram, ctx);
        goto after_5;
    // 0x801ACB68: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    after_5:
    // 0x801ACB6C: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x801ACB70: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x801ACB74: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x801ACB78: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
L_801ACB7C:
    // 0x801ACB7C: b           L_801ACC8C
    // 0x801ACB80: lw          $t0, 0x68($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X68);
        goto L_801ACC8C;
    // 0x801ACB80: lw          $t0, 0x68($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X68);
L_801ACB84:
    // 0x801ACB84: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801ACB88: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801ACB8C: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x801ACB90: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801ACB94: addiu       $a0, $s0, 0x24
    ctx->r4 = ADD32(ctx->r16, 0X24);
    // 0x801ACB98: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x801ACB9C: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x801ACBA0: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    // 0x801ACBA4: jal         0x8009BC2C
    // 0x801ACBA8: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_6;
    // 0x801ACBA8: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_6:
    // 0x801ACBAC: lwc1        $f10, 0x40($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X40);
    // 0x801ACBB0: lwc1        $f4, 0x24($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X24);
    // 0x801ACBB4: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x801ACBB8: addiu       $t7, $zero, 0x6
    ctx->r15 = ADD32(0, 0X6);
    // 0x801ACBBC: c.eq.s      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.fl == ctx->f4.fl;
    // 0x801ACBC0: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x801ACBC4: bc1fl       L_801ACBE4
    if (!c1cs) {
        // 0x801ACBC8: lw          $v0, 0x0($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X0);
            goto L_801ACBE4;
    }
    goto skip_1;
    // 0x801ACBC8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    skip_1:
    // 0x801ACBCC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801ACBD0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x801ACBD4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801ACBD8: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
    // 0x801ACBDC: sw          $t8, -0x1154($at)
    MEM_W(-0X1154, ctx->r1) = ctx->r24;
    // 0x801ACBE0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
L_801ACBE4:
    // 0x801ACBE4: b           L_801ACC8C
    // 0x801ACBE8: lw          $t0, 0x68($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X68);
        goto L_801ACC8C;
    // 0x801ACBE8: lw          $t0, 0x68($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X68);
L_801ACBEC:
    // 0x801ACBEC: lui         $t9, 0x801D
    ctx->r25 = S32(0X801D << 16);
    // 0x801ACBF0: lw          $t9, -0x26BC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X26BC);
    // 0x801ACBF4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801ACBF8: lwc1        $f0, 0x7B5C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X7B5C);
    // 0x801ACBFC: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x801ACC00: bne         $t9, $at, L_801ACC14
    if (ctx->r25 != ctx->r1) {
        // 0x801ACC04: addiu       $a0, $s0, 0x24
        ctx->r4 = ADD32(ctx->r16, 0X24);
            goto L_801ACC14;
    }
    // 0x801ACC04: addiu       $a0, $s0, 0x24
    ctx->r4 = ADD32(ctx->r16, 0X24);
    // 0x801ACC08: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x801ACC0C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801ACC10: nop

L_801ACC14:
    // 0x801ACC14: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x801ACC18: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801ACC1C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801ACC20: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x801ACC24: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x801ACC28: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    // 0x801ACC2C: jal         0x8009BC2C
    // 0x801ACC30: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_7;
    // 0x801ACC30: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_7:
    // 0x801ACC34: lwc1        $f10, 0x40($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X40);
    // 0x801ACC38: lwc1        $f4, 0x24($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X24);
    // 0x801ACC3C: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x801ACC40: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x801ACC44: c.eq.s      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.fl == ctx->f4.fl;
    // 0x801ACC48: sb          $a1, 0x2F($s0)
    MEM_B(0X2F, ctx->r16) = ctx->r5;
    // 0x801ACC4C: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x801ACC50: bc1fl       L_801ACC60
    if (!c1cs) {
        // 0x801ACC54: lw          $v0, 0x0($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X0);
            goto L_801ACC60;
    }
    goto skip_2;
    // 0x801ACC54: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    skip_2:
    // 0x801ACC58: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x801ACC5C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
L_801ACC60:
    // 0x801ACC60: b           L_801ACC8C
    // 0x801ACC64: lw          $t0, 0x68($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X68);
        goto L_801ACC8C;
    // 0x801ACC64: lw          $t0, 0x68($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X68);
L_801ACC68:
    // 0x801ACC68: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
    // 0x801ACC6C: sll         $t2, $t0, 3
    ctx->r10 = S32(ctx->r8 << 3);
    // 0x801ACC70: subu        $t2, $t2, $t0
    ctx->r10 = SUB32(ctx->r10, ctx->r8);
    // 0x801ACC74: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x801ACC78: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x801ACC7C: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x801ACC80: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
    // 0x801ACC84: lw          $t3, -0x2D0($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2D0);
    // 0x801ACC88: sb          $t3, 0x2F($s0)
    MEM_B(0X2F, ctx->r16) = ctx->r11;
L_801ACC8C:
    // 0x801ACC8C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801ACC90: beq         $v0, $at, L_801ACCB0
    if (ctx->r2 == ctx->r1) {
        // 0x801ACC94: addiu       $a1, $zero, 0xFF
        ctx->r5 = ADD32(0, 0XFF);
            goto L_801ACCB0;
    }
    // 0x801ACC94: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x801ACC98: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x801ACC9C: beq         $v0, $at, L_801ACCB0
    if (ctx->r2 == ctx->r1) {
        // 0x801ACCA0: sll         $t4, $t0, 3
        ctx->r12 = S32(ctx->r8 << 3);
            goto L_801ACCB0;
    }
    // 0x801ACCA0: sll         $t4, $t0, 3
    ctx->r12 = S32(ctx->r8 << 3);
    // 0x801ACCA4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x801ACCA8: bne         $v0, $at, L_801ACCD0
    if (ctx->r2 != ctx->r1) {
        // 0x801ACCAC: subu        $t4, $t4, $t0
        ctx->r12 = SUB32(ctx->r12, ctx->r8);
            goto L_801ACCD0;
    }
    // 0x801ACCAC: subu        $t4, $t4, $t0
    ctx->r12 = SUB32(ctx->r12, ctx->r8);
L_801ACCB0:
    // 0x801ACCB0: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x801ACCB4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801ACCB8: addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
    // 0x801ACCBC: sb          $v0, 0x2C($s0)
    MEM_B(0X2C, ctx->r16) = ctx->r2;
    // 0x801ACCC0: sb          $v0, 0x2D($s0)
    MEM_B(0X2D, ctx->r16) = ctx->r2;
    // 0x801ACCC4: sb          $v0, 0x2E($s0)
    MEM_B(0X2E, ctx->r16) = ctx->r2;
    // 0x801ACCC8: b           L_801ACD7C
    // 0x801ACCCC: swc1        $f8, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f8.u32l;
        goto L_801ACD7C;
    // 0x801ACCCC: swc1        $f8, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f8.u32l;
L_801ACCD0:
    // 0x801ACCD0: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x801ACCD4: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x801ACCD8: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x801ACCDC: lw          $t5, -0x2E8($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2E8);
    // 0x801ACCE0: sltiu       $at, $t5, 0x5
    ctx->r1 = ctx->r13 < 0X5 ? 1 : 0;
    // 0x801ACCE4: beq         $at, $zero, L_801ACD7C
    if (ctx->r1 == 0) {
        // 0x801ACCE8: sll         $t5, $t5, 2
        ctx->r13 = S32(ctx->r13 << 2);
            goto L_801ACD7C;
    }
    // 0x801ACCE8: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x801ACCEC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801ACCF0: addu        $at, $at, $t5
    gpr jr_addend_801ACCF8 = ctx->r13;
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x801ACCF4: lw          $t5, 0x7B60($at)
    ctx->r13 = ADD32(ctx->r1, 0X7B60);
    // 0x801ACCF8: jr          $t5
    // 0x801ACCFC: nop

    switch (jr_addend_801ACCF8 >> 2) {
        case 0: goto L_801ACD00; break;
        case 1: goto L_801ACD24; break;
        case 2: goto L_801ACD44; break;
        case 3: goto L_801ACD60; break;
        case 4: goto L_801ACD60; break;
        default: switch_error(__func__, 0x801ACCF8, 0x801B7B60);
    }
    // 0x801ACCFC: nop

L_801ACD00:
    // 0x801ACD00: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x801ACD04: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801ACD08: addiu       $t6, $zero, 0x10
    ctx->r14 = ADD32(0, 0X10);
    // 0x801ACD0C: addiu       $t7, $zero, 0x40
    ctx->r15 = ADD32(0, 0X40);
    // 0x801ACD10: sb          $t6, 0x2C($s0)
    MEM_B(0X2C, ctx->r16) = ctx->r14;
    // 0x801ACD14: sb          $t7, 0x2D($s0)
    MEM_B(0X2D, ctx->r16) = ctx->r15;
    // 0x801ACD18: sb          $a1, 0x2E($s0)
    MEM_B(0X2E, ctx->r16) = ctx->r5;
    // 0x801ACD1C: b           L_801ACD7C
    // 0x801ACD20: swc1        $f10, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f10.u32l;
        goto L_801ACD7C;
    // 0x801ACD20: swc1        $f10, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f10.u32l;
L_801ACD24:
    // 0x801ACD24: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x801ACD28: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801ACD2C: addiu       $t8, $zero, 0xAF
    ctx->r24 = ADD32(0, 0XAF);
    // 0x801ACD30: sb          $a1, 0x2C($s0)
    MEM_B(0X2C, ctx->r16) = ctx->r5;
    // 0x801ACD34: sb          $t8, 0x2D($s0)
    MEM_B(0X2D, ctx->r16) = ctx->r24;
    // 0x801ACD38: sb          $zero, 0x2E($s0)
    MEM_B(0X2E, ctx->r16) = 0;
    // 0x801ACD3C: b           L_801ACD7C
    // 0x801ACD40: swc1        $f4, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f4.u32l;
        goto L_801ACD7C;
    // 0x801ACD40: swc1        $f4, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f4.u32l;
L_801ACD44:
    // 0x801ACD44: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x801ACD48: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801ACD4C: sb          $a1, 0x2C($s0)
    MEM_B(0X2C, ctx->r16) = ctx->r5;
    // 0x801ACD50: sb          $zero, 0x2D($s0)
    MEM_B(0X2D, ctx->r16) = 0;
    // 0x801ACD54: sb          $zero, 0x2E($s0)
    MEM_B(0X2E, ctx->r16) = 0;
    // 0x801ACD58: b           L_801ACD7C
    // 0x801ACD5C: swc1        $f6, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f6.u32l;
        goto L_801ACD7C;
    // 0x801ACD5C: swc1        $f6, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f6.u32l;
L_801ACD60:
    // 0x801ACD60: sb          $zero, 0x2C($s0)
    MEM_B(0X2C, ctx->r16) = 0;
    // 0x801ACD64: sb          $zero, 0x2D($s0)
    MEM_B(0X2D, ctx->r16) = 0;
    // 0x801ACD68: sb          $zero, 0x2E($s0)
    MEM_B(0X2E, ctx->r16) = 0;
    // 0x801ACD6C: sb          $zero, 0x2F($s0)
    MEM_B(0X2F, ctx->r16) = 0;
    // 0x801ACD70: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801ACD74: lwc1        $f8, 0x7B74($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7B74);
    // 0x801ACD78: swc1        $f8, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f8.u32l;
L_801ACD7C:
    // 0x801ACD7C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801ACD80: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801ACD84: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x801ACD88: jr          $ra
    // 0x801ACD8C: nop

    return;
    // 0x801ACD8C: nop

;}
RECOMP_FUNC void Map_SetCamRot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801AD718: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x801AD71C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801AD720: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801AD724: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x801AD728: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x801AD72C: lwc1        $f4, 0x50($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X50);
    // 0x801AD730: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801AD734: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x801AD738: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x801AD73C: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x801AD740: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x801AD744: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801AD748: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x801AD74C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x801AD750: jal         0x80005B00
    // 0x801AD754: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    Matrix_Translate(rdram, ctx);
        goto after_0;
    // 0x801AD754: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x801AD758: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801AD75C: lwc1        $f6, 0x7B90($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7B90);
    // 0x801AD760: lwc1        $f8, 0x58($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X58);
    // 0x801AD764: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801AD768: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801AD76C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x801AD770: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801AD774: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x801AD778: jal         0x80005E90
    // 0x801AD77C: nop

    Matrix_RotateY(rdram, ctx);
        goto after_1;
    // 0x801AD77C: nop

    after_1:
    // 0x801AD780: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801AD784: lwc1        $f16, 0x7B94($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7B94);
    // 0x801AD788: lwc1        $f18, 0x54($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X54);
    // 0x801AD78C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801AD790: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801AD794: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x801AD798: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801AD79C: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x801AD7A0: jal         0x80005D44
    // 0x801AD7A4: nop

    Matrix_RotateX(rdram, ctx);
        goto after_2;
    // 0x801AD7A4: nop

    after_2:
    // 0x801AD7A8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801AD7AC: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801AD7B0: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x801AD7B4: jal         0x80006970
    // 0x801AD7B8: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    Matrix_MultVec3f(rdram, ctx);
        goto after_3;
    // 0x801AD7B8: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    after_3:
    // 0x801AD7BC: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801AD7C0: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x801AD7C4: swc1        $f6, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f6.u32l;
    // 0x801AD7C8: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x801AD7CC: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x801AD7D0: swc1        $f8, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f8.u32l;
    // 0x801AD7D4: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x801AD7D8: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x801AD7DC: swc1        $f10, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f10.u32l;
    // 0x801AD7E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801AD7E4: jr          $ra
    // 0x801AD7E8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x801AD7E8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
