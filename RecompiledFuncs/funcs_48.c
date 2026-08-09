#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void Map_801A281C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A281C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801A2820: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801A2824: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801A2828: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801A282C: lui         $t0, 0x801D
    ctx->r8 = S32(0X801D << 16);
    // 0x801A2830: lui         $t1, 0x801D
    ctx->r9 = S32(0X801D << 16);
    // 0x801A2834: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x801A2838: addiu       $t1, $t1, -0x25EC
    ctx->r9 = ADD32(ctx->r9, -0X25EC);
    // 0x801A283C: addiu       $t0, $t0, -0x25F0
    ctx->r8 = ADD32(ctx->r8, -0X25F0);
    // 0x801A2840: addiu       $a1, $a1, -0x25F4
    ctx->r5 = ADD32(ctx->r5, -0X25F4);
    // 0x801A2844: addiu       $v1, $v1, -0x1118
    ctx->r3 = ADD32(ctx->r3, -0X1118);
    // 0x801A2848: addiu       $v0, $v0, -0x10A8
    ctx->r2 = ADD32(ctx->r2, -0X10A8);
    // 0x801A284C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x801A2850: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801A2854: sw          $zero, -0x7CB8($at)
    MEM_W(-0X7CB8, ctx->r1) = 0;
    // 0x801A2858: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801A285C: sw          $zero, -0x7CB0($at)
    MEM_W(-0X7CB0, ctx->r1) = 0;
    // 0x801A2860: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801A2864: sw          $zero, -0x7CAC($at)
    MEM_W(-0X7CAC, ctx->r1) = 0;
    // 0x801A2868: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801A286C: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x801A2870: sw          $t6, -0x7CC0($at)
    MEM_W(-0X7CC0, ctx->r1) = ctx->r14;
    // 0x801A2874: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A2878: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x801A287C: sw          $t7, -0x2678($at)
    MEM_W(-0X2678, ctx->r1) = ctx->r15;
    // 0x801A2880: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A2884: sw          $zero, -0x1128($at)
    MEM_W(-0X1128, ctx->r1) = 0;
    // 0x801A2888: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A288C: swc1        $f2, -0x1124($at)
    MEM_W(-0X1124, ctx->r1) = ctx->f2.u32l;
    // 0x801A2890: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A2894: lwc1        $f4, 0x76C4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X76C4);
    // 0x801A2898: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A289C: lui         $t8, 0x801D
    ctx->r24 = S32(0X801D << 16);
    // 0x801A28A0: swc1        $f4, -0x1120($at)
    MEM_W(-0X1120, ctx->r1) = ctx->f4.u32l;
    // 0x801A28A4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A28A8: lwc1        $f6, -0x260C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X260C);
    // 0x801A28AC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A28B0: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x801A28B4: swc1        $f6, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f6.u32l;
    // 0x801A28B8: lwc1        $f8, 0xC($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0XC);
    // 0x801A28BC: addiu       $t2, $t2, -0xB60
    ctx->r10 = ADD32(ctx->r10, -0XB60);
    // 0x801A28C0: lui         $t3, 0x801D
    ctx->r11 = S32(0X801D << 16);
    // 0x801A28C4: swc1        $f8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f8.u32l;
    // 0x801A28C8: lwc1        $f10, -0x2608($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2608);
    // 0x801A28CC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A28D0: lui         $t4, 0x801D
    ctx->r12 = S32(0X801D << 16);
    // 0x801A28D4: swc1        $f10, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f10.u32l;
    // 0x801A28D8: lwc1        $f16, 0x10($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X10);
    // 0x801A28DC: addiu       $t4, $t4, -0x10F8
    ctx->r12 = ADD32(ctx->r12, -0X10F8);
    // 0x801A28E0: addiu       $t3, $t3, -0x10FC
    ctx->r11 = ADD32(ctx->r11, -0X10FC);
    // 0x801A28E4: swc1        $f16, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f16.u32l;
    // 0x801A28E8: lwc1        $f18, -0x2604($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X2604);
    // 0x801A28EC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A28F0: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801A28F4: swc1        $f18, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->f18.u32l;
    // 0x801A28F8: lwc1        $f4, 0x14($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X14);
    // 0x801A28FC: addiu       $a3, $a3, -0x1100
    ctx->r7 = ADD32(ctx->r7, -0X1100);
    // 0x801A2900: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x801A2904: swc1        $f4, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f4.u32l;
    // 0x801A2908: lwc1        $f6, -0x2600($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2600);
    // 0x801A290C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A2910: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x801A2914: swc1        $f6, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f6.u32l;
    // 0x801A2918: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x801A291C: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x801A2920: lwc1        $f10, -0x25FC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X25FC);
    // 0x801A2924: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A2928: swc1        $f10, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f10.u32l;
    // 0x801A292C: lwc1        $f16, 0x10($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X10);
    // 0x801A2930: swc1        $f16, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f16.u32l;
    // 0x801A2934: lwc1        $f18, -0x25F8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X25F8);
    // 0x801A2938: lui         $at, 0xC23A
    ctx->r1 = S32(0XC23A << 16);
    // 0x801A293C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801A2940: swc1        $f18, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f18.u32l;
    // 0x801A2944: lwc1        $f4, 0x14($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X14);
    // 0x801A2948: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x801A294C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801A2950: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x801A2954: lw          $t8, -0x26A8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X26A8);
    // 0x801A2958: swc1        $f2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f2.u32l;
    // 0x801A295C: swc1        $f6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f6.u32l;
    // 0x801A2960: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x801A2964: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x801A2968: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x801A296C: addu        $a0, $t9, $t2
    ctx->r4 = ADD32(ctx->r25, ctx->r10);
    // 0x801A2970: lwc1        $f0, 0x10($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X10);
    // 0x801A2974: swc1        $f8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f8.u32l;
    // 0x801A2978: lwc1        $f10, 0x0($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X0);
    // 0x801A297C: swc1        $f0, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f0.u32l;
    // 0x801A2980: swc1        $f0, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f0.u32l;
    // 0x801A2984: swc1        $f0, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f0.u32l;
    // 0x801A2988: swc1        $f0, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->f0.u32l;
    // 0x801A298C: lwc1        $f0, 0x14($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X14);
    // 0x801A2990: lwc1        $f16, 0x0($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X0);
    // 0x801A2994: lwc1        $f18, 0x0($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X0);
    // 0x801A2998: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x801A299C: swc1        $f0, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f0.u32l;
    // 0x801A29A0: swc1        $f0, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f0.u32l;
    // 0x801A29A4: swc1        $f0, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->f0.u32l;
    // 0x801A29A8: lwc1        $f0, 0x18($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X18);
    // 0x801A29AC: lwc1        $f14, 0x1C($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x801A29B0: lwc1        $f12, 0x18($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X18);
    // 0x801A29B4: swc1        $f0, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f0.u32l;
    // 0x801A29B8: lw          $a2, 0x20($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X20);
    // 0x801A29BC: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x801A29C0: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    // 0x801A29C4: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    // 0x801A29C8: swc1        $f0, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f0.u32l;
    // 0x801A29CC: swc1        $f0, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f0.u32l;
    // 0x801A29D0: jal         0x801AD718
    // 0x801A29D4: swc1        $f0, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f0.u32l;
    Map_SetCamRot(rdram, ctx);
        goto after_0;
    // 0x801A29D4: swc1        $f0, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f0.u32l;
    after_0:
    // 0x801A29D8: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801A29DC: addiu       $v1, $v1, -0x1118
    ctx->r3 = ADD32(ctx->r3, -0X1118);
    // 0x801A29E0: lwc1        $f0, 0x18($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X18);
    // 0x801A29E4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A29E8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801A29EC: swc1        $f0, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->f0.u32l;
    // 0x801A29F0: swc1        $f0, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->f0.u32l;
    // 0x801A29F4: swc1        $f0, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f0.u32l;
    // 0x801A29F8: lwc1        $f0, 0x1C($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x801A29FC: addiu       $v0, $v0, -0x10A8
    ctx->r2 = ADD32(ctx->r2, -0X10A8);
    // 0x801A2A00: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801A2A04: swc1        $f0, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->f0.u32l;
    // 0x801A2A08: swc1        $f0, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->f0.u32l;
    // 0x801A2A0C: swc1        $f0, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f0.u32l;
    // 0x801A2A10: lwc1        $f0, 0x20($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X20);
    // 0x801A2A14: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801A2A18: addiu       $a1, $a1, -0x25F4
    ctx->r5 = ADD32(ctx->r5, -0X25F4);
    // 0x801A2A1C: swc1        $f0, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->f0.u32l;
    // 0x801A2A20: swc1        $f0, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->f0.u32l;
    // 0x801A2A24: swc1        $f0, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->f0.u32l;
    // 0x801A2A28: lwc1        $f4, 0x76C8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X76C8);
    // 0x801A2A2C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A2A30: lui         $t0, 0x801D
    ctx->r8 = S32(0X801D << 16);
    // 0x801A2A34: swc1        $f4, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f4.u32l;
    // 0x801A2A38: lwc1        $f12, 0x48($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X48);
    // 0x801A2A3C: addiu       $t0, $t0, -0x25F0
    ctx->r8 = ADD32(ctx->r8, -0X25F0);
    // 0x801A2A40: lui         $t1, 0x801D
    ctx->r9 = S32(0X801D << 16);
    // 0x801A2A44: swc1        $f12, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->f12.u32l;
    // 0x801A2A48: lwc1        $f6, 0x76CC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X76CC);
    // 0x801A2A4C: swc1        $f8, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->f8.u32l;
    // 0x801A2A50: lwc1        $f2, 0x50($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X50);
    // 0x801A2A54: swc1        $f6, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->f6.u32l;
    // 0x801A2A58: lwc1        $f14, 0x4C($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X4C);
    // 0x801A2A5C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A2A60: swc1        $f2, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f2.u32l;
    // 0x801A2A64: swc1        $f14, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f14.u32l;
    // 0x801A2A68: lwc1        $f10, 0x76D0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X76D0);
    // 0x801A2A6C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A2A70: addiu       $t1, $t1, -0x25EC
    ctx->r9 = ADD32(ctx->r9, -0X25EC);
    // 0x801A2A74: swc1        $f10, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f10.u32l;
    // 0x801A2A78: lwc1        $f16, 0x76D4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X76D4);
    // 0x801A2A7C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A2A80: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x801A2A84: swc1        $f16, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f16.u32l;
    // 0x801A2A88: lwc1        $f18, 0x76D8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X76D8);
    // 0x801A2A8C: lwc1        $f8, 0x0($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X0);
    // 0x801A2A90: lui         $t5, 0x801D
    ctx->r13 = S32(0X801D << 16);
    // 0x801A2A94: swc1        $f18, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f18.u32l;
    // 0x801A2A98: lwc1        $f4, 0x0($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X0);
    // 0x801A2A9C: lui         $t6, 0x801D
    ctx->r14 = S32(0X801D << 16);
    // 0x801A2AA0: addiu       $t6, $t6, -0x10C8
    ctx->r14 = ADD32(ctx->r14, -0X10C8);
    // 0x801A2AA4: addiu       $t5, $t5, -0x10CC
    ctx->r13 = ADD32(ctx->r13, -0X10CC);
    // 0x801A2AA8: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801A2AAC: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x801A2AB0: addiu       $a3, $a3, -0x10D0
    ctx->r7 = ADD32(ctx->r7, -0X10D0);
    // 0x801A2AB4: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x801A2AB8: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x801A2ABC: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x801A2AC0: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x801A2AC4: jal         0x801AD718
    // 0x801A2AC8: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    Map_SetCamRot(rdram, ctx);
        goto after_1;
    // 0x801A2AC8: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x801A2ACC: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801A2AD0: addiu       $v1, $v1, -0x1118
    ctx->r3 = ADD32(ctx->r3, -0X1118);
    // 0x801A2AD4: lwc1        $f10, 0x48($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X48);
    // 0x801A2AD8: lwc1        $f16, 0x4C($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X4C);
    // 0x801A2ADC: lwc1        $f18, 0x50($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X50);
    // 0x801A2AE0: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x801A2AE4: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801A2AE8: swc1        $f10, 0x54($v1)
    MEM_W(0X54, ctx->r3) = ctx->f10.u32l;
    // 0x801A2AEC: swc1        $f16, 0x58($v1)
    MEM_W(0X58, ctx->r3) = ctx->f16.u32l;
    // 0x801A2AF0: swc1        $f18, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->f18.u32l;
    // 0x801A2AF4: lw          $a1, -0x26A8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X26A8);
    // 0x801A2AF8: jal         0x801A655C
    // 0x801A2AFC: lw          $a0, -0x26AC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X26AC);
    Map_GetPathId(rdram, ctx);
        goto after_2;
    // 0x801A2AFC: lw          $a0, -0x26AC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X26AC);
    after_2:
    // 0x801A2B00: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801A2B04: addiu       $v1, $v1, -0x1134
    ctx->r3 = ADD32(ctx->r3, -0X1134);
    // 0x801A2B08: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x801A2B0C: lui         $t7, 0x801D
    ctx->r15 = S32(0X801D << 16);
    // 0x801A2B10: lw          $t7, -0x26C4($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X26C4);
    // 0x801A2B14: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x801A2B18: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x801A2B1C: bne         $a0, $t7, L_801A2B4C
    if (ctx->r4 != ctx->r15) {
        // 0x801A2B20: lui         $at, 0x8017
        ctx->r1 = S32(0X8017 << 16);
            goto L_801A2B4C;
    }
    // 0x801A2B20: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801A2B24: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x801A2B28: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x801A2B2C: sll         $t9, $v0, 3
    ctx->r25 = S32(ctx->r2 << 3);
    // 0x801A2B30: sw          $a0, 0x7BD8($at)
    MEM_W(0X7BD8, ctx->r1) = ctx->r4;
    // 0x801A2B34: subu        $t9, $t9, $v0
    ctx->r25 = SUB32(ctx->r25, ctx->r2);
    // 0x801A2B38: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x801A2B3C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A2B40: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x801A2B44: b           L_801A2B7C
    // 0x801A2B48: sw          $a0, -0x2D4($at)
    MEM_W(-0X2D4, ctx->r1) = ctx->r4;
        goto L_801A2B7C;
    // 0x801A2B48: sw          $a0, -0x2D4($at)
    MEM_W(-0X2D4, ctx->r1) = ctx->r4;
L_801A2B4C:
    // 0x801A2B4C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801A2B50: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801A2B54: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x801A2B58: sll         $t2, $v0, 2
    ctx->r10 = S32(ctx->r2 << 2);
    // 0x801A2B5C: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x801A2B60: sll         $t4, $v0, 3
    ctx->r12 = S32(ctx->r2 << 3);
    // 0x801A2B64: sw          $a0, 0x7BD8($at)
    MEM_W(0X7BD8, ctx->r1) = ctx->r4;
    // 0x801A2B68: subu        $t4, $t4, $v0
    ctx->r12 = SUB32(ctx->r12, ctx->r2);
    // 0x801A2B6C: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x801A2B70: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A2B74: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x801A2B78: sw          $t3, -0x2D4($at)
    MEM_W(-0X2D4, ctx->r1) = ctx->r11;
L_801A2B7C:
    // 0x801A2B7C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x801A2B80: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801A2B84: jr          $ra
    // 0x801A2B88: nop

    return;
    // 0x801A2B88: nop

;}
RECOMP_FUNC void Option_Sound_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801948A8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x801948AC: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801948B0: addiu       $a0, $a0, -0x6D78
    ctx->r4 = ADD32(ctx->r4, -0X6D78);
    // 0x801948B4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x801948B8: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x801948BC: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x801948C0: lw          $t0, 0x7AF8($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7AF8);
    // 0x801948C4: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x801948C8: addiu       $t1, $t1, -0x6DB0
    ctx->r9 = ADD32(ctx->r9, -0X6DB0);
    // 0x801948CC: addiu       $t7, $zero, 0x14
    ctx->r15 = ADD32(0, 0X14);
    // 0x801948D0: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x801948D4: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x801948D8: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x801948DC: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x801948E0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801948E4: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x801948E8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x801948EC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801948F0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801948F4: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x801948F8: jal         0x8019C418
    // 0x801948FC: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    Option_Input_MoveCursor_Y(rdram, ctx);
        goto after_0;
    // 0x801948FC: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    after_0:
    // 0x80194900: beq         $v0, $zero, L_80194950
    if (ctx->r2 == 0) {
        // 0x80194904: lui         $a3, 0x800C
        ctx->r7 = S32(0X800C << 16);
            goto L_80194950;
    }
    // 0x80194904: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80194908: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x8019490C: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80194910: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80194914: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80194918: lui         $t4, 0x800C
    ctx->r12 = S32(0X800C << 16);
    // 0x8019491C: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80194920: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80194924: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x80194928: addiu       $t4, $t4, 0x5D3C
    ctx->r12 = ADD32(ctx->r12, 0X5D3C);
    // 0x8019492C: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x80194930: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x80194934: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x80194938: ori         $a0, $a0, 0x2
    ctx->r4 = ctx->r4 | 0X2;
    // 0x8019493C: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80194940: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80194944: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80194948: jal         0x80019218
    // 0x8019494C: swc1        $f4, -0x6D90($at)
    MEM_W(-0X6D90, ctx->r1) = ctx->f4.u32l;
    Audio_PlaySfx(rdram, ctx);
        goto after_1;
    // 0x8019494C: swc1        $f4, -0x6D90($at)
    MEM_W(-0X6D90, ctx->r1) = ctx->f4.u32l;
    after_1:
L_80194950:
    // 0x80194950: lui         $t5, 0x801C
    ctx->r13 = S32(0X801C << 16);
    // 0x80194954: lw          $t5, -0x6D78($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X6D78);
    // 0x80194958: bne         $t5, $zero, L_80194970
    if (ctx->r13 != 0) {
        // 0x8019495C: nop
    
            goto L_80194970;
    }
    // 0x8019495C: nop

    // 0x80194960: jal         0x80194AEC
    // 0x80194964: nop

    Option_Sound_SetSoundMode(rdram, ctx);
        goto after_2;
    // 0x80194964: nop

    after_2:
    // 0x80194968: b           L_80194978
    // 0x8019496C: nop

        goto L_80194978;
    // 0x8019496C: nop

L_80194970:
    // 0x80194970: jal         0x80194BD0
    // 0x80194974: nop

    Option_Sound_SetVolumeLevels(rdram, ctx);
        goto after_3;
    // 0x80194974: nop

    after_3:
L_80194978:
    // 0x80194978: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x8019497C: lw          $t6, 0x7AF8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7AF8);
    // 0x80194980: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80194984: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80194988: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8019498C: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x80194990: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x80194994: lhu         $v0, -0x2768($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X2768);
    // 0x80194998: andi        $t8, $v0, 0x10
    ctx->r24 = ctx->r2 & 0X10;
    // 0x8019499C: beql        $t8, $zero, L_801949E4
    if (ctx->r24 == 0) {
        // 0x801949A0: andi        $t3, $v0, 0x8000
        ctx->r11 = ctx->r2 & 0X8000;
            goto L_801949E4;
    }
    goto skip_0;
    // 0x801949A0: andi        $t3, $v0, 0x8000
    ctx->r11 = ctx->r2 & 0X8000;
    skip_0:
    // 0x801949A4: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801949A8: addiu       $v0, $v0, -0x6D7C
    ctx->r2 = ADD32(ctx->r2, -0X6D7C);
    // 0x801949AC: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x801949B0: xori        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 ^ 0X1;
    // 0x801949B4: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x801949B8: jal         0x8001D8F4
    // 0x801949BC: lbu         $a0, 0x3($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X3);
    Audio_PlaySoundTest(rdram, ctx);
        goto after_4;
    // 0x801949BC: lbu         $a0, 0x3($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X3);
    after_4:
    // 0x801949C0: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x801949C4: lw          $t1, 0x7AF8($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7AF8);
    // 0x801949C8: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x801949CC: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x801949D0: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x801949D4: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x801949D8: addu        $v0, $v0, $t2
    ctx->r2 = ADD32(ctx->r2, ctx->r10);
    // 0x801949DC: lhu         $v0, -0x2768($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X2768);
    // 0x801949E0: andi        $t3, $v0, 0x8000
    ctx->r11 = ctx->r2 & 0X8000;
L_801949E4:
    // 0x801949E4: beq         $t3, $zero, L_80194A50
    if (ctx->r11 == 0) {
        // 0x801949E8: lui         $a3, 0x800C
        ctx->r7 = S32(0X800C << 16);
            goto L_80194A50;
    }
    // 0x801949E8: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x801949EC: lui         $t4, 0x800C
    ctx->r12 = S32(0X800C << 16);
    // 0x801949F0: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x801949F4: addiu       $t4, $t4, 0x5D3C
    ctx->r12 = ADD32(ctx->r12, 0X5D3C);
    // 0x801949F8: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x801949FC: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x80194A00: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x80194A04: ori         $a0, $a0, 0x3
    ctx->r4 = ctx->r4 | 0X3;
    // 0x80194A08: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80194A0C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80194A10: jal         0x80019218
    // 0x80194A14: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_5;
    // 0x80194A14: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_5:
    // 0x80194A18: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x80194A1C: lw          $t8, 0x7AF8($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7AF8);
    // 0x80194A20: lui         $t5, 0x801C
    ctx->r13 = S32(0X801C << 16);
    // 0x80194A24: lw          $t5, -0x6D78($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X6D78);
    // 0x80194A28: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80194A2C: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80194A30: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x80194A34: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80194A38: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x80194A3C: andi        $t7, $t6, 0x3
    ctx->r15 = ctx->r14 & 0X3;
    // 0x80194A40: addu        $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
    // 0x80194A44: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80194A48: sw          $t7, -0x6D78($at)
    MEM_W(-0X6D78, ctx->r1) = ctx->r15;
    // 0x80194A4C: lhu         $v0, -0x2768($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X2768);
L_80194A50:
    // 0x80194A50: andi        $t0, $v0, 0x4000
    ctx->r8 = ctx->r2 & 0X4000;
    // 0x80194A54: beq         $t0, $zero, L_80194ADC
    if (ctx->r8 == 0) {
        // 0x80194A58: lui         $a0, 0x4900
        ctx->r4 = S32(0X4900 << 16);
            goto L_80194ADC;
    }
    // 0x80194A58: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x80194A5C: lui         $t1, 0x800C
    ctx->r9 = S32(0X800C << 16);
    // 0x80194A60: lui         $t2, 0x800C
    ctx->r10 = S32(0X800C << 16);
    // 0x80194A64: addiu       $t2, $t2, 0x5D3C
    ctx->r10 = ADD32(ctx->r10, 0X5D3C);
    // 0x80194A68: addiu       $a3, $t1, 0x5D34
    ctx->r7 = ADD32(ctx->r9, 0X5D34);
    // 0x80194A6C: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x80194A70: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x80194A74: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80194A78: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80194A7C: ori         $a0, $a0, 0x21
    ctx->r4 = ctx->r4 | 0X21;
    // 0x80194A80: jal         0x80019218
    // 0x80194A84: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_6;
    // 0x80194A84: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_6:
    // 0x80194A88: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80194A8C: addiu       $v0, $v0, -0x6D7C
    ctx->r2 = ADD32(ctx->r2, -0X6D7C);
    // 0x80194A90: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x80194A94: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80194A98: bne         $t3, $at, L_80194AAC
    if (ctx->r11 != ctx->r1) {
        // 0x80194A9C: nop
    
            goto L_80194AAC;
    }
    // 0x80194A9C: nop

    // 0x80194AA0: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x80194AA4: jal         0x8001D8F4
    // 0x80194AA8: lbu         $a0, 0x3($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X3);
    Audio_PlaySoundTest(rdram, ctx);
        goto after_7;
    // 0x80194AA8: lbu         $a0, 0x3($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X3);
    after_7:
L_80194AAC:
    // 0x80194AAC: jal         0x800C3084
    // 0x80194AB0: nop

    Save_Write(rdram, ctx);
        goto after_8;
    // 0x80194AB0: nop

    after_8:
    // 0x80194AB4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80194AB8: sw          $zero, 0x7898($at)
    MEM_W(0X7898, ctx->r1) = 0;
    // 0x80194ABC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80194AC0: addiu       $t4, $zero, 0x3E8
    ctx->r12 = ADD32(0, 0X3E8);
    // 0x80194AC4: sw          $t4, -0x6EDC($at)
    MEM_W(-0X6EDC, ctx->r1) = ctx->r12;
    // 0x80194AC8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80194ACC: sw          $zero, -0x6ED4($at)
    MEM_W(-0X6ED4, ctx->r1) = 0;
    // 0x80194AD0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80194AD4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80194AD8: sw          $t5, -0x6DBC($at)
    MEM_W(-0X6DBC, ctx->r1) = ctx->r13;
L_80194ADC:
    // 0x80194ADC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80194AE0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80194AE4: jr          $ra
    // 0x80194AE8: nop

    return;
    // 0x80194AE8: nop

;}
RECOMP_FUNC void Option_Versus_Setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80193B04: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80193B08: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80193B0C: sb          $t6, 0x1A38($at)
    MEM_B(0X1A38, ctx->r1) = ctx->r14;
    // 0x80193B10: lui         $t8, 0x801C
    ctx->r24 = S32(0X801C << 16);
    // 0x80193B14: lw          $t8, -0x6DB8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X6DB8);
    // 0x80193B18: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80193B1C: sw          $zero, -0x274C($at)
    MEM_W(-0X274C, ctx->r1) = 0;
    // 0x80193B20: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80193B24: addiu       $t7, $zero, 0x320
    ctx->r15 = ADD32(0, 0X320);
    // 0x80193B28: bne         $t8, $zero, L_80193BD0
    if (ctx->r24 != 0) {
        // 0x80193B2C: sw          $t7, -0x7BF0($at)
        MEM_W(-0X7BF0, ctx->r1) = ctx->r15;
            goto L_80193BD0;
    }
    // 0x80193B2C: sw          $t7, -0x7BF0($at)
    MEM_W(-0X7BF0, ctx->r1) = ctx->r15;
    // 0x80193B30: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80193B34: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80193B38: sw          $a3, -0x6E44($at)
    MEM_W(-0X6E44, ctx->r1) = ctx->r7;
    // 0x80193B3C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80193B40: lwc1        $f12, 0x7364($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X7364);
    // 0x80193B44: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80193B48: lwc1        $f2, 0x7368($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X7368);
    // 0x80193B4C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80193B50: lui         $v1, 0x801B
    ctx->r3 = S32(0X801B << 16);
    // 0x80193B54: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x80193B58: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x80193B5C: lui         $a2, 0x801B
    ctx->r6 = S32(0X801B << 16);
    // 0x80193B60: lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // 0x80193B64: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80193B68: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80193B6C: addiu       $v0, $v0, -0x1070
    ctx->r2 = ADD32(ctx->r2, -0X1070);
    // 0x80193B70: addiu       $a2, $a2, -0x107C
    ctx->r6 = ADD32(ctx->r6, -0X107C);
    // 0x80193B74: addiu       $a1, $a1, -0x1064
    ctx->r5 = ADD32(ctx->r5, -0X1064);
    // 0x80193B78: addiu       $a0, $a0, -0x1070
    ctx->r4 = ADD32(ctx->r4, -0X1070);
    // 0x80193B7C: addiu       $v1, $v1, -0x1788
    ctx->r3 = ADD32(ctx->r3, -0X1788);
L_80193B80:
    // 0x80193B80: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80193B84: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80193B88: lwc1        $f8, 0x0($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80193B8C: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x80193B90: addiu       $v1, $v1, 0x60
    ctx->r3 = ADD32(ctx->r3, 0X60);
    // 0x80193B94: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80193B98: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80193B9C: swc1        $f0, -0x40($v1)
    MEM_W(-0X40, ctx->r3) = ctx->f0.u32l;
    // 0x80193BA0: swc1        $f0, -0x3C($v1)
    MEM_W(-0X3C, ctx->r3) = ctx->f0.u32l;
    // 0x80193BA4: sw          $a3, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = ctx->r7;
    // 0x80193BA8: swc1        $f2, -0x1C($v1)
    MEM_W(-0X1C, ctx->r3) = ctx->f2.u32l;
    // 0x80193BAC: swc1        $f12, -0x18($v1)
    MEM_W(-0X18, ctx->r3) = ctx->f12.u32l;
    // 0x80193BB0: swc1        $f14, -0x20($v1)
    MEM_W(-0X20, ctx->r3) = ctx->f14.u32l;
    // 0x80193BB4: sw          $a3, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r7;
    // 0x80193BB8: swc1        $f4, -0x48($v1)
    MEM_W(-0X48, ctx->r3) = ctx->f4.u32l;
    // 0x80193BBC: swc1        $f6, -0x44($v1)
    MEM_W(-0X44, ctx->r3) = ctx->f6.u32l;
    // 0x80193BC0: bne         $a2, $v0, L_80193B80
    if (ctx->r6 != ctx->r2) {
        // 0x80193BC4: swc1        $f8, -0x24($v1)
        MEM_W(-0X24, ctx->r3) = ctx->f8.u32l;
            goto L_80193B80;
    }
    // 0x80193BC4: swc1        $f8, -0x24($v1)
    MEM_W(-0X24, ctx->r3) = ctx->f8.u32l;
    // 0x80193BC8: b           L_80193C20
    // 0x80193BCC: lui         $at, 0xC234
    ctx->r1 = S32(0XC234 << 16);
        goto L_80193C20;
    // 0x80193BCC: lui         $at, 0xC234
    ctx->r1 = S32(0XC234 << 16);
L_80193BD0:
    // 0x80193BD0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80193BD4: sw          $zero, -0x6E44($at)
    MEM_W(-0X6E44, ctx->r1) = 0;
    // 0x80193BD8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80193BDC: lwc1        $f12, 0x736C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X736C);
    // 0x80193BE0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80193BE4: lui         $v1, 0x801B
    ctx->r3 = S32(0X801B << 16);
    // 0x80193BE8: lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // 0x80193BEC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80193BF0: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80193BF4: addiu       $v0, $v0, -0x1668
    ctx->r2 = ADD32(ctx->r2, -0X1668);
    // 0x80193BF8: addiu       $v1, $v1, -0x1788
    ctx->r3 = ADD32(ctx->r3, -0X1788);
    // 0x80193BFC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_80193C00:
    // 0x80193C00: addiu       $v1, $v1, 0x60
    ctx->r3 = ADD32(ctx->r3, 0X60);
    // 0x80193C04: swc1        $f0, -0x3C($v1)
    MEM_W(-0X3C, ctx->r3) = ctx->f0.u32l;
    // 0x80193C08: swc1        $f12, -0x18($v1)
    MEM_W(-0X18, ctx->r3) = ctx->f12.u32l;
    // 0x80193C0C: swc1        $f14, -0x20($v1)
    MEM_W(-0X20, ctx->r3) = ctx->f14.u32l;
    // 0x80193C10: sw          $a3, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = ctx->r7;
    // 0x80193C14: bne         $v1, $v0, L_80193C00
    if (ctx->r3 != ctx->r2) {
        // 0x80193C18: sw          $a3, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->r7;
            goto L_80193C00;
    }
    // 0x80193C18: sw          $a3, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r7;
    // 0x80193C1C: lui         $at, 0xC234
    ctx->r1 = S32(0XC234 << 16);
L_80193C20:
    // 0x80193C20: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80193C24: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80193C28: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80193C2C: swc1        $f10, -0x6DFC($at)
    MEM_W(-0X6DFC, ctx->r1) = ctx->f10.u32l;
    // 0x80193C30: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80193C34: addiu       $v0, $v0, -0x6E78
    ctx->r2 = ADD32(ctx->r2, -0X6E78);
    // 0x80193C38: sw          $zero, -0x6DEC($at)
    MEM_W(-0X6DEC, ctx->r1) = 0;
    // 0x80193C3C: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x80193C40: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80193C44: jr          $ra
    // 0x80193C48: nop

    return;
    // 0x80193C48: nop

;}
RECOMP_FUNC void Title_SunGlare2_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801903B8: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x801903BC: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x801903C0: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x801903C4: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x801903C8: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x801903CC: sw          $fp, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r30;
    // 0x801903D0: sw          $s7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r23;
    // 0x801903D4: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x801903D8: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x801903DC: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x801903E0: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x801903E4: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x801903E8: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x801903EC: sdc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X40, ctx->r29);
    // 0x801903F0: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x801903F4: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x801903F8: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x801903FC: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80190400: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80190404: jal         0x800B8DD0
    // 0x80190408: addiu       $a1, $zero, 0x3E
    ctx->r5 = ADD32(0, 0X3E);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x80190408: addiu       $a1, $zero, 0x3E
    ctx->r5 = ADD32(0, 0X3E);
    after_0:
    // 0x8019040C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80190410: lui         $t7, 0xBA00
    ctx->r15 = S32(0XBA00 << 16);
    // 0x80190414: ori         $t7, $t7, 0x402
    ctx->r15 = ctx->r15 | 0X402;
    // 0x80190418: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8019041C: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80190420: addiu       $t8, $zero, 0x20
    ctx->r24 = ADD32(0, 0X20);
    // 0x80190424: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80190428: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8019042C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80190430: lui         $t0, 0xBA00
    ctx->r8 = S32(0XBA00 << 16);
    // 0x80190434: ori         $t0, $t0, 0x602
    ctx->r8 = ctx->r8 | 0X602;
    // 0x80190438: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8019043C: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80190440: addiu       $t1, $zero, 0x80
    ctx->r9 = ADD32(0, 0X80);
    // 0x80190444: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x80190448: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x8019044C: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x80190450: lw          $a1, -0x7CC0($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7CC0);
    // 0x80190454: lui         $s1, 0x8018
    ctx->r17 = S32(0X8018 << 16);
    // 0x80190458: addiu       $s1, $s1, -0x7C30
    ctx->r17 = ADD32(ctx->r17, -0X7C30);
    // 0x8019045C: blez        $a1, L_8019065C
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80190460: lui         $s2, 0x8018
        ctx->r18 = S32(0X8018 << 16);
            goto L_8019065C;
    }
    // 0x80190460: lui         $s2, 0x8018
    ctx->r18 = S32(0X8018 << 16);
    // 0x80190464: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80190468: lwc1        $f6, 0x70C4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X70C4);
    // 0x8019046C: lwc1        $f4, 0x0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80190470: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80190474: lwc1        $f10, 0x70C8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X70C8);
    // 0x80190478: addiu       $s2, $s2, -0x7C2C
    ctx->r18 = ADD32(ctx->r18, -0X7C2C);
    // 0x8019047C: lwc1        $f8, 0x0($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X0);
    // 0x80190480: mul.s       $f26, $f4, $f6
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f26.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80190484: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80190488: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8019048C: slti        $at, $a1, 0xA
    ctx->r1 = SIGNED(ctx->r5) < 0XA ? 1 : 0;
    // 0x80190490: mul.s       $f28, $f8, $f10
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f28.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80190494: beql        $at, $zero, L_801904B4
    if (ctx->r1 == 0) {
        // 0x80190498: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_801904B4;
    }
    goto skip_0;
    // 0x80190498: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    skip_0:
    // 0x8019049C: mtc1        $a1, $f16
    ctx->f16.u32l = ctx->r5;
    // 0x801904A0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801904A4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801904A8: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x801904AC: div.s       $f22, $f18, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f22.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x801904B0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
L_801904B4:
    // 0x801904B4: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x801904B8: lui         $s3, 0x8014
    ctx->r19 = S32(0X8014 << 16);
    // 0x801904BC: addiu       $s3, $s3, -0x4C40
    ctx->r19 = ADD32(ctx->r19, -0X4C40);
    // 0x801904C0: mul.s       $f22, $f22, $f24
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f22.fl = MUL_S(ctx->f22.fl, ctx->f24.fl);
    // 0x801904C4: jal         0x80005708
    // 0x801904C8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    Matrix_Push(rdram, ctx);
        goto after_1;
    // 0x801904C8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_1:
    // 0x801904CC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801904D0: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x801904D4: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x801904D8: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x801904DC: lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X0);
    // 0x801904E0: jal         0x80005B00
    // 0x801904E4: lui         $a3, 0xC348
    ctx->r7 = S32(0XC348 << 16);
    Matrix_Translate(rdram, ctx);
        goto after_2;
    // 0x801904E4: lui         $a3, 0xC348
    ctx->r7 = S32(0XC348 << 16);
    after_2:
    // 0x801904E8: lui         $s4, 0x801B
    ctx->r20 = S32(0X801B << 16);
    // 0x801904EC: lui         $s5, 0x801B
    ctx->r21 = S32(0X801B << 16);
    // 0x801904F0: lui         $s6, 0x801B
    ctx->r22 = S32(0X801B << 16);
    // 0x801904F4: lui         $s2, 0x801B
    ctx->r18 = S32(0X801B << 16);
    // 0x801904F8: lui         $s1, 0x801B
    ctx->r17 = S32(0X801B << 16);
    // 0x801904FC: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80190500: addiu       $s1, $s1, -0x1B64
    ctx->r17 = ADD32(ctx->r17, -0X1B64);
    // 0x80190504: addiu       $s2, $s2, -0x1AE0
    ctx->r18 = ADD32(ctx->r18, -0X1AE0);
    // 0x80190508: addiu       $s6, $s6, -0x1AC8
    ctx->r22 = ADD32(ctx->r22, -0X1AC8);
    // 0x8019050C: addiu       $s5, $s5, -0x1B04
    ctx->r21 = ADD32(ctx->r21, -0X1B04);
    // 0x80190510: addiu       $s4, $s4, -0x1B34
    ctx->r20 = ADD32(ctx->r20, -0X1B34);
    // 0x80190514: lui         $fp, 0xFFFF
    ctx->r30 = S32(0XFFFF << 16);
    // 0x80190518: lui         $s7, 0xFA00
    ctx->r23 = S32(0XFA00 << 16);
L_8019051C:
    // 0x8019051C: jal         0x80005708
    // 0x80190520: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    Matrix_Push(rdram, ctx);
        goto after_3;
    // 0x80190520: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_3:
    // 0x80190524: lwc1        $f0, 0x0($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X0);
    // 0x80190528: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x8019052C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80190530: mul.s       $f6, $f0, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f26.fl);
    // 0x80190534: neg.s       $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = -ctx->f0.fl;
    // 0x80190538: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8019053C: mul.s       $f10, $f8, $f28
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f28.fl);
    // 0x80190540: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x80190544: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80190548: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x8019054C: jal         0x80005B00
    // 0x80190550: nop

    Matrix_Translate(rdram, ctx);
        goto after_4;
    // 0x80190550: nop

    after_4:
    // 0x80190554: lwc1        $f16, 0x0($s5)
    ctx->f16.u32l = MEM_W(ctx->r21, 0X0);
    // 0x80190558: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8019055C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80190560: mul.s       $f0, $f16, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = MUL_S(ctx->f16.fl, ctx->f24.fl);
    // 0x80190564: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x80190568: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8019056C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80190570: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80190574: jal         0x80005C34
    // 0x80190578: nop

    Matrix_Scale(rdram, ctx);
        goto after_5;
    // 0x80190578: nop

    after_5:
    // 0x8019057C: jal         0x80006EB8
    // 0x80190580: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_6;
    // 0x80190580: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80190584: lw          $t5, 0x0($s6)
    ctx->r13 = MEM_W(ctx->r22, 0X0);
    // 0x80190588: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8019058C: addiu       $t6, $t6, -0x1B4C
    ctx->r14 = ADD32(ctx->r14, -0X1B4C);
    // 0x80190590: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x80190594: nop

    // 0x80190598: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8019059C: mul.s       $f0, $f4, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f22.fl);
    // 0x801905A0: beql        $s1, $t6, L_801905E4
    if (ctx->r17 == ctx->r14) {
        // 0x801905A4: lw          $v0, 0x0($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X0);
            goto L_801905E4;
    }
    goto skip_1;
    // 0x801905A4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    skip_1:
    // 0x801905A8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801905AC: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x801905B0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801905B4: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x801905B8: sw          $s7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r23;
    // 0x801905BC: lbu         $t9, 0x0($s2)
    ctx->r25 = MEM_BU(ctx->r18, 0X0);
    // 0x801905C0: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    // 0x801905C4: sll         $t0, $t9, 8
    ctx->r8 = S32(ctx->r25 << 8);
    // 0x801905C8: or          $t1, $t0, $fp
    ctx->r9 = ctx->r8 | ctx->r30;
    // 0x801905CC: andi        $t4, $t3, 0xFF
    ctx->r12 = ctx->r11 & 0XFF;
    // 0x801905D0: or          $t5, $t1, $t4
    ctx->r13 = ctx->r9 | ctx->r12;
    // 0x801905D4: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x801905D8: b           L_80190614
    // 0x801905DC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
        goto L_80190614;
    // 0x801905DC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801905E0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_801905E4:
    // 0x801905E4: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x801905E8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801905EC: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x801905F0: sw          $s7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r23;
    // 0x801905F4: lbu         $t8, 0x0($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0X0);
    // 0x801905F8: lw          $t2, -0x1AA8($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X1AA8);
    // 0x801905FC: sll         $t9, $t8, 8
    ctx->r25 = S32(ctx->r24 << 8);
    // 0x80190600: or          $t0, $t9, $fp
    ctx->r8 = ctx->r25 | ctx->r30;
    // 0x80190604: andi        $t3, $t2, 0xFF
    ctx->r11 = ctx->r10 & 0XFF;
    // 0x80190608: or          $t1, $t0, $t3
    ctx->r9 = ctx->r8 | ctx->r11;
    // 0x8019060C: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x80190610: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_80190614:
    // 0x80190614: lui         $t5, 0x600
    ctx->r13 = S32(0X600 << 16);
    // 0x80190618: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x8019061C: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x80190620: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80190624: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x80190628: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8019062C: jal         0x80005740
    // 0x80190630: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_7;
    // 0x80190630: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_7:
    // 0x80190634: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x80190638: addiu       $t7, $t7, -0x1B44
    ctx->r15 = ADD32(ctx->r15, -0X1B44);
    // 0x8019063C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80190640: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x80190644: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
    // 0x80190648: addiu       $s6, $s6, 0x4
    ctx->r22 = ADD32(ctx->r22, 0X4);
    // 0x8019064C: bne         $s1, $t7, L_8019051C
    if (ctx->r17 != ctx->r15) {
        // 0x80190650: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_8019051C;
    }
    // 0x80190650: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80190654: jal         0x80005740
    // 0x80190658: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_8;
    // 0x80190658: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_8:
L_8019065C:
    // 0x8019065C: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x80190660: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80190664: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x80190668: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x8019066C: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x80190670: ldc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X40);
    // 0x80190674: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x80190678: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x8019067C: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x80190680: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x80190684: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x80190688: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x8019068C: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x80190690: lw          $s7, 0x64($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X64);
    // 0x80190694: lw          $fp, 0x68($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X68);
    // 0x80190698: jr          $ra
    // 0x8019069C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x8019069C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void Option_RankingRouteFrame_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801982B0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x801982B4: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x801982B8: mtc1        $a3, $f12
    ctx->f12.u32l = ctx->r7;
    // 0x801982BC: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x801982C0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x801982C4: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x801982C8: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x801982CC: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x801982D0: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801982D4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801982D8: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x801982DC: c.lt.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl < ctx->f12.fl;
    // 0x801982E0: nop

    // 0x801982E4: bc1fl       L_801984C0
    if (!c1cs) {
        // 0x801982E8: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_801984C0;
    }
    goto skip_0;
    // 0x801982E8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x801982EC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801982F0: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x801982F4: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x801982F8: c.lt.s      $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f12.fl < ctx->f6.fl;
    // 0x801982FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80198300: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    // 0x80198304: bc1fl       L_801984C0
    if (!c1cs) {
        // 0x80198308: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_801984C0;
    }
    goto skip_1;
    // 0x80198308: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_1:
    // 0x8019830C: sw          $a2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r6;
    // 0x80198310: jal         0x800B8DD0
    // 0x80198314: swc1        $f12, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f12.u32l;
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x80198314: swc1        $f12, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x80198318: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x8019831C: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x80198320: slti        $at, $a2, 0x6
    ctx->r1 = SIGNED(ctx->r6) < 0X6 ? 1 : 0;
    // 0x80198324: beq         $at, $zero, L_80198468
    if (ctx->r1 == 0) {
        // 0x80198328: addiu       $t7, $t6, -0x1
        ctx->r15 = ADD32(ctx->r14, -0X1);
            goto L_80198468;
    }
    // 0x80198328: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8019832C: slt         $at, $a2, $t7
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80198330: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80198334: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80198338: beq         $at, $zero, L_801983D8
    if (ctx->r1 == 0) {
        // 0x8019833C: addiu       $t2, $zero, 0xFF
        ctx->r10 = ADD32(0, 0XFF);
            goto L_801983D8;
    }
    // 0x8019833C: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x80198340: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x80198344: sll         $t3, $a2, 1
    ctx->r11 = S32(ctx->r6 << 1);
    // 0x80198348: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8019834C: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x80198350: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80198354: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x80198358: addu        $t4, $t9, $t3
    ctx->r12 = ADD32(ctx->r25, ctx->r11);
    // 0x8019835C: addiu       $t5, $t5, -0x7790
    ctx->r13 = ADD32(ctx->r13, -0X7790);
    // 0x80198360: addu        $v0, $t4, $t5
    ctx->r2 = ADD32(ctx->r12, ctx->r13);
    // 0x80198364: lbu         $a0, 0x5F($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X5F);
    // 0x80198368: lbu         $a1, 0x61($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X61);
    // 0x8019836C: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    // 0x80198370: srl         $t6, $a0, 4
    ctx->r14 = S32(U32(ctx->r4) >> 4);
    // 0x80198374: srl         $t8, $a1, 4
    ctx->r24 = S32(U32(ctx->r5) >> 4);
    // 0x80198378: andi        $a0, $t6, 0xF
    ctx->r4 = ctx->r14 & 0XF;
    // 0x8019837C: andi        $a1, $t8, 0xF
    ctx->r5 = ctx->r24 & 0XF;
    // 0x80198380: sw          $t1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r9;
    // 0x80198384: jal         0x80199284
    // 0x80198388: sw          $t2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r10;
    Option_GetRouteLineColor(rdram, ctx);
        goto after_1;
    // 0x80198388: sw          $t2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r10;
    after_1:
    // 0x8019838C: sltiu       $at, $v0, 0x5
    ctx->r1 = ctx->r2 < 0X5 ? 1 : 0;
    // 0x80198390: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x80198394: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x80198398: beq         $at, $zero, L_801983D8
    if (ctx->r1 == 0) {
        // 0x8019839C: lw          $t2, 0x3C($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X3C);
            goto L_801983D8;
    }
    // 0x8019839C: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x801983A0: sll         $t3, $v0, 2
    ctx->r11 = S32(ctx->r2 << 2);
    // 0x801983A4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801983A8: addu        $at, $at, $t3
    gpr jr_addend_801983B0 = ctx->r11;
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x801983AC: lw          $t3, 0x73EC($at)
    ctx->r11 = ADD32(ctx->r1, 0X73EC);
    // 0x801983B0: jr          $t3
    // 0x801983B4: nop

    switch (jr_addend_801983B0 >> 2) {
        case 0: goto L_801983B8; break;
        case 1: goto L_801983C4; break;
        case 2: goto L_801983D0; break;
        case 3: goto L_801983C4; break;
        case 4: goto L_801983D0; break;
        default: switch_error(__func__, 0x801983B0, 0x801B73EC);
    }
    // 0x801983B4: nop

L_801983B8:
    // 0x801983B8: addiu       $t2, $zero, 0x10
    ctx->r10 = ADD32(0, 0X10);
    // 0x801983BC: b           L_801983D8
    // 0x801983C0: addiu       $t0, $zero, 0x40
    ctx->r8 = ADD32(0, 0X40);
        goto L_801983D8;
    // 0x801983C0: addiu       $t0, $zero, 0x40
    ctx->r8 = ADD32(0, 0X40);
L_801983C4:
    // 0x801983C4: addiu       $t0, $zero, 0xAF
    ctx->r8 = ADD32(0, 0XAF);
    // 0x801983C8: b           L_801983D8
    // 0x801983CC: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
        goto L_801983D8;
    // 0x801983CC: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
L_801983D0:
    // 0x801983D0: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x801983D4: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_801983D8:
    // 0x801983D8: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x801983DC: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x801983E0: andi        $t8, $t0, 0xFF
    ctx->r24 = ctx->r8 & 0XFF;
    // 0x801983E4: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x801983E8: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x801983EC: andi        $t4, $t1, 0xFF
    ctx->r12 = ctx->r9 & 0XFF;
    // 0x801983F0: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x801983F4: sll         $t7, $t2, 24
    ctx->r15 = S32(ctx->r10 << 24);
    // 0x801983F8: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x801983FC: sll         $t5, $t4, 8
    ctx->r13 = S32(ctx->r12 << 8);
    // 0x80198400: or          $t3, $t7, $t9
    ctx->r11 = ctx->r15 | ctx->r25;
    // 0x80198404: or          $t6, $t3, $t5
    ctx->r14 = ctx->r11 | ctx->r13;
    // 0x80198408: ori         $t8, $t6, 0xFF
    ctx->r24 = ctx->r14 | 0XFF;
    // 0x8019840C: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80198410: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x80198414: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80198418: lwc1        $f8, 0x48($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8019841C: lui         $at, 0x4130
    ctx->r1 = S32(0X4130 << 16);
    // 0x80198420: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80198424: lwc1        $f18, 0x4C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80198428: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8019842C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80198430: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80198434: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80198438: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8019843C: lwc1        $f10, 0x7400($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7400);
    // 0x80198440: lui         $a1, 0x604
    ctx->r5 = S32(0X604 << 16);
    // 0x80198444: addiu       $a1, $a1, 0x47A0
    ctx->r5 = ADD32(ctx->r5, 0X47A0);
    // 0x80198448: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x8019844C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x80198450: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80198454: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80198458: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    // 0x8019845C: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x80198460: jal         0x8009D418
    // 0x80198464: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    Lib_TextureRect_RGBA16(rdram, ctx);
        goto after_2;
    // 0x80198464: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    after_2:
L_80198468:
    // 0x80198468: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8019846C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80198470: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80198474: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80198478: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x8019847C: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80198480: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80198484: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80198488: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x8019848C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80198490: lwc1        $f16, 0x48($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80198494: lwc1        $f18, 0x4C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80198498: lui         $a1, 0x604
    ctx->r5 = S32(0X604 << 16);
    // 0x8019849C: addiu       $a1, $a1, 0x7550
    ctx->r5 = ADD32(ctx->r5, 0X7550);
    // 0x801984A0: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    // 0x801984A4: addiu       $a3, $zero, 0x18
    ctx->r7 = ADD32(0, 0X18);
    // 0x801984A8: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x801984AC: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x801984B0: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x801984B4: jal         0x8009D418
    // 0x801984B8: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    Lib_TextureRect_RGBA16(rdram, ctx);
        goto after_3;
    // 0x801984B8: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_3:
    // 0x801984BC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_801984C0:
    // 0x801984C0: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x801984C4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x801984C8: jr          $ra
    // 0x801984CC: nop

    return;
    // 0x801984CC: nop

;}
RECOMP_FUNC void Option_VersusMenu_Setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801992C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801992C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801992CC: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x801992D0: lw          $t6, -0x6E3C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6E3C);
    // 0x801992D4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801992D8: addiu       $a1, $zero, 0x38
    ctx->r5 = ADD32(0, 0X38);
    // 0x801992DC: beq         $t6, $zero, L_801992EC
    if (ctx->r14 == 0) {
        // 0x801992E0: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_801992EC;
    }
    // 0x801992E0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801992E4: jal         0x8001D444
    // 0x801992E8: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    Audio_PlaySequence(rdram, ctx);
        goto after_0;
    // 0x801992E8: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_0:
L_801992EC:
    // 0x801992EC: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x801992F0: lw          $t8, 0x2870($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X2870);
    // 0x801992F4: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x801992F8: lw          $t7, -0x6EDC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X6EDC);
    // 0x801992FC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80199300: beq         $t8, $zero, L_80199328
    if (ctx->r24 == 0) {
        // 0x80199304: sw          $t7, -0x6C30($at)
        MEM_W(-0X6C30, ctx->r1) = ctx->r15;
            goto L_80199328;
    }
    // 0x80199304: sw          $t7, -0x6C30($at)
    MEM_W(-0X6C30, ctx->r1) = ctx->r15;
    // 0x80199308: lui         $at, 0x4301
    ctx->r1 = S32(0X4301 << 16);
    // 0x8019930C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80199310: lui         $at, 0xC0F0
    ctx->r1 = S32(0XC0F0 << 16);
    // 0x80199314: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80199318: lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // 0x8019931C: addiu       $v0, $v0, -0x19C8
    ctx->r2 = ADD32(ctx->r2, -0X19C8);
    // 0x80199320: swc1        $f4, 0x7C($v0)
    MEM_W(0X7C, ctx->r2) = ctx->f4.u32l;
    // 0x80199324: swc1        $f6, 0x9C($v0)
    MEM_W(0X9C, ctx->r2) = ctx->f6.u32l;
L_80199328:
    // 0x80199328: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x8019932C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80199330: sw          $t9, 0x78A4($at)
    MEM_W(0X78A4, ctx->r1) = ctx->r25;
    // 0x80199334: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80199338: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x8019933C: sw          $t2, -0x6CC0($at)
    MEM_W(-0X6CC0, ctx->r1) = ctx->r10;
    // 0x80199340: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80199344: sw          $zero, 0x1A28($at)
    MEM_W(0X1A28, ctx->r1) = 0;
    // 0x80199348: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8019934C: sw          $zero, -0x7BF0($at)
    MEM_W(-0X7BF0, ctx->r1) = 0;
    // 0x80199350: lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // 0x80199354: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80199358: addiu       $a3, $a3, -0x6C3C
    ctx->r7 = ADD32(ctx->r7, -0X6C3C);
    // 0x8019935C: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x80199360: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80199364: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x80199368: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8019936C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80199370: sb          $zero, 0x0($a3)
    MEM_B(0X0, ctx->r7) = 0;
    // 0x80199374: addiu       $v1, $v1, -0x6C60
    ctx->r3 = ADD32(ctx->r3, -0X6C60);
    // 0x80199378: addiu       $a2, $a2, -0x6CA8
    ctx->r6 = ADD32(ctx->r6, -0X6CA8);
    // 0x8019937C: addiu       $a1, $a1, -0x2750
    ctx->r5 = ADD32(ctx->r5, -0X2750);
    // 0x80199380: addiu       $v0, $v0, 0x1A18
    ctx->r2 = ADD32(ctx->r2, 0X1A18);
    // 0x80199384: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80199388: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x8019938C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80199390:
    // 0x80199390: lbu         $t3, 0x0($a1)
    ctx->r11 = MEM_BU(ctx->r5, 0X0);
    // 0x80199394: addiu       $t2, $a0, 0x1
    ctx->r10 = ADD32(ctx->r4, 0X1);
    // 0x80199398: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x8019939C: bne         $t3, $zero, L_801993B8
    if (ctx->r11 != 0) {
        // 0x801993A0: addiu       $t5, $zero, 0x1
        ctx->r13 = ADD32(0, 0X1);
            goto L_801993B8;
    }
    // 0x801993A0: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801993A4: lbu         $t4, 0x0($a3)
    ctx->r12 = MEM_BU(ctx->r7, 0X0);
    // 0x801993A8: sllv        $t6, $t5, $a0
    ctx->r14 = S32(ctx->r13 << (ctx->r4 & 31));
    // 0x801993AC: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x801993B0: or          $t7, $t4, $t6
    ctx->r15 = ctx->r12 | ctx->r14;
    // 0x801993B4: sb          $t7, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r15;
L_801993B8:
    // 0x801993B8: lbu         $t8, 0x1($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X1);
    // 0x801993BC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801993C0: swc1        $f0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f0.u32l;
    // 0x801993C4: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x801993C8: bne         $t8, $zero, L_801993E8
    if (ctx->r24 != 0) {
        // 0x801993CC: sw          $zero, 0x4($v1)
        MEM_W(0X4, ctx->r3) = 0;
            goto L_801993E8;
    }
    // 0x801993CC: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x801993D0: lbu         $t9, 0x0($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0X0);
    // 0x801993D4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x801993D8: sllv        $t5, $t3, $t2
    ctx->r13 = S32(ctx->r11 << (ctx->r10 & 31));
    // 0x801993DC: or          $t4, $t9, $t5
    ctx->r12 = ctx->r25 | ctx->r13;
    // 0x801993E0: sb          $t4, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r12;
    // 0x801993E4: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
L_801993E8:
    // 0x801993E8: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x801993EC: swc1        $f0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f0.u32l;
    // 0x801993F0: sw          $zero, 0x8($v1)
    MEM_W(0X8, ctx->r3) = 0;
    // 0x801993F4: sw          $zero, 0xC($v1)
    MEM_W(0XC, ctx->r3) = 0;
    // 0x801993F8: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x801993FC: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x80199400: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x80199404: bne         $a0, $t1, L_80199390
    if (ctx->r4 != ctx->r9) {
        // 0x80199408: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_80199390;
    }
    // 0x80199408: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x8019940C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80199410: swc1        $f0, -0x6E18($at)
    MEM_W(-0X6E18, ctx->r1) = ctx->f0.u32l;
    // 0x80199414: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80199418: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8019941C: jr          $ra
    // 0x80199420: nop

    return;
    // 0x80199420: nop

;}
RECOMP_FUNC void Option_RankingTotalHits_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80197DE4: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80197DE8: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80197DEC: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80197DF0: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x80197DF4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80197DF8: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x80197DFC: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x80197E00: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x80197E04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80197E08: jal         0x800B8DD0
    // 0x80197E0C: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x80197E0C: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    after_0:
    // 0x80197E10: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80197E14: lui         $t8, 0x3C3C
    ctx->r24 = S32(0X3C3C << 16);
    // 0x80197E18: ori         $t8, $t8, 0xFFAA
    ctx->r24 = ctx->r24 | 0XFFAA;
    // 0x80197E1C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80197E20: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80197E24: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x80197E28: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80197E2C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80197E30: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x80197E34: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x80197E38: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80197E3C: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80197E40: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x80197E44: lwc1        $f8, 0x73E4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X73E4);
    // 0x80197E48: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80197E4C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80197E50: lwc1        $f10, 0x73E8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X73E8);
    // 0x80197E54: lui         $a1, 0x602
    ctx->r5 = S32(0X602 << 16);
    // 0x80197E58: addiu       $a1, $a1, -0x4B50
    ctx->r5 = ADD32(ctx->r5, -0X4B50);
    // 0x80197E5C: cvt.s.w     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    ctx->f2.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80197E60: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x80197E64: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x80197E68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80197E6C: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    // 0x80197E70: addiu       $a3, $zero, 0x11
    ctx->r7 = ADD32(0, 0X11);
    // 0x80197E74: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    // 0x80197E78: swc1        $f2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f2.u32l;
    // 0x80197E7C: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x80197E80: jal         0x8009D994
    // 0x80197E84: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_1;
    // 0x80197E84: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x80197E88: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80197E8C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80197E90: lui         $t2, 0xFA00
    ctx->r10 = S32(0XFA00 << 16);
    // 0x80197E94: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80197E98: lui         $t3, 0xFFFF
    ctx->r11 = S32(0XFFFF << 16);
    // 0x80197E9C: ori         $t3, $t3, 0xFF
    ctx->r11 = ctx->r11 | 0XFF;
    // 0x80197EA0: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x80197EA4: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x80197EA8: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x80197EAC: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x80197EB0: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x80197EB4: addiu       $t4, $t4, 0x7164
    ctx->r12 = ADD32(ctx->r12, 0X7164);
    // 0x80197EB8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80197EBC: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80197EC0: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80197EC4: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x80197EC8: jal         0x800A1200
    // 0x80197ECC: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    Graphics_DisplaySmallText(rdram, ctx);
        goto after_2;
    // 0x80197ECC: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    after_2:
    // 0x80197ED0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80197ED4: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x80197ED8: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80197EDC: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x80197EE0: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x80197EE4: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80197EE8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80197EEC: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x80197EF0: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x80197EF4: addiu       $t0, $t0, -0x7DE0
    ctx->r8 = ADD32(ctx->r8, -0X7DE0);
    // 0x80197EF8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80197EFC: addu        $a3, $t9, $t0
    ctx->r7 = ADD32(ctx->r25, ctx->r8);
    // 0x80197F00: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x80197F04: jal         0x8008BCBC
    // 0x80197F08: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    HUD_CountDigits(rdram, ctx);
        goto after_3;
    // 0x80197F08: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    after_3:
    // 0x80197F0C: sll         $t1, $v0, 3
    ctx->r9 = S32(ctx->r2 << 3);
    // 0x80197F10: addiu       $t2, $t1, -0x8
    ctx->r10 = ADD32(ctx->r9, -0X8);
    // 0x80197F14: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x80197F18: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80197F1C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80197F20: lwc1        $f16, 0x3C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80197F24: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80197F28: lui         $at, 0x4110
    ctx->r1 = S32(0X4110 << 16);
    // 0x80197F2C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80197F30: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x80197F34: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80197F38: lwc1        $f18, 0x38($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80197F3C: lw          $a2, 0x0($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X0);
    // 0x80197F40: sub.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x80197F44: add.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x80197F48: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80197F4C: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80197F50: mfc1        $a0, $f16
    ctx->r4 = (int32_t)ctx->f16.u32l;
    // 0x80197F54: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80197F58: jal         0x8009FEA0
    // 0x80197F5C: nop

    Graphics_DisplaySmallNumber(rdram, ctx);
        goto after_4;
    // 0x80197F5C: nop

    after_4:
    // 0x80197F60: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80197F64: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80197F68: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80197F6C: jr          $ra
    // 0x80197F70: nop

    return;
    // 0x80197F70: nop

;}
RECOMP_FUNC void Title_SetCamUp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80191844: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80191848: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8019184C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80191850: swc1        $f12, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f12.u32l;
    // 0x80191854: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80191858: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019185C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80191860: lwc1        $f6, 0x7100($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7100);
    // 0x80191864: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80191868: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x8019186C: mul.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x80191870: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x80191874: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80191878: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8019187C: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x80191880: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80191884: jal         0x80005E90
    // 0x80191888: nop

    Matrix_RotateY(rdram, ctx);
        goto after_0;
    // 0x80191888: nop

    after_0:
    // 0x8019188C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80191890: lwc1        $f10, 0x7104($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7104);
    // 0x80191894: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80191898: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8019189C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801918A0: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x801918A4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801918A8: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x801918AC: jal         0x80005D44
    // 0x801918B0: nop

    Matrix_RotateX(rdram, ctx);
        goto after_1;
    // 0x801918B0: nop

    after_1:
    // 0x801918B4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801918B8: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801918BC: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x801918C0: jal         0x80006970
    // 0x801918C4: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    Matrix_MultVec3f(rdram, ctx);
        goto after_2;
    // 0x801918C4: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    after_2:
    // 0x801918C8: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x801918CC: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801918D0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801918D4: swc1        $f4, -0x7D64($at)
    MEM_W(-0X7D64, ctx->r1) = ctx->f4.u32l;
    // 0x801918D8: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801918DC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801918E0: swc1        $f6, -0x7D60($at)
    MEM_W(-0X7D60, ctx->r1) = ctx->f6.u32l;
    // 0x801918E4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801918E8: swc1        $f8, -0x7D5C($at)
    MEM_W(-0X7D5C, ctx->r1) = ctx->f8.u32l;
    // 0x801918EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801918F0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801918F4: jr          $ra
    // 0x801918F8: nop

    return;
    // 0x801918F8: nop

;}
RECOMP_FUNC void Map_Wipe_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A9814: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x801A9818: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x801A981C: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x801A9820: lw          $t6, -0x7D80($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7D80);
    // 0x801A9824: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A9828: beql        $t6, $zero, L_801A9904
    if (ctx->r14 == 0) {
        // 0x801A982C: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_801A9904;
    }
    goto skip_0;
    // 0x801A982C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_0:
    // 0x801A9830: jal         0x80005708
    // 0x801A9834: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Push(rdram, ctx);
        goto after_0;
    // 0x801A9834: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_0:
    // 0x801A9838: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A983C: lwc1        $f4, -0x2600($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2600);
    // 0x801A9840: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A9844: lwc1        $f6, -0x25FC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X25FC);
    // 0x801A9848: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A984C: lwc1        $f8, -0x25F8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X25F8);
    // 0x801A9850: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A9854: lwc1        $f10, -0x25E0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X25E0);
    // 0x801A9858: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A985C: lwc1        $f16, -0x25DC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X25DC);
    // 0x801A9860: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A9864: lwc1        $f18, -0x25D8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X25D8);
    // 0x801A9868: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A986C: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801A9870: lui         $a2, 0x801D
    ctx->r6 = S32(0X801D << 16);
    // 0x801A9874: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801A9878: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801A987C: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x801A9880: lw          $a3, -0x2604($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X2604);
    // 0x801A9884: lw          $a2, -0x2608($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X2608);
    // 0x801A9888: lw          $a1, -0x260C($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X260C);
    // 0x801A988C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x801A9890: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x801A9894: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x801A9898: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x801A989C: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x801A98A0: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    // 0x801A98A4: jal         0x80006E3C
    // 0x801A98A8: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    Matrix_LookAt(rdram, ctx);
        goto after_1;
    // 0x801A98A8: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    after_1:
    // 0x801A98AC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A98B0: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801A98B4: lui         $a2, 0x801D
    ctx->r6 = S32(0X801D << 16);
    // 0x801A98B8: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801A98BC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801A98C0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x801A98C4: lw          $a3, -0x15A0($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X15A0);
    // 0x801A98C8: lw          $a2, -0x15A4($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X15A4);
    // 0x801A98CC: lw          $a1, -0x15A8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X15A8);
    // 0x801A98D0: jal         0x80005B00
    // 0x801A98D4: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Translate(rdram, ctx);
        goto after_2;
    // 0x801A98D4: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_2:
    // 0x801A98D8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801A98DC: jal         0x80006EB8
    // 0x801A98E0: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_3;
    // 0x801A98E0: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    after_3:
    // 0x801A98E4: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801A98E8: lw          $a1, -0x7D7C($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7D7C);
    // 0x801A98EC: jal         0x80084688
    // 0x801A98F0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    Wipe_Draw(rdram, ctx);
        goto after_4;
    // 0x801A98F0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_4:
    // 0x801A98F4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A98F8: jal         0x80005740
    // 0x801A98FC: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Pop(rdram, ctx);
        goto after_5;
    // 0x801A98FC: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_5:
    // 0x801A9900: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_801A9904:
    // 0x801A9904: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x801A9908: jr          $ra
    // 0x801A990C: nop

    return;
    // 0x801A990C: nop

;}
RECOMP_FUNC void Map_SolarRays_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A74F4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x801A74F8: lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // 0x801A74FC: addiu       $v0, $v0, -0xB60
    ctx->r2 = ADD32(ctx->r2, -0XB60);
    // 0x801A7500: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801A7504: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801A7508: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x801A750C: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x801A7510: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x801A7514: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x801A7518: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x801A751C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x801A7520: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x801A7524: addu        $v1, $v0, $t7
    ctx->r3 = ADD32(ctx->r2, ctx->r15);
    // 0x801A7528: lw          $t8, 0x24($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X24);
    // 0x801A752C: lw          $a2, 0x2FC($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X2FC);
    // 0x801A7530: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801A7534: slti        $at, $t8, 0x81
    ctx->r1 = SIGNED(ctx->r24) < 0X81 ? 1 : 0;
    // 0x801A7538: bne         $at, $zero, L_801A7544
    if (ctx->r1 != 0) {
        // 0x801A753C: addiu       $a1, $zero, 0x43
        ctx->r5 = ADD32(0, 0X43);
            goto L_801A7544;
    }
    // 0x801A753C: addiu       $a1, $zero, 0x43
    ctx->r5 = ADD32(0, 0X43);
    // 0x801A7540: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
L_801A7544:
    // 0x801A7544: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x801A7548: jal         0x800B8DD0
    // 0x801A754C: sw          $a2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r6;
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x801A754C: sw          $a2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r6;
    after_0:
    // 0x801A7550: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x801A7554: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801A7558: andi        $t1, $a2, 0xFF
    ctx->r9 = ctx->r6 & 0XFF;
    // 0x801A755C: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x801A7560: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x801A7564: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x801A7568: or          $t2, $t1, $at
    ctx->r10 = ctx->r9 | ctx->r1;
    // 0x801A756C: lui         $t0, 0xFA00
    ctx->r8 = S32(0XFA00 << 16);
    // 0x801A7570: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x801A7574: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x801A7578: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801A757C: lui         $t4, 0xFB00
    ctx->r12 = S32(0XFB00 << 16);
    // 0x801A7580: lui         $t5, 0x1F00
    ctx->r13 = S32(0X1F00 << 16);
    // 0x801A7584: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x801A7588: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x801A758C: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x801A7590: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x801A7594: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A7598: jal         0x80005708
    // 0x801A759C: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Push(rdram, ctx);
        goto after_1;
    // 0x801A759C: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_1:
    // 0x801A75A0: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x801A75A4: lui         $t8, 0x801D
    ctx->r24 = S32(0X801D << 16);
    // 0x801A75A8: addiu       $t8, $t8, -0x21E0
    ctx->r24 = ADD32(ctx->r24, -0X21E0);
    // 0x801A75AC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A75B0: sll         $t7, $t6, 6
    ctx->r15 = S32(ctx->r14 << 6);
    // 0x801A75B4: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    // 0x801A75B8: jal         0x80005680
    // 0x801A75BC: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Copy(rdram, ctx);
        goto after_2;
    // 0x801A75BC: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_2:
    // 0x801A75C0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A75C4: lwc1        $f4, 0x797C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X797C);
    // 0x801A75C8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A75CC: lwc1        $f6, 0x6A74($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6A74);
    // 0x801A75D0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A75D4: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x801A75D8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x801A75DC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801A75E0: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x801A75E4: jal         0x80005FE0
    // 0x801A75E8: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_3;
    // 0x801A75E8: nop

    after_3:
    // 0x801A75EC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A75F0: lwc1        $f0, 0x7980($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X7980);
    // 0x801A75F4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A75F8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801A75FC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801A7600: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801A7604: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x801A7608: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x801A760C: jal         0x80005C34
    // 0x801A7610: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Scale(rdram, ctx);
        goto after_4;
    // 0x801A7610: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_4:
    // 0x801A7614: jal         0x80006EB8
    // 0x801A7618: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_5;
    // 0x801A7618: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x801A761C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801A7620: lui         $t1, 0x600
    ctx->r9 = S32(0X600 << 16);
    // 0x801A7624: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x801A7628: addiu       $t0, $v0, 0x8
    ctx->r8 = ADD32(ctx->r2, 0X8);
    // 0x801A762C: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x801A7630: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x801A7634: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x801A7638: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A763C: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x801A7640: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x801A7644: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x801A7648: lw          $t5, 0x68F8($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X68F8);
    // 0x801A764C: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x801A7650: jal         0x80005740
    // 0x801A7654: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Pop(rdram, ctx);
        goto after_6;
    // 0x801A7654: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_6:
    // 0x801A7658: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A765C: lwc1        $f10, 0x6A74($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6A74);
    // 0x801A7660: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A7664: lwc1        $f16, 0x7984($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7984);
    // 0x801A7668: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A766C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801A7670: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x801A7674: swc1        $f18, 0x6A74($at)
    MEM_W(0X6A74, ctx->r1) = ctx->f18.u32l;
    // 0x801A7678: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801A767C: jr          $ra
    // 0x801A7680: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x801A7680: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void Option_3DFont_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019DB20: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8019DB24: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8019DB28: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8019DB2C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8019DB30: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8019DB34: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8019DB38: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x8019DB3C: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8019DB40: lbu         $t6, -0x10A4($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X10A4);
    // 0x8019DB44: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x8019DB48: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8019DB4C: beq         $t6, $zero, L_8019DB84
    if (ctx->r14 == 0) {
        // 0x8019DB50: addiu       $at, $zero, -0x1
        ctx->r1 = ADD32(0, -0X1);
            goto L_8019DB84;
    }
    // 0x8019DB50: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8019DB54: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x8019DB58: addiu       $v0, $t7, -0x10A4
    ctx->r2 = ADD32(ctx->r15, -0X10A4);
    // 0x8019DB5C: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
L_8019DB60:
    // 0x8019DB60: bnel        $a0, $v1, L_8019DB74
    if (ctx->r4 != ctx->r3) {
        // 0x8019DB64: lbu         $v1, 0x1($v0)
        ctx->r3 = MEM_BU(ctx->r2, 0X1);
            goto L_8019DB74;
    }
    goto skip_0;
    // 0x8019DB64: lbu         $v1, 0x1($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X1);
    skip_0:
    // 0x8019DB68: b           L_8019DB84
    // 0x8019DB6C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
        goto L_8019DB84;
    // 0x8019DB6C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8019DB70: lbu         $v1, 0x1($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X1);
L_8019DB74:
    // 0x8019DB74: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8019DB78: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8019DB7C: bne         $v1, $zero, L_8019DB60
    if (ctx->r3 != 0) {
        // 0x8019DB80: nop
    
            goto L_8019DB60;
    }
    // 0x8019DB80: nop

L_8019DB84:
    // 0x8019DB84: beq         $a2, $at, L_8019DCD4
    if (ctx->r6 == ctx->r1) {
        // 0x8019DB88: lui         $s0, 0x8013
        ctx->r16 = S32(0X8013 << 16);
            goto L_8019DCD4;
    }
    // 0x8019DB88: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8019DB8C: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x8019DB90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8019DB94: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    // 0x8019DB98: jal         0x800B8DD0
    // 0x8019DB9C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x8019DB9C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x8019DBA0: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x8019DBA4: addiu       $s1, $s1, -0x4C40
    ctx->r17 = ADD32(ctx->r17, -0X4C40);
    // 0x8019DBA8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8019DBAC: lui         $t9, 0xBB00
    ctx->r25 = S32(0XBB00 << 16);
    // 0x8019DBB0: lui         $t0, 0x9C4
    ctx->r8 = S32(0X9C4 << 16);
    // 0x8019DBB4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8019DBB8: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8019DBBC: ori         $t0, $t0, 0xC8
    ctx->r8 = ctx->r8 | 0XC8;
    // 0x8019DBC0: ori         $t9, $t9, 0x1
    ctx->r25 = ctx->r25 | 0X1;
    // 0x8019DBC4: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8019DBC8: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x8019DBCC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8019DBD0: lui         $t2, 0xB700
    ctx->r10 = S32(0XB700 << 16);
    // 0x8019DBD4: lui         $t3, 0x4
    ctx->r11 = S32(0X4 << 16);
    // 0x8019DBD8: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x8019DBDC: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x8019DBE0: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x8019DBE4: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x8019DBE8: jal         0x80005708
    // 0x8019DBEC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Push(rdram, ctx);
        goto after_1;
    // 0x8019DBEC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x8019DBF0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8019DBF4: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8019DBF8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8019DBFC: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x8019DC00: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x8019DC04: jal         0x80005B00
    // 0x8019DC08: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    Matrix_Translate(rdram, ctx);
        goto after_2;
    // 0x8019DC08: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    after_2:
    // 0x8019DC0C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8019DC10: lwc1        $f4, 0x74A4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X74A4);
    // 0x8019DC14: lwc1        $f6, 0x4C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8019DC18: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8019DC1C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8019DC20: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8019DC24: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8019DC28: jal         0x80005FE0
    // 0x8019DC2C: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_3;
    // 0x8019DC2C: nop

    after_3:
    // 0x8019DC30: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8019DC34: lwc1        $f10, 0x74A8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X74A8);
    // 0x8019DC38: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8019DC3C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8019DC40: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8019DC44: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8019DC48: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8019DC4C: jal         0x80005D44
    // 0x8019DC50: nop

    Matrix_RotateX(rdram, ctx);
        goto after_4;
    // 0x8019DC50: nop

    after_4:
    // 0x8019DC54: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8019DC58: lwc1        $f4, 0x74AC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X74AC);
    // 0x8019DC5C: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8019DC60: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8019DC64: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8019DC68: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8019DC6C: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8019DC70: jal         0x80005E90
    // 0x8019DC74: nop

    Matrix_RotateY(rdram, ctx);
        goto after_5;
    // 0x8019DC74: nop

    after_5:
    // 0x8019DC78: lwc1        $f0, 0x40($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8019DC7C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8019DC80: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8019DC84: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8019DC88: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8019DC8C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8019DC90: jal         0x80005C34
    // 0x8019DC94: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_6;
    // 0x8019DC94: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_6:
    // 0x8019DC98: jal         0x80006EB8
    // 0x8019DC9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_7;
    // 0x8019DC9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8019DCA0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8019DCA4: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x8019DCA8: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x8019DCAC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8019DCB0: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8019DCB4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8019DCB8: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8019DCBC: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8019DCC0: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8019DCC4: lw          $t0, -0xCC4($t0)
    ctx->r8 = MEM_W(ctx->r8, -0XCC4);
    // 0x8019DCC8: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x8019DCCC: jal         0x80005740
    // 0x8019DCD0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_8;
    // 0x8019DCD0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_8:
L_8019DCD4:
    // 0x8019DCD4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8019DCD8: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8019DCDC: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8019DCE0: jr          $ra
    // 0x8019DCE4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8019DCE4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void Option_NameEntry_Setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019CBC0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8019CBC4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8019CBC8: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8019CBCC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8019CBD0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8019CBD4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8019CBD8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8019CBDC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8019CBE0: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    // 0x8019CBE4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8019CBE8: jal         0x8001D444
    // 0x8019CBEC: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    Audio_PlaySequence(rdram, ctx);
        goto after_0;
    // 0x8019CBEC: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_0:
    // 0x8019CBF0: addiu       $t6, $zero, 0xD0
    ctx->r14 = ADD32(0, 0XD0);
    // 0x8019CBF4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8019CBF8: sb          $t6, 0x1A38($at)
    MEM_B(0X1A38, ctx->r1) = ctx->r14;
    // 0x8019CBFC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8019CC00: addiu       $t7, $zero, 0x320
    ctx->r15 = ADD32(0, 0X320);
    // 0x8019CC04: sw          $t7, -0x7BF0($at)
    MEM_W(-0X7BF0, ctx->r1) = ctx->r15;
    // 0x8019CC08: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x8019CC0C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019CC10: sw          $s3, -0x6ED0($at)
    MEM_W(-0X6ED0, ctx->r1) = ctx->r19;
    // 0x8019CC14: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8019CC18: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019CC1C: sw          $zero, -0x6ED8($at)
    MEM_W(-0X6ED8, ctx->r1) = 0;
    // 0x8019CC20: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019CC24: swc1        $f4, -0x6EE4($at)
    MEM_W(-0X6EE4, ctx->r1) = ctx->f4.u32l;
    // 0x8019CC28: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x8019CC2C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8019CC30: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x8019CC34: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019CC38: addiu       $a3, $a3, -0x7790
    ctx->r7 = ADD32(ctx->r7, -0X7790);
    // 0x8019CC3C: swc1        $f6, -0x6EE0($at)
    MEM_W(-0X6EE0, ctx->r1) = ctx->f6.u32l;
    // 0x8019CC40: lbu         $t8, 0xEA($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0XEA);
    // 0x8019CC44: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x8019CC48: addiu       $s0, $s0, -0x6EB0
    ctx->r16 = ADD32(ctx->r16, -0X6EB0);
    // 0x8019CC4C: slti        $at, $t8, 0xA
    ctx->r1 = SIGNED(ctx->r24) < 0XA ? 1 : 0;
    // 0x8019CC50: beq         $at, $zero, L_8019CCE4
    if (ctx->r1 == 0) {
        // 0x8019CC54: lui         $s2, 0x801C
        ctx->r18 = S32(0X801C << 16);
            goto L_8019CCE4;
    }
    // 0x8019CC54: lui         $s2, 0x801C
    ctx->r18 = S32(0X801C << 16);
    // 0x8019CC58: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8019CC5C: multu       $t8, $a2
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8019CC60: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019CC64: sw          $a2, -0x6F68($at)
    MEM_W(-0X6F68, ctx->r1) = ctx->r6;
    // 0x8019CC68: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019CC6C: sw          $s3, -0x6EC8($at)
    MEM_W(-0X6EC8, ctx->r1) = ctx->r19;
    // 0x8019CC70: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8019CC74: addiu       $v1, $v1, -0x6EB0
    ctx->r3 = ADD32(ctx->r3, -0X6EB0);
    // 0x8019CC78: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x8019CC7C: lui         $s2, 0x801C
    ctx->r18 = S32(0X801C << 16);
    // 0x8019CC80: lui         $s1, 0x801C
    ctx->r17 = S32(0X801C << 16);
    // 0x8019CC84: mflo        $t9
    ctx->r25 = lo;
    // 0x8019CC88: addu        $v0, $a3, $t9
    ctx->r2 = ADD32(ctx->r7, ctx->r25);
    // 0x8019CC8C: lbu         $t1, 0x18($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X18);
    // 0x8019CC90: lbu         $t3, 0x19($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X19);
    // 0x8019CC94: lbu         $t5, 0x1A($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X1A);
    // 0x8019CC98: lui         $s4, 0x801C
    ctx->r20 = S32(0X801C << 16);
    // 0x8019CC9C: addiu       $s4, $s4, -0x6F44
    ctx->r20 = ADD32(ctx->r20, -0X6F44);
    // 0x8019CCA0: addiu       $s1, $s1, -0x6F50
    ctx->r17 = ADD32(ctx->r17, -0X6F50);
    // 0x8019CCA4: addiu       $s2, $s2, -0x6F60
    ctx->r18 = ADD32(ctx->r18, -0X6F60);
    // 0x8019CCA8: addiu       $s0, $s0, -0x6EB0
    ctx->r16 = ADD32(ctx->r16, -0X6EB0);
    // 0x8019CCAC: sb          $t1, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r9;
    // 0x8019CCB0: sb          $t3, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r11;
    // 0x8019CCB4: sb          $t5, 0x4($v1)
    MEM_B(0X4, ctx->r3) = ctx->r13;
L_8019CCB8:
    // 0x8019CCB8: jal         0x8019DCE8
    // 0x8019CCBC: lbu         $a0, 0x0($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X0);
    Option_GetCharIndex(rdram, ctx);
        goto after_1;
    // 0x8019CCBC: lbu         $a0, 0x0($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X0);
    after_1:
    // 0x8019CCC0: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8019CCC4: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x8019CCC8: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x8019CCCC: sw          $v0, -0x4($s2)
    MEM_W(-0X4, ctx->r18) = ctx->r2;
    // 0x8019CCD0: sw          $s3, -0x4($s1)
    MEM_W(-0X4, ctx->r17) = ctx->r19;
    // 0x8019CCD4: bne         $s1, $s4, L_8019CCB8
    if (ctx->r17 != ctx->r20) {
        // 0x8019CCD8: sb          $zero, -0x1($s0)
        MEM_B(-0X1, ctx->r16) = 0;
            goto L_8019CCB8;
    }
    // 0x8019CCD8: sb          $zero, -0x1($s0)
    MEM_B(-0X1, ctx->r16) = 0;
    // 0x8019CCDC: b           L_8019CD2C
    // 0x8019CCE0: nop

        goto L_8019CD2C;
    // 0x8019CCE0: nop

L_8019CCE4:
    // 0x8019CCE4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019CCE8: sw          $zero, -0x6F68($at)
    MEM_W(-0X6F68, ctx->r1) = 0;
    // 0x8019CCEC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019CCF0: lui         $s1, 0x801C
    ctx->r17 = S32(0X801C << 16);
    // 0x8019CCF4: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8019CCF8: sw          $zero, -0x6EC8($at)
    MEM_W(-0X6EC8, ctx->r1) = 0;
    // 0x8019CCFC: addiu       $v1, $v1, -0x6F44
    ctx->r3 = ADD32(ctx->r3, -0X6F44);
    // 0x8019CD00: addiu       $s1, $s1, -0x6F50
    ctx->r17 = ADD32(ctx->r17, -0X6F50);
    // 0x8019CD04: addiu       $s2, $s2, -0x6F60
    ctx->r18 = ADD32(ctx->r18, -0X6F60);
    // 0x8019CD08: addiu       $v0, $zero, 0x41
    ctx->r2 = ADD32(0, 0X41);
L_8019CD0C:
    // 0x8019CD0C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8019CD10: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x8019CD14: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x8019CD18: sw          $zero, -0x4($s1)
    MEM_W(-0X4, ctx->r17) = 0;
    // 0x8019CD1C: sw          $zero, -0x4($s2)
    MEM_W(-0X4, ctx->r18) = 0;
    // 0x8019CD20: sb          $v0, -0x2($s0)
    MEM_B(-0X2, ctx->r16) = ctx->r2;
    // 0x8019CD24: bne         $s1, $v1, L_8019CD0C
    if (ctx->r17 != ctx->r3) {
        // 0x8019CD28: sb          $zero, -0x1($s0)
        MEM_B(-0X1, ctx->r16) = 0;
            goto L_8019CD0C;
    }
    // 0x8019CD28: sb          $zero, -0x1($s0)
    MEM_B(-0X1, ctx->r16) = 0;
L_8019CD2C:
    // 0x8019CD2C: jal         0x80192598
    // 0x8019CD30: nop

    Option_PlanetTextures_Setup(rdram, ctx);
        goto after_2;
    // 0x8019CD30: nop

    after_2:
    // 0x8019CD34: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8019CD38: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8019CD3C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8019CD40: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8019CD44: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8019CD48: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8019CD4C: jr          $ra
    // 0x8019CD50: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8019CD50: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void Title_CsGreatFoxCloseUp_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018B038: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018B03C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018B040: jal         0x8018E058
    // 0x8018B044: nop

    Title_GreatFox_Draw(rdram, ctx);
        goto after_0;
    // 0x8018B044: nop

    after_0:
    // 0x8018B048: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018B04C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018B050: jr          $ra
    // 0x8018B054: nop

    return;
    // 0x8018B054: nop

;}
RECOMP_FUNC void Title_CsGreatFoxCloseUp_Setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018ABC0: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8018ABC4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8018ABC8: addiu       $v0, $v0, -0x79A8
    ctx->r2 = ADD32(ctx->r2, -0X79A8);
    // 0x8018ABCC: addiu       $t6, $zero, 0x320
    ctx->r14 = ADD32(0, 0X320);
    // 0x8018ABD0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018ABD4: sw          $t6, -0x7BF0($at)
    MEM_W(-0X7BF0, ctx->r1) = ctx->r14;
    // 0x8018ABD8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018ABDC: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8018ABE0: sw          $t7, -0x7964($at)
    MEM_W(-0X7964, ctx->r1) = ctx->r15;
    // 0x8018ABE4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018ABE8: sw          $zero, -0x7CC0($at)
    MEM_W(-0X7CC0, ctx->r1) = 0;
    // 0x8018ABEC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018ABF0: sw          $zero, -0x7CB8($at)
    MEM_W(-0X7CB8, ctx->r1) = 0;
    // 0x8018ABF4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018ABF8: sw          $zero, -0x7CB0($at)
    MEM_W(-0X7CB0, ctx->r1) = 0;
    // 0x8018ABFC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018AC00: sw          $zero, -0x7CAC($at)
    MEM_W(-0X7CAC, ctx->r1) = 0;
    // 0x8018AC04: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018AC08: addiu       $t8, $zero, 0x65
    ctx->r24 = ADD32(0, 0X65);
    // 0x8018AC0C: sw          $t8, -0x7AB8($at)
    MEM_W(-0X7AB8, ctx->r1) = ctx->r24;
    // 0x8018AC10: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018AC14: addiu       $t9, $zero, 0x6A
    ctx->r25 = ADD32(0, 0X6A);
    // 0x8018AC18: sw          $t9, -0x7AB4($at)
    MEM_W(-0X7AB4, ctx->r1) = ctx->r25;
    // 0x8018AC1C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018AC20: addiu       $t0, $zero, 0x5C
    ctx->r8 = ADD32(0, 0X5C);
    // 0x8018AC24: sw          $t0, -0x7AB0($at)
    MEM_W(-0X7AB0, ctx->r1) = ctx->r8;
    // 0x8018AC28: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018AC2C: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x8018AC30: sw          $t1, -0x7AAC($at)
    MEM_W(-0X7AAC, ctx->r1) = ctx->r9;
    // 0x8018AC34: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018AC38: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x8018AC3C: sw          $t2, -0x7AA8($at)
    MEM_W(-0X7AA8, ctx->r1) = ctx->r10;
    // 0x8018AC40: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018AC44: addiu       $t3, $zero, 0xA
    ctx->r11 = ADD32(0, 0XA);
    // 0x8018AC48: sw          $t3, -0x7AA4($at)
    MEM_W(-0X7AA4, ctx->r1) = ctx->r11;
    // 0x8018AC4C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8018AC50: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018AC54: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018AC58: swc1        $f4, -0x7958($at)
    MEM_W(-0X7958, ctx->r1) = ctx->f4.u32l;
    // 0x8018AC5C: lui         $at, 0xC1F0
    ctx->r1 = S32(0XC1F0 << 16);
    // 0x8018AC60: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018AC64: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018AC68: swc1        $f6, -0x7954($at)
    MEM_W(-0X7954, ctx->r1) = ctx->f6.u32l;
    // 0x8018AC6C: lui         $at, 0x43E1
    ctx->r1 = S32(0X43E1 << 16);
    // 0x8018AC70: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018AC74: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018AC78: swc1        $f8, -0x7950($at)
    MEM_W(-0X7950, ctx->r1) = ctx->f8.u32l;
    // 0x8018AC7C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018AC80: swc1        $f0, -0x7938($at)
    MEM_W(-0X7938, ctx->r1) = ctx->f0.u32l;
    // 0x8018AC84: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018AC88: swc1        $f0, -0x7934($at)
    MEM_W(-0X7934, ctx->r1) = ctx->f0.u32l;
    // 0x8018AC8C: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x8018AC90: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018AC94: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018AC98: swc1        $f10, 0x79A0($at)
    MEM_W(0X79A0, ctx->r1) = ctx->f10.u32l;
    // 0x8018AC9C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018ACA0: swc1        $f0, 0x79B8($at)
    MEM_W(0X79B8, ctx->r1) = ctx->f0.u32l;
    // 0x8018ACA4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018ACA8: swc1        $f0, 0x79C0($at)
    MEM_W(0X79C0, ctx->r1) = ctx->f0.u32l;
    // 0x8018ACAC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018ACB0: swc1        $f0, -0x7D64($at)
    MEM_W(-0X7D64, ctx->r1) = ctx->f0.u32l;
    // 0x8018ACB4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8018ACB8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8018ACBC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018ACC0: swc1        $f16, -0x7D60($at)
    MEM_W(-0X7D60, ctx->r1) = ctx->f16.u32l;
    // 0x8018ACC4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018ACC8: swc1        $f0, -0x7D5C($at)
    MEM_W(-0X7D5C, ctx->r1) = ctx->f0.u32l;
    // 0x8018ACCC: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x8018ACD0: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x8018ACD4: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
    // 0x8018ACD8: swc1        $f0, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f0.u32l;
    // 0x8018ACDC: swc1        $f0, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f0.u32l;
    // 0x8018ACE0: swc1        $f0, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f0.u32l;
    // 0x8018ACE4: jr          $ra
    // 0x8018ACE8: nop

    return;
    // 0x8018ACE8: nop

;}
RECOMP_FUNC void Map_CheckPlanetMedal(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A6DAC: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x801A6DB0: bne         $a0, $at, L_801A6E30
    if (ctx->r4 != ctx->r1) {
        // 0x801A6DB4: lui         $t4, 0x8017
        ctx->r12 = S32(0X8017 << 16);
            goto L_801A6E30;
    }
    // 0x801A6DB4: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x801A6DB8: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x801A6DBC: lw          $t6, 0x79F8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X79F8);
    // 0x801A6DC0: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x801A6DC4: addiu       $a2, $a2, -0x7790
    ctx->r6 = ADD32(ctx->r6, -0X7790);
    // 0x801A6DC8: beql        $t6, $zero, L_801A6E10
    if (ctx->r14 == 0) {
        // 0x801A6DCC: lbu         $t8, 0xF($a2)
        ctx->r24 = MEM_BU(ctx->r6, 0XF);
            goto L_801A6E10;
    }
    goto skip_0;
    // 0x801A6DCC: lbu         $t8, 0xF($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0XF);
    skip_0:
    // 0x801A6DD0: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x801A6DD4: addiu       $a2, $a2, -0x7790
    ctx->r6 = ADD32(ctx->r6, -0X7790);
    // 0x801A6DD8: lbu         $v1, 0xF($a2)
    ctx->r3 = MEM_BU(ctx->r6, 0XF);
    // 0x801A6DDC: lbu         $t2, 0xE($a2)
    ctx->r10 = MEM_BU(ctx->r6, 0XE);
    // 0x801A6DE0: sll         $t9, $v1, 28
    ctx->r25 = S32(ctx->r3 << 28);
    // 0x801A6DE4: sll         $t3, $t2, 28
    ctx->r11 = S32(ctx->r10 << 28);
    // 0x801A6DE8: srl         $t4, $t3, 31
    ctx->r12 = S32(U32(ctx->r11) >> 31);
    // 0x801A6DEC: srl         $t0, $t9, 31
    ctx->r8 = S32(U32(ctx->r25) >> 31);
    // 0x801A6DF0: sll         $v0, $v1, 27
    ctx->r2 = S32(ctx->r3 << 27);
    // 0x801A6DF4: srl         $t7, $v0, 31
    ctx->r15 = S32(U32(ctx->r2) >> 31);
    // 0x801A6DF8: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x801A6DFC: andi        $t5, $t4, 0x1
    ctx->r13 = ctx->r12 & 0X1;
    // 0x801A6E00: andi        $v0, $t7, 0x1
    ctx->r2 = ctx->r15 & 0X1;
    // 0x801A6E04: b           L_801A6E98
    // 0x801A6E08: or          $a0, $t1, $t5
    ctx->r4 = ctx->r9 | ctx->r13;
        goto L_801A6E98;
    // 0x801A6E08: or          $a0, $t1, $t5
    ctx->r4 = ctx->r9 | ctx->r13;
    // 0x801A6E0C: lbu         $t8, 0xF($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0XF);
L_801A6E10:
    // 0x801A6E10: lbu         $t2, 0xE($a2)
    ctx->r10 = MEM_BU(ctx->r6, 0XE);
    // 0x801A6E14: sll         $v0, $t8, 30
    ctx->r2 = S32(ctx->r24 << 30);
    // 0x801A6E18: srl         $t6, $v0, 31
    ctx->r14 = S32(U32(ctx->r2) >> 31);
    // 0x801A6E1C: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x801A6E20: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x801A6E24: andi        $v0, $t6, 0x1
    ctx->r2 = ctx->r14 & 0X1;
    // 0x801A6E28: b           L_801A6E98
    // 0x801A6E2C: or          $a0, $t9, $t3
    ctx->r4 = ctx->r25 | ctx->r11;
        goto L_801A6E98;
    // 0x801A6E2C: or          $a0, $t9, $t3
    ctx->r4 = ctx->r25 | ctx->r11;
L_801A6E30:
    // 0x801A6E30: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x801A6E34: bne         $a0, $at, L_801A6E40
    if (ctx->r4 != ctx->r1) {
        // 0x801A6E38: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_801A6E40;
    }
    // 0x801A6E38: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x801A6E3C: addiu       $v1, $zero, 0xD
    ctx->r3 = ADD32(0, 0XD);
L_801A6E40:
    // 0x801A6E40: lw          $t4, 0x79F8($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X79F8);
    // 0x801A6E44: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x801A6E48: addiu       $a2, $a2, -0x7790
    ctx->r6 = ADD32(ctx->r6, -0X7790);
    // 0x801A6E4C: beq         $t4, $zero, L_801A6E80
    if (ctx->r12 == 0) {
        // 0x801A6E50: addu        $t0, $a2, $v1
        ctx->r8 = ADD32(ctx->r6, ctx->r3);
            goto L_801A6E80;
    }
    // 0x801A6E50: addu        $t0, $a2, $v1
    ctx->r8 = ADD32(ctx->r6, ctx->r3);
    // 0x801A6E54: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x801A6E58: addiu       $a2, $a2, -0x7790
    ctx->r6 = ADD32(ctx->r6, -0X7790);
    // 0x801A6E5C: addu        $t1, $a2, $v1
    ctx->r9 = ADD32(ctx->r6, ctx->r3);
    // 0x801A6E60: lbu         $a1, 0x0($t1)
    ctx->r5 = MEM_BU(ctx->r9, 0X0);
    // 0x801A6E64: sll         $v0, $a1, 27
    ctx->r2 = S32(ctx->r5 << 27);
    // 0x801A6E68: sll         $a0, $a1, 28
    ctx->r4 = S32(ctx->r5 << 28);
    // 0x801A6E6C: srl         $t5, $v0, 31
    ctx->r13 = S32(U32(ctx->r2) >> 31);
    // 0x801A6E70: srl         $t7, $a0, 31
    ctx->r15 = S32(U32(ctx->r4) >> 31);
    // 0x801A6E74: andi        $v0, $t5, 0x1
    ctx->r2 = ctx->r13 & 0X1;
    // 0x801A6E78: b           L_801A6E98
    // 0x801A6E7C: andi        $a0, $t7, 0x1
    ctx->r4 = ctx->r15 & 0X1;
        goto L_801A6E98;
    // 0x801A6E7C: andi        $a0, $t7, 0x1
    ctx->r4 = ctx->r15 & 0X1;
L_801A6E80:
    // 0x801A6E80: lbu         $a0, 0x0($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X0);
    // 0x801A6E84: sll         $v0, $a0, 30
    ctx->r2 = S32(ctx->r4 << 30);
    // 0x801A6E88: srl         $t2, $v0, 31
    ctx->r10 = S32(U32(ctx->r2) >> 31);
    // 0x801A6E8C: andi        $t3, $a0, 0x1
    ctx->r11 = ctx->r4 & 0X1;
    // 0x801A6E90: andi        $v0, $t2, 0x1
    ctx->r2 = ctx->r10 & 0X1;
    // 0x801A6E94: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
L_801A6E98:
    // 0x801A6E98: beq         $v0, $zero, L_801A6EA8
    if (ctx->r2 == 0) {
        // 0x801A6E9C: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_801A6EA8;
    }
    // 0x801A6E9C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x801A6EA0: b           L_801A6EB4
    // 0x801A6EA4: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
        goto L_801A6EB4;
    // 0x801A6EA4: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
L_801A6EA8:
    // 0x801A6EA8: beql        $a0, $zero, L_801A6EB8
    if (ctx->r4 == 0) {
        // 0x801A6EAC: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_801A6EB8;
    }
    goto skip_1;
    // 0x801A6EAC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_1:
    // 0x801A6EB0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_801A6EB4:
    // 0x801A6EB4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_801A6EB8:
    // 0x801A6EB8: jr          $ra
    // 0x801A6EBC: nop

    return;
    // 0x801A6EBC: nop

;}
RECOMP_FUNC void Option_Entry_Setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801924C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801924C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801924CC: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x801924D0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x801924D4: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801924D8: lw          $v0, -0x6EDC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6EDC);
    // 0x801924DC: sb          $t6, 0x1A38($at)
    MEM_B(0X1A38, ctx->r1) = ctx->r14;
    // 0x801924E0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801924E4: sw          $zero, -0x6ED4($at)
    MEM_W(-0X6ED4, ctx->r1) = 0;
    // 0x801924E8: slti        $at, $v0, 0x1F
    ctx->r1 = SIGNED(ctx->r2) < 0X1F ? 1 : 0;
    // 0x801924EC: bne         $at, $zero, L_80192504
    if (ctx->r1 != 0) {
        // 0x801924F0: addiu       $at, $zero, 0x7D0
        ctx->r1 = ADD32(0, 0X7D0);
            goto L_80192504;
    }
    // 0x801924F0: addiu       $at, $zero, 0x7D0
    ctx->r1 = ADD32(0, 0X7D0);
    // 0x801924F4: beq         $v0, $at, L_80192540
    if (ctx->r2 == ctx->r1) {
        // 0x801924F8: nop
    
            goto L_80192540;
    }
    // 0x801924F8: nop

    // 0x801924FC: b           L_8019258C
    // 0x80192500: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8019258C;
    // 0x80192500: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80192504:
    // 0x80192504: sltiu       $at, $v0, 0x1F
    ctx->r1 = ctx->r2 < 0X1F ? 1 : 0;
    // 0x80192508: beq         $at, $zero, L_80192588
    if (ctx->r1 == 0) {
        // 0x8019250C: sll         $t7, $v0, 2
        ctx->r15 = S32(ctx->r2 << 2);
            goto L_80192588;
    }
    // 0x8019250C: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x80192510: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80192514: addu        $at, $at, $t7
    gpr jr_addend_8019251C = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80192518: lw          $t7, 0x72AC($at)
    ctx->r15 = ADD32(ctx->r1, 0X72AC);
    // 0x8019251C: jr          $t7
    // 0x80192520: nop

    switch (jr_addend_8019251C >> 2) {
        case 0: goto L_80192524; break;
        case 1: goto L_80192588; break;
        case 2: goto L_80192588; break;
        case 3: goto L_80192550; break;
        case 4: goto L_80192560; break;
        case 5: goto L_80192580; break;
        case 6: goto L_80192570; break;
        case 7: goto L_80192588; break;
        case 8: goto L_80192588; break;
        case 9: goto L_80192588; break;
        case 10: goto L_80192530; break;
        case 11: goto L_80192588; break;
        case 12: goto L_80192588; break;
        case 13: goto L_80192588; break;
        case 14: goto L_80192588; break;
        case 15: goto L_80192588; break;
        case 16: goto L_80192588; break;
        case 17: goto L_80192588; break;
        case 18: goto L_80192588; break;
        case 19: goto L_80192588; break;
        case 20: goto L_80192530; break;
        case 21: goto L_80192588; break;
        case 22: goto L_80192588; break;
        case 23: goto L_80192588; break;
        case 24: goto L_80192588; break;
        case 25: goto L_80192588; break;
        case 26: goto L_80192588; break;
        case 27: goto L_80192588; break;
        case 28: goto L_80192588; break;
        case 29: goto L_80192588; break;
        case 30: goto L_80192530; break;
        default: switch_error(__func__, 0x8019251C, 0x801B72AC);
    }
    // 0x80192520: nop

L_80192524:
    // 0x80192524: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80192528: b           L_80192588
    // 0x8019252C: sw          $zero, 0x7898($at)
    MEM_W(0X7898, ctx->r1) = 0;
        goto L_80192588;
    // 0x8019252C: sw          $zero, 0x7898($at)
    MEM_W(0X7898, ctx->r1) = 0;
L_80192530:
    // 0x80192530: jal         0x801992C4
    // 0x80192534: nop

    Option_VersusMenu_Setup(rdram, ctx);
        goto after_0;
    // 0x80192534: nop

    after_0:
    // 0x80192538: b           L_8019258C
    // 0x8019253C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8019258C;
    // 0x8019253C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80192540:
    // 0x80192540: jal         0x80199FA8
    // 0x80192544: nop

    Option_VersusStage_Setup(rdram, ctx);
        goto after_1;
    // 0x80192544: nop

    after_1:
    // 0x80192548: b           L_8019258C
    // 0x8019254C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8019258C;
    // 0x8019254C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80192550:
    // 0x80192550: jal         0x80196E54
    // 0x80192554: nop

    Option_Ranking_Setup(rdram, ctx);
        goto after_2;
    // 0x80192554: nop

    after_2:
    // 0x80192558: b           L_8019258C
    // 0x8019255C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8019258C;
    // 0x8019255C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80192560:
    // 0x80192560: jal         0x80194678
    // 0x80192564: nop

    Option_Sound_Setup(rdram, ctx);
        goto after_3;
    // 0x80192564: nop

    after_3:
    // 0x80192568: b           L_8019258C
    // 0x8019256C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8019258C;
    // 0x8019256C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80192570:
    // 0x80192570: jal         0x801958DC
    // 0x80192574: nop

    Option_ExpertSound_Setup(rdram, ctx);
        goto after_4;
    // 0x80192574: nop

    after_4:
    // 0x80192578: b           L_8019258C
    // 0x8019257C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8019258C;
    // 0x8019257C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80192580:
    // 0x80192580: jal         0x80196260
    // 0x80192584: nop

    Option_Data_Setup(rdram, ctx);
        goto after_5;
    // 0x80192584: nop

    after_5:
L_80192588:
    // 0x80192588: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8019258C:
    // 0x8019258C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80192590: jr          $ra
    // 0x80192594: nop

    return;
    // 0x80192594: nop

;}
RECOMP_FUNC void Map_BriefingRadio_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801AB978: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x801AB97C: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x801AB980: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x801AB984: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x801AB988: sw          $fp, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r30;
    // 0x801AB98C: sw          $s7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r23;
    // 0x801AB990: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x801AB994: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x801AB998: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x801AB99C: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x801AB9A0: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x801AB9A4: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x801AB9A8: sdc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X38, ctx->r29);
    // 0x801AB9AC: sdc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X30, ctx->r29);
    // 0x801AB9B0: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x801AB9B4: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x801AB9B8: beq         $s4, $at, L_801AB9E8
    if (ctx->r20 == ctx->r1) {
        // 0x801AB9BC: addiu       $t6, $s4, -0xA
        ctx->r14 = ADD32(ctx->r20, -0XA);
            goto L_801AB9E8;
    }
    // 0x801AB9BC: addiu       $t6, $s4, -0xA
    ctx->r14 = ADD32(ctx->r20, -0XA);
    // 0x801AB9C0: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x801AB9C4: beq         $s4, $at, L_801AB9E8
    if (ctx->r20 == ctx->r1) {
        // 0x801AB9C8: addiu       $at, $zero, 0x14
        ctx->r1 = ADD32(0, 0X14);
            goto L_801AB9E8;
    }
    // 0x801AB9C8: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x801AB9CC: beq         $s4, $at, L_801AB9F4
    if (ctx->r20 == ctx->r1) {
        // 0x801AB9D0: lui         $s5, 0x801D
        ctx->r21 = S32(0X801D << 16);
            goto L_801AB9F4;
    }
    // 0x801AB9D0: lui         $s5, 0x801D
    ctx->r21 = S32(0X801D << 16);
    // 0x801AB9D4: addiu       $at, $zero, 0x15
    ctx->r1 = ADD32(0, 0X15);
    // 0x801AB9D8: beq         $s4, $at, L_801AB9F4
    if (ctx->r20 == ctx->r1) {
        // 0x801AB9DC: nop
    
            goto L_801AB9F4;
    }
    // 0x801AB9DC: nop

    // 0x801AB9E0: b           L_801ABCA4
    // 0x801AB9E4: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
        goto L_801ABCA4;
    // 0x801AB9E4: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
L_801AB9E8:
    // 0x801AB9E8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801AB9EC: b           L_801ABCA0
    // 0x801AB9F0: sw          $t6, -0x27F0($at)
    MEM_W(-0X27F0, ctx->r1) = ctx->r14;
        goto L_801ABCA0;
    // 0x801AB9F0: sw          $t6, -0x27F0($at)
    MEM_W(-0X27F0, ctx->r1) = ctx->r14;
L_801AB9F4:
    // 0x801AB9F4: addiu       $s5, $s5, -0x158C
    ctx->r21 = ADD32(ctx->r21, -0X158C);
    // 0x801AB9F8: lw          $t7, 0x0($s5)
    ctx->r15 = MEM_W(ctx->r21, 0X0);
    // 0x801AB9FC: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x801ABA00: addiu       $s2, $s2, 0x7E64
    ctx->r18 = ADD32(ctx->r18, 0X7E64);
    // 0x801ABA04: beq         $t7, $zero, L_801ABCA0
    if (ctx->r15 == 0) {
        // 0x801ABA08: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_801ABCA0;
    }
    // 0x801ABA08: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x801ABA0C: jal         0x800B8DD0
    // 0x801ABA10: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x801ABA10: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    after_0:
    // 0x801ABA14: lui         $fp, 0xFA00
    ctx->r30 = S32(0XFA00 << 16);
    // 0x801ABA18: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x801ABA1C: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x801ABA20: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x801ABA24: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x801ABA28: sw          $t8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r24;
    // 0x801ABA2C: sw          $fp, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r30;
    // 0x801ABA30: lw          $t9, 0x0($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X0);
    // 0x801ABA34: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801ABA38: lui         $s3, 0x604
    ctx->r19 = S32(0X604 << 16);
    // 0x801ABA3C: andi        $t0, $t9, 0xFF
    ctx->r8 = ctx->r25 & 0XFF;
    // 0x801ABA40: or          $t1, $t0, $at
    ctx->r9 = ctx->r8 | ctx->r1;
    // 0x801ABA44: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x801ABA48: lui         $at, 0x429A
    ctx->r1 = S32(0X429A << 16);
    // 0x801ABA4C: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x801ABA50: lui         $at, 0x434D
    ctx->r1 = S32(0X434D << 16);
    // 0x801ABA54: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x801ABA58: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801ABA5C: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x801ABA60: addiu       $s3, $s3, 0x4820
    ctx->r19 = ADD32(ctx->r19, 0X4820);
L_801ABA64:
    // 0x801ABA64: mtc1        $s1, $f4
    ctx->f4.u32l = ctx->r17;
    // 0x801ABA68: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x801ABA6C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801ABA70: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801ABA74: sll         $t2, $s0, 1
    ctx->r10 = S32(ctx->r16 << 1);
    // 0x801ABA78: addu        $a1, $s3, $t2
    ctx->r5 = ADD32(ctx->r19, ctx->r10);
    // 0x801ABA7C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x801ABA80: addiu       $a2, $zero, 0x5C
    ctx->r6 = ADD32(0, 0X5C);
    // 0x801ABA84: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x801ABA88: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x801ABA8C: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    // 0x801ABA90: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x801ABA94: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x801ABA98: add.s       $f16, $f10, $f24
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f24.fl;
    // 0x801ABA9C: jal         0x8009D418
    // 0x801ABAA0: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    Lib_TextureRect_RGBA16(rdram, ctx);
        goto after_1;
    // 0x801ABAA0: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    after_1:
    // 0x801ABAA4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x801ABAA8: slti        $at, $s1, 0xC
    ctx->r1 = SIGNED(ctx->r17) < 0XC ? 1 : 0;
    // 0x801ABAAC: bne         $at, $zero, L_801ABA64
    if (ctx->r1 != 0) {
        // 0x801ABAB0: addiu       $s0, $s0, 0x170
        ctx->r16 = ADD32(ctx->r16, 0X170);
            goto L_801ABA64;
    }
    // 0x801ABAB0: addiu       $s0, $s0, 0x170
    ctx->r16 = ADD32(ctx->r16, 0X170);
    // 0x801ABAB4: lui         $at, 0x4240
    ctx->r1 = S32(0X4240 << 16);
    // 0x801ABAB8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801ABABC: lui         $a1, 0x604
    ctx->r5 = S32(0X604 << 16);
    // 0x801ABAC0: addiu       $a1, $a1, 0x6AA0
    ctx->r5 = ADD32(ctx->r5, 0X6AA0);
    // 0x801ABAC4: add.s       $f4, $f24, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f24.fl + ctx->f18.fl;
    // 0x801ABAC8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x801ABACC: addiu       $a2, $zero, 0x5C
    ctx->r6 = ADD32(0, 0X5C);
    // 0x801ABAD0: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x801ABAD4: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x801ABAD8: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    // 0x801ABADC: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x801ABAE0: jal         0x8009D418
    // 0x801ABAE4: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    Lib_TextureRect_RGBA16(rdram, ctx);
        goto after_2;
    // 0x801ABAE4: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    after_2:
    // 0x801ABAE8: addiu       $at, $zero, 0x15
    ctx->r1 = ADD32(0, 0X15);
    // 0x801ABAEC: bne         $s4, $at, L_801ABB2C
    if (ctx->r20 != ctx->r1) {
        // 0x801ABAF0: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_801ABB2C;
    }
    // 0x801ABAF0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x801ABAF4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801ABAF8: ldc1        $f8, 0x7B08($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, 0X7B08);
    // 0x801ABAFC: cvt.d.s     $f6, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f6.d = CVT_D_S(ctx->f22.fl);
    // 0x801ABB00: lui         $a1, 0x604
    ctx->r5 = S32(0X604 << 16);
    // 0x801ABB04: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x801ABB08: addiu       $a1, $a1, 0x6CD0
    ctx->r5 = ADD32(ctx->r5, 0X6CD0);
    // 0x801ABB0C: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x801ABB10: addiu       $a3, $zero, 0x22
    ctx->r7 = ADD32(0, 0X22);
    // 0x801ABB14: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801ABB18: swc1        $f24, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f24.u32l;
    // 0x801ABB1C: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x801ABB20: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x801ABB24: jal         0x8009D418
    // 0x801ABB28: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    Lib_TextureRect_RGBA16(rdram, ctx);
        goto after_3;
    // 0x801ABB28: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_3:
L_801ABB2C:
    // 0x801ABB2C: lui         $at, 0x4303
    ctx->r1 = S32(0X4303 << 16);
    // 0x801ABB30: lui         $s3, 0x8017
    ctx->r19 = S32(0X8017 << 16);
    // 0x801ABB34: lui         $s4, 0x801B
    ctx->r20 = S32(0X801B << 16);
    // 0x801ABB38: lui         $s6, 0x801B
    ctx->r22 = S32(0X801B << 16);
    // 0x801ABB3C: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x801ABB40: addiu       $s6, $s6, 0x6B18
    ctx->r22 = ADD32(ctx->r22, 0X6B18);
    // 0x801ABB44: addiu       $s4, $s4, 0x6B0C
    ctx->r20 = ADD32(ctx->r20, 0X6B0C);
    // 0x801ABB48: addiu       $s3, $s3, 0x78DC
    ctx->r19 = ADD32(ctx->r19, 0X78DC);
    // 0x801ABB4C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x801ABB50: addiu       $s0, $sp, 0x90
    ctx->r16 = ADD32(ctx->r29, 0X90);
    // 0x801ABB54: addiu       $s7, $zero, -0x2
    ctx->r23 = ADD32(0, -0X2);
L_801ABB58:
    // 0x801ABB58: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x801ABB5C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801ABB60: beql        $v0, $s7, L_801ABB88
    if (ctx->r2 == ctx->r23) {
        // 0x801ABB64: lw          $v0, 0x0($s5)
        ctx->r2 = MEM_W(ctx->r21, 0X0);
            goto L_801ABB88;
    }
    goto skip_0;
    // 0x801ABB64: lw          $v0, 0x0($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X0);
    skip_0:
    // 0x801ABB68: beql        $v0, $at, L_801ABB88
    if (ctx->r2 == ctx->r1) {
        // 0x801ABB6C: lw          $v0, 0x0($s5)
        ctx->r2 = MEM_W(ctx->r21, 0X0);
            goto L_801ABB88;
    }
    goto skip_1;
    // 0x801ABB6C: lw          $v0, 0x0($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X0);
    skip_1:
    // 0x801ABB70: beq         $v0, $zero, L_801ABBA8
    if (ctx->r2 == 0) {
        // 0x801ABB74: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_801ABBA8;
    }
    // 0x801ABB74: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x801ABB78: lw          $t3, 0x0($s5)
    ctx->r11 = MEM_W(ctx->r21, 0X0);
    // 0x801ABB7C: b           L_801ABC10
    // 0x801ABB80: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
        goto L_801ABC10;
    // 0x801ABB80: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x801ABB84: lw          $v0, 0x0($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X0);
L_801ABB88:
    // 0x801ABB88: addiu       $t4, $zero, 0x20
    ctx->r12 = ADD32(0, 0X20);
    // 0x801ABB8C: slti        $at, $v0, 0x21
    ctx->r1 = SIGNED(ctx->r2) < 0X21 ? 1 : 0;
    // 0x801ABB90: bne         $at, $zero, L_801ABBA0
    if (ctx->r1 != 0) {
        // 0x801ABB94: nop
    
            goto L_801ABBA0;
    }
    // 0x801ABB94: nop

    // 0x801ABB98: b           L_801ABC10
    // 0x801ABB9C: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
        goto L_801ABC10;
    // 0x801ABB9C: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
L_801ABBA0:
    // 0x801ABBA0: b           L_801ABC10
    // 0x801ABBA4: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
        goto L_801ABC10;
    // 0x801ABBA4: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
L_801ABBA8:
    // 0x801ABBA8: jal         0x800B8DD0
    // 0x801ABBAC: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    RCP_SetupDL(rdram, ctx);
        goto after_4;
    // 0x801ABBAC: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    after_4:
    // 0x801ABBB0: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x801ABBB4: lui         $t6, 0xFFFF
    ctx->r14 = S32(0XFFFF << 16);
    // 0x801ABBB8: ori         $t6, $t6, 0xFF
    ctx->r14 = ctx->r14 | 0XFF;
    // 0x801ABBBC: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x801ABBC0: sw          $t5, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r13;
    // 0x801ABBC4: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x801ABBC8: sw          $fp, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r30;
    // 0x801ABBCC: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x801ABBD0: lw          $t7, 0x7DB0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7DB0);
    // 0x801ABBD4: andi        $t8, $t7, 0x10
    ctx->r24 = ctx->r15 & 0X10;
    // 0x801ABBD8: beql        $t8, $zero, L_801ABC0C
    if (ctx->r24 == 0) {
        // 0x801ABBDC: lw          $t1, 0x0($s5)
        ctx->r9 = MEM_W(ctx->r21, 0X0);
            goto L_801ABC0C;
    }
    goto skip_2;
    // 0x801ABBDC: lw          $t1, 0x0($s5)
    ctx->r9 = MEM_W(ctx->r21, 0X0);
    skip_2:
    // 0x801ABBE0: lwc1        $f18, 0x0($s4)
    ctx->f18.u32l = MEM_W(ctx->r20, 0X0);
    // 0x801ABBE4: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x801ABBE8: addiu       $t0, $t0, 0x7518
    ctx->r8 = ADD32(ctx->r8, 0X7518);
    // 0x801ABBEC: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x801ABBF0: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x801ABBF4: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x801ABBF8: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x801ABBFC: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    // 0x801ABC00: jal         0x800A1200
    // 0x801ABC04: addiu       $a1, $zero, 0x9F
    ctx->r5 = ADD32(0, 0X9F);
    Graphics_DisplaySmallText(rdram, ctx);
        goto after_5;
    // 0x801ABC04: addiu       $a1, $zero, 0x9F
    ctx->r5 = ADD32(0, 0X9F);
    after_5:
    // 0x801ABC08: lw          $t1, 0x0($s5)
    ctx->r9 = MEM_W(ctx->r21, 0X0);
L_801ABC0C:
    // 0x801ABC0C: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
L_801ABC10:
    // 0x801ABC10: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x801ABC14: jal         0x800B8DD0
    // 0x801ABC18: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    RCP_SetupDL(rdram, ctx);
        goto after_6;
    // 0x801ABC18: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    after_6:
    // 0x801ABC1C: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x801ABC20: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x801ABC24: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x801ABC28: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x801ABC2C: sw          $t2, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r10;
    // 0x801ABC30: sw          $fp, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r30;
    // 0x801ABC34: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x801ABC38: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
    // 0x801ABC3C: addiu       $a3, $zero, 0x1C
    ctx->r7 = ADD32(0, 0X1C);
    // 0x801ABC40: andi        $t4, $t3, 0xFF
    ctx->r12 = ctx->r11 & 0XFF;
    // 0x801ABC44: or          $t5, $t4, $at
    ctx->r13 = ctx->r12 | ctx->r1;
    // 0x801ABC48: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x801ABC4C: lwc1        $f6, 0x0($s4)
    ctx->f6.u32l = MEM_W(ctx->r20, 0X0);
    // 0x801ABC50: lw          $a1, 0x0($s6)
    ctx->r5 = MEM_W(ctx->r22, 0X0);
    // 0x801ABC54: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    // 0x801ABC58: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x801ABC5C: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x801ABC60: jal         0x8009D418
    // 0x801ABC64: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Lib_TextureRect_RGBA16(rdram, ctx);
        goto after_7;
    // 0x801ABC64: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_7:
    // 0x801ABC68: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x801ABC6C: bgezl       $v0, L_801ABC88
    if (SIGNED(ctx->r2) >= 0) {
        // 0x801ABC70: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_801ABC88;
    }
    goto skip_3;
    // 0x801ABC70: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_3:
    // 0x801ABC74: beq         $s7, $v0, L_801ABC84
    if (ctx->r23 == ctx->r2) {
        // 0x801ABC78: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_801ABC84;
    }
    // 0x801ABC78: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801ABC7C: jal         0x801ABCDC
    // 0x801ABC80: lw          $a1, 0x0($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X0);
    Map_TeamDownWrench_Draw(rdram, ctx);
        goto after_8;
    // 0x801ABC80: lw          $a1, 0x0($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X0);
    after_8:
L_801ABC84:
    // 0x801ABC84: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_801ABC88:
    // 0x801ABC88: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801ABC8C: addiu       $s3, $s3, -0x4
    ctx->r19 = ADD32(ctx->r19, -0X4);
    // 0x801ABC90: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x801ABC94: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x801ABC98: bne         $s1, $at, L_801ABB58
    if (ctx->r17 != ctx->r1) {
        // 0x801ABC9C: addiu       $s6, $s6, 0x4
        ctx->r22 = ADD32(ctx->r22, 0X4);
            goto L_801ABB58;
    }
    // 0x801ABC9C: addiu       $s6, $s6, 0x4
    ctx->r22 = ADD32(ctx->r22, 0X4);
L_801ABCA0:
    // 0x801ABCA0: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
L_801ABCA4:
    // 0x801ABCA4: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x801ABCA8: ldc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X30);
    // 0x801ABCAC: ldc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X38);
    // 0x801ABCB0: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x801ABCB4: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x801ABCB8: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x801ABCBC: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x801ABCC0: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x801ABCC4: lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X54);
    // 0x801ABCC8: lw          $s6, 0x58($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X58);
    // 0x801ABCCC: lw          $s7, 0x5C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X5C);
    // 0x801ABCD0: lw          $fp, 0x60($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X60);
    // 0x801ABCD4: jr          $ra
    // 0x801ABCD8: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    return;
    // 0x801ABCD8: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
;}
RECOMP_FUNC void Title_CsTakeOff_Setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018B058: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x8018B05C: sw          $ra, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r31;
    // 0x8018B060: sw          $fp, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r30;
    // 0x8018B064: sw          $s7, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r23;
    // 0x8018B068: sw          $s6, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r22;
    // 0x8018B06C: sw          $s5, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r21;
    // 0x8018B070: sw          $s4, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r20;
    // 0x8018B074: sw          $s3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r19;
    // 0x8018B078: sw          $s2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r18;
    // 0x8018B07C: sw          $s1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r17;
    // 0x8018B080: sw          $s0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r16;
    // 0x8018B084: sdc1        $f30, 0x68($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X68, ctx->r29);
    // 0x8018B088: sdc1        $f28, 0x60($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X60, ctx->r29);
    // 0x8018B08C: sdc1        $f26, 0x58($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X58, ctx->r29);
    // 0x8018B090: sdc1        $f24, 0x50($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X50, ctx->r29);
    // 0x8018B094: sdc1        $f22, 0x48($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X48, ctx->r29);
    // 0x8018B098: sdc1        $f20, 0x40($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X40, ctx->r29);
    // 0x8018B09C: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x8018B0A0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018B0A4: sw          $t6, 0x7C98($at)
    MEM_W(0X7C98, ctx->r1) = ctx->r14;
    // 0x8018B0A8: lui         $at, 0xC270
    ctx->r1 = S32(0XC270 << 16);
    // 0x8018B0AC: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x8018B0B0: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8018B0B4: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x8018B0B8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018B0BC: lwc1        $f26, 0x6F3C($at)
    ctx->f26.u32l = MEM_W(ctx->r1, 0X6F3C);
    // 0x8018B0C0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018B0C4: lwc1        $f24, 0x6F40($at)
    ctx->f24.u32l = MEM_W(ctx->r1, 0X6F40);
    // 0x8018B0C8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8018B0CC: lui         $s2, 0x801B
    ctx->r18 = S32(0X801B << 16);
    // 0x8018B0D0: lui         $s3, 0x801B
    ctx->r19 = S32(0X801B << 16);
    // 0x8018B0D4: lui         $s4, 0x801B
    ctx->r20 = S32(0X801B << 16);
    // 0x8018B0D8: lui         $s5, 0x801B
    ctx->r21 = S32(0X801B << 16);
    // 0x8018B0DC: lui         $s6, 0x801B
    ctx->r22 = S32(0X801B << 16);
    // 0x8018B0E0: lui         $s7, 0x801B
    ctx->r23 = S32(0X801B << 16);
    // 0x8018B0E4: lui         $fp, 0x801B
    ctx->r30 = S32(0X801B << 16);
    // 0x8018B0E8: lui         $s1, 0x801B
    ctx->r17 = S32(0X801B << 16);
    // 0x8018B0EC: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8018B0F0: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8018B0F4: addiu       $s1, $s1, 0x7CA0
    ctx->r17 = ADD32(ctx->r17, 0X7CA0);
    // 0x8018B0F8: addiu       $fp, $fp, 0x7CF0
    ctx->r30 = ADD32(ctx->r30, 0X7CF0);
    // 0x8018B0FC: addiu       $s7, $s7, 0x7CC8
    ctx->r23 = ADD32(ctx->r23, 0X7CC8);
    // 0x8018B100: addiu       $s6, $s6, 0x7D18
    ctx->r22 = ADD32(ctx->r22, 0X7D18);
    // 0x8018B104: addiu       $s5, $s5, 0x7C70
    ctx->r21 = ADD32(ctx->r21, 0X7C70);
    // 0x8018B108: addiu       $s4, $s4, 0x7C48
    ctx->r20 = ADD32(ctx->r20, 0X7C48);
    // 0x8018B10C: addiu       $s3, $s3, 0x7C20
    ctx->r19 = ADD32(ctx->r19, 0X7C20);
    // 0x8018B110: addiu       $s2, $s2, 0x7BF8
    ctx->r18 = ADD32(ctx->r18, 0X7BF8);
    // 0x8018B114: addiu       $s0, $zero, 0x80
    ctx->r16 = ADD32(0, 0X80);
L_8018B118:
    // 0x8018B118: jal         0x80004EB0
    // 0x8018B11C: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_0;
    // 0x8018B11C: nop

    after_0:
    // 0x8018B120: mul.s       $f4, $f0, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x8018B124: add.s       $f6, $f4, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f22.fl;
    // 0x8018B128: jal         0x80004EB0
    // 0x8018B12C: swc1        $f6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f6.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x8018B12C: swc1        $f6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f6.u32l;
    after_1:
    // 0x8018B130: mul.s       $f8, $f0, $f30
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f30.fl);
    // 0x8018B134: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x8018B138: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018B13C: swc1        $f20, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->f20.u32l;
    // 0x8018B140: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8018B144: jal         0x80004EB0
    // 0x8018B148: swc1        $f16, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f16.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_2;
    // 0x8018B148: swc1        $f16, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f16.u32l;
    after_2:
    // 0x8018B14C: mul.s       $f18, $f0, $f24
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x8018B150: add.s       $f4, $f18, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f26.fl;
    // 0x8018B154: jal         0x80004EB0
    // 0x8018B158: swc1        $f4, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->f4.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_3;
    // 0x8018B158: swc1        $f4, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->f4.u32l;
    after_3:
    // 0x8018B15C: mul.s       $f6, $f0, $f28
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f28.fl);
    // 0x8018B160: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x8018B164: addiu       $t4, $t4, 0x7CC8
    ctx->r12 = ADD32(ctx->r12, 0X7CC8);
    // 0x8018B168: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8018B16C: sltu        $at, $s1, $t4
    ctx->r1 = ctx->r17 < ctx->r12 ? 1 : 0;
    // 0x8018B170: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x8018B174: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x8018B178: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8018B17C: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x8018B180: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x8018B184: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
    // 0x8018B188: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x8018B18C: addiu       $s6, $s6, 0x4
    ctx->r22 = ADD32(ctx->r22, 0X4);
    // 0x8018B190: addiu       $s7, $s7, 0x4
    ctx->r23 = ADD32(ctx->r23, 0X4);
    // 0x8018B194: addiu       $t9, $t8, 0x5
    ctx->r25 = ADD32(ctx->r24, 0X5);
    // 0x8018B198: addiu       $fp, $fp, 0x4
    ctx->r30 = ADD32(ctx->r30, 0X4);
    // 0x8018B19C: sw          $t9, -0x4($s6)
    MEM_W(-0X4, ctx->r22) = ctx->r25;
    // 0x8018B1A0: sw          $t3, -0x4($s7)
    MEM_W(-0X4, ctx->r23) = ctx->r11;
    // 0x8018B1A4: sw          $s0, -0x4($fp)
    MEM_W(-0X4, ctx->r30) = ctx->r16;
    // 0x8018B1A8: bne         $at, $zero, L_8018B118
    if (ctx->r1 != 0) {
        // 0x8018B1AC: sw          $zero, -0x4($s1)
        MEM_W(-0X4, ctx->r17) = 0;
            goto L_8018B118;
    }
    // 0x8018B1AC: sw          $zero, -0x4($s1)
    MEM_W(-0X4, ctx->r17) = 0;
    // 0x8018B1B0: lui         $fp, 0x801C
    ctx->r30 = S32(0X801C << 16);
    // 0x8018B1B4: addiu       $fp, $fp, -0x7F00
    ctx->r30 = ADD32(ctx->r30, -0X7F00);
    // 0x8018B1B8: addiu       $t5, $zero, 0x14
    ctx->r13 = ADD32(0, 0X14);
    // 0x8018B1BC: sw          $t5, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r13;
    // 0x8018B1C0: blez        $t5, L_8018B2C0
    if (SIGNED(ctx->r13) <= 0) {
        // 0x8018B1C4: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8018B2C0;
    }
    // 0x8018B1C4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8018B1C8: lui         $at, 0x4150
    ctx->r1 = S32(0X4150 << 16);
    // 0x8018B1CC: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x8018B1D0: lui         $at, 0x41B0
    ctx->r1 = S32(0X41B0 << 16);
    // 0x8018B1D4: lui         $s1, 0x801B
    ctx->r17 = S32(0X801B << 16);
    // 0x8018B1D8: lui         $s2, 0x801B
    ctx->r18 = S32(0X801B << 16);
    // 0x8018B1DC: lui         $s3, 0x801B
    ctx->r19 = S32(0X801B << 16);
    // 0x8018B1E0: lui         $s4, 0x801B
    ctx->r20 = S32(0X801B << 16);
    // 0x8018B1E4: lui         $s5, 0x801C
    ctx->r21 = S32(0X801C << 16);
    // 0x8018B1E8: lui         $s6, 0x801B
    ctx->r22 = S32(0X801B << 16);
    // 0x8018B1EC: lui         $s7, 0x801C
    ctx->r23 = S32(0X801C << 16);
    // 0x8018B1F0: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x8018B1F4: addiu       $s7, $s7, -0x7EF8
    ctx->r23 = ADD32(ctx->r23, -0X7EF8);
    // 0x8018B1F8: addiu       $s6, $s6, 0x7F20
    ctx->r22 = ADD32(ctx->r22, 0X7F20);
    // 0x8018B1FC: addiu       $s5, $s5, -0x7FA0
    ctx->r21 = ADD32(ctx->r21, -0X7FA0);
    // 0x8018B200: addiu       $s4, $s4, 0x7FC0
    ctx->r20 = ADD32(ctx->r20, 0X7FC0);
    // 0x8018B204: addiu       $s3, $s3, 0x7E80
    ctx->r19 = ADD32(ctx->r19, 0X7E80);
    // 0x8018B208: addiu       $s2, $s2, 0x7DE0
    ctx->r18 = ADD32(ctx->r18, 0X7DE0);
    // 0x8018B20C: addiu       $s1, $s1, 0x7D40
    ctx->r17 = ADD32(ctx->r17, 0X7D40);
L_8018B210:
    // 0x8018B210: jal         0x80004EB0
    // 0x8018B214: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_4;
    // 0x8018B214: nop

    after_4:
    // 0x8018B218: mul.s       $f10, $f0, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x8018B21C: sub.s       $f16, $f26, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f26.fl - ctx->f10.fl;
    // 0x8018B220: jal         0x80004EB0
    // 0x8018B224: swc1        $f16, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f16.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_5;
    // 0x8018B224: swc1        $f16, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f16.u32l;
    after_5:
    // 0x8018B228: mul.s       $f18, $f0, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x8018B22C: sub.s       $f4, $f28, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f28.fl - ctx->f18.fl;
    // 0x8018B230: jal         0x80004EB0
    // 0x8018B234: swc1        $f4, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f4.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_6;
    // 0x8018B234: swc1        $f4, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f4.u32l;
    after_6:
    // 0x8018B238: lui         $at, 0xC1C8
    ctx->r1 = S32(0XC1C8 << 16);
    // 0x8018B23C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018B240: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x8018B244: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018B248: swc1        $f20, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->f20.u32l;
    // 0x8018B24C: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8018B250: sub.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x8018B254: jal         0x80004EB0
    // 0x8018B258: swc1        $f16, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f16.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_7;
    // 0x8018B258: swc1        $f16, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f16.u32l;
    after_7:
    // 0x8018B25C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018B260: lwc1        $f18, 0x6F44($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6F44);
    // 0x8018B264: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x8018B268: jal         0x80004EB0
    // 0x8018B26C: swc1        $f4, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->f4.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_8;
    // 0x8018B26C: swc1        $f4, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->f4.u32l;
    after_8:
    // 0x8018B270: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018B274: lwc1        $f8, 0x6F48($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6F48);
    // 0x8018B278: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018B27C: lwc1        $f10, 0x6F4C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6F4C);
    // 0x8018B280: mul.s       $f6, $f0, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8018B284: lw          $t7, 0x0($fp)
    ctx->r15 = MEM_W(ctx->r30, 0X0);
    // 0x8018B288: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8018B28C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8018B290: slt         $at, $s0, $t7
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8018B294: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x8018B298: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x8018B29C: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8018B2A0: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x8018B2A4: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
    // 0x8018B2A8: addiu       $s6, $s6, 0x4
    ctx->r22 = ADD32(ctx->r22, 0X4);
    // 0x8018B2AC: addiu       $s7, $s7, 0x4
    ctx->r23 = ADD32(ctx->r23, 0X4);
    // 0x8018B2B0: swc1        $f16, -0x4($s6)
    MEM_W(-0X4, ctx->r22) = ctx->f16.u32l;
    // 0x8018B2B4: bne         $at, $zero, L_8018B210
    if (ctx->r1 != 0) {
        // 0x8018B2B8: sw          $zero, -0x4($s7)
        MEM_W(-0X4, ctx->r23) = 0;
            goto L_8018B210;
    }
    // 0x8018B2B8: sw          $zero, -0x4($s7)
    MEM_W(-0X4, ctx->r23) = 0;
    // 0x8018B2BC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8018B2C0:
    // 0x8018B2C0: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8018B2C4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018B2C8: sw          $t8, -0x7964($at)
    MEM_W(-0X7964, ctx->r1) = ctx->r24;
    // 0x8018B2CC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018B2D0: sw          $zero, -0x7CC0($at)
    MEM_W(-0X7CC0, ctx->r1) = 0;
    // 0x8018B2D4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018B2D8: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8018B2DC: sw          $t9, -0x7CB8($at)
    MEM_W(-0X7CB8, ctx->r1) = ctx->r25;
    // 0x8018B2E0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018B2E4: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x8018B2E8: sw          $t3, -0x7CB0($at)
    MEM_W(-0X7CB0, ctx->r1) = ctx->r11;
    // 0x8018B2EC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018B2F0: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x8018B2F4: sw          $t4, -0x7CAC($at)
    MEM_W(-0X7CAC, ctx->r1) = ctx->r12;
    // 0x8018B2F8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018B2FC: sw          $zero, -0x7BF0($at)
    MEM_W(-0X7BF0, ctx->r1) = 0;
    // 0x8018B300: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018B304: sw          $zero, -0x7CCC($at)
    MEM_W(-0X7CCC, ctx->r1) = 0;
    // 0x8018B308: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8018B30C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018B310: sw          $v1, -0x7CC8($at)
    MEM_W(-0X7CC8, ctx->r1) = ctx->r3;
    // 0x8018B314: lui         $at, 0xC3B4
    ctx->r1 = S32(0XC3B4 << 16);
    // 0x8018B318: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8018B31C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018B320: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    // 0x8018B324: swc1        $f18, -0x7938($at)
    MEM_W(-0X7938, ctx->r1) = ctx->f18.u32l;
    // 0x8018B328: lui         $at, 0x4303
    ctx->r1 = S32(0X4303 << 16);
    // 0x8018B32C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018B330: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018B334: addiu       $t5, $zero, 0x4B
    ctx->r13 = ADD32(0, 0X4B);
    // 0x8018B338: swc1        $f4, -0x7934($at)
    MEM_W(-0X7934, ctx->r1) = ctx->f4.u32l;
    // 0x8018B33C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018B340: sw          $a1, -0x7AB8($at)
    MEM_W(-0X7AB8, ctx->r1) = ctx->r5;
    // 0x8018B344: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018B348: sw          $t5, -0x7AB4($at)
    MEM_W(-0X7AB4, ctx->r1) = ctx->r13;
    // 0x8018B34C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018B350: sw          $a1, -0x7AB0($at)
    MEM_W(-0X7AB0, ctx->r1) = ctx->r5;
    // 0x8018B354: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018B358: addiu       $t6, $zero, 0x2D
    ctx->r14 = ADD32(0, 0X2D);
    // 0x8018B35C: sw          $t6, -0x7AAC($at)
    MEM_W(-0X7AAC, ctx->r1) = ctx->r14;
    // 0x8018B360: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018B364: addiu       $t7, $zero, 0x22
    ctx->r15 = ADD32(0, 0X22);
    // 0x8018B368: sw          $t7, -0x7AA8($at)
    MEM_W(-0X7AA8, ctx->r1) = ctx->r15;
    // 0x8018B36C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018B370: addiu       $t8, $zero, 0x38
    ctx->r24 = ADD32(0, 0X38);
    // 0x8018B374: sw          $t8, -0x7AA4($at)
    MEM_W(-0X7AA4, ctx->r1) = ctx->r24;
    // 0x8018B378: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8018B37C: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x8018B380: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018B384: addiu       $a0, $a0, -0x7978
    ctx->r4 = ADD32(ctx->r4, -0X7978);
    // 0x8018B388: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8018B38C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018B390: swc1        $f20, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f20.u32l;
    // 0x8018B394: swc1        $f20, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f20.u32l;
    // 0x8018B398: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
    // 0x8018B39C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018B3A0: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
    // 0x8018B3A4: swc1        $f6, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f6.u32l;
    // 0x8018B3A8: sw          $v1, 0x7BE4($at)
    MEM_W(0X7BE4, ctx->r1) = ctx->r3;
    // 0x8018B3AC: lui         $at, 0xC2F0
    ctx->r1 = S32(0XC2F0 << 16);
    // 0x8018B3B0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8018B3B4: lui         $at, 0x4296
    ctx->r1 = S32(0X4296 << 16);
    // 0x8018B3B8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8018B3BC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018B3C0: lwc1        $f12, 0x6F50($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X6F50);
    // 0x8018B3C4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8018B3C8: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8018B3CC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8018B3D0: addiu       $v0, $v0, -0x7B18
    ctx->r2 = ADD32(ctx->r2, -0X7B18);
    // 0x8018B3D4: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
L_8018B3D8:
    // 0x8018B3D8: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x8018B3DC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018B3E0: subu        $t9, $a0, $s0
    ctx->r25 = SUB32(ctx->r4, ctx->r16);
    // 0x8018B3E4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8018B3E8: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x8018B3EC: add.s       $f0, $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f14.fl;
    // 0x8018B3F0: addiu       $v0, $v0, 0x5C
    ctx->r2 = ADD32(ctx->r2, 0X5C);
    // 0x8018B3F4: swc1        $f20, -0x58($v0)
    MEM_W(-0X58, ctx->r2) = ctx->f20.u32l;
    // 0x8018B3F8: swc1        $f20, -0x54($v0)
    MEM_W(-0X54, ctx->r2) = ctx->f20.u32l;
    // 0x8018B3FC: swc1        $f2, -0x50($v0)
    MEM_W(-0X50, ctx->r2) = ctx->f2.u32l;
    // 0x8018B400: swc1        $f20, -0x44($v0)
    MEM_W(-0X44, ctx->r2) = ctx->f20.u32l;
    // 0x8018B404: swc1        $f20, -0x40($v0)
    MEM_W(-0X40, ctx->r2) = ctx->f20.u32l;
    // 0x8018B408: swc1        $f20, -0x3C($v0)
    MEM_W(-0X3C, ctx->r2) = ctx->f20.u32l;
    // 0x8018B40C: swc1        $f30, -0x38($v0)
    MEM_W(-0X38, ctx->r2) = ctx->f30.u32l;
    // 0x8018B410: swc1        $f20, -0x30($v0)
    MEM_W(-0X30, ctx->r2) = ctx->f20.u32l;
    // 0x8018B414: swc1        $f20, -0x2C($v0)
    MEM_W(-0X2C, ctx->r2) = ctx->f20.u32l;
    // 0x8018B418: sw          $t9, -0x28($v0)
    MEM_W(-0X28, ctx->r2) = ctx->r25;
    // 0x8018B41C: sw          $zero, -0x20($v0)
    MEM_W(-0X20, ctx->r2) = 0;
    // 0x8018B420: sw          $zero, -0x1C($v0)
    MEM_W(-0X1C, ctx->r2) = 0;
    // 0x8018B424: swc1        $f20, -0x18($v0)
    MEM_W(-0X18, ctx->r2) = ctx->f20.u32l;
    // 0x8018B428: swc1        $f12, -0x4C($v0)
    MEM_W(-0X4C, ctx->r2) = ctx->f12.u32l;
    // 0x8018B42C: sw          $v1, -0x14($v0)
    MEM_W(-0X14, ctx->r2) = ctx->r3;
    // 0x8018B430: sw          $v1, -0x10($v0)
    MEM_W(-0X10, ctx->r2) = ctx->r3;
    // 0x8018B434: bne         $s0, $a0, L_8018B3D8
    if (ctx->r16 != ctx->r4) {
        // 0x8018B438: swc1        $f10, -0x34($v0)
        MEM_W(-0X34, ctx->r2) = ctx->f10.u32l;
            goto L_8018B3D8;
    }
    // 0x8018B438: swc1        $f10, -0x34($v0)
    MEM_W(-0X34, ctx->r2) = ctx->f10.u32l;
    // 0x8018B43C: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8018B440: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8018B444: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    // 0x8018B448: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8018B44C: lui         $at, 0x430C
    ctx->r1 = S32(0X430C << 16);
    // 0x8018B450: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8018B454: lui         $at, 0xC248
    ctx->r1 = S32(0XC248 << 16);
    // 0x8018B458: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8018B45C: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8018B460: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8018B464: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8018B468: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x8018B46C: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x8018B470: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x8018B474: lui         $t2, 0x801C
    ctx->r10 = S32(0X801C << 16);
    // 0x8018B478: addiu       $t2, $t2, -0x7948
    ctx->r10 = ADD32(ctx->r10, -0X7948);
    // 0x8018B47C: addiu       $t1, $t1, -0x794C
    ctx->r9 = ADD32(ctx->r9, -0X794C);
    // 0x8018B480: addiu       $t0, $t0, -0x7954
    ctx->r8 = ADD32(ctx->r8, -0X7954);
    // 0x8018B484: addiu       $a1, $a1, -0x7958
    ctx->r5 = ADD32(ctx->r5, -0X7958);
    // 0x8018B488: addiu       $a0, $a0, -0x793C
    ctx->r4 = ADD32(ctx->r4, -0X793C);
    // 0x8018B48C: addiu       $v1, $v1, -0x7940
    ctx->r3 = ADD32(ctx->r3, -0X7940);
    // 0x8018B490: addiu       $v0, $v0, -0x7944
    ctx->r2 = ADD32(ctx->r2, -0X7944);
    // 0x8018B494: swc1        $f20, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f20.u32l;
    // 0x8018B498: swc1        $f20, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f20.u32l;
    // 0x8018B49C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018B4A0: swc1        $f0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f0.u32l;
    // 0x8018B4A4: swc1        $f0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f0.u32l;
    // 0x8018B4A8: swc1        $f22, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f22.u32l;
    // 0x8018B4AC: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
    // 0x8018B4B0: swc1        $f18, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f18.u32l;
    // 0x8018B4B4: swc1        $f20, -0x7D64($at)
    MEM_W(-0X7D64, ctx->r1) = ctx->f20.u32l;
    // 0x8018B4B8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8018B4BC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018B4C0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018B4C4: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x8018B4C8: swc1        $f4, -0x7D60($at)
    MEM_W(-0X7D60, ctx->r1) = ctx->f4.u32l;
    // 0x8018B4CC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018B4D0: swc1        $f20, -0x7D5C($at)
    MEM_W(-0X7D5C, ctx->r1) = ctx->f20.u32l;
    // 0x8018B4D4: lwc1        $f16, 0x0($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X0);
    // 0x8018B4D8: lwc1        $f10, 0x0($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8018B4DC: lwc1        $f6, 0x0($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X0);
    // 0x8018B4E0: lwc1        $f8, 0x0($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X0);
    // 0x8018B4E4: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x8018B4E8: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x8018B4EC: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x8018B4F0: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x8018B4F4: addiu       $t7, $t7, 0x79C0
    ctx->r15 = ADD32(ctx->r15, 0X79C0);
    // 0x8018B4F8: addiu       $t6, $t6, 0x79B8
    ctx->r14 = ADD32(ctx->r14, 0X79B8);
    // 0x8018B4FC: addiu       $t5, $t5, 0x79A0
    ctx->r13 = ADD32(ctx->r13, 0X79A0);
    // 0x8018B500: addiu       $t4, $t4, 0x7988
    ctx->r12 = ADD32(ctx->r12, 0X7988);
    // 0x8018B504: addiu       $t3, $t3, 0x7980
    ctx->r11 = ADD32(ctx->r11, 0X7980);
    // 0x8018B508: lui         $a3, 0x8017
    ctx->r7 = S32(0X8017 << 16);
    // 0x8018B50C: addiu       $a3, $a3, 0x7978
    ctx->r7 = ADD32(ctx->r7, 0X7978);
    // 0x8018B510: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8018B514: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x8018B518: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x8018B51C: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x8018B520: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x8018B524: lw          $a2, 0x0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X0);
    // 0x8018B528: lwc1        $f14, 0x0($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8018B52C: lwc1        $f12, 0x0($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8018B530: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    // 0x8018B534: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    // 0x8018B538: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    // 0x8018B53C: jal         0x801914AC
    // 0x8018B540: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    Title_SetCamUp2(rdram, ctx);
        goto after_9;
    // 0x8018B540: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    after_9:
    // 0x8018B544: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x8018B548: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8018B54C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018B550: ldc1        $f20, 0x40($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X40);
    // 0x8018B554: swc1        $f18, -0x6FBC($at)
    MEM_W(-0X6FBC, ctx->r1) = ctx->f18.u32l;
    // 0x8018B558: lui         $at, 0x42A8
    ctx->r1 = S32(0X42A8 << 16);
    // 0x8018B55C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018B560: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018B564: ldc1        $f24, 0x50($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X50);
    // 0x8018B568: swc1        $f4, -0x6FB8($at)
    MEM_W(-0X6FB8, ctx->r1) = ctx->f4.u32l;
    // 0x8018B56C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018B570: swc1        $f22, -0x6FB4($at)
    MEM_W(-0X6FB4, ctx->r1) = ctx->f22.u32l;
    // 0x8018B574: lui         $at, 0xC204
    ctx->r1 = S32(0XC204 << 16);
    // 0x8018B578: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018B57C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018B580: ldc1        $f22, 0x48($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X48);
    // 0x8018B584: swc1        $f8, -0x6FB0($at)
    MEM_W(-0X6FB0, ctx->r1) = ctx->f8.u32l;
    // 0x8018B588: lw          $ra, 0x94($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X94);
    // 0x8018B58C: ldc1        $f26, 0x58($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X58);
    // 0x8018B590: ldc1        $f28, 0x60($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X60);
    // 0x8018B594: ldc1        $f30, 0x68($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X68);
    // 0x8018B598: lw          $s0, 0x70($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X70);
    // 0x8018B59C: lw          $s1, 0x74($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X74);
    // 0x8018B5A0: lw          $s2, 0x78($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X78);
    // 0x8018B5A4: lw          $s3, 0x7C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X7C);
    // 0x8018B5A8: lw          $s4, 0x80($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X80);
    // 0x8018B5AC: lw          $s5, 0x84($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X84);
    // 0x8018B5B0: lw          $s6, 0x88($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X88);
    // 0x8018B5B4: lw          $s7, 0x8C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X8C);
    // 0x8018B5B8: lw          $fp, 0x90($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X90);
    // 0x8018B5BC: jr          $ra
    // 0x8018B5C0: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x8018B5C0: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void Map_MeteoMeteors_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A9224: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x801A9228: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x801A922C: lui         $s1, 0x801B
    ctx->r17 = S32(0X801B << 16);
    // 0x801A9230: addiu       $s1, $s1, -0xB60
    ctx->r17 = ADD32(ctx->r17, -0XB60);
    // 0x801A9234: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x801A9238: sw          $s5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r21;
    // 0x801A923C: sw          $s4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r20;
    // 0x801A9240: sw          $s3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r19;
    // 0x801A9244: sw          $s2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r18;
    // 0x801A9248: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x801A924C: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x801A9250: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x801A9254: lw          $t6, 0x24($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X24);
    // 0x801A9258: lui         $t7, 0x801D
    ctx->r15 = S32(0X801D << 16);
    // 0x801A925C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801A9260: bne         $t6, $zero, L_801A9274
    if (ctx->r14 != 0) {
        // 0x801A9264: nop
    
            goto L_801A9274;
    }
    // 0x801A9264: nop

    // 0x801A9268: lw          $t7, -0x26AC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X26AC);
    // 0x801A926C: bnel        $t7, $zero, L_801A9420
    if (ctx->r15 != 0) {
        // 0x801A9270: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_801A9420;
    }
    goto skip_0;
    // 0x801A9270: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_0:
L_801A9274:
    // 0x801A9274: lw          $v1, -0x26AC($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X26AC);
    // 0x801A9278: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801A927C: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
    // 0x801A9280: bne         $v1, $zero, L_801A92B0
    if (ctx->r3 != 0) {
        // 0x801A9284: lui         $s2, 0x8013
        ctx->r18 = S32(0X8013 << 16);
            goto L_801A92B0;
    }
    // 0x801A9284: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x801A9288: lw          $v0, -0x26BC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X26BC);
    // 0x801A928C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801A9290: lui         $t8, 0x801D
    ctx->r24 = S32(0X801D << 16);
    // 0x801A9294: bne         $v0, $at, L_801A92B0
    if (ctx->r2 != ctx->r1) {
        // 0x801A9298: nop
    
            goto L_801A92B0;
    }
    // 0x801A9298: nop

    // 0x801A929C: lw          $t8, -0x26A4($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X26A4);
    // 0x801A92A0: beq         $t8, $zero, L_801A92B0
    if (ctx->r24 == 0) {
        // 0x801A92A4: nop
    
            goto L_801A92B0;
    }
    // 0x801A92A4: nop

    // 0x801A92A8: b           L_801A92B8
    // 0x801A92AC: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
        goto L_801A92B8;
    // 0x801A92AC: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_801A92B0:
    // 0x801A92B0: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801A92B4: lw          $v0, -0x26BC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X26BC);
L_801A92B8:
    // 0x801A92B8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801A92BC: beq         $v0, $at, L_801A92D0
    if (ctx->r2 == ctx->r1) {
        // 0x801A92C0: addiu       $s2, $s2, 0x7E64
        ctx->r18 = ADD32(ctx->r18, 0X7E64);
            goto L_801A92D0;
    }
    // 0x801A92C0: addiu       $s2, $s2, 0x7E64
    ctx->r18 = ADD32(ctx->r18, 0X7E64);
    // 0x801A92C4: bne         $v1, $zero, L_801A92E4
    if (ctx->r3 != 0) {
        // 0x801A92C8: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_801A92E4;
    }
    // 0x801A92C8: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x801A92CC: beq         $v0, $at, L_801A92E4
    if (ctx->r2 == ctx->r1) {
        // 0x801A92D0: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_801A92E4;
    }
L_801A92D0:
    // 0x801A92D0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x801A92D4: jal         0x800B8DD0
    // 0x801A92D8: addiu       $a1, $zero, 0x35
    ctx->r5 = ADD32(0, 0X35);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x801A92D8: addiu       $a1, $zero, 0x35
    ctx->r5 = ADD32(0, 0X35);
    after_0:
    // 0x801A92DC: b           L_801A9320
    // 0x801A92E0: nop

        goto L_801A9320;
    // 0x801A92E0: nop

L_801A92E4:
    // 0x801A92E4: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x801A92E8: addiu       $s2, $s2, 0x7E64
    ctx->r18 = ADD32(ctx->r18, 0X7E64);
    // 0x801A92EC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x801A92F0: jal         0x800B8DD0
    // 0x801A92F4: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    RCP_SetupDL(rdram, ctx);
        goto after_1;
    // 0x801A92F4: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_1:
    // 0x801A92F8: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x801A92FC: lui         $t0, 0xFA00
    ctx->r8 = S32(0XFA00 << 16);
    // 0x801A9300: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x801A9304: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x801A9308: sw          $t9, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r25;
    // 0x801A930C: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x801A9310: lw          $t1, 0x24($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X24);
    // 0x801A9314: andi        $t2, $t1, 0xFF
    ctx->r10 = ctx->r9 & 0XFF;
    // 0x801A9318: or          $t3, $t2, $at
    ctx->r11 = ctx->r10 | ctx->r1;
    // 0x801A931C: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
L_801A9320:
    // 0x801A9320: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x801A9324: lw          $t4, 0x7DB0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7DB0);
    // 0x801A9328: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A932C: lui         $s5, 0x801B
    ctx->r21 = S32(0X801B << 16);
    // 0x801A9330: and         $t5, $t4, $s0
    ctx->r13 = ctx->r12 & ctx->r16;
    // 0x801A9334: beq         $t5, $zero, L_801A941C
    if (ctx->r13 == 0) {
        // 0x801A9338: lui         $s0, 0x801B
        ctx->r16 = S32(0X801B << 16);
            goto L_801A941C;
    }
    // 0x801A9338: lui         $s0, 0x801B
    ctx->r16 = S32(0X801B << 16);
    // 0x801A933C: lui         $s4, 0x801B
    ctx->r20 = S32(0X801B << 16);
    // 0x801A9340: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x801A9344: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x801A9348: addiu       $s1, $s1, -0x4C40
    ctx->r17 = ADD32(ctx->r17, -0X4C40);
    // 0x801A934C: addiu       $s4, $s4, 0x68F8
    ctx->r20 = ADD32(ctx->r20, 0X68F8);
    // 0x801A9350: addiu       $s0, $s0, -0x5C8
    ctx->r16 = ADD32(ctx->r16, -0X5C8);
    // 0x801A9354: lwc1        $f20, 0x79D4($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X79D4);
    // 0x801A9358: addiu       $s5, $s5, -0x328
    ctx->r21 = ADD32(ctx->r21, -0X328);
    // 0x801A935C: lui         $s3, 0x600
    ctx->r19 = S32(0X600 << 16);
L_801A9360:
    // 0x801A9360: jal         0x80005708
    // 0x801A9364: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Push(rdram, ctx);
        goto after_2;
    // 0x801A9364: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x801A9368: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x801A936C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801A9370: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801A9374: mul.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x801A9378: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x801A937C: jal         0x80005E90
    // 0x801A9380: nop

    Matrix_RotateY(rdram, ctx);
        goto after_3;
    // 0x801A9380: nop

    after_3:
    // 0x801A9384: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x801A9388: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801A938C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801A9390: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801A9394: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x801A9398: jal         0x80005B00
    // 0x801A939C: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    Matrix_Translate(rdram, ctx);
        goto after_4;
    // 0x801A939C: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    after_4:
    // 0x801A93A0: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x801A93A4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801A93A8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801A93AC: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x801A93B0: mul.s       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x801A93B4: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x801A93B8: jal         0x80005E90
    // 0x801A93BC: nop

    Matrix_RotateY(rdram, ctx);
        goto after_5;
    // 0x801A93BC: nop

    after_5:
    // 0x801A93C0: jal         0x801AD048
    // 0x801A93C4: nop

    Map_CamMatrixRot(rdram, ctx);
        goto after_6;
    // 0x801A93C4: nop

    after_6:
    // 0x801A93C8: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x801A93CC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801A93D0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801A93D4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801A93D8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801A93DC: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x801A93E0: jal         0x80005C34
    // 0x801A93E4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_7;
    // 0x801A93E4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_7:
    // 0x801A93E8: jal         0x80006EB8
    // 0x801A93EC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_8;
    // 0x801A93EC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_8:
    // 0x801A93F0: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x801A93F4: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x801A93F8: sw          $t8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r24;
    // 0x801A93FC: sw          $s3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r19;
    // 0x801A9400: lw          $t9, 0x0($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X0);
    // 0x801A9404: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x801A9408: jal         0x80005740
    // 0x801A940C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_9;
    // 0x801A940C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_9:
    // 0x801A9410: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x801A9414: bne         $s0, $s5, L_801A9360
    if (ctx->r16 != ctx->r21) {
        // 0x801A9418: nop
    
            goto L_801A9360;
    }
    // 0x801A9418: nop

L_801A941C:
    // 0x801A941C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_801A9420:
    // 0x801A9420: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x801A9424: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x801A9428: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x801A942C: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x801A9430: lw          $s2, 0x34($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X34);
    // 0x801A9434: lw          $s3, 0x38($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X38);
    // 0x801A9438: lw          $s4, 0x3C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X3C);
    // 0x801A943C: lw          $s5, 0x40($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X40);
    // 0x801A9440: jr          $ra
    // 0x801A9444: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x801A9444: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void Map_Arwing_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801AC530: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x801AC534: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x801AC538: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x801AC53C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801AC540: addiu       $s0, $s0, -0x1158
    ctx->r16 = ADD32(ctx->r16, -0X1158);
    // 0x801AC544: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x801AC548: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x801AC54C: sw          $a0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r4;
    // 0x801AC550: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x801AC554: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x801AC558: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    // 0x801AC55C: swc1        $f0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f0.u32l;
    // 0x801AC560: bne         $t6, $at, L_801AC584
    if (ctx->r14 != ctx->r1) {
        // 0x801AC564: swc1        $f0, 0x64($sp)
        MEM_W(0X64, ctx->r29) = ctx->f0.u32l;
            goto L_801AC584;
    }
    // 0x801AC564: swc1        $f0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f0.u32l;
    // 0x801AC568: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x801AC56C: addiu       $s1, $s1, 0x7E64
    ctx->r17 = ADD32(ctx->r17, 0X7E64);
    // 0x801AC570: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801AC574: jal         0x800B8DD0
    // 0x801AC578: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x801AC578: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    after_0:
    // 0x801AC57C: b           L_801AC5C0
    // 0x801AC580: nop

        goto L_801AC5C0;
    // 0x801AC580: nop

L_801AC584:
    // 0x801AC584: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x801AC588: addiu       $s1, $s1, 0x7E64
    ctx->r17 = ADD32(ctx->r17, 0X7E64);
    // 0x801AC58C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801AC590: jal         0x800B8DD0
    // 0x801AC594: addiu       $a1, $zero, 0x2E
    ctx->r5 = ADD32(0, 0X2E);
    RCP_SetupDL(rdram, ctx);
        goto after_1;
    // 0x801AC594: addiu       $a1, $zero, 0x2E
    ctx->r5 = ADD32(0, 0X2E);
    after_1:
    // 0x801AC598: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x801AC59C: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x801AC5A0: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x801AC5A4: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x801AC5A8: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x801AC5AC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x801AC5B0: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x801AC5B4: andi        $t0, $t9, 0xFF
    ctx->r8 = ctx->r25 & 0XFF;
    // 0x801AC5B8: or          $t1, $t0, $at
    ctx->r9 = ctx->r8 | ctx->r1;
    // 0x801AC5BC: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
L_801AC5C0:
    // 0x801AC5C0: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x801AC5C4: addiu       $s0, $s0, -0x4C40
    ctx->r16 = ADD32(ctx->r16, -0X4C40);
    // 0x801AC5C8: jal         0x80005708
    // 0x801AC5CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_Push(rdram, ctx);
        goto after_2;
    // 0x801AC5CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x801AC5D0: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801AC5D4: addiu       $v0, $v0, -0x1150
    ctx->r2 = ADD32(ctx->r2, -0X1150);
    // 0x801AC5D8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801AC5DC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x801AC5E0: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x801AC5E4: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    // 0x801AC5E8: lw          $a3, 0x8($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X8);
    // 0x801AC5EC: jal         0x80005B00
    // 0x801AC5F0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_3;
    // 0x801AC5F0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_3:
    // 0x801AC5F4: lw          $t3, 0x80($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X80);
    // 0x801AC5F8: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x801AC5FC: addiu       $t5, $t5, 0x4750
    ctx->r13 = ADD32(ctx->r13, 0X4750);
    // 0x801AC600: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x801AC604: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x801AC608: sll         $t4, $t4, 4
    ctx->r12 = S32(ctx->r12 << 4);
    // 0x801AC60C: addu        $v0, $t4, $t5
    ctx->r2 = ADD32(ctx->r12, ctx->r13);
    // 0x801AC610: lw          $a1, 0x20($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X20);
    // 0x801AC614: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x801AC618: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x801AC61C: jal         0x80005E90
    // 0x801AC620: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateY(rdram, ctx);
        goto after_4;
    // 0x801AC620: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
    // 0x801AC624: lui         $a1, 0xBFC9
    ctx->r5 = S32(0XBFC9 << 16);
    // 0x801AC628: ori         $a1, $a1, 0xFDB
    ctx->r5 = ctx->r5 | 0XFDB;
    // 0x801AC62C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x801AC630: jal         0x80005D44
    // 0x801AC634: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateX(rdram, ctx);
        goto after_5;
    // 0x801AC634: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x801AC638: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x801AC63C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x801AC640: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801AC644: jal         0x80005D44
    // 0x801AC648: lw          $a1, 0x1C($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X1C);
    Matrix_RotateX(rdram, ctx);
        goto after_6;
    // 0x801AC648: lw          $a1, 0x1C($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X1C);
    after_6:
    // 0x801AC64C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801AC650: lwc1        $f0, 0x7B20($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X7B20);
    // 0x801AC654: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801AC658: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801AC65C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801AC660: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801AC664: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x801AC668: jal         0x80005C34
    // 0x801AC66C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_7;
    // 0x801AC66C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_7:
    // 0x801AC670: jal         0x80006EB8
    // 0x801AC674: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_8;
    // 0x801AC674: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_8:
    // 0x801AC678: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x801AC67C: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    // 0x801AC680: jal         0x80006970
    // 0x801AC684: addiu       $a2, $sp, 0x68
    ctx->r6 = ADD32(ctx->r29, 0X68);
    Matrix_MultVec3f(rdram, ctx);
        goto after_9;
    // 0x801AC684: addiu       $a2, $sp, 0x68
    ctx->r6 = ADD32(ctx->r29, 0X68);
    after_9:
    // 0x801AC688: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801AC68C: addiu       $v0, $v0, -0x16A0
    ctx->r2 = ADD32(ctx->r2, -0X16A0);
    // 0x801AC690: lwc1        $f4, 0xA8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XA8);
    // 0x801AC694: lwc1        $f6, 0x68($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X68);
    // 0x801AC698: lwc1        $f18, 0xB0($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0XB0);
    // 0x801AC69C: lwc1        $f8, 0xAC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XAC);
    // 0x801AC6A0: sub.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801AC6A4: lwc1        $f4, 0x70($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X70);
    // 0x801AC6A8: lwc1        $f10, 0x6C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x801AC6AC: sub.s       $f16, $f18, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x801AC6B0: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x801AC6B4: swc1        $f2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f2.u32l;
    // 0x801AC6B8: sub.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x801AC6BC: mul.s       $f8, $f16, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x801AC6C0: swc1        $f16, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f16.u32l;
    // 0x801AC6C4: add.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801AC6C8: jal         0x80005100
    // 0x801AC6CC: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    Math_Atan2F(rdram, ctx);
        goto after_10;
    // 0x801AC6CC: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    after_10:
    // 0x801AC6D0: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    // 0x801AC6D4: lwc1        $f12, 0x50($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X50);
    // 0x801AC6D8: jal         0x80005100
    // 0x801AC6DC: lwc1        $f14, 0x48($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X48);
    Math_Atan2F(rdram, ctx);
        goto after_11;
    // 0x801AC6DC: lwc1        $f14, 0x48($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X48);
    after_11:
    // 0x801AC6E0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801AC6E4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801AC6E8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801AC6EC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801AC6F0: lwc1        $f6, -0x25F0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X25F0);
    // 0x801AC6F4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801AC6F8: swc1        $f10, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f10.u32l;
    // 0x801AC6FC: neg.s       $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = -ctx->f0.fl;
    // 0x801AC700: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x801AC704: swc1        $f18, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f18.u32l;
    // 0x801AC708: sub.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x801AC70C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801AC710: swc1        $f4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f4.u32l;
    // 0x801AC714: lwc1        $f4, 0x7B24($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7B24);
    // 0x801AC718: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801AC71C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801AC720: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x801AC724: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801AC728: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x801AC72C: jal         0x80005E90
    // 0x801AC730: nop

    Matrix_RotateY(rdram, ctx);
        goto after_12;
    // 0x801AC730: nop

    after_12:
    // 0x801AC734: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801AC738: lwc1        $f8, -0x25F4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X25F4);
    // 0x801AC73C: lwc1        $f18, 0x58($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X58);
    // 0x801AC740: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801AC744: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x801AC748: lwc1        $f6, 0x7B28($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7B28);
    // 0x801AC74C: sub.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x801AC750: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801AC754: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801AC758: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801AC75C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x801AC760: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x801AC764: jal         0x80005D44
    // 0x801AC768: nop

    Matrix_RotateX(rdram, ctx);
        goto after_13;
    // 0x801AC768: nop

    after_13:
    // 0x801AC76C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801AC770: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801AC774: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    // 0x801AC778: jal         0x80006970
    // 0x801AC77C: addiu       $a2, $sp, 0x68
    ctx->r6 = ADD32(ctx->r29, 0X68);
    Matrix_MultVec3f(rdram, ctx);
        goto after_14;
    // 0x801AC77C: addiu       $a2, $sp, 0x68
    ctx->r6 = ADD32(ctx->r29, 0X68);
    after_14:
    // 0x801AC780: lwc1        $f10, 0x68($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X68);
    // 0x801AC784: lwc1        $f4, 0x6C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x801AC788: lwc1        $f8, 0x70($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X70);
    // 0x801AC78C: trunc.w.s   $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x801AC790: addiu       $t1, $zero, 0x32
    ctx->r9 = ADD32(0, 0X32);
    // 0x801AC794: addiu       $t2, $zero, 0x32
    ctx->r10 = ADD32(0, 0X32);
    // 0x801AC798: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x801AC79C: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x801AC7A0: addiu       $t3, $zero, 0x28
    ctx->r11 = ADD32(0, 0X28);
    // 0x801AC7A4: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x801AC7A8: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x801AC7AC: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x801AC7B0: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x801AC7B4: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x801AC7B8: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x801AC7BC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801AC7C0: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x801AC7C4: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x801AC7C8: jal         0x8000372C
    // 0x801AC7CC: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    Lights_SetOneLight(rdram, ctx);
        goto after_15;
    // 0x801AC7CC: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_15:
    // 0x801AC7D0: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x801AC7D4: lui         $t6, 0x605
    ctx->r14 = S32(0X605 << 16);
    // 0x801AC7D8: addiu       $t6, $t6, -0x5610
    ctx->r14 = ADD32(ctx->r14, -0X5610);
    // 0x801AC7DC: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x801AC7E0: sw          $t4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r12;
    // 0x801AC7E4: lui         $t5, 0x600
    ctx->r13 = S32(0X600 << 16);
    // 0x801AC7E8: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x801AC7EC: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x801AC7F0: jal         0x80005740
    // 0x801AC7F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_16;
    // 0x801AC7F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x801AC7F8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x801AC7FC: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x801AC800: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x801AC804: jr          $ra
    // 0x801AC808: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x801AC808: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void Title_CsTakeOff_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018C114: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8018C118: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8018C11C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8018C120: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8018C124: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8018C128: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x8018C12C: lw          $t6, -0x796C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X796C);
    // 0x8018C130: beq         $t6, $zero, L_8018C144
    if (ctx->r14 == 0) {
        // 0x8018C134: nop
    
            goto L_8018C144;
    }
    // 0x8018C134: nop

    // 0x8018C138: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8018C13C: jal         0x8018DF0C
    // 0x8018C140: nop

    Title_Corneria_Draw(rdram, ctx);
        goto after_0;
    // 0x8018C140: nop

    after_0:
L_8018C144:
    // 0x8018C144: jal         0x80190950
    // 0x8018C148: nop

    Title_GreatFoxDeck_Draw(rdram, ctx);
        goto after_1;
    // 0x8018C148: nop

    after_1:
    // 0x8018C14C: lui         $s1, 0x801C
    ctx->r17 = S32(0X801C << 16);
    // 0x8018C150: addiu       $s1, $s1, -0x7A04
    ctx->r17 = ADD32(ctx->r17, -0X7A04);
    // 0x8018C154: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
L_8018C158:
    // 0x8018C158: lw          $t7, 0x4C($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X4C);
    // 0x8018C15C: beql        $t7, $zero, L_8018C170
    if (ctx->r15 == 0) {
        // 0x8018C160: addiu       $s0, $s0, -0x1
        ctx->r16 = ADD32(ctx->r16, -0X1);
            goto L_8018C170;
    }
    goto skip_0;
    // 0x8018C160: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    skip_0:
    // 0x8018C164: jal         0x80190B30
    // 0x8018C168: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Title_GreatFoxDeckLauncher_Draw(rdram, ctx);
        goto after_2;
    // 0x8018C168: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8018C16C: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
L_8018C170:
    // 0x8018C170: bgez        $s0, L_8018C158
    if (SIGNED(ctx->r16) >= 0) {
        // 0x8018C174: addiu       $s1, $s1, -0x5C
        ctx->r17 = ADD32(ctx->r17, -0X5C);
            goto L_8018C158;
    }
    // 0x8018C174: addiu       $s1, $s1, -0x5C
    ctx->r17 = ADD32(ctx->r17, -0X5C);
    // 0x8018C178: lui         $s1, 0x801C
    ctx->r17 = S32(0X801C << 16);
    // 0x8018C17C: addiu       $s1, $s1, -0x7B18
    ctx->r17 = ADD32(ctx->r17, -0X7B18);
    // 0x8018C180: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8018C184: addiu       $s2, $zero, 0x4
    ctx->r18 = ADD32(0, 0X4);
L_8018C188:
    // 0x8018C188: lw          $t8, 0x4C($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X4C);
    // 0x8018C18C: beql        $t8, $zero, L_8018C1A0
    if (ctx->r24 == 0) {
        // 0x8018C190: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8018C1A0;
    }
    goto skip_1;
    // 0x8018C190: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_1:
    // 0x8018C194: jal         0x8018D2B8
    // 0x8018C198: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Title_Arwing_Draw(rdram, ctx);
        goto after_3;
    // 0x8018C198: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8018C19C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8018C1A0:
    // 0x8018C1A0: bne         $s0, $s2, L_8018C188
    if (ctx->r16 != ctx->r18) {
        // 0x8018C1A4: addiu       $s1, $s1, 0x5C
        ctx->r17 = ADD32(ctx->r17, 0X5C);
            goto L_8018C188;
    }
    // 0x8018C1A4: addiu       $s1, $s1, 0x5C
    ctx->r17 = ADD32(ctx->r17, 0X5C);
    // 0x8018C1A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8018C1AC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8018C1B0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8018C1B4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8018C1B8: jr          $ra
    // 0x8018C1BC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8018C1BC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void Option_Sound_SetVolumeLevels(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80194BD0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80194BD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80194BD8: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80194BDC: lw          $v0, -0x6D78($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6D78);
    // 0x80194BE0: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x80194BE4: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x80194BE8: sll         $t7, $v0, 3
    ctx->r15 = S32(ctx->r2 << 3);
    // 0x80194BEC: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x80194BF0: subu        $t7, $t7, $v0
    ctx->r15 = SUB32(ctx->r15, ctx->r2);
    // 0x80194BF4: lbu         $t6, -0x1665($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X1665);
    // 0x80194BF8: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80194BFC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80194C00: addiu       $t8, $t7, -0x20
    ctx->r24 = ADD32(ctx->r15, -0X20);
    // 0x80194C04: addiu       $t9, $t9, -0x14B8
    ctx->r25 = ADD32(ctx->r25, -0X14B8);
    // 0x80194C08: lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // 0x80194C0C: addiu       $a3, $a3, -0x6D98
    ctx->r7 = ADD32(ctx->r7, -0X6D98);
    // 0x80194C10: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    // 0x80194C14: lui         $a1, 0x4312
    ctx->r5 = S32(0X4312 << 16);
    // 0x80194C18: lui         $a2, 0x4375
    ctx->r6 = S32(0X4375 << 16);
    // 0x80194C1C: jal         0x8019C66C
    // 0x80194C20: sb          $t6, -0x6DB4($at)
    MEM_B(-0X6DB4, ctx->r1) = ctx->r14;
    Option_Input_Sound_X(rdram, ctx);
        goto after_0;
    // 0x80194C20: sb          $t6, -0x6DB4($at)
    MEM_B(-0X6DB4, ctx->r1) = ctx->r14;
    after_0:
    // 0x80194C24: beq         $v0, $zero, L_80194CD4
    if (ctx->r2 == 0) {
        // 0x80194C28: lui         $v0, 0x801C
        ctx->r2 = S32(0X801C << 16);
            goto L_80194CD4;
    }
    // 0x80194C28: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80194C2C: lw          $v0, -0x6D78($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6D78);
    // 0x80194C30: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80194C34: sll         $t0, $v0, 3
    ctx->r8 = S32(ctx->r2 << 3);
    // 0x80194C38: subu        $t0, $t0, $v0
    ctx->r8 = SUB32(ctx->r8, ctx->r2);
    // 0x80194C3C: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x80194C40: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80194C44: lwc1        $f4, -0x14D8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X14D8);
    // 0x80194C48: lui         $at, 0x4312
    ctx->r1 = S32(0X4312 << 16);
    // 0x80194C4C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80194C50: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80194C54: sll         $t2, $v0, 2
    ctx->r10 = S32(ctx->r2 << 2);
    // 0x80194C58: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80194C5C: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x80194C60: addiu       $a0, $v0, -0x1
    ctx->r4 = ADD32(ctx->r2, -0X1);
    // 0x80194C64: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80194C68: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x80194C6C: nop

    // 0x80194C70: sw          $v1, 0x7C7C($at)
    MEM_W(0X7C7C, ctx->r1) = ctx->r3;
    // 0x80194C74: slti        $at, $v1, 0x64
    ctx->r1 = SIGNED(ctx->r3) < 0X64 ? 1 : 0;
    // 0x80194C78: bne         $at, $zero, L_80194C84
    if (ctx->r1 != 0) {
        // 0x80194C7C: nop
    
            goto L_80194C84;
    }
    // 0x80194C7C: nop

    // 0x80194C80: addiu       $v1, $zero, 0x63
    ctx->r3 = ADD32(0, 0X63);
L_80194C84:
    // 0x80194C84: beq         $a0, $zero, L_80194CA8
    if (ctx->r4 == 0) {
        // 0x80194C88: andi        $a1, $v1, 0xFF
        ctx->r5 = ctx->r3 & 0XFF;
            goto L_80194CA8;
    }
    // 0x80194C88: andi        $a1, $v1, 0xFF
    ctx->r5 = ctx->r3 & 0XFF;
    // 0x80194C8C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80194C90: beq         $a0, $at, L_80194CB4
    if (ctx->r4 == ctx->r1) {
        // 0x80194C94: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80194CB4;
    }
    // 0x80194C94: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80194C98: beq         $a0, $at, L_80194CC0
    if (ctx->r4 == ctx->r1) {
        // 0x80194C9C: nop
    
            goto L_80194CC0;
    }
    // 0x80194C9C: nop

    // 0x80194CA0: b           L_80194CC8
    // 0x80194CA4: nop

        goto L_80194CC8;
    // 0x80194CA4: nop

L_80194CA8:
    // 0x80194CA8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80194CAC: b           L_80194CC8
    // 0x80194CB0: sb          $v1, -0x777B($at)
    MEM_B(-0X777B, ctx->r1) = ctx->r3;
        goto L_80194CC8;
    // 0x80194CB0: sb          $v1, -0x777B($at)
    MEM_B(-0X777B, ctx->r1) = ctx->r3;
L_80194CB4:
    // 0x80194CB4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80194CB8: b           L_80194CC8
    // 0x80194CBC: sb          $v1, -0x777A($at)
    MEM_B(-0X777A, ctx->r1) = ctx->r3;
        goto L_80194CC8;
    // 0x80194CBC: sb          $v1, -0x777A($at)
    MEM_B(-0X777A, ctx->r1) = ctx->r3;
L_80194CC0:
    // 0x80194CC0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80194CC4: sb          $v1, -0x7779($at)
    MEM_B(-0X7779, ctx->r1) = ctx->r3;
L_80194CC8:
    // 0x80194CC8: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80194CCC: jal         0x8001D8A8
    // 0x80194CD0: lbu         $a0, -0x6DB4($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X6DB4);
    Audio_SetVolume(rdram, ctx);
        goto after_1;
    // 0x80194CD0: lbu         $a0, -0x6DB4($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X6DB4);
    after_1:
L_80194CD4:
    // 0x80194CD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80194CD8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80194CDC: jr          $ra
    // 0x80194CE0: nop

    return;
    // 0x80194CE0: nop

;}
RECOMP_FUNC void Map_Planet_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A6A98: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801A6A9C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801A6AA0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801A6AA4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801A6AA8: sll         $t6, $s0, 3
    ctx->r14 = S32(ctx->r16 << 3);
    // 0x801A6AAC: subu        $t6, $t6, $s0
    ctx->r14 = SUB32(ctx->r14, ctx->r16);
    // 0x801A6AB0: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x801A6AB4: addiu       $t7, $t7, -0xB60
    ctx->r15 = ADD32(ctx->r15, -0XB60);
    // 0x801A6AB8: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x801A6ABC: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x801A6AC0: lw          $t8, 0x24($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X24);
    // 0x801A6AC4: lui         $t9, 0x801D
    ctx->r25 = S32(0X801D << 16);
    // 0x801A6AC8: lui         $t0, 0x801D
    ctx->r8 = S32(0X801D << 16);
    // 0x801A6ACC: bne         $t8, $zero, L_801A6AE0
    if (ctx->r24 != 0) {
        // 0x801A6AD0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_801A6AE0;
    }
    // 0x801A6AD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801A6AD4: lw          $t9, -0x26AC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X26AC);
    // 0x801A6AD8: bnel        $s0, $t9, L_801A6D9C
    if (ctx->r16 != ctx->r25) {
        // 0x801A6ADC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801A6D9C;
    }
    goto skip_0;
    // 0x801A6ADC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
L_801A6AE0:
    // 0x801A6AE0: lw          $t0, -0x26AC($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X26AC);
    // 0x801A6AE4: lui         $t1, 0x801D
    ctx->r9 = S32(0X801D << 16);
    // 0x801A6AE8: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x801A6AEC: bnel        $s0, $t0, L_801A6B24
    if (ctx->r16 != ctx->r8) {
        // 0x801A6AF0: sw          $t4, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r12;
            goto L_801A6B24;
    }
    goto skip_1;
    // 0x801A6AF0: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    skip_1:
    // 0x801A6AF4: lw          $t1, -0x26BC($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X26BC);
    // 0x801A6AF8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801A6AFC: lui         $t2, 0x801D
    ctx->r10 = S32(0X801D << 16);
    // 0x801A6B00: bnel        $t1, $at, L_801A6B24
    if (ctx->r9 != ctx->r1) {
        // 0x801A6B04: sw          $t4, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r12;
            goto L_801A6B24;
    }
    goto skip_2;
    // 0x801A6B04: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    skip_2:
    // 0x801A6B08: lw          $t2, -0x26A4($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X26A4);
    // 0x801A6B0C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x801A6B10: beql        $t2, $zero, L_801A6B24
    if (ctx->r10 == 0) {
        // 0x801A6B14: sw          $t4, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r12;
            goto L_801A6B24;
    }
    goto skip_3;
    // 0x801A6B14: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    skip_3:
    // 0x801A6B18: b           L_801A6B24
    // 0x801A6B1C: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
        goto L_801A6B24;
    // 0x801A6B1C: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    // 0x801A6B20: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
L_801A6B24:
    // 0x801A6B24: jal         0x801A6DAC
    // 0x801A6B28: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    Map_CheckPlanetMedal(rdram, ctx);
        goto after_0;
    // 0x801A6B28: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x801A6B2C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x801A6B30: jal         0x801A6EC0
    // 0x801A6B34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Map_PlanetAnim2(rdram, ctx);
        goto after_1;
    // 0x801A6B34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x801A6B38: jal         0x801A7D3C
    // 0x801A6B3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Map_PlanetCleared2_Draw(rdram, ctx);
        goto after_2;
    // 0x801A6B3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x801A6B40: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A6B44: jal         0x80005708
    // 0x801A6B48: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Push(rdram, ctx);
        goto after_3;
    // 0x801A6B48: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_3:
    // 0x801A6B4C: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x801A6B50: lw          $t5, 0x7DB0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7DB0);
    // 0x801A6B54: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x801A6B58: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x801A6B5C: and         $t7, $t5, $t6
    ctx->r15 = ctx->r13 & ctx->r14;
    // 0x801A6B60: beq         $t7, $zero, L_801A6D8C
    if (ctx->r15 == 0) {
        // 0x801A6B64: nop
    
            goto L_801A6D8C;
    }
    // 0x801A6B64: nop

    // 0x801A6B68: bnel        $s0, $at, L_801A6B7C
    if (ctx->r16 != ctx->r1) {
        // 0x801A6B6C: lw          $t8, 0x28($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X28);
            goto L_801A6B7C;
    }
    goto skip_4;
    // 0x801A6B6C: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    skip_4:
    // 0x801A6B70: jal         0x801A791C
    // 0x801A6B74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Map_Titania_DrawRings1(rdram, ctx);
        goto after_4;
    // 0x801A6B74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x801A6B78: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
L_801A6B7C:
    // 0x801A6B7C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801A6B80: sll         $t9, $s0, 2
    ctx->r25 = S32(ctx->r16 << 2);
    // 0x801A6B84: bne         $t8, $at, L_801A6BD8
    if (ctx->r24 != ctx->r1) {
        // 0x801A6B88: sll         $t0, $s0, 2
        ctx->r8 = S32(ctx->r16 << 2);
            goto L_801A6BD8;
    }
    // 0x801A6B88: sll         $t0, $s0, 2
    ctx->r8 = S32(ctx->r16 << 2);
    // 0x801A6B8C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A6B90: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x801A6B94: lwc1        $f4, -0x15E8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X15E8);
    // 0x801A6B98: subu        $t0, $t0, $s0
    ctx->r8 = SUB32(ctx->r8, ctx->r16);
    // 0x801A6B9C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x801A6BA0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A6BA4: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x801A6BA8: lwc1        $f6, -0x1698($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X1698);
    // 0x801A6BAC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801A6BB0: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x801A6BB4: nop

    // 0x801A6BB8: bc1f        L_801A6BD8
    if (!c1cs) {
        // 0x801A6BBC: nop
    
            goto L_801A6BD8;
    }
    // 0x801A6BBC: nop

    // 0x801A6BC0: beq         $s0, $at, L_801A6BD8
    if (ctx->r16 == ctx->r1) {
        // 0x801A6BC4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_801A6BD8;
    }
    // 0x801A6BC4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801A6BC8: beq         $s0, $at, L_801A6BD8
    if (ctx->r16 == ctx->r1) {
        // 0x801A6BCC: nop
    
            goto L_801A6BD8;
    }
    // 0x801A6BCC: nop

    // 0x801A6BD0: jal         0x801A7F1C
    // 0x801A6BD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Map_PlanetCleared_Draw(rdram, ctx);
        goto after_5;
    // 0x801A6BD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
L_801A6BD8:
    // 0x801A6BD8: jal         0x801A7230
    // 0x801A6BDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Map_PlanetAnim(rdram, ctx);
        goto after_6;
    // 0x801A6BDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x801A6BE0: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x801A6BE4: bnel        $s0, $at, L_801A6BF8
    if (ctx->r16 != ctx->r1) {
        // 0x801A6BE8: lw          $t1, 0x24($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X24);
            goto L_801A6BF8;
    }
    goto skip_5;
    // 0x801A6BE8: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    skip_5:
    // 0x801A6BEC: jal         0x801A74F4
    // 0x801A6BF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Map_SolarRays_Draw(rdram, ctx);
        goto after_7;
    // 0x801A6BF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x801A6BF4: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
L_801A6BF8:
    // 0x801A6BF8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x801A6BFC: lw          $t2, 0x28($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X28);
    // 0x801A6C00: bne         $t2, $at, L_801A6C70
    if (ctx->r10 != ctx->r1) {
        // 0x801A6C04: addiu       $at, $zero, 0xD
        ctx->r1 = ADD32(0, 0XD);
            goto L_801A6C70;
    }
    // 0x801A6C04: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x801A6C08: beq         $s0, $at, L_801A6C30
    if (ctx->r16 == ctx->r1) {
        // 0x801A6C0C: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_801A6C30;
    }
    // 0x801A6C0C: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x801A6C10: beq         $s0, $at, L_801A6C28
    if (ctx->r16 == ctx->r1) {
        // 0x801A6C14: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_801A6C28;
    }
    // 0x801A6C14: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x801A6C18: beq         $s0, $at, L_801A6C28
    if (ctx->r16 == ctx->r1) {
        // 0x801A6C1C: nop
    
            goto L_801A6C28;
    }
    // 0x801A6C1C: nop

    // 0x801A6C20: jal         0x801A7684
    // 0x801A6C24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Map_VenomCloud2_Draw(rdram, ctx);
        goto after_8;
    // 0x801A6C24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
L_801A6C28:
    // 0x801A6C28: jal         0x801A77B0
    // 0x801A6C2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Map_PlanetShadow_Draw(rdram, ctx);
        goto after_9;
    // 0x801A6C2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
L_801A6C30:
    // 0x801A6C30: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x801A6C34: bne         $s0, $at, L_801A6C70
    if (ctx->r16 != ctx->r1) {
        // 0x801A6C38: lui         $a0, 0x801D
        ctx->r4 = S32(0X801D << 16);
            goto L_801A6C70;
    }
    // 0x801A6C38: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x801A6C3C: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    // 0x801A6C40: lui         $a2, 0x4046
    ctx->r6 = S32(0X4046 << 16);
    // 0x801A6C44: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x801A6C48: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x801A6C4C: jal         0x801A7BEC
    // 0x801A6C50: addiu       $a0, $a0, -0x1144
    ctx->r4 = ADD32(ctx->r4, -0X1144);
    Map_VenomCloud_Draw(rdram, ctx);
        goto after_10;
    // 0x801A6C50: addiu       $a0, $a0, -0x1144
    ctx->r4 = ADD32(ctx->r4, -0X1144);
    after_10:
    // 0x801A6C54: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x801A6C58: lui         $a1, 0xBDCC
    ctx->r5 = S32(0XBDCC << 16);
    // 0x801A6C5C: lui         $a2, 0x4039
    ctx->r6 = S32(0X4039 << 16);
    // 0x801A6C60: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x801A6C64: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x801A6C68: jal         0x801A7BEC
    // 0x801A6C6C: addiu       $a0, $a0, -0x1140
    ctx->r4 = ADD32(ctx->r4, -0X1140);
    Map_VenomCloud_Draw(rdram, ctx);
        goto after_11;
    // 0x801A6C6C: addiu       $a0, $a0, -0x1140
    ctx->r4 = ADD32(ctx->r4, -0X1140);
    after_11:
L_801A6C70:
    // 0x801A6C70: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x801A6C74: bnel        $s0, $at, L_801A6C88
    if (ctx->r16 != ctx->r1) {
        // 0x801A6C78: addiu       $at, $zero, 0x9
        ctx->r1 = ADD32(0, 0X9);
            goto L_801A6C88;
    }
    goto skip_6;
    // 0x801A6C78: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    skip_6:
    // 0x801A6C7C: jal         0x801A7A84
    // 0x801A6C80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Map_Titania_DrawRings2(rdram, ctx);
        goto after_12;
    // 0x801A6C80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x801A6C84: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
L_801A6C88:
    // 0x801A6C88: bne         $s0, $at, L_801A6CA8
    if (ctx->r16 != ctx->r1) {
        // 0x801A6C8C: lui         $t3, 0x801D
        ctx->r11 = S32(0X801D << 16);
            goto L_801A6CA8;
    }
    // 0x801A6C8C: lui         $t3, 0x801D
    ctx->r11 = S32(0X801D << 16);
    // 0x801A6C90: lw          $t3, -0x14B8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X14B8);
    // 0x801A6C94: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x801A6C98: beql        $t3, $zero, L_801A6CAC
    if (ctx->r11 == 0) {
        // 0x801A6C9C: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_801A6CAC;
    }
    goto skip_7;
    // 0x801A6C9C: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    skip_7:
    // 0x801A6CA0: jal         0x801A89BC
    // 0x801A6CA4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    Map_PlanetExplosions_Draw(rdram, ctx);
        goto after_13;
    // 0x801A6CA4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_13:
L_801A6CA8:
    // 0x801A6CA8: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
L_801A6CAC:
    // 0x801A6CAC: bne         $s0, $at, L_801A6CCC
    if (ctx->r16 != ctx->r1) {
        // 0x801A6CB0: lui         $t4, 0x801D
        ctx->r12 = S32(0X801D << 16);
            goto L_801A6CCC;
    }
    // 0x801A6CB0: lui         $t4, 0x801D
    ctx->r12 = S32(0X801D << 16);
    // 0x801A6CB4: lw          $t4, -0x14B4($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X14B4);
    // 0x801A6CB8: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x801A6CBC: beql        $t4, $zero, L_801A6CD0
    if (ctx->r12 == 0) {
        // 0x801A6CC0: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_801A6CD0;
    }
    goto skip_8;
    // 0x801A6CC0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    skip_8:
    // 0x801A6CC4: jal         0x801A89BC
    // 0x801A6CC8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    Map_PlanetExplosions_Draw(rdram, ctx);
        goto after_14;
    // 0x801A6CC8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_14:
L_801A6CCC:
    // 0x801A6CCC: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
L_801A6CD0:
    // 0x801A6CD0: bne         $s0, $at, L_801A6CF0
    if (ctx->r16 != ctx->r1) {
        // 0x801A6CD4: lui         $t5, 0x801D
        ctx->r13 = S32(0X801D << 16);
            goto L_801A6CF0;
    }
    // 0x801A6CD4: lui         $t5, 0x801D
    ctx->r13 = S32(0X801D << 16);
    // 0x801A6CD8: lw          $t5, -0x14B0($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X14B0);
    // 0x801A6CDC: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x801A6CE0: beql        $t5, $zero, L_801A6CF4
    if (ctx->r13 == 0) {
        // 0x801A6CE4: lw          $t6, 0x28($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X28);
            goto L_801A6CF4;
    }
    goto skip_9;
    // 0x801A6CE4: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    skip_9:
    // 0x801A6CE8: jal         0x801A89BC
    // 0x801A6CEC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    Map_PlanetExplosions_Draw(rdram, ctx);
        goto after_15;
    // 0x801A6CEC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_15:
L_801A6CF0:
    // 0x801A6CF0: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
L_801A6CF4:
    // 0x801A6CF4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801A6CF8: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
    // 0x801A6CFC: bne         $t6, $v0, L_801A6D50
    if (ctx->r14 != ctx->r2) {
        // 0x801A6D00: lui         $at, 0x801D
        ctx->r1 = S32(0X801D << 16);
            goto L_801A6D50;
    }
    // 0x801A6D00: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A6D04: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x801A6D08: sll         $t8, $s0, 2
    ctx->r24 = S32(ctx->r16 << 2);
    // 0x801A6D0C: lwc1        $f8, -0x15E8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X15E8);
    // 0x801A6D10: subu        $t8, $t8, $s0
    ctx->r24 = SUB32(ctx->r24, ctx->r16);
    // 0x801A6D14: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x801A6D18: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A6D1C: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x801A6D20: lwc1        $f10, -0x1698($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X1698);
    // 0x801A6D24: c.le.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl <= ctx->f8.fl;
    // 0x801A6D28: nop

    // 0x801A6D2C: bc1fl       L_801A6D54
    if (!c1cs) {
        // 0x801A6D30: lw          $t9, 0x28($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X28);
            goto L_801A6D54;
    }
    goto skip_10;
    // 0x801A6D30: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    skip_10:
    // 0x801A6D34: beq         $s0, $v0, L_801A6D50
    if (ctx->r16 == ctx->r2) {
        // 0x801A6D38: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_801A6D50;
    }
    // 0x801A6D38: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801A6D3C: beql        $s0, $at, L_801A6D54
    if (ctx->r16 == ctx->r1) {
        // 0x801A6D40: lw          $t9, 0x28($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X28);
            goto L_801A6D54;
    }
    goto skip_11;
    // 0x801A6D40: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    skip_11:
    // 0x801A6D44: jal         0x801A7F1C
    // 0x801A6D48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Map_PlanetCleared_Draw(rdram, ctx);
        goto after_16;
    // 0x801A6D48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x801A6D4C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801A6D50:
    // 0x801A6D50: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
L_801A6D54:
    // 0x801A6D54: bnel        $t9, $v0, L_801A6D78
    if (ctx->r25 != ctx->r2) {
        // 0x801A6D58: lw          $t0, 0x28($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X28);
            goto L_801A6D78;
    }
    goto skip_12;
    // 0x801A6D58: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    skip_12:
    // 0x801A6D5C: beq         $s0, $v0, L_801A6D6C
    if (ctx->r16 == ctx->r2) {
        // 0x801A6D60: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_801A6D6C;
    }
    // 0x801A6D60: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801A6D64: bnel        $s0, $at, L_801A6D78
    if (ctx->r16 != ctx->r1) {
        // 0x801A6D68: lw          $t0, 0x28($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X28);
            goto L_801A6D78;
    }
    goto skip_13;
    // 0x801A6D68: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    skip_13:
L_801A6D6C:
    // 0x801A6D6C: jal         0x801A7F1C
    // 0x801A6D70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Map_PlanetCleared_Draw(rdram, ctx);
        goto after_17;
    // 0x801A6D70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x801A6D74: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
L_801A6D78:
    // 0x801A6D78: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801A6D7C: bne         $t0, $at, L_801A6D8C
    if (ctx->r8 != ctx->r1) {
        // 0x801A6D80: nop
    
            goto L_801A6D8C;
    }
    // 0x801A6D80: nop

    // 0x801A6D84: jal         0x801A809C
    // 0x801A6D88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Map_PlanetMedal_Draw(rdram, ctx);
        goto after_18;
    // 0x801A6D88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
L_801A6D8C:
    // 0x801A6D8C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A6D90: jal         0x80005740
    // 0x801A6D94: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Pop(rdram, ctx);
        goto after_19;
    // 0x801A6D94: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_19:
    // 0x801A6D98: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801A6D9C:
    // 0x801A6D9C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801A6DA0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801A6DA4: jr          $ra
    // 0x801A6DA8: nop

    return;
    // 0x801A6DA8: nop

;}
RECOMP_FUNC void Map_LylatCard_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A1528: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801A152C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801A1530: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801A1534: lw          $v0, -0x26B8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X26B8);
    // 0x801A1538: lui         $t0, 0x801D
    ctx->r8 = S32(0X801D << 16);
    // 0x801A153C: addiu       $t0, $t0, -0x2650
    ctx->r8 = ADD32(ctx->r8, -0X2650);
    // 0x801A1540: beq         $v0, $zero, L_801A155C
    if (ctx->r2 == 0) {
        // 0x801A1544: lui         $a0, 0x801D
        ctx->r4 = S32(0X801D << 16);
            goto L_801A155C;
    }
    // 0x801A1544: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x801A1548: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801A154C: beq         $v0, $at, L_801A15F4
    if (ctx->r2 == ctx->r1) {
        // 0x801A1550: lui         $t6, 0x801D
        ctx->r14 = S32(0X801D << 16);
            goto L_801A15F4;
    }
    // 0x801A1550: lui         $t6, 0x801D
    ctx->r14 = S32(0X801D << 16);
    // 0x801A1554: b           L_801A17D8
    // 0x801A1558: nop

        goto L_801A17D8;
    // 0x801A1558: nop

L_801A155C:
    // 0x801A155C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801A1560: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801A1564: addiu       $a0, $a0, -0x1564
    ctx->r4 = ADD32(ctx->r4, -0X1564);
    // 0x801A1568: lui         $a1, 0x437F
    ctx->r5 = S32(0X437F << 16);
    // 0x801A156C: lw          $a2, 0x0($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X0);
    // 0x801A1570: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x801A1574: jal         0x8009BC2C
    // 0x801A1578: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_0;
    // 0x801A1578: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x801A157C: lui         $t0, 0x801D
    ctx->r8 = S32(0X801D << 16);
    // 0x801A1580: addiu       $t0, $t0, -0x2650
    ctx->r8 = ADD32(ctx->r8, -0X2650);
    // 0x801A1584: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A1588: lwc1        $f8, 0x75D8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X75D8);
    // 0x801A158C: lwc1        $f6, 0x0($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X0);
    // 0x801A1590: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x801A1594: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A1598: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x801A159C: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    // 0x801A15A0: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x801A15A4: addiu       $t7, $zero, 0x2D
    ctx->r15 = ADD32(0, 0X2D);
    // 0x801A15A8: bc1f        L_801A15EC
    if (!c1cs) {
        // 0x801A15AC: swc1        $f10, 0x0($t0)
        MEM_W(0X0, ctx->r8) = ctx->f10.u32l;
            goto L_801A15EC;
    }
    // 0x801A15AC: swc1        $f10, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f10.u32l;
    // 0x801A15B0: swc1        $f2, -0x1560($at)
    MEM_W(-0X1560, ctx->r1) = ctx->f2.u32l;
    // 0x801A15B4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A15B8: swc1        $f2, -0x155C($at)
    MEM_W(-0X155C, ctx->r1) = ctx->f2.u32l;
    // 0x801A15BC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A15C0: lwc1        $f16, 0x75DC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X75DC);
    // 0x801A15C4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A15C8: lui         $t8, 0x801D
    ctx->r24 = S32(0X801D << 16);
    // 0x801A15CC: swc1        $f16, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f16.u32l;
    // 0x801A15D0: lw          $t8, -0x26B8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X26B8);
    // 0x801A15D4: sw          $t6, -0x2648($at)
    MEM_W(-0X2648, ctx->r1) = ctx->r14;
    // 0x801A15D8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A15DC: sw          $t7, -0x2644($at)
    MEM_W(-0X2644, ctx->r1) = ctx->r15;
    // 0x801A15E0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A15E4: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x801A15E8: sw          $t9, -0x26B8($at)
    MEM_W(-0X26B8, ctx->r1) = ctx->r25;
L_801A15EC:
    // 0x801A15EC: b           L_801A17D8
    // 0x801A15F0: nop

        goto L_801A17D8;
    // 0x801A15F0: nop

L_801A15F4:
    // 0x801A15F4: lw          $t6, -0x2648($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2648);
    // 0x801A15F8: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x801A15FC: addiu       $a0, $a0, -0x1564
    ctx->r4 = ADD32(ctx->r4, -0X1564);
    // 0x801A1600: beq         $t6, $zero, L_801A1610
    if (ctx->r14 == 0) {
        // 0x801A1604: addiu       $a1, $zero, 0x0
        ctx->r5 = ADD32(0, 0X0);
            goto L_801A1610;
    }
    // 0x801A1604: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x801A1608: b           L_801A17D8
    // 0x801A160C: nop

        goto L_801A17D8;
    // 0x801A160C: nop

L_801A1610:
    // 0x801A1610: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A1614: lwc1        $f18, 0x75E0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X75E0);
    // 0x801A1618: lui         $a2, 0x801D
    ctx->r6 = S32(0X801D << 16);
    // 0x801A161C: lw          $a2, -0x264C($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X264C);
    // 0x801A1620: lui         $a3, 0x4248
    ctx->r7 = S32(0X4248 << 16);
    // 0x801A1624: jal         0x8009BC2C
    // 0x801A1628: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_1;
    // 0x801A1628: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_1:
    // 0x801A162C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801A1630: addiu       $v0, $v0, -0x264C
    ctx->r2 = ADD32(ctx->r2, -0X264C);
    // 0x801A1634: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A1638: lwc1        $f6, 0x75E4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X75E4);
    // 0x801A163C: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801A1640: lui         $t7, 0x801D
    ctx->r15 = S32(0X801D << 16);
    // 0x801A1644: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x801A1648: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x801A164C: addiu       $a0, $a0, -0x1560
    ctx->r4 = ADD32(ctx->r4, -0X1560);
    // 0x801A1650: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A1654: lui         $a1, 0x4310
    ctx->r5 = S32(0X4310 << 16);
    // 0x801A1658: lui         $a2, 0x801D
    ctx->r6 = S32(0X801D << 16);
    // 0x801A165C: lui         $a3, 0x4248
    ctx->r7 = S32(0X4248 << 16);
    // 0x801A1660: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x801A1664: lw          $t7, -0x2644($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2644);
    // 0x801A1668: beq         $t7, $zero, L_801A1678
    if (ctx->r15 == 0) {
        // 0x801A166C: nop
    
            goto L_801A1678;
    }
    // 0x801A166C: nop

    // 0x801A1670: b           L_801A17D8
    // 0x801A1674: nop

        goto L_801A17D8;
    // 0x801A1674: nop

L_801A1678:
    // 0x801A1678: lwc1        $f10, 0x75E8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X75E8);
    // 0x801A167C: lw          $a2, -0x2650($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X2650);
    // 0x801A1680: jal         0x8009BC2C
    // 0x801A1684: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_2;
    // 0x801A1684: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_2:
    // 0x801A1688: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A168C: lwc1        $f16, 0x75EC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X75EC);
    // 0x801A1690: lui         $t0, 0x801D
    ctx->r8 = S32(0X801D << 16);
    // 0x801A1694: addiu       $t0, $t0, -0x2650
    ctx->r8 = ADD32(ctx->r8, -0X2650);
    // 0x801A1698: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x801A169C: addiu       $a0, $a0, -0x155C
    ctx->r4 = ADD32(ctx->r4, -0X155C);
    // 0x801A16A0: lw          $a2, 0x0($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X0);
    // 0x801A16A4: lui         $a1, 0x437F
    ctx->r5 = S32(0X437F << 16);
    // 0x801A16A8: lui         $a3, 0x4248
    ctx->r7 = S32(0X4248 << 16);
    // 0x801A16AC: jal         0x8009BC2C
    // 0x801A16B0: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_3;
    // 0x801A16B0: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_3:
    // 0x801A16B4: lui         $t0, 0x801D
    ctx->r8 = S32(0X801D << 16);
    // 0x801A16B8: addiu       $t0, $t0, -0x2650
    ctx->r8 = ADD32(ctx->r8, -0X2650);
    // 0x801A16BC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A16C0: lwc1        $f4, 0x75F0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X75F0);
    // 0x801A16C4: lwc1        $f18, 0x0($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X0);
    // 0x801A16C8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A16CC: lui         $v1, 0x801B
    ctx->r3 = S32(0X801B << 16);
    // 0x801A16D0: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x801A16D4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801A16D8: lui         $t1, 0x801D
    ctx->r9 = S32(0X801D << 16);
    // 0x801A16DC: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801A16E0: lui         $a2, 0x801D
    ctx->r6 = S32(0X801D << 16);
    // 0x801A16E4: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801A16E8: addiu       $a1, $a1, -0x26F4
    ctx->r5 = ADD32(ctx->r5, -0X26F4);
    // 0x801A16EC: swc1        $f6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f6.u32l;
    // 0x801A16F0: lwc1        $f2, -0x1560($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X1560);
    // 0x801A16F4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A16F8: lwc1        $f8, -0x155C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X155C);
    // 0x801A16FC: lui         $t0, 0x801D
    ctx->r8 = S32(0X801D << 16);
    // 0x801A1700: addiu       $t0, $t0, -0x26C4
    ctx->r8 = ADD32(ctx->r8, -0X26C4);
    // 0x801A1704: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x801A1708: addiu       $a2, $a2, -0x26F0
    ctx->r6 = ADD32(ctx->r6, -0X26F0);
    // 0x801A170C: addiu       $a3, $a3, -0x26EC
    ctx->r7 = ADD32(ctx->r7, -0X26EC);
    // 0x801A1710: addiu       $t1, $t1, -0x2690
    ctx->r9 = ADD32(ctx->r9, -0X2690);
    // 0x801A1714: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x801A1718: addiu       $v0, $v0, -0x2700
    ctx->r2 = ADD32(ctx->r2, -0X2700);
    // 0x801A171C: addiu       $v1, $v1, -0xB60
    ctx->r3 = ADD32(ctx->r3, -0XB60);
L_801A1720:
    // 0x801A1720: beql        $v0, $a1, L_801A173C
    if (ctx->r2 == ctx->r5) {
        // 0x801A1724: trunc.w.s   $f16, $f2
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    ctx->f16.u32l = TRUNC_W_S(ctx->f2.fl);
            goto L_801A173C;
    }
    goto skip_0;
    // 0x801A1724: trunc.w.s   $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    ctx->f16.u32l = TRUNC_W_S(ctx->f2.fl);
    skip_0:
    // 0x801A1728: beql        $v0, $a2, L_801A173C
    if (ctx->r2 == ctx->r6) {
        // 0x801A172C: trunc.w.s   $f16, $f2
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    ctx->f16.u32l = TRUNC_W_S(ctx->f2.fl);
            goto L_801A173C;
    }
    goto skip_1;
    // 0x801A172C: trunc.w.s   $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    ctx->f16.u32l = TRUNC_W_S(ctx->f2.fl);
    skip_1:
    // 0x801A1730: bnel        $v0, $a3, L_801A174C
    if (ctx->r2 != ctx->r7) {
        // 0x801A1734: sw          $a0, 0x24($v1)
        MEM_W(0X24, ctx->r3) = ctx->r4;
            goto L_801A174C;
    }
    goto skip_2;
    // 0x801A1734: sw          $a0, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r4;
    skip_2:
    // 0x801A1738: trunc.w.s   $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    ctx->f16.u32l = TRUNC_W_S(ctx->f2.fl);
L_801A173C:
    // 0x801A173C: mfc1        $t6, $f16
    ctx->r14 = (int32_t)ctx->f16.u32l;
    // 0x801A1740: b           L_801A1750
    // 0x801A1744: sw          $t6, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r14;
        goto L_801A1750;
    // 0x801A1744: sw          $t6, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r14;
    // 0x801A1748: sw          $a0, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r4;
L_801A174C:
    // 0x801A174C: sw          $a0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r4;
L_801A1750:
    // 0x801A1750: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x801A1754: addiu       $v1, $v1, 0x38
    ctx->r3 = ADD32(ctx->r3, 0X38);
    // 0x801A1758: bne         $v0, $t0, L_801A1720
    if (ctx->r2 != ctx->r8) {
        // 0x801A175C: sw          $a0, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->r4;
            goto L_801A1720;
    }
    // 0x801A175C: sw          $a0, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r4;
    // 0x801A1760: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x801A1764: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801A1768: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801A176C: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x801A1770: c.lt.s      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl < ctx->f2.fl;
    // 0x801A1774: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A1778: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801A177C: ori         $a0, $a0, 0x1F
    ctx->r4 = ctx->r4 | 0X1F;
    // 0x801A1780: bc1f        L_801A178C
    if (!c1cs) {
        // 0x801A1784: lui         $a1, 0x800C
        ctx->r5 = S32(0X800C << 16);
            goto L_801A178C;
    }
    // 0x801A1784: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x801A1788: sw          $t7, -0x268C($at)
    MEM_W(-0X268C, ctx->r1) = ctx->r15;
L_801A178C:
    // 0x801A178C: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x801A1790: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x801A1794: addiu       $a3, $t8, 0x5D34
    ctx->r7 = ADD32(ctx->r24, 0X5D34);
    // 0x801A1798: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x801A179C: bc1f        L_801A17D8
    if (!c1cs) {
        // 0x801A17A0: addiu       $a2, $zero, 0x4
        ctx->r6 = ADD32(0, 0X4);
            goto L_801A17D8;
    }
    // 0x801A17A0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x801A17A4: lui         $t9, 0x800C
    ctx->r25 = S32(0X800C << 16);
    // 0x801A17A8: addiu       $t9, $t9, 0x5D3C
    ctx->r25 = ADD32(ctx->r25, 0X5D3C);
    // 0x801A17AC: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x801A17B0: jal         0x80019218
    // 0x801A17B4: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    Audio_PlaySfx(rdram, ctx);
        goto after_4;
    // 0x801A17B4: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_4:
    // 0x801A17B8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A17BC: sw          $zero, -0x26B8($at)
    MEM_W(-0X26B8, ctx->r1) = 0;
    // 0x801A17C0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A17C4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801A17C8: sw          $t6, -0x2684($at)
    MEM_W(-0X2684, ctx->r1) = ctx->r14;
    // 0x801A17CC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A17D0: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x801A17D4: sw          $t7, -0x26BC($at)
    MEM_W(-0X26BC, ctx->r1) = ctx->r15;
L_801A17D8:
    // 0x801A17D8: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x801A17DC: lw          $t8, 0x7AF8($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7AF8);
    // 0x801A17E0: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x801A17E4: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x801A17E8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x801A17EC: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x801A17F0: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x801A17F4: addu        $t6, $t6, $t9
    ctx->r14 = ADD32(ctx->r14, ctx->r25);
    // 0x801A17F8: lhu         $t6, -0x2768($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X2768);
    // 0x801A17FC: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x801A1800: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x801A1804: andi        $t7, $t6, 0x1000
    ctx->r15 = ctx->r14 & 0X1000;
    // 0x801A1808: beq         $t7, $zero, L_801A1998
    if (ctx->r15 == 0) {
        // 0x801A180C: ori         $a0, $a0, 0x1F
        ctx->r4 = ctx->r4 | 0X1F;
            goto L_801A1998;
    }
    // 0x801A180C: ori         $a0, $a0, 0x1F
    ctx->r4 = ctx->r4 | 0X1F;
    // 0x801A1810: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x801A1814: addiu       $t8, $t8, 0x5D3C
    ctx->r24 = ADD32(ctx->r24, 0X5D3C);
    // 0x801A1818: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x801A181C: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x801A1820: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x801A1824: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x801A1828: jal         0x80019218
    // 0x801A182C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    Audio_PlaySfx(rdram, ctx);
        goto after_5;
    // 0x801A182C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_5:
    // 0x801A1830: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x801A1834: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A1838: sw          $t9, -0xB3C($at)
    MEM_W(-0XB3C, ctx->r1) = ctx->r25;
    // 0x801A183C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A1840: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x801A1844: sw          $t6, -0x2700($at)
    MEM_W(-0X2700, ctx->r1) = ctx->r14;
    // 0x801A1848: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A184C: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x801A1850: sw          $t7, -0xB04($at)
    MEM_W(-0XB04, ctx->r1) = ctx->r15;
    // 0x801A1854: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A1858: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x801A185C: sw          $t8, -0x26FC($at)
    MEM_W(-0X26FC, ctx->r1) = ctx->r24;
    // 0x801A1860: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A1864: sw          $t9, -0xACC($at)
    MEM_W(-0XACC, ctx->r1) = ctx->r25;
    // 0x801A1868: lui         $t7, 0x801D
    ctx->r15 = S32(0X801D << 16);
    // 0x801A186C: addiu       $a2, $t7, -0x26F4
    ctx->r6 = ADD32(ctx->r15, -0X26F4);
    // 0x801A1870: lui         $t9, 0x801D
    ctx->r25 = S32(0X801D << 16);
    // 0x801A1874: lui         $t8, 0x801D
    ctx->r24 = S32(0X801D << 16);
    // 0x801A1878: addiu       $t1, $t8, -0x26F8
    ctx->r9 = ADD32(ctx->r24, -0X26F8);
    // 0x801A187C: addiu       $a3, $t9, -0x26F0
    ctx->r7 = ADD32(ctx->r25, -0X26F0);
    // 0x801A1880: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A1884: lui         $v1, 0x801B
    ctx->r3 = S32(0X801B << 16);
    // 0x801A1888: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801A188C: lui         $t4, 0x801D
    ctx->r12 = S32(0X801D << 16);
    // 0x801A1890: lui         $t0, 0x801D
    ctx->r8 = S32(0X801D << 16);
    // 0x801A1894: addiu       $t0, $t0, -0x26EC
    ctx->r8 = ADD32(ctx->r8, -0X26EC);
    // 0x801A1898: addiu       $t4, $t4, -0x26FC
    ctx->r12 = ADD32(ctx->r12, -0X26FC);
    // 0x801A189C: addiu       $v0, $v0, -0x26F4
    ctx->r2 = ADD32(ctx->r2, -0X26F4);
    // 0x801A18A0: addiu       $v1, $v1, -0xAB8
    ctx->r3 = ADD32(ctx->r3, -0XAB8);
    // 0x801A18A4: sw          $t6, -0x26F8($at)
    MEM_W(-0X26F8, ctx->r1) = ctx->r14;
    // 0x801A18A8: or          $t3, $a3, $zero
    ctx->r11 = ctx->r7 | 0;
    // 0x801A18AC: or          $t5, $t1, $zero
    ctx->r13 = ctx->r9 | 0;
    // 0x801A18B0: or          $ra, $a2, $zero
    ctx->r31 = ctx->r6 | 0;
    // 0x801A18B4: or          $t2, $a2, $zero
    ctx->r10 = ctx->r6 | 0;
    // 0x801A18B8: addiu       $a1, $zero, 0x90
    ctx->r5 = ADD32(0, 0X90);
    // 0x801A18BC: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
L_801A18C0:
    // 0x801A18C0: beq         $v0, $a2, L_801A18D8
    if (ctx->r2 == ctx->r6) {
        // 0x801A18C4: lui         $t6, 0x801D
        ctx->r14 = S32(0X801D << 16);
            goto L_801A18D8;
    }
    // 0x801A18C4: lui         $t6, 0x801D
    ctx->r14 = S32(0X801D << 16);
    // 0x801A18C8: beq         $v0, $a3, L_801A18D8
    if (ctx->r2 == ctx->r7) {
        // 0x801A18CC: nop
    
            goto L_801A18D8;
    }
    // 0x801A18CC: nop

    // 0x801A18D0: bnel        $v0, $t0, L_801A18E4
    if (ctx->r2 != ctx->r8) {
        // 0x801A18D4: sw          $a0, 0x24($v1)
        MEM_W(0X24, ctx->r3) = ctx->r4;
            goto L_801A18E4;
    }
    goto skip_3;
    // 0x801A18D4: sw          $a0, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r4;
    skip_3:
L_801A18D8:
    // 0x801A18D8: b           L_801A18E4
    // 0x801A18DC: sw          $a1, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r5;
        goto L_801A18E4;
    // 0x801A18DC: sw          $a1, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r5;
    // 0x801A18E0: sw          $a0, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r4;
L_801A18E4:
    // 0x801A18E4: beq         $v0, $t1, L_801A18FC
    if (ctx->r2 == ctx->r9) {
        // 0x801A18E8: sw          $a0, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r4;
            goto L_801A18FC;
    }
    // 0x801A18E8: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x801A18EC: beq         $v0, $t2, L_801A18FC
    if (ctx->r2 == ctx->r10) {
        // 0x801A18F0: nop
    
            goto L_801A18FC;
    }
    // 0x801A18F0: nop

    // 0x801A18F4: bnel        $v0, $t3, L_801A1908
    if (ctx->r2 != ctx->r11) {
        // 0x801A18F8: sw          $a0, 0x5C($v1)
        MEM_W(0X5C, ctx->r3) = ctx->r4;
            goto L_801A1908;
    }
    goto skip_4;
    // 0x801A18F8: sw          $a0, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->r4;
    skip_4:
L_801A18FC:
    // 0x801A18FC: b           L_801A1908
    // 0x801A1900: sw          $a1, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->r5;
        goto L_801A1908;
    // 0x801A1900: sw          $a1, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->r5;
    // 0x801A1904: sw          $a0, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->r4;
L_801A1908:
    // 0x801A1908: beq         $v0, $t4, L_801A1920
    if (ctx->r2 == ctx->r12) {
        // 0x801A190C: sw          $a0, 0x4($v0)
        MEM_W(0X4, ctx->r2) = ctx->r4;
            goto L_801A1920;
    }
    // 0x801A190C: sw          $a0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r4;
    // 0x801A1910: beq         $v0, $t5, L_801A1920
    if (ctx->r2 == ctx->r13) {
        // 0x801A1914: nop
    
            goto L_801A1920;
    }
    // 0x801A1914: nop

    // 0x801A1918: bnel        $v0, $ra, L_801A192C
    if (ctx->r2 != ctx->r31) {
        // 0x801A191C: sw          $a0, 0x94($v1)
        MEM_W(0X94, ctx->r3) = ctx->r4;
            goto L_801A192C;
    }
    goto skip_5;
    // 0x801A191C: sw          $a0, 0x94($v1)
    MEM_W(0X94, ctx->r3) = ctx->r4;
    skip_5:
L_801A1920:
    // 0x801A1920: b           L_801A192C
    // 0x801A1924: sw          $a1, 0x94($v1)
    MEM_W(0X94, ctx->r3) = ctx->r5;
        goto L_801A192C;
    // 0x801A1924: sw          $a1, 0x94($v1)
    MEM_W(0X94, ctx->r3) = ctx->r5;
    // 0x801A1928: sw          $a0, 0x94($v1)
    MEM_W(0X94, ctx->r3) = ctx->r4;
L_801A192C:
    // 0x801A192C: addiu       $t6, $t6, -0x2700
    ctx->r14 = ADD32(ctx->r14, -0X2700);
    // 0x801A1930: beq         $v0, $t6, L_801A1954
    if (ctx->r2 == ctx->r14) {
        // 0x801A1934: sw          $a0, 0x8($v0)
        MEM_W(0X8, ctx->r2) = ctx->r4;
            goto L_801A1954;
    }
    // 0x801A1934: sw          $a0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r4;
    // 0x801A1938: lui         $t8, 0x801D
    ctx->r24 = S32(0X801D << 16);
    // 0x801A193C: addiu       $t8, $t8, -0x26FC
    ctx->r24 = ADD32(ctx->r24, -0X26FC);
    // 0x801A1940: beq         $v0, $t8, L_801A1954
    if (ctx->r2 == ctx->r24) {
        // 0x801A1944: lui         $t9, 0x801D
        ctx->r25 = S32(0X801D << 16);
            goto L_801A1954;
    }
    // 0x801A1944: lui         $t9, 0x801D
    ctx->r25 = S32(0X801D << 16);
    // 0x801A1948: addiu       $t9, $t9, -0x26F8
    ctx->r25 = ADD32(ctx->r25, -0X26F8);
    // 0x801A194C: bnel        $v0, $t9, L_801A1960
    if (ctx->r2 != ctx->r25) {
        // 0x801A1950: sw          $a0, 0xCC($v1)
        MEM_W(0XCC, ctx->r3) = ctx->r4;
            goto L_801A1960;
    }
    goto skip_6;
    // 0x801A1950: sw          $a0, 0xCC($v1)
    MEM_W(0XCC, ctx->r3) = ctx->r4;
    skip_6:
L_801A1954:
    // 0x801A1954: b           L_801A1960
    // 0x801A1958: sw          $a1, 0xCC($v1)
    MEM_W(0XCC, ctx->r3) = ctx->r5;
        goto L_801A1960;
    // 0x801A1958: sw          $a1, 0xCC($v1)
    MEM_W(0XCC, ctx->r3) = ctx->r5;
    // 0x801A195C: sw          $a0, 0xCC($v1)
    MEM_W(0XCC, ctx->r3) = ctx->r4;
L_801A1960:
    // 0x801A1960: lui         $t7, 0x801D
    ctx->r15 = S32(0X801D << 16);
    // 0x801A1964: addiu       $t7, $t7, -0x26C4
    ctx->r15 = ADD32(ctx->r15, -0X26C4);
    // 0x801A1968: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x801A196C: sw          $a0, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r4;
    // 0x801A1970: bne         $v0, $t7, L_801A18C0
    if (ctx->r2 != ctx->r15) {
        // 0x801A1974: addiu       $v1, $v1, 0xE0
        ctx->r3 = ADD32(ctx->r3, 0XE0);
            goto L_801A18C0;
    }
    // 0x801A1974: addiu       $v1, $v1, 0xE0
    ctx->r3 = ADD32(ctx->r3, 0XE0);
    // 0x801A1978: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A197C: sw          $a0, -0x2690($at)
    MEM_W(-0X2690, ctx->r1) = ctx->r4;
    // 0x801A1980: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A1984: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x801A1988: sw          $t6, -0x26BC($at)
    MEM_W(-0X26BC, ctx->r1) = ctx->r14;
    // 0x801A198C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A1990: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801A1994: sw          $t8, -0x2684($at)
    MEM_W(-0X2684, ctx->r1) = ctx->r24;
L_801A1998:
    // 0x801A1998: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801A199C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801A19A0: jr          $ra
    // 0x801A19A4: nop

    return;
    // 0x801A19A4: nop

;}
RECOMP_FUNC void Map_Path_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801AC200: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x801AC204: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801AC208: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x801AC20C: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x801AC210: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x801AC214: addiu       $t8, $t8, 0x4750
    ctx->r24 = ADD32(ctx->r24, 0X4750);
    // 0x801AC218: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801AC21C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x801AC220: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x801AC224: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x801AC228: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801AC22C: lwc1        $f6, 0x10($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X10);
    // 0x801AC230: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801AC234: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x801AC238: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x801AC23C: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    // 0x801AC240: lwc1        $f4, 0x14($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X14);
    // 0x801AC244: sub.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x801AC248: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x801AC24C: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x801AC250: lwc1        $f10, 0x18($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X18);
    // 0x801AC254: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801AC258: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x801AC25C: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x801AC260: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x801AC264: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x801AC268: mul.s       $f8, $f12, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x801AC26C: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x801AC270: sub.s       $f14, $f10, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x801AC274: sll         $t3, $t9, 3
    ctx->r11 = S32(ctx->r25 << 3);
    // 0x801AC278: subu        $t3, $t3, $t9
    ctx->r11 = SUB32(ctx->r11, ctx->r25);
    // 0x801AC27C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x801AC280: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x801AC284: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801AC288: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801AC28C: addiu       $t4, $t4, -0x2E8
    ctx->r12 = ADD32(ctx->r12, -0X2E8);
    // 0x801AC290: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801AC294: addu        $t1, $t3, $t4
    ctx->r9 = ADD32(ctx->r11, ctx->r12);
    // 0x801AC298: add.s       $f0, $f10, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x801AC29C: sqrt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = sqrtf(ctx->f0.fl);
    // 0x801AC2A0: c.eq.s      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.fl == ctx->f6.fl;
    // 0x801AC2A4: nop

    // 0x801AC2A8: bc1fl       L_801AC2BC
    if (!c1cs) {
        // 0x801AC2AC: lw          $t2, 0x14($t1)
        ctx->r10 = MEM_W(ctx->r9, 0X14);
            goto L_801AC2BC;
    }
    goto skip_0;
    // 0x801AC2AC: lw          $t2, 0x14($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X14);
    skip_0:
    // 0x801AC2B0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801AC2B4: nop

    // 0x801AC2B8: lw          $t2, 0x14($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X14);
L_801AC2BC:
    // 0x801AC2BC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801AC2C0: bnel        $t2, $at, L_801AC420
    if (ctx->r10 != ctx->r1) {
        // 0x801AC2C4: div.s       $f4, $f2, $f18
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f2.fl, ctx->f18.fl);
            goto L_801AC420;
    }
    goto skip_1;
    // 0x801AC2C4: div.s       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f2.fl, ctx->f18.fl);
    skip_1:
    // 0x801AC2C8: lw          $a0, 0xC($t1)
    ctx->r4 = MEM_W(ctx->r9, 0XC);
    // 0x801AC2CC: div.s       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f2.fl, ctx->f18.fl);
    // 0x801AC2D0: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801AC2D4: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x801AC2D8: mtc1        $a0, $f8
    ctx->f8.u32l = ctx->r4;
    // 0x801AC2DC: addiu       $a3, $a3, -0x1160
    ctx->r7 = ADD32(ctx->r7, -0X1160);
    // 0x801AC2E0: lw          $a1, 0x0($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X0);
    // 0x801AC2E4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801AC2E8: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801AC2EC: addiu       $v1, $v1, -0x1150
    ctx->r3 = ADD32(ctx->r3, -0X1150);
    // 0x801AC2F0: lui         $t0, 0x801D
    ctx->r8 = S32(0X801D << 16);
    // 0x801AC2F4: addiu       $t0, $t0, -0x115C
    ctx->r8 = ADD32(ctx->r8, -0X115C);
    // 0x801AC2F8: lw          $a2, 0x0($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X0);
    // 0x801AC2FC: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x801AC300: div.s       $f0, $f18, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = DIV_S(ctx->f18.fl, ctx->f10.fl);
    // 0x801AC304: div.s       $f8, $f12, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = DIV_S(ctx->f12.fl, ctx->f18.fl);
    // 0x801AC308: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x801AC30C: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    // 0x801AC310: div.s       $f4, $f14, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f14.fl, ctx->f18.fl);
    // 0x801AC314: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x801AC318: mtc1        $a1, $f8
    ctx->f8.u32l = ctx->r5;
    // 0x801AC31C: nop

    // 0x801AC320: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801AC324: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    // 0x801AC328: lwc1        $f10, 0x24($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X24);
    // 0x801AC32C: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x801AC330: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x801AC334: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    // 0x801AC338: mul.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x801AC33C: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x801AC340: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x801AC344: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x801AC348: mul.s       $f6, $f10, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x801AC34C: swc1        $f8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f8.u32l;
    // 0x801AC350: lwc1        $f10, 0x1C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x801AC354: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801AC358: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x801AC35C: mul.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x801AC360: swc1        $f8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f8.u32l;
    // 0x801AC364: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x801AC368: beq         $a2, $zero, L_801AC394
    if (ctx->r6 == 0) {
        // 0x801AC36C: swc1        $f8, 0x8($v1)
        MEM_W(0X8, ctx->r3) = ctx->f8.u32l;
            goto L_801AC394;
    }
    // 0x801AC36C: swc1        $f8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f8.u32l;
    // 0x801AC370: addiu       $v1, $zero, 0xA
    ctx->r3 = ADD32(0, 0XA);
    // 0x801AC374: beq         $v0, $v1, L_801AC3B4
    if (ctx->r2 == ctx->r3) {
        // 0x801AC378: addiu       $at, $zero, 0x14
        ctx->r1 = ADD32(0, 0X14);
            goto L_801AC3B4;
    }
    // 0x801AC378: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x801AC37C: beq         $v0, $at, L_801AC3DC
    if (ctx->r2 == ctx->r1) {
        // 0x801AC380: addiu       $at, $zero, 0x64
        ctx->r1 = ADD32(0, 0X64);
            goto L_801AC3DC;
    }
    // 0x801AC380: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x801AC384: beq         $v0, $at, L_801AC39C
    if (ctx->r2 == ctx->r1) {
        // 0x801AC388: addiu       $t5, $zero, 0x5
        ctx->r13 = ADD32(0, 0X5);
            goto L_801AC39C;
    }
    // 0x801AC388: addiu       $t5, $zero, 0x5
    ctx->r13 = ADD32(0, 0X5);
    // 0x801AC38C: b           L_801AC40C
    // 0x801AC390: nop

        goto L_801AC40C;
    // 0x801AC390: nop

L_801AC394:
    // 0x801AC394: b           L_801AC40C
    // 0x801AC398: addiu       $v1, $zero, 0xA
    ctx->r3 = ADD32(0, 0XA);
        goto L_801AC40C;
    // 0x801AC398: addiu       $v1, $zero, 0xA
    ctx->r3 = ADD32(0, 0XA);
L_801AC39C:
    // 0x801AC39C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801AC3A0: addiu       $v0, $v0, -0x2644
    ctx->r2 = ADD32(ctx->r2, -0X2644);
    // 0x801AC3A4: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x801AC3A8: sw          $v1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r3;
    // 0x801AC3AC: b           L_801AC40C
    // 0x801AC3B0: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
        goto L_801AC40C;
    // 0x801AC3B0: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
L_801AC3B4:
    // 0x801AC3B4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801AC3B8: addiu       $v0, $v0, -0x2644
    ctx->r2 = ADD32(ctx->r2, -0X2644);
    // 0x801AC3BC: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801AC3C0: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x801AC3C4: bne         $t6, $zero, L_801AC40C
    if (ctx->r14 != 0) {
        // 0x801AC3C8: nop
    
            goto L_801AC40C;
    }
    // 0x801AC3C8: nop

    // 0x801AC3CC: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // 0x801AC3D0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801AC3D4: b           L_801AC40C
    // 0x801AC3D8: sw          $a2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r6;
        goto L_801AC40C;
    // 0x801AC3D8: sw          $a2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r6;
L_801AC3DC:
    // 0x801AC3DC: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801AC3E0: addiu       $v0, $v0, -0x2644
    ctx->r2 = ADD32(ctx->r2, -0X2644);
    // 0x801AC3E4: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x801AC3E8: addiu       $t3, $a1, 0x1
    ctx->r11 = ADD32(ctx->r5, 0X1);
    // 0x801AC3EC: slt         $at, $a0, $t3
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x801AC3F0: bne         $t9, $zero, L_801AC40C
    if (ctx->r25 != 0) {
        // 0x801AC3F4: nop
    
            goto L_801AC40C;
    }
    // 0x801AC3F4: nop

    // 0x801AC3F8: beq         $at, $zero, L_801AC404
    if (ctx->r1 == 0) {
        // 0x801AC3FC: sw          $t3, 0x0($a3)
        MEM_W(0X0, ctx->r7) = ctx->r11;
            goto L_801AC404;
    }
    // 0x801AC3FC: sw          $t3, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r11;
    // 0x801AC400: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
L_801AC404:
    // 0x801AC404: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    // 0x801AC408: sw          $a2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r6;
L_801AC40C:
    // 0x801AC40C: beql        $v1, $a2, L_801AC500
    if (ctx->r3 == ctx->r6) {
        // 0x801AC410: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_801AC500;
    }
    goto skip_2;
    // 0x801AC410: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    skip_2:
    // 0x801AC414: b           L_801AC524
    // 0x801AC418: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801AC524;
    // 0x801AC418: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801AC41C: div.s       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f2.fl, ctx->f18.fl);
L_801AC420:
    // 0x801AC420: lwc1        $f16, 0x24($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X24);
    // 0x801AC424: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801AC428: addiu       $v1, $v1, -0x1150
    ctx->r3 = ADD32(ctx->r3, -0X1150);
    // 0x801AC42C: lui         $at, 0x4110
    ctx->r1 = S32(0X4110 << 16);
    // 0x801AC430: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801AC434: addiu       $v0, $v0, -0x1154
    ctx->r2 = ADD32(ctx->r2, -0X1154);
    // 0x801AC438: div.s       $f6, $f12, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = DIV_S(ctx->f12.fl, ctx->f18.fl);
    // 0x801AC43C: mul.s       $f10, $f16, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x801AC440: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    // 0x801AC444: div.s       $f4, $f14, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f14.fl, ctx->f18.fl);
    // 0x801AC448: mul.s       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x801AC44C: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x801AC450: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    // 0x801AC454: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x801AC458: mul.s       $f10, $f16, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x801AC45C: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801AC460: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x801AC464: swc1        $f4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f4.u32l;
    // 0x801AC468: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x801AC46C: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    // 0x801AC470: lwc1        $f10, 0x20($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X20);
    // 0x801AC474: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x801AC478: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x801AC47C: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x801AC480: swc1        $f8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f8.u32l;
    // 0x801AC484: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x801AC488: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x801AC48C: swc1        $f6, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f6.u32l;
    // 0x801AC490: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x801AC494: lwc1        $f10, 0x4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X4);
    // 0x801AC498: sub.s       $f2, $f8, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x801AC49C: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x801AC4A0: lwc1        $f8, 0x8($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X8);
    // 0x801AC4A4: sub.s       $f12, $f10, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x801AC4A8: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x801AC4AC: sub.s       $f14, $f8, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x801AC4B0: mul.s       $f6, $f12, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x801AC4B4: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x801AC4B8: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x801AC4BC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801AC4C0: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x801AC4C4: div.s       $f6, $f18, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f10.fl);
    // 0x801AC4C8: add.s       $f0, $f8, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x801AC4CC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801AC4D0: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x801AC4D4: mul.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x801AC4D8: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x801AC4DC: nop

    // 0x801AC4E0: bc1fl       L_801AC500
    if (!c1cs) {
        // 0x801AC4E4: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_801AC500;
    }
    goto skip_3;
    // 0x801AC4E4: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    skip_3:
    // 0x801AC4E8: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801AC4EC: addiu       $t7, $t6, -0x10
    ctx->r15 = ADD32(ctx->r14, -0X10);
    // 0x801AC4F0: bgez        $t7, L_801AC4FC
    if (SIGNED(ctx->r15) >= 0) {
        // 0x801AC4F4: sw          $t7, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r15;
            goto L_801AC4FC;
    }
    // 0x801AC4F4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801AC4F8: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
L_801AC4FC:
    // 0x801AC4FC: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
L_801AC500:
    // 0x801AC500: bne         $t2, $at, L_801AC518
    if (ctx->r10 != ctx->r1) {
        // 0x801AC504: nop
    
            goto L_801AC518;
    }
    // 0x801AC504: nop

    // 0x801AC508: jal         0x801AC80C
    // 0x801AC50C: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    Map_PathLine_Draw(rdram, ctx);
        goto after_0;
    // 0x801AC50C: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    after_0:
    // 0x801AC510: b           L_801AC524
    // 0x801AC514: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801AC524;
    // 0x801AC514: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801AC518:
    // 0x801AC518: jal         0x801AC530
    // 0x801AC51C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    Map_Arwing_Draw(rdram, ctx);
        goto after_1;
    // 0x801AC51C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_1:
    // 0x801AC520: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801AC524:
    // 0x801AC524: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x801AC528: jr          $ra
    // 0x801AC52C: nop

    return;
    // 0x801AC52C: nop

;}
RECOMP_FUNC void Option_Sound_SetSoundMode(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80194AEC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80194AF0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80194AF4: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x80194AF8: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x80194AFC: lbu         $t6, 0x7C74($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X7C74);
    // 0x80194B00: lw          $t0, 0x7AF8($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7AF8);
    // 0x80194B04: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x80194B08: addiu       $t1, $t1, -0x6DA0
    ctx->r9 = ADD32(ctx->r9, -0X6DA0);
    // 0x80194B0C: addiu       $t7, $zero, 0x14
    ctx->r15 = ADD32(0, 0X14);
    // 0x80194B10: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x80194B14: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x80194B18: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x80194B1C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80194B20: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80194B24: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x80194B28: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x80194B2C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80194B30: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80194B34: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80194B38: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    // 0x80194B3C: jal         0x8019C418
    // 0x80194B40: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    Option_Input_MoveCursor_Y(rdram, ctx);
        goto after_0;
    // 0x80194B40: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    after_0:
    // 0x80194B44: beq         $v0, $zero, L_80194BC0
    if (ctx->r2 == 0) {
        // 0x80194B48: lui         $a3, 0x800C
        ctx->r7 = S32(0X800C << 16);
            goto L_80194BC0;
    }
    // 0x80194B48: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80194B4C: lui         $t2, 0x800C
    ctx->r10 = S32(0X800C << 16);
    // 0x80194B50: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80194B54: addiu       $t2, $t2, 0x5D3C
    ctx->r10 = ADD32(ctx->r10, 0X5D3C);
    // 0x80194B58: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x80194B5C: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x80194B60: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x80194B64: ori         $a0, $a0, 0x2
    ctx->r4 = ctx->r4 | 0X2;
    // 0x80194B68: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80194B6C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80194B70: jal         0x80019218
    // 0x80194B74: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_1;
    // 0x80194B74: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_1:
    // 0x80194B78: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x80194B7C: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80194B80: addiu       $v1, $v1, 0x7C74
    ctx->r3 = ADD32(ctx->r3, 0X7C74);
    // 0x80194B84: andi        $v0, $t3, 0xFF
    ctx->r2 = ctx->r11 & 0XFF;
    // 0x80194B88: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80194B8C: bne         $at, $zero, L_80194B9C
    if (ctx->r1 != 0) {
        // 0x80194B90: sb          $t3, 0x0($v1)
        MEM_B(0X0, ctx->r3) = ctx->r11;
            goto L_80194B9C;
    }
    // 0x80194B90: sb          $t3, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r11;
    // 0x80194B94: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // 0x80194B98: andi        $v0, $zero, 0xFF
    ctx->r2 = 0 & 0XFF;
L_80194B9C:
    // 0x80194B9C: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x80194BA0: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80194BA4: lbu         $a0, -0x1668($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X1668);
    // 0x80194BA8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80194BAC: sb          $v0, -0x777C($at)
    MEM_B(-0X777C, ctx->r1) = ctx->r2;
    // 0x80194BB0: lui         $at, 0xE000
    ctx->r1 = S32(0XE000 << 16);
    // 0x80194BB4: or          $t4, $a0, $at
    ctx->r12 = ctx->r4 | ctx->r1;
    // 0x80194BB8: jal         0x800182F4
    // 0x80194BBC: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_2;
    // 0x80194BBC: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    after_2:
L_80194BC0:
    // 0x80194BC0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80194BC4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80194BC8: jr          $ra
    // 0x80194BCC: nop

    return;
    // 0x80194BCC: nop

;}
RECOMP_FUNC void Map_Main(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019E8D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8019E8D4: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8019E8D8: addiu       $v1, $v1, -0x2648
    ctx->r3 = ADD32(ctx->r3, -0X2648);
    // 0x8019E8DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8019E8E0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8019E8E4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8019E8E8: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x8019E8EC: blez        $v0, L_8019E8F8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8019E8F0: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_8019E8F8;
    }
    // 0x8019E8F0: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x8019E8F4: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
L_8019E8F8:
    // 0x8019E8F8: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8019E8FC: addiu       $v1, $v1, -0x2644
    ctx->r3 = ADD32(ctx->r3, -0X2644);
    // 0x8019E900: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8019E904: blez        $v0, L_8019E910
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8019E908: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_8019E910;
    }
    // 0x8019E908: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x8019E90C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
L_8019E910:
    // 0x8019E910: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8019E914: addiu       $v1, $v1, -0x2640
    ctx->r3 = ADD32(ctx->r3, -0X2640);
    // 0x8019E918: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8019E91C: blez        $v0, L_8019E928
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8019E920: addiu       $t8, $v0, -0x1
        ctx->r24 = ADD32(ctx->r2, -0X1);
            goto L_8019E928;
    }
    // 0x8019E920: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x8019E924: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
L_8019E928:
    // 0x8019E928: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8019E92C: addiu       $v1, $v1, 0x7B40
    ctx->r3 = ADD32(ctx->r3, 0X7B40);
    // 0x8019E930: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8019E934: beq         $v0, $zero, L_8019E954
    if (ctx->r2 == 0) {
        // 0x8019E938: nop
    
            goto L_8019E954;
    }
    // 0x8019E938: nop

    // 0x8019E93C: beq         $v0, $at, L_8019E96C
    if (ctx->r2 == ctx->r1) {
        // 0x8019E940: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8019E96C;
    }
    // 0x8019E940: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8019E944: beq         $v0, $at, L_8019E980
    if (ctx->r2 == ctx->r1) {
        // 0x8019E948: addiu       $t1, $zero, 0x3
        ctx->r9 = ADD32(0, 0X3);
            goto L_8019E980;
    }
    // 0x8019E948: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x8019E94C: b           L_8019E990
    // 0x8019E950: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8019E990;
    // 0x8019E950: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8019E954:
    // 0x8019E954: lw          $t9, 0x783C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X783C);
    // 0x8019E958: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8019E95C: bnel        $t9, $zero, L_8019E990
    if (ctx->r25 != 0) {
        // 0x8019E960: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8019E990;
    }
    goto skip_0;
    // 0x8019E960: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8019E964: b           L_8019E98C
    // 0x8019E968: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
        goto L_8019E98C;
    // 0x8019E968: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
L_8019E96C:
    // 0x8019E96C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019E970: jal         0x8019E99C
    // 0x8019E974: sw          $zero, 0x7898($at)
    MEM_W(0X7898, ctx->r1) = 0;
    Map_Setup(rdram, ctx);
        goto after_0;
    // 0x8019E974: sw          $zero, 0x7898($at)
    MEM_W(0X7898, ctx->r1) = 0;
    after_0:
    // 0x8019E978: b           L_8019E990
    // 0x8019E97C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8019E990;
    // 0x8019E97C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8019E980:
    // 0x8019E980: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019E984: jal         0x8019FF48
    // 0x8019E988: sw          $t1, 0x7898($at)
    MEM_W(0X7898, ctx->r1) = ctx->r9;
    Map_Update(rdram, ctx);
        goto after_1;
    // 0x8019E988: sw          $t1, 0x7898($at)
    MEM_W(0X7898, ctx->r1) = ctx->r9;
    after_1:
L_8019E98C:
    // 0x8019E98C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8019E990:
    // 0x8019E990: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8019E994: jr          $ra
    // 0x8019E998: nop

    return;
    // 0x8019E998: nop

;}
RECOMP_FUNC void Option_RankingTeamAlive_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80197F74: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80197F78: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x80197F7C: lui         $s6, 0x8013
    ctx->r22 = S32(0X8013 << 16);
    // 0x80197F80: sw          $s7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r23;
    // 0x80197F84: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x80197F88: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80197F8C: or          $s7, $a0, $zero
    ctx->r23 = ctx->r4 | 0;
    // 0x80197F90: addiu       $s6, $s6, 0x7E64
    ctx->r22 = ADD32(ctx->r22, 0X7E64);
    // 0x80197F94: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x80197F98: sw          $fp, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r30;
    // 0x80197F9C: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x80197FA0: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x80197FA4: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x80197FA8: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x80197FAC: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x80197FB0: sdc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X40, ctx->r29);
    // 0x80197FB4: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x80197FB8: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x80197FBC: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x80197FC0: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80197FC4: sw          $a2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r6;
    // 0x80197FC8: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80197FCC: jal         0x800B8DD0
    // 0x80197FD0: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x80197FD0: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    after_0:
    // 0x80197FD4: lw          $a1, 0x78($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X78);
    // 0x80197FD8: lui         $at, 0x4110
    ctx->r1 = S32(0X4110 << 16);
    // 0x80197FDC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80197FE0: mtc1        $a1, $f6
    ctx->f6.u32l = ctx->r5;
    // 0x80197FE4: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x80197FE8: mtc1        $s0, $f4
    ctx->f4.u32l = ctx->r16;
    // 0x80197FEC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80197FF0: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x80197FF4: sll         $t6, $s7, 2
    ctx->r14 = S32(ctx->r23 << 2);
    // 0x80197FF8: subu        $t6, $t6, $s7
    ctx->r14 = SUB32(ctx->r14, ctx->r23);
    // 0x80197FFC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80198000: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x80198004: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80198008: addiu       $t7, $t7, -0x7E58
    ctx->r15 = ADD32(ctx->r15, -0X7E58);
    // 0x8019800C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80198010: lui         $s3, 0x801B
    ctx->r19 = S32(0X801B << 16);
    // 0x80198014: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80198018: lui         $s4, 0x801B
    ctx->r20 = S32(0X801B << 16);
    // 0x8019801C: lui         $s5, 0x801B
    ctx->r21 = S32(0X801B << 16);
    // 0x80198020: lui         $s1, 0x801B
    ctx->r17 = S32(0X801B << 16);
    // 0x80198024: mfc1        $fp, $f18
    ctx->r30 = (int32_t)ctx->f18.u32l;
    // 0x80198028: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x8019802C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80198030: addiu       $s1, $s1, -0xF3C
    ctx->r17 = ADD32(ctx->r17, -0XF3C);
    // 0x80198034: addiu       $s5, $s5, -0xF24
    ctx->r21 = ADD32(ctx->r21, -0XF24);
    // 0x80198038: addiu       $s4, $s4, -0xF30
    ctx->r20 = ADD32(ctx->r20, -0XF30);
    // 0x8019803C: addiu       $s3, $s3, -0xF18
    ctx->r19 = ADD32(ctx->r19, -0XF18);
    // 0x80198040: addu        $s2, $t6, $t7
    ctx->r18 = ADD32(ctx->r14, ctx->r15);
    // 0x80198044: lui         $s7, 0xFA00
    ctx->r23 = S32(0XFA00 << 16);
    // 0x80198048: cvt.s.w     $f26, $f4
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 4);
    ctx->f26.fl = CVT_S_W(ctx->f4.u32l);
L_8019804C:
    // 0x8019804C: lw          $a1, 0x78($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X78);
    // 0x80198050: lw          $s0, 0x0($s6)
    ctx->r16 = MEM_W(ctx->r22, 0X0);
    // 0x80198054: add.s       $f22, $f26, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f22.fl = ctx->f26.fl + ctx->f20.fl;
    // 0x80198058: addiu       $t9, $s0, 0x8
    ctx->r25 = ADD32(ctx->r16, 0X8);
    // 0x8019805C: sw          $t9, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r25;
    // 0x80198060: sw          $s7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r23;
    // 0x80198064: lw          $t0, 0x0($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X0);
    // 0x80198068: lw          $t7, 0x0($s5)
    ctx->r15 = MEM_W(ctx->r21, 0X0);
    // 0x8019806C: lw          $t4, 0x0($s4)
    ctx->r12 = MEM_W(ctx->r20, 0X0);
    // 0x80198070: andi        $t1, $t0, 0xFF
    ctx->r9 = ctx->r8 & 0XFF;
    // 0x80198074: sll         $t2, $t1, 8
    ctx->r10 = S32(ctx->r9 << 8);
    // 0x80198078: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x8019807C: sll         $t5, $t4, 24
    ctx->r13 = S32(ctx->r12 << 24);
    // 0x80198080: or          $t6, $t2, $t5
    ctx->r14 = ctx->r10 | ctx->r13;
    // 0x80198084: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x80198088: or          $t0, $t6, $t9
    ctx->r8 = ctx->r14 | ctx->r25;
    // 0x8019808C: ori         $t1, $t0, 0xFF
    ctx->r9 = ctx->r8 | 0XFF;
    // 0x80198090: sw          $t1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r9;
    // 0x80198094: trunc.w.s   $f4, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    ctx->f4.u32l = TRUNC_W_S(ctx->f22.fl);
    // 0x80198098: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x8019809C: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x801980A0: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x801980A4: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    // 0x801980A8: jal         0x800A1200
    // 0x801980AC: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    Graphics_DisplaySmallText(rdram, ctx);
        goto after_1;
    // 0x801980AC: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_1:
    // 0x801980B0: lw          $s0, 0x0($s6)
    ctx->r16 = MEM_W(ctx->r22, 0X0);
    // 0x801980B4: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x801980B8: addiu       $t2, $s0, 0x8
    ctx->r10 = ADD32(ctx->r16, 0X8);
    // 0x801980BC: sw          $t2, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r10;
    // 0x801980C0: sw          $t5, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r13;
    // 0x801980C4: sw          $s7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r23;
    // 0x801980C8: jal         0x8008BCBC
    // 0x801980CC: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    HUD_CountDigits(rdram, ctx);
        goto after_2;
    // 0x801980CC: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_2:
    // 0x801980D0: sll         $t7, $v0, 3
    ctx->r15 = S32(ctx->r2 << 3);
    // 0x801980D4: addiu       $t8, $t7, -0x8
    ctx->r24 = ADD32(ctx->r15, -0X8);
    // 0x801980D8: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x801980DC: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    // 0x801980E0: lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X0);
    // 0x801980E4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801980E8: sub.s       $f10, $f22, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f22.fl - ctx->f8.fl;
    // 0x801980EC: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x801980F0: mfc1        $a0, $f16
    ctx->r4 = (int32_t)ctx->f16.u32l;
    // 0x801980F4: jal         0x8009FEA0
    // 0x801980F8: nop

    Graphics_DisplaySmallNumber(rdram, ctx);
        goto after_3;
    // 0x801980F8: nop

    after_3:
    // 0x801980FC: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x80198100: addiu       $t9, $t9, -0xF30
    ctx->r25 = ADD32(ctx->r25, -0XF30);
    // 0x80198104: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80198108: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x8019810C: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x80198110: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
    // 0x80198114: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80198118: bne         $s1, $t9, L_8019804C
    if (ctx->r17 != ctx->r25) {
        // 0x8019811C: add.s       $f20, $f20, $f28
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f28.fl;
            goto L_8019804C;
    }
    // 0x8019811C: add.s       $f20, $f20, $f28
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f28.fl;
    // 0x80198120: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x80198124: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80198128: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x8019812C: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x80198130: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x80198134: ldc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X40);
    // 0x80198138: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x8019813C: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x80198140: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x80198144: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x80198148: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x8019814C: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x80198150: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x80198154: lw          $s7, 0x64($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X64);
    // 0x80198158: lw          $fp, 0x68($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X68);
    // 0x8019815C: jr          $ra
    // 0x80198160: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x80198160: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void Title_Cutscene_SetCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018CC30: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8018CC34: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x8018CC38: addiu       $t0, $t0, -0x7D68
    ctx->r8 = ADD32(ctx->r8, -0X7D68);
    // 0x8018CC3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018CC40: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8018CC44: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8018CC48: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x8018CC4C: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x8018CC50: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8018CC54: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8018CC58: beq         $v1, $at, L_8018CD8C
    if (ctx->r3 == ctx->r1) {
        // 0x8018CC5C: addiu       $v0, $v0, -0x7D74
        ctx->r2 = ADD32(ctx->r2, -0X7D74);
            goto L_8018CD8C;
    }
    // 0x8018CC5C: addiu       $v0, $v0, -0x7D74
    ctx->r2 = ADD32(ctx->r2, -0X7D74);
    // 0x8018CC60: bne         $v1, $zero, L_8018CC70
    if (ctx->r3 != 0) {
        // 0x8018CC64: addiu       $a0, $sp, 0x1C
        ctx->r4 = ADD32(ctx->r29, 0X1C);
            goto L_8018CC70;
    }
    // 0x8018CC64: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x8018CC68: b           L_8018CCC0
    // 0x8018CC6C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
        goto L_8018CCC0;
    // 0x8018CC6C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_8018CC70:
    // 0x8018CC70: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8018CC74: bne         $v1, $at, L_8018CC98
    if (ctx->r3 != ctx->r1) {
        // 0x8018CC78: lw          $t7, 0x3C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X3C);
            goto L_8018CC98;
    }
    // 0x8018CC78: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x8018CC7C: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x8018CC80: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8018CC84: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8018CC88: bnel        $t6, $at, L_8018CCC4
    if (ctx->r14 != ctx->r1) {
        // 0x8018CC8C: sll         $t2, $v1, 2
        ctx->r10 = S32(ctx->r3 << 2);
            goto L_8018CCC4;
    }
    goto skip_0;
    // 0x8018CC8C: sll         $t2, $v1, 2
    ctx->r10 = S32(ctx->r3 << 2);
    skip_0:
    // 0x8018CC90: b           L_8018CCC0
    // 0x8018CC94: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
        goto L_8018CCC0;
    // 0x8018CC94: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
L_8018CC98:
    // 0x8018CC98: addiu       $t8, $v1, 0x5
    ctx->r24 = ADD32(ctx->r3, 0X5);
    // 0x8018CC9C: bne         $t7, $t8, L_8018CCAC
    if (ctx->r15 != ctx->r24) {
        // 0x8018CCA0: lw          $t9, 0x3C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X3C);
            goto L_8018CCAC;
    }
    // 0x8018CCA0: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x8018CCA4: b           L_8018CCC0
    // 0x8018CCA8: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
        goto L_8018CCC0;
    // 0x8018CCA8: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
L_8018CCAC:
    // 0x8018CCAC: addiu       $t1, $v1, 0x4
    ctx->r9 = ADD32(ctx->r3, 0X4);
    // 0x8018CCB0: bne         $t9, $t1, L_8018CCC0
    if (ctx->r25 != ctx->r9) {
        // 0x8018CCB4: addiu       $a3, $zero, 0x2
        ctx->r7 = ADD32(0, 0X2);
            goto L_8018CCC0;
    }
    // 0x8018CCB4: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x8018CCB8: b           L_8018CCC0
    // 0x8018CCBC: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
        goto L_8018CCC0;
    // 0x8018CCBC: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
L_8018CCC0:
    // 0x8018CCC0: sll         $t2, $v1, 2
    ctx->r10 = S32(ctx->r3 << 2);
L_8018CCC4:
    // 0x8018CCC4: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x8018CCC8: subu        $t2, $t2, $v1
    ctx->r10 = SUB32(ctx->r10, ctx->r3);
    // 0x8018CCCC: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x8018CCD0: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x8018CCD4: jal         0x8018CD9C
    // 0x8018CCD8: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    Title_Camera_Calc(rdram, ctx);
        goto after_0;
    // 0x8018CCD8: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    after_0:
    // 0x8018CCDC: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8018CCE0: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8018CCE4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018CCE8: swc1        $f4, 0x7978($at)
    MEM_W(0X7978, ctx->r1) = ctx->f4.u32l;
    // 0x8018CCEC: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8018CCF0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018CCF4: swc1        $f6, 0x7980($at)
    MEM_W(0X7980, ctx->r1) = ctx->f6.u32l;
    // 0x8018CCF8: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8018CCFC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018CD00: swc1        $f8, 0x7988($at)
    MEM_W(0X7988, ctx->r1) = ctx->f8.u32l;
    // 0x8018CD04: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8018CD08: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018CD0C: swc1        $f10, 0x79A0($at)
    MEM_W(0X79A0, ctx->r1) = ctx->f10.u32l;
    // 0x8018CD10: lwc1        $f18, 0x30($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8018CD14: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018CD18: swc1        $f16, 0x79B8($at)
    MEM_W(0X79B8, ctx->r1) = ctx->f16.u32l;
    // 0x8018CD1C: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8018CD20: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018CD24: addiu       $v0, $v0, -0x7D74
    ctx->r2 = ADD32(ctx->r2, -0X7D74);
    // 0x8018CD28: swc1        $f18, 0x79C0($at)
    MEM_W(0X79C0, ctx->r1) = ctx->f18.u32l;
    // 0x8018CD2C: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8018CD30: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8018CD34: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8018CD38: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018CD3C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8018CD40: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x8018CD44: addiu       $t0, $t0, -0x7D68
    ctx->r8 = ADD32(ctx->r8, -0X7D68);
    // 0x8018CD48: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x8018CD4C: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8018CD50: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x8018CD54: nop

    // 0x8018CD58: bc1fl       L_8018CD90
    if (!c1cs) {
        // 0x8018CD5C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8018CD90;
    }
    goto skip_1;
    // 0x8018CD5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8018CD60: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x8018CD64: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x8018CD68: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8018CD6C: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8018CD70: addiu       $t8, $t7, -0x4
    ctx->r24 = ADD32(ctx->r15, -0X4);
    // 0x8018CD74: slt         $at, $t8, $t5
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8018CD78: sw          $t5, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r13;
    // 0x8018CD7C: beq         $at, $zero, L_8018CD8C
    if (ctx->r1 == 0) {
        // 0x8018CD80: swc1        $f18, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->f18.u32l;
            goto L_8018CD8C;
    }
    // 0x8018CD80: swc1        $f18, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f18.u32l;
    // 0x8018CD84: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x8018CD88: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
L_8018CD8C:
    // 0x8018CD8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8018CD90:
    // 0x8018CD90: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8018CD94: jr          $ra
    // 0x8018CD98: nop

    return;
    // 0x8018CD98: nop

;}
RECOMP_FUNC void Option_VersusMenu_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80199424: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80199428: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8019942C: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80199430: lw          $v0, -0x6ED4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6ED4);
    // 0x80199434: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80199438: beq         $v0, $zero, L_80199450
    if (ctx->r2 == 0) {
        // 0x8019943C: nop
    
            goto L_80199450;
    }
    // 0x8019943C: nop

    // 0x80199440: beq         $v0, $at, L_80199460
    if (ctx->r2 == ctx->r1) {
        // 0x80199444: nop
    
            goto L_80199460;
    }
    // 0x80199444: nop

    // 0x80199448: b           L_80199490
    // 0x8019944C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80199490;
    // 0x8019944C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80199450:
    // 0x80199450: jal         0x8019949C
    // 0x80199454: nop

    Option_VersusMenu_Cursor(rdram, ctx);
        goto after_0;
    // 0x80199454: nop

    after_0:
    // 0x80199458: b           L_80199490
    // 0x8019945C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80199490;
    // 0x8019945C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80199460:
    // 0x80199460: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80199464: lwc1        $f6, -0x6E14($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X6E14);
    // 0x80199468: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8019946C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80199470: addiu       $t6, $zero, 0x7D0
    ctx->r14 = ADD32(0, 0X7D0);
    // 0x80199474: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x80199478: nop

    // 0x8019947C: bc1fl       L_80199490
    if (!c1cs) {
        // 0x80199480: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80199490;
    }
    goto skip_0;
    // 0x80199480: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80199484: jal         0x801924C4
    // 0x80199488: sw          $t6, -0x6EDC($at)
    MEM_W(-0X6EDC, ctx->r1) = ctx->r14;
    Option_Entry_Setup(rdram, ctx);
        goto after_1;
    // 0x80199488: sw          $t6, -0x6EDC($at)
    MEM_W(-0X6EDC, ctx->r1) = ctx->r14;
    after_1:
    // 0x8019948C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80199490:
    // 0x80199490: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80199494: jr          $ra
    // 0x80199498: nop

    return;
    // 0x80199498: nop

;}
RECOMP_FUNC void Title_Screen_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801888E8: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x801888EC: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x801888F0: sw          $fp, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r30;
    // 0x801888F4: sw          $s7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r23;
    // 0x801888F8: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x801888FC: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x80188900: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x80188904: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x80188908: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x8018890C: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x80188910: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x80188914: sdc1        $f24, 0x40($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X40, ctx->r29);
    // 0x80188918: sdc1        $f22, 0x38($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X38, ctx->r29);
    // 0x8018891C: sdc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X30, ctx->r29);
    // 0x80188920: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80188924: lw          $v0, -0x7D40($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D40);
    // 0x80188928: sltiu       $at, $v0, 0x5
    ctx->r1 = ctx->r2 < 0X5 ? 1 : 0;
    // 0x8018892C: beq         $at, $zero, L_80188C90
    if (ctx->r1 == 0) {
        // 0x80188930: sll         $t6, $v0, 2
        ctx->r14 = S32(ctx->r2 << 2);
            goto L_80188C90;
    }
    // 0x80188930: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80188934: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80188938: addu        $at, $at, $t6
    gpr jr_addend_80188940 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8018893C: lw          $t6, 0x6E10($at)
    ctx->r14 = ADD32(ctx->r1, 0X6E10);
    // 0x80188940: jr          $t6
    // 0x80188944: nop

    switch (jr_addend_80188940 >> 2) {
        case 0: goto L_80188948; break;
        case 1: goto L_8018899C; break;
        case 2: goto L_80188A88; break;
        case 3: goto L_80188AA4; break;
        case 4: goto L_80188BE4; break;
        default: switch_error(__func__, 0x80188940, 0x801B6E10);
    }
    // 0x80188944: nop

L_80188948:
    // 0x80188948: jal         0x801881FC
    // 0x8018894C: nop

    Title_Screen_Setup(rdram, ctx);
        goto after_0;
    // 0x8018894C: nop

    after_0:
    // 0x80188950: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80188954: lwc1        $f4, 0x6E24($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6E24);
    // 0x80188958: lui         $s2, 0x801C
    ctx->r18 = S32(0X801C << 16);
    // 0x8018895C: addiu       $s2, $s2, -0x7D34
    ctx->r18 = ADD32(ctx->r18, -0X7D34);
    // 0x80188960: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80188964: swc1        $f4, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f4.u32l;
    // 0x80188968: lwc1        $f6, 0x6E28($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6E28);
    // 0x8018896C: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x80188970: lui         $s1, 0x801C
    ctx->r17 = S32(0X801C << 16);
    // 0x80188974: addiu       $s1, $s1, -0x7D30
    ctx->r17 = ADD32(ctx->r17, -0X7D30);
    // 0x80188978: addiu       $s0, $s0, -0x7CC0
    ctx->r16 = ADD32(ctx->r16, -0X7CC0);
    // 0x8018897C: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x80188980: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x80188984: swc1        $f6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f6.u32l;
    // 0x80188988: lw          $t7, -0x7D40($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7D40);
    // 0x8018898C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80188990: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80188994: b           L_80188C90
    // 0x80188998: sw          $t8, -0x7D40($at)
    MEM_W(-0X7D40, ctx->r1) = ctx->r24;
        goto L_80188C90;
    // 0x80188998: sw          $t8, -0x7D40($at)
    MEM_W(-0X7D40, ctx->r1) = ctx->r24;
L_8018899C:
    // 0x8018899C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801889A0: lwc1        $f20, 0x6E2C($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X6E2C);
    // 0x801889A4: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x801889A8: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x801889AC: lui         $s2, 0x801C
    ctx->r18 = S32(0X801C << 16);
    // 0x801889B0: addiu       $s2, $s2, -0x7D34
    ctx->r18 = ADD32(ctx->r18, -0X7D34);
    // 0x801889B4: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801889B8: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x801889BC: addiu       $a0, $a0, -0x7938
    ctx->r4 = ADD32(ctx->r4, -0X7938);
    // 0x801889C0: lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X0);
    // 0x801889C4: lui         $a1, 0xC120
    ctx->r5 = S32(0XC120 << 16);
    // 0x801889C8: jal         0x8009BC2C
    // 0x801889CC: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_1;
    // 0x801889CC: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_1:
    // 0x801889D0: lui         $s5, 0x801C
    ctx->r21 = S32(0X801C << 16);
    // 0x801889D4: addiu       $s5, $s5, -0x7934
    ctx->r21 = ADD32(ctx->r21, -0X7934);
    // 0x801889D8: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x801889DC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x801889E0: lui         $a1, 0x4264
    ctx->r5 = S32(0X4264 << 16);
    // 0x801889E4: lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X0);
    // 0x801889E8: jal         0x8009BC2C
    // 0x801889EC: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_2;
    // 0x801889EC: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_2:
    // 0x801889F0: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801889F4: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x801889F8: addiu       $a0, $a0, -0x7CFC
    ctx->r4 = ADD32(ctx->r4, -0X7CFC);
    // 0x801889FC: lui         $a1, 0x4150
    ctx->r5 = S32(0X4150 << 16);
    // 0x80188A00: lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X0);
    // 0x80188A04: jal         0x8009BC2C
    // 0x80188A08: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_3;
    // 0x80188A08: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_3:
    // 0x80188A0C: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80188A10: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80188A14: addiu       $a0, $a0, -0x7CF8
    ctx->r4 = ADD32(ctx->r4, -0X7CF8);
    // 0x80188A18: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    // 0x80188A1C: lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X0);
    // 0x80188A20: jal         0x8009BC2C
    // 0x80188A24: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_4;
    // 0x80188A24: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_4:
    // 0x80188A28: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80188A2C: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80188A30: addiu       $a0, $a0, -0x7CF4
    ctx->r4 = ADD32(ctx->r4, -0X7CF4);
    // 0x80188A34: lui         $a1, 0x4170
    ctx->r5 = S32(0X4170 << 16);
    // 0x80188A38: lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X0);
    // 0x80188A3C: jal         0x8009BC2C
    // 0x80188A40: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_5;
    // 0x80188A40: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_5:
    // 0x80188A44: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80188A48: lwc1        $f10, 0x6E30($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6E30);
    // 0x80188A4C: lwc1        $f8, 0x0($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X0);
    // 0x80188A50: lui         $at, 0x4264
    ctx->r1 = S32(0X4264 << 16);
    // 0x80188A54: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80188A58: lwc1        $f4, 0x0($s5)
    ctx->f4.u32l = MEM_W(ctx->r21, 0X0);
    // 0x80188A5C: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80188A60: c.eq.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl == ctx->f4.fl;
    // 0x80188A64: nop

    // 0x80188A68: bc1f        L_80188C90
    if (!c1cs) {
        // 0x80188A6C: swc1        $f16, 0x0($s2)
        MEM_W(0X0, ctx->r18) = ctx->f16.u32l;
            goto L_80188C90;
    }
    // 0x80188A6C: swc1        $f16, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f16.u32l;
    // 0x80188A70: lui         $t9, 0x801C
    ctx->r25 = S32(0X801C << 16);
    // 0x80188A74: lw          $t9, -0x7D40($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7D40);
    // 0x80188A78: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80188A7C: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80188A80: b           L_80188C90
    // 0x80188A84: sw          $t0, -0x7D40($at)
    MEM_W(-0X7D40, ctx->r1) = ctx->r8;
        goto L_80188C90;
    // 0x80188A84: sw          $t0, -0x7D40($at)
    MEM_W(-0X7D40, ctx->r1) = ctx->r8;
L_80188A88:
    // 0x80188A88: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x80188A8C: lw          $t1, -0x7D50($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X7D50);
    // 0x80188A90: bne         $t1, $zero, L_80188C90
    if (ctx->r9 != 0) {
        // 0x80188A94: addiu       $t2, $v0, 0x1
        ctx->r10 = ADD32(ctx->r2, 0X1);
            goto L_80188C90;
    }
    // 0x80188A94: addiu       $t2, $v0, 0x1
    ctx->r10 = ADD32(ctx->r2, 0X1);
    // 0x80188A98: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80188A9C: b           L_80188C90
    // 0x80188AA0: sw          $t2, -0x7D40($at)
    MEM_W(-0X7D40, ctx->r1) = ctx->r10;
        goto L_80188C90;
    // 0x80188AA0: sw          $t2, -0x7D40($at)
    MEM_W(-0X7D40, ctx->r1) = ctx->r10;
L_80188AA4:
    // 0x80188AA4: jal         0x80004EB0
    // 0x80188AA8: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_6;
    // 0x80188AA8: nop

    after_6:
    // 0x80188AAC: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80188AB0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80188AB4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80188AB8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80188ABC: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80188AC0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80188AC4: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x80188AC8: addiu       $s0, $s0, -0x7CC0
    ctx->r16 = ADD32(ctx->r16, -0X7CC0);
    // 0x80188ACC: addiu       $s4, $zero, 0x60
    ctx->r20 = ADD32(0, 0X60);
    // 0x80188AD0: lui         $s3, 0x801C
    ctx->r19 = S32(0X801C << 16);
    // 0x80188AD4: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x80188AD8: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80188ADC: addiu       $s3, $s3, -0x7CB0
    ctx->r19 = ADD32(ctx->r19, -0X7CB0);
    // 0x80188AE0: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80188AE4: mfc1        $t4, $f18
    ctx->r12 = (int32_t)ctx->f18.u32l;
    // 0x80188AE8: nop

    // 0x80188AEC: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80188AF0: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x80188AF4: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x80188AF8: sw          $t5, -0x7D58($at)
    MEM_W(-0X7D58, ctx->r1) = ctx->r13;
    // 0x80188AFC: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80188B00: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80188B04: multu       $v1, $s4
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80188B08: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x80188B0C: nop

    // 0x80188B10: cvt.s.w     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80188B14: mflo        $t6
    ctx->r14 = lo;
    // 0x80188B18: addu        $v0, $s3, $t6
    ctx->r2 = ADD32(ctx->r19, ctx->r14);
    // 0x80188B1C: mov.s       $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    ctx->f20.fl = ctx->f2.fl;
    // 0x80188B20: sw          $zero, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = 0;
    // 0x80188B24: bne         $v1, $at, L_80188B30
    if (ctx->r3 != ctx->r1) {
        // 0x80188B28: swc1        $f24, 0x18($v0)
        MEM_W(0X18, ctx->r2) = ctx->f24.u32l;
            goto L_80188B30;
    }
    // 0x80188B28: swc1        $f24, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f24.u32l;
    // 0x80188B2C: sw          $zero, 0x58($v0)
    MEM_W(0X58, ctx->r2) = 0;
L_80188B30:
    // 0x80188B30: c.eq.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl == ctx->f2.fl;
    // 0x80188B34: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80188B38: bc1f        L_80188B7C
    if (!c1cs) {
        // 0x80188B3C: nop
    
            goto L_80188B7C;
    }
    // 0x80188B3C: nop

    // 0x80188B40: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80188B44: nop

L_80188B48:
    // 0x80188B48: jal         0x80004EB0
    // 0x80188B4C: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_7;
    // 0x80188B4C: nop

    after_7:
    // 0x80188B50: mul.s       $f6, $f0, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x80188B54: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80188B58: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x80188B5C: nop

    // 0x80188B60: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x80188B64: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80188B68: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80188B6C: c.eq.s      $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f20.fl == ctx->f16.fl;
    // 0x80188B70: nop

    // 0x80188B74: bc1t        L_80188B48
    if (c1cs) {
        // 0x80188B78: nop
    
            goto L_80188B48;
    }
    // 0x80188B78: nop

L_80188B7C:
    // 0x80188B7C: jal         0x80004EB0
    // 0x80188B80: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_8;
    // 0x80188B80: nop

    after_8:
    // 0x80188B84: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80188B88: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80188B8C: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80188B90: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80188B94: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80188B98: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80188B9C: multu       $t0, $s4
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80188BA0: lui         $s2, 0x801C
    ctx->r18 = S32(0X801C << 16);
    // 0x80188BA4: addiu       $s2, $s2, -0x7D34
    ctx->r18 = ADD32(ctx->r18, -0X7D34);
    // 0x80188BA8: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x80188BAC: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80188BB0: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    // 0x80188BB4: mflo        $t1
    ctx->r9 = lo;
    // 0x80188BB8: addu        $v0, $s3, $t1
    ctx->r2 = ADD32(ctx->r19, ctx->r9);
    // 0x80188BBC: addiu       $t4, $t3, 0x5
    ctx->r12 = ADD32(ctx->r11, 0X5);
    // 0x80188BC0: sw          $t4, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->r12;
    // 0x80188BC4: sw          $t5, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->r13;
    // 0x80188BC8: lwc1        $f8, 0x6E34($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6E34);
    // 0x80188BCC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80188BD0: swc1        $f8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f8.u32l;
    // 0x80188BD4: lw          $t6, -0x7D40($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7D40);
    // 0x80188BD8: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80188BDC: b           L_80188C90
    // 0x80188BE0: sw          $t7, -0x7D40($at)
    MEM_W(-0X7D40, ctx->r1) = ctx->r15;
        goto L_80188C90;
    // 0x80188BE0: sw          $t7, -0x7D40($at)
    MEM_W(-0X7D40, ctx->r1) = ctx->r15;
L_80188BE4:
    // 0x80188BE4: lui         $t8, 0x801C
    ctx->r24 = S32(0X801C << 16);
    // 0x80188BE8: lw          $t8, -0x7D58($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7D58);
    // 0x80188BEC: bne         $t8, $zero, L_80188C90
    if (ctx->r24 != 0) {
        // 0x80188BF0: lui         $s0, 0x801C
        ctx->r16 = S32(0X801C << 16);
            goto L_80188C90;
    }
    // 0x80188BF0: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x80188BF4: addiu       $s0, $s0, -0x7CC0
    ctx->r16 = ADD32(ctx->r16, -0X7CC0);
    // 0x80188BF8: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80188BFC: addiu       $s4, $zero, 0x60
    ctx->r20 = ADD32(0, 0X60);
    // 0x80188C00: lui         $s3, 0x801C
    ctx->r19 = S32(0X801C << 16);
    // 0x80188C04: multu       $t9, $s4
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80188C08: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80188C0C: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80188C10: addiu       $s3, $s3, -0x7CB0
    ctx->r19 = ADD32(ctx->r19, -0X7CB0);
    // 0x80188C14: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x80188C18: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80188C1C: lui         $s2, 0x801C
    ctx->r18 = S32(0X801C << 16);
    // 0x80188C20: addiu       $s2, $s2, -0x7D34
    ctx->r18 = ADD32(ctx->r18, -0X7D34);
    // 0x80188C24: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80188C28: mfc1        $a1, $f24
    ctx->r5 = (int32_t)ctx->f24.u32l;
    // 0x80188C2C: mflo        $t0
    ctx->r8 = lo;
    // 0x80188C30: addu        $v0, $s3, $t0
    ctx->r2 = ADD32(ctx->r19, ctx->r8);
    // 0x80188C34: sw          $zero, 0x54($v0)
    MEM_W(0X54, ctx->r2) = 0;
    // 0x80188C38: lwc1        $f10, 0x6E38($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6E38);
    // 0x80188C3C: addiu       $a0, $v0, 0x18
    ctx->r4 = ADD32(ctx->r2, 0X18);
    // 0x80188C40: lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X0);
    // 0x80188C44: jal         0x8009BC2C
    // 0x80188C48: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_9;
    // 0x80188C48: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_9:
    // 0x80188C4C: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x80188C50: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80188C54: lwc1        $f18, 0x6E3C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6E3C);
    // 0x80188C58: multu       $t1, $s4
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80188C5C: lwc1        $f16, 0x0($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X0);
    // 0x80188C60: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80188C64: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x80188C68: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80188C6C: mflo        $t2
    ctx->r10 = lo;
    // 0x80188C70: addu        $t3, $s3, $t2
    ctx->r11 = ADD32(ctx->r19, ctx->r10);
    // 0x80188C74: lwc1        $f6, 0x18($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X18);
    // 0x80188C78: swc1        $f4, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f4.u32l;
    // 0x80188C7C: c.eq.s      $f24, $f6
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f24.fl == ctx->f6.fl;
    // 0x80188C80: nop

    // 0x80188C84: bc1f        L_80188C90
    if (!c1cs) {
        // 0x80188C88: nop
    
            goto L_80188C90;
    }
    // 0x80188C88: nop

    // 0x80188C8C: sw          $t4, -0x7D40($at)
    MEM_W(-0X7D40, ctx->r1) = ctx->r12;
L_80188C90:
    // 0x80188C90: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x80188C94: addiu       $s0, $s0, -0x7CC0
    ctx->r16 = ADD32(ctx->r16, -0X7CC0);
    // 0x80188C98: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80188C9C: addiu       $s4, $zero, 0x60
    ctx->r20 = ADD32(0, 0X60);
    // 0x80188CA0: lui         $s3, 0x801C
    ctx->r19 = S32(0X801C << 16);
    // 0x80188CA4: multu       $v1, $s4
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80188CA8: addiu       $s3, $s3, -0x7CB0
    ctx->r19 = ADD32(ctx->r19, -0X7CB0);
    // 0x80188CAC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80188CB0: lwc1        $f20, 0x6E40($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X6E40);
    // 0x80188CB4: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80188CB8: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80188CBC: lui         $s1, 0x801C
    ctx->r17 = S32(0X801C << 16);
    // 0x80188CC0: lui         $s5, 0x801C
    ctx->r21 = S32(0X801C << 16);
    // 0x80188CC4: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x80188CC8: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80188CCC: mflo        $t5
    ctx->r13 = lo;
    // 0x80188CD0: addu        $v0, $s3, $t5
    ctx->r2 = ADD32(ctx->r19, ctx->r13);
    // 0x80188CD4: lw          $t6, 0x54($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X54);
    // 0x80188CD8: addiu       $s5, $s5, -0x7934
    ctx->r21 = ADD32(ctx->r21, -0X7934);
    // 0x80188CDC: addiu       $s1, $s1, -0x7D30
    ctx->r17 = ADD32(ctx->r17, -0X7D30);
    // 0x80188CE0: beq         $t6, $zero, L_80188D68
    if (ctx->r14 == 0) {
        // 0x80188CE4: lw          $a0, -0x7D50($a0)
        ctx->r4 = MEM_W(ctx->r4, -0X7D50);
            goto L_80188D68;
    }
    // 0x80188CE4: lw          $a0, -0x7D50($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7D50);
    // 0x80188CE8: lwc1        $f8, 0x1C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80188CEC: lwc1        $f10, 0x18($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80188CF0: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x80188CF4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80188CF8: add.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80188CFC: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80188D00: sll         $a1, $v1, 2
    ctx->r5 = S32(ctx->r3 << 2);
    // 0x80188D04: c.lt.s      $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f0.fl < ctx->f24.fl;
    // 0x80188D08: nop

    // 0x80188D0C: bc1f        L_80188D28
    if (!c1cs) {
        // 0x80188D10: nop
    
            goto L_80188D28;
    }
    // 0x80188D10: nop

    // 0x80188D14: lwc1        $f16, -0x258C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X258C);
    // 0x80188D18: lwc1        $f4, 0x18($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80188D1C: swc1        $f16, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f16.u32l;
    // 0x80188D20: lwc1        $f18, 0x1C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80188D24: add.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f18.fl + ctx->f4.fl;
L_80188D28:
    // 0x80188D28: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80188D2C: addu        $at, $at, $a1
    ctx->r1 = ADD32(ctx->r1, ctx->r5);
    // 0x80188D30: lwc1        $f6, -0x259C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X259C);
    // 0x80188D34: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80188D38: addu        $at, $at, $a1
    ctx->r1 = ADD32(ctx->r1, ctx->r5);
    // 0x80188D3C: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80188D40: nop

    // 0x80188D44: bc1fl       L_80188D68
    if (!c1cs) {
        // 0x80188D48: swc1        $f0, 0x18($v0)
        MEM_W(0X18, ctx->r2) = ctx->f0.u32l;
            goto L_80188D68;
    }
    goto skip_0;
    // 0x80188D48: swc1        $f0, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f0.u32l;
    skip_0:
    // 0x80188D4C: lwc1        $f8, -0x258C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X258C);
    // 0x80188D50: lwc1        $f18, 0x18($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80188D54: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x80188D58: swc1        $f10, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f10.u32l;
    // 0x80188D5C: lwc1        $f16, 0x1C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80188D60: add.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80188D64: swc1        $f0, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f0.u32l;
L_80188D68:
    // 0x80188D68: bne         $a0, $zero, L_80188E10
    if (ctx->r4 != 0) {
        // 0x80188D6C: lui         $t8, 0x8017
        ctx->r24 = S32(0X8017 << 16);
            goto L_80188E10;
    }
    // 0x80188D6C: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x80188D70: lw          $t8, 0x7DB0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7DB0);
    // 0x80188D74: andi        $t9, $t8, 0x80
    ctx->r25 = ctx->r24 & 0X80;
    // 0x80188D78: beq         $t9, $zero, L_80188DE8
    if (ctx->r25 == 0) {
        // 0x80188D7C: nop
    
            goto L_80188DE8;
    }
    // 0x80188D7C: nop

    // 0x80188D80: lwc1        $f4, 0x84($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X84);
    // 0x80188D84: lwc1        $f6, 0x80($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X80);
    // 0x80188D88: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    // 0x80188D8C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80188D90: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80188D94: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80188D98: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80188D9C: nop

    // 0x80188DA0: bc1fl       L_80188DC0
    if (!c1cs) {
        // 0x80188DA4: c.lt.s      $f24, $f0
        CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f24.fl < ctx->f0.fl;
            goto L_80188DC0;
    }
    goto skip_1;
    // 0x80188DA4: c.lt.s      $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f24.fl < ctx->f0.fl;
    skip_1:
    // 0x80188DA8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80188DAC: lwc1        $f18, 0x80($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0X80);
    // 0x80188DB0: swc1        $f10, 0x84($s3)
    MEM_W(0X84, ctx->r19) = ctx->f10.u32l;
    // 0x80188DB4: lwc1        $f16, 0x84($s3)
    ctx->f16.u32l = MEM_W(ctx->r19, 0X84);
    // 0x80188DB8: add.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80188DBC: c.lt.s      $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f24.fl < ctx->f0.fl;
L_80188DC0:
    // 0x80188DC0: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x80188DC4: bc1f        L_80188DE0
    if (!c1cs) {
        // 0x80188DC8: nop
    
            goto L_80188DE0;
    }
    // 0x80188DC8: nop

    // 0x80188DCC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80188DD0: lwc1        $f8, 0x80($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X80);
    // 0x80188DD4: swc1        $f4, 0x84($s3)
    MEM_W(0X84, ctx->r19) = ctx->f4.u32l;
    // 0x80188DD8: lwc1        $f6, 0x84($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X84);
    // 0x80188DDC: add.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f8.fl;
L_80188DE0:
    // 0x80188DE0: b           L_80188E10
    // 0x80188DE4: swc1        $f0, 0x80($s3)
    MEM_W(0X80, ctx->r19) = ctx->f0.u32l;
        goto L_80188E10;
    // 0x80188DE4: swc1        $f0, 0x80($s3)
    MEM_W(0X80, ctx->r19) = ctx->f0.u32l;
L_80188DE8:
    // 0x80188DE8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80188DEC: lwc1        $f10, 0x6E44($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6E44);
    // 0x80188DF0: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80188DF4: mfc1        $a1, $f24
    ctx->r5 = (int32_t)ctx->f24.u32l;
    // 0x80188DF8: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x80188DFC: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80188E00: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80188E04: addiu       $a0, $a0, -0x7C30
    ctx->r4 = ADD32(ctx->r4, -0X7C30);
    // 0x80188E08: jal         0x8009BC2C
    // 0x80188E0C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_10;
    // 0x80188E0C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_10:
L_80188E10:
    // 0x80188E10: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x80188E14: lw          $t0, -0x795C($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X795C);
    // 0x80188E18: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x80188E1C: slti        $at, $t0, 0x3
    ctx->r1 = SIGNED(ctx->r8) < 0X3 ? 1 : 0;
    // 0x80188E20: bne         $at, $zero, L_80189084
    if (ctx->r1 != 0) {
        // 0x80188E24: nop
    
            goto L_80189084;
    }
    // 0x80188E24: nop

    // 0x80188E28: lw          $t1, -0x6FC0($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X6FC0);
    // 0x80188E2C: beq         $t1, $zero, L_80189084
    if (ctx->r9 == 0) {
        // 0x80188E30: lui         $a0, 0x801C
        ctx->r4 = S32(0X801C << 16);
            goto L_80189084;
    }
    // 0x80188E30: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80188E34: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80188E38: addiu       $a0, $a0, -0x7938
    ctx->r4 = ADD32(ctx->r4, -0X7938);
    // 0x80188E3C: lui         $a1, 0xC120
    ctx->r5 = S32(0XC120 << 16);
    // 0x80188E40: lw          $a2, 0x0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X0);
    // 0x80188E44: jal         0x8009BC2C
    // 0x80188E48: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_11;
    // 0x80188E48: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_11:
    // 0x80188E4C: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80188E50: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80188E54: lui         $a1, 0x4264
    ctx->r5 = S32(0X4264 << 16);
    // 0x80188E58: lw          $a2, 0x0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X0);
    // 0x80188E5C: jal         0x8009BC2C
    // 0x80188E60: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_12;
    // 0x80188E60: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_12:
    // 0x80188E64: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80188E68: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80188E6C: addiu       $a0, $a0, -0x6FA4
    ctx->r4 = ADD32(ctx->r4, -0X6FA4);
    // 0x80188E70: lui         $a1, 0x42F8
    ctx->r5 = S32(0X42F8 << 16);
    // 0x80188E74: lw          $a2, 0x0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X0);
    // 0x80188E78: jal         0x8009BC2C
    // 0x80188E7C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_13;
    // 0x80188E7C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_13:
    // 0x80188E80: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80188E84: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80188E88: addiu       $a0, $a0, -0x6FA0
    ctx->r4 = ADD32(ctx->r4, -0X6FA0);
    // 0x80188E8C: lui         $a1, 0x4372
    ctx->r5 = S32(0X4372 << 16);
    // 0x80188E90: lw          $a2, 0x0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X0);
    // 0x80188E94: jal         0x8009BC2C
    // 0x80188E98: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_14;
    // 0x80188E98: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_14:
    // 0x80188E9C: lui         $s2, 0x801C
    ctx->r18 = S32(0X801C << 16);
    // 0x80188EA0: lui         $s3, 0x801C
    ctx->r19 = S32(0X801C << 16);
    // 0x80188EA4: lui         $s4, 0x801C
    ctx->r20 = S32(0X801C << 16);
    // 0x80188EA8: lui         $s5, 0x801C
    ctx->r21 = S32(0X801C << 16);
    // 0x80188EAC: lui         $s6, 0x801C
    ctx->r22 = S32(0X801C << 16);
    // 0x80188EB0: lui         $s7, 0x801C
    ctx->r23 = S32(0X801C << 16);
    // 0x80188EB4: lui         $fp, 0x801C
    ctx->r30 = S32(0X801C << 16);
    // 0x80188EB8: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x80188EBC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80188EC0: lwc1        $f20, 0x6E48($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X6E48);
    // 0x80188EC4: addiu       $s0, $s0, -0x7C6C
    ctx->r16 = ADD32(ctx->r16, -0X7C6C);
    // 0x80188EC8: addiu       $fp, $fp, -0x7C70
    ctx->r30 = ADD32(ctx->r30, -0X7C70);
    // 0x80188ECC: addiu       $s7, $s7, -0x7C74
    ctx->r23 = ADD32(ctx->r23, -0X7C74);
    // 0x80188ED0: addiu       $s6, $s6, -0x7C78
    ctx->r22 = ADD32(ctx->r22, -0X7C78);
    // 0x80188ED4: addiu       $s5, $s5, -0x7C7C
    ctx->r21 = ADD32(ctx->r21, -0X7C7C);
    // 0x80188ED8: addiu       $s4, $s4, -0x7C80
    ctx->r20 = ADD32(ctx->r20, -0X7C80);
    // 0x80188EDC: addiu       $s3, $s3, -0x7C84
    ctx->r19 = ADD32(ctx->r19, -0X7C84);
    // 0x80188EE0: addiu       $s2, $s2, -0x7C88
    ctx->r18 = ADD32(ctx->r18, -0X7C88);
L_80188EE4:
    // 0x80188EE4: mfc1        $a1, $f24
    ctx->r5 = (int32_t)ctx->f24.u32l;
    // 0x80188EE8: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80188EEC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80188EF0: lw          $a2, 0x0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X0);
    // 0x80188EF4: jal         0x8009BC2C
    // 0x80188EF8: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_15;
    // 0x80188EF8: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_15:
    // 0x80188EFC: mfc1        $a1, $f24
    ctx->r5 = (int32_t)ctx->f24.u32l;
    // 0x80188F00: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80188F04: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80188F08: lw          $a2, 0x0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X0);
    // 0x80188F0C: jal         0x8009BC2C
    // 0x80188F10: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_16;
    // 0x80188F10: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_16:
    // 0x80188F14: mfc1        $a1, $f24
    ctx->r5 = (int32_t)ctx->f24.u32l;
    // 0x80188F18: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80188F1C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80188F20: lw          $a2, 0x0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X0);
    // 0x80188F24: jal         0x8009BC2C
    // 0x80188F28: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_17;
    // 0x80188F28: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_17:
    // 0x80188F2C: mfc1        $a1, $f24
    ctx->r5 = (int32_t)ctx->f24.u32l;
    // 0x80188F30: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80188F34: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80188F38: lw          $a2, 0x0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X0);
    // 0x80188F3C: jal         0x8009BC2C
    // 0x80188F40: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_18;
    // 0x80188F40: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_18:
    // 0x80188F44: mfc1        $a1, $f24
    ctx->r5 = (int32_t)ctx->f24.u32l;
    // 0x80188F48: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80188F4C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80188F50: lw          $a2, 0x0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X0);
    // 0x80188F54: jal         0x8009BC2C
    // 0x80188F58: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_19;
    // 0x80188F58: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_19:
    // 0x80188F5C: mfc1        $a1, $f24
    ctx->r5 = (int32_t)ctx->f24.u32l;
    // 0x80188F60: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80188F64: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80188F68: lw          $a2, 0x0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X0);
    // 0x80188F6C: jal         0x8009BC2C
    // 0x80188F70: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_20;
    // 0x80188F70: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_20:
    // 0x80188F74: mfc1        $a1, $f24
    ctx->r5 = (int32_t)ctx->f24.u32l;
    // 0x80188F78: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80188F7C: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x80188F80: lw          $a2, 0x0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X0);
    // 0x80188F84: jal         0x8009BC2C
    // 0x80188F88: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_21;
    // 0x80188F88: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_21:
    // 0x80188F8C: mfc1        $a1, $f24
    ctx->r5 = (int32_t)ctx->f24.u32l;
    // 0x80188F90: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80188F94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80188F98: lw          $a2, 0x0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X0);
    // 0x80188F9C: jal         0x8009BC2C
    // 0x80188FA0: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_22;
    // 0x80188FA0: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_22:
    // 0x80188FA4: lui         $t2, 0x801C
    ctx->r10 = S32(0X801C << 16);
    // 0x80188FA8: addiu       $t2, $t2, -0x7AEC
    ctx->r10 = ADD32(ctx->r10, -0X7AEC);
    // 0x80188FAC: addiu       $s0, $s0, 0x60
    ctx->r16 = ADD32(ctx->r16, 0X60);
    // 0x80188FB0: addiu       $s2, $s2, 0x60
    ctx->r18 = ADD32(ctx->r18, 0X60);
    // 0x80188FB4: addiu       $s3, $s3, 0x60
    ctx->r19 = ADD32(ctx->r19, 0X60);
    // 0x80188FB8: addiu       $s4, $s4, 0x60
    ctx->r20 = ADD32(ctx->r20, 0X60);
    // 0x80188FBC: addiu       $s5, $s5, 0x60
    ctx->r21 = ADD32(ctx->r21, 0X60);
    // 0x80188FC0: addiu       $s6, $s6, 0x60
    ctx->r22 = ADD32(ctx->r22, 0X60);
    // 0x80188FC4: addiu       $s7, $s7, 0x60
    ctx->r23 = ADD32(ctx->r23, 0X60);
    // 0x80188FC8: bne         $s0, $t2, L_80188EE4
    if (ctx->r16 != ctx->r10) {
        // 0x80188FCC: addiu       $fp, $fp, 0x60
        ctx->r30 = ADD32(ctx->r30, 0X60);
            goto L_80188EE4;
    }
    // 0x80188FCC: addiu       $fp, $fp, 0x60
    ctx->r30 = ADD32(ctx->r30, 0X60);
    // 0x80188FD0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80188FD4: lwc1        $f18, 0x6E4C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6E4C);
    // 0x80188FD8: lwc1        $f16, 0x0($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80188FDC: lui         $at, 0x42F8
    ctx->r1 = S32(0X42F8 << 16);
    // 0x80188FE0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80188FE4: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80188FE8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80188FEC: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x80188FF0: swc1        $f4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f4.u32l;
    // 0x80188FF4: lwc1        $f8, -0x6FA4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X6FA4);
    // 0x80188FF8: lui         $at, 0x4372
    ctx->r1 = S32(0X4372 << 16);
    // 0x80188FFC: c.eq.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl == ctx->f8.fl;
    // 0x80189000: nop

    // 0x80189004: bc1f        L_80189044
    if (!c1cs) {
        // 0x80189008: nop
    
            goto L_80189044;
    }
    // 0x80189008: nop

    // 0x8018900C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80189010: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80189014: lwc1        $f16, -0x6FA0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X6FA0);
    // 0x80189018: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018901C: c.eq.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl == ctx->f16.fl;
    // 0x80189020: nop

    // 0x80189024: bc1f        L_80189044
    if (!c1cs) {
        // 0x80189028: nop
    
            goto L_80189044;
    }
    // 0x80189028: nop

    // 0x8018902C: sw          $zero, -0x6FC0($at)
    MEM_W(-0X6FC0, ctx->r1) = 0;
    // 0x80189030: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80189034: lwc1        $f18, 0x6E50($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6E50);
    // 0x80189038: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018903C: swc1        $f18, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f18.u32l;
    // 0x80189040: sw          $zero, -0x795C($at)
    MEM_W(-0X795C, ctx->r1) = 0;
L_80189044:
    // 0x80189044: lw          $t3, 0x7AF8($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7AF8);
    // 0x80189048: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8018904C: addiu       $t5, $t5, -0x2768
    ctx->r13 = ADD32(ctx->r13, -0X2768);
    // 0x80189050: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80189054: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x80189058: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x8018905C: addu        $v0, $t4, $t5
    ctx->r2 = ADD32(ctx->r12, ctx->r13);
    // 0x80189060: lb          $t6, 0x2($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X2);
    // 0x80189064: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80189068: bne         $t6, $zero, L_8018907C
    if (ctx->r14 != 0) {
        // 0x8018906C: nop
    
            goto L_8018907C;
    }
    // 0x8018906C: nop

    // 0x80189070: lb          $t7, 0x3($v0)
    ctx->r15 = MEM_B(ctx->r2, 0X3);
    // 0x80189074: beq         $t7, $zero, L_80189084
    if (ctx->r15 == 0) {
        // 0x80189078: nop
    
            goto L_80189084;
    }
    // 0x80189078: nop

L_8018907C:
    // 0x8018907C: lwc1        $f4, 0x6E54($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6E54);
    // 0x80189080: swc1        $f4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f4.u32l;
L_80189084:
    // 0x80189084: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80189088: addiu       $v0, $v0, -0x7B18
    ctx->r2 = ADD32(ctx->r2, -0X7B18);
    // 0x8018908C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80189090: lwc1        $f8, 0x6E58($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6E58);
    // 0x80189094: lwc1        $f6, 0x18($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80189098: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018909C: lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // 0x801890A0: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801890A4: lui         $s1, 0x8017
    ctx->r17 = S32(0X8017 << 16);
    // 0x801890A8: lui         $s2, 0x8017
    ctx->r18 = S32(0X8017 << 16);
    // 0x801890AC: lui         $s3, 0x8017
    ctx->r19 = S32(0X8017 << 16);
    // 0x801890B0: swc1        $f10, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f10.u32l;
    // 0x801890B4: lwc1        $f16, -0x7958($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X7958);
    // 0x801890B8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801890BC: lwc1        $f18, -0x7954($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X7954);
    // 0x801890C0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801890C4: lwc1        $f4, -0x7950($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7950);
    // 0x801890C8: lui         $s4, 0x8017
    ctx->r20 = S32(0X8017 << 16);
    // 0x801890CC: lui         $s5, 0x8017
    ctx->r21 = S32(0X8017 << 16);
    // 0x801890D0: addiu       $s5, $s5, 0x79C0
    ctx->r21 = ADD32(ctx->r21, 0X79C0);
    // 0x801890D4: addiu       $s4, $s4, 0x79B8
    ctx->r20 = ADD32(ctx->r20, 0X79B8);
    // 0x801890D8: addiu       $s3, $s3, 0x79A0
    ctx->r19 = ADD32(ctx->r19, 0X79A0);
    // 0x801890DC: addiu       $s2, $s2, 0x7988
    ctx->r18 = ADD32(ctx->r18, 0X7988);
    // 0x801890E0: addiu       $s1, $s1, 0x7980
    ctx->r17 = ADD32(ctx->r17, 0X7980);
    // 0x801890E4: addiu       $s0, $s0, 0x7978
    ctx->r16 = ADD32(ctx->r16, 0X7978);
    // 0x801890E8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x801890EC: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x801890F0: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    // 0x801890F4: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x801890F8: sw          $s4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r20;
    // 0x801890FC: sw          $s5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r21;
    // 0x80189100: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80189104: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    // 0x80189108: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    // 0x8018910C: jal         0x80191320
    // 0x80189110: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    Title_SetCamUp3(rdram, ctx);
        goto after_23;
    // 0x80189110: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    after_23:
    // 0x80189114: lwc1        $f6, 0x0($s4)
    ctx->f6.u32l = MEM_W(ctx->r20, 0X0);
    // 0x80189118: lwc1        $f8, 0x0($s5)
    ctx->f8.u32l = MEM_W(ctx->r21, 0X0);
    // 0x8018911C: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80189120: lwc1        $f14, 0x0($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80189124: lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X0);
    // 0x80189128: lw          $a3, 0x0($s3)
    ctx->r7 = MEM_W(ctx->r19, 0X0);
    // 0x8018912C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x80189130: jal         0x800B6F50
    // 0x80189134: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    Camera_SetStarfieldPos(rdram, ctx);
        goto after_24;
    // 0x80189134: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_24:
    // 0x80189138: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8018913C: addiu       $v0, $v0, -0x7BD4
    ctx->r2 = ADD32(ctx->r2, -0X7BD4);
    // 0x80189140: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80189144: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80189148: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8018914C: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80189150: addiu       $v1, $v1, -0x7D50
    ctx->r3 = ADD32(ctx->r3, -0X7D50);
    // 0x80189154: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80189158: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x8018915C: lui         $t9, 0x801C
    ctx->r25 = S32(0X801C << 16);
    // 0x80189160: addiu       $t0, $zero, 0x1C2
    ctx->r8 = ADD32(0, 0X1C2);
    // 0x80189164: blez        $a0, L_80189174
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80189168: swc1        $f18, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->f18.u32l;
            goto L_80189174;
    }
    // 0x80189168: swc1        $f18, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f18.u32l;
    // 0x8018916C: addiu       $t8, $a0, -0x1
    ctx->r24 = ADD32(ctx->r4, -0X1);
    // 0x80189170: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
L_80189174:
    // 0x80189174: lw          $t9, -0x6FC0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X6FC0);
    // 0x80189178: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8018917C: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80189180: bne         $t9, $at, L_8018918C
    if (ctx->r25 != ctx->r1) {
        // 0x80189184: addiu       $v1, $v1, -0x7D44
        ctx->r3 = ADD32(ctx->r3, -0X7D44);
            goto L_8018918C;
    }
    // 0x80189184: addiu       $v1, $v1, -0x7D44
    ctx->r3 = ADD32(ctx->r3, -0X7D44);
    // 0x80189188: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
L_8018918C:
    // 0x8018918C: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80189190: addiu       $v1, $v1, -0x7D44
    ctx->r3 = ADD32(ctx->r3, -0X7D44);
    // 0x80189194: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80189198: beq         $v0, $zero, L_801891A8
    if (ctx->r2 == 0) {
        // 0x8018919C: addiu       $t1, $v0, -0x1
        ctx->r9 = ADD32(ctx->r2, -0X1);
            goto L_801891A8;
    }
    // 0x8018919C: addiu       $t1, $v0, -0x1
    ctx->r9 = ADD32(ctx->r2, -0X1);
    // 0x801891A0: b           L_801891CC
    // 0x801891A4: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
        goto L_801891CC;
    // 0x801891A4: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
L_801891A8:
    // 0x801891A8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801891AC: sw          $zero, -0x7BF0($at)
    MEM_W(-0X7BF0, ctx->r1) = 0;
    // 0x801891B0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801891B4: sw          $zero, -0x7D40($at)
    MEM_W(-0X7D40, ctx->r1) = 0;
    // 0x801891B8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801891BC: sw          $zero, 0x7898($at)
    MEM_W(0X7898, ctx->r1) = 0;
    // 0x801891C0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801891C4: addiu       $t2, $zero, 0x7
    ctx->r10 = ADD32(0, 0X7);
    // 0x801891C8: sw          $t2, -0x7D3C($at)
    MEM_W(-0X7D3C, ctx->r1) = ctx->r10;
L_801891CC:
    // 0x801891CC: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x801891D0: ldc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X30);
    // 0x801891D4: ldc1        $f22, 0x38($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X38);
    // 0x801891D8: ldc1        $f24, 0x40($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X40);
    // 0x801891DC: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x801891E0: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x801891E4: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x801891E8: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x801891EC: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x801891F0: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x801891F4: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x801891F8: lw          $s7, 0x64($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X64);
    // 0x801891FC: lw          $fp, 0x68($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X68);
    // 0x80189200: jr          $ra
    // 0x80189204: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x80189204: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void Title_Radio_PlayMessage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801919C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801919C8: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x801919CC: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x801919D0: addiu       $a2, $a2, -0x7CF8
    ctx->r6 = ADD32(ctx->r6, -0X7CF8);
    // 0x801919D4: addiu       $v1, $v1, -0x78DC
    ctx->r3 = ADD32(ctx->r3, -0X78DC);
    // 0x801919D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801919DC: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x801919E0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801919E4: sw          $a0, -0x78E0($at)
    MEM_W(-0X78E0, ctx->r1) = ctx->r4;
    // 0x801919E8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801919EC: sll         $t7, $zero, 2
    ctx->r15 = S32(0 << 2);
    // 0x801919F0: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x801919F4: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x801919F8: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x801919FC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80191A00: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80191A04: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x80191A08: swc1        $f6, 0x7D68($at)
    MEM_W(0X7D68, ctx->r1) = ctx->f6.u32l;
    // 0x80191A0C: lw          $v0, 0x7834($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7834);
    // 0x80191A10: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80191A14: addiu       $t0, $zero, 0x64
    ctx->r8 = ADD32(0, 0X64);
    // 0x80191A18: sw          $t0, -0x7D64($at)
    MEM_W(-0X7D64, ctx->r1) = ctx->r8;
    // 0x80191A1C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80191A20: beq         $v0, $at, L_80191A3C
    if (ctx->r2 == ctx->r1) {
        // 0x80191A24: addiu       $t1, $zero, 0xB0
        ctx->r9 = ADD32(0, 0XB0);
            goto L_80191A3C;
    }
    // 0x80191A24: addiu       $t1, $zero, 0xB0
    ctx->r9 = ADD32(0, 0XB0);
    // 0x80191A28: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80191A2C: beq         $v0, $at, L_80191A9C
    if (ctx->r2 == ctx->r1) {
        // 0x80191A30: addiu       $t3, $zero, 0xB3
        ctx->r11 = ADD32(0, 0XB3);
            goto L_80191A9C;
    }
    // 0x80191A30: addiu       $t3, $zero, 0xB3
    ctx->r11 = ADD32(0, 0XB3);
    // 0x80191A34: b           L_80191AF8
    // 0x80191A38: nop

        goto L_80191AF8;
    // 0x80191A38: nop

L_80191A3C:
    // 0x80191A3C: lui         $at, 0x432E
    ctx->r1 = S32(0X432E << 16);
    // 0x80191A40: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80191A44: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80191A48: sw          $t1, -0x78D4($at)
    MEM_W(-0X78D4, ctx->r1) = ctx->r9;
    // 0x80191A4C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80191A50: addiu       $t2, $zero, 0x55
    ctx->r10 = ADD32(0, 0X55);
    // 0x80191A54: sw          $t2, -0x78D8($at)
    MEM_W(-0X78D8, ctx->r1) = ctx->r10;
    // 0x80191A58: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x80191A5C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80191A60: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80191A64: swc1        $f8, -0x78D0($at)
    MEM_W(-0X78D0, ctx->r1) = ctx->f8.u32l;
    // 0x80191A68: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80191A6C: swc1        $f0, -0x78CC($at)
    MEM_W(-0X78CC, ctx->r1) = ctx->f0.u32l;
    // 0x80191A70: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80191A74: lwc1        $f10, 0x7108($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7108);
    // 0x80191A78: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80191A7C: swc1        $f10, -0x78C8($at)
    MEM_W(-0X78C8, ctx->r1) = ctx->f10.u32l;
    // 0x80191A80: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x80191A84: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80191A88: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80191A8C: swc1        $f16, -0x78C4($at)
    MEM_W(-0X78C4, ctx->r1) = ctx->f16.u32l;
    // 0x80191A90: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80191A94: b           L_80191AF8
    // 0x80191A98: swc1        $f0, -0x78C0($at)
    MEM_W(-0X78C0, ctx->r1) = ctx->f0.u32l;
        goto L_80191AF8;
    // 0x80191A98: swc1        $f0, -0x78C0($at)
    MEM_W(-0X78C0, ctx->r1) = ctx->f0.u32l;
L_80191A9C:
    // 0x80191A9C: lui         $at, 0x4332
    ctx->r1 = S32(0X4332 << 16);
    // 0x80191AA0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80191AA4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80191AA8: sw          $t3, -0x78D4($at)
    MEM_W(-0X78D4, ctx->r1) = ctx->r11;
    // 0x80191AAC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80191AB0: addiu       $t4, $zero, 0x4F
    ctx->r12 = ADD32(0, 0X4F);
    // 0x80191AB4: sw          $t4, -0x78D8($at)
    MEM_W(-0X78D8, ctx->r1) = ctx->r12;
    // 0x80191AB8: lui         $at, 0x4294
    ctx->r1 = S32(0X4294 << 16);
    // 0x80191ABC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80191AC0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80191AC4: swc1        $f18, -0x78D0($at)
    MEM_W(-0X78D0, ctx->r1) = ctx->f18.u32l;
    // 0x80191AC8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80191ACC: swc1        $f0, -0x78CC($at)
    MEM_W(-0X78CC, ctx->r1) = ctx->f0.u32l;
    // 0x80191AD0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80191AD4: lwc1        $f4, 0x710C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X710C);
    // 0x80191AD8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80191ADC: swc1        $f4, -0x78C8($at)
    MEM_W(-0X78C8, ctx->r1) = ctx->f4.u32l;
    // 0x80191AE0: lui         $at, 0x41D0
    ctx->r1 = S32(0X41D0 << 16);
    // 0x80191AE4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80191AE8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80191AEC: swc1        $f6, -0x78C4($at)
    MEM_W(-0X78C4, ctx->r1) = ctx->f6.u32l;
    // 0x80191AF0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80191AF4: swc1        $f0, -0x78C0($at)
    MEM_W(-0X78C0, ctx->r1) = ctx->f0.u32l;
L_80191AF8:
    // 0x80191AF8: jal         0x800C2890
    // 0x80191AFC: lw          $a0, 0x0($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X0);
    Message_IdFromPtr(rdram, ctx);
        goto after_0;
    // 0x80191AFC: lw          $a0, 0x0($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X0);
    after_0:
    // 0x80191B00: jal         0x8001ACDC
    // 0x80191B04: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    Audio_PlayVoice(rdram, ctx);
        goto after_1;
    // 0x80191B04: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80191B08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80191B0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80191B10: jr          $ra
    // 0x80191B14: nop

    return;
    // 0x80191B14: nop

;}
RECOMP_FUNC void Map_CurrentLevel_Setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A6368: lui         $t6, 0x801D
    ctx->r14 = S32(0X801D << 16);
    // 0x801A636C: lw          $t6, -0x26AC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X26AC);
    // 0x801A6370: sltiu       $at, $t6, 0xF
    ctx->r1 = ctx->r14 < 0XF ? 1 : 0;
    // 0x801A6374: beq         $at, $zero, L_801A6478
    if (ctx->r1 == 0) {
        // 0x801A6378: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_801A6478;
    }
    // 0x801A6378: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801A637C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A6380: addu        $at, $at, $t6
    gpr jr_addend_801A6388 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x801A6384: lw          $t6, 0x78B0($at)
    ctx->r14 = ADD32(ctx->r1, 0X78B0);
    // 0x801A6388: jr          $t6
    // 0x801A638C: nop

    switch (jr_addend_801A6388 >> 2) {
        case 0: goto L_801A639C; break;
        case 1: goto L_801A63EC; break;
        case 2: goto L_801A63CC; break;
        case 3: goto L_801A63FC; break;
        case 4: goto L_801A641C; break;
        case 5: goto L_801A644C; break;
        case 6: goto L_801A63DC; break;
        case 7: goto L_801A642C; break;
        case 8: goto L_801A643C; break;
        case 9: goto L_801A6390; break;
        case 10: goto L_801A63AC; break;
        case 11: goto L_801A63BC; break;
        case 12: goto L_801A640C; break;
        case 13: goto L_801A645C; break;
        case 14: goto L_801A646C; break;
        default: switch_error(__func__, 0x801A6388, 0x801B78B0);
    }
    // 0x801A638C: nop

L_801A6390:
    // 0x801A6390: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801A6394: jr          $ra
    // 0x801A6398: sw          $zero, -0x7DCC($at)
    MEM_W(-0X7DCC, ctx->r1) = 0;
    return;
    // 0x801A6398: sw          $zero, -0x7DCC($at)
    MEM_W(-0X7DCC, ctx->r1) = 0;
L_801A639C:
    // 0x801A639C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801A63A0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801A63A4: jr          $ra
    // 0x801A63A8: sw          $t7, -0x7DCC($at)
    MEM_W(-0X7DCC, ctx->r1) = ctx->r15;
    return;
    // 0x801A63A8: sw          $t7, -0x7DCC($at)
    MEM_W(-0X7DCC, ctx->r1) = ctx->r15;
L_801A63AC:
    // 0x801A63AC: addiu       $t8, $zero, 0xC
    ctx->r24 = ADD32(0, 0XC);
    // 0x801A63B0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801A63B4: jr          $ra
    // 0x801A63B8: sw          $t8, -0x7DCC($at)
    MEM_W(-0X7DCC, ctx->r1) = ctx->r24;
    return;
    // 0x801A63B8: sw          $t8, -0x7DCC($at)
    MEM_W(-0X7DCC, ctx->r1) = ctx->r24;
L_801A63BC:
    // 0x801A63BC: addiu       $t9, $zero, 0xD
    ctx->r25 = ADD32(0, 0XD);
    // 0x801A63C0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801A63C4: jr          $ra
    // 0x801A63C8: sw          $t9, -0x7DCC($at)
    MEM_W(-0X7DCC, ctx->r1) = ctx->r25;
    return;
    // 0x801A63C8: sw          $t9, -0x7DCC($at)
    MEM_W(-0X7DCC, ctx->r1) = ctx->r25;
L_801A63CC:
    // 0x801A63CC: addiu       $t0, $zero, 0x11
    ctx->r8 = ADD32(0, 0X11);
    // 0x801A63D0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801A63D4: jr          $ra
    // 0x801A63D8: sw          $t0, -0x7DCC($at)
    MEM_W(-0X7DCC, ctx->r1) = ctx->r8;
    return;
    // 0x801A63D8: sw          $t0, -0x7DCC($at)
    MEM_W(-0X7DCC, ctx->r1) = ctx->r8;
L_801A63DC:
    // 0x801A63DC: addiu       $t1, $zero, 0x10
    ctx->r9 = ADD32(0, 0X10);
    // 0x801A63E0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801A63E4: jr          $ra
    // 0x801A63E8: sw          $t1, -0x7DCC($at)
    MEM_W(-0X7DCC, ctx->r1) = ctx->r9;
    return;
    // 0x801A63E8: sw          $t1, -0x7DCC($at)
    MEM_W(-0X7DCC, ctx->r1) = ctx->r9;
L_801A63EC:
    // 0x801A63EC: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x801A63F0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801A63F4: jr          $ra
    // 0x801A63F8: sw          $t2, -0x7DCC($at)
    MEM_W(-0X7DCC, ctx->r1) = ctx->r10;
    return;
    // 0x801A63F8: sw          $t2, -0x7DCC($at)
    MEM_W(-0X7DCC, ctx->r1) = ctx->r10;
L_801A63FC:
    // 0x801A63FC: addiu       $t3, $zero, 0x12
    ctx->r11 = ADD32(0, 0X12);
    // 0x801A6400: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801A6404: jr          $ra
    // 0x801A6408: sw          $t3, -0x7DCC($at)
    MEM_W(-0X7DCC, ctx->r1) = ctx->r11;
    return;
    // 0x801A6408: sw          $t3, -0x7DCC($at)
    MEM_W(-0X7DCC, ctx->r1) = ctx->r11;
L_801A640C:
    // 0x801A640C: addiu       $t4, $zero, 0xE
    ctx->r12 = ADD32(0, 0XE);
    // 0x801A6410: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801A6414: jr          $ra
    // 0x801A6418: sw          $t4, -0x7DCC($at)
    MEM_W(-0X7DCC, ctx->r1) = ctx->r12;
    return;
    // 0x801A6418: sw          $t4, -0x7DCC($at)
    MEM_W(-0X7DCC, ctx->r1) = ctx->r12;
L_801A641C:
    // 0x801A641C: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x801A6420: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801A6424: jr          $ra
    // 0x801A6428: sw          $t5, -0x7DCC($at)
    MEM_W(-0X7DCC, ctx->r1) = ctx->r13;
    return;
    // 0x801A6428: sw          $t5, -0x7DCC($at)
    MEM_W(-0X7DCC, ctx->r1) = ctx->r13;
L_801A642C:
    // 0x801A642C: addiu       $t6, $zero, 0xB
    ctx->r14 = ADD32(0, 0XB);
    // 0x801A6430: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801A6434: jr          $ra
    // 0x801A6438: sw          $t6, -0x7DCC($at)
    MEM_W(-0X7DCC, ctx->r1) = ctx->r14;
    return;
    // 0x801A6438: sw          $t6, -0x7DCC($at)
    MEM_W(-0X7DCC, ctx->r1) = ctx->r14;
L_801A643C:
    // 0x801A643C: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x801A6440: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801A6444: jr          $ra
    // 0x801A6448: sw          $t7, -0x7DCC($at)
    MEM_W(-0X7DCC, ctx->r1) = ctx->r15;
    return;
    // 0x801A6448: sw          $t7, -0x7DCC($at)
    MEM_W(-0X7DCC, ctx->r1) = ctx->r15;
L_801A644C:
    // 0x801A644C: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x801A6450: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801A6454: jr          $ra
    // 0x801A6458: sw          $t8, -0x7DCC($at)
    MEM_W(-0X7DCC, ctx->r1) = ctx->r24;
    return;
    // 0x801A6458: sw          $t8, -0x7DCC($at)
    MEM_W(-0X7DCC, ctx->r1) = ctx->r24;
L_801A645C:
    // 0x801A645C: addiu       $t9, $zero, 0x6
    ctx->r25 = ADD32(0, 0X6);
    // 0x801A6460: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801A6464: jr          $ra
    // 0x801A6468: sw          $t9, -0x7DCC($at)
    MEM_W(-0X7DCC, ctx->r1) = ctx->r25;
    return;
    // 0x801A6468: sw          $t9, -0x7DCC($at)
    MEM_W(-0X7DCC, ctx->r1) = ctx->r25;
L_801A646C:
    // 0x801A646C: addiu       $t0, $zero, 0x7
    ctx->r8 = ADD32(0, 0X7);
    // 0x801A6470: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801A6474: sw          $t0, -0x7DCC($at)
    MEM_W(-0X7DCC, ctx->r1) = ctx->r8;
L_801A6478:
    // 0x801A6478: jr          $ra
    // 0x801A647C: nop

    return;
    // 0x801A647C: nop

;}
RECOMP_FUNC void Map_PlanetAnim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A7230: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801A7234: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801A7238: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801A723C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x801A7240: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801A7244: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x801A7248: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x801A724C: addiu       $t8, $t8, -0xB60
    ctx->r24 = ADD32(ctx->r24, -0XB60);
    // 0x801A7250: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x801A7254: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x801A7258: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x801A725C: addu        $s1, $t7, $t8
    ctx->r17 = ADD32(ctx->r15, ctx->r24);
    // 0x801A7260: lw          $t9, 0x28($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X28);
    // 0x801A7264: sltiu       $at, $t9, 0x5
    ctx->r1 = ctx->r25 < 0X5 ? 1 : 0;
    // 0x801A7268: beq         $at, $zero, L_801A746C
    if (ctx->r1 == 0) {
        // 0x801A726C: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_801A746C;
    }
    // 0x801A726C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x801A7270: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A7274: addu        $at, $at, $t9
    gpr jr_addend_801A727C = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x801A7278: lw          $t9, 0x7964($at)
    ctx->r25 = ADD32(ctx->r1, 0X7964);
    // 0x801A727C: jr          $t9
    // 0x801A7280: nop

    switch (jr_addend_801A727C >> 2) {
        case 0: goto L_801A7284; break;
        case 1: goto L_801A73BC; break;
        case 2: goto L_801A7320; break;
        case 3: goto L_801A7400; break;
        case 4: goto L_801A73BC; break;
        default: switch_error(__func__, 0x801A727C, 0x801B7964);
    }
    // 0x801A7280: nop

L_801A7284:
    // 0x801A7284: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801A7288: lw          $v0, -0x26BC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X26BC);
    // 0x801A728C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801A7290: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x801A7294: beq         $v0, $at, L_801A72B4
    if (ctx->r2 == ctx->r1) {
        // 0x801A7298: lui         $t1, 0x801D
        ctx->r9 = S32(0X801D << 16);
            goto L_801A72B4;
    }
    // 0x801A7298: lui         $t1, 0x801D
    ctx->r9 = S32(0X801D << 16);
    // 0x801A729C: lw          $t1, -0x26AC($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X26AC);
    // 0x801A72A0: lui         $t2, 0x801D
    ctx->r10 = S32(0X801D << 16);
    // 0x801A72A4: beql        $t0, $t1, L_801A72B8
    if (ctx->r8 == ctx->r9) {
        // 0x801A72A8: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_801A72B8;
    }
    goto skip_0;
    // 0x801A72A8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    skip_0:
    // 0x801A72AC: lw          $t2, -0x26A8($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X26A8);
    // 0x801A72B0: bne         $t0, $t2, L_801A72DC
    if (ctx->r8 != ctx->r10) {
        // 0x801A72B4: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_801A72DC;
    }
L_801A72B4:
    // 0x801A72B4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_801A72B8:
    // 0x801A72B8: beq         $v0, $at, L_801A72DC
    if (ctx->r2 == ctx->r1) {
        // 0x801A72BC: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_801A72DC;
    }
    // 0x801A72BC: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x801A72C0: beq         $v0, $at, L_801A72DC
    if (ctx->r2 == ctx->r1) {
        // 0x801A72C4: lui         $s0, 0x8013
        ctx->r16 = S32(0X8013 << 16);
            goto L_801A72DC;
    }
    // 0x801A72C4: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x801A72C8: addiu       $a0, $s0, 0x7E64
    ctx->r4 = ADD32(ctx->r16, 0X7E64);
    // 0x801A72CC: jal         0x800B8DD0
    // 0x801A72D0: addiu       $a1, $zero, 0x35
    ctx->r5 = ADD32(0, 0X35);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x801A72D0: addiu       $a1, $zero, 0x35
    ctx->r5 = ADD32(0, 0X35);
    after_0:
    // 0x801A72D4: b           L_801A746C
    // 0x801A72D8: nop

        goto L_801A746C;
    // 0x801A72D8: nop

L_801A72DC:
    // 0x801A72DC: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x801A72E0: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x801A72E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801A72E8: jal         0x800B8DD0
    // 0x801A72EC: addiu       $a1, $zero, 0x29
    ctx->r5 = ADD32(0, 0X29);
    RCP_SetupDL(rdram, ctx);
        goto after_1;
    // 0x801A72EC: addiu       $a1, $zero, 0x29
    ctx->r5 = ADD32(0, 0X29);
    after_1:
    // 0x801A72F0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801A72F4: lui         $t4, 0xFA00
    ctx->r12 = S32(0XFA00 << 16);
    // 0x801A72F8: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x801A72FC: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x801A7300: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x801A7304: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x801A7308: lw          $t5, 0x24($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X24);
    // 0x801A730C: andi        $t6, $t5, 0xFF
    ctx->r14 = ctx->r13 & 0XFF;
    // 0x801A7310: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x801A7314: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x801A7318: b           L_801A746C
    // 0x801A731C: nop

        goto L_801A746C;
    // 0x801A731C: nop

L_801A7320:
    // 0x801A7320: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801A7324: lw          $v0, -0x26BC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X26BC);
    // 0x801A7328: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801A732C: beq         $v0, $at, L_801A7350
    if (ctx->r2 == ctx->r1) {
        // 0x801A7330: lui         $t9, 0x801D
        ctx->r25 = S32(0X801D << 16);
            goto L_801A7350;
    }
    // 0x801A7330: lui         $t9, 0x801D
    ctx->r25 = S32(0X801D << 16);
    // 0x801A7334: lw          $t9, -0x26AC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X26AC);
    // 0x801A7338: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x801A733C: lui         $t1, 0x801D
    ctx->r9 = S32(0X801D << 16);
    // 0x801A7340: beql        $t8, $t9, L_801A7354
    if (ctx->r24 == ctx->r25) {
        // 0x801A7344: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_801A7354;
    }
    goto skip_1;
    // 0x801A7344: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    skip_1:
    // 0x801A7348: lw          $t1, -0x26A8($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X26A8);
    // 0x801A734C: bne         $t8, $t1, L_801A7378
    if (ctx->r24 != ctx->r9) {
        // 0x801A7350: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_801A7378;
    }
L_801A7350:
    // 0x801A7350: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_801A7354:
    // 0x801A7354: beq         $v0, $at, L_801A7378
    if (ctx->r2 == ctx->r1) {
        // 0x801A7358: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_801A7378;
    }
    // 0x801A7358: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x801A735C: beq         $v0, $at, L_801A7378
    if (ctx->r2 == ctx->r1) {
        // 0x801A7360: lui         $s0, 0x8013
        ctx->r16 = S32(0X8013 << 16);
            goto L_801A7378;
    }
    // 0x801A7360: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x801A7364: addiu       $a0, $s0, 0x7E64
    ctx->r4 = ADD32(ctx->r16, 0X7E64);
    // 0x801A7368: jal         0x800B8DD0
    // 0x801A736C: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    RCP_SetupDL(rdram, ctx);
        goto after_2;
    // 0x801A736C: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    after_2:
    // 0x801A7370: b           L_801A746C
    // 0x801A7374: nop

        goto L_801A746C;
    // 0x801A7374: nop

L_801A7378:
    // 0x801A7378: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x801A737C: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x801A7380: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801A7384: jal         0x800B8DD0
    // 0x801A7388: addiu       $a1, $zero, 0x2E
    ctx->r5 = ADD32(0, 0X2E);
    RCP_SetupDL(rdram, ctx);
        goto after_3;
    // 0x801A7388: addiu       $a1, $zero, 0x2E
    ctx->r5 = ADD32(0, 0X2E);
    after_3:
    // 0x801A738C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801A7390: lui         $t2, 0xFA00
    ctx->r10 = S32(0XFA00 << 16);
    // 0x801A7394: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x801A7398: addiu       $t0, $v0, 0x8
    ctx->r8 = ADD32(ctx->r2, 0X8);
    // 0x801A739C: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x801A73A0: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x801A73A4: lw          $t3, 0x24($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X24);
    // 0x801A73A8: andi        $t4, $t3, 0xFF
    ctx->r12 = ctx->r11 & 0XFF;
    // 0x801A73AC: or          $t5, $t4, $at
    ctx->r13 = ctx->r12 | ctx->r1;
    // 0x801A73B0: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x801A73B4: b           L_801A746C
    // 0x801A73B8: nop

        goto L_801A746C;
    // 0x801A73B8: nop

L_801A73BC:
    // 0x801A73BC: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x801A73C0: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x801A73C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801A73C8: jal         0x800B8DD0
    // 0x801A73CC: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    RCP_SetupDL(rdram, ctx);
        goto after_4;
    // 0x801A73CC: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_4:
    // 0x801A73D0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801A73D4: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x801A73D8: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x801A73DC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801A73E0: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x801A73E4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801A73E8: lw          $t9, 0x24($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X24);
    // 0x801A73EC: andi        $t8, $t9, 0xFF
    ctx->r24 = ctx->r25 & 0XFF;
    // 0x801A73F0: or          $t1, $t8, $at
    ctx->r9 = ctx->r24 | ctx->r1;
    // 0x801A73F4: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x801A73F8: b           L_801A746C
    // 0x801A73FC: nop

        goto L_801A746C;
    // 0x801A73FC: nop

L_801A7400:
    // 0x801A7400: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x801A7404: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x801A7408: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801A740C: jal         0x800B8DD0
    // 0x801A7410: addiu       $a1, $zero, 0x43
    ctx->r5 = ADD32(0, 0X43);
    RCP_SetupDL(rdram, ctx);
        goto after_5;
    // 0x801A7410: addiu       $a1, $zero, 0x43
    ctx->r5 = ADD32(0, 0X43);
    after_5:
    // 0x801A7414: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801A7418: lui         $t2, 0xFA00
    ctx->r10 = S32(0XFA00 << 16);
    // 0x801A741C: lui         $at, 0xF000
    ctx->r1 = S32(0XF000 << 16);
    // 0x801A7420: addiu       $t0, $v0, 0x8
    ctx->r8 = ADD32(ctx->r2, 0X8);
    // 0x801A7424: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x801A7428: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x801A742C: lw          $t3, 0x24($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X24);
    // 0x801A7430: andi        $t4, $t3, 0xFF
    ctx->r12 = ctx->r11 & 0XFF;
    // 0x801A7434: or          $t5, $t4, $at
    ctx->r13 = ctx->r12 | ctx->r1;
    // 0x801A7438: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x801A743C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801A7440: lui         $t7, 0xFB00
    ctx->r15 = S32(0XFB00 << 16);
    // 0x801A7444: lui         $t9, 0x1F00
    ctx->r25 = S32(0X1F00 << 16);
    // 0x801A7448: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801A744C: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x801A7450: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x801A7454: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801A7458: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A745C: lwc1        $f6, 0x7978($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7978);
    // 0x801A7460: lwc1        $f4, 0xC($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XC);
    // 0x801A7464: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801A7468: swc1        $f8, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f8.u32l;
L_801A746C:
    // 0x801A746C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x801A7470: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A7474: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x801A7478: jal         0x80005708
    // 0x801A747C: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Push(rdram, ctx);
        goto after_6;
    // 0x801A747C: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_6:
    // 0x801A7480: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x801A7484: lui         $t0, 0x801D
    ctx->r8 = S32(0X801D << 16);
    // 0x801A7488: addiu       $t0, $t0, -0x21E0
    ctx->r8 = ADD32(ctx->r8, -0X21E0);
    // 0x801A748C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A7490: sll         $t1, $t8, 6
    ctx->r9 = S32(ctx->r24 << 6);
    // 0x801A7494: addu        $a1, $t1, $t0
    ctx->r5 = ADD32(ctx->r9, ctx->r8);
    // 0x801A7498: jal         0x80005680
    // 0x801A749C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Copy(rdram, ctx);
        goto after_7;
    // 0x801A749C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_7:
    // 0x801A74A0: jal         0x80006EB8
    // 0x801A74A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_8;
    // 0x801A74A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x801A74A8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801A74AC: lui         $t3, 0x600
    ctx->r11 = S32(0X600 << 16);
    // 0x801A74B0: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x801A74B4: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x801A74B8: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x801A74BC: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x801A74C0: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x801A74C4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A74C8: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x801A74CC: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x801A74D0: lw          $t6, 0x68F8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X68F8);
    // 0x801A74D4: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x801A74D8: jal         0x80005740
    // 0x801A74DC: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Pop(rdram, ctx);
        goto after_9;
    // 0x801A74DC: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_9:
    // 0x801A74E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801A74E4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x801A74E8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801A74EC: jr          $ra
    // 0x801A74F0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x801A74F0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void Map_8019E800(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019E800: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8019E804: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8019E808: jal         0x80006F20
    // 0x8019E80C: nop

    Memory_FreeAll(rdram, ctx);
        goto after_0;
    // 0x8019E80C: nop

    after_0:
    // 0x8019E810: jal         0x800A5D6C
    // 0x8019E814: nop

    Play_GenerateStarfield(rdram, ctx);
        goto after_1;
    // 0x8019E814: nop

    after_1:
    // 0x8019E818: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8019E81C: sw          $zero, -0x7BF0($at)
    MEM_W(-0X7BF0, ctx->r1) = 0;
    // 0x8019E820: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8019E824: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x8019E828: sh          $t6, 0x1A32($at)
    MEM_H(0X1A32, ctx->r1) = ctx->r14;
    // 0x8019E82C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8019E830: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x8019E834: sh          $t7, 0x1A34($at)
    MEM_H(0X1A34, ctx->r1) = ctx->r15;
    // 0x8019E838: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019E83C: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8019E840: sw          $t8, 0x7868($at)
    MEM_W(0X7868, ctx->r1) = ctx->r24;
    // 0x8019E844: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019E848: sw          $zero, 0x7898($at)
    MEM_W(0X7898, ctx->r1) = 0;
    // 0x8019E84C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8019E850: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8019E854: jr          $ra
    // 0x8019E858: nop

    return;
    // 0x8019E858: nop

;}
RECOMP_FUNC void Map_LevelStart_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A5E80: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801A5E84: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x801A5E88: addiu       $t0, $t0, -0x7D80
    ctx->r8 = ADD32(ctx->r8, -0X7D80);
    // 0x801A5E8C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801A5E90: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x801A5E94: sltiu       $at, $v1, 0x6
    ctx->r1 = ctx->r3 < 0X6 ? 1 : 0;
    // 0x801A5E98: beq         $at, $zero, L_801A61A4
    if (ctx->r1 == 0) {
        // 0x801A5E9C: sll         $t6, $v1, 2
        ctx->r14 = S32(ctx->r3 << 2);
            goto L_801A61A4;
    }
    // 0x801A5E9C: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x801A5EA0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A5EA4: addu        $at, $at, $t6
    gpr jr_addend_801A5EAC = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x801A5EA8: lw          $t6, 0x7810($at)
    ctx->r14 = ADD32(ctx->r1, 0X7810);
    // 0x801A5EAC: jr          $t6
    // 0x801A5EB0: nop

    switch (jr_addend_801A5EAC >> 2) {
        case 0: goto L_801A5EB4; break;
        case 1: goto L_801A5F00; break;
        case 2: goto L_801A606C; break;
        case 3: goto L_801A60D4; break;
        case 4: goto L_801A6104; break;
        case 5: goto L_801A616C; break;
        default: switch_error(__func__, 0x801A5EAC, 0x801B7810);
    }
    // 0x801A5EB0: nop

L_801A5EB4:
    // 0x801A5EB4: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801A5EB8: addiu       $a0, $a0, -0x7D7C
    ctx->r4 = ADD32(ctx->r4, -0X7D7C);
    // 0x801A5EBC: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x801A5EC0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801A5EC4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A5EC8: jal         0x801A6368
    // 0x801A5ECC: sw          $t7, -0x2660($at)
    MEM_W(-0X2660, ctx->r1) = ctx->r15;
    Map_CurrentLevel_Setup(rdram, ctx);
        goto after_0;
    // 0x801A5ECC: sw          $t7, -0x2660($at)
    MEM_W(-0X2660, ctx->r1) = ctx->r15;
    after_0:
    // 0x801A5ED0: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x801A5ED4: jal         0x801A62FC
    // 0x801A5ED8: lw          $a0, -0x26AC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X26AC);
    Map_LevelPlayedStatus_Check(rdram, ctx);
        goto after_1;
    // 0x801A5ED8: lw          $a0, -0x26AC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X26AC);
    after_1:
    // 0x801A5EDC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A5EE0: jal         0x801AB284
    // 0x801A5EE4: sw          $v0, -0x2658($at)
    MEM_W(-0X2658, ctx->r1) = ctx->r2;
    Map_BriefingRadio_Setup(rdram, ctx);
        goto after_2;
    // 0x801A5EE4: sw          $v0, -0x2658($at)
    MEM_W(-0X2658, ctx->r1) = ctx->r2;
    after_2:
    // 0x801A5EE8: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x801A5EEC: addiu       $t0, $t0, -0x7D80
    ctx->r8 = ADD32(ctx->r8, -0X7D80);
    // 0x801A5EF0: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x801A5EF4: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x801A5EF8: b           L_801A61A4
    // 0x801A5EFC: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
        goto L_801A61A4;
    // 0x801A5EFC: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
L_801A5F00:
    // 0x801A5F00: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x801A5F04: lw          $t2, 0x7AF8($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7AF8);
    // 0x801A5F08: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x801A5F0C: lui         $t5, 0x801D
    ctx->r13 = S32(0X801D << 16);
    // 0x801A5F10: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x801A5F14: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x801A5F18: sll         $t3, $t3, 1
    ctx->r11 = S32(ctx->r11 << 1);
    // 0x801A5F1C: addu        $v0, $v0, $t3
    ctx->r2 = ADD32(ctx->r2, ctx->r11);
    // 0x801A5F20: lhu         $v0, -0x2768($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X2768);
    // 0x801A5F24: andi        $t4, $v0, 0x1000
    ctx->r12 = ctx->r2 & 0X1000;
    // 0x801A5F28: beq         $t4, $zero, L_801A5F94
    if (ctx->r12 == 0) {
        // 0x801A5F2C: nop
    
            goto L_801A5F94;
    }
    // 0x801A5F2C: nop

    // 0x801A5F30: lw          $t5, -0x2658($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2658);
    // 0x801A5F34: lui         $a0, 0x4100
    ctx->r4 = S32(0X4100 << 16);
    // 0x801A5F38: bne         $t5, $zero, L_801A5F94
    if (ctx->r13 != 0) {
        // 0x801A5F3C: nop
    
            goto L_801A5F94;
    }
    // 0x801A5F3C: nop

    // 0x801A5F40: jal         0x8001A838
    // 0x801A5F44: ori         $a0, $a0, 0x1E
    ctx->r4 = ctx->r4 | 0X1E;
    Audio_KillSfxById(rdram, ctx);
        goto after_3;
    // 0x801A5F44: ori         $a0, $a0, 0x1E
    ctx->r4 = ctx->r4 | 0X1E;
    after_3:
    // 0x801A5F48: jal         0x8001AE58
    // 0x801A5F4C: nop

    Audio_ClearVoice(rdram, ctx);
        goto after_4;
    // 0x801A5F4C: nop

    after_4:
    // 0x801A5F50: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A5F54: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x801A5F58: lui         $t1, 0x801D
    ctx->r9 = S32(0X801D << 16);
    // 0x801A5F5C: sw          $zero, -0xFE8($at)
    MEM_W(-0XFE8, ctx->r1) = 0;
    // 0x801A5F60: addiu       $t1, $t1, -0x2648
    ctx->r9 = ADD32(ctx->r9, -0X2648);
    // 0x801A5F64: addiu       $t0, $t0, -0x7D80
    ctx->r8 = ADD32(ctx->r8, -0X7D80);
    // 0x801A5F68: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x801A5F6C: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x801A5F70: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
    // 0x801A5F74: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x801A5F78: lw          $t7, 0x7AF8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7AF8);
    // 0x801A5F7C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x801A5F80: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x801A5F84: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x801A5F88: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x801A5F8C: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
    // 0x801A5F90: lhu         $v0, -0x2768($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X2768);
L_801A5F94:
    // 0x801A5F94: lui         $t1, 0x801D
    ctx->r9 = S32(0X801D << 16);
    // 0x801A5F98: andi        $v1, $v0, 0x8000
    ctx->r3 = ctx->r2 & 0X8000;
    // 0x801A5F9C: beq         $v1, $zero, L_801A6010
    if (ctx->r3 == 0) {
        // 0x801A5FA0: addiu       $t1, $t1, -0x2648
        ctx->r9 = ADD32(ctx->r9, -0X2648);
            goto L_801A6010;
    }
    // 0x801A5FA0: addiu       $t1, $t1, -0x2648
    ctx->r9 = ADD32(ctx->r9, -0X2648);
    // 0x801A5FA4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801A5FA8: addiu       $v0, $v0, -0x2660
    ctx->r2 = ADD32(ctx->r2, -0X2660);
    // 0x801A5FAC: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x801A5FB0: lui         $t2, 0x801D
    ctx->r10 = S32(0X801D << 16);
    // 0x801A5FB4: bne         $t9, $zero, L_801A6010
    if (ctx->r25 != 0) {
        // 0x801A5FB8: nop
    
            goto L_801A6010;
    }
    // 0x801A5FB8: nop

    // 0x801A5FBC: lw          $t2, -0x2658($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2658);
    // 0x801A5FC0: bne         $t2, $zero, L_801A6010
    if (ctx->r10 != 0) {
        // 0x801A5FC4: nop
    
            goto L_801A6010;
    }
    // 0x801A5FC4: nop

    // 0x801A5FC8: jal         0x8001AE58
    // 0x801A5FCC: nop

    Audio_ClearVoice(rdram, ctx);
        goto after_5;
    // 0x801A5FCC: nop

    after_5:
    // 0x801A5FD0: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x801A5FD4: lw          $t3, 0x7AF8($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7AF8);
    // 0x801A5FD8: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x801A5FDC: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x801A5FE0: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x801A5FE4: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x801A5FE8: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x801A5FEC: addu        $v1, $v1, $t4
    ctx->r3 = ADD32(ctx->r3, ctx->r12);
    // 0x801A5FF0: lhu         $v1, -0x2768($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X2768);
    // 0x801A5FF4: lui         $t1, 0x801D
    ctx->r9 = S32(0X801D << 16);
    // 0x801A5FF8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801A5FFC: andi        $t5, $v1, 0x8000
    ctx->r13 = ctx->r3 & 0X8000;
    // 0x801A6000: addiu       $t1, $t1, -0x2648
    ctx->r9 = ADD32(ctx->r9, -0X2648);
    // 0x801A6004: addiu       $t0, $t0, -0x7D80
    ctx->r8 = ADD32(ctx->r8, -0X7D80);
    // 0x801A6008: or          $v1, $t5, $zero
    ctx->r3 = ctx->r13 | 0;
    // 0x801A600C: sw          $zero, -0x7D54($at)
    MEM_W(-0X7D54, ctx->r1) = 0;
L_801A6010:
    // 0x801A6010: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801A6014: beq         $v1, $zero, L_801A6040
    if (ctx->r3 == 0) {
        // 0x801A6018: addiu       $v0, $v0, -0x2660
        ctx->r2 = ADD32(ctx->r2, -0X2660);
            goto L_801A6040;
    }
    // 0x801A6018: addiu       $v0, $v0, -0x2660
    ctx->r2 = ADD32(ctx->r2, -0X2660);
    // 0x801A601C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801A6020: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801A6024: lui         $t7, 0x801D
    ctx->r15 = S32(0X801D << 16);
    // 0x801A6028: bne         $t6, $at, L_801A6040
    if (ctx->r14 != ctx->r1) {
        // 0x801A602C: nop
    
            goto L_801A6040;
    }
    // 0x801A602C: nop

    // 0x801A6030: lw          $t7, -0x2658($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2658);
    // 0x801A6034: bne         $t7, $zero, L_801A6040
    if (ctx->r15 != 0) {
        // 0x801A6038: nop
    
            goto L_801A6040;
    }
    // 0x801A6038: nop

    // 0x801A603C: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
L_801A6040:
    // 0x801A6040: lui         $t8, 0x801D
    ctx->r24 = S32(0X801D << 16);
    // 0x801A6044: lw          $t8, -0xFE8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0XFE8);
    // 0x801A6048: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x801A604C: bnel        $t8, $at, L_801A61A8
    if (ctx->r24 != ctx->r1) {
        // 0x801A6050: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801A61A8;
    }
    goto skip_0;
    // 0x801A6050: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x801A6054: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x801A6058: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x801A605C: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x801A6060: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x801A6064: b           L_801A61A4
    // 0x801A6068: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
        goto L_801A61A4;
    // 0x801A6068: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
L_801A606C:
    // 0x801A606C: lui         $t1, 0x801D
    ctx->r9 = S32(0X801D << 16);
    // 0x801A6070: addiu       $t1, $t1, -0x2648
    ctx->r9 = ADD32(ctx->r9, -0X2648);
    // 0x801A6074: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x801A6078: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801A607C: addiu       $a0, $a0, -0x7D7C
    ctx->r4 = ADD32(ctx->r4, -0X7D7C);
    // 0x801A6080: bnel        $t4, $zero, L_801A61A8
    if (ctx->r12 != 0) {
        // 0x801A6084: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801A61A8;
    }
    goto skip_1;
    // 0x801A6084: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x801A6088: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x801A608C: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x801A6090: addiu       $t8, $v1, 0x1
    ctx->r24 = ADD32(ctx->r3, 0X1);
    // 0x801A6094: slti        $at, $v0, 0x78
    ctx->r1 = SIGNED(ctx->r2) < 0X78 ? 1 : 0;
    // 0x801A6098: beq         $at, $zero, L_801A60C0
    if (ctx->r1 == 0) {
        // 0x801A609C: addiu       $t5, $v0, 0xF
        ctx->r13 = ADD32(ctx->r2, 0XF);
            goto L_801A60C0;
    }
    // 0x801A609C: addiu       $t5, $v0, 0xF
    ctx->r13 = ADD32(ctx->r2, 0XF);
    // 0x801A60A0: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x801A60A4: lui         $t6, 0x801D
    ctx->r14 = S32(0X801D << 16);
    // 0x801A60A8: lw          $t6, -0x26AC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X26AC);
    // 0x801A60AC: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x801A60B0: bne         $t6, $at, L_801A61A4
    if (ctx->r14 != ctx->r1) {
        // 0x801A60B4: lui         $at, 0x801D
        ctx->r1 = S32(0X801D << 16);
            goto L_801A61A4;
    }
    // 0x801A60B4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A60B8: b           L_801A61A4
    // 0x801A60BC: sw          $zero, -0x14B8($at)
    MEM_W(-0X14B8, ctx->r1) = 0;
        goto L_801A61A4;
    // 0x801A60BC: sw          $zero, -0x14B8($at)
    MEM_W(-0X14B8, ctx->r1) = 0;
L_801A60C0:
    // 0x801A60C0: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x801A60C4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A60C8: sw          $zero, -0xFE8($at)
    MEM_W(-0XFE8, ctx->r1) = 0;
    // 0x801A60CC: b           L_801A61A4
    // 0x801A60D0: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
        goto L_801A61A4;
    // 0x801A60D0: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
L_801A60D4:
    // 0x801A60D4: lui         $t1, 0x801D
    ctx->r9 = S32(0X801D << 16);
    // 0x801A60D8: addiu       $t1, $t1, -0x2648
    ctx->r9 = ADD32(ctx->r9, -0X2648);
    // 0x801A60DC: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x801A60E0: addiu       $t2, $zero, 0x5
    ctx->r10 = ADD32(0, 0X5);
    // 0x801A60E4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x801A60E8: bne         $t9, $zero, L_801A61A4
    if (ctx->r25 != 0) {
        // 0x801A60EC: lui         $at, 0x801D
        ctx->r1 = S32(0X801D << 16);
            goto L_801A61A4;
    }
    // 0x801A60EC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A60F0: sw          $t2, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r10;
    // 0x801A60F4: sw          $t3, -0x2698($at)
    MEM_W(-0X2698, ctx->r1) = ctx->r11;
    // 0x801A60F8: addiu       $t4, $v1, 0x1
    ctx->r12 = ADD32(ctx->r3, 0X1);
    // 0x801A60FC: b           L_801A61A4
    // 0x801A6100: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
        goto L_801A61A4;
    // 0x801A6100: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
L_801A6104:
    // 0x801A6104: lui         $t1, 0x801D
    ctx->r9 = S32(0X801D << 16);
    // 0x801A6108: addiu       $t1, $t1, -0x2648
    ctx->r9 = ADD32(ctx->r9, -0X2648);
    // 0x801A610C: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x801A6110: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x801A6114: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x801A6118: bne         $t5, $zero, L_801A61A4
    if (ctx->r13 != 0) {
        // 0x801A611C: lui         $a0, 0x4900
        ctx->r4 = S32(0X4900 << 16);
            goto L_801A61A4;
    }
    // 0x801A611C: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x801A6120: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x801A6124: addiu       $t6, $t6, 0x5D3C
    ctx->r14 = ADD32(ctx->r14, 0X5D3C);
    // 0x801A6128: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x801A612C: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x801A6130: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x801A6134: ori         $a0, $a0, 0x2016
    ctx->r4 = ctx->r4 | 0X2016;
    // 0x801A6138: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x801A613C: jal         0x80019218
    // 0x801A6140: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    Audio_PlaySfx(rdram, ctx);
        goto after_6;
    // 0x801A6140: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_6:
    // 0x801A6144: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x801A6148: addiu       $t0, $t0, -0x7D80
    ctx->r8 = ADD32(ctx->r8, -0X7D80);
    // 0x801A614C: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x801A6150: lui         $t1, 0x801D
    ctx->r9 = S32(0X801D << 16);
    // 0x801A6154: addiu       $t1, $t1, -0x2648
    ctx->r9 = ADD32(ctx->r9, -0X2648);
    // 0x801A6158: addiu       $t7, $zero, 0x4B
    ctx->r15 = ADD32(0, 0X4B);
    // 0x801A615C: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x801A6160: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x801A6164: b           L_801A61A4
    // 0x801A6168: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
        goto L_801A61A4;
    // 0x801A6168: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
L_801A616C:
    // 0x801A616C: lui         $t1, 0x801D
    ctx->r9 = S32(0X801D << 16);
    // 0x801A6170: addiu       $t1, $t1, -0x2648
    ctx->r9 = ADD32(ctx->r9, -0X2648);
    // 0x801A6174: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x801A6178: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x801A617C: bnel        $t2, $zero, L_801A61A8
    if (ctx->r10 != 0) {
        // 0x801A6180: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801A61A8;
    }
    goto skip_2;
    // 0x801A6180: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x801A6184: jal         0x801A61B4
    // 0x801A6188: lw          $a0, -0x7DCC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7DCC);
    Map_LevelStart_AudioSpecSetup(rdram, ctx);
        goto after_7;
    // 0x801A6188: lw          $a0, -0x7DCC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7DCC);
    after_7:
    // 0x801A618C: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x801A6190: addiu       $t0, $t0, -0x7D80
    ctx->r8 = ADD32(ctx->r8, -0X7D80);
    // 0x801A6194: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    // 0x801A6198: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A619C: jal         0x801A6628
    // 0x801A61A0: sw          $zero, -0x2698($at)
    MEM_W(-0X2698, ctx->r1) = 0;
    Map_PlayLevel(rdram, ctx);
        goto after_8;
    // 0x801A61A0: sw          $zero, -0x2698($at)
    MEM_W(-0X2698, ctx->r1) = 0;
    after_8:
L_801A61A4:
    // 0x801A61A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801A61A8:
    // 0x801A61A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801A61AC: jr          $ra
    // 0x801A61B0: nop

    return;
    // 0x801A61B0: nop

;}
RECOMP_FUNC void Map_VenomCloud_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A7BEC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801A7BF0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801A7BF4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801A7BF8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x801A7BFC: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x801A7C00: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x801A7C04: lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // 0x801A7C08: lw          $a2, -0x864($v0)
    ctx->r6 = MEM_W(ctx->r2, -0X864);
    // 0x801A7C0C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x801A7C10: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x801A7C14: slti        $at, $a2, 0x81
    ctx->r1 = SIGNED(ctx->r6) < 0X81 ? 1 : 0;
    // 0x801A7C18: bne         $at, $zero, L_801A7C24
    if (ctx->r1 != 0) {
        // 0x801A7C1C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_801A7C24;
    }
    // 0x801A7C1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801A7C20: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
L_801A7C24:
    // 0x801A7C24: addiu       $a1, $zero, 0x43
    ctx->r5 = ADD32(0, 0X43);
    // 0x801A7C28: jal         0x800B8DD0
    // 0x801A7C2C: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x801A7C2C: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    after_0:
    // 0x801A7C30: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x801A7C34: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801A7C38: lui         $at, 0x3F5F
    ctx->r1 = S32(0X3F5F << 16);
    // 0x801A7C3C: ori         $at, $at, 0x1E00
    ctx->r1 = ctx->r1 | 0X1E00;
    // 0x801A7C40: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801A7C44: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x801A7C48: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x801A7C4C: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x801A7C50: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x801A7C54: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801A7C58: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x801A7C5C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801A7C60: lui         $t1, 0xFB00
    ctx->r9 = S32(0XFB00 << 16);
    // 0x801A7C64: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A7C68: addiu       $t0, $v0, 0x8
    ctx->r8 = ADD32(ctx->r2, 0X8);
    // 0x801A7C6C: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x801A7C70: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801A7C74: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x801A7C78: jal         0x80005708
    // 0x801A7C7C: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Push(rdram, ctx);
        goto after_1;
    // 0x801A7C7C: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_1:
    // 0x801A7C80: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A7C84: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801A7C88: addiu       $a1, $a1, -0x1EA0
    ctx->r5 = ADD32(ctx->r5, -0X1EA0);
    // 0x801A7C8C: jal         0x80005680
    // 0x801A7C90: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Copy(rdram, ctx);
        goto after_2;
    // 0x801A7C90: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_2:
    // 0x801A7C94: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x801A7C98: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A7C9C: lwc1        $f6, 0x7998($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7998);
    // 0x801A7CA0: lwc1        $f4, 0x0($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X0);
    // 0x801A7CA4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A7CA8: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x801A7CAC: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x801A7CB0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801A7CB4: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x801A7CB8: jal         0x80005FE0
    // 0x801A7CBC: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_3;
    // 0x801A7CBC: nop

    after_3:
    // 0x801A7CC0: lwc1        $f0, 0x38($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X38);
    // 0x801A7CC4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A7CC8: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x801A7CCC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801A7CD0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801A7CD4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x801A7CD8: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x801A7CDC: jal         0x80005C34
    // 0x801A7CE0: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Scale(rdram, ctx);
        goto after_4;
    // 0x801A7CE0: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_4:
    // 0x801A7CE4: jal         0x80006EB8
    // 0x801A7CE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_5;
    // 0x801A7CE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x801A7CEC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801A7CF0: lui         $t6, 0x604
    ctx->r14 = S32(0X604 << 16);
    // 0x801A7CF4: addiu       $t6, $t6, 0x7E70
    ctx->r14 = ADD32(ctx->r14, 0X7E70);
    // 0x801A7CF8: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x801A7CFC: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x801A7D00: lui         $t5, 0x600
    ctx->r13 = S32(0X600 << 16);
    // 0x801A7D04: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x801A7D08: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x801A7D0C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A7D10: jal         0x80005740
    // 0x801A7D14: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Pop(rdram, ctx);
        goto after_6;
    // 0x801A7D14: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_6:
    // 0x801A7D18: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x801A7D1C: lwc1        $f16, 0x34($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X34);
    // 0x801A7D20: lwc1        $f10, 0x0($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X0);
    // 0x801A7D24: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801A7D28: swc1        $f18, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f18.u32l;
    // 0x801A7D2C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801A7D30: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801A7D34: jr          $ra
    // 0x801A7D38: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x801A7D38: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void Option_RankingHitCount_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801984D0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801984D4: mtc1        $a3, $f12
    ctx->f12.u32l = ctx->r7;
    // 0x801984D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801984DC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801984E0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801984E4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x801984E8: lui         $at, 0x41B0
    ctx->r1 = S32(0X41B0 << 16);
    // 0x801984EC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801984F0: lui         $at, 0x4322
    ctx->r1 = S32(0X4322 << 16);
    // 0x801984F4: c.lt.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl < ctx->f12.fl;
    // 0x801984F8: nop

    // 0x801984FC: bc1fl       L_801985FC
    if (!c1cs) {
        // 0x80198500: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801985FC;
    }
    goto skip_0;
    // 0x80198500: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80198504: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80198508: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8019850C: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x80198510: c.lt.s      $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f12.fl < ctx->f6.fl;
    // 0x80198514: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    // 0x80198518: bc1fl       L_801985FC
    if (!c1cs) {
        // 0x8019851C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801985FC;
    }
    goto skip_1;
    // 0x8019851C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80198520: jal         0x800B8DD0
    // 0x80198524: swc1        $f12, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f12.u32l;
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x80198524: swc1        $f12, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x80198528: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x8019852C: addiu       $a3, $a3, 0x7E64
    ctx->r7 = ADD32(ctx->r7, 0X7E64);
    // 0x80198530: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x80198534: lui         $t8, 0xFFFF
    ctx->r24 = S32(0XFFFF << 16);
    // 0x80198538: ori         $t8, $t8, 0xFF
    ctx->r24 = ctx->r24 | 0XFF;
    // 0x8019853C: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80198540: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x80198544: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x80198548: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8019854C: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80198550: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80198554: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80198558: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8019855C: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x80198560: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x80198564: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
    // 0x80198568: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x8019856C: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x80198570: addiu       $t4, $t4, -0x7790
    ctx->r12 = ADD32(ctx->r12, -0X7790);
    // 0x80198574: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    // 0x80198578: lhu         $a2, 0x5E($a1)
    ctx->r6 = MEM_HU(ctx->r5, 0X5E);
    // 0x8019857C: lbu         $t9, 0x5E($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X5E);
    // 0x80198580: sll         $t5, $a2, 28
    ctx->r13 = S32(ctx->r6 << 28);
    // 0x80198584: srl         $t6, $t5, 31
    ctx->r14 = S32(U32(ctx->r13) >> 31);
    // 0x80198588: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x8019858C: sll         $a2, $t7, 8
    ctx->r6 = S32(ctx->r15 << 8);
    // 0x80198590: or          $a0, $a2, $t9
    ctx->r4 = ctx->r6 | ctx->r25;
    // 0x80198594: jal         0x8008BCBC
    // 0x80198598: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    HUD_CountDigits(rdram, ctx);
        goto after_1;
    // 0x80198598: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_1:
    // 0x8019859C: sll         $t1, $v0, 3
    ctx->r9 = S32(ctx->r2 << 3);
    // 0x801985A0: addiu       $t0, $t1, -0x8
    ctx->r8 = ADD32(ctx->r9, -0X8);
    // 0x801985A4: mtc1        $t0, $f18
    ctx->f18.u32l = ctx->r8;
    // 0x801985A8: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x801985AC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801985B0: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801985B4: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x801985B8: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x801985BC: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801985C0: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x801985C4: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801985C8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801985CC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801985D0: sub.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x801985D4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801985D8: add.s       $f18, $f12, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f12.fl + ctx->f10.fl;
    // 0x801985DC: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x801985E0: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x801985E4: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x801985E8: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x801985EC: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x801985F0: jal         0x8009FEA0
    // 0x801985F4: nop

    Graphics_DisplaySmallNumber(rdram, ctx);
        goto after_2;
    // 0x801985F4: nop

    after_2:
    // 0x801985F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801985FC:
    // 0x801985FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80198600: jr          $ra
    // 0x80198604: nop

    return;
    // 0x80198604: nop

;}
RECOMP_FUNC void Title_Main(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80187754: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80187758: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8018775C: addiu       $v1, $v1, 0x7AE0
    ctx->r3 = ADD32(ctx->r3, 0X7AE0);
    // 0x80187760: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80187764: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80187768: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8018776C: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x80187770: beq         $v0, $zero, L_80187794
    if (ctx->r2 == 0) {
        // 0x80187774: nop
    
            goto L_80187794;
    }
    // 0x80187774: nop

    // 0x80187778: beq         $v0, $a0, L_801877B4
    if (ctx->r2 == ctx->r4) {
        // 0x8018777C: lui         $at, 0x8017
        ctx->r1 = S32(0X8017 << 16);
            goto L_801877B4;
    }
    // 0x8018777C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80187780: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80187784: beq         $v0, $at, L_801877C4
    if (ctx->r2 == ctx->r1) {
        // 0x80187788: nop
    
            goto L_801877C4;
    }
    // 0x80187788: nop

    // 0x8018778C: b           L_801877D0
    // 0x80187790: nop

        goto L_801877D0;
    // 0x80187790: nop

L_80187794:
    // 0x80187794: lw          $t6, 0x783C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X783C);
    // 0x80187798: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8018779C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801877A0: bne         $t6, $zero, L_801877D0
    if (ctx->r14 != 0) {
        // 0x801877A4: nop
    
            goto L_801877D0;
    }
    // 0x801877A4: nop

    // 0x801877A8: sw          $zero, 0x7898($at)
    MEM_W(0X7898, ctx->r1) = 0;
    // 0x801877AC: b           L_801877D0
    // 0x801877B0: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
        goto L_801877D0;
    // 0x801877B0: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
L_801877B4:
    // 0x801877B4: jal         0x801875E0
    // 0x801877B8: sw          $zero, 0x7898($at)
    MEM_W(0X7898, ctx->r1) = 0;
    Title_Setup(rdram, ctx);
        goto after_0;
    // 0x801877B8: sw          $zero, 0x7898($at)
    MEM_W(0X7898, ctx->r1) = 0;
    after_0:
    // 0x801877BC: b           L_801877D0
    // 0x801877C0: nop

        goto L_801877D0;
    // 0x801877C0: nop

L_801877C4:
    // 0x801877C4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801877C8: jal         0x801877F0
    // 0x801877CC: sw          $a0, 0x7898($at)
    MEM_W(0X7898, ctx->r1) = ctx->r4;
    Title_UpdateEntry(rdram, ctx);
        goto after_1;
    // 0x801877CC: sw          $a0, 0x7898($at)
    MEM_W(0X7898, ctx->r1) = ctx->r4;
    after_1:
L_801877D0:
    // 0x801877D0: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x801877D4: addiu       $v0, $v0, 0x7DB0
    ctx->r2 = ADD32(ctx->r2, 0X7DB0);
    // 0x801877D8: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x801877DC: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x801877E0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x801877E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801877E8: jr          $ra
    // 0x801877EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801877EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void Map_GameOver_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A36A8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801A36AC: lui         $t2, 0x801D
    ctx->r10 = S32(0X801D << 16);
    // 0x801A36B0: addiu       $t2, $t2, -0x26B8
    ctx->r10 = ADD32(ctx->r10, -0X26B8);
    // 0x801A36B4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801A36B8: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x801A36BC: sltiu       $at, $v0, 0x15
    ctx->r1 = ctx->r2 < 0X15 ? 1 : 0;
    // 0x801A36C0: beq         $at, $zero, L_801A398C
    if (ctx->r1 == 0) {
        // 0x801A36C4: sll         $t6, $v0, 2
        ctx->r14 = S32(ctx->r2 << 2);
            goto L_801A398C;
    }
    // 0x801A36C4: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x801A36C8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A36CC: addu        $at, $at, $t6
    gpr jr_addend_801A36D4 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x801A36D0: lw          $t6, 0x7730($at)
    ctx->r14 = ADD32(ctx->r1, 0X7730);
    // 0x801A36D4: jr          $t6
    // 0x801A36D8: nop

    switch (jr_addend_801A36D4 >> 2) {
        case 0: goto L_801A36DC; break;
        case 1: goto L_801A38D0; break;
        case 2: goto L_801A391C; break;
        case 3: goto L_801A392C; break;
        case 4: goto L_801A395C; break;
        case 5: goto L_801A398C; break;
        case 6: goto L_801A398C; break;
        case 7: goto L_801A398C; break;
        case 8: goto L_801A398C; break;
        case 9: goto L_801A398C; break;
        case 10: goto L_801A3834; break;
        case 11: goto L_801A398C; break;
        case 12: goto L_801A398C; break;
        case 13: goto L_801A398C; break;
        case 14: goto L_801A398C; break;
        case 15: goto L_801A398C; break;
        case 16: goto L_801A398C; break;
        case 17: goto L_801A398C; break;
        case 18: goto L_801A398C; break;
        case 19: goto L_801A398C; break;
        case 20: goto L_801A38A4; break;
        default: switch_error(__func__, 0x801A36D4, 0x801B7730);
    }
    // 0x801A36D8: nop

L_801A36DC:
    // 0x801A36DC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801A36E0: sw          $zero, -0x7CB8($at)
    MEM_W(-0X7CB8, ctx->r1) = 0;
    // 0x801A36E4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801A36E8: sw          $zero, -0x7CB0($at)
    MEM_W(-0X7CB0, ctx->r1) = 0;
    // 0x801A36EC: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x801A36F0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801A36F4: addiu       $t0, $t0, -0x7CC0
    ctx->r8 = ADD32(ctx->r8, -0X7CC0);
    // 0x801A36F8: sw          $zero, -0x7CAC($at)
    MEM_W(-0X7CAC, ctx->r1) = 0;
    // 0x801A36FC: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x801A3700: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x801A3704: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x801A3708: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801A370C: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x801A3710: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801A3714: lui         $a2, 0x801B
    ctx->r6 = S32(0X801B << 16);
    // 0x801A3718: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801A371C: lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // 0x801A3720: addiu       $v0, $v0, 0x6A14
    ctx->r2 = ADD32(ctx->r2, 0X6A14);
    // 0x801A3724: addiu       $a3, $a3, -0xFA0
    ctx->r7 = ADD32(ctx->r7, -0XFA0);
    // 0x801A3728: addiu       $a2, $a2, 0x69F4
    ctx->r6 = ADD32(ctx->r6, 0X69F4);
    // 0x801A372C: addiu       $a1, $a1, -0xFC0
    ctx->r5 = ADD32(ctx->r5, -0XFC0);
    // 0x801A3730: addiu       $a0, $a0, 0x69D4
    ctx->r4 = ADD32(ctx->r4, 0X69D4);
    // 0x801A3734: addiu       $v1, $v1, -0xFE0
    ctx->r3 = ADD32(ctx->r3, -0XFE0);
    // 0x801A3738: addiu       $t0, $t0, 0x6A34
    ctx->r8 = ADD32(ctx->r8, 0X6A34);
L_801A373C:
    // 0x801A373C: lwc1        $f10, 0x4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X4);
    // 0x801A3740: lwc1        $f16, 0x4($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X4);
    // 0x801A3744: lwc1        $f18, 0x4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801A3748: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x801A374C: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    // 0x801A3750: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801A3754: swc1        $f10, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f10.u32l;
    // 0x801A3758: swc1        $f16, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f16.u32l;
    // 0x801A375C: swc1        $f18, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f18.u32l;
    // 0x801A3760: swc1        $f4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f4.u32l;
    // 0x801A3764: swc1        $f6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f6.u32l;
    // 0x801A3768: swc1        $f8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f8.u32l;
    // 0x801A376C: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801A3770: lwc1        $f6, 0x8($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X8);
    // 0x801A3774: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x801A3778: lwc1        $f18, 0xC($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0XC);
    // 0x801A377C: lwc1        $f16, 0xC($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0XC);
    // 0x801A3780: lwc1        $f10, 0xC($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0XC);
    // 0x801A3784: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x801A3788: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x801A378C: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x801A3790: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x801A3794: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x801A3798: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x801A379C: swc1        $f8, -0x8($a3)
    MEM_W(-0X8, ctx->r7) = ctx->f8.u32l;
    // 0x801A37A0: swc1        $f6, -0x8($a1)
    MEM_W(-0X8, ctx->r5) = ctx->f6.u32l;
    // 0x801A37A4: swc1        $f4, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = ctx->f4.u32l;
    // 0x801A37A8: swc1        $f18, -0x4($a3)
    MEM_W(-0X4, ctx->r7) = ctx->f18.u32l;
    // 0x801A37AC: swc1        $f16, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->f16.u32l;
    // 0x801A37B0: bne         $v0, $t0, L_801A373C
    if (ctx->r2 != ctx->r8) {
        // 0x801A37B4: swc1        $f10, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->f10.u32l;
            goto L_801A373C;
    }
    // 0x801A37B4: swc1        $f10, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f10.u32l;
    // 0x801A37B8: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x801A37BC: lw          $t8, 0x6A38($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6A38);
    // 0x801A37C0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801A37C4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801A37C8: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x801A37CC: lw          $t9, 0x6A40($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6A40);
    // 0x801A37D0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A37D4: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x801A37D8: sw          $t8, -0xF38($at)
    MEM_W(-0XF38, ctx->r1) = ctx->r24;
    // 0x801A37DC: lw          $t3, 0x6A48($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X6A48);
    // 0x801A37E0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A37E4: sw          $t9, -0xF34($at)
    MEM_W(-0XF34, ctx->r1) = ctx->r25;
    // 0x801A37E8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A37EC: sw          $t3, -0xF30($at)
    MEM_W(-0XF30, ctx->r1) = ctx->r11;
    // 0x801A37F0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A37F4: sw          $zero, -0xEE0($at)
    MEM_W(-0XEE0, ctx->r1) = 0;
    // 0x801A37F8: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x801A37FC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801A3800: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A3804: addiu       $t4, $zero, 0xA
    ctx->r12 = ADD32(0, 0XA);
    // 0x801A3808: swc1        $f4, -0x1564($at)
    MEM_W(-0X1564, ctx->r1) = ctx->f4.u32l;
    // 0x801A380C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A3810: swc1        $f0, -0xF80($at)
    MEM_W(-0XF80, ctx->r1) = ctx->f0.u32l;
    // 0x801A3814: sw          $t4, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r12;
    // 0x801A3818: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801A381C: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    // 0x801A3820: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801A3824: jal         0x8001D444
    // 0x801A3828: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    Audio_PlaySequence(rdram, ctx);
        goto after_0;
    // 0x801A3828: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_0:
    // 0x801A382C: b           L_801A398C
    // 0x801A3830: nop

        goto L_801A398C;
    // 0x801A3830: nop

L_801A3834:
    // 0x801A3834: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801A3838: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801A383C: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x801A3840: addiu       $a0, $a0, -0x1564
    ctx->r4 = ADD32(ctx->r4, -0X1564);
    // 0x801A3844: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801A3848: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x801A384C: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x801A3850: jal         0x8009BC2C
    // 0x801A3854: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_1;
    // 0x801A3854: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x801A3858: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A385C: lwc1        $f6, -0x1564($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X1564);
    // 0x801A3860: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801A3864: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x801A3868: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x801A386C: addiu       $t0, $t0, -0x7CC0
    ctx->r8 = ADD32(ctx->r8, -0X7CC0);
    // 0x801A3870: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801A3874: c.eq.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl == ctx->f10.fl;
    // 0x801A3878: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    // 0x801A387C: addiu       $v0, $v0, -0x2640
    ctx->r2 = ADD32(ctx->r2, -0X2640);
    // 0x801A3880: addiu       $t7, $zero, 0x14
    ctx->r15 = ADD32(0, 0X14);
    // 0x801A3884: bc1f        L_801A389C
    if (!c1cs) {
        // 0x801A3888: sw          $t6, 0x0($t0)
        MEM_W(0X0, ctx->r8) = ctx->r14;
            goto L_801A389C;
    }
    // 0x801A3888: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x801A388C: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    // 0x801A3890: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x801A3894: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A3898: sw          $t7, -0x26B8($at)
    MEM_W(-0X26B8, ctx->r1) = ctx->r15;
L_801A389C:
    // 0x801A389C: b           L_801A398C
    // 0x801A38A0: nop

        goto L_801A398C;
    // 0x801A38A0: nop

L_801A38A4:
    // 0x801A38A4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801A38A8: addiu       $v0, $v0, -0x2640
    ctx->r2 = ADD32(ctx->r2, -0X2640);
    // 0x801A38AC: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x801A38B0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A38B4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801A38B8: bne         $t8, $zero, L_801A398C
    if (ctx->r24 != 0) {
        // 0x801A38BC: nop
    
            goto L_801A398C;
    }
    // 0x801A38BC: nop

    // 0x801A38C0: sw          $zero, -0x26B4($at)
    MEM_W(-0X26B4, ctx->r1) = 0;
    // 0x801A38C4: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x801A38C8: b           L_801A398C
    // 0x801A38CC: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
        goto L_801A398C;
    // 0x801A38CC: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
L_801A38D0:
    // 0x801A38D0: lui         $t3, 0x801D
    ctx->r11 = S32(0X801D << 16);
    // 0x801A38D4: lw          $t3, -0xEE0($t3)
    ctx->r11 = MEM_W(ctx->r11, -0XEE0);
    // 0x801A38D8: beq         $t3, $zero, L_801A38F8
    if (ctx->r11 == 0) {
        // 0x801A38DC: lui         $v0, 0x801D
        ctx->r2 = S32(0X801D << 16);
            goto L_801A38F8;
    }
    // 0x801A38DC: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801A38E0: addiu       $v0, $v0, -0x25E4
    ctx->r2 = ADD32(ctx->r2, -0X25E4);
    // 0x801A38E4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A38E8: lwc1        $f18, 0x7784($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7784);
    // 0x801A38EC: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801A38F0: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x801A38F4: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
L_801A38F8:
    // 0x801A38F8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801A38FC: addiu       $v0, $v0, -0x2640
    ctx->r2 = ADD32(ctx->r2, -0X2640);
    // 0x801A3900: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x801A3904: bne         $t4, $zero, L_801A398C
    if (ctx->r12 != 0) {
        // 0x801A3908: nop
    
            goto L_801A398C;
    }
    // 0x801A3908: nop

    // 0x801A390C: jal         0x801A3A00
    // 0x801A3910: nop

    Map_GameOver_3DFont(rdram, ctx);
        goto after_2;
    // 0x801A3910: nop

    after_2:
    // 0x801A3914: b           L_801A398C
    // 0x801A3918: nop

        goto L_801A398C;
    // 0x801A3918: nop

L_801A391C:
    // 0x801A391C: jal         0x801A4394
    // 0x801A3920: nop

    Map_801A4394(rdram, ctx);
        goto after_3;
    // 0x801A3920: nop

    after_3:
    // 0x801A3924: b           L_801A398C
    // 0x801A3928: nop

        goto L_801A398C;
    // 0x801A3928: nop

L_801A392C:
    // 0x801A392C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x801A3930: addiu       $t0, $t0, -0x7CC0
    ctx->r8 = ADD32(ctx->r8, -0X7CC0);
    // 0x801A3934: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x801A3938: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x801A393C: addiu       $t9, $v0, 0x1
    ctx->r25 = ADD32(ctx->r2, 0X1);
    // 0x801A3940: addiu       $t6, $t5, 0x20
    ctx->r14 = ADD32(ctx->r13, 0X20);
    // 0x801A3944: slti        $at, $t6, 0x100
    ctx->r1 = SIGNED(ctx->r14) < 0X100 ? 1 : 0;
    // 0x801A3948: bne         $at, $zero, L_801A398C
    if (ctx->r1 != 0) {
        // 0x801A394C: sw          $t6, 0x0($t0)
        MEM_W(0X0, ctx->r8) = ctx->r14;
            goto L_801A398C;
    }
    // 0x801A394C: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x801A3950: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x801A3954: b           L_801A398C
    // 0x801A3958: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
        goto L_801A398C;
    // 0x801A3958: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
L_801A395C:
    // 0x801A395C: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x801A3960: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801A3964: sw          $t3, 0x7834($at)
    MEM_W(0X7834, ctx->r1) = ctx->r11;
    // 0x801A3968: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801A396C: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x801A3970: sw          $t4, 0x783C($at)
    MEM_W(0X783C, ctx->r1) = ctx->r12;
    // 0x801A3974: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801A3978: sw          $zero, 0x784C($at)
    MEM_W(0X784C, ctx->r1) = 0;
    // 0x801A397C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801A3980: sw          $zero, 0x7898($at)
    MEM_W(0X7898, ctx->r1) = 0;
    // 0x801A3984: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801A3988: sw          $zero, -0x7BF0($at)
    MEM_W(-0X7BF0, ctx->r1) = 0;
L_801A398C:
    // 0x801A398C: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x801A3990: lw          $t5, 0x7AF8($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7AF8);
    // 0x801A3994: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x801A3998: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x801A399C: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x801A39A0: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x801A39A4: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x801A39A8: lhu         $t7, -0x2768($t7)
    ctx->r15 = MEM_HU(ctx->r15, -0X2768);
    // 0x801A39AC: andi        $t8, $t7, 0x9000
    ctx->r24 = ctx->r15 & 0X9000;
    // 0x801A39B0: beq         $t8, $zero, L_801A39F0
    if (ctx->r24 == 0) {
        // 0x801A39B4: lui         $a3, 0x800C
        ctx->r7 = S32(0X800C << 16);
            goto L_801A39F0;
    }
    // 0x801A39B4: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x801A39B8: lui         $t9, 0x800C
    ctx->r25 = S32(0X800C << 16);
    // 0x801A39BC: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x801A39C0: addiu       $t9, $t9, 0x5D3C
    ctx->r25 = ADD32(ctx->r25, 0X5D3C);
    // 0x801A39C4: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x801A39C8: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x801A39CC: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x801A39D0: ori         $a0, $a0, 0x3
    ctx->r4 = ctx->r4 | 0X3;
    // 0x801A39D4: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x801A39D8: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x801A39DC: jal         0x80019218
    // 0x801A39E0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_4;
    // 0x801A39E0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_4:
    // 0x801A39E4: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x801A39E8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A39EC: sw          $t3, -0x26B8($at)
    MEM_W(-0X26B8, ctx->r1) = ctx->r11;
L_801A39F0:
    // 0x801A39F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801A39F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801A39F8: jr          $ra
    // 0x801A39FC: nop

    return;
    // 0x801A39FC: nop

;}
RECOMP_FUNC void Option_Score_Update2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019DE74: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8019DE78: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8019DE7C: jal         0x8019715C
    // 0x8019DE80: nop

    Option_Ranking2_Cursor(rdram, ctx);
        goto after_0;
    // 0x8019DE80: nop

    after_0:
    // 0x8019DE84: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x8019DE88: lw          $t6, 0x7AF8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7AF8);
    // 0x8019DE8C: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8019DE90: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8019DE94: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8019DE98: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8019DE9C: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x8019DEA0: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8019DEA4: lhu         $t8, -0x2768($t8)
    ctx->r24 = MEM_HU(ctx->r24, -0X2768);
    // 0x8019DEA8: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x8019DEAC: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8019DEB0: andi        $t9, $t8, 0xD00E
    ctx->r25 = ctx->r24 & 0XD00E;
    // 0x8019DEB4: beq         $t9, $zero, L_8019DF54
    if (ctx->r25 == 0) {
        // 0x8019DEB8: ori         $a0, $a0, 0x3
        ctx->r4 = ctx->r4 | 0X3;
            goto L_8019DF54;
    }
    // 0x8019DEB8: ori         $a0, $a0, 0x3
    ctx->r4 = ctx->r4 | 0X3;
    // 0x8019DEBC: lui         $t0, 0x800C
    ctx->r8 = S32(0X800C << 16);
    // 0x8019DEC0: addiu       $t0, $t0, 0x5D3C
    ctx->r8 = ADD32(ctx->r8, 0X5D3C);
    // 0x8019DEC4: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x8019DEC8: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x8019DECC: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8019DED0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8019DED4: jal         0x80019218
    // 0x8019DED8: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    Audio_PlaySfx(rdram, ctx);
        goto after_1;
    // 0x8019DED8: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_1:
    // 0x8019DEDC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019DEE0: sw          $zero, 0x7898($at)
    MEM_W(0X7898, ctx->r1) = 0;
    // 0x8019DEE4: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8019DEE8: lhu         $v0, 0x1A34($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X1A34);
    // 0x8019DEEC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019DEF0: sw          $zero, -0x6ED4($at)
    MEM_W(-0X6ED4, ctx->r1) = 0;
    // 0x8019DEF4: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8019DEF8: bne         $v0, $at, L_8019DF28
    if (ctx->r2 != ctx->r1) {
        // 0x8019DEFC: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_8019DF28;
    }
    // 0x8019DEFC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8019DF00: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8019DF04: sw          $zero, -0x7BF0($at)
    MEM_W(-0X7BF0, ctx->r1) = 0;
    // 0x8019DF08: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019DF0C: sw          $t1, 0x7834($at)
    MEM_W(0X7834, ctx->r1) = ctx->r9;
    // 0x8019DF10: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8019DF14: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x8019DF18: sh          $t2, 0x1AA0($at)
    MEM_H(0X1AA0, ctx->r1) = ctx->r10;
    // 0x8019DF1C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8019DF20: b           L_8019DF54
    // 0x8019DF24: sw          $zero, 0x1714($at)
    MEM_W(0X1714, ctx->r1) = 0;
        goto L_8019DF54;
    // 0x8019DF24: sw          $zero, 0x1714($at)
    MEM_W(0X1714, ctx->r1) = 0;
L_8019DF28:
    // 0x8019DF28: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8019DF2C: bne         $v0, $at, L_8019DF54
    if (ctx->r2 != ctx->r1) {
        // 0x8019DF30: lui         $a0, 0x1001
        ctx->r4 = S32(0X1001 << 16);
            goto L_8019DF54;
    }
    // 0x8019DF30: lui         $a0, 0x1001
    ctx->r4 = S32(0X1001 << 16);
    // 0x8019DF34: jal         0x800182F4
    // 0x8019DF38: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_2;
    // 0x8019DF38: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    after_2:
    // 0x8019DF3C: lui         $a0, 0x1101
    ctx->r4 = S32(0X1101 << 16);
    // 0x8019DF40: jal         0x800182F4
    // 0x8019DF44: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_3;
    // 0x8019DF44: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    after_3:
    // 0x8019DF48: addiu       $t3, $zero, 0x190
    ctx->r11 = ADD32(0, 0X190);
    // 0x8019DF4C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019DF50: sw          $t3, -0x6EDC($at)
    MEM_W(-0X6EDC, ctx->r1) = ctx->r11;
L_8019DF54:
    // 0x8019DF54: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8019DF58: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8019DF5C: jr          $ra
    // 0x8019DF60: nop

    return;
    // 0x8019DF60: nop

;}
RECOMP_FUNC void Option_DrawMenuLabel(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019B9C0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8019B9C4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8019B9C8: jal         0x8019BDF0
    // 0x8019B9CC: nop

    Option_Menu_Push(rdram, ctx);
        goto after_0;
    // 0x8019B9CC: nop

    after_0:
    // 0x8019B9D0: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x8019B9D4: lw          $t6, -0x6E5C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6E5C);
    // 0x8019B9D8: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x8019B9DC: addiu       $t9, $t9, -0x19C8
    ctx->r25 = ADD32(ctx->r25, -0X19C8);
    // 0x8019B9E0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8019B9E4: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8019B9E8: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x8019B9EC: addiu       $t8, $t7, 0x38
    ctx->r24 = ADD32(ctx->r15, 0X38);
    // 0x8019B9F0: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8019B9F4: lw          $at, 0x0($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X0);
    // 0x8019B9F8: sw          $at, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r1;
    // 0x8019B9FC: lw          $t2, 0x4($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X4);
    // 0x8019BA00: lw          $a0, 0x0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X0);
    // 0x8019BA04: sw          $t2, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r10;
    // 0x8019BA08: lw          $at, 0x8($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X8);
    // 0x8019BA0C: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x8019BA10: sw          $at, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r1;
    // 0x8019BA14: lw          $a3, 0xC($t0)
    ctx->r7 = MEM_W(ctx->r8, 0XC);
    // 0x8019BA18: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x8019BA1C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8019BA20: lw          $at, 0x10($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X10);
    // 0x8019BA24: jal         0x8019BAB8
    // 0x8019BA28: sw          $at, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r1;
    Option_DrawMenuCard(rdram, ctx);
        goto after_1;
    // 0x8019BA28: sw          $at, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r1;
    after_1:
    // 0x8019BA2C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8019BA30: jal         0x80005740
    // 0x8019BA34: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Pop(rdram, ctx);
        goto after_2;
    // 0x8019BA34: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_2:
    // 0x8019BA38: lui         $t3, 0x801C
    ctx->r11 = S32(0X801C << 16);
    // 0x8019BA3C: lw          $t3, -0x6E5C($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X6E5C);
    // 0x8019BA40: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x8019BA44: addiu       $t5, $t5, -0x19C8
    ctx->r13 = ADD32(ctx->r13, -0X19C8);
    // 0x8019BA48: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8019BA4C: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x8019BA50: sll         $t4, $t4, 5
    ctx->r12 = S32(ctx->r12 << 5);
    // 0x8019BA54: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x8019BA58: addiu       $t8, $t6, 0x30
    ctx->r24 = ADD32(ctx->r14, 0X30);
    // 0x8019BA5C: or          $t9, $sp, $zero
    ctx->r25 = ctx->r29 | 0;
L_8019BA60:
    // 0x8019BA60: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x8019BA64: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x8019BA68: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x8019BA6C: sw          $at, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r1;
    // 0x8019BA70: lw          $at, -0x8($t6)
    ctx->r1 = MEM_W(ctx->r14, -0X8);
    // 0x8019BA74: sw          $at, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r1;
    // 0x8019BA78: lw          $at, -0x4($t6)
    ctx->r1 = MEM_W(ctx->r14, -0X4);
    // 0x8019BA7C: bne         $t6, $t8, L_8019BA60
    if (ctx->r14 != ctx->r24) {
        // 0x8019BA80: sw          $at, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r1;
            goto L_8019BA60;
    }
    // 0x8019BA80: sw          $at, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r1;
    // 0x8019BA84: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x8019BA88: sw          $at, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r1;
    // 0x8019BA8C: lw          $t8, 0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X4);
    // 0x8019BA90: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x8019BA94: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    // 0x8019BA98: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x8019BA9C: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x8019BAA0: jal         0x8019C120
    // 0x8019BAA4: lw          $a0, 0x0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X0);
    Option_DrawCardLabel(rdram, ctx);
        goto after_3;
    // 0x8019BAA4: lw          $a0, 0x0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X0);
    after_3:
    // 0x8019BAA8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8019BAAC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8019BAB0: jr          $ra
    // 0x8019BAB4: nop

    return;
    // 0x8019BAB4: nop

;}
RECOMP_FUNC void Title_CsGreatFoxTraveling_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018A2F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018A2FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018A300: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x8018A304: lw          $t6, -0x796C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X796C);
    // 0x8018A308: lui         $at, 0xC42F
    ctx->r1 = S32(0XC42F << 16);
    // 0x8018A30C: beq         $t6, $zero, L_8018A320
    if (ctx->r14 == 0) {
        // 0x8018A310: nop
    
            goto L_8018A320;
    }
    // 0x8018A310: nop

    // 0x8018A314: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8018A318: jal         0x8018DF0C
    // 0x8018A31C: nop

    Title_Corneria_Draw(rdram, ctx);
        goto after_0;
    // 0x8018A31C: nop

    after_0:
L_8018A320:
    // 0x8018A320: jal         0x8018E058
    // 0x8018A324: nop

    Title_GreatFox_Draw(rdram, ctx);
        goto after_1;
    // 0x8018A324: nop

    after_1:
    // 0x8018A328: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018A32C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018A330: jr          $ra
    // 0x8018A334: nop

    return;
    // 0x8018A334: nop

;}
RECOMP_FUNC void Map_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019FF48: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8019FF4C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8019FF50: jal         0x801A6694
    // 0x8019FF54: nop

    Map_PositionPlanets(rdram, ctx);
        goto after_0;
    // 0x8019FF54: nop

    after_0:
    // 0x8019FF58: jal         0x801A68E4
    // 0x8019FF5C: nop

    Map_PlanetOrderZpos(rdram, ctx);
        goto after_1;
    // 0x8019FF5C: nop

    after_1:
    // 0x8019FF60: jal         0x801A6A24
    // 0x8019FF64: nop

    Map_Fade_Update(rdram, ctx);
        goto after_2;
    // 0x8019FF64: nop

    after_2:
    // 0x8019FF68: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8019FF6C: lw          $v0, -0x26BC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X26BC);
    // 0x8019FF70: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8019FF74: addiu       $v1, $v1, -0x25E4
    ctx->r3 = ADD32(ctx->r3, -0X25E4);
    // 0x8019FF78: sltiu       $at, $v0, 0x8
    ctx->r1 = ctx->r2 < 0X8 ? 1 : 0;
    // 0x8019FF7C: beq         $at, $zero, L_801A00BC
    if (ctx->r1 == 0) {
        // 0x8019FF80: sll         $t6, $v0, 2
        ctx->r14 = S32(ctx->r2 << 2);
            goto L_801A00BC;
    }
    // 0x8019FF80: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x8019FF84: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8019FF88: addu        $at, $at, $t6
    gpr jr_addend_8019FF90 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8019FF8C: lw          $t6, 0x7594($at)
    ctx->r14 = ADD32(ctx->r1, 0X7594);
    // 0x8019FF90: jr          $t6
    // 0x8019FF94: nop

    switch (jr_addend_8019FF90 >> 2) {
        case 0: goto L_8019FF98; break;
        case 1: goto L_8019FFD0; break;
        case 2: goto L_801A0030; break;
        case 3: goto L_801A0000; break;
        case 4: goto L_801A004C; break;
        case 5: goto L_801A0068; break;
        case 6: goto L_801A0084; break;
        case 7: goto L_801A00A0; break;
        default: switch_error(__func__, 0x8019FF90, 0x801B7594);
    }
    // 0x8019FF94: nop

L_8019FF98:
    // 0x8019FF98: jal         0x801A0954
    // 0x8019FF9C: nop

    Map_Prologue_Update(rdram, ctx);
        goto after_3;
    // 0x8019FF9C: nop

    after_3:
    // 0x8019FFA0: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x8019FFA4: addiu       $v1, $v1, -0x7BD4
    ctx->r3 = ADD32(ctx->r3, -0X7BD4);
    // 0x8019FFA8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8019FFAC: lwc1        $f6, 0x75B4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X75B4);
    // 0x8019FFB0: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8019FFB4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8019FFB8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8019FFBC: swc1        $f8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f8.u32l;
    // 0x8019FFC0: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8019FFC4: addiu       $v1, $v1, -0x25E4
    ctx->r3 = ADD32(ctx->r3, -0X25E4);
    // 0x8019FFC8: b           L_801A00BC
    // 0x8019FFCC: lw          $v0, -0x26BC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X26BC);
        goto L_801A00BC;
    // 0x8019FFCC: lw          $v0, -0x26BC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X26BC);
L_8019FFD0:
    // 0x8019FFD0: jal         0x801A1528
    // 0x8019FFD4: nop

    Map_LylatCard_Update(rdram, ctx);
        goto after_4;
    // 0x8019FFD4: nop

    after_4:
    // 0x8019FFD8: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8019FFDC: addiu       $v1, $v1, -0x25E4
    ctx->r3 = ADD32(ctx->r3, -0X25E4);
    // 0x8019FFE0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8019FFE4: lwc1        $f16, 0x75B8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X75B8);
    // 0x8019FFE8: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8019FFEC: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8019FFF0: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8019FFF4: swc1        $f18, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f18.u32l;
    // 0x8019FFF8: b           L_801A00BC
    // 0x8019FFFC: lw          $v0, -0x26BC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X26BC);
        goto L_801A00BC;
    // 0x8019FFFC: lw          $v0, -0x26BC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X26BC);
L_801A0000:
    // 0x801A0000: jal         0x801AD11C
    // 0x801A0004: nop

    Map_Idle_Update(rdram, ctx);
        goto after_5;
    // 0x801A0004: nop

    after_5:
    // 0x801A0008: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801A000C: addiu       $v1, $v1, -0x25E4
    ctx->r3 = ADD32(ctx->r3, -0X25E4);
    // 0x801A0010: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A0014: lwc1        $f6, 0x75BC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X75BC);
    // 0x801A0018: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x801A001C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801A0020: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801A0024: swc1        $f8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f8.u32l;
    // 0x801A0028: b           L_801A00BC
    // 0x801A002C: lw          $v0, -0x26BC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X26BC);
        goto L_801A00BC;
    // 0x801A002C: lw          $v0, -0x26BC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X26BC);
L_801A0030:
    // 0x801A0030: jal         0x801A1C14
    // 0x801A0034: nop

    Map_ZoomPlanet_Update(rdram, ctx);
        goto after_6;
    // 0x801A0034: nop

    after_6:
    // 0x801A0038: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801A003C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801A0040: addiu       $v1, $v1, -0x25E4
    ctx->r3 = ADD32(ctx->r3, -0X25E4);
    // 0x801A0044: b           L_801A00BC
    // 0x801A0048: lw          $v0, -0x26BC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X26BC);
        goto L_801A00BC;
    // 0x801A0048: lw          $v0, -0x26BC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X26BC);
L_801A004C:
    // 0x801A004C: jal         0x801A5E80
    // 0x801A0050: nop

    Map_LevelStart_Update(rdram, ctx);
        goto after_7;
    // 0x801A0050: nop

    after_7:
    // 0x801A0054: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801A0058: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801A005C: addiu       $v1, $v1, -0x25E4
    ctx->r3 = ADD32(ctx->r3, -0X25E4);
    // 0x801A0060: b           L_801A00BC
    // 0x801A0064: lw          $v0, -0x26BC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X26BC);
        goto L_801A00BC;
    // 0x801A0064: lw          $v0, -0x26BC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X26BC);
L_801A0068:
    // 0x801A0068: jal         0x801A2B8C
    // 0x801A006C: nop

    Map_ZoomPlanetPath_Update(rdram, ctx);
        goto after_8;
    // 0x801A006C: nop

    after_8:
    // 0x801A0070: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801A0074: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801A0078: addiu       $v1, $v1, -0x25E4
    ctx->r3 = ADD32(ctx->r3, -0X25E4);
    // 0x801A007C: b           L_801A00BC
    // 0x801A0080: lw          $v0, -0x26BC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X26BC);
        goto L_801A00BC;
    // 0x801A0080: lw          $v0, -0x26BC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X26BC);
L_801A0084:
    // 0x801A0084: jal         0x801A4AE8
    // 0x801A0088: nop

    Map_PathChange_Update(rdram, ctx);
        goto after_9;
    // 0x801A0088: nop

    after_9:
    // 0x801A008C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801A0090: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801A0094: addiu       $v1, $v1, -0x25E4
    ctx->r3 = ADD32(ctx->r3, -0X25E4);
    // 0x801A0098: b           L_801A00BC
    // 0x801A009C: lw          $v0, -0x26BC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X26BC);
        goto L_801A00BC;
    // 0x801A009C: lw          $v0, -0x26BC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X26BC);
L_801A00A0:
    // 0x801A00A0: jal         0x801A36A8
    // 0x801A00A4: nop

    Map_GameOver_Update(rdram, ctx);
        goto after_10;
    // 0x801A00A4: nop

    after_10:
    // 0x801A00A8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801A00AC: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801A00B0: addiu       $v1, $v1, -0x25E4
    ctx->r3 = ADD32(ctx->r3, -0X25E4);
    // 0x801A00B4: b           L_801A00BC
    // 0x801A00B8: lw          $v0, -0x26BC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X26BC);
        goto L_801A00BC;
    // 0x801A00B8: lw          $v0, -0x26BC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X26BC);
L_801A00BC:
    // 0x801A00BC: beq         $v0, $zero, L_801A00D8
    if (ctx->r2 == 0) {
        // 0x801A00C0: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_801A00D8;
    }
    // 0x801A00C0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801A00C4: beq         $v0, $at, L_801A00D8
    if (ctx->r2 == ctx->r1) {
        // 0x801A00C8: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_801A00D8;
    }
    // 0x801A00C8: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x801A00CC: beq         $v0, $at, L_801A00D8
    if (ctx->r2 == ctx->r1) {
        // 0x801A00D0: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_801A00D8;
    }
    // 0x801A00D0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801A00D4: bne         $v0, $at, L_801A0188
    if (ctx->r2 != ctx->r1) {
        // 0x801A00D8: lui         $at, 0x801D
        ctx->r1 = S32(0X801D << 16);
            goto L_801A0188;
    }
L_801A00D8:
    // 0x801A00D8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A00DC: lwc1        $f12, -0x2600($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X2600);
    // 0x801A00E0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A00E4: lwc1        $f14, -0x25FC($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X25FC);
    // 0x801A00E8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A00EC: lwc1        $f10, -0x25EC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X25EC);
    // 0x801A00F0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A00F4: lwc1        $f16, -0x25F4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X25F4);
    // 0x801A00F8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A00FC: lwc1        $f18, -0x25E8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X25E8);
    // 0x801A0100: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A0104: lwc1        $f6, -0x25F0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X25F0);
    // 0x801A0108: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x801A010C: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x801A0110: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x801A0114: lui         $t7, 0x801D
    ctx->r15 = S32(0X801D << 16);
    // 0x801A0118: lui         $t8, 0x801D
    ctx->r24 = S32(0X801D << 16);
    // 0x801A011C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801A0120: addiu       $t8, $t8, -0x2604
    ctx->r24 = ADD32(ctx->r24, -0X2604);
    // 0x801A0124: addiu       $t7, $t7, -0x2608
    ctx->r15 = ADD32(ctx->r15, -0X2608);
    // 0x801A0128: lui         $a2, 0x801D
    ctx->r6 = S32(0X801D << 16);
    // 0x801A012C: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801A0130: addiu       $a3, $a3, -0x260C
    ctx->r7 = ADD32(ctx->r7, -0X260C);
    // 0x801A0134: lw          $a2, -0x25F8($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X25F8);
    // 0x801A0138: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801A013C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x801A0140: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    // 0x801A0144: jal         0x801AD718
    // 0x801A0148: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    Map_SetCamRot(rdram, ctx);
        goto after_11;
    // 0x801A0148: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    after_11:
    // 0x801A014C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A0150: lwc1        $f12, -0x260C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X260C);
    // 0x801A0154: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A0158: lwc1        $f14, -0x2608($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X2608);
    // 0x801A015C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A0160: lwc1        $f16, -0x25FC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X25FC);
    // 0x801A0164: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A0168: lwc1        $f18, -0x25F8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X25F8);
    // 0x801A016C: lui         $a2, 0x801D
    ctx->r6 = S32(0X801D << 16);
    // 0x801A0170: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801A0174: lw          $a3, -0x2600($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X2600);
    // 0x801A0178: lw          $a2, -0x2604($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X2604);
    // 0x801A017C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x801A0180: jal         0x800B6F50
    // 0x801A0184: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    Camera_SetStarfieldPos(rdram, ctx);
        goto after_12;
    // 0x801A0184: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_12:
L_801A0188:
    // 0x801A0188: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x801A018C: addiu       $v0, $v0, 0x7DB0
    ctx->r2 = ADD32(ctx->r2, 0X7DB0);
    // 0x801A0190: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x801A0194: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x801A0198: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x801A019C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x801A01A0: jr          $ra
    // 0x801A01A4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x801A01A4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void Title_NextState_TitleScreen(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80190EA4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80190EA8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80190EAC: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80190EB0: lw          $v0, -0x7D80($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D80);
    // 0x80190EB4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80190EB8: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x80190EBC: beq         $v0, $zero, L_80190ED4
    if (ctx->r2 == 0) {
        // 0x80190EC0: nop
    
            goto L_80190ED4;
    }
    // 0x80190EC0: nop

    // 0x80190EC4: beq         $v0, $at, L_80190F50
    if (ctx->r2 == ctx->r1) {
        // 0x80190EC8: lui         $v1, 0x801C
        ctx->r3 = S32(0X801C << 16);
            goto L_80190F50;
    }
    // 0x80190EC8: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80190ECC: b           L_80190FC4
    // 0x80190ED0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80190FC4;
    // 0x80190ED0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80190ED4:
    // 0x80190ED4: lw          $t6, 0x7AF8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7AF8);
    // 0x80190ED8: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80190EDC: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80190EE0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80190EE4: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80190EE8: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x80190EEC: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80190EF0: lhu         $t8, -0x2768($t8)
    ctx->r24 = MEM_HU(ctx->r24, -0X2768);
    // 0x80190EF4: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x80190EF8: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80190EFC: andi        $t9, $t8, 0xD00F
    ctx->r25 = ctx->r24 & 0XD00F;
    // 0x80190F00: beq         $t9, $zero, L_80190FC0
    if (ctx->r25 == 0) {
        // 0x80190F04: ori         $a0, $a0, 0x3
        ctx->r4 = ctx->r4 | 0X3;
            goto L_80190FC0;
    }
    // 0x80190F04: ori         $a0, $a0, 0x3
    ctx->r4 = ctx->r4 | 0X3;
    // 0x80190F08: lui         $t0, 0x800C
    ctx->r8 = S32(0X800C << 16);
    // 0x80190F0C: addiu       $t0, $t0, 0x5D3C
    ctx->r8 = ADD32(ctx->r8, 0X5D3C);
    // 0x80190F10: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x80190F14: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x80190F18: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80190F1C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80190F20: jal         0x80019218
    // 0x80190F24: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    Audio_PlaySfx(rdram, ctx);
        goto after_0;
    // 0x80190F24: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_0:
    // 0x80190F28: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80190F2C: addiu       $v1, $v1, -0x7D7C
    ctx->r3 = ADD32(ctx->r3, -0X7D7C);
    // 0x80190F30: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x80190F34: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80190F38: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80190F3C: sw          $t1, -0x7D80($at)
    MEM_W(-0X7D80, ctx->r1) = ctx->r9;
    // 0x80190F40: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80190F44: addiu       $t2, $zero, 0x1E
    ctx->r10 = ADD32(0, 0X1E);
    // 0x80190F48: b           L_80190FC0
    // 0x80190F4C: sw          $t2, -0x274C($at)
    MEM_W(-0X274C, ctx->r1) = ctx->r10;
        goto L_80190FC0;
    // 0x80190F4C: sw          $t2, -0x274C($at)
    MEM_W(-0X274C, ctx->r1) = ctx->r10;
L_80190F50:
    // 0x80190F50: addiu       $v1, $v1, -0x7D7C
    ctx->r3 = ADD32(ctx->r3, -0X7D7C);
    // 0x80190F54: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80190F58: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80190F5C: slti        $at, $v0, 0x78
    ctx->r1 = SIGNED(ctx->r2) < 0X78 ? 1 : 0;
    // 0x80190F60: beq         $at, $zero, L_80190F70
    if (ctx->r1 == 0) {
        // 0x80190F64: addiu       $t3, $v0, 0x12
        ctx->r11 = ADD32(ctx->r2, 0X12);
            goto L_80190F70;
    }
    // 0x80190F64: addiu       $t3, $v0, 0x12
    ctx->r11 = ADD32(ctx->r2, 0X12);
    // 0x80190F68: b           L_80190FC0
    // 0x80190F6C: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
        goto L_80190FC0;
    // 0x80190F6C: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
L_80190F70:
    // 0x80190F70: jal         0x8001DC6C
    // 0x80190F74: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    Audio_SetAudioSpec(rdram, ctx);
        goto after_1;
    // 0x80190F74: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    after_1:
    // 0x80190F78: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80190F7C: sw          $zero, -0x7BF0($at)
    MEM_W(-0X7BF0, ctx->r1) = 0;
    // 0x80190F80: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80190F84: sw          $zero, -0x7D64($at)
    MEM_W(-0X7D64, ctx->r1) = 0;
    // 0x80190F88: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80190F8C: sw          $zero, -0x7D40($at)
    MEM_W(-0X7D40, ctx->r1) = 0;
    // 0x80190F90: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80190F94: sw          $zero, 0x7898($at)
    MEM_W(0X7898, ctx->r1) = 0;
    // 0x80190F98: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80190F9C: sw          $zero, -0x7D3C($at)
    MEM_W(-0X7D3C, ctx->r1) = 0;
    // 0x80190FA0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80190FA4: addiu       $t4, $zero, 0x1E
    ctx->r12 = ADD32(0, 0X1E);
    // 0x80190FA8: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80190FAC: sw          $t4, -0x274C($at)
    MEM_W(-0X274C, ctx->r1) = ctx->r12;
    // 0x80190FB0: addiu       $v1, $v1, -0x7D7C
    ctx->r3 = ADD32(ctx->r3, -0X7D7C);
    // 0x80190FB4: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x80190FB8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80190FBC: sw          $zero, -0x7D80($at)
    MEM_W(-0X7D80, ctx->r1) = 0;
L_80190FC0:
    // 0x80190FC0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80190FC4:
    // 0x80190FC4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80190FC8: jr          $ra
    // 0x80190FCC: nop

    return;
    // 0x80190FCC: nop

;}
RECOMP_FUNC void Option_Sound_Setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80194678: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8019467C: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80194680: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80194684: addiu       $v1, $v1, 0x7C74
    ctx->r3 = ADD32(ctx->r3, 0X7C74);
    // 0x80194688: addiu       $v0, $v0, -0x7790
    ctx->r2 = ADD32(ctx->r2, -0X7790);
    // 0x8019468C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80194690: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80194694: addiu       $t6, $zero, 0x320
    ctx->r14 = ADD32(0, 0X320);
    // 0x80194698: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8019469C: sw          $t6, -0x7BF0($at)
    MEM_W(-0X7BF0, ctx->r1) = ctx->r14;
    // 0x801946A0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801946A4: sw          $zero, -0x6E4C($at)
    MEM_W(-0X6E4C, ctx->r1) = 0;
    // 0x801946A8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801946AC: sw          $zero, -0x6E48($at)
    MEM_W(-0X6E48, ctx->r1) = 0;
    // 0x801946B0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801946B4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801946B8: sw          $t7, -0x6E44($at)
    MEM_W(-0X6E44, ctx->r1) = ctx->r15;
    // 0x801946BC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801946C0: sw          $zero, -0x6E60($at)
    MEM_W(-0X6E60, ctx->r1) = 0;
    // 0x801946C4: lbu         $t8, 0x14($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X14);
    // 0x801946C8: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x801946CC: lui         $at, 0xE000
    ctx->r1 = S32(0XE000 << 16);
    // 0x801946D0: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x801946D4: addu        $a0, $a0, $t9
    ctx->r4 = ADD32(ctx->r4, ctx->r25);
    // 0x801946D8: sb          $t8, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r24;
    // 0x801946DC: lbu         $a0, -0x1668($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X1668);
    // 0x801946E0: or          $t0, $a0, $at
    ctx->r8 = ctx->r4 | ctx->r1;
    // 0x801946E4: jal         0x800182F4
    // 0x801946E8: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_0;
    // 0x801946E8: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_0:
    // 0x801946EC: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x801946F0: addiu       $v0, $v0, -0x7790
    ctx->r2 = ADD32(ctx->r2, -0X7790);
    // 0x801946F4: lbu         $t1, 0x15($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X15);
    // 0x801946F8: lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // 0x801946FC: lbu         $t2, 0x16($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X16);
    // 0x80194700: lbu         $t3, 0x17($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X17);
    // 0x80194704: addiu       $s0, $s0, 0x7C80
    ctx->r16 = ADD32(ctx->r16, 0X7C80);
    // 0x80194708: slti        $at, $t1, 0x64
    ctx->r1 = SIGNED(ctx->r9) < 0X64 ? 1 : 0;
    // 0x8019470C: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x80194710: sw          $t2, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r10;
    // 0x80194714: bne         $at, $zero, L_80194724
    if (ctx->r1 != 0) {
        // 0x80194718: sw          $t3, 0x8($s0)
        MEM_W(0X8, ctx->r16) = ctx->r11;
            goto L_80194724;
    }
    // 0x80194718: sw          $t3, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r11;
    // 0x8019471C: addiu       $v0, $zero, 0x63
    ctx->r2 = ADD32(0, 0X63);
    // 0x80194720: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
L_80194724:
    // 0x80194724: lw          $t5, 0x4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X4);
    // 0x80194728: addiu       $v0, $zero, 0x63
    ctx->r2 = ADD32(0, 0X63);
    // 0x8019472C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80194730: slti        $at, $t5, 0x64
    ctx->r1 = SIGNED(ctx->r13) < 0X64 ? 1 : 0;
    // 0x80194734: bnel        $at, $zero, L_80194744
    if (ctx->r1 != 0) {
        // 0x80194738: lw          $t6, 0x8($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X8);
            goto L_80194744;
    }
    goto skip_0;
    // 0x80194738: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
    skip_0:
    // 0x8019473C: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // 0x80194740: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
L_80194744:
    // 0x80194744: slti        $at, $t6, 0x64
    ctx->r1 = SIGNED(ctx->r14) < 0X64 ? 1 : 0;
    // 0x80194748: bne         $at, $zero, L_80194754
    if (ctx->r1 != 0) {
        // 0x8019474C: nop
    
            goto L_80194754;
    }
    // 0x8019474C: nop

    // 0x80194750: sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
L_80194754:
    // 0x80194754: jal         0x8001D8A8
    // 0x80194758: lbu         $a1, 0x3($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X3);
    Audio_SetVolume(rdram, ctx);
        goto after_1;
    // 0x80194758: lbu         $a1, 0x3($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X3);
    after_1:
    // 0x8019475C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80194760: jal         0x8001D8A8
    // 0x80194764: lbu         $a1, 0x7($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X7);
    Audio_SetVolume(rdram, ctx);
        goto after_2;
    // 0x80194764: lbu         $a1, 0x7($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X7);
    after_2:
    // 0x80194768: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8019476C: jal         0x8001D8A8
    // 0x80194770: lbu         $a1, 0xB($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0XB);
    Audio_SetVolume(rdram, ctx);
        goto after_3;
    // 0x80194770: lbu         $a1, 0xB($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0XB);
    after_3:
    // 0x80194774: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80194778: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x8019477C: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    // 0x80194780: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80194784: lui         $at, 0x4312
    ctx->r1 = S32(0X4312 << 16);
    // 0x80194788: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8019478C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80194790: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x80194794: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80194798: lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // 0x8019479C: addiu       $v0, $v0, -0x14B8
    ctx->r2 = ADD32(ctx->r2, -0X14B8);
    // 0x801947A0: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801947A4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801947A8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x801947AC: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x801947B0: addiu       $t1, $t1, -0x6D90
    ctx->r9 = ADD32(ctx->r9, -0X6D90);
    // 0x801947B4: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x801947B8: sll         $t0, $v1, 2
    ctx->r8 = S32(ctx->r3 << 2);
    // 0x801947BC: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801947C0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801947C4: swc1        $f8, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f8.u32l;
    // 0x801947C8: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801947CC: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801947D0: addiu       $a1, $a1, -0x6D98
    ctx->r5 = ADD32(ctx->r5, -0X6D98);
    // 0x801947D4: add.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x801947D8: addiu       $a0, $a0, -0x6DA0
    ctx->r4 = ADD32(ctx->r4, -0X6DA0);
    // 0x801947DC: addiu       $v1, $v1, -0x6DA8
    ctx->r3 = ADD32(ctx->r3, -0X6DA8);
    // 0x801947E0: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x801947E4: swc1        $f18, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->f18.u32l;
    // 0x801947E8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801947EC: swc1        $f8, 0x88($v0)
    MEM_W(0X88, ctx->r2) = ctx->f8.u32l;
    // 0x801947F0: sw          $zero, -0x6D78($at)
    MEM_W(-0X6D78, ctx->r1) = 0;
    // 0x801947F4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801947F8: sw          $zero, -0x6D7C($at)
    MEM_W(-0X6D7C, ctx->r1) = 0;
    // 0x801947FC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80194800: sw          $zero, -0x6EB4($at)
    MEM_W(-0X6EB4, ctx->r1) = 0;
    // 0x80194804: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80194808: sw          $zero, -0x6EA8($at)
    MEM_W(-0X6EA8, ctx->r1) = 0;
    // 0x8019480C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80194810: sw          $zero, -0x6E88($at)
    MEM_W(-0X6E88, ctx->r1) = 0;
    // 0x80194814: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80194818: sw          $zero, -0x6E84($at)
    MEM_W(-0X6E84, ctx->r1) = 0;
    // 0x8019481C: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80194820: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80194824: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80194828: addu        $v0, $t0, $t1
    ctx->r2 = ADD32(ctx->r8, ctx->r9);
    // 0x8019482C: swc1        $f0, -0x6D90($at)
    MEM_W(-0X6D90, ctx->r1) = ctx->f0.u32l;
    // 0x80194830: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80194834: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x80194838: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x8019483C: swc1        $f0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f0.u32l;
    // 0x80194840: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
    // 0x80194844: swc1        $f0, -0x6E1C($at)
    MEM_W(-0X6E1C, ctx->r1) = ctx->f0.u32l;
    // 0x80194848: lui         $at, 0x4260
    ctx->r1 = S32(0X4260 << 16);
    // 0x8019484C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80194850: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80194854: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80194858: swc1        $f10, -0x6DE8($at)
    MEM_W(-0X6DE8, ctx->r1) = ctx->f10.u32l;
    // 0x8019485C: lui         $at, 0xC22C
    ctx->r1 = S32(0XC22C << 16);
    // 0x80194860: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80194864: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80194868: addiu       $v0, $v0, -0x6DB0
    ctx->r2 = ADD32(ctx->r2, -0X6DB0);
    // 0x8019486C: swc1        $f16, -0x6DE4($at)
    MEM_W(-0X6DE4, ctx->r1) = ctx->f16.u32l;
    // 0x80194870: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80194874: swc1        $f18, -0x6DE0($at)
    MEM_W(-0X6DE0, ctx->r1) = ctx->f18.u32l;
    // 0x80194878: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x8019487C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80194880: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x80194884: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80194888: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x8019488C: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x80194890: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x80194894: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x80194898: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8019489C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801948A0: jr          $ra
    // 0x801948A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x801948A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void Option_VsTimeTrial_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019AD84: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8019AD88: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8019AD8C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8019AD90: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x8019AD94: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8019AD98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8019AD9C: jal         0x800B8DD0
    // 0x8019ADA0: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x8019ADA0: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    after_0:
    // 0x8019ADA4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8019ADA8: lui         $t8, 0x3C3C
    ctx->r24 = S32(0X3C3C << 16);
    // 0x8019ADAC: ori         $t8, $t8, 0xFFBE
    ctx->r24 = ctx->r24 | 0XFFBE;
    // 0x8019ADB0: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8019ADB4: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8019ADB8: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x8019ADBC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8019ADC0: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8019ADC4: lui         $at, 0x42BA
    ctx->r1 = S32(0X42BA << 16);
    // 0x8019ADC8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019ADCC: lui         $at, 0x4228
    ctx->r1 = S32(0X4228 << 16);
    // 0x8019ADD0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8019ADD4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8019ADD8: lwc1        $f8, 0x745C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X745C);
    // 0x8019ADDC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8019ADE0: lwc1        $f10, 0x7460($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7460);
    // 0x8019ADE4: lui         $a1, 0x602
    ctx->r5 = S32(0X602 << 16);
    // 0x8019ADE8: addiu       $a1, $a1, -0x4B50
    ctx->r5 = ADD32(ctx->r5, -0X4B50);
    // 0x8019ADEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8019ADF0: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    // 0x8019ADF4: addiu       $a3, $zero, 0x11
    ctx->r7 = ADD32(0, 0X11);
    // 0x8019ADF8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8019ADFC: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x8019AE00: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x8019AE04: jal         0x8009D994
    // 0x8019AE08: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_1;
    // 0x8019AE08: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x8019AE0C: lui         $t9, 0x801C
    ctx->r25 = S32(0X801C << 16);
    // 0x8019AE10: lw          $t9, -0x6ED4($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X6ED4);
    // 0x8019AE14: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x8019AE18: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x8019AE1C: bne         $t9, $zero, L_8019AE7C
    if (ctx->r25 != 0) {
        // 0x8019AE20: lui         $at, 0x437F
        ctx->r1 = S32(0X437F << 16);
            goto L_8019AE7C;
    }
    // 0x8019AE20: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x8019AE24: lui         $at, 0x42D6
    ctx->r1 = S32(0X42D6 << 16);
    // 0x8019AE28: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8019AE2C: lui         $at, 0x42C2
    ctx->r1 = S32(0X42C2 << 16);
    // 0x8019AE30: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8019AE34: lui         $at, 0x4244
    ctx->r1 = S32(0X4244 << 16);
    // 0x8019AE38: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8019AE3C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019AE40: swc1        $f12, -0x6CDC($at)
    MEM_W(-0X6CDC, ctx->r1) = ctx->f12.u32l;
    // 0x8019AE44: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019AE48: swc1        $f14, -0x6CD8($at)
    MEM_W(-0X6CD8, ctx->r1) = ctx->f14.u32l;
    // 0x8019AE4C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019AE50: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x8019AE54: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8019AE58: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8019AE5C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8019AE60: jal         0x8019B6D8
    // 0x8019AE64: swc1        $f0, -0x6CC8($at)
    MEM_W(-0X6CC8, ctx->r1) = ctx->f0.u32l;
    Option_VsSelectionArrows_Draw(rdram, ctx);
        goto after_2;
    // 0x8019AE64: swc1        $f0, -0x6CC8($at)
    MEM_W(-0X6CC8, ctx->r1) = ctx->f0.u32l;
    after_2:
    // 0x8019AE68: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8019AE6C: jal         0x8019C824
    // 0x8019AE70: addiu       $a0, $a0, -0x6C88
    ctx->r4 = ADD32(ctx->r4, -0X6C88);
    Option_Color_FlashRed(rdram, ctx);
        goto after_3;
    // 0x8019AE70: addiu       $a0, $a0, -0x6C88
    ctx->r4 = ADD32(ctx->r4, -0X6C88);
    after_3:
    // 0x8019AE74: b           L_8019AE88
    // 0x8019AE78: nop

        goto L_8019AE88;
    // 0x8019AE78: nop

L_8019AE7C:
    // 0x8019AE7C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8019AE80: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019AE84: swc1        $f16, -0x6C88($at)
    MEM_W(-0X6C88, ctx->r1) = ctx->f16.u32l;
L_8019AE88:
    // 0x8019AE88: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019AE8C: lwc1        $f18, -0x6C88($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X6C88);
    // 0x8019AE90: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8019AE94: addiu       $a0, $a0, -0x6C84
    ctx->r4 = ADD32(ctx->r4, -0X6C84);
    // 0x8019AE98: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8019AE9C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8019AEA0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8019AEA4: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x8019AEA8: mfc1        $t3, $f4
    ctx->r11 = (int32_t)ctx->f4.u32l;
    // 0x8019AEAC: beq         $v1, $zero, L_8019AED0
    if (ctx->r3 == 0) {
        // 0x8019AEB0: addiu       $t7, $v1, -0x1
        ctx->r15 = ADD32(ctx->r3, -0X1);
            goto L_8019AED0;
    }
    // 0x8019AEB0: addiu       $t7, $v1, -0x1
    ctx->r15 = ADD32(ctx->r3, -0X1);
    // 0x8019AEB4: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x8019AEB8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8019AEBC: bne         $t7, $zero, L_8019AED0
    if (ctx->r15 != 0) {
        // 0x8019AEC0: sw          $t7, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r15;
            goto L_8019AED0;
    }
    // 0x8019AEC0: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8019AEC4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8019AEC8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019AECC: sw          $t9, -0x6E10($at)
    MEM_W(-0X6E10, ctx->r1) = ctx->r25;
L_8019AED0:
    // 0x8019AED0: lw          $t4, 0x7DB0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7DB0);
    // 0x8019AED4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8019AED8: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    // 0x8019AEDC: and         $t5, $t4, $v0
    ctx->r13 = ctx->r12 & ctx->r2;
    // 0x8019AEE0: beql        $t5, $zero, L_8019AFEC
    if (ctx->r13 == 0) {
        // 0x8019AEE4: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8019AFEC;
    }
    goto skip_0;
    // 0x8019AEE4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x8019AEE8: jal         0x800B8DD0
    // 0x8019AEEC: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
    RCP_SetupDL(rdram, ctx);
        goto after_4;
    // 0x8019AEEC: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
    after_4:
    // 0x8019AEF0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8019AEF4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8019AEF8: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x8019AEFC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8019AF00: andi        $t1, $t3, 0xFF
    ctx->r9 = ctx->r11 & 0XFF;
    // 0x8019AF04: sll         $t8, $t1, 16
    ctx->r24 = S32(ctx->r9 << 16);
    // 0x8019AF08: lui         $at, 0xFF00
    ctx->r1 = S32(0XFF00 << 16);
    // 0x8019AF0C: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x8019AF10: sll         $t4, $t1, 8
    ctx->r12 = S32(ctx->r9 << 8);
    // 0x8019AF14: or          $t2, $t9, $t4
    ctx->r10 = ctx->r25 | ctx->r12;
    // 0x8019AF18: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8019AF1C: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8019AF20: ori         $t5, $t2, 0xFF
    ctx->r13 = ctx->r10 | 0XFF;
    // 0x8019AF24: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x8019AF28: or          $t2, $t5, $zero
    ctx->r10 = ctx->r13 | 0;
    // 0x8019AF2C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8019AF30: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x8019AF34: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8019AF38: lw          $v1, -0x6CC0($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X6CC0);
    // 0x8019AF3C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8019AF40: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x8019AF44: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x8019AF48: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8019AF4C: lwc1        $f6, -0xDA0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0XDA0);
    // 0x8019AF50: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8019AF54: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8019AF58: lwc1        $f8, -0xD88($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0XD88);
    // 0x8019AF5C: addu        $a1, $a1, $t6
    ctx->r5 = ADD32(ctx->r5, ctx->r14);
    // 0x8019AF60: lw          $a1, -0xD74($a1)
    ctx->r5 = MEM_W(ctx->r5, -0XD74);
    // 0x8019AF64: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x8019AF68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8019AF6C: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    // 0x8019AF70: addiu       $a3, $zero, 0xF
    ctx->r7 = ADD32(0, 0XF);
    // 0x8019AF74: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x8019AF78: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x8019AF7C: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x8019AF80: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x8019AF84: jal         0x8009D994
    // 0x8019AF88: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_5;
    // 0x8019AF88: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_5:
    // 0x8019AF8C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8019AF90: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8019AF94: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x8019AF98: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8019AF9C: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x8019AFA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8019AFA4: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8019AFA8: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x8019AFAC: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x8019AFB0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8019AFB4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8019AFB8: lwc1        $f10, -0xDA4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0XDA4);
    // 0x8019AFBC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8019AFC0: lwc1        $f16, -0xD8C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0XD8C);
    // 0x8019AFC4: lui         $a1, 0x700
    ctx->r5 = S32(0X700 << 16);
    // 0x8019AFC8: addiu       $a1, $a1, 0x2110
    ctx->r5 = ADD32(ctx->r5, 0X2110);
    // 0x8019AFCC: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    // 0x8019AFD0: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    // 0x8019AFD4: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x8019AFD8: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x8019AFDC: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x8019AFE0: jal         0x8009D994
    // 0x8019AFE4: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_6;
    // 0x8019AFE4: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    after_6:
    // 0x8019AFE8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8019AFEC:
    // 0x8019AFEC: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8019AFF0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8019AFF4: jr          $ra
    // 0x8019AFF8: nop

    return;
    // 0x8019AFF8: nop

;}
RECOMP_FUNC void Title_TitleCard_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80190C9C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80190CA0: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80190CA4: sw          $s3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r19;
    // 0x80190CA8: sw          $s2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r18;
    // 0x80190CAC: sw          $s1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r17;
    // 0x80190CB0: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    // 0x80190CB4: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x80190CB8: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80190CBC: lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // 0x80190CC0: lw          $v0, 0x7BF0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7BF0);
    // 0x80190CC4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80190CC8: beql        $v0, $zero, L_80190E44
    if (ctx->r2 == 0) {
        // 0x80190CCC: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_80190E44;
    }
    goto skip_0;
    // 0x80190CCC: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_0:
    // 0x80190CD0: beq         $v0, $at, L_80190CEC
    if (ctx->r2 == ctx->r1) {
        // 0x80190CD4: lui         $s2, 0x8013
        ctx->r18 = S32(0X8013 << 16);
            goto L_80190CEC;
    }
    // 0x80190CD4: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x80190CD8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80190CDC: beq         $v0, $at, L_80190D60
    if (ctx->r2 == ctx->r1) {
        // 0x80190CE0: lui         $s2, 0x8013
        ctx->r18 = S32(0X8013 << 16);
            goto L_80190D60;
    }
    // 0x80190CE0: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x80190CE4: b           L_80190E44
    // 0x80190CE8: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_80190E44;
    // 0x80190CE8: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_80190CEC:
    // 0x80190CEC: addiu       $s2, $s2, 0x7E64
    ctx->r18 = ADD32(ctx->r18, 0X7E64);
    // 0x80190CF0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80190CF4: jal         0x800B8DD0
    // 0x80190CF8: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x80190CF8: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    after_0:
    // 0x80190CFC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80190D00: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80190D04: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80190D08: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x80190D0C: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x80190D10: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80190D14: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80190D18: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
    // 0x80190D1C: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80190D20: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80190D24: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80190D28: lwc1        $f4, -0x1AA4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X1AA4);
    // 0x80190D2C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80190D30: lwc1        $f6, -0x1AA0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X1AA0);
    // 0x80190D34: lui         $a1, 0x601
    ctx->r5 = S32(0X601 << 16);
    // 0x80190D38: addiu       $a1, $a1, -0x1680
    ctx->r5 = ADD32(ctx->r5, -0X1680);
    // 0x80190D3C: addiu       $a2, $zero, 0x90
    ctx->r6 = ADD32(0, 0X90);
    // 0x80190D40: addiu       $a3, $zero, 0x1C
    ctx->r7 = ADD32(0, 0X1C);
    // 0x80190D44: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x80190D48: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80190D4C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80190D50: jal         0x8009D994
    // 0x80190D54: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_1;
    // 0x80190D54: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x80190D58: b           L_80190E44
    // 0x80190D5C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_80190E44;
    // 0x80190D5C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_80190D60:
    // 0x80190D60: addiu       $s2, $s2, 0x7E64
    ctx->r18 = ADD32(ctx->r18, 0X7E64);
    // 0x80190D64: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80190D68: jal         0x800B8DD0
    // 0x80190D6C: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    RCP_SetupDL(rdram, ctx);
        goto after_2;
    // 0x80190D6C: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    after_2:
    // 0x80190D70: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x80190D74: lui         $t0, 0xFA00
    ctx->r8 = S32(0XFA00 << 16);
    // 0x80190D78: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80190D7C: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80190D80: sw          $t9, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r25;
    // 0x80190D84: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x80190D88: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x80190D8C: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80190D90: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80190D94: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80190D98: lui         $s1, 0x601
    ctx->r17 = S32(0X601 << 16);
    // 0x80190D9C: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80190DA0: addiu       $s1, $s1, 0x1890
    ctx->r17 = ADD32(ctx->r17, 0X1890);
    // 0x80190DA4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80190DA8: addiu       $s3, $zero, 0x4
    ctx->r19 = ADD32(0, 0X4);
L_80190DAC:
    // 0x80190DAC: mtc1        $s0, $f10
    ctx->f10.u32l = ctx->r16;
    // 0x80190DB0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80190DB4: lwc1        $f8, -0x1A9C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X1A9C);
    // 0x80190DB8: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80190DBC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80190DC0: lwc1        $f4, -0x1A98($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X1A98);
    // 0x80190DC4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80190DC8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80190DCC: addiu       $a2, $zero, 0x70
    ctx->r6 = ADD32(0, 0X70);
    // 0x80190DD0: mul.s       $f18, $f16, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f22.fl);
    // 0x80190DD4: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    // 0x80190DD8: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x80190DDC: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80190DE0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x80190DE4: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80190DE8: jal         0x8009D994
    // 0x80190DEC: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_3;
    // 0x80190DEC: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_3:
    // 0x80190DF0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80190DF4: bne         $s0, $s3, L_80190DAC
    if (ctx->r16 != ctx->r19) {
        // 0x80190DF8: addiu       $s1, $s1, 0x2A0
        ctx->r17 = ADD32(ctx->r17, 0X2A0);
            goto L_80190DAC;
    }
    // 0x80190DF8: addiu       $s1, $s1, 0x2A0
    ctx->r17 = ADD32(ctx->r17, 0X2A0);
    // 0x80190DFC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80190E00: lwc1        $f8, -0x1A9C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X1A9C);
    // 0x80190E04: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80190E08: lwc1        $f10, -0x1A98($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X1A98);
    // 0x80190E0C: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x80190E10: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80190E14: lui         $a1, 0x601
    ctx->r5 = S32(0X601 << 16);
    // 0x80190E18: addiu       $a1, $a1, 0x2310
    ctx->r5 = ADD32(ctx->r5, 0X2310);
    // 0x80190E1C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80190E20: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80190E24: addiu       $a2, $zero, 0x70
    ctx->r6 = ADD32(0, 0X70);
    // 0x80190E28: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x80190E2C: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x80190E30: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x80190E34: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80190E38: jal         0x8009D994
    // 0x80190E3C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_4;
    // 0x80190E3C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_4:
    // 0x80190E40: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_80190E44:
    // 0x80190E44: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80190E48: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x80190E4C: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x80190E50: lw          $s1, 0x38($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X38);
    // 0x80190E54: lw          $s2, 0x3C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X3C);
    // 0x80190E58: lw          $s3, 0x40($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X40);
    // 0x80190E5C: jr          $ra
    // 0x80190E60: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80190E60: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void Title_Arwing_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D2B8: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x8018D2BC: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8018D2C0: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x8018D2C4: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x8018D2C8: sw          $a0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r4;
    // 0x8018D2CC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018D2D0: lwc1        $f4, -0x7D20($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7D20);
    // 0x8018D2D4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018D2D8: lwc1        $f8, -0x7D1C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X7D1C);
    // 0x8018D2DC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018D2E0: lwc1        $f16, -0x7D18($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X7D18);
    // 0x8018D2E4: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8018D2E8: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8018D2EC: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8018D2F0: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8018D2F4: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8018D2F8: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8018D2FC: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8018D300: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8018D304: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8018D308: lw          $t4, -0x7AA4($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7AA4);
    // 0x8018D30C: lw          $t3, -0x7AA8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X7AA8);
    // 0x8018D310: lw          $t2, -0x7AAC($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X7AAC);
    // 0x8018D314: lw          $t1, -0x7AB0($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X7AB0);
    // 0x8018D318: lw          $t0, -0x7AB4($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7AB4);
    // 0x8018D31C: lw          $t9, -0x7AB8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7AB8);
    // 0x8018D320: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x8018D324: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x8018D328: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8018D32C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8018D330: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8018D334: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    // 0x8018D338: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    // 0x8018D33C: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x8018D340: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x8018D344: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8018D348: jal         0x8000372C
    // 0x8018D34C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    Lights_SetOneLight(rdram, ctx);
        goto after_0;
    // 0x8018D34C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_0:
    // 0x8018D350: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8018D354: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8018D358: jal         0x800B8DD0
    // 0x8018D35C: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    RCP_SetupDL(rdram, ctx);
        goto after_1;
    // 0x8018D35C: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    after_1:
    // 0x8018D360: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x8018D364: addiu       $s1, $s1, -0x4C40
    ctx->r17 = ADD32(ctx->r17, -0X4C40);
    // 0x8018D368: jal         0x80005708
    // 0x8018D36C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Push(rdram, ctx);
        goto after_2;
    // 0x8018D36C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x8018D370: lw          $t5, 0x80($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X80);
    // 0x8018D374: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x8018D378: addiu       $t7, $t7, -0x7B18
    ctx->r15 = ADD32(ctx->r15, -0X7B18);
    // 0x8018D37C: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8018D380: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x8018D384: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8018D388: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x8018D38C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8018D390: addu        $s0, $t6, $t7
    ctx->r16 = ADD32(ctx->r14, ctx->r15);
    // 0x8018D394: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8018D398: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8018D39C: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x8018D3A0: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    // 0x8018D3A4: lw          $a3, 0x8($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X8);
    // 0x8018D3A8: jal         0x80005B00
    // 0x8018D3AC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_3;
    // 0x8018D3AC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_3:
    // 0x8018D3B0: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8018D3B4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8018D3B8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8018D3BC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8018D3C0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8018D3C4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8018D3C8: jal         0x80005C34
    // 0x8018D3CC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_4;
    // 0x8018D3CC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_4:
    // 0x8018D3D0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018D3D4: lwc1        $f6, 0x7018($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7018);
    // 0x8018D3D8: lwc1        $f4, 0x20($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X20);
    // 0x8018D3DC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8018D3E0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018D3E4: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8018D3E8: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8018D3EC: jal         0x80005FE0
    // 0x8018D3F0: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_5;
    // 0x8018D3F0: nop

    after_5:
    // 0x8018D3F4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018D3F8: lwc1        $f16, 0x701C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X701C);
    // 0x8018D3FC: lwc1        $f10, 0x18($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8018D400: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8018D404: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018D408: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8018D40C: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8018D410: jal         0x80005D44
    // 0x8018D414: nop

    Matrix_RotateX(rdram, ctx);
        goto after_6;
    // 0x8018D414: nop

    after_6:
    // 0x8018D418: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018D41C: lwc1        $f6, 0x7020($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7020);
    // 0x8018D420: lwc1        $f4, 0x1C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x8018D424: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8018D428: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018D42C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8018D430: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8018D434: jal         0x80005E90
    // 0x8018D438: nop

    Matrix_RotateY(rdram, ctx);
        goto after_7;
    // 0x8018D438: nop

    after_7:
    // 0x8018D43C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8018D440: jal         0x80006EB8
    // 0x8018D444: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_8;
    // 0x8018D444: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    after_8:
    // 0x8018D448: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8018D44C: lwc1        $f10, 0x28($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X28);
    // 0x8018D450: lw          $t2, 0x34($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X34);
    // 0x8018D454: lwc1        $f16, 0x2C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8018D458: lwc1        $f18, 0x30($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X30);
    // 0x8018D45C: lwc1        $f4, 0x24($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8018D460: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x8018D464: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8018D468: sb          $t1, 0x44($sp)
    MEM_B(0X44, ctx->r29) = ctx->r9;
    // 0x8018D46C: sb          $t0, 0x45($sp)
    MEM_B(0X45, ctx->r29) = ctx->r8;
    // 0x8018D470: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x8018D474: swc1        $f0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f0.u32l;
    // 0x8018D478: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    // 0x8018D47C: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    // 0x8018D480: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x8018D484: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x8018D488: swc1        $f0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f0.u32l;
    // 0x8018D48C: swc1        $f0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f0.u32l;
    // 0x8018D490: swc1        $f0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f0.u32l;
    // 0x8018D494: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    // 0x8018D498: swc1        $f10, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f10.u32l;
    // 0x8018D49C: sb          $t2, 0x70($sp)
    MEM_B(0X70, ctx->r29) = ctx->r10;
    // 0x8018D4A0: swc1        $f16, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f16.u32l;
    // 0x8018D4A4: swc1        $f18, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f18.u32l;
    // 0x8018D4A8: jal         0x80053658
    // 0x8018D4AC: swc1        $f4, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f4.u32l;
    Display_Arwing_Skel(rdram, ctx);
        goto after_9;
    // 0x8018D4AC: swc1        $f4, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f4.u32l;
    after_9:
    // 0x8018D4B0: jal         0x8005F1EC
    // 0x8018D4B4: addiu       $a0, $s0, 0x50
    ctx->r4 = ADD32(ctx->r16, 0X50);
    Object_UpdateSfxSource(rdram, ctx);
        goto after_10;
    // 0x8018D4B4: addiu       $a0, $s0, 0x50
    ctx->r4 = ADD32(ctx->r16, 0X50);
    after_10:
    // 0x8018D4B8: lw          $t3, 0x40($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X40);
    // 0x8018D4BC: beql        $t3, $zero, L_8018D4D0
    if (ctx->r11 == 0) {
        // 0x8018D4C0: lw          $t4, 0x3C($s0)
        ctx->r12 = MEM_W(ctx->r16, 0X3C);
            goto L_8018D4D0;
    }
    goto skip_0;
    // 0x8018D4C0: lw          $t4, 0x3C($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X3C);
    skip_0:
    // 0x8018D4C4: jal         0x8018D80C
    // 0x8018D4C8: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    Title_EngineGlowParticles_Draw(rdram, ctx);
        goto after_11;
    // 0x8018D4C8: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    after_11:
    // 0x8018D4CC: lw          $t4, 0x3C($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X3C);
L_8018D4D0:
    // 0x8018D4D0: beql        $t4, $zero, L_8018D4E4
    if (ctx->r12 == 0) {
        // 0x8018D4D4: lw          $t5, 0x48($s0)
        ctx->r13 = MEM_W(ctx->r16, 0X48);
            goto L_8018D4E4;
    }
    goto skip_1;
    // 0x8018D4D4: lw          $t5, 0x48($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X48);
    skip_1:
    // 0x8018D4D8: jal         0x8018D510
    // 0x8018D4DC: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    Title_Arwing_DrawEngineGlow(rdram, ctx);
        goto after_12;
    // 0x8018D4DC: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    after_12:
    // 0x8018D4E0: lw          $t5, 0x48($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X48);
L_8018D4E4:
    // 0x8018D4E4: beq         $t5, $zero, L_8018D4F4
    if (ctx->r13 == 0) {
        // 0x8018D4E8: nop
    
            goto L_8018D4F4;
    }
    // 0x8018D4E8: nop

    // 0x8018D4EC: jal         0x8018DDB8
    // 0x8018D4F0: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    Title_ArwingShadow_Draw(rdram, ctx);
        goto after_13;
    // 0x8018D4F0: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    after_13:
L_8018D4F4:
    // 0x8018D4F4: jal         0x80005740
    // 0x8018D4F8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_14;
    // 0x8018D4F8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_14:
    // 0x8018D4FC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8018D500: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x8018D504: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x8018D508: jr          $ra
    // 0x8018D50C: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x8018D50C: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void Map_801A9A8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A9A8C: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x801A9A90: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x801A9A94: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x801A9A98: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x801A9A9C: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x801A9AA0: sdc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X30, ctx->r29);
    // 0x801A9AA4: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x801A9AA8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x801A9AAC: lw          $t6, -0x7DCC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7DCC);
    // 0x801A9AB0: sltiu       $at, $t6, 0x13
    ctx->r1 = ctx->r14 < 0X13 ? 1 : 0;
    // 0x801A9AB4: beq         $at, $zero, L_801A9C18
    if (ctx->r1 == 0) {
        // 0x801A9AB8: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_801A9C18;
    }
    // 0x801A9AB8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801A9ABC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A9AC0: addu        $at, $at, $t6
    gpr jr_addend_801A9AC8 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x801A9AC4: lw          $t6, 0x79E8($at)
    ctx->r14 = ADD32(ctx->r1, 0X79E8);
    // 0x801A9AC8: jr          $t6
    // 0x801A9ACC: nop

    switch (jr_addend_801A9AC8 >> 2) {
        case 0: goto L_801A9AD0; break;
        case 1: goto L_801A9AE4; break;
        case 2: goto L_801A9B5C; break;
        case 3: goto L_801A9C04; break;
        case 4: goto L_801A9C18; break;
        case 5: goto L_801A9AFC; break;
        case 6: goto L_801A9C18; break;
        case 7: goto L_801A9B74; break;
        case 8: goto L_801A9B8C; break;
        case 9: goto L_801A9C18; break;
        case 10: goto L_801A9C18; break;
        case 11: goto L_801A9BBC; break;
        case 12: goto L_801A9BA4; break;
        case 13: goto L_801A9B44; break;
        case 14: goto L_801A9B14; break;
        case 15: goto L_801A9C18; break;
        case 16: goto L_801A9B2C; break;
        case 17: goto L_801A9BEC; break;
        case 18: goto L_801A9BD4; break;
        default: switch_error(__func__, 0x801A9AC8, 0x801B79E8);
    }
    // 0x801A9ACC: nop

L_801A9AD0:
    // 0x801A9AD0: lui         $t7, 0x501
    ctx->r15 = S32(0X501 << 16);
    // 0x801A9AD4: addiu       $t7, $t7, -0x5FB0
    ctx->r15 = ADD32(ctx->r15, -0X5FB0);
    // 0x801A9AD8: sw          $t7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r15;
    // 0x801A9ADC: b           L_801A9C18
    // 0x801A9AE0: sw          $zero, 0x58($sp)
    MEM_W(0X58, ctx->r29) = 0;
        goto L_801A9C18;
    // 0x801A9AE0: sw          $zero, 0x58($sp)
    MEM_W(0X58, ctx->r29) = 0;
L_801A9AE4:
    // 0x801A9AE4: lui         $t8, 0x501
    ctx->r24 = S32(0X501 << 16);
    // 0x801A9AE8: addiu       $t8, $t8, -0x5EC0
    ctx->r24 = ADD32(ctx->r24, -0X5EC0);
    // 0x801A9AEC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801A9AF0: sw          $t8, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r24;
    // 0x801A9AF4: b           L_801A9C18
    // 0x801A9AF8: sw          $t9, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r25;
        goto L_801A9C18;
    // 0x801A9AF8: sw          $t9, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r25;
L_801A9AFC:
    // 0x801A9AFC: lui         $t0, 0x501
    ctx->r8 = S32(0X501 << 16);
    // 0x801A9B00: addiu       $t0, $t0, -0x5EC0
    ctx->r8 = ADD32(ctx->r8, -0X5EC0);
    // 0x801A9B04: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x801A9B08: sw          $t0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r8;
    // 0x801A9B0C: b           L_801A9C18
    // 0x801A9B10: sw          $t1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r9;
        goto L_801A9C18;
    // 0x801A9B10: sw          $t1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r9;
L_801A9B14:
    // 0x801A9B14: lui         $t2, 0x501
    ctx->r10 = S32(0X501 << 16);
    // 0x801A9B18: addiu       $t2, $t2, -0x5DD0
    ctx->r10 = ADD32(ctx->r10, -0X5DD0);
    // 0x801A9B1C: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x801A9B20: sw          $t2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r10;
    // 0x801A9B24: b           L_801A9C18
    // 0x801A9B28: sw          $t3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r11;
        goto L_801A9C18;
    // 0x801A9B28: sw          $t3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r11;
L_801A9B2C:
    // 0x801A9B2C: lui         $t4, 0x501
    ctx->r12 = S32(0X501 << 16);
    // 0x801A9B30: addiu       $t4, $t4, -0x5DD0
    ctx->r12 = ADD32(ctx->r12, -0X5DD0);
    // 0x801A9B34: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x801A9B38: sw          $t4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r12;
    // 0x801A9B3C: b           L_801A9C18
    // 0x801A9B40: sw          $t5, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r13;
        goto L_801A9C18;
    // 0x801A9B40: sw          $t5, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r13;
L_801A9B44:
    // 0x801A9B44: lui         $t6, 0x501
    ctx->r14 = S32(0X501 << 16);
    // 0x801A9B48: addiu       $t6, $t6, -0x5DD0
    ctx->r14 = ADD32(ctx->r14, -0X5DD0);
    // 0x801A9B4C: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x801A9B50: sw          $t6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r14;
    // 0x801A9B54: b           L_801A9C18
    // 0x801A9B58: sw          $t7, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r15;
        goto L_801A9C18;
    // 0x801A9B58: sw          $t7, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r15;
L_801A9B5C:
    // 0x801A9B5C: lui         $t8, 0x501
    ctx->r24 = S32(0X501 << 16);
    // 0x801A9B60: addiu       $t8, $t8, -0x5CE0
    ctx->r24 = ADD32(ctx->r24, -0X5CE0);
    // 0x801A9B64: addiu       $t9, $zero, 0x6
    ctx->r25 = ADD32(0, 0X6);
    // 0x801A9B68: sw          $t8, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r24;
    // 0x801A9B6C: b           L_801A9C18
    // 0x801A9B70: sw          $t9, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r25;
        goto L_801A9C18;
    // 0x801A9B70: sw          $t9, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r25;
L_801A9B74:
    // 0x801A9B74: lui         $t0, 0x501
    ctx->r8 = S32(0X501 << 16);
    // 0x801A9B78: addiu       $t0, $t0, -0x5CE0
    ctx->r8 = ADD32(ctx->r8, -0X5CE0);
    // 0x801A9B7C: addiu       $t1, $zero, 0x7
    ctx->r9 = ADD32(0, 0X7);
    // 0x801A9B80: sw          $t0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r8;
    // 0x801A9B84: b           L_801A9C18
    // 0x801A9B88: sw          $t1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r9;
        goto L_801A9C18;
    // 0x801A9B88: sw          $t1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r9;
L_801A9B8C:
    // 0x801A9B8C: lui         $t2, 0x501
    ctx->r10 = S32(0X501 << 16);
    // 0x801A9B90: addiu       $t2, $t2, -0x5CE0
    ctx->r10 = ADD32(ctx->r10, -0X5CE0);
    // 0x801A9B94: addiu       $t3, $zero, 0x8
    ctx->r11 = ADD32(0, 0X8);
    // 0x801A9B98: sw          $t2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r10;
    // 0x801A9B9C: b           L_801A9C18
    // 0x801A9BA0: sw          $t3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r11;
        goto L_801A9C18;
    // 0x801A9BA0: sw          $t3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r11;
L_801A9BA4:
    // 0x801A9BA4: lui         $t4, 0x501
    ctx->r12 = S32(0X501 << 16);
    // 0x801A9BA8: addiu       $t4, $t4, -0x5BF0
    ctx->r12 = ADD32(ctx->r12, -0X5BF0);
    // 0x801A9BAC: addiu       $t5, $zero, 0x9
    ctx->r13 = ADD32(0, 0X9);
    // 0x801A9BB0: sw          $t4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r12;
    // 0x801A9BB4: b           L_801A9C18
    // 0x801A9BB8: sw          $t5, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r13;
        goto L_801A9C18;
    // 0x801A9BB8: sw          $t5, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r13;
L_801A9BBC:
    // 0x801A9BBC: lui         $t6, 0x501
    ctx->r14 = S32(0X501 << 16);
    // 0x801A9BC0: addiu       $t6, $t6, -0x5BF0
    ctx->r14 = ADD32(ctx->r14, -0X5BF0);
    // 0x801A9BC4: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x801A9BC8: sw          $t6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r14;
    // 0x801A9BCC: b           L_801A9C18
    // 0x801A9BD0: sw          $t7, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r15;
        goto L_801A9C18;
    // 0x801A9BD0: sw          $t7, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r15;
L_801A9BD4:
    // 0x801A9BD4: lui         $t8, 0x501
    ctx->r24 = S32(0X501 << 16);
    // 0x801A9BD8: addiu       $t8, $t8, -0x5BF0
    ctx->r24 = ADD32(ctx->r24, -0X5BF0);
    // 0x801A9BDC: addiu       $t9, $zero, 0xB
    ctx->r25 = ADD32(0, 0XB);
    // 0x801A9BE0: sw          $t8, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r24;
    // 0x801A9BE4: b           L_801A9C18
    // 0x801A9BE8: sw          $t9, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r25;
        goto L_801A9C18;
    // 0x801A9BE8: sw          $t9, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r25;
L_801A9BEC:
    // 0x801A9BEC: lui         $t0, 0x501
    ctx->r8 = S32(0X501 << 16);
    // 0x801A9BF0: addiu       $t0, $t0, -0x5B00
    ctx->r8 = ADD32(ctx->r8, -0X5B00);
    // 0x801A9BF4: addiu       $t1, $zero, 0xC
    ctx->r9 = ADD32(0, 0XC);
    // 0x801A9BF8: sw          $t0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r8;
    // 0x801A9BFC: b           L_801A9C18
    // 0x801A9C00: sw          $t1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r9;
        goto L_801A9C18;
    // 0x801A9C00: sw          $t1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r9;
L_801A9C04:
    // 0x801A9C04: lui         $t2, 0x501
    ctx->r10 = S32(0X501 << 16);
    // 0x801A9C08: addiu       $t2, $t2, -0x5B00
    ctx->r10 = ADD32(ctx->r10, -0X5B00);
    // 0x801A9C0C: addiu       $t3, $zero, 0xD
    ctx->r11 = ADD32(0, 0XD);
    // 0x801A9C10: sw          $t2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r10;
    // 0x801A9C14: sw          $t3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r11;
L_801A9C18:
    // 0x801A9C18: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x801A9C1C: addiu       $s2, $s2, 0x7E64
    ctx->r18 = ADD32(ctx->r18, 0X7E64);
    // 0x801A9C20: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x801A9C24: jal         0x800B8DD0
    // 0x801A9C28: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x801A9C28: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    after_0:
    // 0x801A9C2C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801A9C30: lui         $s0, 0x801B
    ctx->r16 = S32(0X801B << 16);
    // 0x801A9C34: lui         $s1, 0x801B
    ctx->r17 = S32(0X801B << 16);
    // 0x801A9C38: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x801A9C3C: addiu       $s1, $s1, 0x6AC8
    ctx->r17 = ADD32(ctx->r17, 0X6AC8);
    // 0x801A9C40: addiu       $s0, $s0, 0x6AC0
    ctx->r16 = ADD32(ctx->r16, 0X6AC0);
    // 0x801A9C44: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x801A9C48: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x801A9C4C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x801A9C50: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x801A9C54: sw          $t4, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r12;
    // 0x801A9C58: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x801A9C5C: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x801A9C60: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x801A9C64: lwc1        $f6, 0x0($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X0);
    // 0x801A9C68: lui         $a1, 0x500
    ctx->r5 = S32(0X500 << 16);
    // 0x801A9C6C: addiu       $a1, $a1, 0x500
    ctx->r5 = ADD32(ctx->r5, 0X500);
    // 0x801A9C70: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x801A9C74: addiu       $a2, $zero, 0x70
    ctx->r6 = ADD32(0, 0X70);
    // 0x801A9C78: addiu       $a3, $zero, 0x13
    ctx->r7 = ADD32(0, 0X13);
    // 0x801A9C7C: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x801A9C80: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x801A9C84: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x801A9C88: jal         0x8009D994
    // 0x801A9C8C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_1;
    // 0x801A9C8C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x801A9C90: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801A9C94: lwc1        $f10, 0x4($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X4);
    // 0x801A9C98: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x801A9C9C: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x801A9CA0: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x801A9CA4: addiu       $a3, $zero, 0xF
    ctx->r7 = ADD32(0, 0XF);
    // 0x801A9CA8: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x801A9CAC: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x801A9CB0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x801A9CB4: jal         0x8009D994
    // 0x801A9CB8: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_2;
    // 0x801A9CB8: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_2:
    // 0x801A9CBC: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
    // 0x801A9CC0: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x801A9CC4: addiu       $t9, $t9, -0x7CC
    ctx->r25 = ADD32(ctx->r25, -0X7CC);
    // 0x801A9CC8: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x801A9CCC: addu        $s1, $t8, $t9
    ctx->r17 = ADD32(ctx->r24, ctx->r25);
    // 0x801A9CD0: lw          $t0, 0x8($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X8);
    // 0x801A9CD4: sw          $t8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r24;
    // 0x801A9CD8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801A9CDC: blez        $t0, L_801A9D48
    if (SIGNED(ctx->r8) <= 0) {
        // 0x801A9CE0: lui         $at, 0x42BC
        ctx->r1 = S32(0X42BC << 16);
            goto L_801A9D48;
    }
    // 0x801A9CE0: lui         $at, 0x42BC
    ctx->r1 = S32(0X42BC << 16);
    // 0x801A9CE4: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x801A9CE8: nop

    // 0x801A9CEC: lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X4);
L_801A9CF0:
    // 0x801A9CF0: mtc1        $s0, $f18
    ctx->f18.u32l = ctx->r16;
    // 0x801A9CF4: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x801A9CF8: multu       $v0, $s0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801A9CFC: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x801A9D00: lwc1        $f16, 0xC($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0XC);
    // 0x801A9D04: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x801A9D08: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801A9D0C: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x801A9D10: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x801A9D14: add.s       $f6, $f4, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f22.fl;
    // 0x801A9D18: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x801A9D1C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x801A9D20: mflo        $t1
    ctx->r9 = lo;
    // 0x801A9D24: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x801A9D28: jal         0x8009D994
    // 0x801A9D2C: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_3;
    // 0x801A9D2C: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    after_3:
    // 0x801A9D30: lw          $t3, 0x8($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X8);
    // 0x801A9D34: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801A9D38: slt         $at, $s0, $t3
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x801A9D3C: bnel        $at, $zero, L_801A9CF0
    if (ctx->r1 != 0) {
        // 0x801A9D40: lw          $v0, 0x4($s1)
        ctx->r2 = MEM_W(ctx->r17, 0X4);
            goto L_801A9CF0;
    }
    goto skip_0;
    // 0x801A9D40: lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X4);
    skip_0:
    // 0x801A9D44: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_801A9D48:
    // 0x801A9D48: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x801A9D4C: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x801A9D50: addiu       $t5, $t5, -0x6EC
    ctx->r13 = ADD32(ctx->r13, -0X6EC);
    // 0x801A9D54: addu        $s1, $t4, $t5
    ctx->r17 = ADD32(ctx->r12, ctx->r13);
    // 0x801A9D58: lw          $t6, 0x8($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X8);
    // 0x801A9D5C: lui         $at, 0x430C
    ctx->r1 = S32(0X430C << 16);
    // 0x801A9D60: blezl       $t6, L_801A9DCC
    if (SIGNED(ctx->r14) <= 0) {
        // 0x801A9D64: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_801A9DCC;
    }
    goto skip_1;
    // 0x801A9D64: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_1:
    // 0x801A9D68: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x801A9D6C: nop

    // 0x801A9D70: lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X4);
L_801A9D74:
    // 0x801A9D74: mtc1        $s0, $f10
    ctx->f10.u32l = ctx->r16;
    // 0x801A9D78: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x801A9D7C: multu       $v0, $s0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801A9D80: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801A9D84: lwc1        $f8, 0xC($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XC);
    // 0x801A9D88: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x801A9D8C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801A9D90: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x801A9D94: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x801A9D98: add.s       $f18, $f16, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f22.fl;
    // 0x801A9D9C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x801A9DA0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x801A9DA4: mflo        $t7
    ctx->r15 = lo;
    // 0x801A9DA8: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x801A9DAC: jal         0x8009D994
    // 0x801A9DB0: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_4;
    // 0x801A9DB0: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_4:
    // 0x801A9DB4: lw          $t9, 0x8($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X8);
    // 0x801A9DB8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801A9DBC: slt         $at, $s0, $t9
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x801A9DC0: bnel        $at, $zero, L_801A9D74
    if (ctx->r1 != 0) {
        // 0x801A9DC4: lw          $v0, 0x4($s1)
        ctx->r2 = MEM_W(ctx->r17, 0X4);
            goto L_801A9D74;
    }
    goto skip_2;
    // 0x801A9DC4: lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X4);
    skip_2:
    // 0x801A9DC8: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_801A9DCC:
    // 0x801A9DCC: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x801A9DD0: ldc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X30);
    // 0x801A9DD4: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x801A9DD8: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x801A9DDC: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x801A9DE0: jr          $ra
    // 0x801A9DE4: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x801A9DE4: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
