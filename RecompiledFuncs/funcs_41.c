#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void Macbeth_MaBarrier_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A6540: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801A6544: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801A6548: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801A654C: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x801A6550: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801A6554: jal         0x800B8DD0
    // 0x801A6558: addiu       $a1, $zero, 0x39
    ctx->r5 = ADD32(0, 0X39);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x801A6558: addiu       $a1, $zero, 0x39
    ctx->r5 = ADD32(0, 0X39);
    after_0:
    // 0x801A655C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x801A6560: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801A6564: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x801A6568: lhu         $t7, 0xC6($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0XC6);
    // 0x801A656C: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x801A6570: beql        $t8, $zero, L_801A65AC
    if (ctx->r24 == 0) {
        // 0x801A6574: lw          $v1, 0x0($a0)
        ctx->r3 = MEM_W(ctx->r4, 0X0);
            goto L_801A65AC;
    }
    goto skip_0;
    // 0x801A6574: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    skip_0:
    // 0x801A6578: jal         0x800B8DD0
    // 0x801A657C: addiu       $a1, $zero, 0x3A
    ctx->r5 = ADD32(0, 0X3A);
    RCP_SetupDL(rdram, ctx);
        goto after_1;
    // 0x801A657C: addiu       $a1, $zero, 0x3A
    ctx->r5 = ADD32(0, 0X3A);
    after_1:
    // 0x801A6580: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801A6584: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x801A6588: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x801A658C: lui         $t1, 0xFF00
    ctx->r9 = S32(0XFF00 << 16);
    // 0x801A6590: ori         $t1, $t1, 0xFF
    ctx->r9 = ctx->r9 | 0XFF;
    // 0x801A6594: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x801A6598: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x801A659C: lui         $t0, 0xFA00
    ctx->r8 = S32(0XFA00 << 16);
    // 0x801A65A0: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x801A65A4: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x801A65A8: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
L_801A65AC:
    // 0x801A65AC: lui         $t4, 0x602
    ctx->r12 = S32(0X602 << 16);
    // 0x801A65B0: addiu       $t4, $t4, 0x57B0
    ctx->r12 = ADD32(ctx->r12, 0X57B0);
    // 0x801A65B4: addiu       $t2, $v1, 0x8
    ctx->r10 = ADD32(ctx->r3, 0X8);
    // 0x801A65B8: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x801A65BC: lui         $t3, 0x600
    ctx->r11 = S32(0X600 << 16);
    // 0x801A65C0: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x801A65C4: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x801A65C8: jal         0x800B8DD0
    // 0x801A65CC: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    RCP_SetupDL(rdram, ctx);
        goto after_2;
    // 0x801A65CC: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    after_2:
    // 0x801A65D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801A65D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801A65D8: jr          $ra
    // 0x801A65DC: nop

    return;
    // 0x801A65DC: nop

;}
RECOMP_FUNC void Macbeth_MaBoulder_Spawn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019D670: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8019D674: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8019D678: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8019D67C: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x8019D680: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8019D684: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8019D688: addiu       $v0, $v0, -0xEF0
    ctx->r2 = ADD32(ctx->r2, -0XEF0);
    // 0x8019D68C: addiu       $a0, $a0, 0x3FE0
    ctx->r4 = ADD32(ctx->r4, 0X3FE0);
    // 0x8019D690: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
L_8019D694:
    // 0x8019D694: bnel        $t6, $zero, L_8019D6E8
    if (ctx->r14 != 0) {
        // 0x8019D698: addiu       $a0, $a0, 0x2F4
        ctx->r4 = ADD32(ctx->r4, 0X2F4);
            goto L_8019D6E8;
    }
    goto skip_0;
    // 0x8019D698: addiu       $a0, $a0, 0x2F4
    ctx->r4 = ADD32(ctx->r4, 0X2F4);
    skip_0:
    // 0x8019D69C: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8019D6A0: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8019D6A4: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8019D6A8: lwc1        $f10, 0x48($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8019D6AC: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x8019D6B0: lbu         $t8, 0x53($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X53);
    // 0x8019D6B4: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8019D6B8: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x8019D6BC: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x8019D6C0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8019D6C4: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x8019D6C8: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x8019D6CC: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x8019D6D0: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x8019D6D4: jal         0x8019D5C8
    // 0x8019D6D8: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    Macbeth_MaBoulder_Setup(rdram, ctx);
        goto after_0;
    // 0x8019D6D8: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    after_0:
    // 0x8019D6DC: b           L_8019D6F4
    // 0x8019D6E0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8019D6F4;
    // 0x8019D6E0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8019D6E4: addiu       $a0, $a0, 0x2F4
    ctx->r4 = ADD32(ctx->r4, 0X2F4);
L_8019D6E8:
    // 0x8019D6E8: bnel        $a0, $v0, L_8019D694
    if (ctx->r4 != ctx->r2) {
        // 0x8019D6EC: lbu         $t6, 0x0($a0)
        ctx->r14 = MEM_BU(ctx->r4, 0X0);
            goto L_8019D694;
    }
    goto skip_1;
    // 0x8019D6EC: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    skip_1:
    // 0x8019D6F0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8019D6F4:
    // 0x8019D6F4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8019D6F8: jr          $ra
    // 0x8019D6FC: nop

    return;
    // 0x8019D6FC: nop

;}
RECOMP_FUNC void Macbeth_8019A87C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019A87C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8019A880: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8019A884: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8019A888: lw          $t6, -0x7D80($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7D80);
    // 0x8019A88C: lwc1        $f6, 0xC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8019A890: lui         $at, 0xC4FA
    ctx->r1 = S32(0XC4FA << 16);
    // 0x8019A894: lwc1        $f4, 0x138($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X138);
    // 0x8019A898: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8019A89C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8019A8A0: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x8019A8A4: nop

    // 0x8019A8A8: bc1fl       L_8019A8BC
    if (!c1cs) {
        // 0x8019A8AC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8019A8BC;
    }
    goto skip_0;
    // 0x8019A8AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8019A8B0: jal         0x80060FBC
    // 0x8019A8B4: addiu       $a1, $a0, 0x100
    ctx->r5 = ADD32(ctx->r4, 0X100);
    Object_Kill(rdram, ctx);
        goto after_0;
    // 0x8019A8B4: addiu       $a1, $a0, 0x100
    ctx->r5 = ADD32(ctx->r4, 0X100);
    after_0:
    // 0x8019A8B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8019A8BC:
    // 0x8019A8BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8019A8C0: jr          $ra
    // 0x8019A8C4: nop

    return;
    // 0x8019A8C4: nop

;}
RECOMP_FUNC void Titania_TiPillar_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018F8B8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8018F8BC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8018F8C0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8018F8C4: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8018F8C8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8018F8CC: lw          $v1, 0x44($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X44);
    // 0x8018F8D0: beq         $v1, $zero, L_8018F8F4
    if (ctx->r3 == 0) {
        // 0x8018F8D4: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8018F8F4;
    }
    // 0x8018F8D4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8018F8D8: beq         $v0, $at, L_8018F958
    if (ctx->r2 == ctx->r1) {
        // 0x8018F8DC: lw          $t3, 0x20($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X20);
            goto L_8018F958;
    }
    // 0x8018F8DC: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x8018F8E0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8018F8E4: beql        $v0, $at, L_8018F95C
    if (ctx->r2 == ctx->r1) {
        // 0x8018F8E8: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_8018F95C;
    }
    goto skip_0;
    // 0x8018F8E8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_0:
    // 0x8018F8EC: b           L_8018FA3C
    // 0x8018F8F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8018FA3C;
    // 0x8018F8F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8018F8F4:
    // 0x8018F8F4: bne         $v1, $zero, L_8018F92C
    if (ctx->r3 != 0) {
        // 0x8018F8F8: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_8018F92C;
    }
    // 0x8018F8F8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8018F8FC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8018F900: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8018F904: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8018F908: lui         $t9, 0x700
    ctx->r25 = S32(0X700 << 16);
    // 0x8018F90C: addiu       $t9, $t9, 0x2270
    ctx->r25 = ADD32(ctx->r25, 0X2270);
    // 0x8018F910: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8018F914: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8018F918: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x8018F91C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8018F920: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8018F924: b           L_8018FA3C
    // 0x8018F928: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8018FA3C;
    // 0x8018F928: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8018F92C:
    // 0x8018F92C: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8018F930: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8018F934: lui         $t2, 0x700
    ctx->r10 = S32(0X700 << 16);
    // 0x8018F938: addiu       $t2, $t2, 0xA80
    ctx->r10 = ADD32(ctx->r10, 0XA80);
    // 0x8018F93C: addiu       $t0, $v0, 0x8
    ctx->r8 = ADD32(ctx->r2, 0X8);
    // 0x8018F940: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
    // 0x8018F944: lui         $t1, 0x600
    ctx->r9 = S32(0X600 << 16);
    // 0x8018F948: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x8018F94C: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x8018F950: b           L_8018FA3C
    // 0x8018F954: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8018FA3C;
    // 0x8018F954: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8018F958:
    // 0x8018F958: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_8018F95C:
    // 0x8018F95C: lwc1        $f2, 0x18($t3)
    ctx->f2.u32l = MEM_W(ctx->r11, 0X18);
    // 0x8018F960: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    // 0x8018F964: nop

    // 0x8018F968: bc1t        L_8018F9E4
    if (c1cs) {
        // 0x8018F96C: nop
    
            goto L_8018F9E4;
    }
    // 0x8018F96C: nop

    // 0x8018F970: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8018F974: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8018F978: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018F97C: lui         $a1, 0xC296
    ctx->r5 = S32(0XC296 << 16);
    // 0x8018F980: bc1f        L_8018F9BC
    if (!c1cs) {
        // 0x8018F984: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_8018F9BC;
    }
    // 0x8018F984: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8018F988: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018F98C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8018F990: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8018F994: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8018F998: lui         $a1, 0x4296
    ctx->r5 = S32(0X4296 << 16);
    // 0x8018F99C: jal         0x80005B00
    // 0x8018F9A0: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    Matrix_Translate(rdram, ctx);
        goto after_0;
    // 0x8018F9A0: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_0:
    // 0x8018F9A4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8018F9A8: jal         0x80006EB8
    // 0x8018F9AC: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_1;
    // 0x8018F9AC: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    after_1:
    // 0x8018F9B0: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x8018F9B4: b           L_8018F9E4
    // 0x8018F9B8: lw          $v1, 0x44($t5)
    ctx->r3 = MEM_W(ctx->r13, 0X44);
        goto L_8018F9E4;
    // 0x8018F9B8: lw          $v1, 0x44($t5)
    ctx->r3 = MEM_W(ctx->r13, 0X44);
L_8018F9BC:
    // 0x8018F9BC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8018F9C0: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8018F9C4: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8018F9C8: jal         0x80005B00
    // 0x8018F9CC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    Matrix_Translate(rdram, ctx);
        goto after_2;
    // 0x8018F9CC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_2:
    // 0x8018F9D0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8018F9D4: jal         0x80006EB8
    // 0x8018F9D8: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_3;
    // 0x8018F9D8: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    after_3:
    // 0x8018F9DC: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8018F9E0: lw          $v1, 0x44($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X44);
L_8018F9E4:
    // 0x8018F9E4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8018F9E8: bne         $v1, $zero, L_8018FA18
    if (ctx->r3 != 0) {
        // 0x8018F9EC: addiu       $a0, $a0, 0x7E64
        ctx->r4 = ADD32(ctx->r4, 0X7E64);
            goto L_8018FA18;
    }
    // 0x8018F9EC: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8018F9F0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8018F9F4: lui         $t0, 0x700
    ctx->r8 = S32(0X700 << 16);
    // 0x8018F9F8: addiu       $t0, $t0, 0x2270
    ctx->r8 = ADD32(ctx->r8, 0X2270);
    // 0x8018F9FC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8018FA00: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8018FA04: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x8018FA08: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8018FA0C: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x8018FA10: b           L_8018FA3C
    // 0x8018FA14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8018FA3C;
    // 0x8018FA14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8018FA18:
    // 0x8018FA18: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8018FA1C: lui         $t3, 0x700
    ctx->r11 = S32(0X700 << 16);
    // 0x8018FA20: addiu       $t3, $t3, 0xA80
    ctx->r11 = ADD32(ctx->r11, 0XA80);
    // 0x8018FA24: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x8018FA28: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x8018FA2C: lui         $t2, 0x600
    ctx->r10 = S32(0X600 << 16);
    // 0x8018FA30: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x8018FA34: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x8018FA38: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8018FA3C:
    // 0x8018FA3C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8018FA40: jr          $ra
    // 0x8018FA44: nop

    return;
    // 0x8018FA44: nop

;}
RECOMP_FUNC void Titania_TiDelphorHead_Init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018E5E8: addiu       $t6, $zero, 0x64
    ctx->r14 = ADD32(0, 0X64);
    // 0x8018E5EC: sh          $t6, 0xCE($a0)
    MEM_H(0XCE, ctx->r4) = ctx->r14;
    // 0x8018E5F0: jr          $ra
    // 0x8018E5F4: nop

    return;
    // 0x8018E5F4: nop

;}
RECOMP_FUNC void Macbeth_MaProximityLight_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A6608: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801A660C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801A6610: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801A6614: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801A6618: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x801A661C: lw          $t6, -0x7D80($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7D80);
    // 0x801A6620: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x801A6624: lwc1        $f10, 0x6C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x801A6628: lwc1        $f4, 0x138($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X138);
    // 0x801A662C: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x801A6630: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801A6634: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x801A6638: nop

    // 0x801A663C: bc1f        L_801A6754
    if (!c1cs) {
        // 0x801A6640: nop
    
            goto L_801A6754;
    }
    // 0x801A6640: nop

    // 0x801A6644: lw          $t7, 0x7854($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7854);
    // 0x801A6648: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x801A664C: addiu       $a0, $s0, 0x64
    ctx->r4 = ADD32(ctx->r16, 0X64);
    // 0x801A6650: beq         $t7, $at, L_801A6698
    if (ctx->r15 == ctx->r1) {
        // 0x801A6654: lui         $a1, 0x41F0
        ctx->r5 = S32(0X41F0 << 16);
            goto L_801A6698;
    }
    // 0x801A6654: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    // 0x801A6658: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801A665C: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    // 0x801A6660: lui         $a3, 0x41F0
    ctx->r7 = S32(0X41F0 << 16);
    // 0x801A6664: jal         0x8009BC2C
    // 0x801A6668: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_0;
    // 0x801A6668: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_0:
    // 0x801A666C: lui         $at, 0x41F8
    ctx->r1 = S32(0X41F8 << 16);
    // 0x801A6670: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801A6674: lwc1        $f18, 0x64($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X64);
    // 0x801A6678: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x801A667C: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x801A6680: nop

    // 0x801A6684: bc1f        L_801A6698
    if (!c1cs) {
        // 0x801A6688: nop
    
            goto L_801A6698;
    }
    // 0x801A6688: nop

    // 0x801A668C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801A6690: nop

    // 0x801A6694: swc1        $f6, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->f6.u32l;
L_801A6698:
    // 0x801A6698: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801A669C: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x801A66A0: jal         0x800B8DD0
    // 0x801A66A4: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    RCP_SetupDL(rdram, ctx);
        goto after_1;
    // 0x801A66A4: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    after_1:
    // 0x801A66A8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801A66AC: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x801A66B0: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x801A66B4: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x801A66B8: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x801A66BC: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x801A66C0: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x801A66C4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801A66C8: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x801A66CC: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x801A66D0: lwc1        $f8, 0x64($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X64);
    // 0x801A66D4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801A66D8: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x801A66DC: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x801A66E0: nop

    // 0x801A66E4: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x801A66E8: beql        $t1, $zero, L_801A6738
    if (ctx->r9 == 0) {
        // 0x801A66EC: mfc1        $t1, $f10
        ctx->r9 = (int32_t)ctx->f10.u32l;
            goto L_801A6738;
    }
    goto skip_0;
    // 0x801A66EC: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    skip_0:
    // 0x801A66F0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801A66F4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801A66F8: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x801A66FC: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x801A6700: nop

    // 0x801A6704: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x801A6708: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x801A670C: nop

    // 0x801A6710: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x801A6714: bne         $t1, $zero, L_801A672C
    if (ctx->r9 != 0) {
        // 0x801A6718: nop
    
            goto L_801A672C;
    }
    // 0x801A6718: nop

    // 0x801A671C: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    // 0x801A6720: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801A6724: b           L_801A6744
    // 0x801A6728: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
        goto L_801A6744;
    // 0x801A6728: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
L_801A672C:
    // 0x801A672C: b           L_801A6744
    // 0x801A6730: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
        goto L_801A6744;
    // 0x801A6730: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x801A6734: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
L_801A6738:
    // 0x801A6738: nop

    // 0x801A673C: bltz        $t1, L_801A672C
    if (SIGNED(ctx->r9) < 0) {
        // 0x801A6740: nop
    
            goto L_801A672C;
    }
    // 0x801A6740: nop

L_801A6744:
    // 0x801A6744: sll         $t3, $t1, 24
    ctx->r11 = S32(ctx->r9 << 24);
    // 0x801A6748: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x801A674C: ori         $t4, $t3, 0xFF
    ctx->r12 = ctx->r11 | 0XFF;
    // 0x801A6750: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
L_801A6754:
    // 0x801A6754: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801A6758: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x801A675C: lui         $s0, 0x600
    ctx->r16 = S32(0X600 << 16);
    // 0x801A6760: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x801A6764: lui         $t6, 0x601
    ctx->r14 = S32(0X601 << 16);
    // 0x801A6768: addiu       $t6, $t6, 0x700
    ctx->r14 = ADD32(ctx->r14, 0X700);
    // 0x801A676C: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x801A6770: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x801A6774: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x801A6778: sw          $s0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r16;
    // 0x801A677C: jal         0x800B8DD0
    // 0x801A6780: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    RCP_SetupDL(rdram, ctx);
        goto after_2;
    // 0x801A6780: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    after_2:
    // 0x801A6784: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801A6788: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x801A678C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x801A6790: lui         $t8, 0x602
    ctx->r24 = S32(0X602 << 16);
    // 0x801A6794: addiu       $t8, $t8, -0xD90
    ctx->r24 = ADD32(ctx->r24, -0XD90);
    // 0x801A6798: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801A679C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x801A67A0: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x801A67A4: sw          $s0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r16;
    // 0x801A67A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801A67AC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801A67B0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801A67B4: jr          $ra
    // 0x801A67B8: nop

    return;
    // 0x801A67B8: nop

;}
RECOMP_FUNC void Macbeth_8019C5B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019C5B8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8019C5BC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8019C5C0: lui         $at, 0x4402
    ctx->r1 = S32(0X4402 << 16);
    // 0x8019C5C4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8019C5C8: lwc1        $f4, 0xC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8019C5CC: lw          $a2, 0x14($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X14);
    // 0x8019C5D0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8019C5D4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8019C5D8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8019C5DC: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8019C5E0: jal         0x801A0308
    // 0x8019C5E4: nop

    Macbeth_801A0308(rdram, ctx);
        goto after_0;
    // 0x8019C5E4: nop

    after_0:
    // 0x8019C5E8: jal         0x80004EB0
    // 0x8019C5EC: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x8019C5EC: nop

    after_1:
    // 0x8019C5F0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8019C5F4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8019C5F8: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x8019C5FC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019C600: sub.s       $f18, $f0, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x8019C604: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x8019C608: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8019C60C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8019C610: mul.s       $f2, $f18, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8019C614: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8019C618: c.lt.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl < ctx->f2.fl;
    // 0x8019C61C: mov.s       $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    ctx->f16.fl = ctx->f2.fl;
    // 0x8019C620: bc1fl       L_8019C674
    if (!c1cs) {
        // 0x8019C624: lui         $at, 0x4396
        ctx->r1 = S32(0X4396 << 16);
            goto L_8019C674;
    }
    goto skip_0;
    // 0x8019C624: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    skip_0:
    // 0x8019C628: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8019C62C: nop

    // 0x8019C630: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x8019C634: nop

    // 0x8019C638: bc1fl       L_8019C674
    if (!c1cs) {
        // 0x8019C63C: lui         $at, 0x4396
        ctx->r1 = S32(0X4396 << 16);
            goto L_8019C674;
    }
    goto skip_1;
    // 0x8019C63C: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    skip_1:
    // 0x8019C640: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8019C644: lui         $at, 0xC020
    ctx->r1 = S32(0XC020 << 16);
    // 0x8019C648: c.le.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl <= ctx->f2.fl;
    // 0x8019C64C: nop

    // 0x8019C650: bc1fl       L_8019C66C
    if (!c1cs) {
        // 0x8019C654: mtc1        $at, $f16
        ctx->f16.u32l = ctx->r1;
            goto L_8019C66C;
    }
    goto skip_2;
    // 0x8019C654: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    skip_2:
    // 0x8019C658: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x8019C65C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8019C660: b           L_8019C674
    // 0x8019C664: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
        goto L_8019C674;
    // 0x8019C664: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x8019C668: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
L_8019C66C:
    // 0x8019C66C: nop

    // 0x8019C670: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
L_8019C674:
    // 0x8019C674: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019C678: lui         $at, 0x4402
    ctx->r1 = S32(0X4402 << 16);
    // 0x8019C67C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8019C680: lwc1        $f6, 0xC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8019C684: lwc1        $f18, 0x8($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8019C688: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8019C68C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8019C690: lwc1        $f12, 0x160($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X160);
    // 0x8019C694: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x8019C698: add.s       $f14, $f18, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8019C69C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8019C6A0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8019C6A4: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x8019C6A8: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x8019C6AC: jal         0x801AF200
    // 0x8019C6B0: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Macbeth_MaShockBox_Spawn(rdram, ctx);
        goto after_2;
    // 0x8019C6B0: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_2:
    // 0x8019C6B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8019C6B8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8019C6BC: jr          $ra
    // 0x8019C6C0: nop

    return;
    // 0x8019C6C0: nop

;}
RECOMP_FUNC void Titania_801891F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801891F4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x801891F8: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x801891FC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80189200: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80189204: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x80189208: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8018920C: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80189210: lw          $v0, -0x7D80($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D80);
    // 0x80189214: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80189218: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8018921C: lwc1        $f8, 0x8C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8C);
    // 0x80189220: lwc1        $f10, 0x138($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X138);
    // 0x80189224: lwc1        $f4, 0x74($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X74);
    // 0x80189228: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8018922C: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80189230: jal         0x80005100
    // 0x80189234: sub.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f18.fl;
    Math_Atan2F(rdram, ctx);
        goto after_0;
    // 0x80189234: sub.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f18.fl;
    after_0:
    // 0x80189238: jal         0x8009F768
    // 0x8018923C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    Math_RadToDeg(rdram, ctx);
        goto after_1;
    // 0x8018923C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_1:
    // 0x80189240: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x80189244: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80189248: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x8018924C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80189250: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x80189254: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80189258: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8018925C: addiu       $a0, $s0, 0x14
    ctx->r4 = ADD32(ctx->r16, 0X14);
    // 0x80189260: bc1f        L_80189284
    if (!c1cs) {
        // 0x80189264: lui         $a3, 0x40C0
        ctx->r7 = S32(0X40C0 << 16);
            goto L_80189284;
    }
    // 0x80189264: lui         $a3, 0x40C0
    ctx->r7 = S32(0X40C0 << 16);
    // 0x80189268: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018926C: nop

    // 0x80189270: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80189274: nop

    // 0x80189278: bc1f        L_80189284
    if (!c1cs) {
        // 0x8018927C: nop
    
            goto L_80189284;
    }
    // 0x8018927C: nop

    // 0x80189280: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
L_80189284:
    // 0x80189284: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80189288: lwc1        $f0, -0x5494($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5494);
    // 0x8018928C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80189290: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80189294: nop

    // 0x80189298: bc1f        L_801892BC
    if (!c1cs) {
        // 0x8018929C: nop
    
            goto L_801892BC;
    }
    // 0x8018929C: nop

    // 0x801892A0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801892A4: nop

    // 0x801892A8: c.lt.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl < ctx->f2.fl;
    // 0x801892AC: nop

    // 0x801892B0: bc1f        L_801892BC
    if (!c1cs) {
        // 0x801892B4: nop
    
            goto L_801892BC;
    }
    // 0x801892B4: nop

    // 0x801892B8: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_801892BC:
    // 0x801892BC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801892C0: lwc1        $f8, -0x5490($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X5490);
    // 0x801892C4: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x801892C8: jal         0x8009BD38
    // 0x801892CC: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_2;
    // 0x801892CC: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x801892D0: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801892D4: lwc1        $f16, 0x114($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X114);
    // 0x801892D8: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x801892DC: lw          $v0, -0x7D80($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D80);
    // 0x801892E0: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801892E4: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801892E8: lwc1        $f4, 0x74($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X74);
    // 0x801892EC: lwc1        $f8, 0x118($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X118);
    // 0x801892F0: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801892F4: sub.s       $f20, $f18, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x801892F8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801892FC: lwc1        $f16, 0x78($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X78);
    // 0x80189300: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80189304: lwc1        $f8, 0x11C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X11C);
    // 0x80189308: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8018930C: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80189310: lwc1        $f18, 0x138($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X138);
    // 0x80189314: add.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80189318: mul.s       $f6, $f20, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x8018931C: sub.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80189320: lwc1        $f4, 0x8C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8C);
    // 0x80189324: sub.s       $f10, $f16, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80189328: add.s       $f22, $f4, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f22.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8018932C: mul.s       $f8, $f22, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x80189330: add.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80189334: jal         0x80005100
    // 0x80189338: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    Math_Atan2F(rdram, ctx);
        goto after_3;
    // 0x80189338: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    after_3:
    // 0x8018933C: jal         0x8009F768
    // 0x80189340: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    Math_RadToDeg(rdram, ctx);
        goto after_4;
    // 0x80189340: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_4:
    // 0x80189344: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80189348: lwc1        $f16, -0x548C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X548C);
    // 0x8018934C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80189350: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x80189354: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80189358: addiu       $a0, $s0, 0x128
    ctx->r4 = ADD32(ctx->r16, 0X128);
    // 0x8018935C: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x80189360: jal         0x8009BD38
    // 0x80189364: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_5;
    // 0x80189364: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_5:
    // 0x80189368: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8018936C: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80189370: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x80189374: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80189378: jr          $ra
    // 0x8018937C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8018937C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void Titania_8018B1B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018B1B4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8018B1B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018B1BC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8018B1C0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8018B1C4: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8018B1C8: addiu       $v1, $v1, -0x25D0
    ctx->r3 = ADD32(ctx->r3, -0X25D0);
    // 0x8018B1CC: sll         $t6, $v1, 4
    ctx->r14 = S32(ctx->r3 << 4);
    // 0x8018B1D0: srl         $t7, $t6, 28
    ctx->r15 = S32(U32(ctx->r14) >> 28);
    // 0x8018B1D4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8018B1D8: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8018B1DC: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8018B1E0: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8018B1E4: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8018B1E8: lw          $t9, 0x1FD0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X1FD0);
    // 0x8018B1EC: and         $t0, $v1, $at
    ctx->r8 = ctx->r3 & ctx->r1;
    // 0x8018B1F0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8018B1F4: lui         $v1, 0x801B
    ctx->r3 = S32(0X801B << 16);
    // 0x8018B1F8: lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // 0x8018B1FC: addu        $a2, $t9, $t0
    ctx->r6 = ADD32(ctx->r25, ctx->r8);
    // 0x8018B200: addu        $a2, $a2, $at
    ctx->r6 = ADD32(ctx->r6, ctx->r1);
    // 0x8018B204: addiu       $v0, $v0, 0x75D0
    ctx->r2 = ADD32(ctx->r2, 0X75D0);
    // 0x8018B208: addiu       $v1, $v1, 0x75E4
    ctx->r3 = ADD32(ctx->r3, 0X75E4);
L_8018B20C:
    // 0x8018B20C: lh          $t1, 0x0($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X0);
    // 0x8018B210: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x8018B214: bne         $a0, $t1, L_8018B250
    if (ctx->r4 != ctx->r9) {
        // 0x8018B218: nop
    
            goto L_8018B250;
    }
    // 0x8018B218: nop

    // 0x8018B21C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018B220: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8018B224: addiu       $a1, $a1, -0x60D4
    ctx->r5 = ADD32(ctx->r5, -0X60D4);
    // 0x8018B228: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018B22C: jal         0x80006970
    // 0x8018B230: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    Matrix_MultVec3f(rdram, ctx);
        goto after_0;
    // 0x8018B230: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x8018B234: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8018B238: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018B23C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018B240: jal         0x80006AB8
    // 0x8018B244: addiu       $a1, $a2, 0xC
    ctx->r5 = ADD32(ctx->r6, 0XC);
    Matrix_GetYPRAngles(rdram, ctx);
        goto after_1;
    // 0x8018B244: addiu       $a1, $a2, 0xC
    ctx->r5 = ADD32(ctx->r6, 0XC);
    after_1:
    // 0x8018B248: b           L_8018B25C
    // 0x8018B24C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8018B25C;
    // 0x8018B24C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8018B250:
    // 0x8018B250: bne         $v0, $v1, L_8018B20C
    if (ctx->r2 != ctx->r3) {
        // 0x8018B254: addiu       $a2, $a2, 0x18
        ctx->r6 = ADD32(ctx->r6, 0X18);
            goto L_8018B20C;
    }
    // 0x8018B254: addiu       $a2, $a2, 0x18
    ctx->r6 = ADD32(ctx->r6, 0X18);
    // 0x8018B258: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8018B25C:
    // 0x8018B25C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8018B260: jr          $ra
    // 0x8018B264: nop

    return;
    // 0x8018B264: nop

;}
RECOMP_FUNC void Macbeth_MaSpear_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801ADD68: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x801ADD6C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801ADD70: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801ADD74: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801ADD78: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x801ADD7C: addiu       $t7, $t7, -0x5888
    ctx->r15 = ADD32(ctx->r15, -0X5888);
    // 0x801ADD80: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x801ADD84: addiu       $t6, $sp, 0x3C
    ctx->r14 = ADD32(ctx->r29, 0X3C);
    // 0x801ADD88: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x801ADD8C: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x801ADD90: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x801ADD94: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x801ADD98: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x801ADD9C: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x801ADDA0: lw          $t1, -0x7D80($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X7D80);
    // 0x801ADDA4: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x801ADDA8: lui         $at, 0xC3FA
    ctx->r1 = S32(0XC3FA << 16);
    // 0x801ADDAC: lwc1        $f4, 0x138($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X138);
    // 0x801ADDB0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801ADDB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801ADDB8: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801ADDBC: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x801ADDC0: nop

    // 0x801ADDC4: bc1fl       L_801ADDD8
    if (!c1cs) {
        // 0x801ADDC8: lh          $v0, 0xB8($s0)
        ctx->r2 = MEM_H(ctx->r16, 0XB8);
            goto L_801ADDD8;
    }
    goto skip_0;
    // 0x801ADDC8: lh          $v0, 0xB8($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XB8);
    skip_0:
    // 0x801ADDCC: jal         0x80060FBC
    // 0x801ADDD0: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    Object_Kill(rdram, ctx);
        goto after_0;
    // 0x801ADDD0: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    after_0:
    // 0x801ADDD4: lh          $v0, 0xB8($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XB8);
L_801ADDD8:
    // 0x801ADDD8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801ADDDC: beql        $v0, $zero, L_801ADDF8
    if (ctx->r2 == 0) {
        // 0x801ADDE0: lhu         $t2, 0xBC($s0)
        ctx->r10 = MEM_HU(ctx->r16, 0XBC);
            goto L_801ADDF8;
    }
    goto skip_1;
    // 0x801ADDE0: lhu         $t2, 0xBC($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0XBC);
    skip_1:
    // 0x801ADDE4: beql        $v0, $at, L_801AE0FC
    if (ctx->r2 == ctx->r1) {
        // 0x801ADDE8: lw          $v0, 0x50($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X50);
            goto L_801AE0FC;
    }
    goto skip_2;
    // 0x801ADDE8: lw          $v0, 0x50($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X50);
    skip_2:
    // 0x801ADDEC: b           L_801AE2AC
    // 0x801ADDF0: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
        goto L_801AE2AC;
    // 0x801ADDF0: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
    // 0x801ADDF4: lhu         $t2, 0xBC($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0XBC);
L_801ADDF8:
    // 0x801ADDF8: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x801ADDFC: bnel        $t2, $zero, L_801ADFD0
    if (ctx->r10 != 0) {
        // 0x801ADE00: lw          $a0, 0x40($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X40);
            goto L_801ADFD0;
    }
    goto skip_3;
    // 0x801ADE00: lw          $a0, 0x40($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X40);
    skip_3:
    // 0x801ADE04: lwc1        $f16, 0xEC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x801ADE08: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801ADE0C: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x801ADE10: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801ADE14: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x801ADE18: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801ADE1C: swc1        $f4, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f4.u32l;
    // 0x801ADE20: lwc1        $f6, 0xEC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x801ADE24: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x801ADE28: nop

    // 0x801ADE2C: bc1fl       L_801ADFD0
    if (!c1cs) {
        // 0x801ADE30: lw          $a0, 0x40($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X40);
            goto L_801ADFD0;
    }
    goto skip_4;
    // 0x801ADE30: lw          $a0, 0x40($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X40);
    skip_4:
    // 0x801ADE34: lh          $v0, -0x1CBC($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X1CBC);
    // 0x801ADE38: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801ADE3C: beq         $v0, $zero, L_801ADE64
    if (ctx->r2 == 0) {
        // 0x801ADE40: nop
    
            goto L_801ADE64;
    }
    // 0x801ADE40: nop

    // 0x801ADE44: beq         $v0, $at, L_801ADE64
    if (ctx->r2 == ctx->r1) {
        // 0x801ADE48: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_801ADE64;
    }
    // 0x801ADE48: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801ADE4C: beq         $v0, $at, L_801ADE6C
    if (ctx->r2 == ctx->r1) {
        // 0x801ADE50: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_801ADE6C;
    }
    // 0x801ADE50: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801ADE54: beql        $v0, $at, L_801ADE78
    if (ctx->r2 == ctx->r1) {
        // 0x801ADE58: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_801ADE78;
    }
    goto skip_5;
    // 0x801ADE58: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    skip_5:
    // 0x801ADE5C: b           L_801ADE78
    // 0x801ADE60: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
        goto L_801ADE78;
    // 0x801ADE60: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_801ADE64:
    // 0x801ADE64: b           L_801ADE78
    // 0x801ADE68: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801ADE78;
    // 0x801ADE68: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801ADE6C:
    // 0x801ADE6C: b           L_801ADE78
    // 0x801ADE70: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_801ADE78;
    // 0x801ADE70: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x801ADE74: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_801ADE78:
    // 0x801ADE78: lw          $t3, 0x58($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X58);
    // 0x801ADE7C: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x801ADE80: lw          $t5, 0x54($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X54);
    // 0x801ADE84: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x801ADE88: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x801ADE8C: cvt.s.w     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    ctx->f2.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801ADE90: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x801ADE94: sll         $t9, $t5, 2
    ctx->r25 = S32(ctx->r13 << 2);
    // 0x801ADE98: addu        $t8, $t4, $t9
    ctx->r24 = ADD32(ctx->r12, ctx->r25);
    // 0x801ADE9C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801ADEA0: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x801ADEA4: lwc1        $f16, -0x5A90($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X5A90);
    // 0x801ADEA8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x801ADEAC: lw          $t6, -0x7D80($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7D80);
    // 0x801ADEB0: div.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f2.fl);
    // 0x801ADEB4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801ADEB8: lwc1        $f4, 0x74($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X74);
    // 0x801ADEBC: lwc1        $f8, -0x45B4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X45B4);
    // 0x801ADEC0: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x801ADEC4: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801ADEC8: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    // 0x801ADECC: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x801ADED0: lui         $a3, 0x41F0
    ctx->r7 = S32(0X41F0 << 16);
    // 0x801ADED4: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x801ADED8: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x801ADEDC: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x801ADEE0: jal         0x8009BC2C
    // 0x801ADEE4: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_1;
    // 0x801ADEE4: nop

    after_1:
    // 0x801ADEE8: lw          $t0, 0x58($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X58);
    // 0x801ADEEC: lw          $t2, 0x54($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X54);
    // 0x801ADEF0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801ADEF4: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x801ADEF8: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x801ADEFC: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x801ADF00: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x801ADF04: addu        $t5, $t1, $t3
    ctx->r13 = ADD32(ctx->r9, ctx->r11);
    // 0x801ADF08: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x801ADF0C: lwc1        $f2, 0x2C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801ADF10: lwc1        $f16, -0x59C8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X59C8);
    // 0x801ADF14: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x801ADF18: lw          $t7, -0x7D80($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7D80);
    // 0x801ADF1C: div.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f2.fl);
    // 0x801ADF20: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801ADF24: lwc1        $f10, 0x138($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X138);
    // 0x801ADF28: lwc1        $f6, -0x45B0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X45B0);
    // 0x801ADF2C: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x801ADF30: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801ADF34: addiu       $a0, $s0, 0xC
    ctx->r4 = ADD32(ctx->r16, 0XC);
    // 0x801ADF38: lui         $a3, 0x4220
    ctx->r7 = S32(0X4220 << 16);
    // 0x801ADF3C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x801ADF40: sub.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x801ADF44: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x801ADF48: jal         0x8009BC2C
    // 0x801ADF4C: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_2;
    // 0x801ADF4C: nop

    after_2:
    // 0x801ADF50: jal         0x80004EB0
    // 0x801ADF54: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_3;
    // 0x801ADF54: nop

    after_3:
    // 0x801ADF58: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801ADF5C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801ADF60: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x801ADF64: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801ADF68: sub.s       $f16, $f0, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x801ADF6C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801ADF70: lwc1        $f4, -0x45AC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X45AC);
    // 0x801ADF74: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x801ADF78: mul.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x801ADF7C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801ADF80: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x801ADF84: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x801ADF88: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x801ADF8C: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x801ADF90: jal         0x8009BC2C
    // 0x801ADF94: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_4;
    // 0x801ADF94: nop

    after_4:
    // 0x801ADF98: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801ADF9C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801ADFA0: lwc1        $f2, 0x11C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X11C);
    // 0x801ADFA4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801ADFA8: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x801ADFAC: nop

    // 0x801ADFB0: bc1fl       L_801ADFD0
    if (!c1cs) {
        // 0x801ADFB4: lw          $a0, 0x40($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X40);
            goto L_801ADFD0;
    }
    goto skip_6;
    // 0x801ADFB4: lw          $a0, 0x40($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X40);
    skip_6:
    // 0x801ADFB8: ldc1        $f16, -0x45A8($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, -0X45A8);
    // 0x801ADFBC: cvt.d.s     $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f8.d = CVT_D_S(ctx->f2.fl);
    // 0x801ADFC0: add.d       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f10.d = ctx->f8.d + ctx->f16.d;
    // 0x801ADFC4: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x801ADFC8: swc1        $f18, 0x11C($s0)
    MEM_W(0X11C, ctx->r16) = ctx->f18.u32l;
    // 0x801ADFCC: lw          $a0, 0x40($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X40);
L_801ADFD0:
    // 0x801ADFD0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x801ADFD4: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    // 0x801ADFD8: jal         0x8006351C
    // 0x801ADFDC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    Object_CheckCollision(rdram, ctx);
        goto after_5;
    // 0x801ADFDC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_5:
    // 0x801ADFE0: bne         $v0, $zero, L_801AE008
    if (ctx->r2 != 0) {
        // 0x801ADFE4: lui         $at, 0x8017
        ctx->r1 = S32(0X8017 << 16);
            goto L_801AE008;
    }
    // 0x801ADFE4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801ADFE8: lwc1        $f2, 0x7940($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X7940);
    // 0x801ADFEC: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x801ADFF0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801ADFF4: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801ADFF8: add.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x801ADFFC: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x801AE000: nop

    // 0x801AE004: bc1f        L_801AE0B0
    if (!c1cs) {
        // 0x801AE008: lui         $a3, 0x800C
        ctx->r7 = S32(0X800C << 16);
            goto L_801AE0B0;
    }
L_801AE008:
    // 0x801AE008: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x801AE00C: lui         $t4, 0x800C
    ctx->r12 = S32(0X800C << 16);
    // 0x801AE010: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x801AE014: addiu       $t4, $t4, 0x5D3C
    ctx->r12 = ADD32(ctx->r12, 0X5D3C);
    // 0x801AE018: lui         $a0, 0x1903
    ctx->r4 = S32(0X1903 << 16);
    // 0x801AE01C: ori         $a0, $a0, 0x2064
    ctx->r4 = ctx->r4 | 0X2064;
    // 0x801AE020: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x801AE024: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x801AE028: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x801AE02C: jal         0x80019218
    // 0x801AE030: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_6;
    // 0x801AE030: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_6:
    // 0x801AE034: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x801AE038: lw          $v0, 0x7AF8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7AF8);
    // 0x801AE03C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801AE040: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801AE044: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x801AE048: sb          $t9, 0x7E84($at)
    MEM_B(0X7E84, ctx->r1) = ctx->r25;
    // 0x801AE04C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801AE050: sll         $t6, $v0, 1
    ctx->r14 = S32(ctx->r2 << 1);
    // 0x801AE054: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801AE058: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x801AE05C: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x801AE060: sh          $t8, 0x7BD0($at)
    MEM_H(0X7BD0, ctx->r1) = ctx->r24;
    // 0x801AE064: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801AE068: swc1        $f0, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f0.u32l;
    // 0x801AE06C: swc1        $f0, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f0.u32l;
    // 0x801AE070: swc1        $f0, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f0.u32l;
    // 0x801AE074: lwc1        $f8, 0x7940($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7940);
    // 0x801AE078: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x801AE07C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801AE080: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801AE084: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801AE088: add.s       $f2, $f8, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x801AE08C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801AE090: c.lt.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl < ctx->f2.fl;
    // 0x801AE094: nop

    // 0x801AE098: bc1fl       L_801AE0A8
    if (!c1cs) {
        // 0x801AE09C: sh          $t7, 0xB8($s0)
        MEM_H(0XB8, ctx->r16) = ctx->r15;
            goto L_801AE0A8;
    }
    goto skip_7;
    // 0x801AE09C: sh          $t7, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r15;
    skip_7:
    // 0x801AE0A0: swc1        $f2, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f2.u32l;
    // 0x801AE0A4: sh          $t7, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r15;
L_801AE0A8:
    // 0x801AE0A8: lwc1        $f2, 0x7940($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X7940);
    // 0x801AE0AC: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
L_801AE0B0:
    // 0x801AE0B0: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
    // 0x801AE0B4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801AE0B8: nop

    // 0x801AE0BC: add.s       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f18.fl;
    // 0x801AE0C0: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x801AE0C4: nop

    // 0x801AE0C8: bc1fl       L_801AE2AC
    if (!c1cs) {
        // 0x801AE0CC: sb          $zero, 0xD0($s0)
        MEM_B(0XD0, ctx->r16) = 0;
            goto L_801AE2AC;
    }
    goto skip_8;
    // 0x801AE0CC: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
    skip_8:
    // 0x801AE0D0: lw          $v0, 0x50($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X50);
    // 0x801AE0D4: slti        $at, $v0, 0xB
    ctx->r1 = SIGNED(ctx->r2) < 0XB ? 1 : 0;
    // 0x801AE0D8: bne         $at, $zero, L_801AE0E8
    if (ctx->r1 != 0) {
        // 0x801AE0DC: addiu       $t0, $v0, -0xA
        ctx->r8 = ADD32(ctx->r2, -0XA);
            goto L_801AE0E8;
    }
    // 0x801AE0DC: addiu       $t0, $v0, -0xA
    ctx->r8 = ADD32(ctx->r2, -0XA);
    // 0x801AE0E0: b           L_801AE2A8
    // 0x801AE0E4: sw          $t0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r8;
        goto L_801AE2A8;
    // 0x801AE0E4: sw          $t0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r8;
L_801AE0E8:
    // 0x801AE0E8: blez        $v0, L_801AE2A8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x801AE0EC: addiu       $t2, $v0, -0x1
        ctx->r10 = ADD32(ctx->r2, -0X1);
            goto L_801AE2A8;
    }
    // 0x801AE0EC: addiu       $t2, $v0, -0x1
    ctx->r10 = ADD32(ctx->r2, -0X1);
    // 0x801AE0F0: b           L_801AE2A8
    // 0x801AE0F4: sw          $t2, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r10;
        goto L_801AE2A8;
    // 0x801AE0F4: sw          $t2, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r10;
    // 0x801AE0F8: lw          $v0, 0x50($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X50);
L_801AE0FC:
    // 0x801AE0FC: addiu       $t4, $zero, 0xF
    ctx->r12 = ADD32(0, 0XF);
    // 0x801AE100: addiu       $t7, $s0, 0x100
    ctx->r15 = ADD32(ctx->r16, 0X100);
    // 0x801AE104: slti        $at, $v0, 0xB
    ctx->r1 = SIGNED(ctx->r2) < 0XB ? 1 : 0;
    // 0x801AE108: bne         $at, $zero, L_801AE118
    if (ctx->r1 != 0) {
        // 0x801AE10C: addiu       $t1, $v0, -0xA
        ctx->r9 = ADD32(ctx->r2, -0XA);
            goto L_801AE118;
    }
    // 0x801AE10C: addiu       $t1, $v0, -0xA
    ctx->r9 = ADD32(ctx->r2, -0XA);
    // 0x801AE110: b           L_801AE124
    // 0x801AE114: sw          $t1, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r9;
        goto L_801AE124;
    // 0x801AE114: sw          $t1, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r9;
L_801AE118:
    // 0x801AE118: blez        $v0, L_801AE124
    if (SIGNED(ctx->r2) <= 0) {
        // 0x801AE11C: addiu       $t3, $v0, -0x1
        ctx->r11 = ADD32(ctx->r2, -0X1);
            goto L_801AE124;
    }
    // 0x801AE11C: addiu       $t3, $v0, -0x1
    ctx->r11 = ADD32(ctx->r2, -0X1);
    // 0x801AE120: sw          $t3, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r11;
L_801AE124:
    // 0x801AE124: lb          $t5, 0xD0($s0)
    ctx->r13 = MEM_B(ctx->r16, 0XD0);
    // 0x801AE128: beql        $t5, $zero, L_801AE2AC
    if (ctx->r13 == 0) {
        // 0x801AE12C: sb          $zero, 0xD0($s0)
        MEM_B(0XD0, ctx->r16) = 0;
            goto L_801AE2AC;
    }
    goto skip_9;
    // 0x801AE12C: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
    skip_9:
    // 0x801AE130: lh          $t9, 0xCE($s0)
    ctx->r25 = MEM_H(ctx->r16, 0XCE);
    // 0x801AE134: lhu         $t8, 0xD6($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0XD6);
    // 0x801AE138: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
    // 0x801AE13C: sw          $t4, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->r12;
    // 0x801AE140: subu        $t6, $t9, $t8
    ctx->r14 = SUB32(ctx->r25, ctx->r24);
    // 0x801AE144: sh          $t6, 0xCE($s0)
    MEM_H(0XCE, ctx->r16) = ctx->r14;
    // 0x801AE148: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x801AE14C: lh          $t0, 0xCE($s0)
    ctx->r8 = MEM_H(ctx->r16, 0XCE);
    // 0x801AE150: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x801AE154: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x801AE158: bgtz        $t0, L_801AE288
    if (SIGNED(ctx->r8) > 0) {
        // 0x801AE15C: lui         $a0, 0x2903
        ctx->r4 = S32(0X2903 << 16);
            goto L_801AE288;
    }
    // 0x801AE15C: lui         $a0, 0x2903
    ctx->r4 = S32(0X2903 << 16);
    // 0x801AE160: lui         $a1, 0x2903
    ctx->r5 = S32(0X2903 << 16);
    // 0x801AE164: ori         $a1, $a1, 0xA008
    ctx->r5 = ctx->r5 | 0XA008;
    // 0x801AE168: jal         0x8007A6F0
    // 0x801AE16C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    Effect_TimedSfx_Spawn(rdram, ctx);
        goto after_7;
    // 0x801AE16C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    after_7:
    // 0x801AE170: jal         0x80004EB0
    // 0x801AE174: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_8;
    // 0x801AE174: nop

    after_8:
    // 0x801AE178: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801AE17C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801AE180: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x801AE184: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801AE188: sub.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x801AE18C: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x801AE190: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801AE194: lwc1        $f18, 0x4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801AE198: mul.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x801AE19C: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801AE1A0: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x801AE1A4: lui         $a3, 0x4100
    ctx->r7 = S32(0X4100 << 16);
    // 0x801AE1A8: sub.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801AE1AC: jal         0x8007D2C8
    // 0x801AE1B0: add.s       $f12, $f10, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f18.fl;
    Effect_FireSmoke1_Spawn3(rdram, ctx);
        goto after_9;
    // 0x801AE1B0: add.s       $f12, $f10, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f18.fl;
    after_9:
    // 0x801AE1B4: jal         0x80004EB0
    // 0x801AE1B8: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_10;
    // 0x801AE1B8: nop

    after_10:
    // 0x801AE1BC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801AE1C0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801AE1C4: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x801AE1C8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801AE1CC: sub.s       $f16, $f0, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x801AE1D0: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801AE1D4: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801AE1D8: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x801AE1DC: mul.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x801AE1E0: lui         $a3, 0x4100
    ctx->r7 = S32(0X4100 << 16);
    // 0x801AE1E4: jal         0x8007D2C8
    // 0x801AE1E8: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    Effect_FireSmoke1_Spawn3(rdram, ctx);
        goto after_11;
    // 0x801AE1E8: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    after_11:
    // 0x801AE1EC: jal         0x80004EB0
    // 0x801AE1F0: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_12;
    // 0x801AE1F0: nop

    after_12:
    // 0x801AE1F4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801AE1F8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801AE1FC: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x801AE200: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801AE204: sub.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x801AE208: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x801AE20C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801AE210: lwc1        $f18, 0x4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801AE214: mul.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x801AE218: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801AE21C: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x801AE220: lui         $a3, 0x40E0
    ctx->r7 = S32(0X40E0 << 16);
    // 0x801AE224: add.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801AE228: jal         0x8007D2C8
    // 0x801AE22C: add.s       $f12, $f10, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f18.fl;
    Effect_FireSmoke1_Spawn3(rdram, ctx);
        goto after_13;
    // 0x801AE22C: add.s       $f12, $f10, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f18.fl;
    after_13:
    // 0x801AE230: jal         0x80004EB0
    // 0x801AE234: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_14;
    // 0x801AE234: nop

    after_14:
    // 0x801AE238: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801AE23C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801AE240: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x801AE244: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801AE248: sub.s       $f16, $f0, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x801AE24C: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x801AE250: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801AE254: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801AE258: mul.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x801AE25C: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801AE260: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x801AE264: lui         $a3, 0x40E0
    ctx->r7 = S32(0X40E0 << 16);
    // 0x801AE268: add.s       $f14, $f6, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801AE26C: jal         0x8007D2C8
    // 0x801AE270: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    Effect_FireSmoke1_Spawn3(rdram, ctx);
        goto after_15;
    // 0x801AE270: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    after_15:
    // 0x801AE274: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801AE278: jal         0x80060FBC
    // 0x801AE27C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    Object_Kill(rdram, ctx);
        goto after_16;
    // 0x801AE27C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_16:
    // 0x801AE280: b           L_801AE2AC
    // 0x801AE284: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
        goto L_801AE2AC;
    // 0x801AE284: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
L_801AE288:
    // 0x801AE288: lui         $t2, 0x800C
    ctx->r10 = S32(0X800C << 16);
    // 0x801AE28C: addiu       $t2, $t2, 0x5D3C
    ctx->r10 = ADD32(ctx->r10, 0X5D3C);
    // 0x801AE290: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x801AE294: ori         $a0, $a0, 0x300E
    ctx->r4 = ctx->r4 | 0X300E;
    // 0x801AE298: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x801AE29C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x801AE2A0: jal         0x80019218
    // 0x801AE2A4: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    Audio_PlaySfx(rdram, ctx);
        goto after_17;
    // 0x801AE2A4: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_17:
L_801AE2A8:
    // 0x801AE2A8: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
L_801AE2AC:
    // 0x801AE2AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801AE2B0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801AE2B4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x801AE2B8: jr          $ra
    // 0x801AE2BC: nop

    return;
    // 0x801AE2BC: nop

;}
RECOMP_FUNC void Macbeth_801A5FC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A5FC4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801A5FC8: jr          $ra
    // 0x801A5FCC: nop

    return;
    // 0x801A5FCC: nop

;}
RECOMP_FUNC void Macbeth_801AF44C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801AF44C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801AF450: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801AF454: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x801AF458: jal         0x800613C4
    // 0x801AF45C: addiu       $a0, $a0, 0x5780
    ctx->r4 = ADD32(ctx->r4, 0X5780);
    Actor_Initialize(rdram, ctx);
        goto after_0;
    // 0x801AF45C: addiu       $a0, $a0, 0x5780
    ctx->r4 = ADD32(ctx->r4, 0X5780);
    after_0:
    // 0x801AF460: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801AF464: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x801AF468: sb          $t6, 0x5780($at)
    MEM_B(0X5780, ctx->r1) = ctx->r14;
    // 0x801AF46C: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x801AF470: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x801AF474: addiu       $t7, $zero, 0xC3
    ctx->r15 = ADD32(0, 0XC3);
    // 0x801AF478: addiu       $v0, $v0, -0x7D80
    ctx->r2 = ADD32(ctx->r2, -0X7D80);
    // 0x801AF47C: sh          $t7, 0x5782($at)
    MEM_H(0X5782, ctx->r1) = ctx->r15;
    // 0x801AF480: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x801AF484: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801AF488: lwc1        $f4, -0x580C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X580C);
    // 0x801AF48C: lwc1        $f6, 0x74($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X74);
    // 0x801AF490: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x801AF494: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801AF498: swc1        $f8, 0x5784($at)
    MEM_W(0X5784, ctx->r1) = ctx->f8.u32l;
    // 0x801AF49C: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x801AF4A0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801AF4A4: lwc1        $f10, -0x57F8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X57F8);
    // 0x801AF4A8: lwc1        $f16, 0x78($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X78);
    // 0x801AF4AC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x801AF4B0: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801AF4B4: swc1        $f18, 0x5788($at)
    MEM_W(0X5788, ctx->r1) = ctx->f18.u32l;
    // 0x801AF4B8: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x801AF4BC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801AF4C0: lwc1        $f4, -0x57E4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X57E4);
    // 0x801AF4C4: lwc1        $f6, 0x7C($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X7C);
    // 0x801AF4C8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x801AF4CC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801AF4D0: swc1        $f8, 0x578C($at)
    MEM_W(0X578C, ctx->r1) = ctx->f8.u32l;
    // 0x801AF4D4: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x801AF4D8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x801AF4DC: lwc1        $f10, 0xC0($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0XC0);
    // 0x801AF4E0: swc1        $f10, 0x5868($at)
    MEM_W(0X5868, ctx->r1) = ctx->f10.u32l;
    // 0x801AF4E4: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x801AF4E8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x801AF4EC: lwc1        $f16, 0xC4($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0XC4);
    // 0x801AF4F0: swc1        $f16, 0x586C($at)
    MEM_W(0X586C, ctx->r1) = ctx->f16.u32l;
    // 0x801AF4F4: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x801AF4F8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x801AF4FC: lwc1        $f18, 0xC8($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0XC8);
    // 0x801AF500: jal         0x80004EB0
    // 0x801AF504: swc1        $f18, 0x5870($at)
    MEM_W(0X5870, ctx->r1) = ctx->f18.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x801AF504: swc1        $f18, 0x5870($at)
    MEM_W(0X5870, ctx->r1) = ctx->f18.u32l;
    after_1:
    // 0x801AF508: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x801AF50C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801AF510: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x801AF514: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x801AF518: jal         0x80004EB0
    // 0x801AF51C: swc1        $f6, 0x58B0($at)
    MEM_W(0X58B0, ctx->r1) = ctx->f6.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_2;
    // 0x801AF51C: swc1        $f6, 0x58B0($at)
    MEM_W(0X58B0, ctx->r1) = ctx->f6.u32l;
    after_2:
    // 0x801AF520: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x801AF524: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801AF528: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x801AF52C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x801AF530: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x801AF534: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801AF538: addiu       $v0, $v0, -0x57E0
    ctx->r2 = ADD32(ctx->r2, -0X57E0);
    // 0x801AF53C: addiu       $t4, $zero, 0x18
    ctx->r12 = ADD32(0, 0X18);
    // 0x801AF540: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801AF544: addiu       $t6, $zero, 0xF
    ctx->r14 = ADD32(0, 0XF);
    // 0x801AF548: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x801AF54C: swc1        $f10, 0x58B4($at)
    MEM_W(0X58B4, ctx->r1) = ctx->f10.u32l;
    // 0x801AF550: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801AF554: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801AF558: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x801AF55C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x801AF560: swc1        $f16, 0x58B8($at)
    MEM_W(0X58B8, ctx->r1) = ctx->f16.u32l;
    // 0x801AF564: lwc1        $f2, 0x10($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X10);
    // 0x801AF568: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x801AF56C: swc1        $f12, 0x5874($at)
    MEM_W(0X5874, ctx->r1) = ctx->f12.u32l;
    // 0x801AF570: lui         $at, 0x43A5
    ctx->r1 = S32(0X43A5 << 16);
    // 0x801AF574: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801AF578: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x801AF57C: addiu       $a0, $a0, 0x579C
    ctx->r4 = ADD32(ctx->r4, 0X579C);
    // 0x801AF580: swc1        $f18, 0x587C($at)
    MEM_W(0X587C, ctx->r1) = ctx->f18.u32l;
    // 0x801AF584: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801AF588: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801AF58C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x801AF590: swc1        $f4, 0x5790($at)
    MEM_W(0X5790, ctx->r1) = ctx->f4.u32l;
    // 0x801AF594: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x801AF598: swc1        $f2, 0x5794($at)
    MEM_W(0X5794, ctx->r1) = ctx->f2.u32l;
    // 0x801AF59C: lui         $at, 0xC3A5
    ctx->r1 = S32(0XC3A5 << 16);
    // 0x801AF5A0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801AF5A4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x801AF5A8: swc1        $f6, 0x5798($at)
    MEM_W(0X5798, ctx->r1) = ctx->f6.u32l;
    // 0x801AF5AC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x801AF5B0: swc1        $f12, 0x5894($at)
    MEM_W(0X5894, ctx->r1) = ctx->f12.u32l;
    // 0x801AF5B4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x801AF5B8: sh          $t4, 0x5836($at)
    MEM_H(0X5836, ctx->r1) = ctx->r12;
    // 0x801AF5BC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x801AF5C0: sw          $t5, 0x57FC($at)
    MEM_W(0X57FC, ctx->r1) = ctx->r13;
    // 0x801AF5C4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x801AF5C8: sh          $t6, 0x5838($at)
    MEM_H(0X5838, ctx->r1) = ctx->r14;
    // 0x801AF5CC: lwc1        $f8, 0x10($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X10);
    // 0x801AF5D0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x801AF5D4: swc1        $f8, 0x58A0($at)
    MEM_W(0X58A0, ctx->r1) = ctx->f8.u32l;
    // 0x801AF5D8: lhu         $a1, 0x5782($a1)
    ctx->r5 = MEM_HU(ctx->r5, 0X5782);
    // 0x801AF5DC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x801AF5E0: jal         0x800612B8
    // 0x801AF5E4: swc1        $f2, 0x5878($at)
    MEM_W(0X5878, ctx->r1) = ctx->f2.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_3;
    // 0x801AF5E4: swc1        $f2, 0x5878($at)
    MEM_W(0X5878, ctx->r1) = ctx->f2.u32l;
    after_3:
    // 0x801AF5E8: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x801AF5EC: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x801AF5F0: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x801AF5F4: addiu       $t7, $t7, 0x5D3C
    ctx->r15 = ADD32(ctx->r15, 0X5D3C);
    // 0x801AF5F8: lui         $a0, 0x3100
    ctx->r4 = S32(0X3100 << 16);
    // 0x801AF5FC: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x801AF600: addiu       $a1, $a1, 0x5880
    ctx->r5 = ADD32(ctx->r5, 0X5880);
    // 0x801AF604: ori         $a0, $a0, 0xC
    ctx->r4 = ctx->r4 | 0XC;
    // 0x801AF608: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801AF60C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x801AF610: jal         0x80019218
    // 0x801AF614: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_4;
    // 0x801AF614: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_4:
    // 0x801AF618: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801AF61C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801AF620: jr          $ra
    // 0x801AF624: nop

    return;
    // 0x801AF624: nop

;}
RECOMP_FUNC void Macbeth_Texture_Scroll2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80199D88: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80199D8C: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x80199D90: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x80199D94: sw          $s7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r23;
    // 0x80199D98: sw          $s6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r22;
    // 0x80199D9C: sw          $s5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r21;
    // 0x80199DA0: sw          $s4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r20;
    // 0x80199DA4: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // 0x80199DA8: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x80199DAC: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x80199DB0: sll         $t6, $a0, 4
    ctx->r14 = S32(ctx->r4 << 4);
    // 0x80199DB4: srl         $t7, $t6, 28
    ctx->r15 = S32(U32(ctx->r14) >> 28);
    // 0x80199DB8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80199DBC: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80199DC0: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80199DC4: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x80199DC8: lw          $t9, 0x1FD0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X1FD0);
    // 0x80199DCC: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80199DD0: and         $t6, $a0, $at
    ctx->r14 = ctx->r4 & ctx->r1;
    // 0x80199DD4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80199DD8: addu        $t1, $t9, $t6
    ctx->r9 = ADD32(ctx->r25, ctx->r14);
    // 0x80199DDC: addu        $t1, $t1, $at
    ctx->r9 = ADD32(ctx->r9, ctx->r1);
    // 0x80199DE0: blez        $a1, L_80199F64
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80199DE4: or          $t2, $zero, $zero
        ctx->r10 = 0 | 0;
            goto L_80199F64;
    }
    // 0x80199DE4: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x80199DE8: addiu       $t7, $s0, -0x1
    ctx->r15 = ADD32(ctx->r16, -0X1);
    // 0x80199DEC: multu       $t7, $a1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80199DF0: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80199DF4: or          $t4, $t1, $zero
    ctx->r12 = ctx->r9 | 0;
    // 0x80199DF8: mflo        $t8
    ctx->r24 = lo;
    // 0x80199DFC: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x80199E00: addu        $t3, $t1, $t9
    ctx->r11 = ADD32(ctx->r9, ctx->r25);
L_80199E04:
    // 0x80199E04: lhu         $t5, 0x0($t3)
    ctx->r13 = MEM_HU(ctx->r11, 0X0);
    // 0x80199E08: blez        $s0, L_80199F4C
    if (SIGNED(ctx->r16) <= 0) {
        // 0x80199E0C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80199F4C;
    }
    // 0x80199E0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80199E10: andi        $s3, $s0, 0x3
    ctx->r19 = ctx->r16 & 0X3;
    // 0x80199E14: negu        $s3, $s3
    ctx->r19 = SUB32(0, ctx->r19);
    // 0x80199E18: beq         $s3, $zero, L_80199E80
    if (ctx->r19 == 0) {
        // 0x80199E1C: nop
    
            goto L_80199E80;
    }
    // 0x80199E1C: nop

    // 0x80199E20: multu       $a0, $a1
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80199E24: addiu       $s1, $a0, -0x1
    ctx->r17 = ADD32(ctx->r4, -0X1);
    // 0x80199E28: addu        $s2, $s3, $s0
    ctx->r18 = ADD32(ctx->r19, ctx->r16);
    // 0x80199E2C: mflo        $t6
    ctx->r14 = lo;
    // 0x80199E30: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x80199E34: addu        $t8, $t1, $t7
    ctx->r24 = ADD32(ctx->r9, ctx->r15);
    // 0x80199E38: multu       $s1, $a1
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80199E3C: addu        $v1, $t8, $t0
    ctx->r3 = ADD32(ctx->r24, ctx->r8);
    // 0x80199E40: mflo        $t9
    ctx->r25 = lo;
    // 0x80199E44: sll         $t6, $t9, 1
    ctx->r14 = S32(ctx->r25 << 1);
    // 0x80199E48: addu        $t7, $t1, $t6
    ctx->r15 = ADD32(ctx->r9, ctx->r14);
    // 0x80199E4C: addu        $v0, $t7, $t0
    ctx->r2 = ADD32(ctx->r15, ctx->r8);
L_80199E50:
    // 0x80199E50: lhu         $t8, 0x0($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X0);
    // 0x80199E54: negu        $at, $a1
    ctx->r1 = SUB32(0, ctx->r5);
    // 0x80199E58: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80199E5C: sll         $t9, $at, 1
    ctx->r25 = S32(ctx->r1 << 1);
    // 0x80199E60: sll         $t6, $at, 1
    ctx->r14 = S32(ctx->r1 << 1);
    // 0x80199E64: sh          $t8, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r24;
    // 0x80199E68: addu        $v1, $v1, $t9
    ctx->r3 = ADD32(ctx->r3, ctx->r25);
    // 0x80199E6C: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80199E70: bne         $s2, $s1, L_80199E50
    if (ctx->r18 != ctx->r17) {
        // 0x80199E74: addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
            goto L_80199E50;
    }
    // 0x80199E74: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x80199E78: beql        $a0, $zero, L_80199F50
    if (ctx->r4 == 0) {
        // 0x80199E7C: addiu       $t2, $t2, 0x1
        ctx->r10 = ADD32(ctx->r10, 0X1);
            goto L_80199F50;
    }
    goto skip_0;
    // 0x80199E7C: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    skip_0:
L_80199E80:
    // 0x80199E80: multu       $a0, $a1
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80199E84: addiu       $t6, $a0, -0x1
    ctx->r14 = ADD32(ctx->r4, -0X1);
    // 0x80199E88: addiu       $s3, $a0, -0x4
    ctx->r19 = ADD32(ctx->r4, -0X4);
    // 0x80199E8C: negu        $at, $a1
    ctx->r1 = SUB32(0, ctx->r5);
    // 0x80199E90: sll         $a2, $at, 3
    ctx->r6 = S32(ctx->r1 << 3);
    // 0x80199E94: sll         $a3, $at, 3
    ctx->r7 = S32(ctx->r1 << 3);
    // 0x80199E98: sll         $s5, $at, 3
    ctx->r21 = S32(ctx->r1 << 3);
    // 0x80199E9C: sll         $s6, $at, 3
    ctx->r22 = S32(ctx->r1 << 3);
    // 0x80199EA0: sll         $s7, $at, 3
    ctx->r23 = S32(ctx->r1 << 3);
    // 0x80199EA4: mflo        $t7
    ctx->r15 = lo;
    // 0x80199EA8: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x80199EAC: addu        $t9, $t1, $t8
    ctx->r25 = ADD32(ctx->r9, ctx->r24);
    // 0x80199EB0: multu       $t6, $a1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80199EB4: addiu       $t6, $a0, -0x2
    ctx->r14 = ADD32(ctx->r4, -0X2);
    // 0x80199EB8: addu        $v1, $t9, $t0
    ctx->r3 = ADD32(ctx->r25, ctx->r8);
    // 0x80199EBC: mflo        $t7
    ctx->r15 = lo;
    // 0x80199EC0: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x80199EC4: addu        $t9, $t1, $t8
    ctx->r25 = ADD32(ctx->r9, ctx->r24);
    // 0x80199EC8: multu       $t6, $a1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80199ECC: addiu       $t6, $a0, -0x3
    ctx->r14 = ADD32(ctx->r4, -0X3);
    // 0x80199ED0: addu        $v0, $t9, $t0
    ctx->r2 = ADD32(ctx->r25, ctx->r8);
    // 0x80199ED4: mflo        $t7
    ctx->r15 = lo;
    // 0x80199ED8: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x80199EDC: addu        $t9, $t1, $t8
    ctx->r25 = ADD32(ctx->r9, ctx->r24);
    // 0x80199EE0: multu       $t6, $a1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80199EE4: addu        $s1, $t9, $t0
    ctx->r17 = ADD32(ctx->r25, ctx->r8);
    // 0x80199EE8: mflo        $t7
    ctx->r15 = lo;
    // 0x80199EEC: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x80199EF0: addu        $t9, $t1, $t8
    ctx->r25 = ADD32(ctx->r9, ctx->r24);
    // 0x80199EF4: multu       $s3, $a1
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80199EF8: addu        $s2, $t9, $t0
    ctx->r18 = ADD32(ctx->r25, ctx->r8);
    // 0x80199EFC: mflo        $t6
    ctx->r14 = lo;
    // 0x80199F00: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x80199F04: addu        $t8, $t1, $t7
    ctx->r24 = ADD32(ctx->r9, ctx->r15);
    // 0x80199F08: addu        $s4, $t8, $t0
    ctx->r20 = ADD32(ctx->r24, ctx->r8);
L_80199F0C:
    // 0x80199F0C: lhu         $t9, 0x0($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X0);
    // 0x80199F10: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80199F14: sh          $t9, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r25;
    // 0x80199F18: lhu         $t6, 0x0($s1)
    ctx->r14 = MEM_HU(ctx->r17, 0X0);
    // 0x80199F1C: addu        $v1, $v1, $a2
    ctx->r3 = ADD32(ctx->r3, ctx->r6);
    // 0x80199F20: sh          $t6, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r14;
    // 0x80199F24: lhu         $t7, 0x0($s2)
    ctx->r15 = MEM_HU(ctx->r18, 0X0);
    // 0x80199F28: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x80199F2C: sh          $t7, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r15;
    // 0x80199F30: lhu         $t8, 0x0($s4)
    ctx->r24 = MEM_HU(ctx->r20, 0X0);
    // 0x80199F34: addu        $s4, $s4, $s7
    ctx->r20 = ADD32(ctx->r20, ctx->r23);
    // 0x80199F38: addu        $s1, $s1, $s5
    ctx->r17 = ADD32(ctx->r17, ctx->r21);
    // 0x80199F3C: sh          $t8, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r24;
    // 0x80199F40: addu        $s2, $s2, $s6
    ctx->r18 = ADD32(ctx->r18, ctx->r22);
    // 0x80199F44: bne         $s3, $zero, L_80199F0C
    if (ctx->r19 != 0) {
        // 0x80199F48: addiu       $s3, $s3, -0x4
        ctx->r19 = ADD32(ctx->r19, -0X4);
            goto L_80199F0C;
    }
    // 0x80199F48: addiu       $s3, $s3, -0x4
    ctx->r19 = ADD32(ctx->r19, -0X4);
L_80199F4C:
    // 0x80199F4C: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
L_80199F50:
    // 0x80199F50: addiu       $t0, $t0, 0x2
    ctx->r8 = ADD32(ctx->r8, 0X2);
    // 0x80199F54: addiu       $t3, $t3, 0x2
    ctx->r11 = ADD32(ctx->r11, 0X2);
    // 0x80199F58: addiu       $t4, $t4, 0x2
    ctx->r12 = ADD32(ctx->r12, 0X2);
    // 0x80199F5C: bne         $t2, $a1, L_80199E04
    if (ctx->r10 != ctx->r5) {
        // 0x80199F60: sh          $t5, -0x2($t4)
        MEM_H(-0X2, ctx->r12) = ctx->r13;
            goto L_80199E04;
    }
    // 0x80199F60: sh          $t5, -0x2($t4)
    MEM_H(-0X2, ctx->r12) = ctx->r13;
L_80199F64:
    // 0x80199F64: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x80199F68: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x80199F6C: lw          $s2, 0x10($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X10);
    // 0x80199F70: lw          $s3, 0x14($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X14);
    // 0x80199F74: lw          $s4, 0x18($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X18);
    // 0x80199F78: lw          $s5, 0x1C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X1C);
    // 0x80199F7C: lw          $s6, 0x20($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X20);
    // 0x80199F80: lw          $s7, 0x24($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X24);
    // 0x80199F84: jr          $ra
    // 0x80199F88: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80199F88: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void Macbeth_MaBombDrop_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801AD6F0: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x801AD6F4: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x801AD6F8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801AD6FC: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x801AD700: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x801AD704: addiu       $t7, $t7, -0x5894
    ctx->r15 = ADD32(ctx->r15, -0X5894);
    // 0x801AD708: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x801AD70C: addiu       $t6, $sp, 0x4C
    ctx->r14 = ADD32(ctx->r29, 0X4C);
    // 0x801AD710: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x801AD714: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x801AD718: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x801AD71C: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x801AD720: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x801AD724: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x801AD728: lw          $t1, -0x7D80($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X7D80);
    // 0x801AD72C: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x801AD730: lui         $at, 0xC3FA
    ctx->r1 = S32(0XC3FA << 16);
    // 0x801AD734: lwc1        $f4, 0x138($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X138);
    // 0x801AD738: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801AD73C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801AD740: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801AD744: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x801AD748: nop

    // 0x801AD74C: bc1fl       L_801AD760
    if (!c1cs) {
        // 0x801AD750: lh          $v0, 0xB8($s0)
        ctx->r2 = MEM_H(ctx->r16, 0XB8);
            goto L_801AD760;
    }
    goto skip_0;
    // 0x801AD750: lh          $v0, 0xB8($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XB8);
    skip_0:
    // 0x801AD754: jal         0x80060FBC
    // 0x801AD758: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    Object_Kill(rdram, ctx);
        goto after_0;
    // 0x801AD758: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    after_0:
    // 0x801AD75C: lh          $v0, 0xB8($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XB8);
L_801AD760:
    // 0x801AD760: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801AD764: beql        $v0, $zero, L_801AD780
    if (ctx->r2 == 0) {
        // 0x801AD768: lhu         $t2, 0xBC($s0)
        ctx->r10 = MEM_HU(ctx->r16, 0XBC);
            goto L_801AD780;
    }
    goto skip_1;
    // 0x801AD768: lhu         $t2, 0xBC($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0XBC);
    skip_1:
    // 0x801AD76C: beql        $v0, $at, L_801AD978
    if (ctx->r2 == ctx->r1) {
        // 0x801AD770: lui         $at, 0x41A0
        ctx->r1 = S32(0X41A0 << 16);
            goto L_801AD978;
    }
    goto skip_2;
    // 0x801AD770: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    skip_2:
    // 0x801AD774: b           L_801ADAB8
    // 0x801AD778: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_801ADAB8;
    // 0x801AD778: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x801AD77C: lhu         $t2, 0xBC($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0XBC);
L_801AD780:
    // 0x801AD780: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801AD784: bnel        $t2, $zero, L_801ADAB8
    if (ctx->r10 != 0) {
        // 0x801AD788: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_801ADAB8;
    }
    goto skip_3;
    // 0x801AD788: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_3:
    // 0x801AD78C: lwc1        $f16, 0xEC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x801AD790: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801AD794: lw          $a0, 0x40($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X40);
    // 0x801AD798: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x801AD79C: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x801AD7A0: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    // 0x801AD7A4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801AD7A8: jal         0x8006351C
    // 0x801AD7AC: swc1        $f4, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f4.u32l;
    Object_CheckCollision(rdram, ctx);
        goto after_1;
    // 0x801AD7AC: swc1        $f4, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f4.u32l;
    after_1:
    // 0x801AD7B0: bne         $v0, $zero, L_801AD7E8
    if (ctx->r2 != 0) {
        // 0x801AD7B4: lui         $at, 0x8017
        ctx->r1 = S32(0X8017 << 16);
            goto L_801AD7E8;
    }
    // 0x801AD7B4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801AD7B8: lwc1        $f8, 0x7940($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7940);
    // 0x801AD7BC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801AD7C0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801AD7C4: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801AD7C8: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801AD7CC: c.lt.s      $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f6.fl < ctx->f16.fl;
    // 0x801AD7D0: nop

    // 0x801AD7D4: bc1tl       L_801AD7EC
    if (c1cs) {
        // 0x801AD7D8: mtc1        $zero, $f2
        ctx->f2.u32l = 0;
            goto L_801AD7EC;
    }
    goto skip_4;
    // 0x801AD7D8: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    skip_4:
    // 0x801AD7DC: lw          $t3, 0x50($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X50);
    // 0x801AD7E0: beql        $t3, $zero, L_801ADAB8
    if (ctx->r11 == 0) {
        // 0x801AD7E4: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_801ADAB8;
    }
    goto skip_5;
    // 0x801AD7E4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_5:
L_801AD7E8:
    // 0x801AD7E8: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
L_801AD7EC:
    // 0x801AD7EC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801AD7F0: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801AD7F4: swc1        $f2, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f2.u32l;
    // 0x801AD7F8: swc1        $f2, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f2.u32l;
    // 0x801AD7FC: swc1        $f2, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f2.u32l;
    // 0x801AD800: lwc1        $f0, 0x7940($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X7940);
    // 0x801AD804: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801AD808: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801AD80C: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x801AD810: lui         $a0, 0x2903
    ctx->r4 = S32(0X2903 << 16);
    // 0x801AD814: add.s       $f8, $f0, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x801AD818: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x801AD81C: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x801AD820: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x801AD824: c.lt.s      $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f18.fl < ctx->f8.fl;
    // 0x801AD828: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801AD82C: addiu       $t5, $zero, 0xC8
    ctx->r13 = ADD32(0, 0XC8);
    // 0x801AD830: addiu       $t9, $zero, 0xC0
    ctx->r25 = ADD32(0, 0XC0);
    // 0x801AD834: bc1f        L_801AD840
    if (!c1cs) {
        // 0x801AD838: ori         $a0, $a0, 0xB009
        ctx->r4 = ctx->r4 | 0XB009;
            goto L_801AD840;
    }
    // 0x801AD838: ori         $a0, $a0, 0xB009
    ctx->r4 = ctx->r4 | 0XB009;
    // 0x801AD83C: swc1        $f0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
L_801AD840:
    // 0x801AD840: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801AD844: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x801AD848: sh          $t4, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r12;
    // 0x801AD84C: sh          $t5, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r13;
    // 0x801AD850: sh          $t9, 0x46($s0)
    MEM_H(0X46, ctx->r16) = ctx->r25;
    // 0x801AD854: addiu       $t8, $t8, 0x5D3C
    ctx->r24 = ADD32(ctx->r24, 0X5D3C);
    // 0x801AD858: swc1        $f0, 0x110($s0)
    MEM_W(0X110, ctx->r16) = ctx->f0.u32l;
    // 0x801AD85C: swc1        $f0, 0x114($s0)
    MEM_W(0X114, ctx->r16) = ctx->f0.u32l;
    // 0x801AD860: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x801AD864: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x801AD868: jal         0x80019218
    // 0x801AD86C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_2;
    // 0x801AD86C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_2:
    // 0x801AD870: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801AD874: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801AD878: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801AD87C: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801AD880: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x801AD884: lui         $a3, 0x40E0
    ctx->r7 = S32(0X40E0 << 16);
    // 0x801AD888: jal         0x8007D0E0
    // 0x801AD88C: add.s       $f14, $f10, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f6.fl;
    Effect_FireSmoke1_Spawn4(rdram, ctx);
        goto after_3;
    // 0x801AD88C: add.s       $f14, $f10, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f6.fl;
    after_3:
    // 0x801AD890: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801AD894: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x801AD898: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801AD89C: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801AD8A0: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x801AD8A4: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801AD8A8: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x801AD8AC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801AD8B0: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x801AD8B4: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x801AD8B8: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x801AD8BC: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    // 0x801AD8C0: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    // 0x801AD8C4: add.s       $f14, $f16, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x801AD8C8: jal         0x8007BFFC
    // 0x801AD8CC: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    Effect_Effect386_Spawn1(rdram, ctx);
        goto after_4;
    // 0x801AD8CC: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    after_4:
    // 0x801AD8D0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801AD8D4: lwc1        $f10, 0x7940($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7940);
    // 0x801AD8D8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801AD8DC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801AD8E0: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801AD8E4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x801AD8E8: add.s       $f16, $f10, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x801AD8EC: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801AD8F0: c.lt.s      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.fl < ctx->f16.fl;
    // 0x801AD8F4: nop

    // 0x801AD8F8: bc1f        L_801AD944
    if (!c1cs) {
        // 0x801AD8FC: nop
    
            goto L_801AD944;
    }
    // 0x801AD8FC: nop

    // 0x801AD900: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801AD904: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x801AD908: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x801AD90C: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x801AD910: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801AD914: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x801AD918: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801AD91C: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x801AD920: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801AD924: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x801AD928: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x801AD92C: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    // 0x801AD930: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    // 0x801AD934: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x801AD938: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x801AD93C: jal         0x800365E4
    // 0x801AD940: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    PlayerShot_Effect344_Spawn(rdram, ctx);
        goto after_5;
    // 0x801AD940: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    after_5:
L_801AD944:
    // 0x801AD944: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x801AD948: lw          $v0, 0x7AF8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7AF8);
    // 0x801AD94C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801AD950: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801AD954: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x801AD958: sb          $t7, 0x7E84($at)
    MEM_B(0X7E84, ctx->r1) = ctx->r15;
    // 0x801AD95C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801AD960: sll         $t1, $v0, 1
    ctx->r9 = S32(ctx->r2 << 1);
    // 0x801AD964: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x801AD968: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x801AD96C: b           L_801ADAB4
    // 0x801AD970: sh          $t0, 0x7BD0($at)
    MEM_H(0X7BD0, ctx->r1) = ctx->r8;
        goto L_801ADAB4;
    // 0x801AD970: sh          $t0, 0x7BD0($at)
    MEM_H(0X7BD0, ctx->r1) = ctx->r8;
    // 0x801AD974: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
L_801AD978:
    // 0x801AD978: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801AD97C: lwc1        $f0, 0x110($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X110);
    // 0x801AD980: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801AD984: lwc1        $f8, -0x45C0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X45C0);
    // 0x801AD988: sub.s       $f6, $f10, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x801AD98C: lui         $at, 0x4198
    ctx->r1 = S32(0X4198 << 16);
    // 0x801AD990: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801AD994: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801AD998: mul.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x801AD99C: add.s       $f4, $f0, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x801AD9A0: swc1        $f4, 0x110($s0)
    MEM_W(0X110, ctx->r16) = ctx->f4.u32l;
    // 0x801AD9A4: lwc1        $f10, 0x110($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X110);
    // 0x801AD9A8: c.lt.s      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.fl < ctx->f10.fl;
    // 0x801AD9AC: nop

    // 0x801AD9B0: bc1fl       L_801AD9EC
    if (!c1cs) {
        // 0x801AD9B4: lui         $at, 0x4334
        ctx->r1 = S32(0X4334 << 16);
            goto L_801AD9EC;
    }
    goto skip_6;
    // 0x801AD9B4: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    skip_6:
    // 0x801AD9B8: lh          $t2, 0x46($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X46);
    // 0x801AD9BC: lwc1        $f6, 0x114($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X114);
    // 0x801AD9C0: lwc1        $f8, -0x45BC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X45BC);
    // 0x801AD9C4: addiu       $t3, $t2, -0x14
    ctx->r11 = ADD32(ctx->r10, -0X14);
    // 0x801AD9C8: sh          $t3, 0x46($s0)
    MEM_H(0X46, ctx->r16) = ctx->r11;
    // 0x801AD9CC: sub.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x801AD9D0: lh          $t4, 0x46($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X46);
    // 0x801AD9D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801AD9D8: bgez        $t4, L_801AD9E8
    if (SIGNED(ctx->r12) >= 0) {
        // 0x801AD9DC: swc1        $f16, 0x114($s0)
        MEM_W(0X114, ctx->r16) = ctx->f16.u32l;
            goto L_801AD9E8;
    }
    // 0x801AD9DC: swc1        $f16, 0x114($s0)
    MEM_W(0X114, ctx->r16) = ctx->f16.u32l;
    // 0x801AD9E0: jal         0x80060FBC
    // 0x801AD9E4: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    Object_Kill(rdram, ctx);
        goto after_6;
    // 0x801AD9E4: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    after_6:
L_801AD9E8:
    // 0x801AD9E8: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
L_801AD9EC:
    // 0x801AD9EC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801AD9F0: lwc1        $f18, 0x14($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X14);
    // 0x801AD9F4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x801AD9F8: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x801AD9FC: sub.s       $f10, $f4, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f18.fl;
    // 0x801ADA00: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x801ADA04: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801ADA08: swc1        $f10, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f10.u32l;
    // 0x801ADA0C: lw          $a0, -0x7D80($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7D80);
    // 0x801ADA10: lwc1        $f6, 0x138($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X138);
    // 0x801ADA14: sub.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x801ADA18: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x801ADA1C: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x801ADA20: nop

    // 0x801ADA24: bc1fl       L_801ADAB8
    if (!c1cs) {
        // 0x801ADA28: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_801ADAB8;
    }
    goto skip_7;
    // 0x801ADA28: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_7:
    // 0x801ADA2C: lwc1        $f4, 0x74($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X74);
    // 0x801ADA30: lwc1        $f18, 0x4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801ADA34: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x801ADA38: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801ADA3C: sub.s       $f0, $f4, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f18.fl;
    // 0x801ADA40: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x801ADA44: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x801ADA48: nop

    // 0x801ADA4C: bc1fl       L_801ADAB8
    if (!c1cs) {
        // 0x801ADA50: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_801ADAB8;
    }
    goto skip_8;
    // 0x801ADA50: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_8:
    // 0x801ADA54: lwc1        $f6, 0x78($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X78);
    // 0x801ADA58: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801ADA5C: lui         $at, 0xC0A0
    ctx->r1 = S32(0XC0A0 << 16);
    // 0x801ADA60: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801ADA64: sub.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x801ADA68: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x801ADA6C: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x801ADA70: nop

    // 0x801ADA74: bc1fl       L_801ADAB8
    if (!c1cs) {
        // 0x801ADA78: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_801ADAB8;
    }
    goto skip_9;
    // 0x801ADA78: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_9:
    // 0x801ADA7C: lwc1        $f4, 0x110($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X110);
    // 0x801ADA80: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801ADA84: nop

    // 0x801ADA88: mul.s       $f10, $f4, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x801ADA8C: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x801ADA90: nop

    // 0x801ADA94: bc1fl       L_801ADAB8
    if (!c1cs) {
        // 0x801ADA98: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_801ADAB8;
    }
    goto skip_10;
    // 0x801ADA98: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_10:
    // 0x801ADA9C: lw          $t5, 0x498($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X498);
    // 0x801ADAA0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801ADAA4: bnel        $t5, $zero, L_801ADAB8
    if (ctx->r13 != 0) {
        // 0x801ADAA8: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_801ADAB8;
    }
    goto skip_11;
    // 0x801ADAA8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_11:
    // 0x801ADAAC: jal         0x800A6CD0
    // 0x801ADAB0: lbu         $a2, 0x34($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X34);
    Player_ApplyDamage(rdram, ctx);
        goto after_7;
    // 0x801ADAB0: lbu         $a2, 0x34($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X34);
    after_7:
L_801ADAB4:
    // 0x801ADAB4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_801ADAB8:
    // 0x801ADAB8: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x801ADABC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x801ADAC0: jr          $ra
    // 0x801ADAC4: nop

    return;
    // 0x801ADAC4: nop

;}
RECOMP_FUNC void Macbeth_MaBoulder_Setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019D5C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8019D5CC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8019D5D0: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8019D5D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8019D5D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8019D5DC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8019D5E0: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8019D5E4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8019D5E8: jal         0x800613C4
    // 0x8019D5EC: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    Actor_Initialize(rdram, ctx);
        goto after_0;
    // 0x8019D5EC: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x8019D5F0: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8019D5F4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8019D5F8: addiu       $t7, $zero, 0xD7
    ctx->r15 = ADD32(0, 0XD7);
    // 0x8019D5FC: sb          $t6, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r14;
    // 0x8019D600: sh          $t7, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r15;
    // 0x8019D604: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8019D608: addiu       $t9, $zero, 0x14
    ctx->r25 = ADD32(0, 0X14);
    // 0x8019D60C: andi        $a1, $t7, 0xFFFF
    ctx->r5 = ctx->r15 & 0XFFFF;
    // 0x8019D610: swc1        $f4, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f4.u32l;
    // 0x8019D614: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8019D618: addiu       $a0, $a2, 0x1C
    ctx->r4 = ADD32(ctx->r6, 0X1C);
    // 0x8019D61C: swc1        $f6, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f6.u32l;
    // 0x8019D620: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8019D624: swc1        $f8, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f8.u32l;
    // 0x8019D628: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8019D62C: swc1        $f10, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->f10.u32l;
    // 0x8019D630: lwc1        $f16, 0x34($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8019D634: swc1        $f16, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->f16.u32l;
    // 0x8019D638: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x8019D63C: sh          $t9, 0xBE($a2)
    MEM_H(0XBE, ctx->r6) = ctx->r25;
    // 0x8019D640: sh          $t8, 0xBC($a2)
    MEM_H(0XBC, ctx->r6) = ctx->r24;
    // 0x8019D644: lwc1        $f18, 0x28($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8019D648: swc1        $f18, 0x114($a2)
    MEM_W(0X114, ctx->r6) = ctx->f18.u32l;
    // 0x8019D64C: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8019D650: swc1        $f4, 0xF0($a2)
    MEM_W(0XF0, ctx->r6) = ctx->f4.u32l;
    // 0x8019D654: lbu         $t0, 0x3F($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X3F);
    // 0x8019D658: jal         0x800612B8
    // 0x8019D65C: sh          $t0, 0x46($a2)
    MEM_H(0X46, ctx->r6) = ctx->r8;
    Object_SetInfo(rdram, ctx);
        goto after_1;
    // 0x8019D65C: sh          $t0, 0x46($a2)
    MEM_H(0X46, ctx->r6) = ctx->r8;
    after_1:
    // 0x8019D660: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8019D664: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8019D668: jr          $ra
    // 0x8019D66C: nop

    return;
    // 0x8019D66C: nop

;}
RECOMP_FUNC void Titania_80188F30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80188F30: lui         $v1, 0x801B
    ctx->r3 = S32(0X801B << 16);
    // 0x80188F34: lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // 0x80188F38: addiu       $v0, $v0, 0x7518
    ctx->r2 = ADD32(ctx->r2, 0X7518);
    // 0x80188F3C: addiu       $v1, $v1, 0x750C
    ctx->r3 = ADD32(ctx->r3, 0X750C);
L_80188F40:
    // 0x80188F40: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80188F44: bne         $v1, $v0, L_80188F40
    if (ctx->r3 != ctx->r2) {
        // 0x80188F48: sw          $zero, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = 0;
            goto L_80188F40;
    }
    // 0x80188F48: sw          $zero, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = 0;
    // 0x80188F4C: addiu       $t6, $zero, 0x63
    ctx->r14 = ADD32(0, 0X63);
    // 0x80188F50: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80188F54: sb          $t6, -0x5E18($at)
    MEM_B(-0X5E18, ctx->r1) = ctx->r14;
    // 0x80188F58: jr          $ra
    // 0x80188F5C: nop

    return;
    // 0x80188F5C: nop

;}
RECOMP_FUNC void Macbeth_801B28BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801B28BC: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x801B28C0: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x801B28C4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801B28C8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x801B28CC: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x801B28D0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x801B28D4: lw          $t6, -0x7D80($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7D80);
    // 0x801B28D8: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801B28DC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801B28E0: sw          $t6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r14;
    // 0x801B28E4: lwc1        $f4, 0x130($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X130);
    // 0x801B28E8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B28EC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801B28F0: swc1        $f8, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->f8.u32l;
    // 0x801B28F4: lwc1        $f16, -0x4338($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X4338);
    // 0x801B28F8: lwc1        $f10, 0x130($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X130);
    // 0x801B28FC: mul.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x801B2900: jal         0x80023090
    // 0x801B2904: nop

    __sinf_recomp(rdram, ctx);
        goto after_0;
    // 0x801B2904: nop

    after_0:
    // 0x801B2908: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x801B290C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801B2910: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801B2914: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801B2918: lwc1        $f6, 0x134($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X134);
    // 0x801B291C: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x801B2920: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B2924: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801B2928: swc1        $f10, 0x134($s0)
    MEM_W(0X134, ctx->r16) = ctx->f10.u32l;
    // 0x801B292C: swc1        $f4, 0xFC($s0)
    MEM_W(0XFC, ctx->r16) = ctx->f4.u32l;
    // 0x801B2930: lwc1        $f18, -0x4334($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X4334);
    // 0x801B2934: lwc1        $f16, 0x134($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X134);
    // 0x801B2938: mul.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x801B293C: jal         0x80023090
    // 0x801B2940: nop

    __sinf_recomp(rdram, ctx);
        goto after_1;
    // 0x801B2940: nop

    after_1:
    // 0x801B2944: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801B2948: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801B294C: nop

    // 0x801B2950: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x801B2954: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    // 0x801B2958: lh          $t7, 0xB8($s0)
    ctx->r15 = MEM_H(ctx->r16, 0XB8);
    // 0x801B295C: addiu       $t8, $t7, -0xA
    ctx->r24 = ADD32(ctx->r15, -0XA);
    // 0x801B2960: sltiu       $at, $t8, 0x17
    ctx->r1 = ctx->r24 < 0X17 ? 1 : 0;
    // 0x801B2964: beq         $at, $zero, L_801B34B0
    if (ctx->r1 == 0) {
        // 0x801B2968: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_801B34B0;
    }
    // 0x801B2968: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x801B296C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B2970: addu        $at, $at, $t8
    gpr jr_addend_801B2978 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x801B2974: lw          $t8, -0x4330($at)
    ctx->r24 = ADD32(ctx->r1, -0X4330);
    // 0x801B2978: jr          $t8
    // 0x801B297C: nop

    switch (jr_addend_801B2978 >> 2) {
        case 0: goto L_801B2980; break;
        case 1: goto L_801B2B28; break;
        case 2: goto L_801B2B74; break;
        case 3: goto L_801B2C30; break;
        case 4: goto L_801B2CC8; break;
        case 5: goto L_801B2E58; break;
        case 6: goto L_801B2F00; break;
        case 7: goto L_801B2FA8; break;
        case 8: goto L_801B34B0; break;
        case 9: goto L_801B34B0; break;
        case 10: goto L_801B3128; break;
        case 11: goto L_801B3170; break;
        case 12: goto L_801B31D4; break;
        case 13: goto L_801B34B0; break;
        case 14: goto L_801B34B0; break;
        case 15: goto L_801B34B0; break;
        case 16: goto L_801B34B0; break;
        case 17: goto L_801B34B0; break;
        case 18: goto L_801B34B0; break;
        case 19: goto L_801B34B0; break;
        case 20: goto L_801B3220; break;
        case 21: goto L_801B33F0; break;
        case 22: goto L_801B3440; break;
        default: switch_error(__func__, 0x801B2978, 0x801BBCD0);
    }
    // 0x801B297C: nop

L_801B2980:
    // 0x801B2980: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B2984: lwc1        $f10, -0x579C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X579C);
    // 0x801B2988: lwc1        $f8, 0x120($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X120);
    // 0x801B298C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B2990: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801B2994: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801B2998: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801B299C: swc1        $f16, 0x120($s0)
    MEM_W(0X120, ctx->r16) = ctx->f16.u32l;
    // 0x801B29A0: lwc1        $f4, -0x42D4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X42D4);
    // 0x801B29A4: lwc1        $f18, 0x120($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X120);
    // 0x801B29A8: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801B29AC: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x801B29B0: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x801B29B4: jal         0x80005E90
    // 0x801B29B8: nop

    Matrix_RotateY(rdram, ctx);
        goto after_2;
    // 0x801B29B8: nop

    after_2:
    // 0x801B29BC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B29C0: lwc1        $f2, -0x42D0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X42D0);
    // 0x801B29C4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B29C8: lwc1        $f8, -0x577C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X577C);
    // 0x801B29CC: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801B29D0: addiu       $v0, $v0, -0x576C
    ctx->r2 = ADD32(ctx->r2, -0X576C);
    // 0x801B29D4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B29D8: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x801B29DC: lwc1        $f10, 0x10($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X10);
    // 0x801B29E0: lwc1        $f16, -0x42CC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X42CC);
    // 0x801B29E4: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801B29E8: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x801B29EC: addiu       $a0, $a0, -0x575C
    ctx->r4 = ADD32(ctx->r4, -0X575C);
    // 0x801B29F0: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    // 0x801B29F4: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    // 0x801B29F8: swc1        $f8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f8.u32l;
    // 0x801B29FC: swc1        $f20, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f20.u32l;
    // 0x801B2A00: swc1        $f10, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f10.u32l;
    // 0x801B2A04: jal         0x8009BC2C
    // 0x801B2A08: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_3;
    // 0x801B2A08: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_3:
    // 0x801B2A0C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801B2A10: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801B2A14: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    // 0x801B2A18: jal         0x80006970
    // 0x801B2A1C: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    Matrix_MultVec3f(rdram, ctx);
        goto after_4;
    // 0x801B2A1C: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    after_4:
    // 0x801B2A20: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x801B2A24: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x801B2A28: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801B2A2C: swc1        $f18, 0x114($s0)
    MEM_W(0X114, ctx->r16) = ctx->f18.u32l;
    // 0x801B2A30: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x801B2A34: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B2A38: lwc1        $f16, 0x120($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X120);
    // 0x801B2A3C: swc1        $f4, 0x118($s0)
    MEM_W(0X118, ctx->r16) = ctx->f4.u32l;
    // 0x801B2A40: lwc1        $f6, 0x4C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x801B2A44: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x801B2A48: swc1        $f10, 0x11C($s0)
    MEM_W(0X11C, ctx->r16) = ctx->f10.u32l;
    // 0x801B2A4C: lwc1        $f18, -0x42C8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X42C8);
    // 0x801B2A50: mul.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x801B2A54: jal         0x80023090
    // 0x801B2A58: nop

    __sinf_recomp(rdram, ctx);
        goto after_5;
    // 0x801B2A58: nop

    after_5:
    // 0x801B2A5C: lui         $at, 0xC1F0
    ctx->r1 = S32(0XC1F0 << 16);
    // 0x801B2A60: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801B2A64: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x801B2A68: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801B2A6C: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x801B2A70: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x801B2A74: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x801B2A78: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x801B2A7C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x801B2A80: jal         0x8009BC2C
    // 0x801B2A84: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_6;
    // 0x801B2A84: nop

    after_6:
    // 0x801B2A88: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x801B2A8C: lwc1        $f8, 0x114($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X114);
    // 0x801B2A90: lui         $a2, 0x3CF5
    ctx->r6 = S32(0X3CF5 << 16);
    // 0x801B2A94: lwc1        $f10, 0x74($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X74);
    // 0x801B2A98: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x801B2A9C: ori         $a2, $a2, 0xC28F
    ctx->r6 = ctx->r6 | 0XC28F;
    // 0x801B2AA0: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801B2AA4: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x801B2AA8: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x801B2AAC: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x801B2AB0: jal         0x8009BC2C
    // 0x801B2AB4: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_7;
    // 0x801B2AB4: nop

    after_7:
    // 0x801B2AB8: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x801B2ABC: lwc1        $f18, 0x118($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X118);
    // 0x801B2AC0: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x801B2AC4: lwc1        $f4, 0x78($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X78);
    // 0x801B2AC8: lui         $a2, 0x3CF5
    ctx->r6 = S32(0X3CF5 << 16);
    // 0x801B2ACC: ori         $a2, $a2, 0xC28F
    ctx->r6 = ctx->r6 | 0XC28F;
    // 0x801B2AD0: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x801B2AD4: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x801B2AD8: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x801B2ADC: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x801B2AE0: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801B2AE4: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x801B2AE8: jal         0x8009BC2C
    // 0x801B2AEC: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_8;
    // 0x801B2AEC: nop

    after_8:
    // 0x801B2AF0: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x801B2AF4: lwc1        $f16, 0x11C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X11C);
    // 0x801B2AF8: lui         $a2, 0x3CF5
    ctx->r6 = S32(0X3CF5 << 16);
    // 0x801B2AFC: lwc1        $f18, 0x138($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0X138);
    // 0x801B2B00: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x801B2B04: ori         $a2, $a2, 0xC28F
    ctx->r6 = ctx->r6 | 0XC28F;
    // 0x801B2B08: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x801B2B0C: addiu       $a0, $s0, 0xC
    ctx->r4 = ADD32(ctx->r16, 0XC);
    // 0x801B2B10: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x801B2B14: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x801B2B18: jal         0x8009BC2C
    // 0x801B2B1C: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_9;
    // 0x801B2B1C: nop

    after_9:
    // 0x801B2B20: b           L_801B34B0
    // 0x801B2B24: nop

        goto L_801B34B0;
    // 0x801B2B24: nop

L_801B2B28:
    // 0x801B2B28: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x801B2B2C: lui         $t2, 0x800C
    ctx->r10 = S32(0X800C << 16);
    // 0x801B2B30: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x801B2B34: addiu       $t2, $t2, 0x5D3C
    ctx->r10 = ADD32(ctx->r10, 0X5D3C);
    // 0x801B2B38: lui         $a0, 0x900
    ctx->r4 = S32(0X900 << 16);
    // 0x801B2B3C: ori         $a0, $a0, 0x2
    ctx->r4 = ctx->r4 | 0X2;
    // 0x801B2B40: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x801B2B44: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x801B2B48: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x801B2B4C: jal         0x80019218
    // 0x801B2B50: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Audio_PlaySfx(rdram, ctx);
        goto after_10;
    // 0x801B2B50: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_10:
    // 0x801B2B54: lh          $t4, 0xB8($s0)
    ctx->r12 = MEM_H(ctx->r16, 0XB8);
    // 0x801B2B58: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x801B2B5C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801B2B60: addiu       $t3, $zero, 0xA
    ctx->r11 = ADD32(0, 0XA);
    // 0x801B2B64: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x801B2B68: sh          $t3, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r11;
    // 0x801B2B6C: sh          $t5, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r13;
    // 0x801B2B70: swc1        $f6, 0x188($s0)
    MEM_W(0X188, ctx->r16) = ctx->f6.u32l;
L_801B2B74:
    // 0x801B2B74: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x801B2B78: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x801B2B7C: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x801B2B80: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x801B2B84: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801B2B88: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    // 0x801B2B8C: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x801B2B90: jal         0x8009BC2C
    // 0x801B2B94: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_11;
    // 0x801B2B94: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_11:
    // 0x801B2B98: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x801B2B9C: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x801B2BA0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801B2BA4: lwc1        $f8, 0x74($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X74);
    // 0x801B2BA8: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x801B2BAC: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801B2BB0: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x801B2BB4: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x801B2BB8: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x801B2BBC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x801B2BC0: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x801B2BC4: jal         0x8009BC2C
    // 0x801B2BC8: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_12;
    // 0x801B2BC8: nop

    after_12:
    // 0x801B2BCC: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x801B2BD0: sw          $t7, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r15;
    // 0x801B2BD4: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x801B2BD8: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801B2BDC: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x801B2BE0: addiu       $a0, $s0, 0x138
    ctx->r4 = ADD32(ctx->r16, 0X138);
    // 0x801B2BE4: lui         $a1, 0x41A0
    ctx->r5 = S32(0X41A0 << 16);
    // 0x801B2BE8: jal         0x8009BC2C
    // 0x801B2BEC: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    Math_SmoothStepToF(rdram, ctx);
        goto after_13;
    // 0x801B2BEC: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    after_13:
    // 0x801B2BF0: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x801B2BF4: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x801B2BF8: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801B2BFC: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x801B2C00: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x801B2C04: jal         0x8009BC2C
    // 0x801B2C08: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_14;
    // 0x801B2C08: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_14:
    // 0x801B2C0C: lhu         $t8, 0xBC($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0XBC);
    // 0x801B2C10: bgtz        $t8, L_801B34B0
    if (SIGNED(ctx->r24) > 0) {
        // 0x801B2C14: nop
    
            goto L_801B34B0;
    }
    // 0x801B2C14: nop

    // 0x801B2C18: lh          $t0, 0xB8($s0)
    ctx->r8 = MEM_H(ctx->r16, 0XB8);
    // 0x801B2C1C: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x801B2C20: sh          $t9, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r25;
    // 0x801B2C24: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x801B2C28: b           L_801B34B0
    // 0x801B2C2C: sh          $t1, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r9;
        goto L_801B34B0;
    // 0x801B2C2C: sh          $t1, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r9;
L_801B2C30:
    // 0x801B2C30: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x801B2C34: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x801B2C38: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801B2C3C: lwc1        $f18, 0x74($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X74);
    // 0x801B2C40: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x801B2C44: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x801B2C48: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x801B2C4C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801B2C50: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x801B2C54: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x801B2C58: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x801B2C5C: jal         0x8009BC2C
    // 0x801B2C60: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_15;
    // 0x801B2C60: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_15:
    // 0x801B2C64: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x801B2C68: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801B2C6C: addiu       $a0, $s0, 0x10
    ctx->r4 = ADD32(ctx->r16, 0X10);
    // 0x801B2C70: lui         $a1, 0xC2F0
    ctx->r5 = S32(0XC2F0 << 16);
    // 0x801B2C74: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x801B2C78: jal         0x8009BC2C
    // 0x801B2C7C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_16;
    // 0x801B2C7C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_16:
    // 0x801B2C80: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B2C84: lwc1        $f2, -0x42C4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X42C4);
    // 0x801B2C88: lui         $a3, 0x3E4C
    ctx->r7 = S32(0X3E4C << 16);
    // 0x801B2C8C: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x801B2C90: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x801B2C94: addiu       $a0, $s0, 0x138
    ctx->r4 = ADD32(ctx->r16, 0X138);
    // 0x801B2C98: lui         $a1, 0xC1A0
    ctx->r5 = S32(0XC1A0 << 16);
    // 0x801B2C9C: jal         0x8009BC2C
    // 0x801B2CA0: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_17;
    // 0x801B2CA0: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_17:
    // 0x801B2CA4: lhu         $t3, 0xBC($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0XBC);
    // 0x801B2CA8: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801B2CAC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801B2CB0: bgtz        $t3, L_801B34B0
    if (SIGNED(ctx->r11) > 0) {
        // 0x801B2CB4: swc1        $f8, 0x188($s0)
        MEM_W(0X188, ctx->r16) = ctx->f8.u32l;
            goto L_801B34B0;
    }
    // 0x801B2CB4: swc1        $f8, 0x188($s0)
    MEM_W(0X188, ctx->r16) = ctx->f8.u32l;
    // 0x801B2CB8: lh          $t4, 0xB8($s0)
    ctx->r12 = MEM_H(ctx->r16, 0XB8);
    // 0x801B2CBC: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x801B2CC0: b           L_801B34B0
    // 0x801B2CC4: sh          $t5, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r13;
        goto L_801B34B0;
    // 0x801B2CC4: sh          $t5, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r13;
L_801B2CC8:
    // 0x801B2CC8: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x801B2CCC: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x801B2CD0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801B2CD4: lwc1        $f10, 0x74($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X74);
    // 0x801B2CD8: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x801B2CDC: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x801B2CE0: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x801B2CE4: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801B2CE8: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x801B2CEC: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    // 0x801B2CF0: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x801B2CF4: jal         0x8009BC2C
    // 0x801B2CF8: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_18;
    // 0x801B2CF8: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_18:
    // 0x801B2CFC: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x801B2D00: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801B2D04: addiu       $a0, $s0, 0x10
    ctx->r4 = ADD32(ctx->r16, 0X10);
    // 0x801B2D08: lui         $a1, 0xC2F0
    ctx->r5 = S32(0XC2F0 << 16);
    // 0x801B2D0C: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x801B2D10: jal         0x8009BC2C
    // 0x801B2D14: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_19;
    // 0x801B2D14: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_19:
    // 0x801B2D18: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B2D1C: lwc1        $f2, -0x42C0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X42C0);
    // 0x801B2D20: lui         $a3, 0x3E4C
    ctx->r7 = S32(0X3E4C << 16);
    // 0x801B2D24: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x801B2D28: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x801B2D2C: addiu       $a0, $s0, 0x138
    ctx->r4 = ADD32(ctx->r16, 0X138);
    // 0x801B2D30: lui         $a1, 0x41B0
    ctx->r5 = S32(0X41B0 << 16);
    // 0x801B2D34: jal         0x8009BC2C
    // 0x801B2D38: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_20;
    // 0x801B2D38: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_20:
    // 0x801B2D3C: lui         $at, 0xC2E6
    ctx->r1 = S32(0XC2E6 << 16);
    // 0x801B2D40: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801B2D44: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    // 0x801B2D48: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x801B2D4C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801B2D50: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x801B2D54: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x801B2D58: lui         $a1, 0x4448
    ctx->r5 = S32(0X4448 << 16);
    // 0x801B2D5C: lui         $a3, 0x4190
    ctx->r7 = S32(0X4190 << 16);
    // 0x801B2D60: bc1f        L_801B34B0
    if (!c1cs) {
        // 0x801B2D64: nop
    
            goto L_801B34B0;
    }
    // 0x801B2D64: nop

    // 0x801B2D68: jal         0x8009BC2C
    // 0x801B2D6C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_21;
    // 0x801B2D6C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_21:
    // 0x801B2D70: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B2D74: lwc1        $f10, -0x42BC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X42BC);
    // 0x801B2D78: lwc1        $f8, 0x14($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X14);
    // 0x801B2D7C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801B2D80: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801B2D84: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x801B2D88: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801B2D8C: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x801B2D90: jal         0x80005E90
    // 0x801B2D94: nop

    Matrix_RotateY(rdram, ctx);
        goto after_22;
    // 0x801B2D94: nop

    after_22:
    // 0x801B2D98: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B2D9C: lwc1        $f4, -0x42B8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X42B8);
    // 0x801B2DA0: lwc1        $f18, 0x10($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X10);
    // 0x801B2DA4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801B2DA8: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801B2DAC: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x801B2DB0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801B2DB4: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x801B2DB8: jal         0x80005D44
    // 0x801B2DBC: nop

    Matrix_RotateX(rdram, ctx);
        goto after_23;
    // 0x801B2DBC: nop

    after_23:
    // 0x801B2DC0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B2DC4: lwc1        $f10, -0x42B4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X42B4);
    // 0x801B2DC8: lwc1        $f8, 0x18($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X18);
    // 0x801B2DCC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801B2DD0: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801B2DD4: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x801B2DD8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801B2DDC: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x801B2DE0: jal         0x80005FE0
    // 0x801B2DE4: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_24;
    // 0x801B2DE4: nop

    after_24:
    // 0x801B2DE8: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x801B2DEC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801B2DF0: lui         $at, 0xC28C
    ctx->r1 = S32(0XC28C << 16);
    // 0x801B2DF4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801B2DF8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801B2DFC: swc1        $f20, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f20.u32l;
    // 0x801B2E00: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801B2E04: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    // 0x801B2E08: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    // 0x801B2E0C: swc1        $f18, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f18.u32l;
    // 0x801B2E10: jal         0x80006A20
    // 0x801B2E14: swc1        $f4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f4.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_25;
    // 0x801B2E14: swc1        $f4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f4.u32l;
    after_25:
    // 0x801B2E18: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801B2E1C: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x801B2E20: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x801B2E24: lwc1        $f4, 0x4C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x801B2E28: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801B2E2C: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801B2E30: lwc1        $f16, 0x48($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X48);
    // 0x801B2E34: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x801B2E38: lui         $a3, 0x4046
    ctx->r7 = S32(0X4046 << 16);
    // 0x801B2E3C: ori         $a3, $a3, 0x6666
    ctx->r7 = ctx->r7 | 0X6666;
    // 0x801B2E40: add.s       $f14, $f10, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801B2E44: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x801B2E48: jal         0x80078E50
    // 0x801B2E4C: nop

    Effect_Sparkle_Spawn(rdram, ctx);
        goto after_26;
    // 0x801B2E4C: nop

    after_26:
    // 0x801B2E50: b           L_801B34B0
    // 0x801B2E54: nop

        goto L_801B34B0;
    // 0x801B2E54: nop

L_801B2E58:
    // 0x801B2E58: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B2E5C: lwc1        $f2, -0x42B0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X42B0);
    // 0x801B2E60: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x801B2E64: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801B2E68: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x801B2E6C: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x801B2E70: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x801B2E74: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x801B2E78: jal         0x8009BD38
    // 0x801B2E7C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_27;
    // 0x801B2E7C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_27:
    // 0x801B2E80: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801B2E84: lui         $a3, 0x3E99
    ctx->r7 = S32(0X3E99 << 16);
    // 0x801B2E88: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x801B2E8C: addiu       $a0, $s0, 0x14
    ctx->r4 = ADD32(ctx->r16, 0X14);
    // 0x801B2E90: lui         $a1, 0x4334
    ctx->r5 = S32(0X4334 << 16);
    // 0x801B2E94: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x801B2E98: jal         0x8009BD38
    // 0x801B2E9C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_28;
    // 0x801B2E9C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_28:
    // 0x801B2EA0: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x801B2EA4: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x801B2EA8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801B2EAC: lwc1        $f16, 0x78($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X78);
    // 0x801B2EB0: lui         $a2, 0x3CF5
    ctx->r6 = S32(0X3CF5 << 16);
    // 0x801B2EB4: ori         $a2, $a2, 0xC28F
    ctx->r6 = ctx->r6 | 0XC28F;
    // 0x801B2EB8: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x801B2EBC: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x801B2EC0: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x801B2EC4: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    // 0x801B2EC8: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x801B2ECC: jal         0x8009BC2C
    // 0x801B2ED0: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_29;
    // 0x801B2ED0: nop

    after_29:
    // 0x801B2ED4: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x801B2ED8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801B2EDC: lwc1        $f8, 0x14($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X14);
    // 0x801B2EE0: c.eq.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl == ctx->f8.fl;
    // 0x801B2EE4: nop

    // 0x801B2EE8: bc1f        L_801B34B0
    if (!c1cs) {
        // 0x801B2EEC: nop
    
            goto L_801B34B0;
    }
    // 0x801B2EEC: nop

    // 0x801B2EF0: lh          $t8, 0xB8($s0)
    ctx->r24 = MEM_H(ctx->r16, 0XB8);
    // 0x801B2EF4: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x801B2EF8: b           L_801B34B0
    // 0x801B2EFC: sh          $t9, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r25;
        goto L_801B34B0;
    // 0x801B2EFC: sh          $t9, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r25;
L_801B2F00:
    // 0x801B2F00: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801B2F04: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801B2F08: lwc1        $f10, 0x114($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X114);
    // 0x801B2F0C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x801B2F10: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801B2F14: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801B2F18: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801B2F1C: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x801B2F20: lui         $a1, 0x4278
    ctx->r5 = S32(0X4278 << 16);
    // 0x801B2F24: swc1        $f18, 0x114($s0)
    MEM_W(0X114, ctx->r16) = ctx->f18.u32l;
    // 0x801B2F28: lwc1        $f6, 0x114($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X114);
    // 0x801B2F2C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x801B2F30: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    // 0x801B2F34: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801B2F38: swc1        $f8, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f8.u32l;
    // 0x801B2F3C: jal         0x8009BD38
    // 0x801B2F40: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_30;
    // 0x801B2F40: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_30:
    // 0x801B2F44: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x801B2F48: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801B2F4C: lwc1        $f18, 0x114($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X114);
    // 0x801B2F50: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x801B2F54: lui         $a0, 0x900
    ctx->r4 = S32(0X900 << 16);
    // 0x801B2F58: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x801B2F5C: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x801B2F60: ori         $a0, $a0, 0x2
    ctx->r4 = ctx->r4 | 0X2;
    // 0x801B2F64: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x801B2F68: bc1f        L_801B34B0
    if (!c1cs) {
        // 0x801B2F6C: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_801B34B0;
    }
    // 0x801B2F6C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801B2F70: lh          $t0, 0xB8($s0)
    ctx->r8 = MEM_H(ctx->r16, 0XB8);
    // 0x801B2F74: lui         $t2, 0x800C
    ctx->r10 = S32(0X800C << 16);
    // 0x801B2F78: addiu       $t2, $t2, 0x5D3C
    ctx->r10 = ADD32(ctx->r10, 0X5D3C);
    // 0x801B2F7C: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x801B2F80: sh          $t1, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r9;
    // 0x801B2F84: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x801B2F88: jal         0x80019218
    // 0x801B2F8C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    Audio_PlaySfx(rdram, ctx);
        goto after_31;
    // 0x801B2F8C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_31:
    // 0x801B2F90: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x801B2F94: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801B2F98: addiu       $t3, $zero, 0xA0
    ctx->r11 = ADD32(0, 0XA0);
    // 0x801B2F9C: sh          $t3, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r11;
    // 0x801B2FA0: b           L_801B34B0
    // 0x801B2FA4: swc1        $f4, 0x188($s0)
    MEM_W(0X188, ctx->r16) = ctx->f4.u32l;
        goto L_801B34B0;
    // 0x801B2FA4: swc1        $f4, 0x188($s0)
    MEM_W(0X188, ctx->r16) = ctx->f4.u32l;
L_801B2FA8:
    // 0x801B2FA8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B2FAC: lwc1        $f6, -0x42AC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X42AC);
    // 0x801B2FB0: lui         $a1, 0x43AC
    ctx->r5 = S32(0X43AC << 16);
    // 0x801B2FB4: ori         $a1, $a1, 0x8000
    ctx->r5 = ctx->r5 | 0X8000;
    // 0x801B2FB8: addiu       $a0, $s0, 0x14
    ctx->r4 = ADD32(ctx->r16, 0X14);
    // 0x801B2FBC: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x801B2FC0: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    // 0x801B2FC4: jal         0x8009BD38
    // 0x801B2FC8: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_32;
    // 0x801B2FC8: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_32:
    // 0x801B2FCC: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x801B2FD0: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x801B2FD4: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801B2FD8: addiu       $a0, $s0, 0x10
    ctx->r4 = ADD32(ctx->r16, 0X10);
    // 0x801B2FDC: lui         $a1, 0x43A4
    ctx->r5 = S32(0X43A4 << 16);
    // 0x801B2FE0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x801B2FE4: jal         0x8009BD38
    // 0x801B2FE8: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_33;
    // 0x801B2FE8: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_33:
    // 0x801B2FEC: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x801B2FF0: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801B2FF4: addiu       $a0, $s0, 0x138
    ctx->r4 = ADD32(ctx->r16, 0X138);
    // 0x801B2FF8: lui         $a1, 0x420C
    ctx->r5 = S32(0X420C << 16);
    // 0x801B2FFC: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    // 0x801B3000: jal         0x8009BC2C
    // 0x801B3004: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_34;
    // 0x801B3004: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_34:
    // 0x801B3008: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801B300C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801B3010: lui         $a1, 0x43CA
    ctx->r5 = S32(0X43CA << 16);
    // 0x801B3014: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x801B3018: swc1        $f8, 0x188($s0)
    MEM_W(0X188, ctx->r16) = ctx->f8.u32l;
    // 0x801B301C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x801B3020: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801B3024: ori         $a1, $a1, 0x8000
    ctx->r5 = ctx->r5 | 0X8000;
    // 0x801B3028: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x801B302C: jal         0x8009BC2C
    // 0x801B3030: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    Math_SmoothStepToF(rdram, ctx);
        goto after_35;
    // 0x801B3030: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    after_35:
    // 0x801B3034: lhu         $t4, 0xBC($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0XBC);
    // 0x801B3038: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B303C: bne         $t4, $zero, L_801B34B0
    if (ctx->r12 != 0) {
        // 0x801B3040: nop
    
            goto L_801B34B0;
    }
    // 0x801B3040: nop

    // 0x801B3044: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    // 0x801B3048: lwc1        $f16, -0x42A8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X42A8);
    // 0x801B304C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801B3050: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801B3054: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x801B3058: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801B305C: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x801B3060: jal         0x80005E90
    // 0x801B3064: nop

    Matrix_RotateY(rdram, ctx);
        goto after_36;
    // 0x801B3064: nop

    after_36:
    // 0x801B3068: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B306C: lwc1        $f6, -0x42A4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X42A4);
    // 0x801B3070: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x801B3074: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801B3078: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801B307C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x801B3080: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801B3084: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x801B3088: jal         0x80005D44
    // 0x801B308C: nop

    Matrix_RotateX(rdram, ctx);
        goto after_37;
    // 0x801B308C: nop

    after_37:
    // 0x801B3090: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B3094: lwc1        $f16, -0x42A0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X42A0);
    // 0x801B3098: lwc1        $f10, 0x18($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X18);
    // 0x801B309C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801B30A0: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801B30A4: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x801B30A8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801B30AC: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x801B30B0: jal         0x80005FE0
    // 0x801B30B4: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_38;
    // 0x801B30B4: nop

    after_38:
    // 0x801B30B8: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x801B30BC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801B30C0: lui         $at, 0xC28C
    ctx->r1 = S32(0XC28C << 16);
    // 0x801B30C4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801B30C8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801B30CC: swc1        $f20, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f20.u32l;
    // 0x801B30D0: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801B30D4: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    // 0x801B30D8: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    // 0x801B30DC: swc1        $f4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f4.u32l;
    // 0x801B30E0: jal         0x80006A20
    // 0x801B30E4: swc1        $f6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f6.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_39;
    // 0x801B30E4: swc1        $f6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f6.u32l;
    after_39:
    // 0x801B30E8: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801B30EC: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x801B30F0: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x801B30F4: lwc1        $f6, 0x4C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x801B30F8: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801B30FC: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801B3100: lwc1        $f18, 0x48($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X48);
    // 0x801B3104: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801B3108: lui         $a3, 0x4046
    ctx->r7 = S32(0X4046 << 16);
    // 0x801B310C: ori         $a3, $a3, 0x6666
    ctx->r7 = ctx->r7 | 0X6666;
    // 0x801B3110: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x801B3114: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x801B3118: jal         0x80078E50
    // 0x801B311C: nop

    Effect_Sparkle_Spawn(rdram, ctx);
        goto after_40;
    // 0x801B311C: nop

    after_40:
    // 0x801B3120: b           L_801B34B0
    // 0x801B3124: nop

        goto L_801B34B0;
    // 0x801B3124: nop

L_801B3128:
    // 0x801B3128: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x801B312C: lui         $a1, 0x43AC
    ctx->r5 = S32(0X43AC << 16);
    // 0x801B3130: lui         $a2, 0x3C23
    ctx->r6 = S32(0X3C23 << 16);
    // 0x801B3134: lw          $a3, 0x124($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X124);
    // 0x801B3138: ori         $a2, $a2, 0xD70A
    ctx->r6 = ctx->r6 | 0XD70A;
    // 0x801B313C: ori         $a1, $a1, 0x8000
    ctx->r5 = ctx->r5 | 0X8000;
    // 0x801B3140: addiu       $a0, $s0, 0x10
    ctx->r4 = ADD32(ctx->r16, 0X10);
    // 0x801B3144: jal         0x8009BD38
    // 0x801B3148: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_41;
    // 0x801B3148: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_41:
    // 0x801B314C: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x801B3150: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801B3154: addiu       $a0, $s0, 0xF0
    ctx->r4 = ADD32(ctx->r16, 0XF0);
    // 0x801B3158: lui         $a1, 0xC396
    ctx->r5 = S32(0XC396 << 16);
    // 0x801B315C: lui         $a3, 0x3E80
    ctx->r7 = S32(0X3E80 << 16);
    // 0x801B3160: jal         0x8009BC2C
    // 0x801B3164: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_42;
    // 0x801B3164: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_42:
    // 0x801B3168: b           L_801B34B0
    // 0x801B316C: nop

        goto L_801B34B0;
    // 0x801B316C: nop

L_801B3170:
    // 0x801B3170: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x801B3174: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x801B3178: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801B317C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x801B3180: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x801B3184: lui         $a3, 0x3E80
    ctx->r7 = S32(0X3E80 << 16);
    // 0x801B3188: jal         0x8009BC2C
    // 0x801B318C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_43;
    // 0x801B318C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_43:
    // 0x801B3190: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x801B3194: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x801B3198: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801B319C: lw          $a1, 0x74($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X74);
    // 0x801B31A0: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x801B31A4: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x801B31A8: jal         0x8009BC2C
    // 0x801B31AC: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    Math_SmoothStepToF(rdram, ctx);
        goto after_44;
    // 0x801B31AC: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    after_44:
    // 0x801B31B0: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x801B31B4: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801B31B8: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x801B31BC: lui         $a1, 0x4448
    ctx->r5 = S32(0X4448 << 16);
    // 0x801B31C0: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x801B31C4: jal         0x8009BC2C
    // 0x801B31C8: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_45;
    // 0x801B31C8: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_45:
    // 0x801B31CC: b           L_801B34B0
    // 0x801B31D0: nop

        goto L_801B34B0;
    // 0x801B31D0: nop

L_801B31D4:
    // 0x801B31D4: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x801B31D8: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x801B31DC: lui         $a3, 0x3BA3
    ctx->r7 = S32(0X3BA3 << 16);
    // 0x801B31E0: ori         $a3, $a3, 0xD70A
    ctx->r7 = ctx->r7 | 0XD70A;
    // 0x801B31E4: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801B31E8: addiu       $a0, $s0, 0x124
    ctx->r4 = ADD32(ctx->r16, 0X124);
    // 0x801B31EC: lui         $a1, 0x3E80
    ctx->r5 = S32(0X3E80 << 16);
    // 0x801B31F0: jal         0x8009BD38
    // 0x801B31F4: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_46;
    // 0x801B31F4: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_46:
    // 0x801B31F8: lui         $a1, 0x43AC
    ctx->r5 = S32(0X43AC << 16);
    // 0x801B31FC: lui         $a2, 0x3C23
    ctx->r6 = S32(0X3C23 << 16);
    // 0x801B3200: lw          $a3, 0x124($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X124);
    // 0x801B3204: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x801B3208: ori         $a2, $a2, 0xD70A
    ctx->r6 = ctx->r6 | 0XD70A;
    // 0x801B320C: ori         $a1, $a1, 0x8000
    ctx->r5 = ctx->r5 | 0X8000;
    // 0x801B3210: jal         0x8009BD38
    // 0x801B3214: addiu       $a0, $s0, 0x10
    ctx->r4 = ADD32(ctx->r16, 0X10);
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_47;
    // 0x801B3214: addiu       $a0, $s0, 0x10
    ctx->r4 = ADD32(ctx->r16, 0X10);
    after_47:
    // 0x801B3218: b           L_801B34B0
    // 0x801B321C: nop

        goto L_801B34B0;
    // 0x801B321C: nop

L_801B3220:
    // 0x801B3220: lw          $t6, 0x40($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X40);
    // 0x801B3224: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B3228: lwc1        $f10, 0x120($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X120);
    // 0x801B322C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801B3230: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x801B3234: lwc1        $f16, -0x57AC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X57AC);
    // 0x801B3238: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B323C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801B3240: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801B3244: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801B3248: swc1        $f18, 0x120($s0)
    MEM_W(0X120, ctx->r16) = ctx->f18.u32l;
    // 0x801B324C: lwc1        $f6, -0x429C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X429C);
    // 0x801B3250: lwc1        $f4, 0x120($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X120);
    // 0x801B3254: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801B3258: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x801B325C: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x801B3260: jal         0x80005E90
    // 0x801B3264: nop

    Matrix_RotateY(rdram, ctx);
        goto after_48;
    // 0x801B3264: nop

    after_48:
    // 0x801B3268: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x801B326C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B3270: lwc1        $f2, -0x4298($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X4298);
    // 0x801B3274: swc1        $f20, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f20.u32l;
    // 0x801B3278: lw          $t8, 0x40($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X40);
    // 0x801B327C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B3280: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801B3284: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x801B3288: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x801B328C: lwc1        $f10, -0x578C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X578C);
    // 0x801B3290: addiu       $v0, $v0, -0x576C
    ctx->r2 = ADD32(ctx->r2, -0X576C);
    // 0x801B3294: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B3298: swc1        $f10, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f10.u32l;
    // 0x801B329C: lw          $t0, 0x40($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X40);
    // 0x801B32A0: lwc1        $f18, -0x4294($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X4294);
    // 0x801B32A4: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x801B32A8: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x801B32AC: addu        $t2, $v0, $t1
    ctx->r10 = ADD32(ctx->r2, ctx->r9);
    // 0x801B32B0: lwc1        $f16, 0x0($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0X0);
    // 0x801B32B4: lui         $a1, 0x437A
    ctx->r5 = S32(0X437A << 16);
    // 0x801B32B8: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    // 0x801B32BC: swc1        $f16, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f16.u32l;
    // 0x801B32C0: lw          $t3, 0x40($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X40);
    // 0x801B32C4: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x801B32C8: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x801B32CC: jal         0x8009BC2C
    // 0x801B32D0: addu        $a0, $v0, $t4
    ctx->r4 = ADD32(ctx->r2, ctx->r12);
    Math_SmoothStepToF(rdram, ctx);
        goto after_49;
    // 0x801B32D0: addu        $a0, $v0, $t4
    ctx->r4 = ADD32(ctx->r2, ctx->r12);
    after_49:
    // 0x801B32D4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801B32D8: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801B32DC: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    // 0x801B32E0: jal         0x80006970
    // 0x801B32E4: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    Matrix_MultVec3f(rdram, ctx);
        goto after_50;
    // 0x801B32E4: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    after_50:
    // 0x801B32E8: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x801B32EC: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x801B32F0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801B32F4: swc1        $f4, 0x114($s0)
    MEM_W(0X114, ctx->r16) = ctx->f4.u32l;
    // 0x801B32F8: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x801B32FC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B3300: lwc1        $f18, 0x120($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X120);
    // 0x801B3304: swc1        $f6, 0x118($s0)
    MEM_W(0X118, ctx->r16) = ctx->f6.u32l;
    // 0x801B3308: lwc1        $f8, 0x4C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x801B330C: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x801B3310: swc1        $f16, 0x11C($s0)
    MEM_W(0X11C, ctx->r16) = ctx->f16.u32l;
    // 0x801B3314: lwc1        $f4, -0x4290($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4290);
    // 0x801B3318: mul.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x801B331C: jal         0x80023090
    // 0x801B3320: nop

    __sinf_recomp(rdram, ctx);
        goto after_51;
    // 0x801B3320: nop

    after_51:
    // 0x801B3324: lui         $at, 0xC1F0
    ctx->r1 = S32(0XC1F0 << 16);
    // 0x801B3328: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801B332C: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x801B3330: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801B3334: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x801B3338: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x801B333C: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x801B3340: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x801B3344: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x801B3348: jal         0x8009BC2C
    // 0x801B334C: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_52;
    // 0x801B334C: nop

    after_52:
    // 0x801B3350: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x801B3354: lwc1        $f10, 0x114($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X114);
    // 0x801B3358: lui         $a2, 0x3CF5
    ctx->r6 = S32(0X3CF5 << 16);
    // 0x801B335C: lwc1        $f16, 0x74($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0X74);
    // 0x801B3360: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x801B3364: ori         $a2, $a2, 0xC28F
    ctx->r6 = ctx->r6 | 0XC28F;
    // 0x801B3368: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801B336C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x801B3370: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x801B3374: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x801B3378: jal         0x8009BC2C
    // 0x801B337C: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_53;
    // 0x801B337C: nop

    after_53:
    // 0x801B3380: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x801B3384: lwc1        $f4, 0x118($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X118);
    // 0x801B3388: lwc1        $f10, 0x3C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x801B338C: lwc1        $f6, 0x78($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X78);
    // 0x801B3390: lui         $a2, 0x3CF5
    ctx->r6 = S32(0X3CF5 << 16);
    // 0x801B3394: ori         $a2, $a2, 0xC28F
    ctx->r6 = ctx->r6 | 0XC28F;
    // 0x801B3398: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801B339C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x801B33A0: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x801B33A4: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x801B33A8: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801B33AC: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x801B33B0: jal         0x8009BC2C
    // 0x801B33B4: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_54;
    // 0x801B33B4: nop

    after_54:
    // 0x801B33B8: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x801B33BC: lwc1        $f18, 0x11C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X11C);
    // 0x801B33C0: lui         $a2, 0x3CF5
    ctx->r6 = S32(0X3CF5 << 16);
    // 0x801B33C4: lwc1        $f4, 0x138($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X138);
    // 0x801B33C8: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x801B33CC: ori         $a2, $a2, 0xC28F
    ctx->r6 = ctx->r6 | 0XC28F;
    // 0x801B33D0: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x801B33D4: addiu       $a0, $s0, 0xC
    ctx->r4 = ADD32(ctx->r16, 0XC);
    // 0x801B33D8: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x801B33DC: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x801B33E0: jal         0x8009BC2C
    // 0x801B33E4: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_55;
    // 0x801B33E4: nop

    after_55:
    // 0x801B33E8: b           L_801B34B0
    // 0x801B33EC: nop

        goto L_801B34B0;
    // 0x801B33EC: nop

L_801B33F0:
    // 0x801B33F0: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x801B33F4: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x801B33F8: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x801B33FC: addiu       $t8, $t8, 0x5D3C
    ctx->r24 = ADD32(ctx->r24, 0X5D3C);
    // 0x801B3400: lui         $a0, 0x900
    ctx->r4 = S32(0X900 << 16);
    // 0x801B3404: ori         $a0, $a0, 0x2
    ctx->r4 = ctx->r4 | 0X2;
    // 0x801B3408: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x801B340C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x801B3410: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x801B3414: jal         0x80019218
    // 0x801B3418: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Audio_PlaySfx(rdram, ctx);
        goto after_56;
    // 0x801B3418: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_56:
    // 0x801B341C: lh          $t0, 0xB8($s0)
    ctx->r8 = MEM_H(ctx->r16, 0XB8);
    // 0x801B3420: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x801B3424: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801B3428: addiu       $t9, $zero, 0x14
    ctx->r25 = ADD32(0, 0X14);
    // 0x801B342C: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x801B3430: sb          $zero, 0xC9($s0)
    MEM_B(0XC9, ctx->r16) = 0;
    // 0x801B3434: sh          $t9, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r25;
    // 0x801B3438: sh          $t1, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r9;
    // 0x801B343C: swc1        $f8, 0x188($s0)
    MEM_W(0X188, ctx->r16) = ctx->f8.u32l;
L_801B3440:
    // 0x801B3440: lhu         $t2, 0xBC($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0XBC);
    // 0x801B3444: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x801B3448: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x801B344C: bgtz        $t2, L_801B345C
    if (SIGNED(ctx->r10) > 0) {
        // 0x801B3450: addiu       $a0, $s0, 0x10
        ctx->r4 = ADD32(ctx->r16, 0X10);
            goto L_801B345C;
    }
    // 0x801B3450: addiu       $a0, $s0, 0x10
    ctx->r4 = ADD32(ctx->r16, 0X10);
    // 0x801B3454: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x801B3458: sb          $t3, 0xC9($s0)
    MEM_B(0XC9, ctx->r16) = ctx->r11;
L_801B345C:
    // 0x801B345C: sw          $t4, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r12;
    // 0x801B3460: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x801B3464: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801B3468: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x801B346C: lui         $a1, 0xC1A0
    ctx->r5 = S32(0XC1A0 << 16);
    // 0x801B3470: jal         0x8009BC2C
    // 0x801B3474: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    Math_SmoothStepToF(rdram, ctx);
        goto after_57;
    // 0x801B3474: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    after_57:
    // 0x801B3478: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x801B347C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801B3480: addiu       $a0, $s0, 0x138
    ctx->r4 = ADD32(ctx->r16, 0X138);
    // 0x801B3484: lui         $a1, 0x41C8
    ctx->r5 = S32(0X41C8 << 16);
    // 0x801B3488: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x801B348C: jal         0x8009BC2C
    // 0x801B3490: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_58;
    // 0x801B3490: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_58:
    // 0x801B3494: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x801B3498: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x801B349C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801B34A0: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x801B34A4: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    // 0x801B34A8: jal         0x8009BC2C
    // 0x801B34AC: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_59;
    // 0x801B34AC: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_59:
L_801B34B0:
    // 0x801B34B0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B34B4: lwc1        $f16, -0x428C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X428C);
    // 0x801B34B8: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    // 0x801B34BC: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x801B34C0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801B34C4: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x801B34C8: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801B34CC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801B34D0: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x801B34D4: jal         0x80005E90
    // 0x801B34D8: nop

    Matrix_RotateY(rdram, ctx);
        goto after_60;
    // 0x801B34D8: nop

    after_60:
    // 0x801B34DC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B34E0: lwc1        $f6, -0x4288($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X4288);
    // 0x801B34E4: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x801B34E8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801B34EC: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801B34F0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x801B34F4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801B34F8: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x801B34FC: jal         0x80005D44
    // 0x801B3500: nop

    Matrix_RotateX(rdram, ctx);
        goto after_61;
    // 0x801B3500: nop

    after_61:
    // 0x801B3504: swc1        $f20, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f20.u32l;
    // 0x801B3508: swc1        $f20, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f20.u32l;
    // 0x801B350C: lwc1        $f10, 0x138($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X138);
    // 0x801B3510: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801B3514: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801B3518: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    // 0x801B351C: addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    // 0x801B3520: jal         0x80006A20
    // 0x801B3524: swc1        $f10, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f10.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_62;
    // 0x801B3524: swc1        $f10, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f10.u32l;
    after_62:
    // 0x801B3528: lwc1        $f16, 0x50($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X50);
    // 0x801B352C: swc1        $f16, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f16.u32l;
    // 0x801B3530: lwc1        $f18, 0x54($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X54);
    // 0x801B3534: swc1        $f18, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f18.u32l;
    // 0x801B3538: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
    // 0x801B353C: swc1        $f4, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f4.u32l;
    // 0x801B3540: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x801B3544: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x801B3548: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x801B354C: jr          $ra
    // 0x801B3550: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x801B3550: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void Titania_TiBoulder_Spawn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018A3F4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8018A3F8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8018A3FC: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8018A400: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x8018A404: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8018A408: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8018A40C: addiu       $v0, $v0, -0xEF0
    ctx->r2 = ADD32(ctx->r2, -0XEF0);
    // 0x8018A410: addiu       $a0, $a0, 0x3FE0
    ctx->r4 = ADD32(ctx->r4, 0X3FE0);
    // 0x8018A414: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
L_8018A418:
    // 0x8018A418: bnel        $t6, $zero, L_8018A45C
    if (ctx->r14 != 0) {
        // 0x8018A41C: addiu       $a0, $a0, 0x2F4
        ctx->r4 = ADD32(ctx->r4, 0X2F4);
            goto L_8018A45C;
    }
    goto skip_0;
    // 0x8018A41C: addiu       $a0, $a0, 0x2F4
    ctx->r4 = ADD32(ctx->r4, 0X2F4);
    skip_0:
    // 0x8018A420: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8018A424: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8018A428: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8018A42C: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8018A430: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x8018A434: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x8018A438: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8018A43C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8018A440: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x8018A444: jal         0x8018A2E8
    // 0x8018A448: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    Titania_TiBoulder_Setup(rdram, ctx);
        goto after_0;
    // 0x8018A448: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x8018A44C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8018A450: b           L_8018A464
    // 0x8018A454: sb          $zero, 0x34($a0)
    MEM_B(0X34, ctx->r4) = 0;
        goto L_8018A464;
    // 0x8018A454: sb          $zero, 0x34($a0)
    MEM_B(0X34, ctx->r4) = 0;
    // 0x8018A458: addiu       $a0, $a0, 0x2F4
    ctx->r4 = ADD32(ctx->r4, 0X2F4);
L_8018A45C:
    // 0x8018A45C: bnel        $a0, $v0, L_8018A418
    if (ctx->r4 != ctx->r2) {
        // 0x8018A460: lbu         $t6, 0x0($a0)
        ctx->r14 = MEM_BU(ctx->r4, 0X0);
            goto L_8018A418;
    }
    goto skip_1;
    // 0x8018A460: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    skip_1:
L_8018A464:
    // 0x8018A464: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8018A468: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8018A46C: jr          $ra
    // 0x8018A470: nop

    return;
    // 0x8018A470: nop

;}
RECOMP_FUNC void Titania_TiBomb_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018B9D0: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8018B9D4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8018B9D8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8018B9DC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8018B9E0: lh          $v0, 0xB8($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XB8);
    // 0x8018B9E4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8018B9E8: sb          $t6, 0xC9($s0)
    MEM_B(0XC9, ctx->r16) = ctx->r14;
    // 0x8018B9EC: beq         $v0, $zero, L_8018BA08
    if (ctx->r2 == 0) {
        // 0x8018B9F0: lui         $t0, 0x8018
        ctx->r8 = S32(0X8018 << 16);
            goto L_8018BA08;
    }
    // 0x8018B9F0: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8018B9F4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8018B9F8: beq         $v0, $at, L_8018BC10
    if (ctx->r2 == ctx->r1) {
        // 0x8018B9FC: addiu       $a2, $sp, 0x4C
        ctx->r6 = ADD32(ctx->r29, 0X4C);
            goto L_8018BC10;
    }
    // 0x8018B9FC: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    // 0x8018BA00: b           L_8018BC9C
    // 0x8018BA04: lwc1        $f2, 0xE8($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XE8);
        goto L_8018BC9C;
    // 0x8018BA04: lwc1        $f2, 0xE8($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XE8);
L_8018BA08:
    // 0x8018BA08: addiu       $t0, $t0, -0x7D80
    ctx->r8 = ADD32(ctx->r8, -0X7D80);
    // 0x8018BA0C: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x8018BA10: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8018BA14: lhu         $v1, 0xBE($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0XBE);
    // 0x8018BA18: lwc1        $f4, 0x74($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X74);
    // 0x8018BA1C: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8018BA20: lwc1        $f8, 0x78($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X78);
    // 0x8018BA24: sub.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8018BA28: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8018BA2C: lwc1        $f4, 0x7C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X7C);
    // 0x8018BA30: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8018BA34: sub.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8018BA38: bne         $v1, $at, L_8018BA90
    if (ctx->r3 != ctx->r1) {
        // 0x8018BA3C: sub.s       $f12, $f4, $f6
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
            goto L_8018BA90;
    }
    // 0x8018BA3C: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8018BA40: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8018BA44: sw          $t7, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r15;
    // 0x8018BA48: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8018BA4C: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x8018BA50: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8018BA54: addiu       $t8, $t8, 0x5D3C
    ctx->r24 = ADD32(ctx->r24, 0X5D3C);
    // 0x8018BA58: lui         $a0, 0x1900
    ctx->r4 = S32(0X1900 << 16);
    // 0x8018BA5C: ori         $a0, $a0, 0x32
    ctx->r4 = ctx->r4 | 0X32;
    // 0x8018BA60: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8018BA64: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8018BA68: swc1        $f12, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f12.u32l;
    // 0x8018BA6C: swc1        $f2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f2.u32l;
    // 0x8018BA70: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x8018BA74: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x8018BA78: jal         0x80019218
    // 0x8018BA7C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Audio_PlaySfx(rdram, ctx);
        goto after_0;
    // 0x8018BA7C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8018BA80: lwc1        $f0, 0x40($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8018BA84: lwc1        $f2, 0x44($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8018BA88: lwc1        $f12, 0x3C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8018BA8C: lhu         $v1, 0xBE($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0XBE);
L_8018BA90:
    // 0x8018BA90: bnel        $v1, $zero, L_8018BB50
    if (ctx->r3 != 0) {
        // 0x8018BA94: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8018BB50;
    }
    goto skip_0;
    // 0x8018BA94: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    skip_0:
    // 0x8018BA98: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8018BA9C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018BAA0: addiu       $t9, $zero, 0x8
    ctx->r25 = ADD32(0, 0X8);
    // 0x8018BAA4: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8018BAA8: andi        $v1, $t9, 0xFFFF
    ctx->r3 = ctx->r25 & 0XFFFF;
    // 0x8018BAAC: mul.s       $f6, $f12, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x8018BAB0: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8018BAB4: lwc1        $f8, -0x53D4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X53D4);
    // 0x8018BAB8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018BABC: add.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8018BAC0: c.lt.s      $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f14.fl < ctx->f8.fl;
    // 0x8018BAC4: nop

    // 0x8018BAC8: bc1f        L_8018BAD8
    if (!c1cs) {
        // 0x8018BACC: nop
    
            goto L_8018BAD8;
    }
    // 0x8018BACC: nop

    // 0x8018BAD0: b           L_8018BB4C
    // 0x8018BAD4: sh          $t9, 0xBE($s0)
    MEM_H(0XBE, ctx->r16) = ctx->r25;
        goto L_8018BB4C;
    // 0x8018BAD4: sh          $t9, 0xBE($s0)
    MEM_H(0XBE, ctx->r16) = ctx->r25;
L_8018BAD8:
    // 0x8018BAD8: lwc1        $f10, -0x53D0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X53D0);
    // 0x8018BADC: c.lt.s      $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f14.fl < ctx->f10.fl;
    // 0x8018BAE0: nop

    // 0x8018BAE4: bc1fl       L_8018BB48
    if (!c1cs) {
        // 0x8018BAE8: sw          $zero, 0x50($s0)
        MEM_W(0X50, ctx->r16) = 0;
            goto L_8018BB48;
    }
    goto skip_1;
    // 0x8018BAE8: sw          $zero, 0x50($s0)
    MEM_W(0X50, ctx->r16) = 0;
    skip_1:
    // 0x8018BAEC: lhu         $t1, 0xBC($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0XBC);
    // 0x8018BAF0: lui         $a0, 0x1900
    ctx->r4 = S32(0X1900 << 16);
    // 0x8018BAF4: sh          $zero, 0xBE($s0)
    MEM_H(0XBE, ctx->r16) = 0;
    // 0x8018BAF8: bne         $t1, $zero, L_8018BB3C
    if (ctx->r9 != 0) {
        // 0x8018BAFC: ori         $a0, $a0, 0x29
        ctx->r4 = ctx->r4 | 0X29;
            goto L_8018BB3C;
    }
    // 0x8018BAFC: ori         $a0, $a0, 0x29
    ctx->r4 = ctx->r4 | 0X29;
    // 0x8018BB00: lui         $t2, 0x800C
    ctx->r10 = S32(0X800C << 16);
    // 0x8018BB04: lui         $t3, 0x800C
    ctx->r11 = S32(0X800C << 16);
    // 0x8018BB08: addiu       $t3, $t3, 0x5D3C
    ctx->r11 = ADD32(ctx->r11, 0X5D3C);
    // 0x8018BB0C: addiu       $a3, $t2, 0x5D34
    ctx->r7 = ADD32(ctx->r10, 0X5D34);
    // 0x8018BB10: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8018BB14: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x8018BB18: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x8018BB1C: jal         0x80019218
    // 0x8018BB20: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_1;
    // 0x8018BB20: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_1:
    // 0x8018BB24: lw          $t4, 0x50($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X50);
    // 0x8018BB28: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8018BB2C: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x8018BB30: subu        $t6, $t5, $t4
    ctx->r14 = SUB32(ctx->r13, ctx->r12);
    // 0x8018BB34: sw          $t6, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r14;
    // 0x8018BB38: sh          $t7, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r15;
L_8018BB3C:
    // 0x8018BB3C: b           L_8018BB4C
    // 0x8018BB40: lhu         $v1, 0xBE($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0XBE);
        goto L_8018BB4C;
    // 0x8018BB40: lhu         $v1, 0xBE($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0XBE);
    // 0x8018BB44: sw          $zero, 0x50($s0)
    MEM_W(0X50, ctx->r16) = 0;
L_8018BB48:
    // 0x8018BB48: lhu         $v1, 0xBE($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0XBE);
L_8018BB4C:
    // 0x8018BB4C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_8018BB50:
    // 0x8018BB50: bne         $v1, $at, L_8018BC98
    if (ctx->r3 != ctx->r1) {
        // 0x8018BB54: lui         $a3, 0x4120
        ctx->r7 = S32(0X4120 << 16);
            goto L_8018BC98;
    }
    // 0x8018BB54: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x8018BB58: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8018BB5C: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8018BB60: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x8018BB64: addiu       $t8, $s0, 0x100
    ctx->r24 = ADD32(ctx->r16, 0X100);
    // 0x8018BB68: jal         0x8007D2C8
    // 0x8018BB6C: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    Effect_FireSmoke1_Spawn3(rdram, ctx);
        goto after_2;
    // 0x8018BB6C: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    after_2:
    // 0x8018BB70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018BB74: jal         0x80060FBC
    // 0x8018BB78: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    Object_Kill(rdram, ctx);
        goto after_3;
    // 0x8018BB78: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_3:
    // 0x8018BB7C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8018BB80: addiu       $t0, $t0, -0x7D80
    ctx->r8 = ADD32(ctx->r8, -0X7D80);
    // 0x8018BB84: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x8018BB88: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018BB8C: jal         0x800A6CD0
    // 0x8018BB90: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    Player_ApplyDamage(rdram, ctx);
        goto after_4;
    // 0x8018BB90: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    after_4:
    // 0x8018BB94: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8018BB98: addiu       $t0, $t0, -0x7D80
    ctx->r8 = ADD32(ctx->r8, -0X7D80);
    // 0x8018BB9C: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8018BBA0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018BBA4: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x8018BBA8: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x8018BBAC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018BBB0: swc1        $f4, 0xC4($t9)
    MEM_W(0XC4, ctx->r25) = ctx->f4.u32l;
    // 0x8018BBB4: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x8018BBB8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8018BBBC: addiu       $t3, $zero, 0xF
    ctx->r11 = ADD32(0, 0XF);
    // 0x8018BBC0: lwc1        $f6, 0x78($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X78);
    // 0x8018BBC4: addiu       $t4, $zero, 0x14
    ctx->r12 = ADD32(0, 0X14);
    // 0x8018BBC8: addiu       $t7, $zero, -0x14
    ctx->r15 = ADD32(0, -0X14);
    // 0x8018BBCC: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8018BBD0: swc1        $f10, 0x78($v0)
    MEM_W(0X78, ctx->r2) = ctx->f10.u32l;
    // 0x8018BBD4: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x8018BBD8: sw          $t1, 0x1DC($t2)
    MEM_W(0X1DC, ctx->r10) = ctx->r9;
    // 0x8018BBDC: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x8018BBE0: sw          $t3, 0x1E8($t5)
    MEM_W(0X1E8, ctx->r13) = ctx->r11;
    // 0x8018BBE4: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x8018BBE8: sw          $t4, 0x1EC($t6)
    MEM_W(0X1EC, ctx->r14) = ctx->r12;
    // 0x8018BBEC: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x8018BBF0: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8018BBF4: lwc1        $f6, 0x74($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X74);
    // 0x8018BBF8: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8018BBFC: nop

    // 0x8018BC00: bc1fl       L_8018BC9C
    if (!c1cs) {
        // 0x8018BC04: lwc1        $f2, 0xE8($s0)
        ctx->f2.u32l = MEM_W(ctx->r16, 0XE8);
            goto L_8018BC9C;
    }
    goto skip_2;
    // 0x8018BC04: lwc1        $f2, 0xE8($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XE8);
    skip_2:
    // 0x8018BC08: b           L_8018BC98
    // 0x8018BC0C: sw          $t7, 0x1EC($v0)
    MEM_W(0X1EC, ctx->r2) = ctx->r15;
        goto L_8018BC98;
    // 0x8018BC0C: sw          $t7, 0x1EC($v0)
    MEM_W(0X1EC, ctx->r2) = ctx->r15;
L_8018BC10:
    // 0x8018BC10: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018BC14: lwc1        $f10, 0x7D20($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x8018BC18: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8018BC1C: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8018BC20: addiu       $t8, $sp, 0x48
    ctx->r24 = ADD32(ctx->r29, 0X48);
    // 0x8018BC24: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8018BC28: addiu       $a3, $sp, 0x50
    ctx->r7 = ADD32(ctx->r29, 0X50);
    // 0x8018BC2C: jal         0x801B6E20
    // 0x8018BC30: add.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f10.fl;
    Ground_801B6E20(rdram, ctx);
        goto after_5;
    // 0x8018BC30: add.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f10.fl;
    after_5:
    // 0x8018BC34: lwc1        $f4, 0x50($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8018BC38: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8018BC3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018BC40: swc1        $f4, 0x114($s0)
    MEM_W(0X114, ctx->r16) = ctx->f4.u32l;
    // 0x8018BC44: lwc1        $f4, 0xEC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x8018BC48: lwc1        $f6, 0x4C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8018BC4C: c.le.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl <= ctx->f10.fl;
    // 0x8018BC50: swc1        $f6, 0x118($s0)
    MEM_W(0X118, ctx->r16) = ctx->f6.u32l;
    // 0x8018BC54: lwc1        $f8, 0x48($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8018BC58: bc1f        L_8018BC98
    if (!c1cs) {
        // 0x8018BC5C: swc1        $f8, 0x11C($s0)
        MEM_W(0X11C, ctx->r16) = ctx->f8.u32l;
            goto L_8018BC98;
    }
    // 0x8018BC5C: swc1        $f8, 0x11C($s0)
    MEM_W(0X11C, ctx->r16) = ctx->f8.u32l;
    // 0x8018BC60: jal         0x80066254
    // 0x8018BC64: sb          $zero, 0x44($s0)
    MEM_B(0X44, ctx->r16) = 0;
    Actor_Despawn(rdram, ctx);
        goto after_6;
    // 0x8018BC64: sb          $zero, 0x44($s0)
    MEM_B(0X44, ctx->r16) = 0;
    after_6:
    // 0x8018BC68: lui         $a1, 0x2903
    ctx->r5 = S32(0X2903 << 16);
    // 0x8018BC6C: ori         $a1, $a1, 0xB009
    ctx->r5 = ctx->r5 | 0XB009;
    // 0x8018BC70: jal         0x8007A6F0
    // 0x8018BC74: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    Effect_TimedSfx_Spawn(rdram, ctx);
        goto after_7;
    // 0x8018BC74: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    after_7:
    // 0x8018BC78: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8018BC7C: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8018BC80: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x8018BC84: jal         0x8007D2C8
    // 0x8018BC88: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    Effect_FireSmoke1_Spawn3(rdram, ctx);
        goto after_8;
    // 0x8018BC88: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    after_8:
    // 0x8018BC8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018BC90: jal         0x80060FBC
    // 0x8018BC94: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    Object_Kill(rdram, ctx);
        goto after_9;
    // 0x8018BC94: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    after_9:
L_8018BC98:
    // 0x8018BC98: lwc1        $f2, 0xE8($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XE8);
L_8018BC9C:
    // 0x8018BC9C: lui         $at, 0x4302
    ctx->r1 = S32(0X4302 << 16);
    // 0x8018BCA0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8018BCA4: abs.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = fabsf(ctx->f2.fl);
    // 0x8018BCA8: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8018BCAC: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x8018BCB0: lui         $a0, 0x1902
    ctx->r4 = S32(0X1902 << 16);
    // 0x8018BCB4: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8018BCB8: ori         $a0, $a0, 0x8
    ctx->r4 = ctx->r4 | 0X8;
    // 0x8018BCBC: bc1f        L_8018BD28
    if (!c1cs) {
        // 0x8018BCC0: addiu       $a1, $s0, 0x100
        ctx->r5 = ADD32(ctx->r16, 0X100);
            goto L_8018BD28;
    }
    // 0x8018BCC0: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x8018BCC4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8018BCC8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8018BCCC: c.lt.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl < ctx->f2.fl;
    // 0x8018BCD0: nop

    // 0x8018BCD4: bc1fl       L_8018BCF8
    if (!c1cs) {
        // 0x8018BCD8: c.eq.s      $f16, $f2
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl == ctx->f2.fl;
            goto L_8018BCF8;
    }
    goto skip_3;
    // 0x8018BCD8: c.eq.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl == ctx->f2.fl;
    skip_3:
    // 0x8018BCDC: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x8018BCE0: nop

    // 0x8018BCE4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8018BCE8: mul.s       $f12, $f8, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x8018BCEC: b           L_8018BD34
    // 0x8018BCF0: neg.s       $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = -ctx->f12.fl;
        goto L_8018BD34;
    // 0x8018BCF0: neg.s       $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = -ctx->f12.fl;
    // 0x8018BCF4: c.eq.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl == ctx->f2.fl;
L_8018BCF8:
    // 0x8018BCF8: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x8018BCFC: bc1f        L_8018BD0C
    if (!c1cs) {
        // 0x8018BD00: nop
    
            goto L_8018BD0C;
    }
    // 0x8018BD00: nop

    // 0x8018BD04: b           L_8018BD0C
    // 0x8018BD08: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_8018BD0C;
    // 0x8018BD08: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8018BD0C:
    // 0x8018BD0C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8018BD10: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x8018BD14: nop

    // 0x8018BD18: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8018BD1C: mul.s       $f12, $f8, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x8018BD20: b           L_8018BD34
    // 0x8018BD24: neg.s       $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = -ctx->f12.fl;
        goto L_8018BD34;
    // 0x8018BD24: neg.s       $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = -ctx->f12.fl;
L_8018BD28:
    // 0x8018BD28: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8018BD2C: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
    // 0x8018BD30: neg.s       $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = -ctx->f12.fl;
L_8018BD34:
    // 0x8018BD34: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8018BD38: div.s       $f4, $f10, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = DIV_S(ctx->f10.fl, ctx->f14.fl);
    // 0x8018BD3C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8018BD40: lwc1        $f2, 0xF0($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XF0);
    // 0x8018BD44: lui         $t1, 0x800C
    ctx->r9 = S32(0X800C << 16);
    // 0x8018BD48: addiu       $t1, $t1, 0x5D3C
    ctx->r9 = ADD32(ctx->r9, 0X5D3C);
    // 0x8018BD4C: abs.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = fabsf(ctx->f2.fl);
    // 0x8018BD50: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8018BD54: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x8018BD58: mul.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x8018BD5C: bc1f        L_8018BDC0
    if (!c1cs) {
        // 0x8018BD60: swc1        $f6, 0x18($s0)
        MEM_W(0X18, ctx->r16) = ctx->f6.u32l;
            goto L_8018BDC0;
    }
    // 0x8018BD60: swc1        $f6, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f6.u32l;
    // 0x8018BD64: c.lt.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl < ctx->f2.fl;
    // 0x8018BD68: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8018BD6C: bc1fl       L_8018BD90
    if (!c1cs) {
        // 0x8018BD70: c.eq.s      $f16, $f2
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl == ctx->f2.fl;
            goto L_8018BD90;
    }
    goto skip_4;
    // 0x8018BD70: c.eq.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl == ctx->f2.fl;
    skip_4:
    // 0x8018BD74: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x8018BD78: nop

    // 0x8018BD7C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8018BD80: mul.s       $f12, $f10, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x8018BD84: b           L_8018BDC8
    // 0x8018BD88: div.s       $f4, $f12, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = DIV_S(ctx->f12.fl, ctx->f14.fl);
        goto L_8018BDC8;
    // 0x8018BD88: div.s       $f4, $f12, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = DIV_S(ctx->f12.fl, ctx->f14.fl);
    // 0x8018BD8C: c.eq.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl == ctx->f2.fl;
L_8018BD90:
    // 0x8018BD90: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x8018BD94: bc1f        L_8018BDA4
    if (!c1cs) {
        // 0x8018BD98: nop
    
            goto L_8018BDA4;
    }
    // 0x8018BD98: nop

    // 0x8018BD9C: b           L_8018BDA4
    // 0x8018BDA0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_8018BDA4;
    // 0x8018BDA0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8018BDA4:
    // 0x8018BDA4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8018BDA8: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x8018BDAC: nop

    // 0x8018BDB0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8018BDB4: mul.s       $f12, $f10, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x8018BDB8: b           L_8018BDC8
    // 0x8018BDBC: div.s       $f4, $f12, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = DIV_S(ctx->f12.fl, ctx->f14.fl);
        goto L_8018BDC8;
    // 0x8018BDBC: div.s       $f4, $f12, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = DIV_S(ctx->f12.fl, ctx->f14.fl);
L_8018BDC0:
    // 0x8018BDC0: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
    // 0x8018BDC4: div.s       $f4, $f12, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = DIV_S(ctx->f12.fl, ctx->f14.fl);
L_8018BDC8:
    // 0x8018BDC8: lb          $t9, 0xD0($s0)
    ctx->r25 = MEM_B(ctx->r16, 0XD0);
    // 0x8018BDCC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8018BDD0: mul.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x8018BDD4: bne         $t9, $at, L_8018BE70
    if (ctx->r25 != ctx->r1) {
        // 0x8018BDD8: swc1        $f6, 0x10($s0)
        MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
            goto L_8018BE70;
    }
    // 0x8018BDD8: swc1        $f6, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
    // 0x8018BDDC: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8018BDE0: jal         0x80019218
    // 0x8018BDE4: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    Audio_PlaySfx(rdram, ctx);
        goto after_10;
    // 0x8018BDE4: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    after_10:
    // 0x8018BDE8: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8018BDEC: lwc1        $f10, 0xD8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XD8);
    // 0x8018BDF0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018BDF4: lwc1        $f12, -0x53CC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X53CC);
    // 0x8018BDF8: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8018BDFC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8018BE00: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018BE04: lwc1        $f4, 0xE8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XE8);
    // 0x8018BE08: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x8018BE0C: mul.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x8018BE10: abs.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = fabsf(ctx->f2.fl);
    // 0x8018BE14: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8018BE18: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
    // 0x8018BE1C: sh          $t2, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r10;
    // 0x8018BE20: sh          $zero, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = 0;
    // 0x8018BE24: sh          $zero, 0xBE($s0)
    MEM_H(0XBE, ctx->r16) = 0;
    // 0x8018BE28: mul.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x8018BE2C: lwc1        $f8, 0xF0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XF0);
    // 0x8018BE30: sw          $zero, 0x50($s0)
    MEM_W(0X50, ctx->r16) = 0;
    // 0x8018BE34: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8018BE38: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018BE3C: lui         $at, 0x4208
    ctx->r1 = S32(0X4208 << 16);
    // 0x8018BE40: sub.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x8018BE44: swc1        $f6, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f6.u32l;
    // 0x8018BE48: mul.s       $f6, $f10, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x8018BE4C: lwc1        $f10, 0xEC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x8018BE50: sub.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x8018BE54: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018BE58: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8018BE5C: add.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8018BE60: swc1        $f4, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f4.u32l;
    // 0x8018BE64: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018BE68: swc1        $f6, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f6.u32l;
    // 0x8018BE6C: swc1        $f4, 0x10C($s0)
    MEM_W(0X10C, ctx->r16) = ctx->f4.u32l;
L_8018BE70:
    // 0x8018BE70: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8018BE74: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8018BE78: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x8018BE7C: jr          $ra
    // 0x8018BE80: nop

    return;
    // 0x8018BE80: nop

;}
RECOMP_FUNC void Macbeth_801A0B00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A0B00: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x801A0B04: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x801A0B08: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801A0B0C: bne         $a0, $at, L_801A0B18
    if (ctx->r4 != ctx->r1) {
        // 0x801A0B10: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801A0B18;
    }
    // 0x801A0B10: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801A0B14: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
L_801A0B18:
    // 0x801A0B18: jr          $ra
    // 0x801A0B1C: nop

    return;
    // 0x801A0B1C: nop

;}
RECOMP_FUNC void Macbeth_801A67BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A67BC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801A67C0: jr          $ra
    // 0x801A67C4: nop

    return;
    // 0x801A67C4: nop

;}
RECOMP_FUNC void Macbeth_MaBombDrop_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801ADAC8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801ADACC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801ADAD0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801ADAD4: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x801ADAD8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801ADADC: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x801ADAE0: lh          $v0, 0xB8($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XB8);
    // 0x801ADAE4: beq         $v0, $zero, L_801ADAFC
    if (ctx->r2 == 0) {
        // 0x801ADAE8: nop
    
            goto L_801ADAFC;
    }
    // 0x801ADAE8: nop

    // 0x801ADAEC: beq         $v0, $at, L_801ADB78
    if (ctx->r2 == ctx->r1) {
        // 0x801ADAF0: lui         $a0, 0x8014
        ctx->r4 = S32(0X8014 << 16);
            goto L_801ADB78;
    }
    // 0x801ADAF0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801ADAF4: b           L_801ADBFC
    // 0x801ADAF8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801ADBFC;
    // 0x801ADAF8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801ADAFC:
    // 0x801ADAFC: jal         0x8005980C
    // 0x801ADB00: lwc1        $f12, 0x110($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0X110);
    Graphics_SetScaleMtx(rdram, ctx);
        goto after_0;
    // 0x801ADB00: lwc1        $f12, 0x110($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0X110);
    after_0:
    // 0x801ADB04: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x801ADB08: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x801ADB0C: lw          $t9, -0x7C24($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7C24);
    // 0x801ADB10: lw          $t8, -0x7C28($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7C28);
    // 0x801ADB14: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x801ADB18: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x801ADB1C: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x801ADB20: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x801ADB24: lw          $a3, -0x7CC8($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X7CC8);
    // 0x801ADB28: lw          $a2, -0x7CD0($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7CD0);
    // 0x801ADB2C: lw          $a1, -0x7CD8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7CD8);
    // 0x801ADB30: lw          $a0, -0x7CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7CE0);
    // 0x801ADB34: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x801ADB38: jal         0x800B9B38
    // 0x801ADB3C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    RCP_SetupDL_60(rdram, ctx);
        goto after_1;
    // 0x801ADB3C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_1:
    // 0x801ADB40: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801ADB44: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x801ADB48: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x801ADB4C: lui         $t2, 0x401
    ctx->r10 = S32(0X401 << 16);
    // 0x801ADB50: addiu       $t2, $t2, -0x7320
    ctx->r10 = ADD32(ctx->r10, -0X7320);
    // 0x801ADB54: addiu       $t0, $v0, 0x8
    ctx->r8 = ADD32(ctx->r2, 0X8);
    // 0x801ADB58: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
    // 0x801ADB5C: lui         $t1, 0x600
    ctx->r9 = S32(0X600 << 16);
    // 0x801ADB60: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x801ADB64: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x801ADB68: jal         0x800B8DD0
    // 0x801ADB6C: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    RCP_SetupDL(rdram, ctx);
        goto after_2;
    // 0x801ADB6C: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_2:
    // 0x801ADB70: b           L_801ADBFC
    // 0x801ADB74: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801ADBFC;
    // 0x801ADB74: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801ADB78:
    // 0x801ADB78: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x801ADB7C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801ADB80: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x801ADB84: lw          $a1, 0x114($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X114);
    // 0x801ADB88: lw          $a2, 0x110($t3)
    ctx->r6 = MEM_W(ctx->r11, 0X110);
    // 0x801ADB8C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x801ADB90: jal         0x80005C34
    // 0x801ADB94: lui         $a3, 0x4020
    ctx->r7 = S32(0X4020 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_3;
    // 0x801ADB94: lui         $a3, 0x4020
    ctx->r7 = S32(0X4020 << 16);
    after_3:
    // 0x801ADB98: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801ADB9C: jal         0x80006EB8
    // 0x801ADBA0: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_4;
    // 0x801ADBA0: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    after_4:
    // 0x801ADBA4: jal         0x800B99C0
    // 0x801ADBA8: nop

    RCP_SetupDL_40(rdram, ctx);
        goto after_5;
    // 0x801ADBA8: nop

    after_5:
    // 0x801ADBAC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801ADBB0: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x801ADBB4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x801ADBB8: lui         $t6, 0xB600
    ctx->r14 = S32(0XB600 << 16);
    // 0x801ADBBC: addiu       $t7, $zero, 0x2000
    ctx->r15 = ADD32(0, 0X2000);
    // 0x801ADBC0: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x801ADBC4: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x801ADBC8: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x801ADBCC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x801ADBD0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x801ADBD4: lui         $t0, 0x401
    ctx->r8 = S32(0X401 << 16);
    // 0x801ADBD8: addiu       $t0, $t0, -0x7090
    ctx->r8 = ADD32(ctx->r8, -0X7090);
    // 0x801ADBDC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x801ADBE0: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x801ADBE4: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x801ADBE8: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x801ADBEC: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x801ADBF0: jal         0x800B8DD0
    // 0x801ADBF4: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    RCP_SetupDL(rdram, ctx);
        goto after_6;
    // 0x801ADBF4: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_6:
    // 0x801ADBF8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801ADBFC:
    // 0x801ADBFC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801ADC00: jr          $ra
    // 0x801ADC04: nop

    return;
    // 0x801ADC04: nop

;}
RECOMP_FUNC void Macbeth_MaBarrier_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A6144: addiu       $sp, $sp, -0xC0
    ctx->r29 = ADD32(ctx->r29, -0XC0);
    // 0x801A6148: sw          $s1, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r17;
    // 0x801A614C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x801A6150: sw          $ra, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r31;
    // 0x801A6154: sw          $s0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r16;
    // 0x801A6158: sdc1        $f30, 0x68($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X68, ctx->r29);
    // 0x801A615C: sdc1        $f28, 0x60($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X60, ctx->r29);
    // 0x801A6160: sdc1        $f26, 0x58($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X58, ctx->r29);
    // 0x801A6164: sdc1        $f24, 0x50($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X50, ctx->r29);
    // 0x801A6168: sdc1        $f22, 0x48($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X48, ctx->r29);
    // 0x801A616C: sdc1        $f20, 0x40($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X40, ctx->r29);
    // 0x801A6170: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x801A6174: lw          $t6, -0x7D80($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7D80);
    // 0x801A6178: lwc1        $f6, 0xC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XC);
    // 0x801A617C: lui         $at, 0xC3FA
    ctx->r1 = S32(0XC3FA << 16);
    // 0x801A6180: lwc1        $f4, 0x138($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X138);
    // 0x801A6184: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801A6188: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801A618C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801A6190: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x801A6194: nop

    // 0x801A6198: bc1fl       L_801A61AC
    if (!c1cs) {
        // 0x801A619C: lh          $v0, 0xB8($s1)
        ctx->r2 = MEM_H(ctx->r17, 0XB8);
            goto L_801A61AC;
    }
    goto skip_0;
    // 0x801A619C: lh          $v0, 0xB8($s1)
    ctx->r2 = MEM_H(ctx->r17, 0XB8);
    skip_0:
    // 0x801A61A0: jal         0x80060FBC
    // 0x801A61A4: addiu       $a1, $s1, 0x100
    ctx->r5 = ADD32(ctx->r17, 0X100);
    Object_Kill(rdram, ctx);
        goto after_0;
    // 0x801A61A4: addiu       $a1, $s1, 0x100
    ctx->r5 = ADD32(ctx->r17, 0X100);
    after_0:
    // 0x801A61A8: lh          $v0, 0xB8($s1)
    ctx->r2 = MEM_H(ctx->r17, 0XB8);
L_801A61AC:
    // 0x801A61AC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801A61B0: beql        $v0, $zero, L_801A61CC
    if (ctx->r2 == 0) {
        // 0x801A61B4: lb          $t7, 0xD0($s1)
        ctx->r15 = MEM_B(ctx->r17, 0XD0);
            goto L_801A61CC;
    }
    goto skip_1;
    // 0x801A61B4: lb          $t7, 0xD0($s1)
    ctx->r15 = MEM_B(ctx->r17, 0XD0);
    skip_1:
    // 0x801A61B8: beq         $v0, $at, L_801A64D8
    if (ctx->r2 == ctx->r1) {
        // 0x801A61BC: addiu       $a0, $s1, 0x10
        ctx->r4 = ADD32(ctx->r17, 0X10);
            goto L_801A64D8;
    }
    // 0x801A61BC: addiu       $a0, $s1, 0x10
    ctx->r4 = ADD32(ctx->r17, 0X10);
    // 0x801A61C0: b           L_801A6518
    // 0x801A61C4: lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X7C);
        goto L_801A6518;
    // 0x801A61C4: lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X7C);
    // 0x801A61C8: lb          $t7, 0xD0($s1)
    ctx->r15 = MEM_B(ctx->r17, 0XD0);
L_801A61CC:
    // 0x801A61CC: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x801A61D0: addiu       $t8, $zero, 0x14
    ctx->r24 = ADD32(0, 0X14);
    // 0x801A61D4: beq         $t7, $zero, L_801A6514
    if (ctx->r15 == 0) {
        // 0x801A61D8: addiu       $t9, $s1, 0x100
        ctx->r25 = ADD32(ctx->r17, 0X100);
            goto L_801A6514;
    }
    // 0x801A61D8: addiu       $t9, $s1, 0x100
    ctx->r25 = ADD32(ctx->r17, 0X100);
    // 0x801A61DC: lwc1        $f6, 0xEC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XEC);
    // 0x801A61E0: lwc1        $f4, 0x8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X8);
    // 0x801A61E4: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x801A61E8: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    // 0x801A61EC: lw          $a3, 0xE8($s1)
    ctx->r7 = MEM_W(ctx->r17, 0XE8);
    // 0x801A61F0: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x801A61F4: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x801A61F8: lwc1        $f8, 0xF0($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XF0);
    // 0x801A61FC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801A6200: lwc1        $f10, -0x493C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X493C);
    // 0x801A6204: sw          $t9, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r25;
    // 0x801A6208: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x801A620C: add.s       $f14, $f4, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f24.fl;
    // 0x801A6210: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x801A6214: jal         0x8007C120
    // 0x801A6218: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    Effect_Effect390_Spawn(rdram, ctx);
        goto after_1;
    // 0x801A6218: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x801A621C: lui         $s0, 0x800C
    ctx->r16 = S32(0X800C << 16);
    // 0x801A6220: lui         $t0, 0x800C
    ctx->r8 = S32(0X800C << 16);
    // 0x801A6224: addiu       $s0, $s0, 0x5D34
    ctx->r16 = ADD32(ctx->r16, 0X5D34);
    // 0x801A6228: addiu       $t0, $t0, 0x5D3C
    ctx->r8 = ADD32(ctx->r8, 0X5D3C);
    // 0x801A622C: lui         $a0, 0x2903
    ctx->r4 = S32(0X2903 << 16);
    // 0x801A6230: ori         $a0, $a0, 0x300E
    ctx->r4 = ctx->r4 | 0X300E;
    // 0x801A6234: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x801A6238: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x801A623C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x801A6240: lw          $a1, 0x80($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X80);
    // 0x801A6244: jal         0x80019218
    // 0x801A6248: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_2;
    // 0x801A6248: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_2:
    // 0x801A624C: lh          $t1, 0xCE($s1)
    ctx->r9 = MEM_H(ctx->r17, 0XCE);
    // 0x801A6250: lhu         $t2, 0xD6($s1)
    ctx->r10 = MEM_HU(ctx->r17, 0XD6);
    // 0x801A6254: addiu       $t4, $zero, 0xF
    ctx->r12 = ADD32(0, 0XF);
    // 0x801A6258: sh          $t4, 0xC6($s1)
    MEM_H(0XC6, ctx->r17) = ctx->r12;
    // 0x801A625C: subu        $t3, $t1, $t2
    ctx->r11 = SUB32(ctx->r9, ctx->r10);
    // 0x801A6260: sh          $t3, 0xCE($s1)
    MEM_H(0XCE, ctx->r17) = ctx->r11;
    // 0x801A6264: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x801A6268: lw          $t5, -0x7D80($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X7D80);
    // 0x801A626C: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x801A6270: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801A6274: lwc1        $f4, 0x138($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X138);
    // 0x801A6278: lwc1        $f10, 0xC($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XC);
    // 0x801A627C: lui         $a0, 0x2903
    ctx->r4 = S32(0X2903 << 16);
    // 0x801A6280: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801A6284: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x801A6288: addiu       $t7, $t7, 0x5D3C
    ctx->r15 = ADD32(ctx->r15, 0X5D3C);
    // 0x801A628C: ori         $a0, $a0, 0xB009
    ctx->r4 = ctx->r4 | 0XB009;
    // 0x801A6290: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x801A6294: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801A6298: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x801A629C: bc1fl       L_801A62AC
    if (!c1cs) {
        // 0x801A62A0: lh          $t6, 0xCE($s1)
        ctx->r14 = MEM_H(ctx->r17, 0XCE);
            goto L_801A62AC;
    }
    goto skip_2;
    // 0x801A62A0: lh          $t6, 0xCE($s1)
    ctx->r14 = MEM_H(ctx->r17, 0XCE);
    skip_2:
    // 0x801A62A4: sh          $zero, 0xCE($s1)
    MEM_H(0XCE, ctx->r17) = 0;
    // 0x801A62A8: lh          $t6, 0xCE($s1)
    ctx->r14 = MEM_H(ctx->r17, 0XCE);
L_801A62AC:
    // 0x801A62AC: lw          $a1, 0x80($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X80);
    // 0x801A62B0: bgtz        $t6, L_801A64D0
    if (SIGNED(ctx->r14) > 0) {
        // 0x801A62B4: nop
    
            goto L_801A64D0;
    }
    // 0x801A62B4: nop

    // 0x801A62B8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x801A62BC: jal         0x80019218
    // 0x801A62C0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    Audio_PlaySfx(rdram, ctx);
        goto after_3;
    // 0x801A62C0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_3:
    // 0x801A62C4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801A62C8: lwc1        $f4, 0x8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X8);
    // 0x801A62CC: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x801A62D0: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    // 0x801A62D4: lui         $at, 0x4160
    ctx->r1 = S32(0X4160 << 16);
    // 0x801A62D8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801A62DC: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x801A62E0: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x801A62E4: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x801A62E8: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x801A62EC: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x801A62F0: add.s       $f14, $f4, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f24.fl;
    // 0x801A62F4: jal         0x8007BFFC
    // 0x801A62F8: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    Effect_Effect386_Spawn1(rdram, ctx);
        goto after_4;
    // 0x801A62F8: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    after_4:
    // 0x801A62FC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801A6300: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x801A6304: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_801A6308:
    // 0x801A6308: jal         0x80004EB0
    // 0x801A630C: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_5;
    // 0x801A630C: nop

    after_5:
    // 0x801A6310: jal         0x80004EB0
    // 0x801A6314: swc1        $f0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_6;
    // 0x801A6314: swc1        $f0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f0.u32l;
    after_6:
    // 0x801A6318: jal         0x80004EB0
    // 0x801A631C: swc1        $f0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_7;
    // 0x801A631C: swc1        $f0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f0.u32l;
    after_7:
    // 0x801A6320: jal         0x80004EB0
    // 0x801A6324: swc1        $f0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_8;
    // 0x801A6324: swc1        $f0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f0.u32l;
    after_8:
    // 0x801A6328: jal         0x80004EB0
    // 0x801A632C: swc1        $f0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_9;
    // 0x801A632C: swc1        $f0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f0.u32l;
    after_9:
    // 0x801A6330: jal         0x80004EB0
    // 0x801A6334: mov.s       $f30, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    ctx->f30.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_10;
    // 0x801A6334: mov.s       $f30, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    ctx->f30.fl = ctx->f0.fl;
    after_10:
    // 0x801A6338: jal         0x80004EB0
    // 0x801A633C: swc1        $f0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_11;
    // 0x801A633C: swc1        $f0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f0.u32l;
    after_11:
    // 0x801A6340: jal         0x80004EB0
    // 0x801A6344: swc1        $f0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_12;
    // 0x801A6344: swc1        $f0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f0.u32l;
    after_12:
    // 0x801A6348: jal         0x80004EB0
    // 0x801A634C: swc1        $f0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_13;
    // 0x801A634C: swc1        $f0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f0.u32l;
    after_13:
    // 0x801A6350: jal         0x80004EB0
    // 0x801A6354: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_14;
    // 0x801A6354: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    after_14:
    // 0x801A6358: jal         0x80004EB0
    // 0x801A635C: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_15;
    // 0x801A635C: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    after_15:
    // 0x801A6360: jal         0x80004EB0
    // 0x801A6364: mov.s       $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    ctx->f26.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_16;
    // 0x801A6364: mov.s       $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    ctx->f26.fl = ctx->f0.fl;
    after_16:
    // 0x801A6368: jal         0x80004EB0
    // 0x801A636C: mov.s       $f28, $f0
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    ctx->f28.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_17;
    // 0x801A636C: mov.s       $f28, $f0
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    ctx->f28.fl = ctx->f0.fl;
    after_17:
    // 0x801A6370: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x801A6374: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801A6378: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801A637C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801A6380: lwc1        $f8, 0x84($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X84);
    // 0x801A6384: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801A6388: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801A638C: sub.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f20.fl;
    // 0x801A6390: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x801A6394: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801A6398: lwc1        $f8, 0x4($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X4);
    // 0x801A639C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x801A63A0: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x801A63A4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801A63A8: lwc1        $f10, 0x8($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X8);
    // 0x801A63AC: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x801A63B0: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x801A63B4: add.s       $f14, $f10, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x801A63B8: lwc1        $f4, 0xC($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XC);
    // 0x801A63BC: sw          $t1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r9;
    // 0x801A63C0: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801A63C4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801A63C8: lwc1        $f6, 0x88($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X88);
    // 0x801A63CC: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x801A63D0: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x801A63D4: lwc1        $f8, 0x8C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x801A63D8: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x801A63DC: sub.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f20.fl;
    // 0x801A63E0: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x801A63E4: lwc1        $f6, 0x90($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X90);
    // 0x801A63E8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801A63EC: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x801A63F0: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x801A63F4: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x801A63F8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801A63FC: sub.s       $f8, $f30, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f30.fl - ctx->f20.fl;
    // 0x801A6400: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x801A6404: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x801A6408: mul.s       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x801A640C: lwc1        $f4, 0x98($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X98);
    // 0x801A6410: lwc1        $f8, 0x9C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x801A6414: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x801A6418: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x801A641C: lwc1        $f4, 0xA0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x801A6420: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    // 0x801A6424: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x801A6428: sub.s       $f8, $f22, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f22.fl - ctx->f20.fl;
    // 0x801A642C: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x801A6430: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x801A6434: sub.s       $f4, $f24, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f24.fl - ctx->f20.fl;
    // 0x801A6438: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x801A643C: mul.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x801A6440: sub.s       $f8, $f26, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f26.fl - ctx->f20.fl;
    // 0x801A6444: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x801A6448: mul.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x801A644C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801A6450: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x801A6454: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    // 0x801A6458: mul.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x801A645C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801A6460: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801A6464: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    // 0x801A6468: mul.s       $f6, $f28, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f28.fl, ctx->f4.fl);
    // 0x801A646C: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    // 0x801A6470: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801A6474: lwc1        $f6, -0x4938($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X4938);
    // 0x801A6478: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801A647C: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x801A6480: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x801A6484: lwc1        $f10, -0x4934($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X4934);
    // 0x801A6488: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x801A648C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801A6490: mfc1        $t0, $f4
    ctx->r8 = (int32_t)ctx->f4.u32l;
    // 0x801A6494: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801A6498: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    // 0x801A649C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x801A64A0: jal         0x801AD624
    // 0x801A64A4: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    Macbeth_Effect357_Spawn1(rdram, ctx);
        goto after_18;
    // 0x801A64A4: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    after_18:
    // 0x801A64A8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801A64AC: sll         $t2, $s0, 16
    ctx->r10 = S32(ctx->r16 << 16);
    // 0x801A64B0: sra         $s0, $t2, 16
    ctx->r16 = S32(SIGNED(ctx->r10) >> 16);
    // 0x801A64B4: slti        $at, $s0, 0x14
    ctx->r1 = SIGNED(ctx->r16) < 0X14 ? 1 : 0;
    // 0x801A64B8: bne         $at, $zero, L_801A6308
    if (ctx->r1 != 0) {
        // 0x801A64BC: nop
    
            goto L_801A6308;
    }
    // 0x801A64BC: nop

    // 0x801A64C0: addiu       $t4, $zero, 0x14
    ctx->r12 = ADD32(0, 0X14);
    // 0x801A64C4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801A64C8: sh          $t4, 0xBC($s1)
    MEM_H(0XBC, ctx->r17) = ctx->r12;
    // 0x801A64CC: sh          $t5, 0xB8($s1)
    MEM_H(0XB8, ctx->r17) = ctx->r13;
L_801A64D0:
    // 0x801A64D0: b           L_801A6514
    // 0x801A64D4: sb          $zero, 0xD0($s1)
    MEM_B(0XD0, ctx->r17) = 0;
        goto L_801A6514;
    // 0x801A64D4: sb          $zero, 0xD0($s1)
    MEM_B(0XD0, ctx->r17) = 0;
L_801A64D8:
    // 0x801A64D8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801A64DC: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x801A64E0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801A64E4: lwc1        $f10, -0x4930($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X4930);
    // 0x801A64E8: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x801A64EC: lui         $a1, 0xC2B4
    ctx->r5 = S32(0XC2B4 << 16);
    // 0x801A64F0: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x801A64F4: jal         0x8009BC2C
    // 0x801A64F8: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_19;
    // 0x801A64F8: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_19:
    // 0x801A64FC: lhu         $t6, 0xBC($s1)
    ctx->r14 = MEM_HU(ctx->r17, 0XBC);
    // 0x801A6500: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801A6504: bnel        $t6, $zero, L_801A6518
    if (ctx->r14 != 0) {
        // 0x801A6508: lw          $ra, 0x7C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X7C);
            goto L_801A6518;
    }
    goto skip_3;
    // 0x801A6508: lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X7C);
    skip_3:
    // 0x801A650C: jal         0x80060FBC
    // 0x801A6510: addiu       $a1, $s1, 0x100
    ctx->r5 = ADD32(ctx->r17, 0X100);
    Object_Kill(rdram, ctx);
        goto after_20;
    // 0x801A6510: addiu       $a1, $s1, 0x100
    ctx->r5 = ADD32(ctx->r17, 0X100);
    after_20:
L_801A6514:
    // 0x801A6514: lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X7C);
L_801A6518:
    // 0x801A6518: ldc1        $f20, 0x40($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X40);
    // 0x801A651C: ldc1        $f22, 0x48($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X48);
    // 0x801A6520: ldc1        $f24, 0x50($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X50);
    // 0x801A6524: ldc1        $f26, 0x58($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X58);
    // 0x801A6528: ldc1        $f28, 0x60($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X60);
    // 0x801A652C: ldc1        $f30, 0x68($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X68);
    // 0x801A6530: lw          $s0, 0x74($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X74);
    // 0x801A6534: lw          $s1, 0x78($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X78);
    // 0x801A6538: jr          $ra
    // 0x801A653C: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
    return;
    // 0x801A653C: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
;}
RECOMP_FUNC void Macbeth_MaRailwaySignal_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A54E8: addiu       $sp, $sp, -0x280
    ctx->r29 = ADD32(ctx->r29, -0X280);
    // 0x801A54EC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801A54F0: sw          $a0, 0x280($sp)
    MEM_W(0X280, ctx->r29) = ctx->r4;
    // 0x801A54F4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A54F8: jal         0x80005708
    // 0x801A54FC: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Push(rdram, ctx);
        goto after_0;
    // 0x801A54FC: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_0:
    // 0x801A5500: lui         $a0, 0x603
    ctx->r4 = S32(0X603 << 16);
    // 0x801A5504: addiu       $a0, $a0, -0xD20
    ctx->r4 = ADD32(ctx->r4, -0XD20);
    // 0x801A5508: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801A550C: jal         0x8009AA20
    // 0x801A5510: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    Animation_GetFrameData(rdram, ctx);
        goto after_1;
    // 0x801A5510: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    after_1:
    // 0x801A5514: lw          $t6, 0x280($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X280);
    // 0x801A5518: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x801A551C: addiu       $t7, $t7, 0x4660
    ctx->r15 = ADD32(ctx->r15, 0X4660);
    // 0x801A5520: lui         $a1, 0x603
    ctx->r5 = S32(0X603 << 16);
    // 0x801A5524: lui         $a3, 0x801A
    ctx->r7 = S32(0X801A << 16);
    // 0x801A5528: addiu       $a3, $a3, 0x54AC
    ctx->r7 = ADD32(ctx->r7, 0X54AC);
    // 0x801A552C: addiu       $a1, $a1, -0xC94
    ctx->r5 = ADD32(ctx->r5, -0XC94);
    // 0x801A5530: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x801A5534: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801A5538: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    // 0x801A553C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x801A5540: jal         0x8009A72C
    // 0x801A5544: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    Animation_DrawSkeleton(rdram, ctx);
        goto after_2;
    // 0x801A5544: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    after_2:
    // 0x801A5548: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A554C: jal         0x80005740
    // 0x801A5550: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Pop(rdram, ctx);
        goto after_3;
    // 0x801A5550: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_3:
    // 0x801A5554: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A5558: jal         0x80005708
    // 0x801A555C: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Push(rdram, ctx);
        goto after_4;
    // 0x801A555C: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_4:
    // 0x801A5560: lui         $a0, 0x603
    ctx->r4 = S32(0X603 << 16);
    // 0x801A5564: addiu       $a0, $a0, -0xF68
    ctx->r4 = ADD32(ctx->r4, -0XF68);
    // 0x801A5568: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801A556C: jal         0x8009AA20
    // 0x801A5570: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    Animation_GetFrameData(rdram, ctx);
        goto after_5;
    // 0x801A5570: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    after_5:
    // 0x801A5574: lw          $t8, 0x280($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X280);
    // 0x801A5578: lui         $t9, 0x800C
    ctx->r25 = S32(0X800C << 16);
    // 0x801A557C: addiu       $t9, $t9, 0x4660
    ctx->r25 = ADD32(ctx->r25, 0X4660);
    // 0x801A5580: lui         $a1, 0x603
    ctx->r5 = S32(0X603 << 16);
    // 0x801A5584: lui         $a3, 0x801A
    ctx->r7 = S32(0X801A << 16);
    // 0x801A5588: addiu       $a3, $a3, 0x5124
    ctx->r7 = ADD32(ctx->r7, 0X5124);
    // 0x801A558C: addiu       $a1, $a1, -0xD9C
    ctx->r5 = ADD32(ctx->r5, -0XD9C);
    // 0x801A5590: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x801A5594: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801A5598: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    // 0x801A559C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x801A55A0: jal         0x8009A72C
    // 0x801A55A4: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    Animation_DrawSkeleton(rdram, ctx);
        goto after_6;
    // 0x801A55A4: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    after_6:
    // 0x801A55A8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A55AC: jal         0x80005740
    // 0x801A55B0: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Pop(rdram, ctx);
        goto after_7;
    // 0x801A55B0: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_7:
    // 0x801A55B4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801A55B8: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x801A55BC: jal         0x800B8DD0
    // 0x801A55C0: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    RCP_SetupDL(rdram, ctx);
        goto after_8;
    // 0x801A55C0: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    after_8:
    // 0x801A55C4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801A55C8: addiu       $sp, $sp, 0x280
    ctx->r29 = ADD32(ctx->r29, 0X280);
    // 0x801A55CC: jr          $ra
    // 0x801A55D0: nop

    return;
    // 0x801A55D0: nop

;}
RECOMP_FUNC void Macbeth_8019A8C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019A8C8: addiu       $sp, $sp, -0xC8
    ctx->r29 = ADD32(ctx->r29, -0XC8);
    // 0x8019A8CC: sw          $s2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r18;
    // 0x8019A8D0: sll         $s2, $a1, 16
    ctx->r18 = S32(ctx->r5 << 16);
    // 0x8019A8D4: sra         $t6, $s2, 16
    ctx->r14 = S32(SIGNED(ctx->r18) >> 16);
    // 0x8019A8D8: sw          $s0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r16;
    // 0x8019A8DC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8019A8E0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8019A8E4: or          $s2, $t6, $zero
    ctx->r18 = ctx->r14 | 0;
    // 0x8019A8E8: sw          $ra, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r31;
    // 0x8019A8EC: sw          $s1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r17;
    // 0x8019A8F0: sdc1        $f30, 0x70($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X70, ctx->r29);
    // 0x8019A8F4: sdc1        $f28, 0x68($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X68, ctx->r29);
    // 0x8019A8F8: sdc1        $f26, 0x60($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X60, ctx->r29);
    // 0x8019A8FC: sdc1        $f24, 0x58($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X58, ctx->r29);
    // 0x8019A900: sdc1        $f22, 0x50($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X50, ctx->r29);
    // 0x8019A904: sdc1        $f20, 0x48($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X48, ctx->r29);
    // 0x8019A908: sw          $a1, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r5;
    // 0x8019A90C: lwc1        $f4, 0x178($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X178);
    // 0x8019A910: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8019A914: lui         $at, 0x4391
    ctx->r1 = S32(0X4391 << 16);
    // 0x8019A918: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8019A91C: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8019A920: lui         $at, 0x41B0
    ctx->r1 = S32(0X41B0 << 16);
    // 0x8019A924: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x8019A928: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8019A92C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019A930: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8019A934: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x8019A938: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x8019A93C: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x8019A940: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x8019A944: add.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8019A948: jal         0x8007BFFC
    // 0x8019A94C: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    Effect_Effect386_Spawn1(rdram, ctx);
        goto after_0;
    // 0x8019A94C: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x8019A950: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8019A954: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x8019A958: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8019A95C:
    // 0x8019A95C: jal         0x80004EB0
    // 0x8019A960: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x8019A960: nop

    after_1:
    // 0x8019A964: jal         0x80004EB0
    // 0x8019A968: swc1        $f0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_2;
    // 0x8019A968: swc1        $f0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x8019A96C: jal         0x80004EB0
    // 0x8019A970: swc1        $f0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_3;
    // 0x8019A970: swc1        $f0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f0.u32l;
    after_3:
    // 0x8019A974: jal         0x80004EB0
    // 0x8019A978: swc1        $f0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_4;
    // 0x8019A978: swc1        $f0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f0.u32l;
    after_4:
    // 0x8019A97C: jal         0x80004EB0
    // 0x8019A980: swc1        $f0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_5;
    // 0x8019A980: swc1        $f0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f0.u32l;
    after_5:
    // 0x8019A984: jal         0x80004EB0
    // 0x8019A988: swc1        $f0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_6;
    // 0x8019A988: swc1        $f0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f0.u32l;
    after_6:
    // 0x8019A98C: jal         0x80004EB0
    // 0x8019A990: swc1        $f0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_7;
    // 0x8019A990: swc1        $f0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f0.u32l;
    after_7:
    // 0x8019A994: jal         0x80004EB0
    // 0x8019A998: swc1        $f0, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_8;
    // 0x8019A998: swc1        $f0, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f0.u32l;
    after_8:
    // 0x8019A99C: jal         0x80004EB0
    // 0x8019A9A0: mov.s       $f30, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    ctx->f30.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_9;
    // 0x8019A9A0: mov.s       $f30, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    ctx->f30.fl = ctx->f0.fl;
    after_9:
    // 0x8019A9A4: jal         0x80004EB0
    // 0x8019A9A8: swc1        $f0, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_10;
    // 0x8019A9A8: swc1        $f0, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f0.u32l;
    after_10:
    // 0x8019A9AC: jal         0x80004EB0
    // 0x8019A9B0: mov.s       $f28, $f0
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    ctx->f28.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_11;
    // 0x8019A9B0: mov.s       $f28, $f0
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    ctx->f28.fl = ctx->f0.fl;
    after_11:
    // 0x8019A9B4: jal         0x80004EB0
    // 0x8019A9B8: mov.s       $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    ctx->f26.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_12;
    // 0x8019A9B8: mov.s       $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    ctx->f26.fl = ctx->f0.fl;
    after_12:
    // 0x8019A9BC: jal         0x80004EB0
    // 0x8019A9C0: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_13;
    // 0x8019A9C0: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_13:
    // 0x8019A9C4: jal         0x80004EB0
    // 0x8019A9C8: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_14;
    // 0x8019A9C8: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    after_14:
    // 0x8019A9CC: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8019A9D0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8019A9D4: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8019A9D8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8019A9DC: lwc1        $f6, 0x8C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x8019A9E0: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8019A9E4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8019A9E8: sub.s       $f8, $f6, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f24.fl;
    // 0x8019A9EC: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8019A9F0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8019A9F4: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8019A9F8: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8019A9FC: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8019AA00: lwc1        $f10, 0x168($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X168);
    // 0x8019AA04: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8019AA08: lwc1        $f6, 0x90($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X90);
    // 0x8019AA0C: sub.s       $f4, $f6, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f24.fl;
    // 0x8019AA10: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8019AA14: add.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8019AA18: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8019AA1C: lui         $at, 0x438C
    ctx->r1 = S32(0X438C << 16);
    // 0x8019AA20: mul.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x8019AA24: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019AA28: lui         $at, 0x43D2
    ctx->r1 = S32(0X43D2 << 16);
    // 0x8019AA2C: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8019AA30: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019AA34: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8019AA38: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8019AA3C: add.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8019AA40: lwc1        $f10, 0x94($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X94);
    // 0x8019AA44: sw          $s2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r18;
    // 0x8019AA48: sub.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x8019AA4C: mul.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8019AA50: lwc1        $f10, 0x98($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X98);
    // 0x8019AA54: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8019AA58: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8019AA5C: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x8019AA60: sub.s       $f6, $f10, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f24.fl;
    // 0x8019AA64: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x8019AA68: lwc1        $f10, 0x9C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x8019AA6C: mul.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8019AA70: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8019AA74: nop

    // 0x8019AA78: mul.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x8019AA7C: lwc1        $f6, 0xA0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x8019AA80: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x8019AA84: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019AA88: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8019AA8C: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x8019AA90: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019AA94: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x8019AA98: sub.s       $f8, $f6, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f24.fl;
    // 0x8019AA9C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x8019AAA0: lwc1        $f6, 0xA4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x8019AAA4: mul.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x8019AAA8: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    // 0x8019AAAC: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8019AAB0: lwc1        $f10, 0xAC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x8019AAB4: mul.s       $f4, $f30, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f30.fl, ctx->f2.fl);
    // 0x8019AAB8: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x8019AABC: mul.s       $f6, $f10, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8019AAC0: sub.s       $f8, $f28, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = ctx->f28.fl - ctx->f24.fl;
    // 0x8019AAC4: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x8019AAC8: mul.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8019AACC: sub.s       $f10, $f26, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = ctx->f26.fl - ctx->f24.fl;
    // 0x8019AAD0: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x8019AAD4: sub.s       $f8, $f20, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = ctx->f20.fl - ctx->f24.fl;
    // 0x8019AAD8: mul.s       $f6, $f10, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8019AADC: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x8019AAE0: mul.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8019AAE4: nop

    // 0x8019AAE8: mul.s       $f10, $f22, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f18.fl);
    // 0x8019AAEC: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    // 0x8019AAF0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8019AAF4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019AAF8: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x8019AAFC: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8019AB00: lwc1        $f10, -0x4D0C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X4D0C);
    // 0x8019AB04: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019AB08: mul.s       $f6, $f0, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8019AB0C: trunc.w.s   $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8019AB10: lwc1        $f8, -0x4D08($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4D08);
    // 0x8019AB14: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x8019AB18: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8019AB1C: sw          $t9, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r25;
    // 0x8019AB20: jal         0x801AD624
    // 0x8019AB24: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    Macbeth_Effect357_Spawn1(rdram, ctx);
        goto after_15;
    // 0x8019AB24: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    after_15:
    // 0x8019AB28: jal         0x80004EB0
    // 0x8019AB2C: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_16;
    // 0x8019AB2C: nop

    after_16:
    // 0x8019AB30: jal         0x80004EB0
    // 0x8019AB34: swc1        $f0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_17;
    // 0x8019AB34: swc1        $f0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f0.u32l;
    after_17:
    // 0x8019AB38: jal         0x80004EB0
    // 0x8019AB3C: swc1        $f0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_18;
    // 0x8019AB3C: swc1        $f0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f0.u32l;
    after_18:
    // 0x8019AB40: jal         0x80004EB0
    // 0x8019AB44: swc1        $f0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_19;
    // 0x8019AB44: swc1        $f0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f0.u32l;
    after_19:
    // 0x8019AB48: jal         0x80004EB0
    // 0x8019AB4C: swc1        $f0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_20;
    // 0x8019AB4C: swc1        $f0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f0.u32l;
    after_20:
    // 0x8019AB50: jal         0x80004EB0
    // 0x8019AB54: swc1        $f0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_21;
    // 0x8019AB54: swc1        $f0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f0.u32l;
    after_21:
    // 0x8019AB58: jal         0x80004EB0
    // 0x8019AB5C: swc1        $f0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_22;
    // 0x8019AB5C: swc1        $f0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f0.u32l;
    after_22:
    // 0x8019AB60: jal         0x80004EB0
    // 0x8019AB64: swc1        $f0, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_23;
    // 0x8019AB64: swc1        $f0, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f0.u32l;
    after_23:
    // 0x8019AB68: jal         0x80004EB0
    // 0x8019AB6C: mov.s       $f30, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    ctx->f30.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_24;
    // 0x8019AB6C: mov.s       $f30, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    ctx->f30.fl = ctx->f0.fl;
    after_24:
    // 0x8019AB70: jal         0x80004EB0
    // 0x8019AB74: swc1        $f0, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_25;
    // 0x8019AB74: swc1        $f0, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f0.u32l;
    after_25:
    // 0x8019AB78: jal         0x80004EB0
    // 0x8019AB7C: mov.s       $f28, $f0
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    ctx->f28.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_26;
    // 0x8019AB7C: mov.s       $f28, $f0
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    ctx->f28.fl = ctx->f0.fl;
    after_26:
    // 0x8019AB80: jal         0x80004EB0
    // 0x8019AB84: mov.s       $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    ctx->f26.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_27;
    // 0x8019AB84: mov.s       $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    ctx->f26.fl = ctx->f0.fl;
    after_27:
    // 0x8019AB88: jal         0x80004EB0
    // 0x8019AB8C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_28;
    // 0x8019AB8C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_28:
    // 0x8019AB90: jal         0x80004EB0
    // 0x8019AB94: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_29;
    // 0x8019AB94: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    after_29:
    // 0x8019AB98: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8019AB9C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8019ABA0: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x8019ABA4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8019ABA8: lwc1        $f10, 0x8C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x8019ABAC: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8019ABB0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8019ABB4: sub.s       $f6, $f10, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f24.fl;
    // 0x8019ABB8: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8019ABBC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8019ABC0: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8019ABC4: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8019ABC8: mul.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8019ABCC: lwc1        $f8, 0x178($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X178);
    // 0x8019ABD0: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8019ABD4: lwc1        $f10, 0x90($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X90);
    // 0x8019ABD8: sub.s       $f4, $f10, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f24.fl;
    // 0x8019ABDC: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8019ABE0: add.s       $f12, $f8, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8019ABE4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8019ABE8: lui         $at, 0x438C
    ctx->r1 = S32(0X438C << 16);
    // 0x8019ABEC: mul.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8019ABF0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019ABF4: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8019ABF8: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8019ABFC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019AC00: lwc1        $f10, 0x94($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X94);
    // 0x8019AC04: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8019AC08: add.s       $f14, $f6, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8019AC0C: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8019AC10: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8019AC14: lwc1        $f4, 0x98($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X98);
    // 0x8019AC18: sw          $s2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r18;
    // 0x8019AC1C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8019AC20: sub.s       $f6, $f4, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f24.fl;
    // 0x8019AC24: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x8019AC28: lwc1        $f10, 0x9C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x8019AC2C: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8019AC30: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x8019AC34: mul.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8019AC38: lwc1        $f8, 0xA0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x8019AC3C: sub.s       $f10, $f8, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f24.fl;
    // 0x8019AC40: add.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x8019AC44: mul.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8019AC48: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x8019AC4C: lwc1        $f6, 0xA4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x8019AC50: mul.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x8019AC54: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x8019AC58: lwc1        $f4, 0xAC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x8019AC5C: mul.s       $f10, $f30, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f30.fl, ctx->f18.fl);
    // 0x8019AC60: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x8019AC64: mul.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x8019AC68: sub.s       $f8, $f28, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = ctx->f28.fl - ctx->f24.fl;
    // 0x8019AC6C: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x8019AC70: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8019AC74: nop

    // 0x8019AC78: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8019AC7C: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x8019AC80: sub.s       $f6, $f26, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = ctx->f26.fl - ctx->f24.fl;
    // 0x8019AC84: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8019AC88: nop

    // 0x8019AC8C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8019AC90: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x8019AC94: sub.s       $f4, $f20, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = ctx->f20.fl - ctx->f24.fl;
    // 0x8019AC98: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8019AC9C: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8019ACA0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8019ACA4: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x8019ACA8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8019ACAC: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x8019ACB0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8019ACB4: mul.s       $f4, $f22, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f10.fl);
    // 0x8019ACB8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019ACBC: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x8019ACC0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8019ACC4: lwc1        $f4, -0x4D04($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4D04);
    // 0x8019ACC8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019ACCC: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8019ACD0: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8019ACD4: lwc1        $f8, -0x4D00($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4D00);
    // 0x8019ACD8: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    // 0x8019ACDC: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8019ACE0: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    // 0x8019ACE4: jal         0x801AD624
    // 0x8019ACE8: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    Macbeth_Effect357_Spawn1(rdram, ctx);
        goto after_30;
    // 0x8019ACE8: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    after_30:
    // 0x8019ACEC: jal         0x80004EB0
    // 0x8019ACF0: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_31;
    // 0x8019ACF0: nop

    after_31:
    // 0x8019ACF4: jal         0x80004EB0
    // 0x8019ACF8: swc1        $f0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_32;
    // 0x8019ACF8: swc1        $f0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f0.u32l;
    after_32:
    // 0x8019ACFC: jal         0x80004EB0
    // 0x8019AD00: swc1        $f0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_33;
    // 0x8019AD00: swc1        $f0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f0.u32l;
    after_33:
    // 0x8019AD04: jal         0x80004EB0
    // 0x8019AD08: swc1        $f0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_34;
    // 0x8019AD08: swc1        $f0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f0.u32l;
    after_34:
    // 0x8019AD0C: jal         0x80004EB0
    // 0x8019AD10: swc1        $f0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_35;
    // 0x8019AD10: swc1        $f0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f0.u32l;
    after_35:
    // 0x8019AD14: jal         0x80004EB0
    // 0x8019AD18: swc1        $f0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_36;
    // 0x8019AD18: swc1        $f0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f0.u32l;
    after_36:
    // 0x8019AD1C: jal         0x80004EB0
    // 0x8019AD20: swc1        $f0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_37;
    // 0x8019AD20: swc1        $f0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f0.u32l;
    after_37:
    // 0x8019AD24: jal         0x80004EB0
    // 0x8019AD28: swc1        $f0, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_38;
    // 0x8019AD28: swc1        $f0, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f0.u32l;
    after_38:
    // 0x8019AD2C: jal         0x80004EB0
    // 0x8019AD30: mov.s       $f30, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    ctx->f30.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_39;
    // 0x8019AD30: mov.s       $f30, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    ctx->f30.fl = ctx->f0.fl;
    after_39:
    // 0x8019AD34: jal         0x80004EB0
    // 0x8019AD38: swc1        $f0, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_40;
    // 0x8019AD38: swc1        $f0, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f0.u32l;
    after_40:
    // 0x8019AD3C: jal         0x80004EB0
    // 0x8019AD40: mov.s       $f28, $f0
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    ctx->f28.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_41;
    // 0x8019AD40: mov.s       $f28, $f0
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    ctx->f28.fl = ctx->f0.fl;
    after_41:
    // 0x8019AD44: jal         0x80004EB0
    // 0x8019AD48: mov.s       $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    ctx->f26.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_42;
    // 0x8019AD48: mov.s       $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    ctx->f26.fl = ctx->f0.fl;
    after_42:
    // 0x8019AD4C: jal         0x80004EB0
    // 0x8019AD50: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_43;
    // 0x8019AD50: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_43:
    // 0x8019AD54: jal         0x80004EB0
    // 0x8019AD58: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_44;
    // 0x8019AD58: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    after_44:
    // 0x8019AD5C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8019AD60: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8019AD64: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8019AD68: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8019AD6C: lwc1        $f4, 0x8C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x8019AD70: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x8019AD74: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8019AD78: sub.s       $f6, $f4, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f24.fl;
    // 0x8019AD7C: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8019AD80: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8019AD84: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8019AD88: lui         $at, 0x438C
    ctx->r1 = S32(0X438C << 16);
    // 0x8019AD8C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8019AD90: lwc1        $f8, 0x170($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X170);
    // 0x8019AD94: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8019AD98: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8019AD9C: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8019ADA0: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8019ADA4: add.s       $f12, $f8, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8019ADA8: lwc1        $f6, 0x90($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X90);
    // 0x8019ADAC: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8019ADB0: sub.s       $f4, $f6, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f24.fl;
    // 0x8019ADB4: lwc1        $f6, 0x94($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X94);
    // 0x8019ADB8: mul.s       $f10, $f4, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8019ADBC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019ADC0: lui         $at, 0x43D2
    ctx->r1 = S32(0X43D2 << 16);
    // 0x8019ADC4: add.s       $f14, $f10, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8019ADC8: mul.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x8019ADCC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8019ADD0: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8019ADD4: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8019ADD8: sw          $s2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r18;
    // 0x8019ADDC: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8019ADE0: add.s       $f8, $f4, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x8019ADE4: lwc1        $f4, 0x98($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X98);
    // 0x8019ADE8: add.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8019ADEC: sub.s       $f10, $f4, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f24.fl;
    // 0x8019ADF0: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x8019ADF4: lwc1        $f6, 0x9C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x8019ADF8: mul.s       $f8, $f10, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8019ADFC: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x8019AE00: mul.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x8019AE04: lwc1        $f8, 0xA0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x8019AE08: sub.s       $f6, $f8, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f24.fl;
    // 0x8019AE0C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8019AE10: add.s       $f10, $f4, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x8019AE14: mul.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x8019AE18: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x8019AE1C: lwc1        $f10, 0xA4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x8019AE20: mul.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x8019AE24: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x8019AE28: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019AE2C: lwc1        $f8, 0xAC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x8019AE30: mul.s       $f10, $f30, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f30.fl, ctx->f4.fl);
    // 0x8019AE34: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x8019AE38: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8019AE3C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8019AE40: mul.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8019AE44: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x8019AE48: sub.s       $f10, $f28, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = ctx->f28.fl - ctx->f24.fl;
    // 0x8019AE4C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8019AE50: nop

    // 0x8019AE54: mul.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x8019AE58: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x8019AE5C: sub.s       $f4, $f26, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = ctx->f26.fl - ctx->f24.fl;
    // 0x8019AE60: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8019AE64: nop

    // 0x8019AE68: mul.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x8019AE6C: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    // 0x8019AE70: sub.s       $f6, $f20, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = ctx->f20.fl - ctx->f24.fl;
    // 0x8019AE74: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019AE78: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8019AE7C: mul.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x8019AE80: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    // 0x8019AE84: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8019AE88: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x8019AE8C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019AE90: mul.s       $f6, $f22, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f22.fl, ctx->f8.fl);
    // 0x8019AE94: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019AE98: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    // 0x8019AE9C: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8019AEA0: lwc1        $f6, -0x4CFC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X4CFC);
    // 0x8019AEA4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019AEA8: mul.s       $f4, $f0, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8019AEAC: trunc.w.s   $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8019AEB0: lwc1        $f10, -0x4CF8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X4CF8);
    // 0x8019AEB4: mfc1        $t3, $f8
    ctx->r11 = (int32_t)ctx->f8.u32l;
    // 0x8019AEB8: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8019AEBC: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x8019AEC0: jal         0x801AD624
    // 0x8019AEC4: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    Macbeth_Effect357_Spawn1(rdram, ctx);
        goto after_45;
    // 0x8019AEC4: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    after_45:
    // 0x8019AEC8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8019AECC: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8019AED0: bne         $s1, $at, L_8019A95C
    if (ctx->r17 != ctx->r1) {
        // 0x8019AED4: nop
    
            goto L_8019A95C;
    }
    // 0x8019AED4: nop

    // 0x8019AED8: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8019AEDC: lui         $t4, 0x800C
    ctx->r12 = S32(0X800C << 16);
    // 0x8019AEE0: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8019AEE4: addiu       $t4, $t4, 0x5D3C
    ctx->r12 = ADD32(ctx->r12, 0X5D3C);
    // 0x8019AEE8: lui         $a0, 0x2940
    ctx->r4 = S32(0X2940 << 16);
    // 0x8019AEEC: ori         $a0, $a0, 0xC00A
    ctx->r4 = ctx->r4 | 0XC00A;
    // 0x8019AEF0: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x8019AEF4: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8019AEF8: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x8019AEFC: jal         0x80019218
    // 0x8019AF00: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_46;
    // 0x8019AF00: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_46:
    // 0x8019AF04: lw          $ra, 0x84($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X84);
    // 0x8019AF08: ldc1        $f20, 0x48($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X48);
    // 0x8019AF0C: ldc1        $f22, 0x50($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X50);
    // 0x8019AF10: ldc1        $f24, 0x58($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X58);
    // 0x8019AF14: ldc1        $f26, 0x60($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X60);
    // 0x8019AF18: ldc1        $f28, 0x68($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X68);
    // 0x8019AF1C: ldc1        $f30, 0x70($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X70);
    // 0x8019AF20: lw          $s0, 0x78($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X78);
    // 0x8019AF24: lw          $s1, 0x7C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X7C);
    // 0x8019AF28: lw          $s2, 0x80($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X80);
    // 0x8019AF2C: jr          $ra
    // 0x8019AF30: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
    return;
    // 0x8019AF30: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
;}
RECOMP_FUNC void Macbeth_MaShockBox_Setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801AF134: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801AF138: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801AF13C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801AF140: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801AF144: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801AF148: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x801AF14C: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x801AF150: jal         0x800613C4
    // 0x801AF154: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Actor_Initialize(rdram, ctx);
        goto after_0;
    // 0x801AF154: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x801AF158: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801AF15C: addiu       $t7, $zero, 0xDE
    ctx->r15 = ADD32(0, 0XDE);
    // 0x801AF160: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
    // 0x801AF164: sh          $t7, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r15;
    // 0x801AF168: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801AF16C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801AF170: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801AF174: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x801AF178: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x801AF17C: addiu       $t8, $zero, 0x1E
    ctx->r24 = ADD32(0, 0X1E);
    // 0x801AF180: andi        $a1, $t7, 0xFFFF
    ctx->r5 = ctx->r15 & 0XFFFF;
    // 0x801AF184: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x801AF188: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x801AF18C: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x801AF190: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    // 0x801AF194: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x801AF198: swc1        $f10, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f10.u32l;
    // 0x801AF19C: lwc1        $f16, 0x3C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x801AF1A0: swc1        $f16, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f16.u32l;
    // 0x801AF1A4: lwc1        $f18, 0x40($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X40);
    // 0x801AF1A8: sh          $zero, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = 0;
    // 0x801AF1AC: sh          $t8, 0xCE($s0)
    MEM_H(0XCE, ctx->r16) = ctx->r24;
    // 0x801AF1B0: swc1        $f0, 0x114($s0)
    MEM_W(0X114, ctx->r16) = ctx->f0.u32l;
    // 0x801AF1B4: swc1        $f0, 0x11C($s0)
    MEM_W(0X11C, ctx->r16) = ctx->f0.u32l;
    // 0x801AF1B8: jal         0x800612B8
    // 0x801AF1BC: swc1        $f18, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f18.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_1;
    // 0x801AF1BC: swc1        $f18, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f18.u32l;
    after_1:
    // 0x801AF1C0: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x801AF1C4: lui         $t9, 0x800C
    ctx->r25 = S32(0X800C << 16);
    // 0x801AF1C8: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x801AF1CC: addiu       $t9, $t9, 0x5D3C
    ctx->r25 = ADD32(ctx->r25, 0X5D3C);
    // 0x801AF1D0: lui         $a0, 0x2900
    ctx->r4 = S32(0X2900 << 16);
    // 0x801AF1D4: ori         $a0, $a0, 0x201D
    ctx->r4 = ctx->r4 | 0X201D;
    // 0x801AF1D8: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x801AF1DC: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x801AF1E0: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x801AF1E4: jal         0x80019218
    // 0x801AF1E8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_2;
    // 0x801AF1E8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_2:
    // 0x801AF1EC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801AF1F0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801AF1F4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801AF1F8: jr          $ra
    // 0x801AF1FC: nop

    return;
    // 0x801AF1FC: nop

;}
RECOMP_FUNC void Macbeth_MaMechbeth_OverrideLimbDraw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801ABC14: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x801ABC18: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801ABC1C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x801ABC20: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x801ABC24: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801ABC28: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x801ABC2C: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x801ABC30: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    // 0x801ABC34: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    // 0x801ABC38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801ABC3C: jal         0x800B8DD0
    // 0x801ABC40: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x801ABC40: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    after_0:
    // 0x801ABC44: lui         $a1, 0x4
    ctx->r5 = S32(0X4 << 16);
    // 0x801ABC48: lui         $a3, 0xB700
    ctx->r7 = S32(0XB700 << 16);
    // 0x801ABC4C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801ABC50: lui         $t7, 0xB600
    ctx->r15 = S32(0XB600 << 16);
    // 0x801ABC54: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801ABC58: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x801ABC5C: sw          $a1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r5;
    // 0x801ABC60: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801ABC64: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801ABC68: addiu       $t9, $zero, 0x2000
    ctx->r25 = ADD32(0, 0X2000);
    // 0x801ABC6C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x801ABC70: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x801ABC74: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x801ABC78: sw          $a3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r7;
    // 0x801ABC7C: lw          $a2, 0x68($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X68);
    // 0x801ABC80: addiu       $t1, $a2, -0x2
    ctx->r9 = ADD32(ctx->r6, -0X2);
    // 0x801ABC84: sltiu       $at, $t1, 0x1A
    ctx->r1 = ctx->r9 < 0X1A ? 1 : 0;
    // 0x801ABC88: beq         $at, $zero, L_801ABCC8
    if (ctx->r1 == 0) {
        // 0x801ABC8C: sll         $t1, $t1, 2
        ctx->r9 = S32(ctx->r9 << 2);
            goto L_801ABCC8;
    }
    // 0x801ABC8C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x801ABC90: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801ABC94: addu        $at, $at, $t1
    gpr jr_addend_801ABC9C = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x801ABC98: lw          $t1, -0x4730($at)
    ctx->r9 = ADD32(ctx->r1, -0X4730);
    // 0x801ABC9C: jr          $t1
    // 0x801ABCA0: nop

    switch (jr_addend_801ABC9C >> 2) {
        case 0: goto L_801ABCA4; break;
        case 1: goto L_801ABCA4; break;
        case 2: goto L_801ABCA4; break;
        case 3: goto L_801ABCC8; break;
        case 4: goto L_801ABCC8; break;
        case 5: goto L_801ABCC8; break;
        case 6: goto L_801ABCC8; break;
        case 7: goto L_801ABCC8; break;
        case 8: goto L_801ABCC8; break;
        case 9: goto L_801ABCC8; break;
        case 10: goto L_801ABCC8; break;
        case 11: goto L_801ABCC8; break;
        case 12: goto L_801ABCC8; break;
        case 13: goto L_801ABCC8; break;
        case 14: goto L_801ABCC8; break;
        case 15: goto L_801ABCC8; break;
        case 16: goto L_801ABCC8; break;
        case 17: goto L_801ABCC8; break;
        case 18: goto L_801ABCC8; break;
        case 19: goto L_801ABCC8; break;
        case 20: goto L_801ABCC8; break;
        case 21: goto L_801ABCC8; break;
        case 22: goto L_801ABCC8; break;
        case 23: goto L_801ABCA4; break;
        case 24: goto L_801ABCA4; break;
        case 25: goto L_801ABCA4; break;
        default: switch_error(__func__, 0x801ABC9C, 0x801BB8D0);
    }
    // 0x801ABCA0: nop

L_801ABCA4:
    // 0x801ABCA4: lw          $t2, 0x78($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X78);
    // 0x801ABCA8: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x801ABCAC: lw          $t4, 0x6C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X6C);
    // 0x801ABCB0: lh          $t3, 0xB8($t2)
    ctx->r11 = MEM_H(ctx->r10, 0XB8);
    // 0x801ABCB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801ABCB8: bnel        $t3, $at, L_801ABCCC
    if (ctx->r11 != ctx->r1) {
        // 0x801ABCBC: addiu       $t5, $a2, -0x1
        ctx->r13 = ADD32(ctx->r6, -0X1);
            goto L_801ABCCC;
    }
    goto skip_0;
    // 0x801ABCBC: addiu       $t5, $a2, -0x1
    ctx->r13 = ADD32(ctx->r6, -0X1);
    skip_0:
    // 0x801ABCC0: b           L_801AC1AC
    // 0x801ABCC4: sw          $zero, 0x0($t4)
    MEM_W(0X0, ctx->r12) = 0;
        goto L_801AC1AC;
    // 0x801ABCC4: sw          $zero, 0x0($t4)
    MEM_W(0X0, ctx->r12) = 0;
L_801ABCC8:
    // 0x801ABCC8: addiu       $t5, $a2, -0x1
    ctx->r13 = ADD32(ctx->r6, -0X1);
L_801ABCCC:
    // 0x801ABCCC: sltiu       $at, $t5, 0x1E
    ctx->r1 = ctx->r13 < 0X1E ? 1 : 0;
    // 0x801ABCD0: beq         $at, $zero, L_801AC090
    if (ctx->r1 == 0) {
        // 0x801ABCD4: sll         $t5, $t5, 2
        ctx->r13 = S32(ctx->r13 << 2);
            goto L_801AC090;
    }
    // 0x801ABCD4: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x801ABCD8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801ABCDC: addu        $at, $at, $t5
    gpr jr_addend_801ABCE4 = ctx->r13;
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x801ABCE0: lw          $t5, -0x46C8($at)
    ctx->r13 = ADD32(ctx->r1, -0X46C8);
    // 0x801ABCE4: jr          $t5
    // 0x801ABCE8: nop

    switch (jr_addend_801ABCE4 >> 2) {
        case 0: goto L_801ABCEC; break;
        case 1: goto L_801ABF14; break;
        case 2: goto L_801ABF14; break;
        case 3: goto L_801ABCEC; break;
        case 4: goto L_801ABF14; break;
        case 5: goto L_801ABF14; break;
        case 6: goto L_801ABCEC; break;
        case 7: goto L_801ABD2C; break;
        case 8: goto L_801AC090; break;
        case 9: goto L_801ABCEC; break;
        case 10: goto L_801ABCEC; break;
        case 11: goto L_801ABCEC; break;
        case 12: goto L_801ABCEC; break;
        case 13: goto L_801AC090; break;
        case 14: goto L_801AC090; break;
        case 15: goto L_801AC090; break;
        case 16: goto L_801ABCEC; break;
        case 17: goto L_801AC090; break;
        case 18: goto L_801ABCEC; break;
        case 19: goto L_801ABCEC; break;
        case 20: goto L_801AC090; break;
        case 21: goto L_801AC090; break;
        case 22: goto L_801AC090; break;
        case 23: goto L_801AC090; break;
        case 24: goto L_801AC090; break;
        case 25: goto L_801ABCEC; break;
        case 26: goto L_801ABCEC; break;
        case 27: goto L_801AC090; break;
        case 28: goto L_801ABCEC; break;
        case 29: goto L_801ABCEC; break;
        default: switch_error(__func__, 0x801ABCE4, 0x801BB938);
    }
    // 0x801ABCE8: nop

L_801ABCEC:
    // 0x801ABCEC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801ABCF0: lui         $t7, 0xBB00
    ctx->r15 = S32(0XBB00 << 16);
    // 0x801ABCF4: lui         $t8, 0xBB8
    ctx->r24 = S32(0XBB8 << 16);
    // 0x801ABCF8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801ABCFC: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x801ABD00: ori         $t8, $t8, 0xBB8
    ctx->r24 = ctx->r24 | 0XBB8;
    // 0x801ABD04: ori         $t7, $t7, 0x1
    ctx->r15 = ctx->r15 | 0X1;
    // 0x801ABD08: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801ABD0C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x801ABD10: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801ABD14: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x801ABD18: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x801ABD1C: sw          $a1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r5;
    // 0x801ABD20: sw          $a3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r7;
    // 0x801ABD24: b           L_801AC094
    // 0x801ABD28: addiu       $t5, $a2, -0x9
    ctx->r13 = ADD32(ctx->r6, -0X9);
        goto L_801AC094;
    // 0x801ABD28: addiu       $t5, $a2, -0x9
    ctx->r13 = ADD32(ctx->r6, -0X9);
L_801ABD2C:
    // 0x801ABD2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801ABD30: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    // 0x801ABD34: jal         0x800B8DD0
    // 0x801ABD38: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    RCP_SetupDL(rdram, ctx);
        goto after_1;
    // 0x801ABD38: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    after_1:
    // 0x801ABD3C: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x801ABD40: addiu       $t0, $t0, -0x1C98
    ctx->r8 = ADD32(ctx->r8, -0X1C98);
    // 0x801ABD44: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x801ABD48: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x801ABD4C: lui         $t2, 0xFA00
    ctx->r10 = S32(0XFA00 << 16);
    // 0x801ABD50: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x801ABD54: addiu       $t1, $v1, 0x8
    ctx->r9 = ADD32(ctx->r3, 0X8);
    // 0x801ABD58: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x801ABD5C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801ABD60: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x801ABD64: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x801ABD68: lwc1        $f4, 0x58($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X58);
    // 0x801ABD6C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801ABD70: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801ABD74: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x801ABD78: nop

    // 0x801ABD7C: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x801ABD80: beql        $t4, $zero, L_801ABDD0
    if (ctx->r12 == 0) {
        // 0x801ABD84: mfc1        $t4, $f6
        ctx->r12 = (int32_t)ctx->f6.u32l;
            goto L_801ABDD0;
    }
    goto skip_1;
    // 0x801ABD84: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    skip_1:
    // 0x801ABD88: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801ABD8C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801ABD90: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801ABD94: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x801ABD98: nop

    // 0x801ABD9C: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801ABDA0: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x801ABDA4: nop

    // 0x801ABDA8: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x801ABDAC: bne         $t4, $zero, L_801ABDC4
    if (ctx->r12 != 0) {
        // 0x801ABDB0: nop
    
            goto L_801ABDC4;
    }
    // 0x801ABDB0: nop

    // 0x801ABDB4: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x801ABDB8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801ABDBC: b           L_801ABDDC
    // 0x801ABDC0: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
        goto L_801ABDDC;
    // 0x801ABDC0: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
L_801ABDC4:
    // 0x801ABDC4: b           L_801ABDDC
    // 0x801ABDC8: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
        goto L_801ABDDC;
    // 0x801ABDC8: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x801ABDCC: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
L_801ABDD0:
    // 0x801ABDD0: nop

    // 0x801ABDD4: bltz        $t4, L_801ABDC4
    if (SIGNED(ctx->r12) < 0) {
        // 0x801ABDD8: nop
    
            goto L_801ABDC4;
    }
    // 0x801ABDD8: nop

L_801ABDDC:
    // 0x801ABDDC: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x801ABDE0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801ABDE4: lwc1        $f8, 0x50($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X50);
    // 0x801ABDE8: andi        $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 & 0XFF;
    // 0x801ABDEC: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x801ABDF0: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x801ABDF4: sll         $t6, $t5, 8
    ctx->r14 = S32(ctx->r13 << 8);
    // 0x801ABDF8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801ABDFC: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x801ABE00: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x801ABE04: nop

    // 0x801ABE08: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x801ABE0C: beql        $t8, $zero, L_801ABE5C
    if (ctx->r24 == 0) {
        // 0x801ABE10: mfc1        $t8, $f10
        ctx->r24 = (int32_t)ctx->f10.u32l;
            goto L_801ABE5C;
    }
    goto skip_2;
    // 0x801ABE10: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    skip_2:
    // 0x801ABE14: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801ABE18: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801ABE1C: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x801ABE20: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x801ABE24: nop

    // 0x801ABE28: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x801ABE2C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x801ABE30: nop

    // 0x801ABE34: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x801ABE38: bne         $t8, $zero, L_801ABE50
    if (ctx->r24 != 0) {
        // 0x801ABE3C: nop
    
            goto L_801ABE50;
    }
    // 0x801ABE3C: nop

    // 0x801ABE40: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x801ABE44: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801ABE48: b           L_801ABE68
    // 0x801ABE4C: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_801ABE68;
    // 0x801ABE4C: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_801ABE50:
    // 0x801ABE50: b           L_801ABE68
    // 0x801ABE54: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_801ABE68;
    // 0x801ABE54: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x801ABE58: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
L_801ABE5C:
    // 0x801ABE5C: nop

    // 0x801ABE60: bltz        $t8, L_801ABE50
    if (SIGNED(ctx->r24) < 0) {
        // 0x801ABE64: nop
    
            goto L_801ABE50;
    }
    // 0x801ABE64: nop

L_801ABE68:
    // 0x801ABE68: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x801ABE6C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801ABE70: lwc1        $f16, 0x54($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X54);
    // 0x801ABE74: sll         $t1, $t8, 24
    ctx->r9 = S32(ctx->r24 << 24);
    // 0x801ABE78: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x801ABE7C: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x801ABE80: or          $t2, $t6, $t1
    ctx->r10 = ctx->r14 | ctx->r9;
    // 0x801ABE84: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801ABE88: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x801ABE8C: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x801ABE90: nop

    // 0x801ABE94: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x801ABE98: beql        $t4, $zero, L_801ABEE8
    if (ctx->r12 == 0) {
        // 0x801ABE9C: mfc1        $t4, $f18
        ctx->r12 = (int32_t)ctx->f18.u32l;
            goto L_801ABEE8;
    }
    goto skip_3;
    // 0x801ABE9C: mfc1        $t4, $f18
    ctx->r12 = (int32_t)ctx->f18.u32l;
    skip_3:
    // 0x801ABEA0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801ABEA4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801ABEA8: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x801ABEAC: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x801ABEB0: nop

    // 0x801ABEB4: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x801ABEB8: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x801ABEBC: nop

    // 0x801ABEC0: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x801ABEC4: bne         $t4, $zero, L_801ABEDC
    if (ctx->r12 != 0) {
        // 0x801ABEC8: nop
    
            goto L_801ABEDC;
    }
    // 0x801ABEC8: nop

    // 0x801ABECC: mfc1        $t4, $f18
    ctx->r12 = (int32_t)ctx->f18.u32l;
    // 0x801ABED0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801ABED4: b           L_801ABEF4
    // 0x801ABED8: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
        goto L_801ABEF4;
    // 0x801ABED8: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
L_801ABEDC:
    // 0x801ABEDC: b           L_801ABEF4
    // 0x801ABEE0: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
        goto L_801ABEF4;
    // 0x801ABEE0: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x801ABEE4: mfc1        $t4, $f18
    ctx->r12 = (int32_t)ctx->f18.u32l;
L_801ABEE8:
    // 0x801ABEE8: nop

    // 0x801ABEEC: bltz        $t4, L_801ABEDC
    if (SIGNED(ctx->r12) < 0) {
        // 0x801ABEF0: nop
    
            goto L_801ABEDC;
    }
    // 0x801ABEF0: nop

L_801ABEF4:
    // 0x801ABEF4: andi        $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 & 0XFF;
    // 0x801ABEF8: sll         $t7, $t5, 16
    ctx->r15 = S32(ctx->r13 << 16);
    // 0x801ABEFC: or          $t8, $t2, $t7
    ctx->r24 = ctx->r10 | ctx->r15;
    // 0x801ABF00: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x801ABF04: ori         $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 | 0XFF;
    // 0x801ABF08: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x801ABF0C: b           L_801AC094
    // 0x801ABF10: addiu       $t5, $a2, -0x9
    ctx->r13 = ADD32(ctx->r6, -0X9);
        goto L_801AC094;
    // 0x801ABF10: addiu       $t5, $a2, -0x9
    ctx->r13 = ADD32(ctx->r6, -0X9);
L_801ABF14:
    // 0x801ABF14: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801ABF18: bne         $a2, $at, L_801ABF28
    if (ctx->r6 != ctx->r1) {
        // 0x801ABF1C: addiu       $t6, $zero, 0x5
        ctx->r14 = ADD32(0, 0X5);
            goto L_801ABF28;
    }
    // 0x801ABF1C: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x801ABF20: b           L_801ABF60
    // 0x801ABF24: sh          $t6, 0x62($sp)
    MEM_H(0X62, ctx->r29) = ctx->r14;
        goto L_801ABF60;
    // 0x801ABF24: sh          $t6, 0x62($sp)
    MEM_H(0X62, ctx->r29) = ctx->r14;
L_801ABF28:
    // 0x801ABF28: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801ABF2C: bne         $a2, $at, L_801ABF3C
    if (ctx->r6 != ctx->r1) {
        // 0x801ABF30: addiu       $t1, $zero, 0x6
        ctx->r9 = ADD32(0, 0X6);
            goto L_801ABF3C;
    }
    // 0x801ABF30: addiu       $t1, $zero, 0x6
    ctx->r9 = ADD32(0, 0X6);
    // 0x801ABF34: b           L_801ABF60
    // 0x801ABF38: sh          $t1, 0x62($sp)
    MEM_H(0X62, ctx->r29) = ctx->r9;
        goto L_801ABF60;
    // 0x801ABF38: sh          $t1, 0x62($sp)
    MEM_H(0X62, ctx->r29) = ctx->r9;
L_801ABF3C:
    // 0x801ABF3C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x801ABF40: bne         $a2, $at, L_801ABF50
    if (ctx->r6 != ctx->r1) {
        // 0x801ABF44: addiu       $t3, $zero, 0x7
        ctx->r11 = ADD32(0, 0X7);
            goto L_801ABF50;
    }
    // 0x801ABF44: addiu       $t3, $zero, 0x7
    ctx->r11 = ADD32(0, 0X7);
    // 0x801ABF48: b           L_801ABF60
    // 0x801ABF4C: sh          $t3, 0x62($sp)
    MEM_H(0X62, ctx->r29) = ctx->r11;
        goto L_801ABF60;
    // 0x801ABF4C: sh          $t3, 0x62($sp)
    MEM_H(0X62, ctx->r29) = ctx->r11;
L_801ABF50:
    // 0x801ABF50: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x801ABF54: bne         $a2, $at, L_801ABF60
    if (ctx->r6 != ctx->r1) {
        // 0x801ABF58: addiu       $t4, $zero, 0x8
        ctx->r12 = ADD32(0, 0X8);
            goto L_801ABF60;
    }
    // 0x801ABF58: addiu       $t4, $zero, 0x8
    ctx->r12 = ADD32(0, 0X8);
    // 0x801ABF5C: sh          $t4, 0x62($sp)
    MEM_H(0X62, ctx->r29) = ctx->r12;
L_801ABF60:
    // 0x801ABF60: lh          $t5, 0x62($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X62);
    // 0x801ABF64: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x801ABF68: sll         $t2, $t5, 1
    ctx->r10 = S32(ctx->r13 << 1);
    // 0x801ABF6C: addu        $t7, $t7, $t2
    ctx->r15 = ADD32(ctx->r15, ctx->r10);
    // 0x801ABF70: lh          $t7, -0x1CE0($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X1CE0);
    // 0x801ABF74: bne         $t7, $zero, L_801ABF88
    if (ctx->r15 != 0) {
        // 0x801ABF78: nop
    
            goto L_801ABF88;
    }
    // 0x801ABF78: nop

    // 0x801ABF7C: lw          $t8, 0x6C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X6C);
    // 0x801ABF80: b           L_801AC090
    // 0x801ABF84: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
        goto L_801AC090;
    // 0x801ABF84: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
L_801ABF88:
    // 0x801ABF88: jal         0x800BA5B0
    // 0x801ABF8C: nop

    RCP_SetupDL_49(rdram, ctx);
        goto after_2;
    // 0x801ABF8C: nop

    after_2:
    // 0x801ABF90: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801ABF94: lui         $t1, 0xB4C8
    ctx->r9 = S32(0XB4C8 << 16);
    // 0x801ABF98: ori         $t1, $t1, 0xFFFF
    ctx->r9 = ctx->r9 | 0XFFFF;
    // 0x801ABF9C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x801ABFA0: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x801ABFA4: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x801ABFA8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x801ABFAC: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x801ABFB0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801ABFB4: lui         $t5, 0x1020
    ctx->r13 = S32(0X1020 << 16);
    // 0x801ABFB8: ori         $t5, $t5, 0xFFFF
    ctx->r13 = ctx->r13 | 0XFFFF;
    // 0x801ABFBC: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x801ABFC0: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x801ABFC4: lui         $t4, 0xFB00
    ctx->r12 = S32(0XFB00 << 16);
    // 0x801ABFC8: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x801ABFCC: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x801ABFD0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801ABFD4: lui         $t7, 0xB600
    ctx->r15 = S32(0XB600 << 16);
    // 0x801ABFD8: addiu       $t8, $zero, 0x2000
    ctx->r24 = ADD32(0, 0X2000);
    // 0x801ABFDC: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x801ABFE0: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x801ABFE4: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x801ABFE8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801ABFEC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801ABFF0: jal         0x80005708
    // 0x801ABFF4: addiu       $a0, $a0, -0x4438
    ctx->r4 = ADD32(ctx->r4, -0X4438);
    Matrix_Push(rdram, ctx);
        goto after_3;
    // 0x801ABFF4: addiu       $a0, $a0, -0x4438
    ctx->r4 = ADD32(ctx->r4, -0X4438);
    after_3:
    // 0x801ABFF8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801ABFFC: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x801AC000: lw          $a1, -0x4438($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X4438);
    // 0x801AC004: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x801AC008: jal         0x80005754
    // 0x801AC00C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_Mult(rdram, ctx);
        goto after_4;
    // 0x801AC00C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
    // 0x801AC010: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801AC014: jal         0x80005708
    // 0x801AC018: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Push(rdram, ctx);
        goto after_5;
    // 0x801AC018: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_5:
    // 0x801AC01C: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x801AC020: addiu       $t0, $t0, -0x1C98
    ctx->r8 = ADD32(ctx->r8, -0X1C98);
    // 0x801AC024: lwc1        $f0, 0x7C($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X7C);
    // 0x801AC028: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801AC02C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801AC030: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801AC034: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x801AC038: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x801AC03C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x801AC040: jal         0x80005C34
    // 0x801AC044: lw          $a2, 0x78($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X78);
    Matrix_Scale(rdram, ctx);
        goto after_6;
    // 0x801AC044: lw          $a2, 0x78($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X78);
    after_6:
    // 0x801AC048: jal         0x80006EB8
    // 0x801AC04C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_7;
    // 0x801AC04C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x801AC050: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801AC054: lui         $t1, 0x600
    ctx->r9 = S32(0X600 << 16);
    // 0x801AC058: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801AC05C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801AC060: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x801AC064: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x801AC068: lw          $t3, 0x6C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X6C);
    // 0x801AC06C: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x801AC070: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x801AC074: jal         0x80005740
    // 0x801AC078: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Pop(rdram, ctx);
        goto after_8;
    // 0x801AC078: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_8:
    // 0x801AC07C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801AC080: jal         0x80005740
    // 0x801AC084: addiu       $a0, $a0, -0x4438
    ctx->r4 = ADD32(ctx->r4, -0X4438);
    Matrix_Pop(rdram, ctx);
        goto after_9;
    // 0x801AC084: addiu       $a0, $a0, -0x4438
    ctx->r4 = ADD32(ctx->r4, -0X4438);
    after_9:
    // 0x801AC088: b           L_801AC1AC
    // 0x801AC08C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801AC1AC;
    // 0x801AC08C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801AC090:
    // 0x801AC090: addiu       $t5, $a2, -0x9
    ctx->r13 = ADD32(ctx->r6, -0X9);
L_801AC094:
    // 0x801AC094: sltiu       $at, $t5, 0xC
    ctx->r1 = ctx->r13 < 0XC ? 1 : 0;
    // 0x801AC098: beq         $at, $zero, L_801AC168
    if (ctx->r1 == 0) {
        // 0x801AC09C: sll         $t5, $t5, 2
        ctx->r13 = S32(ctx->r13 << 2);
            goto L_801AC168;
    }
    // 0x801AC09C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x801AC0A0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801AC0A4: addu        $at, $at, $t5
    gpr jr_addend_801AC0AC = ctx->r13;
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x801AC0A8: lw          $t5, -0x4650($at)
    ctx->r13 = ADD32(ctx->r1, -0X4650);
    // 0x801AC0AC: jr          $t5
    // 0x801AC0B0: nop

    switch (jr_addend_801AC0AC >> 2) {
        case 0: goto L_801AC110; break;
        case 1: goto L_801AC110; break;
        case 2: goto L_801AC110; break;
        case 3: goto L_801AC110; break;
        case 4: goto L_801AC168; break;
        case 5: goto L_801AC0B4; break;
        case 6: goto L_801AC168; break;
        case 7: goto L_801AC168; break;
        case 8: goto L_801AC168; break;
        case 9: goto L_801AC110; break;
        case 10: goto L_801AC110; break;
        case 11: goto L_801AC110; break;
        default: switch_error(__func__, 0x801AC0AC, 0x801BB9B0);
    }
    // 0x801AC0B0: nop

L_801AC0B4:
    // 0x801AC0B4: lw          $t2, 0x78($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X78);
    // 0x801AC0B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801AC0BC: lw          $t7, 0x6C($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X6C);
    // 0x801AC0C0: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x801AC0C4: beq         $t8, $zero, L_801AC0F4
    if (ctx->r24 == 0) {
        // 0x801AC0C8: nop
    
            goto L_801AC0F4;
    }
    // 0x801AC0C8: nop

    // 0x801AC0CC: jal         0x800B8DD0
    // 0x801AC0D0: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    RCP_SetupDL(rdram, ctx);
        goto after_10;
    // 0x801AC0D0: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    after_10:
    // 0x801AC0D4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801AC0D8: lui         $t1, 0xFF00
    ctx->r9 = S32(0XFF00 << 16);
    // 0x801AC0DC: ori         $t1, $t1, 0xFF
    ctx->r9 = ctx->r9 | 0XFF;
    // 0x801AC0E0: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x801AC0E4: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x801AC0E8: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x801AC0EC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x801AC0F0: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
L_801AC0F4:
    // 0x801AC0F4: lui         $t3, 0x801C
    ctx->r11 = S32(0X801C << 16);
    // 0x801AC0F8: lh          $t3, -0x1CCE($t3)
    ctx->r11 = MEM_H(ctx->r11, -0X1CCE);
    // 0x801AC0FC: lw          $t4, 0x6C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X6C);
    // 0x801AC100: bgtzl       $t3, L_801AC16C
    if (SIGNED(ctx->r11) > 0) {
        // 0x801AC104: lw          $t4, 0x78($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X78);
            goto L_801AC16C;
    }
    goto skip_4;
    // 0x801AC104: lw          $t4, 0x78($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X78);
    skip_4:
    // 0x801AC108: b           L_801AC168
    // 0x801AC10C: sw          $zero, 0x0($t4)
    MEM_W(0X0, ctx->r12) = 0;
        goto L_801AC168;
    // 0x801AC10C: sw          $zero, 0x0($t4)
    MEM_W(0X0, ctx->r12) = 0;
L_801AC110:
    // 0x801AC110: lw          $t5, 0x78($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X78);
    // 0x801AC114: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801AC118: lw          $t2, 0x70($t5)
    ctx->r10 = MEM_W(ctx->r13, 0X70);
    // 0x801AC11C: andi        $t7, $t2, 0x1
    ctx->r15 = ctx->r10 & 0X1;
    // 0x801AC120: beq         $t7, $zero, L_801AC150
    if (ctx->r15 == 0) {
        // 0x801AC124: nop
    
            goto L_801AC150;
    }
    // 0x801AC124: nop

    // 0x801AC128: jal         0x800B8DD0
    // 0x801AC12C: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    RCP_SetupDL(rdram, ctx);
        goto after_11;
    // 0x801AC12C: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    after_11:
    // 0x801AC130: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801AC134: lui         $t6, 0xFF00
    ctx->r14 = S32(0XFF00 << 16);
    // 0x801AC138: ori         $t6, $t6, 0xFF
    ctx->r14 = ctx->r14 | 0XFF;
    // 0x801AC13C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x801AC140: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x801AC144: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x801AC148: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x801AC14C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
L_801AC150:
    // 0x801AC150: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x801AC154: lh          $t1, -0x1CCC($t1)
    ctx->r9 = MEM_H(ctx->r9, -0X1CCC);
    // 0x801AC158: lw          $t3, 0x6C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X6C);
    // 0x801AC15C: bgtzl       $t1, L_801AC16C
    if (SIGNED(ctx->r9) > 0) {
        // 0x801AC160: lw          $t4, 0x78($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X78);
            goto L_801AC16C;
    }
    goto skip_5;
    // 0x801AC160: lw          $t4, 0x78($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X78);
    skip_5:
    // 0x801AC164: sw          $zero, 0x0($t3)
    MEM_W(0X0, ctx->r11) = 0;
L_801AC168:
    // 0x801AC168: lw          $t4, 0x78($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X78);
L_801AC16C:
    // 0x801AC16C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801AC170: lw          $t5, 0x74($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X74);
    // 0x801AC174: andi        $t2, $t5, 0x1
    ctx->r10 = ctx->r13 & 0X1;
    // 0x801AC178: beql        $t2, $zero, L_801AC1AC
    if (ctx->r10 == 0) {
        // 0x801AC17C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801AC1AC;
    }
    goto skip_6;
    // 0x801AC17C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_6:
    // 0x801AC180: jal         0x800B8DD0
    // 0x801AC184: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    RCP_SetupDL(rdram, ctx);
        goto after_12;
    // 0x801AC184: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    after_12:
    // 0x801AC188: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801AC18C: lui         $t9, 0xFF00
    ctx->r25 = S32(0XFF00 << 16);
    // 0x801AC190: ori         $t9, $t9, 0xFF
    ctx->r25 = ctx->r25 | 0XFF;
    // 0x801AC194: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801AC198: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x801AC19C: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x801AC1A0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x801AC1A4: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x801AC1A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801AC1AC:
    // 0x801AC1AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801AC1B0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801AC1B4: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x801AC1B8: jr          $ra
    // 0x801AC1BC: nop

    return;
    // 0x801AC1BC: nop

;}
RECOMP_FUNC void Macbeth_801A72DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A72DC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801A72E0: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x801A72E4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x801A72E8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801A72EC: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x801A72F0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801A72F4: lw          $a1, 0xC($s1)
    ctx->r5 = MEM_W(ctx->r17, 0XC);
    // 0x801A72F8: lw          $a2, 0x14($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X14);
    // 0x801A72FC: jal         0x801A0308
    // 0x801A7300: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    Macbeth_801A0308(rdram, ctx);
        goto after_0;
    // 0x801A7300: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x801A7304: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801A7308: lh          $v0, -0x1CE0($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X1CE0);
    // 0x801A730C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801A7310: beq         $v0, $zero, L_801A7330
    if (ctx->r2 == 0) {
        // 0x801A7314: nop
    
            goto L_801A7330;
    }
    // 0x801A7314: nop

    // 0x801A7318: beq         $v0, $at, L_801A73AC
    if (ctx->r2 == ctx->r1) {
        // 0x801A731C: lui         $s0, 0x801C
        ctx->r16 = S32(0X801C << 16);
            goto L_801A73AC;
    }
    // 0x801A731C: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x801A7320: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801A7324: lwc1        $f2, -0x1C94($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X1C94);
    // 0x801A7328: b           L_801A741C
    // 0x801A732C: addiu       $s0, $s0, -0x1C98
    ctx->r16 = ADD32(ctx->r16, -0X1C98);
        goto L_801A741C;
    // 0x801A732C: addiu       $s0, $s0, -0x1C98
    ctx->r16 = ADD32(ctx->r16, -0X1C98);
L_801A7330:
    // 0x801A7330: jal         0x80004EB0
    // 0x801A7334: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x801A7334: nop

    after_1:
    // 0x801A7338: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801A733C: lwc1        $f4, -0x48E8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X48E8);
    // 0x801A7340: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801A7344: lwc1        $f8, -0x48E4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X48E4);
    // 0x801A7348: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x801A734C: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x801A7350: addiu       $s0, $s0, -0x1C98
    ctx->r16 = ADD32(ctx->r16, -0X1C98);
    // 0x801A7354: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x801A7358: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x801A735C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801A7360: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801A7364: lui         $a1, 0x40A0
    ctx->r5 = S32(0X40A0 << 16);
    // 0x801A7368: jal         0x8009BC2C
    // 0x801A736C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_2;
    // 0x801A736C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x801A7370: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801A7374: lwc1        $f16, 0x0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X0);
    // 0x801A7378: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x801A737C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801A7380: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801A7384: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801A7388: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801A738C: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
    // 0x801A7390: lwc1        $f2, 0x4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801A7394: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x801A7398: nop

    // 0x801A739C: bc1fl       L_801A7420
    if (!c1cs) {
        // 0x801A73A0: lwc1        $f8, 0x160($s1)
        ctx->f8.u32l = MEM_W(ctx->r17, 0X160);
            goto L_801A7420;
    }
    goto skip_0;
    // 0x801A73A0: lwc1        $f8, 0x160($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X160);
    skip_0:
    // 0x801A73A4: b           L_801A741C
    // 0x801A73A8: sh          $t6, -0x1CE0($at)
    MEM_H(-0X1CE0, ctx->r1) = ctx->r14;
        goto L_801A741C;
    // 0x801A73A8: sh          $t6, -0x1CE0($at)
    MEM_H(-0X1CE0, ctx->r1) = ctx->r14;
L_801A73AC:
    // 0x801A73AC: jal         0x80004EB0
    // 0x801A73B0: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_3;
    // 0x801A73B0: nop

    after_3:
    // 0x801A73B4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801A73B8: lwc1        $f6, -0x48E0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X48E0);
    // 0x801A73BC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801A73C0: lwc1        $f10, -0x48DC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X48DC);
    // 0x801A73C4: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x801A73C8: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x801A73CC: addiu       $s0, $s0, -0x1C98
    ctx->r16 = ADD32(ctx->r16, -0X1C98);
    // 0x801A73D0: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x801A73D4: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x801A73D8: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801A73DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801A73E0: lui         $a1, 0xC0A0
    ctx->r5 = S32(0XC0A0 << 16);
    // 0x801A73E4: jal         0x8009BC2C
    // 0x801A73E8: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_4;
    // 0x801A73E8: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_4:
    // 0x801A73EC: lwc1        $f16, 0x4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801A73F0: lwc1        $f18, 0x0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X0);
    // 0x801A73F4: lui         $at, 0xC2C8
    ctx->r1 = S32(0XC2C8 << 16);
    // 0x801A73F8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801A73FC: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x801A7400: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x801A7404: lwc1        $f2, 0x4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801A7408: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x801A740C: nop

    // 0x801A7410: bc1f        L_801A741C
    if (!c1cs) {
        // 0x801A7414: lui         $at, 0x801C
        ctx->r1 = S32(0X801C << 16);
            goto L_801A741C;
    }
    // 0x801A7414: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801A7418: sh          $zero, -0x1CE0($at)
    MEM_H(-0X1CE0, ctx->r1) = 0;
L_801A741C:
    // 0x801A741C: lwc1        $f8, 0x160($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X160);
L_801A7420:
    // 0x801A7420: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801A7424: lwc1        $f16, -0x48D8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X48D8);
    // 0x801A7428: add.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f8.fl;
    // 0x801A742C: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x801A7430: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801A7434: addiu       $a0, $s1, 0x4
    ctx->r4 = ADD32(ctx->r17, 0X4);
    // 0x801A7438: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x801A743C: lui         $a3, 0x41F0
    ctx->r7 = S32(0X41F0 << 16);
    // 0x801A7440: jal         0x8009BC2C
    // 0x801A7444: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_5;
    // 0x801A7444: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_5:
    // 0x801A7448: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x801A744C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801A7450: lwc1        $f18, 0x128($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X128);
    // 0x801A7454: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801A7458: lwc1        $f8, -0x48D4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X48D4);
    // 0x801A745C: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x801A7460: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x801A7464: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801A7468: addiu       $a0, $s1, 0x8
    ctx->r4 = ADD32(ctx->r17, 0X8);
    // 0x801A746C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x801A7470: lui         $a3, 0x41F0
    ctx->r7 = S32(0X41F0 << 16);
    // 0x801A7474: jal         0x8009BC2C
    // 0x801A7478: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_6;
    // 0x801A7478: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_6:
    // 0x801A747C: lui         $at, 0x4496
    ctx->r1 = S32(0X4496 << 16);
    // 0x801A7480: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801A7484: lwc1        $f10, 0x18($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X18);
    // 0x801A7488: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801A748C: lwc1        $f4, -0x48D0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X48D0);
    // 0x801A7490: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801A7494: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x801A7498: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801A749C: addiu       $a0, $s1, 0xC
    ctx->r4 = ADD32(ctx->r17, 0XC);
    // 0x801A74A0: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x801A74A4: lui         $a3, 0x41F0
    ctx->r7 = S32(0X41F0 << 16);
    // 0x801A74A8: jal         0x8009BC2C
    // 0x801A74AC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_7;
    // 0x801A74AC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_7:
    // 0x801A74B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801A74B4: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x801A74B8: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x801A74BC: jr          $ra
    // 0x801A74C0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x801A74C0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void Macbeth_MaCannonCar_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019FF9C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8019FFA0: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8019FFA4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8019FFA8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8019FFAC: lh          $v0, 0xB8($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XB8);
    // 0x8019FFB0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8019FFB4: beq         $v0, $zero, L_8019FFE0
    if (ctx->r2 == 0) {
        // 0x8019FFB8: nop
    
            goto L_8019FFE0;
    }
    // 0x8019FFB8: nop

    // 0x8019FFBC: beq         $v0, $at, L_801A0050
    if (ctx->r2 == ctx->r1) {
        // 0x8019FFC0: lui         $v1, 0x801C
        ctx->r3 = S32(0X801C << 16);
            goto L_801A0050;
    }
    // 0x8019FFC0: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8019FFC4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8019FFC8: beq         $v0, $at, L_801A008C
    if (ctx->r2 == ctx->r1) {
        // 0x8019FFCC: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_801A008C;
    }
    // 0x8019FFCC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8019FFD0: beq         $v0, $at, L_801A0104
    if (ctx->r2 == ctx->r1) {
        // 0x8019FFD4: nop
    
            goto L_801A0104;
    }
    // 0x8019FFD4: nop

    // 0x8019FFD8: b           L_801A014C
    // 0x8019FFDC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_801A014C;
    // 0x8019FFDC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8019FFE0:
    // 0x8019FFE0: jal         0x8019A198
    // 0x8019FFE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Macbeth_TrainCarSpeed_Update(rdram, ctx);
        goto after_0;
    // 0x8019FFE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8019FFE8: jal         0x801A015C
    // 0x8019FFEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Macbeth_801A015C(rdram, ctx);
        goto after_1;
    // 0x8019FFEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8019FFF0: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x8019FFF4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8019FFF8: lwc1        $f4, 0x178($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X178);
    // 0x8019FFFC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801A0000: addiu       $t7, $s0, 0x84
    ctx->r15 = ADD32(ctx->r16, 0X84);
    // 0x801A0004: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x801A0008: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801A000C: addiu       $a1, $s0, 0x78
    ctx->r5 = ADD32(ctx->r16, 0X78);
    // 0x801A0010: addiu       $a2, $s0, 0x7C
    ctx->r6 = ADD32(ctx->r16, 0X7C);
    // 0x801A0014: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801A0018: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x801A001C: jal         0x8019FC54
    // 0x801A0020: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    Macbeth_8019FC54(rdram, ctx);
        goto after_2;
    // 0x801A0020: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x801A0024: jal         0x8019A728
    // 0x801A0028: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Macbeth_8019A728(rdram, ctx);
        goto after_3;
    // 0x801A0028: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x801A002C: lw          $t8, 0x54($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X54);
    // 0x801A0030: beq         $t8, $zero, L_801A0040
    if (ctx->r24 == 0) {
        // 0x801A0034: nop
    
            goto L_801A0040;
    }
    // 0x801A0034: nop

    // 0x801A0038: jal         0x8019F164
    // 0x801A003C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Macbeth_8019F164(rdram, ctx);
        goto after_4;
    // 0x801A003C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
L_801A0040:
    // 0x801A0040: jal         0x8019A830
    // 0x801A0044: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Macbeth_8019A830(rdram, ctx);
        goto after_5;
    // 0x801A0044: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x801A0048: b           L_801A014C
    // 0x801A004C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_801A014C;
    // 0x801A004C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_801A0050:
    // 0x801A0050: addiu       $v1, $v1, -0x1D10
    ctx->r3 = ADD32(ctx->r3, -0X1D10);
    // 0x801A0054: lh          $t9, 0x6($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X6);
    // 0x801A0058: lw          $v0, 0x64($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X64);
    // 0x801A005C: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x801A0060: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801A0064: slt         $at, $v0, $t9
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x801A0068: beq         $at, $zero, L_801A0074
    if (ctx->r1 == 0) {
        // 0x801A006C: nop
    
            goto L_801A0074;
    }
    // 0x801A006C: nop

    // 0x801A0070: sh          $v0, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r2;
L_801A0074:
    // 0x801A0074: jal         0x801A015C
    // 0x801A0078: sh          $t0, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r8;
    Macbeth_801A015C(rdram, ctx);
        goto after_6;
    // 0x801A0078: sh          $t0, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r8;
    after_6:
    // 0x801A007C: jal         0x8019A830
    // 0x801A0080: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Macbeth_8019A830(rdram, ctx);
        goto after_7;
    // 0x801A0080: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x801A0084: b           L_801A014C
    // 0x801A0088: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_801A014C;
    // 0x801A0088: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_801A008C:
    // 0x801A008C: jal         0x8019BBEC
    // 0x801A0090: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Macbeth_8019BBEC(rdram, ctx);
        goto after_8;
    // 0x801A0090: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x801A0094: lhu         $t1, 0xBC($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0XBC);
    // 0x801A0098: addiu       $a0, $s0, 0xF0
    ctx->r4 = ADD32(ctx->r16, 0XF0);
    // 0x801A009C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x801A00A0: bne         $t1, $zero, L_801A00B0
    if (ctx->r9 != 0) {
        // 0x801A00A4: lui         $a2, 0x3CA3
        ctx->r6 = S32(0X3CA3 << 16);
            goto L_801A00B0;
    }
    // 0x801A00A4: lui         $a2, 0x3CA3
    ctx->r6 = S32(0X3CA3 << 16);
    // 0x801A00A8: addiu       $t2, $zero, 0x3C
    ctx->r10 = ADD32(0, 0X3C);
    // 0x801A00AC: sh          $t2, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r10;
L_801A00B0:
    // 0x801A00B0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801A00B4: lwc1        $f8, -0x4B84($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4B84);
    // 0x801A00B8: ori         $a2, $a2, 0xD70A
    ctx->r6 = ctx->r6 | 0XD70A;
    // 0x801A00BC: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x801A00C0: jal         0x8009BC2C
    // 0x801A00C4: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_9;
    // 0x801A00C4: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_9:
    // 0x801A00C8: jal         0x801A015C
    // 0x801A00CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Macbeth_801A015C(rdram, ctx);
        goto after_10;
    // 0x801A00CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x801A00D0: jal         0x8019A87C
    // 0x801A00D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Macbeth_8019A87C(rdram, ctx);
        goto after_11;
    // 0x801A00D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x801A00D8: lb          $t3, 0xD0($s0)
    ctx->r11 = MEM_B(ctx->r16, 0XD0);
    // 0x801A00DC: addiu       $t4, $zero, 0x14
    ctx->r12 = ADD32(0, 0X14);
    // 0x801A00E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801A00E4: beql        $t3, $zero, L_801A014C
    if (ctx->r11 == 0) {
        // 0x801A00E8: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_801A014C;
    }
    goto skip_0;
    // 0x801A00E8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x801A00EC: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
    // 0x801A00F0: jal         0x8019BE50
    // 0x801A00F4: sh          $t4, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r12;
    Macbeth_8019BE50(rdram, ctx);
        goto after_12;
    // 0x801A00F4: sh          $t4, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r12;
    after_12:
    // 0x801A00F8: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x801A00FC: b           L_801A0148
    // 0x801A0100: sh          $t5, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r13;
        goto L_801A0148;
    // 0x801A0100: sh          $t5, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r13;
L_801A0104:
    // 0x801A0104: jal         0x801A015C
    // 0x801A0108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Macbeth_801A015C(rdram, ctx);
        goto after_13;
    // 0x801A0108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x801A010C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801A0110: lwc1        $f10, -0x4B80($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X4B80);
    // 0x801A0114: lui         $a2, 0x3CA3
    ctx->r6 = S32(0X3CA3 << 16);
    // 0x801A0118: ori         $a2, $a2, 0xD70A
    ctx->r6 = ctx->r6 | 0XD70A;
    // 0x801A011C: addiu       $a0, $s0, 0x110
    ctx->r4 = ADD32(ctx->r16, 0X110);
    // 0x801A0120: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x801A0124: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x801A0128: jal         0x8009BC2C
    // 0x801A012C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_14;
    // 0x801A012C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_14:
    // 0x801A0130: lhu         $t6, 0xBC($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0XBC);
    // 0x801A0134: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801A0138: bgtzl       $t6, L_801A014C
    if (SIGNED(ctx->r14) > 0) {
        // 0x801A013C: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_801A014C;
    }
    goto skip_1;
    // 0x801A013C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_1:
    // 0x801A0140: jal         0x80060FBC
    // 0x801A0144: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    Object_Kill(rdram, ctx);
        goto after_15;
    // 0x801A0144: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    after_15:
L_801A0148:
    // 0x801A0148: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_801A014C:
    // 0x801A014C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x801A0150: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801A0154: jr          $ra
    // 0x801A0158: nop

    return;
    // 0x801A0158: nop

;}
RECOMP_FUNC void Titania_TiRasco_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018B268: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8018B26C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8018B270: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8018B274: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8018B278: lb          $t6, 0xD0($s0)
    ctx->r14 = MEM_B(ctx->r16, 0XD0);
    // 0x8018B27C: lw          $v1, 0x50($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X50);
    // 0x8018B280: lw          $t0, 0x54($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X54);
    // 0x8018B284: blezl       $t6, L_8018B2E8
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8018B288: lh          $a0, 0xB8($s0)
        ctx->r4 = MEM_H(ctx->r16, 0XB8);
            goto L_8018B2E8;
    }
    goto skip_0;
    // 0x8018B288: lh          $a0, 0xB8($s0)
    ctx->r4 = MEM_H(ctx->r16, 0XB8);
    skip_0:
    // 0x8018B28C: lh          $v0, 0xCE($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XCE);
    // 0x8018B290: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
    // 0x8018B294: blezl       $v0, L_8018B2E0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8018B298: addiu       $t2, $zero, 0xA
        ctx->r10 = ADD32(0, 0XA);
            goto L_8018B2E0;
    }
    goto skip_1;
    // 0x8018B298: addiu       $t2, $zero, 0xA
    ctx->r10 = ADD32(0, 0XA);
    skip_1:
    // 0x8018B29C: lhu         $t7, 0xD6($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0XD6);
    // 0x8018B2A0: andi        $t1, $zero, 0xFF
    ctx->r9 = 0 & 0XFF;
    // 0x8018B2A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018B2A8: subu        $t8, $v0, $t7
    ctx->r24 = SUB32(ctx->r2, ctx->r15);
    // 0x8018B2AC: sh          $t8, 0xCE($s0)
    MEM_H(0XCE, ctx->r16) = ctx->r24;
    // 0x8018B2B0: lh          $t9, 0xCE($s0)
    ctx->r25 = MEM_H(ctx->r16, 0XCE);
    // 0x8018B2B4: bgtzl       $t9, L_8018B2E0
    if (SIGNED(ctx->r25) > 0) {
        // 0x8018B2B8: addiu       $t2, $zero, 0xA
        ctx->r10 = ADD32(0, 0XA);
            goto L_8018B2E0;
    }
    goto skip_2;
    // 0x8018B2B8: addiu       $t2, $zero, 0xA
    ctx->r10 = ADD32(0, 0XA);
    skip_2:
    // 0x8018B2BC: sb          $zero, 0x44($s0)
    MEM_B(0X44, ctx->r16) = 0;
    // 0x8018B2C0: sh          $t1, 0xCE($s0)
    MEM_H(0XCE, ctx->r16) = ctx->r9;
    // 0x8018B2C4: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    // 0x8018B2C8: jal         0x80066254
    // 0x8018B2CC: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    Actor_Despawn(rdram, ctx);
        goto after_0;
    // 0x8018B2CC: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8018B2D0: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x8018B2D4: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8018B2D8: sb          $zero, 0x3C($s0)
    MEM_B(0X3C, ctx->r16) = 0;
    // 0x8018B2DC: addiu       $t2, $zero, 0xA
    ctx->r10 = ADD32(0, 0XA);
L_8018B2E0:
    // 0x8018B2E0: sh          $t2, 0xC6($s0)
    MEM_H(0XC6, ctx->r16) = ctx->r10;
    // 0x8018B2E4: lh          $a0, 0xB8($s0)
    ctx->r4 = MEM_H(ctx->r16, 0XB8);
L_8018B2E8:
    // 0x8018B2E8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8018B2EC: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8018B2F0: beq         $a0, $zero, L_8018B310
    if (ctx->r4 == 0) {
        // 0x8018B2F4: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_8018B310;
    }
    // 0x8018B2F4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8018B2F8: beq         $v0, $at, L_8018B340
    if (ctx->r2 == ctx->r1) {
        // 0x8018B2FC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8018B340;
    }
    // 0x8018B2FC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8018B300: beql        $v0, $at, L_8018B61C
    if (ctx->r2 == ctx->r1) {
        // 0x8018B304: lh          $t3, 0xCE($s0)
        ctx->r11 = MEM_H(ctx->r16, 0XCE);
            goto L_8018B61C;
    }
    goto skip_3;
    // 0x8018B304: lh          $t3, 0xCE($s0)
    ctx->r11 = MEM_H(ctx->r16, 0XCE);
    skip_3:
    // 0x8018B308: b           L_8018B61C
    // 0x8018B30C: lh          $t3, 0xCE($s0)
    ctx->r11 = MEM_H(ctx->r16, 0XCE);
        goto L_8018B61C;
    // 0x8018B30C: lh          $t3, 0xCE($s0)
    ctx->r11 = MEM_H(ctx->r16, 0XCE);
L_8018B310:
    // 0x8018B310: lw          $t3, -0x7D80($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X7D80);
    // 0x8018B314: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8018B318: lwc1        $f10, 0x114($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X114);
    // 0x8018B31C: lwc1        $f4, 0x7C($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X7C);
    // 0x8018B320: addiu       $t4, $a0, 0x1
    ctx->r12 = ADD32(ctx->r4, 0X1);
    // 0x8018B324: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8018B328: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x8018B32C: nop

    // 0x8018B330: bc1fl       L_8018B61C
    if (!c1cs) {
        // 0x8018B334: lh          $t3, 0xCE($s0)
        ctx->r11 = MEM_H(ctx->r16, 0XCE);
            goto L_8018B61C;
    }
    goto skip_4;
    // 0x8018B334: lh          $t3, 0xCE($s0)
    ctx->r11 = MEM_H(ctx->r16, 0XCE);
    skip_4:
    // 0x8018B338: b           L_8018B618
    // 0x8018B33C: sh          $t4, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r12;
        goto L_8018B618;
    // 0x8018B33C: sh          $t4, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r12;
L_8018B340:
    // 0x8018B340: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018B344: lwc1        $f18, -0x53E0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X53E0);
    // 0x8018B348: lwc1        $f16, 0x14($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8018B34C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018B350: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018B354: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8018B358: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    // 0x8018B35C: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    // 0x8018B360: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8018B364: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8018B368: jal         0x80005E90
    // 0x8018B36C: nop

    Matrix_RotateY(rdram, ctx);
        goto after_1;
    // 0x8018B36C: nop

    after_1:
    // 0x8018B370: lh          $v0, 0xB6($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XB6);
    // 0x8018B374: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x8018B378: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8018B37C: slti        $at, $v0, 0x1A
    ctx->r1 = SIGNED(ctx->r2) < 0X1A ? 1 : 0;
    // 0x8018B380: bne         $at, $zero, L_8018B4A4
    if (ctx->r1 != 0) {
        // 0x8018B384: slti        $at, $v0, 0x36
        ctx->r1 = SIGNED(ctx->r2) < 0X36 ? 1 : 0;
            goto L_8018B4A4;
    }
    // 0x8018B384: slti        $at, $v0, 0x36
    ctx->r1 = SIGNED(ctx->r2) < 0X36 ? 1 : 0;
    // 0x8018B388: beql        $at, $zero, L_8018B4A8
    if (ctx->r1 == 0) {
        // 0x8018B38C: slti        $at, $v0, 0x1A
        ctx->r1 = SIGNED(ctx->r2) < 0X1A ? 1 : 0;
            goto L_8018B4A8;
    }
    goto skip_5;
    // 0x8018B38C: slti        $at, $v0, 0x1A
    ctx->r1 = SIGNED(ctx->r2) < 0X1A ? 1 : 0;
    skip_5:
    // 0x8018B390: beq         $v1, $zero, L_8018B4A4
    if (ctx->r3 == 0) {
        // 0x8018B394: addiu       $at, $zero, 0x1A
        ctx->r1 = ADD32(0, 0X1A);
            goto L_8018B4A4;
    }
    // 0x8018B394: addiu       $at, $zero, 0x1A
    ctx->r1 = ADD32(0, 0X1A);
    // 0x8018B398: bnel        $v0, $at, L_8018B3C0
    if (ctx->r2 != ctx->r1) {
        // 0x8018B39C: addiu       $at, $zero, 0x35
        ctx->r1 = ADD32(0, 0X35);
            goto L_8018B3C0;
    }
    goto skip_6;
    // 0x8018B39C: addiu       $at, $zero, 0x35
    ctx->r1 = ADD32(0, 0X35);
    skip_6:
    // 0x8018B3A0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8018B3A4: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x8018B3A8: sh          $t5, 0x46($v1)
    MEM_H(0X46, ctx->r3) = ctx->r13;
    // 0x8018B3AC: swc1        $f0, 0xE8($v1)
    MEM_W(0XE8, ctx->r3) = ctx->f0.u32l;
    // 0x8018B3B0: swc1        $f0, 0xEC($v1)
    MEM_W(0XEC, ctx->r3) = ctx->f0.u32l;
    // 0x8018B3B4: b           L_8018B428
    // 0x8018B3B8: swc1        $f0, 0xF0($v1)
    MEM_W(0XF0, ctx->r3) = ctx->f0.u32l;
        goto L_8018B428;
    // 0x8018B3B8: swc1        $f0, 0xF0($v1)
    MEM_W(0XF0, ctx->r3) = ctx->f0.u32l;
    // 0x8018B3BC: addiu       $at, $zero, 0x35
    ctx->r1 = ADD32(0, 0X35);
L_8018B3C0:
    // 0x8018B3C0: bne         $v0, $at, L_8018B428
    if (ctx->r2 != ctx->r1) {
        // 0x8018B3C4: lui         $a0, 0x8014
        ctx->r4 = S32(0X8014 << 16);
            goto L_8018B428;
    }
    // 0x8018B3C4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018B3C8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8018B3CC: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8018B3D0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018B3D4: swc1        $f6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f6.u32l;
    // 0x8018B3D8: lwc1        $f8, 0x118($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X118);
    // 0x8018B3DC: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    // 0x8018B3E0: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    // 0x8018B3E4: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018B3E8: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x8018B3EC: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // 0x8018B3F0: swc1        $f10, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f10.u32l;
    // 0x8018B3F4: jal         0x80006A20
    // 0x8018B3F8: swc1        $f8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f8.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_2;
    // 0x8018B3F8: swc1        $f8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x8018B3FC: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x8018B400: lwc1        $f16, 0x40($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8018B404: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8018B408: swc1        $f16, 0xE8($v1)
    MEM_W(0XE8, ctx->r3) = ctx->f16.u32l;
    // 0x8018B40C: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8018B410: swc1        $f18, 0xEC($v1)
    MEM_W(0XEC, ctx->r3) = ctx->f18.u32l;
    // 0x8018B414: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8018B418: sh          $zero, 0x46($v1)
    MEM_H(0X46, ctx->r3) = 0;
    // 0x8018B41C: sw          $zero, 0x50($v1)
    MEM_W(0X50, ctx->r3) = 0;
    // 0x8018B420: swc1        $f4, 0xF0($v1)
    MEM_W(0XF0, ctx->r3) = ctx->f4.u32l;
    // 0x8018B424: sw          $zero, 0x50($s0)
    MEM_W(0X50, ctx->r16) = 0;
L_8018B428:
    // 0x8018B428: lwc1        $f6, 0x120($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X120);
    // 0x8018B42C: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8018B430: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018B434: swc1        $f6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f6.u32l;
    // 0x8018B438: lwc1        $f8, 0x124($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X124);
    // 0x8018B43C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018B440: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018B444: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8018B448: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x8018B44C: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // 0x8018B450: swc1        $f16, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f16.u32l;
    // 0x8018B454: lwc1        $f18, 0x128($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X128);
    // 0x8018B458: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    // 0x8018B45C: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    // 0x8018B460: jal         0x80006970
    // 0x8018B464: swc1        $f18, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f18.u32l;
    Matrix_MultVec3f(rdram, ctx);
        goto after_3;
    // 0x8018B464: swc1        $f18, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f18.u32l;
    after_3:
    // 0x8018B468: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8018B46C: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8018B470: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x8018B474: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8018B478: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8018B47C: swc1        $f8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f8.u32l;
    // 0x8018B480: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8018B484: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8018B488: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8018B48C: swc1        $f18, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f18.u32l;
    // 0x8018B490: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8018B494: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8018B498: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8018B49C: swc1        $f8, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f8.u32l;
    // 0x8018B4A0: lh          $v0, 0xB6($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XB6);
L_8018B4A4:
    // 0x8018B4A4: slti        $at, $v0, 0x1A
    ctx->r1 = SIGNED(ctx->r2) < 0X1A ? 1 : 0;
L_8018B4A8:
    // 0x8018B4A8: bne         $at, $zero, L_8018B5E8
    if (ctx->r1 != 0) {
        // 0x8018B4AC: slti        $at, $v0, 0x3A
        ctx->r1 = SIGNED(ctx->r2) < 0X3A ? 1 : 0;
            goto L_8018B5E8;
    }
    // 0x8018B4AC: slti        $at, $v0, 0x3A
    ctx->r1 = SIGNED(ctx->r2) < 0X3A ? 1 : 0;
    // 0x8018B4B0: beql        $at, $zero, L_8018B5EC
    if (ctx->r1 == 0) {
        // 0x8018B4B4: addiu       $t8, $v0, 0x1
        ctx->r24 = ADD32(ctx->r2, 0X1);
            goto L_8018B5EC;
    }
    goto skip_7;
    // 0x8018B4B4: addiu       $t8, $v0, 0x1
    ctx->r24 = ADD32(ctx->r2, 0X1);
    skip_7:
    // 0x8018B4B8: beq         $t0, $zero, L_8018B5E8
    if (ctx->r8 == 0) {
        // 0x8018B4BC: addiu       $at, $zero, 0x1A
        ctx->r1 = ADD32(0, 0X1A);
            goto L_8018B5E8;
    }
    // 0x8018B4BC: addiu       $at, $zero, 0x1A
    ctx->r1 = ADD32(0, 0X1A);
    // 0x8018B4C0: bnel        $v0, $at, L_8018B4E8
    if (ctx->r2 != ctx->r1) {
        // 0x8018B4C4: addiu       $at, $zero, 0x39
        ctx->r1 = ADD32(0, 0X39);
            goto L_8018B4E8;
    }
    goto skip_8;
    // 0x8018B4C4: addiu       $at, $zero, 0x39
    ctx->r1 = ADD32(0, 0X39);
    skip_8:
    // 0x8018B4C8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8018B4CC: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8018B4D0: sh          $t6, 0x46($t0)
    MEM_H(0X46, ctx->r8) = ctx->r14;
    // 0x8018B4D4: swc1        $f0, 0xE8($t0)
    MEM_W(0XE8, ctx->r8) = ctx->f0.u32l;
    // 0x8018B4D8: swc1        $f0, 0xEC($t0)
    MEM_W(0XEC, ctx->r8) = ctx->f0.u32l;
    // 0x8018B4DC: b           L_8018B574
    // 0x8018B4E0: swc1        $f0, 0xF0($t0)
    MEM_W(0XF0, ctx->r8) = ctx->f0.u32l;
        goto L_8018B574;
    // 0x8018B4E0: swc1        $f0, 0xF0($t0)
    MEM_W(0XF0, ctx->r8) = ctx->f0.u32l;
    // 0x8018B4E4: addiu       $at, $zero, 0x39
    ctx->r1 = ADD32(0, 0X39);
L_8018B4E8:
    // 0x8018B4E8: bne         $v0, $at, L_8018B574
    if (ctx->r2 != ctx->r1) {
        // 0x8018B4EC: lui         $a3, 0x800C
        ctx->r7 = S32(0X800C << 16);
            goto L_8018B574;
    }
    // 0x8018B4EC: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8018B4F0: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x8018B4F4: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8018B4F8: addiu       $t7, $t7, 0x5D3C
    ctx->r15 = ADD32(ctx->r15, 0X5D3C);
    // 0x8018B4FC: lui         $a0, 0x2900
    ctx->r4 = S32(0X2900 << 16);
    // 0x8018B500: ori         $a0, $a0, 0x28
    ctx->r4 = ctx->r4 | 0X28;
    // 0x8018B504: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8018B508: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8018B50C: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x8018B510: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8018B514: jal         0x80019218
    // 0x8018B518: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    Audio_PlaySfx(rdram, ctx);
        goto after_4;
    // 0x8018B518: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    after_4:
    // 0x8018B51C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8018B520: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8018B524: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8018B528: swc1        $f10, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f10.u32l;
    // 0x8018B52C: lwc1        $f16, 0x118($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X118);
    // 0x8018B530: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018B534: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018B538: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x8018B53C: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // 0x8018B540: swc1        $f18, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f18.u32l;
    // 0x8018B544: jal         0x80006A20
    // 0x8018B548: swc1        $f16, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f16.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_5;
    // 0x8018B548: swc1        $f16, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f16.u32l;
    after_5:
    // 0x8018B54C: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8018B550: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8018B554: swc1        $f4, 0xE8($t0)
    MEM_W(0XE8, ctx->r8) = ctx->f4.u32l;
    // 0x8018B558: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8018B55C: swc1        $f6, 0xEC($t0)
    MEM_W(0XEC, ctx->r8) = ctx->f6.u32l;
    // 0x8018B560: lwc1        $f8, 0x48($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8018B564: sh          $zero, 0x46($t0)
    MEM_H(0X46, ctx->r8) = 0;
    // 0x8018B568: sw          $zero, 0x50($t0)
    MEM_W(0X50, ctx->r8) = 0;
    // 0x8018B56C: swc1        $f8, 0xF0($t0)
    MEM_W(0XF0, ctx->r8) = ctx->f8.u32l;
    // 0x8018B570: sw          $zero, 0x54($s0)
    MEM_W(0X54, ctx->r16) = 0;
L_8018B574:
    // 0x8018B574: lwc1        $f10, 0x12C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X12C);
    // 0x8018B578: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8018B57C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8018B580: swc1        $f10, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f10.u32l;
    // 0x8018B584: lwc1        $f16, 0x130($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X130);
    // 0x8018B588: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018B58C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018B590: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8018B594: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x8018B598: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // 0x8018B59C: swc1        $f4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f4.u32l;
    // 0x8018B5A0: lwc1        $f6, 0x134($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X134);
    // 0x8018B5A4: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    // 0x8018B5A8: jal         0x80006970
    // 0x8018B5AC: swc1        $f6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f6.u32l;
    Matrix_MultVec3f(rdram, ctx);
        goto after_6;
    // 0x8018B5AC: swc1        $f6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f6.u32l;
    after_6:
    // 0x8018B5B0: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8018B5B4: lwc1        $f10, 0x40($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8018B5B8: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8018B5BC: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8018B5C0: swc1        $f16, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f16.u32l;
    // 0x8018B5C4: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8018B5C8: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8018B5CC: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8018B5D0: swc1        $f6, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->f6.u32l;
    // 0x8018B5D4: lwc1        $f10, 0x48($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8018B5D8: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8018B5DC: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8018B5E0: swc1        $f16, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->f16.u32l;
    // 0x8018B5E4: lh          $v0, 0xB6($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XB6);
L_8018B5E8:
    // 0x8018B5E8: addiu       $t8, $v0, 0x1
    ctx->r24 = ADD32(ctx->r2, 0X1);
L_8018B5EC:
    // 0x8018B5EC: lui         $a0, 0x701
    ctx->r4 = S32(0X701 << 16);
    // 0x8018B5F0: addiu       $a0, $a0, -0x2ACC
    ctx->r4 = ADD32(ctx->r4, -0X2ACC);
    // 0x8018B5F4: jal         0x8009ACDC
    // 0x8018B5F8: sh          $t8, 0xB6($s0)
    MEM_H(0XB6, ctx->r16) = ctx->r24;
    Animation_GetFrameCount(rdram, ctx);
        goto after_7;
    // 0x8018B5F8: sh          $t8, 0xB6($s0)
    MEM_H(0XB6, ctx->r16) = ctx->r24;
    after_7:
    // 0x8018B5FC: lh          $t9, 0xB6($s0)
    ctx->r25 = MEM_H(ctx->r16, 0XB6);
    // 0x8018B600: slt         $at, $t9, $v0
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8018B604: bnel        $at, $zero, L_8018B61C
    if (ctx->r1 != 0) {
        // 0x8018B608: lh          $t3, 0xCE($s0)
        ctx->r11 = MEM_H(ctx->r16, 0XCE);
            goto L_8018B61C;
    }
    goto skip_9;
    // 0x8018B608: lh          $t3, 0xCE($s0)
    ctx->r11 = MEM_H(ctx->r16, 0XCE);
    skip_9:
    // 0x8018B60C: lh          $t1, 0xB8($s0)
    ctx->r9 = MEM_H(ctx->r16, 0XB8);
    // 0x8018B610: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x8018B614: sh          $t2, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r10;
L_8018B618:
    // 0x8018B618: lh          $t3, 0xCE($s0)
    ctx->r11 = MEM_H(ctx->r16, 0XCE);
L_8018B61C:
    // 0x8018B61C: lui         $a0, 0x701
    ctx->r4 = S32(0X701 << 16);
    // 0x8018B620: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x8018B624: bne         $t3, $zero, L_8018B698
    if (ctx->r11 != 0) {
        // 0x8018B628: addiu       $a0, $a0, -0x2ACC
        ctx->r4 = ADD32(ctx->r4, -0X2ACC);
            goto L_8018B698;
    }
    // 0x8018B628: addiu       $a0, $a0, -0x2ACC
    ctx->r4 = ADD32(ctx->r4, -0X2ACC);
    // 0x8018B62C: sb          $t4, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r12;
    // 0x8018B630: lh          $a1, 0xB6($s0)
    ctx->r5 = MEM_H(ctx->r16, 0XB6);
    // 0x8018B634: addiu       $a2, $s0, 0x18C
    ctx->r6 = ADD32(ctx->r16, 0X18C);
    // 0x8018B638: jal         0x8009AA20
    // 0x8018B63C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    Animation_GetFrameData(rdram, ctx);
        goto after_8;
    // 0x8018B63C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    after_8:
    // 0x8018B640: lui         $t5, 0x8019
    ctx->r13 = S32(0X8019 << 16);
    // 0x8018B644: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x8018B648: addiu       $t6, $t6, 0x4660
    ctx->r14 = ADD32(ctx->r14, 0X4660);
    // 0x8018B64C: addiu       $t5, $t5, -0x4E4C
    ctx->r13 = ADD32(ctx->r13, -0X4E4C);
    // 0x8018B650: lui         $a1, 0x701
    ctx->r5 = S32(0X701 << 16);
    // 0x8018B654: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x8018B658: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x8018B65C: addiu       $a3, $a3, -0x502C
    ctx->r7 = ADD32(ctx->r7, -0X502C);
    // 0x8018B660: addiu       $a1, $a1, -0x2900
    ctx->r5 = ADD32(ctx->r5, -0X2900);
    // 0x8018B664: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8018B668: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x8018B66C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8018B670: jal         0x8009A72C
    // 0x8018B674: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    Animation_DrawSkeleton(rdram, ctx);
        goto after_9;
    // 0x8018B674: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_9:
    // 0x8018B678: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8018B67C: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8018B680: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x8018B684: jal         0x8007D2C8
    // 0x8018B688: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    Effect_FireSmoke1_Spawn3(rdram, ctx);
        goto after_10;
    // 0x8018B688: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    after_10:
    // 0x8018B68C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8018B690: sb          $zero, 0xCA($s0)
    MEM_B(0XCA, ctx->r16) = 0;
    // 0x8018B694: swc1        $f18, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f18.u32l;
L_8018B698:
    // 0x8018B698: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8018B69C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8018B6A0: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x8018B6A4: jr          $ra
    // 0x8018B6A8: nop

    return;
    // 0x8018B6A8: nop

;}
RECOMP_FUNC void Macbeth_Effect378_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A57D0: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x801A57D4: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x801A57D8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x801A57DC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x801A57E0: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x801A57E4: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x801A57E8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x801A57EC: lw          $t6, -0x7D80($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7D80);
    // 0x801A57F0: lwc1        $f6, 0xC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XC);
    // 0x801A57F4: lui         $at, 0xC4FA
    ctx->r1 = S32(0XC4FA << 16);
    // 0x801A57F8: lwc1        $f4, 0x138($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X138);
    // 0x801A57FC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801A5800: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801A5804: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801A5808: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x801A580C: nop

    // 0x801A5810: bc1fl       L_801A5824
    if (!c1cs) {
        // 0x801A5814: mtc1        $zero, $f2
        ctx->f2.u32l = 0;
            goto L_801A5824;
    }
    goto skip_0;
    // 0x801A5814: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    skip_0:
    // 0x801A5818: jal         0x80060FBC
    // 0x801A581C: addiu       $a1, $s1, 0x80
    ctx->r5 = ADD32(ctx->r17, 0X80);
    Object_Kill(rdram, ctx);
        goto after_0;
    // 0x801A581C: addiu       $a1, $s1, 0x80
    ctx->r5 = ADD32(ctx->r17, 0X80);
    after_0:
    // 0x801A5820: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
L_801A5824:
    // 0x801A5824: lhu         $t7, 0x50($s1)
    ctx->r15 = MEM_HU(ctx->r17, 0X50);
    // 0x801A5828: addiu       $at, $zero, 0x60
    ctx->r1 = ADD32(0, 0X60);
    // 0x801A582C: swc1        $f2, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f2.u32l;
    // 0x801A5830: swc1        $f2, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f2.u32l;
    // 0x801A5834: bne         $t7, $at, L_801A5878
    if (ctx->r15 != ctx->r1) {
        // 0x801A5838: swc1        $f2, 0x18($s1)
        MEM_W(0X18, ctx->r17) = ctx->f2.u32l;
            goto L_801A5878;
    }
    // 0x801A5838: swc1        $f2, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->f2.u32l;
    // 0x801A583C: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x801A5840: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x801A5844: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_801A5848:
    // 0x801A5848: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x801A584C: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x801A5850: lwc1        $f14, 0x8($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X8);
    // 0x801A5854: jal         0x8007BC7C
    // 0x801A5858: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    Effect_Effect362_Spawn(rdram, ctx);
        goto after_1;
    // 0x801A5858: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    after_1:
    // 0x801A585C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801A5860: andi        $t8, $s0, 0xFF
    ctx->r24 = ctx->r16 & 0XFF;
    // 0x801A5864: slti        $at, $t8, 0x2
    ctx->r1 = SIGNED(ctx->r24) < 0X2 ? 1 : 0;
    // 0x801A5868: bne         $at, $zero, L_801A5848
    if (ctx->r1 != 0) {
        // 0x801A586C: or          $s0, $t8, $zero
        ctx->r16 = ctx->r24 | 0;
            goto L_801A5848;
    }
    // 0x801A586C: or          $s0, $t8, $zero
    ctx->r16 = ctx->r24 | 0;
    // 0x801A5870: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x801A5874: nop

L_801A5878:
    // 0x801A5878: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x801A587C: lw          $a0, -0x7D80($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7D80);
    // 0x801A5880: lwc1        $f18, 0xC($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0XC);
    // 0x801A5884: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x801A5888: lwc1        $f16, 0x138($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X138);
    // 0x801A588C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801A5890: sub.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x801A5894: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x801A5898: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x801A589C: nop

    // 0x801A58A0: bc1f        L_801A59F8
    if (!c1cs) {
        // 0x801A58A4: nop
    
            goto L_801A59F8;
    }
    // 0x801A58A4: nop

    // 0x801A58A8: lwc1        $f6, 0x74($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X74);
    // 0x801A58AC: lwc1        $f8, 0x4($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X4);
    // 0x801A58B0: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801A58B4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x801A58B8: sub.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x801A58BC: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x801A58C0: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x801A58C4: nop

    // 0x801A58C8: bc1f        L_801A59F8
    if (!c1cs) {
        // 0x801A58CC: nop
    
            goto L_801A59F8;
    }
    // 0x801A58CC: nop

    // 0x801A58D0: lwc1        $f10, 0x78($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X78);
    // 0x801A58D4: lwc1        $f16, 0x8($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X8);
    // 0x801A58D8: sub.s       $f0, $f10, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x801A58DC: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x801A58E0: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x801A58E4: nop

    // 0x801A58E8: bc1f        L_801A59F8
    if (!c1cs) {
        // 0x801A58EC: nop
    
            goto L_801A59F8;
    }
    // 0x801A58EC: nop

    // 0x801A58F0: lw          $v0, 0x280($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X280);
    // 0x801A58F4: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x801A58F8: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x801A58FC: bne         $v0, $zero, L_801A5910
    if (ctx->r2 != 0) {
        // 0x801A5900: addiu       $a2, $sp, 0x44
        ctx->r6 = ADD32(ctx->r29, 0X44);
            goto L_801A5910;
    }
    // 0x801A5900: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    // 0x801A5904: lw          $t9, 0x27C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X27C);
    // 0x801A5908: beq         $t9, $zero, L_801A5980
    if (ctx->r25 == 0) {
        // 0x801A590C: nop
    
            goto L_801A5980;
    }
    // 0x801A590C: nop

L_801A5910:
    // 0x801A5910: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801A5914: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A5918: swc1        $f2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f2.u32l;
    // 0x801A591C: swc1        $f2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f2.u32l;
    // 0x801A5920: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801A5924: addiu       $s0, $s1, 0x80
    ctx->r16 = ADD32(ctx->r17, 0X80);
    // 0x801A5928: jal         0x80006970
    // 0x801A592C: swc1        $f18, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f18.u32l;
    Matrix_MultVec3f(rdram, ctx);
        goto after_2;
    // 0x801A592C: swc1        $f18, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f18.u32l;
    after_2:
    // 0x801A5930: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x801A5934: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x801A5938: lui         $t0, 0x800C
    ctx->r8 = S32(0X800C << 16);
    // 0x801A593C: swc1        $f4, 0x54($s1)
    MEM_W(0X54, ctx->r17) = ctx->f4.u32l;
    // 0x801A5940: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x801A5944: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x801A5948: addiu       $t0, $t0, 0x5D3C
    ctx->r8 = ADD32(ctx->r8, 0X5D3C);
    // 0x801A594C: swc1        $f6, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->f6.u32l;
    // 0x801A5950: lwc1        $f8, 0x4C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x801A5954: lui         $a0, 0x900
    ctx->r4 = S32(0X900 << 16);
    // 0x801A5958: ori         $a0, $a0, 0x7011
    ctx->r4 = ctx->r4 | 0X7011;
    // 0x801A595C: swc1        $f8, 0x5C($s1)
    MEM_W(0X5C, ctx->r17) = ctx->f8.u32l;
    // 0x801A5960: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x801A5964: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x801A5968: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x801A596C: jal         0x80019218
    // 0x801A5970: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_3;
    // 0x801A5970: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_3:
    // 0x801A5974: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x801A5978: lw          $a0, -0x7D80($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7D80);
    // 0x801A597C: lw          $v0, 0x280($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X280);
L_801A5980:
    // 0x801A5980: bne         $v0, $zero, L_801A59F8
    if (ctx->r2 != 0) {
        // 0x801A5984: nop
    
            goto L_801A59F8;
    }
    // 0x801A5984: nop

    // 0x801A5988: lw          $t1, 0x498($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X498);
    // 0x801A598C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801A5990: addiu       $s0, $s1, 0x80
    ctx->r16 = ADD32(ctx->r17, 0X80);
    // 0x801A5994: bne         $t1, $zero, L_801A59F8
    if (ctx->r9 != 0) {
        // 0x801A5998: nop
    
            goto L_801A59F8;
    }
    // 0x801A5998: nop

    // 0x801A599C: jal         0x800A6CD0
    // 0x801A59A0: lbu         $a2, 0x34($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X34);
    Player_ApplyDamage(rdram, ctx);
        goto after_4;
    // 0x801A59A0: lbu         $a2, 0x34($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X34);
    after_4:
    // 0x801A59A4: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x801A59A8: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x801A59AC: lw          $t2, -0x7D80($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X7D80);
    // 0x801A59B0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801A59B4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801A59B8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x801A59BC: swc1        $f10, 0xD8($t2)
    MEM_W(0XD8, ctx->r10) = ctx->f10.u32l;
    // 0x801A59C0: lwc1        $f16, 0x54($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X54);
    // 0x801A59C4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x801A59C8: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x801A59CC: nop

    // 0x801A59D0: bc1f        L_801A59F0
    if (!c1cs) {
        // 0x801A59D4: nop
    
            goto L_801A59F0;
    }
    // 0x801A59D4: nop

    // 0x801A59D8: lw          $a0, -0x7D80($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7D80);
    // 0x801A59DC: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x801A59E0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801A59E4: lwc1        $f4, 0xD8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XD8);
    // 0x801A59E8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x801A59EC: swc1        $f8, 0xD8($a0)
    MEM_W(0XD8, ctx->r4) = ctx->f8.u32l;
L_801A59F0:
    // 0x801A59F0: jal         0x80060FBC
    // 0x801A59F4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Object_Kill(rdram, ctx);
        goto after_5;
    // 0x801A59F4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
L_801A59F8:
    // 0x801A59F8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801A59FC: lwc1        $f10, 0x7940($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7940);
    // 0x801A5A00: lwc1        $f14, 0x8($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X8);
    // 0x801A5A04: lui         $a3, 0x4479
    ctx->r7 = S32(0X4479 << 16);
    // 0x801A5A08: ori         $a3, $a3, 0xF99A
    ctx->r7 = ctx->r7 | 0XF99A;
    // 0x801A5A0C: c.lt.s      $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f14.fl < ctx->f10.fl;
    // 0x801A5A10: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x801A5A14: addiu       $s0, $s1, 0x80
    ctx->r16 = ADD32(ctx->r17, 0X80);
    // 0x801A5A18: bc1fl       L_801A5A6C
    if (!c1cs) {
        // 0x801A5A1C: lwc1        $f6, 0x54($s1)
        ctx->f6.u32l = MEM_W(ctx->r17, 0X54);
            goto L_801A5A6C;
    }
    goto skip_1;
    // 0x801A5A1C: lwc1        $f6, 0x54($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X54);
    skip_1:
    // 0x801A5A20: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801A5A24: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x801A5A28: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801A5A2C: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x801A5A30: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    // 0x801A5A34: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x801A5A38: jal         0x801ADCEC
    // 0x801A5A3C: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    Macbeth_MaBombDrop_Spawn(rdram, ctx);
        goto after_6;
    // 0x801A5A3C: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_6:
    // 0x801A5A40: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801A5A44: jal         0x80060FBC
    // 0x801A5A48: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    Object_Kill(rdram, ctx);
        goto after_7;
    // 0x801A5A48: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_7:
    // 0x801A5A4C: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x801A5A50: lw          $t3, 0x1A88($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X1A88);
    // 0x801A5A54: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801A5A58: beq         $t3, $at, L_801A5A68
    if (ctx->r11 == ctx->r1) {
        // 0x801A5A5C: lui         $at, 0x8017
        ctx->r1 = S32(0X8017 << 16);
            goto L_801A5A68;
    }
    // 0x801A5A5C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801A5A60: lwc1        $f4, 0x7940($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7940);
    // 0x801A5A64: swc1        $f4, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f4.u32l;
L_801A5A68:
    // 0x801A5A68: lwc1        $f6, 0x54($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X54);
L_801A5A6C:
    // 0x801A5A6C: addiu       $a0, $zero, 0x3E8
    ctx->r4 = ADD32(0, 0X3E8);
    // 0x801A5A70: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    // 0x801A5A74: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    // 0x801A5A78: lwc1        $f8, 0x58($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X58);
    // 0x801A5A7C: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    // 0x801A5A80: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801A5A84: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    // 0x801A5A88: lwc1        $f10, 0x5C($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X5C);
    // 0x801A5A8C: jal         0x801A55D4
    // 0x801A5A90: swc1        $f10, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f10.u32l;
    Macbeth_801A55D4(rdram, ctx);
        goto after_8;
    // 0x801A5A90: swc1        $f10, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f10.u32l;
    after_8:
    // 0x801A5A94: beq         $v0, $zero, L_801A5AD8
    if (ctx->r2 == 0) {
        // 0x801A5A98: lui         $a3, 0x4479
        ctx->r7 = S32(0X4479 << 16);
            goto L_801A5AD8;
    }
    // 0x801A5A98: lui         $a3, 0x4479
    ctx->r7 = S32(0X4479 << 16);
    // 0x801A5A9C: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x801A5AA0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801A5AA4: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x801A5AA8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801A5AAC: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x801A5AB0: lwc1        $f14, 0x8($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X8);
    // 0x801A5AB4: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    // 0x801A5AB8: ori         $a3, $a3, 0xF99A
    ctx->r7 = ctx->r7 | 0XF99A;
    // 0x801A5ABC: addiu       $s0, $s1, 0x80
    ctx->r16 = ADD32(ctx->r17, 0X80);
    // 0x801A5AC0: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x801A5AC4: jal         0x801ADCEC
    // 0x801A5AC8: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    Macbeth_MaBombDrop_Spawn(rdram, ctx);
        goto after_9;
    // 0x801A5AC8: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_9:
    // 0x801A5ACC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801A5AD0: jal         0x80060FBC
    // 0x801A5AD4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    Object_Kill(rdram, ctx);
        goto after_10;
    // 0x801A5AD4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_10:
L_801A5AD8:
    // 0x801A5AD8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x801A5ADC: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x801A5AE0: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x801A5AE4: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x801A5AE8: jr          $ra
    // 0x801A5AEC: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x801A5AEC: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void Macbeth_Effect357_Setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801AD554: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801AD558: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x801AD55C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x801AD560: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801AD564: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801AD568: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801AD56C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x801AD570: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x801AD574: jal         0x80061474
    // 0x801AD578: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    Effect_Initialize(rdram, ctx);
        goto after_0;
    // 0x801AD578: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x801AD57C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x801AD580: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x801AD584: addiu       $t7, $zero, 0x165
    ctx->r15 = ADD32(0, 0X165);
    // 0x801AD588: sb          $t6, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r14;
    // 0x801AD58C: sh          $t7, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r15;
    // 0x801AD590: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x801AD594: andi        $a1, $t7, 0xFFFF
    ctx->r5 = ctx->r15 & 0XFFFF;
    // 0x801AD598: addiu       $a0, $a2, 0x1C
    ctx->r4 = ADD32(ctx->r6, 0X1C);
    // 0x801AD59C: swc1        $f4, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f4.u32l;
    // 0x801AD5A0: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x801AD5A4: swc1        $f6, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f6.u32l;
    // 0x801AD5A8: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x801AD5AC: swc1        $f8, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f8.u32l;
    // 0x801AD5B0: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x801AD5B4: swc1        $f10, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->f10.u32l;
    // 0x801AD5B8: lwc1        $f16, 0x38($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
    // 0x801AD5BC: swc1        $f16, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->f16.u32l;
    // 0x801AD5C0: lwc1        $f18, 0x3C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x801AD5C4: swc1        $f18, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->f18.u32l;
    // 0x801AD5C8: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801AD5CC: swc1        $f4, 0x54($a2)
    MEM_W(0X54, ctx->r6) = ctx->f4.u32l;
    // 0x801AD5D0: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801AD5D4: swc1        $f6, 0x58($a2)
    MEM_W(0X58, ctx->r6) = ctx->f6.u32l;
    // 0x801AD5D8: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x801AD5DC: swc1        $f8, 0x5C($a2)
    MEM_W(0X5C, ctx->r6) = ctx->f8.u32l;
    // 0x801AD5E0: lwc1        $f10, 0x54($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X54);
    // 0x801AD5E4: swc1        $f10, 0x70($a2)
    MEM_W(0X70, ctx->r6) = ctx->f10.u32l;
    // 0x801AD5E8: lh          $t8, 0x4E($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X4E);
    // 0x801AD5EC: sh          $t8, 0x50($a2)
    MEM_H(0X50, ctx->r6) = ctx->r24;
    // 0x801AD5F0: lwc1        $f16, 0x40($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X40);
    // 0x801AD5F4: swc1        $f16, 0x60($a2)
    MEM_W(0X60, ctx->r6) = ctx->f16.u32l;
    // 0x801AD5F8: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x801AD5FC: swc1        $f18, 0x64($a2)
    MEM_W(0X64, ctx->r6) = ctx->f18.u32l;
    // 0x801AD600: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x801AD604: swc1        $f4, 0x68($a2)
    MEM_W(0X68, ctx->r6) = ctx->f4.u32l;
    // 0x801AD608: lh          $t9, 0x52($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X52);
    // 0x801AD60C: jal         0x800612B8
    // 0x801AD610: sh          $t9, 0x44($a2)
    MEM_H(0X44, ctx->r6) = ctx->r25;
    Object_SetInfo(rdram, ctx);
        goto after_1;
    // 0x801AD610: sh          $t9, 0x44($a2)
    MEM_H(0X44, ctx->r6) = ctx->r25;
    after_1:
    // 0x801AD614: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801AD618: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801AD61C: jr          $ra
    // 0x801AD620: nop

    return;
    // 0x801AD620: nop

;}
RECOMP_FUNC void Titania_TiRasco_OverrideLimbDraw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018AFF0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8018AFF4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8018AFF8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8018AFFC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8018B000: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8018B004: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8018B008: beq         $a0, $at, L_8018B024
    if (ctx->r4 == ctx->r1) {
        // 0x8018B00C: lw          $t6, 0x28($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X28);
            goto L_8018B024;
    }
    // 0x8018B00C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8018B010: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8018B014: beq         $a0, $at, L_8018B024
    if (ctx->r4 == ctx->r1) {
        // 0x8018B018: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8018B024;
    }
    // 0x8018B018: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8018B01C: bne         $a0, $at, L_8018B134
    if (ctx->r4 != ctx->r1) {
        // 0x8018B020: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8018B134;
    }
    // 0x8018B020: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8018B024:
    // 0x8018B024: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018B028: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    // 0x8018B02C: lw          $a2, 0x4($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X4);
    // 0x8018B030: lw          $a3, 0x8($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X8);
    // 0x8018B034: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8018B038: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8018B03C: jal         0x80005B00
    // 0x8018B040: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    Matrix_Translate(rdram, ctx);
        goto after_0;
    // 0x8018B040: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    after_0:
    // 0x8018B044: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8018B048: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018B04C: lwc1        $f6, -0x53EC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X53EC);
    // 0x8018B050: lwc1        $f4, 0x8($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X8);
    // 0x8018B054: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018B058: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018B05C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8018B060: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018B064: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8018B068: jal         0x80005FE0
    // 0x8018B06C: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_1;
    // 0x8018B06C: nop

    after_1:
    // 0x8018B070: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8018B074: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018B078: lwc1        $f16, -0x53E8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X53E8);
    // 0x8018B07C: lwc1        $f10, 0x4($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X4);
    // 0x8018B080: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018B084: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018B088: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8018B08C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018B090: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8018B094: jal         0x80005E90
    // 0x8018B098: nop

    Matrix_RotateY(rdram, ctx);
        goto after_2;
    // 0x8018B098: nop

    after_2:
    // 0x8018B09C: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8018B0A0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018B0A4: lwc1        $f6, -0x53E4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X53E4);
    // 0x8018B0A8: lwc1        $f4, 0x0($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X0);
    // 0x8018B0AC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018B0B0: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018B0B4: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8018B0B8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018B0BC: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8018B0C0: jal         0x80005D44
    // 0x8018B0C4: nop

    Matrix_RotateX(rdram, ctx);
        goto after_3;
    // 0x8018B0C4: nop

    after_3:
    // 0x8018B0C8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018B0CC: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x8018B0D0: lw          $a1, -0x4438($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X4438);
    // 0x8018B0D4: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8018B0D8: jal         0x80005754
    // 0x8018B0DC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_Mult(rdram, ctx);
        goto after_4;
    // 0x8018B0DC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
    // 0x8018B0E0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8018B0E4: jal         0x80006EB8
    // 0x8018B0E8: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_5;
    // 0x8018B0E8: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    after_5:
    // 0x8018B0EC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8018B0F0: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8018B0F4: jal         0x800B8DD0
    // 0x8018B0F8: addiu       $a1, $zero, 0x21
    ctx->r5 = ADD32(0, 0X21);
    RCP_SetupDL(rdram, ctx);
        goto after_6;
    // 0x8018B0F8: addiu       $a1, $zero, 0x21
    ctx->r5 = ADD32(0, 0X21);
    after_6:
    // 0x8018B0FC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8018B100: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8018B104: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8018B108: lui         $t2, 0x600
    ctx->r10 = S32(0X600 << 16);
    // 0x8018B10C: addiu       $t1, $v1, 0x8
    ctx->r9 = ADD32(ctx->r3, 0X8);
    // 0x8018B110: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x8018B114: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x8018B118: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x8018B11C: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8018B120: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x8018B124: jal         0x800B8DD0
    // 0x8018B128: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    RCP_SetupDL(rdram, ctx);
        goto after_7;
    // 0x8018B128: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    after_7:
    // 0x8018B12C: b           L_8018B134
    // 0x8018B130: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8018B134;
    // 0x8018B130: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8018B134:
    // 0x8018B134: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8018B138: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8018B13C: jr          $ra
    // 0x8018B140: nop

    return;
    // 0x8018B140: nop

;}
RECOMP_FUNC void Ground_801B6B40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801B6B40: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x801B6B44: sdc1        $f26, 0x20($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X20, ctx->r29);
    // 0x801B6B48: sdc1        $f24, 0x18($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X18, ctx->r29);
    // 0x801B6B4C: mov.s       $f24, $f12
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 12);
    ctx->f24.fl = ctx->f12.fl;
    // 0x801B6B50: mov.s       $f26, $f14
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 14);
    ctx->f26.fl = ctx->f14.fl;
    // 0x801B6B54: sdc1        $f30, 0x30($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X30, ctx->r29);
    // 0x801B6B58: sdc1        $f28, 0x28($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X28, ctx->r29);
    // 0x801B6B5C: sdc1        $f22, 0x10($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X10, ctx->r29);
    // 0x801B6B60: sdc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X8, ctx->r29);
    // 0x801B6B64: lwc1        $f4, 0x4($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X4);
    // 0x801B6B68: lwc1        $f20, 0x0($a2)
    ctx->f20.u32l = MEM_W(ctx->r6, 0X0);
    // 0x801B6B6C: addiu       $a2, $a2, 0x24
    ctx->r6 = ADD32(ctx->r6, 0X24);
    // 0x801B6B70: swc1        $f4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f4.u32l;
    // 0x801B6B74: lwc1        $f6, -0x14($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, -0X14);
    // 0x801B6B78: lwc1        $f22, -0x1C($a2)
    ctx->f22.u32l = MEM_W(ctx->r6, -0X1C);
    // 0x801B6B7C: lwc1        $f0, -0x18($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, -0X18);
    // 0x801B6B80: swc1        $f6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f6.u32l;
    // 0x801B6B84: lwc1        $f8, -0x8($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, -0X8);
    // 0x801B6B88: lwc1        $f2, -0x10($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, -0X10);
    // 0x801B6B8C: lwc1        $f30, -0xC($a2)
    ctx->f30.u32l = MEM_W(ctx->r6, -0XC);
    // 0x801B6B90: swc1        $f8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f8.u32l;
    // 0x801B6B94: lwc1        $f10, -0x4($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, -0X4);
    // 0x801B6B98: sub.s       $f12, $f2, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f12.fl = ctx->f2.fl - ctx->f22.fl;
    // 0x801B6B9C: mtc1        $zero, $f28
    ctx->f28.u32l = 0;
    // 0x801B6BA0: swc1        $f10, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f10.u32l;
    // 0x801B6BA4: lwc1        $f4, 0x0($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X0);
    // 0x801B6BA8: sub.s       $f10, $f24, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f24.fl - ctx->f0.fl;
    // 0x801B6BAC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x801B6BB0: swc1        $f4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f4.u32l;
    // 0x801B6BB4: lwc1        $f6, 0x4($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X4);
    // 0x801B6BB8: sub.s       $f14, $f0, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f14.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x801B6BBC: mul.s       $f4, $f12, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x801B6BC0: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    // 0x801B6BC4: sub.s       $f6, $f26, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f26.fl - ctx->f2.fl;
    // 0x801B6BC8: lwc1        $f8, 0x8($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X8);
    // 0x801B6BCC: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    // 0x801B6BD0: mul.s       $f8, $f14, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f6.fl);
    // 0x801B6BD4: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x801B6BD8: sub.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x801B6BDC: c.le.s      $f28, $f10
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f28.fl <= ctx->f10.fl;
    // 0x801B6BE0: nop

    // 0x801B6BE4: bc1f        L_801B6CBC
    if (!c1cs) {
        // 0x801B6BE8: nop
    
            goto L_801B6CBC;
    }
    // 0x801B6BE8: nop

    // 0x801B6BEC: sub.s       $f16, $f6, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x801B6BF0: sub.s       $f4, $f24, $f30
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f4.fl = ctx->f24.fl - ctx->f30.fl;
    // 0x801B6BF4: sub.s       $f18, $f30, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f30.fl - ctx->f0.fl;
    // 0x801B6BF8: mul.s       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x801B6BFC: sub.s       $f10, $f26, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f26.fl - ctx->f6.fl;
    // 0x801B6C00: mul.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x801B6C04: c.le.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl <= ctx->f8.fl;
    // 0x801B6C08: nop

    // 0x801B6C0C: bc1f        L_801B6CBC
    if (!c1cs) {
        // 0x801B6C10: nop
    
            goto L_801B6CBC;
    }
    // 0x801B6C10: nop

    // 0x801B6C14: sub.s       $f10, $f22, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f22.fl - ctx->f6.fl;
    // 0x801B6C18: sub.s       $f8, $f24, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f24.fl - ctx->f20.fl;
    // 0x801B6C1C: sub.s       $f6, $f20, $f30
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f6.fl = ctx->f20.fl - ctx->f30.fl;
    // 0x801B6C20: mul.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x801B6C24: sub.s       $f10, $f26, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = ctx->f26.fl - ctx->f22.fl;
    // 0x801B6C28: mul.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x801B6C2C: lwc1        $f10, 0x60($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X60);
    // 0x801B6C30: lwc1        $f6, 0x54($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X54);
    // 0x801B6C34: c.le.s      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.fl <= ctx->f4.fl;
    // 0x801B6C38: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x801B6C3C: bc1f        L_801B6CBC
    if (!c1cs) {
        // 0x801B6C40: nop
    
            goto L_801B6CBC;
    }
    // 0x801B6C40: nop

    // 0x801B6C44: sub.s       $f0, $f6, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x801B6C48: sub.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801B6C4C: mul.s       $f8, $f0, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x801B6C50: nop

    // 0x801B6C54: mul.s       $f10, $f12, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f2.fl);
    // 0x801B6C58: sub.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x801B6C5C: mul.s       $f6, $f12, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f18.fl);
    // 0x801B6C60: nop

    // 0x801B6C64: mul.s       $f8, $f14, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f16.fl);
    // 0x801B6C68: swc1        $f4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f4.u32l;
    // 0x801B6C6C: mul.s       $f4, $f14, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x801B6C70: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x801B6C74: mul.s       $f6, $f0, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x801B6C78: swc1        $f10, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f10.u32l;
    // 0x801B6C7C: lwc1        $f10, 0x0($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X0);
    // 0x801B6C80: c.eq.s      $f28, $f10
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f28.fl == ctx->f10.fl;
    // 0x801B6C84: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801B6C88: bc1f        L_801B6CB8
    if (!c1cs) {
        // 0x801B6C8C: swc1        $f8, 0x8($a3)
        MEM_W(0X8, ctx->r7) = ctx->f8.u32l;
            goto L_801B6CB8;
    }
    // 0x801B6C8C: swc1        $f8, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f8.u32l;
    // 0x801B6C90: lwc1        $f4, 0x4($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X4);
    // 0x801B6C94: c.eq.s      $f28, $f4
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f28.fl == ctx->f4.fl;
    // 0x801B6C98: nop

    // 0x801B6C9C: bc1fl       L_801B6CBC
    if (!c1cs) {
        // 0x801B6CA0: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_801B6CBC;
    }
    goto skip_0;
    // 0x801B6CA0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    skip_0:
    // 0x801B6CA4: lwc1        $f6, 0x8($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X8);
    // 0x801B6CA8: c.eq.s      $f28, $f6
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f28.fl == ctx->f6.fl;
    // 0x801B6CAC: nop

    // 0x801B6CB0: bc1t        L_801B6CBC
    if (c1cs) {
        // 0x801B6CB4: nop
    
            goto L_801B6CBC;
    }
    // 0x801B6CB4: nop

L_801B6CB8:
    // 0x801B6CB8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_801B6CBC:
    // 0x801B6CBC: bne         $v1, $zero, L_801B6DC4
    if (ctx->r3 != 0) {
        // 0x801B6CC0: lwc1        $f8, 0x44($sp)
        ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
            goto L_801B6DC4;
    }
    // 0x801B6CC0: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x801B6CC4: sub.s       $f0, $f8, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f22.fl;
    // 0x801B6CC8: sub.s       $f10, $f24, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f10.fl = ctx->f24.fl - ctx->f30.fl;
    // 0x801B6CCC: sub.s       $f2, $f30, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = ctx->f30.fl - ctx->f20.fl;
    // 0x801B6CD0: mul.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x801B6CD4: sub.s       $f6, $f26, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f26.fl - ctx->f8.fl;
    // 0x801B6CD8: mul.s       $f10, $f2, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x801B6CDC: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x801B6CE0: c.le.s      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.fl <= ctx->f4.fl;
    // 0x801B6CE4: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x801B6CE8: bc1f        L_801B6DC4
    if (!c1cs) {
        // 0x801B6CEC: nop
    
            goto L_801B6DC4;
    }
    // 0x801B6CEC: nop

    // 0x801B6CF0: sub.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x801B6CF4: sub.s       $f10, $f24, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f24.fl - ctx->f4.fl;
    // 0x801B6CF8: sub.s       $f14, $f4, $f30
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f30.fl;
    // 0x801B6CFC: mul.s       $f8, $f12, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x801B6D00: sub.s       $f10, $f26, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f26.fl - ctx->f6.fl;
    // 0x801B6D04: mul.s       $f10, $f14, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f10.fl);
    // 0x801B6D08: c.le.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl <= ctx->f8.fl;
    // 0x801B6D0C: nop

    // 0x801B6D10: bc1f        L_801B6DC4
    if (!c1cs) {
        // 0x801B6D14: nop
    
            goto L_801B6DC4;
    }
    // 0x801B6D14: nop

    // 0x801B6D18: sub.s       $f8, $f22, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f22.fl - ctx->f6.fl;
    // 0x801B6D1C: sub.s       $f10, $f24, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f24.fl - ctx->f20.fl;
    // 0x801B6D20: mul.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x801B6D24: sub.s       $f10, $f26, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = ctx->f26.fl - ctx->f22.fl;
    // 0x801B6D28: sub.s       $f8, $f20, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f20.fl - ctx->f4.fl;
    // 0x801B6D2C: lwc1        $f20, 0x48($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X48);
    // 0x801B6D30: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x801B6D34: lwc1        $f10, 0x3C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x801B6D38: lwc1        $f8, 0x60($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X60);
    // 0x801B6D3C: c.le.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl <= ctx->f6.fl;
    // 0x801B6D40: nop

    // 0x801B6D44: bc1f        L_801B6DC4
    if (!c1cs) {
        // 0x801B6D48: nop
    
            goto L_801B6DC4;
    }
    // 0x801B6D48: nop

    // 0x801B6D4C: sub.s       $f16, $f20, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f20.fl - ctx->f8.fl;
    // 0x801B6D50: sub.s       $f18, $f10, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f20.fl;
    // 0x801B6D54: mul.s       $f6, $f16, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x801B6D58: nop

    // 0x801B6D5C: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x801B6D60: sub.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x801B6D64: mul.s       $f10, $f0, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x801B6D68: nop

    // 0x801B6D6C: mul.s       $f6, $f2, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x801B6D70: swc1        $f8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f8.u32l;
    // 0x801B6D74: mul.s       $f8, $f2, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x801B6D78: sub.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x801B6D7C: mul.s       $f10, $f16, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x801B6D80: swc1        $f4, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f4.u32l;
    // 0x801B6D84: lwc1        $f4, 0x0($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X0);
    // 0x801B6D88: c.eq.s      $f28, $f4
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f28.fl == ctx->f4.fl;
    // 0x801B6D8C: sub.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x801B6D90: bc1f        L_801B6DC0
    if (!c1cs) {
        // 0x801B6D94: swc1        $f6, 0x8($a3)
        MEM_W(0X8, ctx->r7) = ctx->f6.u32l;
            goto L_801B6DC0;
    }
    // 0x801B6D94: swc1        $f6, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f6.u32l;
    // 0x801B6D98: lwc1        $f8, 0x4($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X4);
    // 0x801B6D9C: c.eq.s      $f28, $f8
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f28.fl == ctx->f8.fl;
    // 0x801B6DA0: nop

    // 0x801B6DA4: bc1fl       L_801B6DC4
    if (!c1cs) {
        // 0x801B6DA8: addiu       $v1, $zero, 0x2
        ctx->r3 = ADD32(0, 0X2);
            goto L_801B6DC4;
    }
    goto skip_1;
    // 0x801B6DA8: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    skip_1:
    // 0x801B6DAC: lwc1        $f10, 0x8($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X8);
    // 0x801B6DB0: c.eq.s      $f28, $f10
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f28.fl == ctx->f10.fl;
    // 0x801B6DB4: nop

    // 0x801B6DB8: bc1t        L_801B6DC4
    if (c1cs) {
        // 0x801B6DBC: nop
    
            goto L_801B6DC4;
    }
    // 0x801B6DBC: nop

L_801B6DC0:
    // 0x801B6DC0: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
L_801B6DC4:
    // 0x801B6DC4: beq         $v1, $zero, L_801B6DFC
    if (ctx->r3 == 0) {
        // 0x801B6DC8: lwc1        $f20, 0x48($sp)
        ctx->f20.u32l = MEM_W(ctx->r29, 0X48);
            goto L_801B6DFC;
    }
    // 0x801B6DC8: lwc1        $f20, 0x48($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X48);
    // 0x801B6DCC: lwc1        $f6, 0x0($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X0);
    // 0x801B6DD0: lwc1        $f10, 0x4($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X4);
    // 0x801B6DD4: neg.s       $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = -ctx->f6.fl;
    // 0x801B6DD8: mul.s       $f8, $f4, $f30
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f30.fl);
    // 0x801B6DDC: nop

    // 0x801B6DE0: mul.s       $f6, $f10, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x801B6DE4: lwc1        $f10, 0x8($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X8);
    // 0x801B6DE8: sub.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x801B6DEC: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x801B6DF0: mul.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x801B6DF4: sub.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801B6DF8: swc1        $f10, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->f10.u32l;
L_801B6DFC:
    // 0x801B6DFC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x801B6E00: ldc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X8);
    // 0x801B6E04: ldc1        $f22, 0x10($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X10);
    // 0x801B6E08: ldc1        $f24, 0x18($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X18);
    // 0x801B6E0C: ldc1        $f26, 0x20($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X20);
    // 0x801B6E10: ldc1        $f28, 0x28($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X28);
    // 0x801B6E14: ldc1        $f30, 0x30($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X30);
    // 0x801B6E18: jr          $ra
    // 0x801B6E1C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x801B6E1C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void Ground_801B58AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801B58AC: addiu       $sp, $sp, -0xC8
    ctx->r29 = ADD32(ctx->r29, -0XC8);
    // 0x801B58B0: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x801B58B4: sw          $fp, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r30;
    // 0x801B58B8: sw          $s7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r23;
    // 0x801B58BC: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x801B58C0: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x801B58C4: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x801B58C8: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x801B58CC: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x801B58D0: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x801B58D4: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x801B58D8: sdc1        $f26, 0x40($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X40, ctx->r29);
    // 0x801B58DC: sdc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X38, ctx->r29);
    // 0x801B58E0: sdc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X30, ctx->r29);
    // 0x801B58E4: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x801B58E8: sw          $a0, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r4;
    // 0x801B58EC: sw          $a1, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r5;
    // 0x801B58F0: lw          $a0, 0xC8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC8);
    // 0x801B58F4: jal         0x800B8DD0
    // 0x801B58F8: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x801B58F8: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    after_0:
    // 0x801B58FC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x801B5900: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x801B5904: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x801B5908: lw          $t8, -0x7C24($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7C24);
    // 0x801B590C: lw          $t7, -0x7C28($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7C28);
    // 0x801B5910: lw          $t6, -0x7CC8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7CC8);
    // 0x801B5914: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x801B5918: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x801B591C: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x801B5920: lw          $a3, -0x7CD0($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X7CD0);
    // 0x801B5924: lw          $a2, -0x7CD8($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7CD8);
    // 0x801B5928: lw          $a1, -0x7CE0($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7CE0);
    // 0x801B592C: lw          $a0, 0xC8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC8);
    // 0x801B5930: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x801B5934: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801B5938: jal         0x800B8E14
    // 0x801B593C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    RCP_SetFog(rdram, ctx);
        goto after_1;
    // 0x801B593C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_1:
    // 0x801B5940: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801B5944: lw          $v0, 0x5C14($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X5C14);
    // 0x801B5948: lui         $a2, 0xE800
    ctx->r6 = S32(0XE800 << 16);
    // 0x801B594C: lw          $t0, 0xC8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC8);
    // 0x801B5950: andi        $t9, $v0, 0x2
    ctx->r25 = ctx->r2 & 0X2;
    // 0x801B5954: beq         $t9, $zero, L_801B5B24
    if (ctx->r25 == 0) {
        // 0x801B5958: sw          $v0, 0xC4($sp)
        MEM_W(0XC4, ctx->r29) = ctx->r2;
            goto L_801B5B24;
    }
    // 0x801B5958: sw          $v0, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r2;
    // 0x801B595C: lw          $s0, 0x0($t0)
    ctx->r16 = MEM_W(ctx->r8, 0X0);
    // 0x801B5960: lui         $t6, 0xF510
    ctx->r14 = S32(0XF510 << 16);
    // 0x801B5964: ori         $t6, $t6, 0x1000
    ctx->r14 = ctx->r14 | 0X1000;
    // 0x801B5968: addiu       $t4, $s0, 0x8
    ctx->r12 = ADD32(ctx->r16, 0X8);
    // 0x801B596C: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
    // 0x801B5970: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x801B5974: sw          $a2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r6;
    // 0x801B5978: lw          $s0, 0x0($t0)
    ctx->r16 = MEM_W(ctx->r8, 0X0);
    // 0x801B597C: lui         $t7, 0x1
    ctx->r15 = S32(0X1 << 16);
    // 0x801B5980: ori         $t7, $t7, 0x4150
    ctx->r15 = ctx->r15 | 0X4150;
    // 0x801B5984: addiu       $t5, $s0, 0x8
    ctx->r13 = ADD32(ctx->r16, 0X8);
    // 0x801B5988: sw          $t5, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r13;
    // 0x801B598C: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
    // 0x801B5990: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x801B5994: lw          $s0, 0x0($t0)
    ctx->r16 = MEM_W(ctx->r8, 0X0);
    // 0x801B5998: lui         $t4, 0x7
    ctx->r12 = S32(0X7 << 16);
    // 0x801B599C: ori         $t4, $t4, 0xC07C
    ctx->r12 = ctx->r12 | 0XC07C;
    // 0x801B59A0: addiu       $t8, $s0, 0x8
    ctx->r24 = ADD32(ctx->r16, 0X8);
    // 0x801B59A4: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x801B59A8: lui         $t9, 0xF200
    ctx->r25 = S32(0XF200 << 16);
    // 0x801B59AC: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x801B59B0: sw          $t4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r12;
    // 0x801B59B4: lw          $s0, 0x0($t0)
    ctx->r16 = MEM_W(ctx->r8, 0X0);
    // 0x801B59B8: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x801B59BC: addiu       $t7, $t7, 0x1BA8
    ctx->r15 = ADD32(ctx->r15, 0X1BA8);
    // 0x801B59C0: addiu       $t5, $s0, 0x8
    ctx->r13 = ADD32(ctx->r16, 0X8);
    // 0x801B59C4: sw          $t5, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r13;
    // 0x801B59C8: lui         $t6, 0xFD10
    ctx->r14 = S32(0XFD10 << 16);
    // 0x801B59CC: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x801B59D0: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
    // 0x801B59D4: lw          $s0, 0x0($t0)
    ctx->r16 = MEM_W(ctx->r8, 0X0);
    // 0x801B59D8: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801B59DC: addiu       $v1, $v1, 0x62D8
    ctx->r3 = ADD32(ctx->r3, 0X62D8);
    // 0x801B59E0: addiu       $t8, $s0, 0x8
    ctx->r24 = ADD32(ctx->r16, 0X8);
    // 0x801B59E4: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x801B59E8: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x801B59EC: sw          $a2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r6;
    // 0x801B59F0: lw          $s0, 0x0($t0)
    ctx->r16 = MEM_W(ctx->r8, 0X0);
    // 0x801B59F4: lui         $t4, 0xF510
    ctx->r12 = S32(0XF510 << 16);
    // 0x801B59F8: lui         $t5, 0x700
    ctx->r13 = S32(0X700 << 16);
    // 0x801B59FC: addiu       $t9, $s0, 0x8
    ctx->r25 = ADD32(ctx->r16, 0X8);
    // 0x801B5A00: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x801B5A04: sw          $t5, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r13;
    // 0x801B5A08: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x801B5A0C: lw          $s0, 0x0($t0)
    ctx->r16 = MEM_W(ctx->r8, 0X0);
    // 0x801B5A10: lui         $t7, 0xE600
    ctx->r15 = S32(0XE600 << 16);
    // 0x801B5A14: lui         $t9, 0xF300
    ctx->r25 = S32(0XF300 << 16);
    // 0x801B5A18: addiu       $t6, $s0, 0x8
    ctx->r14 = ADD32(ctx->r16, 0X8);
    // 0x801B5A1C: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x801B5A20: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x801B5A24: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x801B5A28: lw          $s0, 0x0($t0)
    ctx->r16 = MEM_W(ctx->r8, 0X0);
    // 0x801B5A2C: lui         $t4, 0x73F
    ctx->r12 = S32(0X73F << 16);
    // 0x801B5A30: ori         $t4, $t4, 0xF100
    ctx->r12 = ctx->r12 | 0XF100;
    // 0x801B5A34: addiu       $t8, $s0, 0x8
    ctx->r24 = ADD32(ctx->r16, 0X8);
    // 0x801B5A38: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x801B5A3C: sw          $t4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r12;
    // 0x801B5A40: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x801B5A44: lw          $s0, 0x0($t0)
    ctx->r16 = MEM_W(ctx->r8, 0X0);
    // 0x801B5A48: lui         $t6, 0x104
    ctx->r14 = S32(0X104 << 16);
    // 0x801B5A4C: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x801B5A50: addiu       $t5, $s0, 0x8
    ctx->r13 = ADD32(ctx->r16, 0X8);
    // 0x801B5A54: sw          $t5, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r13;
    // 0x801B5A58: addiu       $t7, $t7, 0x4620
    ctx->r15 = ADD32(ctx->r15, 0X4620);
    // 0x801B5A5C: ori         $t6, $t6, 0x40
    ctx->r14 = ctx->r14 | 0X40;
    // 0x801B5A60: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x801B5A64: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
    // 0x801B5A68: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B5A6C: lwc1        $f6, 0x5C10($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5C10);
    // 0x801B5A70: lwc1        $f4, 0x8($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X8);
    // 0x801B5A74: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801B5A78: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x801B5A7C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801B5A80: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x801B5A84: lw          $a2, 0x4($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X4);
    // 0x801B5A88: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x801B5A8C: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x801B5A90: jal         0x80005B00
    // 0x801B5A94: nop

    Matrix_Translate(rdram, ctx);
        goto after_2;
    // 0x801B5A94: nop

    after_2:
    // 0x801B5A98: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x801B5A9C: addiu       $s1, $s1, 0x7E5C
    ctx->r17 = ADD32(ctx->r17, 0X7E5C);
    // 0x801B5AA0: jal         0x80006500
    // 0x801B5AA4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    Matrix_ToMtx(rdram, ctx);
        goto after_3;
    // 0x801B5AA4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_3:
    // 0x801B5AA8: lw          $a3, 0xC8($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC8);
    // 0x801B5AAC: lw          $s0, 0x0($a3)
    ctx->r16 = MEM_W(ctx->r7, 0X0);
    // 0x801B5AB0: lui         $t9, 0x100
    ctx->r25 = S32(0X100 << 16);
    // 0x801B5AB4: ori         $t9, $t9, 0x40
    ctx->r25 = ctx->r25 | 0X40;
    // 0x801B5AB8: addiu       $t8, $s0, 0x8
    ctx->r24 = ADD32(ctx->r16, 0X8);
    // 0x801B5ABC: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x801B5AC0: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x801B5AC4: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x801B5AC8: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x801B5ACC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801B5AD0: sw          $t4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r12;
    // 0x801B5AD4: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x801B5AD8: addiu       $t6, $t5, 0x40
    ctx->r14 = ADD32(ctx->r13, 0X40);
    // 0x801B5ADC: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x801B5AE0: lw          $s0, 0x0($a3)
    ctx->r16 = MEM_W(ctx->r7, 0X0);
    // 0x801B5AE4: lui         $t9, 0x801C
    ctx->r25 = S32(0X801C << 16);
    // 0x801B5AE8: addiu       $t9, $t9, -0x56B0
    ctx->r25 = ADD32(ctx->r25, -0X56B0);
    // 0x801B5AEC: addiu       $t7, $s0, 0x8
    ctx->r15 = ADD32(ctx->r16, 0X8);
    // 0x801B5AF0: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x801B5AF4: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
    // 0x801B5AF8: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x801B5AFC: lw          $s0, 0x0($a3)
    ctx->r16 = MEM_W(ctx->r7, 0X0);
    // 0x801B5B00: lui         $t5, 0xBD00
    ctx->r13 = S32(0XBD00 << 16);
    // 0x801B5B04: addiu       $t4, $s0, 0x8
    ctx->r12 = ADD32(ctx->r16, 0X8);
    // 0x801B5B08: sw          $t4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r12;
    // 0x801B5B0C: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x801B5B10: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x801B5B14: jal         0x801B4AA8
    // 0x801B5B18: addiu       $a1, $sp, 0xC4
    ctx->r5 = ADD32(ctx->r29, 0XC4);
    Ground_801B4AA8(rdram, ctx);
        goto after_4;
    // 0x801B5B18: addiu       $a1, $sp, 0xC4
    ctx->r5 = ADD32(ctx->r29, 0XC4);
    after_4:
    // 0x801B5B1C: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801B5B20: lw          $v0, 0x5C14($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X5C14);
L_801B5B24:
    // 0x801B5B24: andi        $a0, $v0, 0x1
    ctx->r4 = ctx->r2 & 0X1;
    // 0x801B5B28: beq         $a0, $zero, L_801B5EA4
    if (ctx->r4 == 0) {
        // 0x801B5B2C: lui         $t6, 0x800C
        ctx->r14 = S32(0X800C << 16);
            goto L_801B5EA4;
    }
    // 0x801B5B2C: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x801B5B30: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x801B5B34: lw          $t7, 0x5C0C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X5C0C);
    // 0x801B5B38: addiu       $t6, $t6, 0x4620
    ctx->r14 = ADD32(ctx->r14, 0X4620);
    // 0x801B5B3C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801B5B40: bne         $t7, $at, L_801B5E44
    if (ctx->r15 != ctx->r1) {
        // 0x801B5B44: sw          $t6, 0x78($sp)
        MEM_W(0X78, ctx->r29) = ctx->r14;
            goto L_801B5E44;
    }
    // 0x801B5B44: sw          $t6, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r14;
    // 0x801B5B48: lui         $s3, 0x801C
    ctx->r19 = S32(0X801C << 16);
    // 0x801B5B4C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B5B50: addiu       $s3, $s3, 0x5C08
    ctx->r19 = ADD32(ctx->r19, 0X5C08);
    // 0x801B5B54: sw          $zero, 0x5C0C($at)
    MEM_W(0X5C0C, ctx->r1) = 0;
    // 0x801B5B58: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x801B5B5C: addiu       $at, $zero, 0x1C
    ctx->r1 = ADD32(0, 0X1C);
    // 0x801B5B60: lui         $t4, 0x801C
    ctx->r12 = S32(0X801C << 16);
    // 0x801B5B64: addiu       $v1, $v1, 0x1B
    ctx->r3 = ADD32(ctx->r3, 0X1B);
    // 0x801B5B68: div         $zero, $v1, $at
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r1)));
    // 0x801B5B6C: mfhi        $v1
    ctx->r3 = hi;
    // 0x801B5B70: sll         $t9, $v1, 6
    ctx->r25 = S32(ctx->r3 << 6);
    // 0x801B5B74: addiu       $t4, $t4, 0x1D48
    ctx->r12 = ADD32(ctx->r12, 0X1D48);
    // 0x801B5B78: addu        $v0, $t9, $t4
    ctx->r2 = ADD32(ctx->r25, ctx->r12);
    // 0x801B5B7C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_801B5B80:
    // 0x801B5B80: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801B5B84: slti        $at, $s0, 0x10
    ctx->r1 = SIGNED(ctx->r16) < 0X10 ? 1 : 0;
    // 0x801B5B88: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x801B5B8C: bne         $at, $zero, L_801B5B80
    if (ctx->r1 != 0) {
        // 0x801B5B90: sw          $zero, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = 0;
            goto L_801B5B80;
    }
    // 0x801B5B90: sw          $zero, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = 0;
    // 0x801B5B94: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B5B98: lwc1        $f10, -0x18C0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X18C0);
    // 0x801B5B9C: lui         $s5, 0x801C
    ctx->r21 = S32(0X801C << 16);
    // 0x801B5BA0: addiu       $s5, $s5, 0x2448
    ctx->r21 = ADD32(ctx->r21, 0X2448);
    // 0x801B5BA4: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x801B5BA8: addu        $t5, $s5, $v0
    ctx->r13 = ADD32(ctx->r21, ctx->r2);
    // 0x801B5BAC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B5BB0: swc1        $f10, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f10.u32l;
    // 0x801B5BB4: lwc1        $f16, -0x18BC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X18BC);
    // 0x801B5BB8: lui         $s6, 0x801C
    ctx->r22 = S32(0X801C << 16);
    // 0x801B5BBC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B5BC0: addiu       $s6, $s6, 0x1D48
    ctx->r22 = ADD32(ctx->r22, 0X1D48);
    // 0x801B5BC4: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x801B5BC8: sll         $t6, $v1, 6
    ctx->r14 = S32(ctx->r3 << 6);
    // 0x801B5BCC: addu        $a0, $s6, $t6
    ctx->r4 = ADD32(ctx->r22, ctx->r14);
    // 0x801B5BD0: addiu       $a1, $sp, 0xC4
    ctx->r5 = ADD32(ctx->r29, 0XC4);
    // 0x801B5BD4: jal         0x801B4AA8
    // 0x801B5BD8: swc1        $f16, 0x24B8($at)
    MEM_W(0X24B8, ctx->r1) = ctx->f16.u32l;
    Ground_801B4AA8(rdram, ctx);
        goto after_5;
    // 0x801B5BD8: swc1        $f16, 0x24B8($at)
    MEM_W(0X24B8, ctx->r1) = ctx->f16.u32l;
    after_5:
    // 0x801B5BDC: lui         $at, 0x435C
    ctx->r1 = S32(0X435C << 16);
    // 0x801B5BE0: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x801B5BE4: lui         $at, 0xC35C
    ctx->r1 = S32(0XC35C << 16);
    // 0x801B5BE8: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x801B5BEC: lui         $at, 0x44DC
    ctx->r1 = S32(0X44DC << 16);
    // 0x801B5BF0: lui         $s7, 0x801C
    ctx->r23 = S32(0X801C << 16);
    // 0x801B5BF4: lui         $s4, 0x801C
    ctx->r20 = S32(0X801C << 16);
    // 0x801B5BF8: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x801B5BFC: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x801B5C00: addiu       $s4, $s4, 0x5C04
    ctx->r20 = ADD32(ctx->r20, 0X5C04);
    // 0x801B5C04: addiu       $s7, $s7, -0x18B8
    ctx->r23 = ADD32(ctx->r23, -0X18B8);
    // 0x801B5C08: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801B5C0C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x801B5C10: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x801B5C14: addiu       $fp, $zero, 0xF
    ctx->r30 = ADD32(0, 0XF);
L_801B5C18:
    // 0x801B5C18: lw          $t7, 0x0($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X0);
    // 0x801B5C1C: sll         $t8, $t7, 9
    ctx->r24 = S32(ctx->r15 << 9);
    // 0x801B5C20: addu        $t9, $s7, $t8
    ctx->r25 = ADD32(ctx->r23, ctx->r24);
    // 0x801B5C24: addu        $v0, $t9, $s2
    ctx->r2 = ADD32(ctx->r25, ctx->r18);
    // 0x801B5C28: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x801B5C2C: beq         $s0, $zero, L_801B5C70
    if (ctx->r16 == 0) {
        // 0x801B5C30: addiu       $t1, $v0, 0x10
        ctx->r9 = ADD32(ctx->r2, 0X10);
            goto L_801B5C70;
    }
    // 0x801B5C30: addiu       $t1, $v0, 0x10
    ctx->r9 = ADD32(ctx->r2, 0X10);
    // 0x801B5C34: beq         $s0, $fp, L_801B5C70
    if (ctx->r16 == ctx->r30) {
        // 0x801B5C38: nop
    
            goto L_801B5C70;
    }
    // 0x801B5C38: nop

    // 0x801B5C3C: mtc1        $s0, $f4
    ctx->f4.u32l = ctx->r16;
    // 0x801B5C40: lw          $t4, 0x0($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X0);
    // 0x801B5C44: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801B5C48: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x801B5C4C: addu        $t6, $s5, $t5
    ctx->r14 = ADD32(ctx->r21, ctx->r13);
    // 0x801B5C50: lwc1        $f18, 0x0($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0X0);
    // 0x801B5C54: mul.s       $f8, $f6, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f26.fl);
    // 0x801B5C58: sub.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f20.fl;
    // 0x801B5C5C: mul.s       $f16, $f18, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x801B5C60: trunc.w.s   $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x801B5C64: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x801B5C68: b           L_801B5C88
    // 0x801B5C6C: sh          $t8, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r24;
        goto L_801B5C88;
    // 0x801B5C6C: sh          $t8, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r24;
L_801B5C70:
    // 0x801B5C70: bne         $s0, $zero, L_801B5C84
    if (ctx->r16 != 0) {
        // 0x801B5C74: addiu       $t4, $zero, 0xFA0
        ctx->r12 = ADD32(0, 0XFA0);
            goto L_801B5C84;
    }
    // 0x801B5C74: addiu       $t4, $zero, 0xFA0
    ctx->r12 = ADD32(0, 0XFA0);
    // 0x801B5C78: addiu       $t9, $zero, -0xFA0
    ctx->r25 = ADD32(0, -0XFA0);
    // 0x801B5C7C: b           L_801B5C88
    // 0x801B5C80: sh          $t9, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r25;
        goto L_801B5C88;
    // 0x801B5C80: sh          $t9, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r25;
L_801B5C84:
    // 0x801B5C84: sh          $t4, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r12;
L_801B5C88:
    // 0x801B5C88: beq         $s0, $zero, L_801B5CDC
    if (ctx->r16 == 0) {
        // 0x801B5C8C: nop
    
            goto L_801B5CDC;
    }
    // 0x801B5C8C: nop

    // 0x801B5C90: beq         $s0, $fp, L_801B5CDC
    if (ctx->r16 == ctx->r30) {
        // 0x801B5C94: nop
    
            goto L_801B5CDC;
    }
    // 0x801B5C94: nop

    // 0x801B5C98: lw          $t5, 0x0($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X0);
    // 0x801B5C9C: addiu       $at, $zero, 0x1C
    ctx->r1 = ADD32(0, 0X1C);
    // 0x801B5CA0: mtc1        $s0, $f8
    ctx->f8.u32l = ctx->r16;
    // 0x801B5CA4: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x801B5CA8: div         $zero, $t6, $at
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r1)));
    // 0x801B5CAC: cvt.s.w     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801B5CB0: mfhi        $t7
    ctx->r15 = hi;
    // 0x801B5CB4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x801B5CB8: addu        $t9, $s5, $t8
    ctx->r25 = ADD32(ctx->r21, ctx->r24);
    // 0x801B5CBC: lwc1        $f6, 0x0($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X0);
    // 0x801B5CC0: mul.s       $f10, $f18, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f26.fl);
    // 0x801B5CC4: sub.s       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f20.fl;
    // 0x801B5CC8: mul.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x801B5CCC: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x801B5CD0: mfc1        $t5, $f8
    ctx->r13 = (int32_t)ctx->f8.u32l;
    // 0x801B5CD4: b           L_801B5CF4
    // 0x801B5CD8: sh          $t5, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r13;
        goto L_801B5CF4;
    // 0x801B5CD8: sh          $t5, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r13;
L_801B5CDC:
    // 0x801B5CDC: bne         $s0, $zero, L_801B5CF0
    if (ctx->r16 != 0) {
        // 0x801B5CE0: addiu       $t7, $zero, 0xFA0
        ctx->r15 = ADD32(0, 0XFA0);
            goto L_801B5CF0;
    }
    // 0x801B5CE0: addiu       $t7, $zero, 0xFA0
    ctx->r15 = ADD32(0, 0XFA0);
    // 0x801B5CE4: addiu       $t6, $zero, -0xFA0
    ctx->r14 = ADD32(0, -0XFA0);
    // 0x801B5CE8: b           L_801B5CF4
    // 0x801B5CEC: sh          $t6, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r14;
        goto L_801B5CF4;
    // 0x801B5CEC: sh          $t6, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r14;
L_801B5CF0:
    // 0x801B5CF0: sh          $t7, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r15;
L_801B5CF4:
    // 0x801B5CF4: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    // 0x801B5CF8: addiu       $t3, $zero, 0x1C
    ctx->r11 = ADD32(0, 0X1C);
    // 0x801B5CFC: lui         $t2, 0x801C
    ctx->r10 = S32(0X801C << 16);
    // 0x801B5D00: sll         $t9, $t8, 6
    ctx->r25 = S32(ctx->r24 << 6);
    // 0x801B5D04: addu        $t4, $s6, $t9
    ctx->r12 = ADD32(ctx->r22, ctx->r25);
    // 0x801B5D08: addu        $t5, $t4, $s1
    ctx->r13 = ADD32(ctx->r12, ctx->r17);
    // 0x801B5D0C: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x801B5D10: addiu       $t2, $t2, 0x24B8
    ctx->r10 = ADD32(ctx->r10, 0X24B8);
    // 0x801B5D14: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801B5D18: sh          $t6, 0x2($t0)
    MEM_H(0X2, ctx->r8) = ctx->r14;
    // 0x801B5D1C: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    // 0x801B5D20: mfc1        $a1, $f24
    ctx->r5 = (int32_t)ctx->f24.u32l;
    // 0x801B5D24: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x801B5D28: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x801B5D2C: div         $zero, $t8, $t3
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r11))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r11)));
    // 0x801B5D30: mfhi        $t9
    ctx->r25 = hi;
    // 0x801B5D34: sll         $t4, $t9, 6
    ctx->r12 = S32(ctx->r25 << 6);
    // 0x801B5D38: addu        $t5, $s6, $t4
    ctx->r13 = ADD32(ctx->r22, ctx->r12);
    // 0x801B5D3C: addu        $t6, $t5, $s1
    ctx->r14 = ADD32(ctx->r13, ctx->r17);
    // 0x801B5D40: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x801B5D44: bne         $t3, $zero, L_801B5D50
    if (ctx->r11 != 0) {
        // 0x801B5D48: nop
    
            goto L_801B5D50;
    }
    // 0x801B5D48: nop

    // 0x801B5D4C: break       7
    do_break(2149277004);
L_801B5D50:
    // 0x801B5D50: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801B5D54: bne         $t3, $at, L_801B5D68
    if (ctx->r11 != ctx->r1) {
        // 0x801B5D58: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_801B5D68;
    }
    // 0x801B5D58: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801B5D5C: bne         $t8, $at, L_801B5D68
    if (ctx->r24 != ctx->r1) {
        // 0x801B5D60: nop
    
            goto L_801B5D68;
    }
    // 0x801B5D60: nop

    // 0x801B5D64: break       6
    do_break(2149277028);
L_801B5D68:
    // 0x801B5D68: sh          $t7, 0x2($t1)
    MEM_H(0X2, ctx->r9) = ctx->r15;
    // 0x801B5D6C: lw          $t8, 0x0($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X0);
    // 0x801B5D70: addiu       $at, $zero, 0x1B
    ctx->r1 = ADD32(0, 0X1B);
    // 0x801B5D74: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x801B5D78: addiu       $t9, $t8, 0x1B
    ctx->r25 = ADD32(ctx->r24, 0X1B);
    // 0x801B5D7C: div         $zero, $t9, $at
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r1)));
    // 0x801B5D80: mfhi        $t4
    ctx->r12 = hi;
    // 0x801B5D84: addiu       $t7, $v0, 0x1D
    ctx->r15 = ADD32(ctx->r2, 0X1D);
    // 0x801B5D88: sll         $t5, $t4, 9
    ctx->r13 = S32(ctx->r12 << 9);
    // 0x801B5D8C: div         $zero, $t7, $t3
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r11))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r11)));
    // 0x801B5D90: mfhi        $t8
    ctx->r24 = hi;
    // 0x801B5D94: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x801B5D98: addu        $t4, $t2, $t9
    ctx->r12 = ADD32(ctx->r10, ctx->r25);
    // 0x801B5D9C: lwc1        $f18, 0x0($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X0);
    // 0x801B5DA0: addu        $t6, $s7, $t5
    ctx->r14 = ADD32(ctx->r23, ctx->r13);
    // 0x801B5DA4: addu        $v1, $t6, $s2
    ctx->r3 = ADD32(ctx->r14, ctx->r18);
    // 0x801B5DA8: mul.s       $f10, $f18, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f22.fl);
    // 0x801B5DAC: bne         $t3, $zero, L_801B5DB8
    if (ctx->r11 != 0) {
        // 0x801B5DB0: nop
    
            goto L_801B5DB8;
    }
    // 0x801B5DB0: nop

    // 0x801B5DB4: break       7
    do_break(2149277108);
L_801B5DB8:
    // 0x801B5DB8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801B5DBC: bne         $t3, $at, L_801B5DD0
    if (ctx->r11 != ctx->r1) {
        // 0x801B5DC0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_801B5DD0;
    }
    // 0x801B5DC0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801B5DC4: bne         $t7, $at, L_801B5DD0
    if (ctx->r15 != ctx->r1) {
        // 0x801B5DC8: nop
    
            goto L_801B5DD0;
    }
    // 0x801B5DC8: nop

    // 0x801B5DCC: break       6
    do_break(2149277132);
L_801B5DD0:
    // 0x801B5DD0: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x801B5DD4: addu        $t8, $t2, $t7
    ctx->r24 = ADD32(ctx->r10, ctx->r15);
    // 0x801B5DD8: lwc1        $f16, 0x0($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X0);
    // 0x801B5DDC: trunc.w.s   $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x801B5DE0: sh          $zero, 0x14($v1)
    MEM_H(0X14, ctx->r3) = 0;
    // 0x801B5DE4: mul.s       $f4, $f16, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f22.fl);
    // 0x801B5DE8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x801B5DEC: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x801B5DF0: nop

    // 0x801B5DF4: sh          $t6, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r14;
    // 0x801B5DF8: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x801B5DFC: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x801B5E00: jal         0x80005B00
    // 0x801B5E04: nop

    Matrix_Translate(rdram, ctx);
        goto after_6;
    // 0x801B5E04: nop

    after_6:
    // 0x801B5E08: lw          $t9, 0x0($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X0);
    // 0x801B5E0C: lui         $t5, 0x801C
    ctx->r13 = S32(0X801C << 16);
    // 0x801B5E10: addiu       $t5, $t5, 0x5C18
    ctx->r13 = ADD32(ctx->r13, 0X5C18);
    // 0x801B5E14: sll         $t4, $t9, 6
    ctx->r12 = S32(ctx->r25 << 6);
    // 0x801B5E18: jal         0x80006500
    // 0x801B5E1C: addu        $a0, $t4, $t5
    ctx->r4 = ADD32(ctx->r12, ctx->r13);
    Matrix_ToMtx(rdram, ctx);
        goto after_7;
    // 0x801B5E1C: addu        $a0, $t4, $t5
    ctx->r4 = ADD32(ctx->r12, ctx->r13);
    after_7:
    // 0x801B5E20: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801B5E24: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x801B5E28: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x801B5E2C: bne         $s0, $at, L_801B5C18
    if (ctx->r16 != ctx->r1) {
        // 0x801B5E30: addiu       $s2, $s2, 0x20
        ctx->r18 = ADD32(ctx->r18, 0X20);
            goto L_801B5C18;
    }
    // 0x801B5E30: addiu       $s2, $s2, 0x20
    ctx->r18 = ADD32(ctx->r18, 0X20);
    // 0x801B5E34: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x801B5E38: lw          $a1, 0x0($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X0);
    // 0x801B5E3C: jal         0x801B5FE0
    // 0x801B5E40: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Ground_801B5FE0(rdram, ctx);
        goto after_8;
    // 0x801B5E40: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_8:
L_801B5E44:
    // 0x801B5E44: lui         $s4, 0x801C
    ctx->r20 = S32(0X801C << 16);
    // 0x801B5E48: addiu       $s4, $s4, 0x5C04
    ctx->r20 = ADD32(ctx->r20, 0X5C04);
    // 0x801B5E4C: lw          $a0, 0xC8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC8);
    // 0x801B5E50: lw          $s0, 0x0($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X0);
    // 0x801B5E54: lui         $t7, 0x104
    ctx->r15 = S32(0X104 << 16);
    // 0x801B5E58: ori         $t7, $t7, 0x40
    ctx->r15 = ctx->r15 | 0X40;
    // 0x801B5E5C: addiu       $t6, $s0, 0x8
    ctx->r14 = ADD32(ctx->r16, 0X8);
    // 0x801B5E60: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x801B5E64: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x801B5E68: lw          $t8, 0x78($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X78);
    // 0x801B5E6C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801B5E70: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
    // 0x801B5E74: jal         0x801B68A8
    // 0x801B5E78: lw          $a1, 0x0($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X0);
    Ground_801B68A8(rdram, ctx);
        goto after_9;
    // 0x801B5E78: lw          $a1, 0x0($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X0);
    after_9:
    // 0x801B5E7C: lw          $t9, 0xC8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC8);
    // 0x801B5E80: lui         $t5, 0xBD00
    ctx->r13 = S32(0XBD00 << 16);
    // 0x801B5E84: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801B5E88: lw          $s0, 0x0($t9)
    ctx->r16 = MEM_W(ctx->r25, 0X0);
    // 0x801B5E8C: addiu       $t4, $s0, 0x8
    ctx->r12 = ADD32(ctx->r16, 0X8);
    // 0x801B5E90: sw          $t4, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r12;
    // 0x801B5E94: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x801B5E98: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x801B5E9C: lw          $v0, 0x5C14($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X5C14);
    // 0x801B5EA0: andi        $a0, $v0, 0x1
    ctx->r4 = ctx->r2 & 0X1;
L_801B5EA4:
    // 0x801B5EA4: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801B5EA8: addiu       $v1, $v1, 0x5C10
    ctx->r3 = ADD32(ctx->r3, 0X5C10);
    // 0x801B5EAC: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x801B5EB0: lwc1        $f18, 0xCC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x801B5EB4: lui         $at, 0x435C
    ctx->r1 = S32(0X435C << 16);
    // 0x801B5EB8: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x801B5EBC: add.s       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x801B5EC0: lui         $s3, 0x801C
    ctx->r19 = S32(0X801C << 16);
    // 0x801B5EC4: lui         $s4, 0x801C
    ctx->r20 = S32(0X801C << 16);
    // 0x801B5EC8: addiu       $s4, $s4, 0x5C04
    ctx->r20 = ADD32(ctx->r20, 0X5C04);
    // 0x801B5ECC: addiu       $s3, $s3, 0x5C08
    ctx->r19 = ADD32(ctx->r19, 0X5C08);
    // 0x801B5ED0: beq         $a0, $zero, L_801B5F6C
    if (ctx->r4 == 0) {
        // 0x801B5ED4: swc1        $f10, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->f10.u32l;
            goto L_801B5F6C;
    }
    // 0x801B5ED4: swc1        $f10, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f10.u32l;
    // 0x801B5ED8: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x801B5EDC: addiu       $at, $zero, 0x1C
    ctx->r1 = ADD32(0, 0X1C);
    // 0x801B5EE0: lwc1        $f12, 0x0($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X0);
    // 0x801B5EE4: addiu       $t7, $t6, 0x19
    ctx->r15 = ADD32(ctx->r14, 0X19);
    // 0x801B5EE8: div         $zero, $t7, $at
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r1)));
    // 0x801B5EEC: mfhi        $t8
    ctx->r24 = hi;
    // 0x801B5EF0: sll         $t4, $t8, 2
    ctx->r12 = S32(ctx->r24 << 2);
    // 0x801B5EF4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B5EF8: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x801B5EFC: lwc1        $f6, 0x24B8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X24B8);
    // 0x801B5F00: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B5F04: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801B5F08: mul.s       $f14, $f6, $f26
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f14.fl = MUL_S(ctx->f6.fl, ctx->f26.fl);
    // 0x801B5F0C: c.le.s      $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl <= ctx->f12.fl;
    // 0x801B5F10: nop

    // 0x801B5F14: bc1fl       L_801B5F70
    if (!c1cs) {
        // 0x801B5F18: andi        $t5, $v0, 0x2
        ctx->r13 = ctx->r2 & 0X2;
            goto L_801B5F70;
    }
    goto skip_0;
    // 0x801B5F18: andi        $t5, $v0, 0x2
    ctx->r13 = ctx->r2 & 0X2;
    skip_0:
    // 0x801B5F1C: jal         0x80004E20
    // 0x801B5F20: sw          $t9, 0x5C0C($at)
    MEM_W(0X5C0C, ctx->r1) = ctx->r25;
    Math_ModF(rdram, ctx);
        goto after_10;
    // 0x801B5F20: sw          $t9, 0x5C0C($at)
    MEM_W(0X5C0C, ctx->r1) = ctx->r25;
    after_10:
    // 0x801B5F24: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B5F28: swc1        $f0, 0x5C10($at)
    MEM_W(0X5C10, ctx->r1) = ctx->f0.u32l;
    // 0x801B5F2C: lw          $t5, 0x0($s4)
    ctx->r13 = MEM_W(ctx->r20, 0X0);
    // 0x801B5F30: addiu       $at, $zero, 0x1B
    ctx->r1 = ADD32(0, 0X1B);
    // 0x801B5F34: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    // 0x801B5F38: addiu       $t6, $t5, 0x1A
    ctx->r14 = ADD32(ctx->r13, 0X1A);
    // 0x801B5F3C: div         $zero, $t6, $at
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r1)));
    // 0x801B5F40: mfhi        $t7
    ctx->r15 = hi;
    // 0x801B5F44: addiu       $at, $zero, 0x1C
    ctx->r1 = ADD32(0, 0X1C);
    // 0x801B5F48: addiu       $t4, $t8, 0x1B
    ctx->r12 = ADD32(ctx->r24, 0X1B);
    // 0x801B5F4C: div         $zero, $t4, $at
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r1)));
    // 0x801B5F50: mfhi        $t9
    ctx->r25 = hi;
    // 0x801B5F54: sw          $t7, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r15;
    // 0x801B5F58: sw          $t9, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r25;
    // 0x801B5F5C: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801B5F60: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801B5F64: addiu       $v1, $v1, 0x5C10
    ctx->r3 = ADD32(ctx->r3, 0X5C10);
    // 0x801B5F68: lw          $v0, 0x5C14($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X5C14);
L_801B5F6C:
    // 0x801B5F6C: andi        $t5, $v0, 0x2
    ctx->r13 = ctx->r2 & 0X2;
L_801B5F70:
    // 0x801B5F70: beq         $t5, $zero, L_801B5F94
    if (ctx->r13 == 0) {
        // 0x801B5F74: lui         $at, 0x801C
        ctx->r1 = S32(0X801C << 16);
            goto L_801B5F94;
    }
    // 0x801B5F74: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B5F78: lwc1        $f16, -0x18BC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X18BC);
    // 0x801B5F7C: lwc1        $f12, 0x0($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X0);
    // 0x801B5F80: mul.s       $f14, $f26, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = MUL_S(ctx->f26.fl, ctx->f16.fl);
    // 0x801B5F84: jal         0x80004E20
    // 0x801B5F88: nop

    Math_ModF(rdram, ctx);
        goto after_11;
    // 0x801B5F88: nop

    after_11:
    // 0x801B5F8C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B5F90: swc1        $f0, 0x5C10($at)
    MEM_W(0X5C10, ctx->r1) = ctx->f0.u32l;
L_801B5F94:
    // 0x801B5F94: lw          $t6, 0xC4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC4);
    // 0x801B5F98: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B5F9C: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x801B5FA0: sw          $t6, 0x5C14($at)
    MEM_W(0X5C14, ctx->r1) = ctx->r14;
    // 0x801B5FA4: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x801B5FA8: ldc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X30);
    // 0x801B5FAC: ldc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X38);
    // 0x801B5FB0: ldc1        $f26, 0x40($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X40);
    // 0x801B5FB4: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x801B5FB8: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x801B5FBC: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x801B5FC0: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x801B5FC4: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x801B5FC8: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x801B5FCC: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x801B5FD0: lw          $s7, 0x64($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X64);
    // 0x801B5FD4: lw          $fp, 0x68($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X68);
    // 0x801B5FD8: jr          $ra
    // 0x801B5FDC: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
    return;
    // 0x801B5FDC: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
;}
RECOMP_FUNC void Macbeth_MaSpear_Spawn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801AE610: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801AE614: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801AE618: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x801AE61C: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x801AE620: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x801AE624: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x801AE628: addiu       $v0, $v0, 0x3FE0
    ctx->r2 = ADD32(ctx->r2, 0X3FE0);
    // 0x801AE62C: addiu       $a0, $a0, -0x11E4
    ctx->r4 = ADD32(ctx->r4, -0X11E4);
    // 0x801AE630: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
L_801AE634:
    // 0x801AE634: bnel        $t6, $zero, L_801AE678
    if (ctx->r14 != 0) {
        // 0x801AE638: addiu       $a0, $a0, -0x2F4
        ctx->r4 = ADD32(ctx->r4, -0X2F4);
            goto L_801AE678;
    }
    goto skip_0;
    // 0x801AE638: addiu       $a0, $a0, -0x2F4
    ctx->r4 = ADD32(ctx->r4, -0X2F4);
    skip_0:
    // 0x801AE63C: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x801AE640: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x801AE644: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x801AE648: lh          $t7, 0x42($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X42);
    // 0x801AE64C: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x801AE650: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x801AE654: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x801AE658: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x801AE65C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x801AE660: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x801AE664: jal         0x801AE4CC
    // 0x801AE668: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    Macbeth_MaSpear_Setup(rdram, ctx);
        goto after_0;
    // 0x801AE668: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    after_0:
    // 0x801AE66C: b           L_801AE688
    // 0x801AE670: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_801AE688;
    // 0x801AE670: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801AE674: addiu       $a0, $a0, -0x2F4
    ctx->r4 = ADD32(ctx->r4, -0X2F4);
L_801AE678:
    // 0x801AE678: sltu        $at, $a0, $v0
    ctx->r1 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x801AE67C: beql        $at, $zero, L_801AE634
    if (ctx->r1 == 0) {
        // 0x801AE680: lbu         $t6, 0x0($a0)
        ctx->r14 = MEM_BU(ctx->r4, 0X0);
            goto L_801AE634;
    }
    goto skip_1;
    // 0x801AE680: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    skip_1:
    // 0x801AE684: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801AE688:
    // 0x801AE688: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801AE68C: jr          $ra
    // 0x801AE690: nop

    return;
    // 0x801AE690: nop

;}
RECOMP_FUNC void Titania_TiDesertRover_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801895B8: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x801895BC: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x801895C0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801895C4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x801895C8: lw          $t6, 0x58($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X58);
    // 0x801895CC: lh          $v0, 0xB8($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XB8);
    // 0x801895D0: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x801895D4: beq         $v0, $zero, L_801895F8
    if (ctx->r2 == 0) {
        // 0x801895D8: sw          $t7, 0x58($s0)
        MEM_W(0X58, ctx->r16) = ctx->r15;
            goto L_801895F8;
    }
    // 0x801895D8: sw          $t7, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->r15;
    // 0x801895DC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801895E0: beq         $v0, $at, L_80189650
    if (ctx->r2 == ctx->r1) {
        // 0x801895E4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80189650;
    }
    // 0x801895E4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801895E8: beql        $v0, $at, L_801896A8
    if (ctx->r2 == ctx->r1) {
        // 0x801895EC: lw          $t4, 0x50($s0)
        ctx->r12 = MEM_W(ctx->r16, 0X50);
            goto L_801896A8;
    }
    goto skip_0;
    // 0x801895EC: lw          $t4, 0x50($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X50);
    skip_0:
    // 0x801895F0: b           L_8018976C
    // 0x801895F4: lwc1        $f2, 0xC($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XC);
        goto L_8018976C;
    // 0x801895F4: lwc1        $f2, 0xC($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XC);
L_801895F8:
    // 0x801895F8: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x801895FC: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x80189600: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80189604: addiu       $t8, $t8, 0x5D3C
    ctx->r24 = ADD32(ctx->r24, 0X5D3C);
    // 0x80189608: lui         $a0, 0x3100
    ctx->r4 = S32(0X3100 << 16);
    // 0x8018960C: ori         $a0, $a0, 0x17
    ctx->r4 = ctx->r4 | 0X17;
    // 0x80189610: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80189614: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80189618: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x8018961C: jal         0x80019218
    // 0x80189620: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_0;
    // 0x80189620: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_0:
    // 0x80189624: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80189628: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018962C: lwc1        $f6, 0x18($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80189630: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80189634: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80189638: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8018963C: nop

    // 0x80189640: bc1fl       L_80189650
    if (!c1cs) {
        // 0x80189644: sh          $t0, 0xB8($s0)
        MEM_H(0XB8, ctx->r16) = ctx->r8;
            goto L_80189650;
    }
    goto skip_1;
    // 0x80189644: sh          $t0, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r8;
    skip_1:
    // 0x80189648: sw          $t9, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r25;
    // 0x8018964C: sh          $t0, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r8;
L_80189650:
    // 0x80189650: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80189654: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80189658: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8018965C: lwc1        $f2, 0xC($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80189660: swc1        $f8, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->f8.u32l;
    // 0x80189664: lw          $t1, -0x7D80($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X7D80);
    // 0x80189668: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018966C: lwc1        $f16, -0x5484($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X5484);
    // 0x80189670: lwc1        $f10, 0x138($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X138);
    // 0x80189674: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x80189678: addiu       $t3, $zero, 0x1E
    ctx->r11 = ADD32(0, 0X1E);
    // 0x8018967C: sub.s       $f0, $f2, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f10.fl;
    // 0x80189680: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80189684: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x80189688: nop

    // 0x8018968C: bc1f        L_8018976C
    if (!c1cs) {
        // 0x80189690: nop
    
            goto L_8018976C;
    }
    // 0x80189690: nop

    // 0x80189694: sh          $t2, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r10;
    // 0x80189698: sh          $t3, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r11;
    // 0x8018969C: b           L_8018976C
    // 0x801896A0: lwc1        $f2, 0xC($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XC);
        goto L_8018976C;
    // 0x801896A0: lwc1        $f2, 0xC($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XC);
    // 0x801896A4: lw          $t4, 0x50($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X50);
L_801896A8:
    // 0x801896A8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801896AC: bne         $t4, $at, L_80189700
    if (ctx->r12 != ctx->r1) {
        // 0x801896B0: lui         $at, 0x40A0
        ctx->r1 = S32(0X40A0 << 16);
            goto L_80189700;
    }
    // 0x801896B0: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x801896B4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801896B8: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x801896BC: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x801896C0: swc1        $f18, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->f18.u32l;
    // 0x801896C4: lw          $t5, -0x7D80($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X7D80);
    // 0x801896C8: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x801896CC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801896D0: lwc1        $f6, 0x138($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0X138);
    // 0x801896D4: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801896D8: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x801896DC: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x801896E0: nop

    // 0x801896E4: bc1f        L_801896F8
    if (!c1cs) {
        // 0x801896E8: nop
    
            goto L_801896F8;
    }
    // 0x801896E8: nop

    // 0x801896EC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801896F0: nop

    // 0x801896F4: swc1        $f10, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->f10.u32l;
L_801896F8:
    // 0x801896F8: jal         0x801891F4
    // 0x801896FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Titania_801891F4(rdram, ctx);
        goto after_1;
    // 0x801896FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
L_80189700:
    // 0x80189700: lhu         $t6, 0xBC($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0XBC);
    // 0x80189704: addiu       $t7, $zero, 0x28
    ctx->r15 = ADD32(0, 0X28);
    // 0x80189708: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018970C: bnel        $t6, $zero, L_8018976C
    if (ctx->r14 != 0) {
        // 0x80189710: lwc1        $f2, 0xC($s0)
        ctx->f2.u32l = MEM_W(ctx->r16, 0XC);
            goto L_8018976C;
    }
    goto skip_2;
    // 0x80189710: lwc1        $f2, 0xC($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XC);
    skip_2:
    // 0x80189714: jal         0x80189380
    // 0x80189718: sh          $t7, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r15;
    Titania_80189380(rdram, ctx);
        goto after_2;
    // 0x80189718: sh          $t7, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r15;
    after_2:
    // 0x8018971C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80189720: lw          $t8, -0x7D80($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7D80);
    // 0x80189724: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80189728: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8018972C: lwc1        $f18, 0x138($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0X138);
    // 0x80189730: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80189734: sub.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80189738: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8018973C: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80189740: nop

    // 0x80189744: bc1fl       L_8018976C
    if (!c1cs) {
        // 0x80189748: lwc1        $f2, 0xC($s0)
        ctx->f2.u32l = MEM_W(ctx->r16, 0XC);
            goto L_8018976C;
    }
    goto skip_3;
    // 0x80189748: lwc1        $f2, 0xC($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XC);
    skip_3:
    // 0x8018974C: lw          $t9, 0x50($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X50);
    // 0x80189750: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80189754: bne         $t9, $at, L_80189768
    if (ctx->r25 != ctx->r1) {
        // 0x80189758: lui         $at, 0xC120
        ctx->r1 = S32(0XC120 << 16);
            goto L_80189768;
    }
    // 0x80189758: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x8018975C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80189760: nop

    // 0x80189764: swc1        $f6, 0x12C($s0)
    MEM_W(0X12C, ctx->r16) = ctx->f6.u32l;
L_80189768:
    // 0x80189768: lwc1        $f2, 0xC($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XC);
L_8018976C:
    // 0x8018976C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80189770: lwc1        $f8, 0x7D20($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x80189774: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80189778: addiu       $t0, $sp, 0x40
    ctx->r8 = ADD32(ctx->r29, 0X40);
    // 0x8018977C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80189780: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    // 0x80189784: addiu       $a3, $sp, 0x3C
    ctx->r7 = ADD32(ctx->r29, 0X3C);
    // 0x80189788: jal         0x801B6E20
    // 0x8018978C: add.s       $f14, $f2, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f2.fl + ctx->f8.fl;
    Ground_801B6E20(rdram, ctx);
        goto after_3;
    // 0x8018978C: add.s       $f14, $f2, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f2.fl + ctx->f8.fl;
    after_3:
    // 0x80189790: lwc1        $f10, 0x3C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80189794: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80189798: lwc1        $f12, -0x5480($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X5480);
    // 0x8018979C: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
    // 0x801897A0: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
    // 0x801897A4: lwc1        $f0, 0x10($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X10);
    // 0x801897A8: mul.s       $f2, $f16, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x801897AC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x801897B0: nop

    // 0x801897B4: bc1f        L_801897DC
    if (!c1cs) {
        // 0x801897B8: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_801897DC;
    }
    // 0x801897B8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801897BC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x801897C0: nop

    // 0x801897C4: add.s       $f18, $f0, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f14.fl;
    // 0x801897C8: swc1        $f18, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f18.u32l;
    // 0x801897CC: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x801897D0: lwc1        $f0, 0x10($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X10);
    // 0x801897D4: mul.s       $f2, $f4, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x801897D8: nop

L_801897DC:
    // 0x801897DC: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x801897E0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801897E4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x801897E8: bc1fl       L_801897FC
    if (!c1cs) {
        // 0x801897EC: lwc1        $f8, 0x40($sp)
        ctx->f8.u32l = MEM_W(ctx->r29, 0X40);
            goto L_801897FC;
    }
    goto skip_4;
    // 0x801897EC: lwc1        $f8, 0x40($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X40);
    skip_4:
    // 0x801897F0: sub.s       $f6, $f0, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f14.fl;
    // 0x801897F4: swc1        $f6, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
    // 0x801897F8: lwc1        $f8, 0x40($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X40);
L_801897FC:
    // 0x801897FC: lwc1        $f0, 0x18($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80189800: mul.s       $f2, $f8, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x80189804: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80189808: nop

    // 0x8018980C: bc1fl       L_80189838
    if (!c1cs) {
        // 0x80189810: c.lt.s      $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
            goto L_80189838;
    }
    goto skip_5;
    // 0x80189810: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    skip_5:
    // 0x80189814: add.s       $f10, $f0, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f14.fl;
    // 0x80189818: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018981C: swc1        $f10, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f10.u32l;
    // 0x80189820: lwc1        $f18, -0x547C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X547C);
    // 0x80189824: lwc1        $f16, 0x40($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80189828: lwc1        $f0, 0x18($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8018982C: mul.s       $f2, $f16, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80189830: nop

    // 0x80189834: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
L_80189838:
    // 0x80189838: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018983C: bc1fl       L_80189850
    if (!c1cs) {
        // 0x80189840: lwc1        $f6, 0x14($s0)
        ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
            goto L_80189850;
    }
    goto skip_6;
    // 0x80189840: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    skip_6:
    // 0x80189844: sub.s       $f4, $f0, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f14.fl;
    // 0x80189848: swc1        $f4, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f4.u32l;
    // 0x8018984C: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
L_80189850:
    // 0x80189850: lwc1        $f8, -0x5478($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X5478);
    // 0x80189854: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80189858: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018985C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80189860: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80189864: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80189868: jal         0x80005E90
    // 0x8018986C: nop

    Matrix_RotateY(rdram, ctx);
        goto after_4;
    // 0x8018986C: nop

    after_4:
    // 0x80189870: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80189874: jal         0x80005708
    // 0x80189878: addiu       $a0, $a0, -0x4438
    ctx->r4 = ADD32(ctx->r4, -0X4438);
    Matrix_Push(rdram, ctx);
        goto after_5;
    // 0x80189878: addiu       $a0, $a0, -0x4438
    ctx->r4 = ADD32(ctx->r4, -0X4438);
    after_5:
    // 0x8018987C: lw          $t1, 0x58($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X58);
    // 0x80189880: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80189884: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x80189888: bne         $t2, $zero, L_801899AC
    if (ctx->r10 != 0) {
        // 0x8018988C: nop
    
            goto L_801899AC;
    }
    // 0x8018988C: nop

    // 0x80189890: lwc1        $f16, -0x5474($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X5474);
    // 0x80189894: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80189898: lwc1        $f4, 0x7D20($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x8018989C: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x801898A0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801898A4: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x801898A8: c.lt.s      $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f16.fl < ctx->f6.fl;
    // 0x801898AC: nop

    // 0x801898B0: bc1f        L_801899AC
    if (!c1cs) {
        // 0x801898B4: nop
    
            goto L_801899AC;
    }
    // 0x801898B4: nop

    // 0x801898B8: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x801898BC: lwc1        $f10, -0x5470($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X5470);
    // 0x801898C0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801898C4: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801898C8: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x801898CC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801898D0: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x801898D4: jal         0x80005D44
    // 0x801898D8: nop

    Matrix_RotateX(rdram, ctx);
        goto after_6;
    // 0x801898D8: nop

    after_6:
    // 0x801898DC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801898E0: lwc1        $f16, -0x546C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X546C);
    // 0x801898E4: lwc1        $f4, 0x18($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X18);
    // 0x801898E8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801898EC: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801898F0: mul.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x801898F4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801898F8: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x801898FC: jal         0x80005FE0
    // 0x80189900: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_7;
    // 0x80189900: nop

    after_7:
    // 0x80189904: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80189908: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x8018990C: addiu       $a1, $a1, 0x752C
    ctx->r5 = ADD32(ctx->r5, 0X752C);
    // 0x80189910: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80189914: jal         0x80006A20
    // 0x80189918: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_8;
    // 0x80189918: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    after_8:
    // 0x8018991C: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80189920: lwc1        $f16, 0x50($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80189924: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80189928: lwc1        $f10, 0x48($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8018992C: add.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x80189930: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80189934: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80189938: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8018993C: lwc1        $f8, -0x5468($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X5468);
    // 0x80189940: lwc1        $f18, 0x4C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80189944: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80189948: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8018994C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x80189950: jal         0x80189120
    // 0x80189954: add.s       $f14, $f0, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f0.fl + ctx->f18.fl;
    Titania_TankTracks_Spawn(rdram, ctx);
        goto after_9;
    // 0x80189954: add.s       $f14, $f0, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f0.fl + ctx->f18.fl;
    after_9:
    // 0x80189958: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018995C: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x80189960: addiu       $a1, $a1, 0x7538
    ctx->r5 = ADD32(ctx->r5, 0X7538);
    // 0x80189964: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80189968: jal         0x80006A20
    // 0x8018996C: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_10;
    // 0x8018996C: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    after_10:
    // 0x80189970: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80189974: lwc1        $f6, 0x50($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80189978: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8018997C: lwc1        $f18, 0x48($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80189980: add.s       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x80189984: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80189988: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018998C: add.s       $f12, $f10, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x80189990: lwc1        $f10, -0x5464($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X5464);
    // 0x80189994: lwc1        $f4, 0x4C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80189998: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x8018999C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x801899A0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x801899A4: jal         0x80189120
    // 0x801899A8: add.s       $f14, $f0, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f0.fl + ctx->f4.fl;
    Titania_TankTracks_Spawn(rdram, ctx);
        goto after_11;
    // 0x801899A8: add.s       $f14, $f0, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f0.fl + ctx->f4.fl;
    after_11:
L_801899AC:
    // 0x801899AC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801899B0: lwc1        $f18, -0x5460($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X5460);
    // 0x801899B4: lw          $a1, 0x130($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X130);
    // 0x801899B8: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x801899BC: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801899C0: addiu       $a0, $s0, 0x12C
    ctx->r4 = ADD32(ctx->r16, 0X12C);
    // 0x801899C4: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x801899C8: jal         0x8009BC2C
    // 0x801899CC: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_12;
    // 0x801899CC: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_12:
    // 0x801899D0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801899D4: jal         0x80005740
    // 0x801899D8: addiu       $a0, $a0, -0x4438
    ctx->r4 = ADD32(ctx->r4, -0X4438);
    Matrix_Pop(rdram, ctx);
        goto after_13;
    // 0x801899D8: addiu       $a0, $a0, -0x4438
    ctx->r4 = ADD32(ctx->r4, -0X4438);
    after_13:
    // 0x801899DC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801899E0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801899E4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801899E8: swc1        $f4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f4.u32l;
    // 0x801899EC: swc1        $f16, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f16.u32l;
    // 0x801899F0: lwc1        $f6, 0x12C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X12C);
    // 0x801899F4: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801899F8: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x801899FC: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    // 0x80189A00: jal         0x80006970
    // 0x80189A04: swc1        $f6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f6.u32l;
    Matrix_MultVec3f(rdram, ctx);
        goto after_14;
    // 0x80189A04: swc1        $f6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f6.u32l;
    after_14:
    // 0x80189A08: lwc1        $f8, 0x48($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80189A0C: lb          $t3, 0xD0($s0)
    ctx->r11 = MEM_B(ctx->r16, 0XD0);
    // 0x80189A10: addiu       $t4, $s0, 0x100
    ctx->r12 = ADD32(ctx->r16, 0X100);
    // 0x80189A14: swc1        $f8, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f8.u32l;
    // 0x80189A18: lwc1        $f10, 0x4C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80189A1C: swc1        $f10, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f10.u32l;
    // 0x80189A20: lwc1        $f18, 0x50($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80189A24: blez        $t3, L_80189AE8
    if (SIGNED(ctx->r11) <= 0) {
        // 0x80189A28: swc1        $f18, 0xF0($s0)
        MEM_W(0XF0, ctx->r16) = ctx->f18.u32l;
            goto L_80189AE8;
    }
    // 0x80189A28: swc1        $f18, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f18.u32l;
    // 0x80189A2C: jal         0x80004EB0
    // 0x80189A30: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
    Rand_ZeroOne(rdram, ctx);
        goto after_15;
    // 0x80189A30: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
    after_15:
    // 0x80189A34: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80189A38: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80189A3C: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x80189A40: c.le.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl <= ctx->f4.fl;
    // 0x80189A44: nop

    // 0x80189A48: bc1fl       L_80189A5C
    if (!c1cs) {
        // 0x80189A4C: sb          $zero, 0x44($s0)
        MEM_B(0X44, ctx->r16) = 0;
            goto L_80189A5C;
    }
    goto skip_7;
    // 0x80189A4C: sb          $zero, 0x44($s0)
    MEM_B(0X44, ctx->r16) = 0;
    skip_7:
    // 0x80189A50: b           L_80189A5C
    // 0x80189A54: sb          $t5, 0x44($s0)
    MEM_B(0X44, ctx->r16) = ctx->r13;
        goto L_80189A5C;
    // 0x80189A54: sb          $t5, 0x44($s0)
    MEM_B(0X44, ctx->r16) = ctx->r13;
    // 0x80189A58: sb          $zero, 0x44($s0)
    MEM_B(0X44, ctx->r16) = 0;
L_80189A5C:
    // 0x80189A5C: jal         0x80066254
    // 0x80189A60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Actor_Despawn(rdram, ctx);
        goto after_16;
    // 0x80189A60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80189A64: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80189A68: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80189A6C: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80189A70: sb          $zero, 0x3C($s0)
    MEM_B(0X3C, ctx->r16) = 0;
    // 0x80189A74: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80189A78: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x80189A7C: lui         $a3, 0x4100
    ctx->r7 = S32(0X4100 << 16);
    // 0x80189A80: jal         0x8007D2C8
    // 0x80189A84: add.s       $f14, $f16, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f6.fl;
    Effect_FireSmoke1_Spawn3(rdram, ctx);
        goto after_17;
    // 0x80189A84: add.s       $f14, $f16, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f6.fl;
    after_17:
    // 0x80189A88: lwc1        $f18, 0xEC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x80189A8C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80189A90: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80189A94: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80189A98: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80189A9C: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x80189AA0: lw          $a3, 0xE8($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XE8);
    // 0x80189AA4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80189AA8: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x80189AAC: lwc1        $f4, 0xF0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XF0);
    // 0x80189AB0: lwc1        $f16, -0x545C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X545C);
    // 0x80189AB4: addiu       $t6, $zero, 0x1E
    ctx->r14 = ADD32(0, 0X1E);
    // 0x80189AB8: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x80189ABC: add.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80189AC0: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x80189AC4: jal         0x8007C120
    // 0x80189AC8: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    Effect_Effect390_Spawn(rdram, ctx);
        goto after_18;
    // 0x80189AC8: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    after_18:
    // 0x80189ACC: lui         $a1, 0x2903
    ctx->r5 = S32(0X2903 << 16);
    // 0x80189AD0: ori         $a1, $a1, 0xA008
    ctx->r5 = ctx->r5 | 0XA008;
    // 0x80189AD4: jal         0x8007A6F0
    // 0x80189AD8: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    Effect_TimedSfx_Spawn(rdram, ctx);
        goto after_19;
    // 0x80189AD8: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    after_19:
    // 0x80189ADC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80189AE0: jal         0x80060FBC
    // 0x80189AE4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    Object_Kill(rdram, ctx);
        goto after_20;
    // 0x80189AE4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_20:
L_80189AE8:
    // 0x80189AE8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80189AEC: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80189AF0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x80189AF4: jr          $ra
    // 0x80189AF8: nop

    return;
    // 0x80189AF8: nop

;}
RECOMP_FUNC void Titania_TiDelphor_Init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018E3CC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8018E3D0: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8018E3D4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8018E3D8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8018E3DC: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8018E3E0: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // 0x8018E3E4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018E3E8: lwc1        $f6, 0x7D20($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x8018E3EC: lwc1        $f4, 0xC($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8018E3F0: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8018E3F4: sw          $a2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r6;
    // 0x8018E3F8: addiu       $a3, $s1, 0x8
    ctx->r7 = ADD32(ctx->r17, 0X8);
    // 0x8018E3FC: jal         0x801B6E20
    // 0x8018E400: add.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f6.fl;
    Ground_801B6E20(rdram, ctx);
        goto after_0;
    // 0x8018E400: add.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f6.fl;
    after_0:
    // 0x8018E404: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8018E408: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018E40C: lwc1        $f8, 0x8($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8018E410: lui         $s0, 0x8016
    ctx->r16 = S32(0X8016 << 16);
    // 0x8018E414: addiu       $s0, $s0, 0x3FE0
    ctx->r16 = ADD32(ctx->r16, 0X3FE0);
    // 0x8018E418: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8018E41C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8018E420: addiu       $v1, $zero, 0x3C
    ctx->r3 = ADD32(0, 0X3C);
    // 0x8018E424: swc1        $f16, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f16.u32l;
L_8018E428:
    // 0x8018E428: lbu         $t6, 0x0($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X0);
    // 0x8018E42C: bne         $t6, $zero, L_8018E51C
    if (ctx->r14 != 0) {
        // 0x8018E430: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8018E51C;
    }
    // 0x8018E430: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018E434: jal         0x800613C4
    // 0x8018E438: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    Actor_Initialize(rdram, ctx);
        goto after_1;
    // 0x8018E438: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    after_1:
    // 0x8018E43C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8018E440: addiu       $t8, $zero, 0xE4
    ctx->r24 = ADD32(0, 0XE4);
    // 0x8018E444: sb          $t7, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r15;
    // 0x8018E448: sh          $t8, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r24;
    // 0x8018E44C: andi        $a1, $t8, 0xFFFF
    ctx->r5 = ctx->r24 & 0XFFFF;
    // 0x8018E450: jal         0x800612B8
    // 0x8018E454: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    Object_SetInfo(rdram, ctx);
        goto after_2;
    // 0x8018E454: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    after_2:
    // 0x8018E458: lui         $a3, 0x801B
    ctx->r7 = S32(0X801B << 16);
    // 0x8018E45C: sw          $s1, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r17;
    // 0x8018E460: addiu       $a3, $a3, 0x7518
    ctx->r7 = ADD32(ctx->r7, 0X7518);
    // 0x8018E464: sw          $s0, 0x50($s1)
    MEM_W(0X50, ctx->r17) = ctx->r16;
    // 0x8018E468: lwc1        $f18, 0x0($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X0);
    // 0x8018E46C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8018E470: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018E474: swc1        $f18, 0x12C($s0)
    MEM_W(0X12C, ctx->r16) = ctx->f18.u32l;
    // 0x8018E478: lwc1        $f6, 0x0($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X0);
    // 0x8018E47C: lwc1        $f4, 0x4($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X4);
    // 0x8018E480: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018E484: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018E488: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8018E48C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8018E490: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8018E494: swc1        $f16, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f16.u32l;
    // 0x8018E498: lwc1        $f4, -0x5338($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X5338);
    // 0x8018E49C: lwc1        $f18, 0x14($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8018E4A0: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018E4A4: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8018E4A8: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8018E4AC: jal         0x80005E90
    // 0x8018E4B0: nop

    Matrix_RotateY(rdram, ctx);
        goto after_3;
    // 0x8018E4B0: nop

    after_3:
    // 0x8018E4B4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018E4B8: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x8018E4BC: addiu       $a1, $a1, 0x7678
    ctx->r5 = ADD32(ctx->r5, 0X7678);
    // 0x8018E4C0: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018E4C4: jal         0x80006970
    // 0x8018E4C8: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    Matrix_MultVec3f(rdram, ctx);
        goto after_4;
    // 0x8018E4C8: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    after_4:
    // 0x8018E4CC: lwc1        $f8, 0x4($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8018E4D0: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8018E4D4: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x8018E4D8: addiu       $v1, $zero, 0x3C
    ctx->r3 = ADD32(0, 0X3C);
    // 0x8018E4DC: add.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8018E4E0: swc1        $f0, 0x114($s1)
    MEM_W(0X114, ctx->r17) = ctx->f0.u32l;
    // 0x8018E4E4: swc1        $f0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f0.u32l;
    // 0x8018E4E8: lwc1        $f18, 0x38($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8018E4EC: lwc1        $f16, 0x8($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8018E4F0: add.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8018E4F4: swc1        $f0, 0x118($s1)
    MEM_W(0X118, ctx->r17) = ctx->f0.u32l;
    // 0x8018E4F8: swc1        $f0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
    // 0x8018E4FC: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8018E500: lwc1        $f4, 0xC($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8018E504: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8018E508: swc1        $f0, 0x11C($s1)
    MEM_W(0X11C, ctx->r17) = ctx->f0.u32l;
    // 0x8018E50C: swc1        $f0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f0.u32l;
    // 0x8018E510: lwc1        $f8, 0x14($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8018E514: b           L_8018E528
    // 0x8018E518: swc1        $f8, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f8.u32l;
        goto L_8018E528;
    // 0x8018E518: swc1        $f8, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f8.u32l;
L_8018E51C:
    // 0x8018E51C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8018E520: bne         $v0, $v1, L_8018E428
    if (ctx->r2 != ctx->r3) {
        // 0x8018E524: addiu       $s0, $s0, 0x2F4
        ctx->r16 = ADD32(ctx->r16, 0X2F4);
            goto L_8018E428;
    }
    // 0x8018E524: addiu       $s0, $s0, 0x2F4
    ctx->r16 = ADD32(ctx->r16, 0X2F4);
L_8018E528:
    // 0x8018E528: bne         $v0, $v1, L_8018E538
    if (ctx->r2 != ctx->r3) {
        // 0x8018E52C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8018E538;
    }
    // 0x8018E52C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8018E530: jal         0x80060FBC
    // 0x8018E534: addiu       $a1, $s1, 0x100
    ctx->r5 = ADD32(ctx->r17, 0X100);
    Object_Kill(rdram, ctx);
        goto after_5;
    // 0x8018E534: addiu       $a1, $s1, 0x100
    ctx->r5 = ADD32(ctx->r17, 0X100);
    after_5:
L_8018E538:
    // 0x8018E538: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8018E53C: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8018E540: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8018E544: jr          $ra
    // 0x8018E548: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8018E548: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void Macbeth_MaLocomotive_OverrideLimbDraw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A0EB8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801A0EBC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x801A0EC0: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x801A0EC4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801A0EC8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x801A0ECC: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x801A0ED0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801A0ED4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801A0ED8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x801A0EDC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x801A0EE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801A0EE4: jal         0x800B8DD0
    // 0x801A0EE8: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x801A0EE8: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    after_0:
    // 0x801A0EEC: lui         $a1, 0x4
    ctx->r5 = S32(0X4 << 16);
    // 0x801A0EF0: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x801A0EF4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801A0EF8: lui         $t7, 0xB600
    ctx->r15 = S32(0XB600 << 16);
    // 0x801A0EFC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801A0F00: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801A0F04: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x801A0F08: sw          $a1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r5;
    // 0x801A0F0C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801A0F10: beq         $s1, $at, L_801A0F2C
    if (ctx->r17 == ctx->r1) {
        // 0x801A0F14: lui         $t9, 0xBB00
        ctx->r25 = S32(0XBB00 << 16);
            goto L_801A0F2C;
    }
    // 0x801A0F14: lui         $t9, 0xBB00
    ctx->r25 = S32(0XBB00 << 16);
    // 0x801A0F18: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x801A0F1C: beq         $s1, $at, L_801A0F2C
    if (ctx->r17 == ctx->r1) {
        // 0x801A0F20: addiu       $at, $zero, 0x9
        ctx->r1 = ADD32(0, 0X9);
            goto L_801A0F2C;
    }
    // 0x801A0F20: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x801A0F24: bnel        $s1, $at, L_801A0F68
    if (ctx->r17 != ctx->r1) {
        // 0x801A0F28: addiu       $a1, $zero, 0x5
        ctx->r5 = ADD32(0, 0X5);
            goto L_801A0F68;
    }
    goto skip_0;
    // 0x801A0F28: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    skip_0:
L_801A0F2C:
    // 0x801A0F2C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801A0F30: lui         $t2, 0xBB8
    ctx->r10 = S32(0XBB8 << 16);
    // 0x801A0F34: ori         $t2, $t2, 0xBB8
    ctx->r10 = ctx->r10 | 0XBB8;
    // 0x801A0F38: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x801A0F3C: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x801A0F40: ori         $t9, $t9, 0x1
    ctx->r25 = ctx->r25 | 0X1;
    // 0x801A0F44: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x801A0F48: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x801A0F4C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801A0F50: lui         $t4, 0xB700
    ctx->r12 = S32(0XB700 << 16);
    // 0x801A0F54: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x801A0F58: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x801A0F5C: sw          $a1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r5;
    // 0x801A0F60: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x801A0F64: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
L_801A0F68:
    // 0x801A0F68: beq         $s1, $a1, L_801A0F78
    if (ctx->r17 == ctx->r5) {
        // 0x801A0F6C: addiu       $at, $zero, 0x9
        ctx->r1 = ADD32(0, 0X9);
            goto L_801A0F78;
    }
    // 0x801A0F6C: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x801A0F70: bnel        $s1, $at, L_801A11F8
    if (ctx->r17 != ctx->r1) {
        // 0x801A0F74: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_801A11F8;
    }
    goto skip_1;
    // 0x801A0F74: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    skip_1:
L_801A0F78:
    // 0x801A0F78: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x801A0F7C: lw          $a0, 0x6C($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X6C);
    // 0x801A0F80: andi        $t5, $a0, 0x1
    ctx->r13 = ctx->r4 & 0X1;
    // 0x801A0F84: beq         $t5, $zero, L_801A0FC4
    if (ctx->r13 == 0) {
        // 0x801A0F88: nop
    
            goto L_801A0FC4;
    }
    // 0x801A0F88: nop

    // 0x801A0F8C: jal         0x800BA400
    // 0x801A0F90: nop

    RCP_SetupDL_27(rdram, ctx);
        goto after_1;
    // 0x801A0F90: nop

    after_1:
    // 0x801A0F94: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x801A0F98: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x801A0F9C: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x801A0FA0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801A0FA4: lui         $t8, 0xFF00
    ctx->r24 = S32(0XFF00 << 16);
    // 0x801A0FA8: ori         $t8, $t8, 0xFF
    ctx->r24 = ctx->r24 | 0XFF;
    // 0x801A0FAC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801A0FB0: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x801A0FB4: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x801A0FB8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801A0FBC: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x801A0FC0: lw          $a0, 0x6C($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X6C);
L_801A0FC4:
    // 0x801A0FC4: blezl       $a0, L_801A0FDC
    if (SIGNED(ctx->r4) <= 0) {
        // 0x801A0FC8: lwc1        $f4, 0x0($t1)
        ctx->f4.u32l = MEM_W(ctx->r9, 0X0);
            goto L_801A0FDC;
    }
    goto skip_2;
    // 0x801A0FC8: lwc1        $f4, 0x0($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X0);
    skip_2:
    // 0x801A0FCC: bne         $s1, $a1, L_801A0FD8
    if (ctx->r17 != ctx->r5) {
        // 0x801A0FD0: addiu       $t9, $a0, -0x1
        ctx->r25 = ADD32(ctx->r4, -0X1);
            goto L_801A0FD8;
    }
    // 0x801A0FD0: addiu       $t9, $a0, -0x1
    ctx->r25 = ADD32(ctx->r4, -0X1);
    // 0x801A0FD4: sw          $t9, 0x6C($t0)
    MEM_W(0X6C, ctx->r8) = ctx->r25;
L_801A0FD8:
    // 0x801A0FD8: lwc1        $f4, 0x0($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X0);
L_801A0FDC:
    // 0x801A0FDC: lwc1        $f6, 0x11C($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X11C);
    // 0x801A0FE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801A0FE4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801A0FE8: bne         $s1, $a1, L_801A11F4
    if (ctx->r17 != ctx->r5) {
        // 0x801A0FEC: swc1        $f8, 0x0($t1)
        MEM_W(0X0, ctx->r9) = ctx->f8.u32l;
            goto L_801A11F4;
    }
    // 0x801A0FEC: swc1        $f8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f8.u32l;
    // 0x801A0FF0: jal         0x800B8DD0
    // 0x801A0FF4: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    RCP_SetupDL(rdram, ctx);
        goto after_2;
    // 0x801A0FF4: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    after_2:
    // 0x801A0FF8: lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // 0x801A0FFC: addiu       $a3, $a3, -0x1C98
    ctx->r7 = ADD32(ctx->r7, -0X1C98);
    // 0x801A1000: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x801A1004: lui         $t3, 0xFA00
    ctx->r11 = S32(0XFA00 << 16);
    // 0x801A1008: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x801A100C: addiu       $t2, $v1, 0x8
    ctx->r10 = ADD32(ctx->r3, 0X8);
    // 0x801A1010: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x801A1014: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801A1018: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x801A101C: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x801A1020: lwc1        $f10, 0x58($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X58);
    // 0x801A1024: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801A1028: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801A102C: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x801A1030: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x801A1034: nop

    // 0x801A1038: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x801A103C: beql        $t5, $zero, L_801A108C
    if (ctx->r13 == 0) {
        // 0x801A1040: mfc1        $t5, $f16
        ctx->r13 = (int32_t)ctx->f16.u32l;
            goto L_801A108C;
    }
    goto skip_3;
    // 0x801A1040: mfc1        $t5, $f16
    ctx->r13 = (int32_t)ctx->f16.u32l;
    skip_3:
    // 0x801A1044: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801A1048: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801A104C: sub.s       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x801A1050: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x801A1054: nop

    // 0x801A1058: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x801A105C: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x801A1060: nop

    // 0x801A1064: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x801A1068: bne         $t5, $zero, L_801A1080
    if (ctx->r13 != 0) {
        // 0x801A106C: nop
    
            goto L_801A1080;
    }
    // 0x801A106C: nop

    // 0x801A1070: mfc1        $t5, $f16
    ctx->r13 = (int32_t)ctx->f16.u32l;
    // 0x801A1074: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801A1078: b           L_801A1098
    // 0x801A107C: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
        goto L_801A1098;
    // 0x801A107C: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
L_801A1080:
    // 0x801A1080: b           L_801A1098
    // 0x801A1084: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
        goto L_801A1098;
    // 0x801A1084: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x801A1088: mfc1        $t5, $f16
    ctx->r13 = (int32_t)ctx->f16.u32l;
L_801A108C:
    // 0x801A108C: nop

    // 0x801A1090: bltz        $t5, L_801A1080
    if (SIGNED(ctx->r13) < 0) {
        // 0x801A1094: nop
    
            goto L_801A1080;
    }
    // 0x801A1094: nop

L_801A1098:
    // 0x801A1098: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x801A109C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801A10A0: lwc1        $f18, 0x50($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X50);
    // 0x801A10A4: andi        $t6, $t5, 0xFF
    ctx->r14 = ctx->r13 & 0XFF;
    // 0x801A10A8: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x801A10AC: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x801A10B0: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x801A10B4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801A10B8: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x801A10BC: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x801A10C0: nop

    // 0x801A10C4: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x801A10C8: beql        $t9, $zero, L_801A1118
    if (ctx->r25 == 0) {
        // 0x801A10CC: mfc1        $t9, $f4
        ctx->r25 = (int32_t)ctx->f4.u32l;
            goto L_801A1118;
    }
    goto skip_4;
    // 0x801A10CC: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    skip_4:
    // 0x801A10D0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801A10D4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801A10D8: sub.s       $f4, $f18, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x801A10DC: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x801A10E0: nop

    // 0x801A10E4: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801A10E8: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x801A10EC: nop

    // 0x801A10F0: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x801A10F4: bne         $t9, $zero, L_801A110C
    if (ctx->r25 != 0) {
        // 0x801A10F8: nop
    
            goto L_801A110C;
    }
    // 0x801A10F8: nop

    // 0x801A10FC: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x801A1100: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801A1104: b           L_801A1124
    // 0x801A1108: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_801A1124;
    // 0x801A1108: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_801A110C:
    // 0x801A110C: b           L_801A1124
    // 0x801A1110: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_801A1124;
    // 0x801A1110: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x801A1114: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
L_801A1118:
    // 0x801A1118: nop

    // 0x801A111C: bltz        $t9, L_801A110C
    if (SIGNED(ctx->r25) < 0) {
        // 0x801A1120: nop
    
            goto L_801A110C;
    }
    // 0x801A1120: nop

L_801A1124:
    // 0x801A1124: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x801A1128: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801A112C: lwc1        $f6, 0x54($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X54);
    // 0x801A1130: sll         $t3, $t9, 24
    ctx->r11 = S32(ctx->r25 << 24);
    // 0x801A1134: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x801A1138: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x801A113C: or          $t4, $t7, $t3
    ctx->r12 = ctx->r15 | ctx->r11;
    // 0x801A1140: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801A1144: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801A1148: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x801A114C: nop

    // 0x801A1150: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x801A1154: beql        $t6, $zero, L_801A11A4
    if (ctx->r14 == 0) {
        // 0x801A1158: mfc1        $t6, $f8
        ctx->r14 = (int32_t)ctx->f8.u32l;
            goto L_801A11A4;
    }
    goto skip_5;
    // 0x801A1158: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    skip_5:
    // 0x801A115C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801A1160: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801A1164: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x801A1168: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x801A116C: nop

    // 0x801A1170: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x801A1174: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x801A1178: nop

    // 0x801A117C: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x801A1180: bne         $t6, $zero, L_801A1198
    if (ctx->r14 != 0) {
        // 0x801A1184: nop
    
            goto L_801A1198;
    }
    // 0x801A1184: nop

    // 0x801A1188: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    // 0x801A118C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801A1190: b           L_801A11B0
    // 0x801A1194: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
        goto L_801A11B0;
    // 0x801A1194: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
L_801A1198:
    // 0x801A1198: b           L_801A11B0
    // 0x801A119C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
        goto L_801A11B0;
    // 0x801A119C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x801A11A0: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
L_801A11A4:
    // 0x801A11A4: nop

    // 0x801A11A8: bltz        $t6, L_801A1198
    if (SIGNED(ctx->r14) < 0) {
        // 0x801A11AC: nop
    
            goto L_801A1198;
    }
    // 0x801A11AC: nop

L_801A11B0:
    // 0x801A11B0: andi        $t8, $t6, 0xFF
    ctx->r24 = ctx->r14 & 0XFF;
    // 0x801A11B4: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x801A11B8: or          $t2, $t4, $t9
    ctx->r10 = ctx->r12 | ctx->r25;
    // 0x801A11BC: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x801A11C0: ori         $t7, $t2, 0xFF
    ctx->r15 = ctx->r10 | 0XFF;
    // 0x801A11C4: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x801A11C8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801A11CC: lui         $t6, 0x601
    ctx->r14 = S32(0X601 << 16);
    // 0x801A11D0: addiu       $t6, $t6, 0x470
    ctx->r14 = ADD32(ctx->r14, 0X470);
    // 0x801A11D4: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x801A11D8: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x801A11DC: lui         $t5, 0x600
    ctx->r13 = S32(0X600 << 16);
    // 0x801A11E0: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x801A11E4: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x801A11E8: jal         0x800B8DD0
    // 0x801A11EC: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    RCP_SetupDL(rdram, ctx);
        goto after_3;
    // 0x801A11EC: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    after_3:
    // 0x801A11F0: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
L_801A11F4:
    // 0x801A11F4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_801A11F8:
    // 0x801A11F8: beq         $s1, $at, L_801A1214
    if (ctx->r17 == ctx->r1) {
        // 0x801A11FC: lw          $t0, 0x30($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X30);
            goto L_801A1214;
    }
    // 0x801A11FC: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x801A1200: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801A1204: beql        $s1, $at, L_801A1238
    if (ctx->r17 == ctx->r1) {
        // 0x801A1208: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_801A1238;
    }
    goto skip_6;
    // 0x801A1208: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    skip_6:
    // 0x801A120C: b           L_801A1254
    // 0x801A1210: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801A1254;
    // 0x801A1210: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801A1214:
    // 0x801A1214: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801A1218: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801A121C: lwc1        $f10, 0x120($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X120);
    // 0x801A1220: lwc1        $f4, 0x0($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X0);
    // 0x801A1224: div.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x801A1228: add.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x801A122C: b           L_801A1250
    // 0x801A1230: swc1        $f6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f6.u32l;
        goto L_801A1250;
    // 0x801A1230: swc1        $f6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f6.u32l;
    // 0x801A1234: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
L_801A1238:
    // 0x801A1238: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801A123C: lwc1        $f8, 0x120($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X120);
    // 0x801A1240: lwc1        $f4, 0x0($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X0);
    // 0x801A1244: div.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x801A1248: sub.s       $f18, $f4, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f4.fl - ctx->f16.fl;
    // 0x801A124C: swc1        $f18, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f18.u32l;
L_801A1250:
    // 0x801A1250: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801A1254:
    // 0x801A1254: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801A1258: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x801A125C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801A1260: jr          $ra
    // 0x801A1264: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x801A1264: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void Macbeth_801A3C20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A3C20: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x801A3C24: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801A3C28: lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // 0x801A3C2C: addiu       $a3, $a3, -0x1DB0
    ctx->r7 = ADD32(ctx->r7, -0X1DB0);
    // 0x801A3C30: addiu       $a1, $a1, -0x5EC8
    ctx->r5 = ADD32(ctx->r5, -0X5EC8);
    // 0x801A3C34: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801A3C38: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    // 0x801A3C3C: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // 0x801A3C40: lwc1        $f4, 0x50($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X50);
    // 0x801A3C44: lui         $at, 0x4496
    ctx->r1 = S32(0X4496 << 16);
    // 0x801A3C48: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x801A3C4C: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x801A3C50: nop

    // 0x801A3C54: sll         $t7, $a0, 16
    ctx->r15 = S32(ctx->r4 << 16);
    // 0x801A3C58: sra         $a0, $t7, 16
    ctx->r4 = S32(SIGNED(ctx->r15) >> 16);
    // 0x801A3C5C: multu       $a0, $a2
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801A3C60: mflo        $t9
    ctx->r25 = lo;
    // 0x801A3C64: addu        $v0, $a1, $t9
    ctx->r2 = ADD32(ctx->r5, ctx->r25);
    // 0x801A3C68: lh          $v1, 0x10($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X10);
    // 0x801A3C6C: beql        $v1, $zero, L_801A3D74
    if (ctx->r3 == 0) {
        // 0x801A3C70: lwc1        $f12, 0x30($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
            goto L_801A3D74;
    }
    goto skip_0;
    // 0x801A3C70: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    skip_0:
    // 0x801A3C74: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801A3C78: nop

    // 0x801A3C7C: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
L_801A3C80:
    // 0x801A3C80: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x801A3C84: nop

    // 0x801A3C88: bc1fl       L_801A3D50
    if (!c1cs) {
        // 0x801A3C8C: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_801A3D50;
    }
    goto skip_1;
    // 0x801A3C8C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_1:
    // 0x801A3C90: sub.s       $f8, $f0, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x801A3C94: c.lt.s      $f8, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f8.fl < ctx->f14.fl;
    // 0x801A3C98: nop

    // 0x801A3C9C: bc1fl       L_801A3D50
    if (!c1cs) {
        // 0x801A3CA0: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_801A3D50;
    }
    goto skip_2;
    // 0x801A3CA0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_2:
    // 0x801A3CA4: mtc1        $a0, $f10
    ctx->f10.u32l = ctx->r4;
    // 0x801A3CA8: lwc1        $f2, 0x8($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801A3CAC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801A3CB0: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801A3CB4: swc1        $f2, 0x58($a3)
    MEM_W(0X58, ctx->r7) = ctx->f2.u32l;
    // 0x801A3CB8: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x801A3CBC: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801A3CC0: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x801A3CC4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x801A3CC8: swc1        $f4, 0x50($a3)
    MEM_W(0X50, ctx->r7) = ctx->f4.u32l;
    // 0x801A3CCC: lwc1        $f10, -0x49B8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X49B8);
    // 0x801A3CD0: swc1        $f14, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f14.u32l;
    // 0x801A3CD4: swc1        $f2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f2.u32l;
    // 0x801A3CD8: mul.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x801A3CDC: jal         0x80023250
    // 0x801A3CE0: swc1        $f6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f6.u32l;
    __cosf_recomp(rdram, ctx);
        goto after_0;
    // 0x801A3CE0: swc1        $f6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x801A3CE4: lui         $at, 0x4496
    ctx->r1 = S32(0X4496 << 16);
    // 0x801A3CE8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801A3CEC: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x801A3CF0: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x801A3CF4: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x801A3CF8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801A3CFC: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x801A3D00: sub.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x801A3D04: lwc1        $f4, -0x49B4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X49B4);
    // 0x801A3D08: mul.s       $f12, $f6, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x801A3D0C: jal         0x80023090
    // 0x801A3D10: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    __sinf_recomp(rdram, ctx);
        goto after_1;
    // 0x801A3D10: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x801A3D14: lui         $at, 0x4496
    ctx->r1 = S32(0X4496 << 16);
    // 0x801A3D18: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801A3D1C: lwc1        $f18, 0x40($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X40);
    // 0x801A3D20: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x801A3D24: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x801A3D28: lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // 0x801A3D2C: lwc1        $f12, 0x8($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801A3D30: addiu       $a3, $a3, -0x1DB0
    ctx->r7 = ADD32(ctx->r7, -0X1DB0);
    // 0x801A3D34: lwc1        $f14, 0x48($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X48);
    // 0x801A3D38: lh          $v1, 0x10($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X10);
    // 0x801A3D3C: swc1        $f12, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f12.u32l;
    // 0x801A3D40: add.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x801A3D44: b           L_801A3D70
    // 0x801A3D48: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
        goto L_801A3D70;
    // 0x801A3D48: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    // 0x801A3D4C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_801A3D50:
    // 0x801A3D50: sll         $t0, $a0, 16
    ctx->r8 = S32(ctx->r4 << 16);
    // 0x801A3D54: sra         $a0, $t0, 16
    ctx->r4 = S32(SIGNED(ctx->r8) >> 16);
    // 0x801A3D58: multu       $a0, $a2
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801A3D5C: mflo        $t2
    ctx->r10 = lo;
    // 0x801A3D60: addu        $v0, $a1, $t2
    ctx->r2 = ADD32(ctx->r5, ctx->r10);
    // 0x801A3D64: lh          $v1, 0x10($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X10);
    // 0x801A3D68: bnel        $v1, $zero, L_801A3C80
    if (ctx->r3 != 0) {
        // 0x801A3D6C: lwc1        $f0, 0x0($v0)
        ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
            goto L_801A3C80;
    }
    goto skip_3;
    // 0x801A3D6C: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    skip_3:
L_801A3D70:
    // 0x801A3D70: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
L_801A3D74:
    // 0x801A3D74: bne         $v1, $zero, L_801A3D84
    if (ctx->r3 != 0) {
        // 0x801A3D78: lwc1        $f18, 0x40($sp)
        ctx->f18.u32l = MEM_W(ctx->r29, 0X40);
            goto L_801A3D84;
    }
    // 0x801A3D78: lwc1        $f18, 0x40($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X40);
    // 0x801A3D7C: b           L_801A3E60
    // 0x801A3D80: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801A3E60;
    // 0x801A3D80: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801A3D84:
    // 0x801A3D84: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801A3D88: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x801A3D8C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801A3D90: sub.s       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f14.fl;
    // 0x801A3D94: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801A3D98: lwc1        $f16, 0x3C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x801A3D9C: sub.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x801A3DA0: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x801A3DA4: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801A3DA8: c.lt.s      $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f12.fl < ctx->f16.fl;
    // 0x801A3DAC: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x801A3DB0: div.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x801A3DB4: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801A3DB8: addiu       $a0, $a0, -0x1D54
    ctx->r4 = ADD32(ctx->r4, -0X1D54);
    // 0x801A3DBC: lui         $a1, 0xC120
    ctx->r5 = S32(0XC120 << 16);
    // 0x801A3DC0: sub.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f18.fl;
    // 0x801A3DC4: sub.s       $f4, $f12, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f12.fl - ctx->f16.fl;
    // 0x801A3DC8: sub.s       $f0, $f2, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f8.fl;
    // 0x801A3DCC: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x801A3DD0: nop

    // 0x801A3DD4: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x801A3DD8: add.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x801A3DDC: add.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x801A3DE0: swc1        $f8, 0x54($a3)
    MEM_W(0X54, ctx->r7) = ctx->f8.u32l;
    // 0x801A3DE4: bc1f        L_801A3E04
    if (!c1cs) {
        // 0x801A3DE8: swc1        $f10, 0x58($a3)
        MEM_W(0X58, ctx->r7) = ctx->f10.u32l;
            goto L_801A3E04;
    }
    // 0x801A3DE8: swc1        $f10, 0x58($a3)
    MEM_W(0X58, ctx->r7) = ctx->f10.u32l;
    // 0x801A3DEC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801A3DF0: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x801A3DF4: jal         0x8009BC2C
    // 0x801A3DF8: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_2;
    // 0x801A3DF8: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x801A3DFC: b           L_801A3E60
    // 0x801A3E00: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801A3E60;
    // 0x801A3E00: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801A3E04:
    // 0x801A3E04: c.lt.s      $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.fl < ctx->f12.fl;
    // 0x801A3E08: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801A3E0C: addiu       $a0, $a0, -0x1D54
    ctx->r4 = ADD32(ctx->r4, -0X1D54);
    // 0x801A3E10: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x801A3E14: bc1f        L_801A3E48
    if (!c1cs) {
        // 0x801A3E18: lui         $a2, 0x3D4C
        ctx->r6 = S32(0X3D4C << 16);
            goto L_801A3E48;
    }
    // 0x801A3E18: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x801A3E1C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801A3E20: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801A3E24: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x801A3E28: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x801A3E2C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801A3E30: addiu       $a0, $a0, -0x1D54
    ctx->r4 = ADD32(ctx->r4, -0X1D54);
    // 0x801A3E34: lui         $a1, 0x4120
    ctx->r5 = S32(0X4120 << 16);
    // 0x801A3E38: jal         0x8009BC2C
    // 0x801A3E3C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_3;
    // 0x801A3E3C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_3:
    // 0x801A3E40: b           L_801A3E60
    // 0x801A3E44: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801A3E60;
    // 0x801A3E44: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801A3E48:
    // 0x801A3E48: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801A3E4C: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x801A3E50: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801A3E54: jal         0x8009BC2C
    // 0x801A3E58: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_4;
    // 0x801A3E58: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_4:
    // 0x801A3E5C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801A3E60:
    // 0x801A3E60: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801A3E64: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x801A3E68: jr          $ra
    // 0x801A3E6C: nop

    return;
    // 0x801A3E6C: nop

;}
RECOMP_FUNC void Titania_TiRasco_PostLimbDraw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018B144: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018B148: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018B14C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8018B150: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x8018B154: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8018B158: beq         $a0, $at, L_8018B174
    if (ctx->r4 == ctx->r1) {
        // 0x8018B15C: lui         $a1, 0x801B
        ctx->r5 = S32(0X801B << 16);
            goto L_8018B174;
    }
    // 0x8018B15C: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x8018B160: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8018B164: beq         $a0, $at, L_8018B190
    if (ctx->r4 == ctx->r1) {
        // 0x8018B168: lui         $a1, 0x801B
        ctx->r5 = S32(0X801B << 16);
            goto L_8018B190;
    }
    // 0x8018B168: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x8018B16C: b           L_8018B1A8
    // 0x8018B170: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8018B1A8;
    // 0x8018B170: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8018B174:
    // 0x8018B174: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018B178: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018B17C: addiu       $a1, $a1, 0x75C4
    ctx->r5 = ADD32(ctx->r5, 0X75C4);
    // 0x8018B180: jal         0x80006970
    // 0x8018B184: addiu       $a2, $a3, 0x120
    ctx->r6 = ADD32(ctx->r7, 0X120);
    Matrix_MultVec3f(rdram, ctx);
        goto after_0;
    // 0x8018B184: addiu       $a2, $a3, 0x120
    ctx->r6 = ADD32(ctx->r7, 0X120);
    after_0:
    // 0x8018B188: b           L_8018B1A8
    // 0x8018B18C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8018B1A8;
    // 0x8018B18C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8018B190:
    // 0x8018B190: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018B194: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018B198: addiu       $a1, $a1, 0x75C4
    ctx->r5 = ADD32(ctx->r5, 0X75C4);
    // 0x8018B19C: jal         0x80006970
    // 0x8018B1A0: addiu       $a2, $a3, 0x12C
    ctx->r6 = ADD32(ctx->r7, 0X12C);
    Matrix_MultVec3f(rdram, ctx);
        goto after_1;
    // 0x8018B1A0: addiu       $a2, $a3, 0x12C
    ctx->r6 = ADD32(ctx->r7, 0X12C);
    after_1:
    // 0x8018B1A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8018B1A8:
    // 0x8018B1A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018B1AC: jr          $ra
    // 0x8018B1B0: nop

    return;
    // 0x8018B1B0: nop

;}
RECOMP_FUNC void Macbeth_MaMechbeth_FacePlayer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A7CAC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x801A7CB0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801A7CB4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801A7CB8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801A7CBC: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x801A7CC0: lw          $v0, -0x7D80($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D80);
    // 0x801A7CC4: lui         $at, 0x4302
    ctx->r1 = S32(0X4302 << 16);
    // 0x801A7CC8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801A7CCC: lwc1        $f8, 0x138($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X138);
    // 0x801A7CD0: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801A7CD4: lwc1        $f4, 0x74($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X74);
    // 0x801A7CD8: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x801A7CDC: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x801A7CE0: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801A7CE4: sub.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x801A7CE8: mul.s       $f4, $f12, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x801A7CEC: nop

    // 0x801A7CF0: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x801A7CF4: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801A7CF8: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x801A7CFC: jal         0x80005100
    // 0x801A7D00: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    Math_Atan2F(rdram, ctx);
        goto after_0;
    // 0x801A7D00: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x801A7D04: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x801A7D08: lw          $t6, -0x7D80($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7D80);
    // 0x801A7D0C: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x801A7D10: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801A7D14: lwc1        $f8, 0x78($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X78);
    // 0x801A7D18: lwc1        $f14, 0x2C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801A7D1C: jal         0x80005100
    // 0x801A7D20: sub.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f10.fl;
    Math_Atan2F(rdram, ctx);
        goto after_1;
    // 0x801A7D20: sub.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f10.fl;
    after_1:
    // 0x801A7D24: neg.s       $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = -ctx->f0.fl;
    // 0x801A7D28: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    // 0x801A7D2C: jal         0x8009F768
    // 0x801A7D30: swc1        $f16, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f16.u32l;
    Math_RadToDeg(rdram, ctx);
        goto after_2;
    // 0x801A7D30: swc1        $f16, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f16.u32l;
    after_2:
    // 0x801A7D34: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801A7D38: lwc1        $f18, -0x4894($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X4894);
    // 0x801A7D3C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801A7D40: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x801A7D44: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801A7D48: addiu       $a0, $s0, 0x14
    ctx->r4 = ADD32(ctx->r16, 0X14);
    // 0x801A7D4C: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    // 0x801A7D50: jal         0x8009BD38
    // 0x801A7D54: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_3;
    // 0x801A7D54: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_3:
    // 0x801A7D58: jal         0x8009F768
    // 0x801A7D5C: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    Math_RadToDeg(rdram, ctx);
        goto after_4;
    // 0x801A7D5C: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    after_4:
    // 0x801A7D60: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801A7D64: lwc1        $f4, -0x4890($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4890);
    // 0x801A7D68: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801A7D6C: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x801A7D70: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801A7D74: addiu       $a0, $s0, 0x10
    ctx->r4 = ADD32(ctx->r16, 0X10);
    // 0x801A7D78: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    // 0x801A7D7C: jal         0x8009BD38
    // 0x801A7D80: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_5;
    // 0x801A7D80: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_5:
    // 0x801A7D84: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801A7D88: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801A7D8C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x801A7D90: jr          $ra
    // 0x801A7D94: nop

    return;
    // 0x801A7D94: nop

;}
RECOMP_FUNC void Titania_TiDesertCrawler_Init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018BFB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018BFB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018BFB8: lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // 0x8018BFBC: addiu       $v0, $v0, 0x750C
    ctx->r2 = ADD32(ctx->r2, 0X750C);
    // 0x8018BFC0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8018BFC4:
    // 0x8018BFC4: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8018BFC8: bne         $t6, $zero, L_8018BFDC
    if (ctx->r14 != 0) {
        // 0x8018BFCC: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_8018BFDC;
    }
    // 0x8018BFCC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8018BFD0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8018BFD4: b           L_8018BFEC
    // 0x8018BFD8: sw          $v1, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->r3;
        goto L_8018BFEC;
    // 0x8018BFD8: sw          $v1, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->r3;
L_8018BFDC:
    // 0x8018BFDC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8018BFE0: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x8018BFE4: bne         $at, $zero, L_8018BFC4
    if (ctx->r1 != 0) {
        // 0x8018BFE8: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_8018BFC4;
    }
    // 0x8018BFE8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_8018BFEC:
    // 0x8018BFEC: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x8018BFF0: addiu       $t8, $t8, 0x7518
    ctx->r24 = ADD32(ctx->r24, 0X7518);
    // 0x8018BFF4: bne         $v0, $t8, L_8018C00C
    if (ctx->r2 != ctx->r24) {
        // 0x8018BFF8: lui         $t0, 0x801C
        ctx->r8 = S32(0X801C << 16);
            goto L_8018C00C;
    }
    // 0x8018BFF8: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x8018BFFC: jal         0x80060FBC
    // 0x8018C000: addiu       $a1, $a0, 0x100
    ctx->r5 = ADD32(ctx->r4, 0X100);
    Object_Kill(rdram, ctx);
        goto after_0;
    // 0x8018C000: addiu       $a1, $a0, 0x100
    ctx->r5 = ADD32(ctx->r4, 0X100);
    after_0:
    // 0x8018C004: b           L_8018C10C
    // 0x8018C008: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8018C10C;
    // 0x8018C008: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8018C00C:
    // 0x8018C00C: lw          $a2, 0x50($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X50);
    // 0x8018C010: addiu       $t0, $t0, -0x24E0
    ctx->r8 = ADD32(ctx->r8, -0X24E0);
    // 0x8018C014: lui         $t5, 0x801C
    ctx->r13 = S32(0X801C << 16);
    // 0x8018C018: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x8018C01C: addu        $t9, $t9, $a2
    ctx->r25 = ADD32(ctx->r25, ctx->r6);
    // 0x8018C020: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8018C024: subu        $t9, $t9, $a2
    ctx->r25 = SUB32(ctx->r25, ctx->r6);
    // 0x8018C028: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x8018C02C: subu        $t9, $t9, $a2
    ctx->r25 = SUB32(ctx->r25, ctx->r6);
    // 0x8018C030: sll         $t4, $a2, 6
    ctx->r12 = S32(ctx->r6 << 6);
    // 0x8018C034: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8018C038: subu        $t4, $t4, $a2
    ctx->r12 = SUB32(ctx->r12, ctx->r6);
    // 0x8018C03C: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8018C040: addiu       $t2, $zero, 0x50
    ctx->r10 = ADD32(0, 0X50);
    // 0x8018C044: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8018C048: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8018C04C: addiu       $t5, $t5, -0x28C8
    ctx->r13 = ADD32(ctx->r13, -0X28C8);
    // 0x8018C050: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8018C054: sw          $t1, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r9;
    // 0x8018C058: sh          $t2, 0xCE($a0)
    MEM_H(0XCE, ctx->r4) = ctx->r10;
    // 0x8018C05C: sw          $t3, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->r11;
    // 0x8018C060: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    // 0x8018C064: sh          $zero, 0x18($a1)
    MEM_H(0X18, ctx->r5) = 0;
    // 0x8018C068: addiu       $v0, $a1, 0x1C
    ctx->r2 = ADD32(ctx->r5, 0X1C);
    // 0x8018C06C: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x8018C070: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8018C074: swc1        $f0, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->f0.u32l;
    // 0x8018C078: swc1        $f0, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f0.u32l;
    // 0x8018C07C: swc1        $f0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f0.u32l;
    // 0x8018C080: swc1        $f0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f0.u32l;
    // 0x8018C084: swc1        $f0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f0.u32l;
    // 0x8018C088: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
L_8018C08C:
    // 0x8018C08C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8018C090: swc1        $f0, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f0.u32l;
    // 0x8018C094: swc1        $f0, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f0.u32l;
    // 0x8018C098: swc1        $f0, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f0.u32l;
    // 0x8018C09C: swc1        $f0, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f0.u32l;
    // 0x8018C0A0: swc1        $f0, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f0.u32l;
    // 0x8018C0A4: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x8018C0A8: sh          $zero, 0x34($v0)
    MEM_H(0X34, ctx->r2) = 0;
    // 0x8018C0AC: swc1        $f0, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->f0.u32l;
    // 0x8018C0B0: swc1        $f0, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f0.u32l;
    // 0x8018C0B4: swc1        $f0, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f0.u32l;
    // 0x8018C0B8: swc1        $f0, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->f0.u32l;
    // 0x8018C0BC: swc1        $f0, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->f0.u32l;
    // 0x8018C0C0: swc1        $f0, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f0.u32l;
    // 0x8018C0C4: sh          $zero, 0x50($v0)
    MEM_H(0X50, ctx->r2) = 0;
    // 0x8018C0C8: swc1        $f0, 0x68($v0)
    MEM_W(0X68, ctx->r2) = ctx->f0.u32l;
    // 0x8018C0CC: swc1        $f0, 0x64($v0)
    MEM_W(0X64, ctx->r2) = ctx->f0.u32l;
    // 0x8018C0D0: swc1        $f0, 0x60($v0)
    MEM_W(0X60, ctx->r2) = ctx->f0.u32l;
    // 0x8018C0D4: swc1        $f0, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f0.u32l;
    // 0x8018C0D8: swc1        $f0, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f0.u32l;
    // 0x8018C0DC: swc1        $f0, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->f0.u32l;
    // 0x8018C0E0: sh          $zero, 0x6C($v0)
    MEM_H(0X6C, ctx->r2) = 0;
    // 0x8018C0E4: addiu       $v0, $v0, 0x70
    ctx->r2 = ADD32(ctx->r2, 0X70);
    // 0x8018C0E8: swc1        $f0, -0x5C($v0)
    MEM_W(-0X5C, ctx->r2) = ctx->f0.u32l;
    // 0x8018C0EC: swc1        $f0, -0x60($v0)
    MEM_W(-0X60, ctx->r2) = ctx->f0.u32l;
    // 0x8018C0F0: swc1        $f0, -0x64($v0)
    MEM_W(-0X64, ctx->r2) = ctx->f0.u32l;
    // 0x8018C0F4: swc1        $f0, -0x68($v0)
    MEM_W(-0X68, ctx->r2) = ctx->f0.u32l;
    // 0x8018C0F8: swc1        $f0, -0x6C($v0)
    MEM_W(-0X6C, ctx->r2) = ctx->f0.u32l;
    // 0x8018C0FC: swc1        $f0, -0x70($v0)
    MEM_W(-0X70, ctx->r2) = ctx->f0.u32l;
    // 0x8018C100: bne         $v1, $a0, L_8018C08C
    if (ctx->r3 != ctx->r4) {
        // 0x8018C104: sh          $zero, -0x58($v0)
        MEM_H(-0X58, ctx->r2) = 0;
            goto L_8018C08C;
    }
    // 0x8018C104: sh          $zero, -0x58($v0)
    MEM_H(-0X58, ctx->r2) = 0;
    // 0x8018C108: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8018C10C:
    // 0x8018C10C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018C110: jr          $ra
    // 0x8018C114: nop

    return;
    // 0x8018C114: nop

;}
RECOMP_FUNC void Macbeth_MaBoulder_Init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A4660: lwc1        $f6, 0x114($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X114);
    // 0x801A4664: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801A4668: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801A466C: lh          $t6, 0x46($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X46);
    // 0x801A4670: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x801A4674: addiu       $t7, $zero, 0x3C
    ctx->r15 = ADD32(0, 0X3C);
    // 0x801A4678: sh          $t7, 0xCE($a0)
    MEM_H(0XCE, ctx->r4) = ctx->r15;
    // 0x801A467C: swc1        $f4, 0x10C($a0)
    MEM_W(0X10C, ctx->r4) = ctx->f4.u32l;
    // 0x801A4680: bc1f        L_801A4690
    if (!c1cs) {
        // 0x801A4684: sh          $t6, 0x4A($a0)
        MEM_H(0X4A, ctx->r4) = ctx->r14;
            goto L_801A4690;
    }
    // 0x801A4684: sh          $t6, 0x4A($a0)
    MEM_H(0X4A, ctx->r4) = ctx->r14;
    // 0x801A4688: jr          $ra
    // 0x801A468C: sh          $zero, 0x48($a0)
    MEM_H(0X48, ctx->r4) = 0;
    return;
    // 0x801A468C: sh          $zero, 0x48($a0)
    MEM_H(0X48, ctx->r4) = 0;
L_801A4690:
    // 0x801A4690: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801A4694: sh          $t8, 0x48($a0)
    MEM_H(0X48, ctx->r4) = ctx->r24;
    // 0x801A4698: jr          $ra
    // 0x801A469C: nop

    return;
    // 0x801A469C: nop

;}
RECOMP_FUNC void Macbeth_Effect379_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801AE87C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x801AE880: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801AE884: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801AE888: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801AE88C: lwc1        $f0, 0x6C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x801AE890: lwc1        $f4, 0x60($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X60);
    // 0x801AE894: lwc1        $f6, 0x64($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X64);
    // 0x801AE898: lwc1        $f8, 0x68($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X68);
    // 0x801AE89C: mul.s       $f2, $f4, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x801AE8A0: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801AE8A4: lwc1        $f16, 0x70($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X70);
    // 0x801AE8A8: mul.s       $f12, $f6, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x801AE8AC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801AE8B0: lh          $t6, 0x46($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X46);
    // 0x801AE8B4: mul.s       $f14, $f8, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x801AE8B8: lh          $t2, 0x48($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X48);
    // 0x801AE8BC: c.eq.s      $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f6.fl == ctx->f16.fl;
    // 0x801AE8C0: lh          $t9, 0x4A($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X4A);
    // 0x801AE8C4: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801AE8C8: swc1        $f2, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f2.u32l;
    // 0x801AE8CC: trunc.w.s   $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    ctx->f10.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x801AE8D0: swc1        $f12, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f12.u32l;
    // 0x801AE8D4: swc1        $f14, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f14.u32l;
    // 0x801AE8D8: trunc.w.s   $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    ctx->f18.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x801AE8DC: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    // 0x801AE8E0: addiu       $v0, $v0, -0x1C98
    ctx->r2 = ADD32(ctx->r2, -0X1C98);
    // 0x801AE8E4: trunc.w.s   $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    ctx->f4.u32l = TRUNC_W_S(ctx->f14.fl);
    // 0x801AE8E8: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x801AE8EC: addu        $t1, $t6, $t0
    ctx->r9 = ADD32(ctx->r14, ctx->r8);
    // 0x801AE8F0: sh          $t1, 0x46($s0)
    MEM_H(0X46, ctx->r16) = ctx->r9;
    // 0x801AE8F4: mfc1        $t3, $f4
    ctx->r11 = (int32_t)ctx->f4.u32l;
    // 0x801AE8F8: addu        $t8, $t2, $t7
    ctx->r24 = ADD32(ctx->r10, ctx->r15);
    // 0x801AE8FC: sh          $t8, 0x48($s0)
    MEM_H(0X48, ctx->r16) = ctx->r24;
    // 0x801AE900: addu        $t4, $t9, $t3
    ctx->r12 = ADD32(ctx->r25, ctx->r11);
    // 0x801AE904: bc1f        L_801AE924
    if (!c1cs) {
        // 0x801AE908: sh          $t4, 0x4A($s0)
        MEM_H(0X4A, ctx->r16) = ctx->r12;
            goto L_801AE924;
    }
    // 0x801AE908: sh          $t4, 0x4A($s0)
    MEM_H(0X4A, ctx->r16) = ctx->r12;
    // 0x801AE90C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801AE910: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x801AE914: lwc1        $f2, 0x60($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X60);
    // 0x801AE918: lwc1        $f0, 0x64($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X64);
    // 0x801AE91C: b           L_801AE9A0
    // 0x801AE920: lwc1        $f12, 0x68($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X68);
        goto L_801AE9A0;
    // 0x801AE920: lwc1        $f12, 0x68($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X68);
L_801AE924:
    // 0x801AE924: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x801AE928: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801AE92C: nop

    // 0x801AE930: c.eq.s      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.fl == ctx->f16.fl;
    // 0x801AE934: nop

    // 0x801AE938: bc1f        L_801AE95C
    if (!c1cs) {
        // 0x801AE93C: lui         $v0, 0x801C
        ctx->r2 = S32(0X801C << 16);
            goto L_801AE95C;
    }
    // 0x801AE93C: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801AE940: addiu       $v0, $v0, -0x1C98
    ctx->r2 = ADD32(ctx->r2, -0X1C98);
    // 0x801AE944: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801AE948: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x801AE94C: lwc1        $f2, 0x6C($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X6C);
    // 0x801AE950: lwc1        $f0, 0x70($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X70);
    // 0x801AE954: b           L_801AE9A0
    // 0x801AE958: lwc1        $f12, 0x74($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X74);
        goto L_801AE9A0;
    // 0x801AE958: lwc1        $f12, 0x74($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X74);
L_801AE95C:
    // 0x801AE95C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801AE960: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x801AE964: nop

    // 0x801AE968: c.eq.s      $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.fl == ctx->f16.fl;
    // 0x801AE96C: nop

    // 0x801AE970: bc1f        L_801AE98C
    if (!c1cs) {
        // 0x801AE974: lui         $v0, 0x801C
        ctx->r2 = S32(0X801C << 16);
            goto L_801AE98C;
    }
    // 0x801AE974: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801AE978: addiu       $v0, $v0, -0x1C98
    ctx->r2 = ADD32(ctx->r2, -0X1C98);
    // 0x801AE97C: lwc1        $f2, 0x60($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X60);
    // 0x801AE980: lwc1        $f0, 0x64($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X64);
    // 0x801AE984: b           L_801AE9A0
    // 0x801AE988: lwc1        $f12, 0x68($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X68);
        goto L_801AE9A0;
    // 0x801AE988: lwc1        $f12, 0x68($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X68);
L_801AE98C:
    // 0x801AE98C: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801AE990: addiu       $v0, $v0, -0x1C98
    ctx->r2 = ADD32(ctx->r2, -0X1C98);
    // 0x801AE994: lwc1        $f2, 0x6C($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X6C);
    // 0x801AE998: lwc1        $f0, 0x70($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X70);
    // 0x801AE99C: lwc1        $f12, 0x74($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X74);
L_801AE9A0:
    // 0x801AE9A0: lh          $t5, 0x46($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X46);
    // 0x801AE9A4: lh          $t2, 0x48($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X48);
    // 0x801AE9A8: lh          $t7, 0x4A($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X4A);
    // 0x801AE9AC: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x801AE9B0: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x801AE9B4: mfc1        $a1, $f14
    ctx->r5 = (int32_t)ctx->f14.u32l;
    // 0x801AE9B8: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801AE9BC: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x801AE9C0: lui         $a3, 0x3DCC
    ctx->r7 = S32(0X3DCC << 16);
    // 0x801AE9C4: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x801AE9C8: addiu       $a0, $s0, 0x6C
    ctx->r4 = ADD32(ctx->r16, 0X6C);
    // 0x801AE9CC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801AE9D0: add.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f2.fl;
    // 0x801AE9D4: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x801AE9D8: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x801AE9DC: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x801AE9E0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801AE9E4: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x801AE9E8: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
    // 0x801AE9EC: add.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x801AE9F0: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
    // 0x801AE9F4: swc1        $f12, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f12.u32l;
    // 0x801AE9F8: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    // 0x801AE9FC: jal         0x8009BC2C
    // 0x801AEA00: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_0;
    // 0x801AEA00: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x801AEA04: lh          $v0, 0x44($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X44);
    // 0x801AEA08: lwc1        $f2, 0x34($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
    // 0x801AEA0C: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801AEA10: slti        $at, $v0, 0xF0
    ctx->r1 = SIGNED(ctx->r2) < 0XF0 ? 1 : 0;
    // 0x801AEA14: beq         $at, $zero, L_801AEA24
    if (ctx->r1 == 0) {
        // 0x801AEA18: addiu       $t8, $v0, 0xF
        ctx->r24 = ADD32(ctx->r2, 0XF);
            goto L_801AEA24;
    }
    // 0x801AEA18: addiu       $t8, $v0, 0xF
    ctx->r24 = ADD32(ctx->r2, 0XF);
    // 0x801AEA1C: b           L_801AEA40
    // 0x801AEA20: sh          $t8, 0x44($s0)
    MEM_H(0X44, ctx->r16) = ctx->r24;
        goto L_801AEA40;
    // 0x801AEA20: sh          $t8, 0x44($s0)
    MEM_H(0X44, ctx->r16) = ctx->r24;
L_801AEA24:
    // 0x801AEA24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801AEA28: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    // 0x801AEA2C: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    // 0x801AEA30: jal         0x80060FBC
    // 0x801AEA34: swc1        $f12, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f12.u32l;
    Object_Kill(rdram, ctx);
        goto after_1;
    // 0x801AEA34: swc1        $f12, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f12.u32l;
    after_1:
    // 0x801AEA38: lwc1        $f2, 0x34($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
    // 0x801AEA3C: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
L_801AEA40:
    // 0x801AEA40: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801AEA44: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801AEA48: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x801AEA4C: sub.s       $f0, $f10, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f2.fl;
    // 0x801AEA50: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x801AEA54: c.le.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl <= ctx->f14.fl;
    // 0x801AEA58: nop

    // 0x801AEA5C: bc1fl       L_801AEA90
    if (!c1cs) {
        // 0x801AEA60: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_801AEA90;
    }
    goto skip_0;
    // 0x801AEA60: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x801AEA64: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x801AEA68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801AEA6C: sub.s       $f0, $f18, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f18.fl - ctx->f12.fl;
    // 0x801AEA70: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x801AEA74: c.le.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl <= ctx->f14.fl;
    // 0x801AEA78: nop

    // 0x801AEA7C: bc1fl       L_801AEA90
    if (!c1cs) {
        // 0x801AEA80: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_801AEA90;
    }
    goto skip_1;
    // 0x801AEA80: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x801AEA84: jal         0x80060FBC
    // 0x801AEA88: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    Object_Kill(rdram, ctx);
        goto after_2;
    // 0x801AEA88: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    after_2:
    // 0x801AEA8C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801AEA90:
    // 0x801AEA90: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801AEA94: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x801AEA98: jr          $ra
    // 0x801AEA9C: nop

    return;
    // 0x801AEA9C: nop

;}
RECOMP_FUNC void Titania_Cactus_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018F038: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8018F03C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8018F040: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8018F044: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8018F048: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8018F04C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018F050: lwc1        $f10, 0x7D20($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x8018F054: lw          $v0, -0x7D80($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D80);
    // 0x8018F058: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8018F05C: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8018F060: lwc1        $f4, 0x40($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X40);
    // 0x8018F064: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8018F068: lwc1        $f18, 0x48($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X48);
    // 0x8018F06C: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8018F070: jal         0x80005100
    // 0x8018F074: sub.s       $f14, $f18, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f16.fl;
    Math_Atan2F(rdram, ctx);
        goto after_0;
    // 0x8018F074: sub.s       $f14, $f18, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f16.fl;
    after_0:
    // 0x8018F078: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018F07C: lwc1        $f4, -0x52E8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X52E8);
    // 0x8018F080: lb          $t6, 0x46($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X46);
    // 0x8018F084: lui         $at, 0x42C0
    ctx->r1 = S32(0X42C0 << 16);
    // 0x8018F088: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8018F08C: lui         $a3, 0x4080
    ctx->r7 = S32(0X4080 << 16);
    // 0x8018F090: beq         $t6, $zero, L_8018F0C4
    if (ctx->r14 == 0) {
        // 0x8018F094: swc1        $f6, 0x14($s0)
        MEM_W(0X14, ctx->r16) = ctx->f6.u32l;
            goto L_8018F0C4;
    }
    // 0x8018F094: swc1        $f6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f6.u32l;
    // 0x8018F098: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8018F09C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018F0A0: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8018F0A4: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x8018F0A8: jal         0x8007D074
    // 0x8018F0AC: add.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f10.fl;
    Effect_FireSmoke2_Spawn2(rdram, ctx);
        goto after_1;
    // 0x8018F0AC: add.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f10.fl;
    after_1:
    // 0x8018F0B0: lui         $a1, 0x1903
    ctx->r5 = S32(0X1903 << 16);
    // 0x8018F0B4: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    // 0x8018F0B8: ori         $a1, $a1, 0x400F
    ctx->r5 = ctx->r5 | 0X400F;
    // 0x8018F0BC: jal         0x8007A6F0
    // 0x8018F0C0: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    Effect_TimedSfx_Spawn(rdram, ctx);
        goto after_2;
    // 0x8018F0C0: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    after_2:
L_8018F0C4:
    // 0x8018F0C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8018F0C8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8018F0CC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8018F0D0: jr          $ra
    // 0x8018F0D4: nop

    return;
    // 0x8018F0D4: nop

;}
RECOMP_FUNC void Macbeth_EffectClouds_Setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801ACE40: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801ACE44: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801ACE48: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801ACE4C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801ACE50: jal         0x80061474
    // 0x801ACE54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Effect_Initialize(rdram, ctx);
        goto after_0;
    // 0x801ACE54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x801ACE58: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801ACE5C: jal         0x80004EB0
    // 0x801ACE60: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x801ACE60: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
    after_1:
    // 0x801ACE64: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801ACE68: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801ACE6C: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x801ACE70: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801ACE74: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x801ACE78: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x801ACE7C: addiu       $v0, $v0, -0x7D80
    ctx->r2 = ADD32(ctx->r2, -0X7D80);
    // 0x801ACE80: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x801ACE84: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x801ACE88: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x801ACE8C: lwc1        $f16, 0x40($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X40);
    // 0x801ACE90: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801ACE94: lui         $at, 0x44FA
    ctx->r1 = S32(0X44FA << 16);
    // 0x801ACE98: addiu       $t0, $zero, 0x160
    ctx->r8 = ADD32(0, 0X160);
    // 0x801ACE9C: addiu       $t1, $zero, 0x50
    ctx->r9 = ADD32(0, 0X50);
    // 0x801ACEA0: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801ACEA4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801ACEA8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801ACEAC: addiu       $t2, $zero, 0x90
    ctx->r10 = ADD32(0, 0X90);
    // 0x801ACEB0: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
    // 0x801ACEB4: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x801ACEB8: lwc1        $f4, 0x44($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X44);
    // 0x801ACEBC: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801ACEC0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801ACEC4: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x801ACEC8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801ACECC: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    // 0x801ACED0: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x801ACED4: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x801ACED8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801ACEDC: lwc1        $f10, 0x138($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X138);
    // 0x801ACEE0: sh          $t0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r8;
    // 0x801ACEE4: sh          $t1, 0x50($s0)
    MEM_H(0X50, ctx->r16) = ctx->r9;
    // 0x801ACEE8: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x801ACEEC: sh          $t2, 0x46($s0)
    MEM_H(0X46, ctx->r16) = ctx->r10;
    // 0x801ACEF0: swc1        $f4, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f4.u32l;
    // 0x801ACEF4: swc1        $f6, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f6.u32l;
    // 0x801ACEF8: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
    // 0x801ACEFC: jal         0x80004EB0
    // 0x801ACF00: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_2;
    // 0x801ACF00: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
    after_2:
    // 0x801ACF04: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x801ACF08: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801ACF0C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801ACF10: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801ACF14: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x801ACF18: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x801ACF1C: jal         0x80004EB0
    // 0x801ACF20: swc1        $f4, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f4.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_3;
    // 0x801ACF20: swc1        $f4, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f4.u32l;
    after_3:
    // 0x801ACF24: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801ACF28: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801ACF2C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x801ACF30: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x801ACF34: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x801ACF38: nop

    // 0x801ACF3C: bc1f        L_801ACF50
    if (!c1cs) {
        // 0x801ACF40: nop
    
            goto L_801ACF50;
    }
    // 0x801ACF40: nop

    // 0x801ACF44: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801ACF48: nop

    // 0x801ACF4C: swc1        $f8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f8.u32l;
L_801ACF50:
    // 0x801ACF50: jal         0x800612B8
    // 0x801ACF54: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    Object_SetInfo(rdram, ctx);
        goto after_4;
    // 0x801ACF54: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    after_4:
    // 0x801ACF58: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801ACF5C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801ACF60: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801ACF64: jr          $ra
    // 0x801ACF68: nop

    return;
    // 0x801ACF68: nop

;}
RECOMP_FUNC void Macbeth_MaBoulder_HandleDamage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A49B8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801A49BC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801A49C0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801A49C4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801A49C8: lb          $t6, 0xD0($s0)
    ctx->r14 = MEM_B(ctx->r16, 0XD0);
    // 0x801A49CC: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x801A49D0: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x801A49D4: beq         $t6, $zero, L_801A4A50
    if (ctx->r14 == 0) {
        // 0x801A49D8: lui         $a0, 0x2902
        ctx->r4 = S32(0X2902 << 16);
            goto L_801A4A50;
    }
    // 0x801A49D8: lui         $a0, 0x2902
    ctx->r4 = S32(0X2902 << 16);
    // 0x801A49DC: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x801A49E0: addiu       $t7, $t7, 0x5D3C
    ctx->r15 = ADD32(ctx->r15, 0X5D3C);
    // 0x801A49E4: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801A49E8: ori         $a0, $a0, 0x4003
    ctx->r4 = ctx->r4 | 0X4003;
    // 0x801A49EC: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x801A49F0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801A49F4: jal         0x80019218
    // 0x801A49F8: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    Audio_PlaySfx(rdram, ctx);
        goto after_0;
    // 0x801A49F8: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_0:
    // 0x801A49FC: lh          $t9, 0xCE($s0)
    ctx->r25 = MEM_H(ctx->r16, 0XCE);
    // 0x801A4A00: lhu         $t0, 0xD6($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0XD6);
    // 0x801A4A04: addiu       $t8, $zero, 0xF
    ctx->r24 = ADD32(0, 0XF);
    // 0x801A4A08: sh          $t8, 0xC6($s0)
    MEM_H(0XC6, ctx->r16) = ctx->r24;
    // 0x801A4A0C: subu        $t1, $t9, $t0
    ctx->r9 = SUB32(ctx->r25, ctx->r8);
    // 0x801A4A10: sh          $t1, 0xCE($s0)
    MEM_H(0XCE, ctx->r16) = ctx->r9;
    // 0x801A4A14: lh          $t2, 0xCE($s0)
    ctx->r10 = MEM_H(ctx->r16, 0XCE);
    // 0x801A4A18: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x801A4A1C: lui         $a1, 0x2903
    ctx->r5 = S32(0X2903 << 16);
    // 0x801A4A20: bgtzl       $t2, L_801A4A50
    if (SIGNED(ctx->r10) > 0) {
        // 0x801A4A24: sb          $zero, 0xD0($s0)
        MEM_B(0XD0, ctx->r16) = 0;
            goto L_801A4A50;
    }
    goto skip_0;
    // 0x801A4A24: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
    skip_0:
    // 0x801A4A28: jal         0x8007A6F0
    // 0x801A4A2C: ori         $a1, $a1, 0xB009
    ctx->r5 = ctx->r5 | 0XB009;
    Effect_TimedSfx_Spawn(rdram, ctx);
        goto after_1;
    // 0x801A4A2C: ori         $a1, $a1, 0xB009
    ctx->r5 = ctx->r5 | 0XB009;
    after_1:
    // 0x801A4A30: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x801A4A34: addiu       $v0, $v0, 0x1A98
    ctx->r2 = ADD32(ctx->r2, 0X1A98);
    // 0x801A4A38: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x801A4A3C: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x801A4A40: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x801A4A44: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x801A4A48: sh          $t5, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r13;
    // 0x801A4A4C: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
L_801A4A50:
    // 0x801A4A50: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801A4A54: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801A4A58: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801A4A5C: jr          $ra
    // 0x801A4A60: nop

    return;
    // 0x801A4A60: nop

;}
RECOMP_FUNC void Macbeth_InitLevel(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80199920: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80199924: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80199928: lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // 0x8019992C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80199930: addiu       $a3, $a3, -0x1DB0
    ctx->r7 = ADD32(ctx->r7, -0X1DB0);
    // 0x80199934: addiu       $v0, $v0, -0x1D10
    ctx->r2 = ADD32(ctx->r2, -0X1D10);
    // 0x80199938: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8019993C: addiu       $v1, $zero, 0x3E7
    ctx->r3 = ADD32(0, 0X3E7);
    // 0x80199940: lui         $at, 0xC170
    ctx->r1 = S32(0XC170 << 16);
    // 0x80199944: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80199948: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019994C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80199950: swc1        $f4, -0x5E24($at)
    MEM_W(-0X5E24, ctx->r1) = ctx->f4.u32l;
    // 0x80199954: sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
    // 0x80199958: sh          $v1, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r3;
    // 0x8019995C: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
    // 0x80199960: sh          $v1, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r3;
    // 0x80199964: sh          $t6, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r14;
    // 0x80199968: sh          $zero, 0xA($v0)
    MEM_H(0XA, ctx->r2) = 0;
    // 0x8019996C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80199970: sb          $zero, -0x5E1C($at)
    MEM_B(-0X5E1C, ctx->r1) = 0;
    // 0x80199974: swc1        $f0, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->f0.u32l;
    // 0x80199978: swc1        $f0, 0x40($a3)
    MEM_W(0X40, ctx->r7) = ctx->f0.u32l;
    // 0x8019997C: swc1        $f0, 0x50($a3)
    MEM_W(0X50, ctx->r7) = ctx->f0.u32l;
    // 0x80199980: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80199984: addiu       $t7, $zero, 0x62
    ctx->r15 = ADD32(0, 0X62);
    // 0x80199988: sb          $t7, -0x5E18($at)
    MEM_B(-0X5E18, ctx->r1) = ctx->r15;
    // 0x8019998C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80199990: lwc1        $f6, -0x4D50($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X4D50);
    // 0x80199994: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80199998: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8019999C: swc1        $f6, -0x5E20($at)
    MEM_W(-0X5E20, ctx->r1) = ctx->f6.u32l;
    // 0x801999A0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801999A4: sh          $v1, -0x1CF0($at)
    MEM_H(-0X1CF0, ctx->r1) = ctx->r3;
    // 0x801999A8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801999AC: sb          $zero, -0x1CEE($at)
    MEM_B(-0X1CEE, ctx->r1) = 0;
    // 0x801999B0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801999B4: sb          $t8, -0x1CED($at)
    MEM_B(-0X1CED, ctx->r1) = ctx->r24;
    // 0x801999B8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801999BC: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801999C0: sb          $zero, -0x5E28($at)
    MEM_B(-0X5E28, ctx->r1) = 0;
    // 0x801999C4: addiu       $a0, $a0, -0x1CF8
    ctx->r4 = ADD32(ctx->r4, -0X1CF8);
    // 0x801999C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801999CC: jal         0x80099980
    // 0x801999D0: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    Graphics_ClearPrintBuffer(rdram, ctx);
        goto after_0;
    // 0x801999D0: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_0:
    // 0x801999D4: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801999D8: addiu       $v1, $v1, -0x1CE0
    ctx->r3 = ADD32(ctx->r3, -0X1CE0);
    // 0x801999DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801999E0:
    // 0x801999E0: sll         $t9, $v0, 1
    ctx->r25 = S32(ctx->r2 << 1);
    // 0x801999E4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x801999E8: sll         $t1, $v0, 16
    ctx->r9 = S32(ctx->r2 << 16);
    // 0x801999EC: sra         $v0, $t1, 16
    ctx->r2 = S32(SIGNED(ctx->r9) >> 16);
    // 0x801999F0: slti        $at, $v0, 0x23
    ctx->r1 = SIGNED(ctx->r2) < 0X23 ? 1 : 0;
    // 0x801999F4: addu        $t0, $v1, $t9
    ctx->r8 = ADD32(ctx->r3, ctx->r25);
    // 0x801999F8: bne         $at, $zero, L_801999E0
    if (ctx->r1 != 0) {
        // 0x801999FC: sh          $zero, 0x0($t0)
        MEM_H(0X0, ctx->r8) = 0;
            goto L_801999E0;
    }
    // 0x801999FC: sh          $zero, 0x0($t0)
    MEM_H(0X0, ctx->r8) = 0;
    // 0x80199A00: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80199A04: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80199A08: addiu       $v1, $v1, -0x1C98
    ctx->r3 = ADD32(ctx->r3, -0X1C98);
    // 0x80199A0C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80199A10:
    // 0x80199A10: sll         $t3, $v0, 2
    ctx->r11 = S32(ctx->r2 << 2);
    // 0x80199A14: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80199A18: sll         $t5, $v0, 16
    ctx->r13 = S32(ctx->r2 << 16);
    // 0x80199A1C: sra         $v0, $t5, 16
    ctx->r2 = S32(SIGNED(ctx->r13) >> 16);
    // 0x80199A20: slti        $at, $v0, 0x32
    ctx->r1 = SIGNED(ctx->r2) < 0X32 ? 1 : 0;
    // 0x80199A24: addu        $t4, $v1, $t3
    ctx->r12 = ADD32(ctx->r3, ctx->r11);
    // 0x80199A28: bne         $at, $zero, L_80199A10
    if (ctx->r1 != 0) {
        // 0x80199A2C: swc1        $f0, 0x0($t4)
        MEM_W(0X0, ctx->r12) = ctx->f0.u32l;
            goto L_80199A10;
    }
    // 0x80199A2C: swc1        $f0, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f0.u32l;
    // 0x80199A30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80199A34: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80199A38: jr          $ra
    // 0x80199A3C: nop

    return;
    // 0x80199A3C: nop

;}
RECOMP_FUNC void Macbeth_MaMissileCar_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019EA60: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8019EA64: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8019EA68: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8019EA6C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8019EA70: lh          $v0, 0xB8($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XB8);
    // 0x8019EA74: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8019EA78: beq         $v0, $zero, L_8019EAA4
    if (ctx->r2 == 0) {
        // 0x8019EA7C: nop
    
            goto L_8019EAA4;
    }
    // 0x8019EA7C: nop

    // 0x8019EA80: beq         $v0, $at, L_8019EAF0
    if (ctx->r2 == ctx->r1) {
        // 0x8019EA84: lui         $v1, 0x801C
        ctx->r3 = S32(0X801C << 16);
            goto L_8019EAF0;
    }
    // 0x8019EA84: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8019EA88: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8019EA8C: beq         $v0, $at, L_8019EB28
    if (ctx->r2 == ctx->r1) {
        // 0x8019EA90: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8019EB28;
    }
    // 0x8019EA90: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8019EA94: beq         $v0, $at, L_8019EBA0
    if (ctx->r2 == ctx->r1) {
        // 0x8019EA98: nop
    
            goto L_8019EBA0;
    }
    // 0x8019EA98: nop

    // 0x8019EA9C: b           L_8019EBE8
    // 0x8019EAA0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8019EBE8;
    // 0x8019EAA0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8019EAA4:
    // 0x8019EAA4: jal         0x8019A198
    // 0x8019EAA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Macbeth_TrainCarSpeed_Update(rdram, ctx);
        goto after_0;
    // 0x8019EAA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8019EAAC: jal         0x801A015C
    // 0x8019EAB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Macbeth_801A015C(rdram, ctx);
        goto after_1;
    // 0x8019EAB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8019EAB4: lwc1        $f4, 0x178($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X178);
    // 0x8019EAB8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8019EABC: addiu       $t6, $s0, 0x84
    ctx->r14 = ADD32(ctx->r16, 0X84);
    // 0x8019EAC0: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x8019EAC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8019EAC8: addiu       $a1, $s0, 0x78
    ctx->r5 = ADD32(ctx->r16, 0X78);
    // 0x8019EACC: addiu       $a2, $s0, 0x7C
    ctx->r6 = ADD32(ctx->r16, 0X7C);
    // 0x8019EAD0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8019EAD4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8019EAD8: jal         0x8019E624
    // 0x8019EADC: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    Macbeth_8019E624(rdram, ctx);
        goto after_2;
    // 0x8019EADC: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x8019EAE0: jal         0x8019A830
    // 0x8019EAE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Macbeth_8019A830(rdram, ctx);
        goto after_3;
    // 0x8019EAE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8019EAE8: b           L_8019EBE8
    // 0x8019EAEC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8019EBE8;
    // 0x8019EAEC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8019EAF0:
    // 0x8019EAF0: addiu       $v1, $v1, -0x1D10
    ctx->r3 = ADD32(ctx->r3, -0X1D10);
    // 0x8019EAF4: lh          $t7, 0x6($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X6);
    // 0x8019EAF8: lw          $v0, 0x64($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X64);
    // 0x8019EAFC: slt         $at, $v0, $t7
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8019EB00: beq         $at, $zero, L_8019EB0C
    if (ctx->r1 == 0) {
        // 0x8019EB04: nop
    
            goto L_8019EB0C;
    }
    // 0x8019EB04: nop

    // 0x8019EB08: sh          $v0, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r2;
L_8019EB0C:
    // 0x8019EB0C: jal         0x801A015C
    // 0x8019EB10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Macbeth_801A015C(rdram, ctx);
        goto after_4;
    // 0x8019EB10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8019EB14: jal         0x8019A830
    // 0x8019EB18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Macbeth_8019A830(rdram, ctx);
        goto after_5;
    // 0x8019EB18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8019EB1C: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8019EB20: b           L_8019EBE4
    // 0x8019EB24: sh          $t8, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r24;
        goto L_8019EBE4;
    // 0x8019EB24: sh          $t8, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r24;
L_8019EB28:
    // 0x8019EB28: jal         0x8019BBEC
    // 0x8019EB2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Macbeth_8019BBEC(rdram, ctx);
        goto after_6;
    // 0x8019EB2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8019EB30: lhu         $t9, 0xBC($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0XBC);
    // 0x8019EB34: addiu       $a0, $s0, 0xF0
    ctx->r4 = ADD32(ctx->r16, 0XF0);
    // 0x8019EB38: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8019EB3C: bne         $t9, $zero, L_8019EB4C
    if (ctx->r25 != 0) {
        // 0x8019EB40: lui         $a2, 0x3CA3
        ctx->r6 = S32(0X3CA3 << 16);
            goto L_8019EB4C;
    }
    // 0x8019EB40: lui         $a2, 0x3CA3
    ctx->r6 = S32(0X3CA3 << 16);
    // 0x8019EB44: addiu       $t0, $zero, 0x3C
    ctx->r8 = ADD32(0, 0X3C);
    // 0x8019EB48: sh          $t0, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r8;
L_8019EB4C:
    // 0x8019EB4C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019EB50: lwc1        $f8, -0x4C08($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4C08);
    // 0x8019EB54: ori         $a2, $a2, 0xD70A
    ctx->r6 = ctx->r6 | 0XD70A;
    // 0x8019EB58: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x8019EB5C: jal         0x8009BC2C
    // 0x8019EB60: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_7;
    // 0x8019EB60: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_7:
    // 0x8019EB64: jal         0x801A015C
    // 0x8019EB68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Macbeth_801A015C(rdram, ctx);
        goto after_8;
    // 0x8019EB68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x8019EB6C: jal         0x8019A87C
    // 0x8019EB70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Macbeth_8019A87C(rdram, ctx);
        goto after_9;
    // 0x8019EB70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x8019EB74: lb          $t1, 0xD0($s0)
    ctx->r9 = MEM_B(ctx->r16, 0XD0);
    // 0x8019EB78: addiu       $t2, $zero, 0x14
    ctx->r10 = ADD32(0, 0X14);
    // 0x8019EB7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8019EB80: beql        $t1, $zero, L_8019EBE8
    if (ctx->r9 == 0) {
        // 0x8019EB84: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8019EBE8;
    }
    goto skip_0;
    // 0x8019EB84: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x8019EB88: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
    // 0x8019EB8C: jal         0x8019BE50
    // 0x8019EB90: sh          $t2, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r10;
    Macbeth_8019BE50(rdram, ctx);
        goto after_10;
    // 0x8019EB90: sh          $t2, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r10;
    after_10:
    // 0x8019EB94: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x8019EB98: b           L_8019EBE4
    // 0x8019EB9C: sh          $t3, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r11;
        goto L_8019EBE4;
    // 0x8019EB9C: sh          $t3, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r11;
L_8019EBA0:
    // 0x8019EBA0: jal         0x801A015C
    // 0x8019EBA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Macbeth_801A015C(rdram, ctx);
        goto after_11;
    // 0x8019EBA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x8019EBA8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019EBAC: lwc1        $f10, -0x4C04($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X4C04);
    // 0x8019EBB0: lui         $a2, 0x3CA3
    ctx->r6 = S32(0X3CA3 << 16);
    // 0x8019EBB4: ori         $a2, $a2, 0xD70A
    ctx->r6 = ctx->r6 | 0XD70A;
    // 0x8019EBB8: addiu       $a0, $s0, 0x110
    ctx->r4 = ADD32(ctx->r16, 0X110);
    // 0x8019EBBC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8019EBC0: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x8019EBC4: jal         0x8009BC2C
    // 0x8019EBC8: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_12;
    // 0x8019EBC8: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_12:
    // 0x8019EBCC: lhu         $t4, 0xBC($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0XBC);
    // 0x8019EBD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8019EBD4: bgtzl       $t4, L_8019EBE8
    if (SIGNED(ctx->r12) > 0) {
        // 0x8019EBD8: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8019EBE8;
    }
    goto skip_1;
    // 0x8019EBD8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_1:
    // 0x8019EBDC: jal         0x80060FBC
    // 0x8019EBE0: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    Object_Kill(rdram, ctx);
        goto after_13;
    // 0x8019EBE0: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    after_13:
L_8019EBE4:
    // 0x8019EBE4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8019EBE8:
    // 0x8019EBE8: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8019EBEC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8019EBF0: jr          $ra
    // 0x8019EBF4: nop

    return;
    // 0x8019EBF4: nop

;}
