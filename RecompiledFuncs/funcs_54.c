#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void Ending_80187D3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80187D3C: addiu       $sp, $sp, -0x250
    ctx->r29 = ADD32(ctx->r29, -0X250);
    // 0x80187D40: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80187D44: addiu       $a1, $a1, 0x6F88
    ctx->r5 = ADD32(ctx->r5, 0X6F88);
    // 0x80187D48: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x80187D4C: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x80187D50: addiu       $v0, $sp, 0x23C
    ctx->r2 = ADD32(ctx->r29, 0X23C);
    // 0x80187D54: lui         $t6, 0x8019
    ctx->r14 = S32(0X8019 << 16);
    // 0x80187D58: addiu       $t6, $t6, 0x2830
    ctx->r14 = ADD32(ctx->r14, 0X2830);
    // 0x80187D5C: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x80187D60: lui         $t7, 0x8019
    ctx->r15 = S32(0X8019 << 16);
    // 0x80187D64: addiu       $t7, $t7, 0x283C
    ctx->r15 = ADD32(ctx->r15, 0X283C);
    // 0x80187D68: sw          $at, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r1;
    // 0x80187D6C: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x80187D70: addiu       $t8, $sp, 0x13C
    ctx->r24 = ADD32(ctx->r29, 0X13C);
    // 0x80187D74: lui         $t5, 0x8019
    ctx->r13 = S32(0X8019 << 16);
    // 0x80187D78: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80187D7C: lw          $at, 0x8($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X8);
    // 0x80187D80: addiu       $t9, $t7, 0xFC
    ctx->r25 = ADD32(ctx->r15, 0XFC);
    // 0x80187D84: addiu       $t6, $sp, 0x3C
    ctx->r14 = ADD32(ctx->r29, 0X3C);
    // 0x80187D88: sw          $at, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r1;
L_80187D8C:
    // 0x80187D8C: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x80187D90: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x80187D94: addiu       $t8, $t8, 0xC
    ctx->r24 = ADD32(ctx->r24, 0XC);
    // 0x80187D98: sw          $at, -0xC($t8)
    MEM_W(-0XC, ctx->r24) = ctx->r1;
    // 0x80187D9C: lw          $at, -0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, -0X8);
    // 0x80187DA0: sw          $at, -0x8($t8)
    MEM_W(-0X8, ctx->r24) = ctx->r1;
    // 0x80187DA4: lw          $at, -0x4($t7)
    ctx->r1 = MEM_W(ctx->r15, -0X4);
    // 0x80187DA8: bne         $t7, $t9, L_80187D8C
    if (ctx->r15 != ctx->r25) {
        // 0x80187DAC: sw          $at, -0x4($t8)
        MEM_W(-0X4, ctx->r24) = ctx->r1;
            goto L_80187D8C;
    }
    // 0x80187DAC: sw          $at, -0x4($t8)
    MEM_W(-0X4, ctx->r24) = ctx->r1;
    // 0x80187DB0: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x80187DB4: lui         $t9, 0x8019
    ctx->r25 = S32(0X8019 << 16);
    // 0x80187DB8: addiu       $t9, $t9, 0x293C
    ctx->r25 = ADD32(ctx->r25, 0X293C);
    // 0x80187DBC: sw          $at, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r1;
    // 0x80187DC0: addiu       $t8, $t9, 0xFC
    ctx->r24 = ADD32(ctx->r25, 0XFC);
L_80187DC4:
    // 0x80187DC4: lw          $at, 0x0($t9)
    ctx->r1 = MEM_W(ctx->r25, 0X0);
    // 0x80187DC8: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x80187DCC: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80187DD0: sw          $at, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r1;
    // 0x80187DD4: lw          $at, -0x8($t9)
    ctx->r1 = MEM_W(ctx->r25, -0X8);
    // 0x80187DD8: sw          $at, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r1;
    // 0x80187DDC: lw          $at, -0x4($t9)
    ctx->r1 = MEM_W(ctx->r25, -0X4);
    // 0x80187DE0: bne         $t9, $t8, L_80187DC4
    if (ctx->r25 != ctx->r24) {
        // 0x80187DE4: sw          $at, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r1;
            goto L_80187DC4;
    }
    // 0x80187DE4: sw          $at, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r1;
    // 0x80187DE8: lw          $at, 0x0($t9)
    ctx->r1 = MEM_W(ctx->r25, 0X0);
    // 0x80187DEC: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x80187DF0: addiu       $t5, $t5, 0x6FAC
    ctx->r13 = ADD32(ctx->r13, 0X6FAC);
    // 0x80187DF4: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x80187DF8: beq         $a0, $zero, L_80187E14
    if (ctx->r4 == 0) {
        // 0x80187DFC: sw          $t7, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->r15;
            goto L_80187E14;
    }
    // 0x80187DFC: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x80187E00: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80187E04: beql        $a0, $at, L_80187E94
    if (ctx->r4 == ctx->r1) {
        // 0x80187E08: lw          $a0, 0x0($a1)
        ctx->r4 = MEM_W(ctx->r5, 0X0);
            goto L_80187E94;
    }
    goto skip_0;
    // 0x80187E08: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    skip_0:
    // 0x80187E0C: b           L_80187F08
    // 0x80187E10: nop

        goto L_80187F08;
    // 0x80187E10: nop

L_80187E14:
    // 0x80187E14: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x80187E18: lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // 0x80187E1C: addiu       $v1, $v1, 0x6D08
    ctx->r3 = ADD32(ctx->r3, 0X6D08);
    // 0x80187E20: blez        $a0, L_80187E7C
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80187E24: addiu       $a1, $sp, 0x13C
        ctx->r5 = ADD32(ctx->r29, 0X13C);
            goto L_80187E7C;
    }
    // 0x80187E24: addiu       $a1, $sp, 0x13C
    ctx->r5 = ADD32(ctx->r29, 0X13C);
    // 0x80187E28: sll         $t9, $a0, 6
    ctx->r25 = S32(ctx->r4 << 6);
    // 0x80187E2C: addu        $a2, $t9, $a1
    ctx->r6 = ADD32(ctx->r25, ctx->r5);
    // 0x80187E30: or          $t9, $a1, $zero
    ctx->r25 = ctx->r5 | 0;
L_80187E34:
    // 0x80187E34: or          $t8, $v1, $zero
    ctx->r24 = ctx->r3 | 0;
    // 0x80187E38: addiu       $t7, $a1, 0x3C
    ctx->r15 = ADD32(ctx->r5, 0X3C);
L_80187E3C:
    // 0x80187E3C: lw          $at, 0x0($t9)
    ctx->r1 = MEM_W(ctx->r25, 0X0);
    // 0x80187E40: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x80187E44: addiu       $t8, $t8, 0xC
    ctx->r24 = ADD32(ctx->r24, 0XC);
    // 0x80187E48: sw          $at, -0xC($t8)
    MEM_W(-0XC, ctx->r24) = ctx->r1;
    // 0x80187E4C: lw          $at, -0x8($t9)
    ctx->r1 = MEM_W(ctx->r25, -0X8);
    // 0x80187E50: sw          $at, -0x8($t8)
    MEM_W(-0X8, ctx->r24) = ctx->r1;
    // 0x80187E54: lw          $at, -0x4($t9)
    ctx->r1 = MEM_W(ctx->r25, -0X4);
    // 0x80187E58: bne         $t9, $t7, L_80187E3C
    if (ctx->r25 != ctx->r15) {
        // 0x80187E5C: sw          $at, -0x4($t8)
        MEM_W(-0X4, ctx->r24) = ctx->r1;
            goto L_80187E3C;
    }
    // 0x80187E5C: sw          $at, -0x4($t8)
    MEM_W(-0X4, ctx->r24) = ctx->r1;
    // 0x80187E60: lw          $at, 0x0($t9)
    ctx->r1 = MEM_W(ctx->r25, 0X0);
    // 0x80187E64: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    // 0x80187E68: addiu       $v1, $v1, 0x40
    ctx->r3 = ADD32(ctx->r3, 0X40);
    // 0x80187E6C: sw          $at, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r1;
    // 0x80187E70: sltu        $at, $a1, $a2
    ctx->r1 = ctx->r5 < ctx->r6 ? 1 : 0;
    // 0x80187E74: bnel        $at, $zero, L_80187E34
    if (ctx->r1 != 0) {
        // 0x80187E78: or          $t9, $a1, $zero
        ctx->r25 = ctx->r5 | 0;
            goto L_80187E34;
    }
    goto skip_1;
    // 0x80187E78: or          $t9, $a1, $zero
    ctx->r25 = ctx->r5 | 0;
    skip_1:
L_80187E7C:
    // 0x80187E7C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80187E80: lwc1        $f4, 0x6468($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6468);
    // 0x80187E84: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80187E88: b           L_80187F08
    // 0x80187E8C: swc1        $f4, 0x6F9C($at)
    MEM_W(0X6F9C, ctx->r1) = ctx->f4.u32l;
        goto L_80187F08;
    // 0x80187E8C: swc1        $f4, 0x6F9C($at)
    MEM_W(0X6F9C, ctx->r1) = ctx->f4.u32l;
    // 0x80187E90: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
L_80187E94:
    // 0x80187E94: lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // 0x80187E98: addiu       $v1, $v1, 0x6D08
    ctx->r3 = ADD32(ctx->r3, 0X6D08);
    // 0x80187E9C: blez        $a0, L_80187EF8
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80187EA0: addiu       $a1, $sp, 0x3C
        ctx->r5 = ADD32(ctx->r29, 0X3C);
            goto L_80187EF8;
    }
    // 0x80187EA0: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x80187EA4: sll         $t7, $a0, 6
    ctx->r15 = S32(ctx->r4 << 6);
    // 0x80187EA8: addu        $a2, $t7, $a1
    ctx->r6 = ADD32(ctx->r15, ctx->r5);
    // 0x80187EAC: or          $t7, $a1, $zero
    ctx->r15 = ctx->r5 | 0;
L_80187EB0:
    // 0x80187EB0: or          $t6, $v1, $zero
    ctx->r14 = ctx->r3 | 0;
    // 0x80187EB4: addiu       $t8, $a1, 0x3C
    ctx->r24 = ADD32(ctx->r5, 0X3C);
L_80187EB8:
    // 0x80187EB8: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x80187EBC: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x80187EC0: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80187EC4: sw          $at, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r1;
    // 0x80187EC8: lw          $at, -0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, -0X8);
    // 0x80187ECC: sw          $at, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r1;
    // 0x80187ED0: lw          $at, -0x4($t7)
    ctx->r1 = MEM_W(ctx->r15, -0X4);
    // 0x80187ED4: bne         $t7, $t8, L_80187EB8
    if (ctx->r15 != ctx->r24) {
        // 0x80187ED8: sw          $at, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r1;
            goto L_80187EB8;
    }
    // 0x80187ED8: sw          $at, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r1;
    // 0x80187EDC: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x80187EE0: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    // 0x80187EE4: addiu       $v1, $v1, 0x40
    ctx->r3 = ADD32(ctx->r3, 0X40);
    // 0x80187EE8: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x80187EEC: sltu        $at, $a1, $a2
    ctx->r1 = ctx->r5 < ctx->r6 ? 1 : 0;
    // 0x80187EF0: bnel        $at, $zero, L_80187EB0
    if (ctx->r1 != 0) {
        // 0x80187EF4: or          $t7, $a1, $zero
        ctx->r15 = ctx->r5 | 0;
            goto L_80187EB0;
    }
    goto skip_2;
    // 0x80187EF4: or          $t7, $a1, $zero
    ctx->r15 = ctx->r5 | 0;
    skip_2:
L_80187EF8:
    // 0x80187EF8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80187EFC: lwc1        $f6, 0x646C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X646C);
    // 0x80187F00: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80187F04: swc1        $f6, 0x6F9C($at)
    MEM_W(0X6F9C, ctx->r1) = ctx->f6.u32l;
L_80187F08:
    // 0x80187F08: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x80187F0C: lui         $t8, 0x8019
    ctx->r24 = S32(0X8019 << 16);
    // 0x80187F10: addiu       $t4, $t8, 0x6FA0
    ctx->r12 = ADD32(ctx->r24, 0X6FA0);
    // 0x80187F14: addiu       $t3, $t9, -0x7DA0
    ctx->r11 = ADD32(ctx->r25, -0X7DA0);
    // 0x80187F18: lui         $s1, 0x8019
    ctx->r17 = S32(0X8019 << 16);
    // 0x80187F1C: addiu       $s1, $s1, 0x790C
    ctx->r17 = ADD32(ctx->r17, 0X790C);
    // 0x80187F20: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    // 0x80187F24: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    // 0x80187F28: addiu       $s0, $zero, 0x32
    ctx->r16 = ADD32(0, 0X32);
L_80187F2C:
    // 0x80187F2C: lw          $at, 0x0($v0)
    ctx->r1 = MEM_W(ctx->r2, 0X0);
    // 0x80187F30: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x80187F34: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x80187F38: sw          $at, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r1;
    // 0x80187F3C: lw          $at, 0x8($v0)
    ctx->r1 = MEM_W(ctx->r2, 0X8);
    // 0x80187F40: sw          $t6, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r14;
    // 0x80187F44: addiu       $a3, $a2, 0x18
    ctx->r7 = ADD32(ctx->r6, 0X18);
    // 0x80187F48: sw          $at, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r1;
    // 0x80187F4C: lw          $at, 0x0($v0)
    ctx->r1 = MEM_W(ctx->r2, 0X0);
    // 0x80187F50: addiu       $t0, $a3, 0xC
    ctx->r8 = ADD32(ctx->r7, 0XC);
    // 0x80187F54: addiu       $t1, $a3, 0x18
    ctx->r9 = ADD32(ctx->r7, 0X18);
    // 0x80187F58: sw          $at, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r1;
    // 0x80187F5C: lw          $at, 0x8($v0)
    ctx->r1 = MEM_W(ctx->r2, 0X8);
    // 0x80187F60: addiu       $t2, $a3, 0x24
    ctx->r10 = ADD32(ctx->r7, 0X24);
    // 0x80187F64: sw          $zero, 0x0($t3)
    MEM_W(0X0, ctx->r11) = 0;
    // 0x80187F68: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
    // 0x80187F6C: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x80187F70: addiu       $a1, $a0, 0x8
    ctx->r5 = ADD32(ctx->r4, 0X8);
    // 0x80187F74: sw          $t8, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r24;
    // 0x80187F78: sw          $at, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->r1;
L_80187F7C:
    // 0x80187F7C: lw          $at, 0x0($v0)
    ctx->r1 = MEM_W(ctx->r2, 0X0);
    // 0x80187F80: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x80187F84: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x80187F88: sw          $at, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r1;
    // 0x80187F8C: lw          $at, 0x8($v0)
    ctx->r1 = MEM_W(ctx->r2, 0X8);
    // 0x80187F90: sw          $t6, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r14;
    // 0x80187F94: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x80187F98: sw          $at, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r1;
    // 0x80187F9C: lw          $at, 0x0($v0)
    ctx->r1 = MEM_W(ctx->r2, 0X0);
    // 0x80187FA0: sw          $t8, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r24;
    // 0x80187FA4: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x80187FA8: sw          $at, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r1;
    // 0x80187FAC: lw          $at, 0x8($v0)
    ctx->r1 = MEM_W(ctx->r2, 0X8);
    // 0x80187FB0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80187FB4: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x80187FB8: sw          $at, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r1;
    // 0x80187FBC: lw          $at, 0x0($v0)
    ctx->r1 = MEM_W(ctx->r2, 0X0);
    // 0x80187FC0: sw          $t6, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r14;
    // 0x80187FC4: sw          $zero, 0x8($a1)
    MEM_W(0X8, ctx->r5) = 0;
    // 0x80187FC8: sw          $at, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r1;
    // 0x80187FCC: lw          $at, 0x8($v0)
    ctx->r1 = MEM_W(ctx->r2, 0X8);
    // 0x80187FD0: sw          $zero, 0xC($a1)
    MEM_W(0XC, ctx->r5) = 0;
    // 0x80187FD4: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x80187FD8: sw          $at, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r1;
    // 0x80187FDC: lw          $at, 0x0($v0)
    ctx->r1 = MEM_W(ctx->r2, 0X0);
    // 0x80187FE0: addiu       $a3, $a3, 0x30
    ctx->r7 = ADD32(ctx->r7, 0X30);
    // 0x80187FE4: addiu       $t0, $t0, 0x30
    ctx->r8 = ADD32(ctx->r8, 0X30);
    // 0x80187FE8: sw          $at, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r1;
    // 0x80187FEC: lw          $at, 0x8($v0)
    ctx->r1 = MEM_W(ctx->r2, 0X8);
    // 0x80187FF0: addiu       $t1, $t1, 0x30
    ctx->r9 = ADD32(ctx->r9, 0X30);
    // 0x80187FF4: addiu       $t2, $t2, 0x30
    ctx->r10 = ADD32(ctx->r10, 0X30);
    // 0x80187FF8: sw          $zero, -0x10($a1)
    MEM_W(-0X10, ctx->r5) = 0;
    // 0x80187FFC: sw          $t8, -0x2C($t2)
    MEM_W(-0X2C, ctx->r10) = ctx->r24;
    // 0x80188000: bne         $v1, $s0, L_80187F7C
    if (ctx->r3 != ctx->r16) {
        // 0x80188004: sw          $at, -0x28($t2)
        MEM_W(-0X28, ctx->r10) = ctx->r1;
            goto L_80187F7C;
    }
    // 0x80188004: sw          $at, -0x28($t2)
    MEM_W(-0X28, ctx->r10) = ctx->r1;
    // 0x80188008: addiu       $t5, $t5, 0x258
    ctx->r13 = ADD32(ctx->r13, 0X258);
    // 0x8018800C: addiu       $a0, $a0, 0xC8
    ctx->r4 = ADD32(ctx->r4, 0XC8);
    // 0x80188010: addiu       $a2, $a2, 0x258
    ctx->r6 = ADD32(ctx->r6, 0X258);
    // 0x80188014: addiu       $t3, $t3, 0xC8
    ctx->r11 = ADD32(ctx->r11, 0XC8);
    // 0x80188018: bne         $t5, $s1, L_80187F2C
    if (ctx->r13 != ctx->r17) {
        // 0x8018801C: addiu       $t4, $t4, 0x258
        ctx->r12 = ADD32(ctx->r12, 0X258);
            goto L_80187F2C;
    }
    // 0x8018801C: addiu       $t4, $t4, 0x258
    ctx->r12 = ADD32(ctx->r12, 0X258);
    // 0x80188020: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x80188024: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x80188028: jr          $ra
    // 0x8018802C: addiu       $sp, $sp, 0x250
    ctx->r29 = ADD32(ctx->r29, 0X250);
    return;
    // 0x8018802C: addiu       $sp, $sp, 0x250
    ctx->r29 = ADD32(ctx->r29, 0X250);
;}
RECOMP_FUNC void Ending_80191234(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80191234: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80191238: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8019123C: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x80191240: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80191244: sh          $t6, 0x1A34($at)
    MEM_H(0X1A34, ctx->r1) = ctx->r14;
    // 0x80191248: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019124C: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x80191250: sw          $t7, 0x7834($at)
    MEM_W(0X7834, ctx->r1) = ctx->r15;
    // 0x80191254: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80191258: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8019125C: sw          $t8, 0x783C($at)
    MEM_W(0X783C, ctx->r1) = ctx->r24;
    // 0x80191260: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80191264: sw          $zero, 0x784C($at)
    MEM_W(0X784C, ctx->r1) = 0;
    // 0x80191268: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019126C: sw          $zero, 0x7898($at)
    MEM_W(0X7898, ctx->r1) = 0;
    // 0x80191270: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80191274: sh          $zero, 0x1A36($at)
    MEM_H(0X1A36, ctx->r1) = 0;
    // 0x80191278: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8019127C: sw          $zero, -0x7BF0($at)
    MEM_W(-0X7BF0, ctx->r1) = 0;
    // 0x80191280: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80191284: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x80191288: sw          $t9, -0x274C($at)
    MEM_W(-0X274C, ctx->r1) = ctx->r25;
    // 0x8019128C: jr          $ra
    // 0x80191290: nop

    return;
    // 0x80191290: nop

;}
RECOMP_FUNC void Ending_80192290(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80192290: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x80192294: lui         $a2, 0x801A
    ctx->r6 = S32(0X801A << 16);
    // 0x80192298: addiu       $a2, $a2, -0x7A30
    ctx->r6 = ADD32(ctx->r6, -0X7A30);
    // 0x8019229C: beq         $a0, $t6, L_80192374
    if (ctx->r4 == ctx->r14) {
        // 0x801922A0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80192374;
    }
    // 0x801922A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801922A4: lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // 0x801922A8: addiu       $v1, $v1, -0x7A20
    ctx->r3 = ADD32(ctx->r3, -0X7A20);
    // 0x801922AC: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
L_801922B0:
    // 0x801922B0: lwc1        $f8, 0x24($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X24);
    // 0x801922B4: lwc1        $f6, 0x18($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X18);
    // 0x801922B8: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801922BC: lwc1        $f18, 0x0($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X0);
    // 0x801922C0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x801922C4: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x801922C8: sub.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x801922CC: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x801922D0: lwc1        $f16, 0x4($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X4);
    // 0x801922D4: swc1        $f4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f4.u32l;
    // 0x801922D8: lwc1        $f6, 0x28($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X28);
    // 0x801922DC: lwc1        $f8, 0x1C($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x801922E0: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x801922E4: sub.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x801922E8: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x801922EC: lwc1        $f18, 0x8($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X8);
    // 0x801922F0: swc1        $f4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f4.u32l;
    // 0x801922F4: lwc1        $f8, 0x2C($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x801922F8: lwc1        $f6, 0x20($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X20);
    // 0x801922FC: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80192300: sub.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80192304: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80192308: lwc1        $f16, 0x0($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8019230C: swc1        $f4, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f4.u32l;
    // 0x80192310: lwc1        $f6, 0x48($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X48);
    // 0x80192314: lwc1        $f8, 0x3C($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X3C);
    // 0x80192318: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8019231C: sub.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80192320: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80192324: lwc1        $f18, 0x4($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X4);
    // 0x80192328: swc1        $f4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f4.u32l;
    // 0x8019232C: lwc1        $f8, 0x4C($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X4C);
    // 0x80192330: lwc1        $f6, 0x40($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X40);
    // 0x80192334: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80192338: sub.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x8019233C: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80192340: lwc1        $f16, 0x8($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X8);
    // 0x80192344: swc1        $f4, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f4.u32l;
    // 0x80192348: lwc1        $f6, 0x50($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X50);
    // 0x8019234C: lwc1        $f8, 0x44($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X44);
    // 0x80192350: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80192354: sub.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80192358: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8019235C: swc1        $f4, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f4.u32l;
    // 0x80192360: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x80192364: subu        $t9, $a0, $t8
    ctx->r25 = SUB32(ctx->r4, ctx->r24);
    // 0x80192368: sltu        $at, $v0, $t9
    ctx->r1 = ctx->r2 < ctx->r25 ? 1 : 0;
    // 0x8019236C: bnel        $at, $zero, L_801922B0
    if (ctx->r1 != 0) {
        // 0x80192370: mtc1        $v0, $f4
        ctx->f4.u32l = ctx->r2;
            goto L_801922B0;
    }
    goto skip_0;
    // 0x80192370: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    skip_0:
L_80192374:
    // 0x80192374: jr          $ra
    // 0x80192378: nop

    return;
    // 0x80192378: nop

;}
RECOMP_FUNC void Ending_8018D28C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D28C: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8018D290: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x8018D294: addiu       $v1, $v1, -0x7BD0
    ctx->r3 = ADD32(ctx->r3, -0X7BD0);
    // 0x8018D298: addiu       $v0, $v0, -0x7BD4
    ctx->r2 = ADD32(ctx->r2, -0X7BD4);
    // 0x8018D29C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8018D2A0: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8018D2A4: lwc1        $f6, 0x18($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X18);
    // 0x8018D2A8: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8018D2AC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8018D2B0: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x8018D2B4: lwc1        $f16, 0x1C($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x8018D2B8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8018D2BC: swc1        $f18, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f18.u32l;
    // 0x8018D2C0: jr          $ra
    // 0x8018D2C4: nop

    return;
    // 0x8018D2C4: nop

;}
RECOMP_FUNC void Ending_8018FC60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018FC60: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8018FC64: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x8018FC68: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x8018FC6C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8018FC70: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8018FC74: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8018FC78: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x8018FC7C: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x8018FC80: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8018FC84: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8018FC88: lbu         $t6, 0x3190($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X3190);
    // 0x8018FC8C: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x8018FC90: addiu       $s1, $s1, 0x7E64
    ctx->r17 = ADD32(ctx->r17, 0X7E64);
    // 0x8018FC94: beq         $t6, $zero, L_80190254
    if (ctx->r14 == 0) {
        // 0x8018FC98: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80190254;
    }
    // 0x8018FC98: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8018FC9C: jal         0x800B8DD0
    // 0x8018FCA0: lh          $a1, 0x8($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X8);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x8018FCA0: lh          $a1, 0x8($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X8);
    after_0:
    // 0x8018FCA4: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8018FCA8: lui         $t8, 0xBC00
    ctx->r24 = S32(0XBC00 << 16);
    // 0x8018FCAC: ori         $t8, $t8, 0x8
    ctx->r24 = ctx->r24 | 0X8;
    // 0x8018FCB0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8018FCB4: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x8018FCB8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8018FCBC: lh          $t9, 0x66($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X66);
    // 0x8018FCC0: lh          $a0, 0x64($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X64);
    // 0x8018FCC4: lui         $t1, 0x1
    ctx->r9 = S32(0X1 << 16);
    // 0x8018FCC8: ori         $t1, $t1, 0xF400
    ctx->r9 = ctx->r9 | 0XF400;
    // 0x8018FCCC: subu        $a1, $t9, $a0
    ctx->r5 = SUB32(ctx->r25, ctx->r4);
    // 0x8018FCD0: div         $zero, $t1, $a1
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r5)));
    // 0x8018FCD4: negu        $t5, $a0
    ctx->r13 = SUB32(0, ctx->r4);
    // 0x8018FCD8: sll         $t6, $t5, 8
    ctx->r14 = S32(ctx->r13 << 8);
    // 0x8018FCDC: addu        $t7, $t6, $t1
    ctx->r15 = ADD32(ctx->r14, ctx->r9);
    // 0x8018FCE0: mflo        $t2
    ctx->r10 = lo;
    // 0x8018FCE4: andi        $t3, $t2, 0xFFFF
    ctx->r11 = ctx->r10 & 0XFFFF;
    // 0x8018FCE8: sll         $t4, $t3, 16
    ctx->r12 = S32(ctx->r11 << 16);
    // 0x8018FCEC: div         $zero, $t7, $a1
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r5)));
    // 0x8018FCF0: mflo        $t8
    ctx->r24 = lo;
    // 0x8018FCF4: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x8018FCF8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8018FCFC: bne         $a1, $zero, L_8018FD08
    if (ctx->r5 != 0) {
        // 0x8018FD00: nop
    
            goto L_8018FD08;
    }
    // 0x8018FD00: nop

    // 0x8018FD04: break       7
    do_break(2149121284);
L_8018FD08:
    // 0x8018FD08: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8018FD0C: bne         $a1, $at, L_8018FD20
    if (ctx->r5 != ctx->r1) {
        // 0x8018FD10: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8018FD20;
    }
    // 0x8018FD10: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8018FD14: bne         $t1, $at, L_8018FD20
    if (ctx->r9 != ctx->r1) {
        // 0x8018FD18: nop
    
            goto L_8018FD20;
    }
    // 0x8018FD18: nop

    // 0x8018FD1C: break       6
    do_break(2149121308);
L_8018FD20:
    // 0x8018FD20: addu        $at, $t1, $zero
    ctx->r1 = ADD32(ctx->r9, 0);
    // 0x8018FD24: or          $t1, $t4, $t9
    ctx->r9 = ctx->r12 | ctx->r25;
    // 0x8018FD28: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x8018FD2C: bne         $a1, $zero, L_8018FD38
    if (ctx->r5 != 0) {
        // 0x8018FD30: nop
    
            goto L_8018FD38;
    }
    // 0x8018FD30: nop

    // 0x8018FD34: break       7
    do_break(2149121332);
L_8018FD38:
    // 0x8018FD38: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8018FD3C: bne         $a1, $at, L_8018FD50
    if (ctx->r5 != ctx->r1) {
        // 0x8018FD40: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8018FD50;
    }
    // 0x8018FD40: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8018FD44: bne         $t7, $at, L_8018FD50
    if (ctx->r15 != ctx->r1) {
        // 0x8018FD48: nop
    
            goto L_8018FD50;
    }
    // 0x8018FD48: nop

    // 0x8018FD4C: break       6
    do_break(2149121356);
L_8018FD50:
    // 0x8018FD50: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8018FD54: lui         $t3, 0xF800
    ctx->r11 = S32(0XF800 << 16);
    // 0x8018FD58: lui         $s2, 0x8014
    ctx->r18 = S32(0X8014 << 16);
    // 0x8018FD5C: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x8018FD60: sw          $t2, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r10;
    // 0x8018FD64: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8018FD68: lbu         $t4, 0x61($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X61);
    // 0x8018FD6C: lbu         $t6, 0x60($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X60);
    // 0x8018FD70: lbu         $t3, 0x62($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X62);
    // 0x8018FD74: sll         $t9, $t4, 16
    ctx->r25 = S32(ctx->r12 << 16);
    // 0x8018FD78: sll         $t7, $t6, 24
    ctx->r15 = S32(ctx->r14 << 24);
    // 0x8018FD7C: or          $t1, $t7, $t9
    ctx->r9 = ctx->r15 | ctx->r25;
    // 0x8018FD80: sll         $t5, $t3, 8
    ctx->r13 = S32(ctx->r11 << 8);
    // 0x8018FD84: or          $t6, $t1, $t5
    ctx->r14 = ctx->r9 | ctx->r13;
    // 0x8018FD88: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8018FD8C: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8018FD90: lui         $t4, 0xFB00
    ctx->r12 = S32(0XFB00 << 16);
    // 0x8018FD94: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8018FD98: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x8018FD9C: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8018FDA0: lbu         $t1, 0x69($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X69);
    // 0x8018FDA4: lbu         $t9, 0x68($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X68);
    // 0x8018FDA8: lbu         $t4, 0x6A($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X6A);
    // 0x8018FDAC: sll         $t5, $t1, 16
    ctx->r13 = S32(ctx->r9 << 16);
    // 0x8018FDB0: lbu         $t1, 0x6B($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X6B);
    // 0x8018FDB4: sll         $t2, $t9, 24
    ctx->r10 = S32(ctx->r25 << 24);
    // 0x8018FDB8: or          $t6, $t2, $t5
    ctx->r14 = ctx->r10 | ctx->r13;
    // 0x8018FDBC: sll         $t7, $t4, 8
    ctx->r15 = S32(ctx->r12 << 8);
    // 0x8018FDC0: or          $t9, $t6, $t7
    ctx->r25 = ctx->r14 | ctx->r15;
    // 0x8018FDC4: or          $t2, $t9, $t1
    ctx->r10 = ctx->r25 | ctx->r9;
    // 0x8018FDC8: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x8018FDCC: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8018FDD0: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x8018FDD4: addiu       $s2, $s2, -0x4C40
    ctx->r18 = ADD32(ctx->r18, -0X4C40);
    // 0x8018FDD8: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x8018FDDC: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
    // 0x8018FDE0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8018FDE4: lbu         $t9, 0x6D($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X6D);
    // 0x8018FDE8: lbu         $t6, 0x6C($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X6C);
    // 0x8018FDEC: lbu         $t8, 0x6E($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X6E);
    // 0x8018FDF0: sll         $t1, $t9, 16
    ctx->r9 = S32(ctx->r25 << 16);
    // 0x8018FDF4: lbu         $t9, 0x6F($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X6F);
    // 0x8018FDF8: sll         $t7, $t6, 24
    ctx->r15 = S32(ctx->r14 << 24);
    // 0x8018FDFC: or          $t2, $t7, $t1
    ctx->r10 = ctx->r15 | ctx->r9;
    // 0x8018FE00: sll         $t4, $t8, 8
    ctx->r12 = S32(ctx->r24 << 8);
    // 0x8018FE04: or          $t6, $t2, $t4
    ctx->r14 = ctx->r10 | ctx->r12;
    // 0x8018FE08: or          $t7, $t6, $t9
    ctx->r15 = ctx->r14 | ctx->r25;
    // 0x8018FE0C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8018FE10: lw          $t1, 0xC($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XC);
    // 0x8018FE14: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8018FE18: subu        $t5, $s3, $t1
    ctx->r13 = SUB32(ctx->r19, ctx->r9);
    // 0x8018FE1C: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x8018FE20: bgez        $t5, L_8018FE38
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8018FE24: cvt.s.w     $f0, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8018FE38;
    }
    // 0x8018FE24: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8018FE28: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8018FE2C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018FE30: nop

    // 0x8018FE34: add.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f6.fl;
L_8018FE38:
    // 0x8018FE38: lwc1        $f10, 0x3C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x8018FE3C: lwc1        $f8, 0x18($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8018FE40: lwc1        $f6, 0x40($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8018FE44: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8018FE48: lwc1        $f4, 0x1C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x8018FE4C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8018FE50: mul.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8018FE54: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x8018FE58: lwc1        $f16, 0x20($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X20);
    // 0x8018FE5C: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8018FE60: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8018FE64: lwc1        $f18, 0x44($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X44);
    // 0x8018FE68: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8018FE6C: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x8018FE70: mul.s       $f6, $f0, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x8018FE74: add.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x8018FE78: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x8018FE7C: jal         0x80005B00
    // 0x8018FE80: nop

    Matrix_Translate(rdram, ctx);
        goto after_1;
    // 0x8018FE80: nop

    after_1:
    // 0x8018FE84: lw          $a1, 0x30($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X30);
    // 0x8018FE88: lw          $a2, 0x34($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X34);
    // 0x8018FE8C: lw          $a3, 0x38($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X38);
    // 0x8018FE90: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8018FE94: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8018FE98: jal         0x80005C34
    // 0x8018FE9C: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_2;
    // 0x8018FE9C: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_2:
    // 0x8018FEA0: mtc1        $s3, $f10
    ctx->f10.u32l = ctx->r19;
    // 0x8018FEA4: bgez        $s3, L_8018FEBC
    if (SIGNED(ctx->r19) >= 0) {
        // 0x8018FEA8: cvt.s.w     $f8, $f10
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
            goto L_8018FEBC;
    }
    // 0x8018FEA8: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8018FEAC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8018FEB0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8018FEB4: nop

    // 0x8018FEB8: add.s       $f8, $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f18.fl;
L_8018FEBC:
    // 0x8018FEBC: lbu         $t4, 0x70($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X70);
    // 0x8018FEC0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018FEC4: lwc1        $f16, 0x6C44($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6C44);
    // 0x8018FEC8: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x8018FECC: mul.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8018FED0: bgez        $t4, L_8018FEE8
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8018FED4: cvt.s.w     $f10, $f4
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8018FEE8;
    }
    // 0x8018FED4: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8018FED8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8018FEDC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8018FEE0: nop

    // 0x8018FEE4: add.s       $f10, $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f18.fl;
L_8018FEE8:
    // 0x8018FEE8: jal         0x80023090
    // 0x8018FEEC: add.s       $f12, $f6, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f10.fl;
    __sinf_recomp(rdram, ctx);
        goto after_3;
    // 0x8018FEEC: add.s       $f12, $f6, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f10.fl;
    after_3:
    // 0x8018FEF0: lbu         $t3, 0x71($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X71);
    // 0x8018FEF4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8018FEF8: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8018FEFC: bnel        $t3, $at, L_80190054
    if (ctx->r11 != ctx->r1) {
        // 0x8018FF00: lwc1        $f10, 0x58($s0)
        ctx->f10.u32l = MEM_W(ctx->r16, 0X58);
            goto L_80190054;
    }
    goto skip_0;
    // 0x8018FF00: lwc1        $f10, 0x58($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X58);
    skip_0:
    // 0x8018FF04: lwc1        $f18, 0x58($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X58);
    // 0x8018FF08: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018FF0C: lwc1        $f16, -0x7A0C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X7A0C);
    // 0x8018FF10: lwc1        $f8, 0x28($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X28);
    // 0x8018FF14: mul.s       $f6, $f0, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x8018FF18: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x8018FF1C: sub.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x8018FF20: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8018FF24: subu        $t9, $s3, $t6
    ctx->r25 = SUB32(ctx->r19, ctx->r14);
    // 0x8018FF28: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x8018FF2C: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8018FF30: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8018FF34: bgez        $t9, L_8018FF48
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8018FF38: cvt.s.w     $f16, $f8
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
            goto L_8018FF48;
    }
    // 0x8018FF38: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8018FF3C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8018FF40: nop

    // 0x8018FF44: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_8018FF48:
    // 0x8018FF48: lwc1        $f4, 0x4C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x8018FF4C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018FF50: lwc1        $f18, 0x6C48($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6C48);
    // 0x8018FF54: mul.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x8018FF58: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018FF5C: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8018FF60: mul.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x8018FF64: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8018FF68: jal         0x80005E90
    // 0x8018FF6C: nop

    Matrix_RotateY(rdram, ctx);
        goto after_4;
    // 0x8018FF6C: nop

    after_4:
    // 0x8018FF70: lwc1        $f8, 0x54($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X54);
    // 0x8018FF74: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018FF78: lwc1        $f10, -0x7A10($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X7A10);
    // 0x8018FF7C: lwc1        $f4, 0x24($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8018FF80: mul.s       $f18, $f20, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f20.fl, ctx->f8.fl);
    // 0x8018FF84: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x8018FF88: sub.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x8018FF8C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8018FF90: subu        $t1, $s3, $t7
    ctx->r9 = SUB32(ctx->r19, ctx->r15);
    // 0x8018FF94: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x8018FF98: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8018FF9C: add.s       $f16, $f6, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x8018FFA0: bgez        $t1, L_8018FFB4
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8018FFA4: cvt.s.w     $f10, $f4
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8018FFB4;
    }
    // 0x8018FFA4: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8018FFA8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018FFAC: nop

    // 0x8018FFB0: add.s       $f10, $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f8.fl;
L_8018FFB4:
    // 0x8018FFB4: lwc1        $f6, 0x48($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X48);
    // 0x8018FFB8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018FFBC: lwc1        $f8, 0x6C4C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6C4C);
    // 0x8018FFC0: mul.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x8018FFC4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018FFC8: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8018FFCC: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8018FFD0: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8018FFD4: jal         0x80005D44
    // 0x8018FFD8: nop

    Matrix_RotateX(rdram, ctx);
        goto after_5;
    // 0x8018FFD8: nop

    after_5:
    // 0x8018FFDC: lwc1        $f4, 0x5C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X5C);
    // 0x8018FFE0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018FFE4: lwc1        $f16, -0x7A08($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X7A08);
    // 0x8018FFE8: lwc1        $f6, 0x2C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8018FFEC: mul.s       $f8, $f20, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f4.fl);
    // 0x8018FFF0: lw          $t5, 0xC($s0)
    ctx->r13 = MEM_W(ctx->r16, 0XC);
    // 0x8018FFF4: add.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x8018FFF8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8018FFFC: subu        $t8, $s3, $t5
    ctx->r24 = SUB32(ctx->r19, ctx->r13);
    // 0x80190000: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x80190004: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80190008: add.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x8019000C: bgez        $t8, L_80190020
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80190010: cvt.s.w     $f16, $f6
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
            goto L_80190020;
    }
    // 0x80190010: cvt.s.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80190014: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80190018: nop

    // 0x8019001C: add.s       $f16, $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f4.fl;
L_80190020:
    // 0x80190020: lwc1        $f18, 0x50($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80190024: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80190028: lwc1        $f4, 0x6C50($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6C50);
    // 0x8019002C: mul.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80190030: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80190034: add.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80190038: mul.s       $f16, $f6, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x8019003C: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x80190040: jal         0x80005FE0
    // 0x80190044: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_6;
    // 0x80190044: nop

    after_6:
    // 0x80190048: b           L_80190170
    // 0x8019004C: nop

        goto L_80190170;
    // 0x8019004C: nop

    // 0x80190050: lwc1        $f10, 0x58($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X58);
L_80190054:
    // 0x80190054: lw          $t2, 0xC($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XC);
    // 0x80190058: lwc1        $f18, 0x28($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X28);
    // 0x8019005C: mul.s       $f8, $f20, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f10.fl);
    // 0x80190060: subu        $t4, $s3, $t2
    ctx->r12 = SUB32(ctx->r19, ctx->r10);
    // 0x80190064: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x80190068: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8019006C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80190070: cvt.s.w     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80190074: bgez        $t4, L_80190088
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80190078: add.s       $f6, $f18, $f8
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f8.fl;
            goto L_80190088;
    }
    // 0x80190078: add.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x8019007C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80190080: nop

    // 0x80190084: add.s       $f16, $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f10.fl;
L_80190088:
    // 0x80190088: lwc1        $f18, 0x4C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x8019008C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80190090: lwc1        $f10, 0x6C54($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6C54);
    // 0x80190094: mul.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80190098: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8019009C: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801900A0: mul.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x801900A4: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x801900A8: jal         0x80005E90
    // 0x801900AC: nop

    Matrix_RotateY(rdram, ctx);
        goto after_7;
    // 0x801900AC: nop

    after_7:
    // 0x801900B0: lwc1        $f6, 0x54($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X54);
    // 0x801900B4: lw          $t3, 0xC($s0)
    ctx->r11 = MEM_W(ctx->r16, 0XC);
    // 0x801900B8: lwc1        $f18, 0x24($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X24);
    // 0x801900BC: mul.s       $f8, $f20, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f6.fl);
    // 0x801900C0: subu        $t6, $s3, $t3
    ctx->r14 = SUB32(ctx->r19, ctx->r11);
    // 0x801900C4: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x801900C8: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x801900CC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801900D0: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801900D4: bgez        $t6, L_801900E8
    if (SIGNED(ctx->r14) >= 0) {
        // 0x801900D8: add.s       $f4, $f18, $f8
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f8.fl;
            goto L_801900E8;
    }
    // 0x801900D8: add.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x801900DC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801900E0: nop

    // 0x801900E4: add.s       $f16, $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f6.fl;
L_801900E8:
    // 0x801900E8: lwc1        $f18, 0x48($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X48);
    // 0x801900EC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801900F0: lwc1        $f6, 0x6C58($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6C58);
    // 0x801900F4: mul.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x801900F8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801900FC: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80190100: mul.s       $f16, $f10, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x80190104: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x80190108: jal         0x80005D44
    // 0x8019010C: nop

    Matrix_RotateX(rdram, ctx);
        goto after_8;
    // 0x8019010C: nop

    after_8:
    // 0x80190110: lwc1        $f4, 0x5C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X5C);
    // 0x80190114: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    // 0x80190118: lwc1        $f18, 0x2C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8019011C: mul.s       $f8, $f20, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f4.fl);
    // 0x80190120: subu        $t7, $s3, $t9
    ctx->r15 = SUB32(ctx->r19, ctx->r25);
    // 0x80190124: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x80190128: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8019012C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80190130: cvt.s.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80190134: bgez        $t7, L_80190148
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80190138: add.s       $f10, $f18, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f8.fl;
            goto L_80190148;
    }
    // 0x80190138: add.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x8019013C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80190140: nop

    // 0x80190144: add.s       $f16, $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f4.fl;
L_80190148:
    // 0x80190148: lwc1        $f18, 0x50($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X50);
    // 0x8019014C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80190150: lwc1        $f4, 0x6C5C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6C5C);
    // 0x80190154: mul.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80190158: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8019015C: add.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80190160: mul.s       $f16, $f6, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x80190164: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x80190168: jal         0x80005FE0
    // 0x8019016C: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_9;
    // 0x8019016C: nop

    after_9:
L_80190170:
    // 0x80190170: jal         0x80006EB8
    // 0x80190174: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_10;
    // 0x80190174: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_10:
    // 0x80190178: lui         $s0, 0x600
    ctx->r16 = S32(0X600 << 16);
    // 0x8019017C: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80190180: lui         $t5, 0xD01
    ctx->r13 = S32(0XD01 << 16);
    // 0x80190184: addiu       $t5, $t5, -0x4780
    ctx->r13 = ADD32(ctx->r13, -0X4780);
    // 0x80190188: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x8019018C: sw          $t1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r9;
    // 0x80190190: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x80190194: sw          $s0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r16;
    // 0x80190198: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8019019C: jal         0x800B8DD0
    // 0x801901A0: addiu       $a1, $zero, 0x43
    ctx->r5 = ADD32(0, 0X43);
    RCP_SetupDL(rdram, ctx);
        goto after_11;
    // 0x801901A0: addiu       $a1, $zero, 0x43
    ctx->r5 = ADD32(0, 0X43);
    after_11:
    // 0x801901A4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801901A8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801901AC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x801901B0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801901B4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801901B8: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x801901BC: jal         0x80005B00
    // 0x801901C0: lui         $a3, 0xC248
    ctx->r7 = S32(0XC248 << 16);
    Matrix_Translate(rdram, ctx);
        goto after_12;
    // 0x801901C0: lui         $a3, 0xC248
    ctx->r7 = S32(0XC248 << 16);
    after_12:
    // 0x801901C4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801901C8: divu        $zero, $s3, $at
    lo = S32(U32(ctx->r19) / U32(ctx->r1)); hi = S32(U32(ctx->r19) % U32(ctx->r1));
    // 0x801901CC: mfhi        $t2
    ctx->r10 = hi;
    // 0x801901D0: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x801901D4: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x801901D8: bgez        $t2, L_801901F0
    if (SIGNED(ctx->r10) >= 0) {
        // 0x801901DC: cvt.s.w     $f10, $f18
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.fl = CVT_S_W(ctx->f18.u32l);
            goto L_801901F0;
    }
    // 0x801901DC: cvt.s.w     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.fl = CVT_S_W(ctx->f18.u32l);
    // 0x801901E0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801901E4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801901E8: nop

    // 0x801901EC: add.s       $f10, $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f8.fl;
L_801901F0:
    // 0x801901F0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801901F4: lwc1        $f6, 0x6C60($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6C60);
    // 0x801901F8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801901FC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80190200: mul.s       $f0, $f10, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x80190204: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80190208: lwc1        $f16, 0x6C64($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6C64);
    // 0x8019020C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80190210: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80190214: add.s       $f2, $f0, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80190218: add.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x8019021C: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80190220: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80190224: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80190228: jal         0x80005C34
    // 0x8019022C: nop

    Matrix_Scale(rdram, ctx);
        goto after_13;
    // 0x8019022C: nop

    after_13:
    // 0x80190230: jal         0x80006EB8
    // 0x80190234: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_14;
    // 0x80190234: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_14:
    // 0x80190238: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8019023C: lui         $t6, 0x701
    ctx->r14 = S32(0X701 << 16);
    // 0x80190240: addiu       $t6, $t6, 0x970
    ctx->r14 = ADD32(ctx->r14, 0X970);
    // 0x80190244: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x80190248: sw          $t3, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r11;
    // 0x8019024C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80190250: sw          $s0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r16;
L_80190254:
    // 0x80190254: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80190258: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8019025C: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x80190260: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x80190264: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x80190268: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x8019026C: jr          $ra
    // 0x80190270: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80190270: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void Ending_8018D814(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D814: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8018D818: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x8018D81C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8018D820: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8018D824: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x8018D828: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8018D82C: lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC);
    // 0x8018D830: lh          $v1, 0x64($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X64);
    // 0x8018D834: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x8018D838: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x8018D83C: addu        $t6, $v0, $v1
    ctx->r14 = ADD32(ctx->r2, ctx->r3);
    // 0x8018D840: sltu        $at, $a0, $t6
    ctx->r1 = ctx->r4 < ctx->r14 ? 1 : 0;
    // 0x8018D844: beq         $at, $zero, L_8018D874
    if (ctx->r1 == 0) {
        // 0x8018D848: addiu       $s1, $s1, 0x7E64
        ctx->r17 = ADD32(ctx->r17, 0X7E64);
            goto L_8018D874;
    }
    // 0x8018D848: addiu       $s1, $s1, 0x7E64
    ctx->r17 = ADD32(ctx->r17, 0X7E64);
    // 0x8018D84C: subu        $t7, $a0, $v0
    ctx->r15 = SUB32(ctx->r4, ctx->r2);
    // 0x8018D850: sll         $t8, $t7, 8
    ctx->r24 = S32(ctx->r15 << 8);
    // 0x8018D854: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8018D858: divu        $zero, $t8, $v1
    lo = S32(U32(ctx->r24) / U32(ctx->r3)); hi = S32(U32(ctx->r24) % U32(ctx->r3));
    // 0x8018D85C: mflo        $t0
    ctx->r8 = lo;
    // 0x8018D860: andi        $t9, $t0, 0xFF
    ctx->r25 = ctx->r8 & 0XFF;
    // 0x8018D864: or          $t0, $t9, $zero
    ctx->r8 = ctx->r25 | 0;
    // 0x8018D868: bne         $v1, $zero, L_8018D874
    if (ctx->r3 != 0) {
        // 0x8018D86C: nop
    
            goto L_8018D874;
    }
    // 0x8018D86C: nop

    // 0x8018D870: break       7
    do_break(2149111920);
L_8018D874:
    // 0x8018D874: lw          $t1, 0x10($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X10);
    // 0x8018D878: lh          $a1, 0x66($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X66);
    // 0x8018D87C: addu        $v1, $v0, $t1
    ctx->r3 = ADD32(ctx->r2, ctx->r9);
    // 0x8018D880: subu        $t2, $v1, $a1
    ctx->r10 = SUB32(ctx->r3, ctx->r5);
    // 0x8018D884: sltu        $at, $t2, $a0
    ctx->r1 = ctx->r10 < ctx->r4 ? 1 : 0;
    // 0x8018D888: beq         $at, $zero, L_8018D8B4
    if (ctx->r1 == 0) {
        // 0x8018D88C: subu        $t3, $v1, $a0
        ctx->r11 = SUB32(ctx->r3, ctx->r4);
            goto L_8018D8B4;
    }
    // 0x8018D88C: subu        $t3, $v1, $a0
    ctx->r11 = SUB32(ctx->r3, ctx->r4);
    // 0x8018D890: sll         $t4, $t3, 8
    ctx->r12 = S32(ctx->r11 << 8);
    // 0x8018D894: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x8018D898: divu        $zero, $t4, $a1
    lo = S32(U32(ctx->r12) / U32(ctx->r5)); hi = S32(U32(ctx->r12) % U32(ctx->r5));
    // 0x8018D89C: mflo        $t0
    ctx->r8 = lo;
    // 0x8018D8A0: andi        $t5, $t0, 0xFF
    ctx->r13 = ctx->r8 & 0XFF;
    // 0x8018D8A4: or          $t0, $t5, $zero
    ctx->r8 = ctx->r13 | 0;
    // 0x8018D8A8: bne         $a1, $zero, L_8018D8B4
    if (ctx->r5 != 0) {
        // 0x8018D8AC: nop
    
            goto L_8018D8B4;
    }
    // 0x8018D8AC: nop

    // 0x8018D8B0: break       7
    do_break(2149111984);
L_8018D8B4:
    // 0x8018D8B4: lh          $a1, 0x8($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X8);
    // 0x8018D8B8: sb          $t0, 0x3F($sp)
    MEM_B(0X3F, ctx->r29) = ctx->r8;
    // 0x8018D8BC: jal         0x800B8DD0
    // 0x8018D8C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x8018D8C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x8018D8C4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8018D8C8: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8018D8CC: lbu         $t0, 0x3F($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X3F);
    // 0x8018D8D0: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8018D8D4: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x8018D8D8: andi        $t2, $t0, 0xFF
    ctx->r10 = ctx->r8 & 0XFF;
    // 0x8018D8DC: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8018D8E0: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x8018D8E4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8018D8E8: lbu         $t3, 0x6D($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X6D);
    // 0x8018D8EC: lbu         $t9, 0x6C($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X6C);
    // 0x8018D8F0: lbu         $t7, 0x6E($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X6E);
    // 0x8018D8F4: sll         $t4, $t3, 16
    ctx->r12 = S32(ctx->r11 << 16);
    // 0x8018D8F8: sll         $t1, $t9, 24
    ctx->r9 = S32(ctx->r25 << 24);
    // 0x8018D8FC: or          $t5, $t1, $t4
    ctx->r13 = ctx->r9 | ctx->r12;
    // 0x8018D900: sll         $t8, $t7, 8
    ctx->r24 = S32(ctx->r15 << 8);
    // 0x8018D904: or          $t9, $t5, $t8
    ctx->r25 = ctx->r13 | ctx->r24;
    // 0x8018D908: or          $t3, $t9, $t2
    ctx->r11 = ctx->r25 | ctx->r10;
    // 0x8018D90C: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x8018D910: lwc1        $f4, 0x18($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8018D914: lui         $a1, 0x500
    ctx->r5 = S32(0X500 << 16);
    // 0x8018D918: addiu       $a1, $a1, 0x7240
    ctx->r5 = ADD32(ctx->r5, 0X7240);
    // 0x8018D91C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8018D920: lwc1        $f6, 0x1C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x8018D924: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8018D928: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x8018D92C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8018D930: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x8018D934: addiu       $a3, $zero, 0xF
    ctx->r7 = ADD32(0, 0XF);
    // 0x8018D938: jal         0x8009D994
    // 0x8018D93C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_1;
    // 0x8018D93C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x8018D940: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x8018D944: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018D948: lwc1        $f8, 0x18($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8018D94C: lui         $a1, 0x500
    ctx->r5 = S32(0X500 << 16);
    // 0x8018D950: addiu       $a1, $a1, 0x7420
    ctx->r5 = ADD32(ctx->r5, 0X7420);
    // 0x8018D954: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8018D958: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8018D95C: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x8018D960: addiu       $a3, $zero, 0xF
    ctx->r7 = ADD32(0, 0XF);
    // 0x8018D964: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x8018D968: lwc1        $f18, 0x1C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x8018D96C: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8018D970: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x8018D974: jal         0x8009D994
    // 0x8018D978: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_2;
    // 0x8018D978: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_2:
    // 0x8018D97C: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x8018D980: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018D984: lwc1        $f4, 0x18($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8018D988: lui         $a1, 0x500
    ctx->r5 = S32(0X500 << 16);
    // 0x8018D98C: addiu       $a1, $a1, 0x7420
    ctx->r5 = ADD32(ctx->r5, 0X7420);
    // 0x8018D990: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8018D994: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8018D998: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x8018D99C: addiu       $a3, $zero, 0xF
    ctx->r7 = ADD32(0, 0XF);
    // 0x8018D9A0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x8018D9A4: lwc1        $f10, 0x1C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x8018D9A8: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8018D9AC: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x8018D9B0: jal         0x8009D994
    // 0x8018D9B4: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_3;
    // 0x8018D9B4: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_3:
    // 0x8018D9B8: lui         $at, 0x4240
    ctx->r1 = S32(0X4240 << 16);
    // 0x8018D9BC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8018D9C0: lwc1        $f16, 0x18($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8018D9C4: lui         $a1, 0x500
    ctx->r5 = S32(0X500 << 16);
    // 0x8018D9C8: addiu       $a1, $a1, 0x7330
    ctx->r5 = ADD32(ctx->r5, 0X7330);
    // 0x8018D9CC: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8018D9D0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8018D9D4: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x8018D9D8: addiu       $a3, $zero, 0xF
    ctx->r7 = ADD32(0, 0XF);
    // 0x8018D9DC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8018D9E0: lwc1        $f6, 0x1C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x8018D9E4: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8018D9E8: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x8018D9EC: jal         0x8009D994
    // 0x8018D9F0: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_4;
    // 0x8018D9F0: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_4:
    // 0x8018D9F4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8018D9F8: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8018D9FC: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x8018DA00: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x8018DA04: jr          $ra
    // 0x8018DA08: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8018DA08: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void Ending_80187520(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80187520: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80187524: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x80187528: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x8018752C: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x80187530: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80187534: addiu       $s2, $s2, 0x7E64
    ctx->r18 = ADD32(ctx->r18, 0X7E64);
    // 0x80187538: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8018753C: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x80187540: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x80187544: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x80187548: sdc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X30, ctx->r29);
    // 0x8018754C: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x80187550: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80187554: jal         0x800B8DD0
    // 0x80187558: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x80187558: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    after_0:
    // 0x8018755C: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x80187560: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x80187564: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80187568: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8018756C: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
    // 0x80187570: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80187574: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80187578: beq         $s0, $zero, L_80187594
    if (ctx->r16 == 0) {
        // 0x8018757C: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_80187594;
    }
    // 0x8018757C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80187580: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80187584: beq         $s0, $at, L_80187624
    if (ctx->r16 == ctx->r1) {
        // 0x80187588: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_80187624;
    }
    // 0x80187588: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8018758C: b           L_80187680
    // 0x80187590: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
        goto L_80187680;
    // 0x80187590: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_80187594:
    // 0x80187594: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80187598: lui         $s3, 0x800
    ctx->r19 = S32(0X800 << 16);
    // 0x8018759C: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x801875A0: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x801875A4: addiu       $s3, $s3, 0x0
    ctx->r19 = ADD32(ctx->r19, 0X0);
    // 0x801875A8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801875AC: addiu       $s4, $zero, 0x10C
    ctx->r20 = ADD32(0, 0X10C);
L_801875B0:
    // 0x801875B0: mtc1        $s0, $f4
    ctx->f4.u32l = ctx->r16;
    // 0x801875B4: sll         $t9, $s1, 1
    ctx->r25 = S32(ctx->r17 << 1);
    // 0x801875B8: addu        $a1, $s3, $t9
    ctx->r5 = ADD32(ctx->r19, ctx->r25);
    // 0x801875BC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801875C0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x801875C4: addiu       $a2, $zero, 0x13C
    ctx->r6 = ADD32(0, 0X13C);
    // 0x801875C8: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x801875CC: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    // 0x801875D0: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x801875D4: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x801875D8: jal         0x8009D418
    // 0x801875DC: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    Lib_TextureRect_RGBA16(rdram, ctx);
        goto after_1;
    // 0x801875DC: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    after_1:
    // 0x801875E0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x801875E4: bne         $s0, $s4, L_801875B0
    if (ctx->r16 != ctx->r20) {
        // 0x801875E8: addiu       $s1, $s1, 0x4F0
        ctx->r17 = ADD32(ctx->r17, 0X4F0);
            goto L_801875B0;
    }
    // 0x801875E8: addiu       $s1, $s1, 0x4F0
    ctx->r17 = ADD32(ctx->r17, 0X4F0);
    // 0x801875EC: mtc1        $s0, $f8
    ctx->f8.u32l = ctx->r16;
    // 0x801875F0: sll         $t0, $s1, 1
    ctx->r8 = S32(ctx->r17 << 1);
    // 0x801875F4: addu        $a1, $s3, $t0
    ctx->r5 = ADD32(ctx->r19, ctx->r8);
    // 0x801875F8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801875FC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80187600: addiu       $a2, $zero, 0x13C
    ctx->r6 = ADD32(0, 0X13C);
    // 0x80187604: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80187608: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    // 0x8018760C: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x80187610: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    // 0x80187614: jal         0x8009D418
    // 0x80187618: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    Lib_TextureRect_RGBA16(rdram, ctx);
        goto after_2;
    // 0x80187618: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    after_2:
    // 0x8018761C: b           L_80187680
    // 0x80187620: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
        goto L_80187680;
    // 0x80187620: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_80187624:
    // 0x80187624: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80187628: lui         $s3, 0x800
    ctx->r19 = S32(0X800 << 16);
    // 0x8018762C: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80187630: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x80187634: addiu       $s3, $s3, 0x0
    ctx->r19 = ADD32(ctx->r19, 0X0);
    // 0x80187638: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8018763C: addiu       $s4, $zero, 0xF0
    ctx->r20 = ADD32(0, 0XF0);
L_80187640:
    // 0x80187640: mtc1        $s0, $f16
    ctx->f16.u32l = ctx->r16;
    // 0x80187644: sll         $t1, $s1, 1
    ctx->r9 = S32(ctx->r17 << 1);
    // 0x80187648: addu        $a1, $s3, $t1
    ctx->r5 = ADD32(ctx->r19, ctx->r9);
    // 0x8018764C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80187650: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80187654: addiu       $a2, $zero, 0x13C
    ctx->r6 = ADD32(0, 0X13C);
    // 0x80187658: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x8018765C: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    // 0x80187660: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x80187664: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x80187668: jal         0x8009D418
    // 0x8018766C: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    Lib_TextureRect_RGBA16(rdram, ctx);
        goto after_3;
    // 0x8018766C: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    after_3:
    // 0x80187670: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80187674: bne         $s0, $s4, L_80187640
    if (ctx->r16 != ctx->r20) {
        // 0x80187678: addiu       $s1, $s1, 0x4F0
        ctx->r17 = ADD32(ctx->r17, 0X4F0);
            goto L_80187640;
    }
    // 0x80187678: addiu       $s1, $s1, 0x4F0
    ctx->r17 = ADD32(ctx->r17, 0X4F0);
    // 0x8018767C: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_80187680:
    // 0x80187680: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x80187684: ldc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X30);
    // 0x80187688: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x8018768C: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x80187690: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x80187694: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x80187698: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x8018769C: jr          $ra
    // 0x801876A0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x801876A0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void Ending_80190648(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80190648: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8019064C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80190650: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80190654: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80190658: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8019065C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80190660: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x80190664: jal         0x800B8DD0
    // 0x80190668: lh          $a1, 0x8($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X8);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x80190668: lh          $a1, 0x8($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X8);
    after_0:
    // 0x8019066C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80190670: lwc1        $f4, 0x6C78($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6C78);
    // 0x80190674: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80190678: lwc1        $f6, -0x7A0C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7A0C);
    // 0x8019067C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80190680: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80190684: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80190688: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8019068C: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80190690: jal         0x80005E90
    // 0x80190694: nop

    Matrix_RotateY(rdram, ctx);
        goto after_1;
    // 0x80190694: nop

    after_1:
    // 0x80190698: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8019069C: lwc1        $f10, 0x6C7C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6C7C);
    // 0x801906A0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801906A4: lwc1        $f16, -0x7A10($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X7A10);
    // 0x801906A8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801906AC: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x801906B0: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x801906B4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801906B8: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x801906BC: jal         0x80005D44
    // 0x801906C0: nop

    Matrix_RotateX(rdram, ctx);
        goto after_2;
    // 0x801906C0: nop

    after_2:
    // 0x801906C4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801906C8: lwc1        $f4, 0x6C80($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6C80);
    // 0x801906CC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801906D0: lwc1        $f6, -0x7A08($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7A08);
    // 0x801906D4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801906D8: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x801906DC: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x801906E0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801906E4: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x801906E8: jal         0x80005FE0
    // 0x801906EC: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_3;
    // 0x801906EC: nop

    after_3:
    // 0x801906F0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801906F4: lw          $a1, 0x18($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X18);
    // 0x801906F8: lw          $a2, 0x1C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X1C);
    // 0x801906FC: lw          $a3, 0x20($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X20);
    // 0x80190700: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80190704: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80190708: jal         0x80005B00
    // 0x8019070C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Translate(rdram, ctx);
        goto after_4;
    // 0x8019070C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_4:
    // 0x80190710: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80190714: lw          $a1, 0x30($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X30);
    // 0x80190718: lw          $a2, 0x34($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X34);
    // 0x8019071C: lw          $a3, 0x38($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X38);
    // 0x80190720: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80190724: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80190728: jal         0x80005C34
    // 0x8019072C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Scale(rdram, ctx);
        goto after_5;
    // 0x8019072C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_5:
    // 0x80190730: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80190734: jal         0x80006EB8
    // 0x80190738: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_6;
    // 0x80190738: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    after_6:
    // 0x8019073C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80190740: lw          $v1, 0x7E64($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7E64);
    // 0x80190744: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80190748: lui         $t0, 0x700
    ctx->r8 = S32(0X700 << 16);
    // 0x8019074C: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80190750: sw          $t8, 0x7E64($at)
    MEM_W(0X7E64, ctx->r1) = ctx->r24;
    // 0x80190754: addiu       $t0, $t0, 0x2120
    ctx->r8 = ADD32(ctx->r8, 0X2120);
    // 0x80190758: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x8019075C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80190760: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x80190764: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80190768: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8019076C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80190770: jr          $ra
    // 0x80190774: nop

    return;
    // 0x80190774: nop

;}
RECOMP_FUNC void Ending_80187860(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80187860: addiu       $sp, $sp, -0x2E0
    ctx->r29 = ADD32(ctx->r29, -0X2E0);
    // 0x80187864: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x80187868: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x8018786C: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x80187870: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x80187874: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x80187878: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x8018787C: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x80187880: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x80187884: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x80187888: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8018788C: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x80187890: sw          $a1, 0x2E4($sp)
    MEM_W(0X2E4, ctx->r29) = ctx->r5;
    // 0x80187894: lui         $t7, 0x8019
    ctx->r15 = S32(0X8019 << 16);
    // 0x80187898: addiu       $t7, $t7, 0x2820
    ctx->r15 = ADD32(ctx->r15, 0X2820);
    // 0x8018789C: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x801878A0: lw          $t1, 0x4($t7)
    ctx->r9 = MEM_W(ctx->r15, 0X4);
    // 0x801878A4: addiu       $t6, $sp, 0x70
    ctx->r14 = ADD32(ctx->r29, 0X70);
    // 0x801878A8: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x801878AC: sw          $t1, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r9;
    // 0x801878B0: lw          $t1, 0xC($t7)
    ctx->r9 = MEM_W(ctx->r15, 0XC);
    // 0x801878B4: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x801878B8: lui         $t2, 0x8019
    ctx->r10 = S32(0X8019 << 16);
    // 0x801878BC: sw          $t1, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r9;
    // 0x801878C0: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x801878C4: lw          $t2, 0x6F88($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X6F88);
    // 0x801878C8: lui         $t3, 0x8019
    ctx->r11 = S32(0X8019 << 16);
    // 0x801878CC: addiu       $t3, $t3, -0x639C
    ctx->r11 = ADD32(ctx->r11, -0X639C);
    // 0x801878D0: slt         $at, $a0, $t2
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x801878D4: beq         $at, $zero, L_80187D08
    if (ctx->r1 == 0) {
        // 0x801878D8: sw          $a0, 0x84($sp)
        MEM_W(0X84, ctx->r29) = ctx->r4;
            goto L_80187D08;
    }
    // 0x801878D8: sw          $a0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r4;
    // 0x801878DC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801878E0: lui         $s5, 0x8019
    ctx->r21 = S32(0X8019 << 16);
    // 0x801878E4: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x801878E8: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x801878EC: lui         $s0, 0x8019
    ctx->r16 = S32(0X8019 << 16);
    // 0x801878F0: addiu       $s0, $s0, 0x6D08
    ctx->r16 = ADD32(ctx->r16, 0X6D08);
    // 0x801878F4: addiu       $s1, $s1, -0x4C40
    ctx->r17 = ADD32(ctx->r17, -0X4C40);
    // 0x801878F8: addiu       $s4, $s4, 0x7E64
    ctx->r20 = ADD32(ctx->r20, 0X7E64);
    // 0x801878FC: addiu       $s5, $s5, 0x7900
    ctx->r21 = ADD32(ctx->r21, 0X7900);
    // 0x80187900: lwc1        $f20, 0x645C($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X645C);
    // 0x80187904: sw          $t3, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r11;
    // 0x80187908: addiu       $fp, $zero, 0x2
    ctx->r30 = ADD32(0, 0X2);
    // 0x8018790C: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
    // 0x80187910: addiu       $s6, $zero, 0x258
    ctx->r22 = ADD32(0, 0X258);
    // 0x80187914: lw          $s3, 0x80($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X80);
    // 0x80187918: addiu       $s2, $sp, 0x88
    ctx->r18 = ADD32(ctx->r29, 0X88);
L_8018791C:
    // 0x8018791C: jal         0x80005708
    // 0x80187920: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Push(rdram, ctx);
        goto after_0;
    // 0x80187920: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x80187924: lw          $t4, 0x84($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X84);
    // 0x80187928: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8018792C: sll         $t5, $t4, 6
    ctx->r13 = S32(ctx->r12 << 6);
    // 0x80187930: addu        $t9, $s0, $t5
    ctx->r25 = ADD32(ctx->r16, ctx->r13);
    // 0x80187934: jal         0x800B8DD0
    // 0x80187938: lh          $a1, 0x8($t9)
    ctx->r5 = MEM_H(ctx->r25, 0X8);
    RCP_SetupDL(rdram, ctx);
        goto after_1;
    // 0x80187938: lh          $a1, 0x8($t9)
    ctx->r5 = MEM_H(ctx->r25, 0X8);
    after_1:
    // 0x8018793C: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x80187940: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x80187944: addiu       $t8, $a0, 0x8
    ctx->r24 = ADD32(ctx->r4, 0X8);
    // 0x80187948: sw          $t8, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r24;
    // 0x8018794C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80187950: lw          $t7, 0x84($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X84);
    // 0x80187954: sll         $t1, $t7, 6
    ctx->r9 = S32(ctx->r15 << 6);
    // 0x80187958: addu        $v1, $s0, $t1
    ctx->r3 = ADD32(ctx->r16, ctx->r9);
    // 0x8018795C: lbu         $t5, 0x3C($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X3C);
    // 0x80187960: lbu         $t3, 0x3F($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X3F);
    // 0x80187964: lbu         $t7, 0x3D($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X3D);
    // 0x80187968: sll         $t9, $t5, 24
    ctx->r25 = S32(ctx->r13 << 24);
    // 0x8018796C: lbu         $t5, 0x3E($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X3E);
    // 0x80187970: or          $t8, $t3, $t9
    ctx->r24 = ctx->r11 | ctx->r25;
    // 0x80187974: sll         $t1, $t7, 16
    ctx->r9 = S32(ctx->r15 << 16);
    // 0x80187978: or          $t2, $t8, $t1
    ctx->r10 = ctx->r24 | ctx->r9;
    // 0x8018797C: sll         $t3, $t5, 8
    ctx->r11 = S32(ctx->r13 << 8);
    // 0x80187980: or          $t9, $t2, $t3
    ctx->r25 = ctx->r10 | ctx->r11;
    // 0x80187984: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x80187988: lw          $t6, 0x84($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X84);
    // 0x8018798C: beq         $t6, $s7, L_8018799C
    if (ctx->r14 == ctx->r23) {
        // 0x80187990: lw          $t0, 0x84($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X84);
            goto L_8018799C;
    }
    // 0x80187990: lw          $t0, 0x84($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X84);
    // 0x80187994: bne         $t6, $fp, L_801879DC
    if (ctx->r14 != ctx->r30) {
        // 0x80187998: lw          $t1, 0x84($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X84);
            goto L_801879DC;
    }
    // 0x80187998: lw          $t1, 0x84($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X84);
L_8018799C:
    // 0x8018799C: sll         $t7, $t0, 6
    ctx->r15 = S32(ctx->r8 << 6);
    // 0x801879A0: addu        $v1, $s0, $t7
    ctx->r3 = ADD32(ctx->r16, ctx->r15);
    // 0x801879A4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801879A8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801879AC: lwc1        $f4, 0x10($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X10);
    // 0x801879B0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801879B4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x801879B8: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801879BC: lw          $a1, 0xC($v1)
    ctx->r5 = MEM_W(ctx->r3, 0XC);
    // 0x801879C0: lw          $a3, 0x14($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X14);
    // 0x801879C4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801879C8: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x801879CC: jal         0x80005B00
    // 0x801879D0: nop

    Matrix_Translate(rdram, ctx);
        goto after_2;
    // 0x801879D0: nop

    after_2:
    // 0x801879D4: b           L_80187A04
    // 0x801879D8: lw          $t2, 0x84($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X84);
        goto L_80187A04;
    // 0x801879D8: lw          $t2, 0x84($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X84);
L_801879DC:
    // 0x801879DC: sll         $t4, $t1, 6
    ctx->r12 = S32(ctx->r9 << 6);
    // 0x801879E0: addu        $v1, $s0, $t4
    ctx->r3 = ADD32(ctx->r16, ctx->r12);
    // 0x801879E4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801879E8: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x801879EC: lw          $a1, 0xC($v1)
    ctx->r5 = MEM_W(ctx->r3, 0XC);
    // 0x801879F0: lw          $a2, 0x10($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X10);
    // 0x801879F4: lw          $a3, 0x14($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X14);
    // 0x801879F8: jal         0x80005B00
    // 0x801879FC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_3;
    // 0x801879FC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_3:
    // 0x80187A00: lw          $t2, 0x84($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X84);
L_80187A04:
    // 0x80187A04: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80187A08: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80187A0C: sll         $t3, $t2, 6
    ctx->r11 = S32(ctx->r10 << 6);
    // 0x80187A10: addu        $v1, $s0, $t3
    ctx->r3 = ADD32(ctx->r16, ctx->r11);
    // 0x80187A14: lw          $a1, 0x24($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X24);
    // 0x80187A18: lw          $a2, 0x28($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X28);
    // 0x80187A1C: lw          $a3, 0x2C($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X2C);
    // 0x80187A20: jal         0x80005C34
    // 0x80187A24: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_4;
    // 0x80187A24: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_4:
    // 0x80187A28: lw          $t6, 0x84($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X84);
    // 0x80187A2C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80187A30: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80187A34: sll         $t7, $t6, 6
    ctx->r15 = S32(ctx->r14 << 6);
    // 0x80187A38: addu        $t8, $s0, $t7
    ctx->r24 = ADD32(ctx->r16, ctx->r15);
    // 0x80187A3C: lwc1        $f10, 0x1C($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X1C);
    // 0x80187A40: mul.s       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x80187A44: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x80187A48: jal         0x80005E90
    // 0x80187A4C: nop

    Matrix_RotateY(rdram, ctx);
        goto after_5;
    // 0x80187A4C: nop

    after_5:
    // 0x80187A50: lw          $t1, 0x84($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X84);
    // 0x80187A54: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80187A58: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80187A5C: sll         $t4, $t1, 6
    ctx->r12 = S32(ctx->r9 << 6);
    // 0x80187A60: addu        $t5, $s0, $t4
    ctx->r13 = ADD32(ctx->r16, ctx->r12);
    // 0x80187A64: lwc1        $f18, 0x18($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0X18);
    // 0x80187A68: mul.s       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x80187A6C: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80187A70: jal         0x80005D44
    // 0x80187A74: nop

    Matrix_RotateX(rdram, ctx);
        goto after_6;
    // 0x80187A74: nop

    after_6:
    // 0x80187A78: lw          $t0, 0x84($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X84);
    // 0x80187A7C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80187A80: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80187A84: sll         $t2, $t0, 6
    ctx->r10 = S32(ctx->r8 << 6);
    // 0x80187A88: addu        $t3, $s0, $t2
    ctx->r11 = ADD32(ctx->r16, ctx->r10);
    // 0x80187A8C: lwc1        $f6, 0x20($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X20);
    // 0x80187A90: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x80187A94: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80187A98: jal         0x80005FE0
    // 0x80187A9C: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_7;
    // 0x80187A9C: nop

    after_7:
    // 0x80187AA0: jal         0x80006EB8
    // 0x80187AA4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_8;
    // 0x80187AA4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_8:
    // 0x80187AA8: lw          $t9, 0x2E4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2E4);
    // 0x80187AAC: lw          $t0, 0x84($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X84);
    // 0x80187AB0: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x80187AB4: beq         $t9, $zero, L_80187BB0
    if (ctx->r25 == 0) {
        // 0x80187AB8: sll         $t8, $t0, 6
        ctx->r24 = S32(ctx->r8 << 6);
            goto L_80187BB0;
    }
    // 0x80187AB8: sll         $t8, $t0, 6
    ctx->r24 = S32(ctx->r8 << 6);
    // 0x80187ABC: lw          $t6, 0x7A80($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7A80);
    // 0x80187AC0: slti        $at, $t6, 0x18A
    ctx->r1 = SIGNED(ctx->r14) < 0X18A ? 1 : 0;
    // 0x80187AC4: bnel        $at, $zero, L_80187BB4
    if (ctx->r1 != 0) {
        // 0x80187AC8: addu        $t1, $s0, $t8
        ctx->r9 = ADD32(ctx->r16, ctx->r24);
            goto L_80187BB4;
    }
    goto skip_0;
    // 0x80187AC8: addu        $t1, $s0, $t8
    ctx->r9 = ADD32(ctx->r16, ctx->r24);
    skip_0:
    // 0x80187ACC: lw          $t0, 0x84($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X84);
    // 0x80187AD0: lui         $a0, 0x602
    ctx->r4 = S32(0X602 << 16);
    // 0x80187AD4: addiu       $a0, $a0, 0x46F8
    ctx->r4 = ADD32(ctx->r4, 0X46F8);
    // 0x80187AD8: beq         $t0, $zero, L_80187B04
    if (ctx->r8 == 0) {
        // 0x80187ADC: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80187B04;
    }
    // 0x80187ADC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80187AE0: beq         $t0, $s7, L_80187B14
    if (ctx->r8 == ctx->r23) {
        // 0x80187AE4: lui         $a0, 0x603
        ctx->r4 = S32(0X603 << 16);
            goto L_80187B14;
    }
    // 0x80187AE4: lui         $a0, 0x603
    ctx->r4 = S32(0X603 << 16);
    // 0x80187AE8: beq         $t0, $fp, L_80187B30
    if (ctx->r8 == ctx->r30) {
        // 0x80187AEC: lui         $a0, 0x603
        ctx->r4 = S32(0X603 << 16);
            goto L_80187B30;
    }
    // 0x80187AEC: lui         $a0, 0x603
    ctx->r4 = S32(0X603 << 16);
    // 0x80187AF0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80187AF4: beq         $t0, $at, L_80187B4C
    if (ctx->r8 == ctx->r1) {
        // 0x80187AF8: lui         $a0, 0x603
        ctx->r4 = S32(0X603 << 16);
            goto L_80187B4C;
    }
    // 0x80187AF8: lui         $a0, 0x603
    ctx->r4 = S32(0X603 << 16);
    // 0x80187AFC: b           L_80187B64
    // 0x80187B00: sw          $t0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r8;
        goto L_80187B64;
    // 0x80187B00: sw          $t0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r8;
L_80187B04:
    // 0x80187B04: jal         0x8009AA20
    // 0x80187B08: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    Animation_GetFrameData(rdram, ctx);
        goto after_9;
    // 0x80187B08: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_9:
    // 0x80187B0C: b           L_80187B64
    // 0x80187B10: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
        goto L_80187B64;
    // 0x80187B10: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
L_80187B14:
    // 0x80187B14: sw          $t0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r8;
    // 0x80187B18: addiu       $a0, $a0, 0x38DC
    ctx->r4 = ADD32(ctx->r4, 0X38DC);
    // 0x80187B1C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80187B20: jal         0x8009AA20
    // 0x80187B24: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    Animation_GetFrameData(rdram, ctx);
        goto after_10;
    // 0x80187B24: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_10:
    // 0x80187B28: b           L_80187B64
    // 0x80187B2C: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
        goto L_80187B64;
    // 0x80187B2C: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
L_80187B30:
    // 0x80187B30: sw          $t0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r8;
    // 0x80187B34: addiu       $a0, $a0, 0x6278
    ctx->r4 = ADD32(ctx->r4, 0X6278);
    // 0x80187B38: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80187B3C: jal         0x8009AA20
    // 0x80187B40: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    Animation_GetFrameData(rdram, ctx);
        goto after_11;
    // 0x80187B40: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_11:
    // 0x80187B44: b           L_80187B64
    // 0x80187B48: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
        goto L_80187B64;
    // 0x80187B48: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
L_80187B4C:
    // 0x80187B4C: sw          $t0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r8;
    // 0x80187B50: addiu       $a0, $a0, 0x531C
    ctx->r4 = ADD32(ctx->r4, 0X531C);
    // 0x80187B54: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80187B58: jal         0x8009AA20
    // 0x80187B5C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    Animation_GetFrameData(rdram, ctx);
        goto after_12;
    // 0x80187B5C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_12:
    // 0x80187B60: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
L_80187B64:
    // 0x80187B64: lw          $t0, 0x84($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X84);
    // 0x80187B68: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80187B6C: lwc1        $f10, 0x6460($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6460);
    // 0x80187B70: multu       $t0, $s6
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80187B74: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80187B78: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80187B7C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80187B80: lwc1        $f18, 0x6464($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6464);
    // 0x80187B84: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80187B88: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    // 0x80187B8C: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x80187B90: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x80187B94: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x80187B98: mflo        $t7
    ctx->r15 = lo;
    // 0x80187B9C: addu        $a1, $s5, $t7
    ctx->r5 = ADD32(ctx->r21, ctx->r15);
    // 0x80187BA0: jal         0x8009BEEC
    // 0x80187BA4: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToVec3fArray(rdram, ctx);
        goto after_13;
    // 0x80187BA4: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    after_13:
    // 0x80187BA8: b           L_80187C9C
    // 0x80187BAC: lw          $t0, 0x84($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X84);
        goto L_80187C9C;
    // 0x80187BAC: lw          $t0, 0x84($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X84);
L_80187BB0:
    // 0x80187BB0: addu        $t1, $s0, $t8
    ctx->r9 = ADD32(ctx->r16, ctx->r24);
L_80187BB4:
    // 0x80187BB4: jal         0x8009ACDC
    // 0x80187BB8: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    Animation_GetFrameCount(rdram, ctx);
        goto after_14;
    // 0x80187BB8: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    after_14:
    // 0x80187BBC: lw          $t0, 0x84($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X84);
    // 0x80187BC0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80187BC4: sll         $t4, $t0, 6
    ctx->r12 = S32(ctx->r8 << 6);
    // 0x80187BC8: addu        $v1, $s0, $t4
    ctx->r3 = ADD32(ctx->r16, ctx->r12);
    // 0x80187BCC: lw          $t5, 0x34($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X34);
    // 0x80187BD0: lwc1        $f8, 0x30($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X30);
    // 0x80187BD4: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x80187BD8: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x80187BDC: nop

    // 0x80187BE0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80187BE4: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80187BE8: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80187BEC: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80187BF0: nop

    // 0x80187BF4: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80187BF8: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80187BFC: nop

    // 0x80187C00: andi        $at, $t3, 0x4
    ctx->r1 = ctx->r11 & 0X4;
    // 0x80187C04: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x80187C08: beql        $t3, $zero, L_80187C60
    if (ctx->r11 == 0) {
        // 0x80187C0C: mfc1        $t3, $f16
        ctx->r11 = (int32_t)ctx->f16.u32l;
            goto L_80187C60;
    }
    goto skip_1;
    // 0x80187C0C: mfc1        $t3, $f16
    ctx->r11 = (int32_t)ctx->f16.u32l;
    skip_1:
    // 0x80187C10: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80187C14: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80187C18: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80187C1C: sub.s       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80187C20: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80187C24: nop

    // 0x80187C28: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80187C2C: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80187C30: nop

    // 0x80187C34: andi        $at, $t3, 0x4
    ctx->r1 = ctx->r11 & 0X4;
    // 0x80187C38: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x80187C3C: bne         $t3, $zero, L_80187C54
    if (ctx->r11 != 0) {
        // 0x80187C40: nop
    
            goto L_80187C54;
    }
    // 0x80187C40: nop

    // 0x80187C44: mfc1        $t3, $f16
    ctx->r11 = (int32_t)ctx->f16.u32l;
    // 0x80187C48: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80187C4C: b           L_80187C6C
    // 0x80187C50: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
        goto L_80187C6C;
    // 0x80187C50: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
L_80187C54:
    // 0x80187C54: b           L_80187C6C
    // 0x80187C58: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
        goto L_80187C6C;
    // 0x80187C58: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80187C5C: mfc1        $t3, $f16
    ctx->r11 = (int32_t)ctx->f16.u32l;
L_80187C60:
    // 0x80187C60: nop

    // 0x80187C64: bltz        $t3, L_80187C54
    if (SIGNED(ctx->r11) < 0) {
        // 0x80187C68: nop
    
            goto L_80187C54;
    }
    // 0x80187C68: nop

L_80187C6C:
    // 0x80187C6C: divu        $zero, $t3, $v0
    lo = S32(U32(ctx->r11) / U32(ctx->r2)); hi = S32(U32(ctx->r11) % U32(ctx->r2));
    // 0x80187C70: mfhi        $a1
    ctx->r5 = hi;
    // 0x80187C74: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80187C78: bne         $v0, $zero, L_80187C84
    if (ctx->r2 != 0) {
        // 0x80187C7C: nop
    
            goto L_80187C84;
    }
    // 0x80187C7C: nop

    // 0x80187C80: break       7
    do_break(2149088384);
L_80187C84:
    // 0x80187C84: multu       $t0, $s6
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80187C88: mflo        $t9
    ctx->r25 = lo;
    // 0x80187C8C: addu        $a2, $s5, $t9
    ctx->r6 = ADD32(ctx->r21, ctx->r25);
    // 0x80187C90: jal         0x8009AA20
    // 0x80187C94: nop

    Animation_GetFrameData(rdram, ctx);
        goto after_15;
    // 0x80187C94: nop

    after_15:
    // 0x80187C98: lw          $t0, 0x84($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X84);
L_80187C9C:
    // 0x80187C9C: lui         $t4, 0x800C
    ctx->r12 = S32(0X800C << 16);
    // 0x80187CA0: addiu       $t4, $t4, 0x4660
    ctx->r12 = ADD32(ctx->r12, 0X4660);
    // 0x80187CA4: multu       $t0, $s6
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80187CA8: sll         $t6, $t0, 6
    ctx->r14 = S32(ctx->r8 << 6);
    // 0x80187CAC: addu        $t7, $s0, $t6
    ctx->r15 = ADD32(ctx->r16, ctx->r14);
    // 0x80187CB0: lw          $a1, 0x4($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X4);
    // 0x80187CB4: addiu       $t1, $sp, 0x84
    ctx->r9 = ADD32(ctx->r29, 0X84);
    // 0x80187CB8: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80187CBC: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x80187CC0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80187CC4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80187CC8: lw          $a3, 0x60($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X60);
    // 0x80187CCC: mflo        $t8
    ctx->r24 = lo;
    // 0x80187CD0: addu        $a2, $s5, $t8
    ctx->r6 = ADD32(ctx->r21, ctx->r24);
    // 0x80187CD4: jal         0x8009A72C
    // 0x80187CD8: nop

    Animation_DrawSkeleton(rdram, ctx);
        goto after_16;
    // 0x80187CD8: nop

    after_16:
    // 0x80187CDC: jal         0x80005740
    // 0x80187CE0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_17;
    // 0x80187CE0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_17:
    // 0x80187CE4: lw          $t0, 0x84($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X84);
    // 0x80187CE8: lui         $t5, 0x8019
    ctx->r13 = S32(0X8019 << 16);
    // 0x80187CEC: lw          $t5, 0x6F88($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X6F88);
    // 0x80187CF0: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80187CF4: sw          $t0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r8;
    // 0x80187CF8: slt         $at, $t0, $t5
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80187CFC: bne         $at, $zero, L_8018791C
    if (ctx->r1 != 0) {
        // 0x80187D00: nop
    
            goto L_8018791C;
    }
    // 0x80187D00: nop

    // 0x80187D04: sw          $s3, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r19;
L_80187D08:
    // 0x80187D08: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x80187D0C: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x80187D10: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80187D14: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x80187D18: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x80187D1C: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x80187D20: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x80187D24: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x80187D28: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x80187D2C: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x80187D30: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x80187D34: jr          $ra
    // 0x80187D38: addiu       $sp, $sp, 0x2E0
    ctx->r29 = ADD32(ctx->r29, 0X2E0);
    return;
    // 0x80187D38: addiu       $sp, $sp, 0x2E0
    ctx->r29 = ADD32(ctx->r29, 0X2E0);
;}
RECOMP_FUNC void Ending_8018BAD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018BAD0: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8018BAD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018BAD8: lui         $t7, 0x8019
    ctx->r15 = S32(0X8019 << 16);
    // 0x8018BADC: addiu       $t7, $t7, 0x2DB4
    ctx->r15 = ADD32(ctx->r15, 0X2DB4);
    // 0x8018BAE0: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x8018BAE4: addiu       $t6, $sp, 0x4C
    ctx->r14 = ADD32(ctx->r29, 0X4C);
    // 0x8018BAE8: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x8018BAEC: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x8018BAF0: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x8018BAF4: lui         $t2, 0x8019
    ctx->r10 = S32(0X8019 << 16);
    // 0x8018BAF8: addiu       $t2, $t2, 0x2DC0
    ctx->r10 = ADD32(ctx->r10, 0X2DC0);
    // 0x8018BAFC: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x8018BB00: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x8018BB04: lw          $at, 0x0($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X0);
    // 0x8018BB08: addiu       $t1, $sp, 0x40
    ctx->r9 = ADD32(ctx->r29, 0X40);
    // 0x8018BB0C: lw          $t5, 0x4($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X4);
    // 0x8018BB10: sw          $at, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r1;
    // 0x8018BB14: lw          $at, 0x8($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X8);
    // 0x8018BB18: lui         $t8, 0x8019
    ctx->r24 = S32(0X8019 << 16);
    // 0x8018BB1C: addiu       $t8, $t8, 0x2DCC
    ctx->r24 = ADD32(ctx->r24, 0X2DCC);
    // 0x8018BB20: sw          $t5, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r13;
    // 0x8018BB24: sw          $at, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r1;
    // 0x8018BB28: lw          $at, 0x0($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X0);
    // 0x8018BB2C: addiu       $t9, $sp, 0x34
    ctx->r25 = ADD32(ctx->r29, 0X34);
    // 0x8018BB30: lw          $t0, 0x4($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X4);
    // 0x8018BB34: sw          $at, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r1;
    // 0x8018BB38: lw          $at, 0x8($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X8);
    // 0x8018BB3C: lui         $t3, 0x8019
    ctx->r11 = S32(0X8019 << 16);
    // 0x8018BB40: addiu       $t3, $t3, 0x2DD8
    ctx->r11 = ADD32(ctx->r11, 0X2DD8);
    // 0x8018BB44: sw          $t0, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r8;
    // 0x8018BB48: sw          $at, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r1;
    // 0x8018BB4C: lw          $at, 0x0($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X0);
    // 0x8018BB50: addiu       $t4, $sp, 0x28
    ctx->r12 = ADD32(ctx->r29, 0X28);
    // 0x8018BB54: lw          $t5, 0x4($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X4);
    // 0x8018BB58: sw          $at, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r1;
    // 0x8018BB5C: lw          $at, 0x8($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X8);
    // 0x8018BB60: lui         $t6, 0x8019
    ctx->r14 = S32(0X8019 << 16);
    // 0x8018BB64: addiu       $t6, $t6, 0x2DE4
    ctx->r14 = ADD32(ctx->r14, 0X2DE4);
    // 0x8018BB68: sw          $t5, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r13;
    // 0x8018BB6C: sw          $at, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r1;
    // 0x8018BB70: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x8018BB74: addiu       $t7, $sp, 0x1C
    ctx->r15 = ADD32(ctx->r29, 0X1C);
    // 0x8018BB78: lw          $t0, 0x4($t6)
    ctx->r8 = MEM_W(ctx->r14, 0X4);
    // 0x8018BB7C: sw          $at, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r1;
    // 0x8018BB80: lw          $at, 0x8($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X8);
    // 0x8018BB84: sw          $t0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r8;
    // 0x8018BB88: sw          $at, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r1;
    // 0x8018BB8C: lwc1        $f4, 0x4C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8018BB90: lwc1        $f6, 0x50($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8018BB94: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018BB98: swc1        $f4, 0x7978($at)
    MEM_W(0X7978, ctx->r1) = ctx->f4.u32l;
    // 0x8018BB9C: lwc1        $f8, 0x54($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8018BBA0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018BBA4: swc1        $f6, 0x7980($at)
    MEM_W(0X7980, ctx->r1) = ctx->f6.u32l;
    // 0x8018BBA8: lwc1        $f10, 0x40($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8018BBAC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018BBB0: swc1        $f8, 0x7988($at)
    MEM_W(0X7988, ctx->r1) = ctx->f8.u32l;
    // 0x8018BBB4: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8018BBB8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018BBBC: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x8018BBC0: swc1        $f10, 0x79A0($at)
    MEM_W(0X79A0, ctx->r1) = ctx->f10.u32l;
    // 0x8018BBC4: lwc1        $f18, 0x48($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8018BBC8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018BBCC: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x8018BBD0: swc1        $f16, 0x79B8($at)
    MEM_W(0X79B8, ctx->r1) = ctx->f16.u32l;
    // 0x8018BBD4: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8018BBD8: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x8018BBDC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018BBE0: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x8018BBE4: swc1        $f18, 0x79C0($at)
    MEM_W(0X79C0, ctx->r1) = ctx->f18.u32l;
    // 0x8018BBE8: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x8018BBEC: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x8018BBF0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018BBF4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8018BBF8: sw          $t2, -0x7AB8($at)
    MEM_W(-0X7AB8, ctx->r1) = ctx->r10;
    // 0x8018BBFC: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x8018BC00: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x8018BC04: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018BC08: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8018BC0C: sw          $t1, -0x7AB4($at)
    MEM_W(-0X7AB4, ctx->r1) = ctx->r9;
    // 0x8018BC10: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018BC14: sw          $t4, -0x7AB0($at)
    MEM_W(-0X7AB0, ctx->r1) = ctx->r12;
    // 0x8018BC18: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018BC1C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8018BC20: swc1        $f6, -0x7B30($at)
    MEM_W(-0X7B30, ctx->r1) = ctx->f6.u32l;
    // 0x8018BC24: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018BC28: swc1        $f10, -0x7B2C($at)
    MEM_W(-0X7B2C, ctx->r1) = ctx->f10.u32l;
    // 0x8018BC2C: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8018BC30: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018BC34: swc1        $f18, -0x7B28($at)
    MEM_W(-0X7B28, ctx->r1) = ctx->f18.u32l;
    // 0x8018BC38: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8018BC3C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018BC40: sw          $t9, -0x7AAC($at)
    MEM_W(-0X7AAC, ctx->r1) = ctx->r25;
    // 0x8018BC44: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018BC48: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8018BC4C: sw          $t7, -0x7AA8($at)
    MEM_W(-0X7AA8, ctx->r1) = ctx->r15;
    // 0x8018BC50: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018BC54: jal         0x800A6148
    // 0x8018BC58: sw          $t6, -0x7AA4($at)
    MEM_W(-0X7AA4, ctx->r1) = ctx->r14;
    Play_ClearObjectData(rdram, ctx);
        goto after_0;
    // 0x8018BC58: sw          $t6, -0x7AA4($at)
    MEM_W(-0X7AA4, ctx->r1) = ctx->r14;
    after_0:
    // 0x8018BC5C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8018BC60: addiu       $a0, $a0, 0x3FE0
    ctx->r4 = ADD32(ctx->r4, 0X3FE0);
    // 0x8018BC64: jal         0x8018B3E8
    // 0x8018BC68: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    Ending_8018B3E8(rdram, ctx);
        goto after_1;
    // 0x8018BC68: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x8018BC6C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8018BC70: jal         0x8018B624
    // 0x8018BC74: addiu       $a0, $a0, 0x42D4
    ctx->r4 = ADD32(ctx->r4, 0X42D4);
    Ending_8018B624(rdram, ctx);
        goto after_2;
    // 0x8018BC74: addiu       $a0, $a0, 0x42D4
    ctx->r4 = ADD32(ctx->r4, 0X42D4);
    after_2:
    // 0x8018BC78: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8018BC7C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018BC80: sw          $t0, 0x7A10($at)
    MEM_W(0X7A10, ctx->r1) = ctx->r8;
    // 0x8018BC84: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018BC88: sw          $zero, -0x7A74($at)
    MEM_W(-0X7A74, ctx->r1) = 0;
    // 0x8018BC8C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018BC90: addiu       $t2, $zero, 0x4AE5
    ctx->r10 = ADD32(0, 0X4AE5);
    // 0x8018BC94: sh          $t2, 0x1A36($at)
    MEM_H(0X1A36, ctx->r1) = ctx->r10;
    // 0x8018BC98: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018BC9C: sw          $zero, -0x7BF0($at)
    MEM_W(-0X7BF0, ctx->r1) = 0;
    // 0x8018BCA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018BCA4: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x8018BCA8: jr          $ra
    // 0x8018BCAC: nop

    return;
    // 0x8018BCAC: nop

;}
RECOMP_FUNC void Ending_801888F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801888F4: addiu       $sp, $sp, -0x2A0
    ctx->r29 = ADD32(ctx->r29, -0X2A0);
    // 0x801888F8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x801888FC: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80188900: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80188904: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80188908: sw          $t6, 0x29C($sp)
    MEM_W(0X29C, ctx->r29) = ctx->r14;
    // 0x8018890C: jal         0x80005708
    // 0x80188910: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Push(rdram, ctx);
        goto after_0;
    // 0x80188910: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_0:
    // 0x80188914: lw          $t7, 0x29C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X29C);
    // 0x80188918: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018891C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80188920: sll         $t8, $t7, 6
    ctx->r24 = S32(ctx->r15 << 6);
    // 0x80188924: addu        $a1, $a1, $t8
    ctx->r5 = ADD32(ctx->r5, ctx->r24);
    // 0x80188928: lh          $a1, 0x6D10($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X6D10);
    // 0x8018892C: jal         0x800B8DD0
    // 0x80188930: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    RCP_SetupDL(rdram, ctx);
        goto after_1;
    // 0x80188930: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    after_1:
    // 0x80188934: lw          $t9, 0x29C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X29C);
    // 0x80188938: lui         $t1, 0x8019
    ctx->r9 = S32(0X8019 << 16);
    // 0x8018893C: addiu       $t1, $t1, 0x6D08
    ctx->r9 = ADD32(ctx->r9, 0X6D08);
    // 0x80188940: sll         $t0, $t9, 6
    ctx->r8 = S32(ctx->r25 << 6);
    // 0x80188944: addu        $s0, $t0, $t1
    ctx->r16 = ADD32(ctx->r8, ctx->r9);
    // 0x80188948: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018894C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80188950: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80188954: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80188958: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x8018895C: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    // 0x80188960: jal         0x80005B00
    // 0x80188964: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    Matrix_Translate(rdram, ctx);
        goto after_2;
    // 0x80188964: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    after_2:
    // 0x80188968: lw          $t3, 0x29C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X29C);
    // 0x8018896C: lui         $t5, 0x8019
    ctx->r13 = S32(0X8019 << 16);
    // 0x80188970: addiu       $t5, $t5, 0x6D08
    ctx->r13 = ADD32(ctx->r13, 0X6D08);
    // 0x80188974: sll         $t4, $t3, 6
    ctx->r12 = S32(ctx->r11 << 6);
    // 0x80188978: addu        $s0, $t4, $t5
    ctx->r16 = ADD32(ctx->r12, ctx->r13);
    // 0x8018897C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80188980: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80188984: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80188988: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8018898C: lw          $a1, 0x24($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X24);
    // 0x80188990: lw          $a2, 0x28($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X28);
    // 0x80188994: jal         0x80005C34
    // 0x80188998: lw          $a3, 0x2C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X2C);
    Matrix_Scale(rdram, ctx);
        goto after_3;
    // 0x80188998: lw          $a3, 0x2C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X2C);
    after_3:
    // 0x8018899C: lw          $t7, 0x29C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X29C);
    // 0x801889A0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801889A4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801889A8: sll         $t8, $t7, 6
    ctx->r24 = S32(ctx->r15 << 6);
    // 0x801889AC: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x801889B0: lwc1        $f4, 0x6D24($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6D24);
    // 0x801889B4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801889B8: lwc1        $f6, 0x64A0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X64A0);
    // 0x801889BC: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x801889C0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801889C4: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x801889C8: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x801889CC: jal         0x80005E90
    // 0x801889D0: nop

    Matrix_RotateY(rdram, ctx);
        goto after_4;
    // 0x801889D0: nop

    after_4:
    // 0x801889D4: lw          $t9, 0x29C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X29C);
    // 0x801889D8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801889DC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801889E0: sll         $t0, $t9, 6
    ctx->r8 = S32(ctx->r25 << 6);
    // 0x801889E4: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x801889E8: lwc1        $f10, 0x6D20($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6D20);
    // 0x801889EC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801889F0: lwc1        $f16, 0x64A4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X64A4);
    // 0x801889F4: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x801889F8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801889FC: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80188A00: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80188A04: jal         0x80005D44
    // 0x80188A08: nop

    Matrix_RotateX(rdram, ctx);
        goto after_5;
    // 0x80188A08: nop

    after_5:
    // 0x80188A0C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80188A10: jal         0x80006EB8
    // 0x80188A14: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_6;
    // 0x80188A14: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    after_6:
    // 0x80188A18: lw          $t1, 0x29C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X29C);
    // 0x80188A1C: lui         $t3, 0x8019
    ctx->r11 = S32(0X8019 << 16);
    // 0x80188A20: addiu       $t3, $t3, 0x6D08
    ctx->r11 = ADD32(ctx->r11, 0X6D08);
    // 0x80188A24: sll         $t2, $t1, 6
    ctx->r10 = S32(ctx->r9 << 6);
    // 0x80188A28: addu        $s0, $t2, $t3
    ctx->r16 = ADD32(ctx->r10, ctx->r11);
    // 0x80188A2C: lw          $v0, 0x38($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X38);
    // 0x80188A30: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80188A34: beq         $v0, $zero, L_80188A54
    if (ctx->r2 == 0) {
        // 0x80188A38: nop
    
            goto L_80188A54;
    }
    // 0x80188A38: nop

    // 0x80188A3C: beq         $v0, $at, L_80188B4C
    if (ctx->r2 == ctx->r1) {
        // 0x80188A40: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80188B4C;
    }
    // 0x80188A40: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80188A44: beq         $v0, $at, L_80188BFC
    if (ctx->r2 == ctx->r1) {
        // 0x80188A48: nop
    
            goto L_80188BFC;
    }
    // 0x80188A48: nop

    // 0x80188A4C: b           L_80188D60
    // 0x80188A50: nop

        goto L_80188D60;
    // 0x80188A50: nop

L_80188A54:
    // 0x80188A54: jal         0x8009ACDC
    // 0x80188A58: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    Animation_GetFrameCount(rdram, ctx);
        goto after_7;
    // 0x80188A58: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_7:
    // 0x80188A5C: lw          $t4, 0x29C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X29C);
    // 0x80188A60: lui         $t6, 0x8019
    ctx->r14 = S32(0X8019 << 16);
    // 0x80188A64: addiu       $t6, $t6, 0x6D08
    ctx->r14 = ADD32(ctx->r14, 0X6D08);
    // 0x80188A68: sll         $t5, $t4, 6
    ctx->r13 = S32(ctx->r12 << 6);
    // 0x80188A6C: addu        $s0, $t5, $t6
    ctx->r16 = ADD32(ctx->r13, ctx->r14);
    // 0x80188A70: lw          $t7, 0x34($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X34);
    // 0x80188A74: lwc1        $f8, 0x30($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X30);
    // 0x80188A78: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80188A7C: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80188A80: lui         $a2, 0x8019
    ctx->r6 = S32(0X8019 << 16);
    // 0x80188A84: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80188A88: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80188A8C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80188A90: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80188A94: nop

    // 0x80188A98: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80188A9C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80188AA0: nop

    // 0x80188AA4: andi        $at, $t9, 0x4
    ctx->r1 = ctx->r25 & 0X4;
    // 0x80188AA8: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x80188AAC: beql        $t9, $zero, L_80188B04
    if (ctx->r25 == 0) {
        // 0x80188AB0: mfc1        $t9, $f16
        ctx->r25 = (int32_t)ctx->f16.u32l;
            goto L_80188B04;
    }
    goto skip_0;
    // 0x80188AB0: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
    skip_0:
    // 0x80188AB4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80188AB8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80188ABC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80188AC0: sub.s       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80188AC4: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80188AC8: nop

    // 0x80188ACC: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80188AD0: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80188AD4: nop

    // 0x80188AD8: andi        $at, $t9, 0x4
    ctx->r1 = ctx->r25 & 0X4;
    // 0x80188ADC: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x80188AE0: bne         $t9, $zero, L_80188AF8
    if (ctx->r25 != 0) {
        // 0x80188AE4: nop
    
            goto L_80188AF8;
    }
    // 0x80188AE4: nop

    // 0x80188AE8: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
    // 0x80188AEC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80188AF0: b           L_80188B10
    // 0x80188AF4: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_80188B10;
    // 0x80188AF4: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_80188AF8:
    // 0x80188AF8: b           L_80188B10
    // 0x80188AFC: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_80188B10;
    // 0x80188AFC: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80188B00: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
L_80188B04:
    // 0x80188B04: nop

    // 0x80188B08: bltz        $t9, L_80188AF8
    if (SIGNED(ctx->r25) < 0) {
        // 0x80188B0C: nop
    
            goto L_80188AF8;
    }
    // 0x80188B0C: nop

L_80188B10:
    // 0x80188B10: divu        $zero, $t9, $v0
    lo = S32(U32(ctx->r25) / U32(ctx->r2)); hi = S32(U32(ctx->r25) % U32(ctx->r2));
    // 0x80188B14: mfhi        $a1
    ctx->r5 = hi;
    // 0x80188B18: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80188B1C: bne         $v0, $zero, L_80188B28
    if (ctx->r2 != 0) {
        // 0x80188B20: nop
    
            goto L_80188B28;
    }
    // 0x80188B20: nop

    // 0x80188B24: break       7
    do_break(2149092132);
L_80188B28:
    // 0x80188B28: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80188B2C: jal         0x8009AA20
    // 0x80188B30: addiu       $a2, $a2, 0x7900
    ctx->r6 = ADD32(ctx->r6, 0X7900);
    Animation_GetFrameData(rdram, ctx);
        goto after_8;
    // 0x80188B30: addiu       $a2, $a2, 0x7900
    ctx->r6 = ADD32(ctx->r6, 0X7900);
    after_8:
    // 0x80188B34: lw          $t0, 0x29C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X29C);
    // 0x80188B38: lui         $t2, 0x8019
    ctx->r10 = S32(0X8019 << 16);
    // 0x80188B3C: addiu       $t2, $t2, 0x6D08
    ctx->r10 = ADD32(ctx->r10, 0X6D08);
    // 0x80188B40: sll         $t1, $t0, 6
    ctx->r9 = S32(ctx->r8 << 6);
    // 0x80188B44: b           L_80188D60
    // 0x80188B48: addu        $s0, $t1, $t2
    ctx->r16 = ADD32(ctx->r9, ctx->r10);
        goto L_80188D60;
    // 0x80188B48: addu        $s0, $t1, $t2
    ctx->r16 = ADD32(ctx->r9, ctx->r10);
L_80188B4C:
    // 0x80188B4C: lw          $t3, 0x34($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X34);
    // 0x80188B50: lwc1        $f18, 0x30($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X30);
    // 0x80188B54: lui         $a0, 0x602
    ctx->r4 = S32(0X602 << 16);
    // 0x80188B58: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x80188B5C: addiu       $a0, $a0, -0x720
    ctx->r4 = ADD32(ctx->r4, -0X720);
    // 0x80188B60: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80188B64: mul.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x80188B68: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80188B6C: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80188B70: jal         0x8009ACDC
    // 0x80188B74: sw          $a1, 0x294($sp)
    MEM_W(0X294, ctx->r29) = ctx->r5;
    Animation_GetFrameCount(rdram, ctx);
        goto after_9;
    // 0x80188B74: sw          $a1, 0x294($sp)
    MEM_W(0X294, ctx->r29) = ctx->r5;
    after_9:
    // 0x80188B78: lw          $a1, 0x294($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X294);
    // 0x80188B7C: lui         $s0, 0x602
    ctx->r16 = S32(0X602 << 16);
    // 0x80188B80: addiu       $s0, $s0, -0x720
    ctx->r16 = ADD32(ctx->r16, -0X720);
    // 0x80188B84: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80188B88: bnel        $at, $zero, L_80188BA0
    if (ctx->r1 != 0) {
        // 0x80188B8C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80188BA0;
    }
    goto skip_1;
    // 0x80188B8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x80188B90: jal         0x8009ACDC
    // 0x80188B94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Animation_GetFrameCount(rdram, ctx);
        goto after_10;
    // 0x80188B94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80188B98: addiu       $a1, $v0, -0x1
    ctx->r5 = ADD32(ctx->r2, -0X1);
    // 0x80188B9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80188BA0:
    // 0x80188BA0: jal         0x8009AA20
    // 0x80188BA4: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    Animation_GetFrameData(rdram, ctx);
        goto after_11;
    // 0x80188BA4: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    after_11:
    // 0x80188BA8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80188BAC: lwc1        $f16, 0x64A8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X64A8);
    // 0x80188BB0: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80188BB4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80188BB8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80188BBC: lwc1        $f18, 0x64AC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X64AC);
    // 0x80188BC0: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80188BC4: addiu       $a1, $a1, 0x7900
    ctx->r5 = ADD32(ctx->r5, 0X7900);
    // 0x80188BC8: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x80188BCC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80188BD0: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80188BD4: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x80188BD8: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x80188BDC: jal         0x8009BEEC
    // 0x80188BE0: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToVec3fArray(rdram, ctx);
        goto after_12;
    // 0x80188BE0: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    after_12:
    // 0x80188BE4: lw          $t5, 0x29C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X29C);
    // 0x80188BE8: lui         $t7, 0x8019
    ctx->r15 = S32(0X8019 << 16);
    // 0x80188BEC: addiu       $t7, $t7, 0x6D08
    ctx->r15 = ADD32(ctx->r15, 0X6D08);
    // 0x80188BF0: sll         $t6, $t5, 6
    ctx->r14 = S32(ctx->r13 << 6);
    // 0x80188BF4: b           L_80188D60
    // 0x80188BF8: addu        $s0, $t6, $t7
    ctx->r16 = ADD32(ctx->r14, ctx->r15);
        goto L_80188D60;
    // 0x80188BF8: addu        $s0, $t6, $t7
    ctx->r16 = ADD32(ctx->r14, ctx->r15);
L_80188BFC:
    // 0x80188BFC: jal         0x8009ACDC
    // 0x80188C00: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    Animation_GetFrameCount(rdram, ctx);
        goto after_13;
    // 0x80188C00: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_13:
    // 0x80188C04: lw          $t8, 0x29C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X29C);
    // 0x80188C08: lui         $t0, 0x8019
    ctx->r8 = S32(0X8019 << 16);
    // 0x80188C0C: addiu       $t0, $t0, 0x6D08
    ctx->r8 = ADD32(ctx->r8, 0X6D08);
    // 0x80188C10: sll         $t9, $t8, 6
    ctx->r25 = S32(ctx->r24 << 6);
    // 0x80188C14: addu        $s0, $t9, $t0
    ctx->r16 = ADD32(ctx->r25, ctx->r8);
    // 0x80188C18: lw          $t1, 0x34($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X34);
    // 0x80188C1C: lwc1        $f10, 0x30($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X30);
    // 0x80188C20: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80188C24: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x80188C28: lui         $a0, 0x602
    ctx->r4 = S32(0X602 << 16);
    // 0x80188C2C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80188C30: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80188C34: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80188C38: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80188C3C: nop

    // 0x80188C40: cvt.w.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80188C44: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80188C48: nop

    // 0x80188C4C: andi        $at, $t3, 0x4
    ctx->r1 = ctx->r11 & 0X4;
    // 0x80188C50: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x80188C54: beql        $t3, $zero, L_80188CAC
    if (ctx->r11 == 0) {
        // 0x80188C58: mfc1        $t3, $f4
        ctx->r11 = (int32_t)ctx->f4.u32l;
            goto L_80188CAC;
    }
    goto skip_2;
    // 0x80188C58: mfc1        $t3, $f4
    ctx->r11 = (int32_t)ctx->f4.u32l;
    skip_2:
    // 0x80188C5C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80188C60: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80188C64: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80188C68: sub.s       $f4, $f16, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x80188C6C: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80188C70: nop

    // 0x80188C74: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80188C78: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80188C7C: nop

    // 0x80188C80: andi        $at, $t3, 0x4
    ctx->r1 = ctx->r11 & 0X4;
    // 0x80188C84: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x80188C88: bne         $t3, $zero, L_80188CA0
    if (ctx->r11 != 0) {
        // 0x80188C8C: nop
    
            goto L_80188CA0;
    }
    // 0x80188C8C: nop

    // 0x80188C90: mfc1        $t3, $f4
    ctx->r11 = (int32_t)ctx->f4.u32l;
    // 0x80188C94: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80188C98: b           L_80188CB8
    // 0x80188C9C: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
        goto L_80188CB8;
    // 0x80188C9C: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
L_80188CA0:
    // 0x80188CA0: b           L_80188CB8
    // 0x80188CA4: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
        goto L_80188CB8;
    // 0x80188CA4: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80188CA8: mfc1        $t3, $f4
    ctx->r11 = (int32_t)ctx->f4.u32l;
L_80188CAC:
    // 0x80188CAC: nop

    // 0x80188CB0: bltz        $t3, L_80188CA0
    if (SIGNED(ctx->r11) < 0) {
        // 0x80188CB4: nop
    
            goto L_80188CA0;
    }
    // 0x80188CB4: nop

L_80188CB8:
    // 0x80188CB8: divu        $zero, $t3, $v0
    lo = S32(U32(ctx->r11) / U32(ctx->r2)); hi = S32(U32(ctx->r11) % U32(ctx->r2));
    // 0x80188CBC: mfhi        $a1
    ctx->r5 = hi;
    // 0x80188CC0: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80188CC4: bne         $v0, $zero, L_80188CD0
    if (ctx->r2 != 0) {
        // 0x80188CC8: nop
    
            goto L_80188CD0;
    }
    // 0x80188CC8: nop

    // 0x80188CCC: break       7
    do_break(2149092556);
L_80188CD0:
    // 0x80188CD0: addiu       $a0, $a0, 0x46F8
    ctx->r4 = ADD32(ctx->r4, 0X46F8);
    // 0x80188CD4: jal         0x8009AA20
    // 0x80188CD8: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    Animation_GetFrameData(rdram, ctx);
        goto after_14;
    // 0x80188CD8: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    after_14:
    // 0x80188CDC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80188CE0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80188CE4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80188CE8: lwc1        $f18, 0x64B0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X64B0);
    // 0x80188CEC: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80188CF0: lui         $a2, 0x3C23
    ctx->r6 = S32(0X3C23 << 16);
    // 0x80188CF4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80188CF8: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80188CFC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80188D00: ori         $a2, $a2, 0xD70A
    ctx->r6 = ctx->r6 | 0XD70A;
    // 0x80188D04: addiu       $a0, $a0, -0x7A80
    ctx->r4 = ADD32(ctx->r4, -0X7A80);
    // 0x80188D08: jal         0x8009BC2C
    // 0x80188D0C: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_15;
    // 0x80188D0C: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_15:
    // 0x80188D10: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80188D14: lwc1        $f6, -0x7A80($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7A80);
    // 0x80188D18: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80188D1C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80188D20: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80188D24: lwc1        $f10, 0x64B4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X64B4);
    // 0x80188D28: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80188D2C: addiu       $a1, $a1, 0x7900
    ctx->r5 = ADD32(ctx->r5, 0X7900);
    // 0x80188D30: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x80188D34: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80188D38: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80188D3C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x80188D40: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x80188D44: jal         0x8009BEEC
    // 0x80188D48: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToVec3fArray(rdram, ctx);
        goto after_16;
    // 0x80188D48: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    after_16:
    // 0x80188D4C: lw          $t4, 0x29C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X29C);
    // 0x80188D50: lui         $t6, 0x8019
    ctx->r14 = S32(0X8019 << 16);
    // 0x80188D54: addiu       $t6, $t6, 0x6D08
    ctx->r14 = ADD32(ctx->r14, 0X6D08);
    // 0x80188D58: sll         $t5, $t4, 6
    ctx->r13 = S32(ctx->r12 << 6);
    // 0x80188D5C: addu        $s0, $t5, $t6
    ctx->r16 = ADD32(ctx->r13, ctx->r14);
L_80188D60:
    // 0x80188D60: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x80188D64: addiu       $t8, $t8, 0x4660
    ctx->r24 = ADD32(ctx->r24, 0X4660);
    // 0x80188D68: lui         $a2, 0x8019
    ctx->r6 = S32(0X8019 << 16);
    // 0x80188D6C: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x80188D70: addiu       $t7, $sp, 0x29C
    ctx->r15 = ADD32(ctx->r29, 0X29C);
    // 0x80188D74: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80188D78: addiu       $a3, $a3, -0x639C
    ctx->r7 = ADD32(ctx->r7, -0X639C);
    // 0x80188D7C: addiu       $a2, $a2, 0x7900
    ctx->r6 = ADD32(ctx->r6, 0X7900);
    // 0x80188D80: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80188D84: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80188D88: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x80188D8C: jal         0x8009A72C
    // 0x80188D90: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    Animation_DrawSkeleton(rdram, ctx);
        goto after_17;
    // 0x80188D90: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_17:
    // 0x80188D94: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80188D98: jal         0x80005740
    // 0x80188D9C: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Pop(rdram, ctx);
        goto after_18;
    // 0x80188D9C: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_18:
    // 0x80188DA0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80188DA4: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80188DA8: addiu       $sp, $sp, 0x2A0
    ctx->r29 = ADD32(ctx->r29, 0X2A0);
    // 0x80188DAC: jr          $ra
    // 0x80188DB0: nop

    return;
    // 0x80188DB0: nop

;}
RECOMP_FUNC void Ending_8018B624(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018B624: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8018B628: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018B62C: lui         $t7, 0x8019
    ctx->r15 = S32(0X8019 << 16);
    // 0x8018B630: addiu       $t7, $t7, 0x2CB8
    ctx->r15 = ADD32(ctx->r15, 0X2CB8);
    // 0x8018B634: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x8018B638: addiu       $t6, $sp, 0x24
    ctx->r14 = ADD32(ctx->r29, 0X24);
    // 0x8018B63C: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x8018B640: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x8018B644: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x8018B648: lui         $t2, 0x8019
    ctx->r10 = S32(0X8019 << 16);
    // 0x8018B64C: addiu       $t2, $t2, 0x2CC4
    ctx->r10 = ADD32(ctx->r10, 0X2CC4);
    // 0x8018B650: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x8018B654: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x8018B658: lw          $at, 0x0($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X0);
    // 0x8018B65C: addiu       $t1, $sp, 0x18
    ctx->r9 = ADD32(ctx->r29, 0X18);
    // 0x8018B660: lw          $t5, 0x4($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X4);
    // 0x8018B664: sw          $at, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r1;
    // 0x8018B668: lw          $at, 0x8($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X8);
    // 0x8018B66C: sw          $t5, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r13;
    // 0x8018B670: sw          $at, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r1;
    // 0x8018B674: jal         0x800613C4
    // 0x8018B678: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    Actor_Initialize(rdram, ctx);
        goto after_0;
    // 0x8018B678: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_0:
    // 0x8018B67C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8018B680: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8018B684: addiu       $t9, $sp, 0x24
    ctx->r25 = ADD32(ctx->r29, 0X24);
    // 0x8018B688: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
    // 0x8018B68C: sh          $v0, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r2;
    // 0x8018B690: lw          $at, 0x0($t9)
    ctx->r1 = MEM_W(ctx->r25, 0X0);
    // 0x8018B694: sw          $at, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r1;
    // 0x8018B698: lw          $t6, 0x4($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X4);
    // 0x8018B69C: sw          $t6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r14;
    // 0x8018B6A0: lw          $at, 0x8($t9)
    ctx->r1 = MEM_W(ctx->r25, 0X8);
    // 0x8018B6A4: sw          $at, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r1;
    // 0x8018B6A8: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8018B6AC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8018B6B0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018B6B4: swc1        $f4, 0xF4($a0)
    MEM_W(0XF4, ctx->r4) = ctx->f4.u32l;
    // 0x8018B6B8: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8018B6BC: swc1        $f6, 0xF8($a0)
    MEM_W(0XF8, ctx->r4) = ctx->f6.u32l;
    // 0x8018B6C0: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8018B6C4: swc1        $f10, 0x110($a0)
    MEM_W(0X110, ctx->r4) = ctx->f10.u32l;
    // 0x8018B6C8: swc1        $f8, 0xFC($a0)
    MEM_W(0XFC, ctx->r4) = ctx->f8.u32l;
    // 0x8018B6CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018B6D0: jr          $ra
    // 0x8018B6D4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8018B6D4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void Ending_8018F64C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018F64C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8018F650: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x8018F654: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x8018F658: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8018F65C: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8018F660: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8018F664: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x8018F668: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x8018F66C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8018F670: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8018F674: lbu         $t6, 0x3188($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X3188);
    // 0x8018F678: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x8018F67C: addiu       $s1, $s1, 0x7E64
    ctx->r17 = ADD32(ctx->r17, 0X7E64);
    // 0x8018F680: beq         $t6, $zero, L_8018FC40
    if (ctx->r14 == 0) {
        // 0x8018F684: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8018FC40;
    }
    // 0x8018F684: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8018F688: jal         0x800B8DD0
    // 0x8018F68C: lh          $a1, 0x8($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X8);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x8018F68C: lh          $a1, 0x8($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X8);
    after_0:
    // 0x8018F690: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8018F694: lui         $t8, 0xBC00
    ctx->r24 = S32(0XBC00 << 16);
    // 0x8018F698: ori         $t8, $t8, 0x8
    ctx->r24 = ctx->r24 | 0X8;
    // 0x8018F69C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8018F6A0: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x8018F6A4: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8018F6A8: lh          $t9, 0x66($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X66);
    // 0x8018F6AC: lh          $a0, 0x64($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X64);
    // 0x8018F6B0: lui         $t1, 0x1
    ctx->r9 = S32(0X1 << 16);
    // 0x8018F6B4: ori         $t1, $t1, 0xF400
    ctx->r9 = ctx->r9 | 0XF400;
    // 0x8018F6B8: subu        $a1, $t9, $a0
    ctx->r5 = SUB32(ctx->r25, ctx->r4);
    // 0x8018F6BC: div         $zero, $t1, $a1
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r5)));
    // 0x8018F6C0: negu        $t5, $a0
    ctx->r13 = SUB32(0, ctx->r4);
    // 0x8018F6C4: sll         $t6, $t5, 8
    ctx->r14 = S32(ctx->r13 << 8);
    // 0x8018F6C8: addu        $t7, $t6, $t1
    ctx->r15 = ADD32(ctx->r14, ctx->r9);
    // 0x8018F6CC: mflo        $t2
    ctx->r10 = lo;
    // 0x8018F6D0: andi        $t3, $t2, 0xFFFF
    ctx->r11 = ctx->r10 & 0XFFFF;
    // 0x8018F6D4: sll         $t4, $t3, 16
    ctx->r12 = S32(ctx->r11 << 16);
    // 0x8018F6D8: div         $zero, $t7, $a1
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r5)));
    // 0x8018F6DC: mflo        $t8
    ctx->r24 = lo;
    // 0x8018F6E0: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x8018F6E4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8018F6E8: bne         $a1, $zero, L_8018F6F4
    if (ctx->r5 != 0) {
        // 0x8018F6EC: nop
    
            goto L_8018F6F4;
    }
    // 0x8018F6EC: nop

    // 0x8018F6F0: break       7
    do_break(2149119728);
L_8018F6F4:
    // 0x8018F6F4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8018F6F8: bne         $a1, $at, L_8018F70C
    if (ctx->r5 != ctx->r1) {
        // 0x8018F6FC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8018F70C;
    }
    // 0x8018F6FC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8018F700: bne         $t1, $at, L_8018F70C
    if (ctx->r9 != ctx->r1) {
        // 0x8018F704: nop
    
            goto L_8018F70C;
    }
    // 0x8018F704: nop

    // 0x8018F708: break       6
    do_break(2149119752);
L_8018F70C:
    // 0x8018F70C: addu        $at, $t1, $zero
    ctx->r1 = ADD32(ctx->r9, 0);
    // 0x8018F710: or          $t1, $t4, $t9
    ctx->r9 = ctx->r12 | ctx->r25;
    // 0x8018F714: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x8018F718: bne         $a1, $zero, L_8018F724
    if (ctx->r5 != 0) {
        // 0x8018F71C: nop
    
            goto L_8018F724;
    }
    // 0x8018F71C: nop

    // 0x8018F720: break       7
    do_break(2149119776);
L_8018F724:
    // 0x8018F724: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8018F728: bne         $a1, $at, L_8018F73C
    if (ctx->r5 != ctx->r1) {
        // 0x8018F72C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8018F73C;
    }
    // 0x8018F72C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8018F730: bne         $t7, $at, L_8018F73C
    if (ctx->r15 != ctx->r1) {
        // 0x8018F734: nop
    
            goto L_8018F73C;
    }
    // 0x8018F734: nop

    // 0x8018F738: break       6
    do_break(2149119800);
L_8018F73C:
    // 0x8018F73C: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8018F740: lui         $t3, 0xF800
    ctx->r11 = S32(0XF800 << 16);
    // 0x8018F744: lui         $s2, 0x8014
    ctx->r18 = S32(0X8014 << 16);
    // 0x8018F748: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x8018F74C: sw          $t2, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r10;
    // 0x8018F750: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8018F754: lbu         $t4, 0x61($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X61);
    // 0x8018F758: lbu         $t6, 0x60($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X60);
    // 0x8018F75C: lbu         $t3, 0x62($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X62);
    // 0x8018F760: sll         $t9, $t4, 16
    ctx->r25 = S32(ctx->r12 << 16);
    // 0x8018F764: sll         $t7, $t6, 24
    ctx->r15 = S32(ctx->r14 << 24);
    // 0x8018F768: or          $t1, $t7, $t9
    ctx->r9 = ctx->r15 | ctx->r25;
    // 0x8018F76C: sll         $t5, $t3, 8
    ctx->r13 = S32(ctx->r11 << 8);
    // 0x8018F770: or          $t6, $t1, $t5
    ctx->r14 = ctx->r9 | ctx->r13;
    // 0x8018F774: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8018F778: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8018F77C: lui         $t4, 0xFB00
    ctx->r12 = S32(0XFB00 << 16);
    // 0x8018F780: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8018F784: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x8018F788: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8018F78C: lbu         $t1, 0x69($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X69);
    // 0x8018F790: lbu         $t9, 0x68($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X68);
    // 0x8018F794: lbu         $t4, 0x6A($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X6A);
    // 0x8018F798: sll         $t5, $t1, 16
    ctx->r13 = S32(ctx->r9 << 16);
    // 0x8018F79C: lbu         $t1, 0x6B($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X6B);
    // 0x8018F7A0: sll         $t2, $t9, 24
    ctx->r10 = S32(ctx->r25 << 24);
    // 0x8018F7A4: or          $t6, $t2, $t5
    ctx->r14 = ctx->r10 | ctx->r13;
    // 0x8018F7A8: sll         $t7, $t4, 8
    ctx->r15 = S32(ctx->r12 << 8);
    // 0x8018F7AC: or          $t9, $t6, $t7
    ctx->r25 = ctx->r14 | ctx->r15;
    // 0x8018F7B0: or          $t2, $t9, $t1
    ctx->r10 = ctx->r25 | ctx->r9;
    // 0x8018F7B4: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x8018F7B8: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8018F7BC: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x8018F7C0: addiu       $s2, $s2, -0x4C40
    ctx->r18 = ADD32(ctx->r18, -0X4C40);
    // 0x8018F7C4: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x8018F7C8: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
    // 0x8018F7CC: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8018F7D0: lbu         $t9, 0x6D($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X6D);
    // 0x8018F7D4: lbu         $t6, 0x6C($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X6C);
    // 0x8018F7D8: lbu         $t8, 0x6E($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X6E);
    // 0x8018F7DC: sll         $t1, $t9, 16
    ctx->r9 = S32(ctx->r25 << 16);
    // 0x8018F7E0: lbu         $t9, 0x6F($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X6F);
    // 0x8018F7E4: sll         $t7, $t6, 24
    ctx->r15 = S32(ctx->r14 << 24);
    // 0x8018F7E8: or          $t2, $t7, $t1
    ctx->r10 = ctx->r15 | ctx->r9;
    // 0x8018F7EC: sll         $t4, $t8, 8
    ctx->r12 = S32(ctx->r24 << 8);
    // 0x8018F7F0: or          $t6, $t2, $t4
    ctx->r14 = ctx->r10 | ctx->r12;
    // 0x8018F7F4: or          $t7, $t6, $t9
    ctx->r15 = ctx->r14 | ctx->r25;
    // 0x8018F7F8: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8018F7FC: lw          $t1, 0xC($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XC);
    // 0x8018F800: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8018F804: subu        $t5, $s3, $t1
    ctx->r13 = SUB32(ctx->r19, ctx->r9);
    // 0x8018F808: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x8018F80C: bgez        $t5, L_8018F824
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8018F810: cvt.s.w     $f0, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8018F824;
    }
    // 0x8018F810: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8018F814: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8018F818: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018F81C: nop

    // 0x8018F820: add.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f6.fl;
L_8018F824:
    // 0x8018F824: lwc1        $f10, 0x3C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x8018F828: lwc1        $f8, 0x18($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8018F82C: lwc1        $f6, 0x40($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8018F830: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8018F834: lwc1        $f4, 0x1C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x8018F838: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8018F83C: mul.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8018F840: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x8018F844: lwc1        $f16, 0x20($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X20);
    // 0x8018F848: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8018F84C: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8018F850: lwc1        $f18, 0x44($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X44);
    // 0x8018F854: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8018F858: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x8018F85C: mul.s       $f6, $f0, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x8018F860: add.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x8018F864: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x8018F868: jal         0x80005B00
    // 0x8018F86C: nop

    Matrix_Translate(rdram, ctx);
        goto after_1;
    // 0x8018F86C: nop

    after_1:
    // 0x8018F870: lw          $a1, 0x30($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X30);
    // 0x8018F874: lw          $a2, 0x34($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X34);
    // 0x8018F878: lw          $a3, 0x38($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X38);
    // 0x8018F87C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8018F880: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8018F884: jal         0x80005C34
    // 0x8018F888: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_2;
    // 0x8018F888: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_2:
    // 0x8018F88C: mtc1        $s3, $f10
    ctx->f10.u32l = ctx->r19;
    // 0x8018F890: bgez        $s3, L_8018F8A8
    if (SIGNED(ctx->r19) >= 0) {
        // 0x8018F894: cvt.s.w     $f8, $f10
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
            goto L_8018F8A8;
    }
    // 0x8018F894: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8018F898: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8018F89C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8018F8A0: nop

    // 0x8018F8A4: add.s       $f8, $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f18.fl;
L_8018F8A8:
    // 0x8018F8A8: lbu         $t4, 0x70($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X70);
    // 0x8018F8AC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018F8B0: lwc1        $f16, 0x6C1C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6C1C);
    // 0x8018F8B4: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x8018F8B8: mul.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8018F8BC: bgez        $t4, L_8018F8D4
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8018F8C0: cvt.s.w     $f10, $f4
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8018F8D4;
    }
    // 0x8018F8C0: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8018F8C4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8018F8C8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8018F8CC: nop

    // 0x8018F8D0: add.s       $f10, $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f18.fl;
L_8018F8D4:
    // 0x8018F8D4: jal         0x80023090
    // 0x8018F8D8: add.s       $f12, $f6, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f10.fl;
    __sinf_recomp(rdram, ctx);
        goto after_3;
    // 0x8018F8D8: add.s       $f12, $f6, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f10.fl;
    after_3:
    // 0x8018F8DC: lbu         $t3, 0x71($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X71);
    // 0x8018F8E0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8018F8E4: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8018F8E8: bnel        $t3, $at, L_8018FA40
    if (ctx->r11 != ctx->r1) {
        // 0x8018F8EC: lwc1        $f10, 0x58($s0)
        ctx->f10.u32l = MEM_W(ctx->r16, 0X58);
            goto L_8018FA40;
    }
    goto skip_0;
    // 0x8018F8EC: lwc1        $f10, 0x58($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X58);
    skip_0:
    // 0x8018F8F0: lwc1        $f18, 0x58($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X58);
    // 0x8018F8F4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018F8F8: lwc1        $f16, -0x7A0C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X7A0C);
    // 0x8018F8FC: lwc1        $f8, 0x28($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X28);
    // 0x8018F900: mul.s       $f6, $f0, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x8018F904: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x8018F908: sub.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x8018F90C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8018F910: subu        $t9, $s3, $t6
    ctx->r25 = SUB32(ctx->r19, ctx->r14);
    // 0x8018F914: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x8018F918: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8018F91C: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8018F920: bgez        $t9, L_8018F934
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8018F924: cvt.s.w     $f16, $f8
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
            goto L_8018F934;
    }
    // 0x8018F924: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8018F928: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8018F92C: nop

    // 0x8018F930: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_8018F934:
    // 0x8018F934: lwc1        $f4, 0x4C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x8018F938: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018F93C: lwc1        $f18, 0x6C20($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6C20);
    // 0x8018F940: mul.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x8018F944: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018F948: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8018F94C: mul.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x8018F950: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8018F954: jal         0x80005E90
    // 0x8018F958: nop

    Matrix_RotateY(rdram, ctx);
        goto after_4;
    // 0x8018F958: nop

    after_4:
    // 0x8018F95C: lwc1        $f8, 0x54($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X54);
    // 0x8018F960: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018F964: lwc1        $f10, -0x7A10($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X7A10);
    // 0x8018F968: lwc1        $f4, 0x24($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8018F96C: mul.s       $f18, $f20, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f20.fl, ctx->f8.fl);
    // 0x8018F970: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x8018F974: sub.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x8018F978: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8018F97C: subu        $t1, $s3, $t7
    ctx->r9 = SUB32(ctx->r19, ctx->r15);
    // 0x8018F980: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x8018F984: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8018F988: add.s       $f16, $f6, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x8018F98C: bgez        $t1, L_8018F9A0
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8018F990: cvt.s.w     $f10, $f4
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8018F9A0;
    }
    // 0x8018F990: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8018F994: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018F998: nop

    // 0x8018F99C: add.s       $f10, $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f8.fl;
L_8018F9A0:
    // 0x8018F9A0: lwc1        $f6, 0x48($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X48);
    // 0x8018F9A4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018F9A8: lwc1        $f8, 0x6C24($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6C24);
    // 0x8018F9AC: mul.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x8018F9B0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018F9B4: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8018F9B8: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8018F9BC: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8018F9C0: jal         0x80005D44
    // 0x8018F9C4: nop

    Matrix_RotateX(rdram, ctx);
        goto after_5;
    // 0x8018F9C4: nop

    after_5:
    // 0x8018F9C8: lwc1        $f4, 0x5C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X5C);
    // 0x8018F9CC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018F9D0: lwc1        $f16, -0x7A08($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X7A08);
    // 0x8018F9D4: lwc1        $f6, 0x2C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8018F9D8: mul.s       $f8, $f20, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f4.fl);
    // 0x8018F9DC: lw          $t5, 0xC($s0)
    ctx->r13 = MEM_W(ctx->r16, 0XC);
    // 0x8018F9E0: add.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x8018F9E4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8018F9E8: subu        $t8, $s3, $t5
    ctx->r24 = SUB32(ctx->r19, ctx->r13);
    // 0x8018F9EC: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x8018F9F0: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8018F9F4: add.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x8018F9F8: bgez        $t8, L_8018FA0C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8018F9FC: cvt.s.w     $f16, $f6
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
            goto L_8018FA0C;
    }
    // 0x8018F9FC: cvt.s.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8018FA00: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018FA04: nop

    // 0x8018FA08: add.s       $f16, $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f4.fl;
L_8018FA0C:
    // 0x8018FA0C: lwc1        $f18, 0x50($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X50);
    // 0x8018FA10: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018FA14: lwc1        $f4, 0x6C28($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6C28);
    // 0x8018FA18: mul.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8018FA1C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018FA20: add.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8018FA24: mul.s       $f16, $f6, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x8018FA28: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8018FA2C: jal         0x80005FE0
    // 0x8018FA30: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_6;
    // 0x8018FA30: nop

    after_6:
    // 0x8018FA34: b           L_8018FB5C
    // 0x8018FA38: nop

        goto L_8018FB5C;
    // 0x8018FA38: nop

    // 0x8018FA3C: lwc1        $f10, 0x58($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X58);
L_8018FA40:
    // 0x8018FA40: lw          $t2, 0xC($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XC);
    // 0x8018FA44: lwc1        $f18, 0x28($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X28);
    // 0x8018FA48: mul.s       $f8, $f20, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f10.fl);
    // 0x8018FA4C: subu        $t4, $s3, $t2
    ctx->r12 = SUB32(ctx->r19, ctx->r10);
    // 0x8018FA50: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x8018FA54: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8018FA58: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8018FA5C: cvt.s.w     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8018FA60: bgez        $t4, L_8018FA74
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8018FA64: add.s       $f6, $f18, $f8
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f8.fl;
            goto L_8018FA74;
    }
    // 0x8018FA64: add.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x8018FA68: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018FA6C: nop

    // 0x8018FA70: add.s       $f16, $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f10.fl;
L_8018FA74:
    // 0x8018FA74: lwc1        $f18, 0x4C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x8018FA78: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018FA7C: lwc1        $f10, 0x6C2C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6C2C);
    // 0x8018FA80: mul.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8018FA84: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018FA88: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8018FA8C: mul.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x8018FA90: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8018FA94: jal         0x80005E90
    // 0x8018FA98: nop

    Matrix_RotateY(rdram, ctx);
        goto after_7;
    // 0x8018FA98: nop

    after_7:
    // 0x8018FA9C: lwc1        $f6, 0x54($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X54);
    // 0x8018FAA0: lw          $t3, 0xC($s0)
    ctx->r11 = MEM_W(ctx->r16, 0XC);
    // 0x8018FAA4: lwc1        $f18, 0x24($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8018FAA8: mul.s       $f8, $f20, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f6.fl);
    // 0x8018FAAC: subu        $t6, $s3, $t3
    ctx->r14 = SUB32(ctx->r19, ctx->r11);
    // 0x8018FAB0: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x8018FAB4: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8018FAB8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8018FABC: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8018FAC0: bgez        $t6, L_8018FAD4
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8018FAC4: add.s       $f4, $f18, $f8
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f8.fl;
            goto L_8018FAD4;
    }
    // 0x8018FAC4: add.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x8018FAC8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018FACC: nop

    // 0x8018FAD0: add.s       $f16, $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f6.fl;
L_8018FAD4:
    // 0x8018FAD4: lwc1        $f18, 0x48($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X48);
    // 0x8018FAD8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018FADC: lwc1        $f6, 0x6C30($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6C30);
    // 0x8018FAE0: mul.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8018FAE4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018FAE8: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8018FAEC: mul.s       $f16, $f10, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x8018FAF0: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8018FAF4: jal         0x80005D44
    // 0x8018FAF8: nop

    Matrix_RotateX(rdram, ctx);
        goto after_8;
    // 0x8018FAF8: nop

    after_8:
    // 0x8018FAFC: lwc1        $f4, 0x5C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X5C);
    // 0x8018FB00: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    // 0x8018FB04: lwc1        $f18, 0x2C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8018FB08: mul.s       $f8, $f20, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f4.fl);
    // 0x8018FB0C: subu        $t7, $s3, $t9
    ctx->r15 = SUB32(ctx->r19, ctx->r25);
    // 0x8018FB10: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x8018FB14: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8018FB18: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8018FB1C: cvt.s.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8018FB20: bgez        $t7, L_8018FB34
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8018FB24: add.s       $f10, $f18, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f8.fl;
            goto L_8018FB34;
    }
    // 0x8018FB24: add.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x8018FB28: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018FB2C: nop

    // 0x8018FB30: add.s       $f16, $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f4.fl;
L_8018FB34:
    // 0x8018FB34: lwc1        $f18, 0x50($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X50);
    // 0x8018FB38: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018FB3C: lwc1        $f4, 0x6C34($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6C34);
    // 0x8018FB40: mul.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8018FB44: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018FB48: add.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8018FB4C: mul.s       $f16, $f6, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x8018FB50: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8018FB54: jal         0x80005FE0
    // 0x8018FB58: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_9;
    // 0x8018FB58: nop

    after_9:
L_8018FB5C:
    // 0x8018FB5C: jal         0x80006EB8
    // 0x8018FB60: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_10;
    // 0x8018FB60: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_10:
    // 0x8018FB64: lui         $s0, 0x600
    ctx->r16 = S32(0X600 << 16);
    // 0x8018FB68: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8018FB6C: lui         $t5, 0xD01
    ctx->r13 = S32(0XD01 << 16);
    // 0x8018FB70: addiu       $t5, $t5, -0x65C0
    ctx->r13 = ADD32(ctx->r13, -0X65C0);
    // 0x8018FB74: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x8018FB78: sw          $t1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r9;
    // 0x8018FB7C: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x8018FB80: sw          $s0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r16;
    // 0x8018FB84: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8018FB88: jal         0x800B8DD0
    // 0x8018FB8C: addiu       $a1, $zero, 0x43
    ctx->r5 = ADD32(0, 0X43);
    RCP_SetupDL(rdram, ctx);
        goto after_11;
    // 0x8018FB8C: addiu       $a1, $zero, 0x43
    ctx->r5 = ADD32(0, 0X43);
    after_11:
    // 0x8018FB90: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8018FB94: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8018FB98: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8018FB9C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8018FBA0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8018FBA4: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8018FBA8: jal         0x80005B00
    // 0x8018FBAC: lui         $a3, 0xC270
    ctx->r7 = S32(0XC270 << 16);
    Matrix_Translate(rdram, ctx);
        goto after_12;
    // 0x8018FBAC: lui         $a3, 0xC270
    ctx->r7 = S32(0XC270 << 16);
    after_12:
    // 0x8018FBB0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8018FBB4: divu        $zero, $s3, $at
    lo = S32(U32(ctx->r19) / U32(ctx->r1)); hi = S32(U32(ctx->r19) % U32(ctx->r1));
    // 0x8018FBB8: mfhi        $t2
    ctx->r10 = hi;
    // 0x8018FBBC: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x8018FBC0: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8018FBC4: bgez        $t2, L_8018FBDC
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8018FBC8: cvt.s.w     $f10, $f18
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.fl = CVT_S_W(ctx->f18.u32l);
            goto L_8018FBDC;
    }
    // 0x8018FBC8: cvt.s.w     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8018FBCC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8018FBD0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018FBD4: nop

    // 0x8018FBD8: add.s       $f10, $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f8.fl;
L_8018FBDC:
    // 0x8018FBDC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018FBE0: lwc1        $f6, 0x6C38($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6C38);
    // 0x8018FBE4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018FBE8: lwc1        $f4, 0x6C3C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6C3C);
    // 0x8018FBEC: mul.s       $f0, $f10, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x8018FBF0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018FBF4: lwc1        $f16, 0x6C40($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6C40);
    // 0x8018FBF8: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8018FBFC: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8018FC00: add.s       $f2, $f0, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x8018FC04: add.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x8018FC08: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x8018FC0C: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x8018FC10: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x8018FC14: jal         0x80005C34
    // 0x8018FC18: nop

    Matrix_Scale(rdram, ctx);
        goto after_13;
    // 0x8018FC18: nop

    after_13:
    // 0x8018FC1C: jal         0x80006EB8
    // 0x8018FC20: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_14;
    // 0x8018FC20: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_14:
    // 0x8018FC24: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8018FC28: lui         $t6, 0x701
    ctx->r14 = S32(0X701 << 16);
    // 0x8018FC2C: addiu       $t6, $t6, 0x970
    ctx->r14 = ADD32(ctx->r14, 0X970);
    // 0x8018FC30: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x8018FC34: sw          $t3, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r11;
    // 0x8018FC38: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8018FC3C: sw          $s0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r16;
L_8018FC40:
    // 0x8018FC40: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8018FC44: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8018FC48: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x8018FC4C: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x8018FC50: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x8018FC54: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x8018FC58: jr          $ra
    // 0x8018FC5C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8018FC5C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void Ending_8018A124(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018A124: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8018A128: addiu       $t1, $sp, 0x2C
    ctx->r9 = ADD32(ctx->r29, 0X2C);
    // 0x8018A12C: addiu       $t2, $sp, 0x20
    ctx->r10 = ADD32(ctx->r29, 0X20);
    // 0x8018A130: addiu       $t3, $sp, 0x14
    ctx->r11 = ADD32(ctx->r29, 0X14);
    // 0x8018A134: addiu       $t4, $sp, 0x8
    ctx->r12 = ADD32(ctx->r29, 0X8);
    // 0x8018A138: addiu       $t5, $sp, 0x0
    ctx->r13 = ADD32(ctx->r29, 0X0);
    // 0x8018A13C: lui         $t6, 0x8019
    ctx->r14 = S32(0X8019 << 16);
    // 0x8018A140: addiu       $t6, $t6, 0x2C08
    ctx->r14 = ADD32(ctx->r14, 0X2C08);
    // 0x8018A144: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x8018A148: lui         $t8, 0x8019
    ctx->r24 = S32(0X8019 << 16);
    // 0x8018A14C: addiu       $t8, $t8, 0x2C14
    ctx->r24 = ADD32(ctx->r24, 0X2C14);
    // 0x8018A150: sw          $at, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r1;
    // 0x8018A154: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x8018A158: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x8018A15C: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x8018A160: sw          $t9, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r25;
    // 0x8018A164: lw          $at, 0x8($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X8);
    // 0x8018A168: lui         $t6, 0x8019
    ctx->r14 = S32(0X8019 << 16);
    // 0x8018A16C: addiu       $t6, $t6, 0x2C20
    ctx->r14 = ADD32(ctx->r14, 0X2C20);
    // 0x8018A170: sw          $at, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r1;
    // 0x8018A174: lw          $at, 0x0($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X0);
    // 0x8018A178: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8018A17C: addu        $v1, $t1, $v0
    ctx->r3 = ADD32(ctx->r9, ctx->r2);
    // 0x8018A180: sw          $at, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r1;
    // 0x8018A184: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x8018A188: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8018A18C: addu        $a1, $t2, $v0
    ctx->r5 = ADD32(ctx->r10, ctx->r2);
    // 0x8018A190: sw          $t9, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r25;
    // 0x8018A194: lw          $at, 0x8($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X8);
    // 0x8018A198: lui         $t8, 0x8019
    ctx->r24 = S32(0X8019 << 16);
    // 0x8018A19C: addiu       $t8, $t8, 0x2C2C
    ctx->r24 = ADD32(ctx->r24, 0X2C2C);
    // 0x8018A1A0: sw          $at, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r1;
    // 0x8018A1A4: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x8018A1A8: addu        $a2, $t3, $v0
    ctx->r6 = ADD32(ctx->r11, ctx->r2);
    // 0x8018A1AC: addu        $a3, $t4, $v0
    ctx->r7 = ADD32(ctx->r12, ctx->r2);
    // 0x8018A1B0: sw          $at, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r1;
    // 0x8018A1B4: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x8018A1B8: sw          $t9, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r25;
    // 0x8018A1BC: lw          $at, 0x8($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X8);
    // 0x8018A1C0: lui         $t6, 0x8019
    ctx->r14 = S32(0X8019 << 16);
    // 0x8018A1C4: addiu       $t6, $t6, 0x2C38
    ctx->r14 = ADD32(ctx->r14, 0X2C38);
    // 0x8018A1C8: sw          $at, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r1;
    // 0x8018A1CC: lw          $at, 0x0($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X0);
    // 0x8018A1D0: sw          $at, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r1;
    // 0x8018A1D4: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x8018A1D8: sw          $t9, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r25;
    // 0x8018A1DC: lw          $at, 0x8($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X8);
    // 0x8018A1E0: sw          $at, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r1;
    // 0x8018A1E4: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x8018A1E8: sw          $at, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r1;
    // 0x8018A1EC: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x8018A1F0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018A1F4: sw          $t9, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r25;
    // 0x8018A1F8: swc1        $f4, 0x7978($at)
    MEM_W(0X7978, ctx->r1) = ctx->f4.u32l;
    // 0x8018A1FC: lwc1        $f6, 0x4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8018A200: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018A204: swc1        $f6, 0x7980($at)
    MEM_W(0X7980, ctx->r1) = ctx->f6.u32l;
    // 0x8018A208: lwc1        $f8, 0x8($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8018A20C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018A210: swc1        $f8, 0x7988($at)
    MEM_W(0X7988, ctx->r1) = ctx->f8.u32l;
    // 0x8018A214: lwc1        $f10, 0x0($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8018A218: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018A21C: swc1        $f10, 0x79A0($at)
    MEM_W(0X79A0, ctx->r1) = ctx->f10.u32l;
    // 0x8018A220: lwc1        $f16, 0x4($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8018A224: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018A228: swc1        $f16, 0x79B8($at)
    MEM_W(0X79B8, ctx->r1) = ctx->f16.u32l;
    // 0x8018A22C: lwc1        $f18, 0x8($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8018A230: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018A234: swc1        $f18, 0x79C0($at)
    MEM_W(0X79C0, ctx->r1) = ctx->f18.u32l;
    // 0x8018A238: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x8018A23C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018A240: sw          $t8, -0x7AB8($at)
    MEM_W(-0X7AB8, ctx->r1) = ctx->r24;
    // 0x8018A244: lw          $t7, 0x4($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X4);
    // 0x8018A248: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018A24C: sw          $t7, -0x7AB4($at)
    MEM_W(-0X7AB4, ctx->r1) = ctx->r15;
    // 0x8018A250: lw          $t6, 0x8($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X8);
    // 0x8018A254: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018A258: sw          $t6, -0x7AB0($at)
    MEM_W(-0X7AB0, ctx->r1) = ctx->r14;
    // 0x8018A25C: lw          $t9, 0x0($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X0);
    // 0x8018A260: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018A264: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x8018A268: sw          $t9, -0x7AAC($at)
    MEM_W(-0X7AAC, ctx->r1) = ctx->r25;
    // 0x8018A26C: lw          $t8, 0x4($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X4);
    // 0x8018A270: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018A274: addu        $t0, $t5, $t6
    ctx->r8 = ADD32(ctx->r13, ctx->r14);
    // 0x8018A278: sw          $t8, -0x7AA8($at)
    MEM_W(-0X7AA8, ctx->r1) = ctx->r24;
    // 0x8018A27C: lw          $t7, 0x8($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X8);
    // 0x8018A280: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018A284: sw          $t7, -0x7AA4($at)
    MEM_W(-0X7AA4, ctx->r1) = ctx->r15;
    // 0x8018A288: lwc1        $f4, 0x0($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X0);
    // 0x8018A28C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018A290: swc1        $f4, -0x7B30($at)
    MEM_W(-0X7B30, ctx->r1) = ctx->f4.u32l;
    // 0x8018A294: lwc1        $f6, 0x4($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X4);
    // 0x8018A298: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018A29C: swc1        $f6, -0x7B2C($at)
    MEM_W(-0X7B2C, ctx->r1) = ctx->f6.u32l;
    // 0x8018A2A0: jr          $ra
    // 0x8018A2A4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8018A2A4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void Ending_8018A024(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018A024: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8018A028: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8018A02C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018A030: lui         $at, 0xC2C8
    ctx->r1 = S32(0XC2C8 << 16);
    // 0x8018A034: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018A038: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018A03C: lwc1        $f6, -0x7B30($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7B30);
    // 0x8018A040: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018A044: lwc1        $f8, 0x6554($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6554);
    // 0x8018A048: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018A04C: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x8018A050: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8018A054: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x8018A058: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018A05C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8018A060: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x8018A064: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8018A068: jal         0x80005D44
    // 0x8018A06C: nop

    Matrix_RotateX(rdram, ctx);
        goto after_0;
    // 0x8018A06C: nop

    after_0:
    // 0x8018A070: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018A074: lwc1        $f16, -0x7B2C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X7B2C);
    // 0x8018A078: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018A07C: lwc1        $f18, 0x6558($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6558);
    // 0x8018A080: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018A084: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018A088: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8018A08C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018A090: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8018A094: jal         0x80005E90
    // 0x8018A098: nop

    Matrix_RotateY(rdram, ctx);
        goto after_1;
    // 0x8018A098: nop

    after_1:
    // 0x8018A09C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018A0A0: lwc1        $f6, -0x7B28($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7B28);
    // 0x8018A0A4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018A0A8: lwc1        $f8, 0x655C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X655C);
    // 0x8018A0AC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018A0B0: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018A0B4: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8018A0B8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018A0BC: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8018A0C0: jal         0x80005FE0
    // 0x8018A0C4: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_2;
    // 0x8018A0C4: nop

    after_2:
    // 0x8018A0C8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018A0CC: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018A0D0: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x8018A0D4: jal         0x80006A20
    // 0x8018A0D8: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_3;
    // 0x8018A0D8: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    after_3:
    // 0x8018A0DC: lwc1        $f16, 0x18($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8018A0E0: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8018A0E4: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8018A0E8: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8018A0EC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018A0F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018A0F4: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8018A0F8: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x8018A0FC: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8018A100: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x8018A104: sw          $t7, -0x7B24($at)
    MEM_W(-0X7B24, ctx->r1) = ctx->r15;
    // 0x8018A108: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018A10C: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    // 0x8018A110: sw          $t9, -0x7B20($at)
    MEM_W(-0X7B20, ctx->r1) = ctx->r25;
    // 0x8018A114: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018A118: sw          $t1, -0x7B1C($at)
    MEM_W(-0X7B1C, ctx->r1) = ctx->r9;
    // 0x8018A11C: jr          $ra
    // 0x8018A120: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8018A120: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void Ending_8018B3E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018B3E8: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8018B3EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018B3F0: lui         $t7, 0x8019
    ctx->r15 = S32(0X8019 << 16);
    // 0x8018B3F4: addiu       $t7, $t7, 0x2C40
    ctx->r15 = ADD32(ctx->r15, 0X2C40);
    // 0x8018B3F8: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x8018B3FC: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x8018B400: addiu       $t6, $sp, 0x38
    ctx->r14 = ADD32(ctx->r29, 0X38);
    // 0x8018B404: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x8018B408: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x8018B40C: lw          $t0, 0xC($t7)
    ctx->r8 = MEM_W(ctx->r15, 0XC);
    // 0x8018B410: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x8018B414: lui         $t2, 0x8019
    ctx->r10 = S32(0X8019 << 16);
    // 0x8018B418: sw          $t0, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r8;
    // 0x8018B41C: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x8018B420: lw          $at, 0x10($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X10);
    // 0x8018B424: lw          $t0, 0x14($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X14);
    // 0x8018B428: addiu       $t2, $t2, 0x2C58
    ctx->r10 = ADD32(ctx->r10, 0X2C58);
    // 0x8018B42C: sw          $at, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r1;
    // 0x8018B430: sw          $t0, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r8;
    // 0x8018B434: lw          $t5, 0x4($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X4);
    // 0x8018B438: lw          $at, 0x0($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X0);
    // 0x8018B43C: addiu       $t1, $sp, 0x20
    ctx->r9 = ADD32(ctx->r29, 0X20);
    // 0x8018B440: sw          $t5, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r13;
    // 0x8018B444: sw          $at, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r1;
    // 0x8018B448: lw          $at, 0x8($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X8);
    // 0x8018B44C: lw          $t5, 0xC($t2)
    ctx->r13 = MEM_W(ctx->r10, 0XC);
    // 0x8018B450: sw          $at, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r1;
    // 0x8018B454: sw          $t5, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->r13;
    // 0x8018B458: lw          $t5, 0x14($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X14);
    // 0x8018B45C: lw          $at, 0x10($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X10);
    // 0x8018B460: sw          $t5, 0x14($t1)
    MEM_W(0X14, ctx->r9) = ctx->r13;
    // 0x8018B464: sw          $at, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->r1;
    // 0x8018B468: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x8018B46C: jal         0x800613C4
    // 0x8018B470: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    Actor_Initialize(rdram, ctx);
        goto after_0;
    // 0x8018B470: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    after_0:
    // 0x8018B474: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x8018B478: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8018B47C: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8018B480: sll         $v1, $a1, 2
    ctx->r3 = S32(ctx->r5 << 2);
    // 0x8018B484: subu        $v1, $v1, $a1
    ctx->r3 = SUB32(ctx->r3, ctx->r5);
    // 0x8018B488: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8018B48C: addiu       $t8, $sp, 0x20
    ctx->r24 = ADD32(ctx->r29, 0X20);
    // 0x8018B490: addu        $v0, $v1, $t8
    ctx->r2 = ADD32(ctx->r3, ctx->r24);
    // 0x8018B494: sb          $t9, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r25;
    // 0x8018B498: sh          $zero, 0x2($a0)
    MEM_H(0X2, ctx->r4) = 0;
    // 0x8018B49C: sh          $a1, 0xB8($a0)
    MEM_H(0XB8, ctx->r4) = ctx->r5;
    // 0x8018B4A0: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8018B4A4: addiu       $t6, $sp, 0x38
    ctx->r14 = ADD32(ctx->r29, 0X38);
    // 0x8018B4A8: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x8018B4AC: swc1        $f4, 0xF4($a0)
    MEM_W(0XF4, ctx->r4) = ctx->f4.u32l;
    // 0x8018B4B0: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8018B4B4: swc1        $f6, 0xF8($a0)
    MEM_W(0XF8, ctx->r4) = ctx->f6.u32l;
    // 0x8018B4B8: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8018B4BC: swc1        $f8, 0xFC($a0)
    MEM_W(0XFC, ctx->r4) = ctx->f8.u32l;
    // 0x8018B4C0: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x8018B4C4: sw          $at, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r1;
    // 0x8018B4C8: lw          $t4, 0x4($t7)
    ctx->r12 = MEM_W(ctx->r15, 0X4);
    // 0x8018B4CC: sw          $t4, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r12;
    // 0x8018B4D0: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x8018B4D4: bne         $a1, $zero, L_8018B510
    if (ctx->r5 != 0) {
        // 0x8018B4D8: sw          $at, 0xC($a0)
        MEM_W(0XC, ctx->r4) = ctx->r1;
            goto L_8018B510;
    }
    // 0x8018B4D8: sw          $at, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r1;
    // 0x8018B4DC: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x8018B4E0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8018B4E4: lwc1        $f10, 0x4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8018B4E8: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x8018B4EC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018B4F0: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8018B4F4: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8018B4F8: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x8018B4FC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018B500: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8018B504: swc1        $f18, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f18.u32l;
    // 0x8018B508: swc1        $f10, 0x114($a0)
    MEM_W(0X114, ctx->r4) = ctx->f10.u32l;
    // 0x8018B50C: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
L_8018B510:
    // 0x8018B510: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8018B514: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8018B518: nop

    // 0x8018B51C: swc1        $f16, 0x110($a0)
    MEM_W(0X110, ctx->r4) = ctx->f16.u32l;
    // 0x8018B520: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018B524: jr          $ra
    // 0x8018B528: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8018B528: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void Ending_80188030(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80188030: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80188034: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80188038: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8018803C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80188040: beq         $s0, $zero, L_80188060
    if (ctx->r16 == 0) {
        // 0x80188044: lui         $at, 0xC461
        ctx->r1 = S32(0XC461 << 16);
            goto L_80188060;
    }
    // 0x80188044: lui         $at, 0xC461
    ctx->r1 = S32(0XC461 << 16);
    // 0x80188048: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8018804C: beq         $s0, $t0, L_801880A0
    if (ctx->r16 == ctx->r8) {
        // 0x80188050: lui         $at, 0x8019
        ctx->r1 = S32(0X8019 << 16);
            goto L_801880A0;
    }
    // 0x80188050: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80188054: lwc1        $f14, 0x30($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80188058: b           L_801880BC
    // 0x8018805C: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
        goto L_801880BC;
    // 0x8018805C: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
L_80188060:
    // 0x80188060: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80188064: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80188068: lwc1        $f2, 0x6F9C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X6F9C);
    // 0x8018806C: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80188070: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80188074: mul.s       $f12, $f0, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80188078: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018807C: lui         $at, 0xC3A0
    ctx->r1 = S32(0XC3A0 << 16);
    // 0x80188080: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80188084: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80188088: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8018808C: mul.s       $f12, $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x80188090: nop

    // 0x80188094: mul.s       $f14, $f0, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80188098: b           L_801880BC
    // 0x8018809C: nop

        goto L_801880BC;
    // 0x8018809C: nop

L_801880A0:
    // 0x801880A0: lwc1        $f0, 0x6470($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6470);
    // 0x801880A4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801880A8: lwc1        $f6, 0x6F9C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6F9C);
    // 0x801880AC: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x801880B0: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x801880B4: mul.s       $f12, $f0, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x801880B8: nop

L_801880BC:
    // 0x801880BC: bne         $s0, $t0, L_8018810C
    if (ctx->r16 != ctx->r8) {
        // 0x801880C0: lui         $t6, 0x8017
        ctx->r14 = S32(0X8017 << 16);
            goto L_8018810C;
    }
    // 0x801880C0: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x801880C4: lw          $t6, 0x7A80($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7A80);
    // 0x801880C8: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x801880CC: addiu       $a0, $a0, 0x6F9C
    ctx->r4 = ADD32(ctx->r4, 0X6F9C);
    // 0x801880D0: slti        $at, $t6, 0x18A
    ctx->r1 = SIGNED(ctx->r14) < 0X18A ? 1 : 0;
    // 0x801880D4: bne         $at, $zero, L_8018810C
    if (ctx->r1 != 0) {
        // 0x801880D8: addiu       $a1, $zero, 0x0
        ctx->r5 = ADD32(0, 0X0);
            goto L_8018810C;
    }
    // 0x801880D8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x801880DC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801880E0: lwc1        $f8, 0x6474($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6474);
    // 0x801880E4: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x801880E8: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801880EC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x801880F0: swc1        $f12, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f12.u32l;
    // 0x801880F4: swc1        $f14, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f14.u32l;
    // 0x801880F8: jal         0x8009BC2C
    // 0x801880FC: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_0;
    // 0x801880FC: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x80188100: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80188104: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80188108: lwc1        $f14, 0x30($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X30);
L_8018810C:
    // 0x8018810C: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80188110: lw          $a1, 0x6F88($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X6F88);
    // 0x80188114: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80188118: lw          $a0, 0x7A80($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7A80);
    // 0x8018811C: blez        $a1, L_80188174
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80188120: lui         $t7, 0x8019
        ctx->r15 = S32(0X8019 << 16);
            goto L_80188174;
    }
    // 0x80188120: lui         $t7, 0x8019
    ctx->r15 = S32(0X8019 << 16);
    // 0x80188124: addiu       $v0, $t7, 0x6D08
    ctx->r2 = ADD32(ctx->r15, 0X6D08);
    // 0x80188128: sll         $t8, $a1, 6
    ctx->r24 = S32(ctx->r5 << 6);
    // 0x8018812C: addu        $v1, $t8, $v0
    ctx->r3 = ADD32(ctx->r24, ctx->r2);
    // 0x80188130: lwc1        $f10, 0x14($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X14);
L_80188134:
    // 0x80188134: lwc1        $f18, 0x10($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80188138: slti        $at, $a0, 0x18A
    ctx->r1 = SIGNED(ctx->r4) < 0X18A ? 1 : 0;
    // 0x8018813C: sub.s       $f16, $f10, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f12.fl;
    // 0x80188140: add.s       $f4, $f18, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f14.fl;
    // 0x80188144: swc1        $f16, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f16.u32l;
    // 0x80188148: bne         $s0, $t0, L_80188158
    if (ctx->r16 != ctx->r8) {
        // 0x8018814C: swc1        $f4, 0x10($v0)
        MEM_W(0X10, ctx->r2) = ctx->f4.u32l;
            goto L_80188158;
    }
    // 0x8018814C: swc1        $f4, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f4.u32l;
    // 0x80188150: beql        $at, $zero, L_80188168
    if (ctx->r1 == 0) {
        // 0x80188154: addiu       $v0, $v0, 0x40
        ctx->r2 = ADD32(ctx->r2, 0X40);
            goto L_80188168;
    }
    goto skip_0;
    // 0x80188154: addiu       $v0, $v0, 0x40
    ctx->r2 = ADD32(ctx->r2, 0X40);
    skip_0:
L_80188158:
    // 0x80188158: lw          $t9, 0x34($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X34);
    // 0x8018815C: addiu       $t1, $t9, 0x1
    ctx->r9 = ADD32(ctx->r25, 0X1);
    // 0x80188160: sw          $t1, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r9;
    // 0x80188164: addiu       $v0, $v0, 0x40
    ctx->r2 = ADD32(ctx->r2, 0X40);
L_80188168:
    // 0x80188168: sltu        $at, $v0, $v1
    ctx->r1 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x8018816C: bnel        $at, $zero, L_80188134
    if (ctx->r1 != 0) {
        // 0x80188170: lwc1        $f10, 0x14($v0)
        ctx->f10.u32l = MEM_W(ctx->r2, 0X14);
            goto L_80188134;
    }
    goto skip_1;
    // 0x80188170: lwc1        $f10, 0x14($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X14);
    skip_1:
L_80188174:
    // 0x80188174: slti        $at, $a0, 0x96
    ctx->r1 = SIGNED(ctx->r4) < 0X96 ? 1 : 0;
    // 0x80188178: bne         $at, $zero, L_80188184
    if (ctx->r1 != 0) {
        // 0x8018817C: slti        $at, $a0, 0xAB
        ctx->r1 = SIGNED(ctx->r4) < 0XAB ? 1 : 0;
            goto L_80188184;
    }
    // 0x8018817C: slti        $at, $a0, 0xAB
    ctx->r1 = SIGNED(ctx->r4) < 0XAB ? 1 : 0;
    // 0x80188180: bne         $at, $zero, L_801881A4
    if (ctx->r1 != 0) {
        // 0x80188184: slti        $at, $a0, 0x118
        ctx->r1 = SIGNED(ctx->r4) < 0X118 ? 1 : 0;
            goto L_801881A4;
    }
L_80188184:
    // 0x80188184: slti        $at, $a0, 0x118
    ctx->r1 = SIGNED(ctx->r4) < 0X118 ? 1 : 0;
    // 0x80188188: bne         $at, $zero, L_80188194
    if (ctx->r1 != 0) {
        // 0x8018818C: slti        $at, $a0, 0x12D
        ctx->r1 = SIGNED(ctx->r4) < 0X12D ? 1 : 0;
            goto L_80188194;
    }
    // 0x8018818C: slti        $at, $a0, 0x12D
    ctx->r1 = SIGNED(ctx->r4) < 0X12D ? 1 : 0;
    // 0x80188190: bne         $at, $zero, L_801881A4
    if (ctx->r1 != 0) {
        // 0x80188194: slti        $at, $a0, 0x154
        ctx->r1 = SIGNED(ctx->r4) < 0X154 ? 1 : 0;
            goto L_801881A4;
    }
L_80188194:
    // 0x80188194: slti        $at, $a0, 0x154
    ctx->r1 = SIGNED(ctx->r4) < 0X154 ? 1 : 0;
    // 0x80188198: bne         $at, $zero, L_80188224
    if (ctx->r1 != 0) {
        // 0x8018819C: slti        $at, $a0, 0x169
        ctx->r1 = SIGNED(ctx->r4) < 0X169 ? 1 : 0;
            goto L_80188224;
    }
    // 0x8018819C: slti        $at, $a0, 0x169
    ctx->r1 = SIGNED(ctx->r4) < 0X169 ? 1 : 0;
    // 0x801881A0: beq         $at, $zero, L_80188224
    if (ctx->r1 == 0) {
        // 0x801881A4: lui         $at, 0x8019
        ctx->r1 = S32(0X8019 << 16);
            goto L_80188224;
    }
L_801881A4:
    // 0x801881A4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801881A8: lwc1        $f6, 0x6478($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6478);
    // 0x801881AC: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x801881B0: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x801881B4: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801881B8: addiu       $a0, $a0, 0x7450
    ctx->r4 = ADD32(ctx->r4, 0X7450);
    // 0x801881BC: lui         $a1, 0x4220
    ctx->r5 = S32(0X4220 << 16);
    // 0x801881C0: lui         $a3, 0x447A
    ctx->r7 = S32(0X447A << 16);
    // 0x801881C4: jal         0x8009BC2C
    // 0x801881C8: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_1;
    // 0x801881C8: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x801881CC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801881D0: lwc1        $f8, 0x647C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X647C);
    // 0x801881D4: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x801881D8: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x801881DC: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801881E0: addiu       $a0, $a0, 0x7454
    ctx->r4 = ADD32(ctx->r4, 0X7454);
    // 0x801881E4: lui         $a1, 0x4120
    ctx->r5 = S32(0X4120 << 16);
    // 0x801881E8: lui         $a3, 0x447A
    ctx->r7 = S32(0X447A << 16);
    // 0x801881EC: jal         0x8009BC2C
    // 0x801881F0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_2;
    // 0x801881F0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x801881F4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801881F8: lwc1        $f10, 0x6480($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6480);
    // 0x801881FC: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x80188200: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x80188204: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80188208: addiu       $a0, $a0, 0x749C
    ctx->r4 = ADD32(ctx->r4, 0X749C);
    // 0x8018820C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80188210: lui         $a3, 0x447A
    ctx->r7 = S32(0X447A << 16);
    // 0x80188214: jal         0x8009BC2C
    // 0x80188218: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_3;
    // 0x80188218: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_3:
    // 0x8018821C: b           L_80188384
    // 0x80188220: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80188384;
    // 0x80188220: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80188224:
    // 0x80188224: bne         $s0, $t0, L_80188264
    if (ctx->r16 != ctx->r8) {
        // 0x80188228: slti        $at, $a0, 0xC8
        ctx->r1 = SIGNED(ctx->r4) < 0XC8 ? 1 : 0;
            goto L_80188264;
    }
    // 0x80188228: slti        $at, $a0, 0xC8
    ctx->r1 = SIGNED(ctx->r4) < 0XC8 ? 1 : 0;
    // 0x8018822C: bne         $at, $zero, L_80188264
    if (ctx->r1 != 0) {
        // 0x80188230: slti        $at, $a0, 0x105
        ctx->r1 = SIGNED(ctx->r4) < 0X105 ? 1 : 0;
            goto L_80188264;
    }
    // 0x80188230: slti        $at, $a0, 0x105
    ctx->r1 = SIGNED(ctx->r4) < 0X105 ? 1 : 0;
    // 0x80188234: beq         $at, $zero, L_80188264
    if (ctx->r1 == 0) {
        // 0x80188238: lui         $a1, 0x4270
        ctx->r5 = S32(0X4270 << 16);
            goto L_80188264;
    }
    // 0x80188238: lui         $a1, 0x4270
    ctx->r5 = S32(0X4270 << 16);
    // 0x8018823C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80188240: lwc1        $f0, 0x6484($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6484);
    // 0x80188244: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x80188248: addiu       $a0, $a0, 0x7450
    ctx->r4 = ADD32(ctx->r4, 0X7450);
    // 0x8018824C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80188250: lui         $a3, 0x447A
    ctx->r7 = S32(0X447A << 16);
    // 0x80188254: jal         0x8009BC2C
    // 0x80188258: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_4;
    // 0x80188258: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_4:
    // 0x8018825C: b           L_80188384
    // 0x80188260: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80188384;
    // 0x80188260: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80188264:
    // 0x80188264: bne         $s0, $t0, L_80188278
    if (ctx->r16 != ctx->r8) {
        // 0x80188268: slti        $at, $a0, 0xAA
        ctx->r1 = SIGNED(ctx->r4) < 0XAA ? 1 : 0;
            goto L_80188278;
    }
    // 0x80188268: slti        $at, $a0, 0xAA
    ctx->r1 = SIGNED(ctx->r4) < 0XAA ? 1 : 0;
    // 0x8018826C: bne         $at, $zero, L_80188278
    if (ctx->r1 != 0) {
        // 0x80188270: slti        $at, $a0, 0xBF
        ctx->r1 = SIGNED(ctx->r4) < 0XBF ? 1 : 0;
            goto L_80188278;
    }
    // 0x80188270: slti        $at, $a0, 0xBF
    ctx->r1 = SIGNED(ctx->r4) < 0XBF ? 1 : 0;
    // 0x80188274: bne         $at, $zero, L_8018828C
    if (ctx->r1 != 0) {
        // 0x80188278: slti        $at, $a0, 0x12C
        ctx->r1 = SIGNED(ctx->r4) < 0X12C ? 1 : 0;
            goto L_8018828C;
    }
L_80188278:
    // 0x80188278: slti        $at, $a0, 0x12C
    ctx->r1 = SIGNED(ctx->r4) < 0X12C ? 1 : 0;
    // 0x8018827C: bne         $at, $zero, L_8018830C
    if (ctx->r1 != 0) {
        // 0x80188280: addiu       $a1, $zero, 0x0
        ctx->r5 = ADD32(0, 0X0);
            goto L_8018830C;
    }
    // 0x80188280: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80188284: slti        $at, $a0, 0x141
    ctx->r1 = SIGNED(ctx->r4) < 0X141 ? 1 : 0;
    // 0x80188288: beq         $at, $zero, L_8018830C
    if (ctx->r1 == 0) {
        // 0x8018828C: lui         $at, 0x8019
        ctx->r1 = S32(0X8019 << 16);
            goto L_8018830C;
    }
L_8018828C:
    // 0x8018828C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80188290: lwc1        $f16, 0x6488($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6488);
    // 0x80188294: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x80188298: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x8018829C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801882A0: addiu       $a0, $a0, 0x7450
    ctx->r4 = ADD32(ctx->r4, 0X7450);
    // 0x801882A4: lui         $a1, 0xC220
    ctx->r5 = S32(0XC220 << 16);
    // 0x801882A8: lui         $a3, 0x447A
    ctx->r7 = S32(0X447A << 16);
    // 0x801882AC: jal         0x8009BC2C
    // 0x801882B0: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_5;
    // 0x801882B0: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_5:
    // 0x801882B4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801882B8: lwc1        $f18, 0x648C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X648C);
    // 0x801882BC: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x801882C0: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x801882C4: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801882C8: addiu       $a0, $a0, 0x7454
    ctx->r4 = ADD32(ctx->r4, 0X7454);
    // 0x801882CC: lui         $a1, 0x4120
    ctx->r5 = S32(0X4120 << 16);
    // 0x801882D0: lui         $a3, 0x447A
    ctx->r7 = S32(0X447A << 16);
    // 0x801882D4: jal         0x8009BC2C
    // 0x801882D8: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_6;
    // 0x801882D8: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_6:
    // 0x801882DC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801882E0: lwc1        $f4, 0x6490($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6490);
    // 0x801882E4: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x801882E8: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x801882EC: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801882F0: addiu       $a0, $a0, 0x749C
    ctx->r4 = ADD32(ctx->r4, 0X749C);
    // 0x801882F4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x801882F8: lui         $a3, 0x447A
    ctx->r7 = S32(0X447A << 16);
    // 0x801882FC: jal         0x8009BC2C
    // 0x80188300: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_7;
    // 0x80188300: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_7:
    // 0x80188304: b           L_80188384
    // 0x80188308: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80188384;
    // 0x80188308: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8018830C:
    // 0x8018830C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80188310: lwc1        $f6, 0x6494($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6494);
    // 0x80188314: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x80188318: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x8018831C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80188320: addiu       $a0, $a0, 0x7450
    ctx->r4 = ADD32(ctx->r4, 0X7450);
    // 0x80188324: lui         $a3, 0x447A
    ctx->r7 = S32(0X447A << 16);
    // 0x80188328: jal         0x8009BC2C
    // 0x8018832C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_8;
    // 0x8018832C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_8:
    // 0x80188330: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80188334: lwc1        $f8, 0x6498($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6498);
    // 0x80188338: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018833C: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x80188340: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80188344: addiu       $a0, $a0, 0x7454
    ctx->r4 = ADD32(ctx->r4, 0X7454);
    // 0x80188348: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8018834C: lui         $a3, 0x447A
    ctx->r7 = S32(0X447A << 16);
    // 0x80188350: jal         0x8009BC2C
    // 0x80188354: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_9;
    // 0x80188354: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_9:
    // 0x80188358: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018835C: lwc1        $f10, 0x649C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X649C);
    // 0x80188360: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x80188364: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x80188368: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8018836C: addiu       $a0, $a0, 0x749C
    ctx->r4 = ADD32(ctx->r4, 0X749C);
    // 0x80188370: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80188374: lui         $a3, 0x447A
    ctx->r7 = S32(0X447A << 16);
    // 0x80188378: jal         0x8009BC2C
    // 0x8018837C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_10;
    // 0x8018837C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_10:
    // 0x80188380: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80188384:
    // 0x80188384: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80188388: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8018838C: jr          $ra
    // 0x80188390: nop

    return;
    // 0x80188390: nop

;}
RECOMP_FUNC void Ending_8018D2C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D2C8: lw          $v1, 0xC($a1)
    ctx->r3 = MEM_W(ctx->r5, 0XC);
    // 0x8018D2CC: lh          $a2, 0x64($a1)
    ctx->r6 = MEM_H(ctx->r5, 0X64);
    // 0x8018D2D0: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8018D2D4: addu        $t6, $v1, $a2
    ctx->r14 = ADD32(ctx->r3, ctx->r6);
    // 0x8018D2D8: sltu        $at, $a0, $t6
    ctx->r1 = ctx->r4 < ctx->r14 ? 1 : 0;
    // 0x8018D2DC: beql        $at, $zero, L_8018D310
    if (ctx->r1 == 0) {
        // 0x8018D2E0: lw          $t0, 0x10($a1)
        ctx->r8 = MEM_W(ctx->r5, 0X10);
            goto L_8018D310;
    }
    goto skip_0;
    // 0x8018D2E0: lw          $t0, 0x10($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X10);
    skip_0:
    // 0x8018D2E4: subu        $t7, $a0, $v1
    ctx->r15 = SUB32(ctx->r4, ctx->r3);
    // 0x8018D2E8: sll         $t8, $t7, 8
    ctx->r24 = S32(ctx->r15 << 8);
    // 0x8018D2EC: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8018D2F0: divu        $zero, $t8, $a2
    lo = S32(U32(ctx->r24) / U32(ctx->r6)); hi = S32(U32(ctx->r24) % U32(ctx->r6));
    // 0x8018D2F4: mflo        $v0
    ctx->r2 = lo;
    // 0x8018D2F8: andi        $t9, $v0, 0xFF
    ctx->r25 = ctx->r2 & 0XFF;
    // 0x8018D2FC: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x8018D300: bne         $a2, $zero, L_8018D30C
    if (ctx->r6 != 0) {
        // 0x8018D304: nop
    
            goto L_8018D30C;
    }
    // 0x8018D304: nop

    // 0x8018D308: break       7
    do_break(2149110536);
L_8018D30C:
    // 0x8018D30C: lw          $t0, 0x10($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X10);
L_8018D310:
    // 0x8018D310: lh          $a3, 0x66($a1)
    ctx->r7 = MEM_H(ctx->r5, 0X66);
    // 0x8018D314: addu        $a2, $v1, $t0
    ctx->r6 = ADD32(ctx->r3, ctx->r8);
    // 0x8018D318: subu        $t1, $a2, $a3
    ctx->r9 = SUB32(ctx->r6, ctx->r7);
    // 0x8018D31C: sltu        $at, $t1, $a0
    ctx->r1 = ctx->r9 < ctx->r4 ? 1 : 0;
    // 0x8018D320: beq         $at, $zero, L_8018D350
    if (ctx->r1 == 0) {
        // 0x8018D324: subu        $t2, $a2, $a0
        ctx->r10 = SUB32(ctx->r6, ctx->r4);
            goto L_8018D350;
    }
    // 0x8018D324: subu        $t2, $a2, $a0
    ctx->r10 = SUB32(ctx->r6, ctx->r4);
    // 0x8018D328: sll         $t3, $t2, 8
    ctx->r11 = S32(ctx->r10 << 8);
    // 0x8018D32C: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x8018D330: addiu       $t4, $t3, -0xFF
    ctx->r12 = ADD32(ctx->r11, -0XFF);
    // 0x8018D334: divu        $zero, $t4, $a3
    lo = S32(U32(ctx->r12) / U32(ctx->r7)); hi = S32(U32(ctx->r12) % U32(ctx->r7));
    // 0x8018D338: mflo        $v0
    ctx->r2 = lo;
    // 0x8018D33C: andi        $t5, $v0, 0xFF
    ctx->r13 = ctx->r2 & 0XFF;
    // 0x8018D340: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
    // 0x8018D344: bne         $a3, $zero, L_8018D350
    if (ctx->r7 != 0) {
        // 0x8018D348: nop
    
            goto L_8018D350;
    }
    // 0x8018D348: nop

    // 0x8018D34C: break       7
    do_break(2149110604);
L_8018D350:
    // 0x8018D350: lbu         $t6, 0x6C($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X6C);
    // 0x8018D354: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018D358: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x8018D35C: sw          $t6, -0x7CB8($at)
    MEM_W(-0X7CB8, ctx->r1) = ctx->r14;
    // 0x8018D360: lbu         $t7, 0x6D($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X6D);
    // 0x8018D364: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018D368: addiu       $v1, $v1, -0x7CA8
    ctx->r3 = ADD32(ctx->r3, -0X7CA8);
    // 0x8018D36C: sw          $t7, -0x7CB0($at)
    MEM_W(-0X7CB0, ctx->r1) = ctx->r15;
    // 0x8018D370: lbu         $t8, 0x6E($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X6E);
    // 0x8018D374: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018D378: sw          $t8, -0x7CAC($at)
    MEM_W(-0X7CAC, ctx->r1) = ctx->r24;
    // 0x8018D37C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8018D380: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018D384: sw          $v0, -0x7CC0($at)
    MEM_W(-0X7CC0, ctx->r1) = ctx->r2;
    // 0x8018D388: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018D38C: sw          $zero, -0x7CA4($at)
    MEM_W(-0X7CA4, ctx->r1) = 0;
    // 0x8018D390: jr          $ra
    // 0x8018D394: nop

    return;
    // 0x8018D394: nop

;}
RECOMP_FUNC void Ending_Floor_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018EDB8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8018EDBC: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8018EDC0: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x8018EDC4: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8018EDC8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8018EDCC: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8018EDD0: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8018EDD4: addiu       $s1, $s1, 0x7E64
    ctx->r17 = ADD32(ctx->r17, 0X7E64);
    // 0x8018EDD8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8018EDDC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018EDE0: sw          $zero, -0x7BF0($at)
    MEM_W(-0X7BF0, ctx->r1) = 0;
    // 0x8018EDE4: lh          $a1, 0x8($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X8);
    // 0x8018EDE8: jal         0x800B8DD0
    // 0x8018EDEC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x8018EDEC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x8018EDF0: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8018EDF4: lui         $t7, 0xBC00
    ctx->r15 = S32(0XBC00 << 16);
    // 0x8018EDF8: ori         $t7, $t7, 0x8
    ctx->r15 = ctx->r15 | 0X8;
    // 0x8018EDFC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8018EE00: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x8018EE04: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8018EE08: lh          $t8, 0x66($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X66);
    // 0x8018EE0C: lh          $t0, 0x64($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X64);
    // 0x8018EE10: lui         $t9, 0x1
    ctx->r25 = S32(0X1 << 16);
    // 0x8018EE14: ori         $t9, $t9, 0xF400
    ctx->r25 = ctx->r25 | 0XF400;
    // 0x8018EE18: subu        $t1, $t8, $t0
    ctx->r9 = SUB32(ctx->r24, ctx->r8);
    // 0x8018EE1C: div         $zero, $t9, $t1
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r9))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r9)));
    // 0x8018EE20: mflo        $t7
    ctx->r15 = lo;
    // 0x8018EE24: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x8018EE28: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8018EE2C: bne         $t1, $zero, L_8018EE38
    if (ctx->r9 != 0) {
        // 0x8018EE30: nop
    
            goto L_8018EE38;
    }
    // 0x8018EE30: nop

    // 0x8018EE34: break       7
    do_break(2149117492);
L_8018EE38:
    // 0x8018EE38: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8018EE3C: bne         $t1, $at, L_8018EE50
    if (ctx->r9 != ctx->r1) {
        // 0x8018EE40: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8018EE50;
    }
    // 0x8018EE40: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8018EE44: bne         $t9, $at, L_8018EE50
    if (ctx->r25 != ctx->r1) {
        // 0x8018EE48: nop
    
            goto L_8018EE50;
    }
    // 0x8018EE48: nop

    // 0x8018EE4C: break       6
    do_break(2149117516);
L_8018EE50:
    // 0x8018EE50: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8018EE54: negu        $t9, $t0
    ctx->r25 = SUB32(0, ctx->r8);
    // 0x8018EE58: sll         $t6, $t9, 8
    ctx->r14 = S32(ctx->r25 << 8);
    // 0x8018EE5C: ori         $at, $at, 0xF400
    ctx->r1 = ctx->r1 | 0XF400;
    // 0x8018EE60: addu        $t7, $t6, $at
    ctx->r15 = ADD32(ctx->r14, ctx->r1);
    // 0x8018EE64: div         $zero, $t7, $t1
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r9))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r9)));
    // 0x8018EE68: mflo        $t9
    ctx->r25 = lo;
    // 0x8018EE6C: andi        $t6, $t9, 0xFFFF
    ctx->r14 = ctx->r25 & 0XFFFF;
    // 0x8018EE70: bne         $t1, $zero, L_8018EE7C
    if (ctx->r9 != 0) {
        // 0x8018EE74: nop
    
            goto L_8018EE7C;
    }
    // 0x8018EE74: nop

    // 0x8018EE78: break       7
    do_break(2149117560);
L_8018EE7C:
    // 0x8018EE7C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8018EE80: bne         $t1, $at, L_8018EE94
    if (ctx->r9 != ctx->r1) {
        // 0x8018EE84: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8018EE94;
    }
    // 0x8018EE84: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8018EE88: bne         $t7, $at, L_8018EE94
    if (ctx->r15 != ctx->r1) {
        // 0x8018EE8C: nop
    
            goto L_8018EE94;
    }
    // 0x8018EE8C: nop

    // 0x8018EE90: break       6
    do_break(2149117584);
L_8018EE94:
    // 0x8018EE94: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x8018EE98: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8018EE9C: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8018EEA0: lui         $t8, 0xF800
    ctx->r24 = S32(0XF800 << 16);
    // 0x8018EEA4: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8018EEA8: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x8018EEAC: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8018EEB0: lbu         $t7, 0x60($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X60);
    // 0x8018EEB4: lbu         $t6, 0x61($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X61);
    // 0x8018EEB8: sll         $t9, $t7, 24
    ctx->r25 = S32(ctx->r15 << 24);
    // 0x8018EEBC: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x8018EEC0: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x8018EEC4: lbu         $t9, 0x62($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X62);
    // 0x8018EEC8: sll         $t7, $t9, 8
    ctx->r15 = S32(ctx->r25 << 8);
    // 0x8018EECC: or          $t6, $t8, $t7
    ctx->r14 = ctx->r24 | ctx->r15;
    // 0x8018EED0: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8018EED4: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8018EED8: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x8018EEDC: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8018EEE0: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x8018EEE4: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8018EEE8: lbu         $t6, 0x6C($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X6C);
    // 0x8018EEEC: lbu         $t7, 0x6D($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X6D);
    // 0x8018EEF0: sll         $t9, $t6, 24
    ctx->r25 = S32(ctx->r14 << 24);
    // 0x8018EEF4: sll         $t6, $t7, 16
    ctx->r14 = S32(ctx->r15 << 16);
    // 0x8018EEF8: or          $t8, $t9, $t6
    ctx->r24 = ctx->r25 | ctx->r14;
    // 0x8018EEFC: lbu         $t9, 0x6E($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X6E);
    // 0x8018EF00: sll         $t6, $t9, 8
    ctx->r14 = S32(ctx->r25 << 8);
    // 0x8018EF04: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x8018EF08: lbu         $t8, 0x6F($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X6F);
    // 0x8018EF0C: or          $t6, $t7, $t8
    ctx->r14 = ctx->r15 | ctx->r24;
    // 0x8018EF10: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8018EF14: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    // 0x8018EF18: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018EF1C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8018EF20: subu        $t7, $s2, $t9
    ctx->r15 = SUB32(ctx->r18, ctx->r25);
    // 0x8018EF24: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8018EF28: bgez        $t7, L_8018EF40
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8018EF2C: cvt.s.w     $f0, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8018EF40;
    }
    // 0x8018EF2C: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8018EF30: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8018EF34: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018EF38: nop

    // 0x8018EF3C: add.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f6.fl;
L_8018EF40:
    // 0x8018EF40: lwc1        $f10, 0x3C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x8018EF44: lwc1        $f8, 0x18($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8018EF48: lwc1        $f6, 0x40($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8018EF4C: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8018EF50: lwc1        $f4, 0x1C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x8018EF54: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8018EF58: mul.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8018EF5C: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x8018EF60: lwc1        $f16, 0x20($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X20);
    // 0x8018EF64: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8018EF68: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8018EF6C: lwc1        $f18, 0x44($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X44);
    // 0x8018EF70: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8018EF74: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x8018EF78: mul.s       $f6, $f0, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x8018EF7C: add.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x8018EF80: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x8018EF84: jal         0x80005B00
    // 0x8018EF88: nop

    Matrix_Translate(rdram, ctx);
        goto after_1;
    // 0x8018EF88: nop

    after_1:
    // 0x8018EF8C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018EF90: lw          $a1, 0x30($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X30);
    // 0x8018EF94: lw          $a2, 0x34($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X34);
    // 0x8018EF98: lw          $a3, 0x38($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X38);
    // 0x8018EF9C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8018EFA0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8018EFA4: jal         0x80005C34
    // 0x8018EFA8: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Scale(rdram, ctx);
        goto after_2;
    // 0x8018EFA8: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_2:
    // 0x8018EFAC: mtc1        $s2, $f10
    ctx->f10.u32l = ctx->r18;
    // 0x8018EFB0: bgez        $s2, L_8018EFC8
    if (SIGNED(ctx->r18) >= 0) {
        // 0x8018EFB4: cvt.s.w     $f8, $f10
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
            goto L_8018EFC8;
    }
    // 0x8018EFB4: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8018EFB8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8018EFBC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8018EFC0: nop

    // 0x8018EFC4: add.s       $f8, $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f18.fl;
L_8018EFC8:
    // 0x8018EFC8: lbu         $t9, 0x70($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X70);
    // 0x8018EFCC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018EFD0: lwc1        $f16, 0x6BFC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6BFC);
    // 0x8018EFD4: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x8018EFD8: mul.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8018EFDC: bgez        $t9, L_8018EFF4
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8018EFE0: cvt.s.w     $f10, $f4
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8018EFF4;
    }
    // 0x8018EFE0: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8018EFE4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8018EFE8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8018EFEC: nop

    // 0x8018EFF0: add.s       $f10, $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f18.fl;
L_8018EFF4:
    // 0x8018EFF4: jal         0x80023090
    // 0x8018EFF8: add.s       $f12, $f6, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f10.fl;
    __sinf_recomp(rdram, ctx);
        goto after_3;
    // 0x8018EFF8: add.s       $f12, $f6, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f10.fl;
    after_3:
    // 0x8018EFFC: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x8018F000: lwc1        $f16, 0x58($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X58);
    // 0x8018F004: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x8018F008: lwc1        $f8, 0x28($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X28);
    // 0x8018F00C: mul.s       $f4, $f0, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x8018F010: subu        $t8, $s2, $t7
    ctx->r24 = SUB32(ctx->r18, ctx->r15);
    // 0x8018F014: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x8018F018: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018F01C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8018F020: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8018F024: bgez        $t8, L_8018F03C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8018F028: add.s       $f18, $f8, $f4
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f4.fl;
            goto L_8018F03C;
    }
    // 0x8018F028: add.s       $f18, $f8, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x8018F02C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8018F030: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8018F034: nop

    // 0x8018F038: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_8018F03C:
    // 0x8018F03C: lwc1        $f8, 0x4C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x8018F040: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018F044: lwc1        $f16, 0x6C00($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6C00);
    // 0x8018F048: mul.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x8018F04C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018F050: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8018F054: mul.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x8018F058: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8018F05C: jal         0x80005E90
    // 0x8018F060: nop

    Matrix_RotateY(rdram, ctx);
        goto after_4;
    // 0x8018F060: nop

    after_4:
    // 0x8018F064: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8018F068: lwc1        $f18, 0x54($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X54);
    // 0x8018F06C: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x8018F070: lwc1        $f6, 0x24($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8018F074: mul.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x8018F078: subu        $t9, $s2, $t6
    ctx->r25 = SUB32(ctx->r18, ctx->r14);
    // 0x8018F07C: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x8018F080: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018F084: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8018F088: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8018F08C: bgez        $t9, L_8018F0A4
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8018F090: add.s       $f16, $f6, $f4
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f4.fl;
            goto L_8018F0A4;
    }
    // 0x8018F090: add.s       $f16, $f6, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8018F094: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8018F098: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8018F09C: nop

    // 0x8018F0A0: add.s       $f8, $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f18.fl;
L_8018F0A4:
    // 0x8018F0A4: lwc1        $f6, 0x48($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X48);
    // 0x8018F0A8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018F0AC: lwc1        $f18, 0x6C04($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6C04);
    // 0x8018F0B0: mul.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8018F0B4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018F0B8: add.s       $f10, $f16, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x8018F0BC: mul.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8018F0C0: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8018F0C4: jal         0x80005D44
    // 0x8018F0C8: nop

    Matrix_RotateX(rdram, ctx);
        goto after_5;
    // 0x8018F0C8: nop

    after_5:
    // 0x8018F0CC: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8018F0D0: lwc1        $f16, 0x5C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X5C);
    // 0x8018F0D4: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x8018F0D8: lwc1        $f10, 0x2C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8018F0DC: mul.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x8018F0E0: subu        $t8, $s2, $t7
    ctx->r24 = SUB32(ctx->r18, ctx->r15);
    // 0x8018F0E4: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x8018F0E8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018F0EC: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8018F0F0: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8018F0F4: bgez        $t8, L_8018F10C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8018F0F8: add.s       $f18, $f10, $f4
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f4.fl;
            goto L_8018F10C;
    }
    // 0x8018F0F8: add.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8018F0FC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8018F100: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8018F104: nop

    // 0x8018F108: add.s       $f6, $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f16.fl;
L_8018F10C:
    // 0x8018F10C: lwc1        $f10, 0x50($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X50);
    // 0x8018F110: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018F114: lwc1        $f16, 0x6C08($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6C08);
    // 0x8018F118: mul.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8018F11C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018F120: add.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8018F124: mul.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8018F128: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8018F12C: jal         0x80005FE0
    // 0x8018F130: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_6;
    // 0x8018F130: nop

    after_6:
    // 0x8018F134: jal         0x80006EB8
    // 0x8018F138: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_7;
    // 0x8018F138: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_7:
    // 0x8018F13C: lui         $t5, 0xF510
    ctx->r13 = S32(0XF510 << 16);
    // 0x8018F140: lui         $ra, 0x1
    ctx->r31 = S32(0X1 << 16);
    // 0x8018F144: ori         $ra, $ra, 0x4050
    ctx->r31 = ctx->r31 | 0X4050;
    // 0x8018F148: ori         $t5, $t5, 0x1000
    ctx->r13 = ctx->r13 | 0X1000;
    // 0x8018F14C: lui         $s0, 0xF200
    ctx->r16 = S32(0XF200 << 16);
    // 0x8018F150: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8018F154: lui         $t7, 0x701
    ctx->r15 = S32(0X701 << 16);
    // 0x8018F158: addiu       $t7, $t7, -0x15C8
    ctx->r15 = ADD32(ctx->r15, -0X15C8);
    // 0x8018F15C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8018F160: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x8018F164: lui         $t9, 0xFD10
    ctx->r25 = S32(0XFD10 << 16);
    // 0x8018F168: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8018F16C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8018F170: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8018F174: lui         $t9, 0x701
    ctx->r25 = S32(0X701 << 16);
    // 0x8018F178: ori         $t9, $t9, 0x4050
    ctx->r25 = ctx->r25 | 0X4050;
    // 0x8018F17C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8018F180: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x8018F184: lui         $t6, 0xF510
    ctx->r14 = S32(0XF510 << 16);
    // 0x8018F188: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8018F18C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8018F190: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8018F194: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x8018F198: lui         $t9, 0xF300
    ctx->r25 = S32(0XF300 << 16);
    // 0x8018F19C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8018F1A0: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x8018F1A4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8018F1A8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8018F1AC: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8018F1B0: lui         $t7, 0x73F
    ctx->r15 = S32(0X73F << 16);
    // 0x8018F1B4: ori         $t7, $t7, 0xF100
    ctx->r15 = ctx->r15 | 0XF100;
    // 0x8018F1B8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8018F1BC: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x8018F1C0: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8018F1C4: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8018F1C8: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8018F1CC: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x8018F1D0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8018F1D4: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x8018F1D8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8018F1DC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8018F1E0: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8018F1E4: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8018F1E8: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x8018F1EC: sw          $ra, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r31;
    // 0x8018F1F0: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8018F1F4: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8018F1F8: lui         $t8, 0x7
    ctx->r24 = S32(0X7 << 16);
    // 0x8018F1FC: ori         $t8, $t8, 0xC07C
    ctx->r24 = ctx->r24 | 0XC07C;
    // 0x8018F200: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8018F204: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x8018F208: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8018F20C: sw          $s0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r16;
    // 0x8018F210: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8018F214: lui         $t9, 0xE800
    ctx->r25 = S32(0XE800 << 16);
    // 0x8018F218: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8018F21C: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x8018F220: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8018F224: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8018F228: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8018F22C: sll         $t6, $s2, 3
    ctx->r14 = S32(ctx->r18 << 3);
    // 0x8018F230: subu        $t6, $t6, $s2
    ctx->r14 = SUB32(ctx->r14, ctx->r18);
    // 0x8018F234: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8018F238: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x8018F23C: sw          $ra, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r31;
    // 0x8018F240: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8018F244: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8018F248: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x8018F24C: andi        $t9, $t6, 0xFFF
    ctx->r25 = ctx->r14 & 0XFFF;
    // 0x8018F250: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8018F254: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x8018F258: sll         $t7, $t9, 12
    ctx->r15 = S32(ctx->r25 << 12);
    // 0x8018F25C: lui         $t6, 0x7
    ctx->r14 = S32(0X7 << 16);
    // 0x8018F260: ori         $t6, $t6, 0xC07C
    ctx->r14 = ctx->r14 | 0XC07C;
    // 0x8018F264: or          $t8, $t7, $s0
    ctx->r24 = ctx->r15 | ctx->r16;
    // 0x8018F268: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8018F26C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8018F270: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8018F274: lui         $t8, 0x701
    ctx->r24 = S32(0X701 << 16);
    // 0x8018F278: addiu       $t8, $t8, -0x1620
    ctx->r24 = ADD32(ctx->r24, -0X1620);
    // 0x8018F27C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8018F280: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x8018F284: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x8018F288: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8018F28C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8018F290: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8018F294: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8018F298: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8018F29C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8018F2A0: jr          $ra
    // 0x8018F2A4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8018F2A4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void Ending_80191C58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80191C58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80191C5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80191C60: lw          $t9, 0x4($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X4);
    // 0x80191C64: jalr        $t9
    // 0x80191C68: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80191C68: nop

    after_0:
    // 0x80191C6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80191C70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80191C74: jr          $ra
    // 0x80191C78: nop

    return;
    // 0x80191C78: nop

;}
RECOMP_FUNC void Ending_IncomingMsg_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801886F4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x801886F8: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x801886FC: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80188700: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x80188704: lw          $t6, 0x1690($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1690);
    // 0x80188708: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8018870C: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x80188710: beq         $t6, $zero, L_801888E0
    if (ctx->r14 == 0) {
        // 0x80188714: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_801888E0;
    }
    // 0x80188714: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80188718: jal         0x800B8DD0
    // 0x8018871C: addiu       $a1, $zero, 0x4E
    ctx->r5 = ADD32(0, 0X4E);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x8018871C: addiu       $a1, $zero, 0x4E
    ctx->r5 = ADD32(0, 0X4E);
    after_0:
    // 0x80188720: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80188724: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x80188728: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x8018872C: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80188730: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80188734: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80188738: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8018873C: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x80188740: lw          $a0, 0x6F90($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6F90);
    // 0x80188744: bgez        $a0, L_80188758
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80188748: andi        $t0, $a0, 0x7
        ctx->r8 = ctx->r4 & 0X7;
            goto L_80188758;
    }
    // 0x80188748: andi        $t0, $a0, 0x7
    ctx->r8 = ctx->r4 & 0X7;
    // 0x8018874C: beq         $t0, $zero, L_80188758
    if (ctx->r8 == 0) {
        // 0x80188750: nop
    
            goto L_80188758;
    }
    // 0x80188750: nop

    // 0x80188754: addiu       $t0, $t0, -0x8
    ctx->r8 = ADD32(ctx->r8, -0X8);
L_80188758:
    // 0x80188758: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    // 0x8018875C: bgez        $a0, L_8018876C
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80188760: sra         $t1, $a0, 1
        ctx->r9 = S32(SIGNED(ctx->r4) >> 1);
            goto L_8018876C;
    }
    // 0x80188760: sra         $t1, $a0, 1
    ctx->r9 = S32(SIGNED(ctx->r4) >> 1);
    // 0x80188764: addiu       $at, $a0, 0x1
    ctx->r1 = ADD32(ctx->r4, 0X1);
    // 0x80188768: sra         $t1, $at, 1
    ctx->r9 = S32(SIGNED(ctx->r1) >> 1);
L_8018876C:
    // 0x8018876C: beq         $t1, $zero, L_80188890
    if (ctx->r9 == 0) {
        // 0x80188770: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80188890;
    }
    // 0x80188770: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80188774: beq         $t1, $at, L_80188838
    if (ctx->r9 == ctx->r1) {
        // 0x80188778: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80188838;
    }
    // 0x80188778: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8018877C: beq         $t1, $at, L_801887E0
    if (ctx->r9 == ctx->r1) {
        // 0x80188780: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_801887E0;
    }
    // 0x80188780: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80188784: bne         $t1, $at, L_801888E0
    if (ctx->r9 != ctx->r1) {
        // 0x80188788: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_801888E0;
    }
    // 0x80188788: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018878C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80188790: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80188794: lui         $at, 0x430E
    ctx->r1 = S32(0X430E << 16);
    // 0x80188798: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018879C: lui         $at, 0x41F8
    ctx->r1 = S32(0X41F8 << 16);
    // 0x801887A0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801887A4: lui         $at, 0x4190
    ctx->r1 = S32(0X4190 << 16);
    // 0x801887A8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801887AC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801887B0: lui         $a1, 0x701
    ctx->r5 = S32(0X701 << 16);
    // 0x801887B4: lui         $a2, 0x701
    ctx->r6 = S32(0X701 << 16);
    // 0x801887B8: addiu       $t2, $zero, 0x1A
    ctx->r10 = ADD32(0, 0X1A);
    // 0x801887BC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x801887C0: addiu       $a2, $a2, 0x11B0
    ctx->r6 = ADD32(ctx->r6, 0X11B0);
    // 0x801887C4: addiu       $a1, $a1, 0x10E0
    ctx->r5 = ADD32(ctx->r5, 0X10E0);
    // 0x801887C8: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x801887CC: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x801887D0: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x801887D4: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x801887D8: jal         0x8009C320
    // 0x801887DC: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    Lib_TextureRect_CI4(rdram, ctx);
        goto after_1;
    // 0x801887DC: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    after_1:
L_801887E0:
    // 0x801887E0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801887E4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801887E8: lui         $at, 0x430E
    ctx->r1 = S32(0X430E << 16);
    // 0x801887EC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801887F0: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x801887F4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801887F8: lui         $at, 0x4190
    ctx->r1 = S32(0X4190 << 16);
    // 0x801887FC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80188800: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80188804: lui         $a1, 0x701
    ctx->r5 = S32(0X701 << 16);
    // 0x80188808: lui         $a2, 0x701
    ctx->r6 = S32(0X701 << 16);
    // 0x8018880C: addiu       $t3, $zero, 0x1A
    ctx->r11 = ADD32(0, 0X1A);
    // 0x80188810: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80188814: addiu       $a2, $a2, 0x10C0
    ctx->r6 = ADD32(ctx->r6, 0X10C0);
    // 0x80188818: addiu       $a1, $a1, 0xFF0
    ctx->r5 = ADD32(ctx->r5, 0XFF0);
    // 0x8018881C: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x80188820: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80188824: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x80188828: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x8018882C: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x80188830: jal         0x8009C320
    // 0x80188834: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    Lib_TextureRect_CI4(rdram, ctx);
        goto after_2;
    // 0x80188834: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    after_2:
L_80188838:
    // 0x80188838: lui         $at, 0x430E
    ctx->r1 = S32(0X430E << 16);
    // 0x8018883C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80188840: lui         $at, 0x4190
    ctx->r1 = S32(0X4190 << 16);
    // 0x80188844: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80188848: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8018884C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80188850: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80188854: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80188858: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018885C: lui         $a1, 0x701
    ctx->r5 = S32(0X701 << 16);
    // 0x80188860: lui         $a2, 0x701
    ctx->r6 = S32(0X701 << 16);
    // 0x80188864: addiu       $t4, $zero, 0x1A
    ctx->r12 = ADD32(0, 0X1A);
    // 0x80188868: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8018886C: addiu       $a2, $a2, 0xFD0
    ctx->r6 = ADD32(ctx->r6, 0XFD0);
    // 0x80188870: addiu       $a1, $a1, 0xF00
    ctx->r5 = ADD32(ctx->r5, 0XF00);
    // 0x80188874: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x80188878: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018887C: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x80188880: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    // 0x80188884: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x80188888: jal         0x8009C320
    // 0x8018888C: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    Lib_TextureRect_CI4(rdram, ctx);
        goto after_3;
    // 0x8018888C: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    after_3:
L_80188890:
    // 0x80188890: lui         $at, 0x430E
    ctx->r1 = S32(0X430E << 16);
    // 0x80188894: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80188898: lui         $at, 0x4190
    ctx->r1 = S32(0X4190 << 16);
    // 0x8018889C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801888A0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801888A4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801888A8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801888AC: lui         $a1, 0x701
    ctx->r5 = S32(0X701 << 16);
    // 0x801888B0: lui         $a2, 0x701
    ctx->r6 = S32(0X701 << 16);
    // 0x801888B4: addiu       $t5, $zero, 0x1A
    ctx->r13 = ADD32(0, 0X1A);
    // 0x801888B8: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x801888BC: addiu       $a2, $a2, 0xEE0
    ctx->r6 = ADD32(ctx->r6, 0XEE0);
    // 0x801888C0: addiu       $a1, $a1, 0xE10
    ctx->r5 = ADD32(ctx->r5, 0XE10);
    // 0x801888C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801888C8: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x801888CC: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x801888D0: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x801888D4: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    // 0x801888D8: jal         0x8009C320
    // 0x801888DC: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    Lib_TextureRect_CI4(rdram, ctx);
        goto after_4;
    // 0x801888DC: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    after_4:
L_801888E0:
    // 0x801888E0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x801888E4: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x801888E8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x801888EC: jr          $ra
    // 0x801888F0: nop

    return;
    // 0x801888F0: nop

;}
RECOMP_FUNC void Ending_8018ABE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018ABE8: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8018ABEC: lhu         $v0, -0x2756($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X2756);
    // 0x8018ABF0: lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // 0x8018ABF4: addiu       $v1, $v1, -0x7A7C
    ctx->r3 = ADD32(ctx->r3, -0X7A7C);
    // 0x8018ABF8: andi        $t6, $v0, 0x2000
    ctx->r14 = ctx->r2 & 0X2000;
    // 0x8018ABFC: beq         $t6, $zero, L_8018AC10
    if (ctx->r14 == 0) {
        // 0x8018AC00: andi        $t0, $v0, 0x10
        ctx->r8 = ctx->r2 & 0X10;
            goto L_8018AC10;
    }
    // 0x8018AC00: andi        $t0, $v0, 0x10
    ctx->r8 = ctx->r2 & 0X10;
    // 0x8018AC04: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8018AC08: xori        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 ^ 0X1;
    // 0x8018AC0C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
L_8018AC10:
    // 0x8018AC10: lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // 0x8018AC14: addiu       $v1, $v1, -0x7A7C
    ctx->r3 = ADD32(ctx->r3, -0X7A7C);
    // 0x8018AC18: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8018AC1C: beq         $t9, $zero, L_8018B164
    if (ctx->r25 == 0) {
        // 0x8018AC20: nop
    
            goto L_8018B164;
    }
    // 0x8018AC20: nop

    // 0x8018AC24: beq         $t0, $zero, L_8018AC48
    if (ctx->r8 == 0) {
        // 0x8018AC28: lui         $v1, 0x801A
        ctx->r3 = S32(0X801A << 16);
            goto L_8018AC48;
    }
    // 0x8018AC28: lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // 0x8018AC2C: addiu       $v1, $v1, -0x7A78
    ctx->r3 = ADD32(ctx->r3, -0X7A78);
    // 0x8018AC30: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x8018AC34: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x8018AC38: slti        $at, $t2, 0x5
    ctx->r1 = SIGNED(ctx->r10) < 0X5 ? 1 : 0;
    // 0x8018AC3C: bne         $at, $zero, L_8018AC48
    if (ctx->r1 != 0) {
        // 0x8018AC40: sw          $t2, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r10;
            goto L_8018AC48;
    }
    // 0x8018AC40: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x8018AC44: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_8018AC48:
    // 0x8018AC48: lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // 0x8018AC4C: addiu       $v1, $v1, -0x7A78
    ctx->r3 = ADD32(ctx->r3, -0X7A78);
    // 0x8018AC50: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x8018AC54: sltiu       $at, $t4, 0x5
    ctx->r1 = ctx->r12 < 0X5 ? 1 : 0;
    // 0x8018AC58: beq         $at, $zero, L_8018B164
    if (ctx->r1 == 0) {
        // 0x8018AC5C: sll         $t4, $t4, 2
        ctx->r12 = S32(ctx->r12 << 2);
            goto L_8018B164;
    }
    // 0x8018AC5C: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8018AC60: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018AC64: addu        $at, $at, $t4
    gpr jr_addend_8018AC6C = ctx->r12;
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x8018AC68: lw          $t4, 0x65C8($at)
    ctx->r12 = ADD32(ctx->r1, 0X65C8);
    // 0x8018AC6C: jr          $t4
    // 0x8018AC70: nop

    switch (jr_addend_8018AC6C >> 2) {
        case 0: goto L_8018AC74; break;
        case 1: goto L_8018AD6C; break;
        case 2: goto L_8018AE64; break;
        case 3: goto L_8018AF5C; break;
        case 4: goto L_8018B0DC; break;
        default: switch_error(__func__, 0x8018AC6C, 0x801965C8);
    }
    // 0x8018AC70: nop

L_8018AC74:
    // 0x8018AC74: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8018AC78: lhu         $v0, -0x276E($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X276E);
    // 0x8018AC7C: andi        $t5, $v0, 0x4000
    ctx->r13 = ctx->r2 & 0X4000;
    // 0x8018AC80: beq         $t5, $zero, L_8018ACAC
    if (ctx->r13 == 0) {
        // 0x8018AC84: andi        $t9, $v0, 0x8000
        ctx->r25 = ctx->r2 & 0X8000;
            goto L_8018ACAC;
    }
    // 0x8018AC84: andi        $t9, $v0, 0x8000
    ctx->r25 = ctx->r2 & 0X8000;
    // 0x8018AC88: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x8018AC8C: addiu       $v1, $v1, -0x7CE0
    ctx->r3 = ADD32(ctx->r3, -0X7CE0);
    // 0x8018AC90: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8018AC94: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8018AC98: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8018AC9C: slti        $at, $t7, 0x100
    ctx->r1 = SIGNED(ctx->r15) < 0X100 ? 1 : 0;
    // 0x8018ACA0: bne         $at, $zero, L_8018ACAC
    if (ctx->r1 != 0) {
        // 0x8018ACA4: sw          $t7, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r15;
            goto L_8018ACAC;
    }
    // 0x8018ACA4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8018ACA8: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
L_8018ACAC:
    // 0x8018ACAC: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x8018ACB0: addiu       $v1, $v1, -0x7CE0
    ctx->r3 = ADD32(ctx->r3, -0X7CE0);
    // 0x8018ACB4: beq         $t9, $zero, L_8018ACD0
    if (ctx->r25 == 0) {
        // 0x8018ACB8: addiu       $a0, $zero, 0xFF
        ctx->r4 = ADD32(0, 0XFF);
            goto L_8018ACD0;
    }
    // 0x8018ACB8: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8018ACBC: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x8018ACC0: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x8018ACC4: bgez        $t1, L_8018ACD0
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8018ACC8: sw          $t1, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r9;
            goto L_8018ACD0;
    }
    // 0x8018ACC8: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x8018ACCC: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_8018ACD0:
    // 0x8018ACD0: andi        $t3, $v0, 0x2
    ctx->r11 = ctx->r2 & 0X2;
    // 0x8018ACD4: beq         $t3, $zero, L_8018ACFC
    if (ctx->r11 == 0) {
        // 0x8018ACD8: andi        $t7, $v0, 0x4
        ctx->r15 = ctx->r2 & 0X4;
            goto L_8018ACFC;
    }
    // 0x8018ACD8: andi        $t7, $v0, 0x4
    ctx->r15 = ctx->r2 & 0X4;
    // 0x8018ACDC: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x8018ACE0: addiu       $v1, $v1, -0x7CD8
    ctx->r3 = ADD32(ctx->r3, -0X7CD8);
    // 0x8018ACE4: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x8018ACE8: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8018ACEC: slti        $at, $t5, 0x100
    ctx->r1 = SIGNED(ctx->r13) < 0X100 ? 1 : 0;
    // 0x8018ACF0: bne         $at, $zero, L_8018ACFC
    if (ctx->r1 != 0) {
        // 0x8018ACF4: sw          $t5, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r13;
            goto L_8018ACFC;
    }
    // 0x8018ACF4: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x8018ACF8: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
L_8018ACFC:
    // 0x8018ACFC: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x8018AD00: beq         $t7, $zero, L_8018AD1C
    if (ctx->r15 == 0) {
        // 0x8018AD04: addiu       $v1, $v1, -0x7CD8
        ctx->r3 = ADD32(ctx->r3, -0X7CD8);
            goto L_8018AD1C;
    }
    // 0x8018AD04: addiu       $v1, $v1, -0x7CD8
    ctx->r3 = ADD32(ctx->r3, -0X7CD8);
    // 0x8018AD08: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8018AD0C: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x8018AD10: bgez        $t9, L_8018AD1C
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8018AD14: sw          $t9, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r25;
            goto L_8018AD1C;
    }
    // 0x8018AD14: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8018AD18: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_8018AD1C:
    // 0x8018AD1C: andi        $t1, $v0, 0x8
    ctx->r9 = ctx->r2 & 0X8;
    // 0x8018AD20: beq         $t1, $zero, L_8018AD48
    if (ctx->r9 == 0) {
        // 0x8018AD24: andi        $t5, $v0, 0x1
        ctx->r13 = ctx->r2 & 0X1;
            goto L_8018AD48;
    }
    // 0x8018AD24: andi        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 & 0X1;
    // 0x8018AD28: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x8018AD2C: addiu       $v1, $v1, -0x7CD0
    ctx->r3 = ADD32(ctx->r3, -0X7CD0);
    // 0x8018AD30: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x8018AD34: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8018AD38: slti        $at, $t3, 0x100
    ctx->r1 = SIGNED(ctx->r11) < 0X100 ? 1 : 0;
    // 0x8018AD3C: bne         $at, $zero, L_8018AD48
    if (ctx->r1 != 0) {
        // 0x8018AD40: sw          $t3, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r11;
            goto L_8018AD48;
    }
    // 0x8018AD40: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x8018AD44: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
L_8018AD48:
    // 0x8018AD48: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x8018AD4C: beq         $t5, $zero, L_8018B164
    if (ctx->r13 == 0) {
        // 0x8018AD50: addiu       $v1, $v1, -0x7CD0
        ctx->r3 = ADD32(ctx->r3, -0X7CD0);
            goto L_8018B164;
    }
    // 0x8018AD50: addiu       $v1, $v1, -0x7CD0
    ctx->r3 = ADD32(ctx->r3, -0X7CD0);
    // 0x8018AD54: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8018AD58: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8018AD5C: bgez        $t7, L_8018B164
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8018AD60: sw          $t7, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r15;
            goto L_8018B164;
    }
    // 0x8018AD60: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8018AD64: jr          $ra
    // 0x8018AD68: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    return;
    // 0x8018AD68: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_8018AD6C:
    // 0x8018AD6C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8018AD70: lhu         $v0, -0x276E($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X276E);
    // 0x8018AD74: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x8018AD78: addiu       $v1, $v1, -0x7AB8
    ctx->r3 = ADD32(ctx->r3, -0X7AB8);
    // 0x8018AD7C: andi        $t9, $v0, 0x4000
    ctx->r25 = ctx->r2 & 0X4000;
    // 0x8018AD80: beq         $t9, $zero, L_8018ADA4
    if (ctx->r25 == 0) {
        // 0x8018AD84: andi        $t3, $v0, 0x8000
        ctx->r11 = ctx->r2 & 0X8000;
            goto L_8018ADA4;
    }
    // 0x8018AD84: andi        $t3, $v0, 0x8000
    ctx->r11 = ctx->r2 & 0X8000;
    // 0x8018AD88: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x8018AD8C: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8018AD90: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8018AD94: slti        $at, $t1, 0x100
    ctx->r1 = SIGNED(ctx->r9) < 0X100 ? 1 : 0;
    // 0x8018AD98: bne         $at, $zero, L_8018ADA4
    if (ctx->r1 != 0) {
        // 0x8018AD9C: sw          $t1, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r9;
            goto L_8018ADA4;
    }
    // 0x8018AD9C: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x8018ADA0: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
L_8018ADA4:
    // 0x8018ADA4: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x8018ADA8: addiu       $v1, $v1, -0x7AB8
    ctx->r3 = ADD32(ctx->r3, -0X7AB8);
    // 0x8018ADAC: beq         $t3, $zero, L_8018ADC8
    if (ctx->r11 == 0) {
        // 0x8018ADB0: addiu       $a0, $zero, 0xFF
        ctx->r4 = ADD32(0, 0XFF);
            goto L_8018ADC8;
    }
    // 0x8018ADB0: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8018ADB4: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x8018ADB8: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x8018ADBC: bgez        $t5, L_8018ADC8
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8018ADC0: sw          $t5, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r13;
            goto L_8018ADC8;
    }
    // 0x8018ADC0: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x8018ADC4: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_8018ADC8:
    // 0x8018ADC8: andi        $t7, $v0, 0x2
    ctx->r15 = ctx->r2 & 0X2;
    // 0x8018ADCC: beq         $t7, $zero, L_8018ADF4
    if (ctx->r15 == 0) {
        // 0x8018ADD0: andi        $t1, $v0, 0x4
        ctx->r9 = ctx->r2 & 0X4;
            goto L_8018ADF4;
    }
    // 0x8018ADD0: andi        $t1, $v0, 0x4
    ctx->r9 = ctx->r2 & 0X4;
    // 0x8018ADD4: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x8018ADD8: addiu       $v1, $v1, -0x7AB4
    ctx->r3 = ADD32(ctx->r3, -0X7AB4);
    // 0x8018ADDC: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8018ADE0: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8018ADE4: slti        $at, $t9, 0x100
    ctx->r1 = SIGNED(ctx->r25) < 0X100 ? 1 : 0;
    // 0x8018ADE8: bne         $at, $zero, L_8018ADF4
    if (ctx->r1 != 0) {
        // 0x8018ADEC: sw          $t9, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r25;
            goto L_8018ADF4;
    }
    // 0x8018ADEC: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8018ADF0: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
L_8018ADF4:
    // 0x8018ADF4: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x8018ADF8: beq         $t1, $zero, L_8018AE14
    if (ctx->r9 == 0) {
        // 0x8018ADFC: addiu       $v1, $v1, -0x7AB4
        ctx->r3 = ADD32(ctx->r3, -0X7AB4);
            goto L_8018AE14;
    }
    // 0x8018ADFC: addiu       $v1, $v1, -0x7AB4
    ctx->r3 = ADD32(ctx->r3, -0X7AB4);
    // 0x8018AE00: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x8018AE04: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x8018AE08: bgez        $t3, L_8018AE14
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8018AE0C: sw          $t3, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r11;
            goto L_8018AE14;
    }
    // 0x8018AE0C: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x8018AE10: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_8018AE14:
    // 0x8018AE14: andi        $t5, $v0, 0x8
    ctx->r13 = ctx->r2 & 0X8;
    // 0x8018AE18: beq         $t5, $zero, L_8018AE40
    if (ctx->r13 == 0) {
        // 0x8018AE1C: andi        $t9, $v0, 0x1
        ctx->r25 = ctx->r2 & 0X1;
            goto L_8018AE40;
    }
    // 0x8018AE1C: andi        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 & 0X1;
    // 0x8018AE20: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x8018AE24: addiu       $v1, $v1, -0x7AB0
    ctx->r3 = ADD32(ctx->r3, -0X7AB0);
    // 0x8018AE28: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8018AE2C: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8018AE30: slti        $at, $t7, 0x100
    ctx->r1 = SIGNED(ctx->r15) < 0X100 ? 1 : 0;
    // 0x8018AE34: bne         $at, $zero, L_8018AE40
    if (ctx->r1 != 0) {
        // 0x8018AE38: sw          $t7, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r15;
            goto L_8018AE40;
    }
    // 0x8018AE38: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8018AE3C: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
L_8018AE40:
    // 0x8018AE40: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x8018AE44: beq         $t9, $zero, L_8018B164
    if (ctx->r25 == 0) {
        // 0x8018AE48: addiu       $v1, $v1, -0x7AB0
        ctx->r3 = ADD32(ctx->r3, -0X7AB0);
            goto L_8018B164;
    }
    // 0x8018AE48: addiu       $v1, $v1, -0x7AB0
    ctx->r3 = ADD32(ctx->r3, -0X7AB0);
    // 0x8018AE4C: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x8018AE50: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x8018AE54: bgez        $t1, L_8018B164
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8018AE58: sw          $t1, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r9;
            goto L_8018B164;
    }
    // 0x8018AE58: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x8018AE5C: jr          $ra
    // 0x8018AE60: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    return;
    // 0x8018AE60: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_8018AE64:
    // 0x8018AE64: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8018AE68: lhu         $v0, -0x276E($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X276E);
    // 0x8018AE6C: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x8018AE70: addiu       $v1, $v1, -0x7AAC
    ctx->r3 = ADD32(ctx->r3, -0X7AAC);
    // 0x8018AE74: andi        $t3, $v0, 0x4000
    ctx->r11 = ctx->r2 & 0X4000;
    // 0x8018AE78: beq         $t3, $zero, L_8018AE9C
    if (ctx->r11 == 0) {
        // 0x8018AE7C: andi        $t7, $v0, 0x8000
        ctx->r15 = ctx->r2 & 0X8000;
            goto L_8018AE9C;
    }
    // 0x8018AE7C: andi        $t7, $v0, 0x8000
    ctx->r15 = ctx->r2 & 0X8000;
    // 0x8018AE80: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x8018AE84: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8018AE88: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8018AE8C: slti        $at, $t5, 0x100
    ctx->r1 = SIGNED(ctx->r13) < 0X100 ? 1 : 0;
    // 0x8018AE90: bne         $at, $zero, L_8018AE9C
    if (ctx->r1 != 0) {
        // 0x8018AE94: sw          $t5, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r13;
            goto L_8018AE9C;
    }
    // 0x8018AE94: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x8018AE98: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
L_8018AE9C:
    // 0x8018AE9C: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x8018AEA0: addiu       $v1, $v1, -0x7AAC
    ctx->r3 = ADD32(ctx->r3, -0X7AAC);
    // 0x8018AEA4: beq         $t7, $zero, L_8018AEC0
    if (ctx->r15 == 0) {
        // 0x8018AEA8: addiu       $a0, $zero, 0xFF
        ctx->r4 = ADD32(0, 0XFF);
            goto L_8018AEC0;
    }
    // 0x8018AEA8: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8018AEAC: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8018AEB0: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x8018AEB4: bgez        $t9, L_8018AEC0
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8018AEB8: sw          $t9, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r25;
            goto L_8018AEC0;
    }
    // 0x8018AEB8: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8018AEBC: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_8018AEC0:
    // 0x8018AEC0: andi        $t1, $v0, 0x2
    ctx->r9 = ctx->r2 & 0X2;
    // 0x8018AEC4: beq         $t1, $zero, L_8018AEEC
    if (ctx->r9 == 0) {
        // 0x8018AEC8: andi        $t5, $v0, 0x4
        ctx->r13 = ctx->r2 & 0X4;
            goto L_8018AEEC;
    }
    // 0x8018AEC8: andi        $t5, $v0, 0x4
    ctx->r13 = ctx->r2 & 0X4;
    // 0x8018AECC: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x8018AED0: addiu       $v1, $v1, -0x7AA8
    ctx->r3 = ADD32(ctx->r3, -0X7AA8);
    // 0x8018AED4: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x8018AED8: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8018AEDC: slti        $at, $t3, 0x100
    ctx->r1 = SIGNED(ctx->r11) < 0X100 ? 1 : 0;
    // 0x8018AEE0: bne         $at, $zero, L_8018AEEC
    if (ctx->r1 != 0) {
        // 0x8018AEE4: sw          $t3, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r11;
            goto L_8018AEEC;
    }
    // 0x8018AEE4: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x8018AEE8: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
L_8018AEEC:
    // 0x8018AEEC: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x8018AEF0: beq         $t5, $zero, L_8018AF0C
    if (ctx->r13 == 0) {
        // 0x8018AEF4: addiu       $v1, $v1, -0x7AA8
        ctx->r3 = ADD32(ctx->r3, -0X7AA8);
            goto L_8018AF0C;
    }
    // 0x8018AEF4: addiu       $v1, $v1, -0x7AA8
    ctx->r3 = ADD32(ctx->r3, -0X7AA8);
    // 0x8018AEF8: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8018AEFC: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8018AF00: bgez        $t7, L_8018AF0C
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8018AF04: sw          $t7, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r15;
            goto L_8018AF0C;
    }
    // 0x8018AF04: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8018AF08: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_8018AF0C:
    // 0x8018AF0C: andi        $t9, $v0, 0x8
    ctx->r25 = ctx->r2 & 0X8;
    // 0x8018AF10: beq         $t9, $zero, L_8018AF38
    if (ctx->r25 == 0) {
        // 0x8018AF14: andi        $t3, $v0, 0x1
        ctx->r11 = ctx->r2 & 0X1;
            goto L_8018AF38;
    }
    // 0x8018AF14: andi        $t3, $v0, 0x1
    ctx->r11 = ctx->r2 & 0X1;
    // 0x8018AF18: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x8018AF1C: addiu       $v1, $v1, -0x7AA4
    ctx->r3 = ADD32(ctx->r3, -0X7AA4);
    // 0x8018AF20: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x8018AF24: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8018AF28: slti        $at, $t1, 0x100
    ctx->r1 = SIGNED(ctx->r9) < 0X100 ? 1 : 0;
    // 0x8018AF2C: bne         $at, $zero, L_8018AF38
    if (ctx->r1 != 0) {
        // 0x8018AF30: sw          $t1, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r9;
            goto L_8018AF38;
    }
    // 0x8018AF30: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x8018AF34: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
L_8018AF38:
    // 0x8018AF38: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x8018AF3C: beq         $t3, $zero, L_8018B164
    if (ctx->r11 == 0) {
        // 0x8018AF40: addiu       $v1, $v1, -0x7AA4
        ctx->r3 = ADD32(ctx->r3, -0X7AA4);
            goto L_8018B164;
    }
    // 0x8018AF40: addiu       $v1, $v1, -0x7AA4
    ctx->r3 = ADD32(ctx->r3, -0X7AA4);
    // 0x8018AF44: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x8018AF48: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x8018AF4C: bgez        $t5, L_8018B164
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8018AF50: sw          $t5, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r13;
            goto L_8018B164;
    }
    // 0x8018AF50: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x8018AF54: jr          $ra
    // 0x8018AF58: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    return;
    // 0x8018AF58: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_8018AF5C:
    // 0x8018AF5C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8018AF60: lhu         $v0, -0x276E($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X276E);
    // 0x8018AF64: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x8018AF68: addiu       $v1, $v1, -0x7B30
    ctx->r3 = ADD32(ctx->r3, -0X7B30);
    // 0x8018AF6C: andi        $t7, $v0, 0x4000
    ctx->r15 = ctx->r2 & 0X4000;
    // 0x8018AF70: beq         $t7, $zero, L_8018AFB4
    if (ctx->r15 == 0) {
        // 0x8018AF74: andi        $t8, $v0, 0x8000
        ctx->r24 = ctx->r2 & 0X8000;
            goto L_8018AFB4;
    }
    // 0x8018AF74: andi        $t8, $v0, 0x8000
    ctx->r24 = ctx->r2 & 0X8000;
    // 0x8018AF78: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8018AF7C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8018AF80: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8018AF84: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8018AF88: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8018AF8C: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x8018AF90: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
    // 0x8018AF94: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8018AF98: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x8018AF9C: nop

    // 0x8018AFA0: bc1fl       L_8018AFB8
    if (!c1cs) {
        // 0x8018AFA4: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8018AFB8;
    }
    goto skip_0;
    // 0x8018AFA4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_0:
    // 0x8018AFA8: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8018AFAC: nop

    // 0x8018AFB0: swc1        $f12, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f12.u32l;
L_8018AFB4:
    // 0x8018AFB4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_8018AFB8:
    // 0x8018AFB8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8018AFBC: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8018AFC0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8018AFC4: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x8018AFC8: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8018AFCC: beq         $t8, $zero, L_8018B000
    if (ctx->r24 == 0) {
        // 0x8018AFD0: addiu       $v1, $v1, -0x7B30
        ctx->r3 = ADD32(ctx->r3, -0X7B30);
            goto L_8018B000;
    }
    // 0x8018AFD0: addiu       $v1, $v1, -0x7B30
    ctx->r3 = ADD32(ctx->r3, -0X7B30);
    // 0x8018AFD4: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8018AFD8: lui         $at, 0xC3B4
    ctx->r1 = S32(0XC3B4 << 16);
    // 0x8018AFDC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8018AFE0: sub.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x8018AFE4: swc1        $f16, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f16.u32l;
    // 0x8018AFE8: lwc1        $f18, 0x0($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8018AFEC: c.lt.s      $f18, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f18.fl < ctx->f14.fl;
    // 0x8018AFF0: nop

    // 0x8018AFF4: bc1fl       L_8018B004
    if (!c1cs) {
        // 0x8018AFF8: lui         $at, 0xC3B4
        ctx->r1 = S32(0XC3B4 << 16);
            goto L_8018B004;
    }
    goto skip_1;
    // 0x8018AFF8: lui         $at, 0xC3B4
    ctx->r1 = S32(0XC3B4 << 16);
    skip_1:
    // 0x8018AFFC: swc1        $f12, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f12.u32l;
L_8018B000:
    // 0x8018B000: lui         $at, 0xC3B4
    ctx->r1 = S32(0XC3B4 << 16);
L_8018B004:
    // 0x8018B004: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8018B008: andi        $t9, $v0, 0x2
    ctx->r25 = ctx->r2 & 0X2;
    // 0x8018B00C: beq         $t9, $zero, L_8018B040
    if (ctx->r25 == 0) {
        // 0x8018B010: andi        $t0, $v0, 0x4
        ctx->r8 = ctx->r2 & 0X4;
            goto L_8018B040;
    }
    // 0x8018B010: andi        $t0, $v0, 0x4
    ctx->r8 = ctx->r2 & 0X4;
    // 0x8018B014: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x8018B018: addiu       $v1, $v1, -0x7B2C
    ctx->r3 = ADD32(ctx->r3, -0X7B2C);
    // 0x8018B01C: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8018B020: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x8018B024: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
    // 0x8018B028: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8018B02C: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x8018B030: nop

    // 0x8018B034: bc1f        L_8018B040
    if (!c1cs) {
        // 0x8018B038: nop
    
            goto L_8018B040;
    }
    // 0x8018B038: nop

    // 0x8018B03C: swc1        $f12, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f12.u32l;
L_8018B040:
    // 0x8018B040: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x8018B044: beq         $t0, $zero, L_8018B070
    if (ctx->r8 == 0) {
        // 0x8018B048: addiu       $v1, $v1, -0x7B2C
        ctx->r3 = ADD32(ctx->r3, -0X7B2C);
            goto L_8018B070;
    }
    // 0x8018B048: addiu       $v1, $v1, -0x7B2C
    ctx->r3 = ADD32(ctx->r3, -0X7B2C);
    // 0x8018B04C: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8018B050: sub.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x8018B054: swc1        $f16, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f16.u32l;
    // 0x8018B058: lwc1        $f18, 0x0($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8018B05C: c.lt.s      $f18, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f18.fl < ctx->f14.fl;
    // 0x8018B060: nop

    // 0x8018B064: bc1fl       L_8018B074
    if (!c1cs) {
        // 0x8018B068: andi        $t1, $v0, 0x8
        ctx->r9 = ctx->r2 & 0X8;
            goto L_8018B074;
    }
    goto skip_2;
    // 0x8018B068: andi        $t1, $v0, 0x8
    ctx->r9 = ctx->r2 & 0X8;
    skip_2:
    // 0x8018B06C: swc1        $f12, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f12.u32l;
L_8018B070:
    // 0x8018B070: andi        $t1, $v0, 0x8
    ctx->r9 = ctx->r2 & 0X8;
L_8018B074:
    // 0x8018B074: beq         $t1, $zero, L_8018B0A8
    if (ctx->r9 == 0) {
        // 0x8018B078: andi        $t2, $v0, 0x1
        ctx->r10 = ctx->r2 & 0X1;
            goto L_8018B0A8;
    }
    // 0x8018B078: andi        $t2, $v0, 0x1
    ctx->r10 = ctx->r2 & 0X1;
    // 0x8018B07C: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x8018B080: addiu       $v1, $v1, -0x7B28
    ctx->r3 = ADD32(ctx->r3, -0X7B28);
    // 0x8018B084: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8018B088: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x8018B08C: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
    // 0x8018B090: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8018B094: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x8018B098: nop

    // 0x8018B09C: bc1f        L_8018B0A8
    if (!c1cs) {
        // 0x8018B0A0: nop
    
            goto L_8018B0A8;
    }
    // 0x8018B0A0: nop

    // 0x8018B0A4: swc1        $f12, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f12.u32l;
L_8018B0A8:
    // 0x8018B0A8: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x8018B0AC: beq         $t2, $zero, L_8018B164
    if (ctx->r10 == 0) {
        // 0x8018B0B0: addiu       $v1, $v1, -0x7B28
        ctx->r3 = ADD32(ctx->r3, -0X7B28);
            goto L_8018B164;
    }
    // 0x8018B0B0: addiu       $v1, $v1, -0x7B28
    ctx->r3 = ADD32(ctx->r3, -0X7B28);
    // 0x8018B0B4: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8018B0B8: sub.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x8018B0BC: swc1        $f16, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f16.u32l;
    // 0x8018B0C0: lwc1        $f18, 0x0($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8018B0C4: c.lt.s      $f18, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f18.fl < ctx->f14.fl;
    // 0x8018B0C8: nop

    // 0x8018B0CC: bc1f        L_8018B164
    if (!c1cs) {
        // 0x8018B0D0: nop
    
            goto L_8018B164;
    }
    // 0x8018B0D0: nop

    // 0x8018B0D4: jr          $ra
    // 0x8018B0D8: swc1        $f12, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f12.u32l;
    return;
    // 0x8018B0D8: swc1        $f12, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f12.u32l;
L_8018B0DC:
    // 0x8018B0DC: andi        $t3, $v0, 0x4000
    ctx->r11 = ctx->r2 & 0X4000;
    // 0x8018B0E0: beq         $t3, $zero, L_8018B118
    if (ctx->r11 == 0) {
        // 0x8018B0E4: andi        $t8, $v0, 0x8000
        ctx->r24 = ctx->r2 & 0X8000;
            goto L_8018B118;
    }
    // 0x8018B0E4: andi        $t8, $v0, 0x8000
    ctx->r24 = ctx->r2 & 0X8000;
    // 0x8018B0E8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8018B0EC: addiu       $a0, $a0, -0x7C28
    ctx->r4 = ADD32(ctx->r4, -0X7C28);
    // 0x8018B0F0: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8018B0F4: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x8018B0F8: addiu       $a1, $a1, -0x7C24
    ctx->r5 = ADD32(ctx->r5, -0X7C24);
    // 0x8018B0FC: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8018B100: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8018B104: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x8018B108: slt         $at, $t5, $v1
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8018B10C: bne         $at, $zero, L_8018B118
    if (ctx->r1 != 0) {
        // 0x8018B110: addiu       $t7, $v1, -0x1
        ctx->r15 = ADD32(ctx->r3, -0X1);
            goto L_8018B118;
    }
    // 0x8018B110: addiu       $t7, $v1, -0x1
    ctx->r15 = ADD32(ctx->r3, -0X1);
    // 0x8018B114: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
L_8018B118:
    // 0x8018B118: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8018B11C: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8018B120: addiu       $a1, $a1, -0x7C24
    ctx->r5 = ADD32(ctx->r5, -0X7C24);
    // 0x8018B124: beq         $t8, $zero, L_8018B138
    if (ctx->r24 == 0) {
        // 0x8018B128: addiu       $a0, $a0, -0x7C28
        ctx->r4 = ADD32(ctx->r4, -0X7C28);
            goto L_8018B138;
    }
    // 0x8018B128: addiu       $a0, $a0, -0x7C28
    ctx->r4 = ADD32(ctx->r4, -0X7C28);
    // 0x8018B12C: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x8018B130: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x8018B134: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
L_8018B138:
    // 0x8018B138: andi        $t1, $v0, 0x2
    ctx->r9 = ctx->r2 & 0X2;
    // 0x8018B13C: beq         $t1, $zero, L_8018B150
    if (ctx->r9 == 0) {
        // 0x8018B140: andi        $t4, $v0, 0x4
        ctx->r12 = ctx->r2 & 0X4;
            goto L_8018B150;
    }
    // 0x8018B140: andi        $t4, $v0, 0x4
    ctx->r12 = ctx->r2 & 0X4;
    // 0x8018B144: lw          $t2, 0x0($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X0);
    // 0x8018B148: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8018B14C: sw          $t3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r11;
L_8018B150:
    // 0x8018B150: beq         $t4, $zero, L_8018B164
    if (ctx->r12 == 0) {
        // 0x8018B154: nop
    
            goto L_8018B164;
    }
    // 0x8018B154: nop

    // 0x8018B158: lw          $t5, 0x0($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X0);
    // 0x8018B15C: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x8018B160: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
L_8018B164:
    // 0x8018B164: jr          $ra
    // 0x8018B168: nop

    return;
    // 0x8018B168: nop

;}
RECOMP_FUNC void Ending_8018A2A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018A2A8: addiu       $sp, $sp, -0x2C8
    ctx->r29 = ADD32(ctx->r29, -0X2C8);
    // 0x8018A2AC: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x8018A2B0: lui         $fp, 0x8019
    ctx->r30 = S32(0X8019 << 16);
    // 0x8018A2B4: addiu       $fp, $fp, 0x6F88
    ctx->r30 = ADD32(ctx->r30, 0X6F88);
    // 0x8018A2B8: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8018A2BC: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x8018A2C0: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x8018A2C4: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x8018A2C8: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x8018A2CC: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x8018A2D0: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8018A2D4: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x8018A2D8: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8018A2DC: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x8018A2E0: lw          $t6, 0x0($fp)
    ctx->r14 = MEM_W(ctx->r30, 0X0);
    // 0x8018A2E4: lui         $s0, 0x8019
    ctx->r16 = S32(0X8019 << 16);
    // 0x8018A2E8: addiu       $s0, $s0, 0x6D08
    ctx->r16 = ADD32(ctx->r16, 0X6D08);
    // 0x8018A2EC: blez        $t6, L_8018A53C
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8018A2F0: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_8018A53C;
    }
    // 0x8018A2F0: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8018A2F4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018A2F8: lui         $s7, 0x800C
    ctx->r23 = S32(0X800C << 16);
    // 0x8018A2FC: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x8018A300: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x8018A304: addiu       $s1, $s1, -0x4C40
    ctx->r17 = ADD32(ctx->r17, -0X4C40);
    // 0x8018A308: addiu       $s2, $s2, 0x7E64
    ctx->r18 = ADD32(ctx->r18, 0X7E64);
    // 0x8018A30C: addiu       $s7, $s7, 0x4660
    ctx->r23 = ADD32(ctx->r23, 0X4660);
    // 0x8018A310: lwc1        $f20, 0x6560($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X6560);
    // 0x8018A314: lui         $s6, 0x600
    ctx->r22 = S32(0X600 << 16);
    // 0x8018A318: lui         $s5, 0xFA00
    ctx->r21 = S32(0XFA00 << 16);
    // 0x8018A31C: addiu       $s4, $sp, 0x6C
    ctx->r20 = ADD32(ctx->r29, 0X6C);
L_8018A320:
    // 0x8018A320: jal         0x80005708
    // 0x8018A324: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Push(rdram, ctx);
        goto after_0;
    // 0x8018A324: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x8018A328: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8018A32C: jal         0x800B8DD0
    // 0x8018A330: lh          $a1, 0x8($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X8);
    RCP_SetupDL(rdram, ctx);
        goto after_1;
    // 0x8018A330: lh          $a1, 0x8($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X8);
    after_1:
    // 0x8018A334: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x8018A338: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8018A33C: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    // 0x8018A340: sw          $s5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r21;
    // 0x8018A344: lbu         $t1, 0x3C($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X3C);
    // 0x8018A348: lbu         $t5, 0x3D($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X3D);
    // 0x8018A34C: lbu         $t9, 0x3F($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X3F);
    // 0x8018A350: lbu         $t0, 0x3E($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X3E);
    // 0x8018A354: sll         $t2, $t1, 24
    ctx->r10 = S32(ctx->r9 << 24);
    // 0x8018A358: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x8018A35C: or          $t3, $t9, $t2
    ctx->r11 = ctx->r25 | ctx->r10;
    // 0x8018A360: or          $t7, $t3, $t6
    ctx->r15 = ctx->r11 | ctx->r14;
    // 0x8018A364: sll         $t1, $t0, 8
    ctx->r9 = S32(ctx->r8 << 8);
    // 0x8018A368: or          $t9, $t7, $t1
    ctx->r25 = ctx->r15 | ctx->r9;
    // 0x8018A36C: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8018A370: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8018A374: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8018A378: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8018A37C: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x8018A380: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    // 0x8018A384: jal         0x80005B00
    // 0x8018A388: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    Matrix_Translate(rdram, ctx);
        goto after_2;
    // 0x8018A388: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    after_2:
    // 0x8018A38C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8018A390: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8018A394: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8018A398: lw          $a1, 0x24($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X24);
    // 0x8018A39C: lw          $a2, 0x28($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X28);
    // 0x8018A3A0: jal         0x80005C34
    // 0x8018A3A4: lw          $a3, 0x2C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X2C);
    Matrix_Scale(rdram, ctx);
        goto after_3;
    // 0x8018A3A4: lw          $a3, 0x2C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X2C);
    after_3:
    // 0x8018A3A8: lwc1        $f4, 0x1C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x8018A3AC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8018A3B0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018A3B4: mul.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x8018A3B8: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8018A3BC: jal         0x80005E90
    // 0x8018A3C0: nop

    Matrix_RotateY(rdram, ctx);
        goto after_4;
    // 0x8018A3C0: nop

    after_4:
    // 0x8018A3C4: lwc1        $f8, 0x18($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8018A3C8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8018A3CC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018A3D0: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x8018A3D4: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8018A3D8: jal         0x80005D44
    // 0x8018A3DC: nop

    Matrix_RotateX(rdram, ctx);
        goto after_5;
    // 0x8018A3DC: nop

    after_5:
    // 0x8018A3E0: lwc1        $f16, 0x20($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X20);
    // 0x8018A3E4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8018A3E8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018A3EC: mul.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f20.fl);
    // 0x8018A3F0: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8018A3F4: jal         0x80005FE0
    // 0x8018A3F8: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_6;
    // 0x8018A3F8: nop

    after_6:
    // 0x8018A3FC: jal         0x80006EB8
    // 0x8018A400: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_7;
    // 0x8018A400: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_7:
    // 0x8018A404: lw          $t5, 0x4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X4);
    // 0x8018A408: bne         $t5, $zero, L_8018A430
    if (ctx->r13 != 0) {
        // 0x8018A40C: nop
    
            goto L_8018A430;
    }
    // 0x8018A40C: nop

    // 0x8018A410: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x8018A414: addiu       $t3, $v1, 0x8
    ctx->r11 = ADD32(ctx->r3, 0X8);
    // 0x8018A418: sw          $t3, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r11;
    // 0x8018A41C: sw          $s6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r22;
    // 0x8018A420: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x8018A424: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8018A428: b           L_8018A51C
    // 0x8018A42C: nop

        goto L_8018A51C;
    // 0x8018A42C: nop

L_8018A430:
    // 0x8018A430: jal         0x8009ACDC
    // 0x8018A434: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    Animation_GetFrameCount(rdram, ctx);
        goto after_8;
    // 0x8018A434: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_8:
    // 0x8018A438: lw          $t8, 0x34($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X34);
    // 0x8018A43C: lwc1        $f8, 0x30($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X30);
    // 0x8018A440: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8018A444: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8018A448: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8018A44C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8018A450: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8018A454: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x8018A458: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8018A45C: nop

    // 0x8018A460: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8018A464: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8018A468: nop

    // 0x8018A46C: andi        $at, $t7, 0x4
    ctx->r1 = ctx->r15 & 0X4;
    // 0x8018A470: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x8018A474: beql        $t7, $zero, L_8018A4CC
    if (ctx->r15 == 0) {
        // 0x8018A478: mfc1        $t7, $f16
        ctx->r15 = (int32_t)ctx->f16.u32l;
            goto L_8018A4CC;
    }
    goto skip_0;
    // 0x8018A478: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    skip_0:
    // 0x8018A47C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8018A480: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8018A484: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8018A488: sub.s       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8018A48C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8018A490: nop

    // 0x8018A494: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8018A498: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8018A49C: nop

    // 0x8018A4A0: andi        $at, $t7, 0x4
    ctx->r1 = ctx->r15 & 0X4;
    // 0x8018A4A4: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x8018A4A8: bne         $t7, $zero, L_8018A4C0
    if (ctx->r15 != 0) {
        // 0x8018A4AC: nop
    
            goto L_8018A4C0;
    }
    // 0x8018A4AC: nop

    // 0x8018A4B0: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    // 0x8018A4B4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8018A4B8: b           L_8018A4D8
    // 0x8018A4BC: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_8018A4D8;
    // 0x8018A4BC: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_8018A4C0:
    // 0x8018A4C0: b           L_8018A4D8
    // 0x8018A4C4: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_8018A4D8;
    // 0x8018A4C4: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8018A4C8: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
L_8018A4CC:
    // 0x8018A4CC: nop

    // 0x8018A4D0: bltz        $t7, L_8018A4C0
    if (SIGNED(ctx->r15) < 0) {
        // 0x8018A4D4: nop
    
            goto L_8018A4C0;
    }
    // 0x8018A4D4: nop

L_8018A4D8:
    // 0x8018A4D8: divu        $zero, $t7, $v0
    lo = S32(U32(ctx->r15) / U32(ctx->r2)); hi = S32(U32(ctx->r15) % U32(ctx->r2));
    // 0x8018A4DC: mfhi        $a1
    ctx->r5 = hi;
    // 0x8018A4E0: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x8018A4E4: bne         $v0, $zero, L_8018A4F0
    if (ctx->r2 != 0) {
        // 0x8018A4E8: nop
    
            goto L_8018A4F0;
    }
    // 0x8018A4E8: nop

    // 0x8018A4EC: break       7
    do_break(2149098732);
L_8018A4F0:
    // 0x8018A4F0: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x8018A4F4: jal         0x8009AA20
    // 0x8018A4F8: nop

    Animation_GetFrameData(rdram, ctx);
        goto after_9;
    // 0x8018A4F8: nop

    after_9:
    // 0x8018A4FC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8018A500: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x8018A504: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x8018A508: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8018A50C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8018A510: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8018A514: jal         0x8009A72C
    // 0x8018A518: sw          $s7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r23;
    Animation_DrawSkeleton(rdram, ctx);
        goto after_10;
    // 0x8018A518: sw          $s7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r23;
    after_10:
L_8018A51C:
    // 0x8018A51C: jal         0x80005740
    // 0x8018A520: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_11;
    // 0x8018A520: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_11:
    // 0x8018A524: lw          $t1, 0x0($fp)
    ctx->r9 = MEM_W(ctx->r30, 0X0);
    // 0x8018A528: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8018A52C: addiu       $s0, $s0, 0x40
    ctx->r16 = ADD32(ctx->r16, 0X40);
    // 0x8018A530: slt         $at, $s3, $t1
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8018A534: bne         $at, $zero, L_8018A320
    if (ctx->r1 != 0) {
        // 0x8018A538: nop
    
            goto L_8018A320;
    }
    // 0x8018A538: nop

L_8018A53C:
    // 0x8018A53C: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x8018A540: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x8018A544: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8018A548: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x8018A54C: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x8018A550: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x8018A554: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x8018A558: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x8018A55C: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x8018A560: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x8018A564: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x8018A568: jr          $ra
    // 0x8018A56C: addiu       $sp, $sp, 0x2C8
    ctx->r29 = ADD32(ctx->r29, 0X2C8);
    return;
    // 0x8018A56C: addiu       $sp, $sp, 0x2C8
    ctx->r29 = ADD32(ctx->r29, 0X2C8);
;}
RECOMP_FUNC void Ending_80189108(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80189108: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8018910C: lui         $t0, 0x8019
    ctx->r8 = S32(0X8019 << 16);
    // 0x80189110: addiu       $t0, $t0, 0x6D08
    ctx->r8 = ADD32(ctx->r8, 0X6D08);
    // 0x80189114: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80189118: lw          $v1, 0x138($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X138);
    // 0x8018911C: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x80189120: beq         $v1, $zero, L_80189148
    if (ctx->r3 == 0) {
        // 0x80189124: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80189148;
    }
    // 0x80189124: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80189128: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8018912C: beq         $v0, $at, L_80189384
    if (ctx->r2 == ctx->r1) {
        // 0x80189130: lui         $v1, 0x8017
        ctx->r3 = S32(0X8017 << 16);
            goto L_80189384;
    }
    // 0x80189130: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80189134: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80189138: beq         $v0, $at, L_801893E4
    if (ctx->r2 == ctx->r1) {
        // 0x8018913C: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_801893E4;
    }
    // 0x8018913C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80189140: b           L_80189528
    // 0x80189144: nop

        goto L_80189528;
    // 0x80189144: nop

L_80189148:
    // 0x80189148: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8018914C: lw          $v0, 0x7A80($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7A80);
    // 0x80189150: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80189154: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80189158: beq         $v0, $a0, L_801891A0
    if (ctx->r2 == ctx->r4) {
        // 0x8018915C: sw          $t6, -0x7D00($at)
        MEM_W(-0X7D00, ctx->r1) = ctx->r14;
            goto L_801891A0;
    }
    // 0x8018915C: sw          $t6, -0x7D00($at)
    MEM_W(-0X7D00, ctx->r1) = ctx->r14;
    // 0x80189160: addiu       $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
    // 0x80189164: beq         $v0, $at, L_801891C0
    if (ctx->r2 == ctx->r1) {
        // 0x80189168: addiu       $t7, $zero, 0x14
        ctx->r15 = ADD32(0, 0X14);
            goto L_801891C0;
    }
    // 0x80189168: addiu       $t7, $zero, 0x14
    ctx->r15 = ADD32(0, 0X14);
    // 0x8018916C: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x80189170: beq         $v0, $at, L_801891CC
    if (ctx->r2 == ctx->r1) {
        // 0x80189174: addiu       $t8, $zero, 0x14
        ctx->r24 = ADD32(0, 0X14);
            goto L_801891CC;
    }
    // 0x80189174: addiu       $t8, $zero, 0x14
    ctx->r24 = ADD32(0, 0X14);
    // 0x80189178: addiu       $at, $zero, 0x78
    ctx->r1 = ADD32(0, 0X78);
    // 0x8018917C: beq         $v0, $at, L_801891D8
    if (ctx->r2 == ctx->r1) {
        // 0x80189180: addiu       $at, $zero, 0x82
        ctx->r1 = ADD32(0, 0X82);
            goto L_801891D8;
    }
    // 0x80189180: addiu       $at, $zero, 0x82
    ctx->r1 = ADD32(0, 0X82);
    // 0x80189184: beq         $v0, $at, L_801891E4
    if (ctx->r2 == ctx->r1) {
        // 0x80189188: addiu       $t9, $zero, 0x14
        ctx->r25 = ADD32(0, 0X14);
            goto L_801891E4;
    }
    // 0x80189188: addiu       $t9, $zero, 0x14
    ctx->r25 = ADD32(0, 0X14);
    // 0x8018918C: addiu       $at, $zero, 0xAA
    ctx->r1 = ADD32(0, 0XAA);
    // 0x80189190: beq         $v0, $at, L_801891F0
    if (ctx->r2 == ctx->r1) {
        // 0x80189194: addiu       $t2, $zero, 0x14
        ctx->r10 = ADD32(0, 0X14);
            goto L_801891F0;
    }
    // 0x80189194: addiu       $t2, $zero, 0x14
    ctx->r10 = ADD32(0, 0X14);
    // 0x80189198: b           L_801891F8
    // 0x8018919C: nop

        goto L_801891F8;
    // 0x8018919C: nop

L_801891A0:
    // 0x801891A0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x801891A4: addiu       $a0, $a0, 0x4D78
    ctx->r4 = ADD32(ctx->r4, 0X4D78);
    // 0x801891A8: jal         0x800BA808
    // 0x801891AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    Radio_PlayMessage(rdram, ctx);
        goto after_0;
    // 0x801891AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x801891B0: lui         $t0, 0x8019
    ctx->r8 = S32(0X8019 << 16);
    // 0x801891B4: addiu       $t0, $t0, 0x6D08
    ctx->r8 = ADD32(ctx->r8, 0X6D08);
    // 0x801891B8: b           L_801891F8
    // 0x801891BC: lw          $v1, 0x138($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X138);
        goto L_801891F8;
    // 0x801891BC: lw          $v1, 0x138($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X138);
L_801891C0:
    // 0x801891C0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801891C4: b           L_801891F8
    // 0x801891C8: sw          $t7, 0x6F94($at)
    MEM_W(0X6F94, ctx->r1) = ctx->r15;
        goto L_801891F8;
    // 0x801891C8: sw          $t7, 0x6F94($at)
    MEM_W(0X6F94, ctx->r1) = ctx->r15;
L_801891CC:
    // 0x801891CC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801891D0: b           L_801891F8
    // 0x801891D4: sw          $t8, 0x6F94($at)
    MEM_W(0X6F94, ctx->r1) = ctx->r24;
        goto L_801891F8;
    // 0x801891D4: sw          $t8, 0x6F94($at)
    MEM_W(0X6F94, ctx->r1) = ctx->r24;
L_801891D8:
    // 0x801891D8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801891DC: b           L_801891F8
    // 0x801891E0: sw          $a0, 0x6F98($at)
    MEM_W(0X6F98, ctx->r1) = ctx->r4;
        goto L_801891F8;
    // 0x801891E0: sw          $a0, 0x6F98($at)
    MEM_W(0X6F98, ctx->r1) = ctx->r4;
L_801891E4:
    // 0x801891E4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801891E8: b           L_801891F8
    // 0x801891EC: sw          $t9, 0x6F94($at)
    MEM_W(0X6F94, ctx->r1) = ctx->r25;
        goto L_801891F8;
    // 0x801891EC: sw          $t9, 0x6F94($at)
    MEM_W(0X6F94, ctx->r1) = ctx->r25;
L_801891F0:
    // 0x801891F0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801891F4: sw          $t2, 0x6F94($at)
    MEM_W(0X6F94, ctx->r1) = ctx->r10;
L_801891F8:
    // 0x801891F8: bne         $v1, $zero, L_80189220
    if (ctx->r3 != 0) {
        // 0x801891FC: lui         $t3, 0x8017
        ctx->r11 = S32(0X8017 << 16);
            goto L_80189220;
    }
    // 0x801891FC: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x80189200: lw          $t3, 0x7A80($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7A80);
    // 0x80189204: addiu       $at, $zero, 0xB4
    ctx->r1 = ADD32(0, 0XB4);
    // 0x80189208: addiu       $t4, $zero, 0x78
    ctx->r12 = ADD32(0, 0X78);
    // 0x8018920C: bne         $t3, $at, L_80189220
    if (ctx->r11 != ctx->r1) {
        // 0x80189210: lui         $at, 0x8016
        ctx->r1 = S32(0X8016 << 16);
            goto L_80189220;
    }
    // 0x80189210: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80189214: sw          $t4, 0x1690($at)
    MEM_W(0X1690, ctx->r1) = ctx->r12;
    // 0x80189218: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018921C: sw          $zero, -0x7D64($at)
    MEM_W(-0X7D64, ctx->r1) = 0;
L_80189220:
    // 0x80189220: jal         0x80188634
    // 0x80189224: nop

    Ending_80188634(rdram, ctx);
        goto after_1;
    // 0x80189224: nop

    after_1:
    // 0x80189228: lui         $t0, 0x8019
    ctx->r8 = S32(0X8019 << 16);
    // 0x8018922C: bne         $v0, $zero, L_80189244
    if (ctx->r2 != 0) {
        // 0x80189230: addiu       $t0, $t0, 0x6D08
        ctx->r8 = ADD32(ctx->r8, 0X6D08);
            goto L_80189244;
    }
    // 0x80189230: addiu       $t0, $t0, 0x6D08
    ctx->r8 = ADD32(ctx->r8, 0X6D08);
    // 0x80189234: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x80189238: lw          $t5, 0x7A80($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7A80);
    // 0x8018923C: addiu       $at, $zero, 0xE6
    ctx->r1 = ADD32(0, 0XE6);
    // 0x80189240: bne         $t5, $at, L_8018927C
    if (ctx->r13 != ctx->r1) {
        // 0x80189244: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_8018927C;
    }
L_80189244:
    // 0x80189244: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80189248: sw          $zero, 0x134($t0)
    MEM_W(0X134, ctx->r8) = 0;
    // 0x8018924C: sw          $t6, 0x138($t0)
    MEM_W(0X138, ctx->r8) = ctx->r14;
    // 0x80189250: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80189254: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x80189258: sw          $zero, 0x7A80($at)
    MEM_W(0X7A80, ctx->r1) = 0;
    // 0x8018925C: jal         0x8001A838
    // 0x80189260: ori         $a0, $a0, 0x2018
    ctx->r4 = ctx->r4 | 0X2018;
    Audio_KillSfxById(rdram, ctx);
        goto after_2;
    // 0x80189260: ori         $a0, $a0, 0x2018
    ctx->r4 = ctx->r4 | 0X2018;
    after_2:
    // 0x80189264: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80189268: sw          $zero, 0x6F90($at)
    MEM_W(0X6F90, ctx->r1) = 0;
    // 0x8018926C: lui         $t0, 0x8019
    ctx->r8 = S32(0X8019 << 16);
    // 0x80189270: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80189274: addiu       $t0, $t0, 0x6D08
    ctx->r8 = ADD32(ctx->r8, 0X6D08);
    // 0x80189278: sw          $zero, 0x1690($at)
    MEM_W(0X1690, ctx->r1) = 0;
L_8018927C:
    // 0x8018927C: jal         0x8009ACDC
    // 0x80189280: lw          $a0, 0x100($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X100);
    Animation_GetFrameCount(rdram, ctx);
        goto after_3;
    // 0x80189280: lw          $a0, 0x100($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X100);
    after_3:
    // 0x80189284: lui         $t0, 0x8019
    ctx->r8 = S32(0X8019 << 16);
    // 0x80189288: addiu       $t0, $t0, 0x6D08
    ctx->r8 = ADD32(ctx->r8, 0X6D08);
    // 0x8018928C: lw          $a1, 0x134($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X134);
    // 0x80189290: lwc1        $f8, 0x130($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X130);
    // 0x80189294: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80189298: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x8018929C: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x801892A0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801892A4: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x801892A8: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x801892AC: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x801892B0: nop

    // 0x801892B4: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x801892B8: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x801892BC: nop

    // 0x801892C0: andi        $at, $t8, 0x4
    ctx->r1 = ctx->r24 & 0X4;
    // 0x801892C4: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x801892C8: beql        $t8, $zero, L_80189320
    if (ctx->r24 == 0) {
        // 0x801892CC: mfc1        $t8, $f16
        ctx->r24 = (int32_t)ctx->f16.u32l;
            goto L_80189320;
    }
    goto skip_0;
    // 0x801892CC: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
    skip_0:
    // 0x801892D0: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801892D4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801892D8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801892DC: sub.s       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x801892E0: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x801892E4: nop

    // 0x801892E8: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x801892EC: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x801892F0: nop

    // 0x801892F4: andi        $at, $t8, 0x4
    ctx->r1 = ctx->r24 & 0X4;
    // 0x801892F8: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x801892FC: bne         $t8, $zero, L_80189314
    if (ctx->r24 != 0) {
        // 0x80189300: nop
    
            goto L_80189314;
    }
    // 0x80189300: nop

    // 0x80189304: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
    // 0x80189308: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8018930C: b           L_8018932C
    // 0x80189310: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_8018932C;
    // 0x80189310: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_80189314:
    // 0x80189314: b           L_8018932C
    // 0x80189318: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_8018932C;
    // 0x80189318: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8018931C: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
L_80189320:
    // 0x80189320: nop

    // 0x80189324: bltz        $t8, L_80189314
    if (SIGNED(ctx->r24) < 0) {
        // 0x80189328: nop
    
            goto L_80189314;
    }
    // 0x80189328: nop

L_8018932C:
    // 0x8018932C: divu        $zero, $t8, $v0
    lo = S32(U32(ctx->r24) / U32(ctx->r2)); hi = S32(U32(ctx->r24) % U32(ctx->r2));
    // 0x80189330: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
    // 0x80189334: mfhi        $a0
    ctx->r4 = hi;
    // 0x80189338: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8018933C: bne         $v0, $zero, L_80189348
    if (ctx->r2 != 0) {
        // 0x80189340: nop
    
            goto L_80189348;
    }
    // 0x80189340: nop

    // 0x80189344: break       7
    do_break(2149094212);
L_80189348:
    // 0x80189348: slti        $at, $v1, 0x1E
    ctx->r1 = SIGNED(ctx->r3) < 0X1E ? 1 : 0;
    // 0x8018934C: bne         $at, $zero, L_80189358
    if (ctx->r1 != 0) {
        // 0x80189350: slti        $at, $v1, 0x29
        ctx->r1 = SIGNED(ctx->r3) < 0X29 ? 1 : 0;
            goto L_80189358;
    }
    // 0x80189350: slti        $at, $v1, 0x29
    ctx->r1 = SIGNED(ctx->r3) < 0X29 ? 1 : 0;
    // 0x80189354: bne         $at, $zero, L_80189368
    if (ctx->r1 != 0) {
        // 0x80189358: slti        $at, $v1, 0x3C
        ctx->r1 = SIGNED(ctx->r3) < 0X3C ? 1 : 0;
            goto L_80189368;
    }
L_80189358:
    // 0x80189358: slti        $at, $v1, 0x3C
    ctx->r1 = SIGNED(ctx->r3) < 0X3C ? 1 : 0;
    // 0x8018935C: bne         $at, $zero, L_80189374
    if (ctx->r1 != 0) {
        // 0x80189360: slti        $at, $v1, 0x6F
        ctx->r1 = SIGNED(ctx->r3) < 0X6F ? 1 : 0;
            goto L_80189374;
    }
    // 0x80189360: slti        $at, $v1, 0x6F
    ctx->r1 = SIGNED(ctx->r3) < 0X6F ? 1 : 0;
    // 0x80189364: beq         $at, $zero, L_80189374
    if (ctx->r1 == 0) {
        // 0x80189368: addiu       $t9, $a1, 0x1
        ctx->r25 = ADD32(ctx->r5, 0X1);
            goto L_80189374;
    }
L_80189368:
    // 0x80189368: addiu       $t9, $a1, 0x1
    ctx->r25 = ADD32(ctx->r5, 0X1);
    // 0x8018936C: b           L_80189528
    // 0x80189370: sw          $t9, 0x134($t0)
    MEM_W(0X134, ctx->r8) = ctx->r25;
        goto L_80189528;
    // 0x80189370: sw          $t9, 0x134($t0)
    MEM_W(0X134, ctx->r8) = ctx->r25;
L_80189374:
    // 0x80189374: beq         $a0, $zero, L_80189528
    if (ctx->r4 == 0) {
        // 0x80189378: addiu       $t2, $a1, 0x1
        ctx->r10 = ADD32(ctx->r5, 0X1);
            goto L_80189528;
    }
    // 0x80189378: addiu       $t2, $a1, 0x1
    ctx->r10 = ADD32(ctx->r5, 0X1);
    // 0x8018937C: b           L_80189528
    // 0x80189380: sw          $t2, 0x134($t0)
    MEM_W(0X134, ctx->r8) = ctx->r10;
        goto L_80189528;
    // 0x80189380: sw          $t2, 0x134($t0)
    MEM_W(0X134, ctx->r8) = ctx->r10;
L_80189384:
    // 0x80189384: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
    // 0x80189388: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018938C: sw          $zero, -0x7D00($at)
    MEM_W(-0X7D00, ctx->r1) = 0;
    // 0x80189390: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x80189394: bne         $v1, $at, L_801893B8
    if (ctx->r3 != ctx->r1) {
        // 0x80189398: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_801893B8;
    }
    // 0x80189398: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8018939C: addiu       $a0, $a0, 0x4DDC
    ctx->r4 = ADD32(ctx->r4, 0X4DDC);
    // 0x801893A0: jal         0x800BA808
    // 0x801893A4: addiu       $a1, $zero, 0x12C
    ctx->r5 = ADD32(0, 0X12C);
    Radio_PlayMessage(rdram, ctx);
        goto after_4;
    // 0x801893A4: addiu       $a1, $zero, 0x12C
    ctx->r5 = ADD32(0, 0X12C);
    after_4:
    // 0x801893A8: lui         $t0, 0x8019
    ctx->r8 = S32(0X8019 << 16);
    // 0x801893AC: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x801893B0: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
    // 0x801893B4: addiu       $t0, $t0, 0x6D08
    ctx->r8 = ADD32(ctx->r8, 0X6D08);
L_801893B8:
    // 0x801893B8: addiu       $at, $zero, 0x82
    ctx->r1 = ADD32(0, 0X82);
    // 0x801893BC: bne         $v1, $at, L_801893D4
    if (ctx->r3 != ctx->r1) {
        // 0x801893C0: addiu       $t3, $zero, 0x2
        ctx->r11 = ADD32(0, 0X2);
            goto L_801893D4;
    }
    // 0x801893C0: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x801893C4: sw          $zero, 0x134($t0)
    MEM_W(0X134, ctx->r8) = 0;
    // 0x801893C8: sw          $t3, 0x138($t0)
    MEM_W(0X138, ctx->r8) = ctx->r11;
    // 0x801893CC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801893D0: sw          $zero, 0x7A80($at)
    MEM_W(0X7A80, ctx->r1) = 0;
L_801893D4:
    // 0x801893D4: lw          $t4, 0x134($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X134);
    // 0x801893D8: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x801893DC: b           L_80189528
    // 0x801893E0: sw          $t5, 0x134($t0)
    MEM_W(0X134, ctx->r8) = ctx->r13;
        goto L_80189528;
    // 0x801893E0: sw          $t5, 0x134($t0)
    MEM_W(0X134, ctx->r8) = ctx->r13;
L_801893E4:
    // 0x801893E4: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x801893E8: lw          $v0, 0x7A80($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7A80);
    // 0x801893EC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801893F0: sw          $t6, -0x7D00($at)
    MEM_W(-0X7D00, ctx->r1) = ctx->r14;
    // 0x801893F4: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x801893F8: beq         $v0, $at, L_80189414
    if (ctx->r2 == ctx->r1) {
        // 0x801893FC: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_80189414;
    }
    // 0x801893FC: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80189400: addiu       $at, $zero, 0x50
    ctx->r1 = ADD32(0, 0X50);
    // 0x80189404: beq         $v0, $at, L_8018942C
    if (ctx->r2 == ctx->r1) {
        // 0x80189408: addiu       $t7, $zero, 0xFF
        ctx->r15 = ADD32(0, 0XFF);
            goto L_8018942C;
    }
    // 0x80189408: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8018940C: b           L_80189434
    // 0x80189410: nop

        goto L_80189434;
    // 0x80189410: nop

L_80189414:
    // 0x80189414: addiu       $a0, $a0, 0x4E18
    ctx->r4 = ADD32(ctx->r4, 0X4E18);
    // 0x80189418: jal         0x800BA808
    // 0x8018941C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    Radio_PlayMessage(rdram, ctx);
        goto after_5;
    // 0x8018941C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x80189420: lui         $t0, 0x8019
    ctx->r8 = S32(0X8019 << 16);
    // 0x80189424: b           L_80189434
    // 0x80189428: addiu       $t0, $t0, 0x6D08
    ctx->r8 = ADD32(ctx->r8, 0X6D08);
        goto L_80189434;
    // 0x80189428: addiu       $t0, $t0, 0x6D08
    ctx->r8 = ADD32(ctx->r8, 0X6D08);
L_8018942C:
    // 0x8018942C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80189430: sw          $t7, -0x7CA8($at)
    MEM_W(-0X7CA8, ctx->r1) = ctx->r15;
L_80189434:
    // 0x80189434: jal         0x8009ACDC
    // 0x80189438: lw          $a0, 0x100($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X100);
    Animation_GetFrameCount(rdram, ctx);
        goto after_6;
    // 0x80189438: lw          $a0, 0x100($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X100);
    after_6:
    // 0x8018943C: lui         $t0, 0x8019
    ctx->r8 = S32(0X8019 << 16);
    // 0x80189440: addiu       $t0, $t0, 0x6D08
    ctx->r8 = ADD32(ctx->r8, 0X6D08);
    // 0x80189444: lw          $a1, 0x134($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X134);
    // 0x80189448: lwc1        $f6, 0x130($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X130);
    // 0x8018944C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80189450: mtc1        $a1, $f18
    ctx->f18.u32l = ctx->r5;
    // 0x80189454: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80189458: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8018945C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80189460: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80189464: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80189468: nop

    // 0x8018946C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80189470: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80189474: nop

    // 0x80189478: andi        $at, $t9, 0x4
    ctx->r1 = ctx->r25 & 0X4;
    // 0x8018947C: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x80189480: beql        $t9, $zero, L_801894D8
    if (ctx->r25 == 0) {
        // 0x80189484: mfc1        $t9, $f10
        ctx->r25 = (int32_t)ctx->f10.u32l;
            goto L_801894D8;
    }
    goto skip_1;
    // 0x80189484: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    skip_1:
    // 0x80189488: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8018948C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80189490: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80189494: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80189498: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8018949C: nop

    // 0x801894A0: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x801894A4: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x801894A8: nop

    // 0x801894AC: andi        $at, $t9, 0x4
    ctx->r1 = ctx->r25 & 0X4;
    // 0x801894B0: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x801894B4: bne         $t9, $zero, L_801894CC
    if (ctx->r25 != 0) {
        // 0x801894B8: nop
    
            goto L_801894CC;
    }
    // 0x801894B8: nop

    // 0x801894BC: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x801894C0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801894C4: b           L_801894E4
    // 0x801894C8: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_801894E4;
    // 0x801894C8: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_801894CC:
    // 0x801894CC: b           L_801894E4
    // 0x801894D0: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_801894E4;
    // 0x801894D0: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x801894D4: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
L_801894D8:
    // 0x801894D8: nop

    // 0x801894DC: bltz        $t9, L_801894CC
    if (SIGNED(ctx->r25) < 0) {
        // 0x801894E0: nop
    
            goto L_801894CC;
    }
    // 0x801894E0: nop

L_801894E4:
    // 0x801894E4: divu        $zero, $t9, $v0
    lo = S32(U32(ctx->r25) / U32(ctx->r2)); hi = S32(U32(ctx->r25) % U32(ctx->r2));
    // 0x801894E8: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
    // 0x801894EC: mfhi        $a0
    ctx->r4 = hi;
    // 0x801894F0: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x801894F4: bne         $v0, $zero, L_80189500
    if (ctx->r2 != 0) {
        // 0x801894F8: nop
    
            goto L_80189500;
    }
    // 0x801894F8: nop

    // 0x801894FC: break       7
    do_break(2149094652);
L_80189500:
    // 0x80189500: slti        $at, $v1, 0x14
    ctx->r1 = SIGNED(ctx->r3) < 0X14 ? 1 : 0;
    // 0x80189504: bne         $at, $zero, L_8018951C
    if (ctx->r1 != 0) {
        // 0x80189508: slti        $at, $v1, 0x33
        ctx->r1 = SIGNED(ctx->r3) < 0X33 ? 1 : 0;
            goto L_8018951C;
    }
    // 0x80189508: slti        $at, $v1, 0x33
    ctx->r1 = SIGNED(ctx->r3) < 0X33 ? 1 : 0;
    // 0x8018950C: beq         $at, $zero, L_8018951C
    if (ctx->r1 == 0) {
        // 0x80189510: addiu       $t2, $a1, 0x1
        ctx->r10 = ADD32(ctx->r5, 0X1);
            goto L_8018951C;
    }
    // 0x80189510: addiu       $t2, $a1, 0x1
    ctx->r10 = ADD32(ctx->r5, 0X1);
    // 0x80189514: b           L_80189528
    // 0x80189518: sw          $t2, 0x134($t0)
    MEM_W(0X134, ctx->r8) = ctx->r10;
        goto L_80189528;
    // 0x80189518: sw          $t2, 0x134($t0)
    MEM_W(0X134, ctx->r8) = ctx->r10;
L_8018951C:
    // 0x8018951C: beq         $a0, $zero, L_80189528
    if (ctx->r4 == 0) {
        // 0x80189520: addiu       $t3, $a1, 0x1
        ctx->r11 = ADD32(ctx->r5, 0X1);
            goto L_80189528;
    }
    // 0x80189520: addiu       $t3, $a1, 0x1
    ctx->r11 = ADD32(ctx->r5, 0X1);
    // 0x80189524: sw          $t3, 0x134($t0)
    MEM_W(0X134, ctx->r8) = ctx->r11;
L_80189528:
    // 0x80189528: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x8018952C: lw          $v0, 0x6F94($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6F94);
    // 0x80189530: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80189534: lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // 0x80189538: beq         $v0, $zero, L_80189544
    if (ctx->r2 == 0) {
        // 0x8018953C: addiu       $t4, $v0, -0x1
        ctx->r12 = ADD32(ctx->r2, -0X1);
            goto L_80189544;
    }
    // 0x8018953C: addiu       $t4, $v0, -0x1
    ctx->r12 = ADD32(ctx->r2, -0X1);
    // 0x80189540: sw          $t4, 0x6F94($at)
    MEM_W(0X6F94, ctx->r1) = ctx->r12;
L_80189544:
    // 0x80189544: lw          $v1, 0x6F98($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6F98);
    // 0x80189548: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018954C: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x80189550: beq         $v1, $zero, L_80189564
    if (ctx->r3 == 0) {
        // 0x80189554: addiu       $t5, $v1, -0x1
        ctx->r13 = ADD32(ctx->r3, -0X1);
            goto L_80189564;
    }
    // 0x80189554: addiu       $t5, $v1, -0x1
    ctx->r13 = ADD32(ctx->r3, -0X1);
    // 0x80189558: sw          $t5, 0x6F98($at)
    MEM_W(0X6F98, ctx->r1) = ctx->r13;
    // 0x8018955C: lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // 0x80189560: lw          $v1, 0x6F98($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6F98);
L_80189564:
    // 0x80189564: lw          $v0, 0x1690($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1690);
    // 0x80189568: lui         $t6, 0x8019
    ctx->r14 = S32(0X8019 << 16);
    // 0x8018956C: bne         $v0, $zero, L_8018963C
    if (ctx->r2 != 0) {
        // 0x80189570: nop
    
            goto L_8018963C;
    }
    // 0x80189570: nop

    // 0x80189574: lw          $t6, 0x6F94($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6F94);
    // 0x80189578: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8018957C: addiu       $t1, $t1, -0x7DA0
    ctx->r9 = ADD32(ctx->r9, -0X7DA0);
    // 0x80189580: beq         $t6, $zero, L_8018963C
    if (ctx->r14 == 0) {
        // 0x80189584: nop
    
            goto L_8018963C;
    }
    // 0x80189584: nop

    // 0x80189588: lw          $t7, 0xCC($t1)
    ctx->r15 = MEM_W(ctx->r9, 0XCC);
    // 0x8018958C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80189590: bne         $t7, $zero, L_801895F8
    if (ctx->r15 != 0) {
        // 0x80189594: nop
    
            goto L_801895F8;
    }
    // 0x80189594: nop

    // 0x80189598: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018959C: lwc1        $f16, 0x7204($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7204);
    // 0x801895A0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801895A4: lwc1        $f18, 0x64B8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X64B8);
    // 0x801895A8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801895AC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801895B0: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x801895B4: swc1        $f4, 0x7204($at)
    MEM_W(0X7204, ctx->r1) = ctx->f4.u32l;
    // 0x801895B8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801895BC: lwc1        $f6, 0x720C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X720C);
    // 0x801895C0: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x801895C4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801895C8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801895CC: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x801895D0: swc1        $f10, 0x720C($at)
    MEM_W(0X720C, ctx->r1) = ctx->f10.u32l;
    // 0x801895D4: lui         $at, 0xC0C0
    ctx->r1 = S32(0XC0C0 << 16);
    // 0x801895D8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801895DC: nop

    // 0x801895E0: c.le.s      $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f4.fl <= ctx->f16.fl;
    // 0x801895E4: nop

    // 0x801895E8: bc1f        L_8018963C
    if (!c1cs) {
        // 0x801895EC: nop
    
            goto L_8018963C;
    }
    // 0x801895EC: nop

    // 0x801895F0: b           L_8018963C
    // 0x801895F4: sw          $t8, 0xCC($t1)
    MEM_W(0XCC, ctx->r9) = ctx->r24;
        goto L_8018963C;
    // 0x801895F4: sw          $t8, 0xCC($t1)
    MEM_W(0XCC, ctx->r9) = ctx->r24;
L_801895F8:
    // 0x801895F8: lwc1        $f18, 0x7204($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7204);
    // 0x801895FC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80189600: lwc1        $f6, 0x64BC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X64BC);
    // 0x80189604: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80189608: add.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x8018960C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80189610: swc1        $f8, 0x7204($at)
    MEM_W(0X7204, ctx->r1) = ctx->f8.u32l;
    // 0x80189614: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80189618: lwc1        $f10, 0x720C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X720C);
    // 0x8018961C: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x80189620: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80189624: c.le.s      $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f18.fl <= ctx->f8.fl;
    // 0x80189628: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018962C: add.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80189630: bc1f        L_8018963C
    if (!c1cs) {
        // 0x80189634: swc1        $f4, 0x720C($at)
        MEM_W(0X720C, ctx->r1) = ctx->f4.u32l;
            goto L_8018963C;
    }
    // 0x80189634: swc1        $f4, 0x720C($at)
    MEM_W(0X720C, ctx->r1) = ctx->f4.u32l;
    // 0x80189638: sw          $zero, 0xCC($t1)
    MEM_W(0XCC, ctx->r9) = 0;
L_8018963C:
    // 0x8018963C: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x80189640: bne         $v0, $zero, L_80189724
    if (ctx->r2 != 0) {
        // 0x80189644: addiu       $t1, $t1, -0x7DA0
        ctx->r9 = ADD32(ctx->r9, -0X7DA0);
            goto L_80189724;
    }
    // 0x80189644: addiu       $t1, $t1, -0x7DA0
    ctx->r9 = ADD32(ctx->r9, -0X7DA0);
    // 0x80189648: beq         $v1, $zero, L_80189724
    if (ctx->r3 == 0) {
        // 0x8018964C: nop
    
            goto L_80189724;
    }
    // 0x8018964C: nop

    // 0x80189650: lw          $t9, 0x190($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X190);
    // 0x80189654: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x80189658: addiu       $a0, $a0, 0x7454
    ctx->r4 = ADD32(ctx->r4, 0X7454);
    // 0x8018965C: bne         $t9, $zero, L_801896C4
    if (ctx->r25 != 0) {
        // 0x80189660: lui         $a1, 0x4120
        ctx->r5 = S32(0X4120 << 16);
            goto L_801896C4;
    }
    // 0x80189660: lui         $a1, 0x4120
    ctx->r5 = S32(0X4120 << 16);
    // 0x80189664: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80189668: lwc1        $f6, 0x64C0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X64C0);
    // 0x8018966C: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x80189670: lui         $a2, 0x3ECC
    ctx->r6 = S32(0X3ECC << 16);
    // 0x80189674: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80189678: addiu       $a0, $a0, 0x7454
    ctx->r4 = ADD32(ctx->r4, 0X7454);
    // 0x8018967C: lui         $a1, 0xC120
    ctx->r5 = S32(0XC120 << 16);
    // 0x80189680: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x80189684: jal         0x8009BC2C
    // 0x80189688: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_7;
    // 0x80189688: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_7:
    // 0x8018968C: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x80189690: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80189694: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80189698: lwc1        $f16, 0x7454($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7454);
    // 0x8018969C: lui         $t0, 0x8019
    ctx->r8 = S32(0X8019 << 16);
    // 0x801896A0: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x801896A4: c.le.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl <= ctx->f10.fl;
    // 0x801896A8: addiu       $t1, $t1, -0x7DA0
    ctx->r9 = ADD32(ctx->r9, -0X7DA0);
    // 0x801896AC: addiu       $t0, $t0, 0x6D08
    ctx->r8 = ADD32(ctx->r8, 0X6D08);
    // 0x801896B0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801896B4: bc1fl       L_80189714
    if (!c1cs) {
        // 0x801896B8: lw          $t3, 0xF4($t0)
        ctx->r11 = MEM_W(ctx->r8, 0XF4);
            goto L_80189714;
    }
    goto skip_2;
    // 0x801896B8: lw          $t3, 0xF4($t0)
    ctx->r11 = MEM_W(ctx->r8, 0XF4);
    skip_2:
    // 0x801896BC: b           L_80189710
    // 0x801896C0: sw          $t2, 0x190($t1)
    MEM_W(0X190, ctx->r9) = ctx->r10;
        goto L_80189710;
    // 0x801896C0: sw          $t2, 0x190($t1)
    MEM_W(0X190, ctx->r9) = ctx->r10;
L_801896C4:
    // 0x801896C4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801896C8: lwc1        $f4, 0x64C4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X64C4);
    // 0x801896CC: lui         $a2, 0x3ECC
    ctx->r6 = S32(0X3ECC << 16);
    // 0x801896D0: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801896D4: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x801896D8: jal         0x8009BC2C
    // 0x801896DC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_8;
    // 0x801896DC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_8:
    // 0x801896E0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801896E4: lwc1        $f8, 0x7454($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7454);
    // 0x801896E8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801896EC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801896F0: lui         $t0, 0x8019
    ctx->r8 = S32(0X8019 << 16);
    // 0x801896F4: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x801896F8: c.le.s      $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f18.fl <= ctx->f8.fl;
    // 0x801896FC: addiu       $t1, $t1, -0x7DA0
    ctx->r9 = ADD32(ctx->r9, -0X7DA0);
    // 0x80189700: addiu       $t0, $t0, 0x6D08
    ctx->r8 = ADD32(ctx->r8, 0X6D08);
    // 0x80189704: bc1fl       L_80189714
    if (!c1cs) {
        // 0x80189708: lw          $t3, 0xF4($t0)
        ctx->r11 = MEM_W(ctx->r8, 0XF4);
            goto L_80189714;
    }
    goto skip_3;
    // 0x80189708: lw          $t3, 0xF4($t0)
    ctx->r11 = MEM_W(ctx->r8, 0XF4);
    skip_3:
    // 0x8018970C: sw          $zero, 0x190($t1)
    MEM_W(0X190, ctx->r9) = 0;
L_80189710:
    // 0x80189710: lw          $t3, 0xF4($t0)
    ctx->r11 = MEM_W(ctx->r8, 0XF4);
L_80189714:
    // 0x80189714: lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // 0x80189718: addiu       $t4, $t3, 0x2
    ctx->r12 = ADD32(ctx->r11, 0X2);
    // 0x8018971C: sw          $t4, 0xF4($t0)
    MEM_W(0XF4, ctx->r8) = ctx->r12;
    // 0x80189720: lw          $v1, 0x6F98($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6F98);
L_80189724:
    // 0x80189724: bnel        $v1, $zero, L_80189814
    if (ctx->r3 != 0) {
        // 0x80189728: lw          $t9, 0x138($t0)
        ctx->r25 = MEM_W(ctx->r8, 0X138);
            goto L_80189814;
    }
    goto skip_4;
    // 0x80189728: lw          $t9, 0x138($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X138);
    skip_4:
    // 0x8018972C: lw          $t5, 0x138($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X138);
    // 0x80189730: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80189734: beql        $t5, $at, L_80189814
    if (ctx->r13 == ctx->r1) {
        // 0x80189738: lw          $t9, 0x138($t0)
        ctx->r25 = MEM_W(ctx->r8, 0X138);
            goto L_80189814;
    }
    goto skip_5;
    // 0x80189738: lw          $t9, 0x138($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X138);
    skip_5:
    // 0x8018973C: jal         0x8009ACDC
    // 0x80189740: lw          $a0, 0xC0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0XC0);
    Animation_GetFrameCount(rdram, ctx);
        goto after_9;
    // 0x80189740: lw          $a0, 0xC0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0XC0);
    after_9:
    // 0x80189744: lui         $t0, 0x8019
    ctx->r8 = S32(0X8019 << 16);
    // 0x80189748: addiu       $t0, $t0, 0x6D08
    ctx->r8 = ADD32(ctx->r8, 0X6D08);
    // 0x8018974C: lw          $v1, 0xF4($t0)
    ctx->r3 = MEM_W(ctx->r8, 0XF4);
    // 0x80189750: lwc1        $f16, 0xF0($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0XF0);
    // 0x80189754: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80189758: mtc1        $v1, $f6
    ctx->f6.u32l = ctx->r3;
    // 0x8018975C: addiu       $t8, $v1, 0x2
    ctx->r24 = ADD32(ctx->r3, 0X2);
    // 0x80189760: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80189764: mul.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80189768: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8018976C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80189770: nop

    // 0x80189774: cvt.w.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80189778: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8018977C: nop

    // 0x80189780: andi        $at, $t7, 0x4
    ctx->r1 = ctx->r15 & 0X4;
    // 0x80189784: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x80189788: beql        $t7, $zero, L_801897E0
    if (ctx->r15 == 0) {
        // 0x8018978C: mfc1        $t7, $f8
        ctx->r15 = (int32_t)ctx->f8.u32l;
            goto L_801897E0;
    }
    goto skip_6;
    // 0x8018978C: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    skip_6:
    // 0x80189790: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80189794: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80189798: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8018979C: sub.s       $f8, $f4, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x801897A0: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x801897A4: nop

    // 0x801897A8: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x801897AC: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x801897B0: nop

    // 0x801897B4: andi        $at, $t7, 0x4
    ctx->r1 = ctx->r15 & 0X4;
    // 0x801897B8: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x801897BC: bne         $t7, $zero, L_801897D4
    if (ctx->r15 != 0) {
        // 0x801897C0: nop
    
            goto L_801897D4;
    }
    // 0x801897C0: nop

    // 0x801897C4: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x801897C8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801897CC: b           L_801897EC
    // 0x801897D0: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_801897EC;
    // 0x801897D0: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_801897D4:
    // 0x801897D4: b           L_801897EC
    // 0x801897D8: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_801897EC;
    // 0x801897D8: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x801897DC: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
L_801897E0:
    // 0x801897E0: nop

    // 0x801897E4: bltz        $t7, L_801897D4
    if (SIGNED(ctx->r15) < 0) {
        // 0x801897E8: nop
    
            goto L_801897D4;
    }
    // 0x801897E8: nop

L_801897EC:
    // 0x801897EC: divu        $zero, $t7, $v0
    lo = S32(U32(ctx->r15) / U32(ctx->r2)); hi = S32(U32(ctx->r15) % U32(ctx->r2));
    // 0x801897F0: mfhi        $a0
    ctx->r4 = hi;
    // 0x801897F4: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x801897F8: bne         $v0, $zero, L_80189804
    if (ctx->r2 != 0) {
        // 0x801897FC: nop
    
            goto L_80189804;
    }
    // 0x801897FC: nop

    // 0x80189800: break       7
    do_break(2149095424);
L_80189804:
    // 0x80189804: beql        $a0, $zero, L_80189814
    if (ctx->r4 == 0) {
        // 0x80189808: lw          $t9, 0x138($t0)
        ctx->r25 = MEM_W(ctx->r8, 0X138);
            goto L_80189814;
    }
    goto skip_7;
    // 0x80189808: lw          $t9, 0x138($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X138);
    skip_7:
    // 0x8018980C: sw          $t8, 0xF4($t0)
    MEM_W(0XF4, ctx->r8) = ctx->r24;
    // 0x80189810: lw          $t9, 0x138($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X138);
L_80189814:
    // 0x80189814: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80189818: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8018981C: beql        $t9, $at, L_80189A50
    if (ctx->r25 == ctx->r1) {
        // 0x80189820: lui         $at, 0xC0C0
        ctx->r1 = S32(0XC0C0 << 16);
            goto L_80189A50;
    }
    goto skip_8;
    // 0x80189820: lui         $at, 0xC0C0
    ctx->r1 = S32(0XC0C0 << 16);
    skip_8:
    // 0x80189824: lw          $v0, 0x1690($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1690);
    // 0x80189828: beq         $v0, $zero, L_80189894
    if (ctx->r2 == 0) {
        // 0x8018982C: slti        $at, $v0, 0x79
        ctx->r1 = SIGNED(ctx->r2) < 0X79 ? 1 : 0;
            goto L_80189894;
    }
    // 0x8018982C: slti        $at, $v0, 0x79
    ctx->r1 = SIGNED(ctx->r2) < 0X79 ? 1 : 0;
    // 0x80189830: beq         $at, $zero, L_80189894
    if (ctx->r1 == 0) {
        // 0x80189834: lui         $a0, 0x8019
        ctx->r4 = S32(0X8019 << 16);
            goto L_80189894;
    }
    // 0x80189834: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x80189838: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018983C: lwc1        $f18, 0x64C8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X64C8);
    // 0x80189840: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x80189844: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80189848: addiu       $a0, $a0, 0x71F8
    ctx->r4 = ADD32(ctx->r4, 0X71F8);
    // 0x8018984C: lui         $a1, 0xC248
    ctx->r5 = S32(0XC248 << 16);
    // 0x80189850: lui         $a3, 0x447A
    ctx->r7 = S32(0X447A << 16);
    // 0x80189854: jal         0x8009BC2C
    // 0x80189858: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_10;
    // 0x80189858: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_10:
    // 0x8018985C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80189860: lwc1        $f6, 0x64CC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X64CC);
    // 0x80189864: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x80189868: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x8018986C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80189870: addiu       $a0, $a0, 0x7200
    ctx->r4 = ADD32(ctx->r4, 0X7200);
    // 0x80189874: lui         $a1, 0x4190
    ctx->r5 = S32(0X4190 << 16);
    // 0x80189878: lui         $a3, 0x447A
    ctx->r7 = S32(0X447A << 16);
    // 0x8018987C: jal         0x8009BC2C
    // 0x80189880: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_11;
    // 0x80189880: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_11:
    // 0x80189884: lui         $t0, 0x8019
    ctx->r8 = S32(0X8019 << 16);
    // 0x80189888: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8018988C: lw          $v0, 0x1690($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1690);
    // 0x80189890: addiu       $t0, $t0, 0x6D08
    ctx->r8 = ADD32(ctx->r8, 0X6D08);
L_80189894:
    // 0x80189894: beq         $v0, $zero, L_801898D8
    if (ctx->r2 == 0) {
        // 0x80189898: slti        $at, $v0, 0x74
        ctx->r1 = SIGNED(ctx->r2) < 0X74 ? 1 : 0;
            goto L_801898D8;
    }
    // 0x80189898: slti        $at, $v0, 0x74
    ctx->r1 = SIGNED(ctx->r2) < 0X74 ? 1 : 0;
    // 0x8018989C: beq         $at, $zero, L_801898D8
    if (ctx->r1 == 0) {
        // 0x801898A0: lui         $a0, 0x8019
        ctx->r4 = S32(0X8019 << 16);
            goto L_801898D8;
    }
    // 0x801898A0: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x801898A4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801898A8: lwc1        $f10, 0x64D0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X64D0);
    // 0x801898AC: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x801898B0: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801898B4: addiu       $a0, $a0, 0x76A8
    ctx->r4 = ADD32(ctx->r4, 0X76A8);
    // 0x801898B8: lui         $a1, 0x41A0
    ctx->r5 = S32(0X41A0 << 16);
    // 0x801898BC: lui         $a3, 0x447A
    ctx->r7 = S32(0X447A << 16);
    // 0x801898C0: jal         0x8009BC2C
    // 0x801898C4: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_12;
    // 0x801898C4: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_12:
    // 0x801898C8: lui         $t0, 0x8019
    ctx->r8 = S32(0X8019 << 16);
    // 0x801898CC: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x801898D0: lw          $v0, 0x1690($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1690);
    // 0x801898D4: addiu       $t0, $t0, 0x6D08
    ctx->r8 = ADD32(ctx->r8, 0X6D08);
L_801898D8:
    // 0x801898D8: beq         $v0, $zero, L_8018993C
    if (ctx->r2 == 0) {
        // 0x801898DC: slti        $at, $v0, 0x6F
        ctx->r1 = SIGNED(ctx->r2) < 0X6F ? 1 : 0;
            goto L_8018993C;
    }
    // 0x801898DC: slti        $at, $v0, 0x6F
    ctx->r1 = SIGNED(ctx->r2) < 0X6F ? 1 : 0;
    // 0x801898E0: beq         $at, $zero, L_8018993C
    if (ctx->r1 == 0) {
        // 0x801898E4: lui         $a0, 0x8019
        ctx->r4 = S32(0X8019 << 16);
            goto L_8018993C;
    }
    // 0x801898E4: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x801898E8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801898EC: lwc1        $f16, 0x64D4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X64D4);
    // 0x801898F0: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x801898F4: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801898F8: addiu       $a0, $a0, 0x7450
    ctx->r4 = ADD32(ctx->r4, 0X7450);
    // 0x801898FC: lui         $a1, 0x41A0
    ctx->r5 = S32(0X41A0 << 16);
    // 0x80189900: lui         $a3, 0x447A
    ctx->r7 = S32(0X447A << 16);
    // 0x80189904: jal         0x8009BC2C
    // 0x80189908: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_13;
    // 0x80189908: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_13:
    // 0x8018990C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80189910: lwc1        $f4, 0x64D8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X64D8);
    // 0x80189914: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x80189918: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x8018991C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80189920: addiu       $a0, $a0, 0x7454
    ctx->r4 = ADD32(ctx->r4, 0X7454);
    // 0x80189924: lui         $a1, 0x41A0
    ctx->r5 = S32(0X41A0 << 16);
    // 0x80189928: lui         $a3, 0x447A
    ctx->r7 = S32(0X447A << 16);
    // 0x8018992C: jal         0x8009BC2C
    // 0x80189930: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_14;
    // 0x80189930: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_14:
    // 0x80189934: lui         $t0, 0x8019
    ctx->r8 = S32(0X8019 << 16);
    // 0x80189938: addiu       $t0, $t0, 0x6D08
    ctx->r8 = ADD32(ctx->r8, 0X6D08);
L_8018993C:
    // 0x8018993C: lui         $t2, 0x8019
    ctx->r10 = S32(0X8019 << 16);
    // 0x80189940: lw          $t2, 0x6F94($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X6F94);
    // 0x80189944: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x80189948: bne         $t2, $zero, L_801899B0
    if (ctx->r10 != 0) {
        // 0x8018994C: nop
    
            goto L_801899B0;
    }
    // 0x8018994C: nop

    // 0x80189950: lw          $t3, 0x1690($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X1690);
    // 0x80189954: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x80189958: addiu       $a0, $a0, 0x71F8
    ctx->r4 = ADD32(ctx->r4, 0X71F8);
    // 0x8018995C: bne         $t3, $zero, L_801899B0
    if (ctx->r11 != 0) {
        // 0x80189960: addiu       $a1, $zero, 0x0
        ctx->r5 = ADD32(0, 0X0);
            goto L_801899B0;
    }
    // 0x80189960: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80189964: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80189968: lwc1        $f8, 0x64DC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X64DC);
    // 0x8018996C: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x80189970: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80189974: lui         $a3, 0x447A
    ctx->r7 = S32(0X447A << 16);
    // 0x80189978: jal         0x8009BC2C
    // 0x8018997C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_15;
    // 0x8018997C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_15:
    // 0x80189980: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80189984: lwc1        $f18, 0x64E0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X64E0);
    // 0x80189988: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018998C: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x80189990: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80189994: addiu       $a0, $a0, 0x7200
    ctx->r4 = ADD32(ctx->r4, 0X7200);
    // 0x80189998: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8018999C: lui         $a3, 0x447A
    ctx->r7 = S32(0X447A << 16);
    // 0x801899A0: jal         0x8009BC2C
    // 0x801899A4: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_16;
    // 0x801899A4: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_16:
    // 0x801899A8: lui         $t0, 0x8019
    ctx->r8 = S32(0X8019 << 16);
    // 0x801899AC: addiu       $t0, $t0, 0x6D08
    ctx->r8 = ADD32(ctx->r8, 0X6D08);
L_801899B0:
    // 0x801899B0: lui         $t4, 0x8019
    ctx->r12 = S32(0X8019 << 16);
    // 0x801899B4: lw          $t4, 0x6F98($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X6F98);
    // 0x801899B8: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x801899BC: bnel        $t4, $zero, L_80189A50
    if (ctx->r12 != 0) {
        // 0x801899C0: lui         $at, 0xC0C0
        ctx->r1 = S32(0XC0C0 << 16);
            goto L_80189A50;
    }
    goto skip_9;
    // 0x801899C0: lui         $at, 0xC0C0
    ctx->r1 = S32(0XC0C0 << 16);
    skip_9:
    // 0x801899C4: lw          $t5, 0x1690($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X1690);
    // 0x801899C8: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x801899CC: addiu       $a0, $a0, 0x76A8
    ctx->r4 = ADD32(ctx->r4, 0X76A8);
    // 0x801899D0: bne         $t5, $zero, L_80189A4C
    if (ctx->r13 != 0) {
        // 0x801899D4: addiu       $a1, $zero, 0x0
        ctx->r5 = ADD32(0, 0X0);
            goto L_80189A4C;
    }
    // 0x801899D4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x801899D8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801899DC: lwc1        $f6, 0x64E4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X64E4);
    // 0x801899E0: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x801899E4: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801899E8: lui         $a3, 0x447A
    ctx->r7 = S32(0X447A << 16);
    // 0x801899EC: jal         0x8009BC2C
    // 0x801899F0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_17;
    // 0x801899F0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_17:
    // 0x801899F4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801899F8: lwc1        $f10, 0x64E8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X64E8);
    // 0x801899FC: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x80189A00: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x80189A04: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80189A08: addiu       $a0, $a0, 0x7450
    ctx->r4 = ADD32(ctx->r4, 0X7450);
    // 0x80189A0C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80189A10: lui         $a3, 0x447A
    ctx->r7 = S32(0X447A << 16);
    // 0x80189A14: jal         0x8009BC2C
    // 0x80189A18: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_18;
    // 0x80189A18: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_18:
    // 0x80189A1C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80189A20: lwc1        $f16, 0x64EC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X64EC);
    // 0x80189A24: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x80189A28: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x80189A2C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80189A30: addiu       $a0, $a0, 0x7454
    ctx->r4 = ADD32(ctx->r4, 0X7454);
    // 0x80189A34: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80189A38: lui         $a3, 0x447A
    ctx->r7 = S32(0X447A << 16);
    // 0x80189A3C: jal         0x8009BC2C
    // 0x80189A40: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_19;
    // 0x80189A40: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_19:
    // 0x80189A44: lui         $t0, 0x8019
    ctx->r8 = S32(0X8019 << 16);
    // 0x80189A48: addiu       $t0, $t0, 0x6D08
    ctx->r8 = ADD32(ctx->r8, 0X6D08);
L_80189A4C:
    // 0x80189A4C: lui         $at, 0xC0C0
    ctx->r1 = S32(0XC0C0 << 16);
L_80189A50:
    // 0x80189A50: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80189A54: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80189A58: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x80189A5C: swc1        $f4, 0x7470($at)
    MEM_W(0X7470, ctx->r1) = ctx->f4.u32l;
    // 0x80189A60: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80189A64: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80189A68: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80189A6C: swc1        $f8, 0x7458($at)
    MEM_W(0X7458, ctx->r1) = ctx->f8.u32l;
    // 0x80189A70: lw          $t6, 0x138($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X138);
    // 0x80189A74: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80189A78: bnel        $t6, $at, L_80189C58
    if (ctx->r14 != ctx->r1) {
        // 0x80189A7C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80189C58;
    }
    goto skip_10;
    // 0x80189A7C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_10:
    // 0x80189A80: lw          $t7, 0x7A80($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7A80);
    // 0x80189A84: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x80189A88: addiu       $a0, $a0, 0x71F8
    ctx->r4 = ADD32(ctx->r4, 0X71F8);
    // 0x80189A8C: slti        $at, $t7, 0x3C
    ctx->r1 = SIGNED(ctx->r15) < 0X3C ? 1 : 0;
    // 0x80189A90: bne         $at, $zero, L_80189C54
    if (ctx->r1 != 0) {
        // 0x80189A94: lui         $a1, 0xC220
        ctx->r5 = S32(0XC220 << 16);
            goto L_80189C54;
    }
    // 0x80189A94: lui         $a1, 0xC220
    ctx->r5 = S32(0XC220 << 16);
    // 0x80189A98: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80189A9C: lwc1        $f18, 0x64F0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X64F0);
    // 0x80189AA0: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x80189AA4: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80189AA8: lui         $a3, 0x447A
    ctx->r7 = S32(0X447A << 16);
    // 0x80189AAC: jal         0x8009BC2C
    // 0x80189AB0: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_20;
    // 0x80189AB0: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_20:
    // 0x80189AB4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80189AB8: lwc1        $f6, 0x64F4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X64F4);
    // 0x80189ABC: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x80189AC0: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x80189AC4: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80189AC8: addiu       $a0, $a0, 0x7200
    ctx->r4 = ADD32(ctx->r4, 0X7200);
    // 0x80189ACC: lui         $a1, 0x4190
    ctx->r5 = S32(0X4190 << 16);
    // 0x80189AD0: lui         $a3, 0x447A
    ctx->r7 = S32(0X447A << 16);
    // 0x80189AD4: jal         0x8009BC2C
    // 0x80189AD8: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_21;
    // 0x80189AD8: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_21:
    // 0x80189ADC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80189AE0: lwc1        $f10, 0x64F8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X64F8);
    // 0x80189AE4: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x80189AE8: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x80189AEC: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80189AF0: addiu       $a0, $a0, 0x7234
    ctx->r4 = ADD32(ctx->r4, 0X7234);
    // 0x80189AF4: lui         $a1, 0xC140
    ctx->r5 = S32(0XC140 << 16);
    // 0x80189AF8: lui         $a3, 0x447A
    ctx->r7 = S32(0X447A << 16);
    // 0x80189AFC: jal         0x8009BC2C
    // 0x80189B00: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_22;
    // 0x80189B00: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_22:
    // 0x80189B04: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80189B08: lwc1        $f16, 0x64FC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X64FC);
    // 0x80189B0C: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x80189B10: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x80189B14: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80189B18: addiu       $a0, $a0, 0x723C
    ctx->r4 = ADD32(ctx->r4, 0X723C);
    // 0x80189B1C: lui         $a1, 0xC0C0
    ctx->r5 = S32(0XC0C0 << 16);
    // 0x80189B20: lui         $a3, 0x447A
    ctx->r7 = S32(0X447A << 16);
    // 0x80189B24: jal         0x8009BC2C
    // 0x80189B28: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_23;
    // 0x80189B28: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_23:
    // 0x80189B2C: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x80189B30: lw          $t8, 0x7A80($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7A80);
    // 0x80189B34: lui         $t0, 0x8019
    ctx->r8 = S32(0X8019 << 16);
    // 0x80189B38: addiu       $t0, $t0, 0x6D08
    ctx->r8 = ADD32(ctx->r8, 0X6D08);
    // 0x80189B3C: slti        $at, $t8, 0x5B
    ctx->r1 = SIGNED(ctx->r24) < 0X5B ? 1 : 0;
    // 0x80189B40: beq         $at, $zero, L_80189B58
    if (ctx->r1 == 0) {
        // 0x80189B44: nop
    
            goto L_80189B58;
    }
    // 0x80189B44: nop

    // 0x80189B48: lw          $t9, 0xF4($t0)
    ctx->r25 = MEM_W(ctx->r8, 0XF4);
    // 0x80189B4C: addiu       $t2, $t9, 0x2
    ctx->r10 = ADD32(ctx->r25, 0X2);
    // 0x80189B50: b           L_80189C2C
    // 0x80189B54: sw          $t2, 0xF4($t0)
    MEM_W(0XF4, ctx->r8) = ctx->r10;
        goto L_80189C2C;
    // 0x80189B54: sw          $t2, 0xF4($t0)
    MEM_W(0XF4, ctx->r8) = ctx->r10;
L_80189B58:
    // 0x80189B58: jal         0x8009ACDC
    // 0x80189B5C: lw          $a0, 0xC0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0XC0);
    Animation_GetFrameCount(rdram, ctx);
        goto after_24;
    // 0x80189B5C: lw          $a0, 0xC0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0XC0);
    after_24:
    // 0x80189B60: lui         $t0, 0x8019
    ctx->r8 = S32(0X8019 << 16);
    // 0x80189B64: addiu       $t0, $t0, 0x6D08
    ctx->r8 = ADD32(ctx->r8, 0X6D08);
    // 0x80189B68: lw          $v1, 0xF4($t0)
    ctx->r3 = MEM_W(ctx->r8, 0XF4);
    // 0x80189B6C: lwc1        $f18, 0xF0($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0XF0);
    // 0x80189B70: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80189B74: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x80189B78: addiu       $t5, $v1, 0x2
    ctx->r13 = ADD32(ctx->r3, 0X2);
    // 0x80189B7C: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80189B80: mul.s       $f6, $f8, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x80189B84: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80189B88: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80189B8C: nop

    // 0x80189B90: cvt.w.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80189B94: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80189B98: nop

    // 0x80189B9C: andi        $at, $t4, 0x4
    ctx->r1 = ctx->r12 & 0X4;
    // 0x80189BA0: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x80189BA4: beql        $t4, $zero, L_80189BFC
    if (ctx->r12 == 0) {
        // 0x80189BA8: mfc1        $t4, $f10
        ctx->r12 = (int32_t)ctx->f10.u32l;
            goto L_80189BFC;
    }
    goto skip_11;
    // 0x80189BA8: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    skip_11:
    // 0x80189BAC: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80189BB0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80189BB4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80189BB8: sub.s       $f10, $f6, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80189BBC: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80189BC0: nop

    // 0x80189BC4: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80189BC8: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80189BCC: nop

    // 0x80189BD0: andi        $at, $t4, 0x4
    ctx->r1 = ctx->r12 & 0X4;
    // 0x80189BD4: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x80189BD8: bne         $t4, $zero, L_80189BF0
    if (ctx->r12 != 0) {
        // 0x80189BDC: nop
    
            goto L_80189BF0;
    }
    // 0x80189BDC: nop

    // 0x80189BE0: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x80189BE4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80189BE8: b           L_80189C08
    // 0x80189BEC: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
        goto L_80189C08;
    // 0x80189BEC: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
L_80189BF0:
    // 0x80189BF0: b           L_80189C08
    // 0x80189BF4: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
        goto L_80189C08;
    // 0x80189BF4: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80189BF8: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
L_80189BFC:
    // 0x80189BFC: nop

    // 0x80189C00: bltz        $t4, L_80189BF0
    if (SIGNED(ctx->r12) < 0) {
        // 0x80189C04: nop
    
            goto L_80189BF0;
    }
    // 0x80189C04: nop

L_80189C08:
    // 0x80189C08: divu        $zero, $t4, $v0
    lo = S32(U32(ctx->r12) / U32(ctx->r2)); hi = S32(U32(ctx->r12) % U32(ctx->r2));
    // 0x80189C0C: mfhi        $a0
    ctx->r4 = hi;
    // 0x80189C10: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80189C14: bne         $v0, $zero, L_80189C20
    if (ctx->r2 != 0) {
        // 0x80189C18: nop
    
            goto L_80189C20;
    }
    // 0x80189C18: nop

    // 0x80189C1C: break       7
    do_break(2149096476);
L_80189C20:
    // 0x80189C20: beq         $a0, $zero, L_80189C2C
    if (ctx->r4 == 0) {
        // 0x80189C24: nop
    
            goto L_80189C2C;
    }
    // 0x80189C24: nop

    // 0x80189C28: sw          $t5, 0xF4($t0)
    MEM_W(0XF4, ctx->r8) = ctx->r13;
L_80189C2C:
    // 0x80189C2C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80189C30: lwc1        $f16, 0x6500($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6500);
    // 0x80189C34: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x80189C38: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x80189C3C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80189C40: addiu       $a0, $a0, 0x76A8
    ctx->r4 = ADD32(ctx->r4, 0X76A8);
    // 0x80189C44: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80189C48: lui         $a3, 0x447A
    ctx->r7 = S32(0X447A << 16);
    // 0x80189C4C: jal         0x8009BC2C
    // 0x80189C50: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_25;
    // 0x80189C50: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_25:
L_80189C54:
    // 0x80189C54: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80189C58:
    // 0x80189C58: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80189C5C: jr          $ra
    // 0x80189C60: nop

    return;
    // 0x80189C60: nop

;}
RECOMP_FUNC void Ending_80191700(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80191700: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80191704: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80191708: jr          $ra
    // 0x8019170C: nop

    return;
    // 0x8019170C: nop

;}
RECOMP_FUNC void Ending_80190778(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80190778: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8019077C: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x80190780: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x80190784: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x80190788: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x8019078C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80190790: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80190794: addiu       $s2, $s2, 0x7E64
    ctx->r18 = ADD32(ctx->r18, 0X7E64);
    // 0x80190798: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8019079C: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x801907A0: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x801907A4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x801907A8: jal         0x800B8DD0
    // 0x801907AC: lh          $a1, 0x8($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X8);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x801907AC: lh          $a1, 0x8($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X8);
    after_0:
    // 0x801907B0: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x801907B4: lui         $t7, 0xBC00
    ctx->r15 = S32(0XBC00 << 16);
    // 0x801907B8: ori         $t7, $t7, 0x8
    ctx->r15 = ctx->r15 | 0X8;
    // 0x801907BC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801907C0: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
    // 0x801907C4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801907C8: lh          $t8, 0x66($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X66);
    // 0x801907CC: lh          $a0, 0x64($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X64);
    // 0x801907D0: lui         $t9, 0x1
    ctx->r25 = S32(0X1 << 16);
    // 0x801907D4: ori         $t9, $t9, 0xF400
    ctx->r25 = ctx->r25 | 0XF400;
    // 0x801907D8: subu        $a1, $t8, $a0
    ctx->r5 = SUB32(ctx->r24, ctx->r4);
    // 0x801907DC: div         $zero, $t9, $a1
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r5)));
    // 0x801907E0: negu        $t4, $a0
    ctx->r12 = SUB32(0, ctx->r4);
    // 0x801907E4: sll         $t5, $t4, 8
    ctx->r13 = S32(ctx->r12 << 8);
    // 0x801907E8: addu        $t6, $t5, $t9
    ctx->r14 = ADD32(ctx->r13, ctx->r25);
    // 0x801907EC: mflo        $t1
    ctx->r9 = lo;
    // 0x801907F0: andi        $t2, $t1, 0xFFFF
    ctx->r10 = ctx->r9 & 0XFFFF;
    // 0x801907F4: sll         $t3, $t2, 16
    ctx->r11 = S32(ctx->r10 << 16);
    // 0x801907F8: div         $zero, $t6, $a1
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r5)));
    // 0x801907FC: mflo        $t7
    ctx->r15 = lo;
    // 0x80190800: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x80190804: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80190808: bne         $a1, $zero, L_80190814
    if (ctx->r5 != 0) {
        // 0x8019080C: nop
    
            goto L_80190814;
    }
    // 0x8019080C: nop

    // 0x80190810: break       7
    do_break(2149124112);
L_80190814:
    // 0x80190814: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80190818: bne         $a1, $at, L_8019082C
    if (ctx->r5 != ctx->r1) {
        // 0x8019081C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8019082C;
    }
    // 0x8019081C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80190820: bne         $t9, $at, L_8019082C
    if (ctx->r25 != ctx->r1) {
        // 0x80190824: nop
    
            goto L_8019082C;
    }
    // 0x80190824: nop

    // 0x80190828: break       6
    do_break(2149124136);
L_8019082C:
    // 0x8019082C: addu        $at, $t9, $zero
    ctx->r1 = ADD32(ctx->r25, 0);
    // 0x80190830: or          $t9, $t3, $t8
    ctx->r25 = ctx->r11 | ctx->r24;
    // 0x80190834: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80190838: bne         $a1, $zero, L_80190844
    if (ctx->r5 != 0) {
        // 0x8019083C: nop
    
            goto L_80190844;
    }
    // 0x8019083C: nop

    // 0x80190840: break       7
    do_break(2149124160);
L_80190844:
    // 0x80190844: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80190848: bne         $a1, $at, L_8019085C
    if (ctx->r5 != ctx->r1) {
        // 0x8019084C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8019085C;
    }
    // 0x8019084C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80190850: bne         $t6, $at, L_8019085C
    if (ctx->r14 != ctx->r1) {
        // 0x80190854: nop
    
            goto L_8019085C;
    }
    // 0x80190854: nop

    // 0x80190858: break       6
    do_break(2149124184);
L_8019085C:
    // 0x8019085C: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80190860: lui         $t2, 0xF800
    ctx->r10 = S32(0XF800 << 16);
    // 0x80190864: lui         $s3, 0x8014
    ctx->r19 = S32(0X8014 << 16);
    // 0x80190868: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x8019086C: sw          $t1, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r9;
    // 0x80190870: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x80190874: lbu         $t3, 0x61($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X61);
    // 0x80190878: lbu         $t5, 0x60($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X60);
    // 0x8019087C: lbu         $t2, 0x62($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X62);
    // 0x80190880: sll         $t8, $t3, 16
    ctx->r24 = S32(ctx->r11 << 16);
    // 0x80190884: sll         $t6, $t5, 24
    ctx->r14 = S32(ctx->r13 << 24);
    // 0x80190888: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x8019088C: sll         $t4, $t2, 8
    ctx->r12 = S32(ctx->r10 << 8);
    // 0x80190890: or          $t5, $t9, $t4
    ctx->r13 = ctx->r25 | ctx->r12;
    // 0x80190894: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x80190898: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x8019089C: lui         $t3, 0xFB00
    ctx->r11 = S32(0XFB00 << 16);
    // 0x801908A0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801908A4: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    // 0x801908A8: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x801908AC: lbu         $t9, 0x69($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X69);
    // 0x801908B0: lbu         $t8, 0x68($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X68);
    // 0x801908B4: lbu         $t3, 0x6A($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X6A);
    // 0x801908B8: sll         $t4, $t9, 16
    ctx->r12 = S32(ctx->r25 << 16);
    // 0x801908BC: lbu         $t9, 0x6B($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X6B);
    // 0x801908C0: sll         $t1, $t8, 24
    ctx->r9 = S32(ctx->r24 << 24);
    // 0x801908C4: or          $t5, $t1, $t4
    ctx->r13 = ctx->r9 | ctx->r12;
    // 0x801908C8: sll         $t6, $t3, 8
    ctx->r14 = S32(ctx->r11 << 8);
    // 0x801908CC: or          $t8, $t5, $t6
    ctx->r24 = ctx->r13 | ctx->r14;
    // 0x801908D0: or          $t1, $t8, $t9
    ctx->r9 = ctx->r24 | ctx->r25;
    // 0x801908D4: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x801908D8: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x801908DC: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x801908E0: addiu       $s3, $s3, -0x4C40
    ctx->r19 = ADD32(ctx->r19, -0X4C40);
    // 0x801908E4: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x801908E8: sw          $t4, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r12;
    // 0x801908EC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801908F0: lbu         $t8, 0x6D($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X6D);
    // 0x801908F4: lbu         $t5, 0x6C($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X6C);
    // 0x801908F8: lbu         $t7, 0x6E($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X6E);
    // 0x801908FC: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x80190900: lbu         $t8, 0x6F($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X6F);
    // 0x80190904: sll         $t6, $t5, 24
    ctx->r14 = S32(ctx->r13 << 24);
    // 0x80190908: or          $t1, $t6, $t9
    ctx->r9 = ctx->r14 | ctx->r25;
    // 0x8019090C: sll         $t3, $t7, 8
    ctx->r11 = S32(ctx->r15 << 8);
    // 0x80190910: or          $t5, $t1, $t3
    ctx->r13 = ctx->r9 | ctx->r11;
    // 0x80190914: or          $t6, $t5, $t8
    ctx->r14 = ctx->r13 | ctx->r24;
    // 0x80190918: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8019091C: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    // 0x80190920: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x80190924: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80190928: subu        $t4, $s1, $t9
    ctx->r12 = SUB32(ctx->r17, ctx->r25);
    // 0x8019092C: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x80190930: bgez        $t4, L_80190944
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80190934: cvt.s.w     $f0, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80190944;
    }
    // 0x80190934: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80190938: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8019093C: nop

    // 0x80190940: add.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f6.fl;
L_80190944:
    // 0x80190944: lwc1        $f10, 0x3C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x80190948: lwc1        $f8, 0x18($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8019094C: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80190950: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80190954: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80190958: lwc1        $f4, 0x1C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x8019095C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80190960: sub.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80190964: lwc1        $f6, 0x44($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X44);
    // 0x80190968: lwc1        $f4, 0x20($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X20);
    // 0x8019096C: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x80190970: lwc1        $f8, 0x40($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X40);
    // 0x80190974: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80190978: mul.s       $f16, $f0, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8019097C: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80190980: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80190984: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80190988: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8019098C: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80190990: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x80190994: jal         0x80005B00
    // 0x80190998: nop

    Matrix_Translate(rdram, ctx);
        goto after_1;
    // 0x80190998: nop

    after_1:
    // 0x8019099C: lw          $a1, 0x30($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X30);
    // 0x801909A0: lw          $a2, 0x34($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X34);
    // 0x801909A4: lw          $a3, 0x38($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X38);
    // 0x801909A8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801909AC: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x801909B0: jal         0x80005C34
    // 0x801909B4: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_2;
    // 0x801909B4: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    after_2:
    // 0x801909B8: mtc1        $s1, $f16
    ctx->f16.u32l = ctx->r17;
    // 0x801909BC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801909C0: bgez        $s1, L_801909D4
    if (SIGNED(ctx->r17) >= 0) {
        // 0x801909C4: cvt.s.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
            goto L_801909D4;
    }
    // 0x801909C4: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x801909C8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801909CC: nop

    // 0x801909D0: add.s       $f18, $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f6.fl;
L_801909D4:
    // 0x801909D4: lbu         $t3, 0x70($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X70);
    // 0x801909D8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801909DC: lwc1        $f4, 0x6C84($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6C84);
    // 0x801909E0: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x801909E4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801909E8: mul.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x801909EC: bgez        $t3, L_80190A00
    if (SIGNED(ctx->r11) >= 0) {
        // 0x801909F0: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_80190A00;
    }
    // 0x801909F0: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801909F4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801909F8: nop

    // 0x801909FC: add.s       $f16, $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f6.fl;
L_80190A00:
    // 0x80190A00: jal         0x80023090
    // 0x80190A04: add.s       $f12, $f8, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f16.fl;
    __sinf_recomp(rdram, ctx);
        goto after_3;
    // 0x80190A04: add.s       $f12, $f8, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f16.fl;
    after_3:
    // 0x80190A08: lbu         $t2, 0x71($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X71);
    // 0x80190A0C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80190A10: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80190A14: bnel        $t2, $at, L_80190B6C
    if (ctx->r10 != ctx->r1) {
        // 0x80190A18: lwc1        $f16, 0x58($s0)
        ctx->f16.u32l = MEM_W(ctx->r16, 0X58);
            goto L_80190B6C;
    }
    goto skip_0;
    // 0x80190A18: lwc1        $f16, 0x58($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X58);
    skip_0:
    // 0x80190A1C: lwc1        $f6, 0x58($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80190A20: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80190A24: lwc1        $f4, -0x7A0C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7A0C);
    // 0x80190A28: lwc1        $f18, 0x28($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X28);
    // 0x80190A2C: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80190A30: lw          $t5, 0xC($s0)
    ctx->r13 = MEM_W(ctx->r16, 0XC);
    // 0x80190A34: sub.s       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80190A38: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80190A3C: subu        $t8, $s1, $t5
    ctx->r24 = SUB32(ctx->r17, ctx->r13);
    // 0x80190A40: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x80190A44: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x80190A48: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80190A4C: bgez        $t8, L_80190A60
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80190A50: cvt.s.w     $f4, $f18
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
            goto L_80190A60;
    }
    // 0x80190A50: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80190A54: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80190A58: nop

    // 0x80190A5C: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_80190A60:
    // 0x80190A60: lwc1        $f10, 0x4C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x80190A64: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80190A68: lwc1        $f6, 0x6C88($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6C88);
    // 0x80190A6C: mul.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x80190A70: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80190A74: add.s       $f18, $f16, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x80190A78: mul.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x80190A7C: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80190A80: jal         0x80005E90
    // 0x80190A84: nop

    Matrix_RotateY(rdram, ctx);
        goto after_4;
    // 0x80190A84: nop

    after_4:
    // 0x80190A88: lwc1        $f18, 0x54($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80190A8C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80190A90: lwc1        $f16, -0x7A10($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X7A10);
    // 0x80190A94: lwc1        $f10, 0x24($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80190A98: mul.s       $f6, $f20, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f18.fl);
    // 0x80190A9C: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x80190AA0: sub.s       $f8, $f10, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80190AA4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80190AA8: subu        $t9, $s1, $t6
    ctx->r25 = SUB32(ctx->r17, ctx->r14);
    // 0x80190AAC: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x80190AB0: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x80190AB4: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80190AB8: bgez        $t9, L_80190ACC
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80190ABC: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_80190ACC;
    }
    // 0x80190ABC: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80190AC0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80190AC4: nop

    // 0x80190AC8: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_80190ACC:
    // 0x80190ACC: lwc1        $f8, 0x48($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80190AD0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80190AD4: lwc1        $f18, 0x6C8C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6C8C);
    // 0x80190AD8: mul.s       $f6, $f16, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f8.fl);
    // 0x80190ADC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80190AE0: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80190AE4: mul.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80190AE8: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x80190AEC: jal         0x80005D44
    // 0x80190AF0: nop

    Matrix_RotateX(rdram, ctx);
        goto after_5;
    // 0x80190AF0: nop

    after_5:
    // 0x80190AF4: lwc1        $f10, 0x5C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X5C);
    // 0x80190AF8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80190AFC: lwc1        $f4, -0x7A08($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7A08);
    // 0x80190B00: lwc1        $f8, 0x2C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80190B04: mul.s       $f18, $f20, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f20.fl, ctx->f10.fl);
    // 0x80190B08: lw          $t4, 0xC($s0)
    ctx->r12 = MEM_W(ctx->r16, 0XC);
    // 0x80190B0C: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80190B10: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80190B14: subu        $t7, $s1, $t4
    ctx->r15 = SUB32(ctx->r17, ctx->r12);
    // 0x80190B18: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x80190B1C: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x80190B20: add.s       $f16, $f6, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x80190B24: bgez        $t7, L_80190B38
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80190B28: cvt.s.w     $f4, $f8
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
            goto L_80190B38;
    }
    // 0x80190B28: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80190B2C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80190B30: nop

    // 0x80190B34: add.s       $f4, $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f10.fl;
L_80190B38:
    // 0x80190B38: lwc1        $f6, 0x50($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80190B3C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80190B40: lwc1        $f10, 0x6C90($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6C90);
    // 0x80190B44: mul.s       $f18, $f4, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80190B48: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80190B4C: add.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80190B50: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80190B54: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80190B58: jal         0x80005FE0
    // 0x80190B5C: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_6;
    // 0x80190B5C: nop

    after_6:
    // 0x80190B60: b           L_80190C8C
    // 0x80190B64: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
        goto L_80190C8C;
    // 0x80190B64: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80190B68: lwc1        $f16, 0x58($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X58);
L_80190B6C:
    // 0x80190B6C: lw          $t1, 0xC($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XC);
    // 0x80190B70: lwc1        $f6, 0x28($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X28);
    // 0x80190B74: mul.s       $f18, $f20, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f20.fl, ctx->f16.fl);
    // 0x80190B78: subu        $t3, $s1, $t1
    ctx->r11 = SUB32(ctx->r17, ctx->r9);
    // 0x80190B7C: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x80190B80: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x80190B84: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80190B88: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80190B8C: bgez        $t3, L_80190BA0
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80190B90: add.s       $f8, $f6, $f18
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f18.fl;
            goto L_80190BA0;
    }
    // 0x80190B90: add.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x80190B94: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80190B98: nop

    // 0x80190B9C: add.s       $f4, $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f16.fl;
L_80190BA0:
    // 0x80190BA0: lwc1        $f6, 0x4C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x80190BA4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80190BA8: lwc1        $f16, 0x6C94($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6C94);
    // 0x80190BAC: mul.s       $f18, $f4, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80190BB0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80190BB4: add.s       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x80190BB8: mul.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80190BBC: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80190BC0: jal         0x80005E90
    // 0x80190BC4: nop

    Matrix_RotateY(rdram, ctx);
        goto after_7;
    // 0x80190BC4: nop

    after_7:
    // 0x80190BC8: lwc1        $f8, 0x54($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80190BCC: lw          $t2, 0xC($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XC);
    // 0x80190BD0: lwc1        $f6, 0x24($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80190BD4: mul.s       $f18, $f20, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f20.fl, ctx->f8.fl);
    // 0x80190BD8: subu        $t5, $s1, $t2
    ctx->r13 = SUB32(ctx->r17, ctx->r10);
    // 0x80190BDC: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x80190BE0: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x80190BE4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80190BE8: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80190BEC: bgez        $t5, L_80190C00
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80190BF0: add.s       $f10, $f6, $f18
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f18.fl;
            goto L_80190C00;
    }
    // 0x80190BF0: add.s       $f10, $f6, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x80190BF4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80190BF8: nop

    // 0x80190BFC: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
L_80190C00:
    // 0x80190C00: lwc1        $f6, 0x48($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80190C04: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80190C08: lwc1        $f8, 0x6C98($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6C98);
    // 0x80190C0C: mul.s       $f18, $f4, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80190C10: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80190C14: add.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x80190C18: mul.s       $f4, $f16, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f8.fl);
    // 0x80190C1C: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80190C20: jal         0x80005D44
    // 0x80190C24: nop

    Matrix_RotateX(rdram, ctx);
        goto after_8;
    // 0x80190C24: nop

    after_8:
    // 0x80190C28: lwc1        $f10, 0x5C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X5C);
    // 0x80190C2C: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    // 0x80190C30: lwc1        $f6, 0x2C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80190C34: mul.s       $f18, $f20, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f20.fl, ctx->f10.fl);
    // 0x80190C38: subu        $t6, $s1, $t8
    ctx->r14 = SUB32(ctx->r17, ctx->r24);
    // 0x80190C3C: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x80190C40: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x80190C44: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80190C48: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80190C4C: bgez        $t6, L_80190C60
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80190C50: add.s       $f16, $f6, $f18
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f18.fl;
            goto L_80190C60;
    }
    // 0x80190C50: add.s       $f16, $f6, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x80190C54: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80190C58: nop

    // 0x80190C5C: add.s       $f4, $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f10.fl;
L_80190C60:
    // 0x80190C60: lwc1        $f6, 0x50($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80190C64: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80190C68: lwc1        $f10, 0x6C9C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6C9C);
    // 0x80190C6C: mul.s       $f18, $f4, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80190C70: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80190C74: add.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80190C78: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80190C7C: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80190C80: jal         0x80005FE0
    // 0x80190C84: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_9;
    // 0x80190C84: nop

    after_9:
    // 0x80190C88: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_80190C8C:
    // 0x80190C8C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80190C90: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80190C94: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80190C98: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80190C9C: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x80190CA0: jal         0x80005B00
    // 0x80190CA4: lui         $a2, 0x43F0
    ctx->r6 = S32(0X43F0 << 16);
    Matrix_Translate(rdram, ctx);
        goto after_10;
    // 0x80190CA4: lui         $a2, 0x43F0
    ctx->r6 = S32(0X43F0 << 16);
    after_10:
    // 0x80190CA8: jal         0x80006EB8
    // 0x80190CAC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_11;
    // 0x80190CAC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_11:
    // 0x80190CB0: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80190CB4: lui         $t1, 0x300
    ctx->r9 = S32(0X300 << 16);
    // 0x80190CB8: addiu       $t1, $t1, 0x5AB0
    ctx->r9 = ADD32(ctx->r9, 0X5AB0);
    // 0x80190CBC: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x80190CC0: sw          $t4, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r12;
    // 0x80190CC4: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80190CC8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80190CCC: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x80190CD0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80190CD4: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80190CD8: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x80190CDC: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x80190CE0: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x80190CE4: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x80190CE8: jr          $ra
    // 0x80190CEC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80190CEC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void Ending_8018A828(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018A828: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018A82C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018A830: lui         $t6, 0x8019
    ctx->r14 = S32(0X8019 << 16);
    // 0x8018A834: lw          $t6, 0x6F8C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6F8C);
    // 0x8018A838: addiu       $t7, $t6, -0x2
    ctx->r15 = ADD32(ctx->r14, -0X2);
    // 0x8018A83C: sltiu       $at, $t7, 0x7
    ctx->r1 = ctx->r15 < 0X7 ? 1 : 0;
    // 0x8018A840: beq         $at, $zero, L_8018A8EC
    if (ctx->r1 == 0) {
        // 0x8018A844: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_8018A8EC;
    }
    // 0x8018A844: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8018A848: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018A84C: addu        $at, $at, $t7
    gpr jr_addend_8018A854 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8018A850: lw          $t7, 0x658C($at)
    ctx->r15 = ADD32(ctx->r1, 0X658C);
    // 0x8018A854: jr          $t7
    // 0x8018A858: nop

    switch (jr_addend_8018A854 >> 2) {
        case 0: goto L_8018A85C; break;
        case 1: goto L_8018A8EC; break;
        case 2: goto L_8018A880; break;
        case 3: goto L_8018A8EC; break;
        case 4: goto L_8018A8A4; break;
        case 5: goto L_8018A8B4; break;
        case 6: goto L_8018A8B4; break;
        default: switch_error(__func__, 0x8018A854, 0x8019658C);
    }
    // 0x8018A858: nop

L_8018A85C:
    // 0x8018A85C: jal         0x80187520
    // 0x8018A860: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    Ending_80187520(rdram, ctx);
        goto after_0;
    // 0x8018A860: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8018A864: jal         0x801876A4
    // 0x8018A868: nop

    Ending_801876A4(rdram, ctx);
        goto after_1;
    // 0x8018A868: nop

    after_1:
    // 0x8018A86C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8018A870: jal         0x80187860
    // 0x8018A874: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    Ending_80187860(rdram, ctx);
        goto after_2;
    // 0x8018A874: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x8018A878: b           L_8018A8F0
    // 0x8018A87C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8018A8F0;
    // 0x8018A87C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8018A880:
    // 0x8018A880: jal         0x80187520
    // 0x8018A884: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    Ending_80187520(rdram, ctx);
        goto after_3;
    // 0x8018A884: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x8018A888: jal         0x801876A4
    // 0x8018A88C: nop

    Ending_801876A4(rdram, ctx);
        goto after_4;
    // 0x8018A88C: nop

    after_4:
    // 0x8018A890: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8018A894: jal         0x80187860
    // 0x8018A898: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    Ending_80187860(rdram, ctx);
        goto after_5;
    // 0x8018A898: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x8018A89C: b           L_8018A8F0
    // 0x8018A8A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8018A8F0;
    // 0x8018A8A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8018A8A4:
    // 0x8018A8A4: jal         0x8018A2A8
    // 0x8018A8A8: nop

    Ending_8018A2A8(rdram, ctx);
        goto after_6;
    // 0x8018A8A8: nop

    after_6:
    // 0x8018A8AC: b           L_8018A8F0
    // 0x8018A8B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8018A8F0;
    // 0x8018A8B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8018A8B4:
    // 0x8018A8B4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8018A8B8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018A8BC: jal         0x8018A2A8
    // 0x8018A8C0: sw          $t8, 0x6F88($at)
    MEM_W(0X6F88, ctx->r1) = ctx->r24;
    Ending_8018A2A8(rdram, ctx);
        goto after_7;
    // 0x8018A8C0: sw          $t8, 0x6F88($at)
    MEM_W(0X6F88, ctx->r1) = ctx->r24;
    after_7:
    // 0x8018A8C4: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x8018A8C8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018A8CC: sw          $t9, 0x6F88($at)
    MEM_W(0X6F88, ctx->r1) = ctx->r25;
    // 0x8018A8D0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8018A8D4: jal         0x80187860
    // 0x8018A8D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    Ending_80187860(rdram, ctx);
        goto after_8;
    // 0x8018A8D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x8018A8DC: jal         0x801888F4
    // 0x8018A8E0: nop

    Ending_801888F4(rdram, ctx);
        goto after_9;
    // 0x8018A8E0: nop

    after_9:
    // 0x8018A8E4: jal         0x801886F4
    // 0x8018A8E8: nop

    Ending_IncomingMsg_Draw(rdram, ctx);
        goto after_10;
    // 0x8018A8E8: nop

    after_10:
L_8018A8EC:
    // 0x8018A8EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8018A8F0:
    // 0x8018A8F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018A8F4: jr          $ra
    // 0x8018A8F8: nop

    return;
    // 0x8018A8F8: nop

;}
RECOMP_FUNC void Ending_8018E7B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018E7B8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8018E7BC: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x8018E7C0: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x8018E7C4: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8018E7C8: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8018E7CC: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8018E7D0: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x8018E7D4: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x8018E7D8: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8018E7DC: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x8018E7E0: subu        $t7, $s3, $t6
    ctx->r15 = SUB32(ctx->r19, ctx->r14);
    // 0x8018E7E4: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8018E7E8: bgez        $t7, L_8018E800
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8018E7EC: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8018E800;
    }
    // 0x8018E7EC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8018E7F0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8018E7F4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018E7F8: nop

    // 0x8018E7FC: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8018E800:
    // 0x8018E800: lwc1        $f10, 0x44($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X44);
    // 0x8018E804: lwc1        $f18, 0x20($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X20);
    // 0x8018E808: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018E80C: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8018E810: lwc1        $f8, -0x7A28($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X7A28);
    // 0x8018E814: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x8018E818: c.lt.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl < ctx->f8.fl;
    // 0x8018E81C: nop

    // 0x8018E820: bc1f        L_8018E840
    if (!c1cs) {
        // 0x8018E824: lui         $s1, 0x8013
        ctx->r17 = S32(0X8013 << 16);
            goto L_8018E840;
    }
    // 0x8018E824: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x8018E828: addiu       $s1, $s1, 0x7E64
    ctx->r17 = ADD32(ctx->r17, 0X7E64);
    // 0x8018E82C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8018E830: jal         0x800B8DD0
    // 0x8018E834: addiu       $a1, $zero, 0x43
    ctx->r5 = ADD32(0, 0X43);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x8018E834: addiu       $a1, $zero, 0x43
    ctx->r5 = ADD32(0, 0X43);
    after_0:
    // 0x8018E838: b           L_8018E858
    // 0x8018E83C: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
        goto L_8018E858;
    // 0x8018E83C: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
L_8018E840:
    // 0x8018E840: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x8018E844: addiu       $s1, $s1, 0x7E64
    ctx->r17 = ADD32(ctx->r17, 0X7E64);
    // 0x8018E848: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8018E84C: jal         0x800B8DD0
    // 0x8018E850: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    RCP_SetupDL(rdram, ctx);
        goto after_1;
    // 0x8018E850: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    after_1:
    // 0x8018E854: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
L_8018E858:
    // 0x8018E858: lui         $t9, 0xBC00
    ctx->r25 = S32(0XBC00 << 16);
    // 0x8018E85C: ori         $t9, $t9, 0x8
    ctx->r25 = ctx->r25 | 0X8;
    // 0x8018E860: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8018E864: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x8018E868: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8018E86C: lh          $t1, 0x66($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X66);
    // 0x8018E870: lh          $a0, 0x64($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X64);
    // 0x8018E874: lui         $t2, 0x1
    ctx->r10 = S32(0X1 << 16);
    // 0x8018E878: ori         $t2, $t2, 0xF400
    ctx->r10 = ctx->r10 | 0XF400;
    // 0x8018E87C: subu        $a1, $t1, $a0
    ctx->r5 = SUB32(ctx->r9, ctx->r4);
    // 0x8018E880: div         $zero, $t2, $a1
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r5)));
    // 0x8018E884: negu        $t6, $a0
    ctx->r14 = SUB32(0, ctx->r4);
    // 0x8018E888: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x8018E88C: addu        $t8, $t7, $t2
    ctx->r24 = ADD32(ctx->r15, ctx->r10);
    // 0x8018E890: mflo        $t3
    ctx->r11 = lo;
    // 0x8018E894: andi        $t4, $t3, 0xFFFF
    ctx->r12 = ctx->r11 & 0XFFFF;
    // 0x8018E898: sll         $t5, $t4, 16
    ctx->r13 = S32(ctx->r12 << 16);
    // 0x8018E89C: div         $zero, $t8, $a1
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r5)));
    // 0x8018E8A0: mflo        $t9
    ctx->r25 = lo;
    // 0x8018E8A4: andi        $t1, $t9, 0xFFFF
    ctx->r9 = ctx->r25 & 0XFFFF;
    // 0x8018E8A8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8018E8AC: bne         $a1, $zero, L_8018E8B8
    if (ctx->r5 != 0) {
        // 0x8018E8B0: nop
    
            goto L_8018E8B8;
    }
    // 0x8018E8B0: nop

    // 0x8018E8B4: break       7
    do_break(2149116084);
L_8018E8B8:
    // 0x8018E8B8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8018E8BC: bne         $a1, $at, L_8018E8D0
    if (ctx->r5 != ctx->r1) {
        // 0x8018E8C0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8018E8D0;
    }
    // 0x8018E8C0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8018E8C4: bne         $t2, $at, L_8018E8D0
    if (ctx->r10 != ctx->r1) {
        // 0x8018E8C8: nop
    
            goto L_8018E8D0;
    }
    // 0x8018E8C8: nop

    // 0x8018E8CC: break       6
    do_break(2149116108);
L_8018E8D0:
    // 0x8018E8D0: addu        $at, $t2, $zero
    ctx->r1 = ADD32(ctx->r10, 0);
    // 0x8018E8D4: or          $t2, $t5, $t1
    ctx->r10 = ctx->r13 | ctx->r9;
    // 0x8018E8D8: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x8018E8DC: bne         $a1, $zero, L_8018E8E8
    if (ctx->r5 != 0) {
        // 0x8018E8E0: nop
    
            goto L_8018E8E8;
    }
    // 0x8018E8E0: nop

    // 0x8018E8E4: break       7
    do_break(2149116132);
L_8018E8E8:
    // 0x8018E8E8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8018E8EC: bne         $a1, $at, L_8018E900
    if (ctx->r5 != ctx->r1) {
        // 0x8018E8F0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8018E900;
    }
    // 0x8018E8F0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8018E8F4: bne         $t8, $at, L_8018E900
    if (ctx->r24 != ctx->r1) {
        // 0x8018E8F8: nop
    
            goto L_8018E900;
    }
    // 0x8018E8F8: nop

    // 0x8018E8FC: break       6
    do_break(2149116156);
L_8018E900:
    // 0x8018E900: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8018E904: lui         $t4, 0xF800
    ctx->r12 = S32(0XF800 << 16);
    // 0x8018E908: lui         $s2, 0x8014
    ctx->r18 = S32(0X8014 << 16);
    // 0x8018E90C: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x8018E910: sw          $t3, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r11;
    // 0x8018E914: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8018E918: lbu         $t5, 0x61($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X61);
    // 0x8018E91C: lbu         $t7, 0x60($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X60);
    // 0x8018E920: lbu         $t4, 0x62($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X62);
    // 0x8018E924: sll         $t1, $t5, 16
    ctx->r9 = S32(ctx->r13 << 16);
    // 0x8018E928: sll         $t8, $t7, 24
    ctx->r24 = S32(ctx->r15 << 24);
    // 0x8018E92C: or          $t2, $t8, $t1
    ctx->r10 = ctx->r24 | ctx->r9;
    // 0x8018E930: sll         $t6, $t4, 8
    ctx->r14 = S32(ctx->r12 << 8);
    // 0x8018E934: or          $t7, $t2, $t6
    ctx->r15 = ctx->r10 | ctx->r14;
    // 0x8018E938: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8018E93C: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8018E940: lui         $t5, 0xFB00
    ctx->r13 = S32(0XFB00 << 16);
    // 0x8018E944: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8018E948: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x8018E94C: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8018E950: lbu         $t2, 0x69($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X69);
    // 0x8018E954: lbu         $t1, 0x68($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X68);
    // 0x8018E958: lbu         $t5, 0x6A($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X6A);
    // 0x8018E95C: sll         $t6, $t2, 16
    ctx->r14 = S32(ctx->r10 << 16);
    // 0x8018E960: lbu         $t2, 0x6B($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X6B);
    // 0x8018E964: sll         $t3, $t1, 24
    ctx->r11 = S32(ctx->r9 << 24);
    // 0x8018E968: or          $t7, $t3, $t6
    ctx->r15 = ctx->r11 | ctx->r14;
    // 0x8018E96C: sll         $t8, $t5, 8
    ctx->r24 = S32(ctx->r13 << 8);
    // 0x8018E970: or          $t1, $t7, $t8
    ctx->r9 = ctx->r15 | ctx->r24;
    // 0x8018E974: or          $t3, $t1, $t2
    ctx->r11 = ctx->r9 | ctx->r10;
    // 0x8018E978: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x8018E97C: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8018E980: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x8018E984: addiu       $s2, $s2, -0x4C40
    ctx->r18 = ADD32(ctx->r18, -0X4C40);
    // 0x8018E988: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8018E98C: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x8018E990: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8018E994: lbu         $t1, 0x6D($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X6D);
    // 0x8018E998: lbu         $t7, 0x6C($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X6C);
    // 0x8018E99C: lbu         $t9, 0x6E($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X6E);
    // 0x8018E9A0: sll         $t2, $t1, 16
    ctx->r10 = S32(ctx->r9 << 16);
    // 0x8018E9A4: lbu         $t1, 0x6F($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X6F);
    // 0x8018E9A8: sll         $t8, $t7, 24
    ctx->r24 = S32(ctx->r15 << 24);
    // 0x8018E9AC: or          $t3, $t8, $t2
    ctx->r11 = ctx->r24 | ctx->r10;
    // 0x8018E9B0: sll         $t5, $t9, 8
    ctx->r13 = S32(ctx->r25 << 8);
    // 0x8018E9B4: or          $t7, $t3, $t5
    ctx->r15 = ctx->r11 | ctx->r13;
    // 0x8018E9B8: or          $t8, $t7, $t1
    ctx->r24 = ctx->r15 | ctx->r9;
    // 0x8018E9BC: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8018E9C0: lw          $t2, 0xC($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XC);
    // 0x8018E9C4: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8018E9C8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8018E9CC: subu        $t6, $s3, $t2
    ctx->r14 = SUB32(ctx->r19, ctx->r10);
    // 0x8018E9D0: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x8018E9D4: bgez        $t6, L_8018E9E8
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8018E9D8: cvt.s.w     $f0, $f6
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
            goto L_8018E9E8;
    }
    // 0x8018E9D8: cvt.s.w     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8018E9DC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018E9E0: nop

    // 0x8018E9E4: add.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f10.fl;
L_8018E9E8:
    // 0x8018E9E8: lwc1        $f16, 0x3C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x8018E9EC: lwc1        $f18, 0x18($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8018E9F0: lwc1        $f10, 0x40($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8018E9F4: mul.s       $f4, $f0, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x8018E9F8: lwc1        $f6, 0x1C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x8018E9FC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8018EA00: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8018EA04: add.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8018EA08: lwc1        $f4, 0x20($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X20);
    // 0x8018EA0C: add.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x8018EA10: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8018EA14: lwc1        $f8, 0x44($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X44);
    // 0x8018EA18: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8018EA1C: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x8018EA20: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8018EA24: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8018EA28: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x8018EA2C: jal         0x80005B00
    // 0x8018EA30: nop

    Matrix_Translate(rdram, ctx);
        goto after_2;
    // 0x8018EA30: nop

    after_2:
    // 0x8018EA34: mtc1        $s3, $f16
    ctx->f16.u32l = ctx->r19;
    // 0x8018EA38: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8018EA3C: bgez        $s3, L_8018EA50
    if (SIGNED(ctx->r19) >= 0) {
        // 0x8018EA40: cvt.s.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
            goto L_8018EA50;
    }
    // 0x8018EA40: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8018EA44: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018EA48: nop

    // 0x8018EA4C: add.s       $f18, $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f8.fl;
L_8018EA50:
    // 0x8018EA50: lbu         $t3, 0x70($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X70);
    // 0x8018EA54: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018EA58: lwc1        $f4, 0x6BE0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6BE0);
    // 0x8018EA5C: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x8018EA60: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8018EA64: mul.s       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8018EA68: bgez        $t3, L_8018EA7C
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8018EA6C: cvt.s.w     $f16, $f6
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
            goto L_8018EA7C;
    }
    // 0x8018EA6C: cvt.s.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8018EA70: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018EA74: nop

    // 0x8018EA78: add.s       $f16, $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f8.fl;
L_8018EA7C:
    // 0x8018EA7C: jal         0x80023090
    // 0x8018EA80: add.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f16.fl;
    __sinf_recomp(rdram, ctx);
        goto after_3;
    // 0x8018EA80: add.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f16.fl;
    after_3:
    // 0x8018EA84: lbu         $t5, 0x71($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X71);
    // 0x8018EA88: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8018EA8C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8018EA90: bnel        $t5, $at, L_8018EBE8
    if (ctx->r13 != ctx->r1) {
        // 0x8018EA94: lwc1        $f16, 0x58($s0)
        ctx->f16.u32l = MEM_W(ctx->r16, 0X58);
            goto L_8018EBE8;
    }
    goto skip_0;
    // 0x8018EA94: lwc1        $f16, 0x58($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X58);
    skip_0:
    // 0x8018EA98: lwc1        $f8, 0x58($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X58);
    // 0x8018EA9C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018EAA0: lwc1        $f4, -0x7A0C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7A0C);
    // 0x8018EAA4: lwc1        $f18, 0x28($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X28);
    // 0x8018EAA8: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8018EAAC: lw          $t4, 0xC($s0)
    ctx->r12 = MEM_W(ctx->r16, 0XC);
    // 0x8018EAB0: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8018EAB4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8018EAB8: subu        $t7, $s3, $t4
    ctx->r15 = SUB32(ctx->r19, ctx->r12);
    // 0x8018EABC: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x8018EAC0: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8018EAC4: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8018EAC8: bgez        $t7, L_8018EADC
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8018EACC: cvt.s.w     $f4, $f18
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
            goto L_8018EADC;
    }
    // 0x8018EACC: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8018EAD0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018EAD4: nop

    // 0x8018EAD8: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
L_8018EADC:
    // 0x8018EADC: lwc1        $f6, 0x4C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x8018EAE0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018EAE4: lwc1        $f8, 0x6BE4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6BE4);
    // 0x8018EAE8: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8018EAEC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018EAF0: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x8018EAF4: mul.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x8018EAF8: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8018EAFC: jal         0x80005E90
    // 0x8018EB00: nop

    Matrix_RotateY(rdram, ctx);
        goto after_4;
    // 0x8018EB00: nop

    after_4:
    // 0x8018EB04: lwc1        $f18, 0x54($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X54);
    // 0x8018EB08: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018EB0C: lwc1        $f16, -0x7A10($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X7A10);
    // 0x8018EB10: lwc1        $f6, 0x24($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8018EB14: mul.s       $f8, $f20, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f18.fl);
    // 0x8018EB18: lw          $t1, 0xC($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XC);
    // 0x8018EB1C: sub.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f16.fl;
    // 0x8018EB20: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8018EB24: subu        $t8, $s3, $t1
    ctx->r24 = SUB32(ctx->r19, ctx->r9);
    // 0x8018EB28: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x8018EB2C: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8018EB30: add.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8018EB34: bgez        $t8, L_8018EB48
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8018EB38: cvt.s.w     $f16, $f6
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
            goto L_8018EB48;
    }
    // 0x8018EB38: cvt.s.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8018EB3C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8018EB40: nop

    // 0x8018EB44: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_8018EB48:
    // 0x8018EB48: lwc1        $f10, 0x48($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X48);
    // 0x8018EB4C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018EB50: lwc1        $f18, 0x6BE8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6BE8);
    // 0x8018EB54: mul.s       $f8, $f16, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x8018EB58: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018EB5C: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8018EB60: mul.s       $f16, $f6, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x8018EB64: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8018EB68: jal         0x80005D44
    // 0x8018EB6C: nop

    Matrix_RotateX(rdram, ctx);
        goto after_5;
    // 0x8018EB6C: nop

    after_5:
    // 0x8018EB70: lwc1        $f6, 0x5C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X5C);
    // 0x8018EB74: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018EB78: lwc1        $f4, -0x7A08($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7A08);
    // 0x8018EB7C: lwc1        $f10, 0x2C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8018EB80: mul.s       $f18, $f20, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f20.fl, ctx->f6.fl);
    // 0x8018EB84: lw          $t2, 0xC($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XC);
    // 0x8018EB88: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8018EB8C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8018EB90: subu        $t6, $s3, $t2
    ctx->r14 = SUB32(ctx->r19, ctx->r10);
    // 0x8018EB94: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x8018EB98: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8018EB9C: add.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x8018EBA0: bgez        $t6, L_8018EBB4
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8018EBA4: cvt.s.w     $f4, $f10
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
            goto L_8018EBB4;
    }
    // 0x8018EBA4: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8018EBA8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018EBAC: nop

    // 0x8018EBB0: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_8018EBB4:
    // 0x8018EBB4: lwc1        $f8, 0x50($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X50);
    // 0x8018EBB8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018EBBC: lwc1        $f6, 0x6BEC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6BEC);
    // 0x8018EBC0: mul.s       $f18, $f4, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8018EBC4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018EBC8: add.s       $f10, $f16, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8018EBCC: mul.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x8018EBD0: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8018EBD4: jal         0x80005FE0
    // 0x8018EBD8: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_6;
    // 0x8018EBD8: nop

    after_6:
    // 0x8018EBDC: b           L_8018ED08
    // 0x8018EBE0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
        goto L_8018ED08;
    // 0x8018EBE0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8018EBE4: lwc1        $f16, 0x58($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X58);
L_8018EBE8:
    // 0x8018EBE8: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    // 0x8018EBEC: lwc1        $f8, 0x28($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X28);
    // 0x8018EBF0: mul.s       $f18, $f20, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f20.fl, ctx->f16.fl);
    // 0x8018EBF4: subu        $t3, $s3, $t9
    ctx->r11 = SUB32(ctx->r19, ctx->r25);
    // 0x8018EBF8: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x8018EBFC: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8018EC00: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8018EC04: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8018EC08: bgez        $t3, L_8018EC1C
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8018EC0C: add.s       $f10, $f8, $f18
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f18.fl;
            goto L_8018EC1C;
    }
    // 0x8018EC0C: add.s       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x8018EC10: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8018EC14: nop

    // 0x8018EC18: add.s       $f4, $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f16.fl;
L_8018EC1C:
    // 0x8018EC1C: lwc1        $f8, 0x4C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x8018EC20: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018EC24: lwc1        $f16, 0x6BF0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6BF0);
    // 0x8018EC28: mul.s       $f18, $f4, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8018EC2C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018EC30: add.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8018EC34: mul.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x8018EC38: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8018EC3C: jal         0x80005E90
    // 0x8018EC40: nop

    Matrix_RotateY(rdram, ctx);
        goto after_7;
    // 0x8018EC40: nop

    after_7:
    // 0x8018EC44: lwc1        $f10, 0x54($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X54);
    // 0x8018EC48: lw          $t5, 0xC($s0)
    ctx->r13 = MEM_W(ctx->r16, 0XC);
    // 0x8018EC4C: lwc1        $f8, 0x24($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8018EC50: mul.s       $f18, $f20, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f20.fl, ctx->f10.fl);
    // 0x8018EC54: subu        $t4, $s3, $t5
    ctx->r12 = SUB32(ctx->r19, ctx->r13);
    // 0x8018EC58: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x8018EC5C: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8018EC60: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8018EC64: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8018EC68: bgez        $t4, L_8018EC7C
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8018EC6C: add.s       $f6, $f8, $f18
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f18.fl;
            goto L_8018EC7C;
    }
    // 0x8018EC6C: add.s       $f6, $f8, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x8018EC70: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018EC74: nop

    // 0x8018EC78: add.s       $f4, $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f10.fl;
L_8018EC7C:
    // 0x8018EC7C: lwc1        $f8, 0x48($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X48);
    // 0x8018EC80: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018EC84: lwc1        $f10, 0x6BF4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6BF4);
    // 0x8018EC88: mul.s       $f18, $f4, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8018EC8C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018EC90: add.s       $f16, $f6, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x8018EC94: mul.s       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x8018EC98: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8018EC9C: jal         0x80005D44
    // 0x8018ECA0: nop

    Matrix_RotateX(rdram, ctx);
        goto after_8;
    // 0x8018ECA0: nop

    after_8:
    // 0x8018ECA4: lwc1        $f6, 0x5C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X5C);
    // 0x8018ECA8: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x8018ECAC: lwc1        $f8, 0x2C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8018ECB0: mul.s       $f18, $f20, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f20.fl, ctx->f6.fl);
    // 0x8018ECB4: subu        $t1, $s3, $t7
    ctx->r9 = SUB32(ctx->r19, ctx->r15);
    // 0x8018ECB8: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x8018ECBC: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8018ECC0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8018ECC4: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8018ECC8: bgez        $t1, L_8018ECDC
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8018ECCC: add.s       $f16, $f8, $f18
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f18.fl;
            goto L_8018ECDC;
    }
    // 0x8018ECCC: add.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x8018ECD0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018ECD4: nop

    // 0x8018ECD8: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_8018ECDC:
    // 0x8018ECDC: lwc1        $f8, 0x50($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X50);
    // 0x8018ECE0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018ECE4: lwc1        $f6, 0x6BF8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6BF8);
    // 0x8018ECE8: mul.s       $f18, $f4, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8018ECEC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018ECF0: add.s       $f10, $f16, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8018ECF4: mul.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x8018ECF8: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8018ECFC: jal         0x80005FE0
    // 0x8018ED00: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_9;
    // 0x8018ED00: nop

    after_9:
    // 0x8018ED04: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
L_8018ED08:
    // 0x8018ED08: divu        $zero, $s3, $at
    lo = S32(U32(ctx->r19) / U32(ctx->r1)); hi = S32(U32(ctx->r19) % U32(ctx->r1));
    // 0x8018ED0C: mfhi        $t8
    ctx->r24 = hi;
    // 0x8018ED10: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x8018ED14: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8018ED18: bgez        $t8, L_8018ED30
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8018ED1C: cvt.s.w     $f16, $f8
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
            goto L_8018ED30;
    }
    // 0x8018ED1C: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8018ED20: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8018ED24: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8018ED28: nop

    // 0x8018ED2C: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_8018ED30:
    // 0x8018ED30: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8018ED34: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018ED38: lwc1        $f6, 0x30($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X30);
    // 0x8018ED3C: lwc1        $f8, 0x34($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X34);
    // 0x8018ED40: mul.s       $f0, $f16, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x8018ED44: lwc1        $f16, 0x38($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X38);
    // 0x8018ED48: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8018ED4C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8018ED50: add.s       $f4, $f6, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x8018ED54: add.s       $f18, $f8, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x8018ED58: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8018ED5C: add.s       $f10, $f16, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x8018ED60: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x8018ED64: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x8018ED68: jal         0x80005C34
    // 0x8018ED6C: nop

    Matrix_Scale(rdram, ctx);
        goto after_10;
    // 0x8018ED6C: nop

    after_10:
    // 0x8018ED70: jal         0x80006EB8
    // 0x8018ED74: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_11;
    // 0x8018ED74: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_11:
    // 0x8018ED78: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8018ED7C: lui         $t3, 0x701
    ctx->r11 = S32(0X701 << 16);
    // 0x8018ED80: addiu       $t3, $t3, 0x970
    ctx->r11 = ADD32(ctx->r11, 0X970);
    // 0x8018ED84: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8018ED88: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x8018ED8C: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x8018ED90: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8018ED94: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x8018ED98: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8018ED9C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8018EDA0: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x8018EDA4: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x8018EDA8: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x8018EDAC: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x8018EDB0: jr          $ra
    // 0x8018EDB4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8018EDB4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void Ending_8018B52C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018B52C: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8018B530: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018B534: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x8018B538: lui         $t7, 0x8019
    ctx->r15 = S32(0X8019 << 16);
    // 0x8018B53C: addiu       $t7, $t7, 0x2C70
    ctx->r15 = ADD32(ctx->r15, 0X2C70);
    // 0x8018B540: addiu       $t0, $t7, 0x24
    ctx->r8 = ADD32(ctx->r15, 0X24);
    // 0x8018B544: addiu       $t6, $sp, 0x44
    ctx->r14 = ADD32(ctx->r29, 0X44);
L_8018B548:
    // 0x8018B548: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x8018B54C: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x8018B550: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x8018B554: sw          $at, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r1;
    // 0x8018B558: lw          $at, -0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, -0X8);
    // 0x8018B55C: sw          $at, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r1;
    // 0x8018B560: lw          $at, -0x4($t7)
    ctx->r1 = MEM_W(ctx->r15, -0X4);
    // 0x8018B564: bne         $t7, $t0, L_8018B548
    if (ctx->r15 != ctx->r8) {
        // 0x8018B568: sw          $at, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r1;
            goto L_8018B548;
    }
    // 0x8018B568: sw          $at, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r1;
    // 0x8018B56C: lui         $t2, 0x8019
    ctx->r10 = S32(0X8019 << 16);
    // 0x8018B570: addiu       $t2, $t2, 0x2C94
    ctx->r10 = ADD32(ctx->r10, 0X2C94);
    // 0x8018B574: addiu       $t5, $t2, 0x24
    ctx->r13 = ADD32(ctx->r10, 0X24);
    // 0x8018B578: addiu       $t1, $sp, 0x20
    ctx->r9 = ADD32(ctx->r29, 0X20);
L_8018B57C:
    // 0x8018B57C: lw          $at, 0x0($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X0);
    // 0x8018B580: addiu       $t2, $t2, 0xC
    ctx->r10 = ADD32(ctx->r10, 0XC);
    // 0x8018B584: addiu       $t1, $t1, 0xC
    ctx->r9 = ADD32(ctx->r9, 0XC);
    // 0x8018B588: sw          $at, -0xC($t1)
    MEM_W(-0XC, ctx->r9) = ctx->r1;
    // 0x8018B58C: lw          $at, -0x8($t2)
    ctx->r1 = MEM_W(ctx->r10, -0X8);
    // 0x8018B590: sw          $at, -0x8($t1)
    MEM_W(-0X8, ctx->r9) = ctx->r1;
    // 0x8018B594: lw          $at, -0x4($t2)
    ctx->r1 = MEM_W(ctx->r10, -0X4);
    // 0x8018B598: bne         $t2, $t5, L_8018B57C
    if (ctx->r10 != ctx->r13) {
        // 0x8018B59C: sw          $at, -0x4($t1)
        MEM_W(-0X4, ctx->r9) = ctx->r1;
            goto L_8018B57C;
    }
    // 0x8018B59C: sw          $at, -0x4($t1)
    MEM_W(-0X4, ctx->r9) = ctx->r1;
    // 0x8018B5A0: jal         0x800613C4
    // 0x8018B5A4: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    Actor_Initialize(rdram, ctx);
        goto after_0;
    // 0x8018B5A4: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    after_0:
    // 0x8018B5A8: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x8018B5AC: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8018B5B0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8018B5B4: sb          $t9, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r25;
    // 0x8018B5B8: sh          $t8, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r24;
    // 0x8018B5BC: lw          $v1, 0x6C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X6C);
    // 0x8018B5C0: addiu       $t7, $sp, 0x44
    ctx->r15 = ADD32(ctx->r29, 0X44);
    // 0x8018B5C4: addiu       $t5, $sp, 0x20
    ctx->r13 = ADD32(ctx->r29, 0X20);
    // 0x8018B5C8: sll         $t0, $v1, 2
    ctx->r8 = S32(ctx->r3 << 2);
    // 0x8018B5CC: subu        $t0, $t0, $v1
    ctx->r8 = SUB32(ctx->r8, ctx->r3);
    // 0x8018B5D0: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8018B5D4: addu        $t6, $t0, $t7
    ctx->r14 = ADD32(ctx->r8, ctx->r15);
    // 0x8018B5D8: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x8018B5DC: addu        $v0, $t0, $t5
    ctx->r2 = ADD32(ctx->r8, ctx->r13);
    // 0x8018B5E0: sw          $at, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r1;
    // 0x8018B5E4: lw          $t3, 0x4($t6)
    ctx->r11 = MEM_W(ctx->r14, 0X4);
    // 0x8018B5E8: sw          $t3, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r11;
    // 0x8018B5EC: lw          $at, 0x8($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X8);
    // 0x8018B5F0: sw          $at, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r1;
    // 0x8018B5F4: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8018B5F8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8018B5FC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018B600: swc1        $f4, 0xF4($a0)
    MEM_W(0XF4, ctx->r4) = ctx->f4.u32l;
    // 0x8018B604: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8018B608: swc1        $f6, 0xF8($a0)
    MEM_W(0XF8, ctx->r4) = ctx->f6.u32l;
    // 0x8018B60C: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8018B610: swc1        $f10, 0x110($a0)
    MEM_W(0X110, ctx->r4) = ctx->f10.u32l;
    // 0x8018B614: swc1        $f8, 0xFC($a0)
    MEM_W(0XFC, ctx->r4) = ctx->f8.u32l;
    // 0x8018B618: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018B61C: jr          $ra
    // 0x8018B620: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x8018B620: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void Ending_8018A570(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018A570: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8018A574: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8018A578: jal         0x8018A024
    // 0x8018A57C: nop

    Ending_8018A024(rdram, ctx);
        goto after_0;
    // 0x8018A57C: nop

    after_0:
    // 0x8018A580: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8018A584: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8018A588: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8018A58C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8018A590: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8018A594: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8018A598: lw          $t1, -0x7AA4($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X7AA4);
    // 0x8018A59C: lw          $t0, -0x7AA8($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7AA8);
    // 0x8018A5A0: lw          $t9, -0x7AAC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7AAC);
    // 0x8018A5A4: lw          $t8, -0x7AB0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7AB0);
    // 0x8018A5A8: lw          $t7, -0x7AB4($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7AB4);
    // 0x8018A5AC: lw          $t6, -0x7AB8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7AB8);
    // 0x8018A5B0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8018A5B4: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8018A5B8: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x8018A5BC: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x8018A5C0: lw          $a3, -0x7B1C($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X7B1C);
    // 0x8018A5C4: lw          $a2, -0x7B20($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7B20);
    // 0x8018A5C8: lw          $a1, -0x7B24($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7B24);
    // 0x8018A5CC: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8018A5D0: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x8018A5D4: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x8018A5D8: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8018A5DC: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8018A5E0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8018A5E4: jal         0x8000372C
    // 0x8018A5E8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    Lights_SetOneLight(rdram, ctx);
        goto after_1;
    // 0x8018A5E8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_1:
    // 0x8018A5EC: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018A5F0: addiu       $a1, $a1, 0x6F8C
    ctx->r5 = ADD32(ctx->r5, 0X6F8C);
    // 0x8018A5F4: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8018A5F8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8018A5FC: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x8018A600: beq         $v1, $at, L_8018A634
    if (ctx->r3 == ctx->r1) {
        // 0x8018A604: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8018A634;
    }
    // 0x8018A604: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8018A608: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8018A60C: beq         $v0, $at, L_8018A650
    if (ctx->r2 == ctx->r1) {
        // 0x8018A610: lui         $t4, 0x8017
        ctx->r12 = S32(0X8017 << 16);
            goto L_8018A650;
    }
    // 0x8018A610: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x8018A614: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8018A618: beq         $v0, $at, L_8018A66C
    if (ctx->r2 == ctx->r1) {
        // 0x8018A61C: lui         $t6, 0x8017
        ctx->r14 = S32(0X8017 << 16);
            goto L_8018A66C;
    }
    // 0x8018A61C: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x8018A620: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8018A624: beq         $v0, $at, L_8018A688
    if (ctx->r2 == ctx->r1) {
        // 0x8018A628: lui         $t8, 0x8019
        ctx->r24 = S32(0X8019 << 16);
            goto L_8018A688;
    }
    // 0x8018A628: lui         $t8, 0x8019
    ctx->r24 = S32(0X8019 << 16);
    // 0x8018A62C: b           L_8018A6B8
    // 0x8018A630: sltiu       $at, $v1, 0xA
    ctx->r1 = ctx->r3 < 0XA ? 1 : 0;
        goto L_8018A6B8;
    // 0x8018A630: sltiu       $at, $v1, 0xA
    ctx->r1 = ctx->r3 < 0XA ? 1 : 0;
L_8018A634:
    // 0x8018A634: lw          $t2, 0x7A80($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7A80);
    // 0x8018A638: addiu       $at, $zero, 0xC8
    ctx->r1 = ADD32(0, 0XC8);
    // 0x8018A63C: bnel        $t2, $at, L_8018A6B8
    if (ctx->r10 != ctx->r1) {
        // 0x8018A640: sltiu       $at, $v1, 0xA
        ctx->r1 = ctx->r3 < 0XA ? 1 : 0;
            goto L_8018A6B8;
    }
    goto skip_0;
    // 0x8018A640: sltiu       $at, $v1, 0xA
    ctx->r1 = ctx->r3 < 0XA ? 1 : 0;
    skip_0:
    // 0x8018A644: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x8018A648: b           L_8018A6B4
    // 0x8018A64C: sw          $v1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r3;
        goto L_8018A6B4;
    // 0x8018A64C: sw          $v1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r3;
L_8018A650:
    // 0x8018A650: lw          $t4, 0x7A80($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7A80);
    // 0x8018A654: addiu       $at, $zero, 0x1B3
    ctx->r1 = ADD32(0, 0X1B3);
    // 0x8018A658: bnel        $t4, $at, L_8018A6B8
    if (ctx->r12 != ctx->r1) {
        // 0x8018A65C: sltiu       $at, $v1, 0xA
        ctx->r1 = ctx->r3 < 0XA ? 1 : 0;
            goto L_8018A6B8;
    }
    goto skip_1;
    // 0x8018A65C: sltiu       $at, $v1, 0xA
    ctx->r1 = ctx->r3 < 0XA ? 1 : 0;
    skip_1:
    // 0x8018A660: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
    // 0x8018A664: b           L_8018A6B4
    // 0x8018A668: sw          $v1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r3;
        goto L_8018A6B4;
    // 0x8018A668: sw          $v1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r3;
L_8018A66C:
    // 0x8018A66C: lw          $t6, 0x7A80($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7A80);
    // 0x8018A670: addiu       $at, $zero, 0xB4
    ctx->r1 = ADD32(0, 0XB4);
    // 0x8018A674: bnel        $t6, $at, L_8018A6B8
    if (ctx->r14 != ctx->r1) {
        // 0x8018A678: sltiu       $at, $v1, 0xA
        ctx->r1 = ctx->r3 < 0XA ? 1 : 0;
            goto L_8018A6B8;
    }
    goto skip_2;
    // 0x8018A678: sltiu       $at, $v1, 0xA
    ctx->r1 = ctx->r3 < 0XA ? 1 : 0;
    skip_2:
    // 0x8018A67C: addiu       $v1, $zero, 0x7
    ctx->r3 = ADD32(0, 0X7);
    // 0x8018A680: b           L_8018A6B4
    // 0x8018A684: sw          $v1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r3;
        goto L_8018A6B4;
    // 0x8018A684: sw          $v1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r3;
L_8018A688:
    // 0x8018A688: lw          $t8, 0x6E40($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6E40);
    // 0x8018A68C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8018A690: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x8018A694: bnel        $t8, $at, L_8018A6B8
    if (ctx->r24 != ctx->r1) {
        // 0x8018A698: sltiu       $at, $v1, 0xA
        ctx->r1 = ctx->r3 < 0XA ? 1 : 0;
            goto L_8018A6B8;
    }
    goto skip_3;
    // 0x8018A698: sltiu       $at, $v1, 0xA
    ctx->r1 = ctx->r3 < 0XA ? 1 : 0;
    skip_3:
    // 0x8018A69C: lw          $t9, 0x7A80($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7A80);
    // 0x8018A6A0: slti        $at, $t9, 0x6C
    ctx->r1 = SIGNED(ctx->r25) < 0X6C ? 1 : 0;
    // 0x8018A6A4: bnel        $at, $zero, L_8018A6B8
    if (ctx->r1 != 0) {
        // 0x8018A6A8: sltiu       $at, $v1, 0xA
        ctx->r1 = ctx->r3 < 0XA ? 1 : 0;
            goto L_8018A6B8;
    }
    goto skip_4;
    // 0x8018A6A8: sltiu       $at, $v1, 0xA
    ctx->r1 = ctx->r3 < 0XA ? 1 : 0;
    skip_4:
    // 0x8018A6AC: addiu       $v1, $zero, 0x9
    ctx->r3 = ADD32(0, 0X9);
    // 0x8018A6B0: sw          $v1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r3;
L_8018A6B4:
    // 0x8018A6B4: sltiu       $at, $v1, 0xA
    ctx->r1 = ctx->r3 < 0XA ? 1 : 0;
L_8018A6B8:
    // 0x8018A6B8: beq         $at, $zero, L_8018A818
    if (ctx->r1 == 0) {
        // 0x8018A6BC: sll         $t1, $v1, 2
        ctx->r9 = S32(ctx->r3 << 2);
            goto L_8018A818;
    }
    // 0x8018A6BC: sll         $t1, $v1, 2
    ctx->r9 = S32(ctx->r3 << 2);
    // 0x8018A6C0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018A6C4: addu        $at, $at, $t1
    gpr jr_addend_8018A6CC = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x8018A6C8: lw          $t1, 0x6564($at)
    ctx->r9 = ADD32(ctx->r1, 0X6564);
    // 0x8018A6CC: jr          $t1
    // 0x8018A6D0: nop

    switch (jr_addend_8018A6CC >> 2) {
        case 0: goto L_8018A6D4; break;
        case 1: goto L_8018A6DC; break;
        case 2: goto L_8018A70C; break;
        case 3: goto L_8018A71C; break;
        case 4: goto L_8018A75C; break;
        case 5: goto L_8018A76C; break;
        case 6: goto L_8018A7AC; break;
        case 7: goto L_8018A7BC; break;
        case 8: goto L_8018A7EC; break;
        case 9: goto L_8018A7FC; break;
        default: switch_error(__func__, 0x8018A6CC, 0x80196564);
    }
    // 0x8018A6D0: nop

L_8018A6D4:
    // 0x8018A6D4: jal         0x8018A124
    // 0x8018A6D8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    Ending_8018A124(rdram, ctx);
        goto after_2;
    // 0x8018A6D8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
L_8018A6DC:
    // 0x8018A6DC: jal         0x80187D3C
    // 0x8018A6E0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    Ending_80187D3C(rdram, ctx);
        goto after_3;
    // 0x8018A6E0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x8018A6E4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018A6E8: sw          $zero, -0x7CA8($at)
    MEM_W(-0X7CA8, ctx->r1) = 0;
    // 0x8018A6EC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018A6F0: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018A6F4: sw          $zero, -0x7A74($at)
    MEM_W(-0X7A74, ctx->r1) = 0;
    // 0x8018A6F8: addiu       $a1, $a1, 0x6F8C
    ctx->r5 = ADD32(ctx->r5, 0X6F8C);
    // 0x8018A6FC: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x8018A700: sw          $t2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r10;
    // 0x8018A704: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018A708: sw          $zero, 0x7A80($at)
    MEM_W(0X7A80, ctx->r1) = 0;
L_8018A70C:
    // 0x8018A70C: jal         0x80188030
    // 0x8018A710: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    Ending_80188030(rdram, ctx);
        goto after_4;
    // 0x8018A710: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x8018A714: b           L_8018A81C
    // 0x8018A718: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8018A81C;
    // 0x8018A718: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8018A71C:
    // 0x8018A71C: jal         0x80187D3C
    // 0x8018A720: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    Ending_80187D3C(rdram, ctx);
        goto after_5;
    // 0x8018A720: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_5:
    // 0x8018A724: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018A728: sw          $zero, -0x7CA8($at)
    MEM_W(-0X7CA8, ctx->r1) = 0;
    // 0x8018A72C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018A730: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018A734: sw          $zero, -0x7A74($at)
    MEM_W(-0X7A74, ctx->r1) = 0;
    // 0x8018A738: addiu       $a1, $a1, 0x6F8C
    ctx->r5 = ADD32(ctx->r5, 0X6F8C);
    // 0x8018A73C: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x8018A740: sw          $t3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r11;
    // 0x8018A744: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018A748: sw          $zero, 0x7A80($at)
    MEM_W(0X7A80, ctx->r1) = 0;
    // 0x8018A74C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018A750: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8018A754: b           L_8018A818
    // 0x8018A758: sw          $t4, 0x7820($at)
    MEM_W(0X7820, ctx->r1) = ctx->r12;
        goto L_8018A818;
    // 0x8018A758: sw          $t4, 0x7820($at)
    MEM_W(0X7820, ctx->r1) = ctx->r12;
L_8018A75C:
    // 0x8018A75C: jal         0x80188030
    // 0x8018A760: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    Ending_80188030(rdram, ctx);
        goto after_6;
    // 0x8018A760: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_6:
    // 0x8018A764: b           L_8018A81C
    // 0x8018A768: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8018A81C;
    // 0x8018A768: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8018A76C:
    // 0x8018A76C: jal         0x80188394
    // 0x8018A770: nop

    Ending_GralPepper_Animate(rdram, ctx);
        goto after_7;
    // 0x8018A770: nop

    after_7:
    // 0x8018A774: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018A778: sw          $zero, -0x7CA8($at)
    MEM_W(-0X7CA8, ctx->r1) = 0;
    // 0x8018A77C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018A780: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018A784: sw          $zero, -0x7A74($at)
    MEM_W(-0X7A74, ctx->r1) = 0;
    // 0x8018A788: addiu       $a1, $a1, 0x6F8C
    ctx->r5 = ADD32(ctx->r5, 0X6F8C);
    // 0x8018A78C: addiu       $t5, $zero, 0x6
    ctx->r13 = ADD32(0, 0X6);
    // 0x8018A790: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
    // 0x8018A794: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018A798: sw          $zero, 0x7A80($at)
    MEM_W(0X7A80, ctx->r1) = 0;
    // 0x8018A79C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018A7A0: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x8018A7A4: b           L_8018A818
    // 0x8018A7A8: sw          $t6, 0x7820($at)
    MEM_W(0X7820, ctx->r1) = ctx->r14;
        goto L_8018A818;
    // 0x8018A7A8: sw          $t6, 0x7820($at)
    MEM_W(0X7820, ctx->r1) = ctx->r14;
L_8018A7AC:
    // 0x8018A7AC: jal         0x8018845C
    // 0x8018A7B0: nop

    Ending_8018845C(rdram, ctx);
        goto after_8;
    // 0x8018A7B0: nop

    after_8:
    // 0x8018A7B4: b           L_8018A81C
    // 0x8018A7B8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8018A81C;
    // 0x8018A7B8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8018A7BC:
    // 0x8018A7BC: jal         0x80188DB4
    // 0x8018A7C0: nop

    Ending_80188DB4(rdram, ctx);
        goto after_9;
    // 0x8018A7C0: nop

    after_9:
    // 0x8018A7C4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018A7C8: sw          $zero, -0x7CA8($at)
    MEM_W(-0X7CA8, ctx->r1) = 0;
    // 0x8018A7CC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018A7D0: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018A7D4: sw          $zero, -0x7A74($at)
    MEM_W(-0X7A74, ctx->r1) = 0;
    // 0x8018A7D8: addiu       $a1, $a1, 0x6F8C
    ctx->r5 = ADD32(ctx->r5, 0X6F8C);
    // 0x8018A7DC: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x8018A7E0: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x8018A7E4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018A7E8: sw          $zero, 0x7A80($at)
    MEM_W(0X7A80, ctx->r1) = 0;
L_8018A7EC:
    // 0x8018A7EC: jal         0x80189108
    // 0x8018A7F0: nop

    Ending_80189108(rdram, ctx);
        goto after_10;
    // 0x8018A7F0: nop

    after_10:
    // 0x8018A7F4: b           L_8018A81C
    // 0x8018A7F8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8018A81C;
    // 0x8018A7F8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8018A7FC:
    // 0x8018A7FC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018A800: sw          $zero, -0x7CA8($at)
    MEM_W(-0X7CA8, ctx->r1) = 0;
    // 0x8018A804: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018A808: sw          $zero, 0x7A80($at)
    MEM_W(0X7A80, ctx->r1) = 0;
    // 0x8018A80C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018A810: addiu       $t8, $zero, 0x7
    ctx->r24 = ADD32(0, 0X7);
    // 0x8018A814: sw          $t8, 0x6D00($at)
    MEM_W(0X6D00, ctx->r1) = ctx->r24;
L_8018A818:
    // 0x8018A818: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8018A81C:
    // 0x8018A81C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8018A820: jr          $ra
    // 0x8018A824: nop

    return;
    // 0x8018A824: nop

;}
RECOMP_FUNC void Ending_8018D398(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D398: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8018D39C: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8018D3A0: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8018D3A4: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8018D3A8: lw          $v1, 0xC($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XC);
    // 0x8018D3AC: lh          $a2, 0x64($s0)
    ctx->r6 = MEM_H(ctx->r16, 0X64);
    // 0x8018D3B0: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8018D3B4: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8018D3B8: addu        $t6, $v1, $a2
    ctx->r14 = ADD32(ctx->r3, ctx->r6);
    // 0x8018D3BC: sltu        $at, $a0, $t6
    ctx->r1 = ctx->r4 < ctx->r14 ? 1 : 0;
    // 0x8018D3C0: beq         $at, $zero, L_8018D3F0
    if (ctx->r1 == 0) {
        // 0x8018D3C4: addiu       $t0, $t0, -0x7CA8
        ctx->r8 = ADD32(ctx->r8, -0X7CA8);
            goto L_8018D3F0;
    }
    // 0x8018D3C4: addiu       $t0, $t0, -0x7CA8
    ctx->r8 = ADD32(ctx->r8, -0X7CA8);
    // 0x8018D3C8: subu        $t7, $a0, $v1
    ctx->r15 = SUB32(ctx->r4, ctx->r3);
    // 0x8018D3CC: sll         $t8, $t7, 8
    ctx->r24 = S32(ctx->r15 << 8);
    // 0x8018D3D0: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8018D3D4: divu        $zero, $t8, $a2
    lo = S32(U32(ctx->r24) / U32(ctx->r6)); hi = S32(U32(ctx->r24) % U32(ctx->r6));
    // 0x8018D3D8: mflo        $v0
    ctx->r2 = lo;
    // 0x8018D3DC: andi        $t9, $v0, 0xFF
    ctx->r25 = ctx->r2 & 0XFF;
    // 0x8018D3E0: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x8018D3E4: bne         $a2, $zero, L_8018D3F0
    if (ctx->r6 != 0) {
        // 0x8018D3E8: nop
    
            goto L_8018D3F0;
    }
    // 0x8018D3E8: nop

    // 0x8018D3EC: break       7
    do_break(2149110764);
L_8018D3F0:
    // 0x8018D3F0: lw          $t4, 0x10($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X10);
    // 0x8018D3F4: lh          $a2, 0x66($s0)
    ctx->r6 = MEM_H(ctx->r16, 0X66);
    // 0x8018D3F8: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8018D3FC: addu        $a1, $v1, $t4
    ctx->r5 = ADD32(ctx->r3, ctx->r12);
    // 0x8018D400: subu        $t5, $a1, $a2
    ctx->r13 = SUB32(ctx->r5, ctx->r6);
    // 0x8018D404: sltu        $at, $t5, $a0
    ctx->r1 = ctx->r13 < ctx->r4 ? 1 : 0;
    // 0x8018D408: beq         $at, $zero, L_8018D438
    if (ctx->r1 == 0) {
        // 0x8018D40C: lui         $v1, 0x8018
        ctx->r3 = S32(0X8018 << 16);
            goto L_8018D438;
    }
    // 0x8018D40C: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x8018D410: subu        $t6, $a1, $a0
    ctx->r14 = SUB32(ctx->r5, ctx->r4);
    // 0x8018D414: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x8018D418: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8018D41C: divu        $zero, $t7, $a2
    lo = S32(U32(ctx->r15) / U32(ctx->r6)); hi = S32(U32(ctx->r15) % U32(ctx->r6));
    // 0x8018D420: mflo        $v0
    ctx->r2 = lo;
    // 0x8018D424: andi        $t8, $v0, 0xFF
    ctx->r24 = ctx->r2 & 0XFF;
    // 0x8018D428: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8018D42C: bne         $a2, $zero, L_8018D438
    if (ctx->r6 != 0) {
        // 0x8018D430: nop
    
            goto L_8018D438;
    }
    // 0x8018D430: nop

    // 0x8018D434: break       7
    do_break(2149110836);
L_8018D438:
    // 0x8018D438: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8018D43C: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8018D440: addiu       $t3, $t3, -0x7CB0
    ctx->r11 = ADD32(ctx->r11, -0X7CB0);
    // 0x8018D444: addiu       $t2, $t2, -0x7CAC
    ctx->r10 = ADD32(ctx->r10, -0X7CAC);
    // 0x8018D448: addiu       $v1, $v1, -0x7CA4
    ctx->r3 = ADD32(ctx->r3, -0X7CA4);
    // 0x8018D44C: addiu       $t1, $t1, -0x7CC0
    ctx->r9 = ADD32(ctx->r9, -0X7CC0);
    // 0x8018D450: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
    // 0x8018D454: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x8018D458: sw          $zero, 0x0($t2)
    MEM_W(0X0, ctx->r10) = 0;
    // 0x8018D45C: sw          $zero, 0x0($t3)
    MEM_W(0X0, ctx->r11) = 0;
    // 0x8018D460: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    // 0x8018D464: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018D468: addiu       $t8, $zero, 0xE8
    ctx->r24 = ADD32(0, 0XE8);
    // 0x8018D46C: sw          $zero, -0x7CB8($at)
    MEM_W(-0X7CB8, ctx->r1) = 0;
    // 0x8018D470: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8018D474: lbu         $t9, 0x6C($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X6C);
    // 0x8018D478: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8018D47C: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8018D480: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8018D484: lbu         $t4, 0x6D($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X6D);
    // 0x8018D488: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x8018D48C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x8018D490: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x8018D494: lbu         $t5, 0x6E($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X6E);
    // 0x8018D498: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8018D49C: addiu       $a3, $zero, 0x138
    ctx->r7 = ADD32(0, 0X138);
    // 0x8018D4A0: jal         0x8009F574
    // 0x8018D4A4: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    Graphics_FillRectangle(rdram, ctx);
        goto after_0;
    // 0x8018D4A4: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    after_0:
    // 0x8018D4A8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8018D4AC: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8018D4B0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8018D4B4: jr          $ra
    // 0x8018D4B8: nop

    return;
    // 0x8018D4B8: nop

;}
RECOMP_FUNC void Ending_801926D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801926D4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801926D8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801926DC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801926E0: addiu       $t6, $zero, 0x2710
    ctx->r14 = ADD32(0, 0X2710);
    // 0x801926E4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x801926E8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801926EC: sw          $t6, -0x274C($at)
    MEM_W(-0X274C, ctx->r1) = ctx->r14;
    // 0x801926F0: jal         0x80005708
    // 0x801926F4: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Push(rdram, ctx);
        goto after_0;
    // 0x801926F4: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_0:
    // 0x801926F8: lui         $s0, 0x8019
    ctx->r16 = S32(0X8019 << 16);
    // 0x801926FC: addiu       $s0, $s0, 0x2E70
    ctx->r16 = ADD32(ctx->r16, 0X2E70);
    // 0x80192700: jal         0x801924EC
    // 0x80192704: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    Ending_801924EC(rdram, ctx);
        goto after_1;
    // 0x80192704: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_1:
    // 0x80192708: jal         0x80192164
    // 0x8019270C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    Ending_80192164(rdram, ctx);
        goto after_2;
    // 0x8019270C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_2:
    // 0x80192710: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80192714: jal         0x80005740
    // 0x80192718: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Pop(rdram, ctx);
        goto after_3;
    // 0x80192718: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_3:
    // 0x8019271C: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80192720: addiu       $t9, $zero, 0x64
    ctx->r25 = ADD32(0, 0X64);
    // 0x80192724: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x80192728: addiu       $v0, $t7, 0x1
    ctx->r2 = ADD32(ctx->r15, 0X1);
    // 0x8019272C: sltiu       $at, $v0, 0x64
    ctx->r1 = ctx->r2 < 0X64 ? 1 : 0;
    // 0x80192730: beq         $at, $zero, L_801927B0
    if (ctx->r1 == 0) {
        // 0x80192734: sw          $v0, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r2;
            goto L_801927B0;
    }
    // 0x80192734: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80192738: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x8019273C: lw          $t0, 0x7824($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7824);
    // 0x80192740: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80192744: addiu       $a1, $zero, 0x2A
    ctx->r5 = ADD32(0, 0X2A);
    // 0x80192748: bne         $t0, $zero, L_80192790
    if (ctx->r8 != 0) {
        // 0x8019274C: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80192790;
    }
    // 0x8019274C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80192750: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80192754: lw          $t1, -0x7D80($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X7D80);
    // 0x80192758: lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // 0x8019275C: addiu       $t4, $v0, -0x7A70
    ctx->r12 = ADD32(ctx->r2, -0X7A70);
    // 0x80192760: addiu       $t3, $t1, 0x3C
    ctx->r11 = ADD32(ctx->r9, 0X3C);
L_80192764:
    // 0x80192764: lw          $at, 0x49C($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X49C);
    // 0x80192768: addiu       $t1, $t1, 0xC
    ctx->r9 = ADD32(ctx->r9, 0XC);
    // 0x8019276C: addiu       $t4, $t4, 0xC
    ctx->r12 = ADD32(ctx->r12, 0XC);
    // 0x80192770: sw          $at, -0xC($t4)
    MEM_W(-0XC, ctx->r12) = ctx->r1;
    // 0x80192774: lw          $at, 0x494($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X494);
    // 0x80192778: sw          $at, -0x8($t4)
    MEM_W(-0X8, ctx->r12) = ctx->r1;
    // 0x8019277C: lw          $at, 0x498($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X498);
    // 0x80192780: bne         $t1, $t3, L_80192764
    if (ctx->r9 != ctx->r11) {
        // 0x80192784: sw          $at, -0x4($t4)
        MEM_W(-0X4, ctx->r12) = ctx->r1;
            goto L_80192764;
    }
    // 0x80192784: sw          $at, -0x4($t4)
    MEM_W(-0X4, ctx->r12) = ctx->r1;
    // 0x80192788: b           L_801927A4
    // 0x8019278C: nop

        goto L_801927A4;
    // 0x8019278C: nop

L_80192790:
    // 0x80192790: lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // 0x80192794: addiu       $v0, $v0, -0x7A70
    ctx->r2 = ADD32(ctx->r2, -0X7A70);
    // 0x80192798: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8019279C: sb          $t6, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r14;
    // 0x801927A0: sb          $t6, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r14;
L_801927A4:
    // 0x801927A4: jal         0x8001D444
    // 0x801927A8: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    Audio_PlaySequence(rdram, ctx);
        goto after_4;
    // 0x801927A8: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_4:
    // 0x801927AC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_801927B0:
    // 0x801927B0: sltiu       $at, $v0, 0xAE6
    ctx->r1 = ctx->r2 < 0XAE6 ? 1 : 0;
    // 0x801927B4: bne         $at, $zero, L_801927CC
    if (ctx->r1 != 0) {
        // 0x801927B8: sltiu       $at, $v0, 0xBB8
        ctx->r1 = ctx->r2 < 0XBB8 ? 1 : 0;
            goto L_801927CC;
    }
    // 0x801927B8: sltiu       $at, $v0, 0xBB8
    ctx->r1 = ctx->r2 < 0XBB8 ? 1 : 0;
    // 0x801927BC: beql        $at, $zero, L_801927D0
    if (ctx->r1 == 0) {
        // 0x801927C0: sltiu       $at, $v0, 0x131B
        ctx->r1 = ctx->r2 < 0X131B ? 1 : 0;
            goto L_801927D0;
    }
    goto skip_0;
    // 0x801927C0: sltiu       $at, $v0, 0x131B
    ctx->r1 = ctx->r2 < 0X131B ? 1 : 0;
    skip_0:
    // 0x801927C4: addiu       $v0, $zero, 0xC1B
    ctx->r2 = ADD32(0, 0XC1B);
    // 0x801927C8: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
L_801927CC:
    // 0x801927CC: sltiu       $at, $v0, 0x131B
    ctx->r1 = ctx->r2 < 0X131B ? 1 : 0;
L_801927D0:
    // 0x801927D0: bne         $at, $zero, L_801927E8
    if (ctx->r1 != 0) {
        // 0x801927D4: sltiu       $at, $v0, 0x1387
        ctx->r1 = ctx->r2 < 0X1387 ? 1 : 0;
            goto L_801927E8;
    }
    // 0x801927D4: sltiu       $at, $v0, 0x1387
    ctx->r1 = ctx->r2 < 0X1387 ? 1 : 0;
    // 0x801927D8: beql        $at, $zero, L_801927EC
    if (ctx->r1 == 0) {
        // 0x801927DC: sltiu       $at, $v0, 0x1388
        ctx->r1 = ctx->r2 < 0X1388 ? 1 : 0;
            goto L_801927EC;
    }
    goto skip_1;
    // 0x801927DC: sltiu       $at, $v0, 0x1388
    ctx->r1 = ctx->r2 < 0X1388 ? 1 : 0;
    skip_1:
    // 0x801927E0: addiu       $v0, $zero, 0x1387
    ctx->r2 = ADD32(0, 0X1387);
    // 0x801927E4: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
L_801927E8:
    // 0x801927E8: sltiu       $at, $v0, 0x1388
    ctx->r1 = ctx->r2 < 0X1388 ? 1 : 0;
L_801927EC:
    // 0x801927EC: bne         $at, $zero, L_80192800
    if (ctx->r1 != 0) {
        // 0x801927F0: sltiu       $at, $v0, 0x13E8
        ctx->r1 = ctx->r2 < 0X13E8 ? 1 : 0;
            goto L_80192800;
    }
    // 0x801927F0: sltiu       $at, $v0, 0x13E8
    ctx->r1 = ctx->r2 < 0X13E8 ? 1 : 0;
    // 0x801927F4: beq         $at, $zero, L_80192800
    if (ctx->r1 == 0) {
        // 0x801927F8: addiu       $t9, $zero, 0x13E8
        ctx->r25 = ADD32(0, 0X13E8);
            goto L_80192800;
    }
    // 0x801927F8: addiu       $t9, $zero, 0x13E8
    ctx->r25 = ADD32(0, 0X13E8);
    // 0x801927FC: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
L_80192800:
    // 0x80192800: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80192804: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80192808: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8019280C: jr          $ra
    // 0x80192810: nop

    return;
    // 0x80192810: nop

;}
RECOMP_FUNC void Unused_80187520(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80187520: jr          $ra
    // 0x80187524: nop

    return;
    // 0x80187524: nop

;}
RECOMP_FUNC void static_1_80024060(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80024060: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80024064: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x80024068: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002406C: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x80024070: slti        $at, $t6, 0x26
    ctx->r1 = SIGNED(ctx->r14) < 0X26 ? 1 : 0;
    // 0x80024074: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x80024078: sw          $zero, 0xC($s0)
    MEM_W(0XC, ctx->r16) = 0;
    // 0x8002407C: sw          $zero, 0x10($s0)
    MEM_W(0X10, ctx->r16) = 0;
    // 0x80024080: sw          $zero, 0x14($s0)
    MEM_W(0X14, ctx->r16) = 0;
    // 0x80024084: sw          $zero, 0x18($s0)
    MEM_W(0X18, ctx->r16) = 0;
    // 0x80024088: sw          $zero, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = 0;
    // 0x8002408C: sw          $zero, 0x20($s0)
    MEM_W(0X20, ctx->r16) = 0;
    // 0x80024090: bne         $at, $zero, L_800240BC
    if (ctx->r1 != 0) {
        // 0x80024094: or          $v1, $t6, $zero
        ctx->r3 = ctx->r14 | 0;
            goto L_800240BC;
    }
    // 0x80024094: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x80024098: addiu       $t7, $t6, -0x45
    ctx->r15 = ADD32(ctx->r14, -0X45);
    // 0x8002409C: sltiu       $at, $t7, 0x34
    ctx->r1 = ctx->r15 < 0X34 ? 1 : 0;
    // 0x800240A0: beq         $at, $zero, L_800246A8
    if (ctx->r1 == 0) {
        // 0x800240A4: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_800246A8;
    }
    // 0x800240A4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800240A8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800240AC: addu        $at, $at, $t7
    gpr jr_addend_800240B4 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800240B0: lw          $t7, -0x6BFC($at)
    ctx->r15 = ADD32(ctx->r1, -0X6BFC);
    // 0x800240B4: jr          $t7
    // 0x800240B8: nop

    switch (jr_addend_800240B4 >> 2) {
        case 0: goto L_800243C8; break;
        case 1: goto L_800246A8; break;
        case 2: goto L_800243C8; break;
        case 3: goto L_800246A8; break;
        case 4: goto L_800246A8; break;
        case 5: goto L_800246A8; break;
        case 6: goto L_800246A8; break;
        case 7: goto L_800246A8; break;
        case 8: goto L_800246A8; break;
        case 9: goto L_800246A8; break;
        case 10: goto L_800246A8; break;
        case 11: goto L_800246A8; break;
        case 12: goto L_800246A8; break;
        case 13: goto L_800246A8; break;
        case 14: goto L_800246A8; break;
        case 15: goto L_800246A8; break;
        case 16: goto L_800246A8; break;
        case 17: goto L_800246A8; break;
        case 18: goto L_800246A8; break;
        case 19: goto L_80024278; break;
        case 20: goto L_800246A8; break;
        case 21: goto L_800246A8; break;
        case 22: goto L_800246A8; break;
        case 23: goto L_800246A8; break;
        case 24: goto L_800246A8; break;
        case 25: goto L_800246A8; break;
        case 26: goto L_800246A8; break;
        case 27: goto L_800246A8; break;
        case 28: goto L_800246A8; break;
        case 29: goto L_800246A8; break;
        case 30: goto L_800240D0; break;
        case 31: goto L_80024108; break;
        case 32: goto L_800243C8; break;
        case 33: goto L_800243C8; break;
        case 34: goto L_800243C8; break;
        case 35: goto L_800246A8; break;
        case 36: goto L_80024108; break;
        case 37: goto L_800246A8; break;
        case 38: goto L_800246A8; break;
        case 39: goto L_800246A8; break;
        case 40: goto L_800246A8; break;
        case 41: goto L_8002452C; break;
        case 42: goto L_80024278; break;
        case 43: goto L_800245FC; break;
        case 44: goto L_800246A8; break;
        case 45: goto L_800246A8; break;
        case 46: goto L_80024644; break;
        case 47: goto L_800246A8; break;
        case 48: goto L_80024278; break;
        case 49: goto L_800246A8; break;
        case 50: goto L_800246A8; break;
        case 51: goto L_80024278; break;
        default: switch_error(__func__, 0x800240B4, 0x800C9404);
    }
    // 0x800240B8: nop

L_800240BC:
    // 0x800240BC: addiu       $at, $zero, 0x25
    ctx->r1 = ADD32(0, 0X25);
    // 0x800240C0: beql        $v1, $at, L_8002468C
    if (ctx->r3 == ctx->r1) {
        // 0x800240C4: lw          $t8, 0xC($s0)
        ctx->r24 = MEM_W(ctx->r16, 0XC);
            goto L_8002468C;
    }
    goto skip_0;
    // 0x800240C4: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    skip_0:
    // 0x800240C8: b           L_800246AC
    // 0x800240CC: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
        goto L_800246AC;
    // 0x800240CC: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
L_800240D0:
    // 0x800240D0: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x800240D4: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800240D8: addiu       $t9, $t8, 0x3
    ctx->r25 = ADD32(ctx->r24, 0X3);
    // 0x800240DC: and         $t6, $t9, $at
    ctx->r14 = ctx->r25 & ctx->r1;
    // 0x800240E0: addiu       $t7, $t6, 0x4
    ctx->r15 = ADD32(ctx->r14, 0X4);
    // 0x800240E4: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x800240E8: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x800240EC: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x800240F0: addu        $t7, $a3, $t6
    ctx->r15 = ADD32(ctx->r7, ctx->r14);
    // 0x800240F4: sb          $t9, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r25;
    // 0x800240F8: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    // 0x800240FC: addiu       $t6, $t8, 0x1
    ctx->r14 = ADD32(ctx->r24, 0X1);
    // 0x80024100: b           L_800246C0
    // 0x80024104: sw          $t6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r14;
        goto L_800246C0;
    // 0x80024104: sw          $t6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r14;
L_80024108:
    // 0x80024108: lbu         $v0, 0x34($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X34);
    // 0x8002410C: addiu       $at, $zero, 0x6C
    ctx->r1 = ADD32(0, 0X6C);
    // 0x80024110: bnel        $v0, $at, L_80024148
    if (ctx->r2 != ctx->r1) {
        // 0x80024114: addiu       $at, $zero, 0x4C
        ctx->r1 = ADD32(0, 0X4C);
            goto L_80024148;
    }
    goto skip_1;
    // 0x80024114: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
    skip_1:
    // 0x80024118: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x8002411C: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80024120: addiu       $t7, $t9, 0x3
    ctx->r15 = ADD32(ctx->r25, 0X3);
    // 0x80024124: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x80024128: addiu       $t6, $t8, 0x4
    ctx->r14 = ADD32(ctx->r24, 0X4);
    // 0x8002412C: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x80024130: lw          $t7, -0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X4);
    // 0x80024134: sra         $t8, $t7, 31
    ctx->r24 = S32(SIGNED(ctx->r15) >> 31);
    // 0x80024138: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8002413C: b           L_800241A4
    // 0x80024140: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
        goto L_800241A4;
    // 0x80024140: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
    // 0x80024144: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
L_80024148:
    // 0x80024148: bnel        $v0, $at, L_80024180
    if (ctx->r2 != ctx->r1) {
        // 0x8002414C: lw          $t7, 0x0($a2)
        ctx->r15 = MEM_W(ctx->r6, 0X0);
            goto L_80024180;
    }
    goto skip_2;
    // 0x8002414C: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    skip_2:
    // 0x80024150: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x80024154: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x80024158: addiu       $t7, $t6, 0x7
    ctx->r15 = ADD32(ctx->r14, 0X7);
    // 0x8002415C: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x80024160: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x80024164: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x80024168: lw          $t8, -0x8($t9)
    ctx->r24 = MEM_W(ctx->r25, -0X8);
    // 0x8002416C: lw          $t9, -0x4($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4);
    // 0x80024170: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80024174: b           L_800241A4
    // 0x80024178: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
        goto L_800241A4;
    // 0x80024178: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
    // 0x8002417C: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
L_80024180:
    // 0x80024180: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80024184: addiu       $t6, $t7, 0x3
    ctx->r14 = ADD32(ctx->r15, 0X3);
    // 0x80024188: and         $t8, $t6, $at
    ctx->r24 = ctx->r14 & ctx->r1;
    // 0x8002418C: addiu       $t9, $t8, 0x4
    ctx->r25 = ADD32(ctx->r24, 0X4);
    // 0x80024190: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x80024194: lw          $t6, -0x4($t9)
    ctx->r14 = MEM_W(ctx->r25, -0X4);
    // 0x80024198: sra         $t8, $t6, 31
    ctx->r24 = S32(SIGNED(ctx->r14) >> 31);
    // 0x8002419C: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800241A0: sw          $t6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r14;
L_800241A4:
    // 0x800241A4: lbu         $t7, 0x34($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X34);
    // 0x800241A8: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x800241AC: bnel        $t7, $at, L_800241D0
    if (ctx->r15 != ctx->r1) {
        // 0x800241B0: lw          $t6, 0x0($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X0);
            goto L_800241D0;
    }
    goto skip_3;
    // 0x800241B0: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    skip_3:
    // 0x800241B4: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x800241B8: sll         $t9, $t7, 16
    ctx->r25 = S32(ctx->r15 << 16);
    // 0x800241BC: sra         $t6, $t9, 16
    ctx->r14 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800241C0: sra         $t8, $t6, 31
    ctx->r24 = S32(SIGNED(ctx->r14) >> 31);
    // 0x800241C4: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800241C8: sw          $t6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r14;
    // 0x800241CC: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
L_800241D0:
    // 0x800241D0: bgtzl       $t6, L_8002420C
    if (SIGNED(ctx->r14) > 0) {
        // 0x800241D4: lw          $v0, 0x30($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X30);
            goto L_8002420C;
    }
    goto skip_4;
    // 0x800241D4: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
    skip_4:
    // 0x800241D8: bltzl       $t6, L_800241EC
    if (SIGNED(ctx->r14) < 0) {
        // 0x800241DC: lw          $t9, 0xC($s0)
        ctx->r25 = MEM_W(ctx->r16, 0XC);
            goto L_800241EC;
    }
    goto skip_5;
    // 0x800241DC: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    skip_5:
    // 0x800241E0: b           L_8002420C
    // 0x800241E4: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
        goto L_8002420C;
    // 0x800241E4: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
    // 0x800241E8: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
L_800241EC:
    // 0x800241EC: addiu       $t8, $zero, 0x2D
    ctx->r24 = ADD32(0, 0X2D);
    // 0x800241F0: addu        $t6, $a3, $t9
    ctx->r14 = ADD32(ctx->r7, ctx->r25);
    // 0x800241F4: sb          $t8, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r24;
    // 0x800241F8: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x800241FC: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x80024200: b           L_8002425C
    // 0x80024204: sw          $t9, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r25;
        goto L_8002425C;
    // 0x80024204: sw          $t9, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r25;
    // 0x80024208: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
L_8002420C:
    // 0x8002420C: andi        $t8, $v0, 0x2
    ctx->r24 = ctx->r2 & 0X2;
    // 0x80024210: beq         $t8, $zero, L_80024238
    if (ctx->r24 == 0) {
        // 0x80024214: andi        $t6, $v0, 0x1
        ctx->r14 = ctx->r2 & 0X1;
            goto L_80024238;
    }
    // 0x80024214: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x80024218: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x8002421C: addiu       $t6, $zero, 0x2B
    ctx->r14 = ADD32(0, 0X2B);
    // 0x80024220: addu        $t9, $a3, $t7
    ctx->r25 = ADD32(ctx->r7, ctx->r15);
    // 0x80024224: sb          $t6, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r14;
    // 0x80024228: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    // 0x8002422C: addiu       $t7, $t8, 0x1
    ctx->r15 = ADD32(ctx->r24, 0X1);
    // 0x80024230: b           L_8002425C
    // 0x80024234: sw          $t7, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r15;
        goto L_8002425C;
    // 0x80024234: sw          $t7, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r15;
L_80024238:
    // 0x80024238: beql        $t6, $zero, L_80024260
    if (ctx->r14 == 0) {
        // 0x8002423C: lw          $t9, 0xC($s0)
        ctx->r25 = MEM_W(ctx->r16, 0XC);
            goto L_80024260;
    }
    goto skip_6;
    // 0x8002423C: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    skip_6:
    // 0x80024240: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    // 0x80024244: addiu       $t9, $zero, 0x20
    ctx->r25 = ADD32(0, 0X20);
    // 0x80024248: addu        $t7, $a3, $t8
    ctx->r15 = ADD32(ctx->r7, ctx->r24);
    // 0x8002424C: sb          $t9, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r25;
    // 0x80024250: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x80024254: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x80024258: sw          $t8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r24;
L_8002425C:
    // 0x8002425C: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
L_80024260:
    // 0x80024260: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80024264: addu        $t7, $t9, $a3
    ctx->r15 = ADD32(ctx->r25, ctx->r7);
    // 0x80024268: jal         0x80028DE0
    // 0x8002426C: sw          $t7, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r15;
    _Litob(rdram, ctx);
        goto after_0;
    // 0x8002426C: sw          $t7, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r15;
    after_0:
    // 0x80024270: b           L_800246C4
    // 0x80024274: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800246C4;
    // 0x80024274: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80024278:
    // 0x80024278: lbu         $v0, 0x34($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X34);
    // 0x8002427C: addiu       $at, $zero, 0x6C
    ctx->r1 = ADD32(0, 0X6C);
    // 0x80024280: bnel        $v0, $at, L_800242B8
    if (ctx->r2 != ctx->r1) {
        // 0x80024284: addiu       $at, $zero, 0x4C
        ctx->r1 = ADD32(0, 0X4C);
            goto L_800242B8;
    }
    goto skip_7;
    // 0x80024284: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
    skip_7:
    // 0x80024288: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x8002428C: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80024290: addiu       $t8, $t6, 0x3
    ctx->r24 = ADD32(ctx->r14, 0X3);
    // 0x80024294: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x80024298: addiu       $t7, $t9, 0x4
    ctx->r15 = ADD32(ctx->r25, 0X4);
    // 0x8002429C: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x800242A0: lw          $t8, -0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X4);
    // 0x800242A4: sra         $t6, $t8, 31
    ctx->r14 = S32(SIGNED(ctx->r24) >> 31);
    // 0x800242A8: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800242AC: b           L_80024314
    // 0x800242B0: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
        goto L_80024314;
    // 0x800242B0: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
    // 0x800242B4: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
L_800242B8:
    // 0x800242B8: bnel        $v0, $at, L_800242F0
    if (ctx->r2 != ctx->r1) {
        // 0x800242BC: lw          $t6, 0x0($a2)
        ctx->r14 = MEM_W(ctx->r6, 0X0);
            goto L_800242F0;
    }
    goto skip_8;
    // 0x800242BC: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    skip_8:
    // 0x800242C0: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x800242C4: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x800242C8: addiu       $t8, $t9, 0x7
    ctx->r24 = ADD32(ctx->r25, 0X7);
    // 0x800242CC: and         $t6, $t8, $at
    ctx->r14 = ctx->r24 & ctx->r1;
    // 0x800242D0: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800242D4: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x800242D8: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x800242DC: lw          $t8, -0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X8);
    // 0x800242E0: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
    // 0x800242E4: b           L_80024314
    // 0x800242E8: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
        goto L_80024314;
    // 0x800242E8: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800242EC: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
L_800242F0:
    // 0x800242F0: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800242F4: addiu       $t7, $t6, 0x3
    ctx->r15 = ADD32(ctx->r14, 0X3);
    // 0x800242F8: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x800242FC: addiu       $t9, $t8, 0x4
    ctx->r25 = ADD32(ctx->r24, 0X4);
    // 0x80024300: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x80024304: lw          $t7, -0x4($t9)
    ctx->r15 = MEM_W(ctx->r25, -0X4);
    // 0x80024308: sra         $t8, $t7, 31
    ctx->r24 = S32(SIGNED(ctx->r15) >> 31);
    // 0x8002430C: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80024310: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
L_80024314:
    // 0x80024314: lbu         $v0, 0x34($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X34);
    // 0x80024318: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x8002431C: bne         $v0, $at, L_8002433C
    if (ctx->r2 != ctx->r1) {
        // 0x80024320: nop
    
            goto L_8002433C;
    }
    // 0x80024320: nop

    // 0x80024324: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x80024328: addiu       $t6, $zero, 0x0
    ctx->r14 = ADD32(0, 0X0);
    // 0x8002432C: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80024330: andi        $t9, $t7, 0xFFFF
    ctx->r25 = ctx->r15 & 0XFFFF;
    // 0x80024334: b           L_80024354
    // 0x80024338: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
        goto L_80024354;
    // 0x80024338: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
L_8002433C:
    // 0x8002433C: bnel        $v0, $zero, L_80024358
    if (ctx->r2 != 0) {
        // 0x80024340: lw          $t7, 0x30($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X30);
            goto L_80024358;
    }
    goto skip_9;
    // 0x80024340: lw          $t7, 0x30($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X30);
    skip_9:
    // 0x80024344: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x80024348: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x8002434C: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80024350: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
L_80024354:
    // 0x80024354: lw          $t7, 0x30($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X30);
L_80024358:
    // 0x80024358: andi        $t6, $t7, 0x8
    ctx->r14 = ctx->r15 & 0X8;
    // 0x8002435C: beql        $t6, $zero, L_800243B0
    if (ctx->r14 == 0) {
        // 0x80024360: lw          $t8, 0xC($s0)
        ctx->r24 = MEM_W(ctx->r16, 0XC);
            goto L_800243B0;
    }
    goto skip_10;
    // 0x80024360: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    skip_10:
    // 0x80024364: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    // 0x80024368: addiu       $t8, $zero, 0x30
    ctx->r24 = ADD32(0, 0X30);
    // 0x8002436C: addiu       $at, $zero, 0x78
    ctx->r1 = ADD32(0, 0X78);
    // 0x80024370: addu        $t7, $a3, $t9
    ctx->r15 = ADD32(ctx->r7, ctx->r25);
    // 0x80024374: sb          $t8, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r24;
    // 0x80024378: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x8002437C: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x80024380: beq         $v1, $at, L_80024394
    if (ctx->r3 == ctx->r1) {
        // 0x80024384: sw          $t9, 0xC($s0)
        MEM_W(0XC, ctx->r16) = ctx->r25;
            goto L_80024394;
    }
    // 0x80024384: sw          $t9, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r25;
    // 0x80024388: addiu       $at, $zero, 0x58
    ctx->r1 = ADD32(0, 0X58);
    // 0x8002438C: bnel        $v1, $at, L_800243B0
    if (ctx->r3 != ctx->r1) {
        // 0x80024390: lw          $t8, 0xC($s0)
        ctx->r24 = MEM_W(ctx->r16, 0XC);
            goto L_800243B0;
    }
    goto skip_11;
    // 0x80024390: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    skip_11:
L_80024394:
    // 0x80024394: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    // 0x80024398: addu        $t7, $a3, $t8
    ctx->r15 = ADD32(ctx->r7, ctx->r24);
    // 0x8002439C: sb          $a1, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r5;
    // 0x800243A0: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x800243A4: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x800243A8: sw          $t9, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r25;
    // 0x800243AC: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
L_800243B0:
    // 0x800243B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800243B4: addu        $t7, $t8, $a3
    ctx->r15 = ADD32(ctx->r24, ctx->r7);
    // 0x800243B8: jal         0x80028DE0
    // 0x800243BC: sw          $t7, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r15;
    _Litob(rdram, ctx);
        goto after_1;
    // 0x800243BC: sw          $t7, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r15;
    after_1:
    // 0x800243C0: b           L_800246C4
    // 0x800243C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800246C4;
    // 0x800243C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800243C8:
    // 0x800243C8: lbu         $t6, 0x34($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X34);
    // 0x800243CC: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
    // 0x800243D0: bnel        $t6, $at, L_80024438
    if (ctx->r14 != ctx->r1) {
        // 0x800243D4: lw          $v0, 0x0($a2)
        ctx->r2 = MEM_W(ctx->r6, 0X0);
            goto L_80024438;
    }
    goto skip_12;
    // 0x800243D4: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    skip_12:
    // 0x800243D8: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x800243DC: andi        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 & 0X1;
    // 0x800243E0: beq         $t9, $zero, L_800243F8
    if (ctx->r25 == 0) {
        // 0x800243E4: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800243F8;
    }
    // 0x800243E4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800243E8: addiu       $t8, $v1, 0x7
    ctx->r24 = ADD32(ctx->r3, 0X7);
    // 0x800243EC: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x800243F0: b           L_80024428
    // 0x800243F4: addiu       $v0, $t8, -0x16
    ctx->r2 = ADD32(ctx->r24, -0X16);
        goto L_80024428;
    // 0x800243F4: addiu       $v0, $t8, -0x16
    ctx->r2 = ADD32(ctx->r24, -0X16);
L_800243F8:
    // 0x800243F8: andi        $t7, $v1, 0x2
    ctx->r15 = ctx->r3 & 0X2;
    // 0x800243FC: beq         $t7, $zero, L_80024414
    if (ctx->r15 == 0) {
        // 0x80024400: addiu       $t9, $v0, 0x7
        ctx->r25 = ADD32(ctx->r2, 0X7);
            goto L_80024414;
    }
    // 0x80024400: addiu       $t9, $v0, 0x7
    ctx->r25 = ADD32(ctx->r2, 0X7);
    // 0x80024404: addiu       $t6, $v1, 0xA
    ctx->r14 = ADD32(ctx->r3, 0XA);
    // 0x80024408: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x8002440C: b           L_80024424
    // 0x80024410: addiu       $a0, $t6, -0x28
    ctx->r4 = ADD32(ctx->r14, -0X28);
        goto L_80024424;
    // 0x80024410: addiu       $a0, $t6, -0x28
    ctx->r4 = ADD32(ctx->r14, -0X28);
L_80024414:
    // 0x80024414: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x80024418: and         $t8, $t9, $at
    ctx->r24 = ctx->r25 & ctx->r1;
    // 0x8002441C: addiu       $a0, $t8, 0x8
    ctx->r4 = ADD32(ctx->r24, 0X8);
    // 0x80024420: sw          $a0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r4;
L_80024424:
    // 0x80024424: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_80024428:
    // 0x80024428: ldc1        $f4, -0x8($v0)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r2, -0X8);
    // 0x8002442C: b           L_8002448C
    // 0x80024430: sdc1        $f4, 0x0($s0)
    CHECK_FR(ctx, 4);
    SD(ctx->f4.u64, 0X0, ctx->r16);
        goto L_8002448C;
    // 0x80024430: sdc1        $f4, 0x0($s0)
    CHECK_FR(ctx, 4);
    SD(ctx->f4.u64, 0X0, ctx->r16);
    // 0x80024434: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
L_80024438:
    // 0x80024438: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x8002443C: beq         $t6, $zero, L_80024454
    if (ctx->r14 == 0) {
        // 0x80024440: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80024454;
    }
    // 0x80024440: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80024444: addiu       $t9, $v1, 0x7
    ctx->r25 = ADD32(ctx->r3, 0X7);
    // 0x80024448: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x8002444C: b           L_80024484
    // 0x80024450: addiu       $v0, $t9, -0x16
    ctx->r2 = ADD32(ctx->r25, -0X16);
        goto L_80024484;
    // 0x80024450: addiu       $v0, $t9, -0x16
    ctx->r2 = ADD32(ctx->r25, -0X16);
L_80024454:
    // 0x80024454: andi        $t8, $v1, 0x2
    ctx->r24 = ctx->r3 & 0X2;
    // 0x80024458: beq         $t8, $zero, L_80024470
    if (ctx->r24 == 0) {
        // 0x8002445C: addiu       $t6, $v0, 0x7
        ctx->r14 = ADD32(ctx->r2, 0X7);
            goto L_80024470;
    }
    // 0x8002445C: addiu       $t6, $v0, 0x7
    ctx->r14 = ADD32(ctx->r2, 0X7);
    // 0x80024460: addiu       $t7, $v1, 0xA
    ctx->r15 = ADD32(ctx->r3, 0XA);
    // 0x80024464: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x80024468: b           L_80024480
    // 0x8002446C: addiu       $a0, $t7, -0x28
    ctx->r4 = ADD32(ctx->r15, -0X28);
        goto L_80024480;
    // 0x8002446C: addiu       $a0, $t7, -0x28
    ctx->r4 = ADD32(ctx->r15, -0X28);
L_80024470:
    // 0x80024470: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x80024474: and         $t9, $t6, $at
    ctx->r25 = ctx->r14 & ctx->r1;
    // 0x80024478: addiu       $a0, $t9, 0x8
    ctx->r4 = ADD32(ctx->r25, 0X8);
    // 0x8002447C: sw          $a0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r4;
L_80024480:
    // 0x80024480: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_80024484:
    // 0x80024484: ldc1        $f6, -0x8($v0)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r2, -0X8);
    // 0x80024488: sdc1        $f6, 0x0($s0)
    CHECK_FR(ctx, 6);
    SD(ctx->f6.u64, 0X0, ctx->r16);
L_8002448C:
    // 0x8002448C: lhu         $t7, 0x0($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X0);
    // 0x80024490: andi        $t6, $t7, 0x8000
    ctx->r14 = ctx->r15 & 0X8000;
    // 0x80024494: beql        $t6, $zero, L_800244C0
    if (ctx->r14 == 0) {
        // 0x80024498: lw          $v0, 0x30($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X30);
            goto L_800244C0;
    }
    goto skip_13;
    // 0x80024498: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
    skip_13:
    // 0x8002449C: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    // 0x800244A0: addiu       $t9, $zero, 0x2D
    ctx->r25 = ADD32(0, 0X2D);
    // 0x800244A4: addu        $t7, $a3, $t8
    ctx->r15 = ADD32(ctx->r7, ctx->r24);
    // 0x800244A8: sb          $t9, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r25;
    // 0x800244AC: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x800244B0: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x800244B4: b           L_80024510
    // 0x800244B8: sw          $t8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r24;
        goto L_80024510;
    // 0x800244B8: sw          $t8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r24;
    // 0x800244BC: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
L_800244C0:
    // 0x800244C0: andi        $t9, $v0, 0x2
    ctx->r25 = ctx->r2 & 0X2;
    // 0x800244C4: beq         $t9, $zero, L_800244EC
    if (ctx->r25 == 0) {
        // 0x800244C8: andi        $t7, $v0, 0x1
        ctx->r15 = ctx->r2 & 0X1;
            goto L_800244EC;
    }
    // 0x800244C8: andi        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 & 0X1;
    // 0x800244CC: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x800244D0: addiu       $t7, $zero, 0x2B
    ctx->r15 = ADD32(0, 0X2B);
    // 0x800244D4: addu        $t8, $a3, $t6
    ctx->r24 = ADD32(ctx->r7, ctx->r14);
    // 0x800244D8: sb          $t7, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r15;
    // 0x800244DC: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    // 0x800244E0: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x800244E4: b           L_80024510
    // 0x800244E8: sw          $t6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r14;
        goto L_80024510;
    // 0x800244E8: sw          $t6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r14;
L_800244EC:
    // 0x800244EC: beql        $t7, $zero, L_80024514
    if (ctx->r15 == 0) {
        // 0x800244F0: lw          $t8, 0xC($s0)
        ctx->r24 = MEM_W(ctx->r16, 0XC);
            goto L_80024514;
    }
    goto skip_14;
    // 0x800244F0: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    skip_14:
    // 0x800244F4: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    // 0x800244F8: addiu       $t8, $zero, 0x20
    ctx->r24 = ADD32(0, 0X20);
    // 0x800244FC: addu        $t6, $a3, $t9
    ctx->r14 = ADD32(ctx->r7, ctx->r25);
    // 0x80024500: sb          $t8, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r24;
    // 0x80024504: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x80024508: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x8002450C: sw          $t9, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r25;
L_80024510:
    // 0x80024510: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
L_80024514:
    // 0x80024514: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80024518: addu        $t6, $t8, $a3
    ctx->r14 = ADD32(ctx->r24, ctx->r7);
    // 0x8002451C: jal         0x800295F0
    // 0x80024520: sw          $t6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r14;
    _Ldtob(rdram, ctx);
        goto after_2;
    // 0x80024520: sw          $t6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r14;
    after_2:
    // 0x80024524: b           L_800246C4
    // 0x80024528: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800246C4;
    // 0x80024528: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8002452C:
    // 0x8002452C: lbu         $v0, 0x34($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X34);
    // 0x80024530: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x80024534: bnel        $v0, $at, L_80024568
    if (ctx->r2 != ctx->r1) {
        // 0x80024538: addiu       $at, $zero, 0x6C
        ctx->r1 = ADD32(0, 0X6C);
            goto L_80024568;
    }
    goto skip_15;
    // 0x80024538: addiu       $at, $zero, 0x6C
    ctx->r1 = ADD32(0, 0X6C);
    skip_15:
    // 0x8002453C: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x80024540: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80024544: addiu       $t9, $t7, 0x3
    ctx->r25 = ADD32(ctx->r15, 0X3);
    // 0x80024548: and         $t8, $t9, $at
    ctx->r24 = ctx->r25 & ctx->r1;
    // 0x8002454C: addiu       $t6, $t8, 0x4
    ctx->r14 = ADD32(ctx->r24, 0X4);
    // 0x80024550: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x80024554: lw          $t9, -0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, -0X4);
    // 0x80024558: lw          $t7, 0x2C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X2C);
    // 0x8002455C: b           L_800246C0
    // 0x80024560: sh          $t7, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r15;
        goto L_800246C0;
    // 0x80024560: sh          $t7, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r15;
    // 0x80024564: addiu       $at, $zero, 0x6C
    ctx->r1 = ADD32(0, 0X6C);
L_80024568:
    // 0x80024568: bnel        $v0, $at, L_8002459C
    if (ctx->r2 != ctx->r1) {
        // 0x8002456C: addiu       $at, $zero, 0x4C
        ctx->r1 = ADD32(0, 0X4C);
            goto L_8002459C;
    }
    goto skip_16;
    // 0x8002456C: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
    skip_16:
    // 0x80024570: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x80024574: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80024578: addiu       $t6, $t8, 0x3
    ctx->r14 = ADD32(ctx->r24, 0X3);
    // 0x8002457C: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x80024580: addiu       $t9, $t7, 0x4
    ctx->r25 = ADD32(ctx->r15, 0X4);
    // 0x80024584: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x80024588: lw          $t6, -0x4($t9)
    ctx->r14 = MEM_W(ctx->r25, -0X4);
    // 0x8002458C: lw          $t8, 0x2C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X2C);
    // 0x80024590: b           L_800246C0
    // 0x80024594: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
        goto L_800246C0;
    // 0x80024594: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x80024598: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
L_8002459C:
    // 0x8002459C: bnel        $v0, $at, L_800245D8
    if (ctx->r2 != ctx->r1) {
        // 0x800245A0: lw          $t7, 0x0($a2)
        ctx->r15 = MEM_W(ctx->r6, 0X0);
            goto L_800245D8;
    }
    goto skip_17;
    // 0x800245A0: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    skip_17:
    // 0x800245A4: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x800245A8: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800245AC: addiu       $t9, $t7, 0x3
    ctx->r25 = ADD32(ctx->r15, 0X3);
    // 0x800245B0: and         $t8, $t9, $at
    ctx->r24 = ctx->r25 & ctx->r1;
    // 0x800245B4: addiu       $t6, $t8, 0x4
    ctx->r14 = ADD32(ctx->r24, 0X4);
    // 0x800245B8: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x800245BC: lw          $t6, -0x4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4);
    // 0x800245C0: lw          $t7, 0x2C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X2C);
    // 0x800245C4: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x800245C8: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x800245CC: b           L_800246C0
    // 0x800245D0: sw          $t7, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r15;
        goto L_800246C0;
    // 0x800245D0: sw          $t7, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r15;
    // 0x800245D4: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
L_800245D8:
    // 0x800245D8: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800245DC: addiu       $t8, $t7, 0x3
    ctx->r24 = ADD32(ctx->r15, 0X3);
    // 0x800245E0: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x800245E4: addiu       $t6, $t9, 0x4
    ctx->r14 = ADD32(ctx->r25, 0X4);
    // 0x800245E8: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x800245EC: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x800245F0: lw          $t7, 0x2C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X2C);
    // 0x800245F4: b           L_800246C0
    // 0x800245F8: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
        goto L_800246C0;
    // 0x800245F8: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
L_800245FC:
    // 0x800245FC: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x80024600: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80024604: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80024608: addiu       $t6, $t9, 0x3
    ctx->r14 = ADD32(ctx->r25, 0X3);
    // 0x8002460C: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x80024610: addiu       $t8, $t7, 0x4
    ctx->r24 = ADD32(ctx->r15, 0X4);
    // 0x80024614: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x80024618: lw          $t6, -0x4($t8)
    ctx->r14 = MEM_W(ctx->r24, -0X4);
    // 0x8002461C: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x80024620: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
    // 0x80024624: sra         $t8, $t6, 31
    ctx->r24 = S32(SIGNED(ctx->r14) >> 31);
    // 0x80024628: sw          $t6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r14;
    // 0x8002462C: addu        $t6, $t7, $a3
    ctx->r14 = ADD32(ctx->r15, ctx->r7);
    // 0x80024630: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80024634: jal         0x80028DE0
    // 0x80024638: sw          $t6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r14;
    _Litob(rdram, ctx);
        goto after_3;
    // 0x80024638: sw          $t6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r14;
    after_3:
    // 0x8002463C: b           L_800246C4
    // 0x80024640: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800246C4;
    // 0x80024640: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80024644:
    // 0x80024644: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x80024648: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8002464C: addiu       $t9, $t8, 0x3
    ctx->r25 = ADD32(ctx->r24, 0X3);
    // 0x80024650: and         $t7, $t9, $at
    ctx->r15 = ctx->r25 & ctx->r1;
    // 0x80024654: addiu       $t6, $t7, 0x4
    ctx->r14 = ADD32(ctx->r15, 0X4);
    // 0x80024658: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x8002465C: lw          $a0, -0x4($t6)
    ctx->r4 = MEM_W(ctx->r14, -0X4);
    // 0x80024660: jal         0x80023FEC
    // 0x80024664: sw          $a0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r4;
    strlen_recomp(rdram, ctx);
        goto after_4;
    // 0x80024664: sw          $a0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r4;
    after_4:
    // 0x80024668: lw          $v1, 0x24($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X24);
    // 0x8002466C: sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
    // 0x80024670: bltz        $v1, L_800246C0
    if (SIGNED(ctx->r3) < 0) {
        // 0x80024674: slt         $at, $v1, $v0
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_800246C0;
    }
    // 0x80024674: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80024678: beql        $at, $zero, L_800246C4
    if (ctx->r1 == 0) {
        // 0x8002467C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800246C4;
    }
    goto skip_18;
    // 0x8002467C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_18:
    // 0x80024680: b           L_800246C0
    // 0x80024684: sw          $v1, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r3;
        goto L_800246C0;
    // 0x80024684: sw          $v1, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r3;
    // 0x80024688: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
L_8002468C:
    // 0x8002468C: addiu       $t6, $zero, 0x25
    ctx->r14 = ADD32(0, 0X25);
    // 0x80024690: addu        $t9, $a3, $t8
    ctx->r25 = ADD32(ctx->r7, ctx->r24);
    // 0x80024694: sb          $t6, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r14;
    // 0x80024698: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x8002469C: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800246A0: b           L_800246C0
    // 0x800246A4: sw          $t8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r24;
        goto L_800246C0;
    // 0x800246A4: sw          $t8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r24;
L_800246A8:
    // 0x800246A8: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
L_800246AC:
    // 0x800246AC: addu        $t9, $a3, $t6
    ctx->r25 = ADD32(ctx->r7, ctx->r14);
    // 0x800246B0: sb          $a1, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r5;
    // 0x800246B4: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x800246B8: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800246BC: sw          $t8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r24;
L_800246C0:
    // 0x800246C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800246C4:
    // 0x800246C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800246C8: jr          $ra
    // 0x800246CC: nop

    return;
    // 0x800246CC: nop

;}
RECOMP_FUNC void static_1_80029080(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029080: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80029084: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80029088: sll         $t6, $s2, 16
    ctx->r14 = S32(ctx->r18 << 16);
    // 0x8002908C: sra         $s2, $t6, 16
    ctx->r18 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80029090: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80029094: sll         $t8, $s3, 16
    ctx->r24 = S32(ctx->r19 << 16);
    // 0x80029098: sra         $s3, $t8, 16
    ctx->r19 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8002909C: andi        $t6, $s4, 0xFF
    ctx->r14 = ctx->r20 & 0XFF;
    // 0x800290A0: sw          $s4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r20;
    // 0x800290A4: or          $s4, $t6, $zero
    ctx->r20 = ctx->r14 | 0;
    // 0x800290A8: bgtz        $s3, L_800290BC
    if (SIGNED(ctx->r19) > 0) {
        // 0x800290AC: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800290BC;
    }
    // 0x800290AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800290B0: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    // 0x800290B4: addiu       $s1, $s1, -0x6A30
    ctx->r17 = ADD32(ctx->r17, -0X6A30);
    // 0x800290B8: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
L_800290BC:
    // 0x800290BC: addiu       $v0, $zero, 0x66
    ctx->r2 = ADD32(0, 0X66);
    // 0x800290C0: beq         $v0, $s4, L_800290F4
    if (ctx->r2 == ctx->r20) {
        // 0x800290C4: or          $v1, $s4, $zero
        ctx->r3 = ctx->r20 | 0;
            goto L_800290F4;
    }
    // 0x800290C4: or          $v1, $s4, $zero
    ctx->r3 = ctx->r20 | 0;
    // 0x800290C8: addiu       $a0, $zero, 0x67
    ctx->r4 = ADD32(0, 0X67);
    // 0x800290CC: beq         $a0, $v1, L_800290D8
    if (ctx->r4 == ctx->r3) {
        // 0x800290D0: addiu       $at, $zero, 0x47
        ctx->r1 = ADD32(0, 0X47);
            goto L_800290D8;
    }
    // 0x800290D0: addiu       $at, $zero, 0x47
    ctx->r1 = ADD32(0, 0X47);
    // 0x800290D4: bne         $v1, $at, L_80029330
    if (ctx->r3 != ctx->r1) {
        // 0x800290D8: slti        $at, $s2, -0x4
        ctx->r1 = SIGNED(ctx->r18) < -0X4 ? 1 : 0;
            goto L_80029330;
    }
L_800290D8:
    // 0x800290D8: slti        $at, $s2, -0x4
    ctx->r1 = SIGNED(ctx->r18) < -0X4 ? 1 : 0;
    // 0x800290DC: bne         $at, $zero, L_80029330
    if (ctx->r1 != 0) {
        // 0x800290E0: nop
    
            goto L_80029330;
    }
    // 0x800290E0: nop

    // 0x800290E4: lw          $t7, 0x24($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X24);
    // 0x800290E8: slt         $at, $s2, $t7
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800290EC: beq         $at, $zero, L_80029330
    if (ctx->r1 == 0) {
        // 0x800290F0: nop
    
            goto L_80029330;
    }
    // 0x800290F0: nop

L_800290F4:
    // 0x800290F4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800290F8: sll         $t8, $s2, 16
    ctx->r24 = S32(ctx->r18 << 16);
    // 0x800290FC: beq         $v0, $v1, L_80029138
    if (ctx->r2 == ctx->r3) {
        // 0x80029100: sra         $s2, $t8, 16
        ctx->r18 = S32(SIGNED(ctx->r24) >> 16);
            goto L_80029138;
    }
    // 0x80029100: sra         $s2, $t8, 16
    ctx->r18 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80029104: lw          $t6, 0x30($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X30);
    // 0x80029108: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x8002910C: andi        $t7, $t6, 0x8
    ctx->r15 = ctx->r14 & 0X8;
    // 0x80029110: bne         $t7, $zero, L_80029128
    if (ctx->r15 != 0) {
        // 0x80029114: slt         $at, $s3, $v0
        ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_80029128;
    }
    // 0x80029114: slt         $at, $s3, $v0
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80029118: beql        $at, $zero, L_8002912C
    if (ctx->r1 == 0) {
        // 0x8002911C: subu        $t8, $v0, $s2
        ctx->r24 = SUB32(ctx->r2, ctx->r18);
            goto L_8002912C;
    }
    goto skip_0;
    // 0x8002911C: subu        $t8, $v0, $s2
    ctx->r24 = SUB32(ctx->r2, ctx->r18);
    skip_0:
    // 0x80029120: sw          $s3, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r19;
    // 0x80029124: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
L_80029128:
    // 0x80029128: subu        $t8, $v0, $s2
    ctx->r24 = SUB32(ctx->r2, ctx->r18);
L_8002912C:
    // 0x8002912C: bgez        $t8, L_80029138
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80029130: sw          $t8, 0x24($s0)
        MEM_W(0X24, ctx->r16) = ctx->r24;
            goto L_80029138;
    }
    // 0x80029130: sw          $t8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r24;
    // 0x80029134: sw          $zero, 0x24($s0)
    MEM_W(0X24, ctx->r16) = 0;
L_80029138:
    // 0x80029138: bgtz        $s2, L_80029208
    if (SIGNED(ctx->r18) > 0) {
        // 0x8002913C: slt         $at, $s3, $s2
        ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r18) ? 1 : 0;
            goto L_80029208;
    }
    // 0x8002913C: slt         $at, $s3, $s2
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x80029140: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x80029144: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x80029148: addiu       $t6, $zero, 0x30
    ctx->r14 = ADD32(0, 0X30);
    // 0x8002914C: negu        $v1, $s2
    ctx->r3 = SUB32(0, ctx->r18);
    // 0x80029150: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80029154: sb          $t6, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r14;
    // 0x80029158: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x8002915C: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x80029160: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80029164: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80029168: bgtz        $v0, L_80029180
    if (SIGNED(ctx->r2) > 0) {
        // 0x8002916C: sw          $t8, 0x14($s0)
        MEM_W(0X14, ctx->r16) = ctx->r24;
            goto L_80029180;
    }
    // 0x8002916C: sw          $t8, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r24;
    // 0x80029170: lw          $t6, 0x30($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X30);
    // 0x80029174: andi        $t9, $t6, 0x8
    ctx->r25 = ctx->r14 & 0X8;
    // 0x80029178: beql        $t9, $zero, L_800291A8
    if (ctx->r25 == 0) {
        // 0x8002917C: slt         $at, $v0, $v1
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_800291A8;
    }
    goto skip_1;
    // 0x8002917C: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    skip_1:
L_80029180:
    // 0x80029180: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x80029184: lw          $t6, 0x14($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X14);
    // 0x80029188: addiu       $t7, $zero, 0x2E
    ctx->r15 = ADD32(0, 0X2E);
    // 0x8002918C: addu        $t9, $t8, $t6
    ctx->r25 = ADD32(ctx->r24, ctx->r14);
    // 0x80029190: sb          $t7, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r15;
    // 0x80029194: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x80029198: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x8002919C: addiu       $t6, $t8, 0x1
    ctx->r14 = ADD32(ctx->r24, 0X1);
    // 0x800291A0: sw          $t6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r14;
    // 0x800291A4: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
L_800291A8:
    // 0x800291A8: beql        $at, $zero, L_800291C4
    if (ctx->r1 == 0) {
        // 0x800291AC: addu        $t8, $v0, $s2
        ctx->r24 = ADD32(ctx->r2, ctx->r18);
            goto L_800291C4;
    }
    goto skip_2;
    // 0x800291AC: addu        $t8, $v0, $s2
    ctx->r24 = ADD32(ctx->r2, ctx->r18);
    skip_2:
    // 0x800291B0: negu        $s2, $v0
    ctx->r18 = SUB32(0, ctx->r2);
    // 0x800291B4: sll         $t7, $s2, 16
    ctx->r15 = S32(ctx->r18 << 16);
    // 0x800291B8: sra         $s2, $t7, 16
    ctx->r18 = S32(SIGNED(ctx->r15) >> 16);
    // 0x800291BC: negu        $v1, $s2
    ctx->r3 = SUB32(0, ctx->r18);
    // 0x800291C0: addu        $t8, $v0, $s2
    ctx->r24 = ADD32(ctx->r2, ctx->r18);
L_800291C4:
    // 0x800291C4: slt         $at, $t8, $s3
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x800291C8: sw          $v1, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r3;
    // 0x800291CC: beq         $at, $zero, L_800291E0
    if (ctx->r1 == 0) {
        // 0x800291D0: sw          $t8, 0x24($s0)
        MEM_W(0X24, ctx->r16) = ctx->r24;
            goto L_800291E0;
    }
    // 0x800291D0: sw          $t8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r24;
    // 0x800291D4: sll         $s3, $t8, 16
    ctx->r19 = S32(ctx->r24 << 16);
    // 0x800291D8: sra         $t6, $s3, 16
    ctx->r14 = S32(SIGNED(ctx->r19) >> 16);
    // 0x800291DC: or          $s3, $t6, $zero
    ctx->r19 = ctx->r14 | 0;
L_800291E0:
    // 0x800291E0: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x800291E4: lw          $t9, 0x14($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14);
    // 0x800291E8: sw          $s3, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r19;
    // 0x800291EC: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x800291F0: jal         0x80023FC0
    // 0x800291F4: addu        $a0, $t7, $t9
    ctx->r4 = ADD32(ctx->r15, ctx->r25);
    memcpy_recomp(rdram, ctx);
        goto after_0;
    // 0x800291F4: addu        $a0, $t7, $t9
    ctx->r4 = ADD32(ctx->r15, ctx->r25);
    after_0:
    // 0x800291F8: lw          $t8, 0x24($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X24);
    // 0x800291FC: subu        $t6, $t8, $s3
    ctx->r14 = SUB32(ctx->r24, ctx->r19);
    // 0x80029200: b           L_8002958C
    // 0x80029204: sw          $t6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r14;
        goto L_8002958C;
    // 0x80029204: sw          $t6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r14;
L_80029208:
    // 0x80029208: beq         $at, $zero, L_80029280
    if (ctx->r1 == 0) {
        // 0x8002920C: or          $a1, $s1, $zero
        ctx->r5 = ctx->r17 | 0;
            goto L_80029280;
    }
    // 0x8002920C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80029210: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x80029214: lw          $t9, 0x14($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14);
    // 0x80029218: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8002921C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80029220: jal         0x80023FC0
    // 0x80029224: addu        $a0, $t7, $t9
    ctx->r4 = ADD32(ctx->r15, ctx->r25);
    memcpy_recomp(rdram, ctx);
        goto after_1;
    // 0x80029224: addu        $a0, $t7, $t9
    ctx->r4 = ADD32(ctx->r15, ctx->r25);
    after_1:
    // 0x80029228: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x8002922C: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x80029230: subu        $t7, $s2, $s3
    ctx->r15 = SUB32(ctx->r18, ctx->r19);
    // 0x80029234: addu        $t6, $t8, $s3
    ctx->r14 = ADD32(ctx->r24, ctx->r19);
    // 0x80029238: sw          $t6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r14;
    // 0x8002923C: bgtz        $v0, L_80029254
    if (SIGNED(ctx->r2) > 0) {
        // 0x80029240: sw          $t7, 0x18($s0)
        MEM_W(0X18, ctx->r16) = ctx->r15;
            goto L_80029254;
    }
    // 0x80029240: sw          $t7, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r15;
    // 0x80029244: lw          $t9, 0x30($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X30);
    // 0x80029248: andi        $t8, $t9, 0x8
    ctx->r24 = ctx->r25 & 0X8;
    // 0x8002924C: beq         $t8, $zero, L_80029278
    if (ctx->r24 == 0) {
        // 0x80029250: nop
    
            goto L_80029278;
    }
    // 0x80029250: nop

L_80029254:
    // 0x80029254: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x80029258: lw          $t9, 0x14($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14);
    // 0x8002925C: addiu       $t6, $zero, 0x2E
    ctx->r14 = ADD32(0, 0X2E);
    // 0x80029260: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x80029264: sb          $t6, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r14;
    // 0x80029268: lw          $t7, 0x1C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1C);
    // 0x8002926C: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x80029270: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x80029274: sw          $t9, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r25;
L_80029278:
    // 0x80029278: b           L_8002958C
    // 0x8002927C: sw          $v0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r2;
        goto L_8002958C;
    // 0x8002927C: sw          $v0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r2;
L_80029280:
    // 0x80029280: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
    // 0x80029284: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x80029288: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8002928C: jal         0x80023FC0
    // 0x80029290: addu        $a0, $t6, $t8
    ctx->r4 = ADD32(ctx->r14, ctx->r24);
    memcpy_recomp(rdram, ctx);
        goto after_2;
    // 0x80029290: addu        $a0, $t6, $t8
    ctx->r4 = ADD32(ctx->r14, ctx->r24);
    after_2:
    // 0x80029294: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x80029298: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x8002929C: subu        $s3, $s3, $s2
    ctx->r19 = SUB32(ctx->r19, ctx->r18);
    // 0x800292A0: sll         $t6, $s3, 16
    ctx->r14 = S32(ctx->r19 << 16);
    // 0x800292A4: addu        $t9, $t7, $s2
    ctx->r25 = ADD32(ctx->r15, ctx->r18);
    // 0x800292A8: sw          $t9, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r25;
    // 0x800292AC: bgtz        $v0, L_800292C4
    if (SIGNED(ctx->r2) > 0) {
        // 0x800292B0: sra         $s3, $t6, 16
        ctx->r19 = S32(SIGNED(ctx->r14) >> 16);
            goto L_800292C4;
    }
    // 0x800292B0: sra         $s3, $t6, 16
    ctx->r19 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800292B4: lw          $t7, 0x30($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X30);
    // 0x800292B8: andi        $t9, $t7, 0x8
    ctx->r25 = ctx->r15 & 0X8;
    // 0x800292BC: beql        $t9, $zero, L_800292EC
    if (ctx->r25 == 0) {
        // 0x800292C0: slt         $at, $v0, $s3
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r19) ? 1 : 0;
            goto L_800292EC;
    }
    goto skip_3;
    // 0x800292C0: slt         $at, $v0, $s3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r19) ? 1 : 0;
    skip_3:
L_800292C4:
    // 0x800292C4: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x800292C8: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x800292CC: addiu       $t6, $zero, 0x2E
    ctx->r14 = ADD32(0, 0X2E);
    // 0x800292D0: addu        $t9, $t8, $t7
    ctx->r25 = ADD32(ctx->r24, ctx->r15);
    // 0x800292D4: sb          $t6, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r14;
    // 0x800292D8: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x800292DC: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x800292E0: addiu       $t7, $t8, 0x1
    ctx->r15 = ADD32(ctx->r24, 0X1);
    // 0x800292E4: sw          $t7, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r15;
    // 0x800292E8: slt         $at, $v0, $s3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r19) ? 1 : 0;
L_800292EC:
    // 0x800292EC: beq         $at, $zero, L_80029300
    if (ctx->r1 == 0) {
        // 0x800292F0: addu        $a1, $s2, $s1
        ctx->r5 = ADD32(ctx->r18, ctx->r17);
            goto L_80029300;
    }
    // 0x800292F0: addu        $a1, $s2, $s1
    ctx->r5 = ADD32(ctx->r18, ctx->r17);
    // 0x800292F4: sll         $s3, $v0, 16
    ctx->r19 = S32(ctx->r2 << 16);
    // 0x800292F8: sra         $t6, $s3, 16
    ctx->r14 = S32(SIGNED(ctx->r19) >> 16);
    // 0x800292FC: or          $s3, $t6, $zero
    ctx->r19 = ctx->r14 | 0;
L_80029300:
    // 0x80029300: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    // 0x80029304: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x80029308: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x8002930C: jal         0x80023FC0
    // 0x80029310: addu        $a0, $t9, $t8
    ctx->r4 = ADD32(ctx->r25, ctx->r24);
    memcpy_recomp(rdram, ctx);
        goto after_3;
    // 0x80029310: addu        $a0, $t9, $t8
    ctx->r4 = ADD32(ctx->r25, ctx->r24);
    after_3:
    // 0x80029314: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x80029318: lw          $t9, 0x24($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X24);
    // 0x8002931C: addu        $t6, $t7, $s3
    ctx->r14 = ADD32(ctx->r15, ctx->r19);
    // 0x80029320: subu        $t8, $t9, $s3
    ctx->r24 = SUB32(ctx->r25, ctx->r19);
    // 0x80029324: sw          $t6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r14;
    // 0x80029328: b           L_8002958C
    // 0x8002932C: sw          $t8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r24;
        goto L_8002958C;
    // 0x8002932C: sw          $t8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r24;
L_80029330:
    // 0x80029330: beq         $a0, $v1, L_80029340
    if (ctx->r4 == ctx->r3) {
        // 0x80029334: addiu       $at, $zero, 0x47
        ctx->r1 = ADD32(0, 0X47);
            goto L_80029340;
    }
    // 0x80029334: addiu       $at, $zero, 0x47
    ctx->r1 = ADD32(0, 0X47);
    // 0x80029338: bnel        $v1, $at, L_80029380
    if (ctx->r3 != ctx->r1) {
        // 0x8002933C: lw          $t8, 0x8($s0)
        ctx->r24 = MEM_W(ctx->r16, 0X8);
            goto L_80029380;
    }
    goto skip_4;
    // 0x8002933C: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    skip_4:
L_80029340:
    // 0x80029340: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x80029344: addiu       $s4, $zero, 0x45
    ctx->r20 = ADD32(0, 0X45);
    // 0x80029348: slt         $at, $s3, $v0
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8002934C: beql        $at, $zero, L_80029360
    if (ctx->r1 == 0) {
        // 0x80029350: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_80029360;
    }
    goto skip_5;
    // 0x80029350: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    skip_5:
    // 0x80029354: sw          $s3, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r19;
    // 0x80029358: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
    // 0x8002935C: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
L_80029360:
    // 0x80029360: bgez        $t7, L_8002936C
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80029364: sw          $t7, 0x24($s0)
        MEM_W(0X24, ctx->r16) = ctx->r15;
            goto L_8002936C;
    }
    // 0x80029364: sw          $t7, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r15;
    // 0x80029368: sw          $zero, 0x24($s0)
    MEM_W(0X24, ctx->r16) = 0;
L_8002936C:
    // 0x8002936C: bne         $a0, $v1, L_8002937C
    if (ctx->r4 != ctx->r3) {
        // 0x80029370: nop
    
            goto L_8002937C;
    }
    // 0x80029370: nop

    // 0x80029374: b           L_8002937C
    // 0x80029378: addiu       $s4, $zero, 0x65
    ctx->r20 = ADD32(0, 0X65);
        goto L_8002937C;
    // 0x80029378: addiu       $s4, $zero, 0x65
    ctx->r20 = ADD32(0, 0X65);
L_8002937C:
    // 0x8002937C: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
L_80029380:
    // 0x80029380: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x80029384: lbu         $t9, 0x0($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X0);
    // 0x80029388: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8002938C: addu        $t6, $t8, $t7
    ctx->r14 = ADD32(ctx->r24, ctx->r15);
    // 0x80029390: sb          $t9, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r25;
    // 0x80029394: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x80029398: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x8002939C: addiu       $t7, $t8, 0x1
    ctx->r15 = ADD32(ctx->r24, 0X1);
    // 0x800293A0: bgtz        $v0, L_800293B8
    if (SIGNED(ctx->r2) > 0) {
        // 0x800293A4: sw          $t7, 0x14($s0)
        MEM_W(0X14, ctx->r16) = ctx->r15;
            goto L_800293B8;
    }
    // 0x800293A4: sw          $t7, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r15;
    // 0x800293A8: lw          $t9, 0x30($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X30);
    // 0x800293AC: andi        $t6, $t9, 0x8
    ctx->r14 = ctx->r25 & 0X8;
    // 0x800293B0: beq         $t6, $zero, L_800293DC
    if (ctx->r14 == 0) {
        // 0x800293B4: nop
    
            goto L_800293DC;
    }
    // 0x800293B4: nop

L_800293B8:
    // 0x800293B8: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x800293BC: lw          $t9, 0x14($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14);
    // 0x800293C0: addiu       $t8, $zero, 0x2E
    ctx->r24 = ADD32(0, 0X2E);
    // 0x800293C4: addu        $t6, $t7, $t9
    ctx->r14 = ADD32(ctx->r15, ctx->r25);
    // 0x800293C8: sb          $t8, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r24;
    // 0x800293CC: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x800293D0: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x800293D4: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x800293D8: sw          $t9, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r25;
L_800293DC:
    // 0x800293DC: blezl       $v0, L_80029438
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800293E0: lw          $t6, 0x8($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X8);
            goto L_80029438;
    }
    goto skip_6;
    // 0x800293E0: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
    skip_6:
    // 0x800293E4: addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
    // 0x800293E8: sll         $t8, $s3, 16
    ctx->r24 = S32(ctx->r19 << 16);
    // 0x800293EC: sra         $s3, $t8, 16
    ctx->r19 = S32(SIGNED(ctx->r24) >> 16);
    // 0x800293F0: slt         $at, $v0, $s3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x800293F4: beq         $at, $zero, L_80029408
    if (ctx->r1 == 0) {
        // 0x800293F8: or          $a1, $s1, $zero
        ctx->r5 = ctx->r17 | 0;
            goto L_80029408;
    }
    // 0x800293F8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800293FC: sll         $s3, $v0, 16
    ctx->r19 = S32(ctx->r2 << 16);
    // 0x80029400: sra         $t7, $s3, 16
    ctx->r15 = S32(SIGNED(ctx->r19) >> 16);
    // 0x80029404: or          $s3, $t7, $zero
    ctx->r19 = ctx->r15 | 0;
L_80029408:
    // 0x80029408: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    // 0x8002940C: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x80029410: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80029414: jal         0x80023FC0
    // 0x80029418: addu        $a0, $t9, $t8
    ctx->r4 = ADD32(ctx->r25, ctx->r24);
    memcpy_recomp(rdram, ctx);
        goto after_4;
    // 0x80029418: addu        $a0, $t9, $t8
    ctx->r4 = ADD32(ctx->r25, ctx->r24);
    after_4:
    // 0x8002941C: lw          $t6, 0x14($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X14);
    // 0x80029420: lw          $t9, 0x24($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X24);
    // 0x80029424: addu        $t7, $t6, $s3
    ctx->r15 = ADD32(ctx->r14, ctx->r19);
    // 0x80029428: subu        $t8, $t9, $s3
    ctx->r24 = SUB32(ctx->r25, ctx->r19);
    // 0x8002942C: sw          $t7, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r15;
    // 0x80029430: sw          $t8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r24;
    // 0x80029434: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
L_80029438:
    // 0x80029438: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x8002943C: addu        $s1, $t6, $t7
    ctx->r17 = ADD32(ctx->r14, ctx->r15);
    // 0x80029440: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80029444: bltz        $s2, L_8002945C
    if (SIGNED(ctx->r18) < 0) {
        // 0x80029448: sb          $s4, -0x1($s1)
        MEM_B(-0X1, ctx->r17) = ctx->r20;
            goto L_8002945C;
    }
    // 0x80029448: sb          $s4, -0x1($s1)
    MEM_B(-0X1, ctx->r17) = ctx->r20;
    // 0x8002944C: addiu       $t9, $zero, 0x2B
    ctx->r25 = ADD32(0, 0X2B);
    // 0x80029450: sb          $t9, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r25;
    // 0x80029454: b           L_80029478
    // 0x80029458: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
        goto L_80029478;
    // 0x80029458: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8002945C:
    // 0x8002945C: negu        $s2, $s2
    ctx->r18 = SUB32(0, ctx->r18);
    // 0x80029460: sll         $t6, $s2, 16
    ctx->r14 = S32(ctx->r18 << 16);
    // 0x80029464: addiu       $t8, $zero, 0x2D
    ctx->r24 = ADD32(0, 0X2D);
    // 0x80029468: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8002946C: sb          $t8, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r24;
    // 0x80029470: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80029474: or          $s2, $t7, $zero
    ctx->r18 = ctx->r15 | 0;
L_80029478:
    // 0x80029478: slti        $at, $s2, 0x64
    ctx->r1 = SIGNED(ctx->r18) < 0X64 ? 1 : 0;
    // 0x8002947C: bnel        $at, $zero, L_80029528
    if (ctx->r1 != 0) {
        // 0x80029480: addiu       $v0, $zero, 0xA
        ctx->r2 = ADD32(0, 0XA);
            goto L_80029528;
    }
    goto skip_7;
    // 0x80029480: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    skip_7:
    // 0x80029484: slti        $at, $s2, 0x3E8
    ctx->r1 = SIGNED(ctx->r18) < 0X3E8 ? 1 : 0;
    // 0x80029488: bne         $at, $zero, L_800294D8
    if (ctx->r1 != 0) {
        // 0x8002948C: addiu       $v0, $zero, 0x3E8
        ctx->r2 = ADD32(0, 0X3E8);
            goto L_800294D8;
    }
    // 0x8002948C: addiu       $v0, $zero, 0x3E8
    ctx->r2 = ADD32(0, 0X3E8);
    // 0x80029490: div         $zero, $s2, $v0
    lo = S32(S64(S32(ctx->r18)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r18)) % S64(S32(ctx->r2)));
    // 0x80029494: bne         $v0, $zero, L_800294A0
    if (ctx->r2 != 0) {
        // 0x80029498: nop
    
            goto L_800294A0;
    }
    // 0x80029498: nop

    // 0x8002949C: break       7
    do_break(2147652764);
L_800294A0:
    // 0x800294A0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800294A4: bne         $v0, $at, L_800294B8
    if (ctx->r2 != ctx->r1) {
        // 0x800294A8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800294B8;
    }
    // 0x800294A8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800294AC: bne         $s2, $at, L_800294B8
    if (ctx->r18 != ctx->r1) {
        // 0x800294B0: nop
    
            goto L_800294B8;
    }
    // 0x800294B0: nop

    // 0x800294B4: break       6
    do_break(2147652788);
L_800294B8:
    // 0x800294B8: mfhi        $s2
    ctx->r18 = hi;
    // 0x800294BC: sll         $t6, $s2, 16
    ctx->r14 = S32(ctx->r18 << 16);
    // 0x800294C0: mflo        $t9
    ctx->r25 = lo;
    // 0x800294C4: addiu       $t8, $t9, 0x30
    ctx->r24 = ADD32(ctx->r25, 0X30);
    // 0x800294C8: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800294CC: or          $s2, $t7, $zero
    ctx->r18 = ctx->r15 | 0;
    // 0x800294D0: sb          $t8, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r24;
    // 0x800294D4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_800294D8:
    // 0x800294D8: addiu       $v0, $zero, 0x64
    ctx->r2 = ADD32(0, 0X64);
    // 0x800294DC: div         $zero, $s2, $v0
    lo = S32(S64(S32(ctx->r18)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r18)) % S64(S32(ctx->r2)));
    // 0x800294E0: bne         $v0, $zero, L_800294EC
    if (ctx->r2 != 0) {
        // 0x800294E4: nop
    
            goto L_800294EC;
    }
    // 0x800294E4: nop

    // 0x800294E8: break       7
    do_break(2147652840);
L_800294EC:
    // 0x800294EC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800294F0: bne         $v0, $at, L_80029504
    if (ctx->r2 != ctx->r1) {
        // 0x800294F4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80029504;
    }
    // 0x800294F4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800294F8: bne         $s2, $at, L_80029504
    if (ctx->r18 != ctx->r1) {
        // 0x800294FC: nop
    
            goto L_80029504;
    }
    // 0x800294FC: nop

    // 0x80029500: break       6
    do_break(2147652864);
L_80029504:
    // 0x80029504: mfhi        $s2
    ctx->r18 = hi;
    // 0x80029508: sll         $t6, $s2, 16
    ctx->r14 = S32(ctx->r18 << 16);
    // 0x8002950C: mflo        $t9
    ctx->r25 = lo;
    // 0x80029510: addiu       $t8, $t9, 0x30
    ctx->r24 = ADD32(ctx->r25, 0X30);
    // 0x80029514: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80029518: or          $s2, $t7, $zero
    ctx->r18 = ctx->r15 | 0;
    // 0x8002951C: sb          $t8, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r24;
    // 0x80029520: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80029524: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_80029528:
    // 0x80029528: div         $zero, $s2, $v0
    lo = S32(S64(S32(ctx->r18)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r18)) % S64(S32(ctx->r2)));
    // 0x8002952C: bne         $v0, $zero, L_80029538
    if (ctx->r2 != 0) {
        // 0x80029530: nop
    
            goto L_80029538;
    }
    // 0x80029530: nop

    // 0x80029534: break       7
    do_break(2147652916);
L_80029538:
    // 0x80029538: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8002953C: bne         $v0, $at, L_80029550
    if (ctx->r2 != ctx->r1) {
        // 0x80029540: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80029550;
    }
    // 0x80029540: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80029544: bne         $s2, $at, L_80029550
    if (ctx->r18 != ctx->r1) {
        // 0x80029548: nop
    
            goto L_80029550;
    }
    // 0x80029548: nop

    // 0x8002954C: break       6
    do_break(2147652940);
L_80029550:
    // 0x80029550: mfhi        $s2
    ctx->r18 = hi;
    // 0x80029554: sll         $t6, $s2, 16
    ctx->r14 = S32(ctx->r18 << 16);
    // 0x80029558: mflo        $t9
    ctx->r25 = lo;
    // 0x8002955C: addiu       $t8, $t9, 0x30
    ctx->r24 = ADD32(ctx->r25, 0X30);
    // 0x80029560: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80029564: addiu       $t9, $t7, 0x30
    ctx->r25 = ADD32(ctx->r15, 0X30);
    // 0x80029568: sb          $t8, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r24;
    // 0x8002956C: sb          $t9, 0x1($s1)
    MEM_B(0X1, ctx->r17) = ctx->r25;
    // 0x80029570: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x80029574: or          $s2, $t7, $zero
    ctx->r18 = ctx->r15 | 0;
    // 0x80029578: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x8002957C: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x80029580: subu        $t6, $s1, $t8
    ctx->r14 = SUB32(ctx->r17, ctx->r24);
    // 0x80029584: subu        $t9, $t6, $t7
    ctx->r25 = SUB32(ctx->r14, ctx->r15);
    // 0x80029588: sw          $t9, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r25;
L_8002958C:
    // 0x8002958C: lw          $t8, 0x30($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X30);
    // 0x80029590: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x80029594: andi        $t6, $t8, 0x14
    ctx->r14 = ctx->r24 & 0X14;
    // 0x80029598: bnel        $t6, $at, L_800295DC
    if (ctx->r14 != ctx->r1) {
        // 0x8002959C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800295DC;
    }
    goto skip_8;
    // 0x8002959C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_8:
    // 0x800295A0: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x800295A4: lw          $t9, 0x14($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14);
    // 0x800295A8: lw          $t6, 0x18($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X18);
    // 0x800295AC: lw          $v1, 0x28($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X28);
    // 0x800295B0: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x800295B4: lw          $t9, 0x1C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1C);
    // 0x800295B8: addu        $t7, $t8, $t6
    ctx->r15 = ADD32(ctx->r24, ctx->r14);
    // 0x800295BC: lw          $t6, 0x20($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X20);
    // 0x800295C0: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x800295C4: addu        $v0, $t8, $t6
    ctx->r2 = ADD32(ctx->r24, ctx->r14);
    // 0x800295C8: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800295CC: beq         $at, $zero, L_800295D8
    if (ctx->r1 == 0) {
        // 0x800295D0: subu        $t7, $v1, $v0
        ctx->r15 = SUB32(ctx->r3, ctx->r2);
            goto L_800295D8;
    }
    // 0x800295D0: subu        $t7, $v1, $v0
    ctx->r15 = SUB32(ctx->r3, ctx->r2);
    // 0x800295D4: sw          $t7, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r15;
L_800295D8:
    // 0x800295D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800295DC:
    // 0x800295DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800295E0: jr          $ra
    // 0x800295E4: nop

    return;
    // 0x800295E4: nop

    // 0x800295E8: jr          $ra
    // 0x800295EC: nop

    return;
    // 0x800295EC: nop

;}
