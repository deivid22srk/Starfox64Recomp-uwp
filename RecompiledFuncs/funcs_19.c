#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void Effect_FireSmoke2_Spawn3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007D10C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007D110: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007D114: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8007D118: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8007D11C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8007D120: jal         0x8007CF9C
    // 0x8007D124: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    Effect_FireSmoke2_Spawn(rdram, ctx);
        goto after_0;
    // 0x8007D124: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    after_0:
    // 0x8007D128: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007D12C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007D130: jr          $ra
    // 0x8007D134: nop

    return;
    // 0x8007D134: nop

;}
RECOMP_FUNC void Effect_Effect367_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80078604: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80078608: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007860C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80078610: lhu         $t6, 0x50($a2)
    ctx->r14 = MEM_HU(ctx->r6, 0X50);
    // 0x80078614: bnel        $t6, $zero, L_80078680
    if (ctx->r14 != 0) {
        // 0x80078618: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80078680;
    }
    goto skip_0;
    // 0x80078618: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8007861C: lwc1        $f12, 0x70($a2)
    ctx->f12.u32l = MEM_W(ctx->r6, 0X70);
    // 0x80078620: jal         0x8005980C
    // 0x80078624: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    Graphics_SetScaleMtx(rdram, ctx);
        goto after_0;
    // 0x80078624: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80078628: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8007862C: addiu       $a1, $a1, 0x7E64
    ctx->r5 = ADD32(ctx->r5, 0X7E64);
    // 0x80078630: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80078634: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80078638: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x8007863C: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x80078640: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80078644: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x80078648: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8007864C: lh          $t9, 0x44($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X44);
    // 0x80078650: lui         $t3, 0x600
    ctx->r11 = S32(0X600 << 16);
    // 0x80078654: andi        $t0, $t9, 0xFF
    ctx->r8 = ctx->r25 & 0XFF;
    // 0x80078658: or          $t1, $t0, $at
    ctx->r9 = ctx->r8 | ctx->r1;
    // 0x8007865C: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x80078660: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80078664: lui         $t4, 0x201
    ctx->r12 = S32(0X201 << 16);
    // 0x80078668: addiu       $t4, $t4, 0x12C0
    ctx->r12 = ADD32(ctx->r12, 0X12C0);
    // 0x8007866C: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x80078670: sw          $t2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r10;
    // 0x80078674: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80078678: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8007867C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80078680:
    // 0x80078680: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80078684: jr          $ra
    // 0x80078688: nop

    return;
    // 0x80078688: nop

;}
RECOMP_FUNC void ItemRingCheck_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068C48: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80068C4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80068C50: lb          $t6, 0x4C($a0)
    ctx->r14 = MEM_B(ctx->r4, 0X4C);
    // 0x80068C54: beql        $t6, $zero, L_80068C7C
    if (ctx->r14 == 0) {
        // 0x80068C58: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80068C7C;
    }
    goto skip_0;
    // 0x80068C58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80068C5C: jal         0x80060FBC
    // 0x80068C60: addiu       $a1, $a0, 0x5C
    ctx->r5 = ADD32(ctx->r4, 0X5C);
    Object_Kill(rdram, ctx);
        goto after_0;
    // 0x80068C60: addiu       $a1, $a0, 0x5C
    ctx->r5 = ADD32(ctx->r4, 0X5C);
    after_0:
    // 0x80068C64: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80068C68: addiu       $v0, $v0, 0x7E80
    ctx->r2 = ADD32(ctx->r2, 0X7E80);
    // 0x80068C6C: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x80068C70: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80068C74: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80068C78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80068C7C:
    // 0x80068C7C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80068C80: jr          $ra
    // 0x80068C84: nop

    return;
    // 0x80068C84: nop

;}
RECOMP_FUNC void Effect_ElectricArc_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800780F8: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x800780FC: sw          $s4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r20;
    // 0x80078100: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80078104: sw          $ra, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r31;
    // 0x80078108: sw          $fp, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r30;
    // 0x8007810C: sw          $s7, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r23;
    // 0x80078110: sw          $s6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r22;
    // 0x80078114: sw          $s5, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r21;
    // 0x80078118: sw          $s3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r19;
    // 0x8007811C: sw          $s2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r18;
    // 0x80078120: sw          $s1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r17;
    // 0x80078124: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x80078128: sdc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X48, ctx->r29);
    // 0x8007812C: sdc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X40, ctx->r29);
    // 0x80078130: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x80078134: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x80078138: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x8007813C: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80078140: lh          $t6, 0x4A($s4)
    ctx->r14 = MEM_H(ctx->r20, 0X4A);
    // 0x80078144: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x80078148: slti        $at, $t6, 0xB
    ctx->r1 = SIGNED(ctx->r14) < 0XB ? 1 : 0;
    // 0x8007814C: bne         $at, $zero, L_800781C8
    if (ctx->r1 != 0) {
        // 0x80078150: nop
    
            goto L_800781C8;
    }
    // 0x80078150: nop

    // 0x80078154: lw          $t7, 0x40($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X40);
    // 0x80078158: lw          $t8, 0x7DB0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7DB0);
    // 0x8007815C: lui         $s5, 0x8013
    ctx->r21 = S32(0X8013 << 16);
    // 0x80078160: addiu       $s5, $s5, 0x7E64
    ctx->r21 = ADD32(ctx->r21, 0X7E64);
    // 0x80078164: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80078168: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x8007816C: bne         $t0, $zero, L_800781A4
    if (ctx->r8 != 0) {
        // 0x80078170: lui         $t5, 0xFA00
        ctx->r13 = S32(0XFA00 << 16);
            goto L_800781A4;
    }
    // 0x80078170: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x80078174: lui         $s5, 0x8013
    ctx->r21 = S32(0X8013 << 16);
    // 0x80078178: addiu       $s5, $s5, 0x7E64
    ctx->r21 = ADD32(ctx->r21, 0X7E64);
    // 0x8007817C: lw          $v1, 0x0($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X0);
    // 0x80078180: lui         $t3, 0xFF80
    ctx->r11 = S32(0XFF80 << 16);
    // 0x80078184: ori         $t3, $t3, 0x8020
    ctx->r11 = ctx->r11 | 0X8020;
    // 0x80078188: addiu       $t1, $v1, 0x8
    ctx->r9 = ADD32(ctx->r3, 0X8);
    // 0x8007818C: sw          $t1, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r9;
    // 0x80078190: lui         $t2, 0xFA00
    ctx->r10 = S32(0XFA00 << 16);
    // 0x80078194: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x80078198: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x8007819C: b           L_80078234
    // 0x800781A0: nop

        goto L_80078234;
    // 0x800781A0: nop

L_800781A4:
    // 0x800781A4: lw          $v1, 0x0($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X0);
    // 0x800781A8: lui         $t6, 0xFF80
    ctx->r14 = S32(0XFF80 << 16);
    // 0x800781AC: ori         $t6, $t6, 0x8080
    ctx->r14 = ctx->r14 | 0X8080;
    // 0x800781B0: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x800781B4: sw          $t4, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r12;
    // 0x800781B8: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x800781BC: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x800781C0: b           L_80078234
    // 0x800781C4: nop

        goto L_80078234;
    // 0x800781C4: nop

L_800781C8:
    // 0x800781C8: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x800781CC: lw          $t8, 0x7DB0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7DB0);
    // 0x800781D0: lw          $t7, 0x40($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X40);
    // 0x800781D4: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800781D8: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x800781DC: bne         $t0, $zero, L_8007820C
    if (ctx->r8 != 0) {
        // 0x800781E0: lui         $s5, 0x8013
        ctx->r21 = S32(0X8013 << 16);
            goto L_8007820C;
    }
    // 0x800781E0: lui         $s5, 0x8013
    ctx->r21 = S32(0X8013 << 16);
    // 0x800781E4: addiu       $s5, $s5, 0x7E64
    ctx->r21 = ADD32(ctx->r21, 0X7E64);
    // 0x800781E8: lw          $v1, 0x0($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X0);
    // 0x800781EC: lui         $t2, 0xFA00
    ctx->r10 = S32(0XFA00 << 16);
    // 0x800781F0: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x800781F4: addiu       $t1, $v1, 0x8
    ctx->r9 = ADD32(ctx->r3, 0X8);
    // 0x800781F8: sw          $t1, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r9;
    // 0x800781FC: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x80078200: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x80078204: b           L_80078234
    // 0x80078208: nop

        goto L_80078234;
    // 0x80078208: nop

L_8007820C:
    // 0x8007820C: lui         $s5, 0x8013
    ctx->r21 = S32(0X8013 << 16);
    // 0x80078210: addiu       $s5, $s5, 0x7E64
    ctx->r21 = ADD32(ctx->r21, 0X7E64);
    // 0x80078214: lw          $v1, 0x0($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X0);
    // 0x80078218: lui         $t6, 0x6060
    ctx->r14 = S32(0X6060 << 16);
    // 0x8007821C: ori         $t6, $t6, 0xFFFF
    ctx->r14 = ctx->r14 | 0XFFFF;
    // 0x80078220: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x80078224: sw          $t4, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r12;
    // 0x80078228: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x8007822C: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x80078230: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
L_80078234:
    // 0x80078234: jal         0x8005980C
    // 0x80078238: lwc1        $f12, 0x70($s4)
    ctx->f12.u32l = MEM_W(ctx->r20, 0X70);
    Graphics_SetScaleMtx(rdram, ctx);
        goto after_0;
    // 0x80078238: lwc1        $f12, 0x70($s4)
    ctx->f12.u32l = MEM_W(ctx->r20, 0X70);
    after_0:
    // 0x8007823C: lui         $at, 0xC2F0
    ctx->r1 = S32(0XC2F0 << 16);
    // 0x80078240: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x80078244: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80078248: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x8007824C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80078250: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80078254: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80078258: lwc1        $f24, 0x730C($at)
    ctx->f24.u32l = MEM_W(ctx->r1, 0X730C);
    // 0x8007825C: lui         $at, 0xC270
    ctx->r1 = S32(0XC270 << 16);
    // 0x80078260: lui         $s7, 0x800D
    ctx->r23 = S32(0X800D << 16);
    // 0x80078264: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x80078268: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8007826C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80078270: addiu       $s0, $s0, -0x4C40
    ctx->r16 = ADD32(ctx->r16, -0X4C40);
    // 0x80078274: addiu       $s7, $s7, 0x1534
    ctx->r23 = ADD32(ctx->r23, 0X1534);
    // 0x80078278: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8007827C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80078280: addiu       $fp, $zero, 0xA
    ctx->r30 = ADD32(0, 0XA);
    // 0x80078284: lui         $s6, 0x600
    ctx->r22 = S32(0X600 << 16);
L_80078288:
    // 0x80078288: lh          $t7, 0x48($s4)
    ctx->r15 = MEM_H(ctx->r20, 0X48);
    // 0x8007828C: slt         $at, $s1, $t7
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80078290: bnel        $at, $zero, L_80078318
    if (ctx->r1 != 0) {
        // 0x80078294: mfc1        $a1, $f20
        ctx->r5 = (int32_t)ctx->f20.u32l;
            goto L_80078318;
    }
    goto skip_0;
    // 0x80078294: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    skip_0:
    // 0x80078298: lh          $t8, 0x46($s4)
    ctx->r24 = MEM_H(ctx->r20, 0X46);
    // 0x8007829C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800782A0: lui         $s2, 0x103
    ctx->r18 = S32(0X103 << 16);
    // 0x800782A4: slt         $at, $s1, $t8
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800782A8: beql        $at, $zero, L_80078318
    if (ctx->r1 == 0) {
        // 0x800782AC: mfc1        $a1, $f20
        ctx->r5 = (int32_t)ctx->f20.u32l;
            goto L_80078318;
    }
    goto skip_1;
    // 0x800782AC: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    skip_1:
    // 0x800782B0: jal         0x80005708
    // 0x800782B4: addiu       $s2, $s2, -0xA20
    ctx->r18 = ADD32(ctx->r18, -0XA20);
    Matrix_Push(rdram, ctx);
        goto after_1;
    // 0x800782B4: addiu       $s2, $s2, -0xA20
    ctx->r18 = ADD32(ctx->r18, -0XA20);
    after_1:
    // 0x800782B8: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x800782BC: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x800782C0: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x800782C4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800782C8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800782CC: jal         0x80005B00
    // 0x800782D0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_2;
    // 0x800782D0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_2:
    // 0x800782D4: mfc1        $a1, $f24
    ctx->r5 = (int32_t)ctx->f24.u32l;
    // 0x800782D8: mfc1        $a2, $f26
    ctx->r6 = (int32_t)ctx->f26.u32l;
    // 0x800782DC: mfc1        $a3, $f28
    ctx->r7 = (int32_t)ctx->f28.u32l;
    // 0x800782E0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800782E4: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x800782E8: jal         0x80005C34
    // 0x800782EC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_3;
    // 0x800782EC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_3:
    // 0x800782F0: jal         0x80006EB8
    // 0x800782F4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_4;
    // 0x800782F4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_4:
    // 0x800782F8: lw          $v1, 0x0($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X0);
    // 0x800782FC: addiu       $t1, $v1, 0x8
    ctx->r9 = ADD32(ctx->r3, 0X8);
    // 0x80078300: sw          $t1, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r9;
    // 0x80078304: sw          $s2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r18;
    // 0x80078308: sw          $s6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r22;
    // 0x8007830C: jal         0x80005740
    // 0x80078310: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_5;
    // 0x80078310: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80078314: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
L_80078318:
    // 0x80078318: mfc1        $a2, $f30
    ctx->r6 = (int32_t)ctx->f30.u32l;
    // 0x8007831C: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80078320: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80078324: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80078328: jal         0x80005B00
    // 0x8007832C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_6;
    // 0x8007832C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_6:
    // 0x80078330: lbu         $t3, 0x4C($s4)
    ctx->r11 = MEM_BU(ctx->r20, 0X4C);
    // 0x80078334: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80078338: lwc1        $f6, 0x7310($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7310);
    // 0x8007833C: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80078340: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x80078344: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x80078348: addu        $t5, $s7, $t4
    ctx->r13 = ADD32(ctx->r23, ctx->r12);
    // 0x8007834C: addu        $t6, $t5, $s3
    ctx->r14 = ADD32(ctx->r13, ctx->r19);
    // 0x80078350: lwc1        $f4, 0x0($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X0);
    // 0x80078354: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80078358: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8007835C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80078360: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80078364: jal         0x80005FE0
    // 0x80078368: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_7;
    // 0x80078368: nop

    after_7:
    // 0x8007836C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80078370: bne         $s1, $fp, L_80078288
    if (ctx->r17 != ctx->r30) {
        // 0x80078374: addiu       $s3, $s3, 0x4
        ctx->r19 = ADD32(ctx->r19, 0X4);
            goto L_80078288;
    }
    // 0x80078374: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x80078378: lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X74);
    // 0x8007837C: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80078380: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x80078384: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x80078388: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x8007838C: ldc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X40);
    // 0x80078390: ldc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X48);
    // 0x80078394: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x80078398: lw          $s1, 0x54($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X54);
    // 0x8007839C: lw          $s2, 0x58($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X58);
    // 0x800783A0: lw          $s3, 0x5C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X5C);
    // 0x800783A4: lw          $s4, 0x60($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X60);
    // 0x800783A8: lw          $s5, 0x64($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X64);
    // 0x800783AC: lw          $s6, 0x68($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X68);
    // 0x800783B0: lw          $s7, 0x6C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X6C);
    // 0x800783B4: lw          $fp, 0x70($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X70);
    // 0x800783B8: jr          $ra
    // 0x800783BC: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x800783BC: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void Scenery360_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005F2F4: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8005F2F8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8005F2FC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8005F300: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8005F304: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x8005F308: addiu       $t7, $t7, -0x2CC
    ctx->r15 = ADD32(ctx->r15, -0X2CC);
    // 0x8005F30C: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x8005F310: addiu       $t6, $sp, 0x54
    ctx->r14 = ADD32(ctx->r29, 0X54);
    // 0x8005F314: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x8005F318: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x8005F31C: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x8005F320: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x8005F324: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8005F328: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x8005F32C: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x8005F330: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8005F334: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005F338: lwc1        $f0, 0x637C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X637C);
    // 0x8005F33C: lui         $at, 0x44FA
    ctx->r1 = S32(0X44FA << 16);
    // 0x8005F340: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8005F344: lhu         $v0, 0x2($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X2);
    // 0x8005F348: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8005F34C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8005F350: addiu       $at, $zero, 0x9C
    ctx->r1 = ADD32(0, 0X9C);
    // 0x8005F354: bne         $v0, $at, L_8005F378
    if (ctx->r2 != ctx->r1) {
        // 0x8005F358: lui         $t2, 0x8017
        ctx->r10 = S32(0X8017 << 16);
            goto L_8005F378;
    }
    // 0x8005F358: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x8005F35C: lui         $at, 0x457A
    ctx->r1 = S32(0X457A << 16);
    // 0x8005F360: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8005F364: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005F368: lwc1        $f0, 0x6380($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6380);
    // 0x8005F36C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005F370: b           L_8005F3BC
    // 0x8005F374: lwc1        $f16, 0x6384($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6384);
        goto L_8005F3BC;
    // 0x8005F374: lwc1        $f16, 0x6384($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6384);
L_8005F378:
    // 0x8005F378: lw          $t1, -0x7DCC($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X7DCC);
    // 0x8005F37C: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8005F380: bne         $t1, $at, L_8005F398
    if (ctx->r9 != ctx->r1) {
        // 0x8005F384: lui         $at, 0x800D
        ctx->r1 = S32(0X800D << 16);
            goto L_8005F398;
    }
    // 0x8005F384: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005F388: lwc1        $f0, 0x6388($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6388);
    // 0x8005F38C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005F390: b           L_8005F3BC
    // 0x8005F394: lwc1        $f18, 0x638C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X638C);
        goto L_8005F3BC;
    // 0x8005F394: lwc1        $f18, 0x638C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X638C);
L_8005F398:
    // 0x8005F398: addiu       $at, $zero, 0x8F
    ctx->r1 = ADD32(0, 0X8F);
    // 0x8005F39C: bne         $v0, $at, L_8005F3BC
    if (ctx->r2 != ctx->r1) {
        // 0x8005F3A0: lui         $at, 0x800D
        ctx->r1 = S32(0X800D << 16);
            goto L_8005F3BC;
    }
    // 0x8005F3A0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005F3A4: lwc1        $f16, 0x6390($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6390);
    // 0x8005F3A8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005F3AC: lwc1        $f0, 0x6394($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6394);
    // 0x8005F3B0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005F3B4: lwc1        $f18, 0x6398($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6398);
    // 0x8005F3B8: mov.s       $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = ctx->f16.fl;
L_8005F3BC:
    // 0x8005F3BC: lbu         $t2, 0x7C98($t2)
    ctx->r10 = MEM_BU(ctx->r10, 0X7C98);
    // 0x8005F3C0: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8005F3C4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005F3C8: beq         $t2, $zero, L_8005F3E0
    if (ctx->r10 == 0) {
        // 0x8005F3CC: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_8005F3E0;
    }
    // 0x8005F3CC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8005F3D0: lw          $t3, -0x7DCC($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X7DCC);
    // 0x8005F3D4: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x8005F3D8: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8005F3DC: bne         $t3, $at, L_8005F42C
    if (ctx->r11 != ctx->r1) {
        // 0x8005F3E0: lui         $at, 0x8018
        ctx->r1 = S32(0X8018 << 16);
            goto L_8005F42C;
    }
L_8005F3E0:
    // 0x8005F3E0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005F3E4: lwc1        $f6, -0x7B84($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7B84);
    // 0x8005F3E8: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8005F3EC: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x8005F3F0: lw          $a3, 0xC($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XC);
    // 0x8005F3F4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8005F3F8: swc1        $f18, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f18.u32l;
    // 0x8005F3FC: swc1        $f16, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f16.u32l;
    // 0x8005F400: swc1        $f12, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f12.u32l;
    // 0x8005F404: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x8005F408: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x8005F40C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8005F410: jal         0x80005B00
    // 0x8005F414: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Translate(rdram, ctx);
        goto after_0;
    // 0x8005F414: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_0:
    // 0x8005F418: lwc1        $f0, 0x40($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8005F41C: lwc1        $f12, 0x44($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8005F420: lwc1        $f16, 0x3C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8005F424: b           L_8005F468
    // 0x8005F428: lwc1        $f18, 0x38($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X38);
        goto L_8005F468;
    // 0x8005F428: lwc1        $f18, 0x38($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X38);
L_8005F42C:
    // 0x8005F42C: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x8005F430: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    // 0x8005F434: lw          $a3, 0xC($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XC);
    // 0x8005F438: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005F43C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8005F440: swc1        $f18, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f18.u32l;
    // 0x8005F444: swc1        $f16, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f16.u32l;
    // 0x8005F448: swc1        $f12, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f12.u32l;
    // 0x8005F44C: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x8005F450: jal         0x80005B00
    // 0x8005F454: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    Matrix_Translate(rdram, ctx);
        goto after_1;
    // 0x8005F454: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_1:
    // 0x8005F458: lwc1        $f0, 0x40($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8005F45C: lwc1        $f12, 0x44($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8005F460: lwc1        $f16, 0x3C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8005F464: lwc1        $f18, 0x38($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X38);
L_8005F468:
    // 0x8005F468: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005F46C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8005F470: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x8005F474: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    // 0x8005F478: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x8005F47C: swc1        $f12, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f12.u32l;
    // 0x8005F480: swc1        $f16, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f16.u32l;
    // 0x8005F484: jal         0x80006970
    // 0x8005F488: swc1        $f18, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f18.u32l;
    Matrix_MultVec3f(rdram, ctx);
        goto after_2;
    // 0x8005F488: swc1        $f18, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f18.u32l;
    after_2:
    // 0x8005F48C: lwc1        $f12, 0x44($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8005F490: lwc1        $f14, 0x50($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8005F494: lwc1        $f0, 0x40($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8005F498: lwc1        $f16, 0x3C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8005F49C: c.lt.s      $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl < ctx->f12.fl;
    // 0x8005F4A0: lwc1        $f18, 0x38($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8005F4A4: bc1fl       L_8005F660
    if (!c1cs) {
        // 0x8005F4A8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8005F660;
    }
    goto skip_0;
    // 0x8005F4A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8005F4AC: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x8005F4B0: nop

    // 0x8005F4B4: bc1fl       L_8005F660
    if (!c1cs) {
        // 0x8005F4B8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8005F660;
    }
    goto skip_1;
    // 0x8005F4B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x8005F4BC: mul.s       $f12, $f14, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = MUL_S(ctx->f14.fl, ctx->f18.fl);
    // 0x8005F4C0: lwc1        $f0, 0x4C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8005F4C4: abs.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = fabsf(ctx->f0.fl);
    // 0x8005F4C8: lwc1        $f0, 0x48($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8005F4CC: abs.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = fabsf(ctx->f12.fl);
    // 0x8005F4D0: add.s       $f10, $f12, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f12.fl + ctx->f16.fl;
    // 0x8005F4D4: c.lt.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl < ctx->f10.fl;
    // 0x8005F4D8: nop

    // 0x8005F4DC: bc1fl       L_8005F660
    if (!c1cs) {
        // 0x8005F4E0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8005F660;
    }
    goto skip_2;
    // 0x8005F4E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x8005F4E4: add.s       $f4, $f12, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f12.fl + ctx->f16.fl;
    // 0x8005F4E8: abs.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = fabsf(ctx->f0.fl);
    // 0x8005F4EC: c.lt.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl < ctx->f4.fl;
    // 0x8005F4F0: nop

    // 0x8005F4F4: bc1fl       L_8005F660
    if (!c1cs) {
        // 0x8005F4F8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8005F660;
    }
    goto skip_3;
    // 0x8005F4F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_3:
    // 0x8005F4FC: jal         0x8005F670
    // 0x8005F500: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    Display_SetSecondLight(rdram, ctx);
        goto after_3;
    // 0x8005F500: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    after_3:
    // 0x8005F504: lhu         $t9, 0x2($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X2);
    // 0x8005F508: addiu       $at, $zero, 0x83
    ctx->r1 = ADD32(0, 0X83);
    // 0x8005F50C: bne         $t9, $at, L_8005F604
    if (ctx->r25 != ctx->r1) {
        // 0x8005F510: lui         $at, 0x800D
        ctx->r1 = S32(0X800D << 16);
            goto L_8005F604;
    }
    // 0x8005F510: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005F514: lwc1        $f8, 0x639C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X639C);
    // 0x8005F518: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8005F51C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005F520: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8005F524: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8005F528: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8005F52C: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8005F530: jal         0x80005E90
    // 0x8005F534: nop

    Matrix_RotateY(rdram, ctx);
        goto after_4;
    // 0x8005F534: nop

    after_4:
    // 0x8005F538: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005F53C: lwc1        $f6, 0x63A0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X63A0);
    // 0x8005F540: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8005F544: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005F548: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8005F54C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8005F550: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8005F554: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8005F558: jal         0x80005D44
    // 0x8005F55C: nop

    Matrix_RotateX(rdram, ctx);
        goto after_5;
    // 0x8005F55C: nop

    after_5:
    // 0x8005F560: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005F564: lwc1        $f4, 0x63A4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X63A4);
    // 0x8005F568: lwc1        $f10, 0x18($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8005F56C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005F570: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8005F574: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8005F578: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8005F57C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8005F580: jal         0x80005FE0
    // 0x8005F584: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_6;
    // 0x8005F584: nop

    after_6:
    // 0x8005F588: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005F58C: lui         $a1, 0x3FC9
    ctx->r5 = S32(0X3FC9 << 16);
    // 0x8005F590: ori         $a1, $a1, 0xFDB
    ctx->r5 = ctx->r5 | 0XFDB;
    // 0x8005F594: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8005F598: jal         0x80005E90
    // 0x8005F59C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateY(rdram, ctx);
        goto after_7;
    // 0x8005F59C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_7:
    // 0x8005F5A0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8005F5A4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005F5A8: lui         $a1, 0xC409
    ctx->r5 = S32(0XC409 << 16);
    // 0x8005F5AC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8005F5B0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8005F5B4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8005F5B8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8005F5BC: ori         $a1, $a1, 0xC000
    ctx->r5 = ctx->r5 | 0XC000;
    // 0x8005F5C0: jal         0x80005B00
    // 0x8005F5C4: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Translate(rdram, ctx);
        goto after_8;
    // 0x8005F5C4: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_8:
    // 0x8005F5C8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8005F5CC: jal         0x80006EB8
    // 0x8005F5D0: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_9;
    // 0x8005F5D0: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    after_9:
    // 0x8005F5D4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8005F5D8: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8005F5DC: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8005F5E0: lui         $t0, 0x600
    ctx->r8 = S32(0X600 << 16);
    // 0x8005F5E4: addiu       $t0, $t0, 0x7650
    ctx->r8 = ADD32(ctx->r8, 0X7650);
    // 0x8005F5E8: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8005F5EC: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8005F5F0: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x8005F5F4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8005F5F8: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x8005F5FC: b           L_8005F660
    // 0x8005F600: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8005F660;
    // 0x8005F600: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8005F604:
    // 0x8005F604: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005F608: lwc1        $f10, 0x63A8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X63A8);
    // 0x8005F60C: lwc1        $f8, 0x14($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8005F610: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005F614: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8005F618: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8005F61C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8005F620: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8005F624: jal         0x80005E90
    // 0x8005F628: nop

    Matrix_RotateY(rdram, ctx);
        goto after_10;
    // 0x8005F628: nop

    after_10:
    // 0x8005F62C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8005F630: jal         0x80006EB8
    // 0x8005F634: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_11;
    // 0x8005F634: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    after_11:
    // 0x8005F638: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8005F63C: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8005F640: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8005F644: lui         $t2, 0x600
    ctx->r10 = S32(0X600 << 16);
    // 0x8005F648: addiu       $t1, $v1, 0x8
    ctx->r9 = ADD32(ctx->r3, 0X8);
    // 0x8005F64C: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x8005F650: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x8005F654: lw          $t3, 0x1C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X1C);
    // 0x8005F658: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x8005F65C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8005F660:
    // 0x8005F660: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8005F664: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x8005F668: jr          $ra
    // 0x8005F66C: nop

    return;
    // 0x8005F66C: nop

;}
RECOMP_FUNC void Play_SetupStarfield(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A5EBC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A5EC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A5EC4: jal         0x800A5D6C
    // 0x800A5EC8: nop

    Play_GenerateStarfield(rdram, ctx);
        goto after_0;
    // 0x800A5EC8: nop

    after_0:
    // 0x800A5ECC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A5ED0: lwc1        $f4, -0x7CAC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7CAC);
    // 0x800A5ED4: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x800A5ED8: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x800A5EDC: addiu       $a0, $a0, 0x7940
    ctx->r4 = ADD32(ctx->r4, 0X7940);
    // 0x800A5EE0: addiu       $v1, $v1, -0x7BF0
    ctx->r3 = ADD32(ctx->r3, -0X7BF0);
    // 0x800A5EE4: addiu       $t6, $zero, 0x258
    ctx->r14 = ADD32(0, 0X258);
    // 0x800A5EE8: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800A5EEC: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800A5EF0: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x800A5EF4: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
    // 0x800A5EF8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800A5EFC: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x800A5F00: bne         $v0, $at, L_800A5F10
    if (ctx->r2 != ctx->r1) {
        // 0x800A5F04: lui         $t2, 0x8017
        ctx->r10 = S32(0X8017 << 16);
            goto L_800A5F10;
    }
    // 0x800A5F04: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x800A5F08: addiu       $t7, $zero, 0x12C
    ctx->r15 = ADD32(0, 0X12C);
    // 0x800A5F0C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
L_800A5F10:
    // 0x800A5F10: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x800A5F14: bne         $v0, $at, L_800A5F20
    if (ctx->r2 != ctx->r1) {
        // 0x800A5F18: addiu       $t8, $zero, 0x190
        ctx->r24 = ADD32(0, 0X190);
            goto L_800A5F20;
    }
    // 0x800A5F18: addiu       $t8, $zero, 0x190
    ctx->r24 = ADD32(0, 0X190);
    // 0x800A5F1C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
L_800A5F20:
    // 0x800A5F20: lw          $t9, 0x7834($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7834);
    // 0x800A5F24: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x800A5F28: addiu       $t0, $zero, 0x320
    ctx->r8 = ADD32(0, 0X320);
    // 0x800A5F2C: beq         $t9, $at, L_800A5F38
    if (ctx->r25 == ctx->r1) {
        // 0x800A5F30: addiu       $t1, $zero, 0x1F4
        ctx->r9 = ADD32(0, 0X1F4);
            goto L_800A5F38;
    }
    // 0x800A5F30: addiu       $t1, $zero, 0x1F4
    ctx->r9 = ADD32(0, 0X1F4);
    // 0x800A5F34: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
L_800A5F38:
    // 0x800A5F38: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x800A5F3C: bne         $v0, $at, L_800A5F48
    if (ctx->r2 != ctx->r1) {
        // 0x800A5F40: nop
    
            goto L_800A5F48;
    }
    // 0x800A5F40: nop

    // 0x800A5F44: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
L_800A5F48:
    // 0x800A5F48: lw          $t2, 0x78E8($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X78E8);
    // 0x800A5F4C: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x800A5F50: beq         $t2, $zero, L_800A5F5C
    if (ctx->r10 == 0) {
        // 0x800A5F54: nop
    
            goto L_800A5F5C;
    }
    // 0x800A5F54: nop

    // 0x800A5F58: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_800A5F5C:
    // 0x800A5F5C: bne         $v0, $at, L_800A5F74
    if (ctx->r2 != ctx->r1) {
        // 0x800A5F60: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800A5F74;
    }
    // 0x800A5F60: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A5F64: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A5F68: addiu       $t3, $zero, 0x12C
    ctx->r11 = ADD32(0, 0X12C);
    // 0x800A5F6C: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x800A5F70: swc1        $f6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f6.u32l;
L_800A5F74:
    // 0x800A5F74: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800A5F78: bne         $v0, $at, L_800A5F90
    if (ctx->r2 != ctx->r1) {
        // 0x800A5F7C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800A5F90;
    }
    // 0x800A5F7C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A5F80: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800A5F84: addiu       $t4, $zero, 0x320
    ctx->r12 = ADD32(0, 0X320);
    // 0x800A5F88: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x800A5F8C: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
L_800A5F90:
    // 0x800A5F90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A5F94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A5F98: jr          $ra
    // 0x800A5F9C: nop

    return;
    // 0x800A5F9C: nop

;}
RECOMP_FUNC void RCP_SetupDL_74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BA4C0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BA4C4: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x800BA4C8: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800BA4CC: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x800BA4D0: addiu       $t8, $t8, 0x4680
    ctx->r24 = ADD32(ctx->r24, 0X4680);
    // 0x800BA4D4: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800BA4D8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800BA4DC: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x800BA4E0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800BA4E4: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800BA4E8: jr          $ra
    // 0x800BA4EC: nop

    return;
    // 0x800BA4EC: nop

;}
RECOMP_FUNC void RCP_SetupDL_44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BA5E0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BA5E4: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x800BA5E8: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800BA5EC: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x800BA5F0: addiu       $t8, $t8, 0x3E10
    ctx->r24 = ADD32(ctx->r24, 0X3E10);
    // 0x800BA5F4: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800BA5F8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800BA5FC: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x800BA600: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800BA604: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800BA608: jr          $ra
    // 0x800BA60C: nop

    return;
    // 0x800BA60C: nop

;}
RECOMP_FUNC void RCP_SetupDL_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B8F48: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800B8F4C: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x800B8F50: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800B8F54: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x800B8F58: addiu       $t8, $t8, 0x31F8
    ctx->r24 = ADD32(ctx->r24, 0X31F8);
    // 0x800B8F5C: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800B8F60: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800B8F64: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x800B8F68: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800B8F6C: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800B8F70: jr          $ra
    // 0x800B8F74: nop

    return;
    // 0x800B8F74: nop

;}
RECOMP_FUNC void Effect_ShootAtCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007F20C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8007F210: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x8007F214: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8007F218: mtc1        $a1, $f14
    ctx->f14.u32l = ctx->r5;
    // 0x8007F21C: mtc1        $a3, $f12
    ctx->f12.u32l = ctx->r7;
    // 0x8007F220: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8007F224: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8007F228: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8007F22C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8007F230: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8007F234: lw          $v0, -0x7D80($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D80);
    // 0x8007F238: lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // 0x8007F23C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8007F240: lwc1        $f4, 0x48($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X48);
    // 0x8007F244: addiu       $s0, $s0, 0x3754
    ctx->r16 = ADD32(ctx->r16, 0X3754);
    // 0x8007F248: addiu       $a0, $a0, -0x4438
    ctx->r4 = ADD32(ctx->r4, -0X4438);
    // 0x8007F24C: sub.s       $f0, $f12, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f4.fl;
    // 0x8007F250: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8007F254: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8007F258: nop

    // 0x8007F25C: bc1t        L_8007F27C
    if (c1cs) {
        // 0x8007F260: nop
    
            goto L_8007F27C;
    }
    // 0x8007F260: nop

    // 0x8007F264: lwc1        $f6, 0x40($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X40);
    // 0x8007F268: sub.s       $f0, $f14, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f14.fl - ctx->f6.fl;
    // 0x8007F26C: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8007F270: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8007F274: nop

    // 0x8007F278: bc1f        L_8007F2E8
    if (!c1cs) {
        // 0x8007F27C: lui         $v0, 0x8017
        ctx->r2 = S32(0X8017 << 16);
            goto L_8007F2E8;
    }
L_8007F27C:
    // 0x8007F27C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8007F280: addiu       $v0, $v0, 0x130
    ctx->r2 = ADD32(ctx->r2, 0X130);
    // 0x8007F284: lbu         $t6, 0x0($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X0);
L_8007F288:
    // 0x8007F288: bnel        $t6, $zero, L_8007F2DC
    if (ctx->r14 != 0) {
        // 0x8007F28C: addiu       $s0, $s0, -0x8C
        ctx->r16 = ADD32(ctx->r16, -0X8C);
            goto L_8007F2DC;
    }
    goto skip_0;
    // 0x8007F28C: addiu       $s0, $s0, -0x8C
    ctx->r16 = ADD32(ctx->r16, -0X8C);
    skip_0:
    // 0x8007F290: swc1        $f12, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f12.u32l;
    // 0x8007F294: jal         0x80005708
    // 0x8007F298: swc1        $f14, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f14.u32l;
    Matrix_Push(rdram, ctx);
        goto after_0;
    // 0x8007F298: swc1        $f14, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x8007F29C: lwc1        $f14, 0x2C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8007F2A0: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8007F2A4: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8007F2A8: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x8007F2AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8007F2B0: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8007F2B4: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x8007F2B8: swc1        $f12, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f12.u32l;
    // 0x8007F2BC: jal         0x8007E93C
    // 0x8007F2C0: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    Effect_SetupShootAtCamera(rdram, ctx);
        goto after_1;
    // 0x8007F2C0: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x8007F2C4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8007F2C8: jal         0x80005740
    // 0x8007F2CC: addiu       $a0, $a0, -0x4438
    ctx->r4 = ADD32(ctx->r4, -0X4438);
    Matrix_Pop(rdram, ctx);
        goto after_2;
    // 0x8007F2CC: addiu       $a0, $a0, -0x4438
    ctx->r4 = ADD32(ctx->r4, -0X4438);
    after_2:
    // 0x8007F2D0: b           L_8007F2EC
    // 0x8007F2D4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8007F2EC;
    // 0x8007F2D4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8007F2D8: addiu       $s0, $s0, -0x8C
    ctx->r16 = ADD32(ctx->r16, -0X8C);
L_8007F2DC:
    // 0x8007F2DC: sltu        $at, $s0, $v0
    ctx->r1 = ctx->r16 < ctx->r2 ? 1 : 0;
    // 0x8007F2E0: beql        $at, $zero, L_8007F288
    if (ctx->r1 == 0) {
        // 0x8007F2E4: lbu         $t6, 0x0($s0)
        ctx->r14 = MEM_BU(ctx->r16, 0X0);
            goto L_8007F288;
    }
    goto skip_1;
    // 0x8007F2E4: lbu         $t6, 0x0($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X0);
    skip_1:
L_8007F2E8:
    // 0x8007F2E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8007F2EC:
    // 0x8007F2EC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8007F2F0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8007F2F4: jr          $ra
    // 0x8007F2F8: nop

    return;
    // 0x8007F2F8: nop

;}
RECOMP_FUNC void Save_WriteData(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002C50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80002C54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80002C58: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80002C5C: lbu         $t6, 0x7E80($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X7E80);
    // 0x80002C60: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80002C64: bne         $t6, $zero, L_80002C94
    if (ctx->r14 != 0) {
        // 0x80002C68: nop
    
            goto L_80002C94;
    }
    // 0x80002C68: nop

    // 0x80002C6C: jal         0x800071FC
    // 0x80002C70: addiu       $a0, $a0, 0x4F60
    ctx->r4 = ADD32(ctx->r4, 0X4F60);
    Save_WriteEeprom(rdram, ctx);
        goto after_0;
    // 0x80002C70: addiu       $a0, $a0, 0x4F60
    ctx->r4 = ADD32(ctx->r4, 0X4F60);
    after_0:
    // 0x80002C74: bne         $v0, $zero, L_80002C94
    if (ctx->r2 != 0) {
        // 0x80002C78: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_80002C94;
    }
    // 0x80002C78: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80002C7C: addiu       $a0, $a0, 0x2318
    ctx->r4 = ADD32(ctx->r4, 0X2318);
    // 0x80002C80: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    // 0x80002C84: jal         0x80020720
    // 0x80002C88: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x80002C88: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80002C8C: b           L_80002CAC
    // 0x80002C90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80002CAC;
    // 0x80002C90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80002C94:
    // 0x80002C94: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80002C98: addiu       $a0, $a0, 0x2318
    ctx->r4 = ADD32(ctx->r4, 0X2318);
    // 0x80002C9C: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    // 0x80002CA0: jal         0x80020720
    // 0x80002CA4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x80002CA4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80002CA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80002CAC:
    // 0x80002CAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80002CB0: jr          $ra
    // 0x80002CB4: nop

    return;
    // 0x80002CB4: nop

;}
RECOMP_FUNC void Cutscene_LevelStart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004A52C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8004A530: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8004A534: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8004A538: addiu       $v0, $v0, 0x7A80
    ctx->r2 = ADD32(ctx->r2, 0X7A80);
    // 0x8004A53C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8004A540: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8004A544: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8004A548: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x8004A54C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8004A550: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8004A554: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8004A558: lw          $t8, 0x7880($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7880);
    // 0x8004A55C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8004A560: bne         $t8, $zero, L_8004A65C
    if (ctx->r24 != 0) {
        // 0x8004A564: nop
    
            goto L_8004A65C;
    }
    // 0x8004A564: nop

    // 0x8004A568: lw          $t9, -0x7DCC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7DCC);
    // 0x8004A56C: sltiu       $at, $t9, 0xE
    ctx->r1 = ctx->r25 < 0XE ? 1 : 0;
    // 0x8004A570: beq         $at, $zero, L_8004A64C
    if (ctx->r1 == 0) {
        // 0x8004A574: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_8004A64C;
    }
    // 0x8004A574: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8004A578: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004A57C: addu        $at, $at, $t9
    gpr jr_addend_8004A584 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8004A580: lw          $t9, 0x58D8($at)
    ctx->r25 = ADD32(ctx->r1, 0X58D8);
    // 0x8004A584: jr          $t9
    // 0x8004A588: nop

    switch (jr_addend_8004A584 >> 2) {
        case 0: goto L_8004A58C; break;
        case 1: goto L_8004A5A4; break;
        case 2: goto L_8004A5B4; break;
        case 3: goto L_8004A644; break;
        case 4: goto L_8004A64C; break;
        case 5: goto L_8004A5FC; break;
        case 6: goto L_8004A61C; break;
        case 7: goto L_8004A60C; break;
        case 8: goto L_8004A5DC; break;
        case 9: goto L_8004A64C; break;
        case 10: goto L_8004A64C; break;
        case 11: goto L_8004A5EC; break;
        case 12: goto L_8004A5C4; break;
        case 13: goto L_8004A634; break;
        default: switch_error(__func__, 0x8004A584, 0x800D58D8);
    }
    // 0x8004A588: nop

L_8004A58C:
    // 0x8004A58C: jal         0x8018F880
    // 0x8004A590: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Corneria_LevelStart(rdram, ctx);
        goto after_0;
    // 0x8004A590: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8004A594: jal         0x800AA800
    // 0x8004A598: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_FloorCheck(rdram, ctx);
        goto after_1;
    // 0x8004A598: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8004A59C: b           L_8004A64C
    // 0x8004A5A0: nop

        goto L_8004A64C;
    // 0x8004A5A0: nop

L_8004A5A4:
    // 0x8004A5A4: jal         0x8018CD8C
    // 0x8004A5A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Meteo_LevelStart(rdram, ctx);
        goto after_2;
    // 0x8004A5A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8004A5AC: b           L_8004A64C
    // 0x8004A5B0: nop

        goto L_8004A64C;
    // 0x8004A5B0: nop

L_8004A5B4:
    // 0x8004A5B4: jal         0x80193A30
    // 0x8004A5B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    SectorX_LevelStart(rdram, ctx);
        goto after_3;
    // 0x8004A5B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8004A5BC: b           L_8004A64C
    // 0x8004A5C0: nop

        goto L_8004A64C;
    // 0x8004A5C0: nop

L_8004A5C4:
    // 0x8004A5C4: jal         0x8018769C
    // 0x8004A5C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(0x8018769C)(rdram, ctx);
        goto after_4;
    // 0x8004A5C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8004A5CC: jal         0x800AA800
    // 0x8004A5D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_FloorCheck(rdram, ctx);
        goto after_5;
    // 0x8004A5D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8004A5D4: b           L_8004A64C
    // 0x8004A5D8: nop

        goto L_8004A64C;
    // 0x8004A5D8: nop

L_8004A5DC:
    // 0x8004A5DC: jal         0x8019D428
    // 0x8004A5E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Zoness_LevelStart(rdram, ctx);
        goto after_6;
    // 0x8004A5E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8004A5E4: b           L_8004A64C
    // 0x8004A5E8: nop

        goto L_8004A64C;
    // 0x8004A5E8: nop

L_8004A5EC:
    // 0x8004A5EC: jal         0x801AC754
    // 0x8004A5F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Macbeth_LevelStart(rdram, ctx);
        goto after_7;
    // 0x8004A5F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8004A5F4: b           L_8004A64C
    // 0x8004A5F8: nop

        goto L_8004A64C;
    // 0x8004A5F8: nop

L_8004A5FC:
    // 0x8004A5FC: jal         0x801A0AC0
    // 0x8004A600: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    SectorY_LevelStart(rdram, ctx);
        goto after_8;
    // 0x8004A600: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x8004A604: b           L_8004A64C
    // 0x8004A608: nop

        goto L_8004A64C;
    // 0x8004A608: nop

L_8004A60C:
    // 0x8004A60C: jal         0x801A10F4
    // 0x8004A610: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Solar_LevelStart(rdram, ctx);
        goto after_9;
    // 0x8004A610: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x8004A614: b           L_8004A64C
    // 0x8004A618: nop

        goto L_8004A64C;
    // 0x8004A618: nop

L_8004A61C:
    // 0x8004A61C: jal         0x801988B8
    // 0x8004A620: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Venom1_LevelStart(rdram, ctx);
        goto after_10;
    // 0x8004A620: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x8004A624: jal         0x800AA800
    // 0x8004A628: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_FloorCheck(rdram, ctx);
        goto after_11;
    // 0x8004A628: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x8004A62C: b           L_8004A64C
    // 0x8004A630: nop

        goto L_8004A64C;
    // 0x8004A630: nop

L_8004A634:
    // 0x8004A634: jal         0x800935E8
    // 0x8004A638: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Aquas_CsLevelStart(rdram, ctx);
        goto after_12;
    // 0x8004A638: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x8004A63C: b           L_8004A64C
    // 0x8004A640: nop

        goto L_8004A64C;
    // 0x8004A640: nop

L_8004A644:
    // 0x8004A644: jal         0x8018DF74
    // 0x8004A648: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Area6_LevelStart(rdram, ctx);
        goto after_13;
    // 0x8004A648: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
L_8004A64C:
    // 0x8004A64C: jal         0x8004990C
    // 0x8004A650: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Cutscene_PathTexScroll(rdram, ctx);
        goto after_14;
    // 0x8004A650: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x8004A654: b           L_8004A6F0
    // 0x8004A658: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8004A6F0;
    // 0x8004A658: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8004A65C:
    // 0x8004A65C: lw          $t0, -0x7DCC($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7DCC);
    // 0x8004A660: addiu       $t1, $t0, -0xE
    ctx->r9 = ADD32(ctx->r8, -0XE);
    // 0x8004A664: sltiu       $at, $t1, 0x6
    ctx->r1 = ctx->r9 < 0X6 ? 1 : 0;
    // 0x8004A668: beq         $at, $zero, L_8004A6EC
    if (ctx->r1 == 0) {
        // 0x8004A66C: sll         $t1, $t1, 2
        ctx->r9 = S32(ctx->r9 << 2);
            goto L_8004A6EC;
    }
    // 0x8004A66C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8004A670: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004A674: addu        $at, $at, $t1
    gpr jr_addend_8004A67C = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x8004A678: lw          $t1, 0x5910($at)
    ctx->r9 = ADD32(ctx->r1, 0X5910);
    // 0x8004A67C: jr          $t1
    // 0x8004A680: nop

    switch (jr_addend_8004A67C >> 2) {
        case 0: goto L_8004A684; break;
        case 1: goto L_8004A6EC; break;
        case 2: goto L_8004A6CC; break;
        case 3: goto L_8004A6B4; break;
        case 4: goto L_8004A6E4; break;
        case 5: goto L_8004A69C; break;
        default: switch_error(__func__, 0x8004A67C, 0x800D5910);
    }
    // 0x8004A680: nop

L_8004A684:
    // 0x8004A684: jal         0x8002ED60
    // 0x8004A688: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    AllRange_FortunaIntro(rdram, ctx);
        goto after_15;
    // 0x8004A688: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x8004A68C: jal         0x800AA800
    // 0x8004A690: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_FloorCheck(rdram, ctx);
        goto after_16;
    // 0x8004A690: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x8004A694: b           L_8004A6F0
    // 0x8004A698: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8004A6F0;
    // 0x8004A698: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8004A69C:
    // 0x8004A69C: jal         0x80196BF8
    // 0x8004A6A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Venom2_LevelStart(rdram, ctx);
        goto after_17;
    // 0x8004A6A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x8004A6A4: jal         0x800AA800
    // 0x8004A6A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_FloorCheck(rdram, ctx);
        goto after_18;
    // 0x8004A6A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x8004A6AC: b           L_8004A6F0
    // 0x8004A6B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8004A6F0;
    // 0x8004A6B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8004A6B4:
    // 0x8004A6B4: jal         0x8018EF6C
    // 0x8004A6B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Bolse_LevelStart(rdram, ctx);
        goto after_19;
    // 0x8004A6B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x8004A6BC: jal         0x800AA800
    // 0x8004A6C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_FloorCheck(rdram, ctx);
        goto after_20;
    // 0x8004A6C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x8004A6C4: b           L_8004A6F0
    // 0x8004A6C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8004A6F0;
    // 0x8004A6C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8004A6CC:
    // 0x8004A6CC: jal         0x80192E20
    // 0x8004A6D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Katina_LevelStart(rdram, ctx);
        goto after_21;
    // 0x8004A6D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x8004A6D4: jal         0x800AA800
    // 0x8004A6D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_FloorCheck(rdram, ctx);
        goto after_22;
    // 0x8004A6D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x8004A6DC: b           L_8004A6F0
    // 0x8004A6E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8004A6F0;
    // 0x8004A6E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8004A6E4:
    // 0x8004A6E4: jal         0x8019BA64
    // 0x8004A6E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    SectorZ_LevelStart(rdram, ctx);
        goto after_23;
    // 0x8004A6E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
L_8004A6EC:
    // 0x8004A6EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8004A6F0:
    // 0x8004A6F0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8004A6F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8004A6F8: jr          $ra
    // 0x8004A6FC: nop

    return;
    // 0x8004A6FC: nop

;}
RECOMP_FUNC void Effect_OrbRing_Setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083C70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80083C74: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80083C78: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80083C7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80083C80: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80083C84: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80083C88: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80083C8C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80083C90: jal         0x80061474
    // 0x80083C94: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    Effect_Initialize(rdram, ctx);
        goto after_0;
    // 0x80083C94: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80083C98: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80083C9C: lwc1        $f0, 0x1C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80083CA0: lwc1        $f2, 0x20($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80083CA4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80083CA8: addiu       $t7, $zero, 0x18F
    ctx->r15 = ADD32(0, 0X18F);
    // 0x80083CAC: sb          $t6, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r14;
    // 0x80083CB0: sh          $t7, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r15;
    // 0x80083CB4: swc1        $f0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f0.u32l;
    // 0x80083CB8: swc1        $f0, 0x60($a2)
    MEM_W(0X60, ctx->r6) = ctx->f0.u32l;
    // 0x80083CBC: swc1        $f2, 0x64($a2)
    MEM_W(0X64, ctx->r6) = ctx->f2.u32l;
    // 0x80083CC0: swc1        $f2, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f2.u32l;
    // 0x80083CC4: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80083CC8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80083CCC: addiu       $t8, $zero, 0x64
    ctx->r24 = ADD32(0, 0X64);
    // 0x80083CD0: swc1        $f4, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f4.u32l;
    // 0x80083CD4: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80083CD8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80083CDC: andi        $a1, $t7, 0xFFFF
    ctx->r5 = ctx->r15 & 0XFFFF;
    // 0x80083CE0: swc1        $f6, 0x54($a2)
    MEM_W(0X54, ctx->r6) = ctx->f6.u32l;
    // 0x80083CE4: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80083CE8: addiu       $a0, $a2, 0x1C
    ctx->r4 = ADD32(ctx->r6, 0X1C);
    // 0x80083CEC: swc1        $f8, 0x58($a2)
    MEM_W(0X58, ctx->r6) = ctx->f8.u32l;
    // 0x80083CF0: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80083CF4: swc1        $f10, 0x5C($a2)
    MEM_W(0X5C, ctx->r6) = ctx->f10.u32l;
    // 0x80083CF8: lwc1        $f16, 0x34($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80083CFC: swc1        $f16, 0x68($a2)
    MEM_W(0X68, ctx->r6) = ctx->f16.u32l;
    // 0x80083D00: lwc1        $f18, 0x76CC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X76CC);
    // 0x80083D04: sh          $t8, 0x50($a2)
    MEM_H(0X50, ctx->r6) = ctx->r24;
    // 0x80083D08: swc1        $f4, 0x6C($a2)
    MEM_W(0X6C, ctx->r6) = ctx->f4.u32l;
    // 0x80083D0C: swc1        $f18, 0x70($a2)
    MEM_W(0X70, ctx->r6) = ctx->f18.u32l;
    // 0x80083D10: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x80083D14: jal         0x800612B8
    // 0x80083D18: sh          $t9, 0x44($a2)
    MEM_H(0X44, ctx->r6) = ctx->r25;
    Object_SetInfo(rdram, ctx);
        goto after_1;
    // 0x80083D18: sh          $t9, 0x44($a2)
    MEM_H(0X44, ctx->r6) = ctx->r25;
    after_1:
    // 0x80083D1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80083D20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80083D24: jr          $ra
    // 0x80083D28: nop

    return;
    // 0x80083D28: nop

;}
RECOMP_FUNC void Effect_Effect382_Setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007AF30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007AF34: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8007AF38: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8007AF3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007AF40: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8007AF44: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8007AF48: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8007AF4C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8007AF50: jal         0x80061474
    // 0x8007AF54: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    Effect_Initialize(rdram, ctx);
        goto after_0;
    // 0x8007AF54: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x8007AF58: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8007AF5C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8007AF60: addiu       $t7, $zero, 0x17E
    ctx->r15 = ADD32(0, 0X17E);
    // 0x8007AF64: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x8007AF68: sb          $t6, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r14;
    // 0x8007AF6C: sh          $t7, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r15;
    // 0x8007AF70: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8007AF74: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8007AF78: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8007AF7C: swc1        $f4, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f4.u32l;
    // 0x8007AF80: swc1        $f6, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f6.u32l;
    // 0x8007AF84: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8007AF88: addiu       $t8, $zero, 0x64
    ctx->r24 = ADD32(0, 0X64);
    // 0x8007AF8C: andi        $a1, $t7, 0xFFFF
    ctx->r5 = ctx->r15 & 0XFFFF;
    // 0x8007AF90: swc1        $f8, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f8.u32l;
    // 0x8007AF94: lwc1        $f10, 0x24($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8007AF98: addiu       $a0, $a2, 0x1C
    ctx->r4 = ADD32(ctx->r6, 0X1C);
    // 0x8007AF9C: swc1        $f10, 0x54($a2)
    MEM_W(0X54, ctx->r6) = ctx->f10.u32l;
    // 0x8007AFA0: lwc1        $f18, 0x7D08($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7D08);
    // 0x8007AFA4: lwc1        $f16, 0x28($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8007AFA8: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8007AFAC: swc1        $f4, 0x5C($a2)
    MEM_W(0X5C, ctx->r6) = ctx->f4.u32l;
    // 0x8007AFB0: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8007AFB4: sh          $t8, 0x50($a2)
    MEM_H(0X50, ctx->r6) = ctx->r24;
    // 0x8007AFB8: jal         0x800612B8
    // 0x8007AFBC: swc1        $f6, 0x6C($a2)
    MEM_W(0X6C, ctx->r6) = ctx->f6.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_1;
    // 0x8007AFBC: swc1        $f6, 0x6C($a2)
    MEM_W(0X6C, ctx->r6) = ctx->f6.u32l;
    after_1:
    // 0x8007AFC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007AFC4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007AFC8: jr          $ra
    // 0x8007AFCC: nop

    return;
    // 0x8007AFCC: nop

;}
RECOMP_FUNC void func_enmy_80066E80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066E80: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80066E84: jr          $ra
    // 0x80066E88: nop

    return;
    // 0x80066E88: nop

;}
RECOMP_FUNC void Player_UpdateShields(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B40AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B40B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B40B4: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800B40B8: lw          $v0, 0x268($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X268);
    // 0x800B40BC: blez        $v0, L_800B40E8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800B40C0: addiu       $t6, $v0, -0x2
        ctx->r14 = ADD32(ctx->r2, -0X2);
            goto L_800B40E8;
    }
    // 0x800B40C0: addiu       $t6, $v0, -0x2
    ctx->r14 = ADD32(ctx->r2, -0X2);
    // 0x800B40C4: bgtz        $t6, L_800B40D0
    if (SIGNED(ctx->r14) > 0) {
        // 0x800B40C8: sw          $t6, 0x268($a1)
        MEM_W(0X268, ctx->r5) = ctx->r14;
            goto L_800B40D0;
    }
    // 0x800B40C8: sw          $t6, 0x268($a1)
    MEM_W(0X268, ctx->r5) = ctx->r14;
    // 0x800B40CC: sw          $zero, 0x268($a1)
    MEM_W(0X268, ctx->r5) = 0;
L_800B40D0:
    // 0x800B40D0: lw          $t8, 0x264($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X264);
    // 0x800B40D4: addiu       $t9, $t8, -0x2
    ctx->r25 = ADD32(ctx->r24, -0X2);
    // 0x800B40D8: bgtz        $t9, L_800B40E8
    if (SIGNED(ctx->r25) > 0) {
        // 0x800B40DC: sw          $t9, 0x264($a1)
        MEM_W(0X264, ctx->r5) = ctx->r25;
            goto L_800B40E8;
    }
    // 0x800B40DC: sw          $t9, 0x264($a1)
    MEM_W(0X264, ctx->r5) = ctx->r25;
    // 0x800B40E0: sw          $zero, 0x264($a1)
    MEM_W(0X264, ctx->r5) = 0;
    // 0x800B40E4: sw          $zero, 0x268($a1)
    MEM_W(0X268, ctx->r5) = 0;
L_800B40E8:
    // 0x800B40E8: lw          $v0, 0x26C($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X26C);
    // 0x800B40EC: blez        $v0, L_800B414C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800B40F0: addiu       $t1, $v0, -0x2
        ctx->r9 = ADD32(ctx->r2, -0X2);
            goto L_800B414C;
    }
    // 0x800B40F0: addiu       $t1, $v0, -0x2
    ctx->r9 = ADD32(ctx->r2, -0X2);
    // 0x800B40F4: sw          $zero, 0x268($a1)
    MEM_W(0X268, ctx->r5) = 0;
    // 0x800B40F8: bgtz        $t1, L_800B4104
    if (SIGNED(ctx->r9) > 0) {
        // 0x800B40FC: sw          $t1, 0x26C($a1)
        MEM_W(0X26C, ctx->r5) = ctx->r9;
            goto L_800B4104;
    }
    // 0x800B40FC: sw          $t1, 0x26C($a1)
    MEM_W(0X26C, ctx->r5) = ctx->r9;
    // 0x800B4100: sw          $zero, 0x26C($a1)
    MEM_W(0X26C, ctx->r5) = 0;
L_800B4104:
    // 0x800B4104: lw          $t3, 0x264($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X264);
    // 0x800B4108: addiu       $t4, $t3, 0x2
    ctx->r12 = ADD32(ctx->r11, 0X2);
    // 0x800B410C: sw          $t4, 0x264($a1)
    MEM_W(0X264, ctx->r5) = ctx->r12;
    // 0x800B4110: jal         0x800A3FC4
    // 0x800B4114: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    Play_GetMaxShields(rdram, ctx);
        goto after_0;
    // 0x800B4114: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x800B4118: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800B411C: lw          $t5, 0x264($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X264);
    // 0x800B4120: slt         $at, $t5, $v0
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800B4124: bnel        $at, $zero, L_800B4150
    if (ctx->r1 != 0) {
        // 0x800B4128: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800B4150;
    }
    goto skip_0;
    // 0x800B4128: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800B412C: jal         0x800A3FC4
    // 0x800B4130: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    Play_GetMaxShields(rdram, ctx);
        goto after_1;
    // 0x800B4130: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_1:
    // 0x800B4134: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800B4138: lui         $a0, 0x4100
    ctx->r4 = S32(0X4100 << 16);
    // 0x800B413C: ori         $a0, $a0, 0x7012
    ctx->r4 = ctx->r4 | 0X7012;
    // 0x800B4140: sw          $v0, 0x264($a1)
    MEM_W(0X264, ctx->r5) = ctx->r2;
    // 0x800B4144: jal         0x8001A838
    // 0x800B4148: sw          $zero, 0x26C($a1)
    MEM_W(0X26C, ctx->r5) = 0;
    Audio_KillSfxById(rdram, ctx);
        goto after_2;
    // 0x800B4148: sw          $zero, 0x26C($a1)
    MEM_W(0X26C, ctx->r5) = 0;
    after_2:
L_800B414C:
    // 0x800B414C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800B4150:
    // 0x800B4150: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B4154: jr          $ra
    // 0x800B4158: nop

    return;
    // 0x800B4158: nop

;}
RECOMP_FUNC void Matrix_Pop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005740: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80005744: addiu       $t7, $t6, -0x40
    ctx->r15 = ADD32(ctx->r14, -0X40);
    // 0x80005748: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8000574C: jr          $ra
    // 0x80005750: nop

    return;
    // 0x80005750: nop

;}
RECOMP_FUNC void func_versus_800BD2F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BD2F8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800BD2FC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800BD300: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800BD304: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800BD308: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BD30C: lui         $a1, 0x700
    ctx->r5 = S32(0X700 << 16);
    // 0x800BD310: lui         $a2, 0x700
    ctx->r6 = S32(0X700 << 16);
    // 0x800BD314: addiu       $t6, $zero, 0x10
    ctx->r14 = ADD32(0, 0X10);
    // 0x800BD318: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800BD31C: addiu       $a2, $a2, 0x4460
    ctx->r6 = ADD32(ctx->r6, 0X4460);
    // 0x800BD320: addiu       $a1, $a1, 0x4360
    ctx->r5 = ADD32(ctx->r5, 0X4360);
    // 0x800BD324: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x800BD328: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x800BD32C: swc1        $f12, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f12.u32l;
    // 0x800BD330: swc1        $f14, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f14.u32l;
    // 0x800BD334: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x800BD338: jal         0x8009D0BC
    // 0x800BD33C: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    Lib_TextureRect_CI8(rdram, ctx);
        goto after_0;
    // 0x800BD33C: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x800BD340: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800BD344: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800BD348: jr          $ra
    // 0x800BD34C: nop

    return;
    // 0x800BD34C: nop

;}
RECOMP_FUNC void ActorEvent_Effect394_Setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F140: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006F144: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8006F148: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8006F14C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006F150: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8006F154: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8006F158: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8006F15C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8006F160: jal         0x80061474
    // 0x8006F164: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    Effect_Initialize(rdram, ctx);
        goto after_0;
    // 0x8006F164: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x8006F168: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8006F16C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8006F170: addiu       $t7, $zero, 0x18A
    ctx->r15 = ADD32(0, 0X18A);
    // 0x8006F174: sb          $t6, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r14;
    // 0x8006F178: sh          $t7, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r15;
    // 0x8006F17C: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8006F180: addiu       $t8, $zero, 0x64
    ctx->r24 = ADD32(0, 0X64);
    // 0x8006F184: addiu       $t9, $zero, 0x66
    ctx->r25 = ADD32(0, 0X66);
    // 0x8006F188: swc1        $f4, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f4.u32l;
    // 0x8006F18C: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8006F190: addiu       $t0, $zero, 0x12
    ctx->r8 = ADD32(0, 0X12);
    // 0x8006F194: andi        $a1, $t7, 0xFFFF
    ctx->r5 = ctx->r15 & 0XFFFF;
    // 0x8006F198: swc1        $f6, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f6.u32l;
    // 0x8006F19C: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8006F1A0: addiu       $a0, $a2, 0x1C
    ctx->r4 = ADD32(ctx->r6, 0X1C);
    // 0x8006F1A4: swc1        $f8, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f8.u32l;
    // 0x8006F1A8: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8006F1AC: sh          $t8, 0x44($a2)
    MEM_H(0X44, ctx->r6) = ctx->r24;
    // 0x8006F1B0: sh          $t9, 0x78($a2)
    MEM_H(0X78, ctx->r6) = ctx->r25;
    // 0x8006F1B4: sh          $t0, 0x7A($a2)
    MEM_H(0X7A, ctx->r6) = ctx->r8;
    // 0x8006F1B8: jal         0x800612B8
    // 0x8006F1BC: swc1        $f10, 0x6C($a2)
    MEM_W(0X6C, ctx->r6) = ctx->f10.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_1;
    // 0x8006F1BC: swc1        $f10, 0x6C($a2)
    MEM_W(0X6C, ctx->r6) = ctx->f10.u32l;
    after_1:
    // 0x8006F1C0: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8006F1C4: addiu       $t1, $zero, 0x28
    ctx->r9 = ADD32(0, 0X28);
    // 0x8006F1C8: lui         $a1, 0x2903
    ctx->r5 = S32(0X2903 << 16);
    // 0x8006F1CC: ori         $a1, $a1, 0xB009
    ctx->r5 = ctx->r5 | 0XB009;
    // 0x8006F1D0: sb          $t1, 0x34($a2)
    MEM_B(0X34, ctx->r6) = ctx->r9;
    // 0x8006F1D4: jal         0x8007A6F0
    // 0x8006F1D8: addiu       $a0, $a2, 0x4
    ctx->r4 = ADD32(ctx->r6, 0X4);
    Effect_TimedSfx_Spawn(rdram, ctx);
        goto after_2;
    // 0x8006F1D8: addiu       $a0, $a2, 0x4
    ctx->r4 = ADD32(ctx->r6, 0X4);
    after_2:
    // 0x8006F1DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006F1E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006F1E4: jr          $ra
    // 0x8006F1E8: nop

    return;
    // 0x8006F1E8: nop

;}
RECOMP_FUNC void Actor_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069AAC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80069AB0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80069AB4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80069AB8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80069ABC: lhu         $v0, 0xBC($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XBC);
    // 0x80069AC0: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x80069AC4: beq         $v0, $zero, L_80069AD0
    if (ctx->r2 == 0) {
        // 0x80069AC8: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_80069AD0;
    }
    // 0x80069AC8: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80069ACC: sh          $t6, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r14;
L_80069AD0:
    // 0x80069AD0: lhu         $v0, 0xBE($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XBE);
    // 0x80069AD4: beq         $v0, $zero, L_80069AE0
    if (ctx->r2 == 0) {
        // 0x80069AD8: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_80069AE0;
    }
    // 0x80069AD8: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x80069ADC: sh          $t7, 0xBE($s0)
    MEM_H(0XBE, ctx->r16) = ctx->r15;
L_80069AE0:
    // 0x80069AE0: lhu         $v0, 0xC0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XC0);
    // 0x80069AE4: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x80069AE8: beq         $v0, $zero, L_80069AF4
    if (ctx->r2 == 0) {
        // 0x80069AEC: addiu       $t8, $v0, -0x1
        ctx->r24 = ADD32(ctx->r2, -0X1);
            goto L_80069AF4;
    }
    // 0x80069AEC: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x80069AF0: sh          $t8, 0xC0($s0)
    MEM_H(0XC0, ctx->r16) = ctx->r24;
L_80069AF4:
    // 0x80069AF4: lhu         $v0, 0xC2($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XC2);
    // 0x80069AF8: beq         $v0, $zero, L_80069B04
    if (ctx->r2 == 0) {
        // 0x80069AFC: addiu       $t9, $v0, -0x1
        ctx->r25 = ADD32(ctx->r2, -0X1);
            goto L_80069B04;
    }
    // 0x80069AFC: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x80069B00: sh          $t9, 0xC2($s0)
    MEM_H(0XC2, ctx->r16) = ctx->r25;
L_80069B04:
    // 0x80069B04: lhu         $v0, 0xC6($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XC6);
    // 0x80069B08: beq         $v0, $zero, L_80069B14
    if (ctx->r2 == 0) {
        // 0x80069B0C: addiu       $t1, $v0, -0x1
        ctx->r9 = ADD32(ctx->r2, -0X1);
            goto L_80069B14;
    }
    // 0x80069B0C: addiu       $t1, $v0, -0x1
    ctx->r9 = ADD32(ctx->r2, -0X1);
    // 0x80069B10: sh          $t1, 0xC6($s0)
    MEM_H(0XC6, ctx->r16) = ctx->r9;
L_80069B14:
    // 0x80069B14: lw          $t2, 0x78E8($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X78E8);
    // 0x80069B18: beql        $t2, $zero, L_80069BA4
    if (ctx->r10 == 0) {
        // 0x80069B1C: lbu         $v0, 0xCA($s0)
        ctx->r2 = MEM_BU(ctx->r16, 0XCA);
            goto L_80069BA4;
    }
    goto skip_0;
    // 0x80069B1C: lbu         $v0, 0xCA($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0XCA);
    skip_0:
    // 0x80069B20: lw          $a2, 0x78A8($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X78A8);
    // 0x80069B24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80069B28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80069B2C: blez        $a2, L_80069BEC
    if (SIGNED(ctx->r6) <= 0) {
        // 0x80069B30: addiu       $t0, $zero, 0x6
        ctx->r8 = ADD32(0, 0X6);
            goto L_80069BEC;
    }
    // 0x80069B30: addiu       $t0, $zero, 0x6
    ctx->r8 = ADD32(0, 0X6);
    // 0x80069B34: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x80069B38: addiu       $a3, $a3, -0x2780
    ctx->r7 = ADD32(ctx->r7, -0X2780);
L_80069B3C:
    // 0x80069B3C: lbu         $v1, 0xCA($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0XCA);
    // 0x80069B40: beql        $v1, $zero, L_80069B8C
    if (ctx->r3 == 0) {
        // 0x80069B44: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_80069B8C;
    }
    goto skip_1;
    // 0x80069B44: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_1:
    // 0x80069B48: multu       $v0, $t0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80069B4C: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x80069B50: addiu       $t4, $t4, 0x79C8
    ctx->r12 = ADD32(ctx->r12, 0X79C8);
    // 0x80069B54: sll         $t3, $v0, 2
    ctx->r11 = S32(ctx->r2 << 2);
    // 0x80069B58: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    // 0x80069B5C: addiu       $t9, $v1, -0x1
    ctx->r25 = ADD32(ctx->r3, -0X1);
    // 0x80069B60: mflo        $t5
    ctx->r13 = lo;
    // 0x80069B64: addu        $t6, $a3, $t5
    ctx->r14 = ADD32(ctx->r7, ctx->r13);
    // 0x80069B68: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x80069B6C: andi        $t8, $t7, 0x8000
    ctx->r24 = ctx->r15 & 0X8000;
    // 0x80069B70: bnel        $t8, $zero, L_80069B88
    if (ctx->r24 != 0) {
        // 0x80069B74: sw          $zero, 0x0($a1)
        MEM_W(0X0, ctx->r5) = 0;
            goto L_80069B88;
    }
    goto skip_2;
    // 0x80069B74: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    skip_2:
    // 0x80069B78: sb          $t9, 0xCA($a0)
    MEM_B(0XCA, ctx->r4) = ctx->r25;
    // 0x80069B7C: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x80069B80: lw          $a2, 0x78A8($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X78A8);
    // 0x80069B84: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
L_80069B88:
    // 0x80069B88: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_80069B8C:
    // 0x80069B8C: slt         $at, $v0, $a2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x80069B90: bne         $at, $zero, L_80069B3C
    if (ctx->r1 != 0) {
        // 0x80069B94: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_80069B3C;
    }
    // 0x80069B94: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80069B98: b           L_80069BF0
    // 0x80069B9C: lhu         $v0, 0xC4($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XC4);
        goto L_80069BF0;
    // 0x80069B9C: lhu         $v0, 0xC4($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XC4);
    // 0x80069BA0: lbu         $v0, 0xCA($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0XCA);
L_80069BA4:
    // 0x80069BA4: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x80069BA8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80069BAC: beql        $v0, $zero, L_80069BF0
    if (ctx->r2 == 0) {
        // 0x80069BB0: lhu         $v0, 0xC4($s0)
        ctx->r2 = MEM_HU(ctx->r16, 0XC4);
            goto L_80069BF0;
    }
    goto skip_3;
    // 0x80069BB0: lhu         $v0, 0xC4($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XC4);
    skip_3:
    // 0x80069BB4: lw          $t1, 0x7AF8($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7AF8);
    // 0x80069BB8: addiu       $t0, $zero, 0x6
    ctx->r8 = ADD32(0, 0X6);
    // 0x80069BBC: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x80069BC0: multu       $t1, $t0
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80069BC4: addiu       $a3, $a3, -0x2780
    ctx->r7 = ADD32(ctx->r7, -0X2780);
    // 0x80069BC8: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80069BCC: mflo        $t2
    ctx->r10 = lo;
    // 0x80069BD0: addu        $t3, $a3, $t2
    ctx->r11 = ADD32(ctx->r7, ctx->r10);
    // 0x80069BD4: lhu         $t4, 0x0($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X0);
    // 0x80069BD8: andi        $t5, $t4, 0x8000
    ctx->r13 = ctx->r12 & 0X8000;
    // 0x80069BDC: bne         $t5, $zero, L_80069BE8
    if (ctx->r13 != 0) {
        // 0x80069BE0: nop
    
            goto L_80069BE8;
    }
    // 0x80069BE0: nop

    // 0x80069BE4: sb          $t6, 0xCA($s0)
    MEM_B(0XCA, ctx->r16) = ctx->r14;
L_80069BE8:
    // 0x80069BE8: sw          $zero, 0x79C8($at)
    MEM_W(0X79C8, ctx->r1) = 0;
L_80069BEC:
    // 0x80069BEC: lhu         $v0, 0xC4($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XC4);
L_80069BF0:
    // 0x80069BF0: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80069BF4: beq         $v0, $zero, L_80069C00
    if (ctx->r2 == 0) {
        // 0x80069BF8: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_80069C00;
    }
    // 0x80069BF8: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x80069BFC: sh          $t7, 0xC4($s0)
    MEM_H(0XC4, ctx->r16) = ctx->r15;
L_80069C00:
    // 0x80069C00: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x80069C04: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80069C08: beq         $v0, $at, L_80069C28
    if (ctx->r2 == ctx->r1) {
        // 0x80069C0C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80069C28;
    }
    // 0x80069C0C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80069C10: beq         $v0, $at, L_80069C58
    if (ctx->r2 == ctx->r1) {
        // 0x80069C14: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80069C58;
    }
    // 0x80069C14: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80069C18: beq         $v0, $at, L_80069C88
    if (ctx->r2 == ctx->r1) {
        // 0x80069C1C: nop
    
            goto L_80069C88;
    }
    // 0x80069C1C: nop

    // 0x80069C20: b           L_80069CAC
    // 0x80069C24: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80069CAC;
    // 0x80069C24: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80069C28:
    // 0x80069C28: sb          $t8, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r24;
    // 0x80069C2C: lw          $a0, 0x40($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X40);
    // 0x80069C30: jal         0x80063F90
    // 0x80069C34: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    Object_Init(rdram, ctx);
        goto after_0;
    // 0x80069C34: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    after_0:
    // 0x80069C38: lhu         $t9, 0x2($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X2);
    // 0x80069C3C: addiu       $at, $zero, 0xFC
    ctx->r1 = ADD32(0, 0XFC);
    // 0x80069C40: beql        $t9, $at, L_80069CAC
    if (ctx->r25 == ctx->r1) {
        // 0x80069C44: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80069CAC;
    }
    goto skip_4;
    // 0x80069C44: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x80069C48: jal         0x800693E8
    // 0x80069C4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Actor_Move(rdram, ctx);
        goto after_1;
    // 0x80069C4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80069C50: b           L_80069CAC
    // 0x80069C54: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80069CAC;
    // 0x80069C54: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80069C58:
    // 0x80069C58: jal         0x800693E8
    // 0x80069C5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Actor_Move(rdram, ctx);
        goto after_2;
    // 0x80069C5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80069C60: lbu         $t1, 0x0($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X0);
    // 0x80069C64: beql        $t1, $zero, L_80069CAC
    if (ctx->r9 == 0) {
        // 0x80069C68: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80069CAC;
    }
    goto skip_5;
    // 0x80069C68: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_5:
    // 0x80069C6C: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x80069C70: beql        $v0, $zero, L_80069CAC
    if (ctx->r2 == 0) {
        // 0x80069C74: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80069CAC;
    }
    goto skip_6;
    // 0x80069C74: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_6:
    // 0x80069C78: jalr        $v0
    // 0x80069C7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_3;
    // 0x80069C7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80069C80: b           L_80069CAC
    // 0x80069C84: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80069CAC;
    // 0x80069C84: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80069C88:
    // 0x80069C88: jal         0x800693E8
    // 0x80069C8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Actor_Move(rdram, ctx);
        goto after_4;
    // 0x80069C8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80069C90: lbu         $t2, 0x0($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X0);
    // 0x80069C94: beql        $t2, $zero, L_80069CAC
    if (ctx->r10 == 0) {
        // 0x80069C98: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80069CAC;
    }
    goto skip_7;
    // 0x80069C98: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_7:
    // 0x80069C9C: lw          $a0, 0x40($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X40);
    // 0x80069CA0: jal         0x800690D0
    // 0x80069CA4: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    Object_Dying(rdram, ctx);
        goto after_5;
    // 0x80069CA4: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    after_5:
    // 0x80069CA8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80069CAC:
    // 0x80069CAC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80069CB0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80069CB4: jr          $ra
    // 0x80069CB8: nop

    return;
    // 0x80069CB8: nop

;}
RECOMP_FUNC void Display_OnFootFox_PostLimbDraw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800523A8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800523AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800523B0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800523B4: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x800523B8: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x800523BC: bne         $a0, $at, L_80052410
    if (ctx->r4 != ctx->r1) {
        // 0x800523C0: addiu       $a1, $sp, 0x1C
        ctx->r5 = ADD32(ctx->r29, 0X1C);
            goto L_80052410;
    }
    // 0x800523C0: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x800523C4: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x800523C8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800523CC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800523D0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800523D4: lui         $at, 0xC1E0
    ctx->r1 = S32(0XC1E0 << 16);
    // 0x800523D8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800523DC: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x800523E0: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x800523E4: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    // 0x800523E8: lw          $t6, 0x1C4($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X1C4);
    // 0x800523EC: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x800523F0: addiu       $t8, $t8, 0x13B0
    ctx->r24 = ADD32(ctx->r24, 0X13B0);
    // 0x800523F4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800523F8: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800523FC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80052400: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80052404: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80052408: jal         0x80006970
    // 0x8005240C: addu        $a2, $t7, $t8
    ctx->r6 = ADD32(ctx->r15, ctx->r24);
    Matrix_MultVec3f(rdram, ctx);
        goto after_0;
    // 0x8005240C: addu        $a2, $t7, $t8
    ctx->r6 = ADD32(ctx->r15, ctx->r24);
    after_0:
L_80052410:
    // 0x80052410: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80052414: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80052418: jr          $ra
    // 0x8005241C: nop

    return;
    // 0x8005241C: nop

;}
RECOMP_FUNC void func_versus_800BC9DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BC9DC: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x800BC9E0: sdc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X30, ctx->r29);
    // 0x800BC9E4: sdc1        $f24, 0x40($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X40, ctx->r29);
    // 0x800BC9E8: sdc1        $f22, 0x38($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X38, ctx->r29);
    // 0x800BC9EC: mtc1        $a2, $f20
    ctx->f20.u32l = ctx->r6;
    // 0x800BC9F0: mov.s       $f22, $f12
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    ctx->f22.fl = ctx->f12.fl;
    // 0x800BC9F4: mov.s       $f24, $f14
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 14);
    ctx->f24.fl = ctx->f14.fl;
    // 0x800BC9F8: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x800BC9FC: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x800BCA00: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x800BCA04: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x800BCA08: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x800BCA0C: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x800BCA10: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x800BCA14: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x800BCA18: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x800BCA1C: addiu       $t7, $t7, 0x4AA4
    ctx->r15 = ADD32(ctx->r15, 0X4AA4);
    // 0x800BCA20: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x800BCA24: addiu       $t6, $sp, 0x9C
    ctx->r14 = ADD32(ctx->r29, 0X9C);
    // 0x800BCA28: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x800BCA2C: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x800BCA30: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x800BCA34: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x800BCA38: addiu       $t2, $t2, 0x4AB0
    ctx->r10 = ADD32(ctx->r10, 0X4AB0);
    // 0x800BCA3C: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x800BCA40: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x800BCA44: lw          $at, 0x0($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X0);
    // 0x800BCA48: addiu       $t1, $sp, 0x90
    ctx->r9 = ADD32(ctx->r29, 0X90);
    // 0x800BCA4C: lw          $t5, 0x4($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X4);
    // 0x800BCA50: sw          $at, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r1;
    // 0x800BCA54: lw          $at, 0x8($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X8);
    // 0x800BCA58: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x800BCA5C: addiu       $t8, $t8, 0x4ABC
    ctx->r24 = ADD32(ctx->r24, 0X4ABC);
    // 0x800BCA60: sw          $t5, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r13;
    // 0x800BCA64: sw          $at, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r1;
    // 0x800BCA68: lw          $at, 0x0($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X0);
    // 0x800BCA6C: addiu       $t9, $sp, 0x84
    ctx->r25 = ADD32(ctx->r29, 0X84);
    // 0x800BCA70: lw          $t0, 0x4($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X4);
    // 0x800BCA74: sw          $at, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r1;
    // 0x800BCA78: lw          $at, 0x8($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X8);
    // 0x800BCA7C: sll         $v0, $a3, 2
    ctx->r2 = S32(ctx->r7 << 2);
    // 0x800BCA80: addiu       $t1, $sp, 0x9C
    ctx->r9 = ADD32(ctx->r29, 0X9C);
    // 0x800BCA84: addiu       $t4, $sp, 0x84
    ctx->r12 = ADD32(ctx->r29, 0X84);
    // 0x800BCA88: addiu       $t3, $sp, 0x90
    ctx->r11 = ADD32(ctx->r29, 0X90);
    // 0x800BCA8C: lui         $s5, 0x8013
    ctx->r21 = S32(0X8013 << 16);
    // 0x800BCA90: addiu       $s5, $s5, 0x7E64
    ctx->r21 = ADD32(ctx->r21, 0X7E64);
    // 0x800BCA94: addu        $s3, $v0, $t3
    ctx->r19 = ADD32(ctx->r2, ctx->r11);
    // 0x800BCA98: addu        $s2, $v0, $t4
    ctx->r18 = ADD32(ctx->r2, ctx->r12);
    // 0x800BCA9C: addu        $s4, $v0, $t1
    ctx->r20 = ADD32(ctx->r2, ctx->r9);
    // 0x800BCAA0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800BCAA4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800BCAA8: addiu       $s6, $zero, 0x5
    ctx->r22 = ADD32(0, 0X5);
    // 0x800BCAAC: sw          $t0, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r8;
    // 0x800BCAB0: sw          $at, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r1;
L_800BCAB4:
    // 0x800BCAB4: mtc1        $s1, $f4
    ctx->f4.u32l = ctx->r17;
    // 0x800BCAB8: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800BCABC: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    // 0x800BCAC0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800BCAC4: sll         $t2, $v0, 3
    ctx->r10 = S32(ctx->r2 << 3);
    // 0x800BCAC8: multu       $t2, $s0
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BCACC: lw          $a2, 0x0($s4)
    ctx->r6 = MEM_W(ctx->r20, 0X0);
    // 0x800BCAD0: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x800BCAD4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800BCAD8: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x800BCADC: swc1        $f20, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f20.u32l;
    // 0x800BCAE0: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x800BCAE4: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    // 0x800BCAE8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800BCAEC: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x800BCAF0: mflo        $t5
    ctx->r13 = lo;
    // 0x800BCAF4: add.s       $f10, $f8, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f24.fl;
    // 0x800BCAF8: addu        $a1, $t5, $t7
    ctx->r5 = ADD32(ctx->r13, ctx->r15);
    // 0x800BCAFC: jal         0x8009D0BC
    // 0x800BCB00: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    Lib_TextureRect_CI8(rdram, ctx);
        goto after_0;
    // 0x800BCB00: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    after_0:
    // 0x800BCB04: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800BCB08: bne         $s0, $s6, L_800BCAB4
    if (ctx->r16 != ctx->r22) {
        // 0x800BCB0C: addiu       $s1, $s1, 0x8
        ctx->r17 = ADD32(ctx->r17, 0X8);
            goto L_800BCAB4;
    }
    // 0x800BCB0C: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x800BCB10: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x800BCB14: ldc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X30);
    // 0x800BCB18: ldc1        $f22, 0x38($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X38);
    // 0x800BCB1C: ldc1        $f24, 0x40($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X40);
    // 0x800BCB20: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x800BCB24: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x800BCB28: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x800BCB2C: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x800BCB30: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x800BCB34: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x800BCB38: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x800BCB3C: jr          $ra
    // 0x800BCB40: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    return;
    // 0x800BCB40: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
;}
RECOMP_FUNC void ActorTeamBoss_FlyAroundAllRange(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80090E8C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80090E90: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80090E94: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80090E98: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80090E9C: lhu         $t6, 0xBC($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0XBC);
    // 0x80090EA0: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x80090EA4: bnel        $t6, $zero, L_80091000
    if (ctx->r14 != 0) {
        // 0x80090EA8: lh          $t1, 0xE4($s0)
        ctx->r9 = MEM_H(ctx->r16, 0XE4);
            goto L_80091000;
    }
    goto skip_0;
    // 0x80090EA8: lh          $t1, 0xE4($s0)
    ctx->r9 = MEM_H(ctx->r16, 0XE4);
    skip_0:
    // 0x80090EAC: lbu         $t7, 0x7C98($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X7C98);
    // 0x80090EB0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80090EB4: bne         $t7, $at, L_80090F24
    if (ctx->r15 != ctx->r1) {
        // 0x80090EB8: nop
    
            goto L_80090F24;
    }
    // 0x80090EB8: nop

    // 0x80090EBC: jal         0x80004EB0
    // 0x80090EC0: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_0;
    // 0x80090EC0: nop

    after_0:
    // 0x80090EC4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80090EC8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80090ECC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80090ED0: lwc1        $f8, 0x7F28($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7F28);
    // 0x80090ED4: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x80090ED8: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80090EDC: jal         0x80004EB0
    // 0x80090EE0: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x80090EE0: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x80090EE4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80090EE8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80090EEC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80090EF0: lwc1        $f4, 0x7F2C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7F2C);
    // 0x80090EF4: sub.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x80090EF8: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80090EFC: jal         0x80004EB0
    // 0x80090F00: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_2;
    // 0x80090F00: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x80090F04: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80090F08: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80090F0C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80090F10: lwc1        $f16, 0x7F30($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7F30);
    // 0x80090F14: sub.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x80090F18: mul.s       $f2, $f10, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80090F1C: b           L_80090F84
    // 0x80090F20: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
        goto L_80090F84;
    // 0x80090F20: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
L_80090F24:
    // 0x80090F24: jal         0x80004EB0
    // 0x80090F28: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_3;
    // 0x80090F28: nop

    after_3:
    // 0x80090F2C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80090F30: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80090F34: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80090F38: lwc1        $f6, 0x7F34($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7F34);
    // 0x80090F3C: sub.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x80090F40: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80090F44: jal         0x80004EB0
    // 0x80090F48: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_4;
    // 0x80090F48: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    after_4:
    // 0x80090F4C: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80090F50: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80090F54: nop

    // 0x80090F58: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80090F5C: jal         0x80004EB0
    // 0x80090F60: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_5;
    // 0x80090F60: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    after_5:
    // 0x80090F64: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80090F68: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80090F6C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80090F70: lwc1        $f6, 0x7F38($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7F38);
    // 0x80090F74: sub.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x80090F78: mul.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80090F7C: nop

    // 0x80090F80: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
L_80090F84:
    // 0x80090F84: lwc1        $f10, 0x24($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80090F88: lui         $at, 0x44FA
    ctx->r1 = S32(0X44FA << 16);
    // 0x80090F8C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80090F90: sub.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80090F94: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80090F98: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x80090F9C: nop

    // 0x80090FA0: bc1fl       L_80091000
    if (!c1cs) {
        // 0x80090FA4: lh          $t1, 0xE4($s0)
        ctx->r9 = MEM_H(ctx->r16, 0XE4);
            goto L_80091000;
    }
    goto skip_1;
    // 0x80090FA4: lh          $t1, 0xE4($s0)
    ctx->r9 = MEM_H(ctx->r16, 0XE4);
    skip_1:
    // 0x80090FA8: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80090FAC: sub.s       $f0, $f16, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f2.fl;
    // 0x80090FB0: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80090FB4: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x80090FB8: nop

    // 0x80090FBC: bc1fl       L_80091000
    if (!c1cs) {
        // 0x80090FC0: lh          $t1, 0xE4($s0)
        ctx->r9 = MEM_H(ctx->r16, 0XE4);
            goto L_80091000;
    }
    goto skip_2;
    // 0x80090FC0: lh          $t1, 0xE4($s0)
    ctx->r9 = MEM_H(ctx->r16, 0XE4);
    skip_2:
    // 0x80090FC4: swc1        $f10, 0x124($s0)
    MEM_W(0X124, ctx->r16) = ctx->f10.u32l;
    // 0x80090FC8: lwc1        $f18, 0x20($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80090FCC: swc1        $f2, 0x12C($s0)
    MEM_W(0X12C, ctx->r16) = ctx->f2.u32l;
    // 0x80090FD0: jal         0x80004EB0
    // 0x80090FD4: swc1        $f18, 0x128($s0)
    MEM_W(0X128, ctx->r16) = ctx->f18.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_6;
    // 0x80090FD4: swc1        $f18, 0x128($s0)
    MEM_W(0X128, ctx->r16) = ctx->f18.u32l;
    after_6:
    // 0x80090FD8: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80090FDC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80090FE0: nop

    // 0x80090FE4: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80090FE8: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80090FEC: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x80090FF0: nop

    // 0x80090FF4: addiu       $t0, $t9, 0xA
    ctx->r8 = ADD32(ctx->r25, 0XA);
    // 0x80090FF8: sh          $t0, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r8;
    // 0x80090FFC: lh          $t1, 0xE4($s0)
    ctx->r9 = MEM_H(ctx->r16, 0XE4);
L_80091000:
    // 0x80091000: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80091004: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80091008: bne         $t1, $at, L_8009101C
    if (ctx->r9 != ctx->r1) {
        // 0x8009100C: lui         $v0, 0x8017
        ctx->r2 = S32(0X8017 << 16);
            goto L_8009101C;
    }
    // 0x8009100C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80091010: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80091014: b           L_80091024
    // 0x80091018: lwc1        $f2, 0x7F3C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X7F3C);
        goto L_80091024;
    // 0x80091018: lwc1        $f2, 0x7F3C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X7F3C);
L_8009101C:
    // 0x8009101C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80091020: lwc1        $f2, 0x7F40($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X7F40);
L_80091024:
    // 0x80091024: addiu       $v0, $v0, -0xEF0
    ctx->r2 = ADD32(ctx->r2, -0XEF0);
    // 0x80091028: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8009102C: sub.s       $f0, $f12, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f16.fl;
    // 0x80091030: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80091034: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80091038: nop

    // 0x8009103C: bc1fl       L_8009106C
    if (!c1cs) {
        // 0x80091040: lhu         $t2, 0xBE($s0)
        ctx->r10 = MEM_HU(ctx->r16, 0XBE);
            goto L_8009106C;
    }
    goto skip_3;
    // 0x80091040: lhu         $t2, 0xBE($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0XBE);
    skip_3:
    // 0x80091044: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80091048: lwc1        $f18, 0xC($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8009104C: sub.s       $f0, $f10, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x80091050: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80091054: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80091058: nop

    // 0x8009105C: bc1fl       L_8009106C
    if (!c1cs) {
        // 0x80091060: lhu         $t2, 0xBE($s0)
        ctx->r10 = MEM_HU(ctx->r16, 0XBE);
            goto L_8009106C;
    }
    goto skip_4;
    // 0x80091060: lhu         $t2, 0xBE($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0XBE);
    skip_4:
    // 0x80091064: sh          $zero, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = 0;
    // 0x80091068: lhu         $t2, 0xBE($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0XBE);
L_8009106C:
    // 0x8009106C: bnel        $t2, $zero, L_800910AC
    if (ctx->r10 != 0) {
        // 0x80091070: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800910AC;
    }
    goto skip_5;
    // 0x80091070: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_5:
    // 0x80091074: jal         0x80004EB0
    // 0x80091078: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_7;
    // 0x80091078: nop

    after_7:
    // 0x8009107C: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80091080: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80091084: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80091088: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8009108C: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80091090: swc1        $f16, 0x13C($s0)
    MEM_W(0X13C, ctx->r16) = ctx->f16.u32l;
    // 0x80091094: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80091098: mfc1        $t4, $f8
    ctx->r12 = (int32_t)ctx->f8.u32l;
    // 0x8009109C: nop

    // 0x800910A0: addiu       $t5, $t4, 0xC8
    ctx->r13 = ADD32(ctx->r12, 0XC8);
    // 0x800910A4: sh          $t5, 0xBE($s0)
    MEM_H(0XBE, ctx->r16) = ctx->r13;
    // 0x800910A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800910AC:
    // 0x800910AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800910B0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800910B4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800910B8: jr          $ra
    // 0x800910BC: nop

    return;
    // 0x800910BC: nop

;}
RECOMP_FUNC void Play_InitLevel(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AB334: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800AB338: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AB33C: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x800AB340: lw          $v1, -0x7DCC($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7DCC);
    // 0x800AB344: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x800AB348: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800AB34C: beq         $v1, $at, L_800AB39C
    if (ctx->r3 == ctx->r1) {
        // 0x800AB350: addiu       $at, $zero, 0x9
        ctx->r1 = ADD32(0, 0X9);
            goto L_800AB39C;
    }
    // 0x800AB350: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x800AB354: beq         $v1, $at, L_800AB3C4
    if (ctx->r3 == ctx->r1) {
        // 0x800AB358: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_800AB3C4;
    }
    // 0x800AB358: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800AB35C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800AB360: beq         $v1, $at, L_800AB37C
    if (ctx->r3 == ctx->r1) {
        // 0x800AB364: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_800AB37C;
    }
    // 0x800AB364: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800AB368: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x800AB36C: beq         $v1, $at, L_800AB3B0
    if (ctx->r3 == ctx->r1) {
        // 0x800AB370: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_800AB3B0;
    }
    // 0x800AB370: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800AB374: b           L_800AB3E8
    // 0x800AB378: nop

        goto L_800AB3E8;
    // 0x800AB378: nop

L_800AB37C:
    // 0x800AB37C: jal         0x8001DC6C
    // 0x800AB380: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    Audio_SetAudioSpec(rdram, ctx);
        goto after_0;
    // 0x800AB380: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    after_0:
    // 0x800AB384: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x800AB388: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800AB38C: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x800AB390: sw          $t6, 0x796C($at)
    MEM_W(0X796C, ctx->r1) = ctx->r14;
    // 0x800AB394: b           L_800AB3E8
    // 0x800AB398: lw          $v1, -0x7DCC($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7DCC);
        goto L_800AB3E8;
    // 0x800AB398: lw          $v1, -0x7DCC($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7DCC);
L_800AB39C:
    // 0x800AB39C: jal         0x8001DC6C
    // 0x800AB3A0: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    Audio_SetAudioSpec(rdram, ctx);
        goto after_1;
    // 0x800AB3A0: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_1:
    // 0x800AB3A4: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x800AB3A8: b           L_800AB3E8
    // 0x800AB3AC: lw          $v1, -0x7DCC($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7DCC);
        goto L_800AB3E8;
    // 0x800AB3AC: lw          $v1, -0x7DCC($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7DCC);
L_800AB3B0:
    // 0x800AB3B0: jal         0x8001DC6C
    // 0x800AB3B4: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    Audio_SetAudioSpec(rdram, ctx);
        goto after_2;
    // 0x800AB3B4: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_2:
    // 0x800AB3B8: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x800AB3BC: b           L_800AB3E8
    // 0x800AB3C0: lw          $v1, -0x7DCC($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7DCC);
        goto L_800AB3E8;
    // 0x800AB3C0: lw          $v1, -0x7DCC($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7DCC);
L_800AB3C4:
    // 0x800AB3C4: jal         0x8001DC6C
    // 0x800AB3C8: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    Audio_SetAudioSpec(rdram, ctx);
        goto after_3;
    // 0x800AB3C8: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_3:
    // 0x800AB3CC: jal         0x8001D400
    // 0x800AB3D0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    Audio_SetEnvSfxReverb(rdram, ctx);
        goto after_4;
    // 0x800AB3D0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x800AB3D4: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x800AB3D8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800AB3DC: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x800AB3E0: sw          $t7, 0x796C($at)
    MEM_W(0X796C, ctx->r1) = ctx->r15;
    // 0x800AB3E4: lw          $v1, -0x7DCC($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7DCC);
L_800AB3E8:
    // 0x800AB3E8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AB3EC: sw          $zero, -0x7D6C($at)
    MEM_W(-0X7D6C, ctx->r1) = 0;
    // 0x800AB3F0: addiu       $t8, $v1, -0x1
    ctx->r24 = ADD32(ctx->r3, -0X1);
    // 0x800AB3F4: sltiu       $at, $t8, 0x12
    ctx->r1 = ctx->r24 < 0X12 ? 1 : 0;
    // 0x800AB3F8: beq         $at, $zero, L_800AB954
    if (ctx->r1 == 0) {
        // 0x800AB3FC: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_800AB954;
    }
    // 0x800AB3FC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800AB400: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AB404: addu        $at, $at, $t8
    gpr jr_addend_800AB40C = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x800AB408: lw          $t8, -0x7A64($at)
    ctx->r24 = ADD32(ctx->r1, -0X7A64);
    // 0x800AB40C: jr          $t8
    // 0x800AB410: nop

    switch (jr_addend_800AB40C >> 2) {
        case 0: goto L_800AB424; break;
        case 1: goto L_800AB424; break;
        case 2: goto L_800AB954; break;
        case 3: goto L_800AB954; break;
        case 4: goto L_800AB954; break;
        case 5: goto L_800AB954; break;
        case 6: goto L_800AB5A4; break;
        case 7: goto L_800AB560; break;
        case 8: goto L_800AB49C; break;
        case 9: goto L_800AB954; break;
        case 10: goto L_800AB550; break;
        case 11: goto L_800AB538; break;
        case 12: goto L_800AB500; break;
        case 13: goto L_800AB954; break;
        case 14: goto L_800AB954; break;
        case 15: goto L_800AB954; break;
        case 16: goto L_800AB954; break;
        case 17: goto L_800AB414; break;
        default: switch_error(__func__, 0x800AB40C, 0x800D859C);
    }
    // 0x800AB410: nop

L_800AB414:
    // 0x800AB414: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800AB418: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800AB41C: b           L_800AB954
    // 0x800AB420: sb          $t9, 0x7B8C($at)
    MEM_B(0X7B8C, ctx->r1) = ctx->r25;
        goto L_800AB954;
    // 0x800AB420: sb          $t9, 0x7B8C($at)
    MEM_B(0X7B8C, ctx->r1) = ctx->r25;
L_800AB424:
    // 0x800AB424: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800AB428: lw          $t5, -0x7D84($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X7D84);
    // 0x800AB42C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800AB430: addiu       $v0, $zero, 0xC8
    ctx->r2 = ADD32(0, 0XC8);
    // 0x800AB434: bne         $t5, $at, L_800AB954
    if (ctx->r13 != ctx->r1) {
        // 0x800AB438: addiu       $t6, $zero, 0xB2
        ctx->r14 = ADD32(0, 0XB2);
            goto L_800AB954;
    }
    // 0x800AB438: addiu       $t6, $zero, 0xB2
    ctx->r14 = ADD32(0, 0XB2);
    // 0x800AB43C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AB440: sw          $t6, -0x7CE0($at)
    MEM_W(-0X7CE0, ctx->r1) = ctx->r14;
    // 0x800AB444: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AB448: addiu       $t7, $zero, 0xBE
    ctx->r15 = ADD32(0, 0XBE);
    // 0x800AB44C: sw          $t7, -0x7CD8($at)
    MEM_W(-0X7CD8, ctx->r1) = ctx->r15;
    // 0x800AB450: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AB454: addiu       $t8, $zero, 0x5A
    ctx->r24 = ADD32(0, 0X5A);
    // 0x800AB458: sw          $t8, -0x7CD0($at)
    MEM_W(-0X7CD0, ctx->r1) = ctx->r24;
    // 0x800AB45C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AB460: sw          $v0, -0x7AB8($at)
    MEM_W(-0X7AB8, ctx->r1) = ctx->r2;
    // 0x800AB464: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AB468: sw          $v0, -0x7AB4($at)
    MEM_W(-0X7AB4, ctx->r1) = ctx->r2;
    // 0x800AB46C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AB470: addiu       $t9, $zero, 0x78
    ctx->r25 = ADD32(0, 0X78);
    // 0x800AB474: sw          $t9, -0x7AB0($at)
    MEM_W(-0X7AB0, ctx->r1) = ctx->r25;
    // 0x800AB478: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AB47C: sw          $zero, -0x7AAC($at)
    MEM_W(-0X7AAC, ctx->r1) = 0;
    // 0x800AB480: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AB484: addiu       $t5, $zero, 0x32
    ctx->r13 = ADD32(0, 0X32);
    // 0x800AB488: sw          $t5, -0x7AA8($at)
    MEM_W(-0X7AA8, ctx->r1) = ctx->r13;
    // 0x800AB48C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AB490: addiu       $t6, $zero, 0x64
    ctx->r14 = ADD32(0, 0X64);
    // 0x800AB494: b           L_800AB954
    // 0x800AB498: sw          $t6, -0x7AA4($at)
    MEM_W(-0X7AA4, ctx->r1) = ctx->r14;
        goto L_800AB954;
    // 0x800AB498: sw          $t6, -0x7AA4($at)
    MEM_W(-0X7AA4, ctx->r1) = ctx->r14;
L_800AB49C:
    // 0x800AB49C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800AB4A0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800AB4A4: sb          $zero, 0x7A98($at)
    MEM_B(0X7A98, ctx->r1) = 0;
    // 0x800AB4A8: lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // 0x800AB4AC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800AB4B0: addiu       $t7, $zero, 0x6
    ctx->r15 = ADD32(0, 0X6);
    // 0x800AB4B4: addiu       $v0, $v0, 0x7F78
    ctx->r2 = ADD32(ctx->r2, 0X7F78);
    // 0x800AB4B8: sb          $t7, 0x7AB0($at)
    MEM_B(0X7AB0, ctx->r1) = ctx->r15;
    // 0x800AB4BC: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x800AB4C0: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800AB4C4: lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // 0x800AB4C8: addiu       $v1, $v1, 0x7F70
    ctx->r3 = ADD32(ctx->r3, 0X7F70);
    // 0x800AB4CC: swc1        $f4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f4.u32l;
    // 0x800AB4D0: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800AB4D4: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x800AB4D8: addiu       $a0, $a0, 0x7F68
    ctx->r4 = ADD32(ctx->r4, 0X7F68);
    // 0x800AB4DC: swc1        $f6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f6.u32l;
    // 0x800AB4E0: lwc1        $f8, 0x0($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800AB4E4: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x800AB4E8: addiu       $a1, $a1, 0x7F60
    ctx->r5 = ADD32(ctx->r5, 0X7F60);
    // 0x800AB4EC: swc1        $f8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f8.u32l;
    // 0x800AB4F0: lwc1        $f10, 0x0($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800AB4F4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800AB4F8: b           L_800AB954
    // 0x800AB4FC: swc1        $f10, 0x7F58($at)
    MEM_W(0X7F58, ctx->r1) = ctx->f10.u32l;
        goto L_800AB954;
    // 0x800AB4FC: swc1        $f10, 0x7F58($at)
    MEM_W(0X7F58, ctx->r1) = ctx->f10.u32l;
L_800AB500:
    // 0x800AB500: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x800AB504: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800AB508: sb          $t8, 0x7E78($at)
    MEM_B(0X7E78, ctx->r1) = ctx->r24;
    // 0x800AB50C: lui         $at, 0x44C8
    ctx->r1 = S32(0X44C8 << 16);
    // 0x800AB510: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800AB514: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800AB518: swc1        $f16, -0x690($at)
    MEM_W(-0X690, ctx->r1) = ctx->f16.u32l;
    // 0x800AB51C: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x800AB520: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800AB524: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x800AB528: jal         0x801A9824
    // 0x800AB52C: swc1        $f18, 0x4188($at)
    MEM_W(0X4188, ctx->r1) = ctx->f18.u32l;
    Aquas_InitLevel(rdram, ctx);
        goto after_5;
    // 0x800AB52C: swc1        $f18, 0x4188($at)
    MEM_W(0X4188, ctx->r1) = ctx->f18.u32l;
    after_5:
    // 0x800AB530: b           L_800AB958
    // 0x800AB534: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800AB958;
    // 0x800AB534: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800AB538:
    // 0x800AB538: jal         0x80188F30
    // 0x800AB53C: nop

    Titania_80188F30(rdram, ctx);
        goto after_6;
    // 0x800AB53C: nop

    after_6:
    // 0x800AB540: addiu       $t9, $zero, -0x2
    ctx->r25 = ADD32(0, -0X2);
    // 0x800AB544: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800AB548: b           L_800AB954
    // 0x800AB54C: sw          $t9, 0x78B8($at)
    MEM_W(0X78B8, ctx->r1) = ctx->r25;
        goto L_800AB954;
    // 0x800AB54C: sw          $t9, 0x78B8($at)
    MEM_W(0X78B8, ctx->r1) = ctx->r25;
L_800AB550:
    // 0x800AB550: jal         0x80199920
    // 0x800AB554: nop

    Macbeth_InitLevel(rdram, ctx);
        goto after_7;
    // 0x800AB554: nop

    after_7:
    // 0x800AB558: b           L_800AB958
    // 0x800AB55C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800AB958;
    // 0x800AB55C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800AB560:
    // 0x800AB560: jal         0x80006F38
    // 0x800AB564: addiu       $a0, $zero, 0x12C0
    ctx->r4 = ADD32(0, 0X12C0);
    Memory_Allocate(rdram, ctx);
        goto after_8;
    // 0x800AB564: addiu       $a0, $zero, 0x12C0
    ctx->r4 = ADD32(0, 0X12C0);
    after_8:
    // 0x800AB568: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800AB56C: addiu       $a1, $a1, -0x7D3C
    ctx->r5 = ADD32(ctx->r5, -0X7D3C);
    // 0x800AB570: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x800AB574: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800AB578: addiu       $v0, $zero, 0x12C0
    ctx->r2 = ADD32(0, 0X12C0);
    // 0x800AB57C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_800AB580:
    // 0x800AB580: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800AB584: sb          $zero, 0x1($v1)
    MEM_B(0X1, ctx->r3) = 0;
    // 0x800AB588: sb          $zero, 0x2($v1)
    MEM_B(0X2, ctx->r3) = 0;
    // 0x800AB58C: sb          $zero, 0x3($v1)
    MEM_B(0X3, ctx->r3) = 0;
    // 0x800AB590: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800AB594: bne         $a0, $v0, L_800AB580
    if (ctx->r4 != ctx->r2) {
        // 0x800AB598: sb          $zero, -0x4($v1)
        MEM_B(-0X4, ctx->r3) = 0;
            goto L_800AB580;
    }
    // 0x800AB598: sb          $zero, -0x4($v1)
    MEM_B(-0X4, ctx->r3) = 0;
    // 0x800AB59C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AB5A0: sw          $zero, -0x7B5C($at)
    MEM_W(-0X7B5C, ctx->r1) = 0;
L_800AB5A4:
    // 0x800AB5A4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800AB5A8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AB5AC: sw          $t5, -0x7D6C($at)
    MEM_W(-0X7D6C, ctx->r1) = ctx->r13;
    // 0x800AB5B0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AB5B4: lwc1        $f4, -0x7A1C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7A1C);
    // 0x800AB5B8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800AB5BC: addiu       $a0, $zero, 0x484
    ctx->r4 = ADD32(0, 0X484);
    // 0x800AB5C0: jal         0x80006F38
    // 0x800AB5C4: swc1        $f4, 0x7940($at)
    MEM_W(0X7940, ctx->r1) = ctx->f4.u32l;
    Memory_Allocate(rdram, ctx);
        goto after_9;
    // 0x800AB5C4: swc1        $f4, 0x7940($at)
    MEM_W(0X7940, ctx->r1) = ctx->f4.u32l;
    after_9:
    // 0x800AB5C8: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800AB5CC: addiu       $a1, $a1, -0x7D34
    ctx->r5 = ADD32(ctx->r5, -0X7D34);
    // 0x800AB5D0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800AB5D4: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x800AB5D8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800AB5DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_800AB5E0:
    // 0x800AB5E0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800AB5E4: slti        $at, $a0, 0x121
    ctx->r1 = SIGNED(ctx->r4) < 0X121 ? 1 : 0;
    // 0x800AB5E8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800AB5EC: bne         $at, $zero, L_800AB5E0
    if (ctx->r1 != 0) {
        // 0x800AB5F0: swc1        $f0, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->f0.u32l;
            goto L_800AB5E0;
    }
    // 0x800AB5F0: swc1        $f0, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f0.u32l;
    // 0x800AB5F4: jal         0x80006F38
    // 0x800AB5F8: addiu       $a0, $zero, 0x484
    ctx->r4 = ADD32(0, 0X484);
    Memory_Allocate(rdram, ctx);
        goto after_10;
    // 0x800AB5F8: addiu       $a0, $zero, 0x484
    ctx->r4 = ADD32(0, 0X484);
    after_10:
    // 0x800AB5FC: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800AB600: addiu       $a1, $a1, -0x7D2C
    ctx->r5 = ADD32(ctx->r5, -0X7D2C);
    // 0x800AB604: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800AB608: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x800AB60C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800AB610: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_800AB614:
    // 0x800AB614: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800AB618: slti        $at, $a0, 0x121
    ctx->r1 = SIGNED(ctx->r4) < 0X121 ? 1 : 0;
    // 0x800AB61C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800AB620: bne         $at, $zero, L_800AB614
    if (ctx->r1 != 0) {
        // 0x800AB624: swc1        $f0, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->f0.u32l;
            goto L_800AB614;
    }
    // 0x800AB624: swc1        $f0, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f0.u32l;
    // 0x800AB628: jal         0x80006F38
    // 0x800AB62C: addiu       $a0, $zero, 0x484
    ctx->r4 = ADD32(0, 0X484);
    Memory_Allocate(rdram, ctx);
        goto after_11;
    // 0x800AB62C: addiu       $a0, $zero, 0x484
    ctx->r4 = ADD32(0, 0X484);
    after_11:
    // 0x800AB630: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800AB634: addiu       $a1, $a1, -0x7D24
    ctx->r5 = ADD32(ctx->r5, -0X7D24);
    // 0x800AB638: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800AB63C: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x800AB640: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800AB644: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_800AB648:
    // 0x800AB648: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800AB64C: slti        $at, $a0, 0x121
    ctx->r1 = SIGNED(ctx->r4) < 0X121 ? 1 : 0;
    // 0x800AB650: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800AB654: bne         $at, $zero, L_800AB648
    if (ctx->r1 != 0) {
        // 0x800AB658: swc1        $f0, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->f0.u32l;
            goto L_800AB648;
    }
    // 0x800AB658: swc1        $f0, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f0.u32l;
    // 0x800AB65C: jal         0x80006F38
    // 0x800AB660: addiu       $a0, $zero, 0x484
    ctx->r4 = ADD32(0, 0X484);
    Memory_Allocate(rdram, ctx);
        goto after_12;
    // 0x800AB660: addiu       $a0, $zero, 0x484
    ctx->r4 = ADD32(0, 0X484);
    after_12:
    // 0x800AB664: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800AB668: addiu       $a1, $a1, -0x7D1C
    ctx->r5 = ADD32(ctx->r5, -0X7D1C);
    // 0x800AB66C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800AB670: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x800AB674: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800AB678: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_800AB67C:
    // 0x800AB67C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800AB680: slti        $at, $a0, 0x121
    ctx->r1 = SIGNED(ctx->r4) < 0X121 ? 1 : 0;
    // 0x800AB684: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800AB688: bne         $at, $zero, L_800AB67C
    if (ctx->r1 != 0) {
        // 0x800AB68C: swc1        $f0, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->f0.u32l;
            goto L_800AB67C;
    }
    // 0x800AB68C: swc1        $f0, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f0.u32l;
    // 0x800AB690: jal         0x80006F38
    // 0x800AB694: addiu       $a0, $zero, 0x484
    ctx->r4 = ADD32(0, 0X484);
    Memory_Allocate(rdram, ctx);
        goto after_13;
    // 0x800AB694: addiu       $a0, $zero, 0x484
    ctx->r4 = ADD32(0, 0X484);
    after_13:
    // 0x800AB698: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800AB69C: addiu       $a1, $a1, -0x7D14
    ctx->r5 = ADD32(ctx->r5, -0X7D14);
    // 0x800AB6A0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800AB6A4: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x800AB6A8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800AB6AC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_800AB6B0:
    // 0x800AB6B0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800AB6B4: slti        $at, $a0, 0x121
    ctx->r1 = SIGNED(ctx->r4) < 0X121 ? 1 : 0;
    // 0x800AB6B8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800AB6BC: bne         $at, $zero, L_800AB6B0
    if (ctx->r1 != 0) {
        // 0x800AB6C0: swc1        $f0, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->f0.u32l;
            goto L_800AB6B0;
    }
    // 0x800AB6C0: swc1        $f0, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f0.u32l;
    // 0x800AB6C4: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800AB6C8: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
    // 0x800AB6CC: addiu       $t1, $zero, 0x7
    ctx->r9 = ADD32(0, 0X7);
    // 0x800AB6D0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800AB6D4: beq         $v0, $t1, L_800AB704
    if (ctx->r2 == ctx->r9) {
        // 0x800AB6D8: addiu       $t0, $zero, 0x578
        ctx->r8 = ADD32(0, 0X578);
            goto L_800AB704;
    }
    // 0x800AB6D8: addiu       $t0, $zero, 0x578
    ctx->r8 = ADD32(0, 0X578);
    // 0x800AB6DC: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x800AB6E0: beq         $v0, $at, L_800AB744
    if (ctx->r2 == ctx->r1) {
        // 0x800AB6E4: lui         $t2, 0x800E
        ctx->r10 = S32(0X800E << 16);
            goto L_800AB744;
    }
    // 0x800AB6E4: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800AB6E8: lui         $t3, 0xFF
    ctx->r11 = S32(0XFF << 16);
    // 0x800AB6EC: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800AB6F0: addiu       $t2, $t2, 0x1FD0
    ctx->r10 = ADD32(ctx->r10, 0X1FD0);
    // 0x800AB6F4: ori         $t3, $t3, 0xFFFF
    ctx->r11 = ctx->r11 | 0XFFFF;
    // 0x800AB6F8: lui         $t4, 0x8000
    ctx->r12 = S32(0X8000 << 16);
    // 0x800AB6FC: b           L_800AB77C
    // 0x800AB700: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
        goto L_800AB77C;
    // 0x800AB700: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
L_800AB704:
    // 0x800AB704: lui         $v0, 0x600
    ctx->r2 = S32(0X600 << 16);
    // 0x800AB708: addiu       $v0, $v0, 0x1C50
    ctx->r2 = ADD32(ctx->r2, 0X1C50);
    // 0x800AB70C: sll         $t6, $v0, 4
    ctx->r14 = S32(ctx->r2 << 4);
    // 0x800AB710: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800AB714: srl         $t7, $t6, 28
    ctx->r15 = S32(U32(ctx->r14) >> 28);
    // 0x800AB718: addiu       $t2, $t2, 0x1FD0
    ctx->r10 = ADD32(ctx->r10, 0X1FD0);
    // 0x800AB71C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800AB720: addu        $t9, $t2, $t8
    ctx->r25 = ADD32(ctx->r10, ctx->r24);
    // 0x800AB724: lw          $t5, 0x0($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X0);
    // 0x800AB728: lui         $t3, 0xFF
    ctx->r11 = S32(0XFF << 16);
    // 0x800AB72C: ori         $t3, $t3, 0xFFFF
    ctx->r11 = ctx->r11 | 0XFFFF;
    // 0x800AB730: and         $t6, $v0, $t3
    ctx->r14 = ctx->r2 & ctx->r11;
    // 0x800AB734: lui         $t4, 0x8000
    ctx->r12 = S32(0X8000 << 16);
    // 0x800AB738: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x800AB73C: b           L_800AB77C
    // 0x800AB740: addu        $v1, $t7, $t4
    ctx->r3 = ADD32(ctx->r15, ctx->r12);
        goto L_800AB77C;
    // 0x800AB740: addu        $v1, $t7, $t4
    ctx->r3 = ADD32(ctx->r15, ctx->r12);
L_800AB744:
    // 0x800AB744: lui         $v0, 0x601
    ctx->r2 = S32(0X601 << 16);
    // 0x800AB748: addiu       $v0, $v0, -0x6130
    ctx->r2 = ADD32(ctx->r2, -0X6130);
    // 0x800AB74C: sll         $t8, $v0, 4
    ctx->r24 = S32(ctx->r2 << 4);
    // 0x800AB750: srl         $t9, $t8, 28
    ctx->r25 = S32(U32(ctx->r24) >> 28);
    // 0x800AB754: addiu       $t2, $t2, 0x1FD0
    ctx->r10 = ADD32(ctx->r10, 0X1FD0);
    // 0x800AB758: sll         $t5, $t9, 2
    ctx->r13 = S32(ctx->r25 << 2);
    // 0x800AB75C: addu        $t6, $t2, $t5
    ctx->r14 = ADD32(ctx->r10, ctx->r13);
    // 0x800AB760: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800AB764: lui         $t3, 0xFF
    ctx->r11 = S32(0XFF << 16);
    // 0x800AB768: ori         $t3, $t3, 0xFFFF
    ctx->r11 = ctx->r11 | 0XFFFF;
    // 0x800AB76C: and         $t8, $v0, $t3
    ctx->r24 = ctx->r2 & ctx->r11;
    // 0x800AB770: lui         $t4, 0x8000
    ctx->r12 = S32(0X8000 << 16);
    // 0x800AB774: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800AB778: addu        $v1, $t9, $t4
    ctx->r3 = ADD32(ctx->r25, ctx->r12);
L_800AB77C:
    // 0x800AB77C: addiu       $a3, $zero, 0x320
    ctx->r7 = ADD32(0, 0X320);
    // 0x800AB780: addiu       $a2, $zero, -0x578
    ctx->r6 = ADD32(0, -0X578);
    // 0x800AB784: addiu       $a1, $zero, -0x320
    ctx->r5 = ADD32(0, -0X320);
L_800AB788:
    // 0x800AB788: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x800AB78C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800AB790: slti        $at, $a0, 0x121
    ctx->r1 = SIGNED(ctx->r4) < 0X121 ? 1 : 0;
    // 0x800AB794: bne         $a3, $v0, L_800AB7A4
    if (ctx->r7 != ctx->r2) {
        // 0x800AB798: nop
    
            goto L_800AB7A4;
    }
    // 0x800AB798: nop

    // 0x800AB79C: sh          $t0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r8;
    // 0x800AB7A0: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
L_800AB7A4:
    // 0x800AB7A4: bnel        $a1, $v0, L_800AB7B4
    if (ctx->r5 != ctx->r2) {
        // 0x800AB7A8: lh          $t5, 0x4($v1)
        ctx->r13 = MEM_H(ctx->r3, 0X4);
            goto L_800AB7B4;
    }
    goto skip_0;
    // 0x800AB7A8: lh          $t5, 0x4($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X4);
    skip_0:
    // 0x800AB7AC: sh          $a2, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r6;
    // 0x800AB7B0: lh          $t5, 0x4($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X4);
L_800AB7B4:
    // 0x800AB7B4: bne         $a1, $t5, L_800AB7C0
    if (ctx->r5 != ctx->r13) {
        // 0x800AB7B8: nop
    
            goto L_800AB7C0;
    }
    // 0x800AB7B8: nop

    // 0x800AB7BC: sh          $a2, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r6;
L_800AB7C0:
    // 0x800AB7C0: bne         $at, $zero, L_800AB788
    if (ctx->r1 != 0) {
        // 0x800AB7C4: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_800AB788;
    }
    // 0x800AB7C4: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800AB7C8: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800AB7CC: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
    // 0x800AB7D0: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x800AB7D4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800AB7D8: beq         $v0, $t1, L_800AB7F0
    if (ctx->r2 == ctx->r9) {
        // 0x800AB7DC: nop
    
            goto L_800AB7F0;
    }
    // 0x800AB7DC: nop

    // 0x800AB7E0: beq         $v0, $at, L_800AB81C
    if (ctx->r2 == ctx->r1) {
        // 0x800AB7E4: nop
    
            goto L_800AB81C;
    }
    // 0x800AB7E4: nop

    // 0x800AB7E8: b           L_800AB848
    // 0x800AB7EC: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
        goto L_800AB848;
    // 0x800AB7EC: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
L_800AB7F0:
    // 0x800AB7F0: lui         $v0, 0x600
    ctx->r2 = S32(0X600 << 16);
    // 0x800AB7F4: addiu       $v0, $v0, 0x4500
    ctx->r2 = ADD32(ctx->r2, 0X4500);
    // 0x800AB7F8: sll         $t6, $v0, 4
    ctx->r14 = S32(ctx->r2 << 4);
    // 0x800AB7FC: srl         $t7, $t6, 28
    ctx->r15 = S32(U32(ctx->r14) >> 28);
    // 0x800AB800: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800AB804: addu        $t9, $t2, $t8
    ctx->r25 = ADD32(ctx->r10, ctx->r24);
    // 0x800AB808: lw          $t5, 0x0($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X0);
    // 0x800AB80C: and         $t6, $v0, $t3
    ctx->r14 = ctx->r2 & ctx->r11;
    // 0x800AB810: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x800AB814: b           L_800AB844
    // 0x800AB818: addu        $v1, $t7, $t4
    ctx->r3 = ADD32(ctx->r15, ctx->r12);
        goto L_800AB844;
    // 0x800AB818: addu        $v1, $t7, $t4
    ctx->r3 = ADD32(ctx->r15, ctx->r12);
L_800AB81C:
    // 0x800AB81C: lui         $v0, 0x601
    ctx->r2 = S32(0X601 << 16);
    // 0x800AB820: addiu       $v0, $v0, -0x3880
    ctx->r2 = ADD32(ctx->r2, -0X3880);
    // 0x800AB824: sll         $t8, $v0, 4
    ctx->r24 = S32(ctx->r2 << 4);
    // 0x800AB828: srl         $t9, $t8, 28
    ctx->r25 = S32(U32(ctx->r24) >> 28);
    // 0x800AB82C: sll         $t5, $t9, 2
    ctx->r13 = S32(ctx->r25 << 2);
    // 0x800AB830: addu        $t6, $t2, $t5
    ctx->r14 = ADD32(ctx->r10, ctx->r13);
    // 0x800AB834: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800AB838: and         $t8, $v0, $t3
    ctx->r24 = ctx->r2 & ctx->r11;
    // 0x800AB83C: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800AB840: addu        $v1, $t9, $t4
    ctx->r3 = ADD32(ctx->r25, ctx->r12);
L_800AB844:
    // 0x800AB844: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
L_800AB848:
    // 0x800AB848: addiu       $t1, $zero, 0x121
    ctx->r9 = ADD32(0, 0X121);
    // 0x800AB84C: bne         $a3, $v0, L_800AB85C
    if (ctx->r7 != ctx->r2) {
        // 0x800AB850: nop
    
            goto L_800AB85C;
    }
    // 0x800AB850: nop

    // 0x800AB854: sh          $t0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r8;
    // 0x800AB858: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
L_800AB85C:
    // 0x800AB85C: bnel        $a1, $v0, L_800AB86C
    if (ctx->r5 != ctx->r2) {
        // 0x800AB860: lh          $t5, 0x4($v1)
        ctx->r13 = MEM_H(ctx->r3, 0X4);
            goto L_800AB86C;
    }
    goto skip_1;
    // 0x800AB860: lh          $t5, 0x4($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X4);
    skip_1:
    // 0x800AB864: sh          $a2, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r6;
    // 0x800AB868: lh          $t5, 0x4($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X4);
L_800AB86C:
    // 0x800AB86C: bnel        $a1, $t5, L_800AB87C
    if (ctx->r5 != ctx->r13) {
        // 0x800AB870: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_800AB87C;
    }
    goto skip_2;
    // 0x800AB870: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    skip_2:
    // 0x800AB874: sh          $a2, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r6;
    // 0x800AB878: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
L_800AB87C:
    // 0x800AB87C: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x800AB880: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800AB884: bne         $a3, $v0, L_800AB894
    if (ctx->r7 != ctx->r2) {
        // 0x800AB888: nop
    
            goto L_800AB894;
    }
    // 0x800AB888: nop

    // 0x800AB88C: sh          $t0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r8;
    // 0x800AB890: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
L_800AB894:
    // 0x800AB894: bnel        $a1, $v0, L_800AB8A4
    if (ctx->r5 != ctx->r2) {
        // 0x800AB898: lh          $t6, 0x4($v1)
        ctx->r14 = MEM_H(ctx->r3, 0X4);
            goto L_800AB8A4;
    }
    goto skip_3;
    // 0x800AB898: lh          $t6, 0x4($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X4);
    skip_3:
    // 0x800AB89C: sh          $a2, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r6;
    // 0x800AB8A0: lh          $t6, 0x4($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X4);
L_800AB8A4:
    // 0x800AB8A4: bnel        $a1, $t6, L_800AB8B4
    if (ctx->r5 != ctx->r14) {
        // 0x800AB8A8: lh          $v0, 0x10($v1)
        ctx->r2 = MEM_H(ctx->r3, 0X10);
            goto L_800AB8B4;
    }
    goto skip_4;
    // 0x800AB8A8: lh          $v0, 0x10($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X10);
    skip_4:
    // 0x800AB8AC: sh          $a2, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r6;
    // 0x800AB8B0: lh          $v0, 0x10($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X10);
L_800AB8B4:
    // 0x800AB8B4: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800AB8B8: bne         $a3, $v0, L_800AB8C8
    if (ctx->r7 != ctx->r2) {
        // 0x800AB8BC: nop
    
            goto L_800AB8C8;
    }
    // 0x800AB8BC: nop

    // 0x800AB8C0: sh          $t0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r8;
    // 0x800AB8C4: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
L_800AB8C8:
    // 0x800AB8C8: bnel        $a1, $v0, L_800AB8D8
    if (ctx->r5 != ctx->r2) {
        // 0x800AB8CC: lh          $t7, 0x4($v1)
        ctx->r15 = MEM_H(ctx->r3, 0X4);
            goto L_800AB8D8;
    }
    goto skip_5;
    // 0x800AB8CC: lh          $t7, 0x4($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X4);
    skip_5:
    // 0x800AB8D0: sh          $a2, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r6;
    // 0x800AB8D4: lh          $t7, 0x4($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X4);
L_800AB8D8:
    // 0x800AB8D8: bnel        $a1, $t7, L_800AB8E8
    if (ctx->r5 != ctx->r15) {
        // 0x800AB8DC: lh          $v0, 0x10($v1)
        ctx->r2 = MEM_H(ctx->r3, 0X10);
            goto L_800AB8E8;
    }
    goto skip_6;
    // 0x800AB8DC: lh          $v0, 0x10($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X10);
    skip_6:
    // 0x800AB8E0: sh          $a2, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r6;
    // 0x800AB8E4: lh          $v0, 0x10($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X10);
L_800AB8E8:
    // 0x800AB8E8: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800AB8EC: bne         $a3, $v0, L_800AB8FC
    if (ctx->r7 != ctx->r2) {
        // 0x800AB8F0: nop
    
            goto L_800AB8FC;
    }
    // 0x800AB8F0: nop

    // 0x800AB8F4: sh          $t0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r8;
    // 0x800AB8F8: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
L_800AB8FC:
    // 0x800AB8FC: bnel        $a1, $v0, L_800AB90C
    if (ctx->r5 != ctx->r2) {
        // 0x800AB900: lh          $t8, 0x4($v1)
        ctx->r24 = MEM_H(ctx->r3, 0X4);
            goto L_800AB90C;
    }
    goto skip_7;
    // 0x800AB900: lh          $t8, 0x4($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X4);
    skip_7:
    // 0x800AB904: sh          $a2, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r6;
    // 0x800AB908: lh          $t8, 0x4($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X4);
L_800AB90C:
    // 0x800AB90C: bnel        $a1, $t8, L_800AB91C
    if (ctx->r5 != ctx->r24) {
        // 0x800AB910: lh          $v0, 0x10($v1)
        ctx->r2 = MEM_H(ctx->r3, 0X10);
            goto L_800AB91C;
    }
    goto skip_8;
    // 0x800AB910: lh          $v0, 0x10($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X10);
    skip_8:
    // 0x800AB914: sh          $a2, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r6;
    // 0x800AB918: lh          $v0, 0x10($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X10);
L_800AB91C:
    // 0x800AB91C: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800AB920: bne         $a3, $v0, L_800AB930
    if (ctx->r7 != ctx->r2) {
        // 0x800AB924: nop
    
            goto L_800AB930;
    }
    // 0x800AB924: nop

    // 0x800AB928: sh          $t0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r8;
    // 0x800AB92C: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
L_800AB930:
    // 0x800AB930: bnel        $a1, $v0, L_800AB940
    if (ctx->r5 != ctx->r2) {
        // 0x800AB934: lh          $t9, 0x4($v1)
        ctx->r25 = MEM_H(ctx->r3, 0X4);
            goto L_800AB940;
    }
    goto skip_9;
    // 0x800AB934: lh          $t9, 0x4($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X4);
    skip_9:
    // 0x800AB938: sh          $a2, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r6;
    // 0x800AB93C: lh          $t9, 0x4($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X4);
L_800AB940:
    // 0x800AB940: bne         $a1, $t9, L_800AB94C
    if (ctx->r5 != ctx->r25) {
        // 0x800AB944: nop
    
            goto L_800AB94C;
    }
    // 0x800AB944: nop

    // 0x800AB948: sh          $a2, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r6;
L_800AB94C:
    // 0x800AB94C: bne         $a0, $t1, L_800AB87C
    if (ctx->r4 != ctx->r9) {
        // 0x800AB950: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_800AB87C;
    }
    // 0x800AB950: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
L_800AB954:
    // 0x800AB954: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800AB958:
    // 0x800AB958: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800AB95C: jr          $ra
    // 0x800AB960: nop

    return;
    // 0x800AB960: nop

;}
RECOMP_FUNC void Audio_PlayVoice(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001ACDC: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8001ACE0: addiu       $v0, $v0, 0x7384
    ctx->r2 = ADD32(ctx->r2, 0X7384);
    // 0x8001ACE4: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x8001ACE8: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8001ACEC: sw          $a0, 0x7388($at)
    MEM_W(0X7388, ctx->r1) = ctx->r4;
    // 0x8001ACF0: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8001ACF4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8001ACF8: jr          $ra
    // 0x8001ACFC: sb          $t7, 0x738C($at)
    MEM_B(0X738C, ctx->r1) = ctx->r15;
    return;
    // 0x8001ACFC: sb          $t7, 0x738C($at)
    MEM_B(0X738C, ctx->r1) = ctx->r15;
;}
RECOMP_FUNC void func_versus_800C0970(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C0970: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C0974: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C0978: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    // 0x800C097C: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    // 0x800C0980: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C0984: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x800C0988: jal         0x800B8DD0
    // 0x800C098C: addiu       $a1, $zero, 0x4E
    ctx->r5 = ADD32(0, 0X4E);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x800C098C: addiu       $a1, $zero, 0x4E
    ctx->r5 = ADD32(0, 0X4E);
    after_0:
    // 0x800C0990: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C0994: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x800C0998: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800C099C: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x800C09A0: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x800C09A4: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800C09A8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800C09AC: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800C09B0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800C09B4: lui         $at, 0x42C4
    ctx->r1 = S32(0X42C4 << 16);
    // 0x800C09B8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800C09BC: lui         $at, 0x4290
    ctx->r1 = S32(0X4290 << 16);
    // 0x800C09C0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800C09C4: lui         $a2, 0x40A6
    ctx->r6 = S32(0X40A6 << 16);
    // 0x800C09C8: ori         $a2, $a2, 0x147B
    ctx->r6 = ctx->r6 | 0X147B;
    // 0x800C09CC: jal         0x800BCFFC
    // 0x800C09D0: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    func_versus_800BCFFC(rdram, ctx);
        goto after_1;
    // 0x800C09D0: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x800C09D4: lui         $at, 0x42C4
    ctx->r1 = S32(0X42C4 << 16);
    // 0x800C09D8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800C09DC: lui         $at, 0x4318
    ctx->r1 = S32(0X4318 << 16);
    // 0x800C09E0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800C09E4: lui         $a2, 0x40A6
    ctx->r6 = S32(0X40A6 << 16);
    // 0x800C09E8: ori         $a2, $a2, 0x147B
    ctx->r6 = ctx->r6 | 0X147B;
    // 0x800C09EC: jal         0x800BCFFC
    // 0x800C09F0: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    func_versus_800BCFFC(rdram, ctx);
        goto after_2;
    // 0x800C09F0: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x800C09F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C09F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C09FC: jr          $ra
    // 0x800C0A00: nop

    return;
    // 0x800C0A00: nop

;}
RECOMP_FUNC void RCP_SetupDL_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B9180: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800B9184: addiu       $t3, $t3, 0x7E64
    ctx->r11 = ADD32(ctx->r11, 0X7E64);
    // 0x800B9188: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x800B918C: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x800B9190: addiu       $t8, $t8, 0x3438
    ctx->r24 = ADD32(ctx->r24, 0X3438);
    // 0x800B9194: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800B9198: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x800B919C: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x800B91A0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800B91A4: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800B91A8: lw          $t0, 0x0($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X0);
    // 0x800B91AC: lui         $t4, 0xF800
    ctx->r12 = S32(0XF800 << 16);
    // 0x800B91B0: andi        $t7, $a1, 0xFF
    ctx->r15 = ctx->r5 & 0XFF;
    // 0x800B91B4: addiu       $t9, $t0, 0x8
    ctx->r25 = ADD32(ctx->r8, 0X8);
    // 0x800B91B8: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x800B91BC: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x800B91C0: sll         $t6, $a0, 24
    ctx->r14 = S32(ctx->r4 << 24);
    // 0x800B91C4: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
    // 0x800B91C8: andi        $t4, $a2, 0xFF
    ctx->r12 = ctx->r6 & 0XFF;
    // 0x800B91CC: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x800B91D0: sll         $t5, $t4, 8
    ctx->r13 = S32(ctx->r12 << 8);
    // 0x800B91D4: or          $t7, $t9, $t5
    ctx->r15 = ctx->r25 | ctx->r13;
    // 0x800B91D8: andi        $t6, $a3, 0xFF
    ctx->r14 = ctx->r7 & 0XFF;
    // 0x800B91DC: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x800B91E0: sw          $t8, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r24;
    // 0x800B91E4: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x800B91E8: lui         $t9, 0xBC00
    ctx->r25 = S32(0XBC00 << 16);
    // 0x800B91EC: ori         $t9, $t9, 0x8
    ctx->r25 = ctx->r25 | 0X8;
    // 0x800B91F0: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x800B91F4: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
    // 0x800B91F8: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800B91FC: lw          $t7, 0x10($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X10);
    // 0x800B9200: lw          $t5, 0x14($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X14);
    // 0x800B9204: lui         $t6, 0x1
    ctx->r14 = S32(0X1 << 16);
    // 0x800B9208: ori         $t6, $t6, 0xF400
    ctx->r14 = ctx->r14 | 0XF400;
    // 0x800B920C: subu        $t2, $t5, $t7
    ctx->r10 = SUB32(ctx->r13, ctx->r15);
    // 0x800B9210: div         $zero, $t6, $t2
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r10))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r10)));
    // 0x800B9214: negu        $t5, $t7
    ctx->r13 = SUB32(0, ctx->r15);
    // 0x800B9218: mflo        $t4
    ctx->r12 = lo;
    // 0x800B921C: sll         $t9, $t4, 16
    ctx->r25 = S32(ctx->r12 << 16);
    // 0x800B9220: or          $t1, $v1, $zero
    ctx->r9 = ctx->r3 | 0;
    // 0x800B9224: bne         $t2, $zero, L_800B9230
    if (ctx->r10 != 0) {
        // 0x800B9228: nop
    
            goto L_800B9230;
    }
    // 0x800B9228: nop

    // 0x800B922C: break       7
    do_break(2148241964);
L_800B9230:
    // 0x800B9230: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B9234: bne         $t2, $at, L_800B9248
    if (ctx->r10 != ctx->r1) {
        // 0x800B9238: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B9248;
    }
    // 0x800B9238: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B923C: bne         $t6, $at, L_800B9248
    if (ctx->r14 != ctx->r1) {
        // 0x800B9240: nop
    
            goto L_800B9248;
    }
    // 0x800B9240: nop

    // 0x800B9244: break       6
    do_break(2148241988);
L_800B9248:
    // 0x800B9248: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x800B924C: ori         $at, $at, 0xF400
    ctx->r1 = ctx->r1 | 0XF400;
    // 0x800B9250: sll         $t6, $t5, 8
    ctx->r14 = S32(ctx->r13 << 8);
    // 0x800B9254: addu        $t8, $t6, $at
    ctx->r24 = ADD32(ctx->r14, ctx->r1);
    // 0x800B9258: div         $zero, $t8, $t2
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r10))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r10)));
    // 0x800B925C: mflo        $t4
    ctx->r12 = lo;
    // 0x800B9260: andi        $t7, $t4, 0xFFFF
    ctx->r15 = ctx->r12 & 0XFFFF;
    // 0x800B9264: or          $t5, $t9, $t7
    ctx->r13 = ctx->r25 | ctx->r15;
    // 0x800B9268: sw          $t5, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r13;
    // 0x800B926C: bne         $t2, $zero, L_800B9278
    if (ctx->r10 != 0) {
        // 0x800B9270: nop
    
            goto L_800B9278;
    }
    // 0x800B9270: nop

    // 0x800B9274: break       7
    do_break(2148242036);
L_800B9278:
    // 0x800B9278: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B927C: bne         $t2, $at, L_800B9290
    if (ctx->r10 != ctx->r1) {
        // 0x800B9280: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B9290;
    }
    // 0x800B9280: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B9284: bne         $t8, $at, L_800B9290
    if (ctx->r24 != ctx->r1) {
        // 0x800B9288: nop
    
            goto L_800B9290;
    }
    // 0x800B9288: nop

    // 0x800B928C: break       6
    do_break(2148242060);
L_800B9290:
    // 0x800B9290: jr          $ra
    // 0x800B9294: nop

    return;
    // 0x800B9294: nop

;}
RECOMP_FUNC void Play_PlaySfxFirstPlayer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A6028: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A602C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800A6030: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x800A6034: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x800A6038: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800A603C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A6040: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800A6044: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x800A6048: addiu       $t6, $t6, 0x5D3C
    ctx->r14 = ADD32(ctx->r14, 0X5D3C);
    // 0x800A604C: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x800A6050: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x800A6054: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800A6058: jal         0x80019218
    // 0x800A605C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    Audio_PlaySfx(rdram, ctx);
        goto after_0;
    // 0x800A605C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_0:
    // 0x800A6060: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A6064: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800A6068: jr          $ra
    // 0x800A606C: nop

    return;
    // 0x800A606C: nop

;}
RECOMP_FUNC void AudioLoad_Dma(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000FBA8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000FBAC: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x8000FBB0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000FBB4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8000FBB8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8000FBBC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8000FBC0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8000FBC4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8000FBC8: beq         $t6, $at, L_8000FBE4
    if (ctx->r14 == ctx->r1) {
        // 0x8000FBCC: sw          $a3, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r7;
            goto L_8000FBE4;
    }
    // 0x8000FBCC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8000FBD0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8000FBD4: beq         $t6, $at, L_8000FBF4
    if (ctx->r14 == ctx->r1) {
        // 0x8000FBD8: nop
    
            goto L_8000FBF4;
    }
    // 0x8000FBD8: nop

    // 0x8000FBDC: b           L_8000FC68
    // 0x8000FBE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000FC68;
    // 0x8000FBE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000FBE4:
    // 0x8000FBE4: jal         0x80024EC0
    // 0x8000FBE8: nop

    osCartRomInit_recomp(rdram, ctx);
        goto after_0;
    // 0x8000FBE8: nop

    after_0:
    // 0x8000FBEC: b           L_8000FC0C
    // 0x8000FBF0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
        goto L_8000FC0C;
    // 0x8000FBF0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_8000FBF4:
    // 0x8000FBF4: jal         0x8001EE60
    // 0x8000FBF8: nop

    osDriveRomInit(rdram, ctx);
        goto after_1;
    // 0x8000FBF8: nop

    after_1:
    // 0x8000FBFC: b           L_8000FC0C
    // 0x8000FC00: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
        goto L_8000FC0C;
    // 0x8000FC00: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8000FC04: b           L_8000FC68
    // 0x8000FC08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000FC68;
    // 0x8000FC08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000FC0C:
    // 0x8000FC0C: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x8000FC10: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x8000FC14: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8000FC18: andi        $t7, $v0, 0xF
    ctx->r15 = ctx->r2 & 0XF;
    // 0x8000FC1C: beql        $t7, $zero, L_8000FC34
    if (ctx->r15 == 0) {
        // 0x8000FC20: sb          $t9, 0x2($s0)
        MEM_B(0X2, ctx->r16) = ctx->r25;
            goto L_8000FC34;
    }
    goto skip_0;
    // 0x8000FC20: sb          $t9, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r25;
    skip_0:
    // 0x8000FC24: addiu       $v0, $v0, 0xF
    ctx->r2 = ADD32(ctx->r2, 0XF);
    // 0x8000FC28: and         $t8, $v0, $at
    ctx->r24 = ctx->r2 & ctx->r1;
    // 0x8000FC2C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8000FC30: sb          $t9, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r25;
L_8000FC34:
    // 0x8000FC34: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8000FC38: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x8000FC3C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8000FC40: sw          $t0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r8;
    // 0x8000FC44: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8000FC48: sw          $t1, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r9;
    // 0x8000FC4C: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x8000FC50: sw          $v0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r2;
    // 0x8000FC54: sw          $t2, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r10;
    // 0x8000FC58: sw          $t3, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r11;
    // 0x8000FC5C: jal         0x80024FB0
    // 0x8000FC60: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    osEPiStartDma_recomp(rdram, ctx);
        goto after_2;
    // 0x8000FC60: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x8000FC64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000FC68:
    // 0x8000FC68: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8000FC6C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000FC70: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8000FC74: jr          $ra
    // 0x8000FC78: nop

    return;
    // 0x8000FC78: nop

;}
RECOMP_FUNC void Animation_GetLimbIndex(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009A400: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8009A404: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8009A408: beql        $v0, $zero, L_8009A438
    if (ctx->r2 == 0) {
        // 0x8009A40C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8009A438;
    }
    goto skip_0;
    // 0x8009A40C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
L_8009A410:
    // 0x8009A410: bnel        $a0, $v0, L_8009A424
    if (ctx->r4 != ctx->r2) {
        // 0x8009A414: lw          $v0, 0x4($a1)
        ctx->r2 = MEM_W(ctx->r5, 0X4);
            goto L_8009A424;
    }
    goto skip_1;
    // 0x8009A414: lw          $v0, 0x4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X4);
    skip_1:
    // 0x8009A418: jr          $ra
    // 0x8009A41C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8009A41C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8009A420: lw          $v0, 0x4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X4);
L_8009A424:
    // 0x8009A424: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8009A428: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8009A42C: bne         $v0, $zero, L_8009A410
    if (ctx->r2 != 0) {
        // 0x8009A430: nop
    
            goto L_8009A410;
    }
    // 0x8009A430: nop

    // 0x8009A434: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8009A438:
    // 0x8009A438: jr          $ra
    // 0x8009A43C: nop

    return;
    // 0x8009A43C: nop

;}
RECOMP_FUNC void func_versus_800BD9FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BD9FC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800BDA00: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800BDA04: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800BDA08: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800BDA0C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BDA10: lui         $a1, 0x101
    ctx->r5 = S32(0X101 << 16);
    // 0x800BDA14: lui         $a2, 0x101
    ctx->r6 = S32(0X101 << 16);
    // 0x800BDA18: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x800BDA1C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800BDA20: addiu       $a2, $a2, 0x1EC0
    ctx->r6 = ADD32(ctx->r6, 0X1EC0);
    // 0x800BDA24: addiu       $a1, $a1, 0x1E80
    ctx->r5 = ADD32(ctx->r5, 0X1E80);
    // 0x800BDA28: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x800BDA2C: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x800BDA30: swc1        $f12, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f12.u32l;
    // 0x800BDA34: swc1        $f14, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f14.u32l;
    // 0x800BDA38: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x800BDA3C: jal         0x8009C320
    // 0x800BDA40: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    Lib_TextureRect_CI4(rdram, ctx);
        goto after_0;
    // 0x800BDA40: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x800BDA44: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800BDA48: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800BDA4C: jr          $ra
    // 0x800BDA50: nop

    return;
    // 0x800BDA50: nop

;}
RECOMP_FUNC void func_versus_800C075C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C075C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C0760: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C0764: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C0768: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x800C076C: jal         0x800B8DD0
    // 0x800C0770: addiu       $a1, $zero, 0x4E
    ctx->r5 = ADD32(0, 0X4E);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x800C0770: addiu       $a1, $zero, 0x4E
    ctx->r5 = ADD32(0, 0X4E);
    after_0:
    // 0x800C0774: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C0778: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x800C077C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800C0780: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x800C0784: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x800C0788: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800C078C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800C0790: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800C0794: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800C0798: lui         $at, 0x42BC
    ctx->r1 = S32(0X42BC << 16);
    // 0x800C079C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800C07A0: lui         $at, 0x42FC
    ctx->r1 = S32(0X42FC << 16);
    // 0x800C07A4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800C07A8: jal         0x800BCEF8
    // 0x800C07AC: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    func_versus_800BCEF8(rdram, ctx);
        goto after_1;
    // 0x800C07AC: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_1:
    // 0x800C07B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C07B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C07B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C07BC: jr          $ra
    // 0x800C07C0: nop

    return;
    // 0x800C07C0: nop

;}
RECOMP_FUNC void Object_ApplyWaterDistortion(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800596C0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800596C4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800596C8: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x800596CC: lw          $t6, 0x7DB0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7DB0);
    // 0x800596D0: lui         $at, 0x4150
    ctx->r1 = S32(0X4150 << 16);
    // 0x800596D4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800596D8: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800596DC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800596E0: lwc1        $f16, 0x6020($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6020);
    // 0x800596E4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800596E8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800596EC: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x800596F0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800596F4: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800596F8: nop

    // 0x800596FC: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80059700: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80059704: jal         0x80005FE0
    // 0x80059708: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_0;
    // 0x80059708: nop

    after_0:
    // 0x8005970C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80059710: lui         $a1, 0x3F82
    ctx->r5 = S32(0X3F82 << 16);
    // 0x80059714: lui         $a2, 0x3F7A
    ctx->r6 = S32(0X3F7A << 16);
    // 0x80059718: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8005971C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80059720: ori         $a2, $a2, 0xE148
    ctx->r6 = ctx->r6 | 0XE148;
    // 0x80059724: ori         $a1, $a1, 0x8F5C
    ctx->r5 = ctx->r5 | 0X8F5C;
    // 0x80059728: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8005972C: jal         0x80005C34
    // 0x80059730: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_1;
    // 0x80059730: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x80059734: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x80059738: lw          $t8, 0x7DB0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7DB0);
    // 0x8005973C: lui         $at, 0x4150
    ctx->r1 = S32(0X4150 << 16);
    // 0x80059740: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80059744: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80059748: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005974C: lwc1        $f18, 0x6024($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6024);
    // 0x80059750: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80059754: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80059758: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8005975C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80059760: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x80059764: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80059768: nop

    // 0x8005976C: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80059770: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80059774: jal         0x80005FE0
    // 0x80059778: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_2;
    // 0x80059778: nop

    after_2:
    // 0x8005977C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80059780: lui         $a1, 0x3F82
    ctx->r5 = S32(0X3F82 << 16);
    // 0x80059784: lui         $a2, 0x3F7A
    ctx->r6 = S32(0X3F7A << 16);
    // 0x80059788: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8005978C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80059790: ori         $a2, $a2, 0xE148
    ctx->r6 = ctx->r6 | 0XE148;
    // 0x80059794: ori         $a1, $a1, 0x8F5C
    ctx->r5 = ctx->r5 | 0X8F5C;
    // 0x80059798: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8005979C: jal         0x80005C34
    // 0x800597A0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_3;
    // 0x800597A0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_3:
    // 0x800597A4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800597A8: jal         0x80006EB8
    // 0x800597AC: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_4;
    // 0x800597AC: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    after_4:
    // 0x800597B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800597B4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800597B8: jr          $ra
    // 0x800597BC: nop

    return;
    // 0x800597BC: nop

;}
RECOMP_FUNC void Obj54_8006A984(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A984: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8006A988: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8006A98C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8006A990: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006A994: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8006A998: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8006A99C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8006A9A0: jal         0x80061474
    // 0x8006A9A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Effect_Initialize(rdram, ctx);
        goto after_0;
    // 0x8006A9A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8006A9A8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8006A9AC: addiu       $t7, $zero, 0x16D
    ctx->r15 = ADD32(0, 0X16D);
    // 0x8006A9B0: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
    // 0x8006A9B4: sh          $t7, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r15;
    // 0x8006A9B8: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8006A9BC: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8006A9C0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8006A9C4: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x8006A9C8: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8006A9CC: addiu       $t8, $zero, 0x28
    ctx->r24 = ADD32(0, 0X28);
    // 0x8006A9D0: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x8006A9D4: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8006A9D8: sh          $t8, 0x44($s0)
    MEM_H(0X44, ctx->r16) = ctx->r24;
    // 0x8006A9DC: swc1        $f10, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f10.u32l;
    // 0x8006A9E0: jal         0x80004EB0
    // 0x8006A9E4: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x8006A9E4: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    after_1:
    // 0x8006A9E8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8006A9EC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8006A9F0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8006A9F4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8006A9F8: sub.s       $f2, $f0, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x8006A9FC: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    // 0x8006AA00: add.s       $f18, $f2, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x8006AA04: jal         0x80004EB0
    // 0x8006AA08: swc1        $f18, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f18.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_2;
    // 0x8006AA08: swc1        $f18, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f18.u32l;
    after_2:
    // 0x8006AA0C: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8006AA10: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8006AA14: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x8006AA18: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    // 0x8006AA1C: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8006AA20: jal         0x800612B8
    // 0x8006AA24: swc1        $f8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f8.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_3;
    // 0x8006AA24: swc1        $f8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f8.u32l;
    after_3:
    // 0x8006AA28: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006AA2C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8006AA30: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8006AA34: jr          $ra
    // 0x8006AA38: nop

    return;
    // 0x8006AA38: nop

;}
RECOMP_FUNC void func_versus_800C26C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C26C8: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800C26CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C26D0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C26D4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x800C26D8: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x800C26DC: lw          $t6, 0x78AC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X78AC);
    // 0x800C26E0: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x800C26E4: bnel        $a0, $t6, L_800C2818
    if (ctx->r4 != ctx->r14) {
        // 0x800C26E8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800C2818;
    }
    goto skip_0;
    // 0x800C26E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x800C26EC: lw          $t7, 0x7E7C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7E7C);
    // 0x800C26F0: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x800C26F4: addiu       $v1, $v1, -0x78A8
    ctx->r3 = ADD32(ctx->r3, -0X78A8);
    // 0x800C26F8: beql        $t7, $zero, L_800C2818
    if (ctx->r15 == 0) {
        // 0x800C26FC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800C2818;
    }
    goto skip_1;
    // 0x800C26FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x800C2700: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800C2704: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x800C2708: lui         $s0, 0x8016
    ctx->r16 = S32(0X8016 << 16);
    // 0x800C270C: beq         $v0, $zero, L_800C271C
    if (ctx->r2 == 0) {
        // 0x800C2710: addiu       $t8, $v0, -0x1
        ctx->r24 = ADD32(ctx->r2, -0X1);
            goto L_800C271C;
    }
    // 0x800C2710: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x800C2714: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800C2718: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_800C271C:
    // 0x800C271C: bne         $v0, $zero, L_800C2814
    if (ctx->r2 != 0) {
        // 0x800C2720: addiu       $s0, $s0, 0x5D68
        ctx->r16 = ADD32(ctx->r16, 0X5D68);
            goto L_800C2814;
    }
    // 0x800C2720: addiu       $s0, $s0, 0x5D68
    ctx->r16 = ADD32(ctx->r16, 0X5D68);
    // 0x800C2724: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800C2728: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x800C272C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C2730: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800C2734: lwc1        $f8, -0x6CA8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X6CA8);
    // 0x800C2738: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
    // 0x800C273C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C2740: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    // 0x800C2744: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    // 0x800C2748: swc1        $f8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f8.u32l;
L_800C274C:
    // 0x800C274C: lbu         $t9, 0x0($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X0);
    // 0x800C2750: bne         $t9, $zero, L_800C2808
    if (ctx->r25 != 0) {
        // 0x800C2754: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800C2808;
    }
    // 0x800C2754: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C2758: jal         0x800613C4
    // 0x800C275C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    Actor_Initialize(rdram, ctx);
        goto after_0;
    // 0x800C275C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_0:
    // 0x800C2760: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x800C2764: addiu       $t1, $zero, 0xC5
    ctx->r9 = ADD32(0, 0XC5);
    // 0x800C2768: sb          $t0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r8;
    // 0x800C276C: jal         0x80004EB0
    // 0x800C2770: sh          $t1, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r9;
    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x800C2770: sh          $t1, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r9;
    after_1:
    // 0x800C2774: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x800C2778: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800C277C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C2780: lwc1        $f18, -0x6CA4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X6CA4);
    // 0x800C2784: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x800C2788: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800C278C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x800C2790: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800C2794: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800C2798: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x800C279C: jal         0x80005E90
    // 0x800C27A0: nop

    Matrix_RotateY(rdram, ctx);
        goto after_2;
    // 0x800C27A0: nop

    after_2:
    // 0x800C27A4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800C27A8: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x800C27AC: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x800C27B0: jal         0x80006A20
    // 0x800C27B4: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_3;
    // 0x800C27B4: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    after_3:
    // 0x800C27B8: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800C27BC: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x800C27C0: addiu       $t3, $zero, 0x18
    ctx->r11 = ADD32(0, 0X18);
    // 0x800C27C4: swc1        $f6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f6.u32l;
    // 0x800C27C8: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800C27CC: addiu       $t4, $zero, 0x1E
    ctx->r12 = ADD32(0, 0X1E);
    // 0x800C27D0: addiu       $t2, $v0, 0xA
    ctx->r10 = ADD32(ctx->r2, 0XA);
    // 0x800C27D4: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    // 0x800C27D8: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800C27DC: sh          $t2, 0xE4($s0)
    MEM_H(0XE4, ctx->r16) = ctx->r10;
    // 0x800C27E0: sh          $t3, 0xCE($s0)
    MEM_H(0XCE, ctx->r16) = ctx->r11;
    // 0x800C27E4: sh          $t4, 0xC2($s0)
    MEM_H(0XC2, ctx->r16) = ctx->r12;
    // 0x800C27E8: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x800C27EC: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    // 0x800C27F0: jal         0x800612B8
    // 0x800C27F4: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_4;
    // 0x800C27F4: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
    after_4:
    // 0x800C27F8: lui         $t5, 0x800C
    ctx->r13 = S32(0X800C << 16);
    // 0x800C27FC: addiu       $t5, $t5, 0x2244
    ctx->r13 = ADD32(ctx->r13, 0X2244);
    // 0x800C2800: b           L_800C2814
    // 0x800C2804: sw          $t5, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r13;
        goto L_800C2814;
    // 0x800C2804: sw          $t5, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r13;
L_800C2808:
    // 0x800C2808: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800C280C: bne         $v0, $v1, L_800C274C
    if (ctx->r2 != ctx->r3) {
        // 0x800C2810: addiu       $s0, $s0, 0x2F4
        ctx->r16 = ADD32(ctx->r16, 0X2F4);
            goto L_800C274C;
    }
    // 0x800C2810: addiu       $s0, $s0, 0x2F4
    ctx->r16 = ADD32(ctx->r16, 0X2F4);
L_800C2814:
    // 0x800C2814: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800C2818:
    // 0x800C2818: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C281C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x800C2820: jr          $ra
    // 0x800C2824: nop

    return;
    // 0x800C2824: nop

;}
RECOMP_FUNC void Obj54_8006AA3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006AA3C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006AA40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006AA44: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8006AA48: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8006AA4C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8006AA50: addiu       $v0, $v0, 0x37E0
    ctx->r2 = ADD32(ctx->r2, 0X37E0);
    // 0x8006AA54: addiu       $a0, $a0, 0x130
    ctx->r4 = ADD32(ctx->r4, 0X130);
    // 0x8006AA58: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
L_8006AA5C:
    // 0x8006AA5C: bnel        $t6, $zero, L_8006AA80
    if (ctx->r14 != 0) {
        // 0x8006AA60: addiu       $a0, $a0, 0x8C
        ctx->r4 = ADD32(ctx->r4, 0X8C);
            goto L_8006AA80;
    }
    goto skip_0;
    // 0x8006AA60: addiu       $a0, $a0, 0x8C
    ctx->r4 = ADD32(ctx->r4, 0X8C);
    skip_0:
    // 0x8006AA64: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8006AA68: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x8006AA6C: jal         0x8006A984
    // 0x8006AA70: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    Obj54_8006A984(rdram, ctx);
        goto after_0;
    // 0x8006AA70: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    after_0:
    // 0x8006AA74: b           L_8006AA8C
    // 0x8006AA78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8006AA8C;
    // 0x8006AA78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006AA7C: addiu       $a0, $a0, 0x8C
    ctx->r4 = ADD32(ctx->r4, 0X8C);
L_8006AA80:
    // 0x8006AA80: bnel        $a0, $v0, L_8006AA5C
    if (ctx->r4 != ctx->r2) {
        // 0x8006AA84: lbu         $t6, 0x0($a0)
        ctx->r14 = MEM_BU(ctx->r4, 0X0);
            goto L_8006AA5C;
    }
    goto skip_1;
    // 0x8006AA84: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    skip_1:
    // 0x8006AA88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8006AA8C:
    // 0x8006AA8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006AA90: jr          $ra
    // 0x8006AA94: nop

    return;
    // 0x8006AA94: nop

;}
RECOMP_FUNC void Actor237_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A96C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8006A970: jr          $ra
    // 0x8006A974: nop

    return;
    // 0x8006A974: nop

;}
RECOMP_FUNC void BonusText_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077404: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80077408: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8007740C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80077410: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80077414: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x80077418: addiu       $t7, $t7, 0x1528
    ctx->r15 = ADD32(ctx->r15, 0X1528);
    // 0x8007741C: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x80077420: addiu       $t6, $sp, 0x60
    ctx->r14 = ADD32(ctx->r29, 0X60);
    // 0x80077424: lw          $t1, 0x4($t7)
    ctx->r9 = MEM_W(ctx->r15, 0X4);
    // 0x80077428: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x8007742C: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x80077430: sw          $t1, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r9;
    // 0x80077434: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x80077438: lhu         $t2, 0x18($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X18);
    // 0x8007743C: slti        $at, $t2, 0x2E
    ctx->r1 = SIGNED(ctx->r10) < 0X2E ? 1 : 0;
    // 0x80077440: beq         $at, $zero, L_8007777C
    if (ctx->r1 == 0) {
        // 0x80077444: lui         $at, 0x8017
        ctx->r1 = S32(0X8017 << 16);
            goto L_8007777C;
    }
    // 0x80077444: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80077448: lwc1        $f6, 0x7D20($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x8007744C: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80077450: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80077454: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x80077458: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8007745C: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    // 0x80077460: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80077464: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80077468: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x8007746C: jal         0x80005B00
    // 0x80077470: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Translate(rdram, ctx);
        goto after_0;
    // 0x80077470: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_0:
    // 0x80077474: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80077478: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8007747C: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    // 0x80077480: jal         0x80006970
    // 0x80077484: addiu       $a2, $sp, 0x54
    ctx->r6 = ADD32(ctx->r29, 0X54);
    Matrix_MultVec3f(rdram, ctx);
        goto after_1;
    // 0x80077484: addiu       $a2, $sp, 0x54
    ctx->r6 = ADD32(ctx->r29, 0X54);
    after_1:
    // 0x80077488: lwc1        $f10, 0x54($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8007748C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80077490: lwc1        $f2, 0x72C4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X72C4);
    // 0x80077494: abs.s       $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = fabsf(ctx->f10.fl);
    // 0x80077498: lwc1        $f16, 0x58($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8007749C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800774A0: nop

    // 0x800774A4: bc1fl       L_80077780
    if (!c1cs) {
        // 0x800774A8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80077780;
    }
    goto skip_0;
    // 0x800774A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x800774AC: abs.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = fabsf(ctx->f16.fl);
    // 0x800774B0: lwc1        $f18, 0x5C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800774B4: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800774B8: nop

    // 0x800774BC: bc1fl       L_80077780
    if (!c1cs) {
        // 0x800774C0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80077780;
    }
    goto skip_1;
    // 0x800774C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x800774C4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800774C8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800774CC: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x800774D0: nop

    // 0x800774D4: bc1fl       L_8007777C
    if (!c1cs) {
        // 0x800774D8: sb          $zero, 0x0($s0)
        MEM_B(0X0, ctx->r16) = 0;
            goto L_8007777C;
    }
    goto skip_2;
    // 0x800774D8: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    skip_2:
    // 0x800774DC: lwc1        $f6, 0x72C8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X72C8);
    // 0x800774E0: c.lt.s      $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f6.fl < ctx->f18.fl;
    // 0x800774E4: nop

    // 0x800774E8: bc1fl       L_8007777C
    if (!c1cs) {
        // 0x800774EC: sb          $zero, 0x0($s0)
        MEM_B(0X0, ctx->r16) = 0;
            goto L_8007777C;
    }
    goto skip_3;
    // 0x800774EC: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    skip_3:
    // 0x800774F0: mul.s       $f8, $f10, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x800774F4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800774F8: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x800774FC: mul.s       $f4, $f16, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x80077500: lwc1        $f16, 0x72CC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X72CC);
    // 0x80077504: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80077508: mul.s       $f10, $f18, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x8007750C: lw          $t5, 0x78A0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X78A0);
    // 0x80077510: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80077514: lw          $t4, -0x7D80($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7D80);
    // 0x80077518: sll         $t9, $t5, 2
    ctx->r25 = S32(ctx->r13 << 2);
    // 0x8007751C: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80077520: lwc1        $f4, 0x72D0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X72D0);
    // 0x80077524: addu        $t9, $t9, $t5
    ctx->r25 = ADD32(ctx->r25, ctx->r13);
    // 0x80077528: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x8007752C: add.s       $f0, $f6, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80077530: subu        $t9, $t9, $t5
    ctx->r25 = SUB32(ctx->r25, ctx->r13);
    // 0x80077534: sll         $t9, $t9, 5
    ctx->r25 = S32(ctx->r25 << 5);
    // 0x80077538: addu        $t8, $t4, $t9
    ctx->r24 = ADD32(ctx->r12, ctx->r25);
    // 0x8007753C: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x80077540: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80077544: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80077548: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8007754C: mul.s       $f8, $f0, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80077550: nop

    // 0x80077554: mul.s       $f18, $f8, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x80077558: swc1        $f18, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f18.u32l;
    // 0x8007755C: lwc1        $f6, 0x58($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X58);
    // 0x80077560: neg.s       $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = -ctx->f6.fl;
    // 0x80077564: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80077568: jal         0x80005E90
    // 0x8007756C: nop

    Matrix_RotateY(rdram, ctx);
        goto after_2;
    // 0x8007756C: nop

    after_2:
    // 0x80077570: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x80077574: lw          $t7, 0x78A0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X78A0);
    // 0x80077578: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8007757C: lw          $t6, -0x7D80($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7D80);
    // 0x80077580: sll         $t1, $t7, 2
    ctx->r9 = S32(ctx->r15 << 2);
    // 0x80077584: addu        $t1, $t1, $t7
    ctx->r9 = ADD32(ctx->r9, ctx->r15);
    // 0x80077588: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x8007758C: subu        $t1, $t1, $t7
    ctx->r9 = SUB32(ctx->r9, ctx->r15);
    // 0x80077590: sll         $t1, $t1, 5
    ctx->r9 = S32(ctx->r9 << 5);
    // 0x80077594: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80077598: addu        $t2, $t6, $t1
    ctx->r10 = ADD32(ctx->r14, ctx->r9);
    // 0x8007759C: lw          $a1, 0x5C($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X5C);
    // 0x800775A0: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x800775A4: jal         0x80005D44
    // 0x800775A8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateX(rdram, ctx);
        goto after_3;
    // 0x800775A8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x800775AC: lwc1        $f0, 0x50($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800775B0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800775B4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800775B8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800775BC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800775C0: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x800775C4: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x800775C8: jal         0x80005C34
    // 0x800775CC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_4;
    // 0x800775CC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_4:
    // 0x800775D0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800775D4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800775D8: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    // 0x800775DC: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800775E0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800775E4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800775E8: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x800775EC: jal         0x80005B00
    // 0x800775F0: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Translate(rdram, ctx);
        goto after_5;
    // 0x800775F0: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_5:
    // 0x800775F4: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x800775F8: jal         0x80006EB8
    // 0x800775FC: addiu       $a0, $a3, 0x7E64
    ctx->r4 = ADD32(ctx->r7, 0X7E64);
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_6;
    // 0x800775FC: addiu       $a0, $a3, 0x7E64
    ctx->r4 = ADD32(ctx->r7, 0X7E64);
    after_6:
    // 0x80077600: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x80077604: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x80077608: addiu       $a3, $a3, 0x7E64
    ctx->r7 = ADD32(ctx->r7, 0X7E64);
    // 0x8007760C: slti        $at, $v0, 0xB
    ctx->r1 = SIGNED(ctx->r2) < 0XB ? 1 : 0;
    // 0x80077610: beq         $at, $zero, L_80077664
    if (ctx->r1 == 0) {
        // 0x80077614: lui         $t0, 0x600
        ctx->r8 = S32(0X600 << 16);
            goto L_80077664;
    }
    // 0x80077614: lui         $t0, 0x600
    ctx->r8 = S32(0X600 << 16);
    // 0x80077618: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x8007761C: lui         $t9, 0x101
    ctx->r25 = S32(0X101 << 16);
    // 0x80077620: addiu       $t9, $t9, 0x5980
    ctx->r25 = ADD32(ctx->r25, 0X5980);
    // 0x80077624: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x80077628: sw          $t4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r12;
    // 0x8007762C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80077630: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x80077634: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80077638: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x8007763C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80077640: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x80077644: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x80077648: lbu         $t7, 0x0($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X0);
    // 0x8007764C: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x80077650: addu        $t1, $t1, $t6
    ctx->r9 = ADD32(ctx->r9, ctx->r14);
    // 0x80077654: lw          $t1, 0x14FC($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X14FC);
    // 0x80077658: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x8007765C: b           L_80077780
    // 0x80077660: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80077780;
    // 0x80077660: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80077664:
    // 0x80077664: addiu       $at, $zero, 0x65
    ctx->r1 = ADD32(0, 0X65);
    // 0x80077668: bne         $v0, $at, L_80077694
    if (ctx->r2 != ctx->r1) {
        // 0x8007766C: lui         $t0, 0x600
        ctx->r8 = S32(0X600 << 16);
            goto L_80077694;
    }
    // 0x8007766C: lui         $t0, 0x600
    ctx->r8 = S32(0X600 << 16);
    // 0x80077670: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80077674: lui         $t3, 0x101
    ctx->r11 = S32(0X101 << 16);
    // 0x80077678: addiu       $t3, $t3, 0x1F20
    ctx->r11 = ADD32(ctx->r11, 0X1F20);
    // 0x8007767C: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x80077680: sw          $t2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r10;
    // 0x80077684: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x80077688: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x8007768C: b           L_80077780
    // 0x80077690: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80077780;
    // 0x80077690: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80077694:
    // 0x80077694: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x80077698: bne         $v0, $at, L_800776C8
    if (ctx->r2 != ctx->r1) {
        // 0x8007769C: lui         $t0, 0x600
        ctx->r8 = S32(0X600 << 16);
            goto L_800776C8;
    }
    // 0x8007769C: lui         $t0, 0x600
    ctx->r8 = S32(0X600 << 16);
    // 0x800776A0: lui         $t0, 0x600
    ctx->r8 = S32(0X600 << 16);
    // 0x800776A4: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x800776A8: lui         $t4, 0x101
    ctx->r12 = S32(0X101 << 16);
    // 0x800776AC: addiu       $t4, $t4, 0x6580
    ctx->r12 = ADD32(ctx->r12, 0X6580);
    // 0x800776B0: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x800776B4: sw          $t5, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r13;
    // 0x800776B8: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x800776BC: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x800776C0: b           L_80077780
    // 0x800776C4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80077780;
    // 0x800776C4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800776C8:
    // 0x800776C8: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x800776CC: lui         $t8, 0x101
    ctx->r24 = S32(0X101 << 16);
    // 0x800776D0: addiu       $t8, $t8, 0x5980
    ctx->r24 = ADD32(ctx->r24, 0X5980);
    // 0x800776D4: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800776D8: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x800776DC: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800776E0: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x800776E4: lbu         $a0, 0x0($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X0);
    // 0x800776E8: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x800776EC: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x800776F0: beq         $a0, $at, L_80077720
    if (ctx->r4 == ctx->r1) {
        // 0x800776F4: addiu       $t1, $t1, 0x14E0
        ctx->r9 = ADD32(ctx->r9, 0X14E0);
            goto L_80077720;
    }
    // 0x800776F4: addiu       $t1, $t1, 0x14E0
    ctx->r9 = ADD32(ctx->r9, 0X14E0);
    // 0x800776F8: addiu       $at, $zero, 0x1E
    ctx->r1 = ADD32(0, 0X1E);
    // 0x800776FC: beq         $a0, $at, L_80077728
    if (ctx->r4 == ctx->r1) {
        // 0x80077700: addiu       $at, $zero, 0x28
        ctx->r1 = ADD32(0, 0X28);
            goto L_80077728;
    }
    // 0x80077700: addiu       $at, $zero, 0x28
    ctx->r1 = ADD32(0, 0X28);
    // 0x80077704: beq         $a0, $at, L_80077730
    if (ctx->r4 == ctx->r1) {
        // 0x80077708: addiu       $a2, $zero, 0x3
        ctx->r6 = ADD32(0, 0X3);
            goto L_80077730;
    }
    // 0x80077708: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8007770C: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x80077710: beq         $a0, $at, L_80077738
    if (ctx->r4 == ctx->r1) {
        // 0x80077714: nop
    
            goto L_80077738;
    }
    // 0x80077714: nop

    // 0x80077718: b           L_80077738
    // 0x8007771C: nop

        goto L_80077738;
    // 0x8007771C: nop

L_80077720:
    // 0x80077720: b           L_80077738
    // 0x80077724: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
        goto L_80077738;
    // 0x80077724: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_80077728:
    // 0x80077728: b           L_80077738
    // 0x8007772C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_80077738;
    // 0x8007772C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_80077730:
    // 0x80077730: b           L_80077738
    // 0x80077734: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
        goto L_80077738;
    // 0x80077734: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
L_80077738:
    // 0x80077738: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x8007773C: sll         $t6, $a2, 3
    ctx->r14 = S32(ctx->r6 << 3);
    // 0x80077740: addu        $a0, $t6, $t1
    ctx->r4 = ADD32(ctx->r14, ctx->r9);
    // 0x80077744: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80077748: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x8007774C: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x80077750: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x80077754: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x80077758: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x8007775C: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x80077760: sw          $t3, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r11;
    // 0x80077764: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x80077768: lw          $t5, 0x4($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X4);
    // 0x8007776C: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x80077770: b           L_80077780
    // 0x80077774: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80077780;
    // 0x80077774: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80077778: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
L_8007777C:
    // 0x8007777C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80077780:
    // 0x80077780: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80077784: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x80077788: jr          $ra
    // 0x8007778C: nop

    return;
    // 0x8007778C: nop

;}
RECOMP_FUNC void Display_Arwing(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80053C38: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80053C3C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80053C40: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x80053C44: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80053C48: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x80053C4C: lw          $t6, 0x78A0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X78A0);
    // 0x80053C50: lw          $v0, 0x1C4($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X1C4);
    // 0x80053C54: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    // 0x80053C58: bnel        $t6, $v0, L_80053D14
    if (ctx->r14 != ctx->r2) {
        // 0x80053C5C: lw          $t2, 0x238($a3)
        ctx->r10 = MEM_W(ctx->r7, 0X238);
            goto L_80053D14;
    }
    goto skip_0;
    // 0x80053C5C: lw          $t2, 0x238($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X238);
    skip_0:
    // 0x80053C60: bne         $t7, $zero, L_80053D10
    if (ctx->r15 != 0) {
        // 0x80053C64: sll         $t8, $v0, 2
        ctx->r24 = S32(ctx->r2 << 2);
            goto L_80053D10;
    }
    // 0x80053C64: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x80053C68: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x80053C6C: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80053C70: lw          $t9, 0x79C8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X79C8);
    // 0x80053C74: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80053C78: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80053C7C: slti        $at, $t9, 0x14
    ctx->r1 = SIGNED(ctx->r25) < 0X14 ? 1 : 0;
    // 0x80053C80: bne         $at, $zero, L_80053CB0
    if (ctx->r1 != 0) {
        // 0x80053C84: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_80053CB0;
    }
    // 0x80053C84: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x80053C88: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x80053C8C: lw          $t0, 0x7DB0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7DB0);
    // 0x80053C90: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x80053C94: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80053C98: andi        $t1, $t0, 0x7
    ctx->r9 = ctx->r8 & 0X7;
    // 0x80053C9C: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x80053CA0: nop

    // 0x80053CA4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80053CA8: mul.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80053CAC: nop

L_80053CB0:
    // 0x80053CB0: lui         $at, 0x4496
    ctx->r1 = S32(0X4496 << 16);
    // 0x80053CB4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80053CB8: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80053CBC: swc1        $f2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f2.u32l;
    // 0x80053CC0: swc1        $f2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f2.u32l;
    // 0x80053CC4: addiu       $a2, $a2, 0x13E0
    ctx->r6 = ADD32(ctx->r6, 0X13E0);
    // 0x80053CC8: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80053CCC: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x80053CD0: sw          $a3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r7;
    // 0x80053CD4: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x80053CD8: jal         0x80006970
    // 0x80053CDC: swc1        $f10, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f10.u32l;
    Matrix_MultVec3f(rdram, ctx);
        goto after_0;
    // 0x80053CDC: swc1        $f10, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f10.u32l;
    after_0:
    // 0x80053CE0: lui         $at, 0x4516
    ctx->r1 = S32(0X4516 << 16);
    // 0x80053CE4: lwc1        $f0, 0x48($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80053CE8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80053CEC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80053CF0: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80053CF4: add.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x80053CF8: addiu       $a2, $a2, 0x13EC
    ctx->r6 = ADD32(ctx->r6, 0X13EC);
    // 0x80053CFC: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80053D00: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x80053D04: jal         0x80006970
    // 0x80053D08: swc1        $f18, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f18.u32l;
    Matrix_MultVec3f(rdram, ctx);
        goto after_1;
    // 0x80053D08: swc1        $f18, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f18.u32l;
    after_1:
    // 0x80053D0C: lw          $a3, 0x58($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X58);
L_80053D10:
    // 0x80053D10: lw          $t2, 0x238($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X238);
L_80053D14:
    // 0x80053D14: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80053D18: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x80053D1C: beq         $t2, $zero, L_80053E08
    if (ctx->r10 == 0) {
        // 0x80053D20: lui         $t9, 0x8017
        ctx->r25 = S32(0X8017 << 16);
            goto L_80053E08;
    }
    // 0x80053D20: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x80053D24: lw          $t3, 0x7880($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7880);
    // 0x80053D28: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80053D2C: bne         $t3, $zero, L_80053E08
    if (ctx->r11 != 0) {
        // 0x80053D30: nop
    
            goto L_80053E08;
    }
    // 0x80053D30: nop

    // 0x80053D34: lwc1        $f4, 0x138($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X138);
    // 0x80053D38: lwc1        $f6, 0x7D20($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x80053D3C: lwc1        $f10, 0x48($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X48);
    // 0x80053D40: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80053D44: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80053D48: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80053D4C: lw          $t4, 0x5C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X5C);
    // 0x80053D50: sub.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80053D54: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80053D58: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x80053D5C: nop

    // 0x80053D60: bc1f        L_80053E08
    if (!c1cs) {
        // 0x80053D64: nop
    
            goto L_80053E08;
    }
    // 0x80053D64: nop

    // 0x80053D68: bne         $t4, $zero, L_80053F6C
    if (ctx->r12 != 0) {
        // 0x80053D6C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80053F6C;
    }
    // 0x80053D6C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80053D70: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80053D74: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80053D78: sw          $v0, -0x5DD8($at)
    MEM_W(-0X5DD8, ctx->r1) = ctx->r2;
    // 0x80053D7C: jal         0x80005708
    // 0x80053D80: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Push(rdram, ctx);
        goto after_2;
    // 0x80053D80: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_2:
    // 0x80053D84: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80053D88: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80053D8C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80053D90: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80053D94: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80053D98: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80053D9C: lui         $a2, 0xC100
    ctx->r6 = S32(0XC100 << 16);
    // 0x80053DA0: jal         0x80005B00
    // 0x80053DA4: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    Matrix_Translate(rdram, ctx);
        goto after_3;
    // 0x80053DA4: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    after_3:
    // 0x80053DA8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80053DAC: lui         $a1, 0x4049
    ctx->r5 = S32(0X4049 << 16);
    // 0x80053DB0: ori         $a1, $a1, 0xFDB
    ctx->r5 = ctx->r5 | 0XFDB;
    // 0x80053DB4: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80053DB8: jal         0x80005E90
    // 0x80053DBC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateY(rdram, ctx);
        goto after_4;
    // 0x80053DBC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
    // 0x80053DC0: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80053DC4: jal         0x80006EB8
    // 0x80053DC8: addiu       $a0, $a1, 0x7E64
    ctx->r4 = ADD32(ctx->r5, 0X7E64);
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_5;
    // 0x80053DC8: addiu       $a0, $a1, 0x7E64
    ctx->r4 = ADD32(ctx->r5, 0X7E64);
    after_5:
    // 0x80053DCC: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80053DD0: addiu       $a1, $a1, 0x7E64
    ctx->r5 = ADD32(ctx->r5, 0X7E64);
    // 0x80053DD4: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80053DD8: lui         $t8, 0x301
    ctx->r24 = S32(0X301 << 16);
    // 0x80053DDC: addiu       $t8, $t8, 0x31F0
    ctx->r24 = ADD32(ctx->r24, 0X31F0);
    // 0x80053DE0: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80053DE4: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x80053DE8: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80053DEC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80053DF0: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80053DF4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80053DF8: jal         0x80005740
    // 0x80053DFC: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Pop(rdram, ctx);
        goto after_6;
    // 0x80053DFC: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_6:
    // 0x80053E00: b           L_80053F70
    // 0x80053E04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80053F70;
    // 0x80053E04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80053E08:
    // 0x80053E08: lw          $t9, 0x78E8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X78E8);
    // 0x80053E0C: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x80053E10: addiu       $a0, $a3, 0x49C
    ctx->r4 = ADD32(ctx->r7, 0X49C);
    // 0x80053E14: beq         $t9, $zero, L_80053F1C
    if (ctx->r25 == 0) {
        // 0x80053E18: nop
    
            goto L_80053F1C;
    }
    // 0x80053E18: nop

    // 0x80053E1C: lbu         $v0, 0x49C($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X49C);
    // 0x80053E20: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x80053E24: bnel        $v1, $v0, L_80053E68
    if (ctx->r3 != ctx->r2) {
        // 0x80053E28: slti        $at, $v0, 0x2
        ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
            goto L_80053E68;
    }
    goto skip_1;
    // 0x80053E28: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    skip_1:
    // 0x80053E2C: lbu         $t0, 0x49D($a3)
    ctx->r8 = MEM_BU(ctx->r7, 0X49D);
    // 0x80053E30: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80053E34: addiu       $a1, $a1, 0x7E64
    ctx->r5 = ADD32(ctx->r5, 0X7E64);
    // 0x80053E38: bne         $v1, $t0, L_80053E64
    if (ctx->r3 != ctx->r8) {
        // 0x80053E3C: lui         $t2, 0x600
        ctx->r10 = S32(0X600 << 16);
            goto L_80053E64;
    }
    // 0x80053E3C: lui         $t2, 0x600
    ctx->r10 = S32(0X600 << 16);
    // 0x80053E40: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80053E44: lui         $t3, 0x301
    ctx->r11 = S32(0X301 << 16);
    // 0x80053E48: addiu       $t3, $t3, -0x1180
    ctx->r11 = ADD32(ctx->r11, -0X1180);
    // 0x80053E4C: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x80053E50: sw          $t1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r9;
    // 0x80053E54: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x80053E58: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x80053E5C: b           L_80053F70
    // 0x80053E60: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80053F70;
    // 0x80053E60: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80053E64:
    // 0x80053E64: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
L_80053E68:
    // 0x80053E68: beq         $at, $zero, L_80053EA8
    if (ctx->r1 == 0) {
        // 0x80053E6C: nop
    
            goto L_80053EA8;
    }
    // 0x80053E6C: nop

    // 0x80053E70: lbu         $t4, 0x49D($a3)
    ctx->r12 = MEM_BU(ctx->r7, 0X49D);
    // 0x80053E74: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80053E78: addiu       $a1, $a1, 0x7E64
    ctx->r5 = ADD32(ctx->r5, 0X7E64);
    // 0x80053E7C: bne         $v1, $t4, L_80053EA8
    if (ctx->r3 != ctx->r12) {
        // 0x80053E80: lui         $t6, 0x600
        ctx->r14 = S32(0X600 << 16);
            goto L_80053EA8;
    }
    // 0x80053E80: lui         $t6, 0x600
    ctx->r14 = S32(0X600 << 16);
    // 0x80053E84: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80053E88: lui         $t7, 0x301
    ctx->r15 = S32(0X301 << 16);
    // 0x80053E8C: addiu       $t7, $t7, 0xA90
    ctx->r15 = ADD32(ctx->r15, 0XA90);
    // 0x80053E90: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x80053E94: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
    // 0x80053E98: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80053E9C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80053EA0: b           L_80053F70
    // 0x80053EA4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80053F70;
    // 0x80053EA4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80053EA8:
    // 0x80053EA8: bne         $v1, $v0, L_80053EEC
    if (ctx->r3 != ctx->r2) {
        // 0x80053EAC: nop
    
            goto L_80053EEC;
    }
    // 0x80053EAC: nop

    // 0x80053EB0: lbu         $t8, 0x49D($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0X49D);
    // 0x80053EB4: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80053EB8: addiu       $a1, $a1, 0x7E64
    ctx->r5 = ADD32(ctx->r5, 0X7E64);
    // 0x80053EBC: slti        $at, $t8, 0x2
    ctx->r1 = SIGNED(ctx->r24) < 0X2 ? 1 : 0;
    // 0x80053EC0: beq         $at, $zero, L_80053EEC
    if (ctx->r1 == 0) {
        // 0x80053EC4: lui         $t0, 0x600
        ctx->r8 = S32(0X600 << 16);
            goto L_80053EEC;
    }
    // 0x80053EC4: lui         $t0, 0x600
    ctx->r8 = S32(0X600 << 16);
    // 0x80053EC8: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80053ECC: lui         $t1, 0x301
    ctx->r9 = S32(0X301 << 16);
    // 0x80053ED0: addiu       $t1, $t1, 0x1470
    ctx->r9 = ADD32(ctx->r9, 0X1470);
    // 0x80053ED4: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80053ED8: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x80053EDC: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x80053EE0: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x80053EE4: b           L_80053F70
    // 0x80053EE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80053F70;
    // 0x80053EE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80053EEC:
    // 0x80053EEC: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80053EF0: addiu       $a1, $a1, 0x7E64
    ctx->r5 = ADD32(ctx->r5, 0X7E64);
    // 0x80053EF4: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80053EF8: lui         $t4, 0x301
    ctx->r12 = S32(0X301 << 16);
    // 0x80053EFC: addiu       $t4, $t4, -0x2AB0
    ctx->r12 = ADD32(ctx->r12, -0X2AB0);
    // 0x80053F00: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x80053F04: sw          $t2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r10;
    // 0x80053F08: lui         $t3, 0x600
    ctx->r11 = S32(0X600 << 16);
    // 0x80053F0C: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80053F10: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80053F14: b           L_80053F70
    // 0x80053F18: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80053F70;
    // 0x80053F18: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80053F1C:
    // 0x80053F1C: lbu         $t5, 0x7C98($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0X7C98);
    // 0x80053F20: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80053F24: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80053F28: beql        $v0, $t5, L_80053F44
    if (ctx->r2 == ctx->r13) {
        // 0x80053F2C: swc1        $f2, 0x4AC($a3)
        MEM_W(0X4AC, ctx->r7) = ctx->f2.u32l;
            goto L_80053F44;
    }
    goto skip_2;
    // 0x80053F2C: swc1        $f2, 0x4AC($a3)
    MEM_W(0X4AC, ctx->r7) = ctx->f2.u32l;
    skip_2:
    // 0x80053F30: lw          $t6, -0x7DCC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7DCC);
    // 0x80053F34: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x80053F38: bne         $t6, $at, L_80053F54
    if (ctx->r14 != ctx->r1) {
        // 0x80053F3C: nop
    
            goto L_80053F54;
    }
    // 0x80053F3C: nop

    // 0x80053F40: swc1        $f2, 0x4AC($a3)
    MEM_W(0X4AC, ctx->r7) = ctx->f2.u32l;
L_80053F44:
    // 0x80053F44: swc1        $f2, 0x4A8($a3)
    MEM_W(0X4A8, ctx->r7) = ctx->f2.u32l;
    // 0x80053F48: swc1        $f2, 0x4A4($a3)
    MEM_W(0X4A4, ctx->r7) = ctx->f2.u32l;
    // 0x80053F4C: swc1        $f2, 0x4A0($a3)
    MEM_W(0X4A0, ctx->r7) = ctx->f2.u32l;
    // 0x80053F50: swc1        $f2, 0x4C4($a3)
    MEM_W(0X4C4, ctx->r7) = ctx->f2.u32l;
L_80053F54:
    // 0x80053F54: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80053F58: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    // 0x80053F5C: sw          $v0, -0x5DD4($at)
    MEM_W(-0X5DD4, ctx->r1) = ctx->r2;
    // 0x80053F60: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80053F64: jal         0x80053658
    // 0x80053F68: sh          $t7, 0x1410($at)
    MEM_H(0X1410, ctx->r1) = ctx->r15;
    Display_Arwing_Skel(rdram, ctx);
        goto after_7;
    // 0x80053F68: sh          $t7, 0x1410($at)
    MEM_H(0X1410, ctx->r1) = ctx->r15;
    after_7:
L_80053F6C:
    // 0x80053F6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80053F70:
    // 0x80053F70: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80053F74: jr          $ra
    // 0x80053F78: nop

    return;
    // 0x80053F78: nop

;}
RECOMP_FUNC void Cutscene_ArwingDown360(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004D828: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8004D82C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8004D830: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8004D834: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8004D838: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004D83C: lwc1        $f4, 0x5A6C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5A6C);
    // 0x8004D840: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8004D844: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8004D848: addiu       $a0, $s0, 0xE4
    ctx->r4 = ADD32(ctx->r16, 0XE4);
    // 0x8004D84C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8004D850: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8004D854: jal         0x8009BC2C
    // 0x8004D858: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_0;
    // 0x8004D858: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x8004D85C: lwc1        $f6, 0x74($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X74);
    // 0x8004D860: lwc1        $f8, 0xC0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC0);
    // 0x8004D864: lwc1        $f2, 0xC4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x8004D868: lwc1        $f16, 0x78($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X78);
    // 0x8004D86C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8004D870: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8004D874: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8004D878: add.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x8004D87C: swc1        $f10, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f10.u32l;
    // 0x8004D880: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8004D884: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x8004D888: swc1        $f18, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f18.u32l;
    // 0x8004D88C: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
    // 0x8004D890: bne         $v0, $at, L_8004D8A0
    if (ctx->r2 != ctx->r1) {
        // 0x8004D894: nop
    
            goto L_8004D8A0;
    }
    // 0x8004D894: nop

    // 0x8004D898: lw          $t6, -0x7D7C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7D7C);
    // 0x8004D89C: bne         $t6, $zero, L_8004D8DC
    if (ctx->r14 != 0) {
        // 0x8004D8A0: lui         $t7, 0x8017
        ctx->r15 = S32(0X8017 << 16);
            goto L_8004D8DC;
    }
L_8004D8A0:
    // 0x8004D8A0: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x8004D8A4: lbu         $t7, 0x7C98($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X7C98);
    // 0x8004D8A8: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x8004D8AC: beql        $t7, $zero, L_8004D8BC
    if (ctx->r15 == 0) {
        // 0x8004D8B0: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_8004D8BC;
    }
    goto skip_0;
    // 0x8004D8B0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    skip_0:
    // 0x8004D8B4: bne         $v0, $at, L_8004D8DC
    if (ctx->r2 != ctx->r1) {
        // 0x8004D8B8: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_8004D8DC;
    }
    // 0x8004D8B8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
L_8004D8BC:
    // 0x8004D8BC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8004D8C0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8004D8C4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8004D8C8: lwc1        $f8, 0xE4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XE4);
    // 0x8004D8CC: sub.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x8004D8D0: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8004D8D4: swc1        $f6, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f6.u32l;
    // 0x8004D8D8: swc1        $f16, 0xE4($s0)
    MEM_W(0XE4, ctx->r16) = ctx->f16.u32l;
L_8004D8DC:
    // 0x8004D8DC: lwc1        $f18, 0x7C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x8004D8E0: lwc1        $f4, 0xC8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x8004D8E4: lwc1        $f0, 0x12C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X12C);
    // 0x8004D8E8: lwc1        $f10, 0xEC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x8004D8EC: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8004D8F0: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x8004D8F4: lwc1        $f18, 0x130($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X130);
    // 0x8004D8F8: add.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x8004D8FC: swc1        $f6, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->f6.u32l;
    // 0x8004D900: lwc1        $f8, 0x7C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x8004D904: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8004D908: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8004D90C: swc1        $f8, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->f8.u32l;
    // 0x8004D910: lw          $t8, 0x1D0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X1D0);
    // 0x8004D914: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x8004D918: swc1        $f4, 0xF8($s0)
    MEM_W(0XF8, ctx->r16) = ctx->f4.u32l;
    // 0x8004D91C: lui         $at, 0x4130
    ctx->r1 = S32(0X4130 << 16);
    // 0x8004D920: beq         $t8, $zero, L_8004D94C
    if (ctx->r24 == 0) {
        // 0x8004D924: swc1        $f8, 0x12C($s0)
        MEM_W(0X12C, ctx->r16) = ctx->f8.u32l;
            goto L_8004D94C;
    }
    // 0x8004D924: swc1        $f8, 0x12C($s0)
    MEM_W(0X12C, ctx->r16) = ctx->f8.u32l;
    // 0x8004D928: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8004D92C: lui         $at, 0x4188
    ctx->r1 = S32(0X4188 << 16);
    // 0x8004D930: lwc1        $f10, 0xE8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XE8);
    // 0x8004D934: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8004D938: lwc1        $f4, 0xE4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XE4);
    // 0x8004D93C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8004D940: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8004D944: swc1        $f18, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f18.u32l;
    // 0x8004D948: swc1        $f8, 0xE4($s0)
    MEM_W(0XE4, ctx->r16) = ctx->f8.u32l;
L_8004D94C:
    // 0x8004D94C: lw          $t9, 0x78A8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X78A8);
    // 0x8004D950: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8004D954: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x8004D958: bne         $t9, $at, L_8004D9EC
    if (ctx->r25 != ctx->r1) {
        // 0x8004D95C: lui         $t2, 0x8017
        ctx->r10 = S32(0X8017 << 16);
            goto L_8004D9EC;
    }
    // 0x8004D95C: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x8004D960: lw          $t0, 0x7DB0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7DB0);
    // 0x8004D964: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x8004D968: bnel        $t1, $zero, L_8004DA94
    if (ctx->r9 != 0) {
        // 0x8004D96C: lwc1        $f14, 0x78($s0)
        ctx->f14.u32l = MEM_W(ctx->r16, 0X78);
            goto L_8004DA94;
    }
    goto skip_1;
    // 0x8004D96C: lwc1        $f14, 0x78($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X78);
    skip_1:
    // 0x8004D970: jal         0x80004EB0
    // 0x8004D974: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x8004D974: nop

    after_1:
    // 0x8004D978: jal         0x80004EB0
    // 0x8004D97C: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_2;
    // 0x8004D97C: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x8004D980: lui         $at, 0x4034
    ctx->r1 = S32(0X4034 << 16);
    // 0x8004D984: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x8004D988: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8004D98C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8004D990: lwc1        $f10, 0x3C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8004D994: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8004D998: lwc1        $f8, 0x74($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X74);
    // 0x8004D99C: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8004D9A0: lui         $a3, 0x400C
    ctx->r7 = S32(0X400C << 16);
    // 0x8004D9A4: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x8004D9A8: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8004D9AC: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x8004D9B0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8004D9B4: mul.d       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f2.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f2.d);
    // 0x8004D9B8: lw          $a2, 0x138($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X138);
    // 0x8004D9BC: sub.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x8004D9C0: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x8004D9C4: add.d       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f6.d + ctx->f10.d;
    // 0x8004D9C8: mul.d       $f6, $f8, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f2.d); 
    ctx->f6.d = MUL_D(ctx->f8.d, ctx->f2.d);
    // 0x8004D9CC: lwc1        $f10, 0x78($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X78);
    // 0x8004D9D0: cvt.s.d     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f12.fl = CVT_S_D(ctx->f16.d);
    // 0x8004D9D4: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8004D9D8: add.d       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f6.d + ctx->f16.d;
    // 0x8004D9DC: jal         0x8007D24C
    // 0x8004D9E0: cvt.s.d     $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f14.fl = CVT_S_D(ctx->f18.d);
    func_effect_8007D24C(rdram, ctx);
        goto after_3;
    // 0x8004D9E0: cvt.s.d     $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f14.fl = CVT_S_D(ctx->f18.d);
    after_3:
    // 0x8004D9E4: b           L_8004DA94
    // 0x8004D9E8: lwc1        $f14, 0x78($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X78);
        goto L_8004DA94;
    // 0x8004D9E8: lwc1        $f14, 0x78($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X78);
L_8004D9EC:
    // 0x8004D9EC: lw          $t2, 0x7DB0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7DB0);
    // 0x8004D9F0: andi        $t3, $t2, 0x3
    ctx->r11 = ctx->r10 & 0X3;
    // 0x8004D9F4: bnel        $t3, $zero, L_8004DA94
    if (ctx->r11 != 0) {
        // 0x8004D9F8: lwc1        $f14, 0x78($s0)
        ctx->f14.u32l = MEM_W(ctx->r16, 0X78);
            goto L_8004DA94;
    }
    goto skip_2;
    // 0x8004D9F8: lwc1        $f14, 0x78($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X78);
    skip_2:
    // 0x8004D9FC: jal         0x80004EB0
    // 0x8004DA00: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_4;
    // 0x8004DA00: nop

    after_4:
    // 0x8004DA04: jal         0x80004EB0
    // 0x8004DA08: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_5;
    // 0x8004DA08: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    after_5:
    // 0x8004DA0C: jal         0x80004EB0
    // 0x8004DA10: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_6;
    // 0x8004DA10: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    after_6:
    // 0x8004DA14: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8004DA18: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8004DA1C: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8004DA20: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8004DA24: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8004DA28: sub.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x8004DA2C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8004DA30: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8004DA34: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8004DA38: mul.s       $f16, $f10, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x8004DA3C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8004DA40: sub.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x8004DA44: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8004DA48: lwc1        $f18, 0x74($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X74);
    // 0x8004DA4C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8004DA50: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8004DA54: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8004DA58: mul.s       $f16, $f10, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x8004DA5C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8004DA60: sub.s       $f8, $f0, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x8004DA64: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8004DA68: lwc1        $f18, 0x78($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X78);
    // 0x8004DA6C: lui         $a3, 0x400C
    ctx->r7 = S32(0X400C << 16);
    // 0x8004DA70: mul.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8004DA74: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8004DA78: lwc1        $f16, 0x138($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X138);
    // 0x8004DA7C: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x8004DA80: add.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x8004DA84: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x8004DA88: jal         0x8007D10C
    // 0x8004DA8C: nop

    Effect_FireSmoke2_Spawn3(rdram, ctx);
        goto after_7;
    // 0x8004DA8C: nop

    after_7:
    // 0x8004DA90: lwc1        $f14, 0x78($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X78);
L_8004DA94:
    // 0x8004DA94: lwc1        $f0, 0xA4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XA4);
    // 0x8004DA98: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x8004DA9C: nop

    // 0x8004DAA0: bc1fl       L_8004DBA8
    if (!c1cs) {
        // 0x8004DAA4: lw          $t0, 0x220($s0)
        ctx->r8 = MEM_W(ctx->r16, 0X220);
            goto L_8004DBA8;
    }
    goto skip_3;
    // 0x8004DAA4: lw          $t0, 0x220($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X220);
    skip_3:
    // 0x8004DAA8: lw          $t4, 0x1D0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X1D0);
    // 0x8004DAAC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8004DAB0: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8004DAB4: bne         $t4, $zero, L_8004DBA4
    if (ctx->r12 != 0) {
        // 0x8004DAB8: addiu       $a0, $s0, 0x460
        ctx->r4 = ADD32(ctx->r16, 0X460);
            goto L_8004DBA4;
    }
    // 0x8004DAB8: addiu       $a0, $s0, 0x460
    ctx->r4 = ADD32(ctx->r16, 0X460);
    // 0x8004DABC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8004DAC0: swc1        $f0, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f0.u32l;
    // 0x8004DAC4: sw          $zero, 0x284($s0)
    MEM_W(0X284, ctx->r16) = 0;
    // 0x8004DAC8: sw          $zero, 0x220($s0)
    MEM_W(0X220, ctx->r16) = 0;
    // 0x8004DACC: sw          $t5, 0x1D0($s0)
    MEM_W(0X1D0, ctx->r16) = ctx->r13;
    // 0x8004DAD0: lui         $a1, 0x2900
    ctx->r5 = S32(0X2900 << 16);
    // 0x8004DAD4: jal         0x800A6070
    // 0x8004DAD8: swc1        $f4, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f4.u32l;
    Play_PlaySfxNoPlayer(rdram, ctx);
        goto after_8;
    // 0x8004DAD8: swc1        $f4, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f4.u32l;
    after_8:
    // 0x8004DADC: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8004DAE0: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
    // 0x8004DAE4: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x8004DAE8: beql        $v0, $zero, L_8004DAFC
    if (ctx->r2 == 0) {
        // 0x8004DAEC: lwc1        $f12, 0x74($s0)
        ctx->f12.u32l = MEM_W(ctx->r16, 0X74);
            goto L_8004DAFC;
    }
    goto skip_4;
    // 0x8004DAEC: lwc1        $f12, 0x74($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X74);
    skip_4:
    // 0x8004DAF0: bne         $v0, $at, L_8004DB0C
    if (ctx->r2 != ctx->r1) {
        // 0x8004DAF4: lui         $a3, 0x4040
        ctx->r7 = S32(0X4040 << 16);
            goto L_8004DB0C;
    }
    // 0x8004DAF4: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    // 0x8004DAF8: lwc1        $f12, 0x74($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X74);
L_8004DAFC:
    // 0x8004DAFC: jal         0x80062C38
    // 0x8004DB00: lwc1        $f14, 0x7C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X7C);
    Effect_Effect349_Spawn(rdram, ctx);
        goto after_9;
    // 0x8004DB00: lwc1        $f14, 0x7C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X7C);
    after_9:
    // 0x8004DB04: b           L_8004DB20
    // 0x8004DB08: lbu         $t6, 0x49C($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X49C);
        goto L_8004DB20;
    // 0x8004DB08: lbu         $t6, 0x49C($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X49C);
L_8004DB0C:
    // 0x8004DB0C: lwc1        $f12, 0x74($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X74);
    // 0x8004DB10: lwc1        $f14, 0x78($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X78);
    // 0x8004DB14: jal         0x8007D0E0
    // 0x8004DB18: lw          $a2, 0x138($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X138);
    Effect_FireSmoke1_Spawn4(rdram, ctx);
        goto after_10;
    // 0x8004DB18: lw          $a2, 0x138($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X138);
    after_10:
    // 0x8004DB1C: lbu         $t6, 0x49C($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X49C);
L_8004DB20:
    // 0x8004DB20: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8004DB24: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8004DB28: bnel        $t6, $at, L_8004DB60
    if (ctx->r14 != ctx->r1) {
        // 0x8004DB2C: lbu         $t8, 0x49D($s0)
        ctx->r24 = MEM_BU(ctx->r16, 0X49D);
            goto L_8004DB60;
    }
    goto skip_5;
    // 0x8004DB2C: lbu         $t8, 0x49D($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X49D);
    skip_5:
    // 0x8004DB30: lw          $a1, 0x2D4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X2D4);
    // 0x8004DB34: lw          $a2, 0x2D8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X2D8);
    // 0x8004DB38: jal         0x800A69F8
    // 0x8004DB3C: lw          $a3, 0x2DC($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X2DC);
    Play_SpawnDebris(rdram, ctx);
        goto after_11;
    // 0x8004DB3C: lw          $a3, 0x2DC($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X2DC);
    after_11:
    // 0x8004DB40: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8004DB44: sb          $t7, 0x49C($s0)
    MEM_B(0X49C, ctx->r16) = ctx->r15;
    // 0x8004DB48: lwc1        $f12, 0x2D4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X2D4);
    // 0x8004DB4C: lwc1        $f14, 0x2D8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X2D8);
    // 0x8004DB50: lw          $a2, 0x2DC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X2DC);
    // 0x8004DB54: jal         0x8007D0E0
    // 0x8004DB58: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    Effect_FireSmoke1_Spawn4(rdram, ctx);
        goto after_12;
    // 0x8004DB58: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    after_12:
    // 0x8004DB5C: lbu         $t8, 0x49D($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X49D);
L_8004DB60:
    // 0x8004DB60: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8004DB64: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8004DB68: bne         $t8, $at, L_8004DD20
    if (ctx->r24 != ctx->r1) {
        // 0x8004DB6C: nop
    
            goto L_8004DD20;
    }
    // 0x8004DB6C: nop

    // 0x8004DB70: lw          $a1, 0x2C8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X2C8);
    // 0x8004DB74: lw          $a2, 0x2CC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X2CC);
    // 0x8004DB78: jal         0x800A69F8
    // 0x8004DB7C: lw          $a3, 0x2D0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X2D0);
    Play_SpawnDebris(rdram, ctx);
        goto after_13;
    // 0x8004DB7C: lw          $a3, 0x2D0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X2D0);
    after_13:
    // 0x8004DB80: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8004DB84: sb          $t9, 0x49D($s0)
    MEM_B(0X49D, ctx->r16) = ctx->r25;
    // 0x8004DB88: lwc1        $f12, 0x2C8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X2C8);
    // 0x8004DB8C: lwc1        $f14, 0x2CC($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X2CC);
    // 0x8004DB90: lw          $a2, 0x2D0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X2D0);
    // 0x8004DB94: jal         0x8007D0E0
    // 0x8004DB98: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    Effect_FireSmoke1_Spawn4(rdram, ctx);
        goto after_14;
    // 0x8004DB98: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    after_14:
    // 0x8004DB9C: b           L_8004DD20
    // 0x8004DBA0: nop

        goto L_8004DD20;
    // 0x8004DBA0: nop

L_8004DBA4:
    // 0x8004DBA4: lw          $t0, 0x220($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X220);
L_8004DBA8:
    // 0x8004DBA8: bgtzl       $t0, L_8004DBE4
    if (SIGNED(ctx->r8) > 0) {
        // 0x8004DBAC: lw          $t2, 0x1F8($s0)
        ctx->r10 = MEM_W(ctx->r16, 0X1F8);
            goto L_8004DBE4;
    }
    goto skip_6;
    // 0x8004DBAC: lw          $t2, 0x1F8($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X1F8);
    skip_6:
    // 0x8004DBB0: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x8004DBB4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8004DBB8: bc1tl       L_8004DBE4
    if (c1cs) {
        // 0x8004DBBC: lw          $t2, 0x1F8($s0)
        ctx->r10 = MEM_W(ctx->r16, 0X1F8);
            goto L_8004DBE4;
    }
    goto skip_7;
    // 0x8004DBBC: lw          $t2, 0x1F8($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X1F8);
    skip_7:
    // 0x8004DBC0: lwc1        $f8, 0x7CC0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7CC0);
    // 0x8004DBC4: c.lt.s      $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f14.fl < ctx->f8.fl;
    // 0x8004DBC8: nop

    // 0x8004DBCC: bc1tl       L_8004DBE4
    if (c1cs) {
        // 0x8004DBD0: lw          $t2, 0x1F8($s0)
        ctx->r10 = MEM_W(ctx->r16, 0X1F8);
            goto L_8004DBE4;
    }
    goto skip_8;
    // 0x8004DBD0: lw          $t2, 0x1F8($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X1F8);
    skip_8:
    // 0x8004DBD4: lw          $t1, 0x1FC($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X1FC);
    // 0x8004DBD8: bne         $t1, $zero, L_8004DD20
    if (ctx->r9 != 0) {
        // 0x8004DBDC: nop
    
            goto L_8004DD20;
    }
    // 0x8004DBDC: nop

    // 0x8004DBE0: lw          $t2, 0x1F8($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X1F8);
L_8004DBE4:
    // 0x8004DBE4: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x8004DBE8: bne         $t2, $zero, L_8004DD20
    if (ctx->r10 != 0) {
        // 0x8004DBEC: nop
    
            goto L_8004DD20;
    }
    // 0x8004DBEC: nop

    // 0x8004DBF0: lw          $t3, 0x78A8($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X78A8);
    // 0x8004DBF4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8004DBF8: beq         $t3, $at, L_8004DC5C
    if (ctx->r11 == ctx->r1) {
        // 0x8004DBFC: nop
    
            goto L_8004DC5C;
    }
    // 0x8004DBFC: nop

    // 0x8004DC00: lw          $t4, 0x284($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X284);
    // 0x8004DC04: bnel        $t4, $zero, L_8004DC44
    if (ctx->r12 != 0) {
        // 0x8004DC08: c.lt.s      $f14, $f0
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
            goto L_8004DC44;
    }
    goto skip_9;
    // 0x8004DC08: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    skip_9:
    // 0x8004DC0C: lwc1        $f0, 0xC8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x8004DC10: lwc1        $f10, 0x138($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X138);
    // 0x8004DC14: lwc1        $f12, 0x74($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X74);
    // 0x8004DC18: add.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x8004DC1C: addiu       $t5, $zero, 0x50
    ctx->r13 = ADD32(0, 0X50);
    // 0x8004DC20: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8004DC24: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    // 0x8004DC28: sub.s       $f16, $f10, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x8004DC2C: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x8004DC30: jal         0x8007C688
    // 0x8004DC34: nop

    Effect_Effect387_Spawn(rdram, ctx);
        goto after_15;
    // 0x8004DC34: nop

    after_15:
    // 0x8004DC38: lwc1        $f14, 0x78($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X78);
    // 0x8004DC3C: lwc1        $f0, 0xA4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XA4);
    // 0x8004DC40: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
L_8004DC44:
    // 0x8004DC44: nop

    // 0x8004DC48: bc1f        L_8004DC5C
    if (!c1cs) {
        // 0x8004DC4C: nop
    
            goto L_8004DC5C;
    }
    // 0x8004DC4C: nop

    // 0x8004DC50: lwc1        $f12, 0x74($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X74);
    // 0x8004DC54: jal         0x80062C38
    // 0x8004DC58: lwc1        $f14, 0x7C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X7C);
    Effect_Effect349_Spawn(rdram, ctx);
        goto after_16;
    // 0x8004DC58: lwc1        $f14, 0x7C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X7C);
    after_16:
L_8004DC5C:
    // 0x8004DC5C: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x8004DC60: lbu         $t6, 0x7C98($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X7C98);
    // 0x8004DC64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8004DC68: bnel        $t6, $zero, L_8004DCD0
    if (ctx->r14 != 0) {
        // 0x8004DC6C: lwc1        $f12, 0x74($s0)
        ctx->f12.u32l = MEM_W(ctx->r16, 0X74);
            goto L_8004DCD0;
    }
    goto skip_10;
    // 0x8004DC6C: lwc1        $f12, 0x74($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X74);
    skip_10:
    // 0x8004DC70: lw          $a1, 0x74($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X74);
L_8004DC74:
    // 0x8004DC74: lw          $a2, 0x78($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X78);
    // 0x8004DC78: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    // 0x8004DC7C: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x8004DC80: jal         0x800A69F8
    // 0x8004DC84: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    Play_SpawnDebris(rdram, ctx);
        goto after_17;
    // 0x8004DC84: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_17:
    // 0x8004DC88: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
    // 0x8004DC8C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8004DC90: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x8004DC94: bnel        $at, $zero, L_8004DC74
    if (ctx->r1 != 0) {
        // 0x8004DC98: lw          $a1, 0x74($s0)
        ctx->r5 = MEM_W(ctx->r16, 0X74);
            goto L_8004DC74;
    }
    goto skip_11;
    // 0x8004DC98: lw          $a1, 0x74($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X74);
    skip_11:
    // 0x8004DC9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8004DCA0: lw          $a1, 0x74($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X74);
L_8004DCA4:
    // 0x8004DCA4: lw          $a2, 0x78($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X78);
    // 0x8004DCA8: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    // 0x8004DCAC: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x8004DCB0: jal         0x800A69F8
    // 0x8004DCB4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    Play_SpawnDebris(rdram, ctx);
        goto after_18;
    // 0x8004DCB4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_18:
    // 0x8004DCB8: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
    // 0x8004DCBC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8004DCC0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8004DCC4: bnel        $v0, $at, L_8004DCA4
    if (ctx->r2 != ctx->r1) {
        // 0x8004DCC8: lw          $a1, 0x74($s0)
        ctx->r5 = MEM_W(ctx->r16, 0X74);
            goto L_8004DCA4;
    }
    goto skip_12;
    // 0x8004DCC8: lw          $a1, 0x74($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X74);
    skip_12:
    // 0x8004DCCC: lwc1        $f12, 0x74($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X74);
L_8004DCD0:
    // 0x8004DCD0: lwc1        $f14, 0x78($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X78);
    // 0x8004DCD4: lw          $a2, 0x138($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X138);
    // 0x8004DCD8: jal         0x8007D0E0
    // 0x8004DCDC: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    Effect_FireSmoke1_Spawn4(rdram, ctx);
        goto after_19;
    // 0x8004DCDC: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    after_19:
    // 0x8004DCE0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8004DCE4: lwc1        $f12, 0x74($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X74);
    // 0x8004DCE8: lwc1        $f14, 0x78($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X78);
    // 0x8004DCEC: lw          $a2, 0x138($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X138);
    // 0x8004DCF0: lw          $a3, 0xC0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XC0);
    // 0x8004DCF4: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8004DCF8: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x8004DCFC: lwc1        $f4, 0xC8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x8004DD00: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8004DD04: addiu       $t7, $zero, 0x14
    ctx->r15 = ADD32(0, 0X14);
    // 0x8004DD08: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x8004DD0C: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x8004DD10: jal         0x8007BFFC
    // 0x8004DD14: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    Effect_Effect386_Spawn1(rdram, ctx);
        goto after_20;
    // 0x8004DD14: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    after_20:
    // 0x8004DD18: jal         0x8004D440
    // 0x8004DD1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Cutscene_KillPlayer(rdram, ctx);
        goto after_21;
    // 0x8004DD1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
L_8004DD20:
    // 0x8004DD20: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004DD24: lwc1        $f10, 0x5A70($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X5A70);
    // 0x8004DD28: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x8004DD2C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8004DD30: addiu       $a0, $s0, 0x34
    ctx->r4 = ADD32(ctx->r16, 0X34);
    // 0x8004DD34: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8004DD38: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x8004DD3C: jal         0x8009BC2C
    // 0x8004DD40: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_22;
    // 0x8004DD40: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_22:
    // 0x8004DD44: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004DD48: lwc1        $f16, 0x5A74($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X5A74);
    // 0x8004DD4C: lwc1        $f6, 0x134($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X134);
    // 0x8004DD50: lwc1        $f4, 0x114($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X114);
    // 0x8004DD54: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004DD58: mul.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x8004DD5C: lwc1        $f10, 0x5A78($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X5A78);
    // 0x8004DD60: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8004DD64: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8004DD68: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8004DD6C: add.s       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x8004DD70: mul.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8004DD74: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8004DD78: jal         0x80005E90
    // 0x8004DD7C: nop

    Matrix_RotateY(rdram, ctx);
        goto after_23;
    // 0x8004DD7C: nop

    after_23:
    // 0x8004DD80: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004DD84: lwc1        $f16, 0x5A7C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X5A7C);
    // 0x8004DD88: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x8004DD8C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8004DD90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8004DD94: lui         $a1, 0x442F
    ctx->r5 = S32(0X442F << 16);
    // 0x8004DD98: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x8004DD9C: jal         0x8009BC2C
    // 0x8004DDA0: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_24;
    // 0x8004DDA0: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_24:
    // 0x8004DDA4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004DDA8: lwc1        $f18, 0x5A80($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X5A80);
    // 0x8004DDAC: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8004DDB0: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8004DDB4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8004DDB8: mul.s       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x8004DDBC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8004DDC0: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x8004DDC4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8004DDC8: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8004DDCC: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x8004DDD0: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    // 0x8004DDD4: mul.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x8004DDD8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8004DDDC: swc1        $f6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f6.u32l;
    // 0x8004DDE0: lwc1        $f16, 0x0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8004DDE4: mul.s       $f18, $f16, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x8004DDE8: swc1        $f18, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f18.u32l;
    // 0x8004DDEC: lwc1        $f8, 0x8C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8C);
    // 0x8004DDF0: lwc1        $f16, 0x0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8004DDF4: sub.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x8004DDF8: add.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x8004DDFC: jal         0x80006970
    // 0x8004DE00: swc1        $f4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f4.u32l;
    Matrix_MultVec3f(rdram, ctx);
        goto after_25;
    // 0x8004DE00: swc1        $f4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f4.u32l;
    after_25:
    // 0x8004DE04: lwc1        $f0, 0x74($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X74);
    // 0x8004DE08: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8004DE0C: lwc1        $f2, 0x7C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x8004DE10: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x8004DE14: add.s       $f10, $f0, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f18.fl;
    // 0x8004DE18: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8004DE1C: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x8004DE20: swc1        $f10, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f10.u32l;
    // 0x8004DE24: lwc1        $f8, 0x4C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8004DE28: swc1        $f0, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f0.u32l;
    // 0x8004DE2C: swc1        $f2, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f2.u32l;
    // 0x8004DE30: add.s       $f16, $f2, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f2.fl + ctx->f8.fl;
    // 0x8004DE34: swc1        $f16, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f16.u32l;
    // 0x8004DE38: lbu         $t8, 0x7C98($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X7C98);
    // 0x8004DE3C: beql        $t8, $zero, L_8004DE5C
    if (ctx->r24 == 0) {
        // 0x8004DE40: lwc1        $f14, 0x78($s0)
        ctx->f14.u32l = MEM_W(ctx->r16, 0X78);
            goto L_8004DE5C;
    }
    goto skip_13;
    // 0x8004DE40: lwc1        $f14, 0x78($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X78);
    skip_13:
    // 0x8004DE44: lw          $t9, -0x7DCC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7DCC);
    // 0x8004DE48: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x8004DE4C: lwc1        $f16, 0x48($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8004DE50: bnel        $t9, $at, L_8004DEC4
    if (ctx->r25 != ctx->r1) {
        // 0x8004DE54: lwc1        $f14, 0x78($s0)
        ctx->f14.u32l = MEM_W(ctx->r16, 0X78);
            goto L_8004DEC4;
    }
    goto skip_14;
    // 0x8004DE54: lwc1        $f14, 0x78($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X78);
    skip_14:
    // 0x8004DE58: lwc1        $f14, 0x78($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X78);
L_8004DE5C:
    // 0x8004DE5C: lwc1        $f6, 0x148($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X148);
    // 0x8004DE60: lwc1        $f18, 0x48($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8004DE64: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8004DE68: mul.s       $f4, $f14, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f6.fl);
    // 0x8004DE6C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8004DE70: lwc1        $f8, 0x2C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8004DE74: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8004DE78: sub.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x8004DE7C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8004DE80: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8004DE84: add.s       $f10, $f4, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x8004DE88: swc1        $f10, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f10.u32l;
    // 0x8004DE8C: lwc1        $f4, 0x44($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X44);
    // 0x8004DE90: lwc1        $f10, 0x14C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14C);
    // 0x8004DE94: sub.s       $f18, $f4, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8004DE98: mul.s       $f8, $f14, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f10.fl);
    // 0x8004DE9C: lwc1        $f6, 0x60($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X60);
    // 0x8004DEA0: swc1        $f18, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f18.u32l;
    // 0x8004DEA4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8004DEA8: nop

    // 0x8004DEAC: mul.s       $f10, $f6, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x8004DEB0: add.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x8004DEB4: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8004DEB8: b           L_8004DED0
    // 0x8004DEBC: swc1        $f8, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f8.u32l;
        goto L_8004DED0;
    // 0x8004DEBC: swc1        $f8, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f8.u32l;
    // 0x8004DEC0: lwc1        $f14, 0x78($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X78);
L_8004DEC4:
    // 0x8004DEC4: add.s       $f6, $f14, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f14.fl + ctx->f16.fl;
    // 0x8004DEC8: swc1        $f14, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f14.u32l;
    // 0x8004DECC: swc1        $f6, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f6.u32l;
L_8004DED0:
    // 0x8004DED0: lw          $t0, 0x78E8($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X78E8);
    // 0x8004DED4: beql        $t0, $zero, L_8004DEE8
    if (ctx->r8 == 0) {
        // 0x8004DED8: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8004DEE8;
    }
    goto skip_15;
    // 0x8004DED8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_15:
    // 0x8004DEDC: jal         0x800AE278
    // 0x8004DEE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_CheckBounds360(rdram, ctx);
        goto after_26;
    // 0x8004DEE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_26:
    // 0x8004DEE4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8004DEE8:
    // 0x8004DEE8: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8004DEEC: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x8004DEF0: jr          $ra
    // 0x8004DEF4: nop

    return;
    // 0x8004DEF4: nop

;}
RECOMP_FUNC void HUD_ShieldGaugeEdgeLeft_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085618: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8008561C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80085620: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80085624: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80085628: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8008562C: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80085630: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80085634: lui         $a1, 0x100
    ctx->r5 = S32(0X100 << 16);
    // 0x80085638: addiu       $a1, $a1, 0x2280
    ctx->r5 = ADD32(ctx->r5, 0X2280);
    // 0x8008563C: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x80085640: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80085644: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    // 0x80085648: swc1        $f12, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f12.u32l;
    // 0x8008564C: swc1        $f14, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f14.u32l;
    // 0x80085650: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x80085654: jal         0x8009D994
    // 0x80085658: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_0;
    // 0x80085658: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x8008565C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80085660: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80085664: jr          $ra
    // 0x80085668: nop

    return;
    // 0x80085668: nop

;}
RECOMP_FUNC void HUD_VS_PlayerNumber_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008D7F4: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x8008D7F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008D7FC: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x8008D800: addiu       $t7, $t7, 0x2130
    ctx->r15 = ADD32(ctx->r15, 0X2130);
    // 0x8008D804: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x8008D808: lw          $t3, 0x4($t7)
    ctx->r11 = MEM_W(ctx->r15, 0X4);
    // 0x8008D80C: addiu       $t6, $sp, 0x68
    ctx->r14 = ADD32(ctx->r29, 0X68);
    // 0x8008D810: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x8008D814: sw          $t3, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r11;
    // 0x8008D818: lw          $t3, 0xC($t7)
    ctx->r11 = MEM_W(ctx->r15, 0XC);
    // 0x8008D81C: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x8008D820: lui         $t5, 0x800D
    ctx->r13 = S32(0X800D << 16);
    // 0x8008D824: addiu       $t5, $t5, 0x2140
    ctx->r13 = ADD32(ctx->r13, 0X2140);
    // 0x8008D828: sw          $t3, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r11;
    // 0x8008D82C: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x8008D830: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x8008D834: lw          $at, 0x0($t5)
    ctx->r1 = MEM_W(ctx->r13, 0X0);
    // 0x8008D838: addiu       $t4, $sp, 0x58
    ctx->r12 = ADD32(ctx->r29, 0X58);
    // 0x8008D83C: sw          $t6, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r14;
    // 0x8008D840: sw          $at, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r1;
    // 0x8008D844: lw          $at, 0x8($t5)
    ctx->r1 = MEM_W(ctx->r13, 0X8);
    // 0x8008D848: lw          $t6, 0xC($t5)
    ctx->r14 = MEM_W(ctx->r13, 0XC);
    // 0x8008D84C: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x8008D850: addiu       $t3, $t3, 0x2150
    ctx->r11 = ADD32(ctx->r11, 0X2150);
    // 0x8008D854: sw          $at, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r1;
    // 0x8008D858: sw          $t6, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->r14;
    // 0x8008D85C: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x8008D860: lw          $at, 0x0($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X0);
    // 0x8008D864: addiu       $t7, $sp, 0x48
    ctx->r15 = ADD32(ctx->r29, 0X48);
    // 0x8008D868: sw          $t4, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r12;
    // 0x8008D86C: sw          $at, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r1;
    // 0x8008D870: lw          $at, 0x8($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X8);
    // 0x8008D874: lw          $t4, 0xC($t3)
    ctx->r12 = MEM_W(ctx->r11, 0XC);
    // 0x8008D878: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8008D87C: addiu       $t6, $t6, 0x2160
    ctx->r14 = ADD32(ctx->r14, 0X2160);
    // 0x8008D880: sw          $at, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r1;
    // 0x8008D884: sw          $t4, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->r12;
    // 0x8008D888: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8008D88C: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x8008D890: addiu       $t5, $sp, 0x38
    ctx->r13 = ADD32(ctx->r29, 0X38);
    // 0x8008D894: sw          $t7, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r15;
    // 0x8008D898: sw          $at, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r1;
    // 0x8008D89C: lw          $at, 0x8($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X8);
    // 0x8008D8A0: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x8008D8A4: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x8008D8A8: addiu       $t4, $t4, 0x2170
    ctx->r12 = ADD32(ctx->r12, 0X2170);
    // 0x8008D8AC: sw          $at, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->r1;
    // 0x8008D8B0: sw          $t7, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->r15;
    // 0x8008D8B4: lw          $t5, 0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4);
    // 0x8008D8B8: lw          $at, 0x0($t4)
    ctx->r1 = MEM_W(ctx->r12, 0X0);
    // 0x8008D8BC: addiu       $t3, $sp, 0x28
    ctx->r11 = ADD32(ctx->r29, 0X28);
    // 0x8008D8C0: sw          $t5, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r13;
    // 0x8008D8C4: sw          $at, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r1;
    // 0x8008D8C8: lw          $at, 0x8($t4)
    ctx->r1 = MEM_W(ctx->r12, 0X8);
    // 0x8008D8CC: lw          $t5, 0xC($t4)
    ctx->r13 = MEM_W(ctx->r12, 0XC);
    // 0x8008D8D0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8008D8D4: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8008D8D8: addiu       $a1, $zero, 0x4E
    ctx->r5 = ADD32(0, 0X4E);
    // 0x8008D8DC: sw          $at, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r1;
    // 0x8008D8E0: jal         0x800B8DD0
    // 0x8008D8E4: sw          $t5, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->r13;
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x8008D8E4: sw          $t5, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->r13;
    after_0:
    // 0x8008D8E8: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x8008D8EC: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x8008D8F0: addiu       $t2, $t2, 0x7E64
    ctx->r10 = ADD32(ctx->r10, 0X7E64);
    // 0x8008D8F4: addiu       $t1, $t1, 0x78A0
    ctx->r9 = ADD32(ctx->r9, 0X78A0);
    // 0x8008D8F8: lw          $a3, 0x0($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X0);
    // 0x8008D8FC: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x8008D900: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x8008D904: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x8008D908: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x8008D90C: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x8008D910: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x8008D914: addu        $t8, $sp, $t9
    ctx->r24 = ADD32(ctx->r29, ctx->r25);
    // 0x8008D918: lw          $t8, 0x28($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X28);
    // 0x8008D91C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x8008D920: addu        $t5, $sp, $t9
    ctx->r13 = ADD32(ctx->r29, ctx->r25);
    // 0x8008D924: andi        $t3, $t8, 0xFF
    ctx->r11 = ctx->r24 & 0XFF;
    // 0x8008D928: addu        $t8, $sp, $v0
    ctx->r24 = ADD32(ctx->r29, ctx->r2);
    // 0x8008D92C: lw          $t8, 0x38($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X38);
    // 0x8008D930: lw          $t6, 0x48($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X48);
    // 0x8008D934: sll         $t4, $t3, 8
    ctx->r12 = S32(ctx->r11 << 8);
    // 0x8008D938: andi        $t3, $t8, 0xFF
    ctx->r11 = ctx->r24 & 0XFF;
    // 0x8008D93C: sll         $t7, $t6, 24
    ctx->r15 = S32(ctx->r14 << 24);
    // 0x8008D940: or          $t9, $t4, $t7
    ctx->r25 = ctx->r12 | ctx->r15;
    // 0x8008D944: sll         $t5, $t3, 16
    ctx->r13 = S32(ctx->r11 << 16);
    // 0x8008D948: or          $t6, $t9, $t5
    ctx->r14 = ctx->r25 | ctx->r13;
    // 0x8008D94C: ori         $t4, $t6, 0xFF
    ctx->r12 = ctx->r14 | 0XFF;
    // 0x8008D950: sw          $t4, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r12;
    // 0x8008D954: lw          $t0, 0x0($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X0);
    // 0x8008D958: sll         $v0, $t0, 2
    ctx->r2 = S32(ctx->r8 << 2);
    // 0x8008D95C: addu        $a0, $sp, $v0
    ctx->r4 = ADD32(ctx->r29, ctx->r2);
    // 0x8008D960: addu        $a1, $sp, $v0
    ctx->r5 = ADD32(ctx->r29, ctx->r2);
    // 0x8008D964: lw          $a1, 0x58($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X58);
    // 0x8008D968: lw          $a0, 0x68($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X68);
    // 0x8008D96C: jal         0x8009FC0C
    // 0x8008D970: addiu       $a2, $t0, 0x1
    ctx->r6 = ADD32(ctx->r8, 0X1);
    Graphics_DisplayHUDNumber(rdram, ctx);
        goto after_1;
    // 0x8008D970: addiu       $a2, $t0, 0x1
    ctx->r6 = ADD32(ctx->r8, 0X1);
    after_1:
    // 0x8008D974: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008D978: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // 0x8008D97C: jr          $ra
    // 0x8008D980: nop

    return;
    // 0x8008D980: nop

;}
RECOMP_FUNC void Background_DrawSun(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80040450: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80040454: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80040458: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x8004045C: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80040460: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80040464: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80040468: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8004046C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80040470: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80040474: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x80040478: lw          $v1, -0x7DCC($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7DCC);
    // 0x8004047C: lui         $a3, 0x8017
    ctx->r7 = S32(0X8017 << 16);
    // 0x80040480: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x80040484: beq         $v1, $at, L_8004092C
    if (ctx->r3 == ctx->r1) {
        // 0x80040488: lbu         $a3, 0x7C98($a3)
        ctx->r7 = MEM_BU(ctx->r7, 0X7C98);
            goto L_8004092C;
    }
    // 0x80040488: lbu         $a3, 0x7C98($a3)
    ctx->r7 = MEM_BU(ctx->r7, 0X7C98);
    // 0x8004048C: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x80040490: beq         $v1, $at, L_8004092C
    if (ctx->r3 == ctx->r1) {
        // 0x80040494: addiu       $at, $zero, 0x9
        ctx->r1 = ADD32(0, 0X9);
            goto L_8004092C;
    }
    // 0x80040494: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80040498: beq         $v1, $at, L_8004092C
    if (ctx->r3 == ctx->r1) {
        // 0x8004049C: addiu       $t0, $zero, 0x7
        ctx->r8 = ADD32(0, 0X7);
            goto L_8004092C;
    }
    // 0x8004049C: addiu       $t0, $zero, 0x7
    ctx->r8 = ADD32(0, 0X7);
    // 0x800404A0: beq         $t0, $v1, L_8004092C
    if (ctx->r8 == ctx->r3) {
        // 0x800404A4: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_8004092C;
    }
    // 0x800404A4: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800404A8: beq         $v1, $at, L_8004092C
    if (ctx->r3 == ctx->r1) {
        // 0x800404AC: lui         $t6, 0x8017
        ctx->r14 = S32(0X8017 << 16);
            goto L_8004092C;
    }
    // 0x800404AC: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x800404B0: lw          $t6, 0x78E8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X78E8);
    // 0x800404B4: lui         $s6, 0x8018
    ctx->r22 = S32(0X8018 << 16);
    // 0x800404B8: addiu       $s6, $s6, -0x7C80
    ctx->r22 = ADD32(ctx->r22, -0X7C80);
    // 0x800404BC: bne         $t6, $zero, L_8004092C
    if (ctx->r14 != 0) {
        // 0x800404C0: lui         $a1, 0x8017
        ctx->r5 = S32(0X8017 << 16);
            goto L_8004092C;
    }
    // 0x800404C0: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x800404C4: lw          $a1, 0x78A0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X78A0);
    // 0x800404C8: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x800404CC: addiu       $t7, $t7, -0x61B4
    ctx->r15 = ADD32(ctx->r15, -0X61B4);
    // 0x800404D0: sll         $s2, $a3, 2
    ctx->r18 = S32(ctx->r7 << 2);
    // 0x800404D4: sll         $a2, $a1, 2
    ctx->r6 = S32(ctx->r5 << 2);
    // 0x800404D8: addu        $v0, $s6, $a2
    ctx->r2 = ADD32(ctx->r22, ctx->r6);
    // 0x800404DC: addu        $s3, $s2, $t7
    ctx->r19 = ADD32(ctx->r18, ctx->r15);
    // 0x800404E0: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x800404E4: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800404E8: addiu       $t1, $zero, 0xD
    ctx->r9 = ADD32(0, 0XD);
    // 0x800404EC: lui         $s4, 0x8018
    ctx->r20 = S32(0X8018 << 16);
    // 0x800404F0: subu        $t2, $t8, $t9
    ctx->r10 = SUB32(ctx->r24, ctx->r25);
    // 0x800404F4: sltiu       $at, $t2, 0x12D
    ctx->r1 = ctx->r10 < 0X12D ? 1 : 0;
    // 0x800404F8: bne         $at, $zero, L_80040504
    if (ctx->r1 != 0) {
        // 0x800404FC: sw          $t2, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r10;
            goto L_80040504;
    }
    // 0x800404FC: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x80040500: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
L_80040504:
    // 0x80040504: bne         $t1, $v1, L_8004051C
    if (ctx->r9 != ctx->r3) {
        // 0x80040508: addiu       $s4, $s4, -0x7D80
        ctx->r20 = ADD32(ctx->r20, -0X7D80);
            goto L_8004051C;
    }
    // 0x80040508: addiu       $s4, $s4, -0x7D80
    ctx->r20 = ADD32(ctx->r20, -0X7D80);
    // 0x8004050C: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x80040510: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80040514: lw          $t4, 0x1C8($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X1C8);
    // 0x80040518: beq         $t4, $at, L_8004057C
    if (ctx->r12 == ctx->r1) {
        // 0x8004051C: addiu       $s5, $zero, 0x4E0
        ctx->r21 = ADD32(0, 0X4E0);
            goto L_8004057C;
    }
L_8004051C:
    // 0x8004051C: addiu       $s5, $zero, 0x4E0
    ctx->r21 = ADD32(0, 0X4E0);
    // 0x80040520: multu       $a1, $s5
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80040524: lui         $s4, 0x8018
    ctx->r20 = S32(0X8018 << 16);
    // 0x80040528: addiu       $s4, $s4, -0x7D80
    ctx->r20 = ADD32(ctx->r20, -0X7D80);
    // 0x8004052C: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x80040530: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80040534: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x80040538: mflo        $t5
    ctx->r13 = lo;
    // 0x8004053C: addu        $t6, $a0, $t5
    ctx->r14 = ADD32(ctx->r4, ctx->r13);
    // 0x80040540: lw          $v0, 0x1C8($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X1C8);
    // 0x80040544: beq         $v0, $at, L_80040564
    if (ctx->r2 == ctx->r1) {
        // 0x80040548: nop
    
            goto L_80040564;
    }
    // 0x80040548: nop

    // 0x8004054C: lw          $t7, 0x7880($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7880);
    // 0x80040550: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80040554: beq         $t7, $at, L_80040564
    if (ctx->r15 == ctx->r1) {
        // 0x80040558: nop
    
            goto L_80040564;
    }
    // 0x80040558: nop

    // 0x8004055C: bnel        $t0, $v0, L_80040788
    if (ctx->r8 != ctx->r2) {
        // 0x80040560: sll         $t8, $a1, 2
        ctx->r24 = S32(ctx->r5 << 2);
            goto L_80040788;
    }
    goto skip_0;
    // 0x80040560: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    skip_0:
L_80040564:
    // 0x80040564: bne         $a3, $zero, L_80040784
    if (ctx->r7 != 0) {
        // 0x80040568: addiu       $at, $zero, 0xC
        ctx->r1 = ADD32(0, 0XC);
            goto L_80040784;
    }
    // 0x80040568: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8004056C: beql        $v1, $at, L_80040788
    if (ctx->r3 == ctx->r1) {
        // 0x80040570: sll         $t8, $a1, 2
        ctx->r24 = S32(ctx->r5 << 2);
            goto L_80040788;
    }
    goto skip_1;
    // 0x80040570: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    skip_1:
    // 0x80040574: beql        $t1, $v1, L_80040788
    if (ctx->r9 == ctx->r3) {
        // 0x80040578: sll         $t8, $a1, 2
        ctx->r24 = S32(ctx->r5 << 2);
            goto L_80040788;
    }
    goto skip_2;
    // 0x80040578: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    skip_2:
L_8004057C:
    // 0x8004057C: addiu       $s5, $zero, 0x4E0
    ctx->r21 = ADD32(0, 0X4E0);
    // 0x80040580: multu       $a1, $s5
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80040584: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80040588: addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
    // 0x8004058C: addu        $at, $at, $a2
    ctx->r1 = ADD32(ctx->r1, ctx->r6);
    // 0x80040590: sw          $v0, -0x7C70($at)
    MEM_W(-0X7C70, ctx->r1) = ctx->r2;
    // 0x80040594: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80040598: addu        $at, $at, $a2
    ctx->r1 = ADD32(ctx->r1, ctx->r6);
    // 0x8004059C: sw          $v0, -0x7C60($at)
    MEM_W(-0X7C60, ctx->r1) = ctx->r2;
    // 0x800405A0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800405A4: addu        $at, $at, $a2
    ctx->r1 = ADD32(ctx->r1, ctx->r6);
    // 0x800405A8: mflo        $t8
    ctx->r24 = lo;
    // 0x800405AC: sw          $v0, -0x7C50($at)
    MEM_W(-0X7C50, ctx->r1) = ctx->r2;
    // 0x800405B0: addu        $t9, $a0, $t8
    ctx->r25 = ADD32(ctx->r4, ctx->r24);
    // 0x800405B4: jal         0x8009F768
    // 0x800405B8: lwc1        $f12, 0x58($t9)
    ctx->f12.u32l = MEM_W(ctx->r25, 0X58);
    Math_RadToDeg(rdram, ctx);
        goto after_0;
    // 0x800405B8: lwc1        $f12, 0x58($t9)
    ctx->f12.u32l = MEM_W(ctx->r25, 0X58);
    after_0:
    // 0x800405BC: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x800405C0: lw          $t3, 0x78A0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X78A0);
    // 0x800405C4: lw          $t2, 0x0($s4)
    ctx->r10 = MEM_W(ctx->r20, 0X0);
    // 0x800405C8: multu       $t3, $s5
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800405CC: mflo        $t4
    ctx->r12 = lo;
    // 0x800405D0: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x800405D4: lwc1        $f12, 0x5C($t5)
    ctx->f12.u32l = MEM_W(ctx->r13, 0X5C);
    // 0x800405D8: jal         0x8009F768
    // 0x800405DC: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    Math_RadToDeg(rdram, ctx);
        goto after_1;
    // 0x800405DC: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x800405E0: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x800405E4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800405E8: lwc1        $f2, 0x44($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800405EC: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x800405F0: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x800405F4: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x800405F8: bc1f        L_8004060C
    if (!c1cs) {
        // 0x800405FC: nop
    
            goto L_8004060C;
    }
    // 0x800405FC: nop

    // 0x80040600: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80040604: nop

    // 0x80040608: sub.s       $f12, $f0, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f6.fl;
L_8004060C:
    // 0x8004060C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80040610: lwc1        $f0, 0x54EC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X54EC);
    // 0x80040614: lui         $at, 0x4307
    ctx->r1 = S32(0X4307 << 16);
    // 0x80040618: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8004061C: lui         $s1, 0x8018
    ctx->r17 = S32(0X8018 << 16);
    // 0x80040620: addiu       $s1, $s1, -0x7C30
    ctx->r17 = ADD32(ctx->r17, -0X7C30);
    // 0x80040624: sub.s       $f2, $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f8.fl;
    // 0x80040628: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x8004062C: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x80040630: neg.s       $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = -ctx->f12.fl;
    // 0x80040634: neg.s       $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = -ctx->f2.fl;
    // 0x80040638: lui         $at, 0x4302
    ctx->r1 = S32(0X4302 << 16);
    // 0x8004063C: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80040640: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80040644: lui         $at, 0x43AF
    ctx->r1 = S32(0X43AF << 16);
    // 0x80040648: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8004064C: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x80040650: addiu       $s0, $s0, -0x7C2C
    ctx->r16 = ADD32(ctx->r16, -0X7C2C);
    // 0x80040654: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x80040658: swc1        $f16, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f16.u32l;
    // 0x8004065C: lw          $a1, 0x78A0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X78A0);
    // 0x80040660: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80040664: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80040668: multu       $a1, $s5
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004066C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80040670: lwc1        $f4, 0x54F0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X54F0);
    // 0x80040674: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x80040678: mflo        $t6
    ctx->r14 = lo;
    // 0x8004067C: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x80040680: lwc1        $f10, 0x44($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X44);
    // 0x80040684: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80040688: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8004068C: sub.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x80040690: swc1        $f10, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f10.u32l;
    // 0x80040694: lw          $v1, -0x7DCC($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7DCC);
    // 0x80040698: bne         $v1, $at, L_800406B0
    if (ctx->r3 != ctx->r1) {
        // 0x8004069C: lui         $at, 0x42A0
        ctx->r1 = S32(0X42A0 << 16);
            goto L_800406B0;
    }
    // 0x8004069C: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x800406A0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800406A4: lwc1        $f16, 0x0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800406A8: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800406AC: swc1        $f4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f4.u32l;
L_800406B0:
    // 0x800406B0: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x800406B4: bnel        $v1, $at, L_80040708
    if (ctx->r3 != ctx->r1) {
        // 0x800406B8: lui         $at, 0x42F0
        ctx->r1 = S32(0X42F0 << 16);
            goto L_80040708;
    }
    goto skip_3;
    // 0x800406B8: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    skip_3:
    // 0x800406BC: lw          $t8, 0x1D0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X1D0);
    // 0x800406C0: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x800406C4: slti        $at, $t8, 0x2
    ctx->r1 = SIGNED(ctx->r24) < 0X2 ? 1 : 0;
    // 0x800406C8: bnel        $at, $zero, L_80040708
    if (ctx->r1 != 0) {
        // 0x800406CC: lui         $at, 0x42F0
        ctx->r1 = S32(0X42F0 << 16);
            goto L_80040708;
    }
    goto skip_4;
    // 0x800406CC: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    skip_4:
    // 0x800406D0: lbu         $t9, 0x1684($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X1684);
    // 0x800406D4: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x800406D8: bnel        $t9, $zero, L_80040708
    if (ctx->r25 != 0) {
        // 0x800406DC: lui         $at, 0x42F0
        ctx->r1 = S32(0X42F0 << 16);
            goto L_80040708;
    }
    goto skip_5;
    // 0x800406DC: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    skip_5:
    // 0x800406E0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800406E4: lui         $at, 0x43F0
    ctx->r1 = S32(0X43F0 << 16);
    // 0x800406E8: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800406EC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800406F0: lwc1        $f16, 0x0($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X0);
    // 0x800406F4: sub.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x800406F8: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800406FC: swc1        $f10, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f10.u32l;
    // 0x80040700: swc1        $f4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f4.u32l;
    // 0x80040704: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
L_80040708:
    // 0x80040708: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8004070C: lwc1        $f0, 0x0($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80040710: lui         $at, 0xC2F0
    ctx->r1 = S32(0XC2F0 << 16);
    // 0x80040714: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80040718: nop

    // 0x8004071C: bc1fl       L_80040788
    if (!c1cs) {
        // 0x80040720: sll         $t8, $a1, 2
        ctx->r24 = S32(ctx->r5 << 2);
            goto L_80040788;
    }
    goto skip_6;
    // 0x80040720: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    skip_6:
    // 0x80040724: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80040728: nop

    // 0x8004072C: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x80040730: nop

    // 0x80040734: bc1fl       L_80040788
    if (!c1cs) {
        // 0x80040738: sll         $t8, $a1, 2
        ctx->r24 = S32(ctx->r5 << 2);
            goto L_80040788;
    }
    goto skip_7;
    // 0x80040738: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    skip_7:
    // 0x8004073C: lwc1        $f6, 0x0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80040740: sll         $t3, $a1, 2
    ctx->r11 = S32(ctx->r5 << 2);
    // 0x80040744: addu        $v0, $s6, $t3
    ctx->r2 = ADD32(ctx->r22, ctx->r11);
    // 0x80040748: c.lt.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl < ctx->f2.fl;
    // 0x8004074C: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80040750: bc1fl       L_80040788
    if (!c1cs) {
        // 0x80040754: sll         $t8, $a1, 2
        ctx->r24 = S32(ctx->r5 << 2);
            goto L_80040788;
    }
    goto skip_8;
    // 0x80040754: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    skip_8:
    // 0x80040758: lw          $t4, 0x0($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X0);
    // 0x8004075C: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x80040760: addu        $v1, $v1, $s2
    ctx->r3 = ADD32(ctx->r3, ctx->r18);
    // 0x80040764: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x80040768: addu        $t6, $t2, $t5
    ctx->r14 = ADD32(ctx->r10, ctx->r13);
    // 0x8004076C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80040770: lw          $v1, -0x61AC($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X61AC);
    // 0x80040774: sltu        $at, $v1, $t6
    ctx->r1 = ctx->r3 < ctx->r14 ? 1 : 0;
    // 0x80040778: beql        $at, $zero, L_80040788
    if (ctx->r1 == 0) {
        // 0x8004077C: sll         $t8, $a1, 2
        ctx->r24 = S32(ctx->r5 << 2);
            goto L_80040788;
    }
    goto skip_9;
    // 0x8004077C: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    skip_9:
    // 0x80040780: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
L_80040784:
    // 0x80040784: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
L_80040788:
    // 0x80040788: addu        $t9, $s6, $t8
    ctx->r25 = ADD32(ctx->r22, ctx->r24);
    // 0x8004078C: lw          $t3, 0x0($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X0);
    // 0x80040790: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x80040794: lui         $s1, 0x8018
    ctx->r17 = S32(0X8018 << 16);
    // 0x80040798: addiu       $s1, $s1, -0x7C30
    ctx->r17 = ADD32(ctx->r17, -0X7C30);
    // 0x8004079C: beq         $t3, $zero, L_8004092C
    if (ctx->r11 == 0) {
        // 0x800407A0: addiu       $s0, $s0, -0x7C2C
        ctx->r16 = ADD32(ctx->r16, -0X7C2C);
            goto L_8004092C;
    }
    // 0x800407A0: addiu       $s0, $s0, -0x7C2C
    ctx->r16 = ADD32(ctx->r16, -0X7C2C);
    // 0x800407A4: lui         $s6, 0x8014
    ctx->r22 = S32(0X8014 << 16);
    // 0x800407A8: addiu       $s6, $s6, -0x4C40
    ctx->r22 = ADD32(ctx->r22, -0X4C40);
    // 0x800407AC: jal         0x80005708
    // 0x800407B0: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    Matrix_Push(rdram, ctx);
        goto after_2;
    // 0x800407B0: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_2:
    // 0x800407B4: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x800407B8: lw          $t2, 0x78A0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X78A0);
    // 0x800407BC: lw          $t4, 0x0($s4)
    ctx->r12 = MEM_W(ctx->r20, 0X0);
    // 0x800407C0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800407C4: multu       $t2, $s5
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800407C8: lwc1        $f16, 0x54F4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X54F4);
    // 0x800407CC: lw          $a0, 0x0($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X0);
    // 0x800407D0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800407D4: mflo        $t5
    ctx->r13 = lo;
    // 0x800407D8: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x800407DC: lwc1        $f10, 0x34($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X34);
    // 0x800407E0: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800407E4: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x800407E8: jal         0x80005FE0
    // 0x800407EC: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_3;
    // 0x800407EC: nop

    after_3:
    // 0x800407F0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800407F4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800407F8: lw          $a0, 0x0($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X0);
    // 0x800407FC: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x80040800: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    // 0x80040804: jal         0x80005B00
    // 0x80040808: lui         $a3, 0xC348
    ctx->r7 = S32(0XC348 << 16);
    Matrix_Translate(rdram, ctx);
        goto after_4;
    // 0x80040808: lui         $a3, 0xC348
    ctx->r7 = S32(0XC348 << 16);
    after_4:
    // 0x8004080C: jal         0x800B94A0
    // 0x80040810: nop

    RCP_SetupDL_62(rdram, ctx);
        goto after_5;
    // 0x80040810: nop

    after_5:
    // 0x80040814: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80040818: lw          $t8, -0x7DCC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7DCC);
    // 0x8004081C: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    // 0x80040820: lui         $s2, 0x800D
    ctx->r18 = S32(0X800D << 16);
    // 0x80040824: lui         $s3, 0x800D
    ctx->r19 = S32(0X800D << 16);
    // 0x80040828: lui         $s4, 0x800D
    ctx->r20 = S32(0X800D << 16);
    // 0x8004082C: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x80040830: addiu       $s1, $s1, -0x626C
    ctx->r17 = ADD32(ctx->r17, -0X626C);
    // 0x80040834: addiu       $s2, $s2, -0x621C
    ctx->r18 = ADD32(ctx->r18, -0X621C);
    // 0x80040838: addiu       $s3, $s3, -0x63A4
    ctx->r19 = ADD32(ctx->r19, -0X63A4);
    // 0x8004083C: bne         $t8, $at, L_80040864
    if (ctx->r24 != ctx->r1) {
        // 0x80040840: addiu       $s4, $s4, -0x62D4
        ctx->r20 = ADD32(ctx->r20, -0X62D4);
            goto L_80040864;
    }
    // 0x80040840: addiu       $s4, $s4, -0x62D4
    ctx->r20 = ADD32(ctx->r20, -0X62D4);
    // 0x80040844: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    // 0x80040848: lui         $s2, 0x800D
    ctx->r18 = S32(0X800D << 16);
    // 0x8004084C: lui         $s3, 0x800D
    ctx->r19 = S32(0X800D << 16);
    // 0x80040850: lui         $s4, 0x800D
    ctx->r20 = S32(0X800D << 16);
    // 0x80040854: addiu       $s1, $s1, -0x6244
    ctx->r17 = ADD32(ctx->r17, -0X6244);
    // 0x80040858: addiu       $s2, $s2, -0x61E8
    ctx->r18 = ADD32(ctx->r18, -0X61E8);
    // 0x8004085C: addiu       $s3, $s3, -0x6370
    ctx->r19 = ADD32(ctx->r19, -0X6370);
    // 0x80040860: addiu       $s4, $s4, -0x62A0
    ctx->r20 = ADD32(ctx->r20, -0X62A0);
L_80040864:
    // 0x80040864: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80040868: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x8004086C: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
L_80040870:
    // 0x80040870: jal         0x80005708
    // 0x80040874: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    Matrix_Push(rdram, ctx);
        goto after_6;
    // 0x80040874: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_6:
    // 0x80040878: lwc1        $f0, 0x0($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X0);
    // 0x8004087C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80040880: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80040884: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80040888: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8004088C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80040890: jal         0x80005C34
    // 0x80040894: lw          $a0, 0x0($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_7;
    // 0x80040894: lw          $a0, 0x0($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X0);
    after_7:
    // 0x80040898: jal         0x80006EB8
    // 0x8004089C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_8;
    // 0x8004089C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x800408A0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800408A4: lui         $t2, 0xFA00
    ctx->r10 = S32(0XFA00 << 16);
    // 0x800408A8: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x800408AC: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x800408B0: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x800408B4: lbu         $t7, 0x0($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X0);
    // 0x800408B8: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    // 0x800408BC: lbu         $t2, 0x1($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X1);
    // 0x800408C0: sll         $t8, $t7, 24
    ctx->r24 = S32(ctx->r15 << 24);
    // 0x800408C4: andi        $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 & 0XFF;
    // 0x800408C8: or          $t9, $t5, $t8
    ctx->r25 = ctx->r13 | ctx->r24;
    // 0x800408CC: lbu         $t5, 0x2($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0X2);
    // 0x800408D0: sll         $t4, $t2, 16
    ctx->r12 = S32(ctx->r10 << 16);
    // 0x800408D4: or          $t6, $t9, $t4
    ctx->r14 = ctx->r25 | ctx->r12;
    // 0x800408D8: sll         $t8, $t5, 8
    ctx->r24 = S32(ctx->r13 << 8);
    // 0x800408DC: or          $t3, $t6, $t8
    ctx->r11 = ctx->r14 | ctx->r24;
    // 0x800408E0: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x800408E4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800408E8: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x800408EC: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x800408F0: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x800408F4: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800408F8: lw          $t4, 0x0($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X0);
    // 0x800408FC: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80040900: jal         0x80005740
    // 0x80040904: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_9;
    // 0x80040904: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_9:
    // 0x80040908: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x8004090C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80040910: addiu       $s1, $s1, 0x3
    ctx->r17 = ADD32(ctx->r17, 0X3);
    // 0x80040914: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80040918: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x8004091C: bne         $s5, $at, L_80040870
    if (ctx->r21 != ctx->r1) {
        // 0x80040920: addiu       $s4, $s4, 0x4
        ctx->r20 = ADD32(ctx->r20, 0X4);
            goto L_80040870;
    }
    // 0x80040920: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x80040924: jal         0x80005740
    // 0x80040928: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_10;
    // 0x80040928: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_10:
L_8004092C:
    // 0x8004092C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80040930: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80040934: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80040938: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8004093C: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80040940: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80040944: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80040948: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8004094C: jr          $ra
    // 0x80040950: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80040950: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void __nearbyintf_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001FF40: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8001FF44: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8001FF48: nop

    // 0x8001FF4C: add.s       $f0, $f12, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f12.fl + ctx->f4.fl;
    // 0x8001FF50: floor.w.s   $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.u32l = S32(floorf(ctx->f0.fl));
    // 0x8001FF54: jr          $ra
    // 0x8001FF58: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    return;
    // 0x8001FF58: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
;}
RECOMP_FUNC void Sprite_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069E88: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80069E8C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80069E90: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80069E94: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80069E98: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x80069E9C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80069EA0: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80069EA4: beq         $v0, $at, L_80069EC4
    if (ctx->r2 == ctx->r1) {
        // 0x80069EA8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80069EC4;
    }
    // 0x80069EA8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80069EAC: beq         $v0, $at, L_80069EE4
    if (ctx->r2 == ctx->r1) {
        // 0x80069EB0: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80069EE4;
    }
    // 0x80069EB0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80069EB4: beq         $v0, $at, L_80069F08
    if (ctx->r2 == ctx->r1) {
        // 0x80069EB8: nop
    
            goto L_80069F08;
    }
    // 0x80069EB8: nop

    // 0x80069EBC: b           L_80069F20
    // 0x80069EC0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80069F20;
    // 0x80069EC0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80069EC4:
    // 0x80069EC4: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
    // 0x80069EC8: lw          $a0, 0x40($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X40);
    // 0x80069ECC: jal         0x80063F90
    // 0x80069ED0: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    Object_Init(rdram, ctx);
        goto after_0;
    // 0x80069ED0: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    after_0:
    // 0x80069ED4: jal         0x80069858
    // 0x80069ED8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Sprite_Move(rdram, ctx);
        goto after_1;
    // 0x80069ED8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80069EDC: b           L_80069F20
    // 0x80069EE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80069F20;
    // 0x80069EE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80069EE4:
    // 0x80069EE4: jal         0x80069858
    // 0x80069EE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Sprite_Move(rdram, ctx);
        goto after_2;
    // 0x80069EE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80069EEC: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x80069EF0: beql        $v0, $zero, L_80069F20
    if (ctx->r2 == 0) {
        // 0x80069EF4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80069F20;
    }
    goto skip_0;
    // 0x80069EF4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80069EF8: jalr        $v0
    // 0x80069EFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_3;
    // 0x80069EFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80069F00: b           L_80069F20
    // 0x80069F04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80069F20;
    // 0x80069F04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80069F08:
    // 0x80069F08: jal         0x80069858
    // 0x80069F0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Sprite_Move(rdram, ctx);
        goto after_4;
    // 0x80069F0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80069F10: lw          $a0, 0x40($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X40);
    // 0x80069F14: jal         0x800690D0
    // 0x80069F18: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    Object_Dying(rdram, ctx);
        goto after_5;
    // 0x80069F18: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    after_5:
    // 0x80069F1C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80069F20:
    // 0x80069F20: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80069F24: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80069F28: jr          $ra
    // 0x80069F2C: nop

    return;
    // 0x80069F2C: nop

;}
RECOMP_FUNC void Audio_GetSfxFreqMod(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016EE4: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x80016EE8: andi        $t7, $a1, 0xFF
    ctx->r15 = ctx->r5 & 0XFF;
    // 0x80016EEC: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x80016EF0: sll         $t8, $t6, 4
    ctx->r24 = S32(ctx->r14 << 4);
    // 0x80016EF4: subu        $t8, $t8, $t6
    ctx->r24 = SUB32(ctx->r24, ctx->r14);
    // 0x80016EF8: subu        $t9, $t9, $t7
    ctx->r25 = SUB32(ctx->r25, ctx->r15);
    // 0x80016EFC: sll         $t9, $t9, 4
    ctx->r25 = S32(ctx->r25 << 4);
    // 0x80016F00: sll         $t8, $t8, 6
    ctx->r24 = S32(ctx->r24 << 6);
    // 0x80016F04: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x80016F08: addiu       $t1, $t1, -0x79A0
    ctx->r9 = ADD32(ctx->r9, -0X79A0);
    // 0x80016F0C: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80016F10: addu        $v0, $t0, $t1
    ctx->r2 = ADD32(ctx->r8, ctx->r9);
    // 0x80016F14: lw          $v1, 0x24($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X24);
    // 0x80016F18: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80016F1C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80016F20: sll         $t2, $v1, 8
    ctx->r10 = S32(ctx->r3 << 8);
    // 0x80016F24: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80016F28: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80016F2C: bgez        $t2, L_80016F70
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80016F30: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_80016F70;
    }
    // 0x80016F30: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80016F34: lui         $t3, 0x8015
    ctx->r11 = S32(0X8015 << 16);
    // 0x80016F38: lw          $t3, 0x5D84($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X5D84);
    // 0x80016F3C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80016F40: andi        $t4, $t3, 0xF
    ctx->r12 = ctx->r11 & 0XF;
    // 0x80016F44: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x80016F48: bgez        $t4, L_80016F5C
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80016F4C: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80016F5C;
    }
    // 0x80016F4C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80016F50: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80016F54: nop

    // 0x80016F58: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80016F5C:
    // 0x80016F5C: lui         $at, 0x4340
    ctx->r1 = S32(0X4340 << 16);
    // 0x80016F60: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80016F64: nop

    // 0x80016F68: div.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80016F6C: sub.s       $f2, $f0, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f16.fl;
L_80016F70:
    // 0x80016F70: sll         $t5, $v1, 9
    ctx->r13 = S32(ctx->r3 << 9);
    // 0x80016F74: bltz        $t5, L_80016FB8
    if (SIGNED(ctx->r13) < 0) {
        // 0x80016F78: lwc1        $f0, 0x1C($v0)
        ctx->f0.u32l = MEM_W(ctx->r2, 0X1C);
            goto L_80016FB8;
    }
    // 0x80016F78: lwc1        $f0, 0x1C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80016F7C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80016F80: lwc1        $f12, -0x6FF8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X6FF8);
    // 0x80016F84: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80016F88: c.le.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl <= ctx->f0.fl;
    // 0x80016F8C: nop

    // 0x80016F90: bc1fl       L_80016FA8
    if (!c1cs) {
        // 0x80016F94: div.s       $f8, $f0, $f12
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = DIV_S(ctx->f0.fl, ctx->f12.fl);
            goto L_80016FA8;
    }
    goto skip_0;
    // 0x80016F94: div.s       $f8, $f0, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = DIV_S(ctx->f0.fl, ctx->f12.fl);
    skip_0:
    // 0x80016F98: lwc1        $f18, -0x6FF4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X6FF4);
    // 0x80016F9C: b           L_80016FB8
    // 0x80016FA0: add.s       $f2, $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f18.fl;
        goto L_80016FB8;
    // 0x80016FA0: add.s       $f2, $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f18.fl;
    // 0x80016FA4: div.s       $f8, $f0, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = DIV_S(ctx->f0.fl, ctx->f12.fl);
L_80016FA8:
    // 0x80016FA8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80016FAC: lwc1        $f4, -0x6FF0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6FF0);
    // 0x80016FB0: mul.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80016FB4: add.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f6.fl;
L_80016FB8:
    // 0x80016FB8: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x80016FBC: lbu         $t6, 0x5D20($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X5D20);
    // 0x80016FC0: beq         $t6, $zero, L_80016FE8
    if (ctx->r14 == 0) {
        // 0x80016FC4: nop
    
            goto L_80016FE8;
    }
    // 0x80016FC4: nop

    // 0x80016FC8: lbu         $t7, 0xC($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0XC);
    // 0x80016FCC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80016FD0: andi        $t8, $t7, 0x2
    ctx->r24 = ctx->r15 & 0X2;
    // 0x80016FD4: beq         $t8, $zero, L_80016FE8
    if (ctx->r24 == 0) {
        // 0x80016FD8: nop
    
            goto L_80016FE8;
    }
    // 0x80016FD8: nop

    // 0x80016FDC: lwc1        $f10, -0x6FEC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X6FEC);
    // 0x80016FE0: mul.s       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x80016FE4: nop

L_80016FE8:
    // 0x80016FE8: jr          $ra
    // 0x80016FEC: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    return;
    // 0x80016FEC: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
;}
RECOMP_FUNC void ActorEvent_TiLandmine_Setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EBC0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006EBC4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8006EBC8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8006EBCC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8006EBD0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8006EBD4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8006EBD8: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8006EBDC: jal         0x800613C4
    // 0x8006EBE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Actor_Initialize(rdram, ctx);
        goto after_0;
    // 0x8006EBE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8006EBE4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8006EBE8: addiu       $t7, $zero, 0xE1
    ctx->r15 = ADD32(0, 0XE1);
    // 0x8006EBEC: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
    // 0x8006EBF0: sh          $t7, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r15;
    // 0x8006EBF4: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8006EBF8: andi        $a1, $t7, 0xFFFF
    ctx->r5 = ctx->r15 & 0XFFFF;
    // 0x8006EBFC: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x8006EC00: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x8006EC04: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8006EC08: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x8006EC0C: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8006EC10: jal         0x800612B8
    // 0x8006EC14: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_1;
    // 0x8006EC14: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    after_1:
    // 0x8006EC18: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8006EC1C: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8006EC20: lui         $t9, 0x800C
    ctx->r25 = S32(0X800C << 16);
    // 0x8006EC24: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8006EC28: sh          $t8, 0x32($s0)
    MEM_H(0X32, ctx->r16) = ctx->r24;
    // 0x8006EC2C: addiu       $t9, $t9, 0x5D3C
    ctx->r25 = ADD32(ctx->r25, 0X5D3C);
    // 0x8006EC30: lui         $a0, 0x2900
    ctx->r4 = S32(0X2900 << 16);
    // 0x8006EC34: ori         $a0, $a0, 0x201D
    ctx->r4 = ctx->r4 | 0X201D;
    // 0x8006EC38: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8006EC3C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8006EC40: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x8006EC44: jal         0x80019218
    // 0x8006EC48: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_2;
    // 0x8006EC48: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_2:
    // 0x8006EC4C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8006EC50: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8006EC54: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8006EC58: jr          $ra
    // 0x8006EC5C: nop

    return;
    // 0x8006EC5C: nop

;}
RECOMP_FUNC void Audio_GetActiveSeqId(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001839C: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x800183A0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800183A4: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800183A8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800183AC: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800183B0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800183B4: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800183B8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800183BC: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x800183C0: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800183C4: lw          $t8, -0x1AC8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X1AC8);
    // 0x800183C8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800183CC: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x800183D0: srl         $t9, $t8, 31
    ctx->r25 = S32(U32(ctx->r24) >> 31);
    // 0x800183D4: bne         $t9, $zero, L_800183E4
    if (ctx->r25 != 0) {
        // 0x800183D8: sll         $t0, $a0, 2
        ctx->r8 = S32(ctx->r4 << 2);
            goto L_800183E4;
    }
    // 0x800183D8: sll         $t0, $a0, 2
    ctx->r8 = S32(ctx->r4 << 2);
    // 0x800183DC: jr          $ra
    // 0x800183E0: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    return;
    // 0x800183E0: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
L_800183E4:
    // 0x800183E4: addu        $t0, $t0, $a0
    ctx->r8 = ADD32(ctx->r8, ctx->r4);
    // 0x800183E8: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x800183EC: subu        $t0, $t0, $a0
    ctx->r8 = SUB32(ctx->r8, ctx->r4);
    // 0x800183F0: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x800183F4: subu        $t0, $t0, $a0
    ctx->r8 = SUB32(ctx->r8, ctx->r4);
    // 0x800183F8: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x800183FC: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80018400: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x80018404: lhu         $v0, -0x5010($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X5010);
    // 0x80018408: jr          $ra
    // 0x8001840C: nop

    return;
    // 0x8001840C: nop

;}
RECOMP_FUNC void AudioHeap_DiscardSampleCacheEntry(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000DFFC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8000E000: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x8000E004: lw          $t6, 0x5C60($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X5C60);
    // 0x8000E008: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8000E00C: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8000E010: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8000E014: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8000E018: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8000E01C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8000E020: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8000E024: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8000E028: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8000E02C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000E030: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x8000E034: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8000E038: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x8000E03C: blez        $t7, L_8000E194
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8000E040: sw          $t7, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r15;
            goto L_8000E194;
    }
    // 0x8000E040: sw          $t7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r15;
    // 0x8000E044: lui         $s6, 0x8015
    ctx->r22 = S32(0X8015 << 16);
    // 0x8000E048: addiu       $s6, $s6, 0x5C70
    ctx->r22 = ADD32(ctx->r22, 0X5C70);
    // 0x8000E04C: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x8000E050: addiu       $fp, $zero, 0xFF
    ctx->r30 = ADD32(0, 0XFF);
    // 0x8000E054: addiu       $s7, $zero, 0x7F
    ctx->r23 = ADD32(0, 0X7F);
    // 0x8000E058: lw          $t8, 0x0($s6)
    ctx->r24 = MEM_W(ctx->r22, 0X0);
L_8000E05C:
    // 0x8000E05C: lb          $a1, 0x2($s3)
    ctx->r5 = MEM_B(ctx->r19, 0X2);
    // 0x8000E060: addu        $v0, $t8, $s5
    ctx->r2 = ADD32(ctx->r24, ctx->r21);
    // 0x8000E064: lbu         $v1, 0x2($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X2);
    // 0x8000E068: lbu         $a0, 0x3($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X3);
    // 0x8000E06C: beq         $v1, $fp, L_8000E07C
    if (ctx->r3 == ctx->r30) {
        // 0x8000E070: nop
    
            goto L_8000E07C;
    }
    // 0x8000E070: nop

    // 0x8000E074: beql        $v1, $a1, L_8000E094
    if (ctx->r3 == ctx->r5) {
        // 0x8000E078: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_8000E094;
    }
    goto skip_0;
    // 0x8000E078: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    skip_0:
L_8000E07C:
    // 0x8000E07C: beq         $a0, $fp, L_8000E08C
    if (ctx->r4 == ctx->r30) {
        // 0x8000E080: nop
    
            goto L_8000E08C;
    }
    // 0x8000E080: nop

    // 0x8000E084: beql        $a0, $a1, L_8000E094
    if (ctx->r4 == ctx->r5) {
        // 0x8000E088: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_8000E094;
    }
    goto skip_1;
    // 0x8000E088: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    skip_1:
L_8000E08C:
    // 0x8000E08C: bne         $a1, $zero, L_8000E180
    if (ctx->r5 != 0) {
        // 0x8000E090: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_8000E180;
    }
    // 0x8000E090: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8000E094:
    // 0x8000E094: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8000E098: jal         0x8000C990
    // 0x8000E09C: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    AudioHeap_SearchCaches(rdram, ctx);
        goto after_0;
    // 0x8000E09C: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_0:
    // 0x8000E0A0: beq         $v0, $zero, L_8000E180
    if (ctx->r2 == 0) {
        // 0x8000E0A4: lui         $t9, 0x8015
        ctx->r25 = S32(0X8015 << 16);
            goto L_8000E180;
    }
    // 0x8000E0A4: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x8000E0A8: addu        $t9, $t9, $s4
    ctx->r25 = ADD32(ctx->r25, ctx->r20);
    // 0x8000E0AC: lbu         $t9, -0x2C18($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X2C18);
    // 0x8000E0B0: slti        $t0, $t9, 0x2
    ctx->r8 = SIGNED(ctx->r25) < 0X2 ? 1 : 0;
    // 0x8000E0B4: bnel        $t0, $zero, L_8000E184
    if (ctx->r8 != 0) {
        // 0x8000E0B8: lw          $t1, 0x40($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X40);
            goto L_8000E184;
    }
    goto skip_2;
    // 0x8000E0B8: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    skip_2:
    // 0x8000E0BC: lw          $t1, 0x0($s6)
    ctx->r9 = MEM_W(ctx->r22, 0X0);
    // 0x8000E0C0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8000E0C4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8000E0C8: addu        $v0, $t1, $s5
    ctx->r2 = ADD32(ctx->r9, ctx->r21);
    // 0x8000E0CC: lbu         $t2, 0x0($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X0);
    // 0x8000E0D0: blez        $t2, L_8000E140
    if (SIGNED(ctx->r10) <= 0) {
        // 0x8000E0D4: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_8000E140;
    }
    // 0x8000E0D4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
L_8000E0D8:
    // 0x8000E0D8: jal         0x80011D4C
    // 0x8000E0DC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    Audio_GetInstrument(rdram, ctx);
        goto after_1;
    // 0x8000E0DC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_1:
    // 0x8000E0E0: beq         $v0, $zero, L_8000E124
    if (ctx->r2 == 0) {
        // 0x8000E0E4: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8000E124;
    }
    // 0x8000E0E4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8000E0E8: lbu         $t3, 0x1($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X1);
    // 0x8000E0EC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8000E0F0: beql        $t3, $zero, L_8000E104
    if (ctx->r11 == 0) {
        // 0x8000E0F4: lbu         $t4, 0x2($s0)
        ctx->r12 = MEM_BU(ctx->r16, 0X2);
            goto L_8000E104;
    }
    goto skip_3;
    // 0x8000E0F4: lbu         $t4, 0x2($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X2);
    skip_3:
    // 0x8000E0F8: jal         0x8000E1C4
    // 0x8000E0FC: lw          $a1, 0x8($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X8);
    AudioHeap_UnapplySampleCache(rdram, ctx);
        goto after_2;
    // 0x8000E0FC: lw          $a1, 0x8($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X8);
    after_2:
    // 0x8000E100: lbu         $t4, 0x2($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X2);
L_8000E104:
    // 0x8000E104: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8000E108: beql        $s7, $t4, L_8000E11C
    if (ctx->r23 == ctx->r12) {
        // 0x8000E10C: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_8000E11C;
    }
    goto skip_4;
    // 0x8000E10C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    skip_4:
    // 0x8000E110: jal         0x8000E1C4
    // 0x8000E114: lw          $a1, 0x18($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X18);
    AudioHeap_UnapplySampleCache(rdram, ctx);
        goto after_3;
    // 0x8000E114: lw          $a1, 0x18($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X18);
    after_3:
    // 0x8000E118: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_8000E11C:
    // 0x8000E11C: jal         0x8000E1C4
    // 0x8000E120: lw          $a1, 0x10($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X10);
    AudioHeap_UnapplySampleCache(rdram, ctx);
        goto after_4;
    // 0x8000E120: lw          $a1, 0x10($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X10);
    after_4:
L_8000E124:
    // 0x8000E124: lw          $t5, 0x0($s6)
    ctx->r13 = MEM_W(ctx->r22, 0X0);
    // 0x8000E128: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8000E12C: addu        $v0, $t5, $s5
    ctx->r2 = ADD32(ctx->r13, ctx->r21);
    // 0x8000E130: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x8000E134: slt         $at, $s1, $t6
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8000E138: bnel        $at, $zero, L_8000E0D8
    if (ctx->r1 != 0) {
        // 0x8000E13C: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_8000E0D8;
    }
    goto skip_5;
    // 0x8000E13C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    skip_5:
L_8000E140:
    // 0x8000E140: lbu         $t7, 0x1($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X1);
    // 0x8000E144: blez        $t7, L_8000E180
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8000E148: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_8000E180;
    }
    // 0x8000E148: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
L_8000E14C:
    // 0x8000E14C: jal         0x80011DFC
    // 0x8000E150: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    Audio_GetDrum(rdram, ctx);
        goto after_5;
    // 0x8000E150: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_5:
    // 0x8000E154: beq         $v0, $zero, L_8000E164
    if (ctx->r2 == 0) {
        // 0x8000E158: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_8000E164;
    }
    // 0x8000E158: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8000E15C: jal         0x8000E1C4
    // 0x8000E160: lw          $a1, 0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4);
    AudioHeap_UnapplySampleCache(rdram, ctx);
        goto after_6;
    // 0x8000E160: lw          $a1, 0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4);
    after_6:
L_8000E164:
    // 0x8000E164: lw          $t8, 0x0($s6)
    ctx->r24 = MEM_W(ctx->r22, 0X0);
    // 0x8000E168: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8000E16C: addu        $t9, $t8, $s5
    ctx->r25 = ADD32(ctx->r24, ctx->r21);
    // 0x8000E170: lbu         $t0, 0x1($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X1);
    // 0x8000E174: slt         $at, $s2, $t0
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8000E178: bnel        $at, $zero, L_8000E14C
    if (ctx->r1 != 0) {
        // 0x8000E17C: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_8000E14C;
    }
    goto skip_6;
    // 0x8000E17C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    skip_6:
L_8000E180:
    // 0x8000E180: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
L_8000E184:
    // 0x8000E184: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x8000E188: addiu       $s5, $s5, 0xC
    ctx->r21 = ADD32(ctx->r21, 0XC);
    // 0x8000E18C: bnel        $s4, $t1, L_8000E05C
    if (ctx->r20 != ctx->r9) {
        // 0x8000E190: lw          $t8, 0x0($s6)
        ctx->r24 = MEM_W(ctx->r22, 0X0);
            goto L_8000E05C;
    }
    goto skip_7;
    // 0x8000E190: lw          $t8, 0x0($s6)
    ctx->r24 = MEM_W(ctx->r22, 0X0);
    skip_7:
L_8000E194:
    // 0x8000E194: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8000E198: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000E19C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8000E1A0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8000E1A4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8000E1A8: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8000E1AC: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8000E1B0: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8000E1B4: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8000E1B8: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8000E1BC: jr          $ra
    // 0x8000E1C0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8000E1C0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void Effect_Effect395_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082F78: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80082F7C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80082F80: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80082F84: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80082F88: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80082F8C: lh          $v0, 0x4E($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X4E);
    // 0x80082F90: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80082F94: beq         $v0, $zero, L_80082FA0
    if (ctx->r2 == 0) {
        // 0x80082F98: sll         $t6, $v0, 2
        ctx->r14 = S32(ctx->r2 << 2);
            goto L_80082FA0;
    }
    // 0x80082F98: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80082F9C: beq         $v0, $at, L_80082FA0
    if (ctx->r2 == ctx->r1) {
        // 0x80082FA0: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80082FA0;
    }
L_80082FA0:
    // 0x80082FA0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80082FA4: beq         $v0, $at, L_80082FC0
    if (ctx->r2 == ctx->r1) {
        // 0x80082FA8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80082FC0;
    }
    // 0x80082FA8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80082FAC: beq         $v0, $at, L_80082FC0
    if (ctx->r2 == ctx->r1) {
        // 0x80082FB0: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80082FC0;
    }
    // 0x80082FB0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80082FB4: beq         $v0, $at, L_80082FC0
    if (ctx->r2 == ctx->r1) {
        // 0x80082FB8: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_80082FC0;
    }
    // 0x80082FB8: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80082FBC: beq         $v0, $at, L_80082FC0
    if (ctx->r2 == ctx->r1) {
        // 0x80082FC0: sltiu       $at, $v0, 0xD
        ctx->r1 = ctx->r2 < 0XD ? 1 : 0;
            goto L_80082FC0;
    }
L_80082FC0:
    // 0x80082FC0: sltiu       $at, $v0, 0xD
    ctx->r1 = ctx->r2 < 0XD ? 1 : 0;
    // 0x80082FC4: beq         $at, $zero, L_8008369C
    if (ctx->r1 == 0) {
        // 0x80082FC8: lui         $at, 0x800D
        ctx->r1 = S32(0X800D << 16);
            goto L_8008369C;
    }
    // 0x80082FC8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80082FCC: addu        $at, $at, $t6
    gpr jr_addend_80082FD4 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80082FD0: lw          $t6, 0x7650($at)
    ctx->r14 = ADD32(ctx->r1, 0X7650);
    // 0x80082FD4: jr          $t6
    // 0x80082FD8: nop

    switch (jr_addend_80082FD4 >> 2) {
        case 0: goto L_80082FDC; break;
        case 1: goto L_80083084; break;
        case 2: goto L_800830E4; break;
        case 3: goto L_80083188; break;
        case 4: goto L_800831F4; break;
        case 5: goto L_80083270; break;
        case 6: goto L_800832FC; break;
        case 7: goto L_80083270; break;
        case 8: goto L_80083384; break;
        case 9: goto L_80083428; break;
        case 10: goto L_80083554; break;
        case 11: goto L_800835FC; break;
        case 12: goto L_80083694; break;
        default: switch_error(__func__, 0x80082FD4, 0x800D7650);
    }
    // 0x80082FD8: nop

L_80082FDC:
    // 0x80082FDC: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80082FE0: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x80082FE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80082FE8: jal         0x800B8DD0
    // 0x80082FEC: addiu       $a1, $zero, 0x31
    ctx->r5 = ADD32(0, 0X31);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x80082FEC: addiu       $a1, $zero, 0x31
    ctx->r5 = ADD32(0, 0X31);
    after_0:
    // 0x80082FF0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80082FF4: lwc1        $f0, 0x7684($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X7684);
    // 0x80082FF8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80082FFC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80083000: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80083004: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80083008: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8008300C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80083010: jal         0x80005C34
    // 0x80083014: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_1;
    // 0x80083014: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x80083018: jal         0x80006EB8
    // 0x8008301C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_2;
    // 0x8008301C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80083020: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80083024: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x80083028: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8008302C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80083030: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80083034: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x80083038: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8008303C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80083040: lui         $t3, 0x2020
    ctx->r11 = S32(0X2020 << 16);
    // 0x80083044: ori         $t3, $t3, 0xFFFF
    ctx->r11 = ctx->r11 | 0XFFFF;
    // 0x80083048: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x8008304C: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x80083050: lui         $t2, 0xFB00
    ctx->r10 = S32(0XFB00 << 16);
    // 0x80083054: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x80083058: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x8008305C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80083060: lui         $t6, 0x102
    ctx->r14 = S32(0X102 << 16);
    // 0x80083064: addiu       $t6, $t6, 0x4AC0
    ctx->r14 = ADD32(ctx->r14, 0X4AC0);
    // 0x80083068: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x8008306C: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x80083070: lui         $t5, 0x600
    ctx->r13 = S32(0X600 << 16);
    // 0x80083074: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80083078: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8008307C: b           L_8008369C
    // 0x80083080: nop

        goto L_8008369C;
    // 0x80083080: nop

L_80083084:
    // 0x80083084: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80083088: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x8008308C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80083090: jal         0x800B8DD0
    // 0x80083094: addiu       $a1, $zero, 0x29
    ctx->r5 = ADD32(0, 0X29);
    RCP_SetupDL(rdram, ctx);
        goto after_3;
    // 0x80083094: addiu       $a1, $zero, 0x29
    ctx->r5 = ADD32(0, 0X29);
    after_3:
    // 0x80083098: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8008309C: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x800830A0: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x800830A4: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800830A8: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800830AC: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800830B0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800830B4: jal         0x8005980C
    // 0x800830B8: lwc1        $f12, 0x70($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X70);
    Graphics_SetScaleMtx(rdram, ctx);
        goto after_4;
    // 0x800830B8: lwc1        $f12, 0x70($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X70);
    after_4:
    // 0x800830BC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800830C0: lui         $t2, 0x102
    ctx->r10 = S32(0X102 << 16);
    // 0x800830C4: addiu       $t2, $t2, -0x3D20
    ctx->r10 = ADD32(ctx->r10, -0X3D20);
    // 0x800830C8: addiu       $t0, $v0, 0x8
    ctx->r8 = ADD32(ctx->r2, 0X8);
    // 0x800830CC: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x800830D0: lui         $t1, 0x600
    ctx->r9 = S32(0X600 << 16);
    // 0x800830D4: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x800830D8: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x800830DC: b           L_8008369C
    // 0x800830E0: nop

        goto L_8008369C;
    // 0x800830E0: nop

L_800830E4:
    // 0x800830E4: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800830E8: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x800830EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800830F0: jal         0x800B8DD0
    // 0x800830F4: addiu       $a1, $zero, 0x31
    ctx->r5 = ADD32(0, 0X31);
    RCP_SetupDL(rdram, ctx);
        goto after_5;
    // 0x800830F4: addiu       $a1, $zero, 0x31
    ctx->r5 = ADD32(0, 0X31);
    after_5:
    // 0x800830F8: lwc1        $f0, 0x70($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X70);
    // 0x800830FC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80083100: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80083104: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80083108: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8008310C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80083110: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80083114: jal         0x80005C34
    // 0x80083118: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Scale(rdram, ctx);
        goto after_6;
    // 0x80083118: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_6:
    // 0x8008311C: jal         0x80006EB8
    // 0x80083120: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_7;
    // 0x80083120: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80083124: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80083128: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x8008312C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80083130: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x80083134: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x80083138: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8008313C: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80083140: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80083144: lui         $t9, 0x2020
    ctx->r25 = S32(0X2020 << 16);
    // 0x80083148: ori         $t9, $t9, 0xFFFF
    ctx->r25 = ctx->r25 | 0XFFFF;
    // 0x8008314C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80083150: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80083154: lui         $t8, 0xFB00
    ctx->r24 = S32(0XFB00 << 16);
    // 0x80083158: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8008315C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80083160: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80083164: lui         $t2, 0x102
    ctx->r10 = S32(0X102 << 16);
    // 0x80083168: addiu       $t2, $t2, 0x4AC0
    ctx->r10 = ADD32(ctx->r10, 0X4AC0);
    // 0x8008316C: addiu       $t0, $v0, 0x8
    ctx->r8 = ADD32(ctx->r2, 0X8);
    // 0x80083170: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x80083174: lui         $t1, 0x600
    ctx->r9 = S32(0X600 << 16);
    // 0x80083178: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x8008317C: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x80083180: b           L_8008369C
    // 0x80083184: nop

        goto L_8008369C;
    // 0x80083184: nop

L_80083188:
    // 0x80083188: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8008318C: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80083190: lw          $t4, -0x7C24($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7C24);
    // 0x80083194: lw          $t3, -0x7C28($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X7C28);
    // 0x80083198: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8008319C: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800831A0: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x800831A4: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x800831A8: lw          $a3, -0x7CC8($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X7CC8);
    // 0x800831AC: lw          $a2, -0x7CD0($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7CD0);
    // 0x800831B0: lw          $a1, -0x7CD8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7CD8);
    // 0x800831B4: lw          $a0, -0x7CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7CE0);
    // 0x800831B8: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x800831BC: jal         0x800B9B38
    // 0x800831C0: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    RCP_SetupDL_60(rdram, ctx);
        goto after_8;
    // 0x800831C0: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_8:
    // 0x800831C4: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800831C8: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x800831CC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800831D0: lui         $t7, 0x602
    ctx->r15 = S32(0X602 << 16);
    // 0x800831D4: addiu       $t7, $t7, -0x5EE0
    ctx->r15 = ADD32(ctx->r15, -0X5EE0);
    // 0x800831D8: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x800831DC: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x800831E0: lui         $t6, 0x600
    ctx->r14 = S32(0X600 << 16);
    // 0x800831E4: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800831E8: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800831EC: b           L_8008369C
    // 0x800831F0: nop

        goto L_8008369C;
    // 0x800831F0: nop

L_800831F4:
    // 0x800831F4: jal         0x8005980C
    // 0x800831F8: lwc1        $f12, 0x70($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X70);
    Graphics_SetScaleMtx(rdram, ctx);
        goto after_9;
    // 0x800831F8: lwc1        $f12, 0x70($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X70);
    after_9:
    // 0x800831FC: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80083200: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x80083204: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80083208: jal         0x800B8DD0
    // 0x8008320C: addiu       $a1, $zero, 0x44
    ctx->r5 = ADD32(0, 0X44);
    RCP_SetupDL(rdram, ctx);
        goto after_10;
    // 0x8008320C: addiu       $a1, $zero, 0x44
    ctx->r5 = ADD32(0, 0X44);
    after_10:
    // 0x80083210: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80083214: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x80083218: lui         $t5, 0x600
    ctx->r13 = S32(0X600 << 16);
    // 0x8008321C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80083220: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80083224: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80083228: lh          $t0, 0x4A($s1)
    ctx->r8 = MEM_H(ctx->r17, 0X4A);
    // 0x8008322C: andi        $t1, $t0, 0xFF
    ctx->r9 = ctx->r8 & 0XFF;
    // 0x80083230: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x80083234: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80083238: lui         $t3, 0xFB00
    ctx->r11 = S32(0XFB00 << 16);
    // 0x8008323C: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x80083240: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x80083244: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80083248: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8008324C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80083250: lui         $t6, 0x102
    ctx->r14 = S32(0X102 << 16);
    // 0x80083254: addiu       $t6, $t6, 0x3750
    ctx->r14 = ADD32(ctx->r14, 0X3750);
    // 0x80083258: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x8008325C: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x80083260: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80083264: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80083268: b           L_8008369C
    // 0x8008326C: nop

        goto L_8008369C;
    // 0x8008326C: nop

L_80083270:
    // 0x80083270: jal         0x8005980C
    // 0x80083274: lwc1        $f12, 0x70($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X70);
    Graphics_SetScaleMtx(rdram, ctx);
        goto after_11;
    // 0x80083274: lwc1        $f12, 0x70($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X70);
    after_11:
    // 0x80083278: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8008327C: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x80083280: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80083284: jal         0x800B8DD0
    // 0x80083288: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    RCP_SetupDL(rdram, ctx);
        goto after_12;
    // 0x80083288: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    after_12:
    // 0x8008328C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80083290: lw          $a0, -0x7DCC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7DCC);
    // 0x80083294: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x80083298: bnel        $a0, $at, L_800832CC
    if (ctx->r4 != ctx->r1) {
        // 0x8008329C: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_800832CC;
    }
    goto skip_0;
    // 0x8008329C: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    skip_0:
    // 0x800832A0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800832A4: lui         $t9, 0x601
    ctx->r25 = S32(0X601 << 16);
    // 0x800832A8: addiu       $t9, $t9, -0x5DE0
    ctx->r25 = ADD32(ctx->r25, -0X5DE0);
    // 0x800832AC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800832B0: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800832B4: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x800832B8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800832BC: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800832C0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800832C4: lw          $a0, -0x7DCC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7DCC);
    // 0x800832C8: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
L_800832CC:
    // 0x800832CC: bne         $a0, $at, L_8008369C
    if (ctx->r4 != ctx->r1) {
        // 0x800832D0: nop
    
            goto L_8008369C;
    }
    // 0x800832D0: nop

    // 0x800832D4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800832D8: lui         $t2, 0x601
    ctx->r10 = S32(0X601 << 16);
    // 0x800832DC: addiu       $t2, $t2, 0x6880
    ctx->r10 = ADD32(ctx->r10, 0X6880);
    // 0x800832E0: addiu       $t0, $v0, 0x8
    ctx->r8 = ADD32(ctx->r2, 0X8);
    // 0x800832E4: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x800832E8: lui         $t1, 0x600
    ctx->r9 = S32(0X600 << 16);
    // 0x800832EC: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x800832F0: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x800832F4: b           L_8008369C
    // 0x800832F8: nop

        goto L_8008369C;
    // 0x800832F8: nop

L_800832FC:
    // 0x800832FC: jal         0x8005980C
    // 0x80083300: lwc1        $f12, 0x70($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X70);
    Graphics_SetScaleMtx(rdram, ctx);
        goto after_13;
    // 0x80083300: lwc1        $f12, 0x70($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X70);
    after_13:
    // 0x80083304: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80083308: lw          $t3, -0x7DCC($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X7DCC);
    // 0x8008330C: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80083310: bne         $t3, $at, L_80083320
    if (ctx->r11 != ctx->r1) {
        // 0x80083314: nop
    
            goto L_80083320;
    }
    // 0x80083314: nop

    // 0x80083318: jal         0x8005980C
    // 0x8008331C: lwc1        $f12, 0x70($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X70);
    Graphics_SetScaleMtx(rdram, ctx);
        goto after_14;
    // 0x8008331C: lwc1        $f12, 0x70($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X70);
    after_14:
L_80083320:
    // 0x80083320: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80083324: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x80083328: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8008332C: jal         0x800B8DD0
    // 0x80083330: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    RCP_SetupDL(rdram, ctx);
        goto after_15;
    // 0x80083330: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_15:
    // 0x80083334: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80083338: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x8008333C: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x80083340: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x80083344: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x80083348: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8008334C: lh          $t6, 0x4A($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X4A);
    // 0x80083350: lui         $t0, 0x600
    ctx->r8 = S32(0X600 << 16);
    // 0x80083354: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x80083358: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x8008335C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80083360: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80083364: lui         $t1, 0x102
    ctx->r9 = S32(0X102 << 16);
    // 0x80083368: addiu       $t1, $t1, 0x3750
    ctx->r9 = ADD32(ctx->r9, 0X3750);
    // 0x8008336C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80083370: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80083374: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x80083378: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x8008337C: b           L_8008369C
    // 0x80083380: nop

        goto L_8008369C;
    // 0x80083380: nop

L_80083384:
    // 0x80083384: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80083388: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x8008338C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80083390: jal         0x800B8DD0
    // 0x80083394: addiu       $a1, $zero, 0x31
    ctx->r5 = ADD32(0, 0X31);
    RCP_SetupDL(rdram, ctx);
        goto after_16;
    // 0x80083394: addiu       $a1, $zero, 0x31
    ctx->r5 = ADD32(0, 0X31);
    after_16:
    // 0x80083398: lwc1        $f0, 0x70($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X70);
    // 0x8008339C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800833A0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800833A4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800833A8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800833AC: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800833B0: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800833B4: jal         0x80005C34
    // 0x800833B8: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Scale(rdram, ctx);
        goto after_17;
    // 0x800833B8: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_17:
    // 0x800833BC: jal         0x80006EB8
    // 0x800833C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_18;
    // 0x800833C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x800833C4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800833C8: lui         $t4, 0xFA00
    ctx->r12 = S32(0XFA00 << 16);
    // 0x800833CC: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x800833D0: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x800833D4: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x800833D8: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x800833DC: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x800833E0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800833E4: lui         $t8, 0xFF00
    ctx->r24 = S32(0XFF00 << 16);
    // 0x800833E8: ori         $t8, $t8, 0x80FF
    ctx->r24 = ctx->r24 | 0X80FF;
    // 0x800833EC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800833F0: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800833F4: lui         $t7, 0xFB00
    ctx->r15 = S32(0XFB00 << 16);
    // 0x800833F8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800833FC: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80083400: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80083404: lui         $t1, 0x102
    ctx->r9 = S32(0X102 << 16);
    // 0x80083408: addiu       $t1, $t1, 0x4AC0
    ctx->r9 = ADD32(ctx->r9, 0X4AC0);
    // 0x8008340C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80083410: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80083414: lui         $t0, 0x600
    ctx->r8 = S32(0X600 << 16);
    // 0x80083418: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x8008341C: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x80083420: b           L_8008369C
    // 0x80083424: nop

        goto L_8008369C;
    // 0x80083424: nop

L_80083428:
    // 0x80083428: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8008342C: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x80083430: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80083434: jal         0x800B8DD0
    // 0x80083438: addiu       $a1, $zero, 0x31
    ctx->r5 = ADD32(0, 0X31);
    RCP_SetupDL(rdram, ctx);
        goto after_19;
    // 0x80083438: addiu       $a1, $zero, 0x31
    ctx->r5 = ADD32(0, 0X31);
    after_19:
    // 0x8008343C: lwc1        $f0, 0x70($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X70);
    // 0x80083440: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80083444: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80083448: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8008344C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80083450: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80083454: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80083458: jal         0x80005C34
    // 0x8008345C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Scale(rdram, ctx);
        goto after_20;
    // 0x8008345C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_20:
    // 0x80083460: jal         0x80006EB8
    // 0x80083464: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_21;
    // 0x80083464: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x80083468: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8008346C: lui         $t4, 0xFA00
    ctx->r12 = S32(0XFA00 << 16);
    // 0x80083470: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80083474: addiu       $t3, $v1, 0x8
    ctx->r11 = ADD32(ctx->r3, 0X8);
    // 0x80083478: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x8008347C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80083480: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x80083484: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80083488: lwc1        $f4, 0x6C($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X6C);
    // 0x8008348C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80083490: lui         $t3, 0x600
    ctx->r11 = S32(0X600 << 16);
    // 0x80083494: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80083498: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8008349C: nop

    // 0x800834A0: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x800834A4: beql        $t6, $zero, L_800834F4
    if (ctx->r14 == 0) {
        // 0x800834A8: mfc1        $t6, $f6
        ctx->r14 = (int32_t)ctx->f6.u32l;
            goto L_800834F4;
    }
    goto skip_1;
    // 0x800834A8: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    skip_1:
    // 0x800834AC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800834B0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800834B4: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800834B8: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800834BC: nop

    // 0x800834C0: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800834C4: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800834C8: nop

    // 0x800834CC: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x800834D0: bne         $t6, $zero, L_800834E8
    if (ctx->r14 != 0) {
        // 0x800834D4: nop
    
            goto L_800834E8;
    }
    // 0x800834D4: nop

    // 0x800834D8: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x800834DC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800834E0: b           L_80083500
    // 0x800834E4: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
        goto L_80083500;
    // 0x800834E4: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
L_800834E8:
    // 0x800834E8: b           L_80083500
    // 0x800834EC: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
        goto L_80083500;
    // 0x800834EC: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x800834F0: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
L_800834F4:
    // 0x800834F4: nop

    // 0x800834F8: bltz        $t6, L_800834E8
    if (SIGNED(ctx->r14) < 0) {
        // 0x800834FC: nop
    
            goto L_800834E8;
    }
    // 0x800834FC: nop

L_80083500:
    // 0x80083500: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x80083504: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x80083508: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x8008350C: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x80083510: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80083514: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80083518: lui         $t0, 0xFB00
    ctx->r8 = S32(0XFB00 << 16);
    // 0x8008351C: addiu       $t1, $zero, -0x7F01
    ctx->r9 = ADD32(0, -0X7F01);
    // 0x80083520: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80083524: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80083528: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x8008352C: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x80083530: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80083534: lui         $t4, 0x102
    ctx->r12 = S32(0X102 << 16);
    // 0x80083538: addiu       $t4, $t4, 0x4AC0
    ctx->r12 = ADD32(ctx->r12, 0X4AC0);
    // 0x8008353C: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x80083540: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x80083544: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80083548: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8008354C: b           L_8008369C
    // 0x80083550: nop

        goto L_8008369C;
    // 0x80083550: nop

L_80083554:
    // 0x80083554: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x80083558: lw          $t5, 0x7854($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7854);
    // 0x8008355C: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x80083560: beq         $t5, $at, L_8008357C
    if (ctx->r13 == ctx->r1) {
        // 0x80083564: lui         $a0, 0x601
        ctx->r4 = S32(0X601 << 16);
            goto L_8008357C;
    }
    // 0x80083564: lui         $a0, 0x601
    ctx->r4 = S32(0X601 << 16);
    // 0x80083568: addiu       $a0, $a0, 0x2840
    ctx->r4 = ADD32(ctx->r4, 0X2840);
    // 0x8008356C: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x80083570: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80083574: jal         0x80099A2C
    // 0x80083578: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    Lib_Texture_Scroll(rdram, ctx);
        goto after_22;
    // 0x80083578: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_22:
L_8008357C:
    // 0x8008357C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80083580: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x80083584: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80083588: jal         0x800B8DD0
    // 0x8008358C: addiu       $a1, $zero, 0x35
    ctx->r5 = ADD32(0, 0X35);
    RCP_SetupDL(rdram, ctx);
        goto after_23;
    // 0x8008358C: addiu       $a1, $zero, 0x35
    ctx->r5 = ADD32(0, 0X35);
    after_23:
    // 0x80083590: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80083594: lw          $a1, 0x60($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X60);
    // 0x80083598: lw          $a2, 0x64($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X64);
    // 0x8008359C: lw          $a3, 0x68($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X68);
    // 0x800835A0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800835A4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800835A8: jal         0x80005C34
    // 0x800835AC: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Scale(rdram, ctx);
        goto after_24;
    // 0x800835AC: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_24:
    // 0x800835B0: jal         0x80006EB8
    // 0x800835B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_25;
    // 0x800835B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_25:
    // 0x800835B8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800835BC: lui         $t8, 0xB600
    ctx->r24 = S32(0XB600 << 16);
    // 0x800835C0: addiu       $t9, $zero, 0x2000
    ctx->r25 = ADD32(0, 0X2000);
    // 0x800835C4: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800835C8: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800835CC: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800835D0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800835D4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800835D8: lui         $t2, 0x601
    ctx->r10 = S32(0X601 << 16);
    // 0x800835DC: addiu       $t2, $t2, 0x2550
    ctx->r10 = ADD32(ctx->r10, 0X2550);
    // 0x800835E0: addiu       $t0, $v0, 0x8
    ctx->r8 = ADD32(ctx->r2, 0X8);
    // 0x800835E4: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x800835E8: lui         $t1, 0x600
    ctx->r9 = S32(0X600 << 16);
    // 0x800835EC: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x800835F0: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x800835F4: b           L_8008369C
    // 0x800835F8: nop

        goto L_8008369C;
    // 0x800835F8: nop

L_800835FC:
    // 0x800835FC: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80083600: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x80083604: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80083608: jal         0x800B8DD0
    // 0x8008360C: addiu       $a1, $zero, 0x43
    ctx->r5 = ADD32(0, 0X43);
    RCP_SetupDL(rdram, ctx);
        goto after_26;
    // 0x8008360C: addiu       $a1, $zero, 0x43
    ctx->r5 = ADD32(0, 0X43);
    after_26:
    // 0x80083610: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80083614: lui         $t4, 0xFA00
    ctx->r12 = S32(0XFA00 << 16);
    // 0x80083618: lui         $at, 0x6F6F
    ctx->r1 = S32(0X6F6F << 16);
    // 0x8008361C: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x80083620: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x80083624: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80083628: lwc1        $f8, 0x6C($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X6C);
    // 0x8008362C: ori         $at, $at, 0x6F00
    ctx->r1 = ctx->r1 | 0X6F00;
    // 0x80083630: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80083634: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x80083638: nop

    // 0x8008363C: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x80083640: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x80083644: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80083648: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8008364C: lui         $t0, 0xFB00
    ctx->r8 = S32(0XFB00 << 16);
    // 0x80083650: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80083654: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80083658: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x8008365C: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x80083660: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x80083664: jal         0x8005980C
    // 0x80083668: lwc1        $f12, 0x70($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X70);
    Graphics_SetScaleMtx(rdram, ctx);
        goto after_27;
    // 0x80083668: lwc1        $f12, 0x70($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X70);
    after_27:
    // 0x8008366C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80083670: lui         $t4, 0x102
    ctx->r12 = S32(0X102 << 16);
    // 0x80083674: addiu       $t4, $t4, 0x4AC0
    ctx->r12 = ADD32(ctx->r12, 0X4AC0);
    // 0x80083678: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x8008367C: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x80083680: lui         $t3, 0x600
    ctx->r11 = S32(0X600 << 16);
    // 0x80083684: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80083688: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x8008368C: b           L_8008369C
    // 0x80083690: nop

        goto L_8008369C;
    // 0x80083690: nop

L_80083694:
    // 0x80083694: jal         0x8007A3C0
    // 0x80083698: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Effect_Effect383_Draw(rdram, ctx);
        goto after_28;
    // 0x80083698: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_28:
L_8008369C:
    // 0x8008369C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800836A0: addiu       $a0, $s0, 0x7E64
    ctx->r4 = ADD32(ctx->r16, 0X7E64);
    // 0x800836A4: jal         0x800B8DD0
    // 0x800836A8: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    RCP_SetupDL(rdram, ctx);
        goto after_29;
    // 0x800836A8: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_29:
    // 0x800836AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800836B0: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800836B4: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800836B8: jr          $ra
    // 0x800836BC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800836BC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
