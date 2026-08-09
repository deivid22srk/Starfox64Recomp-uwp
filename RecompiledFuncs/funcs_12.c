#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void Message_DisplayScrollingText(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C2D3C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800C2D40: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x800C2D44: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800C2D48: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800C2D4C: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x800C2D50: or          $s6, $a1, $zero
    ctx->r22 = ctx->r5 | 0;
    // 0x800C2D54: or          $fp, $a2, $zero
    ctx->r30 = ctx->r6 | 0;
    // 0x800C2D58: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800C2D5C: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x800C2D60: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800C2D64: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800C2D68: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800C2D6C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800C2D70: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C2D74: or          $s0, $fp, $zero
    ctx->r16 = ctx->r30 | 0;
    // 0x800C2D78: or          $s1, $a3, $zero
    ctx->r17 = ctx->r7 | 0;
    // 0x800C2D7C: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800C2D80: lui         $t7, 0xBA00
    ctx->r15 = S32(0XBA00 << 16);
    // 0x800C2D84: ori         $t7, $t7, 0xE02
    ctx->r15 = ctx->r15 | 0XE02;
    // 0x800C2D88: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800C2D8C: sw          $t6, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r14;
    // 0x800C2D90: ori         $t8, $zero, 0x8000
    ctx->r24 = 0 | 0X8000;
    // 0x800C2D94: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800C2D98: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800C2D9C: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800C2DA0: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800C2DA4: addiu       $t4, $t4, -0x45E0
    ctx->r12 = ADD32(ctx->r12, -0X45E0);
    // 0x800C2DA8: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800C2DAC: sw          $t9, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r25;
    // 0x800C2DB0: lui         $t3, 0xFD10
    ctx->r11 = S32(0XFD10 << 16);
    // 0x800C2DB4: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x800C2DB8: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x800C2DBC: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800C2DC0: lui         $t6, 0xE800
    ctx->r14 = S32(0XE800 << 16);
    // 0x800C2DC4: lui         $t8, 0xF500
    ctx->r24 = S32(0XF500 << 16);
    // 0x800C2DC8: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x800C2DCC: sw          $t5, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r13;
    // 0x800C2DD0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800C2DD4: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800C2DD8: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800C2DDC: ori         $t8, $t8, 0x100
    ctx->r24 = ctx->r24 | 0X100;
    // 0x800C2DE0: lui         $t9, 0x700
    ctx->r25 = S32(0X700 << 16);
    // 0x800C2DE4: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800C2DE8: sw          $t7, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r15;
    // 0x800C2DEC: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800C2DF0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800C2DF4: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800C2DF8: lui         $t4, 0xE600
    ctx->r12 = S32(0XE600 << 16);
    // 0x800C2DFC: lui         $t6, 0xF000
    ctx->r14 = S32(0XF000 << 16);
    // 0x800C2E00: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x800C2E04: sw          $t3, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r11;
    // 0x800C2E08: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800C2E0C: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x800C2E10: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800C2E14: lui         $t7, 0x70F
    ctx->r15 = S32(0X70F << 16);
    // 0x800C2E18: ori         $t7, $t7, 0xC000
    ctx->r15 = ctx->r15 | 0XC000;
    // 0x800C2E1C: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x800C2E20: sw          $t5, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r13;
    // 0x800C2E24: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800C2E28: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800C2E2C: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800C2E30: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x800C2E34: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800C2E38: sw          $t8, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r24;
    // 0x800C2E3C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800C2E40: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800C2E44: lhu         $t3, 0x0($s6)
    ctx->r11 = MEM_HU(ctx->r22, 0X0);
    // 0x800C2E48: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800C2E4C: lw          $s5, 0x58($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X58);
    // 0x800C2E50: beql        $t3, $zero, L_800C2F04
    if (ctx->r11 == 0) {
        // 0x800C2E54: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_800C2F04;
    }
    goto skip_0;
    // 0x800C2E54: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_0:
    // 0x800C2E58: blez        $s5, L_800C2F00
    if (SIGNED(ctx->r21) <= 0) {
        // 0x800C2E5C: sll         $t4, $zero, 1
        ctx->r12 = S32(0 << 1);
            goto L_800C2F00;
    }
    // 0x800C2E5C: sll         $t4, $zero, 1
    ctx->r12 = S32(0 << 1);
    // 0x800C2E60: addu        $s2, $s6, $t4
    ctx->r18 = ADD32(ctx->r22, ctx->r12);
    // 0x800C2E64: lhu         $a1, 0x0($s2)
    ctx->r5 = MEM_HU(ctx->r18, 0X0);
    // 0x800C2E68: lw          $s6, 0x54($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X54);
    // 0x800C2E6C: lw          $s7, 0x50($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X50);
    // 0x800C2E70: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x800C2E74: addiu       $t5, $v0, -0x1
    ctx->r13 = ADD32(ctx->r2, -0X1);
L_800C2E78:
    // 0x800C2E78: sltiu       $at, $t5, 0xF
    ctx->r1 = ctx->r13 < 0XF ? 1 : 0;
    // 0x800C2E7C: beq         $at, $zero, L_800C2EBC
    if (ctx->r1 == 0) {
        // 0x800C2E80: sll         $t5, $t5, 2
        ctx->r13 = S32(ctx->r13 << 2);
            goto L_800C2EBC;
    }
    // 0x800C2E80: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800C2E84: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C2E88: addu        $at, $at, $t5
    gpr jr_addend_800C2E90 = ctx->r13;
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x800C2E8C: lw          $t5, -0x6C54($at)
    ctx->r13 = ADD32(ctx->r1, -0X6C54);
    // 0x800C2E90: jr          $t5
    // 0x800C2E94: nop

    switch (jr_addend_800C2E90 >> 2) {
        case 0: goto L_800C2E98; break;
        case 1: goto L_800C2EE0; break;
        case 2: goto L_800C2EE0; break;
        case 3: goto L_800C2EE0; break;
        case 4: goto L_800C2EE0; break;
        case 5: goto L_800C2EE0; break;
        case 6: goto L_800C2EE0; break;
        case 7: goto L_800C2EE0; break;
        case 8: goto L_800C2EE0; break;
        case 9: goto L_800C2EE0; break;
        case 10: goto L_800C2EE0; break;
        case 11: goto L_800C2EB4; break;
        case 12: goto L_800C2EA4; break;
        case 13: goto L_800C2EAC; break;
        case 14: goto L_800C2EE0; break;
        default: switch_error(__func__, 0x800C2E90, 0x800D93AC);
    }
    // 0x800C2E94: nop

L_800C2E98:
    // 0x800C2E98: or          $s0, $fp, $zero
    ctx->r16 = ctx->r30 | 0;
    // 0x800C2E9C: b           L_800C2EE0
    // 0x800C2EA0: addiu       $s1, $s1, 0xF
    ctx->r17 = ADD32(ctx->r17, 0XF);
        goto L_800C2EE0;
    // 0x800C2EA0: addiu       $s1, $s1, 0xF
    ctx->r17 = ADD32(ctx->r17, 0XF);
L_800C2EA4:
    // 0x800C2EA4: b           L_800C2EE0
    // 0x800C2EA8: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
        goto L_800C2EE0;
    // 0x800C2EA8: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
L_800C2EAC:
    // 0x800C2EAC: b           L_800C2EE0
    // 0x800C2EB0: addiu       $s0, $s0, 0x3
    ctx->r16 = ADD32(ctx->r16, 0X3);
        goto L_800C2EE0;
    // 0x800C2EB0: addiu       $s0, $s0, 0x3
    ctx->r16 = ADD32(ctx->r16, 0X3);
L_800C2EB4:
    // 0x800C2EB4: b           L_800C2EE0
    // 0x800C2EB8: addiu       $s0, $s0, 0x7
    ctx->r16 = ADD32(ctx->r16, 0X7);
        goto L_800C2EE0;
    // 0x800C2EB8: addiu       $s0, $s0, 0x7
    ctx->r16 = ADD32(ctx->r16, 0X7);
L_800C2EBC:
    // 0x800C2EBC: slt         $at, $s6, $s1
    ctx->r1 = SIGNED(ctx->r22) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x800C2EC0: beq         $at, $zero, L_800C2EDC
    if (ctx->r1 == 0) {
        // 0x800C2EC4: slt         $at, $s1, $s7
        ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r23) ? 1 : 0;
            goto L_800C2EDC;
    }
    // 0x800C2EC4: slt         $at, $s1, $s7
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r23) ? 1 : 0;
    // 0x800C2EC8: beq         $at, $zero, L_800C2EDC
    if (ctx->r1 == 0) {
        // 0x800C2ECC: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_800C2EDC;
    }
    // 0x800C2ECC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800C2ED0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x800C2ED4: jal         0x800C295C
    // 0x800C2ED8: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    Message_DisplayChar(rdram, ctx);
        goto after_0;
    // 0x800C2ED8: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_0:
L_800C2EDC:
    // 0x800C2EDC: addiu       $s0, $s0, 0x7
    ctx->r16 = ADD32(ctx->r16, 0X7);
L_800C2EE0:
    // 0x800C2EE0: lhu         $a1, 0x2($s2)
    ctx->r5 = MEM_HU(ctx->r18, 0X2);
    // 0x800C2EE4: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800C2EE8: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // 0x800C2EEC: beq         $a1, $zero, L_800C2F00
    if (ctx->r5 == 0) {
        // 0x800C2EF0: or          $v0, $a1, $zero
        ctx->r2 = ctx->r5 | 0;
            goto L_800C2F00;
    }
    // 0x800C2EF0: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x800C2EF4: slt         $at, $s3, $s5
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r21) ? 1 : 0;
    // 0x800C2EF8: bnel        $at, $zero, L_800C2E78
    if (ctx->r1 != 0) {
        // 0x800C2EFC: addiu       $t5, $v0, -0x1
        ctx->r13 = ADD32(ctx->r2, -0X1);
            goto L_800C2E78;
    }
    goto skip_1;
    // 0x800C2EFC: addiu       $t5, $v0, -0x1
    ctx->r13 = ADD32(ctx->r2, -0X1);
    skip_1:
L_800C2F00:
    // 0x800C2F00: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_800C2F04:
    // 0x800C2F04: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C2F08: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800C2F0C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800C2F10: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800C2F14: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800C2F18: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800C2F1C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800C2F20: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x800C2F24: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x800C2F28: jr          $ra
    // 0x800C2F2C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800C2F2C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void Audio_GetInstrumentTunedSample(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011D10: lbu         $t6, 0x1($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X1);
    // 0x80011D14: slt         $at, $a1, $t6
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80011D18: beql        $at, $zero, L_80011D2C
    if (ctx->r1 == 0) {
        // 0x80011D1C: lbu         $t7, 0x2($a0)
        ctx->r15 = MEM_BU(ctx->r4, 0X2);
            goto L_80011D2C;
    }
    goto skip_0;
    // 0x80011D1C: lbu         $t7, 0x2($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X2);
    skip_0:
    // 0x80011D20: jr          $ra
    // 0x80011D24: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    return;
    // 0x80011D24: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // 0x80011D28: lbu         $t7, 0x2($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X2);
L_80011D2C:
    // 0x80011D2C: addiu       $v1, $a0, 0x18
    ctx->r3 = ADD32(ctx->r4, 0X18);
    // 0x80011D30: slt         $at, $t7, $a1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80011D34: bne         $at, $zero, L_80011D44
    if (ctx->r1 != 0) {
        // 0x80011D38: nop
    
            goto L_80011D44;
    }
    // 0x80011D38: nop

    // 0x80011D3C: jr          $ra
    // 0x80011D40: addiu       $v0, $a0, 0x10
    ctx->r2 = ADD32(ctx->r4, 0X10);
    return;
    // 0x80011D40: addiu       $v0, $a0, 0x10
    ctx->r2 = ADD32(ctx->r4, 0X10);
L_80011D44:
    // 0x80011D44: jr          $ra
    // 0x80011D48: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80011D48: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void ItemGoldRing_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005CA80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005CA84: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8005CA88: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8005CA8C: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8005CA90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005CA94: jal         0x800B8DD0
    // 0x8005CA98: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x8005CA98: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    after_0:
    // 0x8005CA9C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8005CAA0: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8005CAA4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8005CAA8: lui         $t7, 0xBB00
    ctx->r15 = S32(0XBB00 << 16);
    // 0x8005CAAC: lui         $t8, 0x76C
    ctx->r24 = S32(0X76C << 16);
    // 0x8005CAB0: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8005CAB4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8005CAB8: ori         $t8, $t8, 0x6A4
    ctx->r24 = ctx->r24 | 0X6A4;
    // 0x8005CABC: ori         $t7, $t7, 0x1
    ctx->r15 = ctx->r15 | 0X1;
    // 0x8005CAC0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8005CAC4: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8005CAC8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8005CACC: lui         $t0, 0xB700
    ctx->r8 = S32(0XB700 << 16);
    // 0x8005CAD0: lui         $t1, 0xC
    ctx->r9 = S32(0XC << 16);
    // 0x8005CAD4: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8005CAD8: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8005CADC: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x8005CAE0: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x8005CAE4: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x8005CAE8: jal         0x8005980C
    // 0x8005CAEC: lwc1        $f12, 0x68($t2)
    ctx->f12.u32l = MEM_W(ctx->r10, 0X68);
    Graphics_SetScaleMtx(rdram, ctx);
        goto after_1;
    // 0x8005CAEC: lwc1        $f12, 0x68($t2)
    ctx->f12.u32l = MEM_W(ctx->r10, 0X68);
    after_1:
    // 0x8005CAF0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8005CAF4: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8005CAF8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8005CAFC: lui         $t5, 0x101
    ctx->r13 = S32(0X101 << 16);
    // 0x8005CB00: addiu       $t5, $t5, 0x6870
    ctx->r13 = ADD32(ctx->r13, 0X6870);
    // 0x8005CB04: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x8005CB08: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x8005CB0C: lui         $t4, 0x600
    ctx->r12 = S32(0X600 << 16);
    // 0x8005CB10: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8005CB14: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x8005CB18: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8005CB1C: lui         $t7, 0xB600
    ctx->r15 = S32(0XB600 << 16);
    // 0x8005CB20: lui         $t8, 0xC
    ctx->r24 = S32(0XC << 16);
    // 0x8005CB24: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8005CB28: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8005CB2C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8005CB30: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8005CB34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005CB38: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005CB3C: jr          $ra
    // 0x8005CB40: nop

    return;
    // 0x8005CB40: nop

;}
RECOMP_FUNC void Versus_dummy_800C1758(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C1754: jr          $ra
    // 0x800C1758: nop

    return;
    // 0x800C1758: nop

;}
RECOMP_FUNC void ActorAllRange_StarWolfDefeatMesg(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002F64C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002F650: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8002F654: addiu       $v0, $v0, 0x7CD0
    ctx->r2 = ADD32(ctx->r2, 0X7CD0);
    // 0x8002F658: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002F65C: lw          $t6, 0xC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XC);
    // 0x8002F660: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x8002F664: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x8002F668: lw          $t1, 0x8($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X8);
    // 0x8002F66C: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8002F670: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8002F674: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x8002F678: bne         $t2, $zero, L_8002F684
    if (ctx->r10 != 0) {
        // 0x8002F67C: lui         $at, 0x8018
        ctx->r1 = S32(0X8018 << 16);
            goto L_8002F684;
    }
    // 0x8002F67C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002F680: sw          $zero, -0x7D64($at)
    MEM_W(-0X7D64, ctx->r1) = 0;
L_8002F684:
    // 0x8002F684: jal         0x8002F5F4
    // 0x8002F688: nop

    ActorAllRange_PlayMessage(rdram, ctx);
        goto after_0;
    // 0x8002F688: nop

    after_0:
    // 0x8002F68C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002F690: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002F694: jr          $ra
    // 0x8002F698: nop

    return;
    // 0x8002F698: nop

;}
RECOMP_FUNC void Audio_LoadAquasSequence(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80017550: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x80017554: lbu         $t6, 0x5D54($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X5D54);
    // 0x80017558: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001755C: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80017560: bne         $t6, $at, L_80017578
    if (ctx->r14 != ctx->r1) {
        // 0x80017564: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80017578;
    }
    // 0x80017564: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80017568: lui         $a0, 0x8100
    ctx->r4 = S32(0X8100 << 16);
    // 0x8001756C: ori         $a0, $a0, 0xE00
    ctx->r4 = ctx->r4 | 0XE00;
    // 0x80017570: jal         0x8001E8CC
    // 0x80017574: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    AudioThread_QueueCmdS32(rdram, ctx);
        goto after_0;
    // 0x80017574: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
L_80017578:
    // 0x80017578: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001757C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80017580: jr          $ra
    // 0x80017584: nop

    return;
    // 0x80017584: nop

;}
RECOMP_FUNC void Main_SetVIMode(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80003EE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80003EE4: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80003EE8: addiu       $v1, $v1, -0x2780
    ctx->r3 = ADD32(ctx->r3, -0X2780);
    // 0x80003EEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80003EF0: lhu         $t6, 0x0($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X0);
    // 0x80003EF4: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x80003EF8: andi        $t7, $t6, 0x400
    ctx->r15 = ctx->r14 & 0X400;
    // 0x80003EFC: beq         $t7, $zero, L_80003F58
    if (ctx->r15 == 0) {
        // 0x80003F00: nop
    
            goto L_80003F58;
    }
    // 0x80003F00: nop

    // 0x80003F04: lhu         $t8, 0x6($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X6);
    // 0x80003F08: andi        $t9, $t8, 0x400
    ctx->r25 = ctx->r24 & 0X400;
    // 0x80003F0C: beq         $t9, $zero, L_80003F58
    if (ctx->r25 == 0) {
        // 0x80003F10: nop
    
            goto L_80003F58;
    }
    // 0x80003F10: nop

    // 0x80003F14: lhu         $t0, 0xC($v1)
    ctx->r8 = MEM_HU(ctx->r3, 0XC);
    // 0x80003F18: andi        $t1, $t0, 0x400
    ctx->r9 = ctx->r8 & 0X400;
    // 0x80003F1C: beq         $t1, $zero, L_80003F58
    if (ctx->r9 == 0) {
        // 0x80003F20: nop
    
            goto L_80003F58;
    }
    // 0x80003F20: nop

    // 0x80003F24: lhu         $v0, 0x12($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X12);
    // 0x80003F28: andi        $t2, $v0, 0x20
    ctx->r10 = ctx->r2 & 0X20;
    // 0x80003F2C: beq         $t2, $zero, L_80003F58
    if (ctx->r10 == 0) {
        // 0x80003F30: andi        $t3, $v0, 0x10
        ctx->r11 = ctx->r2 & 0X10;
            goto L_80003F58;
    }
    // 0x80003F30: andi        $t3, $v0, 0x10
    ctx->r11 = ctx->r2 & 0X10;
    // 0x80003F34: beq         $t3, $zero, L_80003F58
    if (ctx->r11 == 0) {
        // 0x80003F38: andi        $t4, $v0, 0x2000
        ctx->r12 = ctx->r2 & 0X2000;
            goto L_80003F58;
    }
    // 0x80003F38: andi        $t4, $v0, 0x2000
    ctx->r12 = ctx->r2 & 0X2000;
    // 0x80003F3C: beq         $t4, $zero, L_80003F58
    if (ctx->r12 == 0) {
        // 0x80003F40: lui         $t5, 0x800C
        ctx->r13 = S32(0X800C << 16);
            goto L_80003F58;
    }
    // 0x80003F40: lui         $t5, 0x800C
    ctx->r13 = S32(0X800C << 16);
    // 0x80003F44: lw          $t5, 0x45D0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X45D0);
    // 0x80003F48: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80003F4C: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80003F50: subu        $t7, $t6, $t5
    ctx->r15 = SUB32(ctx->r14, ctx->r13);
    // 0x80003F54: sw          $t7, 0x45D0($at)
    MEM_W(0X45D0, ctx->r1) = ctx->r15;
L_80003F58:
    // 0x80003F58: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x80003F5C: lw          $v0, 0x300($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X300);
    // 0x80003F60: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80003F64: beq         $v0, $zero, L_80003F88
    if (ctx->r2 == 0) {
        // 0x80003F68: nop
    
            goto L_80003F88;
    }
    // 0x80003F68: nop

    // 0x80003F6C: beq         $v0, $at, L_80003FAC
    if (ctx->r2 == ctx->r1) {
        // 0x80003F70: lui         $a0, 0x800C
        ctx->r4 = S32(0X800C << 16);
            goto L_80003FAC;
    }
    // 0x80003F70: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x80003F74: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80003F78: beq         $v0, $at, L_80003F98
    if (ctx->r2 == ctx->r1) {
        // 0x80003F7C: nop
    
            goto L_80003F98;
    }
    // 0x80003F7C: nop

    // 0x80003F80: b           L_80003FAC
    // 0x80003F84: nop

        goto L_80003FAC;
    // 0x80003F84: nop

L_80003F88:
    // 0x80003F88: jal         0x80021AC0
    // 0x80003F8C: addiu       $a0, $a0, 0x7D20
    ctx->r4 = ADD32(ctx->r4, 0X7D20);
    osViSetMode_recomp(rdram, ctx);
        goto after_0;
    // 0x80003F8C: addiu       $a0, $a0, 0x7D20
    ctx->r4 = ADD32(ctx->r4, 0X7D20);
    after_0:
    // 0x80003F90: b           L_80003FB4
    // 0x80003F94: nop

        goto L_80003FB4;
    // 0x80003F94: nop

L_80003F98:
    // 0x80003F98: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x80003F9C: jal         0x80021AC0
    // 0x80003FA0: addiu       $a0, $a0, 0x7D70
    ctx->r4 = ADD32(ctx->r4, 0X7D70);
    osViSetMode_recomp(rdram, ctx);
        goto after_1;
    // 0x80003FA0: addiu       $a0, $a0, 0x7D70
    ctx->r4 = ADD32(ctx->r4, 0X7D70);
    after_1:
    // 0x80003FA4: b           L_80003FB4
    // 0x80003FA8: nop

        goto L_80003FB4;
    // 0x80003FA8: nop

L_80003FAC:
    // 0x80003FAC: jal         0x80021AC0
    // 0x80003FB0: addiu       $a0, $a0, 0x7CD0
    ctx->r4 = ADD32(ctx->r4, 0X7CD0);
    osViSetMode_recomp(rdram, ctx);
        goto after_2;
    // 0x80003FB0: addiu       $a0, $a0, 0x7CD0
    ctx->r4 = ADD32(ctx->r4, 0X7CD0);
    after_2:
L_80003FB4:
    // 0x80003FB4: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x80003FB8: lw          $t8, 0x45D0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X45D0);
    // 0x80003FBC: beq         $t8, $zero, L_80003FD4
    if (ctx->r24 == 0) {
        // 0x80003FC0: nop
    
            goto L_80003FD4;
    }
    // 0x80003FC0: nop

    // 0x80003FC4: jal         0x80021B30
    // 0x80003FC8: addiu       $a0, $zero, 0x65
    ctx->r4 = ADD32(0, 0X65);
    osViSetSpecialFeatures_recomp(rdram, ctx);
        goto after_3;
    // 0x80003FC8: addiu       $a0, $zero, 0x65
    ctx->r4 = ADD32(0, 0X65);
    after_3:
    // 0x80003FCC: b           L_80003FE0
    // 0x80003FD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80003FE0;
    // 0x80003FD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80003FD4:
    // 0x80003FD4: jal         0x80021B30
    // 0x80003FD8: addiu       $a0, $zero, 0x6A
    ctx->r4 = ADD32(0, 0X6A);
    osViSetSpecialFeatures_recomp(rdram, ctx);
        goto after_4;
    // 0x80003FD8: addiu       $a0, $zero, 0x6A
    ctx->r4 = ADD32(0, 0X6A);
    after_4:
    // 0x80003FDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80003FE0:
    // 0x80003FE0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80003FE4: jr          $ra
    // 0x80003FE8: nop

    return;
    // 0x80003FE8: nop

;}
RECOMP_FUNC void AudioSeq_SetInstrument(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80015330: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80015334: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x80015338: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8001533C: slti        $at, $t6, 0x80
    ctx->r1 = SIGNED(ctx->r14) < 0X80 ? 1 : 0;
    // 0x80015340: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x80015344: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80015348: bne         $at, $zero, L_8001535C
    if (ctx->r1 != 0) {
        // 0x8001534C: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_8001535C;
    }
    // 0x8001534C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80015350: sh          $t6, 0x1C($a0)
    MEM_H(0X1C, ctx->r4) = ctx->r14;
    // 0x80015354: b           L_800153A8
    // 0x80015358: sw          $zero, 0x40($a0)
    MEM_W(0X40, ctx->r4) = 0;
        goto L_800153A8;
    // 0x80015358: sw          $zero, 0x40($a0)
    MEM_W(0X40, ctx->r4) = 0;
L_8001535C:
    // 0x8001535C: addiu       $at, $zero, 0x7F
    ctx->r1 = ADD32(0, 0X7F);
    // 0x80015360: bne         $v0, $at, L_80015378
    if (ctx->r2 != ctx->r1) {
        // 0x80015364: addiu       $a2, $a0, 0x40
        ctx->r6 = ADD32(ctx->r4, 0X40);
            goto L_80015378;
    }
    // 0x80015364: addiu       $a2, $a0, 0x40
    ctx->r6 = ADD32(ctx->r4, 0X40);
    // 0x80015368: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8001536C: sh          $zero, 0x1C($a0)
    MEM_H(0X1C, ctx->r4) = 0;
    // 0x80015370: b           L_800153A8
    // 0x80015374: sw          $t7, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->r15;
        goto L_800153A8;
    // 0x80015374: sw          $t7, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->r15;
L_80015378:
    // 0x80015378: addiu       $a3, $a0, 0x74
    ctx->r7 = ADD32(ctx->r4, 0X74);
    // 0x8001537C: jal         0x800152C0
    // 0x80015380: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    AudioSeq_GetInstrument(rdram, ctx);
        goto after_0;
    // 0x80015380: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80015384: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80015388: sll         $t8, $v0, 16
    ctx->r24 = S32(ctx->r2 << 16);
    // 0x8001538C: sra         $t9, $t8, 16
    ctx->r25 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80015390: bne         $t9, $zero, L_800153A8
    if (ctx->r25 != 0) {
        // 0x80015394: sh          $v0, 0x1C($a0)
        MEM_H(0X1C, ctx->r4) = ctx->r2;
            goto L_800153A8;
    }
    // 0x80015394: sh          $v0, 0x1C($a0)
    MEM_H(0X1C, ctx->r4) = ctx->r2;
    // 0x80015398: lbu         $t0, 0x0($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X0);
    // 0x8001539C: andi        $t1, $t0, 0xFFF7
    ctx->r9 = ctx->r8 & 0XFFF7;
    // 0x800153A0: b           L_800153B4
    // 0x800153A4: sb          $t1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r9;
        goto L_800153B4;
    // 0x800153A4: sb          $t1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r9;
L_800153A8:
    // 0x800153A8: lbu         $t3, 0x0($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0X0);
    // 0x800153AC: ori         $t4, $t3, 0x8
    ctx->r12 = ctx->r11 | 0X8;
    // 0x800153B0: sb          $t4, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r12;
L_800153B4:
    // 0x800153B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800153B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800153BC: jr          $ra
    // 0x800153C0: nop

    return;
    // 0x800153C0: nop

;}
RECOMP_FUNC void Lib_InitPerspective(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000316C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80003170: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80003174: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80003178: addiu       $v1, $v1, 0x7E5C
    ctx->r3 = ADD32(ctx->r3, 0X7E5C);
    // 0x8000317C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80003180: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80003184: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80003188: lwc1        $f4, 0x1A40($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X1A40);
    // 0x8000318C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80003190: lwc1        $f6, 0x1A44($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X1A44);
    // 0x80003194: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80003198: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8000319C: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800031A0: lui         $a3, 0x3FAA
    ctx->r7 = S32(0X3FAA << 16);
    // 0x800031A4: ori         $a3, $a3, 0xAAAB
    ctx->r7 = ctx->r7 | 0XAAAB;
    // 0x800031A8: lw          $a2, 0x1A3C($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X1A3C);
    // 0x800031AC: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x800031B0: addiu       $a1, $sp, 0x46
    ctx->r5 = ADD32(ctx->r29, 0X46);
    // 0x800031B4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x800031B8: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x800031BC: jal         0x80021170
    // 0x800031C0: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    guPerspective(rdram, ctx);
        goto after_0;
    // 0x800031C0: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x800031C4: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800031C8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800031CC: addiu       $v1, $v1, 0x7E5C
    ctx->r3 = ADD32(ctx->r3, 0X7E5C);
    // 0x800031D0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800031D4: lui         $t7, 0xBC00
    ctx->r15 = S32(0XBC00 << 16);
    // 0x800031D8: ori         $t7, $t7, 0xE
    ctx->r15 = ctx->r15 | 0XE;
    // 0x800031DC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800031E0: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800031E4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800031E8: lhu         $t8, 0x46($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X46);
    // 0x800031EC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800031F0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800031F4: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800031F8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800031FC: lui         $t2, 0x103
    ctx->r10 = S32(0X103 << 16);
    // 0x80003200: ori         $t2, $t2, 0x40
    ctx->r10 = ctx->r10 | 0X40;
    // 0x80003204: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80003208: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x8000320C: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x80003210: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x80003214: lui         $at, 0xC648
    ctx->r1 = S32(0XC648 << 16);
    // 0x80003218: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8000321C: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x80003220: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x80003224: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80003228: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000322C: addiu       $t5, $t4, 0x40
    ctx->r13 = ADD32(ctx->r12, 0X40);
    // 0x80003230: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x80003234: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80003238: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x8000323C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x80003240: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80003244: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x80003248: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x8000324C: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x80003250: jal         0x80021488
    // 0x80003254: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    guLookAt(rdram, ctx);
        goto after_1;
    // 0x80003254: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    after_1:
    // 0x80003258: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8000325C: addiu       $v1, $v1, 0x7E5C
    ctx->r3 = ADD32(ctx->r3, 0X7E5C);
    // 0x80003260: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80003264: lui         $t7, 0x101
    ctx->r15 = S32(0X101 << 16);
    // 0x80003268: ori         $t7, $t7, 0x40
    ctx->r15 = ctx->r15 | 0X40;
    // 0x8000326C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80003270: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80003274: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80003278: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8000327C: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x80003280: addiu       $a1, $a1, 0x4660
    ctx->r5 = ADD32(ctx->r5, 0X4660);
    // 0x80003284: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80003288: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8000328C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80003290: addiu       $t2, $t9, 0x40
    ctx->r10 = ADD32(ctx->r25, 0X40);
    // 0x80003294: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x80003298: jal         0x80005680
    // 0x8000329C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Copy(rdram, ctx);
        goto after_2;
    // 0x8000329C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_2:
    // 0x800032A0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800032A4: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x800032A8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x800032AC: jr          $ra
    // 0x800032B0: nop

    return;
    // 0x800032B0: nop

;}
RECOMP_FUNC void HUD_RadarMark_Supplies_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089C38: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80089C3C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80089C40: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80089C44: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x80089C48: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80089C4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80089C50: jal         0x800B8DD0
    // 0x80089C54: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x80089C54: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_0:
    // 0x80089C58: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80089C5C: lw          $v0, 0x7DB0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7DB0);
    // 0x80089C60: addiu       $at, $zero, 0x15
    ctx->r1 = ADD32(0, 0X15);
    // 0x80089C64: lui         $t1, 0xFA00
    ctx->r9 = S32(0XFA00 << 16);
    // 0x80089C68: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x80089C6C: mfhi        $t6
    ctx->r14 = hi;
    // 0x80089C70: slti        $at, $t6, 0xB
    ctx->r1 = SIGNED(ctx->r14) < 0XB ? 1 : 0;
    // 0x80089C74: bne         $at, $zero, L_80089C84
    if (ctx->r1 != 0) {
        // 0x80089C78: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_80089C84;
    }
    // 0x80089C78: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80089C7C: addiu       $t7, $zero, 0x14
    ctx->r15 = ADD32(0, 0X14);
    // 0x80089C80: subu        $v0, $t7, $t6
    ctx->r2 = SUB32(ctx->r15, ctx->r14);
L_80089C84:
    // 0x80089C84: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80089C88: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x80089C8C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80089C90: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80089C94: lui         $at, 0x41CC
    ctx->r1 = S32(0X41CC << 16);
    // 0x80089C98: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80089C9C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80089CA0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80089CA4: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x80089CA8: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80089CAC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80089CB0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80089CB4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80089CB8: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80089CBC: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    // 0x80089CC0: nop

    // 0x80089CC4: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80089CC8: andi        $t2, $v0, 0xFF
    ctx->r10 = ctx->r2 & 0XFF;
    // 0x80089CCC: or          $t3, $t2, $at
    ctx->r11 = ctx->r10 | ctx->r1;
    // 0x80089CD0: addiu       $t9, $t0, 0x8
    ctx->r25 = ADD32(ctx->r8, 0X8);
    // 0x80089CD4: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80089CD8: sw          $t3, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r11;
    // 0x80089CDC: sw          $t1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r9;
    // 0x80089CE0: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80089CE4: jal         0x80005C34
    // 0x80089CE8: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    Matrix_Scale(rdram, ctx);
        goto after_1;
    // 0x80089CE8: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_1:
    // 0x80089CEC: jal         0x80006EB8
    // 0x80089CF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_2;
    // 0x80089CF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80089CF4: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80089CF8: lui         $t7, 0x102
    ctx->r15 = S32(0X102 << 16);
    // 0x80089CFC: addiu       $t7, $t7, 0x4230
    ctx->r15 = ADD32(ctx->r15, 0X4230);
    // 0x80089D00: addiu       $t5, $t0, 0x8
    ctx->r13 = ADD32(ctx->r8, 0X8);
    // 0x80089D04: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x80089D08: lui         $t6, 0x600
    ctx->r14 = S32(0X600 << 16);
    // 0x80089D0C: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x80089D10: sw          $t7, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r15;
    // 0x80089D14: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80089D18: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80089D1C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80089D20: jr          $ra
    // 0x80089D24: nop

    return;
    // 0x80089D24: nop

;}
RECOMP_FUNC void Effect_TimedSfx_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007A748: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007A74C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007A750: lhu         $t6, 0x50($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X50);
    // 0x8007A754: bnel        $t6, $zero, L_8007A768
    if (ctx->r14 != 0) {
        // 0x8007A758: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8007A768;
    }
    goto skip_0;
    // 0x8007A758: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8007A75C: jal         0x80060FBC
    // 0x8007A760: addiu       $a1, $a0, 0x80
    ctx->r5 = ADD32(ctx->r4, 0X80);
    Object_Kill(rdram, ctx);
        goto after_0;
    // 0x8007A760: addiu       $a1, $a0, 0x80
    ctx->r5 = ADD32(ctx->r4, 0X80);
    after_0:
    // 0x8007A764: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8007A768:
    // 0x8007A768: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007A76C: jr          $ra
    // 0x8007A770: nop

    return;
    // 0x8007A770: nop

;}
RECOMP_FUNC void Audio_SetVolume(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D8A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001D8AC: andi        $t7, $a1, 0xFF
    ctx->r15 = ctx->r5 & 0XFF;
    // 0x8001D8B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8001D8B4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8001D8B8: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x8001D8BC: slti        $at, $t7, 0x64
    ctx->r1 = SIGNED(ctx->r15) < 0X64 ? 1 : 0;
    // 0x8001D8C0: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x8001D8C4: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x8001D8C8: bne         $at, $zero, L_8001D8D4
    if (ctx->r1 != 0) {
        // 0x8001D8CC: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8001D8D4;
    }
    // 0x8001D8CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001D8D0: addiu       $a1, $zero, 0x63
    ctx->r5 = ADD32(0, 0X63);
L_8001D8D4:
    // 0x8001D8D4: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8001D8D8: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x8001D8DC: jal         0x8001D780
    // 0x8001D8E0: sb          $a1, 0x5D68($at)
    MEM_B(0X5D68, ctx->r1) = ctx->r5;
    Audio_RestoreVolumeSettings(rdram, ctx);
        goto after_0;
    // 0x8001D8E0: sb          $a1, 0x5D68($at)
    MEM_B(0X5D68, ctx->r1) = ctx->r5;
    after_0:
    // 0x8001D8E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001D8E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001D8EC: jr          $ra
    // 0x8001D8F0: nop

    return;
    // 0x8001D8F0: nop

;}
RECOMP_FUNC void Scenery_CoStoneArch_Init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063E5C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80063E60: lui         $a3, 0x8017
    ctx->r7 = S32(0X8017 << 16);
    // 0x80063E64: addiu       $a3, $a3, 0x37E0
    ctx->r7 = ADD32(ctx->r7, 0X37E0);
    // 0x80063E68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063E6C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80063E70: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80063E74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80063E78: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x80063E7C: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
L_80063E80:
    // 0x80063E80: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
    // 0x80063E84: bne         $t6, $zero, L_80063F30
    if (ctx->r14 != 0) {
        // 0x80063E88: sll         $t7, $v0, 3
        ctx->r15 = S32(ctx->r2 << 3);
            goto L_80063F30;
    }
    // 0x80063E88: sll         $t7, $v0, 3
    ctx->r15 = S32(ctx->r2 << 3);
    // 0x80063E8C: subu        $t7, $t7, $v0
    ctx->r15 = SUB32(ctx->r15, ctx->r2);
    // 0x80063E90: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80063E94: subu        $t7, $t7, $v0
    ctx->r15 = SUB32(ctx->r15, ctx->r2);
    // 0x80063E98: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80063E9C: addu        $a0, $a3, $t7
    ctx->r4 = ADD32(ctx->r7, ctx->r15);
    // 0x80063EA0: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x80063EA4: jal         0x80061444
    // 0x80063EA8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    Item_Initialize(rdram, ctx);
        goto after_0;
    // 0x80063EA8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x80063EAC: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80063EB0: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80063EB4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80063EB8: addiu       $t9, $zero, 0x14E
    ctx->r25 = ADD32(0, 0X14E);
    // 0x80063EBC: sb          $t8, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r24;
    // 0x80063EC0: sh          $t9, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r25;
    // 0x80063EC4: lwc1        $f4, 0x4($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X4);
    // 0x80063EC8: andi        $a1, $t9, 0xFFFF
    ctx->r5 = ctx->r25 & 0XFFFF;
    // 0x80063ECC: addiu       $a0, $v1, 0x1C
    ctx->r4 = ADD32(ctx->r3, 0X1C);
    // 0x80063ED0: swc1        $f4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f4.u32l;
    // 0x80063ED4: lwc1        $f6, 0x8($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X8);
    // 0x80063ED8: swc1        $f6, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f6.u32l;
    // 0x80063EDC: lwc1        $f8, 0xC($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0XC);
    // 0x80063EE0: swc1        $f8, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f8.u32l;
    // 0x80063EE4: lwc1        $f10, 0x14($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X14);
    // 0x80063EE8: jal         0x800612B8
    // 0x80063EEC: swc1        $f10, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->f10.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_1;
    // 0x80063EEC: swc1        $f10, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->f10.u32l;
    after_1:
    // 0x80063EF0: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80063EF4: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x80063EF8: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x80063EFC: sll         $t0, $v0, 4
    ctx->r8 = S32(ctx->r2 << 4);
    // 0x80063F00: srl         $t1, $t0, 28
    ctx->r9 = S32(U32(ctx->r8) >> 28);
    // 0x80063F04: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80063F08: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80063F0C: lw          $t3, 0x1FD0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X1FD0);
    // 0x80063F10: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80063F14: and         $t4, $v0, $at
    ctx->r12 = ctx->r2 & ctx->r1;
    // 0x80063F18: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80063F1C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80063F20: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x80063F24: addu        $t6, $t5, $at
    ctx->r14 = ADD32(ctx->r13, ctx->r1);
    // 0x80063F28: b           L_80063F3C
    // 0x80063F2C: sw          $t6, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r14;
        goto L_80063F3C;
    // 0x80063F2C: sw          $t6, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r14;
L_80063F30:
    // 0x80063F30: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80063F34: bne         $v0, $a0, L_80063E80
    if (ctx->r2 != ctx->r4) {
        // 0x80063F38: addiu       $v1, $v1, 0x6C
        ctx->r3 = ADD32(ctx->r3, 0X6C);
            goto L_80063E80;
    }
    // 0x80063F38: addiu       $v1, $v1, 0x6C
    ctx->r3 = ADD32(ctx->r3, 0X6C);
L_80063F3C:
    // 0x80063F3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063F40: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80063F44: jr          $ra
    // 0x80063F48: nop

    return;
    // 0x80063F48: nop

;}
RECOMP_FUNC void ActorSupplies_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006753C: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80067540: sw          $s3, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r19;
    // 0x80067544: lui         $s3, 0x8018
    ctx->r19 = S32(0X8018 << 16);
    // 0x80067548: sw          $s2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r18;
    // 0x8006754C: sw          $s1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r17;
    // 0x80067550: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x80067554: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80067558: addiu       $s3, $s3, -0x7D80
    ctx->r19 = ADD32(ctx->r19, -0X7D80);
    // 0x8006755C: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x80067560: sw          $s0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r16;
    // 0x80067564: sdc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X48, ctx->r29);
    // 0x80067568: sdc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X40, ctx->r29);
    // 0x8006756C: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x80067570: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x80067574: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x80067578: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8006757C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80067580: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80067584: lwc1        $f4, 0x14($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X14);
    // 0x80067588: lw          $s0, 0x0($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X0);
    // 0x8006758C: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x80067590: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80067594: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80067598: swc1        $f8, 0x14($s2)
    MEM_W(0X14, ctx->r18) = ctx->f8.u32l;
    // 0x8006759C: lw          $t6, 0x7880($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7880);
    // 0x800675A0: bnel        $s1, $t6, L_80067640
    if (ctx->r17 != ctx->r14) {
        // 0x800675A4: lb          $t8, 0xD0($s2)
        ctx->r24 = MEM_B(ctx->r18, 0XD0);
            goto L_80067640;
    }
    goto skip_0;
    // 0x800675A4: lb          $t8, 0xD0($s2)
    ctx->r24 = MEM_B(ctx->r18, 0XD0);
    skip_0:
    // 0x800675A8: lw          $t7, -0x7DCC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7DCC);
    // 0x800675AC: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    // 0x800675B0: addiu       $a0, $s2, 0x8
    ctx->r4 = ADD32(ctx->r18, 0X8);
    // 0x800675B4: bne         $t7, $at, L_8006761C
    if (ctx->r15 != ctx->r1) {
        // 0x800675B8: lui         $a1, 0x4396
        ctx->r5 = S32(0X4396 << 16);
            goto L_8006761C;
    }
    // 0x800675B8: lui         $a1, 0x4396
    ctx->r5 = S32(0X4396 << 16);
    // 0x800675BC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800675C0: lwc1        $f20, 0x696C($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X696C);
    // 0x800675C4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800675C8: lwc1        $f22, 0x6970($at)
    ctx->f22.u32l = MEM_W(ctx->r1, 0X6970);
    // 0x800675CC: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800675D0: addiu       $a0, $s2, 0x4
    ctx->r4 = ADD32(ctx->r18, 0X4);
    // 0x800675D4: lui         $a1, 0xC4FA
    ctx->r5 = S32(0XC4FA << 16);
    // 0x800675D8: lui         $a3, 0x4270
    ctx->r7 = S32(0X4270 << 16);
    // 0x800675DC: jal         0x8009BC2C
    // 0x800675E0: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_0;
    // 0x800675E0: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    after_0:
    // 0x800675E4: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800675E8: addiu       $a0, $s2, 0x8
    ctx->r4 = ADD32(ctx->r18, 0X8);
    // 0x800675EC: lui         $a1, 0xC348
    ctx->r5 = S32(0XC348 << 16);
    // 0x800675F0: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    // 0x800675F4: jal         0x8009BC2C
    // 0x800675F8: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_1;
    // 0x800675F8: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    after_1:
    // 0x800675FC: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80067600: addiu       $a0, $s2, 0xC
    ctx->r4 = ADD32(ctx->r18, 0XC);
    // 0x80067604: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80067608: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x8006760C: jal         0x8009BC2C
    // 0x80067610: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_2;
    // 0x80067610: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    after_2:
    // 0x80067614: b           L_80067640
    // 0x80067618: lb          $t8, 0xD0($s2)
    ctx->r24 = MEM_B(ctx->r18, 0XD0);
        goto L_80067640;
    // 0x80067618: lb          $t8, 0xD0($s2)
    ctx->r24 = MEM_B(ctx->r18, 0XD0);
L_8006761C:
    // 0x8006761C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80067620: lwc1        $f20, 0x6974($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X6974);
    // 0x80067624: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80067628: lwc1        $f22, 0x6978($at)
    ctx->f22.u32l = MEM_W(ctx->r1, 0X6978);
    // 0x8006762C: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80067630: lui         $a3, 0x4248
    ctx->r7 = S32(0X4248 << 16);
    // 0x80067634: jal         0x8009BC2C
    // 0x80067638: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_3;
    // 0x80067638: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    after_3:
    // 0x8006763C: lb          $t8, 0xD0($s2)
    ctx->r24 = MEM_B(ctx->r18, 0XD0);
L_80067640:
    // 0x80067640: beq         $t8, $zero, L_80067808
    if (ctx->r24 == 0) {
        // 0x80067644: nop
    
            goto L_80067808;
    }
    // 0x80067644: nop

    // 0x80067648: lh          $t9, 0xCE($s2)
    ctx->r25 = MEM_H(ctx->r18, 0XCE);
    // 0x8006764C: lhu         $t0, 0xD6($s2)
    ctx->r8 = MEM_HU(ctx->r18, 0XD6);
    // 0x80067650: sb          $zero, 0xD0($s2)
    MEM_B(0XD0, ctx->r18) = 0;
    // 0x80067654: addiu       $a0, $s2, 0x4
    ctx->r4 = ADD32(ctx->r18, 0X4);
    // 0x80067658: subu        $t1, $t9, $t0
    ctx->r9 = SUB32(ctx->r25, ctx->r8);
    // 0x8006765C: sh          $t1, 0xCE($s2)
    MEM_H(0XCE, ctx->r18) = ctx->r9;
    // 0x80067660: lh          $t2, 0xCE($s2)
    ctx->r10 = MEM_H(ctx->r18, 0XCE);
    // 0x80067664: lui         $a1, 0x2903
    ctx->r5 = S32(0X2903 << 16);
    // 0x80067668: bgtz        $t2, L_80067808
    if (SIGNED(ctx->r10) > 0) {
        // 0x8006766C: nop
    
            goto L_80067808;
    }
    // 0x8006766C: nop

    // 0x80067670: jal         0x8007A6F0
    // 0x80067674: ori         $a1, $a1, 0xA008
    ctx->r5 = ctx->r5 | 0XA008;
    Effect_TimedSfx_Spawn(rdram, ctx);
        goto after_4;
    // 0x80067674: ori         $a1, $a1, 0xA008
    ctx->r5 = ctx->r5 | 0XA008;
    after_4:
    // 0x80067678: lwc1        $f12, 0x4($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X4);
    // 0x8006767C: lwc1        $f14, 0x8($s2)
    ctx->f14.u32l = MEM_W(ctx->r18, 0X8);
    // 0x80067680: lw          $a2, 0xC($s2)
    ctx->r6 = MEM_W(ctx->r18, 0XC);
    // 0x80067684: jal         0x8007D2C8
    // 0x80067688: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    Effect_FireSmoke1_Spawn3(rdram, ctx);
        goto after_5;
    // 0x80067688: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    after_5:
    // 0x8006768C: lbu         $t3, 0x49C($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X49C);
    // 0x80067690: slti        $at, $t3, 0x2
    ctx->r1 = SIGNED(ctx->r11) < 0X2 ? 1 : 0;
    // 0x80067694: bnel        $at, $zero, L_800676B0
    if (ctx->r1 != 0) {
        // 0x80067698: lw          $t5, 0x1CC($s0)
        ctx->r13 = MEM_W(ctx->r16, 0X1CC);
            goto L_800676B0;
    }
    goto skip_1;
    // 0x80067698: lw          $t5, 0x1CC($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X1CC);
    skip_1:
    // 0x8006769C: lbu         $t4, 0x49D($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X49D);
    // 0x800676A0: slti        $at, $t4, 0x2
    ctx->r1 = SIGNED(ctx->r12) < 0X2 ? 1 : 0;
    // 0x800676A4: beql        $at, $zero, L_800676C8
    if (ctx->r1 == 0) {
        // 0x800676A8: lw          $t7, 0x0($s3)
        ctx->r15 = MEM_W(ctx->r19, 0X0);
            goto L_800676C8;
    }
    goto skip_2;
    // 0x800676A8: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    skip_2:
    // 0x800676AC: lw          $t5, 0x1CC($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X1CC);
L_800676B0:
    // 0x800676B0: addiu       $t6, $zero, 0x17
    ctx->r14 = ADD32(0, 0X17);
    // 0x800676B4: beql        $s1, $t5, L_800676C8
    if (ctx->r17 == ctx->r13) {
        // 0x800676B8: lw          $t7, 0x0($s3)
        ctx->r15 = MEM_W(ctx->r19, 0X0);
            goto L_800676C8;
    }
    goto skip_3;
    // 0x800676B8: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    skip_3:
    // 0x800676BC: b           L_80067714
    // 0x800676C0: sb          $t6, 0x44($s2)
    MEM_B(0X44, ctx->r18) = ctx->r14;
        goto L_80067714;
    // 0x800676C0: sb          $t6, 0x44($s2)
    MEM_B(0X44, ctx->r18) = ctx->r14;
    // 0x800676C4: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
L_800676C8:
    // 0x800676C8: addiu       $t9, $zero, 0x19
    ctx->r25 = ADD32(0, 0X19);
    // 0x800676CC: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x800676D0: lw          $t8, 0x264($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X264);
    // 0x800676D4: slti        $at, $t8, 0x80
    ctx->r1 = SIGNED(ctx->r24) < 0X80 ? 1 : 0;
    // 0x800676D8: beq         $at, $zero, L_800676E8
    if (ctx->r1 == 0) {
        // 0x800676DC: nop
    
            goto L_800676E8;
    }
    // 0x800676DC: nop

    // 0x800676E0: b           L_80067714
    // 0x800676E4: sb          $t9, 0x44($s2)
    MEM_B(0X44, ctx->r18) = ctx->r25;
        goto L_80067714;
    // 0x800676E4: sb          $t9, 0x44($s2)
    MEM_B(0X44, ctx->r18) = ctx->r25;
L_800676E8:
    // 0x800676E8: lw          $t0, 0x1AA8($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X1AA8);
    // 0x800676EC: addiu       $t3, $zero, 0x5
    ctx->r11 = ADD32(0, 0X5);
    // 0x800676F0: bnel        $t0, $zero, L_80067714
    if (ctx->r8 != 0) {
        // 0x800676F4: sb          $t3, 0x44($s2)
        MEM_B(0X44, ctx->r18) = ctx->r11;
            goto L_80067714;
    }
    goto skip_4;
    // 0x800676F4: sb          $t3, 0x44($s2)
    MEM_B(0X44, ctx->r18) = ctx->r11;
    skip_4:
    // 0x800676F8: lw          $t1, 0x1CC($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X1CC);
    // 0x800676FC: addiu       $t2, $zero, 0x9
    ctx->r10 = ADD32(0, 0X9);
    // 0x80067700: beql        $s1, $t1, L_80067714
    if (ctx->r17 == ctx->r9) {
        // 0x80067704: sb          $t3, 0x44($s2)
        MEM_B(0X44, ctx->r18) = ctx->r11;
            goto L_80067714;
    }
    goto skip_5;
    // 0x80067704: sb          $t3, 0x44($s2)
    MEM_B(0X44, ctx->r18) = ctx->r11;
    skip_5:
    // 0x80067708: b           L_80067714
    // 0x8006770C: sb          $t2, 0x44($s2)
    MEM_B(0X44, ctx->r18) = ctx->r10;
        goto L_80067714;
    // 0x8006770C: sb          $t2, 0x44($s2)
    MEM_B(0X44, ctx->r18) = ctx->r10;
    // 0x80067710: sb          $t3, 0x44($s2)
    MEM_B(0X44, ctx->r18) = ctx->r11;
L_80067714:
    // 0x80067714: jal         0x80066254
    // 0x80067718: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Actor_Despawn(rdram, ctx);
        goto after_6;
    // 0x80067718: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_6:
    // 0x8006771C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80067720: lwc1        $f30, 0x697C($at)
    ctx->f30.u32l = MEM_W(ctx->r1, 0X697C);
    // 0x80067724: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80067728: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x8006772C: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80067730: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80067734: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80067738: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x8006773C: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    // 0x80067740: lui         $s3, 0x800D
    ctx->r19 = S32(0X800D << 16);
    // 0x80067744: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80067748: addiu       $s3, $s3, -0xAC
    ctx->r19 = ADD32(ctx->r19, -0XAC);
    // 0x8006774C: addiu       $s1, $s1, -0xF4
    ctx->r17 = ADD32(ctx->r17, -0XF4);
    // 0x80067750: addiu       $s0, $s0, -0x13C
    ctx->r16 = ADD32(ctx->r16, -0X13C);
L_80067754:
    // 0x80067754: jal         0x80004EB0
    // 0x80067758: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_7;
    // 0x80067758: nop

    after_7:
    // 0x8006775C: jal         0x80004EB0
    // 0x80067760: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_8;
    // 0x80067760: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_8:
    // 0x80067764: jal         0x80004EB0
    // 0x80067768: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_9;
    // 0x80067768: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    after_9:
    // 0x8006776C: lwc1        $f10, 0x0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80067770: lwc1        $f16, 0x4($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X4);
    // 0x80067774: lwc1        $f18, 0x4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80067778: lwc1        $f4, 0x8($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X8);
    // 0x8006777C: add.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80067780: lwc1        $f16, 0x4($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80067784: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80067788: add.s       $f14, $f18, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8006778C: lwc1        $f18, 0x14($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X14);
    // 0x80067790: lwc1        $f8, 0xC($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0XC);
    // 0x80067794: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80067798: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8006779C: lwc1        $f8, 0x10($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X10);
    // 0x800677A0: lwc1        $f6, 0x0($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X0);
    // 0x800677A4: sub.s       $f16, $f20, $f24
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f16.fl = ctx->f20.fl - ctx->f24.fl;
    // 0x800677A8: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x800677AC: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x800677B0: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800677B4: mul.s       $f18, $f16, $f26
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f26.fl);
    // 0x800677B8: sub.s       $f8, $f0, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f24.fl;
    // 0x800677BC: mul.s       $f4, $f22, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f28.fl);
    // 0x800677C0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x800677C4: mul.s       $f10, $f8, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f26.fl);
    // 0x800677C8: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x800677CC: add.s       $f6, $f4, $f28
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f28.fl;
    // 0x800677D0: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x800677D4: jal         0x800674B4
    // 0x800677D8: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    Actor_SpawnDebris70(rdram, ctx);
        goto after_10;
    // 0x800677D8: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    after_10:
    // 0x800677DC: mfc1        $a3, $f30
    ctx->r7 = (int32_t)ctx->f30.u32l;
    // 0x800677E0: lwc1        $f12, 0x4($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X4);
    // 0x800677E4: lwc1        $f14, 0x8($s2)
    ctx->f14.u32l = MEM_W(ctx->r18, 0X8);
    // 0x800677E8: jal         0x800794CC
    // 0x800677EC: lw          $a2, 0xC($s2)
    ctx->r6 = MEM_W(ctx->r18, 0XC);
    Effect_Effect357_Spawn50(rdram, ctx);
        goto after_11;
    // 0x800677EC: lw          $a2, 0xC($s2)
    ctx->r6 = MEM_W(ctx->r18, 0XC);
    after_11:
    // 0x800677F0: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    // 0x800677F4: bne         $s1, $s3, L_80067754
    if (ctx->r17 != ctx->r19) {
        // 0x800677F8: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_80067754;
    }
    // 0x800677F8: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x800677FC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80067800: jal         0x80060FBC
    // 0x80067804: addiu       $a1, $s2, 0x100
    ctx->r5 = ADD32(ctx->r18, 0X100);
    Object_Kill(rdram, ctx);
        goto after_12;
    // 0x80067804: addiu       $a1, $s2, 0x100
    ctx->r5 = ADD32(ctx->r18, 0X100);
    after_12:
L_80067808:
    // 0x80067808: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8006780C: addiu       $v0, $v0, 0x5A10
    ctx->r2 = ADD32(ctx->r2, 0X5A10);
    // 0x80067810: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80067814: addiu       $t5, $zero, 0x67
    ctx->r13 = ADD32(0, 0X67);
    // 0x80067818: sb          $t4, 0x9D8($v0)
    MEM_B(0X9D8, ctx->r2) = ctx->r12;
    // 0x8006781C: sh          $t5, 0x9DA($v0)
    MEM_H(0X9DA, ctx->r2) = ctx->r13;
    // 0x80067820: lwc1        $f16, 0x4($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X4);
    // 0x80067824: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80067828: swc1        $f16, 0x9DC($v0)
    MEM_W(0X9DC, ctx->r2) = ctx->f16.u32l;
    // 0x8006782C: lwc1        $f18, 0x8($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X8);
    // 0x80067830: swc1        $f18, 0x9E0($v0)
    MEM_W(0X9E0, ctx->r2) = ctx->f18.u32l;
    // 0x80067834: lwc1        $f4, 0xC($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0XC);
    // 0x80067838: swc1        $f6, 0x9E8($v0)
    MEM_W(0X9E8, ctx->r2) = ctx->f6.u32l;
    // 0x8006783C: swc1        $f4, 0x9E4($v0)
    MEM_W(0X9E4, ctx->r2) = ctx->f4.u32l;
    // 0x80067840: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x80067844: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80067848: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x8006784C: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x80067850: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x80067854: ldc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X40);
    // 0x80067858: ldc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X48);
    // 0x8006785C: lw          $s0, 0x54($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X54);
    // 0x80067860: lw          $s1, 0x58($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X58);
    // 0x80067864: lw          $s2, 0x5C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X5C);
    // 0x80067868: lw          $s3, 0x60($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X60);
    // 0x8006786C: jr          $ra
    // 0x80067870: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80067870: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void _Printf(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800246D0: addiu       $sp, $sp, -0xD8
    ctx->r29 = ADD32(ctx->r29, -0XD8);
    // 0x800246D4: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x800246D8: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800246DC: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800246E0: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x800246E4: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800246E8: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800246EC: sw          $a3, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r7;
    // 0x800246F0: lui         $s5, 0x800C
    ctx->r21 = S32(0X800C << 16);
    // 0x800246F4: lui         $s6, 0x800D
    ctx->r22 = S32(0X800D << 16);
    // 0x800246F8: lui         $s7, 0x800C
    ctx->r23 = S32(0X800C << 16);
    // 0x800246FC: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x80024700: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x80024704: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80024708: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8002470C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80024710: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80024714: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80024718: sw          $a2, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r6;
    // 0x8002471C: sw          $zero, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = 0;
    // 0x80024720: addiu       $s7, $s7, 0x7E30
    ctx->r23 = ADD32(ctx->r23, 0X7E30);
    // 0x80024724: addiu       $s6, $s6, -0x6C1C
    ctx->r22 = ADD32(ctx->r22, -0X6C1C);
    // 0x80024728: addiu       $s5, $s5, 0x7E54
    ctx->r21 = ADD32(ctx->r21, 0X7E54);
    // 0x8002472C: addiu       $fp, $zero, 0xA
    ctx->r30 = ADD32(0, 0XA);
L_80024730:
    // 0x80024730: lbu         $v0, 0x0($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X0);
    // 0x80024734: or          $s2, $a3, $zero
    ctx->r18 = ctx->r7 | 0;
    // 0x80024738: addiu       $v1, $zero, 0x25
    ctx->r3 = ADD32(0, 0X25);
    // 0x8002473C: beq         $v0, $zero, L_80024764
    if (ctx->r2 == 0) {
        // 0x80024740: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80024764;
    }
    // 0x80024740: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80024744: beql        $v1, $v0, L_80024768
    if (ctx->r3 == ctx->r2) {
        // 0x80024748: subu        $v0, $s2, $a3
        ctx->r2 = SUB32(ctx->r18, ctx->r7);
            goto L_80024768;
    }
    goto skip_0;
    // 0x80024748: subu        $v0, $s2, $a3
    ctx->r2 = SUB32(ctx->r18, ctx->r7);
    skip_0:
    // 0x8002474C: lbu         $v0, 0x1($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X1);
L_80024750:
    // 0x80024750: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80024754: beq         $v0, $zero, L_80024764
    if (ctx->r2 == 0) {
        // 0x80024758: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80024764;
    }
    // 0x80024758: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8002475C: bnel        $v1, $v0, L_80024750
    if (ctx->r3 != ctx->r2) {
        // 0x80024760: lbu         $v0, 0x1($s2)
        ctx->r2 = MEM_BU(ctx->r18, 0X1);
            goto L_80024750;
    }
    goto skip_1;
    // 0x80024760: lbu         $v0, 0x1($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X1);
    skip_1:
L_80024764:
    // 0x80024764: subu        $v0, $s2, $a3
    ctx->r2 = SUB32(ctx->r18, ctx->r7);
L_80024768:
    // 0x80024768: blez        $v0, L_800247A0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8002476C: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_800247A0;
    }
    // 0x8002476C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80024770: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80024774: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80024778: jalr        $s4
    // 0x8002477C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_0;
    // 0x8002477C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_0:
    // 0x80024780: beq         $v0, $zero, L_80024798
    if (ctx->r2 == 0) {
        // 0x80024784: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_80024798;
    }
    // 0x80024784: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80024788: lw          $t6, 0xCC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XCC);
    // 0x8002478C: addu        $t7, $t6, $s1
    ctx->r15 = ADD32(ctx->r14, ctx->r17);
    // 0x80024790: b           L_800247A0
    // 0x80024794: sw          $t7, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r15;
        goto L_800247A0;
    // 0x80024794: sw          $t7, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r15;
L_80024798:
    // 0x80024798: b           L_80024CE8
    // 0x8002479C: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
        goto L_80024CE8;
    // 0x8002479C: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
L_800247A0:
    // 0x800247A0: bne         $s0, $zero, L_800247B0
    if (ctx->r16 != 0) {
        // 0x800247A4: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_800247B0;
    }
    // 0x800247A4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800247A8: b           L_80024CE8
    // 0x800247AC: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
        goto L_80024CE8;
    // 0x800247AC: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
L_800247B0:
    // 0x800247B0: sw          $zero, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = 0;
    // 0x800247B4: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
    // 0x800247B8: jal         0x80024014
    // 0x800247BC: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    strchr_recomp(rdram, ctx);
        goto after_1;
    // 0x800247BC: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_1:
    // 0x800247C0: beq         $v0, $zero, L_80024800
    if (ctx->r2 == 0) {
        // 0x800247C4: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80024800;
    }
    // 0x800247C4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_800247C8:
    // 0x800247C8: subu        $t9, $s0, $s6
    ctx->r25 = SUB32(ctx->r16, ctx->r22);
    // 0x800247CC: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x800247D0: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x800247D4: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800247D8: lw          $t7, -0x6C14($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X6C14);
    // 0x800247DC: lw          $t8, 0xD0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XD0);
    // 0x800247E0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800247E4: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x800247E8: or          $t9, $t8, $t7
    ctx->r25 = ctx->r24 | ctx->r15;
    // 0x800247EC: sw          $t9, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r25;
    // 0x800247F0: jal         0x80024014
    // 0x800247F4: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
    strchr_recomp(rdram, ctx);
        goto after_2;
    // 0x800247F4: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
    after_2:
    // 0x800247F8: bne         $v0, $zero, L_800247C8
    if (ctx->r2 != 0) {
        // 0x800247FC: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800247C8;
    }
    // 0x800247FC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80024800:
    // 0x80024800: lbu         $t6, 0x0($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X0);
    // 0x80024804: addiu       $v0, $zero, 0x2A
    ctx->r2 = ADD32(0, 0X2A);
    // 0x80024808: lw          $t8, 0xE4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XE4);
    // 0x8002480C: bne         $v0, $t6, L_80024854
    if (ctx->r2 != ctx->r14) {
        // 0x80024810: lui         $a0, 0x800D
        ctx->r4 = S32(0X800D << 16);
            goto L_80024854;
    }
    // 0x80024810: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80024814: addiu       $t7, $t8, 0x3
    ctx->r15 = ADD32(ctx->r24, 0X3);
    // 0x80024818: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8002481C: and         $t9, $t7, $at
    ctx->r25 = ctx->r15 & ctx->r1;
    // 0x80024820: addiu       $t6, $t9, 0x4
    ctx->r14 = ADD32(ctx->r25, 0X4);
    // 0x80024824: sw          $t6, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r14;
    // 0x80024828: lw          $t8, 0x0($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X0);
    // 0x8002482C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80024830: bgez        $t8, L_8002484C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80024834: sw          $t8, 0xC8($sp)
        MEM_W(0XC8, ctx->r29) = ctx->r24;
            goto L_8002484C;
    }
    // 0x80024834: sw          $t8, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r24;
    // 0x80024838: lw          $t6, 0xD0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XD0);
    // 0x8002483C: negu        $t7, $t8
    ctx->r15 = SUB32(0, ctx->r24);
    // 0x80024840: sw          $t7, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r15;
    // 0x80024844: ori         $t9, $t6, 0x4
    ctx->r25 = ctx->r14 | 0X4;
    // 0x80024848: sw          $t9, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r25;
L_8002484C:
    // 0x8002484C: b           L_800248B0
    // 0x80024850: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
        goto L_800248B0;
    // 0x80024850: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
L_80024854:
    // 0x80024854: sw          $zero, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = 0;
    // 0x80024858: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
    // 0x8002485C: slti        $at, $a1, 0x30
    ctx->r1 = SIGNED(ctx->r5) < 0X30 ? 1 : 0;
    // 0x80024860: bne         $at, $zero, L_800248B0
    if (ctx->r1 != 0) {
        // 0x80024864: slti        $at, $a1, 0x3A
        ctx->r1 = SIGNED(ctx->r5) < 0X3A ? 1 : 0;
            goto L_800248B0;
    }
    // 0x80024864: slti        $at, $a1, 0x3A
    ctx->r1 = SIGNED(ctx->r5) < 0X3A ? 1 : 0;
    // 0x80024868: beql        $at, $zero, L_800248B4
    if (ctx->r1 == 0) {
        // 0x8002486C: addiu       $at, $zero, 0x2E
        ctx->r1 = ADD32(0, 0X2E);
            goto L_800248B4;
    }
    goto skip_2;
    // 0x8002486C: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    skip_2:
    // 0x80024870: lw          $t8, 0xC8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC8);
L_80024874:
    // 0x80024874: slti        $at, $t8, 0x3E7
    ctx->r1 = SIGNED(ctx->r24) < 0X3E7 ? 1 : 0;
    // 0x80024878: beql        $at, $zero, L_80024898
    if (ctx->r1 == 0) {
        // 0x8002487C: lbu         $a1, 0x1($s2)
        ctx->r5 = MEM_BU(ctx->r18, 0X1);
            goto L_80024898;
    }
    goto skip_3;
    // 0x8002487C: lbu         $a1, 0x1($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X1);
    skip_3:
    // 0x80024880: multu       $t8, $fp
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80024884: mflo        $t7
    ctx->r15 = lo;
    // 0x80024888: addu        $t6, $a1, $t7
    ctx->r14 = ADD32(ctx->r5, ctx->r15);
    // 0x8002488C: addiu       $t9, $t6, -0x30
    ctx->r25 = ADD32(ctx->r14, -0X30);
    // 0x80024890: sw          $t9, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r25;
    // 0x80024894: lbu         $a1, 0x1($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X1);
L_80024898:
    // 0x80024898: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8002489C: slti        $at, $a1, 0x30
    ctx->r1 = SIGNED(ctx->r5) < 0X30 ? 1 : 0;
    // 0x800248A0: bne         $at, $zero, L_800248B0
    if (ctx->r1 != 0) {
        // 0x800248A4: slti        $at, $a1, 0x3A
        ctx->r1 = SIGNED(ctx->r5) < 0X3A ? 1 : 0;
            goto L_800248B0;
    }
    // 0x800248A4: slti        $at, $a1, 0x3A
    ctx->r1 = SIGNED(ctx->r5) < 0X3A ? 1 : 0;
    // 0x800248A8: bnel        $at, $zero, L_80024874
    if (ctx->r1 != 0) {
        // 0x800248AC: lw          $t8, 0xC8($sp)
        ctx->r24 = MEM_W(ctx->r29, 0XC8);
            goto L_80024874;
    }
    goto skip_4;
    // 0x800248AC: lw          $t8, 0xC8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC8);
    skip_4:
L_800248B0:
    // 0x800248B0: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
L_800248B4:
    // 0x800248B4: beq         $a1, $at, L_800248C8
    if (ctx->r5 == ctx->r1) {
        // 0x800248B8: addiu       $t8, $zero, -0x1
        ctx->r24 = ADD32(0, -0X1);
            goto L_800248C8;
    }
    // 0x800248B8: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x800248BC: sw          $t8, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r24;
    // 0x800248C0: b           L_8002495C
    // 0x800248C4: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
        goto L_8002495C;
    // 0x800248C4: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
L_800248C8:
    // 0x800248C8: lbu         $t7, 0x1($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0X1);
    // 0x800248CC: lw          $t6, 0xE4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XE4);
    // 0x800248D0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800248D4: bne         $v0, $t7, L_80024900
    if (ctx->r2 != ctx->r15) {
        // 0x800248D8: addiu       $t9, $t6, 0x3
        ctx->r25 = ADD32(ctx->r14, 0X3);
            goto L_80024900;
    }
    // 0x800248D8: addiu       $t9, $t6, 0x3
    ctx->r25 = ADD32(ctx->r14, 0X3);
    // 0x800248DC: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800248E0: and         $t8, $t9, $at
    ctx->r24 = ctx->r25 & ctx->r1;
    // 0x800248E4: addiu       $t7, $t8, 0x4
    ctx->r15 = ADD32(ctx->r24, 0X4);
    // 0x800248E8: sw          $t7, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r15;
    // 0x800248EC: lw          $t6, 0x0($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X0);
    // 0x800248F0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800248F4: sw          $t6, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r14;
    // 0x800248F8: b           L_8002495C
    // 0x800248FC: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
        goto L_8002495C;
    // 0x800248FC: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
L_80024900:
    // 0x80024900: sw          $zero, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = 0;
    // 0x80024904: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
    // 0x80024908: slti        $at, $a1, 0x30
    ctx->r1 = SIGNED(ctx->r5) < 0X30 ? 1 : 0;
    // 0x8002490C: bne         $at, $zero, L_8002495C
    if (ctx->r1 != 0) {
        // 0x80024910: slti        $at, $a1, 0x3A
        ctx->r1 = SIGNED(ctx->r5) < 0X3A ? 1 : 0;
            goto L_8002495C;
    }
    // 0x80024910: slti        $at, $a1, 0x3A
    ctx->r1 = SIGNED(ctx->r5) < 0X3A ? 1 : 0;
    // 0x80024914: beq         $at, $zero, L_8002495C
    if (ctx->r1 == 0) {
        // 0x80024918: nop
    
            goto L_8002495C;
    }
    // 0x80024918: nop

    // 0x8002491C: lw          $t9, 0xC4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC4);
L_80024920:
    // 0x80024920: slti        $at, $t9, 0x3E7
    ctx->r1 = SIGNED(ctx->r25) < 0X3E7 ? 1 : 0;
    // 0x80024924: beql        $at, $zero, L_80024944
    if (ctx->r1 == 0) {
        // 0x80024928: lbu         $a1, 0x1($s2)
        ctx->r5 = MEM_BU(ctx->r18, 0X1);
            goto L_80024944;
    }
    goto skip_5;
    // 0x80024928: lbu         $a1, 0x1($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X1);
    skip_5:
    // 0x8002492C: multu       $t9, $fp
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80024930: mflo        $t7
    ctx->r15 = lo;
    // 0x80024934: addu        $t8, $a1, $t7
    ctx->r24 = ADD32(ctx->r5, ctx->r15);
    // 0x80024938: addiu       $t6, $t8, -0x30
    ctx->r14 = ADD32(ctx->r24, -0X30);
    // 0x8002493C: sw          $t6, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r14;
    // 0x80024940: lbu         $a1, 0x1($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X1);
L_80024944:
    // 0x80024944: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80024948: slti        $at, $a1, 0x30
    ctx->r1 = SIGNED(ctx->r5) < 0X30 ? 1 : 0;
    // 0x8002494C: bne         $at, $zero, L_8002495C
    if (ctx->r1 != 0) {
        // 0x80024950: slti        $at, $a1, 0x3A
        ctx->r1 = SIGNED(ctx->r5) < 0X3A ? 1 : 0;
            goto L_8002495C;
    }
    // 0x80024950: slti        $at, $a1, 0x3A
    ctx->r1 = SIGNED(ctx->r5) < 0X3A ? 1 : 0;
    // 0x80024954: bnel        $at, $zero, L_80024920
    if (ctx->r1 != 0) {
        // 0x80024958: lw          $t9, 0xC4($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XC4);
            goto L_80024920;
    }
    goto skip_6;
    // 0x80024958: lw          $t9, 0xC4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC4);
    skip_6:
L_8002495C:
    // 0x8002495C: jal         0x80024014
    // 0x80024960: addiu       $a0, $a0, -0x6C20
    ctx->r4 = ADD32(ctx->r4, -0X6C20);
    strchr_recomp(rdram, ctx);
        goto after_3;
    // 0x80024960: addiu       $a0, $a0, -0x6C20
    ctx->r4 = ADD32(ctx->r4, -0X6C20);
    after_3:
    // 0x80024964: beq         $v0, $zero, L_8002497C
    if (ctx->r2 == 0) {
        // 0x80024968: addiu       $s0, $sp, 0xA0
        ctx->r16 = ADD32(ctx->r29, 0XA0);
            goto L_8002497C;
    }
    // 0x80024968: addiu       $s0, $sp, 0xA0
    ctx->r16 = ADD32(ctx->r29, 0XA0);
    // 0x8002496C: lbu         $t9, 0x0($s2)
    ctx->r25 = MEM_BU(ctx->r18, 0X0);
    // 0x80024970: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80024974: b           L_80024980
    // 0x80024978: sb          $t9, 0xD4($sp)
    MEM_B(0XD4, ctx->r29) = ctx->r25;
        goto L_80024980;
    // 0x80024978: sb          $t9, 0xD4($sp)
    MEM_B(0XD4, ctx->r29) = ctx->r25;
L_8002497C:
    // 0x8002497C: sb          $zero, 0xD4($sp)
    MEM_B(0XD4, ctx->r29) = 0;
L_80024980:
    // 0x80024980: lbu         $t7, 0xD4($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0XD4);
    // 0x80024984: addiu       $v0, $zero, 0x6C
    ctx->r2 = ADD32(0, 0X6C);
    // 0x80024988: addiu       $a2, $sp, 0xE4
    ctx->r6 = ADD32(ctx->r29, 0XE4);
    // 0x8002498C: bne         $v0, $t7, L_800249AC
    if (ctx->r2 != ctx->r15) {
        // 0x80024990: addiu       $a3, $sp, 0x74
        ctx->r7 = ADD32(ctx->r29, 0X74);
            goto L_800249AC;
    }
    // 0x80024990: addiu       $a3, $sp, 0x74
    ctx->r7 = ADD32(ctx->r29, 0X74);
    // 0x80024994: lbu         $t8, 0x0($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0X0);
    // 0x80024998: addiu       $t6, $zero, 0x4C
    ctx->r14 = ADD32(0, 0X4C);
    // 0x8002499C: bne         $v0, $t8, L_800249AC
    if (ctx->r2 != ctx->r24) {
        // 0x800249A0: nop
    
            goto L_800249AC;
    }
    // 0x800249A0: nop

    // 0x800249A4: sb          $t6, 0xD4($sp)
    MEM_B(0XD4, ctx->r29) = ctx->r14;
    // 0x800249A8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_800249AC:
    // 0x800249AC: jal         0x80024060
    // 0x800249B0: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
    static_1_80024060(rdram, ctx);
        goto after_4;
    // 0x800249B0: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
    after_4:
    // 0x800249B4: lw          $t9, 0xC8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC8);
    // 0x800249B8: lw          $t7, 0xAC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XAC);
    // 0x800249BC: lw          $t6, 0xB0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB0);
    // 0x800249C0: subu        $t8, $t9, $t7
    ctx->r24 = SUB32(ctx->r25, ctx->r15);
    // 0x800249C4: lw          $t7, 0xB4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB4);
    // 0x800249C8: subu        $t9, $t8, $t6
    ctx->r25 = SUB32(ctx->r24, ctx->r14);
    // 0x800249CC: lw          $t6, 0xB8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB8);
    // 0x800249D0: subu        $t8, $t9, $t7
    ctx->r24 = SUB32(ctx->r25, ctx->r15);
    // 0x800249D4: lw          $t7, 0xBC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XBC);
    // 0x800249D8: subu        $t9, $t8, $t6
    ctx->r25 = SUB32(ctx->r24, ctx->r14);
    // 0x800249DC: lw          $t6, 0xC0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC0);
    // 0x800249E0: subu        $t8, $t9, $t7
    ctx->r24 = SUB32(ctx->r25, ctx->r15);
    // 0x800249E4: lw          $t7, 0xD0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XD0);
    // 0x800249E8: subu        $t9, $t8, $t6
    ctx->r25 = SUB32(ctx->r24, ctx->r14);
    // 0x800249EC: sw          $t9, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r25;
    // 0x800249F0: andi        $t8, $t7, 0x4
    ctx->r24 = ctx->r15 & 0X4;
    // 0x800249F4: bne         $t8, $zero, L_80024A60
    if (ctx->r24 != 0) {
        // 0x800249F8: slt         $t6, $zero, $t9
        ctx->r14 = SIGNED(0) < SIGNED(ctx->r25) ? 1 : 0;
            goto L_80024A60;
    }
    // 0x800249F8: slt         $t6, $zero, $t9
    ctx->r14 = SIGNED(0) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800249FC: beql        $t6, $zero, L_80024A64
    if (ctx->r14 == 0) {
        // 0x80024A00: lw          $t9, 0xAC($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XAC);
            goto L_80024A64;
    }
    goto skip_7;
    // 0x80024A00: lw          $t9, 0xAC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XAC);
    skip_7:
    // 0x80024A04: beq         $t6, $zero, L_80024A60
    if (ctx->r14 == 0) {
        // 0x80024A08: or          $s1, $t9, $zero
        ctx->r17 = ctx->r25 | 0;
            goto L_80024A60;
    }
    // 0x80024A08: or          $s1, $t9, $zero
    ctx->r17 = ctx->r25 | 0;
    // 0x80024A0C: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
L_80024A10:
    // 0x80024A10: bne         $at, $zero, L_80024A20
    if (ctx->r1 != 0) {
        // 0x80024A14: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_80024A20;
    }
    // 0x80024A14: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x80024A18: b           L_80024A20
    // 0x80024A1C: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
        goto L_80024A20;
    // 0x80024A1C: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
L_80024A20:
    // 0x80024A20: blez        $s0, L_80024A54
    if (SIGNED(ctx->r16) <= 0) {
        // 0x80024A24: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80024A54;
    }
    // 0x80024A24: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80024A28: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x80024A2C: jalr        $s4
    // 0x80024A30: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_5;
    // 0x80024A30: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_5:
    // 0x80024A34: beq         $v0, $zero, L_80024A4C
    if (ctx->r2 == 0) {
        // 0x80024A38: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_80024A4C;
    }
    // 0x80024A38: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80024A3C: lw          $t7, 0xCC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XCC);
    // 0x80024A40: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x80024A44: b           L_80024A54
    // 0x80024A48: sw          $t8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r24;
        goto L_80024A54;
    // 0x80024A48: sw          $t8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r24;
L_80024A4C:
    // 0x80024A4C: b           L_80024CE8
    // 0x80024A50: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
        goto L_80024CE8;
    // 0x80024A50: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
L_80024A54:
    // 0x80024A54: subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    // 0x80024A58: bgtzl       $s1, L_80024A10
    if (SIGNED(ctx->r17) > 0) {
        // 0x80024A5C: sltiu       $at, $s1, 0x21
        ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
            goto L_80024A10;
    }
    goto skip_8;
    // 0x80024A5C: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
    skip_8:
L_80024A60:
    // 0x80024A60: lw          $t9, 0xAC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XAC);
L_80024A64:
    // 0x80024A64: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80024A68: addiu       $a1, $sp, 0x74
    ctx->r5 = ADD32(ctx->r29, 0X74);
    // 0x80024A6C: blezl       $t9, L_80024AA4
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80024A70: lw          $t9, 0xB0($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XB0);
            goto L_80024AA4;
    }
    goto skip_9;
    // 0x80024A70: lw          $t9, 0xB0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB0);
    skip_9:
    // 0x80024A74: jalr        $s4
    // 0x80024A78: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_6;
    // 0x80024A78: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    after_6:
    // 0x80024A7C: beq         $v0, $zero, L_80024A98
    if (ctx->r2 == 0) {
        // 0x80024A80: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_80024A98;
    }
    // 0x80024A80: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80024A84: lw          $t6, 0xCC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XCC);
    // 0x80024A88: lw          $t7, 0xAC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XAC);
    // 0x80024A8C: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80024A90: b           L_80024AA0
    // 0x80024A94: sw          $t8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r24;
        goto L_80024AA0;
    // 0x80024A94: sw          $t8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r24;
L_80024A98:
    // 0x80024A98: b           L_80024CE8
    // 0x80024A9C: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
        goto L_80024CE8;
    // 0x80024A9C: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
L_80024AA0:
    // 0x80024AA0: lw          $t9, 0xB0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB0);
L_80024AA4:
    // 0x80024AA4: slt         $t6, $zero, $t9
    ctx->r14 = SIGNED(0) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80024AA8: beql        $t6, $zero, L_80024B10
    if (ctx->r14 == 0) {
        // 0x80024AAC: lw          $t9, 0xB4($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XB4);
            goto L_80024B10;
    }
    goto skip_10;
    // 0x80024AAC: lw          $t9, 0xB4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB4);
    skip_10:
    // 0x80024AB0: beq         $t6, $zero, L_80024B0C
    if (ctx->r14 == 0) {
        // 0x80024AB4: or          $s1, $t9, $zero
        ctx->r17 = ctx->r25 | 0;
            goto L_80024B0C;
    }
    // 0x80024AB4: or          $s1, $t9, $zero
    ctx->r17 = ctx->r25 | 0;
    // 0x80024AB8: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
L_80024ABC:
    // 0x80024ABC: bne         $at, $zero, L_80024ACC
    if (ctx->r1 != 0) {
        // 0x80024AC0: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_80024ACC;
    }
    // 0x80024AC0: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x80024AC4: b           L_80024ACC
    // 0x80024AC8: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
        goto L_80024ACC;
    // 0x80024AC8: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
L_80024ACC:
    // 0x80024ACC: blez        $s0, L_80024B00
    if (SIGNED(ctx->r16) <= 0) {
        // 0x80024AD0: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80024B00;
    }
    // 0x80024AD0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80024AD4: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80024AD8: jalr        $s4
    // 0x80024ADC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_7;
    // 0x80024ADC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_7:
    // 0x80024AE0: beq         $v0, $zero, L_80024AF8
    if (ctx->r2 == 0) {
        // 0x80024AE4: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_80024AF8;
    }
    // 0x80024AE4: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80024AE8: lw          $t7, 0xCC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XCC);
    // 0x80024AEC: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x80024AF0: b           L_80024B00
    // 0x80024AF4: sw          $t8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r24;
        goto L_80024B00;
    // 0x80024AF4: sw          $t8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r24;
L_80024AF8:
    // 0x80024AF8: b           L_80024CE8
    // 0x80024AFC: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
        goto L_80024CE8;
    // 0x80024AFC: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
L_80024B00:
    // 0x80024B00: subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    // 0x80024B04: bgtzl       $s1, L_80024ABC
    if (SIGNED(ctx->r17) > 0) {
        // 0x80024B08: sltiu       $at, $s1, 0x21
        ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
            goto L_80024ABC;
    }
    goto skip_11;
    // 0x80024B08: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
    skip_11:
L_80024B0C:
    // 0x80024B0C: lw          $t9, 0xB4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB4);
L_80024B10:
    // 0x80024B10: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80024B14: lw          $a1, 0xA8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA8);
    // 0x80024B18: blezl       $t9, L_80024B50
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80024B1C: lw          $t9, 0xB8($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XB8);
            goto L_80024B50;
    }
    goto skip_12;
    // 0x80024B1C: lw          $t9, 0xB8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB8);
    skip_12:
    // 0x80024B20: jalr        $s4
    // 0x80024B24: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_8;
    // 0x80024B24: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    after_8:
    // 0x80024B28: beq         $v0, $zero, L_80024B44
    if (ctx->r2 == 0) {
        // 0x80024B2C: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_80024B44;
    }
    // 0x80024B2C: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80024B30: lw          $t6, 0xCC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XCC);
    // 0x80024B34: lw          $t7, 0xB4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB4);
    // 0x80024B38: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80024B3C: b           L_80024B4C
    // 0x80024B40: sw          $t8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r24;
        goto L_80024B4C;
    // 0x80024B40: sw          $t8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r24;
L_80024B44:
    // 0x80024B44: b           L_80024CE8
    // 0x80024B48: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
        goto L_80024CE8;
    // 0x80024B48: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
L_80024B4C:
    // 0x80024B4C: lw          $t9, 0xB8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB8);
L_80024B50:
    // 0x80024B50: slt         $t6, $zero, $t9
    ctx->r14 = SIGNED(0) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80024B54: beql        $t6, $zero, L_80024BBC
    if (ctx->r14 == 0) {
        // 0x80024B58: lw          $t9, 0xBC($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XBC);
            goto L_80024BBC;
    }
    goto skip_13;
    // 0x80024B58: lw          $t9, 0xBC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XBC);
    skip_13:
    // 0x80024B5C: beq         $t6, $zero, L_80024BB8
    if (ctx->r14 == 0) {
        // 0x80024B60: or          $s1, $t9, $zero
        ctx->r17 = ctx->r25 | 0;
            goto L_80024BB8;
    }
    // 0x80024B60: or          $s1, $t9, $zero
    ctx->r17 = ctx->r25 | 0;
    // 0x80024B64: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
L_80024B68:
    // 0x80024B68: bne         $at, $zero, L_80024B78
    if (ctx->r1 != 0) {
        // 0x80024B6C: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_80024B78;
    }
    // 0x80024B6C: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x80024B70: b           L_80024B78
    // 0x80024B74: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
        goto L_80024B78;
    // 0x80024B74: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
L_80024B78:
    // 0x80024B78: blez        $s0, L_80024BAC
    if (SIGNED(ctx->r16) <= 0) {
        // 0x80024B7C: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80024BAC;
    }
    // 0x80024B7C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80024B80: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80024B84: jalr        $s4
    // 0x80024B88: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_9;
    // 0x80024B88: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_9:
    // 0x80024B8C: beq         $v0, $zero, L_80024BA4
    if (ctx->r2 == 0) {
        // 0x80024B90: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_80024BA4;
    }
    // 0x80024B90: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80024B94: lw          $t7, 0xCC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XCC);
    // 0x80024B98: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x80024B9C: b           L_80024BAC
    // 0x80024BA0: sw          $t8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r24;
        goto L_80024BAC;
    // 0x80024BA0: sw          $t8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r24;
L_80024BA4:
    // 0x80024BA4: b           L_80024CE8
    // 0x80024BA8: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
        goto L_80024CE8;
    // 0x80024BA8: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
L_80024BAC:
    // 0x80024BAC: subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    // 0x80024BB0: bgtzl       $s1, L_80024B68
    if (SIGNED(ctx->r17) > 0) {
        // 0x80024BB4: sltiu       $at, $s1, 0x21
        ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
            goto L_80024B68;
    }
    goto skip_14;
    // 0x80024BB4: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
    skip_14:
L_80024BB8:
    // 0x80024BB8: lw          $t9, 0xBC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XBC);
L_80024BBC:
    // 0x80024BBC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80024BC0: lw          $t6, 0xA8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA8);
    // 0x80024BC4: blez        $t9, L_80024BFC
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80024BC8: lw          $t7, 0xB4($sp)
        ctx->r15 = MEM_W(ctx->r29, 0XB4);
            goto L_80024BFC;
    }
    // 0x80024BC8: lw          $t7, 0xB4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB4);
    // 0x80024BCC: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    // 0x80024BD0: jalr        $s4
    // 0x80024BD4: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_10;
    // 0x80024BD4: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    after_10:
    // 0x80024BD8: beq         $v0, $zero, L_80024BF4
    if (ctx->r2 == 0) {
        // 0x80024BDC: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_80024BF4;
    }
    // 0x80024BDC: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80024BE0: lw          $t8, 0xCC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XCC);
    // 0x80024BE4: lw          $t6, 0xBC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XBC);
    // 0x80024BE8: addu        $t7, $t8, $t6
    ctx->r15 = ADD32(ctx->r24, ctx->r14);
    // 0x80024BEC: b           L_80024BFC
    // 0x80024BF0: sw          $t7, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r15;
        goto L_80024BFC;
    // 0x80024BF0: sw          $t7, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r15;
L_80024BF4:
    // 0x80024BF4: b           L_80024CE8
    // 0x80024BF8: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
        goto L_80024CE8;
    // 0x80024BF8: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
L_80024BFC:
    // 0x80024BFC: lw          $t9, 0xC0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC0);
    // 0x80024C00: slt         $t8, $zero, $t9
    ctx->r24 = SIGNED(0) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80024C04: beql        $t8, $zero, L_80024C6C
    if (ctx->r24 == 0) {
        // 0x80024C08: lw          $t9, 0xD0($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XD0);
            goto L_80024C6C;
    }
    goto skip_15;
    // 0x80024C08: lw          $t9, 0xD0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD0);
    skip_15:
    // 0x80024C0C: beq         $t8, $zero, L_80024C68
    if (ctx->r24 == 0) {
        // 0x80024C10: or          $s1, $t9, $zero
        ctx->r17 = ctx->r25 | 0;
            goto L_80024C68;
    }
    // 0x80024C10: or          $s1, $t9, $zero
    ctx->r17 = ctx->r25 | 0;
    // 0x80024C14: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
L_80024C18:
    // 0x80024C18: bne         $at, $zero, L_80024C28
    if (ctx->r1 != 0) {
        // 0x80024C1C: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_80024C28;
    }
    // 0x80024C1C: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x80024C20: b           L_80024C28
    // 0x80024C24: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
        goto L_80024C28;
    // 0x80024C24: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
L_80024C28:
    // 0x80024C28: blez        $s0, L_80024C5C
    if (SIGNED(ctx->r16) <= 0) {
        // 0x80024C2C: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80024C5C;
    }
    // 0x80024C2C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80024C30: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80024C34: jalr        $s4
    // 0x80024C38: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_11;
    // 0x80024C38: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_11:
    // 0x80024C3C: beq         $v0, $zero, L_80024C54
    if (ctx->r2 == 0) {
        // 0x80024C40: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_80024C54;
    }
    // 0x80024C40: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80024C44: lw          $t6, 0xCC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XCC);
    // 0x80024C48: addu        $t7, $t6, $s0
    ctx->r15 = ADD32(ctx->r14, ctx->r16);
    // 0x80024C4C: b           L_80024C5C
    // 0x80024C50: sw          $t7, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r15;
        goto L_80024C5C;
    // 0x80024C50: sw          $t7, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r15;
L_80024C54:
    // 0x80024C54: b           L_80024CE8
    // 0x80024C58: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
        goto L_80024CE8;
    // 0x80024C58: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
L_80024C5C:
    // 0x80024C5C: subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    // 0x80024C60: bgtzl       $s1, L_80024C18
    if (SIGNED(ctx->r17) > 0) {
        // 0x80024C64: sltiu       $at, $s1, 0x21
        ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
            goto L_80024C18;
    }
    goto skip_16;
    // 0x80024C64: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
    skip_16:
L_80024C68:
    // 0x80024C68: lw          $t9, 0xD0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD0);
L_80024C6C:
    // 0x80024C6C: lw          $t6, 0xC8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC8);
    // 0x80024C70: andi        $t8, $t9, 0x4
    ctx->r24 = ctx->r25 & 0X4;
    // 0x80024C74: beq         $t8, $zero, L_80024CE0
    if (ctx->r24 == 0) {
        // 0x80024C78: slt         $t7, $zero, $t6
        ctx->r15 = SIGNED(0) < SIGNED(ctx->r14) ? 1 : 0;
            goto L_80024CE0;
    }
    // 0x80024C78: slt         $t7, $zero, $t6
    ctx->r15 = SIGNED(0) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80024C7C: beq         $t7, $zero, L_80024CE0
    if (ctx->r15 == 0) {
        // 0x80024C80: nop
    
            goto L_80024CE0;
    }
    // 0x80024C80: nop

    // 0x80024C84: beq         $t7, $zero, L_80024CE0
    if (ctx->r15 == 0) {
        // 0x80024C88: or          $s1, $t6, $zero
        ctx->r17 = ctx->r14 | 0;
            goto L_80024CE0;
    }
    // 0x80024C88: or          $s1, $t6, $zero
    ctx->r17 = ctx->r14 | 0;
    // 0x80024C8C: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
L_80024C90:
    // 0x80024C90: bne         $at, $zero, L_80024CA0
    if (ctx->r1 != 0) {
        // 0x80024C94: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_80024CA0;
    }
    // 0x80024C94: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x80024C98: b           L_80024CA0
    // 0x80024C9C: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
        goto L_80024CA0;
    // 0x80024C9C: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
L_80024CA0:
    // 0x80024CA0: blez        $s0, L_80024CD4
    if (SIGNED(ctx->r16) <= 0) {
        // 0x80024CA4: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80024CD4;
    }
    // 0x80024CA4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80024CA8: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x80024CAC: jalr        $s4
    // 0x80024CB0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_12;
    // 0x80024CB0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_12:
    // 0x80024CB4: beq         $v0, $zero, L_80024CCC
    if (ctx->r2 == 0) {
        // 0x80024CB8: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_80024CCC;
    }
    // 0x80024CB8: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80024CBC: lw          $t9, 0xCC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XCC);
    // 0x80024CC0: addu        $t8, $t9, $s0
    ctx->r24 = ADD32(ctx->r25, ctx->r16);
    // 0x80024CC4: b           L_80024CD4
    // 0x80024CC8: sw          $t8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r24;
        goto L_80024CD4;
    // 0x80024CC8: sw          $t8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r24;
L_80024CCC:
    // 0x80024CCC: b           L_80024CE8
    // 0x80024CD0: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
        goto L_80024CE8;
    // 0x80024CD0: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
L_80024CD4:
    // 0x80024CD4: subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    // 0x80024CD8: bgtzl       $s1, L_80024C90
    if (SIGNED(ctx->r17) > 0) {
        // 0x80024CDC: sltiu       $at, $s1, 0x21
        ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
            goto L_80024C90;
    }
    goto skip_17;
    // 0x80024CDC: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
    skip_17:
L_80024CE0:
    // 0x80024CE0: b           L_80024730
    // 0x80024CE4: addiu       $a3, $s2, 0x1
    ctx->r7 = ADD32(ctx->r18, 0X1);
        goto L_80024730;
    // 0x80024CE4: addiu       $a3, $s2, 0x1
    ctx->r7 = ADD32(ctx->r18, 0X1);
L_80024CE8:
    // 0x80024CE8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80024CEC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80024CF0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80024CF4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80024CF8: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80024CFC: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80024D00: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80024D04: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80024D08: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80024D0C: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80024D10: jr          $ra
    // 0x80024D14: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
    return;
    // 0x80024D14: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
;}
RECOMP_FUNC void func_versus_800BEDDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BEDDC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800BEDE0: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800BEDE4: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x800BEDE8: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x800BEDEC: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x800BEDF0: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x800BEDF4: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800BEDF8: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800BEDFC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800BEE00: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800BEE04: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800BEE08: lw          $t6, -0x78A4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X78A4);
    // 0x800BEE0C: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x800BEE10: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800BEE14: bne         $t6, $zero, L_800BEE28
    if (ctx->r14 != 0) {
        // 0x800BEE18: lui         $t8, 0x8017
        ctx->r24 = S32(0X8017 << 16);
            goto L_800BEE28;
    }
    // 0x800BEE18: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x800BEE1C: lw          $t7, -0x78A0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X78A0);
    // 0x800BEE20: beq         $t7, $zero, L_800BEE3C
    if (ctx->r15 == 0) {
        // 0x800BEE24: nop
    
            goto L_800BEE3C;
    }
    // 0x800BEE24: nop

L_800BEE28:
    // 0x800BEE28: lw          $t8, 0x789C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X789C);
    // 0x800BEE2C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800BEE30: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800BEE34: bne         $t8, $at, L_800BEE4C
    if (ctx->r24 != ctx->r1) {
        // 0x800BEE38: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_800BEE4C;
    }
    // 0x800BEE38: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_800BEE3C:
    // 0x800BEE3C: jal         0x800BED78
    // 0x800BEE40: nop

    func_versus_800BED78(rdram, ctx);
        goto after_0;
    // 0x800BEE40: nop

    after_0:
    // 0x800BEE44: b           L_800BEED4
    // 0x800BEE48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800BEED4;
    // 0x800BEE48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800BEE4C:
    // 0x800BEE4C: lui         $s3, 0x8016
    ctx->r19 = S32(0X8016 << 16);
    // 0x800BEE50: lui         $s7, 0x8018
    ctx->r23 = S32(0X8018 << 16);
    // 0x800BEE54: lui         $s6, 0x8018
    ctx->r22 = S32(0X8018 << 16);
    // 0x800BEE58: addiu       $s6, $s6, -0x7880
    ctx->r22 = ADD32(ctx->r22, -0X7880);
    // 0x800BEE5C: addiu       $s7, $s7, -0x784C
    ctx->r23 = ADD32(ctx->r23, -0X784C);
    // 0x800BEE60: addiu       $s3, $s3, 0x1A18
    ctx->r19 = ADD32(ctx->r19, 0X1A18);
    // 0x800BEE64: addiu       $s5, $zero, 0x4
    ctx->r21 = ADD32(0, 0X4);
L_800BEE68:
    // 0x800BEE68: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x800BEE6C: addu        $s1, $s6, $s2
    ctx->r17 = ADD32(ctx->r22, ctx->r18);
    // 0x800BEE70: bnel        $t9, $zero, L_800BEEC4
    if (ctx->r25 != 0) {
        // 0x800BEE74: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800BEEC4;
    }
    goto skip_0;
    // 0x800BEE74: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x800BEE78: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x800BEE7C: bne         $t0, $zero, L_800BEE94
    if (ctx->r8 != 0) {
        // 0x800BEE80: nop
    
            goto L_800BEE94;
    }
    // 0x800BEE80: nop

    // 0x800BEE84: jal         0x800BE924
    // 0x800BEE88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_versus_800BE924(rdram, ctx);
        goto after_1;
    // 0x800BEE88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800BEE8C: b           L_800BEEA0
    // 0x800BEE90: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
        goto L_800BEEA0;
    // 0x800BEE90: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
L_800BEE94:
    // 0x800BEE94: jal         0x800BECA8
    // 0x800BEE98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_versus_800BECA8(rdram, ctx);
        goto after_2;
    // 0x800BEE98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800BEE9C: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
L_800BEEA0:
    // 0x800BEEA0: beql        $t1, $zero, L_800BEEC4
    if (ctx->r9 == 0) {
        // 0x800BEEA4: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800BEEC4;
    }
    goto skip_1;
    // 0x800BEEA4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_1:
    // 0x800BEEA8: lw          $t2, 0x0($s7)
    ctx->r10 = MEM_W(ctx->r23, 0X0);
    // 0x800BEEAC: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800BEEB0: bnel        $s4, $t2, L_800BEEC4
    if (ctx->r20 != ctx->r10) {
        // 0x800BEEB4: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800BEEC4;
    }
    goto skip_2;
    // 0x800BEEB4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_2:
    // 0x800BEEB8: jal         0x800BED78
    // 0x800BEEBC: nop

    func_versus_800BED78(rdram, ctx);
        goto after_3;
    // 0x800BEEBC: nop

    after_3:
    // 0x800BEEC0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800BEEC4:
    // 0x800BEEC4: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x800BEEC8: bne         $s0, $s5, L_800BEE68
    if (ctx->r16 != ctx->r21) {
        // 0x800BEECC: addiu       $s3, $s3, 0x4
        ctx->r19 = ADD32(ctx->r19, 0X4);
            goto L_800BEE68;
    }
    // 0x800BEECC: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x800BEED0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800BEED4:
    // 0x800BEED4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800BEED8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800BEEDC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800BEEE0: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800BEEE4: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800BEEE8: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x800BEEEC: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x800BEEF0: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x800BEEF4: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x800BEEF8: jr          $ra
    // 0x800BEEFC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800BEEFC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_tank_80044120(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80044120: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80044124: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80044128: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x8004412C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80044130: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80044134: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x80044138: lwc1        $f4, 0x50($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8004413C: lwc1        $f8, 0x54($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80044140: lwc1        $f16, 0x4C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80044144: lwc1        $f18, 0x58($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80044148: sub.s       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f12.fl - ctx->f4.fl;
    // 0x8004414C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80044150: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80044154: sub.s       $f10, $f14, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f14.fl - ctx->f8.fl;
    // 0x80044158: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    // 0x8004415C: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80044160: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80044164: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    // 0x80044168: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    // 0x8004416C: jal         0x80006A20
    // 0x80044170: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_0;
    // 0x80044170: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x80044174: lwc1        $f0, 0x50($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80044178: lwc1        $f2, 0x54($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8004417C: lwc1        $f12, 0x58($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80044180: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80044184: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80044188: lwc1        $f18, 0x30($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8004418C: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x80044190: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80044194: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80044198: add.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x8004419C: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x800441A0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x800441A4: add.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f12.fl;
    // 0x800441A8: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x800441AC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800441B0: jal         0x800A78C4
    // 0x800441B4: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    Play_CheckSingleHitbox(rdram, ctx);
        goto after_1;
    // 0x800441B4: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x800441B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800441BC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x800441C0: jr          $ra
    // 0x800441C4: nop

    return;
    // 0x800441C4: nop

;}
RECOMP_FUNC void Timer_ThreadEntry(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800040D4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800040D8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800040DC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800040E0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800040E4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800040E8: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x800040EC: addiu       $s0, $s0, 0x2338
    ctx->r16 = ADD32(ctx->r16, 0X2338);
    // 0x800040F0: addiu       $s1, $sp, 0x24
    ctx->r17 = ADD32(ctx->r29, 0X24);
    // 0x800040F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800040F8:
    // 0x800040F8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800040FC: jal         0x800205E0
    // 0x80004100: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80004100: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80004104: jal         0x80007088
    // 0x80004108: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    Timer_CompleteTask(rdram, ctx);
        goto after_1;
    // 0x80004108: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x8000410C: b           L_800040F8
    // 0x80004110: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_800040F8;
    // 0x80004110: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80004114: nop

    // 0x80004118: nop

    // 0x8000411C: nop

    // 0x80004120: nop

    // 0x80004124: nop

    // 0x80004128: nop

    // 0x8000412C: nop

    // 0x80004130: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80004134: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80004138: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8000413C: jr          $ra
    // 0x80004140: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80004140: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void Audio_SetHeatAlarmParams(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D1C8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8001D1CC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8001D1D0: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // 0x8001D1D4: sra         $a1, $v0, 2
    ctx->r5 = S32(SIGNED(ctx->r2) >> 2);
    // 0x8001D1D8: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x8001D1DC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8001D1E0: sll         $t6, $a1, 24
    ctx->r14 = S32(ctx->r5 << 24);
    // 0x8001D1E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001D1E8: sra         $a1, $t6, 24
    ctx->r5 = S32(SIGNED(ctx->r14) >> 24);
    // 0x8001D1EC: lui         $a0, 0x602
    ctx->r4 = S32(0X602 << 16);
    // 0x8001D1F0: ori         $a0, $a0, 0x902
    ctx->r4 = ctx->r4 | 0X902;
    // 0x8001D1F4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8001D1F8: jal         0x8001E8F0
    // 0x8001D1FC: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    AudioThread_QueueCmdS8(rdram, ctx);
        goto after_0;
    // 0x8001D1FC: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_0:
    // 0x8001D200: lui         $a0, 0x602
    ctx->r4 = S32(0X602 << 16);
    // 0x8001D204: ori         $a0, $a0, 0xA02
    ctx->r4 = ctx->r4 | 0XA02;
    // 0x8001D208: jal         0x8001E8F0
    // 0x8001D20C: lb          $a1, 0x1F($sp)
    ctx->r5 = MEM_B(ctx->r29, 0X1F);
    AudioThread_QueueCmdS8(rdram, ctx);
        goto after_1;
    // 0x8001D20C: lb          $a1, 0x1F($sp)
    ctx->r5 = MEM_B(ctx->r29, 0X1F);
    after_1:
    // 0x8001D210: lui         $a0, 0x602
    ctx->r4 = S32(0X602 << 16);
    // 0x8001D214: ori         $a0, $a0, 0xB02
    ctx->r4 = ctx->r4 | 0XB02;
    // 0x8001D218: jal         0x8001E8F0
    // 0x8001D21C: lb          $a1, 0x1F($sp)
    ctx->r5 = MEM_B(ctx->r29, 0X1F);
    AudioThread_QueueCmdS8(rdram, ctx);
        goto after_2;
    // 0x8001D21C: lb          $a1, 0x1F($sp)
    ctx->r5 = MEM_B(ctx->r29, 0X1F);
    after_2:
    // 0x8001D220: lbu         $v0, 0x2F($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X2F);
    // 0x8001D224: addiu       $t9, $zero, 0x13
    ctx->r25 = ADD32(0, 0X13);
    // 0x8001D228: lui         $a0, 0x602
    ctx->r4 = S32(0X602 << 16);
    // 0x8001D22C: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x8001D230: subu        $t8, $t8, $v0
    ctx->r24 = SUB32(ctx->r24, ctx->r2);
    // 0x8001D234: subu        $a1, $t9, $t8
    ctx->r5 = SUB32(ctx->r25, ctx->r24);
    // 0x8001D238: sll         $t0, $a1, 24
    ctx->r8 = S32(ctx->r5 << 24);
    // 0x8001D23C: sra         $a1, $t0, 24
    ctx->r5 = S32(SIGNED(ctx->r8) >> 24);
    // 0x8001D240: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    // 0x8001D244: ori         $a0, $a0, 0x901
    ctx->r4 = ctx->r4 | 0X901;
    // 0x8001D248: jal         0x8001E8F0
    // 0x8001D24C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    AudioThread_QueueCmdS8(rdram, ctx);
        goto after_3;
    // 0x8001D24C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_3:
    // 0x8001D250: lui         $a0, 0x602
    ctx->r4 = S32(0X602 << 16);
    // 0x8001D254: ori         $a0, $a0, 0xA01
    ctx->r4 = ctx->r4 | 0XA01;
    // 0x8001D258: jal         0x8001E8F0
    // 0x8001D25C: lb          $a1, 0x1B($sp)
    ctx->r5 = MEM_B(ctx->r29, 0X1B);
    AudioThread_QueueCmdS8(rdram, ctx);
        goto after_4;
    // 0x8001D25C: lb          $a1, 0x1B($sp)
    ctx->r5 = MEM_B(ctx->r29, 0X1B);
    after_4:
    // 0x8001D260: lui         $a0, 0x602
    ctx->r4 = S32(0X602 << 16);
    // 0x8001D264: ori         $a0, $a0, 0xB01
    ctx->r4 = ctx->r4 | 0XB01;
    // 0x8001D268: jal         0x8001E8F0
    // 0x8001D26C: lb          $a1, 0x1B($sp)
    ctx->r5 = MEM_B(ctx->r29, 0X1B);
    AudioThread_QueueCmdS8(rdram, ctx);
        goto after_5;
    // 0x8001D26C: lb          $a1, 0x1B($sp)
    ctx->r5 = MEM_B(ctx->r29, 0X1B);
    after_5:
    // 0x8001D270: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x8001D274: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8001D278: addiu       $t4, $zero, 0x44
    ctx->r12 = ADD32(0, 0X44);
    // 0x8001D27C: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8001D280: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8001D284: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x8001D288: addiu       $t7, $zero, 0x50
    ctx->r15 = ADD32(0, 0X50);
    // 0x8001D28C: sra         $t3, $t2, 3
    ctx->r11 = S32(SIGNED(ctx->r10) >> 3);
    // 0x8001D290: subu        $v0, $t4, $t3
    ctx->r2 = SUB32(ctx->r12, ctx->r11);
    // 0x8001D294: subu        $a0, $t7, $t6
    ctx->r4 = SUB32(ctx->r15, ctx->r14);
    // 0x8001D298: andi        $t9, $a0, 0xFF
    ctx->r25 = ctx->r4 & 0XFF;
    // 0x8001D29C: andi        $t8, $v0, 0xFF
    ctx->r24 = ctx->r2 & 0XFF;
    // 0x8001D2A0: slt         $at, $t8, $t9
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8001D2A4: beq         $at, $zero, L_8001D2B0
    if (ctx->r1 == 0) {
        // 0x8001D2A8: andi        $v1, $v0, 0xFF
        ctx->r3 = ctx->r2 & 0XFF;
            goto L_8001D2B0;
    }
    // 0x8001D2A8: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x8001D2AC: andi        $v1, $t9, 0xFF
    ctx->r3 = ctx->r25 & 0XFF;
L_8001D2B0:
    // 0x8001D2B0: sll         $a1, $v1, 24
    ctx->r5 = S32(ctx->r3 << 24);
    // 0x8001D2B4: sra         $t0, $a1, 24
    ctx->r8 = S32(SIGNED(ctx->r5) >> 24);
    // 0x8001D2B8: lui         $a0, 0x602
    ctx->r4 = S32(0X602 << 16);
    // 0x8001D2BC: ori         $a0, $a0, 0x903
    ctx->r4 = ctx->r4 | 0X903;
    // 0x8001D2C0: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    // 0x8001D2C4: jal         0x8001E8F0
    // 0x8001D2C8: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    AudioThread_QueueCmdS8(rdram, ctx);
        goto after_6;
    // 0x8001D2C8: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    after_6:
    // 0x8001D2CC: lui         $a0, 0x602
    ctx->r4 = S32(0X602 << 16);
    // 0x8001D2D0: ori         $a0, $a0, 0xA03
    ctx->r4 = ctx->r4 | 0XA03;
    // 0x8001D2D4: jal         0x8001E8F0
    // 0x8001D2D8: lb          $a1, 0x23($sp)
    ctx->r5 = MEM_B(ctx->r29, 0X23);
    AudioThread_QueueCmdS8(rdram, ctx);
        goto after_7;
    // 0x8001D2D8: lb          $a1, 0x23($sp)
    ctx->r5 = MEM_B(ctx->r29, 0X23);
    after_7:
    // 0x8001D2DC: lui         $a0, 0x602
    ctx->r4 = S32(0X602 << 16);
    // 0x8001D2E0: ori         $a0, $a0, 0xB03
    ctx->r4 = ctx->r4 | 0XB03;
    // 0x8001D2E4: jal         0x8001E8F0
    // 0x8001D2E8: lb          $a1, 0x23($sp)
    ctx->r5 = MEM_B(ctx->r29, 0X23);
    AudioThread_QueueCmdS8(rdram, ctx);
        goto after_8;
    // 0x8001D2E8: lb          $a1, 0x23($sp)
    ctx->r5 = MEM_B(ctx->r29, 0X23);
    after_8:
    // 0x8001D2EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001D2F0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8001D2F4: jr          $ra
    // 0x8001D2F8: nop

    return;
    // 0x8001D2F8: nop

;}
RECOMP_FUNC void Player_Collide(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A8804: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A8808: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A880C: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x800A8810: lw          $t6, 0x498($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X498);
    // 0x800A8814: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800A8818: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x800A881C: bnel        $t6, $zero, L_800A8870
    if (ctx->r14 != 0) {
        // 0x800A8820: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800A8870;
    }
    goto skip_0;
    // 0x800A8820: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800A8824: lw          $t7, 0x1CC($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1CC);
    // 0x800A8828: lw          $t9, 0x1CC($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X1CC);
    // 0x800A882C: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    // 0x800A8830: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x800A8834: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800A8838: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x800A883C: addu        $a2, $a2, $t1
    ctx->r6 = ADD32(ctx->r6, ctx->r9);
    // 0x800A8840: lw          $a2, 0x3000($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X3000);
    // 0x800A8844: jal         0x800A6CD0
    // 0x800A8848: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    Player_ApplyDamage(rdram, ctx);
        goto after_0;
    // 0x800A8848: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800A884C: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x800A8850: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800A8854: lw          $t2, 0x1C4($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X1C4);
    // 0x800A8858: lw          $t4, 0x1C4($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X1C4);
    // 0x800A885C: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x800A8860: sw          $t3, 0x288($a0)
    MEM_W(0X288, ctx->r4) = ctx->r11;
    // 0x800A8864: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x800A8868: sw          $t5, 0x288($a3)
    MEM_W(0X288, ctx->r7) = ctx->r13;
    // 0x800A886C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A8870:
    // 0x800A8870: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A8874: jr          $ra
    // 0x800A8878: nop

    return;
    // 0x800A8878: nop

;}
RECOMP_FUNC void ItemBomb_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005CB44: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005CB48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005CB4C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8005CB50: lw          $t6, -0x7DCC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7DCC);
    // 0x8005CB54: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x8005CB58: bne         $t6, $at, L_8005CB98
    if (ctx->r14 != ctx->r1) {
        // 0x8005CB5C: nop
    
            goto L_8005CB98;
    }
    // 0x8005CB5C: nop

    // 0x8005CB60: jal         0x8005980C
    // 0x8005CB64: lwc1        $f12, 0x68($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X68);
    Graphics_SetScaleMtx(rdram, ctx);
        goto after_0;
    // 0x8005CB64: lwc1        $f12, 0x68($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X68);
    after_0:
    // 0x8005CB68: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8005CB6C: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8005CB70: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8005CB74: lui         $t9, 0x300
    ctx->r25 = S32(0X300 << 16);
    // 0x8005CB78: addiu       $t9, $t9, 0x5980
    ctx->r25 = ADD32(ctx->r25, 0X5980);
    // 0x8005CB7C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8005CB80: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8005CB84: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x8005CB88: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8005CB8C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8005CB90: b           L_8005CC90
    // 0x8005CB94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8005CC90;
    // 0x8005CB94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8005CB98:
    // 0x8005CB98: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005CB9C: lwc1        $f6, 0x62A4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X62A4);
    // 0x8005CBA0: lwc1        $f4, 0x68($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X68);
    // 0x8005CBA4: mul.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8005CBA8: jal         0x8005980C
    // 0x8005CBAC: nop

    Graphics_SetScaleMtx(rdram, ctx);
        goto after_1;
    // 0x8005CBAC: nop

    after_1:
    // 0x8005CBB0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8005CBB4: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8005CBB8: jal         0x800B8DD0
    // 0x8005CBBC: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    RCP_SetupDL(rdram, ctx);
        goto after_2;
    // 0x8005CBBC: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    after_2:
    // 0x8005CBC0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8005CBC4: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8005CBC8: lui         $t1, 0x4
    ctx->r9 = S32(0X4 << 16);
    // 0x8005CBCC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8005CBD0: lui         $t3, 0xBB00
    ctx->r11 = S32(0XBB00 << 16);
    // 0x8005CBD4: lui         $t4, 0x7D0
    ctx->r12 = S32(0X7D0 << 16);
    // 0x8005CBD8: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x8005CBDC: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x8005CBE0: ori         $t4, $t4, 0x7D0
    ctx->r12 = ctx->r12 | 0X7D0;
    // 0x8005CBE4: ori         $t3, $t3, 0x1
    ctx->r11 = ctx->r11 | 0X1;
    // 0x8005CBE8: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8005CBEC: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x8005CBF0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8005CBF4: lui         $t6, 0xB700
    ctx->r14 = S32(0XB700 << 16);
    // 0x8005CBF8: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x8005CBFC: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x8005CC00: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x8005CC04: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x8005CC08: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8005CC0C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8005CC10: lui         $t9, 0x102
    ctx->r25 = S32(0X102 << 16);
    // 0x8005CC14: addiu       $t9, $t9, 0x31A0
    ctx->r25 = ADD32(ctx->r25, 0X31A0);
    // 0x8005CC18: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8005CC1C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8005CC20: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8005CC24: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8005CC28: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8005CC2C: lui         $t3, 0xB600
    ctx->r11 = S32(0XB600 << 16);
    // 0x8005CC30: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x8005CC34: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x8005CC38: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x8005CC3C: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8005CC40: jal         0x800B8DD0
    // 0x8005CC44: addiu       $a1, $zero, 0x1B
    ctx->r5 = ADD32(0, 0X1B);
    RCP_SetupDL(rdram, ctx);
        goto after_3;
    // 0x8005CC44: addiu       $a1, $zero, 0x1B
    ctx->r5 = ADD32(0, 0X1B);
    after_3:
    // 0x8005CC48: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8005CC4C: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8005CC50: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8005CC54: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x8005CC58: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8005CC5C: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x8005CC60: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x8005CC64: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8005CC68: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8005CC6C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8005CC70: lui         $t9, 0x102
    ctx->r25 = S32(0X102 << 16);
    // 0x8005CC74: addiu       $t9, $t9, 0x2E80
    ctx->r25 = ADD32(ctx->r25, 0X2E80);
    // 0x8005CC78: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8005CC7C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8005CC80: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x8005CC84: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8005CC88: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8005CC8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8005CC90:
    // 0x8005CC90: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005CC94: jr          $ra
    // 0x8005CC98: nop

    return;
    // 0x8005CC98: nop

;}
RECOMP_FUNC void HUD_VS_DrawHUD(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008DC34: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008DC38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008DC3C: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x8008DC40: lw          $t6, 0x7E7C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7E7C);
    // 0x8008DC44: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8008DC48: beq         $t6, $zero, L_8008DC88
    if (ctx->r14 == 0) {
        // 0x8008DC4C: nop
    
            goto L_8008DC88;
    }
    // 0x8008DC4C: nop

    // 0x8008DC50: lw          $t7, -0x78B0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X78B0);
    // 0x8008DC54: bne         $t7, $zero, L_8008DC88
    if (ctx->r15 != 0) {
        // 0x8008DC58: nop
    
            goto L_8008DC88;
    }
    // 0x8008DC58: nop

    // 0x8008DC5C: jal         0x8008D250
    // 0x8008DC60: nop

    HUD_VsModePortrait_Draw(rdram, ctx);
        goto after_0;
    // 0x8008DC60: nop

    after_0:
    // 0x8008DC64: jal         0x8008D7F4
    // 0x8008DC68: nop

    HUD_VS_PlayerNumber_Draw(rdram, ctx);
        goto after_1;
    // 0x8008DC68: nop

    after_1:
    // 0x8008DC6C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8008DC70: jal         0x8008D4F0
    // 0x8008DC74: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    HUD_BoostGauge_Draw(rdram, ctx);
        goto after_2;
    // 0x8008DC74: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    after_2:
    // 0x8008DC78: jal         0x8008D31C
    // 0x8008DC7C: nop

    HUD_VS_ShieldGauge_Draw(rdram, ctx);
        goto after_3;
    // 0x8008DC7C: nop

    after_3:
    // 0x8008DC80: jal         0x8008D984
    // 0x8008DC84: nop

    HUD_VS_BombCount_Draw(rdram, ctx);
        goto after_4;
    // 0x8008DC84: nop

    after_4:
L_8008DC88:
    // 0x8008DC88: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8008DC8C: lw          $t8, -0x78B0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X78B0);
    // 0x8008DC90: bnel        $t8, $zero, L_8008DCA4
    if (ctx->r24 != 0) {
        // 0x8008DC94: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8008DCA4;
    }
    goto skip_0;
    // 0x8008DC94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8008DC98: jal         0x8008CBE4
    // 0x8008DC9C: nop

    HUD_KillCountStars_Update(rdram, ctx);
        goto after_5;
    // 0x8008DC9C: nop

    after_5:
    // 0x8008DCA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008DCA4:
    // 0x8008DCA4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008DCA8: jr          $ra
    // 0x8008DCAC: nop

    return;
    // 0x8008DCAC: nop

;}
RECOMP_FUNC void ActorAllRange_UpdateStarWolfEvents(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002F69C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8002F6A0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8002F6A4: lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // 0x8002F6A8: addiu       $v1, $v1, -0x6FC
    ctx->r3 = ADD32(ctx->r3, -0X6FC);
    // 0x8002F6AC: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8002F6B0: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8002F6B4: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x8002F6B8: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x8002F6BC: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x8002F6C0: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8002F6C4: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8002F6C8: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8002F6CC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8002F6D0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002F6D4: beq         $v0, $zero, L_8002F730
    if (ctx->r2 == 0) {
        // 0x8002F6D8: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_8002F730;
    }
    // 0x8002F6D8: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x8002F6DC: bne         $t6, $zero, L_8002F730
    if (ctx->r14 != 0) {
        // 0x8002F6E0: sw          $t6, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r14;
            goto L_8002F730;
    }
    // 0x8002F6E0: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8002F6E4: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8002F6E8: lw          $t8, -0x7DCC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7DCC);
    // 0x8002F6EC: addiu       $s2, $zero, 0x11
    ctx->r18 = ADD32(0, 0X11);
    // 0x8002F6F0: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8002F6F4: beq         $s2, $t8, L_8002F730
    if (ctx->r18 == ctx->r24) {
        // 0x8002F6F8: addiu       $v0, $v0, 0x7CD0
        ctx->r2 = ADD32(ctx->r2, 0X7CD0);
            goto L_8002F730;
    }
    // 0x8002F6F8: addiu       $v0, $v0, 0x7CD0
    ctx->r2 = ADD32(ctx->r2, 0X7CD0);
    // 0x8002F6FC: lw          $t9, 0xC($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XC);
    // 0x8002F700: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x8002F704: lw          $t2, 0x4($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X4);
    // 0x8002F708: lw          $t4, 0x8($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X8);
    // 0x8002F70C: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8002F710: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x8002F714: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
    // 0x8002F718: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x8002F71C: bne         $s7, $t5, L_8002F730
    if (ctx->r23 != ctx->r13) {
        // 0x8002F720: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_8002F730;
    }
    // 0x8002F720: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8002F724: addiu       $a0, $a0, 0x32AC
    ctx->r4 = ADD32(ctx->r4, 0X32AC);
    // 0x8002F728: jal         0x800BA808
    // 0x8002F72C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    Radio_PlayMessage(rdram, ctx);
        goto after_0;
    // 0x8002F72C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
L_8002F730:
    // 0x8002F730: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8002F734: lw          $v0, -0x6D8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6D8);
    // 0x8002F738: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8002F73C: lw          $v1, -0x64B4($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X64B4);
    // 0x8002F740: addiu       $t6, $v0, 0x64
    ctx->r14 = ADD32(ctx->r2, 0X64);
    // 0x8002F744: addiu       $s2, $zero, 0x11
    ctx->r18 = ADD32(0, 0X11);
    // 0x8002F748: bne         $t6, $v1, L_8002F78C
    if (ctx->r14 != ctx->r3) {
        // 0x8002F74C: addiu       $s7, $zero, 0x1
        ctx->r23 = ADD32(0, 0X1);
            goto L_8002F78C;
    }
    // 0x8002F74C: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
    // 0x8002F750: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8002F754: lw          $t7, -0x7DCC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7DCC);
    // 0x8002F758: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x8002F75C: lui         $a0, 0x101E
    ctx->r4 = S32(0X101E << 16);
    // 0x8002F760: beq         $t7, $at, L_8002F78C
    if (ctx->r15 == ctx->r1) {
        // 0x8002F764: nop
    
            goto L_8002F78C;
    }
    // 0x8002F764: nop

    // 0x8002F768: jal         0x800182F4
    // 0x8002F76C: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_1;
    // 0x8002F76C: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    after_1:
    // 0x8002F770: lui         $a0, 0x111E
    ctx->r4 = S32(0X111E << 16);
    // 0x8002F774: jal         0x800182F4
    // 0x8002F778: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_2;
    // 0x8002F778: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    after_2:
    // 0x8002F77C: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8002F780: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8002F784: lw          $v1, -0x64B4($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X64B4);
    // 0x8002F788: lw          $v0, -0x6D8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6D8);
L_8002F78C:
    // 0x8002F78C: bne         $v1, $v0, L_8002F890
    if (ctx->r3 != ctx->r2) {
        // 0x8002F790: nop
    
            goto L_8002F890;
    }
    // 0x8002F790: nop

    // 0x8002F794: jal         0x8002F3E0
    // 0x8002F798: nop

    ActorAllRange_SpawnStarWolf(rdram, ctx);
        goto after_3;
    // 0x8002F798: nop

    after_3:
    // 0x8002F79C: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x8002F7A0: addiu       $s5, $zero, 0x3
    ctx->r21 = ADD32(0, 0X3);
    // 0x8002F7A4: addiu       $s0, $s0, -0x7D80
    ctx->r16 = ADD32(ctx->r16, -0X7D80);
    // 0x8002F7A8: sh          $s5, 0xB8($s1)
    MEM_H(0XB8, ctx->r17) = ctx->r21;
    // 0x8002F7AC: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x8002F7B0: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8002F7B4: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x8002F7B8: sw          $zero, 0x1C8($t8)
    MEM_W(0X1C8, ctx->r24) = 0;
    // 0x8002F7BC: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
    // 0x8002F7C0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002F7C4: ori         $a1, $zero, 0x802B
    ctx->r5 = 0 | 0X802B;
    // 0x8002F7C8: beq         $v0, $at, L_8002F7D4
    if (ctx->r2 == ctx->r1) {
        // 0x8002F7CC: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_8002F7D4;
    }
    // 0x8002F7CC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8002F7D0: bne         $s2, $v0, L_8002F7E4
    if (ctx->r18 != ctx->r2) {
        // 0x8002F7D4: lui         $at, 0x41A0
        ctx->r1 = S32(0X41A0 << 16);
            goto L_8002F7E4;
    }
L_8002F7D4:
    // 0x8002F7D4: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8002F7D8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8002F7DC: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x8002F7E0: swc1        $f4, 0x34($t9)
    MEM_W(0X34, ctx->r25) = ctx->f4.u32l;
L_8002F7E4:
    // 0x8002F7E4: jal         0x8001D444
    // 0x8002F7E8: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    Audio_PlaySequence(rdram, ctx);
        goto after_4;
    // 0x8002F7E8: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_4:
    // 0x8002F7EC: jal         0x8002EE34
    // 0x8002F7F0: nop

    AllRange_ClearRadio(rdram, ctx);
        goto after_5;
    // 0x8002F7F0: nop

    after_5:
    // 0x8002F7F4: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8002F7F8: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
    // 0x8002F7FC: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x8002F800: beq         $v0, $at, L_8002F80C
    if (ctx->r2 == ctx->r1) {
        // 0x8002F804: addiu       $at, $zero, 0x13
        ctx->r1 = ADD32(0, 0X13);
            goto L_8002F80C;
    }
    // 0x8002F804: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x8002F808: bne         $v0, $at, L_8002F820
    if (ctx->r2 != ctx->r1) {
        // 0x8002F80C: lui         $at, 0x800D
        ctx->r1 = S32(0X800D << 16);
            goto L_8002F820;
    }
L_8002F80C:
    // 0x8002F80C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002F810: lwc1        $f6, 0x4E94($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X4E94);
    // 0x8002F814: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x8002F818: b           L_8002F834
    // 0x8002F81C: swc1        $f6, 0x40($t0)
    MEM_W(0X40, ctx->r8) = ctx->f6.u32l;
        goto L_8002F834;
    // 0x8002F81C: swc1        $f6, 0x40($t0)
    MEM_W(0X40, ctx->r8) = ctx->f6.u32l;
L_8002F820:
    // 0x8002F820: bne         $s2, $v0, L_8002F834
    if (ctx->r18 != ctx->r2) {
        // 0x8002F824: lui         $at, 0x800D
        ctx->r1 = S32(0X800D << 16);
            goto L_8002F834;
    }
    // 0x8002F824: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002F828: lwc1        $f8, 0x4E98($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X4E98);
    // 0x8002F82C: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x8002F830: swc1        $f8, 0x40($t1)
    MEM_W(0X40, ctx->r9) = ctx->f8.u32l;
L_8002F834:
    // 0x8002F834: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002F838: lwc1        $f10, 0x4E9C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X4E9C);
    // 0x8002F83C: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x8002F840: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002F844: lui         $s3, 0x8016
    ctx->r19 = S32(0X8016 << 16);
    // 0x8002F848: swc1        $f10, 0x44($t2)
    MEM_W(0X44, ctx->r10) = ctx->f10.u32l;
    // 0x8002F84C: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x8002F850: lwc1        $f16, 0x4EA0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X4EA0);
    // 0x8002F854: addiu       $s3, $s3, 0x3FE0
    ctx->r19 = ADD32(ctx->r19, 0X3FE0);
    // 0x8002F858: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8002F85C: swc1        $f16, 0x48($t3)
    MEM_W(0X48, ctx->r11) = ctx->f16.u32l;
    // 0x8002F860: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x8002F864: lwc1        $f18, 0xBD4($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0XBD4);
    // 0x8002F868: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8002F86C: swc1        $f18, 0x4C($t4)
    MEM_W(0X4C, ctx->r12) = ctx->f18.u32l;
    // 0x8002F870: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x8002F874: lwc1        $f4, 0xBD8($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0XBD8);
    // 0x8002F878: swc1        $f4, 0x50($t5)
    MEM_W(0X50, ctx->r13) = ctx->f4.u32l;
    // 0x8002F87C: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x8002F880: lwc1        $f6, 0xBDC($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0XBDC);
    // 0x8002F884: swc1        $f6, 0x54($t6)
    MEM_W(0X54, ctx->r14) = ctx->f6.u32l;
    // 0x8002F888: lw          $v1, -0x64B4($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X64B4);
    // 0x8002F88C: lw          $v0, -0x6D8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6D8);
L_8002F890:
    // 0x8002F890: lui         $s3, 0x8016
    ctx->r19 = S32(0X8016 << 16);
    // 0x8002F894: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8002F898: addiu       $s3, $s3, 0x3FE0
    ctx->r19 = ADD32(ctx->r19, 0X3FE0);
    // 0x8002F89C: beq         $at, $zero, L_8002FB20
    if (ctx->r1 == 0) {
        // 0x8002F8A0: addiu       $s5, $zero, 0x3
        ctx->r21 = ADD32(0, 0X3);
            goto L_8002FB20;
    }
    // 0x8002F8A0: addiu       $s5, $zero, 0x3
    ctx->r21 = ADD32(0, 0X3);
    // 0x8002F8A4: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x8002F8A8: lh          $t7, -0x6F8($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X6F8);
    // 0x8002F8AC: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8002F8B0: addiu       $v0, $v0, -0x6C0
    ctx->r2 = ADD32(ctx->r2, -0X6C0);
    // 0x8002F8B4: bne         $t7, $zero, L_8002FB20
    if (ctx->r15 != 0) {
        // 0x8002F8B8: or          $s4, $s7, $zero
        ctx->r20 = ctx->r23 | 0;
            goto L_8002FB20;
    }
    // 0x8002F8B8: or          $s4, $s7, $zero
    ctx->r20 = ctx->r23 | 0;
    // 0x8002F8BC: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8002F8C0: lui         $s0, 0x8016
    ctx->r16 = S32(0X8016 << 16);
    // 0x8002F8C4: lui         $s6, 0x800D
    ctx->r22 = S32(0X800D << 16);
    // 0x8002F8C8: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8002F8CC: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8002F8D0: addiu       $s6, $s6, -0x5DCC
    ctx->r22 = ADD32(ctx->r22, -0X5DCC);
    // 0x8002F8D4: addiu       $s0, $s0, 0x42D4
    ctx->r16 = ADD32(ctx->r16, 0X42D4);
    // 0x8002F8D8: addiu       $s2, $zero, 0x2F4
    ctx->r18 = ADD32(0, 0X2F4);
    // 0x8002F8DC: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_8002F8E0:
    // 0x8002F8E0: lbu         $t0, 0x0($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X0);
    // 0x8002F8E4: bnel        $s1, $t0, L_8002FADC
    if (ctx->r17 != ctx->r8) {
        // 0x8002F8E8: addiu       $s4, $s4, 0x1
        ctx->r20 = ADD32(ctx->r20, 0X1);
            goto L_8002FADC;
    }
    goto skip_0;
    // 0x8002F8E8: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    skip_0:
    // 0x8002F8EC: lh          $t1, 0xB8($s0)
    ctx->r9 = MEM_H(ctx->r16, 0XB8);
    // 0x8002F8F0: bnel        $s1, $t1, L_8002FADC
    if (ctx->r17 != ctx->r9) {
        // 0x8002F8F4: addiu       $s4, $s4, 0x1
        ctx->r20 = ADD32(ctx->r20, 0X1);
            goto L_8002FADC;
    }
    goto skip_1;
    // 0x8002F8F4: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    skip_1:
    // 0x8002F8F8: lh          $t2, 0xCE($s0)
    ctx->r10 = MEM_H(ctx->r16, 0XCE);
    // 0x8002F8FC: slti        $at, $t2, 0x46
    ctx->r1 = SIGNED(ctx->r10) < 0X46 ? 1 : 0;
    // 0x8002F900: beql        $at, $zero, L_8002FADC
    if (ctx->r1 == 0) {
        // 0x8002F904: addiu       $s4, $s4, 0x1
        ctx->r20 = ADD32(ctx->r20, 0X1);
            goto L_8002FADC;
    }
    goto skip_2;
    // 0x8002F904: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    skip_2:
    // 0x8002F908: lhu         $t3, 0xC6($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0XC6);
    // 0x8002F90C: beql        $t3, $zero, L_8002FADC
    if (ctx->r11 == 0) {
        // 0x8002F910: addiu       $s4, $s4, 0x1
        ctx->r20 = ADD32(ctx->r20, 0X1);
            goto L_8002FADC;
    }
    goto skip_3;
    // 0x8002F910: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    skip_3:
    // 0x8002F914: lh          $t4, 0xD4($s0)
    ctx->r12 = MEM_H(ctx->r16, 0XD4);
    // 0x8002F918: bnel        $s7, $t4, L_8002FADC
    if (ctx->r23 != ctx->r12) {
        // 0x8002F91C: addiu       $s4, $s4, 0x1
        ctx->r20 = ADD32(ctx->r20, 0X1);
            goto L_8002FADC;
    }
    goto skip_4;
    // 0x8002F91C: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    skip_4:
    // 0x8002F920: lh          $t5, 0xE6($s0)
    ctx->r13 = MEM_H(ctx->r16, 0XE6);
    // 0x8002F924: multu       $t5, $s2
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002F928: mflo        $t6
    ctx->r14 = lo;
    // 0x8002F92C: addu        $v0, $s3, $t6
    ctx->r2 = ADD32(ctx->r19, ctx->r14);
    // 0x8002F930: lh          $t7, 0xB8($v0)
    ctx->r15 = MEM_H(ctx->r2, 0XB8);
    // 0x8002F934: bnel        $s5, $t7, L_8002FAA0
    if (ctx->r21 != ctx->r15) {
        // 0x8002F938: lh          $t9, 0xE4($s0)
        ctx->r25 = MEM_H(ctx->r16, 0XE4);
            goto L_8002FAA0;
    }
    goto skip_5;
    // 0x8002F938: lh          $t9, 0xE4($s0)
    ctx->r25 = MEM_H(ctx->r16, 0XE4);
    skip_5:
    // 0x8002F93C: lh          $t8, 0xE4($v0)
    ctx->r24 = MEM_H(ctx->r2, 0XE4);
    // 0x8002F940: slti        $at, $t8, 0x8
    ctx->r1 = SIGNED(ctx->r24) < 0X8 ? 1 : 0;
    // 0x8002F944: beql        $at, $zero, L_8002FAA0
    if (ctx->r1 == 0) {
        // 0x8002F948: lh          $t9, 0xE4($s0)
        ctx->r25 = MEM_H(ctx->r16, 0XE4);
            goto L_8002FAA0;
    }
    goto skip_6;
    // 0x8002F948: lh          $t9, 0xE4($s0)
    ctx->r25 = MEM_H(ctx->r16, 0XE4);
    skip_6:
    // 0x8002F94C: sw          $zero, 0x58($v0)
    MEM_W(0X58, ctx->r2) = 0;
    // 0x8002F950: lh          $t9, 0xE6($s0)
    ctx->r25 = MEM_H(ctx->r16, 0XE6);
    // 0x8002F954: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002F958: multu       $t9, $s2
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002F95C: mflo        $t0
    ctx->r8 = lo;
    // 0x8002F960: addu        $t1, $s3, $t0
    ctx->r9 = ADD32(ctx->r19, ctx->r8);
    // 0x8002F964: sh          $s1, 0xB8($t1)
    MEM_H(0XB8, ctx->r9) = ctx->r17;
    // 0x8002F968: lh          $t3, 0xE6($s0)
    ctx->r11 = MEM_H(ctx->r16, 0XE6);
    // 0x8002F96C: lh          $t2, 0xE4($s0)
    ctx->r10 = MEM_H(ctx->r16, 0XE4);
    // 0x8002F970: multu       $t3, $s2
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002F974: mflo        $t4
    ctx->r12 = lo;
    // 0x8002F978: addu        $t5, $s3, $t4
    ctx->r13 = ADD32(ctx->r19, ctx->r12);
    // 0x8002F97C: sh          $t2, 0xE6($t5)
    MEM_H(0XE6, ctx->r13) = ctx->r10;
    // 0x8002F980: lh          $t6, 0xE6($s0)
    ctx->r14 = MEM_H(ctx->r16, 0XE6);
    // 0x8002F984: lw          $t8, 0x0($s6)
    ctx->r24 = MEM_W(ctx->r22, 0X0);
    // 0x8002F988: multu       $t6, $s2
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002F98C: mflo        $t7
    ctx->r15 = lo;
    // 0x8002F990: addu        $v0, $s3, $t7
    ctx->r2 = ADD32(ctx->r19, ctx->r15);
    // 0x8002F994: bnel        $t8, $v0, L_8002F9CC
    if (ctx->r24 != ctx->r2) {
        // 0x8002F998: lw          $t1, 0x5C($v0)
        ctx->r9 = MEM_W(ctx->r2, 0X5C);
            goto L_8002F9CC;
    }
    goto skip_7;
    // 0x8002F998: lw          $t1, 0x5C($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X5C);
    skip_7:
    // 0x8002F99C: sw          $zero, 0x0($s6)
    MEM_W(0X0, ctx->r22) = 0;
    // 0x8002F9A0: sw          $zero, -0x5DC8($at)
    MEM_W(-0X5DC8, ctx->r1) = 0;
    // 0x8002F9A4: lh          $t9, 0xE6($s0)
    ctx->r25 = MEM_H(ctx->r16, 0XE6);
    // 0x8002F9A8: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8002F9AC: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x8002F9B0: sll         $t0, $t0, 4
    ctx->r8 = S32(ctx->r8 << 4);
    // 0x8002F9B4: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x8002F9B8: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8002F9BC: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8002F9C0: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8002F9C4: addu        $v0, $s3, $t0
    ctx->r2 = ADD32(ctx->r19, ctx->r8);
    // 0x8002F9C8: lw          $t1, 0x5C($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X5C);
L_8002F9CC:
    // 0x8002F9CC: bnel        $t1, $zero, L_8002FAA0
    if (ctx->r9 != 0) {
        // 0x8002F9D0: lh          $t9, 0xE4($s0)
        ctx->r25 = MEM_H(ctx->r16, 0XE4);
            goto L_8002FAA0;
    }
    goto skip_8;
    // 0x8002F9D0: lh          $t9, 0xE4($s0)
    ctx->r25 = MEM_H(ctx->r16, 0XE4);
    skip_8:
    // 0x8002F9D4: lh          $v1, 0xE4($v0)
    ctx->r3 = MEM_H(ctx->r2, 0XE4);
    // 0x8002F9D8: beq         $v1, $s7, L_8002F9F8
    if (ctx->r3 == ctx->r23) {
        // 0x8002F9DC: nop
    
            goto L_8002F9F8;
    }
    // 0x8002F9DC: nop

    // 0x8002F9E0: beq         $v1, $s1, L_8002FA30
    if (ctx->r3 == ctx->r17) {
        // 0x8002F9E4: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_8002FA30;
    }
    // 0x8002F9E4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8002F9E8: beq         $v1, $s5, L_8002FA64
    if (ctx->r3 == ctx->r21) {
        // 0x8002F9EC: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_8002FA64;
    }
    // 0x8002F9EC: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8002F9F0: b           L_8002FA98
    // 0x8002F9F4: addiu       $t8, $zero, 0xC8
    ctx->r24 = ADD32(0, 0XC8);
        goto L_8002FA98;
    // 0x8002F9F4: addiu       $t8, $zero, 0xC8
    ctx->r24 = ADD32(0, 0XC8);
L_8002F9F8:
    // 0x8002F9F8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8002F9FC: addiu       $a0, $a0, -0x14BC
    ctx->r4 = ADD32(ctx->r4, -0X14BC);
    // 0x8002FA00: jal         0x8002F5F4
    // 0x8002FA04: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    ActorAllRange_PlayMessage(rdram, ctx);
        goto after_6;
    // 0x8002FA04: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_6:
    // 0x8002FA08: lh          $t3, 0xE6($s0)
    ctx->r11 = MEM_H(ctx->r16, 0XE6);
    // 0x8002FA0C: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8002FA10: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x8002FA14: sll         $t4, $t4, 4
    ctx->r12 = S32(ctx->r12 << 4);
    // 0x8002FA18: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x8002FA1C: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8002FA20: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8002FA24: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8002FA28: b           L_8002FA94
    // 0x8002FA2C: addu        $v0, $s3, $t4
    ctx->r2 = ADD32(ctx->r19, ctx->r12);
        goto L_8002FA94;
    // 0x8002FA2C: addu        $v0, $s3, $t4
    ctx->r2 = ADD32(ctx->r19, ctx->r12);
L_8002FA30:
    // 0x8002FA30: addiu       $a0, $a0, -0x1464
    ctx->r4 = ADD32(ctx->r4, -0X1464);
    // 0x8002FA34: jal         0x8002F5F4
    // 0x8002FA38: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    ActorAllRange_PlayMessage(rdram, ctx);
        goto after_7;
    // 0x8002FA38: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_7:
    // 0x8002FA3C: lh          $t2, 0xE6($s0)
    ctx->r10 = MEM_H(ctx->r16, 0XE6);
    // 0x8002FA40: sll         $t5, $t2, 2
    ctx->r13 = S32(ctx->r10 << 2);
    // 0x8002FA44: subu        $t5, $t5, $t2
    ctx->r13 = SUB32(ctx->r13, ctx->r10);
    // 0x8002FA48: sll         $t5, $t5, 4
    ctx->r13 = S32(ctx->r13 << 4);
    // 0x8002FA4C: subu        $t5, $t5, $t2
    ctx->r13 = SUB32(ctx->r13, ctx->r10);
    // 0x8002FA50: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8002FA54: addu        $t5, $t5, $t2
    ctx->r13 = ADD32(ctx->r13, ctx->r10);
    // 0x8002FA58: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8002FA5C: b           L_8002FA94
    // 0x8002FA60: addu        $v0, $s3, $t5
    ctx->r2 = ADD32(ctx->r19, ctx->r13);
        goto L_8002FA94;
    // 0x8002FA60: addu        $v0, $s3, $t5
    ctx->r2 = ADD32(ctx->r19, ctx->r13);
L_8002FA64:
    // 0x8002FA64: addiu       $a0, $a0, -0x142C
    ctx->r4 = ADD32(ctx->r4, -0X142C);
    // 0x8002FA68: jal         0x8002F5F4
    // 0x8002FA6C: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    ActorAllRange_PlayMessage(rdram, ctx);
        goto after_8;
    // 0x8002FA6C: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_8:
    // 0x8002FA70: lh          $t6, 0xE6($s0)
    ctx->r14 = MEM_H(ctx->r16, 0XE6);
    // 0x8002FA74: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8002FA78: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8002FA7C: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x8002FA80: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8002FA84: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8002FA88: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8002FA8C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8002FA90: addu        $v0, $s3, $t7
    ctx->r2 = ADD32(ctx->r19, ctx->r15);
L_8002FA94:
    // 0x8002FA94: addiu       $t8, $zero, 0xC8
    ctx->r24 = ADD32(0, 0XC8);
L_8002FA98:
    // 0x8002FA98: sw          $t8, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->r24;
    // 0x8002FA9C: lh          $t9, 0xE4($s0)
    ctx->r25 = MEM_H(ctx->r16, 0XE4);
L_8002FAA0:
    // 0x8002FAA0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8002FAA4: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8002FAA8: bne         $t9, $at, L_8002FAD0
    if (ctx->r25 != ctx->r1) {
        // 0x8002FAAC: addiu       $t3, $zero, -0x1
        ctx->r11 = ADD32(0, -0X1);
            goto L_8002FAD0;
    }
    // 0x8002FAAC: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x8002FAB0: lw          $t0, -0x7DCC($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7DCC);
    // 0x8002FAB4: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x8002FAB8: addiu       $t1, $zero, 0x12C
    ctx->r9 = ADD32(0, 0X12C);
    // 0x8002FABC: beql        $t0, $at, L_8002FADC
    if (ctx->r8 == ctx->r1) {
        // 0x8002FAC0: addiu       $s4, $s4, 0x1
        ctx->r20 = ADD32(ctx->r20, 0X1);
            goto L_8002FADC;
    }
    goto skip_9;
    // 0x8002FAC0: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    skip_9:
    // 0x8002FAC4: sh          $s5, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r21;
    // 0x8002FAC8: b           L_8002FAD8
    // 0x8002FACC: sh          $t1, 0x4E($s0)
    MEM_H(0X4E, ctx->r16) = ctx->r9;
        goto L_8002FAD8;
    // 0x8002FACC: sh          $t1, 0x4E($s0)
    MEM_H(0X4E, ctx->r16) = ctx->r9;
L_8002FAD0:
    // 0x8002FAD0: sh          $s5, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r21;
    // 0x8002FAD4: sh          $t3, 0xE6($s0)
    MEM_H(0XE6, ctx->r16) = ctx->r11;
L_8002FAD8:
    // 0x8002FAD8: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
L_8002FADC:
    // 0x8002FADC: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8002FAE0: bne         $s4, $at, L_8002F8E0
    if (ctx->r20 != ctx->r1) {
        // 0x8002FAE4: addiu       $s0, $s0, 0x2F4
        ctx->r16 = ADD32(ctx->r16, 0X2F4);
            goto L_8002F8E0;
    }
    // 0x8002FAE4: addiu       $s0, $s0, 0x2F4
    ctx->r16 = ADD32(ctx->r16, 0X2F4);
    // 0x8002FAE8: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8002FAEC: addiu       $v0, $v0, 0x78B0
    ctx->r2 = ADD32(ctx->r2, 0X78B0);
    // 0x8002FAF0: lw          $t4, 0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X4);
    // 0x8002FAF4: bgtzl       $t4, L_8002FB04
    if (SIGNED(ctx->r12) > 0) {
        // 0x8002FAF8: lw          $t2, 0x8($v0)
        ctx->r10 = MEM_W(ctx->r2, 0X8);
            goto L_8002FB04;
    }
    goto skip_10;
    // 0x8002FAF8: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    skip_10:
    // 0x8002FAFC: sh          $zero, 0xFAA($s3)
    MEM_H(0XFAA, ctx->r19) = 0;
    // 0x8002FB00: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
L_8002FB04:
    // 0x8002FB04: bgtzl       $t2, L_8002FB14
    if (SIGNED(ctx->r10) > 0) {
        // 0x8002FB08: lw          $t5, 0xC($v0)
        ctx->r13 = MEM_W(ctx->r2, 0XC);
            goto L_8002FB14;
    }
    goto skip_11;
    // 0x8002FB08: lw          $t5, 0xC($v0)
    ctx->r13 = MEM_W(ctx->r2, 0XC);
    skip_11:
    // 0x8002FB0C: sh          $zero, 0x1592($s3)
    MEM_H(0X1592, ctx->r19) = 0;
    // 0x8002FB10: lw          $t5, 0xC($v0)
    ctx->r13 = MEM_W(ctx->r2, 0XC);
L_8002FB14:
    // 0x8002FB14: bgtzl       $t5, L_8002FB24
    if (SIGNED(ctx->r13) > 0) {
        // 0x8002FB18: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_8002FB24;
    }
    goto skip_12;
    // 0x8002FB18: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_12:
    // 0x8002FB1C: sh          $zero, 0x129E($s3)
    MEM_H(0X129E, ctx->r19) = 0;
L_8002FB20:
    // 0x8002FB20: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_8002FB24:
    // 0x8002FB24: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8002FB28: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8002FB2C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8002FB30: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8002FB34: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x8002FB38: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x8002FB3C: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x8002FB40: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x8002FB44: jr          $ra
    // 0x8002FB48: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8002FB48: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_tank_80046E40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80046E40: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x80046E44: sdc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X48, ctx->r29);
    // 0x80046E48: sw          $s2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r18;
    // 0x80046E4C: sw          $s0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r16;
    // 0x80046E50: mtc1        $a3, $f30
    ctx->f30.u32l = ctx->r7;
    // 0x80046E54: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80046E58: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x80046E5C: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x80046E60: sw          $s5, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r21;
    // 0x80046E64: sw          $s4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r20;
    // 0x80046E68: sw          $s3, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r19;
    // 0x80046E6C: sw          $s1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r17;
    // 0x80046E70: sdc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X40, ctx->r29);
    // 0x80046E74: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x80046E78: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x80046E7C: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x80046E80: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80046E84: sw          $a2, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r6;
    // 0x80046E88: lwc1        $f4, 0x0($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X0);
    // 0x80046E8C: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80046E90: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80046E94: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x80046E98: nop

    // 0x80046E9C: beq         $t7, $zero, L_800474C4
    if (ctx->r15 == 0) {
        // 0x80046EA0: sw          $t7, 0xB4($sp)
        MEM_W(0XB4, ctx->r29) = ctx->r15;
            goto L_800474C4;
    }
    // 0x80046EA0: sw          $t7, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r15;
    // 0x80046EA4: blez        $t7, L_800474C4
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80046EA8: or          $s5, $zero, $zero
        ctx->r21 = 0 | 0;
            goto L_800474C4;
    }
    // 0x80046EA8: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x80046EAC: lwc1        $f8, 0xD8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x80046EB0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80046EB4: lwc1        $f16, 0x56F0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X56F0);
    // 0x80046EB8: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x80046EBC: lwc1        $f4, 0xD0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XD0);
    // 0x80046EC0: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80046EC4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80046EC8: lwc1        $f8, 0x56F4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X56F4);
    // 0x80046ECC: lwc1        $f16, 0xD4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x80046ED0: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x80046ED4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80046ED8: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80046EDC: lwc1        $f4, 0x56F8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X56F8);
    // 0x80046EE0: swc1        $f18, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f18.u32l;
    // 0x80046EE4: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x80046EE8: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x80046EEC: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80046EF0: mtc1        $zero, $f28
    ctx->f28.u32l = 0;
    // 0x80046EF4: addiu       $s1, $s1, -0x4438
    ctx->r17 = ADD32(ctx->r17, -0X4438);
    // 0x80046EF8: swc1        $f10, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f10.u32l;
    // 0x80046EFC: lwc1        $f26, 0xCC($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x80046F00: lwc1        $f24, 0xC8($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x80046F04: addiu       $s4, $sp, 0x88
    ctx->r20 = ADD32(ctx->r29, 0X88);
    // 0x80046F08: swc1        $f6, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f6.u32l;
    // 0x80046F0C: addiu       $s3, $sp, 0x94
    ctx->r19 = ADD32(ctx->r29, 0X94);
L_80046F10:
    // 0x80046F10: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80046F14: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80046F18: lwc1        $f10, 0x56FC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X56FC);
    // 0x80046F1C: swc1        $f8, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f8.u32l;
    // 0x80046F20: lwc1        $f0, 0x0($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X0);
    // 0x80046F24: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80046F28: lw          $a1, 0x80($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X80);
    // 0x80046F2C: c.eq.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl == ctx->f0.fl;
    // 0x80046F30: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80046F34: bc1f        L_80046FF8
    if (!c1cs) {
        // 0x80046F38: nop
    
            goto L_80046FF8;
    }
    // 0x80046F38: nop

    // 0x80046F3C: lwc1        $f16, 0xC($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0XC);
    // 0x80046F40: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80046F44: lwc1        $f4, 0x5700($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5700);
    // 0x80046F48: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x80046F4C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80046F50: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80046F54: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80046F58: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80046F5C: jal         0x80005FE0
    // 0x80046F60: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_0;
    // 0x80046F60: nop

    after_0:
    // 0x80046F64: lwc1        $f8, 0x4($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X4);
    // 0x80046F68: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80046F6C: lwc1        $f16, 0x5704($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X5704);
    // 0x80046F70: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x80046F74: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80046F78: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80046F7C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80046F80: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80046F84: jal         0x80005D44
    // 0x80046F88: nop

    Matrix_RotateX(rdram, ctx);
        goto after_1;
    // 0x80046F88: nop

    after_1:
    // 0x80046F8C: lwc1        $f4, 0x8($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X8);
    // 0x80046F90: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80046F94: lwc1        $f8, 0x5708($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5708);
    // 0x80046F98: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x80046F9C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80046FA0: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80046FA4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80046FA8: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80046FAC: jal         0x80005E90
    // 0x80046FB0: nop

    Matrix_RotateY(rdram, ctx);
        goto after_2;
    // 0x80046FB0: nop

    after_2:
    // 0x80046FB4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80046FB8: lw          $a1, 0x80($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X80);
    // 0x80046FBC: jal         0x80005FE0
    // 0x80046FC0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateZ(rdram, ctx);
        goto after_3;
    // 0x80046FC0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x80046FC4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80046FC8: lw          $a1, 0x7C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X7C);
    // 0x80046FCC: jal         0x80005D44
    // 0x80046FD0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateX(rdram, ctx);
        goto after_4;
    // 0x80046FD0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
    // 0x80046FD4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80046FD8: lw          $a1, 0x78($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X78);
    // 0x80046FDC: jal         0x80005E90
    // 0x80046FE0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateY(rdram, ctx);
        goto after_5;
    // 0x80046FE0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x80046FE4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80046FE8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80046FEC: addiu       $s2, $s2, 0x10
    ctx->r18 = ADD32(ctx->r18, 0X10);
    // 0x80046FF0: b           L_80047038
    // 0x80046FF4: swc1        $f16, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f16.u32l;
        goto L_80047038;
    // 0x80046FF4: swc1        $f16, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f16.u32l;
L_80046FF8:
    // 0x80046FF8: lwc1        $f18, 0x570C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X570C);
    // 0x80046FFC: c.eq.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl == ctx->f0.fl;
    // 0x80047000: nop

    // 0x80047004: bc1f        L_80047010
    if (!c1cs) {
        // 0x80047008: nop
    
            goto L_80047010;
    }
    // 0x80047008: nop

    // 0x8004700C: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
L_80047010:
    // 0x80047010: jal         0x80005FE0
    // 0x80047014: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    Matrix_RotateZ(rdram, ctx);
        goto after_6;
    // 0x80047014: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_6:
    // 0x80047018: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8004701C: lw          $a1, 0x7C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X7C);
    // 0x80047020: jal         0x80005D44
    // 0x80047024: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateX(rdram, ctx);
        goto after_7;
    // 0x80047024: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_7:
    // 0x80047028: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8004702C: lw          $a1, 0x78($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X78);
    // 0x80047030: jal         0x80005E90
    // 0x80047034: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateY(rdram, ctx);
        goto after_8;
    // 0x80047034: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_8:
L_80047038:
    // 0x80047038: lwc1        $f4, 0xDC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x8004703C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80047040: lwc1        $f8, 0xE0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XE0);
    // 0x80047044: lwc1        $f16, 0xE4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x80047048: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x8004704C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80047050: bc1f        L_80047080
    if (!c1cs) {
        // 0x80047054: nop
    
            goto L_80047080;
    }
    // 0x80047054: nop

    // 0x80047058: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8004705C: lwc1        $f10, 0xE4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x80047060: c.eq.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl == ctx->f0.fl;
    // 0x80047064: nop

    // 0x80047068: bc1f        L_80047080
    if (!c1cs) {
        // 0x8004706C: nop
    
            goto L_80047080;
    }
    // 0x8004706C: nop

    // 0x80047070: c.eq.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl == ctx->f0.fl;
    // 0x80047074: nop

    // 0x80047078: bc1tl       L_800470F0
    if (c1cs) {
        // 0x8004707C: lwc1        $f8, 0xD4($sp)
        ctx->f8.u32l = MEM_W(ctx->r29, 0XD4);
            goto L_800470F0;
    }
    goto skip_0;
    // 0x8004707C: lwc1        $f8, 0xD4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XD4);
    skip_0:
L_80047080:
    // 0x80047080: lwc1        $f4, 0x5710($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5710);
    // 0x80047084: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x80047088: lwc1        $f8, 0xDC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x8004708C: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80047090: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80047094: lwc1        $f16, 0x5714($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X5714);
    // 0x80047098: lwc1        $f18, 0xE0($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XE0);
    // 0x8004709C: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x800470A0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800470A4: mul.s       $f20, $f10, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f20.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800470A8: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800470AC: lwc1        $f6, 0x5718($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5718);
    // 0x800470B0: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x800470B4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800470B8: mul.s       $f22, $f4, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f22.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800470BC: jal         0x80005FE0
    // 0x800470C0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateZ(rdram, ctx);
        goto after_9;
    // 0x800470C0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_9:
    // 0x800470C4: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x800470C8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800470CC: jal         0x80005D44
    // 0x800470D0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateX(rdram, ctx);
        goto after_10;
    // 0x800470D0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_10:
    // 0x800470D4: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    // 0x800470D8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800470DC: jal         0x80005E90
    // 0x800470E0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateY(rdram, ctx);
        goto after_11;
    // 0x800470E0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_11:
    // 0x800470E4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800470E8: nop

    // 0x800470EC: lwc1        $f8, 0xD4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XD4);
L_800470F0:
    // 0x800470F0: lwc1        $f10, 0xD8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x800470F4: c.eq.s      $f8, $f28
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f8.fl == ctx->f28.fl;
    // 0x800470F8: nop

    // 0x800470FC: bc1fl       L_80047148
    if (!c1cs) {
        // 0x80047100: lwc1        $f4, 0x2D4($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0X2D4);
            goto L_80047148;
    }
    goto skip_1;
    // 0x80047100: lwc1        $f4, 0x2D4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2D4);
    skip_1:
    // 0x80047104: c.eq.s      $f10, $f28
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f10.fl == ctx->f28.fl;
    // 0x80047108: lwc1        $f16, 0xD0($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XD0);
    // 0x8004710C: bc1fl       L_80047148
    if (!c1cs) {
        // 0x80047110: lwc1        $f4, 0x2D4($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0X2D4);
            goto L_80047148;
    }
    goto skip_2;
    // 0x80047110: lwc1        $f4, 0x2D4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2D4);
    skip_2:
    // 0x80047114: c.eq.s      $f16, $f28
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f16.fl == ctx->f28.fl;
    // 0x80047118: lwc1        $f18, 0xA0($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x8004711C: bc1fl       L_80047148
    if (!c1cs) {
        // 0x80047120: lwc1        $f4, 0x2D4($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0X2D4);
            goto L_80047148;
    }
    goto skip_3;
    // 0x80047120: lwc1        $f4, 0x2D4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2D4);
    skip_3:
    // 0x80047124: c.eq.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl == ctx->f0.fl;
    // 0x80047128: nop

    // 0x8004712C: bc1fl       L_80047148
    if (!c1cs) {
        // 0x80047130: lwc1        $f4, 0x2D4($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0X2D4);
            goto L_80047148;
    }
    goto skip_4;
    // 0x80047130: lwc1        $f4, 0x2D4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2D4);
    skip_4:
    // 0x80047134: lwc1        $f0, 0x2D4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X2D4);
    // 0x80047138: lwc1        $f2, 0x2D8($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X2D8);
    // 0x8004713C: b           L_80047190
    // 0x80047140: lwc1        $f12, 0x2DC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X2DC);
        goto L_80047190;
    // 0x80047140: lwc1        $f12, 0x2DC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X2DC);
    // 0x80047144: lwc1        $f4, 0x2D4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2D4);
L_80047148:
    // 0x80047148: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8004714C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80047150: sub.s       $f6, $f4, $f30
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f30.fl;
    // 0x80047154: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x80047158: swc1        $f6, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f6.u32l;
    // 0x8004715C: lwc1        $f8, 0x2D8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2D8);
    // 0x80047160: sub.s       $f10, $f8, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f24.fl;
    // 0x80047164: swc1        $f10, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f10.u32l;
    // 0x80047168: lwc1        $f16, 0x2DC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X2DC);
    // 0x8004716C: sub.s       $f18, $f16, $f26
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f26.fl;
    // 0x80047170: jal         0x80006A20
    // 0x80047174: swc1        $f18, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f18.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_12;
    // 0x80047174: swc1        $f18, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f18.u32l;
    after_12:
    // 0x80047178: lwc1        $f4, 0x88($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X88);
    // 0x8004717C: lwc1        $f6, 0x8C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x80047180: lwc1        $f8, 0x90($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X90);
    // 0x80047184: add.s       $f0, $f4, $f30
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f30.fl;
    // 0x80047188: add.s       $f2, $f6, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f2.fl = ctx->f6.fl + ctx->f24.fl;
    // 0x8004718C: add.s       $f12, $f8, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f26.fl;
L_80047190:
    // 0x80047190: mfc1        $a1, $f30
    ctx->r5 = (int32_t)ctx->f30.u32l;
    // 0x80047194: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x80047198: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x8004719C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800471A0: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x800471A4: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    // 0x800471A8: jal         0x800A78C4
    // 0x800471AC: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    Play_CheckSingleHitbox(rdram, ctx);
        goto after_13;
    // 0x800471AC: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    after_13:
    // 0x800471B0: beq         $v0, $zero, L_800471CC
    if (ctx->r2 == 0) {
        // 0x800471B4: lwc1        $f10, 0xD4($sp)
        ctx->f10.u32l = MEM_W(ctx->r29, 0XD4);
            goto L_800471CC;
    }
    // 0x800471B4: lwc1        $f10, 0xD4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x800471B8: lw          $t0, 0xC0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC0);
    // 0x800471BC: addiu       $t9, $s5, 0x1
    ctx->r25 = ADD32(ctx->r21, 0X1);
    // 0x800471C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800471C4: b           L_800474C8
    // 0x800471C8: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
        goto L_800474C8;
    // 0x800471C8: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
L_800471CC:
    // 0x800471CC: c.eq.s      $f10, $f28
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f10.fl == ctx->f28.fl;
    // 0x800471D0: lwc1        $f16, 0xD8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x800471D4: bc1fl       L_80047228
    if (!c1cs) {
        // 0x800471D8: lwc1        $f8, 0x2C8($s0)
        ctx->f8.u32l = MEM_W(ctx->r16, 0X2C8);
            goto L_80047228;
    }
    goto skip_5;
    // 0x800471D8: lwc1        $f8, 0x2C8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2C8);
    skip_5:
    // 0x800471DC: c.eq.s      $f16, $f28
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f16.fl == ctx->f28.fl;
    // 0x800471E0: lwc1        $f18, 0xD0($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XD0);
    // 0x800471E4: bc1fl       L_80047228
    if (!c1cs) {
        // 0x800471E8: lwc1        $f8, 0x2C8($s0)
        ctx->f8.u32l = MEM_W(ctx->r16, 0X2C8);
            goto L_80047228;
    }
    goto skip_6;
    // 0x800471E8: lwc1        $f8, 0x2C8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2C8);
    skip_6:
    // 0x800471EC: c.eq.s      $f18, $f28
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f18.fl == ctx->f28.fl;
    // 0x800471F0: lwc1        $f4, 0xA0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x800471F4: bc1fl       L_80047228
    if (!c1cs) {
        // 0x800471F8: lwc1        $f8, 0x2C8($s0)
        ctx->f8.u32l = MEM_W(ctx->r16, 0X2C8);
            goto L_80047228;
    }
    goto skip_7;
    // 0x800471F8: lwc1        $f8, 0x2C8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2C8);
    skip_7:
    // 0x800471FC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80047200: nop

    // 0x80047204: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x80047208: nop

    // 0x8004720C: bc1fl       L_80047228
    if (!c1cs) {
        // 0x80047210: lwc1        $f8, 0x2C8($s0)
        ctx->f8.u32l = MEM_W(ctx->r16, 0X2C8);
            goto L_80047228;
    }
    goto skip_8;
    // 0x80047210: lwc1        $f8, 0x2C8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2C8);
    skip_8:
    // 0x80047214: lwc1        $f0, 0x2C8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X2C8);
    // 0x80047218: lwc1        $f2, 0x2CC($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X2CC);
    // 0x8004721C: b           L_80047270
    // 0x80047220: lwc1        $f12, 0x2D0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X2D0);
        goto L_80047270;
    // 0x80047220: lwc1        $f12, 0x2D0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X2D0);
    // 0x80047224: lwc1        $f8, 0x2C8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2C8);
L_80047228:
    // 0x80047228: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8004722C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80047230: sub.s       $f10, $f8, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f30.fl;
    // 0x80047234: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x80047238: swc1        $f10, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f10.u32l;
    // 0x8004723C: lwc1        $f16, 0x2CC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X2CC);
    // 0x80047240: sub.s       $f18, $f16, $f24
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f24.fl;
    // 0x80047244: swc1        $f18, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f18.u32l;
    // 0x80047248: lwc1        $f4, 0x2D0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2D0);
    // 0x8004724C: sub.s       $f6, $f4, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f26.fl;
    // 0x80047250: jal         0x80006A20
    // 0x80047254: swc1        $f6, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f6.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_14;
    // 0x80047254: swc1        $f6, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f6.u32l;
    after_14:
    // 0x80047258: lwc1        $f8, 0x88($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X88);
    // 0x8004725C: lwc1        $f10, 0x8C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x80047260: lwc1        $f16, 0x90($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X90);
    // 0x80047264: add.s       $f0, $f8, $f30
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f30.fl;
    // 0x80047268: add.s       $f2, $f10, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f2.fl = ctx->f10.fl + ctx->f24.fl;
    // 0x8004726C: add.s       $f12, $f16, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f26.fl;
L_80047270:
    // 0x80047270: mfc1        $a1, $f30
    ctx->r5 = (int32_t)ctx->f30.u32l;
    // 0x80047274: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x80047278: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x8004727C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80047280: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x80047284: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    // 0x80047288: jal         0x800A78C4
    // 0x8004728C: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    Play_CheckSingleHitbox(rdram, ctx);
        goto after_15;
    // 0x8004728C: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    after_15:
    // 0x80047290: beq         $v0, $zero, L_800472AC
    if (ctx->r2 == 0) {
        // 0x80047294: lwc1        $f18, 0xD4($sp)
        ctx->f18.u32l = MEM_W(ctx->r29, 0XD4);
            goto L_800472AC;
    }
    // 0x80047294: lwc1        $f18, 0xD4($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x80047298: lw          $t2, 0xC0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC0);
    // 0x8004729C: addiu       $t1, $s5, 0x1
    ctx->r9 = ADD32(ctx->r21, 0X1);
    // 0x800472A0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800472A4: b           L_800474C8
    // 0x800472A8: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
        goto L_800474C8;
    // 0x800472A8: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
L_800472AC:
    // 0x800472AC: c.eq.s      $f18, $f28
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f18.fl == ctx->f28.fl;
    // 0x800472B0: lwc1        $f4, 0xD8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x800472B4: bc1fl       L_80047308
    if (!c1cs) {
        // 0x800472B8: lwc1        $f16, 0x2E0($s0)
        ctx->f16.u32l = MEM_W(ctx->r16, 0X2E0);
            goto L_80047308;
    }
    goto skip_9;
    // 0x800472B8: lwc1        $f16, 0x2E0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X2E0);
    skip_9:
    // 0x800472BC: c.eq.s      $f4, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f4.fl == ctx->f28.fl;
    // 0x800472C0: lwc1        $f6, 0xD0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XD0);
    // 0x800472C4: bc1fl       L_80047308
    if (!c1cs) {
        // 0x800472C8: lwc1        $f16, 0x2E0($s0)
        ctx->f16.u32l = MEM_W(ctx->r16, 0X2E0);
            goto L_80047308;
    }
    goto skip_10;
    // 0x800472C8: lwc1        $f16, 0x2E0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X2E0);
    skip_10:
    // 0x800472CC: c.eq.s      $f6, $f28
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f6.fl == ctx->f28.fl;
    // 0x800472D0: lwc1        $f8, 0xA0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x800472D4: bc1fl       L_80047308
    if (!c1cs) {
        // 0x800472D8: lwc1        $f16, 0x2E0($s0)
        ctx->f16.u32l = MEM_W(ctx->r16, 0X2E0);
            goto L_80047308;
    }
    goto skip_11;
    // 0x800472D8: lwc1        $f16, 0x2E0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X2E0);
    skip_11:
    // 0x800472DC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800472E0: nop

    // 0x800472E4: c.eq.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl == ctx->f10.fl;
    // 0x800472E8: nop

    // 0x800472EC: bc1fl       L_80047308
    if (!c1cs) {
        // 0x800472F0: lwc1        $f16, 0x2E0($s0)
        ctx->f16.u32l = MEM_W(ctx->r16, 0X2E0);
            goto L_80047308;
    }
    goto skip_12;
    // 0x800472F0: lwc1        $f16, 0x2E0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X2E0);
    skip_12:
    // 0x800472F4: lwc1        $f0, 0x2E0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X2E0);
    // 0x800472F8: lwc1        $f2, 0x2E4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X2E4);
    // 0x800472FC: b           L_80047350
    // 0x80047300: lwc1        $f12, 0x2E8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X2E8);
        goto L_80047350;
    // 0x80047300: lwc1        $f12, 0x2E8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X2E8);
    // 0x80047304: lwc1        $f16, 0x2E0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X2E0);
L_80047308:
    // 0x80047308: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8004730C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80047310: sub.s       $f18, $f16, $f30
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f30.fl;
    // 0x80047314: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x80047318: swc1        $f18, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f18.u32l;
    // 0x8004731C: lwc1        $f4, 0x2E4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2E4);
    // 0x80047320: sub.s       $f6, $f4, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f24.fl;
    // 0x80047324: swc1        $f6, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f6.u32l;
    // 0x80047328: lwc1        $f8, 0x2E8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2E8);
    // 0x8004732C: sub.s       $f10, $f8, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f26.fl;
    // 0x80047330: jal         0x80006A20
    // 0x80047334: swc1        $f10, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f10.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_16;
    // 0x80047334: swc1        $f10, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f10.u32l;
    after_16:
    // 0x80047338: lwc1        $f16, 0x88($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X88);
    // 0x8004733C: lwc1        $f18, 0x8C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x80047340: lwc1        $f4, 0x90($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X90);
    // 0x80047344: add.s       $f0, $f16, $f30
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f0.fl = ctx->f16.fl + ctx->f30.fl;
    // 0x80047348: add.s       $f2, $f18, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f2.fl = ctx->f18.fl + ctx->f24.fl;
    // 0x8004734C: add.s       $f12, $f4, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f26.fl;
L_80047350:
    // 0x80047350: mfc1        $a1, $f30
    ctx->r5 = (int32_t)ctx->f30.u32l;
    // 0x80047354: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x80047358: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x8004735C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80047360: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x80047364: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    // 0x80047368: jal         0x800A78C4
    // 0x8004736C: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    Play_CheckSingleHitbox(rdram, ctx);
        goto after_17;
    // 0x8004736C: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    after_17:
    // 0x80047370: beq         $v0, $zero, L_800473B0
    if (ctx->r2 == 0) {
        // 0x80047374: lui         $at, 0x800D
        ctx->r1 = S32(0X800D << 16);
            goto L_800473B0;
    }
    // 0x80047374: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80047378: lw          $t4, 0xC0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC0);
    // 0x8004737C: addiu       $t3, $s5, 0x1
    ctx->r11 = ADD32(ctx->r21, 0X1);
    // 0x80047380: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80047384: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x80047388: lwc1        $f8, -0x4($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, -0X4);
    // 0x8004738C: lwc1        $f6, 0x571C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X571C);
    // 0x80047390: c.eq.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl == ctx->f8.fl;
    // 0x80047394: nop

    // 0x80047398: bc1f        L_800473A8
    if (!c1cs) {
        // 0x8004739C: nop
    
            goto L_800473A8;
    }
    // 0x8004739C: nop

    // 0x800473A0: b           L_800474C8
    // 0x800473A4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800474C8;
    // 0x800473A4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800473A8:
    // 0x800473A8: b           L_800474C8
    // 0x800473AC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_800474C8;
    // 0x800473AC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_800473B0:
    // 0x800473B0: lwc1        $f10, 0x5720($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X5720);
    // 0x800473B4: lwc1        $f16, -0x4($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, -0X4);
    // 0x800473B8: lwc1        $f18, 0xD4($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x800473BC: lwc1        $f4, 0xD8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x800473C0: c.eq.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl == ctx->f16.fl;
    // 0x800473C4: nop

    // 0x800473C8: bc1fl       L_800473DC
    if (!c1cs) {
        // 0x800473CC: c.eq.s      $f18, $f28
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f18.fl == ctx->f28.fl;
            goto L_800473DC;
    }
    goto skip_13;
    // 0x800473CC: c.eq.s      $f18, $f28
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f18.fl == ctx->f28.fl;
    skip_13:
    // 0x800473D0: b           L_800474C8
    // 0x800473D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800474C8;
    // 0x800473D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800473D8: c.eq.s      $f18, $f28
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f18.fl == ctx->f28.fl;
L_800473DC:
    // 0x800473DC: nop

    // 0x800473E0: bc1fl       L_80047434
    if (!c1cs) {
        // 0x800473E4: lwc1        $f16, 0x2EC($s0)
        ctx->f16.u32l = MEM_W(ctx->r16, 0X2EC);
            goto L_80047434;
    }
    goto skip_14;
    // 0x800473E4: lwc1        $f16, 0x2EC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X2EC);
    skip_14:
    // 0x800473E8: c.eq.s      $f4, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f4.fl == ctx->f28.fl;
    // 0x800473EC: lwc1        $f6, 0xD0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XD0);
    // 0x800473F0: bc1fl       L_80047434
    if (!c1cs) {
        // 0x800473F4: lwc1        $f16, 0x2EC($s0)
        ctx->f16.u32l = MEM_W(ctx->r16, 0X2EC);
            goto L_80047434;
    }
    goto skip_15;
    // 0x800473F4: lwc1        $f16, 0x2EC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X2EC);
    skip_15:
    // 0x800473F8: c.eq.s      $f6, $f28
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f6.fl == ctx->f28.fl;
    // 0x800473FC: lwc1        $f8, 0xA0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x80047400: bc1fl       L_80047434
    if (!c1cs) {
        // 0x80047404: lwc1        $f16, 0x2EC($s0)
        ctx->f16.u32l = MEM_W(ctx->r16, 0X2EC);
            goto L_80047434;
    }
    goto skip_16;
    // 0x80047404: lwc1        $f16, 0x2EC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X2EC);
    skip_16:
    // 0x80047408: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8004740C: nop

    // 0x80047410: c.eq.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl == ctx->f10.fl;
    // 0x80047414: nop

    // 0x80047418: bc1fl       L_80047434
    if (!c1cs) {
        // 0x8004741C: lwc1        $f16, 0x2EC($s0)
        ctx->f16.u32l = MEM_W(ctx->r16, 0X2EC);
            goto L_80047434;
    }
    goto skip_17;
    // 0x8004741C: lwc1        $f16, 0x2EC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X2EC);
    skip_17:
    // 0x80047420: lwc1        $f0, 0x2EC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X2EC);
    // 0x80047424: lwc1        $f2, 0x2F0($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X2F0);
    // 0x80047428: b           L_8004747C
    // 0x8004742C: lwc1        $f12, 0x2F4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X2F4);
        goto L_8004747C;
    // 0x8004742C: lwc1        $f12, 0x2F4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X2F4);
    // 0x80047430: lwc1        $f16, 0x2EC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X2EC);
L_80047434:
    // 0x80047434: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80047438: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x8004743C: sub.s       $f18, $f16, $f30
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f30.fl;
    // 0x80047440: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x80047444: swc1        $f18, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f18.u32l;
    // 0x80047448: lwc1        $f4, 0x2F0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2F0);
    // 0x8004744C: sub.s       $f6, $f4, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f24.fl;
    // 0x80047450: swc1        $f6, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f6.u32l;
    // 0x80047454: lwc1        $f8, 0x2F4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2F4);
    // 0x80047458: sub.s       $f10, $f8, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f26.fl;
    // 0x8004745C: jal         0x80006A20
    // 0x80047460: swc1        $f10, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f10.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_18;
    // 0x80047460: swc1        $f10, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f10.u32l;
    after_18:
    // 0x80047464: lwc1        $f16, 0x88($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X88);
    // 0x80047468: lwc1        $f18, 0x8C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x8004746C: lwc1        $f4, 0x90($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X90);
    // 0x80047470: add.s       $f0, $f16, $f30
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f0.fl = ctx->f16.fl + ctx->f30.fl;
    // 0x80047474: add.s       $f2, $f18, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f2.fl = ctx->f18.fl + ctx->f24.fl;
    // 0x80047478: add.s       $f12, $f4, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f26.fl;
L_8004747C:
    // 0x8004747C: mfc1        $a1, $f30
    ctx->r5 = (int32_t)ctx->f30.u32l;
    // 0x80047480: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x80047484: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x80047488: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8004748C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x80047490: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    // 0x80047494: jal         0x800A78C4
    // 0x80047498: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    Play_CheckSingleHitbox(rdram, ctx);
        goto after_19;
    // 0x80047498: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    after_19:
    // 0x8004749C: beq         $v0, $zero, L_800474B8
    if (ctx->r2 == 0) {
        // 0x800474A0: lw          $t7, 0xB4($sp)
        ctx->r15 = MEM_W(ctx->r29, 0XB4);
            goto L_800474B8;
    }
    // 0x800474A0: lw          $t7, 0xB4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB4);
    // 0x800474A4: lw          $t6, 0xC0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC0);
    // 0x800474A8: addiu       $t5, $s5, 0x1
    ctx->r13 = ADD32(ctx->r21, 0X1);
    // 0x800474AC: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x800474B0: b           L_800474C8
    // 0x800474B4: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
        goto L_800474C8;
    // 0x800474B4: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
L_800474B8:
    // 0x800474B8: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x800474BC: bne         $s5, $t7, L_80046F10
    if (ctx->r21 != ctx->r15) {
        // 0x800474C0: addiu       $s2, $s2, 0x18
        ctx->r18 = ADD32(ctx->r18, 0X18);
            goto L_80046F10;
    }
    // 0x800474C0: addiu       $s2, $s2, 0x18
    ctx->r18 = ADD32(ctx->r18, 0X18);
L_800474C4:
    // 0x800474C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800474C8:
    // 0x800474C8: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x800474CC: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x800474D0: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x800474D4: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x800474D8: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x800474DC: ldc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X40);
    // 0x800474E0: ldc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X48);
    // 0x800474E4: lw          $s0, 0x54($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X54);
    // 0x800474E8: lw          $s1, 0x58($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X58);
    // 0x800474EC: lw          $s2, 0x5C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X5C);
    // 0x800474F0: lw          $s3, 0x60($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X60);
    // 0x800474F4: lw          $s4, 0x64($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X64);
    // 0x800474F8: lw          $s5, 0x68($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X68);
    // 0x800474FC: jr          $ra
    // 0x80047500: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    return;
    // 0x80047500: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
;}
RECOMP_FUNC void ActorTeamBoss_Shoot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80091DF4: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80091DF8: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80091DFC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80091E00: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80091E04: lw          $t6, 0x50($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X50);
    // 0x80091E08: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x80091E0C: beql        $t6, $zero, L_80091EEC
    if (ctx->r14 == 0) {
        // 0x80091E10: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80091EEC;
    }
    goto skip_0;
    // 0x80091E10: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80091E14: lw          $t7, 0x7848($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7848);
    // 0x80091E18: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80091E1C: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x80091E20: slti        $at, $t7, 0x47
    ctx->r1 = SIGNED(ctx->r15) < 0X47 ? 1 : 0;
    // 0x80091E24: bne         $at, $zero, L_80091EE8
    if (ctx->r1 != 0) {
        // 0x80091E28: addiu       $a2, $sp, 0x38
        ctx->r6 = ADD32(ctx->r29, 0X38);
            goto L_80091EE8;
    }
    // 0x80091E28: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    // 0x80091E2C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80091E30: sw          $zero, 0x50($s0)
    MEM_W(0X50, ctx->r16) = 0;
    // 0x80091E34: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80091E38: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80091E3C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80091E40: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x80091E44: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x80091E48: jal         0x80006A20
    // 0x80091E4C: swc1        $f4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f4.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_0;
    // 0x80091E4C: swc1        $f4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x80091E50: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80091E54: lui         $at, 0x3FF8
    ctx->r1 = S32(0X3FF8 << 16);
    // 0x80091E58: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x80091E5C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80091E60: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80091E64: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80091E68: mul.d       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f0.d); 
    ctx->f18.d = MUL_D(ctx->f16.d, ctx->f0.d);
    // 0x80091E6C: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80091E70: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80091E74: lh          $a0, 0xE4($s0)
    ctx->r4 = MEM_H(ctx->r16, 0XE4);
    // 0x80091E78: add.d       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f8.d + ctx->f18.d;
    // 0x80091E7C: lwc1        $f18, 0x3C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80091E80: cvt.d.s     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f8.d = CVT_D_S(ctx->f16.fl);
    // 0x80091E84: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x80091E88: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x80091E8C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80091E90: mul.d       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f0.d);
    // 0x80091E94: add.d       $f16, $f8, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f16.d = ctx->f8.d + ctx->f6.d;
    // 0x80091E98: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80091E9C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x80091EA0: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x80091EA4: cvt.s.d     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f4.fl = CVT_S_D(ctx->f16.d);
    // 0x80091EA8: lwc1        $f16, 0x40($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80091EAC: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x80091EB0: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80091EB4: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x80091EB8: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    // 0x80091EBC: mul.d       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f0.d);
    // 0x80091EC0: add.d       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = ctx->f6.d + ctx->f8.d;
    // 0x80091EC4: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80091EC8: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x80091ECC: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x80091ED0: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80091ED4: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x80091ED8: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x80091EDC: lwc1        $f6, 0x18($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80091EE0: jal         0x8006EEFC
    // 0x80091EE4: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    Actor_SpawnPlayerLaser(rdram, ctx);
        goto after_1;
    // 0x80091EE4: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    after_1:
L_80091EE8:
    // 0x80091EE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80091EEC:
    // 0x80091EEC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80091EF0: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80091EF4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80091EF8: jr          $ra
    // 0x80091EFC: nop

    return;
    // 0x80091EFC: nop

;}
RECOMP_FUNC void Effect_Effect350_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007FBE0: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8007FBE4: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x8007FBE8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007FBEC: lwc1        $f2, 0x74C0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X74C0);
    // 0x8007FBF0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8007FBF4: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8007FBF8: sw          $s3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r19;
    // 0x8007FBFC: sw          $s2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r18;
    // 0x8007FC00: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x8007FC04: sdc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X38, ctx->r29);
    // 0x8007FC08: sdc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X30, ctx->r29);
    // 0x8007FC0C: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x8007FC10: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x8007FC14: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x8007FC18: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x8007FC1C: lwc1        $f0, 0x6C($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X6C);
    // 0x8007FC20: lwc1        $f4, 0x70($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X70);
    // 0x8007FC24: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007FC28: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8007FC2C: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x8007FC30: swc1        $f6, 0x70($s1)
    MEM_W(0X70, ctx->r17) = ctx->f6.u32l;
    // 0x8007FC34: lwc1        $f8, 0x74C4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X74C4);
    // 0x8007FC38: sub.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x8007FC3C: swc1        $f10, 0x6C($s1)
    MEM_W(0X6C, ctx->r17) = ctx->f10.u32l;
    // 0x8007FC40: lwc1        $f16, 0x6C($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X6C);
    // 0x8007FC44: c.lt.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl < ctx->f2.fl;
    // 0x8007FC48: nop

    // 0x8007FC4C: bc1fl       L_8007FC5C
    if (!c1cs) {
        // 0x8007FC50: lh          $t6, 0x44($s1)
        ctx->r14 = MEM_H(ctx->r17, 0X44);
            goto L_8007FC5C;
    }
    goto skip_0;
    // 0x8007FC50: lh          $t6, 0x44($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X44);
    skip_0:
    // 0x8007FC54: swc1        $f2, 0x6C($s1)
    MEM_W(0X6C, ctx->r17) = ctx->f2.u32l;
    // 0x8007FC58: lh          $t6, 0x44($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X44);
L_8007FC5C:
    // 0x8007FC5C: addiu       $t7, $t6, -0x6
    ctx->r15 = ADD32(ctx->r14, -0X6);
    // 0x8007FC60: sh          $t7, 0x44($s1)
    MEM_H(0X44, ctx->r17) = ctx->r15;
    // 0x8007FC64: lh          $t8, 0x44($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X44);
    // 0x8007FC68: bgez        $t8, L_8007FC78
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8007FC6C: nop
    
            goto L_8007FC78;
    }
    // 0x8007FC6C: nop

    // 0x8007FC70: jal         0x80060FBC
    // 0x8007FC74: addiu       $a1, $s1, 0x80
    ctx->r5 = ADD32(ctx->r17, 0X80);
    Object_Kill(rdram, ctx);
        goto after_0;
    // 0x8007FC74: addiu       $a1, $s1, 0x80
    ctx->r5 = ADD32(ctx->r17, 0X80);
    after_0:
L_8007FC78:
    // 0x8007FC78: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x8007FC7C: lw          $t9, 0x7DB0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7DB0);
    // 0x8007FC80: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x8007FC84: bnel        $t0, $zero, L_8007FD54
    if (ctx->r8 != 0) {
        // 0x8007FC88: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_8007FD54;
    }
    goto skip_1;
    // 0x8007FC88: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    skip_1:
    // 0x8007FC8C: jal         0x80004EB0
    // 0x8007FC90: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x8007FC90: nop

    after_1:
    // 0x8007FC94: lui         $at, 0x4310
    ctx->r1 = S32(0X4310 << 16);
    // 0x8007FC98: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8007FC9C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007FCA0: lwc1        $f30, 0x74C8($at)
    ctx->f30.u32l = MEM_W(ctx->r1, 0X74C8);
    // 0x8007FCA4: lui         $at, 0x4210
    ctx->r1 = S32(0X4210 << 16);
    // 0x8007FCA8: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x8007FCAC: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x8007FCB0: lui         $s2, 0x8017
    ctx->r18 = S32(0X8017 << 16);
    // 0x8007FCB4: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x8007FCB8: mul.s       $f26, $f0, $f18
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f26.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x8007FCBC: addiu       $s2, $s2, 0x7940
    ctx->r18 = ADD32(ctx->r18, 0X7940);
    // 0x8007FCC0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8007FCC4: addiu       $s3, $zero, 0xA
    ctx->r19 = ADD32(0, 0XA);
    // 0x8007FCC8: mtc1        $s0, $f4
    ctx->f4.u32l = ctx->r16;
L_8007FCCC:
    // 0x8007FCCC: nop

    // 0x8007FCD0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8007FCD4: mul.s       $f8, $f6, $f28
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f28.fl);
    // 0x8007FCD8: nop

    // 0x8007FCDC: mul.s       $f10, $f8, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f30.fl);
    // 0x8007FCE0: add.s       $f20, $f10, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f20.fl = ctx->f10.fl + ctx->f26.fl;
    // 0x8007FCE4: jal         0x80023090
    // 0x8007FCE8: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    __sinf_recomp(rdram, ctx);
        goto after_2;
    // 0x8007FCE8: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_2:
    // 0x8007FCEC: lwc1        $f16, 0x70($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X70);
    // 0x8007FCF0: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x8007FCF4: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x8007FCF8: nop

    // 0x8007FCFC: mul.s       $f22, $f18, $f24
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f22.fl = MUL_S(ctx->f18.fl, ctx->f24.fl);
    // 0x8007FD00: jal         0x80023250
    // 0x8007FD04: nop

    __cosf_recomp(rdram, ctx);
        goto after_3;
    // 0x8007FD04: nop

    after_3:
    // 0x8007FD08: lwc1        $f4, 0x70($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X70);
    // 0x8007FD0C: lwc1        $f18, 0xC($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8007FD10: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8007FD14: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8007FD18: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8007FD1C: lwc1        $f8, 0x0($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X0);
    // 0x8007FD20: lwc1        $f16, 0x4($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8007FD24: lui         $a3, 0x4140
    ctx->r7 = S32(0X4140 << 16);
    // 0x8007FD28: add.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8007FD2C: mul.s       $f2, $f6, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f24.fl);
    // 0x8007FD30: add.s       $f12, $f16, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f22.fl;
    // 0x8007FD34: add.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f2.fl;
    // 0x8007FD38: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x8007FD3C: jal         0x8007BC7C
    // 0x8007FD40: nop

    Effect_Effect362_Spawn(rdram, ctx);
        goto after_4;
    // 0x8007FD40: nop

    after_4:
    // 0x8007FD44: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8007FD48: bnel        $s0, $s3, L_8007FCCC
    if (ctx->r16 != ctx->r19) {
        // 0x8007FD4C: mtc1        $s0, $f4
        ctx->f4.u32l = ctx->r16;
            goto L_8007FCCC;
    }
    goto skip_2;
    // 0x8007FD4C: mtc1        $s0, $f4
    ctx->f4.u32l = ctx->r16;
    skip_2:
    // 0x8007FD50: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_8007FD54:
    // 0x8007FD54: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x8007FD58: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x8007FD5C: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x8007FD60: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x8007FD64: ldc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X30);
    // 0x8007FD68: ldc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X38);
    // 0x8007FD6C: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x8007FD70: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x8007FD74: lw          $s2, 0x4C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X4C);
    // 0x8007FD78: lw          $s3, 0x50($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X50);
    // 0x8007FD7C: jr          $ra
    // 0x8007FD80: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8007FD80: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void HUD_RadarMarks_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A4DC: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8008A4E0: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x8008A4E4: lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // 0x8008A4E8: addiu       $s0, $s0, 0x78E8
    ctx->r16 = ADD32(ctx->r16, 0X78E8);
    // 0x8008A4EC: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8008A4F0: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x8008A4F4: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8008A4F8: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x8008A4FC: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x8008A500: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x8008A504: bne         $t6, $zero, L_8008A710
    if (ctx->r14 != 0) {
        // 0x8008A508: nop
    
            goto L_8008A710;
    }
    // 0x8008A508: nop

    // 0x8008A50C: lw          $t7, 0x7880($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7880);
    // 0x8008A510: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8008A514: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x8008A518: beq         $t7, $at, L_8008A528
    if (ctx->r15 == ctx->r1) {
        // 0x8008A51C: nop
    
            goto L_8008A528;
    }
    // 0x8008A51C: nop

    // 0x8008A520: b           L_8008AC3C
    // 0x8008A524: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008AC3C;
    // 0x8008A524: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008A528:
    // 0x8008A528: lbu         $t8, 0x7AB0($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X7AB0);
    // 0x8008A52C: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x8008A530: slti        $at, $t8, 0x5
    ctx->r1 = SIGNED(ctx->r24) < 0X5 ? 1 : 0;
    // 0x8008A534: bne         $at, $zero, L_8008A544
    if (ctx->r1 != 0) {
        // 0x8008A538: nop
    
            goto L_8008A544;
    }
    // 0x8008A538: nop

    // 0x8008A53C: b           L_8008AC3C
    // 0x8008A540: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008AC3C;
    // 0x8008A540: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008A544:
    // 0x8008A544: lw          $t9, 0x7838($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7838);
    // 0x8008A548: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    // 0x8008A54C: addiu       $s1, $s1, 0x1E10
    ctx->r17 = ADD32(ctx->r17, 0X1E10);
    // 0x8008A550: beq         $t9, $zero, L_8008A570
    if (ctx->r25 == 0) {
        // 0x8008A554: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8008A570;
    }
    // 0x8008A554: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8008A558: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8008A55C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8008A560: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    // 0x8008A564: addiu       $s1, $s1, 0x1E10
    ctx->r17 = ADD32(ctx->r17, 0X1E10);
    // 0x8008A568: b           L_8008A590
    // 0x8008A56C: swc1        $f4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f4.u32l;
        goto L_8008A590;
    // 0x8008A56C: swc1        $f4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f4.u32l;
L_8008A570:
    // 0x8008A570: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8008A574: lwc1        $f6, 0x7964($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7964);
    // 0x8008A578: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x8008A57C: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x8008A580: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8008A584: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x8008A588: jal         0x8009BC2C
    // 0x8008A58C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_0;
    // 0x8008A58C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_0:
L_8008A590:
    // 0x8008A590: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8008A594: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8008A598: lwc1        $f2, 0x0($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8008A59C: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8008A5A0: c.eq.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl == ctx->f2.fl;
    // 0x8008A5A4: nop

    // 0x8008A5A8: bc1f        L_8008A5B8
    if (!c1cs) {
        // 0x8008A5AC: nop
    
            goto L_8008A5B8;
    }
    // 0x8008A5AC: nop

    // 0x8008A5B0: b           L_8008AC3C
    // 0x8008A5B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008AC3C;
    // 0x8008A5B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008A5B8:
    // 0x8008A5B8: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
    // 0x8008A5BC: lui         $at, 0x45FA
    ctx->r1 = S32(0X45FA << 16);
    // 0x8008A5C0: beql        $v0, $zero, L_8008A664
    if (ctx->r2 == 0) {
        // 0x8008A5C4: mtc1        $at, $f18
        ctx->f18.u32l = ctx->r1;
            goto L_8008A664;
    }
    goto skip_0;
    // 0x8008A5C4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    skip_0:
    // 0x8008A5C8: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x8008A5CC: beq         $v0, $at, L_8008A6A0
    if (ctx->r2 == ctx->r1) {
        // 0x8008A5D0: addiu       $at, $zero, 0x12
        ctx->r1 = ADD32(0, 0X12);
            goto L_8008A6A0;
    }
    // 0x8008A5D0: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    // 0x8008A5D4: beq         $v0, $at, L_8008A61C
    if (ctx->r2 == ctx->r1) {
        // 0x8008A5D8: lui         $at, 0x800D
        ctx->r1 = S32(0X800D << 16);
            goto L_8008A61C;
    }
    // 0x8008A5D8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8008A5DC: lwc1        $f10, 0x7968($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7968);
    // 0x8008A5E0: lui         $at, 0xC35C
    ctx->r1 = S32(0XC35C << 16);
    // 0x8008A5E4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8008A5E8: lui         $at, 0x43A5
    ctx->r1 = S32(0X43A5 << 16);
    // 0x8008A5EC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8008A5F0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8008A5F4: lwc1        $f4, 0x796C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X796C);
    // 0x8008A5F8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8008A5FC: lwc1        $f0, 0x7970($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X7970);
    // 0x8008A600: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8008A604: lwc1        $f20, 0x7974($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X7974);
    // 0x8008A608: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    // 0x8008A60C: swc1        $f16, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f16.u32l;
    // 0x8008A610: swc1        $f18, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f18.u32l;
    // 0x8008A614: b           L_8008A6E0
    // 0x8008A618: swc1        $f4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f4.u32l;
        goto L_8008A6E0;
    // 0x8008A618: swc1        $f4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f4.u32l;
L_8008A61C:
    // 0x8008A61C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8008A620: lwc1        $f6, 0x7978($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7978);
    // 0x8008A624: lui         $at, 0xC3B4
    ctx->r1 = S32(0XC3B4 << 16);
    // 0x8008A628: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8008A62C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8008A630: lwc1        $f10, 0x797C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X797C);
    // 0x8008A634: lui         $at, 0xC4C6
    ctx->r1 = S32(0XC4C6 << 16);
    // 0x8008A638: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8008A63C: lui         $at, 0x40F0
    ctx->r1 = S32(0X40F0 << 16);
    // 0x8008A640: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8008A644: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8008A648: lwc1        $f20, 0x7980($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X7980);
    // 0x8008A64C: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    // 0x8008A650: swc1        $f8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f8.u32l;
    // 0x8008A654: swc1        $f10, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f10.u32l;
    // 0x8008A658: b           L_8008A6E0
    // 0x8008A65C: swc1        $f16, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f16.u32l;
        goto L_8008A6E0;
    // 0x8008A65C: swc1        $f16, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f16.u32l;
    // 0x8008A660: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
L_8008A664:
    // 0x8008A664: lui         $at, 0xC30E
    ctx->r1 = S32(0XC30E << 16);
    // 0x8008A668: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8008A66C: lui         $at, 0x4356
    ctx->r1 = S32(0X4356 << 16);
    // 0x8008A670: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8008A674: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8008A678: lwc1        $f8, 0x7984($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7984);
    // 0x8008A67C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8008A680: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8008A684: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8008A688: lwc1        $f20, 0x7988($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X7988);
    // 0x8008A68C: swc1        $f18, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f18.u32l;
    // 0x8008A690: swc1        $f4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f4.u32l;
    // 0x8008A694: swc1        $f6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f6.u32l;
    // 0x8008A698: b           L_8008A6E0
    // 0x8008A69C: swc1        $f8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f8.u32l;
        goto L_8008A6E0;
    // 0x8008A69C: swc1        $f8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f8.u32l;
L_8008A6A0:
    // 0x8008A6A0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8008A6A4: lwc1        $f10, 0x798C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X798C);
    // 0x8008A6A8: lui         $at, 0xC332
    ctx->r1 = S32(0XC332 << 16);
    // 0x8008A6AC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8008A6B0: lui         $at, 0x4386
    ctx->r1 = S32(0X4386 << 16);
    // 0x8008A6B4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8008A6B8: lui         $at, 0xC444
    ctx->r1 = S32(0XC444 << 16);
    // 0x8008A6BC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8008A6C0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8008A6C4: lwc1        $f0, 0x7990($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X7990);
    // 0x8008A6C8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8008A6CC: lwc1        $f20, 0x7994($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X7994);
    // 0x8008A6D0: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    // 0x8008A6D4: swc1        $f16, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f16.u32l;
    // 0x8008A6D8: swc1        $f18, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f18.u32l;
    // 0x8008A6DC: swc1        $f4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f4.u32l;
L_8008A6E0:
    // 0x8008A6E0: mul.s       $f18, $f2, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8008A6E4: lui         $at, 0x437E
    ctx->r1 = S32(0X437E << 16);
    // 0x8008A6E8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8008A6EC: lwc1        $f16, 0x54($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8008A6F0: lui         $at, 0x4322
    ctx->r1 = S32(0X4322 << 16);
    // 0x8008A6F4: add.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x8008A6F8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8008A6FC: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8008A700: swc1        $f8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f8.u32l;
    // 0x8008A704: swc1        $f10, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f10.u32l;
    // 0x8008A708: b           L_8008A770
    // 0x8008A70C: swc1        $f4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f4.u32l;
        goto L_8008A770;
    // 0x8008A70C: swc1        $f4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f4.u32l;
L_8008A710:
    // 0x8008A710: lw          $t0, 0x7E7C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7E7C);
    // 0x8008A714: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8008A718: beq         $t0, $zero, L_8008A734
    if (ctx->r8 == 0) {
        // 0x8008A71C: nop
    
            goto L_8008A734;
    }
    // 0x8008A71C: nop

    // 0x8008A720: lw          $t1, -0x78B0($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X78B0);
    // 0x8008A724: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    // 0x8008A728: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8008A72C: beq         $t1, $zero, L_8008A73C
    if (ctx->r9 == 0) {
        // 0x8008A730: addiu       $s1, $s1, 0x1E10
        ctx->r17 = ADD32(ctx->r17, 0X1E10);
            goto L_8008A73C;
    }
    // 0x8008A730: addiu       $s1, $s1, 0x1E10
    ctx->r17 = ADD32(ctx->r17, 0X1E10);
L_8008A734:
    // 0x8008A734: b           L_8008AC3C
    // 0x8008A738: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008AC3C;
    // 0x8008A738: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008A73C:
    // 0x8008A73C: lwc1        $f6, 0x7998($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7998);
    // 0x8008A740: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8008A744: lwc1        $f20, 0x799C($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X799C);
    // 0x8008A748: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8008A74C: lwc1        $f8, 0x79A0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X79A0);
    // 0x8008A750: lui         $at, 0xC389
    ctx->r1 = S32(0XC389 << 16);
    // 0x8008A754: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8008A758: lui         $at, 0xC326
    ctx->r1 = S32(0XC326 << 16);
    // 0x8008A75C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8008A760: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    // 0x8008A764: swc1        $f8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f8.u32l;
    // 0x8008A768: swc1        $f10, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f10.u32l;
    // 0x8008A76C: swc1        $f16, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f16.u32l;
L_8008A770:
    // 0x8008A770: jal         0x8008A240
    // 0x8008A774: nop

    HUD_RadarMarks_Setup(rdram, ctx);
        goto after_1;
    // 0x8008A774: nop

    after_1:
    // 0x8008A778: lwc1        $f12, 0x48($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8008A77C: jal         0x8008A07C
    // 0x8008A780: lwc1        $f14, 0x44($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X44);
    HUD_RadarWindow_Draw(rdram, ctx);
        goto after_2;
    // 0x8008A780: lwc1        $f14, 0x44($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X44);
    after_2:
    // 0x8008A784: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x8008A788: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8008A78C: bne         $t2, $zero, L_8008AA90
    if (ctx->r10 != 0) {
        // 0x8008A790: nop
    
            goto L_8008AA90;
    }
    // 0x8008A790: nop

    // 0x8008A794: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
    // 0x8008A798: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    // 0x8008A79C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8008A7A0: beq         $v0, $at, L_8008A7D4
    if (ctx->r2 == ctx->r1) {
        // 0x8008A7A4: addiu       $a0, $a0, 0x7E64
        ctx->r4 = ADD32(ctx->r4, 0X7E64);
            goto L_8008A7D4;
    }
    // 0x8008A7A4: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8008A7A8: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x8008A7AC: beq         $v0, $at, L_8008A7D4
    if (ctx->r2 == ctx->r1) {
        // 0x8008A7B0: addiu       $at, $zero, 0x13
        ctx->r1 = ADD32(0, 0X13);
            goto L_8008A7D4;
    }
    // 0x8008A7B0: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x8008A7B4: beq         $v0, $at, L_8008A7D4
    if (ctx->r2 == ctx->r1) {
        // 0x8008A7B8: addiu       $at, $zero, 0x11
        ctx->r1 = ADD32(0, 0X11);
            goto L_8008A7D4;
    }
    // 0x8008A7B8: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x8008A7BC: beq         $v0, $at, L_8008A7D4
    if (ctx->r2 == ctx->r1) {
        // 0x8008A7C0: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_8008A7D4;
    }
    // 0x8008A7C0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8008A7C4: beq         $v0, $at, L_8008A7D4
    if (ctx->r2 == ctx->r1) {
        // 0x8008A7C8: addiu       $at, $zero, 0x10
        ctx->r1 = ADD32(0, 0X10);
            goto L_8008A7D4;
    }
    // 0x8008A7C8: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x8008A7CC: bne         $v0, $at, L_8008AA90
    if (ctx->r2 != ctx->r1) {
        // 0x8008A7D0: nop
    
            goto L_8008AA90;
    }
    // 0x8008A7D0: nop

L_8008A7D4:
    // 0x8008A7D4: jal         0x800B8DD0
    // 0x8008A7D8: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    RCP_SetupDL(rdram, ctx);
        goto after_3;
    // 0x8008A7D8: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    after_3:
    // 0x8008A7DC: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8008A7E0: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x8008A7E4: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8008A7E8: lui         $t5, 0x8080
    ctx->r13 = S32(0X8080 << 16);
    // 0x8008A7EC: ori         $t5, $t5, 0x80FF
    ctx->r13 = ctx->r13 | 0X80FF;
    // 0x8008A7F0: addiu       $t3, $v1, 0x8
    ctx->r11 = ADD32(ctx->r3, 0X8);
    // 0x8008A7F4: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x8008A7F8: lui         $t4, 0xFA00
    ctx->r12 = S32(0XFA00 << 16);
    // 0x8008A7FC: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x8008A800: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x8008A804: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8008A808: lw          $t6, -0x7DCC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7DCC);
    // 0x8008A80C: addiu       $t7, $t6, -0x5
    ctx->r15 = ADD32(ctx->r14, -0X5);
    // 0x8008A810: sltiu       $at, $t7, 0xF
    ctx->r1 = ctx->r15 < 0XF ? 1 : 0;
    // 0x8008A814: beq         $at, $zero, L_8008AA90
    if (ctx->r1 == 0) {
        // 0x8008A818: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_8008AA90;
    }
    // 0x8008A818: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8008A81C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8008A820: addu        $at, $at, $t7
    gpr jr_addend_8008A828 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8008A824: lw          $t7, 0x79A4($at)
    ctx->r15 = ADD32(ctx->r1, 0X79A4);
    // 0x8008A828: jr          $t7
    // 0x8008A82C: nop

    switch (jr_addend_8008A828 >> 2) {
        case 0: goto L_8008A920; break;
        case 1: goto L_8008AA90; break;
        case 2: goto L_8008AA90; break;
        case 3: goto L_8008AA90; break;
        case 4: goto L_8008AA90; break;
        case 5: goto L_8008AA90; break;
        case 6: goto L_8008AA90; break;
        case 7: goto L_8008AA90; break;
        case 8: goto L_8008AA90; break;
        case 9: goto L_8008A880; break;
        case 10: goto L_8008AA90; break;
        case 11: goto L_8008A9F8; break;
        case 12: goto L_8008A8D0; break;
        case 13: goto L_8008A830; break;
        case 14: goto L_8008AA48; break;
        default: switch_error(__func__, 0x8008A828, 0x800D79A4);
    }
    // 0x8008A82C: nop

L_8008A830:
    // 0x8008A830: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8008A834: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8008A838: lui         $at, 0x437B
    ctx->r1 = S32(0X437B << 16);
    // 0x8008A83C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8008A840: lwc1        $f4, 0x0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8008A844: lui         $at, 0x4335
    ctx->r1 = S32(0X4335 << 16);
    // 0x8008A848: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8008A84C: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8008A850: lui         $a1, 0x600
    ctx->r5 = S32(0X600 << 16);
    // 0x8008A854: addiu       $a1, $a1, 0x12D0
    ctx->r5 = ADD32(ctx->r5, 0X12D0);
    // 0x8008A858: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8008A85C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x8008A860: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x8008A864: addiu       $a3, $zero, 0x9
    ctx->r7 = ADD32(0, 0X9);
    // 0x8008A868: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x8008A86C: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x8008A870: jal         0x8009D994
    // 0x8008A874: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_4;
    // 0x8008A874: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_4:
    // 0x8008A878: b           L_8008AA90
    // 0x8008A87C: nop

        goto L_8008AA90;
    // 0x8008A87C: nop

L_8008A880:
    // 0x8008A880: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8008A884: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8008A888: lui         $at, 0x437B
    ctx->r1 = S32(0X437B << 16);
    // 0x8008A88C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8008A890: lwc1        $f16, 0x0($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8008A894: lui         $at, 0x4332
    ctx->r1 = S32(0X4332 << 16);
    // 0x8008A898: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8008A89C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8008A8A0: lui         $a1, 0x600
    ctx->r5 = S32(0X600 << 16);
    // 0x8008A8A4: addiu       $a1, $a1, 0x1260
    ctx->r5 = ADD32(ctx->r5, 0X1260);
    // 0x8008A8A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8008A8AC: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x8008A8B0: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x8008A8B4: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x8008A8B8: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x8008A8BC: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x8008A8C0: jal         0x8009D994
    // 0x8008A8C4: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_5;
    // 0x8008A8C4: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_5:
    // 0x8008A8C8: b           L_8008AA90
    // 0x8008A8CC: nop

        goto L_8008AA90;
    // 0x8008A8CC: nop

L_8008A8D0:
    // 0x8008A8D0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8008A8D4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8008A8D8: lui         $at, 0x437B
    ctx->r1 = S32(0X437B << 16);
    // 0x8008A8DC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8008A8E0: lwc1        $f8, 0x0($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8008A8E4: lui         $at, 0x4332
    ctx->r1 = S32(0X4332 << 16);
    // 0x8008A8E8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8008A8EC: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8008A8F0: lui         $a1, 0x600
    ctx->r5 = S32(0X600 << 16);
    // 0x8008A8F4: addiu       $a1, $a1, 0xC80
    ctx->r5 = ADD32(ctx->r5, 0XC80);
    // 0x8008A8F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8008A8FC: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x8008A900: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x8008A904: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x8008A908: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x8008A90C: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x8008A910: jal         0x8009D994
    // 0x8008A914: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_6;
    // 0x8008A914: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    after_6:
    // 0x8008A918: b           L_8008AA90
    // 0x8008A91C: nop

        goto L_8008AA90;
    // 0x8008A91C: nop

L_8008A920:
    // 0x8008A920: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8008A924: lw          $v0, -0x7D58($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D58);
    // 0x8008A928: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x8008A92C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8008A930: lwc1        $f18, 0x38($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8008A934: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8008A938: add.s       $f2, $f18, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8008A93C: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8008A940: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8008A944: nop

    // 0x8008A948: bc1f        L_8008AA90
    if (!c1cs) {
        // 0x8008A94C: nop
    
            goto L_8008AA90;
    }
    // 0x8008A94C: nop

    // 0x8008A950: lwc1        $f12, 0xC($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8008A954: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x8008A958: abs.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = fabsf(ctx->f12.fl);
    // 0x8008A95C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8008A960: nop

    // 0x8008A964: bc1f        L_8008AA90
    if (!c1cs) {
        // 0x8008A968: nop
    
            goto L_8008AA90;
    }
    // 0x8008A968: nop

    // 0x8008A96C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8008A970: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8008A974: lwc1        $f6, 0x79E0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X79E0);
    // 0x8008A978: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8008A97C: lwc1        $f10, 0x79E4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X79E4);
    // 0x8008A980: add.s       $f8, $f12, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f12.fl + ctx->f6.fl;
    // 0x8008A984: lwc1        $f14, 0x44($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8008A988: lui         $at, 0x434E
    ctx->r1 = S32(0X434E << 16);
    // 0x8008A98C: div.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8008A990: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    // 0x8008A994: nop

    // 0x8008A998: bc1t        L_8008AA90
    if (c1cs) {
        // 0x8008A99C: add.s       $f0, $f16, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f16.fl + ctx->f2.fl;
            goto L_8008AA90;
    }
    // 0x8008A99C: add.s       $f0, $f16, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x8008A9A0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8008A9A4: lui         $a1, 0x600
    ctx->r5 = S32(0X600 << 16);
    // 0x8008A9A8: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x8008A9AC: c.lt.s      $f18, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f18.fl < ctx->f14.fl;
    // 0x8008A9B0: addiu       $a1, $a1, 0x840
    ctx->r5 = ADD32(ctx->r5, 0X840);
    // 0x8008A9B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8008A9B8: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    // 0x8008A9BC: bc1t        L_8008AA90
    if (c1cs) {
        // 0x8008A9C0: nop
    
            goto L_8008AA90;
    }
    // 0x8008A9C0: nop

    // 0x8008A9C4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8008A9C8: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x8008A9CC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8008A9D0: lwc1        $f6, 0x0($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8008A9D4: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    // 0x8008A9D8: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x8008A9DC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8008A9E0: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    // 0x8008A9E4: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    // 0x8008A9E8: jal         0x8009D994
    // 0x8008A9EC: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_7;
    // 0x8008A9EC: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_7:
    // 0x8008A9F0: b           L_8008AA90
    // 0x8008A9F4: nop

        goto L_8008AA90;
    // 0x8008A9F4: nop

L_8008A9F8:
    // 0x8008A9F8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8008A9FC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8008AA00: lui         $at, 0x437E
    ctx->r1 = S32(0X437E << 16);
    // 0x8008AA04: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8008AA08: lwc1        $f16, 0x0($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8008AA0C: lui         $at, 0x4336
    ctx->r1 = S32(0X4336 << 16);
    // 0x8008AA10: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8008AA14: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8008AA18: lui         $a1, 0x600
    ctx->r5 = S32(0X600 << 16);
    // 0x8008AA1C: addiu       $a1, $a1, 0x1260
    ctx->r5 = ADD32(ctx->r5, 0X1260);
    // 0x8008AA20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8008AA24: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x8008AA28: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x8008AA2C: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    // 0x8008AA30: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x8008AA34: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x8008AA38: jal         0x8009D994
    // 0x8008AA3C: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_8;
    // 0x8008AA3C: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_8:
    // 0x8008AA40: b           L_8008AA90
    // 0x8008AA44: nop

        goto L_8008AA90;
    // 0x8008AA44: nop

L_8008AA48:
    // 0x8008AA48: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8008AA4C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8008AA50: lui         $at, 0x437B
    ctx->r1 = S32(0X437B << 16);
    // 0x8008AA54: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8008AA58: lwc1        $f8, 0x0($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8008AA5C: lui         $at, 0x4332
    ctx->r1 = S32(0X4332 << 16);
    // 0x8008AA60: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8008AA64: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8008AA68: lui         $a1, 0x600
    ctx->r5 = S32(0X600 << 16);
    // 0x8008AA6C: addiu       $a1, $a1, 0x2890
    ctx->r5 = ADD32(ctx->r5, 0X2890);
    // 0x8008AA70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8008AA74: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x8008AA78: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x8008AA7C: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x8008AA80: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x8008AA84: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x8008AA88: jal         0x8009D994
    // 0x8008AA8C: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_9;
    // 0x8008AA8C: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    after_9:
L_8008AA90:
    // 0x8008AA90: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x8008AA94: addiu       $s1, $s1, -0x4C40
    ctx->r17 = ADD32(ctx->r17, -0X4C40);
    // 0x8008AA98: jal         0x80005708
    // 0x8008AA9C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Push(rdram, ctx);
        goto after_10;
    // 0x8008AA9C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_10:
    // 0x8008AAA0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8008AAA4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8008AAA8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8008AAAC: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x8008AAB0: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x8008AAB4: jal         0x80005B00
    // 0x8008AAB8: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    Matrix_Translate(rdram, ctx);
        goto after_11;
    // 0x8008AAB8: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    after_11:
    // 0x8008AABC: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8008AAC0: lw          $t9, -0x7DCC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7DCC);
    // 0x8008AAC4: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    // 0x8008AAC8: lui         $s0, 0x8016
    ctx->r16 = S32(0X8016 << 16);
    // 0x8008AACC: bne         $t9, $at, L_8008AB04
    if (ctx->r25 != ctx->r1) {
        // 0x8008AAD0: addiu       $s0, $s0, 0x1710
        ctx->r16 = ADD32(ctx->r16, 0X1710);
            goto L_8008AB04;
    }
    // 0x8008AAD0: addiu       $s0, $s0, 0x1710
    ctx->r16 = ADD32(ctx->r16, 0X1710);
    // 0x8008AAD4: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x8008AAD8: beq         $t0, $zero, L_8008AB04
    if (ctx->r8 == 0) {
        // 0x8008AADC: nop
    
            goto L_8008AB04;
    }
    // 0x8008AADC: nop

    // 0x8008AAE0: jal         0x80005708
    // 0x8008AAE4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Push(rdram, ctx);
        goto after_12;
    // 0x8008AAE4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_12:
    // 0x8008AAE8: jal         0x80089D28
    // 0x8008AAEC: nop

    HUD_RadarMissileAlarm_Draw(rdram, ctx);
        goto after_13;
    // 0x8008AAEC: nop

    after_13:
    // 0x8008AAF0: jal         0x80005740
    // 0x8008AAF4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_14;
    // 0x8008AAF4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_14:
    // 0x8008AAF8: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x8008AAFC: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x8008AB00: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
L_8008AB04:
    // 0x8008AB04: lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // 0x8008AB08: addiu       $s0, $s0, 0x6410
    ctx->r16 = ADD32(ctx->r16, 0X6410);
    // 0x8008AB0C: lbu         $t3, 0x0($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X0);
L_8008AB10:
    // 0x8008AB10: lwc1        $f18, 0x38($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8008AB14: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x8008AB18: beq         $t3, $zero, L_8008AC18
    if (ctx->r11 == 0) {
        // 0x8008AB1C: nop
    
            goto L_8008AC18;
    }
    // 0x8008AB1C: nop

    // 0x8008AB20: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8008AB24: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8008AB28: add.s       $f2, $f18, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8008AB2C: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8008AB30: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8008AB34: nop

    // 0x8008AB38: bc1t        L_8008AC18
    if (c1cs) {
        // 0x8008AB3C: nop
    
            goto L_8008AC18;
    }
    // 0x8008AB3C: nop

    // 0x8008AB40: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8008AB44: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8008AB48: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8008AB4C: nop

    // 0x8008AB50: bc1t        L_8008AC18
    if (c1cs) {
        // 0x8008AB54: nop
    
            goto L_8008AC18;
    }
    // 0x8008AB54: nop

    // 0x8008AB58: jal         0x80005708
    // 0x8008AB5C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Push(rdram, ctx);
        goto after_15;
    // 0x8008AB5C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_15:
    // 0x8008AB60: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8008AB64: lwc1        $f0, 0x79E8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X79E8);
    // 0x8008AB68: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8008AB6C: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8008AB70: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8008AB74: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8008AB78: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x8008AB7C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8008AB80: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8008AB84: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8008AB88: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x8008AB8C: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8008AB90: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x8008AB94: jal         0x80005B00
    // 0x8008AB98: nop

    Matrix_Translate(rdram, ctx);
        goto after_16;
    // 0x8008AB98: nop

    after_16:
    // 0x8008AB9C: lhu         $t5, 0x2($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X2);
    // 0x8008ABA0: addiu       $at, $zero, 0x67
    ctx->r1 = ADD32(0, 0X67);
    // 0x8008ABA4: bne         $t5, $at, L_8008ABB8
    if (ctx->r13 != ctx->r1) {
        // 0x8008ABA8: lui         $at, 0x4234
        ctx->r1 = S32(0X4234 << 16);
            goto L_8008ABB8;
    }
    // 0x8008ABA8: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x8008ABAC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8008ABB0: nop

    // 0x8008ABB4: swc1        $f4, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f4.u32l;
L_8008ABB8:
    // 0x8008ABB8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8008ABBC: lwc1        $f8, 0x79EC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X79EC);
    // 0x8008ABC0: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8008ABC4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8008ABC8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8008ABCC: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8008ABD0: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8008ABD4: jal         0x80005FE0
    // 0x8008ABD8: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_17;
    // 0x8008ABD8: nop

    after_17:
    // 0x8008ABDC: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8008ABE0: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8008ABE4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8008ABE8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8008ABEC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8008ABF0: jal         0x80005C34
    // 0x8008ABF4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_18;
    // 0x8008ABF4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_18:
    // 0x8008ABF8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8008ABFC: jal         0x80006EB8
    // 0x8008AC00: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_19;
    // 0x8008AC00: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    after_19:
    // 0x8008AC04: jal         0x80089E98
    // 0x8008AC08: lhu         $a0, 0x2($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X2);
    HUD_RadarMark_Draw(rdram, ctx);
        goto after_20;
    // 0x8008AC08: lhu         $a0, 0x2($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X2);
    after_20:
    // 0x8008AC0C: jal         0x80005740
    // 0x8008AC10: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_21;
    // 0x8008AC10: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_21:
    // 0x8008AC14: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
L_8008AC18:
    // 0x8008AC18: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x8008AC1C: addiu       $t7, $t7, 0x5A10
    ctx->r15 = ADD32(ctx->r15, 0X5A10);
    // 0x8008AC20: addiu       $s0, $s0, -0x28
    ctx->r16 = ADD32(ctx->r16, -0X28);
    // 0x8008AC24: sltu        $at, $s0, $t7
    ctx->r1 = ctx->r16 < ctx->r15 ? 1 : 0;
    // 0x8008AC28: beql        $at, $zero, L_8008AB10
    if (ctx->r1 == 0) {
        // 0x8008AC2C: lbu         $t3, 0x0($s0)
        ctx->r11 = MEM_BU(ctx->r16, 0X0);
            goto L_8008AB10;
    }
    goto skip_1;
    // 0x8008AC2C: lbu         $t3, 0x0($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X0);
    skip_1:
    // 0x8008AC30: jal         0x80005740
    // 0x8008AC34: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_22;
    // 0x8008AC34: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_22:
    // 0x8008AC38: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008AC3C:
    // 0x8008AC3C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8008AC40: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8008AC44: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x8008AC48: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x8008AC4C: jr          $ra
    // 0x8008AC50: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8008AC50: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void PlayerShot_UpdateHitmark(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003AFD8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003AFDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003AFE0: lw          $t6, 0x60($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X60);
    // 0x8003AFE4: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8003AFE8: slti        $at, $t7, 0x3
    ctx->r1 = SIGNED(ctx->r15) < 0X3 ? 1 : 0;
    // 0x8003AFEC: bne         $at, $zero, L_8003AFFC
    if (ctx->r1 != 0) {
        // 0x8003AFF0: sw          $t7, 0x60($a0)
        MEM_W(0X60, ctx->r4) = ctx->r15;
            goto L_8003AFFC;
    }
    // 0x8003AFF0: sw          $t7, 0x60($a0)
    MEM_W(0X60, ctx->r4) = ctx->r15;
    // 0x8003AFF4: jal         0x80060FBC
    // 0x8003AFF8: addiu       $a1, $a0, 0x38
    ctx->r5 = ADD32(ctx->r4, 0X38);
    Object_Kill(rdram, ctx);
        goto after_0;
    // 0x8003AFF8: addiu       $a1, $a0, 0x38
    ctx->r5 = ADD32(ctx->r4, 0X38);
    after_0:
L_8003AFFC:
    // 0x8003AFFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003B000: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003B004: jr          $ra
    // 0x8003B008: nop

    return;
    // 0x8003B008: nop

;}
RECOMP_FUNC void Effect_WaterSpray_Setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007AC0C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007AC10: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8007AC14: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8007AC18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007AC1C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8007AC20: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8007AC24: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8007AC28: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8007AC2C: jal         0x80061474
    // 0x8007AC30: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    Effect_Initialize(rdram, ctx);
        goto after_0;
    // 0x8007AC30: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x8007AC34: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8007AC38: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8007AC3C: addiu       $t7, $zero, 0x174
    ctx->r15 = ADD32(0, 0X174);
    // 0x8007AC40: sb          $t6, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r14;
    // 0x8007AC44: sh          $t7, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r15;
    // 0x8007AC48: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8007AC4C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8007AC50: addiu       $t8, $zero, 0xB4
    ctx->r24 = ADD32(0, 0XB4);
    // 0x8007AC54: swc1        $f4, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f4.u32l;
    // 0x8007AC58: lwc1        $f6, 0x7940($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7940);
    // 0x8007AC5C: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8007AC60: addiu       $v0, $v0, -0x7D80
    ctx->r2 = ADD32(ctx->r2, -0X7D80);
    // 0x8007AC64: swc1        $f6, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f6.u32l;
    // 0x8007AC68: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8007AC6C: sh          $t8, 0x44($a2)
    MEM_H(0X44, ctx->r6) = ctx->r24;
    // 0x8007AC70: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007AC74: swc1        $f8, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f8.u32l;
    // 0x8007AC78: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8007AC7C: andi        $a1, $t7, 0xFFFF
    ctx->r5 = ctx->r15 & 0XFFFF;
    // 0x8007AC80: addiu       $a0, $a2, 0x1C
    ctx->r4 = ADD32(ctx->r6, 0X1C);
    // 0x8007AC84: swc1        $f10, 0x70($a2)
    MEM_W(0X70, ctx->r6) = ctx->f10.u32l;
    // 0x8007AC88: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8007AC8C: swc1        $f16, 0x6C($a2)
    MEM_W(0X6C, ctx->r6) = ctx->f16.u32l;
    // 0x8007AC90: lwc1        $f18, 0x30($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8007AC94: swc1        $f18, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->f18.u32l;
    // 0x8007AC98: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x8007AC9C: lwc1        $f6, 0x73B4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X73B4);
    // 0x8007ACA0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007ACA4: lwc1        $f4, 0xC0($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0XC0);
    // 0x8007ACA8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8007ACAC: swc1        $f8, 0x54($a2)
    MEM_W(0X54, ctx->r6) = ctx->f8.u32l;
    // 0x8007ACB0: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x8007ACB4: ldc1        $f18, 0x73B8($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, 0X73B8);
    // 0x8007ACB8: lwc1        $f10, 0xC8($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0XC8);
    // 0x8007ACBC: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8007ACC0: mul.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x8007ACC4: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8007ACC8: jal         0x800612B8
    // 0x8007ACCC: swc1        $f6, 0x5C($a2)
    MEM_W(0X5C, ctx->r6) = ctx->f6.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_1;
    // 0x8007ACCC: swc1        $f6, 0x5C($a2)
    MEM_W(0X5C, ctx->r6) = ctx->f6.u32l;
    after_1:
    // 0x8007ACD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007ACD4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007ACD8: jr          $ra
    // 0x8007ACDC: nop

    return;
    // 0x8007ACDC: nop

;}
RECOMP_FUNC void func_versus_800C04DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C04DC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800C04E0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800C04E4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800C04E8: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    // 0x800C04EC: swc1        $f14, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f14.u32l;
    // 0x800C04F0: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x800C04F4: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x800C04F8: lw          $t6, 0x78AC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X78AC);
    // 0x800C04FC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800C0500: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x800C0504: bne         $t6, $at, L_800C069C
    if (ctx->r14 != ctx->r1) {
        // 0x800C0508: lw          $t5, 0x50($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X50);
            goto L_800C069C;
    }
    // 0x800C0508: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x800C050C: lw          $t7, 0x4A98($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X4A98);
    // 0x800C0510: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800C0514: andi        $t8, $t7, 0x20
    ctx->r24 = ctx->r15 & 0X20;
    // 0x800C0518: beql        $t8, $zero, L_800C06A0
    if (ctx->r24 == 0) {
        // 0x800C051C: slti        $at, $t5, 0x4
        ctx->r1 = SIGNED(ctx->r13) < 0X4 ? 1 : 0;
            goto L_800C06A0;
    }
    goto skip_0;
    // 0x800C051C: slti        $at, $t5, 0x4
    ctx->r1 = SIGNED(ctx->r13) < 0X4 ? 1 : 0;
    skip_0:
    // 0x800C0520: lw          $t9, -0x7858($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7858);
    // 0x800C0524: addiu       $at, $zero, 0x63
    ctx->r1 = ADD32(0, 0X63);
    // 0x800C0528: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800C052C: beq         $t9, $at, L_800C069C
    if (ctx->r25 == ctx->r1) {
        // 0x800C0530: addiu       $s0, $s0, 0x7E64
        ctx->r16 = ADD32(ctx->r16, 0X7E64);
            goto L_800C069C;
    }
    // 0x800C0530: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x800C0534: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C0538: jal         0x800B8DD0
    // 0x800C053C: addiu       $a1, $zero, 0x4E
    ctx->r5 = ADD32(0, 0X4E);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x800C053C: addiu       $a1, $zero, 0x4E
    ctx->r5 = ADD32(0, 0X4E);
    after_0:
    // 0x800C0540: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800C0544: lui         $t1, 0xFA00
    ctx->r9 = S32(0XFA00 << 16);
    // 0x800C0548: addiu       $t2, $zero, 0xC8
    ctx->r10 = ADD32(0, 0XC8);
    // 0x800C054C: addiu       $t0, $v0, 0x8
    ctx->r8 = ADD32(ctx->r2, 0X8);
    // 0x800C0550: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x800C0554: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x800C0558: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x800C055C: lui         $at, 0x42C4
    ctx->r1 = S32(0X42C4 << 16);
    // 0x800C0560: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800C0564: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800C0568: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800C056C: lui         $a2, 0x40A6
    ctx->r6 = S32(0X40A6 << 16);
    // 0x800C0570: lui         $a3, 0x403E
    ctx->r7 = S32(0X403E << 16);
    // 0x800C0574: ori         $a3, $a3, 0xB852
    ctx->r7 = ctx->r7 | 0XB852;
    // 0x800C0578: jal         0x800BCFFC
    // 0x800C057C: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    func_versus_800BCFFC(rdram, ctx);
        goto after_1;
    // 0x800C057C: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    after_1:
    // 0x800C0580: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C0584: jal         0x800B8DD0
    // 0x800C0588: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    RCP_SetupDL(rdram, ctx);
        goto after_2;
    // 0x800C0588: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    after_2:
    // 0x800C058C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C0590: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800C0594: lui         $t4, 0xFA00
    ctx->r12 = S32(0XFA00 << 16);
    // 0x800C0598: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800C059C: lui         $t5, 0xFFFF
    ctx->r13 = S32(0XFFFF << 16);
    // 0x800C05A0: ori         $t5, $t5, 0xFF
    ctx->r13 = ctx->r13 | 0XFF;
    // 0x800C05A4: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x800C05A8: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x800C05AC: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x800C05B0: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x800C05B4: lui         $at, 0x42EC
    ctx->r1 = S32(0X42EC << 16);
    // 0x800C05B8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800C05BC: lui         $at, 0x42DC
    ctx->r1 = S32(0X42DC << 16);
    // 0x800C05C0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800C05C4: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800C05C8: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800C05CC: addiu       $t8, $t8, -0x6DB0
    ctx->r24 = ADD32(ctx->r24, -0X6DB0);
    // 0x800C05D0: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800C05D4: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x800C05D8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800C05DC: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800C05E0: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x800C05E4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800C05E8: jal         0x800A1200
    // 0x800C05EC: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    Graphics_DisplaySmallText(rdram, ctx);
        goto after_3;
    // 0x800C05EC: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    after_3:
    // 0x800C05F0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C05F4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800C05F8: lui         $at, 0x42EC
    ctx->r1 = S32(0X42EC << 16);
    // 0x800C05FC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800C0600: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x800C0604: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800C0608: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800C060C: addiu       $t0, $t0, -0x6DA8
    ctx->r8 = ADD32(ctx->r8, -0X6DA8);
    // 0x800C0610: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800C0614: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800C0618: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800C061C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x800C0620: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800C0624: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x800C0628: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x800C062C: jal         0x800A1200
    // 0x800C0630: nop

    Graphics_DisplaySmallText(rdram, ctx);
        goto after_4;
    // 0x800C0630: nop

    after_4:
    // 0x800C0634: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800C0638: lui         $t2, 0xFA00
    ctx->r10 = S32(0XFA00 << 16);
    // 0x800C063C: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x800C0640: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x800C0644: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x800C0648: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x800C064C: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x800C0650: lui         $at, 0x42EC
    ctx->r1 = S32(0X42EC << 16);
    // 0x800C0654: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800C0658: lui         $at, 0x4190
    ctx->r1 = S32(0X4190 << 16);
    // 0x800C065C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800C0660: lui         $at, 0x42DC
    ctx->r1 = S32(0X42DC << 16);
    // 0x800C0664: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800C0668: add.s       $f12, $f18, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x800C066C: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x800C0670: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800C0674: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x800C0678: addiu       $t4, $zero, 0x270F
    ctx->r12 = ADD32(0, 0X270F);
    // 0x800C067C: add.s       $f14, $f10, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800C0680: lw          $a2, 0x4A94($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X4A94);
    // 0x800C0684: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x800C0688: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800C068C: jal         0x800869A0
    // 0x800C0690: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    HUD_Number_Draw(rdram, ctx);
        goto after_5;
    // 0x800C0690: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    after_5:
    // 0x800C0694: b           L_800C0748
    // 0x800C0698: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800C0748;
    // 0x800C0698: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800C069C:
    // 0x800C069C: slti        $at, $t5, 0x4
    ctx->r1 = SIGNED(ctx->r13) < 0X4 ? 1 : 0;
L_800C06A0:
    // 0x800C06A0: beq         $at, $zero, L_800C0700
    if (ctx->r1 == 0) {
        // 0x800C06A4: lui         $s0, 0x8013
        ctx->r16 = S32(0X8013 << 16);
            goto L_800C0700;
    }
    // 0x800C06A4: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800C06A8: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800C06AC: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x800C06B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C06B4: jal         0x800B8DD0
    // 0x800C06B8: addiu       $a1, $zero, 0x4E
    ctx->r5 = ADD32(0, 0X4E);
    RCP_SetupDL(rdram, ctx);
        goto after_6;
    // 0x800C06B8: addiu       $a1, $zero, 0x4E
    ctx->r5 = ADD32(0, 0X4E);
    after_6:
    // 0x800C06BC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800C06C0: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x800C06C4: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x800C06C8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800C06CC: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800C06D0: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800C06D4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800C06D8: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x800C06DC: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800C06E0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800C06E4: lwc1        $f12, 0x48($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800C06E8: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    // 0x800C06EC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x800C06F0: jal         0x800BCC48
    // 0x800C06F4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    func_versus_800BCC48(rdram, ctx);
        goto after_7;
    // 0x800C06F4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_7:
    // 0x800C06F8: b           L_800C0748
    // 0x800C06FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800C0748;
    // 0x800C06FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800C0700:
    // 0x800C0700: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x800C0704: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C0708: jal         0x800B8DD0
    // 0x800C070C: addiu       $a1, $zero, 0x4E
    ctx->r5 = ADD32(0, 0X4E);
    RCP_SetupDL(rdram, ctx);
        goto after_8;
    // 0x800C070C: addiu       $a1, $zero, 0x4E
    ctx->r5 = ADD32(0, 0X4E);
    after_8:
    // 0x800C0710: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800C0714: lui         $t1, 0xFA00
    ctx->r9 = S32(0XFA00 << 16);
    // 0x800C0718: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x800C071C: addiu       $t0, $v0, 0x8
    ctx->r8 = ADD32(ctx->r2, 0X8);
    // 0x800C0720: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x800C0724: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x800C0728: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x800C072C: lui         $at, 0x42D0
    ctx->r1 = S32(0X42D0 << 16);
    // 0x800C0730: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800C0734: lwc1        $f12, 0x48($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800C0738: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    // 0x800C073C: jal         0x800BCE24
    // 0x800C0740: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_versus_800BCE24(rdram, ctx);
        goto after_9;
    // 0x800C0740: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_9:
    // 0x800C0744: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800C0748:
    // 0x800C0748: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800C074C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800C0750: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x800C0754: jr          $ra
    // 0x800C0758: nop

    return;
    // 0x800C0758: nop

;}
RECOMP_FUNC void guLookAtF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800211D0: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800211D4: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x800211D8: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x800211DC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800211E0: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x800211E4: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x800211E8: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x800211EC: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x800211F0: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x800211F4: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x800211F8: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x800211FC: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x80021200: jal         0x80026DD0
    // 0x80021204: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    guMtxIdentF(rdram, ctx);
        goto after_0;
    // 0x80021204: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80021208: lwc1        $f4, 0x60($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8002120C: lwc1        $f6, 0x54($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80021210: lwc1        $f8, 0x64($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80021214: lwc1        $f10, 0x58($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80021218: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8002121C: lwc1        $f6, 0x5C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80021220: lwc1        $f4, 0x68($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80021224: sub.s       $f22, $f8, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f22.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80021228: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8002122C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80021230: sub.s       $f24, $f4, $f6
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f24.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80021234: mul.s       $f10, $f22, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x80021238: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8002123C: mul.s       $f6, $f24, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = MUL_S(ctx->f24.fl, ctx->f24.fl);
    // 0x80021240: jal         0x800233C0
    // 0x80021244: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    guSqrtf(rdram, ctx);
        goto after_1;
    // 0x80021244: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_1:
    // 0x80021248: lui         $at, 0xBFF0
    ctx->r1 = S32(0XBFF0 << 16);
    // 0x8002124C: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80021250: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80021254: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x80021258: lwc1        $f6, 0x70($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8002125C: div.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = DIV_D(ctx->f8.d, ctx->f10.d);
    // 0x80021260: lwc1        $f10, 0x74($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80021264: cvt.s.d     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f2.fl = CVT_S_D(ctx->f4.d);
    // 0x80021268: mul.s       $f20, $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f2.fl);
    // 0x8002126C: nop

    // 0x80021270: mul.s       $f22, $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f22.fl = MUL_S(ctx->f22.fl, ctx->f2.fl);
    // 0x80021274: nop

    // 0x80021278: mul.s       $f24, $f24, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f24.fl = MUL_S(ctx->f24.fl, ctx->f2.fl);
    // 0x8002127C: nop

    // 0x80021280: mul.s       $f8, $f6, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f24.fl);
    // 0x80021284: nop

    // 0x80021288: mul.s       $f4, $f10, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f22.fl);
    // 0x8002128C: sub.s       $f26, $f8, $f4
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f26.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x80021290: mul.s       $f8, $f10, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x80021294: lwc1        $f4, 0x6C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80021298: mul.s       $f10, $f4, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f24.fl);
    // 0x8002129C: sub.s       $f28, $f8, $f10
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f28.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800212A0: mul.s       $f8, $f4, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f22.fl);
    // 0x800212A4: nop

    // 0x800212A8: mul.s       $f10, $f6, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x800212AC: sub.s       $f30, $f8, $f10
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f30.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800212B0: mul.s       $f4, $f26, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = MUL_S(ctx->f26.fl, ctx->f26.fl);
    // 0x800212B4: nop

    // 0x800212B8: mul.s       $f6, $f28, $f28
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f6.fl = MUL_S(ctx->f28.fl, ctx->f28.fl);
    // 0x800212BC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800212C0: mul.s       $f10, $f30, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f10.fl = MUL_S(ctx->f30.fl, ctx->f30.fl);
    // 0x800212C4: jal         0x800233C0
    // 0x800212C8: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    guSqrtf(rdram, ctx);
        goto after_2;
    // 0x800212C8: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_2:
    // 0x800212CC: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800212D0: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800212D4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800212D8: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x800212DC: div.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = DIV_D(ctx->f4.d, ctx->f6.d);
    // 0x800212E0: cvt.s.d     $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f2.fl = CVT_S_D(ctx->f8.d);
    // 0x800212E4: mul.s       $f26, $f26, $f2
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f26.fl = MUL_S(ctx->f26.fl, ctx->f2.fl);
    // 0x800212E8: nop

    // 0x800212EC: mul.s       $f28, $f28, $f2
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f28.fl = MUL_S(ctx->f28.fl, ctx->f2.fl);
    // 0x800212F0: nop

    // 0x800212F4: mul.s       $f30, $f30, $f2
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f30.fl = MUL_S(ctx->f30.fl, ctx->f2.fl);
    // 0x800212F8: nop

    // 0x800212FC: mul.s       $f10, $f22, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f30.fl);
    // 0x80021300: nop

    // 0x80021304: mul.s       $f4, $f24, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f4.fl = MUL_S(ctx->f24.fl, ctx->f28.fl);
    // 0x80021308: nop

    // 0x8002130C: mul.s       $f6, $f24, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = MUL_S(ctx->f24.fl, ctx->f26.fl);
    // 0x80021310: nop

    // 0x80021314: mul.s       $f8, $f20, $f30
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f30.fl);
    // 0x80021318: sub.s       $f14, $f10, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x8002131C: mul.s       $f10, $f20, $f28
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f10.fl = MUL_S(ctx->f20.fl, ctx->f28.fl);
    // 0x80021320: nop

    // 0x80021324: mul.s       $f4, $f22, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f26.fl);
    // 0x80021328: swc1        $f14, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f14.u32l;
    // 0x8002132C: sub.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80021330: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80021334: nop

    // 0x80021338: mul.s       $f8, $f16, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x8002133C: swc1        $f16, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f16.u32l;
    // 0x80021340: sub.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80021344: mul.s       $f4, $f18, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x80021348: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8002134C: swc1        $f18, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f18.u32l;
    // 0x80021350: jal         0x800233C0
    // 0x80021354: add.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f4.fl;
    guSqrtf(rdram, ctx);
        goto after_3;
    // 0x80021354: add.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f4.fl;
    after_3:
    // 0x80021358: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8002135C: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80021360: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80021364: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x80021368: lwc1        $f14, 0x6C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8002136C: div.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = DIV_D(ctx->f6.d, ctx->f8.d);
    // 0x80021370: lwc1        $f12, 0x70($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80021374: lwc1        $f4, 0x74($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80021378: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8002137C: cvt.s.d     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f2.fl = CVT_S_D(ctx->f10.d);
    // 0x80021380: mul.s       $f14, $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x80021384: nop

    // 0x80021388: mul.s       $f12, $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f2.fl);
    // 0x8002138C: nop

    // 0x80021390: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80021394: swc1        $f6, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f6.u32l;
    // 0x80021398: swc1        $f26, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f26.u32l;
    // 0x8002139C: swc1        $f28, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f28.u32l;
    // 0x800213A0: swc1        $f30, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f30.u32l;
    // 0x800213A4: lwc1        $f8, 0x54($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800213A8: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800213AC: mul.s       $f10, $f8, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f26.fl);
    // 0x800213B0: nop

    // 0x800213B4: mul.s       $f6, $f4, $f28
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f28.fl);
    // 0x800213B8: lwc1        $f4, 0x5C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800213BC: swc1        $f14, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f14.u32l;
    // 0x800213C0: swc1        $f12, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f12.u32l;
    // 0x800213C4: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800213C8: mul.s       $f10, $f4, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f30.fl);
    // 0x800213CC: add.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800213D0: neg.s       $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = -ctx->f6.fl;
    // 0x800213D4: swc1        $f4, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f4.u32l;
    // 0x800213D8: lwc1        $f0, 0x74($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800213DC: swc1        $f12, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f12.u32l;
    // 0x800213E0: swc1        $f14, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f14.u32l;
    // 0x800213E4: lwc1        $f14, 0x54($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800213E8: lwc1        $f12, 0x58($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800213EC: lwc1        $f2, 0x5C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800213F0: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x800213F4: lwc1        $f8, 0x6C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800213F8: lwc1        $f6, 0x70($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800213FC: swc1        $f20, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f20.u32l;
    // 0x80021400: mul.s       $f10, $f14, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f8.fl);
    // 0x80021404: swc1        $f22, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f22.u32l;
    // 0x80021408: swc1        $f24, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f24.u32l;
    // 0x8002140C: mul.s       $f4, $f12, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f6.fl);
    // 0x80021410: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80021414: mul.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80021418: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8002141C: nop

    // 0x80021420: swc1        $f0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f0.u32l;
    // 0x80021424: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    // 0x80021428: swc1        $f0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f0.u32l;
    // 0x8002142C: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80021430: mul.s       $f8, $f14, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f20.fl);
    // 0x80021434: nop

    // 0x80021438: mul.s       $f6, $f12, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f22.fl);
    // 0x8002143C: neg.s       $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = -ctx->f10.fl;
    // 0x80021440: swc1        $f4, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f4.u32l;
    // 0x80021444: mul.s       $f4, $f2, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f24.fl);
    // 0x80021448: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8002144C: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80021450: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80021454: neg.s       $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = -ctx->f8.fl;
    // 0x80021458: swc1        $f10, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f10.u32l;
    // 0x8002145C: swc1        $f6, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f6.u32l;
    // 0x80021460: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80021464: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x80021468: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x8002146C: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x80021470: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x80021474: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80021478: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8002147C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80021480: jr          $ra
    // 0x80021484: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80021484: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void AudioThread_SetFadeInTimer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E778: beq         $a1, $zero, L_8001E7C0
    if (ctx->r5 == 0) {
        // 0x8001E77C: sll         $t6, $a0, 2
        ctx->r14 = S32(ctx->r4 << 2);
            goto L_8001E7C0;
    }
    // 0x8001E77C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8001E780: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x8001E784: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8001E788: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x8001E78C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8001E790: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x8001E794: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x8001E798: addiu       $t7, $t7, -0x1AC8
    ctx->r15 = ADD32(ctx->r15, -0X1AC8);
    // 0x8001E79C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8001E7A0: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x8001E7A4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8001E7A8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8001E7AC: sb          $t8, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r24;
    // 0x8001E7B0: sh          $a1, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r5;
    // 0x8001E7B4: sh          $a1, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r5;
    // 0x8001E7B8: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x8001E7BC: swc1        $f0, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f0.u32l;
L_8001E7C0:
    // 0x8001E7C0: jr          $ra
    // 0x8001E7C4: nop

    return;
    // 0x8001E7C4: nop

;}
RECOMP_FUNC void ActorAllRange_UpdateEnemyEvents(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002FC00: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8002FC04: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8002FC08: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8002FC0C: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8002FC10: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8002FC14: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8002FC18: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8002FC1C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8002FC20: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8002FC24: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8002FC28: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8002FC2C: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8002FC30: lui         $s1, 0x8016
    ctx->r17 = S32(0X8016 << 16);
    // 0x8002FC34: lui         $fp, 0x800D
    ctx->r30 = S32(0X800D << 16);
    // 0x8002FC38: lui         $s3, 0x8016
    ctx->r19 = S32(0X8016 << 16);
    // 0x8002FC3C: addiu       $s3, $s3, 0x3FE0
    ctx->r19 = ADD32(ctx->r19, 0X3FE0);
    // 0x8002FC40: addiu       $fp, $fp, -0x5DCC
    ctx->r30 = ADD32(ctx->r30, -0X5DCC);
    // 0x8002FC44: addiu       $s1, $s1, 0x5D68
    ctx->r17 = ADD32(ctx->r17, 0X5D68);
    // 0x8002FC48: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x8002FC4C: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
    // 0x8002FC50: addiu       $s6, $zero, 0x3
    ctx->r22 = ADD32(0, 0X3);
    // 0x8002FC54: addiu       $s4, $zero, 0x2F4
    ctx->r20 = ADD32(0, 0X2F4);
    // 0x8002FC58: addiu       $s2, $zero, 0x33
    ctx->r18 = ADD32(0, 0X33);
    // 0x8002FC5C: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
L_8002FC60:
    // 0x8002FC60: lbu         $t6, 0x0($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X0);
    // 0x8002FC64: bnel        $s6, $t6, L_8002FE38
    if (ctx->r22 != ctx->r14) {
        // 0x8002FC68: addiu       $s5, $s5, 0x1
        ctx->r21 = ADD32(ctx->r21, 0X1);
            goto L_8002FE38;
    }
    goto skip_0;
    // 0x8002FC68: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    skip_0:
    // 0x8002FC6C: lh          $a1, 0xE6($s1)
    ctx->r5 = MEM_H(ctx->r17, 0XE6);
    // 0x8002FC70: blez        $a1, L_8002FE34
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8002FC74: slti        $at, $a1, 0x4
        ctx->r1 = SIGNED(ctx->r5) < 0X4 ? 1 : 0;
            goto L_8002FE34;
    }
    // 0x8002FC74: slti        $at, $a1, 0x4
    ctx->r1 = SIGNED(ctx->r5) < 0X4 ? 1 : 0;
    // 0x8002FC78: beq         $at, $zero, L_8002FE34
    if (ctx->r1 == 0) {
        // 0x8002FC7C: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8002FE34;
    }
    // 0x8002FC7C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8002FC80: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8002FC84: addiu       $v0, $v0, 0x5D68
    ctx->r2 = ADD32(ctx->r2, 0X5D68);
L_8002FC88:
    // 0x8002FC88: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x8002FC8C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8002FC90: bne         $s0, $t7, L_8002FCB0
    if (ctx->r16 != ctx->r15) {
        // 0x8002FC94: nop
    
            goto L_8002FCB0;
    }
    // 0x8002FC94: nop

    // 0x8002FC98: lh          $t8, 0xB8($v0)
    ctx->r24 = MEM_H(ctx->r2, 0XB8);
    // 0x8002FC9C: bne         $s0, $t8, L_8002FCB0
    if (ctx->r16 != ctx->r24) {
        // 0x8002FCA0: nop
    
            goto L_8002FCB0;
    }
    // 0x8002FCA0: nop

    // 0x8002FCA4: lh          $t9, 0xE6($v0)
    ctx->r25 = MEM_H(ctx->r2, 0XE6);
    // 0x8002FCA8: beql        $a1, $t9, L_8002FE48
    if (ctx->r5 == ctx->r25) {
        // 0x8002FCAC: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_8002FE48;
    }
    goto skip_1;
    // 0x8002FCAC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_1:
L_8002FCB0:
    // 0x8002FCB0: bne         $v1, $s2, L_8002FC88
    if (ctx->r3 != ctx->r18) {
        // 0x8002FCB4: addiu       $v0, $v0, 0x2F4
        ctx->r2 = ADD32(ctx->r2, 0X2F4);
            goto L_8002FC88;
    }
    // 0x8002FCB4: addiu       $v0, $v0, 0x2F4
    ctx->r2 = ADD32(ctx->r2, 0X2F4);
    // 0x8002FCB8: sll         $t0, $a1, 2
    ctx->r8 = S32(ctx->r5 << 2);
    // 0x8002FCBC: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x8002FCC0: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8002FCC4: lw          $t1, 0x78B0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X78B0);
    // 0x8002FCC8: blezl       $t1, L_8002FE38
    if (SIGNED(ctx->r9) <= 0) {
        // 0x8002FCCC: addiu       $s5, $s5, 0x1
        ctx->r21 = ADD32(ctx->r21, 0X1);
            goto L_8002FE38;
    }
    goto skip_2;
    // 0x8002FCCC: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    skip_2:
    // 0x8002FCD0: multu       $a1, $s4
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002FCD4: mflo        $t2
    ctx->r10 = lo;
    // 0x8002FCD8: addu        $a0, $s3, $t2
    ctx->r4 = ADD32(ctx->r19, ctx->r10);
    // 0x8002FCDC: jal         0x8002FB4C
    // 0x8002FCE0: nop

    ActorAllRange_ChooseNewTarget(rdram, ctx);
        goto after_0;
    // 0x8002FCE0: nop

    after_0:
    // 0x8002FCE4: lw          $t3, 0x64($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X64);
    // 0x8002FCE8: beql        $t3, $zero, L_8002FE38
    if (ctx->r11 == 0) {
        // 0x8002FCEC: addiu       $s5, $s5, 0x1
        ctx->r21 = ADD32(ctx->r21, 0X1);
            goto L_8002FE38;
    }
    goto skip_3;
    // 0x8002FCEC: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    skip_3:
    // 0x8002FCF0: lh          $t4, 0xD4($s1)
    ctx->r12 = MEM_H(ctx->r17, 0XD4);
    // 0x8002FCF4: bnel        $s7, $t4, L_8002FE38
    if (ctx->r23 != ctx->r12) {
        // 0x8002FCF8: addiu       $s5, $s5, 0x1
        ctx->r21 = ADD32(ctx->r21, 0X1);
            goto L_8002FE38;
    }
    goto skip_4;
    // 0x8002FCF8: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    skip_4:
    // 0x8002FCFC: lh          $t5, 0xE6($s1)
    ctx->r13 = MEM_H(ctx->r17, 0XE6);
    // 0x8002FD00: multu       $t5, $s4
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002FD04: mflo        $t6
    ctx->r14 = lo;
    // 0x8002FD08: addu        $v0, $s3, $t6
    ctx->r2 = ADD32(ctx->r19, ctx->r14);
    // 0x8002FD0C: lw          $t7, 0x5C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X5C);
    // 0x8002FD10: bnel        $t7, $zero, L_8002FE38
    if (ctx->r15 != 0) {
        // 0x8002FD14: addiu       $s5, $s5, 0x1
        ctx->r21 = ADD32(ctx->r21, 0X1);
            goto L_8002FE38;
    }
    goto skip_5;
    // 0x8002FD14: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    skip_5:
    // 0x8002FD18: lw          $t8, 0x0($fp)
    ctx->r24 = MEM_W(ctx->r30, 0X0);
    // 0x8002FD1C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002FD20: bnel        $t8, $v0, L_8002FD58
    if (ctx->r24 != ctx->r2) {
        // 0x8002FD24: lh          $v1, 0xE4($v0)
        ctx->r3 = MEM_H(ctx->r2, 0XE4);
            goto L_8002FD58;
    }
    goto skip_6;
    // 0x8002FD24: lh          $v1, 0xE4($v0)
    ctx->r3 = MEM_H(ctx->r2, 0XE4);
    skip_6:
    // 0x8002FD28: sw          $zero, 0x0($fp)
    MEM_W(0X0, ctx->r30) = 0;
    // 0x8002FD2C: sw          $zero, -0x5DC8($at)
    MEM_W(-0X5DC8, ctx->r1) = 0;
    // 0x8002FD30: lh          $t9, 0xE6($s1)
    ctx->r25 = MEM_H(ctx->r17, 0XE6);
    // 0x8002FD34: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8002FD38: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x8002FD3C: sll         $t0, $t0, 4
    ctx->r8 = S32(ctx->r8 << 4);
    // 0x8002FD40: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x8002FD44: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8002FD48: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8002FD4C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8002FD50: addu        $v0, $s3, $t0
    ctx->r2 = ADD32(ctx->r19, ctx->r8);
    // 0x8002FD54: lh          $v1, 0xE4($v0)
    ctx->r3 = MEM_H(ctx->r2, 0XE4);
L_8002FD58:
    // 0x8002FD58: beq         $v1, $s7, L_8002FD78
    if (ctx->r3 == ctx->r23) {
        // 0x8002FD5C: nop
    
            goto L_8002FD78;
    }
    // 0x8002FD5C: nop

    // 0x8002FD60: beq         $v1, $s0, L_8002FDB0
    if (ctx->r3 == ctx->r16) {
        // 0x8002FD64: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_8002FDB0;
    }
    // 0x8002FD64: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8002FD68: beq         $v1, $s6, L_8002FDE4
    if (ctx->r3 == ctx->r22) {
        // 0x8002FD6C: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_8002FDE4;
    }
    // 0x8002FD6C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8002FD70: b           L_8002FE18
    // 0x8002FD74: addiu       $t7, $zero, 0xC8
    ctx->r15 = ADD32(0, 0XC8);
        goto L_8002FE18;
    // 0x8002FD74: addiu       $t7, $zero, 0xC8
    ctx->r15 = ADD32(0, 0XC8);
L_8002FD78:
    // 0x8002FD78: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8002FD7C: addiu       $a0, $a0, -0x14BC
    ctx->r4 = ADD32(ctx->r4, -0X14BC);
    // 0x8002FD80: jal         0x8002F5F4
    // 0x8002FD84: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    ActorAllRange_PlayMessage(rdram, ctx);
        goto after_1;
    // 0x8002FD84: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_1:
    // 0x8002FD88: lh          $t1, 0xE6($s1)
    ctx->r9 = MEM_H(ctx->r17, 0XE6);
    // 0x8002FD8C: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8002FD90: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x8002FD94: sll         $t2, $t2, 4
    ctx->r10 = S32(ctx->r10 << 4);
    // 0x8002FD98: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x8002FD9C: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8002FDA0: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8002FDA4: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8002FDA8: b           L_8002FE14
    // 0x8002FDAC: addu        $v0, $s3, $t2
    ctx->r2 = ADD32(ctx->r19, ctx->r10);
        goto L_8002FE14;
    // 0x8002FDAC: addu        $v0, $s3, $t2
    ctx->r2 = ADD32(ctx->r19, ctx->r10);
L_8002FDB0:
    // 0x8002FDB0: addiu       $a0, $a0, -0x1464
    ctx->r4 = ADD32(ctx->r4, -0X1464);
    // 0x8002FDB4: jal         0x8002F5F4
    // 0x8002FDB8: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    ActorAllRange_PlayMessage(rdram, ctx);
        goto after_2;
    // 0x8002FDB8: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_2:
    // 0x8002FDBC: lh          $t3, 0xE6($s1)
    ctx->r11 = MEM_H(ctx->r17, 0XE6);
    // 0x8002FDC0: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8002FDC4: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x8002FDC8: sll         $t4, $t4, 4
    ctx->r12 = S32(ctx->r12 << 4);
    // 0x8002FDCC: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x8002FDD0: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8002FDD4: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8002FDD8: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8002FDDC: b           L_8002FE14
    // 0x8002FDE0: addu        $v0, $s3, $t4
    ctx->r2 = ADD32(ctx->r19, ctx->r12);
        goto L_8002FE14;
    // 0x8002FDE0: addu        $v0, $s3, $t4
    ctx->r2 = ADD32(ctx->r19, ctx->r12);
L_8002FDE4:
    // 0x8002FDE4: addiu       $a0, $a0, -0x142C
    ctx->r4 = ADD32(ctx->r4, -0X142C);
    // 0x8002FDE8: jal         0x8002F5F4
    // 0x8002FDEC: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    ActorAllRange_PlayMessage(rdram, ctx);
        goto after_3;
    // 0x8002FDEC: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_3:
    // 0x8002FDF0: lh          $t5, 0xE6($s1)
    ctx->r13 = MEM_H(ctx->r17, 0XE6);
    // 0x8002FDF4: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8002FDF8: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x8002FDFC: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x8002FE00: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x8002FE04: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8002FE08: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8002FE0C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8002FE10: addu        $v0, $s3, $t6
    ctx->r2 = ADD32(ctx->r19, ctx->r14);
L_8002FE14:
    // 0x8002FE14: addiu       $t7, $zero, 0xC8
    ctx->r15 = ADD32(0, 0XC8);
L_8002FE18:
    // 0x8002FE18: sw          $t7, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->r15;
    // 0x8002FE1C: lh          $t9, 0xE6($s1)
    ctx->r25 = MEM_H(ctx->r17, 0XE6);
    // 0x8002FE20: addiu       $t8, $zero, 0x258
    ctx->r24 = ADD32(0, 0X258);
    // 0x8002FE24: multu       $t9, $s4
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002FE28: mflo        $t0
    ctx->r8 = lo;
    // 0x8002FE2C: addu        $t1, $s3, $t0
    ctx->r9 = ADD32(ctx->r19, ctx->r8);
    // 0x8002FE30: sh          $t8, 0xC4($t1)
    MEM_H(0XC4, ctx->r9) = ctx->r24;
L_8002FE34:
    // 0x8002FE34: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
L_8002FE38:
    // 0x8002FE38: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x8002FE3C: bne         $s5, $at, L_8002FC60
    if (ctx->r21 != ctx->r1) {
        // 0x8002FE40: addiu       $s1, $s1, 0x2F4
        ctx->r17 = ADD32(ctx->r17, 0X2F4);
            goto L_8002FC60;
    }
    // 0x8002FE40: addiu       $s1, $s1, 0x2F4
    ctx->r17 = ADD32(ctx->r17, 0X2F4);
    // 0x8002FE44: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_8002FE48:
    // 0x8002FE48: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8002FE4C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8002FE50: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8002FE54: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8002FE58: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8002FE5C: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8002FE60: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8002FE64: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8002FE68: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8002FE6C: jr          $ra
    // 0x8002FE70: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8002FE70: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void AudioLoad_SyncLoadSeqFonts(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000EC14: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8000EC18: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8000EC1C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8000EC20: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8000EC24: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8000EC28: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8000EC2C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8000EC30: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8000EC34: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8000EC38: jal         0x8000F790
    // 0x8000EC3C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    AudioLoad_GetLoadTableIndex(rdram, ctx);
        goto after_0;
    // 0x8000EC3C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8000EC40: lui         $s3, 0x8015
    ctx->r19 = S32(0X8015 << 16);
    // 0x8000EC44: addiu       $s3, $s3, 0x5C68
    ctx->r19 = ADD32(ctx->r19, 0X5C68);
    // 0x8000EC48: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x8000EC4C: sll         $t6, $v0, 1
    ctx->r14 = S32(ctx->r2 << 1);
    // 0x8000EC50: addiu       $s2, $zero, 0xFF
    ctx->r18 = ADD32(0, 0XFF);
    // 0x8000EC54: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x8000EC58: lhu         $s0, 0x0($t7)
    ctx->r16 = MEM_HU(ctx->r15, 0X0);
    // 0x8000EC5C: addu        $t8, $s0, $v1
    ctx->r24 = ADD32(ctx->r16, ctx->r3);
    // 0x8000EC60: lbu         $s1, 0x0($t8)
    ctx->r17 = MEM_BU(ctx->r24, 0X0);
    // 0x8000EC64: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8000EC68: blezl       $s1, L_8000EC9C
    if (SIGNED(ctx->r17) <= 0) {
        // 0x8000EC6C: lw          $t1, 0x3C($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X3C);
            goto L_8000EC9C;
    }
    goto skip_0;
    // 0x8000EC6C: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    skip_0:
    // 0x8000EC70: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
L_8000EC74:
    // 0x8000EC74: addu        $t0, $s0, $t9
    ctx->r8 = ADD32(ctx->r16, ctx->r25);
    // 0x8000EC78: lbu         $s2, 0x0($t0)
    ctx->r18 = MEM_BU(ctx->r8, 0X0);
    // 0x8000EC7C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8000EC80: jal         0x8000F478
    // 0x8000EC84: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    AudioLoad_SyncLoadFont(rdram, ctx);
        goto after_1;
    // 0x8000EC84: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_1:
    // 0x8000EC88: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x8000EC8C: bgtzl       $s1, L_8000EC74
    if (SIGNED(ctx->r17) > 0) {
        // 0x8000EC90: lw          $t9, 0x0($s3)
        ctx->r25 = MEM_W(ctx->r19, 0X0);
            goto L_8000EC74;
    }
    goto skip_1;
    // 0x8000EC90: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    skip_1:
    // 0x8000EC94: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x8000EC98: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
L_8000EC9C:
    // 0x8000EC9C: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x8000ECA0: sw          $s2, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r18;
    // 0x8000ECA4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8000ECA8: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8000ECAC: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8000ECB0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8000ECB4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8000ECB8: jr          $ra
    // 0x8000ECBC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8000ECBC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void AudioThread_CreateTask(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001DF50: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x8001DF54: addiu       $v1, $v1, 0x5CA8
    ctx->r3 = ADD32(ctx->r3, 0X5CA8);
    // 0x8001DF58: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8001DF5C: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x8001DF60: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8001DF64: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x8001DF68: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8001DF6C: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8001DF70: lh          $t8, 0x5C78($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X5C78);
    // 0x8001DF74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001DF78: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8001DF7C: div         $zero, $t7, $t8
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r24))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r24)));
    // 0x8001DF80: mfhi        $t9
    ctx->r25 = hi;
    // 0x8001DF84: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x8001DF88: bne         $t8, $zero, L_8001DF94
    if (ctx->r24 != 0) {
        // 0x8001DF8C: nop
    
            goto L_8001DF94;
    }
    // 0x8001DF8C: nop

    // 0x8001DF90: break       7
    do_break(2147606416);
L_8001DF94:
    // 0x8001DF94: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001DF98: bne         $t8, $at, L_8001DFAC
    if (ctx->r24 != ctx->r1) {
        // 0x8001DF9C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8001DFAC;
    }
    // 0x8001DF9C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001DFA0: bne         $t7, $at, L_8001DFAC
    if (ctx->r15 != ctx->r1) {
        // 0x8001DFA4: nop
    
            goto L_8001DFAC;
    }
    // 0x8001DFA4: nop

    // 0x8001DFA8: break       6
    do_break(2147606440);
L_8001DFAC:
    // 0x8001DFAC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8001DFB0: beq         $t9, $zero, L_8001DFC0
    if (ctx->r25 == 0) {
        // 0x8001DFB4: nop
    
            goto L_8001DFC0;
    }
    // 0x8001DFB4: nop

    // 0x8001DFB8: b           L_8001E434
    // 0x8001DFBC: lw          $v0, 0x7C6C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7C6C);
        goto L_8001E434;
    // 0x8001DFBC: lw          $v0, 0x7C6C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7C6C);
L_8001DFC0:
    // 0x8001DFC0: lw          $a0, 0x7C58($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7C58);
    // 0x8001DFC4: jal         0x80020720
    // 0x8001DFC8: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8001DFC8: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    after_0:
    // 0x8001DFCC: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x8001DFD0: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8001DFD4: addiu       $a0, $a0, 0x5CB4
    ctx->r4 = ADD32(ctx->r4, 0X5CB4);
    // 0x8001DFD8: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x8001DFDC: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8001DFE0: addiu       $a1, $a1, 0x5CB0
    ctx->r5 = ADD32(ctx->r5, 0X5CB0);
    // 0x8001DFE4: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8001DFE8: div         $zero, $t5, $v1
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r3)));
    // 0x8001DFEC: mfhi        $t7
    ctx->r15 = hi;
    // 0x8001DFF0: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x8001DFF4: or          $t6, $t5, $zero
    ctx->r14 = ctx->r13 | 0;
    // 0x8001DFF8: div         $zero, $t9, $v1
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r3)));
    // 0x8001DFFC: lw          $t2, 0x0($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X0);
    // 0x8001E000: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x8001E004: mfhi        $a2
    ctx->r6 = hi;
    // 0x8001E008: xori        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 ^ 0X1;
    // 0x8001E00C: sw          $t3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r11;
    // 0x8001E010: bne         $v1, $zero, L_8001E01C
    if (ctx->r3 != 0) {
        // 0x8001E014: nop
    
            goto L_8001E01C;
    }
    // 0x8001E014: nop

    // 0x8001E018: break       7
    do_break(2147606552);
L_8001E01C:
    // 0x8001E01C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001E020: bne         $v1, $at, L_8001E034
    if (ctx->r3 != ctx->r1) {
        // 0x8001E024: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8001E034;
    }
    // 0x8001E024: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001E028: bne         $t6, $at, L_8001E034
    if (ctx->r14 != ctx->r1) {
        // 0x8001E02C: nop
    
            goto L_8001E034;
    }
    // 0x8001E02C: nop

    // 0x8001E030: break       6
    do_break(2147606576);
L_8001E034:
    // 0x8001E034: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8001E038: or          $t8, $t7, $zero
    ctx->r24 = ctx->r15 | 0;
    // 0x8001E03C: bne         $v1, $zero, L_8001E048
    if (ctx->r3 != 0) {
        // 0x8001E040: nop
    
            goto L_8001E048;
    }
    // 0x8001E040: nop

    // 0x8001E044: break       7
    do_break(2147606596);
L_8001E048:
    // 0x8001E048: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001E04C: bne         $v1, $at, L_8001E060
    if (ctx->r3 != ctx->r1) {
        // 0x8001E050: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8001E060;
    }
    // 0x8001E050: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001E054: bne         $t9, $at, L_8001E060
    if (ctx->r25 != ctx->r1) {
        // 0x8001E058: nop
    
            goto L_8001E060;
    }
    // 0x8001E058: nop

    // 0x8001E05C: break       6
    do_break(2147606620);
L_8001E060:
    // 0x8001E060: sw          $a2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r6;
    // 0x8001E064: jal         0x80025090
    // 0x8001E068: nop

    osAiGetLength_recomp(rdram, ctx);
        goto after_1;
    // 0x8001E068: nop

    after_1:
    // 0x8001E06C: srl         $t2, $v0, 2
    ctx->r10 = S32(U32(ctx->r2) >> 2);
    // 0x8001E070: lui         $t3, 0x8015
    ctx->r11 = S32(0X8015 << 16);
    // 0x8001E074: sw          $t2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r10;
    // 0x8001E078: addiu       $t3, $t3, 0x5D8C
    ctx->r11 = ADD32(ctx->r11, 0X5D8C);
    // 0x8001E07C: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8001E080: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    // 0x8001E084: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8001E088: sltiu       $at, $t4, 0x10
    ctx->r1 = ctx->r12 < 0X10 ? 1 : 0;
    // 0x8001E08C: beq         $at, $zero, L_8001E0B8
    if (ctx->r1 == 0) {
        // 0x8001E090: sll         $t5, $a2, 1
        ctx->r13 = S32(ctx->r6 << 1);
            goto L_8001E0B8;
    }
    // 0x8001E090: sll         $t5, $a2, 1
    ctx->r13 = S32(ctx->r6 << 1);
    // 0x8001E094: addu        $v0, $v0, $t5
    ctx->r2 = ADD32(ctx->r2, ctx->r13);
    // 0x8001E098: lh          $v0, 0x5D7C($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X5D7C);
    // 0x8001E09C: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x8001E0A0: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8001E0A4: beq         $v0, $zero, L_8001E0B8
    if (ctx->r2 == 0) {
        // 0x8001E0A8: addu        $a0, $a0, $t6
        ctx->r4 = ADD32(ctx->r4, ctx->r14);
            goto L_8001E0B8;
    }
    // 0x8001E0A8: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x8001E0AC: lw          $a0, 0x5D70($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5D70);
    // 0x8001E0B0: jal         0x800250A0
    // 0x8001E0B4: sll         $a1, $v0, 2
    ctx->r5 = S32(ctx->r2 << 2);
    osAiSetNextBuffer_recomp(rdram, ctx);
        goto after_2;
    // 0x8001E0B4: sll         $a1, $v0, 2
    ctx->r5 = S32(ctx->r2 << 2);
    after_2:
L_8001E0B8:
    // 0x8001E0B8: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x8001E0BC: addiu       $v1, $v1, 0x5CAC
    ctx->r3 = ADD32(ctx->r3, 0X5CAC);
    // 0x8001E0C0: jal         0x8000E4A0
    // 0x8001E0C4: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    AudioLoad_DecreaseSampleDmaTtls(rdram, ctx);
        goto after_3;
    // 0x8001E0C4: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    after_3:
    // 0x8001E0C8: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x8001E0CC: addiu       $t7, $t7, -0x2AD8
    ctx->r15 = ADD32(ctx->r15, -0X2AD8);
    // 0x8001E0D0: jal         0x8000FF9C
    // 0x8001E0D4: lbu         $a0, 0x0($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0X0);
    AudioLoad_ProcessLoads(rdram, ctx);
        goto after_4;
    // 0x8001E0D4: lbu         $a0, 0x0($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0X0);
    after_4:
    // 0x8001E0D8: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x8001E0DC: lw          $a0, 0x7C60($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7C60);
    // 0x8001E0E0: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x8001E0E4: jal         0x800205E0
    // 0x8001E0E8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_5;
    // 0x8001E0E8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x8001E0EC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001E0F0: beq         $v0, $at, L_8001E11C
    if (ctx->r2 == ctx->r1) {
        // 0x8001E0F4: lui         $v0, 0x8015
        ctx->r2 = S32(0X8015 << 16);
            goto L_8001E11C;
    }
    // 0x8001E0F4: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8001E0F8: addiu       $v0, $v0, -0x2AD8
    ctx->r2 = ADD32(ctx->r2, -0X2AD8);
    // 0x8001E0FC: lbu         $t8, 0x0($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X0);
    // 0x8001E100: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x8001E104: bnel        $t8, $zero, L_8001E114
    if (ctx->r24 != 0) {
        // 0x8001E108: lw          $t2, 0x38($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X38);
            goto L_8001E114;
    }
    goto skip_0;
    // 0x8001E108: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    skip_0:
    // 0x8001E10C: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
    // 0x8001E110: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
L_8001E114:
    // 0x8001E114: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8001E118: sb          $t2, -0x2AD7($at)
    MEM_B(-0X2AD7, ctx->r1) = ctx->r10;
L_8001E11C:
    // 0x8001E11C: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8001E120: addiu       $v0, $v0, -0x2AD8
    ctx->r2 = ADD32(ctx->r2, -0X2AD8);
    // 0x8001E124: lbu         $t3, 0x0($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X0);
    // 0x8001E128: beq         $t3, $zero, L_8001E174
    if (ctx->r11 == 0) {
        // 0x8001E12C: nop
    
            goto L_8001E174;
    }
    // 0x8001E12C: nop

    // 0x8001E130: jal         0x8000D104
    // 0x8001E134: nop

    AudioHeap_ResetStep(rdram, ctx);
        goto after_6;
    // 0x8001E134: nop

    after_6:
    // 0x8001E138: bne         $v0, $zero, L_8001E174
    if (ctx->r2 != 0) {
        // 0x8001E13C: lui         $t4, 0x8015
        ctx->r12 = S32(0X8015 << 16);
            goto L_8001E174;
    }
    // 0x8001E13C: lui         $t4, 0x8015
    ctx->r12 = S32(0X8015 << 16);
    // 0x8001E140: addiu       $t4, $t4, -0x2AD8
    ctx->r12 = ADD32(ctx->r12, -0X2AD8);
    // 0x8001E144: lbu         $t5, 0x0($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X0);
    // 0x8001E148: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x8001E14C: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8001E150: bne         $t5, $zero, L_8001E164
    if (ctx->r13 != 0) {
        // 0x8001E154: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_8001E164;
    }
    // 0x8001E154: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8001E158: lw          $a0, 0x7C64($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7C64);
    // 0x8001E15C: jal         0x80020720
    // 0x8001E160: lbu         $a1, -0x2AD7($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X2AD7);
    osSendMesg_recomp(rdram, ctx);
        goto after_7;
    // 0x8001E160: lbu         $a1, -0x2AD7($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X2AD7);
    after_7:
L_8001E164:
    // 0x8001E164: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8001E168: sw          $zero, 0x7C6C($at)
    MEM_W(0X7C6C, ctx->r1) = 0;
    // 0x8001E16C: b           L_8001E434
    // 0x8001E170: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001E434;
    // 0x8001E170: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001E174:
    // 0x8001E174: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x8001E178: addiu       $v1, $v1, 0x5D8C
    ctx->r3 = ADD32(ctx->r3, 0X5D8C);
    // 0x8001E17C: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8001E180: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x8001E184: addiu       $t1, $t1, 0x5C78
    ctx->r9 = ADD32(ctx->r9, 0X5C78);
    // 0x8001E188: sltiu       $at, $t6, 0x11
    ctx->r1 = ctx->r14 < 0X11 ? 1 : 0;
    // 0x8001E18C: bne         $at, $zero, L_8001E19C
    if (ctx->r1 != 0) {
        // 0x8001E190: lui         $t2, 0x8015
        ctx->r10 = S32(0X8015 << 16);
            goto L_8001E19C;
    }
    // 0x8001E190: lui         $t2, 0x8015
    ctx->r10 = S32(0X8015 << 16);
    // 0x8001E194: b           L_8001E434
    // 0x8001E198: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001E434;
    // 0x8001E198: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001E19C:
    // 0x8001E19C: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8001E1A0: addiu       $t2, $t2, 0x5CC8
    ctx->r10 = ADD32(ctx->r10, 0X5CC8);
    // 0x8001E1A4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8001E1A8: beq         $t7, $zero, L_8001E1BC
    if (ctx->r15 == 0) {
        // 0x8001E1AC: lui         $t5, 0x8015
        ctx->r13 = S32(0X8015 << 16);
            goto L_8001E1BC;
    }
    // 0x8001E1AC: lui         $t5, 0x8015
    ctx->r13 = S32(0X8015 << 16);
    // 0x8001E1B0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8001E1B4: addiu       $t8, $v0, 0x1
    ctx->r24 = ADD32(ctx->r2, 0X1);
    // 0x8001E1B8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
L_8001E1BC:
    // 0x8001E1BC: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x8001E1C0: lw          $v1, 0x5CB0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X5CB0);
    // 0x8001E1C4: lui         $a2, 0x8015
    ctx->r6 = S32(0X8015 << 16);
    // 0x8001E1C8: lw          $a2, 0x5CB4($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X5CB4);
    // 0x8001E1CC: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x8001E1D0: addu        $t9, $t9, $v1
    ctx->r25 = ADD32(ctx->r25, ctx->r3);
    // 0x8001E1D4: sll         $t4, $v1, 2
    ctx->r12 = S32(ctx->r3 << 2);
    // 0x8001E1D8: sll         $t9, $t9, 4
    ctx->r25 = S32(ctx->r25 << 4);
    // 0x8001E1DC: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x8001E1E0: lw          $t5, 0x5CB8($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X5CB8);
    // 0x8001E1E4: addu        $t3, $t9, $t2
    ctx->r11 = ADD32(ctx->r25, ctx->r10);
    // 0x8001E1E8: sw          $t3, 0x5CC4($at)
    MEM_W(0X5CC4, ctx->r1) = ctx->r11;
    // 0x8001E1EC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8001E1F0: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x8001E1F4: sw          $t5, 0x5CC0($at)
    MEM_W(0X5CC0, ctx->r1) = ctx->r13;
    // 0x8001E1F8: lh          $t3, 0x6($t1)
    ctx->r11 = MEM_H(ctx->r9, 0X6);
    // 0x8001E1FC: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x8001E200: addiu       $t7, $t7, 0x5D70
    ctx->r15 = ADD32(ctx->r15, 0X5D70);
    // 0x8001E204: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x8001E208: addu        $t0, $t6, $t7
    ctx->r8 = ADD32(ctx->r14, ctx->r15);
    // 0x8001E20C: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x8001E210: subu        $t5, $t3, $t4
    ctx->r13 = SUB32(ctx->r11, ctx->r12);
    // 0x8001E214: addiu       $t6, $t5, 0x80
    ctx->r14 = ADD32(ctx->r13, 0X80);
    // 0x8001E218: lui         $t2, 0x8015
    ctx->r10 = S32(0X8015 << 16);
    // 0x8001E21C: addiu       $t2, $t2, 0x5D7C
    ctx->r10 = ADD32(ctx->r10, 0X5D7C);
    // 0x8001E220: andi        $t7, $t6, 0xFFF0
    ctx->r15 = ctx->r14 & 0XFFF0;
    // 0x8001E224: sll         $t9, $a2, 1
    ctx->r25 = S32(ctx->r6 << 1);
    // 0x8001E228: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    // 0x8001E22C: addiu       $t8, $t7, 0x10
    ctx->r24 = ADD32(ctx->r15, 0X10);
    // 0x8001E230: addu        $a3, $t9, $t2
    ctx->r7 = ADD32(ctx->r25, ctx->r10);
    // 0x8001E234: sh          $t8, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r24;
    // 0x8001E238: lh          $v0, 0x0($a3)
    ctx->r2 = MEM_H(ctx->r7, 0X0);
    // 0x8001E23C: lh          $a0, 0xA($t1)
    ctx->r4 = MEM_H(ctx->r9, 0XA);
    // 0x8001E240: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8001E244: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x8001E248: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8001E24C: beql        $at, $zero, L_8001E260
    if (ctx->r1 == 0) {
        // 0x8001E250: lh          $v1, 0x8($t1)
        ctx->r3 = MEM_H(ctx->r9, 0X8);
            goto L_8001E260;
    }
    goto skip_1;
    // 0x8001E250: lh          $v1, 0x8($t1)
    ctx->r3 = MEM_H(ctx->r9, 0X8);
    skip_1:
    // 0x8001E254: sh          $a0, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r4;
    // 0x8001E258: lh          $v0, 0x0($a3)
    ctx->r2 = MEM_H(ctx->r7, 0X0);
    // 0x8001E25C: lh          $v1, 0x8($t1)
    ctx->r3 = MEM_H(ctx->r9, 0X8);
L_8001E260:
    // 0x8001E260: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x8001E264: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8001E268: beq         $at, $zero, L_8001E274
    if (ctx->r1 == 0) {
        // 0x8001E26C: nop
    
            goto L_8001E274;
    }
    // 0x8001E26C: nop

    // 0x8001E270: sh          $v1, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r3;
L_8001E274:
    // 0x8001E274: lw          $a0, 0x7C5C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7C5C);
    // 0x8001E278: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x8001E27C: jal         0x800205E0
    // 0x8001E280: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    osRecvMesg_recomp(rdram, ctx);
        goto after_8;
    // 0x8001E280: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    after_8:
    // 0x8001E284: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001E288: beql        $v0, $at, L_8001E2BC
    if (ctx->r2 == ctx->r1) {
        // 0x8001E28C: lw          $t9, 0x28($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X28);
            goto L_8001E2BC;
    }
    goto skip_2;
    // 0x8001E28C: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    skip_2:
L_8001E290:
    // 0x8001E290: jal         0x8001E9AC
    // 0x8001E294: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    AudioThread_ProcessCmds(rdram, ctx);
        goto after_9;
    // 0x8001E294: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_9:
    // 0x8001E298: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x8001E29C: lw          $a0, 0x7C5C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7C5C);
    // 0x8001E2A0: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x8001E2A4: jal         0x800205E0
    // 0x8001E2A8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_10;
    // 0x8001E2A8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_10:
    // 0x8001E2AC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001E2B0: bne         $v0, $at, L_8001E290
    if (ctx->r2 != ctx->r1) {
        // 0x8001E2B4: nop
    
            goto L_8001E290;
    }
    // 0x8001E2B4: nop

    // 0x8001E2B8: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
L_8001E2BC:
    // 0x8001E2BC: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8001E2C0: lw          $a0, 0x5CC0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5CC0);
    // 0x8001E2C4: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x8001E2C8: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x8001E2CC: jal         0x80009B64
    // 0x8001E2D0: lh          $a3, 0x0($t9)
    ctx->r7 = MEM_H(ctx->r25, 0X0);
    AudioSynth_Update(rdram, ctx);
        goto after_11;
    // 0x8001E2D0: lh          $a3, 0x0($t9)
    ctx->r7 = MEM_H(ctx->r25, 0X0);
    after_11:
    // 0x8001E2D4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8001E2D8: jal         0x80025150
    // 0x8001E2DC: sw          $v0, 0x5CC0($at)
    MEM_W(0X5CC0, ctx->r1) = ctx->r2;
    osGetCount_recomp(rdram, ctx);
        goto after_12;
    // 0x8001E2DC: sw          $v0, 0x5CC0($at)
    MEM_W(0X5CC0, ctx->r1) = ctx->r2;
    after_12:
    // 0x8001E2E0: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8001E2E4: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x8001E2E8: addiu       $t1, $t1, 0x5CA8
    ctx->r9 = ADD32(ctx->r9, 0X5CA8);
    // 0x8001E2EC: addiu       $a0, $a0, 0x5D84
    ctx->r4 = ADD32(ctx->r4, 0X5D84);
    // 0x8001E2F0: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x8001E2F4: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x8001E2F8: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8001E2FC: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x8001E300: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8001E304: multu       $v0, $t4
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001E308: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x8001E30C: sll         $t2, $t9, 1
    ctx->r10 = S32(ctx->r25 << 1);
    // 0x8001E310: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x8001E314: addiu       $t0, $t0, 0x5CC4
    ctx->r8 = ADD32(ctx->r8, 0X5CC4);
    // 0x8001E318: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x8001E31C: lui         $a2, 0x8015
    ctx->r6 = S32(0X8015 << 16);
    // 0x8001E320: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x8001E324: addiu       $a1, $a1, 0x450
    ctx->r5 = ADD32(ctx->r5, 0X450);
    // 0x8001E328: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8001E32C: mflo        $t5
    ctx->r13 = lo;
    // 0x8001E330: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x8001E334: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8001E338: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x8001E33C: addiu       $a3, $a3, 0x32E0
    ctx->r7 = ADD32(ctx->r7, 0X32E0);
    // 0x8001E340: addu        $t3, $t7, $t2
    ctx->r11 = ADD32(ctx->r15, ctx->r10);
    // 0x8001E344: lh          $t4, 0x0($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X0);
    // 0x8001E348: lui         $t2, 0x8000
    ctx->r10 = S32(0X8000 << 16);
    // 0x8001E34C: addiu       $t2, $t2, 0x520
    ctx->r10 = ADD32(ctx->r10, 0X520);
    // 0x8001E350: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x8001E354: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8001E358: lw          $a2, 0x5CB0($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X5CB0);
    // 0x8001E35C: sw          $zero, 0x40($t8)
    MEM_W(0X40, ctx->r24) = 0;
    // 0x8001E360: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x8001E364: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x8001E368: subu        $t3, $t2, $a1
    ctx->r11 = SUB32(ctx->r10, ctx->r5);
    // 0x8001E36C: sw          $zero, 0x44($t9)
    MEM_W(0X44, ctx->r25) = 0;
    // 0x8001E370: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x8001E374: addiu       $t6, $t6, 0x3610
    ctx->r14 = ADD32(ctx->r14, 0X3610);
    // 0x8001E378: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8001E37C: subu        $t8, $t6, $a3
    ctx->r24 = SUB32(ctx->r14, ctx->r7);
    // 0x8001E380: lui         $t4, 0x8000
    ctx->r12 = S32(0X8000 << 16);
    // 0x8001E384: sra         $t9, $t8, 3
    ctx->r25 = S32(SIGNED(ctx->r24) >> 3);
    // 0x8001E388: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8001E38C: sw          $t3, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r11;
    // 0x8001E390: addiu       $t4, $t4, 0x520
    ctx->r12 = ADD32(ctx->r12, 0X520);
    // 0x8001E394: addiu       $t5, $zero, 0x1000
    ctx->r13 = ADD32(0, 0X1000);
    // 0x8001E398: sll         $t7, $t9, 3
    ctx->r15 = S32(ctx->r25 << 3);
    // 0x8001E39C: lui         $t3, 0x8015
    ctx->r11 = S32(0X8015 << 16);
    // 0x8001E3A0: sll         $t2, $a2, 2
    ctx->r10 = S32(ctx->r6 << 2);
    // 0x8001E3A4: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8001E3A8: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8001E3AC: sw          $a1, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r5;
    // 0x8001E3B0: sw          $t4, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r12;
    // 0x8001E3B4: sw          $a3, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r7;
    // 0x8001E3B8: sw          $t5, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r13;
    // 0x8001E3BC: sw          $t7, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r15;
    // 0x8001E3C0: sw          $zero, 0x20($v1)
    MEM_W(0X20, ctx->r3) = 0;
    // 0x8001E3C4: sw          $zero, 0x24($v1)
    MEM_W(0X24, ctx->r3) = 0;
    // 0x8001E3C8: sw          $zero, 0x28($v1)
    MEM_W(0X28, ctx->r3) = 0;
    // 0x8001E3CC: sw          $zero, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = 0;
    // 0x8001E3D0: lw          $t3, 0x5CB8($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X5CB8);
    // 0x8001E3D4: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x8001E3D8: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x8001E3DC: sw          $t3, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r11;
    // 0x8001E3E0: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x8001E3E4: sw          $zero, 0x38($v1)
    MEM_W(0X38, ctx->r3) = 0;
    // 0x8001E3E8: sw          $zero, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = 0;
    // 0x8001E3EC: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x8001E3F0: sw          $t5, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->r13;
    // 0x8001E3F4: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x8001E3F8: lw          $t6, 0x7C68($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7C68);
    // 0x8001E3FC: slt         $at, $t6, $t8
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8001E400: beq         $at, $zero, L_8001E40C
    if (ctx->r1 == 0) {
        // 0x8001E404: lui         $at, 0x800C
        ctx->r1 = S32(0X800C << 16);
            goto L_8001E40C;
    }
    // 0x8001E404: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8001E408: sw          $t8, 0x7C68($at)
    MEM_W(0X7C68, ctx->r1) = ctx->r24;
L_8001E40C:
    // 0x8001E40C: lh          $t9, 0x5C78($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X5C78);
    // 0x8001E410: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001E414: bnel        $t9, $at, L_8001E428
    if (ctx->r25 != ctx->r1) {
        // 0x8001E418: lw          $t7, 0x0($t0)
        ctx->r15 = MEM_W(ctx->r8, 0X0);
            goto L_8001E428;
    }
    goto skip_3;
    // 0x8001E418: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    skip_3:
    // 0x8001E41C: b           L_8001E434
    // 0x8001E420: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
        goto L_8001E434;
    // 0x8001E420: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x8001E424: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
L_8001E428:
    // 0x8001E428: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8001E42C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001E430: sw          $t7, 0x7C6C($at)
    MEM_W(0X7C6C, ctx->r1) = ctx->r15;
L_8001E434:
    // 0x8001E434: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001E438: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x8001E43C: jr          $ra
    // 0x8001E440: nop

    return;
    // 0x8001E440: nop

;}
RECOMP_FUNC void func_enmy_80061E48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80061E48: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80061E4C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80061E50: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80061E54: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80061E58: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80061E5C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80061E60: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80061E64: jal         0x800613C4
    // 0x80061E68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Actor_Initialize(rdram, ctx);
        goto after_0;
    // 0x80061E68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80061E6C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80061E70: addiu       $t7, $zero, 0xB5
    ctx->r15 = ADD32(0, 0XB5);
    // 0x80061E74: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
    // 0x80061E78: jal         0x80004EB0
    // 0x80061E7C: sh          $t7, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r15;
    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x80061E7C: sh          $t7, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r15;
    after_1:
    // 0x80061E80: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80061E84: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80061E88: addiu       $t8, $zero, 0xBA
    ctx->r24 = ADD32(0, 0XBA);
    // 0x80061E8C: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80061E90: nop

    // 0x80061E94: bc1f        L_80061EA0
    if (!c1cs) {
        // 0x80061E98: nop
    
            goto L_80061EA0;
    }
    // 0x80061E98: nop

    // 0x80061E9C: sh          $t8, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r24;
L_80061EA0:
    // 0x80061EA0: jal         0x80004EB0
    // 0x80061EA4: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_2;
    // 0x80061EA4: nop

    after_2:
    // 0x80061EA8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80061EAC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80061EB0: addiu       $t9, $zero, 0xB6
    ctx->r25 = ADD32(0, 0XB6);
    // 0x80061EB4: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80061EB8: nop

    // 0x80061EBC: bc1fl       L_80061ECC
    if (!c1cs) {
        // 0x80061EC0: lwc1        $f8, 0x24($sp)
        ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
            goto L_80061ECC;
    }
    goto skip_0;
    // 0x80061EC0: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80061EC4: sh          $t9, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r25;
    // 0x80061EC8: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
L_80061ECC:
    // 0x80061ECC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80061ED0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80061ED4: swc1        $f8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f8.u32l;
    // 0x80061ED8: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80061EDC: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x80061EE0: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    // 0x80061EE4: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
    // 0x80061EE8: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80061EEC: swc1        $f18, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f18.u32l;
    // 0x80061EF0: jal         0x800612B8
    // 0x80061EF4: swc1        $f16, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_3;
    // 0x80061EF4: swc1        $f16, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
    after_3:
    // 0x80061EF8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80061EFC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80061F00: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80061F04: jr          $ra
    // 0x80061F08: nop

    return;
    // 0x80061F08: nop

;}
RECOMP_FUNC void Effect_Effect348_Spawn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062B60: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80062B64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80062B68: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    // 0x80062B6C: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    // 0x80062B70: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80062B74: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80062B78: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x80062B7C: lbu         $t6, 0x7C98($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X7C98);
    // 0x80062B80: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x80062B84: addiu       $a2, $a2, 0x130
    ctx->r6 = ADD32(ctx->r6, 0X130);
    // 0x80062B88: bne         $t6, $zero, L_80062C28
    if (ctx->r14 != 0) {
        // 0x80062B8C: lui         $v0, 0x8017
        ctx->r2 = S32(0X8017 << 16);
            goto L_80062C28;
    }
    // 0x80062B8C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80062B90: addiu       $v0, $v0, 0x37E0
    ctx->r2 = ADD32(ctx->r2, 0X37E0);
    // 0x80062B94: lbu         $t7, 0x0($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X0);
L_80062B98:
    // 0x80062B98: bne         $t7, $zero, L_80062C1C
    if (ctx->r15 != 0) {
        // 0x80062B9C: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_80062C1C;
    }
    // 0x80062B9C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80062BA0: jal         0x80061474
    // 0x80062BA4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    Effect_Initialize(rdram, ctx);
        goto after_0;
    // 0x80062BA4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80062BA8: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80062BAC: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80062BB0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80062BB4: addiu       $t9, $zero, 0x15C
    ctx->r25 = ADD32(0, 0X15C);
    // 0x80062BB8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80062BBC: sb          $t8, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r24;
    // 0x80062BC0: sh          $t9, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r25;
    // 0x80062BC4: swc1        $f4, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f4.u32l;
    // 0x80062BC8: lwc1        $f6, 0x7940($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7940);
    // 0x80062BCC: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80062BD0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80062BD4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80062BD8: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80062BDC: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80062BE0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80062BE4: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80062BE8: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80062BEC: addiu       $t0, $zero, 0x50
    ctx->r8 = ADD32(0, 0X50);
    // 0x80062BF0: andi        $a1, $t9, 0xFFFF
    ctx->r5 = ctx->r25 & 0XFFFF;
    // 0x80062BF4: swc1        $f10, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f10.u32l;
    // 0x80062BF8: sh          $t0, 0x44($a2)
    MEM_H(0X44, ctx->r6) = ctx->r8;
    // 0x80062BFC: addiu       $a0, $a2, 0x1C
    ctx->r4 = ADD32(ctx->r6, 0X1C);
    // 0x80062C00: swc1        $f16, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f16.u32l;
    // 0x80062C04: swc1        $f18, 0x70($a2)
    MEM_W(0X70, ctx->r6) = ctx->f18.u32l;
    // 0x80062C08: swc1        $f4, 0x6C($a2)
    MEM_W(0X6C, ctx->r6) = ctx->f4.u32l;
    // 0x80062C0C: jal         0x800612B8
    // 0x80062C10: sh          $t1, 0x4E($a2)
    MEM_H(0X4E, ctx->r6) = ctx->r9;
    Object_SetInfo(rdram, ctx);
        goto after_1;
    // 0x80062C10: sh          $t1, 0x4E($a2)
    MEM_H(0X4E, ctx->r6) = ctx->r9;
    after_1:
    // 0x80062C14: b           L_80062C2C
    // 0x80062C18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80062C2C;
    // 0x80062C18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80062C1C:
    // 0x80062C1C: addiu       $a2, $a2, 0x8C
    ctx->r6 = ADD32(ctx->r6, 0X8C);
    // 0x80062C20: bnel        $a2, $v0, L_80062B98
    if (ctx->r6 != ctx->r2) {
        // 0x80062C24: lbu         $t7, 0x0($a2)
        ctx->r15 = MEM_BU(ctx->r6, 0X0);
            goto L_80062B98;
    }
    goto skip_0;
    // 0x80062C24: lbu         $t7, 0x0($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X0);
    skip_0:
L_80062C28:
    // 0x80062C28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80062C2C:
    // 0x80062C2C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80062C30: jr          $ra
    // 0x80062C34: nop

    return;
    // 0x80062C34: nop

;}
RECOMP_FUNC void Audio_AudioListPushFront(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80012C00: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x80012C04: bne         $t6, $zero, L_80012C38
    if (ctx->r14 != 0) {
        // 0x80012C08: nop
    
            goto L_80012C38;
    }
    // 0x80012C08: nop

    // 0x80012C0C: sw          $a0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r4;
    // 0x80012C10: lw          $t7, 0x4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4);
    // 0x80012C14: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x80012C18: lw          $t8, 0x4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4);
    // 0x80012C1C: sw          $a1, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r5;
    // 0x80012C20: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x80012C24: lw          $t1, 0xC($a0)
    ctx->r9 = MEM_W(ctx->r4, 0XC);
    // 0x80012C28: sw          $a1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r5;
    // 0x80012C2C: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80012C30: sw          $t0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r8;
    // 0x80012C34: sw          $t1, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r9;
L_80012C38:
    // 0x80012C38: jr          $ra
    // 0x80012C3C: nop

    return;
    // 0x80012C3C: nop

;}
RECOMP_FUNC void func_tank_800444BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800444BC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800444C0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800444C4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800444C8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800444CC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800444D0: lwc1        $f4, 0xD4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XD4);
    // 0x800444D4: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x800444D8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800444DC: c.lt.s      $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f4.fl < ctx->f16.fl;
    // 0x800444E0: sw          $zero, 0x1D4($s0)
    MEM_W(0X1D4, ctx->r16) = 0;
    // 0x800444E4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800444E8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800444EC: bc1f        L_800444F8
    if (!c1cs) {
        // 0x800444F0: addiu       $a2, $sp, 0x40
        ctx->r6 = ADD32(ctx->r29, 0X40);
            goto L_800444F8;
    }
    // 0x800444F0: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // 0x800444F4: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
L_800444F8:
    // 0x800444F8: lwc1        $f6, 0x7940($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7940);
    // 0x800444FC: lw          $t6, -0x7B54($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7B54);
    // 0x80044500: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80044504: swc1        $f16, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f16.u32l;
    // 0x80044508: swc1        $f16, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f16.u32l;
    // 0x8004450C: bne         $t6, $at, L_80044540
    if (ctx->r14 != ctx->r1) {
        // 0x80044510: swc1        $f6, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
            goto L_80044540;
    }
    // 0x80044510: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    // 0x80044514: lwc1        $f8, 0x138($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X138);
    // 0x80044518: lwc1        $f10, 0x144($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X144);
    // 0x8004451C: lwc1        $f12, 0x74($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X74);
    // 0x80044520: addiu       $t7, $sp, 0x3C
    ctx->r15 = ADD32(ctx->r29, 0X3C);
    // 0x80044524: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80044528: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x8004452C: addiu       $a3, $sp, 0x38
    ctx->r7 = ADD32(ctx->r29, 0X38);
    // 0x80044530: jal         0x801B6E20
    // 0x80044534: add.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f10.fl;
    Ground_801B6E20(rdram, ctx);
        goto after_0;
    // 0x80044534: add.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f10.fl;
    after_0:
    // 0x80044538: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8004453C: lwc1        $f0, 0x30($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X30);
L_80044540:
    // 0x80044540: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80044544: lw          $t8, -0x7DCC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7DCC);
    // 0x80044548: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8004454C: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80044550: bne         $t8, $at, L_800445AC
    if (ctx->r24 != ctx->r1) {
        // 0x80044554: addiu       $v0, $v0, -0x1DB0
        ctx->r2 = ADD32(ctx->r2, -0X1DB0);
            goto L_800445AC;
    }
    // 0x80044554: addiu       $v0, $v0, -0x1DB0
    ctx->r2 = ADD32(ctx->r2, -0X1DB0);
    // 0x80044558: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8004455C: lwc1        $f18, 0x7940($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7940);
    // 0x80044560: swc1        $f16, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->f16.u32l;
    // 0x80044564: lwc1        $f4, 0x74($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X74);
    // 0x80044568: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004456C: swc1        $f18, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->f18.u32l;
    // 0x80044570: swc1        $f4, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->f4.u32l;
    // 0x80044574: swc1        $f16, -0x60F0($at)
    MEM_W(-0X60F0, ctx->r1) = ctx->f16.u32l;
    // 0x80044578: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8004457C: jal         0x80047754
    // 0x80044580: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    func_tank_80047754(rdram, ctx);
        goto after_1;
    // 0x80044580: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x80044584: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80044588: addiu       $v0, $v0, -0x1DB0
    ctx->r2 = ADD32(ctx->r2, -0X1DB0);
    // 0x8004458C: lwc1        $f6, 0x6C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X6C);
    // 0x80044590: lwc1        $f8, 0x70($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X70);
    // 0x80044594: lwc1        $f10, 0x74($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X74);
    // 0x80044598: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8004459C: lwc1        $f0, 0x30($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800445A0: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    // 0x800445A4: swc1        $f8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f8.u32l;
    // 0x800445A8: swc1        $f10, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f10.u32l;
L_800445AC:
    // 0x800445AC: lwc1        $f18, 0x78($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X78);
    // 0x800445B0: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800445B4: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x800445B8: sub.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f0.fl;
    // 0x800445BC: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x800445C0: nop

    // 0x800445C4: bc1f        L_80044838
    if (!c1cs) {
        // 0x800445C8: nop
    
            goto L_80044838;
    }
    // 0x800445C8: nop

    // 0x800445CC: lwc1        $f0, 0xC4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x800445D0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800445D4: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x800445D8: lui         $a0, 0x900
    ctx->r4 = S32(0X900 << 16);
    // 0x800445DC: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x800445E0: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x800445E4: ori         $a0, $a0, 0x8015
    ctx->r4 = ctx->r4 | 0X8015;
    // 0x800445E8: addiu       $a1, $s0, 0x460
    ctx->r5 = ADD32(ctx->r16, 0X460);
    // 0x800445EC: bc1f        L_80044610
    if (!c1cs) {
        // 0x800445F0: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80044610;
    }
    // 0x800445F0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800445F4: lui         $t9, 0x800C
    ctx->r25 = S32(0X800C << 16);
    // 0x800445F8: addiu       $t9, $t9, 0x5D3C
    ctx->r25 = ADD32(ctx->r25, 0X5D3C);
    // 0x800445FC: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80044600: jal         0x80019218
    // 0x80044604: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    Audio_PlaySfx(rdram, ctx);
        goto after_2;
    // 0x80044604: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_2:
    // 0x80044608: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8004460C: lwc1        $f0, 0xC4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC4);
L_80044610:
    // 0x80044610: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    // 0x80044614: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80044618: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8004461C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80044620: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80044624: sw          $t0, 0x1D4($s0)
    MEM_W(0X1D4, ctx->r16) = ctx->r8;
    // 0x80044628: addiu       $v0, $v0, 0x7BAC
    ctx->r2 = ADD32(ctx->r2, 0X7BAC);
    // 0x8004462C: addiu       $t1, $zero, 0x14
    ctx->r9 = ADD32(0, 0X14);
    // 0x80044630: bc1f        L_8004463C
    if (!c1cs) {
        // 0x80044634: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8004463C;
    }
    // 0x80044634: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80044638: sw          $t1, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r9;
L_8004463C:
    // 0x8004463C: lbu         $t2, 0x0($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X0);
    // 0x80044640: ori         $a1, $zero, 0x8004
    ctx->r5 = 0 | 0X8004;
    // 0x80044644: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80044648: beq         $t2, $zero, L_80044668
    if (ctx->r10 == 0) {
        // 0x8004464C: addiu       $a3, $zero, 0xFF
        ctx->r7 = ADD32(0, 0XFF);
            goto L_80044668;
    }
    // 0x8004464C: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x80044650: jal         0x8001D444
    // 0x80044654: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    Audio_PlaySequence(rdram, ctx);
        goto after_3;
    // 0x80044654: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    after_3:
    // 0x80044658: jal         0x8001C8B8
    // 0x8004465C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    Audio_StartPlayerNoise(rdram, ctx);
        goto after_4;
    // 0x8004465C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x80044660: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80044664: nop

L_80044668:
    // 0x80044668: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004466C: lwc1        $f12, 0x5640($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X5640);
    // 0x80044670: lwc1        $f2, 0xD0($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XD0);
    // 0x80044674: lwc1        $f0, 0x104($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X104);
    // 0x80044678: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8004467C: mul.s       $f8, $f2, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x80044680: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80044684: lwc1        $f18, 0x38($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80044688: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x8004468C: lui         $at, 0xC040
    ctx->r1 = S32(0XC040 << 16);
    // 0x80044690: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80044694: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80044698: add.s       $f14, $f8, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f12.fl;
    // 0x8004469C: swc1        $f6, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f6.u32l;
    // 0x800446A0: bc1f        L_800446E4
    if (!c1cs) {
        // 0x800446A4: swc1        $f10, 0xC4($s0)
        MEM_W(0XC4, ctx->r16) = ctx->f10.u32l;
            goto L_800446E4;
    }
    // 0x800446A4: swc1        $f10, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f10.u32l;
    // 0x800446A8: lwc1        $f18, 0x40($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800446AC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800446B0: c.le.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl <= ctx->f16.fl;
    // 0x800446B4: nop

    // 0x800446B8: bc1fl       L_800446E8
    if (!c1cs) {
        // 0x800446BC: lwc1        $f4, 0xD4($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0XD4);
            goto L_800446E8;
    }
    goto skip_0;
    // 0x800446BC: lwc1        $f4, 0xD4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XD4);
    skip_0:
    // 0x800446C0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800446C4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800446C8: lwc1        $f10, 0x5644($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X5644);
    // 0x800446CC: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800446D0: swc1        $f0, 0xE4($s0)
    MEM_W(0XE4, ctx->r16) = ctx->f0.u32l;
    // 0x800446D4: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800446D8: nop

    // 0x800446DC: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800446E0: swc1        $f18, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f18.u32l;
L_800446E4:
    // 0x800446E4: lwc1        $f4, 0xD4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XD4);
L_800446E8:
    // 0x800446E8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800446EC: c.lt.s      $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f4.fl < ctx->f16.fl;
    // 0x800446F0: nop

    // 0x800446F4: bc1fl       L_8004471C
    if (!c1cs) {
        // 0x800446F8: lui         $at, 0x4334
        ctx->r1 = S32(0X4334 << 16);
            goto L_8004471C;
    }
    goto skip_1;
    // 0x800446F8: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    skip_1:
    // 0x800446FC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80044700: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x80044704: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80044708: lwc1        $f6, 0x78($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X78);
    // 0x8004470C: swc1        $f0, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f0.u32l;
    // 0x80044710: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80044714: swc1        $f10, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f10.u32l;
    // 0x80044718: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
L_8004471C:
    // 0x8004471C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80044720: lwc1        $f18, 0x40($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80044724: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80044728: lwc1        $f2, 0x5648($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5648);
    // 0x8004472C: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80044730: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80044734: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80044738: div.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8004473C: swc1        $f6, 0x104($s0)
    MEM_W(0X104, ctx->r16) = ctx->f6.u32l;
    // 0x80044740: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80044744: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80044748: div.s       $f18, $f10, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8004474C: swc1        $f18, 0x10C($s0)
    MEM_W(0X10C, ctx->r16) = ctx->f18.u32l;
    // 0x80044750: lw          $t3, -0x7DCC($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X7DCC);
    // 0x80044754: bne         $t3, $at, L_800447B8
    if (ctx->r11 != ctx->r1) {
        // 0x80044758: lui         $at, 0x42B4
        ctx->r1 = S32(0X42B4 << 16);
            goto L_800447B8;
    }
    // 0x80044758: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8004475C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80044760: lwc1        $f0, 0x104($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X104);
    // 0x80044764: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80044768: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8004476C: nop

    // 0x80044770: bc1fl       L_80044790
    if (!c1cs) {
        // 0x80044774: lwc1        $f0, 0x10C($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X10C);
            goto L_80044790;
    }
    goto skip_2;
    // 0x80044774: lwc1        $f0, 0x10C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X10C);
    skip_2:
    // 0x80044778: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8004477C: nop

    // 0x80044780: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x80044784: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x80044788: swc1        $f8, 0x104($s0)
    MEM_W(0X104, ctx->r16) = ctx->f8.u32l;
    // 0x8004478C: lwc1        $f0, 0x10C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X10C);
L_80044790:
    // 0x80044790: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80044794: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80044798: nop

    // 0x8004479C: bc1fl       L_800447BC
    if (!c1cs) {
        // 0x800447A0: lwc1        $f2, 0xE4($s0)
        ctx->f2.u32l = MEM_W(ctx->r16, 0XE4);
            goto L_800447BC;
    }
    goto skip_3;
    // 0x800447A0: lwc1        $f2, 0xE4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XE4);
    skip_3:
    // 0x800447A4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800447A8: nop

    // 0x800447AC: sub.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x800447B0: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x800447B4: swc1        $f4, 0x10C($s0)
    MEM_W(0X10C, ctx->r16) = ctx->f4.u32l;
L_800447B8:
    // 0x800447B8: lwc1        $f2, 0xE4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XE4);
L_800447BC:
    // 0x800447BC: lwc1        $f0, 0x104($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X104);
    // 0x800447C0: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800447C4: nop

    // 0x800447C8: bc1fl       L_800447E4
    if (!c1cs) {
        // 0x800447CC: c.lt.s      $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
            goto L_800447E4;
    }
    goto skip_4;
    // 0x800447CC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    skip_4:
    // 0x800447D0: add.s       $f6, $f2, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f14.fl;
    // 0x800447D4: lwc1        $f0, 0x104($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X104);
    // 0x800447D8: swc1        $f6, 0xE4($s0)
    MEM_W(0XE4, ctx->r16) = ctx->f6.u32l;
    // 0x800447DC: lwc1        $f2, 0xE4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XE4);
    // 0x800447E0: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
L_800447E4:
    // 0x800447E4: nop

    // 0x800447E8: bc1fl       L_800447FC
    if (!c1cs) {
        // 0x800447EC: lwc1        $f2, 0xEC($s0)
        ctx->f2.u32l = MEM_W(ctx->r16, 0XEC);
            goto L_800447FC;
    }
    goto skip_5;
    // 0x800447EC: lwc1        $f2, 0xEC($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XEC);
    skip_5:
    // 0x800447F0: sub.s       $f8, $f2, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f14.fl;
    // 0x800447F4: swc1        $f8, 0xE4($s0)
    MEM_W(0XE4, ctx->r16) = ctx->f8.u32l;
    // 0x800447F8: lwc1        $f2, 0xEC($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XEC);
L_800447FC:
    // 0x800447FC: lwc1        $f0, 0x10C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X10C);
    // 0x80044800: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80044804: nop

    // 0x80044808: bc1fl       L_80044824
    if (!c1cs) {
        // 0x8004480C: c.lt.s      $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
            goto L_80044824;
    }
    goto skip_6;
    // 0x8004480C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    skip_6:
    // 0x80044810: add.s       $f10, $f2, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f14.fl;
    // 0x80044814: lwc1        $f0, 0x10C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X10C);
    // 0x80044818: swc1        $f10, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f10.u32l;
    // 0x8004481C: lwc1        $f2, 0xEC($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x80044820: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
L_80044824:
    // 0x80044824: nop

    // 0x80044828: bc1f        L_80044838
    if (!c1cs) {
        // 0x8004482C: nop
    
            goto L_80044838;
    }
    // 0x8004482C: nop

    // 0x80044830: sub.s       $f18, $f2, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = ctx->f2.fl - ctx->f14.fl;
    // 0x80044834: swc1        $f18, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f18.u32l;
L_80044838:
    // 0x80044838: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8004483C: lw          $t4, -0x7DCC($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7DCC);
    // 0x80044840: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80044844: bnel        $t4, $at, L_80044858
    if (ctx->r12 != ctx->r1) {
        // 0x80044848: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80044858;
    }
    goto skip_7;
    // 0x80044848: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_7:
    // 0x8004484C: jal         0x800443DC
    // 0x80044850: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_tank_800443DC(rdram, ctx);
        goto after_5;
    // 0x80044850: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80044854: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80044858:
    // 0x80044858: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8004485C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80044860: jr          $ra
    // 0x80044864: nop

    return;
    // 0x80044864: nop

;}
RECOMP_FUNC void Effect_Effect384_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007B3B8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8007B3BC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8007B3C0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8007B3C4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8007B3C8: lbu         $v0, 0x4C($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X4C);
    // 0x8007B3CC: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8007B3D0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8007B3D4: bne         $v0, $at, L_8007B3F4
    if (ctx->r2 != ctx->r1) {
        // 0x8007B3D8: addiu       $a0, $s0, 0x70
        ctx->r4 = ADD32(ctx->r16, 0X70);
            goto L_8007B3F4;
    }
    // 0x8007B3D8: addiu       $a0, $s0, 0x70
    ctx->r4 = ADD32(ctx->r16, 0X70);
    // 0x8007B3DC: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x8007B3E0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8007B3E4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007B3E8: lwc1        $f2, 0x73C8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X73C8);
    // 0x8007B3EC: b           L_8007B440
    // 0x8007B3F0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_8007B440;
    // 0x8007B3F0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_8007B3F4:
    // 0x8007B3F4: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8007B3F8: bne         $v0, $at, L_8007B42C
    if (ctx->r2 != ctx->r1) {
        // 0x8007B3FC: lui         $v0, 0x8018
        ctx->r2 = S32(0X8018 << 16);
            goto L_8007B42C;
    }
    // 0x8007B3FC: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8007B400: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
    // 0x8007B404: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x8007B408: beq         $v0, $at, L_8007B414
    if (ctx->r2 == ctx->r1) {
        // 0x8007B40C: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8007B414;
    }
    // 0x8007B40C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8007B410: bne         $v0, $at, L_8007B42C
    if (ctx->r2 != ctx->r1) {
        // 0x8007B414: lui         $at, 0x4120
        ctx->r1 = S32(0X4120 << 16);
            goto L_8007B42C;
    }
L_8007B414:
    // 0x8007B414: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8007B418: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8007B41C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007B420: lwc1        $f2, 0x73CC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X73CC);
    // 0x8007B424: b           L_8007B440
    // 0x8007B428: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_8007B440;
    // 0x8007B428: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_8007B42C:
    // 0x8007B42C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8007B430: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8007B434: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007B438: lwc1        $f2, 0x73D0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X73D0);
    // 0x8007B43C: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
L_8007B440:
    // 0x8007B440: lw          $a1, 0x6C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X6C);
    // 0x8007B444: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x8007B448: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8007B44C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8007B450: jal         0x8009BC2C
    // 0x8007B454: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_0;
    // 0x8007B454: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x8007B458: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x8007B45C: lh          $t6, 0x44($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X44);
    // 0x8007B460: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8007B464: subu        $t7, $t6, $v0
    ctx->r15 = SUB32(ctx->r14, ctx->r2);
    // 0x8007B468: sh          $t7, 0x44($s0)
    MEM_H(0X44, ctx->r16) = ctx->r15;
    // 0x8007B46C: lh          $t8, 0x44($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X44);
    // 0x8007B470: bgezl       $t8, L_8007B484
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8007B474: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8007B484;
    }
    goto skip_0;
    // 0x8007B474: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8007B478: jal         0x80060FBC
    // 0x8007B47C: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    Object_Kill(rdram, ctx);
        goto after_1;
    // 0x8007B47C: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    after_1:
    // 0x8007B480: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8007B484:
    // 0x8007B484: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8007B488: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8007B48C: jr          $ra
    // 0x8007B490: nop

    return;
    // 0x8007B490: nop

;}
RECOMP_FUNC void vsprintf_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001FA04: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001FA08: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8001FA0C: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x8001FA10: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8001FA14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001FA18: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8001FA1C: lui         $a0, 0x8002
    ctx->r4 = S32(0X8002 << 16);
    // 0x8001FA20: addiu       $a0, $a0, -0x620
    ctx->r4 = ADD32(ctx->r4, -0X620);
    // 0x8001FA24: jal         0x800246D0
    // 0x8001FA28: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    _Printf(rdram, ctx);
        goto after_0;
    // 0x8001FA28: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_0:
    // 0x8001FA2C: bltz        $v0, L_8001FA40
    if (SIGNED(ctx->r2) < 0) {
        // 0x8001FA30: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8001FA40;
    }
    // 0x8001FA30: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8001FA34: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8001FA38: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x8001FA3C: sb          $zero, 0x0($t7)
    MEM_B(0X0, ctx->r15) = 0;
L_8001FA40:
    // 0x8001FA40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001FA44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001FA48: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8001FA4C: jr          $ra
    // 0x8001FA50: nop

    return;
    // 0x8001FA50: nop

;}
RECOMP_FUNC void AudioSynth_InverseDiscreteCosineTransform(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80008364: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x80008368: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8000836C: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x80008370: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x80008374: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x80008378: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x8000837C: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x80008380: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x80008384: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80008388: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8000838C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80008390: sw          $a0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r4;
    // 0x80008394: sw          $a1, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r5;
    // 0x80008398: sw          $a2, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r6;
    // 0x8000839C: sw          $a3, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r7;
    // 0x800083A0: lwc1        $f4, 0x0($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X0);
    // 0x800083A4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800083A8: sllv        $t3, $t7, $a2
    ctx->r11 = S32(ctx->r15 << (ctx->r6 & 31));
    // 0x800083AC: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800083B0: sra         $s4, $t3, 1
    ctx->r20 = S32(SIGNED(ctx->r11) >> 1);
    // 0x800083B4: sll         $t1, $s4, 2
    ctx->r9 = S32(ctx->r20 << 2);
    // 0x800083B8: addu        $s0, $t1, $a3
    ctx->r16 = ADD32(ctx->r9, ctx->r7);
    // 0x800083BC: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x800083C0: or          $s3, $s4, $zero
    ctx->r19 = ctx->r20 | 0;
    // 0x800083C4: addu        $s1, $t1, $s0
    ctx->r17 = ADD32(ctx->r9, ctx->r16);
    // 0x800083C8: beql        $t3, $t4, L_80008464
    if (ctx->r11 == ctx->r12) {
        // 0x800083CC: lw          $t7, 0x98($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X98);
            goto L_80008464;
    }
    goto skip_0;
    // 0x800083CC: lw          $t7, 0x98($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X98);
    skip_0:
    // 0x800083D0: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800083D4: blez        $s4, L_80008460
    if (SIGNED(ctx->r20) <= 0) {
        // 0x800083D8: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_80008460;
    }
    // 0x800083D8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800083DC: sll         $t5, $t3, 1
    ctx->r13 = S32(ctx->r11 << 1);
    // 0x800083E0: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x800083E4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800083E8: ldc1        $f8, -0x79E0($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X79E0);
    // 0x800083EC: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800083F0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800083F4: lwc1        $f24, -0x79D8($at)
    ctx->f24.u32l = MEM_W(ctx->r1, -0X79D8);
    // 0x800083F8: sw          $t3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r11;
    // 0x800083FC: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x80008400: div.d       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = DIV_D(ctx->f8.d, ctx->f18.d);
    // 0x80008404: cvt.s.d     $f26, $f4
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f26.fl = CVT_S_D(ctx->f4.d);
L_80008408:
    // 0x80008408: jal         0x80023250
    // 0x8000840C: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    __cosf_recomp(rdram, ctx);
        goto after_0;
    // 0x8000840C: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_0:
    // 0x80008410: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x80008414: jal         0x80023090
    // 0x80008418: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    __sinf_recomp(rdram, ctx);
        goto after_1;
    // 0x80008418: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_1:
    // 0x8000841C: sub.s       $f6, $f22, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f22.fl - ctx->f0.fl;
    // 0x80008420: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80008424: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x80008428: mul.s       $f10, $f6, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f24.fl);
    // 0x8000842C: jal         0x80023250
    // 0x80008430: swc1        $f10, -0x4($s0)
    MEM_W(-0X4, ctx->r16) = ctx->f10.u32l;
    __cosf_recomp(rdram, ctx);
        goto after_2;
    // 0x80008430: swc1        $f10, -0x4($s0)
    MEM_W(-0X4, ctx->r16) = ctx->f10.u32l;
    after_2:
    // 0x80008434: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x80008438: jal         0x80023090
    // 0x8000843C: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    __sinf_recomp(rdram, ctx);
        goto after_3;
    // 0x8000843C: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_3:
    // 0x80008440: add.s       $f16, $f0, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f22.fl;
    // 0x80008444: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80008448: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8000844C: add.s       $f20, $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f26.fl;
    // 0x80008450: mul.s       $f8, $f16, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f24.fl);
    // 0x80008454: bne         $s2, $s3, L_80008408
    if (ctx->r18 != ctx->r19) {
        // 0x80008458: swc1        $f8, -0x4($s1)
        MEM_W(-0X4, ctx->r17) = ctx->f8.u32l;
            goto L_80008408;
    }
    // 0x80008458: swc1        $f8, -0x4($s1)
    MEM_W(-0X4, ctx->r17) = ctx->f8.u32l;
    // 0x8000845C: lw          $t3, 0x5C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X5C);
L_80008460:
    // 0x80008460: lw          $t7, 0x98($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X98);
L_80008464:
    // 0x80008464: lw          $t6, 0x9C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X9C);
    // 0x80008468: sll         $a2, $s4, 2
    ctx->r6 = S32(ctx->r20 << 2);
    // 0x8000846C: lwc1        $f18, 0x0($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0X0);
    // 0x80008470: addu        $t9, $t7, $a2
    ctx->r25 = ADD32(ctx->r15, ctx->r6);
    // 0x80008474: addu        $t4, $t6, $a2
    ctx->r12 = ADD32(ctx->r14, ctx->r6);
    // 0x80008478: swc1        $f18, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f18.u32l;
    // 0x8000847C: lwc1        $f4, 0x0($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X0);
    // 0x80008480: sll         $t1, $s4, 2
    ctx->r9 = S32(ctx->r20 << 2);
    // 0x80008484: addiu       $a1, $t3, -0x1
    ctx->r5 = ADD32(ctx->r11, -0X1);
    // 0x80008488: swc1        $f4, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f4.u32l;
    // 0x8000848C: lw          $t8, 0xA4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA4);
    // 0x80008490: lw          $t5, 0x98($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X98);
    // 0x80008494: lw          $t9, 0x9C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X9C);
    // 0x80008498: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x8000849C: addu        $t0, $t1, $t8
    ctx->r8 = ADD32(ctx->r9, ctx->r24);
    // 0x800084A0: addu        $s1, $t1, $t0
    ctx->r17 = ADD32(ctx->r9, ctx->r8);
    // 0x800084A4: slti        $at, $s4, 0x2
    ctx->r1 = SIGNED(ctx->r20) < 0X2 ? 1 : 0;
    // 0x800084A8: addu        $t2, $t7, $t5
    ctx->r10 = ADD32(ctx->r15, ctx->r13);
    // 0x800084AC: addiu       $s0, $t0, 0x4
    ctx->r16 = ADD32(ctx->r8, 0X4);
    // 0x800084B0: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x800084B4: or          $a3, $t2, $zero
    ctx->r7 = ctx->r10 | 0;
    // 0x800084B8: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x800084BC: addiu       $v0, $t5, 0x4
    ctx->r2 = ADD32(ctx->r13, 0X4);
    // 0x800084C0: addiu       $v1, $t9, 0x4
    ctx->r3 = ADD32(ctx->r25, 0X4);
    // 0x800084C4: bne         $at, $zero, L_80008688
    if (ctx->r1 != 0) {
        // 0x800084C8: addu        $a0, $t7, $t9
        ctx->r4 = ADD32(ctx->r15, ctx->r25);
            goto L_80008688;
    }
    // 0x800084C8: addu        $a0, $t7, $t9
    ctx->r4 = ADD32(ctx->r15, ctx->r25);
    // 0x800084CC: addiu       $a2, $s4, -0x1
    ctx->r6 = ADD32(ctx->r20, -0X1);
    // 0x800084D0: andi        $t6, $a2, 0x3
    ctx->r14 = ctx->r6 & 0X3;
    // 0x800084D4: beq         $t6, $zero, L_80008548
    if (ctx->r14 == 0) {
        // 0x800084D8: addiu       $a1, $t6, 0x1
        ctx->r5 = ADD32(ctx->r14, 0X1);
            goto L_80008548;
    }
    // 0x800084D8: addiu       $a1, $t6, 0x1
    ctx->r5 = ADD32(ctx->r14, 0X1);
L_800084DC:
    // 0x800084DC: lwc1        $f6, 0x0($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X0);
    // 0x800084E0: lwc1        $f10, 0x0($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X0);
    // 0x800084E4: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800084E8: lwc1        $f18, 0x0($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800084EC: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800084F0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800084F4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800084F8: mul.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x800084FC: addiu       $a0, $a0, -0x4
    ctx->r4 = ADD32(ctx->r4, -0X4);
    // 0x80008500: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80008504: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80008508: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8000850C: addiu       $a3, $a3, -0x4
    ctx->r7 = ADD32(ctx->r7, -0X4);
    // 0x80008510: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x80008514: swc1        $f6, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f6.u32l;
    // 0x80008518: lwc1        $f8, -0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, -0X4);
    // 0x8000851C: lwc1        $f10, -0x4($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, -0X4);
    // 0x80008520: lwc1        $f4, -0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, -0X4);
    // 0x80008524: lwc1        $f16, 0x4($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X4);
    // 0x80008528: mul.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x8000852C: nop

    // 0x80008530: mul.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x80008534: sub.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x80008538: bne         $a1, $s2, L_800084DC
    if (ctx->r5 != ctx->r18) {
        // 0x8000853C: swc1        $f10, 0x4($a0)
        MEM_W(0X4, ctx->r4) = ctx->f10.u32l;
            goto L_800084DC;
    }
    // 0x8000853C: swc1        $f10, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f10.u32l;
    // 0x80008540: beql        $s2, $s4, L_80008688
    if (ctx->r18 == ctx->r20) {
        // 0x80008544: or          $a3, $t2, $zero
        ctx->r7 = ctx->r10 | 0;
            goto L_80008688;
    }
    goto skip_1;
    // 0x80008544: or          $a3, $t2, $zero
    ctx->r7 = ctx->r10 | 0;
    skip_1:
L_80008548:
    // 0x80008548: lwc1        $f8, 0x0($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X0);
    // 0x8000854C: lwc1        $f16, 0x0($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80008550: lwc1        $f18, 0x0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80008554: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80008558: mul.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8000855C: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80008560: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80008564: mul.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x80008568: addiu       $a0, $a0, -0x10
    ctx->r4 = ADD32(ctx->r4, -0X10);
    // 0x8000856C: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80008570: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x80008574: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x80008578: addiu       $a3, $a3, -0x10
    ctx->r7 = ADD32(ctx->r7, -0X10);
    // 0x8000857C: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80008580: swc1        $f8, -0x10($v1)
    MEM_W(-0X10, ctx->r3) = ctx->f8.u32l;
    // 0x80008584: lwc1        $f18, -0x10($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, -0X10);
    // 0x80008588: lwc1        $f16, -0x10($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, -0X10);
    // 0x8000858C: lwc1        $f10, -0x10($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, -0X10);
    // 0x80008590: lwc1        $f4, 0x10($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X10);
    // 0x80008594: mul.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80008598: nop

    // 0x8000859C: mul.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x800085A0: sub.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800085A4: swc1        $f16, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f16.u32l;
    // 0x800085A8: lwc1        $f18, 0xC($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0XC);
    // 0x800085AC: lwc1        $f4, -0xC($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, -0XC);
    // 0x800085B0: lwc1        $f6, -0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, -0XC);
    // 0x800085B4: lwc1        $f8, -0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, -0XC);
    // 0x800085B8: mul.s       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800085BC: nop

    // 0x800085C0: mul.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800085C4: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800085C8: swc1        $f18, -0xC($v1)
    MEM_W(-0XC, ctx->r3) = ctx->f18.u32l;
    // 0x800085CC: lwc1        $f6, -0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, -0XC);
    // 0x800085D0: lwc1        $f4, -0xC($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, -0XC);
    // 0x800085D4: lwc1        $f16, -0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, -0XC);
    // 0x800085D8: lwc1        $f10, 0xC($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0XC);
    // 0x800085DC: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800085E0: nop

    // 0x800085E4: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800085E8: sub.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x800085EC: swc1        $f4, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f4.u32l;
    // 0x800085F0: lwc1        $f6, 0x8($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X8);
    // 0x800085F4: lwc1        $f10, -0x8($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, -0X8);
    // 0x800085F8: lwc1        $f8, -0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, -0X8);
    // 0x800085FC: lwc1        $f18, -0x8($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, -0X8);
    // 0x80008600: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80008604: nop

    // 0x80008608: mul.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x8000860C: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x80008610: swc1        $f6, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = ctx->f6.u32l;
    // 0x80008614: lwc1        $f8, -0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, -0X8);
    // 0x80008618: lwc1        $f10, -0x8($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, -0X8);
    // 0x8000861C: lwc1        $f4, -0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, -0X8);
    // 0x80008620: lwc1        $f16, 0x8($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X8);
    // 0x80008624: mul.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80008628: nop

    // 0x8000862C: mul.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x80008630: sub.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x80008634: swc1        $f10, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f10.u32l;
    // 0x80008638: lwc1        $f8, 0x4($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X4);
    // 0x8000863C: lwc1        $f16, -0x4($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, -0X4);
    // 0x80008640: lwc1        $f18, -0x4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, -0X4);
    // 0x80008644: lwc1        $f6, -0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, -0X4);
    // 0x80008648: mul.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8000864C: nop

    // 0x80008650: mul.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x80008654: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80008658: swc1        $f8, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f8.u32l;
    // 0x8000865C: lwc1        $f18, -0x4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, -0X4);
    // 0x80008660: lwc1        $f16, -0x4($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, -0X4);
    // 0x80008664: lwc1        $f10, -0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, -0X4);
    // 0x80008668: lwc1        $f4, 0x4($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X4);
    // 0x8000866C: mul.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80008670: nop

    // 0x80008674: mul.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x80008678: sub.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8000867C: bne         $s2, $s3, L_80008548
    if (ctx->r18 != ctx->r19) {
        // 0x80008680: swc1        $f16, 0x4($a0)
        MEM_W(0X4, ctx->r4) = ctx->f16.u32l;
            goto L_80008548;
    }
    // 0x80008680: swc1        $f16, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f16.u32l;
    // 0x80008684: or          $a3, $t2, $zero
    ctx->r7 = ctx->r10 | 0;
L_80008688:
    // 0x80008688: lw          $a0, 0x9C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X9C);
    // 0x8000868C: lw          $a1, 0xA0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA0);
    // 0x80008690: lw          $a2, 0xA4($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XA4);
    // 0x80008694: sw          $a3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r7;
    // 0x80008698: jal         0x80008780
    // 0x8000869C: sw          $t1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r9;
    AudioSynth_HartleyTransform(rdram, ctx);
        goto after_4;
    // 0x8000869C: sw          $t1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r9;
    after_4:
    // 0x800086A0: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x800086A4: lw          $v1, 0x9C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X9C);
    // 0x800086A8: lw          $a3, 0x7C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X7C);
    // 0x800086AC: lw          $v0, 0x98($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X98);
    // 0x800086B0: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800086B4: blez        $s4, L_80008750
    if (SIGNED(ctx->r20) <= 0) {
        // 0x800086B8: addu        $a0, $t1, $v1
        ctx->r4 = ADD32(ctx->r9, ctx->r3);
            goto L_80008750;
    }
    // 0x800086B8: addu        $a0, $t1, $v1
    ctx->r4 = ADD32(ctx->r9, ctx->r3);
    // 0x800086BC: andi        $a2, $s4, 0x3
    ctx->r6 = ctx->r20 & 0X3;
    // 0x800086C0: beq         $a2, $zero, L_800086F8
    if (ctx->r6 == 0) {
        // 0x800086C4: or          $a1, $a2, $zero
        ctx->r5 = ctx->r6 | 0;
            goto L_800086F8;
    }
    // 0x800086C4: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
L_800086C8:
    // 0x800086C8: lwc1        $f18, 0x0($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800086CC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800086D0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800086D4: swc1        $f18, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f18.u32l;
    // 0x800086D8: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800086DC: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800086E0: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800086E4: addiu       $a3, $a3, -0x8
    ctx->r7 = ADD32(ctx->r7, -0X8);
    // 0x800086E8: bne         $a1, $s2, L_800086C8
    if (ctx->r5 != ctx->r18) {
        // 0x800086EC: swc1        $f4, 0x8($a3)
        MEM_W(0X8, ctx->r7) = ctx->f4.u32l;
            goto L_800086C8;
    }
    // 0x800086EC: swc1        $f4, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f4.u32l;
    // 0x800086F0: beql        $s2, $s4, L_80008754
    if (ctx->r18 == ctx->r20) {
        // 0x800086F4: lw          $ra, 0x4C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X4C);
            goto L_80008754;
    }
    goto skip_2;
    // 0x800086F4: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    skip_2:
L_800086F8:
    // 0x800086F8: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800086FC: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80008700: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80008704: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
    // 0x80008708: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8000870C: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x80008710: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // 0x80008714: swc1        $f6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f6.u32l;
    // 0x80008718: lwc1        $f8, -0xC($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, -0XC);
    // 0x8000871C: addiu       $a3, $a3, -0x20
    ctx->r7 = ADD32(ctx->r7, -0X20);
    // 0x80008720: swc1        $f8, -0x18($v0)
    MEM_W(-0X18, ctx->r2) = ctx->f8.u32l;
    // 0x80008724: lwc1        $f16, -0xC($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, -0XC);
    // 0x80008728: swc1        $f16, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->f16.u32l;
    // 0x8000872C: lwc1        $f18, -0x8($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, -0X8);
    // 0x80008730: swc1        $f18, -0x10($v0)
    MEM_W(-0X10, ctx->r2) = ctx->f18.u32l;
    // 0x80008734: lwc1        $f4, -0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, -0X8);
    // 0x80008738: swc1        $f4, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->f4.u32l;
    // 0x8000873C: lwc1        $f10, -0x4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, -0X4);
    // 0x80008740: swc1        $f10, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f10.u32l;
    // 0x80008744: lwc1        $f6, -0x4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, -0X4);
    // 0x80008748: bne         $s2, $s3, L_800086F8
    if (ctx->r18 != ctx->r19) {
        // 0x8000874C: swc1        $f6, 0x8($a3)
        MEM_W(0X8, ctx->r7) = ctx->f6.u32l;
            goto L_800086F8;
    }
    // 0x8000874C: swc1        $f6, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f6.u32l;
L_80008750:
    // 0x80008750: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_80008754:
    // 0x80008754: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80008758: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8000875C: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80008760: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x80008764: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x80008768: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x8000876C: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x80008770: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x80008774: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x80008778: jr          $ra
    // 0x8000877C: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x8000877C: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void Effect_Effect364_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007B960: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007B964: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007B968: lh          $t6, 0x4A($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X4A);
    // 0x8007B96C: lh          $t7, 0x46($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X46);
    // 0x8007B970: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007B974: lwc1        $f6, 0x73E0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X73E0);
    // 0x8007B978: lwc1        $f4, 0x70($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X70);
    // 0x8007B97C: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x8007B980: sh          $t8, 0x4A($a0)
    MEM_H(0X4A, ctx->r4) = ctx->r24;
    // 0x8007B984: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8007B988: lh          $t9, 0x4A($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X4A);
    // 0x8007B98C: addiu       $a1, $a0, 0x80
    ctx->r5 = ADD32(ctx->r4, 0X80);
    // 0x8007B990: bgez        $t9, L_8007B9A4
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8007B994: swc1        $f8, 0x70($a0)
        MEM_W(0X70, ctx->r4) = ctx->f8.u32l;
            goto L_8007B9A4;
    }
    // 0x8007B994: swc1        $f8, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f8.u32l;
    // 0x8007B998: jal         0x80060FBC
    // 0x8007B99C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    Object_Kill(rdram, ctx);
        goto after_0;
    // 0x8007B99C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8007B9A0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_8007B9A4:
    // 0x8007B9A4: lh          $t0, 0x48($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X48);
    // 0x8007B9A8: lwc1        $f10, 0x18($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X18);
    // 0x8007B9AC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007B9B0: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x8007B9B4: lwc1        $f6, 0x58($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X58);
    // 0x8007B9B8: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8007B9BC: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8007B9C0: swc1        $f4, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f4.u32l;
    // 0x8007B9C4: lwc1        $f8, 0x73E4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X73E4);
    // 0x8007B9C8: add.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8007B9CC: swc1        $f16, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f16.u32l;
    // 0x8007B9D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007B9D4: jr          $ra
    // 0x8007B9D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8007B9D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void Effect_FireSmoke2_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007D748: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8007D74C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8007D750: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8007D754: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8007D758: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x8007D75C: lbu         $t6, 0x7C98($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X7C98);
    // 0x8007D760: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007D764: bnel        $t6, $zero, L_8007D7D4
    if (ctx->r14 != 0) {
        // 0x8007D768: lhu         $t2, 0x50($s0)
        ctx->r10 = MEM_HU(ctx->r16, 0X50);
            goto L_8007D7D4;
    }
    goto skip_0;
    // 0x8007D768: lhu         $t2, 0x50($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X50);
    skip_0:
    // 0x8007D76C: lwc1        $f4, 0x58($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X58);
    // 0x8007D770: lwc1        $f6, 0x7440($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7440);
    // 0x8007D774: lhu         $t7, 0x50($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X50);
    // 0x8007D778: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8007D77C: bne         $t7, $zero, L_8007D810
    if (ctx->r15 != 0) {
        // 0x8007D780: swc1        $f8, 0x58($s0)
        MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
            goto L_8007D810;
    }
    // 0x8007D780: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
    // 0x8007D784: lbu         $v0, 0x4C($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X4C);
    // 0x8007D788: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8007D78C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8007D790: slti        $at, $v0, 0x10
    ctx->r1 = SIGNED(ctx->r2) < 0X10 ? 1 : 0;
    // 0x8007D794: bne         $at, $zero, L_8007D7AC
    if (ctx->r1 != 0) {
        // 0x8007D798: addiu       $t0, $v0, 0x2
        ctx->r8 = ADD32(ctx->r2, 0X2);
            goto L_8007D7AC;
    }
    // 0x8007D798: addiu       $t0, $v0, 0x2
    ctx->r8 = ADD32(ctx->r2, 0X2);
    // 0x8007D79C: addiu       $t9, $v0, 0x1
    ctx->r25 = ADD32(ctx->r2, 0X1);
    // 0x8007D7A0: sh          $t8, 0x50($s0)
    MEM_H(0X50, ctx->r16) = ctx->r24;
    // 0x8007D7A4: b           L_8007D7B0
    // 0x8007D7A8: sb          $t9, 0x4C($s0)
    MEM_B(0X4C, ctx->r16) = ctx->r25;
        goto L_8007D7B0;
    // 0x8007D7A8: sb          $t9, 0x4C($s0)
    MEM_B(0X4C, ctx->r16) = ctx->r25;
L_8007D7AC:
    // 0x8007D7AC: sb          $t0, 0x4C($s0)
    MEM_B(0X4C, ctx->r16) = ctx->r8;
L_8007D7B0:
    // 0x8007D7B0: lbu         $t1, 0x4C($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X4C);
    // 0x8007D7B4: slti        $at, $t1, 0x15
    ctx->r1 = SIGNED(ctx->r9) < 0X15 ? 1 : 0;
    // 0x8007D7B8: bne         $at, $zero, L_8007D810
    if (ctx->r1 != 0) {
        // 0x8007D7BC: nop
    
            goto L_8007D810;
    }
    // 0x8007D7BC: nop

    // 0x8007D7C0: jal         0x80060FBC
    // 0x8007D7C4: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    Object_Kill(rdram, ctx);
        goto after_0;
    // 0x8007D7C4: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    after_0:
    // 0x8007D7C8: b           L_8007D810
    // 0x8007D7CC: nop

        goto L_8007D810;
    // 0x8007D7CC: nop

    // 0x8007D7D0: lhu         $t2, 0x50($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X50);
L_8007D7D4:
    // 0x8007D7D4: bnel        $t2, $zero, L_8007D808
    if (ctx->r10 != 0) {
        // 0x8007D7D8: lh          $t6, 0x44($s0)
        ctx->r14 = MEM_H(ctx->r16, 0X44);
            goto L_8007D808;
    }
    goto skip_1;
    // 0x8007D7D8: lh          $t6, 0x44($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X44);
    skip_1:
    // 0x8007D7DC: lbu         $t3, 0x4C($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X4C);
    // 0x8007D7E0: sh          $zero, 0x50($s0)
    MEM_H(0X50, ctx->r16) = 0;
    // 0x8007D7E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8007D7E8: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8007D7EC: andi        $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 & 0XFF;
    // 0x8007D7F0: slti        $at, $t5, 0xE
    ctx->r1 = SIGNED(ctx->r13) < 0XE ? 1 : 0;
    // 0x8007D7F4: bne         $at, $zero, L_8007D804
    if (ctx->r1 != 0) {
        // 0x8007D7F8: sb          $t4, 0x4C($s0)
        MEM_B(0X4C, ctx->r16) = ctx->r12;
            goto L_8007D804;
    }
    // 0x8007D7F8: sb          $t4, 0x4C($s0)
    MEM_B(0X4C, ctx->r16) = ctx->r12;
    // 0x8007D7FC: jal         0x80060FBC
    // 0x8007D800: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    Object_Kill(rdram, ctx);
        goto after_1;
    // 0x8007D800: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    after_1:
L_8007D804:
    // 0x8007D804: lh          $t6, 0x44($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X44);
L_8007D808:
    // 0x8007D808: addiu       $t7, $t6, -0xF
    ctx->r15 = ADD32(ctx->r14, -0XF);
    // 0x8007D80C: sh          $t7, 0x44($s0)
    MEM_H(0X44, ctx->r16) = ctx->r15;
L_8007D810:
    // 0x8007D810: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8007D814: addiu       $v0, $v0, -0x7C94
    ctx->r2 = ADD32(ctx->r2, -0X7C94);
    // 0x8007D818: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8007D81C: lwc1        $f0, 0x6C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x8007D820: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8007D824: addiu       $a0, $s0, 0x6C
    ctx->r4 = ADD32(ctx->r16, 0X6C);
    // 0x8007D828: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x8007D82C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8007D830: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8007D834: lui         $a3, 0x3DCC
    ctx->r7 = S32(0X3DCC << 16);
    // 0x8007D838: bc1fl       L_8007D88C
    if (!c1cs) {
        // 0x8007D83C: ori         $a3, $a3, 0xCCCD
        ctx->r7 = ctx->r7 | 0XCCCD;
            goto L_8007D88C;
    }
    goto skip_2;
    // 0x8007D83C: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    skip_2:
    // 0x8007D840: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x8007D844: lwc1        $f16, 0x4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8007D848: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8007D84C: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8007D850: swc1        $f16, -0x7C90($at)
    MEM_W(-0X7C90, ctx->r1) = ctx->f16.u32l;
    // 0x8007D854: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8007D858: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8007D85C: addiu       $t9, $zero, 0x32
    ctx->r25 = ADD32(0, 0X32);
    // 0x8007D860: swc1        $f18, -0x7C8C($at)
    MEM_W(-0X7C8C, ctx->r1) = ctx->f18.u32l;
    // 0x8007D864: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8007D868: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8007D86C: swc1        $f4, -0x7C88($at)
    MEM_W(-0X7C88, ctx->r1) = ctx->f4.u32l;
    // 0x8007D870: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8007D874: sw          $t8, -0x7CA0($at)
    MEM_W(-0X7CA0, ctx->r1) = ctx->r24;
    // 0x8007D878: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8007D87C: sw          $t9, -0x7C9C($at)
    MEM_W(-0X7C9C, ctx->r1) = ctx->r25;
    // 0x8007D880: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8007D884: sw          $zero, -0x7C98($at)
    MEM_W(-0X7C98, ctx->r1) = 0;
    // 0x8007D888: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
L_8007D88C:
    // 0x8007D88C: jal         0x8009BC2C
    // 0x8007D890: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_2;
    // 0x8007D890: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x8007D894: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8007D898: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8007D89C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8007D8A0: jr          $ra
    // 0x8007D8A4: nop

    return;
    // 0x8007D8A4: nop

;}
RECOMP_FUNC void Math_NearbyIntF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001FB88: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001FB8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001FB90: jal         0x8001FF40
    // 0x8001FB94: nop

    __nearbyintf_recomp(rdram, ctx);
        goto after_0;
    // 0x8001FB94: nop

    after_0:
    // 0x8001FB98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001FB9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001FBA0: jr          $ra
    // 0x8001FBA4: nop

    return;
    // 0x8001FBA4: nop

;}
RECOMP_FUNC void ItemMeteoWarp_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005CDA8: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8005CDAC: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x8005CDB0: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8005CDB4: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x8005CDB8: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x8005CDBC: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x8005CDC0: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x8005CDC4: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x8005CDC8: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x8005CDCC: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x8005CDD0: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x8005CDD4: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x8005CDD8: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x8005CDDC: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8005CDE0: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x8005CDE4: lw          $t7, 0x78A0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X78A0);
    // 0x8005CDE8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8005CDEC: lw          $t6, -0x7D80($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7D80);
    // 0x8005CDF0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8005CDF4: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8005CDF8: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8005CDFC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005CE00: lwc1        $f10, 0x7D20($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x8005CE04: lwc1        $f8, 0xC($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0XC);
    // 0x8005CE08: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8005CE0C: sll         $t8, $t8, 5
    ctx->r24 = S32(ctx->r24 << 5);
    // 0x8005CE10: addu        $v0, $t6, $t8
    ctx->r2 = ADD32(ctx->r14, ctx->r24);
    // 0x8005CE14: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8005CE18: lwc1        $f4, 0x40($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X40);
    // 0x8005CE1C: lwc1        $f18, 0x48($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X48);
    // 0x8005CE20: lwc1        $f6, 0x4($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X4);
    // 0x8005CE24: sub.s       $f14, $f18, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x8005CE28: jal         0x80005100
    // 0x8005CE2C: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    Math_Atan2F(rdram, ctx);
        goto after_0;
    // 0x8005CE2C: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    after_0:
    // 0x8005CE30: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8005CE34: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8005CE38: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005CE3C: lwc1        $f8, 0x62AC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X62AC);
    // 0x8005CE40: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8005CE44: lbu         $t9, 0x46($s3)
    ctx->r25 = MEM_BU(ctx->r19, 0X46);
    // 0x8005CE48: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x8005CE4C: addiu       $s2, $s2, 0x7E64
    ctx->r18 = ADD32(ctx->r18, 0X7E64);
    // 0x8005CE50: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8005CE54: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8005CE58: beq         $t9, $zero, L_8005CE98
    if (ctx->r25 == 0) {
        // 0x8005CE5C: swc1        $f10, 0x14($s3)
        MEM_W(0X14, ctx->r19) = ctx->f10.u32l;
            goto L_8005CE98;
    }
    // 0x8005CE5C: swc1        $f10, 0x14($s3)
    MEM_W(0X14, ctx->r19) = ctx->f10.u32l;
    // 0x8005CE60: jal         0x800B8DD0
    // 0x8005CE64: addiu       $a1, $zero, 0x29
    ctx->r5 = ADD32(0, 0X29);
    RCP_SetupDL(rdram, ctx);
        goto after_1;
    // 0x8005CE64: addiu       $a1, $zero, 0x29
    ctx->r5 = ADD32(0, 0X29);
    after_1:
    // 0x8005CE68: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x8005CE6C: lui         $t1, 0xFA00
    ctx->r9 = S32(0XFA00 << 16);
    // 0x8005CE70: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x8005CE74: addiu       $t0, $v1, 0x8
    ctx->r8 = ADD32(ctx->r3, 0X8);
    // 0x8005CE78: sw          $t0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r8;
    // 0x8005CE7C: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x8005CE80: lh          $t2, 0x44($s3)
    ctx->r10 = MEM_H(ctx->r19, 0X44);
    // 0x8005CE84: andi        $t3, $t2, 0xFF
    ctx->r11 = ctx->r10 & 0XFF;
    // 0x8005CE88: or          $t4, $t3, $at
    ctx->r12 = ctx->r11 | ctx->r1;
    // 0x8005CE8C: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x8005CE90: b           L_8005CEE0
    // 0x8005CE94: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
        goto L_8005CEE0;
    // 0x8005CE94: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
L_8005CE98:
    // 0x8005CE98: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8005CE9C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8005CEA0: lw          $t7, -0x7C24($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7C24);
    // 0x8005CEA4: lw          $t5, -0x7C28($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X7C28);
    // 0x8005CEA8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8005CEAC: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8005CEB0: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x8005CEB4: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x8005CEB8: lw          $a3, -0x7CC8($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X7CC8);
    // 0x8005CEBC: lw          $a2, -0x7CD0($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7CD0);
    // 0x8005CEC0: lw          $a1, -0x7CD8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7CD8);
    // 0x8005CEC4: lw          $a0, -0x7CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7CE0);
    // 0x8005CEC8: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8005CECC: jal         0x800B9B38
    // 0x8005CED0: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    RCP_SetupDL_60(rdram, ctx);
        goto after_2;
    // 0x8005CED0: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_2:
    // 0x8005CED4: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x8005CED8: addiu       $s2, $s2, 0x7E64
    ctx->r18 = ADD32(ctx->r18, 0X7E64);
    // 0x8005CEDC: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
L_8005CEE0:
    // 0x8005CEE0: lui         $t9, 0x2
    ctx->r25 = S32(0X2 << 16);
    // 0x8005CEE4: ori         $t9, $t9, 0x2000
    ctx->r25 = ctx->r25 | 0X2000;
    // 0x8005CEE8: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8005CEEC: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
    // 0x8005CEF0: lui         $t8, 0xB600
    ctx->r24 = S32(0XB600 << 16);
    // 0x8005CEF4: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8005CEF8: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8005CEFC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005CF00: lwc1        $f26, 0x62B0($at)
    ctx->f26.u32l = MEM_W(ctx->r1, 0X62B0);
    // 0x8005CF04: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x8005CF08: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x8005CF0C: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8005CF10: lui         $s4, 0x103
    ctx->r20 = S32(0X103 << 16);
    // 0x8005CF14: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x8005CF18: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8005CF1C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8005CF20: addiu       $s1, $s1, -0x4C40
    ctx->r17 = ADD32(ctx->r17, -0X4C40);
    // 0x8005CF24: addiu       $s4, $s4, -0x180
    ctx->r20 = ADD32(ctx->r20, -0X180);
    // 0x8005CF28: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8005CF2C: addiu       $s6, $zero, 0x7
    ctx->r22 = ADD32(0, 0X7);
    // 0x8005CF30: lui         $s5, 0x600
    ctx->r21 = S32(0X600 << 16);
L_8005CF34:
    // 0x8005CF34: jal         0x80005708
    // 0x8005CF38: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Push(rdram, ctx);
        goto after_3;
    // 0x8005CF38: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x8005CF3C: mtc1        $s0, $f18
    ctx->f18.u32l = ctx->r16;
    // 0x8005CF40: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8005CF44: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8005CF48: cvt.s.w     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8005CF4C: mul.s       $f4, $f16, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f22.fl);
    // 0x8005CF50: div.s       $f6, $f4, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f24.fl);
    // 0x8005CF54: mul.s       $f8, $f6, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f26.fl);
    // 0x8005CF58: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8005CF5C: jal         0x80005FE0
    // 0x8005CF60: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_4;
    // 0x8005CF60: nop

    after_4:
    // 0x8005CF64: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8005CF68: lw          $a2, 0x68($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X68);
    // 0x8005CF6C: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x8005CF70: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8005CF74: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8005CF78: jal         0x80005B00
    // 0x8005CF7C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_5;
    // 0x8005CF7C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_5:
    // 0x8005CF80: jal         0x80006EB8
    // 0x8005CF84: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_6;
    // 0x8005CF84: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_6:
    // 0x8005CF88: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x8005CF8C: addiu       $t1, $v1, 0x8
    ctx->r9 = ADD32(ctx->r3, 0X8);
    // 0x8005CF90: sw          $t1, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r9;
    // 0x8005CF94: sw          $s4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r20;
    // 0x8005CF98: sw          $s5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r21;
    // 0x8005CF9C: jal         0x80005740
    // 0x8005CFA0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_7;
    // 0x8005CFA0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_7:
    // 0x8005CFA4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8005CFA8: bne         $s0, $s6, L_8005CF34
    if (ctx->r16 != ctx->r22) {
        // 0x8005CFAC: nop
    
            goto L_8005CF34;
    }
    // 0x8005CFAC: nop

    // 0x8005CFB0: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x8005CFB4: lui         $t4, 0x2
    ctx->r12 = S32(0X2 << 16);
    // 0x8005CFB8: ori         $t4, $t4, 0x2000
    ctx->r12 = ctx->r12 | 0X2000;
    // 0x8005CFBC: addiu       $t2, $v1, 0x8
    ctx->r10 = ADD32(ctx->r3, 0X8);
    // 0x8005CFC0: sw          $t2, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r10;
    // 0x8005CFC4: lui         $t3, 0xB700
    ctx->r11 = S32(0XB700 << 16);
    // 0x8005CFC8: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x8005CFCC: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x8005CFD0: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x8005CFD4: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8005CFD8: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x8005CFDC: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x8005CFE0: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x8005CFE4: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x8005CFE8: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x8005CFEC: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x8005CFF0: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x8005CFF4: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x8005CFF8: lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X54);
    // 0x8005CFFC: lw          $s6, 0x58($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X58);
    // 0x8005D000: jr          $ra
    // 0x8005D004: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8005D004: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void Audio_AdsrUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80013B90: lbu         $v1, 0x1($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X1);
    // 0x80013B94: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x80013B98: sltiu       $at, $v1, 0x9
    ctx->r1 = ctx->r3 < 0X9 ? 1 : 0;
    // 0x80013B9C: beq         $at, $zero, L_80013E14
    if (ctx->r1 == 0) {
        // 0x80013BA0: or          $a1, $v1, $zero
        ctx->r5 = ctx->r3 | 0;
            goto L_80013E14;
    }
    // 0x80013BA0: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x80013BA4: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x80013BA8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80013BAC: addu        $at, $at, $t6
    gpr jr_addend_80013BB4 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80013BB0: lw          $t6, -0x7910($at)
    ctx->r14 = ADD32(ctx->r1, -0X7910);
    // 0x80013BB4: jr          $t6
    // 0x80013BB8: nop

    switch (jr_addend_80013BB4 >> 2) {
        case 0: goto L_80013BBC; break;
        case 1: goto L_80013BC8; break;
        case 2: goto L_80013BDC; break;
        case 3: goto L_80013BE8; break;
        case 4: goto L_80013D44; break;
        case 5: goto L_80013E14; break;
        case 6: goto L_80013D74; break;
        case 7: goto L_80013D74; break;
        case 8: goto L_80013DF4; break;
        default: switch_error(__func__, 0x80013BB4, 0x800C86F0);
    }
    // 0x80013BB8: nop

L_80013BBC:
    // 0x80013BBC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80013BC0: jr          $ra
    // 0x80013BC4: nop

    return;
    // 0x80013BC4: nop

L_80013BC8:
    // 0x80013BC8: andi        $t7, $v0, 0x40
    ctx->r15 = ctx->r2 & 0X40;
    // 0x80013BCC: beq         $t7, $zero, L_80013BDC
    if (ctx->r15 == 0) {
        // 0x80013BD0: addiu       $t8, $zero, 0x5
        ctx->r24 = ADD32(0, 0X5);
            goto L_80013BDC;
    }
    // 0x80013BD0: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x80013BD4: b           L_80013E14
    // 0x80013BD8: sb          $t8, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r24;
        goto L_80013E14;
    // 0x80013BD8: sb          $t8, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r24;
L_80013BDC:
    // 0x80013BDC: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x80013BE0: sh          $zero, 0x2($a0)
    MEM_H(0X2, ctx->r4) = 0;
    // 0x80013BE4: sb          $t9, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r25;
L_80013BE8:
    // 0x80013BE8: lh          $t1, 0x2($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X2);
    // 0x80013BEC: lw          $t0, 0x20($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X20);
    // 0x80013BF0: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x80013BF4: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80013BF8: addu        $v1, $t0, $t2
    ctx->r3 = ADD32(ctx->r8, ctx->r10);
    // 0x80013BFC: lh          $t3, 0x0($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X0);
    // 0x80013C00: sh          $t3, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r11;
    // 0x80013C04: lh          $a2, 0x4($a0)
    ctx->r6 = MEM_H(ctx->r4, 0X4);
    // 0x80013C08: beq         $a2, $at, L_80013C4C
    if (ctx->r6 == ctx->r1) {
        // 0x80013C0C: or          $a1, $a2, $zero
        ctx->r5 = ctx->r6 | 0;
            goto L_80013C4C;
    }
    // 0x80013C0C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80013C10: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80013C14: beq         $a2, $at, L_80013C40
    if (ctx->r6 == ctx->r1) {
        // 0x80013C18: addiu       $at, $zero, -0x1
        ctx->r1 = ADD32(0, -0X1);
            goto L_80013C40;
    }
    // 0x80013C18: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80013C1C: beql        $a2, $at, L_80013C38
    if (ctx->r6 == ctx->r1) {
        // 0x80013C20: addiu       $t4, $zero, 0x5
        ctx->r12 = ADD32(0, 0X5);
            goto L_80013C38;
    }
    goto skip_0;
    // 0x80013C20: addiu       $t4, $zero, 0x5
    ctx->r12 = ADD32(0, 0X5);
    skip_0:
    // 0x80013C24: bne         $a2, $zero, L_80013C58
    if (ctx->r6 != 0) {
        // 0x80013C28: slti        $at, $a2, 0x4
        ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
            goto L_80013C58;
    }
    // 0x80013C28: slti        $at, $a2, 0x4
    ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
    // 0x80013C2C: b           L_80013D34
    // 0x80013C30: sb          $zero, 0x1($a0)
    MEM_B(0X1, ctx->r4) = 0;
        goto L_80013D34;
    // 0x80013C30: sb          $zero, 0x1($a0)
    MEM_B(0X1, ctx->r4) = 0;
    // 0x80013C34: addiu       $t4, $zero, 0x5
    ctx->r12 = ADD32(0, 0X5);
L_80013C38:
    // 0x80013C38: b           L_80013D34
    // 0x80013C3C: sb          $t4, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r12;
        goto L_80013D34;
    // 0x80013C3C: sb          $t4, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r12;
L_80013C40:
    // 0x80013C40: lh          $t5, 0x2($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X2);
    // 0x80013C44: b           L_80013BE8
    // 0x80013C48: sh          $t5, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r13;
        goto L_80013BE8;
    // 0x80013C48: sh          $t5, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r13;
L_80013C4C:
    // 0x80013C4C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80013C50: b           L_80013D34
    // 0x80013C54: sb          $t6, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r14;
        goto L_80013D34;
    // 0x80013C54: sb          $t6, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r14;
L_80013C58:
    // 0x80013C58: bne         $at, $zero, L_80013CC0
    if (ctx->r1 != 0) {
        // 0x80013C5C: lui         $v1, 0x8015
        ctx->r3 = S32(0X8015 << 16);
            goto L_80013CC0;
    }
    // 0x80013C5C: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x80013C60: addiu       $v1, $v1, 0x5C78
    ctx->r3 = ADD32(ctx->r3, 0X5C78);
    // 0x80013C64: lh          $t7, 0xC($v1)
    ctx->r15 = MEM_H(ctx->r3, 0XC);
    // 0x80013C68: lh          $t9, 0x0($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X0);
    // 0x80013C6C: multu       $a2, $t7
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80013C70: mflo        $t8
    ctx->r24 = lo;
    // 0x80013C74: nop

    // 0x80013C78: nop

    // 0x80013C7C: div         $zero, $t8, $t9
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r25))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r25)));
    // 0x80013C80: bne         $t9, $zero, L_80013C8C
    if (ctx->r25 != 0) {
        // 0x80013C84: nop
    
            goto L_80013C8C;
    }
    // 0x80013C84: nop

    // 0x80013C88: break       7
    do_break(2147564680);
L_80013C8C:
    // 0x80013C8C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80013C90: bne         $t9, $at, L_80013CA4
    if (ctx->r25 != ctx->r1) {
        // 0x80013C94: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80013CA4;
    }
    // 0x80013C94: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80013C98: bne         $t8, $at, L_80013CA4
    if (ctx->r24 != ctx->r1) {
        // 0x80013C9C: nop
    
            goto L_80013CA4;
    }
    // 0x80013C9C: nop

    // 0x80013CA0: break       6
    do_break(2147564704);
L_80013CA4:
    // 0x80013CA4: mflo        $t1
    ctx->r9 = lo;
    // 0x80013CA8: bgez        $t1, L_80013CB8
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80013CAC: sra         $t0, $t1, 2
        ctx->r8 = S32(SIGNED(ctx->r9) >> 2);
            goto L_80013CB8;
    }
    // 0x80013CAC: sra         $t0, $t1, 2
    ctx->r8 = S32(SIGNED(ctx->r9) >> 2);
    // 0x80013CB0: addiu       $at, $t1, 0x3
    ctx->r1 = ADD32(ctx->r9, 0X3);
    // 0x80013CB4: sra         $t0, $at, 2
    ctx->r8 = S32(SIGNED(ctx->r1) >> 2);
L_80013CB8:
    // 0x80013CB8: sh          $t0, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r8;
    // 0x80013CBC: lh          $a2, 0x4($a0)
    ctx->r6 = MEM_H(ctx->r4, 0X4);
L_80013CC0:
    // 0x80013CC0: bne         $a2, $zero, L_80013CD0
    if (ctx->r6 != 0) {
        // 0x80013CC4: addiu       $t2, $zero, 0x1
        ctx->r10 = ADD32(0, 0X1);
            goto L_80013CD0;
    }
    // 0x80013CC4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80013CC8: sh          $t2, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r10;
    // 0x80013CCC: lh          $a2, 0x4($a0)
    ctx->r6 = MEM_H(ctx->r4, 0X4);
L_80013CD0:
    // 0x80013CD0: lh          $v1, 0x2($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X2);
    // 0x80013CD4: lw          $t3, 0x20($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X20);
    // 0x80013CD8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80013CDC: sll         $t4, $v1, 2
    ctx->r12 = S32(ctx->r3 << 2);
    // 0x80013CE0: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x80013CE4: lh          $t6, 0x2($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X2);
    // 0x80013CE8: lwc1        $f8, -0x78EC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X78EC);
    // 0x80013CEC: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x80013CF0: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80013CF4: addiu       $t8, $v1, 0x1
    ctx->r24 = ADD32(ctx->r3, 0X1);
    // 0x80013CF8: sb          $t7, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r15;
    // 0x80013CFC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80013D00: lwc1        $f4, 0x14($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80013D04: sh          $t8, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r24;
    // 0x80013D08: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80013D0C: mtc1        $a2, $f8
    ctx->f8.u32l = ctx->r6;
    // 0x80013D10: swc1        $f10, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f10.u32l;
    // 0x80013D14: lwc1        $f0, 0x18($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X18);
    // 0x80013D18: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80013D1C: mul.s       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80013D20: swc1        $f16, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f16.u32l;
    // 0x80013D24: lwc1        $f18, 0x18($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X18);
    // 0x80013D28: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80013D2C: div.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80013D30: swc1        $f16, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f16.u32l;
L_80013D34:
    // 0x80013D34: lbu         $t9, 0x1($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X1);
    // 0x80013D38: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80013D3C: bnel        $t9, $at, L_80013E18
    if (ctx->r25 != ctx->r1) {
        // 0x80013D40: mtc1        $zero, $f12
        ctx->f12.u32l = 0;
            goto L_80013E18;
    }
    goto skip_1;
    // 0x80013D40: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    skip_1:
L_80013D44:
    // 0x80013D44: lh          $t1, 0x4($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X4);
    // 0x80013D48: lwc1        $f18, 0x14($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80013D4C: lwc1        $f4, 0xC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80013D50: addiu       $t0, $t1, -0x1
    ctx->r8 = ADD32(ctx->r9, -0X1);
    // 0x80013D54: sh          $t0, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r8;
    // 0x80013D58: add.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80013D5C: lh          $t2, 0x4($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X4);
    // 0x80013D60: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x80013D64: bgtz        $t2, L_80013E14
    if (SIGNED(ctx->r10) > 0) {
        // 0x80013D68: swc1        $f8, 0x14($a0)
        MEM_W(0X14, ctx->r4) = ctx->f8.u32l;
            goto L_80013E14;
    }
    // 0x80013D68: swc1        $f8, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f8.u32l;
    // 0x80013D6C: b           L_80013E14
    // 0x80013D70: sb          $t3, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r11;
        goto L_80013E14;
    // 0x80013D70: sb          $t3, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r11;
L_80013D74:
    // 0x80013D74: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80013D78: lwc1        $f0, 0x8($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80013D7C: lwc1        $f6, 0x14($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80013D80: lwc1        $f10, 0x10($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80013D84: c.eq.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl == ctx->f0.fl;
    // 0x80013D88: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80013D8C: sub.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80013D90: bc1t        L_80013DCC
    if (c1cs) {
        // 0x80013D94: swc1        $f16, 0x14($a0)
        MEM_W(0X14, ctx->r4) = ctx->f16.u32l;
            goto L_80013DCC;
    }
    // 0x80013D94: swc1        $f16, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f16.u32l;
    // 0x80013D98: bne         $a1, $at, L_80013DCC
    if (ctx->r5 != ctx->r1) {
        // 0x80013D9C: nop
    
            goto L_80013DCC;
    }
    // 0x80013D9C: nop

    // 0x80013DA0: lwc1        $f18, 0x14($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80013DA4: addiu       $t4, $zero, 0x80
    ctx->r12 = ADD32(0, 0X80);
    // 0x80013DA8: addiu       $t5, $zero, 0x8
    ctx->r13 = ADD32(0, 0X8);
    // 0x80013DAC: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x80013DB0: nop

    // 0x80013DB4: bc1fl       L_80013E18
    if (!c1cs) {
        // 0x80013DB8: mtc1        $zero, $f12
        ctx->f12.u32l = 0;
            goto L_80013E18;
    }
    goto skip_2;
    // 0x80013DB8: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    skip_2:
    // 0x80013DBC: swc1        $f0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f0.u32l;
    // 0x80013DC0: sh          $t4, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r12;
    // 0x80013DC4: b           L_80013E14
    // 0x80013DC8: sb          $t5, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r13;
        goto L_80013E14;
    // 0x80013DC8: sb          $t5, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r13;
L_80013DCC:
    // 0x80013DCC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80013DD0: lwc1        $f8, -0x78E8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X78E8);
    // 0x80013DD4: lwc1        $f4, 0x14($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80013DD8: c.lt.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl < ctx->f8.fl;
    // 0x80013DDC: nop

    // 0x80013DE0: bc1fl       L_80013E18
    if (!c1cs) {
        // 0x80013DE4: mtc1        $zero, $f12
        ctx->f12.u32l = 0;
            goto L_80013E18;
    }
    goto skip_3;
    // 0x80013DE4: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    skip_3:
    // 0x80013DE8: swc1        $f12, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f12.u32l;
    // 0x80013DEC: b           L_80013E14
    // 0x80013DF0: sb          $zero, 0x1($a0)
    MEM_B(0X1, ctx->r4) = 0;
        goto L_80013E14;
    // 0x80013DF0: sb          $zero, 0x1($a0)
    MEM_B(0X1, ctx->r4) = 0;
L_80013DF4:
    // 0x80013DF4: lh          $t6, 0x4($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X4);
    // 0x80013DF8: addiu       $t9, $zero, 0x7
    ctx->r25 = ADD32(0, 0X7);
    // 0x80013DFC: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80013E00: sh          $t7, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r15;
    // 0x80013E04: lh          $t8, 0x4($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X4);
    // 0x80013E08: bnel        $t8, $zero, L_80013E18
    if (ctx->r24 != 0) {
        // 0x80013E0C: mtc1        $zero, $f12
        ctx->f12.u32l = 0;
            goto L_80013E18;
    }
    goto skip_4;
    // 0x80013E0C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    skip_4:
    // 0x80013E10: sb          $t9, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r25;
L_80013E14:
    // 0x80013E14: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
L_80013E18:
    // 0x80013E18: andi        $t1, $v0, 0x20
    ctx->r9 = ctx->r2 & 0X20;
    // 0x80013E1C: beq         $t1, $zero, L_80013E34
    if (ctx->r9 == 0) {
        // 0x80013E20: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80013E34;
    }
    // 0x80013E20: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80013E24: addiu       $t0, $zero, 0x6
    ctx->r8 = ADD32(0, 0X6);
    // 0x80013E28: andi        $t2, $v0, 0xFFDF
    ctx->r10 = ctx->r2 & 0XFFDF;
    // 0x80013E2C: sb          $t0, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r8;
    // 0x80013E30: sb          $t2, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r10;
L_80013E34:
    // 0x80013E34: andi        $t3, $v1, 0x10
    ctx->r11 = ctx->r3 & 0X10;
    // 0x80013E38: beq         $t3, $zero, L_80013E4C
    if (ctx->r11 == 0) {
        // 0x80013E3C: addiu       $t4, $zero, 0x7
        ctx->r12 = ADD32(0, 0X7);
            goto L_80013E4C;
    }
    // 0x80013E3C: addiu       $t4, $zero, 0x7
    ctx->r12 = ADD32(0, 0X7);
    // 0x80013E40: andi        $t5, $v1, 0xFFEF
    ctx->r13 = ctx->r3 & 0XFFEF;
    // 0x80013E44: sb          $t4, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r12;
    // 0x80013E48: sb          $t5, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r13;
L_80013E4C:
    // 0x80013E4C: lwc1        $f2, 0x14($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80013E50: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80013E54: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x80013E58: nop

    // 0x80013E5C: bc1fl       L_80013E70
    if (!c1cs) {
        // 0x80013E60: mtc1        $at, $f12
        ctx->f12.u32l = ctx->r1;
            goto L_80013E70;
    }
    goto skip_5;
    // 0x80013E60: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    skip_5:
    // 0x80013E64: jr          $ra
    // 0x80013E68: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    return;
    // 0x80013E68: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x80013E6C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
L_80013E70:
    // 0x80013E70: nop

    // 0x80013E74: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x80013E78: nop

    // 0x80013E7C: bc1fl       L_80013E90
    if (!c1cs) {
        // 0x80013E80: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_80013E90;
    }
    goto skip_6;
    // 0x80013E80: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    skip_6:
    // 0x80013E84: jr          $ra
    // 0x80013E88: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    return;
    // 0x80013E88: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x80013E8C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_80013E90:
    // 0x80013E90: jr          $ra
    // 0x80013E94: nop

    return;
    // 0x80013E94: nop

;}
RECOMP_FUNC void Effect_Effect385_Spawn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007B550: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8007B554: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8007B558: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8007B55C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8007B560: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8007B564: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8007B568: addiu       $v0, $v0, 0x37E0
    ctx->r2 = ADD32(ctx->r2, 0X37E0);
    // 0x8007B56C: addiu       $a0, $a0, 0x130
    ctx->r4 = ADD32(ctx->r4, 0X130);
    // 0x8007B570: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
L_8007B574:
    // 0x8007B574: bnel        $t6, $zero, L_8007B5A8
    if (ctx->r14 != 0) {
        // 0x8007B578: addiu       $a0, $a0, 0x8C
        ctx->r4 = ADD32(ctx->r4, 0X8C);
            goto L_8007B5A8;
    }
    goto skip_0;
    // 0x8007B578: addiu       $a0, $a0, 0x8C
    ctx->r4 = ADD32(ctx->r4, 0X8C);
    skip_0:
    // 0x8007B57C: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8007B580: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8007B584: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8007B588: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x8007B58C: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8007B590: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8007B594: jal         0x8007B494
    // 0x8007B598: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    Effect_Effect385_Setup(rdram, ctx);
        goto after_0;
    // 0x8007B598: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_0:
    // 0x8007B59C: b           L_8007B5B4
    // 0x8007B5A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8007B5B4;
    // 0x8007B5A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007B5A4: addiu       $a0, $a0, 0x8C
    ctx->r4 = ADD32(ctx->r4, 0X8C);
L_8007B5A8:
    // 0x8007B5A8: bnel        $a0, $v0, L_8007B574
    if (ctx->r4 != ctx->r2) {
        // 0x8007B5AC: lbu         $t6, 0x0($a0)
        ctx->r14 = MEM_BU(ctx->r4, 0X0);
            goto L_8007B574;
    }
    goto skip_1;
    // 0x8007B5AC: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    skip_1:
    // 0x8007B5B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8007B5B4:
    // 0x8007B5B4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8007B5B8: jr          $ra
    // 0x8007B5BC: nop

    return;
    // 0x8007B5BC: nop

;}
RECOMP_FUNC void ldiv_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002B0B0: div         $zero, $a1, $a2
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r6)));
    // 0x8002B0B4: mflo        $v0
    ctx->r2 = lo;
    // 0x8002B0B8: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8002B0BC: bne         $a2, $zero, L_8002B0C8
    if (ctx->r6 != 0) {
        // 0x8002B0C0: nop
    
            goto L_8002B0C8;
    }
    // 0x8002B0C0: nop

    // 0x8002B0C4: break       7
    do_break(2147659972);
L_8002B0C8:
    // 0x8002B0C8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8002B0CC: bne         $a2, $at, L_8002B0E0
    if (ctx->r6 != ctx->r1) {
        // 0x8002B0D0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8002B0E0;
    }
    // 0x8002B0D0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8002B0D4: bne         $a1, $at, L_8002B0E0
    if (ctx->r5 != ctx->r1) {
        // 0x8002B0D8: nop
    
            goto L_8002B0E0;
    }
    // 0x8002B0D8: nop

    // 0x8002B0DC: break       6
    do_break(2147659996);
L_8002B0E0:
    // 0x8002B0E0: multu       $a2, $v0
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002B0E4: sw          $v0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r2;
    // 0x8002B0E8: addiu       $t7, $sp, 0x0
    ctx->r15 = ADD32(ctx->r29, 0X0);
    // 0x8002B0EC: mflo        $t6
    ctx->r14 = lo;
    // 0x8002B0F0: subu        $v1, $a1, $t6
    ctx->r3 = SUB32(ctx->r5, ctx->r14);
    // 0x8002B0F4: bgez        $v0, L_8002B118
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8002B0F8: sw          $v1, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r3;
            goto L_8002B118;
    }
    // 0x8002B0F8: sw          $v1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r3;
    // 0x8002B0FC: sw          $v0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r2;
    // 0x8002B100: blez        $v1, L_8002B118
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8002B104: sw          $v1, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r3;
            goto L_8002B118;
    }
    // 0x8002B104: sw          $v1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r3;
    // 0x8002B108: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8002B10C: subu        $v1, $v1, $a2
    ctx->r3 = SUB32(ctx->r3, ctx->r6);
    // 0x8002B110: sw          $v1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r3;
    // 0x8002B114: sw          $v0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r2;
L_8002B118:
    // 0x8002B118: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x8002B11C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8002B120: sw          $at, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r1;
    // 0x8002B124: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x8002B128: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x8002B12C: jr          $ra
    // 0x8002B130: sw          $t0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r8;
    return;
    // 0x8002B130: sw          $t0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r8;
;}
RECOMP_FUNC void Cutscene_EffectSmallRock_Spawn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80049B44: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80049B48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80049B4C: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80049B50: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80049B54: addiu       $v0, $v0, 0x37E0
    ctx->r2 = ADD32(ctx->r2, 0X37E0);
    // 0x80049B58: addiu       $a0, $a0, 0x130
    ctx->r4 = ADD32(ctx->r4, 0X130);
    // 0x80049B5C: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
L_80049B60:
    // 0x80049B60: bnel        $t6, $zero, L_80049BF4
    if (ctx->r14 != 0) {
        // 0x80049B64: addiu       $a0, $a0, 0x8C
        ctx->r4 = ADD32(ctx->r4, 0X8C);
            goto L_80049BF4;
    }
    goto skip_0;
    // 0x80049B64: addiu       $a0, $a0, 0x8C
    ctx->r4 = ADD32(ctx->r4, 0X8C);
    skip_0:
    // 0x80049B68: jal         0x80004EB0
    // 0x80049B6C: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    Rand_ZeroOne(rdram, ctx);
        goto after_0;
    // 0x80049B6C: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x80049B70: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80049B74: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80049B78: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x80049B7C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80049B80: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x80049B84: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80049B88: jal         0x80004EB0
    // 0x80049B8C: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x80049B8C: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x80049B90: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80049B94: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80049B98: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x80049B9C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80049BA0: sub.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x80049BA4: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80049BA8: jal         0x80004EB0
    // 0x80049BAC: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_2;
    // 0x80049BAC: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x80049BB0: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x80049BB4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80049BB8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80049BBC: lwc1        $f8, 0x7D20($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x80049BC0: mul.s       $f18, $f0, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x80049BC4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80049BC8: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x80049BCC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80049BD0: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80049BD4: sub.s       $f16, $f10, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f12.fl;
    // 0x80049BD8: sub.s       $f2, $f16, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80049BDC: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80049BE0: jal         0x80049A9C
    // 0x80049BE4: nop

    Cutscene_EffectSmallRock_Setup(rdram, ctx);
        goto after_3;
    // 0x80049BE4: nop

    after_3:
    // 0x80049BE8: b           L_80049C00
    // 0x80049BEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80049C00;
    // 0x80049BEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80049BF0: addiu       $a0, $a0, 0x8C
    ctx->r4 = ADD32(ctx->r4, 0X8C);
L_80049BF4:
    // 0x80049BF4: bnel        $a0, $v0, L_80049B60
    if (ctx->r4 != ctx->r2) {
        // 0x80049BF8: lbu         $t6, 0x0($a0)
        ctx->r14 = MEM_BU(ctx->r4, 0X0);
            goto L_80049B60;
    }
    goto skip_1;
    // 0x80049BF8: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    skip_1:
    // 0x80049BFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80049C00:
    // 0x80049C00: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80049C04: jr          $ra
    // 0x80049C08: nop

    return;
    // 0x80049C08: nop

;}
